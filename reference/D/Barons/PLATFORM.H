#ifndef PLATFORM_H
#define PLATFORM_H


extern void Plat_Init(); // 0x8002D3EC

extern void Plat_InitFile(); // 0x8002D3F4

extern void Plat_Constructor(struct _PLATFORM *p); // 0x8002D4B0

extern void Plat_SetRoll(struct _PLATFORM *p); // 0x8002D62C

extern struct _PLATFORM * Plat_GetPlat(struct PLATFORM_7fake *pos); // 0x8002D6FC

extern long Plat_IsDisplayed(struct _PLATFORM *p, long *visibility); // 0x8002D858

extern void Plat_SetDisplayed(struct _PLATFORM *p, long *visibility); // 0x8002D8D8

extern void Plat_ClearZones(); // 0x8002D96C

extern void * Plat_DisplayZones(void *prims); // 0x8002DA5C

extern void Plat_ScanZone(struct _VISIBILITY *cur, struct _VISPORTAL *port, long min_x, long max_x); // 0x8002DE4C

extern void Plat_ZIntersect(struct PLATFORM_6fake *V1, struct PLATFORM_6fake *V2, long *min_x, long *max_x); // 0x8002DF64

extern void Plat_ZClipPortal(struct PLATFORM_7fake *Box, long *min_x, long *max_x); // 0x8002E0EC

extern void Plat_ComputePortal(struct _VISIBILITY *cur, struct _VISIBILITY *v, struct _VISPORTAL *port); // 0x8002E254

extern long Plat_IsVisible(struct _VISIBILITY *cur, struct _VISIBILITY *v, struct _VISPORTAL *port, long *mini_x, long *maxi_x); // 0x8002EA3C

extern void * Plat_DisplayPlatform(struct _PLATFORM *p, void *prims, long mini_x, long maxi_x); // 0x8002EB80

extern void * Plat_Display(void *Prims); // 0x8002F028

extern void Plat_MarkSurface(struct _PLATFORM *p); // 0x8002F178

extern short Plat_ChangeLevel(struct _PLATFORM *p, short d); // 0x8002F1D4

extern void Water_CTask(); // 0x8002F2A8

extern void Lava_CTask(); // 0x8002F668

extern void Roll_CTask(); // 0x8002FA88


#endif
