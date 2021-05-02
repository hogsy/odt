#include "THISDUST.H"
#include "FILE.H"


// decompiled code
// original method signature: 
// void /*$ra*/ File_Init()
 // line 37, offset 0x8009b2e8
	/* begin block 1 */
		// Start line: 85
	/* end block 1 */
	// End Line: 86

/* WARNING: Unknown calling convention yet parameter storage is locked */

void File_Init(void)

{
  File_Used = 0;
  return;
}



// decompiled code
// original method signature: 
// void * /*$ra*/ FileGroup_GetAddr(void *File /*$a0*/, long Index /*$a1*/)
 // line 59, offset 0x8009b2f4
	/* begin block 1 */
		// Start line: 61
		// Start offset: 0x8009B2F4
	/* end block 1 */
	// End offset: 0x8009B2F4
	// End Line: 69

	/* begin block 2 */
		// Start line: 127
	/* end block 2 */
	// End Line: 128

void * FileGroup_GetAddr(void *File,long Index)

{
  return (void *)((int)File + *(int *)((int)File + Index * 8 + 4));
}



// decompiled code
// original method signature: 
// void /*$ra*/ File_Exec(char *n /*$v0*/, long sp /*$s1*/, long p1 /*$s2*/, long p2 /*$s3*/)
 // line 73, offset 0x8009b308
	/* begin block 1 */
		// Start line: 74
		// Start offset: 0x8009B308
		// Variables:
	// 		struct EXEC Ex; // stack offset -168
	// 		char cdname[80]; // stack offset -104
	/* end block 1 */
	// End offset: 0x8009B3A4
	// End Line: 104

	/* begin block 2 */
		// Start line: 146
	/* end block 2 */
	// End Line: 147

void File_Exec(char *n,long sp,long p1,long p2)

{
  int iVar1;
  char acStack104 [80];
  
  File_CdConvert(acStack104,n,1);
  OS_Stop();
  _96_init();
  iVar1 = Load();
  if (iVar1 == 0) {
    ErrorMaster();
  }
  _96_remove();
  EnterCriticalSection();
  iVar1 = Exec();
  if (iVar1 == 0) {
    ErrorMaster();
  }
  OS_Start();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ File_Seek(char *name /*$a1*/)
 // line 116, offset 0x8009b3c8
	/* begin block 1 */
		// Start line: 117
		// Start offset: 0x8009B3C8
		// Variables:
	// 		struct FILE_3fake fp; // stack offset -112
	// 		char cdname[80]; // stack offset -88
	/* end block 1 */
	// End offset: 0x8009B3C8
	// End Line: 117

	/* begin block 2 */
		// Start line: 239
	/* end block 2 */
	// End Line: 240

void File_Seek(char *name)

{
  FILE_3fake FStack112;
  char acStack88 [80];
  
  File_CdConvert(acStack88,name,0);
  File_CdSearchFile(&FStack112,acStack88,0);
  File_CdSeek(0x90,0);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ File_IsExist(char *name /*$a1*/)
 // line 132, offset 0x8009b414
	/* begin block 1 */
		// Start line: 133
		// Start offset: 0x8009B414
		// Variables:
	// 		char cdname[80]; // stack offset -88
	/* end block 1 */
	// End offset: 0x8009B414
	// End Line: 133

	/* begin block 2 */
		// Start line: 276
	/* end block 2 */
	// End Line: 277

long File_IsExist(char *name)

{
  long lVar1;
  char acStack88 [80];
  
  File_CdConvert(acStack88,name,0);
  lVar1 = File_CdExistFile(acStack88,0);
  return lVar1;
}



// decompiled code
// original method signature: 
// void * /*$ra*/ File_ReadBytes(long nbytes /*$s3*/, void *addr /*$s0*/)
 // line 151, offset 0x8009b448
	/* begin block 1 */
		// Start line: 152
		// Start offset: 0x8009B448
		// Variables:
	// 		long n; // $s1
	// 		long a; // $s2
	/* end block 1 */
	// End offset: 0x8009B4B0
	// End Line: 184

	/* begin block 2 */
		// Start line: 318
	/* end block 2 */
	// End Line: 319

void * File_ReadBytes(long nbytes,void *addr)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = nbytes + 0x7ff;
  if (iVar2 < 0) {
    iVar2 = nbytes + 0xffe;
  }
  bVar1 = addr == (void *)0x0;
  if (bVar1) {
    addr = Heap_AllocMem((iVar2 >> 0xb) << 0xb);
  }
  File_CdReadSectors(addr,iVar2 >> 0xb,0);
  if (bVar1) {
    Heap_ResizeMem(addr,nbytes);
  }
  return addr;
}



// decompiled code
// original method signature: 
// void * /*$ra*/ File_Read(char *name /*$a0*/, void *addr /*$a1*/)
 // line 188, offset 0x8009b4d0
	/* begin block 1 */
		// Start line: 397
	/* end block 1 */
	// End Line: 398

void * File_Read(char *name,void *addr)

{
  void *pvVar1;
  
  pvVar1 = File_Open(name,addr);
  File_Wait();
  return pvVar1;
}



// decompiled code
// original method signature: 
// void * /*$ra*/ File_Open(char *name /*$a0*/, void *addr /*$a1*/)
 // line 197, offset 0x8009b4fc
	/* begin block 1 */
		// Start line: 198
		// Start offset: 0x8009B4FC
	/* end block 1 */
	// End offset: 0x8009B4FC
	// End Line: 198

	/* begin block 2 */
		// Start line: 415
	/* end block 2 */
	// End Line: 416

void * File_Open(char *name,void *addr)

{
  void *pvVar1;
  
  pvVar1 = File_CdReadFile(name,addr,0);
  return pvVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ File_Wait()
 // line 238, offset 0x8009b51c
	/* begin block 1 */
		// Start line: 498
	/* end block 1 */
	// End Line: 499

/* WARNING: Unknown calling convention yet parameter storage is locked */

void File_Wait(void)

{
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ File_CdExistFile(char *name /*$a1*/, long multitasking /*$a1*/)
 // line 249, offset 0x8009b524
	/* begin block 1 */
		// Start line: 250
		// Start offset: 0x8009B524
		// Variables:
	// 		struct FILE_3fake dummy; // stack offset -32
	/* end block 1 */
	// End offset: 0x8009B524
	// End Line: 250

	/* begin block 2 */
		// Start line: 519
	/* end block 2 */
	// End Line: 520

long File_CdExistFile(char *name,long multitasking)

{
  undefined4 *puVar1;
  undefined4 auStack32 [6];
  
  puVar1 = CdSearchFile(auStack32,name);
  return (long)puVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ File_CdSearchFile(struct FILE_3fake *fp /*$s0*/, char *name /*$s1*/, long multitasking /*$a2*/)
 // line 257, offset 0x8009b548
	/* begin block 1 */
		// Start line: 535
	/* end block 1 */
	// End Line: 536

void File_CdSearchFile(FILE_3fake *fp,char *name,long multitasking)

{
  undefined4 *puVar1;
  
  while (puVar1 = CdSearchFile((undefined4 *)fp,name), puVar1 == (undefined4 *)0x0) {
    CdInit();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ File_CdSeek(struct FILE_0fake *pos /*$s3*/, long multitasking /*$s4*/)
 // line 269, offset 0x8009b598
	/* begin block 1 */
		// Start line: 270
		// Start offset: 0x8009B598
		// Variables:
	// 		short status; // $s1
	// 		char c; // stack offset -40
	/* end block 1 */
	// End offset: 0x8009B644
	// End Line: 305

	/* begin block 2 */
		// Start line: 559
	/* end block 2 */
	// End Line: 560

void File_CdSeek(undefined pos,long multitasking)

{
  short sVar1;
  int iVar2;
  undefined3 in_register_00000011;
  undefined auStack40 [8];
  
  do {
    while (iVar2 = CdControl(0x15,(undefined *)CONCAT31(in_register_00000011,pos),(undefined *)0x0),
          iVar2 == 0) {
      CdInit();
    }
    do {
      sVar1 = CdSync(1,auStack40);
      if (sVar1 == 5) {
        CdInit();
        break;
      }
      if (multitasking != 0) {
        Task_Next();
      }
    } while (sVar1 != 2);
    if (sVar1 == 2) {
      return;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ File_CdReadSectors(void *a /*$s3*/, long n /*$s1*/, long multitasking /*$s4*/)
 // line 308, offset 0x8009b668
	/* begin block 1 */
		// Start line: 309
		// Start offset: 0x8009B668
		// Variables:
	// 		struct FILE_0fake pos; // stack offset -40
	// 		long status; // $s0
	// 		char c; // stack offset -32
	/* end block 1 */
	// End offset: 0x8009B724
	// End Line: 349

	/* begin block 2 */
		// Start line: 645
	/* end block 2 */
	// End Line: 646

void File_CdReadSectors(void *a,long n,long multitasking)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 local_28 [2];
  undefined auStack32 [8];
  
  puVar1 = (undefined4 *)CdLastPos();
  local_28[0] = *puVar1;
  do {
    while (uVar2 = CdRead(n,a,0x80), uVar2 == 0) {
      CdInit();
    }
    do {
      iVar3 = CdReadSync(1,auStack32);
      if (iVar3 == -1) {
        CdInit();
        File_CdSeek(0xd8,0);
        break;
      }
      if (multitasking != 0) {
        Task_Next();
      }
    } while (iVar3 != 0);
    if (iVar3 == 0) {
      iVar3 = CdPosToInt((byte *)local_28);
      CdIntToPos(iVar3 + n,(char *)local_28);
      File_CdSeek(0xd8,0);
      return;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// void * /*$ra*/ File_CdReadFile(char *name /*$s3*/, void *a /*$s1*/, long multitasking /*$s2*/)
 // line 356, offset 0x8009b764
	/* begin block 1 */
		// Start line: 357
		// Start offset: 0x8009B764
		// Variables:
	// 		struct FILE_3fake fp; // stack offset -128
	// 		char cdname[80]; // stack offset -104
	// 		short f; // $s4
	// 		long n; // $s0
	/* end block 1 */
	// End offset: 0x8009B834
	// End Line: 385

	/* begin block 2 */
		// Start line: 750
	/* end block 2 */
	// End Line: 751

void * File_CdReadFile(char *name,void *a,long multitasking)

{
  bool bVar1;
  uint uVar2;
  FILE_3fake FStack128;
  char acStack104 [80];
  
  if (File_Used != 0) {
    do {
      Task_Next();
    } while (File_Used != 0);
  }
  File_Used = 1;
  File_CdConvert(acStack104,name,0);
  File_CdSearchFile(&FStack128,acStack104,multitasking);
  File_CdSeek(0x80,multitasking);
  uVar2 = FStack128.size + 0x7ff;
  bVar1 = a == (void *)0x0;
  if (bVar1) {
    a = Heap_AllocMem(uVar2 & 0xfffff800);
  }
  File_CdReadSectors(a,uVar2 >> 0xb,multitasking);
  if (bVar1) {
    Heap_ResizeMem(a,FStack128.size);
  }
  File_Used = 0;
  return a;
}



// decompiled code
// original method signature: 
// void /*$ra*/ File_CdConvert(char *out /*$s2*/, char *in /*$s0*/, long fcd /*$s1*/)
 // line 391, offset 0x8009b85c
	/* begin block 1 */
		// Start line: 392
		// Start offset: 0x8009B85C
	/* end block 1 */
	// End offset: 0x8009B918
	// End Line: 408

	/* begin block 2 */
		// Start line: 829
	/* end block 2 */
	// End Line: 830

void File_CdConvert(char *out,char *in,long fcd)

{
  undefined *puVar1;
  char cVar2;
  size_t sVar3;
  int iVar4;
  byte *pbVar5;
  uint uVar6;
  
  cVar2 = DAT_800adb1d;
  puVar1 = PTR_DAT_800adb18;
  if (fcd == 0) {
    *out = DAT_800adb1c;
    out[1] = cVar2;
  }
  else {
    *(undefined4 *)out = DAT_800adb14;
    *(undefined **)(out + 4) = puVar1;
  }
  strcat(out,&DAT_800adb20);
  strcat(out,in);
  uVar6 = fcd * 6;
  while( true ) {
    sVar3 = strlen(out);
    pbVar5 = (byte *)(out + uVar6);
    if (sVar3 <= uVar6) break;
    uVar6 = uVar6 + 1;
    iVar4 = toupper((uint)*pbVar5);
    *pbVar5 = (byte)iVar4;
  }
  strcat(out,(char *)&PTR_DAT_800adb28);
  return;
}



// decompiled code
// original method signature: 
// void toupper() /* toupper method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 456, offset 0x8009b940
int toupper(int __c)

{
  int iVar1;
  
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)0xa0)();
  return iVar1;
}





