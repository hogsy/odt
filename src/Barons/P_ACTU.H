#ifndef P_ACTU_H
#define P_ACTU_H


extern void Pactu_Dead(); // 0x8003D53C

extern void Pafu_DeadByFall(); // 0x8003D6B8

extern void Pafu_DeadInLiquid(); // 0x8003D724

extern void Pactu_Hurt(); // 0x8003D83C

extern void Pafu_HurtWhileHold(struct _D3_OBJECT *oh); // 0x8003DAD0

extern void Pafu_HurtByShot(struct _D3_OBJECT *oh, long d); // 0x8003DB24

extern void Pafu_HurtByPics(struct _D3_OBJECT *ot); // 0x8003DC34

extern void Pafu_HurtByExplosion(struct _D3_OBJECT *oh, long d); // 0x8003DCCC

extern void Pafu_HurtByKick(struct _D3_OBJECT *oh, long d); // 0x8003DE4C


#endif
