#ifndef BOXES_H
#define BOXES_H


extern void Boxes_ClearColl(); // 0x8001EA50

extern void Boxes_AddColl(struct _D3_OBJECT *oc, long plane, long minmax, long min, long max); // 0x8001EA84

extern void Boxes_DelColl(long i); // 0x8001ECFC

extern long Boxes_TestResetedObject(struct _D3_OBJECT *ot); // 0x8001EDA4

extern long Boxes_TestObject(struct _D3_OBJECT *ot); // 0x8001EE2C

extern long Boxes_TestGround(struct _D3_OBJECT *ot); // 0x8001F070

extern void Boxes_TestDistance(struct _D3_OBJECT *ot, long dist); // 0x8001F128

extern long Boxes_TestPoint(struct _D3_OBJECT *ot); // 0x8001F228

extern long Boxes_TestTransparent(struct _D3_OBJECT *ot); // 0x8001F408

extern long Boxes_TestPlatforms(struct _D3_OBJECT *ot, TDRFuncPtr_Boxes_TestPlatforms1function function); // 0x8001F484

extern long Boxes_TestPlatform(struct _PLATFORM *p, struct _D3_OBJECT *ot, TDRFuncPtr_Boxes_TestPlatform2function function); // 0x8001F6F8

extern long Boxes_TestList(struct _D3_OBJECT *ot, struct _D3_OBJECT **list, TDRFuncPtr_Boxes_TestList2function function); // 0x8001F7C0

extern long Boxes_IsObjectInObject(struct _D3_OBJECT *ot, struct _D3_OBJECT *obj); // 0x8001F854

extern long Boxes_IsObjectInDistance(struct _D3_OBJECT *ot, struct _D3_OBJECT *obj); // 0x8001F9E0

extern long Boxes_IsPointEnterInObject(struct _D3_OBJECT *ot, struct _D3_OBJECT *obj); // 0x8001FA64

extern long Boxes_IsObjectBaseEnterInObject(struct _D3_OBJECT *ot, struct _D3_OBJECT *obj); // 0x80020068

extern long Boxes_IsObjectEnterInObject(struct _D3_OBJECT *ot, struct _D3_OBJECT *obj); // 0x8002022C

extern long Boxes_AcceptObjectFound(struct _D3_OBJECT *ot, struct _D3_OBJECT *obj, long bits); // 0x800207B4

extern long Boxes_ObjectFound(struct _D3_OBJECT *ot, struct _D3_OBJECT *obj, long bits); // 0x8002086C

extern void Boxes_ResultColls(struct _D3_OBJECT *ot); // 0x80020B14

extern void Boxes_ResetPos(struct _D3_OBJECT *ot); // 0x80020C88

extern void Boxes_BounceObject(struct BOXES_7fake *spd); // 0x80020EC4

extern void Boxes_BounceObject12(struct BOXES_6fake *spd); // 0x8002105C

extern void Boxes_ResetList(struct _D3_OBJECT *ot, struct BOXES_7fake *new_p, struct BOXES_7fake *last_p); // 0x800211F4

extern long Boxes_GetHeightPlatform(struct _D3_OBJECT *ot, struct BOXES_7fake *st); // 0x800212B4

extern long Boxes_GetHeight(struct _D3_OBJECT *ot, struct BOXES_7fake *st, short range); // 0x80021314

extern long Boxes_GetHeightUnder(struct _D3_OBJECT *ot, struct BOXES_7fake *st); // 0x80021408

extern long Boxes_IsPosInList(struct _D3_OBJECT *ot, struct BOXES_7fake *st, long maxz, struct _D3_OBJECT *list, long hmax); // 0x80021508

extern long Boxes_IsPosInObject(struct BOXES_7fake *in, struct BOXES_7fake *out, struct _D3_OBJECT *ot, long hmax); // 0x80021620

extern void Boxes_RotPos(struct _D3_OBJECT *obj, struct BOXES_7fake *po, struct BOXES_7fake *in, struct BOXES_7fake *out); // 0x80021738

extern void Boxes_InvRotPos(struct _D3_OBJECT *obj, struct BOXES_7fake *po, struct BOXES_7fake *in, struct BOXES_7fake *out); // 0x80021894

extern long Boxes_GetRealZ(struct _D3_OBJECT *o, long x, long y); // 0x800219EC

extern long Boxes_GetExtendedMaxZ(struct _D3_OBJECT *ot); // 0x80021B24

extern void Boxes_GetExtendedDxDy(struct _D3_OBJECT *ot, long *dx, long *dy); // 0x80021B54

extern void Boxes_TestFloatingGround(struct _D3_OBJECT *ot); // 0x80021C68

extern short Boxes_GetBit(struct _D3_OBJECT *ot, struct _D3_OBJECT *obj); // 0x80021CA4

extern void Boxes_GetMinMax(struct _D3_OBJECT *ot, short bit, struct BOXES_7fake *min, struct BOXES_7fake *max); // 0x80021E48

extern short Boxes_GetDepth(struct _D3_OBJECT *ot, short bit); // 0x80022128

extern short Boxes_GetLength(struct _D3_OBJECT *ot, short bit); // 0x800221E8

extern void Boxes_GetCenter(struct _D3_OBJECT *ot, struct BOXES_7fake *c); // 0x80022270


typedef long (*TDRFuncPtr_Boxes_TestList2function)();

typedef long (*TDRFuncPtr_Boxes_TestPlatform2function)();

typedef long (*TDRFuncPtr_Boxes_TestPlatforms1function)();




#endif
