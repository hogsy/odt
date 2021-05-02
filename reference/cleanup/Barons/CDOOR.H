#ifndef CDOOR_H
#define CDOOR_H


extern void CB_Door_Main_Task(); // 0x8004E128

extern void Door_CheatObject(struct _D3_OBJECT *o); // 0x8004E334

extern void Door_ActivateChild(struct _D3_OBJECT *o, long activate); // 0x8004E478

extern void Door_DisplayChild(struct _D3_OBJECT *o, long disp); // 0x8004E4F8

extern void Door_Drawer(struct _D3_OBJECT *o); // 0x8004E5E0

extern void Door_EnemyTurn(struct _D3_OBJECT *o); // 0x8004EB74

extern long CDoor_ShouldOpen(struct _D3_OBJECT *o, long testkey, long zoneattached, long *Zone_Result); // 0x8004EE70

extern void Door_Dive_Once(struct _D3_OBJECT *D3Obj, long testkey); // 0x8004F060

extern void Door_Slide_Once(struct _D3_OBJECT *D3Obj, long testkey); // 0x8004F2B8

extern void Door_Turn_Once(struct _D3_OBJECT *D3Obj, long testkey, long type); // 0x8004F580

extern void Door_Dive_Normal(struct _D3_OBJECT *D3Obj, long testkey); // 0x8004FA0C

extern void Door_Slide_Normal(struct _D3_OBJECT *D3Obj, long testkey); // 0x8004FC90

extern void Door_Turn_Normal(struct _D3_OBJECT *D3Obj, long testkey, long type); // 0x80050018

extern void Door_Turn_Move(struct _D3_OBJECT *D3Obj, long Distance, long speed, long type); // 0x800502FC

extern void Door_End_Turn(struct _D3_OBJECT *D3Obj, long Distance, long speed, long type); // 0x800504EC

extern void Door_MoveChildren(struct _D3_OBJECT *o, long addx, long addy); // 0x8005057C

extern void Door_End_Move(struct _D3_OBJECT *D3Obj, long Distance, long speed, long direction); // 0x80050608

extern void Door_Slide_Move(struct _D3_OBJECT *D3Obj, long speed, long *Xs, long exzone, long direction); // 0x80050768

extern void Door_Slide_Dive(struct _D3_OBJECT *D3Obj, long speed, long *Xs, long exzone); // 0x80050AD0

extern void Door_End_Dive(struct _D3_OBJECT *D3Obj, long Distance, long speed); // 0x80050C88

extern void Door_GrilleLente(struct _D3_OBJECT *obj); // 0x80050CC0

extern void CB_Elevator_Main_Task(); // 0x80051078

extern void Platform_ShootSwitch(struct _D3_OBJECT *o); // 0x80051238

extern void Platform_ShootLock(struct _D3_OBJECT *o); // 0x800515F8

extern void Platform_Pince_Sucre(struct _D3_OBJECT *D3Obj, long Retour); // 0x8005179C

extern void Platform_Once(struct _D3_OBJECT *D3Obj, long X, long Y, long Z, long special); // 0x80051CA8

extern void Platform_Normal(struct _D3_OBJECT *D3Obj, long X, long Y, long Z, long normal); // 0x80052680

extern void Platform_DestEffect(struct TASK *t); // 0x80052AD8

extern void Platform_TreatEffects(); // 0x80052AFC

extern void Platform_Z_Exit(struct _D3_OBJECT *D3Obj, long reinit); // 0x80052B44

extern void Platform_Z_Set(struct _D3_OBJECT *D3Obj, long Distance, long speed); // 0x80052F1C

extern void Platform_Z_Movement(struct _D3_OBJECT *D3Obj, long Distance, long speed); // 0x80052F74

extern void CB_TrapsTask(); // 0x80053130

extern void Traps_OptimiseCollisions(); // 0x80053354

extern void Traps_ExploseWhenSwitched(struct _D3_OBJECT *o); // 0x800533A8

extern void Traps_FireWall(struct _D3_OBJECT *D3Obj); // 0x80053454

extern void Traps_Piston(struct _D3_OBJECT *D3Obj, long dust); // 0x8005392C

extern void Platform_Trimble(struct _D3_OBJECT *D3Obj, long speed, long time); // 0x800543F0

extern void Traps_DropAway(struct _D3_OBJECT *D3Obj); // 0x800546D4

extern void Traps_BloodyPinns(struct _D3_OBJECT *D3Obj, long XX, long YY, long ZZ); // 0x80054A18

extern void Traps_Bullet(struct _D3_OBJECT *D3Obj, long XX, long YY, long ZZ); // 0x80054EAC

extern void Traps_CreateBBox(long angle, long length, long YY, long hei, long wid, long len, struct CDOOR_7fake *bb); // 0x80055254

extern void Traps_Balance(struct _D3_OBJECT *D3Obj, long YY); // 0x800553A4

extern void Traps_CreateVentiloBBox(struct _D3_OBJECT *o, long offset); // 0x800556D4

extern void Traps_Ventilo(struct _D3_OBJECT *D3Obj); // 0x800558EC

extern void Traps_LethalPick(struct _D3_OBJECT *obj); // 0x80055B90

extern void Traps_Trappe(struct _D3_OBJECT *obj); // 0x80055C88

extern void Trps_ClearCollisions(struct _D3_OBJECT *o); // 0x80055E14

extern void Traps_VitreFragile(struct _D3_OBJECT *o); // 0x80055E6C

extern void Traps_HiddenGrenade(struct _D3_OBJECT *o); // 0x80055F64

extern void Traps_BroSurvive(struct _D3_OBJECT *o); // 0x800563D0


#endif
