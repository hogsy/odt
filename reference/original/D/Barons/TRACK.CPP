#include "THISDUST.H"
#include "TRACK.H"


// decompiled code
// original method signature: 
// void /*$ra*/ Track_InitModule()
 // line 52, offset 0x800597c8
	/* begin block 1 */
		// Start line: 105
	/* end block 1 */
	// End Line: 106

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Track_InitModule(void)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Track_Init()
 // line 57, offset 0x800597d0
	/* begin block 1 */
		// Start line: 58
		// Start offset: 0x800597D0
	/* end block 1 */
	// End offset: 0x800597D0
	// End Line: 58

	/* begin block 2 */
		// Start line: 114
	/* end block 2 */
	// End Line: 115

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Track_Init(void)

{
  Track_Handle = Task_Add(Track_Task,0);
  Track_SetMode(1,0);
  Track_UnsuedTime = 0;
  Track_SpecialMode = '\0';
  Track_HasBlocked = '\0';
  Track_HasLooked = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Track_Delete()
 // line 73, offset 0x80059814
	/* begin block 1 */
		// Start line: 156
	/* end block 1 */
	// End Line: 157

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Track_Delete(void)

{
  Task_Kill(Track_Handle);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Track_InitFile()
 // line 79, offset 0x80059838
	/* begin block 1 */
		// Start line: 81
		// Start offset: 0x80059838
		// Variables:
	// 		long i; // $a1
	/* end block 1 */
	// End offset: 0x800598AC
	// End Line: 88

	/* begin block 2 */
		// Start line: 171
	/* end block 2 */
	// End Line: 172

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Track_InitFile(void)

{
  _D3_OBJECT *p_Var1;
  _PVL_HEADER *p_Var2;
  _CAMERA *p_Var3;
  int iVar4;
  
  p_Var2 = Pvl_File;
  p_Var1 = Pvl_Objects;
  iVar4 = 0;
  p_Var3 = Pvl_Cameras;
  if (0 < Pvl_File->n_cameras) {
    do {
      if (0 < (int)p_Var3->target_d3) {
        p_Var3->target_d3 = (_D3_OBJECT *)((int)p_Var1 + (int)p_Var3->target_d3 * 0xa4 + -0xa4);
      }
      iVar4 = iVar4 + 1;
      p_Var3 = p_Var3 + 1;
    } while (iVar4 < (int)p_Var2->n_cameras);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Track_SetMode(long m /*$a3*/, long t /*$a2*/)
 // line 91, offset 0x800598b4
	/* begin block 1 */
		// Start line: 195
	/* end block 1 */
	// End Line: 196

void Track_SetMode(long m,long t)

{
  if (m == 10) {
    if (*(char *)(t + 0x2a) == -1) {
      return;
    }
  }
  else {
    if ((int)Track_Mode == m) {
      return;
    }
  }
  Task_EventExec(Track_Handle,m,t);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Track_MoveTo(long speed /*$s0*/)
 // line 101, offset 0x80059910
	/* begin block 1 */
		// Start line: 102
		// Start offset: 0x80059910
	/* end block 1 */
	// End offset: 0x80059948
	// End Line: 111

	/* begin block 2 */
		// Start line: 220
	/* end block 2 */
	// End Line: 221

long Track_MoveTo(long speed)

{
  long lVar1;
  
  if (Pvl_Pause != 0) {
    do {
      Task_Next();
    } while (Pvl_Pause != 0);
  }
  lVar1 = Cam_MoveTo(speed);
  return lVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Track_Task()
 // line 117, offset 0x80059960
	/* begin block 1 */
		// Start line: 118
		// Start offset: 0x80059960
	/* end block 1 */
	// End offset: 0x80059A78
	// End Line: 159

	/* begin block 2 */
		// Start line: 252
	/* end block 2 */
	// End Line: 253

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Track_Task(void)

{
  long lVar1;
  
  lVar1 = Task_EventWait();
  Track_Target = TaskCurrent->event_param;
  Track_Mode = (short)lVar1;
  if (Track_HasBlocked != '\0') {
    Track_HasBlocked = '\0';
    _DAT_800b1d58 = 0;
  }
  if (Track_Mode != 2) {
    Track_SpecialMode = '\0';
  }
  if (Track_Target == 0) {
    Track_Target = (long)&Player;
  }
  switch(Track_Mode) {
  case 1:
    Track_InitMode();
    break;
  case 2:
    Track_NormalMode();
    break;
  case 3:
    Track_AdjustMode();
    break;
  case 4:
    Track_DeathMode();
    break;
  case 5:
    Track_ViewPlayer();
    break;
  case 6:
    Track_GolemMode();
    break;
  case 7:
    Track_GolemModeFlee();
    break;
  case 10:
    Track_CustomPvlMode();
  }
  Track_SetMode(2,0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Track_Wait()
 // line 163, offset 0x80059a94
	/* begin block 1 */
		// Start line: 348
	/* end block 1 */
	// End Line: 349

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Track_Wait(void)

{
  if (Track_Mode != 2) {
    do {
      Task_Next();
    } while (Track_Mode != 2);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Track_InitMode()
 // line 172, offset 0x80059ad8
	/* begin block 1 */
		// Start line: 173
		// Start offset: 0x80059AD8
		// Variables:
	// 		long i; // $a0
	/* end block 1 */
	// End offset: 0x80059B1C
	// End Line: 185

	/* begin block 2 */
		// Start line: 367
	/* end block 2 */
	// End Line: 368

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Track_InitMode(void)

{
  undefined2 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  puVar1 = &Cam_Pos_;
  do {
    *puVar1 = 0x7fff;
    puVar1[1] = 0x7fff;
    puVar1[2] = 0x7fff;
    iVar2 = iVar2 + 1;
    puVar1 = puVar1 + 4;
  } while (iVar2 < 2);
  do {
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Track_NormalMode()
 // line 190, offset 0x80059b1c
	/* begin block 1 */
		// Start line: 191
		// Start offset: 0x80059B1C
		// Variables:
	// 		struct _PLAYER *pl; // $a0
	// 		struct TRACK_7fake pos; // stack offset -24
	// 		struct TRACK_7fake target; // stack offset -16
	/* end block 1 */
	// End offset: 0x80059C58
	// End Line: 228

	/* begin block 2 */
		// Start line: 407
	/* end block 2 */
	// End Line: 408

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Track_NormalMode(void)

{
  char cVar1;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined2 local_c;
  
  cVar1 = Track_SpecialMode;
  Track_FirstLook = '\x01';
  Track_Timer = 0;
  Track_SpecialMode = '\0';
  DAT_800b2604 = *(undefined2 *)(Track_Target + 0x40);
  Track_NeedCut = cVar1 == '\0';
  do {
    Track_GetNormal((int)Pvl_File->track_dist * 100,0,0xe8,0xf0);
    if (Track_NeedCut != '\0') {
      Track_NeedCut = '\0';
      Cam_Pos_ = local_18;
      DAT_800b416a = local_16;
      DAT_800b416c = local_14;
      DAT_800b4170 = local_10;
      DAT_800b4172 = local_e;
      DAT_800b4174 = local_c;
    }
    DAT_800b415c = local_14;
    DAT_800b415a = local_16;
    Cam_Target_ = local_18;
    DAT_800b4160 = local_10;
    DAT_800b4162 = local_e;
    DAT_800b4164 = local_c;
    Track_MoveTo(0x280);
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Track_GetNormal(long d /*stack 0*/, long rotz /*$a1*/, struct TRACK_7fake *pos /*$s2*/, struct TRACK_7fake *target /*$s1*/)
 // line 231, offset 0x80059c58
	/* begin block 1 */
		// Start line: 232
		// Start offset: 0x80059C58
		// Variables:
	// 		struct _PLAYER *pl; // $s0
	// 		struct TRACK_7fake rot; // stack offset -40
	// 		struct TRACK_7fake last_rot; // stack offset -32

		/* begin block 1.1 */
			// Start line: 256
			// Start offset: 0x80059D40
			// Variables:
		// 		long dx; // stack offset -24
		// 		long dy; // stack offset -20
		// 		long delta; // $a0
		/* end block 1.1 */
		// End offset: 0x80059DE8
		// End Line: 267
	/* end block 1 */
	// End offset: 0x80059F54
	// End Line: 305

	/* begin block 2 */
		// Start line: 526
	/* end block 2 */
	// End Line: 527

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Track_GetNormal(long d,long rotz,undefined1 pos,undefined target)

{
  undefined4 uVar1;
  long d1;
  int iVar2;
  undefined3 in_register_0000001d;
  undefined4 *puVar3;
  int local_res0;
  long local_18;
  long local_14;
  
  uVar1 = _DAT_800b1c68;
  puVar3 = (undefined4 *)CONCAT31(in_register_0000001d,target);
  *puVar3 = _DAT_800b1c64;
  puVar3[1] = uVar1;
  *(short *)(puVar3 + 1) = *(short *)(puVar3 + 1) + _DAT_800b1ca8;
  local_res0 = 200;
  if (199 < d) {
    local_res0 = d;
  }
  if (((_DAT_800b1c56 & 0x4000) != 0) && (_DAT_800b1cc4 != (_D3_OBJECT *)0x0)) {
    d1 = Boxes_GetExtendedMaxZ(_DAT_800b1cc4);
    if (d1 != 0) {
      Boxes_GetExtendedDxDy(_DAT_800b1cc4,&local_18,&local_14);
      d1 = Direction(local_18,local_14);
      iVar2 = DeltaDirection(d1,(int)_DAT_800b1c78);
      if (iVar2 < 0) {
        iVar2 = -iVar2;
      }
      if ((((0x300 < iVar2) && (_DAT_800b1d5a != 8)) && (0x4ff < iVar2)) &&
         (iVar2 = local_res0 + -200, local_res0 = 200, 199 < iVar2)) {
        local_res0 = iVar2;
      }
    }
  }
  if (((_DAT_800b1d40 != 0) || (Pvl_Demo != 0)) ||
     ((_DAT_800b1d5a == 0xb || (_DAT_800b1d5a == 0xe)))) {
    Track_UnsuedTime = 0;
  }
  iVar2 = (int)Scr_TicksPerSecond;
  Track_UnsuedTime = Track_UnsuedTime + 1;
  if (iVar2 * 0x1e <= Track_UnsuedTime) {
    if (Track_UnsuedTime == iVar2 * 0x1e) {
      Track_UnsuedRot = 0;
      Track_UnsuedSide = 1;
    }
    if (iVar2 * 0x1f < Track_UnsuedTime) {
      Track_UnsuedTime = iVar2 * 0x1f;
    }
    Track_UnsuedRot = Track_UnsuedRot + Track_UnsuedSide;
  }
  d1 = Track_TestShoot(pos,target,0xd8,(long *)register0x00000074);
  if (d1 == 0) {
    Track_ChooseRotZ(pos,target,0xd8,(long *)register0x00000074);
    Track_GetPos(pos,target,0,local_res0);
    Track_TestPosTarget(pos,target,1);
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Track_TestShoot(struct TRACK_7fake *pos /*$s4*/, struct TRACK_7fake *target /*$s2*/, struct TRACK_7fake *rot /*$s1*/, long *d /*$s3*/)
 // line 308, offset 0x80059f6c
	/* begin block 1 */
		// Start line: 309
		// Start offset: 0x80059F6C
		// Variables:
	// 		struct _PLAYER *pl; // $a0

		/* begin block 1.1 */
			// Start line: 323
			// Start offset: 0x80059FB8
			// Variables:
		// 		long x; // $s0
		/* end block 1.1 */
		// End offset: 0x8005A130
		// End Line: 358
	/* end block 1 */
	// End offset: 0x8005A134
	// End Line: 361

	/* begin block 2 */
		// Start line: 714
	/* end block 2 */
	// End Line: 715

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long Track_TestShoot(undefined1 pos,undefined target,undefined rot,long *d)

{
  int iVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  undefined3 in_register_00000015;
  short *psVar5;
  undefined3 in_register_00000019;
  
  iVar1 = CONCAT31(in_register_00000019,rot);
  psVar5 = (short *)CONCAT31(in_register_00000015,target);
  if ((_DAT_800b1d40 & PJOY_AIM) == 0) {
    lVar2 = 0;
  }
  else {
    *d = 0x118;
    *(undefined2 *)(iVar1 + 2) = 0;
    psVar5[2] = psVar5[2] + 0x19;
    *(short *)(iVar1 + 2) = *(short *)(iVar1 + 2) - _DAT_800b1d00;
    *(short *)(iVar1 + 4) = *(short *)(iVar1 + 4) + _DAT_800b1d02;
    if (0x300 < *(short *)(iVar1 + 2)) {
      *(undefined2 *)(iVar1 + 2) = 0x300;
    }
    if (*(short *)(iVar1 + 2) < -0x180) {
      *(undefined2 *)(iVar1 + 2) = 0xfe80;
    }
    iVar3 = (uint)*(ushort *)(iVar1 + 2) << 0x10;
    iVar4 = iVar3 >> 0x10;
    if (iVar4 < 0) {
      *d = *d - (((iVar4 / 5 + (iVar4 >> 0x1f)) - (iVar3 >> 0x1f)) * 0x10000 >> 0x10);
    }
    iVar3 = rcos((int)*(short *)(iVar1 + 2));
    iVar4 = iVar3 * 200 >> 0xc;
    iVar3 = rsin((int)*(short *)(iVar1 + 2));
    psVar5[2] = psVar5[2] - (short)(iVar3 * 200 >> 0xc);
    iVar3 = rcos((int)*(short *)(iVar1 + 4));
    *psVar5 = *psVar5 + (short)(iVar3 * iVar4 >> 0xc);
    iVar1 = rsin((int)*(short *)(iVar1 + 4));
    Track_NeedCut = Track_FirstLook;
    Track_HasLooked = 1;
    Track_FirstLook = '\0';
    psVar5[1] = psVar5[1] + (short)(iVar1 * iVar4 >> 0xc);
    Track_GetPos(pos,target,rot,*d);
    lVar2 = 1;
  }
  return lVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Track_ChooseRotZ(struct TRACK_7fake *pos /*$a0*/, struct TRACK_7fake *target /*$a1*/, struct TRACK_7fake *rot /*$a2*/, long *d /*$a3*/)
 // line 364, offset 0x8005a154
	/* begin block 1 */
		// Start line: 365
		// Start offset: 0x8005A154
		// Variables:
	// 		struct TRACK_7fake rrot; // stack offset -8
	/* end block 1 */
	// End offset: 0x8005A180
	// End Line: 481

	/* begin block 2 */
		// Start line: 854
	/* end block 2 */
	// End Line: 855

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Track_ChooseRotZ(undefined1 pos,undefined1 target,undefined rot,long *d)

{
  undefined3 in_register_00000019;
  
  Track_Rot = *(undefined4 *)CONCAT31(in_register_00000019,rot);
  _DAT_800b2604 = ((undefined4 *)CONCAT31(in_register_00000019,rot))[1];
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Track_TestPosTarget(struct TRACK_7fake *cam /*$s7*/, struct TRACK_7fake *target /*$a1*/, long modify /*stack 8*/)
 // line 484, offset 0x8005a188
	/* begin block 1 */
		// Start line: 485
		// Start offset: 0x8005A188
		// Variables:
	// 		struct _PLATFORM *p1; // $s4
	// 		struct _PLATFORM *p2; // $s3
	// 		struct _PLATFORM *p3; // $s2
	// 		struct _PLATFORM *p4; // $a2
	// 		struct TRACK_7fake test; // stack offset -56
	// 		struct TRACK_7fake t; // stack offset -48
	// 		long dx; // $s6
	// 		long dy; // $s5
	// 		long dz; // $fp
	// 		long dist; // $s0
	// 		long i; // $s1
	/* end block 1 */
	// End offset: 0x8005A588
	// End Line: 547

	/* begin block 2 */
		// Start line: 1100
	/* end block 2 */
	// End Line: 1101

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long Track_TestPosTarget(undefined cam,undefined target,long modify)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  uint uVar6;
  _PLATFORM *p_Var7;
  _PLATFORM *p_Var8;
  _PLATFORM *p_Var9;
  _PLATFORM *p_Var10;
  undefined3 in_register_00000011;
  short *psVar11;
  undefined3 in_register_00000015;
  int iVar12;
  _PLATFORM *p_Var13;
  int iVar14;
  int iVar15;
  int iVar16;
  
  sVar4 = _DAT_800b1c66;
  sVar3 = _DAT_800b1c64;
  psVar11 = (short *)CONCAT31(in_register_00000011,cam);
  sVar2 = *(short *)(CONCAT31(in_register_00000015,target) + 4);
  iVar15 = (int)*psVar11 - (int)_DAT_800b1c64;
  iVar14 = (int)psVar11[1] - (int)_DAT_800b1c66;
  iVar12 = 0x32;
  sVar1 = psVar11[2];
  uVar6 = SquareRoot0(iVar15 * iVar15 + iVar14 * iVar14);
  if (0x32 < (int)uVar6) {
    iVar16 = iVar15 * 0x32;
    do {
      if (uVar6 == 0) {
        trap(0x1c00);
      }
      if ((uVar6 == 0xffffffff) && (iVar16 == -0x80000000)) {
        trap(0x1800);
      }
      if (uVar6 == 0) {
        trap(0x1c00);
      }
      if ((uVar6 == 0xffffffff) && (iVar14 * iVar12 == -0x80000000)) {
        trap(0x1800);
      }
      iVar16 = ((int)sVar1 - (int)sVar2) * iVar12;
      if (uVar6 == 0) {
        trap(0x1c00);
      }
      if ((uVar6 == 0xffffffff) && (iVar16 == -0x80000000)) {
        trap(0x1800);
      }
      sVar5 = sVar2 + (short)(iVar16 / (int)uVar6);
      p_Var7 = Plat_GetPlat(200);
      p_Var8 = Plat_GetPlat(200);
      p_Var9 = Plat_GetPlat(200);
      p_Var10 = Plat_GetPlat(200);
      p_Var13 = p_Var7;
      if ((p_Var7 != (_PLATFORM *)0x0) &&
         (p_Var13 = (_PLATFORM *)0x0,
         (int)sVar5 < (int)(p_Var7->obj).pos.vz + (int)*(short *)&p_Var7[1].obj.prec)) {
        p_Var13 = p_Var7;
      }
      p_Var7 = p_Var8;
      if ((p_Var8 != (_PLATFORM *)0x0) &&
         (p_Var7 = (_PLATFORM *)0x0,
         (int)sVar5 < (int)(p_Var8->obj).pos.vz + (int)*(short *)&p_Var8[1].obj.prec)) {
        p_Var7 = p_Var8;
      }
      p_Var8 = p_Var9;
      if ((p_Var9 != (_PLATFORM *)0x0) &&
         (p_Var8 = (_PLATFORM *)0x0,
         (int)sVar5 < (int)(p_Var9->obj).pos.vz + (int)*(short *)&p_Var9[1].obj.prec)) {
        p_Var8 = p_Var9;
      }
      p_Var9 = p_Var10;
      if ((p_Var10 != (_PLATFORM *)0x0) &&
         (p_Var9 = (_PLATFORM *)0x0,
         (int)sVar5 < (int)(p_Var10->obj).pos.vz + (int)*(short *)&p_Var10[1].obj.prec)) {
        p_Var9 = p_Var10;
      }
      if ((((p_Var13 != (_PLATFORM *)0x0) || (p_Var7 != (_PLATFORM *)0x0)) ||
          (p_Var8 != (_PLATFORM *)0x0)) || (p_Var9 != (_PLATFORM *)0x0)) {
        if (modify != 0) {
          iVar16 = 0x4b;
          if (0x4a < iVar12 + -100) {
            iVar16 = iVar12 + -100;
          }
          if (uVar6 == 0) {
            trap(0x1c00);
          }
          if ((uVar6 == 0xffffffff) && (iVar15 * iVar16 == -0x80000000)) {
            trap(0x1800);
          }
          if (uVar6 == 0) {
            trap(0x1c00);
          }
          if ((uVar6 == 0xffffffff) && (iVar14 * iVar16 == -0x80000000)) {
            trap(0x1800);
          }
          iVar12 = ((int)sVar1 - (int)sVar2) * iVar16;
          if (uVar6 == 0) {
            trap(0x1c00);
          }
          if ((uVar6 == 0xffffffff) && (iVar12 == -0x80000000)) {
            trap(0x1800);
          }
          *psVar11 = sVar3 + (short)((iVar15 * iVar16) / (int)uVar6);
          psVar11[1] = sVar4 + (short)((iVar14 * iVar16) / (int)uVar6);
          psVar11[2] = sVar2 + (short)(iVar12 / (int)uVar6);
          return iVar16;
        }
        return iVar12;
      }
      iVar12 = iVar12 + 0x32;
      iVar16 = iVar15 * iVar12;
    } while (iVar12 < (int)uVar6);
  }
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Track_GetPos(struct TRACK_7fake *pos /*$s0*/, struct TRACK_7fake *target /*$a1*/, struct TRACK_7fake *rot /*$a2*/, long dist /*$s2*/)
 // line 550, offset 0x8005a5b8
	/* begin block 1 */
		// Start line: 551
		// Start offset: 0x8005A5B8
		// Variables:
	// 		long x; // $s1
	// 		long ry; // $s1
	// 		long rz; // $s3
	/* end block 1 */
	// End offset: 0x8005A5B8
	// End Line: 551

	/* begin block 2 */
		// Start line: 1319
	/* end block 2 */
	// End Line: 1320

void Track_GetPos(undefined pos,undefined target,undefined rot,long dist)

{
  int iVar1;
  undefined3 in_register_00000011;
  undefined4 *puVar2;
  undefined3 in_register_00000015;
  undefined3 in_register_00000019;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  puVar2 = (undefined4 *)CONCAT31(in_register_00000011,pos);
  uVar3 = ((undefined4 *)CONCAT31(in_register_00000015,target))[1];
  *puVar2 = *(undefined4 *)CONCAT31(in_register_00000015,target);
  puVar2[1] = uVar3;
  uVar4 = SEXT24(*(short *)(CONCAT31(in_register_00000019,rot) + 2));
  uVar6 = SEXT24(*(short *)(CONCAT31(in_register_00000019,rot) + 4));
  iVar1 = rcos(uVar4);
  iVar5 = iVar1 * dist >> 0xc;
  iVar1 = rsin(uVar4);
  *(short *)(puVar2 + 1) = *(short *)(puVar2 + 1) + (short)(iVar1 * dist >> 0xc);
  iVar1 = rcos(uVar6);
  *(short *)puVar2 = *(short *)puVar2 - (short)(iVar1 * iVar5 >> 0xc);
  iVar1 = rsin(uVar6);
  *(short *)((int)puVar2 + 2) = *(short *)((int)puVar2 + 2) - (short)(iVar1 * iVar5 >> 0xc);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Track_AdjustMode()
 // line 572, offset 0x8005a690
	/* begin block 1 */
		// Start line: 573
		// Start offset: 0x8005A690
		// Variables:
	// 		struct _PLAYER *pl; // $s1
	// 		struct TRACK_7fake pos; // stack offset -32
	// 		struct TRACK_7fake target; // stack offset -24
	// 		long rotz; // $s0
	/* end block 1 */
	// End offset: 0x8005A75C
	// End Line: 598

	/* begin block 2 */
		// Start line: 1368
	/* end block 2 */
	// End Line: 1369

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Track_AdjustMode(void)

{
  long lVar1;
  int rotz;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  
  lVar1 = Track_Target;
  rotz = 0;
  do {
    if ((*(ushort *)(lVar1 + 0x108) & 0x8000) != 0) {
      rotz = rotz + -0x20;
    }
    if ((*(ushort *)(lVar1 + 0x108) & 0x2000) != 0) {
      rotz = rotz + 0x20;
    }
    Track_GetNormal((int)Pvl_File->track_dist * 100,rotz,0xe0,0xe8);
    Cam_Target_ = local_20;
    DAT_800b415a = local_1e;
    DAT_800b415c = local_1c;
    DAT_800b4160 = local_18;
    DAT_800b4162 = local_16;
    DAT_800b4164 = local_14;
    Track_MoveTo(0x300);
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Track_CustomPvlMode()
 // line 603, offset 0x8005a75c
	/* begin block 1 */
		// Start line: 604
		// Start offset: 0x8005A75C
		// Variables:
	// 		struct _ZONE *z; // $s3
	// 		struct _CAMERA *c; // $s2
	// 		struct _PLAYER *pl; // $s5
	// 		struct TRACK_7fake pos; // stack offset -48
	// 		struct TRACK_7fake target; // stack offset -40
	// 		long cut; // $s1
	// 		long time; // $s0
	// 		long speed; // $s3

		/* begin block 1.1 */
			// Start line: 618
			// Start offset: 0x8005A7B8
			// Variables:
		// 		long i; // $s1
		/* end block 1.1 */
		// End offset: 0x8005A83C
		// End Line: 630
	/* end block 1 */
	// End offset: 0x8005AB7C
	// End Line: 727

	/* begin block 2 */
		// Start line: 1460
	/* end block 2 */
	// End Line: 1461

/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Track_CustomPvlMode(void)

{
  bool bVar1;
  long lVar2;
  _ZONE *z;
  int iVar3;
  int speed;
  _CAMERA *c;
  short local_30;
  short local_2e;
  short local_2c;
  undefined4 local_28;
  short local_24;
  
  lVar2 = Track_Target;
  c = Pvl_Cameras + (int)*(char *)(Track_Target + 0x2a);
  if (((c->mode & 1U) != 0) && (speed = 0, 0 < Pvl_File->n_zones)) {
    iVar3 = 0;
    do {
      z = (_ZONE *)((int)&Pvl_Zones->x1 + iVar3);
      if (z->camera == *(char *)(lVar2 + 0x2a)) {
        Pvl_SetZoneStateBits(z,1);
        (&Pvl_Zones->camera)[iVar3] = -1;
      }
      speed = speed + 1;
      iVar3 = iVar3 + 0x30;
    } while (speed < (int)Pvl_File->n_zones);
  }
  if ((c->mode & 2U) != 0) {
    Track_HasBlocked = '\x01';
    _DAT_800b1d58 = 1;
  }
  if (c->target_d3 == (_D3_OBJECT *)0xfffffffe) {
    Track_CustomPvlModePlayer(c);
  }
  speed = (int)c->delay_in;
  if (speed != 0) {
    while (0 < speed) {
      Track_GetNormal((int)Pvl_File->track_dist * 100,0,0xd0,0xd8);
      Cam_Target_ = local_30;
      DAT_800b415a = local_2e;
      DAT_800b415c = local_2c;
      DAT_800b4160 = (undefined2)local_28;
      DAT_800b4162 = local_28._2_2_;
      DAT_800b4164 = local_24;
      speed = speed + -1;
      Task_Next();
    }
  }
  speed = (int)(c->pos).pad;
  bVar1 = speed == 0;
  if (bVar1) {
    Cam_Pos_ = (c->pos).vx;
    DAT_800b416a = (c->pos).vy;
    DAT_800b416c = (c->pos).vz;
    Cam_Target_ = (c->pos).vx;
    DAT_800b415a = (c->pos).vy;
    speed = 0x300;
    DAT_800b415c = (c->pos).vz;
  }
  else {
    Cam_Target_ = (c->pos).vx;
    DAT_800b415a = (c->pos).vy;
    DAT_800b415c = (c->pos).vz;
  }
  iVar3 = (int)c->delay_out;
  do {
    if (c->target_d3 == (_D3_OBJECT *)0xffffffff) {
      local_28 = *(undefined4 *)&c->target;
      local_24 = (short)*(undefined4 *)&(c->target).vz;
    }
    else {
      if (c->target_d3 == (_D3_OBJECT *)0x0) {
        local_28 = _DAT_800b1c64;
        local_24 = (short)_DAT_800b1c68;
        local_24 = local_24 + 0xfa;
      }
      else {
        local_28 = *(undefined4 *)&c->target_d3->pos;
        local_24 = (short)*(undefined4 *)&(c->target_d3->pos).vz;
      }
    }
    if (bVar1) {
      DAT_800b4170 = (undefined2)local_28;
      DAT_800b4172 = local_28._2_2_;
      DAT_800b4174 = local_24;
      bVar1 = false;
    }
    DAT_800b4160 = (undefined2)local_28;
    DAT_800b4162 = local_28._2_2_;
    DAT_800b4164 = local_24;
    Track_MoveTo(speed);
    Task_Next();
  } while ((iVar3 == 0) || (iVar3 = iVar3 + -1, iVar3 != 0));
  if ((c->target).pad != 0) {
    do {
      Track_GetNormal((int)Pvl_File->track_dist * 100,0,0xd0,0xd8);
      Cam_Target_ = local_30;
      DAT_800b415a = local_2e;
      DAT_800b415c = local_2c;
      DAT_800b4160 = (undefined2)local_28;
      DAT_800b4162 = local_28._2_2_;
      DAT_800b4164 = local_24;
      Task_Next();
      lVar2 = Track_MoveTo((int)(c->target).pad);
    } while (lVar2 != 0);
  }
  if ((c->mode & 2U) != 0) {
    Track_HasBlocked = '\0';
    _DAT_800b1d58 = 0;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Track_CustomPvlModePlayer(struct _CAMERA *c /*$s1*/)
 // line 730, offset 0x8005aba0
	/* begin block 1 */
		// Start line: 731
		// Start offset: 0x8005ABA0
		// Variables:
	// 		struct TRACK_7fake pos; // stack offset -32
	// 		struct TRACK_7fake target; // stack offset -24
	// 		long first; // $s0
	/* end block 1 */
	// End offset: 0x8005ACB4
	// End Line: 763

	/* begin block 2 */
		// Start line: 1749
	/* end block 2 */
	// End Line: 1750

void Track_CustomPvlModePlayer(_CAMERA *c)

{
  bool bVar1;
  short local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  
  Track_SpecialMode = '\x01';
  bVar1 = Cam_Pos_ == 0x7fff;
  do {
    Track_GetNormal((int)(c->pos).vz,0,0xe0,0xe8);
    if (bVar1) {
      Cam_Pos_ = local_20;
      DAT_800b416a = local_1e;
      DAT_800b416c = local_1c;
      DAT_800b4170 = local_18;
      DAT_800b4172 = local_16;
      DAT_800b4174 = local_14;
    }
    DAT_800b415c = local_1c;
    DAT_800b415a = local_1e;
    Cam_Target_ = local_20;
    DAT_800b4160 = local_18;
    DAT_800b4162 = local_16;
    DAT_800b4164 = local_14;
    bVar1 = false;
    Track_MoveTo(0x300);
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Track_DeathMode()
 // line 768, offset 0x8005acb4
	/* begin block 1 */
		// Start line: 769
		// Start offset: 0x8005ACB4
		// Variables:
	// 		struct TRACK_7fake p; // stack offset -40
	// 		struct TRACK_7fake target; // stack offset -32
	// 		long s; // $s4
	// 		long ta; // $s0
	// 		long type; // $s2
	// 		long rc; // $s3
	// 		long rs; // $s1
	/* end block 1 */
	// End offset: 0x8005AF74
	// End Line: 828

	/* begin block 2 */
		// Start line: 1859
	/* end block 2 */
	// End Line: 1860

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Track_DeathMode(void)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  long speed;
  short local_24;
  
  iVar7 = TaskCurrent->event_param;
  iVar6 = 400;
  if (iVar7 == 1) {
    iVar6 = 200;
    speed = 0x800;
    iVar3 = rcos((int)_DAT_800b1c78);
    iVar4 = rsin((int)_DAT_800b1c78);
    local_24 = _DAT_800b1c68 + 300;
  }
  else {
    speed = 0x200;
    iVar3 = rcos((int)_DAT_800b1c78 + 0x200);
    iVar4 = rsin((int)_DAT_800b1c78 + 0x200);
    local_24 = _DAT_800b1c68 + 400;
  }
  sVar1 = _DAT_800b1c64 + (short)(iVar3 * iVar6 >> 0xc);
  sVar2 = _DAT_800b1c66 + (short)(iVar4 * iVar6 >> 0xc);
  Track_TestPosTarget(0xd8,0xe0,1);
  DAT_800b4170 = _DAT_800b1c64;
  DAT_800b4172 = _DAT_800b1c66;
  DAT_800b4174 = _DAT_800b1c68;
  DAT_800b4160 = _DAT_800b1c64;
  DAT_800b4162 = _DAT_800b1c66;
  DAT_800b4164 = _DAT_800b1c68;
  Cam_Target_ = sVar1;
  DAT_800b415a = sVar2;
  DAT_800b415c = local_24;
  Cam_Pos_ = sVar1;
  DAT_800b416a = sVar2;
  DAT_800b416c = local_24;
  do {
    sVar1 = _DAT_800b1c64 + (short)(iVar3 * iVar6 >> 0xc);
    sVar2 = _DAT_800b1c66 + (short)(iVar4 * iVar6 >> 0xc);
    if (iVar7 != 1) {
      iVar5 = iVar6 + -3;
      local_24 = _DAT_800b1c68 + (short)iVar6;
      iVar6 = 200;
      if (199 < iVar5) {
        iVar6 = iVar5;
      }
    }
    if (iVar7 == 0) {
      Track_TestPosTarget(0xd8,0xe0,1);
    }
    DAT_800b415c = local_24;
    DAT_800b4160 = _DAT_800b1c64;
    DAT_800b4162 = _DAT_800b1c66;
    DAT_800b4164 = _DAT_800b1c68;
    Cam_Target_ = sVar1;
    DAT_800b415a = sVar2;
    Track_MoveTo(speed);
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Track_ViewPlayer()
 // line 832, offset 0x8005af74
	/* begin block 1 */
		// Start line: 833
		// Start offset: 0x8005AF74
		// Variables:
	// 		struct _PLAYER *pl; // $s1
	// 		long cx; // $s0
	// 		long cy; // $a0
	// 		long rz; // $s0
	// 		long speed; // $s2
	/* end block 1 */
	// End offset: 0x8005B0D8
	// End Line: 858

	/* begin block 2 */
		// Start line: 2022
	/* end block 2 */
	// End Line: 2023

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Track_ViewPlayer(void)

{
  short sVar1;
  bool bVar2;
  long lVar3;
  int iVar4;
  long lVar5;
  int iVar6;
  int speed;
  
  lVar3 = Track_Target;
  DAT_800b4170 = *(undefined2 *)(Track_Target + 0x2c);
  DAT_800b4172 = *(undefined2 *)(Track_Target + 0x2e);
  DAT_800b4174 = *(short *)(Track_Target + 0x30) + 0xfa;
  DAT_800b4160 = *(undefined2 *)(Track_Target + 0x2c);
  DAT_800b4162 = *(undefined2 *)(Track_Target + 0x2e);
  DAT_800b4164 = *(short *)(Track_Target + 0x30) + 0xfa;
  speed = 8;
  bVar2 = true;
  while( true ) {
    if (!bVar2) {
      speed = 0x400;
    }
    iVar6 = 0;
    if ((*(ushort *)(lVar3 + 0x11c) & 8) != 0) {
      iVar6 = (int)*(short *)(lVar3 + 0x124);
    }
    iVar4 = rcos((int)*(short *)(lVar3 + 0x40) + iVar6);
    sVar1 = *(short *)(lVar3 + 0x2c);
    iVar6 = rsin((int)*(short *)(lVar3 + 0x40) + iVar6);
    DAT_800b415a = *(short *)(lVar3 + 0x2e) - (short)(iVar6 * 0x28a >> 0xc);
    DAT_800b415c = *(short *)(lVar3 + 0x30) + 800;
    DAT_800b4160 = *(undefined2 *)(lVar3 + 0x2c);
    DAT_800b4162 = *(undefined2 *)(lVar3 + 0x2e);
    DAT_800b4164 = *(short *)(lVar3 + 0x30) + 0xfa;
    Cam_Target_ = sVar1 - (short)(iVar4 * 0x28a >> 0xc);
    lVar5 = Track_MoveTo(speed);
    if (lVar5 == 0) break;
    speed = speed + 8;
    Task_Next();
    bVar2 = speed < 0x401;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Track_GolemMode()
 // line 861, offset 0x8005b0f0
	/* begin block 1 */
		// Start line: 862
		// Start offset: 0x8005B0F0
		// Variables:
	// 		struct _D3_OBJECT *o; // $s3
	// 		long x; // $s0
	// 		long y; // $a0
	// 		long z; // $s1
	// 		long tx; // $s0
	// 		long ty; // $a1
	// 		long tz; // $a0
	// 		long speed; // $s2
	/* end block 1 */
	// End offset: 0x8005B278
	// End Line: 893

	/* begin block 2 */
		// Start line: 2087
	/* end block 2 */
	// End Line: 2088

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Track_GolemMode(void)

{
  short sVar1;
  short sVar2;
  bool bVar3;
  int iVar4;
  int speed;
  long lVar5;
  long lVar6;
  
  lVar6 = Track_Target;
  iVar4 = rcos((int)*(short *)(Track_Target + 0x40));
  sVar1 = *(short *)(lVar6 + 0x2c);
  speed = rsin((int)*(short *)(lVar6 + 0x40));
  DAT_800b4162 = *(short *)(lVar6 + 0x2e) + (short)(speed * 800 >> 0xc);
  DAT_800b4164 = *(short *)(lVar6 + 0x30) + *(short *)(lVar6 + 0x70) + -100;
  speed = 8;
  DAT_800b4160 = sVar1 + (short)(iVar4 * 800 >> 0xc);
  do {
    lVar5 = Track_MoveTo(speed);
    if (lVar5 == 0) break;
    Task_Next();
    bVar3 = speed < 0x140;
    speed = speed + 8;
  } while (bVar3);
  sVar1 = *(short *)(lVar6 + 0x30);
  iVar4 = rcos((int)*(short *)(lVar6 + 0x40));
  sVar2 = *(short *)(lVar6 + 0x2c);
  speed = rsin((int)*(short *)(lVar6 + 0x40));
  DAT_800b415a = *(short *)(lVar6 + 0x2e) + (short)(speed * 0x578 >> 0xc);
  speed = 0x26;
  bVar3 = true;
  Cam_Target_ = sVar2 + (short)(iVar4 * 0x578 >> 0xc);
  DAT_800b415c = sVar1 + 100;
  while( true ) {
    if (!bVar3) {
      speed = 0x400;
    }
    lVar6 = Track_MoveTo(speed);
    if (lVar6 == 0) break;
    speed = speed + 8;
    Task_Next();
    bVar3 = speed < 0x401;
  }
  do {
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Track_GolemModeFlee()
 // line 896, offset 0x8005b278
	/* begin block 1 */
		// Start line: 897
		// Start offset: 0x8005B278
		// Variables:
	// 		struct _D3_OBJECT *o; // $s0
	// 		long x; // $s2
	// 		long y; // $s0
	// 		long z; // $s3
	// 		long speed; // $s1
	/* end block 1 */
	// End offset: 0x8005B364
	// End Line: 916

	/* begin block 2 */
		// Start line: 2165
	/* end block 2 */
	// End Line: 2166

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Track_GolemModeFlee(void)

{
  short sVar1;
  short sVar2;
  short sVar3;
  bool bVar4;
  long lVar5;
  int iVar6;
  int iVar7;
  int speed;
  
  lVar5 = Track_Target;
  sVar1 = *(short *)(Track_Target + 0x30);
  iVar6 = rcos((int)*(short *)(Track_Target + 0x40));
  sVar2 = *(short *)(lVar5 + 0x2c);
  iVar7 = rsin((int)*(short *)(lVar5 + 0x40));
  DAT_800b4160 = *(undefined2 *)(lVar5 + 0x2c);
  sVar3 = *(short *)(lVar5 + 0x2e);
  DAT_800b4162 = *(undefined2 *)(lVar5 + 0x2e);
  DAT_800b4164 = *(short *)(lVar5 + 0x30) + *(short *)(lVar5 + 0x70) + -100;
  speed = 0x10;
  bVar4 = true;
  do {
    if (!bVar4) {
      speed = 0x70;
    }
    Cam_Target_ = sVar2 + (short)(iVar6 * 800 >> 0xc);
    DAT_800b415a = sVar3 + (short)(iVar7 * 800 >> 0xc);
    DAT_800b415c = sVar1 + 300;
    Track_MoveTo(speed);
    speed = speed + 0x10;
    Task_Next();
    bVar4 = speed < 0x71;
  } while( true );
}





