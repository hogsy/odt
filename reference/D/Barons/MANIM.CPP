#include "THISDUST.H"
#include "MANIM.H"


// decompiled code
// original method signature: 
// void /*$ra*/ Manim_Init()
 // line 45, offset 0x800223b0
	/* begin block 1 */
		// Start line: 91
	/* end block 1 */
	// End Line: 92

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Manim_Init(void)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Manim_GetLinkPos(struct M_OBJECT *Obj /*$s0*/, struct MANIM_100fake *Ani /*$a1*/, long Anim /*$a2*/, struct MANIM_7fake *Out /*$s1*/)
 // line 56, offset 0x800223b8
	/* begin block 1 */
		// Start line: 57
		// Start offset: 0x800223B8
		// Variables:
	// 		struct MANIM_7fake Temp; // stack offset -24
	/* end block 1 */
	// End offset: 0x800223B8
	// End Line: 57

	/* begin block 2 */
		// Start line: 112
	/* end block 2 */
	// End Line: 113

void Manim_GetLinkPos(M_OBJECT *Obj,undefined1 Ani,long Anim,undefined Out)

{
  undefined3 in_register_0000001d;
  short *psVar1;
  short local_18;
  short local_16;
  short local_14;
  
  psVar1 = (short *)CONCAT31(in_register_0000001d,Out);
  Manim_GetLinkPosDelta(Obj,Ani,Anim,0xe8);
  *psVar1 = local_18 + (Obj->sit->pos).vx;
  psVar1[1] = local_16 + (Obj->sit->pos).vy;
  psVar1[2] = local_14 + (Obj->sit->pos).vz;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Manim_GetLinkPosDelta(struct M_OBJECT *Obj /*$s3*/, struct MANIM_100fake *Ani /*$a1*/, long Anim /*$a2*/, struct MANIM_7fake *Out /*$s4*/)
 // line 68, offset 0x80022434
	/* begin block 1 */
		// Start line: 69
		// Start offset: 0x80022434
		// Variables:
	// 		long vx; // $s0
	// 		long vy; // $v0
	// 		long r; // $s1
	// 		long t; // $v1
	// 		struct MANIM_7fake *Traj; // $s2
	/* end block 1 */
	// End offset: 0x800224C4
	// End Line: 81

	/* begin block 2 */
		// Start line: 136
	/* end block 2 */
	// End Line: 137

void Manim_GetLinkPosDelta(M_OBJECT *Obj,undefined Ani,long Anim,undefined Out)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined3 in_register_00000015;
  undefined3 in_register_0000001d;
  undefined2 *puVar9;
  uint uVar10;
  short *psVar11;
  
  puVar9 = (undefined2 *)CONCAT31(in_register_0000001d,Out);
  iVar8 = *(int *)(CONCAT31(in_register_00000015,Ani) + Anim * 4 + 8);
  uVar10 = SEXT24((Obj->sit->rot).vz);
  psVar11 = (short *)(iVar8 + ((int)((uint)*(ushort *)&(Obj->Env).nPivot << 0x10) >> 0x14) *
                              ((uint)*(ushort *)(iVar8 + 2) + 1) * 8 + 0x14);
  if (((Obj->Env).Obj.normal_top.vx & 4U) != 0) {
    iVar7 = uVar10 + (int)*(short *)((int)&(Obj->Env).Obj.n_vert + 2);
    iVar8 = iVar7;
    if (iVar7 < 0) {
      iVar8 = iVar7 + 0xfff;
    }
    uVar10 = iVar7 + (iVar8 >> 0xc) * -0x1000;
  }
  iVar8 = rcos(uVar10);
  iVar7 = rsin(uVar10);
  sVar1 = *psVar11;
  sVar2 = psVar11[1];
  iVar5 = rsin(uVar10);
  iVar6 = rcos(uVar10);
  sVar3 = *psVar11;
  sVar4 = psVar11[1];
  *puVar9 = (short)(iVar8 * (int)sVar1 - iVar7 * (int)sVar2 >> 0xc);
  puVar9[1] = (short)(iVar5 * (int)sVar3 + iVar6 * (int)sVar4 >> 0xc);
  puVar9[2] = psVar11[2] - (Obj->sit->pos).vz;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Manim_SetEffect(struct M_OBJECT *mo /*$a0*/, TDRFuncPtr_Manim_SetEffect1f f /*$a1*/)
 // line 96, offset 0x8002257c
	/* begin block 1 */
		// Start line: 218
	/* end block 1 */
	// End Line: 219

void Manim_SetEffect(M_OBJECT *mo,TDRFuncPtr_Manim_SetEffect1f f)

{
  ushort uVar1;
  
  uVar1 = (mo->Env).Obj.normal_top.vx;
  (mo->Env).Obj.vert_top.vz = 0;
  *(undefined2 *)((int)&(mo->Env).nPivot + 2) = 0;
  *(TDRFuncPtr_Manim_SetEffect1f *)&(mo->Env).Obj.n_normal = f;
  (mo->Env).Obj.normal_top.vx = uVar1 & 0xffdf;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Manim_SetAnim(struct M_OBJECT *obj /*$a0*/, long Anim /*$a1*/)
 // line 106, offset 0x80022598
	/* begin block 1 */
		// Start line: 239
	/* end block 1 */
	// End Line: 240

void Manim_SetAnim(M_OBJECT *obj,long Anim)

{
  short sVar1;
  int iVar2;
  
  sVar1 = *(short *)((int)&(obj->Env).Version + 2);
  (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0x20U | 3;
  if (Anim != (int)sVar1) {
    iVar2 = *(int *)((obj->Sq).Data.FatherTrans + 2);
    *(undefined2 *)((int)&(obj->Env).Version + 2) = (short)Anim;
    *(undefined2 *)&(obj->Env).nPivot = 0;
    sVar1 = *(short *)(*(int *)(iVar2 + Anim * 4 + 8) + 0x1a);
    (obj->Env).Obj.normal_top.pad = 0x100;
    (obj->Env).Obj.normal_top.vy = 0x100;
    (obj->Env).Obj.normal_top.vz = 0x100;
    (obj->Env).Obj.vert_top.pad = sVar1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Manim_ForceAnim(struct M_OBJECT *obj /*$a0*/, long Anim /*$a1*/)
 // line 125, offset 0x800225ec
	/* begin block 1 */
		// Start line: 286
	/* end block 1 */
	// End Line: 287

void Manim_ForceAnim(M_OBJECT *obj,long Anim)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  
  uVar1 = (obj->Env).Obj.normal_top.vx;
  *(undefined2 *)((int)&(obj->Env).Version + 2) = (short)Anim;
  (obj->Env).Obj.normal_top.vx = uVar1 & 0x20 | 3;
  iVar3 = *(int *)((obj->Sq).Data.FatherTrans + 2);
  *(undefined2 *)&(obj->Env).nPivot = 0;
  sVar2 = *(short *)(*(int *)(iVar3 + Anim * 4 + 8) + 0x1a);
  (obj->Env).Obj.normal_top.pad = 0x100;
  (obj->Env).Obj.normal_top.vy = 0x100;
  (obj->Env).Obj.normal_top.vz = 0x100;
  (obj->Env).Obj.vert_top.pad = sVar2;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Manim_WaitAnim(struct M_OBJECT *obj /*$s0*/)
 // line 141, offset 0x80022634
	/* begin block 1 */
		// Start line: 324
	/* end block 1 */
	// End Line: 325

void Manim_WaitAnim(M_OBJECT *obj)

{
  while (((obj->Env).Obj.normal_top.vx & 0x4000U) == 0) {
    Task_Next();
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Manim_WaitEvent(struct M_OBJECT *obj /*$s0*/, long Events /*$s1*/)
 // line 148, offset 0x80022674
	/* begin block 1 */
		// Start line: 149
		// Start offset: 0x80022674
		// Variables:
	// 		long Exit; // $v1
	/* end block 1 */
	// End offset: 0x800226C4
	// End Line: 155

	/* begin block 2 */
		// Start line: 338
	/* end block 2 */
	// End Line: 339

long Manim_WaitEvent(M_OBJECT *obj,long Events)

{
  short sVar1;
  
  sVar1 = (obj->Env).Obj.vert_top.pad;
  while ((((int)sVar1 & Events) == 0 && (((obj->Env).Obj.normal_top.vx & 0x4000U) == 0))) {
    Task_Next();
    sVar1 = (obj->Env).Obj.vert_top.pad;
  }
  return (int)sVar1 & Events;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Manim_GetEventTime(struct M_OBJECT *obj /*$a0*/, long Event /*$t1*/)
 // line 159, offset 0x800226dc
	/* begin block 1 */
		// Start line: 160
		// Start offset: 0x800226DC
		// Variables:
	// 		long Time; // $a3
	// 		long i; // $v1
	// 		long fTraj; // $a2
	// 		long index; // $v0
	// 		struct MANIM_99fake *Anm; // $a1
	// 		struct MANIM_7fake *Trans; // $t0
	/* end block 1 */
	// End offset: 0x80022774
	// End Line: 189

	/* begin block 2 */
		// Start line: 361
	/* end block 2 */
	// End Line: 362

long Manim_GetEventTime(M_OBJECT *obj,long Event)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = 0;
  piVar3 = *(int **)(*(int *)((obj->Sq).Data.FatherTrans + 2) +
                     (int)*(short *)((int)&(obj->Env).Version + 2) * 4 + 8);
  iVar2 = (int)((uint)*(ushort *)&(obj->Env).nPivot << 0x10) >> 0x14;
  while (iVar2 < (int)(uint)*(ushort *)((int)piVar3 + 6)) {
    iVar1 = iVar2;
    if (*piVar3 == 0x14000) {
      iVar1 = iVar2 * (uint)*(ushort *)(piVar3 + 1) * 2;
    }
    iVar2 = iVar2 + 1;
    if (((int)*(short *)((int)piVar3 + iVar1 * 8 + 0x1a) & Event) != 0) break;
    iVar4 = iVar4 + 1;
  }
  iVar2 = (int)((uint)*(ushort *)(piVar3 + 2) * 0x13) >> 4;
  if (iVar2 == 0) {
    trap(0x1c00);
  }
  if ((iVar2 == -1) && (iVar4 << 4 == -0x80000000)) {
    trap(0x1800);
  }
  return (iVar4 << 4) / iVar2;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Manim_GetEventTX(struct MANIM_100fake *Ani /*$a0*/, long Anim /*$a1*/, long Event /*$a2*/)
 // line 196, offset 0x800227c4
	/* begin block 1 */
		// Start line: 198
		// Start offset: 0x800227C4
		// Variables:
	// 		short i; // $a3
	// 		short index; // $v0
	// 		struct MANIM_99fake *Anm; // $t0
	// 		struct MANIM_7fake *Trans; // $t3
	/* end block 1 */
	// End offset: 0x80022890
	// End Line: 215

	/* begin block 2 */
		// Start line: 483
	/* end block 2 */
	// End Line: 484

long Manim_GetEventTX(undefined Ani,long Anim,long Event)

{
  int iVar1;
  short *psVar2;
  undefined3 in_register_00000011;
  int iVar3;
  int *piVar4;
  
  piVar4 = *(int **)(CONCAT31(in_register_00000011,Ani) + Anim * 4 + 8);
  iVar3 = 0;
  if (*(ushort *)((int)piVar4 + 6) != 0) {
    do {
      iVar1 = iVar3;
      if (*piVar4 == 0x14000) {
        iVar1 = (int)(short)iVar3 * (uint)*(ushort *)(piVar4 + 1) * 2;
      }
      psVar2 = (short *)((int)piVar4 + ((iVar1 << 0x10) >> 0xd) + 0x14);
      iVar3 = iVar3 + 1;
      if (((int)psVar2[3] & Event) != 0) {
        return (int)*psVar2;
      }
    } while (iVar3 * 0x10000 >> 0x10 < (int)(uint)*(ushort *)((int)piVar4 + 6));
  }
  iVar3 = *(int *)(CONCAT31(in_register_00000011,Ani) + Anim * 4 + 8);
  return (int)*(short *)(iVar3 + ((uint)*(ushort *)(iVar3 + 6) - 1) * 8 + 0x14);
}



// decompiled code
// original method signature: 
// long /*$ra*/ Manim_GetEventTZ(struct MANIM_100fake *Ani /*$a0*/, long Anim /*$a1*/, long Event /*$a2*/)
 // line 218, offset 0x80022898
	/* begin block 1 */
		// Start line: 220
		// Start offset: 0x80022898
		// Variables:
	// 		long i; // $t0
	// 		long index; // $v0
	// 		long fTraj; // $v1
	// 		struct MANIM_99fake *Anm; // $t1
	// 		struct MANIM_7fake *Trans; // $t3
	/* end block 1 */
	// End offset: 0x80022950
	// End Line: 237

	/* begin block 2 */
		// Start line: 542
	/* end block 2 */
	// End Line: 543

long Manim_GetEventTZ(undefined Ani,long Anim,long Event)

{
  int iVar1;
  undefined3 in_register_00000011;
  int iVar2;
  int *piVar3;
  
  piVar3 = *(int **)(CONCAT31(in_register_00000011,Ani) + Anim * 4 + 8);
  iVar2 = 0;
  if (*(ushort *)((int)piVar3 + 6) != 0) {
    do {
      iVar1 = iVar2;
      if (*piVar3 == 0x14000) {
        iVar1 = iVar2 * (uint)*(ushort *)(piVar3 + 1) * 2;
      }
      iVar2 = iVar2 + 1;
      if (((int)*(short *)((int)(piVar3 + iVar1 * 2 + 5) + 6) & Event) != 0) {
        return (int)*(short *)(piVar3 + iVar1 * 2 + 5 + 1);
      }
    } while (iVar2 < (int)(uint)*(ushort *)((int)piVar3 + 6));
  }
  iVar2 = *(int *)(CONCAT31(in_register_00000011,Ani) + Anim * 4 + 8);
  return (int)*(short *)(iVar2 + ((uint)*(ushort *)(iVar2 + 6) - 1) * 8 + 0x18);
}



// decompiled code
// original method signature: 
// long /*$ra*/ Manim_GetSpdX(struct M_OBJECT *mo /*$t0*/)
 // line 240, offset 0x80022958
	/* begin block 1 */
		// Start line: 241
		// Start offset: 0x80022958
		// Variables:
	// 		struct MANIM_99fake *Anm; // $a2
	// 		long t; // $a0
	// 		long Speed; // $a1
	/* end block 1 */
	// End offset: 0x80022A94
	// End Line: 278

	/* begin block 2 */
		// Start line: 595
	/* end block 2 */
	// End Line: 596

long Manim_GetSpdX(M_OBJECT *mo)

{
  short sVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  int iVar5;
  int *piVar6;
  
  piVar6 = *(int **)(*(int *)((mo->Sq).Data.FatherTrans + 2) +
                     (int)*(short *)((int)&(mo->Env).Version + 2) * 4 + 8);
  iVar5 = ((int)((uint)*(ushort *)(piVar6 + 2) * (int)(mo->Env).Obj.normal_top.pad) >> 8) * 0x13 >>
          4;
  if (*piVar6 == 0x14000) {
    iVar2 = (uint)*(ushort *)&(mo->Env).nPivot << 0x10;
    iVar5 = (iVar2 >> 0x10) - iVar5 >> 4;
    sVar1 = *(short *)(piVar6 + (iVar2 >> 0x14) * (uint)*(ushort *)(piVar6 + 1) * 4 + 5);
    if (iVar5 < 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = iVar5 * (uint)*(ushort *)(piVar6 + 1) * 0x10;
    }
  }
  else {
    if ((*(ushort *)((int)piVar6 + 10) & 1) != 0) {
      return 0;
    }
    iVar2 = (uint)*(ushort *)&(mo->Env).nPivot << 0x10;
    iVar3 = (iVar2 >> 0x10) - iVar5 >> 4;
    sVar1 = *(short *)(piVar6 + (iVar2 >> 0x14) * 2 + 5);
    iVar5 = 0;
    if (-1 < iVar3) {
      iVar5 = iVar3 << 3;
    }
  }
  lVar4 = ((int)sVar1 - (int)*(short *)((int)piVar6 + iVar5 + 0x14)) *
          (int)(mo->Env).Obj.normal_top.vy >> 8;
  if ((*(ushort *)((int)piVar6 + 10) & 0x40) == 0) {
    lVar4 = (int)(lVar4 * (uint)*(byte *)((int)(mo->Sq).Header + 3)) >> 6;
  }
  return lVar4;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Manim_GetSpdY(struct M_OBJECT *mo /*$t0*/)
 // line 281, offset 0x80022aa4
	/* begin block 1 */
		// Start line: 282
		// Start offset: 0x80022AA4
		// Variables:
	// 		struct MANIM_99fake *Anm; // $a2
	// 		long t; // $a0
	// 		long Speed; // $a1
	/* end block 1 */
	// End offset: 0x80022BE0
	// End Line: 319

	/* begin block 2 */
		// Start line: 686
	/* end block 2 */
	// End Line: 687

long Manim_GetSpdY(M_OBJECT *mo)

{
  short sVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  int iVar5;
  int *piVar6;
  
  piVar6 = *(int **)(*(int *)((mo->Sq).Data.FatherTrans + 2) +
                     (int)*(short *)((int)&(mo->Env).Version + 2) * 4 + 8);
  iVar5 = ((int)((uint)*(ushort *)(piVar6 + 2) * (int)(mo->Env).Obj.normal_top.pad) >> 8) * 0x13 >>
          4;
  if (*piVar6 == 0x14000) {
    iVar2 = (uint)*(ushort *)&(mo->Env).nPivot << 0x10;
    iVar5 = (iVar2 >> 0x10) - iVar5 >> 4;
    sVar1 = *(short *)((int)piVar6 + (iVar2 >> 0x14) * (uint)*(ushort *)(piVar6 + 1) * 0x10 + 0x16);
    if (iVar5 < 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = iVar5 * (uint)*(ushort *)(piVar6 + 1) * 0x10;
    }
  }
  else {
    if ((*(ushort *)((int)piVar6 + 10) & 1) != 0) {
      return 0;
    }
    iVar2 = (uint)*(ushort *)&(mo->Env).nPivot << 0x10;
    iVar3 = (iVar2 >> 0x10) - iVar5 >> 4;
    sVar1 = *(short *)((int)piVar6 + (iVar2 >> 0x14) * 8 + 0x16);
    iVar5 = 0;
    if (-1 < iVar3) {
      iVar5 = iVar3 << 3;
    }
  }
  lVar4 = ((int)sVar1 - (int)*(short *)((int)piVar6 + iVar5 + 0x16)) *
          (int)(mo->Env).Obj.normal_top.vy >> 8;
  if ((*(ushort *)((int)piVar6 + 10) & 0x40) == 0) {
    lVar4 = (int)(lVar4 * (uint)*(byte *)((int)(mo->Sq).Header + 3)) >> 6;
  }
  return lVar4;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Manim_GetSpdZ(struct M_OBJECT *mo /*$t0*/)
 // line 322, offset 0x80022bf0
	/* begin block 1 */
		// Start line: 323
		// Start offset: 0x80022BF0
		// Variables:
	// 		struct MANIM_99fake *Anm; // $a2
	// 		long t; // $a0
	// 		long Speed; // $a1
	/* end block 1 */
	// End offset: 0x80022D3C
	// End Line: 365

	/* begin block 2 */
		// Start line: 777
	/* end block 2 */
	// End Line: 778

long Manim_GetSpdZ(M_OBJECT *mo)

{
  short sVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  int iVar5;
  int *piVar6;
  
  piVar6 = *(int **)(*(int *)((mo->Sq).Data.FatherTrans + 2) +
                     (int)*(short *)((int)&(mo->Env).Version + 2) * 4 + 8);
  iVar5 = ((int)((uint)*(ushort *)(piVar6 + 2) * (int)(mo->Env).Obj.normal_top.pad) >> 8) * 0x13 >>
          4;
  if (*piVar6 == 0x14000) {
    iVar2 = (uint)*(ushort *)&(mo->Env).nPivot << 0x10;
    iVar5 = (iVar2 >> 0x10) - iVar5 >> 4;
    sVar1 = *(short *)(piVar6 + (iVar2 >> 0x14) * (uint)*(ushort *)(piVar6 + 1) * 4 + 6);
    if (iVar5 < 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = iVar5 * (uint)*(ushort *)(piVar6 + 1) * 0x10;
    }
  }
  else {
    if ((*(ushort *)((int)piVar6 + 10) & 1) != 0) {
      return 0;
    }
    iVar2 = 0;
    if ((*(ushort *)((int)piVar6 + 10) & 0x100) != 0) goto LAB_80022cfc;
    iVar2 = (uint)*(ushort *)&(mo->Env).nPivot << 0x10;
    iVar3 = (iVar2 >> 0x10) - iVar5 >> 4;
    sVar1 = *(short *)(piVar6 + (iVar2 >> 0x14) * 2 + 6);
    iVar5 = 0;
    if (-1 < iVar3) {
      iVar5 = iVar3 << 3;
    }
  }
  iVar2 = (int)sVar1 - (int)*(short *)((int)piVar6 + iVar5 + 0x18);
LAB_80022cfc:
  lVar4 = iVar2 * (int)(mo->Env).Obj.normal_top.vz >> 8;
  if ((*(ushort *)((int)piVar6 + 10) & 0x40) == 0) {
    lVar4 = (int)(lVar4 * (uint)*(byte *)((int)(mo->Sq).Header + 3)) >> 6;
  }
  return lVar4;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Manim_GoToFrame(struct M_OBJECT *obj /*$t2*/, long fa /*$a1*/)
 // line 368, offset 0x80022d44
	/* begin block 1 */
		// Start line: 369
		// Start offset: 0x80022D44
		// Variables:
	// 		struct MANIM_99fake *Anm; // $t1
	// 		long fd; // $v1
	// 		long txd; // $a1
	// 		long tyd; // $a2
	// 		long tzd; // $a3
	// 		long txa; // $a1
	// 		long tya; // $a2
	// 		long tza; // $a3
	// 		long scale; // $v0
	/* end block 1 */
	// End offset: 0x80022E18
	// End Line: 404

	/* begin block 2 */
		// Start line: 878
	/* end block 2 */
	// End Line: 879

void Manim_GoToFrame(M_OBJECT *obj,long fa)

{
  ushort uVar1;
  uint local_10;
  int *piVar2;
  long tz;
  int *piVar3;
  int *piVar4;
  
  piVar4 = *(int **)(*(int *)((obj->Sq).Data.FatherTrans + 2) +
                     (int)*(short *)((int)&(obj->Env).Version + 2) * 4 + 8);
  uVar1 = *(ushort *)&(obj->Env).nPivot;
  *(short *)&(obj->Env).nPivot = (short)(fa << 4);
  if (((*(ushort *)((int)piVar4 + 10) & 1) == 0) && (*piVar4 != 0x14000)) {
    piVar2 = piVar4 + ((int)((uint)uVar1 << 0x10) >> 0x14) * 2;
    piVar3 = piVar4 + fa * 2;
    if ((*(ushort *)((int)piVar4 + 10) & 0x100) == 0) {
      tz = (int)*(short *)(piVar3 + 6) - (int)*(short *)(piVar2 + 6);
    }
    else {
      tz = 0;
    }
    if ((*(ushort *)((int)piVar4 + 10) & 0x40) == 0) {
      local_10 = (uint)*(byte *)((int)(obj->Sq).Header + 3);
    }
    else {
      local_10 = 0x40;
    }
    Manim_Move(obj,(int)*(short *)(piVar3 + 5) - (int)*(short *)(piVar2 + 5),
               (int)*(short *)((int)piVar3 + 0x16) - (int)*(short *)((int)piVar2 + 0x16),tz,local_10
              );
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Manim_PlayAnim(struct M_OBJECT *obj /*$s2*/)
 // line 407, offset 0x80022e28
	/* begin block 1 */
		// Start line: 408
		// Start offset: 0x80022E28
		// Variables:
	// 		struct MANIM_99fake *Anm; // $s0
	// 		long fd; // $s3
	// 		long fa; // $s1
	// 		long scale; // $t5
	// 		long fraca; // $t4
	// 		long fracd; // $t3
	// 		long txd; // $a1
	// 		long tyd; // $a2
	// 		long tzd; // $a3
	// 		long txa; // $a1
	// 		long tya; // $a2
	// 		long tza; // $a3
	// 		long start; // $v0
	// 		long end; // $t2
	// 		long speed; // $a0
	// 		long fTraj; // $s4
	/* end block 1 */
	// End offset: 0x80023314
	// End Line: 569

	/* begin block 2 */
		// Start line: 981
	/* end block 2 */
	// End Line: 982

void Manim_PlayAnim(M_OBJECT *obj)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  long tx;
  int iVar8;
  long ty;
  int iVar9;
  long tz;
  int *piVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint scale;
  int *piVar14;
  uint uVar15;
  int iVar16;
  
  (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0x3fff;
  piVar14 = *(int **)(*(int *)((obj->Sq).Data.FatherTrans + 2) +
                      (int)*(short *)((int)&(obj->Env).Version + 2) * 4 + 8);
  bVar4 = *piVar14 == 0x14000;
  if (((*(ushort *)((int)piVar14 + 10) & 0x40) != 0) || (bVar4)) {
    scale = 0x40;
  }
  else {
    scale = (uint)*(byte *)((int)(obj->Sq).Header + 3);
  }
  if (((obj->Env).Obj.n_normal != 0) && (((obj->Env).Obj.normal_top.vx & 0x20U) == 0)) {
    (obj->Env).Obj.vert_top.vz = (obj->Env).Obj.vert_top.vz + 1;
  }
  if (((obj->Env).Obj.normal_top.vx & 1U) == 0) {
    if (bVar4) {
      iVar5 = ((int)((uint)*(ushort *)&(obj->Env).nPivot << 0x10) >> 0x14) *
              (uint)*(ushort *)(piVar14 + 1) * 0x10;
    }
    else {
      iVar5 = ((int)((uint)*(ushort *)&(obj->Env).nPivot << 0x10) >> 0x14) << 3;
    }
    (obj->Env).Obj.vert_top.pad = *(short *)((int)piVar14 + iVar5 + 0x1a);
    return;
  }
  (obj->Env).Obj.vert_top.pad = 0;
  iVar5 = (int)((uint)*(ushort *)(piVar14 + 2) * 0x13) >> 4;
  uVar1 = *(ushort *)((int)piVar14 + 6);
  iVar11 = (uint)uVar1 - 1;
  if (iVar11 < 3) {
    iVar5 = iVar11 * 0x10;
  }
  uVar2 = *(ushort *)&(obj->Env).nPivot;
  iVar6 = (uint)uVar2 << 0x10;
  iVar16 = iVar6 >> 0x14;
  iVar5 = iVar5 * (int)(obj->Env).Obj.normal_top.pad >> 8;
  uVar15 = (iVar6 >> 0x10) + iVar5;
  uVar12 = (uint)uVar2 & 0xf;
  if (iVar11 < (int)uVar15 >> 4) {
    uVar3 = (obj->Env).Obj.normal_top.vx;
    (obj->Env).Obj.normal_top.vx = uVar3 | 0x8000;
    if ((uVar3 & 2) == 0) {
      (obj->Env).Obj.normal_top.vx = uVar3 & 0xfffe | 0x8000;
      return;
    }
    uVar15 = (uVar15 + iVar11 * -0x10) - 0x10;
    if (bVar4) {
      uVar3 = (obj->Env).Obj.vert_top.pad;
      iVar6 = ((int)uVar15 >> 4) * (uint)*(ushort *)(piVar14 + 1) * 0x10;
    }
    else {
      iVar6 = ((int)uVar15 >> 4) * 8;
      uVar3 = (obj->Env).Obj.vert_top.pad;
    }
    (obj->Env).Obj.vert_top.pad = uVar3 | *(ushort *)((int)piVar14 + iVar6 + 0x1a);
  }
  uVar13 = uVar15 & 0xf;
  if (iVar11 <= (int)(uVar15 + iVar5) >> 4) {
    (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx | 0x4000;
  }
  *(short *)&(obj->Env).nPivot = (short)uVar15;
  iVar5 = (int)uVar15 >> 4;
  if (((*(ushort *)((int)piVar14 + 10) & 1) != 0) || (bVar4)) goto LAB_800232a0;
  piVar7 = piVar14 + iVar16 * 2;
  iVar6 = (int)*(short *)(piVar7 + 5);
  iVar8 = (int)*(short *)((int)piVar7 + 0x16);
  iVar9 = 0;
  if ((*(ushort *)((int)piVar14 + 10) & 0x100) == 0) {
    iVar9 = (int)*(short *)(piVar7 + 6);
  }
  if ((uVar2 & 0xf) != 0) {
    piVar10 = piVar14 + (iVar16 + 1) * 2;
    piVar7 = piVar14 + iVar16 * 2;
    iVar6 = iVar6 + ((int)(((int)*(short *)(piVar10 + 5) - (int)*(short *)(piVar7 + 5)) * uVar12) >>
                    4);
    iVar8 = iVar8 + ((int)(((int)*(short *)((int)piVar10 + 0x16) -
                           (int)*(short *)((int)piVar7 + 0x16)) * uVar12) >> 4);
    if ((*(ushort *)((int)piVar14 + 10) & 0x100) == 0) {
      iVar9 = iVar9 + ((int)(((int)*(short *)(piVar10 + 6) - (int)*(short *)(piVar7 + 6)) * uVar12)
                      >> 4);
    }
  }
  if (((int)(obj->Env).Obj.normal_top.vx & 0x8000U) == 0) {
    piVar7 = piVar14 + iVar5 * 2;
    tx = (int)*(short *)(piVar7 + 5) - iVar6;
    ty = (int)*(short *)((int)piVar7 + 0x16) - iVar8;
    if ((*(ushort *)((int)piVar14 + 10) & 0x100) == 0) {
      tz = (int)*(short *)(piVar7 + 6) - iVar9;
    }
    else {
LAB_800231f4:
      tz = 0;
    }
  }
  else {
    if (((obj->Env).Obj.normal_top.vx & 2U) == 0) {
      tz = 0;
      ty = 0;
      tx = 0;
    }
    else {
      piVar7 = piVar14 + iVar5 * 2;
      tx = (((int)*(short *)(piVar14 + (uint)uVar1 * 2 + 5) - iVar6) - (int)*(short *)(piVar14 + 5))
           + (int)*(short *)(piVar7 + 5);
      ty = (((int)*(short *)((int)(piVar14 + (uint)uVar1 * 2) + 0x16) - iVar8) -
           (int)*(short *)((int)piVar14 + 0x16)) + (int)*(short *)((int)piVar7 + 0x16);
      if ((*(ushort *)((int)piVar14 + 10) & 0x100) != 0) goto LAB_800231f4;
      tz = (((int)*(short *)(piVar14 + iVar11 * 2 + 6) - iVar9) - (int)*(short *)(piVar14 + 6)) +
           (int)*(short *)(piVar7 + 6);
    }
  }
  if (uVar13 != 0) {
    piVar10 = piVar14 + (iVar5 + 1) * 2;
    piVar7 = piVar14 + iVar5 * 2;
    tx = tx + ((int)(((int)*(short *)(piVar10 + 5) - (int)*(short *)(piVar7 + 5)) * uVar13) >> 4);
    ty = ty + ((int)(((int)*(short *)((int)piVar10 + 0x16) - (int)*(short *)((int)piVar7 + 0x16)) *
                    uVar13) >> 4);
    if ((*(ushort *)((int)piVar14 + 10) & 0x100) == 0) {
      tz = tz + ((int)(((int)*(short *)(piVar10 + 6) - (int)*(short *)(piVar7 + 6)) * uVar13) >> 4);
    }
  }
  Manim_Move(obj,tx,ty,tz,scale);
LAB_800232a0:
  iVar11 = iVar16 + 1;
  if ((0 < iVar5 - iVar16) && (iVar11 <= iVar5)) {
    piVar7 = piVar14 + iVar11 * 2;
    do {
      if (bVar4) {
        (obj->Env).Obj.vert_top.pad =
             (obj->Env).Obj.vert_top.pad |
             *(ushort *)((int)piVar14 + iVar11 * (uint)*(ushort *)(piVar14 + 1) * 0x10 + 0x1a);
      }
      else {
        (obj->Env).Obj.vert_top.pad = (obj->Env).Obj.vert_top.pad | *(ushort *)((int)piVar7 + 0x1a);
      }
      iVar11 = iVar11 + 1;
      piVar7 = piVar7 + 2;
    } while (iVar11 <= iVar5);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Manim_Move(struct M_OBJECT *mo /*$s4*/, long tx /*$s1*/, long ty /*$s2*/, long tz /*$s3*/, long scale /*stack 16*/)
 // line 572, offset 0x80023334
	/* begin block 1 */
		// Start line: 573
		// Start offset: 0x80023334
		// Variables:
	// 		long r; // $s0
	// 		long rc; // $s0
	// 		long rs; // $v0
	/* end block 1 */
	// End offset: 0x800233FC
	// End Line: 595

	/* begin block 2 */
		// Start line: 1343
	/* end block 2 */
	// End Line: 1344

void Manim_Move(M_OBJECT *mo,long tx,long ty,long tz,long scale)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  short sVar5;
  
  iVar1 = (int)(mo->Env).Obj.normal_top.vy;
  iVar2 = *(int *)&(mo->Sq).Data.Flag;
  iVar4 = (tx * iVar1 >> 8) * scale >> 6;
  iVar1 = (ty * iVar1 >> 8) * scale >> 6;
  _sVar5 = (tz * (int)(mo->Env).Obj.normal_top.vz >> 8) * scale >> 6;
  sVar5 = (short)_sVar5;
  if (iVar2 != 0) {
    iVar4 = iVar4 * iVar2 >> 0xc;
    iVar1 = iVar1 * iVar2 >> 0xc;
    sVar5 = (short)(_sVar5 * iVar2 >> 0xc);
  }
  uVar3 = SEXT24((mo->sit->rot).vz);
  iVar2 = rcos(uVar3);
  _sVar5 = rsin(uVar3);
  (mo->sit->pos).vx = (mo->sit->pos).vx + (short)((iVar2 * iVar4 - _sVar5 * iVar1) + 0x800 >> 0xc);
  (mo->sit->pos).vy = (mo->sit->pos).vy + (short)(_sVar5 * iVar4 + iVar2 * iVar1 + 0x800 >> 0xc);
  (mo->sit->pos).vz = (mo->sit->pos).vz + sVar5;
  return;
}



// decompiled code
// original method signature: 
// void * /*$ra*/ Manim_DisplayActor(struct M_OBJECT *obj /*$s3*/, void *Prims /*$s4*/, long mini_x /*$s0*/, long maxi_x /*$s1*/)
 // line 610, offset 0x800234c8
	/* begin block 1 */
		// Start line: 611
		// Start offset: 0x800234C8
		// Variables:
	// 		struct MANIM_7fake *box; // $a0
	// 		struct MANIM_5fake m; // stack offset -128
	// 		struct MANIM_5fake matrix; // stack offset -96
	// 		struct MANIM_7fake v[4]; // stack offset -64
	// 		long z; // $s2
	// 		long zs; // $s5
	/* end block 1 */
	// End offset: 0x80023944
	// End Line: 701

	/* begin block 2 */
		// Start line: 1441
	/* end block 2 */
	// End Line: 1442

void * Manim_DisplayActor(M_OBJECT *obj,void *Prims,long mini_x,long maxi_x)

{
  int iVar1;
  int iVar2;
  undefined4 in_zero;
  undefined4 in_at;
  _D3_OBJECT *o;
  _ROTMATRIX *p_Var3;
  int z;
  long zs;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  
  o = obj->sit;
  setCopReg(2,in_zero,*(undefined4 *)&o->pos);
  setCopReg(2,in_at,*(undefined4 *)&(o->pos).vz);
  copFunction(2,0x486012);
  z = getCopReg(2,0x19);
  iVar1 = getCopReg(2,0x1a);
  iVar2 = getCopReg(2,0x1b);
  setCopControlWord(2,0x2800,z + Cam_Matrix.t[0]);
  setCopControlWord(2,0x3000,iVar1 + Cam_Matrix.t[1]);
  setCopControlWord(2,0x3800,iVar2 + Cam_Matrix.t[2]);
  GtxTmd_RotTransPersN(&o->b_box,Tmd_2DSpeed,8);
  z = (int)Tmd_2DSpeed->vz + (int)Tmd_2DSpeed[1].vz + (int)Tmd_2DSpeed[2].vz +
      (int)Tmd_2DSpeed[3].vz +
      (int)Tmd_2DSpeed[4].vz + (int)Tmd_2DSpeed[5].vz + (int)Tmd_2DSpeed[6].vz +
      (int)Tmd_2DSpeed[7].vz;
  if (z < 0) {
    z = z + 0x1f;
  }
  z = z >> 5;
  if (((2 < z) && (z < (int)Scr_OtSize)) &&
     ((-1 < Tmd_2DSpeed->vy ||
      (((-1 < Tmd_2DSpeed[1].vy || (-1 < Tmd_2DSpeed[2].vy)) || (-1 < Tmd_2DSpeed[3].vy)))))) {
    if (((((Tmd_2DSpeed[4].vy < Scr_H) || (Tmd_2DSpeed[5].vy < Scr_H)) ||
         ((Tmd_2DSpeed[6].vy < Scr_H || (Tmd_2DSpeed[7].vy < Scr_H)))) &&
        ((((mini_x <= (int)Tmd_2DSpeed->vx || (mini_x <= (int)Tmd_2DSpeed[1].vx)) ||
          ((mini_x <= (int)Tmd_2DSpeed[2].vx ||
           (((mini_x <= (int)Tmd_2DSpeed[3].vx || (mini_x <= (int)Tmd_2DSpeed[4].vx)) ||
            (mini_x <= (int)Tmd_2DSpeed[5].vx)))))) ||
         ((mini_x <= (int)Tmd_2DSpeed[6].vx || (mini_x <= (int)Tmd_2DSpeed[7].vx)))))) &&
       (((int)Tmd_2DSpeed->vx < maxi_x ||
        ((((int)Tmd_2DSpeed[1].vx < maxi_x || ((int)Tmd_2DSpeed[2].vx < maxi_x)) ||
         (((int)Tmd_2DSpeed[3].vx < maxi_x ||
          (((((int)Tmd_2DSpeed[4].vx < maxi_x || ((int)Tmd_2DSpeed[5].vx < maxi_x)) ||
            ((int)Tmd_2DSpeed[6].vx < maxi_x)) || ((int)Tmd_2DSpeed[7].vx < maxi_x)))))))))) {
      obj->sit->collision_state = obj->sit->collision_state | 0x80;
      o = obj->sit;
      if ((o->display_mode & 0x80U) != 0) {
        zs = D3_SetShadow(o,(char)*(undefined4 *)&(obj->Env).Obj.vert_top + (char)Scr_Frame * '(');
        o = obj->sit;
      }
      if ((o->display_mode & 8U) != 0) {
        Light_SetMatrix(o);
      }
      Light_RotMatrix(obj->sit,0x80);
      setCopControlWord(2,0x4000,local_80);
      setCopControlWord(2,0x4800,local_7c);
      setCopControlWord(2,0x5000,local_78);
      setCopControlWord(2,0x5800,local_74);
      setCopControlWord(2,0x6000,local_70);
      p_Var3 = obj->sit->matrices;
      setCopControlWord(2,0x8000,*(undefined4 *)p_Var3[1].m);
      setCopControlWord(2,0x8800,*(undefined4 *)(p_Var3[1].m + 2));
      setCopControlWord(2,0x9000,*(undefined4 *)(p_Var3[1].m + 4));
      setCopControlWord(2,0x9800,*(undefined4 *)(p_Var3[1].m + 6));
      setCopControlWord(2,0xa000,*(undefined4 *)(p_Var3[1].m + 8));
      if (((obj->Env).Obj.normal_top.vx & 4U) == 0) {
        DAT_800b016c = 0;
        DAT_800b016a = 0;
      }
      else {
        DAT_800b016a = *(undefined2 *)&(obj->Env).Obj.n_vert;
        DAT_800b016c = *(undefined2 *)((int)&(obj->Env).Obj.n_vert + 2);
      }
      Target = 0;
      Prims = Manim_DisplayMotion(obj,Prims,z,zs);
    }
  }
  setCopControlWord(2,0,Cam_Matrix.m[0]._0_4_);
  setCopControlWord(2,0x800,Cam_Matrix.m._4_4_);
  setCopControlWord(2,0x1000,Cam_Matrix.m[1]._2_4_);
  setCopControlWord(2,0x1800,Cam_Matrix.m[2]._0_4_);
  setCopControlWord(2,0x2000,Cam_Matrix._16_4_);
  setCopControlWord(2,0x2800,Cam_Matrix.t[0]);
  setCopControlWord(2,0x3000,Cam_Matrix.t[1]);
  setCopControlWord(2,0x3800,Cam_Matrix.t[2]);
  return Prims;
}



// decompiled code
// original method signature: 
// void * /*$ra*/ Manim_DisplayMotion(struct M_OBJECT *obj /*$s2*/, void *Prims /*$s1*/, long z /*stack 8*/, long zs /*$s7*/)
 // line 708, offset 0x800239b4
	/* begin block 1 */
		// Start line: 709
		// Start offset: 0x800239B4
		// Variables:
	// 		long numobj; // $fp
	// 		long nObj; // stack offset -56
	// 		long ot_size; // $s5
	// 		long dz; // $s3
	// 		void *tmd; // $s6
	// 		void *ot_start; // $s0
	// 		struct MANIM_31fake *p; // stack offset -52
	/* end block 1 */
	// End offset: 0x80023D7C
	// End Line: 794

	/* begin block 2 */
		// Start line: 1659
	/* end block 2 */
	// End Line: 1660

void * Manim_DisplayMotion(M_OBJECT *obj,void *Prims,long z,long zs)

{
  ushort uVar1;
  _SCREEN *p_Var2;
  code *pcVar3;
  uint *puVar4;
  ulong *puVar5;
  ulong *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int local_38;
  int local_2c;
  
  puVar4 = (uint *)(*(int *)&(obj->Env).Obj.vert_top + (int)Scr_Frame * 0x28);
  if ((obj->sit->display_mode & 0x1000U) == 0) {
    local_38 = 1;
  }
  else {
    local_38 = *(int *)(*(int *)(obj->Sq).Data.FatherTrans + 8);
  }
  iVar10 = 0;
  if (0 < local_38) {
    local_2c = 0xc;
    do {
      if ((obj->sit->display_mode & 0x1000U) == 0) {
        Manim_EnvRotTransPers(obj);
        iVar9 = *(int *)(*(int *)(obj->Sq).Data.FatherTrans + 8);
      }
      else {
        Manim_TrajRotTransPers(obj,(short)iVar10);
        iVar9 = *(int *)(obj->Sq).Data.FatherTrans + local_2c;
      }
      if (*(short *)((int)&obj->sit->b_hurt + 2) != 0) {
        Prims = Manim_DisplayShapes(obj->sit,Prims);
      }
      pcVar3 = (code *)(obj->Env).Obj.n_normal;
      if (((pcVar3 == (code *)0x0) ||
          (Prims = (void *)(*pcVar3)(obj,Prims), (obj->Env).Obj.n_normal == 0)) ||
         (((obj->Env).Obj.normal_top.vx & 0x10U) != 0)) {
        p_Var2 = Scr;
        uVar1 = obj->sit->display_mode;
        if ((uVar1 & 0x100) == 0) {
          iVar8 = (int)Scr_OtSize;
          puVar5 = Scr->ot;
          iVar7 = 0;
          puVar6 = (ulong *)Prims;
          if ((uVar1 & 0x80) != 0) {
            zs = zs + -0x10;
            puVar6 = (ulong *)Prims;
            if ((0 < zs) && (puVar6 = (ulong *)Prims, zs < iVar8)) {
              *puVar4 = *puVar4 & 0xff000000 | puVar5[zs] & 0xffffff;
              p_Var2->ot[zs] = p_Var2->ot[zs] & 0xff000000 | (uint)puVar4 & 0xffffff;
              puVar6 = (ulong *)Prims;
            }
          }
        }
        else {
          iVar7 = z + -0x40;
          ClearOTagR((undefined4 *)Prims);
          iVar8 = 0x80;
          puVar5 = (ulong *)Prims;
          puVar6 = (ulong *)Prims + 0x80;
          if ((obj->sit->display_mode & 0x80U) != 0) {
            *puVar4 = *puVar4 & 0xff000000 | ((ulong *)Prims)[0x7f] & 0xffffff;
            ((ulong *)Prims)[0x7f] = ((ulong *)Prims)[0x7f] & 0xff000000 | (uint)puVar4 & 0xffffff;
            puVar5 = (ulong *)Prims;
            puVar6 = (ulong *)Prims + 0x80;
          }
        }
        if ((obj->sit->display_mode & 0x400U) == 0) {
          Prims = (void *)GtxTmx_DisplayLON(iVar9,puVar6,puVar5,iVar8,iVar7,obj->sit->color);
        }
        else {
          Prims = (void *)GtxTmx_Display3LON(iVar9,puVar6,puVar5,iVar8,iVar7,obj->sit->color,
                                             Main_TextContext.Font.ascii_tab._20_4_);
        }
        p_Var2 = Scr;
        if ((obj->sit->display_mode & 0x100U) != 0) {
          iVar9 = (z + -0x10) * 4;
          if (z + -0x10 < 2) {
            iVar9 = 8;
          }
          iVar7 = z + -0x10;
          *puVar5 = *puVar5 & 0xff000000 | *(uint *)(iVar9 + (int)Scr->ot) & 0xffffff;
          if (iVar7 < 2) {
            iVar7 = 2;
          }
          p_Var2->ot[iVar7] =
               p_Var2->ot[iVar7] & 0xff000000 | (uint)(puVar5 + iVar8 + -1) & 0xffffff;
        }
      }
      iVar10 = iVar10 + 1;
      local_2c = local_2c + 0x1c;
      Prims = D3_DisplayBox(obj->sit,Prims);
    } while (iVar10 < local_38);
  }
  return (ulong *)Prims;
}



// decompiled code
// original method signature: 
// void * /*$ra*/ Manim_DisplayShapes(struct _D3_OBJECT *o /*$fp*/, void *Prims /*$s0*/)
 // line 798, offset 0x80023db0
	/* begin block 1 */
		// Start line: 799
		// Start offset: 0x80023DB0
		// Variables:
	// 		long i; // $s4
	// 		long z; // $s0
	// 		short w; // stack offset -48
	// 		short h; // stack offset -46
	// 		short mark; // $s6
	// 		struct _D3_ANIMSHP *anim; // $s2
	// 		struct MANIM_7fake *s; // $a0
	// 		struct MANIM_31fake *p; // $s3
	// 		struct MANIM_70fake shp; // stack offset -64
	// 		struct _TMD_2D *pvert; // $a1
	/* end block 1 */
	// End offset: 0x8002406C
	// End Line: 865

	/* begin block 2 */
		// Start line: 2122
	/* end block 2 */
	// End Line: 2123

void * Manim_DisplayShapes(_D3_OBJECT *o,void *Prims)

{
  _SCREEN *p_Var1;
  short sVar2;
  uint uVar3;
  _D3_ANIMSHP *p_Var4;
  _TMD_2D *p_Var5;
  int iVar6;
  _D3_ANIMSHP *anim;
  SHAPE_31fake *prim;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  SHAPE_68fake local_40;
  short local_30;
  short local_2e [3];
  
  anim = (_D3_ANIMSHP *)o->shapes;
  local_40.file = Pvl_Pcl;
  iVar7 = 0;
  sVar2 = Shp_GetMark(Pvl_Pcl,(int)Pvl_File->crc);
  prim = (SHAPE_31fake *)Prims;
  if (0 < *(short *)((int)&o->b_hurt + 2)) {
    do {
      if ((anim->display & 1) != 0) {
        p_Var4 = anim + 1;
        p_Var5 = Tmd_2D + (int)*(short *)(anim + 1);
        iVar6 = (int)((uint)(ushort)p_Var5->vz << 0x10) >> 0x12;
        if (1 < anim->n) {
          p_Var4 = p_Var4 + (uint)(byte)anim->current;
        }
        local_40.shape = p_Var4->reserved + sVar2;
        local_40.x = p_Var5->vx;
        local_40.y = p_Var5->vy;
        *(undefined *)
         (*(int *)((int)Pvl_Pcl + ((int)p_Var4->reserved + (int)sVar2) * 4 + 0x10) + 0x11) = 1;
        if ((10 < iVar6) && (iVar6 < (int)Scr_OtSize)) {
          Shp_GetWH(&local_40,&local_30,local_2e);
          iVar8 = (int)local_30 * (int)Scr_GeomScreen;
          iVar9 = iVar8 / iVar6;
          if (iVar6 == 0) {
            trap(0x1c00);
          }
          if ((iVar6 == -1) && (iVar8 == -0x80000000)) {
            trap(0x1800);
          }
          iVar8 = (int)local_2e[0] * (int)Scr_GeomScreen;
          iVar10 = iVar8 / iVar6;
          if (iVar6 == 0) {
            trap(0x1c00);
          }
          if ((iVar6 == -1) && (iVar8 == -0x80000000)) {
            trap(0x1800);
          }
          local_30 = (short)iVar9;
          local_2e[0] = (short)iVar10;
          Shp_SetPolyFT4(prim,&local_40,(short)((uint)((iVar9 + 1) * 0x10000) >> 0x10),
                         (short)((uint)((iVar10 + 1) * 0x10000) >> 0x10));
          *(char *)((int)Prims + 0x14) = *(char *)((int)Prims + 0x14) + '\x01';
          *(char *)((int)Prims + 0x24) = *(char *)((int)Prims + 0x24) + '\x01';
          *(char *)((int)Prims + 0x1d) = *(char *)((int)Prims + 0x1d) + '\x01';
          *(char *)((int)Prims + 0x25) = *(char *)((int)Prims + 0x25) + '\x01';
          p_Var1 = Scr;
          Prims = (void *)((int)Prims + 0x28);
          prim->tag = prim->tag & 0xff000000 | Scr->ot[iVar6 + -10] & 0xffffff;
          uVar3 = (uint)prim & 0xffffff;
          prim = prim + 1;
          (p_Var1->ot + iVar6)[-10] = (p_Var1->ot + iVar6)[-10] & 0xff000000 | uVar3;
        }
        D3_IncShpAnim(anim);
      }
      iVar7 = iVar7 + 1;
      anim = anim + (uint)anim->n + 1;
    } while (iVar7 < (int)*(short *)((int)&o->b_hurt + 2));
  }
  return Prims;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Manim_EnvRotTransPers(struct M_OBJECT *Mobject /*$v1*/)
 // line 1038, offset 0x800240a0
	/* begin block 1 */
		// Start line: 1039
		// Start offset: 0x800240A0
		// Variables:
	// 		long SaveSp; // $s0
	// 		long sp; // $sp
	/* end block 1 */
	// End offset: 0x800240A0
	// End Line: 1039

	/* begin block 2 */
		// Start line: 2762
	/* end block 2 */
	// End Line: 2763

/* WARNING: This function may have set the stack pointer */

void Manim_EnvRotTransPers(M_OBJECT *Mobject)

{
  DAT_1f8003c8 = &Mobject->sit->pos;
  DAT_1f8003cc = &Mobject->sit->rot;
  DAT_1f8003d0 = *(long *)&(Mobject->Sq).Data.Flag;
  DAT_1f8003d4 = Manim_ModifyAngle;
  Motion_EnvRotTransPers
            ((MOTION_94fake *)(Mobject->Sq).Header,*(MOTION_96fake **)(Mobject->Sq).Data.FatherTrans
             ,(char)*(undefined4 *)
                     (*(int *)((Mobject->Sq).Data.FatherTrans + 2) +
                      (int)*(short *)((int)&(Mobject->Env).Version + 2) * 4 + 8),
             *(short *)&(Mobject->Env).nPivot >> 4,DAT_1f8003c8._0_1_,DAT_1f8003cc._0_1_,
             DAT_1f8003d0,Manim_ModifyAngle);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Manim_ModifyAngle(unsigned short Flag /*$a2*/, struct MANIM_7fake *Angle /*$a1*/)
 // line 1072, offset 0x80024128
	/* begin block 1 */
		// Start line: 2837
	/* end block 1 */
	// End Line: 2838

void Manim_ModifyAngle(ushort Flag,undefined Angle)

{
  undefined3 in_register_00000015;
  ushort *puVar1;
  
  puVar1 = (ushort *)CONCAT31(in_register_00000015,Angle);
  if (((Flag & 1) != 0) && ((DAT_800b016a != 0 || (DAT_800b016c != 0)))) {
    *puVar1 = 0x400;
    puVar1[2] = puVar1[2] + DAT_800b016a & 0xfff;
    puVar1[1] = puVar1[1] + DAT_800b016c & 0xfff;
  }
  if ((Flag & 4) != 0) {
    *puVar1 = *puVar1 + DAT_800b016c & 0xfff;
    puVar1[1] = puVar1[1] -
                (short)((int)(((int)((uint)DAT_800b016a << 0x10) >> 0x10) +
                             (((uint)DAT_800b016a << 0x10) >> 0x1f)) >> 1) & 0xfff;
  }
  if ((Flag & 8) != 0) {
    puVar1[1] = puVar1[1] - DAT_800b016a & 0xfff;
  }
  if ((Flag & 0x510) != 0) {
    puVar1[2] = puVar1[2] + DAT_800b016c & 0xfff;
  }
  if ((Flag & 0x200) != 0) {
    puVar1[1] = puVar1[1] - DAT_800b016c & 0xfff;
  }
  if ((Flag & 0x800) != 0) {
    *puVar1 = *puVar1 - DAT_800b016c & 0xfff;
  }
  if ((Flag & 0x80) != 0) {
    *puVar1 = *puVar1 + DAT_800b016a & 0xfff;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Manim_TrajRotTransPers(struct M_OBJECT *Mobject /*$a0*/, short NumObj /*$a1*/)
 // line 1120, offset 0x80024298
	/* begin block 1 */
		// Start line: 1121
		// Start offset: 0x80024298
		// Variables:
	// 		struct MANIM_5fake Matrix; // stack offset -56
	// 		struct MANIM_99fake *AnItem; // $s0
	// 		struct MANIM_74fake *Tmd; // $a2
	// 		struct MANIM_93fake *TmdObj; // $s1
	// 		long An; // $v0
	// 		long SaveSp; // $s3
	// 		long sp; // $sp
	/* end block 1 */
	// End offset: 0x800243C8
	// End Line: 1161

	/* begin block 2 */
		// Start line: 2933
	/* end block 2 */
	// End Line: 2934

/* WARNING: This function may have set the stack pointer */

void Manim_TrajRotTransPers(M_OBJECT *Mobject,short NumObj)

{
  undefined4 in_zero;
  undefined4 in_at;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(*(int *)((Mobject->Sq).Data.FatherTrans + 2) +
                   (int)*(short *)((int)&(Mobject->Env).Version + 2) * 4 + 8);
  uVar2 = *(undefined4 *)(Mobject->Sq).Data.FatherTrans;
  iVar3 = ((int)((uint)*(ushort *)&(Mobject->Env).nPivot << 0x10) >> 0x14) *
          (uint)*(ushort *)(iVar4 + 4) + (int)NumObj;
  iVar1 = iVar4 + (iVar3 * 0x20000 >> 0xd);
  Root = *(undefined2 *)(iVar1 + 0x14);
  DAT_800b017a = *(undefined2 *)(iVar1 + 0x16);
  DAT_800b017c = *(undefined2 *)(iVar1 + 0x18);
  setCopReg(2,in_zero,*(undefined4 *)&Mobject->sit->pos);
  setCopReg(2,in_at,*(undefined4 *)&(Mobject->sit->pos).vz);
  copFunction(2,0x486012);
  DAT_1f8003dc = getCopReg(2,0x19);
  DAT_1f8003e0 = getCopReg(2,0x1a);
  DAT_1f8003e4 = getCopReg(2,0x1b);
  DAT_1f8003dc = DAT_1f8003dc + Cam_Matrix.t[0];
  DAT_1f8003e0 = DAT_1f8003e0 + Cam_Matrix.t[1];
  DAT_1f8003e4 = DAT_1f8003e4 + Cam_Matrix.t[2];
  if ((Mobject->sit->display_mode & 2U) != 0) {
    RotMatrix((short *)&Mobject->sit->rot,(undefined2 *)&DAT_1f8003c8);
    MulRotMatrix(&DAT_1f8003c8);
  }
  Manim_TrajProjection
            ((char)uVar2 + (char)NumObj * '\x1c' + '\f',(char)iVar4,200,
             (short)((uint)((iVar3 * 2 + 1) * 0x10000) >> 0x10));
  setCopControlWord(2,0,Cam_Matrix.m[0]._0_4_);
  setCopControlWord(2,0x800,Cam_Matrix.m._4_4_);
  setCopControlWord(2,0x1000,Cam_Matrix.m[1]._2_4_);
  setCopControlWord(2,0x1800,Cam_Matrix.m[2]._0_4_);
  setCopControlWord(2,0x2000,Cam_Matrix._16_4_);
  setCopControlWord(2,0x2800,Cam_Matrix.t[0]);
  setCopControlWord(2,0x3000,Cam_Matrix.t[1]);
  setCopControlWord(2,0x3800,Cam_Matrix.t[2]);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Manim_TrajProjection(struct MANIM_93fake *TmdObj /*$s1*/, struct MANIM_99fake *AnItem /*$a1*/, struct MANIM_5fake *Father /*$s0*/, short index /*$a3*/)
 // line 1173, offset 0x8002444c
	/* begin block 1 */
		// Start line: 1174
		// Start offset: 0x8002444C
		// Variables:
	// 		struct MANIM_5fake Matrix; // stack offset -48
	/* end block 1 */
	// End offset: 0x800245D8
	// End Line: 1215

	/* begin block 2 */
		// Start line: 3097
	/* end block 2 */
	// End Line: 3098

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Manim_TrajProjection(undefined TmdObj,undefined AnItem,undefined Father,short index)

{
  undefined4 in_zero;
  undefined4 in_at;
  int iVar1;
  undefined3 in_register_00000011;
  undefined4 *puVar2;
  undefined3 in_register_00000015;
  undefined3 in_register_00000019;
  undefined4 *puVar3;
  ushort auStack48 [10];
  int local_1c;
  int local_18;
  int local_14;
  
  puVar3 = (undefined4 *)CONCAT31(in_register_00000019,Father);
  puVar2 = (undefined4 *)CONCAT31(in_register_00000011,TmdObj);
  VerTop = *puVar2;
  NormTop = puVar2[2];
  setCopControlWord(2,0,*puVar3);
  setCopControlWord(2,0x800,puVar3[1]);
  setCopControlWord(2,0x1000,puVar3[2]);
  setCopControlWord(2,0x1800,puVar3[3]);
  setCopControlWord(2,0x2000,puVar3[4]);
  setCopReg(2,in_zero,_Root);
  setCopReg(2,in_at,_DAT_800b017c);
  copFunction(2,0x486012);
  local_1c = getCopReg(2,0x19);
  local_18 = getCopReg(2,0x1a);
  local_14 = getCopReg(2,0x1b);
  local_1c = local_1c + puVar3[5];
  local_18 = local_18 + puVar3[6];
  local_14 = local_14 + puVar3[7];
  if (*(short *)(CONCAT31(in_register_00000015,AnItem) + 2) == 1) {
    iVar1 = CONCAT31(in_register_00000015,AnItem) + ((int)((uint)(ushort)index << 0x10) >> 0xd);
    Angle = *(undefined4 *)(iVar1 + 0x14);
    DAT_800b0174 = *(uint *)(iVar1 + 0x18);
  }
  else {
    Angle = 0;
    DAT_800b0174 = DAT_800b0174 & 0xffff0000;
  }
  RotMatrix((short *)&Angle,auStack48);
  SetMulMatrix(puVar3,auStack48);
  setCopControlWord(2,0x2800,local_1c);
  setCopControlWord(2,0x3000,local_18);
  setCopControlWord(2,0x3800,local_14);
  if (puVar2[3] != 0) {
    GtxTmd_RotN(NormTop,Tmd_2D);
  }
  if (puVar2[1] != 0) {
    GtxTmd_RotTransPersN(VerTop,Tmd_2D);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Manim_EventGetPos(struct M_OBJECT *mo /*$s4*/, struct MANIM_7fake *pos /*$s1*/)
 // line 1220, offset 0x800245ec
	/* begin block 1 */
		// Start line: 1221
		// Start offset: 0x800245EC
		// Variables:
	// 		short i; // $a0
	// 		short value; // $s3
	// 		long f; // stack offset -40
	// 		struct MANIM_5fake mr; // stack offset -96
	// 		struct MANIM_99fake *Anim; // $s5
	// 		struct MANIM_7fake *trans; // $s2
	// 		struct MANIM_7fake angle; // stack offset -64
	// 		struct MANIM_6fake dummy; // stack offset -56
	/* end block 1 */
	// End offset: 0x800247B8
	// End Line: 1256

	/* begin block 2 */
		// Start line: 3196
	/* end block 2 */
	// End Line: 3197

void Manim_EventGetPos(M_OBJECT *mo,undefined pos)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 in_zero;
  undefined4 in_at;
  _D3_OBJECT *p_Var4;
  int iVar5;
  int iVar6;
  undefined3 in_register_00000015;
  undefined4 *puVar7;
  uint uVar8;
  int iVar9;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  short local_38;
  short local_34;
  short local_30;
  
  puVar7 = (undefined4 *)CONCAT31(in_register_00000015,pos);
  uVar8 = 1;
  p_Var4 = mo->sit;
  iVar9 = *(int *)(*(int *)((mo->Sq).Data.FatherTrans + 2) + 8);
  memset(&local_40,0,8);
  setCopReg(2,in_zero,local_40);
  setCopReg(2,in_at,local_3c);
  copFunction(2,0x486012);
  local_4c = getCopReg(2,0x19);
  local_48 = getCopReg(2,0x1a);
  local_44 = getCopReg(2,0x1b);
  RotMatrix((short *)&mo->sit->rot,(undefined2 *)&local_60);
  setCopControlWord(2,0x2800,local_4c);
  setCopControlWord(2,0x3000,local_48);
  setCopControlWord(2,0x3800,local_44);
  setCopControlWord(2,0,local_60);
  setCopControlWord(2,0x800,local_5c);
  setCopControlWord(2,0x1000,local_58);
  setCopControlWord(2,0x1800,local_54);
  setCopControlWord(2,0x2000,local_50);
  iVar6 = 0;
  do {
    if ((uVar8 & (uint)(ushort)(mo->Env).Obj.vert_top.pad) != 0) {
      iVar5 = iVar9 + ((int)((((int)((uint)*(ushort *)&(mo->Env).nPivot << 0x10) >> 0x14) *
                              (uint)*(ushort *)(iVar9 + 4) + (int)(short)iVar6) * 0x20000) >> 0xd);
      *(undefined2 *)puVar7 = *(undefined2 *)(iVar5 + 0x14);
      *(undefined2 *)((int)puVar7 + 2) = *(undefined2 *)(iVar5 + 0x16);
      *(undefined2 *)(puVar7 + 1) = *(undefined2 *)(iVar5 + 0x18);
      setCopReg(2,in_zero,*puVar7);
      setCopReg(2,in_at,puVar7[1]);
      copFunction(2,0x480012);
      uVar1 = getCopReg(2,0x19);
      uVar2 = getCopReg(2,0x1a);
      uVar3 = getCopReg(2,0x1b);
      getCopControlWord(2,0xf800);
      local_38 = (short)uVar1;
      *(short *)puVar7 = local_38 + (p_Var4->pos).vx;
      local_34 = (short)uVar2;
      *(short *)((int)puVar7 + 2) = local_34 + (p_Var4->pos).vy;
      local_30 = (short)uVar3;
      *(short *)(puVar7 + 1) = local_30 + (p_Var4->pos).vz;
    }
    iVar6 = iVar6 + 1;
    uVar8 = uVar8 << 1;
  } while (iVar6 * 0x10000 >> 0x10 < 0x10);
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





