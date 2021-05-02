#include "THISDUST.H"
#include "DEMO.H"


// decompiled code
// original method signature: 
// void /*$ra*/ Demo_Init()
 // line 40, offset 0x80031830
	/* begin block 1 */
		// Start line: 81
	/* end block 1 */
	// End Line: 82

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Demo_Init(void)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Demo_InitPlayer()
 // line 45, offset 0x80031838
	/* begin block 1 */
		// Start line: 47
		// Start offset: 0x80031838
		// Variables:
	// 		long i; // $a0
	/* end block 1 */
	// End offset: 0x80031894
	// End Line: 64

	/* begin block 2 */
		// Start line: 101
	/* end block 2 */
	// End Line: 102

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Demo_InitPlayer(void)

{
  undefined *puVar1;
  int iVar2;
  
  iVar2 = 0;
  puVar1 = &Player;
  _DAT_800b1e38 = 0x1e00;
  _DAT_800b1e3a = 0x1e00;
  _DAT_800b1e3c = 0x1e00;
  _DAT_800b1e36 = 100;
  _DAT_800b1e34 = 0;
  do {
    puVar1[0x1ac] = 5;
    *(undefined2 *)(puVar1 + 0x1aa) = 100;
    iVar2 = iVar2 + 1;
    puVar1 = puVar1 + 8;
  } while (iVar2 < 4);
  _DAT_800b1e14 = &DAT_0001e327;
  DAT_800b1e20 = 2;
  DAT_800b1e21 = 0xd;
  DAT_800b1e22 = 9;
  DAT_800b1e23 = 0x10;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Demo_PlayInit(long index /*$a0*/)
 // line 76, offset 0x800318dc
	/* begin block 1 */
		// Start line: 77
		// Start offset: 0x800318DC
		// Variables:
	// 		char file[20]; // stack offset -32
	/* end block 1 */
	// End offset: 0x800318DC
	// End Line: 77

	/* begin block 2 */
		// Start line: 162
	/* end block 2 */
	// End Line: 163

void Demo_PlayInit(long index)

{
  char acStack32 [24];
  
  sprintf(acStack32,s_Demos_Demo_d_joy_800ad448,index + 1);
  Demo_File = (_DEMO *)File_Read(acStack32,(void *)0x0);
  Pvl_PlayerNumber = Demo_File->player;
  Pvl_LevelNumber = Demo_File->level;
  Pvl_SectorNumber = Demo_File->sector;
  Demo_Play = Demo_File->block;
  Demo_Frame = 0;
  Demo_InitPlayer();
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Demo_PlayFrame()
 // line 113, offset 0x80031950
	/* begin block 1 */
		// Start line: 256
	/* end block 1 */
	// End Line: 257

/* WARNING: Unknown calling convention yet parameter storage is locked */

long Demo_PlayFrame(void)

{
  ushort uVar1;
  long lVar2;
  
  Demo_Frame = Demo_Frame + 1;
  if (Demo_Frame < (int)Scr_TicksPerSecond * 0x1e) {
    uVar1 = Demo_Play[1];
    Pvl_Trig0 = uVar1 & ~Pvl_Run0;
    if (*Demo_Play == 0) {
      Demo_Play = Demo_Play + 2;
      lVar2 = 0;
      Pvl_Run0 = uVar1;
    }
    else {
      Pvl_Run0 = uVar1;
      *Demo_Play = *Demo_Play - 1;
      lVar2 = 0;
    }
  }
  else {
    if (Demo_Frame == (int)Scr_TicksPerSecond * 0x1e) {
      Heap_FreeMem(Demo_File);
    }
    Pvl_Trig0 = 0;
    Pvl_Run0 = 0;
    lVar2 = 1;
  }
  return lVar2;
}





