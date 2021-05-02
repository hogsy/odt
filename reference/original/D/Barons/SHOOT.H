#ifndef SHOOT_H
#define SHOOT_H


extern struct _SHOOT * Shoot_Add(struct _D3_OBJECT *owner, struct SHOOT_7fake *pos, struct SHOOT_7fake *rot, struct SHOOT_8fake *col, long number, long size, long power, long mode); // 0x800436F4

extern void Shoot_Task(); // 0x80043898

extern void Shoot_SetAspect(struct _SHOOT *sh, long number, long size, long mode); // 0x80043954

extern void Shoot_SetFunctions(struct _SHOOT *sh); // 0x800439E0

extern void Shoot_SetVelocity(struct _SHOOT *sh); // 0x80043A24

extern void Shoot_DisplayShapes(); // 0x80043A58

extern void Shoot_Impact(struct _SHOOT *sh); // 0x80043C74

extern void Shoot_UpdateSound(struct _SHOOT *sh); // 0x80043CEC

extern void Shoot_StopLoopingSound(struct _SHOOT *sh); // 0x80043DA4

extern void Shoot_InitNormal(struct _SHOOT *sh); // 0x80043DF4

extern void Shoot_MoveNormal(); // 0x800440A4

extern void Shoot_ImpactNormal(); // 0x80044360

extern void Shoot_DestructorNormal(struct TASK *t); // 0x800443F0

extern void Shoot_DisplayCross(struct SHOOT_31fake *p); // 0x80044448

extern void Shoot_SeekPlayer(); // 0x800445C4

extern void Shoot_InitRiffle(struct _SHOOT *sh); // 0x8004497C

extern void Shoot_MoveRiffle(); // 0x800449DC

extern void Grenade_Add(struct SHOOT_7fake *pos, struct SHOOT_7fake *rot, long number, long distance, struct _D3_OBJECT *owner, long height); // 0x80044FC4

extern void Laser_Add(struct SHOOT_7fake *p, struct SHOOT_7fake *r, struct _D3_OBJECT *o, struct SHOOT_8fake *c); // 0x800450F0


#endif
