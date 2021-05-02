#ifndef TPAGE_H
#define TPAGE_H


extern void TPage_Init(); // 0x8009F7E8

extern void TPage_InitZone(long x, long y, long w, long h); // 0x8009F814

extern void TPage_ClearAll(); // 0x8009F8AC

extern void TPage_Clear(long n); // 0x8009F8F0

extern long TPage_Alloc(long n); // 0x8009F954

extern long TPage_AllocAt(long n, long t); // 0x8009FA04

extern void TPage_Free(long i); // 0x8009FA54


#endif
