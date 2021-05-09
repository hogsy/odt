#include "THISDUST.H"
#include "P_ACTC.H"


// decompiled code
// original method signature: 
// void /*$ra*/ Pactc_Esquive()
 // line 21, offset 0x8003b530
	/* begin block 1 */
		// Start line: 22
		// Start offset: 0x8003B530
		// Variables:
	// 		struct _PLAYER *pl; // $s1
	// 		long Anm; // $a1
	// 		long Shot; // $s2
	// 		long reload; // $s0
	// 		long nana; // $s4
	/* end block 1 */
	// End offset: 0x8003B848
	// End Line: 152

	/* begin block 2 */
		// Start line: 43
	/* end block 2 */
	// End Line: 44

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pactc_Esquive(void)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  TASK *pTVar4;
  long Anim;
  _PLAYER *pl;
  uint uVar5;
  M_OBJECT *obj;
  uint nana;
  
  pl = (_PLAYER *)TaskCurrent->local;
  (pl->m_obj).Ani.Anim.Rot[4].m[3] = 0;
  bVar2 = (uint)(ushort)Pvl_PlayerNumber - 1 < 2;
  nana = (uint)bVar2;
  D3_SetHighBoxZ((_D3_OBJECT *)pl,(uint)(*(ushort *)((pl->env2).Obj.primitive_top.Data + 10) >> 1));
  pTVar4 = TaskCurrent;
  *(ushort *)&(pl->m_obj).shadow.u0 = *(ushort *)&(pl->m_obj).shadow.u0 | 0x1000;
  if (pTVar4->event_param == 0) {
    Anim = 0x1f;
    if (((pl->m_obj).shadow.clut & 0x800) != 0) {
      Anim = 0xe;
    }
    Manim_SetAnim((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data,Anim);
    while (((((int)*(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x22) & 0x8000U) == 0 &&
            ((*(ushort *)&(pl->m_obj).Env.Obj.n_primitive & 0x4000) == 0)) &&
           (Anim = Pafc_TestEsquive(pl,nana), Anim == 0))) {
      Task_Next();
    }
  }
  else {
    Pafc_SetEsquive(pl);
  }
  obj = (M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data;
  *(ushort *)&(pl->m_obj).Env.Obj.n_primitive = *(ushort *)&(pl->m_obj).Env.Obj.n_primitive & 0xfffe
  ;
LAB_8003b628:
  do {
    Task_Next();
    if (((pl->m_obj).dummy1 & PJOY_ESQUIVE) == 0) {
      Anim = Pafc_TestStandUp(pl);
      if (Anim != 0) {
        D3_SetHighBoxZ((_D3_OBJECT *)pl,(uint)*(ushort *)((pl->env2).Obj.primitive_top.Data + 10));
        if ((((pl->m_obj).dummy1 & 0x1000U) != 0) &&
           (*(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x16) == 0xe)) {
          Pl_ForceAction(pl,6,0);
        }
        if ((!bVar2) || (*(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x16) != 0x5e)) {
          obj = (M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data;
          *(ushort *)&(pl->m_obj).shadow.u0 = *(ushort *)&(pl->m_obj).shadow.u0 | 0x40;
          Manim_SetAnim(obj,0x20);
          Task_Next();
          *(ushort *)&(pl->m_obj).shadow.u0 = *(ushort *)&(pl->m_obj).shadow.u0 & 0xefff;
          Manim_WaitAnim(obj);
        }
        (pl->m_obj).Ani.Anim.Rot[4].m[3] = 1;
        return;
      }
      (pl->m_obj).dummy1 = (pl->m_obj).dummy1 | PJOY_ESQUIVE;
    }
    Pafc_TestEsquive(pl,nana);
    uVar5 = 0;
  } while ((ushort)((pl->m_obj).dummy1 & (PJOY_SHOT | PJOY_AIM)) == 0);
  bVar3 = false;
  bVar1 = (pl->env1).Obj.primitive_top.Data[0x19];
  *(undefined2 *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x26) = 0;
  *(undefined2 *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x24) = 0;
  Anim = Pl_IsWeaponAvailable(pl,(int)(char)bVar1);
  if (Anim == 0) goto code_r0x8003b6c0;
  goto LAB_8003b6e0;
code_r0x8003b6c0:
  if (*(int *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x10) == 0) {
    Anim = Invent_ReloadAmmo(pl);
    bVar3 = true;
    if (Anim != 0) {
LAB_8003b6e0:
      if (!bVar3) {
        uVar5 = (uint)((pl->m_obj).dummy1 & PJOY_SHOT);
        Manim_SetAnim(obj,0x4c);
        Manim_WaitAnim(obj);
      }
      *(undefined2 *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x26) = 0;
      *(undefined2 *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x24) = 0;
      if (!bVar3) goto LAB_8003b758;
      do {
        Pafc_Reload(pl,100);
        if ((ushort)((pl->m_obj).dummy1 & (PJOY_SHOT | PJOY_AIM)) == 0) break;
        Manim_SetAnim(obj,0x4c);
        Manim_WaitAnim(obj);
LAB_8003b758:
        bVar3 = false;
        Anim = Pafc_ExecShot(0x57,uVar5 | (uint)((pl->m_obj).dummy1 & PJOY_SHOT));
        if (Anim != 0) {
          Anim = Invent_ReloadAmmo(pl);
          bVar3 = Anim != 0;
        }
        uVar5 = 0;
      } while (bVar3);
      if (!bVar3) {
        Manim_SetAnim(obj,0x4d);
        Manim_WaitAnim(obj);
      }
      Pafc_SetEsquive(pl);
    }
  }
  goto LAB_8003b628;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Pafc_TestEsquive(struct _PLAYER *pl /*$s2*/, long nana /*$s0*/)
 // line 156, offset 0x8003b874
	/* begin block 1 */
		// Start line: 157
		// Start offset: 0x8003B874
		// Variables:
	// 		long anm; // $s1
	// 		long ret; // $a0
	/* end block 1 */
	// End offset: 0x8003BA64
	// End Line: 235

	/* begin block 2 */
		// Start line: 406
	/* end block 2 */
	// End Line: 407

/* WARNING: Type propagation algorithm not settling */

long Pafc_TestEsquive(_PLAYER *pl,long nana)

{
  bool bVar1;
  ushort uVar2;
  long lVar3;
  M_OBJECT *obj;
  int Anim;
  
  uVar2 = (pl->m_obj).dummy1;
  if ((uVar2 & PJOY_STRAFE) != 0) {
    bVar1 = false;
    if ((uVar2 & 0x1000) == 0) {
      if ((uVar2 & 0x8000) == 0) {
        if ((uVar2 & 0x2000) == 0) goto LAB_8003b900;
        uVar2 = (pl->obj).rot.vz - 0x30;
      }
      else {
        uVar2 = (pl->obj).rot.vz + 0x30;
      }
      bVar1 = true;
      (pl->obj).rot.vz = uVar2 & 0xfff;
    }
    else {
      Pafd_Crawl();
      bVar1 = true;
    }
LAB_8003b900:
    if (bVar1) goto LAB_8003ba58;
    uVar2 = (pl->m_obj).dummy1;
  }
  Anim = 0x23;
  if ((((uVar2 & 0x8000) == 0) && (Anim = 0x22, (uVar2 & 0x2000) == 0)) &&
     (Anim = 0x24, (uVar2 & 0x1000) == 0)) {
    if ((uVar2 & 0x4000) == 0) {
      return 0;
    }
    Anim = 0x5e;
    if (nana != 0) {
      lVar3 = Pafc_TestStandUp(pl);
      Anim = 0x5e;
      if (lVar3 == 0) {
        return 0;
      }
    }
  }
  if ((nana != 0) && (Anim == 0x5e)) {
    D3_SetHighBoxZ((_D3_OBJECT *)pl,(uint)*(ushort *)((pl->env2).Obj.primitive_top.Data + 10));
    uVar2 = (pl->m_obj).dummy1;
    obj = (M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data;
    while ((uVar2 & 0x4000) != 0) {
      if ((uVar2 & PJOY_ESQUIVE) == 0) {
        return 1;
      }
      Fx_Play(0x1c,(char)pl + ',');
      Manim_ForceAnim(obj,0x5e);
      Manim_WaitAnim(obj);
      uVar2 = (pl->m_obj).dummy1;
    }
    if (((pl->m_obj).dummy1 & PJOY_ESQUIVE) != 0) {
      D3_SetHighBoxZ((_D3_OBJECT *)pl,
                     (uint)(*(ushort *)((pl->env2).Obj.primitive_top.Data + 10) >> 1));
      obj = (M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data;
      Manim_SetAnim(obj,0x1f);
      Manim_WaitAnim(obj);
      *(ushort *)&(pl->m_obj).Env.Obj.n_primitive =
           *(ushort *)&(pl->m_obj).Env.Obj.n_primitive & 0xfffe;
      return 1;
    }
    return 1;
  }
  Fx_Play(0x1c,(char)pl + ',');
  obj = (M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data;
  Manim_ForceAnim(obj,Anim);
  Manim_WaitAnim(obj);
LAB_8003ba58:
  Pafc_SetEsquive(pl);
  return 1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pafc_SetEsquive(struct _PLAYER *pl /*$s0*/)
 // line 238, offset 0x8003ba7c
	/* begin block 1 */
		// Start line: 570
	/* end block 1 */
	// End Line: 571

/* WARNING: Type propagation algorithm not settling */

void Pafc_SetEsquive(_PLAYER *pl)

{
  short sVar1;
  
  Manim_SetAnim((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data,0xe);
  sVar1 = *(short *)(*(int *)(*(int *)((pl->m_obj).Env.Obj.primitive_top.Data + 0xc) + 0x40) + 6);
  *(ushort *)&(pl->m_obj).Env.Obj.n_primitive = *(ushort *)&(pl->m_obj).Env.Obj.n_primitive & 0xfffe
  ;
  *(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x18) = (sVar1 + -1) * 0x10;
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Pafc_TestStandUp(struct _PLAYER *pl /*$s0*/)
 // line 246, offset 0x8003bad0
	/* begin block 1 */
		// Start line: 247
		// Start offset: 0x8003BAD0
		// Variables:
	// 		long col; // $s1
	/* end block 1 */
	// End offset: 0x8003BAD0
	// End Line: 247

	/* begin block 2 */
		// Start line: 589
	/* end block 2 */
	// End Line: 590

long Pafc_TestStandUp(_PLAYER *pl)

{
  long lVar1;
  
  D3_SetHighBoxZ((_D3_OBJECT *)pl,(uint)*(ushort *)((pl->env2).Obj.primitive_top.Data + 10));
  D3_SetCollBits((_D3_OBJECT *)pl,0x2000);
  lVar1 = Boxes_TestObject((_D3_OBJECT *)pl);
  D3_SetHighBoxZ((_D3_OBJECT *)pl,(uint)(*(ushort *)((pl->env2).Obj.primitive_top.Data + 10) >> 1));
  D3_ClearCollBits((_D3_OBJECT *)pl,0x2000);
  return (uint)(lVar1 == 0);
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pactc_Shot()
 // line 264, offset 0x8003bb3c
	/* begin block 1 */
		// Start line: 265
		// Start offset: 0x8003BB3C
		// Variables:
	// 		struct _PLAYER *pl; // $s0
	// 		long Anm; // $a1
	// 		long reload; // $s2
	// 		long shot; // $s3

		/* begin block 1.1 */
			// Start line: 326
			// Start offset: 0x8003BCA8
			// Variables:
		// 		long iz; // $s4
		// 		long rz; // $s1
		/* end block 1.1 */
		// End offset: 0x8003BD60
		// End Line: 340
	/* end block 1 */
	// End offset: 0x8003BEA8
	// End Line: 393

	/* begin block 2 */
		// Start line: 628
	/* end block 2 */
	// End Line: 629

/* WARNING: Removing unreachable block (ram,0x8003bcf4) */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pactc_Shot(void)

{
  ushort uVar1;
  bool bVar2;
  ushort uVar3;
  long Anim;
  int iVar4;
  int iVar5;
  _PLAYER *pl;
  M_OBJECT *obj;
  uint uVar6;
  int iVar7;
  
  pl = (_PLAYER *)TaskCurrent->local;
  bVar2 = false;
  (pl->m_obj).Ani.Anim.Rot[4].m[3] = 0;
  Anim = Pl_IsWeaponAvailable(pl,(int)(char)(pl->env1).Obj.primitive_top.Data[0x19]);
  if (Anim == 0) {
    if (*(int *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x10) == 0) {
      Anim = Invent_ReloadAmmo(pl);
      bVar2 = true;
      if (Anim != 0) goto LAB_8003bbec;
    }
    do {
      Pafc_ExecKick();
      if (((pl->m_obj).dummy1 & PJOY_SHOT) == 0) {
        return;
      }
    } while ((pl->env1).Obj.primitive_top.Data[0x19] == 4);
  }
  else {
LAB_8003bbec:
    if (bVar2) {
      *(ushort *)&(pl->m_obj).shadow.u0 = *(ushort *)&(pl->m_obj).shadow.u0 | 0x400;
    }
    uVar6 = (uint)((pl->m_obj).dummy1 & PJOY_SHOT);
    if (((pl->m_obj).nFrame & 0x4000U) == 0) {
      Anim = 0x46;
      if (((pl->m_obj).shadow.clut & 0x800) != 0) {
        Anim = 0x10;
      }
    }
    else {
      Anim = 0x4f;
      if (((pl->m_obj).shadow.clut & 0x800) == 0) {
        uVar1 = *(ushort *)&(pl->m_obj).shadow.u0;
        Anim = 0x4e;
      }
      else {
        uVar1 = *(ushort *)&(pl->m_obj).shadow.u0;
      }
      *(ushort *)&(pl->m_obj).shadow.u0 = uVar1 | 8;
    }
    obj = (M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data;
    Manim_SetAnim(obj,Anim);
    *(ushort *)&(pl->m_obj).shadow.u0 = *(ushort *)&(pl->m_obj).shadow.u0 | 0x8000;
    uVar1 = *(ushort *)&(pl->m_obj).shadow.u0;
    (pl->m_obj).shadow.clut = (pl->m_obj).shadow.clut & 0xf7ff;
    if ((uVar1 & 8) == 0) {
      *(ushort *)&(pl->m_obj).shadow.u0 = uVar1 | 0x40;
      Manim_WaitAnim(obj);
      *(ushort *)&(pl->m_obj).shadow.u0 = *(ushort *)&(pl->m_obj).shadow.u0 & 0xffbf;
    }
    else {
      uVar1 = *(ushort *)&(pl->m_obj).Env.Obj.n_primitive;
      uVar3 = *(ushort *)
               (*(int *)(*(int *)((pl->m_obj).Env.Obj.primitive_top.Data + 0xc) +
                         (int)*(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x16) * 4 + 8) + 6
               ) >> 1;
      iVar7 = 0x80000 / (int)(uint)uVar3;
      iVar4 = iVar7;
      if (uVar3 == 0) {
        trap(0x1c00);
        iVar4 = iVar7;
      }
      while ((uVar1 & 0x4000) == 0) {
        iVar5 = 0x80000;
        if (iVar4 < 0x80001) {
          iVar5 = iVar4;
        }
        *(short *)&(pl->m_obj).shadow.u1 = (short)((uint)iVar5 >> 8);
        Task_Next();
        uVar1 = *(ushort *)&(pl->m_obj).Env.Obj.n_primitive;
        iVar4 = iVar5 + iVar7;
      }
      iVar5 = (int)(pl->obj).rot.vz;
      iVar7 = iVar5 + 0x800;
      *(ushort *)&(pl->m_obj).shadow.u0 = *(ushort *)&(pl->m_obj).shadow.u0 & 0xfff7;
      iVar4 = iVar7;
      if (iVar7 < 0) {
        iVar4 = iVar5 + 0x17ff;
      }
      (pl->obj).rot.vz = (short)iVar7 + (short)(iVar4 >> 0xc) * -0x1000;
    }
    obj = (M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data;
    do {
      *(undefined2 *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x26) = 0;
      *(undefined2 *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x24) = 0;
      if (!bVar2) goto LAB_8003bdf4;
      do {
        Pafc_Reload(pl,0x62);
        uVar3 = PJOY_SHOT;
        uVar1 = PJOY_AIM;
        *(ushort *)&(pl->m_obj).shadow.u0 = *(ushort *)&(pl->m_obj).shadow.u0 & 0xfbff;
        if ((ushort)((pl->m_obj).dummy1 & (uVar3 | uVar1)) == 0) break;
        Manim_SetAnim(obj,0x46);
        Manim_WaitAnim(obj);
LAB_8003bdf4:
        bVar2 = false;
        Anim = Pafc_ExecShot(0x54,uVar6 | (uint)((pl->m_obj).dummy1 & PJOY_SHOT));
        if (Anim != 0) {
          Anim = Invent_ReloadAmmo(pl);
          bVar2 = Anim != 0;
        }
        uVar6 = 0;
      } while (bVar2);
      if (!bVar2) {
        *(ushort *)&(pl->m_obj).shadow.u0 = *(ushort *)&(pl->m_obj).shadow.u0 | 0x4040;
        Manim_SetAnim(obj,0x47);
        Manim_WaitAnim(obj);
        *(ushort *)&(pl->m_obj).shadow.u0 = *(ushort *)&(pl->m_obj).shadow.u0 & 0xffbf;
      }
    } while (((ushort)((pl->m_obj).dummy1 & (PJOY_SHOT | PJOY_AIM)) != 0) &&
            (Anim = Pl_IsWeaponAvailable(pl,(int)(char)(pl->env1).Obj.primitive_top.Data[0x19]),
            Anim != 0));
    (pl->m_obj).Ani.Anim.Rot[4].m[3] = 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pafc_Reload(struct _PLAYER *pl /*$s1*/, long anm /*$a1*/)
 // line 396, offset 0x8003becc
	/* begin block 1 */
		// Start line: 397
		// Start offset: 0x8003BECC
		// Variables:
	// 		long m; // $s2
	/* end block 1 */
	// End offset: 0x8003BF0C
	// End Line: 413

	/* begin block 2 */
		// Start line: 910
	/* end block 2 */
	// End Line: 911

void Pafc_Reload(_PLAYER *pl,long anm)

{
  undefined2 uVar1;
  TASK *t;
  ushort uVar2;
  _D3_OBJECT **pp_Var3;
  M_OBJECT *obj;
  
  uVar1 = *(undefined2 *)&(pl->m_obj).shadow.u0;
  uVar2 = *(ushort *)&(pl->m_obj).shadow.u0 & 0x9fff;
  *(ushort *)&(pl->m_obj).shadow.u0 = uVar2 | 0x400;
  obj = (M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data;
  if (anm == 0x62) {
    *(ushort *)&(pl->m_obj).shadow.u0 = uVar2 | 0x440;
  }
  (pl->m_obj).Ani.Anim.nPivot = 10;
  *(undefined2 *)&(pl->m_obj).Sq.Data.nSon = 0;
  (pl->m_obj).Ani.Anim.nFrame = 0x3b;
  Manim_SetAnim(obj,anm);
  Manim_WaitEvent(obj,6);
  Invent_RemoveUsedObject(2,(int)(char)(pl->env1).Obj.primitive_top.Data[0x19],0);
  t = Overlay_Handle;
  pp_Var3 = &(pl->obj).next + (int)(char)(pl->env1).Obj.primitive_top.Data[0x19] * 2;
  *(short *)((int)pp_Var3 + 0x1aa) = *(short *)((int)pp_Var3 + 0x1aa) + 0x14;
  Task_EventExec(t,t->event_msg | 8,t->event_param);
  Manim_WaitAnim(obj);
  *(undefined2 *)&(pl->m_obj).shadow.u0 = uVar1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pafc_ExecKick()
 // line 433, offset 0x8003bf9c
	/* begin block 1 */
		// Start line: 434
		// Start offset: 0x8003BF9C
		// Variables:
	// 		struct _PLAYER *pl; // $s0
	// 		struct _D3_OBJECT kick; // stack offset -208
	// 		long anm; // $s1
	// 		long jump; // $s7
	// 		long height; // $s6
	// 		long power; // $s2
	// 		long kicked; // $s1
	// 		long again; // $s3
	// 		long loop; // $s5
	// 		long already; // $s2
	// 		long canexit; // $s4
	/* end block 1 */
	// End offset: 0x8003C370
	// End Line: 564

	/* begin block 2 */
		// Start line: 993
	/* end block 2 */
	// End Line: 994

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pafc_ExecKick(void)

{
  ushort uVar1;
  ushort uVar2;
  bool bVar3;
  char cVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  uint uVar9;
  _PLAYER *pl;
  long Anim;
  int iVar10;
  int iVar11;
  short sVar12;
  undefined auStack208 [28];
  short local_b4;
  uchar local_ae;
  uint local_a4;
  uint local_a0;
  uint local_9c;
  uint local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined local_37;
  _PLAYER *local_30;
  
  pl = (_PLAYER *)TaskCurrent->local;
  Overlay_ChangeRWeapon(pl,0x14);
  uVar1 = (pl->m_obj).shadow.clut;
  Anim = 0x27;
  if ((uVar1 & 0x800) == 0) {
    bVar3 = false;
    iVar10 = 8;
    if (((pl->m_obj).dummy1 & 0x4000U) == 0) {
      Anim = 0x5f;
      uVar9 = M_rand();
      sVar12 = 100;
      if ((uVar9 & 1) != 0) {
        Anim = 0x65;
      }
    }
    else {
      Anim = 0x28;
      sVar12 = 0x32;
    }
  }
  else {
    bVar3 = true;
    sVar12 = 0;
    iVar10 = 0x10;
    uVar2 = *(ushort *)&(pl->m_obj).shadow.u0;
    (pl->m_obj).shadow.clut = uVar1 & 0xf7ff;
    *(ushort *)&(pl->m_obj).shadow.u0 = uVar2 | 1;
  }
  iVar11 = (((int)((uint)*(ushort *)((pl->env2).Obj.primitive_top.Data + 0x10) +
                  (uint)(*(ushort *)((pl->env2).Obj.primitive_top.Data + 0x12) >> 1)) >> 8) + -0x1e)
           * 6 + 0x100;
  if (!bVar3) {
    *(ushort *)&(pl->m_obj).shadow.u0 = *(ushort *)&(pl->m_obj).shadow.u0 | 0x8040;
  }
  local_94 = *(undefined4 *)&(pl->obj).rot;
  local_90 = *(undefined4 *)&(pl->obj).rot.vz;
  D3_SetBox((_D3_OBJECT *)auStack208,-0x32,-0x32,-0x32,0x32,0x32,0x32);
  local_b4 = 0x2002;
  local_37 = 0xf3;
  local_ae = (uchar)((uint)(iVar10 * iVar11) >> 8);
  local_30 = pl;
  Manim_SetAnim((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data,Anim);
  bVar5 = false;
  bVar8 = false;
  bVar6 = false;
  bVar7 = false;
  if ((!bVar3) && ((uint)(ushort)Pvl_PlayerNumber - 1 < 2)) {
    Task_Sleep(6);
  }
  cVar4 = (char)pl;
  Fx_Play(0x1c,cVar4 + ',');
  uVar1 = *(ushort *)&(pl->m_obj).Env.Obj.n_primitive;
  while ((uVar1 & 0x4000) == 0) {
    if ((bVar8) && (((int)*(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x22) & 0x8000U) == 0)
       ) {
      bVar5 = true;
      bVar8 = false;
    }
    if ((bVar5) && (((int)*(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x22) & 0x8000U) != 0)
       ) break;
    if ((!bVar7) &&
       (((int)*(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x22) & 0x8000U) != 0)) {
      bVar8 = true;
      iVar10 = rcos((int)(pl->obj).rot.vz);
      local_a4 = local_a4 & 0xffff0000 |
                 (uint)(ushort)((pl->obj).pos.vx + (short)(iVar10 * 0x4b >> 0xc));
      iVar10 = rsin((int)(pl->obj).rot.vz);
      local_a4 = local_a4 & 0xffff |
                 (uint)(ushort)((pl->obj).pos.vy + (short)(iVar10 * 0x4b >> 0xc)) << 0x10;
      local_a0 = local_a0 & 0xffff0000 | (uint)(ushort)((pl->obj).pos.vz + sVar12);
      local_9c = local_a4;
      local_98 = local_a0;
      D3_ClearCollBits((_D3_OBJECT *)pl,1);
      Anim = Boxes_TestObject((_D3_OBJECT *)auStack208);
      if (Anim != 0) {
        Fx_Play(0xd,cVar4 + ',');
        Impact_Smoke(0x5c,1);
        bVar7 = true;
      }
      D3_SetCollBits((_D3_OBJECT *)pl,1);
    }
    uVar1 = *(ushort *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x22);
    if ((uVar1 & 0x2000) != 0) {
      iVar11 = (int)((uint)*(ushort *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x18) << 0x10) >>
               0x14;
    }
    if (((uVar1 & 0x4000) != 0) && (((pl->m_obj).nAnim & PJOY_SHOT) != 0)) {
      bVar6 = true;
    }
    if ((*(ushort *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x22) & 0x1000) != 0) {
      if (!bVar6) break;
      *(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x18) = (short)(iVar11 << 4);
      bVar6 = false;
      bVar7 = false;
      Fx_Play(0x1c,cVar4 + ',');
    }
    Task_Next();
    uVar1 = *(ushort *)&(pl->m_obj).Env.Obj.n_primitive;
  }
  if (!bVar5) {
    while (((int)*(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x22) & 0x8000U) != 0) {
      Task_Next();
    }
  }
  if (bVar3) {
    Pafj_ExecJpDown(1);
  }
  else {
    Manim_WaitAnim((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data);
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Pafc_ExecShot(long recul_anm /*stack 0*/, long first /*stack 4*/)
 // line 567, offset 0x8003c3a0
	/* begin block 1 */
		// Start line: 568
		// Start offset: 0x8003C3A0
		// Variables:
	// 		struct _PLAYER *pl; // $s2
	// 		struct _D3_OBJECT *ot; // $s5
	// 		struct _D3_OBJECT *otz; // stack offset -56
	// 		long target_y; // $fp
	// 		long target_z; // $s7
	// 		long mini_y; // stack offset -52
	// 		long exit; // $s1
	// 		long hold; // stack offset -48
	// 		long c_weapon; // $s0
	// 		long need_ammo; // $a2
	// 		long shot; // $s3

		/* begin block 1.1 */
			// Start line: 597
			// Start offset: 0x8003C47C
			// Variables:
		// 		long d; // $s3
		// 		long dz; // $v1
		// 		struct P_ACTC_7fake p; // stack offset -64

			/* begin block 1.1.1 */
				// Start line: 605
				// Start offset: 0x8003C49C
			/* end block 1.1.1 */
			// End offset: 0x8003C5B4
			// End Line: 615
		/* end block 1.1 */
		// End offset: 0x8003C660
		// End Line: 628
	/* end block 1 */
	// End offset: 0x8003C928
	// End Line: 723

	/* begin block 2 */
		// Start line: 1277
	/* end block 2 */
	// End Line: 1278

/* WARNING: Type propagation algorithm not settling */

long Pafc_ExecShot(long recul_anm,long first)

{
  ushort uVar1;
  bool bVar2;
  bool bVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  long d1;
  long lVar7;
  long lVar8;
  int iVar9;
  int iVar10;
  ulong uVar11;
  _PLAYER *pl;
  _D3_OBJECT *ot;
  int iVar12;
  int iVar13;
  long local_res4;
  short local_40;
  short local_3e;
  short local_3c;
  _D3_OBJECT *local_38;
  int local_34;
  
  pl = (_PLAYER *)TaskCurrent->local;
  if (recul_anm == 0x54) {
    local_34 = -0x380;
  }
  else {
    local_34 = 0;
  }
  iVar13 = (int)*(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x24);
  iVar12 = (int)*(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x26);
  local_res4 = first;
  do {
    ot = (_D3_OBJECT *)0x0;
    local_38 = (_D3_OBJECT *)0x0;
    uVar1 = (pl->m_obj).dummy1 & PJOY_AIM;
    (pl->obj).rot.vz = (pl->obj).rot.vz + (short)iVar12 + 0x1000U & 0xfff;
    if ((uVar1 == 0) && ((pl->env1).Obj.primitive_top.Data[0x19] == 0)) {
      ot = D3_SeekLookTarget((_D3_OBJECT *)pl,0x80,0,0x10);
    }
    (pl->obj).rot.vz = ((pl->obj).rot.vz - (short)iVar12) + 0x1000U & 0xfff;
    if (ot != (_D3_OBJECT *)0x0) {
      Boxes_GetCenter(ot,0xc0);
      if ((ot->display_mode & 0x40U) != 0) {
        iVar5 = rcos((int)(ot->rot).vz);
        iVar6 = rsin((int)(ot->rot).vz);
        d1 = Distance3D((int)(pl->obj).pos.vx,(int)(pl->obj).pos.vy,(int)(pl->obj).pos.vz,
                        (int)(ot->pos).vx,(int)(ot->pos).vy,(int)(ot->pos).vz);
        lVar7 = Manim_GetSpdX((M_OBJECT *)ot->description);
        sVar4 = (short)(d1 / 100);
        d1 = Manim_GetSpdY((M_OBJECT *)ot->description);
        lVar8 = Manim_GetSpdZ((M_OBJECT *)ot->description);
        iVar10 = (int)(short)((short)lVar7 * sVar4);
        iVar9 = (int)(short)((short)d1 * sVar4);
        local_3c = local_3c + (short)lVar8 * sVar4;
        local_40 = local_40 + (short)(iVar10 * (int)(short)iVar5 - iVar9 * (int)(short)iVar6 >> 0xc)
        ;
        local_3e = local_3e + (short)(iVar10 * (int)(short)iVar6 + iVar9 * (int)(short)iVar5 >> 0xc)
        ;
      }
      d1 = Direction((int)local_40 - (int)(pl->obj).pos.vx,(int)local_3e - (int)(pl->obj).pos.vy);
      d1 = DeltaDirection(d1,(int)(pl->obj).rot.vz);
      lVar7 = DirectionZ((int)local_40 - (int)(pl->obj).pos.vx,(int)local_3e - (int)(pl->obj).pos.vy
                         ,((int)local_3c + -0x96) - (int)(pl->obj).pos.vz);
      if (0x7ff < lVar7) {
        lVar7 = lVar7 + -0x1000;
      }
      if (((lVar7 < 0x200) && (local_34 < lVar7)) && ((ot->collision_mode & 0x4000U) != 0)) {
        *(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x24) = (short)lVar7;
        local_38 = ot;
      }
      *(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x26) = (short)d1;
    }
    uVar11 = (pl->m_obj).Ani.nAnim;
    bVar3 = false;
    *(undefined4 *)((pl->m_obj).Env.Obj.primitive_top.Data + 4) =
         *(undefined4 *)&(pl->m_obj).Env.Data.nNorm;
    *(ulong *)((pl->m_obj).Env.Obj.primitive_top.Data + 8) = uVar11;
    Manim_ForceAnim((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data,recul_anm);
    bVar2 = false;
    iVar5 = (int)(char)(pl->env1).Obj.primitive_top.Data[0x19];
    uVar1 = (pl->m_obj).dummy1 & PJOY_SHOT;
    *(ushort *)&(pl->m_obj).Env.Obj.n_primitive =
         *(ushort *)&(pl->m_obj).Env.Obj.n_primitive & 0xfffe | 4;
    if ((uVar1 != 0) || (local_res4 != 0)) {
      PShoot_Add(pl);
      bVar3 = true;
      local_res4 = 0;
      if (1 < iVar5 - 1U) {
        *(ushort *)&(pl->m_obj).Env.Obj.n_primitive =
             *(ushort *)&(pl->m_obj).Env.Obj.n_primitive | 1;
      }
    }
    do {
      uVar1 = (pl->m_obj).dummy1;
      if ((uVar1 & PJOY_AIM) != 0) {
        ot = (_D3_OBJECT *)0x0;
      }
      if ((recul_anm == 0x54) || ((recul_anm == 0x57 && ((uVar1 & PJOY_STRAFE) != 0)))) {
        if ((uVar1 & 0x2000) != 0) {
          (pl->obj).rot.vz = (pl->obj).rot.vz + 0xfd0U & 0xfff;
        }
        if (((pl->m_obj).dummy1 & 0x8000U) != 0) {
          (pl->obj).rot.vz = (pl->obj).rot.vz + 0x30U & 0xfff;
        }
      }
      else {
        if (((((pl->m_obj).dummy1 & 0x2000U) != 0) && (ot == (_D3_OBJECT *)0x0)) &&
           (-0x100 < iVar12)) {
          iVar12 = iVar12 + -0x10;
        }
        if (((((pl->m_obj).dummy1 & 0x8000U) != 0) && (ot == (_D3_OBJECT *)0x0)) && (iVar12 < 0x100)
           ) {
          iVar12 = iVar12 + 0x10;
        }
      }
      if (((((pl->m_obj).dummy1 & 0x1000U) != 0) && (local_38 == (_D3_OBJECT *)0x0)) &&
         (iVar13 < 0x380)) {
        iVar13 = iVar13 + 0x20;
      }
      if (((((pl->m_obj).dummy1 & 0x4000U) != 0) && (local_38 == (_D3_OBJECT *)0x0)) &&
         (local_34 < iVar13)) {
        iVar13 = iVar13 + -0x20;
      }
      if (ot == (_D3_OBJECT *)0x0) {
        *(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x24) = (short)iVar13;
        *(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x26) = (short)iVar12;
      }
      Task_Next();
      if (iVar5 - 1U < 2) {
        if ((((pl->m_obj).dummy1 & PJOY_SHOT) == 0) ||
           (*(short *)((pl->env1).Obj.primitive_top.Data + iVar5 * 8 + 0x1a) == 0)) {
LAB_8003c8cc:
          bVar2 = true;
        }
        else {
          if ((int)(char)(pl->env1).Obj.primitive_top.Data[0x19] != iVar5) {
            bVar2 = true;
          }
        }
      }
      else {
        if ((*(ushort *)&(pl->m_obj).Env.Obj.n_primitive & 0x4000) != 0) goto LAB_8003c8cc;
      }
    } while ((!bVar2) && (bVar3));
    iVar6 = (int)(char)(pl->env1).Obj.primitive_top.Data[0x19];
    bVar2 = *(short *)((pl->env1).Obj.primitive_top.Data + iVar6 * 8 + 0x1a) == 0;
    if (((ushort)((pl->m_obj).dummy1 & (PJOY_SHOT | PJOY_AIM)) == 0) ||
       ((bVar2 || (iVar6 != iVar5)))) {
      uVar11 = (pl->m_obj).Ani.Text;
      *(undefined4 *)((pl->m_obj).Env.Obj.primitive_top.Data + 4) =
           *(undefined4 *)&(pl->m_obj).Env.Data.nPrim;
      *(ulong *)((pl->m_obj).Env.Obj.primitive_top.Data + 8) = uVar11;
      return (uint)bVar2;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pactc_Bomb()
 // line 730, offset 0x8003c96c
	/* begin block 1 */
		// Start line: 731
		// Start offset: 0x8003C96C
		// Variables:
	// 		struct _PLAYER *pl; // $s1
	// 		long length; // $s3
	/* end block 1 */
	// End offset: 0x8003CAF0
	// End Line: 792

	/* begin block 2 */
		// Start line: 1657
	/* end block 2 */
	// End Line: 1658

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pactc_Bomb(void)

{
  long Anim;
  M_OBJECT *obj;
  _PLAYER *pl;
  uint uVar1;
  uint speed;
  
  pl = (_PLAYER *)TaskCurrent->local;
  (pl->m_obj).Ani.Anim.Rot[4].m[3] = 0;
  uVar1 = 0;
  if ((&Pl_LeftWeapons)[(int)(char)(pl->env1).Obj.primitive_top.Data[0x18]] == 5) {
    obj = (M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data;
    Manim_SetAnim(obj,0x25);
    Task_Sleep(4);
    uVar1 = (uint)(((pl->m_obj).dummy1 & PJOY_BOMB) != 0);
    Manim_WaitEvent(obj,0x8000);
    if (((pl->m_obj).dummy1 & PJOY_BOMB) != 0) {
      Task_Sleep(6);
      speed = uVar1 + 1;
      if (((pl->m_obj).dummy1 & PJOY_BOMB) != 0) {
        speed = uVar1 + 2;
      }
      goto LAB_8003ca7c;
    }
    Anim = 0x26;
  }
  else {
    speed = uVar1;
    if ((&Pl_LeftWeapons)[(int)(char)(pl->env1).Obj.primitive_top.Data[0x18]] != 6)
    goto LAB_8003ca7c;
    Anim = 0x1f;
  }
  Manim_SetAnim((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data,Anim);
  speed = uVar1;
LAB_8003ca7c:
  obj = (M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data;
  Manim_WaitEvent(obj,0x8000);
  Invent_RemoveUsedObject
            ((int)(&Pl_LeftWeapons)[(int)(char)(pl->env1).Obj.primitive_top.Data[0x18]],0,0);
  PGrenade_Add(pl,speed);
  Manim_WaitAnim(obj);
  if ((&Pl_LeftWeapons)[(int)(char)(pl->env1).Obj.primitive_top.Data[0x18]] == 6) {
    Manim_SetAnim(obj,0x20);
    Manim_WaitAnim(obj);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pactc_UseCanon()
 // line 808, offset 0x8003cb0c
	/* begin block 1 */
		// Start line: 809
		// Start offset: 0x8003CB0C
		// Variables:
	// 		struct _PLAYER *pl; // $s3
	// 		struct _D3_OBJECT *ou; // $s2
	// 		struct _D3_OBJECT *oc; // $v1
	// 		struct M_OBJECT *mu; // $s4
	// 		struct P_ACTC_7fake pos; // stack offset -96
	// 		struct P_ACTC_8fake col; // stack offset -88
	// 		struct TASK *shot_handle; // $s5
	// 		short l; // $s0
	// 		short dx; // $v0
	// 		short dy; // $v0
	// 		short rx; // stack offset -80
	// 		short ry; // stack offset -72
	// 		short rz; // stack offset -64
	// 		short snd_actif; // $s7
	// 		short snd_motor; // $s1
	// 		short Fx_Handle; // $fp
	// 		short shot; // $s6
	// 		short c_weapon; // stack offset -56
	// 		short shot_type; // $s1
	/* end block 1 */
	// End offset: 0x8003D4BC
	// End Line: 1052

	/* begin block 2 */
		// Start line: 1818
	/* end block 2 */
	// End Line: 1819

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pactc_UseCanon(void)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  undefined2 uVar4;
  short sVar5;
  char cVar6;
  bool bVar7;
  bool bVar8;
  ushort uVar9;
  short sVar10;
  short snd_handle;
  int iVar11;
  uint uVar12;
  long lVar13;
  int iVar14;
  int iVar15;
  _D3_OBJECT *p_Var16;
  int mode;
  int iVar17;
  undefined4 uVar18;
  int iVar19;
  M_OBJECT *obj;
  _D3_OBJECT *o;
  _PLAYER *pl;
  void *pvVar20;
  TASK *t;
  uint uVar21;
  
  pl = (_PLAYER *)TaskCurrent->local;
  (pl->m_obj).Ani.Anim.Rot[4].m[3] = 0;
  t = TaskCurrent;
  *(ushort *)&(pl->m_obj).shadow.u0 = *(ushort *)&(pl->m_obj).shadow.u0 | 4;
  o = (_D3_OBJECT *)t->event_param;
  t = (TASK *)0x0;
  sVar2 = (o->pos).vx;
  snd_handle = 0;
  mode = (int)(o->rot).vz;
  sVar3 = (o->pos).vy;
  iVar14 = mode + 0x1000;
  iVar11 = iVar14;
  if (iVar14 < 0) {
    iVar11 = mode + 0x1fff;
  }
  pvVar20 = o->description;
  *(undefined2 *)((int)pvVar20 + 0x24) = 0;
  *(ushort *)((int)pvVar20 + 0x28) = *(ushort *)((int)pvVar20 + 0x28) | 4;
  bVar1 = (pl->env1).Obj.primitive_top.Data[0x19];
  *(_D3_OBJECT **)&(pl->m_obj).Scale = o;
  uVar9 = SEXT12((char)bVar1);
  Overlay_ChangeRWeapon(pl,0x15);
  sVar10 = o[1].last_pos.vx;
  uVar4 = *(undefined2 *)((int)&o[1].father + 2);
  (pl->m_obj).Ani.Anim.nPivot = 3;
  (pl->m_obj).Ani.Anim.nFrame = 4;
  *(undefined2 *)&(pl->m_obj).Sq.Data.nSon = uVar4;
  mode = *(int *)((int)pvVar20 + 0xc);
  *(int *)((pl->m_obj).Env.Obj.primitive_top.Data + 0xc) = mode;
  mode = *(int *)(mode + 0xc);
  sVar5 = *(short *)(mode + ((uint)*(ushort *)(mode + 6) - 1) * 8 + 0x14);
  mode = rcos((int)(o->rot).vz);
  iVar19 = (int)sVar5;
  (pl->obj).pos.vx = (o->pos).vx - (short)(iVar19 * mode >> 0xc);
  bVar7 = false;
  mode = rsin((int)(o->rot).vz);
  uVar21 = 0;
  obj = (M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data;
  (pl->obj).pos.vy = (o->pos).vy - (short)(iVar19 * mode >> 0xc);
  (pl->obj).rot.vz = (o->rot).vz;
  Manim_SetAnim(obj,1);
  D3_ClearCollBits((_D3_OBJECT *)pl,8);
  Manim_WaitAnim(obj);
  *(ushort *)&(pl->m_obj).Env.Obj.n_primitive = *(ushort *)&(pl->m_obj).Env.Obj.n_primitive & 0xfffe
  ;
  uVar18 = *(undefined4 *)&(pl->obj).pos.vz;
  *(undefined4 *)&(pl->obj).last_pos = *(undefined4 *)&(pl->obj).pos;
  *(undefined4 *)&(pl->obj).last_pos.vz = uVar18;
  D3_SetCollBits((_D3_OBJECT *)pl,8);
  mode = (int)sVar10;
  do {
    bVar8 = false;
    if (((pl->m_obj).dummy1 & 0x8000U) != 0) {
      iVar17 = (int)(o->rot).vz;
      iVar15 = iVar17 + 0x20;
      iVar19 = iVar15;
      if (iVar15 < 0) {
        iVar19 = iVar17 + 0x101f;
      }
      bVar8 = true;
      sVar10 = (short)iVar15 + (short)(iVar19 >> 0xc) * -0x1000;
      (o->rot).vz = sVar10;
      (pl->obj).rot.vz = sVar10;
    }
    if (((pl->m_obj).dummy1 & 0x2000U) != 0) {
      iVar17 = (int)(o->rot).vz;
      iVar15 = iVar17 + 0xfe0;
      iVar19 = iVar15;
      if (iVar15 < 0) {
        iVar19 = iVar17 + 0x1fdf;
      }
      bVar8 = true;
      sVar10 = (short)iVar15 + (short)(iVar19 >> 0xc) * -0x1000;
      (o->rot).vz = sVar10;
      (pl->obj).rot.vz = sVar10;
    }
    p_Var16 = o->child;
    while (p_Var16 != (_D3_OBJECT *)0x0) {
      (p_Var16->rot).vz = (o->rot).vz;
      uVar18 = *(undefined4 *)&(o->pos).vz;
      *(undefined4 *)&p_Var16->pos = *(undefined4 *)&o->pos;
      *(undefined4 *)&(p_Var16->pos).vz = uVar18;
      p_Var16 = p_Var16->next;
    }
    if ((((pl->m_obj).dummy1 & 0x1000U) != 0) && (*(short *)((int)pvVar20 + 0x24) < 0x100)) {
      *(short *)((int)pvVar20 + 0x24) = *(short *)((int)pvVar20 + 0x24) + 0x20;
      bVar8 = true;
    }
    if ((((pl->m_obj).dummy1 & 0x4000U) != 0) && (-0x100 < *(short *)((int)pvVar20 + 0x24))) {
      *(short *)((int)pvVar20 + 0x24) = *(short *)((int)pvVar20 + 0x24) + -0x20;
      bVar8 = true;
    }
    cVar6 = (char)o;
    if (((pl->m_obj).nAnim & PJOY_SHOT) != 0) {
      if (o[1].pos.pad == 0) {
        Fx_Play(0x40,cVar6 + ',');
      }
      else {
        rcos((int)(o->rot).vz);
        rsin((int)(o->rot).vz);
        sVar10 = *(short *)((int)pvVar20 + 0x24);
        (o->rot).vx = sVar10;
        rsin((int)sVar10);
        if ((mode < 3) && (-1 < mode)) {
          t = Motion2D_Flame((_D3_OBJECT *)pl,0xa0,cVar6 + '<',1,0xf,0x28,mode);
        }
        else {
          Shoot_Add((_D3_OBJECT *)pl,0xa0,cVar6 + '<',0xa8,8,0,(uint)o->hit_power,0);
        }
        (o->rot).vx = 0;
        D3_PlaySound(o,5);
        uVar21 = 3;
        iVar19 = rcos((int)(o->rot).vz);
        sVar10 = (o->rot).vz;
        (o->pos).vx = (o->pos).vx - (short)(iVar19 * 10 >> 0xc);
        iVar19 = rsin((int)sVar10);
        sVar10 = o[1].pos.pad;
        (o->pos).vy = (o->pos).vy - (short)(iVar19 * 10 >> 0xc);
        if (sVar10 < 15000) {
          o[1].pos.pad = o[1].pos.pad + -1;
        }
        Task_EventExec(Overlay_Handle,Overlay_Handle->event_msg | 8,Overlay_Handle->event_param);
      }
    }
    if (t != (TASK *)0x0) {
      if (((pl->m_obj).dummy1 & PJOY_SHOT) == 0) {
        Motion2D_FlameModify(t,0,0);
        t = (TASK *)0x0;
      }
      else {
        (o->rot).vx = *(short *)((int)pvVar20 + 0x24);
        rcos((int)(o->rot).vz);
        rsin((int)(o->rot).vz);
        rsin((int)(o->rot).vx);
        Motion2D_FlameModify(t,0xa0,cVar6 + '<');
        (o->rot).vx = 0;
      }
    }
    if (bVar7) {
      if (!bVar8) {
        D3_StopSound(o,snd_handle);
        D3_PlaySound(o,2);
        bVar7 = false;
      }
    }
    else {
      if (bVar8) {
        D3_PlaySound(o,0);
        snd_handle = D3_PlaySound(o,1);
        bVar7 = true;
      }
    }
    iVar19 = rcos((int)(o->rot).vz);
    iVar15 = rsin((int)(o->rot).vz);
    (pl->obj).pos.vx =
         ((o->pos).vx + (short)(iVar19 * -0x1a >> 0xc)) - (short)(iVar15 * 0x20 >> 0xc);
    iVar19 = rsin((int)(o->rot).vz);
    iVar15 = rcos((int)(o->rot).vz);
    (pl->obj).pos.vy = (o->pos).vy + (short)(iVar19 * -0x1a >> 0xc) + (short)(iVar15 * 0x20 >> 0xc);
    (pl->obj).rot.vz = (o->rot).vz;
    Task_Next();
    uVar12 = uVar21 - 1;
    if ((uVar21 & 0xffff) != 0) {
      iVar19 = (int)(uVar12 * 0x10000) >> 0x10;
      if (iVar19 == 1) {
LAB_8003d234:
        iVar19 = rcos((int)(o->rot).vz);
        sVar10 = (o->rot).vz;
        (o->pos).vx = (o->pos).vx + (short)(iVar19 * 3 >> 0xc);
        iVar19 = rsin((int)sVar10);
        (o->pos).vy = (o->pos).vy + (short)(iVar19 * 3 >> 0xc);
        uVar21 = uVar12;
      }
      else {
        if (iVar19 < 2) {
          uVar21 = uVar12;
          if (iVar19 == 0) {
            (o->pos).vx = sVar2;
            (o->pos).vy = sVar3;
            uVar21 = uVar12;
          }
        }
        else {
          uVar21 = uVar12;
          if (iVar19 == 2) goto LAB_8003d234;
        }
      }
    }
    if ((o->collision_state & 4U) != 0) {
      *(undefined *)((int)&o[1].pos.vx + 1) = 0xfe;
      if (bVar7) {
        D3_StopSound(o,snd_handle);
      }
      Overlay_ChangeRWeapon(pl,(short)(((uint)uVar9 + 0x10) * 0x10000 >> 0x10));
      Pl_ForceAction(pl,0xf,(long)o);
    }
    if (((pl->m_obj).nAnim & PJOY_JUMP) != 0) {
      if (t != (TASK *)0x0) {
        Motion2D_FlameModify(t,0,0);
      }
      if (!bVar7) {
        D3_PlaySound(o,0);
      }
      if (!bVar8) {
        snd_handle = D3_PlaySound(o,1);
      }
      *(undefined2 *)((int)pvVar20 + 0x24) = 0;
      uVar21 = SEXT24((short)((short)iVar14 + (short)(iVar11 >> 0xc) * -0x1000));
      iVar11 = rcos(uVar21);
      iVar14 = rsin(uVar21);
      while (lVar13 = D3_GoToDir(o,(int)(short)((uint)(iVar11 * 0x19) >> 9),
                                 (int)(short)((uint)(iVar14 * 0x19) >> 9),0x20), lVar13 != 0) {
        mode = rcos((int)(o->rot).vz);
        iVar19 = rsin((int)(o->rot).vz);
        (pl->obj).pos.vx =
             ((o->pos).vx + (short)(mode * -0x1a >> 0xc)) - (short)(iVar19 * 0x20 >> 0xc);
        mode = rsin((int)(o->rot).vz);
        iVar19 = rcos((int)(o->rot).vz);
        (pl->obj).pos.vy =
             (o->pos).vy + (short)(mode * -0x1a >> 0xc) + (short)(iVar19 * 0x20 >> 0xc);
        (pl->obj).rot.vz = (o->rot).vz;
        p_Var16 = o->child;
        while (p_Var16 != (_D3_OBJECT *)0x0) {
          (p_Var16->rot).vz = (o->rot).vz;
          p_Var16 = p_Var16->next;
        }
        Task_Next();
      }
      D3_PlaySound(o,2);
      D3_StopSound(o,snd_handle);
      Overlay_ChangeRWeapon(pl,(short)(((uint)uVar9 + 0x10) * 0x10000 >> 0x10));
      Manim_SetAnim((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data,2);
      *(ushort *)&(pl->m_obj).shadow.u0 = *(ushort *)&(pl->m_obj).shadow.u0 & 0xfffb;
      Pafj_ExecJpDown(-1);
      return;
    }
  } while( true );
}





