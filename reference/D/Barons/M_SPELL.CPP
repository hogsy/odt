#include "THISDUST.H"
#include "M_SPELL.H"


// decompiled code
// original method signature: 
// unsigned long /*$ra*/ MSpell_TestAppliedOnObject(struct _D3_OBJECT *D3Obj /*$a0*/, long index /*$a1*/)
 // line 17, offset 0x800817c4
	/* begin block 1 */
		// Start line: 19
		// Start offset: 0x800817C4
		// Variables:
	// 		struct _MONSTER *monst; // $v1
	/* end block 1 */
	// End offset: 0x80081864
	// End Line: 36

	/* begin block 2 */
		// Start line: 39
	/* end block 2 */
	// End Line: 40

ulong MSpell_TestAppliedOnObject(_D3_OBJECT *D3Obj,long index)

{
  uint uVar1;
  
  uVar1 = index & 0xff;
  if ((D3Obj == (_D3_OBJECT *)0x0) || (((int)D3Obj->collision_mode & 0x8000U) == 0)) {
    return 0;
  }
  if (((uVar1 == 2) || (((1 < uVar1 && (uVar1 < 0x11)) && (0xe < uVar1)))) &&
     ((D3Obj->display_mode & 0x40U) == 0)) {
    return 0;
  }
  return 4 - (uint)*(byte *)((int)MSpell_Conversion[(uint)(byte)(&PSpells)[uVar1].element] +
                             *(int *)&D3Obj[1].last_pos + 0x142);
}



// decompiled code
// original method signature: 
// long /*$ra*/ MSpell_AppliedOnObject(struct _D3_OBJECT *D3Obj /*$a0*/, long index /*$a2*/)
 // line 39, offset 0x8008186c
	/* begin block 1 */
		// Start line: 40
		// Start offset: 0x8008186C
		// Variables:
	// 		struct _MONSTER *monst; // $a3
	/* end block 1 */
	// End offset: 0x80081924
	// End Line: 63

	/* begin block 2 */
		// Start line: 79
	/* end block 2 */
	// End Line: 80

long MSpell_AppliedOnObject(_D3_OBJECT *D3Obj,long index)

{
  uint uVar1;
  int iVar2;
  
  if (D3Obj != (_D3_OBJECT *)0x0) {
    uVar1 = index & 0xff;
    if (((uVar1 != 2) && (((uVar1 < 2 || (0x10 < uVar1)) || (uVar1 < 0xf)))) ||
       ((D3Obj->display_mode & 0x40U) != 0)) {
      iVar2 = *(int *)&D3Obj[1].last_pos +
              (int)MSpell_Conversion[(uint)(byte)(&PSpells)[index & 0xff].element] + 6;
      if (*(char *)(iVar2 + 0x13c) == '\x04') {
        return 0;
      }
      *(uint *)(*(int *)&D3Obj[1].last_pos + 0x20) = (uint)*(byte *)(iVar2 + 0x13c);
      Monster_ExternForceAction(D3Obj,0x1f,index);
      return 1;
    }
  }
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MSpell_SpellTesting(struct _MONSTER *monst /*$s6*/, long WhatSpell /*$a1*/, long WParam1 /*$a2*/, long anim /*$a3*/)
 // line 68, offset 0x80081934
	/* begin block 1 */
		// Start line: 69
		// Start offset: 0x80081934
		// Variables:
	// 		char old_resistance[10]; // stack offset -64
	// 		struct _D3_OBJECT *o; // $s2
	// 		struct M_OBJECT *mo; // $s3
	// 		long i; // $s0
	// 		long tmp; // $s1
	// 		long tmp2; // $s3
	// 		long resist; // $s5
	// 		long oldboxheight; // $s4
	// 		long oldsens; // $fp

		/* begin block 1.1 */
			// Start line: 154
			// Start offset: 0x80081CBC
			// Variables:
		// 		struct M_SPELL_7fake pos; // stack offset -48
		/* end block 1.1 */
		// End offset: 0x80081E3C
		// End Line: 202
	/* end block 1 */
	// End offset: 0x80081F08
	// End Line: 239

	/* begin block 2 */
		// Start line: 137
	/* end block 2 */
	// End Line: 138

/* WARNING: Could not reconcile some variable overlaps */

void MSpell_SpellTesting(_MONSTER *monst,long WhatSpell,long WParam1,long anim)

{
  uchar *puVar1;
  bool bVar2;
  byte bVar3;
  short sVar4;
  ushort uVar5;
  TASK *pTVar6;
  short sVar7;
  long lVar8;
  uchar *puVar9;
  uint time;
  _MONSTER *p_Var10;
  int iVar11;
  int iVar12;
  short sVar13;
  uint uVar14;
  _D3_OBJECT *o;
  M_OBJECT *obj;
  int iVar15;
  int iVar16;
  uint uVar17;
  uchar local_40 [16];
  undefined4 local_30;
  uint local_2c;
  
  o = monst->obj;
  uVar17 = monst->sensormask;
  obj = (M_OBJECT *)o->description;
  monst->sensormask = uVar17 & 0xffffefff;
  if (((int)o->collision_mode & 0x8000U) != 0) {
    *(uint *)(*(int *)&o[1].last_pos + 0x14c) =
         *(uint *)(*(int *)&o[1].last_pos + 0x14c) | 1 << (WhatSpell & 0x1fU);
  }
  iVar11 = 0;
  bVar3 = monst->resistance
          [(int)MSpell_Conversion[(uint)(byte)(&PSpells)[WhatSpell & 0xff].element] + 6];
  puVar9 = local_40;
  do {
    puVar1 = monst->resistance + iVar11;
    iVar11 = iVar11 + 1;
    *puVar9 = *puVar1;
    puVar9 = local_40 + iVar11;
  } while (iVar11 < 10);
  time = WhatSpell & 0xff;
  TaskCurrent->event_enable = 0;
  monst->hurttimer = 2;
  if (time == 0xf) {
    if ((monst->flags & 0x800U) == 0) {
      monst->hbcounter = 300;
    }
    monst->mode = 0x32;
    if (anim < 0) {
      if (anim != -2) {
        (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
        Monster_StopChilds(o);
      }
    }
    else {
      Manim_SetAnim(obj,anim);
    }
    Manim_SetEffect(obj,Motion2D_ManimVampire);
    Task_Sleep(0x3c);
    if ((monst->flags & 0x800U) == 0) {
      monst->hbcounter = 0x3c;
    }
    (obj->Env).Obj.vert_top.vz = 0x80;
  }
  else {
    if (time < 0x10) {
      if (time == 5) {
        iVar11 = 4;
        if ((WhatSpell & 0x100U) == 0) {
          sVar7 = (o->pos).vz;
          Pvl_SctState[(int)o->index] = Pvl_SctState[(int)o->index] | 2;
          D3_SetBonuses(o,1,o);
          D3_ClearCollBits(o,0xb);
          monst->mode = 0x32;
          sVar4 = (o->pos).vz;
          sVar13 = 0;
          while ((int)sVar4 - (int)sVar7 < 10000) {
            (o->rot).vz = (o->rot).vz + 0x580;
            (o->pos).vz = (o->pos).vz + sVar13;
            Impact_Smoke((char)o + ',',0);
            sVar13 = sVar13 + 5;
            Task_Next();
            sVar4 = (o->pos).vz;
          }
          uVar5 = o->display_mode;
          (o->pos).vz = sVar7;
          o->display_mode = uVar5 & 0xffef;
          monst->mode = 0x11;
          monst->sensormask = uVar17;
          return;
        }
        iVar15 = 4;
        iVar12 = (int)Scr_TicksPerSecond * 4;
        time = (uint)(ushort)(o->rot).vz & 0xfff;
        if (0 < iVar12) {
          iVar16 = (int)Scr_TicksPerSecond * 0x30;
          do {
            bVar2 = iVar15 == 0;
            iVar15 = iVar15 + -1;
            if (bVar2) {
              if (iVar12 <= (int)Scr_TicksPerSecond << 1) {
                iVar11 = iVar11 + 2;
              }
              iVar15 = iVar11;
              if (5 < iVar12) {
                Fx_Play(0x1c,(char)o + ',');
                iVar15 = iVar11;
              }
            }
            (o->rot).vz = (o->rot).vz + (short)iVar16;
            local_30 = *(uint *)&o->pos;
            local_2c = *(uint *)&(o->pos).vz;
            iVar12 = iVar12 + -1;
            lVar8 = M_rand();
            local_30 = local_30 & 0xffff0000 |
                       (uint)(ushort)((short)local_30 + -0x40 + ((ushort)lVar8 & 0x7f));
            lVar8 = M_rand();
            iVar16 = iVar16 + -0xc;
            local_30 = local_30 & 0xffff |
                       (uint)(ushort)(local_30._2_2_ + -0x40 + ((ushort)lVar8 & 0x7f)) << 0x10;
            lVar8 = M_rand();
            local_2c = local_2c & 0xffff0000 |
                       (uint)(ushort)((short)local_2c + -0x40 + ((ushort)lVar8 & 0x7f));
            Impact_Smoke(0xd0,0);
            Task_Next();
          } while (0 < iVar12);
        }
        if (*(char *)((int)&o[1].pos.vx + 1) == '\v') {
          uVar5 = (o->rot).vz;
          while (((uint)uVar5 & 0xfff) != time) {
            uVar14 = (int)(short)uVar5 - time & 0xfff;
            if (uVar14 - 0x1e < 0xfc5) {
              sVar7 = uVar5 - 0x1e;
              if (0x800 < uVar14) {
                sVar7 = uVar5 + 0x1e;
              }
              (o->rot).vz = sVar7;
            }
            else {
              (o->rot).vz = (short)time;
            }
            Task_Next();
            uVar5 = (o->rot).vz;
          }
        }
      }
    }
    else {
      if (time == 0x10) {
        D3_ClearCollBits(o,2);
        monst->mode = 0x33;
        iVar15 = 5;
        iVar11 = (int)&monst->sensormask + 1;
        do {
          *(undefined *)(iVar11 + 0x13c) = 0;
          iVar15 = iVar15 + -1;
          iVar11 = iVar11 + -1;
        } while (-1 < iVar15);
        iVar11 = (int)*(short *)&o[1].prec - (int)(o->b_box).vz;
        if (iVar11 < 10) {
          sVar7 = (o->b_box).vz + monst->height;
          o[1].collision_mode = sVar7;
          *(short *)&o[1].handle = sVar7;
          *(short *)&o[1].father = sVar7;
          *(short *)&o[1].prec = sVar7;
        }
        Manim_SetEffect(obj,Motion2D_ManimFreeze);
        iVar15 = 0;
        uVar5 = (obj->Env).Obj.normal_top.vx;
        (obj->Env).Obj.normal_top.pad = 0x80;
        while ((uVar5 & 0x4000) == 0) {
          iVar15 = iVar15 + 1;
          Task_Next();
          if (7 < iVar15) break;
          uVar5 = (obj->Env).Obj.normal_top.vx;
        }
        time = (int)Scr_TicksPerSecond * 10;
        (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
        if (bVar3 == 2) {
          time = (int)(time + (time >> 0x1f)) >> 1;
        }
        else {
          if (bVar3 < 3) {
            if (bVar3 == 1) {
              uVar14 = time;
              if ((int)time < 0) {
                uVar14 = time + 3;
              }
              time = time - ((int)uVar14 >> 2);
            }
          }
          else {
            if (bVar3 == 3) {
              if ((int)time < 0) {
                time = time + 3;
              }
              time = (int)time >> 2;
            }
          }
        }
        Task_Sleep(time);
        (obj->Env).Obj.vert_top.vz = 0x80;
        Task_Sleep(8);
        iVar15 = 0;
        uVar5 = (obj->Env).Obj.normal_top.vx;
        (obj->Env).Obj.normal_top.pad = 0x100;
        (obj->Env).Obj.normal_top.vx = uVar5 | 1;
        p_Var10 = monst;
        do {
          puVar9 = local_40 + iVar15;
          iVar15 = iVar15 + 1;
          p_Var10->resistance[0] = *puVar9;
          p_Var10 = (_MONSTER *)((int)&monst->obj + iVar15);
        } while (iVar15 < 10);
        if (iVar11 < 10) {
          sVar7 = (o->b_box).vz + (short)iVar11;
          o[1].collision_mode = sVar7;
          *(short *)&o[1].handle = sVar7;
          *(short *)&o[1].father = sVar7;
          *(short *)&o[1].prec = sVar7;
        }
      }
    }
  }
  pTVar6 = TaskCurrent;
  monst->sensormask = uVar17;
  pTVar6->event_enable = 1;
  return;
}





