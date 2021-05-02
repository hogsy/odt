#ifndef LIGHT_H
#define LIGHT_H


extern void Light_Blink(); // 0x8001CE54

extern void Light_IntplBlink(struct _ANIM_BLINK *ab, short coef); // 0x8001D360

extern void Light_InitFile(); // 0x8001D524

extern void Light_DeleteFile(); // 0x8001D5B4

extern void Light_Constructor(struct _LIGHT *l); // 0x8001D618

extern void Light_Add(struct _LIGHT *l); // 0x8001D6CC

extern void Light_Delete(struct _LIGHT *l); // 0x8001D6D4

extern void Light_SetIdentity(); // 0x8001D6DC

extern void Light_SetMatrix(struct _D3_OBJECT *o); // 0x8001D760

extern void Light_SetLocalMatrix(struct _D3_OBJECT *o); // 0x8001DB9C

extern void Light_RotMatrix(struct _D3_OBJECT *o, struct LIGHT_5fake *m); // 0x8001DD40

extern short Light_GetNearIndices(short x0, short y0, short z0); // 0x8001DE08

extern void Light_GetNearLights(short t, struct _LIGHT **l); // 0x8001E104

extern long Light_IsVisible(struct _LIGHT *l, struct LIGHT_7fake *pos); // 0x8001E184

extern void Light_AmbianceAdd(struct _LIGHT *l); // 0x8001E1F4

extern void Light_AddEffect(struct _LIGHT *l, short effect); // 0x8001E264

extern void Light_FlareTask(); // 0x8001E2B8

extern void Light_DisplayFlare(); // 0x8001E2F4

extern void Light_DisplayRemanence(struct LIGHT_31fake *prim, short x, short y); // 0x8001E778


#endif
