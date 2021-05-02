#include "THISDUST.H"
#include "CAMERA.H"


// decompiled code
// original method signature: 
// void /*$ra*/ Cam_SetMatrix(struct CAMERA_7fake *Camera /*$a0*/, struct CAMERA_7fake *Vise /*$s4*/)
 // line 21, offset 0x8009fab8
	/* begin block 1 */
		// Start line: 22
		// Start offset: 0x8009FAB8
		// Variables:
	// 		long vx; // $s2
	// 		long vy; // $s3
	// 		long vz; // $s1
	// 		long r1; // $s0
	// 		long r2; // $a1
	// 		long sina; // $a3
	// 		long cosa; // $a2
	// 		long cosb; // $a0
	// 		long sinb; // $v1
	/* end block 1 */
	// End offset: 0x8009FC40
	// End Line: 34

	/* begin block 2 */
		// Start line: 42
	/* end block 2 */
	// End Line: 43

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Cam_SetMatrix(undefined Camera,undefined Vise)

{
  undefined4 in_zero;
  undefined4 in_at;
  uint uVar1;
  uint uVar2;
  undefined3 in_register_00000011;
  short *psVar3;
  undefined3 in_register_00000015;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  
  puVar4 = (undefined4 *)CONCAT31(in_register_00000015,Vise);
  psVar3 = (short *)CONCAT31(in_register_00000011,Camera);
  iVar7 = (int)*psVar3 - (int)*(short *)puVar4;
  iVar8 = (int)psVar3[1] - (int)*(short *)((int)puVar4 + 2);
  iVar5 = iVar7 * iVar7 + iVar8 * iVar8;
  iVar6 = (int)psVar3[2] - (int)*(short *)(puVar4 + 1);
  uVar1 = SquareRoot0(iVar5);
  uVar2 = SquareRoot0(iVar5 + iVar6 * iVar6);
  if (uVar2 == 0) {
    uVar9 = 0;
  }
  else {
    uVar9 = (iVar6 * -0x1000) / (int)uVar2;
    if (uVar2 == 0) {
      trap(0x1c00);
    }
    in_at = 0x80000000;
    if ((uVar2 == 0xffffffff) && (iVar6 * -0x1000 == -0x80000000)) {
      trap(0x1800);
    }
  }
  if (uVar2 == 0) {
    iVar5 = 0x1000;
  }
  else {
    iVar5 = (int)(uVar1 << 0xc) / (int)uVar2;
    if (uVar2 == 0) {
      trap(0x1c00);
    }
    in_at = 0x80000000;
    if ((uVar2 == 0xffffffff) && (uVar1 << 0xc == -0x80000000)) {
      trap(0x1800);
    }
  }
  if (uVar1 == 0) {
    iVar6 = 0x1000;
  }
  else {
    iVar6 = (iVar7 * 0x1000) / (int)uVar1;
    if (uVar1 == 0) {
      trap(0x1c00);
    }
    in_at = 0x80000000;
    if ((uVar1 == 0xffffffff) && (iVar7 * 0x1000 == -0x80000000)) {
      trap(0x1800);
    }
  }
  if (uVar1 == 0) {
    uVar10 = 0;
  }
  else {
    uVar10 = (iVar8 * -0x1000) / (int)uVar1;
    if (uVar1 == 0) {
      trap(0x1c00);
    }
    in_at = 0x80000000;
    if ((uVar1 == 0xffffffff) && (iVar8 * -0x1000 == -0x80000000)) {
      trap(0x1800);
    }
  }
  Cam_Matrix.m[0]._0_4_ = uVar10 & 0xffff | iVar6 << 0x10;
  Cam_Matrix._16_4_ = Cam_Matrix._16_4_ & 0xffff0000 | uVar9 & 0xffff;
  Cam_Matrix.m._4_4_ = ((int)(-uVar9 * iVar6) >> 0xc) << 0x10;
  Cam_Matrix.m[1]._2_4_ = (int)(uVar9 * uVar10) >> 0xc & 0xffffU | iVar5 * -0x10000;
  Cam_Matrix.m[2]._0_4_ = -iVar5 * iVar6 >> 0xc & 0xffffU | ((int)(iVar5 * uVar10) >> 0xc) << 0x10;
  setCopControlWord(2,0,Cam_Matrix.m[0]._0_4_);
  setCopControlWord(2,0x800,Cam_Matrix.m._4_4_);
  setCopControlWord(2,0x1000,Cam_Matrix.m[1]._2_4_);
  setCopControlWord(2,0x1800,Cam_Matrix.m[2]._0_4_);
  setCopControlWord(2,0x2000,Cam_Matrix._16_4_);
  setCopReg(2,in_zero,*puVar4);
  setCopReg(2,in_at,puVar4[1]);
  copFunction(2,0x486012);
  iVar5 = getCopReg(2,0x19);
  iVar6 = getCopReg(2,0x1a);
  iVar7 = getCopReg(2,0x1b);
  setCopControlWord(2,0x2800,-iVar5);
  setCopControlWord(2,0x3000,-iVar6);
  setCopControlWord(2,0x3800,uVar2 - iVar7);
  Cam_Matrix.t[0] = -iVar5;
  Cam_Matrix.t[1] = -iVar6;
  Cam_Matrix.t[2] = uVar2 - iVar7;
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Cam_MoveTo(long Weight /*$a3*/)
 // line 50, offset 0x8009fd64
	/* begin block 1 */
		// Start line: 51
		// Start offset: 0x8009FD64
		// Variables:
	// 		struct CAMERA_7fake Diff[2]; // stack offset -24
	// 		long i; // $t0
	/* end block 1 */
	// End offset: 0x8009FEAC
	// End Line: 72

	/* begin block 2 */
		// Start line: 118
	/* end block 2 */
	// End Line: 119

/* WARNING: Type propagation algorithm not settling */

long Cam_MoveTo(long Weight)

{
  short *psVar1;
  short *psVar2;
  long lVar3;
  short *psVar4;
  short *psVar5;
  short *psVar6;
  int iVar7;
  short local_18;
  short local_16;
  short local_14;
  short local_10;
  short local_e;
  short local_c;
  
  iVar7 = 0;
  psVar6 = (short *)&local_18;
  psVar5 = &Cam_Pos_;
  psVar4 = &Cam_Target_;
  do {
    *psVar6 = *psVar4 - *psVar5;
    iVar7 = iVar7 + 1;
    psVar6[1] = psVar4[1] - psVar5[1];
    psVar1 = psVar5 + 2;
    psVar5 = psVar5 + 4;
    psVar2 = psVar4 + 2;
    psVar4 = psVar4 + 4;
    psVar6[2] = *psVar2 - *psVar1;
    psVar6 = psVar6 + 4;
  } while (iVar7 < 2);
  gteMIMefunc((undefined4 *)&Cam_Pos_,&local_18,2,Weight);
  iVar7 = (int)local_18;
  if (iVar7 < 0) {
    iVar7 = -iVar7;
  }
  lVar3 = 1;
  if (iVar7 < 0x15) {
    iVar7 = (int)local_16;
    if (iVar7 < 0) {
      iVar7 = -iVar7;
    }
    lVar3 = 1;
    if (iVar7 < 0x15) {
      iVar7 = (int)local_14;
      if (iVar7 < 0) {
        iVar7 = -iVar7;
      }
      lVar3 = 1;
      if (iVar7 < 0x15) {
        iVar7 = (int)local_10;
        if (iVar7 < 0) {
          iVar7 = -iVar7;
        }
        lVar3 = 1;
        if (iVar7 < 0x15) {
          iVar7 = (int)local_e;
          if (iVar7 < 0) {
            iVar7 = -iVar7;
          }
          lVar3 = 1;
          if (iVar7 < 0x15) {
            iVar7 = (int)local_c;
            if (iVar7 < 0) {
              iVar7 = -iVar7;
            }
            lVar3 = 0;
            if (0x14 < iVar7) {
              lVar3 = 1;
            }
          }
        }
      }
    }
  }
  return lVar3;
}





