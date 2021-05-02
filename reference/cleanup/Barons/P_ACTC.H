#ifndef P_ACTC_H
#define P_ACTC_H


extern void Pactc_Esquive(); // 0x8003B530

extern long Pafc_TestEsquive(struct _PLAYER *pl, long nana); // 0x8003B874

extern void Pafc_SetEsquive(struct _PLAYER *pl); // 0x8003BA7C

extern long Pafc_TestStandUp(struct _PLAYER *pl); // 0x8003BAD0

extern void Pactc_Shot(); // 0x8003BB3C

extern void Pafc_Reload(struct _PLAYER *pl, long anm); // 0x8003BECC

extern void Pafc_ExecKick(); // 0x8003BF9C

extern long Pafc_ExecShot(long recul_anm, long first); // 0x8003C3A0

extern void Pactc_Bomb(); // 0x8003C96C

extern void Pactc_UseCanon(); // 0x8003CB0C


#endif
