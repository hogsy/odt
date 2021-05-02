#ifndef P_SPELL_H
#define P_SPELL_H


extern void PSpell_Spell(struct _PLAYER *pl, long spell); // 0x80040F0C

extern long PSpell_TestSelection(struct _PLAYER *pl, long spell); // 0x80040FD8

extern void PSpell_LongSpell(struct _PLAYER *pl, long spell, long level, long time); // 0x8004108C

extern void PSpell_RestoreSpell(struct _PLAYER *pl); // 0x80041104

extern void PSpell_EndSpell(struct _PLAYER *pl); // 0x800411A8

extern long PSpell_GetTargets(struct _PLAYER *pl, long spell, struct _D3_OBJECT **targets); // 0x80041220

extern long PSpell_SeekTargets(struct _PLAYER *pl, struct _D3_OBJECT **ot, long dist_max, long dir_max, long n_max); // 0x80041340

extern void PSpell_Effect(struct _PLAYER *pl, long spell, long start); // 0x80041414

extern void PSpell_EffectTask(); // 0x8004153C

extern void PSpell_EffectTaskDisplay(); // 0x80041728

extern void Earth_Healing(struct _PLAYER *pl, long level); // 0x80041A7C

extern void Earth_Mana(struct _PLAYER *pl, long level); // 0x80041AD0

extern void Earth_Minimize(struct _PLAYER *pl, long level); // 0x80041B24

extern void Earth_MegaBlast(struct _PLAYER *pl, long level); // 0x80041B68

extern void Earth_MegaBlastTask(); // 0x80041BA0

extern void Earth_MinimizeTask(); // 0x80041D34

extern void Earth_HealManaTask(); // 0x80042080

extern void Air_Teleport(struct _PLAYER *pl, long level); // 0x800421E8

extern void Air_Ghost(struct _PLAYER *pl, long level); // 0x8004225C

extern void Air_Lightning(struct _PLAYER *pl, long level); // 0x8004229C

extern void Air_Twister(struct _PLAYER *pl, long level); // 0x800422E8

extern void Air_TwisterTask(); // 0x80042334

extern void Air_LightningTask(); // 0x800424CC

extern void Air_GhostTask(); // 0x80042704

extern void Fire_Rain(struct _PLAYER *pl, long level); // 0x80042810

extern void Fire_Shield(struct _PLAYER *pl, long level); // 0x8004285C

extern void Fire_Missile(struct _PLAYER *pl, long level); // 0x800428B8

extern void Fire_Works(struct _PLAYER *pl, long level); // 0x800429A8

extern void Fire_ShieldTask(); // 0x80042AB0

extern void Fire_RainTask(); // 0x80042D84

extern void Water_Freeze(struct _PLAYER *pl, long level); // 0x80042E80

extern void Water_Antidote(struct _PLAYER *pl, long level); // 0x80042EEC

extern void Water_Vampire(struct _PLAYER *pl, long level); // 0x80042F30

extern void Water_Wall(struct _PLAYER *pl, long level); // 0x80042F74

extern void Water_AntidoteTask(); // 0x80042FB8

extern void Water_VampireTask(); // 0x80043098

extern void Water_WallTask(); // 0x800432B0

extern void Water_WallDisplay(); // 0x8004361C


#endif
