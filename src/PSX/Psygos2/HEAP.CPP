#include "THISDUST.H"
#include "HEAP.H"


// decompiled code
// original method signature: 
// void /*$ra*/ Heap_Init(void *start /*$a0*/)
 // line 27, offset 0x8009a754
	/* begin block 1 */
		// Start line: 29
		// Start offset: 0x8009A754
		// Variables:
	// 		unsigned long si; // $v0
	/* end block 1 */
	// End offset: 0x8009A754
	// End Line: 37

	/* begin block 2 */
		// Start line: 63
	/* end block 2 */
	// End Line: 64

void Heap_Init(void *start)

{
  int iVar1;
  
  CLV_TotalMem = 0x801ffa00 - (int)start;
  iVar1 = (int)start + CLV_TotalMem;
  *(undefined4 *)(iVar1 + -0x10) = 0;
  CLV_SelectedMem = 0;
  CLV_GlobalMem = 0;
  CLV_NbAlloc = 0;
  CLV_UsedMem = 0;
  CLV_LastAlloc = (MemDefstruct *)(iVar1 + -0x10);
  CLV_BasePtr = (uchar *)start;
  *(undefined4 *)(iVar1 + -8) = 0;
  *(undefined4 *)(iVar1 + -4) = 0;
  CLV_FirstAlloc = (MemDefstruct *)start;
  *(undefined4 *)start = 0;
  *(undefined4 *)((int)start + 8) = 0;
  *(undefined4 *)((int)start + 0xc) = 1;
  *(void **)(iVar1 + -0xc) = start;
  *(MemDefstruct **)((int)start + 4) = (MemDefstruct *)(iVar1 + -0x10);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Heap_MaxBlock()
 // line 66, offset 0x8009a7b0
	/* begin block 1 */
		// Start line: 68
		// Start offset: 0x8009A7B0
		// Variables:
	// 		struct MemDefstruct *ptr; // $a1
	// 		long size; // $a3
	// 		long free; // $a0
	/* end block 1 */
	// End offset: 0x8009A878
	// End Line: 114

	/* begin block 2 */
		// Start line: 152
	/* end block 2 */
	// End Line: 153

/* WARNING: Unknown calling convention yet parameter storage is locked */

long Heap_MaxBlock(void)

{
  int iVar1;
  MemDefstruct *pMVar2;
  MemDefstruct *pMVar3;
  int iVar4;
  
  pMVar2 = CLV_FirstAlloc;
  iVar4 = 0;
  while( true ) {
    pMVar3 = pMVar2->Next;
    if (pMVar3->Flags == 0) break;
    iVar1 = (int)pMVar3 + (-pMVar2->Size - (int)pMVar2) + -0x10;
    pMVar2 = pMVar3;
    if (iVar4 < iVar1) {
      pMVar2 = pMVar3;
      iVar4 = iVar1;
    }
  }
  iVar1 = ((CLV_TotalMem - ((int)pMVar2 + (pMVar2->Size - (int)CLV_FirstAlloc) + 0x10)) -
          (int)((int)CLV_LastAlloc - (int)pMVar2->Next)) + -0x10;
  pMVar2 = CLV_LastAlloc;
  if (iVar4 < iVar1) {
    pMVar2 = CLV_LastAlloc;
    iVar4 = iVar1;
  }
  while( true ) {
    pMVar3 = pMVar2->Next;
    if (pMVar3->Flags == 1) break;
    iVar1 = (int)pMVar2 + (-pMVar3->Size - (int)pMVar3) + -0x10;
    pMVar2 = pMVar3;
    if (iVar4 < iVar1) {
      pMVar2 = pMVar3;
      iVar4 = iVar1;
    }
  }
  return iVar4;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Heap_MaxMem()
 // line 123, offset 0x8009a880
	/* begin block 1 */
		// Start line: 125
		// Start offset: 0x8009A880
		// Variables:
	// 		struct MemDefstruct *ptr; // $a1
	// 		long size; // $a0
	/* end block 1 */
	// End offset: 0x8009A904
	// End Line: 149

	/* begin block 2 */
		// Start line: 283
	/* end block 2 */
	// End Line: 284

/* WARNING: Unknown calling convention yet parameter storage is locked */

long Heap_MaxMem(void)

{
  ulong uVar1;
  int iVar2;
  MemDefstruct *pMVar3;
  
  uVar1 = CLV_FirstAlloc->Next->Flags;
  iVar2 = CLV_FirstAlloc->Size + 0x10;
  pMVar3 = CLV_FirstAlloc;
  while (uVar1 != 0) {
    pMVar3 = pMVar3->Next;
    uVar1 = pMVar3->Next->Flags;
    iVar2 = iVar2 + 0x10 + pMVar3->Size;
  }
  iVar2 = iVar2 + 0x10 + CLV_LastAlloc->Size;
  uVar1 = CLV_LastAlloc->Next->Flags;
  pMVar3 = CLV_LastAlloc;
  while (uVar1 != 1) {
    pMVar3 = pMVar3->Next;
    uVar1 = pMVar3->Next->Flags;
    iVar2 = iVar2 + 0x10 + pMVar3->Size;
  }
  return CLV_TotalMem - iVar2;
}



// decompiled code
// original method signature: 
// void * /*$ra*/ Heap_AllocMem(unsigned long size /*$a0*/)
 // line 159, offset 0x8009a910
	/* begin block 1 */
		// Start line: 161
		// Start offset: 0x8009A910
		// Variables:
	// 		struct MemDefstruct *ptr; // $a1
	// 		struct MemDefstruct *ptrn; // $v1
	// 		struct MemDefstruct *ptr2; // $v0
	// 		long free; // $v0
	/* end block 1 */
	// End offset: 0x8009A9E8
	// End Line: 209

	/* begin block 2 */
		// Start line: 367
	/* end block 2 */
	// End Line: 368

void * Heap_AllocMem(ulong size)

{
  MemDefstruct *pMVar1;
  int iVar2;
  MemDefstruct *pMVar3;
  ulong uVar4;
  MemDefstruct *pMVar5;
  uint uVar6;
  
  uVar6 = size + 3 & 0xfffffffc;
  CLV_UsedMem = CLV_UsedMem + 0x10 + uVar6;
  uVar4 = CLV_FirstAlloc->Next->Flags;
  CLV_NbAlloc = CLV_NbAlloc + 1;
  pMVar1 = CLV_FirstAlloc;
  do {
    if (uVar4 == 0) {
      iVar2 = (int)&pMVar1->Size + pMVar1->Size;
      pMVar5 = (MemDefstruct *)(iVar2 + 0x10);
      *(uint *)(iVar2 + 0x10) = uVar6;
      *(undefined4 *)(iVar2 + 0x1c) = 1;
      pMVar3 = pMVar1->Next;
      *(MemDefstruct **)(iVar2 + 0x18) = pMVar1;
      *(MemDefstruct **)(iVar2 + 0x14) = pMVar3;
      pMVar3->Next = pMVar5;
LAB_8009a9e4:
      pMVar1->Next = pMVar5;
      return pMVar5 + 1;
    }
    pMVar3 = pMVar1->Next;
    iVar2 = (int)&pMVar1->Size + pMVar1->Size;
    if ((int)(uVar6 + 0x10) <= (int)((int)pMVar3 + (-pMVar1->Size - (int)pMVar1) + -0x10)) {
      pMVar5 = (MemDefstruct *)(iVar2 + 0x10);
      *(uint *)(iVar2 + 0x10) = uVar6;
      *(undefined4 *)(iVar2 + 0x1c) = 1;
      pMVar3 = pMVar1->Next;
      *(MemDefstruct **)(iVar2 + 0x14) = pMVar3;
      pMVar3->Last = pMVar5;
      *(MemDefstruct **)(iVar2 + 0x18) = pMVar1;
      goto LAB_8009a9e4;
    }
    uVar4 = pMVar3->Next->Flags;
    pMVar1 = pMVar3;
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Heap_FreeMem(void *ptt /*$a0*/)
 // line 218, offset 0x8009a9f0
	/* begin block 1 */
		// Start line: 219
		// Start offset: 0x8009A9F0
		// Variables:
	// 		struct MemDefstruct *ptr; // $a1
	// 		struct MemDefstruct *ptrn; // $v1
	// 		void *pt; // $a2

		/* begin block 1.1 */
			// Start line: 257
			// Start offset: 0x8009AA80
		/* end block 1.1 */
		// End offset: 0x8009AA90
		// End Line: 259
	/* end block 1 */
	// End offset: 0x8009AAA0
	// End Line: 263

	/* begin block 2 */
		// Start line: 527
	/* end block 2 */
	// End Line: 528

void Heap_FreeMem(void *ptt)

{
  MemDefstruct *pMVar1;
  MemDefstruct *pMVar2;
  
  CLV_UsedMem = (CLV_UsedMem - 0x10) - ((MemDefstruct *)((int)ptt + -0x10))->Size;
  CLV_NbAlloc = CLV_NbAlloc + -1;
  pMVar2 = CLV_FirstAlloc;
  do {
    if ((MemDefstruct *)((int)ptt + -0x10) == pMVar2) {
      pMVar2->Last->Next = pMVar2->Next;
      pMVar1 = pMVar2->Next;
      if (pMVar1->Flags == 0) {
        pMVar1->Next = pMVar2->Last;
      }
      else {
        pMVar1->Last = pMVar2->Last;
      }
      CLV_NbAlloc = CLV_NbAlloc + -1;
      return;
    }
    pMVar2 = pMVar2->Next;
  } while (pMVar2->Flags != 0);
  ErrorMaster();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Heap_ResizeMem(void *ptt /*$a0*/, long si /*$a1*/)
 // line 271, offset 0x8009aab0
	/* begin block 1 */
		// Start line: 272
		// Start offset: 0x8009AAB0
		// Variables:
	// 		unsigned long ls; // $a2
	/* end block 1 */
	// End offset: 0x8009AB2C
	// End Line: 296

	/* begin block 2 */
		// Start line: 649
	/* end block 2 */
	// End Line: 650

void Heap_ResizeMem(void *ptt,long si)

{
  uint uVar1;
  
  if (si == 0) {
    Heap_FreeMem(ptt);
  }
  else {
    uVar1 = *(uint *)((int)ptt + -0x10);
    if (-1 < si) {
      si = si + 3U & 0xfffffffc;
      if (-1 < si) {
        if ((uint)si <= uVar1) {
          *(uint *)((int)ptt + -0x10) = si;
          CLV_UsedMem = CLV_UsedMem - (uVar1 - si);
          return;
        }
        ErrorMaster();
        return;
      }
    }
    *(int *)((int)ptt + -0x10) = uVar1 + si;
    CLV_UsedMem = CLV_UsedMem + si;
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Heap_GetSize(void *ptt /*$a0*/)
 // line 304, offset 0x8009ab3c
	/* begin block 1 */
		// Start line: 306
		// Start offset: 0x8009AB3C
	/* end block 1 */
	// End offset: 0x8009AB3C
	// End Line: 310

	/* begin block 2 */
		// Start line: 720
	/* end block 2 */
	// End Line: 721

long Heap_GetSize(void *ptt)

{
  return *(long *)((int)ptt + -0x10);
}





