#ifndef WEATHER_H
#define WEATHER_H


extern void Weather_Add(struct _LIGHT *l); // 0x800653EC

extern struct TASK * Weather_AddRain(struct WEATHER_7fake *pos, long duration, long fall_off, struct WEATHER_8fake *col, long density); // 0x800654C0

extern void Weather_Init(struct _WEATHER *wea, short type, short mode); // 0x80065584

extern void Weather_Task(); // 0x80065900

extern void Weather_InitPos(struct _WEATHER *wea, struct WEATHER_7fake *p); // 0x80065950

extern void Weather_MoveRain(); // 0x80065A58

extern void Weather_MoveFire(); // 0x80065C94

extern void Weather_MoveImpact(); // 0x80065F58

extern void Weather_DisplayLines(); // 0x8006606C

extern void Weather_InitLines(struct _WEATHER *wea, short trans); // 0x80066338

extern void Impact_Add(struct WEATHER_7fake *pos, struct WEATHER_8fake *col, struct WEATHER_7fake *speed, short nb_part, int life, int trans, int grav); // 0x80066464

extern short Impact_Clipped(struct WEATHER_7fake *pos); // 0x80066690

extern void Impact_DisplayShapeList(short num_shape); // 0x8006674C

extern void Impact_DisplayShape(); // 0x80066818

extern void Impact_Rain(struct WEATHER_7fake *pos, struct WEATHER_8fake *col, short nb_part); // 0x800668E0

extern void Impact_D3Blood(struct WEATHER_7fake *pos, struct _D3_OBJECT *o, short nb_part); // 0x80066948

extern void Impact_Sprites(struct WEATHER_7fake *pos, long nb_part, long sprite, long size); // 0x80066A00

extern void Impact_Blood(struct WEATHER_7fake *pos, long nb_part); // 0x80066AAC

extern void Impact_GreenBlood(struct WEATHER_7fake *pos, long nb_part); // 0x80066AD0

extern void Impact_Petrole(struct WEATHER_7fake *pos, long nb_part); // 0x80066AF4

extern void Impact_Sparks(struct WEATHER_7fake *pos, short nb_part); // 0x80066B20

extern void Impact_Circle(struct WEATHER_7fake *pos, short nb); // 0x80066BA4

extern void Impact_CircleTask(); // 0x80066C44

extern short Impact_InitCircles(); // 0x80066CE0

extern void Impact_DisplayCircles(); // 0x80066D9C

extern void Impact_Acid(struct WEATHER_7fake *pos); // 0x80066FDC

extern void Impact_AcidTask(); // 0x80067044

extern short Impact_InitAcid(); // 0x800670CC

extern void Impact_Bubble(struct WEATHER_7fake *pos, short nshp, short life, short height); // 0x80067160

extern void Impact_BubbleTask(); // 0x8006720C

extern short Impact_InitBubble(); // 0x80067344

extern void Impact_Smoke(struct WEATHER_7fake *pos, short mode); // 0x800674D4

extern void Impact_SmokeTask(); // 0x8006754C

extern short Impact_InitSmoke(); // 0x8006766C

extern void Impact_Heat(struct WEATHER_7fake *pos); // 0x800676F0

extern void Impact_HeatTask(); // 0x80067758

extern void Impact_InitHeat(); // 0x80067824

extern void Impact_Stone(struct WEATHER_7fake *pos, short nb_part); // 0x80067864


#endif
