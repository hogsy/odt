#include "THISDUST.H"
#include "SHAPE.H"


// decompiled code
// original method signature: 
// void /*$ra*/ Shp_Init()
 // line 23, offset 0x8009e690
	/* begin block 1 */
		// Start line: 50
	/* end block 1 */
	// End Line: 51

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Shp_Init(void)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Shp_InitFile(void *S /*$a0*/)
 // line 36, offset 0x8009e698
	/* begin block 1 */
		// Start line: 38
		// Start offset: 0x8009E698
		// Variables:
	// 		struct SHAPE_71fake *File; // $a0
	// 		long i; // $a2
	/* end block 1 */
	// End offset: 0x8009E70C
	// End Line: 54

	/* begin block 2 */
		// Start line: 76
	/* end block 2 */
	// End Line: 77

void Shp_InitFile(void *S)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  
  iVar3 = 0;
  if ((*(uint *)S & 0xffff0000) != 0x10000) {
    *(undefined2 *)((int)S + 2) = 1;
    pvVar2 = S;
    if (0 < *(short *)((int)S + 4)) {
      do {
        iVar1 = (int)S + *(int *)((int)pvVar2 + 0x10);
        *(int *)((int)pvVar2 + 0x10) = iVar1;
        if (*(int *)(iVar1 + 0x14) != 0) {
          *(int *)(iVar1 + 0x14) = (int)S + *(int *)(iVar1 + 0x14);
        }
        iVar3 = iVar3 + 1;
        pvVar2 = (void *)((int)pvVar2 + 4);
      } while (iVar3 < (int)*(short *)((int)S + 4));
    }
    *(int *)((int)S + 0xc) = (int)S + *(int *)((int)S + 0xc);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Shp_TmdToVram(void *S /*$s0*/, void *T /*$s6*/, short Offset /*$a2*/, short dummy /*$a3*/)
 // line 62, offset 0x8009e714
	/* begin block 1 */
		// Start line: 63
		// Start offset: 0x8009E714
		// Variables:
	// 		struct SHAPE_68fake Shp; // stack offset -48
	// 		struct SHAPE_72fake *Tmd; // $s4
	// 		struct SHAPE_91fake *Obj; // $s1
	// 		struct SHAPE_90fake *Prim; // $s0
	// 		short i; // $s3
	// 		short j; // $s2
	/* end block 1 */
	// End offset: 0x8009E818
	// End Line: 89

	/* begin block 2 */
		// Start line: 130
	/* end block 2 */
	// End Line: 131

void Shp_TmdToVram(void *S,void *T,short Offset,short dummy)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  SHAPE_68fake local_30;
  
  Shp_GroupToVram(S,1);
  if (*(int *)T != 0x41414141) {
    iVar4 = 0;
    if (*(int *)((int)T + 8) != 0) {
      iVar1 = 0;
      local_30.file = S;
      do {
        iVar3 = (int)T + (iVar1 >> 0x10) * 0x1c + 0xc;
        iVar2 = *(int *)(iVar3 + 0x10);
        iVar1 = 0;
        if (*(int *)(iVar3 + 0x14) != 0) {
          do {
            Shp_SetTmdPrim((char)iVar2,&local_30,Offset,1);
            iVar1 = iVar1 + 1;
            iVar2 = iVar2 + (uint)*(byte *)(iVar2 + 1) * 4 + 4;
          } while ((uint)(iVar1 * 0x10000 >> 0x10) < *(uint *)(iVar3 + 0x14));
        }
        iVar4 = iVar4 + 1;
        iVar1 = iVar4 * 0x10000;
      } while ((uint)(iVar4 * 0x10000 >> 0x10) < *(uint *)((int)T + 8));
    }
    *(undefined4 *)T = 0x41414141;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Shp_TmdToVramUv(void *S /*$s0*/, void *T /*$a1*/, short Offset /*$a2*/)
 // line 97, offset 0x8009e840
	/* begin block 1 */
		// Start line: 98
		// Start offset: 0x8009E840
		// Variables:
	// 		struct SHAPE_68fake Shp; // stack offset -48
	// 		struct SHAPE_72fake *Tmd; // $s3
	// 		struct SHAPE_91fake *Obj; // $s1
	// 		struct SHAPE_90fake *Prim; // $s0
	// 		short i; // $s4
	// 		short j; // $s2
	/* end block 1 */
	// End offset: 0x8009E93C
	// End Line: 126

	/* begin block 2 */
		// Start line: 223
	/* end block 2 */
	// End Line: 224

void Shp_TmdToVramUv(void *S,void *T,short Offset)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  SHAPE_68fake local_30;
  
  Shp_GroupToVram(S,1);
  if (*(int *)T != 0x41414141) {
    iVar4 = 0;
    if (*(int *)((int)T + 8) != 0) {
      iVar1 = 0;
      local_30.file = S;
      do {
        iVar3 = (int)T + (iVar1 >> 0x10) * 0x1c + 0xc;
        iVar2 = *(int *)(iVar3 + 0x10);
        iVar1 = 0;
        if (*(int *)(iVar3 + 0x14) != 0) {
          do {
            Shp_SetTmdPrim((char)iVar2,&local_30,Offset,0);
            iVar1 = iVar1 + 1;
            iVar2 = iVar2 + (uint)*(byte *)(iVar2 + 1) * 4 + 4;
          } while ((uint)(iVar1 * 0x10000 >> 0x10) < *(uint *)(iVar3 + 0x14));
        }
        iVar4 = iVar4 + 1;
        iVar1 = iVar4 * 0x10000;
      } while ((uint)(iVar4 * 0x10000 >> 0x10) < *(uint *)((int)T + 8));
    }
    *(undefined4 *)T = 0x41414141;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Shp_SetTmdPrim(struct SHAPE_90fake *Prim /*$s0*/, struct SHAPE_68fake *Shp /*$s1*/, short Offset /*$t0*/, short Mode /*$s2*/)
 // line 134, offset 0x8009e960
	/* begin block 1 */
		// Start line: 135
		// Start offset: 0x8009E960
		// Variables:
	// 		short Su; // stack offset -24
	// 		short Sv; // stack offset -22
	// 		short Code; // $v0
	/* end block 1 */
	// End offset: 0x8009EB40
	// End Line: 210

	/* begin block 2 */
		// Start line: 319
	/* end block 2 */
	// End Line: 320

void Shp_SetTmdPrim(undefined Prim,SHAPE_68fake *Shp,short Offset,short Mode)

{
  ushort uVar1;
  short sVar2;
  byte bVar3;
  undefined3 in_register_00000011;
  int iVar4;
  short local_18;
  short local_16 [3];
  
  iVar4 = CONCAT31(in_register_00000011,Prim);
  bVar3 = *(byte *)(iVar4 + 3) & 0x7c;
  if (bVar3 == 0x34) {
LAB_8009e9d0:
    Offset = *(short *)(iVar4 + 6) + Offset;
    *(short *)(iVar4 + 6) = Offset;
    Shp->shape = Offset;
    Shp_GetUV(Shp,&local_18,local_16);
    *(ushort *)(iVar4 + 4) =
         local_18 + (*(ushort *)(iVar4 + 4) & 0xff) |
         (local_16[0] + (*(ushort *)(iVar4 + 4) >> 8)) * 0x100;
    *(ushort *)(iVar4 + 8) =
         local_18 + (*(ushort *)(iVar4 + 8) & 0xff) |
         (local_16[0] + (*(ushort *)(iVar4 + 8) >> 8)) * 0x100;
    uVar1 = *(ushort *)(iVar4 + 10);
    *(ushort *)(iVar4 + 0xc) =
         local_18 + (*(ushort *)(iVar4 + 0xc) & 0xff) |
         (local_16[0] + (*(ushort *)(iVar4 + 0xc) >> 8)) * 0x100;
  }
  else {
    if (bVar3 < 0x35) {
      if (bVar3 == 0x24) goto LAB_8009e9d0;
      if (bVar3 != 0x2c) {
        return;
      }
    }
    else {
      if (bVar3 != 0x3c) {
        return;
      }
    }
    Offset = *(short *)(iVar4 + 6) + Offset;
    *(short *)(iVar4 + 6) = Offset;
    Shp->shape = Offset;
    Shp_GetUV(Shp,&local_18,local_16);
    *(ushort *)(iVar4 + 4) =
         local_18 + (*(ushort *)(iVar4 + 4) & 0xff) |
         (local_16[0] + (*(ushort *)(iVar4 + 4) >> 8)) * 0x100;
    *(ushort *)(iVar4 + 8) =
         local_18 + (*(ushort *)(iVar4 + 8) & 0xff) |
         (local_16[0] + (*(ushort *)(iVar4 + 8) >> 8)) * 0x100;
    uVar1 = *(ushort *)(iVar4 + 10);
    *(ushort *)(iVar4 + 0xc) =
         local_18 + (*(ushort *)(iVar4 + 0xc) & 0xff) |
         (local_16[0] + (*(ushort *)(iVar4 + 0xc) >> 8)) * 0x100;
    *(ushort *)(iVar4 + 0x10) =
         local_18 + (*(ushort *)(iVar4 + 0x10) & 0xff) |
         (local_16[0] + (*(ushort *)(iVar4 + 0x10) >> 8)) * 0x100;
  }
  *(ushort *)(iVar4 + 10) = uVar1 & 0xfe60;
  if (Mode != 0) {
    uVar1 = Shp_GetTPage(Shp);
    *(ushort *)(iVar4 + 10) = *(ushort *)(iVar4 + 10) | uVar1 & 0x19f;
    sVar2 = Shp_GetClut(Shp);
    *(short *)(iVar4 + 6) = sVar2;
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Shp_GroupToVram(void *pcl /*$s4*/, short fsize /*$s5*/)
 // line 218, offset 0x8009eb58
	/* begin block 1 */
		// Start line: 219
		// Start offset: 0x8009EB58
		// Variables:
	// 		struct SHAPE_68fake shp; // stack offset -48
	// 		struct SHAPE_71fake *p; // $s2
	// 		long nsize; // $a1
	// 		long size; // $s1
	// 		short i; // $s0
	// 		short j; // $s1
	/* end block 1 */
	// End offset: 0x8009ECD8
	// End Line: 283

	/* begin block 2 */
		// Start line: 549
	/* end block 2 */
	// End Line: 550

long Shp_GroupToVram(void *pcl,short fsize)

{
  long lVar1;
  long lVar2;
  short sVar3;
  uint uVar4;
  ushort uVar5;
  SHAPE_68fake local_30;
  
  if (*(undefined **)pcl == &DAT_00010001) {
    lVar1 = 0;
  }
  else {
    local_30.file = pcl;
    Shp_InitFile(pcl);
    uVar4 = (uint)*(ushort *)((int)pcl + 8);
    *(undefined4 *)pcl = 0x10001;
    uVar5 = 0;
    while (0 < (int)(uVar4 << 0x10)) {
      if ((int)(uVar4 << 0x10) >> 0x10 < 2) {
        lVar1 = TPage_Alloc(1);
        *(undefined2 *)((int)&Shp_TPage + ((int)((uint)uVar5 << 0x10) >> 0xf)) = (short)lVar1;
        uVar4 = uVar4 - 1;
        uVar5 = uVar5 + 1;
      }
      else {
        lVar1 = TPage_Alloc(2);
        uVar4 = uVar4 - 2;
        (&Shp_TPage)[(int)(short)uVar5] = (short)lVar1;
        (&Shp_TPage)[(int)(short)uVar5 + 1] = (short)lVar1 + 1;
        uVar5 = uVar5 + 2;
      }
    }
    sVar3 = 0;
    Shp_Clut = Pal_Alloc(*(short *)((int)pcl + 6));
    lVar1 = 0;
    if (0 < *(short *)((int)pcl + 4)) {
      do {
        local_30.shape = sVar3;
        lVar2 = Shp_ShpToVram(&local_30);
        lVar1 = lVar1 + lVar2;
        sVar3 = sVar3 + 1;
      } while (sVar3 < *(short *)((int)pcl + 4));
    }
    Pal_PalToVram(*(ulong **)((int)pcl + 0xc),Shp_Clut,*(short *)((int)pcl + 6));
    if (fsize != 0) {
      Heap_ResizeMem(pcl,(int)*(short *)((int)pcl + 4) * 0x20 + 0x14);
    }
  }
  return lVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Shp_GroupRelease(void *pcl /*$a0*/, short ffree /*$s3*/)
 // line 291, offset 0x8009ecfc
	/* begin block 1 */
		// Start line: 292
		// Start offset: 0x8009ECFC
		// Variables:
	// 		struct SHAPE_71fake *p; // $s1
	// 		struct SHAPE_70fake *shape; // $s0
	// 		short i; // $s2
	/* end block 1 */
	// End offset: 0x8009ED9C
	// End Line: 310

	/* begin block 2 */
		// Start line: 717
	/* end block 2 */
	// End Line: 718

void Shp_GroupRelease(void *pcl,short ffree)

{
  int iVar1;
  short *psVar2;
  int iVar3;
  
  if (*(undefined **)pcl == &DAT_00010001) {
    iVar3 = 0;
    if (0 < *(short *)((int)pcl + 4)) {
      iVar1 = 0;
      do {
        psVar2 = *(short **)((int)pcl + (iVar1 >> 0xe) + 0x10);
        TPage_Free((int)*psVar2);
        Pal_Free(psVar2[7]);
        iVar3 = iVar3 + 1;
        iVar1 = iVar3 * 0x10000;
      } while (iVar3 * 0x10000 >> 0x10 < (int)*(short *)((int)pcl + 4));
    }
    if (ffree != 0) {
      Heap_FreeMem(pcl);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Shp_ShpToVram(struct SHAPE_68fake *shp /*$a0*/)
 // line 318, offset 0x8009edb8
	/* begin block 1 */
		// Start line: 319
		// Start offset: 0x8009EDB8
		// Variables:
	// 		struct SHAPE_70fake *shape; // $s0
	// 		struct SHAPE_71fake *p; // $v1
	// 		unsigned long *graphs; // $a1
	// 		struct SHAPE_21fake r; // stack offset -32
	// 		short x; // $a0
	// 		short y; // $v1
	// 		short tpage; // $v1
	// 		short mode; // $v0
	// 		long size; // $s3
	/* end block 1 */
	// End offset: 0x8009EF80
	// End Line: 372

	/* begin block 2 */
		// Start line: 782
	/* end block 2 */
	// End Line: 783

/* WARNING: Removing unreachable block (ram,0x8009ef50) */

long Shp_ShpToVram(SHAPE_68fake *shp)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  short *psVar4;
  uint uVar5;
  long lVar6;
  short local_20;
  short local_1e;
  ushort local_1c;
  ushort local_1a;
  
  lVar6 = 0;
  psVar4 = *(short **)((int)shp->file + (int)shp->shape * 4 + 0x10);
  sVar1 = (&Shp_TPage)[(int)psVar4[1]];
  uVar5 = SEXT24(*psVar4);
  *psVar4 = sVar1;
  iVar3 = (int)sVar1;
  uVar2 = GetTPage(uVar5,(uint)*(byte *)(psVar4 + 9),(int)(&TPages)[iVar3].x,(int)(&TPages)[iVar3].y
                  );
  psVar4[1] = (short)uVar2;
  psVar4[7] = psVar4[7] + Shp_Clut;
  if (*(int *)(psVar4 + 10) != 0) {
    sVar1 = (&TPages)[iVar3].x;
    local_1e = psVar4[3] + (&TPages)[iVar3].y;
    local_1a = psVar4[5] + 3U & 0xfffc;
    if (uVar5 == 1) {
      local_20 = sVar1 + (short)((int)(((int)((uint)(ushort)psVar4[2] << 0x10) >> 0x10) +
                                      (((uint)(ushort)psVar4[2] << 0x10) >> 0x1f)) >> 1);
      local_1c = (ushort)((int)((int)psVar4[4] + 3U & 0xfffc) >> 1);
    }
    else {
      if ((int)uVar5 < 2) {
        if (uVar5 == 0) {
          iVar3 = (int)psVar4[2];
          if (iVar3 < 0) {
            iVar3 = iVar3 + 3;
          }
          local_20 = sVar1 + (short)(iVar3 >> 2);
          local_1c = (ushort)((int)((int)psVar4[4] + 3U & 0xfffc) >> 2);
        }
      }
      else {
        if (uVar5 == 2) {
          local_20 = sVar1 + psVar4[2];
          local_1c = psVar4[4] + 3U & 0xfffc;
        }
      }
    }
    LoadImage(&local_20,*(int *)(psVar4 + 10));
    DrawSync();
    lVar6 = (int)(short)local_1c * (int)(short)local_1a * 2;
  }
  return lVar6;
}



// decompiled code
// original method signature: 
// short /*$ra*/ Shp_GetMark(void *file /*$a0*/, long mark /*$a1*/)
 // line 381, offset 0x8009efa0
	/* begin block 1 */
		// Start line: 383
		// Start offset: 0x8009EFA0
		// Variables:
	// 		short i; // $a2
	// 		struct SHAPE_71fake *p; // $a0
	// 		struct SHAPE_70fake *s; // $v0
	/* end block 1 */
	// End offset: 0x8009EFFC
	// End Line: 396

	/* begin block 2 */
		// Start line: 947
	/* end block 2 */
	// End Line: 948

short Shp_GetMark(void *file,long mark)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < (int)*(short *)((int)file + 4)) {
    iVar1 = 0;
    do {
      iVar2 = iVar2 + 1;
      if (*(int *)(*(int *)((int)file + (iVar1 >> 0x10) * 4 + 0x10) + 0x18) == mark) {
        return (short)((uint)iVar1 >> 0x10);
      }
      iVar1 = iVar2 * 0x10000;
    } while (iVar2 * 0x10000 >> 0x10 < (int)*(short *)((int)file + 4));
  }
  return -1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Shp_GetWH(struct SHAPE_68fake *shp /*$a0*/, short *w /*$a1*/, short *h /*$a2*/)
 // line 404, offset 0x8009f004
	/* begin block 1 */
		// Start line: 406
		// Start offset: 0x8009F004
		// Variables:
	// 		struct SHAPE_71fake *p; // $v1
	// 		struct SHAPE_70fake *s; // $v1
	/* end block 1 */
	// End offset: 0x8009F004
	// End Line: 408

	/* begin block 2 */
		// Start line: 996
	/* end block 2 */
	// End Line: 997

void Shp_GetWH(SHAPE_68fake *shp,short *w,short *h)

{
  int iVar1;
  
  iVar1 = *(int *)((int)shp->file + (int)shp->shape * 4 + 0x10);
  *w = *(short *)(iVar1 + 8);
  *h = *(short *)(iVar1 + 10);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Shp_GetUV(struct SHAPE_68fake *shp /*$a0*/, short *u /*$a1*/, short *v /*$a2*/)
 // line 420, offset 0x8009f034
	/* begin block 1 */
		// Start line: 422
		// Start offset: 0x8009F034
		// Variables:
	// 		struct SHAPE_71fake *p; // $v1
	// 		struct SHAPE_70fake *s; // $v1
	/* end block 1 */
	// End offset: 0x8009F034
	// End Line: 424

	/* begin block 2 */
		// Start line: 1029
	/* end block 2 */
	// End Line: 1030

void Shp_GetUV(SHAPE_68fake *shp,short *u,short *v)

{
  int iVar1;
  
  iVar1 = *(int *)((int)shp->file + (int)shp->shape * 4 + 0x10);
  *u = *(short *)(iVar1 + 4);
  *v = *(short *)(iVar1 + 6);
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ Shp_GetPal(struct SHAPE_68fake *shp /*$a0*/)
 // line 436, offset 0x8009f064
	/* begin block 1 */
		// Start line: 438
		// Start offset: 0x8009F064
		// Variables:
	// 		struct SHAPE_71fake *p; // $v1
	// 		struct SHAPE_70fake *s; // $v0
	/* end block 1 */
	// End offset: 0x8009F064
	// End Line: 440

	/* begin block 2 */
		// Start line: 1062
	/* end block 2 */
	// End Line: 1063

short Shp_GetPal(SHAPE_68fake *shp)

{
  return *(short *)(*(int *)((int)shp->file + (int)shp->shape * 4 + 0x10) + 0xe);
}



// decompiled code
// original method signature: 
// short /*$ra*/ Shp_GetTPage(struct SHAPE_68fake *shp /*$a0*/)
 // line 451, offset 0x8009f088
	/* begin block 1 */
		// Start line: 453
		// Start offset: 0x8009F088
		// Variables:
	// 		struct SHAPE_71fake *p; // $v1
	// 		struct SHAPE_70fake *s; // $v0
	/* end block 1 */
	// End offset: 0x8009F088
	// End Line: 455

	/* begin block 2 */
		// Start line: 1093
	/* end block 2 */
	// End Line: 1094

short Shp_GetTPage(SHAPE_68fake *shp)

{
  return *(short *)(*(int *)((int)shp->file + (int)shp->shape * 4 + 0x10) + 2);
}



// decompiled code
// original method signature: 
// short /*$ra*/ Shp_GetMode(struct SHAPE_68fake *shp /*$a0*/)
 // line 466, offset 0x8009f0ac
	/* begin block 1 */
		// Start line: 468
		// Start offset: 0x8009F0AC
		// Variables:
	// 		struct SHAPE_71fake *p; // $v1
	// 		struct SHAPE_70fake *s; // $v0
	/* end block 1 */
	// End offset: 0x8009F0AC
	// End Line: 470

	/* begin block 2 */
		// Start line: 1124
	/* end block 2 */
	// End Line: 1125

short Shp_GetMode(SHAPE_68fake *shp)

{
  return **(short **)((int)shp->file + (int)shp->shape * 4 + 0x10);
}



// decompiled code
// original method signature: 
// short /*$ra*/ Shp_GetClut(struct SHAPE_68fake *shp /*$a0*/)
 // line 481, offset 0x8009f0d0
	/* begin block 1 */
		// Start line: 483
		// Start offset: 0x8009F0D0
		// Variables:
	// 		struct SHAPE_71fake *p; // $v1
	// 		struct SHAPE_70fake *s; // $v0
	/* end block 1 */
	// End offset: 0x8009F0D0
	// End Line: 485

	/* begin block 2 */
		// Start line: 1155
	/* end block 2 */
	// End Line: 1156

short Shp_GetClut(SHAPE_68fake *shp)

{
  return (short)Pals[(int)*(short *)(*(int *)((int)shp->file + (int)shp->shape * 4 + 0x10) + 0xe)].
                clut;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Shp_SetPolyFT4(struct SHAPE_31fake *prim /*$t1*/, struct SHAPE_68fake *shp /*$a1*/, short w /*$a2*/, short h /*$a3*/)
 // line 497, offset 0x8009f104
	/* begin block 1 */
		// Start line: 498
		// Start offset: 0x8009F104
		// Variables:
	// 		long x; // $a0
	// 		long y; // $t2
	// 		struct SHAPE_71fake *p; // $v1
	// 		struct SHAPE_70fake *s; // $t0
	/* end block 1 */
	// End offset: 0x8009F2A8
	// End Line: 519

	/* begin block 2 */
		// Start line: 1189
	/* end block 2 */
	// End Line: 1190

void Shp_SetPolyFT4(SHAPE_31fake *prim,SHAPE_68fake *shp,short w,short h)

{
  char cVar1;
  char cVar2;
  ushort uVar3;
  short sVar4;
  uchar uVar5;
  byte bVar6;
  int iVar7;
  short sVar8;
  int iVar9;
  short sVar10;
  int iVar11;
  
  iVar9 = *(int *)((int)shp->file + (int)shp->shape * 4 + 0x10);
  prim->u0 = *(uchar *)(iVar9 + 4);
  prim->v0 = *(uchar *)(iVar9 + 6);
  cVar1 = *(char *)(iVar9 + 4);
  cVar2 = *(char *)(iVar9 + 8);
  prim->u2 = prim->u0;
  prim->u1 = cVar1 + cVar2 + -1;
  prim->v1 = prim->v0;
  prim->v2 = *(char *)(iVar9 + 6) + *(char *)(iVar9 + 10) + -1;
  prim->u3 = prim->u1;
  prim->v3 = prim->v2;
  sVar8 = 0;
  prim->tpage = *(ushort *)(iVar9 + 2);
  shp->tpage = *(ushort *)(iVar9 + 2);
  uVar3 = Pals[(int)*(short *)(iVar9 + 0xe)].clut;
  *(undefined *)((int)&prim->tag + 3) = 9;
  prim->code = ',';
  prim->clut = uVar3;
  sVar10 = 0;
  if (*(char *)(iVar9 + 0x10) == '\0') {
    uVar5 = ',';
  }
  else {
    uVar5 = '-';
  }
  prim->code = uVar5;
  if (*(char *)(iVar9 + 0x11) == '\0') {
    bVar6 = prim->code & 0xfd;
  }
  else {
    bVar6 = prim->code | 2;
  }
  prim->code = bVar6;
  if ((int)*(char *)(iVar9 + 0xc) != 0) {
    iVar11 = (int)*(char *)(iVar9 + 0xc) * (int)w;
    iVar7 = (int)*(short *)(iVar9 + 8);
    sVar8 = (short)(iVar11 / iVar7);
    if (iVar7 == 0) {
      trap(0x1c00);
    }
    if ((iVar7 == -1) && (iVar11 == -0x80000000)) {
      trap(0x1800);
    }
  }
  if ((int)*(char *)(iVar9 + 0xd) != 0) {
    iVar7 = (int)*(char *)(iVar9 + 0xd) * (int)h;
    iVar9 = (int)*(short *)(iVar9 + 10);
    sVar10 = (short)(iVar7 / iVar9);
    if (iVar9 == 0) {
      trap(0x1c00);
    }
    if ((iVar9 == -1) && (iVar7 == -0x80000000)) {
      trap(0x1800);
    }
  }
  prim->x0 = shp->x + sVar8;
  prim->y0 = shp->y + sVar10;
  sVar4 = shp->x;
  prim->x2 = prim->x0;
  prim->x1 = w + sVar4 + sVar8 + -1;
  prim->y1 = prim->y0;
  prim->y2 = h + shp->y + sVar10 + -1;
  prim->x3 = prim->x1;
  prim->y3 = prim->y2;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Shp_SetXyFT4(struct SHAPE_31fake *prim /*$a0*/, struct SHAPE_68fake *shp /*$a1*/, short w /*$a2*/, short h /*$a3*/)
 // line 523, offset 0x8009f314
	/* begin block 1 */
		// Start line: 525
		// Start offset: 0x8009F314
		// Variables:
	// 		struct SHAPE_71fake *p; // $v1
	// 		struct SHAPE_70fake *s; // $t1
	/* end block 1 */
	// End offset: 0x8009F314
	// End Line: 527

	/* begin block 2 */
		// Start line: 1255
	/* end block 2 */
	// End Line: 1256

void Shp_SetXyFT4(SHAPE_31fake *prim,SHAPE_68fake *shp,short w,short h)

{
  char cVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  
  iVar4 = *(int *)((int)shp->file + (int)shp->shape * 4 + 0x10);
  prim->x0 = shp->x + (short)*(char *)(iVar4 + 0xc);
  prim->y0 = shp->y + (short)*(char *)(iVar4 + 0xd);
  cVar1 = *(char *)(iVar4 + 0xc);
  sVar2 = shp->x;
  prim->x2 = prim->x0;
  sVar2 = w + sVar2 + (short)cVar1 + -1;
  prim->x1 = sVar2;
  prim->y1 = prim->y0;
  sVar3 = h + shp->y + (short)*(char *)(iVar4 + 0xd) + -1;
  prim->y2 = sVar3;
  prim->x3 = sVar2;
  prim->y3 = sVar3;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Shp_SetSprt(struct SHAPE_42fake *prim /*$a0*/, struct SHAPE_68fake *shp /*$a1*/, short scalex /*$a2*/, short scaley /*$a3*/)
 // line 539, offset 0x8009f3c0
	/* begin block 1 */
		// Start line: 541
		// Start offset: 0x8009F3C0
		// Variables:
	// 		struct SHAPE_71fake *p; // $v1
	// 		struct SHAPE_70fake *s; // $a2
	/* end block 1 */
	// End offset: 0x8009F4AC
	// End Line: 558

	/* begin block 2 */
		// Start line: 1288
	/* end block 2 */
	// End Line: 1289

void Shp_SetSprt(SHAPE_42fake *prim,SHAPE_68fake *shp,short scalex,short scaley)

{
  short sVar1;
  uchar uVar2;
  byte bVar3;
  int iVar4;
  
  iVar4 = *(int *)((int)shp->file + (int)shp->shape * 4 + 0x10);
  shp->tpage = *(ushort *)(iVar4 + 2);
  prim->clut = Pals[(int)*(short *)(iVar4 + 0xe)].clut;
  prim->u0 = *(uchar *)(iVar4 + 4);
  prim->v0 = *(uchar *)(iVar4 + 6);
  prim->w = *(short *)(iVar4 + 8);
  sVar1 = *(short *)(iVar4 + 10);
  *(undefined *)((int)&prim->tag + 3) = 4;
  prim->code = 'd';
  prim->h = sVar1;
  uVar2 = 'e';
  if (*(char *)(iVar4 + 0x10) == '\0') {
    uVar2 = 'd';
  }
  prim->code = uVar2;
  if (*(char *)(iVar4 + 0x11) == '\0') {
    bVar3 = prim->code & 0xfd;
  }
  else {
    bVar3 = prim->code | 2;
  }
  prim->code = bVar3;
  prim->x0 = shp->x + (short)*(char *)(iVar4 + 0xc);
  prim->y0 = shp->y + (short)*(char *)(iVar4 + 0xd);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Shp_SetXySprt(struct SHAPE_42fake *prim /*$a0*/, struct SHAPE_68fake *shp /*$a1*/, short scalex /*$a2*/, short scaley /*$a3*/)
 // line 561, offset 0x8009f4b4
	/* begin block 1 */
		// Start line: 563
		// Start offset: 0x8009F4B4
		// Variables:
	// 		struct SHAPE_71fake *p; // $v1
	// 		struct SHAPE_70fake *s; // $a2
	/* end block 1 */
	// End offset: 0x8009F4B4
	// End Line: 565

	/* begin block 2 */
		// Start line: 1336
	/* end block 2 */
	// End Line: 1337

void Shp_SetXySprt(SHAPE_42fake *prim,SHAPE_68fake *shp,short scalex,short scaley)

{
  int iVar1;
  
  iVar1 = *(int *)((int)shp->file + (int)shp->shape * 4 + 0x10);
  prim->x0 = shp->x + (short)*(char *)(iVar1 + 0xc);
  prim->y0 = shp->y + (short)*(char *)(iVar1 + 0xd);
  return;
}





