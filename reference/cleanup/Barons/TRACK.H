#ifndef TRACK_H
#define TRACK_H


extern void Track_InitModule(); // 0x800597C8

extern void Track_Init(); // 0x800597D0

extern void Track_Delete(); // 0x80059814

extern void Track_InitFile(); // 0x80059838

extern void Track_SetMode(long m, long t); // 0x800598B4

extern long Track_MoveTo(long speed); // 0x80059910

extern void Track_Task(); // 0x80059960

extern void Track_Wait(); // 0x80059A94

extern void Track_InitMode(); // 0x80059AD8

extern void Track_NormalMode(); // 0x80059B1C

extern void Track_GetNormal(long d, long rotz, struct TRACK_7fake *pos, struct TRACK_7fake *target); // 0x80059C58

extern long Track_TestShoot(struct TRACK_7fake *pos, struct TRACK_7fake *target, struct TRACK_7fake *rot, long *d); // 0x80059F6C

extern void Track_ChooseRotZ(struct TRACK_7fake *pos, struct TRACK_7fake *target, struct TRACK_7fake *rot, long *d); // 0x8005A154

extern long Track_TestPosTarget(struct TRACK_7fake *cam, struct TRACK_7fake *target, long modify); // 0x8005A188

extern void Track_GetPos(struct TRACK_7fake *pos, struct TRACK_7fake *target, struct TRACK_7fake *rot, long dist); // 0x8005A5B8

extern void Track_AdjustMode(); // 0x8005A690

extern void Track_CustomPvlMode(); // 0x8005A75C

extern void Track_CustomPvlModePlayer(struct _CAMERA *c); // 0x8005ABA0

extern void Track_DeathMode(); // 0x8005ACB4

extern void Track_ViewPlayer(); // 0x8005AF74

extern void Track_GolemMode(); // 0x8005B0F0

extern void Track_GolemModeFlee(); // 0x8005B278


#endif
