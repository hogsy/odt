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
/*
 * Internal types used by ODT Engine
 */

#pragma once

#include <cstdint>

namespace baron {
    struct RGB {
        uint8_t r, g, b;
        uint8_t cb;
    };

    struct Vector3D {
        int16_t x, y, z;
        int16_t pad;
    };

    struct PVLHeader {
        int8_t id[2]; /* P0 */
        int16_t crc;
        int16_t numPlatforms;
        int16_t numLObjects;
        int16_t numGObjects;
        int16_t numLights;
        int16_t numZones;
        int16_t numEnemyZones;
        int16_t numMonsters;
        int16_t numIndices;
        int16_t numMatrices;
        int16_t numMObjects;
        int16_t numExitNames;
        int16_t numShapes;
        int16_t numAnimBlinks;
        int16_t numBlinks;
        int16_t numVisibilities;
        int16_t numCameras;
        int16_t numHObjects;
        int16_t mode;
        int16_t trackDistance;
        int16_t pad;

        RGB lightAmbience;

        int16_t mapW, mapH;

        Vector3D wind;
        RGB fog;
    };
}
