#ifndef MOTION_H
#define MOTION_H


extern void Motion_Init(); // 0x800A465C

extern void Motion_InitEnv(struct MOTION_96fake *Env, struct MOTION_72fake *Tmd); // 0x800A4664

extern void Motion_InitAni(struct MOTION_98fake *buff); // 0x800A46A0

extern void Motion_EnvRotTransPers(struct MOTION_94fake *sq, struct MOTION_96fake *env, struct MOTION_97fake *AnItem, short nFrame, struct MOTION_7fake *pos, struct MOTION_7fake *rot, long scale, TDRFuncPtr_Motion_EnvRotTransPers7modify modify); // 0x800A47C0

extern void Motion_EnvPersMat(struct MOTION_5fake *Father, short PivotId); // 0x800A4A64

extern void Motion_EnvPersAng(struct MOTION_5fake *Father, short PivotId); // 0x800A4CC4

extern void __rdata_obj() ; // 0x800A5000


typedef void (*TDRFuncPtr_Motion_EnvRotTransPers7modify)();




#endif
