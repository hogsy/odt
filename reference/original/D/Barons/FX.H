#ifndef FX_H
#define FX_H


extern short Fx_Play_Sample(short Fx, struct FX_7fake *pos, struct FX_7fake *orig, long VolumeMode); // 0x800650FC

extern short Fx_Play(short Fx, struct FX_7fake *pos); // 0x80065154

extern short Fx_PlayLoud(short Fx, struct FX_7fake *pos); // 0x80065188

extern short Fx_PlaySoft(short Fx, struct FX_7fake *pos); // 0x800651BC

extern short Fx_Play_Camera(short Fx, struct FX_7fake *pos); // 0x800651F0

extern short Fx_PlayInPause(short Fx, struct FX_7fake *pos); // 0x80065224

extern long Fx_GetVolume(struct _VoiceSetting *Set, struct FX_7fake *pos, struct FX_7fake *orig, long VolumeMode); // 0x80065284

extern void Fx_SetVolume_Sample(short wPlayID, struct FX_7fake *pos, struct FX_7fake *orig); // 0x8006534C

extern void Fx_SetVolume(short Fx, struct FX_7fake *pos); // 0x80065394

extern void Fx_SetVolume_Camera(short Fx, struct FX_7fake *pos); // 0x800653C0


#endif
