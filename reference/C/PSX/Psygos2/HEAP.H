#ifndef HEAP_H
#define HEAP_H


extern void Heap_Init(void *start); // 0x8009A754

extern long Heap_MaxBlock(); // 0x8009A7B0

extern long Heap_MaxMem(); // 0x8009A880

extern void * Heap_AllocMem(unsigned long size); // 0x8009A910

extern void Heap_FreeMem(void *ptt); // 0x8009A9F0

extern void Heap_ResizeMem(void *ptt, long si); // 0x8009AAB0

extern long Heap_GetSize(void *ptt); // 0x8009AB3C


#endif
