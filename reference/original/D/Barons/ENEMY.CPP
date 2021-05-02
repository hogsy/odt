#include "THISDUST.H"
#include "ENEMY.H"


// decompiled code
// original method signature: 
// void /*$ra*/ Decisions()
 // line 132, offset 0x80071600
	/* begin block 1 */
		// Start line: 133
		// Start offset: 0x80071600
		// Variables:
	// 		struct _MONSTER *monst; // $s0
	/* end block 1 */
	// End offset: 0x8007164C
	// End Line: 141

	/* begin block 2 */
		// Start line: 264
	/* end block 2 */
	// End Line: 265

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Decisions(void)

{
  _MONSTER *monst;
  
  monst = (_MONSTER *)TaskCurrent->local;
  if (LONG_ARRAY_800b2e2c[0] != -1) {
    Monster_StopAllActions(monst);
    Monster_AddAction(monst,0,5,0,0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Monster_Type1_Task()
 // line 144, offset 0x8007165c
	/* begin block 1 */
		// Start line: 145
		// Start offset: 0x8007165C
		// Variables:
	// 		struct ENEMY_31fake pft4[2]; // stack offset -96
	// 		struct _D3_OBJECT *D3Obj; // $s0
	// 		struct _MONSTER *Monster; // $s1
	// 		short comp; // $s2
	/* end block 1 */
	// End offset: 0x80071ACC
	// End Line: 256

	/* begin block 2 */
		// Start line: 293
	/* end block 2 */
	// End Line: 294

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Monster_Type1_Task(void)

{
  short sVar1;
  int iVar2;
  _MONSTER *Monster;
  code *pcVar3;
  short sVar4;
  ulong Mask;
  _D3_OBJECT *D3Obj;
  uint uVar5;
  
  D3Obj = (_D3_OBJECT *)TaskCurrent->local;
  uVar5 = (uint)(ushort)D3Obj[1].pos.vy & 0xf;
  if ((Pvl_BossState & 1U) != 0) {
    if (Pvl_LevelNumber == 2) {
      sVar4 = D3Obj->hit_points;
      sVar1 = sVar4 / 5 + ((sVar4 >> 0x10) >> 0xf);
LAB_80071780:
      D3Obj->hit_points = sVar4 - (sVar1 - (sVar4 >> 0xf));
    }
    else {
      if (Pvl_LevelNumber < 3) {
        if (Pvl_LevelNumber == 1) {
          iVar2 = (int)D3Obj->hit_points;
          if (iVar2 < 0) {
            iVar2 = iVar2 + 3;
          }
          D3Obj->hit_points = D3Obj->hit_points - (short)(iVar2 >> 2);
        }
      }
      else {
        if (Pvl_LevelNumber == 3) {
          D3Obj->hit_points = D3Obj->hit_points - (short)(((int)D3Obj->hit_points * 0xf) / 100);
        }
        else {
          if (Pvl_LevelNumber == 5) {
            sVar4 = D3Obj->hit_points;
            sVar1 = sVar4 / 0x14 + ((sVar4 >> 0x10) >> 0xf);
            goto LAB_80071780;
          }
        }
      }
    }
  }
  if ((Pvl_BossState & 2U) != 0) {
    D3Obj->exp = '\0';
  }
  Pvl_BossState = Pvl_BossState | 1;
  if (1 < uVar5 - 5) {
    Monster_CreateShadow(D3Obj,0xa0);
  }
  Monster = Monster_Main_Init((_D3_OBJECT *)0x0);
  Monster->flags = Monster->flags | 4;
  *(undefined *)((int)&D3Obj[1].pos.vx + 1) = 0xf2;
  *(undefined2 *)((int)&D3Obj->b_hurt + 2) = 0;
  Scts_Interruptors = Scts_Interruptors & 0x7fffffff;
  switch(uVar5) {
  case 0:
    D3_SetBox(D3Obj,-0x32,-0x32,0x14,0x32,0x32,(int)*(short *)&D3Obj[1].prec);
    Mask = 0x7cff5fff;
    D3Obj[1].pos.vy = D3Obj[1].pos.vy | 0x1230;
    Monster->task_action = Golem_Task_Action;
    Monster->func_decide = Golem_Func_Decisions;
    Monster->func_reflex = Golem_Func_Reflex;
    Monster->func_init = (_func_34 *)0x0;
    break;
  case 1:
    Mask = 0xfcff7fff;
    Monster->task_action = RobotProto_Task_Action;
    Monster->func_decide = RobotProto_Func_Decisions;
    Monster->func_reflex = RobotProto_Func_Reflex;
    Monster->func_init = RobotProto_Init;
    break;
  case 2:
    Mask = 0xfcffffff;
    Monster->task_action = Harb_Task_Action;
    Monster->func_decide = Harb_Func_Decisions;
    Monster->func_reflex = Golem_Hit;
    Monster->func_init = (_func_34 *)0x0;
    Scts_Interruptors = Scts_Interruptors & 0xfffffbff;
    Monster->guninfo1 = (D3Obj->pos).vz;
    break;
  case 3:
    D3_SetBox(D3Obj,(int)(D3Obj->b_box).vx,(int)D3Obj->comp_opt3,0,(int)*(short *)&D3Obj->b_step,
              (int)(D3Obj->b_box).vy,(int)*(short *)&D3Obj[1].prec);
    D3_SetCollBits(D3Obj,(long)&DAT_00002008);
    Mask = 0x9cffffff;
    Monster->task_action = Mutant_Task_Action;
    Monster->func_decide = Mutant_Func_Decisions;
    pcVar3 = Mutant_Func_Reflex;
    goto LAB_80071ac0;
  case 4:
    Mask = 0x900fffff;
    Monster->task_action = Boucher_Task_Action;
    Monster->func_decide = Boucher_Func_Decisions;
    pcVar3 = Golem_Hit;
    goto LAB_80071ac0;
  case 5:
    Mask = 0x900fffff;
    *(undefined *)((int)&D3Obj[1].pos.vx + 1) = 0xf3;
    Monster->task_action = Harb_Func_Decisions;
    pcVar3 = Nessy_Func_Reflex;
    Monster->func_decide = (_func_33 *)0x0;
    goto LAB_80071ac0;
  case 6:
    Monster->task_action = Dragon_Task_Action;
    Monster->func_decide = Dragon_Func_Decisions;
    Monster->func_reflex = Dragon_Func_Reflex;
    Scts_Interruptors = Scts_Interruptors & 0xffffbfff;
    Mask = 0x900fcfff;
    break;
  case 7:
    D3_SetBox(D3Obj,(int)(D3Obj->b_box).vx,(int)D3Obj->comp_opt3,0,(int)*(short *)&D3Obj->b_step,
              (int)(D3Obj->b_box).vy,(int)*(short *)&D3Obj[1].prec);
    Mask = 0x9cffffff;
    Monster->timer_agression = 0xd2;
    Monster->task_action = Puch_Task_Action;
    Monster->func_decide = Puch_Func_Decisions;
    pcVar3 = Puch_Func_Reflex;
LAB_80071ac0:
    Monster->func_reflex = pcVar3;
    break;
  default:
    goto LAB_80071acc;
  }
  Monster_Main_Module(Monster,Mask);
LAB_80071acc:
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EB_Bat_MainTask()
 // line 259, offset 0x80071ae4
	/* begin block 1 */
		// Start line: 260
		// Start offset: 0x80071AE4
		// Variables:
	// 		struct ENEMY_31fake pft4[2]; // stack offset -96
	// 		struct _MONSTER *Monster; // $s1
	// 		struct _D3_OBJECT *D3Obj; // $s0
	// 		long comp; // $s2
	/* end block 1 */
	// End offset: 0x80071FD0
	// End Line: 389

	/* begin block 2 */
		// Start line: 586
	/* end block 2 */
	// End Line: 587

/* WARNING: Unknown calling convention yet parameter storage is locked */

void EB_Bat_MainTask(void)

{
  short sVar1;
  ushort uVar2;
  long lVar3;
  _MONSTER *Monster;
  code *pcVar4;
  ulong Mask;
  _D3_OBJECT *D3Obj;
  uint uVar5;
  
  D3Obj = (_D3_OBJECT *)TaskCurrent->local;
  uVar5 = (uint)(ushort)D3Obj[1].pos.vy & 0xf;
  if (uVar5 == 9) {
    Pirhana_Task(0xa0);
    return;
  }
  Monster_CreateShadow(D3Obj,0xa0);
  lVar3 = Pvl_TestStateBits(D3Obj,2);
  if (lVar3 != 0) {
    D3Obj->display_mode = D3Obj->display_mode & 0xffef;
    D3_ClearCollBits(D3Obj,(long)&DAT_00004019);
    lVar3 = Pvl_TestStateBits(D3Obj,0x10);
    if (lVar3 != 0) {
      D3_SetBonuses(D3Obj,1,D3Obj);
    }
    do {
      Task_Next();
    } while( true );
  }
  *(undefined *)((int)&D3Obj[1].pos.vx + 1) = 0xe0;
  D3_SetCollBits(D3Obj,8);
  Monster = Monster_Main_Init((_D3_OBJECT *)0x0);
  switch(uVar5) {
  case 0:
    Mask = 0x80fed5fb;
    *(undefined *)((int)&D3Obj[1].pos.vx + 1) = 0xf3;
    Monster->task_action = Bat_Small_Task_Action;
    Monster->func_decide = Bat_Small_Func_Decisions;
    pcVar4 = Bat_Small_Func_Reflex;
    break;
  case 1:
    Mask = 0x80fed5fb;
    *(undefined *)((int)&D3Obj[1].pos.vx + 1) = 0xf3;
    Monster->task_action = Bat_Small_Task_Action;
    Monster->func_decide = Bat_Small_Func_Decisions;
    Monster->func_reflex = Bat_Small_Func_Reflex;
    Monster->flags = Monster->flags & 0xffef;
    goto LAB_80071fc8;
  case 2:
    if ((D3Obj[1].pos.vz & 0x400U) == 0) {
      lVar3 = 10;
    }
    else {
      lVar3 = 0x3c;
    }
    Monster->timer_agression = lVar3;
    D3_SetBox(D3Obj,(int)(D3Obj->b_box).vx,(int)D3Obj->comp_opt3,0,(int)*(short *)&D3Obj->b_step,
              (int)(D3Obj->b_box).vy,(int)*(short *)&D3Obj[1].prec);
    Mask = 0x980fffff;
    Monster->task_action = Raptor_Small_Task_Action;
    Monster->func_decide = Decisions;
    pcVar4 = Raptor_Small_Func_Reflex;
    break;
  case 3:
    if ((D3Obj[1].pos.vz & 0x400U) == 0) {
      lVar3 = 0x1e;
    }
    else {
      lVar3 = 0x5a;
    }
    Monster->timer_agression = lVar3;
    D3_SetBox(D3Obj,(int)(D3Obj->b_box).vx,(int)D3Obj->comp_opt3,0,(int)*(short *)&D3Obj->b_step,
              (int)(D3Obj->b_box).vy,(int)*(short *)&D3Obj[1].prec);
    Mask = 0x880efef9;
    Monster->task_action = Funkie_Task_Action;
    Monster->func_decide = Decisions;
    pcVar4 = Funkie_Func_Reflex;
    break;
  case 4:
    D3_SetBox(D3Obj,(int)(D3Obj->b_box).vx,(int)D3Obj->comp_opt3,0,(int)*(short *)&D3Obj->b_step,
              (int)(D3Obj->b_box).vy,(int)*(short *)&D3Obj[1].prec);
    if ((D3Obj[1].pos.vz & 0x400U) == 0) {
      lVar3 = 0x1e;
    }
    else {
      lVar3 = 0x5a;
    }
    Monster->timer_agression = lVar3;
    Mask = 0x880efff9;
    Monster->task_action = Rat_Task_Action;
    Monster->func_decide = Decisions;
    pcVar4 = Rat_Func_Reflex;
    break;
  case 5:
    D3_SetBox(D3Obj,(int)(D3Obj->b_box).vx,(int)D3Obj->comp_opt3,0,(int)*(short *)&D3Obj->b_step,
              (int)(D3Obj->b_box).vy,(int)*(short *)&D3Obj[1].prec);
    lVar3 = 0x5a;
    if ((D3Obj[1].pos.vz & 0x400U) == 0) {
      lVar3 = 0x1e;
    }
    Monster->timer_agression = lVar3;
    Mask = 0x880efff9;
    Monster->task_action = Spider_Task_Action;
    Monster->func_decide = Decisions;
    Monster->func_reflex = Spider_Func_Reflex;
    Monster->flags = Monster->flags & 0xfffc;
    goto LAB_80071fc8;
  case 6:
    D3_SetBox(D3Obj,(int)(D3Obj->b_box).vx,(int)D3Obj->comp_opt3,0,(int)*(short *)&D3Obj->b_step,
              (int)(D3Obj->b_box).vy,(int)*(short *)&D3Obj[1].prec);
    lVar3 = 0x5a;
    if ((D3Obj[1].pos.vz & 0x400U) == 0) {
      lVar3 = 0x1e;
    }
    Monster->timer_agression = lVar3;
    if ((D3Obj[1].pos.vz & 0x20U) == 0) {
      uVar2 = Monster->flags | 1;
    }
    else {
      uVar2 = Monster->flags | 2;
    }
    Monster->flags = uVar2;
    Mask = 0x880efff9;
    Monster->task_action = Spider_Task_Action;
    Monster->func_decide = Decisions;
    pcVar4 = Spider_Func_Reflex;
    break;
  default:
    goto switchD_80071bd4_caseD_7;
  case 8:
    Mask = 0x88060f2d;
    *(undefined *)((int)&D3Obj[1].pos.vx + 1) = 0xf3;
    sVar1 = (D3Obj->pos).vz;
    Monster->task_action = Pirhana_Task_Action;
    Monster->func_decide = Pirhana_Func_Decide;
    Monster->func_reflex = Pirhana_Func_Reflex;
    Monster->timer = sVar1;
    goto LAB_80071fc8;
  case 10:
    uVar2 = D3Obj[1].pos.vz;
    *(undefined *)((int)&D3Obj[1].pos.vx + 1) = 0xf3;
    if ((uVar2 & 0x400) == 0) {
LAB_80071f90:
      lVar3 = 0x5a;
    }
    else {
      lVar3 = 0x96;
    }
    goto LAB_80071f94;
  case 0xb:
    uVar2 = D3Obj[1].pos.vz;
    *(undefined *)((int)&D3Obj[1].pos.vx + 1) = 0xf3;
    if ((uVar2 & 0x400) == 0) goto LAB_80071f90;
    lVar3 = 0x96;
LAB_80071f94:
    Monster->timer_agression = lVar3;
    Mask = 0x880efff9;
    Monster->task_action = Rod_Task_Action;
    Monster->func_decide = Rod_Func_Decisions;
    pcVar4 = Rod_Func_Reflex;
  }
  Monster->func_reflex = pcVar4;
LAB_80071fc8:
  Monster_Main_Module(Monster,Mask);
switchD_80071bd4_caseD_7:
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EB_Soldats_MainTask()
 // line 392, offset 0x80071fe8
	/* begin block 1 */
		// Start line: 393
		// Start offset: 0x80071FE8
		// Variables:
	// 		struct ENEMY_31fake pft4[2]; // stack offset -104
	// 		struct _D3_OBJECT *D3Obj; // $s0
	// 		struct M_OBJECT *mo; // $s3
	// 		struct _MONSTER *Monster; // $s1
	// 		long comp; // $s4
	// 		long factor; // $s2
	/* end block 1 */
	// End offset: 0x8007297C
	// End Line: 651

	/* begin block 2 */
		// Start line: 895
	/* end block 2 */
	// End Line: 896

/* WARNING: Unknown calling convention yet parameter storage is locked */

void EB_Soldats_MainTask(void)

{
  ushort uVar1;
  long lVar2;
  _MONSTER *Monster;
  code *pcVar3;
  int iVar4;
  ulong Mask;
  _D3_OBJECT *D3Obj;
  int unaff_s2;
  void *pvVar5;
  
  D3Obj = (_D3_OBJECT *)TaskCurrent->local;
  pvVar5 = D3Obj->description;
  if (Pvl_Difficulty == 1) {
    unaff_s2 = 0xa000;
  }
  else {
    if (Pvl_Difficulty < 2) {
      if (Pvl_Difficulty == 0) {
        unaff_s2 = 0x18000;
      }
    }
    else {
      if (Pvl_Difficulty == 2) {
        unaff_s2 = 0x4000;
      }
    }
  }
  iVar4 = (int)Pvl_LevelNumber;
  *(undefined *)((int)&D3Obj[1].pos.vx + 1) = 0xf3;
  iVar4 = unaff_s2 + (10 - iVar4) * 0x1000;
  Monster_CreateShadow(D3Obj,0x98);
  lVar2 = Pvl_TestStateBits(D3Obj,2);
  if (lVar2 != 0) {
    D3Obj->display_mode = D3Obj->display_mode & 0xffef;
    D3_ClearCollBits(D3Obj,(long)&DAT_00004019);
    lVar2 = Pvl_TestStateBits(D3Obj,0x10);
    if (lVar2 != 0) {
      D3_SetBonuses(D3Obj,1,D3Obj);
    }
    if ((D3Obj[1].pos.vy & 0x1fU) == 3) {
      Monster_DisplayChild(D3Obj,0);
    }
    do {
      Task_Next();
    } while( true );
  }
  D3_SetCollBits(D3Obj,8);
  uVar1 = D3Obj[1].pos.vy;
  Monster = Monster_Main_Init((_D3_OBJECT *)0x0);
  D3_SetBox(D3Obj,(int)(D3Obj->b_box).vx,(int)D3Obj->comp_opt3,0,(int)*(short *)&D3Obj->b_step,
            (int)(D3Obj->b_box).vy,(int)*(short *)&D3Obj[1].prec);
  switch((uint)uVar1 & 0x1f) {
  case 0:
    *(undefined *)(*(int *)((int)pvVar5 + 4) + 3) = 0x39;
    if ((D3Obj[1].pos.vz & 0x400U) == 0) {
      lVar2 = 0x1e;
    }
    else {
      lVar2 = 0x5a;
    }
    Monster->timer_agression = lVar2;
    Mask = 0x8a0fffbf;
    Monster->task_action = Soldier_Grenade_Task_Action;
    Monster->func_decide = Decisions;
    pcVar3 = Soldier_Grenade_Func_Reflex;
    break;
  case 1:
    if ((D3Obj[1].pos.vz & 0x400U) == 0) {
      iVar4 = iVar4 * 0xb4;
    }
    else {
      iVar4 = iVar4 * 0x168;
    }
    Monster->timer_agression = iVar4 >> 0x10;
    Mask = 0x8a1fffff;
    Monster->task_action = Soldier_Gunner_Task_Action;
    Monster->func_decide = Decisions;
    Monster->func_reflex = Soldier_Gunner_Func_Reflex;
    Monster->height = Monster->height + -0x28;
    goto LAB_80072974;
  case 2:
    *(undefined *)(*(int *)((int)pvVar5 + 4) + 3) = 0x39;
    if ((D3Obj[1].pos.vz & 0x400U) == 0) {
      lVar2 = 0x3c;
    }
    else {
      lVar2 = 0x78;
    }
    Monster->timer_agression = lVar2;
    Mask = 0x8a0fffff;
    Monster->task_action = Soldier_Gremit_Task_Action;
    Monster->func_decide = Decisions;
    pcVar3 = Soldier_Grenade_Func_Reflex;
    break;
  case 3:
    lVar2 = 0x96;
    if ((D3Obj[1].pos.vz & 0x400U) == 0) {
      lVar2 = 0x5a;
    }
    Monster->timer_agression = lVar2;
    Mask = 0x880fefff;
    Monster->task_action = Soldier_Soudeur_Task_Action;
    Monster->func_decide = Decisions;
    Monster->func_reflex = Soldier_Soudeur_Func_Reflex;
    Monster->func_init = Soldier_Soudeur_Init;
    Monster->height = 100;
    goto LAB_80072974;
  case 4:
    lVar2 = 0xf0;
    if ((D3Obj[1].pos.vz & 0x400U) == 0) {
      lVar2 = 0x78;
    }
    Monster->timer_agression = lVar2;
    Mask = 0x880f7fff;
    Monster->task_action = Soldier_RobNail_Task_Action;
    Monster->func_decide = Soldier_RobNail_Func_Decisions;
    Monster->func_reflex = Soldier_RobNail_Func_Reflex;
    Monster->func_init = Soldier_RobNail_Init;
    Monster->height = -0x1e;
    goto LAB_80072974;
  case 5:
    if ((D3Obj[1].pos.vz & 0x400U) == 0) {
      lVar2 = 0x5a;
    }
    else {
      lVar2 = 0x96;
    }
    Monster->timer_agression = lVar2;
    Mask = 0x880fdf7f;
    Monster->task_action = Zombie_Task_Action;
    Monster->func_decide = Decisions;
    pcVar3 = Zombie_Func_Reflex;
    break;
  case 6:
    if ((D3Obj[1].pos.vz & 0x400U) == 0) {
      lVar2 = 0x5a;
    }
    else {
      lVar2 = 0x96;
    }
    Monster->timer_agression = lVar2;
    Mask = 0x880fdf7f;
    Monster->task_action = Zombie_Task_Action;
    Monster->func_decide = Decisions;
    pcVar3 = Zombie_Func_Reflex;
    break;
  case 7:
    if ((D3Obj[1].pos.vz & 0x400U) == 0) {
      lVar2 = 0x5a;
    }
    else {
      lVar2 = 0x96;
    }
    Monster->timer_agression = lVar2;
    Mask = 0x980fdf7f;
    Monster->task_action = Zombie_Task_Action;
    Monster->func_decide = Decisions;
    pcVar3 = Zombie_Func_Reflex;
    break;
  case 8:
    lVar2 = 0xd2;
    if ((D3Obj[1].pos.vz & 0x400U) == 0) {
      lVar2 = 0x96;
    }
    Monster->timer_agression = lVar2;
    Mask = 0x8a0efdff;
    Monster->task_action = Maton_Task_Action;
    Monster->func_decide = Decisions;
    Monster->func_reflex = Maton_Func_Reflex;
    Monster->height = Monster->height + -0x28;
    goto LAB_80072974;
  case 9:
    lVar2 = 0xb4;
    if ((D3Obj[1].pos.vz & 0x400U) == 0) {
      lVar2 = 0x5a;
    }
    Monster->timer_agression = lVar2;
    Mask = 0x880fffff;
    Monster->task_action = Hpl_Task_Action;
    Monster->func_decide = Decisions;
    Monster->func_reflex = Hpl_Func_Reflex;
    Monster->height = 100;
    goto LAB_80072974;
  case 10:
    *(undefined *)(*(int *)((int)pvVar5 + 4) + 3) = 0x39;
    lVar2 = 0xb4;
    if ((D3Obj[1].pos.vz & 0x400U) == 0) {
      lVar2 = 0x78;
    }
    Monster->timer_agression = lVar2;
    Mask = 0x8a0efdff;
    Monster->task_action = Maton_Task_Action;
    Monster->func_decide = Decisions;
    Monster->func_reflex = Gua_Func_Reflex;
    Monster->height = Monster->height + -0x28;
    goto LAB_80072974;
  case 0xb:
    if ((D3Obj[1].pos.vz & 0x400U) == 0) {
      lVar2 = 0x5a;
    }
    else {
      lVar2 = 0x96;
    }
    Monster->timer_agression = lVar2;
    Mask = 0x8a0fffff;
    Monster->task_action = Big_Task_Action;
    Monster->func_decide = Decisions;
    pcVar3 = Big_Func_Reflex;
    break;
  case 0xc:
    Mask = 0x98003089;
    Monster->task_action = Pri_Task_Action;
    Monster->func_decide = Decisions;
    Monster->func_reflex = Pri_Func_Reflex;
    Monster->flags2 = Monster->flags2 | 1;
    goto LAB_80072974;
  case 0xd:
    Monster->flags2 = Monster->flags2 | 1;
    if ((D3Obj[1].pos.vz & 0x400U) == 0) {
      lVar2 = 0x78;
    }
    else {
      lVar2 = 0xf0;
    }
    Monster->timer_agression = lVar2;
    Mask = 0x880fffff;
    Monster->task_action = Bos_Task_Action;
    Monster->func_decide = Bos_Func_Decisions;
    pcVar3 = Bos_Func_Reflex;
    break;
  case 0xe:
    Mask = 0x880fffff;
    Monster->task_action = Bos_Task_Action;
    Monster->func_decide = Bos_Func_Decisions;
    Monster->func_reflex = Bos_Func_Reflex;
    Monster->flags2 = Monster->flags2 | 1;
    goto LAB_80072974;
  case 0xf:
    lVar2 = 0x5a;
    if ((D3Obj[1].pos.vz & 0x400U) == 0) {
      lVar2 = 0x3c;
    }
    Monster->timer_agression = lVar2;
    Mask = 0x88042f7f;
    Monster->task_action = Haq_Task_Action;
    pcVar3 = Haq_Func_Reflex;
    Monster->func_decide = (_func_33 *)0x0;
    break;
  case 0x10:
    *(undefined *)(*(int *)((int)pvVar5 + 4) + 3) = 0x39;
    if ((D3Obj[1].pos.vz & 0x400U) == 0) {
      lVar2 = 0x78;
    }
    else {
      lVar2 = 0xf0;
    }
    Monster->timer_agression = lVar2;
    Mask = 0x880fffff;
    Monster->task_action = Com_Task_Action;
    Monster->func_decide = Decisions;
    pcVar3 = Com_Func_Reflex;
    break;
  case 0x11:
    lVar2 = Pvl_TestStateBits(D3Obj,8);
    if (lVar2 != 0) goto switchD_80072178_caseD_14;
    lVar2 = 0xf0;
    if ((D3Obj[1].pos.vz & 0x400U) == 0) {
      lVar2 = 0x78;
    }
    Monster->timer_agression = lVar2;
    D3_SetBox(D3Obj,(int)(D3Obj->b_box).vx,(int)D3Obj->comp_opt3,0,(int)*(short *)&D3Obj->b_step,
              (int)(D3Obj->b_box).vy,5);
    D3_ClearCollBits(D3Obj,0x4000);
    Mask = 0x980fdf7f;
    D3Obj[1].pos.vy = (D3Obj[1].pos.vy & 0xffe0U) + 7;
    Monster->task_action = Zombie_Task_Action;
    Monster->func_decide = Decisions;
    Monster->func_reflex = Spectre_Func_Reflex;
    Monster->flags2 = Monster->flags2 | 0x10;
    goto LAB_80072974;
  case 0x12:
    if ((D3Obj[1].pos.vz & 0x400U) == 0) {
      lVar2 = 0x78;
    }
    else {
      lVar2 = 0xf0;
    }
    Monster->timer_agression = lVar2;
    Mask = 0x880fdf7f;
    Monster->task_action = Skeleton_Task_Action;
    Monster->func_decide = Decisions;
    pcVar3 = Skeleton_Func_Reflex;
    break;
  case 0x13:
    lVar2 = 0xf0;
    if ((D3Obj[1].pos.vz & 0x400U) == 0) {
      lVar2 = 0x78;
    }
    Monster->timer_agression = lVar2;
    Mask = 0x880fdf7f;
    Monster->task_action = Sorcier_Task_Action;
    Monster->func_decide = Decisions;
    pcVar3 = Sorcier_Func_Reflex;
    break;
  case 0x14:
switchD_80072178_caseD_14:
    lVar2 = 0xf0;
    if ((D3Obj[1].pos.vz & 0x400U) == 0) {
      lVar2 = 0x78;
    }
    Monster->timer_agression = lVar2;
    D3_SetBox(D3Obj,(int)(D3Obj->b_box).vx,(int)D3Obj->comp_opt3,0,(int)*(short *)&D3Obj->b_step,
              (int)(D3Obj->b_box).vy,5);
    D3_ClearCollBits(D3Obj,0x4000);
    lVar2 = 0x96;
    if ((D3Obj[1].pos.vz & 0x400U) == 0) {
      lVar2 = 0x5a;
    }
    Monster->timer_agression = lVar2;
    Mask = 0x880fdf7f;
    Monster->task_action = Zombie_Task_Action;
    Monster->func_decide = Decisions;
    Monster->func_reflex = Spectre_Func_Reflex;
    Monster->flags2 = Monster->flags2 | 0x10;
    goto LAB_80072974;
  default:
    goto LAB_8007297c;
  }
  Monster->func_reflex = pcVar3;
LAB_80072974:
  Monster_Main_Module(Monster,Mask);
LAB_8007297c:
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pirhana_Task_Next()
 // line 669, offset 0x8007299c
	/* begin block 1 */
		// Start line: 670
		// Start offset: 0x8007299C
		// Variables:
	// 		struct _D3_OBJECT *o; // $v1
	/* end block 1 */
	// End offset: 0x80072A00
	// End Line: 677

	/* begin block 2 */
		// Start line: 1569
	/* end block 2 */
	// End Line: 1570

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pirhana_Task_Next(void)

{
  void *pvVar1;
  
  pvVar1 = TaskCurrent->local;
  if (((int)*(short *)((int)pvVar1 + 0x9c) & 0x8000U) == 0) {
    *(undefined4 *)((int)pvVar1 + 0x28) = 0x808080;
  }
  if (((*(ushort *)((int)pvVar1 + 0x1e) & 0x20) != 0) &&
     (((int)*(short *)((int)pvVar1 + 0x9c) & 0x8000U) == 0)) {
    *(undefined4 *)((int)pvVar1 + 0x28) = 0xff3030;
  }
  Task_Next();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pirhana_Wait(struct _D3_OBJECT *o /*$s0*/, long time /*$s5*/, long x /*$s3*/, long y /*$s4*/)
 // line 680, offset 0x80072a18
	/* begin block 1 */
		// Start line: 681
		// Start offset: 0x80072A18
		// Variables:
	// 		struct M_OBJECT *mo; // $s2
	// 		long i; // $s1
	// 		long j; // $s6
	/* end block 1 */
	// End offset: 0x80072B2C
	// End Line: 704

	/* begin block 2 */
		// Start line: 1591
	/* end block 2 */
	// End Line: 1592

void Pirhana_Wait(_D3_OBJECT *o,long time,long x,long y)

{
  short sVar1;
  short sVar2;
  long lVar3;
  long lVar4;
  uint uVar5;
  uint uVar6;
  M_OBJECT *obj;
  
  obj = (M_OBJECT *)o->description;
  if ((o[1].pos.vz & 0x200U) != 0) {
    (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
  }
  uVar6 = 0;
  lVar3 = M_rand();
  if (0 < time) {
    uVar5 = 0;
    do {
      if (uVar5 == 0xf) {
        Impact_Circle((char)o + ',',1);
      }
      if ((o[1].pos.vz & 0x200U) == 0) {
        sVar1 = (o->pos).vx;
        sVar2 = (o->pos).vy;
        (o->rot).vz = (o->rot).vz + (((ushort)lVar3 & 0xf) - 8) * 8;
        lVar4 = Distance2D(x,y,(int)sVar1,(int)sVar2);
        if (0x96 < lVar4) {
          (obj->Env).Obj.normal_top.vy = 0;
          while (lVar4 = D3_GoToDir(o,x - (int)(o->pos).vx,y - (int)(o->pos).vy,0x28), lVar4 != 0) {
            Task_Next();
          }
          (obj->Env).Obj.normal_top.vy = 0x100;
          Task_Sleep(3);
        }
      }
      uVar6 = uVar6 + 1;
      Task_Next();
      uVar5 = uVar6 & 0x1f;
    } while ((int)uVar6 < time);
  }
  Manim_SetAnim(obj,0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pirhana_Func_Reflex()
 // line 708, offset 0x80072b60
	/* begin block 1 */
		// Start line: 709
		// Start offset: 0x80072B60
		// Variables:
	// 		struct _MONSTER *monst; // $s0
	// 		struct _D3_OBJECT *o; // $s1
	// 		struct _D3_OBJECT *target; // $s2
	// 		long tmp; // $a0
	// 		long i; // $v1
	/* end block 1 */
	// End offset: 0x80072D6C
	// End Line: 756

	/* begin block 2 */
		// Start line: 1668
	/* end block 2 */
	// End Line: 1669

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pirhana_Func_Reflex(void)

{
  ushort uVar1;
  short sVar2;
  long lVar3;
  short sVar4;
  long d1;
  int iVar5;
  int iVar6;
  _MONSTER *monst;
  _D3_OBJECT *p_Var7;
  
  lVar3 = Monster_Feelings;
  monst = (_MONSTER *)TaskCurrent->local;
  p_Var7 = monst->obj;
  uVar1 = p_Var7[1].pos.pad;
  if ((uVar1 != 0) && ((Scts_Interruptors & (uint)uVar1) == (uint)uVar1)) {
    Monster_StopAllActions(monst);
    Monster_AddAction(monst,0,3,0,0);
  }
  d1 = Direction((int)*(short *)(lVar3 + 0x2c) - (int)(p_Var7->pos).vx,
                 (int)*(short *)(lVar3 + 0x2e) - (int)(p_Var7->pos).vy);
  d1 = DeltaDirection(d1,(int)(p_Var7->rot).vz);
  if (monst->mode != 0xd) {
    if ((((LONG_ARRAY_800b2e40[0] != -1) && (LONG_ARRAY_800b2e40[0] < 2000)) && (d1 + 0x200 < 0x400)
        ) && ((0 < d1 + 0x200 && (LONG_ARRAY_800b2e40[0] < 0x96)))) {
      Monster_StopAllActions(monst);
      Monster_AddAction(monst,0,0xb,0,0);
    }
  }
  if (monst->action == 3) goto LAB_80072d28;
  if (LONG_ARRAY_800b2e2c[0] == -1) {
LAB_80072cdc:
    iVar5 = (int)(p_Var7->pos).vz;
    if (((monst->counter <= iVar5) || (sVar4 = (p_Var7->pos).vz + 2, (int)monst->timer <= iVar5)) &&
       (sVar4 = (p_Var7->pos).vz + -2, (p_Var7->pos).vz <= monst->timer)) goto LAB_80072d28;
  }
  else {
    iVar5 = (int)(p_Var7->pos).vz;
    iVar6 = (int)*(short *)(lVar3 + 0x30);
    sVar2 = (p_Var7->pos).vz;
    if (iVar5 + (int)monst->height <= iVar6) goto LAB_80072cdc;
    sVar4 = sVar2 + -2;
    if (iVar5 <= iVar6 + 100) {
      if ((iVar5 < monst->counter) && (iVar5 < iVar6)) {
        (p_Var7->pos).vz = sVar2 + 2;
      }
      goto LAB_80072d28;
    }
  }
  (p_Var7->pos).vz = sVar4;
LAB_80072d28:
  if ((LONG_ARRAY_800b2e2c[0] == -1) && (monst->mode != 0x10)) {
    Monster_StopAllActions(monst);
    Monster_AddAction(monst,0,1,0,0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pirhana_Func_Decide()
 // line 758, offset 0x80072d84
	/* begin block 1 */
		// Start line: 759
		// Start offset: 0x80072D84
		// Variables:
	// 		struct _MONSTER *monst; // $s0
	// 		struct _D3_OBJECT *target; // $a1
	/* end block 1 */
	// End offset: 0x80072DFC
	// End Line: 768

	/* begin block 2 */
		// Start line: 1771
	/* end block 2 */
	// End Line: 1772

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pirhana_Func_Decide(void)

{
  _MONSTER *monst;
  
  monst = (_MONSTER *)TaskCurrent->local;
  if ((LONG_ARRAY_800b2e2c[0] != -1) &&
     ((int)*(short *)(Monster_Feelings + 0x30) < (int)(monst->obj->pos).vz + (int)monst->height)) {
    Monster_StopAllActions(monst);
    Monster_AddAction(monst,0,5,LONG_ARRAY_800b2e2c[0],0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pirhana_Task_Action()
 // line 771, offset 0x80072e0c
	/* begin block 1 */
		// Start line: 772
		// Start offset: 0x80072E0C
		// Variables:
	// 		struct _MONSTER *monst; // $s2
	// 		struct _D3_OBJECT *o; // $s1
	// 		struct M_OBJECT *mo; // $s3
	// 		long tmp; // $s0
	// 		long x; // $s2
	// 		long y; // $s0
	/* end block 1 */
	// End offset: 0x80073184
	// End Line: 863

	/* begin block 2 */
		// Start line: 1803
	/* end block 2 */
	// End Line: 1804

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pirhana_Task_Action(void)

{
  short sVar1;
  TASK *pTVar2;
  short sVar3;
  long lVar4;
  uint uVar5;
  int iVar6;
  _D3_OBJECT *o;
  _MONSTER *monst;
  M_OBJECT *obj;
  
  monst = (_MONSTER *)TaskCurrent->local;
  o = monst->obj;
  obj = (M_OBJECT *)o->description;
  monst->sensormask = monst->sensormask | 0x80003000;
  sVar3 = (o->pos).vz;
  monst->monster_trans = 0x100;
  monst->monster_speed = 0x58;
  monst->counter = (int)sVar3;
  if (((int)o[1].pos.vz & 0x8000U) == 0) {
    o->color = 0xff3030;
  }
  lVar4 = Task_EventWait();
  pTVar2 = TaskCurrent;
  monst->action = (short)lVar4;
  pTVar2->event_enable = 1;
  do {
    pTVar2 = TaskCurrent;
    switch((int)(((uint)(ushort)monst->action - 1) * 0x10000) >> 0x10) {
    case 0:
      monst->busy = 0;
      monst->mode = 0x10;
      Manim_SetAnim(obj,0);
      sVar3 = (o->pos).vx;
      sVar1 = (o->pos).vy;
      do {
        Pirhana_Wait(o,0x5a,(int)sVar3,(int)sVar1);
      } while( true );
    case 1:
      lVar4 = Monster_Action_Hit(-1,2,1,-1);
      if (lVar4 != 0) {
        Manim_SetAnim(obj,1);
        Monster_ReleaseBonuses();
        TaskCurrent->event_enable = 0;
        while (((int)o->collision_state & 0xfc00U) == 0) {
          (o->pos).vz = (o->pos).vz + -5;
          Task_Next();
        }
        monst->sensormask = 1;
        D3_ClearCollBits(o,0xb);
        (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
        return;
      }
      break;
    case 2:
      TaskCurrent->event_enable = 0;
      (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
      uVar5 = M_rand();
      sVar3 = 0x200;
      if ((uVar5 & 1) == 0) {
        sVar3 = -0x200;
      }
      (o->rot).vx = sVar3;
      while (((int)o->collision_state & 0xfc00U) == 0) {
        (o->pos).vz = (o->pos).vz + -5;
        Task_Next();
      }
      monst->sensormask = 1;
      Manim_SetAnim(obj,1);
      D3_ClearCollBits(o,0xb);
      do {
        Task_Next();
      } while( true );
    case 4:
      Monster_Action_MoveTo
                ((int)*(short *)((int)&TaskCurrent->event_param + 2),
                 (int)*(short *)&TaskCurrent->event_param,0,(_D3_OBJECT *)Monster_Feelings,0x50,-1,2
                 ,-1,-1,-1,-1);
      monst->actionmask = 0;
      goto LAB_8007315c;
    case 10:
      iVar6 = 0;
      monst->mode = 0xd;
      pTVar2->event_enable = 0;
      D3_SetCollBits(o,2);
      Manim_SetAnim(obj,2);
      (obj->Env).Obj.normal_top.vy = 0x280;
      do {
        iVar6 = iVar6 + 1;
        Task_Next();
      } while (iVar6 < 7);
      D3_ClearCollBits(o,2);
      sVar3 = 0x100;
      if (monst->timer_agression == 0) {
        sVar3 = 0x150;
      }
      (obj->Env).Obj.normal_top.vy = sVar3;
      uVar5 = M_rand();
      if ((uVar5 & 1) == 0) {
        sVar3 = (o->rot).vz + -0x300;
      }
      else {
        sVar3 = (o->rot).vz + 0x300;
      }
      (o->rot).vz = sVar3;
      D3_PlaySound(o,0);
      while (LONG_ARRAY_800b2e40[0] < 0xfa) {
        Task_Next();
      }
      TaskCurrent->event_enable = 1;
    }
    monst->actionmask = 0;
LAB_8007315c:
    monst->busy = -1;
    Task_Next();
    Monster_ForceAction(monst,1,0);
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pirhana_Impact(struct _D3_OBJECT *o /*$s2*/, long extra /*$s3*/)
 // line 865, offset 0x800731a4
	/* begin block 1 */
		// Start line: 866
		// Start offset: 0x800731A4
		// Variables:
	// 		struct ENEMY_7fake pos[4]; // stack offset -64
	// 		struct ENEMY_8fake color; // stack offset -32
	// 		long i; // $s1
	/* end block 1 */
	// End offset: 0x80073268
	// End Line: 883

	/* begin block 2 */
		// Start line: 2018
	/* end block 2 */
	// End Line: 2019

/* WARNING: Could not reconcile some variable overlaps */

void Pirhana_Impact(_D3_OBJECT *o,long extra)

{
  long lVar1;
  uint uVar2;
  short *psVar3;
  int iVar4;
  short local_40 [12];
  undefined4 local_28;
  uint local_24;
  undefined local_20;
  undefined local_1f;
  undefined local_1e;
  
  iVar4 = 0;
  psVar3 = local_40;
  local_20 = 0xff;
  local_1f = 0xff;
  local_1e = 0xff;
  do {
    iVar4 = iVar4 + 1;
    lVar1 = M_rand();
    *psVar3 = (o->pos).vx + ((ushort)lVar1 & 0x7f) + -0x40;
    lVar1 = M_rand();
    psVar3[1] = (o->pos).vy + ((ushort)lVar1 & 0x7f) + -0x40;
    psVar3[2] = (o->pos).vz;
    psVar3 = psVar3 + 4;
  } while (iVar4 < 3);
  local_28 = *(undefined4 *)&o->pos;
  uVar2 = *(uint *)&(o->pos).vz;
  local_24._0_2_ = (short)uVar2;
  local_24 = uVar2 & 0xffff0000 | (uint)(ushort)((short)local_24 + 0x8c);
  if (extra != 0) {
    Impact_Rain(0xd8,0xe0,10);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pirhana_Task(struct ENEMY_31fake *pft4 /*$s0*/)
 // line 885, offset 0x80073284
	/* begin block 1 */
		// Start line: 886
		// Start offset: 0x80073284
		// Variables:
	// 		struct ENEMY_8fake color; // stack offset -104
	// 		struct ENEMY_70fake shp; // stack offset -96
	// 		struct _D3_OBJECT *o; // $s2
	// 		struct M_OBJECT *mo; // $s7
	// 		struct _ZONE *z; // $a2
	// 		long posx; // $s6
	// 		long posy; // $s5
	// 		long posz; // $s4
	// 		long speedx; // $fp
	// 		long speedy; // $s1
	// 		long speedz; // $s3
	// 		long tmp; // $a2
	// 		long i; // $s0
	// 		long j; // $s1
	// 		long zone; // stack offset -56
	// 		long basez; // stack offset -52
	// 		long currentzone; // stack offset -48
	// 		long positions[3][2]; // stack offset -80
	/* end block 1 */
	// End offset: 0x800736C8
	// End Line: 976

	/* begin block 2 */
		// Start line: 2079
	/* end block 2 */
	// End Line: 2080

/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pirhana_Task(undefined pft4)

{
  ushort uVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined3 in_register_00000011;
  SHAPE_31fake *prim;
  short *psVar7;
  int iVar8;
  int *piVar9;
  long time;
  _ZONE *p_Var10;
  int vy;
  int vx;
  uint uVar11;
  int iVar12;
  _D3_OBJECT *o;
  int iVar13;
  int iVar14;
  M_OBJECT *obj;
  SHAPE_68fake local_60;
  short local_50 [12];
  uint local_38;
  int local_34;
  int local_30;
  
  local_60.file = Pl_Pcl;
  prim = (SHAPE_31fake *)CONCAT31(in_register_00000011,pft4);
  local_30 = 0;
  o = (_D3_OBJECT *)TaskCurrent->local;
  local_38 = 0;
  obj = (M_OBJECT *)o->description;
  uVar1 = (obj->Env).Obj.normal_top.vx;
  *(SHAPE_31fake **)&(obj->Env).Obj.vert_top = prim;
  (obj->Env).Obj.normal_top.vx = uVar1 & 0xfffe;
  local_60.shape = 0x25;
  Shp_SetPolyFT4(prim,&local_60,0,0);
  Shp_SetPolyFT4(prim + 1,&local_60,0,0);
  local_34 = (int)(o->pos).vz;
  o->display_mode = o->display_mode | 0x80;
  D3_SetCollBits(o,0x2000);
  vy = 0;
  if (0 < Pvl_File->n_zones) {
    psVar7 = &Pvl_Zones->nObjects;
    p_Var10 = Pvl_Zones;
    do {
      iVar12 = 0;
      if (0 < *psVar7) {
        piVar9 = (int *)(local_50 + local_38 * 4);
        do {
          if (*(_D3_OBJECT **)(iVar12 * 4 + *(int *)(psVar7 + 2)) == o) {
            *piVar9 = (int)p_Var10->x1 + (int)psVar7[-0x11] >> 1;
            local_38 = local_38 + 1;
            piVar9[1] = (int)psVar7[-0x13] + (int)psVar7[-0x10] >> 1;
            piVar9 = piVar9 + 2;
          }
          iVar12 = iVar12 + 1;
        } while (iVar12 < (int)*psVar7);
      }
      vy = vy + 1;
      psVar7 = psVar7 + 0x18;
      p_Var10 = p_Var10 + 1;
    } while (vy < (int)Pvl_File->n_zones);
  }
  if (local_38 < 2) {
    return;
  }
  (o->pos).vx = local_50[0];
  (o->pos).vy = local_50[2];
  do {
    if (((int)o[1].pos.vz & 0x8000U) == 0) {
      o->color = 0xff3030;
    }
    Manim_SetAnim(obj,0);
    time = *(long *)&o[1].last_pos;
    if (time < 0) {
      lVar2 = M_rand();
      vy = *(int *)&o[1].last_pos;
      if (vy < 0) {
        vy = -vy;
      }
      time = lVar2 % vy;
      if (vy == 0) {
        trap(0x1c00);
      }
      if ((vy == -1) && (lVar2 == -0x80000000)) {
        trap(0x1800);
      }
    }
    Pirhana_Wait(o,time,(int)(o->pos).vx,(int)(o->pos).vy);
    (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
    time = M_rand();
    vy = local_38 - 1;
    iVar12 = time % vy;
    if (vy == 0) {
      trap(0x1c00);
    }
    if ((vy == -1) && (time == -0x80000000)) {
      trap(0x1800);
    }
    vy = iVar12 << 3;
    if (iVar12 == local_30) {
      iVar12 = iVar12 + 1;
      vy = iVar12 * 8;
    }
    iVar3 = (int)(o->pos).vx;
    iVar5 = (int)(o->pos).vy;
    vx = *(int *)((int)local_50 + vy) - iVar3;
    vy = *(int *)((int)local_50[2] + vy) - iVar5;
    iVar3 = iVar3 << 0xc;
    iVar5 = iVar5 << 0xc;
    (o->pos).vz = (short)local_34;
    local_30 = iVar12;
    time = Direction(vx,vy);
    iVar12 = (int)o[1].pos.pad;
    vx = vx * 0x800;
    if (iVar12 == 0) {
      trap(0x1c00);
    }
    if ((iVar12 == -1) && (vx == -0x80000000)) {
      trap(0x1800);
    }
    (o->rot).vz = (short)time;
    iVar13 = iVar12 * 0x5000;
    vy = vy * 0x800;
    if (iVar12 == 0) {
      trap(0x1c00);
    }
    if ((iVar12 == -1) && (vy == -0x80000000)) {
      trap(0x1800);
    }
    iVar14 = local_34 << 0xc;
    Manim_SetAnim(obj,1);
    uVar11 = 0;
    if (0 < (int)o[1].pos.pad << 1) {
      do {
        if (uVar11 == 3) {
          Pirhana_Impact(o,0);
          D3_PlaySound(o,1);
        }
        else {
          if (((int)uVar11 < 8) && ((uVar11 & 1) != 0)) {
            Impact_Rain((char)o + ',',0x98,(short)((0xd - uVar11) * 0x10000 >> 0x10));
          }
        }
        iVar13 = iVar13 + -0x5000;
        iVar8 = iVar3 >> 0xc;
        iVar3 = iVar3 + vx / iVar12;
        iVar6 = iVar5 >> 0xc;
        iVar5 = iVar5 + vy / iVar12;
        iVar4 = iVar14 >> 0xc;
        iVar14 = iVar14 + iVar13;
        (o->pos).vx = (short)iVar8;
        (o->pos).vy = (short)iVar6;
        (o->pos).vz = (short)iVar4;
        Pirhana_Task_Next();
        uVar11 = uVar11 + 1;
      } while ((int)uVar11 < (int)o[1].pos.pad << 1);
    }
    D3_PlaySound(o,2);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Bat_Small_Func_Reflex()
 // line 1007, offset 0x800736f8
	/* begin block 1 */
		// Start line: 1008
		// Start offset: 0x800736F8
		// Variables:
	// 		struct _MONSTER *monst; // $s0
	/* end block 1 */
	// End offset: 0x80073778
	// End Line: 1019

	/* begin block 2 */
		// Start line: 2447
	/* end block 2 */
	// End Line: 2448

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Bat_Small_Func_Reflex(void)

{
  long lVar1;
  _MONSTER *monst;
  
  monst = (_MONSTER *)TaskCurrent->local;
  lVar1 = Monster_Reflex_Fear(monst);
  if ((((lVar1 == 0) && (monst->action != 1)) && ((monst->flags & 0x10U) == 0)) &&
     (LONG_ARRAY_800b2e2c[0] == -1)) {
    Monster_ResetActions(monst);
    Monster_AddAction(monst,0,1,0,0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Bat_Small_Func_Decisions()
 // line 1022, offset 0x80073788
	/* begin block 1 */
		// Start line: 1023
		// Start offset: 0x80073788
		// Variables:
	// 		struct _MONSTER *mo; // $s1
	// 		long height; // $s0
	/* end block 1 */
	// End offset: 0x80073804
	// End Line: 1033

	/* begin block 2 */
		// Start line: 2477
	/* end block 2 */
	// End Line: 2478

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Bat_Small_Func_Decisions(void)

{
  long lVar1;
  _MONSTER *monst;
  
  monst = (_MONSTER *)TaskCurrent->local;
  if (LONG_ARRAY_800b2e2c[0] != -1) {
    lVar1 = Boxes_GetHeight((_D3_OBJECT *)Monster_Feelings,(char)Monster_Feelings + ',',
                            (short)(((uint)(ushort)monst->height + 100) * 0x10000 >> 0x10));
    Monster_StopAllActions(monst);
    Monster_AddAction(monst,0,5,LONG_ARRAY_800b2e2c[0],lVar1 + 300);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Bat_Small_Task_Action()
 // line 1036, offset 0x80073818
	/* begin block 1 */
		// Start line: 1037
		// Start offset: 0x80073818
		// Variables:
	// 		struct ENEMY_7fake pos; // stack offset -48
	// 		struct _MONSTER *monst; // $s1
	// 		struct _D3_OBJECT *o; // $s2
	// 		struct _D3_OBJECT *target; // $s5
	// 		struct M_OBJECT *mo; // $s0
	// 		long tmp; // $v0
	/* end block 1 */
	// End offset: 0x80073D5C
	// End Line: 1139

	/* begin block 2 */
		// Start line: 2511
	/* end block 2 */
	// End Line: 2512

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Bat_Small_Task_Action(void)

{
  short sVar1;
  TASK *pTVar2;
  short sVar3;
  short sVar4;
  long local_50;
  uint uVar5;
  long AnimNr;
  short zz;
  M_OBJECT *obj;
  _MONSTER *monst;
  _D3_OBJECT *o;
  
  AnimNr = Monster_Feelings;
  monst = (_MONSTER *)TaskCurrent->local;
  o = monst->obj;
  obj = (M_OBJECT *)o->description;
  monst->hurtsound = 3;
  if ((Pvl_SctState[(int)o->index] & 8U) != 0) {
    monst->flags = monst->flags & 0xffef;
  }
  local_50 = Task_EventWait();
  pTVar2 = TaskCurrent;
  monst->action = (short)local_50;
  pTVar2->event_enable = 1;
  do {
    switch((int)(((uint)(ushort)monst->action - 1) * 0x10000) >> 0x10) {
    case 0:
      monst->busy = 0;
      Task_Next();
      do {
        sVar3 = (short)((int)monst->zone_wait->x1 + (int)monst->zone_wait->x2 >> 1);
        sVar4 = (short)((int)monst->zone_wait->y1 + (int)monst->zone_wait->y2 >> 1);
        AnimNr = Boxes_GetHeightPlatform(o,0xd0);
        if ((monst->flags & 0x10U) == 0) {
          zz = (short)((uint)((AnimNr + 400) * 0x10000) >> 0x10);
          Monster_Action_MoveTo3D
                    ((short)((int)monst->zone_wait->x1 + (int)sVar3 >> 1),
                     (short)((int)monst->zone_wait->y1 + (int)sVar4 >> 1),zz,(_D3_OBJECT *)0x0,0xa0,
                     3,5,-1,8,5,0);
          Monster_Action_RunAnimationSpeed(2,0x10,0x100,0,4);
          Monster_Action_MoveTo3D
                    ((short)((int)monst->zone_wait->x2 + (int)sVar3 >> 1),
                     (short)((int)monst->zone_wait->y2 + (int)sVar4 >> 1),zz,(_D3_OBJECT *)0x0,0xa0,
                     3,5,-1,8,5,0);
          AnimNr = 2;
          local_50 = 4;
        }
        else {
          uVar5 = M_rand();
          if ((uVar5 & 3) == 1) {
            D3_PlaySound(o,4);
          }
          local_50 = -1;
          AnimNr = 1;
        }
        Monster_Action_RunAnimationSpeed(AnimNr,0x10,0x100,0,local_50);
        Task_Next();
      } while( true );
    case 1:
      monst->flags = monst->flags & 0xffef;
      D3_SetCollBits(o,0x4000);
      Monster_Action_Hit(7,6,0x801,1);
      monst->actionmask = 0;
      break;
    case 4:
      Pvl_SctState[(int)o->index] = Pvl_SctState[(int)o->index] | 8;
      Monster_Action_MoveTo3D
                (*(short *)((int)&TaskCurrent->event_param + 2),*(short *)&TaskCurrent->event_param,
                 (short)(((uint)*(ushort *)&monst->task_param2 -
                         (uint)*(ushort *)(Monster_Feelings + 0x30)) * 0x10000 >> 0x10),
                 (_D3_OBJECT *)AnimNr,0x96,3,5,0,8,5,0);
      monst->actionmask = 0;
      break;
    case 0x1d:
      D3_PlaySound(o,2);
      sVar3 = Pvl_EnemyZones[(int)monst->zone_fear].x1;
      sVar4 = Pvl_EnemyZones[(int)monst->zone_fear].x2;
      zz = Pvl_EnemyZones[(int)monst->zone_fear].y1;
      sVar1 = Pvl_EnemyZones[(int)monst->zone_fear].y2;
      local_50 = Boxes_GetHeight(monst->obj,0xd0,
                                 (short)(((uint)(ushort)monst->height + 100) * 0x10000 >> 0x10));
      Monster_Action_MoveTo3D
                ((short)((int)sVar3 + (int)sVar4 >> 1),(short)((int)zz + (int)sVar1 >> 1),
                 (short)((uint)((local_50 + 200) * 0x10000) >> 0x10),(_D3_OBJECT *)0x0,0x96,3,5,-1,8
                 ,5,0);
      D3_PlaySound(o,2);
      local_50 = Monster_FearFindFriends(monst);
      if (local_50 != 0) {
        MSensor_AddFear(monst,-100);
      }
      if (LONG_800b2e64 == -1) goto switchD_80073900_caseD_2;
      do {
        Manim_SetAnim(obj,4);
        while (((obj->Env).Obj.normal_top.vx & 0x4000U) == 0) {
          if (LONG_800b2e64 == -1) goto switchD_80073900_caseD_2;
          Task_Next();
        }
      } while (LONG_800b2e64 != -1);
      monst->actionmask = 0;
      break;
    case 0x1e:
      MSpell_SpellTesting(monst,TaskCurrent->event_param,-1,5);
    default:
switchD_80073900_caseD_2:
      monst->actionmask = 0;
    }
    monst->busy = -1;
    Task_Next();
    if (monst->mode == 0x11) {
      Monster_ReleaseBonuses();
      TaskCurrent->event_enable = 0;
      D3_ClearCollBits(o,8);
      do {
        AnimNr = Boxes_GetHeight(o,(char)o + ',',
                                 (short)(((uint)(ushort)monst->height + 200) * 0x10000 >> 0x10));
        if (AnimNr != (int)(o->pos).vz) {
          (o->pos).vz = (short)AnimNr;
        }
        Task_Next();
      } while( true );
    }
    Monster_ForceAction(monst,1,0);
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Soldier_Gunner_Func_Reflex()
 // line 1174, offset 0x80073d5c
	/* begin block 1 */
		// Start line: 1175
		// Start offset: 0x80073D5C
		// Variables:
	// 		struct _MONSTER *monst; // $s0
	// 		long tmp; // $s1
	/* end block 1 */
	// End offset: 0x80073E78
	// End Line: 1210

	/* begin block 2 */
		// Start line: 2801
	/* end block 2 */
	// End Line: 2802

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Soldier_Gunner_Func_Reflex(void)

{
  long lVar1;
  _MONSTER *monst;
  int unaff_s1;
  
  monst = (_MONSTER *)TaskCurrent->local;
  if ((LONG_800b2e20 != -1) || (LONG_800b2e1c != -1)) {
    if (Pvl_Difficulty == 1) {
      unaff_s1 = 3;
    }
    else {
      if (Pvl_Difficulty < 2) {
        if (Pvl_Difficulty == 0) {
          unaff_s1 = 4;
        }
      }
      else {
        if (Pvl_Difficulty == 2) {
          unaff_s1 = 2;
        }
      }
    }
    lVar1 = M_rand();
    if (unaff_s1 == 0) {
      trap(0x1c00);
    }
    if ((unaff_s1 == -1) && (lVar1 == -0x80000000)) {
      trap(0x1800);
    }
    if (lVar1 % unaff_s1 == 0) {
      monst->timer = monst->timer + 1;
      Monster_ResetActions(monst);
      Monster_AddAction(monst,0,8,1,0);
    }
  }
  lVar1 = Monster_Reflex_Fear(monst);
  if (lVar1 == 0) {
    Monster_ReflexCombat(monst,0x82,monst->timer_agression);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Soldier_Gunner_Task_Action()
 // line 1213, offset 0x80073e8c
	/* begin block 1 */
		// Start line: 1214
		// Start offset: 0x80073E8C
		// Variables:
	// 		struct _MONSTER *monst; // $s2
	// 		struct _D3_OBJECT *o; // $s3
	// 		struct M_OBJECT *mo; // $s4
	// 		long i; // $s0
	// 		long missing; // $s1
	/* end block 1 */
	// End offset: 0x80074444
	// End Line: 1322

	/* begin block 2 */
		// Start line: 2887
	/* end block 2 */
	// End Line: 2888

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Soldier_Gunner_Task_Action(void)

{
  ushort uVar1;
  TASK *pTVar2;
  long local_48;
  uint missing;
  _ENEMYZONE *p_Var3;
  short sVar4;
  int iVar5;
  _MONSTER *monst;
  _D3_OBJECT *o;
  M_OBJECT *obj;
  
  monst = (_MONSTER *)TaskCurrent->local;
  o = monst->obj;
  obj = (M_OBJECT *)o->description;
  monst->hurtsound = 2;
  monst->fleesound = 1;
  local_48 = Task_EventWait();
  pTVar2 = TaskCurrent;
  monst->action = (short)local_48;
  pTVar2->event_enable = 1;
  Monster_Action_SetBoundingBox(0,(int)monst->height);
  (o->rot).vx = 0;
  (o->rot).vy = 0;
  do {
    switch((int)(((uint)(ushort)monst->action - 1) * 0x10000) >> 0x10) {
    case 0:
      Monster_Action_WaitRun(monst,0,1,100,1,4);
      monst->actionmask = 0;
      break;
    case 1:
      Monster_Action_Hit(8,9,0,0);
      TaskCurrent->event_enable = 1;
    default:
      goto switchD_80073f40_caseD_2;
    case 4:
      if ((o[1].pos.vz & 0x200U) != 0) goto switchD_80073f40_caseD_2;
      iVar5 = 0;
      if (0 < (int)Pvl_LevelNumber * -5 + 0x28) {
        do {
          iVar5 = iVar5 + 1;
          Task_Next();
        } while (iVar5 < (int)Pvl_LevelNumber * -5 + 0x28);
      }
      Monster_Action_MoveTo(0,0,0,(_D3_OBJECT *)Monster_Feelings,100,2,1,-1,-1,-1,8);
      monst->actionmask = 0;
      break;
    case 7:
      missing = 0;
      if ((o[1].pos.vz & 0x100U) != 0) {
        missing = (uint)(monst->timer_agression != 0);
      }
      uVar1 = o->collision_state;
      sVar4 = 0;
      while ((uVar1 & 0x4000) == 0) {
        sVar4 = sVar4 + -5;
        (o->pos).vz = (o->pos).vz + sVar4;
        Task_Next();
        uVar1 = o->collision_state;
      }
      Manim_SetAnim(obj,5);
      Manim_WaitAnim(obj);
      Monster_Action_SetBoundingBox(1,(int)monst->height);
      if ((o[1].pos.vz & 0x800U) == 0) {
        local_48 = 2;
      }
      else {
        local_48 = 4;
      }
      Monster_Action_Shooting(-1,-1,6,1,local_48,0x96,missing,monst->timer_agression,3);
      Monster_Action_SetBoundingBox(0,(int)monst->height);
      Manim_SetAnim(obj,7);
      Manim_WaitAnim(obj);
      monst->actionmask = 0;
      break;
    case 10:
      Manim_SetAnim(obj,0);
      while (local_48 = D3_GoToDir(o,(int)*(short *)(Monster_Feelings + 0x2c) - (int)(o->pos).vx,
                                   (int)*(short *)(Monster_Feelings + 0x2e) - (int)(o->pos).vy,0xa0)
            , local_48 != 0) {
        Task_Next();
      }
      iVar5 = 0;
      Monster_Action_Slaying(10,0x8c,(_D3_OBJECT *)Monster_Feelings,-1);
      Manim_SetAnim(obj,0);
      while (missing = M_rand(), iVar5 < (int)((missing & 0xf) + (monst->timer_agression >> 1))) {
        iVar5 = iVar5 + 1;
        Task_Next();
      }
      goto switchD_80073f40_caseD_2;
    case 0xb:
      iVar5 = 0;
      while (missing = M_rand(), iVar5 < (int)(missing & 7)) {
        iVar5 = iVar5 + 1;
        Task_Next();
      }
      uVar1 = o[1].pos.vz;
      missing = 0;
      if ((uVar1 & 0x100) != 0) {
        missing = (uint)(monst->timer_agression != 0);
      }
      if ((uVar1 & 0x800) == 0) {
        local_48 = 2;
      }
      else {
        local_48 = 4;
      }
      Monster_Action_Shooting(2,4,3,1,local_48,200,missing,monst->timer_agression,3);
      monst->actionmask = 0;
      break;
    case 0x14:
      Monster_Action_Flee(monst,1,0,8);
switchD_80073f40_caseD_2:
      monst->actionmask = 0;
      break;
    case 0x1d:
      TaskCurrent->event_enable = 0;
      D3_PlaySound(o,1);
      p_Var3 = Pvl_EnemyZones + (int)monst->zone_fear;
      Monster_Action_MoveTo
                ((int)p_Var3->x1 + (int)p_Var3->x2 >> 1,(int)p_Var3->y1 + (int)p_Var3->y2 >> 1,
                 (int)p_Var3->z1 + (int)p_Var3->z2 >> 1,(_D3_OBJECT *)0x0,100,2,1,-1,-1,-1,8);
      local_48 = Monster_FearFindFriends(monst);
      if (local_48 != 0) {
        MSensor_AddFear(monst,-100);
      }
      TaskCurrent->event_enable = 1;
      if (LONG_800b2e64 == -1) goto switchD_80073f40_caseD_2;
      do {
        Manim_ForceAnim(obj,0);
        while (((obj->Env).Obj.normal_top.vx & 0x4000U) == 0) {
          if (LONG_800b2e64 == -1) goto switchD_80073f40_caseD_2;
          Monster_Action_FollowObject((_D3_OBJECT *)Monster_Feelings,0);
          Task_Next();
        }
      } while (LONG_800b2e64 != -1);
      monst->actionmask = 0;
      break;
    case 0x1e:
      MSpell_SpellTesting(monst,TaskCurrent->event_param,1,0);
      monst->actionmask = 0;
    }
    monst->busy = -1;
    Task_Next();
    if (monst->mode == 0x11) {
      Monster_ReleaseBonuses();
      return;
    }
    Monster_ForceAction(monst,1,0);
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Soldier_Grenade_Func_Reflex()
 // line 1356, offset 0x80074478
	/* begin block 1 */
		// Start line: 1357
		// Start offset: 0x80074478
		// Variables:
	// 		struct _MONSTER *monst; // $s0
	// 		long tmp; // $s1
	/* end block 1 */
	// End offset: 0x800745D4
	// End Line: 1391

	/* begin block 2 */
		// Start line: 3232
	/* end block 2 */
	// End Line: 3233

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Soldier_Grenade_Func_Reflex(void)

{
  long lVar1;
  _MONSTER *monst;
  int unaff_s1;
  
  monst = (_MONSTER *)TaskCurrent->local;
  lVar1 = Monster_Reflex_Fear(monst);
  if (lVar1 == 0) {
    if ((LONG_800b2e20 != -1) || (LONG_800b2e1c != -1)) {
      if (Pvl_Difficulty == 1) {
        unaff_s1 = 3;
      }
      else {
        if (Pvl_Difficulty < 2) {
          if (Pvl_Difficulty == 0) {
            unaff_s1 = 4;
          }
        }
        else {
          if (Pvl_Difficulty == 2) {
            unaff_s1 = 2;
          }
        }
      }
      lVar1 = M_rand();
      if (unaff_s1 == 0) {
        trap(0x1c00);
      }
      if ((unaff_s1 == -1) && (lVar1 == -0x80000000)) {
        trap(0x1800);
      }
      if (lVar1 % unaff_s1 == 0) {
        monst->timer = monst->timer + 1;
        Monster_ResetActions(monst);
        Monster_AddAction(monst,0,8,0,0);
        if (1999 < LONG_ARRAY_800b2e40[0]) {
          return;
        }
        if (LONG_ARRAY_800b2e40[0] == -1) {
          return;
        }
        Monster_AddAction(monst,0,0xc,0,0);
        return;
      }
    }
    Monster_ReflexCombat(monst,0x96,monst->timer_agression);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Soldier_Grenade_Task_Action()
 // line 1394, offset 0x800745e8
	/* begin block 1 */
		// Start line: 1395
		// Start offset: 0x800745E8
		// Variables:
	// 		struct _MONSTER *monst; // $s1
	// 		struct _D3_OBJECT *o; // $s3
	// 		struct M_OBJECT *mo; // $s5
	// 		long i; // $s0
	/* end block 1 */
	// End offset: 0x80074978
	// End Line: 1452

	/* begin block 2 */
		// Start line: 3309
	/* end block 2 */
	// End Line: 3310

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Soldier_Grenade_Task_Action(void)

{
  TASK *pTVar1;
  long Anim;
  uint uVar2;
  int iVar3;
  _MONSTER *monst;
  _D3_OBJECT *o;
  M_OBJECT *obj;
  
  monst = (_MONSTER *)TaskCurrent->local;
  o = monst->obj;
  obj = (M_OBJECT *)o->description;
  monst->hurtsound = 2;
  monst->fleesound = 1;
  monst->monster_speed = 200;
  Anim = Task_EventWait();
  pTVar1 = TaskCurrent;
  monst->action = (short)Anim;
  pTVar1->event_enable = 1;
  do {
    switch((int)(((uint)(ushort)monst->action - 1) * 0x10000) >> 0x10) {
    case 0:
      Monster_Action_WaitRun(monst,1,3,100,1,7);
      monst->actionmask = 0;
      break;
    case 1:
      Monster_Action_Hit(8,2,1,0);
      monst->actionmask = 0;
      break;
    default:
      goto switchD_80074688_caseD_2;
    case 4:
switchD_80074688_caseD_4:
      if ((o[1].pos.vz & 0x200U) == 0) {
        iVar3 = 0;
        if (0 < (int)Pvl_LevelNumber * -5 + 0x28) {
          do {
            iVar3 = iVar3 + 1;
            Task_Next();
          } while (iVar3 < (int)Pvl_LevelNumber * -5 + 0x28);
        }
        Monster_Action_MoveTo(0,0,0,(_D3_OBJECT *)Monster_Feelings,0x6e,-1,3,-1,-1,-1,-1);
        Manim_SetAnim(obj,1);
        iVar3 = 0;
        if (0 < monst->timer_agression) {
          do {
            iVar3 = iVar3 + 1;
            Task_Next();
          } while (iVar3 < monst->timer_agression);
          monst->actionmask = 0;
          break;
        }
      }
      goto switchD_80074688_caseD_2;
    case 7:
      Monster_Action_Protect(1,10,4,5,0,0,-1);
      monst->actionmask = 0;
      break;
    case 10:
      while (Anim = D3_GoToDir(o,(int)*(short *)(Monster_Feelings + 0x2c) - (int)(o->pos).vx,
                               (int)*(short *)(Monster_Feelings + 0x2e) - (int)(o->pos).vy,0xa0),
            Anim != 0) {
        Task_Next();
      }
      D3_PlaySound(o,5);
      uVar2 = M_rand();
      Anim = 6;
      if ((uVar2 & 1) != 0) {
        Anim = 7;
      }
      Monster_Action_Slaying(Anim,200,(_D3_OBJECT *)Monster_Feelings,-1);
      Manim_SetAnim(obj,1);
      iVar3 = 0;
      if (monst->timer_agression >> 1 < 1) goto switchD_80074688_caseD_2;
      do {
        iVar3 = iVar3 + 1;
        Task_Next();
      } while (iVar3 < monst->timer_agression >> 1);
      monst->actionmask = 0;
      break;
    case 0xb:
      Monster_Action_Shooting(-1,-1,0,0x15,1,200,0,monst->timer_agression,6);
      if (LONG_ARRAY_800b2e2c[0] != -1) goto switchD_80074688_caseD_4;
      goto switchD_80074688_caseD_2;
    case 0x14:
      Monster_Action_Flee(monst,3,1,-1);
switchD_80074688_caseD_2:
      monst->actionmask = 0;
      break;
    case 0x1d:
      Monster_Action_Fear(monst,1,3,100,1);
      monst->actionmask = 0;
      break;
    case 0x1e:
      MSpell_SpellTesting(monst,TaskCurrent->event_param,3,1);
      monst->actionmask = 0;
    }
    monst->busy = -1;
    Task_Next();
    if (monst->mode == 0x11) {
      Monster_ReleaseBonuses();
      return;
    }
    Monster_ForceAction(monst,1,0);
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Soldier_Gremit_Task_Action()
 // line 1483, offset 0x800749a8
	/* begin block 1 */
		// Start line: 1484
		// Start offset: 0x800749A8
		// Variables:
	// 		struct _MONSTER *monst; // $s1
	// 		struct _D3_OBJECT *o; // $s2
	// 		struct _D3_OBJECT *tmpobj; // $v0
	// 		struct M_OBJECT *mo; // $s5
	// 		long missing; // $t0
	// 		long i; // $s0
	/* end block 1 */
	// End offset: 0x80074DB8
	// End Line: 1569

	/* begin block 2 */
		// Start line: 3507
	/* end block 2 */
	// End Line: 3508

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Soldier_Gremit_Task_Action(void)

{
  ushort uVar1;
  TASK *pTVar2;
  long Sound;
  long waiter;
  int iVar3;
  long AnimStart;
  long AnimStop;
  long AnimShoot;
  long ShootType;
  _MONSTER *monst;
  _D3_OBJECT *o;
  M_OBJECT *obj;
  long local_40;
  uint local_38;
  
  monst = (_MONSTER *)TaskCurrent->local;
  o = monst->obj;
  obj = (M_OBJECT *)o->description;
  monst->hurtsound = 2;
  monst->monster_speed = 200;
  monst->fleesound = 1;
  monst->monster_trans = 0xc0;
  Sound = Task_EventWait();
  pTVar2 = TaskCurrent;
  monst->action = (short)Sound;
  pTVar2->event_enable = 1;
  Monster_Action_SetBoundingBox(0,(int)monst->height);
  (o->rot).vx = 0;
  (o->rot).vy = 0;
  do {
    switch((int)(((uint)(ushort)monst->action - 1) * 0x10000) >> 0x10) {
    case 0:
      Monster_Action_WaitRun(monst,1,3,100,1,7);
      monst->actionmask = 0;
      break;
    case 1:
      Monster_Action_Hit(10,2,1,0);
      monst->actionmask = 0;
      break;
    default:
      goto switchD_80074a60_caseD_2;
    case 4:
      if ((o[1].pos.vz & 0x200U) == 0) {
        Monster_Action_MoveTo(0,0,0,(_D3_OBJECT *)Monster_Feelings,0x6e,-1,3,-1,0xc,0xb,-1);
        Manim_SetAnim(obj,1);
        iVar3 = 0;
        if (0 < monst->timer_agression) {
          do {
            iVar3 = iVar3 + 1;
            Task_Next();
          } while (iVar3 < monst->timer_agression);
          monst->actionmask = 0;
          break;
        }
      }
      goto switchD_80074a60_caseD_2;
    case 7:
      Monster_Action_Protect(0,10,4,5,7,6,3);
      monst->actionmask = 0;
      break;
    case 10:
      while (Sound = D3_GoToDir(o,(int)*(short *)(Monster_Feelings + 0x2c) - (int)(o->pos).vx,
                                (int)*(short *)(Monster_Feelings + 0x2e) - (int)(o->pos).vy,0xa0),
            Sound != 0) {
        Task_Next();
      }
      D3_PlaySound(o,5);
      local_38 = M_rand();
      Sound = 8;
      if ((local_38 & 1) != 0) {
        Sound = 9;
      }
      Monster_Action_Slaying(Sound,200,(_D3_OBJECT *)Monster_Feelings,-1);
      Manim_SetAnim(obj,1);
      iVar3 = 0;
      if (LONG_800b2e28 == -1) {
        while (local_38 = M_rand(), iVar3 < (int)((local_38 & 0xf) + (monst->timer_agression >> 1)))
        {
          iVar3 = iVar3 + 1;
          Task_Next();
        }
      }
      goto switchD_80074a60_caseD_2;
    case 0xb:
      if (Monster_Feelings == 0) goto switchD_80074a60_caseD_2;
      iVar3 = (int)(o->pos).vz;
      if ((iVar3 + 0x96 < (int)*(short *)(Monster_Feelings + 0x30)) ||
         ((int)*(short *)(Monster_Feelings + 0x30) < iVar3 + -0x96)) {
        AnimStart = -1;
        AnimStop = -1;
        AnimShoot = 0;
        ShootType = 0x15;
        local_40 = 1;
        local_38 = 0;
        waiter = monst->timer_agression;
        Sound = 6;
      }
      else {
        uVar1 = o[1].pos.vz;
        local_38 = 0;
        if ((uVar1 & 0x100) != 0) {
          local_38 = (uint)(monst->timer_agression != 0);
        }
        AnimStart = 0xd;
        if ((uVar1 & 0x800) == 0) {
          local_40 = 1;
        }
        else {
          local_40 = 2;
        }
        ShootType = 3;
        AnimShoot = 0xe;
        AnimStop = 0xf;
        waiter = monst->timer_agression;
        Sound = 4;
      }
      Monster_Action_Shooting
                (AnimStart,AnimStop,AnimShoot,ShootType,local_40,200,local_38,waiter,Sound);
      monst->actionmask = 0;
      break;
    case 0x14:
      Monster_Action_Flee(monst,3,1,-1);
switchD_80074a60_caseD_2:
      monst->actionmask = 0;
      break;
    case 0x1d:
      Monster_Action_Fear(monst,1,3,100,1);
      monst->actionmask = 0;
      break;
    case 0x1e:
      MSpell_SpellTesting(monst,TaskCurrent->event_param,-1,3);
      monst->actionmask = 0;
    }
    monst->busy = -1;
    Task_Next();
    if (monst->mode == 0x11) {
      Monster_ReleaseBonuses();
      return;
    }
    Monster_ForceAction(monst,1,0);
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Soudeur_RIP(struct M_OBJECT *mo /*$s1*/, struct _D3_OBJECT *o /*$s2*/)
 // line 1597, offset 0x80074de4
	/* begin block 1 */
		// Start line: 1598
		// Start offset: 0x80074DE4
		// Variables:
	// 		struct M_OBJECT *mochild; // $s0
	// 		struct ENEMY_7fake pos; // stack offset -32
	// 		long i; // $s0
	/* end block 1 */
	// End offset: 0x80074F38
	// End Line: 1634

	/* begin block 2 */
		// Start line: 3769
	/* end block 2 */
	// End Line: 3770

void Soudeur_RIP(M_OBJECT *mo,_D3_OBJECT *o)

{
  ushort uVar1;
  void *pvVar2;
  int iVar3;
  
  pvVar2 = o->child->description;
  Manim_SetAnim(mo,0);
  *(ushort *)((int)pvVar2 + 0x28) = *(ushort *)((int)pvVar2 + 0x28) & 0xfffe;
  o->child->display_mode = o->child->display_mode & 0xffef;
  uVar1 = (mo->Env).Obj.normal_top.vx;
  iVar3 = 0;
  while ((uVar1 & 0x4000) == 0) {
    if (iVar3 == 0xf) {
      iVar3 = 0;
      Impact_Sparks(0xe0,6);
    }
    iVar3 = iVar3 + 1;
    Task_Next();
    uVar1 = (mo->Env).Obj.normal_top.vx;
  }
  Manim_SetAnim(mo,1);
  uVar1 = (mo->Env).Obj.normal_top.vx;
  while ((uVar1 & 0x4000) == 0) {
    if (iVar3 == 0xf) {
      iVar3 = 0;
      Impact_Sparks(0xe0,3);
    }
    iVar3 = iVar3 + 1;
    Task_Next();
    uVar1 = (mo->Env).Obj.normal_top.vx;
  }
  (mo->Env).Obj.normal_top.vx = (mo->Env).Obj.normal_top.vx & 0xfffe;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Soldier_Soudeur_Init()
 // line 1637, offset 0x80074f64
	/* begin block 1 */
		// Start line: 1638
		// Start offset: 0x80074F64
		// Variables:
	// 		struct _MONSTER *monst; // $s0
	// 		struct _D3_OBJECT *obj; // $s1
	// 		struct M_OBJECT *mo; // $v1
	/* end block 1 */
	// End offset: 0x80074F64
	// End Line: 1638

	/* begin block 2 */
		// Start line: 3849
	/* end block 2 */
	// End Line: 3850

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Soldier_Soudeur_Init(void)

{
  void *pvVar1;
  _D3_OBJECT *p_Var2;
  _D3_OBJECT *o;
  
  p_Var2 = (_D3_OBJECT *)TaskCurrent->local;
  o = p_Var2->next;
  D3_SetBox(o,-0x3c,-0x3c,0,0x3c,0x3c,300);
  *(undefined2 *)((int)(p_Var2 + 2) + 0x4e) = 0x40;
  *(undefined2 *)((int)(p_Var2 + 2) + 0x14) = 0xe6;
  *(undefined2 *)((int)(p_Var2 + 2) + 0x16) = 0xff9b;
  *(undefined2 *)((int)(p_Var2 + 2) + 0x18) = 0xbe;
  *(undefined2 *)((int)(p_Var2 + 2) + 0x1a) = 0;
  *(short *)((int)(p_Var2 + 2) + 0x20) = *(short *)((int)(p_Var2 + 2) + 0x20) << 1;
  pvVar1 = o->child->description;
  *(ushort *)((int)pvVar1 + 0x28) = *(ushort *)((int)pvVar1 + 0x28) & 0xfffe;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Soldier_Soudeur_Func_Reflex()
 // line 1658, offset 0x80075010
	/* begin block 1 */
		// Start line: 1659
		// Start offset: 0x80075010
		// Variables:
	// 		struct _MONSTER *monst; // $s1
	// 		struct _D3_OBJECT *o; // $a0
	// 		struct M_OBJECT *mo; // $a1
	// 		struct M_OBJECT *mochild; // $s0
	// 		long tmp; // $v0
	/* end block 1 */
	// End offset: 0x80075270
	// End Line: 1709

	/* begin block 2 */
		// Start line: 3909
	/* end block 2 */
	// End Line: 3910

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Soldier_Soudeur_Func_Reflex(void)

{
  undefined2 uVar1;
  short sVar2;
  ushort uVar3;
  _D3_OBJECT *p_Var4;
  int iVar5;
  int iVar6;
  _D3_OBJECT *p_Var7;
  void *pvVar8;
  undefined4 uVar9;
  void *pvVar10;
  _MONSTER *monst;
  
  monst = (_MONSTER *)TaskCurrent->local;
  p_Var7 = monst->obj;
  p_Var4 = p_Var7->child;
  pvVar8 = p_Var7->description;
  pvVar10 = p_Var4->description;
  uVar9 = *(undefined4 *)&(p_Var7->pos).vz;
  *(undefined4 *)&p_Var4->last_pos = *(undefined4 *)&p_Var7->pos;
  *(undefined4 *)&(p_Var4->last_pos).vz = uVar9;
  uVar9 = *(undefined4 *)&(p_Var4->last_pos).vz;
  *(undefined4 *)&p_Var4->pos = *(undefined4 *)&p_Var4->last_pos;
  *(undefined4 *)&(p_Var4->pos).vz = uVar9;
  sVar2 = monst->action;
  if ((sVar2 == 5) && ((monst->flags & 0x200U) != 0)) {
    p_Var4 = p_Var7->child;
    uVar9 = *(undefined4 *)&(p_Var7->rot).vz;
    *(undefined4 *)&p_Var4->rot = *(undefined4 *)&p_Var7->rot;
    *(undefined4 *)&(p_Var4->rot).vz = uVar9;
    uVar1 = 4;
code_r0x80075114:
    *(undefined2 *)((int)pvVar10 + 0x16) = uVar1;
    *(undefined2 *)((int)pvVar10 + 0x18) = *(undefined2 *)((int)pvVar8 + 0x18);
  }
  else {
    if ((sVar2 == 1) || (sVar2 == 5)) {
      p_Var4 = p_Var7->child;
      uVar9 = *(undefined4 *)&(p_Var7->rot).vz;
      *(undefined4 *)&p_Var4->rot = *(undefined4 *)&p_Var7->rot;
      *(undefined4 *)&(p_Var4->rot).vz = uVar9;
      uVar1 = *(undefined2 *)((int)pvVar8 + 0x16);
      goto code_r0x80075114;
    }
  }
  Monster_ReflexCombat(monst,0xb4,monst->timer_agression);
  if ((monst->flags & 0x200U) == 0) {
    return;
  }
  *(ushort *)((int)pvVar10 + 0x28) = *(ushort *)((int)pvVar10 + 0x28) | 4;
  if ((monst->flags & 0x20U) == 0) {
    sVar2 = (monst->eff_pos).pad + -0x14;
    (monst->eff_pos).pad = sVar2;
    if (-0x81 < sVar2) goto LAB_800751d0;
    uVar3 = monst->flags | 0x20;
  }
  else {
    sVar2 = (monst->eff_pos).pad + 0x14;
    (monst->eff_pos).pad = sVar2;
    if (sVar2 < 0x201) goto LAB_800751d0;
    uVar3 = monst->flags & 0xffdf;
  }
  monst->flags = uVar3;
LAB_800751d0:
  *(short *)((int)pvVar10 + 0x26) = (monst->eff_pos).pad;
  iVar5 = rcos((int)(monst->eff_pos).pad);
  iVar6 = rsin((int)(monst->eff_pos).pad);
  (monst->eff_pos).vx = (short)(iVar5 * 0xe4 + iVar6 * 0x2d >> 0xc) + -10;
  iVar5 = rsin((int)(monst->eff_pos).pad);
  iVar6 = rcos((int)(monst->eff_pos).pad);
  (monst->eff_pos).vy = (short)(iVar5 * 0xe4 + iVar6 * -0x2d >> 0xc) + -0x3c;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Soldier_Soudeur_Task_Action()
 // line 1713, offset 0x80075284
	/* begin block 1 */
		// Start line: 1714
		// Start offset: 0x80075284
		// Variables:
	// 		struct _MONSTER *monst; // $s1
	// 		struct _D3_OBJECT *o; // $s0
	// 		struct M_OBJECT *mo; // $s3
	// 		struct ENEMY_7fake pos; // stack offset -32
	// 		long x; // $s0
	// 		long y; // $a1
	/* end block 1 */
	// End offset: 0x8007564C
	// End Line: 1792

	/* begin block 2 */
		// Start line: 4022
	/* end block 2 */
	// End Line: 4023

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Soldier_Soudeur_Task_Action(void)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  TASK *pTVar5;
  long lVar6;
  uint uVar7;
  _ENEMYZONE *p_Var8;
  void *pvVar9;
  _D3_OBJECT *o;
  int zz;
  _D3_OBJECT *o_00;
  _MONSTER *monst;
  M_OBJECT *mo;
  
  monst = (_MONSTER *)TaskCurrent->local;
  o_00 = monst->obj;
  mo = (M_OBJECT *)o_00->description;
  lVar6 = Task_EventWait();
  pTVar5 = TaskCurrent;
  monst->action = (short)lVar6;
  pTVar5->event_enable = 1;
  do {
    switch((int)(((uint)(ushort)monst->action - 1) * 0x10000) >> 0x10) {
    case 0:
      monst->busy = 0;
      monst->mode = 0x10;
      do {
        uVar7 = M_rand();
        if ((uVar7 & 1) == 0) {
          sVar1 = monst->zone_wait->x2;
        }
        else {
          sVar1 = monst->zone_wait->x1;
        }
        sVar2 = monst->zone_wait->x1;
        sVar3 = monst->zone_wait->x2;
        uVar7 = M_rand();
        if ((uVar7 & 1) == 0) {
          sVar4 = monst->zone_wait->y2;
          p_Var8 = monst->zone_wait;
        }
        else {
          p_Var8 = monst->zone_wait;
          sVar4 = p_Var8->y1;
        }
        zz = (int)p_Var8->y1 + (int)p_Var8->y2 >> 1;
        Monster_Action_MoveTo
                  ((int)sVar1 + ((int)sVar2 + (int)sVar3 >> 1) >> 1,(int)sVar4 + zz >> 1,zz,
                   (_D3_OBJECT *)0x0,100,-1,0,-1,-1,-1,-1);
        Task_Next();
      } while( true );
    case 1:
      lVar6 = Monster_Action_Hit(-1,-1,1,-1);
      if (lVar6 == 0) goto switchD_80075308_caseD_2;
      monst->sensormask = 0x88000001;
      D3_ClearCollBits(o_00,(long)&DAT_00004011);
      SFX_AddExplosion(o_00->child,0,0);
      D3_PlaySound(o_00,0);
      Soudeur_RIP(mo,o_00);
      monst->actionmask = 0;
      break;
    default:
      goto switchD_80075308_caseD_2;
    case 4:
      Monster_Action_MoveTo(0,0,0,(_D3_OBJECT *)Monster_Feelings,0x8c,-1,0,-1,-1,-1,-1);
      monst->actionmask = 0;
      break;
    case 6:
      (mo->Env).Obj.normal_top.vx = (mo->Env).Obj.normal_top.vx & 0xfffe;
      pvVar9 = o_00->child->description;
      *(ushort *)((int)pvVar9 + 0x28) = *(ushort *)((int)pvVar9 + 0x28) & 0xfffe;
      monst->mode = 7;
      while( true ) {
        o = o_00->child;
        lVar6 = D3_GoToDir(o,(int)*(short *)((int)&TaskCurrent->event_param + 2) - (int)(o->pos).vx,
                           (int)*(short *)&TaskCurrent->event_param - (int)(o->pos).vy,0x50);
        if (lVar6 == 0) break;
        D3_PlaySound(o_00,4);
        Task_Next();
      }
      goto switchD_80075308_caseD_2;
    case 10:
      (mo->Env).Obj.normal_top.vx = (mo->Env).Obj.normal_top.vx & 0xfffe;
      Monster_Action_SlayingObject(o_00->child,3,0xdc,(_D3_OBJECT *)Monster_Feelings,monst,1);
      monst->actionmask = 0;
      break;
    case 0xb:
      monst->mode = 7;
      monst->flags = monst->flags | 0x200;
      D3_PlaySound(o_00,3);
      Shoot_Add(o_00,0xe0,(char)o_00 + '<',0,6,0x21,5,0);
      monst->actionmask = 0;
      break;
    case 0x1d:
      lVar6 = Monster_FearFindFriends(monst);
      if (lVar6 == 0) goto switchD_80075308_caseD_2;
      MSensor_AddFear(monst,-0xfa);
      monst->actionmask = 0;
      break;
    case 0x1e:
      MSpell_SpellTesting(monst,TaskCurrent->event_param,-1,-1);
switchD_80075308_caseD_2:
      monst->actionmask = 0;
    }
    monst->busy = -1;
    Task_Next();
    if (monst->mode == 0x11) {
      Monster_ReleaseBonuses();
      return;
    }
    Monster_ForceAction(monst,1,0);
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Soldier_RobNail_Init()
 // line 1810, offset 0x80075670
	/* begin block 1 */
		// Start line: 1811
		// Start offset: 0x80075670
		// Variables:
	// 		struct _MONSTER *monst; // $s0
	// 		struct _D3_OBJECT *o; // $s1
	// 		struct M_OBJECT *mo; // $s2
	/* end block 1 */
	// End offset: 0x80075670
	// End Line: 1811

	/* begin block 2 */
		// Start line: 4231
	/* end block 2 */
	// End Line: 4232

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Soldier_RobNail_Init(void)

{
  _D3_OBJECT *p_Var1;
  _D3_OBJECT *o;
  void *pvVar2;
  
  p_Var1 = (_D3_OBJECT *)TaskCurrent->local;
  o = p_Var1->next;
  pvVar2 = o->description;
  D3_SetBox(o,-0x32,-0x32,0,0x32,0x32,200);
  *(_D3_OBJECT **)((int)(p_Var1 + 2) + 0x58) = (_D3_OBJECT *)o->color;
  *(undefined2 *)((int)pvVar2 + 0x26) = 0;
  *(undefined2 *)((int)pvVar2 + 0x24) = 0;
  *(undefined2 *)((int)(p_Var1 + 2) + 0x48) = 100;
  *(undefined2 *)((int)(p_Var1 + 2) + 0x14) = 0xa0;
  *(undefined2 *)((int)(p_Var1 + 2) + 0x4a) = 0;
  *(undefined2 *)((int)(p_Var1 + 2) + 0x16) = 0;
  *(undefined2 *)((int)(p_Var1 + 2) + 0x18) = 0xdc;
  *(undefined2 *)((int)(p_Var1 + 2) + 0x1a) = 0;
  *(ushort *)((int)pvVar2 + 0x28) = *(ushort *)((int)pvVar2 + 0x28) | 4;
  D3_SetCollBits(o,10);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Soldier_RobNail_Func_Reflex()
 // line 1834, offset 0x80075724
	/* begin block 1 */
		// Start line: 1835
		// Start offset: 0x80075724
		// Variables:
	// 		struct ENEMY_7fake pos; // stack offset -32
	// 		struct _MONSTER *monst; // $s0
	// 		struct _D3_OBJECT *o; // $s1
	// 		struct _D3_OBJECT *target; // $s2
	// 		struct M_OBJECT *mo; // $s3
	// 		long z; // $v0
	// 		long x; // $a0
	// 		long y; // $a1
	// 		long tmp; // $a0
	/* end block 1 */
	// End offset: 0x80075BC8
	// End Line: 1954

	/* begin block 2 */
		// Start line: 4314
	/* end block 2 */
	// End Line: 4315

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Soldier_RobNail_Func_Reflex(void)

{
  short sVar1;
  long lVar2;
  uint uVar3;
  short sVar4;
  int iVar5;
  long param1;
  _MONSTER *monst;
  _D3_OBJECT *ot;
  void *pvVar6;
  
  param1 = Monster_Feelings;
  monst = (_MONSTER *)TaskCurrent->local;
  ot = monst->obj;
  pvVar6 = ot->description;
  if (ot->hit_points < 0x1e) {
    ot->color = *(long *)&monst->guninfo1;
    if (0x11 < monst->weapon_timer2) {
      ot->color = 0x6060ff;
    }
    if (monst->weapon_timer2 == 0) {
      ot->color = 0x6060ff;
      M_rand();
      M_rand();
      M_rand();
      Impact_Smoke(0xe0,1);
      monst->weapon_timer2 = 0x14;
    }
    monst->weapon_timer2 = monst->weapon_timer2 + -1;
  }
  *(ushort *)((int)pvVar6 + 0x28) = *(ushort *)((int)pvVar6 + 0x28) & 0xfffe;
  if (2 < (uint)(ushort)monst->mode - 0x32) {
    lVar2 = Boxes_GetHeight(ot,(char)ot + ',',
                            (short)(((uint)(ushort)monst->height + 100) * 0x10000 >> 0x10));
    iVar5 = (int)(ot->pos).vz;
    if ((lVar2 < iVar5 + 200) && (iVar5 + -200 < lVar2)) {
      if (monst->counter < 0x15) {
        sVar4 = monst->weapon_timer1 + (short)lVar2 + *(short *)&monst->counter * 2;
      }
      else {
        sVar4 = (monst->weapon_timer1 + (short)lVar2) - (*(short *)&monst->counter * 2 + -0x50);
      }
      (ot->pos).vz = sVar4;
      iVar5 = monst->counter + 1;
      monst->counter = iVar5;
      if (iVar5 == 0x28) {
        monst->counter = 0;
      }
      sVar4 = (ot->pos).vx;
      sVar1 = (ot->pos).vy;
      (ot->rot).vz = (ot->rot).vz + 0xf;
      lVar2 = Direction((int)*(short *)(param1 + 0x2c) - (int)sVar4,
                        (int)*(short *)(param1 + 0x2e) - (int)sVar1);
      *(short *)((int)pvVar6 + 0x26) = (short)lVar2 - (ot->rot).vz;
    }
    uVar3 = DirectionZ(((int)*(short *)(param1 + 0x2c) +
                       ((int)*(short *)(param1 + 0x4c) + (int)*(short *)(param1 + 0x54) >> 1)) -
                       (int)(ot->pos).vx,
                       ((int)*(short *)(param1 + 0x2e) +
                       ((int)*(short *)(param1 + 0x4e) + (int)*(short *)(param1 + 0x5e) >> 1)) -
                       (int)(ot->pos).vy,
                       ((int)*(short *)(param1 + 0x30) +
                       ((int)*(short *)(param1 + 0x50) + (int)*(short *)(param1 + 0x70) >> 1)) -
                       ((int)(ot->pos).vz + (int)monst->height));
    if (0xc00 < (uVar3 & 0xfff) - 0x200) {
      *(short *)((int)pvVar6 + 0x24) = -(short)(uVar3 & 0xfff);
    }
  }
  if (monst->timer != 0) {
    monst->timer = monst->timer + -1;
  }
  param1 = LONG_ARRAY_800b2e40[0];
  if (LONG_ARRAY_800b2e2c[0] != -1) {
    if (LONG_ARRAY_800b2e40[0] != -1) {
      if (((LONG_ARRAY_800b2e40[0] < 100) &&
          (sVar4 = monst->weapon_timer1 + -4, monst->weapon_timer1 != 0)) ||
         (sVar4 = monst->weapon_timer1 + 4, monst->weapon_timer1 < 100)) {
        monst->weapon_timer1 = sVar4;
      }
      if (param1 < 300) {
        Monster_ResetActions(monst);
        param1 = 0x19;
LAB_80075ab8:
        Monster_AddAction(monst,0,5,param1,5);
      }
      else {
        if (monst->timer == 0) {
          if (param1 < 700) {
            Monster_ResetActions(monst);
            Monster_AddAction(monst,0,0xc,0,0);
            if (monst->timer_agression < 0x2e) {
              monst->timer = 0x2d;
            }
            else {
              monst->timer = *(short *)&monst->timer_agression;
            }
          }
        }
        else {
          if (param1 < 500) {
            Monster_ResetActions(monst);
            param1 = 300;
            goto LAB_80075ab8;
          }
        }
      }
    }
    if (LONG_ARRAY_800b2e2c[0] != -1) goto LAB_80075b7c;
  }
  if (LONG_ARRAY_800b2e40[0] < 2000) {
    if ((monst->timer == 0) && (LONG_ARRAY_800b2e40[0] < 900)) {
      Monster_ResetActions(monst);
      Monster_AddAction(monst,0,0xc,0,0);
      if (monst->timer_agression < 0x2e) {
        monst->timer = 0x2d;
      }
      else {
        monst->timer = *(short *)&monst->timer_agression;
      }
    }
  }
  else {
    if (monst->action != 1) {
      Monster_StopAllActions(monst);
      Monster_AddAction(monst,0,1,0,0);
    }
  }
LAB_80075b7c:
  if ((LONG_ARRAY_800b2e5c[0] != -1) && (Monster_Feelings == LONG_ARRAY_800b2e5c[0])) {
    Monster_StopAllActions(monst);
    Monster_AddAction(monst,0,1,0x3c,0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Soldier_RobNail_Func_Decisions()
 // line 1956, offset 0x80075be4
	/* begin block 1 */
		// Start line: 1957
		// Start offset: 0x80075BE4
		// Variables:
	// 		struct _MONSTER *monst; // $s0
	// 		long dist; // $a0
	/* end block 1 */
	// End offset: 0x80075C60
	// End Line: 1969

	/* begin block 2 */
		// Start line: 4578
	/* end block 2 */
	// End Line: 4579

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Soldier_RobNail_Func_Decisions(void)

{
  _MONSTER *monst;
  
  monst = (_MONSTER *)TaskCurrent->local;
  if ((((monst->obj[1].pos.vz & 0x200U) == 0) && (LONG_ARRAY_800b2e2c[0] != -1)) &&
     (400 < LONG_ARRAY_800b2e40[0])) {
    Monster_StopAllActions(monst);
    Monster_AddAction(monst,0,5,400,0xc);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Soldier_RobNail_Task_Action()
 // line 1971, offset 0x80075c70
	/* begin block 1 */
		// Start line: 1972
		// Start offset: 0x80075C70
		// Variables:
	// 		struct ENEMY_7fake trans; // stack offset -48
	// 		struct _MONSTER *monst; // $s5
	// 		struct _D3_OBJECT *o; // $s6
	// 		long i; // $s0
	/* end block 1 */
	// End offset: 0x80075F04
	// End Line: 2028

	/* begin block 2 */
		// Start line: 4609
	/* end block 2 */
	// End Line: 4610

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Soldier_RobNail_Task_Action(void)

{
  TASK *pTVar1;
  long lVar2;
  char pos;
  char rot;
  int iVar3;
  _MONSTER *monst;
  _D3_OBJECT *o;
  
  monst = (_MONSTER *)TaskCurrent->local;
  o = monst->obj;
  pos = (char)o + ',';
  rot = (char)o + '<';
  SFX_StreamReactor(pos,rot,0xd0);
  SFX_StreamReactor(pos,rot,0xd0);
  SFX_StreamReactor(pos,rot,0xd0);
  lVar2 = Task_EventWait();
  pTVar1 = TaskCurrent;
  monst->action = (short)lVar2;
  pTVar1->event_enable = 1;
  do {
    pTVar1 = TaskCurrent;
    switch((int)(((uint)(ushort)monst->action - 1) * 0x10000) >> 0x10) {
    case 0:
      monst->busy = 1;
      iVar3 = 0;
      pTVar1->event_enable = 0;
      if (0 < pTVar1->event_param) {
        do {
          iVar3 = iVar3 + 1;
          Task_Next();
        } while (iVar3 < TaskCurrent->event_param);
      }
      TaskCurrent->event_enable = 1;
      monst->busy = 0;
      monst->mode = 0x10;
      do {
        Task_Next();
      } while( true );
    case 1:
      lVar2 = Monster_Action_Hit(-1,-1,1,-1);
      if (lVar2 == 0) break;
      monst->mode = 0x11;
      D3_ClearCollBits(o,(long)&DAT_00004011);
      o->display_mode = o->display_mode & 0xffef;
      SFX_AddExplosion(o,0,0);
      SFX_AddExplosion(o,1,0);
      monst->actionmask = 0;
      goto LAB_80075ed0;
    case 4:
      Monster_Action_MoveGlide
                ((_D3_OBJECT *)Monster_Feelings,*(short *)&TaskCurrent->event_param,
                 *(short *)&monst->task_param2,(o->pos).vz,0,0,0);
      monst->actionmask = 0;
      goto LAB_80075ed0;
    case 0xb:
      Monster_Action_Shooting(-1,-1,-1,0x16,1,-1,0,1,-1);
      monst->timer = *(short *)&monst->timer_agression;
      break;
    case 0x1e:
      MSpell_SpellTesting(monst,TaskCurrent->event_param,-1,-2);
    }
    monst->actionmask = 0;
LAB_80075ed0:
    monst->busy = -1;
    Task_Next();
    if (monst->mode == 0x11) {
      Monster_ReleaseBonuses();
      return;
    }
    Monster_ForceAction(monst,1,0);
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Raptor_Small_Func_Reflex()
 // line 2057, offset 0x80075f3c
	/* begin block 1 */
		// Start line: 2058
		// Start offset: 0x80075F3C
		// Variables:
	// 		struct _MONSTER *monst; // $s0
	/* end block 1 */
	// End offset: 0x80075F90
	// End Line: 2068

	/* begin block 2 */
		// Start line: 4826
	/* end block 2 */
	// End Line: 4827

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Raptor_Small_Func_Reflex(void)

{
  long lVar1;
  _MONSTER *monst;
  
  monst = (_MONSTER *)TaskCurrent->local;
  if (monst->timer != 0) {
    monst->timer = monst->timer + -1;
  }
  lVar1 = Monster_Reflex_Fear(monst);
  if (lVar1 == 0) {
    Monster_Reflex_SmallBeastAttack(monst,0xb4);
    Monster_Reflex_Feasting(monst);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Raptor_Small_Task_Action()
 // line 2071, offset 0x80075fa0
	/* begin block 1 */
		// Start line: 2072
		// Start offset: 0x80075FA0
		// Variables:
	// 		char old_resistance[10]; // stack offset -64
	// 		struct ENEMY_7fake pos; // stack offset -48
	// 		struct _MONSTER *monst; // $s0
	// 		struct _D3_OBJECT *o; // $s1
	// 		struct M_OBJECT *mo; // $s3
	// 		long i; // $a0
	// 		long Oldfear; // $fp
	// 		long OldWeight; // $s6
	// 		long Oldhitpoints; // $s5
	// 		long Oldagression; // $s7
	/* end block 1 */
	// End offset: 0x8007643C
	// End Line: 2187

	/* begin block 2 */
		// Start line: 4854
	/* end block 2 */
	// End Line: 4855

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Raptor_Small_Task_Action(void)

{
  uchar *puVar1;
  short sVar2;
  short sVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  TASK *pTVar7;
  long lVar8;
  uchar *puVar9;
  _MONSTER *p_Var10;
  int iVar11;
  int iVar12;
  _MONSTER *monst;
  _D3_OBJECT *o;
  M_OBJECT *obj;
  uchar local_40 [24];
  
  iVar11 = 0;
  monst = (_MONSTER *)TaskCurrent->local;
  uVar4 = monst->fear;
  uVar5 = monst->agression;
  o = monst->obj;
  sVar2 = monst->meatweight;
  obj = (M_OBJECT *)o->description;
  monst->fleesound = 0;
  monst->hurtsound = 2;
  sVar3 = o->hit_points;
  puVar9 = local_40;
  do {
    puVar1 = monst->resistance + iVar11;
    iVar11 = iVar11 + 1;
    *puVar9 = *puVar1;
    puVar9 = local_40 + iVar11;
  } while (iVar11 < 10);
LAB_8007602c:
  if (o->father != (_D3_OBJECT *)0x0) {
    iVar12 = 5;
    iVar11 = (int)&monst->sensormask + 1;
    do {
      *(undefined *)(iVar11 + 0x13c) = 4;
      iVar12 = iVar12 + -1;
      iVar11 = iVar11 + -1;
    } while (-1 < iVar12);
    monst->flags = monst->flags | 0x10;
    D3_ClearCollBits(o,(long)&DAT_00004010);
    uVar6 = monst->flags;
    monst->busy = 1;
    while ((uVar6 & 0x10) != 0) {
      Task_Next();
      uVar6 = monst->flags;
    }
    D3_PlaySound(o,3);
    monst->busy = 0;
    D3_SetCollBits(o,(long)&DAT_00004010);
    iVar11 = 0;
    p_Var10 = monst;
    do {
      puVar9 = local_40 + iVar11;
      iVar11 = iVar11 + 1;
      p_Var10->resistance[0] = *puVar9;
      p_Var10 = (_MONSTER *)((int)&monst->obj + iVar11);
    } while (iVar11 < 10);
    Manim_SetAnim(obj,0);
    Task_Sleep(3);
    D3_PlaySound(o,3);
  }
  pTVar7 = TaskCurrent;
  monst->sensormask = monst->sensormask & 0xefffffff;
  pTVar7->event_enable = 1;
  lVar8 = Task_EventWait();
  monst->action = (short)lVar8;
  do {
    switch((int)(((uint)(ushort)monst->action - 1) * 0x10000) >> 0x10) {
    case 0:
      Monster_Action_WaitRun(monst,0,3,0x32,1,3);
      monst->actionmask = 0;
      break;
    case 1:
      lVar8 = Monster_Action_Hit(8,7,1,1);
      pTVar7 = TaskCurrent;
      if ((lVar8 != 0) && (o->father == (_D3_OBJECT *)0x0)) {
        monst->sensormask = monst->sensormask & 0xfffffff7;
        pTVar7->event_enable = 0;
        monst->mode = 0x10;
        (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
        do {
          Task_Next();
        } while( true );
      }
    default:
switchD_8007615c_caseD_2:
      monst->actionmask = 0;
      break;
    case 4:
      if ((o[1].pos.vz & 0x200U) != 0) goto switchD_8007615c_caseD_2;
      Monster_Action_MoveTo(0,0,0,(_D3_OBJECT *)Monster_Feelings,0x96,-1,3,-1,-1,-1,-1);
      monst->actionmask = 0;
      break;
    case 10:
      monst->mode = 7;
      Monster_Action_SlayDirection(o,9,200,(_D3_OBJECT *)Monster_Feelings,monst,0);
      monst->mode = 1;
      if (((o[1].pos.vz & 0x400U) != 0) || (monst->timer_agression == 0))
      goto switchD_8007615c_caseD_2;
      Manim_SetAnim(obj,0);
      Manim_WaitAnim(obj);
      monst->actionmask = 0;
      break;
    case 0xd:
      Monster_Action_Feast(o,(_D3_OBJECT *)TaskCurrent->event_param,3,1,0xf,-1);
      monst->actionmask = 0;
      break;
    case 0x14:
      Monster_Action_Flee(monst,3,0,-1);
      goto switchD_8007615c_caseD_2;
    case 0x1d:
      Monster_Action_Fear(monst,0,3,100,-1);
      monst->actionmask = 0;
      break;
    case 0x1e:
      MSpell_SpellTesting(monst,TaskCurrent->event_param,-1,0);
      monst->actionmask = 0;
    }
    monst->busy = -1;
    Task_Next();
    if (monst->mode == 0x11) break;
    Monster_ForceAction(monst,1,0);
    Task_Next();
  } while( true );
  if (o->father == (_D3_OBJECT *)0x0) {
    Monster_ReleaseBonuses();
    return;
  }
  (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
  o->hit_points = sVar3;
  o->display_mode = o->display_mode & 0xffef;
  D3_ClearCollBits(o,0xb);
  D3_SetBox(o,(int)(o->b_box).vx,(int)o->comp_opt3,0,(int)*(short *)&o->b_step,(int)(o->b_box).vy,
            (int)monst->height);
  Manim_SetEffect(obj,(TDRFuncPtr_Manim_SetEffect1f)0x0);
  *(undefined *)((int)&o[1].pos.vx + 1) = 0xf3;
  pTVar7 = TaskCurrent;
  monst->sensormask = monst->sensormask | 0x10000008;
  o->color = 0x808080;
  monst->agression = uVar5;
  monst->fear = uVar4;
  monst->meatweight = sVar2;
  monst->actionmask = 0;
  monst->mode = 0;
  monst->busy = 0;
  pTVar7->event_enable = 0;
  goto LAB_8007602c;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Funkie_Func_Reflex()
 // line 2217, offset 0x80076474
	/* begin block 1 */
		// Start line: 2218
		// Start offset: 0x80076474
		// Variables:
	// 		struct _MONSTER *monst; // $s0
	/* end block 1 */
	// End offset: 0x800764B0
	// End Line: 2224

	/* begin block 2 */
		// Start line: 5211
	/* end block 2 */
	// End Line: 5212

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Funkie_Func_Reflex(void)

{
  long lVar1;
  _MONSTER *monst;
  
  monst = (_MONSTER *)TaskCurrent->local;
  lVar1 = Monster_Reflex_Fear(monst);
  if (lVar1 == 0) {
    Monster_Reflex_SmallBeastAttack(monst,0x78);
    Monster_Reflex_Feasting(monst);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Funkie_Task_Action()
 // line 2227, offset 0x800764c0
	/* begin block 1 */
		// Start line: 2228
		// Start offset: 0x800764C0
		// Variables:
	// 		struct _MONSTER *monst; // $s0
	// 		struct _D3_OBJECT *o; // $s1
	// 		struct M_OBJECT *mo; // $s3
	// 		struct ENEMY_7fake pos; // stack offset -40
	// 		long tmp; // $a3
	/* end block 1 */
	// End offset: 0x8007674C
	// End Line: 2286

	/* begin block 2 */
		// Start line: 5232
	/* end block 2 */
	// End Line: 5233

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Funkie_Task_Action(void)

{
  TASK *pTVar1;
  long AnimFeast;
  uint uVar2;
  _MONSTER *monst;
  _D3_OBJECT *o;
  M_OBJECT *obj;
  
  monst = (_MONSTER *)TaskCurrent->local;
  o = monst->obj;
  obj = (M_OBJECT *)o->description;
  monst->hurtsound = 3;
  monst->fleesound = 2;
  monst->monster_speed = 300;
  AnimFeast = Task_EventWait();
  pTVar1 = TaskCurrent;
  monst->action = (short)AnimFeast;
  pTVar1->event_enable = 1;
  do {
    switch((int)(((uint)(ushort)monst->action - 1) * 0x10000) >> 0x10) {
    case 0:
      Monster_Action_WaitRun(monst,0,4,100,0,4);
      monst->actionmask = 0;
      break;
    case 1:
      Monster_Action_Hit(3,3,1,1);
      monst->actionmask = 0;
      break;
    case 4:
      if ((o[1].pos.vz & 0x200U) != 0) goto switchD_80076568_caseD_2;
      Monster_Action_MoveTo(0,0,0,(_D3_OBJECT *)Monster_Feelings,100,-1,4,-1,-1,-1,-1);
      monst->actionmask = 0;
      break;
    case 10:
      monst->mode = 7;
      Monster_Action_SlayDirection(o,5,-200,(_D3_OBJECT *)Monster_Feelings,monst,0);
      monst->mode = 1;
      if (((o[1].pos.vz & 0x400U) != 0) || (monst->timer_agression == 0))
      goto switchD_80076568_caseD_2;
      Manim_SetAnim(obj,0);
      Manim_WaitAnim(obj);
      monst->actionmask = 0;
      break;
    case 0xd:
      uVar2 = M_rand();
      AnimFeast = 2;
      if ((uVar2 & 1) != 0) {
        AnimFeast = 1;
      }
      Monster_Action_Feast(o,(_D3_OBJECT *)TaskCurrent->event_param,4,AnimFeast,2,8);
      monst->actionmask = 0;
      break;
    case 0x14:
      Monster_Action_Flee(monst,4,0,-1);
    default:
switchD_80076568_caseD_2:
      monst->actionmask = 0;
      break;
    case 0x1d:
      Monster_Action_Fear(monst,0,4,100,2);
      monst->actionmask = 0;
      break;
    case 0x1e:
      MSpell_SpellTesting(monst,TaskCurrent->event_param,-1,0);
      monst->actionmask = 0;
    }
    monst->busy = -1;
    Task_Next();
    if (monst->mode == 0x11) {
      Monster_ReleaseBonuses();
      return;
    }
    Monster_ForceAction(monst,1,0);
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Spectre_Func_Reflex()
 // line 2321, offset 0x80076778
	/* begin block 1 */
		// Start line: 2322
		// Start offset: 0x80076778
		// Variables:
	// 		struct _MONSTER *monst; // $s0
	/* end block 1 */
	// End offset: 0x80076874
	// End Line: 2345

	/* begin block 2 */
		// Start line: 5438
	/* end block 2 */
	// End Line: 5439

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Spectre_Func_Reflex(void)

{
  long action;
  _MONSTER *monst;
  
  monst = (_MONSTER *)TaskCurrent->local;
  if (monst->timer != 0) {
    monst->timer = monst->timer + -1;
  }
  if ((LONG_ARRAY_800b2e40[0] < 2000) && (LONG_ARRAY_800b2e40[0] != -1)) {
    if (LONG_ARRAY_800b2e40[0] < 0x96) {
      Monster_StopAllActions(monst);
      action = 0xb;
    }
    else {
      if (0x2ba < LONG_ARRAY_800b2e40[0] - 0x12dU) {
        return;
      }
      if (LONG_800b2e38 == -1) {
        return;
      }
      if (monst->timer != 0) {
        return;
      }
      if (monst->action == 0xc) {
        return;
      }
      if ((monst->obj->collision_state & 0x80U) == 0) {
        return;
      }
      monst->timer = *(short *)&monst->timer_agression;
      Monster_StopAllActions(monst);
      action = 0x14;
    }
    Monster_AddAction(monst,0,action,0,0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Zombie_Func_Reflex()
 // line 2349, offset 0x80076884
	/* begin block 1 */
		// Start line: 2350
		// Start offset: 0x80076884
		// Variables:
	// 		struct _MONSTER *monst; // $a0
	/* end block 1 */
	// End offset: 0x80076884
	// End Line: 2350

	/* begin block 2 */
		// Start line: 5495
	/* end block 2 */
	// End Line: 5496

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Zombie_Func_Reflex(void)

{
  Monster_ReflexCombat
            ((_MONSTER *)TaskCurrent->local,0x96,((_MONSTER *)TaskCurrent->local)->timer_agression);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Zombie_Task_Action()
 // line 2357, offset 0x800768b8
	/* begin block 1 */
		// Start line: 2358
		// Start offset: 0x800768B8
		// Variables:
	// 		struct ENEMY_8fake col; // stack offset -64
	// 		struct _MONSTER *monst; // $s2
	// 		struct _D3_OBJECT *o; // $s1
	// 		struct M_OBJECT *mo; // $s4
	// 		struct TASK *t; // $s3
	// 		long sensorbackup; // $fp
	// 		struct ENEMY_7fake pos; // stack offset -56
	// 		long tmp; // $s0
	// 		long x; // $s3
	// 		long y; // $s7
	// 		long grav; // $s5
	// 		long expos; // stack offset -48
	// 		struct _D3_OBJECT *bonus; // $s6
	/* end block 1 */
	// End offset: 0x80077228
	// End Line: 2625

	/* begin block 2 */
		// Start line: 5513
	/* end block 2 */
	// End Line: 5514

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Zombie_Task_Action(void)

{
  bool bVar1;
  short sVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  _D3_OBJECT *p_Var6;
  long waiter;
  uint uVar7;
  uint uVar8;
  TASK *t;
  long AnimShoot;
  long ShootType;
  _D3_OBJECT *o;
  _MONSTER *monst;
  uint uVar9;
  M_OBJECT *obj;
  short sVar10;
  _D3_OBJECT *o_00;
  long local_5c;
  short local_30;
  
  monst = (_MONSTER *)TaskCurrent->local;
  o = monst->obj;
  obj = (M_OBJECT *)o->description;
  o_00 = (_D3_OBJECT *)0x0;
  if ((((Pvl_LevelNumber == 4) && (Pvl_SectorNumber == 0xb)) && (o->father != (_D3_OBJECT *)0x0)) &&
     (o_00 = o->father->child, o_00 != (_D3_OBJECT *)0x0)) {
    do {
      if (*(char *)((int)&o_00[1].pos.vx + 1) == '\x03') break;
      o_00 = o_00->next;
    } while (o_00 != (_D3_OBJECT *)0x0);
    if (o_00 != (_D3_OBJECT *)0x0) {
      t = o_00->handle;
      local_30 = (o_00->pos).vz;
      (o_00->pos).vz = -0x5dc;
      (o_00->last_pos).vz = -0x5dc;
      Task_EventExec(t,-0x2000,0);
    }
  }
  uVar8 = monst->sensormask;
  monst->hurtsound = 1;
  monst->monster_speed = 0x20;
  monst->sensormask = 1;
  uVar8 = uVar8 & 0xefffffff | 0x8000000;
  if ((monst->flags & 0x40U) == 0) {
    uVar3 = o[1].pos.vy & 0xf;
    if (uVar3 == 6) {
      iVar4 = rcos((int)(o->rot).vz + 0x800);
      iVar5 = rsin((int)(o->rot).vz + 0x800);
      sVar10 = -1;
      D3_ClearCollBits(o,9);
      Manim_SetAnim(obj,1);
      do {
        p_Var6 = Monster_GetChild(o,0x4d2);
        if (p_Var6 == (_D3_OBJECT *)0x0) goto LAB_80076ae8;
        Task_Next();
      } while ((Scts_Interruptors & 0x8000U) == 0);
      (o->pos).vz = (o->pos).vz + -0x32;
      monst->mode = 0x11;
      Manim_SetAnim(obj,0xb);
      Manim_WaitAnim(obj);
      monst->flags = monst->flags | 0x80;
LAB_80076ae8:
      if ((monst->flags & 0x80U) == 0) {
        D3_SetCollBits(o,(long)&DAT_0000200a);
        Manim_SetAnim(obj,10);
        do {
          if (((int)(obj->Env).Obj.vert_top.pad & 0x8000U) != 0) break;
          (o->pos).vx = (o->pos).vx + (short)((iVar4 * 100) / 6 >> 0xc);
          (o->pos).vz = (o->pos).vz + -1;
          (o->pos).vy = (o->pos).vy + (short)((iVar5 * 100) / 6 >> 0xc);
          Task_Next();
        } while (((obj->Env).Obj.normal_top.vx & 0x4000U) == 0);
        waiter = Boxes_GetHeightPlatform(o,(char)o + ',');
        iVar4 = rcos((int)(o->rot).vz + 0x800);
        iVar5 = rsin((int)(o->rot).vz + 0x800);
        (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
        sVar2 = (o->pos).vz;
        while (waiter != (int)sVar2) {
          sVar2 = (o->pos).vz + sVar10;
          sVar10 = sVar10 + -5;
          (o->pos).vz = sVar2;
          (o->pos).vx = (o->pos).vx + (short)(iVar4 * 10 >> 0xc);
          (o->pos).vy = (o->pos).vy + (short)(iVar5 * 10 >> 0xc);
          if ((int)sVar2 < waiter) {
            (o->pos).vz = (short)waiter;
          }
          Task_Next();
          sVar2 = (o->pos).vz;
        }
        D3_ClearCollBits(o,(long)&DAT_00002002);
        D3_SetCollBits(o,9);
        (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx | 1;
        Manim_WaitAnim(obj);
        Manim_SetAnim(obj,3);
        Manim_WaitAnim(obj);
        (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
      }
    }
    else {
      if (uVar3 == 7) {
        monst->sensormask = 0x10000001;
        D3_ClearCollBits(o,9);
        Manim_SetAnim(obj,2);
        (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
        Task_Next();
        *(undefined4 *)&o->father[1].last_pos = 0;
        while (*(int *)&o->father[1].last_pos == 0) {
          Task_Next();
        }
        D3_SetCollBits(o,9);
        D3_PlaySound(o,2);
        Manim_SetAnim(obj,2);
        Manim_WaitAnim(obj);
      }
    }
  }
  if (o_00 != (_D3_OBJECT *)0x0) {
    Task_Next();
    D3_SetCollBits(o_00,9);
    t = o_00->handle;
    uVar3 = o_00->display_mode;
    (o_00->pos).vz = local_30 + 0x50;
    (o_00->last_pos).vz = local_30 + 0x50;
    o_00->display_mode = uVar3 | 0x10;
    Task_EventExec(t,-0x2000,0);
  }
  monst->counter = 3;
  Pvl_SetStateBits(o,8);
  monst->timer = *(short *)&monst->timer_agression;
  if ((monst->flags & 0x80U) != 0) {
LAB_80077228:
    Monster_ReleaseBonuses();
    return;
  }
  monst->sensormask = uVar8;
  monst->flags = monst->flags | 0x40;
  o->display_mode = o->display_mode | 0x10;
  D3_SetCollBits(o,9);
  if (monst->zone_current != (_ENEMYZONE *)0x0) {
    monst->zone_wait = monst->zone_current;
  }
  waiter = Task_EventWait();
  t = TaskCurrent;
  monst->action = (short)waiter;
  t->event_enable = 1;
  do {
    switch((int)(((uint)(ushort)monst->action - 1) * 0x10000) >> 0x10) {
    case 0:
      Monster_Action_WaitRun(monst,0,5,100,0,3);
      break;
    case 1:
      waiter = Monster_Action_Hit(9,10,0x70000001,1);
      if (waiter == 0) {
        (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
      }
      else {
        if ((monst->flags2 & 0x10U) == 0) {
          if (waiter != 2) goto switchD_80076df8_caseD_f;
        }
        else {
          if (o_00 != (_D3_OBJECT *)0x0) {
            D3_DeleteObject(o_00);
            o_00 = (_D3_OBJECT *)0x0;
          }
          if (waiter != 2) {
            uVar7 = 0;
            t = SFX_StreamFire(o);
            SFX_Magic(200,0xc0,0x32);
            bVar1 = true;
            do {
              if (!bVar1) {
                if ((uVar7 & 1) == 0) {
                  uVar3 = o->display_mode & 0xffef;
                }
                else {
                  uVar3 = o->display_mode | 0x10;
                }
                o->display_mode = uVar3;
              }
              uVar7 = uVar7 + 1;
              Task_Next();
              bVar1 = (int)uVar7 < 0x11;
            } while ((int)uVar7 < 0x20);
            Task_Kill(t);
            o->display_mode = o->display_mode & 0xffef;
            D3_ClearCollBits(o,0xb);
          }
        }
        monst->mode = 0x11;
      }
      break;
    case 4:
      if ((o[1].pos.vz & 0x200U) == 0) {
        Monster_Action_MoveTo(0,0,0,(_D3_OBJECT *)Monster_Feelings,100,4,5,-1,-1,-1,-1);
      }
      break;
    case 10:
      Manim_SetAnim(obj,0);
      while (waiter = D3_GoToDir(o,(int)*(short *)(Monster_Feelings + 0x2c) - (int)(o->pos).vx,
                                 (int)*(short *)(Monster_Feelings + 0x2e) - (int)(o->pos).vy,0xa0),
            waiter != 0) {
        Task_Next();
      }
      uVar7 = M_rand();
      waiter = 7;
      if ((uVar7 & 1) != 0) {
        waiter = 8;
      }
      Monster_Action_Slaying(waiter,200,(_D3_OBJECT *)Monster_Feelings,0);
      Manim_SetAnim(obj,0);
      iVar4 = 0;
      if (monst->timer_agression >> 1 < 1) break;
      do {
        iVar4 = iVar4 + 1;
        Task_Next();
      } while (iVar4 < monst->timer_agression >> 1);
      monst->actionmask = 0;
      goto LAB_800771f4;
    case 0xb:
      AnimShoot = 7;
      ShootType = 5;
      local_5c = 0x8c;
      waiter = monst->timer_agression;
      goto LAB_800770f8;
    case 0xf:
switchD_80076df8_caseD_f:
      (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
      iVar4 = monst->counter + -1;
      monst->counter = iVar4;
      if (iVar4 == 0) {
        uVar9 = 0;
        monst->mode = 0x11;
        o->color = 0x8080ff;
        uVar7 = 0;
        do {
          if (uVar7 != 0) {
            Impact_Blood((char)o + ',',3);
          }
          uVar9 = uVar9 + 1;
          Task_Next();
          uVar7 = uVar9 & 7;
        } while ((int)uVar9 < 0x1e);
      }
      else {
        iVar4 = 0;
        do {
          iVar4 = iVar4 + 1;
          Task_Next();
        } while (iVar4 < 0xb4);
        o->hit_points = monst->oldhit_points;
        Manim_SetAnim(obj,3);
        Manim_WaitAnim(obj);
        t = TaskCurrent;
        (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
        monst->mode = 0x10;
        monst->sensormask = uVar8;
        t->event_enable = 1;
        D3_SetCollBits(o,(long)&DAT_00004011);
        o->collision_state = o->collision_state & 0xfffd;
      }
      break;
    case 0x13:
      AnimShoot = 0xc;
      ShootType = 0x18;
      local_5c = 200;
      waiter = monst->timer_agression;
LAB_800770f8:
      Monster_Action_Shooting(-1,-1,AnimShoot,ShootType,1,local_5c,0,waiter,7);
      break;
    case 0x1e:
      MSpell_SpellTesting(monst,TaskCurrent->event_param,-1,0);
    }
    monst->actionmask = 0;
LAB_800771f4:
    monst->busy = -1;
    Task_Next();
    if (monst->mode == 0x11) goto LAB_80077228;
    Monster_ForceAction(monst,1,0);
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Maton_Func_Reflex()
 // line 2661, offset 0x80077260
	/* begin block 1 */
		// Start line: 2662
		// Start offset: 0x80077260
		// Variables:
	// 		struct _MONSTER *monst; // $s1
	// 		struct _D3_OBJECT *o; // $s2
	// 		struct M_OBJECT *mo; // $s4
	// 		long i; // $s0
	// 		long x; // $s3
	// 		long y; // $s0
	/* end block 1 */
	// End offset: 0x80077570
	// End Line: 2738

	/* begin block 2 */
		// Start line: 6224
	/* end block 2 */
	// End Line: 6225

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Maton_Func_Reflex(void)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  _ENEMYZONE *p_Var6;
  long action;
  short sVar7;
  _MONSTER *monst;
  _D3_OBJECT *o;
  short sVar8;
  M_OBJECT *obj;
  
  monst = (_MONSTER *)TaskCurrent->local;
  o = monst->obj;
  obj = (M_OBJECT *)o->description;
  if (monst->zone_current->type == '\x03') {
    p_Var6 = monst->zonecustom1;
    if (monst->zone_current == p_Var6) {
      p_Var6 = monst->zonecustom2;
      sVar7 = p_Var6->x1;
      sVar8 = p_Var6->x2;
      sVar1 = p_Var6->y1;
      sVar2 = p_Var6->y2;
      monst->zone_current = p_Var6;
      iVar4 = (int)sVar7 + (int)sVar8;
      iVar5 = (int)sVar1 + (int)sVar2;
    }
    else {
      sVar7 = p_Var6->x1;
      sVar8 = p_Var6->x2;
      sVar1 = p_Var6->y1;
      sVar2 = p_Var6->y2;
      monst->zone_current = p_Var6;
      iVar4 = (int)sVar7 + (int)sVar8;
      iVar5 = (int)sVar1 + (int)sVar2;
    }
    Monster_StopAllActions(monst);
    Monster_AddAction(monst,0,0xf,0,0);
    o->display_mode = o->display_mode & 0xffef;
    D3_ClearCollBits(o,9);
    sVar8 = (short)(iVar4 >> 1);
    (o->pos).vx = sVar8;
    sVar7 = (short)(iVar5 >> 1);
    (o->pos).vy = sVar7;
    (o->last_pos).vx = sVar8;
    (o->last_pos).vy = sVar7;
    sVar7 = 0xc00;
    if ((int)monst->zone_current->y1 + (int)monst->zone_current->y2 < 1) {
      sVar7 = 0x400;
    }
    (o->rot).vz = sVar7;
    iVar5 = 0;
    do {
      iVar5 = iVar5 + 1;
      Task_Next();
    } while (iVar5 < 0x5a);
    iVar5 = 0;
    o->display_mode = o->display_mode | 0x10;
    D3_SetCollBits(o,9);
    monst->counter = 1;
    Manim_SetAnim(obj,0);
    do {
      iVar5 = iVar5 + 1;
      Task_Next();
    } while (iVar5 < 0x17);
    Monster_StopAllActions(monst);
    Monster_AddAction(monst,0,1,0,0);
  }
  if (monst->timer != 0) {
    monst->timer = monst->timer + -1;
  }
  if ((((monst->flags2 & 4U) == 0) && (LONG_ARRAY_800b2e40[0] < 2000)) &&
     (LONG_ARRAY_800b2e40[0] != -1)) {
    if (LONG_ARRAY_800b2e40[0] < 0x8e) {
      Monster_StopAllActions(monst);
      action = 0xb;
    }
    else {
      if (((0x2ba < LONG_ARRAY_800b2e40[0] - 0x12dU) || (LONG_800b2e38 == -1)) ||
         ((monst->timer != 0 ||
          ((monst->action == 0xc || ((monst->obj->collision_state & 0x80U) == 0))))))
      goto LAB_800774e8;
      monst->timer = *(short *)&monst->timer_agression;
      Monster_StopAllActions(monst);
      action = 0xc;
    }
    Monster_AddAction(monst,0,action,0,0);
  }
LAB_800774e8:
  if ((((LONG_800b2e20 != -1) || (LONG_800b2e1c != -1)) && (2 < (uint)(ushort)monst->mode - 0x32))
     && ((uVar3 = M_rand(), 5 < (uVar3 & 7) && (monst->action != 8)))) {
    Monster_StopAllActions(monst);
    Monster_AddAction(monst,1,8,0,0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Maton_Task_Action()
 // line 2741, offset 0x80077590
	/* begin block 1 */
		// Start line: 2742
		// Start offset: 0x80077590
		// Variables:
	// 		short foundpath[3]; // stack offset -32
	// 		struct _MONSTER *monst; // $s1
	// 		struct _D3_OBJECT *o; // $s2
	// 		struct M_OBJECT *mo; // $s4
	// 		long x; // $s0
	// 		long y; // $t1
	// 		long tmp; // $a0
	// 		long i; // $s0
	// 		unsigned long low; // $a1
	// 		unsigned long high; // $a3
	// 		long missing; // $t1
	/* end block 1 */
	// End offset: 0x80077B08
	// End Line: 2854

	/* begin block 2 */
		// Start line: 6406
	/* end block 2 */
	// End Line: 6407

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Maton_Task_Action(void)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  ushort uVar7;
  _PVL_HEADER *p_Var8;
  long local_40;
  _ENEMYZONE *p_Var9;
  int iVar10;
  uint uVar11;
  _MONSTER *monst;
  _D3_OBJECT *o;
  M_OBJECT *obj;
  
  monst = (_MONSTER *)TaskCurrent->local;
  o = monst->obj;
  obj = (M_OBJECT *)o->description;
  if (o->hit_points == 5000) {
    monst->flags2 = monst->flags2 | 4;
  }
  p_Var8 = Pvl_File;
  uVar11 = monst->zb_low;
  monst->hurtsound = 3;
  monst->fleesound = 2;
  monst->timer = 0x5a;
  monst->zonecustom2 = (_ENEMYZONE *)0x0;
  monst->zonecustom1 = (_ENEMYZONE *)0x0;
  iVar10 = 0;
  p_Var9 = Pvl_EnemyZones;
  if (0 < p_Var8->n_enemyzones) {
    do {
      if (((uVar11 & 1) != 0) && (p_Var9->type == '\x03')) {
        if (monst->zonecustom1 == (_ENEMYZONE *)0x0) {
          monst->zonecustom1 = p_Var9;
        }
        else {
          monst->zonecustom2 = p_Var9;
        }
      }
      uVar11 = uVar11 >> 1;
      if (iVar10 == 0x1f) {
        uVar11 = monst->zb_high;
      }
      iVar10 = iVar10 + 1;
      p_Var9 = p_Var9 + 1;
    } while (iVar10 < (int)p_Var8->n_enemyzones);
  }
  local_40 = Task_EventWait();
  monst->action = (short)local_40;
  TaskCurrent->event_enable = 1;
  monst->monster_speed = 0x100;
  do {
    switch((int)(((uint)(ushort)monst->action - 1) * 0x10000) >> 0x10) {
    case 0:
      monst->busy = 0;
      do {
        monst->monster_speed = 0x80;
        iVar10 = 0;
        while (uVar11 = M_rand(), iVar10 < (int)(uVar11 & 3)) {
          iVar10 = iVar10 + 1;
          local_40 = M_rand();
          D3_PlaySound(o,(ushort)local_40 & 3 | 4);
          Manim_SetAnim(obj,5);
          Manim_WaitAnim(obj);
        }
        if ((o[1].pos.vz & 0x200U) == 0) {
          uVar11 = M_rand();
          if ((uVar11 & 1) == 0) {
            sVar1 = monst->zone_wait->x2;
          }
          else {
            sVar1 = monst->zone_wait->x1;
          }
          sVar2 = monst->zone_wait->x1;
          sVar3 = monst->zone_wait->x2;
          uVar11 = M_rand();
          if ((uVar11 & 1) == 0) {
            sVar4 = monst->zone_wait->y2;
            p_Var9 = monst->zone_wait;
          }
          else {
            p_Var9 = monst->zone_wait;
            sVar4 = p_Var9->y1;
          }
          sVar5 = p_Var9->y1;
          sVar6 = p_Var9->y2;
          monst->mode = 0x10;
          Monster_Action_MoveTo
                    ((int)sVar1 + ((int)sVar2 + (int)sVar3 >> 1) >> 1,
                     (int)sVar4 + ((int)sVar5 + (int)sVar6 >> 1) >> 1,
                     (int)p_Var9->z1 + (int)p_Var9->z2 >> 1,(_D3_OBJECT *)0x0,0x96,6,1,7,-1,-1,-1);
        }
        Task_Next();
      } while( true );
    case 1:
      Monster_Action_Hit(4,0xd,1,1);
      monst->actionmask = 0;
      break;
    case 4:
      if ((o[1].pos.vz & 0x200U) != 0) goto switchD_800776e4_caseD_2;
      Monster_Action_MoveTo(0,0,0,(_D3_OBJECT *)Monster_Feelings,0x96,6,0,7,-1,-1,-1);
      monst->actionmask = 0;
      break;
    case 7:
      Monster_Action_Protect(0,1,-1,-1,3,2,-1);
      monst->actionmask = 0;
      break;
    case 10:
      while (local_40 = D3_GoToDir(o,(int)*(short *)(Monster_Feelings + 0x2c) - (int)(o->pos).vx,
                                   (int)*(short *)(Monster_Feelings + 0x2e) - (int)(o->pos).vy,0xa0)
            , local_40 != 0) {
        Task_Next();
      }
      uVar11 = M_rand();
      local_40 = 9;
      if ((uVar11 & 3) != 0) {
        local_40 = 8;
      }
      Monster_Action_Slaying(local_40,0x96,(_D3_OBJECT *)Monster_Feelings,0);
      Manim_SetAnim(obj,5);
      if ((LONG_800b2e28 != -1) || (iVar10 = 0, monst->timer_agression >> 1 < 1))
      goto switchD_800776e4_caseD_2;
      do {
        iVar10 = iVar10 + 1;
        Task_Next();
      } while (iVar10 < monst->timer_agression >> 1);
      monst->actionmask = 0;
      break;
    case 0xb:
      uVar7 = o[1].pos.vz;
      if ((uVar7 & 0x800) == 0) {
        local_40 = 1;
      }
      else {
        local_40 = 3;
      }
      Monster_Action_Shooting(10,0xc,0xb,0x17,local_40,200,(uint)((uVar7 & 0x100) != 0),10,8);
      monst->actionmask = 0;
      break;
    case 0xe:
      (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
      do {
        Task_Next();
      } while( true );
    case 0x14:
      Monster_Action_Flee(monst,0,5,-1);
    default:
switchD_800776e4_caseD_2:
      monst->actionmask = 0;
      break;
    case 0x1d:
      Monster_Action_Fear(monst,5,0,100,2);
      monst->actionmask = 0;
      break;
    case 0x1e:
      MSpell_SpellTesting(monst,TaskCurrent->event_param,-1,5);
      monst->actionmask = 0;
    }
    monst->busy = -1;
    Task_Next();
    if (monst->mode == 0x11) {
      Monster_ReleaseBonuses();
      return;
    }
    Monster_ForceAction(monst,1,0);
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Hpl_Func_Reflex()
 // line 2889, offset 0x80077b30
	/* begin block 1 */
		// Start line: 2890
		// Start offset: 0x80077B30
		// Variables:
	// 		struct _MONSTER *monst; // $s0
	// 		struct _D3_OBJECT *o; // $v1
	/* end block 1 */
	// End offset: 0x80077C5C
	// End Line: 2908

	/* begin block 2 */
		// Start line: 6737
	/* end block 2 */
	// End Line: 6738

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Hpl_Func_Reflex(void)

{
  uint uVar1;
  _MONSTER *monst;
  
  monst = (_MONSTER *)TaskCurrent->local;
  if ((monst->obj->hit_points < 0x1e) && (0x78 < monst->timer_agression)) {
    monst->timer_agression = 0x78;
  }
  if ((monst->obj->hit_points < 10) && (0x5a < monst->timer_agression)) {
    monst->timer_agression = 0x5a;
  }
  if (((((int)monst->obj->hit_points < (int)Pvl_LevelNumber * 5 + 0x32) && (LONG_800b2e20 != -1)) ||
      (LONG_800b2e1c != -1)) &&
     (((2 < (uint)(ushort)monst->mode - 0x32 && (uVar1 = M_rand(), 5 < (uVar1 & 7))) &&
      (monst->action != 8)))) {
    Monster_StopAllActions(monst);
    Monster_AddAction(monst,0,8,0,0);
  }
  Monster_ReflexCombat(monst,0xa2,monst->timer_agression);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Hpl_Task_Action()
 // line 2912, offset 0x80077c7c
	/* begin block 1 */
		// Start line: 2913
		// Start offset: 0x80077C7C
		// Variables:
	// 		struct _MONSTER *monst; // $s1
	// 		struct _D3_OBJECT *o; // $s3
	// 		struct M_OBJECT *mo; // $s4
	// 		long missing; // $s2
	// 		long x; // $s0
	// 		long y; // $t1
	/* end block 1 */
	// End offset: 0x80078070
	// End Line: 2996

	/* begin block 2 */
		// Start line: 6784
	/* end block 2 */
	// End Line: 6785

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Hpl_Task_Action(void)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  ushort uVar5;
  TASK *pTVar6;
  long waiter;
  _ENEMYZONE *p_Var7;
  uint uVar8;
  uint uVar9;
  long AnimStart;
  long AnimStop;
  long AnimShoot;
  long ShootType;
  _MONSTER *monst;
  _D3_OBJECT *o;
  M_OBJECT *obj;
  long local_48;
  long local_44;
  
  monst = (_MONSTER *)TaskCurrent->local;
  o = monst->obj;
  obj = (M_OBJECT *)o->description;
  monst->hurtsound = 2;
  monst->monster_speed = 0x40;
  waiter = Task_EventWait();
  pTVar6 = TaskCurrent;
  monst->action = (short)waiter;
  pTVar6->event_enable = 1;
  do {
    switch((int)(((uint)(ushort)monst->action - 1) * 0x10000) >> 0x10) {
    case 0:
      monst->busy = 0;
      monst->mode = 0x10;
      do {
        if ((o[1].pos.vz & 0x200U) == 0) {
          uVar8 = M_rand();
          if ((uVar8 & 1) == 0) {
            sVar1 = monst->zone_wait->x2;
          }
          else {
            sVar1 = monst->zone_wait->x1;
          }
          sVar2 = monst->zone_wait->x1;
          sVar3 = monst->zone_wait->x2;
          uVar8 = M_rand();
          if ((uVar8 & 1) == 0) {
            sVar4 = monst->zone_wait->y2;
            p_Var7 = monst->zone_wait;
          }
          else {
            p_Var7 = monst->zone_wait;
            sVar4 = p_Var7->y1;
          }
          Monster_Action_MoveTo
                    ((int)sVar1 + ((int)sVar2 + (int)sVar3 >> 1) >> 1,
                     (int)sVar4 + ((int)p_Var7->y1 + (int)p_Var7->y2 >> 1) >> 1,
                     (int)p_Var7->z1 + (int)p_Var7->z2 >> 1,(_D3_OBJECT *)0x0,100,1,2,3,-1,-1,4);
          Task_Next();
        }
        else {
          Manim_ForceAnim(obj,0);
          Manim_WaitAnim(obj);
        }
        Task_Next();
      } while( true );
    case 1:
      Monster_Action_Hit(0xc,0xd,2,1);
      monst->actionmask = 0;
      break;
    case 4:
      if ((o[1].pos.vz & 0x200U) != 0) goto switchD_80077d20_caseD_2;
      Monster_Action_MoveTo(0,0,0,(_D3_OBJECT *)Monster_Feelings,0x96,1,2,3,-1,-1,4);
      monst->actionmask = 0;
      break;
    case 7:
      Monster_Action_Magic(monst,3,0xe,0xf,1);
      monst->actionmask = 0;
      break;
    case 10:
      while (waiter = D3_GoToDir(o,(int)*(short *)(Monster_Feelings + 0x2c) - (int)(o->pos).vx,
                                 (int)*(short *)(Monster_Feelings + 0x2e) - (int)(o->pos).vy,0xa0),
            waiter != 0) {
        Task_Next();
      }
      Monster_Action_Slaying(0xb,200,(_D3_OBJECT *)Monster_Feelings,0);
      Manim_SetAnim(obj,0);
      monst->actionmask = 0;
      break;
    case 0xb:
      uVar5 = o[1].pos.vz;
      uVar9 = monst->timer_agression;
      uVar8 = M_rand();
      if ((uVar8 & 1) == 0) {
        AnimStart = -1;
        AnimStop = -1;
        AnimShoot = 10;
        local_48 = 1;
        local_44 = 0x96;
        waiter = monst->timer_agression;
        ShootType = 4;
      }
      else {
        AnimStart = 4;
        if ((o[1].pos.vz & 0x800U) == 0) {
          AnimStop = 6;
          AnimShoot = 5;
          local_48 = 1;
          local_44 = 200;
          waiter = monst->timer_agression;
          ShootType = 6;
        }
        else {
          AnimStop = 6;
          AnimShoot = 5;
          local_48 = 3;
          local_44 = 200;
          waiter = monst->timer_agression;
          ShootType = 6;
        }
      }
      Monster_Action_Shooting
                (AnimStart,AnimStop,AnimShoot,ShootType,local_48,local_44,
                 (uint)(((int)(short)(uVar5 & 0x100) & uVar9) != 0),waiter,3);
      monst->actionmask = 0;
      break;
    case 0x1e:
      MSpell_SpellTesting(monst,TaskCurrent->event_param,-1,0);
    default:
switchD_80077d20_caseD_2:
      monst->actionmask = 0;
    }
    monst->busy = -1;
    Task_Next();
    if (monst->mode == 0x11) {
      Monster_ReleaseBonuses();
      return;
    }
    Monster_ForceAction(monst,1,0);
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Gua_Func_Reflex()
 // line 3027, offset 0x800780a4
	/* begin block 1 */
		// Start line: 3028
		// Start offset: 0x800780A4
		// Variables:
	// 		struct _MONSTER *monst; // $s0
	/* end block 1 */
	// End offset: 0x80078198
	// End Line: 3056

	/* begin block 2 */
		// Start line: 7043
	/* end block 2 */
	// End Line: 7044

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Gua_Func_Reflex(void)

{
  long lVar1;
  uint uVar2;
  _MONSTER *monst;
  
  monst = (_MONSTER *)TaskCurrent->local;
  lVar1 = Monster_Reflex_Fear(monst);
  if (lVar1 == 0) {
    if ((((LONG_800b2e20 != -1) || (LONG_800b2e1c != -1)) && (2 < (uint)(ushort)monst->mode - 0x32))
       && ((uVar2 = M_rand(), 5 < (uVar2 & 7) && (monst->action != 8)))) {
      Monster_StopAllActions(monst);
      Monster_AddAction(monst,1,8,0,0);
    }
    if (((LONG_ARRAY_800b2e40[0] != -1) && (LONG_ARRAY_800b2e40[0] < 2000)) &&
       (LONG_ARRAY_800b2e40[0] < 0x91)) {
      Monster_StopAllActions(monst);
      Monster_AddAction(monst,0,0xb,0,0);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Big_Func_Reflex()
 // line 3087, offset 0x800781a8
	/* begin block 1 */
		// Start line: 3088
		// Start offset: 0x800781A8
		// Variables:
	// 		struct _MONSTER *monst; // $a0
	/* end block 1 */
	// End offset: 0x800781A8
	// End Line: 3088

	/* begin block 2 */
		// Start line: 7164
	/* end block 2 */
	// End Line: 7165

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Big_Func_Reflex(void)

{
  Monster_ReflexCombat
            ((_MONSTER *)TaskCurrent->local,0xa0,((_MONSTER *)TaskCurrent->local)->timer_agression);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Big_Task_Action()
 // line 3095, offset 0x800781dc
	/* begin block 1 */
		// Start line: 3096
		// Start offset: 0x800781DC
		// Variables:
	// 		struct _MONSTER *monst; // $s1
	// 		struct _D3_OBJECT *o; // $s2
	// 		struct M_OBJECT *mo; // $s4
	// 		long tmp; // $s0
	/* end block 1 */
	// End offset: 0x800784B8
	// End Line: 3146

	/* begin block 2 */
		// Start line: 7181
	/* end block 2 */
	// End Line: 7182

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Big_Task_Action(void)

{
  TASK *pTVar1;
  long Anim;
  uint uVar2;
  long sound;
  int iVar3;
  _MONSTER *monst;
  _D3_OBJECT *o;
  M_OBJECT *obj;
  
  monst = (_MONSTER *)TaskCurrent->local;
  o = monst->obj;
  obj = (M_OBJECT *)o->description;
  monst->hurtsound = 2;
  monst->fleesound = 2;
  monst->timer = 0x78;
  Anim = Task_EventWait();
  pTVar1 = TaskCurrent;
  monst->action = (short)Anim;
  pTVar1->event_enable = 1;
  do {
    switch((int)(((uint)(ushort)monst->action - 1) * 0x10000) >> 0x10) {
    case 0:
      monst->zone_wait = monst->zone_current;
      Monster_Action_WaitRun(monst,0,1,0x28,0,6);
      monst->actionmask = 0;
      break;
    case 1:
      Monster_Action_Hit(9,8,1,1);
      monst->actionmask = 0;
      break;
    case 4:
      if ((o[1].pos.vz & 0x200U) != 0) goto switchD_8007827c_caseD_2;
      Monster_Action_MoveTo(0,0,0,(_D3_OBJECT *)Monster_Feelings,0x96,-1,2,-1,-1,10,5);
      monst->actionmask = 0;
      break;
    case 10:
      Manim_SetAnim(obj,0);
      while (Anim = D3_GoToDir(o,(int)*(short *)(Monster_Feelings + 0x2c) - (int)(o->pos).vx,
                               (int)*(short *)(Monster_Feelings + 0x2e) - (int)(o->pos).vy,0xa0),
            Anim != 0) {
        Task_Next();
      }
      uVar2 = M_rand();
      Anim = 6;
      if ((uVar2 & 1) == 0) {
        Anim = 7;
        sound = 3;
      }
      else {
        sound = 0;
      }
      iVar3 = 0;
      Monster_Action_Slaying(Anim,0xaa,(_D3_OBJECT *)Monster_Feelings,sound);
      Manim_SetAnim(obj,0);
      if (monst->timer_agression >> 1 < 1) goto switchD_8007827c_caseD_2;
      do {
        iVar3 = iVar3 + 1;
        Task_Next();
      } while (iVar3 < monst->timer_agression >> 1);
      monst->actionmask = 0;
      break;
    case 0xb:
      Monster_Action_Shooting(4,5,3,9,3,0xfa,0,monst->timer_agression,4);
      monst->actionmask = 0;
      break;
    case 0x14:
      Monster_Action_Flee(monst,2,0,5);
    default:
switchD_8007827c_caseD_2:
      monst->actionmask = 0;
      break;
    case 0x1e:
      MSpell_SpellTesting(monst,TaskCurrent->event_param,-1,0);
      monst->actionmask = 0;
    }
    monst->busy = -1;
    Task_Next();
    if (monst->mode == 0x11) {
      Monster_ReleaseBonuses();
      return;
    }
    Monster_ForceAction(monst,1,0);
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pri_Get_CustomZones(struct _MONSTER *monst /*$a0*/, short *ret /*$a1*/)
 // line 3178, offset 0x800784e4
	/* begin block 1 */
		// Start line: 3180
		// Start offset: 0x800784E4
		// Variables:
	// 		long tmp; // $a2
	// 		unsigned long low; // $a3
	// 		unsigned long high; // $t0
	/* end block 1 */
	// End offset: 0x800785A4
	// End Line: 3199

	/* begin block 2 */
		// Start line: 7361
	/* end block 2 */
	// End Line: 7362

void Pri_Get_CustomZones(_MONSTER *monst,short *ret)

{
  _ENEMYZONE *p_Var1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  
  uVar3 = monst->zb_low;
  uVar4 = monst->zb_high;
  iVar2 = 0;
  p_Var1 = Pvl_EnemyZones;
  if (0 < Pvl_File->n_enemyzones) {
    do {
      if (((uVar3 & 1) != 0) && (p_Var1->type == '\x02')) {
        *ret = (short)((int)p_Var1->x1 + (int)p_Var1->x2 >> 1);
        ret[1] = (short)((int)p_Var1->y1 + (int)p_Var1->y2 >> 1);
        ret[2] = (short)((int)p_Var1->z1 + (int)p_Var1->z2 >> 1);
        ret = ret + 3;
      }
      uVar3 = uVar3 >> 1;
      if (iVar2 == 0x1f) {
        uVar3 = uVar4;
      }
      iVar2 = iVar2 + 1;
      p_Var1 = p_Var1 + 1;
    } while (iVar2 < (int)Pvl_File->n_enemyzones);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pri_Func_Reflex()
 // line 3202, offset 0x800785ac
	/* begin block 1 */
		// Start line: 3203
		// Start offset: 0x800785AC
		// Variables:
	// 		struct _MONSTER *monst; // $s1
	// 		struct _D3_OBJECT *o; // $s2
	// 		struct _D3_OBJECT *tmpobj; // $s0
	/* end block 1 */
	// End offset: 0x800786A0
	// End Line: 3225

	/* begin block 2 */
		// Start line: 7417
	/* end block 2 */
	// End Line: 7418

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pri_Func_Reflex(void)

{
  long lVar1;
  _D3_OBJECT *o;
  _MONSTER *monst;
  _D3_OBJECT *p_Var2;
  
  monst = (_MONSTER *)TaskCurrent->local;
  p_Var2 = monst->obj;
  o = p_Var2->child;
  lVar1 = Task_EventRead(TaskCurrent);
  if (lVar1 == 2) {
    monst->flags = monst->flags & 0xffdf;
  }
  if (((monst->flags & 0x80U) != 0) && (monst->action != 0xe)) {
    while (o != (_D3_OBJECT *)0x0) {
      if (*(char *)((int)&o[1].pos.vx + 1) == '\a') {
        lVar1 = Direction((int)(p_Var2->pos).vx - (int)(o->pos).vx,
                          (int)(p_Var2->pos).vy - (int)(o->pos).vy);
        (o->rot).vz = (short)lVar1;
      }
      lVar1 = Pvl_TestStateBits(o,1);
      if (lVar1 != 0) {
        Monster_StopAllActions(monst);
        Monster_AddAction(monst,0,0xe,0,0);
      }
      o = o->next;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Stop_Yelling(struct _D3_OBJECT *o /*$v1*/, long stop /*$a1*/)
 // line 3228, offset 0x800786b8
	/* begin block 1 */
		// Start line: 7470
	/* end block 1 */
	// End Line: 7471

void Stop_Yelling(_D3_OBJECT *o,long stop)

{
  ushort uVar1;
  _D3_OBJECT *p_Var2;
  
  p_Var2 = o->child;
  while (p_Var2 != (_D3_OBJECT *)0x0) {
    if (*(char *)((int)&p_Var2[1].pos.vx + 1) == '\a') {
      if (stop == 0) {
        uVar1 = p_Var2->display_mode | 0x10;
      }
      else {
        uVar1 = p_Var2->display_mode & 0xffef;
      }
      p_Var2->display_mode = uVar1;
    }
    p_Var2 = p_Var2->next;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pri_Task_Action()
 // line 3246, offset 0x80078718
	/* begin block 1 */
		// Start line: 3247
		// Start offset: 0x80078718
		// Variables:
	// 		struct ENEMY_104fake t; // stack offset -88
	// 		struct _ZONE *zone; // $v0
	// 		struct _MONSTER *monst; // $s3
	// 		struct _D3_OBJECT *o; // $s2
	// 		struct M_OBJECT *mo; // $s5
	// 		struct _D3_OBJECT *target; // $s0
	// 		struct _D3_OBJECT *tmpobj; // $s6
	// 		long i; // $s0
	// 		long j; // $v0
	// 		long k; // $s4
	// 		long tmp; // $s1
	// 		long key; // $s7
	// 		short oldhitpoints; // $s0
	// 		short customzone[6]; // stack offset -56
	/* end block 1 */
	// End offset: 0x80078FC4
	// End Line: 3459

	/* begin block 2 */
		// Start line: 7508
	/* end block 2 */
	// End Line: 7509

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pri_Task_Action(void)

{
  ushort uVar1;
  char *pcVar2;
  TASK *pTVar3;
  short sVar4;
  long Anim;
  uint uVar5;
  _D3_OBJECT *o;
  long lVar6;
  long lVar7;
  _ZONE *t;
  short sVar8;
  int index;
  short sVar9;
  _D3_OBJECT *obj;
  _MONSTER *monst;
  M_OBJECT *obj_00;
  undefined auStack88 [4];
  undefined4 local_54;
  short local_38;
  short local_36;
  short local_34;
  short local_32;
  short local_30;
  short local_2e;
  
  monst = (_MONSTER *)TaskCurrent->local;
  obj = monst->obj;
  obj_00 = (M_OBJECT *)obj->description;
  monst->flags = monst->flags & 0xff7f;
  monst->hurtsound = 2;
  monst->monster_speed = 0x40;
  Pri_Get_CustomZones(monst,&local_38);
  monst->sensormask = monst->sensormask & 0xefffffff;
  Anim = Zone_IsZoneAttached(obj);
  if (Anim == 0) {
    Stop_Yelling(obj,0);
    monst->flags = monst->flags | 0x80;
    Scts_Interruptors = Scts_Interruptors & 0xffff9fff;
    monst->sensormask = monst->sensormask | 0x10000000;
  }
  if ((Pvl_SctState[(int)obj->index] & 8U) == 0) {
    monst->flags = monst->flags | 0x20;
    Manim_SetAnim(obj_00,2);
    Anim = Zone_IsZoneAttached(obj);
    if (Anim == 0) {
      Scts_Interruptors = Scts_Interruptors & 0xffff9fff;
      Stop_Yelling(obj,1);
      while ((Scts_Interruptors & 0x8000U) == 0) {
        if (((obj_00->Env).Obj.vert_top.pad & 1U) != 0) {
          Anim = M_rand();
          D3_PlaySound(obj,((ushort)Anim & 1) + 5);
        }
        Task_Next();
      }
      monst->flags = monst->flags | 0x80;
      Stop_Yelling(obj,0);
    }
    else {
      uVar1 = monst->flags;
      sVar4 = obj->hit_points;
      monst->flags = uVar1 | 4;
      while ((uVar1 & 0x20) != 0) {
        if (((obj_00->Env).Obj.vert_top.pad & 1U) != 0) {
          Anim = M_rand();
          D3_PlaySound(obj,((ushort)Anim & 1) + 5);
        }
        Task_Next();
        uVar1 = monst->flags;
      }
      monst->flags = monst->flags & 0xfffb;
      obj->hit_points = sVar4;
    }
    Manim_SetAnim(obj_00,3);
    Manim_WaitAnim(obj_00);
    Manim_SetAnim(obj_00,4);
    if (*(short *)((int)&obj[1].prec + 2) != -1) {
      Pvl_Prisoner_Status =
           Pvl_Prisoner_Status | (ushort)(1 << ((int)(uint)(ushort)obj[1].pos.vz >> 0xe) + 8);
      index = 0;
      Pvl_SctState[(int)obj->index] = Pvl_SctState[(int)obj->index] | 8;
      Text_SetContext((TEXT_102fake *)auStack88);
      Text_SetContextFont(0x70);
      Text_SetContextXY(0,0);
      Text_SetContextWH(0x140,0xf0);
      Text_SetContextRange(0);
      Text_SetContextMode(0);
      while (sVar4 = Text_AmountOfTexts((char *)Pvl_Texts[(int)*(short *)((int)&obj[1].prec + 2)]),
            index < (int)sVar4) {
        Anim = M_rand();
        D3_PlaySound(obj,(ushort)Anim & 1 | 4);
        Text_DisplayLine((char *)Pvl_Texts[(int)*(short *)((int)&obj[1].prec + 2)],index,0x32,
                         (long *)0x0);
        uVar5 = M_rand();
        if ((uVar5 & 1) == 0) {
          Anim = 4;
        }
        else {
          Anim = 5;
        }
        index = index + 1;
        Manim_SetAnim(obj_00,Anim);
      }
      D3_SetBonuses(obj,1,obj);
    }
  }
  else {
    Manim_SetAnim(obj_00,5);
  }
  Anim = Task_EventWait();
  pTVar3 = TaskCurrent;
  monst->action = (short)Anim;
  pTVar3->event_enable = 1;
  do {
    switch((int)(((uint)(ushort)monst->action - 1) * 0x10000) >> 0x10) {
    case 0:
      monst->busy = 0;
      do {
        Anim = M_rand();
        D3_PlaySound(obj,((ushort)Anim & 3) + 3);
        Manim_SetAnim(obj_00,5);
        Manim_WaitAnim(obj_00);
        monst->mode = 0x10;
        Monster_Action_MoveTo
                  ((int)local_38,(int)local_36,(int)local_34,(_D3_OBJECT *)0x0,100,-1,6,-1,-1,-1,0);
        Anim = M_rand();
        D3_PlaySound(obj,((ushort)Anim & 3) + 3);
        Manim_SetAnim(obj_00,5);
        Manim_WaitAnim(obj_00);
        monst->mode = 0x10;
        Monster_Action_MoveTo
                  ((int)local_32,(int)local_30,(int)local_2e,(_D3_OBJECT *)0x0,100,-1,6,-1,-1,-1,0);
      } while( true );
    case 1:
      Anim = Monster_Action_Hit(7,8,1,1);
      if (Anim == 0) break;
      Pvl_Prisoner_Status =
           Pvl_Prisoner_Status | (ushort)(1 << ((int)(uint)(ushort)obj[1].pos.vz >> 0xe));
      monst->actionmask = 0;
      goto LAB_80078f90;
    case 4:
      if ((obj[1].pos.vz & 0x200U) == 0) {
        Monster_Action_MoveTo(0,0,0,(_D3_OBJECT *)Monster_Feelings,100,-1,6,-1,-1,-1,0);
        monst->actionmask = 0;
        goto LAB_80078f90;
      }
      break;
    case 0xd:
      Stop_Yelling(obj,1);
      local_54 = 0xffffff;
      Manim_SetAnim(obj_00,5);
      o = Monster_GetChild(obj,(long)&DAT_000010e1);
      _DAT_800b1d58 = 1;
      if (o != (_D3_OBJECT *)0x0) {
        Anim = M_rand();
        Text_DisplayLine((char *)Pvl_Texts[(int)*(short *)((int)&o[1].prec + 2)],Anim % 3,0x50,
                         (long *)0x0);
      }
      lVar6 = Distance2D((int)local_38,(int)local_36,(int)(obj->pos).vx,(int)(obj->pos).vy);
      lVar7 = Distance2D((int)local_32,(int)local_30,(int)(obj->pos).vx,(int)(obj->pos).vy);
      Anim = Monster_Feelings;
      sVar4 = 0x800;
      if (lVar7 < lVar6) {
        uVar5 = 0x4000;
        lVar6 = lVar7;
        sVar8 = local_32;
        sVar9 = local_30;
      }
      else {
        sVar4 = 0;
        uVar5 = 0x2000;
        sVar8 = local_38;
        sVar9 = local_36;
      }
      if (200 < lVar6) {
        local_54 = 0x808080;
        while (lVar6 = D3_GoToDir(obj,(int)*(short *)(Anim + 0x2c) - (int)(obj->pos).vx,
                                  (int)*(short *)(Anim + 0x2e) - (int)(obj->pos).vy,0x28),
              lVar6 != 0) {
          Task_Next();
        }
        Text_DisplayLine((char *)Pvl_Texts[(int)*(short *)((int)&o[1].prec + 2)],4,0x32,(long *)0x0)
        ;
        Manim_SetAnim(obj_00,5);
        _DAT_800b1d58 = 0;
        Stop_Yelling(obj,0);
        monst->actionmask = 0;
        goto LAB_80078f90;
      }
      t = Zone_GetObjectZone(o);
      if (t != (_ZONE *)0x0) {
        Track_SetMode(10,(long)t);
      }
      (obj->pos).vx = sVar8;
      (obj->last_pos).vx = sVar8;
      (obj->pos).vy = sVar9;
      (obj->last_pos).vy = sVar9;
      (obj->rot).vz = sVar4;
      Manim_SetAnim(obj_00,9);
      Task_Sleep(10);
      Fx_Play(10,(char)obj + ',');
      Manim_WaitAnim(obj_00);
      _DAT_800b1d58 = 0;
      Manim_SetAnim(obj_00,5);
      index = 0;
      do {
        index = index + 1;
        Task_Next();
      } while (index < 0x5a);
      index = 0;
      Scts_Interruptors = Scts_Interruptors | uVar5;
      do {
        index = index + 1;
        Task_Next();
      } while (index < 300);
      _DAT_800b1d58 = 1;
      t = Zone_GetObjectZone(o);
      if (t != (_ZONE *)0x0) {
        Track_SetMode(10,(long)t);
      }
      Manim_SetAnim(obj_00,10);
      Task_Sleep(10);
      Fx_Play(10,(char)obj + ',');
      Manim_WaitAnim(obj_00);
      _DAT_800b1d58 = 0;
      index = 0;
      do {
        index = index + 1;
        Task_Next();
      } while (index < 0x1e);
      Scts_Interruptors = Scts_Interruptors & ~uVar5;
      Stop_Yelling(obj,0);
      local_54 = 0x808080;
      break;
    case 0x1e:
      MSpell_SpellTesting(monst,TaskCurrent->event_param,-1,5);
    }
    monst->actionmask = 0;
LAB_80078f90:
    monst->busy = -1;
    Task_Next();
    pcVar2 = Pvl_SctState;
    if (monst->mode == 0x11) {
      (obj_00->Env).Obj.normal_top.vx = (obj_00->Env).Obj.normal_top.vx & 0xfffe;
      monst->actionmask = 0;
      monst->mode = 0;
      pcVar2[(int)obj->index] = pcVar2[(int)obj->index] ^ 2;
      D3_ClearCollBits(obj,10);
      return;
    }
    Monster_ForceAction(monst,1,0);
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ PrisBoss_Scripting()
 // line 3496, offset 0x80079030
	/* begin block 1 */
		// Start line: 3497
		// Start offset: 0x80079030
		// Variables:
	// 		short customzone[6]; // stack offset -56
	// 		struct _ZONE *zone; // $fp
	// 		struct _MONSTER *monst; // $s4
	// 		struct _D3_OBJECT *o; // $s1
	// 		struct M_OBJECT *mo; // $s7
	// 		struct _D3_OBJECT *target; // $s6
	// 		long grav; // $s0
	// 		long x; // $s2
	// 		long y; // $s5
	// 		long sensors; // $fp
	// 		unsigned long value; // $s3
	// 		struct _D3_OBJECT *good; // $s3
	// 		struct _D3_OBJECT *bad; // $s2
	/* end block 1 */
	// End offset: 0x80079F3C
	// End Line: 3825

	/* begin block 2 */
		// Start line: 8075
	/* end block 2 */
	// End Line: 8076

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void PrisBoss_Scripting(void)

{
  bool bVar1;
  short sVar2;
  short sVar3;
  ushort uVar4;
  short sVar5;
  short sVar6;
  _D3_OBJECT *obj;
  _D3_OBJECT *o;
  _ZONE *t;
  _ENEMYZONE *p_Var7;
  long t_00;
  long lVar8;
  uint uVar9;
  int index;
  _D3_OBJECT *o_00;
  _D3_OBJECT *o_01;
  int iVar10;
  _MONSTER *monst;
  M_OBJECT *obj_00;
  _ZONE *t_01;
  ulong uVar11;
  short local_38;
  short local_36;
  short local_34;
  
  t_00 = Monster_Feelings;
  monst = (_MONSTER *)TaskCurrent->local;
  o_00 = monst->obj;
  obj_00 = (M_OBJECT *)o_00->description;
  o = o_00->next;
  if (o_00->next == (_D3_OBJECT *)0x0) {
    o = (_D3_OBJECT *)0x0;
    if (o_00->prec != (_D3_OBJECT *)0x0) {
      o = o_00->prec;
    }
  }
  o_01 = o_00->father;
  if (o_01 != (_D3_OBJECT *)0x0) {
    obj = o_01->next;
    if (obj == (_D3_OBJECT *)0x0) {
      obj = o_01->prec;
      o_01 = (_D3_OBJECT *)0x0;
      if (obj == (_D3_OBJECT *)0x0) goto LAB_800790d0;
    }
    o_01 = obj;
  }
LAB_800790d0:
  if ((Pvl_Prisoner_Status & 0xff00) == 0xff00) {
    return;
  }
  Pri_Get_CustomZones(monst,&local_38);
  uVar9 = (int)(uint)(ushort)o_00[1].pos.vz >> 0xe;
  if (uVar9 == 1) {
    sVar6 = monst->scriptpos;
  }
  else {
    if (1 < uVar9) {
      if (uVar9 == 2) {
        monst->flags = monst->flags | 0x20;
        while( true ) {
          Manim_SetAnim(obj_00,4);
          while ((monst->flags & 0x20U) != 0) {
            D3_GoToDir(o_00,(int)*(short *)(t_00 + 0x2c) - (int)(o_00->pos).vx,
                       (int)*(short *)(t_00 + 0x2e) - (int)(o_00->pos).vy,(int)monst->monster_speed)
            ;
            Task_Next();
          }
          if ((Pvl_Prisoner_Status & 0xff00) == 0xf00) break;
          lVar8 = M_rand();
          D3_PlaySound(o_00,(short)((uint)((lVar8 % 3 + 4) * 0x10000) >> 0x10));
          Text_DisplayLine((char *)Pvl_Texts[(int)*(short *)((int)&o_00[1].prec + 2)],0,0x8c,
                           (long *)0x0);
          uVar4 = monst->flags;
          while ((uVar4 & 0x20) == 0) {
            Task_Next();
            uVar4 = monst->flags;
          }
        }
        if ((Pvl_Prisoner_Status & 0xf) == 0) {
          obj = o_01;
          if (o != (_D3_OBJECT *)0x0) {
            _DAT_800b1d58 = 1;
            t_00 = M_rand();
            D3_PlaySound(o_00,(short)((uint)((t_00 % 3 + 4) * 0x10000) >> 0x10));
            Text_DisplayLine((char *)Pvl_Texts[(int)*(short *)((int)&o_00[1].prec + 2)],1,0x82,
                             (long *)0x0);
            t_00 = M_rand();
            D3_PlaySound(o_00,(short)((uint)((t_00 % 3 + 4) * 0x10000) >> 0x10));
            Text_DisplayLine((char *)Pvl_Texts[(int)*(short *)((int)&o_00[1].prec + 2)],4,100,
                             (long *)0x0);
            _DAT_800b1d58 = 0;
            o->display_mode = o->display_mode | 0x10;
            D3_SetCollBits(o,1);
            Task_EventExec(o->handle,-0x2000,0);
            obj = o_01;
          }
        }
        else {
          if (2 < ((uint)Pvl_Prisoner_Status &
                  (uint)((Pvl_Prisoner_Status & 2) != 0) +
                  (uint)((Pvl_Prisoner_Status & 4) != 0) + 1 +
                  (uint)((Pvl_Prisoner_Status & 8) != 0))) {
            _DAT_800b1d58 = 1;
            Text_DisplayLine((char *)Pvl_Texts[(int)*(short *)((int)&o_00[1].prec + 2)],3,100,
                             (long *)0x0);
            MSensor_AddAgression(monst,0x400);
            _DAT_800b1d58 = 0;
            Pvl_Prisoner_Status = Pvl_Prisoner_Status | 0xff00;
            monst->flags = monst->flags | 0x40;
            Pvl_SetStateBits(o_00,8);
            return;
          }
          obj = o;
          if (o_01 != (_D3_OBJECT *)0x0) {
            _DAT_800b1d58 = 1;
            Text_DisplayLine((char *)Pvl_Texts[(int)*(short *)((int)&o_00[1].prec + 2)],2,0x82,
                             (long *)0x0);
            Text_DisplayLine((char *)Pvl_Texts[(int)*(short *)((int)&o_00[1].prec + 2)],4,100,
                             (long *)0x0);
            _DAT_800b1d58 = 0;
            o_01->display_mode = o_01->display_mode | 0x10;
            D3_SetCollBits(o_01,1);
            Task_EventExec(o_01->handle,-0x2000,0);
            obj = o;
          }
        }
        if (obj != (_D3_OBJECT *)0x0) {
          D3_DeleteObject(obj);
        }
        monst->flags = monst->flags | 0x40;
        Pvl_SetStateBits(o_00,8);
      }
      return;
    }
    if (uVar9 != 0) {
      return;
    }
    sVar6 = monst->scriptpos;
    switch(sVar6) {
    case 0:
      TaskCurrent->event_enable = 0;
      uVar11 = monst->sensormask;
      monst->sensormask = 1;
      (o_00->rot).vz = 0x5e0;
      index = rcos(0x5e0);
      iVar10 = rsin((int)(o_00->rot).vz);
      sVar6 = -1;
      Manim_SetAnim(obj_00,3);
      D3_ClearCollBits(o_00,9);
      while (o = Monster_GetChild(o_00,0x4d2), o != (_D3_OBJECT *)0x0) {
        Task_Next();
      }
      D3_SetCollBits(o_00,(long)&DAT_0000200a);
      uVar9 = Boxes_GetHeightPlatform(o_00,(char)o_00 + ',');
      Manim_SetAnim(obj_00,9);
      D3_PlaySound(o_00,2);
      while( true ) {
        sVar2 = (short)((index * 100) / 7 >> 0xc);
        sVar3 = (short)((iVar10 * 100) / 7 >> 0xc);
        if (((int)(obj_00->Env).Obj.vert_top.pad & 0x8000U) != 0) break;
        (o_00->pos).vx = (o_00->pos).vx + sVar2;
        (o_00->pos).vz = (o_00->pos).vz + -1;
        (o_00->pos).vy = (o_00->pos).vy + sVar3;
        Task_Next();
      }
      (obj_00->Env).Obj.normal_top.vx = (obj_00->Env).Obj.normal_top.vx & 0xfffe;
      sVar5 = (o_00->pos).vz;
      while (uVar9 != (int)sVar5) {
        sVar5 = (o_00->pos).vz + sVar6;
        sVar6 = sVar6 + -5;
        (o_00->pos).vz = sVar5;
        (o_00->pos).vx = (o_00->pos).vx + sVar2;
        (o_00->pos).vy = (o_00->pos).vy + sVar3;
        if ((uint)(int)sVar5 < uVar9) {
          (o_00->pos).vz = (short)uVar9;
        }
        Task_Next();
        sVar5 = (o_00->pos).vz;
      }
      D3_ClearCollBits(o_00,(long)&DAT_00002002);
      D3_SetCollBits(o_00,9);
      monst->sensormask = uVar11;
      (obj_00->Env).Obj.normal_top.vx = (obj_00->Env).Obj.normal_top.vx | 1;
      Manim_WaitAnim(obj_00);
      Manim_SetAnim(obj_00,10);
      monst->scriptpos = 1;
    case 1:
      Manim_WaitAnim(obj_00);
      Manim_SetAnim(obj_00,4);
      do {
        if ((LONG_ARRAY_800b2e40[0] != -1) && (LONG_ARRAY_800b2e40[0] < 0xc9)) {
          index = (int)(o_00->pos).vz;
          if ((index + -0x1e <= (int)*(short *)(t_00 + 0x30)) &&
             ((int)*(short *)(t_00 + 0x30) <= index + 200)) goto code_r0x800793d0;
        }
        Task_Next();
      } while( true );
    case 2:
switchD_8007915c_caseD_2:
      Pri_Get_CustomZones(monst,&local_38);
      while (t_00 = Monster_Action_MoveTo
                              ((int)local_38,(int)local_36,(int)local_34,(_D3_OBJECT *)0x0,100,-1,8,
                               -1,-1,-1,0), t_00 == 0) {
        Task_Next();
      }
      Manim_SetAnim(obj_00,4);
      TaskCurrent->event_enable = 0;
      Text_DisplayLine((char *)Pvl_Texts[(int)*(short *)((int)&o_00[1].prec + 2)],3,0x3c,(long *)0x0
                      );
      TaskCurrent->event_enable = 1;
      monst->scriptpos = 3;
    case 3:
      monst->flags = monst->flags | 0x80;
      Manim_SetAnim(obj_00,4);
      if (LONG_ARRAY_800b2e40[0] < 200) {
        Text_DisplayLine((char *)Pvl_Texts[(int)*(short *)((int)&o_00[1].prec + 2)],0,0x5a,
                         (long *)0x0);
        while (LONG_ARRAY_800b2e40[0] < 200) {
          Task_Next();
        }
      }
      p_Var7 = Pvl_EnemyZones + (int)monst->zone_fear;
      sVar6 = p_Var7->x1;
      sVar2 = p_Var7->x2;
      index = (int)p_Var7->y1 + (int)p_Var7->y2 >> 1;
      while (t_00 = Monster_Action_MoveTo
                              ((int)sVar6 + (int)sVar2 >> 1,index,index,(_D3_OBJECT *)0x0,0x3c,-1,7,
                               -1,-1,-1,0), t_00 == 0) {
        Task_Next();
      }
      monst->flags = monst->flags & 0xff7f;
      (o_00->rot).vz = 0x800;
      monst->scriptpos = 4;
    case 4:
      TaskCurrent->event_enable = 0;
      Manim_SetAnim(obj_00,6);
      Manim_WaitAnim(obj_00);
      D3_SetCollBits(o_00,0x10);
      sVar6 = o_00->child[1].pos.vy;
      Pvl_Prisoner_Status = Pvl_Prisoner_Status | 0x80;
      monst->scriptpos = 5;
      Scts_Interruptors = Scts_Interruptors | 1 << ((int)sVar6 + 9U & 0x1f);
    case 5:
      TaskCurrent->event_enable = 1;
      monst->flags = monst->flags | 0x80;
      Manim_SetAnim(obj_00,4);
      if (LONG_ARRAY_800b2e40[0] < 200) {
        Text_DisplayLine((char *)Pvl_Texts[(int)*(short *)((int)&o_00[1].prec + 2)],0,0x5a,
                         (long *)0x0);
        while (LONG_ARRAY_800b2e40[0] < 200) {
          Task_Next();
        }
      }
      iVar10 = 5;
      index = (int)&monst->sensormask + 1;
      Pvl_Prisoner_Status = (ushort)(byte)Pvl_Prisoner_Status;
      do {
        *(undefined *)(index + 0x13c) = 4;
        iVar10 = iVar10 + -1;
        index = index + -1;
      } while (-1 < iVar10);
      TaskCurrent->event_enable = 0;
      monst->flags = monst->flags & 0xff7f;
      Monster_Action_Falling(0xb);
      Manim_SetAnim(obj_00,4);
      D3_ClearCollBits(o_00,9);
      do {
        Task_Next();
      } while( true );
    }
  }
  if (sVar6 == 1) {
LAB_800799ec:
    Manim_SetAnim(obj_00,4);
    t_00 = Monster_Feelings;
    monst->flags = monst->flags | 0x20;
    bVar1 = true;
    while (bVar1) {
      D3_GoToDir(o_00,(int)*(short *)(t_00 + 0x2c) - (int)(o_00->pos).vx,
                 (int)*(short *)(t_00 + 0x2e) - (int)(o_00->pos).vy,(int)monst->monster_speed);
      Task_Next();
      bVar1 = (monst->flags & 0x20U) != 0;
    }
    if ((Pvl_Prisoner_Status & 0xff00) != 0xf00) {
      t_01 = Zone_GetObjectZone(o_00);
      if (t_01 != (_ZONE *)0x0) {
        Track_SetMode(10,(long)t_01);
      }
      _DAT_800b1d58 = 1;
      Manim_SetAnim(obj_00,5);
      index = 0;
      while (sVar6 = Text_AmountOfTexts((char *)Pvl_Texts[(int)*(short *)((int)&o_00[1].prec + 2)]),
            index < (int)sVar6) {
        lVar8 = M_rand();
        D3_PlaySound(o_00,(short)((uint)((lVar8 % 3 + 4) * 0x10000) >> 0x10));
        Text_DisplayLine((char *)Pvl_Texts[(int)*(short *)((int)&o_00[1].prec + 2)],index,0x50,
                         (long *)0x0);
        index = index + 1;
      }
      Manim_WaitAnim(obj_00);
    }
    monst->scriptpos = 2;
  }
  else {
    if (sVar6 < 2) {
      if (sVar6 != 0) goto LAB_80079be0;
      monst->flags = monst->flags | 0x20;
      p_Var7 = Pvl_EnemyZones + (int)monst->zone_fear;
      sVar6 = p_Var7->x1;
      sVar2 = p_Var7->x2;
      sVar3 = p_Var7->y1;
      sVar5 = p_Var7->y2;
      while (t_00 = Monster_Action_MoveTo
                              ((int)sVar6 + (int)sVar2 >> 1,(int)sVar3 + (int)sVar5 >> 1,0,
                               (_D3_OBJECT *)0x0,100,-1,8,-1,-1,-1,0), t_00 == 0) {
        Task_Next();
      }
      monst->scriptpos = 1;
      goto LAB_800799ec;
    }
    if (sVar6 != 2) goto LAB_80079be0;
  }
  _DAT_800b1d58 = 0;
  Pvl_Prisoner_Status = Pvl_Prisoner_Status | 0xc0;
  while (lVar8 = Monster_Action_MoveTo
                           ((int)local_38,(int)local_36,(int)local_34,(_D3_OBJECT *)0x0,200,-1,7,-1,
                            -1,-1,0), lVar8 == 0) {
    Task_Next();
  }
  if (t_01 != (_ZONE *)0x0) {
    Track_SetMode(5,t_00);
  }
LAB_80079be0:
  o_00->display_mode = o_00->display_mode & 0xffef;
  D3_ClearCollBits(o_00,9);
  monst->sensormask = 1;
  do {
    Task_Next();
  } while( true );
code_r0x800793d0:
  Manim_SetAnim(obj_00,5);
  t = Zone_GetObjectZone(o_00);
  if (t != (_ZONE *)0x0) {
    Track_SetMode(10,(long)t);
  }
  _DAT_800b1d58 = 1;
  while (lVar8 = D3_GoToDir(o_00,(int)*(short *)(t_00 + 0x2c) - (int)(o_00->pos).vx,
                            (int)*(short *)(t_00 + 0x2e) - (int)(o_00->pos).vy,
                            (int)monst->monster_speed), lVar8 != 0) {
    Task_Next();
  }
  lVar8 = M_rand();
  D3_PlaySound(o_00,(short)((uint)((lVar8 % 3 + 4) * 0x10000) >> 0x10));
  Text_DisplayLine((char *)Pvl_Texts[(int)*(short *)((int)&o_00[1].prec + 2)],1,0x50,(long *)0x0);
  lVar8 = M_rand();
  D3_PlaySound(o_00,(short)((uint)((lVar8 % 3 + 4) * 0x10000) >> 0x10));
  Text_DisplayLine((char *)Pvl_Texts[(int)*(short *)((int)&o_00[1].prec + 2)],2,0x50,(long *)0x0);
  Manim_WaitAnim(obj_00);
  t = Zone_GetZone((char)t_00 + ',');
  if (t != (_ZONE *)0x0) {
    Track_SetMode(10,(long)t);
  }
  _DAT_800b1d58 = 0;
  TaskCurrent->event_enable = 1;
  monst->scriptpos = 2;
  goto switchD_8007915c_caseD_2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Bos_SetInFront(struct _D3_OBJECT *o /*$s0*/, struct ENEMY_7fake *pos /*$s1*/, long rot /*$s2*/)
 // line 3827, offset 0x80079f6c
	/* begin block 1 */
		// Start line: 8951
	/* end block 1 */
	// End Line: 8952

void Bos_SetInFront(_D3_OBJECT *o,undefined pos,long rot)

{
  int iVar1;
  undefined3 in_register_00000015;
  short *psVar2;
  
  psVar2 = (short *)CONCAT31(in_register_00000015,pos);
  if (o != (_D3_OBJECT *)0x0) {
    do {
      if (o->child != (_D3_OBJECT *)0x0) {
        Bos_SetInFront(o->child,pos,rot);
      }
      if (*(char *)((int)&o[1].pos.vx + 1) == '\x03') {
        (o->pos).vz = psVar2[2] + 100;
        iVar1 = rcos(rot);
        (o->pos).vx = *psVar2 + (short)(iVar1 * 0x96 >> 0xc);
        iVar1 = rsin(rot);
        (o->pos).vy = psVar2[1] + (short)(iVar1 * 0x96 >> 0xc);
      }
      o = o->next;
    } while (o != (_D3_OBJECT *)0x0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Bos_Func_Reflex()
 // line 3845, offset 0x8007a044
	/* begin block 1 */
		// Start line: 3846
		// Start offset: 0x8007A044
		// Variables:
	// 		struct _MONSTER *monst; // $s2
	// 		struct _D3_OBJECT *o; // $s0
	// 		struct _D3_OBJECT *target; // $s3
	// 		long tmp; // $s1
	/* end block 1 */
	// End offset: 0x8007A520
	// End Line: 3944

	/* begin block 2 */
		// Start line: 8989
	/* end block 2 */
	// End Line: 8990

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Bos_Func_Reflex(void)

{
  ushort uVar1;
  long lVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  _D3_OBJECT *p_Var6;
  _D3_OBJECT *o;
  _MONSTER *monst;
  
  lVar5 = Monster_Feelings;
  monst = (_MONSTER *)TaskCurrent->local;
  o = monst->obj;
  if (((monst->flags & 0x80U) == 0) || (LONG_ARRAY_800b2e40[0] == -1)) {
    monst->sensormask = monst->sensormask | 0xf0000;
  }
  else {
    monst->sensormask = monst->sensormask & 0xfffcffff;
    lVar2 = Direction((int)*(short *)(lVar5 + 0x2c) - (int)(o->pos).vx,
                      (int)*(short *)(lVar5 + 0x2e) - (int)(o->pos).vy);
    if ((((lVar2 - (int)(o->rot).vz) + 0x300U & 0xfff) < 0x600) && (LONG_ARRAY_800b2e40[0] < 200)) {
      if (monst->t_move != (TASK *)0x0) {
        monst->t_move->event_enable = 1;
      }
      Monster_StopAllActions(monst);
      Monster_AddAction(monst,1,0x11,0,0);
    }
  }
  if (((o->father != (_D3_OBJECT *)0x0) && (p_Var6 = o->father->father, p_Var6 != (_D3_OBJECT *)0x0)
      ) && ((monst->flags & 0x40U) == 0)) {
    Bos_SetInFront(p_Var6->child,(char)o + ',',(int)(o->rot).vz);
  }
  if (((int)(uint)(ushort)o[1].pos.vz >> 0xe == 2) && ((monst->flags & 0x40U) == 0)) {
    uVar3 = Direction((int)*(short *)(lVar5 + 0x2c) - (int)(o->pos).vx,
                      (int)*(short *)(lVar5 + 0x2e) - (int)(o->pos).vy);
    if (o->child != (_D3_OBJECT *)0x0) {
      iVar4 = rcos(uVar3);
      (o->child->pos).vx = (o->pos).vx + (short)(iVar4 * 100 >> 0xc);
      iVar4 = rsin(uVar3);
      (o->child->pos).vy = (o->pos).vy + (short)(iVar4 * 100 >> 0xc);
    }
    if (o->next != (_D3_OBJECT *)0x0) {
      iVar4 = rcos(uVar3);
      (o->next->pos).vx = (o->pos).vx + (short)(iVar4 * 100 >> 0xc);
      iVar4 = rsin(uVar3);
      (o->next->pos).vy = (o->pos).vy + (short)(iVar4 * 100 >> 0xc);
    }
    if (o->prec != (_D3_OBJECT *)0x0) {
      iVar4 = rcos(uVar3);
      (o->prec->pos).vx = (o->pos).vx + (short)(iVar4 * 100 >> 0xc);
      iVar4 = rsin(uVar3);
      (o->prec->pos).vy = (o->pos).vy + (short)(iVar4 * 100 >> 0xc);
    }
  }
  lVar5 = Task_EventRead(TaskCurrent);
  if (lVar5 == 2) {
    uVar1 = monst->flags & 0xffdf;
  }
  else {
    uVar1 = monst->flags | 0x20;
  }
  monst->flags = uVar1;
  if ((((monst->flags & 0x20U) == 0) && (monst->scriptpos == 4)) &&
     ((((int)o[1].pos.vz & 0xc000U) == 0 &&
      (((monst->action != 1 && (monst->action != 0xf)) && ((o->collision_mode & 0x10U) == 0)))))) {
    Monster_StopAllActions(monst);
    Monster_AddAction(monst,0,0xf,0,0);
    monst->actionmask = 0;
  }
  if ((Pvl_Prisoner_Status & 0xff00) == 0xff00) {
    if (monst->action == 0x11) {
      Monster_StopAllActions(monst);
      Monster_AddAction(monst,0,5,0,0);
    }
    if (((LONG_ARRAY_800b2e40[0] != -1) && (LONG_ARRAY_800b2e40[0] < 2000)) &&
       ((monst->action != 0xb && (LONG_ARRAY_800b2e40[0] < 100)))) {
      Monster_StopAllActions(monst);
      Monster_AddAction(monst,0,0xb,0,0);
      return;
    }
  }
  else {
    if ((2 < ((uint)Pvl_Prisoner_Status &
             (uint)((Pvl_Prisoner_Status & 2) != 0) + (uint)((Pvl_Prisoner_Status & 4) != 0) + 1 +
             (uint)((Pvl_Prisoner_Status & 8) != 0))) &&
       (lVar5 = Pvl_TestStateBits(o,8), lVar5 != 0)) {
      Pvl_Prisoner_Status = Pvl_Prisoner_Status | 0xff00;
      MSensor_AddAgression(monst,0x400);
    }
  }
  if (LONG_ARRAY_800b2e48[0] != -1) {
    Pvl_Prisoner_Status = Pvl_Prisoner_Status | 0xff00;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Bos_Func_Decisions()
 // line 3947, offset 0x8007a53c
	/* begin block 1 */
		// Start line: 3948
		// Start offset: 0x8007A53C
		// Variables:
	// 		struct _MONSTER *monst; // $s0
	/* end block 1 */
	// End offset: 0x8007A618
	// End Line: 3970

	/* begin block 2 */
		// Start line: 9202
	/* end block 2 */
	// End Line: 9203

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Bos_Func_Decisions(void)

{
  long action;
  _MONSTER *monst;
  
  monst = (_MONSTER *)TaskCurrent->local;
  if ((monst->flags & 0x40U) == 0) {
    if ((Pvl_Prisoner_Status & 0xff00) == 0xff00) {
      action = Pvl_TestStateBits(monst->obj,8);
      if (action != 0) {
        return;
      }
      if (((monst->flags & 0x20U) == 0) && (((int)monst->obj[1].pos.vz & 0xc000U) == 0)) {
        return;
      }
      Monster_StopAllActions(monst);
      action = 0x11;
    }
    else {
      if (LONG_ARRAY_800b2e2c[0] == -1) {
        return;
      }
      Monster_StopAllActions(monst);
      action = 5;
    }
    Monster_AddAction(monst,0,action,0,0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Bos_Task_Action()
 // line 3973, offset 0x8007a628
	/* begin block 1 */
		// Start line: 3974
		// Start offset: 0x8007A628
		// Variables:
	// 		struct ENEMY_104fake t; // stack offset -56
	// 		struct _MONSTER *monst; // $s1
	// 		struct _D3_OBJECT *o; // $s2
	// 		struct M_OBJECT *mo; // $s3
	// 		long tmp; // $s0
	/* end block 1 */
	// End offset: 0x8007ABAC
	// End Line: 4107

	/* begin block 2 */
		// Start line: 9256
	/* end block 2 */
	// End Line: 9257

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Bos_Task_Action(void)

{
  _D3_OBJECT *p_Var1;
  long lVar2;
  uint uVar3;
  int iVar4;
  _MONSTER *monst;
  _D3_OBJECT *o;
  M_OBJECT *obj;
  undefined auStack56 [32];
  
  monst = (_MONSTER *)TaskCurrent->local;
  o = monst->obj;
  obj = (M_OBJECT *)o->description;
  Text_SetContext((TEXT_102fake *)auStack56);
  Text_SetContextFont(0x70);
  Text_SetContextXY(0,0);
  Text_SetContextWH(0x140,0xf0);
  Text_SetContextRange(0);
  Text_SetContextMode(0);
  monst->hurtsound = 3;
  D3_ClearCollBits(o,0x10);
  monst->monster_speed = 0x40;
  uVar3 = (int)(uint)(ushort)o[1].pos.vz >> 0xe;
  Pvl_Prisoner_Status = (ushort)(byte)Pvl_Prisoner_Status;
  if (uVar3 == 1) {
    if ((Pvl_Prisoner_Status & 0xc0) != 0x80) {
      o->display_mode = o->display_mode & 0xffef;
      D3_ClearCollBits(o,9);
      monst->sensormask = 1;
      do {
        Task_Next();
      } while( true );
    }
  }
  else {
    if (uVar3 < 2) {
      if (uVar3 == 0) {
        p_Var1 = Monster_GetChild(o,0x4d2);
        if (p_Var1 == (_D3_OBJECT *)0x0) {
          monst->scriptpos = 3;
        }
        if ((Pvl_Prisoner_Status & 0x80) != 0) {
          o->display_mode = o->display_mode & 0xffef;
          D3_ClearCollBits(o,9);
          monst->sensormask = 1;
          do {
            Task_Next();
          } while( true );
        }
      }
    }
    else {
      if ((uVar3 == 2) && ((Pvl_Prisoner_Status & 0xe0) != 0xc0)) {
        o->display_mode = o->display_mode & 0xffef;
        D3_ClearCollBits(o,9);
        monst->sensormask = 1;
        do {
          Task_Next();
        } while( true );
      }
    }
  }
  monst->sensormask = monst->sensormask | 0x8000000;
  if (((monst->flags & 0x40U) == 0) && (lVar2 = Pvl_TestStateBits(o,8), lVar2 == 0)) {
    Monster_ForceAction(monst,0x11,0);
  }
  lVar2 = Task_EventWait();
  monst->action = (short)lVar2;
  TaskCurrent->event_enable = 1;
  *(undefined *)((int)&o[1].pos.vx + 1) = 0xff;
  do {
    switch((int)(((uint)(ushort)monst->action - 1) * 0x10000) >> 0x10) {
    case 0:
      Monster_Action_WaitRun(monst,4,8,100,0,5);
      monst->actionmask = 0;
      break;
    case 1:
      Monster_Action_Hit(2,9,1,2);
      monst->actionmask = 0;
      break;
    case 4:
      if ((o[1].pos.vz & 0x200U) == 0) {
        Monster_Action_MoveTo(0,0,0,(_D3_OBJECT *)Monster_Feelings,0x32,-1,7,-1,-1,-1,0);
      }
      if (((monst->flags & 0x40U) != 0) || (lVar2 = Pvl_TestStateBits(monst->obj,8), lVar2 != 0))
      goto switchD_8007a878_caseD_2;
      Monster_ForceAction(monst,0x11,0);
      monst->actionmask = 0;
      break;
    case 10:
      *(undefined *)((int)&o[1].pos.vx + 1) = 0xf3;
      Manim_SetAnim(obj,4);
      while (lVar2 = D3_GoToDir(o,(int)*(short *)(Monster_Feelings + 0x2c) - (int)(o->pos).vx,
                                (int)*(short *)(Monster_Feelings + 0x2e) - (int)(o->pos).vy,0xa0),
            lVar2 != 0) {
        Task_Next();
      }
      uVar3 = M_rand();
      Monster_Action_Slaying((uint)((uVar3 & 1) == 0),0x78,(_D3_OBJECT *)Monster_Feelings,1);
      Manim_SetAnim(obj,4);
      (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
      iVar4 = 0;
      if (monst->timer_agression >> 1 < 1) goto switchD_8007a878_caseD_2;
      do {
        iVar4 = iVar4 + 1;
        Task_Next();
      } while (iVar4 < monst->timer_agression >> 1);
      monst->actionmask = 0;
      break;
    case 0xe:
      monst->busy = 0;
      monst->mode = 0x10;
      Manim_SetAnim(obj,4);
      TaskCurrent->event_enable = 0;
      Text_DisplayLine((char *)Pvl_Texts[(int)*(short *)((int)&o[1].prec + 2)],0,0x78,(long *)0x0);
      TaskCurrent->event_enable = 1;
      while ((monst->flags & 0x20U) == 0) {
        Task_Next();
      }
      Monster_StopAllActions(monst);
      Monster_AddAction(monst,0,0x11,0,0);
      monst->actionmask = 0;
      break;
    case 0x10:
      PrisBoss_Scripting();
      monst->actionmask = 0;
      break;
    case 0x1e:
      MSpell_SpellTesting(monst,TaskCurrent->event_param,-1,4);
    default:
switchD_8007a878_caseD_2:
      monst->actionmask = 0;
    }
    monst->busy = -1;
    Task_Next();
    if (monst->mode == 0x11) {
      Pvl_Prisoner_Status = Pvl_Prisoner_Status | 0xe0;
      if (Pvl_SectorNumber == 5) {
        Monster_ReleaseBonuses();
        monst->actionmask = 0x10000000;
        Manim_SetEffect(obj,(TDRFuncPtr_Manim_SetEffect1f)0x0);
        (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
        monst->mode = 0;
        Pvl_SetStateBits(o,2);
        D3_ClearCollBits(o,0xb);
      }
      else {
        Monster_ReleaseBonuses();
      }
      return;
    }
    Monster_ForceAction(monst,1,0);
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Haq_Func_Reflex()
 // line 4132, offset 0x8007abcc
	/* begin block 1 */
		// Start line: 4133
		// Start offset: 0x8007ABCC
		// Variables:
	// 		struct _MONSTER *monst; // $s0
	// 		struct _D3_OBJECT *o; // $s1
	// 		struct _D3_OBJECT *target; // $a2
	// 		struct _D3_OBJECT *tmpobj; // $v0
	// 		long tmp; // $s2
	/* end block 1 */
	// End offset: 0x8007AD3C
	// End Line: 4190

	/* begin block 2 */
		// Start line: 9602
	/* end block 2 */
	// End Line: 9603

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Haq_Func_Reflex(void)

{
  _PLATFORM *p_Var1;
  short sVar2;
  long param1;
  _MONSTER *monst;
  _D3_OBJECT *o;
  
  param1 = LONG_ARRAY_800b2e40[0];
  monst = (_MONSTER *)TaskCurrent->local;
  o = monst->obj;
  if ((monst->flags & 0x20U) != 0) {
    D3_GoToDir(o,(int)*(short *)(Monster_Feelings + 0x2c) - (int)(o->pos).vx,
               (int)*(short *)(Monster_Feelings + 0x2e) - (int)(o->pos).vy,100);
  }
  if ((monst->flags & 0x80U) == 0) {
    if ((monst->flags & 0x20U) == 0) {
      p_Var1 = Plat_GetPlat((char)o + ',');
      sVar2 = *(short *)&p_Var1[1].obj.prec + p_Var1[1].obj.pos.vy + -0x32;
      (o->last_pos).vz = sVar2;
      (o->pos).vz = sVar2;
    }
    if (param1 != -1) {
      if (param1 < 800) {
        if ((monst->flags & 0x20U) != 0) {
          if (monst->timer != 0) {
            monst->timer = monst->timer + -1;
            return;
          }
          Monster_StopAllActions(monst);
          Monster_AddAction(monst,0,0xc,0,0);
          monst->timer = *(short *)&monst->timer_agression;
          return;
        }
        Monster_StopAllActions(monst);
        param1 = 1;
      }
      else {
        if ((monst->flags & 0x20U) == 0) {
          return;
        }
        if (param1 < 0x3e9) {
          return;
        }
        Monster_StopAllActions(monst);
        param1 = 0;
      }
      Monster_AddAction(monst,0,0xe,param1,0);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Haq_Task_Action()
 // line 4193, offset 0x8007ad54
	/* begin block 1 */
		// Start line: 4194
		// Start offset: 0x8007AD54
		// Variables:
	// 		struct ENEMY_8fake col; // stack offset -40
	// 		struct ENEMY_7fake pos; // stack offset -32
	// 		struct _MONSTER *monst; // $s1
	// 		struct _D3_OBJECT *o; // $s0
	// 		struct M_OBJECT *mo; // $s2
	// 		struct _D3_OBJECT *tmpobj; // $v0
	// 		long x; // $s0
	// 		long y; // $t0
	// 		long oldz; // $s3
	/* end block 1 */
	// End offset: 0x8007B1C4
	// End Line: 4320

	/* begin block 2 */
		// Start line: 9737
	/* end block 2 */
	// End Line: 9738

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Haq_Task_Action(void)

{
  short sVar1;
  short sVar2;
  short sVar3;
  TASK *pTVar4;
  _PLATFORM *p_Var5;
  long lVar6;
  uint uVar7;
  _ENEMYZONE *p_Var8;
  short sVar9;
  _D3_OBJECT *o;
  _MONSTER *monst;
  M_OBJECT *obj;
  
  monst = (_MONSTER *)TaskCurrent->local;
  o = monst->obj;
  obj = (M_OBJECT *)o->description;
  p_Var5 = Plat_GetPlat((char)o + ',');
  sVar9 = *(short *)&p_Var5[1].obj.prec + p_Var5[1].obj.pos.vy + -0x32;
  (o->last_pos).vz = sVar9;
  (o->pos).vz = sVar9;
  monst->hurtsound = 0;
  monst->monster_speed = 0x1e;
  monst->monster_trans = 0x200;
  monst->timer = 0x1e;
  monst->flags = monst->flags & 0xff1f;
  lVar6 = Task_EventWait();
  pTVar4 = TaskCurrent;
  monst->action = (short)lVar6;
  pTVar4->event_enable = 1;
  do {
    pTVar4 = TaskCurrent;
    switch((int)(((uint)(ushort)monst->action - 1) * 0x10000) >> 0x10) {
    case 0:
      monst->busy = 0;
      monst->mode = 0x10;
      do {
        while (Manim_SetAnim(obj,0), (monst->flags & 0x20U) != 0) {
          Manim_SetAnim(obj,1);
          Manim_WaitAnim(obj);
        }
        uVar7 = M_rand();
        if ((uVar7 & 1) == 0) {
          sVar9 = monst->zone_wait->x2;
        }
        else {
          sVar9 = monst->zone_wait->x1;
        }
        sVar1 = monst->zone_wait->x1;
        sVar2 = monst->zone_wait->x2;
        uVar7 = M_rand();
        if ((uVar7 & 1) == 0) {
          sVar3 = monst->zone_wait->y2;
          p_Var8 = monst->zone_wait;
        }
        else {
          p_Var8 = monst->zone_wait;
          sVar3 = p_Var8->y1;
        }
        Monster_Action_MoveTo
                  ((int)sVar9 + ((int)sVar1 + (int)sVar2 >> 1) >> 1,
                   (int)sVar3 + ((int)p_Var8->y1 + (int)p_Var8->y2 >> 1) >> 1,-0x5dc,
                   (_D3_OBJECT *)0x0,100,-1,0,-1,-1,-1,-1);
        Task_Next();
      } while( true );
    case 1:
      lVar6 = Monster_Action_Hit(-1,-1,1,-1);
      if (lVar6 != 0) {
        D3_ClearCollBits(monst->obj,(long)&DAT_00004011);
        D3_PlaySound(o,0);
        monst->mode = 0x11;
        Manim_SetAnim(obj,3);
        (obj->Env).Obj.normal_top.vy = 0;
        Manim_WaitEvent(obj,0x4000);
        Manim_SetAnim(obj,4);
        (obj->Env).Obj.normal_top.vy = 0;
        Manim_WaitAnim(obj);
        Manim_SetAnim(obj,5);
        while (sVar9 < (o->pos).vz) {
          (o->pos).vz = (o->pos).vz + -5;
          Task_Next();
        }
        while ((o->pos).vz < sVar9) {
          (o->pos).vz = (o->pos).vz + 1;
          Task_Next();
        }
        do {
          (o->rot).vz = (o->rot).vz + 1;
          Task_Next();
        } while( true );
      }
      break;
    case 0xb:
      D3_SetCollBits(o,(long)&DAT_00004019);
      Monster_Action_Shooting(-1,-1,2,8,1,0x87,0,1,1);
      monst->actionmask = 0;
      goto LAB_8007b190;
    case 0xd:
      monst->flags = monst->flags | 0x80;
      if (pTVar4->event_param == 0) {
        Manim_SetAnim(obj,7);
        SFX_ShockWave(2,0xe0,0xd8,0x1f);
        D3_PlaySound(o,2);
        Manim_WaitAnim(obj);
        monst->flags = monst->flags & 0xffdf;
        (o->last_pos).vz = sVar9;
        (o->pos).vz = sVar9;
      }
      else {
        Manim_SetAnim(obj,6);
        SFX_ShockWave(2,0xe0,0xd8,0x1f);
        D3_PlaySound(o,2);
        Manim_WaitAnim(obj);
        monst->flags = monst->flags | 0x20;
      }
      monst->flags = monst->flags & 0xff7f;
      break;
    case 0x1e:
      MSpell_SpellTesting(monst,TaskCurrent->event_param,-1,1);
    }
    monst->actionmask = 0;
LAB_8007b190:
    monst->busy = -1;
    Task_Next();
    if (monst->mode == 0x11) {
      Monster_ReleaseBonuses();
      return;
    }
    Monster_ForceAction(monst,1,0);
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Rat_Func_Reflex()
 // line 4346, offset 0x8007b1ec
	/* begin block 1 */
		// Start line: 4347
		// Start offset: 0x8007B1EC
		// Variables:
	// 		struct _MONSTER *monst; // $s2
	// 		struct _D3_OBJECT *target; // $s1
	// 		struct M_OBJECT *mo_obj; // $s4
	// 		struct _D3_OBJECT *o; // $s0
	// 		struct M_OBJECT *mo; // $s3
	// 		long angle; // $a0
	/* end block 1 */
	// End offset: 0x8007B304
	// End Line: 4383

	/* begin block 2 */
		// Start line: 10082
	/* end block 2 */
	// End Line: 10083

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Rat_Func_Reflex(void)

{
  short sVar1;
  long lVar2;
  short sVar3;
  long lVar4;
  _D3_OBJECT *p_Var5;
  _MONSTER *monst;
  void *pvVar6;
  int iVar7;
  
  lVar2 = Monster_Feelings;
  monst = (_MONSTER *)TaskCurrent->local;
  iVar7 = *(int *)(Monster_Feelings + 0x24);
  p_Var5 = monst->obj;
  pvVar6 = p_Var5->description;
  lVar4 = Monster_Reflex_Fear(monst);
  if (lVar4 != 0) {
    return;
  }
  lVar4 = Direction((int)(p_Var5->pos).vx - (int)*(short *)(lVar2 + 0x2c),
                    (int)(p_Var5->pos).vy - (int)*(short *)(lVar2 + 0x2e));
  sVar1 = *(short *)(lVar2 + 0x40);
  if ((*(ushort *)(lVar2 + 0x1c) & 0x1000) != 0) {
    sVar3 = *(short *)(iVar7 + 0x16);
    if (sVar3 == 0x5d) {
      sVar3 = 0x80;
LAB_8007b2b4:
      monst->monster_trans = sVar3;
    }
    else {
      if (sVar3 == 99) {
        sVar3 = 0xc0;
        goto LAB_8007b2b4;
      }
      monst->monster_trans = 0x40;
      sVar3 = 0x100;
      if (((lVar4 - (int)sVar1) + 0x400U & 0xfff) < 0x800) goto LAB_8007b2b4;
    }
    if (*(short *)((int)pvVar6 + 0x16) != 3) goto LAB_8007b2f4;
    *(short *)((int)pvVar6 + 0x2a) = monst->monster_trans;
  }
  if (*(short *)((int)pvVar6 + 0x16) == 3) {
    *(short *)((int)pvVar6 + 0x2a) = monst->monster_trans;
  }
LAB_8007b2f4:
  Monster_Reflex_SmallBeastAttack(monst,0xa0);
  Monster_Reflex_Feasting(monst);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Rat_Task_Action()
 // line 4386, offset 0x8007b324
	/* begin block 1 */
		// Start line: 4387
		// Start offset: 0x8007B324
		// Variables:
	// 		struct _MONSTER *monst; // $s1
	// 		struct _D3_OBJECT *o; // $s3
	// 		struct M_OBJECT *mo; // $s4
	// 		struct ENEMY_7fake pos; // stack offset -48
	// 		long tmp; // $s0
	/* end block 1 */
	// End offset: 0x8007B5C0
	// End Line: 4451

	/* begin block 2 */
		// Start line: 10165
	/* end block 2 */
	// End Line: 10166

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Rat_Task_Action(void)

{
  TASK *pTVar1;
  long lVar2;
  int iVar3;
  _MONSTER *monst;
  _D3_OBJECT *o;
  M_OBJECT *obj;
  
  monst = (_MONSTER *)TaskCurrent->local;
  o = monst->obj;
  obj = (M_OBJECT *)o->description;
  monst->monster_trans = 0x80;
  monst->hurtsound = 0;
  monst->fleesound = 0;
  monst->monster_speed = 0x100;
  lVar2 = Task_EventWait();
  pTVar1 = TaskCurrent;
  monst->action = (short)lVar2;
  pTVar1->event_enable = 1;
  do {
    switch((int)(((uint)(ushort)monst->action - 1) * 0x10000) >> 0x10) {
    case 0:
      Monster_Action_WaitRun(monst,0,3,100,0,2);
      monst->actionmask = 0;
      break;
    case 1:
      Monster_Action_Hit(5,6,1,1);
      monst->actionmask = 0;
      break;
    case 4:
      if ((o[1].pos.vz & 0x200U) != 0) goto switchD_8007b3d4_caseD_2;
      Monster_Action_MoveTo(0,0,0,(_D3_OBJECT *)Monster_Feelings,100,-1,3,-1,-1,-1,-1);
      monst->actionmask = 0;
      break;
    case 10:
      Manim_SetAnim(obj,2);
      Manim_WaitAnim(obj);
      monst->mode = 7;
      D3_PlaySound(o,0);
      Monster_Action_SlayDirection(o,4,0xaa,(_D3_OBJECT *)Monster_Feelings,monst,-1);
      monst->mode = 1;
      Manim_SetAnim(obj,2);
      iVar3 = 0;
      if (monst->timer_agression >> 1 < 1) goto switchD_8007b3d4_caseD_2;
      do {
        iVar3 = iVar3 + 1;
        Task_Next();
      } while (iVar3 < monst->timer_agression >> 1);
      monst->actionmask = 0;
      break;
    case 0xd:
      Monster_Action_Feast(o,(_D3_OBJECT *)TaskCurrent->event_param,3,1,2,-1);
      monst->actionmask = 0;
      break;
    case 0x14:
      Monster_Action_Flee(monst,3,0,-1);
    default:
switchD_8007b3d4_caseD_2:
      monst->actionmask = 0;
      break;
    case 0x1d:
      Monster_Action_Fear(monst,0,3,100,2);
      monst->actionmask = 0;
      break;
    case 0x1e:
      MSpell_SpellTesting(monst,TaskCurrent->event_param,-1,0);
      monst->actionmask = 0;
    }
    monst->busy = -1;
    Task_Next();
    if (monst->mode == 0x11) {
      Monster_ReleaseBonuses();
      return;
    }
    Monster_ForceAction(monst,1,0);
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Spider_Func_Reflex()
 // line 4480, offset 0x8007b5f4
	/* begin block 1 */
		// Start line: 4481
		// Start offset: 0x8007B5F4
		// Variables:
	// 		struct _MONSTER *monst; // $s1
	// 		struct _D3_OBJECT *target; // $s0
	// 		struct M_OBJECT *mo_obj; // $s2
	// 		struct _D3_OBJECT *o; // $v0
	// 		struct M_OBJECT *mo; // $s3
	// 		long tmp; // $v0
	// 		long angle; // $a0
	/* end block 1 */
	// End offset: 0x8007B768
	// End Line: 4528

	/* begin block 2 */
		// Start line: 10392
	/* end block 2 */
	// End Line: 10393

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Spider_Func_Reflex(void)

{
  long lVar1;
  short sVar2;
  _D3_OBJECT *p_Var3;
  long lVar4;
  uint uVar5;
  _MONSTER *monst;
  int iVar6;
  void *pvVar7;
  
  lVar1 = Monster_Feelings;
  monst = (_MONSTER *)TaskCurrent->local;
  p_Var3 = monst->obj;
  iVar6 = *(int *)(Monster_Feelings + 0x24);
  pvVar7 = p_Var3->description;
  lVar4 = Direction((int)(p_Var3->pos).vx - (int)*(short *)(Monster_Feelings + 0x2c),
                    (int)(p_Var3->pos).vy - (int)*(short *)(Monster_Feelings + 0x2e));
  uVar5 = (lVar4 - (int)*(short *)(lVar1 + 0x40)) + 0x400U & 0xfff;
  if ((*(ushort *)(lVar1 + 0x1c) & 0x1000) == 0) goto LAB_8007b6c4;
  sVar2 = *(short *)(iVar6 + 0x16);
  if (sVar2 == 0x5d) {
    sVar2 = 0x400;
LAB_8007b6a4:
    monst->monster_trans = sVar2;
  }
  else {
    if (sVar2 == 99) {
      sVar2 = 0x800;
      goto LAB_8007b6a4;
    }
    monst->monster_trans = 0x200;
    sVar2 = 0x800;
    if (uVar5 < 0x800) goto LAB_8007b6a4;
  }
  if (*(short *)((int)pvVar7 + 0x16) == 2) {
    *(short *)((int)pvVar7 + 0x2a) = monst->monster_trans;
  }
LAB_8007b6c4:
  sVar2 = monst->timer;
  if ((((monst->timer == 0) || (monst->timer = sVar2 + -1, sVar2 == 1)) && (LONG_800b2e38 != -1)) &&
     ((((monst->obj->collision_state & 0x80U) != 0 && (monst->mode != 0xd)) &&
      ((LONG_ARRAY_800b2e40[0] - 0x12dU < 699 && (uVar5 < 0x800)))))) {
    Monster_ResetActions(monst);
    Monster_AddAction(monst,0,0xc,0,0);
  }
  Monster_Reflex_SmallBeastAttack(monst,200);
  Monster_Reflex_Feasting(monst);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Spider_Task_Action()
 // line 4533, offset 0x8007b798
	/* begin block 1 */
		// Start line: 4534
		// Start offset: 0x8007B798
		// Variables:
	// 		struct _MONSTER *monst; // $s0
	// 		struct _D3_OBJECT *o; // $s2
	// 		struct M_OBJECT *mo; // $s1
	// 		struct ENEMY_7fake pos; // stack offset -40
	/* end block 1 */
	// End offset: 0x8007BA50
	// End Line: 4595

	/* begin block 2 */
		// Start line: 10509
	/* end block 2 */
	// End Line: 10510

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Spider_Task_Action(void)

{
  TASK *pTVar1;
  long lVar2;
  _MONSTER *monst;
  M_OBJECT *obj;
  _D3_OBJECT *o;
  
  monst = (_MONSTER *)TaskCurrent->local;
  o = monst->obj;
  obj = (M_OBJECT *)o->description;
  monst->monster_trans = 0x800;
  monst->fleesound = 0;
  monst->monster_speed = 100;
  lVar2 = Task_EventWait();
  pTVar1 = TaskCurrent;
  monst->action = (short)lVar2;
  pTVar1->event_enable = 1;
  do {
    switch((int)(((uint)(ushort)monst->action - 1) * 0x10000) >> 0x10) {
    case 0:
      Monster_Action_WaitRun(monst,0,2,100,0,2);
      monst->actionmask = 0;
      break;
    case 1:
      Monster_Action_Hit(5,6,1,1);
      monst->actionmask = 0;
      break;
    default:
      goto switchD_8007b838_caseD_2;
    case 4:
      if ((o[1].pos.vz & 0x200U) != 0) goto switchD_8007b838_caseD_2;
      Monster_Action_MoveTo(0,0,0,(_D3_OBJECT *)Monster_Feelings,100,-1,2,-1,-1,-1,-1);
      monst->actionmask = 0;
      break;
    case 10:
      Manim_SetAnim(obj,0);
      Manim_WaitAnim(obj);
      monst->mode = 7;
      D3_PlaySound(o,0);
      Monster_Action_SlayDirection(o,3,0xdc,(_D3_OBJECT *)Monster_Feelings,monst,-1);
      monst->mode = 1;
      if (((o[1].pos.vz & 0x400U) != 0) || (monst->timer_agression == 0))
      goto switchD_8007b838_caseD_2;
      Manim_SetAnim(obj,0);
      Manim_WaitAnim(obj);
      Manim_SetAnim(obj,0);
      Manim_WaitAnim(obj);
      monst->actionmask = 0;
      break;
    case 0xb:
      Monster_Action_Shooting(-1,-1,4,7,1,200,0,1,7);
      monst->timer = *(short *)&monst->timer_agression;
      goto switchD_8007b838_caseD_2;
    case 0xd:
      Monster_Action_Feast(o,(_D3_OBJECT *)TaskCurrent->event_param,2,1,2,6);
      monst->actionmask = 0;
      break;
    case 0x14:
      Monster_Action_Flee(monst,2,0,-1);
switchD_8007b838_caseD_2:
      monst->actionmask = 0;
      break;
    case 0x1e:
      MSpell_SpellTesting(monst,TaskCurrent->event_param,-1,0);
      monst->actionmask = 0;
    }
    monst->busy = -1;
    Task_Next();
    if (monst->mode == 0x11) {
      Monster_ReleaseBonuses();
      return;
    }
    Monster_ForceAction(monst,1,0);
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Com_Func_Reflex()
 // line 4624, offset 0x8007ba7c
	/* begin block 1 */
		// Start line: 4625
		// Start offset: 0x8007BA7C
		// Variables:
	// 		struct _MONSTER *monst; // $s0
	/* end block 1 */
	// End offset: 0x8007BAB0
	// End Line: 4630

	/* begin block 2 */
		// Start line: 10710
	/* end block 2 */
	// End Line: 10711

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Com_Func_Reflex(void)

{
  long lVar1;
  _MONSTER *monst;
  
  monst = (_MONSTER *)TaskCurrent->local;
  lVar1 = Monster_Reflex_Fear(monst);
  if (lVar1 == 0) {
    Monster_ReflexCombat(monst,100,monst->timer_agression);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Com_Task_Action()
 // line 4633, offset 0x8007bac0
	/* begin block 1 */
		// Start line: 4634
		// Start offset: 0x8007BAC0
		// Variables:
	// 		struct _MONSTER *monst; // $s1
	// 		struct _D3_OBJECT *o; // $s2
	// 		struct M_OBJECT *mo; // $s4
	// 		long tmp; // $s0
	/* end block 1 */
	// End offset: 0x8007BD4C
	// End Line: 4679

	/* begin block 2 */
		// Start line: 10729
	/* end block 2 */
	// End Line: 10730

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Com_Task_Action(void)

{
  TASK *pTVar1;
  long lVar2;
  int iVar3;
  _MONSTER *monst;
  _D3_OBJECT *o;
  M_OBJECT *obj;
  
  monst = (_MONSTER *)TaskCurrent->local;
  o = monst->obj;
  obj = (M_OBJECT *)o->description;
  monst->hurtsound = 3;
  lVar2 = Task_EventWait();
  pTVar1 = TaskCurrent;
  monst->action = (short)lVar2;
  pTVar1->event_enable = 1;
  do {
    switch((int)(((uint)(ushort)monst->action - 1) * 0x10000) >> 0x10) {
    case 0:
      Monster_Action_WaitRun(monst,0,1,100,0,5);
      monst->actionmask = 0;
      break;
    case 1:
      Monster_Action_Hit(8,9,1,1);
      monst->actionmask = 0;
      break;
    case 4:
      if ((o[1].pos.vz & 0x200U) != 0) goto switchD_8007bb54_caseD_2;
      Monster_Action_MoveTo(0,0,0,(_D3_OBJECT *)Monster_Feelings,100,-1,2,-1,-1,-1,-1);
      monst->actionmask = 0;
      break;
    case 10:
      while (lVar2 = D3_GoToDir(o,(int)*(short *)(Monster_Feelings + 0x2c) - (int)(o->pos).vx,
                                (int)*(short *)(Monster_Feelings + 0x2e) - (int)(o->pos).vy,0xa0),
            lVar2 != 0) {
        Task_Next();
      }
      Monster_Action_Slaying(6,0x78,(_D3_OBJECT *)Monster_Feelings,0);
      Manim_SetAnim(obj,0);
      iVar3 = 0;
      if (monst->timer_agression >> 1 < 1) goto switchD_8007bb54_caseD_2;
      do {
        iVar3 = iVar3 + 1;
        Task_Next();
      } while (iVar3 < monst->timer_agression >> 1);
      monst->actionmask = 0;
      break;
    case 0xb:
      Monster_Action_Shooting(-1,-1,7,0xe,1,0x96,0,monst->timer_agression,4);
      monst->actionmask = 0;
      break;
    case 0x1d:
      Monster_Action_Fear(monst,0,2,100,2);
      monst->actionmask = 0;
      break;
    case 0x1e:
      MSpell_SpellTesting(monst,TaskCurrent->event_param,-1,0);
    default:
switchD_8007bb54_caseD_2:
      monst->actionmask = 0;
    }
    monst->busy = -1;
    Task_Next();
    if (monst->mode == 0x11) {
      Monster_ReleaseBonuses();
      return;
    }
    Monster_ForceAction(monst,1,0);
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Skeleton_Func_Reflex()
 // line 4709, offset 0x8007bd78
	/* begin block 1 */
		// Start line: 4710
		// Start offset: 0x8007BD78
		// Variables:
	// 		struct _MONSTER *monst; // $s0
	/* end block 1 */
	// End offset: 0x8007BDFC
	// End Line: 4727

	/* begin block 2 */
		// Start line: 10887
	/* end block 2 */
	// End Line: 10888

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Skeleton_Func_Reflex(void)

{
  _MONSTER *monst;
  
  monst = (_MONSTER *)TaskCurrent->local;
  if (monst->timer != 0) {
    monst->timer = monst->timer + -1;
  }
  if ((((LONG_ARRAY_800b2e40[0] != -1) && (LONG_ARRAY_800b2e40[0] < 2000)) && (monst->action != 0xb)
      ) && (LONG_ARRAY_800b2e40[0] < 0x96)) {
    Monster_StopAllActions(monst);
    Monster_AddAction(monst,0,0xb,0,0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Skeleton_Task_Action()
 // line 4730, offset 0x8007be0c
	/* begin block 1 */
		// Start line: 4731
		// Start offset: 0x8007BE0C
		// Variables:
	// 		struct _MONSTER *monst; // $s2
	// 		struct _D3_OBJECT *o; // $s3
	// 		struct M_OBJECT *mo; // $s4
	// 		struct _D3_OBJECT *target; // $s1
	// 		long i; // $s0
	// 		long tmp; // $s0
	// 		long sensorbackup; // $v1
	// 		long oldhitpoints; // $s7
	/* end block 1 */
	// End offset: 0x8007C294
	// End Line: 4834

	/* begin block 2 */
		// Start line: 10930
	/* end block 2 */
	// End Line: 10931

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Skeleton_Task_Action(void)

{
  byte bVar1;
  short sVar2;
  TASK *pTVar3;
  long Anim;
  int iVar4;
  long d1;
  uint uVar5;
  int iVar6;
  _MONSTER *monst;
  _D3_OBJECT *o;
  M_OBJECT *obj;
  
  monst = (_MONSTER *)TaskCurrent->local;
  o = monst->obj;
  obj = (M_OBJECT *)o->description;
  monst->monster_speed = 0x30;
  monst->hurtsound = 2;
  monst->fleesound = 2;
  sVar2 = o->hit_points;
  monst->counter = 5;
  if (o->father != (_D3_OBJECT *)0x0) {
    (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
    o->display_mode = o->display_mode & 0xffef;
    bVar1 = Pvl_SctState[(int)o->father->index];
    while ((bVar1 & 1) == 0) {
      (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
      Task_Next();
      bVar1 = Pvl_SctState[(int)o->father->index];
    }
    o->hit_points = sVar2;
    o->display_mode = o->display_mode | 0x10;
    D3_PlaySound(o,8);
    Manim_SetAnim(obj,2);
    Manim_WaitAnim(obj);
  }
  Anim = Task_EventWait();
  monst->action = (short)Anim;
  TaskCurrent->event_enable = 1;
  monst->monster_speed = 0x100;
  do {
    switch((int)(((uint)(ushort)monst->action - 1) * 0x10000) >> 0x10) {
    case 0:
      Monster_Action_WaitRun(monst,1,3,100,0,4);
      monst->actionmask = 0;
      break;
    case 1:
      Anim = Monster_Action_Hit(6,7,1,1);
      if (Anim == 0) {
        (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
      }
      else {
        if (Anim != 2) goto switchD_8007bf98_caseD_f;
        monst->mode = 0x11;
      }
    default:
switchD_8007bf98_caseD_2:
      monst->actionmask = 0;
      break;
    case 4:
      if ((o[1].pos.vz & 0x200U) != 0) goto switchD_8007bf98_caseD_2;
      Monster_Action_MoveTo(0,0,0,(_D3_OBJECT *)Monster_Feelings,0x96,-1,3,-1,-1,-1,3);
      monst->actionmask = 0;
      break;
    case 10:
      while (Anim = D3_GoToDir(o,(int)*(short *)(Monster_Feelings + 0x2c) - (int)(o->pos).vx,
                               (int)*(short *)(Monster_Feelings + 0x2e) - (int)(o->pos).vy,0xa0),
            Anim != 0) {
        Task_Next();
      }
      uVar5 = M_rand();
      Anim = 5;
      if ((uVar5 & 3) != 0) {
        Anim = 4;
      }
      Monster_Action_Slaying(Anim,0xa0,(_D3_OBJECT *)Monster_Feelings,0);
      Manim_SetAnim(obj,1);
      if ((LONG_800b2e28 != -1) || (iVar4 = 0, monst->timer_agression >> 1 < 1))
      goto switchD_8007bf98_caseD_2;
      do {
        iVar4 = iVar4 + 1;
        Task_Next();
      } while (iVar4 < monst->timer_agression >> 1);
      monst->actionmask = 0;
      break;
    case 0xf:
switchD_8007bf98_caseD_f:
      (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
      iVar4 = monst->counter + -1;
      monst->counter = iVar4;
      Anim = Monster_Feelings;
      iVar6 = 0;
      if (iVar4 == 0) goto switchD_8007bf98_caseD_2;
      do {
        iVar6 = iVar6 + 1;
        Task_Next();
      } while (iVar6 < 0x78);
      do {
        Task_Next();
        d1 = Direction((int)*(short *)(Anim + 0x2c) - (int)(o->pos).vx,
                       (int)*(short *)(Anim + 0x2e) - (int)(o->pos).vy);
        uVar5 = DeltaDirection(d1,(int)*(short *)(Anim + 0x40));
      } while ((uVar5 & 0xfff) - 0x201 < 0xbff);
      o->hit_points = sVar2;
      Manim_SetAnim(obj,0);
      Manim_WaitAnim(obj);
      pTVar3 = TaskCurrent;
      (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
      monst->mode = 0x10;
      pTVar3->event_enable = 1;
      D3_SetCollBits(o,(long)&DAT_00004011);
      monst->actionmask = 0;
      break;
    case 0x14:
      Monster_Action_Flee(monst,3,1,3);
      goto switchD_8007bf98_caseD_2;
    case 0x1d:
      Monster_Action_Fear(monst,1,3,100,-1);
      monst->actionmask = 0;
      break;
    case 0x1e:
      MSpell_SpellTesting(monst,TaskCurrent->event_param,-1,1);
      monst->actionmask = 0;
    }
    monst->busy = -1;
    Task_Next();
    if (monst->mode == 0x11) {
      Monster_ReleaseBonuses();
      return;
    }
    Monster_ForceAction(monst,1,0);
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Sorcier_Func_Reflex()
 // line 4873, offset 0x8007c2c8
	/* begin block 1 */
		// Start line: 4874
		// Start offset: 0x8007C2C8
		// Variables:
	// 		struct _MONSTER *monst; // $s0
	/* end block 1 */
	// End offset: 0x8007C444
	// End Line: 4912

	/* begin block 2 */
		// Start line: 11228
	/* end block 2 */
	// End Line: 11229

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Sorcier_Func_Reflex(void)

{
  uint uVar1;
  _MONSTER *monst;
  
  monst = (_MONSTER *)TaskCurrent->local;
  if ((((LONG_800b2e20 != -1) || (LONG_800b2e1c != -1)) && (2 < (uint)(ushort)monst->mode - 0x32))
     && ((uVar1 = M_rand(), 5 < (uVar1 & 7) && (monst->action != 8)))) {
    Monster_StopAllActions(monst);
    Monster_AddAction(monst,0,8,0,0);
  }
  if (monst->counter != 0) {
    monst->counter = monst->counter + -1;
  }
  if ((2 < (uint)(ushort)monst->mode - 0x32) && (monst->counter == 0)) {
    uVar1 = M_rand();
    monst->counter = (uVar1 & 0x3f) + 0xb4;
    Monster_StopAllActions(monst);
    Monster_AddAction(monst,0,0x10,0,0);
    Monster_AddAction(monst,0,0xc,0,0);
  }
  if ((((LONG_ARRAY_800b2e40[0] != -1) && (LONG_ARRAY_800b2e40[0] < 2000)) && (monst->action != 0xb)
      ) && (LONG_ARRAY_800b2e40[0] < 0x96)) {
    Monster_StopAllActions(monst);
    Monster_AddAction(monst,0,0xb,0,0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Sorcier_Task_Action()
 // line 4915, offset 0x8007c454
	/* begin block 1 */
		// Start line: 4916
		// Start offset: 0x8007C454
		// Variables:
	// 		struct ENEMY_7fake pos; // stack offset -56
	// 		struct ENEMY_8fake col; // stack offset -48
	// 		struct _MONSTER *monst; // $s2
	// 		struct _D3_OBJECT *o; // $s1
	// 		struct TASK *t; // $s3
	// 		long i; // $v1
	// 		long tmp; // $s0
	/* end block 1 */
	// End offset: 0x8007C828
	// End Line: 5006

	/* begin block 2 */
		// Start line: 11324
	/* end block 2 */
	// End Line: 11325

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Sorcier_Task_Action(void)

{
  bool bVar1;
  ushort uVar2;
  long AnimStart;
  TASK *t;
  uint uVar3;
  long waiter;
  char pos;
  long AnimStop;
  long AnimShoot;
  long ShootType;
  _D3_OBJECT *o;
  _MONSTER *monst;
  long local_58;
  
  monst = (_MONSTER *)TaskCurrent->local;
  o = monst->obj;
  monst->counter = 300;
  monst->hurtsound = 2;
  monst->monster_speed = 0x30;
  AnimStart = Task_EventWait();
  monst->action = (short)AnimStart;
  pos = (char)o + ',';
  TaskCurrent->event_enable = 1;
  do {
    switch((int)(((uint)(ushort)monst->action - 1) * 0x10000) >> 0x10) {
    case 0:
      Monster_Action_WaitRun(monst,0,4,100,0,5);
      monst->actionmask = 0;
      break;
    case 1:
      AnimStart = Monster_Action_Hit(0xb,0xc,1,1);
      if (AnimStart != 0) {
        if (AnimStart != 2) {
          uVar3 = 0;
          t = SFX_StreamFire(o);
          SFX_Magic(200,0xd0,0x32);
          bVar1 = true;
          do {
            if (!bVar1) {
              if ((uVar3 & 1) == 0) {
                uVar2 = o->display_mode & 0xffef;
              }
              else {
                uVar2 = o->display_mode | 0x10;
              }
              o->display_mode = uVar2;
            }
            uVar3 = uVar3 + 1;
            Task_Next();
            bVar1 = (int)uVar3 < 0x11;
          } while ((int)uVar3 < 0x20);
          Task_Kill(t);
          o->display_mode = o->display_mode & 0xffef;
          D3_ClearCollBits(o,0xb);
          monst->actionmask = 0;
          break;
        }
        monst->mode = 0x11;
      }
    default:
switchD_8007c508_caseD_2:
      monst->actionmask = 0;
      break;
    case 4:
      if ((o[1].pos.vz & 0x200U) != 0) goto switchD_8007c508_caseD_2;
      Monster_Action_MoveTo(0,0,0,(_D3_OBJECT *)Monster_Feelings,0x96,-1,4,-1,-1,-1,3);
      monst->actionmask = 0;
      break;
    case 7:
      D3_PlaySound(o,7);
      Monster_Action_Magic(monst,3,5,6,3);
      monst->actionmask = 0;
      break;
    case 10:
      while (AnimStart = D3_GoToDir(o,(int)*(short *)(Monster_Feelings + 0x2c) - (int)(o->pos).vx,
                                    (int)*(short *)(Monster_Feelings + 0x2e) - (int)(o->pos).vy,0xa0
                                   ), AnimStart != 0) {
        Task_Next();
      }
      Monster_Action_Slaying(7,0xa0,(_D3_OBJECT *)Monster_Feelings,0);
      monst->actionmask = 0;
      break;
    case 0xb:
      Fx_Play(0x3b,pos);
      uVar3 = M_rand();
      AnimStart = 8;
      if ((uVar3 & 1) == 0) {
        SFX_StreamCone(pos,(char)o + '<',0xd0);
        AnimStart = -1;
        AnimStop = 0x10;
        AnimShoot = 0xf;
        local_58 = 1;
        waiter = monst->timer_agression;
        ShootType = 10;
      }
      else {
        AnimStop = 10;
        AnimShoot = 9;
        local_58 = 3;
        waiter = monst->timer_agression;
        ShootType = 0xd;
      }
      Monster_Action_Shooting(AnimStart,AnimStop,AnimShoot,ShootType,local_58,0x96,0,waiter,-1);
      monst->actionmask = 0;
      break;
    case 0xf:
      D3_PlaySound(o,4);
      Monster_Action_Magic(monst,2,0xd,0xe,0);
      monst->actionmask = 0;
      break;
    case 0x1e:
      MSpell_SpellTesting(monst,TaskCurrent->event_param,-1,1);
      goto switchD_8007c508_caseD_2;
    }
    monst->busy = -1;
    Task_Next();
    if (monst->mode == 0x11) {
      Monster_ReleaseBonuses();
      return;
    }
    Monster_ForceAction(monst,1,0);
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Rod_Func_Reflex()
 // line 5031, offset 0x8007c860
	/* begin block 1 */
		// Start line: 5032
		// Start offset: 0x8007C860
		// Variables:
	// 		struct _MONSTER *monst; // $s0
	// 		struct _D3_OBJECT *o; // $s1
	// 		struct _D3_OBJECT *target; // $s2
	// 		long tmp; // $v1
	/* end block 1 */
	// End offset: 0x8007C948
	// End Line: 5051

	/* begin block 2 */
		// Start line: 11632
	/* end block 2 */
	// End Line: 11633

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Rod_Func_Reflex(void)

{
  short sVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  _MONSTER *monst;
  _D3_OBJECT *ot;
  
  lVar2 = Monster_Feelings;
  monst = (_MONSTER *)TaskCurrent->local;
  ot = monst->obj;
  if (monst->mode != 0x11) {
    lVar3 = Boxes_GetHeightPlatform(ot,(char)ot + ',');
    iVar4 = (int)(ot->pos).vz;
    if ((lVar3 < iVar4 + 200) && (iVar4 + -200 < lVar3)) {
      if (monst->counter < 0x15) {
        sVar1 = *(short *)&monst->counter * 2 + 0x96;
      }
      else {
        sVar1 = -(*(short *)&monst->counter * 2 + -0xe6);
      }
      (ot->pos).vz = (short)lVar3 + sVar1;
      iVar4 = monst->counter + 1;
      monst->counter = iVar4;
      if (iVar4 == 0x28) {
        monst->counter = 0;
      }
    }
    D3_GoToDir(ot,(int)*(short *)(lVar2 + 0x2c) - (int)(ot->pos).vx,
               (int)*(short *)(lVar2 + 0x2e) - (int)(ot->pos).vy,(int)monst->monster_speed);
  }
  Monster_ReflexCombat(monst,0x70,monst->timer_agression);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Rod_Func_Decisions()
 // line 5055, offset 0x8007c970
	/* begin block 1 */
		// Start line: 5056
		// Start offset: 0x8007C970
		// Variables:
	// 		struct _MONSTER *monst; // $s0
	/* end block 1 */
	// End offset: 0x8007C9C0
	// End Line: 5065

	/* begin block 2 */
		// Start line: 11692
	/* end block 2 */
	// End Line: 11693

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Rod_Func_Decisions(void)

{
  _MONSTER *monst;
  
  monst = (_MONSTER *)TaskCurrent->local;
  if (LONG_ARRAY_800b2e2c[0] != -1) {
    Monster_StopAllActions(monst);
    Monster_AddAction(monst,0,5,100,10);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Rod_Task_Action()
 // line 5068, offset 0x8007c9d0
	/* begin block 1 */
		// Start line: 5069
		// Start offset: 0x8007C9D0
		// Variables:
	// 		struct _MONSTER *monst; // $s1
	// 		struct _D3_OBJECT *o; // $s2
	// 		struct M_OBJECT *mo; // $s3
	// 		struct _D3_OBJECT *target; // $s0
	// 		long tmp; // $s0
	/* end block 1 */
	// End offset: 0x8007CCCC
	// End Line: 5127

	/* begin block 2 */
		// Start line: 11723
	/* end block 2 */
	// End Line: 11724

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Rod_Task_Action(void)

{
  TASK *pTVar1;
  long target;
  int iVar2;
  _MONSTER *monst;
  _D3_OBJECT *o;
  M_OBJECT *obj;
  
  monst = (_MONSTER *)TaskCurrent->local;
  o = monst->obj;
  obj = (M_OBJECT *)o->description;
  monst->monster_speed = 0x28;
  monst->hurtsound = 1;
  target = Task_EventWait();
  pTVar1 = TaskCurrent;
  monst->action = (short)target;
  pTVar1->event_enable = 1;
  do {
    target = Monster_Feelings;
    switch((int)(((uint)(ushort)monst->action - 1) * 0x10000) >> 0x10) {
    case 0:
      monst->busy = 0;
      Manim_SetAnim(obj,0);
      iVar2 = 0x59;
      do {
        if (iVar2 == -1) {
          target = M_rand();
          D3_PlaySound(o,(short)((uint)((target % 3 + 2) * 0x10000) >> 0x10));
          target = M_rand();
          iVar2 = target % 0x1f + 0x3c;
        }
        iVar2 = iVar2 + -1;
        Task_Next();
      } while( true );
    case 1:
      target = Monster_Action_Hit(3,4,1,1);
      if (target == 0) goto switchD_8007ca60_caseD_2;
      D3_ClearCollBits(o,0xb);
      o->display_mode = o->display_mode & 0xffef;
      SFX_AddExplosion(o,4,0);
      monst->actionmask = 0;
      break;
    case 4:
      Manim_SetAnim(obj,0);
      Monster_Action_MoveGlide
                ((_D3_OBJECT *)target,*(short *)&TaskCurrent->event_param,
                 *(short *)&monst->task_param2,(o->pos).vz,0,0,0);
      monst->actionmask = 0;
      break;
    case 10:
      while (target = D3_GoToDir(o,(int)*(short *)(Monster_Feelings + 0x2c) - (int)(o->pos).vx,
                                 (int)*(short *)(Monster_Feelings + 0x2e) - (int)(o->pos).vy,0xa0),
            target != 0) {
        Task_Next();
      }
      Monster_Action_Slaying(2,0x78,(_D3_OBJECT *)Monster_Feelings,0);
      Manim_SetAnim(obj,0);
      iVar2 = 0;
      if (monst->timer_agression >> 1 < 1) goto switchD_8007ca60_caseD_2;
      do {
        iVar2 = iVar2 + 1;
        Task_Next();
      } while (iVar2 < monst->timer_agression >> 1);
      monst->actionmask = 0;
      break;
    case 0xb:
      Monster_Action_Shooting(-1,-1,1,0xb,1,0x32,0,monst->timer_agression,-1);
      monst->actionmask = 0;
      break;
    case 0x1e:
      MSpell_SpellTesting(monst,TaskCurrent->event_param,-1,0);
    default:
switchD_8007ca60_caseD_2:
      monst->actionmask = 0;
    }
    monst->busy = -1;
    Task_Next();
    if (monst->mode == 0x11) {
      Monster_ReleaseBonuses();
      return;
    }
    Monster_ForceAction(monst,1,0);
    Task_Next();
  } while( true );
}





