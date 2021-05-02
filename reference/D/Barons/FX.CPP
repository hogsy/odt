#include "THISDUST.H"
#include "FX.H"


// decompiled code
// original method signature: 
// short /*$ra*/ Fx_Play_Sample(short Fx /*$a0*/, struct FX_7fake *pos /*$a1*/, struct FX_7fake *orig /*$a2*/, long VolumeMode /*$a3*/)
 // line 24, offset 0x800650fc
	/* begin block 1 */
		// Start line: 25
		// Start offset: 0x800650FC
		// Variables:
	// 		struct _VoiceSetting Set; // stack offset -24
	/* end block 1 */
	// End offset: 0x80065144
	// End Line: 46

	/* begin block 2 */
		// Start line: 48
	/* end block 2 */
	// End Line: 49

short Fx_Play_Sample(short Fx,undefined1 pos,undefined orig,long VolumeMode)

{
  short sVar1;
  long lVar2;
  undefined3 in_register_00000019;
  undefined4 uVar3;
  
  uVar3 = CONCAT31(in_register_00000019,orig);
  lVar2 = Fx_GetVolume((_VoiceSetting *)&stack0xffffffe8,pos,orig,VolumeMode);
  if (lVar2 == 0) {
    sVar1 = -1;
  }
  else {
    sVar1 = Task_CallSys(Sound_Play,&stack0xffffffe8,uVar3,VolumeMode,(int)Fx);
  }
  return sVar1;
}



// decompiled code
// original method signature: 
// short /*$ra*/ Fx_Play(short Fx /*$a0*/, struct FX_7fake *pos /*$a1*/)
 // line 49, offset 0x80065154
	/* begin block 1 */
		// Start line: 50
		// Start offset: 0x80065154
	/* end block 1 */
	// End offset: 0x80065154
	// End Line: 50

	/* begin block 2 */
		// Start line: 108
	/* end block 2 */
	// End Line: 109

short Fx_Play(short Fx,undefined1 pos)

{
  short sVar1;
  
  sVar1 = Fx_Play_Sample(Fx,pos,0x70,0);
  return sVar1;
}



// decompiled code
// original method signature: 
// short /*$ra*/ Fx_PlayLoud(short Fx /*$a0*/, struct FX_7fake *pos /*$a1*/)
 // line 65, offset 0x80065188
	/* begin block 1 */
		// Start line: 66
		// Start offset: 0x80065188
	/* end block 1 */
	// End offset: 0x80065188
	// End Line: 66

	/* begin block 2 */
		// Start line: 150
	/* end block 2 */
	// End Line: 151

short Fx_PlayLoud(short Fx,undefined1 pos)

{
  short sVar1;
  
  sVar1 = Fx_Play_Sample(Fx,pos,0x70,1);
  return sVar1;
}



// decompiled code
// original method signature: 
// short /*$ra*/ Fx_PlaySoft(short Fx /*$a0*/, struct FX_7fake *pos /*$a1*/)
 // line 81, offset 0x800651bc
	/* begin block 1 */
		// Start line: 82
		// Start offset: 0x800651BC
	/* end block 1 */
	// End offset: 0x800651BC
	// End Line: 82

	/* begin block 2 */
		// Start line: 192
	/* end block 2 */
	// End Line: 193

short Fx_PlaySoft(short Fx,undefined1 pos)

{
  short sVar1;
  
  sVar1 = Fx_Play_Sample(Fx,pos,0x70,2);
  return sVar1;
}



// decompiled code
// original method signature: 
// short /*$ra*/ Fx_Play_Camera(short Fx /*$a0*/, struct FX_7fake *pos /*$a1*/)
 // line 97, offset 0x800651f0
	/* begin block 1 */
		// Start line: 98
		// Start offset: 0x800651F0
	/* end block 1 */
	// End offset: 0x800651F0
	// End Line: 98

	/* begin block 2 */
		// Start line: 234
	/* end block 2 */
	// End Line: 235

short Fx_Play_Camera(short Fx,undefined1 pos)

{
  short sVar1;
  
  sVar1 = Fx_Play_Sample(Fx,pos,0x68,0);
  return sVar1;
}



// decompiled code
// original method signature: 
// short /*$ra*/ Fx_PlayInPause(short Fx /*$a0*/, struct FX_7fake *pos /*$a1*/)
 // line 112, offset 0x80065224
	/* begin block 1 */
		// Start line: 113
		// Start offset: 0x80065224
		// Variables:
	// 		struct _VoiceSetting Set; // stack offset -24
	/* end block 1 */
	// End offset: 0x80065274
	// End Line: 130

	/* begin block 2 */
		// Start line: 273
	/* end block 2 */
	// End Line: 274

short Fx_PlayInPause(short Fx,undefined pos)

{
  short sVar1;
  long lVar2;
  undefined3 in_register_00000015;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar3 = CONCAT31(in_register_00000015,pos);
  uVar4 = 0;
  lVar2 = Fx_GetVolume((_VoiceSetting *)&stack0xffffffe8,pos,pos,0);
  if (lVar2 == 0) {
    sVar1 = -1;
  }
  else {
    sVar1 = Task_CallSys(Sound_PlayInPause,&stack0xffffffe8,uVar3,uVar4,(int)Fx);
  }
  return sVar1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Fx_GetVolume(struct _VoiceSetting *Set /*$s1*/, struct FX_7fake *pos /*$s3*/, struct FX_7fake *orig /*$a2*/, long VolumeMode /*$s2*/)
 // line 137, offset 0x80065284
	/* begin block 1 */
		// Start line: 138
		// Start offset: 0x80065284
		// Variables:
	// 		char Vol; // $s0
	// 		char PanLR; // stack offset -32
	// 		char PanFB; // stack offset -31
	/* end block 1 */
	// End offset: 0x80065330
	// End Line: 161

	/* begin block 2 */
		// Start line: 334
	/* end block 2 */
	// End Line: 335

long Fx_GetVolume(_VoiceSetting *Set,undefined pos,undefined orig,long VolumeMode)

{
  bool bVar1;
  uint uVar2;
  undefined3 in_register_00000015;
  undefined3 in_register_00000019;
  undefined2 uVar3;
  undefined4 in_stack_ffffffe0;
  
  uVar2 = Task_CallSys(Sound_GetVolFromDist,CONCAT31(in_register_00000015,pos),
                       CONCAT31(in_register_00000019,orig),VolumeMode & 1,in_stack_ffffffe0);
  uVar3 = (undefined2)in_stack_ffffffe0;
  if ((VolumeMode & 2U) != 0) {
    uVar2 = (uVar2 & 0xff) / 3;
  }
  bVar1 = (uVar2 & 0xff) != 0;
  if (bVar1) {
    Task_CallSys(Sound_GetPanLRFB,CONCAT31(in_register_00000015,pos),&stack0xffffffe0,
                 &stack0xffffffe1,in_stack_ffffffe0);
    Set->bVolume = (uchar)uVar2;
    Set->wPitch = 0x100;
    Set->bLRPan = (uchar)uVar3;
    Set->bPitchMode = (byte)((uint)VolumeMode >> 2) & 1;
    Set->bFBPan = (uchar)((ushort)uVar3 >> 8);
  }
  return (uint)bVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Fx_SetVolume_Sample(short wPlayID /*$a0*/, struct FX_7fake *pos /*$a1*/, struct FX_7fake *orig /*$a2*/)
 // line 165, offset 0x8006534c
	/* begin block 1 */
		// Start line: 166
		// Start offset: 0x8006534C
		// Variables:
	// 		struct _VoiceSetting Set; // stack offset -24
	/* end block 1 */
	// End offset: 0x8006534C
	// End Line: 166

	/* begin block 2 */
		// Start line: 420
	/* end block 2 */
	// End Line: 421

void Fx_SetVolume_Sample(short wPlayID,undefined1 pos,undefined orig)

{
  undefined3 in_register_00000019;
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = CONCAT31(in_register_00000019,orig);
  uVar2 = 0;
  Fx_GetVolume((_VoiceSetting *)&stack0xffffffe8,pos,orig,0);
  Task_CallSys(Sound_Update,&stack0xffffffe8,uVar1,uVar2,(int)wPlayID);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Fx_SetVolume(short Fx /*$a0*/, struct FX_7fake *pos /*$a1*/)
 // line 183, offset 0x80065394
	/* begin block 1 */
		// Start line: 460
	/* end block 1 */
	// End Line: 461

void Fx_SetVolume(short Fx,undefined1 pos)

{
  Fx_SetVolume_Sample(Fx,pos,0x70);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Fx_SetVolume_Camera(short Fx /*$a0*/, struct FX_7fake *pos /*$a1*/)
 // line 189, offset 0x800653c0
	/* begin block 1 */
		// Start line: 473
	/* end block 1 */
	// End Line: 474

void Fx_SetVolume_Camera(short Fx,undefined1 pos)

{
  Fx_SetVolume_Sample(Fx,pos,0x68);
  return;
}





