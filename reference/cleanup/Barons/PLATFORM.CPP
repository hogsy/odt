#include "THISDUST.H"
#include "PLATFORM.H"


// decompiled code
// original method signature: 
// void /*$ra*/ Plat_Init()
 // line 50, offset 0x8002d3ec
	/* begin block 1 */
		// Start line: 101
	/* end block 1 */
	// End Line: 102

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Plat_Init(void)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Plat_InitFile()
 // line 61, offset 0x8002d3f4
	/* begin block 1 */
		// Start line: 62
		// Start offset: 0x8002D3F4
		// Variables:
	// 		long i; // $s0
	// 		struct _PLATFORM *p; // $s1
	/* end block 1 */
	// End offset: 0x8002D498
	// End Line: 77

	/* begin block 2 */
		// Start line: 127
	/* end block 2 */
	// End Line: 128

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Plat_InitFile(void)

{
  TMD_72fake *Tmd;
  void *T;
  int iVar1;
  _PLATFORM *p;
  
  p = Pvl_Platforms;
  Tmd = (TMD_72fake *)FileGroup_GetAddr(Pvl_Lnk,1);
  Tmd_InitFile(Tmd);
  T = FileGroup_GetAddr(Pvl_Lnk,1);
  Shp_TmdToVram(Pvl_Pcl,T,0,1);
  iVar1 = 0;
  if (0 < Pvl_File->n_platforms) {
    do {
      (p->obj).index = ~(ushort)iVar1;
      Plat_Constructor(p);
      iVar1 = iVar1 + 1;
      p = (_PLATFORM *)&p[1].obj.last_pos.vz;
    } while (iVar1 < (int)Pvl_File->n_platforms);
  }
  Plat_LastZone = (_VISIBILITY *)0x0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Plat_Constructor(struct _PLATFORM *p /*$s0*/)
 // line 81, offset 0x8002d4b0
	/* begin block 1 */
		// Start line: 82
		// Start offset: 0x8002D4B0
	/* end block 1 */
	// End offset: 0x8002D61C
	// End Line: 122

	/* begin block 2 */
		// Start line: 177
	/* end block 2 */
	// End Line: 178

void Plat_Constructor(_PLATFORM *p)

{
  void *pvVar1;
  int iVar2;
  TASK *pTVar3;
  _D3_OBJECT *p_Var4;
  undefined4 uVar5;
  
  pvVar1 = FileGroup_GetAddr(Pvl_Lnk,1);
  (p->obj).description = (void *)((int)pvVar1 + (int)(p->obj).description * 0x1c + 0xc);
  uVar5 = *(undefined4 *)&(p->obj).pos.vz;
  *(undefined4 *)&(p->obj).last_pos = *(undefined4 *)&(p->obj).pos;
  *(undefined4 *)&(p->obj).last_pos.vz = uVar5;
  p_Var4 = (p->obj).child;
  (p->obj).rot.pad = (p->obj).rot.vz;
  if ((int)p_Var4 < 0) {
    (p->obj).child = (_D3_OBJECT *)0x0;
  }
  else {
    (p->obj).child = (_D3_OBJECT *)((int)Pvl_Objects + (int)p_Var4 * 0xa4);
  }
  p_Var4 = (p->obj).prec;
  if ((int)p_Var4 < 0) {
    (p->obj).prec = (_D3_OBJECT *)0x0;
  }
  else {
    (p->obj).prec = (_D3_OBJECT *)((int)Pvl_Platforms + (int)p_Var4 * 0xa4);
  }
  p_Var4 = (p->obj).next;
  if ((int)p_Var4 < 0) {
    (p->obj).next = (_D3_OBJECT *)0x0;
  }
  else {
    (p->obj).next = (_D3_OBJECT *)((int)Pvl_Platforms + (int)p_Var4 * 0xa4);
  }
  iVar2 = (int)*(char *)((int)&p[1].obj.pos.vx + 1);
  (p->obj).father = (_D3_OBJECT *)0x0;
  (p->obj).list = (_D3_OBJECT **)0x0;
  if (iVar2 == 0) {
    (p->obj).handle = (TASK *)0x0;
  }
  else {
    pTVar3 = Task_Link((TDRFuncPtr_Task_Link0f)Platform_Comps[iVar2 + -1],0);
    (p->obj).handle = pTVar3;
    *(_PLATFORM **)&pTVar3->local = p;
    if (*(char *)((int)&p[1].obj.pos.vx + 1) == '\x05') {
      Plat_SetRoll(p);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Plat_SetRoll(struct _PLATFORM *p /*$a0*/)
 // line 127, offset 0x8002d62c
	/* begin block 1 */
		// Start line: 129
		// Start offset: 0x8002D62C
		// Variables:
	// 		struct PLATFORM_92fake *prs; // $a1
	// 		short i; // $a3
	// 		short u; // $v1
	// 		short v; // $a2
	/* end block 1 */
	// End offset: 0x8002D6F4
	// End Line: 162

	/* begin block 2 */
		// Start line: 284
	/* end block 2 */
	// End Line: 285

void Plat_SetRoll(_PLATFORM *p)

{
  short sVar1;
  ushort uVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  pvVar3 = (p->obj).description;
  *(undefined *)((int)&p[1].obj.pos.vx + 1) = 0;
  iVar4 = (int)*(short *)((int)pvVar3 + 0x14);
  iVar5 = *(int *)((int)pvVar3 + 0x10);
  iVar7 = 0;
  if (0 < iVar4) {
    do {
      sVar1 = *(short *)(iVar5 + 0xe);
      if (sVar1 == 0) goto LAB_8002d6cc;
      uVar6 = (uint)(*(ushort *)(iVar5 + 4) >> 8);
      if (sVar1 == 0x2000) {
LAB_8002d6b0:
        uVar2 = *(ushort *)(iVar5 + 0x12);
        uVar6 = (uint)*(ushort *)(iVar5 + 4) & 0xff;
LAB_8002d6c4:
        *(ushort *)(iVar5 + 0x12) = uVar2 | (ushort)(uVar6 << 8);
      }
      else {
        if (sVar1 < 0x2001) {
          if (sVar1 == 0x1000) goto LAB_8002d6b0;
        }
        else {
          if ((sVar1 == 0x3000) || (sVar1 == 0x4000)) {
            uVar2 = *(ushort *)(iVar5 + 0x12);
            goto LAB_8002d6c4;
          }
        }
      }
LAB_8002d6cc:
      iVar7 = iVar7 + 1;
      iVar5 = iVar5 + (uint)*(byte *)(iVar5 + 1) * 4 + 4;
    } while (iVar7 * 0x10000 >> 0x10 < iVar4);
  }
  return;
}



// decompiled code
// original method signature: 
// struct _PLATFORM * /*$ra*/ Plat_GetPlat(struct PLATFORM_7fake *pos /*$t0*/)
 // line 206, offset 0x8002d6fc
	/* begin block 1 */
		// Start line: 207
		// Start offset: 0x8002D6FC
		// Variables:
	// 		short x; // $a1
	// 		short y; // $a0
	// 		short w; // $a2
	// 		short h; // $a3
	/* end block 1 */
	// End offset: 0x8002D850
	// End Line: 232

	/* begin block 2 */
		// Start line: 483
	/* end block 2 */
	// End Line: 484

/* WARNING: Unknown calling convention yet parameter storage is locked */

_PLATFORM * Plat_GetPlat(undefined pos)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  undefined3 in_register_00000011;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar3 = (uint)*(ushort *)CONCAT31(in_register_00000011,pos) << 0x10;
  iVar4 = iVar3 >> 0x10;
  uVar1 = Pvl_File->map_w;
  if (iVar4 < 0) {
    iVar6 = (int)((ulonglong)((longlong)(iVar4 + -99) * 0x51eb851f) >> 0x20);
    iVar3 = iVar4 + -99;
  }
  else {
    iVar6 = (int)((ulonglong)((longlong)iVar4 * 0x51eb851f) >> 0x20);
  }
  iVar4 = (uint)((ushort *)CONCAT31(in_register_00000011,pos))[1] << 0x10;
  iVar5 = iVar4 >> 0x10;
  if (iVar5 < 0) {
    iVar7 = (int)((ulonglong)((longlong)(iVar5 + -99) * 0x51eb851f) >> 0x20);
    iVar4 = iVar5 + -99;
  }
  else {
    iVar7 = (int)((ulonglong)((longlong)iVar5 * 0x51eb851f) >> 0x20);
  }
  uVar2 = (uint)(ushort)Pvl_File->map_h << 0x10;
  iVar3 = (((iVar6 >> 5) - (iVar3 >> 0x1f)) +
          ((int)(((int)((uint)uVar1 << 0x10) >> 0x10) + (((uint)uVar1 << 0x10) >> 0x1f)) >> 1)) *
          0x10000 >> 0x10;
  if (-1 < iVar3) {
    if ((((iVar3 < (int)(short)uVar1) &&
         (iVar4 = (((iVar7 >> 5) - (iVar4 >> 0x1f)) +
                  ((int)(((int)uVar2 >> 0x10) + (uVar2 >> 0x1f)) >> 1)) * 0x10000 >> 0x10,
         -1 < iVar4)) && (iVar4 < (int)Pvl_File->map_h)) &&
       (-1 < (int)Pvl_Map[iVar4 * (int)(short)uVar1 + iVar3])) {
      return (_PLATFORM *)
             ((int)Pvl_Platforms + (int)Pvl_Map[iVar4 * (int)(short)uVar1 + iVar3] * 0xa4);
    }
  }
  return (_PLATFORM *)0x0;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Plat_IsDisplayed(struct _PLATFORM *p /*$a0*/, long *visibility /*$a1*/)
 // line 235, offset 0x8002d858
	/* begin block 1 */
		// Start line: 237
		// Start offset: 0x8002D858
		// Variables:
	// 		long i; // $a0
	/* end block 1 */
	// End offset: 0x8002D8D0
	// End Line: 249

	/* begin block 2 */
		// Start line: 552
	/* end block 2 */
	// End Line: 553

long Plat_IsDisplayed(_PLATFORM *p,long *visibility)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = -(int)(p->obj).index;
  uVar2 = iVar1 - 1;
  if ((int)uVar2 < 0x20) {
    return *visibility & 1 << (uVar2 & 0x1f);
  }
  if ((int)uVar2 < 0x40) {
    uVar2 = iVar1 - 0x21;
    uVar3 = visibility[1];
  }
  else {
    if ((int)uVar2 < 0x60) {
      return visibility[2] & 1 << (iVar1 - 0x41U & 0x1f);
    }
    uVar2 = iVar1 - 0x61;
    uVar3 = visibility[3];
  }
  return uVar3 & 1 << (uVar2 & 0x1f);
}



// decompiled code
// original method signature: 
// void /*$ra*/ Plat_SetDisplayed(struct _PLATFORM *p /*$a0*/, long *visibility /*$a1*/)
 // line 252, offset 0x8002d8d8
	/* begin block 1 */
		// Start line: 254
		// Start offset: 0x8002D8D8
		// Variables:
	// 		long i; // $a0
	/* end block 1 */
	// End offset: 0x8002D964
	// End Line: 266

	/* begin block 2 */
		// Start line: 588
	/* end block 2 */
	// End Line: 589

void Plat_SetDisplayed(_PLATFORM *p,long *visibility)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = -(int)(p->obj).index;
  uVar2 = iVar1 - 1;
  if ((int)uVar2 < 0x20) {
    *visibility = *visibility | 1 << (uVar2 & 0x1f);
    return;
  }
  if ((int)uVar2 < 0x40) {
    visibility[1] = visibility[1] | 1 << (iVar1 - 0x21U & 0x1f);
    return;
  }
  if ((int)uVar2 < 0x60) {
    visibility[2] = visibility[2] | 1 << (iVar1 - 0x41U & 0x1f);
    return;
  }
  visibility[3] = visibility[3] | 1 << (iVar1 - 0x61U & 0x1f);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Plat_ClearZones()
 // line 289, offset 0x8002d96c
	/* begin block 1 */
		// Start line: 291
		// Start offset: 0x8002D96C
		// Variables:
	// 		struct _VISIBILITY *vis; // $a0
	// 		long i; // $a1
	// 		long s; // $v0
	/* end block 1 */
	// End offset: 0x8002DA54
	// End Line: 318

	/* begin block 2 */
		// Start line: 664
	/* end block 2 */
	// End Line: 665

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Plat_ClearZones(void)

{
  _PVL_HEADER *p_Var1;
  short sVar2;
  int iVar3;
  long *plVar4;
  _VISPLATRANGE *p_Var5;
  long *plVar6;
  char *pcVar7;
  int iVar8;
  
  iVar8 = 0;
  plVar6 = &Plat_Visibility;
  plVar4 = &Plat_RealVisibility;
  do {
    *plVar4 = 0;
    *plVar6 = 0;
    sVar2 = Scr_W;
    p_Var1 = Pvl_File;
    plVar6 = plVar6 + 1;
    iVar8 = iVar8 + 1;
    plVar4 = plVar4 + 1;
  } while (iVar8 < 4);
  iVar8 = 0;
  pcVar7 = Pvl_Visibility;
  if (0 < Pvl_File->n_visibilitys) {
    do {
      *(short *)(pcVar7 + 0xc) = sVar2;
      *(undefined2 *)(pcVar7 + 0xe) = 0;
      *(ushort *)(pcVar7 + 0x14) = *(ushort *)(pcVar7 + 0x14) & 0xfff1;
      iVar3 = (int)*(short *)(pcVar7 + 0x10) * 8 + (int)*(short *)(pcVar7 + 0x12) * 4 + 0x18;
      iVar8 = iVar8 + iVar3;
      pcVar7 = pcVar7 + iVar3;
    } while (iVar8 < (int)p_Var1->n_visibilitys);
  }
  sVar2 = Scr_W;
  p_Var1 = Pvl_File;
  iVar8 = 0;
  if (0 < Pvl_File->n_platforms) {
    p_Var5 = &Plat_RangeVisibility;
    do {
      p_Var5->minx = sVar2;
      p_Var5->maxx = 0;
      iVar8 = iVar8 + 1;
      p_Var5 = p_Var5 + 1;
    } while (iVar8 < (int)p_Var1->n_platforms);
  }
  return;
}



// decompiled code
// original method signature: 
// void * /*$ra*/ Plat_DisplayZones(void *prims /*$s4*/)
 // line 321, offset 0x8002da5c
	/* begin block 1 */
		// Start line: 322
		// Start offset: 0x8002DA5C
		// Variables:
	// 		struct _PLATFORM *p; // $s1
	// 		struct _VISIBILITY *vis; // $s1
	// 		long i; // $s3
	// 		long j; // $s2
	// 		long s; // $s0
	// 		long *v; // $s2

		/* begin block 1.1 */
			// Start line: 333
			// Start offset: 0x8002DAB4
			// Variables:
		// 		struct _PLATFORM **ps; // $v1
		// 		short VisMin; // $t1
		// 		short VisMax; // $t0

			/* begin block 1.1.1 */
				// Start line: 343
				// Start offset: 0x8002DADC
				// Variables:
			// 		long index; // $v0
			/* end block 1.1.1 */
			// End offset: 0x8002DB3C
			// End Line: 351
		/* end block 1.1 */
		// End offset: 0x8002DB54
		// End Line: 353

		/* begin block 1.2 */
			// Start line: 372
			// Start offset: 0x8002DC40
			// Variables:
		// 		struct _PLATFORM **ps; // $v0

			/* begin block 1.2.1 */
				// Start line: 386
				// Start offset: 0x8002DC7C
				// Variables:
			// 		long index; // $v0
			/* end block 1.2.1 */
			// End offset: 0x8002DCB0
			// End Line: 389
		/* end block 1.2 */
		// End offset: 0x8002DCC4
		// End Line: 390
	/* end block 1 */
	// End offset: 0x8002DE28
	// End Line: 433

	/* begin block 2 */
		// Start line: 754
	/* end block 2 */
	// End Line: 755

void * Plat_DisplayZones(void *prims)

{
  short sVar1;
  _PVL_HEADER *p_Var2;
  uint uVar3;
  long lVar4;
  _VISIBILITY **pp_Var5;
  short sVar6;
  _D3_OBJECT *obj;
  short sVar7;
  short sVar8;
  _VISPLATRANGE *p_Var9;
  int *piVar10;
  _PLATFORM **pp_Var11;
  char *pcVar12;
  _PLATFORM *p_Var13;
  _VISIBILITY *p_Var14;
  int iVar15;
  long *plVar16;
  int iVar17;
  
  iVar17 = 0;
  pcVar12 = Pvl_Visibility;
  if (0 < Pvl_File->n_visibilitys) {
    do {
      if ((*(ushort *)(pcVar12 + 0x14) & 4) != 0) {
        sVar6 = *(short *)(pcVar12 + 0xc);
        piVar10 = (int *)(pcVar12 + (int)*(short *)(pcVar12 + 0x10) * 8 + 0x18);
        sVar8 = *(short *)(pcVar12 + 0xe);
        iVar15 = 0;
        if (0 < *(short *)(pcVar12 + 0x12)) {
          do {
            uVar3 = ~(int)*(short *)(*piVar10 + 0x18);
            p_Var9 = &Plat_RangeVisibility + uVar3;
            sVar7 = sVar6;
            if (p_Var9->minx < sVar6) {
              sVar7 = p_Var9->minx;
            }
            sVar1 = (&Plat_RangeVisibility)[uVar3].maxx;
            p_Var9->minx = sVar7;
            sVar7 = sVar8;
            if (sVar8 < sVar1) {
              sVar7 = (&Plat_RangeVisibility)[uVar3].maxx;
            }
            (&Plat_RangeVisibility)[uVar3].maxx = sVar7;
            iVar15 = iVar15 + 1;
            piVar10 = piVar10 + 1;
          } while (iVar15 < (int)*(short *)(pcVar12 + 0x12));
        }
      }
      iVar15 = (int)*(short *)(pcVar12 + 0x10) * 8 + (int)*(short *)(pcVar12 + 0x12) * 4 + 0x18;
      iVar17 = iVar17 + iVar15;
      pcVar12 = pcVar12 + iVar15;
    } while (iVar17 < (int)Pvl_File->n_visibilitys);
  }
  p_Var2 = Pvl_File;
  iVar17 = 0;
  if (0 < Pvl_File->n_platforms) {
    p_Var9 = &Plat_RangeVisibility;
    do {
      sVar8 = Scr_W;
      sVar6 = p_Var9->minx;
      if (p_Var9->minx < 0) {
        sVar6 = 0;
      }
      p_Var9->minx = sVar6;
      if (p_Var9->maxx < sVar8) {
        sVar8 = p_Var9->maxx;
      }
      p_Var9->maxx = sVar8;
      iVar17 = iVar17 + 1;
      p_Var9 = p_Var9 + 1;
    } while (iVar17 < (int)p_Var2->n_platforms);
  }
  iVar17 = 0;
  pcVar12 = Pvl_Visibility;
  if (0 < Pvl_File->n_visibilitys) {
    do {
      if ((*(ushort *)(pcVar12 + 0x14) & 4) != 0) {
        iVar15 = 0;
        pp_Var11 = (_PLATFORM **)(pcVar12 + (int)*(short *)(pcVar12 + 0x10) * 8 + 0x18);
        if (0 < *(short *)(pcVar12 + 0x12)) {
          do {
            lVar4 = Plat_IsDisplayed(*pp_Var11,&Plat_Visibility);
            if (lVar4 == 0) {
              uVar3 = ~(int)((*pp_Var11)->obj).index;
              prims = Plat_DisplayPlatform
                                (*pp_Var11,prims,(int)(&Plat_RangeVisibility)[uVar3].minx,
                                 (int)(&Plat_RangeVisibility)[uVar3].maxx);
            }
            iVar15 = iVar15 + 1;
            pp_Var11 = pp_Var11 + 1;
          } while (iVar15 < (int)*(short *)(pcVar12 + 0x12));
        }
      }
      iVar15 = (int)*(short *)(pcVar12 + 0x10) * 8 + (int)*(short *)(pcVar12 + 0x12) * 4 + 0x18;
      iVar17 = iVar17 + iVar15;
      pcVar12 = pcVar12 + iVar15;
    } while (iVar17 < (int)Pvl_File->n_visibilitys);
  }
  plVar16 = &Plat_RealVisibility;
  uVar3 = 1;
  iVar17 = 0;
  p_Var13 = Pvl_Platforms;
  if (0 < Pvl_File->n_platforms) {
    do {
      if ((*plVar16 & uVar3) != 0) {
        obj = (p_Var13->obj).child;
        if (obj != (_D3_OBJECT *)0x0) {
          prims = D3_DisplayList(obj,prims,(int)(&Plat_RangeVisibility)[iVar17].minx,
                                 (int)(&Plat_RangeVisibility)[iVar17].maxx);
        }
      }
      uVar3 = uVar3 << 1;
      p_Var13 = (_PLATFORM *)&p_Var13[1].obj.last_pos.vz;
      if (uVar3 == 0) {
        uVar3 = 1;
        plVar16 = (long *)((uint *)plVar16 + 1);
      }
      iVar17 = iVar17 + 1;
    } while (iVar17 < (int)Pvl_File->n_platforms);
  }
  p_Var2 = Pvl_File;
  Plat_NVisibleZones = 0;
  iVar17 = 0;
  p_Var14 = (_VISIBILITY *)Pvl_Visibility;
  if (0 < Pvl_File->n_visibilitys) {
    do {
      if ((p_Var14->state & 4U) != 0) {
        pp_Var5 = &Plat_VisibleZones256 + Plat_NVisibleZones;
        Plat_NVisibleZones = Plat_NVisibleZones + 1;
        *pp_Var5 = p_Var14;
      }
      iVar17 = iVar17 + (int)p_Var14->n_zones * 8 + (int)p_Var14->n_plats * 4 + 0x18;
      p_Var14 = (_VISIBILITY *)
                (&p_Var14[1].x1 + (int)p_Var14->n_plats * 2 + (int)p_Var14->n_zones * 4);
    } while (iVar17 < (int)p_Var2->n_visibilitys);
  }
  return prims;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Plat_ScanZone(struct _VISIBILITY *cur /*$a0*/, struct _VISPORTAL *port /*$a1*/, long min_x /*stack 8*/, long max_x /*stack 12*/)
 // line 437, offset 0x8002de4c
	/* begin block 1 */
		// Start line: 438
		// Start offset: 0x8002DE4C
		// Variables:
	// 		struct _VISIBILITY *v; // $s2
	// 		struct _VISPORTAL *zs; // $s3
	// 		long i; // $s1
	/* end block 1 */
	// End offset: 0x8002DF48
	// End Line: 470

	/* begin block 2 */
		// Start line: 1160
	/* end block 2 */
	// End Line: 1161

void Plat_ScanZone(_VISIBILITY *cur,_VISPORTAL *port,long min_x,long max_x)

{
  long lVar1;
  _VISIBILITY *port_00;
  _VISIBILITY *port_01;
  int iVar2;
  _VISIBILITY *v;
  long local_res8;
  long local_resc;
  
  v = port->zone;
  local_res8 = min_x;
  local_resc = max_x;
  lVar1 = Plat_IsVisible(cur,v,port,&local_res8,&local_resc);
  if (lVar1 != 0) {
    port_01 = v + 1;
    if ((v->state & 8U) == 0) {
      iVar2 = 0;
      port_00 = port_01;
      if (0 < v->n_zones) {
        do {
          Plat_ComputePortal(v,*(_VISIBILITY **)port_00,(_VISPORTAL *)port_00);
          iVar2 = iVar2 + 1;
          port_00 = (_VISIBILITY *)&port_00->y2;
        } while (iVar2 < (int)v->n_zones);
      }
      v->state = v->state | 8;
    }
    iVar2 = 0;
    v->state = v->state | 2;
    if (0 < v->n_zones) {
      do {
        Plat_ScanZone(v,(_VISPORTAL *)port_01,local_res8,local_resc);
        iVar2 = iVar2 + 1;
        port_01 = (_VISIBILITY *)&port_01->y2;
      } while (iVar2 < (int)v->n_zones);
    }
    v->state = v->state & 0xfffd;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Plat_ZIntersect(struct PLATFORM_6fake *V1 /*$a0*/, struct PLATFORM_6fake *V2 /*$a1*/, long *min_x /*$a2*/, long *max_x /*$a3*/)
 // line 473, offset 0x8002df64
	/* begin block 1 */
		// Start line: 475
		// Start offset: 0x8002DF64
		// Variables:
	// 		long X; // $a0
	// 		long X1; // $t0
	// 		long X2; // $v1
	// 		long Z1; // $a0
	// 		long Z2; // $a1
	/* end block 1 */
	// End offset: 0x8002E0E4
	// End Line: 523

	/* begin block 2 */
		// Start line: 1265
	/* end block 2 */
	// End Line: 1266

void Plat_ZIntersect(undefined V1,undefined V2,long *min_x,long *max_x)

{
  int iVar1;
  undefined *puVar2;
  undefined3 in_register_00000011;
  int iVar3;
  undefined *puVar4;
  undefined3 in_register_00000015;
  int iVar5;
  int iVar6;
  undefined *puVar7;
  
  iVar6 = *(int *)CONCAT31(in_register_00000011,V1);
  iVar1 = *(int *)CONCAT31(in_register_00000015,V2);
  iVar3 = ((int *)CONCAT31(in_register_00000011,V1))[2];
  iVar5 = ((int *)CONCAT31(in_register_00000015,V2))[2];
  if (((iVar3 < 1) || (iVar5 < 1)) && ((-1 < iVar3 || (-1 < iVar5)))) {
    if ((iVar3 == 0) && (iVar5 == 0)) {
      puVar7 = &DAT_00002710;
      if (iVar6 < 0) {
        puVar7 = (undefined *)0xffffd8f0;
      }
      puVar2 = &DAT_00002710;
      if (iVar1 < 0) {
        puVar2 = (undefined *)0xffffd8f0;
      }
      puVar4 = puVar7;
      if ((int)(undefined *)*min_x < (int)puVar7) {
        puVar4 = (undefined *)*min_x;
      }
      *(undefined **)min_x = puVar4;
      if ((int)puVar7 < (int)(undefined *)*max_x) {
        puVar7 = (undefined *)*max_x;
      }
      *(undefined **)max_x = puVar7;
      puVar7 = puVar2;
      if ((int)(undefined *)*min_x < (int)puVar2) {
        puVar7 = (undefined *)*min_x;
      }
      *(undefined **)min_x = puVar7;
      if ((int)puVar2 < (int)(undefined *)*max_x) {
        puVar2 = (undefined *)*max_x;
      }
      *(undefined **)max_x = puVar2;
      return;
    }
    iVar1 = (iVar1 - iVar6) * -iVar3;
    iVar5 = iVar5 - iVar3;
    if (iVar5 == 0) {
      trap(0x1c00);
    }
    if ((iVar5 == -1) && (iVar1 == -0x80000000)) {
      trap(0x1800);
    }
    iVar6 = iVar6 + iVar1 / iVar5;
    if (iVar6 + 4U < 9) {
      *min_x = 0;
      *max_x = (int)Scr_W;
    }
    puVar7 = &DAT_00002710;
    if (iVar6 < 0) {
      puVar7 = (undefined *)0xffffd8f0;
    }
    puVar2 = puVar7;
    if ((int)(undefined *)*min_x < (int)puVar7) {
      puVar2 = (undefined *)*min_x;
    }
    *(undefined **)min_x = puVar2;
    if ((int)puVar7 < (int)(undefined *)*max_x) {
      puVar7 = (undefined *)*max_x;
    }
    *(undefined **)max_x = puVar7;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Plat_ZClipPortal(struct PLATFORM_7fake *Box /*$a0*/, long *min_x /*$s1*/, long *max_x /*$s2*/)
 // line 527, offset 0x8002e0ec
	/* begin block 1 */
		// Start line: 528
		// Start offset: 0x8002E0EC
		// Variables:
	// 		struct PLATFORM_6fake RotVerts[4]; // stack offset -88
	// 		long i; // $a2

		/* begin block 1.1 */
			// Start line: 548
			// Start offset: 0x8002E1A0
			// Variables:
		// 		long KiSertPas; // stack offset -24
		/* end block 1.1 */
		// End offset: 0x8002E1A0
		// End Line: 549
	/* end block 1 */
	// End offset: 0x8002E1E0
	// End Line: 554

	/* begin block 2 */
		// Start line: 1370
	/* end block 2 */
	// End Line: 1371

void Plat_ZClipPortal(undefined Box,long *min_x,long *max_x)

{
  undefined4 uVar1;
  undefined4 in_zero;
  undefined4 in_at;
  int iVar2;
  undefined4 *puVar3;
  undefined3 in_register_00000011;
  undefined4 *puVar4;
  int iVar5;
  undefined4 local_58 [16];
  undefined4 local_18;
  
  puVar4 = (undefined4 *)CONCAT31(in_register_00000011,Box);
  iVar5 = 0;
  *min_x = 10000;
  *max_x = -10000;
  do {
    if (Tmd_2DSpeed[iVar5].vz != 0) {
      iVar2 = (int)Tmd_2DSpeed[iVar5].vx;
      if (*min_x < iVar2) {
        iVar2 = *min_x;
      }
      *min_x = iVar2;
      iVar2 = (int)Tmd_2DSpeed[iVar5].vx;
      if ((int)Tmd_2DSpeed[iVar5].vx < *max_x) {
        iVar2 = *max_x;
      }
      *max_x = iVar2;
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 4);
  iVar5 = 0;
  puVar3 = local_58;
  do {
    setCopReg(2,in_zero,*puVar4);
    setCopReg(2,in_at,puVar4[1]);
    copFunction(2,0x480012);
    uVar1 = getCopReg(2,0x19);
    *puVar3 = uVar1;
    uVar1 = getCopReg(2,0x1a);
    puVar3[1] = uVar1;
    uVar1 = getCopReg(2,0x1b);
    puVar3[2] = uVar1;
    local_18 = getCopControlWord(2,0xf800);
    puVar3 = puVar3 + 4;
    iVar5 = iVar5 + 1;
    puVar4 = puVar4 + 2;
  } while (iVar5 < 4);
  Plat_ZIntersect(0xa8,0xb8,min_x,max_x);
  Plat_ZIntersect(0xb8,0xd8,min_x,max_x);
  Plat_ZIntersect(0xd8,200,min_x,max_x);
  Plat_ZIntersect(200,0xa8,min_x,max_x);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Plat_ComputePortal(struct _VISIBILITY *cur /*$t0*/, struct _VISIBILITY *v /*$a1*/, struct _VISPORTAL *port /*$s3*/)
 // line 562, offset 0x8002e254
	/* begin block 1 */
		// Start line: 563
		// Start offset: 0x8002E254
		// Variables:
	// 		struct PLATFORM_7fake box[4]; // stack offset -80
	// 		struct PLATFORM_7fake CamPos; // stack offset -48
	// 		long min_x; // stack offset -40
	// 		long max_x; // stack offset -36
	// 		long x1; // $s2
	// 		long y1; // $s1
	// 		long x2; // $s5
	// 		long y2; // $s4
	// 		long i; // $a2
	// 		long j; // $a0

		/* begin block 1.1 */
			// Start line: 678
			// Start offset: 0x8002E6EC
			// Variables:
		// 		long MiddleX; // $a0
		// 		long bInf; // $a2
		// 		long bSup; // $a1
		/* end block 1.1 */
		// End offset: 0x8002E904
		// End Line: 717
	/* end block 1 */
	// End offset: 0x8002EA18
	// End Line: 741

	/* begin block 2 */
		// Start line: 1456
	/* end block 2 */
	// End Line: 1457

/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Plat_ComputePortal(_VISIBILITY *cur,_VISIBILITY *v,_VISPORTAL *port)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  short sVar4;
  short sVar5;
  _TMD_2D *p_Var6;
  short sVar7;
  short sVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  short local_50;
  short local_4e;
  short local_4c;
  short local_48;
  short local_46;
  short local_44;
  short local_40;
  short local_3e;
  short local_3c;
  short local_38;
  short local_36;
  short local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  
  sVar4 = Scr_W;
  if ((cur == (_VISIBILITY *)0x0) || ((cur->state & 1U) != 0)) {
    v->min = 0;
    port->min = 0;
    v->max = sVar4;
    port->max = sVar4;
    v->state = v->state | 4;
    return;
  }
  if (((int)v->interruptor != 0) && (((int)v->interruptor & Scts_Interruptors) == 0))
  goto LAB_8002e68c;
  local_30 = _Cam_Pos_;
  local_2c = _DAT_800b416c;
  local_50 = v->x1;
  if (v->x1 < cur->x1) {
    local_50 = cur->x1;
  }
  iVar12 = (int)local_50;
  local_38 = v->x2;
  if (cur->x2 < v->x2) {
    local_38 = cur->x2;
  }
  iVar14 = (int)local_38;
  local_4e = v->y1;
  if (v->y1 < cur->y1) {
    local_4e = cur->y1;
  }
  iVar11 = (int)local_4e;
  local_36 = v->y2;
  if (cur->y2 < v->y2) {
    local_36 = cur->y2;
  }
  iVar13 = (int)local_36;
  if (iVar12 == iVar14) {
    uVar3 = (int)v->x1 + (int)v->x2;
    local_30._0_2_ = (short)_Cam_Pos_;
    if ((iVar12 - (int)(short)local_30 != 0) &&
       ((iVar12 - ((int)(uVar3 + (uVar3 >> 0x1f)) >> 1) & 0x80000000U) ==
        (iVar12 - (int)(short)local_30 & 0x80000000U))) goto LAB_8002e68c;
    local_3c = v->z2;
    local_38 = local_50;
  }
  else {
    if (iVar11 != iVar13) goto LAB_8002e68c;
    uVar3 = (int)v->y1 + (int)v->y2;
    local_30._2_2_ = (short)((uint)_Cam_Pos_ >> 0x10);
    if ((iVar11 - (int)local_30._2_2_ != 0) &&
       ((iVar11 - ((int)(uVar3 + (uVar3 >> 0x1f)) >> 1) & 0x80000000U) ==
        (iVar11 - (int)local_30._2_2_ & 0x80000000U))) goto LAB_8002e68c;
    local_3c = v->z2;
    local_36 = local_4e;
  }
  local_34 = v->z2;
  if (v->z2 < v->z1) {
    local_3c = 0xc80;
    local_34 = 0xc80;
  }
  local_4c = cur->z1;
  if (v->z1 < cur->z1) {
    local_4c = v->z1;
  }
  local_44 = cur->z1;
  if (v->z1 < cur->z1) {
    local_44 = v->z1;
  }
  if (cur->z2 < cur->z1) {
    local_4c = -0xc80;
    local_44 = -0xc80;
  }
  local_2c._0_2_ = (short)_DAT_800b416c;
  iVar9 = (int)(short)local_2c;
  sVar4 = (short)(iVar9 + -10);
  if ((int)local_4c < iVar9 + -10) {
    sVar4 = local_4c;
  }
  sVar7 = (short)(iVar9 + -10);
  if ((int)local_44 < iVar9 + -10) {
    sVar7 = local_44;
  }
  sVar5 = (short)(iVar9 + 10);
  if (iVar9 + 10 < (int)local_3c) {
    sVar5 = local_3c;
  }
  sVar8 = (short)(iVar9 + 10);
  if (iVar9 + 10 < (int)local_34) {
    sVar8 = local_34;
  }
  iVar9 = (uint)(Pvl_File->fog).cd * 100;
  local_4c = sVar4;
  local_48 = local_38;
  local_46 = local_36;
  local_44 = sVar7;
  local_40 = local_50;
  local_3e = local_4e;
  local_3c = sVar5;
  local_34 = sVar8;
  GtxTmd_RotTransPersN(&local_50,Tmd_2DSpeed,4);
  if ((((iVar9 <= (int)Tmd_2DSpeed->vz) && (iVar9 <= (int)Tmd_2DSpeed[1].vz)) &&
      (iVar9 <= (int)Tmd_2DSpeed[2].vz)) && (iVar9 <= (int)Tmd_2DSpeed[3].vz)) {
LAB_8002e68c:
    port->max = -0x8000;
    return;
  }
  if (Tmd_2DSpeed->vz == 0) {
    if (((Tmd_2DSpeed[1].vz == 0) && (Tmd_2DSpeed[2].vz == 0)) && (Tmd_2DSpeed[3].vz == 0))
    goto LAB_8002e68c;
    if (Tmd_2DSpeed->vz != 0) goto LAB_8002e6b0;
  }
  else {
LAB_8002e6b0:
    if (((Tmd_2DSpeed[1].vz != 0) && (Tmd_2DSpeed[2].vz != 0)) && (Tmd_2DSpeed[3].vz != 0)) {
      sVar4 = Tmd_2DSpeed[1].vx;
      if (Tmd_2DSpeed[1].vx < Tmd_2DSpeed->vx) {
        sVar4 = Tmd_2DSpeed->vx;
      }
      iVar12 = (int)Tmd_2DSpeed[2].vx;
      if ((int)Tmd_2DSpeed[2].vx < (int)sVar4) {
        iVar12 = (int)sVar4;
      }
      local_24 = (int)Tmd_2DSpeed[3].vx;
      if ((int)Tmd_2DSpeed[3].vx < iVar12) {
        local_24 = iVar12;
      }
      sVar4 = Tmd_2DSpeed[1].vx;
      if (Tmd_2DSpeed->vx < Tmd_2DSpeed[1].vx) {
        sVar4 = Tmd_2DSpeed->vx;
      }
      iVar12 = (int)Tmd_2DSpeed[2].vx;
      if ((int)sVar4 < (int)Tmd_2DSpeed[2].vx) {
        iVar12 = (int)sVar4;
      }
      local_28 = (int)Tmd_2DSpeed[3].vx;
      if (iVar12 < (int)Tmd_2DSpeed[3].vx) {
        local_28 = iVar12;
      }
      goto LAB_8002e9c0;
    }
  }
  iVar10 = 0;
  iVar9 = (int)((uint)(ushort)Scr_W << 0x10) >> 0x11;
  p_Var6 = Tmd_2DSpeed;
  do {
    if (p_Var6->vz == 0) {
      if ((int)p_Var6->vx < iVar9) {
        p_Var6->vx = -0x8000;
      }
      else {
        p_Var6->vx = 0x7fff;
      }
    }
    iVar10 = iVar10 + 1;
    p_Var6 = p_Var6 + 1;
  } while (iVar10 < 4);
  bVar1 = false;
  if ((((int)Tmd_2DSpeed->vx < iVar9) && ((int)Tmd_2DSpeed[1].vx < iVar9)) &&
     ((int)Tmd_2DSpeed[2].vx < iVar9)) {
    bVar1 = (int)Tmd_2DSpeed[3].vx < iVar9;
  }
  bVar2 = false;
  if (((iVar9 < (int)Tmd_2DSpeed->vx) && (iVar9 < (int)Tmd_2DSpeed[1].vx)) &&
     (iVar9 < (int)Tmd_2DSpeed[2].vx)) {
    bVar2 = iVar9 < (int)Tmd_2DSpeed[3].vx;
  }
  if ((bVar1) || (bVar2)) {
    sVar4 = Tmd_2DSpeed[1].vx;
    if (Tmd_2DSpeed[1].vx < Tmd_2DSpeed->vx) {
      sVar4 = Tmd_2DSpeed->vx;
    }
    iVar9 = (int)Tmd_2DSpeed[2].vx;
    if ((int)Tmd_2DSpeed[2].vx < (int)sVar4) {
      iVar9 = (int)sVar4;
    }
    local_24 = (int)Tmd_2DSpeed[3].vx;
    if ((int)Tmd_2DSpeed[3].vx < iVar9) {
      local_24 = iVar9;
    }
    sVar4 = Tmd_2DSpeed[1].vx;
    if (Tmd_2DSpeed->vx < Tmd_2DSpeed[1].vx) {
      sVar4 = Tmd_2DSpeed->vx;
    }
    iVar9 = (int)Tmd_2DSpeed[2].vx;
    if ((int)sVar4 < (int)Tmd_2DSpeed[2].vx) {
      iVar9 = (int)sVar4;
    }
    local_28 = (int)Tmd_2DSpeed[3].vx;
    if (iVar9 < (int)Tmd_2DSpeed[3].vx) {
      local_28 = iVar9;
    }
  }
  else {
    Plat_ZClipPortal(0xb0,&local_28,&local_24);
  }
  if (((iVar12 == iVar14) && (iVar12 == (int)(short)local_30)) ||
     ((iVar11 == iVar13 && (iVar11 == (int)local_30._2_2_)))) {
    local_28 = 0;
    local_24 = 0x140;
  }
LAB_8002e9c0:
  sVar4 = Scr_W;
  if (local_24 < (int)Scr_W) {
    sVar4 = (short)local_24;
  }
  if (local_28 < 0) {
    local_28._0_2_ = 0;
  }
  local_24._0_2_ = sVar4 + 1;
  local_28._0_2_ = (short)local_28 + -1;
  port->min = (short)local_28;
  port->max = (short)local_24;
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Plat_IsVisible(struct _VISIBILITY *cur /*$a0*/, struct _VISIBILITY *v /*$a1*/, struct _VISPORTAL *port /*$a2*/, long *mini_x /*$a3*/, long *maxi_x /*stack 16*/)
 // line 745, offset 0x8002ea3c
	/* begin block 1 */
		// Start line: 746
		// Start offset: 0x8002EA3C
		// Variables:
	// 		long min_x; // $t0
	// 		long max_x; // $a2
	/* end block 1 */
	// End offset: 0x8002EB78
	// End Line: 810

	/* begin block 2 */
		// Start line: 1867
	/* end block 2 */
	// End Line: 1868

long Plat_IsVisible(_VISIBILITY *cur,_VISIBILITY *v,_VISPORTAL *port,long *mini_x,long *maxi_x)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  sVar1 = Scr_W;
  if ((cur == (_VISIBILITY *)0x0) || ((cur->state & 1U) != 0)) {
    v->min = 0;
    v->max = sVar1;
    v->state = v->state | 4;
    return 1;
  }
  if ((v->state & 2U) == 0) {
    iVar4 = (int)port->min;
    iVar3 = (int)port->max;
    if (((iVar3 != 0x8000) && (*mini_x < iVar3)) && (iVar4 < *maxi_x)) {
      v->state = v->state | 4;
      iVar2 = *mini_x;
      if (*mini_x < iVar4) {
        iVar2 = iVar4;
      }
      iVar4 = *maxi_x;
      if (iVar3 < *maxi_x) {
        iVar4 = iVar3;
      }
      if ((iVar2 < (int)v->min) || ((int)v->max < iVar4)) {
        sVar1 = (short)iVar2;
        if ((int)v->min < iVar2) {
          sVar1 = v->min;
        }
        v->min = sVar1;
        sVar1 = (short)iVar4;
        if (iVar4 < (int)v->max) {
          sVar1 = v->max;
        }
        v->max = sVar1;
        *mini_x = (int)v->min;
        *maxi_x = (int)v->max;
        return 1;
      }
    }
  }
  return 0;
}



// decompiled code
// original method signature: 
// void * /*$ra*/ Plat_DisplayPlatform(struct _PLATFORM *p /*$s0*/, void *prims /*$s1*/, long mini_x /*$s2*/, long maxi_x /*$s3*/)
 // line 815, offset 0x8002eb80
	/* begin block 1 */
		// Start line: 816
		// Start offset: 0x8002EB80
		// Variables:
	// 		long ot; // $a2
	/* end block 1 */
	// End offset: 0x8002F00C
	// End Line: 886

	/* begin block 2 */
		// Start line: 2014
	/* end block 2 */
	// End Line: 2015

void * Plat_DisplayPlatform(_PLATFORM *p,void *prims,long mini_x,long maxi_x)

{
  short sVar1;
  short sVar2;
  short sVar3;
  undefined4 *puVar4;
  int iVar5;
  
  Plat_SetDisplayed(p,&Plat_Visibility);
  if (*(char *)((int)&p[1].obj.pos.vx + 1) != '\0') {
    sVar1 = p[1].obj.pos.vy;
    sVar2 = *(short *)&p[1].obj.father;
    *(short *)&p[1].obj.prec = *(short *)&p[1].obj.prec + sVar1;
    sVar3 = *(short *)&p[1].obj.handle;
    *(short *)&p[1].obj.father = sVar2 + sVar1;
    sVar2 = p[1].obj.collision_mode;
    *(short *)&p[1].obj.handle = sVar3 + sVar1;
    p[1].obj.collision_mode = sVar2 + sVar1;
  }
  GtxTmd_RotTransPersN(&(p->obj).b_box,Tmd_2DSpeed,8);
  iVar5 = (uint)(Pvl_File->fog).cd * 100;
  if (*(char *)((int)&p[1].obj.pos.vx + 1) != '\0') {
    sVar1 = p[1].obj.pos.vy;
    sVar2 = *(short *)&p[1].obj.father;
    *(short *)&p[1].obj.prec = *(short *)&p[1].obj.prec - sVar1;
    sVar3 = *(short *)&p[1].obj.handle;
    *(short *)&p[1].obj.father = sVar2 - sVar1;
    sVar2 = p[1].obj.collision_mode;
    *(short *)&p[1].obj.handle = sVar3 - sVar1;
    p[1].obj.collision_mode = sVar2 - sVar1;
  }
  if (((((((int)Tmd_2DSpeed->vz < iVar5) || ((int)Tmd_2DSpeed[1].vz < iVar5)) ||
        ((int)Tmd_2DSpeed[2].vz < iVar5)) ||
       (((int)Tmd_2DSpeed[3].vz < iVar5 || ((int)Tmd_2DSpeed[4].vz < iVar5)))) ||
      (((int)Tmd_2DSpeed[5].vz < iVar5 ||
       (((int)Tmd_2DSpeed[6].vz < iVar5 || ((int)Tmd_2DSpeed[7].vz < iVar5)))))) &&
     (((Tmd_2DSpeed->vz != 0 ||
       ((((Tmd_2DSpeed[1].vz != 0 || (Tmd_2DSpeed[2].vz != 0)) || (Tmd_2DSpeed[3].vz != 0)) ||
        (((Tmd_2DSpeed[4].vz == 0 || (Tmd_2DSpeed[5].vz == 0)) ||
         ((Tmd_2DSpeed[6].vz == 0 || (Tmd_2DSpeed[7].vz != 0)))))))) &&
      (((((mini_x <= (int)Tmd_2DSpeed->vx || (mini_x <= (int)Tmd_2DSpeed[1].vx)) ||
         (mini_x <= (int)Tmd_2DSpeed[2].vx)) ||
        ((((mini_x <= (int)Tmd_2DSpeed[3].vx || (mini_x <= (int)Tmd_2DSpeed[4].vx)) ||
          (mini_x <= (int)Tmd_2DSpeed[5].vx)) ||
         ((mini_x <= (int)Tmd_2DSpeed[6].vx || (mini_x <= (int)Tmd_2DSpeed[7].vx)))))) &&
       ((((((int)Tmd_2DSpeed->vx < maxi_x ||
           (((int)Tmd_2DSpeed[1].vx < maxi_x || ((int)Tmd_2DSpeed[2].vx < maxi_x)))) ||
          ((int)Tmd_2DSpeed[3].vx < maxi_x)) ||
         (((((int)Tmd_2DSpeed[4].vx < maxi_x || ((int)Tmd_2DSpeed[5].vx < maxi_x)) ||
           ((int)Tmd_2DSpeed[6].vx < maxi_x)) || ((int)Tmd_2DSpeed[7].vx < maxi_x)))) &&
        (((-1 < Tmd_2DSpeed->vy || (-1 < Tmd_2DSpeed[1].vy)) ||
         ((-1 < Tmd_2DSpeed[2].vy || (-1 < Tmd_2DSpeed[3].vy)))))))))))) {
    if (((Tmd_2DSpeed[4].vy <= Scr_H) || (Tmd_2DSpeed[5].vy <= Scr_H)) ||
       ((Tmd_2DSpeed[6].vy <= Scr_H || (Tmd_2DSpeed[7].vy <= Scr_H)))) {
      puVar4 = (undefined4 *)(p->obj).description;
      GtxTmd_RotTransPersN1(*puVar4,Tmd_2D,puVar4[1]);
      prims = (void *)GtxTmx_Display4LOFF((p->obj).description,prims,Scr->ot,(int)Scr_OtSize,
                                          Main_TextContext.Font.ascii_tab._20_4_);
    }
    Plat_SetDisplayed(p,&Plat_RealVisibility);
  }
  return prims;
}



// decompiled code
// original method signature: 
// void * /*$ra*/ Plat_Display(void *Prims /*$s2*/)
 // line 889, offset 0x8002f028
	/* begin block 1 */
		// Start line: 890
		// Start offset: 0x8002F028
		// Variables:
	// 		struct _PLATFORM *p; // $s0
	// 		struct _VISIBILITY *vis; // $v1
	// 		short i; // $s1
	// 		struct PLATFORM_5fake CamBase; // stack offset -136

		/* begin block 1.1 */
			// Start line: 918
			// Start offset: 0x8002F074
			// Variables:
		// 		char text[80]; // stack offset -104
		// 		struct _VISPORTAL BeginPortal; // stack offset -24
		/* end block 1.1 */
		// End offset: 0x8002F0A8
		// End Line: 954
	/* end block 1 */
	// End offset: 0x8002F128
	// End Line: 971

	/* begin block 2 */
		// Start line: 2174
	/* end block 2 */
	// End Line: 2175

void * Plat_Display(void *Prims)

{
  _VISIBILITY *p_Var1;
  void *Prims_00;
  _D3_OBJECT *obj;
  _PLATFORM *p_Var2;
  int iVar3;
  _VISPORTAL local_18;
  
  Plat_ClearZones();
  p_Var1 = Vis_GetVisPos(0x68);
  if (p_Var1 == (_VISIBILITY *)0x0) {
    p_Var1 = Plat_LastZone;
  }
  Plat_LastZone = p_Var1;
  if (p_Var1 != (_VISIBILITY *)0x0) {
    local_18.min = 0;
    local_18.max = Scr_W;
    Plat_LastZone = p_Var1;
    local_18.zone = p_Var1;
    Plat_ScanZone((_VISIBILITY *)0x0,&local_18,0,(int)Scr_W);
    Prims = Plat_DisplayZones(Prims);
  }
  iVar3 = 0;
  D3_ManageList(Pvl_GlobalObjects);
  D3_ManageList(Pvl_HoleObjects);
  p_Var2 = Pvl_Platforms;
  if (0 < Pvl_File->n_platforms) {
    do {
      obj = (p_Var2->obj).child;
      if (obj != (_D3_OBJECT *)0x0) {
        D3_ManageList(obj);
      }
      iVar3 = iVar3 + 1;
      p_Var2 = (_PLATFORM *)&p_Var2[1].obj.last_pos.vz;
    } while (iVar3 * 0x10000 >> 0x10 < (int)Pvl_File->n_platforms);
  }
  Prims_00 = D3_DisplayList(Pvl_HoleObjects,Prims,0,(int)Scr_W);
  Prims_00 = D3_DisplayList(Pvl_GlobalObjects,Prims_00,0,(int)Scr_W);
  return Prims_00;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Plat_MarkSurface(struct _PLATFORM *p /*$a0*/)
 // line 1138, offset 0x8002f178
	/* begin block 1 */
		// Start line: 1140
		// Start offset: 0x8002F178
		// Variables:
	// 		struct PLATFORM_7fake *pts; // $v0
	// 		long i; // $a2
	// 		long n; // $a0
	// 		long height; // $a1
	/* end block 1 */
	// End offset: 0x8002F1CC
	// End Line: 1153

	/* begin block 2 */
		// Start line: 2681
	/* end block 2 */
	// End Line: 2682

void Plat_MarkSurface(_PLATFORM *p)

{
  short sVar1;
  short sVar2;
  int *piVar3;
  ushort *puVar4;
  int iVar5;
  int iVar6;
  
  sVar1 = p[1].obj.pos.vy;
  sVar2 = *(short *)&p[1].obj.prec;
  piVar3 = (int *)(p->obj).description;
  iVar5 = piVar3[1];
  iVar6 = 0;
  if (0 < iVar5) {
    puVar4 = (ushort *)(*piVar3 + 6);
    do {
      if ((int)(short)puVar4[-1] == (int)sVar1 + (int)sVar2) {
        *puVar4 = *puVar4 | 2;
      }
      iVar6 = iVar6 + 1;
      puVar4 = puVar4 + 4;
    } while (iVar6 < iVar5);
  }
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ Plat_ChangeLevel(struct _PLATFORM *p /*$a0*/, short d /*$a3*/)
 // line 1156, offset 0x8002f1d4
	/* begin block 1 */
		// Start line: 1157
		// Start offset: 0x8002F1D4
		// Variables:
	// 		struct PLATFORM_7fake *pts; // $v0
	// 		short i; // $a1
	// 		short nd; // $a2
	// 		short nh; // $t0
	// 		long test; // $v0

		/* begin block 1.1 */
			// Start line: 1180
			// Start offset: 0x8002F248
			// Variables:
		// 		struct PLATFORM_93fake *o; // $v0
		/* end block 1.1 */
		// End offset: 0x8002F29C
		// End Line: 1201
	/* end block 1 */
	// End offset: 0x8002F29C
	// End Line: 1204

	/* begin block 2 */
		// Start line: 2726
	/* end block 2 */
	// End Line: 2727

short Plat_ChangeLevel(_PLATFORM *p,short d)

{
  short sVar1;
  bool bVar2;
  int *piVar3;
  ushort uVar4;
  int iVar5;
  ushort *puVar6;
  int iVar7;
  short sVar8;
  
  if ((int)p[1].obj.pos.vy + (int)d < 0) {
    sVar8 = 0;
  }
  else {
    sVar8 = p[1].obj.pos.vy + d;
  }
  sVar1 = *(short *)&p[1].obj.prec;
  uVar4 = sVar1 + sVar8;
  if ((int)((uint)(ushort)d << 0x10) < 1) {
    bVar2 = uVar4 != (ushort)(p[1].obj.pos.vy + sVar1);
  }
  else {
    bVar2 = (int)((uint)uVar4 << 0x10) < (int)((uint)(ushort)((p->obj).comp_opt1 + sVar1) << 0x10);
  }
  if (bVar2) {
    piVar3 = (int *)(p->obj).description;
    iVar5 = (int)*(short *)(piVar3 + 1);
    iVar7 = 0;
    if (0 < iVar5) {
      puVar6 = (ushort *)(*piVar3 + 4);
      do {
        iVar7 = iVar7 + 1;
        if ((puVar6[1] & 2) != 0) {
          *puVar6 = uVar4;
        }
        puVar6 = puVar6 + 4;
      } while (iVar7 * 0x10000 >> 0x10 < iVar5);
    }
    p[1].obj.pos.vy = sVar8;
  }
  return sVar8;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Water_CTask()
 // line 1216, offset 0x8002f2a8
	/* begin block 1 */
		// Start line: 1217
		// Start offset: 0x8002F2A8
		// Variables:
	// 		struct _PLATFORM *p; // $s4
	// 		struct PLATFORM_93fake *o; // $s7
	// 		struct PLATFORM_7fake *v; // $s2
	// 		struct PLATFORM_9fake tab_move[5]; // stack offset -88
	// 		struct PLATFORM_9fake *mv; // $s0
	// 		struct PLATFORM_9fake tab_chrono[5]; // stack offset -64
	// 		struct PLATFORM_9fake *cv; // $s2
	// 		long i; // $s1
	// 		long r; // $s6
	// 		long Level; // $v0
	// 		long TestMask; // $v0
	// 		long start_empty; // $fp
	/* end block 1 */
	// End offset: 0x8002F668
	// End Line: 1326

	/* begin block 2 */
		// Start line: 2853
	/* end block 2 */
	// End Line: 2854

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Water_CTask(void)

{
  bool bVar1;
  short d;
  uint uVar2;
  long lVar3;
  short *psVar4;
  short *psVar5;
  int iVar6;
  short *psVar7;
  short *psVar8;
  _PLATFORM *p;
  int iVar9;
  short **ppsVar10;
  int iVar11;
  short local_58 [12];
  short local_40;
  short local_3e [11];
  
  p = (_PLATFORM *)TaskCurrent->local;
  ppsVar10 = (short **)(p->obj).description;
  iVar11 = *(int *)&p[1].obj.last_pos;
  (p->obj).comp_opt1 = p[1].obj.pos.vy;
  Plat_MarkSurface(p);
  iVar9 = 0;
  uVar2 = Scts_Interruptors & (int)p[1].obj.pos.vz;
  if (iVar11 != 0) {
    uVar2 = (uint)(uVar2 == 0);
  }
  if (uVar2 != 0) {
    Plat_ChangeLevel(p,-p[1].obj.pos.vy);
  }
  psVar7 = local_58;
  psVar4 = &local_40;
  iVar6 = 0;
  psVar5 = local_58 + 1;
  do {
    *psVar7 = 0;
    *psVar5 = 0;
    if (*psVar7 == 0) {
      do {
        lVar3 = M_rand();
        uVar2 = lVar3 % 0x1e - 0x3c;
        *psVar7 = (short)uVar2;
      } while ((uVar2 & 0xffff) == 0);
    }
    if (*psVar5 == 0) {
      do {
        lVar3 = M_rand();
        uVar2 = lVar3 % 0x1e - 0x3c;
        *psVar5 = (short)uVar2;
      } while ((uVar2 & 0xffff) == 0);
    }
    d = (short)((int)*psVar7 << 1);
    if (0 < (int)*psVar7) {
      d = 0;
    }
    *psVar4 = d;
    d = (short)((int)*psVar5 << 1);
    if (0 < (int)*psVar5) {
      d = 0;
    }
    psVar4[1] = d;
    iVar6 = iVar6 + 1;
    psVar5 = psVar5 + 2;
    psVar7 = psVar7 + 2;
    psVar4 = psVar4 + 2;
  } while (iVar6 < 5);
  do {
    uVar2 = Scts_Interruptors & (int)p[1].obj.pos.vz;
    if (iVar11 != 0) {
      uVar2 = (uint)(uVar2 == 0);
    }
    if (uVar2 == 0) {
      d = 2;
    }
    else {
      d = -2;
    }
    d = Plat_ChangeLevel(p,d);
    if (d != 0) {
      psVar7 = *ppsVar10;
      iVar6 = 0;
      if (0 < (int)ppsVar10[1]) {
        psVar4 = psVar7 + 1;
        do {
          if (((*(char *)((int)&p[1].obj.pos.vx + 1) == '\x03') && (p[1].obj.pos.pad != 0)) &&
             (bVar1 = iVar9 == 0, iVar9 = iVar9 + -1, bVar1)) {
            lVar3 = M_rand();
            Impact_Smoke((char)psVar7,1);
            iVar9 = lVar3 % 400 + 199;
          }
          if ((psVar4[2] & 1U) == 0) {
            d = 1;
            if (local_58[(iVar6 % 5) * 2] < 1) {
              d = -1;
            }
            *psVar7 = *psVar7 + d;
            d = 1;
            if (local_58[(iVar6 % 5) * 2 + 1] < 1) {
              d = -1;
            }
            *psVar4 = *psVar4 + d;
          }
          iVar6 = iVar6 + 1;
          psVar4 = psVar4 + 4;
          psVar7 = psVar7 + 4;
        } while (iVar6 < (int)ppsVar10[1]);
      }
      psVar5 = local_58;
      psVar8 = &local_40;
      iVar6 = 0;
      psVar7 = local_3e;
      psVar4 = local_58 + 1;
      do {
        *psVar8 = *psVar8 + 1;
        *psVar7 = *psVar7 + 1;
        d = *psVar8;
        if ((int)d == (int)*psVar5) {
          *psVar5 = -d;
          if ((int)d * -0x10000 < 1) {
            d = d * -2;
          }
          else {
            d = 0;
          }
          *psVar8 = d;
        }
        d = *psVar7;
        if ((int)d == (int)*psVar4) {
          *psVar4 = -d;
          if ((int)d * -0x10000 < 1) {
            d = d * -2;
          }
          else {
            d = 0;
          }
          *psVar7 = d;
        }
        iVar6 = iVar6 + 1;
        psVar4 = psVar4 + 2;
        psVar5 = psVar5 + 2;
        psVar7 = psVar7 + 2;
        psVar8 = psVar8 + 2;
      } while (iVar6 < 5);
    }
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Lava_CTask()
 // line 1330, offset 0x8002f668
	/* begin block 1 */
		// Start line: 1331
		// Start offset: 0x8002F668
		// Variables:
	// 		struct _PLATFORM *p; // $s4
	// 		struct PLATFORM_93fake *o; // $s7
	// 		struct PLATFORM_7fake *v; // $s1
	// 		struct PLATFORM_7fake rot; // stack offset -104
	// 		long i; // $s2
	// 		long r; // $s6
	// 		struct PLATFORM_9fake tab_move[5]; // stack offset -96
	// 		struct PLATFORM_9fake *mv; // $s0
	// 		struct PLATFORM_9fake tab_chrono[5]; // stack offset -72
	// 		struct PLATFORM_9fake *cv; // $s1
	// 		struct PLATFORM_8fake col; // stack offset -48
	/* end block 1 */
	// End offset: 0x8002FA88
	// End Line: 1422

	/* begin block 2 */
		// Start line: 3213
	/* end block 2 */
	// End Line: 3214

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Lava_CTask(void)

{
  bool bVar1;
  short sVar2;
  long lVar3;
  uint uVar4;
  short *psVar5;
  short *psVar6;
  short *psVar7;
  short *psVar8;
  int iVar9;
  _PLATFORM *p;
  int iVar10;
  short **ppsVar11;
  short local_60 [12];
  short local_48;
  short local_46 [11];
  undefined *local_30;
  
  p = (_PLATFORM *)TaskCurrent->local;
  ppsVar11 = (short **)(p->obj).description;
  local_30 = PTR_DAT_800ad440;
  iVar10 = 0;
  if ((Scts_Interruptors & (int)p[1].obj.pos.vz) != 0) {
    Plat_ChangeLevel(p,-p[1].obj.pos.vy);
  }
  Plat_MarkSurface(p);
  psVar7 = local_60;
  psVar5 = &local_48;
  iVar9 = 0;
  psVar6 = local_60 + 1;
  do {
    *psVar7 = 0;
    *psVar6 = 0;
    if (*psVar7 == 0) {
      do {
        lVar3 = M_rand();
        uVar4 = lVar3 % 0x32 - 100;
        *psVar7 = (short)uVar4;
      } while ((uVar4 & 0xffff) == 0);
    }
    if (*psVar6 == 0) {
      do {
        lVar3 = M_rand();
        uVar4 = lVar3 % 0x32 - 100;
        *psVar6 = (short)uVar4;
      } while ((uVar4 & 0xffff) == 0);
    }
    sVar2 = (short)((int)*psVar7 << 1);
    if (0 < (int)*psVar7) {
      sVar2 = 0;
    }
    *psVar5 = sVar2;
    sVar2 = (short)((int)*psVar6 << 1);
    if (0 < (int)*psVar6) {
      sVar2 = 0;
    }
    psVar5[1] = sVar2;
    iVar9 = iVar9 + 1;
    psVar6 = psVar6 + 2;
    psVar7 = psVar7 + 2;
    psVar5 = psVar5 + 2;
  } while (iVar9 < 5);
  do {
    psVar7 = *ppsVar11;
    iVar9 = 0;
    if (0 < (int)ppsVar11[1]) {
      psVar5 = psVar7 + 1;
      do {
        if (((*(char *)((int)&p[1].obj.pos.vx + 1) == '\x04') && (p[1].obj.pos.pad != 0)) &&
           (bVar1 = iVar10 == 0, iVar10 = iVar10 + -1, bVar1)) {
          lVar3 = M_rand();
          M_rand();
          Shoot_Add((_D3_OBJECT *)0x0,(char)psVar7,0x98,0xd0,0xd,0xc,5,0x106);
          iVar10 = lVar3 % 600 + 299;
        }
        if ((psVar5[2] & 1U) == 0) {
          sVar2 = 1;
          if (local_60[(iVar9 % 5) * 2] < 1) {
            sVar2 = -1;
          }
          *psVar7 = *psVar7 + sVar2;
          sVar2 = 1;
          if (local_60[(iVar9 % 5) * 2 + 1] < 1) {
            sVar2 = -1;
          }
          *psVar5 = *psVar5 + sVar2;
        }
        iVar9 = iVar9 + 1;
        psVar5 = psVar5 + 4;
        psVar7 = psVar7 + 4;
      } while (iVar9 < (int)ppsVar11[1]);
    }
    psVar6 = local_60;
    psVar8 = &local_48;
    iVar9 = 0;
    psVar7 = local_46;
    psVar5 = local_60 + 1;
    do {
      *psVar8 = *psVar8 + 1;
      *psVar7 = *psVar7 + 1;
      sVar2 = *psVar8;
      if ((int)sVar2 == (int)*psVar6) {
        *psVar6 = -sVar2;
        if ((int)sVar2 * -0x10000 < 1) {
          sVar2 = sVar2 * -2;
        }
        else {
          sVar2 = 0;
        }
        *psVar8 = sVar2;
      }
      sVar2 = *psVar7;
      if ((int)sVar2 == (int)*psVar5) {
        *psVar5 = -sVar2;
        if ((int)sVar2 * -0x10000 < 1) {
          sVar2 = sVar2 * -2;
        }
        else {
          sVar2 = 0;
        }
        *psVar7 = sVar2;
      }
      iVar9 = iVar9 + 1;
      psVar5 = psVar5 + 2;
      psVar6 = psVar6 + 2;
      psVar7 = psVar7 + 2;
      psVar8 = psVar8 + 2;
    } while (iVar9 < 5);
    if (((int)p[1].obj.pos.vz & Scts_Interruptors) != 0) {
      Plat_ChangeLevel(p,-4);
    }
    Task_Sleep(5);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Roll_CTask()
 // line 1427, offset 0x8002fa88
	/* begin block 1 */
		// Start line: 1428
		// Start offset: 0x8002FA88
		// Variables:
	// 		struct _PLATFORM *p; // $v0
	// 		struct PLATFORM_92fake *prims; // $s1
	// 		struct PLATFORM_92fake *prs; // $a3
	// 		short n; // $s0
	// 		short i; // $t7
	// 		short u0; // $t5
	// 		short v0; // $t6
	// 		short u1; // $t3
	// 		short v1; // $t4
	/* end block 1 */
	// End offset: 0x8002FC54
	// End Line: 1497

	/* begin block 2 */
		// Start line: 3516
	/* end block 2 */
	// End Line: 3517

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Roll_CTask(void)

{
  short sVar1;
  short sVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  ushort uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  ushort uVar13;
  ushort uVar14;
  int iVar15;
  
  iVar4 = *(int *)((int)TaskCurrent->local + 0x24);
  iVar15 = *(int *)(iVar4 + 0x10);
  sVar2 = *(short *)(iVar4 + 0x14);
  do {
    iVar8 = 0;
    iVar5 = (int)sVar2;
    iVar4 = iVar15;
    if (0 < iVar5) {
      do {
        sVar1 = *(short *)(iVar4 + 0xe);
        if (sVar1 != 0) {
          uVar6 = *(ushort *)(iVar4 + 4);
          uVar7 = (uint)uVar6 & 0xff;
          uVar14 = (ushort)uVar7;
          uVar12 = (uint)(uVar6 >> 8);
          uVar13 = *(ushort *)(iVar4 + 0x10) & 0xff;
          uVar11 = (uint)(*(ushort *)(iVar4 + 0x10) >> 8);
          uVar10 = (uint)*(ushort *)(iVar4 + 0x12) & 0xff;
          uVar3 = *(ushort *)(iVar4 + 0x12) >> 8;
          uVar9 = (uint)uVar3;
          if (sVar1 == 0x2000) {
            uVar14 = (ushort)(uVar7 - 1);
            uVar13 = uVar13 - 1;
            if ((int)(uVar7 - 1) < (int)uVar9) {
              uVar14 = (uVar3 + (short)uVar10) - 1;
              uVar13 = (uVar3 + (short)uVar10 * 2) - 1;
            }
LAB_8002fbf8:
            uVar6 = (ushort)(uVar12 << 8);
            uVar3 = uVar14 | uVar6;
          }
          else {
            if (sVar1 < 0x2001) {
              if (sVar1 == 0x1000) {
                uVar14 = (ushort)(uVar7 + 1);
                uVar13 = uVar13 + 1;
                if (uVar9 + uVar10 <= uVar7 + 1) {
                  uVar14 = uVar3;
                  uVar13 = (ushort)(uVar9 + uVar10);
                }
              }
              goto LAB_8002fbf8;
            }
            if (sVar1 == 0x3000) {
              uVar12 = uVar12 - 1;
              uVar11 = uVar11 - 1;
              if ((int)uVar12 < (int)uVar9) {
                uVar12 = (uVar9 + uVar10) - 1;
                uVar11 = (uVar9 + uVar10 * 2) - 1;
              }
              goto LAB_8002fbf8;
            }
            uVar6 = uVar6 & 0xff00;
            if (sVar1 == 0x4000) {
              uVar12 = uVar12 + 1;
              uVar11 = uVar11 + 1;
              if (uVar9 + uVar10 <= uVar12) {
                uVar11 = uVar9 + uVar10;
                uVar12 = uVar9;
              }
              goto LAB_8002fbf8;
            }
            uVar3 = uVar14 | uVar6;
          }
          *(ushort *)(iVar4 + 8) = uVar13 | uVar6;
          *(ushort *)(iVar4 + 4) = uVar3;
          uVar6 = (ushort)(uVar11 << 8);
          *(ushort *)(iVar4 + 0xc) = uVar14 | uVar6;
          *(ushort *)(iVar4 + 0x10) = uVar13 | uVar6;
        }
        iVar8 = iVar8 + 1;
        iVar4 = iVar4 + (uint)*(byte *)(iVar4 + 1) * 4 + 4;
      } while (iVar8 * 0x10000 >> 0x10 < iVar5);
    }
    Task_Next();
  } while( true );
}





