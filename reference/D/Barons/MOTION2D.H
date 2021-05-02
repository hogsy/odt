#ifndef MOTION2D_H
#define MOTION2D_H


extern void * Motion2D_EnvMotionCapture(struct M_OBJECT *mo, void *prims, long type); // 0x8002481C

extern void * Motion2D_ShapesMotionCapture(struct M_OBJECT *mo, struct MOTION2D_31fake *pft4, long start, long end, long average, long coef, long mode); // 0x80025090

extern void * Motion2D_ManimSmoke(struct M_OBJECT *mo, void *prims); // 0x800256DC

extern void * Motion2D_EffectSmokeXtra(struct M_OBJECT *mo, void *prims); // 0x80025794

extern void * Motion2D_ManimBurn(struct M_OBJECT *mo, void *prims); // 0x800258A8

extern void * Motion2D_ManimSmallBurn(struct M_OBJECT *mo, void *prims); // 0x8002595C

extern void * Motion2D_ManimElectricity(struct M_OBJECT *mo, void *prims); // 0x80025A10

extern void * Motion2D_ManimGhost(struct M_OBJECT *mo, void *prims); // 0x80025AEC

extern void * Motion2D_ManimInvincibility(struct M_OBJECT *mo, void *prims); // 0x80025C08

extern void * Motion2D_ManimMagic(struct M_OBJECT *mo, void *prims); // 0x80025CFC

extern void * Motion2D_EffectAnimXtra(struct M_OBJECT *mo, void *prims); // 0x80025D90

extern void * Motion2D_ManimFreeze(struct M_OBJECT *mo, void *prims); // 0x80025EA0

extern void * Motion2D_ManimVampire(struct M_OBJECT *mo, void *prims); // 0x80025FD0

extern void * Motion2D_ManimDistortion(struct M_OBJECT *mo, void *prims); // 0x800260E0

extern void * Motion2D_ManimSmallDistortion(struct M_OBJECT *mo, void *prims); // 0x80026134

extern void * Motion2D_ManimWaveDistortion(struct M_OBJECT *mo, void *prims); // 0x80026188

extern void Motion2D_FireRainInit(struct _FIRERAIN *fr, struct _D3_OBJECT *owner, long hp); // 0x800261DC

extern void Motion2D_FireRainAdd(struct TASK *t, struct MOTION2D_7fake *p, struct MOTION2D_7fake *s); // 0x80026288

extern void Motion2D_FireRainMove(struct _FIRERAIN *fr, long gravity); // 0x80026334

extern void Motion2D_FireRainImpact(struct _FIRERAIN *fr, long i); // 0x8002668C

extern struct TASK * Motion2D_FireRain(struct _D3_OBJECT *owner, struct MOTION2D_7fake *pos, long area, long time, long freq, long hp); // 0x80026820

extern void Motion2D_FireRainTask(); // 0x800268B4

extern void Motion2D_FireRainTaskDisplay(); // 0x80026AAC

extern struct TASK * Motion2D_FireWork(struct _D3_OBJECT *owner, struct MOTION2D_7fake *pos, struct MOTION2D_7fake *spd, long duration, long n_drops, long hp); // 0x80026BDC

extern void Motion2D_FireWorkTask(); // 0x80026C84

extern void Motion2D_FireWorkTaskDestructor(struct TASK *t); // 0x80026F40

extern struct TASK * Motion2D_FireBall(struct _D3_OBJECT *owner, struct _D3_OBJECT *target, struct MOTION2D_7fake *pos, struct MOTION2D_7fake *rot, long hp); // 0x80026F64

extern void Motion2D_FireBallTask(); // 0x80026FFC

extern void Motion2D_FireBallTaskDisplay(); // 0x80027104

extern void Motion2D_FireBallTaskDestructor(struct TASK *t); // 0x8002715C

extern void Motion2D_FireBallInit(struct _FIREBALL *fb, struct _D3_OBJECT *owner, struct _D3_OBJECT *target, struct MOTION2D_7fake *pos, struct MOTION2D_7fake *rot, long hp); // 0x8002718C

extern long Motion2D_FireBallMove(struct _FIREBALL *fb); // 0x800272B0

extern void Motion2D_FireBallCompute(struct _FIREBALL *fb, long base); // 0x80027410

extern void Motion2D_FireBallImpact(struct _FIREBALL *fb); // 0x80027504

extern struct TASK * Motion2D_Flame(struct _D3_OBJECT *obj, struct MOTION2D_7fake *pos, struct MOTION2D_7fake *rot, long growth, long max, long power, long mode); // 0x80027830

extern void Motion2D_FlameModify(struct TASK *t, struct MOTION2D_7fake *pos, struct MOTION2D_7fake *rot); // 0x80027998

extern void Motion2D_FlameTask(); // 0x800279F4

extern void Motion2D_FlameTaskDisplay(); // 0x80027A90

extern void Motion2D_FlameDestructor(struct TASK *t); // 0x80027ABC

extern long Motion2D_FlameInit(struct _D3_OBJECT *obj, struct MOTION2D_71fake *list, struct MOTION2D_7fake *poses, struct MOTION2D_8fake *colors, long power, long max, long mode); // 0x80027AE8

extern long Motion2D_FlameCompute(struct _D3_OBJECT *obj, struct MOTION2D_71fake *list, struct MOTION2D_7fake *spd, long growth, long max, long disappear, long mode); // 0x80027C88

extern void Motion2D_FlameDisplay(struct MOTION2D_71fake *list); // 0x80028228

extern void Motion2D_Lightning(struct MOTION2D_7fake *s, struct MOTION2D_7fake *d, long r, long n); // 0x80028278

extern void Motion2D_LightningTask(); // 0x80028318

extern void Motion2D_LightningTaskDisplay(); // 0x800283C8

extern short Motion2D_LightningCompute(struct MOTION2D_7fake *s, struct MOTION2D_7fake *d, short r, struct MOTION2D_7fake *pts, int n); // 0x80028438

extern void Motion2D_LightningDisplay(struct MOTION2D_8fake *color, struct MOTION2D_7fake *pts, short n, short fbranche); // 0x800289AC

extern struct TASK * Motion2D_Storm(struct _D3_OBJECT *ot, long power, struct TASK **handle); // 0x800293C4

extern void Motion2D_StormEnd(struct TASK *t); // 0x80029420

extern void Motion2D_StormTask(); // 0x8002943C

extern void Motion2D_StormDisplay(); // 0x800296B4

extern struct TASK * Motion2D_Twister(struct _D3_OBJECT *ot, long type); // 0x800297D8

extern void Motion2D_TwisterEnd(struct TASK *t); // 0x8002981C

extern void Motion2D_TwisterTask(); // 0x8002982C

extern void Motion2D_TwisterTaskDisplay(); // 0x80029AB0

extern void Motion2D_DisplayTmd(struct MOTION2D_7fake *r, struct MOTION2D_6fake *s, struct MOTION2D_93fake *tmd, struct MOTION2D_8fake *col, void *ot, long otsize, struct MOTION2D_5fake *mn64); // 0x80029B8C

extern void Motion2D_SetTrans(struct MOTION2D_7fake *p, struct MOTION2D_5fake *mn64); // 0x80029C58

extern void Motion2D_SetRotTrans(struct MOTION2D_7fake *p, struct MOTION2D_7fake *r); // 0x80029CDC


#endif
