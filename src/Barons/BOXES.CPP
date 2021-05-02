#include "THISDUST.H"
#include "BOXES.H"


// decompiled code
// original method signature: 
// void /*$ra*/ Boxes_ClearColl()
 // line 64, offset 0x8001ea50
	/* begin block 1 */
		// Start line: 133
	/* end block 1 */
	// End Line: 134

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Boxes_ClearColl(void)

{
  Boxes_MiniZ = -0x8000;
  Boxes_MaxiZ = 0x7fff;
  Boxes_MiniY = -0x8000;
  Boxes_MaxiY = 0x7fff;
  Boxes_MiniX = -0x8000;
  Boxes_MaxiX = 0x7fff;
  fReset = 0;
  Boxes_Collz = (_D3_OBJECT *)0x0;
  Boxes_nColls = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Boxes_AddColl(struct _D3_OBJECT *oc /*$s2*/, long plane /*$a1*/, long minmax /*$a2*/, long min /*$a3*/, long max /*stack 16*/)
 // line 79, offset 0x8001ea84
	/* begin block 1 */
		// Start line: 80
		// Start offset: 0x8001EA84
		// Variables:
	// 		long n; // $s1
	/* end block 1 */
	// End offset: 0x8001ECE4
	// End Line: 132

	/* begin block 2 */
		// Start line: 167
	/* end block 2 */
	// End Line: 168

void Boxes_AddColl(_D3_OBJECT *oc,long plane,long minmax,long min,long max)

{
  int iVar1;
  int iVar2;
  long lVar3;
  
  iVar2 = (int)Boxes_nColls;
  if (7 < iVar2) {
    return;
  }
  (&Boxes_Colls)[iVar2].obj = oc;
  (&Boxes_Colls)[iVar2].plane = plane;
  (&Boxes_Colls)[iVar2].minmax = minmax;
  (&Boxes_Colls)[iVar2].min = min;
  (&Boxes_Colls)[iVar2].max = max;
  iVar2 = 1;
  if (plane == 0x1000) {
LAB_8001ebd0:
    if ((oc->collision_mode & 4U) == 0) {
      iVar1 = (int)Boxes_nColls;
      (&Boxes_Colls)[iVar1].normal.vx = 0;
      (&Boxes_Colls)[iVar1].normal.vy = iVar2 << 0xc;
    }
    else {
      iVar1 = rsin((int)(oc->rot).vz);
      (&Boxes_Colls)[(int)Boxes_nColls].normal.vx = -iVar1 * iVar2;
      iVar1 = rcos((int)(oc->rot).vz);
      lVar3 = iVar1 * iVar2;
LAB_8001ec2c:
      (&Boxes_Colls)[(int)Boxes_nColls].normal.vy = lVar3;
    }
  }
  else {
    if (0x1000 < plane) {
      if (plane != 0x4000) {
        if (plane < 0x4001) {
          iVar2 = -1;
          if (plane != 0x2000) goto LAB_8001ecd4;
          goto LAB_8001ebd0;
        }
        iVar2 = -1;
        if (plane != 0x8000) goto LAB_8001ecd4;
      }
      iVar1 = (int)Boxes_nColls;
      (&Boxes_Colls)[iVar1].normal.vx = 0;
      (&Boxes_Colls)[iVar1].normal.vy = 0;
      (&Boxes_Colls)[iVar1].normal.vz = iVar2 << 0xc;
      goto LAB_8001ecd4;
    }
    if ((plane != 0x400) && (iVar2 = -1, plane != 0x800)) goto LAB_8001ecd4;
    if ((oc->collision_mode & 4U) != 0) {
      iVar1 = rcos((int)(oc->rot).vz);
      (&Boxes_Colls)[(int)Boxes_nColls].normal.vx = iVar1 * iVar2;
      iVar1 = rsin((int)(oc->rot).vz);
      lVar3 = iVar1 * iVar2;
      goto LAB_8001ec2c;
    }
    iVar1 = (int)Boxes_nColls;
    (&Boxes_Colls)[iVar1].normal.vx = iVar2 << 0xc;
    (&Boxes_Colls)[iVar1].normal.vy = 0;
  }
  (&Boxes_Colls)[(int)Boxes_nColls].normal.vz = 0;
LAB_8001ecd4:
  Boxes_nColls = Boxes_nColls + 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Boxes_DelColl(long i /*$a0*/)
 // line 135, offset 0x8001ecfc
	/* begin block 1 */
		// Start line: 137
		// Start offset: 0x8001ECFC
		// Variables:
	// 		long j; // $a0
	/* end block 1 */
	// End offset: 0x8001ED9C
	// End Line: 147

	/* begin block 2 */
		// Start line: 284
	/* end block 2 */
	// End Line: 285

void Boxes_DelColl(long i)

{
  int iVar1;
  int iVar2;
  _D3_OBJECT **pp_Var3;
  BOXES_106fake *pBVar4;
  BOXES_106fake *pBVar5;
  _D3_OBJECT *p_Var6;
  _D3_OBJECT *p_Var7;
  _D3_OBJECT *p_Var8;
  
  if ((int)Boxes_nColls != 0) {
    if (i < (int)Boxes_nColls + -1) {
      pBVar5 = &Boxes_Colls + i;
      iVar1 = i * 0x24;
      do {
        pp_Var3 = (_D3_OBJECT **)((int)&BOXES_106fake_800b005c.obj + iVar1);
        pBVar4 = pBVar5;
        do {
          p_Var6 = pp_Var3[1];
          p_Var7 = pp_Var3[2];
          p_Var8 = pp_Var3[3];
          pBVar4->obj = *pp_Var3;
          *(_D3_OBJECT **)&pBVar4->min = p_Var6;
          *(_D3_OBJECT **)&pBVar4->max = p_Var7;
          *(_D3_OBJECT **)&pBVar4->minmax = p_Var8;
          pp_Var3 = pp_Var3 + 4;
          pBVar4 = (BOXES_106fake *)&pBVar4->plane;
        } while (pp_Var3 != (_D3_OBJECT **)((int)&BOXES_106fake_800b005c.normal.pad + iVar1));
        pBVar5 = pBVar5 + 1;
        iVar2 = (int)Boxes_nColls;
        i = i + 1;
        pBVar4->obj = *pp_Var3;
        iVar1 = iVar1 + 0x24;
      } while (i < iVar2 + -1);
    }
    Boxes_nColls = Boxes_nColls + -1;
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Boxes_TestResetedObject(struct _D3_OBJECT *ot /*$s2*/)
 // line 156, offset 0x8001eda4
	/* begin block 1 */
		// Start line: 157
		// Start offset: 0x8001EDA4
		// Variables:
	// 		long found; // $s0
	/* end block 1 */
	// End offset: 0x8001EDA4
	// End Line: 157

	/* begin block 2 */
		// Start line: 325
	/* end block 2 */
	// End Line: 326

long Boxes_TestResetedObject(_D3_OBJECT *ot)

{
  uint uVar1;
  uint uVar2;
  
  fReset = 1;
  fEnterZ = 0;
  Boxes_MiniZ = -0x8000;
  Boxes_MaxiZ = 0x7fff;
  Boxes_MiniY = -0x8000;
  Boxes_MaxiY = 0x7fff;
  Boxes_MiniX = -0x8000;
  Boxes_MaxiX = 0x7fff;
  uVar1 = Boxes_TestPlatforms(ot,Boxes_IsObjectEnterInObject);
  uVar2 = Boxes_TestList(ot,&Pvl_GlobalObjects,Boxes_IsObjectEnterInObject);
  return uVar1 | uVar2;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Boxes_TestObject(struct _D3_OBJECT *ot /*$s1*/)
 // line 182, offset 0x8001ee2c
	/* begin block 1 */
		// Start line: 183
		// Start offset: 0x8001EE2C
		// Variables:
	// 		long found; // $s2
	/* end block 1 */
	// End offset: 0x8001F058
	// End Line: 268

	/* begin block 2 */
		// Start line: 401
	/* end block 2 */
	// End Line: 402

long Boxes_TestObject(_D3_OBJECT *ot)

{
  short sVar1;
  ushort uVar2;
  short sVar3;
  long lVar4;
  uint uVar5;
  TASK *pTVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  
  uVar9 = 0;
  Boxes_ClearColl();
  sVar1 = (ot->rot).vz;
  uVar2 = ot->collision_mode;
  ot->collision_state = ot->collision_state & 0x3bf;
  (ot->rot).pad = sVar1;
  if ((((uVar2 & 0x2080) != 0) || (*(int *)&ot->pos != *(int *)&ot->last_pos)) ||
     ((ot->pos).vz != (ot->last_pos).vz)) {
    uVar2 = ot->collision_mode;
    ot->collision_state = ot->collision_state & 0xffdf;
    if ((uVar2 & 0x20) != 0) {
      lVar4 = Boxes_TestPoint(ot);
      return lVar4;
    }
    if ((uVar2 & 0x2000) != 0) {
      lVar4 = Boxes_TestTransparent(ot);
      return lVar4;
    }
    if ((uVar2 & 0x80) != 0) {
      sVar1 = (ot->pos).vz;
      sVar3 = ot[1].collision_state + -5;
      ot[1].collision_state = sVar3;
      (ot->pos).vz = sVar1 + sVar3;
    }
    uVar9 = Boxes_TestPlatforms(ot,Boxes_IsObjectEnterInObject);
    uVar5 = Boxes_TestList(ot,&Pvl_GlobalObjects,Boxes_IsObjectEnterInObject);
    uVar9 = uVar9 | uVar5;
    if (uVar9 != 0) {
      Boxes_ResultColls(ot);
      Boxes_ResetPos(ot);
    }
    if ((ot->collision_mode & 0x80U) != 0) {
      if ((ot->collision_state & 0x4000U) == 0) {
        if (((ot->pos).vz < -800) && (-0x321 < (ot->last_pos).vz)) {
          pTVar6 = ot->handle;
          ot[1].collision_state = 0;
          ot->hit_points = 0;
          if (pTVar6 == (TASK *)0x0) {
            D3_DeleteObject(ot);
          }
        }
      }
      else {
        iVar7 = (int)ot[1].collision_state;
        if (iVar7 < -5) {
          if ((int)ot->hit_points != 0) {
            if (iVar7 < 0) {
              iVar7 = iVar7 + 7;
            }
            uVar5 = (uint)(ushort)ot->hit_points + (iVar7 >> 3);
            if ((int)ot->hit_points + (iVar7 >> 3) < 0) {
              uVar5 = 0;
            }
            ot->hit_points = (short)uVar5;
            if (((uVar5 & 0xffff) == 0) && (ot->handle == (TASK *)0x0)) {
              D3_ExplodeObject(ot);
            }
          }
        }
        ot[1].collision_state = 0;
      }
    }
  }
  if ((ot->collision_mode & 0x1000U) != 0) {
    Zone_TestObject(ot);
  }
  uVar8 = *(undefined4 *)&(ot->pos).vz;
  *(undefined4 *)&ot->last_pos = *(undefined4 *)&ot->pos;
  *(undefined4 *)&(ot->last_pos).vz = uVar8;
  return uVar9;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Boxes_TestGround(struct _D3_OBJECT *ot /*$s1*/)
 // line 271, offset 0x8001f070
	/* begin block 1 */
		// Start line: 272
		// Start offset: 0x8001F070
		// Variables:
	// 		long found; // $s2
	/* end block 1 */
	// End offset: 0x8001F10C
	// End Line: 299

	/* begin block 2 */
		// Start line: 603
	/* end block 2 */
	// End Line: 604

long Boxes_TestGround(_D3_OBJECT *ot)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  
  Boxes_ClearColl();
  sVar1 = (ot->pos).vz;
  ot->collision_state = ot->collision_state & 0xbfff;
  (ot->pos).vz = sVar1 + -0x21;
  uVar2 = Boxes_TestPlatforms(ot,Boxes_IsObjectBaseEnterInObject);
  uVar3 = Boxes_TestList(ot,&Pvl_GlobalObjects,Boxes_IsObjectBaseEnterInObject);
  if ((uVar2 | uVar3) == 0) {
    (ot->pos).vz = (ot->pos).vz + 0x21;
  }
  else {
    Boxes_ResetPos(ot);
    (ot->last_pos).vz = (ot->pos).vz;
    Boxes_TestFloatingGround(ot);
  }
  return uVar2 | uVar3;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Boxes_TestDistance(struct _D3_OBJECT *ot /*$s4*/, long dist /*$a1*/)
 // line 303, offset 0x8001f128
	/* begin block 1 */
		// Start line: 304
		// Start offset: 0x8001F128
		// Variables:
	// 		struct _PLATFORM *p; // $s2
	// 		long Mask; // $s0
	// 		long *Visible; // $s3
	// 		long i; // $s1
	/* end block 1 */
	// End offset: 0x8001F1D4
	// End Line: 329

	/* begin block 2 */
		// Start line: 686
	/* end block 2 */
	// End Line: 687

void Boxes_TestDistance(_D3_OBJECT *ot,long dist)

{
  _PVL_HEADER *p_Var1;
  int iVar2;
  int iVar3;
  _PLATFORM *p_Var4;
  long *plVar5;
  
  p_Var1 = Pvl_File;
  plVar5 = &Plat_RealVisibility;
  iVar2 = 1;
  (ot->b_box).vx = (short)dist;
  iVar3 = 0;
  p_Var4 = Pvl_Platforms;
  if (0 < p_Var1->n_platforms) {
    do {
      if ((*plVar5 != 0) && (iVar2 != 0)) {
        Boxes_TestList(ot,&(p_Var4->obj).child,Boxes_IsObjectInDistance);
      }
      iVar2 = iVar2 << 1;
      if (iVar2 == 0) {
        plVar5 = plVar5 + 1;
        iVar2 = 1;
      }
      iVar3 = iVar3 + 1;
      p_Var4 = (_PLATFORM *)&p_Var4[1].obj.last_pos.vz;
    } while (iVar3 < (int)Pvl_File->n_platforms);
  }
  Boxes_TestList(ot,&Pvl_HoleObjects,Boxes_IsObjectInDistance);
  Boxes_TestList(ot,&Pvl_GlobalObjects,Boxes_IsObjectInDistance);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Boxes_TestPoint(struct _D3_OBJECT *ot /*$s2*/)
 // line 336, offset 0x8001f228
	/* begin block 1 */
		// Start line: 337
		// Start offset: 0x8001F228
		// Variables:
	// 		struct _PLATFORM *p; // $a0
	// 		struct _PLATFORM (*ps[4]); // stack offset -64
	// 		struct BOXES_7fake pos; // stack offset -48
	// 		long i; // $s0
	// 		long j; // $a2
	// 		long found; // $s3
	// 		long pfound; // $s5
	// 		long dx; // $s7
	// 		long dy; // $s4
	/* end block 1 */
	// End offset: 0x8001F3B8
	// End Line: 394

	/* begin block 2 */
		// Start line: 792
	/* end block 2 */
	// End Line: 793

/* WARNING: Could not reconcile some variable overlaps */

long Boxes_TestPoint(_D3_OBJECT *ot)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  _PLATFORM *p;
  uint uVar6;
  _PLATFORM **pp_Var7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  _PLATFORM **pp_Var11;
  uint uVar12;
  int iVar13;
  _PLATFORM *local_40 [4];
  undefined4 local_30;
  uint local_2c;
  
  uVar12 = 0;
  iVar13 = 0;
  iVar10 = 0;
  local_30 = *(undefined4 *)&ot->last_pos;
  local_2c = *(uint *)&(ot->last_pos).vz;
  sVar1 = (ot->pos).vx;
  sVar2 = (ot->last_pos).vx;
  sVar3 = (ot->last_pos).vy;
  sVar4 = (ot->pos).vy;
  pp_Var11 = local_40;
  do {
    sVar5 = (short)((int)sVar4 - (int)sVar3 >> 2);
    local_2c = local_2c & 0xffff0000 | (uint)(ushort)((short)local_2c + sVar5);
    local_30 = CONCAT22((short)((uint)local_30 >> 0x10) + sVar5,
                        (short)local_30 + (short)((int)sVar1 - (int)sVar2 >> 2));
    p = Plat_GetPlat(0xd0);
    *pp_Var11 = p;
    if (p != (_PLATFORM *)0x0) {
      iVar13 = iVar13 + 1;
    }
    iVar8 = 0;
    pp_Var7 = local_40;
    if (0 < iVar10) {
      do {
        if (p == (_PLATFORM *)0x0) goto LAB_8001f340;
        if (*pp_Var11 == *pp_Var7) {
          *pp_Var11 = (_PLATFORM *)0x0;
          p = (_PLATFORM *)0x0;
        }
        iVar8 = iVar8 + 1;
        pp_Var7 = pp_Var7 + 1;
      } while (iVar8 < iVar10);
    }
    if (p != (_PLATFORM *)0x0) {
      uVar6 = Boxes_TestPlatform(p,ot,Boxes_IsPointEnterInObject);
      uVar12 = uVar12 | uVar6;
    }
LAB_8001f340:
    iVar10 = iVar10 + 1;
    pp_Var11 = pp_Var11 + 1;
    if (3 < iVar10) {
      if (iVar13 < 4) {
        uVar6 = Boxes_TestList(ot,&Pvl_HoleObjects,Boxes_IsPointEnterInObject);
        uVar12 = uVar12 | uVar6;
      }
      uVar6 = Boxes_TestList(ot,&Pvl_GlobalObjects,Boxes_IsPointEnterInObject);
      if ((uVar12 | uVar6) != 0) {
        Boxes_ResultColls(ot);
        sVar1 = (ot->last_pos).vy;
        sVar2 = (ot->last_pos).vz;
        (ot->pos).vx = (ot->last_pos).vx;
        (ot->pos).vy = sVar1;
        (ot->pos).vz = sVar2;
      }
      uVar9 = *(undefined4 *)&(ot->pos).vz;
      *(undefined4 *)&ot->last_pos = *(undefined4 *)&ot->pos;
      *(undefined4 *)&(ot->last_pos).vz = uVar9;
      return uVar12 | uVar6;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// long /*$ra*/ Boxes_TestTransparent(struct _D3_OBJECT *ot /*$s1*/)
 // line 401, offset 0x8001f408
	/* begin block 1 */
		// Start line: 402
		// Start offset: 0x8001F408
	/* end block 1 */
	// End offset: 0x8001F408
	// End Line: 402

	/* begin block 2 */
		// Start line: 1018
	/* end block 2 */
	// End Line: 1019

long Boxes_TestTransparent(_D3_OBJECT *ot)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar1 = Boxes_TestPlatforms(ot,Boxes_IsObjectInObject);
  uVar2 = Boxes_TestList(ot,&Pvl_GlobalObjects,Boxes_IsObjectInObject);
  uVar3 = *(undefined4 *)&(ot->pos).vz;
  *(undefined4 *)&ot->last_pos = *(undefined4 *)&ot->pos;
  *(undefined4 *)&(ot->last_pos).vz = uVar3;
  return uVar1 | uVar2;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Boxes_TestPlatforms(struct _D3_OBJECT *ot /*$s3*/, TDRFuncPtr_Boxes_TestPlatforms1function function /*$s6*/)
 // line 419, offset 0x8001f484
	/* begin block 1 */
		// Start line: 420
		// Start offset: 0x8001F484
		// Variables:
	// 		struct _PLATFORM *p; // $a0
	// 		struct _PLATFORM (*ps[8]); // stack offset -80
	// 		struct BOXES_7fake t; // stack offset -48
	// 		long i; // $s0
	// 		long j; // $v1
	// 		long found; // $s1
	// 		long hole; // $s5
	/* end block 1 */
	// End offset: 0x8001F6C8
	// End Line: 476

	/* begin block 2 */
		// Start line: 1064
	/* end block 2 */
	// End Line: 1065

/* WARNING: Could not reconcile some variable overlaps */

long Boxes_TestPlatforms(_D3_OBJECT *ot,TDRFuncPtr_Boxes_TestPlatforms1function function)

{
  bool bVar1;
  _PLATFORM *p;
  int iVar2;
  _PLATFORM **pp_Var3;
  _D3_OBJECT *p_Var4;
  uint uVar5;
  _D3_OBJECT *p_Var6;
  int iVar7;
  uint uVar8;
  _PLATFORM **pp_Var9;
  _PLATFORM *local_50 [4];
  _PLATFORM *local_40 [4];
  undefined4 local_30;
  uint local_2c;
  
  uVar8 = 0;
  iVar7 = 0;
  bVar1 = false;
  pp_Var9 = local_50;
  p_Var4 = ot;
  do {
    uVar5 = *(uint *)&(p_Var4->b_box).vz;
    local_30._0_2_ = (short)*(undefined4 *)&p_Var4->b_box;
    local_30 = CONCAT22((short)((uint)*(undefined4 *)&p_Var4->b_box >> 0x10) + (ot->last_pos).vy,
                        (short)local_30 + (ot->last_pos).vx);
    local_2c._0_2_ = (short)uVar5;
    local_2c = uVar5 & 0xffff0000 | (uint)(ushort)((short)local_2c + (ot->last_pos).vz);
    p = Plat_GetPlat(0xd0);
    iVar2 = 0;
    *pp_Var9 = p;
    pp_Var3 = local_50;
    if (0 < iVar7) {
      do {
        iVar2 = iVar2 + 1;
        if (p == *pp_Var3) {
          p = (_PLATFORM *)0x0;
          break;
        }
        pp_Var3 = pp_Var3 + 1;
      } while (iVar2 < iVar7);
    }
    if (p == (_PLATFORM *)0x0) {
      if ((!bVar1) && (*pp_Var9 == (_PLATFORM *)0x0)) {
        bVar1 = true;
        uVar5 = Boxes_TestList(ot,&Pvl_HoleObjects,(TDRFuncPtr_Boxes_TestList2function)function);
        uVar8 = uVar8 | uVar5;
      }
    }
    else {
      uVar5 = Boxes_TestPlatform(p,ot,(TDRFuncPtr_Boxes_TestPlatform2function)function);
      uVar8 = uVar8 | uVar5;
    }
    pp_Var9 = pp_Var9 + 1;
    iVar7 = iVar7 + 1;
    p_Var4 = (_D3_OBJECT *)&p_Var4->child;
  } while (iVar7 < 4);
  iVar7 = 4;
  pp_Var9 = local_40;
  do {
    p_Var4 = (&ot->next + (iVar7 + -4) * 2)[0x13];
    p_Var6 = (&ot->next + (iVar7 + -4) * 2)[0x14];
    local_30._0_2_ = (short)p_Var4;
    local_30 = CONCAT22((short)((uint)p_Var4 >> 0x10) + (ot->pos).vy,(short)local_30 + (ot->pos).vx)
    ;
    local_2c._0_2_ = (short)p_Var6;
    local_2c = (uint)p_Var6 & 0xffff0000 | (uint)(ushort)((short)local_2c + (ot->pos).vz);
    p = Plat_GetPlat(0xd0);
    iVar2 = 0;
    *pp_Var9 = p;
    pp_Var3 = local_50;
    if (0 < iVar7) {
      do {
        iVar2 = iVar2 + 1;
        if (p == *pp_Var3) {
          p = (_PLATFORM *)0x0;
          break;
        }
        pp_Var3 = pp_Var3 + 1;
      } while (iVar2 < iVar7);
    }
    if (p == (_PLATFORM *)0x0) {
      if ((!bVar1) && (*pp_Var9 == (_PLATFORM *)0x0)) {
        bVar1 = true;
        uVar5 = Boxes_TestList(ot,&Pvl_HoleObjects,(TDRFuncPtr_Boxes_TestList2function)function);
        uVar8 = uVar8 | uVar5;
      }
    }
    else {
      uVar5 = Boxes_TestPlatform(p,ot,(TDRFuncPtr_Boxes_TestPlatform2function)function);
      uVar8 = uVar8 | uVar5;
    }
    iVar7 = iVar7 + 1;
    pp_Var9 = pp_Var9 + 1;
    if (7 < iVar7) {
      return uVar8;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// long /*$ra*/ Boxes_TestPlatform(struct _PLATFORM *p /*$s0*/, struct _D3_OBJECT *ot /*$s2*/, TDRFuncPtr_Boxes_TestPlatform2function function /*$s3*/)
 // line 480, offset 0x8001f6f8
	/* begin block 1 */
		// Start line: 481
		// Start offset: 0x8001F6F8
		// Variables:
	// 		long z; // $v1
	// 		long found; // $s1
	/* end block 1 */
	// End offset: 0x8001F780
	// End Line: 494

	/* begin block 2 */
		// Start line: 1284
	/* end block 2 */
	// End Line: 1285

long Boxes_TestPlatform(_PLATFORM *p,_D3_OBJECT *ot,TDRFuncPtr_Boxes_TestPlatform2function function)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  if ((((*(char *)((int)&p[1].obj.pos.vx + 1) != '\0') && (iVar4 = (int)p[1].obj.pos.vy, iVar4 != 0)
       ) && ((int)(ot->pos).vz < (int)(p->obj).pos.vz + (int)*(short *)&p[1].obj.prec + iVar4 + -5))
     && (fReset == 0)) {
    uVar1 = ot->collision_state;
    *(_PLATFORM **)&ot[1].color = p;
    ot->collision_state = uVar1 | 0x20;
  }
  uVar2 = (*function)(ot,p);
  uVar3 = Boxes_TestList(ot,&(p->obj).child,(TDRFuncPtr_Boxes_TestList2function)function);
  return uVar2 | uVar3;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Boxes_TestList(struct _D3_OBJECT *ot /*$s2*/, struct _D3_OBJECT **list /*$a1*/, TDRFuncPtr_Boxes_TestList2function function /*$s3*/)
 // line 503, offset 0x8001f7c0
	/* begin block 1 */
		// Start line: 504
		// Start offset: 0x8001F7C0
		// Variables:
	// 		struct _D3_OBJECT *obj; // $s0
	// 		long found; // $s1
	/* end block 1 */
	// End offset: 0x8001F834
	// End Line: 517

	/* begin block 2 */
		// Start line: 1332
	/* end block 2 */
	// End Line: 1333

long Boxes_TestList(_D3_OBJECT *ot,_D3_OBJECT **list,TDRFuncPtr_Boxes_TestList2function function)

{
  uint uVar1;
  _D3_OBJECT *p_Var2;
  uint uVar3;
  
  uVar3 = 0;
  p_Var2 = *list;
  while (p_Var2 != (_D3_OBJECT *)0x0) {
    if (p_Var2->child != (_D3_OBJECT *)0x0) {
      uVar1 = Boxes_TestList(ot,&p_Var2->child,function);
      uVar3 = uVar3 | uVar1;
    }
    if (ot != p_Var2) {
      uVar1 = (*function)(ot,p_Var2);
      uVar3 = uVar3 | uVar1;
    }
    p_Var2 = p_Var2->next;
  }
  return uVar3;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Boxes_IsObjectInObject(struct _D3_OBJECT *ot /*$s3*/, struct _D3_OBJECT *obj /*$s2*/)
 // line 521, offset 0x8001f854
	/* begin block 1 */
		// Start line: 522
		// Start offset: 0x8001F854
		// Variables:
	// 		struct BOXES_7fake p; // stack offset -64
	// 		long txmin; // $s1
	// 		long txmax; // stack offset -56
	// 		long tymin; // stack offset -52
	// 		long tymax; // stack offset -48
	// 		long tzmin; // stack offset -44
	// 		long tzmax; // $fp
	// 		long oxmin; // $s7
	// 		long oxmax; // $s0
	// 		long oymin; // $s6
	// 		long oymax; // $s4
	// 		long ozmin; // $s5
	// 		long ozmax; // $v1
	/* end block 1 */
	// End offset: 0x8001F9B0
	// End Line: 562

	/* begin block 2 */
		// Start line: 1378
	/* end block 2 */
	// End Line: 1379

long Boxes_IsObjectInObject(_D3_OBJECT *ot,_D3_OBJECT *obj)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  short sVar9;
  short sVar10;
  short sVar11;
  short sVar12;
  long lVar13;
  int x;
  int y;
  int iVar14;
  int iVar15;
  short local_40;
  short local_3e;
  short local_3c;
  
  if ((*(uint *)&obj->collision_mode & 0x2001) == 1) {
    Boxes_RotPos(obj,(char)obj + '4',(char)ot + ',',0xc0);
    x = (int)local_40;
    y = (int)local_3e;
    sVar1 = (ot->b_box).vx;
    sVar2 = *(short *)((int)&ot->b_sunk + 2);
    sVar3 = *(short *)&ot->b_step;
    sVar4 = (ot->b_box).vy;
    sVar5 = (ot->b_box).vz;
    sVar6 = *(short *)&ot[1].prec;
    iVar15 = (int)(obj->pos).vx;
    sVar7 = (obj->b_box).vx;
    iVar14 = (int)(obj->pos).vy;
    sVar8 = *(short *)&obj->b_step;
    sVar9 = *(short *)((int)&obj->b_sunk + 2);
    sVar10 = (obj->pos).vz;
    sVar11 = (obj->b_box).vy;
    sVar12 = (obj->b_box).vz;
    lVar13 = Boxes_GetRealZ(obj,x,y);
    if (x + (int)sVar1 < iVar15 + (int)sVar8) {
      if (x + (int)sVar3 <= iVar15 + (int)sVar7) {
        return 0;
      }
      if (iVar14 + (int)sVar11 <= y + (int)sVar2) {
        return 0;
      }
      if (y + (int)sVar4 <= iVar14 + (int)sVar9) {
        return 0;
      }
      if (((int)local_3c + (int)sVar5 < (int)(obj->pos).vz + lVar13) &&
         ((int)sVar10 + (int)sVar12 < (int)local_3c + (int)sVar6)) {
        lVar13 = Boxes_ObjectFound(ot,obj,0x400);
        return lVar13;
      }
    }
  }
  return 0;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Boxes_IsObjectInDistance(struct _D3_OBJECT *ot /*$s0*/, struct _D3_OBJECT *obj /*$s1*/)
 // line 565, offset 0x8001f9e0
	/* begin block 1 */
		// Start line: 1497
	/* end block 1 */
	// End Line: 1498

long Boxes_IsObjectInDistance(_D3_OBJECT *ot,_D3_OBJECT *obj)

{
  long lVar1;
  
  if ((obj->collision_mode & 1U) != 0) {
    lVar1 = Distance3D((int)(ot->pos).vx,(int)(ot->pos).vy,(int)(ot->pos).vz,(int)(obj->pos).vx,
                       (int)(obj->pos).vy,(int)(obj->pos).vz);
    if (lVar1 <= (int)(ot->b_box).vx) {
      Boxes_ObjectFound(ot,obj,0x400);
    }
  }
  return 0;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Boxes_IsPointEnterInObject(struct _D3_OBJECT *ot /*stack 0*/, struct _D3_OBJECT *obj /*$s5*/)
 // line 575, offset 0x8001fa64
	/* begin block 1 */
		// Start line: 576
		// Start offset: 0x8001FA64
		// Variables:
	// 		struct BOXES_7fake *po; // $s0
	// 		struct BOXES_7fake t1; // stack offset -72
	// 		struct BOXES_7fake t2; // stack offset -64
	// 		long coeff; // $s4
	// 		long minx; // stack offset -56
	// 		long miny; // $fp
	// 		long minz; // stack offset -52
	// 		long maxx; // $s7
	// 		long maxy; // $s6
	// 		long minmax; // $a2
	// 		long tzo; // stack offset -48
	// 		long bits; // $s3
	// 		long txt; // $s1
	// 		long tyt; // $s2
	// 		long tzt; // $s0
	/* end block 1 */
	// End offset: 0x80020038
	// End Line: 730

	/* begin block 2 */
		// Start line: 1517
	/* end block 2 */
	// End Line: 1518

long Boxes_IsPointEnterInObject(_D3_OBJECT *ot,_D3_OBJECT *obj)

{
  int iVar1;
  long minmax;
  int iVar2;
  int iVar3;
  int x;
  char po;
  int iVar4;
  int local_50;
  int iVar5;
  int x_00;
  int y;
  long bits;
  int unaff_s4;
  int min;
  short local_48;
  short local_46;
  short local_44;
  short local_40;
  short local_3e;
  short local_3c;
  short local_38;
  
  if ((obj->collision_mode & 1U) == 0) {
LAB_80020034:
    bits = 0;
  }
  else {
    po = (char)obj + '4';
    iVar4 = (int)(obj->last_pos).vx;
    iVar1 = (int)(obj->b_box).vx + iVar4;
    local_50 = (int)(obj->last_pos).vy;
    iVar5 = (int)(obj->last_pos).vz;
    iVar4 = (int)*(short *)&obj->b_step + iVar4;
    min = (int)*(short *)((int)&obj->b_sunk + 2) + local_50;
    local_50 = (int)(obj->b_box).vy + local_50;
    iVar2 = (int)(obj->b_box).vz + iVar5;
    Boxes_RotPos(obj,po,(char)ot + ',',0xb8);
    Boxes_RotPos(obj,po,(char)ot + '4',0xc0);
    iVar3 = (int)local_48;
    x = (int)local_40;
    bits = 0;
    if (iVar3 < x) {
      if ((((int)Boxes_MiniX < iVar4) && (iVar3 < iVar4)) && (iVar4 <= x)) {
        bits = 0x400;
        x_00 = iVar4;
      }
    }
    else {
      if ((((x < iVar3) && (iVar1 < (int)Boxes_MaxiX)) && (iVar1 < iVar3)) && (x <= iVar1)) {
        bits = 0x800;
        x_00 = iVar1;
      }
    }
    if (bits == 0) {
LAB_8001fce4:
      iVar3 = (int)local_46;
      x = (int)local_3e;
      bits = 0;
      if (iVar3 < x) {
        if ((((int)Boxes_MiniY < local_50) && (iVar3 < local_50)) && (local_50 <= x)) {
          bits = 0x1000;
          y = local_50;
        }
      }
      else {
        if (((x < iVar3) && (min < (int)Boxes_MaxiY)) && ((min < iVar3 && (x <= min)))) {
          bits = 0x2000;
          y = min;
        }
      }
      if (bits != 0) {
        x = (y - (int)local_3e) * 0x10000;
        iVar3 = (int)local_46 - (int)local_3e;
        unaff_s4 = x / iVar3;
        if (iVar3 == 0) {
          trap(0x1c00);
        }
        if ((iVar3 == -1) && (x == -0x80000000)) {
          trap(0x1800);
        }
        if (unaff_s4 < 0) {
          unaff_s4 = -unaff_s4;
        }
        x = (((int)local_48 - (int)local_40) * unaff_s4 + 0x8000 >> 0x10) + (int)local_40;
        iVar3 = (((int)local_44 - (int)local_3c) * unaff_s4 + 0x8000 >> 0x10) + (int)local_3c;
        if ((((x < iVar4) && (iVar1 < x)) &&
            (minmax = Boxes_GetRealZ(obj,x,y), iVar3 < minmax + iVar5)) && (iVar2 < iVar3)) {
          minmax = Boxes_AcceptObjectFound(ot,obj,bits);
          if (minmax == 0) goto LAB_80020034;
          if (bits == 0x1000) {
            Boxes_MiniY = (short)local_50;
            min = local_50;
          }
          else {
            Boxes_MaxiY = (short)min;
          }
          minmax = min * 0x10000 >> 0x10;
          min = iVar1;
          local_50 = iVar4;
          goto LAB_8001feb0;
        }
      }
      iVar3 = (int)local_44;
      x = (int)local_3c;
      bits = 0;
      if (((x < iVar3) && (iVar2 < iVar3)) && (x <= iVar2)) {
        iVar2 = (iVar2 - x) * 0x10000;
        iVar3 = iVar3 - x;
        unaff_s4 = iVar2 / iVar3;
        if (iVar3 == 0) {
          trap(0x1c00);
        }
        if ((iVar3 == -1) && (iVar2 == -0x80000000)) {
          trap(0x1800);
        }
        bits = 0x4000;
        if (unaff_s4 < 0) {
          unaff_s4 = -unaff_s4;
        }
      }
      if (bits == 0) {
        minmax = Boxes_GetRealZ(obj,(int)local_48,(int)local_46);
        if (((int)local_44 < minmax + iVar5) &&
           (minmax = Boxes_GetRealZ(obj,(int)local_40,(int)local_3e),
           minmax + iVar5 <= (int)local_3c)) {
          bits = 0x8000;
          unaff_s4 = 0x10000;
        }
        if (bits == 0) {
          return 0;
        }
      }
      iVar2 = (((int)local_48 - (int)local_40) * unaff_s4 + 0x8000 >> 0x10) + (int)local_40;
      iVar3 = (((int)local_46 - (int)local_3e) * unaff_s4 + 0x8000 >> 0x10) + (int)local_3e;
      if ((((iVar4 <= iVar2) || (iVar2 <= iVar1)) || (local_50 <= iVar3)) ||
         ((iVar3 <= min || (minmax = Boxes_AcceptObjectFound(ot,obj,bits), minmax == 0))))
      goto LAB_80020034;
      local_50 = 0;
      minmax = 0;
      min = 0;
    }
    else {
      x = (x_00 - (int)local_40) * 0x10000;
      iVar3 = (int)local_48 - (int)local_40;
      unaff_s4 = x / iVar3;
      if (iVar3 == 0) {
        trap(0x1c00);
      }
      if ((iVar3 == -1) && (x == -0x80000000)) {
        trap(0x1800);
      }
      if (unaff_s4 < 0) {
        unaff_s4 = -unaff_s4;
      }
      y = (((int)local_46 - (int)local_3e) * unaff_s4 + 0x8000 >> 0x10) + (int)local_3e;
      iVar3 = (((int)local_44 - (int)local_3c) * unaff_s4 + 0x8000 >> 0x10) + (int)local_3c;
      if ((((local_50 <= y) || (y <= min)) ||
          (minmax = Boxes_GetRealZ(obj,x_00,y), minmax + iVar5 <= iVar3)) || (iVar3 <= iVar2))
      goto LAB_8001fce4;
      minmax = Boxes_AcceptObjectFound(ot,obj,bits);
      if (minmax == 0) goto LAB_80020034;
      if (bits == 0x400) {
        Boxes_MiniX = (short)iVar4;
        minmax = iVar4 * 0x10000 >> 0x10;
      }
      else {
        local_38 = (short)iVar1;
        Boxes_MaxiX = local_38;
        minmax = (long)local_38;
      }
    }
LAB_8001feb0:
    Boxes_AddColl(obj,bits,minmax,min,local_50);
    bits = 1;
  }
  return bits;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Boxes_IsObjectBaseEnterInObject(struct _D3_OBJECT *ot /*$s2*/, struct _D3_OBJECT *obj /*$s1*/)
 // line 733, offset 0x80020068
	/* begin block 1 */
		// Start line: 734
		// Start offset: 0x80020068
		// Variables:
	// 		struct BOXES_7fake *po; // $s0
	// 		struct BOXES_7fake t1; // stack offset -56
	// 		struct BOXES_7fake t2; // stack offset -48
	// 		long test; // $s0
	// 		long txt; // $a0
	// 		long tyt; // $a1
	// 		long txo; // $s6
	// 		long tyo; // $s7
	// 		long tzo; // $s5
	// 		long a; // $s3
	// 		long d; // $s4

		/* begin block 1.1 */
			// Start line: 760
			// Start offset: 0x800200F8
			// Variables:
		// 		long testd; // $a0
		/* end block 1.1 */
		// End offset: 0x800201FC
		// End Line: 786
	/* end block 1 */
	// End offset: 0x80020200
	// End Line: 790

	/* begin block 2 */
		// Start line: 1941
	/* end block 2 */
	// End Line: 1942

long Boxes_IsObjectBaseEnterInObject(_D3_OBJECT *ot,_D3_OBJECT *obj)

{
  int iVar1;
  long lVar2;
  char po;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  short local_38;
  short local_36;
  short local_34;
  short local_30;
  short local_2e;
  short local_2c;
  
  if ((*(uint *)&obj->collision_mode & 0x2001) == 1) {
    po = (char)obj + '4';
    iVar5 = (int)(obj->last_pos).vx;
    iVar6 = (int)(obj->last_pos).vy;
    iVar4 = (int)(obj->last_pos).vz;
    Boxes_RotPos(obj,po,(char)ot + ',',200);
    Boxes_RotPos(obj,po,(char)ot + '4',0xd0);
    if ((int)local_34 < (int)local_2c) {
      iVar1 = (int)(ot->b_box).vz;
      lVar2 = Boxes_GetRealZ(obj,(int)local_38,(int)local_36);
      iVar3 = lVar2 + iVar4;
      lVar2 = Boxes_GetRealZ(obj,(int)local_30,(int)local_2e);
      if (((int)Boxes_MiniZ < iVar3) && ((int)local_34 + iVar1 < iVar3)) {
        if ((int)local_2c + iVar1 < lVar2 + iVar4) {
          return 0;
        }
        if ((int)*(short *)&obj->b_step + iVar5 <= (int)(ot->b_box).vx + (int)local_38) {
          return 0;
        }
        if ((int)*(short *)&ot->b_step + (int)local_38 <= (int)(obj->b_box).vx + iVar5) {
          return 0;
        }
        if ((int)(ot->b_box).vy + (int)local_36 <= (int)*(short *)((int)&obj->b_sunk + 2) + iVar6) {
          return 0;
        }
        if ((int)(obj->b_box).vy + iVar6 <= (int)*(short *)((int)&ot->b_sunk + 2) + (int)local_36) {
          return 0;
        }
        if (fReset != 0) {
          return 0;
        }
        Boxes_MiniZ = (short)iVar3;
        Boxes_Collp = 0x4000;
        Boxes_Collz = obj;
        lVar2 = Boxes_ObjectFound(ot,obj,0x4000);
        return lVar2;
      }
    }
  }
  return 0;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Boxes_IsObjectEnterInObject(struct _D3_OBJECT *ot /*$s3*/, struct _D3_OBJECT *obj /*stack 4*/)
 // line 793, offset 0x8002022c
	/* begin block 1 */
		// Start line: 794
		// Start offset: 0x8002022C
		// Variables:
	// 		struct BOXES_7fake *po; // $s0
	// 		struct BOXES_7fake t1; // stack offset -80
	// 		struct BOXES_7fake t2; // stack offset -72
	// 		long txt; // $t1
	// 		long tyt; // $t2
	// 		long tzt; // $fp
	// 		long minx; // $s7
	// 		long maxx; // $s4
	// 		long miny; // $s6
	// 		long maxy; // $s5
	// 		long minz; // $t0
	// 		long maxz; // $t3
	// 		long tzo; // stack offset -64
	// 		long a; // $s0
	// 		long d; // $s1
	// 		long bits; // $s2
	// 		long minmax; // $a2

		/* begin block 1.1 */
			// Start line: 952
			// Start offset: 0x80020644
			// Variables:
		// 		long maxzd; // $a0
		/* end block 1.1 */
		// End offset: 0x800206B4
		// End Line: 961
	/* end block 1 */
	// End offset: 0x80020784
	// End Line: 994

	/* begin block 2 */
		// Start line: 2077
	/* end block 2 */
	// End Line: 2078

long Boxes_IsObjectEnterInObject(_D3_OBJECT *ot,_D3_OBJECT *obj)

{
  short sVar1;
  long lVar2;
  int iVar3;
  int bits;
  char po;
  int max;
  int iVar4;
  int max_00;
  int iVar5;
  int x;
  int y;
  int iVar6;
  int bits_00;
  int min;
  int min_00;
  int iVar7;
  short local_50;
  short local_4e;
  short local_4c;
  short local_48;
  short local_46;
  short local_44;
  
  if ((*(uint *)&obj->collision_mode & 0x2001) == 1) {
    po = (char)obj + '4';
    sVar1 = (obj->last_pos).vz;
    Boxes_RotPos(obj,po,(char)ot + ',',0xb0);
    Boxes_RotPos(obj,po,(char)ot + '4',0xb8);
    bits_00 = 0;
    x = (int)local_50;
    y = (int)local_4e;
    max_00 = (int)(obj->last_pos).vy;
    iVar7 = (int)local_4c;
    max = (int)(obj->last_pos).vx;
    min_00 = max + (int)(obj->b_box).vx;
    max = max + (int)*(short *)&obj->b_step;
    min = max_00 + (int)*(short *)((int)&obj->b_sunk + 2);
    max_00 = max_00 + (int)(obj->b_box).vy;
    iVar5 = (int)(obj->last_pos).vz + (int)(obj->b_box).vz;
    lVar2 = Boxes_GetRealZ(obj,x,y);
    iVar4 = (int)local_50;
    bits = (int)local_48;
    iVar6 = (int)(obj->last_pos).vz + lVar2;
    if (iVar4 < bits) {
      iVar3 = (int)(ot->b_box).vx;
      if (((int)Boxes_MiniX < max) && (iVar4 + iVar3 < max)) {
        bits_00 = ((uint)(bits + iVar3 < max) ^ 1) << 10;
      }
    }
    else {
      if (bits < iVar4) {
        if (((min_00 < (int)Boxes_MaxiX) && (min_00 < iVar4 + (int)*(short *)&ot->b_step)) &&
           (bits + (int)*(short *)&ot->b_step <= min_00)) {
          bits_00 = 0x800;
        }
      }
    }
    if ((((bits_00 == 0) || (max_00 <= (int)Boxes_MiniY)) ||
        (((int)Boxes_MaxiY <= min ||
         (((max_00 <= (int)*(short *)((int)&ot->b_sunk + 2) + y || ((int)(ot->b_box).vy + y <= min))
          || (iVar6 <= (int)(ot->b_box).vz + iVar7)))))) ||
       ((int)*(short *)&ot[1].prec + iVar7 <= iVar5)) {
      iVar4 = (int)local_4e;
      bits = (int)local_46;
      bits_00 = 0;
      if (iVar4 < bits) {
        iVar3 = (int)*(short *)((int)&ot->b_sunk + 2);
        if (((int)Boxes_MiniY < max_00) && (iVar4 + iVar3 < max_00)) {
          bits_00 = ((uint)(bits + iVar3 < max_00) ^ 1) << 0xc;
        }
      }
      else {
        if (bits < iVar4) {
          iVar3 = (int)(ot->b_box).vy;
          if (((min < (int)Boxes_MaxiY) && (min < iVar4 + iVar3)) && (bits + iVar3 <= min)) {
            bits_00 = 0x2000;
          }
        }
      }
      if (((((bits_00 == 0) || (max <= (int)Boxes_MiniX)) || ((int)Boxes_MaxiX <= min_00)) ||
          ((max <= (int)(ot->b_box).vx + x || ((int)*(short *)&ot->b_step + x <= min_00)))) ||
         ((iVar6 <= (int)(ot->b_box).vz + iVar7 || ((int)*(short *)&ot[1].prec + iVar7 <= iVar5))))
      {
        bits = 0;
        if ((int)local_44 < (int)local_4c) {
          if ((iVar5 < (int)Boxes_MaxiZ) && (iVar5 < (int)local_4c + (int)*(short *)&ot[1].prec)) {
            bits = ((uint)(iVar5 < (int)local_44 + (int)*(short *)&ot[1].prec) ^ 1) << 0xf;
          }
        }
        if (bits == 0) {
          iVar4 = (int)(ot->b_box).vz;
          lVar2 = Boxes_GetRealZ(obj,(int)local_48,(int)local_46);
          if ((((int)Boxes_MiniZ < iVar6) && ((int)local_4c + iVar4 < iVar6)) &&
             (lVar2 + (int)sVar1 <= (int)local_44 + iVar4)) {
            bits = 0x4000;
          }
          if (bits == 0) {
            return 0;
          }
        }
        if (max <= (int)(ot->b_box).vx + x) {
          return 0;
        }
        if ((int)*(short *)&ot->b_step + x <= min_00) {
          return 0;
        }
        if ((int)(ot->b_box).vy + y <= min) {
          return 0;
        }
        if (max_00 <= (int)*(short *)((int)&ot->b_sunk + 2) + y) {
          return 0;
        }
        if (fReset != 0) {
          fEnterZ = 1;
          return 1;
        }
        sVar1 = (short)iVar5;
        if (bits == 0x4000) {
          Boxes_MiniZ = (short)iVar6;
          sVar1 = Boxes_MaxiZ;
        }
        Boxes_MaxiZ = sVar1;
        lVar2 = Boxes_ObjectFound(ot,obj,bits);
        if (lVar2 != 0) {
          Boxes_Collp = (short)bits;
          Boxes_Collz = obj;
          return 1;
        }
      }
      else {
        if (fReset != 0) {
          return 1;
        }
        lVar2 = Boxes_AcceptObjectFound(ot,obj,bits_00);
        if (lVar2 != 0) {
          if (bits_00 == 0x1000) {
            Boxes_MiniY = (short)max_00;
            min = max_00;
          }
          else {
            Boxes_MaxiY = (short)min;
          }
          Boxes_AddColl(obj,bits_00,min * 0x10000 >> 0x10,min_00,max);
          return 1;
        }
      }
    }
    else {
      if (fReset != 0) {
        return 1;
      }
      lVar2 = Boxes_AcceptObjectFound(ot,obj,bits_00);
      if (lVar2 != 0) {
        if (bits_00 == 0x400) {
          Boxes_MiniX = (short)max;
          min_00 = max;
        }
        else {
          Boxes_MaxiX = (short)min_00;
        }
        Boxes_AddColl(obj,bits_00,min_00 * 0x10000 >> 0x10,min,max_00);
        return 1;
      }
    }
  }
  return 0;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Boxes_AcceptObjectFound(struct _D3_OBJECT *ot /*$s0*/, struct _D3_OBJECT *obj /*$s1*/, long bits /*$s2*/)
 // line 997, offset 0x800207b4
	/* begin block 1 */
		// Start line: 2535
	/* end block 1 */
	// End Line: 2536

long Boxes_AcceptObjectFound(_D3_OBJECT *ot,_D3_OBJECT *obj,long bits)

{
  long lVar1;
  
  if ((((ot->collision_mode & 0x1000U) != 0) || ((obj->collision_mode & 0x1000U) != 0)) &&
     (lVar1 = Pl_AcceptCollisioned(ot,obj,bits), lVar1 == 0)) {
    return 0;
  }
  if (((((int)ot->collision_mode & 0x8000U) != 0) || (((int)obj->collision_mode & 0x8000U) != 0)) &&
     (lVar1 = Monster_AcceptCollisioned(ot,obj,bits), lVar1 == 0)) {
    return 0;
  }
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Boxes_ObjectFound(struct _D3_OBJECT *ot /*$s1*/, struct _D3_OBJECT *obj /*$s0*/, long bits /*$s2*/)
 // line 1013, offset 0x8002086c
	/* begin block 1 */
		// Start line: 2567
	/* end block 1 */
	// End Line: 2568

long Boxes_ObjectFound(_D3_OBJECT *ot,_D3_OBJECT *obj,long bits)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  uchar uVar4;
  long lVar5;
  uint uVar6;
  char cVar7;
  
  if ((((ot->collision_mode & 0x1000U) != 0) || ((obj->collision_mode & 0x1000U) != 0)) &&
     (lVar5 = Pl_Collisioned(ot,obj,bits), lVar5 == 0)) {
    return 0;
  }
  if (((((int)ot->collision_mode & 0x8000U) != 0) || (((int)obj->collision_mode & 0x8000U) != 0)) &&
     (lVar5 = Monster_Collisioned(ot,obj,bits), lVar5 == 0)) {
    return 0;
  }
  cVar7 = *(char *)((int)&ot[1].pos.vx + 1);
  if ((cVar7 == -7) || (cVar7 == -0x14)) {
    if ((*(uint *)&obj[1].pos & 0xffffff00) == 0x20f00) {
      uVar2 = ot->collision_state;
      *(_D3_OBJECT **)&ot[1].description = obj;
      ot->collision_state = uVar2 | 2;
    }
    cVar7 = *(char *)((int)&ot[1].pos.vx + 1);
  }
  if ((cVar7 != -0xd) || (obj->comp_opt1 != 4)) {
    ot->collision_state = ot->collision_state | (ushort)bits;
    uVar2 = obj->collision_state;
    obj->collision_state = uVar2 | 1;
    if (((uVar2 & 0x20) == 0) &&
       ((cVar7 = *(char *)((int)&ot[1].pos.vx + 1), -2 < cVar7 || (cVar7 == -0x12)))) {
      uVar2 = obj->collision_state;
      *(_D3_OBJECT **)&obj[1].color = ot;
      obj->collision_state = uVar2 | 0x100;
    }
    if ((bits & 0x4000U) == 0) {
      if ((ot->collision_mode & 0x2000U) != 0) {
        *(_D3_OBJECT **)&ot[1].hit_points = obj;
      }
    }
    else {
      uVar2 = ot->collision_mode;
      *(_D3_OBJECT **)&ot[1].hit_points = obj;
      if ((uVar2 & 0x1000) != 0) {
        obj->collision_state = obj->collision_state | 0x10;
      }
    }
    if (((ot->collision_mode & 2U) != 0) && (((int)obj->collision_mode & 0x9000U) == 0)) {
      uVar2 = obj->collision_state;
      sVar1 = obj->hit_points;
      uVar3 = obj->hit_points;
      *(_D3_OBJECT **)&obj[1].description = ot;
      obj->collision_state = uVar2 | 2;
      if ((int)sVar1 != 0) {
        if ((int)((int)sVar1 - (uint)ot->hit_power) < 0) {
          uVar6 = 0;
        }
        else {
          uVar6 = (uint)uVar3 - (uint)ot->hit_power;
        }
        obj->hit_points = (short)uVar6;
        if ((uVar6 & 0xffff) != 0) {
          return 1;
        }
        if (obj->handle != (TASK *)0x0) {
          return 1;
        }
        if (((byte)(*(char *)((int)&ot[1].pos.vx + 1) + 0x20U) < 0x1a) &&
           ((*(ushort *)(*(int *)&ot[1].last_pos + 0x1c) & 0x1000) != 0)) {
          uVar4 = obj->exp;
          if (uVar4 == '\0') {
            uVar4 = '\x01';
          }
          obj->exp = uVar4;
          Pl_AddExperience(*(_PLAYER **)&ot[1].last_pos,obj);
        }
        D3_ExplodeObject(obj);
      }
    }
  }
  return 1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Boxes_ResultColls(struct _D3_OBJECT *ot /*$s2*/)
 // line 1095, offset 0x80020b14
	/* begin block 1 */
		// Start line: 1096
		// Start offset: 0x80020B14
		// Variables:
	// 		long i; // $s1
	/* end block 1 */
	// End offset: 0x80020C70
	// End Line: 1142

	/* begin block 2 */
		// Start line: 2740
	/* end block 2 */
	// End Line: 2741

void Boxes_ResultColls(_D3_OBJECT *ot)

{
  long *plVar1;
  _D3_OBJECT **pp_Var2;
  BOXES_106fake *pBVar3;
  int i;
  int iVar4;
  
  i = 0;
  if (0 < Boxes_nColls) {
    pBVar3 = &Boxes_Colls;
    do {
      if ((((pBVar3->plane & 0xc00U) != 0) &&
          ((((pBVar3->minmax != (int)Boxes_MiniX && (pBVar3->minmax != (int)Boxes_MaxiX)) ||
            (pBVar3->max <= (int)Boxes_MiniY)) || ((int)Boxes_MaxiY <= pBVar3->min)))) ||
         ((iVar4 = i, (pBVar3->plane & 0x3000U) != 0 &&
          (((pBVar3->minmax != (int)Boxes_MiniY && (pBVar3->minmax != (int)Boxes_MaxiY)) ||
           ((pBVar3->max <= (int)Boxes_MiniX || (iVar4 = i, (int)Boxes_MaxiX <= pBVar3->min))))))))
      {
        pBVar3 = (BOXES_106fake *)&pBVar3[-1].min;
        iVar4 = i + -1;
        Boxes_DelColl(i);
      }
      i = iVar4 + 1;
      pBVar3 = pBVar3 + 1;
    } while (i < (int)Boxes_nColls);
  }
  i = 0;
  if (0 < Boxes_nColls) {
    pBVar3 = &Boxes_Colls;
    do {
      pp_Var2 = &pBVar3->obj;
      plVar1 = &pBVar3->plane;
      pBVar3 = pBVar3 + 1;
      Boxes_ObjectFound(ot,*pp_Var2,*plVar1);
      i = i + 1;
    } while (i < (int)Boxes_nColls);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Boxes_ResetPos(struct _D3_OBJECT *ot /*$s1*/)
 // line 1145, offset 0x80020c88
	/* begin block 1 */
		// Start line: 1146
		// Start offset: 0x80020C88
		// Variables:
	// 		struct BOXES_6fake vel; // stack offset -40
	// 		struct BOXES_6fake *norm; // $v0
	// 		struct BOXES_7fake pt; // stack offset -24
	// 		struct _D3_OBJECT *obj; // $s0
	// 		long backoff; // $v0
	// 		long dx; // $v0
	// 		long dy; // $v0
	/* end block 1 */
	// End offset: 0x80020EB0
	// End Line: 1216

	/* begin block 2 */
		// Start line: 2878
	/* end block 2 */
	// End Line: 2879

/* WARNING: Could not reconcile some variable overlaps */

void Boxes_ResetPos(_D3_OBJECT *ot)

{
  short sVar1;
  short sVar2;
  _D3_OBJECT *o;
  long lVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 local_18;
  
  o = Boxes_Collz;
  if ((ot->collision_state & 0x4000U) != 0) {
    Boxes_RotPos(Boxes_Collz,(char)Boxes_Collz + '4',(char)ot + ',',0xe8);
    lVar3 = Boxes_GetRealZ(o,(int)(short)local_18,(int)local_18._2_2_);
    (ot->pos).vz = ((o->last_pos).vz + (short)lVar3) - (ot->b_box).vz;
  }
  if (((int)ot->collision_state & 0x8000U) != 0) {
    (ot->pos).vz = ((Boxes_Collz->last_pos).vz + (Boxes_Collz->b_box).vz) - *(short *)&ot[1].prec;
  }
  sVar2 = Boxes_nColls;
  if (Boxes_nColls != 0) {
    iVar4 = ((int)(ot->pos).vx - (int)(ot->last_pos).vx) * 0x1000;
    iVar5 = ((int)(ot->pos).vy - (int)(ot->last_pos).vy) * 0x1000;
    sVar1 = (ot->last_pos).vy;
    (ot->pos).vx = (ot->last_pos).vx;
    (ot->pos).vy = sVar1;
    if (sVar2 == 1) {
      iVar6 = (iVar4 * Boxes_Colls.normal.vx >> 0xc) + (iVar5 * Boxes_Colls.normal.vy >> 0xc);
      iVar7 = Boxes_Colls.normal.vy * iVar6;
      (ot->pos).vx = (ot->pos).vx + (short)(iVar4 - (Boxes_Colls.normal.vx * iVar6 >> 0xc) >> 0xc);
      (ot->pos).vy = (ot->pos).vy + (short)(iVar5 - (iVar7 >> 0xc) >> 0xc);
    }
  }
  lVar3 = Boxes_TestResetedObject(ot);
  sVar2 = fEnterZ;
  if (lVar3 != 0) {
    sVar1 = (ot->last_pos).vy;
    (ot->pos).vx = (ot->last_pos).vx;
    (ot->pos).vy = sVar1;
    if ((sVar2 != 0) && (((int)ot->collision_state & 0xc000U) == 0)) {
      Boxes_TestObject(ot);
    }
  }
  if ((ot->collision_mode & 0x20U) == 0) {
    if (ot->child != (_D3_OBJECT *)0x0) {
      Boxes_ResetList(ot->child,(char)ot + ',',0xe8);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Boxes_BounceObject(struct BOXES_7fake *spd /*$s0*/)
 // line 1220, offset 0x80020ec4
	/* begin block 1 */
		// Start line: 1221
		// Start offset: 0x80020EC4
		// Variables:
	// 		struct BOXES_6fake norm; // stack offset -40
	// 		struct BOXES_6fake vel; // stack offset -24
	// 		long backoff; // $a0
	// 		long i; // $a2
	/* end block 1 */
	// End offset: 0x8002104C
	// End Line: 1257

	/* begin block 2 */
		// Start line: 3037
	/* end block 2 */
	// End Line: 3038

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Boxes_BounceObject(undefined spd)

{
  _struct_1670 *p_Var1;
  undefined3 in_register_00000011;
  short *psVar2;
  BOXES_106fake *pBVar3;
  int iVar4;
  int iVar5;
  int local_28;
  int local_24;
  int local_20;
  
  psVar2 = (short *)CONCAT31(in_register_00000011,spd);
  if (Boxes_Collz != (_D3_OBJECT *)0x0) {
    Boxes_AddColl(Boxes_Collz,(int)Boxes_Collp,0,0,0);
  }
  iVar5 = (int)Boxes_nColls;
  iVar4 = 1;
  if (iVar5 != 0) {
    local_24 = Boxes_Colls.normal.vy;
    local_20 = Boxes_Colls.normal.vz;
    local_28 = Boxes_Colls.normal.vx;
    if (1 < iVar5) {
      pBVar3 = &BOXES_106fake_800b005c;
      do {
        local_28 = local_28 + (pBVar3->normal).vx >> 1;
        iVar4 = iVar4 + 1;
        local_24 = local_28 + (pBVar3->normal).vy >> 1;
        p_Var1 = &pBVar3->normal;
        pBVar3 = pBVar3 + 1;
        local_20 = local_28 + p_Var1->vz >> 1;
      } while (iVar4 < iVar5);
    }
    iVar4 = ((int)*psVar2 * local_28 >> 0xc) + ((int)psVar2[1] * local_24 >> 0xc) +
            ((int)psVar2[2] * local_20 >> 0xc) >> 4;
    *psVar2 = *psVar2 - (short)((local_28 >> 4) * iVar4 >> 3);
    psVar2[1] = psVar2[1] - (short)((local_24 >> 4) * iVar4 >> 3);
    psVar2[2] = psVar2[2] - (short)((local_20 >> 4) * iVar4 >> 3);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Boxes_BounceObject12(struct BOXES_6fake *spd /*$s0*/)
 // line 1261, offset 0x8002105c
	/* begin block 1 */
		// Start line: 1262
		// Start offset: 0x8002105C
		// Variables:
	// 		struct BOXES_6fake norm; // stack offset -40
	// 		struct BOXES_6fake vel; // stack offset -24
	// 		long backoff; // $a0
	// 		long i; // $a2
	/* end block 1 */
	// End offset: 0x800211E4
	// End Line: 1298

	/* begin block 2 */
		// Start line: 3141
	/* end block 2 */
	// End Line: 3142

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Boxes_BounceObject12(undefined spd)

{
  _struct_1670 *p_Var1;
  undefined3 in_register_00000011;
  int *piVar2;
  BOXES_106fake *pBVar3;
  int iVar4;
  int iVar5;
  int local_28;
  int local_24;
  int local_20;
  
  piVar2 = (int *)CONCAT31(in_register_00000011,spd);
  if (Boxes_Collz != (_D3_OBJECT *)0x0) {
    Boxes_AddColl(Boxes_Collz,(int)Boxes_Collp,0,0,0);
  }
  iVar5 = (int)Boxes_nColls;
  iVar4 = 1;
  if (iVar5 != 0) {
    local_24 = Boxes_Colls.normal.vy;
    local_20 = Boxes_Colls.normal.vz;
    local_28 = Boxes_Colls.normal.vx;
    if (1 < iVar5) {
      pBVar3 = &BOXES_106fake_800b005c;
      do {
        local_28 = local_28 + (pBVar3->normal).vx >> 1;
        iVar4 = iVar4 + 1;
        local_24 = local_28 + (pBVar3->normal).vy >> 1;
        p_Var1 = &pBVar3->normal;
        pBVar3 = pBVar3 + 1;
        local_20 = local_28 + p_Var1->vz >> 1;
      } while (iVar4 < iVar5);
    }
    iVar4 = (*piVar2 * local_28 >> 0xc) + (piVar2[1] * local_24 >> 0xc) +
            (piVar2[2] * local_20 >> 0xc) >> 4;
    *piVar2 = *piVar2 - ((local_28 >> 4) * iVar4 >> 3);
    piVar2[1] = piVar2[1] - ((local_24 >> 4) * iVar4 >> 3);
    piVar2[2] = piVar2[2] - ((local_20 >> 4) * iVar4 >> 3);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Boxes_ResetList(struct _D3_OBJECT *ot /*$s0*/, struct BOXES_7fake *new_p /*$s1*/, struct BOXES_7fake *last_p /*$s2*/)
 // line 1301, offset 0x800211f4
	/* begin block 1 */
		// Start line: 3243
	/* end block 1 */
	// End Line: 3244

void Boxes_ResetList(_D3_OBJECT *ot,undefined new_p,undefined last_p)

{
  undefined3 in_register_00000015;
  short *psVar1;
  undefined3 in_register_00000019;
  short *psVar2;
  
  psVar2 = (short *)CONCAT31(in_register_00000019,last_p);
  psVar1 = (short *)CONCAT31(in_register_00000015,new_p);
  if (ot != (_D3_OBJECT *)0x0) {
    do {
      if (ot->child != (_D3_OBJECT *)0x0) {
        Boxes_ResetList(ot->child,new_p,last_p);
      }
      if ((ot->display_mode & 1U) != 0) {
        (ot->pos).vx = (ot->pos).vx + (*psVar1 - *psVar2);
        (ot->pos).vy = (ot->pos).vy + (psVar1[1] - psVar2[1]);
        (ot->pos).vz = (ot->pos).vz + (psVar1[2] - psVar2[2]);
      }
      ot = ot->next;
    } while (ot != (_D3_OBJECT *)0x0);
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Boxes_GetHeightPlatform(struct _D3_OBJECT *ot /*$a0*/, struct BOXES_7fake *st /*$a1*/)
 // line 1320, offset 0x800212b4
	/* begin block 1 */
		// Start line: 1321
		// Start offset: 0x800212B4
		// Variables:
	// 		struct _PLATFORM *p; // $a0
	/* end block 1 */
	// End offset: 0x80021304
	// End Line: 1335

	/* begin block 2 */
		// Start line: 3290
	/* end block 2 */
	// End Line: 3291

long Boxes_GetHeightPlatform(_D3_OBJECT *ot,undefined1 st)

{
  ushort uVar1;
  _PLATFORM *p_Var2;
  long lVar3;
  
  p_Var2 = Plat_GetPlat(st);
  lVar3 = -0x7ffe;
  if (p_Var2 != (_PLATFORM *)0x0) {
    uVar1 = (p_Var2->obj).collision_mode;
    lVar3 = 0x7fff;
    if ((uVar1 & 0x800) == 0) {
      if ((uVar1 & 1) == 0) {
        lVar3 = -0x7ffe;
      }
      else {
        lVar3 = (int)*(short *)&p_Var2[1].obj.prec + (int)(p_Var2->obj).pos.vz;
      }
    }
  }
  return lVar3;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Boxes_GetHeight(struct _D3_OBJECT *ot /*$s2*/, struct BOXES_7fake *st /*$s1*/, short range /*$a2*/)
 // line 1338, offset 0x80021314
	/* begin block 1 */
		// Start line: 1339
		// Start offset: 0x80021314
		// Variables:
	// 		struct _PLATFORM *p; // $a2
	// 		long maxz; // $s0
	/* end block 1 */
	// End offset: 0x800213F0
	// End Line: 1373

	/* begin block 2 */
		// Start line: 3326
	/* end block 2 */
	// End Line: 3327

long Boxes_GetHeight(_D3_OBJECT *ot,undefined1 st,short range)

{
  _D3_OBJECT *p_Var1;
  long maxz;
  
  maxz = -0x7fff;
  Boxes_Object = (_D3_OBJECT *)0x0;
  gRange = range;
  p_Var1 = (_D3_OBJECT *)Plat_GetPlat(st);
  if (p_Var1 != (_D3_OBJECT *)0x0) {
    if ((p_Var1->collision_mode & 0x800U) != 0) {
      Boxes_Object = p_Var1;
      return 0x7fff;
    }
    if ((p_Var1->collision_mode & 1U) != 0) {
      maxz = (int)*(short *)&p_Var1[1].prec + (int)(p_Var1->pos).vz;
    }
    Boxes_Object = p_Var1;
    maxz = Boxes_IsPosInList(ot,st,maxz,p_Var1->child,0);
    if (maxz == 0x7fff) {
      return 0x7fff;
    }
  }
  maxz = Boxes_IsPosInList(ot,st,maxz,Pvl_GlobalObjects,0);
  if (maxz < 0x7fff) {
    maxz = Boxes_IsPosInList(ot,st,maxz,Pvl_HoleObjects,0);
  }
  return maxz;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Boxes_GetHeightUnder(struct _D3_OBJECT *ot /*$s2*/, struct BOXES_7fake *st /*$s1*/)
 // line 1376, offset 0x80021408
	/* begin block 1 */
		// Start line: 1377
		// Start offset: 0x80021408
		// Variables:
	// 		struct _PLATFORM *p; // $a2
	// 		long maxz; // $s0
	/* end block 1 */
	// End offset: 0x800214F0
	// End Line: 1411

	/* begin block 2 */
		// Start line: 3408
	/* end block 2 */
	// End Line: 3409

long Boxes_GetHeightUnder(_D3_OBJECT *ot,undefined st)

{
  _D3_OBJECT *p_Var1;
  undefined3 in_register_00000015;
  long maxz;
  
  maxz = -0x7fff;
  Boxes_Object = (_D3_OBJECT *)0x0;
  gRange = 400;
  p_Var1 = (_D3_OBJECT *)Plat_GetPlat(st);
  if (p_Var1 != (_D3_OBJECT *)0x0) {
    if ((p_Var1->collision_mode & 0x800U) != 0) {
      Boxes_Object = p_Var1;
      return 0x7fff;
    }
    if ((p_Var1->collision_mode & 1U) != 0) {
      maxz = (int)*(short *)&p_Var1[1].prec + (int)(p_Var1->pos).vz;
    }
    Boxes_Object = p_Var1;
    maxz = Boxes_IsPosInList(ot,st,maxz,p_Var1->child,
                             (int)*(short *)(CONCAT31(in_register_00000015,st) + 4));
    if (maxz == 0x7fff) {
      return 0x7fff;
    }
  }
  maxz = Boxes_IsPosInList(ot,st,maxz,Pvl_GlobalObjects,
                           (int)*(short *)(CONCAT31(in_register_00000015,st) + 4));
  if (maxz < 0x7fff) {
    maxz = Boxes_IsPosInList(ot,st,maxz,Pvl_HoleObjects,0);
  }
  return maxz;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Boxes_IsPosInList(struct _D3_OBJECT *ot /*$s2*/, struct BOXES_7fake *st /*$s3*/, long maxz /*$s1*/, struct _D3_OBJECT *list /*$s0*/, long hmax /*stack 16*/)
 // line 1414, offset 0x80021508
	/* begin block 1 */
		// Start line: 1415
		// Start offset: 0x80021508
		// Variables:
	// 		struct BOXES_7fake pt; // stack offset -32
	// 		long z; // $v1
	/* end block 1 */
	// End offset: 0x80021600
	// End Line: 1443

	/* begin block 2 */
		// Start line: 3491
	/* end block 2 */
	// End Line: 3492

long Boxes_IsPosInList(_D3_OBJECT *ot,undefined1 st,long maxz,_D3_OBJECT *list,long hmax)

{
  long lVar1;
  int iVar2;
  short local_20;
  short local_1e;
  
  if (list != (_D3_OBJECT *)0x0) {
    do {
      if ((list != ot) && ((list->collision_mode & 0x1000U) == 0)) {
        if (list->child != (_D3_OBJECT *)0x0) {
          maxz = Boxes_IsPosInList(ot,st,maxz,list->child,hmax);
        }
        lVar1 = Boxes_IsPosInObject(st,0xe0,list,hmax);
        if (lVar1 != 0) {
          if ((list->collision_mode & 0x800U) != 0) {
            Boxes_Object = list;
            return 0x7fff;
          }
          lVar1 = Boxes_GetRealZ(list,(int)local_20,(int)local_1e);
          iVar2 = lVar1 + (int)(list->pos).vz;
          if (maxz < iVar2) {
            maxz = iVar2;
            Boxes_Object = list;
          }
        }
      }
      list = list->next;
    } while (list != (_D3_OBJECT *)0x0);
  }
  return maxz;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Boxes_IsPosInObject(struct BOXES_7fake *in /*$t0*/, struct BOXES_7fake *out /*$s3*/, struct _D3_OBJECT *ot /*$s0*/, long hmax /*$a3*/)
 // line 1446, offset 0x80021620
	/* begin block 1 */
		// Start line: 1447
		// Start offset: 0x80021620
		// Variables:
	// 		long tx; // $s1
	// 		long ty; // $s2
	/* end block 1 */
	// End offset: 0x8002171C
	// End Line: 1474

	/* begin block 2 */
		// Start line: 3574
	/* end block 2 */
	// End Line: 3575

long Boxes_IsPosInObject(undefined in,undefined out,_D3_OBJECT *ot,long hmax)

{
  int iVar1;
  undefined3 in_register_00000011;
  undefined3 in_register_00000015;
  int iVar2;
  int iVar3;
  
  if ((*(uint *)&ot->collision_mode & 0x2201) == 1) {
    if ((hmax != 0) && (hmax < (int)*(short *)&ot[1].prec + (int)(ot->last_pos).vz)) {
      return 0;
    }
    if ((int)*(short *)(CONCAT31(in_register_00000011,in) + 4) + (int)gRange <
        (int)(ot->b_box).vz + (int)(ot->last_pos).vz) {
      return 0;
    }
    iVar2 = (int)(ot->last_pos).vx;
    iVar3 = (int)(ot->last_pos).vy;
    Boxes_RotPos(ot,(char)ot + '4',in,out);
    iVar1 = (int)*(short *)CONCAT31(in_register_00000015,out);
    if (iVar1 < (int)(ot->b_box).vx + iVar2) {
      return 0;
    }
    if ((int)*(short *)&ot->b_step + iVar2 < iVar1) {
      return 0;
    }
    iVar1 = (int)((short *)CONCAT31(in_register_00000015,out))[1];
    if (iVar1 < (int)*(short *)((int)&ot->b_sunk + 2) + iVar3) {
      return 0;
    }
    if (iVar1 <= (int)(ot->b_box).vy + iVar3) {
      return 1;
    }
  }
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Boxes_RotPos(struct _D3_OBJECT *obj /*$s0*/, struct BOXES_7fake *po /*$s2*/, struct BOXES_7fake *in /*$s3*/, struct BOXES_7fake *out /*$s1*/)
 // line 1477, offset 0x80021738
	/* begin block 1 */
		// Start line: 1478
		// Start offset: 0x80021738
		// Variables:
	// 		struct BOXES_7fake d; // stack offset -32
	// 		long rc; // $s0
	// 		long rs; // $v0
	/* end block 1 */
	// End offset: 0x80021878
	// End Line: 1498

	/* begin block 2 */
		// Start line: 3637
	/* end block 2 */
	// End Line: 3638

void Boxes_RotPos(_D3_OBJECT *obj,undefined po,undefined in,undefined out)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  undefined3 in_register_00000015;
  short *psVar6;
  undefined3 in_register_00000019;
  undefined4 *puVar7;
  undefined3 in_register_0000001d;
  undefined4 *puVar8;
  undefined4 uVar9;
  
  puVar8 = (undefined4 *)CONCAT31(in_register_0000001d,out);
  puVar7 = (undefined4 *)CONCAT31(in_register_00000019,in);
  psVar6 = (short *)CONCAT31(in_register_00000015,po);
  if (((obj->collision_mode & 4U) == 0) || ((obj->rot).vz == 0)) {
    uVar9 = puVar7[1];
    *puVar8 = *puVar7;
    puVar8[1] = uVar9;
  }
  else {
    sVar1 = *(short *)puVar7;
    sVar2 = *psVar6;
    sVar3 = *(short *)((int)puVar7 + 2) - psVar6[1];
    iVar4 = rcos(-(int)(obj->rot).vz);
    iVar5 = rsin(-(int)(obj->rot).vz);
    *(short *)puVar8 =
         (short)((iVar4 * (int)(short)(sVar1 - sVar2) - iVar5 * (int)sVar3) + 0x800 >> 0xc);
    *(short *)((int)puVar8 + 2) =
         (short)(iVar5 * (int)(short)(sVar1 - sVar2) + iVar4 * (int)sVar3 + 0x800 >> 0xc);
    *(short *)puVar8 = *(short *)puVar8 + *psVar6;
    *(short *)((int)puVar8 + 2) = *(short *)((int)puVar8 + 2) + psVar6[1];
    *(short *)(puVar8 + 1) = *(short *)(puVar7 + 1);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Boxes_InvRotPos(struct _D3_OBJECT *obj /*$s0*/, struct BOXES_7fake *po /*$s2*/, struct BOXES_7fake *in /*$s3*/, struct BOXES_7fake *out /*$s1*/)
 // line 1501, offset 0x80021894
	/* begin block 1 */
		// Start line: 1502
		// Start offset: 0x80021894
		// Variables:
	// 		struct BOXES_7fake temp; // stack offset -32
	// 		long rc; // $s0
	// 		long rs; // $v0
	/* end block 1 */
	// End offset: 0x800219D0
	// End Line: 1522

	/* begin block 2 */
		// Start line: 3686
	/* end block 2 */
	// End Line: 3687

void Boxes_InvRotPos(_D3_OBJECT *obj,undefined po,undefined in,undefined out)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  undefined3 in_register_00000015;
  short *psVar6;
  undefined3 in_register_00000019;
  undefined4 *puVar7;
  undefined3 in_register_0000001d;
  undefined4 *puVar8;
  undefined4 uVar9;
  
  puVar8 = (undefined4 *)CONCAT31(in_register_0000001d,out);
  puVar7 = (undefined4 *)CONCAT31(in_register_00000019,in);
  psVar6 = (short *)CONCAT31(in_register_00000015,po);
  if (((obj->collision_mode & 4U) == 0) || ((obj->rot).vz == 0)) {
    uVar9 = puVar7[1];
    *puVar8 = *puVar7;
    puVar8[1] = uVar9;
  }
  else {
    sVar1 = *(short *)puVar7;
    sVar2 = *psVar6;
    sVar3 = *(short *)((int)puVar7 + 2) - psVar6[1];
    iVar4 = rcos((int)(obj->rot).vz);
    iVar5 = rsin((int)(obj->rot).vz);
    *(short *)puVar8 =
         (short)((iVar4 * (int)(short)(sVar1 - sVar2) - iVar5 * (int)sVar3) + 0x800 >> 0xc);
    *(short *)((int)puVar8 + 2) =
         (short)(iVar5 * (int)(short)(sVar1 - sVar2) + iVar4 * (int)sVar3 + 0x800 >> 0xc);
    *(short *)puVar8 = *(short *)puVar8 + *psVar6;
    *(short *)((int)puVar8 + 2) = *(short *)((int)puVar8 + 2) + psVar6[1];
    *(short *)(puVar8 + 1) = *(short *)(puVar7 + 1);
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Boxes_GetRealZ(struct _D3_OBJECT *o /*$v1*/, long x /*$a1*/, long y /*$a2*/)
 // line 1525, offset 0x800219ec
	/* begin block 1 */
		// Start line: 1526
		// Start offset: 0x800219EC
		// Variables:
	// 		long dxy; // $v1
	// 		long f; // $v1
	// 		long dz; // $a1
	// 		long z; // $v0
	/* end block 1 */
	// End offset: 0x80021B1C
	// End Line: 1555

	/* begin block 2 */
		// Start line: 3734
	/* end block 2 */
	// End Line: 3735

long Boxes_GetRealZ(_D3_OBJECT *o,long x,long y)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = (int)*(short *)&o[1].prec;
  if (iVar3 != (int)*(short *)&o[1].father) {
    iVar2 = (int)*(short *)&o[1].child - (int)*(short *)&o[1].next;
    iVar1 = (x - ((int)(o->last_pos).vx + (int)*(short *)&o[1].next)) * 0x10000;
    iVar4 = iVar1 / iVar2;
    if (iVar2 == 0) {
      trap(0x1c00);
    }
    if ((iVar2 == -1) && (iVar1 == -0x80000000)) {
      trap(0x1800);
    }
    iVar1 = (int)*(short *)&o[1].father - iVar3;
    if (iVar4 < 0) {
      iVar4 = 0;
    }
    iVar2 = iVar1 * 0x10000;
    if (iVar4 < 0x10001) {
      iVar2 = iVar4 * iVar1;
    }
    return iVar3 + (iVar2 >> 0x10);
  }
  iVar1 = (int)o[1].collision_mode;
  if (iVar3 != iVar1) {
    iVar4 = (int)*(short *)((int)&o[1].next + 2) - (int)o[1].display_mode;
    iVar2 = (y - ((int)(o->last_pos).vy + (int)o[1].display_mode)) * 0x10000;
    iVar5 = iVar2 / iVar4;
    if (iVar4 == 0) {
      trap(0x1c00);
    }
    if ((iVar4 == -1) && (iVar2 == -0x80000000)) {
      trap(0x1800);
    }
    if (iVar5 < 0) {
      iVar5 = 0;
    }
    iVar2 = (iVar3 - iVar1) * 0x10000;
    if (iVar5 < 0x10001) {
      iVar2 = iVar5 * (iVar3 - iVar1);
    }
    return iVar1 + (iVar2 >> 0x10);
  }
  return iVar3;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Boxes_GetExtendedMaxZ(struct _D3_OBJECT *ot /*$a0*/)
 // line 1558, offset 0x80021b24
	/* begin block 1 */
		// Start line: 3803
	/* end block 1 */
	// End Line: 3804

long Boxes_GetExtendedMaxZ(_D3_OBJECT *ot)

{
  long lVar1;
  
  lVar1 = 0;
  if ((*(short *)&ot[1].prec != *(short *)&ot[1].father) ||
     (*(short *)&ot[1].prec != ot[1].collision_mode)) {
    lVar1 = 1;
  }
  return lVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Boxes_GetExtendedDxDy(struct _D3_OBJECT *ot /*$s0*/, long *dx /*$s3*/, long *dy /*$s2*/)
 // line 1564, offset 0x80021b54
	/* begin block 1 */
		// Start line: 1565
		// Start offset: 0x80021B54
		// Variables:
	// 		long dx1; // $s1
	// 		long rc; // $s0
	// 		long rs; // $v0
	/* end block 1 */
	// End offset: 0x80021C4C
	// End Line: 1600

	/* begin block 2 */
		// Start line: 3814
	/* end block 2 */
	// End Line: 3815

void Boxes_GetExtendedDxDy(_D3_OBJECT *ot,long *dx,long *dy)

{
  short sVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  *dy = 0;
  *dx = 0;
  sVar1 = *(short *)&ot[1].prec;
  iVar5 = 0;
  if (sVar1 == *(short *)&ot[1].father) {
    if (sVar1 != ot[1].collision_mode) {
      lVar2 = 0x21;
      if (ot[1].collision_mode <= sVar1) {
        lVar2 = -0x21;
      }
      *dy = lVar2;
    }
  }
  else {
    iVar5 = 0x21;
    if (sVar1 < *(short *)&ot[1].father) {
      iVar5 = -0x21;
    }
  }
  if ((ot->collision_mode & 4U) == 0) {
    *dx = iVar5;
  }
  else {
    iVar3 = rcos((int)(ot->rot).vz);
    iVar4 = rsin((int)(ot->rot).vz);
    *dx = iVar3 * iVar5 - iVar4 * *dy >> 0xc;
    *dy = iVar4 * iVar5 + iVar3 * *dy >> 0xc;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Boxes_TestFloatingGround(struct _D3_OBJECT *ot /*$a0*/)
 // line 1603, offset 0x80021c68
	/* begin block 1 */
		// Start line: 1604
		// Start offset: 0x80021C68
		// Variables:
	// 		struct _D3_OBJECT *oc; // $a1
	/* end block 1 */
	// End offset: 0x80021C94
	// End Line: 1611

	/* begin block 2 */
		// Start line: 3893
	/* end block 2 */
	// End Line: 3894

void Boxes_TestFloatingGround(_D3_OBJECT *ot)

{
  if (((*(_D3_OBJECT **)&ot[1].hit_points)->collision_mode & 0x400U) != 0) {
    CB_Float(ot,*(_D3_OBJECT **)&ot[1].hit_points);
  }
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ Boxes_GetBit(struct _D3_OBJECT *ot /*$a0*/, struct _D3_OBJECT *obj /*$s0*/)
 // line 1614, offset 0x80021ca4
	/* begin block 1 */
		// Start line: 1615
		// Start offset: 0x80021CA4
		// Variables:
	// 		struct BOXES_7fake t; // stack offset -32
	// 		long d; // $v1
	// 		long d1; // $s4
	// 		long d2; // $s3
	// 		long d3; // $s1
	// 		long d4; // $s0
	// 		long cx; // $s2
	// 		long cy; // $s1
	/* end block 1 */
	// End offset: 0x80021E28
	// End Line: 1652

	/* begin block 2 */
		// Start line: 3915
	/* end block 2 */
	// End Line: 3916

short Boxes_GetBit(_D3_OBJECT *ot,_D3_OBJECT *obj)

{
  short sVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  int iVar8;
  int iVar9;
  short local_20;
  short local_1e;
  
  Boxes_RotPos(obj,(char)obj + ',',(char)ot + ',',0xe0);
  uVar2 = (int)(obj->b_box).vx + (int)*(short *)&obj->b_step;
  iVar9 = (int)(obj->pos).vx + ((int)(uVar2 + (uVar2 >> 0x1f)) >> 1);
  uVar2 = (int)(obj->b_box).vy + (int)*(short *)((int)&obj->b_sunk + 2);
  iVar8 = (int)(obj->pos).vy + ((int)(uVar2 + (uVar2 >> 0x1f)) >> 1);
  lVar3 = Direction(((int)(obj->pos).vx + (int)*(short *)&obj->b_step) - iVar9,
                    ((int)(obj->pos).vy + (int)*(short *)((int)&obj->b_step + 2)) - iVar8);
  lVar4 = Direction(((int)(obj->pos).vx + (int)(obj->b_box).vx) - iVar9,
                    ((int)(obj->pos).vy + (int)(obj->b_box).vy) - iVar8);
  lVar5 = Direction(((int)(obj->pos).vx + (int)obj->comp_opt2) - iVar9,
                    ((int)(obj->pos).vy + (int)obj->comp_opt3) - iVar8);
  lVar6 = Direction(((int)(obj->pos).vx + (int)*(short *)&obj->b_sunk) - iVar9,
                    ((int)(obj->pos).vy + (int)*(short *)((int)&obj->b_sunk + 2)) - iVar8);
  if (lVar6 == 0) {
    lVar6 = 0x1000;
  }
  lVar7 = Direction((int)(short)(local_20 - (short)iVar9),(int)(short)(local_1e - (short)iVar8));
  if ((lVar3 < lVar7) && (lVar7 < lVar6)) {
    if (lVar4 < lVar7) {
      sVar1 = 0x400;
      if (lVar5 < lVar7) {
        sVar1 = 0x1000;
      }
    }
    else {
      sVar1 = 0x2000;
    }
  }
  else {
    sVar1 = 0x800;
  }
  return sVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Boxes_GetMinMax(struct _D3_OBJECT *ot /*$s1*/, short bit /*$a1*/, struct BOXES_7fake *min /*$s3*/, struct BOXES_7fake *max /*$s2*/)
 // line 1655, offset 0x80021e48
	/* begin block 1 */
		// Start line: 1656
		// Start offset: 0x80021E48
		// Variables:
	// 		struct BOXES_7fake mn; // stack offset -40
	// 		struct BOXES_7fake mx; // stack offset -32
	// 		long rz; // $s0
	// 		long cs; // $s0
	// 		long sn; // $v0
	/* end block 1 */
	// End offset: 0x8002210C
	// End Line: 1690

	/* begin block 2 */
		// Start line: 4022
	/* end block 2 */
	// End Line: 4023

/* WARNING: Could not reconcile some variable overlaps */

void Boxes_GetMinMax(_D3_OBJECT *ot,short bit,undefined min,undefined max)

{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined3 in_register_00000019;
  short *psVar4;
  undefined3 in_register_0000001d;
  short *psVar5;
  uint uVar6;
  undefined4 local_28;
  short local_24;
  undefined4 local_20;
  short local_1c;
  
  psVar5 = (short *)CONCAT31(in_register_0000001d,max);
  psVar4 = (short *)CONCAT31(in_register_00000019,min);
  if (bit == 0x800) {
    local_28 = ot->b_sunk;
    local_24 = (short)*(undefined4 *)&ot->difficulty;
  }
  else {
    if (bit < 0x801) {
      if (bit == 0x400) {
        local_28 = *(_D3_OBJECT **)&ot->comp_opt2;
        local_24 = (short)ot->comp_opt4;
        local_20 = ot[1].next;
        local_1c = (short)ot[1].prec;
      }
      goto LAB_80021fac;
    }
    if (bit == 0x1000) {
      local_28 = *(_D3_OBJECT **)&ot->comp_opt2;
      local_24 = (short)ot->comp_opt4;
      local_20 = (_D3_OBJECT *)ot[1].list;
      local_1c = (short)ot[1].handle;
      goto LAB_80021fac;
    }
    if (bit != 0x2000) goto LAB_80021fac;
    local_28 = *(_D3_OBJECT **)&ot->b_box;
    local_24 = (short)*(undefined4 *)&(ot->b_box).vz;
  }
  local_20 = ot[1].child;
  local_1c = (short)ot[1].father;
LAB_80021fac:
  uVar6 = 0;
  if ((ot->collision_mode & 4U) != 0) {
    uVar6 = SEXT24((ot->rot).vz);
  }
  iVar2 = rcos(uVar6);
  iVar3 = rsin(uVar6);
  *psVar4 = (ot->pos).vx +
            (short)((int)(short)local_28 * iVar2 - (int)local_28._2_2_ * iVar3 >> 0xc);
  psVar4[1] = (ot->pos).vy +
              (short)((int)(short)local_28 * iVar3 + (int)local_28._2_2_ * iVar2 >> 0xc);
  psVar4[2] = (ot->pos).vz + local_24;
  *psVar5 = (ot->pos).vx +
            (short)((int)(short)local_20 * iVar2 - (int)local_20._2_2_ * iVar3 >> 0xc);
  psVar5[1] = (ot->pos).vy +
              (short)((int)(short)local_20 * iVar3 + (int)local_20._2_2_ * iVar2 >> 0xc);
  sVar1 = *psVar5;
  psVar5[2] = (ot->pos).vz + local_1c;
  if (sVar1 < *psVar4) {
    *psVar5 = *psVar4;
    *psVar4 = sVar1;
  }
  sVar1 = psVar5[1];
  if (sVar1 < psVar4[1]) {
    psVar5[1] = psVar4[1];
    psVar4[1] = sVar1;
  }
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ Boxes_GetDepth(struct _D3_OBJECT *ot /*$a0*/, short bit /*$a1*/)
 // line 1693, offset 0x80022128
	/* begin block 1 */
		// Start line: 1695
		// Start offset: 0x80022128
		// Variables:
	// 		struct BOXES_7fake *b_box; // $v1
	// 		long min; // $a3
	// 		long max; // $a2
	/* end block 1 */
	// End offset: 0x800221C8
	// End Line: 1710

	/* begin block 2 */
		// Start line: 4111
	/* end block 2 */
	// End Line: 4112

short Boxes_GetDepth(_D3_OBJECT *ot,short bit)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  int in_a2;
  int in_a3;
  
  uVar3 = SEXT24(bit);
  if (uVar3 == 0x1000) {
LAB_800221b0:
    iVar2 = (int)*(short *)((int)&ot->b_sunk + 2) - (int)(ot->b_box).vy;
  }
  else {
    if (uVar3 < 0x1001) {
      if ((uVar3 == 0x400) || (uVar3 == 0x800)) {
        iVar2 = (int)*(short *)&ot->b_step - (int)(ot->b_box).vx;
      }
      else {
        iVar2 = in_a2 - in_a3;
      }
      goto LAB_800221d0;
    }
    if (uVar3 != 0x4000) {
      if (uVar3 < 0x4001) {
        if (uVar3 != 0x2000) {
          iVar2 = in_a2 - in_a3;
          goto LAB_800221d0;
        }
        goto LAB_800221b0;
      }
      if (uVar3 != 0x8000) {
        iVar2 = in_a2 - in_a3;
        goto LAB_800221d0;
      }
    }
    iVar2 = (int)*(short *)&ot[1].prec - (int)(ot->b_box).vz;
  }
LAB_800221d0:
  sVar1 = (short)iVar2;
  if (iVar2 < 0) {
    sVar1 = -sVar1;
  }
  return sVar1;
}



// decompiled code
// original method signature: 
// short /*$ra*/ Boxes_GetLength(struct _D3_OBJECT *ot /*$a0*/, short bit /*$a1*/)
 // line 1714, offset 0x800221e8
	/* begin block 1 */
		// Start line: 1716
		// Start offset: 0x800221E8
		// Variables:
	// 		struct BOXES_7fake *b_box; // $a0
	// 		long min; // $a2
	// 		long max; // $v1
	/* end block 1 */
	// End offset: 0x80022250
	// End Line: 1729

	/* begin block 2 */
		// Start line: 4153
	/* end block 2 */
	// End Line: 4154

short Boxes_GetLength(_D3_OBJECT *ot,short bit)

{
  short sVar1;
  int iVar2;
  int in_v1;
  int in_a2;
  
  if (bit != 0x800) {
    if (0x800 < bit) {
      if ((bit == 0x1000) || (bit == 0x2000)) {
        iVar2 = (int)*(short *)&ot->b_step - (int)(ot->b_box).vx;
      }
      else {
        iVar2 = in_v1 - in_a2;
      }
      goto LAB_80022258;
    }
    if (bit != 0x400) {
      iVar2 = in_v1 - in_a2;
      goto LAB_80022258;
    }
  }
  iVar2 = (int)*(short *)((int)&ot->b_sunk + 2) - (int)(ot->b_box).vx;
LAB_80022258:
  sVar1 = (short)iVar2;
  if (iVar2 < 0) {
    sVar1 = -sVar1;
  }
  return sVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Boxes_GetCenter(struct _D3_OBJECT *ot /*$s1*/, struct BOXES_7fake *c /*$s5*/)
 // line 1733, offset 0x80022270
	/* begin block 1 */
		// Start line: 1734
		// Start offset: 0x80022270
		// Variables:
	// 		long x1; // $s3
	// 		long y; // $s2
	/* end block 1 */
	// End offset: 0x8002236C
	// End Line: 1747

	/* begin block 2 */
		// Start line: 4185
	/* end block 2 */
	// End Line: 4186

void Boxes_GetCenter(_D3_OBJECT *ot,undefined c)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined3 in_register_00000015;
  short *psVar4;
  short sVar5;
  short sVar6;
  
  psVar4 = (short *)CONCAT31(in_register_00000015,c);
  uVar1 = (int)(ot->b_box).vx + (int)*(short *)&ot->b_step;
  _sVar6 = (int)(uVar1 + (uVar1 >> 0x1f)) >> 1;
  sVar6 = (short)_sVar6;
  uVar1 = (int)(ot->b_box).vy + (int)*(short *)((int)&ot->b_sunk + 2);
  _sVar5 = (int)(uVar1 + (uVar1 >> 0x1f)) >> 1;
  sVar5 = (short)_sVar5;
  uVar1 = (int)(ot->b_box).vz + (int)*(short *)&ot[1].prec;
  psVar4[2] = (ot->pos).vz + (short)((int)(uVar1 + (uVar1 >> 0x1f)) >> 1);
  if ((ot->collision_mode & 4U) != 0) {
    iVar2 = rcos((int)(ot->rot).vz);
    iVar3 = rsin((int)(ot->rot).vz);
    sVar6 = (short)(iVar2 * _sVar6 - iVar3 * _sVar5 >> 0xc);
    iVar2 = rsin((int)(ot->rot).vz);
    iVar3 = rcos((int)(ot->rot).vz);
    sVar5 = (short)(iVar2 * _sVar6 + iVar3 * _sVar5 >> 0xc);
  }
  *psVar4 = (ot->pos).vx + sVar6;
  psVar4[1] = (ot->pos).vy + sVar5;
  return;
}





