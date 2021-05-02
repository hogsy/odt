#ifndef BOSS2_H
#define BOSS2_H


extern void Monster_Shot_Position(long x, long y, long z, long shoot); // 0x800ADBE0

extern void Monster_Animate_Child(struct _D3_OBJECT *obj, long childID, long AnimNr); // 0x800ADDEC

extern void Proto_ExplosionScript(struct _D3_OBJECT *o, long loop, long run); // 0x800ADE78

extern void MonstScript_Proto_FuncAttack(); // 0x800AE380

extern void RobotProto_Init(); // 0x800AE4A8

extern void RobotProto_Func_Reflex(); // 0x800AE624

extern void RobotProto_Func_Decisions(); // 0x800AEA1C

extern void RobotProto_Task_Action(); // 0x800AEA78

extern void Proto_Scripting(); // 0x800AF040

extern void _boss7_bss_objend() ; // 0x800AF204

extern void Bosses_Explosion() ; // 0x800AF3B8


#endif
