#ifndef P_ACTH_H
#define P_ACTH_H


extern void Pafh_TestHold(struct _PLAYER *pl); // 0x8003955C

extern void Pafh_TestHoldDown(struct _PLAYER *pl, struct _D3_OBJECT **hog, short *hsg, long arriere); // 0x80039858

extern long Pafh_GetPosRot(struct _PLAYER *pl, struct _D3_OBJECT *oh, long bit, struct P_ACTH_7fake *pos, long offset, long adjust); // 0x80039B80

extern long Pafh_Shot(struct _D3_OBJECT *oh, long bit, long swing); // 0x80039E48

extern long Pafh_GoUp(long anm, struct _D3_OBJECT *oh, long bit); // 0x80039F48

extern long Pafh_GoDown(struct _D3_OBJECT *oh, long bit, long arriere); // 0x8003A020

extern void Pafh_Swing(struct _D3_OBJECT *oh, long bit); // 0x8003A2D4

extern long Pafh_ChangeSide(struct _D3_OBJECT *ot, long bit); // 0x8003A508

extern void Pafh_Move(struct _D3_OBJECT **oh, long *bit, long swing); // 0x8003A694

extern void Pacth_Hold(); // 0x8003A9C8

extern void Pacth_Grabbed(); // 0x8003AD9C

extern void Pacth_Dropped(); // 0x8003AFCC

extern void Pacth_Climb(); // 0x8003AFFC


#endif
