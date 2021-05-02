#ifndef SH_E01_H
#define SH_E01_H


extern void SHS01_Display(); // 0x80045174

extern void SHE02_Impact(); // 0x80045510

extern void SHE03_Move(); // 0x8004556C

extern void SHE03_Impact(); // 0x800458CC

extern void SHGE04_Init(struct _SHOOT *sh); // 0x80045914

extern void SHGE04_Move(); // 0x80045B04

extern void SHGE04_Impact(); // 0x80045CA0

extern void SHFE05_Init(struct _SHOOT *sh); // 0x80045CC8

extern void SHFE05_Destructor(struct TASK *t); // 0x80045F5C

extern void SHFE05_Move(); // 0x80045FA0

extern void SHE_LaserInitPrims(struct _SHOOT *sh, struct SH_E01_8fake *col1, struct SH_E01_8fake *col2); // 0x800468DC

extern void SHE_LaserInitVertices(struct SH_E01_7fake *pos); // 0x80046A68

extern void SHE_LaserSetPrims(struct _SHOOT *sh); // 0x80046E10

extern void SHE_LaserDisplayHilite(struct SH_E01_7fake *pos, struct SH_E01_31fake *p); // 0x80046FD0

extern void SHE_DisplayLaser(); // 0x80047144

extern void SHE07_Init(struct _SHOOT *sh); // 0x80047348

extern void SHE07_Move(); // 0x800475E8

extern void SHE07_Impact(); // 0x8004776C


#endif
