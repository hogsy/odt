#ifndef CARD_H
#define CARD_H


extern void Card_Init(); // 0x800A3E04

extern void Card_Start(); // 0x800A3E10

extern void Card_Stop(); // 0x800A3E40

extern long Card_Test(long channel); // 0x800A3E78

extern char * Card_GetName(char *file); // 0x800A3EE0

extern void Card_SetName(struct _CARD_HEADER *h, char *name); // 0x800A3F58

extern void Card_SetIcons(struct _CARD_HEADER *h, long ni, struct CARD_68fake *shp); // 0x800A3F98

extern long Card_Exist(long channel); // 0x800A40EC

extern long Card_ReadDirectory(long channel, struct DIRENTRY *directory, long *files); // 0x800A4138

extern long Card_CreateFile(long channel, char *name, long nb); // 0x800A41C0

extern long Card_WriteFile(long channel, char *name, struct _CARD_HEADER *h, long size); // 0x800A4240

extern long Card_ReadFile(long channel, char *name, struct _CARD_HEADER *h, long size); // 0x800A4348

extern long Card_DeleteFile(long channel, char *name); // 0x800A43F4

extern long Card_Format(long channel); // 0x800A4458


#endif
