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

#define BARON_VIEWER_TITLE L"Baron Viewer"
#define BARON_VIEWER_WIDTH 1024
#define BARON_VIEWER_HEIGHT 768

static Baron::GroupFile *effectsGroup;

irr::video::IVideoDriver *videoDriver;
irr::scene::ISceneManager *sceneManager;
irr::io::IFileSystem *fileSystem;
irr::gui::IGUIEnvironment *guiEnvironment;

#ifdef _IRR_WINDOWS_
#pragma comment( lib, "Irrlicht.lib" )
#pragma comment( linker, "/subsystem:windows /ENTRY:mainCRTStartup" )
#endif

int main( int argc, char **argv ) {
	irr::IrrlichtDevice *device = irr::createDevice(
	        irr::video::EDT_OPENGL,
	        irr::core::dimension2du( BARON_VIEWER_WIDTH, BARON_VIEWER_HEIGHT ),
	        16, false, false, false,
	        0 );
	if ( device == nullptr ) {
		printf( "Failed to setup device!\n" );
		return EXIT_FAILURE;
	}

	device->setWindowCaption( BARON_VIEWER_TITLE );

	fileSystem     = device->getFileSystem();
	videoDriver    = device->getVideoDriver();
	guiEnvironment = device->getGUIEnvironment();
	sceneManager   = device->getSceneManager();

	unsigned int errCode;
	Baron::GroupFile groupFile( "LEVEL02/SECTOR01.ALL", &errCode );
	if ( errCode != Baron::GroupFile::GF_ERR_SUCCESS ) {
		printf( "Failed to open group file!\nERR: %d\n", errCode );
		return EXIT_FAILURE;
	}

	int lnkBufferLength;
	uint8_t *lnkBuffer = groupFile.ReadIndex( 2, &lnkBufferLength );
	Baron::GroupFile lnkGroupFile( lnkBuffer, lnkBufferLength, &errCode );
	if ( errCode != Baron::GroupFile::GF_ERR_SUCCESS ) {
		printf( "Failed to open group file!\nERR: %d\n", errCode );
		return EXIT_FAILURE;
	}

	int size;
	uint8_t *lvlData = lnkGroupFile.ReadIndex( 0, &size );
	/* fetch the PVL header, which is at the top */
	const Baron::PVLHeader *hdr = ( Baron::PVLHeader * ) lvlData;

	while ( device->run() ) {
		videoDriver->beginScene();

		sceneManager->drawAll();
		guiEnvironment->drawAll();

		videoDriver->endScene();
	}

	device->drop();

	return EXIT_SUCCESS;
}
