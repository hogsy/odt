#ifndef P_ACT_H
#define P_ACT_H


extern void Pl_GetAction(struct _PLAYER *pl); // 0x800352A8

extern void Pl_SetAction(struct _PLAYER *pl, long Action, long Param); // 0x80035BA0

extern void Pl_ForceAction(struct _PLAYER *pl, long Action, long Param); // 0x80035BE8

extern void Pact_StartSector(); // 0x80035C2C

extern void Pact_ExitSector(); // 0x80035D34

extern void Pact_Save(); // 0x80035DFC

extern void Paf_TeleportOut(struct _D3_OBJECT *ou); // 0x80035F30

extern void Paf_TeleportIn(struct _D3_OBJECT *ou); // 0x80035FCC

extern void Paf_TeleportEffectTask(); // 0x800360A0

extern void Paf_EnterSector(struct _ZONE *zone, struct _D3_OBJECT *o); // 0x800361E0

extern void Pact_Wait(); // 0x800364EC

extern void Paf_Look(struct _PLAYER *pl); // 0x80036648

extern void Pact_Freeze(); // 0x80036724

extern void Pact_Use(); // 0x80036994

extern void Paf_UseSas(struct _D3_OBJECT *ou); // 0x80036CFC

extern void Paf_UseCustom(struct _D3_OBJECT *ou); // 0x80036F38

extern void Paf_TestUse(); // 0x80036F68

extern struct _D3_OBJECT * Paf_TestUsePossible(struct _PLAYER *pl); // 0x80037128

extern void Pact_Spell(); // 0x8003715C


#endif
