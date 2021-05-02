#ifndef BOSS6_H
#define BOSS6_H


extern void Nessy_Func_Reflex(); // 0x800ADC5C

extern long Nessy_GetSortedZones(struct _MONSTER *monst, short *one); // 0x800ADEC8

extern void Nessy_Task_Action(); // 0x800ADFCC

extern void Dragon_GetHeadPosition(struct _MONSTER *monst, struct M_OBJECT *mo, struct BOSS6_7fake *pos, long anim); // 0x800AEAB0

extern void Dragon_PlaySound(struct _D3_OBJECT *o, long sound); // 0x800AEC88

extern void Dragon_Func_Reflex(); // 0x800AECC0

extern void Dragon_Func_Decisions(); // 0x800AF0C8

extern void Dragon_Sound(struct _D3_OBJECT *o, struct M_OBJECT *mo); // 0x800AF0D0

extern void Dragon_Task_Action(); // 0x800AF164

extern void _boss2_sbss_obj() ; // 0x800AF40C

extern void _boss7_ctors_obj() ; // 0x800AF208

extern void Nessy_Scripting(long dist); // 0x800AFBE0

extern void _boss1_ctors_obj() ; // 0x800AFC04

extern void Dragon_Scripting(long dist); // 0x800AFD20

extern void GolemBeingHit() ; // 0x800AFC00

extern void _boss6_sbss_obj() ; // 0x800AFE3C


#endif
