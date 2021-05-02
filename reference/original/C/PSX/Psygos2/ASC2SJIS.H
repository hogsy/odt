#ifndef ASC2SJIS_H
#define ASC2SJIS_H


extern unsigned short Asc2Sjis_Char(unsigned char ascii_code); // 0x800A4490

extern void SwapByte(unsigned short *sjis_code); // 0x800A4640

extern void Asc2Sjis_String(unsigned short *sjis_string, unsigned char *ascii_string); // 0x800A45A8


#endif
