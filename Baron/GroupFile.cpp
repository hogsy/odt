/*
MIT License

Copyright (c) 2021 Mark Sowden

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

#include <cstdio>
#include <cstring>

#include "GroupFile.h"

using namespace Baron;

GroupFile::GroupFile( uint8_t *nBuffer, unsigned int nLength, unsigned int *errCode ) : buffer( nBuffer ), length( nLength ) {
	*errCode = SetupIndexTable();
}

GroupFile::GroupFile( const char *path, unsigned int *errCode ) {
	FILE *file = fopen( path, "rb" );
	if ( file == nullptr ) {
		*errCode = GF_ERR_IO;
		return;
	}

	fseek( file, 0, SEEK_END );
	length = ftell( file );
	rewind( file );
	if ( length <= 0 ) {
		*errCode = GF_ERR_IO;
	} else {
		buffer = new uint8_t[ length ];
		fread( buffer, sizeof( uint8_t ), length, file );
		*errCode = SetupIndexTable();
		if ( *errCode != GF_ERR_SUCCESS ) {
			delete buffer;
		}
	}

	fclose( file );
}

GroupFile::~GroupFile() {
	delete buffer;
}

uint8_t *GroupFile::ReadIndex( unsigned int index, int *outLength ) {
	if ( index >= indices.size() ) {
		return nullptr;
	}

	uint8_t *offsetPtr = buffer + indices[ index ].offset;

	uint8_t *rb = new uint8_t[ indices[ index ].length ];
	memcpy( rb, offsetPtr, indices[ index ].length );
	*outLength = indices[ index ].length;

	return rb;
}

unsigned int GroupFile::SetupIndexTable() {
	int numIndices = *buffer;
	if ( numIndices <= 0 ) {
		return GF_ERR_EMPTY_FILE;
	}

	indices.resize( numIndices );
	memcpy( indices.data(), buffer + 4, sizeof( Index ) * numIndices );

	return GF_ERR_SUCCESS;
}
