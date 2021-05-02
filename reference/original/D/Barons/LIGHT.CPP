#include "THISDUST.H"
#include "LIGHT.H"


// decompiled code
// original method signature: 
// void /*$ra*/ Light_Blink()
 // line 29, offset 0x8001ce54
	/* begin block 1 */
		// Start line: 30
		// Start offset: 0x8001CE54
		// Variables:
	// 		struct _LIGHT *l; // $s5
	// 		struct _ANIM_BLINK *ab; // $s0
	// 		long dummy; // stack offset -40
	// 		long z; // stack offset -36
	// 		long spd; // $v1
	// 		long p; // $s1
	// 		long ip; // $s2
	// 		long cmin; // $s3
	// 		long cmax; // $s4
	/* end block 1 */
	// End offset: 0x8001D360
	// End Line: 148

	/* begin block 2 */
		// Start line: 65
	/* end block 2 */
	// End Line: 66

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Light_Blink(void)

{
  short coef;
  ushort uVar1;
  undefined4 in_zero;
  undefined4 in_at;
  long lVar2;
  int iVar3;
  _ANIM_BLINK *ab;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  void *pvVar8;
  
  pvVar8 = TaskCurrent->local;
  ab = *(_ANIM_BLINK **)((int)pvVar8 + 4);
  iVar3 = (int)ab->speed;
  uVar7 = SEXT24(ab->coef_max);
  uVar6 = SEXT24(ab->coef_min);
  iVar5 = uVar7 - uVar6;
  if (iVar3 != 0) {
    if (ab->speed_rnd != 0) {
      lVar2 = M_rand();
      iVar5 = (int)ab->speed_rnd;
      if (iVar5 == 0) {
        trap(0x1c00);
      }
      if ((iVar5 == -1) && (lVar2 == -0x80000000)) {
        trap(0x1800);
      }
      iVar3 = (int)ab->speed - lVar2 % iVar5;
    }
    iVar5 = (int)(uVar7 - uVar6) / iVar3;
    if (iVar3 == 0) {
      trap(0x1c00);
    }
    in_at = 0x80000000;
    if ((iVar3 == -1) && (uVar7 - uVar6 == -0x80000000)) {
      trap(0x1800);
    }
  }
  uVar4 = uVar6;
  if (((ab->color).pad & 4U) != 0) {
    uVar4 = uVar7;
  }
  if (ab->pblink != (long *)0x0) {
    Light_IntplBlink(ab,(short)uVar4);
  }
  do {
    setCopReg(2,in_zero,*(undefined4 *)((int)pvVar8 + 0x18));
    setCopReg(2,in_at,*(undefined4 *)((int)pvVar8 + 0x1c));
    copFunction(2,0x180001);
    getCopReg(2,0xe);
    iVar3 = getCopReg(2,0x9800);
    if ((iVar3 >> 2) * 4 - (int)*(short *)((int)pvVar8 + 0x12) <=
        (int)((uint)(Pvl_File->fog).cd * 100)) {
      if (((int)ab->interruptor == 0) || (((int)ab->interruptor & Scts_Interruptors) != 0)) {
        if (((ab->color).pad & 1U) == 0) {
          uVar4 = uVar4 + iVar5;
          *(undefined2 *)((int)pvVar8 + 0xe) = (short)uVar4;
        }
        else {
          lVar2 = M_rand();
          iVar5 = lVar2 % 0x14 + 0x40;
          uVar4 = uVar4 + iVar5;
          if (0x1000 < (int)uVar4) {
            uVar4 = 0;
          }
          iVar3 = rsin(uVar4);
          *(undefined2 *)((int)pvVar8 + 0xe) = (short)iVar3;
        }
        uVar1 = (ab->color).pad;
        if ((uVar1 & 2) != 0) {
          iVar5 = 0;
          if ((uVar1 & 4) == 0) {
            uVar4 = SEXT24(ab->coef_max);
            *(short *)((int)pvVar8 + 0xe) = ab->coef_max;
          }
          else {
            uVar4 = SEXT24(ab->coef_min);
            *(short *)((int)pvVar8 + 0xe) = ab->coef_min;
          }
        }
        if (ab->pblink != (long *)0x0) {
          Light_IntplBlink(ab,(short)uVar4);
        }
        if (((int)uVar4 <= (int)ab->coef_min) || ((int)ab->coef_max <= (int)uVar4)) {
          if (iVar5 < 0) {
            if (ab->rand_max != 0) {
              lVar2 = M_rand();
              iVar5 = (int)ab->rand_max;
              if (iVar5 == 0) {
                trap(0x1c00);
              }
              in_at = 0x80000000;
              if ((iVar5 == -1) && (lVar2 == -0x80000000)) {
                trap(0x1800);
              }
              uVar7 = (int)ab->coef_max - lVar2 % iVar5;
            }
            if (ab->rand_min != 0) {
              lVar2 = M_rand();
              iVar5 = (int)ab->rand_min;
              if (iVar5 == 0) {
                trap(0x1c00);
              }
              in_at = 0x80000000;
              if ((iVar5 == -1) && (lVar2 == -0x80000000)) {
                trap(0x1800);
              }
              uVar6 = (int)ab->coef_min + lVar2 % iVar5;
            }
            if ((int)uVar7 <= (int)uVar6) {
              uVar6 = SEXT24(ab->coef_min);
            }
            iVar3 = (int)ab->speed;
            iVar5 = uVar7 - uVar6;
            if (iVar3 != 0) {
              if (ab->speed_rnd != 0) {
                lVar2 = M_rand();
                iVar5 = (int)ab->speed_rnd;
                if (iVar5 == 0) {
                  trap(0x1c00);
                }
                if ((iVar5 == -1) && (lVar2 == -0x80000000)) {
                  trap(0x1800);
                }
                iVar3 = (int)ab->speed - lVar2 % iVar5;
              }
              iVar5 = (int)(uVar7 - uVar6) / iVar3;
              if (iVar3 == 0) {
                trap(0x1c00);
              }
              in_at = 0x80000000;
              if ((iVar3 == -1) && (uVar7 - uVar6 == -0x80000000)) {
                trap(0x1800);
              }
            }
            uVar4 = uVar6;
            if (((ab->color).pad & 4U) != 0) {
              uVar4 = uVar7;
            }
          }
          else {
            iVar5 = -iVar5;
          }
          if ((ab->random != 0) && (ab->max != ab->min)) {
            lVar2 = M_rand();
            iVar3 = (int)ab->max - (int)ab->min;
            if (iVar3 == 0) {
              trap(0x1c00);
            }
            in_at = 0x80000000;
            if ((iVar3 == -1) && (lVar2 == -0x80000000)) {
              trap(0x1800);
            }
            Task_Sleep(lVar2 % iVar3 + (int)ab->min);
          }
        }
      }
      uVar1 = (ab->color).pad;
      if ((((uVar1 & 2) != 0) && ((int)ab->interruptor != 0)) &&
         (((int)ab->interruptor & Scts_Interruptors) == 0)) {
        iVar5 = 0;
        if ((uVar1 & 4) == 0) {
          coef = ab->coef_min;
          *(short *)((int)pvVar8 + 0xe) = coef;
        }
        else {
          coef = ab->coef_max;
          *(short *)((int)pvVar8 + 0xe) = coef;
        }
        uVar4 = SEXT24(coef);
        if (ab->pblink != (long *)0x0) {
          Light_IntplBlink(ab,coef);
        }
      }
    }
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Light_IntplBlink(struct _ANIM_BLINK *ab /*$s7*/, short coef /*$s4*/)
 // line 151, offset 0x8001d360
	/* begin block 1 */
		// Start line: 152
		// Start offset: 0x8001D360
		// Variables:
	// 		struct LIGHT_6fake s; // stack offset -64
	// 		struct LIGHT_8fake *c; // $s1
	// 		struct LIGHT_8fake *f; // $v0
	// 		struct LIGHT_8fake co; // stack offset -48
	// 		long *blink; // $s2
	// 		short i; // $s0
	// 		short n; // $s6
	// 		short j; // $a1
	// 		short k; // $s3
	/* end block 1 */
	// End offset: 0x8001D4D8
	// End Line: 182

	/* begin block 2 */
		// Start line: 393
	/* end block 2 */
	// End Line: 394

void Light_IntplBlink(_ANIM_BLINK *ab,short coef)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  long *plVar6;
  int iVar7;
  uint uVar8;
  undefined4 in_t1;
  undefined4 in_t2;
  undefined4 in_t3;
  int iVar9;
  byte *pbVar10;
  long *plVar11;
  
  uVar5 = (uint)(ushort)coef;
  iVar9 = 0;
  plVar6 = ab->pblink;
  uVar1 = *(ushort *)plVar6;
  plVar11 = plVar6 + 1;
  if (0 < (short)*(ushort *)plVar6) {
    iVar3 = 1;
    uVar8 = uVar5;
    do {
      iVar7 = iVar9 << 0x10;
      iVar9 = iVar3 + 1;
      pbVar4 = (byte *)((int)plVar11 + ((iVar3 << 0x10) >> 0xe));
      pbVar10 = (byte *)((int)plVar11 + (iVar7 >> 0xe));
      SetFarColor((uint)*pbVar4,(uint)pbVar4[1],(uint)pbVar4[2]);
      if (((ab->color).pad & 1U) != 0) {
        uVar8 = uVar8 + 0x500;
        uVar5 = rsin((int)(uVar8 * 0x10000) >> 0x10);
      }
      setCopReg(2,in_t1,(uint)*pbVar10 << 4);
      setCopReg(2,in_t2,(uint)pbVar10[1] << 4);
      setCopReg(2,in_t3,(uint)pbVar10[2] << 4);
      setCopReg(2,0x4000,0x1000 - (int)(short)uVar5);
      copFunction(2,0x980011);
      uVar2 = getCopReg(2,0x16);
      iVar3 = 0;
      if (pbVar10[3] != 0) {
        do {
          iVar3 = iVar3 + 1;
          **(uint **)(((iVar9 << 0x10) >> 0xe) + (int)plVar11) = uVar2 & 0xffffff;
          iVar9 = iVar9 + 1;
        } while (iVar3 * 0x10000 >> 0x10 < (int)(uint)pbVar10[3]);
      }
      iVar3 = iVar9 + 1;
    } while (iVar9 << 0x10 < (int)((uint)uVar1 << 0x10));
  }
  SetFarColor((uint)(Pvl_File->fog).r,(uint)(Pvl_File->fog).g,(uint)(Pvl_File->fog).b);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Light_InitFile()
 // line 233, offset 0x8001d524
	/* begin block 1 */
		// Start line: 234
		// Start offset: 0x8001D524
		// Variables:
	// 		struct _LIGHT *l; // $s0
	// 		long i; // $s1
	/* end block 1 */
	// End offset: 0x8001D59C
	// End Line: 249

	/* begin block 2 */
		// Start line: 579
	/* end block 2 */
	// End Line: 580

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Light_InitFile(void)

{
  _LIGHT *l;
  int iVar1;
  
  Light_Special = -1;
  iVar1 = 0;
  l = Pvl_Lights;
  if (0 < Pvl_File->n_lights) {
    do {
      if (l->amb == '\x06') {
        Light_Special = iVar1;
      }
      Light_Constructor(l);
      iVar1 = iVar1 + 1;
      l = l + 1;
    } while (iVar1 < (int)Pvl_File->n_lights);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Light_DeleteFile()
 // line 252, offset 0x8001d5b4
	/* begin block 1 */
		// Start line: 253
		// Start offset: 0x8001D5B4
		// Variables:
	// 		struct _LIGHT *l; // $s1
	// 		long n; // $s0
	/* end block 1 */
	// End offset: 0x8001D604
	// End Line: 263

	/* begin block 2 */
		// Start line: 637
	/* end block 2 */
	// End Line: 638

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Light_DeleteFile(void)

{
  int iVar1;
  _LIGHT *p_Var2;
  
  iVar1 = (int)Pvl_File->n_lights;
  p_Var2 = Pvl_Lights;
  while (iVar1 != 0) {
    if (p_Var2->handle != (TASK *)0x0) {
      Task_Kill(p_Var2->handle);
    }
    iVar1 = iVar1 + -1;
    p_Var2 = p_Var2 + 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Light_Constructor(struct _LIGHT *l /*$s0*/)
 // line 266, offset 0x8001d618
	/* begin block 1 */
		// Start line: 667
	/* end block 1 */
	// End Line: 668

void Light_Constructor(_LIGHT *l)

{
  TASK *pTVar1;
  _ANIM_BLINK *p_Var2;
  
  if (l->amb != '\0') {
    Light_AmbianceAdd(l);
  }
  if ((int)l->blink < 0) {
    l->blink = (_ANIM_BLINK *)0x0;
  }
  else {
    p_Var2 = Pvl_AnimBlinks + (int)l->blink;
    l->blink = p_Var2;
    p_Var2->pblink = Pvl_Blinks + (int)p_Var2->pblink;
    if (*l->blink->pblink == 0) {
      l->blink->pblink = (long *)0x0;
    }
    pTVar1 = Task_Link(Light_Blink,0x100);
    l->handle = pTVar1;
    *(_LIGHT **)&pTVar1->local = l;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Light_Add(struct _LIGHT *l /*$a0*/)
 // line 293, offset 0x8001d6cc
	/* begin block 1 */
		// Start line: 722
	/* end block 1 */
	// End Line: 723

void Light_Add(_LIGHT *l)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Light_Delete(struct _LIGHT *l /*$a0*/)
 // line 298, offset 0x8001d6d4
	/* begin block 1 */
		// Start line: 732
	/* end block 1 */
	// End Line: 733

void Light_Delete(_LIGHT *l)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Light_SetIdentity()
 // line 303, offset 0x8001d6dc
	/* begin block 1 */
		// Start line: 304
		// Start offset: 0x8001D6DC
		// Variables:
	// 		struct LIGHT_5fake ml; // stack offset -40
	/* end block 1 */
	// End offset: 0x8001D6DC
	// End Line: 304

	/* begin block 2 */
		// Start line: 741
	/* end block 2 */
	// End Line: 742

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Light_SetIdentity(void)

{
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  Matrix_Clear((MISC_5fake *)&local_28);
  setCopControlWord(2,0x4000,local_28);
  setCopControlWord(2,0x4800,local_24);
  setCopControlWord(2,0x5000,local_20);
  setCopControlWord(2,0x5800,local_1c);
  setCopControlWord(2,0x6000,local_18);
  setCopControlWord(2,0x8000,local_28);
  setCopControlWord(2,0x8800,local_24);
  setCopControlWord(2,0x9000,local_20);
  setCopControlWord(2,0x9800,local_1c);
  setCopControlWord(2,0xa000,local_18);
  SetBackColor(0x80,0x80,0x80);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Light_SetMatrix(struct _D3_OBJECT *o /*$s4*/)
 // line 316, offset 0x8001d760
	/* begin block 1 */
		// Start line: 317
		// Start offset: 0x8001D760
		// Variables:
	// 		long d; // $s1
	// 		long i; // $s6
	// 		long xo; // stack offset -48
	// 		long yo; // $fp
	// 		long zo; // $s7
	// 		long fatt; // $s2
	// 		short t; // $v0
	// 		struct _LIGHT *l; // $s0
	// 		struct _LIGHT (*ls[3]); // stack offset -112
	// 		struct LIGHT_7fake dif; // stack offset -96
	// 		struct LIGHT_7fake color; // stack offset -88
	// 		struct LIGHT_6fake vec; // stack offset -80
	// 		struct LIGHT_6fake vecsq; // stack offset -64
	/* end block 1 */
	// End offset: 0x8001DB6C
	// End Line: 395

	/* begin block 2 */
		// Start line: 767
	/* end block 2 */
	// End Line: 768

/* WARNING: Could not reconcile some variable overlaps */

void Light_SetMatrix(_D3_OBJECT *o)

{
  short t;
  uint uVar1;
  int iVar2;
  undefined4 in_t1;
  undefined4 in_t2;
  undefined4 in_t3;
  _LIGHT *p_Var3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  _LIGHT *local_70 [4];
  short local_60;
  short local_5e;
  short local_5c;
  undefined4 local_58;
  undefined4 local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_40;
  int local_3c;
  int local_38;
  int local_30;
  
  iVar7 = 0;
  iVar6 = 0;
  iVar5 = 0;
  uVar1 = (int)(o->b_box).vx + (int)*(short *)&o->b_step;
  local_30 = (int)(o->pos).vx + ((int)(uVar1 + (uVar1 >> 0x1f)) >> 1);
  uVar1 = (int)(o->b_box).vy + (int)*(short *)((int)&o->b_sunk + 2);
  iVar9 = (int)(o->pos).vy + ((int)(uVar1 + (uVar1 >> 0x1f)) >> 1);
  uVar1 = (int)(o->b_box).vz + (int)*(short *)&o[1].prec;
  iVar8 = (int)(o->pos).vz + ((int)(uVar1 + (uVar1 >> 0x1f)) >> 1);
  t = Light_GetNearIndices
                ((short)((uint)(local_30 * 0x10000) >> 0x10),
                 (short)((uint)(iVar9 * 0x10000) >> 0x10),(short)((uint)(iVar8 * 0x10000) >> 0x10));
  o->matrices[1].pad = t;
  Light_GetNearLights(t,local_70);
  do {
    p_Var3 = local_70[iVar7];
    if (p_Var3 == (_LIGHT *)0x0) {
      *(undefined2 *)((int)o->matrices[1].m + iVar5) = 0;
      *(undefined2 *)((int)o->matrices[1].m + iVar5 + 6) = 0;
      *(undefined2 *)((int)o->matrices[1].m + iVar5 + 0xc) = 0;
    }
    else {
      local_50 = (int)(p_Var3->pos).vx - local_30;
      local_4c = (int)(p_Var3->pos).vy - iVar9;
      local_48 = (int)(p_Var3->pos).vz - iVar8;
      setCopReg(2,in_t1,local_50);
      setCopReg(2,in_t2,local_4c);
      setCopReg(2,in_t3,local_48);
      copFunction(2,0xa00428);
      local_40 = getCopReg(2,0x19);
      local_3c = getCopReg(2,0x1a);
      local_38 = getCopReg(2,0x1b);
      uVar1 = SquareRoot0(local_40 + local_3c + local_38);
      if ((int)uVar1 < 1) {
        uVar1 = 1;
      }
      iVar2 = (int)p_Var3->fall_on;
      iVar4 = 0x1000;
      if (iVar2 < (int)uVar1) {
        if ((int)uVar1 < (int)p_Var3->fall_off) {
          iVar4 = (uVar1 - iVar2) * 0x1000;
          iVar2 = (int)p_Var3->fall_off - iVar2;
          if (iVar2 == 0) {
            trap(0x1c00);
          }
          if ((iVar2 == -1) && (iVar4 == -0x80000000)) {
            trap(0x1800);
          }
          iVar4 = 0x1000 - iVar4 / iVar2;
        }
        else {
          iVar4 = 0;
        }
      }
      local_58 = *(undefined4 *)&p_Var3->color;
      in_t1 = *(undefined4 *)&(p_Var3->color).vz;
      local_54 = in_t1;
      if (p_Var3->blink != (_ANIM_BLINK *)0x0) {
        local_60 = (p_Var3->blink->color).vx - (p_Var3->color).vx;
        local_5e = (p_Var3->blink->color).vy - (p_Var3->color).vy;
        local_5c = (p_Var3->blink->color).vz - (p_Var3->color).vz;
        local_54 = in_t1;
        gteMIMefunc(&local_58,(uint *)&local_60,1,0x1000 - (int)(p_Var3->color).pad);
      }
      iVar2 = iVar4 * (int)(o->b_box).pad >> 0xc;
      *(undefined2 *)((int)o->matrices[1].m + iVar5) = (short)((int)(short)local_58 * iVar2 >> 0xc);
      *(undefined2 *)((int)o->matrices[1].m + iVar5 + 6) =
           (short)((int)local_58._2_2_ * iVar2 >> 0xc);
      *(undefined2 *)((int)o->matrices[1].m + iVar5 + 0xc) =
           (short)((int)(short)local_54 * iVar2 >> 0xc);
      if (uVar1 == 0) {
        trap(0x1c00);
      }
      if ((uVar1 == 0xffffffff) && (local_50 << 0xc == -0x80000000)) {
        trap(0x1800);
      }
      if (uVar1 == 0) {
        trap(0x1c00);
      }
      if ((uVar1 == 0xffffffff) && (local_4c << 0xc == -0x80000000)) {
        trap(0x1800);
      }
      if (uVar1 == 0) {
        trap(0x1c00);
      }
      if ((uVar1 == 0xffffffff) && (local_48 << 0xc == -0x80000000)) {
        trap(0x1800);
      }
      local_50._0_2_ = (undefined2)((local_50 << 0xc) / (int)uVar1);
      *(undefined2 *)((int)o->matrices->m + iVar6) = (undefined2)local_50;
      local_4c._0_2_ = (undefined2)((local_4c << 0xc) / (int)uVar1);
      *(undefined2 *)((int)o->matrices->m + iVar6 + 2) = (undefined2)local_4c;
      local_48._0_2_ = (undefined2)((local_48 << 0xc) / (int)uVar1);
      *(undefined2 *)((int)o->matrices->m + iVar6 + 4) = (undefined2)local_48;
    }
    iVar6 = iVar6 + 6;
    iVar7 = iVar7 + 1;
    iVar5 = iVar5 + 2;
  } while (iVar7 < 3);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Light_SetLocalMatrix(struct _D3_OBJECT *o /*$s0*/)
 // line 398, offset 0x8001db9c
	/* begin block 1 */
		// Start line: 399
		// Start offset: 0x8001DB9C
		// Variables:
	// 		short i; // $a3
	// 		struct _ROTMATRIX m; // stack offset -80
	// 		struct _LIGHT *l; // $a2
	// 		struct _LIGHT (*ls[3]); // stack offset -56
	// 		struct LIGHT_5fake matrix; // stack offset -40
	/* end block 1 */
	// End offset: 0x8001DD30
	// End Line: 435

	/* begin block 2 */
		// Start line: 1061
	/* end block 2 */
	// End Line: 1062

/* WARNING: Type propagation algorithm not settling */

void Light_SetLocalMatrix(_D3_OBJECT *o)

{
  int iVar1;
  _ROTMATRIX *p_Var2;
  int iVar3;
  _LIGHT *p_Var4;
  int iVar5;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  _LIGHT *local_44 [15];
  
  p_Var2 = o->matrices;
  if (p_Var2[1].pad == 0x7fff) {
    setCopControlWord(2,0x8000,*(undefined4 *)p_Var2[1].m);
    setCopControlWord(2,0x8800,*(undefined4 *)(p_Var2[1].m + 2));
    setCopControlWord(2,0x9000,*(undefined4 *)(p_Var2[1].m + 4));
    setCopControlWord(2,0x9800,*(undefined4 *)(p_Var2[1].m + 6));
    setCopControlWord(2,0xa000,*(undefined4 *)(p_Var2[1].m + 8));
  }
  else {
    Light_GetNearLights(p_Var2[1].pad,local_44 + 3);
    iVar5 = 0;
    iVar1 = 0;
    do {
      iVar1 = iVar1 >> 0x10;
      p_Var4 = local_44[iVar1 + 3];
      iVar3 = iVar1 * 2;
      if (p_Var4 == (_LIGHT *)0x0) {
        iVar3 = iVar1 * 2;
        *(short *)((int)&local_50 + iVar3) = o->matrices[1].m[iVar1];
        *(short *)(&local_4c + iVar3 + 2) = o->matrices[1].m[iVar1 + 3];
        *(short *)((int)local_44 + iVar3) = o->matrices[1].m[iVar1 + 6];
      }
      else {
        *(short *)((int)&local_50 + iVar3) =
             (short)((int)o->matrices[1].m[iVar1] * (int)(p_Var4->color).pad >> 0xc);
        *(short *)(&local_4c + iVar3 + 2) =
             (short)((int)o->matrices[1].m[iVar1 + 3] * (int)(p_Var4->color).pad >> 0xc);
        *(short *)((int)local_44 + iVar3) =
             (short)((int)o->matrices[1].m[iVar1 + 6] * (int)(p_Var4->color).pad >> 0xc);
      }
      iVar5 = iVar5 + 1;
      iVar1 = iVar5 * 0x10000;
    } while (iVar5 * 0x10000 >> 0x10 < 3);
    setCopControlWord(2,0x8000,local_50);
    setCopControlWord(2,0x8800,local_4c);
    setCopControlWord(2,0x9000,local_48);
    setCopControlWord(2,0x9800,local_44[0]);
    setCopControlWord(2,0xa000,local_44[1]);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Light_RotMatrix(struct _D3_OBJECT *o /*$a3*/, struct LIGHT_5fake *m /*$a1*/)
 // line 438, offset 0x8001dd40
	/* begin block 1 */
		// Start line: 439
		// Start offset: 0x8001DD40
		// Variables:
	// 		struct LIGHT_7fake sv; // stack offset -24
	// 		struct LIGHT_6fake v; // stack offset -16
	// 		short i; // $a2
	/* end block 1 */
	// End offset: 0x8001DE00
	// End Line: 494

	/* begin block 2 */
		// Start line: 1157
	/* end block 2 */
	// End Line: 1158

void Light_RotMatrix(_D3_OBJECT *o,undefined m)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 in_zero;
  undefined4 in_at;
  int iVar4;
  undefined2 *puVar5;
  undefined3 in_register_00000015;
  int iVar6;
  undefined4 local_18;
  uint local_14;
  undefined2 local_10;
  undefined2 local_c;
  undefined2 local_8;
  
  iVar6 = 0;
  do {
    iVar4 = (int)(short)iVar6;
    local_18 = CONCAT22(o->matrices->m[iVar4 * 3 + 1],o->matrices->m[iVar4 * 3]);
    local_14 = local_14 & 0xffff0000 | (uint)(ushort)o->matrices->m[iVar4 * 3 + 2];
    setCopReg(2,in_zero,local_18);
    setCopReg(2,in_at,local_14);
    copFunction(2,0x486012);
    uVar1 = getCopReg(2,0x19);
    uVar2 = getCopReg(2,0x1a);
    uVar3 = getCopReg(2,0x1b);
    local_10 = (undefined2)uVar1;
    puVar5 = (undefined2 *)(CONCAT31(in_register_00000015,m) + iVar4 * 6);
    *puVar5 = local_10;
    local_c = (undefined2)uVar2;
    puVar5[1] = local_c;
    iVar6 = iVar6 + 1;
    local_8 = (undefined2)uVar3;
    puVar5[2] = local_8;
  } while (iVar6 * 0x10000 >> 0x10 < 3);
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ Light_GetNearIndices(short x0 /*$s6*/, short y0 /*$s1*/, short z0 /*$s4*/)
 // line 501, offset 0x8001de08
	/* begin block 1 */
		// Start line: 502
		// Start offset: 0x8001DE08
		// Variables:
	// 		long x; // $a3
	// 		long y; // $v1
	// 		long z; // $t1
	// 		long w; // $t0
	// 		long h; // $a2
	// 		long t; // $s2

		/* begin block 1.1 */
			// Start line: 532
			// Start offset: 0x8001DFF8
			// Variables:
		// 		struct _LIGHT *l; // $s0
		// 		long d; // $s3

			/* begin block 1.1.1 */
				// Start line: 540
				// Start offset: 0x8001E048
				// Variables:
			// 		struct _LIGHT (*ls[3]); // stack offset -48
			// 		long i; // $s0
			/* end block 1.1.1 */
			// End offset: 0x8001E0D4
			// End Line: 565
		/* end block 1.1 */
		// End offset: 0x8001E0D4
		// End Line: 566
	/* end block 1 */
	// End offset: 0x8001E0DC
	// End Line: 569

	/* begin block 2 */
		// Start line: 1302
	/* end block 2 */
	// End Line: 1303

short Light_GetNearIndices(short x0,short y0,short z0)

{
  ushort t;
  bool bVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  _LIGHT **pp_Var5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  _LIGHT *p_Var12;
  _LIGHT *local_30 [4];
  
  iVar2 = (int)((uint)(ushort)z0 << 0x10) >> 0x10;
  iVar10 = ((iVar2 / 200 + (iVar2 >> 0x1f)) - ((int)((uint)(ushort)z0 << 0x10) >> 0x1f)) * 0x10000
           >> 0x10;
  uVar8 = SEXT24(Pvl_File->map_h);
  uVar7 = (uint)(ushort)Pvl_File->map_w << 0x10;
  iVar2 = (int)((uint)(ushort)x0 << 0x10) >> 0x10;
  iVar9 = (int)uVar7 >> 0x10;
  if (iVar2 < 0) {
    iVar2 = (iVar2 + -99) / 100;
  }
  else {
    iVar2 = ((iVar2 / 100 + (iVar2 >> 0x1f)) - ((int)((uint)(ushort)x0 << 0x10) >> 0x1f)) * 0x10000
            >> 0x10;
  }
  iVar6 = (int)((uint)(ushort)y0 << 0x10) >> 0x10;
  iVar2 = iVar2 + ((int)(iVar9 + (uVar7 >> 0x1f)) >> 1);
  if (iVar6 < 0) {
    iVar6 = (iVar6 + -99) / 100;
  }
  else {
    iVar6 = ((iVar6 / 100 + (iVar6 >> 0x1f)) - ((int)((uint)(ushort)y0 << 0x10) >> 0x1f)) * 0x10000
            >> 0x10;
  }
  iVar6 = iVar6 + ((int)(uVar8 + (uVar8 >> 0x1f)) >> 1);
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  if (iVar9 <= iVar2) {
    iVar2 = iVar9 + -1;
  }
  bVar1 = iVar6 < (int)uVar8;
  if (iVar6 < 0) {
    iVar6 = 0;
    bVar1 = 0 < (int)uVar8;
  }
  if (!bVar1) {
    iVar6 = uVar8 - 1;
  }
  iVar11 = iVar10;
  if (iVar10 < 0) {
    iVar11 = 0;
  }
  if (7 < iVar10) {
    iVar11 = 7;
  }
  t = Pvl_SortLights[iVar11 * iVar9 * uVar8 + iVar6 * iVar9 + iVar2];
  if (-1 < Light_Special) {
    p_Var12 = Pvl_Lights + Light_Special;
    lVar3 = Distance3D((int)(p_Var12->pos).vx,(int)(p_Var12->pos).vy,(int)(p_Var12->pos).vz,(int)x0,
                       (int)y0,(int)z0);
    if (lVar3 < (int)p_Var12->fall_off) {
      Light_GetNearLights(t,local_30);
      iVar2 = 0;
      pp_Var5 = local_30;
      do {
        if (*pp_Var5 == (_LIGHT *)0x0) {
          uVar7 = iVar2 * 5;
          goto LAB_8001df04;
        }
        iVar2 = iVar2 + 1;
        pp_Var5 = pp_Var5 + 1;
      } while (iVar2 < 3);
      iVar2 = 0;
      iVar9 = 0;
      do {
        iVar10 = *(int *)((int)local_30 + iVar9);
        lVar4 = Distance3D((int)*(short *)(iVar10 + 0x18),(int)*(short *)(iVar10 + 0x1a),
                           (int)*(short *)(iVar10 + 0x1c),(int)x0,(int)y0,(int)z0);
        uVar7 = iVar9 + iVar2;
        if (lVar3 < lVar4) {
LAB_8001df04:
          return t & ~(ushort)(0x1f << (uVar7 & 0x1f)) | (ushort)(Light_Special << (uVar7 & 0x1f));
        }
        iVar2 = iVar2 + 1;
        iVar9 = iVar2 * 4;
      } while (iVar2 < 3);
    }
  }
  return (short)t;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Light_GetNearLights(short t /*$a0*/, struct _LIGHT **l /*$a1*/)
 // line 571, offset 0x8001e104
	/* begin block 1 */
		// Start line: 1510
	/* end block 1 */
	// End Line: 1511

void Light_GetNearLights(short t,_LIGHT **l)

{
  uint uVar1;
  
  l[2] = (_LIGHT *)0x0;
  l[1] = (_LIGHT *)0x0;
  *l = (_LIGHT *)0x0;
  if (((uint)(ushort)t & 0x1f) != 0x1f) {
    *l = Pvl_Lights + ((uint)(ushort)t & 0x1f);
  }
  uVar1 = (int)((uint)(ushort)t << 0x10) >> 0x15 & 0x1f;
  if (uVar1 != 0x1f) {
    l[1] = Pvl_Lights + uVar1;
  }
  uVar1 = (int)((uint)(ushort)t << 0x10) >> 0x1a & 0x1f;
  if (uVar1 != 0x1f) {
    l[2] = Pvl_Lights + uVar1;
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Light_IsVisible(struct _LIGHT *l /*$s0*/, struct LIGHT_7fake *pos /*$v0*/)
 // line 585, offset 0x8001e184
	/* begin block 1 */
		// Start line: 586
		// Start offset: 0x8001E184
		// Variables:
	// 		long i; // $a0
	// 		struct _LIGHT (*ls[3]); // stack offset -24
	/* end block 1 */
	// End offset: 0x8001E1E4
	// End Line: 602

	/* begin block 2 */
		// Start line: 1537
	/* end block 2 */
	// End Line: 1538

long Light_IsVisible(_LIGHT *l,undefined pos)

{
  short t;
  _LIGHT **pp_Var1;
  int iVar2;
  undefined3 in_register_00000015;
  short *psVar3;
  _LIGHT *ap_Stack24 [3];
  _LIGHT *local_c;
  
  psVar3 = (short *)CONCAT31(in_register_00000015,pos);
  t = Light_GetNearIndices(*psVar3,psVar3[1],psVar3[2]);
  Light_GetNearLights(t,ap_Stack24);
  iVar2 = 3;
  pp_Var1 = &local_c;
  do {
    if (l == *pp_Var1) {
      return 1;
    }
    iVar2 = iVar2 + -1;
    pp_Var1 = pp_Var1 + -1;
  } while (iVar2 != 0);
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Light_AmbianceAdd(struct _LIGHT *l /*$a0*/)
 // line 608, offset 0x8001e1f4
	/* begin block 1 */
		// Start line: 1585
	/* end block 1 */
	// End Line: 1586

void Light_AmbianceAdd(_LIGHT *l)

{
  short effect;
  
  switch(l->amb) {
  case '\x01':
  case '\x03':
  case '\x05':
    Weather_Add(l);
    return;
  case '\x02':
    effect = 0;
    break;
  case '\x04':
    effect = 1;
    break;
  default:
    goto switchD_8001e228_caseD_5;
  }
  Light_AddEffect(l,effect);
switchD_8001e228_caseD_5:
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Light_AddEffect(struct _LIGHT *l /*$s1*/, short effect /*$a1*/)
 // line 627, offset 0x8001e264
	/* begin block 1 */
		// Start line: 1623
	/* end block 1 */
	// End Line: 1624

void Light_AddEffect(_LIGHT *l,short effect)

{
  TASK *pTVar1;
  
  pTVar1 = Task_Link(Light_FlareTask,0);
  l->handle = pTVar1;
  *(_LIGHT **)&pTVar1->local = l;
  l->handle->s0 = (int)effect;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Light_FlareTask()
 // line 671, offset 0x8001e2b8
	/* begin block 1 */
		// Start line: 672
		// Start offset: 0x8001E2B8
		// Variables:
	// 		struct _LIGHT *l; // $a0
	/* end block 1 */
	// End offset: 0x8001E2F4
	// End Line: 684

	/* begin block 2 */
		// Start line: 1715
	/* end block 2 */
	// End Line: 1716

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Light_FlareTask(void)

{
  TASK *pTVar1;
  
  pTVar1 = TaskCurrent;
  *(undefined2 *)((int)TaskCurrent->local + 0x1e) = *(undefined2 *)&TaskCurrent->s0;
  pTVar1->display = Light_DisplayFlare;
  do {
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Light_DisplayFlare()
 // line 686, offset 0x8001e2f4
	/* begin block 1 */
		// Start line: 687
		// Start offset: 0x8001E2F4
		// Variables:
	// 		struct _LIGHT *l; // $s2
	// 		struct LIGHT_31fake Glow[2]; // stack offset -1856
	// 		struct LIGHT_31fake Flares[2][18]; // stack offset -1776
	// 		struct LIGHT_31fake *p; // $s1
	// 		struct LIGHT_5fake mr; // stack offset -336
	// 		struct LIGHT_6fake d[4]; // stack offset -304
	// 		struct LIGHT_7fake angle; // stack offset -240
	// 		struct LIGHT_7fake dummy; // stack offset -232
	// 		struct _D3_OBJECT obj; // stack offset -224
	// 		struct LIGHT_70fake shp; // stack offset -56
	// 		long z; // stack offset -36
	// 		long f; // stack offset -32
	// 		long mode; // $s0
	// 		short i; // $t1
	// 		short w; // stack offset -40
	// 		short h; // stack offset -38
	/* end block 1 */
	// End offset: 0x8001E75C
	// End Line: 754

	/* begin block 2 */
		// Start line: 1745
	/* end block 2 */
	// End Line: 1746

/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Light_DisplayFlare(void)

{
  short sVar1;
  void *prim;
  _SCREEN *p_Var2;
  undefined4 in_zero;
  undefined4 in_at;
  undefined4 uVar3;
  long lVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  _LIGHT *l;
  int iVar8;
  int iVar9;
  undefined4 local_150;
  undefined4 local_14c;
  undefined4 local_148;
  undefined4 local_144;
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined2 local_130 [4];
  undefined4 local_128 [2];
  undefined2 local_120;
  undefined2 local_11c;
  undefined2 local_110;
  undefined2 local_10c;
  undefined2 local_100;
  undefined2 local_fc;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined local_e8 [4];
  undefined4 local_e4;
  undefined4 local_b4;
  undefined4 local_b0;
  void *local_38;
  short local_34;
  undefined4 local_30;
  short local_28;
  short sStack38;
  int local_24;
  
  l = (_LIGHT *)TaskCurrent->local;
  memset(&local_f0,0,8);
  memset(local_e8,0,8);
  sVar1 = (l->pos).pad;
  local_38 = Effects_Pcl;
  local_34 = 0xe6;
  Shp_GetWH((SHAPE_68fake *)&local_38,&local_28,&sStack38);
  prim = Main_Prims;
  local_b4 = *(undefined4 *)&l->pos;
  local_b0 = *(undefined4 *)&(l->pos).vz;
  setCopReg(2,in_zero,*(undefined4 *)&l->pos);
  setCopReg(2,in_at,*(undefined4 *)&(l->pos).vz);
  copFunction(2,0x180001);
  local_30 = getCopReg(2,0xe);
  local_24 = getCopReg(2,0x9800);
  local_24 = local_24 >> 2;
  if ((0 < local_24) && (local_24 < (int)Scr_OtSize)) {
    Main_Prims = (void *)((int)Main_Prims + 0x28);
    uVar3 = 0x800b0000;
    if ((sVar1 != 0) && (lVar4 = Light_IsVisible(l,0x68), lVar4 != 0)) {
      Light_DisplayRemanence((char)Main_Prims,(short)local_30,local_30._2_2_);
    }
    Shp_SetPolyFT4((SHAPE_31fake *)prim,(SHAPE_68fake *)&local_38,0x32,0x32);
    *(byte *)((int)prim + 7) = *(byte *)((int)prim + 7) & 0xfe;
    local_ec = (uint)local_ec._2_2_ << 0x10;
    setCopReg(2,in_zero,local_f0);
    setCopReg(2,uVar3,local_ec);
    copFunction(2,0x486012);
    local_13c = getCopReg(2,0x19);
    local_138 = getCopReg(2,0x1a);
    local_134 = getCopReg(2,0x1b);
    local_ec = CONCAT22(local_ec._2_2_,
                        ((short)((int)(((int)((uint)(ushort)Scr_W << 0x10) >> 0x10) +
                                      (((uint)(ushort)Scr_W << 0x10) >> 0x1f)) >> 1) -
                        (short)local_30) * 5);
    RotMatrix((short *)&local_f0,(undefined2 *)&local_150);
    setCopControlWord(2,0x2800,local_13c);
    setCopControlWord(2,0x3000,local_138);
    setCopControlWord(2,0x3800,local_134);
    setCopControlWord(2,0,local_150);
    setCopControlWord(2,0x800,local_14c);
    setCopControlWord(2,0x1000,local_148);
    setCopControlWord(2,0x1800,local_144);
    setCopControlWord(2,0x2000,local_140);
    iVar7 = 0;
    do {
      iVar5 = (int)(short)iVar7;
      iVar8 = (int)(short)(&Tab_Glow)[iVar5 * 4] * (int)local_28 * (int)Scr_GeomScreen;
      if (local_24 == 0) {
        trap(0x1c00);
      }
      if ((local_24 == -1) && (iVar8 == -0x80000000)) {
        trap(0x1800);
      }
      iVar9 = (int)*(short *)(&PTR_DAT_800ad2ea + iVar5 * 2) * (int)local_28 * (int)Scr_GeomScreen;
      if (local_24 == 0) {
        trap(0x1c00);
      }
      if ((local_24 == -1) && (iVar9 == -0x80000000)) {
        trap(0x1800);
      }
      setCopReg(2,in_zero,iVar8 / local_24 & 0xffffU | iVar9 / local_24 << 0x10);
      setCopReg(2,0x80000000,local_e4);
      copFunction(2,0x480012);
      piVar6 = (int *)(local_130 + iVar5 * 8);
      iVar8 = getCopReg(2,0x19);
      *piVar6 = iVar8;
      uVar3 = getCopReg(2,0x1a);
      *(undefined4 *)(local_130[2] + iVar5 * 8) = uVar3;
      uVar3 = getCopReg(2,0x1b);
      local_128[iVar5 * 4] = uVar3;
      getCopControlWord(2,0xf800);
      *piVar6 = *piVar6 + (int)(short)local_30;
      iVar7 = iVar7 + 1;
      *(int *)(local_130[2] + iVar5 * 8) = *(int *)(local_130[2] + iVar5 * 8) + (int)local_30._2_2_;
    } while (iVar7 * 0x10000 >> 0x10 < 4);
    *(undefined2 *)((int)prim + 8) = local_130[0];
    *(undefined2 *)((int)prim + 10) = local_130[2];
    *(undefined2 *)((int)prim + 0x10) = local_120;
    *(undefined2 *)((int)prim + 0x12) = local_11c;
    *(undefined2 *)((int)prim + 0x18) = local_110;
    *(undefined2 *)((int)prim + 0x1a) = local_10c;
    *(undefined2 *)((int)prim + 0x20) = local_100;
    *(undefined2 *)((int)prim + 0x22) = local_fc;
    *(undefined *)((int)prim + 4) = *(undefined *)&(l->color).vx;
    *(undefined *)((int)prim + 5) = *(undefined *)&(l->color).vy;
    *(undefined *)((int)prim + 6) = *(undefined *)&(l->color).vz;
    p_Var2 = Scr;
    *(uint *)prim = *(uint *)prim & 0xff000000 | Scr->ot[local_24] & 0xffffff;
    p_Var2->ot[local_24] = p_Var2->ot[local_24] & 0xff000000 | (uint)prim & 0xffffff;
    setCopControlWord(2,0x2800,Cam_Matrix.t[0]);
    setCopControlWord(2,0x3000,Cam_Matrix.t[1]);
    setCopControlWord(2,0x3800,Cam_Matrix.t[2]);
    setCopControlWord(2,0,Cam_Matrix.m[0]._0_4_);
    setCopControlWord(2,0x800,Cam_Matrix.m._4_4_);
    setCopControlWord(2,0x1000,Cam_Matrix.m[1]._2_4_);
    setCopControlWord(2,0x1800,Cam_Matrix.m[2]._0_4_);
    setCopControlWord(2,0x2000,Cam_Matrix._16_4_);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Light_DisplayRemanence(struct LIGHT_31fake *prim /*$a0*/, short x /*$a1*/, short y /*$a2*/)
 // line 756, offset 0x8001e778
	/* begin block 1 */
		// Start line: 757
		// Start offset: 0x8001E778
		// Variables:
	// 		struct LIGHT_31fake *pft4; // $s2
	// 		struct LIGHT_8fake *col; // $v1
	// 		struct LIGHT_70fake shp; // stack offset -56
	// 		short i; // $s3
	// 		short w; // $a0
	// 		short cx; // $s6
	// 		short cy; // $s5
	/* end block 1 */
	// End offset: 0x8001EA20
	// End Line: 797

	/* begin block 2 */
		// Start line: 1953
	/* end block 2 */
	// End Line: 1954

void Light_DisplayRemanence(undefined prim,short x,short y)

{
  uchar uVar1;
  ushort w;
  _SCREEN *p_Var2;
  SHAPE_31fake *pSVar3;
  short sVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined3 in_register_00000011;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  uchar *puVar15;
  SHAPE_31fake *prim_00;
  int iVar16;
  SHAPE_68fake local_38;
  
  prim_00 = (SHAPE_31fake *)CONCAT31(in_register_00000011,prim);
  uVar5 = (uint)(ushort)Scr_W;
  uVar7 = (uint)(ushort)Scr_H;
  iVar11 = (int)x;
  iVar12 = (int)(uVar5 << 0x10) >> 0x10;
  iVar10 = (int)(uVar7 << 0x10) >> 0x10;
  pSVar3 = (SHAPE_31fake *)Main_Prims;
  if ((((-1 < iVar11) && (pSVar3 = (SHAPE_31fake *)Main_Prims, iVar11 <= iVar12)) &&
      (iVar8 = (int)y, pSVar3 = (SHAPE_31fake *)Main_Prims, -1 < iVar8)) &&
     (iVar16 = 0, pSVar3 = (SHAPE_31fake *)Main_Prims, iVar8 <= iVar10)) {
    puVar15 = &prim_00->v3;
    local_38.file = Effects_Pcl;
    do {
      iVar14 = (int)(short)iVar16 * 4;
      local_38.shape = (&Tab_Flares)[(int)(short)iVar16 * 4];
      sVar4 = (short)(iVar12 + ((uVar5 << 0x10) >> 0x1f) >> 1);
      iVar6 = (int)(&Tab_Flares)[iVar14 + 2];
      iVar9 = (iVar11 - (int)sVar4) * 10;
      if (iVar6 == 0) {
        trap(0x1c00);
      }
      if ((iVar6 == -1) && (iVar9 == -0x80000000)) {
        trap(0x1800);
      }
      w = (&Tab_Flares)[iVar14 + 1];
      local_38.y = (short)((int)(((int)((uint)w << 0x10) >> 0x10) + (((uint)w << 0x10) >> 0x1f)) >>
                          1);
      local_38.x = (sVar4 + (short)(iVar9 / iVar6)) - local_38.y;
      sVar4 = (short)(iVar10 + ((uVar7 << 0x10) >> 0x1f) >> 1);
      iVar9 = (int)(&Tab_Flares)[iVar14 + 2];
      iVar6 = (iVar8 - (int)sVar4) * 10;
      if (iVar9 == 0) {
        trap(0x1c00);
      }
      if ((iVar9 == -1) && (iVar6 == -0x80000000)) {
        trap(0x1800);
      }
      local_38.y = (sVar4 + (short)(iVar6 / iVar9)) - local_38.y;
      Shp_SetPolyFT4(prim_00,&local_38,w,w);
      iVar16 = iVar16 + 1;
      puVar15[-0x1e] = puVar15[-0x1e] & 0xfe;
      iVar6 = (int)(&Tab_Flares)[iVar14 + 3] * 4;
      puVar15[-0x21] = (&Tab_Col)[iVar6];
      puVar15[-0x20] = (&DAT_800a6921)[iVar6];
      uVar1 = (&DAT_800a6922)[iVar6];
      puVar15[-0x11] = puVar15[-0x11] + '\x01';
      puVar15[-1] = puVar15[-1] + '\x01';
      puVar15[-0x1f] = uVar1;
      puVar15[-8] = puVar15[-8] + '\x01';
      *puVar15 = *puVar15 + '\x01';
      p_Var2 = Scr;
      puVar15 = puVar15 + 0x28;
      prim_00->tag = prim_00->tag & 0xff000000 | Scr->ot[1] & 0xffffff;
      uVar13 = (uint)prim_00 & 0xffffff;
      prim_00 = prim_00 + 1;
      p_Var2->ot[1] = p_Var2->ot[1] & 0xff000000 | uVar13;
      pSVar3 = prim_00;
    } while (iVar16 * 0x10000 >> 0x10 < 0x12);
  }
  Main_Prims = pSVar3;
  return;
}





