#include "THISDUST.H"
#include "P_ACTD.H"


// decompiled code
// original method signature: 
// void /*$ra*/ Pactd_Move()
 // line 16, offset 0x8003723c
	/* begin block 1 */
		// Start line: 17
		// Start offset: 0x8003723C
		// Variables:
	// 		struct _PLAYER *pl; // $s0
	// 		long lAnm; // stack offset -48
	// 		long Anm; // $s5
	// 		long joy_dep; // $s6
	// 		long run; // $s1
	// 		long rot; // $s2
	// 		long rot_speed; // $s3
	// 		long test_coll; // $s4

		/* begin block 1.1 */
			// Start line: 83
			// Start offset: 0x80037468
		/* end block 1.1 */
		// End offset: 0x80037468
		// End Line: 86
	/* end block 1 */
	// End offset: 0x800376EC
	// End Line: 179

	/* begin block 2 */
		// Start line: 33
	/* end block 2 */
	// End Line: 34

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pactd_Move(void)

{
  short sVar1;
  ushort uVar2;
  bool bVar3;
  short sVar4;
  short sVar5;
  ushort uVar6;
  long lVar7;
  int iVar8;
  short sVar9;
  int iVar10;
  M_OBJECT *obj;
  _PLAYER *pl;
  int iVar11;
  int unaff_s3;
  int Anim;
  M_OBJECT *obj_00;
  
  pl = (_PLAYER *)TaskCurrent->local;
  uVar2 = (pl->m_obj).shadow.clut;
  bVar3 = false;
  if ((uVar2 & 0x1000) == 0) {
    Anim = 99;
    if ((uVar2 & 0x800) != 0) goto LAB_800372a0;
    Anim = 0x58;
  }
  else {
    Anim = 0xf;
LAB_800372a0:
    bVar3 = true;
    *(ushort *)&(pl->m_obj).shadow.u0 = *(ushort *)&(pl->m_obj).shadow.u0 | 0x800;
  }
  iVar11 = 0;
  sVar1 = *(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x16);
  obj_00 = (M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data;
LAB_800372dc:
  uVar2 = (pl->m_obj).dummy1;
  iVar10 = (int)*(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x16);
  if ((iVar10 != 99) && (iVar10 == Anim)) {
    if (((int)*(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x22) & 0x8000U) != 0) {
      bVar3 = true;
      *(ushort *)&(pl->m_obj).shadow.u0 = *(ushort *)&(pl->m_obj).shadow.u0 | 0x800;
    }
    if ((*(ushort *)&(pl->m_obj).Env.Obj.n_primitive & 0x4000) != 0) {
      Anim = 99;
      bVar3 = true;
      *(ushort *)&(pl->m_obj).shadow.u0 = *(ushort *)&(pl->m_obj).shadow.u0 | 0x800;
    }
  }
  iVar10 = 1;
  if (((uVar2 & 0x1000) == 0) && (iVar10 = 0, (uVar2 & 0x4000) != 0)) {
    iVar10 = -1;
  }
  if (bVar3) {
    if ((((int)(pl->obj).collision_state & 0xfc00U) == 0) ||
       (lVar7 = Pl_TestHeight(pl,0x21), lVar7 < (int)(pl->obj).pos.vz + 200)) {
      uVar6 = *(ushort *)&(pl->m_obj).shadow.u0 | 0x800;
    }
    else {
      uVar6 = *(ushort *)&(pl->m_obj).shadow.u0 & 0xf7ff;
    }
    *(ushort *)&(pl->m_obj).shadow.u0 = uVar6;
  }
  if ((uVar2 & 0x8000) == 0) {
    if ((uVar2 & 0x2000) == 0) {
      iVar8 = 0;
      iVar11 = 0;
    }
    else {
      if ((iVar11 < 0) && (0x3f < unaff_s3 + 0x10)) {
        iVar8 = 0x40;
      }
      else {
        iVar8 = 0x10;
        if (iVar11 < 0) {
          iVar8 = unaff_s3 + 0x10;
        }
      }
      iVar11 = -1;
    }
  }
  else {
    if ((iVar11 < 1) || (unaff_s3 + 0x10 < 0x40)) {
      iVar8 = 0x10;
      if (0 < iVar11) {
        iVar8 = unaff_s3 + 0x10;
      }
    }
    else {
      iVar8 = 0x40;
    }
    iVar11 = 1;
  }
  sVar5 = (short)iVar8;
  sVar4 = (short)iVar11;
  if (iVar10 < 1) {
LAB_800374cc:
    if (((pl->m_obj).dummy1 & PJOY_STRAFE) != 0) {
      if ((iVar11 == 0) && (iVar10 == 0)) {
LAB_80037640:
        if (iVar11 != 0) {
          *(ushort *)&(pl->m_obj).shadow.u0 = *(ushort *)&(pl->m_obj).shadow.u0 & 0xf7ff;
          Manim_ForceAnim((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data,0x61);
          Anim = 0x58;
          sVar9 = (pl->obj).rot.vz;
          *(ushort *)&(pl->m_obj).Env.Obj.n_primitive =
               *(ushort *)&(pl->m_obj).Env.Obj.n_primitive & 0xfffe;
          goto LAB_80037678;
        }
      }
      else {
        bVar3 = false;
        Anim = 0x58;
        *(ushort *)&(pl->m_obj).shadow.u0 = *(ushort *)&(pl->m_obj).shadow.u0 & 0xf7ff;
        if (iVar10 < 1) {
          obj = (M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data;
          if (iVar11 < 1) {
            if (iVar11 < 0) {
              Manim_SetAnim(obj,0x5b);
            }
            else {
              if (iVar10 < 0) goto LAB_80037548;
            }
          }
          else {
            Manim_SetAnim(obj,0x5c);
          }
        }
        else {
          Manim_SetAnim(obj_00,0x5d);
          if (iVar11 != 0) {
            (pl->obj).rot.vz = (pl->obj).rot.vz + sVar4 * sVar5 & 0xfff;
          }
          lVar7 = Pl_TestHeight(pl,0x14);
          if (lVar7 < (int)(pl->obj).pos.vz + -0x32) {
            Manim_ForceAnim(obj_00,0x61);
          }
        }
      }
      goto LAB_80037688;
    }
    if (iVar10 < 1) {
      if (-1 < iVar10) goto LAB_80037640;
LAB_80037548:
      Pafd_Recul();
      goto LAB_80037690;
    }
    Manim_SetAnim((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data,Anim);
    if ((Anim == 99) && (sVar1 == 0x40)) {
      *(undefined2 *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x18) = 0xd0;
      sVar1 = -1;
    }
    if ((Anim == 0x58) && (((pl->obj).collision_state & 0x40U) != 0)) {
      lVar7 = Pafd_TestPush();
      if (lVar7 == 0) goto LAB_80037620;
      Pafd_PushObject();
      goto LAB_80037698;
    }
LAB_80037620:
    (pl->obj).rot.vz = (pl->obj).rot.vz + sVar5 * sVar4 & 0xfff;
  }
  else {
    obj = (M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data;
    if (((pl->m_obj).shadow.y2 & 0x10U) == 0) {
      if (*(short *)((int)&(pl->m_obj).Env.Obj.n_normal + 2) != 0x50) goto LAB_800374cc;
      *(ushort *)&(pl->m_obj).shadow.u0 = *(ushort *)&(pl->m_obj).shadow.u0 & 0xf7ff;
      Manim_SetAnim(obj,0x5d);
      bVar3 = false;
      goto LAB_80037620;
    }
    *(ushort *)&(pl->m_obj).shadow.u0 = *(ushort *)&(pl->m_obj).shadow.u0 & 0xf7ff;
    Manim_SetAnim(obj,0x1e);
    lVar7 = M_rand();
    sVar9 = (pl->obj).rot.vz + (((ushort)lVar7 & 0x7f) - 0x40);
LAB_80037678:
    bVar3 = false;
    (pl->obj).rot.vz = sVar9 + sVar5 * sVar4 & 0xfff;
  }
LAB_80037688:
  Task_Next();
LAB_80037690:
  unaff_s3 = iVar8;
  if ((uVar2 & 0xf000) == 0) {
LAB_80037698:
    if (((*(ushort *)&(pl->m_obj).shadow.u0 & 0x800) != 0) &&
       (obj_00 = (M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data,
       *(short *)((int)&(pl->m_obj).Env.Obj.n_normal + 2) == 0x4f)) {
      TaskCurrent->event_enable = 0;
      Manim_SetAnim(obj_00,0x59);
      Manim_WaitAnim(obj_00);
      TaskCurrent->event_enable = 1;
    }
    return;
  }
  goto LAB_800372dc;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pactd_TurnBack()
 // line 182, offset 0x8003771c
	/* begin block 1 */
		// Start line: 183
		// Start offset: 0x8003771C
		// Variables:
	// 		struct _PLAYER *pl; // $s0
	/* end block 1 */
	// End offset: 0x8003771C
	// End Line: 183

	/* begin block 2 */
		// Start line: 500
	/* end block 2 */
	// End Line: 501

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pactd_TurnBack(void)

{
  _PLAYER *pl;
  
  pl = (_PLAYER *)TaskCurrent->local;
  TaskCurrent->event_enable = 0;
  Manim_SetAnim((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data,0x50);
  Pl_TurnBackRot(pl,0,0);
  TaskCurrent->event_enable = 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pactd_Slop()
 // line 199, offset 0x80037774
	/* begin block 1 */
		// Start line: 200
		// Start offset: 0x80037774
		// Variables:
	// 		struct _PLAYER *pl; // $s0
	// 		struct _D3_OBJECT *os; // $s4
	// 		struct P_ACTD_7fake *p; // $s1
	// 		long dxg; // $fp
	// 		long dyg; // $s7
	// 		long dxd; // $s6
	// 		long dyd; // $s5
	// 		long dx; // stack offset -48
	// 		long dy; // stack offset -44
	// 		long d; // $v1
	// 		long joyd; // $s3
	// 		long joyg; // $s2
	/* end block 1 */
	// End offset: 0x80037A80
	// End Line: 291

	/* begin block 2 */
		// Start line: 537
	/* end block 2 */
	// End Line: 538

/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pactd_Slop(void)

{
  uint uVar1;
  uint uVar2;
  ushort uVar3;
  short sVar4;
  long d1;
  int iVar5;
  int iVar6;
  int wPlayId;
  short sVar7;
  _PLAYER *pl;
  _struct_241 *p_Var8;
  ushort uVar9;
  ushort uVar10;
  _D3_OBJECT *ot;
  uint local_30;
  uint local_2c;
  
  ot = (_D3_OBJECT *)TaskCurrent->event_param;
  pl = (_PLAYER *)TaskCurrent->local;
  Boxes_GetExtendedDxDy(ot,(long *)&local_30,(long *)&local_2c);
  p_Var8 = &(pl->obj).pos;
  d1 = Direction(local_30,local_2c);
  d1 = DeltaDirection(d1,(int)(pl->obj).rot.vz);
  wPlayId = d1;
  if (d1 < 0) {
    wPlayId = -d1;
  }
  uVar10 = 0x2000;
  if (wPlayId < 0x201) {
    uVar9 = 0x8000;
  }
  else {
    uVar10 = 0x1000;
    if (d1 - 0x201U < 0x3ff) {
      uVar9 = 0x4000;
    }
    else {
      uVar10 = 0x4000;
      if (wPlayId < 0x600) {
        uVar9 = 0x1000;
      }
      else {
        uVar10 = 0x8000;
        uVar9 = 0x2000;
      }
    }
  }
  uVar1 = -local_2c;
  iVar5 = local_30 + (local_30 >> 0x1f);
  iVar6 = local_2c + (local_2c >> 0x1f);
  uVar2 = -local_30;
  d1 = Direction(local_30,local_2c);
  wPlayId = DeltaDirection(d1,(int)(pl->obj).rot.vz);
  if (wPlayId < 0) {
    wPlayId = -wPlayId;
  }
  if (0x400 < wPlayId) {
    *(ushort *)&(pl->m_obj).shadow.u0 = *(ushort *)&(pl->m_obj).shadow.u0 | 0x10;
  }
  Manim_SetAnim((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data,0x45);
  TaskCurrent->event_enable = 0;
  uVar3 = Fx_Play(0x1a,0);
  (pl->m_obj).Ani.Anim.Flags = uVar3;
  do {
    p_Var8->vx = p_Var8->vx + (short)local_30;
    sVar4 = (pl->obj).pos.vz;
    (pl->obj).pos.vy = (pl->obj).pos.vy + (short)local_2c;
    (pl->obj).pos.vz = sVar4 + -0x14;
    uVar3 = (pl->m_obj).dummy1;
    if ((uVar3 & uVar9) == 0) {
      if ((uVar3 & uVar10) != 0) {
        sVar4 = p_Var8->vx + (short)(iVar6 >> 1);
        sVar7 = (pl->obj).pos.vy + (short)((int)(uVar2 + (uVar2 >> 0x1f)) >> 1);
        goto LAB_80037940;
      }
    }
    else {
      sVar4 = p_Var8->vx + (short)((int)(uVar1 + (uVar1 >> 0x1f)) >> 1);
      sVar7 = (pl->obj).pos.vy + (short)(iVar5 >> 1);
LAB_80037940:
      p_Var8->vx = sVar4;
      (pl->obj).pos.vy = sVar7;
    }
    if (((pl->m_obj).nAnim & PJOY_JUMP) != 0) {
      Pl_ForceAction(pl,10,0);
    }
    if ((*(ushort *)&(pl->m_obj).Env.Obj.n_primitive & 0x4000) != 0) {
      Manim_SetAnim((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data,0x1d);
    }
    Task_Next();
    if ((((pl->obj).collision_state & 0x4000U) == 0) ||
       (*(_D3_OBJECT **)&(pl->m_obj).Env.Obj.vert_top.vz != ot)) {
      while ((local_30 != 0 || (local_2c != 0))) {
        sVar4 = (pl->obj).pos.vy;
        (pl->obj).pos.vx = (pl->obj).pos.vx + (short)local_30;
        sVar7 = (pl->obj).pos.vz;
        (pl->obj).pos.vy = sVar4 + (short)local_2c;
        (pl->obj).pos.vz = sVar7 + -0x14;
        local_30 = (int)(local_30 + (local_30 >> 0x1f)) >> 1;
        local_2c = (int)(local_2c + (local_2c >> 0x1f)) >> 1;
        if (((pl->m_obj).nAnim & PJOY_JUMP) != 0) {
          Pl_ForceAction(pl,10,0);
        }
        Task_Next();
      }
      wPlayId = (int)(short)(pl->m_obj).Ani.Anim.Flags;
      if (-1 < wPlayId) {
        Sound_Stop(wPlayId,0);
        (pl->m_obj).Ani.Anim.Flags = 0xffff;
      }
      TaskCurrent->event_enable = 1;
      return;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pafd_Recul()
 // line 297, offset 0x80037ac0
	/* begin block 1 */
		// Start line: 298
		// Start offset: 0x80037AC0
		// Variables:
	// 		struct _PLAYER *pl; // $s0
	// 		short rot; // $a0
	/* end block 1 */
	// End offset: 0x80037BFC
	// End Line: 350

	/* begin block 2 */
		// Start line: 778
	/* end block 2 */
	// End Line: 779

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pafd_Recul(void)

{
  ushort uVar1;
  short sVar2;
  void *pvVar3;
  M_OBJECT *obj;
  
  pvVar3 = TaskCurrent->local;
  uVar1 = *(ushort *)((int)pvVar3 + 0x108) & PJOY_STRAFE;
  *(ushort *)((int)pvVar3 + 0x11c) = *(ushort *)((int)pvVar3 + 0x11c) & 0xf7ff | 0x10;
  if (uVar1 == 0) {
    obj = (M_OBJECT *)((int)pvVar3 + 0xa4);
    Manim_SetAnim(obj,0x15);
    Manim_WaitEvent(obj,0x8000);
    if ((*(ushort *)((int)pvVar3 + 0x108) & 0x4000) == 0) {
      Manim_SetAnim(obj,0x14);
      Manim_WaitAnim(obj);
      goto LAB_80037bec;
    }
  }
  Manim_SetAnim((M_OBJECT *)((int)pvVar3 + 0xa4),0x5a);
  do {
    sVar2 = 0;
    if ((*(ushort *)((int)pvVar3 + 0x108) & 0x8000) == 0) {
      if ((*(ushort *)((int)pvVar3 + 0x108) & 0x2000) != 0) {
        sVar2 = 1;
      }
    }
    else {
      sVar2 = -1;
    }
    if (((*(ushort *)((int)pvVar3 + 0x108) & PJOY_STRAFE) != 0) && (sVar2 != 0)) break;
    if (sVar2 != 0) {
      *(ushort *)((int)pvVar3 + 0x40) =
           *(short *)((int)pvVar3 + 0x40) + sVar2 * 0x20 + 0x1000U & 0xfff;
    }
    Task_Next();
  } while ((*(ushort *)((int)pvVar3 + 0x108) & 0x4000) != 0);
LAB_80037bec:
  *(ushort *)((int)pvVar3 + 0x11c) = *(ushort *)((int)pvVar3 + 0x11c) & 0xffef;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pafd_PushObject()
 // line 355, offset 0x80037c10
	/* begin block 1 */
		// Start line: 356
		// Start offset: 0x80037C10
		// Variables:
	// 		struct _PLAYER *pl; // $s3
	// 		struct P_ACTD_7fake t; // stack offset -40
	// 		struct P_ACTD_7fake p; // stack offset -32
	// 		struct _D3_OBJECT *op; // $s0
	// 		struct _ZONE *z; // $a0
	// 		long x; // $s2
	// 		long y; // $s1
	// 		long block; // $s4
	/* end block 1 */
	// End offset: 0x80037F08
	// End Line: 455

	/* begin block 2 */
		// Start line: 901
	/* end block 2 */
	// End Line: 902

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pafd_PushObject(void)

{
  ushort uVar1;
  short sVar2;
  long lVar3;
  int iVar4;
  _ZONE *p_Var5;
  _D3_OBJECT *obj;
  undefined4 uVar6;
  undefined4 uVar7;
  _D3_OBJECT *o;
  int iVar8;
  void *pvVar9;
  int iVar10;
  short local_28;
  short local_26;
  short local_20;
  short sStack30;
  short local_1c;
  
  pvVar9 = TaskCurrent->local;
  o = *(_D3_OBJECT **)((int)pvVar9 + 0x100);
  iVar10 = 0;
  Zone_GetObjectZone(o);
  Manim_SetAnim((M_OBJECT *)((int)pvVar9 + 0xa4),0x11);
  uVar1 = *(ushort *)((int)pvVar9 + 0x108);
  *(ushort *)((int)pvVar9 + 0x11c) = *(ushort *)((int)pvVar9 + 0x11c) & 0xf7ff;
  while ((uVar1 & 0x1000) != 0) {
    if ((*(ushort *)((int)pvVar9 + 0xcc) & 0x4000) != 0) {
      Manim_SetAnim((M_OBJECT *)((int)pvVar9 + 0xa4),0x12);
    }
    lVar3 = Pafd_TestPush();
    if (lVar3 == 0) break;
    sVar2 = D3_UpdateSound(o,0,*(short *)((int)pvVar9 + 0xf2));
    *(short *)((int)pvVar9 + 0xf2) = sVar2;
    uVar6 = *(undefined4 *)&o->pos;
    uVar7 = *(undefined4 *)&(o->pos).vz;
    lVar3 = Manim_GetSpdX((M_OBJECT *)((int)pvVar9 + 0xa4));
    iVar4 = rsin((int)*(short *)((int)pvVar9 + 0x40));
    local_26 = (short)((int)(short)lVar3 * iVar4 + 0x800 >> 0xc);
    iVar4 = rcos((int)*(short *)((int)pvVar9 + 0x40));
    local_28 = (short)((int)(short)lVar3 * iVar4 + 0x800 >> 0xc);
    if (Scr_Frame == 0) {
      D3_ClearCollBits(o,0x80);
    }
    else {
      D3_SetCollBits(o,0x80);
    }
    if (((int)local_28 != 0) || (local_26 != 0)) {
      iVar8 = (int)(o->pos).vx + (int)local_28;
      iVar4 = (int)(o->pos).vy + (int)local_26;
      p_Var5 = Zone_GetObjectZone(o);
      while (p_Var5 != (_ZONE *)0x0) {
        if ((int)p_Var5->x2 <= iVar8 + (int)*(short *)&o->b_step) {
          local_28 = 0;
        }
        if (iVar8 + (int)(o->b_box).vx < (int)p_Var5->x1) {
          local_28 = 0;
        }
        if ((int)p_Var5->y2 <= iVar4 + (int)(o->b_box).vy) {
          local_26 = 0;
        }
        if (iVar4 + (int)*(short *)((int)&o->b_sunk + 2) < (int)p_Var5->y1) {
          local_26 = 0;
        }
        p_Var5 = Zone_GetObjectNext(o);
      }
    }
    (o->pos).vx = (o->pos).vx + local_28;
    obj = o->child;
    (o->pos).vy = (o->pos).vy + local_26;
    D3_MoveList(obj,0xd8);
    Task_Next();
    local_1c = (short)uVar7;
    if ((o->pos).vz < local_1c) break;
    if (((local_28 == 0) && (local_26 == 0)) || (local_20 = (short)uVar6, local_20 != (o->pos).vx))
    {
LAB_80037ec4:
      iVar10 = 0;
    }
    else {
      sStack30 = (short)((uint)uVar6 >> 0x10);
      iVar10 = iVar10 + 1;
      if (sStack30 != (o->pos).vy) goto LAB_80037ec4;
      if (1 < iVar10) break;
    }
    uVar1 = *(ushort *)((int)pvVar9 + 0x108);
  }
  D3_SetCollBits(o,0x80);
  if (-1 < (int)*(short *)((int)pvVar9 + 0xf2)) {
    Sound_Stop((int)*(short *)((int)pvVar9 + 0xf2),0);
    *(undefined2 *)((int)pvVar9 + 0xf2) = 0xffff;
  }
  Manim_SetAnim((M_OBJECT *)((int)pvVar9 + 0xa4),0x13);
  Manim_WaitAnim((M_OBJECT *)((int)pvVar9 + 0xa4));
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Pafd_TestPush()
 // line 460, offset 0x80037f40
	/* begin block 1 */
		// Start line: 461
		// Start offset: 0x80037F40
		// Variables:
	// 		struct _PLAYER *pl; // $s0
	// 		struct P_ACTD_7fake pos; // stack offset -24
	// 		struct _D3_OBJECT *op; // $s1
	/* end block 1 */
	// End offset: 0x8003800C
	// End Line: 488

	/* begin block 2 */
		// Start line: 1121
	/* end block 2 */
	// End Line: 1122

/* WARNING: Unknown calling convention yet parameter storage is locked */

long Pafd_TestPush(void)

{
  long d1;
  int iVar1;
  void *pvVar2;
  _D3_OBJECT *ot;
  short local_18;
  short local_16;
  
  pvVar2 = TaskCurrent->local;
  ot = *(_D3_OBJECT **)((int)pvVar2 + 0x100);
  d1 = 0;
  if ((ot->collision_state & 4U) == 0) {
    Boxes_GetCenter(ot,0xe8);
    d1 = Direction((int)local_18 - (int)*(short *)((int)pvVar2 + 0x2c),
                   (int)local_16 - (int)*(short *)((int)pvVar2 + 0x2e));
    iVar1 = DeltaDirection(d1,(int)*(short *)((int)pvVar2 + 0x40));
    if (iVar1 < 0) {
      iVar1 = -iVar1;
    }
    d1 = 0;
    if (iVar1 < 0x200) {
      iVar1 = (int)(ot->pos).vz;
      d1 = 0;
      if (((int)*(short *)((int)pvVar2 + 0x30) + (int)*(short *)((int)pvVar2 + 0x50) <=
           iVar1 + (int)*(short *)&ot[1].prec) &&
         (d1 = 0, iVar1 + (int)(ot->b_box).vz <=
                  (int)*(short *)((int)pvVar2 + 0x30) + (int)*(short *)((int)pvVar2 + 0x70))) {
        d1 = 1;
      }
    }
  }
  return d1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pafd_Crawl()
 // line 493, offset 0x80038020
	/* begin block 1 */
		// Start line: 494
		// Start offset: 0x80038020
		// Variables:
	// 		struct _PLAYER *pl; // $s1
	// 		long col; // $s0
	/* end block 1 */
	// End offset: 0x80038190
	// End Line: 545

	/* begin block 2 */
		// Start line: 1188
	/* end block 2 */
	// End Line: 1189

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pafd_Crawl(void)

{
  ushort uVar1;
  M_OBJECT *obj;
  long lVar2;
  _D3_OBJECT *o;
  
  o = (_D3_OBJECT *)TaskCurrent->local;
  obj = (M_OBJECT *)&o[1].last_pos.vz;
  D3_SetHighBoxZ(o,(uint)(*(ushort *)((int)&o[4].shapes + 2) >> 2));
  Manim_SetAnim(obj,0x1a);
  Manim_WaitAnim(obj);
  while( true ) {
    do {
      Manim_SetAnim(obj,0x1b);
      if ((o[2].pos.vz & 0x2000U) != 0) {
        (o->rot).vz = (o->rot).vz - 0x10U & 0xfff;
      }
      if ((o[2].pos.vz & 0x8000U) != 0) {
        (o->rot).vz = (o->rot).vz + 0x10U & 0xfff;
      }
      if (*(short *)&o[2].shapes != 0) {
        *(ushort *)&o[1].difficulty = *(ushort *)&o[1].difficulty & 0xfffe;
      }
      Task_Next();
      uVar1 = PJOY_STRAFE;
      *(ushort *)&o[1].difficulty = *(ushort *)&o[1].difficulty | 1;
    } while (((ushort)(o[2].pos.vz & (uVar1 | 0x1000)) == (uVar1 | 0x1000)) ||
            (*(short *)&o[2].shapes != 0));
    D3_SetCollBits(o,0x2000);
    D3_SetHighBoxZ(o,(uint)(*(ushort *)((int)&o[4].shapes + 2) >> 1));
    lVar2 = Boxes_TestObject(o);
    D3_ClearCollBits(o,0x2000);
    D3_SetHighBoxZ(o,(uint)(*(ushort *)((int)&o[4].shapes + 2) >> 2));
    if (lVar2 == 0) break;
    o[2].pos.vz = o[2].pos.vz | PJOY_STRAFE | 0x1000;
  }
  D3_SetHighBoxZ(o,(uint)(*(ushort *)((int)&o[4].shapes + 2) >> 1));
  Manim_SetAnim(obj,0x1c);
  Manim_WaitAnim(obj);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Pafd_AdjustZ()
 // line 555, offset 0x800381c8
	/* begin block 1 */
		// Start line: 556
		// Start offset: 0x800381C8
		// Variables:
	// 		struct _PLAYER *pl; // $s2
	// 		struct _D3_OBJECT *o; // $s0
	// 		struct P_ACTD_7fake pos; // stack offset -32
	// 		long sx; // $s1
	// 		long sy; // $s3
	// 		long dz; // $s1
	// 		long cs; // $s0
	// 		long sn; // $v0
	/* end block 1 */
	// End offset: 0x800383B8
	// End Line: 617

	/* begin block 2 */
		// Start line: 1358
	/* end block 2 */
	// End Line: 1359

/* WARNING: Unknown calling convention yet parameter storage is locked */

long Pafd_AdjustZ(void)

{
  _D3_OBJECT *p_Var1;
  long lVar2;
  long lVar3;
  M_OBJECT *mo;
  int iVar4;
  _D3_OBJECT *ot;
  
  ot = (_D3_OBJECT *)TaskCurrent->local;
  lVar2 = 0;
  if ((*(ushort *)&ot[2].matrices & 1) == 0) {
    mo = (M_OBJECT *)&ot[1].last_pos.vz;
    lVar2 = Manim_GetSpdX(mo);
    lVar3 = Manim_GetSpdY(mo);
    if (lVar2 < 0) {
      lVar2 = lVar2 - (int)*(short *)&ot->b_step;
    }
    else {
      if (0 < lVar2) {
        lVar2 = lVar2 + (int)*(short *)&ot->b_step;
      }
    }
    if ((lVar2 != 0) || (lVar2 = 0, lVar3 != 0)) {
      rcos((int)(ot->rot).vz);
      rsin((int)(ot->rot).vz);
      lVar2 = Boxes_GetHeight(ot,0xe0,0x32);
      p_Var1 = Boxes_Object;
      iVar4 = lVar2 - (int)(ot->pos).vz;
      Boxes_GetHeight(ot,(char)ot + ',',0x32);
      lVar2 = 0;
      if (p_Var1 != Boxes_Object) {
        if ((iVar4 < 1) || (lVar2 = 1, 0x19 < iVar4)) {
          lVar2 = 0;
        }
        else {
          (ot->pos).vz = (ot->pos).vz + (short)iVar4;
        }
      }
    }
  }
  return lVar2;
}





