#ifndef SHAPE_H
#define SHAPE_H


extern void Shp_Init(); // 0x8009E690

extern void Shp_InitFile(void *S); // 0x8009E698

extern void Shp_TmdToVram(void *S, void *T, short Offset, short dummy); // 0x8009E714

extern void Shp_TmdToVramUv(void *S, void *T, short Offset); // 0x8009E840

extern void Shp_SetTmdPrim(struct SHAPE_90fake *Prim, struct SHAPE_68fake *Shp, short Offset, short Mode); // 0x8009E960

extern long Shp_GroupToVram(void *pcl, short fsize); // 0x8009EB58

extern void Shp_GroupRelease(void *pcl, short ffree); // 0x8009ECFC

extern long Shp_ShpToVram(struct SHAPE_68fake *shp); // 0x8009EDB8

extern short Shp_GetMark(void *file, long mark); // 0x8009EFA0

extern void Shp_GetWH(struct SHAPE_68fake *shp, short *w, short *h); // 0x8009F004

extern void Shp_GetUV(struct SHAPE_68fake *shp, short *u, short *v); // 0x8009F034

extern short Shp_GetPal(struct SHAPE_68fake *shp); // 0x8009F064

extern short Shp_GetTPage(struct SHAPE_68fake *shp); // 0x8009F088

extern short Shp_GetMode(struct SHAPE_68fake *shp); // 0x8009F0AC

extern short Shp_GetClut(struct SHAPE_68fake *shp); // 0x8009F0D0

extern void Shp_SetPolyFT4(struct SHAPE_31fake *prim, struct SHAPE_68fake *shp, short w, short h); // 0x8009F104

extern void Shp_SetXyFT4(struct SHAPE_31fake *prim, struct SHAPE_68fake *shp, short w, short h); // 0x8009F314

extern void Shp_SetSprt(struct SHAPE_42fake *prim, struct SHAPE_68fake *shp, short scalex, short scaley); // 0x8009F3C0

extern void Shp_SetXySprt(struct SHAPE_42fake *prim, struct SHAPE_68fake *shp, short scalex, short scaley); // 0x8009F4B4


#endif
