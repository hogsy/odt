#include "THISDUST.H"
#include "P_ACTJ.H"


// decompiled code
// original method signature: 
// void /*$ra*/ Pactj_Fall()
 // line 19, offset 0x800383d4
	/* begin block 1 */
		// Start line: 20
		// Start offset: 0x800383D4
		// Variables:
	// 		struct _PLAYER *pl; // $s0
	// 		long side; // $s2
	// 		long anm; // $s1
	// 		long atxy; // $s3
	/* end block 1 */
	// End offset: 0x80038550
	// End Line: 88

	/* begin block 2 */
		// Start line: 39
	/* end block 2 */
	// End Line: 40

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pactj_Fall(void)

{
  ushort uVar1;
  long dist;
  int iVar2;
  _PLAYER *pl;
  int Anim;
  short sxy;
  int iVar3;
  undefined2 uVar4;
  
  iVar3 = 1;
  pl = (_PLAYER *)TaskCurrent->local;
  Anim = -1;
  TaskCurrent->event_enable = 0;
  uVar1 = (pl->m_obj).shadow.clut;
  uVar4 = 0x100;
  if ((uVar1 & 0x10) != 0) {
    iVar3 = -1;
  }
  sxy = (short)iVar3;
  if (((uVar1 & 0x1000) == 0) ||
     ((*(ushort *)
        (*(int *)(*(int *)((pl->m_obj).Env.Obj.primitive_top.Data + 0xc) +
                  (int)*(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x16) * 4 + 8) + 10) & 4)
      == 0)) {
    iVar2 = *(int *)((pl->m_obj).Env.Obj.primitive_top.Data + 0xc);
    uVar1 = *(ushort *)
             (*(int *)(iVar2 + (int)*(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x16) * 4 +
                      8) + 10);
    if ((uVar1 & 2) == 0) {
      if (((pl->m_obj).shadow.clut & 2) == 0) {
        if (iVar3 < 0) {
          if ((uVar1 & 4) == 0) {
            dist = Manim_GetEventTX((char)iVar2,0x42,0x8000);
            dist = Pl_TestHeight(pl,dist);
            Anim = 0x42;
            if (dist < (int)(pl->obj).pos.vz + -300) {
              Anim = 0x32;
            }
          }
        }
        else {
          if ((uVar1 & 4) == 0) {
            Anim = 0x35;
            uVar4 = 0x80;
          }
        }
      }
      else {
        Anim = 0x3b;
        sxy = -1;
      }
    }
  }
  else {
    D3_SetHighBoxZ((_D3_OBJECT *)pl,(uint)(*(ushort *)((pl->env2).Obj.primitive_top.Data + 10) >> 1)
                  );
    *(ushort *)&(pl->m_obj).shadow.u0 = *(ushort *)&(pl->m_obj).shadow.u0 | 0x1000;
  }
  if (-1 < Anim) {
    Manim_SetAnim((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data,Anim);
    *(undefined2 *)((int)&(pl->m_obj).Env.Obj.n_primitive + 2) = uVar4;
  }
  Pafj_ExecJpDown(sxy);
  if ((*(ushort *)&(pl->m_obj).shadow.u0 & 0x1000) != 0) {
    Pl_ForceAction(pl,0x12,1);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pactj_Jump()
 // line 91, offset 0x8003856c
	/* begin block 1 */
		// Start line: 92
		// Start offset: 0x8003856C
		// Variables:
	// 		struct _PLAYER *pl; // $s4
	// 		struct _D3_OBJECT *oh; // $s0
	// 		struct _D3_OBJECT *ohr; // $s5
	// 		struct _D3_OBJECT (*ho[13]); // stack offset -320
	// 		struct _D3_OBJECT (*hog[13]); // stack offset -264
	// 		struct _D3_OBJECT (*hogr[13]); // stack offset -208
	// 		short hs[13]; // stack offset -152
	// 		short hsg[13]; // stack offset -120
	// 		short hsgr[13]; // stack offset -88
	// 		long h; // $s1
	// 		long dist; // $s3
	// 		long dist_max; // $fp
	// 		long anm; // $a0
	// 		long slide; // stack offset -56
	// 		long first; // $s0
	/* end block 1 */
	// End offset: 0x80038CA0
	// End Line: 292

	/* begin block 2 */
		// Start line: 195
	/* end block 2 */
	// End Line: 196

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pactj_Jump(void)

{
  ushort uVar1;
  uint uVar2;
  bool bVar3;
  short dist;
  short anm;
  long lVar4;
  long lVar5;
  int iVar6;
  _D3_OBJECT **pp_Var7;
  _D3_OBJECT *Param;
  int iVar8;
  short anm_00;
  int iVar9;
  short *psVar10;
  _D3_OBJECT *ot;
  short *psVar11;
  _D3_OBJECT **pp_Var12;
  int iVar13;
  _PLAYER *pl;
  int dist_00;
  _D3_OBJECT *local_140 [14];
  _D3_OBJECT *local_108;
  _D3_OBJECT *local_104 [13];
  _D3_OBJECT *local_d0;
  _D3_OBJECT *local_cc [13];
  short local_98 [16];
  short local_78;
  short local_76 [15];
  short local_58;
  short local_56 [15];
  int local_38;
  short *local_34;
  _D3_OBJECT **local_30;
  
  iVar13 = 1;
  local_34 = local_98;
  local_30 = local_140;
  pp_Var7 = local_140;
  psVar11 = local_98;
  pp_Var12 = local_104;
  dist_00 = 0;
  pl = (_PLAYER *)TaskCurrent->local;
  psVar10 = local_76;
  Paf_TestUse();
  uVar1 = (pl->m_obj).shadow.clut;
  TaskCurrent->event_enable = 0;
  local_38 = (int)(short)(uVar1 & 0x100);
  lVar4 = Pl_TestHeight(pl,0);
  local_98[0] = (pl->obj).pos.vz;
  local_140[0] = Boxes_Object;
  local_108 = Boxes_Object;
  local_78 = local_98[0];
  do {
    pp_Var7 = pp_Var7 + 1;
    psVar11 = psVar11 + 1;
    lVar5 = Pl_TestHeight(pl,iVar13 << 4);
    Param = Boxes_Object;
    *pp_Var12 = Boxes_Object;
    if (Param == local_108) {
      *psVar10 = local_78;
    }
    else {
      *psVar10 = (short)lVar5;
    }
    if ((int)*(short *)((int)local_34 + dist_00) < lVar5) {
      *psVar11 = (short)lVar5;
      *pp_Var7 = *pp_Var12;
    }
    else {
      *psVar11 = *(short *)((int)local_34 + dist_00);
      *pp_Var7 = local_30[iVar13 + -1];
    }
    pp_Var12 = pp_Var12 + 1;
    dist_00 = dist_00 + 2;
    iVar13 = iVar13 + 1;
    psVar10 = psVar10 + 1;
  } while (iVar13 < 0xd);
  dist_00 = 1;
  iVar13 = 0;
  local_98[0] = (short)lVar4;
  local_78 = local_98[0];
  do {
    Param = local_140[dist_00];
    if ((Param != (_D3_OBJECT *)0x0) && ((*(uint *)&Param[1].pos & 0xffffff00) == 0xf00)) {
      iVar9 = (int)(Param->pos).vz;
      iVar6 = iVar9 + (int)(Param->b_box).vz;
      if ((int)*(short *)((int)local_98 + iVar13) <= iVar6) {
        iVar8 = (int)(pl->obj).pos.vz;
        iVar6 = iVar6 - iVar8;
        if (iVar6 < 0) {
          iVar6 = -iVar6;
        }
        if ((iVar6 < 10) && (iVar8 + 100 < iVar9 + (int)*(short *)&Param[1].prec)) {
          iVar6 = DeltaDirection((int)(Param->rot).vz,(int)(pl->obj).rot.vz);
          if (iVar6 < 0) {
            iVar6 = -iVar6;
          }
          if (iVar6 < 0x200) {
            Pl_ForceAction(pl,0xe,(long)Param);
          }
        }
      }
    }
    dist_00 = dist_00 + 1;
    iVar13 = iVar13 + 2;
  } while (dist_00 < 10);
  lVar4 = Manim_GetEventTX((char)*(undefined4 *)((pl->m_obj).Env.Obj.primitive_top.Data + 0xc),0x2e,
                           0x4000);
  iVar13 = lVar4 << 1;
  anm_00 = local_98[iVar13 >> 4];
  dist_00 = (int)(pl->obj).pos.vz;
  Param = local_140[iVar13 >> 4];
  if ((dist_00 + 0x96 < (int)anm_00) && ((int)anm_00 < dist_00 + 0xfa)) {
    if (((int)(dist_00 + (uint)*(ushort *)((pl->env2).Obj.primitive_top.Data + 10)) <=
         (int)(Param->pos).vz + (int)(Param->b_box).vz) &&
       (iVar13 = 0, local_140[2] == local_140[0])) {
      dist_00 = 3;
      pp_Var7 = local_140 + 3;
      do {
        iVar13 = dist_00 << 4;
        if (*pp_Var7 == Param) goto LAB_80038854;
        dist_00 = dist_00 + 1;
        pp_Var7 = pp_Var7 + 1;
      } while (dist_00 < 10);
      iVar13 = dist_00 * 0x10;
LAB_80038854:
      iVar13 = iVar13 + 8;
    }
    dist = (short)iVar13;
    anm = 0x2e;
    if (iVar13 != 0) goto LAB_80038b5c;
  }
  if (((pl->m_obj).shadow.clut & 0x800) != 0) {
    lVar4 = Manim_GetEventTX((char)*(undefined4 *)((pl->m_obj).Env.Obj.primitive_top.Data + 0xc),
                             0x37,0x4000);
    iVar13 = lVar4 * 5;
    if (iVar13 < 0) {
      iVar13 = iVar13 + 3;
    }
    dist_00 = (int)(pl->obj).pos.vz;
    anm_00 = local_98[iVar13 >> 6];
    if ((dist_00 + 0x3c < (int)anm_00) && ((int)anm_00 <= dist_00 + 0x96)) {
      *(ushort *)&(pl->m_obj).shadow.u0 = *(ushort *)&(pl->m_obj).shadow.u0 | 0x800;
      Pafj_ExecJpUp(0x37,anm_00,0);
      return;
    }
  }
  iVar13 = *(int *)(*(int *)((pl->m_obj).Env.Obj.primitive_top.Data + 0xc) + 0xd8);
  uVar2 = (int)*(short *)(iVar13 + ((uint)*(ushort *)(iVar13 + 6) - 1) * 8 + 0x14) * 3;
  iVar13 = uVar2 + (uVar2 >> 0x1f);
  dist_00 = (int)(pl->obj).pos.vz;
  anm_00 = local_98[iVar13 >> 5];
  if (((int)anm_00 <= dist_00 + 0x3c) || (dist_00 + 0x96 < (int)anm_00)) {
    lVar4 = Manim_GetEventTX((char)*(undefined4 *)((pl->m_obj).Env.Obj.primitive_top.Data + 0xc),
                             0x2d,0x4000);
    if ((lVar4 << 1) >> 4 < 0xe) {
      lVar4 = Manim_GetEventTX((char)*(undefined4 *)((pl->m_obj).Env.Obj.primitive_top.Data + 0xc),
                               0x2d,0x4000);
      iVar13 = (lVar4 << 1) >> 4;
    }
    else {
      iVar13 = 0xd;
    }
    Pl_TestHeight(pl,-0x10);
    Param = Boxes_Object;
    dist_00 = 0;
    if (0 < iVar13) {
      pp_Var7 = local_140;
      do {
        ot = *pp_Var7;
        anm_00 = local_98[dist_00];
        if ((ot == (_D3_OBJECT *)0x0) || (lVar4 = Boxes_GetExtendedMaxZ(ot), lVar4 == 0)) {
LAB_80038aa4:
          if (((*pp_Var7 != Param) && (iVar6 = (int)(pl->obj).pos.vz, iVar6 + 0xfa <= (int)anm_00))
             && (anm = 0x2d, (int)anm_00 <= iVar6 + 0x140)) {
            dist = (short)dist_00 * 0x10 + 1;
            goto LAB_80038b5c;
          }
        }
        else {
          dist = Boxes_GetBit((_D3_OBJECT *)pl,ot);
          if (dist == 0x800) {
            dist = *(short *)&ot[1].father;
            anm = *(short *)&ot[1].handle;
          }
          else {
            if (dist < 0x801) {
              if (dist != 0x400) goto LAB_80038aa4;
              dist = *(short *)&ot[1].prec;
              anm = ot[1].collision_mode;
            }
            else {
              if (dist == 0x1000) {
                dist = ot[1].collision_mode;
                anm = *(short *)&ot[1].handle;
              }
              else {
                if (dist != 0x2000) goto LAB_80038aa4;
                dist = *(short *)&ot[1].prec;
                anm = *(short *)&ot[1].father;
              }
            }
          }
          if (dist == anm) goto LAB_80038aa4;
        }
        dist_00 = dist_00 + 1;
        pp_Var7 = pp_Var7 + 1;
      } while (dist_00 < iVar13);
    }
    anm_00 = 0x38;
    if (local_38 == 0) {
      if ((((pl->m_obj).dummy1 & 0x1000U) == 0) && (((pl->m_obj).shadow.clut & 0x800) == 0)) {
        Manim_SetAnim((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data,0x36);
        bVar3 = true;
        uVar1 = *(ushort *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x22);
        *(undefined2 *)&(pl->m_obj).Env.Obj.scale = 0x180;
        do {
          if ((uVar1 & 0x1000) == 0) {
            Fx_Play(6,(char)pl + ',');
            Pafj_ExecJpDown(0);
            return;
          }
          uVar1 = (pl->m_obj).dummy1;
          if ((uVar1 & 0x4000) == 0) {
            anm_00 = 0x3a;
            if ((uVar1 & 0x1000) != 0) goto LAB_80038b70;
          }
          else {
            Pafh_TestHoldDown(pl,&local_108,&local_78,0);
            iVar13 = 1;
            if (bVar3) {
              psVar11 = local_56;
              pp_Var7 = local_cc;
              dist_00 = -0x10;
              local_58 = local_78;
              local_d0 = local_108;
              do {
                lVar4 = Pl_TestHeight(pl,dist_00);
                Param = Boxes_Object;
                *psVar11 = (short)lVar4;
                *pp_Var7 = Param;
                if (Param == local_d0) {
                  *psVar11 = local_58;
                }
                psVar11 = psVar11 + 1;
                pp_Var7 = pp_Var7 + 1;
                iVar13 = iVar13 + 1;
                dist_00 = dist_00 + -0x10;
              } while (iVar13 < 10);
              bVar3 = false;
            }
            Pafh_TestHoldDown(pl,&local_d0,&local_58,0x8000);
          }
          Task_Next();
          uVar1 = *(ushort *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x22);
        } while( true );
      }
      anm_00 = 0x39;
      if (((pl->m_obj).shadow.clut & 0x800) == 0) {
        anm_00 = 0x3a;
      }
      else {
        *(ushort *)&(pl->m_obj).shadow.u0 = *(ushort *)&(pl->m_obj).shadow.u0 | 0x800;
      }
    }
LAB_80038b70:
    Pafj_ExecJpUp(anm_00,0,0);
    return;
  }
  dist = (short)(((iVar13 >> 1) << 2) / 3);
  anm = 0x34;
LAB_80038b5c:
  Pafj_ExecJpUp(anm,anm_00,dist);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pafj_ExecJpUp(short anm /*$a0*/, short h /*$a1*/, short dist /*$a2*/)
 // line 297, offset 0x80038cd0
	/* begin block 1 */
		// Start line: 298
		// Start offset: 0x80038CD0
		// Variables:
	// 		struct _PLAYER *pl; // $s0
	// 		short az; // $a0
	/* end block 1 */
	// End offset: 0x80038ED4
	// End Line: 360

	/* begin block 2 */
		// Start line: 898
	/* end block 2 */
	// End Line: 899

/* WARNING: Type propagation algorithm not settling */

void Pafj_ExecJpUp(short anm,short h,short dist)

{
  short sVar1;
  long lVar2;
  int iVar3;
  M_OBJECT *obj;
  _PLAYER *pl;
  int Anim;
  
  Anim = (int)anm;
  pl = (_PLAYER *)TaskCurrent->local;
  *(ushort *)&(pl->m_obj).shadow.u0 = *(ushort *)&(pl->m_obj).shadow.u0 | 1;
  Manim_ForceAnim((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data,Anim);
  Fx_Play(6,(char)pl + ',');
  if (Anim == 0x38) {
    *(undefined2 *)((int)&(pl->m_obj).Env.Obj.n_primitive + 2) = 0x280;
  }
  if ((int)dist != 0) {
    lVar2 = Manim_GetEventTX((char)*(undefined4 *)((pl->m_obj).Env.Obj.primitive_top.Data + 0xc),
                             Anim,0x4000);
    iVar3 = ((int)dist + -0xf) * 0x100;
    if (lVar2 == 0) {
      trap(0x1c00);
    }
    if ((lVar2 == -1) && (iVar3 == -0x80000000)) {
      trap(0x1800);
    }
    *(undefined2 *)((int)&(pl->m_obj).Env.Obj.n_primitive + 2) = (short)(iVar3 / lVar2);
  }
  if (h == 0) {
    *(undefined2 *)&(pl->m_obj).Env.Obj.scale = 0x180;
  }
  else {
    if (Anim == 0x2d) {
      lVar2 = Manim_GetEventTZ((char)*(undefined4 *)((pl->m_obj).Env.Obj.primitive_top.Data + 0xc),
                               0x2d,0x4000);
      sVar1 = (short)lVar2;
      iVar3 = ((uint)(ushort)h - 0xd2) - (uint)(ushort)(pl->obj).pos.vz;
    }
    else {
      Anim = *(int *)(*(int *)((pl->m_obj).Env.Obj.primitive_top.Data + 0xc) + Anim * 4 + 8);
      iVar3 = ((uint)(ushort)h + 0xf) - (uint)(ushort)(pl->obj).pos.vz;
      sVar1 = *(short *)(Anim + ((uint)*(ushort *)(Anim + 6) - 1) * 8 + 0x18);
    }
    iVar3 = (iVar3 << 0x10) >> 8;
    Anim = (int)sVar1;
    if (Anim == 0) {
      trap(0x1c00);
    }
    if ((Anim == -1) && (iVar3 == -0x80000000)) {
      trap(0x1800);
    }
    *(short *)&(pl->m_obj).Env.Obj.scale = (short)(iVar3 / Anim);
  }
  obj = (M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data;
  if (*(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x16) == 0x37) {
    Manim_WaitEvent(obj,0x4000);
    while (((*(ushort *)&(pl->m_obj).Env.Obj.n_primitive & 0x4000) == 0 &&
           (((pl->m_obj).dummy1 & 0x1000U) != 0))) {
      Task_Next();
    }
  }
  else {
    lVar2 = Manim_WaitEvent(obj,0x8000);
    if (lVar2 != 0) {
      Pafj_ExecJpDown(1);
      return;
    }
  }
  if ((*(ushort *)&(pl->m_obj).shadow.u0 & 0x800) != 0) {
    Pl_ForceAction(pl,6,0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pafj_ExecJpDown(short sxy /*$a0*/)
 // line 363, offset 0x80038ef0
	/* begin block 1 */
		// Start line: 364
		// Start offset: 0x80038EF0
		// Variables:
	// 		struct _PLAYER *pl; // $s1
	// 		short cumul_z; // $s0
	// 		short anm; // $a1
	// 		short txy; // $s0
	/* end block 1 */
	// End offset: 0x80039230
	// End Line: 492

	/* begin block 2 */
		// Start line: 1048
	/* end block 2 */
	// End Line: 1049

/* WARNING: Type propagation algorithm not settling */

void Pafj_ExecJpDown(short sxy)

{
  short sVar1;
  undefined2 uVar2;
  char cVar3;
  ushort uVar4;
  uint uVar5;
  long Anim;
  _PLAYER *pl;
  
  pl = (_PLAYER *)TaskCurrent->local;
  uVar4 = *(ushort *)&(pl->m_obj).shadow.u0;
  *(ushort *)&(pl->m_obj).shadow.u0 = uVar4 | 1;
  if ((int)((uint)(ushort)sxy << 0x10) < 0) {
    *(ushort *)&(pl->m_obj).shadow.u0 = uVar4 | 0x11;
  }
  if ((uint)*(ushort *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x16) - 0x39 < 2) {
    Manim_WaitAnim((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data);
    uVar2 = *(undefined2 *)((int)&(pl->m_obj).Env.Obj.n_primitive + 2);
    Anim = 0x40;
    if (((pl->m_obj).dummy1 & 0x1000U) == 0) {
      Anim = 0x41;
      uVar4 = *(ushort *)&(pl->m_obj).shadow.u0 & 0xf7ff;
    }
    else {
      uVar4 = *(ushort *)&(pl->m_obj).shadow.u0 | 0x800;
    }
    *(ushort *)&(pl->m_obj).shadow.u0 = uVar4;
    Manim_SetAnim((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data,Anim);
    *(undefined2 *)((int)&(pl->m_obj).Env.Obj.n_primitive + 2) = uVar2;
  }
  if ((*(ushort *)
        (*(int *)(*(int *)((pl->m_obj).Env.Obj.primitive_top.Data + 0xc) +
                  (int)*(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x16) * 4 + 8) + 10) & 4)
      == 0) {
    while (((int)*(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x22) & 0x8000U) == 0) {
      if ((*(ushort *)&(pl->m_obj).Env.Obj.n_primitive & 0x4000) != 0) {
        if (((int)*(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x22) & 0x8000U) == 0) {
          uVar4 = *(ushort *)&(pl->m_obj).shadow.u0;
          goto LAB_8003921c;
        }
        break;
      }
      if (((*(ushort *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x22) & 0x2000) != 0) &&
         (((pl->m_obj).nAnim & PJOY_JUMP) != 0)) {
        *(ushort *)&(pl->m_obj).shadow.u0 = (pl->m_obj).shadow.clut;
        Pl_ForceAction(pl,10,0);
      }
      Task_Next();
    }
  }
  Anim = Pafj_ExecChute();
  cVar3 = (char)pl;
  if ((((pl->obj).collision_state & 0x20U) == 0) && (0x32 < (short)Anim)) {
    Impact_Smoke(cVar3 + ',',1);
  }
  uVar4 = *(ushort *)&(pl->m_obj).shadow.u0;
  *(undefined2 *)((int)&(pl->m_obj).Env.Obj.n_primitive + 2) = 0x100;
  *(ushort *)&(pl->m_obj).shadow.u0 = uVar4 & 0xff7f | 0x40;
  Pafj_ExecReception((short)Anim);
  uVar4 = *(ushort *)&(pl->m_obj).shadow.u0;
  sVar1 = *(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x16);
  (pl->m_obj).shadow.y1 = 0;
  *(ushort *)&(pl->m_obj).shadow.u0 = uVar4 & 0xfffe;
  if (sVar1 == 0x27) {
    *(ushort *)&(pl->m_obj).shadow.u0 = *(ushort *)&(pl->m_obj).shadow.u0 | 0x8000;
  }
  *(ushort *)&(pl->m_obj).Env.Obj.n_primitive = *(ushort *)&(pl->m_obj).Env.Obj.n_primitive | 1;
  Anim = Manim_WaitEvent((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data,0x7000);
  if (Anim == 0x2000) {
    uVar5 = M_rand();
    if ((uVar5 & 1) == 0) {
      Fx_Play(1,cVar3 + ',');
      Manim_WaitAnim((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data);
      Anim = 0x3d;
    }
    else {
      Fx_Play(0x1c,cVar3 + ',');
      Anim = 0x43;
    }
    Manim_SetAnim((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data,Anim);
  }
  else {
    if (0x2000 < Anim) {
      if (Anim == 0x4000) {
        TaskCurrent->event_enable = 1;
        while (((*(ushort *)&(pl->m_obj).Env.Obj.n_primitive & 0x4000) == 0 &&
               (((pl->m_obj).dummy1 & 0x1000U) != 0))) {
          Task_Next();
        }
      }
      goto LAB_80039208;
    }
    if (Anim != 0x1000) goto LAB_80039208;
    if ((pl->obj).hit_points == 0) {
      *(ushort *)&(pl->m_obj).Env.Obj.n_primitive =
           *(ushort *)&(pl->m_obj).Env.Obj.n_primitive & 0xfffe;
      Pl_ForceAction(pl,0x10,2);
    }
  }
  Manim_WaitAnim((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data);
LAB_80039208:
  uVar4 = *(ushort *)&(pl->m_obj).shadow.u0;
  *(ushort *)&(pl->m_obj).shadow.u0 = uVar4 & 0xffbf;
LAB_8003921c:
  if ((uVar4 & 0x800) != 0) {
    Pl_ForceAction(pl,6,0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pafj_ExecJpForward(short Anm /*$a2*/, short txya /*$s1*/)
 // line 495, offset 0x80039248
	/* begin block 1 */
		// Start line: 496
		// Start offset: 0x80039248
		// Variables:
	// 		struct _PLAYER *pl; // $s0
	/* end block 1 */
	// End offset: 0x80039294
	// End Line: 504

	/* begin block 2 */
		// Start line: 1341
	/* end block 2 */
	// End Line: 1342

void Pafj_ExecJpForward(short Anm,short txya)

{
  void *pvVar1;
  
  pvVar1 = TaskCurrent->local;
  if ((Anm == 0x3a) && ((*(ushort *)((int)pvVar1 + 0x11e) & 0x800) != 0)) {
    Anm = 0x39;
  }
  Manim_SetAnim((M_OBJECT *)((int)pvVar1 + 0xa4),(int)Anm);
  *(short *)((int)pvVar1 + 0xce) = txya;
  *(undefined2 *)((int)pvVar1 + 0xd0) = 0x180;
  Pafj_ExecJpDown(1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pafj_ExecReception(short cumul_z /*$s2*/)
 // line 512, offset 0x800392cc
	/* begin block 1 */
		// Start line: 513
		// Start offset: 0x800392CC
		// Variables:
	// 		struct _PLAYER *pl; // $s0
	// 		long anm; // $a1
	/* end block 1 */
	// End offset: 0x800393CC
	// End Line: 546

	/* begin block 2 */
		// Start line: 1385
	/* end block 2 */
	// End Line: 1386

/* WARNING: Type propagation algorithm not settling */

void Pafj_ExecReception(short cumul_z)

{
  ushort uVar1;
  int iVar2;
  long Anim;
  _PLAYER *pl;
  
  pl = (_PLAYER *)TaskCurrent->local;
  if ((600 < (int)cumul_z) && ((pl->obj).hit_points != 0)) {
    Fx_Play(1,(char)pl + ',');
    Pl_ReduceHitPoints(pl,(short)((uint)((((int)cumul_z + -600) / 10) * 0x10000) >> 0x10));
  }
  iVar2 = (int)*(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x16);
  if ((*(ushort *)
        (*(int *)(*(int *)((pl->m_obj).Env.Obj.primitive_top.Data + 0xc) + iVar2 * 4 + 8) + 10) & 2)
      == 0) {
    if (cumul_z < 0x259) {
      if (cumul_z < 0xc9) {
        return;
      }
      if (iVar2 != 0x35) {
        return;
      }
      Anim = 0x3e;
    }
    else {
      uVar1 = *(ushort *)&(pl->m_obj).shadow.u0;
      Anim = 0x3f;
      if ((uVar1 & 0x10) != 0) {
        Anim = 0x32;
      }
      *(ushort *)&(pl->m_obj).shadow.u0 = uVar1 & 0xe7ff;
    }
    Manim_SetAnim((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data,Anim);
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Pafj_ExecChute()
 // line 549, offset 0x800393e4
	/* begin block 1 */
		// Start line: 550
		// Start offset: 0x800393E4
		// Variables:
	// 		struct _PLAYER *pl; // $s2
	// 		long cumul_z; // $s0
	// 		long sx; // $s4
	// 		long sy; // $s3
	// 		long sz; // $s1
	/* end block 1 */
	// End offset: 0x8003953C
	// End Line: 582

	/* begin block 2 */
		// Start line: 1483
	/* end block 2 */
	// End Line: 1484

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention yet parameter storage is locked */

long Pafj_ExecChute(void)

{
  ushort uVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  long lVar5;
  int iVar6;
  long lVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  M_OBJECT *mo;
  _PLAYER *pl;
  
  pl = (_PLAYER *)TaskCurrent->local;
  mo = (M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data;
  iVar4 = rcos((int)(pl->obj).rot.vz);
  lVar5 = Manim_GetSpdX(mo);
  iVar6 = rsin((int)(pl->obj).rot.vz);
  lVar7 = Manim_GetSpdX(mo);
  iVar8 = Manim_GetSpdZ(mo);
  iVar10 = 0;
  if ((*(ushort *)
        (*(int *)(*(int *)((pl->m_obj).Env.Obj.primitive_top.Data + 0xc) +
                  (int)*(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x16) * 4 + 8) + 10) & 4)
      == 0) {
    *(ushort *)&(pl->m_obj).Env.Obj.n_primitive =
         *(ushort *)&(pl->m_obj).Env.Obj.n_primitive & 0xfffe;
  }
  while (((pl->obj).collision_state & 0x4000U) == 0) {
    uVar1 = *(ushort *)&(pl->m_obj).Env.Obj.n_primitive;
    if ((uVar1 & 0x4000) != 0) {
      *(ushort *)&(pl->m_obj).Env.Obj.n_primitive = uVar1 & 0xfffe;
    }
    iVar9 = (int)(pl->obj).pos.vz;
    if ((-0x1f5 < iVar9) && (iVar9 + iVar8 < -500)) {
      Pl_ForceAction(pl,0x10,1);
    }
    sVar2 = (pl->obj).pos.vz;
    (pl->obj).pos.vx = (pl->obj).pos.vx + (short)(iVar4 * lVar5 >> 0xc);
    sVar3 = (pl->obj).pos.vy;
    (pl->obj).pos.vz = sVar2 + (short)iVar8;
    iVar9 = iVar8 + -5;
    (pl->obj).pos.vy = sVar3 + (short)(iVar6 * lVar7 >> 0xc);
    iVar10 = iVar10 - iVar8;
    iVar8 = -100;
    if (-0x65 < iVar9) {
      iVar8 = iVar9;
    }
    Task_Next();
  }
  return iVar10;
}





