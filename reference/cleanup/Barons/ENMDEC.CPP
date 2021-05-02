#include "THISDUST.H"
#include "ENMDEC.H"


// decompiled code
// original method signature: 
// void /*$ra*/ Living_Decor_RobTab_B4(struct _D3_OBJECT *obj /*$a0*/)
 // line 56, offset 0x8007ccf8
	/* begin block 1 */
		// Start line: 57
		// Start offset: 0x8007CCF8
		// Variables:
	// 		short i; // $a3
	// 		short j; // $a2
	// 		short k; // $a1
	// 		short l; // $t0
	/* end block 1 */
	// End offset: 0x8007CD6C
	// End Line: 84

	/* begin block 2 */
		// Start line: 112
	/* end block 2 */
	// End Line: 113

void Living_Decor_RobTab_B4(_D3_OBJECT *obj)

{
  ushort uVar1;
  int iVar2;
  ushort uVar3;
  short in_a1;
  short in_a2;
  int in_a3;
  short in_t0;
  
  uVar1 = (obj->rot).vz;
  uVar3 = uVar1 & 0xfff;
  if ((uVar1 & 0xfff) == 0) {
    in_a1 = 0x7d;
    in_t0 = 0x32;
    in_a2 = 0x32;
    in_a3 = 0;
  }
  if (uVar3 == 0x400) {
    in_a1 = 0x32;
    in_a3 = 0x32;
    in_a2 = 0x7d;
    in_t0 = 0;
  }
  if (uVar3 == 0x800) {
    in_a3 = 0x7d;
    in_a2 = 0x32;
    in_t0 = 0x32;
    in_a1 = 0;
  }
  iVar2 = in_a3 << 0x10;
  if (uVar3 == 0xc00) {
    in_a1 = 0x32;
    in_t0 = 0x7d;
    in_a2 = 0;
    iVar2 = 0x320000;
  }
  D3_SetBox(obj,-(int)in_a1,-(int)in_a2,0x96,iVar2 >> 0x10,(int)in_t0,200);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EB_Living_Decor()
 // line 95, offset 0x8007cdbc
	/* begin block 1 */
		// Start line: 96
		// Start offset: 0x8007CDBC
		// Variables:
	// 		struct ENMDEC_31fake pft4[2]; // stack offset -96
	// 		struct _D3_OBJECT *D3Obj; // $s0
	// 		struct _MONSTER *Monster; // $s1
	// 		long comp; // $s2
	/* end block 1 */
	// End offset: 0x8007D0C0
	// End Line: 189

	/* begin block 2 */
		// Start line: 192
	/* end block 2 */
	// End Line: 193

/* WARNING: Unknown calling convention yet parameter storage is locked */

void EB_Living_Decor(void)

{
  short sVar1;
  short sVar2;
  short sVar3;
  ushort uVar4;
  long lVar5;
  _MONSTER *Monster;
  code *pcVar6;
  undefined *Mask;
  _D3_OBJECT *obj;
  
  obj = (_D3_OBJECT *)TaskCurrent->local;
  if ((obj[1].pos.vy & 0xfU) == 0) {
    Living_Decor_RobTab_B4(obj);
  }
  lVar5 = Pvl_TestStateBits(obj,2);
  if (lVar5 != 0) {
    obj->display_mode = obj->display_mode & 0xffef;
    D3_ClearCollBits(obj,(long)&DAT_00004019);
    lVar5 = Pvl_TestStateBits(obj,0x10);
    if (lVar5 != 0) {
      D3_SetBonuses(obj,1,obj);
    }
    do {
      Task_Next();
    } while( true );
  }
  uVar4 = obj[1].pos.vy;
  Monster = Monster_Main_Init((_D3_OBJECT *)0x0);
  Monster->flags = Monster->flags | 0x10;
  switch((uint)uVar4 & 0xf) {
  case 0:
    Mask = &DAT_80001429;
    Monster->task_action = Living_Decor_RobTab_Task_Action;
    Monster->func_decide = Living_Decor_Robtab_Func_Decisions;
    Monster->func_reflex = Living_Decor_RobTab_Func_Reflex;
    Monster->func_init = Living_Decor_RobTab_Init;
    break;
  case 1:
    Mask = (undefined *)0x90001029;
    Monster->task_action = Living_Decor_CyberBall_Task_Action;
    Monster->func_decide = Living_Decor_CyberBall_Func_Decisions;
    Monster->func_reflex = Living_Decor_CyberBall_Func_Reflex;
    Monster->func_init = Living_Decor_CyberBall_Init;
    Monster->height = -0x23;
    break;
  case 2:
    Mask = (undefined *)0x10001008;
    pcVar6 = Living_Decor_Egnose_Task_Action;
    goto LAB_8007d0ac;
  case 3:
    Mask = (undefined *)0x1000;
    pcVar6 = Living_Decor_Crumble_Task_Action;
    goto LAB_8007d0ac;
  case 4:
    Mask = (undefined *)0x10040028;
    Monster->task_action = Asp_Task_Action;
    Monster->func_decide = (_func_33 *)0x0;
    Monster->func_reflex = Asp_Func_Reflex;
    break;
  case 5:
    Mask = (undefined *)0x10001049;
    Monster->task_action = Living_Decor_Camera_Task_Action;
    Monster->func_reflex = Living_Decor_Camera_Func_Reflex;
    Monster->func_decide = (_func_33 *)0x0;
    Monster->height = -0x1e;
    break;
  case 6:
    Monster_CreateShadow(obj,0xa0);
    sVar1 = (obj->b_box).vx;
    sVar2 = obj->comp_opt3;
    sVar3 = *(short *)&obj->b_step;
    obj[1].pos.pad = 0;
    D3_SetBox(obj,(int)sVar1,(int)sVar2,0,(int)sVar3,(int)(obj->b_box).vy,
              (int)*(short *)&obj[1].prec);
    Mask = (undefined *)0x180fffe1;
    Monster->task_action = Captain_Task_Action;
    Monster->func_decide = (_func_33 *)0x0;
    Monster->func_reflex = Captain_Reflex;
    break;
  case 7:
    Monster_CreateShadow(obj,0xa0);
    if (obj[1].pos.pad == 0) {
      obj[1].pos.pad = 1;
    }
    D3_SetBox(obj,(int)(obj->b_box).vx,(int)obj->comp_opt3,0,(int)*(short *)&obj->b_step,
              (int)(obj->b_box).vy,(int)*(short *)&obj[1].prec);
    Mask = (undefined *)0x180fffe1;
    Monster->task_action = Captain_Task_Action;
    Monster->func_decide = (_func_33 *)0x0;
    Monster->func_reflex = Captain_Reflex;
    break;
  case 8:
    Mask = (undefined *)0x10000000;
    pcVar6 = Dropped_Task_Action;
LAB_8007d0ac:
    Monster->task_action = pcVar6;
    Monster->func_decide = (_func_33 *)0x0;
    Monster->func_reflex = (_func_32 *)0x0;
    break;
  default:
    return;
  }
  Monster_Main_Module(Monster,(ulong)Mask);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Dropped_Task_Action()
 // line 203, offset 0x8007d0d8
	/* begin block 1 */
		// Start line: 204
		// Start offset: 0x8007D0D8
		// Variables:
	// 		struct ENMDEC_8fake col; // stack offset -72
	// 		struct _MONSTER *monst; // $v0
	// 		struct _D3_OBJECT *o; // $s4
	// 		struct _D3_OBJECT (*tests[4]); // stack offset -64
	// 		struct _D3_OBJECT *tmpobj; // $s1
	// 		struct _ZONE *zone; // $v0
	// 		long waiting; // $s3
	// 		long i; // $s2
	// 		long zx; // stack offset -48
	// 		long zy; // stack offset -44
	// 		long zw; // $fp
	// 		long zh; // $s7
	// 		long exz; // $s0
	// 		long stopdrop; // $s5
	// 		long stopdone; // $s6
	// 		long flipflop; // $s1
	// 		long Quake; // $s3
	/* end block 1 */
	// End offset: 0x8007D64C
	// End Line: 353

	/* begin block 2 */
		// Start line: 448
	/* end block 2 */
	// End Line: 449

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Dropped_Task_Action(void)

{
  bool bVar1;
  short sVar2;
  ushort uVar3;
  ushort uVar4;
  bool bVar5;
  _ZONE *p_Var6;
  long lVar7;
  uint uVar8;
  int iVar9;
  long lVar10;
  short sVar11;
  _D3_OBJECT *o;
  char pos;
  _D3_OBJECT **pp_Var12;
  int iVar13;
  int iVar14;
  _D3_OBJECT *o_00;
  int iVar15;
  int iVar16;
  int iVar17;
  _D3_OBJECT *local_40;
  _D3_OBJECT *local_3c;
  _D3_OBJECT *local_38;
  _D3_OBJECT *local_34;
  int local_30;
  int local_2c;
  
  o_00 = ((_D3_OBJECT *)TaskCurrent->local)->next;
  Overlay_UpdateBoss(100);
  p_Var6 = Zone_GetObjectZone(o_00);
  local_30 = (int)p_Var6->x1;
  local_2c = (int)p_Var6->y1;
  iVar17 = (int)p_Var6->x2 - local_30;
  iVar16 = (int)p_Var6->y2 - local_2c;
  D3_SetCollBits(o_00,2);
  D3_ClearCollBits(o_00,0x8000);
  local_40 = o_00->child;
  local_3c = local_40->next;
  local_38 = local_3c->next;
  local_34 = local_38->next;
  do {
    iVar13 = 0;
    bVar5 = false;
    iVar14 = 0;
    pp_Var12 = &local_40;
    do {
      lVar7 = Pvl_TestStateBits(*pp_Var12,2);
      if (lVar7 == 0) {
        bVar5 = true;
      }
      else {
        iVar13 = iVar13 + 0x14;
      }
      iVar14 = iVar14 + 1;
      pp_Var12 = pp_Var12 + 1;
    } while (iVar14 < 4);
    Overlay_UpdateBoss(100 - iVar13);
    Task_Next();
    iVar13 = 0;
  } while (bVar5);
  pp_Var12 = &local_40;
  do {
    o = *pp_Var12;
    pp_Var12 = pp_Var12 + 1;
    iVar13 = iVar13 + 1;
    Pvl_ClearStateBits(o,2);
  } while (iVar13 < 4);
  iVar13 = 8;
  iVar15 = 0xb4;
  bVar5 = true;
  iVar14 = 0x3c;
  Scts_Interruptors = Scts_Interruptors | 0x80004000;
  do {
    if (iVar15 == 0) {
      bVar5 = false;
    }
    else {
      iVar15 = iVar15 + -1;
    }
    if (iVar13 != 0) {
      iVar13 = iVar13 + -1;
    }
    if (((iVar15 != 0) && (iVar13 == 0)) &&
       (o = Monster_GetChild(o_00->father,0x3db), o != (_D3_OBJECT *)0x0)) {
      o[1].pos.vz = 0x6f;
      (o->pos).vz = 0x5dc;
      o[1].pos.pad = 0;
      uVar8 = M_rand();
      if ((uVar8 & 0xf) == 2) {
        D3_PlaySoundCamera(o_00,2);
      }
      iVar9 = (1000 - (int)(o->b_box).vx) - (int)*(short *)&o->b_step;
      if (-1 < iVar9) {
        iVar13 = iVar9 >> 3;
      }
      lVar7 = M_rand();
      lVar10 = M_rand();
      if (iVar13 == 0) {
        trap(0x1c00);
      }
      if ((iVar13 == -1) && (lVar10 == -0x80000000)) {
        trap(0x1800);
      }
      if (iVar13 == 0) {
        trap(0x1c00);
      }
      if ((iVar13 == -1) && (lVar7 == -0x80000000)) {
        trap(0x1800);
      }
      *(int *)&o[1].last_pos = lVar7 % iVar13 + (lVar10 % iVar13) * 0x10000;
      lVar7 = M_rand();
      if (iVar17 == 0) {
        trap(0x1c00);
      }
      if ((iVar17 == -1) && (lVar7 == -0x80000000)) {
        trap(0x1800);
      }
      (o->pos).vx = (short)local_30 + (short)(lVar7 % iVar17);
      lVar7 = M_rand();
      if (iVar16 == 0) {
        trap(0x1c00);
      }
      if ((iVar16 == -1) && (lVar7 == -0x80000000)) {
        trap(0x1800);
      }
      iVar13 = 4;
      (o->pos).vy = (short)local_2c + (short)(lVar7 % iVar16);
    }
    o = o_00->father->child;
    while (o != (_D3_OBJECT *)0x0) {
      if (o[1].pos.vz == 0x6f) {
        sVar2 = (o->pos).vz;
        sVar11 = o[1].pos.pad + -3;
        (o->pos).vz = (o->pos).vz + sVar11;
        uVar4 = o[1].last_pos.vx;
        o[1].pos.pad = sVar11;
        uVar3 = o[1].last_pos.vy;
        bVar5 = true;
        (o->rot).vx = (o->rot).vx + (uVar4 & 0xfff);
        (o->rot).vy = (o->rot).vy + (uVar3 & 0xfff);
        if ((1000 < sVar2) && ((o->pos).vz < 0x3e9)) {
          Impact_Stone((char)o + ',',8);
        }
        if (((((300 < sVar2) && ((o->pos).vz < 0x12d)) &&
             (0x136 < (int)*(short *)&o->b_step - (int)(o->b_box).vx)) &&
            ((-0x32 < (o->pos).vx && (sVar11 = (o->pos).vy, sVar11 < 0xfa)))) && (-0x15e < sVar11))
        {
          o[1].pos.vz = 0x70;
        }
        if ((200 < sVar2) && ((o->pos).vz < 0xc9)) {
          pos = (char)o + ',';
          SFX_ShockWave(2,pos,0xb8,0x1f);
          SFX_ShockWave(3,pos,0xb8,0x1a);
          uVar8 = M_rand();
          if ((uVar8 & 0xf) == 3) {
            D3_PlaySoundCamera(o_00,0);
          }
        }
        if ((o->pos).vz < -1000) {
          o[1].pos.vz = 0x3db;
        }
      }
      o = o->next;
    }
    if (iVar14 == 0x11) {
      D3_PlaySoundCamera(o_00,1);
    }
    bVar1 = iVar14 == 0;
    iVar14 = iVar14 + -1;
    if (bVar1) {
      SFX_ShakeScreen(0x78,0xf);
      iVar14 = 0x3c;
    }
    Task_Next();
  } while (bVar5);
  while (o = Monster_GetChild(o_00->father,0x315), o != (_D3_OBJECT *)0x0) {
    o[1].pos.vz = 0x1234;
    o[1].pos.pad = 0;
    D3_PlaySoundCamera(o_00,2);
    while ((0x1c2 < (o->pos).vz && (((int)o->collision_state & 0xfc00U) == 0))) {
      sVar2 = (o->pos).vz;
      sVar11 = o[1].pos.pad + -4;
      o[1].pos.pad = sVar11;
      (o->pos).vz = sVar2 + sVar11;
      Task_Next();
    }
    D3_PlaySoundCamera(o_00,1);
  }
  do {
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Captain_Sprite()
 // line 387, offset 0x8007d64c
	/* begin block 1 */
		// Start line: 388
		// Start offset: 0x8007D64C
		// Variables:
	// 		struct ENMDEC_31fake p[2]; // stack offset -120
	// 		struct ENMDEC_70fake shp; // stack offset -40
	// 		short i; // $s3
	// 		short flash; // $s2
	/* end block 1 */
	// End offset: 0x8007D820
	// End Line: 435

	/* begin block 2 */
		// Start line: 856
	/* end block 2 */
	// End Line: 857

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Captain_Sprite(void)

{
  _SCREEN *p_Var1;
  SHAPE_31fake *pSVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  SHAPE_31fake SStack120;
  undefined auStack80 [8];
  short local_48;
  short local_46;
  short local_40;
  short local_3e;
  short local_38;
  short local_36;
  short local_30;
  short local_2e;
  SHAPE_68fake local_28;
  
  iVar4 = 0;
  iVar5 = 0;
  local_28.shape = 0x77;
  local_28.x = 100;
  local_28.y = 100;
  local_28.file = Effects_Pcl;
  Shp_SetPolyFT4(&SStack120,&local_28,10,0x14);
  Shp_SetPolyFT4((SHAPE_31fake *)auStack80,&local_28,10,0x14);
  SStack120.x2 = (short)((int)(((int)((uint)(ushort)Scr_W << 0x10) >> 0x10) +
                              (((uint)(ushort)Scr_W << 0x10) >> 0x1f)) >> 1);
  SStack120.x0 = SStack120.x2 + 6;
  SStack120.x2 = SStack120.x2 + -6;
  SStack120.y0 = Scr_H - (short)(((int)Scr_H * 0x17) / 100);
  SStack120.y1 = SStack120.y0 + 5;
  SStack120.y0 = SStack120.y0 + -4;
  SStack120.x1 = SStack120.x0;
  SStack120.y2 = SStack120.y0;
  SStack120.x3 = SStack120.x2;
  SStack120.y3 = SStack120.y1;
  local_48 = SStack120.x0;
  local_46 = SStack120.y0;
  local_40 = SStack120.x0;
  local_3e = SStack120.y1;
  local_38 = SStack120.x2;
  local_36 = SStack120.y0;
  local_30 = SStack120.x2;
  local_2e = SStack120.y1;
  do {
    p_Var1 = Scr;
    iVar4 = iVar4 + 1;
    iVar3 = iVar4 * 0x10000 >> 0x10;
    if (3 < iVar3) {
      pSVar2 = &SStack120 + (int)Scr_Frame;
      pSVar2->tag = pSVar2->tag & 0xff000000 | Scr->ot[3] & 0xffffff;
      p_Var1->ot[3] = p_Var1->ot[3] & 0xff000000 | (uint)pSVar2 & 0xffffff;
    }
    if (iVar3 == 0xc) {
      iVar4 = 0;
    }
    Task_Next();
    iVar5 = iVar5 + 1;
  } while (iVar5 * 0x10000 >> 0x10 < 900);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Captain_Reflex()
 // line 438, offset 0x8007d840
	/* begin block 1 */
		// Start line: 439
		// Start offset: 0x8007D840
		// Variables:
	// 		struct _MONSTER *monst; // $s2
	// 		struct _D3_OBJECT *o; // $s0
	// 		struct _D3_OBJECT *target; // $s3
	// 		long distance; // $s1
	// 		long tmp; // $v1
	/* end block 1 */
	// End offset: 0x8007DAA8
	// End Line: 491

	/* begin block 2 */
		// Start line: 1177
	/* end block 2 */
	// End Line: 1178

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Captain_Reflex(void)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  int iVar5;
  _D3_OBJECT *o;
  _MONSTER *monst;
  
  lVar1 = Monster_Feelings;
  monst = (_MONSTER *)TaskCurrent->local;
  o = monst->obj;
  if (((Pvl_SctState[(int)o->index] & 8U) == 0) && (o[1].pos.pad != 0)) {
    D3_GoToDir(o,(int)*(short *)(Monster_Feelings + 0x2c) - (int)(o->pos).vx,
               (int)*(short *)(Monster_Feelings + 0x2e) - (int)(o->pos).vy,0x14);
    uVar2 = Direction((int)*(short *)(lVar1 + 0x2c) - (int)(o->pos).vx,
                      (int)*(short *)(lVar1 + 0x2e) - (int)(o->pos).vy);
    if (o->father == (_D3_OBJECT *)0x0) {
      iVar3 = rcos(uVar2);
      (o->child->pos).vx = (o->pos).vx + (short)(iVar3 * 100 >> 0xc);
      iVar3 = rsin(uVar2);
      (o->child->pos).vy = (o->pos).vy + (short)(iVar3 * 100 >> 0xc);
    }
  }
  if ((Pvl_Trig0 & 0x4000) != 0) {
    monst->counter = 0;
  }
  lVar4 = Distance2D((int)(o->pos).vx,(int)(o->pos).vy,(int)*(short *)(lVar1 + 0x2c),
                     (int)*(short *)(lVar1 + 0x2e));
  iVar3 = 200;
  if (o[1].pos.pad != 0) {
    iVar3 = 300;
  }
  if ((lVar4 < iVar3) && (monst->timer == 0)) {
    iVar5 = (int)(o->pos).vz;
    if (((int)*(short *)(lVar1 + 0x30) + -100 < iVar5) &&
       (iVar5 < (int)*(short *)(lVar1 + 0x30) + 100)) {
      Monster_StopAllActions(monst);
      Monster_AddAction(monst,0,0xe,0,0);
      monst->timer = 1;
      goto LAB_8007da54;
    }
  }
  if ((iVar3 + 100 < lVar4) && (monst->action != 2)) {
    monst->guninfo2 = 1;
    monst->timer = 0;
    Monster_StopAllActions(monst);
    Monster_AddAction(monst,0,1,0,0);
  }
LAB_8007da54:
  if ((LONG_ARRAY_800b2e48[0] != -1) && (o[1].pos.pad == 0)) {
    o->collision_state = o->collision_state & 0xfffd;
    Monster_StopAllActions(monst);
    Monster_AddAction(monst,0,2,0,0);
    monst->guninfo2 = 0;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Captain_GameOver(struct _D3_OBJECT *o /*$s1*/, struct M_OBJECT *mo /*$s3*/, short *SpeechTab /*$a2*/)
 // line 515, offset 0x8007dac4
	/* begin block 1 */
		// Start line: 516
		// Start offset: 0x8007DAC4
		// Variables:
	// 		struct _D3_OBJECT *target; // $s2
	// 		struct M_OBJECT *moch; // $s4
	// 		long i; // $s0
	/* end block 1 */
	// End offset: 0x8007DCD0
	// End Line: 559

	/* begin block 2 */
		// Start line: 1335
	/* end block 2 */
	// End Line: 1336

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Captain_GameOver(_D3_OBJECT *o,M_OBJECT *mo,short *SpeechTab)

{
  long lVar1;
  int iVar2;
  void *Param;
  
  lVar1 = Monster_Feelings;
  Param = o->child->description;
  if (o->father == (_D3_OBJECT *)0x0) {
    o->display_mode = o->display_mode & 0xffef;
    D3_ClearCollBits(o,(long)&DAT_00004019);
    do {
      Task_Next();
    } while( true );
  }
  Task_Next();
  while (((300 < LONG_ARRAY_800b2e40[0] || (LONG_ARRAY_800b2e40[0] == -1)) ||
         (LONG_ARRAY_800b2e40[0] == 0))) {
    D3_GoToDir(o,(int)*(short *)(lVar1 + 0x2c) - (int)(o->pos).vx,
               (int)*(short *)(lVar1 + 0x2e) - (int)(o->pos).vy,0x14);
    if (LONG_ARRAY_800b2e48[0] != -1) {
      Manim_SetAnim(mo,0);
      Sky.volume = 1;
      D3_PlaySoundCamera(o,6);
      Text_DisplayLine((char *)Pvl_Texts[(int)*(short *)((int)&o[1].prec + 2)],4,0x32,(long *)0x0);
      Manim_SetAnim(mo,2);
    }
    Task_Next();
  }
  _DAT_800b1d58 = 1;
  Manim_SetAnim(mo,0);
  iVar2 = 0;
  D3_PlaySoundCamera(o->child,0);
  Text_DisplayLine((char *)Pvl_Texts[(int)*(short *)((int)&o->child[1].prec + 2)],0,0x3c,(long *)0x0
                  );
  Text_DisplayLine((char *)Pvl_Texts[(int)*(short *)((int)&o->child[1].prec + 2)],1,0x3c,(long *)0x0
                  );
  Manim_SetAnim(mo,2);
  do {
    iVar2 = iVar2 + 1;
    Task_Next();
  } while (iVar2 < 0x1e);
  Pl_ForceAction((_PLAYER *)&Player,0x201,(long)Param);
  do {
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Captain_Task_Action()
 // line 562, offset 0x8007dcd0
	/* begin block 1 */
		// Start line: 563
		// Start offset: 0x8007DCD0
		// Variables:
	// 		struct ENMDEC_104fake t; // stack offset -112
	// 		struct TASK *task; // stack offset -64
	// 		struct _MONSTER *monst; // $s4
	// 		struct _D3_OBJECT *o; // $s2
	// 		struct _D3_OBJECT *target; // stack offset -60
	// 		struct M_OBJECT *mo; // $s6
	// 		struct _ZONE *zone; // $v0
	// 		short specialaction; // stack offset -56
	// 		short *SpeechTab; // $s5
	// 		short customzone[6]; // stack offset -80
	// 		long i; // $s1
	// 		long j; // $s0
	// 		long k; // $s3
	// 		long handle; // stack offset -48
	// 		long gas; // $s0
	/* end block 1 */
	// End offset: 0x8007EB24
	// End Line: 941

	/* begin block 2 */
		// Start line: 1441
	/* end block 2 */
	// End Line: 1442

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Captain_Task_Action(void)

{
  short *psVar1;
  byte bVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  bool bVar8;
  TASK *pTVar9;
  short sVar10;
  long index;
  _ENEMYZONE *p_Var11;
  _ZONE *t;
  char *src;
  long *info;
  undefined4 uVar12;
  int iVar13;
  short *psVar14;
  int index_00;
  _D3_OBJECT *o;
  _MONSTER *monst;
  short *SpeechTab;
  M_OBJECT *mo;
  undefined auStack112 [32];
  short local_50;
  short local_4e;
  short local_4c;
  short local_4a;
  short local_48;
  short local_46;
  TASK *local_40;
  long local_3c;
  short local_38;
  int local_30;
  
  monst = (_MONSTER *)TaskCurrent->local;
  local_38 = 0;
  o = monst->obj;
  local_3c = Monster_Feelings;
  mo = (M_OBJECT *)o->description;
  if (o->father != (_D3_OBJECT *)0x0) {
    o->child->display_mode = o->child->display_mode & 0xffbf;
  }
  Text_SetContext((TEXT_102fake *)auStack112);
  bVar8 = false;
  Text_SetContextFont(0x70);
  Text_SetContextXY(0,0);
  Text_SetContextWH(0x140,0xf0);
  Text_SetContextRange(0);
  Text_SetContextMode(0);
  if (Pvl_Difficulty == 1) {
    sVar10 = Invent_GetNbObjects(0x1b,0);
    bVar8 = sVar10 < 0x1e;
LAB_8007de18:
    bVar8 = !bVar8;
  }
  else {
    if (Pvl_Difficulty < 2) {
      if (Pvl_Difficulty == 0) {
        sVar10 = Invent_GetNbObjects(0x1b,0);
        bVar8 = sVar10 < 0x14;
        goto LAB_8007de18;
      }
    }
    else {
      if (Pvl_Difficulty == 2) {
        sVar10 = Invent_GetNbObjects(0x1b,0);
        bVar8 = sVar10 < 0x28;
        goto LAB_8007de18;
      }
    }
  }
  Capitain_Speech0 = 1;
  SHORT_ARRAY_800ad8b6[0] = 9;
  SHORT_800ad8bc = 9;
  SHORT_ARRAY_800ad8be[0] = 10;
  local_30 = -1;
  Capitain_Speech1 = 0;
  SHORT_ARRAY_800ad8de[0] = 6;
  SHORT_800ad8e4 = 6;
  SHORT_ARRAY_800ad8e6[0] = 7;
  Capitain_Speech2 = 0;
  SHORT_ARRAY_800ad906[0] = 6;
  SHORT_800ad90c = 6;
  SHORT_ARRAY_800ad90e[0] = 7;
  monst->guninfo1 = 0;
  monst->guninfo2 = 0;
  if (o[1].pos.pad == 0) {
    sVar10 = o[1].pos.vz;
    if (sVar10 == 1) {
      SpeechTab = &Capitain_Speech1;
LAB_8007dee4:
      if (!bVar8) {
        Captain_GameOver(o,mo,SpeechTab);
      }
    }
    else {
      if (sVar10 < 2) {
        if (sVar10 == 0) {
          SpeechTab = &Capitain_Speech0;
        }
      }
      else {
        if (sVar10 == 2) {
          SpeechTab = &Capitain_Speech2;
          goto LAB_8007dee4;
        }
      }
    }
    if (o[1].pos.vz != 0) {
      if (o->father != (_D3_OBJECT *)0x0) {
        if (((uint)(ushort)Pvl_Difficulty - 1 < 2) && ((Scts_Interruptors & 0x20000000U) != 0)) {
          o->display_mode = o->display_mode & 0xffef;
          D3_ClearCollBits(o,(long)&DAT_00004019);
          do {
            Task_Next();
          } while( true );
        }
        monst->guninfo1 = 1;
      }
      if ((o[1].pos.vz != 0) && (o->father == (_D3_OBJECT *)0x0)) {
        if (((Scts_Interruptors & 0x20000000U) == 0) || (1 < (uint)(ushort)Pvl_Difficulty - 1)) {
          o->display_mode = o->display_mode & 0xffef;
          D3_ClearCollBits(o,(long)&DAT_00004019);
          do {
            Task_Next();
          } while( true );
        }
        monst->guninfo1 = 0x10;
      }
    }
    if (o[1].pos.pad == 0) goto LAB_8007e048;
  }
  if (Pvl_PlayerNumber == o[1].pos.vz) {
    o->display_mode = o->display_mode & 0xffef;
    D3_ClearCollBits(o,(long)&DAT_00004019);
    do {
      Task_Next();
    } while( true );
  }
LAB_8007e048:
  monst->monster_speed = 0x20;
  Pri_Get_CustomZones(monst,&local_50);
  local_40 = (TASK *)0x0;
  index = Task_EventWait();
  pTVar9 = TaskCurrent;
  monst->action = (short)index;
  pTVar9->event_enable = 1;
  _DAT_800b1d58 = 0;
  if ((monst->guninfo1 == 0xf) || (monst->guninfo1 == 0xf0)) {
    pTVar9->event_enable = 0;
    monst->sensormask = 0;
    monst->func_reflex = (_func_32 *)0x0;
    if (monst->guninfo1 == 0xf0) {
      Task_Sleep(0x5a);
      Invent_RemoveUsedKey(0x20000000,0);
      Scts_Interruptors = Scts_Interruptors | 0x40000000;
    }
    p_Var11 = Pvl_EnemyZones + (int)monst->zone_fear;
    sVar10 = p_Var11->x1;
    sVar3 = p_Var11->x2;
    sVar4 = p_Var11->y2;
    sVar5 = p_Var11->y1;
    sVar6 = p_Var11->z1;
    sVar7 = p_Var11->z2;
    while (index = Monster_Action_MoveTo
                             ((int)sVar10 + (int)sVar3 >> 1,(int)sVar5 + (int)sVar4 >> 1,
                              (int)sVar6 + (int)sVar7 >> 1,(_D3_OBJECT *)0x0,100,-1,3,-1,-1,-1,8),
          index == 0) {
      Task_Next();
    }
    index_00 = 0;
    (o->pos).vy = (o->pos).vy + 0x28;
    (o->pos).vx = (o->pos).vx + -0xf;
    uVar12 = *(undefined4 *)&(o->pos).vz;
    *(undefined4 *)&o->last_pos = *(undefined4 *)&o->pos;
    *(undefined4 *)&(o->last_pos).vz = uVar12;
    (o->rot).vz = 0x400;
    Manim_SetAnim(mo,4);
    Manim_WaitAnim(mo);
    do {
      Manim_SetAnim(mo,5);
      Manim_WaitAnim(mo);
      index_00 = index_00 + 1;
    } while (index_00 < 6);
    D3_ClearCollBits(o,(long)&DAT_00004019);
    if (monst->guninfo1 == 0xf) {
      Pl_ForceAction((_PLAYER *)&Player,0x101,0);
    }
    index_00 = 0;
    do {
      Manim_SetAnim(mo,5);
      Manim_WaitAnim(mo);
      index_00 = index_00 + 1;
    } while (index_00 < 6);
    (mo->Env).Obj.normal_top.vx = (mo->Env).Obj.normal_top.vx & 0xfffe;
    do {
      Task_Next();
    } while( true );
  }
  do {
    sVar10 = monst->action;
    if (sVar10 == 2) {
      Manim_SetAnim(mo,0);
      Sky.volume = 1;
      index_00 = (int)SpeechTab[4];
      if (index_00 < (int)SpeechTab[5]) {
        psVar14 = SpeechTab + index_00;
        do {
          if (monst->guninfo2 != 0) break;
          if ((psVar14[8] & 0xff00U) != 0) {
            D3_PlaySound(o,(psVar14[8] >> 8) + -1);
          }
          psVar1 = psVar14 + 8;
          psVar14 = psVar14 + 1;
          Text_DisplayLine((char *)Pvl_Texts[(int)*(short *)((int)&o[1].prec + 2)],index_00,
                           (uint)*(byte *)psVar1,(long *)0x0);
          index_00 = index_00 + 1;
        } while (index_00 < (int)SpeechTab[5]);
      }
      Manim_SetAnim(mo,2);
      monst->actionmask = 0;
      monst->busy = -1;
      Task_Next();
      Monster_ForceAction(monst,1,0);
    }
    else {
      if (sVar10 < 3) {
        if (sVar10 == 1) {
          monst->busy = 0;
          monst->mode = 0x10;
          if ((Pvl_SctState[(int)o->index] & 8U) == 0) {
            index = 2;
            if (o[1].pos.vz == 0x32) {
              index = 0;
            }
            Manim_SetAnim(mo,index);
            sVar10 = (o->pos).vx;
            sVar3 = (o->pos).vy;
            do {
              Manim_WaitAnim(mo);
              (o->pos).vx = sVar10;
              (o->pos).vy = sVar3;
              Task_Next();
            } while( true );
          }
          while (index = Monster_Action_MoveTo
                                   ((int)local_50,(int)local_4e,(int)local_4c,(_D3_OBJECT *)0x0,100,
                                    -1,3,-1,-1,-1,-2), index == 0) {
            Task_Next();
          }
          monst->mode = 0x10;
          if (*(short *)((int)&o[1].father + 2) != -1) {
            index = M_rand();
            D3_PlaySound(o,((ushort)index & 3) + 9);
          }
          Manim_SetAnim(mo,2);
          Manim_WaitAnim(mo);
          while (index = Monster_Action_MoveTo
                                   ((int)local_4a,(int)local_48,(int)local_46,(_D3_OBJECT *)0x0,100,
                                    -1,3,-1,-1,-1,-2), index == 0) {
            Task_Next();
          }
          monst->mode = 0x10;
          if (*(short *)((int)&o[1].father + 2) != -1) {
            index = M_rand();
            D3_PlaySound(o,((ushort)index & 3) + 9);
          }
          Manim_SetAnim(mo,2);
          Manim_WaitAnim(mo);
        }
      }
      else {
        if (sVar10 == 0xe) {
          local_38 = 1;
          if (o[1].pos.pad == 0) {
            monst->guninfo2 = 0;
            Manim_SetAnim(mo,0);
            Sky.volume = 1;
            local_40 = (TASK *)0x0;
            if ((Pvl_SctState[(int)o->index] & 8U) == 0) {
              local_40 = Task_Add(Captain_Sprite,0x200);
              t = Zone_GetObjectZone(o);
              if (t != (_ZONE *)0x0) {
                Track_SetMode(10,(long)t);
              }
              _DAT_800b1d58 = 1;
            }
            while (index = D3_GoToDir(o,(int)*(short *)(local_3c + 0x2c) - (int)(o->pos).vx,
                                      (int)*(short *)(local_3c + 0x2e) - (int)(o->pos).vy,
                                      (int)monst->monster_speed), index != 0) {
              Task_Next();
            }
            if (monst->guninfo2 == 0) {
              index_00 = (int)*SpeechTab;
              if (index_00 < (int)SpeechTab[1]) {
                psVar14 = SpeechTab + index_00;
                do {
                  if (monst->guninfo2 != 0) break;
                  TaskCurrent->event_enable = 0;
                  if (((int)psVar14[8] & 0xff00U) != 0) {
                    if (-1 < local_30) {
                      Sound_Stop(local_30,1);
                    }
                    sVar10 = D3_PlaySound(o,(psVar14[8] >> 8) + -1);
                    local_30 = (int)sVar10;
                  }
                  monst->counter = 1;
                  if ((Pvl_SctState[(int)o->index] & 8U) == 0) {
                    bVar2 = *(byte *)(psVar14 + 8);
                    src = (char *)Pvl_Texts[(int)*(short *)((int)&o[1].prec + 2)];
                    info = &monst->counter;
                  }
                  else {
                    bVar2 = *(byte *)(psVar14 + 8);
                    src = (char *)Pvl_Texts[(int)*(short *)((int)&o[1].prec + 2)];
                    info = (long *)0x0;
                  }
                  psVar14 = psVar14 + 1;
                  Text_DisplayLine(src,index_00,(uint)bVar2,info);
                  TaskCurrent->event_enable = 1;
                  index_00 = index_00 + 1;
                } while (index_00 < (int)SpeechTab[1]);
              }
              *SpeechTab = SpeechTab[2];
              SpeechTab[1] = SpeechTab[3];
              SpeechTab[4] = SpeechTab[6];
              SpeechTab[5] = SpeechTab[7];
              if (monst->guninfo2 == 0) {
                Manim_SetAnim(mo,2);
              }
            }
            Invent_RemoveUsedObject(0x1b,1,2);
            if ((monst->guninfo1 & 0xfU) != 0) {
              monst->guninfo1 = 0xf;
            }
            if ((monst->guninfo1 & 0xf0U) != 0) {
              monst->guninfo1 = 0xf0;
            }
          }
          else {
            if ((Pvl_SctState[(int)o->index] & 8U) == 0) {
              Manim_SetAnim(mo,0);
              t = Zone_GetObjectZone(o);
              if (t != (_ZONE *)0x0) {
                Track_SetMode(10,(long)t);
              }
              TaskCurrent->event_enable = 0;
              _DAT_800b1d58 = local_38;
              if (o[1].pos.vz == 0x32) {
                local_40 = Task_Add(Captain_Sprite,0x200);
                sVar10 = Text_AmountOfTexts((char *)Pvl_Texts[(int)*(short *)((int)&o[1].prec + 2)])
                ;
                index_00 = 3;
                if (3 < (int)sVar10) {
                  do {
                    index = M_rand();
                    D3_PlaySound(o,(ushort)index & 3);
                    iVar13 = index_00 + 1;
                    monst->counter = 1;
                    Text_DisplayLine((char *)Pvl_Texts[(int)*(short *)((int)&o[1].prec + 2)],
                                     index_00,(int)o[1].pos.pad * 0x1e,&monst->counter);
                    index_00 = iVar13;
                  } while (iVar13 < (int)sVar10);
                }
                if (local_40 != (TASK *)0x0) {
                  Task_Kill(local_40);
                  local_40 = (TASK *)0x0;
                }
                D3_PlaySound(o,3);
                if (Pvl_Difficulty == 1) {
                  monst->counter = 1;
                  Text_DisplayLine((char *)Pvl_Texts[(int)*(short *)((int)&o[1].prec + 2)],1,
                                   (int)o[1].pos.pad * 0x1e,&monst->counter);
                }
                else {
                  if (Pvl_Difficulty < 2) {
                    if (Pvl_Difficulty == 0) {
                      index = 0;
                      monst->counter = 1;
                      sVar10 = *(short *)((int)&o[1].prec + 2);
LAB_8007e72c:
                      Text_DisplayLine((char *)Pvl_Texts[(int)sVar10],index,(int)o[1].pos.pad * 0x1e
                                       ,&monst->counter);
                    }
                  }
                  else {
                    if (Pvl_Difficulty == 2) {
                      index = 2;
                      monst->counter = 1;
                      sVar10 = *(short *)((int)&o[1].prec + 2);
                      goto LAB_8007e72c;
                    }
                  }
                }
              }
              else {
                index_00 = 0;
                sVar10 = Text_AmountOfTexts((char *)Pvl_Texts[(int)*(short *)((int)&o[1].prec + 2)])
                ;
                iVar13 = (int)sVar10;
                if (0 < iVar13) {
                  do {
                    monst->counter = 1;
                    if (iVar13 == 1) {
                      info = (long *)0x0;
                    }
                    else {
                      info = &monst->counter;
                    }
                    Text_DisplayLine((char *)Pvl_Texts[(int)*(short *)((int)&o[1].prec + 2)],
                                     index_00,(int)o[1].pos.pad * 0x1e,info);
                    index_00 = index_00 + 1;
                  } while (index_00 < iVar13);
                }
              }
              D3_SetBonuses(o,1,o);
              Fx_Play(0x3e,(char)o + ',');
              TaskCurrent->event_enable = 1;
            }
          }
        }
      }
    }
    if (local_38 != 0) {
      Sky.volume = 2;
      if ((Pvl_SctState[(int)o->index] & 8U) == 0) {
        if (local_40 != (TASK *)0x0) {
          Task_Kill(local_40);
          local_40 = (TASK *)0x0;
        }
        Track_SetMode(2,0);
      }
      local_38 = 0;
      Pvl_SctState[(int)o->index] = Pvl_SctState[(int)o->index] | 8;
    }
    monst->actionmask = 0;
    monst->busy = -1;
    Task_Next();
    Monster_ForceAction(monst,1,0);
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Living_Decor_RobTab_Init()
 // line 965, offset 0x8007eb24
	/* begin block 1 */
		// Start line: 967
		// Start offset: 0x8007EB24
		// Variables:
	// 		struct _MONSTER *mo; // $v1
	/* end block 1 */
	// End offset: 0x8007EB24
	// End Line: 967

	/* begin block 2 */
		// Start line: 2352
	/* end block 2 */
	// End Line: 2353

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Living_Decor_RobTab_Init(void)

{
  void *pvVar1;
  
  pvVar1 = TaskCurrent->local;
  *(undefined2 *)((int)pvVar1 + 0xec) = 0xb4;
  *(undefined2 *)((int)pvVar1 + 0xee) = 0xff9c;
  *(undefined2 *)((int)pvVar1 + 0xf0) = 0xb4;
  *(undefined2 *)((int)pvVar1 + 0xf2) = 0;
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ GetShoulder(struct _MONSTER *monst /*$a0*/, struct ENMDEC_7fake *vec /*$s2*/)
 // line 976, offset 0x8007eb4c
	/* begin block 1 */
		// Start line: 977
		// Start offset: 0x8007EB4C
		// Variables:
	// 		struct _D3_OBJECT *o; // $s1
	// 		struct _D3_OBJECT *target; // $s3
	// 		long tmp; // $v1
	/* end block 1 */
	// End offset: 0x8007EB4C
	// End Line: 977

	/* begin block 2 */
		// Start line: 2377
	/* end block 2 */
	// End Line: 2378

short GetShoulder(_MONSTER *monst,undefined vec)

{
  int iVar1;
  int iVar2;
  long lVar3;
  undefined3 in_register_00000015;
  short *psVar4;
  _D3_OBJECT *p_Var5;
  
  lVar3 = Monster_Feelings;
  psVar4 = (short *)CONCAT31(in_register_00000015,vec);
  p_Var5 = monst->obj;
  psVar4[2] = (p_Var5->pos).vz;
  iVar1 = rcos((int)(p_Var5->rot).vz);
  iVar2 = rsin((int)(p_Var5->rot).vz);
  *psVar4 = (p_Var5->pos).vx + (short)(iVar2 * 0x4a + iVar1 * -0x25 >> 0xc);
  iVar1 = rsin((int)(p_Var5->rot).vz);
  iVar2 = rcos((int)(p_Var5->rot).vz);
  iVar1 = (uint)(ushort)(p_Var5->pos).vy + (iVar2 * -0x46 + iVar1 * -0x25 >> 0xc);
  psVar4[1] = (short)iVar1;
  lVar3 = Direction((int)*(short *)(lVar3 + 0x2c) - (int)*psVar4,
                    (int)*(short *)(lVar3 + 0x2e) - (iVar1 * 0x10000 >> 0x10));
  return (short)lVar3;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Living_Decor_Bullet_Create(struct _D3_OBJECT *target /*$s0*/)
 // line 993, offset 0x8007ec64
	/* begin block 1 */
		// Start line: 994
		// Start offset: 0x8007EC64
		// Variables:
	// 		struct _MONSTER *monst; // $a0
	// 		struct _D3_OBJECT *o; // $s1
	// 		struct ENMDEC_7fake pos; // stack offset -40
	// 		struct ENMDEC_7fake rot; // stack offset -32
	// 		struct ENMDEC_8fake color; // stack offset -24
	/* end block 1 */
	// End offset: 0x8007EC64
	// End Line: 994

	/* begin block 2 */
		// Start line: 2421
	/* end block 2 */
	// End Line: 2422

void Living_Decor_Bullet_Create(_D3_OBJECT *target)

{
  short sVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  _MONSTER *monst;
  _D3_OBJECT *o;
  short local_28;
  ushort local_26;
  short local_24;
  
  monst = (_MONSTER *)TaskCurrent->local;
  o = monst->obj;
  pvVar4 = o->description;
  *(ushort *)((int)pvVar4 + 0x28) = *(ushort *)((int)pvVar4 + 0x28) & 0xfffe;
  sVar1 = GetShoulder(monst,0xd8);
  iVar2 = rcos((int)sVar1);
  iVar3 = rsin((int)sVar1);
  DirectionZ((int)(target->pos).vx - (int)(short)(local_28 + (short)(iVar2 * 0xb4 >> 0xc)),
             (int)(target->pos).vy -
             ((int)(((uint)local_26 + (iVar3 * 0xb4 >> 0xc)) * 0x10000) >> 0x10),
             ((int)(target->pos).vz - (int)(short)(local_24 + 0xe1)) +
             ((int)*(short *)&target[1].prec - (int)(target->b_box).vz >> 1));
  Impact_Sparks(0xd8,2);
  Laser_Add(0xd8,0xe0,o,0xe8);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Living_Decor_RobTab_Func_Reflex()
 // line 1022, offset 0x8007edb4
	/* begin block 1 */
		// Start line: 1023
		// Start offset: 0x8007EDB4
		// Variables:
	// 		struct ENMDEC_7fake pos; // stack offset -24
	// 		struct _MONSTER *monst; // $s0
	// 		struct M_OBJECT *mo; // $s1
	/* end block 1 */
	// End offset: 0x8007EE4C
	// End Line: 1040

	/* begin block 2 */
		// Start line: 2498
	/* end block 2 */
	// End Line: 2499

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Living_Decor_RobTab_Func_Reflex(void)

{
  short sVar1;
  ushort uVar2;
  _MONSTER *monst;
  void *pvVar3;
  
  monst = (_MONSTER *)TaskCurrent->local;
  pvVar3 = monst->obj->description;
  if (((2 < LONG_ARRAY_800b2e2c[0] + 3U) && ((monst->flags & 0x20U) != 0)) && (monst->mode != 0xc))
  {
    *(ushort *)((int)pvVar3 + 0x28) = *(ushort *)((int)pvVar3 + 0x28) | 4;
    sVar1 = GetShoulder(monst,0xe8);
    uVar2 = ((monst->obj->rot).vz + 0xc00) - sVar1 & 0xfff;
    (monst->eff_pos).pad = uVar2;
    *(ushort *)((int)pvVar3 + 0x26) = uVar2;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Living_Decor_Robtab_Func_Decisions()
 // line 1043, offset 0x8007ee60
	/* begin block 1 */
		// Start line: 1044
		// Start offset: 0x8007EE60
		// Variables:
	// 		struct _MONSTER *mo; // $s0
	/* end block 1 */
	// End offset: 0x8007EFB4
	// End Line: 1086

	/* begin block 2 */
		// Start line: 2558
	/* end block 2 */
	// End Line: 2559

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Living_Decor_Robtab_Func_Decisions(void)

{
  long action;
  long param1;
  _MONSTER *monst;
  
  monst = (_MONSTER *)TaskCurrent->local;
  if (LONG_ARRAY_800b2e40[0] < 200) {
    if ((monst->flags & 0x20U) == 0) {
      return;
    }
    monst->flags = monst->flags & 0xffdf;
    Monster_StopAllActions(monst);
    action = 0x10;
    param1 = 0;
  }
  else {
    if ((LONG_ARRAY_800b2e2c[0] + 3U < 3) || ((monst->flags & 0x20U) != 0)) {
      if ((LONG_ARRAY_800b2e2c[0] == -1) && ((monst->flags & 0x20U) != 0)) {
        monst->flags = monst->flags & 0xffdf;
        Monster_StopAllActions(monst);
        Monster_AddAction(monst,0,0x10,0,0);
      }
      if (LONG_ARRAY_800b2e2c[0] + 3U < 3) {
        return;
      }
      Monster_StopAllActions(monst);
      Monster_AddAction(monst,0,0xc,0,0);
      param1 = (long)monst->obj[1].pos.vz;
      action = 0xf;
    }
    else {
      monst->flags = monst->flags | 0x20;
      Monster_StopAllActions(monst);
      action = 0xe;
      param1 = 0;
    }
  }
  Monster_AddAction(monst,0,action,param1,0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Living_Decor_RobTab_Task_Action()
 // line 1089, offset 0x8007efc4
	/* begin block 1 */
		// Start line: 1090
		// Start offset: 0x8007EFC4
		// Variables:
	// 		struct _MONSTER *monst; // $s2
	// 		struct _D3_OBJECT *o; // $s3
	// 		struct M_OBJECT *mo; // $s1
	// 		long i; // $s0
	/* end block 1 */
	// End offset: 0x8007F28C
	// End Line: 1162

	/* begin block 2 */
		// Start line: 2654
	/* end block 2 */
	// End Line: 2655

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Living_Decor_RobTab_Task_Action(void)

{
  TASK *pTVar1;
  long Anim;
  int iVar2;
  M_OBJECT *obj;
  _MONSTER *monst;
  _D3_OBJECT *o;
  
  monst = (_MONSTER *)TaskCurrent->local;
  o = monst->obj;
  obj = (M_OBJECT *)o->description;
  monst->hurtsound = 1;
  Anim = Task_EventWait();
  pTVar1 = TaskCurrent;
  monst->action = (short)Anim;
  pTVar1->event_enable = 1;
  do {
    pTVar1 = TaskCurrent;
    switch((int)(((uint)(ushort)monst->action - 1) * 0x10000) >> 0x10) {
    case 0:
      monst->busy = 0;
      monst->mode = 0x10;
      (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
      do {
        Task_Next();
      } while( true );
    case 1:
      if (LONG_800b2e24 == -1) break;
      if ((Monster_Feelings != 0) && ((*(ushort *)(Monster_Feelings + 0x1c) & 0x1000) != 0)) {
        Pl_AddExperience((_PLAYER *)Monster_Feelings,o);
      }
      monst->mode = 0x11;
      D3_ClearCollBits(o,(long)&DAT_00004011);
      o->display_mode = o->display_mode & 0xffef;
      SFX_AddExplosion(o,0,0);
      D3_PlaySound(o,0);
      monst->actionmask = 0;
      goto LAB_8007f258;
    case 0xb:
      D3_PlaySound(o,2);
      Living_Decor_Bullet_Create((_D3_OBJECT *)Monster_Feelings);
      Anim = 3;
      goto LAB_8007f1a8;
    case 0xd:
      monst->mode = 0xc;
      D3_PlaySound(o,3);
      Manim_SetAnim(obj,0);
      Manim_WaitAnim(obj);
      Anim = 1;
      monst->mode = 0x10;
LAB_8007f1a8:
      Manim_SetAnim(obj,Anim);
      (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx | 4;
      *(short *)((int)&(obj->Env).Obj.n_vert + 2) = (monst->eff_pos).pad;
      Manim_WaitAnim(obj);
LAB_8007f1d0:
      (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
      break;
    case 0xe:
      (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
      iVar2 = 0;
      if (0 < pTVar1->event_param) {
        do {
          iVar2 = iVar2 + 1;
          Task_Next();
        } while (iVar2 < TaskCurrent->event_param);
        monst->actionmask = 0;
        goto LAB_8007f258;
      }
      break;
    case 0xf:
      D3_PlaySound(o,3);
      Monster_Action_RunAnimationSpeed(2,0x10,0x80,0,-1);
      goto LAB_8007f1d0;
    case 0x1e:
      MSpell_SpellTesting(monst,TaskCurrent->event_param,-1,-1);
    }
    monst->actionmask = 0;
LAB_8007f258:
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
// void /*$ra*/ Living_Decor_CyberBall_Init()
 // line 1184, offset 0x8007f2bc
	/* begin block 1 */
		// Start line: 1185
		// Start offset: 0x8007F2BC
		// Variables:
	// 		struct _MONSTER *monst; // $s0
	/* end block 1 */
	// End offset: 0x8007F2BC
	// End Line: 1185

	/* begin block 2 */
		// Start line: 2875
	/* end block 2 */
	// End Line: 2876

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Living_Decor_CyberBall_Init(void)

{
  int iVar1;
  _D3_OBJECT *p_Var2;
  _D3_OBJECT *p_Var3;
  
  p_Var3 = (_D3_OBJECT *)TaskCurrent->local;
  D3_ClearCollBits(p_Var3->next,4);
  D3_SetCollBits(p_Var3->next,10);
  *(undefined *)((int)(p_Var3->next + 1) + 0x2d) = 0xf6;
  p_Var2 = p_Var3->next;
  *(undefined2 *)((int)(p_Var3 + 2) + 0x58) = 2;
  *(short *)((int)(p_Var3 + 2) + 0x1a) = 0;
  iVar1 = rcos((int)*(short *)((int)&p_Var2->rot + 4));
  p_Var2 = p_Var3->next;
  *(short *)((int)(p_Var3 + 2) + 0x14) = (p_Var3->next->pos).vx + (short)(iVar1 * 100 >> 0xc);
  iVar1 = rsin((int)*(short *)((int)&p_Var2->rot + 4));
  p_Var2 = p_Var3->next;
  *(short *)((int)(p_Var3 + 2) + 0x16) =
       *(short *)((int)&p_Var3->next->pos + 2) + (short)(iVar1 * 100 >> 0xc);
  *(short *)((int)(p_Var3 + 2) + 0x18) = *(short *)((int)&p_Var2->pos + 4);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CyberBall_Private_Bullet_Launcher(struct _D3_OBJECT *target /*$s5*/, struct _D3_OBJECT *obj /*$s4*/, struct ENMDEC_7fake *pos /*$s2*/)
 // line 1199, offset 0x8007f398
	/* begin block 1 */
		// Start line: 1200
		// Start offset: 0x8007F398
		// Variables:
	// 		struct _MONSTER *monst; // $s6
	// 		struct ENMDEC_7fake rot; // stack offset -48
	// 		long i; // $s0
	// 		long x; // $s3
	// 		long y; // $s1
	// 		long z; // $s1
	// 		struct ENMDEC_8fake color; // stack offset -40
	/* end block 1 */
	// End offset: 0x8007F614
	// End Line: 1251

	/* begin block 2 */
		// Start line: 2909
	/* end block 2 */
	// End Line: 2910

void CyberBall_Private_Bullet_Launcher(_D3_OBJECT *target,_D3_OBJECT *obj,undefined pos)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  undefined3 in_register_00000019;
  short *psVar7;
  void *pvVar8;
  
  psVar7 = (short *)CONCAT31(in_register_00000019,pos);
  sVar1 = *psVar7;
  sVar2 = psVar7[2];
  pvVar8 = TaskCurrent->local;
  iVar4 = rcos((int)(obj->rot).vy);
  iVar5 = rsin((int)(obj->rot).vy);
  *psVar7 = (short)(iVar4 * (int)sVar1 + iVar5 * (int)sVar2 >> 0xc);
  iVar4 = rsin((int)(obj->rot).vy);
  iVar5 = rcos((int)(obj->rot).vy);
  sVar3 = *psVar7;
  psVar7[2] = (short)(-iVar4 * (int)sVar1 + iVar5 * (int)sVar2 >> 0xc);
  sVar1 = psVar7[1];
  iVar4 = rcos((int)(obj->rot).vz);
  iVar5 = rsin((int)(obj->rot).vz);
  *psVar7 = (short)(iVar4 * (int)sVar3 - iVar5 * (int)sVar1 >> 0xc);
  iVar4 = rsin((int)(obj->rot).vz);
  iVar5 = rcos((int)(obj->rot).vz);
  psVar7[1] = (short)(iVar4 * (int)sVar3 + iVar5 * (int)sVar1 >> 0xc);
  *psVar7 = *psVar7 + (obj->pos).vx;
  psVar7[1] = psVar7[1] + (obj->pos).vy;
  psVar7[2] = psVar7[2] + (obj->pos).vz;
  iVar4 = (int)*(short *)&target[1].prec - (int)(target->b_box).vz;
  DirectionZ((int)(target->pos).vx - (int)*psVar7,(int)(target->pos).vy - (int)psVar7[1],
             ((int)(target->pos).vz - (int)psVar7[2]) + (iVar4 >> 2));
  Direction((int)(target->pos).vx - (int)*psVar7,(int)(target->pos).vy - (int)psVar7[1]);
  if ((iVar4 >> 1 < 0x46) &&
     (lVar6 = Distance2D((int)(target->pos).vx,(int)(target->pos).vy,(int)*psVar7,(int)psVar7[1]),
     500 < lVar6)) {
    if (*(short *)((int)pvVar8 + 0x130) < 1) {
      *(undefined2 *)((int)pvVar8 + 0x130) = 4;
    }
    else {
      M_rand();
    }
  }
  Impact_Sparks(pos,2);
  Laser_Add(pos,0xd0,obj,0xd8);
  D3_PlaySound(obj,2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Living_Decor_CyberBall_Bullet_Create(struct _D3_OBJECT *target /*$s3*/)
 // line 1256, offset 0x8007f65c
	/* begin block 1 */
		// Start line: 1257
		// Start offset: 0x8007F65C
		// Variables:
	// 		struct _MONSTER *monst; // $s1
	// 		struct ENMDEC_7fake pos; // stack offset -32
	// 		long i; // $s0
	// 		long j; // $s2
	/* end block 1 */
	// End offset: 0x8007F700
	// End Line: 1278

	/* begin block 2 */
		// Start line: 3047
	/* end block 2 */
	// End Line: 3048

/* WARNING: Type propagation algorithm not settling */

void Living_Decor_CyberBall_Bullet_Create(_D3_OBJECT *target)

{
  int iVar1;
  _D3_OBJECT *p_Var2;
  
  p_Var2 = (_D3_OBJECT *)TaskCurrent->local;
  *(short *)((int)(p_Var2 + 2) + 0x58) = *(short *)((int)(p_Var2 + 2) + 0x58) + -1;
  M_rand();
  iVar1 = 0;
  CyberBall_Private_Bullet_Launcher(target,p_Var2->next,0xe0);
  do {
    iVar1 = iVar1 + 1;
    Task_Next();
  } while (iVar1 < 8);
  CyberBall_Private_Bullet_Launcher(target,p_Var2->next,0xe0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Living_Decor_CyberBall_Func_Reflex()
 // line 1283, offset 0x8007f72c
	/* begin block 1 */
		// Start line: 1284
		// Start offset: 0x8007F72C
		// Variables:
	// 		struct _MONSTER *monst; // $s0
	// 		struct _D3_OBJECT *obj; // $s1
	// 		struct _D3_OBJECT *t; // $s2
	/* end block 1 */
	// End offset: 0x8007FB30
	// End Line: 1401

	/* begin block 2 */
		// Start line: 3109
	/* end block 2 */
	// End Line: 3110

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Living_Decor_CyberBall_Func_Reflex(void)

{
  short sVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  long lVar5;
  int iVar6;
  _D3_OBJECT *p_Var7;
  int iVar8;
  int iVar9;
  _MONSTER *monst;
  _D3_OBJECT *o;
  
  lVar5 = Monster_Feelings;
  monst = (_MONSTER *)TaskCurrent->local;
  o = monst->obj;
  if (monst->dummy_001 != 0) {
    monst->dummy_001 = monst->dummy_001 + -1;
  }
  if (monst->weapon_timer1 != 0) {
    monst->weapon_timer1 = monst->weapon_timer1 + -1;
  }
  if (monst->weapon_timer2 == 0) {
    monst->flags = monst->flags & 0xff7f;
  }
  else {
    monst->weapon_timer2 = monst->weapon_timer2 + -1;
  }
  if ((LONG_ARRAY_800b2e48[0] != -1) && (p_Var7 = o->child, p_Var7 != (_D3_OBJECT *)0x0)) {
    p_Var7->hit_points = p_Var7->hit_points + -10;
    if (o->child->hit_points < 1) {
      o->child->hit_points = 0;
      if (o->child->hit_points == 0) {
        SFX_AddExplosion(o->child,0,0);
        D3_PlaySound(o,1);
        D3_DeleteObject(o->child);
      }
    }
  }
  if (1 < (monst->eff_pos).pad) {
    (monst->eff_pos).pad = (monst->eff_pos).pad + -1;
  }
  if ((monst->eff_pos).pad < 0) {
    (monst->eff_pos).pad = 1;
  }
  sVar1 = (monst->eff_pos).pad;
  if (sVar1 == 1) {
    D3_StopSound(o,monst->fx_handle);
    monst->fx_handle = -1;
    D3_PlaySound(o,0);
    (monst->eff_pos).pad = 0;
    sVar1 = (monst->eff_pos).pad;
  }
  if (sVar1 == 0x1c) {
    D3_StopSound(o,monst->fx_handle);
    monst->fx_handle = -1;
    D3_PlaySound(o,4);
    sVar1 = D3_PlaySound(o,3);
    monst->fx_handle = sVar1;
  }
  if ((lVar5 != 0) && ((2 < LONG_ARRAY_800b2e2c[0] + 3U || ((monst->flags & 0x80U) != 0)))) {
    uVar4 = D3_GoToDir(o,(int)*(short *)(lVar5 + 0x2c) - (int)(o->pos).vx,
                       (int)*(short *)(lVar5 + 0x2e) - (int)(o->pos).vy,(int)monst->monster_speed);
    monst->timer = (short)uVar4;
    if (((o->child != (_D3_OBJECT *)0x0) || ((o[1].pos.pad & 1U) != 0)) &&
       ((((uVar4 & 0xffff) == 0 && ((monst->flags & 0x80U) != 0)) && (monst->weapon_timer1 == 0))))
    {
      monst->weapon_timer1 = 0x5a;
      Monster_StopAllActions(monst);
      Monster_AddAction(monst,0,0xc,0,0);
      monst->weapon_timer2 = 0;
      (monst->eff_pos).pad = 0x1e;
    }
    lVar5 = Distance2D((int)(o->pos).vx,(int)(o->pos).vy,(int)_DAT_800b1c64,(int)_DAT_800b1c66);
    lVar5 = Direction((int)(short)lVar5,(int)(o->pos).vz - (int)_DAT_800b1c68);
    sVar1 = (o->rot).vy;
    if (1 < (uint)(ushort)o[1].pos.pad - 2) {
      iVar9 = (lVar5 + -0x800) * 0x10000 >> 0x10;
      iVar8 = (int)(short)(sVar1 + -0x800);
      iVar6 = iVar8 - iVar9;
      if (iVar9 != iVar8) {
        if (iVar6 < 0) {
          iVar6 = -iVar6;
        }
        if (iVar6 < 0x1e) {
          (o->rot).vy = (short)lVar5;
        }
        else {
          sVar2 = sVar1 + -0x1e;
          if (iVar8 <= iVar9) {
            sVar2 = sVar1 + 0x1e;
          }
          (o->rot).vy = sVar2;
          monst->timer = 0x1e;
          (monst->eff_pos).pad = 0x1e;
        }
      }
    }
  }
  if ((LONG_ARRAY_800b2e2c[0] == -1) && ((monst->flags & 0x80U) == 0)) {
    lVar5 = D3_GoToDir(o,(int)(monst->eff_pos).vx - (int)(o->pos).vx,
                       (int)(monst->eff_pos).vy - (int)(o->pos).vy,(int)monst->monster_speed);
    monst->timer = (short)lVar5;
    if (1 < (uint)(ushort)o[1].pos.pad - 2) {
      sVar1 = (o->rot).vy;
      sVar2 = (o->rot).vy;
      if (sVar1 != 0) {
        sVar3 = sVar2 + -0x40;
        if (0x800 < sVar1) {
          sVar3 = sVar2 + 0x40;
        }
        (o->rot).vy = sVar3;
        (o->rot).vy = (o->rot).vy & 0xfc0;
        monst->timer = 0x1e;
        (monst->eff_pos).pad = 0x1e;
      }
    }
  }
  p_Var7 = o->child;
  if ((p_Var7 != (_D3_OBJECT *)0x0) && ((p_Var7->display_mode & 2U) != 0)) {
    (p_Var7->rot).vz = (o->rot).vz;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Living_Decor_CyberBall_Func_Decisions()
 // line 1404, offset 0x8007fb48
	/* begin block 1 */
		// Start line: 1405
		// Start offset: 0x8007FB48
		// Variables:
	// 		struct _MONSTER *monst; // $s0
	// 		struct _D3_OBJECT *obj; // $v1
	/* end block 1 */
	// End offset: 0x8007FBC4
	// End Line: 1419

	/* begin block 2 */
		// Start line: 3366
	/* end block 2 */
	// End Line: 3367

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Living_Decor_CyberBall_Func_Decisions(void)

{
  short sVar1;
  _MONSTER *monst;
  
  monst = (_MONSTER *)TaskCurrent->local;
  if ((2 < LONG_ARRAY_800b2e2c[0] + 3U) &&
     (((monst->obj->child != (_D3_OBJECT *)0x0 || (sVar1 = monst->obj[1].pos.pad, sVar1 == 2)) ||
      (sVar1 == 3)))) {
    Monster_StopAllActions(monst);
    Monster_AddAction(monst,0,0xc,0,0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Living_Decor_CyberBall_Task_Action()
 // line 1422, offset 0x8007fbd4
	/* begin block 1 */
		// Start line: 1423
		// Start offset: 0x8007FBD4
		// Variables:
	// 		struct ENMDEC_7fake pos; // stack offset -40
	// 		struct ENMDEC_7fake rot; // stack offset -32
	// 		struct _MONSTER *monst; // $s0
	// 		struct _D3_OBJECT *o; // $s1
	/* end block 1 */
	// End offset: 0x8007FFC4
	// End Line: 1524

	/* begin block 2 */
		// Start line: 3410
	/* end block 2 */
	// End Line: 3411

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Living_Decor_CyberBall_Task_Action(void)

{
  ushort uVar1;
  TASK *pTVar2;
  short sVar3;
  long lVar4;
  uint local_38;
  _MONSTER *monst;
  _D3_OBJECT *o;
  
  monst = (_MONSTER *)TaskCurrent->local;
  o = monst->obj;
  monst->dummy_001 = 0;
  monst->weapon_timer1 = 0x3c;
  monst->hurtsound = 0;
  sVar3 = 0x19;
  if ((o[1].pos.pad & 0x10U) == 0) {
    sVar3 = 0x32;
  }
  monst->monster_speed = sVar3;
  o[1].pos.pad = o[1].pos.pad & 0xffef;
  lVar4 = Task_EventWait();
  pTVar2 = TaskCurrent;
  monst->action = (short)lVar4;
  pTVar2->event_enable = 1;
  do {
    sVar3 = monst->action;
    if (sVar3 == 2) {
      lVar4 = Monster_Action_Hit(-1,-1,1,-1);
      if (lVar4 == 0) {
        uVar1 = monst->flags;
        (monst->eff_pos).pad = 0x1e;
        monst->weapon_timer2 = 0x78;
        monst->flags = uVar1 | 0x80;
        goto LAB_8007ff58;
      }
      monst->mode = 0x11;
      D3_ClearCollBits(monst->obj,(long)&DAT_00004011);
      monst->obj->display_mode = monst->obj->display_mode & 0xffef;
      SFX_AddExplosion(monst->obj,0,0);
      if (-1 < monst->fx_handle) {
        D3_StopSound(o,monst->fx_handle);
        monst->fx_handle = -1;
      }
      D3_PlaySound(o,1);
      monst->actionmask = 0;
    }
    else {
      if (sVar3 < 3) {
        if (sVar3 == 1) {
          monst->busy = 0;
          do {
            Task_Next();
          } while( true );
        }
        monst->actionmask = 0;
      }
      else {
        if (sVar3 == 0xc) {
          while (monst->dummy_001 != 0) {
            Task_Next();
          }
          if ((LONG_ARRAY_800b2e2c[0] != -1) || ((monst->flags & 0x80U) != 0)) {
            if ((uint)(ushort)o[1].pos.pad - 2 < 2) {
              monst->weapon_timer1 = 0x5a;
              monst->weapon_timer2 = 0;
              if (o[1].pos.pad == 3) {
                Monster_Action_Shooting(-1,-1,-1,0x14,1,0xbe,0,1,2);
              }
              else {
                rcos((int)(o->rot).vz);
                rsin((int)(o->rot).vz);
                Impact_Sparks(0xd8,2);
                if (o->hit_power == '\0') {
                  local_38 = 10;
                }
                else {
                  local_38 = (uint)o->hit_power;
                }
                Shoot_Add(o,0xd8,0xe0,0,1,0x21,local_38,1);
                D3_PlaySound(o,2);
                Impact_Smoke(0xd8,0);
              }
            }
            else {
              if (o->child != (_D3_OBJECT *)0x0) {
                Living_Decor_CyberBall_Bullet_Create((_D3_OBJECT *)Monster_Feelings);
              }
            }
            monst->dummy_001 = (int)o[1].pos.vz + 0x1e;
          }
        }
        else {
          if (sVar3 != 0x1f) {
            monst->actionmask = 0;
            goto LAB_8007ff5c;
          }
          MSpell_SpellTesting(monst,TaskCurrent->event_param,-1,-1);
        }
LAB_8007ff58:
        monst->actionmask = 0;
      }
    }
LAB_8007ff5c:
    monst->busy = -1;
    Task_Next();
    if (monst->mode == 0x11) {
      if (-1 < monst->fx_handle) {
        D3_StopSound(o,monst->fx_handle);
        monst->fx_handle = -1;
      }
      Monster_ReleaseBonuses();
      do {
        Task_Next();
      } while( true );
    }
    Monster_ForceAction(monst,1,0);
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Living_Decor_Egnose_Breath()
 // line 1548, offset 0x8007ffc4
	/* begin block 1 */
		// Start line: 1549
		// Start offset: 0x8007FFC4
		// Variables:
	// 		struct ENMDEC_7fake pos; // stack offset -56
	// 		struct ENMDEC_7fake speed; // stack offset -48
	// 		struct _MONSTER *monst; // $s6
	// 		struct _D3_OBJECT *o; // $s2
	// 		struct _D3_OBJECT *o2; // $s0
	// 		struct M_OBJECT *mo; // $s3
	// 		struct M_OBJECT *mo2; // $s1
	// 		struct TASK *SFX_handle; // $s4
	// 		long i; // $s0
	// 		long size; // $s0
	// 		long timer; // $s4
	// 		long heartbeat; // $fp

		/* begin block 1.1 */
			// Start line: 1654
			// Start offset: 0x800802FC
			// Variables:
		// 		struct _MONSTER *baby; // $s5
		/* end block 1.1 */
		// End offset: 0x8008049C
		// End Line: 1698
	/* end block 1 */
	// End offset: 0x800804D0
	// End Line: 1707

	/* begin block 2 */
		// Start line: 3686
	/* end block 2 */
	// End Line: 3687

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Living_Decor_Egnose_Breath(void)

{
  ushort uVar1;
  int iVar2;
  long lVar3;
  M_OBJECT *obj;
  TASK *t;
  _D3_OBJECT *o;
  int iVar4;
  _D3_OBJECT *obj_00;
  M_OBJECT *obj_01;
  int iVar5;
  _MONSTER *monst;
  int iVar6;
  short local_30;
  short local_2e;
  short local_2c;
  
  monst = (_MONSTER *)TaskCurrent->local;
  obj_00 = monst->obj;
  o = obj_00->child;
  obj_01 = (M_OBJECT *)obj_00->description;
  iVar6 = 2;
  if (o != (_D3_OBJECT *)0x0) {
    iVar2 = rcos((int)(obj_00->rot).vz);
    local_30 = (short)((uint)(iVar2 * 5) >> 0xb);
    iVar2 = rsin((int)(obj_00->rot).vz);
    local_2e = (short)(iVar2 * 10 >> 0xc);
    local_2c = -0x14;
    do {
      o->display_mode = o->display_mode & 0xffef;
      D3_ClearCollBits(o,9);
      o = o->next;
    } while (o != (_D3_OBJECT *)0x0);
  }
  lVar3 = Zone_IsZoneAttached(obj_00);
  if (lVar3 != 0) {
    do {
      if ((Scts_Interruptors & (int)obj_00[1].pos.vz) != 0) {
        Monster_StopAllActions(monst);
        Monster_AddAction(monst,0,2,0,0);
      }
      if (((obj_01->Env).Obj.vert_top.pad & 1U) != 0) {
        D3_PlaySound(obj_00,0);
      }
      Task_Next();
      lVar3 = Task_EventRead(obj_00->handle);
    } while (lVar3 != 2);
  }
  do {
    Manim_SetAnim(obj_01,0);
    if (monst->timer == 2) {
      iVar6 = 8;
    }
    if (monst->timer == 4) {
      iVar6 = 4;
    }
    iVar5 = iVar6 << 2;
    iVar2 = iVar6;
    do {
      Manim_ForceAnim(obj_01,0);
      D3_PlaySound(obj_00,0);
      while ((((obj_01->Env).Obj.normal_top.vx & 0x4000U) == 0 &&
             ((obj_00->collision_state & 1U) == 0))) {
        if ((Scts_Interruptors & (int)obj_00[1].pos.vz) != 0) {
          Monster_StopAllActions(monst);
          Monster_AddAction(monst,0,2,0,0);
        }
        Task_Next();
      }
      iVar4 = 0;
      (obj_01->Env).Obj.normal_top.vx = (obj_01->Env).Obj.normal_top.vx & 0xfffe;
      if (0 < iVar5) {
        do {
          if ((obj_00->collision_state & 1U) != 0) break;
          if ((Scts_Interruptors & (int)obj_00[1].pos.vz) != 0) {
            Monster_StopAllActions(monst);
            Monster_AddAction(monst,0,2,0,0);
          }
          iVar4 = iVar4 + 1;
          Task_Next();
        } while (iVar4 < iVar5);
      }
      iVar5 = iVar5 + -4;
      iVar2 = iVar2 + -1;
      if ((Scts_Interruptors & (int)obj_00[1].pos.vz) != 0) {
        Monster_StopAllActions(monst);
        Monster_AddAction(monst,0,2,0,0);
      }
      Task_Next();
      if ((obj_00->collision_state & 1U) != 0) {
        obj_00->collision_state = obj_00->collision_state & 0xfffe;
        break;
      }
    } while (-1 < iVar2);
    o = Living_Decor_Egnose_FindBaby(obj_00);
    if (o != (_D3_OBJECT *)0x0) {
      iVar2 = *(int *)&o[1].last_pos;
      obj = Living_Decor_Egnose_ResetBaby(obj_00,o);
      Manim_SetAnim(obj_01,2);
      Manim_WaitEvent(obj_01,0x10);
      o->display_mode = o->display_mode | 0x10;
      (o->pos).vx = (o->pos).vx + local_30 * 6;
      (o->pos).vy = (o->pos).vy + local_2e * 6;
      D3_PlaySound(obj_00,1);
      t = SFX_StreamBirth(200,(char)obj_00 + '<');
      Manim_SetAnim(obj,2);
      while (((obj->Env).Obj.vert_top.pad & 0x10U) == 0) {
        uVar1 = (obj_01->Env).Obj.normal_top.vx;
        if ((uVar1 & 0x4000) != 0) {
          (obj_01->Env).Obj.normal_top.vx = uVar1 & 0xfffe;
        }
        Task_Next();
      }
      (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
      while (((int)o->collision_state & 0xfc00U) == 0) {
        (o->pos).vx = (o->pos).vx + local_30;
        (o->pos).vy = (o->pos).vy + local_2e;
        (o->pos).vz = (o->pos).vz + local_2c;
        uVar1 = (obj_01->Env).Obj.normal_top.vx;
        if ((uVar1 & 0x4000) != 0) {
          (obj_01->Env).Obj.normal_top.vx = uVar1 & 0xfffe;
        }
        Task_Next();
      }
      uVar1 = (obj->Env).Obj.normal_top.vx;
      (obj->Env).Obj.normal_top.vx = uVar1 | 1;
      iVar5 = 0x14;
      while ((uVar1 & 0x4000) == 0) {
        *(undefined2 *)((int)&t[1].s7 + 2) = (short)iVar5;
        if (0 < iVar5) {
          iVar5 = iVar5 + -1;
        }
        Task_Next();
        uVar1 = (obj->Env).Obj.normal_top.vx;
      }
      (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
      *(ushort *)(iVar2 + 0x14) = *(ushort *)(iVar2 + 0x14) & 0xffef;
      Task_Kill(t);
    }
  } while( true );
}



// decompiled code
// original method signature: 
// struct _D3_OBJECT * /*$ra*/ Living_Decor_Egnose_FindBaby(struct _D3_OBJECT *obj /*$a0*/)
 // line 1711, offset 0x800804d0
	/* begin block 1 */
		// Start line: 1713
		// Start offset: 0x800804D0
		// Variables:
	// 		struct _D3_OBJECT *child; // $v1

		/* begin block 1.1 */
			// Start line: 1717
			// Start offset: 0x800804E0
			// Variables:
		// 		struct _MONSTER *monst; // $v0
		/* end block 1.1 */
		// End offset: 0x800804FC
		// End Line: 1722
	/* end block 1 */
	// End offset: 0x8008050C
	// End Line: 1725

	/* begin block 2 */
		// Start line: 4105
	/* end block 2 */
	// End Line: 4106

_D3_OBJECT * Living_Decor_Egnose_FindBaby(_D3_OBJECT *obj)

{
  _D3_OBJECT *p_Var1;
  
  p_Var1 = obj->child;
  while( true ) {
    if (p_Var1 == (_D3_OBJECT *)0x0) {
      return (_D3_OBJECT *)0x0;
    }
    if ((*(ushort *)(*(int *)&p_Var1[1].last_pos + 0x14) & 0x10) != 0) break;
    p_Var1 = p_Var1->next;
  }
  return p_Var1;
}



// decompiled code
// original method signature: 
// struct M_OBJECT * /*$ra*/ Living_Decor_Egnose_ResetBaby(struct _D3_OBJECT *obj /*$s1*/, struct _D3_OBJECT *child /*$s0*/)
 // line 1729, offset 0x8008051c
	/* begin block 1 */
		// Start line: 1730
		// Start offset: 0x8008051C
		// Variables:
	// 		struct M_OBJECT *mo; // $s0
	/* end block 1 */
	// End offset: 0x8008051C
	// End Line: 1730

	/* begin block 2 */
		// Start line: 4140
	/* end block 2 */
	// End Line: 4141

M_OBJECT * Living_Decor_Egnose_ResetBaby(_D3_OBJECT *obj,_D3_OBJECT *child)

{
  ushort uVar1;
  undefined4 uVar2;
  M_OBJECT *obj_00;
  
  child->display_mode = child->display_mode & 0xffef;
  D3_SetCollBits(child,9);
  *(undefined2 *)(*(int *)&child[1].last_pos + 0x10) = 0;
  uVar2 = *(undefined4 *)&(obj->pos).vz;
  *(undefined4 *)&child->pos = *(undefined4 *)&obj->pos;
  *(undefined4 *)&(child->pos).vz = uVar2;
  (child->pos).vz = (child->pos).vz + -100;
  uVar2 = *(undefined4 *)&(child->pos).vz;
  *(undefined4 *)&child->last_pos = *(undefined4 *)&child->pos;
  *(undefined4 *)&(child->last_pos).vz = uVar2;
  uVar2 = *(undefined4 *)&(obj->rot).vz;
  *(undefined4 *)&child->rot = *(undefined4 *)&obj->rot;
  *(undefined4 *)&(child->rot).vz = uVar2;
  obj_00 = (M_OBJECT *)child->description;
  Manim_SetAnim(obj_00,2);
  uVar1 = (obj_00->Env).Obj.normal_top.vx;
  *(undefined2 *)&(obj_00->Env).nPivot = 0;
  (obj_00->Env).Obj.normal_top.vx = uVar1 & 0xfffe;
  return obj_00;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Living_Decor_Egnose_Task_Action()
 // line 1750, offset 0x80080600
	/* begin block 1 */
		// Start line: 1751
		// Start offset: 0x80080600
		// Variables:
	// 		struct _MONSTER *monst; // $s0
	// 		struct M_OBJECT *mo; // $s1
	/* end block 1 */
	// End offset: 0x80080720
	// End Line: 1792

	/* begin block 2 */
		// Start line: 4189
	/* end block 2 */
	// End Line: 4190

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Living_Decor_Egnose_Task_Action(void)

{
  TASK *pTVar1;
  long lVar2;
  _MONSTER *monst;
  M_OBJECT *obj;
  
  monst = (_MONSTER *)TaskCurrent->local;
  obj = (M_OBJECT *)monst->obj->description;
  lVar2 = Task_EventWait();
  pTVar1 = TaskCurrent;
  monst->action = (short)lVar2;
  pTVar1->event_enable = 1;
  do {
    if (monst->action == 1) {
      monst->busy = 0;
      Living_Decor_Egnose_Breath();
    }
    else {
      if (monst->action == 2) {
        lVar2 = Monster_Action_Hit(-1,-1,1,-1);
        if (lVar2 != 0) {
          monst->mode = 0x11;
          D3_ClearCollBits(monst->obj,(long)&DAT_00004011);
          SFX_AddExplosion(monst->obj,0,0);
          Manim_SetAnim(obj,3);
          Manim_WaitAnim(obj);
          (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
          return;
        }
        if (monst->timer != 5) {
          monst->timer = monst->timer + 1;
        }
      }
    }
    monst->actionmask = 0;
    monst->busy = -1;
    Monster_ForceAction(monst,1,0);
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Living_Decor_Crumbling_Wall()
 // line 1807, offset 0x80080734
	/* begin block 1 */
		// Start line: 1808
		// Start offset: 0x80080734
		// Variables:
	// 		struct _MONSTER *monst; // $v0
	// 		struct _D3_OBJECT *o; // $s1
	// 		struct M_OBJECT *mo; // $s0
	// 		struct ENMDEC_7fake pos; // stack offset -24
	// 		long i; // $a0

		/* begin block 1.1 */
			// Start line: 1821
			// Start offset: 0x800807A0
			// Variables:
		// 		struct ENMDEC_99fake *Anim; // $v0
		/* end block 1.1 */
		// End offset: 0x800807F0
		// End Line: 1831
	/* end block 1 */
	// End offset: 0x800808C4
	// End Line: 1876

	/* begin block 2 */
		// Start line: 4308
	/* end block 2 */
	// End Line: 4309

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Living_Decor_Crumbling_Wall(void)

{
  short *psVar1;
  int iVar2;
  M_OBJECT *obj;
  _D3_OBJECT *o;
  
  o = ((_D3_OBJECT *)TaskCurrent->local)->next;
  obj = (M_OBJECT *)o->description;
  (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
  iVar2 = 4;
  if ((Pvl_SctState[(int)o->index] & 0x40U) == 0) {
    while (o->hit_points != 0) {
      Task_Next();
    }
    Manim_SetAnim(obj,0);
    while (iVar2 = 4, ((obj->Env).Obj.normal_top.vx & 0x4000U) == 0) {
      if ((obj->Env).Obj.vert_top.pad != 0) {
        Manim_EventGetPos(obj,0xe8);
        Impact_Stone(0xe8,7);
        Impact_Smoke(0xe8,1);
      }
      Task_Next();
    }
    psVar1 = &o->hit_points;
    (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
    do {
      iVar2 = iVar2 + 1;
      psVar1[0x28] = (o->b_box).vz + 100;
      psVar1 = psVar1 + 4;
    } while (iVar2 < 8);
    Pvl_SetStateBits(o,0x40);
    do {
      (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
      Task_Next();
    } while( true );
  }
  psVar1 = &o->hit_points;
  *(short *)&(obj->Env).nPivot =
       (*(short *)(*(int *)(*(int *)((obj->Sq).Data.FatherTrans + 2) + 8) + 6) + -1) * 0x10;
  do {
    iVar2 = iVar2 + 1;
    psVar1[0x28] = (o->b_box).vz + 100;
    psVar1 = psVar1 + 4;
  } while (iVar2 < 8);
  do {
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Living_Decor_Crumble_Task_Action()
 // line 1879, offset 0x800808c4
	/* begin block 1 */
		// Start line: 1880
		// Start offset: 0x800808C4
		// Variables:
	// 		struct _MONSTER *monst; // $s0
	/* end block 1 */
	// End offset: 0x80080944
	// End Line: 1901

	/* begin block 2 */
		// Start line: 4463
	/* end block 2 */
	// End Line: 4464

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Living_Decor_Crumble_Task_Action(void)

{
  TASK *pTVar1;
  long lVar2;
  _MONSTER *monst;
  
  monst = (_MONSTER *)TaskCurrent->local;
  lVar2 = Task_EventWait();
  pTVar1 = TaskCurrent;
  monst->action = (short)lVar2;
  pTVar1->event_enable = 1;
  do {
    if (monst->action == 1) {
      monst->busy = 0;
      Living_Decor_Crumbling_Wall();
    }
    monst->actionmask = 0;
    monst->busy = -1;
    Monster_ForceAction(monst,1,0);
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Asp_Func_Reflex()
 // line 1921, offset 0x80080944
	/* begin block 1 */
		// Start line: 1922
		// Start offset: 0x80080944
		// Variables:
	// 		struct _MONSTER *monst; // $s0
	// 		struct _D3_OBJECT *o; // $s1
	/* end block 1 */
	// End offset: 0x800809EC
	// End Line: 1956

	/* begin block 2 */
		// Start line: 4553
	/* end block 2 */
	// End Line: 4554

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Asp_Func_Reflex(void)

{
  short sVar1;
  _MONSTER *monst;
  _D3_OBJECT *o;
  
  monst = (_MONSTER *)TaskCurrent->local;
  o = monst->obj;
  if (o->child != (_D3_OBJECT *)0x0) {
    D3_ClearCollBits(o->child,9);
  }
  if (monst->mode == 1) {
    sVar1 = D3_UpdateSound(o,1,monst->fx_handle);
    monst->fx_handle = sVar1;
    if (monst->timer != 0) {
      monst->timer = monst->timer + -1;
    }
    if (((int)o->collision_state & 0xfc00U) != 0) {
      Monster_StopAllActions(monst);
      Monster_AddAction(monst,0,3,0,0);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Asp_Task_Action()
 // line 1959, offset 0x80080a00
	/* begin block 1 */
		// Start line: 1960
		// Start offset: 0x80080A00
		// Variables:
	// 		struct _MONSTER *monst; // $s1
	// 		struct _D3_OBJECT *o; // $s5
	// 		struct M_OBJECT *mo; // $s4
	// 		struct _D3_OBJECT *tmpobj; // $s0
	// 		long i; // $s0
	// 		long x; // $s3
	// 		long y; // $s2
	// 		long z; // $s0
	// 		short customzone[6]; // stack offset -56
	/* end block 1 */
	// End offset: 0x80080DA4
	// End Line: 2049

	/* begin block 2 */
		// Start line: 4630
	/* end block 2 */
	// End Line: 4631

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Asp_Task_Action(void)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  TASK *pTVar7;
  long lVar8;
  _ENEMYZONE *p_Var9;
  _D3_OBJECT *o;
  int iVar10;
  _MONSTER *monst;
  M_OBJECT *obj;
  _D3_OBJECT *o_00;
  short local_38;
  short local_36;
  short local_34;
  short local_32;
  short local_30;
  short local_2e;
  
  monst = (_MONSTER *)TaskCurrent->local;
  o_00 = monst->obj;
  obj = (M_OBJECT *)o_00->description;
  monst->timer = 0x5a;
  D3_ClearCollBits(o_00,(long)&DAT_00004010);
  if ((o_00->display_mode & 0x40U) != 0) {
    (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
  }
  o = o_00->child;
  if (o != (_D3_OBJECT *)0x0) {
    while (lVar8 = Pvl_TestStateBits(o,2), lVar8 == 0) {
      Task_Next();
    }
    Monster_ForceAction(monst,0xe,0);
    monst->flags = monst->flags & 0xffef;
  }
  monst->timer = 0;
  Pri_Get_CustomZones(monst,&local_38);
  monst->monster_speed = 0x20;
  if (monst->zone_fear == -1) {
    monst->flags = monst->flags & 0xffef;
  }
  monst->fx_handle = -1;
  lVar8 = Task_EventWait();
  pTVar7 = TaskCurrent;
  monst->action = (short)lVar8;
  pTVar7->event_enable = 1;
  while( true ) {
    sVar1 = monst->action;
    if (sVar1 == 3) {
      monst->mode = 0x10;
      if (monst->fx_handle != -1) {
        D3_StopSound(o_00,monst->fx_handle);
        monst->fx_handle = -1;
      }
      iVar10 = 0;
      do {
        iVar10 = iVar10 + 1;
        Task_Next();
      } while (iVar10 < 0x3c);
      D3_PlaySound(o_00,2);
      Monster_StopAllActions(monst);
      Monster_AddAction(monst,0,1,0,0);
      monst->actionmask = 0;
    }
    else {
      if (sVar1 < 4) {
        if (sVar1 == 1) {
          monst->busy = 0;
          if ((monst->flags & 0x10U) != 0) {
            do {
              Task_Next();
            } while( true );
          }
          (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
          do {
            if (monst->fx_handle != -1) {
              D3_StopSound(o_00,monst->fx_handle);
              monst->fx_handle = -1;
            }
            monst->mode = 1;
            Monster_Action_MoveGlide
                      ((_D3_OBJECT *)0x0,0x21,5,local_38,(int)local_36,(int)local_34,1);
            Monster_Action_MoveGlide
                      ((_D3_OBJECT *)0x0,0x21,5,local_32,(int)local_30,(int)local_2e,1);
            monst->mode = 0x10;
          } while( true );
        }
        monst->actionmask = 0;
      }
      else {
        if (sVar1 == 0xe) {
          p_Var9 = Pvl_EnemyZones + (int)monst->zone_fear;
          sVar1 = p_Var9->x1;
          sVar2 = p_Var9->x2;
          sVar3 = p_Var9->y1;
          sVar4 = p_Var9->y2;
          sVar5 = p_Var9->z1;
          sVar6 = p_Var9->z2;
          if (monst->fx_handle != -1) {
            D3_StopSound(o_00,monst->fx_handle);
          }
          monst->mode = 1;
          Monster_Action_MoveGlide
                    ((_D3_OBJECT *)0x0,0x21,5,(short)((int)sVar1 + (int)sVar2 >> 1),
                     (int)sVar3 + (int)sVar4 >> 1,(int)sVar5 + (int)sVar6 >> 1,1);
          monst->mode = 0x10;
          if (monst->fx_handle != -1) {
            D3_StopSound(o_00,monst->fx_handle);
          }
          D3_PlaySound(o_00,0);
          Manim_SetAnim(obj,0);
          Manim_WaitAnim(obj);
          Scts_Interruptors = Scts_Interruptors | 0x40;
          D3_PlaySound(o_00,0);
          Manim_SetAnim(obj,1);
          Manim_WaitAnim(obj);
          (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
          monst->actionmask = 0;
        }
        else {
          monst->actionmask = 0;
        }
      }
    }
    monst->busy = -1;
    Task_Next();
    if (monst->mode == 0x11) break;
    Monster_ForceAction(monst,1,0);
    Task_Next();
  }
  Monster_ReleaseBonuses();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Living_Decor_Camera_Task_Action()
 // line 2068, offset 0x80080dd8
	/* begin block 1 */
		// Start line: 2069
		// Start offset: 0x80080DD8
		// Variables:
	// 		struct _MONSTER *monst; // $s1
	// 		struct _D3_OBJECT *o; // $s0
	// 		struct ENMDEC_7fake trans; // stack offset -32
	// 		struct TASK *ReactorTask; // $s0
	/* end block 1 */
	// End offset: 0x80080EA0
	// End Line: 2100

	/* begin block 2 */
		// Start line: 4874
	/* end block 2 */
	// End Line: 4875

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Living_Decor_Camera_Task_Action(void)

{
  char cVar1;
  TASK *pTVar2;
  TASK *t;
  long lVar3;
  _D3_OBJECT *p_Var4;
  _MONSTER *monst;
  undefined auStack32 [8];
  
  monst = (_MONSTER *)TaskCurrent->local;
  p_Var4 = monst->obj;
  memset(auStack32,0,8);
  monst->hurtsound = 3;
  cVar1 = (char)p_Var4;
  t = SFX_StreamReactor(cVar1 + ',',cVar1 + '<',0xe0);
  lVar3 = Task_EventWait();
  pTVar2 = TaskCurrent;
  monst->action = (short)lVar3;
  pTVar2->event_enable = 1;
  while( true ) {
    if (monst->action == 1) {
      monst->busy = 0;
      Living_Decor_Camera_Wait();
    }
    monst->actionmask = 0;
    monst->busy = -1;
    if (monst->mode == 0x11) break;
    Monster_ForceAction(monst,1,0);
    Task_Next();
  }
  Task_Kill(t);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Living_Decor_Camera_Wait()
 // line 2104, offset 0x80080ec8
	/* begin block 1 */
		// Start line: 2105
		// Start offset: 0x80080EC8
		// Variables:
	// 		struct _MONSTER *monst; // $s6
	// 		struct _D3_OBJECT *o; // $s4
	// 		struct _D3_OBJECT *child; // $s1
	// 		struct _D3_OBJECT *bchild; // $s2
	// 		struct ENMDEC_7fake rot; // stack offset -120
	// 		struct ENMDEC_7fake pos; // stack offset -112
	// 		short nChild; // $s0
	// 		short cpt; // $s5
	// 		short timer[3]; // stack offset -104
	// 		short ShootState; // stack offset -80
	// 		long state[3]; // stack offset -96
	// 		long loff; // stack offset -72
	// 		long lon; // stack offset -68
	// 		long lred; // stack offset -64
	// 		short cpt_trans; // stack offset -56
	// 		short step; // $s7
	// 		short nbf; // stack offset -48
	/* end block 1 */
	// End offset: 0x8008146C
	// End Line: 2259

	/* begin block 2 */
		// Start line: 4971
	/* end block 2 */
	// End Line: 4972

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Living_Decor_Camera_Wait(void)

{
  short sVar1;
  _PLATFORM *p_Var2;
  long target;
  int index;
  long lVar3;
  short sVar4;
  int iVar5;
  uint *puVar6;
  undefined4 uVar7;
  ushort uVar8;
  _D3_OBJECT *o;
  _D3_OBJECT *o_00;
  short *psVar9;
  _D3_OBJECT *o_01;
  _D3_OBJECT *p_Var10;
  int iVar11;
  undefined auStack120 [4];
  short local_74;
  undefined2 local_70;
  undefined2 local_6e;
  short local_6c;
  short local_68 [4];
  uint local_60 [4];
  short local_50;
  undefined *local_48;
  long local_44;
  undefined *local_40;
  ushort local_38;
  ushort local_30;
  
  local_50 = 0;
  local_48 = &DAT_00323232;
  local_44 = 0x969696;
  p_Var10 = (_D3_OBJECT *)TaskCurrent->local;
  local_40 = &DAT_000a0000;
  o_01 = p_Var10->next;
  uVar8 = 0;
  memset(auStack120,0,8);
  local_60[0] = DAT_800ad92c;
  local_60[1] = DAT_800ad930;
  local_60[2] = DAT_800ad934;
  Pvl_SetStateBits(o_01,4);
  local_30 = o_01[1].pos.vz;
  *(undefined2 *)((int)(p_Var10 + 2) + 0x44) = 0xffff;
  *(undefined2 *)((int)(p_Var10 + 2) + 0x48) = 0xffff;
  local_30 = local_30 >> 8;
  p_Var2 = Plat_GetPlat((char)o_01 + ',');
  local_6e = 0;
  local_70 = 0x96;
  local_40 = (undefined *)((uint)local_40 | 0xafa);
  local_6c = *(short *)&p_Var2[1].obj.prec + 0x14;
  o = o_01->child;
  local_38 = 0;
  while (o != (_D3_OBJECT *)0x0) {
    o_00 = o->child;
    D3_ClearCollBits(o,1);
    D3_ClearCollBits(o_00,1);
    uVar7 = *(undefined4 *)&(o_01->pos).vz;
    *(undefined4 *)&o->pos = *(undefined4 *)&o_01->pos;
    *(undefined4 *)&(o->pos).vz = uVar7;
    (o->rot).vz = (o->rot).vz + uVar8 * 0x555;
    target = M_rand();
    *(short *)((int)local_68 + ((int)((uint)uVar8 << 0x10) >> 0xf)) =
         (short)target + (short)(target / 0x8c) * -0x8c + 2;
    o = o->next;
    uVar8 = uVar8 + 1;
  }
  iVar5 = (int)o_01[1].pos.pad * 100;
  index = (int)(short)local_30;
  iVar11 = iVar5 / index;
  if (index == 0) {
    trap(0x1c00);
  }
  if ((index == -1) && (iVar5 == -0x80000000)) {
    trap(0x1800);
  }
  if (*(short *)&p_Var10->list != 0x11) {
    do {
      sVar1 = D3_UpdateSound(o_01,1,*(short *)((int)(p_Var10 + 2) + 0x48));
      *(short *)((int)(p_Var10 + 2) + 0x48) = sVar1;
      if ((int)(short)iVar11 != 0) {
        if (local_38 == local_30) {
          local_38 = 0;
          iVar11 = -(int)(short)iVar11;
        }
        sVar1 = (short)iVar11;
        if (*(char *)&o_01[1].pos.vz == '\0') {
          o = o_01->child;
          (o_01->pos).vx = (o_01->pos).vx + sVar1;
          while (o != (_D3_OBJECT *)0x0) {
            (o->pos).vx = (o->pos).vx + sVar1;
            o = o->next;
          }
        }
        else {
          o = o_01->child;
          (o_01->pos).vy = (o_01->pos).vy + sVar1;
          while (o != (_D3_OBJECT *)0x0) {
            (o->pos).vy = (o->pos).vy + sVar1;
            o = o->next;
          }
        }
        local_38 = local_38 + 1;
      }
      (o_01->rot).vz = (o_01->rot).vz + 0x14;
      local_74 = local_74 + 0x14;
      o = o_01->child;
      uVar8 = 0;
      while (o != (_D3_OBJECT *)0x0) {
        o_00 = o->child;
        (o->rot).vz = (o->rot).vz + 0x14;
        (o_00->rot).vz = (o_00->rot).vz + 0x14;
        index = (int)(short)uVar8;
        Living_Decor_Camera_RotTarget(o_01,0x90,0x88,(char)o_00 + ',',index);
        psVar9 = local_68 + index;
        sVar1 = *psVar9;
        *psVar9 = sVar1 + -1;
        if (sVar1 == 1) {
          if (local_60[index] == 0) {
            target = M_rand();
            sVar1 = (short)target;
            sVar4 = (short)(target / 0x8c) * 0x8c;
          }
          else {
            D3_PlaySound(o_01,3);
            target = M_rand();
            sVar1 = (short)target;
            sVar4 = (short)(target / 10) * 10;
          }
          *psVar9 = (sVar1 - sVar4) + 2;
          puVar6 = (uint *)((int)local_60 + ((int)((uint)uVar8 << 0x10) >> 0xe));
          *puVar6 = *puVar6 ^ 1;
        }
        target = Monster_Feelings;
        if ((1 < Monster_Feelings + 1U) && ((_D3_OBJECT *)Monster_Feelings != o_01)) {
          lVar3 = Distance3D((int)(o_00->pos).vx,(int)(o_00->pos).vy,(int)(o_00->pos).vz,
                             (int)*(short *)(Monster_Feelings + 0x2c),
                             (int)*(short *)(Monster_Feelings + 0x2e),
                             (int)*(short *)(Monster_Feelings + 0x30));
          if (lVar3 < 0x5a) {
            if (local_50 == 0) {
              sVar1 = D3_PlaySound(o_01,0);
              *(short *)((int)(p_Var10 + 2) + 0x44) = sVar1;
              local_50 = 1;
            }
            Camera_Shoot((_D3_OBJECT *)target,o_01,(int)(short)uVar8);
            *(undefined **)&o->color = local_40;
            *(undefined **)&o_00->color = local_40;
          }
          else {
            D3_StopSound(o_01,*(short *)((int)(p_Var10 + 2) + 0x44));
            *(undefined2 *)((int)(p_Var10 + 2) + 0x44) = 0xffff;
            if (*(int *)((int)local_60 + ((int)((uint)uVar8 << 0x10) >> 0xe)) == 0) {
              *(undefined **)&o->color = local_48;
              *(undefined **)&o_00->color = local_48;
            }
            else {
              o->color = local_44;
              o_00->color = local_44;
            }
          }
        }
        o = o->next;
        uVar8 = uVar8 + 1;
      }
      Task_Next();
    } while (*(short *)&p_Var10->list != 0x11);
  }
  if (-1 < *(short *)((int)(p_Var10 + 2) + 0x48)) {
    D3_StopSound(o_01,*(short *)((int)(p_Var10 + 2) + 0x48));
  }
  if (-1 < *(short *)((int)(p_Var10 + 2) + 0x44)) {
    D3_StopSound(o_01,*(short *)((int)(p_Var10 + 2) + 0x44));
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Living_Decor_Camera_RotTarget(struct _D3_OBJECT *father /*$s4*/, struct ENMDEC_7fake *pos /*$s5*/, struct ENMDEC_7fake *angle /*$s3*/, struct ENMDEC_7fake *result /*$s2*/, int index /*stack 16*/)
 // line 2263, offset 0x8008149c
	/* begin block 1 */
		// Start line: 2264
		// Start offset: 0x8008149C
		// Variables:
	// 		struct ENMDEC_5fake mr; // stack offset -104
	// 		struct ENMDEC_7fake rot; // stack offset -72
	// 		struct ENMDEC_7fake trans; // stack offset -64
	// 		struct ENMDEC_7fake *ctr; // $s6
	// 		struct ENMDEC_6fake dummy; // stack offset -56
	// 		long f; // stack offset -40
	/* end block 1 */
	// End offset: 0x8008149C
	// End Line: 2264

	/* begin block 2 */
		// Start line: 5470
	/* end block 2 */
	// End Line: 5471

/* WARNING: Could not reconcile some variable overlaps */

void Living_Decor_Camera_RotTarget
               (_D3_OBJECT *father,undefined pos,undefined angle,undefined result,int index)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 in_zero;
  undefined4 in_at;
  undefined3 in_register_00000015;
  undefined3 in_register_00000019;
  undefined3 in_register_0000001d;
  short *psVar4;
  uint uVar5;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  uint local_44;
  undefined4 local_40;
  undefined4 local_3c;
  short local_38;
  short local_34;
  short local_30;
  
  psVar4 = (short *)CONCAT31(in_register_0000001d,result);
  memset(&local_40,0,8);
  setCopReg(2,in_zero,local_40);
  setCopReg(2,in_at,local_3c);
  copFunction(2,0x486012);
  local_54 = getCopReg(2,0x19);
  local_50 = getCopReg(2,0x1a);
  local_4c = getCopReg(2,0x1b);
  local_48 = *(undefined4 *)CONCAT31(in_register_00000019,angle);
  uVar5 = ((undefined4 *)CONCAT31(in_register_00000019,angle))[1];
  local_44._0_2_ = (short)uVar5;
  local_44 = uVar5 & 0xffff0000 | (uint)(ushort)((short)local_44 + (short)index * 0x555);
  RotMatrix((short *)&local_48,(undefined2 *)&local_68);
  setCopControlWord(2,0x2800,local_54);
  setCopControlWord(2,0x3000,local_50);
  setCopControlWord(2,0x3800,local_4c);
  setCopControlWord(2,0,local_68);
  setCopControlWord(2,0x800,local_64);
  setCopControlWord(2,0x1000,local_60);
  setCopControlWord(2,0x1800,local_5c);
  setCopControlWord(2,0x2000,local_58);
  setCopReg(2,in_zero,*(undefined4 *)CONCAT31(in_register_00000015,pos));
  setCopReg(2,in_at,((undefined4 *)CONCAT31(in_register_00000015,pos))[1]);
  copFunction(2,0x480012);
  uVar1 = getCopReg(2,0x19);
  uVar2 = getCopReg(2,0x1a);
  uVar3 = getCopReg(2,0x1b);
  getCopControlWord(2,0xf800);
  local_38 = (short)uVar1;
  *psVar4 = local_38 + (father->pos).vx;
  local_34 = (short)uVar2;
  psVar4[1] = local_34 + (father->pos).vy;
  local_30 = (short)uVar3;
  psVar4[2] = local_30;
  setCopControlWord(2,0x2800,Cam_Matrix.t[0]);
  setCopControlWord(2,0x3000,Cam_Matrix.t[1]);
  setCopControlWord(2,0x3800,Cam_Matrix.t[2]);
  setCopControlWord(2,0,Cam_Matrix.m[0]._0_4_);
  setCopControlWord(2,0x800,Cam_Matrix.m._4_4_);
  setCopControlWord(2,0x1000,Cam_Matrix.m[1]._2_4_);
  setCopControlWord(2,0x1800,Cam_Matrix.m[2]._0_4_);
  setCopControlWord(2,0x2000,Cam_Matrix._16_4_);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Camera_Shoot(struct _D3_OBJECT *target /*$s0*/, struct _D3_OBJECT *obj /*$s2*/, long index /*$s1*/)
 // line 2296, offset 0x80081680
	/* begin block 1 */
		// Start line: 2297
		// Start offset: 0x80081680
		// Variables:
	// 		struct ENMDEC_7fake pos; // stack offset -40
	// 		struct ENMDEC_7fake rot; // stack offset -32
	// 		struct ENMDEC_8fake color; // stack offset -24
	/* end block 1 */
	// End offset: 0x80081680
	// End Line: 2297

	/* begin block 2 */
		// Start line: 5545
	/* end block 2 */
	// End Line: 5546

void Camera_Shoot(_D3_OBJECT *target,_D3_OBJECT *obj,long index)

{
  long lVar1;
  short local_28;
  short sStack38;
  short local_24;
  
  local_28 = (short)*(undefined4 *)&obj->pos;
  sStack38 = (short)((uint)*(undefined4 *)&obj->pos >> 0x10);
  local_24 = (short)*(undefined4 *)&(obj->pos).vz;
  lVar1 = Distance2D((int)local_28,(int)sStack38,(int)(target->pos).vx,(int)(target->pos).vy);
  Direction((int)(short)lVar1,(int)(target->pos).vz - (int)(short)(local_24 + -0x32));
  Laser_Add(0xd8,0xe0,obj,0xe8);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Living_Decor_Camera_Func_Reflex()
 // line 2318, offset 0x80081764
	/* begin block 1 */
		// Start line: 2319
		// Start offset: 0x80081764
		// Variables:
	// 		struct _MONSTER *mo; // $s0
	// 		struct _D3_OBJECT *obj; // $a0
	/* end block 1 */
	// End offset: 0x800817B4
	// End Line: 2333

	/* begin block 2 */
		// Start line: 5620
	/* end block 2 */
	// End Line: 5621

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Living_Decor_Camera_Func_Reflex(void)

{
  _MONSTER *monst;
  
  monst = (_MONSTER *)TaskCurrent->local;
  if ((LONG_ARRAY_800b2e48[0] != -1) && (monst->obj->hit_points < 1)) {
    monst->mode = 0x11;
    D3_ExplodeObject(monst->obj);
    Monster_StopAllActions(monst);
  }
  return;
}





