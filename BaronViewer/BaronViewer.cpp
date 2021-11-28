/*
MIT License

Copyright (c) 2021 Mark E Sowden <hogsy@oldtimes-software.com>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "BaronViewer.h"

#ifdef _IRR_WINDOWS_
#pragma comment( lib, "Irrlicht.lib" )
#pragma comment( linker, "/subsystem:windows /ENTRY:mainCRTStartup" )
#endif

#define BARON_VIEWER_TITLE L"Baron Viewer"
#define BARON_VIEWER_WIDTH 800
#define BARON_VIEWER_HEIGHT 600

static Baron::GroupFile *effectsGroup;

namespace BaronViewer {
	class App {
	public:
		static App *InitializeApp( int argc, char **argv );
		static inline App *GetApp() {
			return appInstance;
		}

		const char *GetCLArgument( const char *arg ) const;
		bool HasCLArgument( const char *arg ) const;

		int Run();

		inline irr::IrrlichtDevice *GetDevice() const { return device; }
		inline irr::video::IVideoDriver *GetVideoDriver() const { return videoDriver; }
		inline irr::scene::ISceneManager *GetSceneManager() const { return sceneManager; }
		inline irr::io::IFileSystem *GetFileSystem() const { return fileSystem; }
		inline irr::gui::IGUIEnvironment *GetGUIEnvironment() const { return guiEnvironment; }

	protected:
	private:
        inline App( int argc, char **argv ) : numCLArguments( argc ), CLArguments( argv ) {}
        ~App();

        bool InitializeIrrlicht();

		irr::IrrlichtDevice *device{ nullptr };

		irr::video::IVideoDriver *videoDriver{ nullptr };
		irr::scene::ISceneManager *sceneManager{ nullptr };
		irr::io::IFileSystem *fileSystem{ nullptr };
		irr::gui::IGUIEnvironment *guiEnvironment{ nullptr };

		int numCLArguments;
		char **CLArguments;

		static App *appInstance;
	};
}// namespace BaronViewer

using namespace BaronViewer;

App *App::appInstance = nullptr;
App *App::InitializeApp( int argc, char **argv ) {
	appInstance = new App( argc, argv );
	appInstance->InitializeIrrlicht();

	return appInstance;
}

App::~App() {
    device->drop();
}

const char *App::GetCLArgument( const char *arg ) const {
	for ( unsigned int i = 0; i < numCLArguments; ++i ) {
		if ( strcmp( arg, CLArguments[ i ] ) != 0 ) {
			continue;
		}

		if ( ( i + 1 ) >= numCLArguments ) {
			break;
		}

        return CLArguments[ i + 1 ];
	}

    return nullptr;
}

bool App::HasCLArgument( const char *arg ) const {
	for ( unsigned int i = 0; i < numCLArguments; ++i ) {
		if ( strcmp( arg, CLArguments[ i ] ) != 0 ) {
			continue;
		}

		return true;
	}

    return false;
}

bool App::InitializeIrrlicht() {
    device = irr::createDevice(
            irr::video::EDT_OPENGL,
            irr::core::dimension2du( BARON_VIEWER_WIDTH, BARON_VIEWER_HEIGHT ),
            16, false, false, false,
            0 );
    if ( device == nullptr ) {
        printf( "Failed to setup device!\n" );
        return false;
    }

    device->setWindowCaption( BARON_VIEWER_TITLE );

    fileSystem     = device->getFileSystem();
    videoDriver    = device->getVideoDriver();
    guiEnvironment = device->getGUIEnvironment();
    sceneManager   = device->getSceneManager();
    sceneManager->addCameraSceneNode();

    return true;
}

int App::Run() {
    irr::gui::IGUIStaticText *fpsCounter = guiEnvironment->addStaticText( L"FPS: ", irr::core::recti( 20, 20, 128, 32 ) );
    fpsCounter->setOverrideColor( irr::video::SColor( 255, 255, 255, 255 ) );

    int lastFPS = -1;
    while ( device->run() ) {
        if ( !device->isWindowActive() ) {
            device->yield();
            continue;
        }

        videoDriver->beginScene();

        sceneManager->drawAll();
        guiEnvironment->drawAll();

        videoDriver->endScene();

        int fps = videoDriver->getFPS();
        if ( fps != lastFPS ) {
            irr::core::stringw str = L"FPS: ";
            str += fps;
            fpsCounter->setText( str.c_str() );
        }
    }

	return EXIT_SUCCESS;
}

namespace BaronViewer {
	class Level {
	public:
		Level( unsigned int levelNum );

		void LoadSector( unsigned int sectorNum );

	protected:
	private:
		int curSector{ -1 };
	};
}

Level::Level( unsigned int levelNum ) {

}

void Level::LoadSector( unsigned int sectorNum ) {

}

static bool LoadBaronData( unsigned int levelNum, unsigned int sectorNum ) {
	char levelDir[ 16 ];
	snprintf( levelDir, sizeof( levelDir ), "LEVEL%02d/", levelNum );
	char sectorPath[ 32 ];
	snprintf( sectorPath, sizeof( sectorPath ), "%sSECTOR%02d.ALL", levelDir, sectorNum );

	unsigned int errCode;
	Baron::GroupFile sectorGroup( sectorPath, &errCode );
	if ( errCode != Baron::GroupFile::GF_ERR_SUCCESS ) {
		printf( "Failed to open group file!\nERR: %d\n", errCode );
		return false;
	}

	int lnkBufferLength;
	uint8_t *lnkBuffer = sectorGroup.ReadIndex( 2, &lnkBufferLength );
	Baron::GroupFile lnkGroupFile( lnkBuffer, lnkBufferLength, &errCode );
	if ( errCode != Baron::GroupFile::GF_ERR_SUCCESS ) {
		printf( "Failed to open group file!\nERR: %d\n", errCode );
		return false;
	}

	int size;
	uint8_t *lvlData = lnkGroupFile.ReadIndex( 0, &size );
	/* fetch the PVL header, which is at the top */
	const Baron::PVLHeader *hdr = ( Baron::PVLHeader * ) lvlData;
	const char *map = ( const char * )( lvlData + 1 );

	return true;
}

int main( int argc, char **argv ) {
	App *app = App::InitializeApp( argc, argv );

	unsigned int levelNum;
	const char *arg = app->GetCLArgument( "-level" );
	if ( arg != nullptr ) {
		levelNum = strtol( arg, nullptr, 10 );
	} else {
		levelNum = 2;
	}

	unsigned int sectorNum;
	arg = app->GetCLArgument( "-sector" );
	if ( arg != nullptr ) {
		sectorNum = strtol( arg, nullptr, 10 );
	} else {
		sectorNum = 1;
	}

	if ( !LoadBaronData( levelNum, sectorNum ) ) {
		printf( "Failed to load Baron data!\n" );
		return EXIT_FAILURE;
	}

	return app->Run();
}
