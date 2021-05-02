#ifndef D3_H
#define D3_H


extern void D3_SetCollBits(struct _D3_OBJECT *o, long bits); // 0x8001A19C

extern void D3_ClearCollBits(struct _D3_OBJECT *o, long bits); // 0x8001A210

extern void D3_SetBox(struct _D3_OBJECT *o, long nx, long ny, long nz, long xx, long xy, long xz); // 0x8001A250

extern void D3_SetLowBox(struct _D3_OBJECT *o, long nx, long ny, long xx, long xy, long z); // 0x8001A2C0

extern void D3_SetHighBox(struct _D3_OBJECT *o, long nx, long ny, long xx, long xy, long z); // 0x8001A2FC

extern void D3_SetHighBoxZ(struct _D3_OBJECT *o, long z); // 0x8001A338

extern void D3_SetLowBoxZ(struct _D3_OBJECT *o, long z); // 0x8001A34C

extern void D3_InsertObject(struct _D3_OBJECT *obj, struct _D3_OBJECT **list); // 0x8001A360

extern void D3_DeleteObject(struct _D3_OBJECT *obj); // 0x8001A394

extern void D3_ExplodeObject(struct _D3_OBJECT *obj); // 0x8001A4B8

extern void D3_MoveWithObject(struct _D3_OBJECT *ot, struct _D3_OBJECT *oc); // 0x8001A56C

extern void D3_MoveList(struct _D3_OBJECT *obj, struct D3_7fake *spd); // 0x8001A6FC

extern void D3_RotList(struct _D3_OBJECT *obj, struct D3_7fake *rot); // 0x8001A7A4

extern void D3_ExplodeList(struct _D3_OBJECT *obj); // 0x8001A8A0

extern void D3_SetColorList(struct _D3_OBJECT *obj, long color); // 0x8001A8F4

extern void D3_SetDisplayBitsList(struct _D3_OBJECT *obj, long mask); // 0x8001A950

extern void D3_ClearDisplayBitsList(struct _D3_OBJECT *obj, long mask); // 0x8001A9B8

extern void D3_SetCollBitsList(struct _D3_OBJECT *obj, long mask); // 0x8001AA2C

extern void D3_ClearCollBitsList(struct _D3_OBJECT *obj, long mask); // 0x8001AA90

extern void D3_StopMotion(struct _D3_OBJECT *obj); // 0x8001AAF4

extern void D3_RunMotion(struct _D3_OBJECT *obj); // 0x8001AB78

extern struct _D3_OBJECT * D3_SeekDangerousObject(struct _D3_OBJECT *ot, struct _D3_OBJECT *ol, long dtmax, long drmax, long drdanger); // 0x8001ABF0

extern void D3_IsObjectLooker(struct _D3_OBJECT *ot, struct _D3_OBJECT *obj); // 0x8001AD34

extern void D3_IsObjectCloser(struct _D3_OBJECT *ot, struct _D3_OBJECT *obj); // 0x8001AE04

extern void D3_IsFriendCloser(struct _D3_OBJECT *ot, struct _D3_OBJECT *obj); // 0x8001AE84

extern void D3_IsObjectGrenade(struct _D3_OBJECT *ot, struct _D3_OBJECT *obj); // 0x8001AEF0

extern struct _D3_OBJECT * D3_SeekClosestGrenade(struct _D3_OBJECT *ot); // 0x8001AF5C

extern void D3_SeekInList(struct _D3_OBJECT *ot, struct _D3_OBJECT *list, TDRFuncPtr_D3_SeekInList2test test); // 0x8001AF94

extern struct _D3_OBJECT * D3_SeekDistTarget(struct _D3_OBJECT *ot, long dist_maxi, long mask); // 0x8001B00C

extern struct _D3_OBJECT * D3_SeekLookTarget(struct _D3_OBJECT *ot, long dir_max, long dist_max, long mask); // 0x8001B048

extern struct _D3_OBJECT * D3_SeekDistFriend(struct _D3_OBJECT *ot, long dist_maxi); // 0x8001B094

extern void D3_SetDir(struct _D3_OBJECT *o, long x, long y); // 0x8001B0CC

extern long D3_GoToDir(struct _D3_OBJECT *o, long x, long y, long speed); // 0x8001B10C

extern long D3_ObjectInScreen(struct _D3_OBJECT *obj); // 0x8001B1A4

extern void D3_ComputeBBox2D(struct _D3_OBJECT *obj, long *XMin, long *YMin, long *XMax, long *YMax); // 0x8001B58C

extern long D3_ZoneIntersectBBox2D(struct _VISIBILITY *z, long XMin, long YMin, long XMax, long YMax); // 0x8001CE0C

extern long D3_SetShadow(struct _D3_OBJECT *o, struct D3_31fake *p); // 0x8001B7F8

extern void D3_ManageList(struct _D3_OBJECT *obj); // 0x8001B914

extern void * D3_DisplayList(struct _D3_OBJECT *obj, void *Prims, long mini_x, long maxi_x); // 0x8001B9D4

extern void * D3_DisplayTmd(struct _D3_OBJECT *obj, void *Prims, long mini_x, long maxi_x); // 0x8001BC9C

extern void * D3_DisplayShapes(struct _D3_OBJECT *o, void *Prims); // 0x8001C584

extern void D3_IncShpAnim(struct _D3_ANIMSHP *anim); // 0x8001C8BC

extern void * D3_DisplayBox(struct _D3_OBJECT *o, void *Prims); // 0x8001C9FC

extern long D3_SetBonuses(struct _D3_OBJECT *o, long visible, struct _D3_OBJECT *orig); // 0x8001CA04

extern short D3_PlaySoundCamera(struct _D3_OBJECT *o, short snd); // 0x8001CC10

extern short D3_PlaySound(struct _D3_OBJECT *o, short snd); // 0x8001CC60

extern void D3_StopSound(struct _D3_OBJECT *o, short snd_handle); // 0x8001CCE8

extern short D3_UpdateSound(struct _D3_OBJECT *o, short snd, short snd_handle); // 0x8001CD24


typedef void (*TDRFuncPtr_D3_SeekInList2test)();




#endif
