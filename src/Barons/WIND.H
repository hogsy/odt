#ifndef WIND_H
#define WIND_H


extern void Wind_InitFile(); // 0x80067924

extern void Wind_DeleteFile(); // 0x80067950

extern void Wind_GeneralTask(); // 0x80067978

extern struct _WIND * Wind_Add(short vx, short vy, short vz); // 0x80067BE4

extern void Wind_ChangeDir(struct _WIND *w, short nb_Frames, short vx, short vy, int vz); // 0x80067C38

extern void Wind_Task(); // 0x80067CE0

extern struct _WIND * Wind_AddInList(struct _WIND **list); // 0x80067EB4

extern struct _WIND * Wind_DeleteList(struct _WIND **list); // 0x80067F18

extern void Wind_GetValue(struct WIND_7fake *pos, struct WIND_7fake *sum); // 0x80067F5C

extern long Wind_TestPos(struct _WIND *w, struct WIND_7fake *p); // 0x80068020


#endif
