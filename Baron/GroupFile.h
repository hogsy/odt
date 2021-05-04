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

#pragma once

#include <vector>
#include <string>

namespace baron {
    class GroupFile {
    public:
        enum {
            GF_ERR_SUCCESS,
            GF_ERR_IO,
            GF_ERR_EMPTY_FILE,
        };

        explicit GroupFile(const char *path, unsigned int *errCode);
        GroupFile(uint8_t *nBuffer, unsigned int nLength, unsigned int *errCode);
        ~GroupFile();

        inline unsigned int GetNumberOfIndices() const {
            return indices.size();
        }

        uint8_t *ReadIndex(unsigned int index, int *outLength);

    protected:
    private:
        unsigned int SetupIndexTable();

        struct Index {
            int offset;
            int length;
        };
        std::vector<Index> indices;

        uint8_t *buffer{ nullptr };
        unsigned int length{ 0 };
    };
}
