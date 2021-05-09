#ifndef VIS_H
#define VIS_H


extern void Vis_Init(); // 0x800314EC

extern void Vis_InitFile(); // 0x800314F4

extern long Vis_TestObjects(struct _D3_OBJECT *ot, struct _D3_OBJECT *obj); // 0x80031648

extern struct _VISIBILITY * Vis_GetVisPos(struct VIS_7fake *pos); // 0x800316D0


#endif
