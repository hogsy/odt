#ifndef P_ANIMAL_H
#define P_ANIMAL_H


extern void Pan_AddAnimal(struct _PLAYER *pl, void *Lnk); // 0x80034258

extern void Pan_Task(); // 0x800343C8

extern void Pan_Display(); // 0x80034498

extern void Pan_ActMove(); // 0x8003465C

extern void Pan_ActAttack(); // 0x80034894

extern long Pan_MoveFly(struct _D3_OBJECT *obj, long attack); // 0x800348C0

extern long Pan_LandOnObject(struct _D3_OBJECT *obj); // 0x80034C30

extern void Pan_TakeOff(); // 0x80034F58

extern void Pan_Attack(struct _D3_OBJECT *obj); // 0x80034FBC

extern long Pan_TestObject(struct _D3_OBJECT *obj, struct _PLAYER *pl, long fmove); // 0x80035100

extern void Pan_GetLandPos(struct _D3_OBJECT *obj, struct P_ANIMAL_7fake *out); // 0x800351E4


#endif
