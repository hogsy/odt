#ifndef SCREEN_H
#define SCREEN_H


extern void S_AddPrim(long rang, void *prim); // 0x8009D4B8

extern void Scr_Init(); // 0x8009D514

extern void Scr_Stop(); // 0x8009D630

extern void Scr_Start(); // 0x8009D680

extern void Scr_Remove(); // 0x8009D6E0

extern void Scr_InitZone(short x, short y, short w, short h, int fi); // 0x8009D708

extern void Scr_SetSync(long s); // 0x8009D978

extern void Scr_SetOtSize(long size); // 0x8009D9BC

extern void Scr_Clear(); // 0x8009DA38

extern void Scr_SetBackground(void *image); // 0x8009DAB4

extern void Scr_FadeVSync(long type, long time); // 0x8009DAEC

extern struct TASK * Scr_Fade(short type, short time); // 0x8009DAF4

extern void Scr_FadeWait(); // 0x8009DB70

extern void Scr_FadeTask(); // 0x8009DBB4

extern void Scr_FadeInit(struct SCREEN_55fake *tpages, struct SCREEN_45fake *tiles); // 0x8009DDE0

extern void Scr_FadeDestructor(struct TASK *t); // 0x8009DE44

extern void Scr_Swap(); // 0x8009DE50

extern struct _SCREEN * Scr_GetFlag(); // 0x8009DEC0

extern void Scr_CallBack(); // 0x8009DED0

extern void SetDefDispEnv() ; // 0x8009DF88


#endif
