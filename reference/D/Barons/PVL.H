#ifndef PVL_H
#define PVL_H


extern void Pvl_Init(); // 0x80029D20

extern char * Pvl_GetAllName(); // 0x80029D28

extern char * Pvl_GetLnkName(); // 0x80029D60

extern char * Pvl_GetPclName(); // 0x80029D98

extern char * Pvl_GetSndName(); // 0x80029DD0

extern char * Pvl_GetTxtName(); // 0x80029E08

extern char * Pvl_GetLocName(); // 0x80029E3C

extern char * Pvl_GetBossName(); // 0x80029E70

extern void Pvl_GetXA(); // 0x80029EA4

extern void Pvl_StopXA(); // 0x80029EDC

extern void Pvl_PlayMovie(long movie); // 0x80029EFC

extern void Pvl_InitGame(); // 0x80029F64

extern void Pvl_AbortGame(); // 0x8002A294

extern void Pvl_DeleteGame(); // 0x8002A2C0

extern void Pvl_PlayGame(); // 0x8002A310

extern void Pvl_GameTask(); // 0x8002A374

extern void Pvl_PauseGame(); // 0x8002A5A0

extern void Pvl_UnpauseGame(); // 0x8002A63C

extern void Pvl_GreyScreen(); // 0x8002A684

extern void Pvl_InitLevel(); // 0x8002A7BC

extern void Pvl_DeleteLevel(); // 0x8002A954

extern void Pvl_InitMonsters(); // 0x8002A998

extern long Pvl_PlaySector(short sector, long entry); // 0x8002AA44

extern long Pvl_ExitSector(); // 0x8002ACE4

extern void Pvl_EngineTask(); // 0x8002B058

extern void Pvl_EngineDisplay(); // 0x8002B0EC

extern void Pvl_InitFile(short level, short sector, long Entry); // 0x8002B284

extern void Pvl_DeleteFile(); // 0x8002B698

extern void Pvl_InitBlink(); // 0x8002B770

extern void Pvl_ReadSector(); // 0x8002B8CC

extern void Pvl_SndToSram(void *file); // 0x8002B97C

extern void Pvl_ClearSctState(); // 0x8002BA18

extern void Pvl_SetSctState(); // 0x8002BAD4

extern void Pvl_UpdateSctState(); // 0x8002BD2C

extern void Pvl_UpdateListSctState(struct _D3_OBJECT *o); // 0x8002BFB0

extern void Pvl_SaveMonsters(); // 0x8002C0A0

extern void Pvl_CheckPoint(long entry, long fsound); // 0x8002C190

extern void Pvl_SetZoneStateBits(struct _ZONE *z, long v); // 0x8002C1F0

extern void Pvl_ClearZoneStateBits(struct _ZONE *z, long v); // 0x8002C21C

extern long Pvl_TestZoneStateBits(struct _ZONE *z, long v); // 0x8002C24C

extern void Pvl_ClearStateBits(struct _D3_OBJECT *o, long mask); // 0x8002C274

extern void Pvl_SetStateBits(struct _D3_OBJECT *o, long mask); // 0x8002C2A8

extern long Pvl_TestStateBits(struct _D3_OBJECT *o, long mask); // 0x8002C2DC

extern char * Pvl_AddMaxs(char *in); // 0x8002C30C

extern long Pvl_GetMaxNumber(char **in); // 0x8002C434

extern void Pvl_InitTexts(); // 0x8002C474

extern char * Pvl_InitLevelText(char *input, struct PVL_135fake *pvl_txt); // 0x8002C4E8

extern long * Pvl_GetSectorText(short crc); // 0x8002C508

extern void Pvl_DeleteTexts(); // 0x8002C5AC

extern long Pvl_SaveGame(struct _PLAYER *pl, long entry, long channel, long n, long flevel); // 0x8002C634

extern long Pvl_LoadGame(struct _PLAYER *pl, short channel, char *name); // 0x8002CE60


#endif
