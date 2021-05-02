#ifndef ENEMY_H
#define ENEMY_H


extern void Decisions(); // 0x80071600

extern void Monster_Type1_Task(); // 0x8007165C

extern void EB_Bat_MainTask(); // 0x80071AE4

extern void EB_Soldats_MainTask(); // 0x80071FE8

extern void Pirhana_Task_Next(); // 0x8007299C

extern void Pirhana_Wait(struct _D3_OBJECT *o, long time, long x, long y); // 0x80072A18

extern void Pirhana_Func_Reflex(); // 0x80072B60

extern void Pirhana_Func_Decide(); // 0x80072D84

extern void Pirhana_Task_Action(); // 0x80072E0C

extern void Pirhana_Impact(struct _D3_OBJECT *o, long extra); // 0x800731A4

extern void Pirhana_Task(struct ENEMY_31fake *pft4); // 0x80073284

extern void Bat_Small_Func_Reflex(); // 0x800736F8

extern void Bat_Small_Func_Decisions(); // 0x80073788

extern void Bat_Small_Task_Action(); // 0x80073818

extern void Soldier_Gunner_Func_Reflex(); // 0x80073D5C

extern void Soldier_Gunner_Task_Action(); // 0x80073E8C

extern void Soldier_Grenade_Func_Reflex(); // 0x80074478

extern void Soldier_Grenade_Task_Action(); // 0x800745E8

extern void Soldier_Gremit_Task_Action(); // 0x800749A8

extern void Soudeur_RIP(struct M_OBJECT *mo, struct _D3_OBJECT *o); // 0x80074DE4

extern void Soldier_Soudeur_Init(); // 0x80074F64

extern void Soldier_Soudeur_Func_Reflex(); // 0x80075010

extern void Soldier_Soudeur_Task_Action(); // 0x80075284

extern void Soldier_RobNail_Init(); // 0x80075670

extern void Soldier_RobNail_Func_Reflex(); // 0x80075724

extern void Soldier_RobNail_Func_Decisions(); // 0x80075BE4

extern void Soldier_RobNail_Task_Action(); // 0x80075C70

extern void Raptor_Small_Func_Reflex(); // 0x80075F3C

extern void Raptor_Small_Task_Action(); // 0x80075FA0

extern void Funkie_Func_Reflex(); // 0x80076474

extern void Funkie_Task_Action(); // 0x800764C0

extern void Spectre_Func_Reflex(); // 0x80076778

extern void Zombie_Func_Reflex(); // 0x80076884

extern void Zombie_Task_Action(); // 0x800768B8

extern void Maton_Func_Reflex(); // 0x80077260

extern void Maton_Task_Action(); // 0x80077590

extern void Hpl_Func_Reflex(); // 0x80077B30

extern void Hpl_Task_Action(); // 0x80077C7C

extern void Gua_Func_Reflex(); // 0x800780A4

extern void Big_Func_Reflex(); // 0x800781A8

extern void Big_Task_Action(); // 0x800781DC

extern void Pri_Get_CustomZones(struct _MONSTER *monst, short *ret); // 0x800784E4

extern void Pri_Func_Reflex(); // 0x800785AC

extern void Stop_Yelling(struct _D3_OBJECT *o, long stop); // 0x800786B8

extern void Pri_Task_Action(); // 0x80078718

extern void PrisBoss_Scripting(); // 0x80079030

extern void Bos_SetInFront(struct _D3_OBJECT *o, struct ENEMY_7fake *pos, long rot); // 0x80079F6C

extern void Bos_Func_Reflex(); // 0x8007A044

extern void Bos_Func_Decisions(); // 0x8007A53C

extern void Bos_Task_Action(); // 0x8007A628

extern void Haq_Func_Reflex(); // 0x8007ABCC

extern void Haq_Task_Action(); // 0x8007AD54

extern void Rat_Func_Reflex(); // 0x8007B1EC

extern void Rat_Task_Action(); // 0x8007B324

extern void Spider_Func_Reflex(); // 0x8007B5F4

extern void Spider_Task_Action(); // 0x8007B798

extern void Com_Func_Reflex(); // 0x8007BA7C

extern void Com_Task_Action(); // 0x8007BAC0

extern void Skeleton_Func_Reflex(); // 0x8007BD78

extern void Skeleton_Task_Action(); // 0x8007BE0C

extern void Sorcier_Func_Reflex(); // 0x8007C2C8

extern void Sorcier_Task_Action(); // 0x8007C454

extern void Rod_Func_Reflex(); // 0x8007C860

extern void Rod_Func_Decisions(); // 0x8007C970

extern void Rod_Task_Action(); // 0x8007C9D0


#endif
