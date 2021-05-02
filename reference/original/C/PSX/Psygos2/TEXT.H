#ifndef TEXT_H
#define TEXT_H


extern void Text_Init(); // 0x800A2FE0

extern void Text_AllocMem(long size); // 0x800A2FEC

extern void Text_FreeMem(); // 0x800A3034

extern void Text_InitFont(struct TEXT_101fake *f, void *pcl, short s, short type); // 0x800A305C

extern void Text_InitContext(struct TEXT_102fake *t); // 0x800A3194

extern void Text_SetFontIChar(struct TEXT_101fake *f, short ic); // 0x800A31B0

extern void Text_SetFontILine(struct TEXT_101fake *f, short il); // 0x800A3218

extern void Text_SetText(char *text, short x, short y); // 0x800A327C

extern void Text_SetText3D(char *text, struct TEXT_7fake *pos); // 0x800A36E4

extern long Text_LenX(char *text, struct TEXT_102fake *t); // 0x800A373C

extern long Text_LenY(char *text, struct TEXT_102fake *t); // 0x800A3860

extern void Text_SetContext(struct TEXT_102fake *t); // 0x800A38B4

extern void Text_SetContextFont(struct TEXT_101fake *f); // 0x800A38F0

extern void Text_SetContextXY(short a, short b); // 0x800A3920

extern void Text_SetContextWH(short a, short b); // 0x800A3954

extern void Text_SetContextRange(short r); // 0x800A3988

extern void Text_SetContextMode(short a); // 0x800A39B0

extern void Text_SetContextColor(long a); // 0x800A39D8

extern void Text_SetContextScale(short scalex, short scaley); // 0x800A3A00

extern char * Text_GetIndexPointers(char *input, char *crc, long **array); // 0x800A3A34

extern short Text_AmountOfTexts(char *src); // 0x800A3C78

extern void Text_DisplayLine(char *src, long index, long time, long *info); // 0x800A3CC8

extern void strchr() ; // 0x800A3DC4


#endif
