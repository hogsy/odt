#include "THISDUST.H"
#include "D3.H"


// decompiled code
// original method signature: 
// void /*$ra*/ D3_SetCollBits(struct _D3_OBJECT *o /*$a0*/, long bits /*$a1*/)
 // line 34, offset 0x8001a19c
	/* begin block 1 */
		// Start line: 69
	/* end block 1 */
	// End Line: 70

void D3_SetCollBits(_D3_OBJECT *o,long bits)

{
  undefined4 uVar1;
  
  if (((bits & 8U) != 0) && (((int)o->collision_mode & bits) == 0)) {
    uVar1 = *(undefined4 *)&(o->pos).vz;
    *(undefined4 *)&o->last_pos = *(undefined4 *)&o->pos;
    *(undefined4 *)&(o->last_pos).vz = uVar1;
  }
  if (((bits & 0x80U) != 0) && (((int)o->collision_mode & bits) == 0)) {
    o[1].collision_state = 0;
  }
  o->collision_mode = o->collision_mode | (ushort)bits;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ D3_ClearCollBits(struct _D3_OBJECT *o /*$a0*/, long bits /*$a1*/)
 // line 46, offset 0x8001a210
	/* begin block 1 */
		// Start line: 93
	/* end block 1 */
	// End Line: 94

void D3_ClearCollBits(_D3_OBJECT *o,long bits)

{
  undefined4 uVar1;
  
  if ((bits & 8U) != 0) {
    uVar1 = *(undefined4 *)&(o->pos).vz;
    *(undefined4 *)&o->last_pos = *(undefined4 *)&o->pos;
    *(undefined4 *)&(o->last_pos).vz = uVar1;
  }
  o->collision_mode = o->collision_mode & ~(ushort)bits;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ D3_SetBox(struct _D3_OBJECT *o /*$a0*/, long nx /*$a1*/, long ny /*$a2*/, long nz /*$a3*/, long xx /*stack 16*/, long xy /*stack 20*/, long xz /*stack 24*/)
 // line 55, offset 0x8001a250
	/* begin block 1 */
		// Start line: 110
	/* end block 1 */
	// End Line: 111

void D3_SetBox(_D3_OBJECT *o,long nx,long ny,long nz,long xx,long xy,long xz)

{
  short sVar1;
  undefined2 uVar2;
  short sVar3;
  short sVar4;
  
  sVar1 = (short)nx;
  (o->b_box).vx = sVar1;
  sVar4 = (short)nz;
  (o->b_box).vz = sVar4;
  *(short *)&o->b_hurt = sVar4;
  sVar3 = (short)ny;
  *(short *)((int)&o->b_sunk + 2) = sVar3;
  *(short *)&o->difficulty = sVar4;
  o->comp_opt2 = sVar1;
  o->comp_opt3 = sVar3;
  *(short *)&o->comp_opt4 = sVar4;
  *(short *)&o[1].next = sVar1;
  *(short *)((int)&o[1].list + 2) = sVar3;
  o[1].index = sVar1;
  o[1].display_mode = sVar3;
  sVar1 = (short)xy;
  (o->b_box).vy = sVar1;
  uVar2 = (undefined2)xx;
  *(undefined2 *)&o->b_step = uVar2;
  *(short *)((int)&o->b_step + 2) = sVar1;
  *(undefined2 *)&o->b_sunk = uVar2;
  *(short *)((int)&o[1].next + 2) = sVar1;
  sVar3 = (short)xz;
  *(short *)&o[1].prec = sVar3;
  *(undefined2 *)&o[1].child = uVar2;
  *(short *)((int)&o[1].child + 2) = sVar1;
  *(short *)&o[1].father = sVar3;
  *(undefined2 *)&o[1].list = uVar2;
  *(short *)&o[1].handle = sVar3;
  o[1].collision_mode = sVar3;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ D3_SetLowBox(struct _D3_OBJECT *o /*$a0*/, long nx /*$a1*/, long ny /*$a2*/, long xx /*$a3*/, long xy /*stack 16*/, long z /*stack 20*/)
 // line 68, offset 0x8001a2c0
	/* begin block 1 */
		// Start line: 143
	/* end block 1 */
	// End Line: 144

void D3_SetLowBox(_D3_OBJECT *o,long nx,long ny,long xx,long xy,long z)

{
  short sVar1;
  
  (o->b_box).vx = (short)nx;
  *(short *)&o->b_step = (short)xx;
  *(short *)&o->b_sunk = (short)xx;
  *(short *)((int)&o->b_sunk + 2) = (short)ny;
  o->comp_opt2 = (short)nx;
  o->comp_opt3 = (short)ny;
  (o->b_box).vy = (short)xy;
  sVar1 = (short)z;
  (o->b_box).vz = sVar1;
  *(short *)((int)&o->b_step + 2) = (short)xy;
  *(short *)&o->b_hurt = sVar1;
  *(short *)&o->difficulty = sVar1;
  *(short *)&o->comp_opt4 = sVar1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ D3_SetHighBox(struct _D3_OBJECT *o /*$a0*/, long nx /*$a1*/, long ny /*$a2*/, long xx /*$a3*/, long xy /*stack 16*/, long z /*stack 20*/)
 // line 76, offset 0x8001a2fc
	/* begin block 1 */
		// Start line: 162
	/* end block 1 */
	// End Line: 163

void D3_SetHighBox(_D3_OBJECT *o,long nx,long ny,long xx,long xy,long z)

{
  short sVar1;
  
  *(short *)&o[1].next = (short)nx;
  *(short *)&o[1].child = (short)xx;
  *(short *)&o[1].list = (short)xx;
  *(short *)((int)&o[1].list + 2) = (short)ny;
  o[1].index = (short)nx;
  o[1].display_mode = (short)ny;
  *(undefined2 *)((int)&o[1].next + 2) = (short)xy;
  sVar1 = (short)z;
  *(short *)&o[1].prec = sVar1;
  *(undefined2 *)((int)&o[1].child + 2) = (short)xy;
  *(short *)&o[1].father = sVar1;
  *(short *)&o[1].handle = sVar1;
  o[1].collision_mode = sVar1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ D3_SetHighBoxZ(struct _D3_OBJECT *o /*$a0*/, long z /*$a1*/)
 // line 86, offset 0x8001a338
	/* begin block 1 */
		// Start line: 186
	/* end block 1 */
	// End Line: 187

void D3_SetHighBoxZ(_D3_OBJECT *o,long z)

{
  short sVar1;
  
  sVar1 = (short)z;
  *(short *)&o[1].prec = sVar1;
  *(short *)&o[1].father = sVar1;
  *(short *)&o[1].handle = sVar1;
  o[1].collision_mode = sVar1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ D3_SetLowBoxZ(struct _D3_OBJECT *o /*$a0*/, long z /*$a1*/)
 // line 95, offset 0x8001a34c
	/* begin block 1 */
		// Start line: 204
	/* end block 1 */
	// End Line: 205

void D3_SetLowBoxZ(_D3_OBJECT *o,long z)

{
  short sVar1;
  
  sVar1 = (short)z;
  (o->b_box).vz = sVar1;
  *(short *)&o->b_hurt = sVar1;
  *(short *)&o->difficulty = sVar1;
  *(short *)&o->comp_opt4 = sVar1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ D3_InsertObject(struct _D3_OBJECT *obj /*$a0*/, struct _D3_OBJECT **list /*$a1*/)
 // line 110, offset 0x8001a360
	/* begin block 1 */
		// Start line: 112
		// Start offset: 0x8001A360
		// Variables:
	// 		struct _D3_OBJECT *n; // $v1
	/* end block 1 */
	// End offset: 0x8001A38C
	// End Line: 127

	/* begin block 2 */
		// Start line: 236
	/* end block 2 */
	// End Line: 237

void D3_InsertObject(_D3_OBJECT *obj,_D3_OBJECT **list)

{
  _D3_OBJECT *p_Var1;
  
  p_Var1 = *list;
  *list = obj;
  obj->list = list;
  obj->index = -1;
  obj->prec = (_D3_OBJECT *)0x0;
  obj->child = (_D3_OBJECT *)0x0;
  obj->father = (_D3_OBJECT *)0x0;
  obj->next = p_Var1;
  if (p_Var1 != (_D3_OBJECT *)0x0) {
    p_Var1->prec = obj;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ D3_DeleteObject(struct _D3_OBJECT *obj /*$s0*/)
 // line 130, offset 0x8001a394
	/* begin block 1 */
		// Start line: 131
		// Start offset: 0x8001A394
		// Variables:
	// 		struct _D3_OBJECT *n; // $a0
	// 		struct _D3_OBJECT *p; // $v0
	// 		struct _D3_OBJECT *f; // $v1
	/* end block 1 */
	// End offset: 0x8001A498
	// End Line: 169

	/* begin block 2 */
		// Start line: 276
	/* end block 2 */
	// End Line: 277

/* WARNING: Type propagation algorithm not settling */

void D3_DeleteObject(_D3_OBJECT *obj)

{
  _D3_OBJECT *p_Var1;
  _D3_OBJECT *p_Var2;
  TASK *t;
  _D3_OBJECT *p_Var3;
  
  p_Var1 = obj->child;
  while (p_Var1 != (_D3_OBJECT *)0x0) {
    D3_DeleteObject(obj->child);
    p_Var1 = obj->child;
  }
  Zone_DeleteObject(obj);
  t = obj->handle;
  if ((t != (TASK *)0x0) && ((obj->collision_mode & 0x1000U) == 0)) {
    if (t != TaskCurrent) {
      Task_Kill(t);
    }
    obj->handle = (TASK *)0x0;
  }
  p_Var2 = obj->father;
  p_Var3 = obj->next;
  p_Var1 = obj->prec;
  if (p_Var3 != (_D3_OBJECT *)0x0) {
    p_Var3->prec = p_Var1;
  }
  if (p_Var1 != (_D3_OBJECT *)0x0) {
    p_Var1->next = p_Var3;
  }
  if ((p_Var2 != (_D3_OBJECT *)0x0) && (p_Var2->child == obj)) {
    p_Var2->child = p_Var3;
  }
  p_Var1 = (_D3_OBJECT *)obj->list;
  if ((p_Var1 != (_D3_OBJECT *)0x0) && (p_Var1->next == obj)) {
    p_Var1->next = p_Var3;
  }
  if (-1 < obj->index) {
    Pvl_SetStateBits(obj,0x80);
  }
  obj->collision_state = obj->collision_state | 4;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ D3_ExplodeObject(struct _D3_OBJECT *obj /*$s0*/)
 // line 173, offset 0x8001a4b8
	/* begin block 1 */
		// Start line: 362
	/* end block 1 */
	// End Line: 363

void D3_ExplodeObject(_D3_OBJECT *obj)

{
  SFX_ExplodeObject(obj);
  if ((obj->child == (_D3_OBJECT *)0x0) || (*(char *)((int)&obj->child[1].pos.vx + 1) != '\x03')) {
    if (((obj->collision_mode & 0x1000U) == 0) && (obj->comp_opt1 != 4)) {
      D3_DeleteObject(obj);
    }
  }
  else {
    Pvl_SetStateBits(obj,0x80);
    obj->display_mode = obj->display_mode & 0xffef;
    D3_ClearCollBits(obj,1);
    obj->collision_state = obj->collision_state | 4;
    D3_SetBonuses(obj,1,obj);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ D3_MoveWithObject(struct _D3_OBJECT *ot /*$s5*/, struct _D3_OBJECT *oc /*$s4*/)
 // line 203, offset 0x8001a56c
	/* begin block 1 */
		// Start line: 204
		// Start offset: 0x8001A56C
		// Variables:
	// 		long dx; // $s1
	// 		long dy; // $s0
	// 		long r; // $s3
	// 		long rc; // $s2
	// 		long rs; // $v0
	/* end block 1 */
	// End offset: 0x8001A6D8
	// End Line: 239

	/* begin block 2 */
		// Start line: 428
	/* end block 2 */
	// End Line: 429

void D3_MoveWithObject(_D3_OBJECT *ot,_D3_OBJECT *oc)

{
  short sVar1;
  short sVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  if (((oc->collision_mode & 4U) != 0) &&
     (iVar4 = (int)(oc->rot).pad, iVar7 = (int)(oc->rot).vz, uVar8 = iVar7 - iVar4, iVar4 != iVar7))
  {
    iVar6 = (int)(ot->pos).vx - (int)(oc->last_pos).vx;
    iVar5 = (int)(ot->pos).vy - (int)(oc->last_pos).vy;
    iVar4 = rcos(uVar8);
    iVar7 = rsin(uVar8);
    sVar1 = (ot->rot).vz;
    (ot->pos).vx = (oc->last_pos).vx + (short)((iVar4 * iVar6 - iVar7 * iVar5) + 0x800 >> 0xc);
    sVar2 = (oc->last_pos).vy;
    (ot->rot).vz = sVar1 + (short)uVar8;
    (ot->pos).vy = sVar2 + (short)(iVar7 * iVar6 + iVar4 * iVar5 + 0x800 >> 0xc);
  }
  (ot->pos).vx = (ot->pos).vx + ((oc->pos).vx - (oc->last_pos).vx);
  (ot->pos).vy = (ot->pos).vy + ((oc->pos).vy - (oc->last_pos).vy);
  uVar3 = ot->collision_mode;
  (ot->pos).vz = (ot->pos).vz + ((oc->pos).vz - (oc->last_pos).vz);
  if (((uVar3 & 0x1000) != 0) &&
     (uVar3 = oc->collision_state, oc->collision_state = uVar3 | 0x10, (uVar3 & 0x20) == 0)) {
    uVar3 = oc->collision_state;
    *(_D3_OBJECT **)&oc[1].color = ot;
    oc->collision_state = uVar3 | 0x100;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ D3_MoveList(struct _D3_OBJECT *obj /*$s0*/, struct D3_7fake *spd /*$s1*/)
 // line 242, offset 0x8001a6fc
	/* begin block 1 */
		// Start line: 524
	/* end block 1 */
	// End Line: 525

void D3_MoveList(_D3_OBJECT *obj,undefined spd)

{
  undefined3 in_register_00000015;
  short *psVar1;
  
  psVar1 = (short *)CONCAT31(in_register_00000015,spd);
  if (obj != (_D3_OBJECT *)0x0) {
    do {
      if (obj->child != (_D3_OBJECT *)0x0) {
        D3_MoveList(obj->child,spd);
      }
      if ((obj->display_mode & 1U) != 0) {
        (obj->pos).vx = (obj->pos).vx + *psVar1;
        (obj->pos).vy = (obj->pos).vy + psVar1[1];
        (obj->pos).vz = (obj->pos).vz + psVar1[2];
      }
      obj = obj->next;
    } while (obj != (_D3_OBJECT *)0x0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ D3_RotList(struct _D3_OBJECT *obj /*$s0*/, struct D3_7fake *rot /*$s1*/)
 // line 255, offset 0x8001a7a4
	/* begin block 1 */
		// Start line: 556
	/* end block 1 */
	// End Line: 557

void D3_RotList(_D3_OBJECT *obj,undefined rot)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined3 in_register_00000015;
  short *psVar4;
  
  psVar4 = (short *)CONCAT31(in_register_00000015,rot);
  if (obj != (_D3_OBJECT *)0x0) {
    do {
      if (obj->child != (_D3_OBJECT *)0x0) {
        D3_RotList(obj->child,rot);
      }
      if ((obj->display_mode & 2U) != 0) {
        iVar2 = (int)(obj->rot).vx + (int)*psVar4;
        iVar3 = iVar2 + 0x1000;
        iVar1 = iVar3;
        if (iVar3 < 0) {
          iVar1 = iVar2 + 0x1fff;
        }
        (obj->rot).vx = (short)iVar3 + (short)(iVar1 >> 0xc) * -0x1000;
        iVar2 = (int)(obj->rot).vy + (int)psVar4[1];
        iVar3 = iVar2 + 0x1000;
        iVar1 = iVar3;
        if (iVar3 < 0) {
          iVar1 = iVar2 + 0x1fff;
        }
        (obj->rot).vy = (short)iVar3 + (short)(iVar1 >> 0xc) * -0x1000;
        iVar2 = (int)(obj->rot).vz + (int)psVar4[2];
        iVar3 = iVar2 + 0x1000;
        iVar1 = iVar3;
        if (iVar3 < 0) {
          iVar1 = iVar2 + 0x1fff;
        }
        (obj->rot).vz = (short)iVar3 + (short)(iVar1 >> 0xc) * -0x1000;
      }
      obj = obj->next;
    } while (obj != (_D3_OBJECT *)0x0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ D3_ExplodeList(struct _D3_OBJECT *obj /*$s0*/)
 // line 272, offset 0x8001a8a0
	/* begin block 1 */
		// Start line: 601
	/* end block 1 */
	// End Line: 602

void D3_ExplodeList(_D3_OBJECT *obj)

{
  if (obj != (_D3_OBJECT *)0x0) {
    do {
      if (obj->child != (_D3_OBJECT *)0x0) {
        D3_ExplodeList(obj->child);
      }
      D3_ExplodeObject(obj);
      obj = obj->next;
    } while (obj != (_D3_OBJECT *)0x0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ D3_SetColorList(struct _D3_OBJECT *obj /*$s0*/, long color /*$s1*/)
 // line 284, offset 0x8001a8f4
	/* begin block 1 */
		// Start line: 630
	/* end block 1 */
	// End Line: 631

void D3_SetColorList(_D3_OBJECT *obj,long color)

{
  if (obj != (_D3_OBJECT *)0x0) {
    do {
      if (obj->child != (_D3_OBJECT *)0x0) {
        D3_SetColorList(obj->child,color);
      }
      obj->color = color;
      obj = obj->next;
    } while (obj != (_D3_OBJECT *)0x0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ D3_SetDisplayBitsList(struct _D3_OBJECT *obj /*$s0*/, long mask /*$s1*/)
 // line 296, offset 0x8001a950
	/* begin block 1 */
		// Start line: 659
	/* end block 1 */
	// End Line: 660

void D3_SetDisplayBitsList(_D3_OBJECT *obj,long mask)

{
  if (obj != (_D3_OBJECT *)0x0) {
    do {
      if (obj->child != (_D3_OBJECT *)0x0) {
        D3_SetDisplayBitsList(obj->child,mask);
      }
      obj->display_mode = obj->display_mode | (ushort)mask;
      obj = obj->next;
    } while (obj != (_D3_OBJECT *)0x0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ D3_ClearDisplayBitsList(struct _D3_OBJECT *obj /*$s0*/, long mask /*$s1*/)
 // line 308, offset 0x8001a9b8
	/* begin block 1 */
		// Start line: 688
	/* end block 1 */
	// End Line: 689

void D3_ClearDisplayBitsList(_D3_OBJECT *obj,long mask)

{
  if (obj != (_D3_OBJECT *)0x0) {
    do {
      if (obj->child != (_D3_OBJECT *)0x0) {
        D3_ClearDisplayBitsList(obj->child,mask);
      }
      obj->display_mode = obj->display_mode & ~(ushort)mask;
      obj = obj->next;
    } while (obj != (_D3_OBJECT *)0x0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ D3_SetCollBitsList(struct _D3_OBJECT *obj /*$s0*/, long mask /*$s1*/)
 // line 320, offset 0x8001aa2c
	/* begin block 1 */
		// Start line: 717
	/* end block 1 */
	// End Line: 718

void D3_SetCollBitsList(_D3_OBJECT *obj,long mask)

{
  if (obj != (_D3_OBJECT *)0x0) {
    do {
      if (obj->child != (_D3_OBJECT *)0x0) {
        D3_SetCollBitsList(obj->child,mask);
      }
      D3_SetCollBits(obj,mask);
      obj = obj->next;
    } while (obj != (_D3_OBJECT *)0x0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ D3_ClearCollBitsList(struct _D3_OBJECT *obj /*$s0*/, long mask /*$s1*/)
 // line 332, offset 0x8001aa90
	/* begin block 1 */
		// Start line: 746
	/* end block 1 */
	// End Line: 747

void D3_ClearCollBitsList(_D3_OBJECT *obj,long mask)

{
  if (obj != (_D3_OBJECT *)0x0) {
    do {
      if (obj->child != (_D3_OBJECT *)0x0) {
        D3_ClearCollBitsList(obj->child,mask);
      }
      D3_ClearCollBits(obj,mask);
      obj = obj->next;
    } while (obj != (_D3_OBJECT *)0x0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ D3_StopMotion(struct _D3_OBJECT *obj /*$s0*/)
 // line 350, offset 0x8001aaf4
	/* begin block 1 */
		// Start line: 787
	/* end block 1 */
	// End Line: 788

void D3_StopMotion(_D3_OBJECT *obj)

{
  if (obj != (_D3_OBJECT *)0x0) {
    do {
      if (obj->child != (_D3_OBJECT *)0x0) {
        D3_StopMotion(obj->child);
      }
      if ((obj->display_mode & 0x40U) != 0) {
        *(ushort *)((int)obj->description + 0x28) =
             *(ushort *)((int)obj->description + 0x28) & 0xfffe;
      }
      obj = obj->next;
    } while (obj != (_D3_OBJECT *)0x0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ D3_RunMotion(struct _D3_OBJECT *obj /*$s0*/)
 // line 363, offset 0x8001ab78
	/* begin block 1 */
		// Start line: 819
	/* end block 1 */
	// End Line: 820

void D3_RunMotion(_D3_OBJECT *obj)

{
  if (obj != (_D3_OBJECT *)0x0) {
    do {
      if (obj->child != (_D3_OBJECT *)0x0) {
        D3_RunMotion(obj->child);
      }
      if ((obj->display_mode & 0x40U) != 0) {
        *(ushort *)((int)obj->description + 0x28) = *(ushort *)((int)obj->description + 0x28) | 1;
      }
      obj = obj->next;
    } while (obj != (_D3_OBJECT *)0x0);
  }
  return;
}



// decompiled code
// original method signature: 
// struct _D3_OBJECT * /*$ra*/ D3_SeekDangerousObject(struct _D3_OBJECT *ot /*$s2*/, struct _D3_OBJECT *ol /*$s0*/, long dtmax /*$s3*/, long drmax /*$s6*/, long drdanger /*stack 16*/)
 // line 382, offset 0x8001abf0
	/* begin block 1 */
		// Start line: 383
		// Start offset: 0x8001ABF0
		// Variables:
	// 		struct _D3_OBJECT *or; // $s4
	// 		long dt; // $s1
	/* end block 1 */
	// End offset: 0x8001AD08
	// End Line: 413

	/* begin block 2 */
		// Start line: 863
	/* end block 2 */
	// End Line: 864

_D3_OBJECT *
D3_SeekDangerousObject(_D3_OBJECT *ot,_D3_OBJECT *ol,long dtmax,long drmax,long drdanger)

{
  long d2;
  int iVar1;
  long d1;
  _D3_OBJECT *p_Var2;
  
  p_Var2 = (_D3_OBJECT *)0x0;
  if (ol != (_D3_OBJECT *)0x0) {
    do {
      if (*(char *)((int)&ol[1].pos.vx + 1) != -8) {
        d2 = Direction((int)(ol->pos).vx - (int)(ot->pos).vx,(int)(ol->pos).vy - (int)(ot->pos).vy);
        iVar1 = DeltaDirection((int)(ot->rot).vz,d2);
        if (iVar1 < 0) {
          iVar1 = -iVar1;
        }
        if (iVar1 < drmax) {
          d2 = Distance2D((int)(ot->pos).vx,(int)(ot->pos).vy,(int)(ol->pos).vx,(int)(ol->pos).vy);
          if ((d2 < dtmax) && (100 < d2)) {
            d1 = Direction((int)(ot->pos).vx - (int)(ol->pos).vx,
                           (int)(ot->pos).vy - (int)(ol->pos).vy);
            iVar1 = DeltaDirection(d1,(int)(ol->rot).vz);
            if (iVar1 < 0) {
              iVar1 = -iVar1;
            }
            if (iVar1 < drdanger) {
              dtmax = d2;
              p_Var2 = ol;
            }
          }
        }
      }
      ol = ol->next;
    } while (ol != (_D3_OBJECT *)0x0);
  }
  return p_Var2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ D3_IsObjectLooker(struct _D3_OBJECT *ot /*$s0*/, struct _D3_OBJECT *obj /*$s1*/)
 // line 417, offset 0x8001ad34
	/* begin block 1 */
		// Start line: 418
		// Start offset: 0x8001AD34
		// Variables:
	// 		long d; // $s0
	// 		long dist; // $a0
	/* end block 1 */
	// End offset: 0x8001ADF0
	// End Line: 434

	/* begin block 2 */
		// Start line: 957
	/* end block 2 */
	// End Line: 958

void D3_IsObjectLooker(_D3_OBJECT *ot,_D3_OBJECT *obj)

{
  long d1;
  int iVar1;
  
  if ((((int)obj->collision_mode & seek_mask) == seek_mask) && ((obj->collision_state & 0x80U) != 0)
     ) {
    d1 = Direction((int)(obj->pos).vx - (int)(ot->pos).vx,(int)(obj->pos).vy - (int)(ot->pos).vy);
    iVar1 = DeltaDirection(d1,(int)(ot->rot).vz);
    if (iVar1 < 0) {
      iVar1 = -iVar1;
    }
    d1 = Distance2D((int)(ot->pos).vx,(int)(ot->pos).vy,(int)(obj->pos).vx,(int)(obj->pos).vy);
    if ((iVar1 < seek_max) && (d1 < seek_submax)) {
      seek_max = iVar1;
      seek_object = obj;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ D3_IsObjectCloser(struct _D3_OBJECT *ot /*$a2*/, struct _D3_OBJECT *obj /*$s0*/)
 // line 437, offset 0x8001ae04
	/* begin block 1 */
		// Start line: 438
		// Start offset: 0x8001AE04
		// Variables:
	// 		long d; // $v0
	/* end block 1 */
	// End offset: 0x8001AE74
	// End Line: 451

	/* begin block 2 */
		// Start line: 999
	/* end block 2 */
	// End Line: 1000

void D3_IsObjectCloser(_D3_OBJECT *ot,_D3_OBJECT *obj)

{
  long lVar1;
  
  if (((((int)obj->collision_mode & seek_mask) == seek_mask) &&
      ((obj->collision_state & 0x80U) != 0)) &&
     (lVar1 = Distance2D((int)(ot->pos).vx,(int)(ot->pos).vy,(int)(obj->pos).vx,(int)(obj->pos).vy),
     lVar1 < seek_max)) {
    seek_max = lVar1;
    seek_object = obj;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ D3_IsFriendCloser(struct _D3_OBJECT *ot /*$a2*/, struct _D3_OBJECT *obj /*$s0*/)
 // line 454, offset 0x8001ae84
	/* begin block 1 */
		// Start line: 455
		// Start offset: 0x8001AE84
		// Variables:
	// 		long d; // $v0
	/* end block 1 */
	// End offset: 0x8001AEE0
	// End Line: 468

	/* begin block 2 */
		// Start line: 1033
	/* end block 2 */
	// End Line: 1034

void D3_IsFriendCloser(_D3_OBJECT *ot,_D3_OBJECT *obj)

{
  long lVar1;
  
  if ((*(char *)((int)&obj[1].pos.vx + 1) == *(char *)((int)&ot[1].pos.vx + 1)) &&
     (lVar1 = Distance2D((int)(ot->pos).vx,(int)(ot->pos).vy,(int)(obj->pos).vx,(int)(obj->pos).vy),
     lVar1 < seek_max)) {
    seek_max = lVar1;
    seek_object = obj;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ D3_IsObjectGrenade(struct _D3_OBJECT *ot /*$v1*/, struct _D3_OBJECT *obj /*$s0*/)
 // line 472, offset 0x8001aef0
	/* begin block 1 */
		// Start line: 473
		// Start offset: 0x8001AEF0
		// Variables:
	// 		long d; // $v1
	/* end block 1 */
	// End offset: 0x8001AF4C
	// End Line: 486

	/* begin block 2 */
		// Start line: 1069
	/* end block 2 */
	// End Line: 1070

void D3_IsObjectGrenade(_D3_OBJECT *ot,_D3_OBJECT *obj)

{
  long lVar1;
  
  if (((byte)(*(char *)((int)&obj[1].pos.vx + 1) + 0xcU) < 2) &&
     (lVar1 = Distance2D((int)(ot->pos).vx,(int)(ot->pos).vy,(int)(obj->pos).vx,(int)(obj->pos).vy),
     lVar1 < 300)) {
    seek_max = lVar1;
    seek_object = obj;
  }
  return;
}



// decompiled code
// original method signature: 
// struct _D3_OBJECT * /*$ra*/ D3_SeekClosestGrenade(struct _D3_OBJECT *ot /*$a0*/)
 // line 488, offset 0x8001af5c
	/* begin block 1 */
		// Start line: 1101
	/* end block 1 */
	// End Line: 1102

_D3_OBJECT * D3_SeekClosestGrenade(_D3_OBJECT *ot)

{
  seek_object = (_D3_OBJECT *)0x0;
  seek_mask = 0;
  D3_SeekInList(ot,Pvl_PlayerShots,D3_IsObjectGrenade);
  return seek_object;
}



// decompiled code
// original method signature: 
// void /*$ra*/ D3_SeekInList(struct _D3_OBJECT *ot /*$s1*/, struct _D3_OBJECT *list /*$s0*/, TDRFuncPtr_D3_SeekInList2test test /*$s2*/)
 // line 502, offset 0x8001af94
	/* begin block 1 */
		// Start line: 1135
	/* end block 1 */
	// End Line: 1136

void D3_SeekInList(_D3_OBJECT *ot,_D3_OBJECT *list,TDRFuncPtr_D3_SeekInList2test test)

{
  if (list != (_D3_OBJECT *)0x0) {
    do {
      if (ot != list) {
        if (list->child != (_D3_OBJECT *)0x0) {
          D3_SeekInList(ot,list->child,test);
        }
        (*test)(ot,list);
      }
      list = list->next;
    } while (list != (_D3_OBJECT *)0x0);
  }
  return;
}



// decompiled code
// original method signature: 
// struct _D3_OBJECT * /*$ra*/ D3_SeekDistTarget(struct _D3_OBJECT *ot /*$a0*/, long dist_maxi /*$a1*/, long mask /*$a2*/)
 // line 517, offset 0x8001b00c
	/* begin block 1 */
		// Start line: 1173
	/* end block 1 */
	// End Line: 1174

_D3_OBJECT * D3_SeekDistTarget(_D3_OBJECT *ot,long dist_maxi,long mask)

{
  seek_object = (_D3_OBJECT *)0x0;
  seek_max = dist_maxi;
  seek_mask = mask;
  D3_SeekInList(ot,Pvl_GlobalObjects,D3_IsObjectCloser);
  return seek_object;
}



// decompiled code
// original method signature: 
// struct _D3_OBJECT * /*$ra*/ D3_SeekLookTarget(struct _D3_OBJECT *ot /*$a0*/, long dir_max /*$a1*/, long dist_max /*$a2*/, long mask /*$a3*/)
 // line 531, offset 0x8001b048
	/* begin block 1 */
		// Start line: 1212
	/* end block 1 */
	// End Line: 1213

_D3_OBJECT * D3_SeekLookTarget(_D3_OBJECT *ot,long dir_max,long dist_max,long mask)

{
  seek_object = (_D3_OBJECT *)0x0;
  seek_submax = dist_max;
  if (dist_max == 0) {
    seek_submax = 0x7fff;
  }
  seek_max = dir_max;
  seek_mask = mask;
  D3_SeekInList(ot,Pvl_GlobalObjects,D3_IsObjectLooker);
  return seek_object;
}



// decompiled code
// original method signature: 
// struct _D3_OBJECT * /*$ra*/ D3_SeekDistFriend(struct _D3_OBJECT *ot /*$a0*/, long dist_maxi /*$a1*/)
 // line 547, offset 0x8001b094
	/* begin block 1 */
		// Start line: 1244
	/* end block 1 */
	// End Line: 1245

_D3_OBJECT * D3_SeekDistFriend(_D3_OBJECT *ot,long dist_maxi)

{
  seek_object = (_D3_OBJECT *)0x0;
  seek_max = dist_maxi;
  D3_SeekInList(ot,Pvl_GlobalObjects,D3_IsFriendCloser);
  return seek_object;
}



// decompiled code
// original method signature: 
// void /*$ra*/ D3_SetDir(struct _D3_OBJECT *o /*$s0*/, long x /*$a1*/, long y /*$a2*/)
 // line 560, offset 0x8001b0cc
	/* begin block 1 */
		// Start line: 561
		// Start offset: 0x8001B0CC
		// Variables:
	// 		long vz; // $v1
	/* end block 1 */
	// End offset: 0x8001B0FC
	// End Line: 566

	/* begin block 2 */
		// Start line: 1279
	/* end block 2 */
	// End Line: 1280

void D3_SetDir(_D3_OBJECT *o,long x,long y)

{
  long lVar1;
  
  lVar1 = Direction(x,y);
  if (lVar1 != -1) {
    (o->rot).vz = (short)lVar1;
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ D3_GoToDir(struct _D3_OBJECT *o /*$s0*/, long x /*$a1*/, long y /*$a2*/, long speed /*$s1*/)
 // line 569, offset 0x8001b10c
	/* begin block 1 */
		// Start line: 570
		// Start offset: 0x8001B10C
		// Variables:
	// 		long Dir; // $v1
	// 		long Ok; // $v1
	/* end block 1 */
	// End offset: 0x8001B18C
	// End Line: 592

	/* begin block 2 */
		// Start line: 1298
	/* end block 2 */
	// End Line: 1299

long D3_GoToDir(_D3_OBJECT *o,long x,long y,long speed)

{
  short sVar1;
  ushort uVar2;
  long d1;
  
  d1 = Direction(x,y);
  d1 = DeltaDirection(d1,(int)(o->rot).vz);
  if (d1 < -speed) {
    uVar2 = (o->rot).vz - (short)speed;
    d1 = -speed;
  }
  else {
    if (speed < d1) {
      sVar1 = (o->rot).vz;
      d1 = speed;
    }
    else {
      sVar1 = (o->rot).vz;
    }
    uVar2 = sVar1 + (short)d1;
  }
  (o->rot).vz = uVar2 & 0xfff;
  return d1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ D3_ObjectInScreen(struct _D3_OBJECT *obj /*$s2*/)
 // line 602, offset 0x8001b1a4
	/* begin block 1 */
		// Start line: 603
		// Start offset: 0x8001B1A4
		// Variables:
	// 		struct D3_5fake mr; // stack offset -48
	// 		long z; // $a0
	// 		long ot; // $s1
	/* end block 1 */
	// End offset: 0x8001B574
	// End Line: 653

	/* begin block 2 */
		// Start line: 1369
	/* end block 2 */
	// End Line: 1370

long D3_ObjectInScreen(_D3_OBJECT *obj)

{
  undefined4 in_zero;
  undefined4 in_at;
  long lVar1;
  int iVar2;
  ushort auStack48 [10];
  int local_1c;
  int local_18;
  int local_14;
  
  iVar2 = (uint)(Pvl_File->fog).cd * 100;
  setCopReg(2,in_zero,*(undefined4 *)&obj->pos);
  setCopReg(2,in_at,*(undefined4 *)&(obj->pos).vz);
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
  if (((obj->display_mode & 0x40U) == 0) && ((obj->collision_mode & 4U) != 0)) {
    RotMatrixZYX((short *)&obj->rot,auStack48);
    SetMulMatrix((undefined4 *)&Cam_Matrix,auStack48);
  }
  GtxTmd_RotTransPersN(&obj->b_box,Tmd_2DSpeed,8);
  setCopControlWord(2,0,Cam_Matrix.m[0]._0_4_);
  setCopControlWord(2,0x800,Cam_Matrix.m._4_4_);
  setCopControlWord(2,0x1000,Cam_Matrix.m[1]._2_4_);
  setCopControlWord(2,0x1800,Cam_Matrix.m[2]._0_4_);
  setCopControlWord(2,0x2000,Cam_Matrix._16_4_);
  setCopControlWord(2,0x2800,Cam_Matrix.t[0]);
  setCopControlWord(2,0x3000,Cam_Matrix.t[1]);
  setCopControlWord(2,0x3800,Cam_Matrix.t[2]);
  lVar1 = 0;
  if (((0 < (int)Tmd_2DSpeed->vz + (int)Tmd_2DSpeed[1].vz + (int)Tmd_2DSpeed[2].vz +
            (int)Tmd_2DSpeed[3].vz +
            (int)Tmd_2DSpeed[4].vz + (int)Tmd_2DSpeed[5].vz + (int)Tmd_2DSpeed[6].vz +
            (int)Tmd_2DSpeed[7].vz) &&
      (((((int)Tmd_2DSpeed->vz < iVar2 || ((int)Tmd_2DSpeed[1].vz < iVar2)) ||
        ((int)Tmd_2DSpeed[2].vz < iVar2)) ||
       ((((int)Tmd_2DSpeed[3].vz < iVar2 || ((int)Tmd_2DSpeed[4].vz < iVar2)) ||
        (((int)Tmd_2DSpeed[5].vz < iVar2 ||
         (((int)Tmd_2DSpeed[6].vz < iVar2 || (lVar1 = 0, (int)Tmd_2DSpeed[7].vz < iVar2)))))))))) &&
     ((((-1 < Tmd_2DSpeed->vy ||
        (((-1 < Tmd_2DSpeed[1].vy || (-1 < Tmd_2DSpeed[2].vy)) ||
         (lVar1 = 0, -1 < Tmd_2DSpeed[3].vy)))) &&
       ((((Tmd_2DSpeed[4].vy < Scr_H || (Tmd_2DSpeed[5].vy < Scr_H)) ||
         ((Tmd_2DSpeed[6].vy < Scr_H || (lVar1 = 0, Tmd_2DSpeed[7].vy < Scr_H)))) &&
        ((((-1 < Tmd_2DSpeed->vx || (-1 < Tmd_2DSpeed[1].vx)) || (-1 < Tmd_2DSpeed[2].vx)) ||
         ((((-1 < Tmd_2DSpeed[3].vx || (-1 < Tmd_2DSpeed[4].vx)) || (-1 < Tmd_2DSpeed[5].vx)) ||
          ((-1 < Tmd_2DSpeed[6].vx || (lVar1 = 0, -1 < Tmd_2DSpeed[7].vx)))))))))) &&
      ((((lVar1 = 1, Scr_W <= Tmd_2DSpeed->vx &&
         ((lVar1 = 1, Scr_W <= Tmd_2DSpeed[1].vx && (lVar1 = 1, Scr_W <= Tmd_2DSpeed[2].vx)))) &&
        (lVar1 = 1, Scr_W <= Tmd_2DSpeed[3].vx)) &&
       ((((lVar1 = 1, Scr_W <= Tmd_2DSpeed[4].vx && (lVar1 = 1, Scr_W <= Tmd_2DSpeed[5].vx)) &&
         (lVar1 = 1, Scr_W <= Tmd_2DSpeed[6].vx)) && (lVar1 = 0, Tmd_2DSpeed[7].vx < Scr_W)))))))) {
    lVar1 = 1;
  }
  return lVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ D3_ComputeBBox2D(struct _D3_OBJECT *obj /*$s2*/, long *XMin /*$s3*/, long *YMin /*$s4*/, long *XMax /*$s5*/, long *YMax /*stack 16*/)
 // line 656, offset 0x8001b58c
	/* begin block 1 */
		// Start line: 657
		// Start offset: 0x8001B58C
		// Variables:
	// 		long i; // $a1

		/* begin block 1.1 */
			// Start line: 663
			// Start offset: 0x8001B5D0
			// Variables:
		// 		struct D3_7fake *Box; // $s1
		// 		struct D3_6fake RotVert; // stack offset -88
		// 		struct D3_5fake mr; // stack offset -72

			/* begin block 1.1.1 */
				// Start line: 677
				// Start offset: 0x8001B674
				// Variables:
			// 		long KiSertPas; // stack offset -40
			/* end block 1.1.1 */
			// End offset: 0x8001B71C
			// End Line: 680
		/* end block 1.1 */
		// End offset: 0x8001B730
		// End Line: 683
	/* end block 1 */
	// End offset: 0x8001B7D0
	// End Line: 694

	/* begin block 2 */
		// Start line: 1482
	/* end block 2 */
	// End Line: 1483

void D3_ComputeBBox2D(_D3_OBJECT *obj,long *XMin,long *YMin,long *XMax,long *YMax)

{
  undefined4 in_zero;
  undefined4 in_at;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  _struct_245 *p_Var5;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  
  if ((obj->collision_mode & 4U) == 0) {
    *XMin = (int)obj->comp_opt2 + (int)(obj->pos).vx;
    *YMin = (int)obj->comp_opt3 + (int)(obj->pos).vy;
    *XMax = (int)*(short *)&obj->b_step + (int)(obj->pos).vx;
    *YMax = (int)*(short *)((int)&obj->b_step + 2) + (int)(obj->pos).vy;
  }
  else {
    p_Var5 = &obj->b_box;
    RotMatrixZYX((short *)&obj->rot,(undefined2 *)&local_48);
    setCopControlWord(2,0,local_48);
    setCopControlWord(2,0x800,local_44);
    setCopControlWord(2,0x1000,local_40);
    setCopControlWord(2,0x1800,local_3c);
    setCopControlWord(2,0x2000,local_38);
    setCopControlWord(2,0x2800,(int)(obj->pos).vx);
    setCopControlWord(2,0x3000,(int)(obj->pos).vy);
    setCopControlWord(2,0x3800,(int)(obj->pos).vz);
    iVar4 = 0;
    *XMin = 100000;
    *YMin = 100000;
    *XMax = -100000;
    *YMax = -100000;
    do {
      setCopReg(2,in_zero,*(undefined4 *)p_Var5);
      setCopReg(2,in_at,*(undefined4 *)&p_Var5->vz);
      copFunction(2,0x480012);
      iVar2 = getCopReg(2,0x19);
      iVar3 = getCopReg(2,0x1a);
      getCopReg(2,0x1b);
      getCopControlWord(2,0xf800);
      iVar1 = iVar2;
      if (*XMin < iVar2) {
        iVar1 = *XMin;
      }
      *XMin = iVar1;
      iVar1 = iVar3;
      if (*YMin < iVar3) {
        iVar1 = *YMin;
      }
      *YMin = iVar1;
      if (iVar2 < *XMax) {
        iVar2 = *XMax;
      }
      *XMax = iVar2;
      if (iVar3 < *YMax) {
        iVar3 = *YMax;
      }
      *YMax = iVar3;
      iVar4 = iVar4 + 1;
      p_Var5 = p_Var5 + 1;
    } while (iVar4 < 8);
    setCopControlWord(2,0,Cam_Matrix.m[0]._0_4_);
    setCopControlWord(2,0x800,Cam_Matrix.m._4_4_);
    setCopControlWord(2,0x1000,Cam_Matrix.m[1]._2_4_);
    setCopControlWord(2,0x1800,Cam_Matrix.m[2]._0_4_);
    setCopControlWord(2,0x2000,Cam_Matrix._16_4_);
    setCopControlWord(2,0x2800,Cam_Matrix.t[0]);
    setCopControlWord(2,0x3000,Cam_Matrix.t[1]);
    setCopControlWord(2,0x3800,Cam_Matrix.t[2]);
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ D3_ZoneIntersectBBox2D(struct _VISIBILITY *z /*$a0*/, long XMin /*$a1*/, long YMin /*$a2*/, long XMax /*$a3*/, long YMax /*stack 16*/)
 // line 697, offset 0x8001ce0c
	/* begin block 1 */
		// Start line: 698
		// Start offset: 0x8001CE0C
		// Variables:
	// 		long ZoneXMin; // $v0
	// 		long ZoneYMin; // $a3
	// 		long ZoneXMax; // $t0
	// 		long ZoneYMax; // $v1
	// 		long t1; // $v0
	// 		long t2; // $t0
	// 		long t3; // $a1
	// 		long t4; // $v1
	/* end block 1 */
	// End offset: 0x8001CE0C
	// End Line: 700

	/* begin block 2 */
		// Start line: 1396
	/* end block 2 */
	// End Line: 1397

long D3_ZoneIntersectBBox2D(_VISIBILITY *z,long XMin,long YMin,long XMax,long YMax)

{
  return ((XMax - (int)z->x1 | (int)z->x2 - XMin | YMax - (int)z->y1 | (int)z->y2 - YMin) >> 0x1f) +
         1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ D3_SetShadow(struct _D3_OBJECT *o /*$s0*/, struct D3_31fake *p /*$s1*/)
 // line 725, offset 0x8001b7f8
	/* begin block 1 */
		// Start line: 726
		// Start offset: 0x8001B7F8
		// Variables:
	// 		struct D3_7fake v[4]; // stack offset -48
	// 		long zs; // $v0
	/* end block 1 */
	// End offset: 0x8001B900
	// End Line: 759

	/* begin block 2 */
		// Start line: 1630
	/* end block 2 */
	// End Line: 1631

long D3_SetShadow(_D3_OBJECT *o,undefined p)

{
  _TMD_2D *p_Var1;
  long lVar2;
  undefined3 in_register_00000015;
  int iVar3;
  short local_30;
  short local_2e;
  short local_2c;
  undefined2 local_28;
  undefined2 local_26;
  short local_24;
  undefined2 local_20;
  undefined2 local_1e;
  short local_1c;
  short local_18;
  short local_16;
  short local_14;
  
  iVar3 = CONCAT31(in_register_00000015,p);
  lVar2 = Boxes_GetHeightUnder(o,(char)o + ',');
  local_30 = (o->b_box).vx;
  local_2e = (o->b_box).vy;
  local_28 = *(undefined2 *)&o->b_step;
  local_26 = *(undefined2 *)((int)&o->b_step + 2);
  local_20 = *(undefined2 *)&o->b_sunk;
  local_1e = *(undefined2 *)((int)&o->b_sunk + 2);
  local_18 = o->comp_opt2;
  local_2c = (short)lVar2 - (o->pos).vz;
  local_16 = o->comp_opt3;
  local_24 = local_2c;
  local_1c = local_2c;
  local_14 = local_2c;
  GtxTmd_RotTransPersN(&local_30,Tmd_2DSpeed,4);
  p_Var1 = Tmd_2DSpeed;
  *(undefined4 *)(iVar3 + 8) = *(undefined4 *)Tmd_2DSpeed;
  *(undefined4 *)(iVar3 + 0x10) = *(undefined4 *)(p_Var1 + 1);
  *(undefined4 *)(iVar3 + 0x18) = *(undefined4 *)(p_Var1 + 3);
  *(undefined4 *)(iVar3 + 0x20) = *(undefined4 *)(p_Var1 + 2);
  lVar2 = (int)p_Var1->vz + (int)p_Var1[1].vz + (int)p_Var1[2].vz + (int)p_Var1[3].vz >> 4;
  if (lVar2 < 0) {
    lVar2 = 0;
  }
  return lVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ D3_ManageList(struct _D3_OBJECT *obj /*$s0*/)
 // line 762, offset 0x8001b914
	/* begin block 1 */
		// Start line: 1738
	/* end block 1 */
	// End Line: 1739

void D3_ManageList(_D3_OBJECT *obj)

{
  short sVar1;
  short sVar2;
  short sVar3;
  
  if ((Pvl_Pause == 0) && (obj != (_D3_OBJECT *)0x0)) {
    do {
      if ((obj->display_mode & 0x40U) != 0) {
        Manim_PlayAnim((M_OBJECT *)obj->description);
      }
      if ((obj->collision_mode & 8U) == 0) {
        sVar1 = (obj->pos).vx;
        sVar2 = (obj->pos).vy;
        sVar3 = (obj->pos).vz;
        (obj->rot).pad = (obj->rot).vz;
        (obj->last_pos).vx = sVar1;
        (obj->last_pos).vy = sVar2;
        (obj->last_pos).vz = sVar3;
      }
      else {
        Boxes_TestObject(obj);
      }
      if (obj->child != (_D3_OBJECT *)0x0) {
        D3_ManageList(obj->child);
      }
      obj = obj->next;
    } while (obj != (_D3_OBJECT *)0x0);
  }
  return;
}



// decompiled code
// original method signature: 
// void * /*$ra*/ D3_DisplayList(struct _D3_OBJECT *obj /*$s0*/, void *Prims /*$s3*/, long mini_x /*$s5*/, long maxi_x /*$s6*/)
 // line 792, offset 0x8001b9d4
	/* begin block 1 */
		// Start line: 793
		// Start offset: 0x8001B9D4

		/* begin block 1.1 */
			// Start line: 809
			// Start offset: 0x8001BA7C
			// Variables:
		// 		long disp; // $s4
		// 		long ObjMinX; // $s2
		// 		long ObjMaxX; // $s1

			/* begin block 1.1.1 */
				// Start line: 817
				// Start offset: 0x8001BA94
				// Variables:
			// 		long XObj0; // stack offset -56
			// 		long YObj0; // stack offset -52
			// 		long XObj1; // stack offset -48
			// 		long YObj1; // stack offset -44
			// 		long i; // $t0

				/* begin block 1.1.1.1 */
					// Start line: 793
					// Start offset: 0x8001BAF0
					// Variables:
				// 		struct _VISIBILITY *z; // $a2
				// 		long XMin; // $t4
				// 		long YMin; // $t3
				// 		long XMax; // $t2
				// 		long YMax; // $t1

					/* begin block 1.1.1.1.1 */
						// Start line: 793
						// Start offset: 0x8001BAF0
						// Variables:
					// 		long t4; // $a0
					// 		long t3; // $v1
					// 		long t2; // $a1
					// 		long t1; // $v0
					// 		long ZoneYMax; // $a0
					// 		long ZoneXMax; // $a1
					// 		long ZoneYMin; // $v1
					// 		long ZoneXMin; // $v0
					/* end block 1.1.1.1.1 */
					// End offset: 0x8001BAF0
					// End Line: 793
				/* end block 1.1.1.1 */
				// End offset: 0x8001BAF0
				// End Line: 793
			/* end block 1.1.1 */
			// End offset: 0x8001BB8C
			// End Line: 838
		/* end block 1.1 */
		// End offset: 0x8001BBD4
		// End Line: 847
	/* end block 1 */
	// End offset: 0x8001BC6C
	// End Line: 863

	/* begin block 2 */
		// Start line: 1820
	/* end block 2 */
	// End Line: 1821

void * D3_DisplayList(_D3_OBJECT *obj,void *Prims,long mini_x,long maxi_x)

{
  bool bVar1;
  long lVar2;
  _VISIBILITY *p_Var3;
  _VISIBILITY **pp_Var4;
  int iVar5;
  int maxi_x_00;
  int iVar6;
  int mini_x_00;
  int iVar7;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  if (obj != (_D3_OBJECT *)0x0) {
    do {
      obj->collision_state = obj->collision_state & 0xff7f;
      if ((obj->display_mode & 0x10U) != 0) {
        if ((obj->collision_mode & 0x1010U) != 0) {
          SetBackColor((uint)(Pvl_File->light_ambient).r + 0x20,
                       (uint)(Pvl_File->light_ambient).g + 0x20,
                       (uint)(Pvl_File->light_ambient).b + 0x20);
        }
        bVar1 = true;
        if (obj->description != (void *)0x0) {
          maxi_x_00 = maxi_x;
          mini_x_00 = mini_x;
          if ((obj->display_mode & 0x20U) != 0) {
            bVar1 = false;
            lVar2 = D3_ObjectInScreen(obj);
            maxi_x_00 = maxi_x;
            mini_x_00 = mini_x;
            if (lVar2 != 0) {
              D3_ComputeBBox2D(obj,&local_38,&local_34,&local_30,&local_2c);
              iVar5 = 0;
              mini_x_00 = (int)Scr_W;
              maxi_x_00 = 0;
              pp_Var4 = &Plat_VisibleZones256;
              iVar6 = maxi_x_00;
              iVar7 = mini_x_00;
              if (0 < Plat_NVisibleZones) {
                do {
                  p_Var3 = *pp_Var4;
                  maxi_x_00 = iVar6;
                  mini_x_00 = iVar7;
                  if ((local_30 - (int)p_Var3->x1 | (int)p_Var3->x2 - local_38 |
                       local_2c - (int)p_Var3->y1 | (int)p_Var3->y2 - local_34) >> 0x1f == 0) {
                    bVar1 = true;
                    mini_x_00 = (int)p_Var3->min;
                    if (iVar7 < (int)p_Var3->min) {
                      mini_x_00 = iVar7;
                    }
                    maxi_x_00 = (int)p_Var3->max;
                    if ((int)p_Var3->max < iVar6) {
                      maxi_x_00 = iVar6;
                    }
                  }
                  iVar5 = iVar5 + 1;
                  pp_Var4 = pp_Var4 + 1;
                  iVar6 = maxi_x_00;
                  iVar7 = mini_x_00;
                } while (iVar5 < Plat_NVisibleZones);
              }
            }
          }
          if (bVar1) {
            if ((obj->display_mode & 0x40U) == 0) {
              Prims = D3_DisplayTmd(obj,Prims,mini_x_00,maxi_x_00);
            }
            else {
              Prims = Manim_DisplayActor((M_OBJECT *)obj->description,Prims,mini_x_00,maxi_x_00);
            }
          }
        }
        if (((obj->collision_state & 0x80U) != 0) && (((int)obj->collision_mode & 0x8000U) != 0)) {
          Prims = Stats_DisplayMonsterLives(obj,Prims);
        }
        if ((obj->collision_mode & 0x1010U) != 0) {
          SetBackColor((uint)(Pvl_File->light_ambient).r,(uint)(Pvl_File->light_ambient).g,
                       (uint)(Pvl_File->light_ambient).b);
        }
      }
      if (obj->child != (_D3_OBJECT *)0x0) {
        Prims = D3_DisplayList(obj->child,Prims,mini_x,maxi_x);
      }
      obj = obj->next;
    } while (obj != (_D3_OBJECT *)0x0);
  }
  return Prims;
}



// decompiled code
// original method signature: 
// void * /*$ra*/ D3_DisplayTmd(struct _D3_OBJECT *obj /*$s4*/, void *Prims /*$s2*/, long mini_x /*$s5*/, long maxi_x /*$s6*/)
 // line 867, offset 0x8001bc9c
	/* begin block 1 */
		// Start line: 868
		// Start offset: 0x8001BC9C
		// Variables:
	// 		struct D3_5fake mr; // stack offset -192
	// 		struct D3_5fake ml; // stack offset -160
	// 		struct D3_5fake ms; // stack offset -128
	// 		struct D3_5fake mn64; // stack offset -96
	// 		struct D3_5fake matrix; // stack offset -64
	// 		struct D3_93fake *tmd; // $s0
	// 		long dz; // $a2
	// 		long z; // $s3
	// 		long ot; // $s0
	// 		void *otl; // $s1
	/* end block 1 */
	// End offset: 0x8001C510
	// End Line: 1054

	/* begin block 2 */
		// Start line: 2050
	/* end block 2 */
	// End Line: 2051

void * D3_DisplayTmd(_D3_OBJECT *obj,void *Prims,long mini_x,long maxi_x)

{
  ushort uVar1;
  _SCREEN *p_Var2;
  undefined4 in_zero;
  undefined4 in_at;
  void *Prims_00;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  _ROTMATRIX *p_Var7;
  int iVar8;
  int iVar9;
  int iVar10;
  ushort local_c0;
  ushort local_be;
  ushort local_bc;
  ushort local_ba;
  ushort local_b8;
  ushort local_b6;
  ushort local_b4;
  ushort local_b2;
  ushort local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  uint local_a0;
  uint local_9c;
  uint local_98;
  uint local_94;
  uint local_90;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  
  iVar8 = (uint)(Pvl_File->fog).cd * 100;
  setCopReg(2,in_zero,*(undefined4 *)&obj->pos);
  setCopReg(2,in_at,*(undefined4 *)&(obj->pos).vz);
  copFunction(2,0x486012);
  local_ac = getCopReg(2,0x19);
  local_a8 = getCopReg(2,0x1a);
  local_a4 = getCopReg(2,0x1b);
  local_ac = local_ac + Cam_Matrix.t[0];
  local_a8 = local_a8 + Cam_Matrix.t[1];
  local_a4 = local_a4 + Cam_Matrix.t[2];
  setCopControlWord(2,0x2800,local_ac);
  setCopControlWord(2,0x3000,local_a8);
  setCopControlWord(2,0x3800,local_a4);
  if ((obj->collision_mode & 4U) != 0) {
    RotMatrixZYX((short *)&obj->rot,&local_c0);
    SetMulMatrix((undefined4 *)&Cam_Matrix,&local_c0);
  }
  GtxTmd_RotTransPersN(&obj->b_box,Tmd_2DSpeed,8);
  setCopControlWord(2,0,Cam_Matrix.m[0]._0_4_);
  setCopControlWord(2,0x800,Cam_Matrix.m._4_4_);
  setCopControlWord(2,0x1000,Cam_Matrix.m[1]._2_4_);
  setCopControlWord(2,0x1800,Cam_Matrix.m[2]._0_4_);
  setCopControlWord(2,0x2000,Cam_Matrix._16_4_);
  if ((obj->display_mode & 1U) == 0) {
    setCopControlWord(2,0x2800,Cam_Matrix.t[0]);
    setCopControlWord(2,0x3000,Cam_Matrix.t[1]);
    setCopControlWord(2,0x3800,Cam_Matrix.t[2]);
  }
  else {
    if ((obj->display_mode & 2U) != 0) {
      RotMatrixZYX((short *)&obj->rot,&local_c0);
      SetMulMatrix((undefined4 *)&Cam_Matrix,&local_c0);
    }
  }
  iVar9 = (int)Tmd_2DSpeed->vz + (int)Tmd_2DSpeed[1].vz + (int)Tmd_2DSpeed[2].vz +
          (int)Tmd_2DSpeed[3].vz +
          (int)Tmd_2DSpeed[4].vz + (int)Tmd_2DSpeed[5].vz + (int)Tmd_2DSpeed[6].vz +
          (int)Tmd_2DSpeed[7].vz;
  iVar10 = iVar9 >> 5;
  if (0 < iVar9) {
    if (iVar10 < 2) {
      iVar10 = 2;
    }
    if ((((((int)Tmd_2DSpeed->vz < iVar8) || ((int)Tmd_2DSpeed[1].vz < iVar8)) ||
         ((int)Tmd_2DSpeed[2].vz < iVar8)) ||
        ((((int)Tmd_2DSpeed[3].vz < iVar8 || ((int)Tmd_2DSpeed[4].vz < iVar8)) ||
         (((int)Tmd_2DSpeed[5].vz < iVar8 ||
          (((int)Tmd_2DSpeed[6].vz < iVar8 || ((int)Tmd_2DSpeed[7].vz < iVar8)))))))) &&
       ((((obj->display_mode & 0x100U) == 0 || (iVar10 < (int)Scr_OtSize)) &&
        (((((-1 < Tmd_2DSpeed->vy || (-1 < Tmd_2DSpeed[1].vy)) || (-1 < Tmd_2DSpeed[2].vy)) ||
          (-1 < Tmd_2DSpeed[3].vy)) &&
         (((((Tmd_2DSpeed[4].vy < Scr_H || (Tmd_2DSpeed[5].vy < Scr_H)) ||
            ((Tmd_2DSpeed[6].vy < Scr_H || (Tmd_2DSpeed[7].vy < Scr_H)))) &&
           ((((mini_x <= (int)Tmd_2DSpeed->vx || (mini_x <= (int)Tmd_2DSpeed[1].vx)) ||
             (mini_x <= (int)Tmd_2DSpeed[2].vx)) ||
            ((((mini_x <= (int)Tmd_2DSpeed[3].vx || (mini_x <= (int)Tmd_2DSpeed[4].vx)) ||
              (mini_x <= (int)Tmd_2DSpeed[5].vx)) ||
             ((mini_x <= (int)Tmd_2DSpeed[6].vx || (mini_x <= (int)Tmd_2DSpeed[7].vx)))))))) &&
          (((((int)Tmd_2DSpeed->vx < maxi_x ||
             (((int)Tmd_2DSpeed[1].vx < maxi_x || ((int)Tmd_2DSpeed[2].vx < maxi_x)))) ||
            ((int)Tmd_2DSpeed[3].vx < maxi_x)) ||
           (((((int)Tmd_2DSpeed[4].vx < maxi_x || ((int)Tmd_2DSpeed[5].vx < maxi_x)) ||
             ((int)Tmd_2DSpeed[6].vx < maxi_x)) || ((int)Tmd_2DSpeed[7].vx < maxi_x)))))))))))) {
      obj->collision_state = obj->collision_state | 0x80;
      if ((obj->display_mode & 8U) != 0) {
        Light_SetMatrix(obj);
      }
      if ((obj->display_mode & 4U) != 0) {
        if ((obj->display_mode & 2U) == 0) {
          p_Var7 = obj->matrices;
          setCopControlWord(2,0x4000,*(undefined4 *)p_Var7->m);
          setCopControlWord(2,0x4800,*(undefined4 *)(p_Var7->m + 2));
          setCopControlWord(2,0x5000,*(undefined4 *)(p_Var7->m + 4));
          setCopControlWord(2,0x5800,*(undefined4 *)(p_Var7->m + 6));
          setCopControlWord(2,0x6000,*(undefined4 *)(p_Var7->m + 8));
        }
        else {
          local_80 = getCopControlWord(2,0);
          local_7c = getCopControlWord(2,0x800);
          local_78 = getCopControlWord(2,0x1000);
          local_74 = getCopControlWord(2,0x1800);
          local_70 = getCopControlWord(2,0x2000);
          local_6c = getCopControlWord(2,0x2800);
          local_68 = getCopControlWord(2,0x3000);
          local_64 = getCopControlWord(2,0x3800);
          p_Var7 = obj->matrices;
          setCopControlWord(2,0,*(undefined4 *)p_Var7->m);
          setCopControlWord(2,0x800,*(undefined4 *)(p_Var7->m + 2));
          setCopControlWord(2,0x1000,*(undefined4 *)(p_Var7->m + 4));
          setCopControlWord(2,0x1800,*(undefined4 *)(p_Var7->m + 6));
          setCopControlWord(2,0x2000,*(undefined4 *)(p_Var7->m + 8));
          setCopReg(2,0x4800,(uint)local_c0);
          setCopReg(2,0x5000,(uint)local_ba);
          setCopReg(2,0x5800,(uint)local_b4);
          copFunction(2,0x49e012);
          uVar3 = getCopReg(2,0x4800);
          iVar9 = getCopReg(2,0x5000);
          uVar5 = getCopReg(2,0x5800);
          setCopReg(2,0x4800,(uint)local_be);
          setCopReg(2,0x5000,(uint)local_b8);
          setCopReg(2,0x5800,(uint)local_b2);
          copFunction(2,0x49e012);
          iVar8 = getCopReg(2,0x4800);
          uVar4 = getCopReg(2,0x5000);
          iVar6 = getCopReg(2,0x5800);
          local_a0 = uVar3 & 0xffff | iVar8 << 0x10;
          local_94 = uVar5 & 0xffff | iVar6 << 0x10;
          setCopReg(2,0x4800,(uint)local_bc);
          setCopReg(2,0x5000,(uint)local_b6);
          setCopReg(2,0x5800,(uint)local_b0);
          copFunction(2,0x49e012);
          uVar3 = getCopReg(2,0x4800);
          iVar8 = getCopReg(2,0x5000);
          uVar5 = getCopReg(2,0x5800);
          local_9c = uVar3 & 0xffff | iVar9 << 0x10;
          local_98 = uVar4 & 0xffff | iVar8 << 0x10;
          local_90 = local_90 & 0xffff0000 | uVar5 & 0xffff;
          setCopControlWord(2,0x4000,local_a0);
          setCopControlWord(2,0x4800,local_9c);
          setCopControlWord(2,0x5000,local_98);
          setCopControlWord(2,0x5800,local_94);
          setCopControlWord(2,0x6000,local_90);
          setCopControlWord(2,0,local_80);
          setCopControlWord(2,0x800,local_7c);
          setCopControlWord(2,0x1000,local_78);
          setCopControlWord(2,0x1800,local_74);
          setCopControlWord(2,0x2000,local_70);
        }
        if ((obj->display_mode & 8U) == 0) {
          Light_SetLocalMatrix(obj);
        }
        else {
          p_Var7 = obj->matrices;
          setCopControlWord(2,0x8000,*(undefined4 *)p_Var7[1].m);
          setCopControlWord(2,0x8800,*(undefined4 *)(p_Var7[1].m + 2));
          setCopControlWord(2,0x9000,*(undefined4 *)(p_Var7[1].m + 4));
          setCopControlWord(2,0x9800,*(undefined4 *)(p_Var7[1].m + 6));
          setCopControlWord(2,0xa000,*(undefined4 *)(p_Var7[1].m + 8));
        }
      }
      if ((obj->display_mode & 0x1000U) == 0) {
        Prims_00 = obj->description;
      }
      else {
        Prims_00 = (void *)((int)obj->description + 0xc);
      }
      uVar1 = obj->display_mode;
      if ((uVar1 & 0x100) == 0) {
        iVar8 = 0;
        if ((uVar1 & 0x200) != 0) {
          iVar8 = 0x14;
        }
        if ((uVar1 & 4) == 0) {
          Prims_00 = (void *)GtxTmd_DisplayLOFF(Prims_00,Prims,Scr->ot + iVar8,
                                                (int)Scr_OtSize - iVar8,0);
        }
        else {
          Prims_00 = (void *)GtxTmd_DisplayLON(Prims_00,Prims,Scr->ot + iVar8,
                                               (int)Scr_OtSize - iVar8,0,obj->color);
        }
      }
      else {
        ClearOTagR((undefined4 *)Prims);
        if ((obj->display_mode & 4U) == 0) {
          Prims_00 = (void *)GtxTmd_DisplayLOFF(Prims_00,(int)Prims + 0x200,Prims,0x80,
                                                iVar10 + -0x40);
        }
        else {
          Prims_00 = (void *)GtxTmd_DisplayLON(Prims_00,(int)Prims + 0x200,Prims,0x80,iVar10 + -0x40
                                               ,obj->color);
        }
        p_Var2 = Scr;
        *(uint *)Prims = *(uint *)Prims & 0xff000000 | Scr->ot[iVar10] & 0xffffff;
        p_Var2->ot[iVar10] = p_Var2->ot[iVar10] & 0xff000000 | (int)Prims + 0x1fcU & 0xffffff;
      }
      if (*(short *)((int)&obj->b_hurt + 2) != 0) {
        Prims_00 = D3_DisplayShapes(obj,Prims_00);
      }
      Prims = D3_DisplayBox(obj,Prims_00);
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
// void * /*$ra*/ D3_DisplayShapes(struct _D3_OBJECT *o /*$s7*/, void *Prims /*$a1*/)
 // line 1061, offset 0x8001c584
	/* begin block 1 */
		// Start line: 1062
		// Start offset: 0x8001C584
		// Variables:
	// 		long i; // $s3
	// 		long z; // stack offset -52
	// 		long coef; // stack offset -56
	// 		long mark; // $fp
	// 		short w; // stack offset -48
	// 		short h; // stack offset -46
	// 		struct _D3_ANIMSHP *anim; // $s1
	// 		struct D3_7fake *s; // $v1
	// 		struct D3_31fake *p; // $s2
	// 		struct D3_8fake color; // stack offset -80
	// 		struct D3_70fake shp; // stack offset -72
	/* end block 1 */
	// End offset: 0x8001C888
	// End Line: 1137

	/* begin block 2 */
		// Start line: 2577
	/* end block 2 */
	// End Line: 2578

void * D3_DisplayShapes(_D3_OBJECT *o,void *Prims)

{
  undefined4 uVar1;
  _SCREEN *p_Var2;
  undefined4 in_zero;
  undefined4 in_at;
  short sVar3;
  _D3_ANIMSHP *p_Var4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  _D3_ANIMSHP *anim;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  char local_50;
  char cStack79;
  char cStack78;
  void *local_48;
  short local_44;
  undefined4 local_40;
  undefined4 local_38;
  int local_34;
  short local_30;
  short local_2e [3];
  
  anim = (_D3_ANIMSHP *)o->shapes;
  local_48 = Pvl_Pcl;
  iVar8 = 0;
  sVar3 = Shp_GetMark(Pvl_Pcl,(int)Pvl_File->crc);
  if (0 < *(short *)((int)&o->b_hurt + 2)) {
    pcVar7 = (char *)((int)Prims + 0x25);
    do {
      if ((anim->display & 1) != 0) {
        p_Var4 = anim + 1;
        if (1 < anim->n) {
          p_Var4 = p_Var4 + (uint)(byte)anim->current;
        }
        local_44 = p_Var4->reserved + sVar3;
        setCopReg(2,in_zero,*(undefined4 *)p_Var4);
        setCopReg(2,in_at,*(undefined4 *)&p_Var4->sens);
        copFunction(2,0x180001);
        local_40 = getCopReg(2,0xe);
        local_38 = getCopReg(2,8);
        local_34 = getCopReg(2,0x9800);
        local_34 = local_34 >> 2;
        if ((10 < local_34) && (local_34 < (int)Scr_OtSize)) {
          Shp_GetWH((SHAPE_68fake *)&local_48,&local_30,local_2e);
          iVar9 = (int)local_30 * (int)Scr_GeomScreen;
          iVar10 = iVar9 / local_34;
          if (local_34 == 0) {
            trap(0x1c00);
          }
          if ((local_34 == -1) && (iVar9 == -0x80000000)) {
            trap(0x1800);
          }
          iVar9 = (int)local_2e[0] * (int)Scr_GeomScreen;
          iVar11 = iVar9 / local_34;
          if (local_34 == 0) {
            trap(0x1c00);
          }
          in_at = 0x80000000;
          if ((local_34 == -1) && (iVar9 == -0x80000000)) {
            trap(0x1800);
          }
          iVar9 = (iVar10 + 1) * 0x10000;
          iVar6 = iVar9 >> 0x10;
          local_30 = (short)iVar10;
          local_2e[0] = (short)iVar11;
          Shp_SetPolyFT4((SHAPE_31fake *)Prims,(SHAPE_68fake *)&local_48,
                         (short)((uint)iVar9 >> 0x10),
                         (short)((uint)((iVar11 + 1) * 0x10000) >> 0x10));
          pcVar7[-0x1e] = pcVar7[-0x1e] & 0xfe;
          setCopReg(2,iVar6,0x808080);
          setCopReg(2,0x4000,local_38);
          copFunction(2,0x780010);
          uVar1 = getCopReg(2,0x16);
          local_50 = (char)uVar1;
          pcVar7[-0x21] = local_50;
          cStack79 = (char)((uint)uVar1 >> 8);
          pcVar7[-0x20] = cStack79;
          cStack78 = (char)((uint)uVar1 >> 0x10);
          pcVar7[-1] = pcVar7[-1] + '\x01';
          pcVar7[-0x11] = pcVar7[-0x11] + '\x01';
          *pcVar7 = *pcVar7 + '\x01';
          pcVar7[-0x1f] = cStack78;
          pcVar7[-8] = pcVar7[-8] + '\x01';
          p_Var2 = Scr;
          pcVar7 = pcVar7 + 0x28;
          ((SHAPE_31fake *)Prims)->tag =
               ((SHAPE_31fake *)Prims)->tag & 0xff000000 | Scr->ot[local_34 + -10] & 0xffffff;
          uVar5 = (uint)Prims & 0xffffff;
          Prims = (SHAPE_31fake *)Prims + 1;
          (p_Var2->ot + local_34)[-10] = (p_Var2->ot + local_34)[-10] & 0xff000000 | uVar5;
        }
        D3_IncShpAnim(anim);
      }
      iVar8 = iVar8 + 1;
      anim = anim + (uint)anim->n + 1;
    } while (iVar8 < (int)*(short *)((int)&o->b_hurt + 2));
  }
  return (SHAPE_31fake *)Prims;
}



// decompiled code
// original method signature: 
// void /*$ra*/ D3_IncShpAnim(struct _D3_ANIMSHP *anim /*$a0*/)
 // line 1141, offset 0x8001c8bc
	/* begin block 1 */
		// Start line: 2939
	/* end block 1 */
	// End Line: 2940

void D3_IncShpAnim(_D3_ANIMSHP *anim)

{
  byte bVar1;
  char cVar2;
  
  if (Pvl_Pause != 0) {
    return;
  }
  if (anim->n < 2) {
    return;
  }
  if (anim->rate == 0) {
    trap(0x1c00);
  }
  if ((uint)(byte)anim->step % (uint)anim->rate == 0) {
    bVar1 = anim->display;
    if ((bVar1 & 2) == 0) {
      if ((bVar1 & 4) == 0) {
        if ((bVar1 & 8) == 0) goto LAB_8001c9e4;
        if ((anim->current == '\0') || ((uint)(byte)anim->current == (uint)anim->n - 1)) {
          anim->sens = -anim->sens;
        }
        if ((anim->current == '\0') && (1 < (byte)anim->sens)) {
          anim->sens = '\x01';
        }
        cVar2 = anim->current + anim->sens;
      }
      else {
        cVar2 = anim->current + 1;
        if ((int)((uint)anim->n - 1) <= (int)(uint)(byte)anim->current) {
          cVar2 = '\0';
        }
      }
    }
    else {
      cVar2 = anim->current + 1;
      if ((int)((uint)anim->n - 1) <= (int)(uint)(byte)anim->current) {
        anim->display = '\0';
        goto LAB_8001c9e4;
      }
    }
    anim->current = cVar2;
  }
LAB_8001c9e4:
  anim->step = anim->step + '\x01';
  return;
}



// decompiled code
// original method signature: 
// void * /*$ra*/ D3_DisplayBox(struct _D3_OBJECT *o /*$a0*/, void *Prims /*$a1*/)
 // line 1188, offset 0x8001c9fc
	/* begin block 1 */
		// Start line: 3033
	/* end block 1 */
	// End Line: 3034

void * D3_DisplayBox(_D3_OBJECT *o,void *Prims)

{
  return Prims;
}



// decompiled code
// original method signature: 
// long /*$ra*/ D3_SetBonuses(struct _D3_OBJECT *o /*$s3*/, long visible /*$s4*/, struct _D3_OBJECT *orig /*$s1*/)
 // line 1277, offset 0x8001ca04
	/* begin block 1 */
		// Start line: 1278
		// Start offset: 0x8001CA04
		// Variables:
	// 		struct _D3_OBJECT *obj; // $s0
	// 		long ret; // $s2
	/* end block 1 */
	// End offset: 0x8001CBF0
	// End Line: 1340

	/* begin block 2 */
		// Start line: 3210
	/* end block 2 */
	// End Line: 3211

long D3_SetBonuses(_D3_OBJECT *o,long visible,_D3_OBJECT *orig)

{
  char cVar1;
  short sVar2;
  long lVar3;
  _D3_OBJECT *o_00;
  long lVar4;
  
  lVar4 = 0;
  if (o->child != (_D3_OBJECT *)0x0) {
    if (*(char *)((int)&o[1].pos.vx + 1) != '\b') {
      o_00 = o->father;
      while (o_00 != (_D3_OBJECT *)0x0) {
        if ((((int)o_00->collision_mode & 0x8000U) != 0) &&
           (lVar3 = Pvl_TestStateBits(o_00,2), lVar3 == 0)) {
          return 0;
        }
        o_00 = o_00->father;
      }
    }
    o_00 = o->child;
    do {
      if ((((int)o_00->collision_mode & 0x8000U) != 0) &&
         (lVar3 = Pvl_TestStateBits(o_00,2), lVar3 == 0)) {
        return 0;
      }
      if (*(char *)((int)&o_00[1].pos.vx + 1) == '\x03') {
        if (visible == 0) {
          o_00->display_mode = o_00->display_mode & 0xffef;
          D3_ClearCollBits(o_00,9);
          Impact_Smoke((char)o_00 + ',',1);
LAB_8001cbbc:
          lVar4 = 1;
        }
        else {
          Task_EventExec(o_00->handle,-0x2000,0);
          o_00->display_mode = o_00->display_mode | 0x10;
          D3_SetCollBits(o_00,1);
          if ((*(uint *)&o[1].pos & 0xffffff00) != 0xb00) {
            cVar1 = *(char *)((int)&o[1].pos.vx + 1);
            if ((cVar1 == '\b') || (*(char *)((int)&orig[1].pos.vx + 1) == '\0')) goto LAB_8001cbbc;
            lVar4 = 1;
            if (cVar1 == '\v') goto LAB_8001cbc0;
            sVar2 = (orig->pos).vx;
            (o_00->last_pos).vx = sVar2;
            (o_00->pos).vx = sVar2;
            sVar2 = (orig->pos).vy;
            (o_00->last_pos).vy = sVar2;
            (o_00->pos).vy = sVar2;
            sVar2 = (orig->pos).vz + 100;
            (o_00->last_pos).vz = sVar2;
            (o_00->pos).vz = sVar2;
          }
          Pvl_SetStateBits(orig,0x10);
          Impact_Smoke((char)o_00 + ',',1);
          Fx_Play(0x3e,(char)orig + ',');
          lVar4 = 1;
        }
      }
LAB_8001cbc0:
      if (o_00->child != (_D3_OBJECT *)0x0) {
        D3_SetBonuses(o_00,visible,orig);
      }
      o_00 = o_00->next;
    } while (o_00 != (_D3_OBJECT *)0x0);
  }
  return lVar4;
}



// decompiled code
// original method signature: 
// short /*$ra*/ D3_PlaySoundCamera(struct _D3_OBJECT *o /*$a0*/, short snd /*$a1*/)
 // line 1343, offset 0x8001cc10
	/* begin block 1 */
		// Start line: 1344
		// Start offset: 0x8001CC10
	/* end block 1 */
	// End offset: 0x8001CC50
	// End Line: 1352

	/* begin block 2 */
		// Start line: 3345
	/* end block 2 */
	// End Line: 3346

short D3_PlaySoundCamera(_D3_OBJECT *o,short snd)

{
  short sVar1;
  
  if (*(short *)((int)&o[1].father + 2) == -1) {
    sVar1 = -1;
  }
  else {
    sVar1 = Fx_Play_Camera((short)(((uint)*(ushort *)((int)&o[1].father + 2) + (uint)(ushort)snd) *
                                   0x10000 >> 0x10),0x68);
  }
  return sVar1;
}



// decompiled code
// original method signature: 
// short /*$ra*/ D3_PlaySound(struct _D3_OBJECT *o /*$a2*/, short snd /*$a1*/)
 // line 1355, offset 0x8001cc60
	/* begin block 1 */
		// Start line: 1356
		// Start offset: 0x8001CC60
		// Variables:
	// 		short flag; // $a3

		/* begin block 1.1 */
			// Start line: 1365
			// Start offset: 0x8001CC90
			// Variables:
		// 		struct M_OBJECT *mo; // $v0
		/* end block 1.1 */
		// End offset: 0x8001CCAC
		// End Line: 1370
	/* end block 1 */
	// End offset: 0x8001CCD8
	// End Line: 1376

	/* begin block 2 */
		// Start line: 3372
	/* end block 2 */
	// End Line: 3373

short D3_PlaySound(_D3_OBJECT *o,short snd)

{
  short sVar1;
  long VolumeMode;
  
  sVar1 = -1;
  VolumeMode = 0;
  if (*(short *)((int)&o[1].father + 2) != -1) {
    if ((((int)o->collision_mode & 0x8000U) != 0) && (*(int *)((int)o->description + 0x10) == 0xb00)
       ) {
      VolumeMode = 6;
    }
    sVar1 = Fx_Play_Sample((short)(((uint)*(ushort *)((int)&o[1].father + 2) + (uint)(ushort)snd) *
                                   0x10000 >> 0x10),(char)o + ',',0x70,VolumeMode);
  }
  return sVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ D3_StopSound(struct _D3_OBJECT *o /*$a0*/, short snd_handle /*$a1*/)
 // line 1379, offset 0x8001cce8
	/* begin block 1 */
		// Start line: 3420
	/* end block 1 */
	// End Line: 3421

void D3_StopSound(_D3_OBJECT *o,short snd_handle)

{
  if ((*(short *)((int)&o[1].father + 2) != -1) && ((int)snd_handle != -1)) {
    Sound_Stop((int)snd_handle,0);
  }
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ D3_UpdateSound(struct _D3_OBJECT *o /*$s2*/, short snd /*$a1*/, short snd_handle /*$s1*/)
 // line 1387, offset 0x8001cd24
	/* begin block 1 */
		// Start line: 3436
	/* end block 1 */
	// End Line: 3437

short D3_UpdateSound(_D3_OBJECT *o,short snd,short snd_handle)

{
  long lVar1;
  int wPlayId;
  
  lVar1 = Distance3D((int)(o->pos).vx,(int)(o->pos).vy,(int)(o->pos).vz,(int)DAT_800b4170,
                     (int)DAT_800b4172,(int)DAT_800b4174);
  wPlayId = (int)snd_handle;
  if (lVar1 < 0x4b0) {
    if (wPlayId == -1) {
      if (-1 < *(short *)((int)&o[1].father + 2)) {
        snd_handle = Fx_Play((short)(((uint)*(ushort *)((int)&o[1].father + 2) + (uint)(ushort)snd)
                                     * 0x10000 >> 0x10),(char)o + ',');
      }
    }
    else {
      Fx_SetVolume(snd_handle,(char)o + ',');
    }
  }
  else {
    if (-1 < wPlayId) {
      Sound_Stop(wPlayId,0);
      snd_handle = -1;
    }
  }
  return snd_handle;
}





