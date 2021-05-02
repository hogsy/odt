#include "THISDUST.H"
#include "MISC.H"


// decompiled code
// original method signature: 
// void /*$ra*/ OS_Init(TDRFuncPtr_OS_Init0startup startup /*$s0*/)
 // line 28, offset 0x80096950
	/* begin block 1 */
		// Start line: 56
	/* end block 1 */
	// End Line: 57

void OS_Init(TDRFuncPtr_OS_Init0startup startup)

{
  ResetCallback();
  CdInit();
  SpuInit();
  ResetGraph(3);
  InitGeom();
  OS_Install(&Heap_Start);
  (*startup)();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ OS_Install(void *heap /*$s0*/)
 // line 50, offset 0x800969ac
	/* begin block 1 */
		// Start line: 100
	/* end block 1 */
	// End Line: 101

void OS_Install(void *heap)

{
  M_srand(1);
  Heap_Init(heap);
  Task_Init();
  File_Init();
  Joy_Init();
  Card_Init();
  Text_Init();
  Scr_Init();
  TPage_Init();
  Pal_Init();
  Shp_Init();
  Tmd_Init();
  Motion_Init();
  Sound_Init(Sound_Mode);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ OS_Remove()
 // line 80, offset 0x80096a44
	/* begin block 1 */
		// Start line: 81
		// Start offset: 0x80096A44
	/* end block 1 */
	// End offset: 0x80096A44
	// End Line: 81

	/* begin block 2 */
		// Start line: 160
	/* end block 2 */
	// End Line: 161

/* WARNING: Unknown calling convention yet parameter storage is locked */

void OS_Remove(void)

{
  Scr_Remove();
  Tmd_FreeMem();
  Text_FreeMem();
  StopTAP();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ OS_Stop()
 // line 90, offset 0x80096a7c
	/* begin block 1 */
		// Start line: 91
		// Start offset: 0x80096A7C
	/* end block 1 */
	// End offset: 0x80096A7C
	// End Line: 91

	/* begin block 2 */
		// Start line: 180
	/* end block 2 */
	// End Line: 181

/* WARNING: Unknown calling convention yet parameter storage is locked */

void OS_Stop(void)

{
  Scr_Stop();
  DrawSync();
  StopRCnt(0xf2000000);
  StopRCnt(0xf2000001);
  StopRCnt(0xf2000002);
  StopRCnt(0xf2000003);
  SpuQuit();
  StopTAP();
  StopCallback();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ OS_Start()
 // line 109, offset 0x80096ae8
	/* begin block 1 */
		// Start line: 110
		// Start offset: 0x80096AE8
	/* end block 1 */
	// End offset: 0x80096AE8
	// End Line: 110

	/* begin block 2 */
		// Start line: 218
	/* end block 2 */
	// End Line: 219

/* WARNING: Unknown calling convention yet parameter storage is locked */

void OS_Start(void)

{
  ResetCallback();
  CdInit();
  SpuInit();
  ResetGraph(3);
  StartTAP();
  Scr_Start();
  Sound_Start();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ M_srand(long n /*$a0*/)
 // line 130, offset 0x80096b38
	/* begin block 1 */
		// Start line: 261
	/* end block 1 */
	// End Line: 262

void M_srand(long n)

{
  M_seed = n;
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ M_rand()
 // line 136, offset 0x80096b44
	/* begin block 1 */
		// Start line: 273
	/* end block 1 */
	// End Line: 274

/* WARNING: Unknown calling convention yet parameter storage is locked */

long M_rand(void)

{
  M_seed = M_seed * 0x41c64e6d + 0x3039;
  return M_seed >> 0x10 & 0x7fff;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Direction(long vx /*$s0*/, long vy /*$s1*/)
 // line 149, offset 0x80096b6c
	/* begin block 1 */
		// Start line: 150
		// Start offset: 0x80096B6C
		// Variables:
	// 		struct MISC_6fake v; // stack offset -32
	// 		long h; // $a0
	// 		long cos; // $s0
	// 		long sin; // $s1
	// 		long vz; // $v1
	/* end block 1 */
	// End offset: 0x80096CE4
	// End Line: 204

	/* begin block 2 */
		// Start line: 298
	/* end block 2 */
	// End Line: 299

long Direction(long vx,long vy)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 in_t1;
  undefined4 in_t2;
  undefined4 in_t3;
  int iVar4;
  double __z;
  int iVar5;
  int iVar6;
  undefined4 local_18;
  
  setCopReg(2,in_t1,vx);
  setCopReg(2,in_t2,vy);
  setCopReg(2,in_t3,local_18);
  copFunction(2,0xa00428);
  iVar2 = getCopReg(2,0x19);
  iVar5 = getCopReg(2,0x1a);
  getCopReg(2,0x1b);
  uVar1 = SquareRoot0(iVar2 + iVar5);
  iVar2 = uVar1 << 6;
  if (iVar2 < 1) {
    iVar2 = -1;
  }
  else {
    iVar5 = (vx << 0xc) / iVar2;
    if (iVar2 == 0) {
      trap(0x1c00);
    }
    if ((iVar2 == -1) && (vx << 0xc == -0x80000000)) {
      trap(0x1800);
    }
    iVar6 = (vy << 0xc) / iVar2;
    if (iVar2 == 0) {
      trap(0x1c00);
    }
    if ((iVar2 == -1) && (vy << 0xc == -0x80000000)) {
      trap(0x1800);
    }
    iVar4 = iVar5 * 0x40;
    uVar1 = iVar6 * 0x40;
    if (iVar4 == 0) {
      iVar2 = 0xc00;
      if (0 < (int)uVar1) {
        iVar2 = 0x400;
      }
    }
    else {
      if (uVar1 == 0) {
        iVar2 = (uint)(iVar4 < 1) << 0xb;
      }
      else {
        uVar3 = uVar1;
        if ((int)uVar1 < 0) {
          uVar3 = iVar6 * -0x40;
        }
        iVar2 = iVar4;
        if (iVar4 < 0) {
          iVar2 = iVar5 * -0x40;
        }
        if (iVar2 == 0) {
          trap(0x1c00);
        }
        if ((iVar2 == -1) && ((uVar3 & 0xfffff) == 0x80000)) {
          trap(0x1800);
        }
        catan(__z);
        if ((int)uVar1 < 1) {
          if (iVar4 < 0) {
            iVar2 = iVar2 + 0x800;
          }
          else {
            iVar2 = 0x1000 - iVar2;
          }
        }
        else {
          if (iVar4 < 0) {
            iVar2 = 0x800 - iVar2;
          }
        }
      }
    }
  }
  return iVar2;
}



// decompiled code
// original method signature: 
// long /*$ra*/ DirectionZ(long dx /*$a0*/, long dy /*$a1*/, long dz /*$s0*/)
 // line 207, offset 0x80096cf8
	/* begin block 1 */
		// Start line: 208
		// Start offset: 0x80096CF8
	/* end block 1 */
	// End offset: 0x80096CF8
	// End Line: 208

	/* begin block 2 */
		// Start line: 428
	/* end block 2 */
	// End Line: 429

long DirectionZ(long dx,long dy,long dz)

{
  uint vx;
  long lVar1;
  
  vx = SquareRoot0(dx * dx + dy * dy);
  lVar1 = Direction(vx,dz);
  return lVar1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ DeltaDirection(long d1 /*$a0*/, long d2 /*$a1*/)
 // line 218, offset 0x80096d44
	/* begin block 1 */
		// Start line: 220
		// Start offset: 0x80096D44
		// Variables:
	// 		long dd; // $a0
	/* end block 1 */
	// End offset: 0x80096D68
	// End Line: 230

	/* begin block 2 */
		// Start line: 453
	/* end block 2 */
	// End Line: 454

long DeltaDirection(long d1,long d2)

{
  d1 = d1 - d2;
  if (0x800 < d1) {
    d1 = d1 + -0x1000;
  }
  if (d1 < -0x800) {
    d1 = d1 + 0x1000;
  }
  return d1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Distance3D(long x1 /*$a0*/, long y1 /*$a1*/, long z1 /*$a2*/, long x2 /*$a3*/, long y2 /*stack 16*/, long z2 /*stack 20*/)
 // line 234, offset 0x80096d70
	/* begin block 1 */
		// Start line: 235
		// Start offset: 0x80096D70
		// Variables:
	// 		struct MISC_6fake v; // stack offset -24
	/* end block 1 */
	// End offset: 0x80096D70
	// End Line: 235

	/* begin block 2 */
		// Start line: 482
	/* end block 2 */
	// End Line: 483

long Distance3D(long x1,long y1,long z1,long x2,long y2,long z2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 in_t1;
  undefined4 in_t2;
  undefined4 in_t3;
  
  setCopReg(2,in_t1,x1 - x2);
  setCopReg(2,in_t2,y1 - y2);
  setCopReg(2,in_t3,z1 - z2);
  copFunction(2,0xa00428);
  iVar1 = getCopReg(2,0x19);
  iVar2 = getCopReg(2,0x1a);
  iVar3 = getCopReg(2,0x1b);
  uVar4 = SquareRoot0(iVar1 + iVar2 + iVar3);
  return uVar4;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Distance2D(long x1 /*$a0*/, long y1 /*$a1*/, long x2 /*$a2*/, long y2 /*$a3*/)
 // line 247, offset 0x80096de8
	/* begin block 1 */
		// Start line: 248
		// Start offset: 0x80096DE8
		// Variables:
	// 		struct MISC_6fake v; // stack offset -24
	/* end block 1 */
	// End offset: 0x80096DE8
	// End Line: 248

	/* begin block 2 */
		// Start line: 514
	/* end block 2 */
	// End Line: 515

long Distance2D(long x1,long y1,long x2,long y2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 in_t1;
  undefined4 in_t2;
  undefined4 in_t3;
  
  setCopReg(2,in_t1,x1 - x2);
  setCopReg(2,in_t2,y1 - y2);
  setCopReg(2,in_t3,0);
  copFunction(2,0xa00428);
  iVar1 = getCopReg(2,0x19);
  iVar2 = getCopReg(2,0x1a);
  getCopReg(2,0x1b);
  uVar3 = SquareRoot0(iVar1 + iVar2);
  return uVar3;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Matrix_Clear(struct MISC_5fake *mat /*$a0*/)
 // line 261, offset 0x80096e4c
	/* begin block 1 */
		// Start line: 263
		// Start offset: 0x80096E4C
		// Variables:
	// 		short *m; // $a0
	// 		long i; // $v0
	/* end block 1 */
	// End offset: 0x80096E60
	// End Line: 268

	/* begin block 2 */
		// Start line: 553
	/* end block 2 */
	// End Line: 554

void Matrix_Clear(MISC_5fake *mat)

{
  int iVar1;
  
  iVar1 = 8;
  do {
    mat->m[0] = 0;
    iVar1 = iVar1 + -1;
    mat = (MISC_5fake *)(mat->m + 1);
  } while (-1 < iVar1);
  return;
}





