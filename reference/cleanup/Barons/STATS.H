#ifndef STATS_H
#define STATS_H


extern void Stats_Init(); // 0x8008A490

extern void Stats_PrepareDisplay(long sx, long sy); // 0x8008A4DC

extern void Stats_SetHilite(long mode); // 0x8008AA64

extern void Stats_SetTanks(long sx, long sy); // 0x8008AB04

extern void Stats_SetTanksLevels(long sx, long sy); // 0x8008AE78

extern void Stats_SetHiliteTanks(); // 0x8008B40C

extern void Stats_SetPowerColor(struct STATS_31fake *p, long num_power, long num_weapon); // 0x8008B518

extern void Stats_Display(); // 0x8008B5B0

extern void Stats_Task(); // 0x8008BC90

extern void Stats_StopSound(); // 0x8008C544

extern void Stats_Appear(); // 0x8008C588

extern void Stats_AppearTask(); // 0x8008C5B0

extern void Stats_Disappear(); // 0x8008C6B0

extern void Stats_DisappearTask(); // 0x8008C6D8

extern void Stats_IncExperience(struct _PLAYER *pl, short coef); // 0x8008C784

extern void Stats_DecExperience(struct _PLAYER *pl, short coef); // 0x8008C7B4

extern void Stats_DisplayWeaponLevel(long level); // 0x8008C7DC

extern void Stats_DisplaySpiritLevel(long level); // 0x8008C830

extern void Stats_SpiritLevelTask(); // 0x8008C884

extern void Stats_SpiritLevelInit(long level, struct STATS_36fake *prims, long mode); // 0x8008C9DC

extern void Stats_SpiritLevelDestructor(struct TASK *t); // 0x8008CAFC

extern void Stats_LifeAppear(); // 0x8008CB08

extern void Stats_LifeTask(); // 0x8008CB58

extern void Stats_LifeDisplay(long posx, long posy, struct STATS_31fake *pft4); // 0x8008CD34

extern void Stats_LifeDestructor(struct TASK *t); // 0x8008CE50

extern void * Stats_DisplayMonsterLives(struct _D3_OBJECT *o, void *Prims); // 0x8008CE5C

extern void Stats_GameOver(); // 0x8008D198

extern void Stats_GameOverTask(); // 0x8008D1C0

extern void Stats_LoadingStart(); // 0x8008D3A0

extern void Stats_LoadingEnd(); // 0x8008D3E8

extern void Stats_LoadingTask(); // 0x8008D404

extern void Stats_LoadingDestructor(struct TASK *t); // 0x8008D804

extern void Stats_LoadingInit(struct STATS_31fake *prims); // 0x8008D810

extern void Stats_EndOfLevel(); // 0x8008D9E4

extern void Stats_EOLTask(); // 0x8008DA0C

extern long Stats_EOLComputeStat(long n, long max); // 0x8008E088

extern void Stats_EOLDisplayBG(); // 0x8008E0EC

extern void Stats_EOLDisplay(long sItems, long sMonsters, long sSecrets, long sGaz, long sTime, long mark); // 0x8008E234

extern void Stats_EOLDispPoints(long sItems, long sMonsters, long sSecrets, long sGaz, long sTime, struct STATS_36fake *pl, long perfect); // 0x8008E3E4

extern void Stats_EOLDispMark(long mark, long posx, long posy); // 0x8008E590

extern void Stats_EOLDisplayLine(struct STATS_36fake *pl, long posx, long posy); // 0x8008E608

extern void Stats_EOLDestructor(); // 0x8008E698

extern long Stats_EOLWait(); // 0x8008E6A4

extern void Stats_AtTheMax(); // 0x8008E6B0

extern void Stats_ATMTask(); // 0x8008E70C

extern void Stats_ATMInit(struct STATS_31fake *pft4); // 0x8008E930

extern void atoi() ; // 0x8008EA18


#endif
