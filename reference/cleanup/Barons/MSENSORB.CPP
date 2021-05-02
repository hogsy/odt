#include "THISDUST.H"
#include "MSENSORB.H"


// decompiled code
// original method signature: 
// long /*$ra*/ MSensorB_Test_Path(struct _MONSTER *monst /*$s0*/)
 // line 18, offset 0x80070eb4
	/* begin block 1 */
		// Start line: 19
		// Start offset: 0x80070EB4
		// Variables:
	// 		struct _D3_OBJECT *target; // $s1
	// 		long ret; // $s2
	/* end block 1 */
	// End offset: 0x80070FE0
	// End Line: 47

	/* begin block 2 */
		// Start line: 36
	/* end block 2 */
	// End Line: 37

long MSensorB_Test_Path(_MONSTER *monst)

{
  long lVar1;
  short sVar2;
  int iVar3;
  long lVar4;
  
  lVar1 = Monster_Feelings;
  iVar3 = -1;
  lVar4 = iVar3;
  if (Monster_Feelings != 0) {
    lVar4 = -1;
    if ((monst->zb_low | monst->zb_high) != 0) {
      sVar2 = Zone_GetEnemyZone(*(short *)(Monster_Feelings + 0x2c),
                                *(short *)(Monster_Feelings + 0x2e),
                                *(short *)(Monster_Feelings + 0x30),monst->zb_low,monst->zb_high);
      if ((int)sVar2 == -1) {
        lVar4 = iVar3;
        if ((monst->flags & 0x4000U) != 0) {
          lVar4 = -3;
        }
        monst->flags = monst->flags & 0xbfff;
        MSensor_AddAgression(monst,-2);
      }
      else {
        lVar4 = -1;
        if ((Pvl_EnemyZones[(int)sVar2].flags & 2) == 0) {
          monst->obj[1].pos.vz = monst->obj[1].pos.vz & 0xefff;
          if ((monst->flags & 0x4000U) == 0) {
            iVar3 = 0;
          }
          monst->flags = monst->flags | 0x4000;
          if (iVar3 == 0) {
            MSensor_AddFear(monst,5);
            MSensor_AddAgression(monst,4);
            lVar4 = -2;
          }
          else {
            lVar4 = CONCAT22(*(undefined2 *)(lVar1 + 0x2c),*(undefined2 *)(lVar1 + 0x2e));
          }
        }
      }
    }
  }
  return lVar4;
}



// decompiled code
// original method signature: 
// long /*$ra*/ MSensorB_Test_ViolatedWaitZone(struct _MONSTER *mo /*$a0*/)
 // line 51, offset 0x80070ff8
	/* begin block 1 */
		// Start line: 53
		// Start offset: 0x80070FF8
		// Variables:
	// 		struct _D3_OBJECT *target; // $a2
	// 		long ret; // $a3
	/* end block 1 */
	// End offset: 0x800710C0
	// End Line: 71

	/* begin block 2 */
		// Start line: 108
	/* end block 2 */
	// End Line: 109

long MSensorB_Test_ViolatedWaitZone(_MONSTER *mo)

{
  long lVar1;
  _ENEMYZONE *p_Var2;
  long lVar3;
  
  lVar1 = Monster_Feelings;
  p_Var2 = mo->zone_wait;
  lVar3 = -1;
  if ((((p_Var2 == (_ENEMYZONE *)0x0) || (*(short *)(Monster_Feelings + 0x2c) <= p_Var2->x1)) ||
      (p_Var2->x2 <= *(short *)(Monster_Feelings + 0x2c))) ||
     ((*(short *)(Monster_Feelings + 0x2e) <= p_Var2->y1 ||
      (p_Var2->y2 <= *(short *)(Monster_Feelings + 0x2e))))) {
    if (((int)mo->flags & 0x8000U) != 0) {
      lVar3 = -3;
    }
    mo->flags = mo->flags & 0x7fff;
    return lVar3;
  }
  if (((int)mo->flags & 0x8000U) == 0) {
    lVar3 = 0;
  }
  mo->flags = mo->flags | 0x8000;
  if (lVar3 == 0) {
    return -2;
  }
  return CONCAT22(*(undefined2 *)(lVar1 + 0x2c),*(undefined2 *)(lVar1 + 0x2e));
}



// decompiled code
// original method signature: 
// long /*$ra*/ MSensorB_Test_HeardPlayer(struct _MONSTER *mo /*$a0*/)
 // line 73, offset 0x800710c8
	/* begin block 1 */
		// Start line: 151
	/* end block 1 */
	// End Line: 152

long MSensorB_Test_HeardPlayer(_MONSTER *mo)

{
  return -1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ MSensorB_Test_ViewMonster(struct _MONSTER *monst /*$s1*/)
 // line 78, offset 0x800710d0
	/* begin block 1 */
		// Start line: 79
		// Start offset: 0x800710D0
		// Variables:
	// 		struct _MONSTER *monst2; // $v0
	// 		struct _D3_OBJECT *spotted; // $s0
	/* end block 1 */
	// End offset: 0x800711AC
	// End Line: 107

	/* begin block 2 */
		// Start line: 160
	/* end block 2 */
	// End Line: 161

long MSensorB_Test_ViewMonster(_MONSTER *monst)

{
  _D3_OBJECT *p_Var1;
  
  p_Var1 = (_D3_OBJECT *)0xffffffff;
  if (((int)monst->obj->collision_mode & 0x8000U) != 0) {
    p_Var1 = D3_SeekDistFriend(monst->obj,2000);
    if (p_Var1 == (_D3_OBJECT *)0x0) {
      p_Var1 = (_D3_OBJECT *)0xffffffff;
    }
    else {
      MSensor_AddFear(monst,-0x10);
      MSensor_AddAgression(monst,-0x1e);
      if ((Pvl_SctState[(int)p_Var1->index] & 2U) != 0) {
        MSensor_AddFear(monst,0x20);
        MSensor_AddAgression(monst,100);
      }
      if ((((int)p_Var1->collision_mode & 0x8000U) != 0) &&
         (0x100 < *(ushort *)(*(int *)&p_Var1[1].last_pos + 0xf6))) {
        MSensor_AddAgression(monst,0x32);
      }
    }
  }
  return (long)p_Var1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ MSensorB_Test_ViewPlayer(struct _MONSTER *mo /*$s4*/)
 // line 109, offset 0x800711c0
	/* begin block 1 */
		// Start line: 110
		// Start offset: 0x800711C0
		// Variables:
	// 		struct _D3_OBJECT *target; // $s0
	// 		struct MSENSORB_7fake pos; // stack offset -32
	// 		long dir; // $s1
	// 		long m_dir; // $s3
	// 		short i; // $s2
	/* end block 1 */
	// End offset: 0x80071364
	// End Line: 131

	/* begin block 2 */
		// Start line: 222
	/* end block 2 */
	// End Line: 223

long MSensorB_Test_ViewPlayer(_MONSTER *mo)

{
  ushort uVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  uint uVar6;
  _D3_OBJECT *p_Var7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  short local_20;
  short sStack30;
  short local_1c;
  
  lVar3 = Monster_Feelings;
  p_Var7 = mo->obj;
  uVar1 = (p_Var7->rot).vz;
  lVar4 = Direction((int)*(short *)(Monster_Feelings + 0x2c) - (int)(p_Var7->pos).vx,
                    (int)*(short *)(Monster_Feelings + 0x2e) - (int)(p_Var7->pos).vy);
  lVar5 = -1;
  if ((lVar4 - (((uint)uVar1 & 0xfff) - 0x200) & 0xfff) < 0x601) {
    uVar8 = *(undefined4 *)&mo->obj->pos;
    uVar9 = *(undefined4 *)&(mo->obj->pos).vz;
    uVar6 = Direction((int)*(short *)(lVar3 + 0x2c) - (int)(mo->obj->pos).vx,
                      (int)*(short *)(lVar3 + 0x2e) - (int)(mo->obj->pos).vy);
    local_20 = (short)uVar8;
    sStack30 = (short)((uint)uVar8 >> 0x10);
    lVar4 = Distance2D((int)*(short *)(lVar3 + 0x2c),(int)*(short *)(lVar3 + 0x2e),(int)local_20,
                       (int)sStack30);
    iVar2 = lVar4 / 100;
    if (iVar2 < 0x15) {
      iVar10 = 0;
      if (0 < iVar2) {
        do {
          rcos(uVar6);
          rsin(uVar6);
          lVar4 = Boxes_GetHeightPlatform(mo->obj,0xe0);
          local_1c = (short)uVar9;
          iVar10 = iVar10 + 1;
          if ((int)local_1c + 0x96 < lVar4) goto LAB_800712b0;
        } while (iVar10 * 0x10000 >> 0x10 < iVar2);
      }
      lVar5 = CONCAT22(*(undefined2 *)(lVar3 + 0x2c),*(undefined2 *)(lVar3 + 0x2e));
    }
    else {
LAB_800712b0:
      lVar5 = -1;
    }
  }
  return lVar5;
}



// decompiled code
// original method signature: 
// long /*$ra*/ MSensorB_Test_NearToPlayer(struct _MONSTER *mo /*$a0*/)
 // line 133, offset 0x80071384
	/* begin block 1 */
		// Start line: 134
		// Start offset: 0x80071384
		// Variables:
	// 		struct _D3_OBJECT *target; // $v1
	// 		struct _D3_OBJECT *o; // $v0
	/* end block 1 */
	// End offset: 0x80071384
	// End Line: 134

	/* begin block 2 */
		// Start line: 281
	/* end block 2 */
	// End Line: 282

long MSensorB_Test_NearToPlayer(_MONSTER *mo)

{
  long lVar1;
  
  lVar1 = Distance2D((int)(mo->obj->pos).vx,(int)(mo->obj->pos).vy,
                     (int)*(short *)(Monster_Feelings + 0x2c),
                     (int)*(short *)(Monster_Feelings + 0x2e));
  return lVar1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ MSensorB_Test_HitByPlayerBullet(struct _MONSTER *monst /*$a0*/)
 // line 142, offset 0x800713c0
	/* begin block 1 */
		// Start line: 301
	/* end block 1 */
	// End Line: 302

long MSensorB_Test_HitByPlayerBullet(_MONSTER *monst)

{
  if (((monst->obj->collision_state & 2U) != 0) && ((ushort)(monst->whohitme + 0x1fU) < 0x19)) {
    return monst->whohitme_turn + 0x800U & 0xfff;
  }
  return -1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ MSensorB_Test_HitByMonsterBullet(struct _MONSTER *monst /*$s0*/)
 // line 152, offset 0x80071414
	/* begin block 1 */
		// Start line: 320
	/* end block 1 */
	// End Line: 321

long MSensorB_Test_HitByMonsterBullet(_MONSTER *monst)

{
  uint uVar1;
  
  uVar1 = 0xffffffff;
  if ((monst->obj->collision_state & 2U) != 0) {
    if ((ushort)(monst->whohitme + 0x28U) < 9) {
      MSensor_AddFear(monst,0x96);
      MSensor_AddAgression(monst,0x14);
      uVar1 = monst->whohitme_turn + 0x800U & 0xfff;
    }
    else {
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ MSensorB_Test_HitByGrenade(struct _MONSTER *monst /*$a0*/)
 // line 166, offset 0x80071498
	/* begin block 1 */
		// Start line: 349
	/* end block 1 */
	// End Line: 350

long MSensorB_Test_HitByGrenade(_MONSTER *monst)

{
  long lVar1;
  
  lVar1 = 1;
  if ((monst->obj->collision_state & 2U) == 0) {
    lVar1 = -1;
  }
  return lVar1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ MSensorB_Test_MyTarget(struct _MONSTER *mo /*$a0*/)
 // line 175, offset 0x800714c0
	/* begin block 1 */
		// Start line: 177
		// Start offset: 0x800714C0
		// Variables:
	// 		struct _D3_OBJECT *target; // $a0
	/* end block 1 */
	// End offset: 0x80071504
	// End Line: 188

	/* begin block 2 */
		// Start line: 367
	/* end block 2 */
	// End Line: 368

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long MSensorB_Test_MyTarget(_MONSTER *mo)

{
  if (((_DAT_800b1c54 & 0x1000) != 0) && (DAT_800b1e2c == '\x06')) {
    Monster_Mask = Monster_Mask & 0xfffffa9f;
  }
  return (long)&Player;
}



// decompiled code
// original method signature: 
// long /*$ra*/ MSensorB_Test_TargetInformation(struct _MONSTER *mo /*$a0*/)
 // line 191, offset 0x8007150c
	/* begin block 1 */
		// Start line: 192
		// Start offset: 0x8007150C
		// Variables:
	// 		struct _D3_OBJECT *target; // $s1
	// 		struct _D3_OBJECT *tmpobj; // $v0
	// 		long ret; // $s0
	/* end block 1 */
	// End offset: 0x800715E4
	// End Line: 232

	/* begin block 2 */
		// Start line: 398
	/* end block 2 */
	// End Line: 399

long MSensorB_Test_TargetInformation(_MONSTER *mo)

{
  long lVar1;
  _D3_OBJECT *p_Var2;
  _D3_OBJECT *p_Var3;
  
  lVar1 = Monster_Feelings;
  p_Var3 = (_D3_OBJECT *)0xffffffff;
  if ((*(ushort *)(Monster_Feelings + 0x1c) & 0x1000) != 0) {
    if (mo->zone_fear != -1) {
      return -1;
    }
    if ((*(char *)(Monster_Feelings + 500) == '\v') && (LONG_ARRAY_800b2e40[0] < 500)) {
      p_Var3 = (_D3_OBJECT *)Monster_Feelings;
    }
    if (p_Var3 != (_D3_OBJECT *)0xffffffff) {
      return (long)p_Var3;
    }
    p_Var2 = D3_SeekClosestGrenade(mo->obj);
    if (p_Var2 != (_D3_OBJECT *)0x0) {
      p_Var3 = p_Var2;
    }
    if (p_Var3 != (_D3_OBJECT *)0xffffffff) {
      return (long)p_Var3;
    }
    if (LONG_800b2e28 != -1) {
      return -1;
    }
    if (LONG_800b2e64 == -1) {
      return -1;
    }
    p_Var3 = (_D3_OBJECT *)lVar1;
    if (799 < LONG_ARRAY_800b2e40[0]) {
      return -1;
    }
  }
  return (long)p_Var3;
}





