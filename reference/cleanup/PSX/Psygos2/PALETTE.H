#ifndef PALETTE_H
#define PALETTE_H


extern void Pal_Init(); // 0x8009F500

extern void Pal_InitZone(short x, short y, short w, short h); // 0x8009F52C

extern short Pal_Alloc(short n); // 0x8009F61C

extern void Pal_Free(short i); // 0x8009F728

extern void Pal_PalToVram(unsigned long *source, short dest, short n); // 0x8009F744


#endif
