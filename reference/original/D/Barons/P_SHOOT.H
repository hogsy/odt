#ifndef P_SHOOT_H
#define P_SHOOT_H


extern void PGrenade_Add(struct _PLAYER *pl, long speed); // 0x8003DEE8

extern void PShoot_Add(struct _PLAYER *pl); // 0x8003E0E4

extern long PShoot_GetPos(struct _PLAYER *pl, struct P_SHOOT_7fake *pos); // 0x8003E218

extern struct P_SHOOT_143fake * PShoot_Init(struct _PLAYER *pl, struct P_SHOOT_7fake *pos, struct P_SHOOT_7fake *rot, short type, TDRFuncPtr_PShoot_Init4f_move f_move, TDRFuncPtr_PShoot_Init5f_impact f_impact, TDRFuncPtr_PShoot_Init6f_display f_display, TDRFuncPtr_PShoot_Init7f_destructor f_destructor); // 0x8003E438

extern void PShoot_Destructor(struct TASK *t); // 0x8003E5DC

extern void PShoot_Task(); // 0x8003E600

extern void SHPL_Add(struct _PLAYER *pl, struct P_SHOOT_7fake *pos, struct P_SHOOT_7fake *rot); // 0x8003E6EC

extern void SHPL1_Init(struct _PLAYER *pl, struct P_SHOOT_7fake *pos, struct P_SHOOT_7fake *rot); // 0x8003E878

extern short SHPL1_Move(); // 0x8003EA8C

extern void SHPL1_Impact(); // 0x8003EC7C

extern void SHPL1_Display(); // 0x8003ED94

extern void SHPL2_Init(struct _PLAYER *pl, struct P_SHOOT_7fake *pos, struct P_SHOOT_7fake *rot); // 0x8003F1A0

extern short SHPL2_Move(); // 0x8003F370

extern void SHPL2_Impact(); // 0x8003F608

extern void SHPL2_Display(); // 0x8003F6C0

extern void SHPE_Add(struct _PLAYER *pl, struct P_SHOOT_7fake *pos, struct P_SHOOT_7fake *rot); // 0x8003FB3C

extern void SHPE1_Init(struct _PLAYER *pl, struct P_SHOOT_7fake *pos, struct P_SHOOT_7fake *rot); // 0x8003FB5C

extern short SHPE1_Move(); // 0x8003FC54

extern void SHPE1_Display(); // 0x800400D8

extern void SHPE1_Destructor(struct TASK *t); // 0x800401A0

extern void SHPA_Add(struct _PLAYER *pl, struct P_SHOOT_7fake *pos, struct P_SHOOT_7fake *rot); // 0x800401E0

extern void SHPG1_Init(struct _PLAYER *pl, struct P_SHOOT_7fake *pos, struct P_SHOOT_7fake *rot, long speed); // 0x80040234

extern short SHPG1_Move(); // 0x80040420

extern void SHPG1_Impact(); // 0x80040618

extern void SHPG1_Display(); // 0x80040640

extern void SHPG2_Init(struct _PLAYER *pl, struct P_SHOOT_7fake *pos, struct P_SHOOT_7fake *rot); // 0x800407FC

extern void SHPG2_Destructor(struct TASK *t); // 0x80040934

extern short SHPG2_Move(); // 0x80040964

extern void SHPG2_Display(); // 0x80040A30

extern void SHPF_Add(struct _PLAYER *pl, struct P_SHOOT_7fake *pos, struct P_SHOOT_7fake *rot); // 0x80040C18

extern void SHPF1_Init(struct _PLAYER *pl, struct P_SHOOT_7fake *pos, struct P_SHOOT_7fake *rot); // 0x80040C38

extern short SHPF1_Move(); // 0x80040D60

extern void SHPF1_Destructor(struct TASK *t); // 0x80040EB4

extern void SHPF1_Display(); // 0x80040EE4


typedef short (*TDRFuncPtr_PShoot_Init4f_move)();

typedef void (*TDRFuncPtr_PShoot_Init5f_impact)();

typedef void (*TDRFuncPtr_PShoot_Init6f_display)();

typedef void (*TDRFuncPtr_PShoot_Init7f_destructor)();




#endif
