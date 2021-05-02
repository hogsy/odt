#ifndef OVERLAY_H
#define OVERLAY_H


extern void Overlay_Init(); // 0x8005B364

extern void Overlay_Delete(); // 0x8005B454

extern void Overlay_EndSector(); // 0x8005B498

extern void Overlay_SetPrims(); // 0x8005B55C

extern void Overlay_SetSpellsPrims(); // 0x8005BAD0

extern void Overlay_SetHealthPrims(); // 0x8005BD70

extern void Overlay_RotBoussole(struct OVERLAY_31fake *Prims, long PosX, long PosY); // 0x8005C140

extern void Overlay_Task(); // 0x8005C4D8

extern void Overlay_Display(); // 0x8005C664

extern void Overlay_MoveHealthBar(short mode); // 0x8005CDCC

extern void Overlay_MoveHealthAwayTask(); // 0x8005CE1C

extern void Overlay_MoveHealthBackTask(); // 0x8005CEC8

extern void Overlay_SpellsAppear(); // 0x8005CF74

extern void Overlay_SpellsDisappear(long mode); // 0x8005CFD8

extern void Overlay_SetSpellOFF(long value); // 0x8005D06C

extern void Overlay_UpdateBoss(long value); // 0x8005D0A8

extern void Overlay_SpellsAppearTask(); // 0x8005D0E8

extern void Overlay_SpellsDisappearTask(); // 0x8005D178

extern void Overlay_InventAppear(); // 0x8005D1D0

extern void Overlay_InventDisappear(); // 0x8005D220

extern void Overlay_ChangeRWeapon(struct _PLAYER *pl, short offset); // 0x8005D270

extern void Overlay_ChangeLWeapon(struct _PLAYER *pl, short offset); // 0x8005D344

extern void Overlay_SetText(char *str); // 0x8005D494

extern void Overlay_SetTextTask(); // 0x8005D4F8

extern void Overlay_SetBossPrims(long percent); // 0x8005D5C0

extern void Overlay_MoveBossPrims(long offset); // 0x8005D804

extern void Overlay_BossAppear(); // 0x8005D8A4

extern void Overlay_BossDisappear(); // 0x8005D8CC

extern void Overlay_BossAppearTask(); // 0x8005D8F4

extern void Overlay_BossDisappearTask(); // 0x8005D974

extern void Overlay_BlinkBossPrims(); // 0x8005D9D0

extern void Overlay_BlinkBossPrimsTask(); // 0x8005DA08

extern void Overlay_BlinkBossDestructor(struct TASK *handle); // 0x8005DA20

extern void Overlay_BlinkState(); // 0x8005DA34

extern void Overlay_BlinkStateTask(); // 0x8005DA6C

extern void Overlay_BlinkStateDestructor(struct TASK *handle); // 0x8005DB2C

extern void Overlay_DisplayPicture(char *FileName, long w, long time); // 0x8005DB58

extern void Overlay_FreePicture(); // 0x8005DCA4

extern void Overlay_PictureFunc(); // 0x8005DCCC


#endif
