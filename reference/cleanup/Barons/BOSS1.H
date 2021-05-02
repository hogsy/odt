#ifndef BOSS1_H
#define BOSS1_H


extern void Golem_Hit(); // 0x800ADC1C

extern void Golem_Func_Reflex(); // 0x800ADD2C

extern void Golem_Func_Decisions(); // 0x800AE190

extern void Golem_Task_Action(); // 0x800AE1F0

extern void Golem_Die(); // 0x800AE644

extern void Golem_Shadow(struct _D3_OBJECT *obj, struct BOSS1_31fake *pft4); // 0x800AEABC

extern void Monster_Golem_Rock_Task(); // 0x800AEE50

extern void Monster_Action_GolemDrop(); // 0x800AF0F4

extern void Golem_EffectTask(); // 0x800AF160

extern void Monster_Action_GolemThrow(short AnimNr, short AnimEnd, short mode, struct _D3_OBJECT *target); // 0x800AF4E4

extern void Golem_Bash_Ground(long AnimNr, long mode); // 0x800AF79C

extern long Golem_Start_Sequence(); // 0x800AF948

extern void Golem_Explosion() ; // 0x800AFBAC


#endif
