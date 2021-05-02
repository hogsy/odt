#ifndef JOYSTICK_H
#define JOYSTICK_H


extern void Joy_Init(); // 0x8009CEA4

extern long Joy_IsConnected(long i); // 0x8009CF0C

extern long Joy_IsMultiTap(long side); // 0x8009CF30

extern void Joy_RefreshPhysLog(); // 0x8009CF5C

extern void Joy_ReadTap(struct JOYSTICK_105fake *data, long j); // 0x8009CFC4

extern void Joy_ReadMultiTap(struct JOYSTICK_106fake *data, long j); // 0x8009D274

extern long Joy_ReadLog(long j); // 0x8009D2FC

extern long Joy_ReadTrig(long j); // 0x8009D328

extern long Joy_ReadX(long j); // 0x8009D354

extern long Joy_ReadY(long j); // 0x8009D380

extern long Joy_ReadLogAll(); // 0x8009D3AC

extern long Joy_ReadTrigAll(); // 0x8009D3C0

extern void Joy_Driver(); // 0x8009D3D4


#endif
