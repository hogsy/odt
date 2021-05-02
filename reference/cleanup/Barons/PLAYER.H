#ifndef PLAYER_H
#define PLAYER_H


extern void Pl_Init(); // 0x80031A14

extern void Pl_InitPlayer(short p); // 0x80031A1C

extern void Pl_AddPlayer(struct _PLAYER *pl, long entry); // 0x800320B8

extern void Pl_DeletePlayer(struct _PLAYER *pl); // 0x80032134

extern void Pl_InitLevel(); // 0x80032164

extern void Pl_DeleteLevel(); // 0x800321FC

extern void Pl_DeleteWholePlayer(); // 0x8003224C

extern void Pl_Pause(); // 0x8003227C

extern void Pl_Unpause(); // 0x800322BC

extern void Pl_TaskTest(); // 0x80032304

extern void Pl_TaskMove(); // 0x800326F8

extern void Pl_TaskState(); // 0x800328E0

extern void Pl_ManageStateBits(struct _PLAYER *pl); // 0x80032D4C

extern void Pl_SetStateBits(struct _PLAYER *pl, long bits); // 0x8003302C

extern void Pl_ClearStateBits(struct _PLAYER *pl, long bits); // 0x80033150

extern void Pl_DisplayLookDisable(); // 0x80033188

extern long Pl_DisplayAir(); // 0x80033250

extern long Pl_AcceptCollisioned(struct _D3_OBJECT *ot, struct _D3_OBJECT *obj, long bits); // 0x80033438

extern long Pl_Collisioned(struct _D3_OBJECT *ot, struct _D3_OBJECT *obj, long bits); // 0x80033508

extern void Pl_TurnBackRot(struct _PLAYER *pl, long dx, long dy); // 0x80033718

extern void Pl_AdjustUse(struct _PLAYER *pl, struct PLAYER_7fake *pos, long rotz, long frot); // 0x800338F0

extern void Pl_AdjustPosZ(struct _PLAYER *pl); // 0x80033AC8

extern long Pl_TestHeight(struct _PLAYER *pl, long dist); // 0x80033D3C

extern void Pl_ReduceHitPoints(struct _PLAYER *pl, short hits); // 0x80033DF4

extern void Pl_AddExperience(struct _PLAYER *pl, struct _D3_OBJECT *ot); // 0x80033F44

extern long Pl_GetFlying(struct _PLAYER *pl); // 0x80033FFC

extern long Pl_IsWeaponAvailable(struct _PLAYER *pl, long weapon); // 0x80034024

extern long Pl_GetSpellCost(struct _PLAYER *pl, long spell); // 0x8003404C

extern long Pl_GetSpellLevel(struct _PLAYER *pl, long spell, long *spell_levels); // 0x80034194

extern void Pl_SetSpellLevel(struct _PLAYER *pl, long spell, long level, long *spell_levels); // 0x800341F4


#endif
