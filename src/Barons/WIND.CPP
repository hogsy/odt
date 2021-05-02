#include "THISDUST.H"
#include "WIND.H"


// decompiled code
// original method signature: 
// void /*$ra*/ Wind_InitFile()
 // line 29, offset 0x80067924
	/* begin block 1 */
		// Start line: 30
		// Start offset: 0x80067924
	/* end block 1 */
	// End offset: 0x80067948
	// End Line: 49

	/* begin block 2 */
		// Start line: 59
	/* end block 2 */
	// End Line: 60

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Wind_InitFile(void)

{
  if ((Pvl_File->wind).pad != 0) {
    Winds = (_WIND *)0x0;
  }
  Wind_Handle = (TASK *)0x0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Wind_DeleteFile()
 // line 52, offset 0x80067950
	/* begin block 1 */
		// Start line: 105
	/* end block 1 */
	// End Line: 106

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Wind_DeleteFile(void)

{
  if (Wind_Handle != (TASK *)0x0) {
    Task_Kill(Wind_Handle);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Wind_GeneralTask()
 // line 59, offset 0x80067978
	/* begin block 1 */
		// Start line: 60
		// Start offset: 0x80067978
		// Variables:
	// 		struct _WIND *pwind; // $s3
	// 		short cpt; // $s0
	// 		struct WIND_7fake v1; // stack offset -40
	// 		struct WIND_7fake v2; // stack offset -32

		/* begin block 1.1 */
			// Start line: 74
			// Start offset: 0x80067A20
			// Variables:
		// 		short valx; // $s2
		// 		short valy; // $s1
		// 		short valz; // $s0
		/* end block 1.1 */
		// End offset: 0x80067BD4
		// End Line: 80
	/* end block 1 */
	// End offset: 0x80067BE4
	// End Line: 85

	/* begin block 2 */
		// Start line: 120
	/* end block 2 */
	// End Line: 121

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Wind_GeneralTask(void)

{
  int iVar1;
  long lVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  short sVar6;
  int iVar7;
  short vy;
  short vx;
  _WIND *w;
  short local_28;
  short sStack38;
  short local_24;
  
  w = (_WIND *)TaskCurrent->local;
  iVar7 = 0;
  uVar4 = *(uint *)&w->speed;
  iVar5 = *(int *)&(w->speed).vz;
  uVar3 = iVar5 << 0x10;
  iVar1 = 0;
  do {
    if (iVar1 == 0) {
      local_28 = (short)uVar4;
      vx = 0;
      if (local_28 != 0) {
        lVar2 = M_rand();
        iVar1 = (int)local_28;
        if (iVar1 == 0) {
          trap(0x1c00);
        }
        if ((iVar1 == -1) && (lVar2 == -0x80000000)) {
          trap(0x1800);
        }
        vx = (short)(lVar2 % iVar1) -
             (short)((int)(((int)(uVar4 << 0x10) >> 0x10) + ((uVar4 << 0x10) >> 0x1f)) >> 1);
      }
      sStack38 = (short)(uVar4 >> 0x10);
      vy = 0;
      if (sStack38 != 0) {
        lVar2 = M_rand();
        iVar1 = (int)sStack38;
        if (iVar1 == 0) {
          trap(0x1c00);
        }
        if ((iVar1 == -1) && (lVar2 == -0x80000000)) {
          trap(0x1800);
        }
        vy = (short)(lVar2 % iVar1) -
             (short)((int)(((int)(uVar4 & 0xffff0000) >> 0x10) + ((uVar4 & 0xffff0000) >> 0x1f)) >>
                    1);
      }
      local_24 = (short)iVar5;
      if (local_24 == 0) {
        sVar6 = 0;
      }
      else {
        lVar2 = M_rand();
        iVar1 = (int)local_24;
        if (iVar1 == 0) {
          trap(0x1c00);
        }
        if ((iVar1 == -1) && (lVar2 == -0x80000000)) {
          trap(0x1800);
        }
        sVar6 = (short)(lVar2 % iVar1) - (short)((int)(((int)uVar3 >> 0x10) + (uVar3 >> 0x1f)) >> 1)
        ;
      }
      lVar2 = M_rand();
      Wind_ChangeDir(w,(short)((uint)((lVar2 % 0x3c + 5) * 0x10000) >> 0x10),vx,vy,(int)sVar6);
      lVar2 = M_rand();
      iVar7 = lVar2 % 1000 + 0x3c;
    }
    iVar7 = iVar7 + -1;
    Task_Next();
    iVar1 = iVar7 * 0x10000;
  } while( true );
}



// decompiled code
// original method signature: 
// struct _WIND * /*$ra*/ Wind_Add(short vx /*$a0*/, short vy /*$a1*/, short vz /*$a2*/)
 // line 88, offset 0x80067be4
	/* begin block 1 */
		// Start line: 89
		// Start offset: 0x80067BE4
		// Variables:
	// 		struct _WIND *w; // $v0
	/* end block 1 */
	// End offset: 0x80067BE4
	// End Line: 89

	/* begin block 2 */
		// Start line: 194
	/* end block 2 */
	// End Line: 195

_WIND * Wind_Add(short vx,short vy,short vz)

{
  _WIND *p_Var1;
  
  p_Var1 = Wind_AddInList(&Winds);
  (p_Var1->speed).vx = vx;
  (p_Var1->speed).vy = vy;
  (p_Var1->speed).vz = vz;
  p_Var1->inf = 0;
  return p_Var1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Wind_ChangeDir(struct _WIND *w /*$s4*/, short nb_Frames /*$a1*/, short vx /*$a2*/, short vy /*$a3*/, int vz /*stack 16*/)
 // line 104, offset 0x80067c38
	/* begin block 1 */
		// Start line: 229
	/* end block 1 */
	// End Line: 230

void Wind_ChangeDir(_WIND *w,short nb_Frames,short vx,short vy,int vz)

{
  TASK *pTVar1;
  
  pTVar1 = Task_Link(Wind_Task,0x100);
  w->handle = pTVar1;
  *(_WIND **)&pTVar1->local = w;
  w->handle->s0 = (int)nb_Frames;
  w->handle->s1 = (int)vx;
  w->handle->s2 = (int)vy;
  w->handle->s3 = (int)(short)vz;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Wind_Task()
 // line 115, offset 0x80067ce0
	/* begin block 1 */
		// Start line: 116
		// Start offset: 0x80067CE0
		// Variables:
	// 		struct _WIND *w; // $s0
	// 		short Nbf; // $v1
	// 		short ToX; // $a2
	// 		short ToY; // $a0
	// 		short ToZ; // $a1
	// 		struct WIND_7fake step; // stack offset -32
	// 		struct WIND_7fake accum; // stack offset -24
	// 		short i; // $s1
	/* end block 1 */
	// End offset: 0x80067E98
	// End Line: 146

	/* begin block 2 */
		// Start line: 260
	/* end block 2 */
	// End Line: 261

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Wind_Task(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ushort *puVar5;
  int iVar6;
  short local_18;
  short local_16;
  short local_14;
  
  puVar5 = (ushort *)TaskCurrent->local;
  iVar4 = (int)*(short *)&TaskCurrent->s0;
  iVar3 = ((int)((uint)*(ushort *)&TaskCurrent->s1 << 0x10) >> 8) -
          ((int)((uint)*puVar5 << 0x18) >> 0x10);
  if (iVar4 == 0) {
    trap(0x1c00);
  }
  if ((iVar4 == -1) && (iVar3 == -0x80000000)) {
    trap(0x1800);
  }
  local_18 = *puVar5 << 8;
  iVar1 = ((int)((uint)*(ushort *)&TaskCurrent->s2 << 0x10) >> 8) -
          ((int)((uint)puVar5[1] << 0x18) >> 0x10);
  if (iVar4 == 0) {
    trap(0x1c00);
  }
  if ((iVar4 == -1) && (iVar1 == -0x80000000)) {
    trap(0x1800);
  }
  local_16 = puVar5[1] << 8;
  iVar2 = ((int)((uint)*(ushort *)&TaskCurrent->s3 << 0x10) >> 8) -
          ((int)((uint)puVar5[2] << 0x18) >> 0x10);
  if (iVar4 == 0) {
    trap(0x1c00);
  }
  if ((iVar4 == -1) && (iVar2 == -0x80000000)) {
    trap(0x1800);
  }
  iVar6 = 0;
  local_14 = puVar5[2] << 8;
  if (0 < iVar4) {
    do {
      local_18 = local_18 + (short)(iVar3 / iVar4);
      local_14 = local_14 + (short)(iVar2 / iVar4);
      local_16 = local_16 + (short)(iVar1 / iVar4);
      *puVar5 = local_18 >> 8;
      puVar5[1] = local_16 >> 8;
      puVar5[2] = local_14 >> 8;
      Task_Next();
      iVar6 = iVar6 + 1;
    } while (iVar6 * 0x10000 >> 0x10 < iVar4);
  }
  *(undefined4 *)(puVar5 + 0xe) = 0;
  return;
}



// decompiled code
// original method signature: 
// struct _WIND * /*$ra*/ Wind_AddInList(struct _WIND **list /*$s0*/)
 // line 150, offset 0x80067eb4
	/* begin block 1 */
		// Start line: 151
		// Start offset: 0x80067EB4
		// Variables:
	// 		struct _WIND *p; // $v0
	// 		struct _WIND *prec; // $s0
	/* end block 1 */
	// End offset: 0x80067F08
	// End Line: 175

	/* begin block 2 */
		// Start line: 381
	/* end block 2 */
	// End Line: 382

_WIND * Wind_AddInList(_WIND **list)

{
  _WIND *p_Var1;
  _WIND *p_Var2;
  
  p_Var2 = *list;
  if (*list == (_WIND *)0x0) {
    p_Var2 = (_WIND *)Heap_AllocMem(0x24);
    *list = p_Var2;
  }
  else {
    do {
      p_Var1 = p_Var2;
      p_Var2 = p_Var1->next;
    } while (p_Var2 != (_WIND *)0x0);
    p_Var2 = (_WIND *)Heap_AllocMem(0x24);
    p_Var1->next = p_Var2;
  }
  p_Var2->next = (_WIND *)0x0;
  return p_Var2;
}



// decompiled code
// original method signature: 
// struct _WIND * /*$ra*/ Wind_DeleteList(struct _WIND **list /*$a0*/)
 // line 178, offset 0x80067f18
	/* begin block 1 */
		// Start line: 179
		// Start offset: 0x80067F18
		// Variables:
	// 		struct _WIND *p; // $s0
	// 		struct _WIND *prec; // $a0
	/* end block 1 */
	// End offset: 0x80067F48
	// End Line: 192

	/* begin block 2 */
		// Start line: 437
	/* end block 2 */
	// End Line: 438

_WIND * Wind_DeleteList(_WIND **list)

{
  _WIND *ptt;
  _WIND *p_Var1;
  
  ptt = *list;
  while (ptt != (_WIND *)0x0) {
    p_Var1 = ptt->next;
    Heap_FreeMem(ptt);
    ptt = p_Var1;
  }
  return (_WIND *)0x0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Wind_GetValue(struct WIND_7fake *pos /*$s2*/, struct WIND_7fake *sum /*$s1*/)
 // line 197, offset 0x80067f5c
	/* begin block 1 */
		// Start line: 198
		// Start offset: 0x80067F5C
		// Variables:
	// 		struct _WIND *pw; // $s0

		/* begin block 1.1 */
			// Start line: 208
			// Start offset: 0x80067F90
			// Variables:
		// 		long add; // $v0
		/* end block 1.1 */
		// End offset: 0x80067FF8
		// End Line: 221
	/* end block 1 */
	// End offset: 0x80068008
	// End Line: 223

	/* begin block 2 */
		// Start line: 476
	/* end block 2 */
	// End Line: 477

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Wind_GetValue(undefined1 pos,undefined sum)

{
  int iVar1;
  undefined3 in_register_00000015;
  short *psVar2;
  _WIND *w;
  
  w = Winds;
  psVar2 = (short *)CONCAT31(in_register_00000015,sum);
  *psVar2 = 0;
  psVar2[1] = 0;
  psVar2[2] = 0;
  if (w != (_WIND *)0x0) {
    do {
      if (w->inf == 0) {
        iVar1 = 1;
      }
      else {
        iVar1 = Wind_TestPos(w,pos);
      }
      if (iVar1 != 0) {
        *psVar2 = *psVar2 + (w->speed).vx;
        psVar2[1] = psVar2[1] + (w->speed).vy;
        psVar2[2] = psVar2[2] + (w->speed).vz;
      }
      w = w->next;
    } while (w != (_WIND *)0x0);
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Wind_TestPos(struct _WIND *w /*$a0*/, struct WIND_7fake *p /*$a1*/)
 // line 226, offset 0x80068020
	/* begin block 1 */
		// Start line: 228
		// Start offset: 0x80068020
		// Variables:
	// 		struct WIND_7fake *min; // $a2
	// 		struct WIND_7fake *max; // $a3
	/* end block 1 */
	// End offset: 0x800680B0
	// End Line: 241

	/* begin block 2 */
		// Start line: 540
	/* end block 2 */
	// End Line: 541

long Wind_TestPos(_WIND *w,undefined p)

{
  undefined3 in_register_00000015;
  short *psVar1;
  
  psVar1 = (short *)CONCAT31(in_register_00000015,p);
  if (((((w->min).vx <= *psVar1) && (*psVar1 <= (w->max).vx)) && ((w->min).vy <= psVar1[1])) &&
     (((psVar1[1] <= (w->max).vy && ((w->min).vz <= psVar1[2])) && (psVar1[2] <= (w->max).vz)))) {
    return 1;
  }
  return 0;
}





