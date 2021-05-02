#ifndef MONSTER_H
#define MONSTER_H


extern long Monster_EmptyRoutine(struct _MONSTER *monst); // 0x80068520

extern long Monster_AcceptCollisioned(struct _D3_OBJECT *ot, struct _D3_OBJECT *obj, long flags); // 0x80068528

extern long Monster_Collisioned(struct _D3_OBJECT *ot, struct _D3_OBJECT *obj, long flags); // 0x80068680

extern void Monster_CreateShadow(struct _D3_OBJECT *D3Obj, struct MONSTER_31fake *pft4); // 0x800689F0

extern void Monster_DisplayText(struct _D3_OBJECT *obj); // 0x80068A70

extern struct _MONSTER * Monster_Main_Init(struct _D3_OBJECT *Target); // 0x80068AA8

extern void Monster_ReleaseBonuses(); // 0x80068C74

extern void Monster_Func_Display(); // 0x80068D04

extern void Monster_Main_SequenceDispatcher(); // 0x80068E20

extern void Monster_Main_Module(struct _MONSTER *Monster, unsigned long Mask); // 0x80068F48

extern void Monster_ExternForceAction(struct _D3_OBJECT *D3Obj, long Action, long Param); // 0x800699D4

extern long Monster_FSetAction(struct _MONSTER *monst, long Action, long Param); // 0x80069A24

extern void Monster_ForceAction(struct _MONSTER *monst, long Action, long Param); // 0x80069AC4

extern void Monster_StopAllActions(struct _MONSTER *monst); // 0x80069B44

extern void Monster_ResetActions(struct _MONSTER *monst); // 0x80069B54

extern void Monster_AddAction(struct _MONSTER *monst, long command, long action, long param1, long param2); // 0x80069B60

extern void Monster_AppendAction(struct _MONSTER *monst, long command, long action, long param1, long param2); // 0x80069B94

extern struct _D3_OBJECT * Monster_GetChild(struct _D3_OBJECT *obj, long childID); // 0x80069BF4

extern long Monster_DisplayChild(struct _D3_OBJECT *obj, long disp); // 0x80069C80

extern void Monster_StopChilds(struct _D3_OBJECT *o); // 0x80069CCC

extern void Monster_SyncChilds(struct _D3_OBJECT *o, struct M_OBJECT *mo, struct _MONSTER *monst, long Animation, long Animation2); // 0x80069D34

extern struct _D3_OBJECT * Monster_GetBrother(struct _D3_OBJECT *o, long opt2); // 0x80069E30

extern long Monster_TestLastSpell(struct _D3_OBJECT *o, long index); // 0x80069E80

extern void Monster_Action_SetBoundingBox(long sm, long height); // 0x80069EBC

extern void Monster_Action_RunAnimationSpeed(long AnimNr, long mode, long speed, long Gravity, long Sound); // 0x80069F44

extern void Monster_Action_SlayDirection(struct _D3_OBJECT *o, long Anim, long dist, struct _D3_OBJECT *to, struct _MONSTER *monst, long sound); // 0x8006A058

extern void Monster_Action_SlayingObject(struct _D3_OBJECT *o, long Anim, long dist, struct _D3_OBJECT *to, struct _MONSTER *monst, long sound); // 0x8006A4CC

extern void Monster_Action_Slaying(long Anim, long dist, struct _D3_OBJECT *to, long sound); // 0x8006A740

extern long Monster_FearFindFriends(struct _MONSTER *monst); // 0x8006A788

extern void Monster_Action_Falling(short AnimNr); // 0x8006A894

extern void Monster_Action_FollowObject(struct _D3_OBJECT *target, short AnimNr); // 0x8006AA60

extern short Monster_Action_WalkHandling(struct M_OBJECT *mo, struct _D3_OBJECT *o, short xx, short yy, int soundR, int soundL, int dist); // 0x8006AB30

extern long Monster_Action_WalkTo(short x_given, short y_given, short zz, struct _D3_OBJECT *target, int dist, int AnimSt, int AnimLoop, int AnimHalf, int AnimStop, int Sound, long option); // 0x8006B108

extern long Monster_Action_MoveTo3D(short xx, short yy, short zz, struct _D3_OBJECT *target, int dist, int AnimLoop, int AnimAttack, int AnimXtra1, int Anim180, int Sound, int AttSound); // 0x8006B700

extern void Monster_AdjustZ(struct _D3_OBJECT *obj, struct M_OBJECT *mo); // 0x8006BE94

extern void Monster_Adjust(struct _D3_OBJECT *o, struct _MONSTER *monst); // 0x8006C078

extern long Monster_Action_MoveTo(long xx, long yy, long zz, struct _D3_OBJECT *target, long dist, long AnimStart, long AnimLoop, long AnimStop, long AnimFall, long AnimJump, long Snd); // 0x8006C0FC

extern void Monster_Action_MoveGlide(struct _D3_OBJECT *target, short distance, short spd, short xx, int yy, int zz, long dodir); // 0x8006CAA8

extern void Monster_Action_Protect(short forcedtype, short timer, short AnimSit, short AnimStand, int AnimLeft, int AnimRight, int Sound); // 0x8006CDFC

extern void Monster_Reflex_Feasting(struct _MONSTER *monst); // 0x8006D108

extern void Monster_Reflex_SmallBeastAttack(struct _MONSTER *monst, short dist); // 0x8006D1A8

extern void Monster_ReflexCombat(struct _MONSTER *monst, long attdist, long resettimer); // 0x8006D2D4

extern void Monster_Action_Feast(struct _D3_OBJECT *o, struct _D3_OBJECT *tmpobj, long AnimRun, long AnimFeast, long power, long sound); // 0x8006D528

extern void Monster_Action_WaitRun(struct _MONSTER *monst, short AnimWait, short AnimRun, short distance, long follow, int snd); // 0x8006D6DC

extern void Monster_Action_Fear(struct _MONSTER *monst, long AnimWait, long AnimRun, long distance, long snd); // 0x8006D97C

extern long Monster_Reflex_Fear(struct _MONSTER *monst); // 0x8006DB18

extern long Monster_CalcShotPower(long whichshot, struct MONSTER_8fake *col); // 0x8006DBCC

extern void Monster_Action_ShootMultiple(long Anim, long Amount, long Heightpos, long waiter, long missing, long Sound, long type); // 0x8006DCE4

extern void Monster_Grenade_Add(struct _D3_OBJECT *o, struct _D3_OBJECT *target); // 0x8006EAB8

extern void Monster_Action_Shooting(long AnimStart, long AnimStop, long AnimShoot, long ShootType, long amount, long height, long missing, long waiter, long Sound); // 0x8006EBB8

extern void Monster_Action_BeingHit(long direction, long AnimNr, long param); // 0x8006F280

extern void Monster_Action_Exploding(long AnimNr, long direction); // 0x8006F3BC

extern void Monster_Action_Dieing(long AnimNr, long bottom); // 0x8006F5CC

extern long Monster_Action_Hit(long AnimHurt, long AnimDie, long param, long SndDead); // 0x8006F844

extern void Magic_StreamFire(); // 0x8006FF98

extern void Monster_Action_Magic(struct _MONSTER *monst, long move, long animstart, long animstop, long param); // 0x80070034

extern void Monster_Action_Flee(struct _MONSTER *monst, long anim, long wait, long sound); // 0x80070448


#endif
