#ifndef INVENTRY_H
#define INVENTRY_H


extern void Invent_Init(); // 0x800838E8

extern void Invent_AppearTask(); // 0x8008394C

extern void Invent_GoToScreen(); // 0x80083A58

extern void Invent_DisappearTask(); // 0x80083B60

extern void Invent_OuttaScreen(); // 0x80083BF4

extern void Invent_Task(); // 0x80083C84

extern void Invent_InitBackGround(); // 0x80084394

extern void Invent_InitArrows(); // 0x800844D8

extern void Invent_MoveCadre(); // 0x8008467C

extern void Invent_MoveArrows(); // 0x80084730

extern void Invent_MoveHelp(short valx); // 0x80084820

extern void Invent_Display(); // 0x80084A04

extern void Invent_DisplayButtons(); // 0x80084CC8

extern void Invent_DisplayArrow(long arrow); // 0x80084D5C

extern void Invent_ObjectDisplay(); // 0x80084DF0

extern long Invent_IsNameFemale(char *str); // 0x800851C0

extern long Invent_SPRINT_A(char *name, char *str, long A); // 0x80085208

extern long Invent_SPRINT_AB(char *str, long A, long B, long Invert); // 0x80085268

extern long Invent_D3GetName(struct _D3_OBJECT *o, struct _TAKEN_OBJECT *to, char *name); // 0x80085344

extern void Invent_DisplayObjectName(struct _TAKEN_OBJECT *to, short index); // 0x80085880

extern void * Invent_DisplayTmd(struct _TAKEN_OBJECT *to, void *otl, void *Prims, long hilite); // 0x8008594C

extern void * Invent_GtxTmd(struct INVENTRY_93fake *tmd, long dispmode, struct INVENTRY_5fake *mn64, void *otl, long col, void *Prims); // 0x80085B4C

extern void Invent_SetLightMatrices(struct INVENTRY_5fake *mr); // 0x80085BF4

extern void Invent_SetBoxCenter(struct _D3_OBJECT *obj); // 0x80085DB8

extern void Invent_SetCamera(struct _D3_OBJECT *obj, short dist); // 0x80085EC8

extern void Invent_Update(struct _PLAYER *pl); // 0x80085F58

extern void Invent_SetTotalObjects(); // 0x80086078

extern short Invent_AddObject(struct _PLAYER *pl, struct _D3_OBJECT *obj); // 0x800860C0

extern short Invent_ObjectIsStored(struct _PLAYER *pl, struct _D3_OBJECT *obj); // 0x80086430

extern long Invent_D3IsTheSame(struct _D3_OBJECT *o1, struct _D3_OBJECT *o2); // 0x800866CC

extern long Invent_SetCarac(long carac, long value); // 0x80086744

extern short Invent_IsFull(); // 0x80086760

extern long Invent_GetTakenIndex(long type, long elem); // 0x800867A8

extern long Invent_GetFreeTakenObject(); // 0x800867F8

extern void Invent_SortPlayerIndices(); // 0x80086838

extern short Invent_GetNbObjects(short type, short elem); // 0x80086A70

extern struct _D3_OBJECT * Invent_GetDroppedD3(short type); // 0x80086B94

extern long Invent_GetDroppedIndex(short type, long index); // 0x80086BF4

extern void Invent_UnDropObject(long index); // 0x80086C7C

extern void Invent_RemoveObjInPlayer(struct _PLAYER *pl, struct _INVENT_LIST *l, long start); // 0x80086D28

extern long Invent_RemoveDroppedObject(struct _D3_OBJECT *obj); // 0x80086DBC

extern void Invent_RemoveUsedObject(long type, long elem, long mode); // 0x80086E08

extern void Invent_RemoveUsedKey(long mask, long force); // 0x80086F6C

extern void Invent_RemoveMarkedObject(long limit); // 0x8008722C

extern void Invent_UseInventBack(struct _PLAYER *pl); // 0x80087374

extern long Invent_UseObject(struct _PLAYER *pl); // 0x80087420

extern void Invent_PlayerReload(); // 0x80087B84

extern void Invent_PlayerReloadTask(); // 0x80087BAC

extern void Invent_AutomaticDrop(struct _PLAYER *pl); // 0x80087C2C

extern long Invent_DropObject(struct _PLAYER *pl); // 0x80087CD0

extern void Invent_LaunchD3Object(struct _PLAYER *pl, short num); // 0x80087DF4

extern void Invent_ReleaseLocalObjects(); // 0x80087EF0

extern void Invent_DeleteDropped(); // 0x80087FC0

extern void Invent_InitTakenObjects(); // 0x80088020

extern void Invent_SetTakenObjects(); // 0x80088088

extern long Invent_InitGlobalObject(long glob_index); // 0x800881CC

extern void Invent_InitLoaded(); // 0x800884C0

extern void Invent_InitAlertWindow(); // 0x80088634

extern void Invent_Alert(char *message, short mode); // 0x800886A0

extern short Invent_GetElemNumber(struct _TAKEN_OBJECT *to); // 0x800889A8

extern void Invent_UpdateMultiObject(struct _TAKEN_OBJECT *to, struct _D3_OBJECT *obj); // 0x80088A1C

extern long Invent_MultiIsComplete(struct _TAKEN_OBJECT *to); // 0x80088AA0

extern long Invent_IsMultiPresent(long multi_number, long subobject_index); // 0x80088AE4

extern void Invent_SetAllInvisible(struct _PLAYER *pl); // 0x80088B94

extern long Invent_CountInvisible(); // 0x80088D64

extern void Invent_SetAllVisible(struct _PLAYER *pl); // 0x80088DA0

extern long Invent_AddSpell(struct _PLAYER *pl, struct _TAKEN_OBJECT *to); // 0x80088F8C

extern void Invent_BuildSpellList(struct _PLAYER *pl); // 0x8008908C

extern void Invent_SpellDisplay(); // 0x80089118

extern void Invent_DisplaySpellLevels(long numspell, long index, unsigned char col); // 0x800895FC

extern void Invent_DisplaySpellName(short index, short spell); // 0x8008986C

extern long Invent_GetSpellColor(short spell, long hilite); // 0x80089950

extern short Invent_UseSpell(struct _PLAYER *pl, short index); // 0x80089A0C

extern long Invent_SpellGetPos(struct _PLAYER *pl, long index); // 0x80089AE0

extern void Invent_SpellGoToButton(struct _PLAYER *pl, long index); // 0x80089B24

extern void Invent_SpellGoToButtonTask(); // 0x80089B84

extern void Invent_FlyObject(struct _TAKEN_OBJECT *to, long multi); // 0x8008A0D8

extern void Invent_FlyObjectTask(); // 0x8008A11C

extern long Invent_ReloadAmmo(struct _PLAYER *pl); // 0x8008A44C


#endif
