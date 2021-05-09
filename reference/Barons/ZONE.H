#ifndef ZONE_H
#define ZONE_H


extern void Zone_InitFile(); // 0x80030308

extern void Zone_Constructor(struct _ZONE *z); // 0x800303A4

extern short Zone_IsPosInZone(struct _ZONE *z, struct ZONE_7fake *pos); // 0x8003040C

extern void Zone_DeleteObject(struct _D3_OBJECT *obj); // 0x800304A4

extern struct _ZONE * Zone_GetZone(struct ZONE_7fake *pos); // 0x80030614

extern void Zone_TestObject(struct _D3_OBJECT *obj); // 0x800306A4

extern struct _ZONE * Zone_GetEntry(long id); // 0x80030988

extern struct _ZONE * Zone_GetObjectExit(struct _D3_OBJECT *o); // 0x800309EC

extern struct _ZONE * Zone_GetObjectNext(struct _D3_OBJECT *o); // 0x80030A40

extern struct _ZONE * Zone_GetObjectZone(struct _D3_OBJECT *o); // 0x80030ADC

extern long Zone_IsZoneAttached(struct _D3_OBJECT *obj); // 0x80030B00

extern struct _ZONE * Zone_GetLinkedZone(struct _D3_OBJECT *obj, char type); // 0x80030B54

extern void Zone_TextDisplay(struct _ZONE *z); // 0x80030BF4

extern void Zone_TxtDispTask(); // 0x80030CD4

extern void Zone_TxtDispDestructor(struct TASK *t); // 0x80030EC0

extern short Zone_GetEnemyZone(short x, short y, short z, unsigned long low, unsigned long high); // 0x80030ECC

extern short Zone_GetEnemyZonePath(short xs, short ys, short zs, short xd, int yd, int zd, unsigned long low, unsigned long high, short *res); // 0x80030FE0


#endif
