#include "THISDUST.H"
#include "PALETTE.H"


// decompiled code
// original method signature: 
// void /*$ra*/ Pal_Init()
 // line 21, offset 0x8009f500
	/* begin block 1 */
		// Start line: 42
	/* end block 1 */
	// End Line: 43

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pal_Init(void)

{
  Pal_InitZone(0,0x1e0,0x200,0x20);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pal_InitZone(short x /*$a0*/, short y /*$a1*/, short w /*$a2*/, short h /*$a3*/)
 // line 32, offset 0x8009f52c
	/* begin block 1 */
		// Start line: 33
		// Start offset: 0x8009F52C
		// Variables:
	// 		long i; // $s1
	// 		long x1; // $a0
	// 		long y1; // $a1
	/* end block 1 */
	// End offset: 0x8009F5FC
	// End Line: 57

	/* begin block 2 */
		// Start line: 65
	/* end block 2 */
	// End Line: 66

void Pal_InitZone(short x,short y,short w,short h)

{
  long lVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  PALETTE_100fake *pPVar7;
  
  iVar2 = (int)w;
  iVar3 = iVar2;
  if (iVar2 < 0) {
    iVar3 = iVar2 + 0xff;
  }
  nPals = (iVar3 >> 8) * (int)h;
  iVar3 = 0;
  if (0 < nPals) {
    pPVar7 = Pals;
    do {
      iVar5 = iVar3 << 8;
      if (iVar2 == 0) {
        trap(0x1c00);
      }
      if ((iVar2 == -1) && (iVar5 == -0x80000000)) {
        trap(0x1800);
      }
      iVar4 = (int)x + iVar5 % iVar2;
      uVar6 = (int)y + iVar5 / iVar2;
      pPVar7->x = (short)iVar4;
      pPVar7->y = (short)uVar6;
      uVar6 = GetClut(iVar4,uVar6);
      pPVar7->clut = (ushort)uVar6;
      lVar1 = nPals;
      iVar3 = iVar3 + 1;
      pPVar7->used = 0;
      pPVar7 = pPVar7 + 1;
    } while (iVar3 < lVar1);
  }
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ Pal_Alloc(short n /*$t5*/)
 // line 65, offset 0x8009f61c
	/* begin block 1 */
		// Start line: 66
		// Start offset: 0x8009F61C
		// Variables:
	// 		short i; // $t1
	// 		short j; // $a1
	// 		short used; // $a2
	/* end block 1 */
	// End offset: 0x8009F71C
	// End Line: 87

	/* begin block 2 */
		// Start line: 152
	/* end block 2 */
	// End Line: 153

short Pal_Alloc(short n)

{
  int iVar1;
  short sVar2;
  int iVar3;
  short sVar4;
  short sVar5;
  int iVar6;
  
  iVar6 = 0;
  iVar3 = (int)n;
  sVar5 = 0;
  if (0 < nPals - iVar3) {
    do {
      sVar5 = (short)iVar6;
      sVar4 = 0;
      if (0 < iVar3) {
        sVar2 = sVar4;
        do {
          iVar1 = (int)sVar2;
          sVar2 = sVar2 + 1;
          sVar4 = sVar4 + Pals[(int)sVar5 + iVar1].used;
        } while ((int)sVar2 < iVar3);
      }
      iVar6 = iVar6 + 1;
    } while ((sVar4 != 0) && (sVar5 = (short)iVar6, iVar6 * 0x10000 >> 0x10 < nPals - iVar3));
  }
  iVar6 = 0;
  if (0 < (int)n) {
    do {
      Pals[(int)sVar5 + (int)(short)iVar6].used = 1;
      iVar6 = iVar6 + 1;
    } while (iVar6 * 0x10000 >> 0x10 < (int)n);
  }
  return sVar5;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pal_Free(short i /*$a0*/)
 // line 96, offset 0x8009f728
	/* begin block 1 */
		// Start line: 224
	/* end block 1 */
	// End Line: 225

void Pal_Free(short i)

{
  *(undefined2 *)((int)&Pals[0].used + ((int)((uint)(ushort)i << 0x10) >> 0xd)) = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pal_PalToVram(unsigned long *source /*$s0*/, short dest /*$a1*/, short n /*$a2*/)
 // line 111, offset 0x8009f744
	/* begin block 1 */
		// Start line: 112
		// Start offset: 0x8009F744
		// Variables:
	// 		short i; // $s1
	/* end block 1 */
	// End offset: 0x8009F7C8
	// End Line: 117

	/* begin block 2 */
		// Start line: 253
	/* end block 2 */
	// End Line: 254

void Pal_PalToVram(ulong *source,short dest,short n)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < (int)n) {
    do {
      iVar1 = (int)dest + (int)(short)iVar2;
      LoadClut(source,(int)Pals[iVar1].x,(int)Pals[iVar1].y);
      iVar2 = iVar2 + 1;
      source = source + 0x80;
    } while (iVar2 * 0x10000 >> 0x10 < (int)n);
  }
  return;
}





