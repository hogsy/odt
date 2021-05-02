#include "THISDUST.H"
#include "SOUND.H"


// decompiled code
// original method signature: 
// void /*$ra*/ Sound_Init(unsigned char bMode /*$s0*/)
 // line 163, offset 0x8009febc
	/* begin block 1 */
		// Start line: 164
		// Start offset: 0x8009FEBC
		// Variables:
	// 		long wSampleId; // $a1
	/* end block 1 */
	// End offset: 0x8009FF6C
	// End Line: 195

	/* begin block 2 */
		// Start line: 326
	/* end block 2 */
	// End Line: 327

void Sound_Init(uchar bMode)

{
  _EffectStruct *p_Var1;
  _PlayStruct *p_Var2;
  _VoiceStruct *p_Var3;
  int iVar4;
  
  SpuInitMalloc(0x80,(undefined4 *)pbSpuMallocRec);
  SpuSetCommonMasterVolume(&DAT_00005fff,&DAT_00005fff);
  SpuSetCommonCDVolume(0x5fff,0x5fff);
  SpuSetCommonCDMix(1);
  iVar4 = 0;
  p_Var1 = &EffectList;
  do {
    p_Var1->dwAddr = 0;
    p_Var1->dwSize = 0;
    p_Var1->dwImgAddr = 0;
    p_Var1->dwImgSize = 0;
    p_Var1->loop = 0;
    iVar4 = iVar4 + 1;
    p_Var1 = p_Var1 + 1;
  } while (iVar4 < 0x80);
  iVar4 = 0;
  p_Var2 = playList;
  p_Var3 = &voiceList;
  do {
    p_Var3->wFlags = 0;
    p_Var3->wDelay = 0;
    p_Var2->wControlFlags = 0;
    p_Var2->bVoice1 = -1;
    p_Var2->bVoice2 = -1;
    p_Var2 = p_Var2 + 1;
    iVar4 = iVar4 + 1;
    p_Var3 = p_Var3 + 1;
  } while (iVar4 < 0x18);
  SRAM_UsedMem = 0;
  Sound_nSounds = 0;
  Sound_Mode = bMode;
  Sound_FlagPaused = '\0';
  Sound_CdHandle = (TASK *)0x0;
  bInitOkG = '\x01';
  bCallBackOnG = '\0';
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Sound_Start()
 // line 205, offset 0x8009ff9c
	/* begin block 1 */
		// Start line: 439
	/* end block 1 */
	// End Line: 440

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Sound_Start(void)

{
  Sound_Init(Sound_Mode);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Sound_Quit()
 // line 211, offset 0x8009ffc0
	/* begin block 1 */
		// Start line: 454
	/* end block 1 */
	// End Line: 455

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Sound_Quit(void)

{
  return;
}



// decompiled code
// original method signature: 
// void * /*$ra*/ Sound_LoadGroup(char *name /*$a0*/)
 // line 218, offset 0x8009ffc8
	/* begin block 1 */
		// Start line: 465
	/* end block 1 */
	// End Line: 466

void * Sound_LoadGroup(char *name)

{
  All_Sounds = File_Read(name,(void *)0x0);
  return All_Sounds;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Sound_ReleaseGroup()
 // line 225, offset 0x8009ffe8
	/* begin block 1 */
		// Start line: 481
	/* end block 1 */
	// End Line: 482

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Sound_ReleaseGroup(void)

{
  Heap_FreeMem(All_Sounds);
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ Sound_AllocGroup(void *group /*$s1*/)
 // line 242, offset 0x800a000c
	/* begin block 1 */
		// Start line: 243
		// Start offset: 0x800A000C
		// Variables:
	// 		short i; // $s0
	// 		short FirstIndex; // $s2
	/* end block 1 */
	// End offset: 0x800A0068
	// End Line: 250

	/* begin block 2 */
		// Start line: 515
	/* end block 2 */
	// End Line: 516

short Sound_AllocGroup(void *group)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  sVar1 = Sound_nSounds;
  iVar3 = 0;
  if (0 < *(int *)group) {
    iVar2 = 0;
    do {
      Sound_TransferVAG(group,(short)((uint)iVar2 >> 0x10),(void *)0x0);
      iVar3 = iVar3 + 1;
      iVar2 = iVar3 * 0x10000;
    } while (iVar3 * 0x10000 >> 0x10 < *(int *)group);
  }
  return sVar1;
}



// decompiled code
// original method signature: 
// void * /*$ra*/ Sound_FileRead(void *group /*$a0*/, long wSampleId /*$a1*/)
 // line 266, offset 0x800a0088
	/* begin block 1 */
		// Start line: 567
	/* end block 1 */
	// End Line: 568

void * Sound_FileRead(void *group,long wSampleId)

{
  void *pvVar1;
  
  pvVar1 = FileGroup_GetAddr(group,wSampleId);
  return pvVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Sound_SetMasterVolume(unsigned char bVolume /*$a0*/)
 // line 280, offset 0x800a00a8
	/* begin block 1 */
		// Start line: 596
	/* end block 1 */
	// End Line: 597

void Sound_SetMasterVolume(uchar bVolume)

{
  if (bInitOkG != '\0') {
    Sound_MasterVol = bVolume;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Sound_SetCdVolume(unsigned char bVolume /*$a0*/)
 // line 297, offset 0x800a00c4
	/* begin block 1 */
		// Start line: 298
		// Start offset: 0x800A00C4
		// Variables:
	// 		struct SOUND_2fake cdVol; // stack offset -16
	/* end block 1 */
	// End offset: 0x800A00C4
	// End Line: 298

	/* begin block 2 */
		// Start line: 629
	/* end block 2 */
	// End Line: 630

void Sound_SetCdVolume(uchar bVolume)

{
  uchar local_10;
  undefined local_f;
  uchar local_e;
  undefined local_d;
  
  local_f = 0;
  local_d = 0;
  local_10 = bVolume;
  local_e = bVolume;
  CdMix(&local_10);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Sound_SetCallBack(TDRFuncPtr_Sound_SetCallBack0CallBack CallBack /*$a0*/)
 // line 320, offset 0x800a00f4
	/* begin block 1 */
		// Start line: 684
	/* end block 1 */
	// End Line: 685

void Sound_SetCallBack(TDRFuncPtr_Sound_SetCallBack0CallBack CallBack)

{
  if (bInitOkG != '\0') {
    bCallBackOnG = '\x01';
    DoCallBack = CallBack;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Sound_SetMode(unsigned char bMode /*$a0*/)
 // line 339, offset 0x800a0114
	/* begin block 1 */
		// Start line: 722
	/* end block 1 */
	// End Line: 723

void Sound_SetMode(uchar bMode)

{
  if (bInitOkG != '\0') {
    Sound_Mode = bMode;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Sound_UnInit()
 // line 354, offset 0x800a0130
	/* begin block 1 */
		// Start line: 752
	/* end block 1 */
	// End Line: 753

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Sound_UnInit(void)

{
  if (bInitOkG != '\0') {
    SpuSetKey(0,0xffffff);
    SpuQuit();
    bInitOkG = '\0';
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Sound_Pause()
 // line 372, offset 0x800a016c
	/* begin block 1 */
		// Start line: 373
		// Start offset: 0x800A016C
		// Variables:
	// 		short wVoice; // $s2
	// 		short wVolL; // stack offset -40
	// 		short wVolR; // stack offset -38
	// 		short wPitch; // stack offset -36
	// 		long dwGet; // stack offset -32
	/* end block 1 */
	// End offset: 0x800A0248
	// End Line: 395

	/* begin block 2 */
		// Start line: 788
	/* end block 2 */
	// End Line: 789

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Sound_Pause(void)

{
  int iVar1;
  int iVar2;
  ushort local_28;
  ushort local_26;
  short local_24 [2];
  long local_20 [2];
  
  iVar2 = 0;
  Sound_FlagPaused = '\x01';
  bVoiceInPause = '\0';
  iVar1 = 0;
  do {
    iVar1 = iVar1 >> 0x10;
    SpuGetVoiceVolume(iVar1,&local_28,&local_26);
    (&dwVolumeStore)[iVar1 * 2] = (int)(short)local_28;
    *(int *)((int)&dwVolumeStore + (iVar1 << 3 | 4U)) = (int)(short)local_26;
    SpuGetVoicePitch(iVar1,local_24);
    (&dwPitchStore)[iVar1] = (int)local_24[0];
    SpuGetVoiceStartAddr(iVar1,local_20);
    dwAddrStore[iVar1] = local_20[0];
    SpuSetVoiceVolume(iVar1,0,0);
    iVar2 = iVar2 + 1;
    iVar1 = iVar2 * 0x10000;
  } while (iVar2 * 0x10000 >> 0x10 < 0x18);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Sound_Continue()
 // line 404, offset 0x800a0264
	/* begin block 1 */
		// Start line: 405
		// Start offset: 0x800A0264
		// Variables:
	// 		int wVoice; // $s1
	/* end block 1 */
	// End offset: 0x800A02F8
	// End Line: 417

	/* begin block 2 */
		// Start line: 887
	/* end block 2 */
	// End Line: 888

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Sound_Continue(void)

{
  short sVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  long *plVar6;
  int iVar7;
  
  iVar7 = 4;
  plVar6 = &dwVolumeStore;
  Sound_FlagPaused = '\0';
  iVar3 = 0;
  iVar4 = 0;
  do {
    SpuSetVoicePitch(iVar4,*(undefined2 *)((int)&dwPitchStore + iVar3));
    SpuSetVoiceStartAddr(iVar4,*(uint *)((int)dwAddrStore + iVar3));
    psVar2 = (short *)((int)&dwVolumeStore + iVar7);
    iVar7 = iVar7 + 8;
    sVar1 = *(short *)plVar6;
    plVar6 = plVar6 + 2;
    iVar5 = iVar4 + 1;
    SpuSetVoiceVolume(iVar4,(int)sVar1,(int)*psVar2);
    iVar3 = iVar5 * 4;
    iVar4 = iVar5;
  } while (iVar5 < 0x18);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Sound_TransferVAG(void *group /*$a0*/, short wSampleId /*$a1*/, void *pImgPtr /*$a2*/)
 // line 440, offset 0x800a0318
	/* begin block 1 */
		// Start line: 441
		// Start offset: 0x800A0318
		// Variables:
	// 		long dwSize; // $s3
	// 		long dwAddr; // $s2
	// 		long dwMulti; // $a1
	// 		struct _VagHdr *pHeader; // $s1
	/* end block 1 */
	// End offset: 0x800A0470
	// End Line: 515

	/* begin block 2 */
		// Start line: 1003
	/* end block 2 */
	// End Line: 1004

long Sound_TransferVAG(void *group,short wSampleId,void *pImgPtr)

{
  byte bVar1;
  long lVar2;
  char *pVag;
  uint uVar3;
  int iVar4;
  undefined *puVar5;
  
  if (bInitOkG == '\0') {
    lVar2 = -1;
  }
  else {
    pVag = (char *)FileGroup_GetAddr(group,(int)wSampleId);
    puVar5 = *(undefined **)(pVag + 0xc);
    uVar3 = SpuMalloc((uint)puVar5);
    if (uVar3 == 0xffffffff) {
      lVar2 = -2;
    }
    else {
      bVar1 = pVag[0x13];
      if (bVar1 == 0x40) {
        lVar2 = 3;
      }
      else {
        if (bVar1 < 0x41) {
          if (bVar1 == 0x11) {
            lVar2 = 2;
          }
          else {
            if (bVar1 == 0x22) {
              lVar2 = 1;
            }
            else {
              lVar2 = 0;
            }
          }
        }
        else {
          if (bVar1 == 0x44) {
            lVar2 = 0;
          }
          else {
            if (bVar1 == 0x70) {
              lVar2 = 4;
            }
            else {
              lVar2 = 0;
            }
          }
        }
      }
      iVar4 = (int)Sound_nSounds;
      (&EffectList)[iVar4].dwAddr = uVar3;
      *(undefined **)&(&EffectList)[iVar4].dwSize = puVar5;
      (&EffectList)[iVar4].dwMulti = lVar2;
      lVar2 = Sound_VagIsLoop(pVag);
      (&EffectList)[(int)Sound_nSounds].loop = (short)lVar2;
      SpuSetTransferStartAddr(uVar3);
      SpuWrite((undefined2 *)(pVag + 0x30),puVar5,(uint)pImgPtr);
      SpuIsTransferCompleted(1);
      Sound_nSounds = Sound_nSounds + 1;
      lVar2 = (int)Sound_nSounds + -1;
      SRAM_UsedMem = SRAM_UsedMem + *(int *)(pVag + 0xc);
    }
  }
  return lVar2;
}



// decompiled code
// original method signature: 
// int /*$ra*/ Sound_FreeSRAM(char dwSampleId /*$v1*/)
 // line 545, offset 0x800a048c
	/* begin block 1 */
		// Start line: 1235
	/* end block 1 */
	// End Line: 1236

int Sound_FreeSRAM(char dwSampleId)

{
  uint uVar1;
  
  if (bInitOkG != '\0') {
    uVar1 = (uint)(byte)dwSampleId;
    if ((&EffectList)[uVar1].dwAddr != 0) {
      if ((&EffectList)[uVar1].dwImgAddr != 0) {
        SpuFree((&EffectList)[uVar1].dwImgAddr);
        (&EffectList)[uVar1].dwImgSize = 0;
        (&EffectList)[uVar1].dwMulti = 0;
      }
      SRAM_UsedMem = SRAM_UsedMem - (&EffectList)[uVar1].dwSize;
      SpuFree((&EffectList)[uVar1].dwAddr);
      (&EffectList)[uVar1].dwSize = 0;
      (&EffectList)[uVar1].dwMulti = 0;
      Sound_nSounds = Sound_nSounds + -1;
      return 1;
    }
  }
  return -1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Sound_VagIsLoop(char *pVag /*$a0*/)
 // line 590, offset 0x800a053c
	/* begin block 1 */
		// Start line: 592
		// Start offset: 0x800A053C
	/* end block 1 */
	// End offset: 0x800A053C
	// End Line: 595

	/* begin block 2 */
		// Start line: 1338
	/* end block 2 */
	// End Line: 1339

long Sound_VagIsLoop(char *pVag)

{
  return (uint)(pVag[*(int *)(pVag + 0xc) + 0x21] != '\a');
}



// decompiled code
// original method signature: 
// short /*$ra*/ Sound_TestEmptyVoices(char *bStatus /*$a0*/)
 // line 611, offset 0x800a055c
	/* begin block 1 */
		// Start line: 613
		// Start offset: 0x800A055C
		// Variables:
	// 		short test; // $a1
	// 		short wId; // $v1
	/* end block 1 */
	// End offset: 0x800A05AC
	// End Line: 622

	/* begin block 2 */
		// Start line: 1377
	/* end block 2 */
	// End Line: 1378

short Sound_TestEmptyVoices(char *bStatus)

{
  int iVar1;
  short sVar2;
  
  sVar2 = 0;
  iVar1 = 0;
  do {
    if ((bStatus[(int)(short)iVar1] == '\0') || (bStatus[(int)(short)iVar1] == '\x03')) {
      sVar2 = sVar2 + 1;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 * 0x10000 >> 0x10 < 0x18);
  return (short)(ushort)(sVar2 < 5);
}



// decompiled code
// original method signature: 
// void /*$ra*/ Sound_SetVoicePitch(long dwVoice /*$a0*/, long dwMulti /*$a1*/, char bPitchMode /*$a2*/)
 // line 639, offset 0x800a05b8
	/* begin block 1 */
		// Start line: 640
		// Start offset: 0x800A05B8
		// Variables:
	// 		long dwPitch; // $a3
	/* end block 1 */
	// End offset: 0x800A061C
	// End Line: 660

	/* begin block 2 */
		// Start line: 1435
	/* end block 2 */
	// End Line: 1436

void Sound_SetVoicePitch(long dwVoice,long dwMulti,char bPitchMode)

{
  undefined2 uVar1;
  int in_a3;
  
  switch(dwMulti) {
  case 0:
    in_a3 = 0x1000;
    break;
  case 1:
    in_a3 = 0x800;
    break;
  case 2:
    in_a3 = 0x400;
    break;
  case 3:
    in_a3 = 0x300;
    break;
  case 4:
    in_a3 = 0x200;
  }
  uVar1 = (undefined2)in_a3;
  if (bPitchMode != '\0') {
    uVar1 = (undefined2)(in_a3 << 1);
  }
  SpuSetVoicePitch(dwVoice,uVar1);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Sound_TurnOffUnusedVoices(char *bStatus /*$s4*/)
 // line 673, offset 0x800a0634
	/* begin block 1 */
		// Start line: 674
		// Start offset: 0x800A0634
		// Variables:
	// 		short i; // $s0
	// 		short j; // $a3
	// 		short wId; // $t4
	// 		short Voice[4]; // stack offset -40
	// 		short Count[4]; // stack offset -32
	/* end block 1 */
	// End offset: 0x800A0888
	// End Line: 733

	/* begin block 2 */
		// Start line: 1503
	/* end block 2 */
	// End Line: 1504

long Sound_TurnOffUnusedVoices(char *bStatus)

{
  int iVar1;
  int iVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  ushort uVar6;
  int iVar7;
  short *psVar8;
  ushort local_28 [4];
  short local_20 [4];
  
  iVar7 = 0;
  do {
    iVar5 = iVar7 << 0x10;
    iVar7 = iVar7 + 1;
    iVar5 = iVar5 >> 0xf;
    *(undefined2 *)((int)local_20 + iVar5) = 0xffff;
    *(undefined2 *)((int)local_28 + iVar5) = 0xffff;
  } while (iVar7 * 0x10000 >> 0x10 < 4);
  uVar6 = 0;
  iVar7 = 0;
  while ((iVar7 = iVar7 >> 0xc, (*(ushort *)((int)&voiceList.wFlags + iVar7) & 8) != 0 ||
         ((playList[(int)*(short *)((int)&voiceList.wPlayId + iVar7)].wControlFlags & 2U) != 0))) {
LAB_800a07c4:
    uVar6 = uVar6 + 1;
    iVar7 = (uint)uVar6 << 0x10;
    if (0x17 < (short)uVar6) {
      iVar5 = 0;
      iVar7 = 0;
      do {
        psVar8 = (short *)((int)local_28 + (iVar7 >> 0xf));
        if ((int)*psVar8 != -1) {
          SpuSetVoiceVolume((int)*psVar8,0,0);
          bStatus[(int)*psVar8] = '\0';
          playList[(int)(&voiceList)[(int)*psVar8].wPlayId].wControlFlags = 0;
          (&voiceList)[(int)*psVar8].wFlags = 0;
        }
        iVar5 = iVar5 + 1;
        iVar7 = iVar5 * 0x10000;
      } while (iVar5 * 0x10000 >> 0x10 < 4);
      return 1;
    }
  }
  iVar1 = 0;
  iVar5 = 0;
LAB_800a0708:
  iVar1 = iVar1 >> 0x10;
  iVar2 = iVar5 + 1;
  if ((int)(uint)*(ushort *)((int)&voiceList.wCount + iVar7) < (int)local_20[iVar1])
  goto LAB_800a07a8;
  iVar2 = 3;
  if (iVar1 < 3) {
    do {
      sVar3 = (short)iVar2;
      iVar2 = iVar2 + -1;
      iVar4 = (int)sVar3;
      local_20[iVar4] = local_20[iVar4 + -1];
      local_28[iVar4] = local_28[iVar4 + -1];
    } while (iVar1 < iVar2 * 0x10000 >> 0x10);
  }
  iVar5 = (iVar5 << 0x10) >> 0xf;
  *(undefined2 *)((int)local_20 + iVar5) = *(undefined2 *)((int)&voiceList.wCount + iVar7);
  *(ushort *)((int)local_28 + iVar5) = uVar6;
  goto LAB_800a07c4;
LAB_800a07a8:
  iVar1 = iVar2 * 0x10000;
  iVar5 = iVar2;
  if (2 < iVar2 * 0x10000 >> 0x10) goto LAB_800a07c4;
  goto LAB_800a0708;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Sound_Off()
 // line 744, offset 0x800a08ac
	/* begin block 1 */
		// Start line: 745
		// Start offset: 0x800A08AC
		// Variables:
	// 		short wId; // $s1
	/* end block 1 */
	// End offset: 0x800A093C
	// End Line: 761

	/* begin block 2 */
		// Start line: 1704
	/* end block 2 */
	// End Line: 1705

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Sound_Off(void)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    uVar1 = SEXT24((short)iVar2);
    SpuSetVoiceVolume(uVar1,0,0);
    SpuSetKey(0,1 << (uVar1 & 0x1f));
    iVar2 = iVar2 + 1;
    (&voiceList)[uVar1].wDelay = 0;
    playList[uVar1].wControlFlags = 0;
  } while (iVar2 * 0x10000 >> 0x10 < 0x18);
  Sound_ManageVoices();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Sound_ManageVoices()
 // line 775, offset 0x800a0964
	/* begin block 1 */
		// Start line: 776
		// Start offset: 0x800A0964
		// Variables:
	// 		int wTrigger; // $s3
	// 		int wPlayId; // $s0
	// 		int wId; // $s2
	// 		int wVoiceId; // $v1
	// 		int wChainId; // $v0
	// 		char bStatus[24]; // stack offset -56
	/* end block 1 */
	// End offset: 0x800A0B6C
	// End Line: 861

	/* begin block 2 */
		// Start line: 1800
	/* end block 2 */
	// End Line: 1801

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Sound_ManageVoices(void)

{
  short sVar1;
  long lVar2;
  int iVar3;
  _VoiceStruct *p_Var4;
  uint uVar5;
  uint uVar6;
  char local_38 [24];
  
  if (bInitOkG != '\0') {
    uVar6 = 0;
    SpuGetAllKeysStatus(local_38);
    sVar1 = Sound_TestEmptyVoices(local_38);
    if ((sVar1 == 0) || (lVar2 = Sound_TurnOffUnusedVoices(local_38), lVar2 != 0)) {
      uVar5 = 0;
      p_Var4 = &voiceList;
      do {
        if ((p_Var4->wFlags & 1U) != 0) {
          p_Var4->wCount = p_Var4->wCount + 1;
        }
        iVar3 = (int)p_Var4->wDelay;
        if (iVar3 == 1) {
          uVar6 = uVar6 | iVar3 << (uVar5 & 0x1f);
        }
        if ((p_Var4->wFlags & 1U) == 0) {
LAB_800a0b18:
          if (p_Var4->wDelay != 0) goto LAB_800a0b28;
        }
        else {
          if (iVar3 == 0) {
            if ((local_38[uVar5] == '\0') || (local_38[uVar5] == '\x03')) {
              iVar3 = (int)p_Var4->wPlayId;
              if ((bCallBackOnG != '\0') && ((playList[iVar3].wControlFlags & 2U) != 0)) {
                (*DoCallBack)(iVar3);
              }
              p_Var4->wFlags = 0;
              if ((playList[iVar3].wControlFlags & 2U) == 0) {
                playList[iVar3].wControlFlags = 0;
              }
              else {
                if ((playList[iVar3].wControlFlags & 4U) != 0) {
                  sVar1 = playList[iVar3].wChainId;
                  (&voiceList)[(int)playList[(int)sVar1].bVoice1].wFlags =
                       (&voiceList)[(int)playList[(int)sVar1].bVoice1].wFlags & 0xfffb;
                  if (-1 < (int)playList[(int)sVar1].bVoice2) {
                    (&voiceList)[(int)playList[(int)sVar1].bVoice2].wFlags =
                         (&voiceList)[(int)playList[(int)sVar1].bVoice2].wFlags & 0xfffb;
                  }
                }
              }
            }
            goto LAB_800a0b18;
          }
LAB_800a0b28:
          if ((p_Var4->wFlags & 4U) == 0) {
            p_Var4->wDelay = p_Var4->wDelay + -1;
          }
        }
        uVar5 = uVar5 + 1;
        p_Var4 = p_Var4 + 1;
      } while ((int)uVar5 < 0x18);
      if (0 < (int)uVar6) {
        SpuSetKey(1,uVar6);
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ Sound_Play(struct _VoiceSetting *Set /*$s4*/)
 // line 887, offset 0x800a0b94
	/* begin block 1 */
		// Start line: 888
		// Start offset: 0x800A0B94
		// Variables:
	// 		long dwMulti; // $s5
	// 		int wVoice; // $s0
	// 		int wPlayId; // $s3
	/* end block 1 */
	// End offset: 0x800A0E24
	// End Line: 975

	/* begin block 2 */
		// Start line: 2098
	/* end block 2 */
	// End Line: 2099

short Sound_Play(_VoiceSetting *Set)

{
  int wPlayId;
  int dwVoice;
  short sVar1;
  long dwMulti;
  int dwVoice_00;
  
  if (bInitOkG != '\0') {
    wPlayId = Sound_GetFreePlayId();
    if (wPlayId < -1) {
      return -1;
    }
    dwVoice = Set->wSampleId;
    if (dwVoice < 0) {
      return -1;
    }
    dwMulti = (&EffectList)[dwVoice].dwMulti;
    sVar1 = (short)wPlayId;
    (&EffectList)[dwVoice].wPlayId = sVar1;
    playList[wPlayId].wControlFlags = 1;
    if ((&EffectList)[Set->wSampleId].loop != 0) {
      playList[wPlayId].wControlFlags = 3;
    }
    playList[wPlayId].wEffectFlags = 2;
    playList[wPlayId].bVol = (uchar)((int)((uint)Set->bVolume * (uint)Sound_MasterVol) / 0xff);
    playList[wPlayId].bLRPan = Set->bLRPan;
    playList[wPlayId].bFBPan = Set->bFBPan;
    dwVoice_00._1_2_ = *(short *)&Set->wPitch;
    playList[wPlayId].dwMulti = dwMulti;
    playList[wPlayId].wPitch = dwVoice_00._1_2_;
    dwVoice = Sound_GetFreeVoice();
    if (dwVoice != -1) {
      playList[wPlayId].bVoice1 = (char)dwVoice;
      (&voiceList)[dwVoice].wFlags = 1;
      (&voiceList)[dwVoice].wDelay = 1;
      dwVoice_00 = Set->wPitch * dwMulti;
      dwVoice_00._1_2_ = (short)((uint)dwVoice_00 >> 8);
      if (dwVoice_00 < 0) {
        dwVoice_00._1_2_ = (short)((uint)(dwVoice_00 + 0xff) >> 8);
      }
      (&voiceList)[dwVoice].wPitch = dwVoice_00._1_2_;
      (&voiceList)[dwVoice].wPlayId = sVar1;
      (&voiceList)[dwVoice].wCount = 0;
      Sound_SetVoicePitch(dwVoice,dwMulti,Set->bPitchMode);
      SpuSetVoiceStartAddr(dwVoice,(&EffectList)[Set->wSampleId].dwAddr);
      if (Sound_Mode != '\0') {
        playList[wPlayId].bVoice2 = -1;
LAB_800a0e08:
        Sound_SetPitch(wPlayId,(uint)Set->bVolume);
        Sound_SetEffectVolume(wPlayId);
        return sVar1;
      }
      (&voiceList)[dwVoice].wDelay = 2;
      dwVoice_00 = Sound_GetFreeVoice();
      if ((dwVoice_00 != -1) && (dwVoice_00 != dwVoice)) {
        playList[wPlayId].bVoice2 = (char)dwVoice_00;
        (&voiceList)[dwVoice_00].wFlags = 1;
        (&voiceList)[dwVoice_00].wDelay = 1;
        dwVoice = Set->wPitch * dwMulti;
        dwVoice_00._1_2_ = (short)((uint)dwVoice >> 8);
        if (dwVoice < 0) {
          dwVoice_00._1_2_ = (short)((uint)(dwVoice + 0xff) >> 8);
        }
        (&voiceList)[dwVoice_00].wPitch = dwVoice_00._1_2_;
        (&voiceList)[dwVoice_00].wPlayId = sVar1;
        (&voiceList)[dwVoice_00].wCount = 0;
        Sound_SetVoicePitch(dwVoice_00,dwMulti,Set->bPitchMode);
        SpuSetVoiceStartAddr(dwVoice_00,(&EffectList)[Set->wSampleId].dwAddr);
        goto LAB_800a0e08;
      }
    }
    playList[wPlayId].wControlFlags = 0;
  }
  return -1;
}



// decompiled code
// original method signature: 
// short /*$ra*/ Sound_PlayInPause(struct _VoiceSetting *Set /*$s2*/)
 // line 988, offset 0x800a0e54
	/* begin block 1 */
		// Start line: 989
		// Start offset: 0x800A0E54
		// Variables:
	// 		long dwVoice; // $s1
	// 		long i; // $a1
	// 		long j; // $a2
	// 		long FOUND; // $a3
	/* end block 1 */
	// End offset: 0x800A0FAC
	// End Line: 1042

	/* begin block 2 */
		// Start line: 2312
	/* end block 2 */
	// End Line: 2313

short Sound_PlayInPause(_VoiceSetting *Set)

{
  bool bVar1;
  bool bVar2;
  _PlayStruct *p_Var3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint dwVoice;
  
  bVar2 = false;
  if (bInitOkG != '\0') {
    iVar6 = 0;
    do {
      iVar5 = 0;
      uVar4 = (uint)(byte)bVoiceInPause;
      p_Var3 = playList;
      do {
        if ((uVar4 == (int)p_Var3->bVoice1) || (uVar4 == (int)p_Var3->bVoice2)) {
          if ((p_Var3->wControlFlags & 2U) == 0) {
            bVar2 = true;
            dwVoice = uVar4;
          }
          break;
        }
        iVar5 = iVar5 + 1;
        p_Var3 = p_Var3 + 1;
      } while (iVar5 < 0x18);
      if (iVar5 == 0x18) {
        bVar2 = true;
        dwVoice = (uint)(byte)bVoiceInPause;
      }
      bVar1 = bVoiceInPause == '\x17';
      bVoiceInPause = bVoiceInPause + '\x01';
      if (bVar1) {
        bVoiceInPause = '\0';
      }
      iVar6 = iVar6 + 1;
    } while ((iVar6 < 0x18) && (!bVar2));
    if (iVar6 != 0x18) {
      Sound_SetVoicePitch(dwVoice,(&EffectList)[Set->wSampleId].dwMulti,'\0');
      SpuSetVoiceStartAddr(dwVoice,(&EffectList)[Set->wSampleId].dwAddr);
      iVar6 = (uint)Set->bVolume << 6;
      SpuSetVoiceVolume(dwVoice,iVar6,iVar6);
      SpuSetKey(1,1 << (dwVoice & 0x1f));
      return 1;
    }
  }
  return -1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Sound_Stop(int wPlayId /*$s0*/, int wStopAll /*$a1*/)
 // line 1055, offset 0x800a0fc4
	/* begin block 1 */
		// Start line: 1056
		// Start offset: 0x800A0FC4
		// Variables:
	// 		int wTest; // $v0

		/* begin block 1.1 */
			// Start line: 1077
			// Start offset: 0x800A1030
			// Variables:
		// 		int wVoiceId; // $a0
		// 		int wVoices; // $s2
		/* end block 1.1 */
		// End offset: 0x800A10E0
		// End Line: 1120
	/* end block 1 */
	// End offset: 0x800A10E0
	// End Line: 1121

	/* begin block 2 */
		// Start line: 2504
	/* end block 2 */
	// End Line: 2505

void Sound_Stop(int wPlayId,int wStopAll)

{
  ushort uVar1;
  uint uVar2;
  uint unaff_s2;
  
  if (((bInitOkG != '\0') && (wPlayId != -1)) && ((uint)wPlayId < 0x18)) {
    uVar1 = 1;
    if (wStopAll == 0) {
      uVar1 = playList[wPlayId].wControlFlags & 2;
    }
    if (uVar1 != 0) {
      uVar2 = SEXT14(playList[wPlayId].bVoice1);
      if ((int)(&voiceList)[uVar2].wPlayId == wPlayId) {
        unaff_s2 = 1 << (uVar2 & 0x1f);
        (&voiceList)[uVar2].wFlags = 0;
        SpuSetVoiceVolume(uVar2,0,0);
      }
      uVar2 = SEXT14(playList[wPlayId].bVoice2);
      if ((-1 < (int)uVar2) && ((int)(&voiceList)[uVar2].wPlayId == wPlayId)) {
        unaff_s2 = unaff_s2 | 1 << (uVar2 & 0x1f);
        (&voiceList)[uVar2].wFlags = 0;
        SpuSetVoiceVolume(uVar2,0,0);
      }
      SpuSetKey(0,unaff_s2);
      playList[wPlayId].wControlFlags = 0;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Sound_StopTask()
 // line 1130, offset 0x800a10fc
	/* begin block 1 */
		// Start line: 1131
		// Start offset: 0x800A10FC
		// Variables:
	// 		long wPlayId; // $s3
	// 		long wStopAll; // $s6
	// 		long i; // $s0
	// 		long j; // $t0
	// 		long wVoices; // $s7
	// 		long wVoice1; // $s2
	// 		long wVoice2; // $s1
	// 		short wVol1[2]; // stack offset -72
	// 		short wVol2[2]; // stack offset -64
	// 		short wVolStep1[2]; // stack offset -56
	// 		short wVolStep2[2]; // stack offset -48
	/* end block 1 */
	// End offset: 0x800A1400
	// End Line: 1204

	/* begin block 2 */
		// Start line: 2657
	/* end block 2 */
	// End Line: 2658

/* WARNING: Removing unreachable block (ram,0x800a128c) */
/* WARNING: Removing unreachable block (ram,0x800a1294) */
/* WARNING: Removing unreachable block (ram,0x800a120c) */
/* WARNING: Removing unreachable block (ram,0x800a1214) */
/* WARNING: Removing unreachable block (ram,0x800a11d8) */
/* WARNING: Removing unreachable block (ram,0x800a11e0) */
/* WARNING: Removing unreachable block (ram,0x800a11c8) */
/* WARNING: Removing unreachable block (ram,0x800a11fc) */
/* WARNING: Removing unreachable block (ram,0x800a127c) */
/* WARNING: Removing unreachable block (ram,0x800a12b0) */
/* WARNING: Removing unreachable block (ram,0x800a12c0) */
/* WARNING: Removing unreachable block (ram,0x800a12c8) */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Sound_StopTask(void)

{
  short sVar1;
  ushort *puVar2;
  ushort *puVar3;
  short *psVar4;
  short *psVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  void *pvVar9;
  int iVar10;
  uint unaff_s7;
  ushort local_48;
  ushort local_46 [3];
  ushort local_40;
  ushort local_3e [3];
  short local_38;
  short local_36;
  short local_30;
  short local_2e;
  
  pvVar9 = TaskCurrent->local;
  iVar10 = TaskCurrent->s0;
  memset(&local_48,0,4);
  memset(&local_40,0,4);
  uVar8 = SEXT14(playList[(int)pvVar9].bVoice1);
  if ((void *)(int)(&voiceList)[uVar8].wPlayId == pvVar9) {
    unaff_s7 = 1 << (uVar8 & 0x1f);
    (&voiceList)[uVar8].wFlags = 8;
    SpuGetVoiceVolume(uVar8,&local_48,local_46);
    local_38 = (short)local_48 / 6;
    local_36 = (short)local_46[0] / 6;
  }
  uVar7 = SEXT14(playList[(int)pvVar9].bVoice2);
  if ((-1 < (int)uVar7) && ((void *)(int)(&voiceList)[uVar7].wPlayId == pvVar9)) {
    unaff_s7 = unaff_s7 | 1 << (uVar7 & 0x1f);
    (&voiceList)[uVar7].wFlags = 8;
    SpuGetVoiceVolume(uVar7,&local_40,local_3e);
    local_30 = (short)local_40 / 6;
    local_2e = (short)local_3e[0] / 6;
  }
  if ((local_38 != 0) && (iVar10 == 0)) {
    iVar10 = 5;
    do {
      iVar6 = 0;
      psVar5 = &local_30;
      puVar2 = &local_48;
      puVar3 = &local_40;
      psVar4 = &local_38;
      do {
        sVar1 = *psVar4;
        psVar4 = psVar4 + 1;
        iVar6 = iVar6 + 1;
        *puVar2 = *puVar2 - sVar1;
        sVar1 = *psVar5;
        psVar5 = psVar5 + 1;
        puVar2 = puVar2 + 1;
        *puVar3 = *puVar3 - sVar1;
        puVar3 = puVar3 + 1;
      } while (iVar6 < 2);
      if ((-1 < (int)uVar8) && (0 < (int)(short)local_48)) {
        SpuSetVoiceVolume(uVar8,(int)(short)local_48,(int)(short)local_46[0]);
      }
      if ((-1 < (int)uVar7) && (0 < (int)(short)local_40)) {
        SpuSetVoiceVolume(uVar7,(int)(short)local_40,(int)(short)local_3e[0]);
      }
      iVar10 = iVar10 + -1;
      Task_Next();
    } while (iVar10 != -1);
  }
  if (-1 < (int)uVar8) {
    (&voiceList)[uVar8].wFlags = 0;
    SpuSetVoiceVolume(uVar8,0,0);
  }
  if (-1 < (int)uVar7) {
    (&voiceList)[uVar7].wFlags = 0;
    SpuSetVoiceVolume(uVar7,0,0);
  }
  SpuSetKey(0,unaff_s7);
  playList[(int)pvVar9].wControlFlags = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Sound_Update(struct _VoiceSetting *Set /*$a1*/)
 // line 1218, offset 0x800a1454
	/* begin block 1 */
		// Start line: 1219
		// Start offset: 0x800A1454
		// Variables:
	// 		short wPlayId; // $v1
	/* end block 1 */
	// End offset: 0x800A14F8
	// End Line: 1237

	/* begin block 2 */
		// Start line: 2859
	/* end block 2 */
	// End Line: 2860

void Sound_Update(_VoiceSetting *Set)

{
  int wPlayId;
  
  if (bInitOkG != '\0') {
    wPlayId = (int)(short)*(ushort *)&Set->wSampleId;
    if ((wPlayId != -1) && (*(ushort *)&Set->wSampleId < 0x18)) {
      playList[wPlayId].bLRPan = Set->bLRPan;
      playList[wPlayId].bFBPan = Set->bFBPan;
      playList[wPlayId].bVol = (uchar)((int)((uint)Set->bVolume * (uint)Sound_MasterVol) / 0xff);
      Sound_SetPitch(wPlayId,(uint)Set->bVolume);
      Sound_SetEffectVolume(wPlayId);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Sound_SetVol(int wPlayId /*$a0*/, unsigned char bVolume /*$a1*/)
 // line 1252, offset 0x800a1508
	/* begin block 1 */
		// Start line: 2931
	/* end block 1 */
	// End Line: 2932

void Sound_SetVol(int wPlayId,uchar bVolume)

{
  if (((bInitOkG != '\0') && (wPlayId != -1)) && ((uint)wPlayId < 0x18)) {
    if ((playList[wPlayId].wControlFlags & 2U) != 0) {
      playList[wPlayId].bVol = (uchar)((int)((uint)bVolume * (uint)Sound_MasterVol) / 0xff);
      Sound_SetEffectVolume(wPlayId);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Sound_SetPitch(long wPlayId /*$s0*/, long dwVol /*$a1*/)
 // line 1280, offset 0x800a1594
	/* begin block 1 */
		// Start line: 1281
		// Start offset: 0x800A1594
		// Variables:
	// 		long dwMulti; // $a2
	// 		long dwVoice; // $a0
	// 		short wPitch; // $a3
	// 		short wDoppler; // $v1
	/* end block 1 */
	// End offset: 0x800A1714
	// End Line: 1328

	/* begin block 2 */
		// Start line: 2991
	/* end block 2 */
	// End Line: 2992

void Sound_SetPitch(long wPlayId,long dwVol)

{
  int iVar1;
  short in_a3;
  short sVar2;
  
  if (bInitOkG == '\0') {
    return;
  }
  if (wPlayId == -1) {
    return;
  }
  if (0x17 < (uint)wPlayId) {
    return;
  }
  if ((playList[wPlayId].wControlFlags & 2U) == 0) {
    return;
  }
  iVar1 = playList[wPlayId].dwMulti;
  if (iVar1 == 4) {
    return;
  }
  if ((int)(&voiceList)[(int)playList[wPlayId].bVoice1].wPlayId != wPlayId) {
    return;
  }
  if (iVar1 == 1) {
    sVar2 = 0x800;
  }
  else {
    if (iVar1 < 2) {
      if (iVar1 != 0) {
        iVar1 = (int)in_a3;
        goto LAB_800a1678;
      }
      sVar2 = 0x1000;
    }
    else {
      if (iVar1 == 2) {
        sVar2 = 0x400;
      }
      else {
        if (iVar1 != 3) {
          iVar1 = (int)in_a3;
          goto LAB_800a1678;
        }
        sVar2 = 0x300;
      }
    }
  }
  iVar1 = (int)sVar2;
LAB_800a1678:
  sVar2 = (short)((dwVol * iVar1) / 0x2fd) + (short)((iVar1 << 1) / 3);
  SpuSetVoicePitch((int)playList[wPlayId].bVoice1,sVar2);
  iVar1 = (int)playList[wPlayId].bVoice2;
  if ((-1 < iVar1) && ((int)(&voiceList)[iVar1].wPlayId == wPlayId)) {
    SpuSetVoicePitch(iVar1,sVar2);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Sound_SetEffectVolume(int wPlayId /*$a0*/)
 // line 1340, offset 0x800a1728
	/* begin block 1 */
		// Start line: 3113
	/* end block 1 */
	// End Line: 3114

void Sound_SetEffectVolume(int wPlayId)

{
  if (Sound_Mode == '\x01') {
    Sound_SetStereoVolume(wPlayId);
  }
  else {
    if (Sound_Mode < 2) {
      if (Sound_Mode == '\0') {
        Sound_SetDolbyVolume(wPlayId);
      }
    }
    else {
      if (Sound_Mode == '\x02') {
        Sound_SetMonoVolume(wPlayId);
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Sound_SetMonoVolume(long wPlayId /*$a0*/)
 // line 1363, offset 0x800a179c
	/* begin block 1 */
		// Start line: 1364
		// Start offset: 0x800A179C
		// Variables:
	// 		long wVolume; // $v1
	// 		long wVoice; // $a3
	/* end block 1 */
	// End offset: 0x800A17FC
	// End Line: 1379

	/* begin block 2 */
		// Start line: 3159
	/* end block 2 */
	// End Line: 3160

void Sound_SetMonoVolume(long wPlayId)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (int)playList[wPlayId].bVoice1;
  iVar1 = (uint)playList[wPlayId].bVol << 6;
  if ((int)(&voiceList)[iVar2].wPlayId == wPlayId) {
    (&voiceList)[iVar2].wLeftVol = (short)iVar1;
    (&voiceList)[iVar2].wRightVol = (short)iVar1;
    SpuSetVoiceVolume(iVar2,iVar1,iVar1);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Sound_SetStereoVolume(long wPlayId /*$a3*/)
 // line 1388, offset 0x800a180c
	/* begin block 1 */
		// Start line: 1389
		// Start offset: 0x800A180C
		// Variables:
	// 		long wVolume; // $a1
	// 		long wVoice; // $a0
	// 		long wLRPan; // $a0
	// 		long wLeftVol; // $a1
	// 		long wRightVol; // $a2
	/* end block 1 */
	// End offset: 0x800A18D4
	// End Line: 1418

	/* begin block 2 */
		// Start line: 3220
	/* end block 2 */
	// End Line: 3221

void Sound_SetStereoVolume(long wPlayId)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = (uint)playList[wPlayId].bVol * 0x40;
  iVar3 = (uint)playList[wPlayId].bVol * -0x40;
  if ((playList[wPlayId].wEffectFlags & 1U) == 0) {
    iVar3 = iVar2 * (uint)pbStereoLookup[0x1e - (uint)playList[wPlayId].bLRPan];
    iVar2 = (int)(iVar2 * (uint)pbStereoLookup[(uint)playList[wPlayId].bLRPan]) >> 8;
    iVar3 = iVar3 >> 8;
  }
  iVar1 = (int)playList[wPlayId].bVoice1;
  if ((int)(&voiceList)[iVar1].wPlayId == wPlayId) {
    (&voiceList)[iVar1].wLeftVol = (short)iVar2;
    (&voiceList)[iVar1].wRightVol = (short)iVar3;
    SpuSetVoiceVolume(iVar1,iVar2,iVar3);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Sound_SetDolbyVolume(int wPlayId /*$s5*/)
 // line 1427, offset 0x800a18e4
	/* begin block 1 */
		// Start line: 1428
		// Start offset: 0x800A18E4
		// Variables:
	// 		int wVolume; // $a2
	// 		int wLeftVol; // $t0
	// 		int wRightVol; // $a3
	// 		int wRearVol; // $a1
	// 		int wRearLeftVol; // $s2
	// 		int wRearRightVol; // $s3
	// 		int wVoice; // $a0
	// 		int wFlags; // $s1
	// 		int wLRPan; // $a3
	// 		int wFBPan; // $a0
	/* end block 1 */
	// End offset: 0x800A1B04
	// End Line: 1506

	/* begin block 2 */
		// Start line: 3313
	/* end block 2 */
	// End Line: 3314

void Sound_SetDolbyVolume(int wPlayId)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  short sVar6;
  short sVar7;
  uint uVar8;
  short sVar9;
  short sVar10;
  
  bVar1 = playList[wPlayId].bFBPan;
  uVar2 = playList[wPlayId].wEffectFlags;
  uVar8 = (uint)playList[wPlayId].bLRPan;
  iVar5 = (uint)playList[wPlayId].bVol * 0x40;
  iVar4 = iVar5;
  if ((uVar2 & 2) != 0) {
    if (bVar1 < 0xf) {
      iVar3 = (uint)bVar1 - 5;
      if (iVar3 < 0) {
        iVar3 = 0;
      }
      iVar4 = iVar5;
      iVar5 = (iVar5 * iVar3) / 0xf;
    }
    else {
      iVar4 = iVar5;
      if (0xf < bVar1) {
        iVar4 = (int)(iVar5 * (0x1f - (uint)bVar1)) / 0xf;
      }
    }
  }
  sVar10 = (short)(iVar4 * (uint)pbRearLookup[uVar8] >> 8);
  sVar9 = (short)(iVar5 * (uint)pbStereoLookup[uVar8] >> 8);
  sVar7 = (short)(iVar5 * (uint)pbStereoLookup[-uVar8 + 0x1e] >> 8);
  sVar6 = (short)(iVar4 * (uint)pbRearLookup[-uVar8 + 0x1e] >> 8);
  if (((uVar2 & 3) == 1) && (Sound_Mode != '\x02')) {
    sVar7 = -sVar6;
    sVar9 = sVar10;
  }
  iVar4 = (int)playList[wPlayId].bVoice1;
  if ((int)(&voiceList)[iVar4].wPlayId == wPlayId) {
    (&voiceList)[iVar4].wLeftVol = sVar9;
    (&voiceList)[iVar4].wRightVol = sVar7;
    SpuSetVoiceVolume(iVar4,(int)sVar9,(int)sVar7);
  }
  if ((Sound_Mode == '\0') && ((uVar2 & 2) != 0)) {
    iVar4 = (int)playList[wPlayId].bVoice2;
    sVar6 = -sVar6;
    if ((int)(&voiceList)[iVar4].wPlayId == wPlayId) {
      (&voiceList)[iVar4].wLeftVol = sVar10;
      (&voiceList)[iVar4].wRightVol = sVar6;
      SpuSetVoiceVolume(iVar4,(int)sVar10,(int)sVar6);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ Sound_GetFreePlayId()
 // line 1516, offset 0x800a1b28
	/* begin block 1 */
		// Start line: 1518
		// Start offset: 0x800A1B28
		// Variables:
	// 		int wPlayId; // $v1
	/* end block 1 */
	// End offset: 0x800A1B74
	// End Line: 1530

	/* begin block 2 */
		// Start line: 3528
	/* end block 2 */
	// End Line: 3529

/* WARNING: Unknown calling convention yet parameter storage is locked */

int Sound_GetFreePlayId(void)

{
  _PlayStruct *p_Var1;
  int iVar2;
  int iVar3;
  _PlayStruct *p_Var4;
  
  iVar3 = 0;
  if ((playList[0].wControlFlags & 1U) != 0) {
    iVar2 = 1;
    p_Var4 = playList;
    do {
      iVar3 = iVar2;
      if (iVar3 == 0x18) {
        return -1;
      }
      p_Var1 = p_Var4 + 1;
      iVar2 = iVar3 + 1;
      p_Var4 = p_Var4 + 1;
    } while ((p_Var1->wControlFlags & 1U) != 0);
  }
  return iVar3;
}



// decompiled code
// original method signature: 
// int /*$ra*/ Sound_GetFreeVoice()
 // line 1540, offset 0x800a1b7c
	/* begin block 1 */
		// Start line: 1542
		// Start offset: 0x800A1B7C
		// Variables:
	// 		int wVoice; // $a0
	// 		int wFound; // $a2
	// 		int wPlayId; // $v0
	/* end block 1 */
	// End offset: 0x800A1C38
	// End Line: 1596

	/* begin block 2 */
		// Start line: 3579
	/* end block 2 */
	// End Line: 3580

/* WARNING: Unknown calling convention yet parameter storage is locked */

int Sound_GetFreeVoice(void)

{
  bool bVar1;
  int iVar2;
  _VoiceStruct *p_Var3;
  int iVar4;
  
  bVar1 = true;
  iVar4 = 0;
  if ((voiceList.wFlags & 1U) != 0) {
    p_Var3 = &voiceList;
    iVar2 = 1;
    do {
      iVar4 = iVar2;
      p_Var3 = p_Var3 + 1;
      if (iVar4 == 0x18) {
        bVar1 = false;
        break;
      }
      iVar2 = iVar4 + 1;
    } while ((p_Var3->wFlags & 1U) != 0);
  }
  if (!bVar1) {
    iVar4 = 0;
    p_Var3 = &voiceList;
    while ((playList[(int)p_Var3->wPlayId].wControlFlags & 2U) != 0) {
      iVar4 = iVar4 + 1;
      p_Var3 = p_Var3 + 1;
      if ((iVar4 == 0x18) || (bVar1)) goto LAB_800a1c2c;
    }
    bVar1 = true;
LAB_800a1c2c:
    if (!bVar1) {
      iVar4 = -1;
    }
  }
  return iVar4;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Sound_GetPanLRFB(struct SOUND_7fake *pos /*$s0*/, char *PanLR /*$s1*/, char *PanFB /*$s2*/)
 // line 1606, offset 0x800a1c40
	/* begin block 1 */
		// Start line: 1607
		// Start offset: 0x800A1C40
		// Variables:
	// 		static struct SOUND_6fake dummy; // offset 0x800b4198
	// 		long f; // stack offset -24
	/* end block 1 */
	// End offset: 0x800A1D68
	// End Line: 1620

	/* begin block 2 */
		// Start line: 3704
	/* end block 2 */
	// End Line: 3705

void Sound_GetPanLRFB(undefined pos,char *PanLR,char *PanFB)

{
  _TMD_2D *p_Var1;
  short sVar2;
  undefined4 in_zero;
  short sVar3;
  undefined3 in_register_00000011;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  
  puVar4 = (undefined4 *)CONCAT31(in_register_00000011,pos);
  GtxTmd_RotTransPersN(puVar4,Tmd_2D,1);
  sVar2 = Scr_W;
  p_Var1 = Tmd_2D;
  sVar3 = Tmd_2D->vx;
  if (Tmd_2D->vx < 0) {
    sVar3 = 0;
  }
  iVar6 = (int)Scr_W;
  Tmd_2D->vx = sVar3;
  if (iVar6 < (int)sVar3) {
    sVar3 = sVar2;
  }
  if (iVar6 == 0) {
    trap(0x1c00);
  }
  if ((iVar6 == -1) && ((int)sVar3 * 0x1e == -0x80000000)) {
    trap(0x1800);
  }
  p_Var1->vx = sVar3;
  *PanLR = (char)(((int)sVar3 * 0x1e) / iVar6);
  setCopReg(2,in_zero,*puVar4);
  setCopReg(2,0x80000000,puVar4[1]);
  copFunction(2,0x480012);
  dummy_72 = getCopReg(2,0x19);
  DAT_800b419c = getCopReg(2,0x1a);
  iVar6 = getCopReg(2,0x1b);
  getCopControlWord(2,0xf800);
  iVar5 = -0x4b0;
  if (-0x4b1 < iVar6) {
    iVar5 = iVar6;
  }
  DAT_800b41a0 = 0x4b0;
  if (iVar5 < 0x4b1) {
    DAT_800b41a0 = iVar5;
  }
  *PanFB = (char)(DAT_800b41a0 / 0x50) + '\x0f';
  return;
}



// decompiled code
// original method signature: 
// char /*$ra*/ Sound_GetVolFromDist(struct SOUND_7fake *pos /*$a0*/, struct SOUND_7fake *reference /*$a1*/, long curve /*$a2*/)
 // line 1631, offset 0x800a1da8
	/* begin block 1 */
		// Start line: 1632
		// Start offset: 0x800A1DA8
		// Variables:
	// 		struct SOUND_6fake temp1; // stack offset -48
	// 		struct SOUND_6fake temp2; // stack offset -32
	// 		long d; // $v1
	// 		long mindist; // $s1
	// 		long maxdist; // $s0
	// 		char Vol; // $s2
	/* end block 1 */
	// End offset: 0x800A1EC8
	// End Line: 1657

	/* begin block 2 */
		// Start line: 3760
	/* end block 2 */
	// End Line: 3761

char Sound_GetVolFromDist(undefined pos,undefined reference,long curve)

{
  int iVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  undefined3 in_register_00000011;
  short *psVar6;
  uint uVar7;
  undefined3 in_register_00000015;
  short *psVar8;
  undefined4 in_t1;
  undefined4 in_t2;
  undefined4 in_t3;
  uint uVar9;
  int iVar10;
  
  psVar8 = (short *)CONCAT31(in_register_00000015,reference);
  psVar6 = (short *)CONCAT31(in_register_00000011,pos);
  iVar10 = 600;
  if (curve != 0) {
    iVar10 = 0x5dc;
  }
  uVar9 = 0x4b0;
  if (curve != 0) {
    uVar9 = 2000;
  }
  bVar4 = 0xff;
  if (psVar6 != (short *)0x0) {
    setCopReg(2,in_t1,(int)*psVar8 - (int)*psVar6);
    setCopReg(2,in_t2,(int)psVar8[1] - (int)psVar6[1]);
    setCopReg(2,in_t3,(int)psVar8[2] - (int)psVar6[2]);
    copFunction(2,0xa00428);
    iVar1 = getCopReg(2,0x19);
    iVar2 = getCopReg(2,0x1a);
    iVar3 = getCopReg(2,0x1b);
    uVar5 = SquareRoot0(iVar1 + iVar2 + iVar3);
    uVar7 = uVar9;
    if ((int)uVar5 < (int)uVar9) {
      uVar7 = uVar5;
    }
    bVar4 = 0xff;
    if (iVar10 <= (int)uVar7) {
      iVar1 = (uVar7 - iVar10) * 0xff;
      iVar10 = uVar9 - iVar10;
      if (iVar10 == 0) {
        trap(0x1c00);
      }
      if ((iVar10 == -1) && (iVar1 == -0x80000000)) {
        trap(0x1800);
      }
      bVar4 = ~(byte)(iVar1 / iVar10);
    }
  }
  return (char)bVar4;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Sound_IsON(int wSampleId /*$a0*/)
 // line 1669, offset 0x800a1ee4
	/* begin block 1 */
		// Start line: 3845
	/* end block 1 */
	// End Line: 3846

long Sound_IsON(int wSampleId)

{
  return (uint)(~(&EffectList)[wSampleId].wPlayId != 0);
}



// decompiled code
// original method signature: 
// void /*$ra*/ Sound_PlayCd(short wTrack /*$a0*/, short wChannel /*$a1*/)
 // line 1687, offset 0x800a1f10
	/* begin block 1 */
		// Start line: 3881
	/* end block 1 */
	// End Line: 3882

void Sound_PlayCd(short wTrack,short wChannel)

{
  if (Sound_CdHandle == (TASK *)0x0) {
    Sound_CdHandle = Task_Link(Sound_PlayCdTask,0x300);
    Sound_CdHandle->s0 = (int)wTrack;
    Sound_CdHandle->s1 = (int)wChannel;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Sound_PlayCdTask()
 // line 1704, offset 0x800a1f70
	/* begin block 1 */
		// Start line: 1705
		// Start offset: 0x800A1F70
		// Variables:
	// 		short wTrack; // $v0
	// 		short wChannel; // $v1
	/* end block 1 */
	// End offset: 0x800A1FC0
	// End Line: 1718

	/* begin block 2 */
		// Start line: 3917
	/* end block 2 */
	// End Line: 3918

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Sound_PlayCdTask(void)

{
  short wTrack;
  short wChannel;
  TASK *pTVar1;
  
  pTVar1 = TaskCurrent;
  TaskCurrent->destructor = Sound_PlayCdDestructor;
  wTrack = *(short *)&pTVar1->s0;
  wChannel = *(short *)&pTVar1->s1;
  do {
    Sound_ReadCdTrack(wTrack,wChannel);
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Sound_ReadCdTrack(short wTrack /*$s0*/, short wChannel /*$s4*/)
 // line 1729, offset 0x800a1fc0
	/* begin block 1 */
		// Start line: 1730
		// Start offset: 0x800A1FC0
		// Variables:
	// 		struct SOUND_1fake filter; // stack offset -72
	// 		struct SOUND_3fake fp; // stack offset -64
	// 		unsigned long EndPos; // $s3
	// 		unsigned char param[4]; // stack offset -40
	// 		unsigned char status[8]; // stack offset -32
	/* end block 1 */
	// End offset: 0x800A2198
	// End Line: 1793

	/* begin block 2 */
		// Start line: 3988
	/* end block 2 */
	// End Line: 3989

void Sound_ReadCdTrack(short wTrack,short wChannel)

{
  int iVar1;
  uint uVar2;
  undefined local_48;
  undefined local_47;
  undefined4 uStack64;
  uint local_3c;
  undefined local_28 [8];
  byte abStack32 [8];
  
  if (File_Used != 0) {
    do {
      Task_Next();
    } while (File_Used != 0);
  }
  File_Used = 1;
  CdSearchFile(&uStack64,Sound_TrackNames + (int)wTrack * 0x28);
  iVar1 = CdPosToInt((byte *)&uStack64);
  local_28[0] = 0x49;
  CdControl(0xe,local_28,(undefined *)0x0);
  local_48 = 1;
  local_47 = (undefined)wChannel;
  CdControl(0xd,&local_48,abStack32);
  CdControlF(0x1b,(undefined *)&uStack64);
  File_Used = 0;
  Sound_SetCdVolume(Sound_CdVol);
  while ((uVar2 = CdControlB(0x10,(undefined *)0x0,abStack32), uVar2 == 0 ||
         (uVar2 = CdPosToInt(abStack32),
         uVar2 <= (iVar1 + (uint)((ulonglong)(local_3c >> 2) * 0x70070071 >> 0x28)) - 0x3c))) {
    if (Sound_FlagPaused != '\0') {
      Sound_SetCdVolume('\0');
      CdControl(9,(undefined *)0x0,(undefined *)0x0);
      while (Sound_FlagPaused != '\0') {
        Task_Next();
      }
      Sound_SetCdVolume(Sound_CdVol);
      CdControlF(0x1b,abStack32);
    }
    Task_Next();
  }
  Sound_SetCdVolume('\0');
  while (Sound_FlagPaused != '\0') {
    Task_Next();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Sound_StopCd()
 // line 1802, offset 0x800a21b8
	/* begin block 1 */
		// Start line: 4150
	/* end block 1 */
	// End Line: 4151

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Sound_StopCd(void)

{
  if (Sound_CdHandle != (TASK *)0x0) {
    Task_Kill(Sound_CdHandle);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Sound_PlayCdDestructor()
 // line 1816, offset 0x800a21e0
	/* begin block 1 */
		// Start line: 4178
	/* end block 1 */
	// End Line: 4179

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Sound_PlayCdDestructor(void)

{
  Sound_SetCdVolume('\0');
  Sound_CdHandle = (TASK *)0x0;
  return;
}



// decompiled code
// original method signature: 
// void SpuInitMalloc() /* SpuInitMalloc method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 2364, offset 0x800a2200
int SpuInitMalloc(int param_1,undefined4 *param_2)

{
  uint uVar1;
  
  uVar1 = _spu_mem_mode_plus;
  if (param_1 < 1) {
    param_1 = 0;
  }
  else {
    *param_2 = 0x40001010;
    _spu_AllocLastNum = 0;
    _spu_AllocBlockNum = param_1;
    _spu_memList = param_2;
    param_2[1] = (0x10000 << (uVar1 & 0x1f)) + -0x1010;
  }
  return param_1;
}





