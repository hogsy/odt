#include "THISDUST.H"
#include "P_ACTH.H"


// decompiled code
// original method signature: 
// void /*$ra*/ Pafh_TestHold(struct _PLAYER *pl /*$s3*/)
 // line 21, offset 0x8003955c
	/* begin block 1 */
		// Start line: 22
		// Start offset: 0x8003955C
		// Variables:
	// 		struct _D3_OBJECT *oc; // $s0
	// 		long h0; // $v0
	// 		long h; // $s2
	// 		long a; // $s6
	// 		long d; // $s7
	// 		long i; // $s4
	// 		long n; // $fp
	// 		long t; // stack offset -48
	// 		long pente; // $s1
	/* end block 1 */
	// End offset: 0x80039828
	// End Line: 102

	/* begin block 2 */
		// Start line: 42
	/* end block 2 */
	// End Line: 43

/* WARNING: Type propagation algorithm not settling */

void Pafh_TestHold(_PLAYER *pl)

{
  bool bVar1;
  ushort uVar2;
  _D3_OBJECT *obj;
  short sVar3;
  ushort uVar4;
  long Action;
  long lVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int dist;
  int iVar9;
  int iVar10;
  int local_30;
  
  uVar4 = *(ushort *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x22);
  if ((((uVar4 & 0x30) != 0) && ((*(ushort *)&(pl->m_obj).shadow.u0 & 2) == 0)) &&
     (((uVar4 & 0x20) == 0 ||
      ((((uVar4 = (pl->m_obj).shadow.clut, (uVar4 & 0x200) == 0 ||
         (((pl->m_obj).nAnim & PJOY_JUMP) != 0)) &&
        (uVar2 = (pl->m_obj).dummy1 & PJOY_JUMP, (pl->m_obj).shadow.clut = uVar4 & 0xfdff,
        uVar2 != 0)) && ((*(ushort *)&(pl->m_obj).Env.Obj.n_primitive & 1) == 0)))))) {
    Action = Pl_TestHeight(pl,0);
    uVar4 = *(ushort *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x22);
    iVar10 = 4;
    if ((uVar4 & 0x20) != 0) {
      iVar10 = 0x10;
    }
    local_30 = 8;
    if ((uVar4 & 0x20) != 0) {
      local_30 = 10;
    }
    iVar6 = (int)(pl->obj).pos.vz;
    iVar8 = 0;
    if (Action <= iVar6) {
      iVar6 = iVar6 + 0xd2;
      iVar9 = (int)(pl->obj).last_pos.vz + 0xd2;
      if (iVar10 != 0) {
        dist = 0x10;
        do {
          Action = Pl_TestHeight(pl,dist);
          obj = Boxes_Object;
          if ((Boxes_Object != (_D3_OBJECT *)0x0) &&
             (bVar1 = false, (Boxes_Object->collision_mode & 0x800U) == 0)) {
            lVar5 = Boxes_GetExtendedMaxZ(Boxes_Object);
            if (lVar5 != 0) {
              sVar3 = Boxes_GetBit((_D3_OBJECT *)pl,obj);
              if (sVar3 == 0x800) {
                uVar4 = *(ushort *)&obj[1].father ^ *(ushort *)&obj[1].handle;
              }
              else {
                if (sVar3 < 0x801) {
                  if (sVar3 != 0x400) goto LAB_80039754;
                  uVar4 = *(ushort *)&obj[1].prec ^ obj[1].collision_mode;
                }
                else {
                  if (sVar3 == 0x1000) {
                    uVar4 = obj[1].collision_mode ^ *(ushort *)&obj[1].handle;
                  }
                  else {
                    if (sVar3 != 0x2000) goto LAB_80039754;
                    uVar4 = *(ushort *)&obj[1].prec ^ *(ushort *)&obj[1].father;
                  }
                }
              }
              bVar1 = uVar4 != 0;
            }
LAB_80039754:
            if (!bVar1) {
              if ((*(uint *)&obj[1].pos & 0xffffff00) == 0xf00) {
                iVar7 = (int)(obj->pos).vz;
                if ((iVar7 + (int)(obj->b_box).vz < (int)(pl->obj).pos.vz) &&
                   (iVar6 <= iVar7 + (int)*(short *)&obj[1].prec)) {
                  iVar7 = DeltaDirection((int)(pl->obj).rot.vz,(int)(obj->rot).vz);
                  if (iVar7 < 0) {
                    iVar7 = -iVar7;
                  }
                  if (iVar7 < 0x200) {
                    Action = 0xe;
                    goto LAB_8003980c;
                  }
                }
              }
              else {
                if (((iVar6 < Action + 0x32) && (Action + -0x32 <= iVar9)) ||
                   ((Action + -0x32 < iVar6 && (iVar9 <= Action + 0x32)))) {
                  Action = 0xb;
LAB_8003980c:
                  Pl_ForceAction(pl,Action,(long)obj);
                }
              }
            }
          }
          iVar8 = iVar8 + 1;
          dist = dist + local_30;
        } while (iVar8 < iVar10);
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pafh_TestHoldDown(struct _PLAYER *pl /*$s2*/, struct _D3_OBJECT **hog /*$s7*/, short *hsg /*$s5*/, long arriere /*$s6*/)
 // line 105, offset 0x80039858
	/* begin block 1 */
		// Start line: 106
		// Start offset: 0x80039858
		// Variables:
	// 		long dd; // $a0
	// 		long h; // $a0
	// 		long i; // $a0
	// 		long dist; // $s0
	// 		struct _D3_OBJECT *oh; // $s1

		/* begin block 1.1 */
			// Start line: 150
			// Start offset: 0x800399D4
			// Variables:
		// 		long d; // $s0
		// 		long dx; // $s4
		// 		long dy; // $s0
		// 		long pente; // $s3
		/* end block 1.1 */
		// End offset: 0x80039AD8
		// End Line: 174
	/* end block 1 */
	// End offset: 0x80039B54
	// End Line: 188

	/* begin block 2 */
		// Start line: 248
	/* end block 2 */
	// End Line: 249

void Pafh_TestHoldDown(_PLAYER *pl,_D3_OBJECT **hog,short *hsg,long arriere)

{
  bool bVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  ushort uVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  _D3_OBJECT *ot;
  _D3_OBJECT **pp_Var12;
  
  iVar11 = 0;
  pp_Var12 = hog;
  do {
    ot = *pp_Var12;
    if ((ot != (_D3_OBJECT *)0x0) && ((*(uint *)&ot[1].pos & 0xffffff00) == 0xf00)) {
      iVar6 = DeltaDirection((int)(ot->rot).vz,(int)(pl->obj).rot.vz);
      if (iVar6 < 0) {
        iVar6 = -iVar6;
      }
      iVar9 = (int)(ot->pos).vz;
      iVar10 = (int)(pl->obj).pos.vz;
      iVar7 = (iVar9 + (int)*(short *)&ot[1].prec) - iVar10;
      if (iVar7 < 0) {
        iVar7 = -iVar7;
      }
      if (((iVar7 < 10) && (iVar9 + (int)(ot->b_box).vz < iVar10 + -100)) &&
         (0x400 < iVar6 - 0x200U)) {
        iVar6 = 0;
        if (0 < iVar11) {
          iVar7 = 0;
          do {
            iVar6 = iVar6 + 1;
            if (iVar10 < (int)*(short *)(iVar7 + (int)hsg)) {
              iVar6 = -1;
              break;
            }
            iVar7 = iVar6 * 2;
          } while (iVar6 < iVar11);
        }
        if (-1 < iVar6) {
          Pl_ForceAction(pl,arriere | 0xe,(long)ot);
        }
      }
    }
    iVar11 = iVar11 + 1;
    pp_Var12 = pp_Var12 + 1;
  } while (iVar11 < 10);
  ot = *hog;
  if (ot == (_D3_OBJECT *)0x0) {
    return;
  }
  iVar11 = (int)*hsg - (int)(pl->obj).pos.vz;
  if (iVar11 < 0) {
    iVar11 = -iVar11;
  }
  if (0x19 < iVar11) {
    return;
  }
  lVar8 = Boxes_GetExtendedMaxZ(ot);
  bVar1 = false;
  if (lVar8 == 0) goto LAB_80039ad8;
  iVar11 = 100;
  if (arriere != 0) {
    iVar11 = -100;
  }
  iVar6 = rcos((int)(pl->obj).rot.vz);
  iVar7 = rsin((int)(pl->obj).rot.vz);
  sVar2 = (short)(iVar6 * iVar11 >> 0xc);
  (pl->obj).pos.vx = (pl->obj).pos.vx + sVar2;
  sVar3 = (short)(iVar7 * iVar11 >> 0xc);
  (pl->obj).pos.vy = (pl->obj).pos.vy + sVar3;
  sVar4 = Boxes_GetBit((_D3_OBJECT *)pl,ot);
  if (sVar4 == 0x800) {
    uVar5 = *(ushort *)&ot[1].father ^ *(ushort *)&ot[1].handle;
LAB_80039ab8:
    bVar1 = uVar5 != 0;
  }
  else {
    if (0x800 < sVar4) {
      if (sVar4 == 0x1000) {
        uVar5 = ot[1].collision_mode ^ *(ushort *)&ot[1].handle;
      }
      else {
        if (sVar4 != 0x2000) goto LAB_80039abc;
        uVar5 = *(ushort *)&ot[1].prec ^ *(ushort *)&ot[1].father;
      }
      goto LAB_80039ab8;
    }
    if (sVar4 == 0x400) {
      uVar5 = *(ushort *)&ot[1].prec ^ ot[1].collision_mode;
      goto LAB_80039ab8;
    }
  }
LAB_80039abc:
  sVar4 = (pl->obj).pos.vy;
  (pl->obj).pos.vx = (pl->obj).pos.vx - sVar2;
  (pl->obj).pos.vy = sVar4 - sVar3;
  if (bVar1) {
    return;
  }
LAB_80039ad8:
  iVar11 = 1;
  hog = hog + 1;
  do {
    if (*hog != ot) break;
    iVar11 = iVar11 + 1;
    hog = hog + 1;
  } while (iVar11 < 6);
  iVar6 = iVar11 + 4;
  if (iVar11 < iVar6) {
    hsg = hsg + iVar11;
    do {
      iVar11 = iVar11 + 1;
      if ((int)(pl->obj).pos.vz + -0xd2 <= (int)*hsg) {
        return;
      }
      hsg = hsg + 1;
    } while (iVar11 < iVar6);
  }
  Pl_ForceAction(pl,arriere | 0x400b,(long)ot);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Pafh_GetPosRot(struct _PLAYER *pl /*$t0*/, struct _D3_OBJECT *oh /*$s0*/, long bit /*$s1*/, struct P_ACTH_7fake *pos /*$s2*/, long offset /*stack 16*/, long adjust /*stack 20*/)
 // line 191, offset 0x80039b80
	/* begin block 1 */
		// Start line: 192
		// Start offset: 0x80039B80
		// Variables:
	// 		struct P_ACTH_7fake t; // stack offset -32
	// 		long rz; // $s3
	// 		long orz; // $a0
	/* end block 1 */
	// End offset: 0x80039E20
	// End Line: 263

	/* begin block 2 */
		// Start line: 472
	/* end block 2 */
	// End Line: 473

long Pafh_GetPosRot(_PLAYER *pl,_D3_OBJECT *oh,long bit,undefined pos,long offset,long adjust)

{
  short sVar1;
  uint uVar2;
  undefined3 in_register_0000001d;
  short *psVar3;
  uint unaff_s3;
  
  psVar3 = (short *)CONCAT31(in_register_0000001d,pos);
  uVar2 = 0;
  if ((*(uint *)&oh[1].pos & 0xffffff00) == 0xf00) {
    *psVar3 = (oh->last_pos).vx;
    psVar3[1] = (oh->last_pos).vy;
    return (int)(oh->rot).vz;
  }
  if ((oh->collision_mode & 4U) != 0) {
    uVar2 = SEXT24((oh->rot).vz);
  }
  if (bit == 0x800) {
    uVar2 = uVar2 + 0x800;
LAB_80039c30:
    unaff_s3 = uVar2 & 0xfff;
  }
  else {
    if (0x800 < bit) {
      if (bit == 0x1000) {
        uVar2 = uVar2 + 0x400;
      }
      else {
        uVar2 = uVar2 + 0xc00;
        if (bit != 0x2000) goto LAB_80039c34;
      }
      goto LAB_80039c30;
    }
    if (bit == 0x400) {
      unaff_s3 = uVar2 & 0xfff;
    }
  }
LAB_80039c34:
  if (psVar3 == (short *)0x0) {
    return unaff_s3;
  }
  Boxes_RotPos(oh,(char)oh + '4',(char)pl + ',',0xe0);
  Boxes_InvRotPos(oh,(char)oh + '4',0xe0,pos);
  psVar3[2] = (oh->last_pos).vz + (short)offset + -0xd2;
  if (bit == 0x800) {
LAB_80039d64:
    sVar1 = psVar3[2] + *(short *)&oh[1].handle;
  }
  else {
    if (bit < 0x801) {
      if (bit != 0x400) goto LAB_80039d78;
    }
    else {
      if (bit == 0x1000) goto LAB_80039d64;
      if (bit != 0x2000) goto LAB_80039d78;
    }
    sVar1 = psVar3[2] + *(short *)&oh[1].prec;
  }
  psVar3[2] = sVar1;
LAB_80039d78:
  if (adjust == 0) {
    return unaff_s3;
  }
  if (Pvl_PlayerNumber != 2) {
    if (2 < Pvl_PlayerNumber) {
      if (Pvl_PlayerNumber == 3) {
        psVar3[2] = psVar3[2] + -4;
        return unaff_s3;
      }
      if (Pvl_PlayerNumber != 5) {
        return unaff_s3;
      }
      psVar3[2] = psVar3[2] + 2;
      return unaff_s3;
    }
    if (Pvl_PlayerNumber != 1) {
      return unaff_s3;
    }
  }
  psVar3[2] = psVar3[2] + 0xc;
  return unaff_s3;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Pafh_Shot(struct _D3_OBJECT *oh /*$s1*/, long bit /*$s3*/, long swing /*$s0*/)
 // line 269, offset 0x80039e48
	/* begin block 1 */
		// Start line: 270
		// Start offset: 0x80039E48
		// Variables:
	// 		struct _PLAYER *pl; // $s2
	// 		long anm_start; // $a1
	// 		long anm_recul; // $s3
	// 		long anm_end; // $s4
	// 		long shot; // $s1
	/* end block 1 */
	// End offset: 0x80039F28
	// End Line: 303

	/* begin block 2 */
		// Start line: 645
	/* end block 2 */
	// End Line: 646

/* WARNING: Type propagation algorithm not settling */

long Pafh_Shot(_D3_OBJECT *oh,long bit,long swing)

{
  ushort uVar1;
  short sVar2;
  long Anim;
  M_OBJECT *obj;
  _PLAYER *pl;
  long recul_anm;
  long Anim_00;
  
  pl = (_PLAYER *)TaskCurrent->local;
  Anim = Pl_IsWeaponAvailable(pl,(int)(char)(pl->env1).Obj.primitive_top.Data[0x19]);
  if (Anim == 0) {
    return 0;
  }
  if (swing != 0) {
    sVar2 = Boxes_GetDepth(oh,(short)bit);
    Anim = 0x4a;
    if (sVar2 < 100) {
      recul_anm = 0x56;
      Anim_00 = 0x4b;
      goto LAB_80039ed0;
    }
  }
  Anim = 0x49;
  recul_anm = 0x55;
  Anim_00 = 0x48;
LAB_80039ed0:
  obj = (M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data;
  uVar1 = (pl->m_obj).dummy1 & PJOY_SHOT;
  Manim_SetAnim(obj,Anim);
  Manim_WaitAnim(obj);
  *(undefined2 *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x26) = 0;
  *(undefined2 *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x24) = 0;
  Pafc_ExecShot(recul_anm,(uint)uVar1);
  Manim_SetAnim(obj,Anim_00);
  Manim_WaitAnim(obj);
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Pafh_GoUp(long anm /*$s2*/, struct _D3_OBJECT *oh /*$a1*/, long bit /*$a2*/)
 // line 306, offset 0x80039f48
	/* begin block 1 */
		// Start line: 307
		// Start offset: 0x80039F48
		// Variables:
	// 		struct _PLAYER *pl; // $s1
	/* end block 1 */
	// End offset: 0x8003A008
	// End Line: 340

	/* begin block 2 */
		// Start line: 723
	/* end block 2 */
	// End Line: 724

long Pafh_GoUp(long anm,_D3_OBJECT *oh,long bit)

{
  long Anim;
  M_OBJECT *obj;
  _PLAYER *pl;
  
  pl = (_PLAYER *)TaskCurrent->local;
  Anim = Pafh_GetPosRot(pl,oh,bit,(char)pl + ',',0,0);
  obj = (M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data;
  (pl->obj).rot.vz = (short)Anim;
  Manim_SetAnim(obj,anm);
  Manim_WaitAnim(obj);
  if (((pl->m_obj).dummy1 & 0x4000U) == 0) {
    Manim_SetAnim(obj,4);
    *(undefined2 *)((int)&(pl->m_obj).Env.Obj.n_primitive + 2) = 0x200;
    *(undefined2 *)&(pl->m_obj).Env.Obj.scale = 0x120;
    Manim_WaitAnim(obj);
    Anim = 1;
  }
  else {
    Anim = 0xd;
    if (anm == 2) {
      Anim = 3;
    }
    Manim_SetAnim(obj,Anim);
    Manim_WaitAnim((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data);
    Anim = 0;
  }
  return Anim;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Pafh_GoDown(struct _D3_OBJECT *oh /*$s7*/, long bit /*$s6*/, long arriere /*$s5*/)
 // line 343, offset 0x8003a020
	/* begin block 1 */
		// Start line: 344
		// Start offset: 0x8003A020
		// Variables:
	// 		struct _PLAYER *pl; // $s2
	// 		struct P_ACTH_7fake pos; // stack offset -48
	// 		long time; // $s3
	// 		long x; // $a0
	// 		long y; // $a1
	// 		long rz; // $a2
	// 		long ret; // $s1
	// 		long anm; // $a1
	/* end block 1 */
	// End offset: 0x8003A290
	// End Line: 424

	/* begin block 2 */
		// Start line: 805
	/* end block 2 */
	// End Line: 806

/* WARNING: Removing unreachable block (ram,0x8003a1fc) */
/* WARNING: Type propagation algorithm not settling */

long Pafh_GoDown(_D3_OBJECT *oh,long bit,long arriere)

{
  short sVar1;
  short sVar2;
  ushort uVar3;
  short sVar4;
  long lVar5;
  long d1;
  M_OBJECT *obj;
  int iVar6;
  int iVar7;
  long lVar8;
  _PLAYER *pl;
  short local_30;
  short local_2e;
  
  pl = (_PLAYER *)TaskCurrent->local;
  obj = (M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data;
  Manim_SetAnim(obj,5);
  if (arriere != 0) {
    Manim_GoToFrame(obj,0x2d);
    (pl->obj).rot.vz = (pl->obj).rot.vz + 0x800U & 0xfff;
  }
  while (((int)*(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x22) & 0x8000U) == 0) {
    d1 = Pafh_GetPosRot(pl,oh,bit,0xd0,0,0);
    lVar8 = Manim_GetEventTime((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data,0x8000);
    if (lVar8 == 0) {
      lVar8 = 1;
    }
    iVar7 = ((int)local_30 - (int)(pl->obj).pos.vx) * 0x10000;
    if (lVar8 == 0) {
      trap(0x1c00);
    }
    if ((lVar8 == -1) && (iVar7 == -0x80000000)) {
      trap(0x1800);
    }
    iVar6 = ((int)local_2e - (int)(pl->obj).pos.vy) * 0x10000;
    if (lVar8 == 0) {
      trap(0x1c00);
    }
    if ((lVar8 == -1) && (iVar6 == -0x80000000)) {
      trap(0x1800);
    }
    lVar5 = DeltaDirection(d1,(int)(pl->obj).rot.vz + 0x800U & 0xfff);
    if (lVar8 == 0) {
      trap(0x1c00);
    }
    if ((lVar8 == -1) && (lVar5 << 0x10 == -0x80000000)) {
      trap(0x1800);
    }
    sVar4 = (pl->obj).pos.vx;
    sVar1 = (pl->obj).pos.vy;
    sVar2 = (pl->obj).rot.vz;
    *(ushort *)&(pl->m_obj).shadow.u0 = *(ushort *)&(pl->m_obj).shadow.u0 | 8;
    (pl->obj).pos.vx = (short)((uint)((int)sVar4 * 0x10000 + iVar7 / lVar8) >> 0x10);
    if (lVar8 == 0) {
      trap(0x1c00);
    }
    (pl->obj).pos.vy = (short)((uint)((int)sVar1 * 0x10000 + iVar6 / lVar8) >> 0x10);
    sVar4 = (short)((uint)((int)sVar2 * 0x10000 + (lVar5 << 0x10) / lVar8) >> 0x10);
    (pl->obj).rot.vz = sVar4;
    if (arriere == 0) {
      sVar4 = (short)((uint)(0x8000000 / lVar8) >> 0x10);
    }
    else {
      sVar4 = (short)d1 - sVar4;
    }
    *(short *)&(pl->m_obj).shadow.u1 = sVar4;
    Task_Next();
  }
  Manim_WaitAnim((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data);
  sVar4 = (pl->obj).rot.vz;
  *(ushort *)&(pl->m_obj).shadow.u0 = *(ushort *)&(pl->m_obj).shadow.u0 & 0xfff7;
  uVar3 = (pl->m_obj).dummy1;
  (pl->obj).rot.vz = sVar4 + 0x800U & 0xfff;
  if ((uVar3 & 0x1000) == 0) {
    d1 = 0xd;
    if (bit != 0) {
      d1 = 3;
    }
    lVar8 = 1;
  }
  else {
    d1 = 4;
    lVar8 = 0;
    (pl->obj).pos.vz = (pl->obj).pos.vz + 4;
  }
  obj = (M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data;
  Manim_SetAnim(obj,d1);
  Manim_WaitAnim(obj);
  return lVar8;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pafh_Swing(struct _D3_OBJECT *oh /*$s3*/, long bit /*$s4*/)
 // line 432, offset 0x8003a2d4
	/* begin block 1 */
		// Start line: 433
		// Start offset: 0x8003A2D4
		// Variables:
	// 		struct _PLAYER *pl; // $s0
	// 		long z; // $v0
	// 		long anm; // $s1
	// 		long test; // $a0
	/* end block 1 */
	// End offset: 0x8003A4C4
	// End Line: 490

	/* begin block 2 */
		// Start line: 1015
	/* end block 2 */
	// End Line: 1016

/* WARNING: Type propagation algorithm not settling */

void Pafh_Swing(_D3_OBJECT *oh,long bit)

{
  short sVar1;
  long lVar2;
  int iVar3;
  ushort uVar4;
  _PLAYER *pl;
  int Anim;
  M_OBJECT *obj;
  
  pl = (_PLAYER *)TaskCurrent->local;
  Anim = 0x2a;
  if (*(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x16) == 0x29) {
    Anim = 0x2f;
  }
  iVar3 = *(int *)(*(int *)((pl->m_obj).Env.Obj.primitive_top.Data + 0xc) + Anim * 4 + 8);
  D3_SetHighBoxZ((_D3_OBJECT *)pl,
                 0x96 - (int)*(short *)(iVar3 + ((uint)*(ushort *)(iVar3 + 6) - 1) * 8 + 0x18));
  obj = (M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data;
  Manim_SetAnim(obj,Anim);
  Manim_WaitAnim(obj);
  if (((pl->m_obj).dummy1 & PJOY_JUMP) != 0) {
    uVar4 = *(ushort *)&(pl->m_obj).shadow.u0;
    *(undefined4 *)&(pl->m_obj).Ani.Anim.Trans = 0;
    *(ushort *)&(pl->m_obj).shadow.u0 = uVar4 & 0xfffd;
    lVar2 = Pafh_GetPosRot(pl,oh,bit,(char)pl + ',',0,1);
    sVar1 = *(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x16);
    Anim = *(int *)((pl->m_obj).Env.Obj.primitive_top.Data + 0xc);
    (pl->obj).rot.vz = (short)lVar2;
    (pl->obj).pos.vz =
         *(short *)(*(int *)(Anim + (int)sVar1 * 4 + 8) +
                    ((int)((uint)*(ushort *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x18) << 0x10)
                    >> 0x14) * 8 + 0x18) + (pl->obj).pos.vz + 5;
    Pafj_ExecJpForward(0x2c,0x180);
    Pl_ForceAction(pl,3,0);
  }
  Manim_SetAnim(obj,0x2b);
  Manim_WaitEvent(obj,0x8000);
  D3_SetHighBoxZ((_D3_OBJECT *)pl,(uint)*(ushort *)((pl->env2).Obj.primitive_top.Data + 10));
  uVar4 = *(ushort *)&(pl->m_obj).Env.Obj.n_primitive;
  do {
    if ((uVar4 & 0x4000) != 0) {
LAB_8003a4c8:
      lVar2 = Pafh_GetPosRot(pl,oh,bit,(char)pl + ',',0,1);
      (pl->obj).rot.vz = (short)lVar2;
      return;
    }
    uVar4 = PJOY_JUMP | 0xf000;
    if ((pl->env1).Obj.primitive_top.Data[0x19] != 4) {
      uVar4 = uVar4 | PJOY_SHOT | PJOY_AIM;
    }
    uVar4 = (pl->m_obj).dummy1 & uVar4;
    if (uVar4 != 0) {
      (pl->m_obj).nAnim = (pl->m_obj).nAnim | uVar4;
      goto LAB_8003a4c8;
    }
    Task_Next();
    uVar4 = *(ushort *)&(pl->m_obj).Env.Obj.n_primitive;
  } while( true );
}



// decompiled code
// original method signature: 
// long /*$ra*/ Pafh_ChangeSide(struct _D3_OBJECT *ot /*$s5*/, long bit /*$s0*/)
 // line 494, offset 0x8003a508
	/* begin block 1 */
		// Start line: 495
		// Start offset: 0x8003A508
		// Variables:
	// 		struct _PLAYER *pl; // $s2
	// 		long dx; // $s1
	// 		long dy; // $s0
	// 		long obit; // $s3
	// 		long depth; // $s0
	/* end block 1 */
	// End offset: 0x8003A648
	// End Line: 530

	/* begin block 2 */
		// Start line: 1155
	/* end block 2 */
	// End Line: 1156

long Pafh_ChangeSide(_D3_OBJECT *ot,long bit)

{
  short sVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  char pos;
  _PLAYER *pl;
  long bit_00;
  
  pl = (_PLAYER *)TaskCurrent->local;
  if (bit == 0x800) {
    bit_00 = 0x400;
  }
  else {
    if (bit < 0x801) {
      if (bit == 0x400) {
        bit_00 = 0x800;
      }
    }
    else {
      if (bit == 0x1000) {
        bit_00 = 0x2000;
      }
      else {
        if (bit == 0x2000) {
          bit_00 = 0x1000;
        }
      }
    }
  }
  D3_SetHighBoxZ((_D3_OBJECT *)pl,(uint)*(ushort *)((pl->env2).Obj.primitive_top.Data + 10) - 0x32);
  Manim_SetAnim((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data,0x51);
  sVar1 = Boxes_GetDepth(ot,(short)bit);
  iVar2 = rcos((int)(pl->obj).rot.vz);
  iVar3 = rsin((int)(pl->obj).rot.vz);
  pos = (char)pl + ',';
  Fx_Play(6,pos);
  Pl_TurnBackRot(pl,iVar2 * (int)sVar1 * 4 >> 0xc,iVar3 * (int)sVar1 * 4 >> 0xc);
  D3_SetHighBoxZ((_D3_OBJECT *)pl,(uint)*(ushort *)((pl->env2).Obj.primitive_top.Data + 10));
  if (((int)(pl->obj).collision_state & 0xfc00U) != 0) {
    Pl_ForceAction(pl,9,0);
  }
  lVar4 = Pafh_GetPosRot(pl,ot,bit_00,pos,0,1);
  (pl->obj).rot.vz = (short)lVar4;
  return bit_00;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pafh_Move(struct _D3_OBJECT **oh /*$s6*/, long *bit /*$s7*/, long swing /*$a2*/)
 // line 537, offset 0x8003a694
	/* begin block 1 */
		// Start line: 538
		// Start offset: 0x8003A694
		// Variables:
	// 		struct _PLAYER *pl; // $s2
	// 		struct P_ACTH_7fake spos; // stack offset -56
	// 		long anm; // $a1
	// 		long anm_next; // stack offset -48
	// 		long joy; // $fp

		/* begin block 1.1 */
			// Start line: 563
			// Start offset: 0x8003A72C
			// Variables:
		// 		long h; // $s0
		// 		long h1; // $s3
		// 		long h2; // $a0
		// 		long hold; // $s5
		// 		long change; // $s4
		// 		struct _D3_OBJECT *ot1; // $s1
		// 		struct _D3_OBJECT *ot2; // $v1

			/* begin block 1.1.1 */
				// Start line: 595
				// Start offset: 0x8003A820
				// Variables:
			// 		long pente; // $s0
			/* end block 1.1.1 */
			// End offset: 0x8003A8E4
			// End Line: 609
		/* end block 1.1 */
		// End offset: 0x8003A8F8
		// End Line: 616
	/* end block 1 */
	// End offset: 0x8003A998
	// End Line: 634

	/* begin block 2 */
		// Start line: 1251
	/* end block 2 */
	// End Line: 1252

void Pafh_Move(_D3_OBJECT **oh,long *bit,long swing)

{
  bool bVar1;
  bool bVar2;
  _D3_OBJECT *p_Var3;
  short sVar4;
  int iVar5;
  ushort uVar6;
  long Anim;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  _PLAYER *pl;
  ushort uVar10;
  long local_30;
  
  pl = (_PLAYER *)TaskCurrent->local;
  uVar10 = (pl->m_obj).dummy1;
  if ((uVar10 & 0x8000) == 0) {
    if ((uVar10 & 0x2000) == 0) {
      return;
    }
    Anim = 0x16;
    local_30 = 0x17;
    uVar10 = 0x2000;
  }
  else {
    Anim = 0x18;
    local_30 = 0x19;
    uVar10 = 0x8000;
  }
  *(undefined2 *)&(pl->m_obj).Sq.Data.nSon = 0;
  (pl->m_obj).Ani.Anim.nPivot = 0x16;
  do {
    Manim_SetAnim((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data,Anim);
    while( true ) {
      bVar1 = false;
      if ((*(ushort *)&(pl->m_obj).Env.Obj.n_primitive & 0x4000) != 0) break;
      bVar2 = false;
      uVar7 = *(undefined4 *)&(pl->obj).pos;
      uVar8 = *(undefined4 *)&(pl->obj).pos.vz;
      Anim = Pafh_GetPosRot(pl,*oh,*bit,(char)pl + ',',0,1);
      (pl->obj).rot.vz = (short)Anim;
      iVar9 = (int)(pl->obj).pos.vz + 0xd2;
      Anim = Pl_TestHeight(pl,0x19);
      p_Var3 = Boxes_Object;
      iVar5 = Anim - iVar9;
      if (iVar5 < 0) {
        iVar5 = -iVar5;
      }
      Anim = Pl_TestHeight(pl,0x23);
      iVar9 = Anim - iVar9;
      if (iVar9 < 0) {
        iVar9 = -iVar9;
      }
      if ((p_Var3 == *oh) || (Boxes_Object == *oh)) {
        bVar2 = true;
      }
      else {
        if (iVar5 < 0x32) {
          *oh = p_Var3;
        }
        else {
          if (0x31 < iVar9) goto LAB_8003a804;
          *oh = Boxes_Object;
        }
        bVar2 = true;
        bVar1 = true;
      }
LAB_8003a804:
      if (bVar1) {
        Anim = Boxes_GetExtendedMaxZ(*oh);
        bVar1 = false;
        if (Anim != 0) {
          sVar4 = Boxes_GetBit((_D3_OBJECT *)pl,*oh);
          if (sVar4 == 0x800) {
            uVar6 = *(ushort *)&(*oh)[1].father ^ *(ushort *)&(*oh)[1].handle;
LAB_8003a8d4:
            bVar1 = uVar6 != 0;
          }
          else {
            if (0x800 < sVar4) {
              if (sVar4 == 0x1000) {
                uVar6 = (*oh)[1].collision_mode ^ *(ushort *)&(*oh)[1].handle;
              }
              else {
                if (sVar4 != 0x2000) goto LAB_8003a8d8;
                uVar6 = *(ushort *)&(*oh)[1].prec ^ *(ushort *)&(*oh)[1].father;
              }
              goto LAB_8003a8d4;
            }
            if (sVar4 == 0x400) {
              uVar6 = *(ushort *)&(*oh)[1].prec ^ (*oh)[1].collision_mode;
              goto LAB_8003a8d4;
            }
          }
LAB_8003a8d8:
          if (bVar1) {
            bVar2 = false;
          }
        }
      }
      if (!bVar2) {
        Pl_ForceAction(pl,9,0);
      }
      *(_D3_OBJECT **)&(pl->m_obj).Ani.Anim.Trans = *oh;
      sVar4 = Boxes_GetBit((_D3_OBJECT *)pl,*oh);
      *bit = (int)sVar4;
      *(undefined4 *)&(pl->obj).pos = uVar7;
      *(undefined4 *)&(pl->obj).pos.vz = uVar8;
      Task_Next();
    }
    Anim = Pafh_GetPosRot(pl,*oh,*bit,(char)pl + ',',0,1);
    uVar6 = (pl->m_obj).dummy1;
    (pl->obj).rot.vz = (short)Anim;
    Anim = local_30;
    if ((uVar6 & uVar10) == 0) {
      *(undefined2 *)&(pl->m_obj).Sq.Data.nSon = 0xffff;
      (pl->m_obj).Ani.Anim.nPivot = 0xffff;
      return;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pacth_Hold()
 // line 642, offset 0x8003a9c8
	/* begin block 1 */
		// Start line: 643
		// Start offset: 0x8003A9C8
		// Variables:
	// 		struct _PLAYER *pl; // $s1
	// 		struct _D3_OBJECT *oh; // stack offset -48
	// 		long bit; // stack offset -44
	// 		long swing; // $s2
	// 		long anm; // $a1
	// 		long climb; // $s7
	// 		long arriere; // $s6
	// 		long down; // $s4
	// 		long maxz; // $s3
	// 		long d; // $s0
	// 		long dx; // $s5
	// 		long dy; // $s0
	/* end block 1 */
	// End offset: 0x8003AD70
	// End Line: 775

	/* begin block 2 */
		// Start line: 1477
	/* end block 2 */
	// End Line: 1478

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pacth_Hold(void)

{
  bool bVar1;
  ushort uVar2;
  ushort uVar3;
  short bit;
  ushort uVar4;
  int iVar5;
  int iVar6;
  long Anim;
  short sVar7;
  char pos;
  short unaff_s0;
  int iVar8;
  M_OBJECT *obj;
  _PLAYER *pl;
  int unaff_s3;
  short unaff_s5;
  uint arriere;
  _D3_OBJECT *local_30;
  long local_2c;
  
  pl = (_PLAYER *)TaskCurrent->local;
  local_30 = (_D3_OBJECT *)TaskCurrent->event_param;
  TaskCurrent->event_enable = 0;
  uVar4 = (pl->m_obj).shadow.y1;
  bit = (pl->m_obj).shadow.y1;
  *(_D3_OBJECT **)&(pl->m_obj).Ani.Anim.Trans = local_30;
  arriere = (int)bit & 0x8000;
  uVar3 = uVar4 & 0x4000;
  (pl->m_obj).shadow.y1 = uVar4 & 0x3fff;
  if (uVar3 != 0) {
    iVar8 = 100;
    if (arriere != 0) {
      iVar8 = -100;
    }
    iVar5 = rcos((int)(pl->obj).rot.vz);
    iVar6 = rsin((int)(pl->obj).rot.vz);
    unaff_s5 = (short)(iVar5 * iVar8 >> 0xc);
    (pl->obj).pos.vx = (pl->obj).pos.vx + unaff_s5;
    unaff_s0 = (short)(iVar6 * iVar8 >> 0xc);
    (pl->obj).pos.vy = (pl->obj).pos.vy + unaff_s0;
  }
  bit = Boxes_GetBit((_D3_OBJECT *)pl,local_30);
  local_2c = (long)bit;
  if (local_2c == 0x800) {
LAB_8003aae8:
    unaff_s3 = (int)*(short *)&local_30[1].handle;
  }
  else {
    if (local_2c < 0x801) {
      if (local_2c != 0x400) goto LAB_8003aaf4;
    }
    else {
      if (local_2c == 0x1000) goto LAB_8003aae8;
      if (local_2c != 0x2000) goto LAB_8003aaf4;
    }
    unaff_s3 = (int)*(short *)&local_30[1].prec;
  }
LAB_8003aaf4:
  bVar1 = unaff_s3 - (int)(local_30->b_box).vz < 0x33;
  uVar4 = Boxes_GetDepth(local_30,bit);
  if (uVar3 != 0) {
    (pl->obj).pos.vx = (pl->obj).pos.vx - unaff_s5;
    (pl->obj).pos.vy = (pl->obj).pos.vy - unaff_s0;
    bit = (pl->obj).pos.vz;
    iVar8 = unaff_s3 + (int)(local_30->pos).vz;
    sVar7 = (short)iVar8;
    if (iVar8 < (int)bit) {
      sVar7 = bit;
    }
    (pl->obj).pos.vz = sVar7;
    Anim = Pafh_GoDown(local_30,local_2c,arriere);
    if (Anim == 0) {
      return;
    }
  }
  pos = (char)pl + ',';
  Fx_Play(5,pos);
  Anim = Pafh_GetPosRot(pl,local_30,local_2c,pos,0,1);
  (pl->obj).rot.vz = (short)Anim;
  if (bVar1) {
    Pafh_Swing(local_30,local_2c);
  }
  else {
    iVar8 = (int)*(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x16);
    if (((iVar8 - 0x39U < 2) || (iVar8 == 0x41)) || (iVar8 == 0x40)) {
      Anim = 0x44;
    }
    else {
      Anim = 0x29;
    }
    obj = (M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data;
    Manim_SetAnim(obj,Anim);
    Manim_WaitAnim(obj);
  }
  Anim = Pafh_GetPosRot(pl,local_30,local_2c,(char)pl + ',',0,1);
  (pl->obj).rot.vz = (short)Anim;
LAB_8003ac34:
  do {
    Manim_SetAnim((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data,0x29);
    uVar2 = PJOY_AIM;
    uVar3 = *(ushort *)&(pl->m_obj).Env.Obj.n_primitive;
    *(undefined2 *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x18) = 0xe0;
    *(ushort *)&(pl->m_obj).Env.Obj.n_primitive = uVar3 & 0xfffe;
    if ((ushort)((pl->m_obj).dummy1 & (PJOY_SHOT | uVar2)) != 0) {
      Anim = Pafh_Shot(local_30,local_2c,(uint)bVar1);
      if (Anim != 0) goto LAB_8003ac34;
    }
    if ((bVar1) && (((pl->m_obj).nAnim & PJOY_JUMP) != 0)) {
      Pafh_Swing(local_30,local_2c);
    }
    else {
      if (((pl->m_obj).nAnim & 0x4000U) != 0) {
        Pl_ForceAction(pl,9,0);
      }
      if (((pl->m_obj).nAnim & 0x1000U) == 0) {
LAB_8003ad44:
        Pafh_Move(&local_30,&local_2c,(uint)bVar1);
        Task_Next();
      }
      else {
        if ((int)((uint)uVar4 << 0x10) < 0x190001) {
          if (!bVar1) goto LAB_8003ad44;
          local_2c = Pafh_ChangeSide(local_30,local_2c);
        }
        else {
          Anim = Pafh_GoUp(2,local_30,local_2c);
          if (Anim != 0) {
            TaskCurrent->event_enable = 1;
            return;
          }
        }
      }
    }
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pacth_Grabbed()
 // line 780, offset 0x8003ad9c
	/* begin block 1 */
		// Start line: 781
		// Start offset: 0x8003AD9C
		// Variables:
	// 		struct _PLAYER *pl; // $s1
	// 		struct _D3_OBJECT *ot; // $fp
	// 		struct M_OBJECT *mot; // $s5
	// 		struct P_ACTH_7fake rot; // stack offset -48
	// 		long time; // $s0
	// 		long frt; // $s2
	// 		long x; // $s4
	// 		long y; // $s3
	// 		long r; // $s2
	// 		long sx; // $s7
	// 		long sy; // $s6
	// 		long sr; // $s0
	/* end block 1 */
	// End offset: 0x8003AFCC
	// End Line: 849

	/* begin block 2 */
		// Start line: 1819
	/* end block 2 */
	// End Line: 1820

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pacth_Grabbed(void)

{
  short sVar1;
  ushort uVar2;
  short sVar3;
  TASK *pTVar4;
  long lVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  void *pvVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  M_OBJECT *obj;
  int iVar14;
  
  pTVar4 = TaskCurrent;
  iVar14 = TaskCurrent->event_param;
  TaskCurrent->event_enable = 0;
  obj = *(M_OBJECT **)(iVar14 + 0x24);
  pvVar10 = pTVar4->local;
  lVar5 = Manim_GetEventTime(obj,0x4000);
  uVar2 = *(ushort *)&(obj->Env).nPivot;
  *(undefined4 *)((int)pvVar10 + 0xb0) = *(undefined4 *)((obj->Sq).Data.FatherTrans + 2);
  Manim_SetAnim((M_OBJECT *)((int)pvVar10 + 0xa4),5);
  *(undefined2 *)((int)pvVar10 + 0xbc) = (short)(((int)((uint)uVar2 << 0x10) >> 0x14) << 4);
  iVar6 = ((int)*(short *)(iVar14 + 0x2c) - (int)*(short *)((int)pvVar10 + 0x2c)) * 0x10000;
  if (lVar5 == 0) {
    trap(0x1c00);
  }
  if ((lVar5 == -1) && (iVar6 == -0x80000000)) {
    trap(0x1800);
  }
  iVar7 = ((int)*(short *)(iVar14 + 0x2e) - (int)*(short *)((int)pvVar10 + 0x2e)) * 0x10000;
  if (lVar5 == 0) {
    trap(0x1c00);
  }
  if ((lVar5 == -1) && (iVar7 == -0x80000000)) {
    trap(0x1800);
  }
  iVar12 = (int)*(short *)((int)pvVar10 + 0x2e) << 0x10;
  iVar11 = (int)*(short *)((int)pvVar10 + 0x40) << 0x10;
  iVar8 = ((int)*(short *)(iVar14 + 0x40) - (int)*(short *)((int)pvVar10 + 0x40)) * 0x10000;
  uVar2 = (obj->Env).Obj.vert_top.pad;
  if (lVar5 == 0) {
    trap(0x1c00);
  }
  if ((lVar5 == -1) && (iVar8 == -0x80000000)) {
    trap(0x1800);
  }
  iVar13 = (int)*(short *)((int)pvVar10 + 0x2c) * 0x10000;
  while ((uVar2 & 0x4000) == 0) {
    iVar13 = iVar13 + iVar6 / lVar5;
    iVar12 = iVar12 + iVar7 / lVar5;
    iVar11 = iVar11 + iVar8 / lVar5;
    *(undefined2 *)((int)pvVar10 + 0x2c) = (short)((uint)iVar13 >> 0x10);
    *(undefined2 *)((int)pvVar10 + 0x2e) = (short)((uint)iVar12 >> 0x10);
    *(undefined2 *)((int)pvVar10 + 0x40) = (short)((uint)iVar11 >> 0x10);
    Task_Next();
    uVar2 = (obj->Env).Obj.vert_top.pad;
  }
  sVar1 = *(short *)((int)&(obj->Env).Version + 2);
  sVar3 = *(short *)((int)&(obj->Env).Version + 2);
  while (sVar1 < 2) {
    uVar2 = *(ushort *)&(obj->Env).nPivot;
    Manim_SetAnim((M_OBJECT *)((int)pvVar10 + 0xa4),(int)sVar3 + 5);
    *(undefined2 *)((int)pvVar10 + 0xbc) = (short)(((int)((uint)uVar2 << 0x10) >> 0x14) << 4);
    *(ushort *)((int)pvVar10 + 0xcc) = *(ushort *)((int)pvVar10 + 0xcc) & 0xfffe;
    uVar9 = *(undefined4 *)(iVar14 + 0x30);
    *(undefined4 *)((int)pvVar10 + 0x2c) = *(undefined4 *)(iVar14 + 0x2c);
    *(undefined4 *)((int)pvVar10 + 0x30) = uVar9;
    *(short *)((int)pvVar10 + 0x30) = *(short *)((int)pvVar10 + 0x30) + -0x69;
    Task_Next();
    sVar1 = *(short *)((int)&(obj->Env).Version + 2);
    sVar3 = *(short *)((int)&(obj->Env).Version + 2);
  }
  do {
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pacth_Dropped()
 // line 852, offset 0x8003afcc
	/* begin block 1 */
		// Start line: 853
		// Start offset: 0x8003AFCC
	/* end block 1 */
	// End offset: 0x8003AFCC
	// End Line: 853

	/* begin block 2 */
		// Start line: 2014
	/* end block 2 */
	// End Line: 2015

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pacth_Dropped(void)

{
  Pl_SetAction((_PLAYER *)TaskCurrent->local,3,0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pacth_Climb()
 // line 862, offset 0x8003affc
	/* begin block 1 */
		// Start line: 863
		// Start offset: 0x8003AFFC
		// Variables:
	// 		struct _PLAYER *pl; // $s1
	// 		struct _D3_OBJECT *oh; // $s2
	// 		long anm; // $s0
	// 		long frame; // $s0
	// 		long h; // $s4
	// 		long arriere; // $a2
	// 		long zmax; // $s7
	// 		long zmin; // $s6
	// 		long look; // $v1
	// 		long cz; // $s5
	// 		long rc; // $s0
	// 		long rs; // $v0
	// 		long tx; // $a1
	// 		long ty; // $v1
	/* end block 1 */
	// End offset: 0x8003B504
	// End Line: 1031

	/* begin block 2 */
		// Start line: 2038
	/* end block 2 */
	// End Line: 2039

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pacth_Climb(void)

{
  bool bVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  ushort uVar6;
  ushort uVar7;
  ushort uVar8;
  TASK *pTVar9;
  _ZONE *Param;
  int iVar10;
  int iVar11;
  uint uVar12;
  int Anim;
  long Anim_00;
  int iVar13;
  int Anim_01;
  _PLAYER *pl;
  _D3_OBJECT *oh;
  M_OBJECT *obj;
  int iVar14;
  int iVar15;
  
  pTVar9 = TaskCurrent;
  pl = (_PLAYER *)TaskCurrent->local;
  TaskCurrent->event_enable = 0;
  sVar2 = (pl->m_obj).shadow.y1;
  *(ushort *)&(pl->m_obj).shadow.u0 = *(ushort *)&(pl->m_obj).shadow.u0 | 0x10;
  oh = (_D3_OBJECT *)pTVar9->event_param;
  uVar6 = (pl->m_obj).shadow.y1;
  iVar11 = (int)(oh->pos).vz;
  sVar3 = *(short *)&oh[1].prec;
  Anim_01 = (int)(oh->b_box).vz;
  *(_D3_OBJECT **)&(pl->m_obj).Ani.Anim.Trans = oh;
  (pl->m_obj).shadow.y1 = uVar6 & 0x7fff;
  sVar4 = *(short *)&oh[1].prec;
  sVar5 = (oh->b_box).vz;
  iVar15 = iVar11 + (int)sVar3 + -200;
  iVar14 = iVar11 + Anim_01 + 0x10;
  uVar12 = iVar11 * 2 + Anim_01 + (int)sVar3;
  iVar11 = (int)(uVar12 + (uVar12 >> 0x1f)) >> 1;
  if (((uint)(ushort)oh[1].pos.vz - 1 < 2) && ((int)(pl->obj).pos.vz == iVar11 + -100)) {
    Anim_00 = 0xb;
  }
  else {
    iVar10 = (int)(pl->obj).pos.vz;
    Anim_01 = iVar10 - ((int)(oh->pos).vz + (int)*(short *)&oh[1].prec);
    if (Anim_01 < 0) {
      Anim_01 = -Anim_01;
    }
    Anim = -1;
    if ((9 < Anim_01) && (Anim = 6, iVar14 < iVar10)) {
      Anim = 0xc;
    }
    if (Anim < 0) {
      Anim_00 = Pafh_GoDown(oh,0,(int)sVar2 & 0x8000);
      if (Anim_00 == 0) {
        return;
      }
    }
    else {
      Manim_SetAnim((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data,Anim);
      Pl_AdjustUse(pl,(char)oh + ',',(int)(oh->rot).vz,1);
    }
    Anim_00 = 7;
  }
  obj = (M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data;
  Manim_SetAnim((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data,Anim_00);
LAB_8003b1a4:
  do {
    uVar8 = PJOY_JUMP;
    uVar6 = (pl->m_obj).nAnim;
    uVar7 = uVar6 & PJOY_JUMP;
    *(short *)&(pl->m_obj).Env.Obj.scale =
         (short)(((((int)sVar4 - (int)sVar5) % 300) * 0x80) / 0x96) + 0x100;
    if (uVar7 != 0) {
      (pl->m_obj).nAnim = uVar6 & ~uVar8;
      Pl_ForceAction(pl,9,0);
    }
    bVar1 = ((pl->m_obj).dummy1 & PJOY_AIM) == 0;
    if (bVar1) {
      *(undefined2 *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x24) = 0;
      *(undefined2 *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x26) = 0;
    }
    else {
      Paf_Look(pl);
    }
    bVar1 = !bVar1;
    if ((((bVar1) || (Anim_01 = 7, ((pl->m_obj).dummy1 & 0x1000U) == 0)) && (Anim_01 = -1, !bVar1))
       && (((pl->m_obj).dummy1 & 0x4000U) != 0)) {
      Anim_01 = 0xb;
    }
    if (Anim_01 == 7) {
      if ((oh[1].pos.vz == 1) && (iVar11 + -0x4b < (int)(pl->obj).pos.vz)) {
        Param = Zone_GetObjectExit(oh);
        Pl_ForceAction(pl,1,(long)Param);
      }
      if (iVar15 <= (int)(pl->obj).pos.vz) {
        (pl->obj).pos.vz = (short)iVar15;
        Anim_00 = Pafh_GoUp(9,oh,0x400);
        if (Anim_00 != 0) goto LAB_8003b4e8;
        Manim_SetAnim((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data,7);
        goto LAB_8003b1a4;
      }
      if (*(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x16) != 0xb) goto LAB_8003b3fc;
      sVar2 = *(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x18);
      iVar10 = *(int *)(*(int *)((pl->m_obj).Env.Obj.primitive_top.Data + 0xc) + 0x34);
LAB_8003b3dc:
      sVar3 = *(short *)(iVar10 + 6);
      Manim_SetAnim((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data,Anim_01);
      *(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x18) = (sVar3 - (sVar2 >> 4)) * 0x10;
LAB_8003b430:
      *(undefined2 *)((int)&(pl->m_obj).Env.Obj.n_primitive + 2) = 0;
    }
    else {
      if (Anim_01 != 0xb) {
        if (((int)*(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x22) & 0x8000U) != 0) {
          *(ushort *)&(pl->m_obj).Env.Obj.n_primitive =
               *(ushort *)&(pl->m_obj).Env.Obj.n_primitive & 0xfffe;
        }
        goto LAB_8003b430;
      }
      if ((oh[1].pos.vz == 2) && ((int)(pl->obj).pos.vz < iVar11 + -0x7d)) {
        Param = Zone_GetObjectExit(oh);
        Pl_ForceAction(pl,1,(long)Param);
      }
      if ((int)(pl->obj).pos.vz <= iVar14) {
        (pl->obj).pos.vz = (short)iVar14;
        Anim_00 = Pl_TestHeight(pl,0);
        if (Anim_00 < (int)(oh->pos).vz + (int)(oh->b_box).vz + -0x10) {
          Manim_SetAnim(obj,8);
          Manim_WaitAnim(obj);
          Pl_ForceAction(pl,9,0);
        }
        Manim_SetAnim(obj,10);
        Manim_WaitAnim(obj);
LAB_8003b4e8:
        pTVar9 = TaskCurrent;
        *(ushort *)&(pl->m_obj).shadow.u0 = *(ushort *)&(pl->m_obj).shadow.u0 & 0xffef;
        pTVar9->event_enable = 1;
        return;
      }
      if (*(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x16) == 7) {
        sVar2 = *(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x18);
        iVar10 = *(int *)(*(int *)((pl->m_obj).Env.Obj.primitive_top.Data + 0xc) + 0x24);
        goto LAB_8003b3dc;
      }
LAB_8003b3fc:
      Manim_SetAnim((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data,Anim_01);
      *(undefined2 *)((int)&(pl->m_obj).Env.Obj.n_primitive + 2) = 0;
    }
    Anim_01 = rcos((int)(oh->rot).vz);
    iVar10 = rsin((int)(oh->rot).vz);
    Anim = *(int *)(*(int *)((pl->m_obj).Env.Obj.primitive_top.Data + 0xc) +
                    (int)*(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x16) * 4 + 8) +
           ((int)((uint)*(ushort *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x18) << 0x10) >> 0x14)
           * 8;
    iVar13 = (int)*(short *)(Anim + 0x14);
    Anim = (int)*(short *)(Anim + 0x16);
    (pl->obj).pos.vx = (oh->pos).vx + (short)(Anim_01 * iVar13 - iVar10 * Anim >> 0xc);
    (pl->obj).pos.vy = (oh->pos).vy + (short)(iVar10 * iVar13 + Anim_01 * Anim >> 0xc);
    Task_Next();
  } while( true );
}





