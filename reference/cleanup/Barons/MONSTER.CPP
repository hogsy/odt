#include "THISDUST.H"
#include "MONSTER.H"


// decompiled code
// original method signature: 
// long /*$ra*/ Monster_EmptyRoutine(struct _MONSTER *monst /*$a0*/)
 // line 108, offset 0x80068520
	/* begin block 1 */
		// Start line: 217
	/* end block 1 */
	// End Line: 218

long Monster_EmptyRoutine(_MONSTER *monst)

{
  return 0;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Monster_AcceptCollisioned(struct _D3_OBJECT *ot /*$a0*/, struct _D3_OBJECT *obj /*$a1*/, long flags /*$a2*/)
 // line 152, offset 0x80068528
	/* begin block 1 */
		// Start line: 154
		// Start offset: 0x80068528
		// Variables:
	// 		struct _MONSTER *monst; // $a2
	/* end block 1 */
	// End offset: 0x80068678
	// End Line: 215

	/* begin block 2 */
		// Start line: 307
	/* end block 2 */
	// End Line: 308

long Monster_AcceptCollisioned(_D3_OBJECT *ot,_D3_OBJECT *obj,long flags)

{
  char cVar1;
  int iVar2;
  
  if ((ot->collision_mode & 0x200U) != 0) {
    return 0;
  }
  if ((obj->collision_mode & 0x200U) != 0) {
    return 0;
  }
  if (((obj->collision_mode & 0x8000U) == 0) || ((ot->collision_mode & 2U) == 0))
  goto switchD_80068594_caseD_1;
  iVar2 = *(int *)&obj[1].last_pos;
  switch((int)(((uint)*(byte *)((int)&ot[1].pos.vx + 1) + 0x13) * 0x1000000) >> 0x18) {
  case 0:
    if ((*(ushort *)(iVar2 + 0x158) & 2) == 0) {
      cVar1 = *(char *)(iVar2 + 0x13f);
      break;
    }
  default:
    goto switchD_80068594_caseD_1;
  case 3:
    cVar1 = *(char *)(iVar2 + 0x144);
    break;
  case 4:
    cVar1 = *(char *)(iVar2 + 0x145);
    break;
  case 5:
  case 6:
    cVar1 = *(char *)(iVar2 + 0x140);
    break;
  case 9:
    cVar1 = *(char *)(iVar2 + 0x13d);
    break;
  case 10:
    cVar1 = *(char *)(iVar2 + 0x13e);
    break;
  case 0xb:
  case 0xc:
    cVar1 = *(char *)(iVar2 + 0x13c);
    break;
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x11:
    if ((*(ushort *)(iVar2 + 0x14) & 4) != 0) {
      cVar1 = *(char *)(iVar2 + 0x141);
      break;
    }
    goto switchD_80068594_caseD_1;
  }
  if (cVar1 != '\x05') {
switchD_80068594_caseD_1:
    if (((Pvl_LevelNumber != 4) || (Pvl_SectorNumber != 7)) ||
       ((*(char *)((int)&ot[1].pos.vx + 1) != '\b' && (*(char *)((int)&obj[1].pos.vx + 1) != '\b')))
       ) {
      return 1;
    }
  }
  return 0;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Monster_Collisioned(struct _D3_OBJECT *ot /*$s4*/, struct _D3_OBJECT *obj /*$s3*/, long flags /*$s5*/)
 // line 217, offset 0x80068680
	/* begin block 1 */
		// Start line: 219
		// Start offset: 0x800686AC
		// Variables:
	// 		struct _MONSTER *monst; // $s0
	// 		long hit_power; // $s2
	// 		long index; // $s1

		/* begin block 1.1 */
			// Start line: 316
			// Start offset: 0x800688E4
			// Variables:
		// 		struct M_OBJECT *mo; // $v0
		/* end block 1.1 */
		// End offset: 0x80068900
		// End Line: 320
	/* end block 1 */
	// End offset: 0x800689CC
	// End Line: 347

	/* begin block 2 */
		// Start line: 436
	/* end block 2 */
	// End Line: 437

/* WARNING: Removing unreachable block (ram,0x80068860) */
/* WARNING: Removing unreachable block (ram,0x80068888) */

long Monster_Collisioned(_D3_OBJECT *ot,_D3_OBJECT *obj,long flags)

{
  short sVar1;
  short sVar2;
  long lVar3;
  uint uVar4;
  _MONSTER *monst;
  int iVar5;
  uint uVar6;
  _D3_OBJECT *obj_00;
  
  while( true ) {
    obj_00 = obj;
    uVar6 = (uint)ot->hit_power;
    iVar5 = -1;
    lVar3 = Monster_AcceptCollisioned(ot,obj_00,flags);
    if (lVar3 == 0) {
      return 0;
    }
    if (((int)obj_00->collision_mode & 0x8000U) != 0) break;
    *(_D3_OBJECT **)(*(int *)&ot[1].last_pos + 0x100) = obj_00;
    if ((obj_00->collision_mode & 2U) == 0) {
      return 1;
    }
    obj = ot;
    ot = obj_00;
    if (*(char *)((int)&obj_00[1].pos.vx + 1) != -9) {
      return 1;
    }
  }
  if ((((int)ot->collision_mode & 0x8000U) != 0) && (*(char *)((int)&ot[1].pos.vx + 1) != -9)) {
    *(_D3_OBJECT **)(*(int *)&ot[1].last_pos + 0x100) = obj_00;
    return 1;
  }
  monst = *(_MONSTER **)&obj_00[1].last_pos;
  switch((int)(((uint)*(byte *)((int)&ot[1].pos.vx + 1) + 0x13) * 0x1000000) >> 0x18) {
  case 0:
    if ((monst->flags2 & 2U) != 0) {
      return 1;
    }
    iVar5 = 3;
    break;
  default:
    if (((obj_00->collision_mode & 2U) != 0) && ((ot->collision_mode & 0x1000U) != 0)) {
      Pl_Collisioned(obj_00,ot,flags);
      return 1;
    }
    break;
  case 3:
    iVar5 = 8;
    break;
  case 4:
    iVar5 = 9;
    break;
  case 5:
  case 6:
    iVar5 = 4;
    break;
  case 9:
    iVar5 = 1;
    break;
  case 10:
    iVar5 = 2;
    break;
  case 0xb:
  case 0xc:
    iVar5 = 0;
    break;
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x11:
    iVar5 = 0x45;
    if ((monst->flags & 4U) != 0) {
      iVar5 = 5;
    }
  }
  if ((ot->collision_mode & 2U) == 0) {
    return 1;
  }
  MSensor_AddFear(monst,0x96);
  MSensor_AddAgression(monst,0x14);
  if (iVar5 == -1) goto switchD_80068850_caseD_5;
  uVar4 = (int)uVar6 >> 2;
  switch(monst->resistance[iVar5]) {
  case '\x01':
    uVar4 = uVar6 - uVar4;
    break;
  case '\x02':
    uVar4 = (int)uVar6 >> 1;
    break;
  case '\x03':
    break;
  case '\x04':
    if ((monst->flags & 4U) != 0) {
      monst->flags2 = monst->flags2 | 0x20;
      return 1;
    }
    return 1;
  default:
    goto switchD_80068850_caseD_5;
  case '\x06':
    uVar6 = 1;
    goto switchD_80068850_caseD_5;
  }
  uVar6 = uVar4;
  if ((int)uVar4 < 1) {
    uVar6 = 1;
  }
switchD_80068850_caseD_5:
  if (((obj_00->display_mode & 0x40U) != 0) && (*(int *)((int)obj_00->description + 0x10) != 0)) {
    uVar6 = uVar6 << 1;
  }
  if ((monst->flags & 8U) == 0) {
    monst->whohitme = (short)*(char *)((int)&ot[1].pos.vx + 1);
    monst->whohitme_turn = (int)(ot->rot).vz;
    if ((monst->flags & 4U) == 0) {
      monst->hbcounter = 0x96;
      monst->flags2 = monst->flags2 & 0xfff7;
    }
    sVar2 = obj_00->hit_points;
    obj_00->collision_state = obj_00->collision_state | 2;
    sVar1 = obj_00->hit_points;
    *(_D3_OBJECT **)&obj_00[1].description = ot;
    if ((int)sVar1 != 0) {
      sVar2 = sVar2 - (short)uVar6;
      if ((int)((int)sVar1 - uVar6) < 0) {
        sVar2 = 0;
      }
      obj_00->hit_points = sVar2;
    }
    return 1;
  }
  return 1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Monster_CreateShadow(struct _D3_OBJECT *D3Obj /*$s1*/, struct MONSTER_31fake *pft4 /*$s0*/)
 // line 351, offset 0x800689f0
	/* begin block 1 */
		// Start line: 352
		// Start offset: 0x800689F0
		// Variables:
	// 		struct MONSTER_70fake shp; // stack offset -32
	/* end block 1 */
	// End offset: 0x800689F0
	// End Line: 352

	/* begin block 2 */
		// Start line: 710
	/* end block 2 */
	// End Line: 711

void Monster_CreateShadow(_D3_OBJECT *D3Obj,undefined pft4)

{
  undefined3 in_register_00000015;
  SHAPE_31fake *prim;
  SHAPE_68fake local_20;
  
  local_20.file = Pl_Pcl;
  prim = (SHAPE_31fake *)CONCAT31(in_register_00000015,pft4);
  *(SHAPE_31fake **)((int)D3Obj->description + 0x1c) = prim;
  local_20.shape = 0x25;
  Shp_SetPolyFT4(prim,&local_20,0,0);
  Shp_SetPolyFT4(prim + 1,&local_20,0,0);
  D3Obj->display_mode = D3Obj->display_mode | 0x80;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Monster_DisplayText(struct _D3_OBJECT *obj /*$a0*/)
 // line 364, offset 0x80068a70
	/* begin block 1 */
		// Start line: 746
	/* end block 1 */
	// End Line: 747

void Monster_DisplayText(_D3_OBJECT *obj)

{
  Overlay_SetText((char *)Pvl_Texts[(int)*(short *)((int)&obj[1].prec + 2)]);
  return;
}



// decompiled code
// original method signature: 
// struct _MONSTER * /*$ra*/ Monster_Main_Init(struct _D3_OBJECT *Target /*$a0*/)
 // line 374, offset 0x80068aa8
	/* begin block 1 */
		// Start line: 375
		// Start offset: 0x80068AA8
		// Variables:
	// 		struct _D3_OBJECT *obj; // $s2
	// 		struct _MONSTER *monst; // $s1
	// 		struct M_OBJECT *mobj; // $s0
	// 		long i; // $v1
	// 		long mask; // $a0
	/* end block 1 */
	// End offset: 0x80068BE4
	// End Line: 430

	/* begin block 2 */
		// Start line: 767
	/* end block 2 */
	// End Line: 768

_MONSTER * Monster_Main_Init(_D3_OBJECT *Target)

{
  short sVar1;
  bool bVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  M_OBJECT *mo;
  _MONSTER *p_Var8;
  _D3_OBJECT *o;
  
  o = (_D3_OBJECT *)TaskCurrent->local;
  p_Var8 = *(_MONSTER **)&o[1].last_pos;
  mo = (M_OBJECT *)o->description;
  p_Var8->hbcounter = 0;
  sVar3 = o->hit_points;
  p_Var8->d3_lasttouched = (_D3_OBJECT *)0x0;
  p_Var8->busy = 0;
  p_Var8->oldhit_points = sVar3;
  D3_ClearCollBits(o,4);
  D3_SetCollBits(o,0x8000);
  p_Var8->flags2 = 0;
  p_Var8->flags = p_Var8->flags & 0xefffU | 0x10;
  Manim_SetEffect(mo,(TDRFuncPtr_Manim_SetEffect1f)0x0);
  *(undefined2 *)((int)&(mo->Env).nPivot + 2) = 0;
  D3_SetBonuses(o,0,o);
  sVar3 = *(short *)&o[1].prec;
  sVar1 = (o->b_box).vz;
  p_Var8->task_action = (_func_31 *)0x0;
  p_Var8->func_reflex = (_func_32 *)0x0;
  p_Var8->func_init = (_func_34 *)0x0;
  p_Var8->height = sVar3 - sVar1;
  sVar3 = Zone_GetEnemyZone((o->pos).vx,(o->pos).vy,(o->pos).vz,p_Var8->zb_low,p_Var8->zb_high);
  iVar5 = (int)sVar3;
  iVar4 = iVar5 << 1;
  if (iVar5 == -1) {
    uVar6 = p_Var8->zb_low;
    iVar5 = 0;
    if ((uVar6 & 1) == 0) {
      bVar2 = true;
      do {
        iVar4 = iVar5 << 1;
        if (!bVar2) goto LAB_80068bcc;
        iVar5 = iVar5 + 1;
        uVar6 = (int)uVar6 >> 1;
        if (iVar5 == 0x20) {
          uVar6 = p_Var8->zb_high;
        }
        bVar2 = iVar5 < 0x3f;
      } while ((uVar6 & 1) == 0);
    }
    iVar4 = iVar5 << 1;
  }
LAB_80068bcc:
  p_Var8->zone_wait = (_ENEMYZONE *)(&Pvl_EnemyZones->x1 + (iVar4 + iVar5) * 4);
  p_Var8->meatweight = 200;
  p_Var8->monster_speed = 0x100;
  p_Var8->monster_trans = 0x100;
  p_Var8->virtual_child = (_D3_OBJECT *)0x0;
  p_Var8->zone_path = (_ZONE *)0x0;
  p_Var8->startcommand = 0;
  p_Var8->endcommand = 0;
  p_Var8->whohitme = 0;
  p_Var8->zone_current = p_Var8->zone_wait;
  uVar7 = *(undefined4 *)&(o->pos).vz;
  *(undefined4 *)&p_Var8->last_pos = *(undefined4 *)&o->pos;
  *(undefined4 *)&(p_Var8->last_pos).vz = uVar7;
  p_Var8->hurtsound = -1;
  p_Var8->hurttimer = 0;
  p_Var8->last_spell = 0;
  p_Var8->sfxhurt_timer = 0;
  p_Var8->counter = 0;
  p_Var8->timer = 0;
  p_Var8->fleesound = 0;
  p_Var8->wait_kick = 0;
  return p_Var8;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Monster_ReleaseBonuses()
 // line 433, offset 0x80068c74
	/* begin block 1 */
		// Start line: 434
		// Start offset: 0x80068C74
		// Variables:
	// 		struct _MONSTER *monst; // $s1
	// 		struct _D3_OBJECT *o; // $s2
	// 		struct M_OBJECT *mo; // $s0
	/* end block 1 */
	// End offset: 0x80068C74
	// End Line: 434

	/* begin block 2 */
		// Start line: 929
	/* end block 2 */
	// End Line: 930

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Monster_ReleaseBonuses(void)

{
  M_OBJECT *mo;
  _D3_OBJECT *p_Var1;
  _D3_OBJECT *o;
  
  p_Var1 = (_D3_OBJECT *)TaskCurrent->local;
  o = p_Var1->next;
  mo = (M_OBJECT *)o->description;
  p_Var1->child = (_D3_OBJECT *)0x10000000;
  Manim_SetEffect(mo,(TDRFuncPtr_Manim_SetEffect1f)0x0);
  (mo->Env).Obj.normal_top.vx = (mo->Env).Obj.normal_top.vx & 0xfffe;
  *(undefined2 *)&p_Var1->list = 0;
  Pvl_SetStateBits(o,2);
  D3_ClearCollBits(o,0xb);
  D3_SetBonuses(o,1,o);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Monster_Func_Display()
 // line 450, offset 0x80068d04
	/* begin block 1 */
		// Start line: 451
		// Start offset: 0x80068D04
		// Variables:
	// 		struct _MONSTER *monst; // $s1
	// 		struct _D3_OBJECT *o; // $s0
	/* end block 1 */
	// End offset: 0x80068E08
	// End Line: 467

	/* begin block 2 */
		// Start line: 971
	/* end block 2 */
	// End Line: 972

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Monster_Func_Display(void)

{
  undefined2 uVar1;
  short sVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  piVar6 = (int *)TaskCurrent->local;
  iVar5 = *piVar6;
  if (((*(short *)(piVar6 + 4) != 0x11) && (*(short *)(piVar6 + 4) != 0x15)) &&
     ((piVar6[1] & 0x8000000U) != 0)) {
    sVar2 = Zone_GetEnemyZone(*(short *)(iVar5 + 0x2c),*(short *)(iVar5 + 0x2e),
                              *(short *)(iVar5 + 0x30),piVar6[0xf],piVar6[0x10]);
    if (sVar2 == -1) {
      sVar2 = *(short *)((int)piVar6 + 0x12);
      if (((sVar2 == 0x11) || (sVar2 == 5)) || (sVar2 == 1)) {
        lVar3 = Direction((int)*(short *)(piVar6 + 0x4d) - (int)*(short *)(iVar5 + 0x2c),
                          (int)*(short *)((int)piVar6 + 0x136) - (int)*(short *)(iVar5 + 0x2e));
        *(undefined2 *)(iVar5 + 0x40) = (short)lVar3;
      }
      uVar1 = *(undefined2 *)(piVar6 + 0x4d);
      *(undefined2 *)(iVar5 + 0x2c) = uVar1;
      *(undefined2 *)(iVar5 + 0x34) = uVar1;
      uVar1 = *(undefined2 *)((int)piVar6 + 0x136);
      *(undefined2 *)(iVar5 + 0x2e) = uVar1;
      *(undefined2 *)(iVar5 + 0x36) = uVar1;
    }
    iVar4 = *(int *)(iVar5 + 0x30);
    piVar6[0x4d] = *(int *)(iVar5 + 0x2c);
    piVar6[0x4e] = iVar4;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Monster_Main_SequenceDispatcher()
 // line 474, offset 0x80068e20
	/* begin block 1 */
		// Start line: 475
		// Start offset: 0x80068E20
		// Variables:
	// 		struct _MONSTER *monst; // $s0
	// 		long changefifo; // $s2
	/* end block 1 */
	// End offset: 0x80068F30
	// End Line: 506

	/* begin block 2 */
		// Start line: 1022
	/* end block 2 */
	// End Line: 1023

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Monster_Main_SequenceDispatcher(void)

{
  bool bVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  _MONSTER *monst;
  
  monst = (_MONSTER *)TaskCurrent->local;
  bVar1 = true;
  if (((Pvl_Pause == 0) && (monst->busy == -1)) &&
     (iVar3 = (int)monst->startcommand, (int)monst->endcommand != iVar3)) {
    iVar4 = (int)&monst->obj + iVar3;
    if (*(char *)(iVar4 + 0x4c) == '\0') {
      lVar2 = Monster_FSetAction(monst,(uint)*(byte *)(iVar4 + 0x5c),monst->param1[iVar3]);
      if (lVar2 == 0) {
        bVar1 = false;
      }
      else {
        lVar2 = monst->param2[(int)monst->startcommand];
        monst->busy = 1;
        monst->task_param2 = lVar2;
      }
    }
    iVar3 = (int)&monst->obj + (int)monst->startcommand;
    if (*(char *)(iVar3 + 0x4c) == '\x01') {
      Monster_ForceAction(monst,(uint)*(byte *)(iVar3 + 0x5c),
                          monst->param1[(int)monst->startcommand]);
      lVar2 = monst->param2[(int)monst->startcommand];
      monst->busy = 1;
      monst->task_param2 = lVar2;
    }
    if (bVar1) {
      monst->startcommand = monst->startcommand + 1U & 0xf;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Monster_Main_Module(struct _MONSTER *Monster /*$s2*/, unsigned long Mask /*$a1*/)
 // line 512, offset 0x80068f48
	/* begin block 1 */
		// Start line: 513
		// Start offset: 0x80068F48
		// Variables:
	// 		struct _D3_OBJECT *obj; // $s3
	// 		struct M_OBJECT *mo; // $s5
	// 		long i; // $s0
	// 		long orgtimer_agression; // stack offset -48
	// 		long excolor; // $s7
	// 		long excomp_mode; // stack offset -44
	/* end block 1 */
	// End offset: 0x800699A4
	// End Line: 792

	/* begin block 2 */
		// Start line: 1102
	/* end block 2 */
	// End Line: 1103

void Monster_Main_Module(_MONSTER *Monster,ulong Mask)

{
  undefined uVar1;
  short sVar2;
  TASK *pTVar3;
  long param1;
  _D3_OBJECT *p_Var4;
  int iVar5;
  TDRFuncPtr_Manim_SetEffect1f pTVar6;
  code *pcVar7;
  int iVar8;
  long command;
  code *f;
  long action;
  int iVar9;
  long *plVar10;
  undefined **ppuVar11;
  _D3_OBJECT *o;
  M_OBJECT *mo;
  long lVar12;
  
  pTVar3 = TaskCurrent;
  o = (_D3_OBJECT *)TaskCurrent->local;
  mo = (M_OBJECT *)o->description;
  (mo->Env).Obj.normal_top.vx = (mo->Env).Obj.normal_top.vx & 0xfffe;
  if (Monster->task_action == (_func_31 *)0x0) {
    return;
  }
  uVar1 = *(undefined *)((int)&o[1].pos.vx + 1);
  lVar12 = o->color;
  iVar9 = Monster->timer_agression;
  Monster->sensormask = Mask & 0x9fffffff | 0x80000;
  *(_MONSTER **)&pTVar3->local = Monster;
  pTVar3 = Task_Link((TDRFuncPtr_Task_Link0f)Monster->task_action,0x600);
  Monster->t_move = pTVar3;
  if ((Monster->sensormask & 0x8000000) != 0) {
    pTVar3->display = Monster_Func_Display;
  }
  TaskCurrent->display = Monster_Main_SequenceDispatcher;
  Monster_ForceAction(Monster,1,0);
  Monster->t_move->event_enable = 1;
  Monster->mode = 0;
  if (Monster->func_init != (_func_34 *)0x0) {
    (*Monster->func_init)();
  }
  do {
    param1 = Pvl_TestStateBits(o,2);
    if (param1 != 0) {
      TaskCurrent->display = (_func_11 *)0x0;
      Monster->t_move = (TASK *)0x0;
      if ((*(short *)((int)&o[1].prec + 2) != -1) && ((Monster->flags2 & 1U) == 0)) {
        Monster_DisplayText(o);
      }
      do {
        Task_Next();
        if (Monster->hbcounter < 1) {
          Monster->flags2 = Monster->flags2 & 0xfff7;
        }
        else {
          Monster->hbcounter = Monster->hbcounter + -1;
        }
        sVar2 = Monster->hurttimer;
        if ((Monster->hurttimer != 0) && (Monster->hurttimer = sVar2 + -1, sVar2 == 1)) {
          o->color = lVar12;
        }
      } while( true );
    }
    do {
      if (Monster->wait_kick != 0) {
        Monster->wait_kick = Monster->wait_kick + -1;
      }
      if (Monster->hbcounter < 1) {
        Monster->flags2 = Monster->flags2 & 0xfff7;
      }
      else {
        Monster->hbcounter = Monster->hbcounter + -1;
      }
      Monster_Mask = Monster->sensormask;
      if ((o[1].pos.vz & 0x1000U) != 0) {
        Monster_Mask = Monster_Mask & 0x100030a9;
      }
      p_Var4 = o;
      if ((Monster_Mask & 1U) != 0) {
        p_Var4 = (_D3_OBJECT *)(*(code *)Monster_Sensor)(Monster);
      }
      Monster_Feelings = (long)p_Var4;
      Monster_Mask = Monster_Mask >> 1;
      if ((((Monster->sensormask & 0x10000000) == 0) && (Monster->action == 1)) &&
         ((o->collision_state & 0x80U) == 0)) {
        Monster_Mask = Monster_Mask & 0x719f4;
        plVar10 = &LONG_800b2e1c;
        ppuVar11 = PTR_ARRAY_800ad838;
        do {
          if ((Monster_Mask & 1U) == 0) {
            *plVar10 = -1;
          }
          else {
            param1 = (*(code *)*ppuVar11)(Monster);
            *plVar10 = param1;
          }
          plVar10 = plVar10 + 1;
          Monster_Mask = Monster_Mask >> 1;
          ppuVar11 = (code **)ppuVar11 + 1;
        } while ((int)plVar10 < -0x7ff4d16c);
        o->collision_state = o->collision_state & 0xfffd;
        if ((Monster->flags & 0x1000U) == 0) {
          (mo->Env).Obj.normal_top.vx = (mo->Env).Obj.normal_top.vx & 0xfffe;
        }
        Monster->flags = Monster->flags | 0x1000;
        Monster->t_move->enable = 0;
        if (Monster->func_reflex != (_func_32 *)0x0) {
          (*Monster->func_reflex)();
        }
        if ((((int)Monster->sensormask < 0) && (LONG_800b2e24 != -1)) && (Monster->mode != 0x11)) {
          Monster_StopAllActions(Monster);
          command = 1;
          action = 2;
          param1 = LONG_ARRAY_800b2e48[0];
          goto LAB_80069520;
        }
      }
      else {
        plVar10 = &LONG_800b2e1c;
        if (((Monster->flags & 0x1000U) != 0) && ((o->display_mode & 0x40U) != 0)) {
          (mo->Env).Obj.normal_top.vx = (mo->Env).Obj.normal_top.vx | 1;
        }
        ppuVar11 = PTR_ARRAY_800ad838;
        Monster->flags = Monster->flags & 0xefff;
        Monster->t_move->enable = 1;
        do {
          if ((Monster_Mask & 1U) == 0) {
            *plVar10 = -1;
          }
          else {
            param1 = (*(code *)*ppuVar11)(Monster);
            *plVar10 = param1;
          }
          plVar10 = plVar10 + 1;
          Monster_Mask = Monster_Mask >> 1;
          ppuVar11 = (code **)ppuVar11 + 1;
        } while ((int)plVar10 < -0x7ff4d16c);
        o->collision_state = o->collision_state & 0xfffd;
        MSensor_AddFear(Monster,-2);
        if (Monster->func_reflex != (_func_32 *)0x0) {
          (*Monster->func_reflex)();
        }
        if ((int)Monster->sensormask < 0) {
          if ((LONG_ARRAY_800b2e48[0] == -1) && ((LONG_800b2e24 == -1 || (Monster->mode == 0x11))))
          {
            if ((((o[1].pos.vz & 0x200U) != 0) || (Monster->action == 0x15)) ||
               ((LONG_ARRAY_800b2e68[0] == -1 ||
                ((Monster->fleesound == 0 || ((o->display_mode & 0x40U) == 0))))))
            goto LAB_80069528;
            Monster_StopAllActions(Monster);
            command = 1;
            action = 0x15;
            param1 = LONG_ARRAY_800b2e68[0];
          }
          else {
            if ((LONG_800b2e24 == -1) &&
               ((LONG_ARRAY_800b2e48[0] != -1 && (Monster->whohitme != -0x13)))) {
              sVar2 = Monster->action;
              if (((((sVar2 == 0x1e) || (sVar2 == 0xc)) || (sVar2 == 0xb)) || (sVar2 == 0x15)) &&
                 (*(short *)((int)&o->comp_opt4 + 2) == 1)) {
                switch((int)(((uint)(ushort)Monster->whohitme + 0x10) * 0x10000) >> 0x10) {
                case 0:
                case 7:
                case 10:
                case 0xb:
                case 0xc:
                case 0xd:
                case 0xe:
                  if ((o->collision_state & 0x20U) == 0) {
                    pTVar6 = (TDRFuncPtr_Manim_SetEffect1f)(mo->Env).Obj.n_normal;
                    f = Motion2D_ManimBurn;
                  }
                  else {
                    pTVar6 = (TDRFuncPtr_Manim_SetEffect1f)(mo->Env).Obj.n_normal;
                    f = Motion2D_ManimSmoke;
                  }
                  if (pTVar6 == f) {
                    (mo->Env).Obj.vert_top.vz = 0x10;
                  }
                  else {
LAB_80069478:
                    Manim_SetEffect(mo,f);
                  }
                  break;
                case 1:
                case 6:
                  f = Motion2D_ManimElectricity;
                  if ((code *)(mo->Env).Obj.n_normal != Motion2D_ManimElectricity)
                  goto LAB_80069478;
                }
              }
              command = 0;
              action = 2;
              param1 = LONG_ARRAY_800b2e48[0];
            }
            else {
              Monster_StopAllActions(Monster);
              command = 1;
              action = 2;
              param1 = LONG_ARRAY_800b2e48[0];
            }
          }
LAB_80069520:
          Monster_AddAction(Monster,command,action,param1,0);
        }
      }
LAB_80069528:
      if ((Monster->busy == 0) && (Monster->func_decide != (_func_33 *)0x0)) {
        (*Monster->func_decide)();
      }
      sVar2 = Monster->hurttimer;
      if ((Monster->hurttimer == 0) || (Monster->action == 0x1f)) {
LAB_800695a8:
        if ((o->display_mode & 0x40U) != 0) goto LAB_800695bc;
      }
      else {
        Monster->hurttimer = sVar2 + -1;
        if (sVar2 == 1) {
          o->color = lVar12;
        }
        if ((o->display_mode & 0x40U) == 0) {
          Monster->flags2 = Monster->flags2 & 0xfffd;
          goto LAB_800695a8;
        }
LAB_800695bc:
        if ((mo->Env).Obj.n_normal == 0) {
          Monster->flags2 = Monster->flags2 & 0xfffd;
        }
      }
      if (Monster->sfxhurt_timer != 0) {
        Monster->sfxhurt_timer = Monster->sfxhurt_timer + -1;
      }
      if (((LONG_ARRAY_800b2e48[0] != -1) && (Monster->hurtsound != -1)) &&
         (Monster->hurttimer == 0)) {
        sVar2 = 3;
        if ((o->display_mode & 0x40U) == 0) {
          sVar2 = 10;
        }
        Monster->hurttimer = sVar2;
        o->color = 0xffffff;
        if (Monster->sfxhurt_timer == 0) {
          if (((Monster->wait_kick == 0) && ((Monster->sensormask & 0x2000000) != 0)) &&
             (Monster->whohitme == -0xd)) {
            Monster->wait_kick = 0x14;
          }
          D3_PlaySound(o,Monster->hurtsound);
          Monster->sfxhurt_timer = 0x1e;
        }
      }
      if ((0x280 < LONG_800b2e28) &&
         (iVar5 = iVar9 - (LONG_800b2e28 * (iVar9 >> 4) >> 8), Monster->timer_agression = iVar5,
         iVar5 < 0x23)) {
        Monster->timer_agression = 0x23;
      }
      if ((Monster->flags & 0x800U) != 0) {
        if ((int)o->hit_points == 0) {
          Task_EventExec(Overlay_Handle,Overlay_Handle->event_msg | 0x200,
                         Overlay_Handle->event_param);
          Monster->flags = Monster->flags & 0xf7ff;
        }
        else {
          iVar5 = (int)Monster->oldhit_points;
          iVar8 = (int)o->hit_points * 100;
          if (iVar5 == 0) {
            trap(0x1c00);
          }
          if ((iVar5 == -1) && (iVar8 == -0x80000000)) {
            trap(0x1800);
          }
          Overlay_UpdateBoss(iVar8 / iVar5);
        }
      }
      f = (code *)(mo->Env).Obj.n_normal;
      Task_Next();
      if ((((o->display_mode & 0x40U) != 0) &&
          ((*(char *)((int)&o[1].pos.vx + 1) != -9 || ((o->collision_mode & 2U) == 0)))) &&
         ((pcVar7 = (code *)(mo->Env).Obj.n_normal, pcVar7 == Motion2D_EffectAnimXtra ||
          (pcVar7 == Motion2D_ManimBurn)))) {
        *(undefined *)((int)&o[1].pos.vx + 1) = 0xf7;
        D3_SetCollBits(o,2);
      }
      if ((f != (code *)0x0) &&
         ((f == Motion2D_EffectAnimXtra ||
          ((f == Motion2D_ManimBurn && ((mo->Env).Obj.n_normal == 0)))))) {
        *(undefined *)((int)&o[1].pos.vx + 1) = uVar1;
        D3_ClearCollBits(o,2);
      }
      if ((o->pos).vz < -1000) {
        Monster->mode = 0x11;
      }
    } while (Monster->mode != 0x11);
    if ((Monster->flags & 4U) == 0) {
      Pvl_nMonsters = Pvl_nMonsters + 1;
    }
    D3_ClearCollBits(o,(long)&DAT_00004010);
    o->color = lVar12;
    sVar2 = Monster->mode;
    while (sVar2 == 0x11) {
      Task_Next();
      if (Monster->hbcounter < 1) {
        Monster->flags2 = Monster->flags2 & 0xfff7;
      }
      else {
        Monster->hbcounter = Monster->hbcounter + -1;
      }
      sVar2 = Monster->mode;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Monster_ExternForceAction(struct _D3_OBJECT *D3Obj /*$a0*/, long Action /*$s0*/, long Param /*$s2*/)
 // line 798, offset 0x800699d4
	/* begin block 1 */
		// Start line: 799
		// Start offset: 0x800699D4
		// Variables:
	// 		struct _MONSTER *monst; // $s1
	/* end block 1 */
	// End offset: 0x800699D4
	// End Line: 799

	/* begin block 2 */
		// Start line: 1708
	/* end block 2 */
	// End Line: 1709

void Monster_ExternForceAction(_D3_OBJECT *D3Obj,long Action,long Param)

{
  _MONSTER *monst;
  
  monst = *(_MONSTER **)&D3Obj[1].last_pos;
  Monster_StopAllActions(monst);
  Monster_ForceAction(monst,Action,Param);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Monster_FSetAction(struct _MONSTER *monst /*$s0*/, long Action /*$s1*/, long Param /*$a2*/)
 // line 807, offset 0x80069a24
	/* begin block 1 */
		// Start line: 808
		// Start offset: 0x80069A24
		// Variables:
	// 		long maskcreation; // $v1
	/* end block 1 */
	// End offset: 0x80069AB0
	// End Line: 824

	/* begin block 2 */
		// Start line: 1727
	/* end block 2 */
	// End Line: 1728

long Monster_FSetAction(_MONSTER *monst,long Action,long Param)

{
  long lVar1;
  TASK *pTVar2;
  
  lVar1 = 0;
  if ((((~monst->actionmask & 1 << (Action & 0x1fU)) != 0) &&
      (pTVar2 = monst->t_move, pTVar2 != (TASK *)0x0)) && (lVar1 = 0, pTVar2->event_enable != 0)) {
    pTVar2->enable = 1;
    Task_EventExec(monst->t_move,Action,Param);
    monst->t_move->event_enable = 0;
    monst->action = (short)Action;
    lVar1 = 1;
    monst->actionmask = Monster_ActionTabel[Action * 2];
  }
  return lVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Monster_ForceAction(struct _MONSTER *monst /*$s0*/, long Action /*$s1*/, long Param /*$a2*/)
 // line 827, offset 0x80069ac4
	/* begin block 1 */
		// Start line: 1773
	/* end block 1 */
	// End Line: 1774

void Monster_ForceAction(_MONSTER *monst,long Action,long Param)

{
  if (monst->t_move != (TASK *)0x0) {
    monst->t_move->enable = 1;
    monst->t_move->event_enable = 1;
    Task_EventExec(monst->t_move,Action,Param);
    monst->t_move->event_enable = 0;
    monst->action = (short)Action;
    monst->actionmask = Monster_ActionTabel[Action * 2];
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Monster_StopAllActions(struct _MONSTER *monst /*$a0*/)
 // line 841, offset 0x80069b44
	/* begin block 1 */
		// Start line: 1805
	/* end block 1 */
	// End Line: 1806

void Monster_StopAllActions(_MONSTER *monst)

{
  monst->endcommand = 0;
  monst->startcommand = 0;
  monst->busy = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Monster_ResetActions(struct _MONSTER *monst /*$a0*/)
 // line 847, offset 0x80069b54
	/* begin block 1 */
		// Start line: 1817
	/* end block 1 */
	// End Line: 1818

void Monster_ResetActions(_MONSTER *monst)

{
  monst->endcommand = 0;
  monst->startcommand = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Monster_AddAction(struct _MONSTER *monst /*$s0*/, long command /*$a1*/, long action /*$a2*/, long param1 /*$a3*/, long param2 /*stack 16*/)
 // line 853, offset 0x80069b60
	/* begin block 1 */
		// Start line: 1828
	/* end block 1 */
	// End Line: 1829

void Monster_AddAction(_MONSTER *monst,long command,long action,long param1,long param2)

{
  Monster_AppendAction(monst,command,action,param1,param2);
  monst->busy = -1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Monster_AppendAction(struct _MONSTER *monst /*$a0*/, long command /*$a1*/, long action /*$a2*/, long param1 /*$a3*/, long param2 /*stack 16*/)
 // line 860, offset 0x80069b94
	/* begin block 1 */
		// Start line: 1843
	/* end block 1 */
	// End Line: 1844

void Monster_AppendAction(_MONSTER *monst,long command,long action,long param1,long param2)

{
  monst->com[(int)monst->endcommand] = (char)command;
  monst->act[(int)monst->endcommand] = (char)action;
  monst->param1[(int)monst->endcommand] = param1;
  monst->param2[(int)monst->endcommand] = param2;
  monst->endcommand = monst->endcommand + 1U & 0xf;
  return;
}



// decompiled code
// original method signature: 
// struct _D3_OBJECT * /*$ra*/ Monster_GetChild(struct _D3_OBJECT *obj /*$a0*/, long childID /*$s1*/)
 // line 879, offset 0x80069bf4
	/* begin block 1 */
		// Start line: 880
		// Start offset: 0x80069BF4
		// Variables:
	// 		struct _D3_OBJECT *child; // $s0
	// 		struct _D3_OBJECT *tmp; // $v1
	/* end block 1 */
	// End offset: 0x80069C6C
	// End Line: 896

	/* begin block 2 */
		// Start line: 1881
	/* end block 2 */
	// End Line: 1882

_D3_OBJECT * Monster_GetChild(_D3_OBJECT *obj,long childID)

{
  _D3_OBJECT *p_Var1;
  _D3_OBJECT *obj_00;
  
  obj_00 = obj->child;
  while( true ) {
    if (obj_00 == (_D3_OBJECT *)0x0) {
      return (_D3_OBJECT *)0x0;
    }
    if ((int)obj_00[1].pos.vz == childID) break;
    if (((obj_00->child != (_D3_OBJECT *)0x0) &&
        (p_Var1 = Monster_GetChild(obj_00,childID), p_Var1 != (_D3_OBJECT *)0x0)) &&
       ((int)p_Var1[1].pos.vz == childID)) {
      return p_Var1;
    }
    obj_00 = obj_00->next;
  }
  return obj_00;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Monster_DisplayChild(struct _D3_OBJECT *obj /*$a0*/, long disp /*$a1*/)
 // line 899, offset 0x80069c80
	/* begin block 1 */
		// Start line: 901
		// Start offset: 0x80069C80
		// Variables:
	// 		struct _D3_OBJECT *child; // $v1
	/* end block 1 */
	// End offset: 0x80069CC4
	// End Line: 909

	/* begin block 2 */
		// Start line: 1922
	/* end block 2 */
	// End Line: 1923

long Monster_DisplayChild(_D3_OBJECT *obj,long disp)

{
  ushort uVar1;
  _D3_OBJECT *p_Var2;
  
  p_Var2 = obj->child;
  while (p_Var2 != (_D3_OBJECT *)0x0) {
    if (disp == 0) {
      uVar1 = p_Var2->display_mode & 0xffef;
    }
    else {
      uVar1 = p_Var2->display_mode | 0x10;
    }
    p_Var2->display_mode = uVar1;
    p_Var2 = p_Var2->next;
  }
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Monster_StopChilds(struct _D3_OBJECT *o /*$a0*/)
 // line 913, offset 0x80069ccc
	/* begin block 1 */
		// Start line: 915
		// Start offset: 0x80069CCC
		// Variables:
	// 		struct _D3_OBJECT *obj; // $a0
	/* end block 1 */
	// End offset: 0x80069D2C
	// End Line: 923

	/* begin block 2 */
		// Start line: 1950
	/* end block 2 */
	// End Line: 1951

void Monster_StopChilds(_D3_OBJECT *o)

{
  _D3_OBJECT *p_Var1;
  
  p_Var1 = o->child;
  while (p_Var1 != (_D3_OBJECT *)0x0) {
    if (((p_Var1->display_mode & 0x40U) != 0) && (((int)p_Var1->collision_mode & 0x8000U) == 0)) {
      *(ushort *)((int)p_Var1->description + 0x28) =
           *(ushort *)((int)p_Var1->description + 0x28) & 0xfffe;
    }
    p_Var1 = p_Var1->next;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Monster_SyncChilds(struct _D3_OBJECT *o /*$a0*/, struct M_OBJECT *mo /*$s3*/, struct _MONSTER *monst /*$s2*/, long Animation /*$s4*/, long Animation2 /*stack 16*/)
 // line 926, offset 0x80069d34
	/* begin block 1 */
		// Start line: 927
		// Start offset: 0x80069D34
		// Variables:
	// 		struct _D3_OBJECT *obj; // $s0
	/* end block 1 */
	// End offset: 0x80069E10
	// End Line: 948

	/* begin block 2 */
		// Start line: 1975
	/* end block 2 */
	// End Line: 1976

void Monster_SyncChilds(_D3_OBJECT *o,M_OBJECT *mo,_MONSTER *monst,long Animation,long Animation2)

{
  M_OBJECT *obj;
  long Anim;
  _D3_OBJECT *p_Var1;
  
  p_Var1 = o->child;
  while (p_Var1 != (_D3_OBJECT *)0x0) {
    if (((p_Var1->display_mode & 0x40U) != 0) && ('\0' < *(char *)((int)&p_Var1[1].pos.vx + 1))) {
      if (((monst->flags & 0x200U) == 0) || (Animation2 == 0)) {
        obj = (M_OBJECT *)p_Var1->description;
        Anim = Animation;
      }
      else {
        obj = (M_OBJECT *)p_Var1->description;
        Anim = Animation2;
      }
      Manim_SetAnim(obj,Anim);
      Manim_GoToFrame((M_OBJECT *)p_Var1->description,
                      (int)((uint)*(ushort *)&(mo->Env).nPivot << 0x10) >> 0x14);
      *(ushort *)((int)p_Var1->description + 0x28) =
           *(ushort *)((int)p_Var1->description + 0x28) | 4;
      *(short *)((int)p_Var1->description + 0x26) = (monst->eff_pos).pad;
    }
    p_Var1 = p_Var1->next;
  }
  return;
}



// decompiled code
// original method signature: 
// struct _D3_OBJECT * /*$ra*/ Monster_GetBrother(struct _D3_OBJECT *o /*$a0*/, long opt2 /*$a1*/)
 // line 950, offset 0x80069e30
	/* begin block 1 */
		// Start line: 952
		// Start offset: 0x80069E30
		// Variables:
	// 		struct _D3_OBJECT *obj; // $v1
	/* end block 1 */
	// End offset: 0x80069E70
	// End Line: 960

	/* begin block 2 */
		// Start line: 2025
	/* end block 2 */
	// End Line: 2026

_D3_OBJECT * Monster_GetBrother(_D3_OBJECT *o,long opt2)

{
  _D3_OBJECT *p_Var1;
  
  p_Var1 = o->father->child;
  while( true ) {
    if (p_Var1 == (_D3_OBJECT *)0x0) {
      return (_D3_OBJECT *)0x0;
    }
    if ((p_Var1 != o) && ((int)p_Var1[1].pos.vz == opt2)) break;
    p_Var1 = p_Var1->next;
  }
  return p_Var1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Monster_TestLastSpell(struct _D3_OBJECT *o /*$a0*/, long index /*$a1*/)
 // line 962, offset 0x80069e80
	/* begin block 1 */
		// Start line: 2049
	/* end block 1 */
	// End Line: 2050

long Monster_TestLastSpell(_D3_OBJECT *o,long index)

{
  long lVar1;
  
  lVar1 = 1;
  if ((((int)o->collision_mode & 0x8000U) == 0) ||
     ((*(uint *)(*(int *)&o[1].last_pos + 0x14c) & 1 << (index & 0x1fU)) == 0)) {
    lVar1 = 0;
  }
  return lVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Monster_Action_SetBoundingBox(long sm /*$a0*/, long height /*$s1*/)
 // line 977, offset 0x80069ebc
	/* begin block 1 */
		// Start line: 978
		// Start offset: 0x80069EBC
		// Variables:
	// 		struct _MONSTER *monst; // $v0
	// 		struct _D3_OBJECT *obj; // $s0
	/* end block 1 */
	// End offset: 0x80069F30
	// End Line: 998

	/* begin block 2 */
		// Start line: 2079
	/* end block 2 */
	// End Line: 2080

/* WARNING: Type propagation algorithm not settling */

void Monster_Action_SetBoundingBox(long sm,long height)

{
  short sVar1;
  _D3_OBJECT *o;
  
  o = ((_D3_OBJECT *)TaskCurrent->local)->next;
  if (sm == 0) {
    sVar1 = (short)height;
    *(short *)&o[1].prec = sVar1;
    *(short *)&o[1].father = sVar1;
    *(short *)&o[1].handle = sVar1;
    o[1].collision_mode = sVar1;
    D3_SetCollBits(o,0x4000);
  }
  else {
    D3_ClearCollBits(o,0x4000);
    sVar1 = (short)((int)(height + ((uint)height >> 0x1f)) >> 1);
    *(short *)&o[1].prec = sVar1;
    *(short *)&o[1].father = sVar1;
    *(short *)&o[1].handle = sVar1;
    o[1].collision_mode = sVar1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Monster_Action_RunAnimationSpeed(long AnimNr /*$a0*/, long mode /*$a1*/, long speed /*$s0*/, long Gravity /*$s4*/, long Sound /*stack 16*/)
 // line 1002, offset 0x80069f44
	/* begin block 1 */
		// Start line: 1003
		// Start offset: 0x80069F44
		// Variables:
	// 		struct _MONSTER *monst; // $s2
	// 		struct M_OBJECT *mo; // $s1
	/* end block 1 */
	// End offset: 0x8006A028
	// End Line: 1018

	/* begin block 2 */
		// Start line: 2134
	/* end block 2 */
	// End Line: 2135

/* WARNING: Type propagation algorithm not settling */

void Monster_Action_RunAnimationSpeed(long AnimNr,long mode,long speed,long Gravity,long Sound)

{
  ushort uVar1;
  _D3_OBJECT *p_Var2;
  M_OBJECT *obj;
  _D3_OBJECT *p_Var3;
  
  p_Var3 = (_D3_OBJECT *)TaskCurrent->local;
  obj = (M_OBJECT *)p_Var3->next->description;
  *(short *)&p_Var3->list = (short)mode;
  Manim_SetAnim(obj,AnimNr);
  uVar1 = (obj->Env).Obj.normal_top.vx;
  (obj->Env).Obj.normal_top.pad = (short)speed;
  while ((uVar1 & 0x4000) == 0) {
    if ((((obj->Env).Obj.vert_top.pad & 1U) != 0) && (Sound != -1)) {
      D3_PlaySound(p_Var3->next,(short)Sound);
    }
    if ((Gravity != 0) && (p_Var2 = p_Var3->next, ((int)p_Var2->collision_state & 0xc000U) != 0)) {
      *(short *)((int)&p_Var2->pos + 4) = *(short *)((int)&p_Var2->pos + 4) + 5;
    }
    Task_Next();
    uVar1 = (obj->Env).Obj.normal_top.vx;
  }
  (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Monster_Action_SlayDirection(struct _D3_OBJECT *o /*$s1*/, long Anim /*$s7*/, long dist /*$s6*/, struct _D3_OBJECT *to /*$s3*/, struct _MONSTER *monst /*stack 16*/, long sound /*stack 20*/)
 // line 1029, offset 0x8006a058
	/* begin block 1 */
		// Start line: 1030
		// Start offset: 0x8006A058
		// Variables:
	// 		struct M_OBJECT *mo; // $s2
	// 		struct _D3_OBJECT *tmpobj; // $v0
	// 		long m_dir; // $s0
	// 		long dir; // $s0
	// 		long startZ; // $s0
	/* end block 1 */
	// End offset: 0x8006A49C
	// End Line: 1138

	/* begin block 2 */
		// Start line: 2197
	/* end block 2 */
	// End Line: 2198

void Monster_Action_SlayDirection
               (_D3_OBJECT *o,long Anim,long dist,_D3_OBJECT *to,_MONSTER *monst,long sound)

{
  short sVar1;
  long bits;
  _D3_OBJECT *p_Var2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  short sVar7;
  M_OBJECT *obj;
  
  obj = (M_OBJECT *)o->description;
  if ((int)monst->height + (int)(o->pos).vz < (int)(to->pos).vz) {
    return;
  }
  monst->mode = 7;
  sVar7 = (o->last_pos).vz;
  Manim_ForceAnim(obj,Anim);
  Monster_SyncChilds(o,obj,monst,Anim,0);
  (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
  Monster_StopChilds(o);
  iVar4 = dist;
  if (dist < 0) {
    iVar4 = -dist;
  }
  while (bits = D3_GoToDir(o,(int)(to->pos).vx - (int)(o->pos).vx,
                           (int)(to->pos).vy - (int)(o->pos).vy,0xa0), bits != 0) {
    Task_Next();
    if (iVar4 < LONG_ARRAY_800b2e40[0]) {
      p_Var2 = o->child;
      (o->pos).vz = sVar7;
      (o->last_pos).vz = sVar7;
      while (p_Var2 != (_D3_OBJECT *)0x0) {
        uVar6 = *(undefined4 *)&(o->pos).vz;
        *(undefined4 *)&p_Var2->pos = *(undefined4 *)&o->pos;
        *(undefined4 *)&(p_Var2->pos).vz = uVar6;
        uVar6 = *(undefined4 *)&(o->last_pos).vz;
        *(undefined4 *)&p_Var2->last_pos = *(undefined4 *)&o->last_pos;
        *(undefined4 *)&(p_Var2->last_pos).vz = uVar6;
        p_Var2 = p_Var2->next;
      }
      return;
    }
  }
  monst->mode = 0x7b;
  iVar4 = dist;
  if (dist < 0) {
    iVar4 = -dist;
  }
  if (iVar4 < LONG_ARRAY_800b2e40[0]) goto LAB_8006a490;
  Manim_ForceAnim(obj,Anim);
  Monster_SyncChilds(o,obj,monst,Anim,0);
  uVar3 = (obj->Env).Obj.normal_top.vx;
  sVar7 = (obj->Env).Obj.vert_top.pad;
  *(undefined2 *)((int)&(obj->Env).Obj.n_vert + 2) = 0;
  (obj->Env).Obj.normal_top.vx = uVar3 | 4;
  if (((int)sVar7 & 0x8000U) == 0) {
    while ((uVar3 & 0x4000) == 0) {
      D3_GoToDir(o,(int)(to->pos).vx - (int)(o->pos).vx,(int)(to->pos).vy - (int)(o->pos).vy,0xa0);
      p_Var2 = o->child;
      while (p_Var2 != (_D3_OBJECT *)0x0) {
        uVar6 = *(undefined4 *)&(o->rot).vz;
        *(undefined4 *)&p_Var2->rot = *(undefined4 *)&o->rot;
        *(undefined4 *)&(p_Var2->rot).vz = uVar6;
        p_Var2 = p_Var2->next;
      }
      Task_Next();
      if ((sound != -1) && (((obj->Env).Obj.vert_top.pad & 1U) != 0)) {
        D3_PlaySound(monst->obj,(short)sound);
      }
      if (((int)(obj->Env).Obj.vert_top.pad & 0x8000U) != 0) break;
      uVar3 = (obj->Env).Obj.normal_top.vx;
    }
  }
  monst->mode = 0xea;
  if (dist < 0) {
    dist = 0x5a;
  }
  if ((LONG_ARRAY_800b2e40[0] <= dist) &&
     (sVar7 = (o->rot).vz, sVar1 = *(short *)((int)&(obj->Env).Obj.n_vert + 2),
     bits = Direction((int)(to->pos).vx - (int)(o->pos).vx,(int)(to->pos).vy - (int)(o->pos).vy),
     (bits - (((int)sVar7 + (int)sVar1 & 0xfffU) - 0x400) & 0xfff) < 0x800)) {
    iVar5 = (int)(o->pos).vz;
    iVar4 = (int)(to->pos).vz;
    if ((iVar4 < (int)monst->height + iVar5) && (iVar5 < iVar4 + 200)) {
      D3_SetCollBits(o,2);
      Boxes_ObjectFound(o,to,0);
      MSensor_AddAgression(monst,-200);
      uVar3 = monst->flags & 3;
      if (((monst->flags & 3U) != 0) && ((to->collision_mode & 0x1000U) != 0)) {
        if (uVar3 == 1) {
          bits = 2;
        }
        else {
          bits = 8;
          if (uVar3 != 2) goto LAB_8006a3f0;
        }
        Pl_SetStateBits((_PLAYER *)to,bits);
      }
LAB_8006a3f0:
      D3_ClearCollBits(o,2);
    }
  }
  monst->mode = 0x159;
  uVar3 = o->collision_state;
  sVar7 = 0;
  while ((uVar3 & 0x4000) == 0) {
    sVar7 = sVar7 + -5;
    (o->pos).vz = (o->pos).vz + sVar7;
    uVar3 = (obj->Env).Obj.normal_top.vx;
    if ((uVar3 & 0x4000) != 0) {
      (obj->Env).Obj.normal_top.vx = uVar3 & 0xfffe;
      Monster_StopChilds(o);
    }
    Task_Next();
    uVar3 = o->collision_state;
  }
  monst->mode = 0x1c8;
  Manim_WaitAnim(obj);
  monst->mode = 0x237;
  (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
  Monster_StopChilds(o);
LAB_8006a490:
  *(undefined **)&monst->actionmask = PTR_DAT_800ad81c;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Monster_Action_SlayingObject(struct _D3_OBJECT *o /*$s2*/, long Anim /*$s5*/, long dist /*$s6*/, struct _D3_OBJECT *to /*$s3*/, struct _MONSTER *monst /*stack 16*/, long sound /*stack 20*/)
 // line 1140, offset 0x8006a4cc
	/* begin block 1 */
		// Start line: 1141
		// Start offset: 0x8006A4CC
		// Variables:
	// 		struct M_OBJECT *mo; // $s1
	// 		long distance; // $v0
	// 		long m_dir; // $s0
	// 		long dir; // $v0
	// 		long motionfollow; // $s5
	/* end block 1 */
	// End offset: 0x8006A718
	// End Line: 1193

	/* begin block 2 */
		// Start line: 2444
	/* end block 2 */
	// End Line: 2445

void Monster_Action_SlayingObject
               (_D3_OBJECT *o,long Anim,long dist,_D3_OBJECT *to,_MONSTER *monst,long sound)

{
  short sVar1;
  short sVar2;
  long d1;
  ushort uVar3;
  int iVar4;
  int iVar5;
  M_OBJECT *obj;
  
  obj = (M_OBJECT *)o->description;
  if ((int)monst->height + (int)(o->pos).vz < (int)(to->pos).vz) {
    return;
  }
  if (dist + 0x78 < LONG_ARRAY_800b2e40[0]) {
    return;
  }
  monst->mode = 7;
  Manim_ForceAnim(obj,Anim);
  Monster_SyncChilds(o,obj,monst,Anim,0);
  sVar1 = (obj->Env).Obj.vert_top.pad;
  sVar2 = (o->rot).vz;
  while ((((int)sVar1 & 0x8000U) == 0 && (((obj->Env).Obj.normal_top.vx & 0x4000U) == 0))) {
    d1 = Direction((int)(to->pos).vx - (int)(o->pos).vx,(int)(to->pos).vy - (int)(o->pos).vy);
    DeltaDirection(d1,(int)sVar2);
    Task_Next();
    if ((sound != -1) && (((obj->Env).Obj.vert_top.pad & 1U) != 0)) {
      D3_PlaySound(monst->obj,(short)sound);
    }
    sVar1 = (obj->Env).Obj.vert_top.pad;
  }
  if ((dist < LONG_ARRAY_800b2e40[0]) ||
     (sVar2 = (o->rot).vz,
     d1 = Direction((int)(to->pos).vx - (int)(o->pos).vx,(int)(to->pos).vy - (int)(o->pos).vy),
     0x7ff < (d1 - ((int)sVar2 + -0x400) & 0xfffU))) goto LAB_8006a6f0;
  iVar5 = (int)(o->pos).vz;
  iVar4 = (int)(to->pos).vz;
  if (((int)monst->height + iVar5 <= iVar4) || (iVar4 + 200 <= iVar5)) goto LAB_8006a6f0;
  D3_SetCollBits(o,2);
  Boxes_ObjectFound(o,to,0);
  MSensor_AddAgression(monst,-200);
  uVar3 = monst->flags & 3;
  if (((monst->flags & 3U) != 0) && ((to->collision_mode & 0x1000U) != 0)) {
    if (uVar3 == 1) {
      d1 = 2;
    }
    else {
      d1 = 8;
      if (uVar3 != 2) goto LAB_8006a6e8;
    }
    Pl_SetStateBits((_PLAYER *)to,d1);
  }
LAB_8006a6e8:
  D3_ClearCollBits(o,2);
LAB_8006a6f0:
  Manim_WaitAnim(obj);
  (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
  Monster_StopChilds(o);
  *(undefined **)&monst->actionmask = PTR_DAT_800ad81c;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Monster_Action_Slaying(long Anim /*$a0*/, long dist /*$v1*/, struct _D3_OBJECT *to /*$t0*/, long sound /*$a3*/)
 // line 1195, offset 0x8006a740
	/* begin block 1 */
		// Start line: 1196
		// Start offset: 0x8006A740
		// Variables:
	// 		struct _MONSTER *monst; // $v0
	/* end block 1 */
	// End offset: 0x8006A740
	// End Line: 1196

	/* begin block 2 */
		// Start line: 2570
	/* end block 2 */
	// End Line: 2571

void Monster_Action_Slaying(long Anim,long dist,_D3_OBJECT *to,long sound)

{
  Monster_Action_SlayingObject
            (((_MONSTER *)TaskCurrent->local)->obj,Anim,dist,to,(_MONSTER *)TaskCurrent->local,sound
            );
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Monster_FearFindFriends(struct _MONSTER *monst /*$t0*/)
 // line 1204, offset 0x8006a788
	/* begin block 1 */
		// Start line: 1205
		// Start offset: 0x8006A788
		// Variables:
	// 		long mine; // $t3
	// 		long res; // $a2
	// 		long i; // $a3
	// 		long shift; // $t1
	/* end block 1 */
	// End offset: 0x8006A88C
	// End Line: 1228

	/* begin block 2 */
		// Start line: 2591
	/* end block 2 */
	// End Line: 2592

long Monster_FearFindFriends(_MONSTER *monst)

{
  short sVar1;
  ushort uVar2;
  _PVL_HEADER *p_Var3;
  uint uVar4;
  _MONSTER *p_Var5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  p_Var3 = Pvl_File;
  iVar7 = 0;
  uVar8 = 0;
  sVar1 = monst->zone_fear;
  iVar6 = 0;
  p_Var5 = Pvl_Monsters;
  if (0 < Pvl_File->n_monsters) {
    do {
      if (((p_Var5->zone_fear == sVar1) && (p_Var5 != monst)) && ((p_Var5->flags & 0x400U) == 0)) {
        p_Var5->flags = p_Var5->flags | 0x400;
        uVar2 = p_Var5->obj[1].pos.vz;
        p_Var5->obj[1].pos.vz = uVar2 & 0xff00 | (ushort)(((uint)uVar2 & 0xff) >> 1);
        p_Var5->zb_low = p_Var5->zb_low | monst->zb_low;
        uVar4 = monst->zb_high;
        iVar6 = 1;
        p_Var5->action = 0xf;
        p_Var5->zb_high = p_Var5->zb_high | uVar4;
      }
      iVar7 = iVar7 + 1;
      uVar8 = uVar8 + 1;
      p_Var5 = p_Var5 + 1;
    } while (iVar7 < (int)p_Var3->n_monsters);
  }
  if (iVar6 != 0) {
    uVar2 = monst->obj[1].pos.vz;
    monst->obj[1].pos.vz = uVar2 & 0xff00 | (ushort)((int)((uint)uVar2 & 0xff) >> (uVar8 & 0x1f));
  }
  return iVar6;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Monster_Action_Falling(short AnimNr /*$fp*/)
 // line 1232, offset 0x8006a894
	/* begin block 1 */
		// Start line: 1233
		// Start offset: 0x8006A894
		// Variables:
	// 		struct _MONSTER *monst; // $s5
	// 		struct _D3_OBJECT *obj; // $s1
	// 		struct M_OBJECT *mo; // $s2
	// 		long speed; // $s4
	// 		long speedx; // $s7
	// 		long speedy; // $s6
	// 		long hitcount; // $s3
	/* end block 1 */
	// End offset: 0x8006AA14
	// End Line: 1277

	/* begin block 2 */
		// Start line: 2664
	/* end block 2 */
	// End Line: 2665

/* WARNING: Type propagation algorithm not settling */

void Monster_Action_Falling(short AnimNr)

{
  TASK *pTVar1;
  int iVar2;
  int iVar3;
  int Anim;
  _D3_OBJECT *o;
  M_OBJECT *obj;
  int iVar4;
  short sVar5;
  _D3_OBJECT *p_Var6;
  
  p_Var6 = (_D3_OBJECT *)TaskCurrent->local;
  sVar5 = 0;
  o = p_Var6->next;
  obj = (M_OBJECT *)o->description;
  iVar4 = 0;
  iVar2 = rcos((int)(o->rot).vz);
  iVar3 = rsin((int)(o->rot).vz);
  Anim = (int)AnimNr;
  if (Anim != 0) {
    Manim_SetAnim(obj,Anim);
  }
  TaskCurrent->event_enable = 0;
  *(undefined2 *)&p_Var6->list = 0xb;
  if (Anim != 0) {
    while (((int)(obj->Env).Obj.vert_top.pad & 0x8000U) == 0) {
      (o->pos).vx = (o->pos).vx + (short)(iVar2 >> 10);
      (o->pos).vy = (o->pos).vy + (short)(iVar3 >> 10);
      Task_Next();
    }
  }
  D3_SetCollBits(o,9);
  (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
  do {
    if ((o->pos).vz < -1999) goto LAB_8006a9f0;
    if ((o->collision_state & 0x4000U) != 0) {
      iVar4 = iVar4 + 1;
    }
    sVar5 = sVar5 + -5;
    (o->pos).vz = (o->pos).vz + sVar5;
    Task_Next();
  } while (iVar4 != 3);
  if ((o->pos).vz < -1999) {
LAB_8006a9f0:
    *(undefined2 *)&p_Var6->list = 0x11;
  }
  if (AnimNr != 0) {
    (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx | 1;
    Manim_WaitAnim(obj);
  }
  pTVar1 = TaskCurrent;
  (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
  pTVar1->event_enable = 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Monster_Action_FollowObject(struct _D3_OBJECT *target /*$s2*/, short AnimNr /*$a1*/)
 // line 1282, offset 0x8006aa60
	/* begin block 1 */
		// Start line: 1283
		// Start offset: 0x8006AA60
		// Variables:
	// 		struct _MONSTER *monst; // $a2
	// 		struct _D3_OBJECT *o; // $s0
	// 		struct M_OBJECT *mo; // $s1
	/* end block 1 */
	// End offset: 0x8006AB18
	// End Line: 1306

	/* begin block 2 */
		// Start line: 2782
	/* end block 2 */
	// End Line: 2783

/* WARNING: Type propagation algorithm not settling */

void Monster_Action_FollowObject(_D3_OBJECT *target,short AnimNr)

{
  _D3_OBJECT *o;
  M_OBJECT *obj;
  
  o = ((_D3_OBJECT *)TaskCurrent->local)->next;
  obj = (M_OBJECT *)o->description;
  if (((target->collision_mode & 0x1000U) == 0) || (*(char *)&target[4].matrices != '\x06')) {
    *(undefined2 *)&((_D3_OBJECT *)TaskCurrent->local)->list = 0x10;
    Manim_SetAnim(obj,(int)AnimNr);
    while (((obj->Env).Obj.normal_top.vx & 0x4000U) == 0) {
      D3_GoToDir(o,(int)(target->pos).vx - (int)(o->pos).vx,(int)(target->pos).vy - (int)(o->pos).vy
                 ,0x46);
      Task_Next();
    }
  }
  else {
    Task_Next();
  }
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ Monster_Action_WalkHandling(struct M_OBJECT *mo /*$s5*/, struct _D3_OBJECT *o /*$s3*/, short xx /*$s7*/, short yy /*$s6*/, int soundR /*stack 16*/, int soundL /*stack 20*/, int dist /*stack 24*/)
 // line 1309, offset 0x8006ab30
	/* begin block 1 */
		// Start line: 1310
		// Start offset: 0x8006AB30
		// Variables:
	// 		struct _D3_OBJECT *obj; // $v1
	// 		long distance; // $s4
	// 		long direct; // $s2
	// 		long movedangle; // $s1
	/* end block 1 */
	// End offset: 0x8006B0D8
	// End Line: 1392

	/* begin block 2 */
		// Start line: 2842
	/* end block 2 */
	// End Line: 2843

short Monster_Action_WalkHandling
                (M_OBJECT *mo,_D3_OBJECT *o,short xx,short yy,int soundR,int soundL,int dist)

{
  short sVar1;
  ushort uVar2;
  short sVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  int iVar7;
  _D3_OBJECT *p_Var8;
  undefined4 uVar9;
  short sVar10;
  
  iVar4 = Distance2D((int)xx,(int)yy,(int)(o->pos).vx,(int)(o->pos).vy);
  lVar5 = Direction((int)xx - (int)(o->pos).vx,(int)yy - (int)(o->pos).vy);
  sVar3 = (o->rot).vz;
  sVar10 = (short)dist;
  iVar7 = iVar4;
  if (iVar4 < 0) {
    iVar7 = -iVar4;
  }
  if (iVar7 <= (int)sVar10) goto LAB_8006afb0;
  do {
    do {
      if (((mo->Env).Obj.normal_top.vx & 0x4000U) != 0) goto LAB_8006b090;
      if (((mo->Env).Obj.vert_top.pad & 0x4000U) != 0) {
        lVar6 = D3_GoToDir(o,(int)xx - (int)(o->pos).vx,(int)yy - (int)(o->pos).vy,0x50);
        if (lVar6 < 0) {
          iVar7 = rcos((int)(o->rot).vz);
          sVar1 = (o->rot).vz;
          (o->pos).vx = (o->pos).vx + (short)((iVar7 << 1) >> 0xc);
          iVar7 = rsin((int)sVar1);
          (o->pos).vy = (o->pos).vy + (short)((iVar7 << 1) >> 0xc);
        }
        if (0 < lVar6) {
          iVar7 = rcos((int)(o->rot).vz);
          sVar1 = (o->rot).vz;
          (o->pos).vx = (o->pos).vx - (short)((iVar7 * 100) / 0x3c >> 0xc);
          iVar7 = rsin((int)sVar1);
          (o->pos).vy = (o->pos).vy - (short)((iVar7 * 100) / 0x3c >> 0xc);
        }
      }
      if (((mo->Env).Obj.vert_top.pad & 0x2000U) != 0) {
        lVar6 = D3_GoToDir(o,(int)xx - (int)(o->pos).vx,(int)yy - (int)(o->pos).vy,0x50);
        if (lVar6 < 0) {
          iVar7 = rcos((int)(o->rot).vz);
          sVar1 = (o->rot).vz;
          (o->pos).vx = (o->pos).vx - (short)((iVar7 * 100) / 0x50 >> 0xc);
          iVar7 = rsin((int)sVar1);
          (o->pos).vy = (o->pos).vy - (short)((iVar7 * 100) / 0x50 >> 0xc);
        }
        if (0 < lVar6) {
          iVar7 = rcos((int)(o->rot).vz);
          sVar1 = (o->rot).vz;
          (o->pos).vx = (o->pos).vx + (short)((iVar7 * 100) / 0x46 >> 0xc);
          iVar7 = rsin((int)sVar1);
          (o->pos).vy = (o->pos).vy + (short)((iVar7 * 100) / 0x46 >> 0xc);
        }
      }
      if (((short)soundR != -1) && (((mo->Env).Obj.vert_top.pad & 1U) != 0)) {
        D3_PlaySound(o,(short)soundR);
      }
      if (((short)soundL != -1) && (((mo->Env).Obj.vert_top.pad & 2U) != 0)) {
        D3_PlaySound(o,(short)soundL);
      }
      iVar4 = Distance2D((int)xx,(int)yy,(int)(o->pos).vx,(int)(o->pos).vy);
      p_Var8 = o->child;
      while (p_Var8 != (_D3_OBJECT *)0x0) {
        if ((p_Var8->display_mode & 0x40U) != 0) {
          uVar9 = *(undefined4 *)&(o->rot).vz;
          *(undefined4 *)&p_Var8->rot = *(undefined4 *)&o->rot;
          *(undefined4 *)&(p_Var8->rot).vz = uVar9;
          (p_Var8->pos).vx = (o->pos).vx;
          (p_Var8->pos).vy = (o->pos).vy;
        }
        p_Var8 = p_Var8->next;
      }
      Task_Next();
      if (((int)(mo->Env).Obj.vert_top.pad & 0x8000U) != 0) {
        return -1;
      }
      iVar7 = iVar4;
      if (iVar4 < 0) {
        iVar7 = -iVar4;
      }
    } while ((int)sVar10 < iVar7);
LAB_8006afb0:
  } while (0x400 < ((lVar5 - (int)sVar3) + 0x200U & 0xfff));
  uVar2 = (mo->Env).Obj.normal_top.vx;
  while ((uVar2 & 0x4000) == 0) {
    p_Var8 = o->child;
    while (p_Var8 != (_D3_OBJECT *)0x0) {
      if ((p_Var8->display_mode & 0x40U) != 0) {
        (p_Var8->pos).vx = (o->pos).vx;
        (p_Var8->pos).vy = (o->pos).vy;
      }
      p_Var8 = p_Var8->next;
    }
    Task_Next();
    if (((short)soundR != -1) && (((mo->Env).Obj.vert_top.pad & 1U) != 0)) {
      D3_PlaySound(o,(short)soundR);
    }
    if (((short)soundL != -1) && (((mo->Env).Obj.vert_top.pad & 2U) != 0)) {
      D3_PlaySound(o,(short)soundL);
    }
    uVar2 = (mo->Env).Obj.normal_top.vx;
  }
LAB_8006b090:
  if (iVar4 < 0) {
    iVar4 = -iVar4;
  }
  sVar3 = 0;
  if (((int)sVar10 <= iVar4) &&
     ((((int)(mo->Env).Obj.vert_top.pad & 0x8000U) == 0 || (sVar3 = 0, (int)sVar10 + 100 <= iVar4)))
     ) {
    sVar3 = 1;
  }
  return sVar3;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Monster_Action_WalkTo(short x_given /*stack -96*/, short y_given /*stack -88*/, short zz /*stack -80*/, struct _D3_OBJECT *target /*$s7*/, int dist /*stack 16*/, int AnimSt /*stack 20*/, int AnimLoop /*stack 24*/, int AnimHalf /*stack 28*/, int AnimStop /*stack 32*/, int Sound /*stack 36*/, long option /*stack 40*/)
 // line 1395, offset 0x8006b108
	/* begin block 1 */
		// Start line: 1396
		// Start offset: 0x8006B108
		// Variables:
	// 		struct _MONSTER *monst; // $s2
	// 		struct _D3_OBJECT *o; // $s1
	// 		struct M_OBJECT *mo; // $s3
	// 		long ret; // $s6
	// 		long direct; // $v0
	// 		long x; // $a2
	// 		long y; // $v0
	// 		long xx; // $s5
	// 		long yy; // $s4
	// 		short foundpath[3]; // stack offset -104
	/* end block 1 */
	// End offset: 0x8006B6C4
	// End Line: 1519

	/* begin block 2 */
		// Start line: 3041
	/* end block 2 */
	// End Line: 3042

long Monster_Action_WalkTo
               (short x_given,short y_given,short zz,_D3_OBJECT *target,int dist,int AnimSt,
               int AnimLoop,int AnimHalf,int AnimStop,int Sound,long option)

{
  short xx;
  short sVar1;
  short yy;
  int iVar2;
  int iVar3;
  _ENEMYZONE *p_Var4;
  short xx_00;
  long Anim;
  uint Anim_00;
  int dist_00;
  _D3_OBJECT *o;
  _MONSTER *monst;
  M_OBJECT *obj;
  short yy_00;
  int y1;
  int x1;
  int soundR;
  short local_68;
  short local_66;
  short local_60;
  short local_58;
  short local_50;
  short local_48;
  short local_40;
  short local_38;
  short local_30;
  
  xx = 1;
  local_48 = (short)dist;
  local_40 = (short)AnimHalf;
  monst = (_MONSTER *)TaskCurrent->local;
  local_38 = (short)AnimStop;
  o = monst->obj;
  local_30 = (short)Sound;
  obj = (M_OBJECT *)o->description;
  local_60 = x_given;
  local_58 = y_given;
  local_50 = zz;
  if (target != (_D3_OBJECT *)0x0) {
    local_50 = (target->pos).vz;
    local_60 = (target->pos).vx;
    local_58 = (target->pos).vy;
  }
  yy_00 = local_58;
  xx_00 = local_60;
  x1 = (int)local_60;
  y1 = (int)local_58;
  Distance2D(x1,y1,(int)(o->pos).vx,(int)(o->pos).vy);
  monst->flags = monst->flags & 0xfeff;
  iVar2 = option >> 0x10;
  if (monst->mode != 1) {
    (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
    Monster_StopChilds(o);
    Anim = (long)(short)AnimSt;
    if (Anim != 0) {
      Manim_SetAnim(obj,Anim);
      if (option == 0) {
LAB_8006b250:
        Monster_SyncChilds(o,obj,monst,Anim,0);
      }
      else {
        if (iVar2 == 1) {
          Anim = (option & 0xffffU) - 1;
          goto LAB_8006b250;
        }
      }
      xx = Monster_Action_WalkHandling(obj,o,xx_00,yy_00,-1,-1,(int)local_48);
      Anim = Direction(x1 - (int)(o->pos).vx,y1 - (int)(o->pos).vy);
      if ((((Anim - (int)(o->rot).vz) + 0x200U & 0xfff) < 0x400) && (xx == 0)) {
        monst->flags = monst->flags | 0x100;
      }
    }
  }
  monst->mode = 1;
  Anim_00 = SEXT24((short)AnimLoop);
  if (Anim_00 == 0) goto LAB_8006b530;
  Manim_SetAnim(obj,Anim_00);
  if (option == 0) {
LAB_8006b340:
    Monster_SyncChilds(o,obj,monst,Anim_00,0);
  }
  else {
    if (iVar2 == 1) {
      Anim_00 = option & 0xffff;
      goto LAB_8006b340;
    }
  }
  if ((monst->flags & 0x180U) == 0) {
    soundR = (int)local_30;
    dist_00 = (int)local_48;
    do {
      if (target != (_D3_OBJECT *)0x0) {
        x1 = (int)(target->pos).vx;
        y1 = (int)(target->pos).vy;
        local_50 = (target->pos).vz;
      }
      yy_00 = (short)y1;
      xx_00 = (short)x1;
      sVar1 = Zone_GetEnemyZonePath
                        ((o->pos).vx,(o->pos).vy,(o->pos).vz,xx_00,y1,(int)local_50,monst->zb_low,
                         monst->zb_high,&local_68);
      xx = xx_00;
      yy = yy_00;
      if (((sVar1 != 0) && (xx = local_68, yy = local_66, local_68 == 0x7fff)) &&
         (xx = local_68, yy = local_66, local_66 == 0x7fff)) {
        p_Var4 = monst->zone_current;
        xx = (short)((int)p_Var4->x1 + (int)p_Var4->x2 >> 1);
        yy = (short)((int)p_Var4->y1 + (int)p_Var4->y2 >> 1);
      }
      xx = Monster_Action_WalkHandling(obj,o,xx,yy,soundR,soundR,dist_00);
      Task_Next();
      iVar3 = Distance2D((int)local_60,(int)local_58,(int)(o->pos).vx,(int)(o->pos).vy);
      if (iVar3 < 0) {
        iVar3 = -iVar3;
      }
      if (iVar3 <= dist_00) {
        monst->flags = monst->flags | 0x100;
      }
      if (((target != (_D3_OBJECT *)0x0) &&
          (Anim = Direction(x1 - (int)(o->pos).vx,y1 - (int)(o->pos).vy),
          ((Anim - (int)(o->rot).vz) + 0x200U & 0xfff) < 0x400)) && (xx == 0)) {
        monst->flags = monst->flags | 0x100;
      }
    } while ((monst->flags & 0x180U) == 0);
  }
LAB_8006b530:
  y1 = (int)local_38;
  if ((y1 != 0) && (xx != -1)) {
    Manim_SetAnim(obj,y1);
    if (option == 0) {
      Monster_SyncChilds(o,obj,monst,y1,0);
    }
    else {
      Monster_StopChilds(o);
    }
    Monster_Action_WalkHandling(obj,o,xx_00,yy_00,(int)local_30,(int)local_30,(int)local_48);
  }
  y1 = (int)local_40;
  if ((y1 != 0) && (xx == -1)) {
    Manim_SetAnim(obj,y1);
    if (option == 0) {
      Monster_SyncChilds(o,obj,monst,y1,0);
    }
    else {
      Monster_StopChilds(o);
    }
    Monster_Action_WalkHandling(obj,o,xx_00,yy_00,(int)local_30,(int)local_30,(int)local_48);
  }
  monst->mode = 0x10;
  if (monst->action != 1) {
    monst->busy = -1;
  }
  (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
  if ((option != 0) && (iVar2 == 1)) {
    Monster_Animate_Child(o,0xffff,(option & 0xffffU) - 2);
    Manim_WaitAnim((M_OBJECT *)o->child->description);
  }
  Monster_StopChilds(o);
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Monster_Action_MoveTo3D(short xx /*stack -96*/, short yy /*stack -88*/, short zz /*stack -80*/, struct _D3_OBJECT *target /*$s5*/, int dist /*stack 16*/, int AnimLoop /*stack 20*/, int AnimAttack /*stack 24*/, int AnimXtra1 /*stack 28*/, int Anim180 /*stack 32*/, int Sound /*stack 36*/, int AttSound /*stack 40*/)
 // line 1532, offset 0x8006b700
	/* begin block 1 */
		// Start line: 1533
		// Start offset: 0x8006B700
		// Variables:
	// 		short foundpath[3]; // stack offset -104
	// 		struct _MONSTER *monst; // $s7
	// 		struct _D3_OBJECT *o; // $s1
	// 		struct M_OBJECT *mo; // $s6
	// 		struct _D3_OBJECT *co; // $s2
	// 		long distance; // $fp
	// 		long tmp; // $s0
	// 		long dir; // $v1
	// 		long usex; // $s3
	// 		long usey; // $s2
	// 		long usez; // $s4
	// 		long x; // $s0
	// 		long y; // $s2
	// 		long z; // $s4
	// 		long x2; // $v0
	// 		long y2; // $v1
	/* end block 1 */
	// End offset: 0x8006BE64
	// End Line: 1738

	/* begin block 2 */
		// Start line: 3351
	/* end block 2 */
	// End Line: 3352

/* WARNING: Type propagation algorithm not settling */

long Monster_Action_MoveTo3D
               (short xx,short yy,short zz,_D3_OBJECT *target,int dist,int AnimLoop,int AnimAttack,
               int AnimXtra1,int Anim180,int Sound,int AttSound)

{
  ushort uVar1;
  short sVar2;
  short xd;
  int iVar3;
  long lVar4;
  _D3_OBJECT *p_Var5;
  int x1;
  _D3_OBJECT *o;
  int y1;
  int iVar6;
  M_OBJECT *obj;
  _D3_OBJECT *p_Var7;
  short local_68;
  short local_66;
  short local_64;
  short local_60;
  short local_58;
  short local_50;
  short local_48;
  short local_40;
  short local_38;
  int local_30;
  int local_2c;
  
  local_48 = (short)dist;
  local_40 = (short)AnimLoop;
  p_Var7 = (_D3_OBJECT *)TaskCurrent->local;
  o = p_Var7->next;
  local_38 = (short)AttSound;
  obj = (M_OBJECT *)o->description;
  local_60 = xx;
  local_58 = yy;
  local_50 = zz;
  if ((target != (_D3_OBJECT *)0x0) &&
     (local_60 = xx, local_58 = yy, local_50 = zz, (*(ushort *)&p_Var7->handle & 0x10) != 0)) {
    local_60 = xx;
    local_58 = yy;
    local_50 = zz;
    if ((int)(short)AnimXtra1 != -1) {
      local_60 = xx;
      local_58 = yy;
      local_50 = zz;
      Manim_SetAnim(obj,(int)(short)AnimXtra1);
      Manim_WaitAnim(obj);
    }
    *(ushort *)&p_Var7->handle = *(ushort *)&p_Var7->handle & 0xffef;
  }
  *(undefined2 *)&p_Var7->list = 1;
  Manim_SetAnim(obj,(int)local_40);
  local_30 = (int)(short)Sound;
  local_2c = (int)(short)AnimAttack;
  (obj->Env).Obj.normal_top.pad = 0x180;
  (obj->Env).Obj.normal_top.vy = 0xc0;
  do {
    if (target == (_D3_OBJECT *)0x0) {
      iVar6 = (int)local_50;
      xd = local_60;
      sVar2 = local_58;
    }
    else {
      iVar6 = (int)(target->pos).vz + (int)local_50;
      xd = (target->pos).vx;
      sVar2 = (target->pos).vy;
    }
    y1 = (int)sVar2;
    x1 = (int)xd;
    iVar3 = Distance2D(x1,y1,(int)(o->pos).vx,(int)(o->pos).vy);
    xd = Zone_GetEnemyZonePath
                   ((o->pos).vx,(o->pos).vy,(o->pos).vz,xd,y1,(int)local_50,
                    (ulong)*(_D3_OBJECT **)&p_Var7->rot,
                    (ulong)*(_D3_OBJECT **)((int)&p_Var7->rot + 4),&local_68);
    if (xd != 0) {
      if ((local_68 == 0x7fff) && (local_66 == 0x7fff)) {
        p_Var5 = *(_D3_OBJECT **)((int)&p_Var7->last_pos + 4);
        x1 = (int)*(short *)&p_Var5->next + (int)*(short *)((int)&p_Var5->prec + 2) >> 1;
        y1 = (int)*(short *)((int)&p_Var5->next + 2) + (int)*(short *)&p_Var5->child >> 1;
      }
      else {
        x1 = (int)local_68;
        y1 = (int)local_66;
      }
    }
    if (((target == (_D3_OBJECT *)0x0) || (199 < LONG_ARRAY_800b2e40[0])) ||
       (lVar4 = Direction((int)(target->pos).vx - (int)(o->pos).vx,
                          (int)(target->pos).vy - (int)(o->pos).vy),
       0x578 < (((int)(o->rot).vz + 700) - lVar4 & 0xfffU))) {
      D3_GoToDir(o,x1 - (int)(o->pos).vx,y1 - (int)(o->pos).vy,0x96);
    }
    if ((int)local_64 != -1) {
      lVar4 = DeltaDirection((int)local_64,(int)(o->rot).vz);
      x1 = lVar4;
      if (lVar4 < 0) {
        x1 = -lVar4;
      }
      if (x1 < 900) {
        (o->rot).vz = (o->rot).vz + (short)(lVar4 >> 1);
      }
    }
    if (((int)o->collision_state & 0xfc00U) != 0) {
      if (((int)o->collision_state & 0x8000U) == 0) {
        if (((o->collision_state & 0x4000U) != 0) &&
           (x1 = *(int *)&o[1].hit_points,
           (int)(o->pos).vz < (int)*(short *)(x1 + 0x70) + (int)*(short *)(x1 + 0x30) + 0xfa)) {
          do {
            xd = (o->pos).vz;
            (o->pos).vz = (o->pos).vz + 0xe;
            Task_Next();
            y1 = (int)(o->pos).vz;
            if ((int)xd == y1) {
              return 0;
            }
          } while (y1 < (int)*(short *)(x1 + 0x70) + (int)*(short *)(x1 + 0x30) + 0xfa);
        }
      }
      else {
        x1 = (int)(o->pos).vz;
        xd = (o->pos).vz;
        y1 = x1 + -0x96;
        while (y1 < x1) {
          (o->pos).vz = xd + -0x16;
          Task_Next();
          x1 = (int)(o->pos).vz;
          xd = (o->pos).vz;
        }
      }
    }
    if ((local_30 != -1) && (((obj->Env).Obj.normal_top.vx & 0x4000U) != 0)) {
      D3_PlaySound(o,(short)local_30);
    }
    Task_Next();
    lVar4 = Boxes_GetHeightPlatform(o,(char)o + ',');
    if (((lVar4 <= iVar6) && (iVar6 < (int)(o->pos).vz)) &&
       (*(short *)((int)&p_Var7->list + 2) != 1)) {
      (o->pos).vz = (o->pos).vz + -0x12;
    }
    if ((int)(o->pos).vz < iVar6) {
      (o->pos).vz = (o->pos).vz + 0xf;
    }
    if (target != (_D3_OBJECT *)0x0) {
      if (((iVar6 <= (int)(o->pos).vz) && (iVar3 < 400)) && (0x32 < iVar3)) {
        local_50 = 0x78;
      }
      if (((target != (_D3_OBJECT *)0x0) && (local_2c != 0)) && (LONG_ARRAY_800b2e40[0] < 2000)) {
        uVar1 = (o->rot).vz;
        lVar4 = Direction((int)(target->pos).vx - (int)(o->pos).vx,
                          (int)(target->pos).vy - (int)(o->pos).vy);
        if ((LONG_ARRAY_800b2e40[0] < 0x78) &&
           ((lVar4 - (((uint)uVar1 & 0xfff) - 0x200) & 0xfff) < 0x400)) {
          x1 = (int)(o->pos).vz;
          iVar6 = (int)(target->pos).vz;
          if (iVar6 < (int)*(short *)((int)(p_Var7 + 2) + 0x20) + x1) {
            if (x1 < ((int)*(short *)&target[1].prec - (int)(target->b_box).vz) + iVar6 + 0x1e) {
              D3_SetCollBits(o,2);
              Manim_SetAnim(obj,local_2c);
              if (local_38 != -1) {
                D3_PlaySound(o,local_38);
              }
              while (((obj->Env).Obj.normal_top.vx & 0x4000U) == 0) {
                D3_GoToDir(o,(int)(target->pos).vx - (int)(o->pos).vx,
                           (int)(target->pos).vy - (int)(o->pos).vy,0xfa);
                Task_Next();
                if ((target->collision_state & 2U) != 0) {
                  D3_ClearCollBits(o,2);
                }
              }
            }
            D3_ClearCollBits(o,2);
            Manim_SetAnim(obj,(int)local_40);
            do {
              (o->pos).vz = (o->pos).vz + 5;
              Task_Next();
              iVar6 = LONG_ARRAY_800b2e40[0];
              if ((local_30 != -1) && (((obj->Env).Obj.normal_top.vx & 0x4000U) != 0)) {
                D3_PlaySound(o,(short)local_30);
              }
              if (iVar6 < 0) {
                iVar6 = -iVar6;
              }
            } while (iVar6 < 0x17c);
            return 1;
          }
        }
      }
    }
    if (LONG_ARRAY_800b2e5c[0] != -1) {
      if ((int)local_40 != -1) {
        Manim_SetAnim(obj,(int)local_40);
      }
      if ((o->collision_state & 0x3c00U) != 0) {
        if ((o->collision_state & 0x800U) != 0) {
          xd = 0x600;
          if (0xc00 < (o->rot).vz) {
            xd = 0xa00;
          }
          (o->rot).vz = xd;
        }
        if ((o->collision_state & 0x400U) != 0) {
          xd = 0x200;
          if (0x800 < (o->rot).vz) {
            xd = 0xe00;
          }
          (o->rot).vz = xd;
        }
        if ((o->collision_state & 0x2000U) != 0) {
          xd = 0xe00;
          if (0x400 < (o->rot).vz) {
            xd = 0xa00;
          }
          (o->rot).vz = xd;
        }
        iVar6 = 0;
        if ((o->collision_state & 0x1000U) != 0) {
          xd = 0x600;
          if (0xc00 < (o->rot).vz) {
            xd = 0x200;
          }
          (o->rot).vz = xd;
          iVar6 = 0;
        }
        do {
          iVar6 = iVar6 + 1;
          Task_Next();
        } while (iVar6 < 10);
      }
    }
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
  } while ((int)local_48 < iVar3);
  return 1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Monster_AdjustZ(struct _D3_OBJECT *obj /*$s2*/, struct M_OBJECT *mo /*$s0*/)
 // line 1741, offset 0x8006be94
	/* begin block 1 */
		// Start line: 1742
		// Start offset: 0x8006BE94
		// Variables:
	// 		struct _D3_OBJECT *o; // $s0
	// 		struct MONSTER_7fake pos; // stack offset -32
	// 		long sx; // $s1
	// 		long sy; // $s3
	// 		long dz; // $s1
	// 		long cs; // $s0
	// 		long sn; // $v0
	/* end block 1 */
	// End offset: 0x8006C05C
	// End Line: 1793

	/* begin block 2 */
		// Start line: 3787
	/* end block 2 */
	// End Line: 3788

void Monster_AdjustZ(_D3_OBJECT *obj,M_OBJECT *mo)

{
  _D3_OBJECT *p_Var1;
  long lVar2;
  long lVar3;
  int iVar4;
  
  lVar2 = Manim_GetSpdX(mo);
  lVar3 = Manim_GetSpdY(mo);
  if (lVar2 < 0) {
    lVar2 = lVar2 - (int)*(short *)&obj->b_step;
  }
  else {
    if (0 < lVar2) {
      lVar2 = lVar2 + (int)*(short *)&obj->b_step;
    }
  }
  if ((lVar2 != 0) || (lVar3 != 0)) {
    rcos((int)(obj->rot).vz);
    rsin((int)(obj->rot).vz);
    lVar2 = Boxes_GetHeight(obj,0xe0,0x32);
    p_Var1 = Boxes_Object;
    iVar4 = lVar2 - (int)(obj->pos).vz;
    Boxes_GetHeight(obj,(char)obj + ',',0x32);
    if ((p_Var1 != Boxes_Object) && ((0 < iVar4 && (iVar4 < 0x3d)))) {
      (obj->pos).vz = (obj->pos).vz + (short)iVar4;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Monster_Adjust(struct _D3_OBJECT *o /*$s0*/, struct _MONSTER *monst /*$s2*/)
 // line 1795, offset 0x8006c078
	/* begin block 1 */
		// Start line: 1796
		// Start offset: 0x8006C078
		// Variables:
	// 		struct M_OBJECT *mo; // $s1
	// 		long height; // $v0
	/* end block 1 */
	// End offset: 0x8006C0E4
	// End Line: 1810

	/* begin block 2 */
		// Start line: 3914
	/* end block 2 */
	// End Line: 3915

void Monster_Adjust(_D3_OBJECT *o,_MONSTER *monst)

{
  long lVar1;
  M_OBJECT *mo;
  
  mo = (M_OBJECT *)o->description;
  lVar1 = Boxes_TestGround(o);
  if (lVar1 == 0) {
    lVar1 = Boxes_GetHeight(o,(char)o + ',',
                            (short)(((uint)(ushort)monst->height + 100) * 0x10000 >> 0x10));
    if (lVar1 <= (int)(o->pos).vz + -1) {
      (o->pos).vz = (short)lVar1;
    }
  }
  else {
    Monster_AdjustZ(o,mo);
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Monster_Action_MoveTo(long xx /*stack 0*/, long yy /*stack 4*/, long zz /*stack 8*/, struct _D3_OBJECT *target /*$fp*/, long dist /*stack 16*/, long AnimStart /*stack 20*/, long AnimLoop /*stack 24*/, long AnimStop /*stack 28*/, long AnimFall /*stack 32*/, long AnimJump /*stack 36*/, long Snd /*stack 40*/)
 // line 1812, offset 0x8006c0fc
	/* begin block 1 */
		// Start line: 1813
		// Start offset: 0x8006C0FC
		// Variables:
	// 		short foundpath[3]; // stack offset -72
	// 		struct _MONSTER *monst; // $s6
	// 		struct _D3_OBJECT *o; // $s1
	// 		struct M_OBJECT *mo; // $s5
	// 		long QuitVal; // stack offset -64
	// 		long HadHurts; // stack offset -60
	// 		long ZeroGravity; // stack offset -56
	// 		long i; // $s0
	// 		long distance; // stack offset -52
	// 		long height; // $s3
	// 		long tmp; // $s0
	// 		long grav; // $s7
	// 		long x; // $s2
	// 		long y; // $s4
	// 		long sensmask; // stack offset -48
	/* end block 1 */
	// End offset: 0x8006CA78
	// End Line: 2065

	/* begin block 2 */
		// Start line: 3948
	/* end block 2 */
	// End Line: 3949

/* WARNING: Removing unreachable block (ram,0x8006c4a0) */

long Monster_Action_MoveTo
               (long xx,long yy,long zz,_D3_OBJECT *target,long dist,long AnimStart,long AnimLoop,
               long AnimStop,long AnimFall,long AnimJump,long Snd)

{
  ushort uVar1;
  TASK *pTVar2;
  short Fx;
  short sVar3;
  int iVar4;
  long lVar5;
  uint uVar6;
  int x1;
  _ENEMYZONE *p_Var7;
  int y1;
  int iVar8;
  _D3_OBJECT *o;
  int iVar9;
  M_OBJECT *obj;
  _MONSTER *monst;
  int iVar10;
  long local_res0;
  long local_res4;
  long local_res8;
  short local_48;
  short local_46;
  short local_44;
  long local_40;
  uint local_3c;
  uint local_38;
  long local_34;
  ulong local_30;
  
  local_40 = 1;
  monst = (_MONSTER *)TaskCurrent->local;
  o = monst->obj;
  obj = (M_OBJECT *)o->description;
  local_res8 = zz;
  if (zz == -0x5dc) {
    local_res8 = (long)(o->pos).vz;
  }
  local_38 = (uint)(zz == -0x5dc);
  sVar3 = 0;
  Fx = 0;
  if (target == (_D3_OBJECT *)0x0) {
    local_34 = Distance2D(xx,yy,(int)(o->pos).vx,(int)(o->pos).vy);
  }
  else {
    Fx = Zone_GetEnemyZone((target->pos).vx,(target->pos).vy,(target->pos).vz,monst->zb_low,
                           monst->zb_high);
    sVar3 = Zone_GetEnemyZone((o->pos).vx,(o->pos).vy,(o->pos).vz,monst->zb_low,monst->zb_high);
    local_34 = LONG_ARRAY_800b2e40[0];
  }
  if (Fx == sVar3) {
    x1 = local_34;
    if (local_34 < 0) {
      x1 = -local_34;
    }
    if (x1 <= dist + 0x28) {
      return 1;
    }
  }
  if (AnimStart == -1) {
    AnimStart = AnimLoop;
    if (AnimLoop == -1) goto LAB_8006c27c;
  }
  else {
    if (monst->mode == 1) {
      (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx | 1;
      goto LAB_8006c27c;
    }
  }
  Manim_SetAnim(obj,AnimStart);
LAB_8006c27c:
  monst->mode = 1;
  local_3c = (uint)((o->collision_mode & 2U) != 0);
  D3_ClearCollBits(o,2);
  (obj->Env).Obj.normal_top.vy = monst->monster_trans;
  local_res0 = xx;
  local_res4 = yy;
  do {
    if (target != (_D3_OBJECT *)0x0) {
      local_res0 = (long)(target->pos).vx;
      local_res4 = (long)(target->pos).vy;
      local_res8 = (long)(target->pos).vz;
    }
    Fx = Zone_GetEnemyZonePath
                   ((o->pos).vx,(o->pos).vy,(o->pos).vz,(short)local_res0,(int)(short)local_res4,
                    (int)(short)local_res8,monst->zb_low,monst->zb_high,&local_48);
    if (Fx == 0) {
LAB_8006c5a0:
      local_34 = Distance2D(local_res0,local_res4,(int)(o->pos).vx,(int)(o->pos).vy);
      x1 = local_res0;
      y1 = local_res4;
    }
    else {
      if (Fx == -2) {
        if (AnimJump == -1) goto LAB_8006c5a0;
        x1 = (int)local_48;
        y1 = (int)local_46;
        while (lVar5 = D3_GoToDir(o,x1 - (int)(o->pos).vx,y1 - (int)(o->pos).vy,
                                  (int)monst->monster_speed << 1), lVar5 != 0) {
          Task_Next();
        }
        TaskCurrent->event_enable = 0;
        local_30 = monst->sensormask;
        monst->sensormask = 9;
        monst->mode = 0x15;
        Manim_ForceAnim(obj,AnimJump);
        Manim_WaitEvent(obj,0x8000);
        lVar5 = Distance2D(x1,y1,(int)(o->pos).vx,(int)(o->pos).vy);
        iVar9 = 0x20000;
        iVar8 = lVar5 / 0x28;
        iVar10 = 0x40000 / iVar8;
        if (iVar8 == 0) {
          trap(0x1c00);
        }
        D3_SetCollBits(o,2);
        do {
          iVar4 = rcos((int)(o->rot).vz);
          Fx = (o->rot).vz;
          (o->pos).vx = (o->pos).vx + (short)(iVar4 * 0x28 >> 0xc);
          iVar4 = rsin((int)Fx);
          (o->pos).vy = (o->pos).vy + (short)(iVar4 * 0x28 >> 0xc);
          (o->pos).vz = (o->pos).vz + (short)(iVar9 >> 0xc);
          Task_Next();
          iVar9 = iVar9 - iVar10;
          if (((int)(obj->Env).Obj.vert_top.pad & 0x8000U) != 0) {
            (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
          }
          iVar8 = iVar8 + -1;
        } while (((o->collision_state & 0x4000U) == 0) && (iVar8 != -1));
        D3_ClearCollBits(o,2);
        (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx | 1;
        Manim_WaitAnim(obj);
        Manim_SetAnim(obj,AnimLoop);
        monst->mode = 1;
        pTVar2 = TaskCurrent;
        monst->sensormask = local_30;
        pTVar2->event_enable = 1;
      }
      else {
        if ((local_48 == 0x7fff) && (local_46 == 0x7fff)) {
          p_Var7 = monst->zone_current;
          local_res0 = (int)p_Var7->x1 + (int)p_Var7->x2 >> 1;
          local_res4 = (int)p_Var7->y1 + (int)p_Var7->y2 >> 1;
          local_34 = Distance2D(local_res0,local_res4,(int)(o->pos).vx,(int)(o->pos).vy);
          target = (_D3_OBJECT *)0x0;
          x1 = local_res0;
          y1 = local_res4;
        }
        else {
          x1 = (int)local_48;
          y1 = (int)local_46;
        }
      }
    }
    D3_GoToDir(o,x1 - (int)(o->pos).vx,y1 - (int)(o->pos).vy,(int)monst->monster_speed << 1);
    Direction(x1 - (int)(o->pos).vx,y1 - (int)(o->pos).vy);
    if ((int)local_44 != -1) {
      lVar5 = DeltaDirection((int)local_44,(int)(o->rot).vz);
      x1 = lVar5;
      if (lVar5 < 0) {
        x1 = -lVar5;
      }
      if (x1 < (int)monst->monster_speed * 3) {
        (o->rot).vz = (o->rot).vz + (short)lVar5;
      }
    }
    uVar1 = (o->pos).vx;
    if ((uVar1 & 1) == 0) {
      (o->pos).vx = uVar1 & 0xfffe;
    }
    uVar1 = (o->pos).vy;
    if ((uVar1 & 1) == 0) {
      (o->pos).vy = uVar1 & 0xfffe;
    }
    Task_Next();
    if ((((obj->Env).Obj.vert_top.pad & 1U) != 0) && (Snd != -1)) {
      if ((*(short *)((int)&o[1].father + 2) == -1) || (Snd == -2)) {
        uVar6 = M_rand();
        Fx = 0x17;
        if ((uVar6 & 1) != 0) {
          Fx = 0x16;
        }
        Fx_Play(Fx,(char)o + ',');
      }
      else {
        D3_PlaySound(o,(short)Snd);
      }
    }
    if (((AnimLoop != -1) && ((int)*(short *)((int)&(obj->Env).Version + 2) != AnimLoop)) &&
       (((obj->Env).Obj.normal_top.vx & 0x4000U) != 0)) {
      Manim_SetAnim(obj,AnimLoop);
    }
    if (local_38 == 0) {
      Monster_Adjust(o,monst);
    }
    if (LONG_ARRAY_800b2e5c[0] != -1) {
      if ((int)*(short *)(LONG_ARRAY_800b2e5c[0] + 0x70) ==
          (int)*(short *)(LONG_ARRAY_800b2e5c[0] + 0x80)) {
        if ((*(ushort *)(LONG_ARRAY_800b2e5c[0] + 0x1c) & 0x800) == 0) {
          y1 = (int)(o->pos).vz;
          x1 = (int)*(short *)(LONG_ARRAY_800b2e5c[0] + 0x30) +
               (int)*(short *)(LONG_ARRAY_800b2e5c[0] + 0x70);
          if ((y1 < x1) && (x1 + -0x28 < y1)) {
            if (x1 + -0x1e < y1) {
              Fx = *(short *)(LONG_ARRAY_800b2e5c[0] + 0x30) +
                   *(short *)(LONG_ARRAY_800b2e5c[0] + 0x70) + 2;
              (o->last_pos).vz = Fx;
              goto LAB_8006c864;
            }
            goto LAB_8006c9dc;
          }
        }
        if (AnimLoop != -1) {
          Manim_SetAnim(obj,AnimLoop);
        }
        if ((o->collision_state & 0x3c00U) != 0) {
          if ((o->collision_state & 0x800U) != 0) {
            Fx = 0x600;
            if (0xc00 < (o->rot).vz) {
              Fx = 0xa00;
            }
            (o->rot).vz = Fx;
          }
          if ((o->collision_state & 0x400U) != 0) {
            Fx = 0x200;
            if (0x800 < (o->rot).vz) {
              Fx = 0xe00;
            }
            (o->rot).vz = Fx;
          }
          if ((o->collision_state & 0x2000U) != 0) {
            Fx = 0xe00;
            if (0x400 < (o->rot).vz) {
              Fx = 0xa00;
            }
            (o->rot).vz = Fx;
          }
          if ((o->collision_state & 0x1000U) != 0) {
            Fx = 0x600;
            if (0xc00 < (o->rot).vz) {
              Fx = 0x200;
            }
            (o->rot).vz = Fx;
          }
          x1 = *(int *)(*(int *)((obj->Sq).Data.FatherTrans + 2) + AnimLoop * 4 + 8);
          y1 = 0;
          if (*(short *)(x1 + ((uint)*(ushort *)(x1 + 6) - 1) * 8 + 0x14) < 0xc9) {
            do {
              Monster_Adjust(o,monst);
              y1 = y1 + 1;
              Task_Next();
            } while (y1 < 0x14);
            local_40 = 0;
          }
          else {
            do {
              Monster_Adjust(o,monst);
              y1 = y1 + 1;
              Task_Next();
            } while (y1 < 10);
            local_40 = 0;
          }
LAB_8006c9fc:
          if (AnimStop != -1) {
            Manim_SetAnim(obj,AnimStop);
          }
          if (AnimLoop != -1) {
            if (0x3c < dist) {
              Manim_SetAnim(obj,AnimLoop);
              (obj->Env).Obj.normal_top.vy = monst->monster_trans;
              Task_Next();
            }
            (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
          }
          if (local_3c == 0) {
            return local_40;
          }
          D3_SetCollBits(o,2);
          return local_40;
        }
      }
      else {
        if ((int)*(short *)(LONG_ARRAY_800b2e5c[0] + 0x30) +
            (int)*(short *)(LONG_ARRAY_800b2e5c[0] + 0x80) + -0x1e < (int)(o->pos).vz) {
          x1 = rcos((int)(o->rot).vz);
          lVar5 = Manim_GetSpdX(obj);
          Fx = (o->rot).vz;
          sVar3 = (o->pos).vx + (short)(x1 * lVar5 >> 0xc);
          (o->last_pos).vx = sVar3;
          (o->pos).vx = sVar3;
          x1 = rsin((int)Fx);
          lVar5 = Manim_GetSpdX(obj);
          Fx = (o->pos).vy + (short)(x1 * lVar5 >> 0xc);
          (o->last_pos).vy = Fx;
          (o->pos).vy = Fx;
          lVar5 = Boxes_GetHeight(o,(char)o + ',',
                                  (short)(((uint)(ushort)monst->height + 100) * 0x10000 >> 0x10));
          Fx = (short)lVar5;
          (o->last_pos).vz = Fx;
LAB_8006c864:
          (o->pos).vz = Fx;
        }
      }
    }
LAB_8006c9dc:
    x1 = local_34;
    if (local_34 < 0) {
      x1 = -local_34;
    }
    if (x1 <= dist) goto LAB_8006c9fc;
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Monster_Action_MoveGlide(struct _D3_OBJECT *target /*$s3*/, short distance /*stack -56*/, short spd /*$a2*/, short xx /*$fp*/, int yy /*stack 16*/, int zz /*stack 20*/, long dodir /*stack 24*/)
 // line 2069, offset 0x8006caa8
	/* begin block 1 */
		// Start line: 2070
		// Start offset: 0x8006CAA8
		// Variables:
	// 		struct _MONSTER *monst; // $s5
	// 		struct _D3_OBJECT *o; // $s1
	// 		short foundpath[3]; // stack offset -64
	// 		long dist; // $s4
	// 		long dir; // $s0
	// 		short x; // $s2
	// 		short y; // $s0
	// 		short z; // $v1
	/* end block 1 */
	// End offset: 0x8006CDCC
	// End Line: 2141

	/* begin block 2 */
		// Start line: 4533
	/* end block 2 */
	// End Line: 4534

/* WARNING: Type propagation algorithm not settling */

void Monster_Action_MoveGlide
               (_D3_OBJECT *target,short distance,short spd,short xx,int yy,int zz,long dodir)

{
  short sVar1;
  short sVar2;
  short sVar3;
  long z1;
  long lVar4;
  uint d2;
  int local_54;
  _D3_OBJECT *p_Var5;
  int iVar6;
  uint x1;
  undefined2 in_register_0000001a;
  short sVar7;
  _D3_OBJECT *o;
  short xd;
  _D3_OBJECT *p_Var8;
  short sVar9;
  short sVar10;
  short local_40;
  short local_3e;
  short local_3c;
  short local_38;
  undefined4 local_30;
  short local_2c;
  
  x1 = (uint)(ushort)xx;
  local_30 = CONCAT22(in_register_0000001a,spd);
  sVar2 = (short)yy;
  p_Var8 = (_D3_OBJECT *)TaskCurrent->local;
  local_2c = (short)zz;
  o = p_Var8->next;
  if (target != (_D3_OBJECT *)0x0) {
    xx = (target->pos).vx;
    sVar2 = (target->pos).vy;
  }
  local_38 = distance;
  z1 = Distance3D((int)xx,(int)sVar2,0,(int)(o->pos).vx,(int)(o->pos).vy,0);
  if ((int)distance < z1) {
    sVar2 = (short)local_30;
    do {
      sVar9 = (short)yy;
      sVar10 = (short)x1;
      sVar3 = local_2c;
      sVar7 = sVar9;
      xd = sVar10;
      if (target != (_D3_OBJECT *)0x0) {
        sVar3 = (target->pos).vz;
        sVar7 = (target->pos).vy;
        xd = (target->pos).vx;
      }
      sVar3 = Zone_GetEnemyZonePath
                        ((o->pos).vx,(o->pos).vy,(o->pos).vz,xd,(int)sVar7,(int)sVar3,
                         (ulong)*(_D3_OBJECT **)&p_Var8->rot,
                         (ulong)*(_D3_OBJECT **)((int)&p_Var8->rot + 4),&local_40);
      if (sVar3 == 0) {
        if (target == (_D3_OBJECT *)0x0) {
          sVar1 = (o->pos).vx;
          sVar3 = (o->pos).vy;
          z1 = 0;
          local_54 = 0;
        }
        else {
          sVar3 = (o->pos).vy;
          sVar10 = (target->pos).vx;
          sVar9 = (target->pos).vy;
          z1 = (long)(target->pos).vz;
          sVar1 = (o->pos).vx;
          local_54 = (int)(o->pos).vz;
        }
        z1 = Distance3D((int)sVar10,(int)sVar9,z1,(int)sVar1,(int)sVar3,local_54);
      }
      else {
        xd = local_40;
        sVar7 = local_3e;
        if ((local_40 == 0x7fff) && (xd = local_40, sVar7 = local_3e, local_3e == 0x7fff)) {
          p_Var5 = *(_D3_OBJECT **)((int)&p_Var8->last_pos + 4);
          x1 = (int)*(short *)&p_Var5->next + (int)*(short *)((int)&p_Var5->prec + 2) >> 1;
          yy = (int)*(short *)((int)&p_Var5->next + 2) + (int)*(short *)&p_Var5->child >> 1;
          lVar4 = Distance2D(x1,yy,(int)(o->pos).vx,(int)(o->pos).vy);
          target = (_D3_OBJECT *)0x0;
          local_38 = (short)lVar4;
          xd = (short)x1;
          sVar7 = (short)yy;
        }
      }
      if (dodir != 0) {
        D3_GoToDir(o,(int)xd - (int)(o->pos).vx,(int)sVar7 - (int)(o->pos).vy,
                   (int)*(short *)((int)(p_Var8 + 2) + 0x4e));
      }
      d2 = Direction((int)xd - (int)(o->pos).vx,(int)sVar7 - (int)(o->pos).vy);
      if ((int)local_3c != -1) {
        lVar4 = DeltaDirection((int)local_3c,d2);
        iVar6 = (int)(short)lVar4;
        local_54 = iVar6;
        if (iVar6 < 0) {
          local_54 = -iVar6;
        }
        if (local_54 < 900) {
          d2 = d2 + iVar6;
        }
      }
      local_54 = rcos(d2);
      (o->pos).vx = ((o->pos).vx + (short)(local_54 * (int)sVar2 >> 0xc) & 0xfffeU) + 1;
      local_54 = rsin(d2);
      (o->pos).vy = ((o->pos).vy + (short)(local_54 * (int)sVar2 >> 0xc) & 0xfffeU) + 1;
      Task_Next();
    } while ((int)local_38 < z1);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Monster_Action_Protect(short forcedtype /*$s4*/, short timer /*$s3*/, short AnimSit /*stack -56*/, short AnimStand /*stack -48*/, int AnimLeft /*stack 16*/, int AnimRight /*stack 20*/, int Sound /*stack 24*/)
 // line 2146, offset 0x8006cdfc
	/* begin block 1 */
		// Start line: 2147
		// Start offset: 0x8006CDFC
		// Variables:
	// 		struct _MONSTER *monst; // $s2
	// 		struct _D3_OBJECT *obj; // $s1
	// 		struct M_OBJECT *mo; // $s0
	// 		short speed; // $s5
	/* end block 1 */
	// End offset: 0x8006D0D8
	// End Line: 2217

	/* begin block 2 */
		// Start line: 4702
	/* end block 2 */
	// End Line: 4703

/* WARNING: Type propagation algorithm not settling */

void Monster_Action_Protect
               (short forcedtype,short timer,short AnimSit,short AnimStand,int AnimLeft,
               int AnimRight,int Sound)

{
  TASK *pTVar1;
  long lVar2;
  uint uVar3;
  M_OBJECT *obj;
  _D3_OBJECT *o;
  _D3_OBJECT *p_Var4;
  short sVar5;
  
  uVar3 = (uint)(ushort)timer;
  sVar5 = 0;
  p_Var4 = (_D3_OBJECT *)TaskCurrent->local;
  o = p_Var4->next;
  obj = (M_OBJECT *)o->description;
  if (AnimSit == -1) {
    return;
  }
  if (AnimStand == -1) {
    return;
  }
  if (forcedtype == 0) {
    if (((short)AnimRight == -1) || ((short)AnimLeft == -1)) {
      forcedtype = 1;
    }
    else {
      lVar2 = M_rand();
      forcedtype = (short)lVar2 + (short)(lVar2 / 3) * -3 + 1;
    }
  }
  *(undefined2 *)&p_Var4->list = 4;
  if ((short)Sound != -1) {
    D3_PlaySound(o,(short)Sound);
  }
  if (forcedtype == 2) {
    AnimLeft = AnimRight << 0x10;
  }
  else {
    if (forcedtype < 3) {
      if (forcedtype != 1) goto LAB_8006cf6c;
      AnimLeft = (uint)(ushort)AnimSit << 0x10;
    }
    else {
      if (forcedtype != 3) goto LAB_8006cf6c;
      AnimLeft = AnimLeft << 0x10;
    }
  }
  Manim_SetAnim(obj,AnimLeft >> 0x10);
LAB_8006cf6c:
  TaskCurrent->event_enable = 0;
  Monster_Action_SetBoundingBox(1,(int)*(short *)((int)(p_Var4 + 2) + 0x20));
  while (((obj->Env).Obj.normal_top.vx & 0x4000U) == 0) {
    if (((int)(obj->Env).Obj.vert_top.pad & 0x8000U) != 0) {
      Monster_Action_SetBoundingBox(1,(int)*(short *)((int)(p_Var4 + 2) + 0x20));
      Manim_WaitEvent(obj,0x8000);
    }
    if ((((int)o->collision_state & 0xc000U) == 0) && (((obj->Env).Obj.vert_top.pad & 0x4000U) == 0)
       ) {
      (o->pos).vz = (o->pos).vz + sVar5 + -5;
      sVar5 = sVar5 + -5;
    }
    Task_Next();
  }
  (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
  lVar2 = Boxes_TestGround(o);
  if (lVar2 == 0) {
    Monster_Action_Falling(0);
  }
  else {
    if (forcedtype == 1) {
      while (uVar3 = uVar3 - 1, (int)(uVar3 * 0x10000) >> 0x10 != -1) {
        Task_Next();
      }
    }
    Monster_Action_SetBoundingBox(0,(int)*(short *)((int)(p_Var4 + 2) + 0x20));
    if ((int)AnimStand != -1) {
      Manim_SetAnim(obj,(int)AnimStand);
      Manim_WaitAnim(obj);
    }
    pTVar1 = TaskCurrent;
    (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
    pTVar1->event_enable = 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Monster_Reflex_Feasting(struct _MONSTER *monst /*$s1*/)
 // line 2221, offset 0x8006d108
	/* begin block 1 */
		// Start line: 2222
		// Start offset: 0x8006D108
	/* end block 1 */
	// End offset: 0x8006D194
	// End Line: 2238

	/* begin block 2 */
		// Start line: 4877
	/* end block 2 */
	// End Line: 4878

void Monster_Reflex_Feasting(_MONSTER *monst)

{
  long o;
  long lVar1;
  
  o = LONG_800b2e3c;
  if ((((LONG_800b2e3c != -1) &&
       (lVar1 = Distance2D((int)*(short *)(LONG_800b2e3c + 0x2c),
                           (int)*(short *)(LONG_800b2e3c + 0x2e),(int)(monst->obj->pos).vx,
                           (int)(monst->obj->pos).vy), lVar1 < 500)) &&
      (lVar1 = Pvl_TestStateBits((_D3_OBJECT *)o,2), lVar1 != 0)) &&
     ((*(ushort *)(o + 0x1a) & 0x10) != 0)) {
    Monster_StopAllActions(monst);
    Monster_AddAction(monst,0,0xe,LONG_800b2e3c,0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Monster_Reflex_SmallBeastAttack(struct _MONSTER *monst /*$s2*/, short dist /*$a1*/)
 // line 2241, offset 0x8006d1a8
	/* begin block 1 */
		// Start line: 2242
		// Start offset: 0x8006D1A8
		// Variables:
	// 		struct _D3_OBJECT *o; // $s0
	// 		struct _D3_OBJECT *target; // $s1
	// 		long dir; // $a1
	/* end block 1 */
	// End offset: 0x8006D2B8
	// End Line: 2267

	/* begin block 2 */
		// Start line: 4917
	/* end block 2 */
	// End Line: 4918

void Monster_Reflex_SmallBeastAttack(_MONSTER *monst,short dist)

{
  long lVar1;
  int iVar2;
  long action;
  _D3_OBJECT *p_Var3;
  
  action = Monster_Feelings;
  p_Var3 = monst->obj;
  if (LONG_ARRAY_800b2e2c[0] == -1) {
    if (monst->action == 1) {
      return;
    }
    Monster_StopAllActions(monst);
    action = 1;
  }
  else {
    if (1999 < LONG_ARRAY_800b2e40[0]) {
      return;
    }
    lVar1 = Direction((int)*(short *)(Monster_Feelings + 0x2c) - (int)(p_Var3->pos).vx,
                      (int)*(short *)(Monster_Feelings + 0x2e) - (int)(p_Var3->pos).vy);
    iVar2 = (int)(p_Var3->pos).vz;
    if ((int)*(short *)(action + 0x30) + 200 <= iVar2) {
      return;
    }
    if (iVar2 + (int)monst->height + 100 <= (int)*(short *)(action + 0x30)) {
      return;
    }
    if (0x5ff < ((lVar1 - (int)(p_Var3->rot).vz) + 0x300U & 0xfff)) {
      return;
    }
    if ((int)dist <= LONG_ARRAY_800b2e40[0]) {
      return;
    }
    Monster_StopAllActions(monst);
    action = 0xb;
  }
  Monster_AddAction(monst,0,action,0,0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Monster_ReflexCombat(struct _MONSTER *monst /*$s0*/, long attdist /*$s3*/, long resettimer /*$s2*/)
 // line 2270, offset 0x8006d2d4
	/* begin block 1 */
		// Start line: 2271
		// Start offset: 0x8006D2D4
		// Variables:
	// 		struct _D3_OBJECT *target; // $s1
	// 		long tmp; // $a0
	/* end block 1 */
	// End offset: 0x8006D50C
	// End Line: 2325

	/* begin block 2 */
		// Start line: 4984
	/* end block 2 */
	// End Line: 4985

void Monster_ReflexCombat(_MONSTER *monst,long attdist,long resettimer)

{
  bool bVar1;
  long lVar2;
  int iVar3;
  long action;
  
  action = Monster_Feelings;
  if (monst->timer != 0) {
    monst->timer = monst->timer + -1;
  }
  lVar2 = Distance2D((int)*(short *)(action + 0x2c),(int)*(short *)(action + 0x2e),
                     (int)(monst->obj->pos).vx,(int)(monst->obj->pos).vy);
  if (((((monst->agression < 0x101) || (resettimer == 0)) || (monst->timer != 0)) ||
      ((lVar2 < 0x191 || (0x4af < lVar2)))) ||
     ((monst->action == 0xc || ((monst->obj->collision_state & 0x80U) == 0)))) {
    if (1999 < LONG_ARRAY_800b2e40[0]) {
      return;
    }
    if (LONG_ARRAY_800b2e40[0] == -1) {
      return;
    }
    iVar3 = (int)(monst->obj->pos).vz;
    if (((iVar3 < (int)*(short *)(action + 0x30) + 200) &&
        ((int)*(short *)(action + 0x30) < iVar3 + (int)monst->height + 100)) &&
       ((lVar2 < attdist && ((monst->action != 0xb && (monst->wait_kick == 0)))))) {
      Monster_StopAllActions(monst);
      action = 0xb;
      goto LAB_8006d504;
    }
    if ((monst->obj[1].pos.vz & 0x200U) == 0) {
      if (resettimer == 0) {
        return;
      }
      if (LONG_800b2e38 == -1) {
        return;
      }
      if (monst->timer != 0) {
        return;
      }
      bVar1 = lVar2 < 0x4b0;
      if (lVar2 <= attdist + 100) {
        return;
      }
    }
    else {
      if (resettimer == 0) {
        return;
      }
      if (LONG_800b2e38 == -1) {
        return;
      }
      if (monst->timer != 0) {
        return;
      }
      bVar1 = lVar2 < 0x640;
      if (lVar2 < attdist) {
        return;
      }
    }
    if (!bVar1) {
      return;
    }
    if (monst->action == 0xc) {
      return;
    }
    if ((monst->obj->collision_state & 0x80U) == 0) {
      return;
    }
  }
  monst->timer = (short)resettimer;
  Monster_StopAllActions(monst);
  action = 0xc;
LAB_8006d504:
  Monster_AddAction(monst,0,action,0,0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Monster_Action_Feast(struct _D3_OBJECT *o /*$s3*/, struct _D3_OBJECT *tmpobj /*$s0*/, long AnimRun /*$s5*/, long AnimFeast /*$fp*/, long power /*stack 16*/, long sound /*stack 20*/)
 // line 2329, offset 0x8006d528
	/* begin block 1 */
		// Start line: 2330
		// Start offset: 0x8006D528
		// Variables:
	// 		struct M_OBJECT *mo; // $s2
	/* end block 1 */
	// End offset: 0x8006D6AC
	// End Line: 2356

	/* begin block 2 */
		// Start line: 5103
	/* end block 2 */
	// End Line: 5104

void Monster_Action_Feast
               (_D3_OBJECT *o,_D3_OBJECT *tmpobj,long AnimRun,long AnimFeast,long power,long sound)

{
  long lVar1;
  M_OBJECT *obj;
  
  obj = (M_OBJECT *)o->description;
  while( true ) {
    lVar1 = Monster_Action_MoveTo
                      ((int)(tmpobj->pos).vx,(int)(tmpobj->pos).vy,(int)(tmpobj->pos).vz,
                       (_D3_OBJECT *)0x0,100,-1,AnimRun,-1,-1,-1,-1);
    if (lVar1 != 0) break;
    Task_Next();
  }
  while (lVar1 = D3_GoToDir(o,(int)(tmpobj->pos).vx - (int)(o->pos).vx,
                            (int)(tmpobj->pos).vy - (int)(o->pos).vy,0xa0), lVar1 != 0) {
    Task_Next();
  }
  while ((tmpobj->display_mode & 0x10U) != 0) {
    Manim_SetAnim(obj,AnimFeast);
    while (((obj->Env).Obj.normal_top.vx & 0x4000U) == 0) {
      if (((int)(obj->Env).Obj.vert_top.pad & 0x8000U) != 0) {
        if (sound != -1) {
          D3_PlaySound(o,(short)sound);
        }
        Impact_Blood((char)tmpobj + ',',3);
        *(short *)(*(int *)&tmpobj[1].last_pos + 0x124) =
             *(short *)(*(int *)&tmpobj[1].last_pos + 0x124) - (short)power;
        if (*(short *)(*(int *)&tmpobj[1].last_pos + 0x124) < 0) {
          tmpobj->display_mode = tmpobj->display_mode & 0xffef;
        }
      }
      Task_Next();
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Monster_Action_WaitRun(struct _MONSTER *monst /*$s1*/, short AnimWait /*$s4*/, short AnimRun /*stack -48*/, short distance /*$fp*/, long follow /*stack 16*/, int snd /*stack 20*/)
 // line 2359, offset 0x8006d6dc
	/* begin block 1 */
		// Start line: 2360
		// Start offset: 0x8006D6DC
		// Variables:
	// 		struct _D3_OBJECT *o; // $s5
	// 		struct M_OBJECT *mo; // $s2
	// 		long x; // $s0
	// 		long y; // $t1
	/* end block 1 */
	// End offset: 0x8006D97C
	// End Line: 2421

	/* begin block 2 */
		// Start line: 5175
	/* end block 2 */
	// End Line: 5176

void Monster_Action_WaitRun
               (_MONSTER *monst,short AnimWait,short AnimRun,short distance,long follow,int snd)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  _ENEMYZONE *p_Var5;
  uint uVar6;
  int iVar7;
  M_OBJECT *obj;
  _D3_OBJECT *o;
  
  o = monst->obj;
  obj = (M_OBJECT *)o->description;
  monst->busy = 0;
  monst->mode = 0x10;
  Manim_SetAnim(obj,(int)AnimWait);
  p_Var5 = monst->zone_wait;
  if ((299 < (int)p_Var5->x2 - (int)p_Var5->x1) && (299 < (int)p_Var5->y2 - (int)p_Var5->y1)) {
    do {
      if (follow != 0) {
        Monster_Action_FollowObject((_D3_OBJECT *)Monster_Feelings,AnimWait);
        iVar7 = 0;
        (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
        while (uVar6 = M_rand(), iVar7 < (int)(uVar6 & 0x3f)) {
          iVar7 = iVar7 + 1;
          Task_Next();
        }
        Monster_Action_FollowObject((_D3_OBJECT *)Monster_Feelings,AnimWait);
      }
      if ((short)snd != -1) {
        if (monst->fx_handle == 0) {
          uVar6 = M_rand();
          D3_PlaySound(o,(short)(((snd & 0xffffU) + (uVar6 & 3)) * 0x10000 >> 0x10));
          sVar4 = 0x5a;
        }
        else {
          sVar4 = monst->fx_handle + -1;
        }
        monst->fx_handle = sVar4;
      }
      if ((o[1].pos.vz & 0x200U) == 0) {
        uVar6 = M_rand();
        if ((uVar6 & 1) == 0) {
          sVar4 = monst->zone_wait->x2;
        }
        else {
          sVar4 = monst->zone_wait->x1;
        }
        sVar1 = monst->zone_wait->x1;
        sVar2 = monst->zone_wait->x2;
        uVar6 = M_rand();
        if ((uVar6 & 1) == 0) {
          sVar3 = monst->zone_wait->y2;
        }
        else {
          sVar3 = monst->zone_wait->y1;
        }
        p_Var5 = monst->zone_wait;
        Monster_Action_MoveTo
                  ((int)sVar4 + ((int)sVar1 + (int)sVar2 >> 1) >> 1,
                   (int)sVar3 + ((int)p_Var5->y1 + (int)p_Var5->y2 >> 1) >> 1,
                   (int)p_Var5->z1 + (int)p_Var5->z2 >> 1,(_D3_OBJECT *)0x0,(int)distance,-1,
                   (int)AnimRun,-1,-1,-1,-1);
        monst->fx_handle = 0;
        Manim_ForceAnim(obj,(int)AnimWait);
        (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
      }
      Task_Next();
    } while( true );
  }
  do {
    Monster_Action_FollowObject((_D3_OBJECT *)Monster_Feelings,AnimWait);
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Monster_Action_Fear(struct _MONSTER *monst /*$s2*/, long AnimWait /*$s4*/, long AnimRun /*$s5*/, long distance /*$s3*/, long snd /*stack 16*/)
 // line 2423, offset 0x8006d97c
	/* begin block 1 */
		// Start line: 2424
		// Start offset: 0x8006D97C
		// Variables:
	// 		struct _D3_OBJECT *o; // $a0
	// 		struct M_OBJECT *mo; // $s1
	/* end block 1 */
	// End offset: 0x8006DAF4
	// End Line: 2455

	/* begin block 2 */
		// Start line: 5332
	/* end block 2 */
	// End Line: 5333

void Monster_Action_Fear(_MONSTER *monst,long AnimWait,long AnimRun,long distance,long snd)

{
  _ENEMYZONE *p_Var1;
  long lVar2;
  _D3_OBJECT *o;
  M_OBJECT *obj;
  
  o = monst->obj;
  obj = (M_OBJECT *)o->description;
  if (monst->zone_fear != -1) {
    TaskCurrent->event_enable = 0;
    if (snd != -1) {
      D3_PlaySound(o,(short)snd);
    }
    p_Var1 = Pvl_EnemyZones + (int)monst->zone_fear;
    Monster_Action_MoveTo
              ((int)p_Var1->x1 + (int)p_Var1->x2 >> 1,(int)p_Var1->y1 + (int)p_Var1->y2 >> 1,
               (int)p_Var1->z1 + (int)p_Var1->z2 >> 1,(_D3_OBJECT *)0x0,distance,-1,AnimRun,-1,-1,-1
               ,-1);
    lVar2 = Monster_FearFindFriends(monst);
    if (lVar2 != 0) {
      MSensor_AddFear(monst,-100);
    }
    TaskCurrent->event_enable = 1;
    if (LONG_800b2e64 != -1) {
      do {
        Manim_ForceAnim(obj,AnimWait);
        while (((obj->Env).Obj.normal_top.vx & 0x4000U) == 0) {
          if (LONG_800b2e64 == -1) {
            return;
          }
          Monster_Action_FollowObject((_D3_OBJECT *)Monster_Feelings,(short)AnimWait);
          Task_Next();
        }
      } while (LONG_800b2e64 != -1);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Monster_Reflex_Fear(struct _MONSTER *monst /*$s0*/)
 // line 2457, offset 0x8006db18
	/* begin block 1 */
		// Start line: 5417
	/* end block 1 */
	// End Line: 5418

long Monster_Reflex_Fear(_MONSTER *monst)

{
  if (monst->action != 0x1e) {
    if (LONG_800b2e28 != -1) {
      return 0;
    }
    if (LONG_800b2e64 == -1) {
      return 0;
    }
    if (monst->zone_current == Pvl_EnemyZones + (int)monst->zone_fear) {
      return 0;
    }
    if ((int)monst->zone_fear != -1) {
      if (LONG_800b2e64 < 0x101) {
        return 0;
      }
      Monster_ResetActions(monst);
      Monster_AddAction(monst,0,0x1e,0,0);
      return 1;
    }
  }
  return 0;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Monster_CalcShotPower(long whichshot /*$a0*/, struct MONSTER_8fake *col /*$a1*/)
 // line 2480, offset 0x8006dbcc
	/* begin block 1 */
		// Start line: 2482
		// Start offset: 0x8006DBCC
		// Variables:
	// 		long shotpower; // $a2
	// 		short comp; // $v1
	/* end block 1 */
	// End offset: 0x8006DCD4
	// End Line: 2539

	/* begin block 2 */
		// Start line: 5467
	/* end block 2 */
	// End Line: 5468

long Monster_CalcShotPower(long whichshot,undefined col)

{
  int iVar1;
  undefined3 in_register_00000015;
  byte *pbVar2;
  int iVar3;
  
  pbVar2 = (byte *)CONCAT31(in_register_00000015,col);
  switch(whichshot) {
  case 1:
  case 2:
  case 3:
  case 0x14:
    iVar3 = 0xf;
    break;
  case 4:
  case 6:
  case 10:
  case 0xb:
    iVar3 = 0x28;
    break;
  case 5:
    iVar3 = 0x32;
    break;
  case 7:
  case 8:
  case 9:
  case 0xd:
    iVar3 = 0x14;
    break;
  default:
    iVar3 = 4;
  }
  iVar1 = (uint)*pbVar2 + (int)Pvl_LevelNumber * 5;
  if (iVar1 * 0x10000 >> 0x10 < 0x100) {
    *pbVar2 = (byte)iVar1;
  }
  else {
    *pbVar2 = 0xff;
  }
  iVar1 = (uint)pbVar2[1] + (int)Pvl_LevelNumber * 5;
  if (iVar1 * 0x10000 >> 0x10 < 0x100) {
    pbVar2[1] = (byte)iVar1;
  }
  else {
    pbVar2[1] = 0xff;
  }
  iVar1 = (uint)pbVar2[2] + (int)Pvl_LevelNumber * 5;
  if (iVar1 * 0x10000 >> 0x10 < 0x100) {
    pbVar2[2] = (byte)iVar1;
  }
  else {
    pbVar2[2] = 0xff;
  }
  return iVar3 + (int)Pvl_LevelNumber;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Monster_Action_ShootMultiple(long Anim /*stack 0*/, long Amount /*stack 4*/, long Heightpos /*$a2*/, long waiter /*$s0*/, long missing /*stack 16*/, long Sound /*stack 20*/, long type /*stack 24*/)
 // line 2543, offset 0x8006dce4
	/* begin block 1 */
		// Start line: 2544
		// Start offset: 0x8006DCE4
		// Variables:
	// 		struct MONSTER_7fake pos; // stack offset -80
	// 		struct MONSTER_7fake rot; // stack offset -72
	// 		struct MONSTER_8fake col; // stack offset -64
	// 		struct _MONSTER *monst; // stack offset -56
	// 		struct _D3_OBJECT *o; // $s3
	// 		struct M_OBJECT *mo; // $s7
	// 		struct _D3_OBJECT *target; // $s4
	// 		long i; // $s6
	// 		long direct; // $s1
	// 		long size; // $s5
	// 		long tmp; // $s2
	/* end block 1 */
	// End offset: 0x8006EA88
	// End Line: 2830

	/* begin block 2 */
		// Start line: 5592
	/* end block 2 */
	// End Line: 5593

/* WARNING: Could not reconcile some variable overlaps */

void Monster_Action_ShootMultiple
               (long Anim,long Amount,long Heightpos,long waiter,long missing,long Sound,long type)

{
  long lVar1;
  _MONSTER *monst;
  int iVar2;
  int iVar3;
  long lVar4;
  uint uVar5;
  _D3_OBJECT *ot;
  int iVar6;
  uint uVar7;
  M_OBJECT *obj;
  undefined4 local_50;
  short local_4c;
  
  lVar1 = Monster_Feelings;
  monst = (_MONSTER *)TaskCurrent->local;
  ot = monst->obj;
  obj = (M_OBJECT *)ot->description;
  (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
  local_50 = *(undefined4 *)&ot->pos;
  local_4c = (short)*(undefined4 *)&(ot->pos).vz;
  if ((ot->collision_state & 0x80U) != 0) {
    iVar6 = 0;
    if (400 < LONG_ARRAY_800b2e40[0]) {
      do {
        iVar2 = rcos((int)(ot->rot).vz);
        iVar3 = rsin((int)(ot->rot).vz);
        local_50 = CONCAT22((short)((uint)local_50 >> 0x10) + (short)(iVar3 * 0x50 >> 0xc),
                            (short)local_50 + (short)(iVar2 * 0x50 >> 0xc));
        lVar4 = Boxes_GetHeightPlatform(ot,0xb0);
        iVar6 = iVar6 + 1;
        if ((int)(short)(local_4c + (short)Heightpos) + 200 < lVar4) {
          return;
        }
      } while (iVar6 < 5);
    }
    iVar6 = 0;
    if (0 < waiter) {
      do {
        while (lVar4 = D3_GoToDir(ot,(int)*(short *)(lVar1 + 0x2c) - (int)(ot->pos).vx,
                                  (int)*(short *)(lVar1 + 0x2e) - (int)(ot->pos).vy,0xa0),
              lVar4 != 0) {
          Task_Next();
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < waiter);
    }
    if (Anim != -1) {
      Manim_ForceAnim(obj,Anim);
      Manim_WaitEvent(obj,0x8000);
    }
    switch(type) {
    case 1:
    case 2:
      break;
    case 3:
      break;
    case 4:
    case 6:
    case 0xb:
      break;
    case 5:
      break;
    case 7:
      break;
    case 8:
      break;
    case 9:
      break;
    case 10:
      break;
    case 0xd:
    case 0x14:
    }
    uVar7 = 0;
    if (0 < Amount) {
      uVar5 = type - 1;
      do {
        D3_GoToDir(ot,(int)*(short *)(lVar1 + 0x2c) - (int)(short)local_50,
                   (int)*(short *)(lVar1 + 0x2e) - (int)local_50._2_2_,0x100);
        if ((LONG_ARRAY_800b2e40[0] != -1) && (LONG_ARRAY_800b2e40[0] < 200)) {
LAB_8006df68:
          MSensor_AddAgression(monst,100);
          return;
        }
        if (uVar5 < 0x14) {
                    /* WARNING: Could not recover jumptable at 0x8006e028. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*(code *)PTR_ARRAY_800a5578[uVar5])();
          return;
        }
        Direction((int)*(short *)(lVar1 + 0x2c) - (int)(short)local_50,
                  (int)*(short *)(lVar1 + 0x2e) - (int)local_50._2_2_);
        if (Pvl_LevelNumber < 4) {
          if ((uVar7 & 1) == 0) {
            M_rand();
          }
          else {
            M_rand();
          }
        }
        else {
          if (missing != 0) {
            M_rand();
          }
        }
        Impact_Sparks(0xb0,2);
        if (Sound != -1) {
          D3_PlaySound(ot,(short)Sound);
        }
        Monster_CalcShotPower(type,0xc0);
        if (uVar5 < 0x14) {
                    /* WARNING: Could not recover jumptable at 0x8006e5dc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*(code *)PTR_ARRAY_800a55c8[uVar5])();
          return;
        }
        if (Anim != -1) {
          while (((obj->Env).Obj.normal_top.vx & 0x4000U) == 0) {
            if ((LONG_ARRAY_800b2e40[0] != -1) && (LONG_ARRAY_800b2e40[0] < 200)) goto LAB_8006df68;
            Task_Next();
          }
          if ((int)uVar7 < Amount + -1) {
            Manim_ForceAnim(obj,Anim);
            Manim_WaitEvent(obj,0x8000);
          }
        }
        uVar7 = uVar7 + 1;
      } while ((int)uVar7 < Amount);
    }
    if ((((type != 0x13) && (type != 5)) && (type != 8)) &&
       (((type != 0xe && (type != 0xc)) && ((type != 0xf && (type != 0x10)))))) {
      Impact_Smoke(0xb0,0);
    }
    (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Monster_Grenade_Add(struct _D3_OBJECT *o /*$s1*/, struct _D3_OBJECT *target /*$s0*/)
 // line 2833, offset 0x8006eab8
	/* begin block 1 */
		// Start line: 2834
		// Start offset: 0x8006EAB8
		// Variables:
	// 		struct MONSTER_7fake pos; // stack offset -32
	// 		struct MONSTER_7fake rot; // stack offset -24
	// 		long height; // $s0
	// 		long i; // $a3
	/* end block 1 */
	// End offset: 0x8006EB90
	// End Line: 2851

	/* begin block 2 */
		// Start line: 6561
	/* end block 2 */
	// End Line: 6562

void Monster_Grenade_Add(_D3_OBJECT *o,_D3_OBJECT *target)

{
  short sVar1;
  short sVar2;
  long distance;
  
  distance = Direction((int)(target->pos).vx - (int)(o->pos).vx,
                       (int)(target->pos).vy - (int)(o->pos).vy);
  rcos((int)(short)distance);
  rsin((int)(short)distance);
  sVar1 = (target->pos).vz;
  sVar2 = (o->pos).vz;
  distance = Distance2D((int)(o->pos).vx,(int)(o->pos).vy,(int)(target->pos).vx,
                        (int)(target->pos).vy);
  distance = (long)(short)distance;
  if (distance < 400) {
    distance = 400;
  }
  Grenade_Add(0xe0,0xe8,5,distance,o,(int)sVar1 - (int)sVar2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Monster_Action_Shooting(long AnimStart /*stack 0*/, long AnimStop /*stack 4*/, long AnimShoot /*stack 8*/, long ShootType /*$s6*/, long amount /*stack 16*/, long height /*stack 20*/, long missing /*stack 24*/, long waiter /*stack 28*/, long Sound /*stack 32*/)
 // line 2856, offset 0x8006ebb8
	/* begin block 1 */
		// Start line: 2857
		// Start offset: 0x8006EBB8
		// Variables:
	// 		struct _MONSTER *monst; // $fp
	// 		struct _D3_OBJECT *o; // $s1
	// 		struct M_OBJECT *mo; // $s3
	// 		struct _D3_OBJECT *target; // $s4
	// 		struct _D3_OBJECT *tmpobj; // $s0
	// 		struct MONSTER_7fake rot; // stack offset -160
	// 		struct MONSTER_7fake pos; // stack offset -152
	// 		struct MONSTER_8fake col; // stack offset -144
	// 		long i; // $s0
	// 		long j; // $s2
	// 		long d; // $s5
	// 		long done; // $s6

		/* begin block 1.1 */
			// Start line: 2930
			// Start offset: 0x8006EED4
			// Variables:
		// 		struct MONSTER_7fake lpos[12]; // stack offset -136
		/* end block 1.1 */
		// End offset: 0x8006F1F8
		// End Line: 3016
	/* end block 1 */
	// End offset: 0x8006F250
	// End Line: 3028

	/* begin block 2 */
		// Start line: 6616
	/* end block 2 */
	// End Line: 6617

void Monster_Action_Shooting
               (long AnimStart,long AnimStop,long AnimShoot,long ShootType,long amount,long height,
               long missing,long waiter,long Sound)

{
  ushort uVar1;
  bool bVar2;
  long ot;
  short sVar3;
  long lVar4;
  uint uVar5;
  long lVar6;
  _D3_OBJECT *p_Var7;
  int iVar8;
  _D3_OBJECT *o;
  M_OBJECT *obj;
  _MONSTER *monst;
  
  ot = Monster_Feelings;
  monst = (_MONSTER *)TaskCurrent->local;
  o = monst->obj;
  obj = (M_OBJECT *)o->description;
  if ((((AnimStart != -1) || (AnimStop != -1)) || (AnimShoot != -1)) &&
     ((o->collision_state & 0x80U) == 0)) {
    return;
  }
  if ((LONG_ARRAY_800b2e40[0] != -1) && (LONG_ARRAY_800b2e40[0] < 200)) {
LAB_8006f070:
    MSensor_AddAgression(monst,100);
    return;
  }
  monst->mode = 0xd;
  if ((AnimStart & AnimShoot) != 0xffffffff) {
    (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
  }
  if (height != -1) {
    while (lVar4 = D3_GoToDir(o,(int)*(short *)(ot + 0x2c) - (int)(o->pos).vx,
                              (int)*(short *)(ot + 0x2e) - (int)(o->pos).vy,0xa0), lVar4 != 0) {
      Task_Next();
    }
  }
  if (AnimStart != -1) {
    Manim_SetAnim(obj,AnimStart);
    uVar1 = (obj->Env).Obj.normal_top.vx;
    while ((uVar1 & 0x4000) == 0) {
      if ((LONG_ARRAY_800b2e40[0] != -1) && (LONG_ARRAY_800b2e40[0] < 200)) goto LAB_8006f070;
      Task_Next();
      uVar1 = (obj->Env).Obj.normal_top.vx;
    }
  }
  MSensor_AddAgression(monst,-0x14);
  if ((AnimStart & AnimShoot) != 0xffffffff) {
    (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
  }
  lVar4 = LONG_ARRAY_800b2e40[0];
  if (ShootType - 1U < 0x14) {
    Monster_Action_ShootMultiple(AnimShoot,amount,height,waiter,missing,Sound,ShootType);
  }
  else {
    if (ShootType == 0x16) {
      Shoot_Add(o,0x68,0x60,0,7,0x21,5,2);
    }
    else {
      if (ShootType < 0x17) {
        if (ShootType == 0x15) {
          Manim_ForceAnim(obj,AnimShoot);
          iVar8 = 0;
          (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
          if (0 < waiter) {
            do {
              iVar8 = iVar8 + 1;
              Task_Next();
            } while (iVar8 < waiter);
          }
          while (lVar4 = D3_GoToDir(o,(int)*(short *)(ot + 0x2c) - (int)(o->pos).vx,
                                    (int)*(short *)(ot + 0x2e) - (int)(o->pos).vy,0xa0), lVar4 != 0)
          {
            Task_Next();
          }
          (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx | 1;
          Manim_WaitEvent(obj,0x8000);
          if (Sound != -1) {
            D3_PlaySound(o,(short)Sound);
          }
          Monster_Grenade_Add(o,(_D3_OBJECT *)ot);
          Manim_WaitAnim(obj);
          (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
        }
      }
      else {
        iVar8 = 0x50;
        if (ShootType < 0x1a) {
          uVar5 = Direction((int)*(short *)(ot + 0x2c) - (int)(o->pos).vx,
                            (int)*(short *)(ot + 0x2e) - (int)(o->pos).vy);
          if ((ShootType != 0x19) && (0x50 < lVar4)) {
            do {
              rcos(uVar5);
              rsin(uVar5);
              sVar3 = (o->pos).vz;
              lVar6 = Boxes_GetHeight((_D3_OBJECT *)ot,0x68,300);
              bVar2 = iVar8 < lVar4;
              if ((int)sVar3 + 100 < lVar6) break;
              iVar8 = iVar8 + 0x50;
              bVar2 = iVar8 < lVar4;
            } while (bVar2);
            if (bVar2) goto LAB_8006f1f8;
          }
          if (ot == 0) {
            return;
          }
          if (AnimShoot != -1) {
            Manim_ForceAnim(obj,AnimShoot);
            Manim_WaitEvent(obj,0x8000);
            (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
          }
          Boxes_GetCenter(o,0x68);
          if ((ShootType == 0x19) && (p_Var7 = Monster_GetChild(o,1), p_Var7 != (_D3_OBJECT *)0x0))
          {
            rcos((int)(p_Var7->rot).vz);
            rsin((int)(p_Var7->rot).vz);
          }
          else {
            rcos((int)(o->rot).vz);
            rsin((int)(o->rot).vz);
          }
          bVar2 = false;
          if (Sound != -1) {
            D3_PlaySound(o,(short)Sound);
          }
          iVar8 = 0;
          do {
            Boxes_GetCenter((_D3_OBJECT *)ot,0x60);
            sVar3 = Motion2D_LightningCompute(0x68,0x60,(o->rot).vz,0x78,0xc);
            Motion2D_LightningDisplay(0x70,0x78,0xc,1);
            if ((sVar3 == 0xc) && (!bVar2)) {
              *(undefined *)((int)&o[1].pos.vx + 1) = 0xf6;
              bVar2 = true;
              if ((*(ushort *)(ot + 0x1c) & 0x1000) != 0) {
                Pl_SetStateBits((_PLAYER *)ot,0x10);
              }
              D3_SetCollBits(o,2);
              Boxes_ObjectFound(o,(_D3_OBJECT *)ot,0);
              D3_ClearCollBits(o,2);
              MSensor_AddAgression(monst,-200);
            }
            iVar8 = iVar8 + 1;
            Task_Next();
            *(undefined *)((int)&o[1].pos.vx + 1) = (char)sVar3;
          } while (iVar8 < 0x14);
          if (AnimShoot != -1) {
            (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx | 1;
            Manim_WaitAnim(obj);
          }
        }
      }
    }
  }
LAB_8006f1f8:
  if (AnimStop != -1) {
    Manim_SetAnim(obj,AnimStop);
    Manim_WaitAnim(obj);
  }
  if ((AnimStart & AnimShoot) != 0xffffffff) {
    (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
  }
  *(undefined **)&monst->actionmask = PTR_DAT_800ad81c;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Monster_Action_BeingHit(long direction /*$s0*/, long AnimNr /*$a1*/, long param /*$s4*/)
 // line 3038, offset 0x8006f280
	/* begin block 1 */
		// Start line: 3039
		// Start offset: 0x8006F280
		// Variables:
	// 		struct _MONSTER *monst; // $v1
	// 		struct _D3_OBJECT *obj; // $s1
	// 		struct M_OBJECT *mo; // $s3
	// 		long speed; // $s2
	/* end block 1 */
	// End offset: 0x8006F394
	// End Line: 3079

	/* begin block 2 */
		// Start line: 7105
	/* end block 2 */
	// End Line: 7106

void Monster_Action_BeingHit(long direction,long AnimNr,long param)

{
  ushort uVar1;
  int iVar2;
  short sVar3;
  M_OBJECT *obj;
  
  sVar3 = 0;
  iVar2 = *(int *)TaskCurrent->local;
  obj = *(M_OBJECT **)(iVar2 + 0x24);
  *(undefined2 *)(TaskCurrent->local + 4) = 0x13;
  Manim_ForceAnim(obj,AnimNr);
  *(undefined2 *)(iVar2 + 0x40) = (short)direction;
  if (param == 1) {
    Impact_Blood((char)iVar2 + ',',10);
  }
  else {
    if ((1 < param) && (param == 2)) {
      Impact_GreenBlood((char)iVar2 + ',',10);
    }
  }
  uVar1 = (obj->Env).Obj.normal_top.vx;
  while (((uVar1 & 0x4000) == 0 && (((int)(obj->Env).Obj.vert_top.pad & 0x8000U) == 0))) {
    if (((param & 0x800U) != 0) && ((*(ushort *)(iVar2 + 0x1c) & 9) != 0)) {
      sVar3 = sVar3 + -5;
      if ((*(ushort *)(iVar2 + 0x1e) & 0x4000) == 0) {
        *(short *)(iVar2 + 0x30) = *(short *)(iVar2 + 0x30) + sVar3;
      }
      else {
        sVar3 = 0;
      }
    }
    Task_Next();
    uVar1 = (obj->Env).Obj.normal_top.vx;
  }
  Task_Next();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Monster_Action_Exploding(long AnimNr /*$s1*/, long direction /*$s0*/)
 // line 3084, offset 0x8006f3bc
	/* begin block 1 */
		// Start line: 3085
		// Start offset: 0x8006F3BC
		// Variables:
	// 		struct _MONSTER *monst; // $v0
	// 		struct _D3_OBJECT *obj; // $s3
	// 		struct M_OBJECT *mo; // $s2
	// 		long speedz; // $s5
	// 		long speedx; // $s7
	// 		long speedy; // $s6
	// 		long posx; // $s4
	// 		long posy; // $s1
	// 		long posz; // $s0
	/* end block 1 */
	// End offset: 0x8006F584
	// End Line: 3123

	/* begin block 2 */
		// Start line: 7205
	/* end block 2 */
	// End Line: 7206

/* WARNING: Type propagation algorithm not settling */

void Monster_Action_Exploding(long AnimNr,long direction)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  M_OBJECT *obj;
  _D3_OBJECT *o;
  int iVar6;
  int iVar7;
  
  iVar7 = 0x21000;
  o = ((_D3_OBJECT *)TaskCurrent->local)->next;
  obj = (M_OBJECT *)o->description;
  iVar2 = rcos(direction);
  iVar2 = iVar2 << 4;
  iVar3 = rsin(direction);
  iVar3 = iVar3 << 4;
  iVar6 = (int)(o->pos).vx << 0xc;
  iVar4 = (int)(o->pos).vz << 0xc;
  iVar5 = (int)(o->pos).vy << 0xc;
  TaskCurrent->event_enable = 0;
  Manim_SetAnim(obj,AnimNr);
  do {
    if (((obj->Env).Obj.n_normal != 0) && (0x18 < (obj->Env).Obj.vert_top.vz)) {
      (obj->Env).Obj.vert_top.vz = 0x10;
    }
    if (((int)(obj->Env).Obj.vert_top.pad & 0x8000U) != 0) {
      (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
    }
    if ((o->collision_state & 0xc00U) != 0) {
      iVar2 = 0;
    }
    if ((o->collision_state & 0x3000U) != 0) {
      iVar3 = 0;
    }
    iVar7 = iVar7 + -0x2800;
    iVar6 = iVar6 + iVar2;
    iVar5 = iVar5 + iVar3;
    iVar4 = iVar4 + iVar7;
    (o->pos).vx = (short)(iVar6 >> 0xc);
    (o->pos).vy = (short)(iVar5 >> 0xc);
    (o->pos).vz = (short)(iVar4 >> 0xc);
    Task_Next();
  } while (((o->collision_state & 0x4000U) == 0) && (-1000 < (o->pos).vz));
  uVar1 = (obj->Env).Obj.normal_top.vx;
  (obj->Env).Obj.normal_top.vx = uVar1 | 1;
  while ((uVar1 & 0x4000) == 0) {
    if (((obj->Env).Obj.n_normal != 0) && (0x18 < (obj->Env).Obj.vert_top.vz)) {
      (obj->Env).Obj.vert_top.vz = 0x10;
    }
    Task_Next();
    uVar1 = (obj->Env).Obj.normal_top.vx;
  }
  D3_ClearCollBits(o,(long)&DAT_00004011);
  TaskCurrent->event_enable = 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Monster_Action_Dieing(long AnimNr /*$s3*/, long bottom /*$s4*/)
 // line 3128, offset 0x8006f5cc
	/* begin block 1 */
		// Start line: 3129
		// Start offset: 0x8006F5CC
		// Variables:
	// 		struct _MONSTER *monst; // $v0
	// 		struct _D3_OBJECT *obj; // $s1
	// 		struct M_OBJECT *mo; // $s0
	// 		long speed; // $s2
	/* end block 1 */
	// End offset: 0x8006F80C
	// End Line: 3189

	/* begin block 2 */
		// Start line: 7308
	/* end block 2 */
	// End Line: 7309

/* WARNING: Type propagation algorithm not settling */

void Monster_Action_Dieing(long AnimNr,long bottom)

{
  ushort uVar1;
  char cVar2;
  long lVar3;
  M_OBJECT *obj;
  _D3_OBJECT *o;
  short sVar4;
  
  o = ((_D3_OBJECT *)TaskCurrent->local)->next;
  obj = (M_OBJECT *)o->description;
  sVar4 = 0;
  cVar2 = (char)o;
  if (*(short *)((int)&o->comp_opt4 + 2) == 1) {
    Impact_Blood(cVar2 + ',',10);
  }
  Manim_SetAnim(obj,AnimNr);
  TaskCurrent->event_enable = 0;
  lVar3 = Manim_WaitEvent(obj,0x8000);
  if (lVar3 != 0) {
    (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
    while (((o->collision_state & 0x4000U) == 0 && (-2000 < (o->pos).vz))) {
      if (((obj->Env).Obj.n_normal != 0) && (0x18 < (obj->Env).Obj.vert_top.vz)) {
        (obj->Env).Obj.vert_top.vz = 0x10;
      }
      sVar4 = sVar4 + -5;
      (o->pos).vz = (o->pos).vz + sVar4;
      Task_Next();
      if (((obj->Env).Obj.vert_top.pad & 1U) != 0) {
        Fx_Play(0x43,cVar2 + ',');
      }
      if (((int)o->collision_state & 0xfc00U) != 0) {
        Fx_Play(0x43,cVar2 + ',');
      }
    }
    uVar1 = (obj->Env).Obj.normal_top.vx;
    (obj->Env).Obj.normal_top.vx = uVar1 | 1;
    while ((uVar1 & 0x4000) == 0) {
      if (((obj->Env).Obj.n_normal != 0) && (0x18 < (obj->Env).Obj.vert_top.vz)) {
        (obj->Env).Obj.vert_top.vz = 0x10;
      }
      Task_Next();
      if (((obj->Env).Obj.vert_top.pad & 1U) != 0) {
        Fx_Play(0x43,cVar2 + ',');
      }
      uVar1 = (obj->Env).Obj.normal_top.vx;
    }
  }
  sVar4 = 0;
  (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
  uVar1 = o->collision_state;
  while (((uVar1 & 0x4000) == 0 && (bottom < (int)(o->pos).vz))) {
    if (((obj->Env).Obj.n_normal != 0) && (0x18 < (obj->Env).Obj.vert_top.vz)) {
      (obj->Env).Obj.vert_top.vz = 0x10;
    }
    sVar4 = sVar4 + -5;
    (o->pos).vz = (o->pos).vz + sVar4;
    Task_Next();
    uVar1 = o->collision_state;
  }
  D3_ClearCollBits(o,(long)&DAT_00004011);
  (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Monster_Action_Hit(long AnimHurt /*$s2*/, long AnimDie /*$s4*/, long param /*$s5*/, long SndDead /*$s6*/)
 // line 3194, offset 0x8006f844
	/* begin block 1 */
		// Start line: 3195
		// Start offset: 0x8006F844
		// Variables:
	// 		struct _MONSTER *monst; // $s3
	// 		struct _D3_OBJECT *obj; // $s0
	// 		struct M_OBJECT *mo; // $s1
	// 		struct MONSTER_7fake pos; // stack offset -40
	// 		long i; // $s0
	/* end block 1 */
	// End offset: 0x8006FF70
	// End Line: 3421

	/* begin block 2 */
		// Start line: 7449
	/* end block 2 */
	// End Line: 7450

/* WARNING: Type propagation algorithm not settling */

long Monster_Action_Hit(long AnimHurt,long AnimDie,long param,long SndDead)

{
  short sVar1;
  ushort uVar2;
  code *f;
  long bottom;
  _D3_OBJECT *o;
  int iVar3;
  M_OBJECT *mo;
  _MONSTER *monst;
  
  monst = (_MONSTER *)TaskCurrent->local;
  o = monst->obj;
  mo = (M_OBJECT *)o->description;
  TaskCurrent->event_enable = 0;
  if (LONG_800b2e24 != -1) {
    D3_ClearCollBits(o,2);
    if ((Monster_Feelings != 0) && ((*(ushort *)(Monster_Feelings + 0x1c) & 0x1000) != 0)) {
      Pl_AddExperience((_PLAYER *)Monster_Feelings,o);
    }
    if (((uint)(ushort)monst->mode - 0x32 < 3) && (monst->mode == 0x33)) {
      SFX_Explosion(0xd8,0,4);
      o->display_mode = o->display_mode & 0xffef;
      D3_ClearCollBits(o,9);
      monst->mode = 0x11;
      return 2;
    }
    monst->mode = 0x11;
    if (SndDead != -1) {
      D3_PlaySound(o,(short)SndDead);
    }
    if (AnimDie == -1) {
      return 1;
    }
    sVar1 = *(short *)((int)&o->comp_opt4 + 2);
    if (sVar1 == 0) {
      if ((monst->whohitme == -0x13) && ((o->display_mode & 0x40U) != 0)) {
        Manim_SetEffect(mo,Motion2D_ManimDistortion);
        D3_ClearCollBits(o,1);
        sVar1 = (mo->Env).Obj.vert_top.vz;
        (mo->Env).Obj.normal_top.vx = (mo->Env).Obj.normal_top.vx & 0xfffe;
        while (sVar1 < 0x1e) {
          Task_Next();
          sVar1 = (mo->Env).Obj.vert_top.vz;
        }
LAB_8006fd20:
        o->display_mode = o->display_mode & 0xffef;
        return 2;
      }
LAB_8006fd58:
      bottom = -2000;
LAB_8006fd5c:
      Monster_Action_Dieing(AnimDie,bottom);
      return 1;
    }
    if (sVar1 < 0) {
      return 1;
    }
    if (2 < sVar1) {
      return 1;
    }
    sVar1 = monst->whohitme;
    if (sVar1 != -9) {
      if (-9 < sVar1) {
        if (sVar1 < -1) {
          if (-7 < sVar1) {
            Manim_SetEffect(mo,Motion2D_EffectAnimXtra);
            o->color = 0;
            Monster_Action_Exploding(AnimDie,LONG_ARRAY_800b2e48[0] + 0x800U & 0xfff);
            if ((o->collision_state & 0x20U) != 0) {
              Manim_SetEffect(mo,Motion2D_EffectSmokeXtra);
            }
            D3_SetBox(o,(int)(o->b_box).vx,(int)o->comp_opt3,0,(int)*(short *)&o->b_step,
                      (int)(o->b_box).vy,10);
            D3_SetCollBits(o,1);
            (mo->Env).Obj.normal_top.vx = (mo->Env).Obj.normal_top.vx & 0xfffe;
            if ((o->display_mode & 0x10U) != 0) {
              while ((mo->Env).Obj.vert_top.vz < 0x5f) {
                Task_Next();
              }
            }
            goto LAB_8006fca4;
          }
          if (sVar1 != -8) goto LAB_8006fd4c;
        }
        else {
          if (sVar1 != 29999) goto LAB_8006fd4c;
        }
        if (AnimDie == -1) {
          return 1;
        }
        bottom = 0;
        goto LAB_8006fd5c;
      }
      if (sVar1 != -0x10) {
        if (sVar1 < -0xf) {
          if ((sVar1 == -0x13) && ((o->display_mode & 0x40U) != 0)) {
            Manim_SetEffect(mo,Motion2D_ManimDistortion);
            D3_ClearCollBits(o,1);
            sVar1 = (mo->Env).Obj.vert_top.vz;
            (mo->Env).Obj.normal_top.vx = (mo->Env).Obj.normal_top.vx & 0xfffe;
            while (sVar1 < 0x1e) {
              Task_Next();
              sVar1 = (mo->Env).Obj.vert_top.vz;
            }
            goto LAB_8006fd20;
          }
        }
        else {
          if ((sVar1 == -0xf) || (sVar1 == -10)) {
            Manim_SetEffect(mo,Motion2D_ManimElectricity);
            if (AnimDie != -1) {
              Monster_Action_Dieing(AnimDie,-2000);
            }
            (mo->Env).Obj.normal_top.vx = (mo->Env).Obj.normal_top.vx & 0xfffe;
            return 1;
          }
        }
LAB_8006fd4c:
        if (AnimDie == -1) {
          return 1;
        }
        goto LAB_8006fd58;
      }
    }
    if ((o->collision_state & 0x20U) == 0) {
      f = Motion2D_EffectAnimXtra;
    }
    else {
      f = Motion2D_EffectSmokeXtra;
    }
    Manim_SetEffect(mo,f);
    o->color = 0;
    if (AnimDie != -1) {
      Monster_Action_Dieing(AnimDie,-2000);
    }
    D3_SetBox(o,(int)(o->b_box).vx,(int)o->comp_opt3,0,(int)*(short *)&o->b_step,(int)(o->b_box).vy,
              10);
    D3_SetCollBits(o,1);
    (mo->Env).Obj.normal_top.vx = (mo->Env).Obj.normal_top.vx & 0xfffe;
    if (((o->display_mode & 0x10U) != 0) && ((mo->Env).Obj.n_normal != 0)) {
      while ((mo->Env).Obj.vert_top.vz < 0x5f) {
        Task_Next();
      }
    }
LAB_8006fca4:
    o->display_mode = o->display_mode & 0xffef;
    D3_ClearCollBits(o,1);
    return 2;
  }
  if (LONG_ARRAY_800b2e48[0] == -1) {
    return 0;
  }
  sVar1 = *(short *)((int)&o->comp_opt4 + 2);
  if (sVar1 == 0) {
    if (monst->whohitme == -0x13) {
      if (((o->display_mode & 0x40U) != 0) &&
         (Manim_SetEffect(mo,Motion2D_ManimSmallDistortion), (o->display_mode & 0x40U) != 0)) {
        uVar2 = (mo->Env).Obj.normal_top.vx & 0xfffe;
        (mo->Env).Obj.normal_top.vx = uVar2;
        if ((o->display_mode & 0x40U) != 0) {
          (mo->Env).Obj.normal_top.vx = uVar2 | 1;
        }
      }
    }
    else {
      if (AnimHurt != -1) {
        Monster_Action_BeingHit(LONG_ARRAY_800b2e48[0],AnimHurt,param & 0xffff);
      }
    }
  }
  else {
    if (sVar1 != 1) goto LAB_8006ff58;
  }
  switch((int)(((uint)(ushort)monst->whohitme + 0x13) * 0x10000) >> 0x10) {
  case 0:
    if ((o->display_mode & 0x40U) != 0) {
      Manim_SetEffect(mo,Motion2D_ManimSmallDistortion);
    }
    monst->flags2 = monst->flags2 | 2;
    iVar3 = 0;
    (mo->Env).Obj.normal_top.vx = (mo->Env).Obj.normal_top.vx & 0xfffe;
    do {
      iVar3 = iVar3 + 1;
      Task_Next();
    } while (iVar3 < 0x1e);
    (mo->Env).Obj.normal_top.vx = (mo->Env).Obj.normal_top.vx | 1;
    break;
  case 3:
  case 10:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x11:
    if ((o->collision_state & 0x20U) == 0) {
      f = Motion2D_ManimBurn;
      if ((code *)(mo->Env).Obj.n_normal == Motion2D_ManimBurn) {
        (mo->Env).Obj.vert_top.vz = 0x10;
      }
      else {
LAB_8006ff00:
        Manim_SetEffect(mo,f);
      }
    }
    else {
      f = Motion2D_ManimSmoke;
      if ((code *)(mo->Env).Obj.n_normal != Motion2D_ManimSmoke) goto LAB_8006ff00;
      (mo->Env).Obj.vert_top.vz = 0x10;
    }
  default:
    if (AnimHurt != -1) {
      Monster_Action_BeingHit(LONG_ARRAY_800b2e48[0],AnimHurt,param & 0xffff);
    }
    break;
  case 4:
  case 9:
    if ((code *)(mo->Env).Obj.n_normal != Motion2D_ManimElectricity) {
      Manim_SetEffect(mo,Motion2D_ManimElectricity);
    }
  }
LAB_8006ff58:
  TaskCurrent->event_enable = 1;
  Monster_StopAllActions(monst);
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Magic_StreamFire()
 // line 3431, offset 0x8006ff98
	/* begin block 1 */
		// Start line: 3432
		// Start offset: 0x8006FF98
		// Variables:
	// 		struct MONSTER_7fake pos; // stack offset -24
	// 		struct _D3_OBJECT *o; // $s2
	// 		struct TASK *t; // $s1
	// 		long i; // $s0
	/* end block 1 */
	// End offset: 0x8006FFDC
	// End Line: 3441

	/* begin block 2 */
		// Start line: 7942
	/* end block 2 */
	// End Line: 7943

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Magic_StreamFire(void)

{
  TASK *t;
  int iVar1;
  
  iVar1 = 0;
  t = SFX_StreamFire((_D3_OBJECT *)TaskCurrent->local);
  do {
    iVar1 = iVar1 + 1;
    Task_Next();
  } while (iVar1 < 0x3c);
  Task_Kill(t);
  Impact_Smoke(0xe8,1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Monster_Action_Magic(struct _MONSTER *monst /*$s4*/, long move /*$a1*/, long animstart /*$s5*/, long animstop /*$s7*/, long param /*stack 16*/)
 // line 3447, offset 0x80070034
	/* begin block 1 */
		// Start line: 3448
		// Start offset: 0x80070034
		// Variables:
	// 		struct MONSTER_8fake col; // stack offset -152
	// 		struct MONSTER_7fake pos; // stack offset -144
	// 		char old_resistance[10]; // stack offset -136
	// 		struct _D3_OBJECT *o; // $s3
	// 		struct M_OBJECT *mo; // $s1
	// 		long i; // $s0
	// 		long j; // $s2
	// 		long actionmask; // $s6

		/* begin block 1.1 */
			// Start line: 3467
			// Start offset: 0x800700CC
			// Variables:
		// 		long zones[10][2]; // stack offset -120
		// 		long low; // $a2
		// 		long high; // $t0
		/* end block 1.1 */
		// End offset: 0x800702BC
		// End Line: 3521
	/* end block 1 */
	// End offset: 0x80070408
	// End Line: 3575

	/* begin block 2 */
		// Start line: 7979
	/* end block 2 */
	// End Line: 7980

void Monster_Action_Magic(_MONSTER *monst,long move,long animstart,long animstop,long param)

{
  uchar *puVar1;
  bool bVar2;
  ushort uVar3;
  short sVar4;
  short sVar5;
  _PVL_HEADER *p_Var6;
  TASK *pTVar7;
  long lVar8;
  uchar *puVar9;
  int iVar10;
  _MONSTER *p_Var11;
  _ENEMYZONE *p_Var12;
  int *piVar13;
  ulong uVar14;
  ulong uVar15;
  int iVar16;
  int iVar17;
  M_OBJECT *obj;
  _D3_OBJECT *ot;
  ulong uVar18;
  uchar local_88 [16];
  int local_78;
  short local_74 [38];
  
  iVar16 = 0;
  ot = monst->obj;
  uVar18 = monst->actionmask;
  obj = (M_OBJECT *)ot->description;
  puVar9 = local_88;
  do {
    puVar1 = monst->resistance + iVar16;
    iVar16 = iVar16 + 1;
    *puVar9 = *puVar1;
    pTVar7 = TaskCurrent;
    puVar9 = local_88 + iVar16;
  } while (iVar16 < 10);
  monst->actionmask = 0xffffffff;
  pTVar7->event_enable = 0;
  p_Var6 = Pvl_File;
  if (move == 2) {
    iVar17 = 0;
    uVar14 = monst->zb_low;
    uVar15 = monst->zb_high;
    iVar16 = 0;
    if (0 < Pvl_File->n_enemyzones) {
      piVar13 = &local_78;
      p_Var12 = Pvl_EnemyZones;
      do {
        if ((uVar14 & 1) != 0) {
          *piVar13 = (int)p_Var12->x1 + (int)p_Var12->x2 >> 1;
          iVar17 = iVar17 + 1;
          piVar13[1] = (int)p_Var12->y1 + (int)p_Var12->y2 >> 1;
          piVar13 = piVar13 + 2;
        }
        uVar14 = (int)uVar14 >> 1;
        if (iVar16 == 0x1f) {
          uVar14 = uVar15;
        }
        if (iVar17 == 10) break;
        iVar16 = iVar16 + 1;
        p_Var12 = p_Var12 + 1;
      } while (iVar16 < (int)p_Var6->n_enemyzones);
    }
    pTVar7 = Task_Link(Magic_StreamFire,0x100);
    *(_D3_OBJECT **)&pTVar7->local = ot;
    Manim_SetAnim(obj,animstart);
    uVar3 = (obj->Env).Obj.normal_top.vx;
    *(undefined4 *)&(obj->Sq).Data.Flag = 0x1000;
    while ((uVar3 & 0x4000) == 0) {
      iVar10 = *(int *)&(obj->Sq).Data.Flag;
      if (0x600 < iVar10) {
        *(int *)&(obj->Sq).Data.Flag = iVar10 + -0x30;
      }
      Task_Next();
      uVar3 = (obj->Env).Obj.normal_top.vx;
    }
    if (iVar17 != 0) {
      lVar8 = M_rand();
      iVar16 = lVar8 % iVar17;
      if (iVar17 == 0) {
        trap(0x1c00);
      }
      if ((iVar17 == -1) && (lVar8 == -0x80000000)) {
        trap(0x1800);
      }
    }
    sVar4 = *(short *)(&local_78 + iVar16 * 2);
    (ot->last_pos).vx = sVar4;
    (ot->pos).vx = sVar4;
    sVar4 = local_74[iVar16 * 4];
    (ot->last_pos).vy = sVar4;
    (ot->pos).vy = sVar4;
    lVar8 = Boxes_GetHeight(ot,(char)ot + ',',
                            (short)(((uint)(ushort)monst->height + 200) * 0x10000 >> 0x10));
    (ot->last_pos).vz = (short)lVar8;
    (ot->pos).vz = (short)lVar8;
    pTVar7 = Task_Link(Magic_StreamFire,0x100);
    *(_D3_OBJECT **)&pTVar7->local = ot;
    Manim_SetAnim(obj,animstop);
    while (((obj->Env).Obj.normal_top.vx & 0x4000U) == 0) {
      iVar16 = *(int *)&(obj->Sq).Data.Flag;
      if (iVar16 < 0x1000) {
        *(int *)&(obj->Sq).Data.Flag = iVar16 + 0x30;
      }
      Task_Next();
    }
    *(undefined4 *)&(obj->Sq).Data.Flag = 0;
  }
  else {
    if (move == 3) {
      iVar17 = 5;
      iVar16 = (int)&monst->sensormask + 1;
      do {
        *(undefined *)(iVar16 + 0x13c) = 4;
        iVar17 = iVar17 + -1;
        iVar16 = iVar16 + -1;
      } while (-1 < iVar17);
      Manim_SetAnim(obj,animstart);
      Manim_WaitAnim(obj);
      (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
      Manim_SetEffect((M_OBJECT *)ot->description,Motion2D_ManimInvincibility);
      sVar5 = Pvl_LevelNumber;
      *(undefined2 *)((int)ot->description + 0x1a) = (short)param;
      sVar4 = ot->hit_points;
      iVar16 = 0;
      if ((int)ot->hit_points < (int)Pvl_LevelNumber * 5 + 0x32) {
        do {
          bVar2 = iVar16 == 7 - (int)sVar5;
          iVar16 = iVar16 + 1;
          if (bVar2) {
            ot->hit_points = sVar4 + 1;
            iVar16 = 0;
          }
          Task_Next();
          sVar4 = ot->hit_points;
          sVar5 = Pvl_LevelNumber;
        } while ((int)ot->hit_points < (int)Pvl_LevelNumber * 5 + 0x32);
      }
      iVar16 = 0;
      Manim_SetEffect((M_OBJECT *)ot->description,(TDRFuncPtr_Manim_SetEffect1f)0x0);
      monst->hurttimer = 2;
      Manim_SetAnim(obj,animstop);
      Manim_WaitAnim(obj);
      p_Var11 = monst;
      do {
        puVar9 = local_88 + iVar16;
        iVar16 = iVar16 + 1;
        p_Var11->resistance[0] = *puVar9;
        p_Var11 = (_MONSTER *)((int)&monst->obj + iVar16);
      } while (iVar16 < 10);
      (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
    }
  }
  TaskCurrent->event_enable = 1;
  monst->actionmask = uVar18;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Monster_Action_Flee(struct _MONSTER *monst /*$s5*/, long anim /*$s4*/, long wait /*stack 8*/, long sound /*$fp*/)
 // line 3579, offset 0x80070448
	/* begin block 1 */
		// Start line: 3580
		// Start offset: 0x80070448
		// Variables:
	// 		struct _D3_OBJECT *o; // $s0
	// 		struct M_OBJECT *mo; // $s6
	// 		struct _D3_OBJECT *target; // $s2
	// 		long min; // $s1
	// 		long i; // $s3
	// 		long j; // $s4
	/* end block 1 */
	// End offset: 0x800705D4
	// End Line: 3621

	/* begin block 2 */
		// Start line: 8288
	/* end block 2 */
	// End Line: 8289

void Monster_Action_Flee(_MONSTER *monst,long anim,long wait,long sound)

{
  ushort uVar1;
  uint uVar2;
  _D3_OBJECT *o;
  int iVar3;
  long lVar4;
  int unaff_s3;
  int iVar5;
  int iVar6;
  int iVar7;
  M_OBJECT *obj;
  
  lVar4 = LONG_ARRAY_800b2e68[0];
  o = monst->obj;
  obj = (M_OBJECT *)o->description;
  iVar3 = 0x3c;
  if (LONG_ARRAY_800b2e68[0] != -1) {
    MSensor_AddFear(monst,-100);
    Manim_SetAnim(obj,anim);
    uVar2 = M_rand();
    if ((uVar2 & 7) == 3) {
      D3_PlaySound(o,monst->fleesound);
    }
    uVar2 = M_rand();
    iVar7 = (uVar2 & 0x1f) + 0xf;
    iVar5 = unaff_s3 + 1;
LAB_800704e8:
    do {
      iVar6 = iVar5;
      if ((iVar5 == iVar7) && (uVar2 = M_rand(), iVar6 = iVar5, (uVar2 & 3) == 1)) {
        iVar6 = 0;
        uVar2 = M_rand();
        iVar7 = (uVar2 & 0x1f) + 0xf;
        D3_PlaySound(o,monst->fleesound);
      }
      if ((sound != -1) &&
         ((uVar1 = (obj->Env).Obj.vert_top.pad, (uVar1 & 1) != 0 || ((uVar1 & 2) != 0)))) {
        D3_PlaySound(o,(short)sound);
      }
      if (LONG_ARRAY_800b2e68[0] == -1) {
        lVar4 = Monster_Feelings;
      }
      D3_GoToDir(o,(int)(o->pos).vx - (int)*(short *)(lVar4 + 0x2c),
                 (int)(o->pos).vy - (int)*(short *)(lVar4 + 0x2e),0x50);
      Monster_Adjust(o,monst);
      Task_Next();
      if (iVar3 != 0) {
        iVar3 = iVar3 + -1;
        iVar5 = iVar6 + 1;
        if (iVar3 != 0) goto LAB_800704e8;
      }
      iVar5 = iVar6 + 1;
    } while (LONG_ARRAY_800b2e68[0] != -1);
    Manim_SetAnim(obj,wait);
  }
  return;
}





