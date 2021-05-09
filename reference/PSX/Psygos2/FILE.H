#ifndef FILE_H
#define FILE_H


extern void File_Init(); // 0x8009B2E8

extern void * FileGroup_GetAddr(void *File, long Index); // 0x8009B2F4

extern void File_Exec(char *n, long sp, long p1, long p2); // 0x8009B308

extern void File_Seek(char *name); // 0x8009B3C8

extern long File_IsExist(char *name); // 0x8009B414

extern void * File_ReadBytes(long nbytes, void *addr); // 0x8009B448

extern void * File_Read(char *name, void *addr); // 0x8009B4D0

extern void * File_Open(char *name, void *addr); // 0x8009B4FC

extern void File_Wait(); // 0x8009B51C

extern long File_CdExistFile(char *name, long multitasking); // 0x8009B524

extern void File_CdSearchFile(struct FILE_3fake *fp, char *name, long multitasking); // 0x8009B548

extern void File_CdSeek(struct FILE_0fake *pos, long multitasking); // 0x8009B598

extern void File_CdReadSectors(void *a, long n, long multitasking); // 0x8009B668

extern void * File_CdReadFile(char *name, void *a, long multitasking); // 0x8009B764

extern void File_CdConvert(char *out, char *in, long fcd); // 0x8009B85C

extern void toupper() ; // 0x8009B940


#endif
