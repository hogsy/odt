#include "THISDUST.H"
#include "MSENSORA.H"


// decompiled code
// original method signature: 
// long /*$ra*/ MSensor_AddFear(struct _MONSTER *monst /*$a0*/, short value /*$a1*/)
 // line 13, offset 0x80070604
	/* begin block 1 */
		// Start line: 15
		// Start offset: 0x80070604
		// Variables:
	// 		struct _D3_OBJECT *o; // $v0
	// 		long tmp; // $a2
	/* end block 1 */
	// End offset: 0x80070668
	// End Line: 30

	/* begin block 2 */
		// Start line: 27
	/* end block 2 */
	// End Line: 28

long MSensor_AddFear(_MONSTER *monst,short value)

{
  int iVar1;
  
  iVar1 = (int)((int)value * (uint)*(byte *)&monst->obj[1].pos.vz) >> 4;
  if (iVar1 < 0) {
    if (-1 < (int)((uint)monst->fear + (int)value)) {
      monst->fear = monst->fear + value;
    }
    return 1;
  }
  iVar1 = (uint)monst->fear + iVar1;
  if (iVar1 < 0x8000) {
    monst->fear = (ushort)iVar1;
  }
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ MSensor_AddAgression(struct _MONSTER *monst /*$a0*/, short value /*$a1*/)
 // line 32, offset 0x80070670
	/* begin block 1 */
		// Start line: 34
		// Start offset: 0x80070670
		// Variables:
	// 		struct _D3_OBJECT *o; // $v0
	// 		long tmp; // $a2
	/* end block 1 */
	// End offset: 0x800706DC
	// End Line: 49

	/* begin block 2 */
		// Start line: 65
	/* end block 2 */
	// End Line: 66

long MSensor_AddAgression(_MONSTER *monst,short value)

{
  int iVar1;
  
  iVar1 = (int)value * ((int)((int)monst->obj[1].pos.pad & 0xff00U) >> 8) >> 4;
  if (iVar1 < 0) {
    if (-1 < (int)((uint)monst->agression + (int)value)) {
      monst->agression = monst->agression + value;
    }
    return 1;
  }
  iVar1 = (uint)monst->agression + iVar1;
  if (iVar1 < 0x8000) {
    monst->agression = (ushort)iVar1;
  }
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ MSensorA_Test_AmIInZone(struct _MONSTER *monst /*$s1*/)
 // line 57, offset 0x800706e4
	/* begin block 1 */
		// Start line: 58
		// Start offset: 0x800706E4
		// Variables:
	// 		struct MSENSORA_7fake pos; // stack offset -24
	// 		long ret; // $s0
	/* end block 1 */
	// End offset: 0x80070848
	// End Line: 81

	/* begin block 2 */
		// Start line: 114
	/* end block 2 */
	// End Line: 115

long MSensorA_Test_AmIInZone(_MONSTER *monst)

{
  short sVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  long lVar6;
  short local_18;
  short local_14;
  
  uVar4 = *(uint *)&monst->obj->pos;
  uVar5 = *(undefined4 *)&(monst->obj->pos).vz;
  lVar6 = -1;
  iVar2 = rcos((int)(monst->obj->rot).vz);
  local_18 = (short)uVar4;
  iVar3 = rsin((int)(monst->obj->rot).vz);
  if ((monst->zb_low | monst->zb_high) != 0) {
    local_14 = (short)uVar5;
    sVar1 = Zone_GetEnemyZone(local_18 + (short)(iVar2 * 100 >> 0xc),
                              (short)(((uVar4 >> 0x10) + (iVar3 * 100 >> 0xc)) * 0x10000 >> 0x10),
                              local_14,monst->zb_low,monst->zb_high);
    if ((int)sVar1 == -1) {
      if ((monst->flags & 0x2000U) != 0) {
        lVar6 = -3;
      }
      monst->flags = monst->flags & 0xdfff;
    }
    else {
      monst->zone_current = Pvl_EnemyZones + (int)sVar1;
      if ((monst->flags & 0x2000U) == 0) {
        lVar6 = 0;
      }
      monst->flags = monst->flags | 0x2000;
      if (lVar6 == 0) {
        lVar6 = -2;
      }
      else {
        lVar6 = CONCAT22((monst->obj->pos).vx,(monst->obj->pos).vy);
      }
    }
  }
  return lVar6;
}



// decompiled code
// original method signature: 
// long /*$ra*/ MSensorA_Test_HeightInFront(struct _MONSTER *mo /*$s0*/)
 // line 83, offset 0x8007085c
	/* begin block 1 */
		// Start line: 84
		// Start offset: 0x8007085C
		// Variables:
	// 		struct MSENSORA_7fake pos1; // stack offset -32
	// 		struct MSENSORA_7fake pos; // stack offset -24
	// 		long res; // $v1
	/* end block 1 */
	// End offset: 0x80070CBC
	// End Line: 134

	/* begin block 2 */
		// Start line: 167
	/* end block 2 */
	// End Line: 168

long MSensorA_Test_HeightInFront(_MONSTER *mo)

{
  long lVar1;
  long lVar2;
  int iVar3;
  
  rcos((int)(mo->obj->rot).vz);
  rsin((int)(mo->obj->rot).vz);
  lVar1 = Boxes_GetHeight(mo->obj,0xe0,(short)(((uint)(ushort)mo->height + 200) * 0x10000 >> 0x10));
  iVar3 = (int)(mo->obj->pos).vz;
  lVar2 = lVar1 - iVar3;
  if (((lVar1 <= iVar3) && (lVar2 = lVar1 - iVar3, iVar3 + -0x19 <= lVar1)) &&
     (lVar2 = -1, lVar1 != iVar3)) {
    if (Scr_Frame == 0) {
      rsin((int)(mo->obj->rot).vz);
      rcos((int)(mo->obj->rot).vz);
      lVar1 = Boxes_GetHeightPlatform(mo->obj,0xe8);
      iVar3 = (int)(mo->obj->pos).vz;
      lVar2 = lVar1 - iVar3;
      if ((lVar1 <= iVar3) && (lVar2 = -1, lVar1 != iVar3)) {
        rsin((int)(mo->obj->rot).vz);
        rcos((int)(mo->obj->rot).vz);
        lVar1 = Boxes_GetHeightPlatform(mo->obj,0xe8);
        iVar3 = (int)(mo->obj->pos).vz;
        lVar2 = lVar1 - iVar3;
        if ((lVar1 <= iVar3) && (lVar2 = -1, lVar1 != iVar3)) {
          lVar2 = -1;
        }
      }
    }
    else {
      rsin((int)(mo->obj->rot).vz);
      rcos((int)(mo->obj->rot).vz);
      lVar1 = Boxes_GetHeightPlatform(mo->obj,0xe8);
      iVar3 = (int)(mo->obj->pos).vz;
      lVar2 = lVar1 - iVar3;
      if ((lVar1 <= iVar3) && (lVar2 = -1, lVar1 != iVar3)) {
        rsin((int)(mo->obj->rot).vz);
        rcos((int)(mo->obj->rot).vz);
        lVar1 = Boxes_GetHeightPlatform(mo->obj,0xe8);
        iVar3 = (int)(mo->obj->pos).vz;
        lVar2 = lVar1 - iVar3;
        if (lVar1 <= iVar3) {
          lVar2 = -1;
        }
      }
    }
  }
  return lVar2;
}



// decompiled code
// original method signature: 
// long /*$ra*/ MSensorA_Test_Fear(struct _MONSTER *monst /*$a0*/)
 // line 136, offset 0x80070cd4
	/* begin block 1 */
		// Start line: 138
		// Start offset: 0x80070CD4
		// Variables:
	// 		long tmp; // $v0
	/* end block 1 */
	// End offset: 0x80070CEC
	// End Line: 144

	/* begin block 2 */
		// Start line: 288
	/* end block 2 */
	// End Line: 289

long MSensorA_Test_Fear(_MONSTER *monst)

{
  uint uVar1;
  
  uVar1 = (uint)monst->fear;
  if (monst->fear < 0x101) {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ MSensorA_Test_Agression(struct _MONSTER *monst /*$a0*/)
 // line 146, offset 0x80070cf4
	/* begin block 1 */
		// Start line: 148
		// Start offset: 0x80070CF4
		// Variables:
	// 		long tmp; // $v0
	/* end block 1 */
	// End offset: 0x80070D0C
	// End Line: 153

	/* begin block 2 */
		// Start line: 307
	/* end block 2 */
	// End Line: 308

long MSensorA_Test_Agression(_MONSTER *monst)

{
  uint uVar1;
  
  uVar1 = (uint)monst->agression;
  if (monst->agression < 0x101) {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ MSensorA_Test_HitPoints(struct _MONSTER *mo /*$a0*/)
 // line 155, offset 0x80070d14
	/* begin block 1 */
		// Start line: 157
		// Start offset: 0x80070D14
		// Variables:
	// 		struct _D3_OBJECT *o; // $v0
	/* end block 1 */
	// End offset: 0x80070D30
	// End Line: 161

	/* begin block 2 */
		// Start line: 323
	/* end block 2 */
	// End Line: 324

long MSensorA_Test_HitPoints(_MONSTER *mo)

{
  long lVar1;
  
  lVar1 = 0;
  if (mo->obj->hit_points != 0) {
    lVar1 = -1;
  }
  return lVar1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ MSensorA_Test_TargetedByPlayer(struct _MONSTER *monst /*$s2*/)
 // line 163, offset 0x80070d38
	/* begin block 1 */
		// Start line: 164
		// Start offset: 0x80070D38
		// Variables:
	// 		struct _D3_OBJECT *ret; // $s1
	// 		short index; // $s0
	/* end block 1 */
	// End offset: 0x80070E20
	// End Line: 193

	/* begin block 2 */
		// Start line: 342
	/* end block 2 */
	// End Line: 343

long MSensorA_Test_TargetedByPlayer(_MONSTER *monst)

{
  char cVar1;
  _D3_OBJECT *p_Var2;
  int iVar3;
  
  if (Scr_Frame == 0) {
    return -1;
  }
  p_Var2 = D3_SeekDangerousObject(monst->obj,Pvl_PlayerShots,0x9c4,0x800,0x140);
  if (p_Var2 == (_D3_OBJECT *)0x0) {
    return -1;
  }
  MSensor_AddFear(monst,0x40);
  MSensor_AddAgression(monst,0x96);
  cVar1 = *(char *)((int)&p_Var2[1].pos.vx + 1);
  if (cVar1 == -8) {
    iVar3 = 3;
LAB_80070de8:
    iVar3 = iVar3 << 0x10;
  }
  else {
    if (cVar1 < -7) {
      if (cVar1 != -9) {
        iVar3 = -1;
        goto LAB_80070df0;
      }
      iVar3 = 1;
      goto LAB_80070de8;
    }
    iVar3 = -0x10000;
    if (cVar1 == -7) {
      iVar3 = 0;
      goto LAB_80070de8;
    }
  }
  iVar3 = iVar3 >> 0x10;
LAB_80070df0:
  if (iVar3 == -1) {
    return -1;
  }
  if (1 < (uint)monst->resistance[iVar3] - 2) {
    return (long)p_Var2;
  }
  return -1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ MSensorA_Test_TargetedByMonster(struct _MONSTER *monst /*$a0*/)
 // line 195, offset 0x80070e38
	/* begin block 1 */
		// Start line: 409
	/* end block 1 */
	// End Line: 410

long MSensorA_Test_TargetedByMonster(_MONSTER *monst)

{
  return -1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ MSensorA_Test_TouchedObject(struct _MONSTER *monst /*$a0*/)
 // line 200, offset 0x80070e40
	/* begin block 1 */
		// Start line: 202
		// Start offset: 0x80070E40
		// Variables:
	// 		struct _D3_OBJECT *o; // $a1
	// 		struct _D3_OBJECT *ret; // $v1
	/* end block 1 */
	// End offset: 0x80070EAC
	// End Line: 219

	/* begin block 2 */
		// Start line: 419
	/* end block 2 */
	// End Line: 420

long MSensorA_Test_TouchedObject(_MONSTER *monst)

{
  _D3_OBJECT *p_Var1;
  _D3_OBJECT *p_Var2;
  
  p_Var1 = (_D3_OBJECT *)0xffffffff;
  if (((((int)monst->obj->collision_state & 0xfc00U) != 0) &&
      (p_Var2 = monst->d3_lasttouched, p_Var1 = (_D3_OBJECT *)0xffffffff,
      p_Var2 != (_D3_OBJECT *)0x0)) &&
     (((((int)p_Var2->collision_mode & 0x8000U) == 0 &&
       (*(char *)((int)&p_Var2[1].pos.vx + 1) < '\0')) ||
      ((p_Var1 = p_Var2, p_Var2 == (_D3_OBJECT *)0x0 &&
       (p_Var1 = (_D3_OBJECT *)monst->obj[1].color, p_Var1 == (_D3_OBJECT *)0x0)))))) {
    p_Var1 = (_D3_OBJECT *)0xffffffff;
  }
  return (long)p_Var1;
}





