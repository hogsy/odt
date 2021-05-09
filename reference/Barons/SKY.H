#ifndef SKY_H
#define SKY_H


extern void Sky_InitFile(); // 0x800680B8

extern void Sky_DeleteFile(); // 0x80068108

extern void Sky_Task(); // 0x80068130

extern void Sky_Destructor(struct TASK *handle); // 0x800683B0

extern short Sky_TestPresence(); // 0x8006844C

extern struct _ZONE * Sky_TestZones(); // 0x80068494


#endif
