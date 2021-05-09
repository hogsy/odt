#include "THISDUST.H"
#include "P_SPELL.H"


// decompiled code
// original method signature: 
// void /*$ra*/ PSpell_Spell(struct _PLAYER *pl /*$s1*/, long spell /*$s2*/)
 // line 68, offset 0x80040f0c
	/* begin block 1 */
		// Start line: 69
		// Start offset: 0x80040F0C
	/* end block 1 */
	// End offset: 0x80040F5C
	// End Line: 76

	/* begin block 2 */
		// Start line: 136
	/* end block 2 */
	// End Line: 137

void PSpell_Spell(_PLAYER *pl,long spell)

{
  short sVar1;
  short sVar2;
  long lVar3;
  long lVar4;
  
  sVar1 = *(short *)((pl->env2).Obj.primitive_top.Data + 0xe);
  if (sVar1 != 0) {
    lVar3 = Pl_GetSpellCost(pl,spell);
    if (lVar3 < 1) {
      sVar2 = -1;
    }
    else {
      lVar3 = Pl_GetSpellCost(pl,spell);
      sVar2 = -(short)lVar3;
    }
    *(short *)((pl->env2).Obj.primitive_top.Data + 0xe) = sVar1 + sVar2;
  }
  Task_EventExec(Overlay_Handle,Overlay_Handle->event_msg | 0x10,Overlay_Handle->event_param);
  lVar3 = Pl_GetSpellLevel(pl,spell,(long *)0x0);
  lVar4 = PSpell_TestSelection(pl,spell);
  (*(&PSpells)[spell].function)(pl,lVar3 + lVar4 + 1);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ PSpell_TestSelection(struct _PLAYER *pl /*$s1*/, long spell /*$a1*/)
 // line 89, offset 0x80040fd8
	/* begin block 1 */
		// Start line: 90
		// Start offset: 0x80040FD8
		// Variables:
	// 		long i; // $a0
	// 		long element; // $s0
	/* end block 1 */
	// End offset: 0x80041074
	// End Line: 113

	/* begin block 2 */
		// Start line: 181
	/* end block 2 */
	// End Line: 182

long PSpell_TestSelection(_PLAYER *pl,long spell)

{
  byte bVar1;
  long lVar2;
  long lVar3;
  _PLAYER *p_Var4;
  int iVar5;
  uint uVar6;
  
  uVar6 = (uint)(byte)(&PSpells)[spell].element;
  lVar2 = Pl_GetSpellLevel(pl,spell,(long *)0x0);
  lVar3 = 0;
  if (lVar2 < 3) {
    iVar5 = 0;
    p_Var4 = pl;
    do {
      bVar1 = *(byte *)&(p_Var4->env2).Obj.n_normal;
      if (((bVar1 & 0x80) != 0) || ((uint)(byte)(&PSpells)[(uint)bVar1 & 0x3f].element != uVar6)) {
        uVar6 = 0xffffffff;
        break;
      }
      iVar5 = iVar5 + 1;
      p_Var4 = (_PLAYER *)((int)&(pl->obj).next + iVar5);
    } while (iVar5 < 4);
    lVar3 = 1;
    if ((int)uVar6 < 0) {
      lVar3 = 0;
    }
  }
  return lVar3;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PSpell_LongSpell(struct _PLAYER *pl /*$s0*/, long spell /*$s1*/, long level /*$s2*/, long time /*$s3*/)
 // line 116, offset 0x8004108c
	/* begin block 1 */
		// Start line: 250
	/* end block 1 */
	// End Line: 251

void PSpell_LongSpell(_PLAYER *pl,long spell,long level,long time)

{
  if (-1 < (char)(pl->env2).Obj.primitive_top.Data[4]) {
    PSpell_EndSpell(pl);
    *(undefined4 *)(*(int *)(pl->env2).Obj.primitive_top.Data + 0x28) = 1;
  }
  (pl->env2).Obj.primitive_top.Data[4] = (byte)spell;
  (pl->env2).Obj.primitive_top.Data[5] = (byte)level;
  *(short *)((pl->env2).Obj.primitive_top.Data + 6) = (short)time;
  PSpell_RestoreSpell(pl);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PSpell_RestoreSpell(struct _PLAYER *pl /*$s0*/)
 // line 133, offset 0x80041104
	/* begin block 1 */
		// Start line: 134
		// Start offset: 0x80041104
		// Variables:
	// 		struct TASK *t; // $v0
	// 		void (*task)(); // $a1
	/* end block 1 */
	// End offset: 0x80041198
	// End Line: 154

	/* begin block 2 */
		// Start line: 288
	/* end block 2 */
	// End Line: 289

void PSpell_RestoreSpell(_PLAYER *pl)

{
  byte bVar1;
  TASK *pTVar2;
  code *f;
  
  bVar1 = (pl->env2).Obj.primitive_top.Data[4];
  if (-1 < (char)bVar1) {
    if (bVar1 == 6) {
      f = Air_GhostTask;
    }
    else {
      if ((char)bVar1 < '\a') {
        if (bVar1 == 3) {
          f = Earth_MegaBlastTask;
        }
      }
      else {
        if (bVar1 == 0xb) {
          f = Fire_ShieldTask;
        }
      }
    }
    pTVar2 = Task_Link(f,0x400);
    *(_PLAYER **)&pTVar2->s0 = pl;
    bVar1 = (pl->env2).Obj.primitive_top.Data[5];
    pTVar2->local = (void *)0x0;
    pTVar2->s1 = (int)(char)bVar1;
    *(TASK **)(pl->env2).Obj.primitive_top.Data = pTVar2;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PSpell_EndSpell(struct _PLAYER *pl /*$a0*/)
 // line 157, offset 0x800411a8
	/* begin block 1 */
		// Start line: 159
		// Start offset: 0x800411A8
		// Variables:
	// 		long i; // $a1
	/* end block 1 */
	// End offset: 0x80041214
	// End Line: 179

	/* begin block 2 */
		// Start line: 340
	/* end block 2 */
	// End Line: 341

/* WARNING: Type propagation algorithm not settling */

void PSpell_EndSpell(_PLAYER *pl)

{
  byte bVar1;
  code *pcVar2;
  _PLAYER *p_Var3;
  code *pcVar4;
  int iVar5;
  
  bVar1 = (pl->env2).Obj.primitive_top.Data[4];
  if (bVar1 == 3) {
    iVar5 = 0;
    p_Var3 = pl;
    do {
      iVar5 = iVar5 + 1;
      (p_Var3->env1).Obj.primitive_top.Data[0x1c] = (p_Var3->env1).Obj.primitive_top.Data[0x1d];
      p_Var3 = (_PLAYER *)&(p_Var3->obj).child;
    } while (iVar5 < 4);
    pcVar4 = *(code **)&(pl->m_obj).Env.Data;
    pcVar2 = Motion2D_ManimVampire;
  }
  else {
    if (bVar1 != 6) goto LAB_80041218;
    pcVar4 = *(code **)&(pl->m_obj).Env.Data;
    pcVar2 = Motion2D_ManimGhost;
  }
  if (pcVar4 == pcVar2) {
    *(undefined2 *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x20) = 0x80;
  }
LAB_80041218:
  (pl->env2).Obj.primitive_top.Data[4] = 0xff;
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ PSpell_GetTargets(struct _PLAYER *pl /*$s2*/, long spell /*$s0*/, struct _D3_OBJECT **targets /*$s3*/)
 // line 189, offset 0x80041220
	/* begin block 1 */
		// Start line: 190
		// Start offset: 0x80041220
		// Variables:
	// 		long n; // $v0
	// 		long p; // $a2
	// 		long a; // $t0
	// 		long level; // $s1
	/* end block 1 */
	// End offset: 0x80041320
	// End Line: 229

	/* begin block 2 */
		// Start line: 403
	/* end block 2 */
	// End Line: 404

long PSpell_GetTargets(_PLAYER *pl,long spell,_D3_OBJECT **targets)

{
  long dist_max;
  long lVar1;
  int iVar2;
  int local_20;
  
  dist_max = Pl_GetSpellLevel(pl,spell,(long *)0x0);
  lVar1 = PSpell_TestSelection(pl,spell);
  iVar2 = 0;
  local_20 = dist_max + lVar1 + 1;
  switch(spell) {
  case 2:
    iVar2 = 0x5dc;
  case 0x10:
    dist_max = iVar2 + 500 + (local_20 + -1) * 300;
    break;
  default:
    *(_PLAYER **)targets = pl;
    dist_max = 1;
    goto LAB_80041320;
  case 5:
  case 9:
    iVar2 = -500;
  case 10:
  case 0xf:
    local_20 = 1;
    dist_max = iVar2 + 2000;
    break;
  case 0xc:
    local_20 = (int)(local_20 + 1U + (local_20 + 1U >> 0x1f)) >> 1;
    dist_max = 0x9c4;
  }
  dist_max = PSpell_SeekTargets(pl,targets,dist_max,0x400,local_20);
LAB_80041320:
  PSpell_nTargets = (short)dist_max;
  return dist_max;
}



// decompiled code
// original method signature: 
// long /*$ra*/ PSpell_SeekTargets(struct _PLAYER *pl /*$s3*/, struct _D3_OBJECT **ot /*$s6*/, long dist_max /*$s4*/, long dir_max /*$s5*/, long n_max /*stack 16*/)
 // line 234, offset 0x80041340
	/* begin block 1 */
		// Start line: 235
		// Start offset: 0x80041340
		// Variables:
	// 		long i; // $s2
	// 		long j; // $s0
	/* end block 1 */
	// End offset: 0x800413E8
	// End Line: 253

	/* begin block 2 */
		// Start line: 502
	/* end block 2 */
	// End Line: 503

long PSpell_SeekTargets(_PLAYER *pl,_D3_OBJECT **ot,long dist_max,long dir_max,long n_max)

{
  _D3_OBJECT *o;
  _D3_OBJECT **pp_Var1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  pp_Var1 = ot;
  if (0 < n_max) {
    do {
      o = D3_SeekLookTarget((_D3_OBJECT *)pl,dir_max,dist_max,(long)&DAT_00008010);
      *pp_Var1 = o;
      if (o == (_D3_OBJECT *)0x0) break;
      D3_ClearCollBits(o,0x10);
      iVar3 = iVar3 + 1;
      pp_Var1 = pp_Var1 + 1;
    } while (iVar3 < n_max);
  }
  iVar2 = 0;
  if (0 < iVar3) {
    do {
      o = *ot;
      ot = ot + 1;
      iVar2 = iVar2 + 1;
      D3_SetCollBits(o,0x10);
    } while (iVar2 < iVar3);
  }
  return iVar3;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PSpell_Effect(struct _PLAYER *pl /*$s0*/, long spell /*$s2*/, long start /*$s1*/)
 // line 266, offset 0x80041414
	/* begin block 1 */
		// Start line: 267
		// Start offset: 0x80041414

		/* begin block 1.1 */
			// Start line: 271
			// Start offset: 0x80041458
			// Variables:
		// 		struct P_SPELL_7fake pos; // stack offset -32
		// 		struct P_SPELL_8fake color; // stack offset -24
		/* end block 1.1 */
		// End offset: 0x800414EC
		// End Line: 287

		/* begin block 1.2 */
			// Start line: 292
			// Start offset: 0x80041514
		/* end block 1.2 */
		// End offset: 0x80041524
		// End Line: 297
	/* end block 1 */
	// End offset: 0x80041524
	// End Line: 298

	/* begin block 2 */
		// Start line: 579
	/* end block 2 */
	// End Line: 580

void PSpell_Effect(_PLAYER *pl,long spell,long start)

{
  TASK *pTVar1;
  
  if (start == 0) {
    if ((&PSpells)[spell].effect == 0) {
      SFX_StreamCone(0xe0,(char)pl + '<',0xe8);
    }
  }
  else {
    if ((&PSpells)[spell].effect == 1) {
      pTVar1 = Task_Link(PSpell_EffectTask,0x180);
      *(_PLAYER **)&pTVar1->s0 = pl;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PSpell_EffectTask()
 // line 301, offset 0x8004153c
	/* begin block 1 */
		// Start line: 302
		// Start offset: 0x8004153C
		// Variables:
	// 		struct _PSPELL_CIRCLE *pc; // $s1
	// 		struct _PLAYER *pl; // $s2
	// 		long i; // $a1
	/* end block 1 */
	// End offset: 0x80041710
	// End Line: 354

	/* begin block 2 */
		// Start line: 654
	/* end block 2 */
	// End Line: 655

/* WARNING: Unknown calling convention yet parameter storage is locked */

void PSpell_EffectTask(void)

{
  void *pvVar1;
  TASK *pTVar2;
  TASK *pTVar3;
  undefined uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  TASK *pTVar8;
  int iVar9;
  
  pTVar2 = TaskCurrent;
  pTVar3 = TaskCurrent + 1;
  iVar9 = TaskCurrent->s0;
  pTVar8 = TaskCurrent + 1;
  *(undefined *)((int)&TaskCurrent[1].event_s3 + 2) = 0x80;
  *(undefined *)((int)&pTVar2[1].event_s3 + 1) = 0x80;
  *(undefined *)&pTVar2[1].event_s3 = 0x80;
  pvVar1 = Pl_Pcl;
  pTVar2[1].event_s4 = iVar9;
  pTVar2[1].prec = pvVar1;
  pTVar2[1].child = pvVar1;
  *(undefined2 *)&pTVar2[1].bprec = 0x26;
  RotMatrixZYX((short *)(iVar9 + 0x3c),(undefined2 *)&pTVar3->event_msg);
  iVar7 = 0;
  pTVar3 = pTVar8;
  do {
    iVar6 = 0;
    iVar5 = iVar7;
    do {
      *(undefined2 *)((int)&pTVar8->exec + iVar5) = 0x32;
      iVar6 = iVar6 + 1;
      iVar5 = iVar5 + 8;
    } while (iVar6 < 4);
    if (pTVar3 == pTVar8) {
      *(undefined2 *)((int)&pTVar3->exec + 2) = 0xffc4;
      *(undefined2 *)((int)&pTVar3->display + 2) = 0x3c;
      *(undefined2 *)((int)&pTVar3->local + 2) = 0xffc4;
      *(undefined2 *)((int)&pTVar3->s1 + 2) = 0x3c;
    }
    else {
      *(undefined2 *)((int)&pTVar3->exec + 2) = 0;
      *(undefined2 *)((int)&pTVar3->display + 2) = 0;
      *(undefined2 *)((int)&pTVar3->local + 2) = 0;
      *(undefined2 *)((int)&pTVar3->s1 + 2) = 0;
    }
    *(undefined2 *)&pTVar3->sp = 0xbe;
    *(undefined2 *)&pTVar3->destructor = 0xbe;
    *(undefined2 *)&pTVar3->s0 = 0x46;
    *(undefined2 *)&pTVar3->s2 = 0x46;
    pTVar3 = (TASK *)&pTVar3->display;
    iVar7 = iVar7 + 0x20;
  } while ((int)pTVar3 < (int)&pTVar2[1].s5);
  Fx_Play(0x2f,(char)iVar9 + ',');
  Task_Sleep(0xb);
  TaskCurrent->display = PSpell_EffectTaskDisplay;
  *(undefined2 *)&pTVar2[1].next = 0x14;
  do {
    iVar7 = (uint)*(byte *)&pTVar2[1].event_s3 - 6;
    uVar4 = (undefined)iVar7;
    *(short *)((int)&pTVar2[1].s5 + 2) = *(short *)((int)&pTVar2[1].s5 + 2) + 0x14;
    *(short *)((int)&pTVar2[1].s3 + 2) = *(short *)((int)&pTVar2[1].s3 + 2) + -0x14;
    *(short *)((int)&pTVar2[1].text_context + 2) =
         *(short *)((int)&pTVar2[1].text_context + 2) + 0x14;
    *(short *)((int)&pTVar2[1].s7 + 2) = *(short *)((int)&pTVar2[1].s7 + 2) + -0x14;
    if (iVar7 < 0) {
      uVar4 = 0;
    }
    *(undefined *)((int)&pTVar2[1].event_s3 + 2) = uVar4;
    *(undefined *)((int)&pTVar2[1].event_s3 + 1) = uVar4;
    *(undefined *)&pTVar2[1].event_s3 = uVar4;
    Task_Next();
    if (Scr_Frame != 0) {
      *(short *)&pTVar2[1].next = *(short *)&pTVar2[1].next + 1;
    }
  } while (*(short *)&pTVar2[1].next < 0x23);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PSpell_EffectTaskDisplay()
 // line 357, offset 0x80041728
	/* begin block 1 */
		// Start line: 358
		// Start offset: 0x80041728
		// Variables:
	// 		struct _PSPELL_CIRCLE *pc; // $s3
	// 		struct P_SPELL_31fake *p; // $s0
	// 		long z; // $s2
	/* end block 1 */
	// End offset: 0x80041A14
	// End Line: 409

	/* begin block 2 */
		// Start line: 829
	/* end block 2 */
	// End Line: 830

/* WARNING: Unknown calling convention yet parameter storage is locked */

void PSpell_EffectTaskDisplay(void)

{
  long lVar1;
  void *pvVar2;
  TASK *pTVar3;
  _TMD_2D *p_Var4;
  _SCREEN *p_Var5;
  undefined4 in_zero;
  undefined4 in_at;
  short sVar6;
  int iVar7;
  int iVar8;
  TASK *shp;
  
  pTVar3 = TaskCurrent;
  shp = TaskCurrent + 1;
  setCopReg(2,in_zero,*(undefined4 *)(TaskCurrent[1].event_s4 + 0x2c));
  setCopReg(2,in_at,*(undefined4 *)(TaskCurrent[1].event_s4 + 0x30));
  copFunction(2,0x486012);
  lVar1 = getCopReg(2,0x19);
  TaskCurrent[1].event_s0 = lVar1;
  lVar1 = getCopReg(2,0x1a);
  pTVar3[1].event_s1 = lVar1;
  lVar1 = getCopReg(2,0x1b);
  pTVar3[1].event_s2 = lVar1;
  pTVar3[1].event_s0 = pTVar3[1].event_s0 + Cam_Matrix.t[0];
  pTVar3[1].event_s1 = pTVar3[1].event_s1 + Cam_Matrix.t[1];
  pTVar3[1].event_s2 = pTVar3[1].event_s2 + Cam_Matrix.t[2];
  setCopControlWord(2,0x2800,pTVar3[1].event_s0);
  setCopControlWord(2,0x3000,pTVar3[1].event_s1);
  setCopControlWord(2,0x3800,pTVar3[1].event_s2);
  SetMulMatrix((undefined4 *)&Cam_Matrix,(ushort *)&pTVar3[1].event_msg);
  GtxTmd_RotTransPersN(&pTVar3[1].exec,Tmd_2DSpeed,8);
  pvVar2 = Main_Prims;
  sVar6 = Tmd_2DSpeed[1].vz;
  if (Tmd_2DSpeed->vz < Tmd_2DSpeed[1].vz) {
    sVar6 = Tmd_2DSpeed->vz;
  }
  iVar7 = (int)Tmd_2DSpeed[2].vz;
  if ((int)sVar6 < (int)Tmd_2DSpeed[2].vz) {
    iVar7 = (int)sVar6;
  }
  iVar8 = (int)Tmd_2DSpeed[3].vz;
  if (iVar7 < (int)Tmd_2DSpeed[3].vz) {
    iVar8 = iVar7;
  }
  if (iVar8 < 0) {
    iVar8 = iVar8 + 3;
  }
  iVar8 = iVar8 >> 2;
  if ((iVar8 != 0) && (iVar8 < (int)Scr_OtSize)) {
    Shp_SetPolyFT4((SHAPE_31fake *)Main_Prims,(SHAPE_68fake *)shp,0,0);
    *(undefined *)((int)pvVar2 + 4) = 0x50;
    *(undefined *)((int)pvVar2 + 5) = 10;
    *(undefined *)((int)pvVar2 + 6) = 100;
    *(byte *)((int)pvVar2 + 7) = *(byte *)((int)pvVar2 + 7) & 0xfe;
    p_Var4 = Tmd_2DSpeed;
    *(undefined4 *)((int)pvVar2 + 8) = *(undefined4 *)Tmd_2DSpeed;
    *(undefined4 *)((int)pvVar2 + 0x10) = *(undefined4 *)(p_Var4 + 1);
    *(undefined4 *)((int)pvVar2 + 0x18) = *(undefined4 *)(p_Var4 + 2);
    *(undefined4 *)((int)pvVar2 + 0x20) = *(undefined4 *)(p_Var4 + 3);
    Shp_SetPolyFT4((SHAPE_31fake *)((int)pvVar2 + 0x28),(SHAPE_68fake *)&pTVar3[1].child,0,0);
    *(byte *)((int)pvVar2 + 0x2f) = *(byte *)((int)pvVar2 + 0x2f) & 0xfe;
    *(undefined *)((int)pvVar2 + 0x2c) = *(undefined *)&pTVar3[1].event_s3;
    *(undefined *)((int)pvVar2 + 0x2d) = *(undefined *)((int)&pTVar3[1].event_s3 + 1);
    *(undefined *)((int)pvVar2 + 0x2e) = *(undefined *)((int)&pTVar3[1].event_s3 + 2);
    p_Var4 = Tmd_2DSpeed;
    *(undefined4 *)((int)pvVar2 + 0x30) = *(undefined4 *)(Tmd_2DSpeed + 4);
    *(undefined4 *)((int)pvVar2 + 0x38) = *(undefined4 *)(p_Var4 + 5);
    *(undefined4 *)((int)pvVar2 + 0x40) = *(undefined4 *)(p_Var4 + 6);
    *(undefined4 *)((int)pvVar2 + 0x48) = *(undefined4 *)(p_Var4 + 7);
    p_Var5 = Scr;
    *(uint *)pvVar2 = *(uint *)pvVar2 & 0xff000000 | Scr->ot[iVar8] & 0xffffff;
    p_Var5->ot[iVar8] = p_Var5->ot[iVar8] & 0xff000000 | (uint)pvVar2 & 0xffffff;
    *(uint *)((int)pvVar2 + 0x28) =
         *(uint *)((int)pvVar2 + 0x28) & 0xff000000 | p_Var5->ot[iVar8] & 0xffffff;
    Main_Prims = (void *)((int)pvVar2 + 0x50);
    p_Var5->ot[iVar8] =
         p_Var5->ot[iVar8] & 0xff000000 | (uint)(SHAPE_31fake *)((int)pvVar2 + 0x28) & 0xffffff;
  }
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
// void /*$ra*/ Earth_Healing(struct _PLAYER *pl /*$s1*/, long level /*$s0*/)
 // line 424, offset 0x80041a7c
	/* begin block 1 */
		// Start line: 425
		// Start offset: 0x80041A7C
		// Variables:
	// 		struct TASK *t; // $v0
	/* end block 1 */
	// End offset: 0x80041A7C
	// End Line: 425

	/* begin block 2 */
		// Start line: 1006
	/* end block 2 */
	// End Line: 1007

void Earth_Healing(_PLAYER *pl,long level)

{
  TASK *pTVar1;
  
  pTVar1 = Task_Link(Earth_HealManaTask,0x100);
  *(_PLAYER **)&pTVar1->s0 = pl;
  pTVar1->s1 = level * 10;
  pTVar1->s2 = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Earth_Mana(struct _PLAYER *pl /*$s1*/, long level /*$s0*/)
 // line 436, offset 0x80041ad0
	/* begin block 1 */
		// Start line: 437
		// Start offset: 0x80041AD0
		// Variables:
	// 		struct TASK *t; // $v0
	/* end block 1 */
	// End offset: 0x80041AD0
	// End Line: 437

	/* begin block 2 */
		// Start line: 1035
	/* end block 2 */
	// End Line: 1036

void Earth_Mana(_PLAYER *pl,long level)

{
  TASK *pTVar1;
  
  pTVar1 = Task_Link(Earth_HealManaTask,0x100);
  pTVar1->s1 = level * 5;
  *(_PLAYER **)&pTVar1->s0 = pl;
  pTVar1->s2 = 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Earth_Minimize(struct _PLAYER *pl /*$s0*/, long level /*$s1*/)
 // line 448, offset 0x80041b24
	/* begin block 1 */
		// Start line: 449
		// Start offset: 0x80041B24
		// Variables:
	// 		struct TASK *t; // $v0
	/* end block 1 */
	// End offset: 0x80041B24
	// End Line: 449

	/* begin block 2 */
		// Start line: 1065
	/* end block 2 */
	// End Line: 1066

void Earth_Minimize(_PLAYER *pl,long level)

{
  TASK *pTVar1;
  
  pTVar1 = Task_Link(Earth_MinimizeTask,0x400);
  *(_PLAYER **)&pTVar1->s0 = pl;
  pTVar1->s1 = level;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Earth_MegaBlast(struct _PLAYER *pl /*$a0*/, long level /*$a2*/)
 // line 459, offset 0x80041b68
	/* begin block 1 */
		// Start line: 1091
	/* end block 1 */
	// End Line: 1092

void Earth_MegaBlast(_PLAYER *pl,long level)

{
  PSpell_LongSpell(pl,3,level,(int)Scr_TicksPerSecond * 10);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Earth_MegaBlastTask()
 // line 466, offset 0x80041ba0
	/* begin block 1 */
		// Start line: 467
		// Start offset: 0x80041BA0
		// Variables:
	// 		struct _PLAYER *pl; // $s0
	// 		long level; // $a2
	// 		long i; // $a1
	// 		long snd; // $s2
	/* end block 1 */
	// End offset: 0x80041D1C
	// End Line: 515

	/* begin block 2 */
		// Start line: 1116
	/* end block 2 */
	// End Line: 1117

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Earth_MegaBlastTask(void)

{
  char cVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = TaskCurrent->s0;
  iVar6 = TaskCurrent->s1;
  if ((int)*(short *)(iVar7 + 0x1f6) == (int)Scr_TicksPerSecond * 10) {
    iVar5 = 0;
    iVar4 = iVar7;
    do {
      *(char *)(iVar4 + 0x1ad) = *(char *)(iVar4 + 0x1ac);
      if ((int)*(char *)(iVar4 + 0x1ac) + iVar6 < 10) {
        cVar1 = *(char *)(iVar4 + 0x1ac) + (char)iVar6;
      }
      else {
        cVar1 = '\t';
      }
      *(char *)(iVar4 + 0x1ac) = cVar1;
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 8;
    } while (iVar5 < 4);
  }
  sVar2 = Fx_Play(0x26,0);
  sVar3 = *(short *)(iVar7 + 0x1f6) + -1;
  *(short *)(iVar7 + 0x1f6) = sVar3;
  while( true ) {
    if (sVar3 == -1) {
      iVar4 = 0;
      iVar6 = iVar7;
      do {
        iVar4 = iVar4 + 1;
        *(undefined *)(iVar6 + 0x1ac) = *(undefined *)(iVar6 + 0x1ad);
        iVar6 = iVar6 + 8;
      } while (iVar4 < 4);
      Sound_Stop((int)sVar2,0);
      Fx_Play(0x27,(char)iVar7 + ',');
      *(undefined2 *)(iVar7 + 0xc4) = 0x80;
      *(undefined *)(iVar7 + 500) = 0xff;
      return;
    }
    if (*(code **)(iVar7 + 0xd4) != Motion2D_ManimVampire) {
      Manim_SetEffect((M_OBJECT *)(iVar7 + 0xa4),Motion2D_ManimVampire);
    }
    if (TaskCurrent->local != (void *)0x0) break;
    Task_Next();
    sVar3 = *(short *)(iVar7 + 0x1f6) + -1;
    *(short *)(iVar7 + 0x1f6) = sVar3;
  }
  Sound_Stop((int)sVar2,0);
  Fx_Play(0x27,0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Earth_MinimizeTask()
 // line 518, offset 0x80041d34
	/* begin block 1 */
		// Start line: 519
		// Start offset: 0x80041D34
		// Variables:
	// 		struct _D3_OBJECT (*ot[4]); // stack offset -96
	// 		struct _MONSTER *monst; // $a1
	// 		struct M_OBJECT *mo; // $s0
	// 		long i; // $s3
	// 		long j; // $s4
	// 		long level; // $s5
	// 		long times[4]; // stack offset -80
	// 		long powers[4]; // stack offset -64
	// 		long resist; // $v1
	/* end block 1 */
	// End offset: 0x80042050
	// End Line: 608

	/* begin block 2 */
		// Start line: 1233
	/* end block 2 */
	// End Line: 1234

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Earth_MinimizeTask(void)

{
  uint uVar1;
  ulong uVar2;
  byte bVar3;
  int iVar4;
  _D3_OBJECT *D3Obj;
  int iVar5;
  int iVar6;
  code *f;
  void *pvVar7;
  M_OBJECT *mo;
  _D3_OBJECT **pp_Var8;
  int iVar9;
  int iVar10;
  int iVar11;
  _D3_OBJECT *local_60 [4];
  int local_50 [4];
  uint local_40 [4];
  _D3_OBJECT **local_30;
  
  iVar11 = (int)PSpell_nTargets;
  iVar10 = 0;
  if (0 < iVar11) {
    pp_Var8 = local_60;
    iVar9 = 0;
    do {
      D3Obj = *(_D3_OBJECT **)((int)&PSpell_Targets4 + iVar9);
      *pp_Var8 = D3Obj;
      pvVar7 = D3Obj->description;
      if ((*(int *)((int)pvVar7 + 0x10) == 0) &&
         (uVar2 = MSpell_TestAppliedOnObject(D3Obj,2), uVar2 != 0)) {
        if (uVar2 == 2) {
          iVar4 = (int)Scr_TicksPerSecond * 5;
        }
        else {
          if ((int)uVar2 < 3) {
            if (uVar2 == 1) {
              uVar1 = (int)Scr_TicksPerSecond * 5;
LAB_80041e30:
              iVar4 = (int)(uVar1 + (uVar1 >> 0x1f)) >> 1;
              goto LAB_80041e58;
            }
          }
          else {
            if (uVar2 == 3) {
              uVar1 = (int)Scr_TicksPerSecond * 0xf;
              goto LAB_80041e30;
            }
          }
          iVar4 = (int)Scr_TicksPerSecond * 10;
        }
LAB_80041e58:
        *(int *)((int)local_50 + iVar9) = iVar4;
        *(undefined4 *)((int)pvVar7 + 0x10) = 0x1000;
        *(uint *)((int)local_40 + iVar9) = (uint)(*pp_Var8)->hit_power;
        bVar3 = (*pp_Var8)->hit_power >> 1;
        if (bVar3 == 0) {
          bVar3 = 1;
        }
        (*pp_Var8)->hit_power = bVar3;
        Fx_Play(0x2b,(char)*pp_Var8 + ',');
      }
      else {
        *pp_Var8 = (_D3_OBJECT *)0x0;
      }
      pp_Var8 = pp_Var8 + 1;
      iVar10 = iVar10 + 1;
      iVar9 = iVar9 + 4;
    } while (iVar10 < iVar11);
  }
  iVar10 = 0;
  local_30 = local_60;
  do {
    iVar9 = 0;
    if (0 < iVar11) {
      iVar4 = 0;
      pp_Var8 = local_30;
      do {
        D3Obj = *pp_Var8;
        if (D3Obj != (_D3_OBJECT *)0x0) {
          mo = (M_OBJECT *)D3Obj->description;
          iVar6 = *(int *)&D3Obj[1].last_pos;
          if (iVar10 < *(int *)((int)local_50 + iVar4)) {
            iVar5 = *(int *)&(mo->Sq).Data.Flag + -0x40;
            if (iVar5 < 0xb00) {
              iVar5 = 0xb00;
            }
            *(int *)&(mo->Sq).Data.Flag = iVar5;
            *(uint *)(iVar6 + 8) = *(uint *)(iVar6 + 8) | 0x183100;
          }
          else {
            D3Obj->hit_power = *(uchar *)((int)local_40 + iVar4);
            *(long *)(iVar6 + 8) = Monster_ActionTabel[(int)*(short *)(iVar6 + 0x12) * 2];
            if (*(int *)&(mo->Sq).Data.Flag == 0xb00) {
              Fx_Play(0x2a,(char)*pp_Var8 + ',');
            }
            iVar6 = *(int *)&(mo->Sq).Data.Flag;
            if ((iVar6 == 0) || (iVar5 = iVar6 + 0x80, 0xfff < iVar6)) {
              *(undefined4 *)&(mo->Sq).Data.Flag = 0;
              *pp_Var8 = (_D3_OBJECT *)0x0;
            }
            else {
              if (0x1000 < iVar5) {
                iVar5 = 0x1000;
              }
              *(int *)&(mo->Sq).Data.Flag = iVar5;
            }
          }
          iVar6 = *(int *)&(mo->Sq).Data.Flag;
          if (((iVar6 == 0) || (iVar6 == 0xb00)) || (iVar6 == 0x1000)) {
            if ((code *)(mo->Env).Obj.n_normal == Motion2D_ManimMagic) {
              f = (TDRFuncPtr_Manim_SetEffect1f)0x0;
              goto LAB_80042020;
            }
          }
          else {
            if ((mo->Env).Obj.n_normal == 0) {
              f = Motion2D_ManimMagic;
LAB_80042020:
              Manim_SetEffect(mo,f);
            }
          }
        }
        pp_Var8 = pp_Var8 + 1;
        iVar9 = iVar9 + 1;
        iVar4 = iVar4 + 4;
      } while (iVar9 < iVar11);
    }
    iVar10 = iVar10 + 1;
    Task_Next();
    if (0x14b < iVar10) {
      return;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Earth_HealManaTask()
 // line 611, offset 0x80042080
	/* begin block 1 */
		// Start line: 612
		// Start offset: 0x80042080
		// Variables:
	// 		struct _PLAYER *pl; // $s0
	// 		long i; // $s1
	// 		long gain; // $s4
	// 		long type; // $s3
	/* end block 1 */
	// End offset: 0x800421C8
	// End Line: 659

	/* begin block 2 */
		// Start line: 1552
	/* end block 2 */
	// End Line: 1553

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Earth_HealManaTask(void)

{
  TASK *t;
  undefined2 uVar1;
  int iVar2;
  uint type;
  long param;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = TaskCurrent->s0;
  iVar5 = TaskCurrent->s1;
  iVar4 = TaskCurrent->s2;
  Fx_Play(0x3b,(char)iVar3 + ',');
  t = Overlay_Handle;
  if (iVar4 != 0) {
    _uVar1 = (int)*(short *)(iVar3 + 0x20) + -10;
    uVar1 = (undefined2)_uVar1;
    if (_uVar1 < 1) {
      uVar1 = 1;
    }
    *(undefined2 *)(iVar3 + 0x20) = uVar1;
    Task_EventExec(t,t->event_msg | 4,t->event_param);
  }
  _uVar1 = 0;
  if (0 < iVar5) {
    do {
      t = Overlay_Handle;
      if (iVar4 == 0) {
        iVar2 = (int)*(short *)(iVar3 + 0x20) + 1;
        uVar1 = (undefined2)iVar2;
        if (100 < iVar2) {
          uVar1 = 100;
        }
        *(undefined2 *)(iVar3 + 0x20) = uVar1;
        param = t->event_param;
        type = t->event_msg | 4;
      }
      else {
        type = (uint)*(ushort *)(iVar3 + 0x1fe) + 1;
        uVar1 = (undefined2)type;
        if (100 < type) {
          uVar1 = 100;
        }
        *(undefined2 *)(iVar3 + 0x1fe) = uVar1;
        param = t->event_param;
        type = t->event_msg | 0x10;
      }
      Task_EventExec(t,type,param);
      if (*(code **)(iVar3 + 0xd4) != Motion2D_ManimVampire) {
        Manim_SetEffect((M_OBJECT *)(iVar3 + 0xa4),Motion2D_ManimVampire);
      }
      _uVar1 = _uVar1 + 1;
      Task_Next();
    } while (_uVar1 < iVar5);
  }
  if (*(code **)(iVar3 + 0xd4) == Motion2D_ManimVampire) {
    *(undefined2 *)(iVar3 + 0xc4) = 0x80;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Air_Teleport(struct _PLAYER *pl /*$s0*/, long level /*$a1*/)
 // line 672, offset 0x800421e8
	/* begin block 1 */
		// Start line: 1709
	/* end block 1 */
	// End Line: 1710

void Air_Teleport(_PLAYER *pl,long level)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)&(pl->m_obj).shadow.u0;
  (pl->env2).Obj.primitive_top.olen = '\x01';
  *(ushort *)&(pl->m_obj).shadow.u0 = uVar1 | 4;
  Fx_Play(0x2a,(char)pl + ',');
  Task_Link(Paf_TeleportEffectTask,0x200);
  Task_Sleep(0xe);
  (pl->obj).display_mode = (pl->obj).display_mode & 0xffef;
  Pl_ForceAction(pl,1,0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Air_Ghost(struct _PLAYER *pl /*$a0*/, long level /*$a2*/)
 // line 691, offset 0x8004225c
	/* begin block 1 */
		// Start line: 1760
	/* end block 1 */
	// End Line: 1761

void Air_Ghost(_PLAYER *pl,long level)

{
  PSpell_LongSpell(pl,6,level,(int)Scr_TicksPerSecond * level * 10);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Air_Lightning(struct _PLAYER *pl /*$s0*/, long level /*$s1*/)
 // line 698, offset 0x8004229c
	/* begin block 1 */
		// Start line: 699
		// Start offset: 0x8004229C
		// Variables:
	// 		struct TASK *t; // $v0
	/* end block 1 */
	// End offset: 0x8004229C
	// End Line: 699

	/* begin block 2 */
		// Start line: 1776
	/* end block 2 */
	// End Line: 1777

void Air_Lightning(_PLAYER *pl,long level)

{
  _D3_OBJECT *p_Var1;
  TASK *pTVar2;
  
  pTVar2 = Task_Link(Air_LightningTask,0x4a4);
  *(_PLAYER **)&pTVar2->s0 = pl;
  p_Var1 = PSpell_Targets4;
  pTVar2->s2 = level;
  *(_D3_OBJECT **)&pTVar2->s1 = p_Var1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Air_Twister(struct _PLAYER *pl /*$s0*/, long level /*$s1*/)
 // line 709, offset 0x800422e8
	/* begin block 1 */
		// Start line: 710
		// Start offset: 0x800422E8
		// Variables:
	// 		struct TASK *t; // $v0
	/* end block 1 */
	// End offset: 0x800422E8
	// End Line: 710

	/* begin block 2 */
		// Start line: 1802
	/* end block 2 */
	// End Line: 1803

void Air_Twister(_PLAYER *pl,long level)

{
  _D3_OBJECT *p_Var1;
  TASK *pTVar2;
  
  pTVar2 = Task_Link(Air_TwisterTask,0x300);
  *(_PLAYER **)&pTVar2->s0 = pl;
  p_Var1 = PSpell_Targets4;
  pTVar2->s2 = level;
  *(_D3_OBJECT **)&pTVar2->s1 = p_Var1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Air_TwisterTask()
 // line 721, offset 0x80042334
	/* begin block 1 */
		// Start line: 722
		// Start offset: 0x80042334
		// Variables:
	// 		struct _PLAYER *pl; // $s3
	// 		struct _D3_OBJECT *ot; // $s1
	// 		long level; // $s0
	// 		long resist; // $a1

		/* begin block 1.1 */
			// Start line: 748
			// Start offset: 0x800423A4
			// Variables:
		// 		long hits; // $v1
		// 		long effect; // $s2
		/* end block 1.1 */
		// End offset: 0x800424A8
		// End Line: 772
	/* end block 1 */
	// End offset: 0x800424A8
	// End Line: 775

	/* begin block 2 */
		// Start line: 1831
	/* end block 2 */
	// End Line: 1832

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Air_TwisterTask(void)

{
  ulong uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  _D3_OBJECT *ot;
  uint uVar5;
  int iVar6;
  
  ot = (_D3_OBJECT *)TaskCurrent->s1;
  iVar6 = TaskCurrent->s0;
  iVar4 = TaskCurrent->s2;
  Motion2D_Storm(ot,1,(TASK **)0x0);
  Task_Sleep(0x28);
  Motion2D_Twister(ot,0);
  Task_Sleep(0x18);
  uVar1 = MSpell_TestAppliedOnObject(ot,5);
  uVar5 = 0;
  if (uVar1 != 0) {
    uVar3 = (uint)(ushort)ot->hit_points << 0x10;
    iVar2 = (int)uVar3 >> 0x10;
    if (iVar4 == 3) {
      iVar2 = (iVar2 / 3 + (iVar2 >> 0x1f)) - ((int)uVar3 >> 0x1f);
    }
    else {
      if (iVar4 < 4) {
        if (iVar4 == 2) {
          iVar2 = (int)(iVar2 + (uVar3 >> 0x1f)) >> 1;
        }
      }
      else {
        if (iVar4 == 4) {
          if (iVar2 < 0) {
            iVar2 = iVar2 + 3;
          }
          iVar2 = iVar2 >> 2;
        }
      }
    }
    if (uVar1 == 2) {
      iVar2 = iVar2 * 3;
    }
    else {
      if ((int)uVar1 < 3) {
        if (uVar1 == 1) {
          iVar2 = iVar2 << 2;
        }
      }
      else {
        if (uVar1 == 3) {
          iVar2 = iVar2 << 1;
        }
      }
    }
    if ((int)*(short *)(iVar6 + 0x20) <= iVar2) {
      uVar5 = 0x100;
    }
    Fx_Play(0x30,(char)ot + ',');
    MSpell_AppliedOnObject(ot,uVar5 | 5);
  }
  Task_Sleep(0x40);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Air_LightningTask()
 // line 779, offset 0x800424cc
	/* begin block 1 */
		// Start line: 780
		// Start offset: 0x800424CC
		// Variables:
	// 		struct _PLAYER *pl; // $s5
	// 		struct _D3_OBJECT *ot; // $s1
	// 		struct _D3_OBJECT o; // stack offset -216
	// 		struct P_SPELL_7fake pos; // stack offset -48
	// 		struct P_SPELL_7fake posf; // stack offset -40
	// 		long level; // $s4
	// 		long dz; // $s0
	/* end block 1 */
	// End offset: 0x800424CC
	// End Line: 780

	/* begin block 2 */
		// Start line: 1964
	/* end block 2 */
	// End Line: 1965

/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Air_LightningTask(void)

{
  uint uVar1;
  short sVar2;
  _D3_OBJECT *ot;
  long lVar3;
  undefined auStack216 [28];
  short local_bc;
  uchar local_b6;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined local_3f;
  long local_38;
  undefined4 local_30;
  uint local_2c;
  
  ot = (_D3_OBJECT *)TaskCurrent->s1;
  local_38 = TaskCurrent->s0;
  lVar3 = TaskCurrent->s2;
  Motion2D_Storm(ot,0,(TASK **)0x0);
  Task_Sleep(0x30);
  Boxes_GetCenter(ot,0xd8);
  uVar1 = *(uint *)&(ot->pos).vz;
  local_2c._0_2_ = (short)uVar1;
  local_30._0_2_ = (short)*(uint *)&ot->pos;
  sVar2 = *(short *)&ot[1].prec + 100;
  local_2c = uVar1 & 0xffff0000 | (uint)(ushort)((short)local_2c + sVar2);
  local_30 = *(uint *)&ot->pos & 0xffff0000 | (uint)(ushort)((short)local_30 + 200);
  Motion2D_Lightning(0xd0,0xd8,0,-10);
  uVar1 = *(uint *)&(ot->pos).vz;
  local_2c._0_2_ = (short)uVar1;
  local_30._2_2_ = (short)((uint)*(undefined4 *)&ot->pos >> 0x10);
  local_2c = uVar1 & 0xffff0000 | (uint)(ushort)((short)local_2c + sVar2);
  local_30._0_2_ = (short)*(undefined4 *)&ot->pos;
  local_30 = CONCAT22(local_30._2_2_ + 0xad,(short)local_30 + -100);
  Motion2D_Lightning(0xd0,0xd8,0x555,-10);
  uVar1 = *(uint *)&(ot->pos).vz;
  local_2c._0_2_ = (short)uVar1;
  local_30._2_2_ = (short)((uint)*(undefined4 *)&ot->pos >> 0x10);
  local_2c = uVar1 & 0xffff0000 | (uint)(ushort)((short)local_2c + sVar2);
  local_30._0_2_ = (short)*(undefined4 *)&ot->pos;
  local_30 = CONCAT22(local_30._2_2_ + -0xad,(short)local_30 + -100);
  Motion2D_Lightning(0xd0,0xd8,0xaaa,-10);
  Fx_Play(0x34,0xd8);
  Task_Sleep(4);
  D3_SetBox((_D3_OBJECT *)auStack216,-200,-200,0,200,200,300);
  local_ac = *(undefined4 *)&ot->pos;
  local_a8 = *(undefined4 *)&(ot->pos).vz;
  local_bc = 0x2002;
  local_3f = 0xf1;
  local_b6 = (char)lVar3 * '(';
  local_a4 = local_ac;
  local_a0 = local_a8;
  Boxes_TestObject((_D3_OBJECT *)auStack216);
  Task_Sleep(0x4c);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Air_GhostTask()
 // line 829, offset 0x80042704
	/* begin block 1 */
		// Start line: 830
		// Start offset: 0x80042704
		// Variables:
	// 		struct _PLAYER *pl; // $s0
	// 		long snd; // $s1
	/* end block 1 */
	// End offset: 0x800427F8
	// End Line: 863

	/* begin block 2 */
		// Start line: 2097
	/* end block 2 */
	// End Line: 2098

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Air_GhostTask(void)

{
  short sVar1;
  short sVar2;
  int iVar3;
  
  iVar3 = TaskCurrent->s0;
  sVar1 = Fx_Play(0x29,0);
  sVar2 = *(short *)(iVar3 + 0x1f6) + -1;
  *(short *)(iVar3 + 0x1f6) = sVar2;
  while( true ) {
    if (sVar2 == -1) {
      Sound_Stop((int)sVar1,0);
      if (*(code **)(iVar3 + 0xd4) == Motion2D_ManimGhost) {
        *(undefined2 *)(iVar3 + 0xc4) = 0x80;
      }
      *(undefined *)(iVar3 + 500) = 0xff;
      return;
    }
    if (*(code **)(iVar3 + 0xd4) != Motion2D_ManimGhost) {
      Manim_SetEffect((M_OBJECT *)(iVar3 + 0xa4),Motion2D_ManimGhost);
    }
    if (TaskCurrent->local != (void *)0x0) break;
    Task_Next();
    sVar2 = *(short *)(iVar3 + 0x1f6) + -1;
    *(short *)(iVar3 + 0x1f6) = sVar2;
  }
  Sound_Stop((int)sVar1,0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Fire_Rain(struct _PLAYER *pl /*$s0*/, long level /*$s1*/)
 // line 875, offset 0x80042810
	/* begin block 1 */
		// Start line: 876
		// Start offset: 0x80042810
		// Variables:
	// 		struct TASK *t; // $v0
	/* end block 1 */
	// End offset: 0x80042810
	// End Line: 876

	/* begin block 2 */
		// Start line: 2197
	/* end block 2 */
	// End Line: 2198

void Fire_Rain(_PLAYER *pl,long level)

{
  _D3_OBJECT *p_Var1;
  TASK *pTVar2;
  
  pTVar2 = Task_Link(Fire_RainTask,0x200);
  *(_PLAYER **)&pTVar2->s0 = pl;
  p_Var1 = PSpell_Targets4;
  pTVar2->s2 = level;
  *(_D3_OBJECT **)&pTVar2->s1 = p_Var1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Fire_Shield(struct _PLAYER *pl /*$a0*/, long level /*$a2*/)
 // line 886, offset 0x8004285c
	/* begin block 1 */
		// Start line: 887
		// Start offset: 0x8004285C
		// Variables:
	// 		long time_depart; // $a3
	/* end block 1 */
	// End offset: 0x800428A0
	// End Line: 892

	/* begin block 2 */
		// Start line: 2223
	/* end block 2 */
	// End Line: 2224

void Fire_Shield(_PLAYER *pl,long level)

{
  int time;
  
  if (level < 3) {
    time = (int)Scr_TicksPerSecond * 10;
  }
  else {
    time = (int)Scr_TicksPerSecond * 0xf;
  }
  PSpell_LongSpell(pl,0xb,level,time);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Fire_Missile(struct _PLAYER *pl /*$s2*/, long level /*$s0*/)
 // line 896, offset 0x800428b8
	/* begin block 1 */
		// Start line: 897
		// Start offset: 0x800428B8
		// Variables:
	// 		struct P_SPELL_7fake pos; // stack offset -32
	// 		long i; // $s1
	/* end block 1 */
	// End offset: 0x8004298C
	// End Line: 909

	/* begin block 2 */
		// Start line: 2243
	/* end block 2 */
	// End Line: 2244

void Fire_Missile(_PLAYER *pl,long level)

{
  _D3_OBJECT *target;
  _D3_OBJECT **pp_Var1;
  int iVar2;
  
  rcos((int)(pl->obj).rot.vz);
  iVar2 = 0;
  rsin((int)(pl->obj).rot.vz);
  if (0 < PSpell_nTargets) {
    pp_Var1 = &PSpell_Targets4;
    do {
      target = *pp_Var1;
      pp_Var1 = pp_Var1 + 1;
      Motion2D_FireBall((_D3_OBJECT *)pl,target,0xe0,(char)pl + '<',level * 0x28);
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)PSpell_nTargets);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Fire_Works(struct _PLAYER *pl /*$s1*/, long level /*$s2*/)
 // line 912, offset 0x800429a8
	/* begin block 1 */
		// Start line: 913
		// Start offset: 0x800429A8
		// Variables:
	// 		struct P_SPELL_7fake pos; // stack offset -32
	// 		struct P_SPELL_7fake spd; // stack offset -24
	// 		long rc; // $s0
	// 		long rs; // $v0
	/* end block 1 */
	// End offset: 0x800429A8
	// End Line: 913

	/* begin block 2 */
		// Start line: 2280
	/* end block 2 */
	// End Line: 2281

void Fire_Works(_PLAYER *pl,long level)

{
  rcos((int)(pl->obj).rot.vz);
  rsin((int)(pl->obj).rot.vz);
  Motion2D_FireWork((_D3_OBJECT *)pl,0xe0,0xe8,(int)Scr_TicksPerSecond,0x20,level * 5);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Fire_ShieldTask()
 // line 936, offset 0x80042ab0
	/* begin block 1 */
		// Start line: 937
		// Start offset: 0x80042AB0
		// Variables:
	// 		struct _D3_OBJECT obj; // stack offset -208
	// 		struct _PLAYER *pl; // $s1
	// 		struct TASK *ts; // stack offset -32
	// 		struct TASK *tt; // $s3
	// 		long level; // $s0
	// 		long coll; // $s0
	// 		long snd; // $s4
	// 		long time_depart; // $a0

		/* begin block 1.1 */
			// Start line: 993
			// Start offset: 0x80042C4C
			// Variables:
		// 		long i; // $s0

			/* begin block 1.1.1 */
				// Start line: 998
				// Start offset: 0x80042C50
				// Variables:
			// 		struct P_SPELL_7fake pos; // stack offset -40
			/* end block 1.1.1 */
			// End offset: 0x80042C50
			// End Line: 1000
		/* end block 1.1 */
		// End offset: 0x80042CE0
		// End Line: 1012
	/* end block 1 */
	// End offset: 0x80042D64
	// End Line: 1043

	/* begin block 2 */
		// Start line: 2380
	/* end block 2 */
	// End Line: 2381

/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Fire_ShieldTask(void)

{
  short sVar1;
  short sVar2;
  TASK *t;
  long lVar3;
  int iVar4;
  char pos;
  int iVar5;
  _D3_OBJECT *ot;
  undefined auStack208 [28];
  short local_b4;
  short local_b2;
  uchar local_ae;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined local_37;
  _D3_OBJECT *local_30;
  undefined4 local_28;
  uint local_24;
  TASK *local_20 [2];
  
  iVar5 = TaskCurrent->s1;
  local_20[0] = (TASK *)0x0;
  ot = (_D3_OBJECT *)TaskCurrent->s0;
  if (iVar5 < 3) {
    iVar4 = (int)Scr_TicksPerSecond * 10;
  }
  else {
    iVar4 = (int)Scr_TicksPerSecond * 0xf;
  }
  if ((int)*(short *)((int)&ot[4].matrices + 2) == iVar4) {
    *(short *)((int)&ot[4].matrices + 2) = *(short *)((int)&ot[4].matrices + 2) + -1;
    Motion2D_Storm(ot,2,local_20);
  }
  sVar1 = Fx_Play(0x2c,0);
  t = Motion2D_Twister(ot,1);
  local_b4 = 0x2003;
  local_37 = 0xf0;
  local_b2 = 0;
  local_ae = (uchar)iVar5;
  local_30 = ot;
  D3_SetBox((_D3_OBJECT *)auStack208,-100,-100,0,100,100,200);
  sVar2 = *(short *)((int)&ot[4].matrices + 2) + -1;
  *(short *)((int)&ot[4].matrices + 2) = sVar2;
  while( true ) {
    if (sVar2 == -1) goto LAB_80042d24;
    local_a4 = *(undefined4 *)&ot->pos;
    local_a0 = *(undefined4 *)&(ot->pos).vz;
    sVar2 = ot->collision_mode;
    D3_ClearCollBits(ot,1);
    Boxes_TestObject((_D3_OBJECT *)auStack208);
    ot->collision_mode = sVar2;
    if ((ot->collision_state & 0x20U) != 0) break;
    if (TaskCurrent->local != (void *)0x0) {
      Motion2D_TwisterEnd(t);
      Motion2D_StormEnd(local_20[0]);
      Task_Sleep(0x20);
      Sound_Stop((int)sVar1,0);
      pos = '\0';
      goto LAB_80042d5c;
    }
    Task_Next();
    sVar2 = *(short *)((int)&ot[4].matrices + 2) + -1;
    *(short *)((int)&ot[4].matrices + 2) = sVar2;
  }
  iVar5 = 0;
  do {
    local_28 = *(uint *)&ot->pos;
    local_24 = *(uint *)&(ot->pos).vz;
    iVar5 = iVar5 + 1;
    lVar3 = M_rand();
    local_28 = local_28 & 0xffff0000 |
               (uint)(ushort)((short)local_28 + -0x40 + ((ushort)lVar3 & 0x7f));
    lVar3 = M_rand();
    local_28 = local_28 & 0xffff |
               (uint)(ushort)(local_28._2_2_ + -0x40 + ((ushort)lVar3 & 0x7f)) << 0x10;
    lVar3 = M_rand();
    local_24 = local_24 & 0xffff0000 | (uint)(ushort)((short)local_24 - ((ushort)lVar3 & 0x3f));
    Impact_Smoke(0xd8,1);
  } while (iVar5 < 0x10);
  Task_Next();
LAB_80042d24:
  Motion2D_TwisterEnd(t);
  Motion2D_StormEnd(local_20[0]);
  *(undefined *)&ot[4].matrices = 0xff;
  Task_Sleep(0x20);
  Sound_Stop((int)sVar1,0);
  pos = (char)ot + ',';
LAB_80042d5c:
  Fx_Play(0x2d,pos);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Fire_RainTask()
 // line 1046, offset 0x80042d84
	/* begin block 1 */
		// Start line: 1047
		// Start offset: 0x80042D84
		// Variables:
	// 		struct _D3_OBJECT *ot; // $s0
	// 		struct _PLAYER *pl; // $s3
	// 		struct P_SPELL_7fake pos; // stack offset -32
	// 		long level; // $s2
	/* end block 1 */
	// End offset: 0x80042D84
	// End Line: 1047

	/* begin block 2 */
		// Start line: 2726
	/* end block 2 */
	// End Line: 2727

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Fire_RainTask(void)

{
  int iVar1;
  int hp;
  _D3_OBJECT *owner;
  
  hp = TaskCurrent->s2;
  iVar1 = hp * 3;
  owner = (_D3_OBJECT *)TaskCurrent->s0;
  Motion2D_Storm((_D3_OBJECT *)TaskCurrent->s1,(int)Scr_TicksPerSecond * (iVar1 + 2),(TASK **)0x0);
  Task_Sleep((int)Scr_TicksPerSecond);
  Motion2D_FireRain(owner,0xe0,300,(int)Scr_TicksPerSecond * (iVar1 + -1),1,hp);
  Task_Sleep((int)Scr_TicksPerSecond * (iVar1 + 1));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Water_Freeze(struct _PLAYER *pl /*$a0*/, long level /*$a1*/)
 // line 1096, offset 0x80042e80
	/* begin block 1 */
		// Start line: 1097
		// Start offset: 0x80042E80
		// Variables:
	// 		struct _D3_OBJECT (*ot[4]); // stack offset -32
	// 		long i; // $s0
	/* end block 1 */
	// End offset: 0x80042ED8
	// End Line: 1106

	/* begin block 2 */
		// Start line: 2842
	/* end block 2 */
	// End Line: 2843

void Water_Freeze(_PLAYER *pl,long level)

{
  _D3_OBJECT *D3Obj;
  int iVar1;
  _D3_OBJECT **pp_Var2;
  
  Fx_Play(0x28,(char)pl + ',');
  iVar1 = 0;
  if (0 < PSpell_nTargets) {
    pp_Var2 = &PSpell_Targets4;
    do {
      D3Obj = *pp_Var2;
      pp_Var2 = pp_Var2 + 1;
      MSpell_AppliedOnObject(D3Obj,0x10);
      iVar1 = iVar1 + 1;
    } while (iVar1 < (int)PSpell_nTargets);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Water_Antidote(struct _PLAYER *pl /*$s0*/, long level /*$s1*/)
 // line 1109, offset 0x80042eec
	/* begin block 1 */
		// Start line: 1110
		// Start offset: 0x80042EEC
		// Variables:
	// 		struct TASK *t; // $v0
	/* end block 1 */
	// End offset: 0x80042EEC
	// End Line: 1110

	/* begin block 2 */
		// Start line: 2874
	/* end block 2 */
	// End Line: 2875

void Water_Antidote(_PLAYER *pl,long level)

{
  TASK *pTVar1;
  
  pTVar1 = Task_Link(Water_AntidoteTask,0x200);
  *(_PLAYER **)&pTVar1->s0 = pl;
  pTVar1->s1 = level;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Water_Vampire(struct _PLAYER *pl /*$s0*/, long level /*$s1*/)
 // line 1119, offset 0x80042f30
	/* begin block 1 */
		// Start line: 1120
		// Start offset: 0x80042F30
		// Variables:
	// 		struct TASK *t; // $v0
	/* end block 1 */
	// End offset: 0x80042F30
	// End Line: 1120

	/* begin block 2 */
		// Start line: 2897
	/* end block 2 */
	// End Line: 2898

void Water_Vampire(_PLAYER *pl,long level)

{
  TASK *pTVar1;
  
  pTVar1 = Task_Link(Water_VampireTask,0x200);
  *(_PLAYER **)&pTVar1->s0 = pl;
  pTVar1->s1 = level;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Water_Wall(struct _PLAYER *pl /*$s0*/, long level /*$s1*/)
 // line 1129, offset 0x80042f74
	/* begin block 1 */
		// Start line: 1130
		// Start offset: 0x80042F74
		// Variables:
	// 		struct TASK *t; // $v0
	/* end block 1 */
	// End offset: 0x80042F74
	// End Line: 1130

	/* begin block 2 */
		// Start line: 2920
	/* end block 2 */
	// End Line: 2921

void Water_Wall(_PLAYER *pl,long level)

{
  TASK *pTVar1;
  
  pTVar1 = Task_Link(Water_WallTask,0x300);
  *(_PLAYER **)&pTVar1->s0 = pl;
  pTVar1->s1 = level;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Water_AntidoteTask()
 // line 1139, offset 0x80042fb8
	/* begin block 1 */
		// Start line: 1140
		// Start offset: 0x80042FB8
		// Variables:
	// 		struct _PLAYER *pl; // $s1
	// 		long i; // $s0
	/* end block 1 */
	// End offset: 0x80043080
	// End Line: 1168

	/* begin block 2 */
		// Start line: 2948
	/* end block 2 */
	// End Line: 2949

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Water_AntidoteTask(void)

{
  int iVar1;
  _PLAYER *pl;
  
  pl = (_PLAYER *)TaskCurrent->s0;
  Pl_ClearStateBits(pl,2);
  Pl_ClearStateBits(pl,4);
  Pl_ClearStateBits(pl,8);
  Pl_ClearStateBits(pl,0x10);
  Fx_Play(0x3b,(char)pl + ',');
  iVar1 = 0;
  if (0 < Scr_TicksPerSecond) {
    do {
      if (*(code **)&(pl->m_obj).Env.Data != Motion2D_ManimVampire) {
        Manim_SetEffect((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data,Motion2D_ManimVampire);
      }
      iVar1 = iVar1 + 1;
      Task_Next();
    } while (iVar1 < (int)Scr_TicksPerSecond);
  }
  if (*(code **)&(pl->m_obj).Env.Data == Motion2D_ManimVampire) {
    *(undefined2 *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x20) = 0x80;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Water_VampireTask()
 // line 1171, offset 0x80043098
	/* begin block 1 */
		// Start line: 1172
		// Start offset: 0x80043098
		// Variables:
	// 		struct _PLAYER *pl; // $s2
	// 		struct _D3_OBJECT *ot; // $s3
	// 		long level; // $s1
	// 		long result; // $s0
	// 		long resist; // $a1
	// 		long i; // $s1
	// 		long hit; // $s0
	// 		long vamp; // $s4
	/* end block 1 */
	// End offset: 0x80043290
	// End Line: 1231

	/* begin block 2 */
		// Start line: 3025
	/* end block 2 */
	// End Line: 3026

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Water_VampireTask(void)

{
  _D3_OBJECT *D3Obj;
  TASK *t;
  short sVar1;
  long lVar2;
  ulong uVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  D3Obj = PSpell_Targets4;
  iVar5 = 0;
  iVar8 = 0;
  iVar7 = TaskCurrent->s0;
  iVar6 = TaskCurrent->s1;
  Fx_Play(0x31,(char)iVar7 + ',');
  lVar2 = MSpell_AppliedOnObject(D3Obj,0xf);
  if (lVar2 != 0) {
    iVar5 = iVar6 << 6;
  }
  if (iVar5 == 0) goto LAB_800431e0;
  uVar3 = MSpell_TestAppliedOnObject(D3Obj,0xf);
  iVar8 = (int)D3Obj->hit_points;
  if (iVar8 < 100) {
    if (iVar5 * iVar8 >> 8 < 1) {
      iVar8 = 1;
    }
    else {
LAB_8004315c:
      if (iVar8 < 100) {
        iVar8 = iVar5 * iVar8 >> 8;
      }
      else {
        iVar8 = iVar5 * 100 >> 8;
      }
    }
  }
  else {
    iVar8 = 1;
    if (0 < iVar5 * 100 >> 8) {
      iVar8 = (int)D3Obj->hit_points;
      goto LAB_8004315c;
    }
  }
  iVar6 = iVar8 * uVar3 * 0x40;
  iVar5 = iVar6 >> 8;
  if (iVar6 < 1) {
    iVar5 = 0;
  }
  iVar6 = iVar8 * uVar3 * 0x40;
  sVar1 = (short)((uint)iVar6 >> 8);
  if ((int)D3Obj->hit_points - iVar5 < 0) {
    sVar1 = 0;
  }
  else {
    if (iVar6 < 1) {
      sVar1 = 0;
    }
    sVar1 = D3Obj->hit_points - sVar1;
  }
  D3Obj->hit_points = sVar1;
LAB_800431e0:
  iVar6 = 0;
  iVar5 = (int)*(short *)(iVar7 + 0x20) << 8;
  do {
    if (*(code **)(iVar7 + 0xd4) != Motion2D_ManimVampire) {
      Manim_SetEffect((M_OBJECT *)(iVar7 + 0xa4),Motion2D_ManimVampire);
    }
    t = Overlay_Handle;
    iVar5 = iVar5 + (iVar8 * 0x100) / 0x3c;
    uVar4 = (undefined2)((uint)iVar5 >> 8);
    if (100 < iVar5 >> 8) {
      uVar4 = 100;
    }
    iVar6 = iVar6 + 1;
    *(undefined2 *)(iVar7 + 0x20) = uVar4;
    Task_EventExec(t,t->event_msg | 4,t->event_param);
    Task_Next();
  } while (iVar6 < 0x3c);
  if (*(code **)(iVar7 + 0xd4) == Motion2D_ManimVampire) {
    *(undefined2 *)(iVar7 + 0xc4) = 0x80;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Water_WallTask()
 // line 1234, offset 0x800432b0
	/* begin block 1 */
		// Start line: 1235
		// Start offset: 0x800432B0
		// Variables:
	// 		struct P_SPELL_134fake *w; // $s2
	// 		struct _PLAYER *pl; // $s0
	// 		long level; // $s1
	/* end block 1 */
	// End offset: 0x800435E8
	// End Line: 1330

	/* begin block 2 */
		// Start line: 3216
	/* end block 2 */
	// End Line: 3217

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Water_WallTask(void)

{
  undefined2 uVar1;
  TASK *pTVar2;
  void *File;
  int iVar3;
  TASK *pTVar4;
  char pos;
  int iVar5;
  long lVar6;
  TASK *pTVar7;
  _D3_OBJECT *o;
  
  pTVar2 = TaskCurrent;
  File = Pl_Spells;
  iVar5 = TaskCurrent->s0;
  lVar6 = TaskCurrent->s1;
  pTVar7 = TaskCurrent + 1;
  *(TASK **)&TaskCurrent->local = pTVar7;
  pTVar2->display = Water_WallDisplay;
  File = FileGroup_GetAddr(File,4);
  o = (_D3_OBJECT *)&pTVar2[1].next;
  pTVar2[1].local = (void *)((int)File + 0xc);
  *(undefined2 *)((int)&pTVar2[1].sp + 2) = 0x107;
  *(undefined2 *)&pTVar2[1].display = 0x2805;
  *(undefined2 *)((int)&pTVar2[1].event_s0 + 2) = 4;
  pTVar2[1].s0 = 0x808080;
  pTVar2[1].exec = (_func_10 *)0x0;
  *(undefined2 *)((int)&pTVar2[1].event_param + 2) = 0;
  *(undefined2 *)((int)&pTVar2[1].display + 2) = 0;
  *(undefined2 *)((int)&pTVar2[1].event_exec + 2) = 0;
  *(undefined2 *)((int)&pTVar2[1].event_s4 + 2) = 0xffff;
  *(short *)&pTVar2[1].destructor = (short)lVar6 * 100;
  D3_SetBox(o,-0x21,-100,0,0x21,100,200);
  pTVar2[2].exec = *(_func_10 **)pTVar2[1].local;
  iVar3 = rcos((int)*(short *)(iVar5 + 0x40));
  *(short *)&pTVar2[1].s1 = *(short *)(iVar5 + 0x2c) + (short)(iVar3 * 200 >> 0xc);
  iVar3 = rsin((int)*(short *)(iVar5 + 0x40));
  *(short *)((int)&pTVar2[1].s1 + 2) = *(short *)(iVar5 + 0x2e) + (short)(iVar3 * 200 >> 0xc);
  *(short *)&pTVar2[1].s2 = *(short *)(iVar5 + 0x30) + 1;
  pTVar2[1].s3 = pTVar2[1].s1;
  pTVar2[1].s4 = pTVar2[1].s2;
  lVar6 = *(long *)(iVar5 + 0x40);
  pTVar2[1].s5 = *(long *)(iVar5 + 0x3c);
  pTVar2[1].s6 = lVar6;
  uVar1 = *(undefined2 *)(iVar5 + 0x40);
  pTVar2[1].event_enable = 0x1000;
  *(void ***)&pTVar2[1].s7 = &pTVar2[2].sp;
  *(undefined2 *)((int)&pTVar2[1].s6 + 2) = uVar1;
  Light_SetMatrix(o);
  pos = (char)pTVar2 + -0x40;
  lVar6 = Boxes_TestObject(o);
  if (lVar6 != 0) {
    SFX_Explosion(pos,(int)*(short *)((int)&pTVar2[1].event_exec + 2),
                  (int)*(short *)((int)&pTVar2[1].event_s0 + 2));
    goto LAB_800435e8;
  }
  D3_ClearCollBits(o,0x2000);
  Task_EventExec(TaskCurrent,1,0);
  D3_InsertObject(o,&Pvl_GlobalObjects);
  lVar6 = Task_EventWait();
  if (lVar6 == 2) {
LAB_80043548:
    Task_Sleep((int)Scr_TicksPerSecond * 0x14);
    Task_EventExec(TaskCurrent,3,0);
LAB_8004357c:
    Fx_Play(0x30,(char)pTVar7 + '0');
    pTVar4 = pTVar7->prec;
    while ((int)pTVar4 < 0x1000) {
      D3_SetHighBoxZ((_D3_OBJECT *)&pTVar2[1].next,(int)*(short *)&pTVar2[1].event_s2 + -0x19);
      Task_Next();
      pTVar4 = (TASK *)&pTVar7->prec[3].text_context;
      pTVar7->prec = pTVar4;
    }
  }
  else {
    if (lVar6 < 3) {
      if (lVar6 == 1) {
        Fx_Play(0x32,pos);
        pTVar2[1].prec = (TASK *)0x1000;
        do {
          Task_Next();
          pTVar4 = (TASK *)&pTVar7->prec[-3].display;
          pTVar7->prec = pTVar4;
        } while (pTVar4 != (TASK *)0x0);
        Task_EventExec(TaskCurrent,2,0);
        goto LAB_80043548;
      }
    }
    else {
      if (lVar6 == 3) goto LAB_8004357c;
    }
  }
  if ((*(ushort *)((int)&pTVar2[1].display + 2) & 4) == 0) {
    D3_DeleteObject((_D3_OBJECT *)&pTVar2[1].next);
  }
LAB_800435e8:
  TaskCurrent->display = (_func_11 *)0x0;
  Task_Sleep(4);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Water_WallDisplay()
 // line 1337, offset 0x8004361c
	/* begin block 1 */
		// Start line: 1338
		// Start offset: 0x8004361C
		// Variables:
	// 		struct P_SPELL_134fake *w; // $s0
	// 		struct _D3_OBJECT *oh; // $v0
	/* end block 1 */
	// End offset: 0x800436AC
	// End Line: 1360

	/* begin block 2 */
		// Start line: 3495
	/* end block 2 */
	// End Line: 3496

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Water_WallDisplay(void)

{
  char cVar1;
  TASK *t;
  int *piVar2;
  
  t = TaskCurrent;
  piVar2 = (int *)TaskCurrent->local;
  if ((*(ushort *)((int)piVar2 + 0x22) & 2) != 0) {
    *(ushort *)((int)piVar2 + 0x22) = *(ushort *)((int)piVar2 + 0x22) & 0xfffd;
    if (*(short *)(piVar2 + 9) == 0) {
      Task_EventExec(t,4,0);
    }
    cVar1 = *(char *)(piVar2[0x25] + 0x99);
    if (((cVar1 == -9) || (cVar1 == -0x10)) || ((byte)(*(char *)(piVar2[0x25] + 0x99) + 6U) < 5)) {
      Task_EventExec(TaskCurrent,3,0);
    }
  }
  GtxTmd_ApplyMIMe((uint **)piVar2[10],*piVar2);
  Main_Prims = D3_DisplayTmd((_D3_OBJECT *)(piVar2 + 1),Main_Prims,0,(int)Scr_W);
  return;
}





