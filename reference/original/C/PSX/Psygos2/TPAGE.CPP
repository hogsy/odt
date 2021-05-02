#include "THISDUST.H"
#include "TPAGE.H"


// decompiled code
// original method signature: 
// void /*$ra*/ TPage_Init()
 // line 19, offset 0x8009f7e8
	/* begin block 1 */
		// Start line: 38
	/* end block 1 */
	// End Line: 39

/* WARNING: Unknown calling convention yet parameter storage is locked */

void TPage_Init(void)

{
  TPage_InitZone(0x140,0,0x2c0,0x200);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ TPage_InitZone(long x /*$a0*/, long y /*$a1*/, long w /*$a2*/, long h /*$a3*/)
 // line 30, offset 0x8009f814
	/* begin block 1 */
		// Start line: 31
		// Start offset: 0x8009F814
		// Variables:
	// 		long i; // $a3
	// 		long x1; // $t0
	// 		long y1; // $a1
	// 		long n; // $t1
	/* end block 1 */
	// End offset: 0x8009F8A4
	// End Line: 61

	/* begin block 2 */
		// Start line: 62
	/* end block 2 */
	// End Line: 63

void TPage_InitZone(long x,long y,long w,long h)

{
  long lVar1;
  TPAGE_99fake *pTVar2;
  int iVar3;
  int iVar4;
  
  lVar1 = w;
  if (w < 0) {
    lVar1 = w + 0x3f;
  }
  if (h < 0) {
    h = h + 0xff;
  }
  iVar4 = (lVar1 >> 6) * (h >> 8);
  TPage_N = 0;
  iVar3 = 0;
  if (0 < iVar4) {
    pTVar2 = &TPages;
    lVar1 = x;
    do {
      pTVar2->x = (short)lVar1;
      lVar1 = lVar1 + 0x40;
      pTVar2->y = (short)y;
      pTVar2->n = 1;
      pTVar2->used = 0;
      if (lVar1 < x + w) {
        pTVar2->extreme = 0;
      }
      else {
        pTVar2->extreme = 1;
        y = y + 0x100;
        lVar1 = x;
      }
      iVar3 = iVar3 + 1;
      TPage_N = TPage_N + 1;
      pTVar2 = pTVar2 + 1;
    } while (iVar3 < iVar4);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ TPage_ClearAll()
 // line 69, offset 0x8009f8ac
	/* begin block 1 */
		// Start line: 70
		// Start offset: 0x8009F8AC
		// Variables:
	// 		long i; // $s0
	/* end block 1 */
	// End offset: 0x8009F8E0
	// End Line: 79

	/* begin block 2 */
		// Start line: 192
	/* end block 2 */
	// End Line: 193

/* WARNING: Unknown calling convention yet parameter storage is locked */

void TPage_ClearAll(void)

{
  int n;
  
  n = 0;
  if (0 < TPage_N) {
    do {
      TPage_Clear(n);
      n = n + 1;
    } while (n < (int)TPage_N);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ TPage_Clear(long n /*$a0*/)
 // line 87, offset 0x8009f8f0
	/* begin block 1 */
		// Start line: 89
		// Start offset: 0x8009F8F0
		// Variables:
	// 		long i; // $a1
	/* end block 1 */
	// End offset: 0x8009F94C
	// End Line: 97

	/* begin block 2 */
		// Start line: 232
	/* end block 2 */
	// End Line: 233

void TPage_Clear(long n)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = n;
  if (0 < (&TPages)[n].n) {
    do {
      (&TPages)[iVar1].used = 0;
      iVar2 = iVar2 + 1;
      iVar1 = n + iVar2;
    } while (iVar2 < (int)(&TPages)[n].n);
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ TPage_Alloc(long n /*$a0*/)
 // line 106, offset 0x8009f954
	/* begin block 1 */
		// Start line: 107
		// Start offset: 0x8009F954
		// Variables:
	// 		long i; // $a1
	// 		long j; // $a3
	// 		long used; // $a2
	/* end block 1 */
	// End offset: 0x8009F9EC
	// End Line: 128

	/* begin block 2 */
		// Start line: 268
	/* end block 2 */
	// End Line: 269

long TPage_Alloc(long n)

{
  int iVar1;
  long t;
  int iVar2;
  int iVar3;
  
  t = 0;
  if (0 < (int)TPage_N - n) {
    do {
      iVar2 = 0;
      iVar1 = t;
      iVar3 = iVar2;
      if (0 < n) {
        do {
          iVar2 = iVar2 + (int)(&TPages)[iVar1].used;
          if (iVar3 < n + -1) {
            iVar2 = iVar2 + (int)(&TPages)[iVar1].extreme;
          }
          iVar3 = iVar3 + 1;
          iVar1 = t + iVar3;
        } while (iVar3 < n);
      }
    } while ((iVar2 != 0) && (t = t + 1, t < (int)TPage_N - n));
  }
  t = TPage_AllocAt(n,t);
  return t;
}



// decompiled code
// original method signature: 
// long /*$ra*/ TPage_AllocAt(long n /*$a3*/, long t /*$a1*/)
 // line 132, offset 0x8009fa04
	/* begin block 1 */
		// Start line: 133
		// Start offset: 0x8009FA04
		// Variables:
	// 		long i; // $a2
	/* end block 1 */
	// End offset: 0x8009FA4C
	// End Line: 147

	/* begin block 2 */
		// Start line: 337
	/* end block 2 */
	// End Line: 338

long TPage_AllocAt(long n,long t)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = t;
  if (0 < n) {
    do {
      sVar1 = (short)iVar3;
      iVar3 = iVar3 + 1;
      (&TPages)[iVar2].used = 1;
      (&TPages)[iVar2].n = (short)n - sVar1;
      iVar2 = t + iVar3;
    } while (iVar3 < n);
  }
  return t;
}



// decompiled code
// original method signature: 
// void /*$ra*/ TPage_Free(long i /*$a0*/)
 // line 156, offset 0x8009fa54
	/* begin block 1 */
		// Start line: 158
		// Start offset: 0x8009FA54
		// Variables:
	// 		long j; // $a1
	// 		long n; // $a2
	/* end block 1 */
	// End offset: 0x8009FAB0
	// End Line: 171

	/* begin block 2 */
		// Start line: 394
	/* end block 2 */
	// End Line: 395

void TPage_Free(long i)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  if ((&TPages)[i].used != 0) {
    sVar1 = (&TPages)[i].n;
    iVar3 = 0;
    if (0 < (int)sVar1) {
      do {
        iVar2 = i + iVar3;
        iVar3 = iVar3 + 1;
        (&TPages)[iVar2].used = 0;
      } while (iVar3 < (int)sVar1);
    }
  }
  return;
}





