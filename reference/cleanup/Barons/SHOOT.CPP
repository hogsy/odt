#include "THISDUST.H"
#include "SHOOT.H"


// decompiled code
// original method signature: 
// struct _SHOOT * /*$ra*/ Shoot_Add(struct _D3_OBJECT *owner /*$s1*/, struct SHOOT_7fake *pos /*$s4*/, struct SHOOT_7fake *rot /*$s7*/, struct SHOOT_8fake *col /*$s3*/, long number /*stack 16*/, long size /*stack 20*/, long power /*stack 24*/, long mode /*stack 28*/)
 // line 69, offset 0x800436f4
	/* begin block 1 */
		// Start line: 70
		// Start offset: 0x800436F4
		// Variables:
	// 		struct _SHOOT *t; // $s0
	// 		long color; // $s5
	/* end block 1 */
	// End offset: 0x8004384C
	// End Line: 101

	/* begin block 2 */
		// Start line: 138
	/* end block 2 */
	// End Line: 139

_SHOOT * Shoot_Add(_D3_OBJECT *owner,undefined pos,undefined rot,undefined col,long number,long size
                  ,long power,long mode)

{
  _SHOOT *sh;
  void *pvVar1;
  undefined3 in_register_00000015;
  undefined4 *puVar2;
  undefined3 in_register_00000019;
  undefined4 *puVar3;
  undefined3 in_register_0000001d;
  long *plVar4;
  undefined4 uVar5;
  
  plVar4 = (long *)CONCAT31(in_register_0000001d,col);
  puVar3 = (undefined4 *)CONCAT31(in_register_00000019,rot);
  puVar2 = (undefined4 *)CONCAT31(in_register_00000015,pos);
  sh = (_SHOOT *)Task_Link(Shoot_Task,0x74c);
  if (owner == (_D3_OBJECT *)0x0) {
    uVar5 = puVar2[1];
    *(undefined4 *)&(sh->obj).last_pos = *puVar2;
    *(undefined4 *)&(sh->obj).last_pos.vz = uVar5;
  }
  else {
    Boxes_GetCenter(owner,(char)sh + -0x3c);
  }
  uVar5 = puVar2[1];
  *(undefined4 *)&(sh->obj).pos = *puVar2;
  *(undefined4 *)&(sh->obj).pos.vz = uVar5;
  uVar5 = puVar3[1];
  *(undefined4 *)&(sh->obj).rot = *puVar3;
  *(undefined4 *)&(sh->obj).rot.vz = uVar5;
  *(_D3_OBJECT **)&sh->handle2 = owner;
  (sh->obj).hit_power = (uchar)power;
  if (plVar4 == (long *)0x0) {
    (sh->obj).color = 0x808080;
  }
  else {
    (sh->obj).color = *plVar4;
  }
  *(undefined2 *)((int)&sh->handle1 + 2) = 0xc0;
  sh->speed = 0;
  if ((mode & 0x200U) == 0) {
    (sh->task).local = (void *)0x0;
  }
  else {
    *(long *)&(sh->task).local = power;
    (sh->obj).hit_power = *(uchar *)(power + 0x22);
    if (plVar4 == (long *)0x0) {
      *(undefined4 *)(power + 0x28) = 0x808080;
    }
    else {
      *(long *)(power + 0x28) = *plVar4;
    }
    pvVar1 = (sh->task).local;
    uVar5 = puVar3[1];
    *(undefined4 *)((int)pvVar1 + 0x3c) = *puVar3;
    *(undefined4 *)((int)pvVar1 + 0x40) = uVar5;
  }
  Shoot_SetAspect(sh,number,size,mode);
  Shoot_SetFunctions(sh);
  return sh;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Shoot_Task()
 // line 115, offset 0x80043898
	/* begin block 1 */
		// Start line: 116
		// Start offset: 0x80043898
		// Variables:
	// 		struct _SHOOT *sh; // $s0
	/* end block 1 */
	// End offset: 0x80043930
	// End Line: 134

	/* begin block 2 */
		// Start line: 242
	/* end block 2 */
	// End Line: 243

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Shoot_Task(void)

{
  TASK *t;
  long lVar1;
  
  t = TaskCurrent;
  (*(code *)TaskCurrent[7].s7)(TaskCurrent);
  TaskCurrent->display = *(_func_11 **)&t[7].enable;
  Task_EventExec(t,1,0);
  TaskCurrent->event_enable = 1;
  lVar1 = Task_EventWait();
  if (lVar1 == 1) {
    (*(code *)t[7].fp)();
  }
  else {
    if (lVar1 == 2) {
      Shoot_Impact((_SHOOT *)t);
    }
  }
  TaskCurrent->display = (_func_11 *)0x0;
  Task_Sleep(2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Shoot_SetAspect(struct _SHOOT *sh /*$a0*/, long number /*$a1*/, long size /*$a2*/, long mode /*$a3*/)
 // line 139, offset 0x80043954
	/* begin block 1 */
		// Start line: 140
		// Start offset: 0x80043954
		// Variables:
	// 		struct _SHOOT_ASPECT *aspect; // $a1
	/* end block 1 */
	// End offset: 0x8004398C
	// End Line: 143

	/* begin block 2 */
		// Start line: 294
	/* end block 2 */
	// End Line: 295

void Shoot_SetAspect(_SHOOT *sh,long number,long size,long mode)

{
  short sVar1;
  
  if (Shoot_TabAspects[number].pcl == 0) {
    *(void **)&(sh->shadow).x2 = Effects_Pcl;
  }
  else {
    *(void **)&(sh->shadow).x2 = Pl_Pcl;
  }
  (sh->shadow).y0 = Shoot_TabAspects[number].shp;
  (sh->shadow).x0 = Shoot_TabAspects[number].type;
  *(short *)&(sh->shadow).u1 = Shoot_TabAspects[number].fx;
  (sh->shadow).clut = Shoot_TabAspects[number].speed;
  sVar1 = Shoot_TabAspects[number].nbpart;
  (sh->shadow).x1 = (short)size;
  *(short *)&(sh->shadow).u0 = (short)mode;
  (sh->shadow).y1 = sVar1;
  *(_func_19 **)&sh[2].task.event_s3 = Shoot_TabAspects[number].impact;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Shoot_SetFunctions(struct _SHOOT *sh /*$a0*/)
 // line 157, offset 0x800439e0
	/* begin block 1 */
		// Start line: 159
		// Start offset: 0x800439E0
		// Variables:
	// 		struct _SHOOT_TYPE *type; // $v1
	/* end block 1 */
	// End offset: 0x800439E0
	// End Line: 159

	/* begin block 2 */
		// Start line: 333
	/* end block 2 */
	// End Line: 334

void Shoot_SetFunctions(_SHOOT *sh)

{
  int iVar1;
  
  iVar1 = (int)(sh->shadow).x0;
  *(_func_25 **)&sh[2].task.event_s1 = Shoot_TabFunctions[iVar1].init;
  *(_func_26 **)&sh[2].task.event_s2 = Shoot_TabFunctions[iVar1].move;
  *(_func_27 **)&sh[2].task.event_s4 = Shoot_TabFunctions[iVar1].display;
  *(_func_28 **)&sh[2].task.event_s5 = Shoot_TabFunctions[iVar1].destructor;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Shoot_SetVelocity(struct _SHOOT *sh /*$a0*/)
 // line 168, offset 0x80043a24
	/* begin block 1 */
		// Start line: 355
	/* end block 1 */
	// End Line: 356

void Shoot_SetVelocity(_SHOOT *sh)

{
  short sVar1;
  short sVar2;
  short sVar3;
  
  sVar1 = *(short *)((int)&(sh->shadow).tag + 2);
  sVar2 = *(short *)&(sh->shadow).r0;
  (sh->obj).last_pos.vx = (sh->obj).pos.vx - *(short *)&(sh->shadow).tag;
  sVar3 = (sh->obj).pos.vz;
  (sh->obj).last_pos.vy = (sh->obj).pos.vy - sVar1;
  (sh->obj).last_pos.vz = sVar3 - sVar2;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Shoot_DisplayShapes()
 // line 176, offset 0x80043a58
	/* begin block 1 */
		// Start line: 177
		// Start offset: 0x80043A58
		// Variables:
	// 		struct _SHOOT *sh; // $s0
	// 		struct SHOOT_8fake color; // stack offset -56
	// 		struct _D3_OBJECT *o; // $s1

		/* begin block 1.1 */
			// Start line: 184
			// Start offset: 0x80043AA8
			// Variables:
		// 		struct SHOOT_5fake m; // stack offset -48
		// 		long z; // $a1
		/* end block 1.1 */
		// End offset: 0x80043BFC
		// End Line: 201
	/* end block 1 */
	// End offset: 0x80043C60
	// End Line: 210

	/* begin block 2 */
		// Start line: 374
	/* end block 2 */
	// End Line: 375

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Shoot_DisplayShapes(void)

{
  TASK *pTVar1;
  _SCREEN *p_Var2;
  undefined4 in_zero;
  undefined4 in_at;
  long lVar3;
  int iVar4;
  void *pvVar5;
  undefined4 local_38 [7];
  int local_1c;
  int local_18;
  int local_14;
  
  pTVar1 = TaskCurrent;
  local_38[0] = DAT_800ad5e4;
  pvVar5 = TaskCurrent->local;
  if ((*(ushort *)&TaskCurrent[2].display & 0x1000) != 0) {
    setCopReg(2,in_zero,TaskCurrent[1].s0);
    setCopReg(2,in_at,TaskCurrent[1].s1);
    copFunction(2,0x486012);
    local_1c = getCopReg(2,0x19);
    local_18 = getCopReg(2,0x1a);
    local_14 = getCopReg(2,0x1b);
    local_1c = local_1c + Cam_Matrix.t[0];
    local_18 = local_18 + Cam_Matrix.t[1];
    local_14 = local_14 + Cam_Matrix.t[2];
    setCopControlWord(2,0x2800,local_1c);
    setCopControlWord(2,0x3000,local_18);
    setCopControlWord(2,0x3800,local_14);
    lVar3 = D3_SetShadow((_D3_OBJECT *)(TaskCurrent + 1),
                         (char)TaskCurrent + (char)Scr_Frame * '(' + 'h');
    p_Var2 = Scr;
    if ((lVar3 != 0) && (lVar3 < (int)Scr_OtSize)) {
      iVar4 = (int)Scr_Frame;
      (&pTVar1->prec + iVar4 * 10)[0x5a] =
           (TASK *)((uint)(&pTVar1->prec + iVar4 * 10)[0x5a] & 0xff000000 |
                   Scr->ot[lVar3] & 0xffffff);
      p_Var2->ot[lVar3] =
           p_Var2->ot[lVar3] & 0xff000000 | (uint)(&pTVar1[2].s7 + iVar4 * 10) & 0xffffff;
    }
    setCopControlWord(2,0x2800,Cam_Matrix.t[0]);
    setCopControlWord(2,0x3000,Cam_Matrix.t[1]);
    setCopControlWord(2,0x3800,Cam_Matrix.t[2]);
  }
  if (((*(ushort *)&pTVar1[2].display & 0x200) == 0) || (pvVar5 == (void *)0x0)) {
    if ((*(ushort *)&pTVar1[2].display & 0x20) != 0) {
      *(undefined4 **)&pTVar1[2].s3 = local_38;
    }
    Main_Prims = (void *)GtxShp_DisplayListLOFF
                                   (&pTVar1[2].s1,Main_Prims,Scr->ot,(int)Scr_OtSize,0,
                                    Main_TextContext.Font.ascii_tab._20_4_);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Shoot_Impact(struct _SHOOT *sh /*$s0*/)
 // line 213, offset 0x80043c74
	/* begin block 1 */
		// Start line: 453
	/* end block 1 */
	// End Line: 454

void Shoot_Impact(_SHOOT *sh)

{
  code *pcVar1;
  
  if (*(TASK **)(sh->type + 4) != (TASK *)0x0) {
    Task_Kill(*(TASK **)(sh->type + 4));
  }
  if (*(TASK **)(sh->type + 8) != (TASK *)0x0) {
    Task_Kill(*(TASK **)(sh->type + 8));
  }
  TaskCurrent->display = (_func_11 *)0x0;
  pcVar1 = (code *)sh[2].task.event_s3;
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Shoot_UpdateSound(struct _SHOOT *sh /*$s1*/)
 // line 228, offset 0x80043cec
	/* begin block 1 */
		// Start line: 229
		// Start offset: 0x80043CEC
		// Variables:
	// 		short previous_handle; // $s2
	/* end block 1 */
	// End offset: 0x80043D8C
	// End Line: 246

	/* begin block 2 */
		// Start line: 488
	/* end block 2 */
	// End Line: 489

void Shoot_UpdateSound(_SHOOT *sh)

{
  ushort snd_handle;
  ushort uVar1;
  
  snd_handle = (sh->shadow).tpage;
  if (Shoot_NbShots < 4) {
    uVar1 = D3_UpdateSound(&sh->obj,*(short *)&(sh->shadow).u1,snd_handle);
    (sh->shadow).tpage = uVar1;
    if (((short)snd_handle < 0) && (-1 < (int)((uint)uVar1 << 0x10))) {
      Shoot_NbShots = Shoot_NbShots + 1;
    }
    if (((-1 < Shoot_NbShots) && (-1 < (int)((uint)snd_handle << 0x10))) &&
       ((short)(sh->shadow).tpage < 0)) {
      Shoot_NbShots = Shoot_NbShots + -1;
    }
  }
  else {
    Shoot_StopLoopingSound(sh);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Shoot_StopLoopingSound(struct _SHOOT *sh /*$s0*/)
 // line 249, offset 0x80043da4
	/* begin block 1 */
		// Start line: 530
	/* end block 1 */
	// End Line: 531

void Shoot_StopLoopingSound(_SHOOT *sh)

{
  if (-1 < (short)(sh->shadow).tpage) {
    Shoot_NbShots = Shoot_NbShots + -1;
    Sound_Stop((int)(short)(sh->shadow).tpage,0);
    (sh->shadow).tpage = 0xffff;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Shoot_InitNormal(struct _SHOOT *sh /*$s1*/)
 // line 268, offset 0x80043df4
	/* begin block 1 */
		// Start line: 269
		// Start offset: 0x80043DF4
		// Variables:
	// 		struct _D3_OBJECT *o; // $s2
	// 		struct SHOOT_71fake *list; // $s0

		/* begin block 1.1 */
			// Start line: 316
			// Start offset: 0x80044000
			// Variables:
		// 		struct M_OBJECT *mo; // $a0
		/* end block 1.1 */
		// End offset: 0x80044000
		// End Line: 316

		/* begin block 1.2 */
			// Start line: 326
			// Start offset: 0x80044028
			// Variables:
		// 		struct SHOOT_7fake *a; // $v0
		/* end block 1.2 */
		// End offset: 0x80044040
		// End Line: 330
	/* end block 1 */
	// End offset: 0x80044070
	// End Line: 340

	/* begin block 2 */
		// Start line: 569
	/* end block 2 */
	// End Line: 570

void Shoot_InitNormal(_SHOOT *sh)

{
  short sVar1;
  ushort uVar2;
  uint uVar3;
  undefined2 uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  M_OBJECT *obj;
  long lVar8;
  void *pvVar9;
  
  pvVar9 = (sh->task).local;
  iVar5 = rcos((int)(sh->obj).rot.vz);
  sVar1 = (sh->obj).rot.vz;
  *(short *)&(sh->shadow).tag = (short)(iVar5 * (int)(short)(sh->shadow).clut >> 0xc);
  iVar5 = rsin((int)sVar1);
  uVar2 = *(ushort *)&(sh->shadow).u0;
  *(undefined2 *)((int)&(sh->shadow).tag + 2) =
       (short)(iVar5 * (int)(short)(sh->shadow).clut >> 0xc);
  if ((uVar2 & 0x400) == 0) {
    iVar5 = rsin((int)(sh->obj).rot.vx);
    uVar4 = (undefined2)(iVar5 * (int)(short)(sh->shadow).clut >> 0xc);
  }
  else {
    iVar7 = (int)(sh->obj).rot.vx + -0xfa;
    iVar5 = (int)(short)(sh->shadow).clut << 1;
    if (iVar5 == 0) {
      trap(0x1c00);
    }
    if ((iVar5 == -1) && (iVar7 == -0x80000000)) {
      trap(0x1800);
    }
    uVar3 = (iVar7 / iVar5) * 5;
    uVar4 = (undefined2)((int)(uVar3 + (uVar3 >> 0x1f)) >> 1);
  }
  *(undefined2 *)&(sh->shadow).r0 = uVar4;
  if ((*(ushort *)&(sh->shadow).u0 & 0x100) != 0) {
    *(short *)&(sh->shadow).r0 = *(short *)&(sh->shadow).r0 + 0x21;
  }
  uVar6 = *(undefined4 *)&(sh->shadow).x2;
  *(undefined4 *)(sh->type + 8) = 0;
  *(undefined4 *)(sh->type + 4) = 0;
  *(undefined4 *)&(sh->shadow).u3 = 0;
  *(_struct_241 **)&(sh->shadow).x3 = &(sh->obj).pos;
  *(undefined4 *)&(sh->shadow).u2 = uVar6;
  (sh->obj).pos.pad = (sh->shadow).x1 + (sh->shadow).y0 * 0x100;
  *(long **)&(sh->shadow).u3 = &(sh->obj).color;
  *(undefined2 *)sh->type = 1;
  *(undefined *)((int)&(sh->list).n_shapes + 1) = 0xe0;
  (sh->obj).hit_points = 10;
  if ((sh->obj).hit_power == '\0') {
    (sh->obj).hit_power = '\n';
  }
  D3_ClearCollBits(&sh->obj,0xffff);
  D3_SetCollBits(&sh->obj,0x23);
  uVar2 = *(ushort *)&(sh->shadow).u0;
  (sh->obj).child = (_D3_OBJECT *)0x0;
  if ((uVar2 & 0x200) == 0) {
    if ((uVar2 & 1) != 0) {
      sh[2].task.event_s4 = -0x7ffbae8c;
      *(undefined2 *)(sh->type + 0x5c) = 0;
      *(undefined2 *)(sh->type + 0x5e) = 0;
      *(undefined2 *)(sh->type + 0x60) = 0;
    }
  }
  else {
    *(undefined2 *)((int)pvVar9 + 0x9c) = 0xffff;
    *(ushort *)((int)pvVar9 + 0x1a) = *(ushort *)((int)pvVar9 + 0x1a) | 0x10;
    lVar8 = sh->handle2->s1;
    *(long *)((int)pvVar9 + 0x34) = sh->handle2->s0;
    *(long *)((int)pvVar9 + 0x38) = lVar8;
    *(undefined4 *)((int)pvVar9 + 0x2c) = *(undefined4 *)((int)pvVar9 + 0x34);
    *(undefined4 *)((int)pvVar9 + 0x30) = *(undefined4 *)((int)pvVar9 + 0x38);
    *(undefined2 *)((int)pvVar9 + 0x3e) = 0;
    *(undefined2 *)((int)pvVar9 + 0x3c) = 0;
    if ((*(ushort *)((int)pvVar9 + 0x1a) & 0x40) != 0) {
      obj = *(M_OBJECT **)((int)pvVar9 + 0x24);
      *(undefined4 *)&(obj->Sq).Data.Flag = 0xa00;
      Manim_SetAnim(obj,0);
    }
  }
  if ((*(ushort *)&(sh->shadow).u0 & 0x10) != 0) {
    (sh->shadow).x1 = 1;
  }
  if ((sh->shadow).x0 == 4) {
    Shoot_InitRiffle(sh);
  }
  D3_InsertObject(&sh->obj,&Pvl_EnemyShots);
  (sh->task).destructor = (_func_12 *)sh[2].task.event_s5;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Shoot_MoveNormal()
 // line 346, offset 0x800440a4
	/* begin block 1 */
		// Start line: 347
		// Start offset: 0x800440A4
		// Variables:
	// 		struct _SHOOT *sh; // $s0
	// 		struct _D3_OBJECT *o; // $s1
	// 		struct SHOOT_7fake *angle; // $s3
	// 		struct SHOOT_31fake cross; // stack offset -64
	// 		long i; // $s2

		/* begin block 1.1 */
			// Start line: 407
			// Start offset: 0x8004427C
			// Variables:
		// 		struct M_OBJECT *mo; // $a0
		/* end block 1.1 */
		// End offset: 0x8004429C
		// End Line: 411
	/* end block 1 */
	// End offset: 0x8004433C
	// End Line: 437

	/* begin block 2 */
		// Start line: 748
	/* end block 2 */
	// End Line: 749

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Shoot_MoveNormal(void)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  ushort uVar5;
  char cVar6;
  TASK *t;
  TASK *pTVar7;
  int nb_part;
  long lVar8;
  void *pvVar9;
  int iVar10;
  
  t = TaskCurrent;
  iVar10 = 100;
  pvVar9 = TaskCurrent->local;
  cVar6 = (char)TaskCurrent;
  if ((*(ushort *)&TaskCurrent[2].display & 4) != 0) {
    nb_part = (int)*(short *)((int)&TaskCurrent[2].destructor + 2);
    if (0 < nb_part) {
      pTVar7 = SFX_StreamTracingBullet((_D3_OBJECT *)(TaskCurrent + 1),cVar6 + '4',nb_part);
      *(TASK **)&t[2].s5 = pTVar7;
      goto LAB_80044120;
    }
  }
  if ((*(ushort *)&TaskCurrent[2].display & 8) != 0) {
    pTVar7 = SFX_StreamWarminMissile
                       ((_D3_OBJECT *)(TaskCurrent + 1),cVar6 + '4',
                        *(short *)&TaskCurrent[2].destructor);
    *(TASK **)&t[2].s5 = pTVar7;
  }
LAB_80044120:
  if ((*(ushort *)&t[2].display & 0x40) != 0) {
    Shoot_DisplayCross(0xc0);
  }
  *(undefined2 *)((int)&t[2].local + 2) = 0xffff;
  do {
    iVar10 = iVar10 + -1;
    if (iVar10 == -1) {
LAB_8004433c:
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
    if (((*(ushort *)&t[2].display & 0x200) != 0) && (pvVar9 != (void *)0x0)) {
      lVar8 = t[1].s1;
      *(long *)((int)pvVar9 + 0x2c) = t[1].s0;
      *(long *)((int)pvVar9 + 0x30) = lVar8;
    }
    uVar5 = *(ushort *)&t[2].display;
    if ((uVar5 & 1) == 0) {
      if ((pvVar9 != (void *)0x0) && ((uVar5 & 0x200) != 0)) {
        lVar8 = Direction((int)*(short *)&t[2].bnext,(int)*(short *)((int)&t[2].bnext + 2));
        *(undefined2 *)((int)pvVar9 + 0x40) = (short)lVar8;
        if ((*(ushort *)((int)pvVar9 + 0x1a) & 0x40) != 0) {
          nb_part = *(int *)(*(int *)((int)pvVar9 + 0x24) + 0x10);
          if (nb_part < 0x1a00) {
            *(int *)(*(int *)((int)pvVar9 + 0x24) + 0x10) = nb_part + 0x40;
          }
        }
      }
    }
    else {
      if (((uVar5 & 0x200) != 0) && (pvVar9 != (void *)0x0)) {
        *(short *)((int)pvVar9 + 0x3e) = *(short *)((int)pvVar9 + 0x3e) + 0x100;
      }
      *(short *)&t[3].child = *(short *)&t[3].child + 200;
      if (((*(ushort *)&t[2].display & 0x10) != 0) && (*(short *)&t[2].destructor < 0x21)) {
        *(short *)&t[2].destructor = *(short *)&t[2].destructor + 3;
      }
    }
    if ((*(ushort *)&t[2].display & 0x80) != 0) {
      Shoot_SeekPlayer();
    }
    lVar8 = Boxes_TestObject((_D3_OBJECT *)(t + 1));
    if (lVar8 != 0) {
      Shoot_SetVelocity((_SHOOT *)t);
      Boxes_BounceObject(cVar6 + '4');
      if (((*(ushort *)&t[2].display & 0x200) != 0) && (pvVar9 != (void *)0x0)) {
        *(ushort *)((int)pvVar9 + 0x1a) = *(ushort *)((int)pvVar9 + 0x1a) & 0xffef;
      }
      Task_Sleep(2);
      Task_EventExec(t,2,0);
      goto LAB_8004433c;
    }
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Shoot_ImpactNormal()
 // line 441, offset 0x80044360
	/* begin block 1 */
		// Start line: 442
		// Start offset: 0x80044360
		// Variables:
	// 		struct _SHOOT *sh; // $s1
	// 		long i; // $s0
	/* end block 1 */
	// End offset: 0x800443DC
	// End Line: 461

	/* begin block 2 */
		// Start line: 955
	/* end block 2 */
	// End Line: 956

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Shoot_ImpactNormal(void)

{
  TASK *pTVar1;
  int iVar2;
  
  pTVar1 = TaskCurrent;
  Shoot_StopLoopingSound((_SHOOT *)TaskCurrent);
  Fx_Play(0x38,(char)pTVar1 + -0x44);
  iVar2 = *(int *)&pTVar1[7].enable;
  *(undefined2 *)((int)&pTVar1[1].s1 + 2) = 0x2d32;
  pTVar1[1].local = (void *)0x808080;
  if (iVar2 == 0) {
    TaskCurrent->display = Shoot_DisplayShapes;
  }
  iVar2 = 0x19;
  do {
    iVar2 = iVar2 + -1;
    Task_Next();
    *(short *)((int)&pTVar1[1].s1 + 2) = *(short *)((int)&pTVar1[1].s1 + 2) + 0x100;
  } while (iVar2 != 0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Shoot_DestructorNormal(struct TASK *t /*$a0*/)
 // line 464, offset 0x800443f0
	/* begin block 1 */
		// Start line: 465
		// Start offset: 0x800443F0
		// Variables:
	// 		struct _SHOOT *sh; // $s0
	// 		struct _D3_OBJECT *o; // $a0
	/* end block 1 */
	// End offset: 0x80044424
	// End Line: 475

	/* begin block 2 */
		// Start line: 1008
	/* end block 2 */
	// End Line: 1009

void Shoot_DestructorNormal(TASK *t)

{
  void *pvVar1;
  
  pvVar1 = t->local;
  if ((*(ushort *)&t[2].display & 0x200) != 0) {
    *(undefined2 *)((int)pvVar1 + 0x9c) = 0x1b39;
    *(ushort *)((int)pvVar1 + 0x1a) = *(ushort *)((int)pvVar1 + 0x1a) & 0xffef;
  }
  Shoot_StopLoopingSound((_SHOOT *)t);
  t[1].bnext = (TASK *)0x0;
  D3_DeleteObject((_D3_OBJECT *)(t + 1));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Shoot_DisplayCross(struct SHOOT_31fake *p /*$s0*/)
 // line 482, offset 0x80044448
	/* begin block 1 */
		// Start line: 483
		// Start offset: 0x80044448
		// Variables:
	// 		struct _SHOOT *sh; // $v1
	// 		struct SHOOT_70fake shp; // stack offset -32
	// 		long z; // stack offset -16
	/* end block 1 */
	// End offset: 0x800445B4
	// End Line: 512

	/* begin block 2 */
		// Start line: 1048
	/* end block 2 */
	// End Line: 1049

/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Shoot_DisplayCross(undefined p)

{
  undefined4 uVar1;
  _SCREEN *p_Var2;
  undefined4 in_zero;
  undefined4 in_at;
  uint uVar3;
  undefined3 in_register_00000011;
  SHAPE_31fake *prim;
  short w;
  int iVar4;
  void *local_20;
  short local_1c;
  undefined4 local_18;
  int local_10;
  
  prim = (SHAPE_31fake *)CONCAT31(in_register_00000011,p);
  local_20 = (void *)TaskCurrent[2].s0;
  local_1c = 0xe7;
  setCopReg(2,in_zero,TaskCurrent[1].s0);
  setCopReg(2,in_at,TaskCurrent[1].s1);
  copFunction(2,0x180001);
  uVar1 = getCopReg(2,0xe);
  local_10 = getCopReg(2,0x9800);
  local_10 = local_10 >> 2;
  if ((0 < local_10) && (local_10 < (int)Scr_OtSize)) {
    iVar4 = ((int)Scr_GeomScreen * 0x19) / local_10;
    if (local_10 == 0) {
      trap(0x1c00);
    }
    if ((local_10 == -1) && ((int)Scr_GeomScreen * 0x19 == -0x80000000)) {
      trap(0x1800);
    }
    local_18._0_2_ = (short)uVar1;
    local_18._2_2_ = (short)((uint)uVar1 >> 0x10);
    uVar3 = iVar4 << 0x10;
    w = (short)((int)(((int)uVar3 >> 0x10) + (uVar3 >> 0x1f)) >> 1);
    local_18 = CONCAT22(local_18._2_2_ - w,(short)local_18 - w);
    w = (short)iVar4;
    Shp_SetPolyFT4(prim,(SHAPE_68fake *)&local_20,w,w);
    prim->code = prim->code | 2;
    p_Var2 = Scr;
    prim->tag = prim->tag & 0xff000000 | Scr->ot[local_10] & 0xffffff;
    p_Var2->ot[local_10] = p_Var2->ot[local_10] & 0xff000000 | (uint)prim & 0xffffff;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Shoot_SeekPlayer()
 // line 516, offset 0x800445c4
	/* begin block 1 */
		// Start line: 517
		// Start offset: 0x800445C4
		// Variables:
	// 		struct SHOOT_7fake pos; // stack offset -64
	// 		struct _SHOOT *sh; // $s0
	// 		struct _D3_OBJECT *ot; // $s3
	// 		struct SHOOT_6fake vec; // stack offset -56
	// 		struct SHOOT_6fake vecsq; // stack offset -40
	// 		long change; // $s4
	// 		long d; // $s1
	// 		long sz; // $s2
	/* end block 1 */
	// End offset: 0x8004495C
	// End Line: 590

	/* begin block 2 */
		// Start line: 1144
	/* end block 2 */
	// End Line: 1145

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Shoot_SeekPlayer(void)

{
  short sVar1;
  bool bVar2;
  undefined4 uVar3;
  TASK *pTVar4;
  short sVar5;
  uint uVar6;
  long lVar7;
  int iVar8;
  int x;
  int iVar9;
  int y;
  undefined4 uVar10;
  undefined4 in_t2;
  undefined *puVar11;
  int iVar12;
  short local_3c;
  
  pTVar4 = TaskCurrent;
  uVar3 = _DAT_800b1c68;
  bVar2 = false;
  iVar12 = 0;
  puVar11 = &DAT_800b1c64;
  uVar10 = _DAT_800b1c68;
  uVar6 = Direction((int)*(short *)&TaskCurrent[1].s0 - (int)_DAT_800b1c64,
                    (int)*(short *)((int)&TaskCurrent[1].s0 + 2) - (int)_DAT_800b1c66);
  do {
    rcos(uVar6);
    rsin(uVar6);
    lVar7 = Boxes_GetHeight((_D3_OBJECT *)&Player,0xc0,300);
    local_3c = (short)uVar3;
    iVar12 = iVar12 + 1;
    if ((int)local_3c + 100 < lVar7) {
      bVar2 = true;
      break;
    }
  } while (iVar12 < 4);
  iVar12 = (int)_DAT_800b1c88;
  iVar9 = (int)_DAT_800b1ca8;
  x = ((int)_DAT_800b1c64 +
      ((int)((int)_DAT_800b1c84 + (int)_DAT_800b1c8c +
            ((uint)((int)_DAT_800b1c84 + (int)_DAT_800b1c8c) >> 0x1f)) >> 1)) -
      (int)*(short *)&pTVar4[1].s0;
  y = ((int)_DAT_800b1c66 +
      ((int)((int)_DAT_800b1c86 + (int)_DAT_800b1c96 +
            ((uint)((int)_DAT_800b1c86 + (int)_DAT_800b1c96) >> 0x1f)) >> 1)) -
      (int)*(short *)((int)&pTVar4[1].s0 + 2);
  if (((*(ushort *)&pTVar4[2].display & 0x800) == 0) || (!bVar2)) {
    if (*(short *)((int)&pTVar4[2].child + 2) < 0xc0) {
      *(short *)((int)&pTVar4[2].child + 2) = *(short *)((int)&pTVar4[2].child + 2) + 8;
    }
    lVar7 = D3_GoToDir((_D3_OBJECT *)(pTVar4 + 1),x,y,(int)*(short *)((int)&pTVar4[2].child + 2));
    if ((lVar7 == 0) && (bVar2)) {
      *(ushort *)&pTVar4[2].display = *(ushort *)&pTVar4[2].display | 0x800;
      uVar6 = M_rand();
      if ((uVar6 & 1) == 0) {
        sVar5 = *(short *)&pTVar4[1].s5 + -0x400;
      }
      else {
        sVar5 = *(short *)&pTVar4[1].s5 + 0x400;
      }
      *(short *)&pTVar4[1].s5 = sVar5;
      *(undefined2 *)((int)&pTVar4[2].child + 2) = 0x19;
    }
    else {
      *(ushort *)&pTVar4[2].display = *(ushort *)&pTVar4[2].display & 0xf7ff;
    }
  }
  else {
    D3_GoToDir((_D3_OBJECT *)(pTVar4 + 1),x,y,(int)*(short *)((int)&pTVar4[2].child + 2));
  }
  iVar8 = ((int)_DAT_800b1c68 + ((int)(iVar12 + iVar9 + ((uint)(iVar12 + iVar9) >> 0x1f)) >> 1)) -
          (int)*(short *)&pTVar4[1].s1;
  setCopReg(2,uVar10,x);
  setCopReg(2,in_t2,y);
  setCopReg(2,puVar11,iVar8);
  copFunction(2,0xa00428);
  iVar12 = getCopReg(2,0x19);
  x = getCopReg(2,0x1a);
  iVar9 = getCopReg(2,0x1b);
  uVar6 = SquareRoot0(iVar12 + x + iVar9);
  iVar12 = 0;
  if (uVar6 != 0) {
    iVar8 = iVar8 * 0x100;
    if (uVar6 == 0) {
      trap(0x1c00);
    }
    if ((uVar6 == 0xffffffff) && (iVar8 == -0x80000000)) {
      trap(0x1800);
    }
    iVar12 = (iVar8 / (int)uVar6) * (int)*(short *)((int)&pTVar4[2].display + 2) >> 8;
  }
  sVar5 = *(short *)&pTVar4[2].exec + 8;
  if (((int)*(short *)&pTVar4[2].exec < iVar12) ||
     (sVar5 = *(short *)&pTVar4[2].exec + -8, iVar12 < (int)*(short *)&pTVar4[2].exec)) {
    *(short *)&pTVar4[2].exec = sVar5;
  }
  iVar12 = rcos((int)*(short *)&pTVar4[1].s5);
  sVar5 = *(short *)&pTVar4[1].s5;
  *(short *)&pTVar4[2].bnext = (short)(iVar12 * (int)*(short *)((int)&pTVar4[2].display + 2) >> 0xc)
  ;
  iVar12 = rsin((int)sVar5);
  sVar5 = *(short *)&pTVar4[1].s0;
  sVar1 = *(short *)((int)&pTVar4[1].s0 + 2);
  *(undefined2 *)((int)&pTVar4[2].bnext + 2) =
       (short)(iVar12 * (int)*(short *)((int)&pTVar4[2].display + 2) >> 0xc);
  lVar7 = Distance2D((int)_DAT_800b1c64,(int)_DAT_800b1c66,(int)sVar5,(int)sVar1);
  if (lVar7 < 100) {
    *(ushort *)&pTVar4[2].display = *(ushort *)&pTVar4[2].display & 0xff7f;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Shoot_InitRiffle(struct _SHOOT *sh /*$a0*/)
 // line 599, offset 0x8004497c
	/* begin block 1 */
		// Start line: 601
		// Start offset: 0x8004497C
		// Variables:
	// 		struct SHOOT_71fake *list; // $v0
	// 		struct SHOOT_7fake *spd; // $a2
	// 		long i; // $a1
	/* end block 1 */
	// End offset: 0x800449D4
	// End Line: 614

	/* begin block 2 */
		// Start line: 1375
	/* end block 2 */
	// End Line: 1376

void Shoot_InitRiffle(_SHOOT *sh)

{
  _func_20 **pp_Var1;
  int iVar2;
  _func_20 *p_Var3;
  
  iVar2 = 0;
  *(byte **)&(sh->shadow).x3 = sh->type + 0x5c;
  *(undefined4 *)&(sh->shadow).u3 = 0;
  *(undefined2 *)sh->type = 0;
  pp_Var1 = &sh->init;
  do {
    p_Var3 = (_func_20 *)sh->move;
    *pp_Var1 = sh->init;
    pp_Var1[1] = p_Var3;
    *(undefined2 *)((int)pp_Var1 + 6) = 0x3c;
    iVar2 = iVar2 + 1;
    pp_Var1 = pp_Var1 + 2;
  } while (iVar2 < 3);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Shoot_MoveRiffle()
 // line 617, offset 0x800449dc
	/* begin block 1 */
		// Start line: 618
		// Start offset: 0x800449DC
		// Variables:
	// 		struct _SHOOT *sh; // $s0
	// 		struct SHOOT_71fake *list; // $s2
	// 		struct SHOOT_7fake *spd; // stack offset -56
	// 		struct _D3_OBJECT *o; // $s3
	// 		struct _D3_OBJECT *owner; // $s5
	// 		struct _MONSTER *monst; // $s7
	// 		struct M_OBJECT *mo; // stack offset -52
	// 		long i; // $s6
	// 		long cpt; // $fp
	// 		long cont; // $s4
	// 		long tmp; // $s1
	/* end block 1 */
	// End offset: 0x80044F94
	// End Line: 714

	/* begin block 2 */
		// Start line: 1420
	/* end block 2 */
	// End Line: 1421

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Shoot_MoveRiffle(void)

{
  bool bVar1;
  TASK *pTVar2;
  short sVar3;
  long *plVar4;
  long lVar5;
  short *psVar6;
  int iVar7;
  long lVar8;
  _func_11 **pp_Var9;
  _func_12 *p_Var10;
  _func_11 **pp_Var11;
  int iVar12;
  uint uVar13;
  TASK *o;
  TASK *o_00;
  int iVar14;
  TASK *pTVar15;
  int iVar16;
  
  pTVar2 = TaskCurrent;
  iVar16 = 0;
  pp_Var9 = &TaskCurrent[3].display;
  o = TaskCurrent + 1;
  o_00 = TaskCurrent[2].bprec;
  pTVar15 = o_00[1].bprec;
  p_Var10 = o_00->destructor;
  D3_SetBox((_D3_OBJECT *)o,-0x32,-0x32,0,0x32,0x32,0x32);
  *(undefined2 *)((int)&pTVar2[1].exec + 2) = 0x20;
  *(undefined2 *)&pTVar2[1].sp = 3;
  *(undefined2 *)((int)&pTVar2[2].local + 2) = 0xffff;
  do {
    iVar14 = 0;
    bVar1 = false;
    if (0 < *(short *)&pTVar2[2].s4) {
      iVar12 = 0;
      pp_Var11 = pp_Var9;
      do {
        if ((*(short *)((int)pp_Var11 + 6) != 0x1234) && (0 < *(short *)((int)pp_Var11 + 6))) {
          *(undefined2 *)((int)&pTVar2[1].sp + 2) = 0;
          plVar4 = (long *)(iVar12 + pTVar2[2].s2);
          lVar8 = plVar4[1];
          pTVar2[1].s2 = *plVar4;
          pTVar2[1].s3 = lVar8;
          pTVar2[1].s0 = pTVar2[1].s2;
          pTVar2[1].s1 = pTVar2[1].s3;
          *(short *)&pTVar2[1].s0 = *(short *)&pTVar2[1].s0 + *(short *)pp_Var11;
          *(short *)((int)&pTVar2[1].s0 + 2) =
               *(short *)((int)&pTVar2[1].s0 + 2) + *(short *)((int)pp_Var11 + 2);
          *(short *)&pTVar2[1].s1 = *(short *)&pTVar2[1].s1 + *(short *)(pp_Var11 + 1);
          lVar8 = Boxes_TestObject((_D3_OBJECT *)o);
          if (lVar8 == 0) {
            *(short *)((int)pp_Var11 + 6) = *(short *)((int)pp_Var11 + 6) + -1;
          }
          else {
            if (*(short *)((int)&o_00->event_s3 + 2) != -1) {
              D3_PlaySound((_D3_OBJECT *)o_00,1);
            }
            Boxes_BounceObject((char)pp_Var11);
            lVar5 = M_rand();
            lVar8 = lVar5;
            if (lVar5 < 0) {
              lVar8 = lVar5 + 3;
            }
            *(ushort *)(iVar12 + pTVar2[2].s2 + 6) =
                 ((short)lVar5 + (short)(lVar8 >> 2) * -4 + 0xeb) * 0x100 | 6;
            *(short *)pp_Var11 = *(short *)pp_Var11 >> 1;
            *(short *)((int)pp_Var11 + 2) = *(short *)((int)pp_Var11 + 2) >> 1;
            *(short *)(pp_Var11 + 1) = *(short *)(pp_Var11 + 1) >> 1;
          }
          bVar1 = true;
          psVar6 = (short *)(iVar12 + pTVar2[2].s2);
          *psVar6 = *psVar6 + *(short *)pp_Var11;
          iVar7 = iVar12 + pTVar2[2].s2;
          *(short *)(iVar7 + 2) = *(short *)(iVar7 + 2) + *(short *)((int)pp_Var11 + 2);
          iVar7 = iVar12 + pTVar2[2].s2;
          *(short *)(iVar7 + 4) = *(short *)(iVar7 + 4) + *(short *)(pp_Var11 + 1);
          if (*(short *)pp_Var11 < 0) {
            sVar3 = *(short *)pp_Var11 + 1;
          }
          else {
            sVar3 = *(short *)pp_Var11 + -1;
          }
          *(short *)pp_Var11 = sVar3;
          if (*(short *)((int)pp_Var11 + 2) < 0) {
            sVar3 = *(short *)((int)pp_Var11 + 2) + 1;
          }
          else {
            sVar3 = *(short *)((int)pp_Var11 + 2) + -1;
          }
          *(short *)((int)pp_Var11 + 2) = sVar3;
          *(short *)(pp_Var11 + 1) = *(short *)(pp_Var11 + 1) + -6;
          lVar8 = SFX_TestVectorSpeed((char)pTVar2[2].s2 + (char)iVar12,(char)pp_Var11);
          if (lVar8 == 0) {
            *(short *)((int)pp_Var11 + 6) = 0x1234;
          }
        }
        pp_Var11 = pp_Var11 + 2;
        iVar14 = iVar14 + 1;
        iVar12 = iVar12 + 8;
      } while (iVar14 < (int)*(short *)&pTVar2[2].s4);
    }
    if ((((iVar16 == (iVar16 / 10) * 10) && (*(short *)&pTVar2[2].s4 < 3)) &&
        (pTVar15 != (TASK *)0x0)) && (o_00 != (TASK *)0x0)) {
      if (*(short *)((int)&o_00->event_s3 + 2) != -1) {
        D3_PlaySound((_D3_OBJECT *)o_00,0);
      }
      uVar13 = (int)*(short *)&o_00->s5 + (int)*(short *)(p_Var10 + 0x26);
      iVar14 = rcos(uVar13);
      *(short *)(pp_Var9 + (int)*(short *)&pTVar2[2].s4 * 2) = (short)((iVar14 * 100) / 3 >> 0xb);
      iVar14 = rsin(uVar13);
      *(undefined2 *)((int)pp_Var9 + (int)*(short *)&pTVar2[2].s4 * 8 + 2) =
           (short)((iVar14 * 100) / 3 >> 0xb);
      *(short *)(pp_Var9 + (int)*(short *)&pTVar2[2].s4 * 2 + 1) = 0;
      iVar14 = rcos(uVar13);
      iVar12 = rsin((int)*(short *)(p_Var10 + 0x26) + (int)*(short *)&o_00->s5);
      *(short *)((int)*(short *)&pTVar2[2].s4 * 8 + pTVar2[2].s2) =
           *(short *)&o_00->s0 +
           (short)(iVar14 * (int)*(short *)&pTVar15[1].event_param -
                   iVar12 * (int)*(short *)((int)&pTVar15[1].event_param + 2) >> 0xc);
      iVar14 = rsin(uVar13);
      iVar12 = rcos((int)*(short *)(p_Var10 + 0x26) + (int)*(short *)&o_00->s5);
      *(short *)((int)*(short *)&pTVar2[2].s4 * 8 + pTVar2[2].s2 + 2) =
           *(short *)((int)&o_00->s0 + 2) +
           (short)(iVar14 * (int)*(short *)&pTVar15[1].event_param +
                   iVar12 * (int)*(short *)((int)&pTVar15[1].event_param + 2) >> 0xc);
      iVar14 = rsin(-(int)*(short *)(p_Var10 + 0x24));
      *(short *)((int)*(short *)&pTVar2[2].s4 * 8 + pTVar2[2].s2 + 4) =
           *(short *)&o_00->s1 + *(short *)&pTVar15[1].event_sp + (short)(iVar14 * 0x96 >> 0xc);
      Impact_Sparks((char)pTVar2[2].s2 + (char)*(undefined2 *)&pTVar2[2].s4 * '\b',2);
      Impact_Smoke((char)pTVar2[2].s2 + (char)*(undefined2 *)&pTVar2[2].s4 * '\b',0);
      lVar5 = M_rand();
      lVar8 = lVar5;
      if (lVar5 < 0) {
        lVar8 = lVar5 + 3;
      }
      *(ushort *)((int)*(short *)&pTVar2[2].s4 * 8 + pTVar2[2].s2 + 6) =
           ((short)lVar5 + (short)(lVar8 >> 2) * -4 + 0xeb) * 0x100 | 6;
      bVar1 = true;
      *(short *)&pTVar2[2].s4 = *(short *)&pTVar2[2].s4 + 1;
    }
    iVar16 = iVar16 + 1;
    Task_Next();
  } while (bVar1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Grenade_Add(struct SHOOT_7fake *pos /*$s3*/, struct SHOOT_7fake *rot /*$s5*/, long number /*$s4*/, long distance /*$s6*/, struct _D3_OBJECT *owner /*stack 16*/, long height /*stack 20*/)
 // line 723, offset 0x80044fc4
	/* begin block 1 */
		// Start line: 724
		// Start offset: 0x80044FC4
		// Variables:
	// 		struct _SHOOT *t; // $s0
	// 		long col; // $s2
	/* end block 1 */
	// End offset: 0x80045050
	// End Line: 744

	/* begin block 2 */
		// Start line: 1736
	/* end block 2 */
	// End Line: 1737

void Grenade_Add(undefined pos,undefined rot,long number,long distance,_D3_OBJECT *owner,long height
                )

{
  _SHOOT *sh;
  undefined3 in_register_00000011;
  undefined4 *puVar1;
  undefined3 in_register_00000015;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)CONCAT31(in_register_00000011,pos);
  sh = (_SHOOT *)Task_Link(Shoot_Task,0x84c);
  if (owner == (_D3_OBJECT *)0x0) {
    uVar2 = puVar1[1];
    *(undefined4 *)&(sh->obj).last_pos = *puVar1;
    *(undefined4 *)&(sh->obj).last_pos.vz = uVar2;
  }
  else {
    Boxes_GetCenter(owner,(char)sh + -0x3c);
  }
  uVar2 = puVar1[1];
  *(undefined4 *)&(sh->obj).pos = *puVar1;
  *(undefined4 *)&(sh->obj).pos.vz = uVar2;
  uVar2 = ((undefined4 *)CONCAT31(in_register_00000015,rot))[1];
  *(undefined4 *)&(sh->obj).rot = *(undefined4 *)CONCAT31(in_register_00000015,rot);
  *(undefined4 *)&(sh->obj).rot.vz = uVar2;
  *(_D3_OBJECT **)&sh->handle2 = owner;
  (sh->obj).hit_power = '\x05';
  (sh->obj).color = 0x808080;
  *(short *)(sh->type + 0x5c) = (short)distance;
  *(short *)(sh->type + 0x5e) = (short)height;
  Shoot_SetAspect(sh,number,100,0x1000);
  Shoot_SetFunctions(sh);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Laser_Add(struct SHOOT_7fake *p /*$v1*/, struct SHOOT_7fake *r /*$t0*/, struct _D3_OBJECT *o /*$a0*/, struct SHOOT_8fake *c /*$a3*/)
 // line 749, offset 0x800450f0
	/* begin block 1 */
		// Start line: 1811
	/* end block 1 */
	// End Line: 1812

void Laser_Add(undefined1 p,undefined1 r,_D3_OBJECT *o,undefined1 c)

{
  uint local_10;
  
  if (o->hit_power == '\0') {
    local_10 = 5;
  }
  else {
    local_10 = (uint)o->hit_power;
  }
  Shoot_Add(o,p,r,c,8,0x21,local_10,0);
  return;
}





