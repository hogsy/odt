#ifndef SFX_H
#define SFX_H


extern void SFX_Init(); // 0x8005DD18

extern void SFX_Delete(); // 0x8005DE10

extern void SFX_ExplodeObject(struct _D3_OBJECT *o); // 0x8005DE40

extern void SFX_Explosion(struct SFX_7fake *pos, long ExType, long ExMaterial); // 0x8005DF64

extern void SFX_AddExplosion(struct _D3_OBJECT *o, long type, long pointfixe); // 0x8005E14C

extern void SFX_ExplosionTask(); // 0x8005E440

extern void SFX_ApocalypseInit(struct _D3_OBJECT *o); // 0x8005E4AC

extern void SFX_ApocalypseTask(); // 0x8005E4E8

extern void SFX_BounceSpeed(struct _D3_OBJECT *o, struct SFX_7fake *spd, long frottement); // 0x8005E5E0

extern long SFX_TestSpeed(struct SFX_118fake *ex, struct SFX_7fake *pos, struct SFX_7fake *spd); // 0x8005E6F0

extern long SFX_TestVectorSpeed(struct SFX_7fake *pos, struct SFX_7fake *spd); // 0x8005E728

extern long SFX_IsPieceClipped(struct SFX_7fake *pos); // 0x8005E7B4

extern long SFX_GetPieceSpeed(struct SFX_118fake *ex, struct SFX_7fake *pos, long piece); // 0x8005E878

extern long SFX_IsPiecePresent(); // 0x8005EC08

extern void SFX01_Init(struct SFX_118fake *ex); // 0x8005EC50

extern void SFX01_Destructor(struct TASK *t); // 0x8005EEE0

extern void SFX01_MoveExplosion(); // 0x8005EF20

extern void SFX01_MoveSmoke(); // 0x8005F294

extern void SFX01_DispExplosion(); // 0x8005F450

extern void SFX01_DispSmoke(); // 0x8005F670

extern void SFX02_Init(struct SFX_118fake *ex, long nPart); // 0x8005F888

extern void SFX02_Destructor(struct TASK *t); // 0x8005FB10

extern void SFX02_MoveExplosion(); // 0x8005FB58

extern void SFX02_DontMove(); // 0x8005FC78

extern void SFX02_DispExplosion(); // 0x8005FD34

extern void SFX02_DispPieces(); // 0x8005FF4C

extern void SFX04_Init(struct SFX_118fake *ex, long nb_part, long num_sprt, long nb_sprt); // 0x800600E4

extern void SFX04_Destructor(struct TASK *t); // 0x80060708

extern void SFX04_MoveExplosion(); // 0x8006079C

extern void SFX04_DispExplosion(); // 0x800609E0

extern void SFX05_Init(struct SFX_118fake *ex, long circle, long mode); // 0x80060AE8

extern void SFX05_Destructor(struct TASK *t); // 0x80060B58

extern void SFX05_MoveExplosion(); // 0x80060B78

extern void SFX05_DispExplosion(); // 0x80060D68

extern void SFX_IncendieInit(struct _D3_OBJECT *obj); // 0x80060F40

extern void SFX_IncendieDestructor(); // 0x80060FCC

extern void SFX_IncendieWithPosTask(); // 0x80061010

extern void D3_Splash(struct _D3_OBJECT *obj); // 0x80061270

extern void SplashInit(struct _D3_OBJECT *obj, struct _SPLASH *splash); // 0x8006130C

extern void SFX_LightRay(struct SFX_7fake *pos, long nb); // 0x80061434

extern void SFX_LightRayTask(); // 0x800614A8

extern void SFX_LightRayInit(struct _LIGHTRAY *lr); // 0x8006176C

extern void SFX_ShockWave(long type, struct SFX_7fake *pos, struct SFX_8fake *col, long flag); // 0x8006197C

extern void SFX_ShockWaveTask(); // 0x80061A5C

extern void SFX_ShockSetVertices(long ray1, long ray2); // 0x80061B64

extern void SFX_ShockSetPrims(); // 0x80061DB4

extern void SFX_Fusion(struct _D3_OBJECT *owner, struct SFX_7fake *pos, long power, long rotz, long dist, long col); // 0x8006218C

extern void SFX_FusionTask(); // 0x80062258

extern void SFX_FusionInit(struct _D3_OBJECT *o); // 0x80062310

extern long SFX_FusionIsON(); // 0x80062594

extern void SFX_FusionGrow(); // 0x800625EC

extern void SFX_FusionDisplay(struct _D3_OBJECT *o); // 0x80062654

extern void SFX_FusionDisplayRay(struct SFX_7fake *p, long h, long grey); // 0x80062790

extern long SFX_FusionSetPolyF4(long index, long z, long grey); // 0x800628B8

extern long SFX_FusionSetPolyG4(long index, long z, long grey); // 0x80062ADC

extern void SFX_FusionSetPolyFT4(long z, long grey); // 0x80062E2C

extern void SFX_Magic(struct SFX_7fake *pos, struct SFX_8fake *col, long nb_part); // 0x80062F24

extern void SFX_MagicTask(); // 0x80062FE0

extern void SFX_MagicInit(struct _MAGIC *f); // 0x800630AC

extern void SFX_MagicMove(struct _MAGIC *f, long mode); // 0x800632AC

extern void SFX_MagicDisplay(struct _MAGIC *f); // 0x80063534

extern void SFX_D3ShakeScreen(struct _D3_OBJECT *o1, struct _D3_OBJECT *o2, long time, long amplitude); // 0x80063688

extern void SFX_ShakeScreen(long time, long amplitude); // 0x80063730

extern void SFX_ShakeScreenTask(); // 0x80063788

extern void SFX_ShakeScreenDestructor(struct TASK *handle); // 0x80063840

extern struct TASK * SFX_Stream(struct SFX_7fake *pos, struct SFX_7fake *rot, struct SFX_7fake *trans, long num_shp, long nb, struct _SPEED_RAND *speed, long size, long size_step, struct _INTPL_COLOR *col, int flags); // 0x80063864

extern void SFX_StreamDisplay(); // 0x800639C8

extern void SFX_StreamTask(); // 0x80063A20

extern void SFX_StreamInit(); // 0x80063DA4

extern void SFX_StreamDestructor(struct TASK *t); // 0x80063E6C

extern void SFX_StreamCreate(long index); // 0x80063EA4

extern struct TASK * SFX_StreamSteam(struct SFX_7fake *pos, struct SFX_7fake *spd, long flag); // 0x800643E4

extern struct TASK * SFX_StreamGeiser(struct SFX_7fake *pos, struct SFX_7fake *spd); // 0x800644D0

extern struct TASK * SFX_StreamFire(struct _D3_OBJECT *obj); // 0x800645F8

extern struct TASK * SFX_StreamBubble(struct SFX_7fake *pos, long transZ); // 0x800646B8

extern struct TASK * SFX_StreamWarminMissile(struct _D3_OBJECT *obj, struct SFX_7fake *spd, short size); // 0x8006477C

extern struct TASK * SFX_StreamMissile(struct _D3_OBJECT *obj); // 0x80064878

extern struct TASK * SFX_StreamSmokyFire(struct _D3_OBJECT *obj); // 0x80064938

extern struct TASK * SFX_StreamFireWall(struct SFX_7fake *pos); // 0x800649F8

extern struct TASK * SFX_StreamWaterFall(struct SFX_7fake *pos); // 0x80064AB4

extern struct TASK * SFX_StreamReactor(struct SFX_7fake *pos, struct SFX_7fake *rot, struct SFX_7fake *trans); // 0x80064B64

extern struct TASK * SFX_StreamTracingBullet(struct _D3_OBJECT *obj, struct SFX_7fake *spd, long nb_part); // 0x80064C18

extern struct TASK * SFX_StreamTracingImpact(struct _D3_OBJECT *obj, struct SFX_7fake *spd); // 0x80064D20

extern struct TASK * SFX_StreamBirth(struct SFX_7fake *pos, struct SFX_7fake *rot); // 0x80064E48

extern struct TASK * SFX_StreamCone(struct SFX_7fake *pos, struct SFX_7fake *rot, struct SFX_8fake *col); // 0x80064F00

extern struct TASK * SFX_StreamExplosion(struct SFX_7fake *pos, struct SFX_7fake *rot, struct SFX_8fake *col); // 0x80065048


#endif
