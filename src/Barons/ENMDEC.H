#ifndef ENMDEC_H
#define ENMDEC_H


extern void Living_Decor_RobTab_B4(struct _D3_OBJECT *obj); // 0x8007CCF8

extern void EB_Living_Decor(); // 0x8007CDBC

extern void Dropped_Task_Action(); // 0x8007D0D8

extern void Captain_Sprite(); // 0x8007D64C

extern void Captain_Reflex(); // 0x8007D840

extern void Captain_GameOver(struct _D3_OBJECT *o, struct M_OBJECT *mo, short *SpeechTab); // 0x8007DAC4

extern void Captain_Task_Action(); // 0x8007DCD0

extern void Living_Decor_RobTab_Init(); // 0x8007EB24

extern short GetShoulder(struct _MONSTER *monst, struct ENMDEC_7fake *vec); // 0x8007EB4C

extern void Living_Decor_Bullet_Create(struct _D3_OBJECT *target); // 0x8007EC64

extern void Living_Decor_RobTab_Func_Reflex(); // 0x8007EDB4

extern void Living_Decor_Robtab_Func_Decisions(); // 0x8007EE60

extern void Living_Decor_RobTab_Task_Action(); // 0x8007EFC4

extern void Living_Decor_CyberBall_Init(); // 0x8007F2BC

extern void CyberBall_Private_Bullet_Launcher(struct _D3_OBJECT *target, struct _D3_OBJECT *obj, struct ENMDEC_7fake *pos); // 0x8007F398

extern void Living_Decor_CyberBall_Bullet_Create(struct _D3_OBJECT *target); // 0x8007F65C

extern void Living_Decor_CyberBall_Func_Reflex(); // 0x8007F72C

extern void Living_Decor_CyberBall_Func_Decisions(); // 0x8007FB48

extern void Living_Decor_CyberBall_Task_Action(); // 0x8007FBD4

extern void Living_Decor_Egnose_Breath(); // 0x8007FFC4

extern struct _D3_OBJECT * Living_Decor_Egnose_FindBaby(struct _D3_OBJECT *obj); // 0x800804D0

extern struct M_OBJECT * Living_Decor_Egnose_ResetBaby(struct _D3_OBJECT *obj, struct _D3_OBJECT *child); // 0x8008051C

extern void Living_Decor_Egnose_Task_Action(); // 0x80080600

extern void Living_Decor_Crumbling_Wall(); // 0x80080734

extern void Living_Decor_Crumble_Task_Action(); // 0x800808C4

extern void Asp_Func_Reflex(); // 0x80080944

extern void Asp_Task_Action(); // 0x80080A00

extern void Living_Decor_Camera_Task_Action(); // 0x80080DD8

extern void Living_Decor_Camera_Wait(); // 0x80080EC8

extern void Living_Decor_Camera_RotTarget(struct _D3_OBJECT *father, struct ENMDEC_7fake *pos, struct ENMDEC_7fake *angle, struct ENMDEC_7fake *result, int index); // 0x8008149C

extern void Camera_Shoot(struct _D3_OBJECT *target, struct _D3_OBJECT *obj, long index); // 0x80081680

extern void Living_Decor_Camera_Func_Reflex(); // 0x80081764


#endif
