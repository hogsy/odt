#ifndef MANIM_H
#define MANIM_H


extern void Manim_Init(); // 0x800223B0

extern void Manim_GetLinkPos(struct M_OBJECT *Obj, struct MANIM_100fake *Ani, long Anim, struct MANIM_7fake *Out); // 0x800223B8

extern void Manim_GetLinkPosDelta(struct M_OBJECT *Obj, struct MANIM_100fake *Ani, long Anim, struct MANIM_7fake *Out); // 0x80022434

extern void Manim_SetEffect(struct M_OBJECT *mo, TDRFuncPtr_Manim_SetEffect1f f); // 0x8002257C

extern void Manim_SetAnim(struct M_OBJECT *obj, long Anim); // 0x80022598

extern void Manim_ForceAnim(struct M_OBJECT *obj, long Anim); // 0x800225EC

extern void Manim_WaitAnim(struct M_OBJECT *obj); // 0x80022634

extern long Manim_WaitEvent(struct M_OBJECT *obj, long Events); // 0x80022674

extern long Manim_GetEventTime(struct M_OBJECT *obj, long Event); // 0x800226DC

extern long Manim_GetEventTX(struct MANIM_100fake *Ani, long Anim, long Event); // 0x800227C4

extern long Manim_GetEventTZ(struct MANIM_100fake *Ani, long Anim, long Event); // 0x80022898

extern long Manim_GetSpdX(struct M_OBJECT *mo); // 0x80022958

extern long Manim_GetSpdY(struct M_OBJECT *mo); // 0x80022AA4

extern long Manim_GetSpdZ(struct M_OBJECT *mo); // 0x80022BF0

extern void Manim_GoToFrame(struct M_OBJECT *obj, long fa); // 0x80022D44

extern void Manim_PlayAnim(struct M_OBJECT *obj); // 0x80022E28

extern void Manim_Move(struct M_OBJECT *mo, long tx, long ty, long tz, long scale); // 0x80023334

extern void * Manim_DisplayActor(struct M_OBJECT *obj, void *Prims, long mini_x, long maxi_x); // 0x800234C8

extern void * Manim_DisplayMotion(struct M_OBJECT *obj, void *Prims, long z, long zs); // 0x800239B4

extern void * Manim_DisplayShapes(struct _D3_OBJECT *o, void *Prims); // 0x80023DB0

extern void Manim_EnvRotTransPers(struct M_OBJECT *Mobject); // 0x800240A0

extern void Manim_ModifyAngle(unsigned short Flag, struct MANIM_7fake *Angle); // 0x80024128

extern void Manim_TrajRotTransPers(struct M_OBJECT *Mobject, short NumObj); // 0x80024298

extern void Manim_TrajProjection(struct MANIM_93fake *TmdObj, struct MANIM_99fake *AnItem, struct MANIM_5fake *Father, short index); // 0x8002444C

extern void Manim_EventGetPos(struct M_OBJECT *mo, struct MANIM_7fake *pos); // 0x800245EC


typedef void (**TDRFuncPtr_Manim_SetEffect1f)();




#endif
