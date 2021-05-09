#include "THISDUST.H"
#include "SFX.H"


// decompiled code
// original method signature: 
// void /*$ra*/ SFX_Init()
 // line 110, offset 0x8005dd18
	/* begin block 1 */
		// Start line: 111
		// Start offset: 0x8005DD18
		// Variables:
	// 		long i; // $s1
	/* end block 1 */
	// End offset: 0x8005DDE8
	// End Line: 146

	/* begin block 2 */
		// Start line: 220
	/* end block 2 */
	// End Line: 221

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SFX_Init(void)

{
  TMD_72fake *T;
  void **ppvVar1;
  int iVar2;
  
  Effects_Tmd = File_Read(s_Effects_lnk_800ad6e8,(void *)0x0);
  Effects_Pcl = File_Read(s_Effects_pcl_800ad6f4,(void *)0x0);
  Shp_GroupToVram(Effects_Pcl,1);
  ppvVar1 = &Sfx_TabTmd5;
  iVar2 = 0;
  Sfx_TabTmd5 = FileGroup_GetAddr(Effects_Tmd,4);
  PTR_800b2dec = FileGroup_GetAddr(Effects_Tmd,3);
  PTR_800b2df0 = FileGroup_GetAddr(Effects_Tmd,2);
  PTR_800b2df4 = FileGroup_GetAddr(Effects_Tmd,5);
  PTR_800b2df8 = FileGroup_GetAddr(Effects_Tmd,1);
  do {
    iVar2 = iVar2 + 1;
    Tmd_InitFile((TMD_72fake *)*ppvVar1);
    T = (TMD_72fake *)*ppvVar1;
    ppvVar1 = (TMD_72fake **)ppvVar1 + 1;
    Shp_TmdToVram(Effects_Pcl,T,0,0);
  } while (iVar2 < 5);
  Text_InitFont(0x70,Effects_Pcl,0x100,0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX_Delete()
 // line 150, offset 0x8005de10
	/* begin block 1 */
		// Start line: 331
	/* end block 1 */
	// End Line: 332

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SFX_Delete(void)

{
  Heap_FreeMem(Effects_Tmd);
  Shp_GroupRelease(Effects_Pcl,1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX_ExplodeObject(struct _D3_OBJECT *o /*$s0*/)
 // line 157, offset 0x8005de40
	/* begin block 1 */
		// Start line: 158
		// Start offset: 0x8005DE40
		// Variables:
	// 		struct SFX_7fake center; // stack offset -16
	/* end block 1 */
	// End offset: 0x8005DF54
	// End Line: 211

	/* begin block 2 */
		// Start line: 345
	/* end block 2 */
	// End Line: 346

void SFX_ExplodeObject(_D3_OBJECT *o)

{
  short sVar1;
  long type;
  
  switch(o->comp_opt1) {
  case 0:
    sVar1 = *(short *)((int)&o->comp_opt4 + 2);
    if (sVar1 == 3) {
LAB_8005dec8:
      Boxes_GetCenter(o,0xf0);
      Impact_Stone(0xf0,10);
      return;
    }
    if (sVar1 == 5) {
      type = 7;
    }
    else {
      type = 1;
    }
    break;
  case 1:
    sVar1 = *(short *)((int)&o->comp_opt4 + 2);
    if (sVar1 == 3) goto LAB_8005dec8;
    if (sVar1 == 5) {
      type = 7;
    }
    else {
      type = 0;
    }
    break;
  case 2:
    type = 4;
    break;
  case 3:
    o->comp_opt1 = 1;
    SFX_AddExplosion(o,0,0);
    SFX_ApocalypseInit(o);
    return;
  case 4:
    SFX_AddExplosion(o,5,0);
    SFX_IncendieInit(o);
    return;
  case 5:
    type = 6;
    break;
  default:
    return;
  }
  SFX_AddExplosion(o,type,0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX_Explosion(struct SFX_7fake *pos /*$s1*/, long ExType /*$s3*/, long ExMaterial /*$s4*/)
 // line 214, offset 0x8005df64
	/* begin block 1 */
		// Start line: 215
		// Start offset: 0x8005DF64
		// Variables:
	// 		struct SFX_118fake *t; // $s2
	/* end block 1 */
	// End offset: 0x8005E12C
	// End Line: 260

	/* begin block 2 */
		// Start line: 459
	/* end block 2 */
	// End Line: 460

void SFX_Explosion(undefined pos,long ExType,long ExMaterial)

{
  SFX_118fake *ex;
  undefined3 in_register_00000011;
  long mode;
  undefined4 uVar1;
  _D3_OBJECT *o;
  
  ex = (SFX_118fake *)Task_Add(SFX_ExplosionTask,0x784);
  o = &ex->obj;
  (ex->t).local = (void *)0x0;
  uVar1 = ((undefined4 *)CONCAT31(in_register_00000011,pos))[1];
  *(undefined4 *)&(ex->obj).pos = *(undefined4 *)CONCAT31(in_register_00000011,pos);
  *(undefined4 *)&(ex->obj).pos.vz = uVar1;
  D3_SetBox(o,-0x14,-0x14,-0x14,0x14,0x14,0x14);
  ex->type[5] = 0xfe - (char)ExType;
  (ex->obj).comp_opt1 = (short)ExType;
  (ex->obj).display_mode = 0x11;
  D3_ClearCollBits(o,0xffff);
  D3_SetCollBits(o,0x21);
  if (ExType == 0) {
    *(void **)&ex[2].t.s7 = (&Sfx_TabTmd5)[Sfx_TabExplosion[ExMaterial * 2]];
  }
  else {
    ex[2].t.s7 = 0;
  }
  if (ExType == 2) {
    Fx_Play(*(short *)((int)Sfx_TabExplosion + (ExMaterial << 3 | 4U)),0);
  }
  else {
    Fx_PlayLoud(*(short *)((int)Sfx_TabExplosion + (ExMaterial << 3 | 4U)),(char)ex + -0x44);
  }
  switch(ExType) {
  case 0:
    SFX02_Init(ex,9);
    break;
  case 1:
    SFX01_Init(ex);
    break;
  case 2:
    mode = 1;
    goto LAB_8005e124;
  case 3:
    SFX04_Init(ex,0x14,0xd4,0xc);
    break;
  case 5:
    mode = 0;
LAB_8005e124:
    SFX05_Init(ex,1,mode);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX_AddExplosion(struct _D3_OBJECT *o /*$s2*/, long type /*$s3*/, long pointfixe /*$s0*/)
 // line 263, offset 0x8005e14c
	/* begin block 1 */
		// Start line: 264
		// Start offset: 0x8005E14C
		// Variables:
	// 		struct SFX_118fake *t; // $s1
	// 		long i; // $a1
	/* end block 1 */
	// End offset: 0x8005E424
	// End Line: 333

	/* begin block 2 */
		// Start line: 574
	/* end block 2 */
	// End Line: 575

void SFX_AddExplosion(_D3_OBJECT *o,long type,long pointfixe)

{
  SFX_118fake *ex;
  SFX_118fake *pSVar1;
  _D3_OBJECT *p_Var2;
  int iVar3;
  long circle;
  undefined4 uVar4;
  
  ex = (SFX_118fake *)Task_Add(SFX_ExplosionTask,0x784);
  if (pointfixe == 0) {
    Boxes_GetCenter(o,(char)ex + -0x44);
    *(_D3_OBJECT **)&(ex->t).local = o;
  }
  else {
    uVar4 = *(undefined4 *)&(o->pos).vz;
    *(undefined4 *)&(ex->obj).pos = *(undefined4 *)&o->pos;
    *(undefined4 *)&(ex->obj).pos.vz = uVar4;
    *(_D3_OBJECT **)&(ex->t).local = o;
  }
  iVar3 = 0;
  pSVar1 = ex;
  p_Var2 = o;
  if ((o->collision_state & 2U) != 0) {
    (ex->t).local = o[1].description;
    pSVar1 = ex;
    p_Var2 = o;
  }
  do {
    uVar4 = *(undefined4 *)&(p_Var2->b_box).vz;
    *(undefined4 *)&(pSVar1->obj).b_box = *(undefined4 *)&p_Var2->b_box;
    *(undefined4 *)&(pSVar1->obj).b_box.vz = uVar4;
    iVar3 = iVar3 + 1;
    pSVar1 = (SFX_118fake *)&(pSVar1->t).father;
    p_Var2 = (_D3_OBJECT *)&p_Var2->child;
  } while (iVar3 < 8);
  (ex->obj).b_box.pad = (o->b_box).pad;
  (ex->obj).matrices = o->matrices;
  ex->type[5] = 0xfe - *(char *)&o->comp_opt1;
  (ex->obj).comp_opt1 = o->comp_opt1;
  (ex->obj).display_mode = o->display_mode | 0x11;
  D3_ClearCollBits(&ex->obj,0xffff);
  D3_SetCollBits(&ex->obj,0x21);
  if (o->comp_opt1 == 0) {
    *(void **)&ex[2].t.s7 =
         (&Sfx_TabTmd5)[Sfx_TabExplosion[(int)*(short *)((int)&o->comp_opt4 + 2) * 2]];
  }
  else {
    if (o->comp_opt1 == 5) {
      *(void **)&ex[2].t.s7 = o->description;
    }
    else {
      ex[2].t.s7 = 0;
    }
  }
  if (((*(char *)((int)&o[1].pos.vx + 1) == '\0') && (-1 < *(short *)((int)&o[1].father + 2))) &&
     ((o->collision_mode & 0x40U) == 0)) {
    D3_PlaySound(o,0);
  }
  else {
    if (o->comp_opt1 != 4) {
      if (type == 4) {
        Fx_Play(*(short *)((int)Sfx_TabExplosion +
                          ((int)*(short *)((int)&o->comp_opt4 + 2) << 3 | 4U)),0);
      }
      else {
        Fx_PlayLoud(*(short *)((int)Sfx_TabExplosion +
                              ((int)*(short *)((int)&o->comp_opt4 + 2) << 3 | 4U)),(char)ex + -0x44)
        ;
      }
    }
  }
  switch(type) {
  case 0:
    SFX01_Init(ex);
    break;
  case 1:
    circle = 9;
    goto LAB_8005e41c;
  case 3:
    SFX04_Init(ex,0x14,0xd4,0xc);
    break;
  case 4:
    circle = 1;
    goto LAB_8005e3ec;
  case 5:
    circle = 0;
LAB_8005e3ec:
    SFX05_Init(ex,circle,circle);
    break;
  case 6:
    SFX05_Init(ex,1,0);
    break;
  case 7:
    circle = 1;
LAB_8005e41c:
    SFX02_Init(ex,circle);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX_ExplosionTask()
 // line 336, offset 0x8005e440
	/* begin block 1 */
		// Start line: 337
		// Start offset: 0x8005E440
		// Variables:
	// 		struct SFX_118fake *exp; // $s0
	/* end block 1 */
	// End offset: 0x8005E488
	// End Line: 345

	/* begin block 2 */
		// Start line: 735
	/* end block 2 */
	// End Line: 736

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SFX_ExplosionTask(void)

{
  TASK *pTVar1;
  code *pcVar2;
  void *pvVar3;
  
  pTVar1 = TaskCurrent;
  pvVar3 = TaskCurrent[6].sp;
  TaskCurrent->display = TaskCurrent[6].display;
  if (pvVar3 != (void *)0x0) {
    pcVar2 = (code *)pTVar1[6].sp;
    do {
      (*pcVar2)();
      pcVar2 = (code *)pTVar1[6].sp;
    } while (pcVar2 != (code *)0x0);
  }
  TaskCurrent->display = (_func_11 *)0x0;
  Task_Sleep(2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX_ApocalypseInit(struct _D3_OBJECT *o /*$s0*/)
 // line 356, offset 0x8005e4ac
	/* begin block 1 */
		// Start line: 357
		// Start offset: 0x8005E4AC
	/* end block 1 */
	// End offset: 0x8005E4AC
	// End Line: 357

	/* begin block 2 */
		// Start line: 776
	/* end block 2 */
	// End Line: 777

void SFX_ApocalypseInit(_D3_OBJECT *o)

{
  TASK *pTVar1;
  
  pTVar1 = Task_Add(SFX_ApocalypseTask,0xb84);
  Boxes_GetCenter(o,(char)pTVar1 + -0x44);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX_ApocalypseTask()
 // line 367, offset 0x8005e4e8
	/* begin block 1 */
		// Start line: 368
		// Start offset: 0x8005E4E8
		// Variables:
	// 		struct SFX_118fake *ex; // $a2
	// 		long i; // $s0
	// 		long size; // $s1
	// 		long grey; // stack offset -24
	// 		struct _D3_OBJECT obj; // stack offset -200
	// 		struct SFX_8fake colwave; // stack offset -32
	/* end block 1 */
	// End offset: 0x8005E5CC
	// End Line: 398

	/* begin block 2 */
		// Start line: 801
	/* end block 2 */
	// End Line: 802

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SFX_ApocalypseTask(void)

{
  TASK *pTVar1;
  int iVar2;
  int dist;
  undefined auStack200 [34];
  uchar local_a6;
  long local_9c;
  long local_98;
  undefined local_2f;
  undefined4 local_20;
  int local_18 [2];
  
  pTVar1 = TaskCurrent;
  dist = 1;
  iVar2 = 0x28;
  local_18[0] = 0xfa;
  local_20 = DAT_800ad700;
  *(int **)&TaskCurrent->local = local_18;
  local_9c = pTVar1[1].s0;
  local_98 = pTVar1[1].s1;
  local_2f = 0xfb;
  local_a6 = '\n';
  D3_ClearCollBits((_D3_OBJECT *)auStack200,0xffff);
  D3_SetCollBits((_D3_OBJECT *)auStack200,3);
  SFX_ShockWave(1,100,0xe0,1);
  SFX_ShakeScreen(0x78,0x1e);
  do {
    Boxes_TestDistance((_D3_OBJECT *)auStack200,dist);
    dist = dist + 0x1e;
    iVar2 = iVar2 + -1;
    local_18[0] = local_18[0] + -10;
    Task_Next();
  } while (iVar2 != 0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX_BounceSpeed(struct _D3_OBJECT *o /*$a0*/, struct SFX_7fake *spd /*$a1*/, long frottement /*$a2*/)
 // line 401, offset 0x8005e5e0
	/* begin block 1 */
		// Start line: 935
	/* end block 1 */
	// End Line: 936

void SFX_BounceSpeed(_D3_OBJECT *o,undefined spd,long frottement)

{
  undefined3 in_register_00000015;
  short *psVar1;
  
  psVar1 = (short *)CONCAT31(in_register_00000015,spd);
  if ((o->collision_state & 0xc00U) != 0) {
    if (frottement == 0) {
      trap(0x1c00);
    }
    if ((frottement == -1) && ((int)*psVar1 == -0x80000000)) {
      trap(0x1800);
    }
    *psVar1 = (short)((int)*psVar1 / frottement) - *psVar1;
  }
  if ((o->collision_state & 0x3000U) != 0) {
    if (frottement == 0) {
      trap(0x1c00);
    }
    if ((frottement == -1) && ((int)psVar1[1] == -0x80000000)) {
      trap(0x1800);
    }
    psVar1[1] = (short)((int)psVar1[1] / frottement) - psVar1[1];
  }
  if (((int)o->collision_state & 0xc000U) != 0) {
    if (frottement == 0) {
      trap(0x1c00);
    }
    if ((frottement == -1) && ((int)psVar1[2] == -0x80000000)) {
      trap(0x1800);
    }
    psVar1[2] = (short)((int)psVar1[2] / frottement) - psVar1[2];
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SFX_TestSpeed(struct SFX_118fake *ex /*$a0*/, struct SFX_7fake *pos /*$a1*/, struct SFX_7fake *spd /*$a2*/)
 // line 414, offset 0x8005e6f0
	/* begin block 1 */
		// Start line: 960
	/* end block 1 */
	// End Line: 961

long SFX_TestSpeed(SFX_118fake *ex,undefined1 pos,undefined1 spd)

{
  bool bVar1;
  
  bVar1 = 0 < *(short *)(ex->type + 0x26);
  if (!bVar1) {
    SFX_TestVectorSpeed(pos,spd);
  }
  return (uint)bVar1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SFX_TestVectorSpeed(struct SFX_7fake *pos /*$a0*/, struct SFX_7fake *spd /*$a1*/)
 // line 424, offset 0x8005e728
	/* begin block 1 */
		// Start line: 982
	/* end block 1 */
	// End Line: 983

/* WARNING: Unknown calling convention yet parameter storage is locked */

long SFX_TestVectorSpeed(undefined pos,undefined spd)

{
  long lVar1;
  undefined3 in_register_00000011;
  undefined3 in_register_00000015;
  short *psVar2;
  
  psVar2 = (short *)CONCAT31(in_register_00000015,spd);
  if (*(short *)(CONCAT31(in_register_00000011,pos) + 4) < -0x5dc) {
    *(undefined2 *)(CONCAT31(in_register_00000011,pos) + 4) = 0xfa24;
    *psVar2 = 0;
    psVar2[1] = 0;
    psVar2[2] = 0;
  }
  lVar1 = 1;
  if ((ushort)(*psVar2 + 4U) < 9) {
    lVar1 = 1;
    if ((-5 < psVar2[1]) && (lVar1 = 1, psVar2[1] < 5)) {
      lVar1 = 1;
      if ((-10 < psVar2[2]) && (lVar1 = 0, 9 < psVar2[2])) {
        lVar1 = 1;
      }
    }
  }
  return lVar1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SFX_IsPieceClipped(struct SFX_7fake *pos /*$a0*/)
 // line 443, offset 0x8005e7b4
	/* begin block 1 */
		// Start line: 444
		// Start offset: 0x8005E7B4
		// Variables:
	// 		struct SFX_9fake p2D; // stack offset -16
	// 		long z; // stack offset -8
	/* end block 1 */
	// End offset: 0x8005E870
	// End Line: 460

	/* begin block 2 */
		// Start line: 1018
	/* end block 2 */
	// End Line: 1019

/* WARNING: Unknown calling convention yet parameter storage is locked */

long SFX_IsPieceClipped(undefined pos)

{
  undefined4 uVar1;
  undefined4 in_zero;
  undefined4 in_at;
  long lVar2;
  undefined3 in_register_00000011;
  int iVar3;
  short local_10;
  short sStack14;
  
  setCopReg(2,in_zero,*(undefined4 *)CONCAT31(in_register_00000011,pos));
  setCopReg(2,in_at,((undefined4 *)CONCAT31(in_register_00000011,pos))[1]);
  copFunction(2,0x180001);
  uVar1 = getCopReg(2,0xe);
  iVar3 = getCopReg(2,0x9800);
  local_10 = (short)uVar1;
  lVar2 = 1;
  if ((-0x15 < (int)local_10) && (lVar2 = 1, (int)local_10 <= (int)Scr_W + 0x14)) {
    sStack14 = (short)((uint)uVar1 >> 0x10);
    lVar2 = 1;
    if ((-0x15 < (int)sStack14) && (lVar2 = 1, (int)sStack14 <= (int)Scr_H + 0x14)) {
      lVar2 = 1;
      if ((0x13 < iVar3 >> 2) && (lVar2 = 0, 2000 < iVar3 >> 2)) {
        lVar2 = 1;
      }
    }
  }
  return lVar2;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SFX_GetPieceSpeed(struct SFX_118fake *ex /*$s3*/, struct SFX_7fake *pos /*$s2*/, long piece /*$s4*/)
 // line 463, offset 0x8005e878
	/* begin block 1 */
		// Start line: 464
		// Start offset: 0x8005E878
		// Variables:
	// 		struct SFX_7fake *last_pos; // $s0
	// 		struct SFX_7fake *spd; // $s1
	// 		struct _D3_OBJECT obj; // stack offset -200
	// 		struct _PLATFORM *plat; // $s0
	// 		long result; // $s5
	/* end block 1 */
	// End offset: 0x8005EBE4
	// End Line: 586

	/* begin block 2 */
		// Start line: 1058
	/* end block 2 */
	// End Line: 1059

/* WARNING: Could not reconcile some variable overlaps */

long SFX_GetPieceSpeed(SFX_118fake *ex,undefined pos,long piece)

{
  short sVar1;
  long lVar2;
  long lVar3;
  _PLATFORM *p_Var4;
  _PLATFORM *p_Var5;
  int iVar6;
  int iVar7;
  undefined3 in_register_00000015;
  undefined4 *puVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  short *psVar11;
  undefined auStack200 [30];
  ushort local_aa;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  
  puVar8 = (undefined4 *)CONCAT31(in_register_00000015,pos);
  psVar11 = (short *)(ex->type + (piece & 0xffffU) * 8 + 0x34);
  puVar10 = (undefined4 *)(&ex[1].obj.hit_points + (piece & 0xffffU) * 4);
  lVar2 = SFX_TestSpeed(ex,pos,(char)psVar11);
  uVar9 = puVar8[1];
  *puVar10 = *puVar8;
  puVar10[1] = uVar9;
  *(short *)puVar8 = *(short *)puVar8 + *psVar11;
  *(short *)((int)puVar8 + 2) = *(short *)((int)puVar8 + 2) + psVar11[1];
  *(short *)(puVar8 + 1) = *(short *)(puVar8 + 1) + psVar11[2];
  local_94 = *puVar10;
  local_90 = puVar10[1];
  local_9c = *puVar8;
  local_98 = puVar8[1];
  lVar3 = SFX_IsPieceClipped(100);
  if (lVar3 != 0) {
    psVar11[2] = 0;
    psVar11[1] = 0;
    *psVar11 = 0;
    *(short *)(puVar8 + 1) = -0x5dc;
    return 0;
  }
  p_Var4 = Plat_GetPlat(pos);
  if (lVar2 != 0) {
    if (piece >> 0x10 == 0) {
      psVar11[2] = psVar11[2] + -6;
      sVar1 = *psVar11 + -1;
      if (*psVar11 < 0) {
        sVar1 = *psVar11 + 1;
      }
      *psVar11 = sVar1;
      sVar1 = psVar11[1] + -1;
      if (psVar11[1] < 0) {
        sVar1 = psVar11[1] + 1;
      }
      psVar11[1] = sVar1;
    }
    else {
      psVar11[2] = psVar11[2] + -3;
    }
    local_aa = local_aa & 0xfbff;
    if (p_Var4 == (_PLATFORM *)0x0) {
      return lVar2;
    }
    iVar7 = (int)*(short *)&p_Var4[1].obj.prec;
    if ((int)(short)local_98 <= iVar7) {
      p_Var5 = Plat_GetPlat(0x6c);
      if (p_Var5 == p_Var4) {
        local_aa = local_aa | 0x4000;
      }
      else {
        iVar7 = (int)*psVar11;
        iVar6 = (int)psVar11[1];
        if (iVar7 < 0) {
          iVar7 = -iVar7;
        }
        if (iVar6 < 0) {
          iVar6 = -iVar6;
        }
        if (iVar6 < iVar7) {
          local_aa = local_aa | 0x400;
        }
        else {
          local_aa = local_aa | 0x1000;
        }
      }
      local_9c = local_94;
      local_98 = local_90;
      SFX_BounceSpeed((_D3_OBJECT *)auStack200,(char)psVar11,2);
      return lVar2;
    }
    if (*(char *)((int)&p_Var4[1].obj.pos.vx + 1) == '\0') {
      return lVar2;
    }
    if (iVar7 + (int)p_Var4[1].obj.pos.vy <= (int)(short)local_98) {
      return lVar2;
    }
    psVar11[2] = -1;
    if (*(short *)((int)puVar8 + 6) < 0) {
      return lVar2;
    }
    *(short *)((int)puVar8 + 6) = -1;
    if (*(char *)((int)&p_Var4[1].obj.pos.vx + 1) != '\x03') {
      return lVar2;
    }
    Impact_Acid(100);
    return lVar2;
  }
  if (p_Var4 != (_PLATFORM *)0x0) {
    if ((int)*(short *)&p_Var4[1].obj.prec + 0xd < (int)*(short *)(puVar8 + 1)) {
      if (piece >> 0x10 != 0) {
        psVar11[2] = psVar11[2] + -3;
        return 1;
      }
      psVar11[2] = psVar11[2] + -6;
      sVar1 = *psVar11 + -1;
      if (*psVar11 < 0) {
        sVar1 = *psVar11 + 1;
      }
      *psVar11 = sVar1;
      sVar1 = psVar11[1] + -1;
      if (psVar11[1] < 0) {
        sVar1 = psVar11[1] + 1;
      }
      psVar11[1] = sVar1;
      return 1;
    }
    *(undefined2 *)(ex->type + 0x26) = 0;
    if (((p_Var4->obj).collision_mode & 0x800U) == 0) {
      psVar11[2] = 0;
      psVar11[1] = 0;
      *psVar11 = 0;
      sVar1 = *(short *)&p_Var4[1].obj.prec + 5;
      goto LAB_8005ebdc;
    }
  }
  sVar1 = -0x5dc;
  psVar11[2] = 0;
  psVar11[1] = 0;
  *psVar11 = 0;
LAB_8005ebdc:
  *(short *)(puVar8 + 1) = sVar1;
  return 0;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SFX_IsPiecePresent()
 // line 589, offset 0x8005ec08
	/* begin block 1 */
		// Start line: 591
		// Start offset: 0x8005EC08
		// Variables:
	// 		struct SFX_118fake *ex; // $v0
	// 		struct SFX_7fake *pos; // $a0
	// 		long i; // $v1
	/* end block 1 */
	// End offset: 0x8005EC48
	// End Line: 602

	/* begin block 2 */
		// Start line: 1328
	/* end block 2 */
	// End Line: 1329

/* WARNING: Unknown calling convention yet parameter storage is locked */

long SFX_IsPiecePresent(void)

{
  int iVar1;
  _func_11 **pp_Var2;
  
  iVar1 = 0;
  pp_Var2 = &TaskCurrent[3].display;
  if (0 < (int)*(short *)&TaskCurrent[2].destructor) {
    do {
      iVar1 = iVar1 + 1;
      if (0 < *(short *)(pp_Var2 + 1)) {
        return 1;
      }
      pp_Var2 = pp_Var2 + 2;
    } while (iVar1 < (int)*(short *)&TaskCurrent[2].destructor);
  }
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX01_Init(struct SFX_118fake *ex /*$s2*/)
 // line 609, offset 0x8005ec50
	/* begin block 1 */
		// Start line: 610
		// Start offset: 0x8005EC50
		// Variables:
	// 		long i; // $s1
	// 		long j; // $a0
	// 		struct SFX_8fake *col; // $v0

		/* begin block 1.1 */
			// Start line: 637
			// Start offset: 0x8005ED9C
			// Variables:
		// 		struct SFX_7fake *spd; // $s0
		/* end block 1.1 */
		// End offset: 0x8005ED9C
		// End Line: 637
	/* end block 1 */
	// End offset: 0x8005EE90
	// End Line: 648

	/* begin block 2 */
		// Start line: 1370
	/* end block 2 */
	// End Line: 1371

void SFX01_Init(SFX_118fake *ex)

{
  short sVar1;
  void *pvVar2;
  undefined *puVar3;
  long lVar4;
  int iVar5;
  int iVar6;
  ushort uVar7;
  short *psVar8;
  int iVar9;
  SFX_118fake *pSVar10;
  
  *(undefined2 *)(ex->type + 0x22) = 0xb;
  *(undefined2 *)(ex->type + 0x20) = 5;
  pvVar2 = Effects_Pcl;
  *(undefined2 *)(ex->type + 0x24) = 0;
  *(undefined4 *)(ex->type + 0x18) = 0;
  *(void **)(ex->type + 0x10) = pvVar2;
  pvVar2 = Heap_AllocMem((int)*(short *)(ex->type + 0x20) * (int)*(short *)(ex->type + 0x22) * 8);
  *(void **)(ex->type + 0x14) = pvVar2;
  pvVar2 = Heap_AllocMem((int)*(short *)(ex->type + 0x20) * (int)*(short *)(ex->type + 0x22) * 4);
  iVar9 = 0;
  *(void **)(ex->type + 0x18) = pvVar2;
  if (0 < *(short *)(ex->type + 0x22)) {
    uVar7 = 0x19;
    do {
      sVar1 = *(short *)(ex->type + 0x20);
      iVar6 = 0;
      if (0 < *(short *)(ex->type + 0x20)) {
        do {
          *(ushort *)((iVar6 + iVar9 * (int)sVar1) * 8 + *(int *)(ex->type + 0x14) + 6) =
               uVar7 | 0x9b00;
          iVar5 = iVar6 + iVar9 * (int)*(short *)(ex->type + 0x20);
          iVar6 = iVar6 + 1;
          puVar3 = (undefined *)(*(int *)(ex->type + 0x18) + iVar5 * 4);
          *puVar3 = 0x80;
          puVar3[1] = 0x80;
          puVar3[2] = 0x80;
          sVar1 = *(short *)(ex->type + 0x20);
        } while (iVar6 < (int)*(short *)(ex->type + 0x20));
      }
      iVar9 = iVar9 + 1;
      uVar7 = uVar7 - 2;
    } while (iVar9 < (int)*(short *)(ex->type + 0x22));
  }
  iVar9 = 0;
  if (0 < *(short *)(ex->type + 0x20)) {
    iVar6 = 0x158;
    pSVar10 = ex;
    do {
      psVar8 = (short *)((int)&(ex->t).prec + iVar6);
      lVar4 = M_rand();
      *psVar8 = (short)lVar4 + (short)(lVar4 / 0x5a) * -0x5a + -0x2d;
      lVar4 = M_rand();
      psVar8[1] = (short)lVar4 + (short)(lVar4 / 0x5a) * -0x5a + -0x2d;
      lVar4 = M_rand();
      iVar6 = iVar6 + 8;
      iVar9 = iVar9 + 1;
      psVar8[2] = (short)lVar4 + (short)(lVar4 / 0x2d) * -0x2d;
      lVar4 = *(long *)&(ex->obj).pos.vz;
      pSVar10[1].t.s3 = *(long *)&(ex->obj).pos;
      pSVar10[1].t.s4 = lVar4;
      *(undefined2 *)((int)&pSVar10[1].t.s4 + 2) = 0x19;
      pSVar10 = (SFX_118fake *)&(pSVar10->t).father;
    } while (iVar9 < (int)*(short *)(ex->type + 0x20));
  }
  Light_Add((_LIGHT *)(ex[1].type + 4));
  (ex->t).destructor = SFX01_Destructor;
  ex[2].t.fp = -0x7ffa10e0;
  *(code **)&ex[2].t.text_context = SFX01_DispExplosion;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX01_Destructor(struct TASK *t /*$s0*/)
 // line 659, offset 0x8005eee0
	/* begin block 1 */
		// Start line: 660
		// Start offset: 0x8005EEE0
	/* end block 1 */
	// End offset: 0x8005EEE0
	// End Line: 660

	/* begin block 2 */
		// Start line: 1505
	/* end block 2 */
	// End Line: 1506

void SFX01_Destructor(TASK *t)

{
  Heap_FreeMem(t[2].exec);
  Heap_FreeMem(t[2].sp);
  Light_Delete((_LIGHT *)&t[4].event_s5);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX01_MoveExplosion()
 // line 670, offset 0x8005ef20
	/* begin block 1 */
		// Start line: 671
		// Start offset: 0x8005EF20
		// Variables:
	// 		struct SFX_118fake *ex; // $s2
	// 		struct _D3_OBJECT obj; // stack offset -208
	// 		long r; // $s4

		/* begin block 1.1 */
			// Start line: 691
			// Start offset: 0x8005EFCC
			// Variables:
		// 		int i; // $s3

			/* begin block 1.1.1 */
				// Start line: 695
				// Start offset: 0x8005EFDC
				// Variables:
			// 		struct SFX_7fake *pos; // $s0
			// 		struct SFX_7fake *spd; // $s1
			// 		struct SFX_7fake wind; // stack offset -40
			// 		int j; // $a2
			// 		int index; // $v1
			/* end block 1.1.1 */
			// End offset: 0x8005F1F8
			// End Line: 739
		/* end block 1.1 */
		// End offset: 0x8005F20C
		// End Line: 741
	/* end block 1 */
	// End offset: 0x8005F234
	// End Line: 745

	/* begin block 2 */
		// Start line: 1527
	/* end block 2 */
	// End Line: 1528

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SFX01_MoveExplosion(void)

{
  TASK *pTVar1;
  short sVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  TASK *pTVar6;
  _func_11 **pp_Var7;
  long *plVar8;
  int iVar9;
  int iVar10;
  undefined auStack208 [28];
  short local_b4;
  _func_11 *local_a4;
  _func_11 *local_a0;
  _func_11 *local_9c;
  _func_11 *local_98;
  undefined local_37;
  short local_28;
  short local_26;
  short local_24;
  
  pTVar1 = TaskCurrent;
  local_37 = *(undefined *)((int)&TaskCurrent[2].father + 1);
  local_b4 = *(short *)&TaskCurrent[1].sp;
  D3_SetCollBits((_D3_OBJECT *)auStack208,0x21);
  *(undefined2 *)&pTVar1[4].event_s7 = 0x1400;
  *(undefined2 *)&pTVar1[5].next = 0x1000;
  *(undefined2 *)((int)&pTVar1[4].event_s7 + 2) = 0x1000;
  *(undefined2 *)&pTVar1[4].event_fp = 0x500;
  pTVar6 = (TASK *)pTVar1[1].s1;
  pTVar1[5].father = (TASK *)pTVar1[1].s0;
  pTVar1[5].child = pTVar6;
  SFX_D3ShakeScreen((_D3_OBJECT *)(pTVar1 + 1),(_D3_OBJECT *)&Player,0x78,0x14);
  iVar10 = 0;
  if (0 < *(short *)((int)&pTVar1[2].destructor + 2)) {
    do {
      iVar9 = 0;
      if (0 < *(short *)&pTVar1[2].destructor) {
        do {
          pp_Var7 = &pTVar1[3].display + iVar9 * 2;
          plVar8 = &pTVar1[2].s3 + iVar9 * 2;
          memset(&local_28,0,8);
          Wind_GetValue((char)pp_Var7,(char)&local_28);
          iVar4 = (iVar9 + iVar10 * (int)*(short *)&pTVar1[2].destructor) * 8;
          *(short *)(pTVar1[2].exec + iVar4) = *(short *)pp_Var7;
          *(short *)(pTVar1[2].exec + iVar4 + 2) = *(short *)((int)pp_Var7 + 2);
          *(short *)(pTVar1[2].exec + iVar4 + 4) = *(short *)(pp_Var7 + 1);
          local_9c = *pp_Var7;
          local_98 = pp_Var7[1];
          *(short *)pp_Var7 = *(short *)pp_Var7 + *(short *)plVar8;
          *(short *)((int)pp_Var7 + 2) = *(short *)((int)pp_Var7 + 2) + *(short *)((int)plVar8 + 2);
          *(short *)(pp_Var7 + 1) = *(short *)(pp_Var7 + 1) + *(short *)(plVar8 + 1);
          local_a4 = *pp_Var7;
          local_a0 = pp_Var7[1];
          iVar4 = 0;
          if (0 < *(short *)((int)&pTVar1[2].destructor + 2)) {
            do {
              iVar5 = (iVar9 + iVar4 * (int)*(short *)&pTVar1[2].destructor) * 8;
              *(short *)(pTVar1[2].exec + iVar5) = *(short *)(pTVar1[2].exec + iVar5) + local_28;
              *(short *)(pTVar1[2].exec + iVar5 + 2) =
                   *(short *)(pTVar1[2].exec + iVar5 + 2) + local_26;
              *(short *)(pTVar1[2].exec + iVar5 + 4) = *(short *)(pTVar1[2].exec + iVar5 + 4) + 1;
              iVar4 = iVar4 + 1;
            } while (iVar4 < (int)*(short *)((int)&pTVar1[2].destructor + 2));
          }
          sVar2 = *(short *)plVar8 + -1;
          if (*(short *)plVar8 < 0) {
            sVar2 = *(short *)plVar8 + 1;
          }
          *(short *)plVar8 = sVar2;
          if (*(short *)((int)plVar8 + 2) < 0) {
            sVar2 = *(short *)((int)plVar8 + 2) + 1;
          }
          else {
            sVar2 = *(short *)((int)plVar8 + 2) + -1;
          }
          *(short *)((int)plVar8 + 2) = sVar2;
          *(short *)(plVar8 + 1) = *(short *)(plVar8 + 1) + -3;
          *(short *)plVar8 = *(short *)plVar8 + local_28;
          *(short *)((int)plVar8 + 2) = *(short *)((int)plVar8 + 2) + local_26;
          *(short *)(plVar8 + 1) = *(short *)(plVar8 + 1) + local_24;
          lVar3 = Boxes_TestObject((_D3_OBJECT *)auStack208);
          if (lVar3 != 0) {
            SFX_BounceSpeed((_D3_OBJECT *)auStack208,(char)plVar8,3);
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 < (int)*(short *)&pTVar1[2].destructor);
      }
      *(short *)&pTVar1[2].local = *(short *)&pTVar1[2].local + 1;
      Task_Next();
      iVar10 = iVar10 + 1;
    } while (iVar10 < (int)*(short *)((int)&pTVar1[2].destructor + 2));
  }
  *(undefined2 *)&pTVar1[5].next = 1;
  *(undefined2 *)&pTVar1[4].event_s7 = 0x800;
  *(undefined2 *)((int)&pTVar1[4].event_s7 + 2) = 0x800;
  *(undefined2 *)&pTVar1[4].event_fp = 0x800;
  pTVar6 = TaskCurrent;
  *(undefined2 *)&pTVar1[2].local = 0;
  pTVar6->display = SFX01_DispSmoke;
  *(code **)&pTVar1[6].sp = SFX01_MoveSmoke;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX01_MoveSmoke()
 // line 758, offset 0x8005f294
	/* begin block 1 */
		// Start line: 759
		// Start offset: 0x8005F294
		// Variables:
	// 		struct SFX_118fake *ex; // $s0
	// 		long r; // $s2

		/* begin block 1.1 */
			// Start line: 763
			// Start offset: 0x8005F2B4
			// Variables:
		// 		long i; // $s1

			/* begin block 1.1.1 */
				// Start line: 767
				// Start offset: 0x8005F2C4
				// Variables:
			// 		int j; // $a3
			// 		struct SFX_7fake wind; // stack offset -24

				/* begin block 1.1.1.1 */
					// Start line: 777
					// Start offset: 0x8005F2E8
					// Variables:
				// 		long index; // $a2
				/* end block 1.1.1.1 */
				// End offset: 0x8005F3E8
				// End Line: 796
			/* end block 1.1.1 */
			// End offset: 0x8005F400
			// End Line: 797
		/* end block 1.1 */
		// End offset: 0x8005F414
		// End Line: 799
	/* end block 1 */
	// End offset: 0x8005F434
	// End Line: 803

	/* begin block 2 */
		// Start line: 1829
	/* end block 2 */
	// End Line: 1830

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SFX01_MoveSmoke(void)

{
  short sVar1;
  TASK *pTVar2;
  char *pcVar3;
  void *pvVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  short local_18;
  short local_16;
  
  pTVar2 = TaskCurrent;
  iVar9 = 0;
  do {
    iVar8 = 0;
    if (0 < *(short *)((int)&pTVar2[2].destructor + 2)) {
      iVar5 = 0;
      do {
        Wind_GetValue((char)pTVar2 + (char)iVar5 + -0x30,0xe8);
        sVar1 = *(short *)&pTVar2[2].destructor;
        iVar5 = 0;
        if (0 < *(short *)&pTVar2[2].destructor) {
          do {
            iVar7 = iVar5 + iVar8 * (int)sVar1;
            iVar6 = iVar7 * 8;
            *(short *)(pTVar2[2].exec + iVar6) = *(short *)(pTVar2[2].exec + iVar6) + local_18;
            *(short *)(pTVar2[2].exec + iVar6 + 2) =
                 *(short *)(pTVar2[2].exec + iVar6 + 2) + local_16;
            *(short *)(pTVar2[2].exec + iVar6 + 4) = *(short *)(pTVar2[2].exec + iVar6 + 4) + 1;
            if ((iVar5 < 1) || (iVar6 = iVar7 * 4, iVar8 != 0)) {
              iVar7 = iVar7 * 4;
              pcVar3 = (char *)(iVar7 + (int)pTVar2[2].sp);
              *pcVar3 = *pcVar3 + -3;
              pvVar4 = (void *)(iVar7 + (int)pTVar2[2].sp);
              *(char *)((int)pvVar4 + 1) = *(char *)((int)pvVar4 + 1) + -3;
              pvVar4 = (void *)(iVar7 + (int)pTVar2[2].sp);
              *(char *)((int)pvVar4 + 2) = *(char *)((int)pvVar4 + 2) + -3;
            }
            else {
              *(undefined *)(iVar6 + (int)pTVar2[2].sp) = 0;
              *(undefined *)((int)pTVar2[2].sp + iVar6 + 1) = 0;
              *(undefined *)((int)pTVar2[2].sp + iVar6 + 2) = 0;
            }
            iVar5 = iVar5 + 1;
            sVar1 = *(short *)&pTVar2[2].destructor;
          } while (iVar5 < (int)*(short *)&pTVar2[2].destructor);
        }
        iVar8 = iVar8 + 1;
        iVar5 = iVar8 * 8;
      } while (iVar8 < (int)*(short *)((int)&pTVar2[2].destructor + 2));
    }
    iVar9 = iVar9 + 1;
    *(short *)&pTVar2[2].local = *(short *)&pTVar2[2].local + 1;
    Task_Next();
  } while (iVar9 < 0x2a);
  pTVar2[6].sp = (void *)0x0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX01_DispExplosion()
 // line 808, offset 0x8005f450
	/* begin block 1 */
		// Start line: 809
		// Start offset: 0x8005F450
		// Variables:
	// 		struct SFX_118fake *ex; // $s0
	// 		struct SFX_31fake *p; // $s1
	// 		struct SFX_70fake shp; // stack offset -40
	// 		long z; // stack offset -24
	// 		long borne; // $v0

		/* begin block 1.1 */
			// Start line: 824
			// Start offset: 0x8005F4F4
		/* end block 1.1 */
		// End offset: 0x8005F5E8
		// End Line: 836
	/* end block 1 */
	// End offset: 0x8005F608
	// End Line: 838

	/* begin block 2 */
		// Start line: 2042
	/* end block 2 */
	// End Line: 2043

/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void SFX01_DispExplosion(void)

{
  short sVar1;
  undefined4 uVar2;
  void *pvVar3;
  TASK *pTVar4;
  _SCREEN *p_Var5;
  undefined4 in_zero;
  undefined4 in_at;
  int iVar6;
  SHAPE_31fake *prim;
  uint uVar7;
  void *local_28;
  short local_24;
  undefined4 local_20;
  int local_18;
  
  pTVar4 = TaskCurrent;
  local_28 = Effects_Pcl;
  local_24 = *(short *)&TaskCurrent[2].local + 0x2d;
  prim = (SHAPE_31fake *)(&TaskCurrent[5].bprec + (int)Scr_Frame * 10);
  setCopReg(2,in_zero,TaskCurrent[1].s0);
  setCopReg(2,in_at,TaskCurrent[1].s1);
  copFunction(2,0x180001);
  local_20 = getCopReg(2,0xe);
  local_18 = getCopReg(2,0x9800);
  local_18 = local_18 >> 2;
  if ((0 < local_18) && (local_18 < (int)Scr_OtSize)) {
    uVar7 = ((int)Scr_GeomScreen * 0x3c) / local_18;
    if (local_18 == 0) {
      trap(0x1c00);
    }
    if ((local_18 == -1) && ((int)Scr_GeomScreen * 0x3c == -0x80000000)) {
      trap(0x1800);
    }
    if (2 < (int)uVar7) {
      local_20._2_2_ = (short)((uint)local_20 >> 0x10);
      sVar1 = (short)((int)(uVar7 + (uVar7 >> 0x1f)) >> 1);
      local_20 = CONCAT22(local_20._2_2_ - sVar1,(short)local_20 - sVar1);
      Shp_SetPolyFT4(prim,(SHAPE_68fake *)&local_28,(short)uVar7,(short)uVar7);
      SetSemiTrans((int)prim,1);
      p_Var5 = Scr;
      prim->tag = prim->tag & 0xff000000 | Scr->ot[local_18] & 0xffffff;
      p_Var5->ot[local_18] = p_Var5->ot[local_18] & 0xff000000 | (uint)prim & 0xffffff;
    }
  }
  pvVar3 = Main_Prims;
  uVar2 = Main_TextContext.Font.ascii_tab._20_4_;
  sVar1 = *(short *)((int)&pTVar4[2].destructor + 2);
  if (*(short *)&pTVar4[2].local < *(short *)((int)&pTVar4[2].destructor + 2)) {
    sVar1 = *(short *)&pTVar4[2].local;
  }
  iVar6 = (int)Scr_OtSize;
  *(short *)&pTVar4[2].display = *(short *)&pTVar4[2].destructor * sVar1;
  Main_Prims = (void *)GtxShp_DisplayListLOFF(&pTVar4[2].bnext,pvVar3,Scr->ot,iVar6,0,uVar2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX01_DispSmoke()
 // line 845, offset 0x8005f670
	/* begin block 1 */
		// Start line: 846
		// Start offset: 0x8005F670
		// Variables:
	// 		struct SFX_118fake *ex; // $s0
	// 		struct SFX_31fake *p; // $s1
	// 		struct SFX_70fake shp; // stack offset -40
	// 		long z; // stack offset -24

		/* begin block 1.1 */
			// Start line: 863
			// Start offset: 0x8005F72C
		/* end block 1.1 */
		// End offset: 0x8005F820
		// End Line: 875
	/* end block 1 */
	// End offset: 0x8005F820
	// End Line: 878

	/* begin block 2 */
		// Start line: 2146
	/* end block 2 */
	// End Line: 2147

/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void SFX01_DispSmoke(void)

{
  short sVar1;
  undefined4 uVar2;
  void *pvVar3;
  TASK *pTVar4;
  _SCREEN *p_Var5;
  undefined4 in_zero;
  undefined4 in_at;
  int iVar6;
  SHAPE_31fake *prim;
  uint uVar7;
  void *local_28;
  short local_24;
  undefined4 local_20;
  int local_18;
  
  pTVar4 = TaskCurrent;
  local_28 = Effects_Pcl;
  local_24 = *(short *)&TaskCurrent[2].local +
             *(short *)((int)&TaskCurrent[2].destructor + 2) + 0x2d;
  prim = (SHAPE_31fake *)(&TaskCurrent[5].bprec + (int)Scr_Frame * 10);
  if (local_24 < 0x46) {
    setCopReg(2,in_zero,TaskCurrent[1].s0);
    setCopReg(2,in_at,TaskCurrent[1].s1);
    copFunction(2,0x180001);
    local_20 = getCopReg(2,0xe);
    local_18 = getCopReg(2,0x9800);
    local_18 = local_18 >> 2;
    if ((0 < local_18) && (local_18 < (int)Scr_OtSize)) {
      uVar7 = ((int)Scr_GeomScreen * 0x3c) / local_18;
      if (local_18 == 0) {
        trap(0x1c00);
      }
      if ((local_18 == -1) && ((int)Scr_GeomScreen * 0x3c == -0x80000000)) {
        trap(0x1800);
      }
      if (2 < (int)uVar7) {
        local_20._2_2_ = (short)((uint)local_20 >> 0x10);
        sVar1 = (short)((int)(uVar7 + (uVar7 >> 0x1f)) >> 1);
        local_20 = CONCAT22(local_20._2_2_ - sVar1,(short)local_20 - sVar1);
        Shp_SetPolyFT4(prim,(SHAPE_68fake *)&local_28,(short)uVar7,(short)uVar7);
        SetSemiTrans((int)prim,1);
        p_Var5 = Scr;
        prim->tag = prim->tag & 0xff000000 | Scr->ot[local_18] & 0xffffff;
        p_Var5->ot[local_18] = p_Var5->ot[local_18] & 0xff000000 | (uint)prim & 0xffffff;
      }
    }
  }
  pvVar3 = Main_Prims;
  uVar2 = Main_TextContext.Font.ascii_tab._20_4_;
  iVar6 = (int)Scr_OtSize;
  *(short *)&pTVar4[2].display =
       *(short *)&pTVar4[2].destructor * *(short *)((int)&pTVar4[2].destructor + 2);
  Main_Prims = (void *)GtxShp_DisplayListLOFF(&pTVar4[2].bnext,pvVar3,Scr->ot,iVar6,0,uVar2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX02_Init(struct SFX_118fake *ex /*$s2*/, long nPart /*$s6*/)
 // line 888, offset 0x8005f888
	/* begin block 1 */
		// Start line: 889
		// Start offset: 0x8005F888
		// Variables:
	// 		struct _D3_OBJECT *hurt; // $a0
	// 		struct SFX_7fake spd3D; // stack offset -40
	// 		long i; // $s1
	// 		long nPrim; // $a0

		/* begin block 1.1 */
			// Start line: 921
			// Start offset: 0x8005F9A0
			// Variables:
		// 		struct SFX_7fake *spd; // $s0
		/* end block 1.1 */
		// End offset: 0x8005F9A0
		// End Line: 921
	/* end block 1 */
	// End offset: 0x8005FAC4
	// End Line: 940

	/* begin block 2 */
		// Start line: 2248
	/* end block 2 */
	// End Line: 2249

void SFX02_Init(SFX_118fake *ex,long nPart)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  void *pvVar4;
  short *psVar5;
  SFX_118fake *pSVar6;
  int iVar7;
  int iVar8;
  short local_28;
  short local_26;
  
  pvVar4 = (ex->t).local;
  *(undefined2 *)(ex->type + 0x22) = 0;
  if (nPart < 2) {
    *(undefined2 *)(ex->type + 0x20) = 1;
  }
  else {
    *(undefined2 *)(ex->type + 0x20) = *(undefined2 *)(ex[2].t.s7 + 8);
  }
  *(undefined2 *)(ex->type + 0x24) = 0;
  *(undefined2 *)(ex->type + 0x26) = 0x19;
  if (pvVar4 == (void *)0x0) {
    local_28 = 0;
    local_26 = 0;
  }
  else {
    uVar1 = (int)*(short *)((int)pvVar4 + 0x2c) - (int)*(short *)((int)pvVar4 + 0x34);
    local_28 = (short)((int)(uVar1 + (uVar1 >> 0x1f)) >> 1);
    uVar1 = (int)*(short *)((int)pvVar4 + 0x2e) - (int)*(short *)((int)pvVar4 + 0x36);
    local_26 = (short)((int)(uVar1 + (uVar1 >> 0x1f)) >> 1);
  }
  iVar7 = 0;
  lVar2 = M_rand();
  if (0 < *(short *)(ex->type + 0x20)) {
    iVar8 = 0x158;
    pSVar6 = ex;
    do {
      psVar5 = (short *)((int)&(ex->t).prec + iVar8);
      lVar3 = M_rand();
      *psVar5 = local_28 + (short)lVar3 + (short)(lVar3 / 0x28) * -0x28 + -0x14;
      lVar3 = M_rand();
      iVar8 = iVar8 + 8;
      psVar5[1] = local_26 + (short)lVar3 + (short)(lVar3 / 0x28) * -0x28 + -0x14;
      iVar7 = iVar7 + 1;
      psVar5[2] = (short)lVar2 + (short)(lVar2 / 0x2d) * -0x2d + 10;
      lVar3 = *(long *)&(ex->obj).pos.vz;
      pSVar6[1].t.s3 = *(long *)&(ex->obj).pos;
      pSVar6[1].t.s4 = lVar3;
      pSVar6 = (SFX_118fake *)&(pSVar6->t).father;
    } while (iVar7 < (int)*(short *)(ex->type + 0x20));
  }
  if ((nPart == 1) && (((ex->obj).display_mode & 0x1000U) == 0)) {
    lVar2 = *(int *)(ex[2].t.s7 + 0x14);
  }
  else {
    lVar2 = Tmd_GetnPrimitives((void *)ex[2].t.s7);
  }
  iVar7 = 0;
  pSVar6 = ex;
  do {
    pvVar4 = Heap_AllocMem(lVar2 * 0x28);
    *(void **)(pSVar6[1].type + 0xc) = pvVar4;
    iVar7 = iVar7 + 1;
    pSVar6 = (SFX_118fake *)&(pSVar6->t).next;
  } while (iVar7 < 2);
  (ex->t).destructor = SFX02_Destructor;
  ex[2].t.fp = -0x7ffa04a8;
  *(code **)&ex[2].t.text_context = SFX02_DispExplosion;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX02_Destructor(struct TASK *t /*$a0*/)
 // line 948, offset 0x8005fb10
	/* begin block 1 */
		// Start line: 949
		// Start offset: 0x8005FB10
		// Variables:
	// 		long i; // $s1
	/* end block 1 */
	// End offset: 0x8005FB44
	// End Line: 956

	/* begin block 2 */
		// Start line: 2389
	/* end block 2 */
	// End Line: 2390

void SFX02_Destructor(TASK *t)

{
  TASK *pTVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    pTVar1 = t + 4;
    t = (TASK *)&t->next;
    iVar2 = iVar2 + 1;
    Heap_FreeMem((void *)pTVar1->event_s7);
  } while (iVar2 < 2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX02_MoveExplosion()
 // line 959, offset 0x8005fb58
	/* begin block 1 */
		// Start line: 960
		// Start offset: 0x8005FB58
		// Variables:
	// 		struct SFX_118fake *ex; // $s0
	// 		long i; // $s2
	// 		long test; // $s3
	/* end block 1 */
	// End offset: 0x8005FC3C
	// End Line: 1000

	/* begin block 2 */
		// Start line: 2423
	/* end block 2 */
	// End Line: 2424

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SFX02_MoveExplosion(void)

{
  short sVar1;
  TASK *ex;
  long lVar2;
  short sVar3;
  char cVar4;
  int piece;
  int iVar5;
  
  ex = TaskCurrent;
  SFX_D3ShakeScreen((_D3_OBJECT *)(TaskCurrent + 1),(_D3_OBJECT *)&Player,0x3c,10);
  do {
    piece = 0;
    iVar5 = 0;
    if (0 < *(short *)&ex[2].destructor) {
      cVar4 = -0x30;
      do {
        lVar2 = SFX_GetPieceSpeed((SFX_118fake *)ex,(char)ex + cVar4,piece);
        iVar5 = iVar5 + lVar2;
        piece = piece + 1;
        cVar4 = cVar4 + '\b';
      } while (piece < (int)*(short *)&ex[2].destructor);
    }
    sVar3 = *(short *)((int)&ex[2].local + 2) + -1;
    if (*(short *)((int)&ex[2].local + 2) < 1) {
      *(undefined2 *)&ex[2].s0 = 0;
      *(undefined2 *)((int)&ex[2].s0 + 2) = 0;
      *(undefined2 *)&ex[2].s1 = 0;
    }
    else {
      *(short *)((int)&ex[2].local + 2) = sVar3;
      *(short *)&ex[2].s0 = *(short *)&ex[2].s0 + sVar3;
      sVar1 = *(short *)&ex[2].s1;
      *(short *)((int)&ex[2].s0 + 2) = *(short *)((int)&ex[2].s0 + 2) + sVar3;
      *(short *)&ex[2].s1 = sVar1 + sVar3;
    }
    *(short *)&ex[2].local = *(short *)&ex[2].local + 1;
    Task_Next();
  } while (iVar5 != 0);
  TaskCurrent->display = SFX02_DispPieces;
  *(code **)&ex[6].sp = SFX02_DontMove;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX02_DontMove()
 // line 1005, offset 0x8005fc78
	/* begin block 1 */
		// Start line: 1006
		// Start offset: 0x8005FC78
		// Variables:
	// 		struct SFX_118fake *ex; // $s3
	// 		long i; // $s4
	// 		long j; // $s1
	/* end block 1 */
	// End offset: 0x8005FD0C
	// End Line: 1026

	/* begin block 2 */
		// Start line: 2537
	/* end block 2 */
	// End Line: 2538

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SFX02_DontMove(void)

{
  TASK *pTVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  TASK *pTVar5;
  int iVar6;
  
  pTVar1 = TaskCurrent;
  iVar6 = 0x180;
  do {
    iVar4 = 0;
    if (0 < *(short *)&pTVar1[2].destructor) {
      cVar3 = -0x30;
      pTVar5 = pTVar1;
      do {
        lVar2 = SFX_IsPieceClipped((char)pTVar1 + cVar3);
        if (lVar2 != 0) {
          *(undefined2 *)&pTVar5[3].destructor = 0xfa24;
        }
        pTVar5 = (TASK *)&pTVar5->father;
        iVar4 = iVar4 + 1;
        cVar3 = cVar3 + '\b';
      } while (iVar4 < (int)*(short *)&pTVar1[2].destructor);
    }
    lVar2 = SFX_IsPiecePresent();
    if (lVar2 == 0) break;
    iVar6 = iVar6 + -1;
    Task_Next();
  } while (iVar6 != 0);
  pTVar1[6].sp = (void *)0x0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX02_DispExplosion()
 // line 1030, offset 0x8005fd34
	/* begin block 1 */
		// Start line: 1031
		// Start offset: 0x8005FD34
		// Variables:
	// 		struct SFX_118fake *ex; // $s0
	// 		void *Pr; // $s1
	// 		long i; // $s2
	// 		struct SFX_5fake m2; // stack offset -120
	// 		struct SFX_5fake mn64; // stack offset -88

		/* begin block 1.1 */
			// Start line: 1046
			// Start offset: 0x8005FDC4
			// Variables:
		// 		struct SFX_7fake *pos; // $v0
		// 		struct SFX_5fake m; // stack offset -56
		/* end block 1.1 */
		// End offset: 0x8005FEC8
		// End Line: 1065
	/* end block 1 */
	// End offset: 0x8005FF0C
	// End Line: 1068

	/* begin block 2 */
		// Start line: 2612
	/* end block 2 */
	// End Line: 2613

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SFX02_DispExplosion(void)

{
  TASK *pTVar1;
  undefined4 in_zero;
  undefined4 in_at;
  long lVar2;
  int iVar3;
  int iVar4;
  undefined4 auStack120 [21];
  int local_24;
  int local_20;
  int local_1c;
  
  pTVar1 = TaskCurrent;
  lVar2 = (&TaskCurrent[4].event_s7)[(int)Scr_Frame];
  RotMatrix((short *)&TaskCurrent[2].s0,(undefined2 *)auStack120);
  setCopControlWord(2,0,Cam_Matrix.m[0]._0_4_);
  setCopControlWord(2,0x800,Cam_Matrix.m._4_4_);
  setCopControlWord(2,0x1000,Cam_Matrix.m[1]._2_4_);
  setCopControlWord(2,0x1800,Cam_Matrix.m[2]._0_4_);
  setCopControlWord(2,0x2000,Cam_Matrix._16_4_);
  iVar3 = 0;
  if (0 < *(short *)&pTVar1[2].destructor) {
    iVar4 = 0xc;
    do {
      setCopReg(2,in_zero,(&pTVar1[3].display)[iVar3 * 2]);
      setCopReg(2,in_at,(&pTVar1[3].display + iVar3 * 2)[1]);
      copFunction(2,0x486012);
      local_24 = getCopReg(2,0x19);
      local_20 = getCopReg(2,0x1a);
      local_1c = getCopReg(2,0x1b);
      local_24 = local_24 + Cam_Matrix.t[0];
      local_20 = local_20 + Cam_Matrix.t[1];
      local_1c = local_1c + Cam_Matrix.t[2];
      setCopControlWord(2,0x2800,local_24);
      setCopControlWord(2,0x3000,local_20);
      setCopControlWord(2,0x3800,local_1c);
      SetMulMatrix(auStack120,(ushort *)&Cam_Matrix);
      if (*(short *)&pTVar1[2].destructor == 1) {
        lVar2 = GtxTmd_DisplayLON(pTVar1[6].exec,lVar2,Scr->ot,(int)Scr_OtSize,0,0x808080);
      }
      else {
        lVar2 = GtxTmd_DisplayLOFF(pTVar1[6].exec + iVar4,lVar2,Scr->ot,(int)Scr_OtSize,0);
      }
      setCopControlWord(2,0,Cam_Matrix.m[0]._0_4_);
      setCopControlWord(2,0x800,Cam_Matrix.m._4_4_);
      setCopControlWord(2,0x1000,Cam_Matrix.m[1]._2_4_);
      setCopControlWord(2,0x1800,Cam_Matrix.m[2]._0_4_);
      setCopControlWord(2,0x2000,Cam_Matrix._16_4_);
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x1c;
    } while (iVar3 < (int)*(short *)&pTVar1[2].destructor);
  }
  setCopControlWord(2,0x2800,Cam_Matrix.t[0]);
  setCopControlWord(2,0x3000,Cam_Matrix.t[1]);
  setCopControlWord(2,0x3800,Cam_Matrix.t[2]);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX02_DispPieces()
 // line 1072, offset 0x8005ff4c
	/* begin block 1 */
		// Start line: 1073
		// Start offset: 0x8005FF4C
		// Variables:
	// 		struct SFX_118fake *ex; // $s0
	// 		void *Pr; // $a2
	// 		long i; // $s1

		/* begin block 1.1 */
			// Start line: 1080
			// Start offset: 0x8005FF8C
			// Variables:
		// 		struct SFX_7fake *pos; // $v1
		// 		struct SFX_5fake m; // stack offset -48
		/* end block 1.1 */
		// End offset: 0x80060098
		// End Line: 1099
	/* end block 1 */
	// End offset: 0x800600AC
	// End Line: 1101

	/* begin block 2 */
		// Start line: 2728
	/* end block 2 */
	// End Line: 2729

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SFX02_DispPieces(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  TASK *pTVar4;
  undefined4 in_zero;
  undefined4 in_at;
  _func_11 **pp_Var5;
  long lVar6;
  int iVar7;
  int iVar8;
  
  pTVar4 = TaskCurrent;
  lVar6 = (&TaskCurrent[4].event_s7)[(int)Scr_Frame];
  iVar7 = 0;
  if (0 < *(short *)&TaskCurrent[2].destructor) {
    iVar8 = 0xc;
    do {
      pp_Var5 = &pTVar4[3].display + iVar7 * 2;
      if (-0x5dc < *(short *)(pp_Var5 + 1)) {
        setCopReg(2,in_zero,*pp_Var5);
        setCopReg(2,in_at,pp_Var5[1]);
        copFunction(2,0x486012);
        iVar1 = getCopReg(2,0x19);
        iVar2 = getCopReg(2,0x1a);
        iVar3 = getCopReg(2,0x1b);
        setCopControlWord(2,0x2800,iVar1 + Cam_Matrix.t[0]);
        setCopControlWord(2,0x3000,iVar2 + Cam_Matrix.t[1]);
        setCopControlWord(2,0x3800,iVar3 + Cam_Matrix.t[2]);
        if (*(short *)&pTVar4[2].destructor == 1) {
          lVar6 = GtxTmd_DisplayLON(pTVar4[6].exec,lVar6,Scr->ot,(int)Scr_OtSize,0,0x808080);
        }
        else {
          lVar6 = GtxTmd_DisplayLOFF(pTVar4[6].exec + iVar8,lVar6,Scr->ot,(int)Scr_OtSize,0);
        }
      }
      iVar7 = iVar7 + 1;
      iVar8 = iVar8 + 0x1c;
    } while (iVar7 < (int)*(short *)&pTVar4[2].destructor);
  }
  setCopControlWord(2,0x2800,Cam_Matrix.t[0]);
  setCopControlWord(2,0x3000,Cam_Matrix.t[1]);
  setCopControlWord(2,0x3800,Cam_Matrix.t[2]);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX04_Init(struct SFX_118fake *ex /*$s3*/, long nb_part /*$a1*/, long num_sprt /*stack 8*/, long nb_sprt /*stack 12*/)
 // line 1107, offset 0x800600e4
	/* begin block 1 */
		// Start line: 1108
		// Start offset: 0x800600E4
		// Variables:
	// 		struct _D3_OBJECT *hurt; // $fp
	// 		struct SFX_7fake spd3D; // stack offset -48
	// 		long i; // $s6
	// 		long max; // $s5

		/* begin block 1.1 */
			// Start line: 1179
			// Start offset: 0x80060324
			// Variables:
		// 		struct SFX_7fake *spd; // $s2
		/* end block 1.1 */
		// End offset: 0x800606A0
		// End Line: 1222
	/* end block 1 */
	// End offset: 0x800606B4
	// End Line: 1225

	/* begin block 2 */
		// Start line: 2823
	/* end block 2 */
	// End Line: 2824

void SFX04_Init(SFX_118fake *ex,long nb_part,long num_sprt,long nb_sprt)

{
  short sVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  void *pvVar6;
  undefined4 *puVar7;
  long lVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  short *psVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  void *pvVar16;
  short local_res8;
  undefined2 local_resc;
  short local_30;
  short local_2e;
  ushort local_2c;
  
  iVar3 = nb_sprt >> 0x10;
  uVar14 = SEXT24(*(short *)(ex[1].type + 6));
  pvVar16 = (ex->t).local;
  if (iVar3 == 0) {
    uVar4 = *(uint *)(ex->type + 0x30) & 0xfffffffd | 1;
  }
  else {
    if ((nb_sprt & 0xffff0000U) == 0xff0000) {
      uVar4 = *(uint *)(ex->type + 0x30) & 0xfffffffd;
    }
    else {
      uVar4 = *(uint *)(ex->type + 0x30) | 2;
    }
    *(uint *)(ex->type + 0x30) = uVar4;
    uVar4 = *(uint *)(ex->type + 0x30) & 0xfffffffe;
  }
  *(uint *)(ex->type + 0x30) = uVar4;
  *(undefined2 *)(ex->type + 0x22) = 0;
  *(short *)(ex->type + 0x20) = (short)nb_part;
  *(undefined2 *)(ex->type + 0x24) = 0;
  *(undefined2 *)(ex->type + 0x26) = 0;
  local_res8 = (short)num_sprt;
  *(short *)(ex[1].type + 8) = local_res8;
  local_resc = (undefined2)nb_sprt;
  *(undefined2 *)(ex[1].type + 10) = local_resc;
  if (pvVar16 == (void *)0x0) {
    if (((nb_sprt & 0xffff0000U) != 0) && ((*(uint *)(ex->type + 0x30) & 2) != 0)) {
      local_30 = 0;
      local_2e = 0;
      lVar5 = M_rand();
      uVar14 = 0x10;
      local_2c = (ushort)lVar5 & 0x14;
      if (iVar3 == 2) {
        local_2e = 1;
      }
      else {
        if (iVar3 < 3) {
          if (iVar3 == 1) {
            local_30 = (short)((uint)nb_sprt >> 0x10);
          }
        }
        else {
          if (iVar3 == 3) {
            local_30 = -1;
          }
          else {
            if (iVar3 == 4) {
              local_2e = -1;
            }
          }
        }
      }
    }
  }
  else {
    uVar4 = (int)*(short *)((int)pvVar16 + 0x2c) - (int)*(short *)((int)pvVar16 + 0x34);
    local_30 = (short)((int)(uVar4 + (uVar4 >> 0x1f)) >> 1);
    uVar4 = (int)*(short *)((int)pvVar16 + 0x2e) - (int)*(short *)((int)pvVar16 + 0x36);
    local_2e = (short)((int)(uVar4 + (uVar4 >> 0x1f)) >> 1);
    lVar5 = M_rand();
    local_2c = (short)lVar5 + (short)(lVar5 / 0x23) * -0x23 + 5;
  }
  pvVar6 = Effects_Pcl;
  *(undefined4 *)(ex->type + 0x18) = 0;
  *(void **)(ex->type + 0x10) = pvVar6;
  pvVar6 = Heap_AllocMem((int)*(short *)(ex->type + 0x20) << 3);
  *(void **)(ex->type + 0x14) = pvVar6;
  pvVar6 = Heap_AllocMem((int)*(short *)(ex->type + 0x20) << 2);
  iVar15 = 0;
  *(void **)(ex->type + 0x18) = pvVar6;
  *(undefined2 *)(ex->type + 0x1c) = *(undefined2 *)(ex->type + 0x20);
  if (0 < *(short *)(ex->type + 0x20)) {
    iVar13 = 0;
    do {
      iVar11 = iVar15 * 8;
      lVar5 = M_rand();
      uVar4 = nb_sprt & 0xffff;
      if (uVar4 == 0) {
        trap(0x1c00);
      }
      if ((uVar4 == 0xffffffff) && (lVar5 == -0x80000000)) {
        trap(0x1800);
      }
      puVar7 = (undefined4 *)(iVar11 + *(int *)(ex->type + 0x14));
      uVar10 = *(undefined4 *)&(ex->obj).pos.vz;
      *puVar7 = *(undefined4 *)&(ex->obj).pos;
      puVar7[1] = uVar10;
      psVar12 = (short *)(ex->type + iVar11 + 0x34);
      lVar8 = M_rand();
      iVar9 = (int)*(short *)(ex[1].type + 4);
      if (iVar9 == 0) {
        trap(0x1c00);
      }
      if ((iVar9 == -1) && (lVar8 == -0x80000000)) {
        trap(0x1800);
      }
      *(ushort *)(iVar11 + *(int *)(ex->type + 0x14) + 6) =
           (short)(lVar8 % iVar9) + 1U | (local_res8 + (short)(lVar5 % uVar4)) * 0x100;
      if ((iVar3 == 0) || ((*(uint *)(ex->type + 0x30) & 2) == 0)) {
        *(undefined *)(iVar13 + *(int *)(ex->type + 0x18)) = 0x80;
        *(undefined *)(iVar13 + *(int *)(ex->type + 0x18) + 1) = 0x80;
        *(undefined *)(iVar13 + *(int *)(ex->type + 0x18) + 2) = 0x80;
      }
      else {
        *(undefined *)(iVar13 + *(int *)(ex->type + 0x18)) = 0x20;
        *(undefined *)(iVar13 + *(int *)(ex->type + 0x18) + 1) = 0x20;
        *(undefined *)(iVar13 + *(int *)(ex->type + 0x18) + 2) = 0x20;
      }
      sVar1 = (short)((int)(uVar14 + (uVar14 >> 0x1f)) >> 1);
      if (pvVar16 == (void *)0x0) {
        if (((nb_sprt & 0xffff0000U) == 0) || ((*(uint *)(ex->type + 0x30) & 2) == 0)) {
          lVar5 = M_rand();
          if (uVar14 == 0) {
            trap(0x1c00);
          }
          if ((uVar14 == 0xffffffff) && (lVar5 == -0x80000000)) {
            trap(0x1800);
          }
          *psVar12 = (short)(lVar5 % uVar14) - sVar1;
          lVar5 = M_rand();
          if (uVar14 == 0) {
            trap(0x1c00);
          }
          if ((uVar14 == 0xffffffff) && (lVar5 == -0x80000000)) {
            trap(0x1800);
          }
          psVar12[1] = (short)(lVar5 % uVar14) - sVar1;
          lVar5 = M_rand();
          uVar2 = (short)lVar5 + (short)(lVar5 / 0x23) * -0x23 + 5;
        }
        else {
          if (local_30 == 0) {
            lVar5 = M_rand();
            psVar12[1] = local_2e * ((ushort)lVar5 & 0xf);
          }
          else {
            lVar5 = M_rand();
            psVar12[1] = ((ushort)lVar5 & 0xf) - 8;
          }
          if (local_2e == 0) {
            lVar5 = M_rand();
            *psVar12 = local_30 * ((ushort)lVar5 & 0xf);
            uVar2 = local_2c;
          }
          else {
            lVar5 = M_rand();
            *psVar12 = ((ushort)lVar5 & 0xf) - 8;
            uVar2 = local_2c;
          }
        }
      }
      else {
        lVar5 = M_rand();
        if (uVar14 == 0) {
          trap(0x1c00);
        }
        if ((uVar14 == 0xffffffff) && (lVar5 == -0x80000000)) {
          trap(0x1800);
        }
        *psVar12 = (local_30 + (short)(lVar5 % uVar14)) - sVar1;
        lVar5 = M_rand();
        if (uVar14 == 0) {
          trap(0x1c00);
        }
        if ((uVar14 == 0xffffffff) && (lVar5 == -0x80000000)) {
          trap(0x1800);
        }
        psVar12[1] = (local_2e + (short)(lVar5 % uVar14)) - sVar1;
        uVar2 = local_2c;
      }
      psVar12[2] = uVar2;
      iVar15 = iVar15 + 1;
      iVar13 = iVar13 + 4;
    } while (iVar15 < (int)*(short *)(ex->type + 0x20));
  }
  (ex->t).destructor = SFX04_Destructor;
  ex[2].t.fp = -0x7ff9f864;
  *(code **)&ex[2].t.text_context = SFX04_DispExplosion;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX04_Destructor(struct TASK *t /*$a0*/)
 // line 1233, offset 0x80060708
	/* begin block 1 */
		// Start line: 1234
		// Start offset: 0x80060708
		// Variables:
	// 		int i; // $a0
	// 		struct SFX_118fake *ex; // $s0
	/* end block 1 */
	// End offset: 0x80060774
	// End Line: 1246

	/* begin block 2 */
		// Start line: 3135
	/* end block 2 */
	// End Line: 3136

void SFX04_Destructor(TASK *t)

{
  int iVar1;
  
  if (((t[2].s2 & 1U) != 0) && (iVar1 = 0, 0 < *(short *)((int)&t[4].event_s6 + 2))) {
    do {
      *(undefined *)
       (*(int *)((int)Effects_Pcl + ((int)*(short *)&t[4].event_s6 + iVar1) * 4 + 0x10) + 0x11) = 1;
      iVar1 = iVar1 + 1;
    } while (iVar1 < (int)*(short *)((int)&t[4].event_s6 + 2));
  }
  Heap_FreeMem(t[2].exec);
  Heap_FreeMem(t[2].sp);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX04_MoveExplosion()
 // line 1251, offset 0x8006079c
	/* begin block 1 */
		// Start line: 1252
		// Start offset: 0x8006079C
		// Variables:
	// 		struct SFX_118fake *ex; // $s1
	// 		long result; // $a2
	// 		long i; // $s0
	// 		long test; // $s5
	// 		long num; // $a0
	// 		long num_sprt; // $fp
	// 		long nb_sprt; // $v1
	// 		long movingparts; // $s6
	// 		long flipflop; // $s7

		/* begin block 1.1 */
			// Start line: 1284
			// Start offset: 0x80060840
			// Variables:
		// 		struct SFX_7fake *spd; // $s3
		/* end block 1.1 */
		// End offset: 0x800608E0
		// End Line: 1302

		/* begin block 1.2 */
			// Start line: 1315
			// Start offset: 0x80060940
			// Variables:
		// 		long j; // $a1
		// 		struct SFX_8fake *col; // $a0
		/* end block 1.2 */
		// End offset: 0x8006097C
		// End Line: 1324
	/* end block 1 */
	// End offset: 0x800609A4
	// End Line: 1336

	/* begin block 2 */
		// Start line: 3172
	/* end block 2 */
	// End Line: 3173

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SFX04_MoveExplosion(void)

{
  short sVar1;
  short sVar2;
  ushort uVar3;
  TASK *ex;
  uint piece;
  int iVar4;
  undefined *puVar5;
  uint uVar6;
  undefined *puVar7;
  char cVar8;
  undefined uVar9;
  uint uVar10;
  int iVar11;
  short *psVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  
  ex = TaskCurrent;
  sVar1 = *(short *)&TaskCurrent[4].event_s6;
  sVar2 = *(short *)((int)&TaskCurrent[4].event_s6 + 2);
  iVar16 = 0;
  if ((TaskCurrent[2].s2 & 2U) == 0) {
    iVar15 = (int)*(short *)&TaskCurrent[2].display;
  }
  else {
    iVar15 = 0;
  }
  do {
    uVar14 = 0;
    if (iVar15 != (int)*(short *)&ex[2].display) {
      uVar14 = 1;
      if (iVar16 == 0) {
        iVar15 = iVar15 + 1;
        iVar16 = 2;
      }
      else {
        iVar16 = iVar16 + -1;
      }
    }
    uVar10 = 0;
    if (0 < iVar15) {
      iVar11 = 0;
      iVar13 = 0x158;
      do {
        psVar12 = (short *)((int)&ex->prec + iVar13);
        if ((ex[2].s2 & 2U) == 0) {
          cVar8 = (char)ex[2].exec;
          piece = uVar10;
        }
        else {
          cVar8 = (char)ex[2].exec;
          piece = uVar10 | 0x10000;
        }
        piece = SFX_GetPieceSpeed((SFX_118fake *)ex,cVar8 + (char)iVar11,piece);
        if ((int)*psVar12 + (int)psVar12[1] != 0) {
          uVar3 = *(ushort *)(ex[2].exec + iVar11 + 6);
          uVar6 = (uint)(uVar3 >> 8);
          iVar4 = (int)sVar1;
          if (uVar6 != ((int)sVar1 + (int)sVar2) - 1U) {
            iVar4 = uVar6 + 1;
          }
          *(ushort *)(ex[2].exec + iVar11 + 6) = uVar3 & 0xff;
          *(ushort *)(ex[2].exec + iVar11 + 6) =
               *(ushort *)(ex[2].exec + iVar11 + 6) | (ushort)(iVar4 << 8);
        }
        uVar14 = uVar14 | piece;
        iVar11 = iVar11 + 8;
        uVar10 = uVar10 + 1;
        iVar13 = iVar13 + 8;
      } while ((int)uVar10 < iVar15);
    }
    *(short *)&ex[2].local = *(short *)&ex[2].local + 1;
    Task_Next();
  } while (uVar14 != 0);
  iVar16 = 0x3c;
  if (((ex[2].s2 & 1U) == 0) ||
     (uVar14 = ex[2].s2, *(undefined2 *)((int)&ex[4].event_s5 + 2) = 0, (uVar14 & 1) == 0)) {
    do {
      iVar16 = iVar16 + -1;
      Task_Next();
    } while (iVar16 != 0);
    ex[6].sp = (void *)0x0;
  }
  else {
    iVar16 = 0xa0;
    do {
      puVar7 = (undefined *)ex[2].sp;
      iVar15 = 0;
      if (0 < *(short *)&ex[2].destructor) {
        puVar5 = puVar7 + 2;
        do {
          iVar15 = iVar15 + 1;
          uVar9 = (undefined)iVar16;
          *puVar7 = uVar9;
          puVar5[-1] = uVar9;
          *puVar5 = uVar9;
          puVar5 = puVar5 + 4;
          puVar7 = puVar7 + 4;
        } while (iVar15 < (int)*(short *)&ex[2].destructor);
      }
      iVar16 = iVar16 + -1;
      Task_Next();
    } while (iVar16 != 0);
    ex[6].sp = (void *)0x0;
  }
  ex[6].display = (_func_11 *)0x0;
  Task_Sleep(2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX04_DispExplosion()
 // line 1340, offset 0x800609e0
	/* begin block 1 */
		// Start line: 1341
		// Start offset: 0x800609E0
		// Variables:
	// 		struct SFX_118fake *ex; // $s0
	// 		long i; // $a0
	/* end block 1 */
	// End offset: 0x80060AD8
	// End Line: 1358

	/* begin block 2 */
		// Start line: 3394
	/* end block 2 */
	// End Line: 3395

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SFX04_DispExplosion(void)

{
  TASK *pTVar1;
  int iVar2;
  
  pTVar1 = TaskCurrent;
  if ((*(short *)((int)&TaskCurrent[4].event_s5 + 2) == 0) &&
     (iVar2 = 0, 0 < *(short *)((int)&TaskCurrent[4].event_s6 + 2))) {
    do {
      *(undefined *)
       (*(int *)((int)Effects_Pcl + ((int)*(short *)&pTVar1[4].event_s6 + iVar2) * 4 + 0x10) + 0x11)
           = 1;
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)*(short *)((int)&pTVar1[4].event_s6 + 2));
  }
  Main_Prims = (void *)GtxShp_DisplayListLOFF
                                 (&pTVar1[2].bnext,Main_Prims,Scr->ot,(int)Scr_OtSize,0,
                                  Main_TextContext.Font.ascii_tab._20_4_);
  if ((*(short *)((int)&pTVar1[4].event_s5 + 2) == 0) &&
     (iVar2 = 0, 0 < *(short *)((int)&pTVar1[4].event_s6 + 2))) {
    do {
      *(undefined *)
       (*(int *)((int)Effects_Pcl + ((int)*(short *)&pTVar1[4].event_s6 + iVar2) * 4 + 0x10) + 0x11)
           = 0;
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)*(short *)((int)&pTVar1[4].event_s6 + 2));
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX05_Init(struct SFX_118fake *ex /*$a3*/, long circle /*$a1*/, long mode /*$a2*/)
 // line 1367, offset 0x80060ae8
	/* begin block 1 */
		// Start line: 3453
	/* end block 1 */
	// End Line: 3454

void SFX05_Init(SFX_118fake *ex,long circle,long mode)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  
  (ex->t).destructor = SFX05_Destructor;
  sVar1 = (ex->list).pos.vx;
  sVar2 = (ex->obj).b_box.vz;
  *(short *)(ex->type + 0x22) = (short)circle;
  *(undefined2 *)(ex->type + 0x20) = 0;
  *(undefined2 *)(ex->type + 0x24) = 0;
  *(long *)(ex->type + 0x34) = mode;
  ex[2].t.fp = -0x7ff9f488;
  ex[2].t.text_context = (TEXTCONTEXT *)0x0;
  uVar3 = (int)sVar1 + (int)sVar2;
  (ex->obj).pos.vz = (ex->obj).pos.vz - (short)((int)(uVar3 + (uVar3 >> 0x1f)) >> 1);
  if (mode != 0) {
    *(code **)&ex[2].t.text_context = SFX05_DispExplosion;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX05_Destructor(struct TASK *t /*$a0*/)
 // line 1392, offset 0x80060b58
	/* begin block 1 */
		// Start line: 1393
		// Start offset: 0x80060B58
	/* end block 1 */
	// End offset: 0x80060B58
	// End Line: 1393

	/* begin block 2 */
		// Start line: 3557
	/* end block 2 */
	// End Line: 3558

void SFX05_Destructor(TASK *t)

{
  Light_Delete((_LIGHT *)&t[5].sp);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX05_MoveExplosion()
 // line 1401, offset 0x80060b78
	/* begin block 1 */
		// Start line: 1402
		// Start offset: 0x80060B78
		// Variables:
	// 		struct SFX_118fake *ex; // $s1
	// 		struct _LIGHT *light; // $a0
	// 		struct _D3_OBJECT obj; // stack offset -208
	// 		struct SFX_8fake col; // stack offset -40
	// 		long r; // $s0
	// 		long size; // $s3
	// 		long grey; // stack offset -32
	/* end block 1 */
	// End offset: 0x80060D40
	// End Line: 1469

	/* begin block 2 */
		// Start line: 3575
	/* end block 2 */
	// End Line: 3576

/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void SFX05_MoveExplosion(void)

{
  TASK *pTVar1;
  TASK *pTVar2;
  long type;
  int iVar3;
  int dist;
  undefined auStack208 [28];
  short local_b4;
  uchar local_ae;
  long local_a4;
  long local_a0;
  undefined local_37;
  void *local_30;
  undefined *local_28;
  int local_20 [2];
  
  pTVar2 = TaskCurrent;
  local_28 = PTR_DAT_800ad704;
  local_20[0] = 200;
  local_30 = TaskCurrent->local;
  pTVar1 = TaskCurrent + 5;
  *(int **)&TaskCurrent->local = local_20;
  *(undefined2 *)&pTVar2[5].destructor = 0x1400;
  *(undefined2 *)&pTVar2[5].s1 = 0x1000;
  *(undefined2 *)((int)&pTVar2[5].destructor + 2) = 0x1000;
  *(undefined2 *)&pTVar2[5].local = 0x500;
  type = pTVar2[1].s1;
  pTVar2[5].s2 = pTVar2[1].s0;
  pTVar2[5].s3 = type;
  dist = 1;
  Light_Add((_LIGHT *)&pTVar1->sp);
  local_a4 = pTVar2[1].s0;
  local_a0 = pTVar2[1].s1;
  local_ae = '\x05';
  local_37 = *(undefined *)((int)&pTVar2[2].father + 1);
  local_b4 = *(short *)&pTVar2[1].sp;
  D3_SetCollBits((_D3_OBJECT *)auStack208,2);
  if (*(short *)((int)&pTVar2[2].destructor + 2) != 0) {
    type = 0;
    if (pTVar2[2].s3 == 0) {
      type = 4;
      local_28._0_2_ = 0xfa32;
    }
    else {
      local_28._0_2_ = 0xc8fa;
    }
    local_28 = (undefined *)((uint)local_28 & 0xff000000 | (uint)CONCAT12(0x32,local_28._0_2_));
    SFX_ShockWave(type,0x5c,0xd8,9);
    SFX_D3ShakeScreen((_D3_OBJECT *)(pTVar2 + 1),(_D3_OBJECT *)&Player,0x78,0x14);
  }
  iVar3 = 0;
  do {
    if ((iVar3 < 0x14) &&
       (local_20[0] = local_20[0] + -10, *(short *)((int)&pTVar2[2].destructor + 2) != 0)) {
      Boxes_TestDistance((_D3_OBJECT *)auStack208,dist);
      dist = dist + 0x14;
    }
    iVar3 = iVar3 + 1;
    *(short *)&pTVar2[2].local = *(short *)&pTVar2[2].local + 1;
    Task_Next();
  } while (iVar3 < 0x25);
  *(undefined2 *)&pTVar2[2].local = 0;
  pTVar2[6].sp = (void *)0x0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX05_DispExplosion()
 // line 1474, offset 0x80060d68
	/* begin block 1 */
		// Start line: 1475
		// Start offset: 0x80060D68
		// Variables:
	// 		struct SFX_118fake *ex; // $a0
	// 		struct SFX_31fake *p; // $s1
	// 		struct SFX_70fake shp; // stack offset -40
	// 		long z; // stack offset -24

		/* begin block 1.1 */
			// Start line: 1495
			// Start offset: 0x80060E30
		/* end block 1.1 */
		// End offset: 0x80060F2C
		// End Line: 1511
	/* end block 1 */
	// End offset: 0x80060F2C
	// End Line: 1512

	/* begin block 2 */
		// Start line: 3809
	/* end block 2 */
	// End Line: 3810

/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void SFX05_DispExplosion(void)

{
  undefined4 uVar1;
  short w;
  _SCREEN *p_Var2;
  undefined4 in_zero;
  undefined4 in_at;
  uint uVar3;
  int iVar4;
  SHAPE_31fake *prim;
  void *local_28;
  short local_24;
  undefined4 local_20;
  int local_18;
  
  local_28 = Effects_Pcl;
  uVar3 = (uint)*(ushort *)&TaskCurrent[2].local << 0x10;
  local_24 = (short)((int)(((int)uVar3 >> 0x10) + (uVar3 >> 0x1f)) >> 1) + 0x4b;
  iVar4 = (int)TaskCurrent + (int)Scr_Frame * 200 + 0x15c;
  prim = (SHAPE_31fake *)(iVar4 + 0xa0);
  setCopReg(2,in_zero,TaskCurrent[1].s0);
  setCopReg(2,in_at,TaskCurrent[1].s1);
  copFunction(2,0x180001);
  uVar1 = getCopReg(2,0xe);
  local_18 = getCopReg(2,0x9800);
  local_18 = local_18 >> 2;
  if ((0 < local_18) && (local_18 < (int)Scr_OtSize)) {
    uVar3 = ((int)Scr_GeomScreen * 100) / local_18;
    if (local_18 == 0) {
      trap(0x1c00);
    }
    if ((local_18 == -1) && ((int)Scr_GeomScreen * 100 == -0x80000000)) {
      trap(0x1800);
    }
    if (2 < (int)uVar3) {
      local_20._0_2_ = (short)uVar1;
      local_20._2_2_ = (short)((uint)uVar1 >> 0x10);
      w = (short)uVar3;
      local_20 = CONCAT22(local_20._2_2_ - w,
                          (short)local_20 - (short)((int)(uVar3 + (uVar3 >> 0x1f)) >> 1));
      Shp_SetPolyFT4(prim,(SHAPE_68fake *)&local_28,w,w);
      SetSemiTrans((int)prim,1);
      p_Var2 = Scr;
      *(uint *)(iVar4 + 0xa0) = *(uint *)(iVar4 + 0xa0) & 0xff000000 | Scr->ot[local_18] & 0xffffff;
      p_Var2->ot[local_18] = p_Var2->ot[local_18] & 0xff000000 | (uint)prim & 0xffffff;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX_IncendieInit(struct _D3_OBJECT *obj /*$s0*/)
 // line 1519, offset 0x80060f40
	/* begin block 1 */
		// Start line: 1520
		// Start offset: 0x80060F40
		// Variables:
	// 		struct _INCENDIE *Incendie; // $v1
	// 		struct SFX_8fake col; // stack offset -16
	/* end block 1 */
	// End offset: 0x80060FA0
	// End Line: 1531

	/* begin block 2 */
		// Start line: 3917
	/* end block 2 */
	// End Line: 3918

void SFX_IncendieInit(_D3_OBJECT *obj)

{
  TASK *pTVar1;
  
  if (obj->handle == (TASK *)0x0) {
    pTVar1 = Task_Add(SFX_IncendieWithPosTask,0x8c8);
  }
  else {
    pTVar1 = Task_Link(SFX_IncendieWithPosTask,0x8c8);
  }
  *(_D3_OBJECT **)&pTVar1[1].prec = obj;
  pTVar1[1].next = (TASK *)obj->description;
  Tmd_ChangeColor((char)obj->description,0xf0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX_IncendieDestructor()
 // line 1542, offset 0x80060fcc
	/* begin block 1 */
		// Start line: 1543
		// Start offset: 0x80060FCC
		// Variables:
	// 		struct _INCENDIE *Incendie; // $s0
	/* end block 1 */
	// End offset: 0x80060FF8
	// End Line: 1551

	/* begin block 2 */
		// Start line: 3967
	/* end block 2 */
	// End Line: 3968

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SFX_IncendieDestructor(void)

{
  TASK *pTVar1;
  int wPlayId;
  
  pTVar1 = TaskCurrent;
  wPlayId = (int)*(short *)((int)&TaskCurrent[1].destructor + 2);
  if (-1 < wPlayId) {
    Sound_Stop(wPlayId,0);
  }
  Light_Delete((_LIGHT *)&pTVar1[1].father);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX_IncendieWithPosTask()
 // line 1556, offset 0x80061010
	/* begin block 1 */
		// Start line: 1557
		// Start offset: 0x80061010
		// Variables:
	// 		struct _INCENDIE *Incendie; // $s1
	// 		struct SFX_7fake *pvert_orig; // $s4
	// 		struct _D3_OBJECT *obj; // $s3
	// 		struct TASK *FireTask; // $s6
	// 		long i; // $s0
	// 		long FireSize; // $s2
	// 		long cpt; // $s5
	/* end block 1 */
	// End offset: 0x80061238
	// End Line: 1649

	/* begin block 2 */
		// Start line: 3996
	/* end block 2 */
	// End Line: 3997

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SFX_IncendieWithPosTask(void)

{
  TASK *pTVar1;
  short sVar2;
  TASK *t;
  _func_11 **pp_Var3;
  TASK *pTVar4;
  _func_12 *p_Var5;
  int iVar6;
  int iVar7;
  TASK *obj;
  char pVert;
  bool bVar8;
  
  pTVar1 = TaskCurrent;
  iVar7 = 0x19;
  bVar8 = false;
  obj = TaskCurrent[1].prec;
  TaskCurrent->destructor = SFX_IncendieDestructor;
  t = SFX_StreamSmokyFire((_D3_OBJECT *)obj);
  pVert = (char)(pTVar1[1].next)->prec;
  if (((int)*(short *)((int)&(pTVar1[1].prec)->exec + 2) & 0x8000U) != 0) {
    pVert = pVert + (char)(pTVar1[1].next)->next * '\b';
  }
  *(undefined2 *)&pTVar1[1].sp = 0x1000;
  *(undefined2 *)&pTVar1[1].bprec = 0x1800;
  *(undefined2 *)((int)&pTVar1[1].bprec + 2) = 0x1400;
  *(undefined2 *)&pTVar1[1].bnext = 0x500;
  p_Var5 = (_func_12 *)(&obj->s0)[1];
  pTVar1[1].display = (_func_11 *)obj->s0;
  pTVar1[1].destructor = p_Var5;
  Light_Add((_LIGHT *)&pTVar1[1].father);
  D3_SetCollBits((_D3_OBJECT *)obj,2);
  *(undefined *)((int)&obj[1].father + 1) = 0xf7;
  *(undefined *)&obj->display = 5;
  *(undefined2 *)((int)&obj->event_s3 + 2) = 0;
  *(undefined2 *)((int)&pTVar1[1].destructor + 2) = 0xffff;
  while( true ) {
    sVar2 = D3_UpdateSound((_D3_OBJECT *)pTVar1[1].prec,0x33,
                           *(short *)((int)&pTVar1[1].destructor + 2));
    pTVar4 = pTVar1[1].next;
    *(short *)((int)&pTVar1[1].destructor + 2) = sVar2;
    sVar2 = Tmd_TestEndStretchZ((char)pTVar4,pVert);
    bVar8 = (bool)(bVar8 ^ 1);
    if (sVar2 != 0) break;
    if (bVar8) {
      iVar6 = 4;
      Tmd_StretchZ((char)pTVar1[1].next,pVert,-3);
      pp_Var3 = &obj->display;
      do {
        iVar6 = iVar6 + 1;
        *(short *)(pp_Var3 + 0x14) = *(short *)(pp_Var3 + 0x14) + -3;
        pp_Var3 = pp_Var3 + 2;
      } while (iVar6 < 8);
    }
    Task_Next();
  }
  do {
    iVar6 = 0;
    sVar2 = D3_UpdateSound((_D3_OBJECT *)pTVar1[1].prec,0x33,
                           *(short *)((int)&pTVar1[1].destructor + 2));
    *(short *)((int)&pTVar1[1].destructor + 2) = sVar2;
    *(undefined2 *)((int)&t[1].s7 + 2) = (short)iVar7;
    iVar7 = iVar7 + -2;
    do {
      iVar6 = iVar6 + 1;
      Task_Next();
    } while (iVar6 < 5);
  } while (0 < iVar7);
  if ((pTVar1[1].prec)->bnext != (TASK *)0x0) {
    Task_EventExec(TaskCurrent->father,1,0);
  }
  iVar7 = 0x80;
  *(undefined2 *)((int)&t[1].s7 + 2) = 2;
  *(undefined2 *)&t[1].fp = 0xfffe;
  do {
    iVar7 = iVar7 + -3;
    sVar2 = D3_UpdateSound((_D3_OBJECT *)pTVar1[1].prec,0x33,
                           *(short *)((int)&pTVar1[1].destructor + 2));
    *(short *)((int)&pTVar1[1].destructor + 2) = sVar2;
    Task_Next();
  } while (0 < iVar7);
  if ((pTVar1[1].prec)->bnext == (TASK *)0x0) {
    D3_DeleteObject((_D3_OBJECT *)pTVar1[1].prec);
  }
  Task_Kill(t);
  Task_Sleep(2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ D3_Splash(struct _D3_OBJECT *obj /*$s0*/)
 // line 1664, offset 0x80061270
	/* begin block 1 */
		// Start line: 1665
		// Start offset: 0x80061270
		// Variables:
	// 		struct _SPLASH splash; // stack offset -224
	// 		struct _PLATFORM *p; // $s0
	// 		long i; // $s1
	/* end block 1 */
	// End offset: 0x800612F4
	// End Line: 1684

	/* begin block 2 */
		// Start line: 4236
	/* end block 2 */
	// End Line: 4237

void D3_Splash(_D3_OBJECT *obj)

{
  _PLATFORM *p_Var1;
  char cVar2;
  int iVar3;
  _SPLASH _Stack224;
  
  p_Var1 = Plat_GetPlat((char)obj + ',');
  SplashInit(obj,&_Stack224);
  cVar2 = *(char *)((int)&p_Var1[1].obj.pos.vx + 1);
  if (cVar2 == '\x01') {
    Impact_Circle(0xb0,4);
  }
  else {
    iVar3 = 0;
    if (cVar2 == '\x03') {
      cVar2 = -0x70;
      do {
        Impact_Acid(cVar2 + ' ');
        iVar3 = iVar3 + 1;
        cVar2 = cVar2 + '\b';
      } while (iVar3 < 4);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SplashInit(struct _D3_OBJECT *obj /*$s5*/, struct _SPLASH *splash /*$s0*/)
 // line 1687, offset 0x8006130c
	/* begin block 1 */
		// Start line: 1688
		// Start offset: 0x8006130C
		// Variables:
	// 		struct _PLATFORM *p; // $s4
	// 		long i; // $s2
	/* end block 1 */
	// End offset: 0x80061410
	// End Line: 1701

	/* begin block 2 */
		// Start line: 4288
	/* end block 2 */
	// End Line: 4289

void SplashInit(_D3_OBJECT *obj,_SPLASH *splash)

{
  short sVar1;
  short sVar2;
  _PLATFORM *p_Var3;
  long lVar4;
  _D3_OBJECT *p_Var5;
  int iVar6;
  
  p_Var3 = Plat_GetPlat((char)obj + ',');
  iVar6 = 0;
  p_Var5 = obj;
  do {
    iVar6 = iVar6 + 1;
    lVar4 = M_rand();
    (splash->v).vx =
         (p_Var5->b_box).vx + (obj->pos).vx + (short)lVar4 + (short)(lVar4 / 0x32) * -0x32 + -0x19;
    lVar4 = M_rand();
    (splash->v).vy =
         (p_Var5->b_box).vy + (obj->pos).vy + (short)lVar4 + (short)(lVar4 / 0x32) * -0x32 + -0x19;
    sVar1 = *(short *)&p_Var3[1].obj.prec;
    sVar2 = p_Var3[1].obj.pos.vy;
    p_Var5 = (_D3_OBJECT *)&p_Var5->child;
    (splash->v).pad = 0;
    (splash->v).vz = sVar1 + sVar2;
    splash = (_SPLASH *)&(splash->t).father;
  } while (iVar6 < 4);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX_LightRay(struct SFX_7fake *pos /*$s0*/, long nb /*$s1*/)
 // line 1713, offset 0x80061434
	/* begin block 1 */
		// Start line: 1714
		// Start offset: 0x80061434
		// Variables:
	// 		struct _LIGHTRAY *lr; // $v1
	/* end block 1 */
	// End offset: 0x80061490
	// End Line: 1719

	/* begin block 2 */
		// Start line: 4352
	/* end block 2 */
	// End Line: 4353

void SFX_LightRay(undefined pos,long nb)

{
  TASK *pTVar1;
  undefined3 in_register_00000011;
  TASK *pTVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)nb;
  pTVar1 = Task_Link(SFX_LightRayTask,0x2c0);
  pTVar2 = ((TASK **)CONCAT31(in_register_00000011,pos))[1];
  pTVar1[1].prec = *(TASK **)CONCAT31(in_register_00000011,pos);
  pTVar1[1].next = pTVar2;
  if (10 < nb) {
    uVar3 = 10;
  }
  *(undefined2 *)&pTVar1[2].sp = uVar3;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX_LightRayTask()
 // line 1722, offset 0x800614a8
	/* begin block 1 */
		// Start line: 1723
		// Start offset: 0x800614A8
		// Variables:
	// 		struct _LIGHTRAY *lr; // $s1
	// 		struct _D3_OBJECT *o; // $s4
	// 		struct SFX_7fake *r; // $s3
	// 		struct SFX_7fake *pvert; // $fp
	// 		struct SFX_8fake col; // stack offset -56
	// 		long i; // $s5
	// 		long j; // $s0
	// 		long cont; // $s6
	// 		short *c; // $s7
	// 		short *e; // stack offset -48
	/* end block 1 */
	// End offset: 0x8006173C
	// End Line: 1789

	/* begin block 2 */
		// Start line: 4374
	/* end block 2 */
	// End Line: 4375

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SFX_LightRayTask(void)

{
  char cVar1;
  bool bVar2;
  TASK *pTVar3;
  short *psVar4;
  long lVar5;
  short *psVar6;
  int iVar7;
  short *psVar8;
  long *plVar9;
  int iVar10;
  TASK *pTVar11;
  
  pTVar3 = TaskCurrent;
  pTVar11 = TaskCurrent + 2;
  SFX_LightRayInit((_LIGHTRAY *)TaskCurrent);
  psVar4 = (short *)((int)&pTVar3[2].s1 + 2);
  do {
    plVar9 = (long *)((int)&pTVar3[2].s6 + 2);
    bVar2 = false;
    *(TASK **)&pTVar3[1].s2 = pTVar3[1].prec;
    *(TASK **)&pTVar3[1].s3 = pTVar3[1].next;
    iVar10 = 0;
    psVar6 = (short *)((int)&pTVar11->sp + 2);
    psVar8 = psVar4;
    if (0 < *(short *)&pTVar3[2].sp) {
      do {
        lVar5 = plVar9[1];
        pTVar3[1].s6 = *plVar9;
        pTVar3[1].s7 = lVar5;
        if (*psVar6 < *psVar8) {
          *psVar6 = *psVar6 + 200;
          bVar2 = true;
        }
        if (0 < (int)*psVar6) {
          GtxTmd_ApplyMIMe((uint **)pTVar3[1].s0,(int)*psVar6);
          Main_Prims = D3_DisplayTmd((_D3_OBJECT *)&pTVar3[1].father,Main_Prims,0,(int)Scr_W);
        }
        iVar10 = iVar10 + 1;
        plVar9 = plVar9 + 2;
        psVar6 = psVar6 + 1;
        psVar8 = psVar8 + 1;
      } while (iVar10 < (int)*(short *)&pTVar3[2].sp);
    }
    Task_Next();
  } while (bVar2);
  iVar10 = 0;
  pTVar11 = pTVar3;
  if (0 < *(short *)&pTVar3[2].sp) {
    do {
      *(TASK **)&pTVar3[1].s2 = pTVar3[1].prec;
      *(TASK **)&pTVar3[1].s3 = pTVar3[1].next;
      cVar1 = *(char *)((int)&pTVar11[3].next + 2);
      while (cVar1 != '\0') {
        plVar9 = (long *)((int)&pTVar3[2].s6 + 2);
        iVar7 = 0;
        psVar6 = psVar4;
        if (0 < *(short *)&pTVar3[2].sp) {
          do {
            lVar5 = plVar9[1];
            pTVar3[1].s6 = *plVar9;
            pTVar3[1].s7 = lVar5;
            iVar7 = iVar7 + 1;
            plVar9 = plVar9 + 2;
            Tmd_ChangeColor((char)pTVar3[1].s0,200);
            GtxTmd_ApplyMIMe((uint **)pTVar3[1].s0,(int)*psVar6);
            Main_Prims = D3_DisplayTmd((_D3_OBJECT *)&pTVar3[1].father,Main_Prims,0,(int)Scr_W);
            psVar6 = psVar6 + 1;
          } while (iVar7 < (int)*(short *)&pTVar3[2].sp);
        }
        *(char *)((int)&pTVar11[3].next + 2) = *(char *)((int)&pTVar11[3].next + 2) + -0x1e;
        Task_Next();
        cVar1 = *(char *)((int)&pTVar11[3].next + 2);
      }
      iVar10 = iVar10 + 1;
      pTVar11 = (TASK *)((int)&pTVar11->prec + 1);
    } while (iVar10 < (int)*(short *)&pTVar3[2].sp);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX_LightRayInit(struct _LIGHTRAY *lr /*$s2*/)
 // line 1791, offset 0x8006176c
	/* begin block 1 */
		// Start line: 1792
		// Start offset: 0x8006176C
		// Variables:
	// 		long i; // $s0
	// 		short *c; // $s5
	// 		short *e; // $s4
	// 		unsigned char *g; // $s6
	// 		struct SFX_7fake *r; // $s3
	// 		struct _D3_OBJECT *o; // $s0
	// 		struct SFX_8fake col; // stack offset -40
	/* end block 1 */
	// End offset: 0x80061954
	// End Line: 1831

	/* begin block 2 */
		// Start line: 4599
	/* end block 2 */
	// End Line: 4600

void SFX_LightRayInit(_LIGHTRAY *lr)

{
  ushort uVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  int iVar5;
  short *psVar6;
  short *psVar7;
  short *psVar8;
  short *psVar9;
  
  psVar9 = (short *)(lr->tab_col + 8);
  psVar8 = (short *)((int)&lr[1].t.bprec + 2);
  psVar7 = (short *)((int)&lr[1].t.destructor + 2);
  (lr->obj).display_mode = 0;
  uVar1 = (lr->obj).display_mode;
  (lr->obj).collision_mode = 0;
  *(undefined2 *)((int)&(lr->obj).b_hurt + 2) = 0;
  (lr->obj).display_mode = uVar1 | 0x13;
  (lr->obj).description = (void *)((int)PTR_800b2df4 + 0xc);
  D3_SetBox(&lr->obj,-10,-10,-10,10,10,10);
  Tmd_ChangeColor((char)(lr->obj).description,0xd8);
  iVar5 = 0;
  if (0 < *(short *)(lr->tab_col + 6)) {
    psVar6 = (short *)((int)&lr[1].t.local + 2);
    do {
      lVar3 = M_rand();
      lVar4 = lVar3;
      if (lVar3 < 0) {
        lVar4 = lVar3 + 0xfff;
      }
      *psVar7 = (short)lVar3 + (short)(lVar4 >> 0xc) * -0x1000;
      lVar3 = M_rand();
      lVar4 = lVar3;
      if (lVar3 < 0) {
        lVar4 = lVar3 + 0xfff;
      }
      psVar6[-1] = (short)lVar3 + (short)(lVar4 >> 0xc) * -0x1000;
      lVar3 = M_rand();
      lVar4 = lVar3;
      if (lVar3 < 0) {
        lVar4 = lVar3 + 0xfff;
      }
      *psVar6 = (short)lVar3 + (short)(lVar4 >> 0xc) * -0x1000;
      lVar4 = M_rand();
      *psVar9 = (short)(lVar4 / 10000) * 10000 - (short)lVar4;
      lVar4 = M_rand();
      psVar6 = psVar6 + 4;
      psVar7 = psVar7 + 4;
      iVar2 = iVar5 + 2;
      iVar5 = iVar5 + 1;
      psVar9 = psVar9 + 1;
      *psVar8 = (short)lVar4 + (short)(lVar4 / 0x738) * -0x738 + 200;
      *(undefined *)((int)&lr[1].t.event_s2 + iVar2) = 0x78;
      psVar8 = psVar8 + 1;
    } while (iVar5 < (int)*(short *)(lr->tab_col + 6));
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX_ShockWave(long type /*$s0*/, struct SFX_7fake *pos /*$s1*/, struct SFX_8fake *col /*$s2*/, long flag /*$s3*/)
 // line 1852, offset 0x8006197c
	/* begin block 1 */
		// Start line: 1853
		// Start offset: 0x8006197C
		// Variables:
	// 		struct _SHOCK *sh; // $v0
	/* end block 1 */
	// End offset: 0x8006197C
	// End Line: 1853

	/* begin block 2 */
		// Start line: 4808
	/* end block 2 */
	// End Line: 4809

void SFX_ShockWave(long type,undefined pos,undefined col,long flag)

{
  TASK *pTVar1;
  undefined3 in_register_00000015;
  undefined3 in_register_00000019;
  TASK *pTVar2;
  void *pvVar3;
  _func_13 *p_Var4;
  long lVar5;
  
  pTVar1 = Task_Add(SFX_ShockWaveTask,0x740);
  *(TASK **)&pTVar1->local = pTVar1;
  pTVar2 = ((TASK **)CONCAT31(in_register_00000015,pos))[1];
  pTVar1[1].prec = *(TASK **)CONCAT31(in_register_00000015,pos);
  pTVar1[1].next = pTVar2;
  pTVar1[5].event_msg = *(long *)CONCAT31(in_register_00000019,col);
  pTVar1[5].event_s0 = flag;
  pvVar3 = *(void **)&Tab_Shocks[type].ray1_step;
  p_Var4 = *(_func_13 **)&Tab_Shocks[type].height;
  lVar5 = *(long *)&Tab_Shocks[type].nbseg;
  pTVar1[5].event_param = *(long *)(Tab_Shocks + type);
  pTVar1[5].event_sp = pvVar3;
  pTVar1[5].event_exec = p_Var4;
  pTVar1[5].event_ra = lVar5;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX_ShockWaveTask()
 // line 1867, offset 0x80061a5c
	/* begin block 1 */
		// Start line: 1868
		// Start offset: 0x80061A5C
		// Variables:
	// 		struct _SHOCK *sh; // $s0
	// 		long ray1; // $s3
	// 		long ray2; // $s2
	// 		long cpt; // $s1
	/* end block 1 */
	// End offset: 0x80061B48
	// End Line: 1897

	/* begin block 2 */
		// Start line: 4848
	/* end block 2 */
	// End Line: 4849

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SFX_ShockWaveTask(void)

{
  short sVar1;
  uint uVar2;
  void *pvVar3;
  int iVar4;
  int ray2;
  long ray1;
  
  pvVar3 = TaskCurrent->local;
  ray1 = (long)*(short *)((int)pvVar3 + 0x32c);
  ray2 = (int)*(short *)((int)pvVar3 + 0x32e);
  iVar4 = (int)*(short *)((int)pvVar3 + 0x33a);
  TaskCurrent->display = SFX_ShockSetPrims;
  while (iVar4 = iVar4 + -1, iVar4 != -1) {
    SFX_ShockSetVertices(ray1,ray2);
    uVar2 = *(uint *)((int)pvVar3 + 0x33c);
    if ((uVar2 & 1) != 0) {
      ray1 = ray1 + (int)*(short *)((int)pvVar3 + 0x330);
      ray2 = ray2 + (int)*(short *)((int)pvVar3 + 0x332);
    }
    if ((uVar2 & 2) != 0) {
      if (((uVar2 & 0x10) == 0) ||
         (uVar2 = (uint)*(ushort *)((int)pvVar3 + 0x33a) << 0x10,
         (int)(((int)uVar2 >> 0x10) + (uVar2 >> 0x1f)) >> 1 <= iVar4)) {
        sVar1 = *(short *)((int)pvVar3 + 0x334) + *(short *)((int)pvVar3 + 0x336);
      }
      else {
        sVar1 = *(short *)((int)pvVar3 + 0x334) - *(short *)((int)pvVar3 + 0x336);
      }
      *(short *)((int)pvVar3 + 0x334) = sVar1;
    }
    Task_Next();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX_ShockSetVertices(long ray1 /*stack 0*/, long ray2 /*stack 4*/)
 // line 1900, offset 0x80061b64
	/* begin block 1 */
		// Start line: 1901
		// Start offset: 0x80061B64
		// Variables:
	// 		struct _SHOCK *sh; // $s3
	// 		struct SFX_7fake *vert; // $s0
	// 		struct SFX_7fake *vert2; // $s2
	// 		long i; // $s4
	// 		long h; // $s6
	// 		long nseg; // $s5
	// 		short angleZ; // $fp
	// 		short step; // stack offset -56
	/* end block 1 */
	// End offset: 0x80061D24
	// End Line: 1926

	/* begin block 2 */
		// Start line: 4920
	/* end block 2 */
	// End Line: 4921

/* WARNING: Removing unreachable block (ram,0x80061bd4) */

void SFX_ShockSetVertices(long ray1,long ray2)

{
  ushort uVar1;
  int iVar2;
  long lVar3;
  void *pvVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined2 *puVar7;
  uint uVar8;
  undefined2 *puVar9;
  void *pvVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  short sVar15;
  
  pvVar10 = TaskCurrent->local;
  iVar12 = (int)*(short *)((int)pvVar10 + 0x338);
  if (iVar12 == 0) {
    trap(0x1c00);
  }
  sVar15 = 0;
  uVar1 = *(ushort *)((int)pvVar10 + 0x334);
  iVar11 = 0;
  uVar5 = (uint)uVar1 << 0x10;
  iVar13 = (int)uVar5 >> 0x10;
  if (0 < iVar12) {
    iVar14 = 0x98;
    do {
      uVar8 = SEXT24(sVar15);
      puVar9 = (undefined2 *)((int)pvVar10 + (iVar11 + iVar12) * 8 + 0xa0);
      iVar2 = rcos(uVar8);
      puVar7 = (undefined2 *)((int)pvVar10 + iVar14);
      *puVar7 = (short)(iVar2 * ray1 >> 0xc);
      iVar2 = rsin(uVar8);
      puVar7[2] = 0;
      puVar7[1] = (short)(iVar2 * ray1 >> 0xc);
      iVar2 = rcos(uVar8);
      *puVar9 = (short)(iVar2 * ray2 >> 0xc);
      iVar2 = rsin(uVar8);
      puVar9[1] = (short)(iVar2 * ray2 >> 0xc);
      if ((*(uint *)((int)pvVar10 + 0x33c) & 8) == 0) {
        puVar9[2] = uVar1;
      }
      else {
        lVar3 = M_rand();
        if (iVar13 == 0) {
          trap(0x1c00);
        }
        if ((iVar13 == -1) && (lVar3 == -0x80000000)) {
          trap(0x1800);
        }
        puVar9[2] = (short)(lVar3 % iVar13) + (short)((int)(iVar13 + (uVar5 >> 0x1f)) >> 1);
      }
      iVar14 = iVar14 + 8;
      iVar11 = iVar11 + 1;
      sVar15 = sVar15 + (short)(0x1000 / iVar12);
    } while (iVar11 < iVar12);
  }
  pvVar4 = (void *)((int)pvVar10 + iVar12 * 8);
  iVar11 = (int)pvVar10 + (iVar12 << 4 | 8U);
  uVar6 = *(undefined4 *)((int)pvVar10 + 0x9c);
  *(undefined4 *)((int)pvVar4 + 0x98) = *(undefined4 *)((int)pvVar10 + 0x98);
  *(undefined4 *)((int)pvVar4 + 0x9c) = uVar6;
  pvVar10 = (void *)((int)pvVar10 + (iVar12 + 1) * 8);
  uVar6 = *(undefined4 *)((int)pvVar10 + 0x9c);
  *(undefined4 *)(iVar11 + 0x98) = *(undefined4 *)((int)pvVar10 + 0x98);
  *(undefined4 *)(iVar11 + 0x9c) = uVar6;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX_ShockSetPrims()
 // line 1931, offset 0x80061db4
	/* begin block 1 */
		// Start line: 1932
		// Start offset: 0x80061DB4
		// Variables:
	// 		struct SFX_5fake mr; // stack offset -64
	// 		struct _SHOCK *sh; // $a3
	// 		struct SFX_55fake *dtp; // $s0
	// 		struct SFX_33fake *pg4; // $t1
	// 		struct SFX_8fake col1; // stack offset -32
	// 		struct SFX_8fake col2; // stack offset -24
	// 		long i; // $t0
	// 		long z; // $a1
	// 		long nseg; // $s1
	/* end block 1 */
	// End offset: 0x80062178
	// End Line: 2017

	/* begin block 2 */
		// Start line: 5016
	/* end block 2 */
	// End Line: 5017

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SFX_ShockSetPrims(void)

{
  int iVar1;
  _SCREEN *p_Var2;
  undefined4 in_zero;
  undefined4 in_at;
  uint uVar3;
  _TMD_2D *p_Var4;
  uint uVar5;
  uint *puVar6;
  _TMD_2D *p_Var7;
  int iVar8;
  void *pvVar9;
  int iVar10;
  uint *puVar11;
  int iVar12;
  undefined local_20;
  undefined local_1f;
  undefined local_1e;
  undefined local_18;
  undefined local_17;
  undefined local_16;
  
  pvVar9 = TaskCurrent->local;
  iVar12 = (int)*(short *)((int)pvVar9 + 0x338);
  iVar10 = 0;
  puVar11 = (uint *)Main_Prims;
  if (0 < iVar12) {
    puVar6 = (uint *)((int)Main_Prims + 4);
    puVar11 = (uint *)Main_Prims;
    do {
      if (Main_TextContext.Font.ascii_tab._20_4_ <= (int)puVar11) {
        return;
      }
      *(undefined *)((int)puVar6 + -1) = 1;
      uVar5 = 0xe1000000;
      if (Scr_Dtd != 0) {
        uVar5 = 0xe1000200;
      }
      uVar3 = uVar5 | 0x420;
      if (Scr_Dfe == 0) {
        uVar3 = uVar5 | 0x20;
      }
      *puVar6 = uVar3;
      iVar10 = iVar10 + 1;
      puVar6 = puVar6 + 2;
      puVar11 = puVar11 + 2;
    } while (iVar10 < iVar12);
  }
  if ((*(uint *)((int)pvVar9 + 0x33c) & 4) == 0) {
    local_18 = *(undefined *)((int)pvVar9 + 0x328);
    local_17 = *(undefined *)((int)pvVar9 + 0x329);
    local_16 = *(undefined *)((int)pvVar9 + 0x32a);
    local_20 = 0;
    local_1f = 0;
    local_1e = 0;
  }
  else {
    local_20 = *(undefined *)((int)pvVar9 + 0x328);
    local_1f = *(undefined *)((int)pvVar9 + 0x329);
    local_1e = *(undefined *)((int)pvVar9 + 0x32a);
    local_18 = 0;
    local_17 = 0;
    local_16 = 0;
  }
  setCopReg(2,in_zero,*(undefined4 *)((int)pvVar9 + 0x90));
  setCopReg(2,in_at,*(undefined4 *)((int)pvVar9 + 0x94));
  copFunction(2,0x486012);
  iVar10 = getCopReg(2,0x19);
  iVar8 = getCopReg(2,0x1a);
  iVar1 = getCopReg(2,0x1b);
  setCopControlWord(2,0x2800,iVar10 + Cam_Matrix.t[0]);
  setCopControlWord(2,0x3000,iVar8 + Cam_Matrix.t[1]);
  setCopControlWord(2,0x3800,iVar1 + Cam_Matrix.t[2]);
  GtxTmd_RotTransPersN((int)pvVar9 + 0x98,Tmd_2D,(iVar12 + 1) * 2);
  iVar10 = 0;
  if (0 < iVar12) {
    puVar6 = puVar11 + 8;
    do {
      if (Main_TextContext.Font.ascii_tab._20_4_ <= (int)puVar11) break;
      *(undefined *)((int)puVar6 + -0x1d) = 8;
      *(undefined *)((int)puVar6 + -0x19) = 0x3a;
      *(undefined *)(puVar6 + -7) = local_20;
      *(undefined *)((int)puVar6 + -0x1b) = local_1f;
      *(undefined *)((int)puVar6 + -0x1a) = local_1e;
      *(undefined *)(puVar6 + -5) = local_20;
      *(undefined *)((int)puVar6 + -0x13) = local_1f;
      *(undefined *)((int)puVar6 + -0x12) = local_1e;
      *(undefined *)(puVar6 + -3) = local_18;
      *(undefined *)((int)puVar6 + -0xb) = local_17;
      *(undefined *)((int)puVar6 + -10) = local_16;
      *(undefined *)(puVar6 + -1) = local_18;
      *(undefined *)((int)puVar6 + -3) = local_17;
      *(undefined *)((int)puVar6 + -2) = local_16;
      p_Var7 = Tmd_2D + iVar10;
      iVar8 = (int)((uint)(ushort)p_Var7->vz << 0x10) >> 0x12;
      if ((iVar8 != 0) && (iVar8 < (int)Scr_OtSize)) {
        p_Var4 = Tmd_2D + iVar10 + iVar12;
        puVar6[-6] = *(uint *)(p_Var4 + 1);
        puVar6[-4] = *(uint *)(p_Var4 + 2);
        puVar6[-2] = *(uint *)p_Var7;
        *puVar6 = *(uint *)(p_Var7 + 1);
        p_Var2 = Scr;
        *puVar11 = *puVar11 & 0xff000000 | Scr->ot[iVar8] & 0xffffff;
        p_Var2->ot[iVar8] = p_Var2->ot[iVar8] & 0xff000000 | (uint)puVar11 & 0xffffff;
        *(uint *)Main_Prims = *(uint *)Main_Prims & 0xff000000 | p_Var2->ot[iVar8] & 0xffffff;
        p_Var2->ot[iVar8] = p_Var2->ot[iVar8] & 0xff000000 | (uint)Main_Prims & 0xffffff;
      }
      iVar10 = iVar10 + 1;
      puVar6 = puVar6 + 9;
      puVar11 = puVar11 + 9;
      Main_Prims = (uint *)Main_Prims + 2;
    } while (iVar10 < iVar12);
  }
  setCopControlWord(2,0x2800,Cam_Matrix.t[0]);
  setCopControlWord(2,0x3000,Cam_Matrix.t[1]);
  setCopControlWord(2,0x3800,Cam_Matrix.t[2]);
  Main_Prims = puVar11;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX_Fusion(struct _D3_OBJECT *owner /*$s3*/, struct SFX_7fake *pos /*$s1*/, long power /*$s2*/, long rotz /*$s0*/, long dist /*stack 16*/, long col /*stack 20*/)
 // line 2044, offset 0x8006218c
	/* begin block 1 */
		// Start line: 2045
		// Start offset: 0x8006218C
		// Variables:
	// 		struct _FUSION *f; // $v0
	/* end block 1 */
	// End offset: 0x8006218C
	// End Line: 2045

	/* begin block 2 */
		// Start line: 5285
	/* end block 2 */
	// End Line: 5286

void SFX_Fusion(_D3_OBJECT *owner,undefined pos,long power,long rotz,long dist,long col)

{
  TASK *pTVar1;
  undefined3 in_register_00000015;
  TASK *pTVar2;
  
  pTVar1 = Task_Add(SFX_FusionTask,0x650);
  *(TASK **)&pTVar1->local = pTVar1;
  pTVar2 = ((TASK **)CONCAT31(in_register_00000015,pos))[1];
  pTVar1[1].prec = *(TASK **)CONCAT31(in_register_00000015,pos);
  pTVar1[1].next = pTVar2;
  pTVar1[1].sp = (void *)0x1;
  pTVar1[1].display = (_func_11 *)((int)&DAT_00000008 + 2);
  pTVar1[1].destructor = (_func_12 *)((int)&DAT_00000004 + 1);
  *(undefined4 **)&pTVar1[1].local = &DAT_00000014;
  *(long *)&pTVar1[1].bprec = rotz;
  *(_D3_OBJECT **)&pTVar1[1].father = owner;
  *(long *)&pTVar1[1].child = power;
  pTVar1[1].s0 = 0x32;
  *(long *)&pTVar1[1].bnext = col;
  *(long *)&pTVar1[1].exec = dist;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX_FusionTask()
 // line 2065, offset 0x80062258
	/* begin block 1 */
		// Start line: 2066
		// Start offset: 0x80062258
		// Variables:
	// 		struct _FUSION *f; // $s0
	// 		struct _D3_OBJECT o; // stack offset -184
	// 		long time; // $s1
	/* end block 1 */
	// End offset: 0x800622FC
	// End Line: 2093

	/* begin block 2 */
		// Start line: 5361
	/* end block 2 */
	// End Line: 5362

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SFX_FusionTask(void)

{
  long lVar1;
  uint uVar2;
  void *pvVar3;
  int iVar4;
  _D3_OBJECT _Stack184;
  
  iVar4 = 0;
  pvVar3 = TaskCurrent->local;
  SFX_FusionInit(&_Stack184);
  while (lVar1 = SFX_FusionIsON(), lVar1 != 0) {
    if (iVar4 == 0) {
      uVar2 = *(uint *)((int)pvVar3 + 0xac);
      if ((int)uVar2 < *(int *)((int)pvVar3 + 0xb0)) {
        iVar4 = *(int *)((int)pvVar3 + 0xb4);
        if ((uVar2 & 1) != 0) {
          Fx_Play(0x32,(char)pvVar3 + (char)uVar2 * '\b' + -0x40);
        }
        *(int *)((int)pvVar3 + 0xac) = *(int *)((int)pvVar3 + 0xac) + 1;
      }
    }
    iVar4 = iVar4 + -1;
    SFX_FusionGrow();
    SFX_FusionDisplay(&_Stack184);
    Task_Next();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX_FusionInit(struct _D3_OBJECT *o /*$s7*/)
 // line 2096, offset 0x80062310
	/* begin block 1 */
		// Start line: 2097
		// Start offset: 0x80062310
		// Variables:
	// 		struct _FUSION *f; // $s0
	// 		struct _D3_OBJECT *owner; // $a3
	// 		struct SFX_7fake *p; // $s4
	// 		short *h; // $s5
	// 		long i; // $s3
	// 		long sdist; // $fp
	// 		long dist; // $s2

		/* begin block 1.1 */
			// Start line: 2114
			// Start offset: 0x800623D0
			// Variables:
		// 		struct _D3_OBJECT *o; // $a0
		/* end block 1.1 */
		// End offset: 0x800624D4
		// End Line: 2131
	/* end block 1 */
	// End offset: 0x800624FC
	// End Line: 2137

	/* begin block 2 */
		// Start line: 5427
	/* end block 2 */
	// End Line: 5428

void SFX_FusionInit(_D3_OBJECT *o)

{
  bool bVar1;
  undefined2 uVar2;
  _D3_OBJECT *ot;
  int iVar3;
  long lVar4;
  int iVar5;
  int iVar6;
  void *pvVar7;
  undefined2 *puVar8;
  int iVar9;
  int iVar10;
  short *psVar11;
  undefined2 *puVar12;
  
  pvVar7 = TaskCurrent->local;
  iVar9 = 0;
  psVar11 = (short *)((int)pvVar7 + 0xc0);
  iVar6 = *(int *)((int)pvVar7 + 0xa8);
  iVar3 = *(int *)((int)pvVar7 + 0xb0);
  if (iVar3 == 0) {
    trap(0x1c00);
  }
  if ((iVar3 == -1) && (iVar6 == -0x80000000)) {
    trap(0x1800);
  }
  puVar12 = (undefined2 *)((int)pvVar7 + 0x200);
  lVar4 = Distance2D((int)*(short *)((int)pvVar7 + 0x90),(int)*(short *)((int)pvVar7 + 0x92),
                     (int)*(short *)(*(int *)((int)pvVar7 + 0x98) + 0x2c),
                     (int)*(short *)(*(int *)((int)pvVar7 + 0x98) + 0x2e));
  if (lVar4 < 100) {
    iVar9 = 100;
  }
  iVar10 = 0;
  if (0 < *(int *)((int)pvVar7 + 0xb0)) {
    puVar8 = (undefined2 *)((int)pvVar7 + 0xc4);
    do {
      lVar4 = M_rand();
      iVar5 = rcos((*(int *)((int)pvVar7 + 0xa0) + lVar4 % 200) - 100);
      *psVar11 = *(short *)((int)pvVar7 + 0x90) + (short)(iVar5 * iVar9 >> 0xc);
      lVar4 = M_rand();
      iVar5 = rsin((*(int *)((int)pvVar7 + 0xa0) + lVar4 % 200) - 100);
      puVar8[-1] = *(short *)((int)pvVar7 + 0x92) + (short)(iVar5 * iVar9 >> 0xc);
      uVar2 = *(undefined2 *)((int)pvVar7 + 0x94);
      puVar8[1] = 0;
      *puVar8 = uVar2;
      lVar4 = Boxes_GetHeight((_D3_OBJECT *)0x0,(char)psVar11,0x640);
      ot = Boxes_Object;
      bVar1 = Boxes_Object != (_D3_OBJECT *)0x0;
      *puVar8 = (short)lVar4;
      if ((bVar1) && (((int)ot->collision_mode & 0x8000U) != 0)) {
        lVar4 = Boxes_GetHeight(ot,(char)ot + ',',0x640);
        *puVar8 = (short)lVar4;
      }
      iVar10 = iVar10 + 1;
      puVar8 = puVar8 + 4;
      psVar11 = psVar11 + 4;
      *puVar12 = 0;
      puVar12 = puVar12 + 1;
      iVar9 = iVar9 + iVar6 / iVar3;
    } while (iVar10 < *(int *)((int)pvVar7 + 0xb0));
  }
  o->display_mode = 0x11;
  D3_ClearCollBits(o,0xffff);
  D3_SetCollBits(o,(long)&DAT_00002003);
  D3_SetBox(o,-0x1e,-0x1e,0,0x1e,0x1e,1000);
  *(undefined *)((int)&o[1].pos.vx + 1) = 0xed;
  *(undefined4 *)&o[1].last_pos = *(undefined4 *)((int)pvVar7 + 0x98);
  o->hit_power = *(uchar *)((int)pvVar7 + 0x9c);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SFX_FusionIsON()
 // line 2147, offset 0x80062594
	/* begin block 1 */
		// Start line: 2149
		// Start offset: 0x80062594
		// Variables:
	// 		struct _FUSION *f; // $v0
	// 		struct SFX_7fake *p; // $a0
	// 		long i; // $v1
	/* end block 1 */
	// End offset: 0x800625E4
	// End Line: 2160

	/* begin block 2 */
		// Start line: 5594
	/* end block 2 */
	// End Line: 5595

/* WARNING: Unknown calling convention yet parameter storage is locked */

long SFX_FusionIsON(void)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  
  pvVar1 = TaskCurrent->local;
  iVar2 = 0;
  iVar3 = (int)pvVar1 + 0xc0;
  if (0 < *(int *)((int)pvVar1 + 0xac)) {
    do {
      iVar2 = iVar2 + 1;
      if ((int)*(short *)(iVar3 + 6) < *(int *)((int)pvVar1 + 0xb8)) {
        return 1;
      }
      iVar3 = iVar3 + 8;
    } while (iVar2 < *(int *)((int)pvVar1 + 0xac));
  }
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX_FusionGrow()
 // line 2163, offset 0x800625ec
	/* begin block 1 */
		// Start line: 2165
		// Start offset: 0x800625EC
		// Variables:
	// 		struct _FUSION *f; // $a3
	// 		long i; // $a2
	// 		short *h; // $a1
	/* end block 1 */
	// End offset: 0x8006264C
	// End Line: 2176

	/* begin block 2 */
		// Start line: 5629
	/* end block 2 */
	// End Line: 5630

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SFX_FusionGrow(void)

{
  short *psVar1;
  short *psVar2;
  int iVar3;
  void *pvVar4;
  
  pvVar4 = TaskCurrent->local;
  iVar3 = 0;
  psVar2 = (short *)((int)pvVar4 + 0x200);
  if (0 < *(int *)((int)pvVar4 + 0xac)) {
    psVar1 = (short *)((int)pvVar4 + 0xc6);
    do {
      iVar3 = iVar3 + 1;
      *psVar1 = *psVar1 + 1;
      psVar1 = psVar1 + 4;
      *psVar2 = *psVar2 + *(short *)((int)pvVar4 + 0xbc);
      psVar2 = psVar2 + 1;
    } while (iVar3 < *(int *)((int)pvVar4 + 0xac));
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX_FusionDisplay(struct _D3_OBJECT *o /*$s4*/)
 // line 2179, offset 0x80062654
	/* begin block 1 */
		// Start line: 2180
		// Start offset: 0x80062654
		// Variables:
	// 		struct _FUSION *f; // $s1
	// 		struct SFX_7fake *p; // $s0
	// 		long i; // $s2
	// 		short *h; // $s3
	// 		short grey; // $v1
	/* end block 1 */
	// End offset: 0x80062770
	// End Line: 2205

	/* begin block 2 */
		// Start line: 5672
	/* end block 2 */
	// End Line: 5673

void SFX_FusionDisplay(_D3_OBJECT *o)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  void *pvVar5;
  int iVar6;
  short *psVar7;
  
  pvVar5 = TaskCurrent->local;
  iVar6 = 0;
  puVar4 = (undefined4 *)((int)pvVar5 + 0xc0);
  psVar7 = (short *)((int)pvVar5 + 0x200);
  if (0 < *(int *)((int)pvVar5 + 0xac)) {
    do {
      if ((int)*(short *)((int)puVar4 + 6) < *(int *)((int)pvVar5 + 0xb8)) {
        iVar2 = (int)(((uint)*(ushort *)((int)pvVar5 + 0xb8) - (uint)*(ushort *)((int)puVar4 + 6)) *
                     0x10000) >> 0x10;
        if (iVar2 < 0xb) {
          sVar1 = (short)((iVar2 << 7) / 10);
        }
        else {
          sVar1 = 0x80;
        }
        SFX_FusionDisplayRay((char)puVar4,(int)*psVar7,(int)sVar1);
        uVar3 = puVar4[1];
        *(undefined4 *)&o->pos = *puVar4;
        *(undefined4 *)&(o->pos).vz = uVar3;
        uVar3 = puVar4[1];
        *(undefined4 *)&o->last_pos = *puVar4;
        *(undefined4 *)&(o->last_pos).vz = uVar3;
        Boxes_TestObject(o);
      }
      iVar6 = iVar6 + 1;
      puVar4 = puVar4 + 2;
      psVar7 = psVar7 + 1;
    } while (iVar6 < *(int *)((int)pvVar5 + 0xac));
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX_FusionDisplayRay(struct SFX_7fake *p /*$a0*/, long h /*$a1*/, long grey /*$s2*/)
 // line 2208, offset 0x80062790
	/* begin block 1 */
		// Start line: 2209
		// Start offset: 0x80062790
		// Variables:
	// 		struct SFX_7fake pos[2]; // stack offset -48
	// 		struct SFX_70fake shp; // stack offset -32
	// 		long i; // $s0
	// 		long z; // $s1
	/* end block 1 */
	// End offset: 0x800628A0
	// End Line: 2239

	/* begin block 2 */
		// Start line: 5750
	/* end block 2 */
	// End Line: 5751

/* WARNING: Could not reconcile some variable overlaps */

void SFX_FusionDisplayRay(undefined p,long h,long grey)

{
  long lVar1;
  undefined3 in_register_00000011;
  undefined4 *puVar2;
  int index;
  int z;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  uint local_24;
  
  puVar2 = (undefined4 *)CONCAT31(in_register_00000011,p);
  local_30 = *puVar2;
  local_2c = puVar2[1];
  local_28 = *puVar2;
  local_24._0_2_ = (short)puVar2[1];
  local_24 = puVar2[1] & 0xffff0000 | (uint)(ushort)((short)local_24 + (short)h);
  GtxTmd_RotTransPersN(&local_30,Tmd_2D,2);
  z = (int)((uint)(ushort)Tmd_2D->vz << 0x10) >> 0x12;
  if ((1 < z) && (index = 0, z < (int)Scr_OtSize)) {
    do {
      lVar1 = SFX_FusionSetPolyF4(index,z,grey);
      index = index + 1;
      if (lVar1 == 0) {
        return;
      }
    } while (index < 2);
    index = 2;
    do {
      lVar1 = SFX_FusionSetPolyG4(index,z,grey);
      index = index + 1;
      if (lVar1 == 0) {
        return;
      }
    } while (index < 6);
    SFX_FusionSetPolyFT4(z,grey);
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SFX_FusionSetPolyF4(long index /*$a0*/, long z /*$t2*/, long grey /*$a2*/)
 // line 2241, offset 0x800628b8
	/* begin block 1 */
		// Start line: 2242
		// Start offset: 0x800628B8
		// Variables:
	// 		struct SFX_29fake *pf4; // $t0
	// 		struct SFX_55fake *dtp; // $t1
	// 		long col; // $a2
	// 		short *pOffset; // $a0
	/* end block 1 */
	// End offset: 0x80062AD4
	// End Line: 2283

	/* begin block 2 */
		// Start line: 5830
	/* end block 2 */
	// End Line: 5831

long SFX_FusionSetPolyF4(long index,long z,long grey)

{
  _TMD_2D *p_Var1;
  _SCREEN *p_Var2;
  uint uVar3;
  uint uVar4;
  ulong *puVar5;
  char cVar6;
  uint *puVar7;
  
  cVar6 = ((char)grey + -1) * '\x02';
  if (Main_TextContext.Font.ascii_tab._20_4_ <= (int)Main_Prims) {
    return 0;
  }
  *(undefined *)((int)Main_Prims + 3) = 5;
  *(undefined *)((int)Main_Prims + 7) = 0x2a;
  *(char *)((int)Main_Prims + 4) = cVar6;
  *(char *)((int)Main_Prims + 5) = cVar6;
  *(char *)((int)Main_Prims + 6) = cVar6;
  p_Var1 = Tmd_2D;
  *(undefined4 *)((int)Main_Prims + 8) = *(undefined4 *)(Tmd_2D + 1);
  *(undefined4 *)((int)Main_Prims + 0xc) = *(undefined4 *)(p_Var1 + 1);
  *(undefined4 *)((int)Main_Prims + 0x10) = *(undefined4 *)p_Var1;
  *(undefined4 *)((int)Main_Prims + 0x14) = *(undefined4 *)p_Var1;
  *(short *)((int)Main_Prims + 8) = *(short *)((int)Main_Prims + 8) + (&FusionOffsets)[index * 8];
  *(short *)((int)Main_Prims + 10) = *(short *)((int)Main_Prims + 10) + (&SHORT_800a6e4e)[index * 8]
  ;
  *(short *)((int)Main_Prims + 0xc) =
       *(short *)((int)Main_Prims + 0xc) + (&SHORT_800a6e50)[index * 8];
  *(short *)((int)Main_Prims + 0xe) =
       *(short *)((int)Main_Prims + 0xe) + (&SHORT_800a6e52)[index * 8];
  *(short *)((int)Main_Prims + 0x10) =
       *(short *)((int)Main_Prims + 0x10) + (&SHORT_800a6e54)[index * 8];
  *(short *)((int)Main_Prims + 0x12) =
       *(short *)((int)Main_Prims + 0x12) + (&SHORT_800a6e56)[index * 8];
  *(short *)((int)Main_Prims + 0x14) =
       *(short *)((int)Main_Prims + 0x14) + (&SHORT_800a6e58)[index * 8];
  p_Var2 = Scr;
  *(short *)((int)Main_Prims + 0x16) =
       *(short *)((int)Main_Prims + 0x16) + SHORT_ARRAY_800a6e5a[index * 8];
  *(uint *)Main_Prims = *(uint *)Main_Prims & 0xff000000 | p_Var2->ot[z] & 0xffffff;
  puVar7 = (uint *)((int)Main_Prims + 0x18);
  puVar5 = p_Var2->ot + z;
  *puVar5 = *puVar5 & 0xff000000 | (uint)Main_Prims & 0xffffff;
  *(undefined *)((int)Main_Prims + 0x1b) = 1;
  p_Var2 = Scr;
  uVar4 = 0xe1000000;
  if (Scr_Dtd != 0) {
    uVar4 = 0xe1000200;
  }
  uVar3 = uVar4 | 0x420;
  if (Scr_Dfe == 0) {
    uVar3 = uVar4 | 0x20;
  }
  *(uint *)((int)Main_Prims + 0x1c) = uVar3;
  *puVar7 = *puVar7 & 0xff000000 | p_Var2->ot[z] & 0xffffff;
  puVar5 = p_Var2->ot + z;
  Main_Prims = (void *)((int)Main_Prims + 0x20);
  *puVar5 = *puVar5 & 0xff000000 | (uint)puVar7 & 0xffffff;
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SFX_FusionSetPolyG4(long index /*$a0*/, long z /*$t2*/, long grey /*$a2*/)
 // line 2285, offset 0x80062adc
	/* begin block 1 */
		// Start line: 2286
		// Start offset: 0x80062ADC
		// Variables:
	// 		struct _FUSION *f; // $v0
	// 		struct SFX_33fake *pg4; // $t0
	// 		struct SFX_55fake *dtp; // $t1
	// 		struct SFX_8fake c; // stack offset -8
	// 		short *pOffset; // $a1
	/* end block 1 */
	// End offset: 0x80062E24
	// End Line: 2364

	/* begin block 2 */
		// Start line: 5960
	/* end block 2 */
	// End Line: 5961

/* WARNING: Could not reconcile some variable overlaps */

long SFX_FusionSetPolyG4(long index,long z,long grey)

{
  _TMD_2D *p_Var1;
  _SCREEN *p_Var2;
  long lVar3;
  uint uVar4;
  uint uVar5;
  ulong *puVar6;
  undefined uVar7;
  uint *puVar8;
  undefined4 local_8;
  
  if (grey < 0x80) {
    uVar7 = (undefined)grey;
    local_8 = (uint)CONCAT12(uVar7,CONCAT11(uVar7,uVar7));
  }
  else {
    local_8 = *(uint *)((int)TaskCurrent->local + 0xa4);
  }
  if ((int)Main_Prims < Main_TextContext.Font.ascii_tab._20_4_) {
    *(undefined *)((int)Main_Prims + 3) = 8;
    *(undefined *)((int)Main_Prims + 7) = 0x3a;
    if (index < 4) {
      *(undefined *)((int)Main_Prims + 4) = 0;
      *(undefined *)((int)Main_Prims + 5) = 0;
      *(undefined *)((int)Main_Prims + 6) = 0;
      *(undefined *)((int)Main_Prims + 0xc) = (undefined)local_8;
      *(undefined *)((int)Main_Prims + 0xd) = local_8._1_1_;
      *(undefined *)((int)Main_Prims + 0x14) = 0;
      *(undefined *)((int)Main_Prims + 0x15) = 0;
      *(undefined *)((int)Main_Prims + 0x16) = 0;
      *(undefined *)((int)Main_Prims + 0xe) = local_8._2_1_;
      *(undefined *)((int)Main_Prims + 0x1c) = (undefined)local_8;
      *(undefined *)((int)Main_Prims + 0x1d) = local_8._1_1_;
      *(undefined *)((int)Main_Prims + 0x1e) = local_8._2_1_;
    }
    else {
      *(undefined *)((int)Main_Prims + 4) = (undefined)local_8;
      *(undefined *)((int)Main_Prims + 5) = local_8._1_1_;
      *(undefined *)((int)Main_Prims + 0xc) = 0;
      *(undefined *)((int)Main_Prims + 0xd) = 0;
      *(undefined *)((int)Main_Prims + 0xe) = 0;
      *(undefined *)((int)Main_Prims + 6) = local_8._2_1_;
      *(undefined *)((int)Main_Prims + 0x14) = (undefined)local_8;
      *(undefined *)((int)Main_Prims + 0x15) = local_8._1_1_;
      *(undefined *)((int)Main_Prims + 0x1c) = 0;
      *(undefined *)((int)Main_Prims + 0x1d) = 0;
      *(undefined *)((int)Main_Prims + 0x1e) = 0;
      *(undefined *)((int)Main_Prims + 0x16) = local_8._2_1_;
    }
    p_Var1 = Tmd_2D;
    *(undefined4 *)((int)Main_Prims + 8) = *(undefined4 *)(Tmd_2D + 1);
    *(undefined4 *)((int)Main_Prims + 0x10) = *(undefined4 *)(p_Var1 + 1);
    *(undefined4 *)((int)Main_Prims + 0x18) = *(undefined4 *)p_Var1;
    *(undefined4 *)((int)Main_Prims + 0x20) = *(undefined4 *)p_Var1;
    if (index - 3U < 2) {
      *(undefined4 *)((int)Main_Prims + 0x18) = *(undefined4 *)(p_Var1 + 1);
      *(undefined4 *)((int)Main_Prims + 0x20) = *(undefined4 *)(p_Var1 + 1);
    }
    else {
      *(undefined4 *)((int)Main_Prims + 0x18) = *(undefined4 *)p_Var1;
      *(undefined4 *)((int)Main_Prims + 0x20) = *(undefined4 *)p_Var1;
    }
    *(short *)((int)Main_Prims + 8) = *(short *)((int)Main_Prims + 8) + (&FusionOffsets)[index * 8];
    *(short *)((int)Main_Prims + 10) =
         *(short *)((int)Main_Prims + 10) + (&SHORT_800a6e4e)[index * 8];
    *(short *)((int)Main_Prims + 0x10) =
         *(short *)((int)Main_Prims + 0x10) + (&SHORT_800a6e50)[index * 8];
    *(short *)((int)Main_Prims + 0x12) =
         *(short *)((int)Main_Prims + 0x12) + (&SHORT_800a6e52)[index * 8];
    *(short *)((int)Main_Prims + 0x18) =
         *(short *)((int)Main_Prims + 0x18) + (&SHORT_800a6e54)[index * 8];
    *(short *)((int)Main_Prims + 0x1a) =
         *(short *)((int)Main_Prims + 0x1a) + (&SHORT_800a6e56)[index * 8];
    p_Var2 = Scr;
    *(short *)((int)Main_Prims + 0x20) =
         *(short *)((int)Main_Prims + 0x20) + (&SHORT_800a6e58)[index * 8];
    *(short *)((int)Main_Prims + 0x22) =
         *(short *)((int)Main_Prims + 0x22) + SHORT_ARRAY_800a6e5a[index * 8];
    *(uint *)Main_Prims = *(uint *)Main_Prims & 0xff000000 | p_Var2->ot[z] & 0xffffff;
    puVar8 = (uint *)((int)Main_Prims + 0x24);
    puVar6 = p_Var2->ot + z;
    *puVar6 = *puVar6 & 0xff000000 | (uint)Main_Prims & 0xffffff;
    *(undefined *)((int)Main_Prims + 0x27) = 1;
    p_Var2 = Scr;
    uVar5 = 0xe1000000;
    if (Scr_Dtd != 0) {
      uVar5 = 0xe1000200;
    }
    uVar4 = uVar5 | 0x420;
    if (Scr_Dfe == 0) {
      uVar4 = uVar5 | 0x20;
    }
    *(uint *)((int)Main_Prims + 0x28) = uVar4;
    lVar3 = 1;
    *puVar8 = *puVar8 & 0xff000000 | p_Var2->ot[z] & 0xffffff;
    puVar6 = p_Var2->ot + z;
    Main_Prims = (void *)((int)Main_Prims + 0x2c);
    *puVar6 = *puVar6 & 0xff000000 | (uint)puVar8 & 0xffffff;
  }
  else {
    lVar3 = 0;
  }
  return lVar3;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX_FusionSetPolyFT4(long z /*$s1*/, long grey /*$s2*/)
 // line 2366, offset 0x80062e2c
	/* begin block 1 */
		// Start line: 2367
		// Start offset: 0x80062E2C
		// Variables:
	// 		struct SFX_70fake shp; // stack offset -32
	// 		struct SFX_31fake *pft4; // $s0
	/* end block 1 */
	// End offset: 0x80062E2C
	// End Line: 2367

	/* begin block 2 */
		// Start line: 6169
	/* end block 2 */
	// End Line: 6170

void SFX_FusionSetPolyFT4(long z,long grey)

{
  void *pvVar1;
  _SCREEN *p_Var2;
  undefined uVar3;
  SHAPE_68fake local_20;
  
  pvVar1 = Main_Prims;
  local_20.shape = 0xe6;
  local_20.file = Effects_Pcl;
  local_20.x = Tmd_2D->vx + -0xf;
  local_20.y = Tmd_2D->vy + -5;
  Shp_SetPolyFT4((SHAPE_31fake *)Main_Prims,&local_20,0x1e,10);
  uVar3 = (undefined)grey;
  *(undefined *)((int)pvVar1 + 4) = uVar3;
  *(undefined *)((int)pvVar1 + 5) = uVar3;
  *(undefined *)((int)pvVar1 + 6) = uVar3;
  *(byte *)((int)pvVar1 + 7) = *(byte *)((int)pvVar1 + 7) & 0xfe;
  p_Var2 = Scr;
  *(uint *)pvVar1 = *(uint *)pvVar1 & 0xff000000 | Scr->ot[z] & 0xffffff;
  Main_Prims = (void *)((int)pvVar1 + 0x28);
  p_Var2->ot[z] = p_Var2->ot[z] & 0xff000000 | (uint)pvVar1 & 0xffffff;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX_Magic(struct SFX_7fake *pos /*$s0*/, struct SFX_8fake *col /*$s2*/, long nb_part /*$s1*/)
 // line 2427, offset 0x80062f24
	/* begin block 1 */
		// Start line: 2428
		// Start offset: 0x80062F24
		// Variables:
	// 		struct _MAGIC *f; // $v1
	/* end block 1 */
	// End offset: 0x80062FAC
	// End Line: 2439

	/* begin block 2 */
		// Start line: 6321
	/* end block 2 */
	// End Line: 6322

void SFX_Magic(undefined pos,undefined col,long nb_part)

{
  TASK *pTVar1;
  undefined3 in_register_00000011;
  undefined3 in_register_00000015;
  TASK *pTVar2;
  
  pTVar1 = Task_Add(SFX_MagicTask,0x8a8);
  *(TASK **)&pTVar1->local = pTVar1;
  pTVar2 = ((TASK **)CONCAT31(in_register_00000011,pos))[1];
  pTVar1[1].prec = *(TASK **)CONCAT31(in_register_00000011,pos);
  pTVar1[1].next = pTVar2;
  *(undefined2 *)&pTVar1[1].bnext = 300;
  *(undefined2 *)((int)&pTVar1[1].bnext + 2) = 100;
  *(undefined2 *)((int)&pTVar1[1].exec + 2) = 0x14;
  if (nb_part < 0x33) {
    *(short *)&pTVar1[1].exec = (short)nb_part;
  }
  else {
    *(undefined2 *)&pTVar1[1].exec = 0x32;
  }
  *(undefined2 *)&pTVar1[1].sp = 1;
  pTVar1[1].bprec = *(TASK **)CONCAT31(in_register_00000015,col);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX_MagicTask()
 // line 2444, offset 0x80062fe0
	/* begin block 1 */
		// Start line: 2445
		// Start offset: 0x80062FE0
		// Variables:
	// 		struct _MAGIC *f; // $s0
	// 		long duration; // $s1
	/* end block 1 */
	// End offset: 0x80063094
	// End Line: 2479

	/* begin block 2 */
		// Start line: 6362
	/* end block 2 */
	// End Line: 6363

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SFX_MagicTask(void)

{
  short sVar1;
  _MAGIC *f;
  int iVar2;
  
  f = (_MAGIC *)TaskCurrent->local;
  iVar2 = (int)f->life;
  SFX_MagicInit(f);
  while (iVar2 = iVar2 + -1, iVar2 != -1) {
    SFX_MagicMove(f,1);
    SFX_MagicDisplay(f);
    if (0x95 < f->stepz) break;
    sVar1 = (f->rot).vz;
    f->stepz = f->stepz + 3;
    (f->rot).vz = sVar1 + 100;
    Task_Next();
  }
  iVar2 = 0x1d;
  do {
    SFX_MagicMove(f,0);
    SFX_MagicDisplay(f);
    iVar2 = iVar2 + -1;
    Task_Next();
  } while (iVar2 != -1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX_MagicInit(struct _MAGIC *f /*$s2*/)
 // line 2481, offset 0x800630ac
	/* begin block 1 */
		// Start line: 2482
		// Start offset: 0x800630AC
		// Variables:
	// 		long i; // $s3
	// 		struct SFX_71fake *l; // $v0
	// 		struct SFX_7fake *p; // $s5
	// 		struct SFX_7fake *s; // $s7
	// 		struct SFX_8fake *c; // $s4
	/* end block 1 */
	// End offset: 0x80063280
	// End Line: 2510

	/* begin block 2 */
		// Start line: 6449
	/* end block 2 */
	// End Line: 6450

void SFX_MagicInit(_MAGIC *f)

{
  short sVar1;
  long lVar2;
  int iVar3;
  short *psVar4;
  short *psVar5;
  int iVar6;
  _struct_7589 *p_Var7;
  _struct_7590 *p_Var8;
  _struct_7587 *p_Var9;
  
  p_Var8 = &f->pos;
  p_Var7 = (_struct_7589 *)&f[4].task.event_s1;
  f[5].task.event_sp = Effects_Pcl;
  f[5].task.event_ra = 0;
  *(_struct_7590 **)&f[5].task.event_exec = p_Var8;
  *(_struct_7589 **)&f[5].task.event_ra = p_Var7;
  p_Var9 = &f[2].p;
  *(short *)&f[5].task.event_s0 = f->n;
  sVar1 = f->n;
  iVar6 = 0;
  (f->rot).vx = 0;
  (f->rot).vy = 0;
  (f->rot).vz = 0;
  if (0 < sVar1) {
    psVar5 = &f[2].p.pad;
    psVar4 = &(f->pos).pad;
    do {
      p_Var8->vx = 0;
      psVar4[-2] = 0;
      lVar2 = M_rand();
      iVar3 = (int)f->stepz;
      if (iVar3 == 0) {
        trap(0x1c00);
      }
      if ((iVar3 == -1) && (lVar2 == -0x80000000)) {
        trap(0x1800);
      }
      *psVar4 = -0x19fc;
      psVar4[-1] = (short)(lVar2 % iVar3);
      lVar2 = M_rand();
      p_Var9->vx = (short)lVar2 + (short)(lVar2 / 10) * -10 + -5;
      lVar2 = M_rand();
      psVar5[-2] = (short)lVar2 + (short)(lVar2 / 10) * -10 + -5;
      lVar2 = M_rand();
      psVar5[-1] = (short)lVar2 + (short)(lVar2 / 10) * -10 + -5;
      lVar2 = M_rand();
      iVar3 = (int)f->limit;
      if (iVar3 == 0) {
        trap(0x1c00);
      }
      if ((iVar3 == -1) && (lVar2 == -0x80000000)) {
        trap(0x1800);
      }
      iVar6 = iVar6 + 1;
      p_Var8 = p_Var8 + 1;
      psVar4 = psVar4 + 4;
      p_Var9 = p_Var9 + 1;
      *psVar5 = (short)(lVar2 % iVar3);
      *p_Var7 = f->c;
      p_Var7 = p_Var7 + 1;
      psVar5 = psVar5 + 4;
    } while (iVar6 < (int)f->n);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX_MagicMove(struct _MAGIC *f /*$s5*/, long mode /*stack 4*/)
 // line 2512, offset 0x800632ac
	/* begin block 1 */
		// Start line: 2513
		// Start offset: 0x800632AC
		// Variables:
	// 		long i; // $s6
	// 		struct SFX_7fake *p; // $s4
	// 		struct SFX_7fake *s; // $s7
	// 		struct SFX_8fake *c; // $s3
	/* end block 1 */
	// End offset: 0x80063504
	// End Line: 2544

	/* begin block 2 */
		// Start line: 6551
	/* end block 2 */
	// End Line: 6552

void SFX_MagicMove(_MAGIC *f,long mode)

{
  long lVar1;
  int iVar2;
  short *psVar3;
  short *psVar4;
  byte *pbVar5;
  _struct_7589 *p_Var6;
  _struct_7590 *p_Var7;
  int iVar8;
  _struct_7587 *p_Var9;
  
  p_Var7 = &f->pos;
  p_Var9 = &f[2].p;
  p_Var6 = (_struct_7589 *)&f[4].task.event_s1;
  iVar8 = 0;
  if (0 < f->n) {
    pbVar5 = (byte *)((int)&f[4].task.event_s1 + 2);
    psVar4 = &f[2].p.pad;
    psVar3 = &(f->pos).vz;
    do {
      if ((*psVar4 == 0) && (mode != 0)) {
        lVar1 = M_rand();
        p_Var7->vx = (short)lVar1 + (short)(lVar1 / 0x1e) * -0x1e + -0xf;
        lVar1 = M_rand();
        psVar3[-1] = (short)lVar1 + (short)(lVar1 / 0x1e) * -0x1e + -0xf;
        lVar1 = M_rand();
        iVar2 = (int)f->stepz;
        if (iVar2 == 0) {
          trap(0x1c00);
        }
        if ((iVar2 == -1) && (lVar1 == -0x80000000)) {
          trap(0x1800);
        }
        *psVar3 = (short)(lVar1 % iVar2);
        *p_Var6 = f->c;
        lVar1 = M_rand();
        iVar2 = (int)f->limit;
        if (iVar2 == 0) {
          trap(0x1c00);
        }
        if ((iVar2 == -1) && (lVar1 == -0x80000000)) {
          trap(0x1800);
        }
        *psVar4 = (short)(lVar1 % iVar2);
      }
      else {
        p_Var7->vx = p_Var7->vx + p_Var9->vx;
        psVar3[-1] = psVar3[-1] + psVar4[-2];
        *psVar3 = *psVar3 + psVar4[-1];
        p_Var6->r = p_Var6->r - p_Var6->r / 10;
        pbVar5[-1] = pbVar5[-1] - pbVar5[-1] / 10;
        *pbVar5 = *pbVar5 - *pbVar5 / 10;
        *psVar4 = *psVar4 + -1;
      }
      iVar8 = iVar8 + 1;
      psVar3 = psVar3 + 4;
      p_Var7 = p_Var7 + 1;
      psVar4 = psVar4 + 4;
      p_Var9 = p_Var9 + 1;
      pbVar5 = pbVar5 + 4;
      p_Var6 = p_Var6 + 1;
    } while (iVar8 < (int)f->n);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX_MagicDisplay(struct _MAGIC *f /*$a0*/)
 // line 2546, offset 0x80063534
	/* begin block 1 */
		// Start line: 2547
		// Start offset: 0x80063534
		// Variables:
	// 		struct SFX_5fake mr; // stack offset -48
	// 		struct SFX_71fake *l; // $s2
	/* end block 1 */
	// End offset: 0x80063534
	// End Line: 2547

	/* begin block 2 */
		// Start line: 6649
	/* end block 2 */
	// End Line: 6650

void SFX_MagicDisplay(_MAGIC *f)

{
  undefined4 in_zero;
  undefined4 in_at;
  ushort auStack48 [10];
  int local_1c;
  int local_18;
  int local_14;
  
  setCopReg(2,in_zero,*(undefined4 *)&f->p);
  setCopReg(2,in_at,*(undefined4 *)&(f->p).vz);
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
  RotMatrixZYX((short *)&f->rot,auStack48);
  SetMulMatrix((undefined4 *)&Cam_Matrix,auStack48);
  Main_Prims = (void *)GtxShp_DisplayListLOFF
                                 (&f[5].task.event_sp,Main_Prims,Scr->ot,(int)Scr_OtSize,0,
                                  Main_TextContext.Font.ascii_tab._20_4_);
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
// void /*$ra*/ SFX_D3ShakeScreen(struct _D3_OBJECT *o1 /*$a0*/, struct _D3_OBJECT *o2 /*$a1*/, long time /*$s1*/, long amplitude /*$s0*/)
 // line 2581, offset 0x80063688
	/* begin block 1 */
		// Start line: 2582
		// Start offset: 0x80063688
		// Variables:
	// 		long dist; // $v1
	/* end block 1 */
	// End offset: 0x8006371C
	// End Line: 2598

	/* begin block 2 */
		// Start line: 6728
	/* end block 2 */
	// End Line: 6729

void SFX_D3ShakeScreen(_D3_OBJECT *o1,_D3_OBJECT *o2,long time,long amplitude)

{
  long lVar1;
  TASK *pTVar2;
  
  lVar1 = Distance3D((int)(o1->pos).vx,(int)(o1->pos).vy,(int)(o1->pos).vz,(int)(o2->pos).vx,
                     (int)(o2->pos).vy,(int)(o2->pos).vz);
  if (lVar1 < 0x3e9) {
    if (600 < lVar1) {
      amplitude = amplitude >> 1;
    }
    if (SFX_ShakeHandle != (TASK *)0x0) {
      Task_Kill(SFX_ShakeHandle);
    }
    pTVar2 = Task_Add(SFX_ShakeScreenTask,0x80);
    SFX_ShakeHandle = pTVar2;
    pTVar2->s0 = time;
    pTVar2->s1 = amplitude;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX_ShakeScreen(long time /*$s0*/, long amplitude /*$s1*/)
 // line 2600, offset 0x80063730
	/* begin block 1 */
		// Start line: 6766
	/* end block 1 */
	// End Line: 6767

void SFX_ShakeScreen(long time,long amplitude)

{
  if (SFX_ShakeHandle != (TASK *)0x0) {
    Task_Kill(SFX_ShakeHandle);
  }
  SFX_ShakeHandle = Task_Add(SFX_ShakeScreenTask,0x80);
  SFX_ShakeHandle->s0 = time;
  SFX_ShakeHandle->s1 = amplitude;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX_ShakeScreenTask()
 // line 2611, offset 0x80063788
	/* begin block 1 */
		// Start line: 2612
		// Start offset: 0x80063788
		// Variables:
	// 		long i; // $s1
	// 		long time; // $v0
	// 		long quake; // $s0
	/* end block 1 */
	// End offset: 0x8006382C
	// End Line: 2637

	/* begin block 2 */
		// Start line: 6791
	/* end block 2 */
	// End Line: 6792

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SFX_ShakeScreenTask(void)

{
  TASK *pTVar1;
  int iVar2;
  int iVar3;
  
  pTVar1 = TaskCurrent;
  iVar3 = TaskCurrent->s1;
  TaskCurrent->destructor = SFX_ShakeScreenDestructor;
  iVar2 = pTVar1->s0;
  SFX_ScrY = (long)Screens.disp.screen.y;
  LONG_800b2ddc = (long)_SCREEN_800b993c.disp.screen.y;
  while (iVar2 != 0) {
    Screens.disp.screen.y = (short)SFX_ScrY + (short)iVar3;
    _SCREEN_800b993c.disp.screen.y = (short)LONG_800b2ddc + (short)iVar3;
    if (iVar3 != 0) {
      if (0 < iVar3) {
        iVar3 = iVar3 + -1;
      }
      if (iVar3 < 0) {
        iVar3 = iVar3 + 1;
      }
      iVar3 = -iVar3;
    }
    iVar2 = iVar2 + -1;
    Task_Next();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX_ShakeScreenDestructor(struct TASK *handle /*$a0*/)
 // line 2640, offset 0x80063840
	/* begin block 1 */
		// Start line: 6878
	/* end block 1 */
	// End Line: 6879

void SFX_ShakeScreenDestructor(TASK *handle)

{
  SFX_ShakeHandle = (TASK *)0x0;
  Screens.disp.screen.y = (short)SFX_ScrY;
  _SCREEN_800b993c.disp.screen.y = (short)LONG_800b2ddc;
  return;
}



// decompiled code
// original method signature: 
// struct TASK * /*$ra*/ SFX_Stream(struct SFX_7fake *pos /*$s0*/, struct SFX_7fake *rot /*$s1*/, struct SFX_7fake *trans /*$s2*/, long num_shp /*$s5*/, long nb /*stack 16*/, struct _SPEED_RAND *speed /*stack 20*/, long size /*stack 24*/, long size_step /*stack 28*/, struct _INTPL_COLOR *col /*stack 32*/, int flags /*stack 36*/)
 // line 2654, offset 0x80063864
	/* begin block 1 */
		// Start line: 2655
		// Start offset: 0x80063864
		// Variables:
	// 		struct _STREAM_FT4 *sf; // $a0
	/* end block 1 */
	// End offset: 0x80063910
	// End Line: 2679

	/* begin block 2 */
		// Start line: 6906
	/* end block 2 */
	// End Line: 6907

TASK * SFX_Stream(undefined pos,undefined rot,undefined trans,long num_shp,long nb,
                 _SPEED_RAND *speed,long size,long size_step,_INTPL_COLOR *col,int flags)

{
  undefined2 uVar1;
  TASK *pTVar2;
  undefined2 uVar3;
  undefined3 in_register_00000011;
  undefined3 in_register_00000015;
  undefined3 in_register_00000019;
  undefined2 *puVar4;
  void *pvVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  
  puVar4 = (undefined2 *)CONCAT31(in_register_00000019,trans);
  pTVar2 = Task_Link(SFX_StreamTask,0x650);
  pTVar2[1].bprec = (TASK *)CONCAT31(in_register_00000011,pos);
  pTVar2[1].bnext = (TASK *)CONCAT31(in_register_00000015,rot);
  if (puVar4 == (undefined2 *)0x0) {
    *(undefined2 *)&pTVar2[1].exec = 0;
    *(undefined2 *)((int)&pTVar2[1].exec + 2) = 0;
    *(undefined2 *)&pTVar2[1].sp = 0;
  }
  else {
    *(undefined2 *)&pTVar2[1].exec = *puVar4;
    *(undefined2 *)((int)&pTVar2[1].exec + 2) = puVar4[1];
    *(undefined2 *)&pTVar2[1].sp = puVar4[2];
  }
  uVar1 = *(undefined2 *)&(col->col1).pad;
  uVar3 = (undefined2)nb;
  *(undefined2 *)&pTVar2[1].s7 = (undefined2)flags;
  *(short *)&pTVar2[1].display = (short)num_shp;
  *(undefined2 *)((int)&pTVar2[1].sp + 2) = uVar1;
  if (100 < nb) {
    uVar3 = 100;
  }
  *(undefined2 *)((int)&pTVar2[1].display + 2) = uVar3;
  pvVar5 = *(void **)&speed->vz;
  lVar6 = *(long *)&speed->randy;
  pTVar2[1].destructor = *(_func_12 **)speed;
  pTVar2[1].local = pvVar5;
  pTVar2[1].s0 = lVar6;
  *(undefined2 *)((int)&pTVar2[1].s7 + 2) = (short)size;
  *(short *)&pTVar2[1].fp = (short)size_step;
  lVar6 = (col->col1).vy;
  lVar7 = (col->col1).vz;
  lVar8 = (col->col1).pad;
  pTVar2[1].s1 = (col->col1).vx;
  pTVar2[1].s2 = lVar6;
  pTVar2[1].s3 = lVar7;
  pTVar2[1].s4 = lVar8;
  *(_struct_560 *)&pTVar2[1].s5 = col->col2;
  *(short *)&pTVar2[1].s6 = col->nbf;
  return pTVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX_StreamDisplay()
 // line 2694, offset 0x800639c8
	/* begin block 1 */
		// Start line: 2695
		// Start offset: 0x800639C8
		// Variables:
	// 		struct _STREAM_FT4 *sf; // $a0
	/* end block 1 */
	// End offset: 0x800639C8
	// End Line: 2695

	/* begin block 2 */
		// Start line: 7008
	/* end block 2 */
	// End Line: 7009

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SFX_StreamDisplay(void)

{
  Main_Prims = (void *)GtxShp_DisplayListLOFF
                                 (TaskCurrent + 1,Main_Prims,Scr->ot,(int)Scr_OtSize,0,
                                  Main_TextContext.Font.ascii_tab._20_4_);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX_StreamTask()
 // line 2705, offset 0x80063a20
	/* begin block 1 */
		// Start line: 2706
		// Start offset: 0x80063A20
		// Variables:
	// 		struct _STREAM_FT4 *sf; // $s0
	// 		struct SFX_6fake s; // stack offset -64
	// 		long i; // $s2
	// 		long size; // $a1
	// 		long timer; // $s6
	// 		long delai; // stack offset -48
	// 		short *coef; // $s5
	// 		struct SFX_7fake *p; // $s4
	// 		struct SFX_7fake *v; // $fp
	// 		struct SFX_8fake *c; // $s7
	/* end block 1 */
	// End offset: 0x80063D74
	// End Line: 2826

	/* begin block 2 */
		// Start line: 7042
	/* end block 2 */
	// End Line: 7043

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SFX_StreamTask(void)

{
  bool bVar1;
  undefined4 uVar2;
  TASK *pTVar3;
  int index;
  int iVar4;
  undefined4 in_t1;
  undefined4 in_t2;
  undefined4 in_t3;
  long *plVar5;
  long index_00;
  short *psVar6;
  short *psVar7;
  ushort *puVar8;
  int iVar9;
  undefined4 *puVar10;
  short *psVar11;
  int local_30;
  
  pTVar3 = TaskCurrent;
  iVar9 = 0;
  TaskCurrent->display = SFX_StreamDisplay;
  SFX_StreamInit();
  local_30 = (int)*(short *)((int)&pTVar3[1].sp + 2);
  do {
    psVar11 = (short *)((int)&pTVar3[2].event_s6 + 2);
    puVar8 = (ushort *)((int)&pTVar3[1].fp + 2);
    index_00 = 0;
    SetFarColor((uint)*(byte *)&pTVar3[1].s5,(uint)*(byte *)((int)&pTVar3[1].s5 + 1),
                (uint)*(byte *)((int)&pTVar3[1].s5 + 2));
    psVar7 = (short *)pTVar3[8].s7;
    puVar10 = (undefined4 *)pTVar3[8].fp;
    if (0 < *(short *)&pTVar3[1].child) {
      plVar5 = &pTVar3[2].event_fp;
      psVar6 = psVar7 + 2;
      do {
        *psVar7 = *psVar7 + *psVar11;
        psVar6[-1] = psVar6[-1] + *(short *)(plVar5 + -1);
        *psVar6 = *psVar6 + *(short *)((int)plVar5 + -2);
        if ((*(ushort *)&pTVar3[1].s7 & 0x400) != 0) {
          *(short *)((int)plVar5 + -2) = *(short *)((int)plVar5 + -2) + -2;
        }
        if ((*(ushort *)&pTVar3[1].s7 & 0x800) != 0) {
          *(short *)((int)plVar5 + -2) = *(short *)((int)plVar5 + -2) + -4;
        }
        *(short *)plVar5 = *(short *)plVar5 + 1;
        setCopReg(2,in_t1,pTVar3[1].s1);
        setCopReg(2,in_t2,pTVar3[1].s2);
        setCopReg(2,in_t3,pTVar3[1].s3);
        setCopReg(2,0x4000,0x1000 - (int)(short)*puVar8);
        copFunction(2,0x980011);
        uVar2 = getCopReg(2,0x16);
        *puVar10 = uVar2;
        index = ((uint)(ushort)psVar6[1] & 0xff) + (int)*(short *)&pTVar3[1].fp;
        if ((0 < index) && ((*(ushort *)&pTVar3[1].s7 & 4) == 0)) {
          psVar6[1] = psVar6[1] + *(short *)&pTVar3[1].fp;
        }
        if ((*(ushort *)&pTVar3[1].s7 & 0x80) == 0) {
          if ((*(ushort *)&pTVar3[1].s7 & 0x40) == 0) {
            iVar4 = (uint)*puVar8 - (uint)*(ushort *)((int)&pTVar3[1].s6 + 2);
            *puVar8 = (ushort)iVar4;
            if ((iVar4 * 0x10000 < 1) || (index < 0)) goto LAB_80063c30;
          }
          else {
            if ((*(short *)&pTVar3[1].s6 <= *(short *)plVar5) && (iVar9 == 0)) {
LAB_80063c30:
              SFX_StreamCreate(index_00);
            }
          }
        }
        else {
          if (*(short *)&pTVar3[1].sp <= *psVar6) goto LAB_80063c30;
        }
        index_00 = index_00 + 1;
        psVar6 = psVar6 + 4;
        psVar7 = psVar7 + 4;
        plVar5 = plVar5 + 2;
        psVar11 = psVar11 + 4;
        puVar10 = puVar10 + 1;
        puVar8 = puVar8 + 1;
      } while (index_00 < (int)*(short *)&pTVar3[1].child);
    }
    index = (int)*(short *)&pTVar3[1].child;
    iVar4 = (int)*(short *)((int)&pTVar3[1].display + 2);
    if ((index < iVar4) && (iVar9 == 0)) {
      if ((*(ushort *)&pTVar3[1].s7 & 8) == 0) {
        SFX_StreamCreate(index);
        *(short *)&pTVar3[1].child = *(short *)&pTVar3[1].child + 1;
      }
      else {
        if ((index <= iVar4 - (int)*(short *)&pTVar3[1].s6) &&
           (index = 0, 0 < (int)*(short *)&pTVar3[1].s6)) {
          do {
            index = index + 1;
            SFX_StreamCreate((int)*(short *)&pTVar3[1].child);
            *(short *)&pTVar3[1].child = *(short *)&pTVar3[1].child + 1;
          } while (index < (int)*(short *)&pTVar3[1].s6);
        }
      }
    }
    SetFarColor((uint)(Pvl_File->fog).r,(uint)(Pvl_File->fog).g,(uint)(Pvl_File->fog).b);
    if (((*(ushort *)&pTVar3[1].s7 & 0x200) != 0) && (bVar1 = iVar9 == 0, iVar9 = iVar9 + -1, bVar1)
       ) {
      iVar9 = local_30;
    }
    if (((*(ushort *)&pTVar3[1].s7 & 0x100) != 0) &&
       (bVar1 = local_30 == 0, local_30 = local_30 + -1, bVar1)) {
      return;
    }
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX_StreamInit()
 // line 2828, offset 0x80063da4
	/* begin block 1 */
		// Start line: 2829
		// Start offset: 0x80063DA4
		// Variables:
	// 		struct _STREAM_FT4 *sf; // $s0
	/* end block 1 */
	// End offset: 0x80063E10
	// End Line: 2839

	/* begin block 2 */
		// Start line: 7374
	/* end block 2 */
	// End Line: 7375

/* WARNING: Removing unreachable block (ram,0x80063e00) */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void SFX_StreamInit(void)

{
  TASK *pTVar1;
  void *pvVar2;
  TASK *pTVar3;
  
  pTVar1 = TaskCurrent;
  if ((*(ushort *)&TaskCurrent[1].s7 & 0x40) == 0) {
    if ((int)*(short *)&TaskCurrent[1].s6 == 0) {
      trap(0x1c00);
    }
    *(undefined2 *)((int)&TaskCurrent[1].s6 + 2) =
         (short)(0x1000 / (int)*(short *)&TaskCurrent[1].s6);
  }
  else {
    *(undefined2 *)((int)&TaskCurrent[1].s6 + 2) = 0;
  }
  pvVar2 = Effects_Pcl;
  pTVar1[1].father = (TASK *)0x0;
  *(undefined2 *)&pTVar1[1].child = 0;
  pTVar1[1].prec = pvVar2;
  pvVar2 = Heap_AllocMem(800);
  *(void **)&pTVar1[8].s7 = pvVar2;
  pvVar2 = Heap_AllocMem(400);
  *(void **)&pTVar1[8].fp = pvVar2;
  pTVar3 = (TASK *)pTVar1[8].fp;
  pTVar1[1].next = (TASK *)pTVar1[8].s7;
  pTVar1[1].father = pTVar3;
  TaskCurrent->destructor = SFX_StreamDestructor;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX_StreamDestructor(struct TASK *t /*$s0*/)
 // line 2852, offset 0x80063e6c
	/* begin block 1 */
		// Start line: 2853
		// Start offset: 0x80063E6C
	/* end block 1 */
	// End offset: 0x80063E6C
	// End Line: 2853

	/* begin block 2 */
		// Start line: 7429
	/* end block 2 */
	// End Line: 7430

void SFX_StreamDestructor(TASK *t)

{
  Heap_FreeMem((void *)t[8].s7);
  Heap_FreeMem((void *)t[8].fp);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SFX_StreamCreate(long index /*$s2*/)
 // line 2861, offset 0x80063ea4
	/* begin block 1 */
		// Start line: 2862
		// Start offset: 0x80063EA4
		// Variables:
	// 		struct _STREAM_FT4 *sf; // $s1
	// 		struct SFX_5fake mr; // stack offset -56
	// 		long f; // stack offset -24
	// 		long size; // $a0
	/* end block 1 */
	// End offset: 0x8006429C
	// End Line: 2928

	/* begin block 2 */
		// Start line: 7447
	/* end block 2 */
	// End Line: 7448

void SFX_StreamCreate(long index)

{
  byte bVar1;
  short sVar2;
  undefined2 uVar3;
  TASK *pTVar4;
  long lVar5;
  int iVar6;
  TASK *pTVar7;
  ushort uVar8;
  int iVar9;
  short *psVar10;
  TASK **ppTVar11;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined auStack24 [8];
  
  pTVar4 = TaskCurrent;
  if ((*(ushort *)&TaskCurrent[1].s7 & 0x80) == 0) {
    iVar6 = index * 8;
    *(undefined2 *)(iVar6 + TaskCurrent[8].s7) = *(undefined2 *)&TaskCurrent[1].exec;
    *(undefined2 *)(iVar6 + pTVar4[8].s7 + 2) = *(undefined2 *)((int)&pTVar4[1].exec + 2);
    *(undefined2 *)(iVar6 + pTVar4[8].s7 + 4) = *(undefined2 *)&pTVar4[1].sp;
  }
  else {
    iVar6 = index * 8;
    *(undefined2 *)(iVar6 + TaskCurrent[8].s7) = 0;
    *(undefined2 *)(iVar6 + pTVar4[8].s7 + 2) = 0;
    *(undefined2 *)(iVar6 + pTVar4[8].s7 + 4) = 0;
  }
  if ((*(ushort *)&pTVar4[1].s7 & 2) != 0) {
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    setCopControlWord(2,0x2800,0);
    setCopControlWord(2,0x3000,0);
    setCopControlWord(2,0x3800,0);
    RotMatrix((short *)pTVar4[1].bnext,(undefined2 *)&local_38);
    setCopControlWord(2,0,local_38);
    setCopControlWord(2,0x800,local_34);
    setCopControlWord(2,0x1000,local_30);
    setCopControlWord(2,0x1800,local_2c);
    setCopControlWord(2,0x2000,local_28);
    iVar6 = pTVar4[8].s7 + index * 8;
    RotTransSV(iVar6,iVar6,auStack24);
    setCopControlWord(2,0x2800,Cam_Matrix.t[0]);
    setCopControlWord(2,0x3000,Cam_Matrix.t[1]);
    setCopControlWord(2,0x3800,Cam_Matrix.t[2]);
    setCopControlWord(2,0,Cam_Matrix.m[0]._0_4_);
    setCopControlWord(2,0x800,Cam_Matrix.m._4_4_);
    setCopControlWord(2,0x1000,Cam_Matrix.m[1]._2_4_);
    setCopControlWord(2,0x1800,Cam_Matrix.m[2]._0_4_);
    setCopControlWord(2,0x2000,Cam_Matrix._16_4_);
  }
  pTVar7 = pTVar4[1].bprec;
  if (pTVar7 != (TASK *)0x0) {
    iVar6 = index * 8;
    if ((*(ushort *)&pTVar4[1].s7 & 1) == 0) {
      if ((*(ushort *)&pTVar4[1].s7 & 8) == 0) {
        psVar10 = (short *)(iVar6 + pTVar4[8].s7);
        *psVar10 = *psVar10 + *(short *)&pTVar7->prec;
        iVar9 = iVar6 + pTVar4[8].s7;
        *(short *)(iVar9 + 2) =
             *(short *)(iVar9 + 2) + *(short *)((int)&(pTVar4[1].bprec)->prec + 2);
        iVar6 = iVar6 + pTVar4[8].s7;
        *(short *)(iVar6 + 4) = *(short *)(iVar6 + 4) + *(short *)&(pTVar4[1].bprec)->next;
      }
      else {
        iVar6 = index * 8;
        lVar5 = M_rand();
        bVar1 = *(byte *)((int)&pTVar4[1].local + 2);
        if (bVar1 == 0) {
          trap(0x1c00);
        }
        if (((uint)bVar1 == 0xffffffff) && (lVar5 == -0x80000000)) {
          trap(0x1800);
        }
        psVar10 = (short *)(iVar6 + pTVar4[8].s7);
        *psVar10 = *psVar10 + *(short *)&(pTVar4[1].bprec)->prec + (short)(lVar5 % (uint)bVar1);
        lVar5 = M_rand();
        bVar1 = *(byte *)&pTVar4[1].s0;
        if (bVar1 == 0) {
          trap(0x1c00);
        }
        if (((uint)bVar1 == 0xffffffff) && (lVar5 == -0x80000000)) {
          trap(0x1800);
        }
        iVar9 = iVar6 + pTVar4[8].s7;
        *(short *)(iVar9 + 2) =
             *(short *)(iVar9 + 2) +
             *(short *)((int)&(pTVar4[1].bprec)->prec + 2) + (short)(lVar5 % (uint)bVar1);
        lVar5 = M_rand();
        bVar1 = *(byte *)((int)&pTVar4[1].s0 + 2);
        if (bVar1 == 0) {
          trap(0x1c00);
        }
        if (((uint)bVar1 == 0xffffffff) && (lVar5 == -0x80000000)) {
          trap(0x1800);
        }
        iVar6 = iVar6 + pTVar4[8].s7;
        *(short *)(iVar6 + 4) =
             *(short *)(iVar6 + 4) +
             *(short *)&(pTVar4[1].bprec)->next + (short)(lVar5 % (uint)bVar1);
      }
    }
    else {
      psVar10 = (short *)(iVar6 + pTVar4[8].s7);
      *psVar10 = *psVar10 + *(short *)(&pTVar7->prec + index * 2);
      iVar9 = iVar6 + pTVar4[8].s7;
      *(short *)(iVar9 + 2) =
           *(short *)(iVar9 + 2) + *(short *)((int)&(pTVar4[1].bprec)->prec + iVar6 + 2);
      iVar6 = iVar6 + pTVar4[8].s7;
      *(short *)(iVar6 + 4) =
           *(short *)(iVar6 + 4) + *(short *)(&(pTVar4[1].bprec)->next + index * 2);
    }
  }
  if ((*(ushort *)&pTVar4[1].s7 & 0x20) == 0) {
    uVar8 = *(ushort *)((int)&pTVar4[1].s7 + 2);
  }
  else {
    lVar5 = M_rand();
    sVar2 = *(short *)((int)&pTVar4[1].s7 + 2);
    iVar6 = (int)sVar2 * 3;
    if (iVar6 < 0) {
      iVar6 = iVar6 + 3;
    }
    iVar6 = iVar6 >> 2;
    if (iVar6 == 0) {
      trap(0x1c00);
    }
    if ((iVar6 == -1) && (lVar5 == -0x80000000)) {
      trap(0x1800);
    }
    uVar8 = sVar2 - (short)(lVar5 % iVar6);
  }
  if ((*(ushort *)&pTVar4[1].s7 & 4) != 0) {
    uVar8 = 0;
  }
  *(ushort *)(index * 8 + pTVar4[8].s7 + 6) = uVar8 | *(short *)&pTVar4[1].display << 8;
  *(undefined2 *)((int)&pTVar4[1].fp + index * 2 + 2) = 0x1000;
  ppTVar11 = &pTVar4->prec + index * 2;
  *(undefined2 *)((int)ppTVar11 + 0x1a6) = *(undefined2 *)&pTVar4[1].destructor;
  *(undefined2 *)(ppTVar11 + 0x6a) = *(undefined2 *)((int)&pTVar4[1].destructor + 2);
  uVar3 = *(undefined2 *)&pTVar4[1].local;
  *(undefined2 *)(ppTVar11 + 0x6b) = 0;
  *(undefined2 *)((int)ppTVar11 + 0x1aa) = uVar3;
  lVar5 = M_rand();
  bVar1 = *(byte *)((int)&pTVar4[1].local + 2);
  if (bVar1 == 0) {
    trap(0x1c00);
  }
  if (((uint)bVar1 == 0xffffffff) && (lVar5 == -0x80000000)) {
    trap(0x1800);
  }
  *(short *)((int)ppTVar11 + 0x1a6) =
       *(short *)((int)ppTVar11 + 0x1a6) +
       ((short)(lVar5 % (uint)bVar1) - (ushort)*(byte *)((int)&pTVar4[1].local + 3));
  lVar5 = M_rand();
  bVar1 = *(byte *)&pTVar4[1].s0;
  if (bVar1 == 0) {
    trap(0x1c00);
  }
  if (((uint)bVar1 == 0xffffffff) && (lVar5 == -0x80000000)) {
    trap(0x1800);
  }
  *(ushort *)(ppTVar11 + 0x6a) =
       *(short *)(ppTVar11 + 0x6a) +
       ((short)(lVar5 % (uint)bVar1) - (ushort)*(byte *)((int)&pTVar4[1].s0 + 1));
  lVar5 = M_rand();
  bVar1 = *(byte *)((int)&pTVar4[1].s0 + 2);
  if (bVar1 == 0) {
    trap(0x1c00);
  }
  if (((uint)bVar1 == 0xffffffff) && (lVar5 == -0x80000000)) {
    trap(0x1800);
  }
  *(short *)((int)ppTVar11 + 0x1aa) =
       *(short *)((int)ppTVar11 + 0x1aa) +
       ((short)(lVar5 % (uint)bVar1) - (ushort)*(byte *)((int)&pTVar4[1].s0 + 3));
  return;
}



// decompiled code
// original method signature: 
// struct TASK * /*$ra*/ SFX_StreamSteam(struct SFX_7fake *pos /*$a3*/, struct SFX_7fake *spd /*$a1*/, long flag /*$a2*/)
 // line 2950, offset 0x800643e4
	/* begin block 1 */
		// Start line: 2951
		// Start offset: 0x800643E4
		// Variables:
	// 		struct _SPEED_RAND speed; // stack offset -48
	// 		struct _INTPL_COLOR colors; // stack offset -32
	// 		short size; // $v1
	/* end block 1 */
	// End offset: 0x80064470
	// End Line: 2984

	/* begin block 2 */
		// Start line: 7626
	/* end block 2 */
	// End Line: 7627

TASK * SFX_StreamSteam(undefined1 pos,undefined spd,long flag)

{
  TASK *pTVar1;
  long size;
  undefined3 in_register_00000015;
  short *psVar2;
  _SPEED_RAND local_30;
  _INTPL_COLOR local_20;
  
  psVar2 = (short *)CONCAT31(in_register_00000015,spd);
  local_30.vx = *psVar2;
  local_30.vy = psVar2[1];
  local_30.vz = psVar2[2];
  local_30.offsetx = '\x02';
  local_30.offsety = '\x02';
  local_30.randx = '\x04';
  local_30.randy = '\x04';
  local_30.randz = '\n';
  local_30.offsetz = '\0';
  if (flag == 0) {
    size = 8;
    local_20.col1.vx = 0xc80;
    local_20.col1.vy = 0xc80;
    local_20.col1.vz = 0xc80;
    local_20.nbf = 0xf;
  }
  else {
    size = 5;
    local_20.col1.vx = 800;
    local_20.col1.vy = 4000;
    local_20.col1.vz = 0x640;
    local_20.nbf = 10;
  }
  local_20.col2.r = '\n';
  local_20.col2.g = '\n';
  local_20.col2.b = '\n';
  local_20.col1.pad = 0;
  pTVar1 = SFX_Stream(pos,0,0,0x9b,0x19,&local_30,size,1,&local_20,0);
  return pTVar1;
}



// decompiled code
// original method signature: 
// struct TASK * /*$ra*/ SFX_StreamGeiser(struct SFX_7fake *pos /*$a2*/, struct SFX_7fake *spd /*$a1*/)
 // line 2996, offset 0x800644d0
	/* begin block 1 */
		// Start line: 2997
		// Start offset: 0x800644D0
		// Variables:
	// 		struct _SPEED_RAND speed; // stack offset -48
	// 		struct _INTPL_COLOR colors; // stack offset -32
	// 		struct TASK *handle; // $v0
	// 		long flags; // $v1
	/* end block 1 */
	// End offset: 0x800645E8
	// End Line: 3040

	/* begin block 2 */
		// Start line: 7744
	/* end block 2 */
	// End Line: 7745

/* WARNING: Unknown calling convention yet parameter storage is locked */

TASK * SFX_StreamGeiser(undefined1 pos,undefined spd)

{
  TASK *pTVar1;
  int flags;
  undefined3 in_register_00000015;
  short *psVar2;
  long num_shp;
  long local_40;
  _SPEED_RAND local_30;
  _INTPL_COLOR local_20;
  
  psVar2 = (short *)CONCAT31(in_register_00000015,spd);
  local_30.vx = *psVar2;
  local_30.vy = psVar2[1];
  local_30.vz = psVar2[2];
  local_30.randx = '\x04';
  local_30.offsetx = '\x02';
  local_30.randy = '\x04';
  local_30.offsety = '\x02';
  local_30.randz = '\x04';
  local_30.offsetz = '\x02';
  flags = 0x800;
  if (psVar2[3] == 0) {
    flags = 0x400;
    local_20.col1.vx = 800;
    local_20.col1.vy = 0x800;
    local_20.col1.vz = 4000;
  }
  else {
    local_20.col1.vz = 0x960;
    local_20.col1.vx = 0x960;
    local_20.col1.vy = 0x960;
  }
  local_20.col2.r = '\n';
  local_20.col2.g = '\n';
  local_20.col2.b = '\n';
  local_20.col1.pad = 0;
  local_20.nbf = 0xf;
  if (psVar2[3] == 0) {
    num_shp = 0xe2;
    local_40 = 8;
  }
  else {
    num_shp = 0x99;
    local_40 = 2;
  }
  pTVar1 = SFX_Stream(pos,0,0,num_shp,0x19,&local_30,local_40,(uint)(psVar2[3] != 0),&local_20,flags
                     );
  return pTVar1;
}



// decompiled code
// original method signature: 
// struct TASK * /*$ra*/ SFX_StreamFire(struct _D3_OBJECT *obj /*$a0*/)
 // line 3043, offset 0x800645f8
	/* begin block 1 */
		// Start line: 3044
		// Start offset: 0x800645F8
		// Variables:
	// 		struct _SPEED_RAND speed; // stack offset -48
	// 		struct _INTPL_COLOR colors; // stack offset -32
	/* end block 1 */
	// End offset: 0x800645F8
	// End Line: 3044

	/* begin block 2 */
		// Start line: 7858
	/* end block 2 */
	// End Line: 7859

TASK * SFX_StreamFire(_D3_OBJECT *obj)

{
  TASK *pTVar1;
  _SPEED_RAND local_30;
  _INTPL_COLOR local_20;
  
  local_30.vz = 4;
  local_30.randx = '\x04';
  local_30.randy = '\x04';
  local_30.randz = '\n';
  local_20.col1.vx = 4000;
  local_20.col1.vy = 0x960;
  local_20.col1.vz = 0x460;
  local_20.col2.r = 'd';
  local_20.col2.g = 'd';
  local_20.col2.b = '<';
  local_20.nbf = 0xf;
  local_30.vx = 0;
  local_30.vy = 0;
  local_30.offsetx = '\x02';
  local_30.offsety = '\x02';
  local_30.offsetz = '\0';
  local_20.col1.pad = 0;
  pTVar1 = SFX_Stream((char)obj + ',',0,0,0x9b,0x19,&local_30,0x21,-1,&local_20,0);
  return pTVar1;
}



// decompiled code
// original method signature: 
// struct TASK * /*$ra*/ SFX_StreamBubble(struct SFX_7fake *pos /*$a0*/, long transZ /*$a1*/)
 // line 3075, offset 0x800646b8
	/* begin block 1 */
		// Start line: 3076
		// Start offset: 0x800646B8
		// Variables:
	// 		struct _SPEED_RAND speed; // stack offset -56
	// 		struct _INTPL_COLOR colors; // stack offset -40
	// 		struct SFX_7fake trans; // stack offset -16
	/* end block 1 */
	// End offset: 0x800646B8
	// End Line: 3076

	/* begin block 2 */
		// Start line: 7967
	/* end block 2 */
	// End Line: 7968

TASK * SFX_StreamBubble(undefined1 pos,long transZ)

{
  TASK *pTVar1;
  _SPEED_RAND local_38;
  _INTPL_COLOR local_28;
  undefined2 local_10;
  undefined2 local_e;
  undefined2 local_c;
  
  local_38.vz = 5;
  local_38.randx = '\x01';
  local_38.randy = '\x01';
  local_38.randz = '\x02';
  local_28.col1.vx = 4000;
  local_28.col1.vy = 4000;
  local_28.col1.vz = 4000;
  local_28.col1.pad = 5;
  local_28.col2.r = -6;
  local_28.col2.g = -6;
  local_28.col2.b = -6;
  local_28.nbf = 0x14;
  local_38.vx = 0;
  local_38.vy = 0;
  local_38.offsetx = '\0';
  local_38.offsety = '\0';
  local_38.offsetz = '\0';
  local_10 = 0;
  local_e = 0;
  local_c = (undefined2)transZ;
  pTVar1 = SFX_Stream(pos,0,0xf0,0xa7,0x14,&local_38,0xc,0,&local_28,0x2e0);
  return pTVar1;
}



// decompiled code
// original method signature: 
// struct TASK * /*$ra*/ SFX_StreamWarminMissile(struct _D3_OBJECT *obj /*$a0*/, struct SFX_7fake *spd /*$a1*/, short size /*$a2*/)
 // line 3119, offset 0x8006477c
	/* begin block 1 */
		// Start line: 3120
		// Start offset: 0x8006477C
		// Variables:
	// 		struct _SPEED_RAND speed; // stack offset -48
	// 		struct _INTPL_COLOR colors; // stack offset -32
	/* end block 1 */
	// End offset: 0x8006477C
	// End Line: 3120

	/* begin block 2 */
		// Start line: 8153
	/* end block 2 */
	// End Line: 8154

TASK * SFX_StreamWarminMissile(_D3_OBJECT *obj,undefined spd,short size)

{
  TASK *pTVar1;
  undefined3 in_register_00000015;
  short *psVar2;
  _SPEED_RAND local_30;
  _INTPL_COLOR local_20;
  
  psVar2 = (short *)CONCAT31(in_register_00000015,spd);
  local_30.vx = (short)((int)(-(int)*psVar2 + ((uint)-(int)*psVar2 >> 0x1f)) >> 1);
  local_30.vy = (short)((int)(-(int)psVar2[1] + ((uint)-(int)psVar2[1] >> 0x1f)) >> 1);
  local_30.offsetx = '\x02';
  local_30.offsety = '\x02';
  local_30.randz = '\x05';
  local_20.col1.vx = 4000;
  local_20.col1.vy = 0x460;
  local_20.col1.vz = 0x460;
  local_20.col2.r = 'F';
  local_20.col2.g = '<';
  local_20.col2.b = '<';
  local_30.randx = '\x04';
  local_30.randy = '\x04';
  local_30.offsetz = '\0';
  local_20.col1.pad = 0;
  local_20.nbf = 7;
  local_30.vz = (short)((int)(-(int)psVar2[2] + ((uint)-(int)psVar2[2] >> 0x1f)) >> 1);
  pTVar1 = SFX_Stream((char)obj + ',',0,0,0x9b,0xf,&local_30,(int)size,-1,&local_20,0);
  return pTVar1;
}



// decompiled code
// original method signature: 
// struct TASK * /*$ra*/ SFX_StreamMissile(struct _D3_OBJECT *obj /*$a0*/)
 // line 3151, offset 0x80064878
	/* begin block 1 */
		// Start line: 3152
		// Start offset: 0x80064878
		// Variables:
	// 		struct _SPEED_RAND speed; // stack offset -48
	// 		struct _INTPL_COLOR colors; // stack offset -32
	/* end block 1 */
	// End offset: 0x80064878
	// End Line: 3152

	/* begin block 2 */
		// Start line: 8348
	/* end block 2 */
	// End Line: 8349

TASK * SFX_StreamMissile(_D3_OBJECT *obj)

{
  TASK *pTVar1;
  _SPEED_RAND local_30;
  _INTPL_COLOR local_20;
  
  local_30.offsetx = '\x02';
  local_30.offsety = '\x02';
  local_30.randz = '\x05';
  local_20.col1.vx = 4000;
  local_20.col1.vy = 0x960;
  local_20.col1.vz = 0x460;
  local_20.col2.r = 'd';
  local_20.col2.g = 'P';
  local_20.col2.b = '<';
  local_30.randx = '\x04';
  local_30.randy = '\x04';
  local_20.nbf = 0xe;
  local_30.vx = 0;
  local_30.vy = 0;
  local_30.vz = 0;
  local_30.offsetz = '\0';
  local_20.col1.pad = 0;
  pTVar1 = SFX_Stream((char)obj + ',',0,0,0x9b,0x14,&local_30,0x14,1,&local_20,0);
  return pTVar1;
}



// decompiled code
// original method signature: 
// struct TASK * /*$ra*/ SFX_StreamSmokyFire(struct _D3_OBJECT *obj /*$a0*/)
 // line 3183, offset 0x80064938
	/* begin block 1 */
		// Start line: 3184
		// Start offset: 0x80064938
		// Variables:
	// 		struct _SPEED_RAND speed; // stack offset -48
	// 		struct _INTPL_COLOR colors; // stack offset -32
	/* end block 1 */
	// End offset: 0x80064938
	// End Line: 3184

	/* begin block 2 */
		// Start line: 8474
	/* end block 2 */
	// End Line: 8475

TASK * SFX_StreamSmokyFire(_D3_OBJECT *obj)

{
  TASK *pTVar1;
  _SPEED_RAND local_30;
  _INTPL_COLOR local_20;
  
  local_30.vz = 3;
  local_30.offsetx = '\x02';
  local_30.offsety = '\x02';
  local_30.randz = '\f';
  local_20.col1.vx = 4000;
  local_20.col1.vy = 0x960;
  local_20.col1.vz = 0x460;
  local_20.col2.r = '\n';
  local_20.col2.g = '\n';
  local_20.col2.b = '\n';
  local_20.nbf = 0x12;
  local_30.vx = 0;
  local_30.vy = 0;
  local_30.randx = '\x04';
  local_30.randy = '\x04';
  local_30.offsetz = '\0';
  local_20.col1.pad = 0;
  pTVar1 = SFX_Stream((char)obj + ',',0,0,0x9b,0xf,&local_30,0x21,1,&local_20,0);
  return pTVar1;
}



// decompiled code
// original method signature: 
// struct TASK * /*$ra*/ SFX_StreamFireWall(struct SFX_7fake *pos /*$a0*/)
 // line 3215, offset 0x800649f8
	/* begin block 1 */
		// Start line: 3216
		// Start offset: 0x800649F8
		// Variables:
	// 		struct _SPEED_RAND speed; // stack offset -48
	// 		struct _INTPL_COLOR colors; // stack offset -32
	/* end block 1 */
	// End offset: 0x800649F8
	// End Line: 3216

	/* begin block 2 */
		// Start line: 8583
	/* end block 2 */
	// End Line: 8584

/* WARNING: Unknown calling convention yet parameter storage is locked */

TASK * SFX_StreamFireWall(undefined1 pos)

{
  TASK *pTVar1;
  _SPEED_RAND local_30;
  _INTPL_COLOR local_20;
  
  local_30.vz = 3;
  local_30.offsetx = '\x02';
  local_30.offsety = '\x02';
  local_30.randz = '\f';
  local_20.col1.vx = 4000;
  local_20.col1.vy = 0x960;
  local_20.col1.vz = 0x460;
  local_20.col2.r = '\n';
  local_20.col2.g = '\n';
  local_20.col2.b = '\n';
  local_20.nbf = 0x12;
  local_30.vx = 0;
  local_30.vy = 0;
  local_30.randx = '\x04';
  local_30.randy = '\x04';
  local_30.offsetz = '\0';
  local_20.col1.pad = 0;
  pTVar1 = SFX_Stream(pos,0,0,0x9b,0x19,&local_30,0x32,1,&local_20,0);
  return pTVar1;
}



// decompiled code
// original method signature: 
// struct TASK * /*$ra*/ SFX_StreamWaterFall(struct SFX_7fake *pos /*$a0*/)
 // line 3247, offset 0x80064ab4
	/* begin block 1 */
		// Start line: 3248
		// Start offset: 0x80064AB4
		// Variables:
	// 		struct _INTPL_COLOR colors; // stack offset -48
	// 		struct _SPEED_RAND speed; // stack offset -24
	/* end block 1 */
	// End offset: 0x80064AB4
	// End Line: 3248

	/* begin block 2 */
		// Start line: 8692
	/* end block 2 */
	// End Line: 8693

/* WARNING: Unknown calling convention yet parameter storage is locked */

TASK * SFX_StreamWaterFall(undefined1 pos)

{
  TASK *pTVar1;
  _INTPL_COLOR local_30;
  _SPEED_RAND local_18;
  
  local_18.vz = -0xf;
  local_18.offsetx = '\x01';
  local_18.offsety = '\x01';
  local_18.offsetz = '\x01';
  local_30.col1.vx = 0x960;
  local_30.col1.vy = 0x960;
  local_30.col1.vz = 4000;
  local_30.col2.r = '\n';
  local_30.col2.g = '\n';
  local_30.col2.b = '\n';
  local_30.nbf = 0x23;
  local_18.vx = 0;
  local_18.vy = 0;
  local_18.randx = '\x02';
  local_18.randy = '\x02';
  local_18.randz = '\x02';
  local_30.col1.pad = 0;
  pTVar1 = SFX_Stream(pos,0,0,0xe2,0x2d,&local_18,6,0,&local_30,0);
  return pTVar1;
}



// decompiled code
// original method signature: 
// struct TASK * /*$ra*/ SFX_StreamReactor(struct SFX_7fake *pos /*$a0*/, struct SFX_7fake *rot /*$a1*/, struct SFX_7fake *trans /*$a2*/)
 // line 3279, offset 0x80064b64
	/* begin block 1 */
		// Start line: 3280
		// Start offset: 0x80064B64
		// Variables:
	// 		struct _SPEED_RAND speed; // stack offset -48
	// 		struct _INTPL_COLOR colors; // stack offset -32
	/* end block 1 */
	// End offset: 0x80064B64
	// End Line: 3280

	/* begin block 2 */
		// Start line: 8801
	/* end block 2 */
	// End Line: 8802

/* WARNING: Unknown calling convention yet parameter storage is locked */

TASK * SFX_StreamReactor(undefined1 pos,undefined1 rot,undefined1 trans)

{
  TASK *pTVar1;
  _SPEED_RAND local_30;
  _INTPL_COLOR local_20;
  
  local_30.vz = -0xf;
  local_30.offsetx = '\x02';
  local_30.offsety = '\x02';
  local_30.randz = '\x01';
  local_20.col1.vx = 0x640;
  local_20.col1.vy = 0x640;
  local_20.col1.vz = 4000;
  local_20.col2.b = '\n';
  local_20.nbf = 5;
  local_30.vx = 0;
  local_30.vy = 0;
  local_30.randx = '\x04';
  local_30.randy = '\x04';
  local_30.offsetz = '\0';
  local_20.col1.pad = 0;
  local_20.col2.r = '\0';
  local_20.col2.g = '\0';
  pTVar1 = SFX_Stream(pos,rot,trans,0x9b,10,&local_30,0x10,-2,&local_20,2);
  return pTVar1;
}



// decompiled code
// original method signature: 
// struct TASK * /*$ra*/ SFX_StreamTracingBullet(struct _D3_OBJECT *obj /*$a3*/, struct SFX_7fake *spd /*$a1*/, long nb_part /*$a2*/)
 // line 3314, offset 0x80064c18
	/* begin block 1 */
		// Start line: 3315
		// Start offset: 0x80064C18
		// Variables:
	// 		struct _SPEED_RAND speed; // stack offset -48
	// 		struct _INTPL_COLOR colors; // stack offset -32
	/* end block 1 */
	// End offset: 0x80064C6C
	// End Line: 3322

	/* begin block 2 */
		// Start line: 8937
	/* end block 2 */
	// End Line: 8938

TASK * SFX_StreamTracingBullet(_D3_OBJECT *obj,undefined spd,long nb_part)

{
  int iVar1;
  TASK *pTVar2;
  undefined3 in_register_00000015;
  short *psVar3;
  _SPEED_RAND local_30;
  _INTPL_COLOR local_20;
  
  psVar3 = (short *)CONCAT31(in_register_00000015,spd);
  iVar1 = (int)*psVar3;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 3;
  }
  local_30.vx = (short)(iVar1 >> 2);
  iVar1 = (int)psVar3[1];
  if (iVar1 < 0) {
    iVar1 = iVar1 + 3;
  }
  local_30.vy = (short)(iVar1 >> 2);
  iVar1 = (int)psVar3[2];
  if (iVar1 < 0) {
    iVar1 = iVar1 + 3;
  }
  local_30.vz = (short)(iVar1 >> 2);
  local_30.randx = '\n';
  local_30.offsetx = '\x05';
  local_30.randy = '\n';
  local_30.offsety = '\x05';
  local_30.randz = '\n';
  local_30.offsetz = '\x05';
  local_20.col1.vx = (uint)*(byte *)&obj->color << 4;
  local_20.col1.vy = (uint)*(byte *)((int)&obj->color + 1) << 4;
  local_20.nbf = 10;
  local_20.col2.r = '\n';
  local_20.col2.g = '\n';
  local_20.col2.b = '\n';
  local_20.col1.pad = 0;
  local_20.col1.vz = (uint)*(byte *)((int)&obj->color + 2) << 4;
  pTVar2 = SFX_Stream((char)obj + ',',0,0,0xe6,nb_part,&local_30,9,-1,&local_20,0);
  return pTVar2;
}



// decompiled code
// original method signature: 
// struct TASK * /*$ra*/ SFX_StreamTracingImpact(struct _D3_OBJECT *obj /*$a0*/, struct SFX_7fake *spd /*$a1*/)
 // line 3348, offset 0x80064d20
	/* begin block 1 */
		// Start line: 3349
		// Start offset: 0x80064D20
		// Variables:
	// 		struct _SPEED_RAND speed; // stack offset -48
	// 		struct _INTPL_COLOR colors; // stack offset -32
	/* end block 1 */
	// End offset: 0x80064D20
	// End Line: 3349

	/* begin block 2 */
		// Start line: 9036
	/* end block 2 */
	// End Line: 9037

TASK * SFX_StreamTracingImpact(_D3_OBJECT *obj,undefined spd)

{
  TASK *pTVar1;
  undefined3 in_register_00000015;
  short *psVar2;
  _SPEED_RAND local_30;
  _INTPL_COLOR local_20;
  
  psVar2 = (short *)CONCAT31(in_register_00000015,spd);
  local_30.vx = (short)((ulonglong)((longlong)(int)*psVar2 * 0x55555556) >> 0x20) - (*psVar2 >> 0xf)
  ;
  local_30.vy = (short)((ulonglong)((longlong)(int)psVar2[1] * 0x55555556) >> 0x20) -
                (psVar2[1] >> 0xf);
  local_30.randx = '\x14';
  local_30.offsetx = '\n';
  local_30.randy = '\x14';
  local_30.offsety = '\n';
  local_30.randz = '\x14';
  local_30.offsetz = '\n';
  local_30.vz = (short)((ulonglong)((longlong)-(int)psVar2[2] * 0x55555556) >> 0x20) -
                (short)(-(int)psVar2[2] >> 0x1f);
  local_20.col1.vx = (uint)*(byte *)&obj->color << 4;
  local_20.col1.vy = (uint)*(byte *)((int)&obj->color + 1) << 4;
  local_20.nbf = 10;
  local_20.col2.r = '\n';
  local_20.col2.g = '\n';
  local_20.col2.b = '\n';
  local_20.col1.pad = 0;
  local_20.col1.vz = (uint)*(byte *)((int)&obj->color + 2) << 4;
  pTVar1 = SFX_Stream((char)obj + ',',0,0,0xe6,0xf,&local_30,10,-1,&local_20,8);
  return pTVar1;
}



// decompiled code
// original method signature: 
// struct TASK * /*$ra*/ SFX_StreamBirth(struct SFX_7fake *pos /*$a0*/, struct SFX_7fake *rot /*$a1*/)
 // line 3384, offset 0x80064e48
	/* begin block 1 */
		// Start line: 3385
		// Start offset: 0x80064E48
		// Variables:
	// 		struct _SPEED_RAND speed; // stack offset -48
	// 		struct _INTPL_COLOR colors; // stack offset -32
	/* end block 1 */
	// End offset: 0x80064E48
	// End Line: 3385

	/* begin block 2 */
		// Start line: 9163
	/* end block 2 */
	// End Line: 9164

/* WARNING: Unknown calling convention yet parameter storage is locked */

TASK * SFX_StreamBirth(undefined1 pos,undefined1 rot)

{
  TASK *pTVar1;
  _SPEED_RAND local_30;
  _INTPL_COLOR local_20;
  
  local_30.vz = -0xf;
  local_30.offsetx = '\x04';
  local_30.offsety = '\x04';
  local_30.randz = '\x05';
  local_30.offsetz = '\x02';
  local_20.col1.vx = 0x800;
  local_20.col1.vy = 0x800;
  local_20.col1.vz = 0x800;
  local_20.col2.r = -0x80;
  local_20.col2.g = -0x80;
  local_20.col2.b = -0x80;
  local_20.nbf = 10;
  local_30.vx = 0;
  local_30.vy = 0;
  local_30.randx = '\b';
  local_30.randy = '\b';
  local_20.col1.pad = 0;
  pTVar1 = SFX_Stream(pos,0,0,0x29,0x14,&local_30,0x10,-1,&local_20,0);
  return pTVar1;
}



// decompiled code
// original method signature: 
// struct TASK * /*$ra*/ SFX_StreamCone(struct SFX_7fake *pos /*$s3*/, struct SFX_7fake *rot /*$s1*/, struct SFX_8fake *col /*$s2*/)
 // line 3420, offset 0x80064f00
	/* begin block 1 */
		// Start line: 3421
		// Start offset: 0x80064F00
		// Variables:
	// 		struct _SPEED_RAND speed; // stack offset -72
	// 		struct _INTPL_COLOR colors; // stack offset -56
	// 		long dist; // $s0
	// 		struct SFX_7fake spd; // stack offset -32
	/* end block 1 */
	// End offset: 0x80064F00
	// End Line: 3421

	/* begin block 2 */
		// Start line: 9288
	/* end block 2 */
	// End Line: 9289

/* WARNING: Unknown calling convention yet parameter storage is locked */

TASK * SFX_StreamCone(undefined1 pos,undefined rot,undefined col)

{
  int iVar1;
  TASK *pTVar2;
  undefined3 in_register_00000015;
  short *psVar3;
  undefined3 in_register_00000019;
  byte *pbVar4;
  _SPEED_RAND local_48;
  _INTPL_COLOR local_38;
  short local_20;
  short local_1e;
  short local_1c;
  
  pbVar4 = (byte *)CONCAT31(in_register_00000019,col);
  psVar3 = (short *)CONCAT31(in_register_00000015,rot);
  iVar1 = rcos((int)psVar3[2]);
  local_20 = (short)(iVar1 * 0x19 >> 0xc);
  iVar1 = rsin((int)psVar3[2]);
  local_1e = (short)(iVar1 * 0x19 >> 0xc);
  iVar1 = rsin((int)*psVar3);
  local_48.randx = '\x1e';
  local_48.offsetx = '\x0f';
  local_48.randy = '\x1e';
  local_48.offsety = '\x0f';
  local_48.randz = '\x1e';
  local_48.offsetz = '\x0f';
  local_48.vx = local_20;
  local_48.vy = local_1e;
  local_48.vz = (short)(iVar1 * 0x19 >> 0xc);
  local_38.col1.vx = (uint)*pbVar4 << 4;
  local_38.col1.vy = (uint)pbVar4[1] << 4;
  local_38.col2.r = '\n';
  local_38.col2.g = '\n';
  local_38.col2.b = '\n';
  local_38.col1.pad = 0x1e;
  local_38.nbf = 0x1e;
  local_38.col1.vz = (uint)pbVar4[2] << 4;
  local_1c = local_48.vz;
  pTVar2 = SFX_Stream(0,0,pos,0xe6,0x32,&local_48,4,0,&local_38,0x108);
  return pTVar2;
}



// decompiled code
// original method signature: 
// struct TASK * /*$ra*/ SFX_StreamExplosion(struct SFX_7fake *pos /*$a0*/, struct SFX_7fake *rot /*$a1*/, struct SFX_8fake *col /*$a2*/)
 // line 3463, offset 0x80065048
	/* begin block 1 */
		// Start line: 3464
		// Start offset: 0x80065048
		// Variables:
	// 		struct _SPEED_RAND speed; // stack offset -56
	// 		struct _INTPL_COLOR colors; // stack offset -40
	// 		struct SFX_7fake spd; // stack offset -16
	/* end block 1 */
	// End offset: 0x80065048
	// End Line: 3464

	/* begin block 2 */
		// Start line: 9488
	/* end block 2 */
	// End Line: 9489

/* WARNING: Unknown calling convention yet parameter storage is locked */

TASK * SFX_StreamExplosion(undefined1 pos,undefined1 rot,undefined1 col)

{
  TASK *pTVar1;
  _SPEED_RAND local_38;
  _INTPL_COLOR local_28;
  
  local_38.offsetx = '\x19';
  local_38.offsety = '\x19';
  local_38.offsetz = '\x19';
  local_28.col1.vx = 4000;
  local_28.col1.vy = 0xaa0;
  local_38.randx = '2';
  local_38.randy = '2';
  local_38.randz = '2';
  local_28.col1.vz = 800;
  local_28.col2.r = '\n';
  local_28.col2.g = '\n';
  local_28.col2.b = '\n';
  local_38.vx = 0;
  local_38.vy = 0;
  local_38.vz = 0;
  local_28.col1.pad = 0x19;
  local_28.nbf = 0x19;
  pTVar1 = SFX_Stream(pos,0,0,0xe6,0x50,&local_38,4,0,&local_28,0x508);
  return pTVar1;
}





