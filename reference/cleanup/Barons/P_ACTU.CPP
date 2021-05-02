#include "THISDUST.H"
#include "P_ACTU.H"


// decompiled code
// original method signature: 
// void /*$ra*/ Pactu_Dead()
 // line 24, offset 0x8003d53c
	/* begin block 1 */
		// Start line: 25
		// Start offset: 0x8003D53C
		// Variables:
	// 		struct _PLAYER *pl; // $s1
	// 		long mode; // $s0

		/* begin block 1.1 */
			// Start line: 47
			// Start offset: 0x8003D5AC
			// Variables:
		// 		struct _D3_OBJECT *os; // $v0
		// 		long zs; // $a0
		/* end block 1.1 */
		// End offset: 0x8003D61C
		// End Line: 67
	/* end block 1 */
	// End offset: 0x8003D6B8
	// End Line: 109

	/* begin block 2 */
		// Start line: 49
	/* end block 2 */
	// End Line: 50

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pactu_Dead(void)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  short Fx;
  int iVar4;
  void *pvVar5;
  
  pvVar5 = TaskCurrent->local;
  *(undefined2 *)(*(int *)((int)pvVar5 + 0xf8) + 0x56) = 0;
  iVar4 = *(int *)(*(int *)((int)pvVar5 + 0xf8) + 0x5c);
  uVar2 = *(ushort *)((int)pvVar5 + 0x1e);
  *(undefined2 *)((int)pvVar5 + 0x20) = 0;
  *(undefined4 *)((int)pvVar5 + 0x118) = 0;
  *(ushort *)((int)pvVar5 + 0x1e) = uVar2 | 8;
  if (iVar4 == 1) {
    if ((uVar2 & 0x20) == 0) {
      Pafu_DeadByFall();
      goto LAB_8003d6a8;
    }
  }
  else {
    if ((1 < iVar4) || (iVar4 != 0)) goto LAB_8003d6a8;
    if ((uVar2 & 0x20) != 0) {
      iVar3 = *(int *)((int)pvVar5 + 0x94);
      cVar1 = *(char *)(iVar3 + 0x99);
      if ('\0' < cVar1) {
        if (cVar1 < '\x04') {
          if ((int)*(short *)((int)pvVar5 + 0x30) + (int)*(short *)((int)pvVar5 + 0x70) <
              (int)*(short *)(iVar3 + 0x30) + (int)*(short *)(iVar3 + 0x70) +
              (int)*(short *)(iVar3 + 0x9a)) {
            iVar4 = 2;
          }
        }
        else {
          if (cVar1 == '\x04') {
            iVar4 = 1;
          }
        }
      }
    }
    if (iVar4 != 2) {
      Track_SetMode(4,0);
      if (iVar4 == 0) {
        Manim_SetAnim((M_OBJECT *)((int)pvVar5 + 0xa4),0);
        Fx = 7;
      }
      else {
        Manim_SetAnim((M_OBJECT *)((int)pvVar5 + 0xa4),1);
        Manim_SetEffect((M_OBJECT *)((int)pvVar5 + 0xa4),Motion2D_ManimBurn);
        Fx = 4;
      }
      Fx_Play(Fx,(char)pvVar5 + ',');
      Pafj_ExecJpDown(1);
      goto LAB_8003d6a8;
    }
  }
  Pafu_DeadInLiquid();
LAB_8003d6a8:
  do {
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pafu_DeadByFall()
 // line 112, offset 0x8003d6b8
	/* begin block 1 */
		// Start line: 113
		// Start offset: 0x8003D6B8
		// Variables:
	// 		struct _PLAYER *pl; // $s0
	/* end block 1 */
	// End offset: 0x8003D724
	// End Line: 132

	/* begin block 2 */
		// Start line: 227
	/* end block 2 */
	// End Line: 228

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pafu_DeadByFall(void)

{
  void *pvVar1;
  
  pvVar1 = TaskCurrent->local;
  Track_SetMode(4,1);
  Fx_Play(9,(char)pvVar1 + ',');
  Manim_SetAnim((M_OBJECT *)((int)pvVar1 + 0xa4),1);
  do {
    *(short *)((int)pvVar1 + 0x40) = *(short *)((int)pvVar1 + 0x40) + 0x80;
    *(short *)((int)pvVar1 + 0x30) = *(short *)((int)pvVar1 + 0x30) + -0x21;
    *(short *)((int)pvVar1 + 0x3c) = *(short *)((int)pvVar1 + 0x3c) + 0x20;
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pafu_DeadInLiquid()
 // line 135, offset 0x8003d724
	/* begin block 1 */
		// Start line: 136
		// Start offset: 0x8003D724
		// Variables:
	// 		struct _PLAYER *pl; // $s0
	// 		struct P_ACTU_7fake pos; // stack offset -24
	/* end block 1 */
	// End offset: 0x8003D83C
	// End Line: 166

	/* begin block 2 */
		// Start line: 279
	/* end block 2 */
	// End Line: 280

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pafu_DeadInLiquid(void)

{
  uint uVar1;
  void *pvVar2;
  
  pvVar2 = TaskCurrent->local;
  Track_SetMode(4,0);
  Fx_Play(8,(char)pvVar2 + ',');
  Manim_SetAnim((M_OBJECT *)((int)pvVar2 + 0xa4),1);
  *(ushort *)((int)pvVar2 + 0xcc) = *(ushort *)((int)pvVar2 + 0xcc) & 0xfffe;
  do {
    *(short *)((int)pvVar2 + 0x30) = *(short *)((int)pvVar2 + 0x30) + -1;
    uVar1 = M_rand();
    if ((uVar1 & 3) == 0) {
      rcos((int)*(short *)((int)pvVar2 + 0x40));
      rsin((int)*(short *)((int)pvVar2 + 0x40));
      Impact_Bubble(0xe8,10,0x1e,0);
    }
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pactu_Hurt()
 // line 169, offset 0x8003d83c
	/* begin block 1 */
		// Start line: 170
		// Start offset: 0x8003D83C
		// Variables:
	// 		struct _PLAYER *pl; // $s1
	// 		struct _D3_OBJECT *ot; // $s2
	// 		long d; // $s3
	// 		long mode; // $s4
	/* end block 1 */
	// End offset: 0x8003DAB0
	// End Line: 261

	/* begin block 2 */
		// Start line: 365
	/* end block 2 */
	// End Line: 366

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pactu_Hurt(void)

{
  byte bVar1;
  long d;
  char pos;
  _PLAYER *pl;
  _D3_OBJECT *o;
  ushort hits;
  int iVar2;
  
  pl = (_PLAYER *)TaskCurrent->local;
  Pl_SetStateBits(pl,1);
  o = (_D3_OBJECT *)TaskCurrent->event_param;
  TaskCurrent->event_enable = 0;
  hits = (ushort)o->hit_power;
  iVar2 = (int)*(char *)((int)&o[1].pos.vx + 1);
  if (((pl->env2).Obj.primitive_top.Data[4] == 0xb) &&
     (bVar1 = o->hit_power >> 1, hits = (ushort)bVar1, bVar1 == 0)) {
    hits = 1;
  }
  Pl_ReduceHitPoints(pl,hits);
  if ((iVar2 == 1) && (o[1].pos.vy == 0x12)) {
    iVar2 = -0x13;
  }
  else {
    Impact_D3Blood((char)pl + ',',o,0xf);
  }
  d = Direction((int)(pl->obj).pos.vx - (int)(o->pos).vx,(int)(pl->obj).pos.vy - (int)(o->pos).vy);
  switch(iVar2) {
  case -0x13:
    Manim_SetEffect((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data,Motion2D_ManimDistortion);
    break;
  case -0x10:
  case -9:
    hits = *(ushort *)&(pl->m_obj).shadow.u0;
    (pl->m_obj).shadow.tpage = 1;
    *(ushort *)&(pl->m_obj).shadow.u0 = hits | 0x80;
    break;
  case -0xf:
  case -10:
    pos = (char)pl + ',';
    hits = *(ushort *)&(pl->m_obj).shadow.u0;
    (pl->m_obj).shadow.tpage = 2;
    *(ushort *)&(pl->m_obj).shadow.u0 = hits | 0x80;
    Fx_Play(0x1d,pos);
    Fx_Play(0x1f,pos);
  }
  if (iVar2 == -0x13) {
    D3_PlaySound(o,1);
    Fx_Play(7,0);
    d = 2;
    *(ushort *)&(pl->m_obj).Env.Obj.n_primitive =
         *(ushort *)&(pl->m_obj).Env.Obj.n_primitive & 0xfffe;
  }
  else {
    if ((iVar2 == 0xd) && (o[1].pos.vy == 0xd)) {
      Pafu_HurtByPics(o);
      return;
    }
    if (iVar2 + 6U < 5) {
      Pafu_HurtByExplosion(o,d);
      return;
    }
    if ((((pl->m_obj).shadow.clut & 2) != 0) && (*(char *)((int)&o[1].pos.vx + 1) != -0xe)) {
      Pafu_HurtWhileHold(o);
      return;
    }
    if (iVar2 + 0xeU < 2) {
      Pafu_HurtByKick(o,d);
      return;
    }
    if ((pl->obj).hit_points != 0) {
      Pafu_HurtByShot(o,d);
      return;
    }
    Task_Next();
    d = 0;
  }
  Pl_ForceAction(pl,0x10,d);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pafu_HurtWhileHold(struct _D3_OBJECT *oh /*$a0*/)
 // line 264, offset 0x8003dad0
	/* begin block 1 */
		// Start line: 265
		// Start offset: 0x8003DAD0
		// Variables:
	// 		struct _PLAYER *pl; // $s0
	/* end block 1 */
	// End offset: 0x8003DAD0
	// End Line: 265

	/* begin block 2 */
		// Start line: 564
	/* end block 2 */
	// End Line: 565

void Pafu_HurtWhileHold(_D3_OBJECT *oh)

{
  void *pvVar1;
  
  pvVar1 = TaskCurrent->local;
  Fx_Play(1,(char)pvVar1 + ',');
  Manim_SetAnim((M_OBJECT *)((int)pvVar1 + 0xa4),0x60);
  *(ushort *)((int)pvVar1 + 0x11c) = *(ushort *)((int)pvVar1 + 0x11c) & 0xfffb;
  Pafj_ExecJpDown(-1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pafu_HurtByShot(struct _D3_OBJECT *oh /*$a0*/, long d /*$s2*/)
 // line 277, offset 0x8003db24
	/* begin block 1 */
		// Start line: 278
		// Start offset: 0x8003DB24
		// Variables:
	// 		struct _PLAYER *pl; // $s0
	// 		long esquive; // $s1
	/* end block 1 */
	// End offset: 0x8003DC1C
	// End Line: 317

	/* begin block 2 */
		// Start line: 592
	/* end block 2 */
	// End Line: 593

void Pafu_HurtByShot(_D3_OBJECT *oh,long d)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  short Fx;
  M_OBJECT *obj;
  _PLAYER *pl;
  
  pl = (_PLAYER *)TaskCurrent->local;
  uVar1 = (pl->m_obj).shadow.clut;
  uVar2 = M_rand();
  uVar2 = uVar2 & 3;
  if (uVar2 == 1) {
    Fx = 2;
  }
  else {
    if (uVar2 < 2) {
      Fx = 1;
      if (uVar2 != 0) goto LAB_8003dba4;
    }
    else {
      Fx = 3;
      if (uVar2 != 2) goto LAB_8003dba4;
    }
  }
  Fx_Play(Fx,(char)pl + ',');
LAB_8003dba4:
  iVar3 = DeltaDirection(d,(int)(pl->obj).rot.vz);
  if (iVar3 < 0) {
    iVar3 = -iVar3;
  }
  obj = (M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data;
  if (iVar3 < 0x400) {
    Manim_SetAnim(obj,0x33);
    Fx = 1;
  }
  else {
    Manim_SetAnim(obj,0x30);
    Fx = -1;
  }
  Pafj_ExecJpDown(Fx);
  if (((uVar1 & 0x1000) != 0) && (((pl->m_obj).dummy1 & PJOY_ESQUIVE) != 0)) {
    Pl_ForceAction(pl,0x12,0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pafu_HurtByPics(struct _D3_OBJECT *ot /*$s2*/)
 // line 320, offset 0x8003dc34
	/* begin block 1 */
		// Start line: 321
		// Start offset: 0x8003DC34
		// Variables:
	// 		struct _PLAYER *pl; // $s0
	/* end block 1 */
	// End offset: 0x8003DC34
	// End Line: 321

	/* begin block 2 */
		// Start line: 684
	/* end block 2 */
	// End Line: 685

void Pafu_HurtByPics(_D3_OBJECT *ot)

{
  char pos;
  undefined4 uVar1;
  _PLAYER *pl;
  
  pl = (_PLAYER *)TaskCurrent->local;
  pos = (char)pl + ',';
  (pl->obj).hit_points = 0;
  Fx_Play(7,pos);
  Manim_SetAnim((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data,1);
  Boxes_GetCenter(ot,pos);
  uVar1 = *(undefined4 *)&(pl->obj).pos.vz;
  *(undefined4 *)&(pl->obj).last_pos = *(undefined4 *)&(pl->obj).pos;
  *(undefined4 *)&(pl->obj).last_pos.vz = uVar1;
  Pl_ForceAction(pl,0x10,2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pafu_HurtByExplosion(struct _D3_OBJECT *oh /*$s2*/, long d /*$s3*/)
 // line 340, offset 0x8003dccc
	/* begin block 1 */
		// Start line: 341
		// Start offset: 0x8003DCCC
		// Variables:
	// 		struct _PLAYER *pl; // $s0
	// 		long txy; // $s1
	// 		long side; // $s2
	// 		long anm; // $a1
	/* end block 1 */
	// End offset: 0x8003DDF8
	// End Line: 380

	/* begin block 2 */
		// Start line: 727
	/* end block 2 */
	// End Line: 728

void Pafu_HurtByExplosion(_D3_OBJECT *oh,long d)

{
  char cVar1;
  long Anim;
  int iVar2;
  _PLAYER *pl;
  undefined2 uVar3;
  short sxy;
  ushort uVar4;
  uint uVar5;
  
  uVar4 = (ushort)d;
  cVar1 = *(char *)((int)&oh[1].pos.vx + 1);
  pl = (_PLAYER *)TaskCurrent->local;
  if (cVar1 == -4) {
    uVar3 = 0x200;
  }
  else {
    if (cVar1 < -3) {
      uVar3 = 0x100;
      if (cVar1 == -5) {
        uVar3 = 0x280;
      }
    }
    else {
      uVar3 = 0x100;
      if (cVar1 == -3) {
        uVar3 = 0x180;
      }
    }
  }
  Anim = Distance3D((int)(pl->obj).pos.vx,(int)(pl->obj).pos.vy,(int)(pl->obj).pos.vz,
                    (int)(oh->pos).vx,(int)(oh->pos).vy,(int)(oh->pos).vz);
  if (0x1e0 - Anim < 1) {
    iVar2 = 0;
  }
  else {
    iVar2 = (0x1e0 - Anim) / 10;
  }
  uVar5 = iVar2 * (uint)oh->hit_power;
  Pl_ReduceHitPoints(pl,(short)((uVar5 + (uVar5 >> 0x1f)) * 0x8000 >> 0x10));
  iVar2 = DeltaDirection(d,(int)(pl->obj).rot.vz);
  if (iVar2 < 0) {
    iVar2 = -iVar2;
  }
  Anim = 0x31;
  if (iVar2 < 0x400) {
    sxy = 1;
  }
  else {
    Anim = 0x60;
    sxy = -1;
    uVar4 = uVar4 + 0x800 & 0xfff;
  }
  (pl->obj).rot.vz = uVar4;
  Manim_SetAnim((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data,Anim);
  uVar4 = *(ushort *)&(pl->m_obj).shadow.u0;
  *(undefined2 *)((int)&(pl->m_obj).Env.Obj.n_primitive + 2) = uVar3;
  *(undefined2 *)&(pl->m_obj).Env.Obj.scale = uVar3;
  (pl->m_obj).shadow.tpage = 0;
  *(ushort *)&(pl->m_obj).shadow.u0 = uVar4 | 0x80;
  Fx_Play(4,(char)pl + ',');
  Pafj_ExecJpDown(sxy);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pafu_HurtByKick(struct _D3_OBJECT *oh /*$a0*/, long d /*$a1*/)
 // line 393, offset 0x8003de4c
	/* begin block 1 */
		// Start line: 394
		// Start offset: 0x8003DE4C
		// Variables:
	// 		struct _PLAYER *pl; // $s0
	// 		long rot; // $a3
	// 		long anm; // $a1
	// 		long snd; // $a0
	/* end block 1 */
	// End offset: 0x8003DEC8
	// End Line: 411

	/* begin block 2 */
		// Start line: 850
	/* end block 2 */
	// End Line: 851

void Pafu_HurtByKick(_D3_OBJECT *oh,long d)

{
  char cVar1;
  uint uVar2;
  short Fx;
  undefined2 in_a3;
  ushort uVar3;
  void *pvVar4;
  
  cVar1 = *(char *)((int)&oh[1].pos.vx + 1);
  pvVar4 = TaskCurrent->local;
  if (cVar1 == -0xe) {
    d = 0x60;
    uVar3 = (oh->rot).vz + 0x800U & 0xfff;
  }
  else {
    if (cVar1 != -0xd) {
      *(undefined2 *)((int)pvVar4 + 0x40) = in_a3;
      goto LAB_8003dea8;
    }
    d = 0x30;
    uVar3 = *(ushort *)((int)pvVar4 + 0x40);
  }
  *(ushort *)((int)pvVar4 + 0x40) = uVar3;
LAB_8003dea8:
  Manim_SetAnim((M_OBJECT *)((int)pvVar4 + 0xa4),d);
  uVar2 = M_rand();
  Fx = 2;
  if ((uVar2 & 1) != 0) {
    Fx = 1;
  }
  Fx_Play(Fx,(char)pvVar4 + ',');
  Pafj_ExecJpDown(-1);
  return;
}





