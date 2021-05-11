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

#include <sys/stat.h>

#include "FileSystem.h"

bool Baron::FileSystem::FileExists( const char *path ) {
	struct stat s;
	return ( stat( path, &s ) == 0 );
}

/**
 * Reads the entire specified file into
 * a buffer.
 */
uint8_t *Baron::FileSystem::ReadFile( const char *path ) {
	struct stat s;
	if ( stat( path, &s ) == 0 ) {
		return NULL;
	}

	FILE *file = fopen( path, "rb" );
	if ( file == NULL ) {
		return NULL;
	}

	uint8_t *buf = new uint8_t[ s.st_size ];
	fread( buf, sizeof( uint8_t ), s.st_size, file );
	fclose( file );

	return buf;
}
