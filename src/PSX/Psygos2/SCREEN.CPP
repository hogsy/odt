#include "THISDUST.H"
#include "SCREEN.H"


// decompiled code
// original method signature: 
// void /*$ra*/ S_AddPrim(long rang /*$a0*/, void *prim /*$a1*/)
 // line 44, offset 0x8009d4b8
	/* begin block 1 */
		// Start line: 89
	/* end block 1 */
	// End Line: 90

void S_AddPrim(long rang,void *prim)

{
  _SCREEN *p_Var1;
  
  p_Var1 = Scr;
  *(uint *)prim = *(uint *)prim & 0xff000000 | Scr->ot[rang] & 0xffffff;
  p_Var1->ot[rang] = p_Var1->ot[rang] & 0xff000000 | (uint)prim & 0xffffff;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Scr_Init()
 // line 55, offset 0x8009d514
	/* begin block 1 */
		// Start line: 56
		// Start offset: 0x8009D514
		// Variables:
	// 		long i; // $s1
	// 		struct SCREEN_21fake Total; // stack offset -24
	/* end block 1 */
	// End offset: 0x8009D5E0
	// End Line: 98

	/* begin block 2 */
		// Start line: 110
	/* end block 2 */
	// End Line: 111

/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Scr_Init(void)

{
  short sVar1;
  undefined4 local_18;
  undefined4 local_14;
  
  local_18 = DAT_800a684c;
  local_14 = DAT_800a6850;
  Scr_Frame = 0;
  Scr = &Screens;
  Scr_Flag = (_SCREEN *)0x0;
  Scr_Background = (void *)0x0;
  Screens.ot = (ulong *)0x0;
  Scr_Count = 0;
  Scr_FadeUsed = 0;
  Scr_InitZone(0,0,0x140,0x1e0,0);
  Scr_SetOtSize(0x800);
  Scr_ClearCall = 0;
  Scr_Start();
  SetVideoMode(1);
  Scr_SetSync(1);
  sVar1 = Scr_Count;
  do {
    M_rand();
  } while (Scr_Count == sVar1);
  ClearImage2(&local_18,0,0,0);
  DrawSync();
  local_18 = CONCAT22(0x100,(undefined2)local_18);
  ClearImage2(&local_18,0,0,0);
  DrawSync();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Scr_Stop()
 // line 107, offset 0x8009d630
	/* begin block 1 */
		// Start line: 108
		// Start offset: 0x8009D630
	/* end block 1 */
	// End offset: 0x8009D630
	// End Line: 108

	/* begin block 2 */
		// Start line: 265
	/* end block 2 */
	// End Line: 266

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Scr_Stop(void)

{
  EnterCriticalSection();
  StopRCnt(0xf2000003);
  DisableEvent();
  CloseEvent();
  ExitCriticalSection();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Scr_Start()
 // line 117, offset 0x8009d680
	/* begin block 1 */
		// Start line: 118
		// Start offset: 0x8009D680
	/* end block 1 */
	// End offset: 0x8009D680
	// End Line: 118

	/* begin block 2 */
		// Start line: 285
	/* end block 2 */
	// End Line: 286

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Scr_Start(void)

{
  EnterCriticalSection();
  Scr_Evbl = OpenEvent();
  EnableEvent();
  StartRCnt(0xf2000003);
  ExitCriticalSection();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Scr_Remove()
 // line 127, offset 0x8009d6e0
	/* begin block 1 */
		// Start line: 305
	/* end block 1 */
	// End Line: 306

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Scr_Remove(void)

{
  Scr_Stop();
  Scr_SetOtSize(0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Scr_InitZone(short x /*$a0*/, short y /*$a1*/, short w /*$a2*/, short h /*$t0*/, int fi /*stack 16*/)
 // line 134, offset 0x8009d708
	/* begin block 1 */
		// Start line: 135
		// Start offset: 0x8009D708
		// Variables:
	// 		struct SCREEN_21fake Total; // stack offset -48
	// 		short dy; // $s1
	/* end block 1 */
	// End offset: 0x8009D948
	// End Line: 191

	/* begin block 2 */
		// Start line: 319
	/* end block 2 */
	// End Line: 320

void Scr_InitZone(short x,short y,short w,short h,int fi)

{
  int iVar1;
  int iVar2;
  short sVar3;
  short sVar4;
  short local_30;
  short local_2e;
  short local_2c;
  short local_2a;
  
  iVar1 = (uint)(ushort)h << 0x10;
  iVar2 = iVar1 >> 0x10;
  local_2a = 0;
  iVar1 = (uint)(ushort)h - (iVar2 + ((iVar2 / 0xf0 + (iVar2 >> 0x1f)) - (iVar1 >> 0x1f)) * -0xf0);
  Screens.clipping.h = (short)iVar1;
  sVar3 = (short)fi;
  if (iVar1 * 0x10000 >> 0x10 == 0x1e0) {
    Screens.clipping.h = 0x200;
  }
  sVar4 = 0;
  if (sVar3 == 0) {
    Screens.clipping.h = Screens.clipping.h >> 1;
    sVar4 = Screens.clipping.h;
  }
  Scr_Dtd = 1;
  Screens.clipping.x = 0;
  Screens.clipping.y = 0;
  _SCREEN_800b993c.clipping.x = 0;
  _SCREEN_800b993c.clipping.y = 0;
  Scr_Dfe = sVar3;
  Screens.clipping.w = w;
  _SCREEN_800b993c.clipping.w = w;
  _SCREEN_800b993c.clipping.h = Screens.clipping.h;
  Scr_H = Screens.clipping.h;
  Scr_W = w;
  local_30 = x;
  local_2e = y;
  local_2c = w;
  SetDefDrawEnv((undefined2 *)&Screens.draw,x,y,w,(int)Screens.clipping.h);
  SetDefDrawEnv((undefined2 *)&_SCREEN_800b993c.draw,x,y + sVar4,Scr_W,(int)Scr_H);
  SetDefDispEnv((undefined2 *)&Screens.disp,x,y + sVar4,Scr_W,(int)Scr_H);
  SetDefDispEnv((undefined2 *)&_SCREEN_800b993c.disp,x,y,Scr_W,(int)Scr_H);
  _SCREEN_800b993c.draw.r0 = '\0';
  Screens.draw.r0 = '\0';
  _SCREEN_800b993c.draw.g0 = '\0';
  Screens.draw.g0 = '\0';
  _SCREEN_800b993c.draw.b0 = '\0';
  Screens.draw.b0 = '\0';
  Screens.draw.isbg = '\x01';
  _SCREEN_800b993c.draw.isbg = '\x01';
  Screens.disp.screen.y = 0x14;
  _SCREEN_800b993c.disp.screen.y = 0x14;
  Screens.disp.screen.h = 0x100;
  _SCREEN_800b993c.disp.screen.h = 0x100;
  Screens.disp.isinter = (uchar)Scr_Dfe;
  _SCREEN_800b993c.disp.isinter = (uchar)Scr_Dfe;
  Screens.draw.dfe = (uchar)Scr_Dfe;
  _SCREEN_800b993c.draw.dfe = (uchar)Scr_Dfe;
  local_2a = Scr_H;
  ClearImage(&local_30,0,0,0);
  DrawSync();
  if (sVar3 == 0) {
    local_2e = local_2e + Scr_H;
    ClearImage(&local_30,0,0,0);
    DrawSync();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Scr_SetSync(long s /*$a0*/)
 // line 194, offset 0x8009d978
	/* begin block 1 */
		// Start line: 513
	/* end block 1 */
	// End Line: 514

/* WARNING: Removing unreachable block (ram,0x8009d9a0) */

void Scr_SetSync(long s)

{
  if (s == 0) {
    trap(0x1c00);
  }
  Scr_TicksPerSecond = (short)(0x32 / s);
  Scr_Sync = (short)s;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Scr_SetOtSize(long size /*$s1*/)
 // line 211, offset 0x8009d9bc
	/* begin block 1 */
		// Start line: 546
	/* end block 1 */
	// End Line: 547

void Scr_SetOtSize(long size)

{
  if (Screens.ot != (ulong *)0x0) {
    Heap_FreeMem(Screens.ot);
  }
  _SCREEN_800b993c.ot = (ulong *)0x0;
  Screens.ot = (ulong *)0x0;
  Scr_OtSize = (short)size;
  if (size != 0) {
    Screens.ot = (ulong *)Heap_AllocMem(size << 3);
    _SCREEN_800b993c.ot = Screens.ot + size;
  }
  Scr_Clear();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Scr_Clear()
 // line 234, offset 0x8009da38
	/* begin block 1 */
		// Start line: 597
	/* end block 1 */
	// End Line: 598

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Scr_Clear(void)

{
  if (Scr->ot != (ulong *)0x0) {
    ClearOTagR(Scr->ot);
  }
  pChar = (&Tab_Char2)[(int)Scr_Frame];
  if (Scr_ClearCall != (code *)0x0) {
    (*Scr_ClearCall)();
  }
  Joy_Driver();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Scr_SetBackground(void *image /*$a0*/)
 // line 249, offset 0x8009dab4
	/* begin block 1 */
		// Start line: 633
	/* end block 1 */
	// End Line: 634

void Scr_SetBackground(void *image)

{
  if (image != (void *)0x0) {
    Screens.draw.isbg = '\0';
    _SCREEN_800b993c.draw.isbg = '\0';
    Scr_Background = image;
    return;
  }
  Screens.draw.isbg = '\x01';
  _SCREEN_800b993c.draw.isbg = '\x01';
  Scr_Background = image;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Scr_FadeVSync(long type /*$a0*/, long time /*$a1*/)
 // line 261, offset 0x8009daec
	/* begin block 1 */
		// Start line: 656
	/* end block 1 */
	// End Line: 657

void Scr_FadeVSync(long type,long time)

{
  return;
}



// decompiled code
// original method signature: 
// struct TASK * /*$ra*/ Scr_Fade(short type /*$a0*/, short time /*$a1*/)
 // line 266, offset 0x8009daf4
	/* begin block 1 */
		// Start line: 267
		// Start offset: 0x8009DAF4
		// Variables:
	// 		struct TASK *t; // $v0
	/* end block 1 */
	// End offset: 0x8009DB5C
	// End Line: 283

	/* begin block 2 */
		// Start line: 668
	/* end block 2 */
	// End Line: 669

TASK * Scr_Fade(short type,short time)

{
  TASK *pTVar1;
  
  if (Scr_FadeUsed == 0) {
    Scr_FadeUsed = 1;
    pTVar1 = Task_Add(Scr_FadeTask,0x180);
    pTVar1->destructor = Scr_FadeDestructor;
    pTVar1->s0 = (int)type;
    pTVar1->s1 = (int)time;
  }
  else {
    pTVar1 = (TASK *)0x0;
  }
  return pTVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Scr_FadeWait()
 // line 286, offset 0x8009db70
	/* begin block 1 */
		// Start line: 720
	/* end block 1 */
	// End Line: 721

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Scr_FadeWait(void)

{
  if (Scr_FadeUsed != 0) {
    do {
      Task_Next();
    } while (Scr_FadeUsed != 0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Scr_FadeTask()
 // line 293, offset 0x8009dbb4
	/* begin block 1 */
		// Start line: 294
		// Start offset: 0x8009DBB4
		// Variables:
	// 		long k; // $s1
	// 		long s; // $s1
	// 		long e; // $s6
	// 		long ik; // $s4
	// 		struct SCREEN_45fake *ptile; // $s2
	// 		struct SCREEN_45fake tiles[2]; // stack offset -88
	// 		struct SCREEN_55fake *ptpage; // $s3
	// 		struct SCREEN_55fake tpages[2]; // stack offset -56
	/* end block 1 */
	// End offset: 0x8009DD24
	// End Line: 326

	/* begin block 2 */
		// Start line: 734
	/* end block 2 */
	// End Line: 735

/* WARNING: Removing unreachable block (ram,0x8009dc14) */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Scr_FadeTask(void)

{
  bool bVar1;
  _SCREEN *p_Var2;
  int iVar3;
  uchar uVar4;
  uint uVar5;
  SCREEN_45fake *unaff_s2;
  SCREEN_55fake *unaff_s3;
  uint uVar6;
  int iVar7;
  SCREEN_45fake aSStack88 [2];
  SCREEN_55fake aSStack56 [2];
  
  iVar7 = 0xff / TaskCurrent->s1;
  if (TaskCurrent->s1 == 0) {
    trap(0x1c00);
  }
  uVar5 = 0xff;
  if (TaskCurrent->s0 == 0) {
    uVar5 = 0;
    uVar6 = 0xff;
  }
  else {
    uVar6 = 0;
    iVar7 = -iVar7;
  }
  Scr_FadeInit(aSStack56,aSStack88);
  bVar1 = uVar5 < uVar6;
  while (((p_Var2 = Scr, bVar1 && (0 < iVar7)) || (((int)uVar6 < (int)uVar5 && (iVar7 < 0))))) {
    iVar3 = (int)Scr_Frame;
    unaff_s2 = aSStack88 + iVar3;
    uVar4 = (uchar)uVar5;
    aSStack88[iVar3].b0 = uVar4;
    aSStack88[iVar3].g0 = uVar4;
    aSStack88[iVar3].r0 = uVar4;
    p_Var2 = Scr;
    unaff_s2->tag = unaff_s2->tag & 0xff000000 | Scr->ot[3] & 0xffffff;
    unaff_s3 = aSStack56 + iVar3;
    p_Var2->ot[3] = p_Var2->ot[3] & 0xff000000 | (uint)unaff_s2 & 0xffffff;
    unaff_s3->tag = unaff_s3->tag & 0xff000000 | p_Var2->ot[3] & 0xffffff;
    uVar5 = uVar5 + iVar7;
    p_Var2->ot[3] = p_Var2->ot[3] & 0xff000000 | (uint)unaff_s3 & 0xffffff;
    Task_Next();
    bVar1 = (int)uVar5 < (int)uVar6;
  }
  unaff_s2->tag = unaff_s2->tag & 0xff000000 | Scr->ot[3] & 0xffffff;
  p_Var2->ot[3] = p_Var2->ot[3] & 0xff000000 | (uint)unaff_s2 & 0xffffff;
  unaff_s3->tag = unaff_s3->tag & 0xff000000 | p_Var2->ot[3] & 0xffffff;
  Scr_FadeUsed = 0;
  p_Var2->ot[3] = p_Var2->ot[3] & 0xff000000 | (uint)unaff_s3 & 0xffffff;
  Task_Next();
  Task_Sleep(2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Scr_FadeInit(struct SCREEN_55fake *tpages /*$a0*/, struct SCREEN_45fake *tiles /*$a1*/)
 // line 334, offset 0x8009dde0
	/* begin block 1 */
		// Start line: 336
		// Start offset: 0x8009DDE0
		// Variables:
	// 		long i; // $a2
	/* end block 1 */
	// End offset: 0x8009DE3C
	// End Line: 350

	/* begin block 2 */
		// Start line: 860
	/* end block 2 */
	// End Line: 861

void Scr_FadeInit(SCREEN_55fake *tpages,SCREEN_45fake *tiles)

{
  short sVar1;
  short sVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    sVar2 = Scr_W;
    sVar1 = Scr_H;
    iVar3 = iVar3 + 1;
    tiles->x0 = 0;
    tiles->y0 = 0;
    *(undefined *)((int)&tiles->tag + 3) = 3;
    tiles->code = 'b';
    tiles->w = sVar2;
    tiles->h = sVar1;
    *(undefined *)((int)&tpages->tag + 3) = 1;
    tpages->code[0] = 0xe1000240;
    tpages = tpages + 1;
    tiles = tiles + 1;
  } while (iVar3 < 2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Scr_FadeDestructor(struct TASK *t /*$a0*/)
 // line 353, offset 0x8009de44
	/* begin block 1 */
		// Start line: 910
	/* end block 1 */
	// End Line: 911

void Scr_FadeDestructor(TASK *t)

{
  Scr_FadeUsed = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Scr_Swap()
 // line 365, offset 0x8009de50
	/* begin block 1 */
		// Start line: 933
	/* end block 1 */
	// End Line: 934

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Scr_Swap(void)

{
  _SCREEN *p_Var1;
  
  do {
    p_Var1 = Scr_GetFlag();
  } while (p_Var1 != (_SCREEN *)0x0);
  DrawSync();
  setCopControlWord(2,0xd000,(uint)(ushort)Scr_GeomScreen);
  p_Var1 = &Screens;
  if (Scr == &Screens) {
    p_Var1 = &_SCREEN_800b993c;
  }
  Scr_Flag = Scr;
  Scr = p_Var1;
  Scr_Frame = Scr_Frame ^ 1;
  return;
}



// decompiled code
// original method signature: 
// struct _SCREEN * /*$ra*/ Scr_GetFlag()
 // line 380, offset 0x8009dec0
	/* begin block 1 */
		// Start line: 968
	/* end block 1 */
	// End Line: 969

/* WARNING: Unknown calling convention yet parameter storage is locked */

_SCREEN * Scr_GetFlag(void)

{
  return Scr_Flag;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Scr_CallBack()
 // line 392, offset 0x8009ded0
	/* begin block 1 */
		// Start line: 393
		// Start offset: 0x8009DED0
	/* end block 1 */
	// End offset: 0x8009DF74
	// End Line: 422

	/* begin block 2 */
		// Start line: 991
	/* end block 2 */
	// End Line: 992

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Scr_CallBack(void)

{
  Scr_Count = Scr_Count + 1;
  if ((Scr_Flag != (_SCREEN *)0x0) && (Scr_Sync <= Scr_Count)) {
    PutDispEnv((ushort *)&Scr_Flag->disp);
    PutDrawEnv((undefined4 *)&Scr_Flag->draw);
    if (Scr_Background != (void *)0x0) {
      LoadImage(&Scr_Flag->draw,Scr_Background);
    }
    DrawOTag(Scr_Flag->ot + (int)Scr_OtSize + -1);
    Scr_Flag = (_SCREEN *)0x0;
    Scr_Count = 0;
  }
  return;
}



// decompiled code
// original method signature: 
// void SetDefDispEnv() /* SetDefDispEnv method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 638, offset 0x8009df88
void SetDefDispEnv(undefined2 *param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
                  undefined4 param_5)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = param_4;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  *(undefined *)((int)param_1 + 0x11) = 0;
  *(undefined *)(param_1 + 8) = 0;
  *(undefined *)((int)param_1 + 0x13) = 0;
  *(undefined *)(param_1 + 9) = 0;
  param_1[3] = (undefined2)param_5;
  return;
}





