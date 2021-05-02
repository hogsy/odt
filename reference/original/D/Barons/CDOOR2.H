#ifndef CDOOR2_H
#define CDOOR2_H


extern void Door_MIMe(struct _D3_OBJECT *D3Obj, long testkey); // 0x80056460

extern long Door_MIMe_Move(struct _D3_OBJECT *D3Obj, long speed); // 0x80056640

extern void Door_End_MIMe(struct _D3_OBJECT *D3Obj, long mode); // 0x800567BC

extern void Traps_EngrenageRemove(struct _D3_OBJECT *D3Obj); // 0x800567E8

extern void Traps_EngrenageAdd(struct _D3_OBJECT *D3Obj); // 0x80056CF8

extern void Traps_Pipette(struct _D3_OBJECT *D3Obj); // 0x80056EF8

extern long Pipette_FindMovingVertices(struct _D3_OBJECT *o); // 0x800570F0

extern void Pipette_SetWater(struct _D3_OBJECT *o, long LevelZ, long nMoving); // 0x80057154

extern void Pipette_ChangeWater(struct _D3_OBJECT *o, long diffZ, long nMoving); // 0x80057198

extern long Pipette_GetNbLevels(struct _D3_OBJECT *o); // 0x800571E8

extern void Traps_LameCirc(struct _D3_OBJECT *D3Obj); // 0x80057250

extern void Traps_VoletEau(struct _D3_OBJECT *D3Obj); // 0x80057524

extern struct _D3_OBJECT * Volets_Init(struct _D3_OBJECT *D3Obj); // 0x80057714

extern void Volets_Impacts(struct _D3_OBJECT *o, long NbImpacts); // 0x800578D4

extern void Volets_CheckRot(struct _D3_OBJECT *o, long *FlagRot); // 0x80057990

extern void Volets_CheckPos(struct _D3_OBJECT *o, long *FlagPos); // 0x80057A80

extern long Volets_GetNbFalls(long FlagRot, long FlagPos); // 0x80057B50

extern void Volets_SetVisibleFalls(struct _D3_OBJECT *o, long NbFalls); // 0x80057C40

extern void Volets_RotateTask(); // 0x80057CAC

extern void Volets_SetStream(struct _D3_OBJECT *o, struct TASK *handle, long NbFalls); // 0x80057DB8

extern void CB_ColumnDragon(struct _D3_OBJECT *o); // 0x80057F14

extern void CB_ColumnSetHighBoxZ(struct _D3_OBJECT *o, long height, long num_child); // 0x80058040

extern void CB_ColumnFall(); // 0x800580B8

extern void CB_PieceOWheel(struct _D3_OBJECT *o); // 0x800583D4

extern void CB_Piece2Water(struct _D3_OBJECT *o, struct CDOOR2_7fake *dest); // 0x8005875C

extern long CB_FloatPiece(struct _D3_OBJECT *o, long *angX, long sensX); // 0x800588A0

extern void CB_Lucioles(struct _D3_OBJECT *o); // 0x80058938

extern void CB_LuciolesGoToPos(struct _D3_OBJECT *o, struct CDOOR2_7fake *pos, short speed); // 0x80058BE0

extern void CB_LuciolesDisplay(); // 0x80058D0C

extern void CB_LucioleInitPos(struct CDOOR2_7fake *sv); // 0x80058E70

extern void CB_LucioleInitCol(struct CDOOR2_8fake *tab_col, struct CDOOR2_8fake *col); // 0x80058E80

extern void CB_LucioleInitSpeed(struct CDOOR2_7fake *tab_spd); // 0x80058EB0

extern void CB_LucioleInvertSpeed(struct CDOOR2_7fake *spd); // 0x80058FD8

extern void CB_LuciolesMove(struct _D3_OBJECT *o, struct CDOOR2_7fake *tab_pos, struct CDOOR2_7fake *tab_spd, long invert); // 0x80059054

extern void CB_DalleWeight(struct _D3_OBJECT *o); // 0x80059170

extern long CB_ReceptTestSum(struct _D3_OBJECT *o, long nbobj, long sum); // 0x80059388

extern void CB_WeightDisableSmoke(struct _D3_OBJECT *o); // 0x800593D8

extern void CB_WeightSetPos(struct _D3_OBJECT *o, long nbobj, long *tab); // 0x8005941C

extern void CB_WrongWeight(struct _D3_OBJECT *o, long nbobj, long *tab); // 0x80059500

extern void CB_RightWeight(struct _D3_OBJECT *o, long nbobj, long *tab); // 0x80059660


#endif
