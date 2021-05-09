#include "THISDUST.H"
#include "TMD.H"


// decompiled code
// original method signature: 
// void /*$ra*/ Tmd_Init()
 // line 22, offset 0x8009e240
	/* begin block 1 */
		// Start line: 46
	/* end block 1 */
	// End Line: 47

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Tmd_Init(void)

{
  Tmd_2D = (_TMD_2D *)0x0;
  Tmd_2DSpeed = (_TMD_2D *)&DAT_1f800000;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Tmd_InitFile(struct TMD_72fake *Tmd /*$a0*/)
 // line 29, offset 0x8009e254
	/* begin block 1 */
		// Start line: 30
		// Start offset: 0x8009E254
	/* end block 1 */
	// End offset: 0x8009E254
	// End Line: 30

	/* begin block 2 */
		// Start line: 59
	/* end block 2 */
	// End Line: 60

void Tmd_InitFile(TMD_72fake *Tmd)

{
  GsMapModelingData(&Tmd->Flags);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Tmd_AllocMem(long nVertices /*$s0*/)
 // line 35, offset 0x8009e274
	/* begin block 1 */
		// Start line: 71
	/* end block 1 */
	// End Line: 72

void Tmd_AllocMem(long nVertices)

{
  if (Tmd_2D != (_TMD_2D *)0x0) {
    Heap_FreeMem(Tmd_2D);
  }
  Tmd_2D = (_TMD_2D *)Heap_AllocMem(nVertices << 4);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Tmd_FreeMem()
 // line 44, offset 0x8009e2b4
	/* begin block 1 */
		// Start line: 90
	/* end block 1 */
	// End Line: 91

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Tmd_FreeMem(void)

{
  if (Tmd_2D != (_TMD_2D *)0x0) {
    Heap_FreeMem(Tmd_2D);
  }
  Tmd_2D = (_TMD_2D *)0x0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Tmd_ForceSemiTrans(struct TMD_91fake *Tmd /*$a0*/)
 // line 53, offset 0x8009e2dc
	/* begin block 1 */
		// Start line: 55
		// Start offset: 0x8009E2DC
		// Variables:
	// 		long i; // $a1
	// 		long nPrims; // $a2
	// 		struct TMD_90fake *pPrim; // $a0
	/* end block 1 */
	// End offset: 0x8009E314
	// End Line: 60

	/* begin block 2 */
		// Start line: 109
	/* end block 2 */
	// End Line: 110

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Tmd_ForceSemiTrans(undefined Tmd)

{
  undefined3 in_register_00000011;
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(CONCAT31(in_register_00000011,Tmd) + 0x14);
  iVar1 = *(int *)(CONCAT31(in_register_00000011,Tmd) + 0x10);
  iVar2 = 0;
  if (0 < iVar3) {
    do {
      iVar2 = iVar2 + 1;
      *(byte *)(iVar1 + 3) = *(byte *)(iVar1 + 3) | 2;
      iVar1 = iVar1 + (uint)*(byte *)(iVar1 + 1) * 4 + 4;
    } while (iVar2 < iVar3);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Tmd_ForceSolid(struct TMD_91fake *Tmd /*$a0*/)
 // line 63, offset 0x8009e31c
	/* begin block 1 */
		// Start line: 65
		// Start offset: 0x8009E31C
		// Variables:
	// 		long i; // $a1
	// 		long nPrims; // $a2
	// 		struct TMD_90fake *pPrim; // $a0
	/* end block 1 */
	// End offset: 0x8009E354
	// End Line: 70

	/* begin block 2 */
		// Start line: 132
	/* end block 2 */
	// End Line: 133

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Tmd_ForceSolid(undefined Tmd)

{
  undefined3 in_register_00000011;
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(CONCAT31(in_register_00000011,Tmd) + 0x14);
  iVar1 = *(int *)(CONCAT31(in_register_00000011,Tmd) + 0x10);
  iVar2 = 0;
  if (0 < iVar3) {
    do {
      iVar2 = iVar2 + 1;
      *(byte *)(iVar1 + 3) = *(byte *)(iVar1 + 3) & 0xfd;
      iVar1 = iVar1 + (uint)*(byte *)(iVar1 + 1) * 4 + 4;
    } while (iVar2 < iVar3);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Tmd_ChangeColor(struct TMD_91fake *Tmd /*$a0*/, struct TMD_8fake *col /*$a1*/)
 // line 73, offset 0x8009e35c
	/* begin block 1 */
		// Start line: 75
		// Start offset: 0x8009E35C
		// Variables:
	// 		long i; // $a2
	// 		long nPrims; // $a3
	// 		struct TMD_90fake *pPrim; // $v1
	/* end block 1 */
	// End offset: 0x8009E410
	// End Line: 91

	/* begin block 2 */
		// Start line: 155
	/* end block 2 */
	// End Line: 156

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Tmd_ChangeColor(undefined Tmd,undefined col)

{
  byte bVar1;
  int iVar2;
  undefined3 in_register_00000011;
  undefined3 in_register_00000015;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  puVar3 = (undefined4 *)CONCAT31(in_register_00000015,col);
  iVar5 = *(int *)(CONCAT31(in_register_00000011,Tmd) + 0x14);
  iVar2 = *(int *)(CONCAT31(in_register_00000011,Tmd) + 0x10);
  iVar4 = 0;
  if (0 < iVar5) {
    do {
      bVar1 = *(byte *)(iVar2 + 3) & 0x7d;
      if (bVar1 == 0x25) {
        *(undefined4 *)(iVar2 + 0x10) = *puVar3;
      }
      else {
        if (bVar1 == 0x35) {
          *(undefined4 *)(iVar2 + 0x10) = *puVar3;
          *(undefined4 *)(iVar2 + 0x14) = *puVar3;
          *(undefined4 *)(iVar2 + 0x18) = *puVar3;
        }
      }
      iVar4 = iVar4 + 1;
      iVar2 = iVar2 + (uint)*(byte *)(iVar2 + 1) * 4 + 4;
    } while (iVar4 < iVar5);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Tmd_StretchZ(struct TMD_91fake *Tmd /*$a0*/, struct TMD_7fake *pVert /*$a1*/, short stretch /*$t0*/)
 // line 94, offset 0x8009e418
	/* begin block 1 */
		// Start line: 95
		// Start offset: 0x8009E418
		// Variables:
	// 		long i; // $a3
	// 		long nVert; // $a0
	/* end block 1 */
	// End offset: 0x8009E468
	// End Line: 105

	/* begin block 2 */
		// Start line: 207
	/* end block 2 */
	// End Line: 208

void Tmd_StretchZ(undefined Tmd,undefined pVert,short stretch)

{
  undefined3 in_register_00000011;
  int iVar1;
  undefined3 in_register_00000015;
  short *psVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar1 = *(int *)(CONCAT31(in_register_00000011,Tmd) + 4);
  if (0 < iVar1) {
    psVar2 = (short *)(CONCAT31(in_register_00000015,pVert) + 4);
    do {
      if ((int)*psVar2 + (int)stretch < 1) {
        *psVar2 = 0;
      }
      else {
        *psVar2 = *psVar2 + stretch;
      }
      iVar3 = iVar3 + 1;
      psVar2 = psVar2 + 4;
    } while (iVar3 < iVar1);
  }
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ Tmd_TestEndStretchZ(struct TMD_91fake *Tmd /*$a0*/, struct TMD_7fake *pVert /*$a1*/)
 // line 107, offset 0x8009e470
	/* begin block 1 */
		// Start line: 109
		// Start offset: 0x8009E470
		// Variables:
	// 		long i; // $v1
	// 		long nVert; // $a0
	/* end block 1 */
	// End offset: 0x8009E4A4
	// End Line: 118

	/* begin block 2 */
		// Start line: 238
	/* end block 2 */
	// End Line: 239

/* WARNING: Unknown calling convention yet parameter storage is locked */

short Tmd_TestEndStretchZ(undefined Tmd,undefined pVert)

{
  int iVar1;
  undefined3 in_register_00000011;
  int iVar2;
  undefined3 in_register_00000015;
  int iVar3;
  
  iVar3 = CONCAT31(in_register_00000015,pVert);
  iVar2 = *(int *)(CONCAT31(in_register_00000011,Tmd) + 4);
  iVar1 = 0;
  if (0 < iVar2) {
    do {
      iVar1 = iVar1 + 1;
      if (*(short *)(iVar3 + 4) != 0) {
        return 0;
      }
      iVar3 = iVar3 + 8;
    } while (iVar1 < iVar2);
  }
  return 1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Tmd_SetZ(struct TMD_91fake *Tmd /*$a0*/, short value /*$a1*/)
 // line 121, offset 0x8009e4ac
	/* begin block 1 */
		// Start line: 122
		// Start offset: 0x8009E4AC
		// Variables:
	// 		struct TMD_7fake *pVert; // $a2
	// 		long i; // $v1
	// 		long nVert; // $a0
	/* end block 1 */
	// End offset: 0x8009E4D4
	// End Line: 133

	/* begin block 2 */
		// Start line: 273
	/* end block 2 */
	// End Line: 274

void Tmd_SetZ(undefined Tmd,short value)

{
  int iVar1;
  undefined3 in_register_00000011;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)CONCAT31(in_register_00000011,Tmd);
  iVar2 = ((int *)CONCAT31(in_register_00000011,Tmd))[1];
  iVar1 = 0;
  if (0 < iVar2) {
    do {
      *(short *)(iVar3 + 4) = value;
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 8;
    } while (iVar1 < iVar2);
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Tmd_GetnPrimitives(void *File /*$a0*/)
 // line 136, offset 0x8009e4dc
	/* begin block 1 */
		// Start line: 138
		// Start offset: 0x8009E4DC
		// Variables:
	// 		long n; // $a2
	// 		long i; // $a1
	// 		long nPrim; // $v1
	/* end block 1 */
	// End offset: 0x8009E508
	// End Line: 144

	/* begin block 2 */
		// Start line: 303
	/* end block 2 */
	// End Line: 304

long Tmd_GetnPrimitives(void *File)

{
  int *piVar1;
  long lVar2;
  int iVar3;
  
  iVar3 = 0;
  piVar1 = (int *)((int)File + 8);
  lVar2 = 0;
  if (0 < *piVar1) {
    do {
      iVar3 = iVar3 + 1;
      lVar2 = lVar2 + *(int *)((int)File + 0x20);
      File = (void *)((int)File + 0x1c);
    } while (iVar3 < *piVar1);
  }
  return lVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Tmd_GetBox(struct TMD_91fake *Tmd /*$a0*/, struct TMD_7fake *min /*$a1*/, struct TMD_7fake *max /*$a2*/)
 // line 148, offset 0x8009e510
	/* begin block 1 */
		// Start line: 150
		// Start offset: 0x8009E510
		// Variables:
	// 		struct TMD_7fake *pVert; // $a3
	// 		long i; // $t0
	// 		long nVert; // $t1
	/* end block 1 */
	// End offset: 0x8009E618
	// End Line: 171

	/* begin block 2 */
		// Start line: 340
	/* end block 2 */
	// End Line: 341

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Tmd_GetBox(undefined Tmd,undefined min,undefined max)

{
  undefined3 in_register_00000011;
  short *psVar1;
  undefined3 in_register_00000015;
  short *psVar2;
  undefined3 in_register_00000019;
  short *psVar3;
  short *psVar4;
  int iVar5;
  short *psVar6;
  
  psVar3 = (short *)CONCAT31(in_register_00000019,max);
  psVar2 = (short *)CONCAT31(in_register_00000015,min);
  iVar5 = 0;
  psVar4 = *(short **)CONCAT31(in_register_00000011,Tmd);
  psVar6 = ((short **)CONCAT31(in_register_00000011,Tmd))[1];
  *psVar3 = -10000;
  psVar3[1] = -10000;
  psVar3[2] = -10000;
  *psVar2 = 10000;
  psVar2[1] = 10000;
  psVar2[2] = 10000;
  if (0 < (int)psVar6) {
    psVar1 = psVar4 + 2;
    do {
      if (*psVar3 < *psVar4) {
        *psVar3 = *psVar4;
      }
      if (psVar3[1] < psVar1[-1]) {
        psVar3[1] = psVar1[-1];
      }
      if (psVar3[2] < *psVar1) {
        psVar3[2] = *psVar1;
      }
      if (*psVar4 < *psVar2) {
        *psVar2 = *psVar4;
      }
      if (psVar1[-1] < psVar2[1]) {
        psVar2[1] = psVar1[-1];
      }
      if (*psVar1 < psVar2[2]) {
        psVar2[2] = *psVar1;
      }
      iVar5 = iVar5 + 1;
      psVar1 = psVar1 + 4;
      psVar4 = psVar4 + 4;
    } while (iVar5 < (int)psVar6);
  }
  return;
}



// decompiled code
// original method signature: 
// void GsMapModelingData() /* GsMapModelingData method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 217, offset 0x8009e620
void GsMapModelingData(uint *param_1)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  
  if ((*param_1 & 1) == 0) {
    *param_1 = *param_1 | 1;
    iVar2 = 0;
    uVar3 = param_1[1];
    param_1 = param_1 + 2;
    puVar1 = param_1;
    if (0 < (int)uVar3) {
      do {
        iVar2 = iVar2 + 1;
        *puVar1 = *puVar1 + (int)param_1;
        puVar1[4] = puVar1[4] + (int)param_1;
        puVar1[2] = puVar1[2] + (int)param_1;
        puVar1 = puVar1 + 7;
      } while (iVar2 < (int)uVar3);
    }
  }
  return;
}





