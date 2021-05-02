#ifndef MISC_H
#define MISC_H


extern void OS_Init(TDRFuncPtr_OS_Init0startup startup); // 0x80096950

extern void OS_Install(void *heap); // 0x800969AC

extern void OS_Remove(); // 0x80096A44

extern void OS_Stop(); // 0x80096A7C

extern void OS_Start(); // 0x80096AE8

extern void M_srand(long n); // 0x80096B38

extern long M_rand(); // 0x80096B44

extern long Direction(long vx, long vy); // 0x80096B6C

extern long DirectionZ(long dx, long dy, long dz); // 0x80096CF8

extern long DeltaDirection(long d1, long d2); // 0x80096D44

extern long Distance3D(long x1, long y1, long z1, long x2, long y2, long z2); // 0x80096D70

extern long Distance2D(long x1, long y1, long x2, long y2); // 0x80096DE8

extern void Matrix_Clear(struct MISC_5fake *mat); // 0x80096E4C


typedef void (*TDRFuncPtr_OS_Init0startup)();




#endif
