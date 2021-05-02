#ifndef CBASE_H
#define CBASE_H


extern void CB_BonusTask(); // 0x80047860

extern void CB_BonusDisplay(); // 0x80047D0C

extern void CB_BonusDisplay2(); // 0x80047D68

extern void CB_BonusTestAmmo(struct _D3_OBJECT *o); // 0x80047D70

extern void CB_BonusTestMana(struct _D3_OBJECT *o); // 0x80047E24

extern void CB_TakeObject(struct _PLAYER *pl, struct _D3_OBJECT *o); // 0x80047EAC

extern void CB_TakeObjectDelete(struct _D3_OBJECT *o); // 0x80047FD4

extern void CB_TranslationTask(); // 0x80048074

extern void CB_TranslateDestructor(struct TASK *handle); // 0x8004863C

extern long Test_Interruptors(long mask); // 0x8004866C

extern void CB_TranslateObjects(struct _D3_OBJECT *o, struct CBASE_6fake *trans); // 0x80048688

extern void CB_RotateObjects(struct _D3_OBJECT *o, struct CBASE_6fake *rot, long RotList); // 0x8004874C

extern long CB_EndTransRot(struct _D3_OBJECT *o, long pos); // 0x8004880C

extern void CB_InvertTransRot(struct _D3_OBJECT *o, long *BeginPos, long *EndPos, struct CBASE_6fake *step); // 0x80048960

extern void CB_PontLevis(struct _D3_OBJECT *D3Obj, struct CBASE_6fake *step, long Begin, long End, long nbframes); // 0x800489C8

extern long CB_PontLevisTestEnd(struct _D3_OBJECT *o, struct CBASE_6fake *step, long begin, long end); // 0x80048D78

extern void CB_PontLevisChangeBBox(struct _D3_OBJECT *o); // 0x80048DD0

extern long CB_PontLevisTestZones(struct _D3_OBJECT *D3Obj, struct _D3_OBJECT *weight); // 0x8004905C

extern void CB_InterruptorTask(); // 0x800491C4

extern void CB_DalleInt(struct _D3_OBJECT *o); // 0x80049654

extern void CB_DalleRadio(struct _D3_OBJECT *o); // 0x800499CC

extern void CB_InterruptorSwitchONOFF(struct _D3_OBJECT *o, struct _D3_OBJECT *user); // 0x80049D84

extern void CB_MiscTask(); // 0x8004A10C

extern void CB_TeleportPod(struct _D3_OBJECT *o); // 0x8004A2B4

extern void CB_TeleportOut(struct _D3_OBJECT *o, struct _D3_OBJECT *ot); // 0x8004A364

extern void CB_SavePod(struct _D3_OBJECT *o); // 0x8004A49C

extern void CB_SavePodDisplay(); // 0x8004A708

extern void CB_SavePodDestructor(struct TASK *t); // 0x8004A7E4

extern void CB_Caisse47(struct _D3_OBJECT *caisse); // 0x8004A81C

extern void CB_PasseurSounds(struct CBASE_134fake *p); // 0x8004AC00

extern void CB_Passeur(struct _D3_OBJECT *obj); // 0x8004ADDC

extern void CB_PasseurState(); // 0x8004B264

extern void CB_WayByInterrupt(struct _D3_OBJECT *o); // 0x8004B718

extern void CB_Cascade(struct _D3_OBJECT *o); // 0x8004B928

extern void CB_CascadeDestructor(struct TASK *handle); // 0x8004BC20

extern char CB_CascadeGetRef(char *v); // 0x8004BC64

extern void CB_CascadeGetLimits(char *v, char *Low, char *High); // 0x8004BCA0

extern void CB_ToxicSmoke(struct _D3_OBJECT *o); // 0x8004BD00

extern void CB_SmokeSetBBox(struct _D3_OBJECT *o); // 0x8004BF60

extern void CB_JetDeau(struct _D3_OBJECT *o); // 0x8004C244

extern void CB_StreamSetSpeed(struct _D3_OBJECT *o, struct CBASE_7fake *spd, long value); // 0x8004C7D8

extern void CB_PushedIfInterrupt(struct _D3_OBJECT *o); // 0x8004C8A8

extern void CB_Stalagtite(struct _D3_OBJECT *o); // 0x8004C9F4

extern void CB_Dangerous(struct _D3_OBJECT *o); // 0x8004CA5C

extern void CB_FireWall(struct _D3_OBJECT *o); // 0x8004CAF4

extern void CB_FireWallDestructor(struct TASK *handle); // 0x8004CD28

extern void CB_WallAhPuch(struct _D3_OBJECT *o); // 0x8004CD60

extern void CB_GreenPearl(struct _D3_OBJECT *o); // 0x8004D01C

extern long CB_PearlRSonsVisible(struct _D3_OBJECT *o); // 0x8004D1E0

extern void CB_PearlSetSonsInvisible(struct _D3_OBJECT *o); // 0x8004D244

extern void CB_Laser39(struct _D3_OBJECT *o); // 0x8004D29C

extern long CB_Laser39GetNChild(struct _D3_OBJECT *o); // 0x8004D420

extern void CB_Grue28(struct _D3_OBJECT *o); // 0x8004D45C

extern void CB_Grue28Destructor(struct TASK *handle); // 0x8004D500

extern void CB_LoopingSound(struct _D3_OBJECT *o); // 0x8004D558

extern void CB_LoopingSoundDestructor(struct TASK *handle); // 0x8004D5DC

extern void CB_FloatingTask(); // 0x8004D618

extern void CB_Float(struct _D3_OBJECT *ot, struct _D3_OBJECT *oc); // 0x8004D7D8

extern void CB_Float4aWhile(struct _D3_OBJECT *o, short angle, short time, short speed); // 0x8004D9BC

extern long CB_InitAngle(long angle, long speed, long *sens); // 0x8004DB1C

extern long CB_TestPlanteExplosion(struct _D3_OBJECT *o, long Explode, long Z); // 0x8004DBD0

extern void CB_PlanteTask(); // 0x8004DC7C

extern void CB_Lvl4_05(struct _D3_OBJECT *o); // 0x8004DF88


#endif
