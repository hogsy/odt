#include "THISDUST.H"
#include "SH_E01.H"


// decompiled code
// original method signature: 
// void /*$ra*/ SHS01_Display()
 // line 46, offset 0x80045174
	/* begin block 1 */
		// Start line: 47
		// Start offset: 0x80045174
		// Variables:
	// 		struct _SHOOT *sh; // $s0
	// 		short size; // $t0
	// 		struct SH_E01_7fake *angle; // $s4
	// 		struct SH_E01_31fake *p; // $s1
	// 		struct SH_E01_70fake shp; // stack offset -160
	// 		struct SH_E01_5fake mr; // stack offset -144
	// 		struct SH_E01_6fake d[4]; // stack offset -112
	// 		struct SH_E01_7fake dummy; // stack offset -48
	// 		struct SH_E01_8fake *col; // $s3
	// 		long i; // $a3
	// 		long z; // stack offset -40
	// 		long f; // stack offset -36
	/* end block 1 */
	// End offset: 0x800454EC
	// End Line: 101

	/* begin block 2 */
		// Start line: 92
	/* end block 2 */
	// End Line: 93

/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void SHS01_Display(void)

{
  int iVar1;
  short sVar2;
  TASK *pTVar3;
  _SCREEN *p_Var4;
  undefined4 in_zero;
  undefined4 in_at;
  uint uVar5;
  ulong *puVar6;
  int *piVar7;
  short *psVar8;
  int iVar9;
  SHAPE_31fake *prim;
  int iVar10;
  void *local_a0;
  short local_9c;
  undefined4 local_98;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  short local_70 [2];
  short local_6c;
  short local_60;
  short local_5c;
  short local_50;
  short local_4c;
  short local_40;
  short local_3c;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  
  pTVar3 = TaskCurrent;
  uVar5 = (uint)*(ushort *)&TaskCurrent[2].destructor << 0x10;
  prim = (SHAPE_31fake *)(&TaskCurrent[3].bprec + (int)Scr_Frame * 10);
  memset(&local_30,0,8);
  local_a0 = (void *)pTVar3[2].s0;
  local_9c = *(short *)((int)&pTVar3[2].sp + 2);
  setCopReg(2,in_zero,pTVar3[1].s0);
  setCopReg(2,in_at,pTVar3[1].s1);
  copFunction(2,0x180001);
  local_98 = getCopReg(2,0xe);
  local_28 = getCopReg(2,0x9800);
  local_28 = local_28 >> 2;
  if ((0 < local_28) && (local_28 < (int)Scr_OtSize)) {
    Shp_SetPolyFT4(prim,(SHAPE_68fake *)&local_a0,0x32,0x32);
    prim->code = prim->code & 0xfe;
    prim->r0 = *(uchar *)&pTVar3[1].local;
    prim->g0 = *(uchar *)((int)&pTVar3[1].local + 1);
    prim->b0 = *(uchar *)((int)&pTVar3[1].local + 2);
    setCopReg(2,in_zero,local_30);
    setCopReg(2,in_at,local_2c);
    copFunction(2,0x486012);
    local_7c = getCopReg(2,0x19);
    local_78 = getCopReg(2,0x1a);
    local_74 = getCopReg(2,0x1b);
    RotMatrix((short *)&pTVar3[3].father,(undefined2 *)&local_90);
    setCopControlWord(2,0x2800,local_7c);
    setCopControlWord(2,0x3000,local_78);
    setCopControlWord(2,0x3800,local_74);
    setCopControlWord(2,0,local_90);
    setCopControlWord(2,0x800,local_8c);
    setCopControlWord(2,0x1000,local_88);
    setCopControlWord(2,0x1800,local_84);
    setCopControlWord(2,0x2000,local_80);
    iVar10 = ((int)(((int)uVar5 >> 0x10) + (uVar5 >> 0x1f)) >> 1) * (int)Scr_GeomScreen;
    if (local_28 == 0) {
      trap(0x1c00);
    }
    if ((local_28 == -1) && (iVar10 == -0x80000000)) {
      trap(0x1800);
    }
    iVar9 = 0;
    piVar7 = (int *)local_70;
    psVar8 = &Tab_Shoot;
    do {
      sVar2 = (short)(iVar10 / local_28);
      local_30 = CONCAT22(psVar8[1] * sVar2,*psVar8 * sVar2);
      setCopReg(2,in_zero,local_30);
      setCopReg(2,0x80000000,local_2c);
      copFunction(2,0x480012);
      iVar1 = getCopReg(2,0x19);
      *piVar7 = iVar1;
      iVar1 = getCopReg(2,0x1a);
      piVar7[1] = iVar1;
      iVar1 = getCopReg(2,0x1b);
      piVar7[2] = iVar1;
      getCopControlWord(2,0xf800);
      psVar8 = psVar8 + 4;
      *piVar7 = *piVar7 + (int)(short)local_98;
      iVar9 = iVar9 + 1;
      piVar7[1] = piVar7[1] + (int)local_98._2_2_;
      p_Var4 = Scr;
      piVar7 = piVar7 + 4;
    } while (iVar9 < 4);
    prim->x0 = local_70[0];
    prim->y0 = local_6c;
    prim->x1 = local_60;
    prim->y1 = local_5c;
    prim->x2 = local_50;
    prim->y2 = local_4c;
    prim->x3 = local_40;
    prim->y3 = local_3c;
    prim->tag = prim->tag & 0xff000000 | p_Var4->ot[local_28] & 0xffffff;
    puVar6 = p_Var4->ot + local_28;
    *puVar6 = *puVar6 & 0xff000000 | (uint)prim & 0xffffff;
    setCopControlWord(2,0x2800,Cam_Matrix.t[0]);
    setCopControlWord(2,0x3000,Cam_Matrix.t[1]);
    setCopControlWord(2,0x3800,Cam_Matrix.t[2]);
    setCopControlWord(2,0,Cam_Matrix.m[0]._0_4_);
    setCopControlWord(2,0x800,Cam_Matrix.m._4_4_);
    setCopControlWord(2,0x1000,Cam_Matrix.m[1]._2_4_);
    setCopControlWord(2,0x1800,Cam_Matrix.m[2]._0_4_);
    setCopControlWord(2,0x2000,Cam_Matrix._16_4_);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SHE02_Impact()
 // line 108, offset 0x80045510
	/* begin block 1 */
		// Start line: 109
		// Start offset: 0x80045510
		// Variables:
	// 		struct _SHOOT *sh; // $s0
	/* end block 1 */
	// End offset: 0x80045510
	// End Line: 109

	/* begin block 2 */
		// Start line: 292
	/* end block 2 */
	// End Line: 293

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SHE02_Impact(void)

{
  TASK *pTVar1;
  TASK *pTVar2;
  
  pTVar1 = TaskCurrent;
  Shoot_StopLoopingSound((_SHOOT *)TaskCurrent);
  Fx_Play(0x38,(char)pTVar1 + -0x44);
  pTVar2 = SFX_StreamTracingImpact((_D3_OBJECT *)(pTVar1 + 1),(char)pTVar1 + '4');
  *(TASK **)&pTVar1[2].s5 = pTVar2;
  Task_Sleep(10);
  Task_Kill((TASK *)pTVar1[2].s5);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SHE03_Move()
 // line 129, offset 0x8004556c
	/* begin block 1 */
		// Start line: 130
		// Start offset: 0x8004556C
		// Variables:
	// 		struct _SHOOT *sh; // $s1
	// 		struct SH_E01_7fake *angle; // $s5
	// 		struct _D3_OBJECT *owner; // $s3
	// 		struct _MONSTER *monst; // $s2
	// 		long i; // $s4
	// 		long counter; // $s6
	/* end block 1 */
	// End offset: 0x80045890
	// End Line: 212

	/* begin block 2 */
		// Start line: 335
	/* end block 2 */
	// End Line: 336

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SHE03_Move(void)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  ushort uVar5;
  TASK *t;
  TASK *pTVar6;
  int iVar7;
  int iVar8;
  long lVar9;
  TASK *pTVar10;
  TASK *pTVar11;
  int iVar12;
  int iVar13;
  
  t = TaskCurrent;
  iVar13 = 0x32;
  iVar12 = 0x1e;
  pTVar11 = TaskCurrent[2].bprec;
  pTVar10 = pTVar11[1].bprec;
  pTVar6 = SFX_StreamWarminMissile
                     ((_D3_OBJECT *)(TaskCurrent + 1),(char)TaskCurrent + '4',
                      *(short *)&TaskCurrent[2].destructor);
  *(TASK **)&t[2].s5 = pTVar6;
  do {
    if (((*(ushort *)&pTVar10->bnext & 4) == 0) || (Pvl_LevelNumber != 6)) {
      iVar7 = rcos((int)*(short *)&pTVar11->s5);
      iVar8 = rsin((int)*(short *)&pTVar11->s5);
      *(short *)&t[1].s0 =
           *(short *)&pTVar11->s0 +
           (short)(iVar7 * (int)*(short *)&pTVar10[1].event_param -
                   iVar8 * (int)*(short *)((int)&pTVar10[1].event_param + 2) >> 0xc);
      iVar7 = rsin((int)*(short *)&pTVar11->s5);
      iVar8 = rcos((int)*(short *)&pTVar11->s5);
      *(short *)((int)&t[1].s0 + 2) =
           *(short *)((int)&pTVar11->s0 + 2) +
           (short)(iVar7 * (int)*(short *)&pTVar10[1].event_param +
                   iVar8 * (int)*(short *)((int)&pTVar10[1].event_param + 2) >> 0xc);
      *(short *)&t[1].s1 = *(short *)&pTVar11->s1 + *(short *)&pTVar10[1].event_sp;
    }
    else {
      *(undefined2 *)&t[1].s0 = *(undefined2 *)&pTVar10[1].event_param;
      *(undefined2 *)((int)&t[1].s0 + 2) = *(undefined2 *)((int)&pTVar10[1].event_param + 2);
      *(undefined2 *)&t[1].s1 = *(undefined2 *)&pTVar10[1].event_sp;
    }
    **(undefined2 **)(t[2].s5 + 0xa0) = *(undefined2 *)&t[1].s0;
    *(undefined2 *)(*(int *)(t[2].s5 + 0xa0) + 2) = *(undefined2 *)((int)&t[1].s0 + 2);
    iVar12 = iVar12 + -1;
    *(undefined2 *)(*(int *)(t[2].s5 + 0xa0) + 4) = *(undefined2 *)&t[1].s1;
    Task_Next();
  } while (iVar12 != 0);
  pTVar6 = SFX_StreamMissile((_D3_OBJECT *)(t + 1));
  *(TASK **)&t[2].s6 = pTVar6;
  *(undefined2 *)((int)&t[2].local + 2) = 0xffff;
  if (((*(ushort *)&pTVar10->bnext & 4) != 0) && (iVar13 = 0x32, Pvl_LevelNumber == 6)) {
    iVar13 = 0x96;
  }
  do {
    if (iVar13 == 0) {
LAB_80045890:
      Task_EventExec(t,2,0);
      Task_Sleep(2);
      return;
    }
    Shoot_UpdateSound((_SHOOT *)t);
    sVar1 = *(short *)((int)&t[1].s0 + 2);
    sVar2 = *(short *)((int)&t[2].bnext + 2);
    *(short *)&t[1].s0 = *(short *)&t[1].s0 + *(short *)&t[2].bnext;
    sVar3 = *(short *)&t[1].s1;
    sVar4 = *(short *)&t[2].exec;
    *(short *)((int)&t[1].s0 + 2) = sVar1 + sVar2;
    uVar5 = *(ushort *)&t[2].display;
    *(short *)&t[1].s1 = sVar3 + sVar4;
    if ((uVar5 & 2) != 0) {
      *(short *)&t[2].exec = sVar4 + -2;
    }
    if ((((*(ushort *)&t[2].display & 1) != 0) &&
        (*(short *)&t[3].child = *(short *)&t[3].child + 200, (*(ushort *)&t[2].display & 0x10) != 0
        )) && (*(short *)&t[2].destructor < 0x21)) {
      *(short *)&t[2].destructor = *(short *)&t[2].destructor + 3;
    }
    if ((*(ushort *)&t[2].display & 0x80) != 0) {
      Shoot_SeekPlayer();
      *(short *)(t[2].s5 + 0xb4) = -*(short *)&t[2].bnext;
      *(short *)(t[2].s5 + 0xb6) = -*(short *)((int)&t[2].bnext + 2);
      *(short *)(t[2].s5 + 0xb8) = -*(short *)&t[2].exec;
    }
    lVar9 = Boxes_TestObject((_D3_OBJECT *)(t + 1));
    if (lVar9 != 0) {
      if ((*(ushort *)&t[2].display & 1) != 0) {
        Task_Sleep(2);
      }
      Shoot_SetVelocity((_SHOOT *)t);
      goto LAB_80045890;
    }
    iVar13 = iVar13 + -1;
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ SHE03_Impact()
 // line 217, offset 0x800458cc
	/* begin block 1 */
		// Start line: 218
		// Start offset: 0x800458CC
		// Variables:
	// 		struct _SHOOT *sh; // $s0
	/* end block 1 */
	// End offset: 0x800458CC
	// End Line: 218

	/* begin block 2 */
		// Start line: 615
	/* end block 2 */
	// End Line: 616

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SHE03_Impact(void)

{
  TASK *pTVar1;
  
  pTVar1 = TaskCurrent;
  Shoot_StopLoopingSound((_SHOOT *)TaskCurrent);
  TaskCurrent->display = (_func_11 *)0x0;
  SFX_Explosion((char)pTVar1 + -0x44,1,0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SHGE04_Init(struct _SHOOT *sh /*$s1*/)
 // line 274, offset 0x80045914
	/* begin block 1 */
		// Start line: 275
		// Start offset: 0x80045914
		// Variables:
	// 		long dist; // $s4
	// 		long height; // $s2
	// 		struct SH_E01_71fake *list; // $s5
	// 		struct SH_E01_70fake shp; // stack offset -48
	/* end block 1 */
	// End offset: 0x80045914
	// End Line: 275

	/* begin block 2 */
		// Start line: 732
	/* end block 2 */
	// End Line: 733

void SHGE04_Init(_SHOOT *sh)

{
  short sVar1;
  short sVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  _D3_OBJECT *o;
  int iVar6;
  int iVar7;
  SHAPE_68fake local_30;
  
  sVar1 = *(short *)(sh->type + 0x5e);
  iVar5 = (uint)*(ushort *)(sh->type + 0x5c) << 0x10;
  iVar4 = rcos((int)(sh->obj).rot.vz);
  iVar7 = iVar5 >> 0x10;
  iVar6 = (iVar7 / 0x14 + (iVar7 >> 0x1f)) - (iVar5 >> 0x1f);
  sVar2 = (sh->obj).rot.vz;
  *(short *)&(sh->shadow).tag = (short)(iVar4 * iVar6 >> 0xc);
  iVar4 = rsin((int)sVar2);
  pvVar3 = Effects_Pcl;
  iVar5 = ((int)sVar1 + -0x82) * 0x100;
  if (iVar7 == 0) {
    trap(0x1c00);
  }
  if ((iVar7 == -1) && (iVar5 == -0x80000000)) {
    trap(0x1800);
  }
  *(undefined4 *)(sh->type + 8) = 0;
  *(undefined4 *)(sh->type + 4) = 0;
  *(void **)&(sh->shadow).u2 = pvVar3;
  *(undefined2 *)((int)&(sh->shadow).tag + 2) = (short)(iVar4 * iVar6 >> 0xc);
  *(short *)&(sh->shadow).r0 = (short)((uint)((iVar5 / iVar7) * 0x32) >> 8) + 0x32;
  *(undefined4 *)&(sh->shadow).u3 = 0;
  *(_struct_241 **)&(sh->shadow).x3 = &(sh->obj).pos;
  (sh->obj).pos.pad = 0x5f0c;
  *(long **)&(sh->shadow).u3 = &(sh->obj).color;
  *(undefined2 *)sh->type = 1;
  *(undefined *)((int)&(sh->list).n_shapes + 1) = 0xe0;
  local_30.shape = 0x25;
  local_30.file = Pl_Pcl;
  Shp_SetPolyFT4((SHAPE_31fake *)(sh->type + 0xc),&local_30,0,0);
  Shp_SetPolyFT4((SHAPE_31fake *)(sh->type + 0x34),&local_30,0,0);
  o = &sh->obj;
  (sh->obj).comp_opt1 = 2;
  *(undefined2 *)((int)&(sh->obj).comp_opt4 + 2) = 0;
  D3_SetBox(o,-0x14,-0x14,-0x14,0x14,0x14,0x14);
  (sh->obj).hit_points = 0;
  D3_ClearCollBits(o,0xffff);
  D3_SetCollBits(o,1);
  (sh->obj).child = (_D3_OBJECT *)0x0;
  D3_InsertObject(o,&Pvl_EnemyShots);
  (sh->task).destructor = (_func_12 *)sh[2].task.event_s5;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SHGE04_Move()
 // line 323, offset 0x80045b04
	/* begin block 1 */
		// Start line: 324
		// Start offset: 0x80045B04
		// Variables:
	// 		struct _SHOOT *sh; // $s0
	// 		struct SH_E01_71fake *list; // $s5
	// 		long i; // $s1
	// 		long k; // $s3
	// 		long bounce; // $s4
	/* end block 1 */
	// End offset: 0x80045CA0
	// End Line: 365

	/* begin block 2 */
		// Start line: 894
	/* end block 2 */
	// End Line: 895

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SHGE04_Move(void)

{
  bool bVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  TASK *t;
  long lVar6;
  int iVar7;
  BOXES_106fake *pBVar8;
  int iVar9;
  int iVar10;
  
  t = TaskCurrent;
  iVar9 = 0;
  iVar10 = 4;
  do {
    *(short *)(t[2].s2 + 6) =
         ((short)iVar9 +
          ((short)((ulonglong)((longlong)iVar9 * 0x2aaaaaab) >> 0x20) - (short)(iVar9 >> 0x1f)) * -6
         + 0x5f) * 0x100 + 0xc;
    sVar2 = *(short *)&t[1].s0;
    *(short *)&t[2].exec = *(short *)&t[2].exec + -5;
    sVar3 = *(short *)((int)&t[1].s0 + 2);
    sVar4 = *(short *)((int)&t[2].bnext + 2);
    iVar9 = iVar9 + 1;
    *(short *)&t[1].s0 = sVar2 + *(short *)&t[2].bnext;
    sVar2 = *(short *)&t[1].s1;
    sVar5 = *(short *)&t[2].exec;
    *(short *)((int)&t[1].s0 + 2) = sVar3 + sVar4;
    *(short *)&t[1].s1 = sVar2 + sVar5;
    lVar6 = Boxes_TestObject((_D3_OBJECT *)(t + 1));
    if (lVar6 != 0) {
      Boxes_BounceObject((char)t + '4');
      iVar10 = iVar10 + -1;
      *(short *)&t[2].exec = *(short *)&t[2].exec >> 1;
      sVar2 = *(short *)((int)&t[2].bnext + 2);
      *(short *)&t[2].bnext = *(short *)&t[2].bnext >> 1;
      sVar3 = Boxes_nColls;
      bVar1 = Boxes_nColls != 0;
      *(short *)((int)&t[2].bnext + 2) = sVar2 >> 1;
      if ((bVar1) && (iVar7 = 0, pBVar8 = &Boxes_Colls, 0 < sVar3)) {
        do {
          if ((pBVar8->obj->collision_mode & 0x1000U) != 0) {
            Task_EventExec(t,2,0);
          }
          iVar7 = iVar7 + 1;
          pBVar8 = pBVar8 + 1;
        } while (iVar7 < (int)Boxes_nColls);
      }
      if (iVar10 == 0) {
        iVar9 = 0;
        do {
          iVar9 = iVar9 + 1;
          Task_Next();
        } while (iVar9 < 0x1e);
        Task_EventExec(t,2,0);
      }
    }
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ SHGE04_Impact()
 // line 368, offset 0x80045ca0
	/* begin block 1 */
		// Start line: 369
		// Start offset: 0x80045CA0
		// Variables:
	// 		struct _SHOOT *sh; // $a0
	/* end block 1 */
	// End offset: 0x80045CA0
	// End Line: 369

	/* begin block 2 */
		// Start line: 1032
	/* end block 2 */
	// End Line: 1033

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SHGE04_Impact(void)

{
  SFX_ExplodeObject((_D3_OBJECT *)(TaskCurrent + 1));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SHFE05_Init(struct _SHOOT *sh /*$s2*/)
 // line 382, offset 0x80045cc8
	/* begin block 1 */
		// Start line: 383
		// Start offset: 0x80045CC8
		// Variables:
	// 		struct SH_E01_71fake *list; // $s5
	// 		long i; // $s3
	// 		long vx; // $s1
	// 		long vy; // $s0
	// 		long vz; // $v1
	/* end block 1 */
	// End offset: 0x80045F2C
	// End Line: 420

	/* begin block 2 */
		// Start line: 1060
	/* end block 2 */
	// End Line: 1061

void SHFE05_Init(_SHOOT *sh)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  short sVar4;
  undefined4 uVar5;
  short sVar6;
  short sVar7;
  int iVar8;
  _SHOOT *p_Var9;
  
  iVar2 = rcos((int)(sh->obj).rot.vz);
  sVar1 = (sh->obj).rot.vz;
  *(short *)&(sh->shadow).tag = (short)((uint)(iVar2 * 5) >> 7);
  iVar2 = rsin((int)sVar1);
  sVar1 = (sh->obj).rot.vx;
  *(undefined2 *)((int)&(sh->shadow).tag + 2) = (short)((uint)(iVar2 * 5) >> 7);
  iVar2 = rsin((int)sVar1);
  *(short *)&(sh->shadow).r0 = (short)(iVar2 * -10 >> 9);
  (sh->obj).hit_points = 10;
  (sh->obj).collision_mode = 0;
  D3_SetCollBits(&sh->obj,0);
  *(undefined4 *)&(sh->shadow).u2 = *(undefined4 *)&(sh->shadow).x2;
  *(undefined4 *)&(sh->shadow).u3 = 0;
  *(byte **)&(sh->shadow).x3 = sh->type + 100;
  *(undefined2 *)sh->type = 0;
  uVar5 = *(undefined4 *)&(sh->obj).pos.vz;
  *(undefined4 *)(sh->type + 0x5c) = *(undefined4 *)&(sh->obj).pos;
  *(undefined4 *)(sh->type + 0x60) = uVar5;
  iVar8 = 0;
  iVar2 = rcos((int)(sh->obj).rot.vz);
  sVar1 = (sh->obj).rot.vz;
  *(short *)(sh->type + 0x5c) = *(short *)(sh->type + 0x5c) + (short)(iVar2 * 0x35 >> 0xc);
  iVar2 = rsin((int)sVar1);
  *(undefined2 *)(sh[1].type + 0x60) = 0x28;
  *(short *)(sh->type + 0x5e) = *(short *)(sh->type + 0x5e) + (short)(iVar2 * 0x35 >> 0xc);
  *(short *)(sh->type + 0x60) = *(short *)(sh->type + 0x60) + 0x96;
  p_Var9 = sh;
  do {
    uVar3 = M_rand();
    iVar2 = rcos(((int)(sh->obj).rot.vz + (uVar3 & 0xf)) - 8);
    sVar7 = (short)(iVar2 * 5 >> 10);
    p_Var9[1].obj.rot.vx = sVar7;
    uVar3 = M_rand();
    iVar2 = rsin(((int)(sh->obj).rot.vz + (uVar3 & 0xf)) - 8);
    sVar6 = (short)(iVar2 * 5 >> 10);
    p_Var9[1].obj.rot.vy = sVar6;
    uVar3 = M_rand();
    iVar2 = rsin(((int)(sh->obj).rot.vx + (uVar3 & 0xf)) - 8);
    sVar1 = (short)iVar8;
    sVar4 = (short)(iVar2 * 5 >> 10);
    p_Var9[1].obj.rot.vz = sVar4;
    iVar2 = iVar8 * 8;
    iVar8 = iVar8 + 1;
    *(short *)(iVar2 + *(int *)&(sh->shadow).x3) = *(short *)(sh->type + 0x5c) + sVar7 * sVar1;
    *(short *)(iVar2 + *(int *)&(sh->shadow).x3 + 2) = *(short *)(sh->type + 0x5e) + sVar6 * sVar1;
    *(short *)(iVar2 + *(int *)&(sh->shadow).x3 + 4) = *(short *)(sh->type + 0x60) + sVar4 * sVar1;
    *(ushort *)(iVar2 + *(int *)&(sh->shadow).x3 + 6) = (sh->shadow).y0 << 8 | 0xc;
    p_Var9 = (_SHOOT *)&(p_Var9->task).father;
  } while (iVar8 < 0x1e);
  (sh->task).destructor = (_func_12 *)sh[2].task.event_s5;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SHFE05_Destructor(struct TASK *t /*$a0*/)
 // line 424, offset 0x80045f5c
	/* begin block 1 */
		// Start line: 426
		// Start offset: 0x80045F5C
		// Variables:
	// 		struct _SHOOT *sh; // $a0
	// 		struct _MONSTER *monst; // $v1
	/* end block 1 */
	// End offset: 0x80045F98
	// End Line: 439

	/* begin block 2 */
		// Start line: 1190
	/* end block 2 */
	// End Line: 1191

void SHFE05_Destructor(TASK *t)

{
  TASK *pTVar1;
  
  pTVar1 = t[2].bprec;
  if ((pTVar1 != (TASK *)0x0) && (((int)*(short *)&pTVar1->sp & 0x8000U) != 0)) {
    *(ushort *)&(pTVar1[1].bprec)->bnext = *(ushort *)&(pTVar1[1].bprec)->bnext & 0xfdff;
  }
  t[1].bnext = (TASK *)0x0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SHFE05_Move()
 // line 443, offset 0x80045fa0
	/* begin block 1 */
		// Start line: 444
		// Start offset: 0x80045FA0
		// Variables:
	// 		struct _D3_OBJECT Hurt; // stack offset -240
	// 		struct _SHOOT *sh; // $s6
	// 		struct SH_E01_71fake *list; // $s4
	// 		struct _D3_OBJECT *owner; // stack offset -64
	// 		struct _MONSTER *monst; // stack offset -60
	// 		long i; // $s7
	// 		long cont; // stack offset -56
	// 		long j; // $s1
	// 		long cos; // $s0
	// 		long sin; // $s3
	// 		long FlameLength; // stack offset -52
	// 		long CurrentShape; // stack offset -48
	// 		struct SH_E01_7fake pos; // stack offset -72
	/* end block 1 */
	// End offset: 0x800468AC
	// End Line: 633

	/* begin block 2 */
		// Start line: 1223
	/* end block 2 */
	// End Line: 1224

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SHFE05_Move(void)

{
  byte bVar1;
  short sVar2;
  TASK *pTVar3;
  short sVar4;
  undefined4 *puVar5;
  uint uVar6;
  long lVar7;
  TASK **ppTVar8;
  short *psVar9;
  int iVar10;
  TASK *pTVar11;
  TASK *pTVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  undefined auStack240 [28];
  short local_d4;
  short local_d2;
  uchar local_ce;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined local_57;
  TASK *local_50;
  short local_48;
  short local_46;
  undefined2 local_44;
  TASK *local_40;
  TASK *local_3c;
  int local_38;
  int local_34;
  uint local_30;
  
  pTVar3 = TaskCurrent;
  local_3c = (TASK *)0x0;
  local_34 = 0x32;
  local_30 = 0;
  local_40 = TaskCurrent[2].bprec;
  memset(auStack240,0,0xa4);
  if (((int)*(short *)&local_40->sp & 0x8000U) == 0) {
    local_34 = (int)*(short *)&local_40[1].child * 5 >> 8;
    *(undefined2 *)&pTVar3[6].s5 = *(undefined2 *)((int)&local_40[1].child + 2);
  }
  else {
    local_3c = local_40[1].bprec;
  }
  D3_SetBox((_D3_OBJECT *)auStack240,-0x32,-0x32,-0x32,0x32,0x32,0x32);
  local_d4 = 3;
  local_57 = 0xf7;
  local_ce = '\x19';
  local_50 = local_40;
  while (sVar4 = *(short *)&pTVar3[6].s5 + -1, *(short *)&pTVar3[6].s5 = sVar4, sVar4 != -1) {
    lVar7 = local_40->s5;
    pTVar3[1].s4 = local_40->s4;
    pTVar3[1].s5 = lVar7;
    if (local_3c == (TASK *)0x0) {
      pTVar12 = (TASK *)pTVar3[1].s1;
      pTVar3[3].father = (TASK *)pTVar3[1].s0;
      pTVar3[3].child = pTVar12;
    }
    else {
      pTVar12 = (TASK *)local_40->s1;
      pTVar3[3].father = (TASK *)local_40->s0;
      pTVar3[3].child = pTVar12;
      iVar14 = rcos((int)*(short *)&pTVar3[1].s5);
      iVar13 = rsin((int)*(short *)&pTVar3[1].s5);
      *(short *)&pTVar3[3].father =
           *(short *)&pTVar3[3].father +
           (short)(iVar14 * (int)*(short *)&local_3c[1].event_param -
                   iVar13 * (int)*(short *)((int)&local_3c[1].event_param + 2) >> 0xc);
      sVar4 = *(short *)&pTVar3[3].child;
      *(short *)((int)&pTVar3[3].father + 2) =
           *(short *)((int)&pTVar3[3].father + 2) +
           (short)(iVar13 * (int)*(short *)&local_3c[1].event_param +
                   iVar14 * (int)*(short *)((int)&local_3c[1].event_param + 2) >> 0xc);
      *(short *)&pTVar3[3].child = sVar4 + *(short *)&local_3c[1].event_sp;
      *(short *)&pTVar3[1].s5 = *(short *)&pTVar3[1].s5 + *(short *)((int)&local_3c[1].event_sp + 2)
      ;
    }
    uVar15 = 0;
    if (0 < *(short *)&pTVar3[2].s4) {
      iVar14 = 0;
      pTVar12 = pTVar3;
      do {
        local_d2 = 0;
        puVar5 = (undefined4 *)(iVar14 + pTVar3[2].s2);
        local_bc = *puVar5;
        local_b8 = puVar5[1];
        psVar9 = (short *)(iVar14 + pTVar3[2].s2);
        bVar1 = *(byte *)(psVar9 + 3);
        iVar13 = 4;
        if (bVar1 < 4) {
          iVar13 = 1;
        }
        if (bVar1 < 10) {
          iVar13 = 2;
        }
        if (0x12 < bVar1) {
          iVar13 = 8;
        }
        *psVar9 = *psVar9 + (short)((int)*(short *)&pTVar12[4].event_s1 * iVar13 >> 2);
        iVar10 = iVar14 + pTVar3[2].s2;
        *(short *)(iVar10 + 2) =
             *(short *)(iVar10 + 2) +
             (short)((int)*(short *)((int)&pTVar12[4].event_s1 + 2) * iVar13 >> 2);
        iVar10 = iVar14 + pTVar3[2].s2;
        *(short *)(iVar10 + 6) = *(short *)(iVar10 + 6) + 2;
        puVar5 = (undefined4 *)(iVar14 + pTVar3[2].s2);
        local_c4 = *puVar5;
        local_c0 = puVar5[1];
        psVar9 = (short *)(iVar14 + pTVar3[2].s2);
        if (psVar9[2] != -0x400) {
          sVar4 = (short)((int)*(short *)&pTVar12[4].event_s1 * iVar13 >> 4);
          local_48 = *psVar9 + sVar4 * 4;
          sVar2 = (short)((int)*(short *)((int)&pTVar12[4].event_s1 + 2) * iVar13 >> 4);
          local_46 = *(short *)(iVar14 + pTVar3[2].s2 + 2) + sVar2 * 4;
          iVar13 = 0;
          local_44 = *(undefined2 *)(iVar14 + pTVar3[2].s2 + 4);
          do {
            lVar7 = Boxes_GetHeightPlatform((_D3_OBJECT *)0x0,0xb8);
            if ((int)*(short *)(iVar14 + pTVar3[2].s2 + 4) + 0x1e < lVar7) {
              if ((uVar15 & 3) == 0) {
                Impact_Smoke(0x44,0);
              }
              *(undefined2 *)(iVar14 + pTVar3[2].s2 + 4) = 0xfc00;
              break;
            }
            iVar13 = iVar13 + 1;
            local_48 = local_48 + sVar4;
            local_46 = local_46 + sVar2;
          } while (iVar13 < 4);
          if ((uVar15 & 7) == 0) {
            Boxes_TestObject((_D3_OBJECT *)auStack240);
            Main_Prims = D3_DisplayBox((_D3_OBJECT *)auStack240,Main_Prims);
          }
        }
        ppTVar8 = (TASK **)(iVar14 + pTVar3[2].s2);
        if (local_34 < (int)(uint)*(byte *)((int)ppTVar8 + 6)) {
          pTVar11 = pTVar3[3].child;
          *ppTVar8 = pTVar3[3].father;
          ppTVar8[1] = pTVar11;
          uVar6 = M_rand();
          local_30 = uVar15;
          iVar13 = rcos(((int)*(short *)&pTVar3[1].s5 + (uVar6 & 0xf)) - 8);
          *(short *)&pTVar12[4].event_s1 = (short)(iVar13 * 5 >> 10);
          uVar6 = M_rand();
          iVar13 = rsin(((int)*(short *)&pTVar3[1].s5 + (uVar6 & 0xf)) - 8);
          *(undefined2 *)((int)&pTVar12[4].event_s1 + 2) = (short)(iVar13 * 5 >> 10);
          *(ushort *)(iVar14 + pTVar3[2].s2 + 6) = *(short *)((int)&pTVar3[2].sp + 2) << 8 | 6;
        }
        pTVar12 = (TASK *)&pTVar12->father;
        uVar15 = uVar15 + 1;
        iVar14 = iVar14 + 8;
      } while ((int)uVar15 < (int)*(short *)&pTVar3[2].s4);
    }
    iVar14 = local_30 * 8;
    if ((int)local_30 < 0x1e) {
      ppTVar8 = (TASK **)(iVar14 + pTVar3[2].s2);
      pTVar12 = pTVar3[3].child;
      *ppTVar8 = pTVar3[3].father;
      ppTVar8[1] = pTVar12;
      iVar13 = local_30 * 2;
      uVar15 = M_rand();
      iVar10 = rcos(((int)*(short *)&pTVar3[1].s5 + (uVar15 & 0xf)) - 8);
      *(short *)(&pTVar3->prec + iVar13 + 0xac) = (short)(iVar10 * 5 >> 10);
      uVar15 = M_rand();
      iVar10 = rsin(((int)*(short *)&pTVar3[1].s5 + (uVar15 & 0xf)) - 8);
      *(undefined2 *)((int)(&pTVar3->prec + iVar13) + 0x2b2) = (short)(iVar10 * 5 >> 10);
      *(ushort *)(iVar14 + pTVar3[2].s2 + 6) = *(short *)((int)&pTVar3[2].sp + 2) << 8 | 6;
      local_30 = local_30 + 1;
      if ((int)*(short *)&pTVar3[2].s4 < (int)local_30) {
        *(short *)&pTVar3[2].s4 = *(short *)&pTVar3[2].s4 + 1;
      }
    }
    Task_Next();
    if ((local_3c != (TASK *)0x0) &&
       ((*(short *)&local_3c->bprec == 0x11 || ((*(ushort *)&local_3c->bnext & 0x200) == 0)))) {
      *(undefined2 *)&pTVar3[6].s5 = 0;
    }
  }
  do {
    uVar15 = 0;
    local_38 = 0;
    if (0 < *(short *)&pTVar3[2].s4) {
      iVar14 = 0;
      pTVar12 = pTVar3;
      do {
        local_d2 = 0;
        puVar5 = (undefined4 *)(iVar14 + pTVar3[2].s2);
        local_bc = *puVar5;
        local_b8 = puVar5[1];
        psVar9 = (short *)(iVar14 + pTVar3[2].s2);
        bVar1 = *(byte *)(psVar9 + 3);
        iVar13 = 4;
        if (bVar1 < 4) {
          iVar13 = 1;
        }
        if (bVar1 < 10) {
          iVar13 = 2;
        }
        if (0x12 < bVar1) {
          iVar13 = 8;
        }
        *psVar9 = *psVar9 + (short)((int)*(short *)&pTVar12[4].event_s1 * iVar13 >> 2);
        iVar10 = iVar14 + pTVar3[2].s2;
        *(short *)(iVar10 + 2) =
             *(short *)(iVar10 + 2) +
             (short)((int)*(short *)((int)&pTVar12[4].event_s1 + 2) * iVar13 >> 2);
        iVar10 = iVar14 + pTVar3[2].s2;
        *(short *)(iVar10 + 6) = *(short *)(iVar10 + 6) + 2;
        puVar5 = (undefined4 *)(iVar14 + pTVar3[2].s2);
        local_c4 = *puVar5;
        local_c0 = puVar5[1];
        psVar9 = (short *)(iVar14 + pTVar3[2].s2);
        if (psVar9[2] != -0x400) {
          sVar4 = (short)((int)*(short *)&pTVar12[4].event_s1 * iVar13 >> 4);
          local_48 = *psVar9 + sVar4 * 4;
          sVar2 = (short)((int)*(short *)((int)&pTVar12[4].event_s1 + 2) * iVar13 >> 4);
          local_46 = *(short *)(iVar14 + pTVar3[2].s2 + 2) + sVar2 * 4;
          iVar13 = 0;
          local_44 = *(undefined2 *)(iVar14 + pTVar3[2].s2 + 4);
          do {
            lVar7 = Boxes_GetHeightPlatform((_D3_OBJECT *)0x0,0xb8);
            if ((int)*(short *)(iVar14 + pTVar3[2].s2 + 4) + 0x1e < lVar7) {
              if ((uVar15 & 3) == 0) {
                Impact_Smoke(0x44,0);
              }
              *(undefined2 *)(iVar14 + pTVar3[2].s2 + 4) = 0xfc00;
              break;
            }
            iVar13 = iVar13 + 1;
            local_48 = local_48 + sVar4;
            local_46 = local_46 + sVar2;
          } while (iVar13 < 4);
          if ((uVar15 & 7) == 0) {
            Boxes_TestObject((_D3_OBJECT *)auStack240);
            Main_Prims = D3_DisplayBox((_D3_OBJECT *)auStack240,Main_Prims);
          }
        }
        iVar13 = iVar14 + pTVar3[2].s2;
        if (local_34 < (int)(uint)*(byte *)(iVar13 + 6)) {
          *(undefined2 *)(iVar13 + 4) = 0xfc00;
        }
        else {
          local_38 = 1;
        }
        iVar14 = iVar14 + 8;
        uVar15 = uVar15 + 1;
        pTVar12 = (TASK *)&pTVar12->father;
      } while ((int)uVar15 < (int)*(short *)&pTVar3[2].s4);
    }
    Task_Next();
    if (local_38 == 0) {
      return;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ SHE_LaserInitPrims(struct _SHOOT *sh /*$a0*/, struct SH_E01_8fake *col1 /*$a1*/, struct SH_E01_8fake *col2 /*$a2*/)
 // line 642, offset 0x800468dc
	/* begin block 1 */
		// Start line: 644
		// Start offset: 0x800468DC
		// Variables:
	// 		long i; // $t3
	// 		long j; // $t0
	/* end block 1 */
	// End offset: 0x80046A60
	// End Line: 679

	/* begin block 2 */
		// Start line: 1816
	/* end block 2 */
	// End Line: 1817

void SHE_LaserInitPrims(_SHOOT *sh,undefined col1,undefined col2)

{
  undefined uVar1;
  int iVar2;
  undefined3 in_register_00000015;
  undefined *puVar3;
  undefined3 in_register_00000019;
  undefined *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  puVar4 = (undefined *)CONCAT31(in_register_00000019,col2);
  puVar3 = (undefined *)CONCAT31(in_register_00000015,col1);
  iVar8 = 0;
  iVar6 = 0x218;
  iVar7 = 0x1b8;
  do {
    iVar5 = 0;
    iVar2 = (int)&(sh->task).prec + iVar7;
    do {
      *(undefined *)(iVar2 + 3) = 5;
      *(undefined *)(iVar2 + 7) = 0x28;
      *(undefined *)(iVar2 + 4) = *puVar3;
      *(undefined *)(iVar2 + 5) = puVar3[1];
      iVar5 = iVar5 + 1;
      *(undefined *)(iVar2 + 6) = puVar3[2];
      iVar2 = iVar2 + 0x18;
    } while (iVar5 < 2);
    iVar5 = 0;
    iVar2 = (int)&(sh->task).prec + iVar6;
    do {
      *(undefined *)(iVar2 + 3) = 8;
      *(undefined *)(iVar2 + 7) = 0x38;
      *(undefined *)(iVar2 + 4) = 0;
      *(undefined *)(iVar2 + 5) = 0;
      *(undefined *)(iVar2 + 6) = 0;
      *(undefined *)(iVar2 + 0x14) = 0;
      *(undefined *)(iVar2 + 0x15) = 0;
      *(undefined *)(iVar2 + 0x16) = 0;
      *(undefined *)(iVar2 + 0xc) = *puVar4;
      *(undefined *)(iVar2 + 0xd) = puVar4[1];
      *(undefined *)(iVar2 + 0xe) = puVar4[2];
      *(undefined *)(iVar2 + 0x1c) = *puVar4;
      iVar5 = iVar5 + 1;
      *(undefined *)(iVar2 + 0x1d) = puVar4[1];
      uVar1 = puVar4[2];
      *(byte *)(iVar2 + 7) = *(byte *)(iVar2 + 7) | 2;
      *(undefined *)(iVar2 + 0x1e) = uVar1;
      iVar2 = iVar2 + 0x24;
    } while (iVar5 < 3);
    iVar5 = 3;
    iVar2 = (int)&(sh->task).event_s0 + iVar6;
    do {
      *(undefined *)(iVar2 + 3) = 8;
      *(undefined *)(iVar2 + 7) = 0x38;
      *(undefined *)(iVar2 + 0xc) = 0;
      *(undefined *)(iVar2 + 0xd) = 0;
      *(undefined *)(iVar2 + 0xe) = 0;
      *(undefined *)(iVar2 + 0x1c) = 0;
      *(undefined *)(iVar2 + 0x1d) = 0;
      *(undefined *)(iVar2 + 0x1e) = 0;
      *(undefined *)(iVar2 + 4) = *puVar4;
      *(undefined *)(iVar2 + 5) = puVar4[1];
      *(undefined *)(iVar2 + 6) = puVar4[2];
      *(undefined *)(iVar2 + 0x14) = *puVar4;
      iVar5 = iVar5 + 1;
      *(undefined *)(iVar2 + 0x15) = puVar4[1];
      uVar1 = puVar4[2];
      *(byte *)(iVar2 + 7) = *(byte *)(iVar2 + 7) | 2;
      *(undefined *)(iVar2 + 0x16) = uVar1;
      iVar2 = iVar2 + 0x24;
    } while (iVar5 < 6);
    iVar6 = iVar6 + 0xd8;
    iVar8 = iVar8 + 1;
    iVar7 = iVar7 + 0x30;
  } while (iVar8 < 2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SHE_LaserInitVertices(struct SH_E01_7fake *pos /*$a0*/)
 // line 682, offset 0x80046a68
	/* begin block 1 */
		// Start line: 683
		// Start offset: 0x80046A68
		// Variables:
	// 		long dx; // $t4
	// 		long dy; // $t5
	// 		long nx; // $t2
	// 		long ny; // $t3
	// 		long z; // $v1
	// 		long rate; // $s0
	/* end block 1 */
	// End offset: 0x80046D68
	// End Line: 740

	/* begin block 2 */
		// Start line: 1951
	/* end block 2 */
	// End Line: 1952

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void SHE_LaserInitVertices(undefined pos)

{
  short sVar1;
  short sVar2;
  int iVar3;
  undefined3 in_register_00000011;
  int iVar4;
  int iVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  short sVar9;
  
  GtxTmd_RotTransPersN(CONCAT31(in_register_00000011,pos),Tmd_2D,2);
  iVar4 = (int)Tmd_2D[1].vx - (int)Tmd_2D->vx;
  iVar5 = (int)Tmd_2D[1].vy - (int)Tmd_2D->vy;
  if (iVar4 == 0) {
    iVar4 = 10;
  }
  if (iVar5 == 0) {
    iVar5 = 10;
  }
  if ((int)Tmd_2D->vz * 2 < 1) {
    iVar3 = 10;
  }
  else {
    iVar3 = (int)Tmd_2D->vz * 0x14;
  }
  _sVar6 = (iVar5 * 300) / iVar3;
  sVar6 = (short)_sVar6;
  if (iVar3 == 0) {
    trap(0x1c00);
  }
  if ((iVar3 == -1) && (iVar5 * 300 == -0x80000000)) {
    trap(0x1800);
  }
  _sVar7 = (iVar4 * 300) / iVar3;
  sVar7 = (short)_sVar7;
  if (iVar3 == 0) {
    trap(0x1c00);
  }
  if ((iVar3 == -1) && (iVar4 * 300 == -0x80000000)) {
    trap(0x1800);
  }
  if (_sVar6 < 0) {
    _sVar6 = -_sVar6;
  }
  if (((_sVar6 < 1) && (iVar4 != 0)) && (sVar6 = -1, 0 < iVar4)) {
    sVar6 = 1;
  }
  if (_sVar7 < 0) {
    _sVar7 = -_sVar7;
  }
  if (((_sVar7 < 1) && (iVar5 != 0)) && (sVar7 = -1, 0 < iVar5)) {
    sVar7 = 1;
  }
  iVar4 = iVar4 / 10;
  sVar1 = (short)iVar4;
  _DAT_800b1eac = Tmd_2D->vx - sVar1;
  iVar5 = iVar5 / 10;
  sVar2 = (short)iVar5;
  _DAT_800b1eae = Tmd_2D->vy - sVar2;
  _DAT_800b1eb0 = Tmd_2D->vx + sVar6;
  _DAT_800b1eb2 = Tmd_2D->vy - sVar7;
  _DAT_800b1eb4 = Tmd_2D->vx - sVar6;
  _DAT_800b1eb6 = Tmd_2D->vy + sVar7;
  iVar3 = (int)Tmd_2D[1].vz << 1;
  if (iVar3 < 1) {
    iVar3 = 1;
  }
  _sVar6 = (iVar5 * 300) / iVar3;
  sVar8 = (short)_sVar6;
  if (iVar3 == 0) {
    trap(0x1c00);
  }
  if ((iVar3 == -1) && (iVar5 * 300 == -0x80000000)) {
    trap(0x1800);
  }
  _sVar7 = (iVar4 * 300) / iVar3;
  sVar9 = (short)_sVar7;
  if (iVar3 == 0) {
    trap(0x1c00);
  }
  if ((iVar3 == -1) && (iVar4 * 300 == -0x80000000)) {
    trap(0x1800);
  }
  if (_sVar6 < 0) {
    _sVar6 = -_sVar6;
  }
  if (((_sVar6 < 1) && (iVar4 != 0)) && (sVar8 = -1, 0 < iVar4)) {
    sVar8 = 1;
  }
  if (_sVar7 < 0) {
    _sVar7 = -_sVar7;
  }
  if (((_sVar7 < 1) && (iVar5 != 0)) && (sVar9 = -1, 0 < iVar5)) {
    sVar9 = 1;
  }
  _DAT_800b1eb8 = Tmd_2D[1].vx + sVar8;
  _DAT_800b1eba = Tmd_2D[1].vy - sVar9;
  _DAT_800b1ebc = Tmd_2D[1].vx + sVar1;
  _DAT_800b1ebe = Tmd_2D[1].vy + sVar2;
  _DAT_800b1ec0 = Tmd_2D[1].vx - sVar8;
  _DAT_800b1ec2 = Tmd_2D[1].vy + sVar9;
  _ray = _DAT_800b1eac - sVar1;
  _DAT_800b1ea2 = _DAT_800b1eae - sVar2;
  _DAT_800b1ea4 = _DAT_800b1eb0 + sVar6 * 6;
  _DAT_800b1ea6 = _DAT_800b1eb2 + sVar7 * -6;
  _DAT_800b1ea8 = _DAT_800b1eb4 + sVar6 * -6;
  _DAT_800b1eaa = _DAT_800b1eb6 + sVar7 * 6;
  _DAT_800b1ec4 = _DAT_800b1eb8 + sVar8 * 6;
  _DAT_800b1ec6 = _DAT_800b1eba + sVar9 * -6;
  _DAT_800b1ec8 = _DAT_800b1ebc + sVar1;
  _DAT_800b1eca = _DAT_800b1ebe + sVar2;
  _DAT_800b1ecc = _DAT_800b1ec0 + sVar8 * -6;
  _DAT_800b1ece = _DAT_800b1ec2 + sVar9 * 6;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SHE_LaserSetPrims(struct _SHOOT *sh /*$a0*/)
 // line 759, offset 0x80046e10
	/* begin block 1 */
		// Start line: 760
		// Start offset: 0x80046E10
		// Variables:
	// 		struct SH_E01_29fake *pf4; // $s0
	// 		struct SH_E01_33fake *pg4; // $s1
	// 		long i; // $a1
	/* end block 1 */
	// End offset: 0x80046FBC
	// End Line: 792

	/* begin block 2 */
		// Start line: 2282
	/* end block 2 */
	// End Line: 2283

void SHE_LaserSetPrims(_SHOOT *sh)

{
  int iVar1;
  short *psVar2;
  short *psVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar1 = (int)Scr_Frame;
  SHE_LaserInitVertices((char)sh + '(');
  iVar5 = 0;
  puVar4 = (undefined4 *)(sh->type + iVar1 * 0x30 + 0x70);
  iVar8 = 6;
  iVar7 = 4;
  iVar6 = 2;
  psVar3 = &ray_vert;
  do {
    puVar4[-3] = *(undefined4 *)(&ray + (int)*psVar3 * 4);
    psVar2 = (short *)((int)&ray_vert + iVar8);
    iVar8 = iVar8 + 8;
    puVar4[-2] = *(undefined4 *)(&ray + (int)*(short *)((int)&ray_vert + iVar6) * 4);
    psVar3 = psVar3 + 4;
    iVar5 = iVar5 + 4;
    puVar4[-1] = *(undefined4 *)(&ray + (int)*(short *)((int)&ray_vert + iVar7) * 4);
    iVar6 = iVar6 + 8;
    iVar7 = iVar7 + 8;
    *puVar4 = *(undefined4 *)(&ray + (int)*psVar2 * 4);
    puVar4 = puVar4 + 6;
  } while (iVar5 < 8);
  iVar5 = 8;
  puVar4 = (undefined4 *)((int)&sh[1].task + iVar1 * 0xd8 + 0x54);
  iVar7 = 0x16;
  iVar6 = 0x14;
  iVar1 = 0x12;
  psVar3 = &SHORT_800ad5f8;
  do {
    puVar4[-6] = *(undefined4 *)(&ray + (int)*psVar3 * 4);
    psVar2 = (short *)((int)&ray_vert + iVar7);
    iVar7 = iVar7 + 8;
    puVar4[-4] = *(undefined4 *)(&ray + (int)*(short *)((int)&ray_vert + iVar1) * 4);
    psVar3 = psVar3 + 4;
    iVar5 = iVar5 + 4;
    puVar4[-2] = *(undefined4 *)(&ray + (int)*(short *)((int)&ray_vert + iVar6) * 4);
    iVar1 = iVar1 + 8;
    iVar6 = iVar6 + 8;
    *puVar4 = *(undefined4 *)(&ray + (int)*psVar2 * 4);
    puVar4 = puVar4 + 9;
  } while (iVar5 < 0x20);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SHE_LaserDisplayHilite(struct SH_E01_7fake *pos /*$a0*/, struct SH_E01_31fake *p /*$s0*/)
 // line 794, offset 0x80046fd0
	/* begin block 1 */
		// Start line: 795
		// Start offset: 0x80046FD0
		// Variables:
	// 		struct SH_E01_70fake shp; // stack offset -32
	// 		long z; // stack offset -16
	/* end block 1 */
	// End offset: 0x80047134
	// End Line: 819

	/* begin block 2 */
		// Start line: 2408
	/* end block 2 */
	// End Line: 2409

/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void SHE_LaserDisplayHilite(undefined pos,undefined p)

{
  undefined4 uVar1;
  short sVar2;
  _SCREEN *p_Var3;
  undefined4 in_zero;
  undefined4 in_at;
  undefined3 in_register_00000011;
  undefined3 in_register_00000015;
  SHAPE_31fake *prim;
  uint uVar4;
  void *local_20;
  short local_1c;
  undefined4 local_18;
  int local_10;
  
  prim = (SHAPE_31fake *)CONCAT31(in_register_00000015,p);
  local_1c = 0xe6;
  local_20 = Effects_Pcl;
  setCopReg(2,in_zero,*(undefined4 *)CONCAT31(in_register_00000011,pos));
  setCopReg(2,in_at,((undefined4 *)CONCAT31(in_register_00000011,pos))[1]);
  copFunction(2,0x180001);
  uVar1 = getCopReg(2,0xe);
  local_10 = getCopReg(2,0x9800);
  local_10 = local_10 >> 2;
  if ((0 < local_10) && (local_10 < (int)Scr_OtSize)) {
    uVar4 = ((int)Scr_GeomScreen * 0x19) / local_10;
    if (local_10 == 0) {
      trap(0x1c00);
    }
    if ((local_10 == -1) && ((int)Scr_GeomScreen * 0x19 == -0x80000000)) {
      trap(0x1800);
    }
    local_18._2_2_ = (short)((uint)uVar1 >> 0x10);
    local_18._0_2_ = (short)uVar1;
    sVar2 = (short)((int)(uVar4 + (uVar4 >> 0x1f)) >> 1);
    local_18 = CONCAT22(local_18._2_2_ - sVar2,(short)local_18 - sVar2);
    Shp_SetPolyFT4(prim,(SHAPE_68fake *)&local_20,(short)uVar4,(short)uVar4);
    prim->code = prim->code | 2;
    p_Var3 = Scr;
    prim->tag = prim->tag & 0xff000000 | Scr->ot[local_10] & 0xffffff;
    p_Var3->ot[local_10] = p_Var3->ot[local_10] & 0xff000000 | (uint)prim & 0xffffff;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SHE_DisplayLaser()
 // line 821, offset 0x80047144
	/* begin block 1 */
		// Start line: 822
		// Start offset: 0x80047144
		// Variables:
	// 		struct _SHOOT *sh; // $s2
	// 		struct SH_E01_29fake *pf4; // $s0
	// 		struct SH_E01_33fake *pg4; // $s1
	// 		long i; // $a2
	// 		long z; // $a1
	/* end block 1 */
	// End offset: 0x80047330
	// End Line: 846

	/* begin block 2 */
		// Start line: 2483
	/* end block 2 */
	// End Line: 2484

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SHE_DisplayLaser(void)

{
  TASK *pTVar1;
  _SCREEN *p_Var2;
  _SCREEN *p_Var3;
  int iVar4;
  ulong *puVar5;
  int iVar6;
  TASK **ppTVar7;
  uint *puVar8;
  
  pTVar1 = TaskCurrent;
  ppTVar7 = &TaskCurrent[3].father + (int)Scr_Frame * 0xc;
  puVar8 = (uint *)((int)TaskCurrent + (int)Scr_Frame * 0xd8 + 0x218);
  SHE_LaserSetPrims((_SHOOT *)TaskCurrent);
  p_Var2 = Scr;
  iVar6 = (uint)(ushort)Tmd_2D->vz << 0x10;
  iVar4 = (uint)(ushort)Tmd_2D[1].vz << 0x10;
  if (iVar4 <= iVar6) {
    iVar6 = iVar4;
  }
  iVar6 = iVar6 >> 0x12;
  if ((0 < iVar6) && (iVar4 = 0, iVar6 < (int)Scr_OtSize + -1)) {
    do {
      iVar4 = iVar4 + 1;
      *ppTVar7 = (TASK *)((uint)*ppTVar7 & 0xff000000 | p_Var2->ot[iVar6] & 0xffffff);
      puVar5 = p_Var2->ot + iVar6;
      *puVar5 = *puVar5 & 0xff000000 | (uint)ppTVar7 & 0xffffff;
      p_Var3 = Scr;
      ppTVar7 = ppTVar7 + 6;
    } while (iVar4 < 2);
    iVar4 = 0;
    do {
      iVar4 = iVar4 + 1;
      *puVar8 = *puVar8 & 0xff000000 | p_Var3->ot[iVar6] & 0xffffff;
      puVar5 = p_Var3->ot + iVar6;
      *puVar5 = *puVar5 & 0xff000000 | (uint)puVar8 & 0xffffff;
      p_Var2 = Scr;
      puVar8 = puVar8 + 9;
    } while (iVar4 < 6);
    iVar4 = (int)Scr_Frame;
    ppTVar7 = &pTVar1->prec + iVar4 * 2;
    ppTVar7[0xf2] = (TASK *)((uint)ppTVar7[0xf2] & 0xff000000 | Scr->ot[iVar6] & 0xffffff);
    p_Var2->ot[iVar6] =
         p_Var2->ot[iVar6] & 0xff000000 | (uint)(&pTVar1[6].event_ra + iVar4 * 2) & 0xffffff;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SHE07_Init(struct _SHOOT *sh /*$s1*/)
 // line 851, offset 0x80047348
	/* begin block 1 */
		// Start line: 852
		// Start offset: 0x80047348
		// Variables:
	// 		struct _D3_OBJECT *obj; // $s2
	// 		struct SH_E01_8fake col1; // stack offset -24
	// 		long i; // $a2
	/* end block 1 */
	// End offset: 0x800475A0
	// End Line: 893

	/* begin block 2 */
		// Start line: 2548
	/* end block 2 */
	// End Line: 2549

void SHE07_Init(_SHOOT *sh)

{
  uchar uVar1;
  short sVar2;
  undefined2 uVar3;
  TASK *pTVar4;
  uint uVar5;
  _SHOOT *p_Var6;
  int iVar7;
  _func_13 *p_Var8;
  _D3_OBJECT *o;
  
  o = &sh->obj;
  iVar7 = 0;
  p_Var6 = sh;
  do {
    uVar5 = 0xe1000000;
    p_Var8 = *(_func_13 **)&(sh->obj).pos.vz;
    p_Var6[2].task.event_sp = *(void **)&(sh->obj).pos;
    p_Var6[2].task.event_exec = p_Var8;
    *(undefined *)((int)&p_Var6[2].task.prec + 3) = 1;
    if (Scr_Dtd != 0) {
      uVar5 = 0xe1000200;
    }
    pTVar4 = (TASK *)(uVar5 | 0x420);
    if (Scr_Dfe == 0) {
      pTVar4 = (TASK *)(uVar5 | 0x20);
    }
    p_Var6[2].task.next = pTVar4;
    iVar7 = iVar7 + 1;
    p_Var6 = (_SHOOT *)&(p_Var6->task).father;
  } while (iVar7 < 2);
  if (*(short *)&(sh->shadow).u0 == 0) {
    iVar7 = rcos((int)(sh->obj).rot.vz);
    sVar2 = (sh->obj).rot.vz;
    *(short *)&(sh->shadow).tag = (short)((iVar7 * 100) / 3 >> 10);
    iVar7 = rsin((int)sVar2);
    sVar2 = (sh->obj).rot.vx;
    *(undefined2 *)((int)&(sh->shadow).tag + 2) = (short)((iVar7 * 100) / 3 >> 10);
    iVar7 = rsin((int)sVar2);
    *(short *)&(sh->shadow).r0 = (short)((iVar7 * 100) / 3 >> 10);
  }
  else {
    iVar7 = rcos((int)(sh->obj).rot.vz);
    sVar2 = (sh->obj).rot.vz;
    *(short *)&(sh->shadow).tag = (short)((iVar7 * 100) / 9 >> 10);
    iVar7 = rsin((int)sVar2);
    sVar2 = (sh->obj).rot.vx;
    *(undefined2 *)((int)&(sh->shadow).tag + 2) = (short)((iVar7 * 100) / 9 >> 10);
    iVar7 = rsin((int)sVar2);
    *(short *)&(sh->shadow).r0 = (short)((iVar7 * 100) / 9 >> 10);
  }
  uVar3 = *(undefined2 *)&(sh->shadow).u0;
  *(undefined4 *)(sh->type + 8) = 0;
  *(undefined4 *)(sh->type + 4) = 0;
  *(undefined2 *)&(sh->shadow).b0 = uVar3;
  (sh->obj).display_mode = 0x20;
  D3_ClearCollBits(o,0xffff);
  D3_SetCollBits(o,0x2b);
  uVar1 = (sh->obj).hit_power;
  *(undefined *)((int)&(sh->list).n_shapes + 1) = 0xe0;
  if (uVar1 == '\0') {
    (sh->obj).hit_power = '\x05';
  }
  (sh->obj).child = (_D3_OBJECT *)0x0;
  SHE_LaserInitPrims(sh,0xe8,(char)sh + -0x48);
  D3_InsertObject(o,&Pvl_EnemyShots);
  (sh->task).destructor = (_func_12 *)sh[2].task.event_s5;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SHE07_Move()
 // line 900, offset 0x800475e8
	/* begin block 1 */
		// Start line: 901
		// Start offset: 0x800475E8
		// Variables:
	// 		struct _SHOOT *sh; // $s0
	// 		struct SH_E01_7fake *pos; // $s2
	// 		struct SH_E01_7fake *pos2; // $s1
	// 		struct _PLATFORM *plat; // $v0
	// 		long cont; // $s3
	/* end block 1 */
	// End offset: 0x80047750
	// End Line: 943

	/* begin block 2 */
		// Start line: 2673
	/* end block 2 */
	// End Line: 2674

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SHE07_Move(void)

{
  TASK *t;
  _PLATFORM *p_Var1;
  long lVar2;
  long *plVar3;
  long *plVar4;
  int iVar5;
  
  t = TaskCurrent;
  iVar5 = 0x27;
  plVar4 = &TaskCurrent[7].s3;
  plVar3 = &TaskCurrent[7].s5;
  do {
    *(short *)plVar4 = *(short *)plVar4 + *(short *)&t[2].bnext;
    *(short *)((int)&t[7].s3 + 2) = *(short *)((int)&t[7].s3 + 2) + *(short *)((int)&t[2].bnext + 2)
    ;
    *(short *)&t[7].s4 = *(short *)&t[7].s4 + *(short *)&t[2].exec;
    lVar2 = t[7].s4;
    t[1].s0 = *plVar4;
    t[1].s1 = lVar2;
    if (iVar5 < 0x25) {
      *(short *)plVar3 = *(short *)plVar3 + *(short *)&t[2].bnext;
      *(short *)((int)&t[7].s5 + 2) =
           *(short *)((int)&t[7].s5 + 2) + *(short *)((int)&t[2].bnext + 2);
      *(short *)&t[7].s6 = *(short *)&t[7].s6 + *(short *)&t[2].exec;
    }
    else {
      SHE_LaserDisplayHilite((char)plVar3,(char)t + (char)Scr_Frame * '(' + -0x28);
    }
    p_Var1 = Plat_GetPlat((char)t + -0x44);
    if ((p_Var1 != (_PLATFORM *)0x0) && (*(short *)&t[1].s1 <= *(short *)&p_Var1[1].obj.prec)) {
      Task_EventExec(t,2,0);
    }
    lVar2 = Boxes_TestObject((_D3_OBJECT *)(t + 1));
    if (lVar2 != 0) {
      Shoot_SetVelocity((_SHOOT *)t);
      Task_EventExec(t,2,0);
    }
    iVar5 = iVar5 + -1;
    Task_Next();
  } while (iVar5 != -1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SHE07_Impact()
 // line 946, offset 0x8004776c
	/* begin block 1 */
		// Start line: 947
		// Start offset: 0x8004776C
		// Variables:
	// 		struct _SHOOT *sh; // $v0
	// 		struct SH_E01_71fake *list; // $s0
	// 		long i; // $s1
	/* end block 1 */
	// End offset: 0x8004784C
	// End Line: 972

	/* begin block 2 */
		// Start line: 2775
	/* end block 2 */
	// End Line: 2776

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SHE07_Impact(void)

{
  TASK *pTVar1;
  TASK *pTVar2;
  undefined4 uVar3;
  void *pvVar4;
  TASK *pTVar5;
  int iVar6;
  int iVar7;
  
  pTVar5 = TaskCurrent;
  pvVar4 = Effects_Pcl;
  iVar7 = 0;
  pTVar1 = TaskCurrent + 1;
  pTVar2 = TaskCurrent + 2;
  TaskCurrent->display = (_func_11 *)0x0;
  *(void **)&pTVar5[2].s1 = pvVar4;
  pTVar5[2].s3 = 0;
  *(long **)&pTVar5[2].s2 = &pTVar1->s0;
  *(undefined2 *)&pTVar5[2].s4 = 1;
  Fx_Play(0x3d,(char)&pTVar1->s0);
  do {
    pvVar4 = Main_Prims;
    *(ushort *)(pTVar5[2].s2 + 6) = ((short)(iVar7 / 5) + 0x9b) * 0x100 | 0x14;
    uVar3 = Main_TextContext.Font.ascii_tab._20_4_;
    iVar6 = (int)Scr_OtSize;
    *(short *)(pTVar5[2].s2 + 4) = *(short *)(pTVar5[2].s2 + 4) + 3;
    iVar7 = iVar7 + 1;
    Main_Prims = (void *)GtxShp_DisplayListLOFF(&pTVar2->s1,pvVar4,Scr->ot,iVar6,0,uVar3);
    Task_Next();
  } while (iVar7 < 0x1e);
  return;
}





