#include "THISDUST.H"
#include "MOTION.H"


// decompiled code
// original method signature: 
// void /*$ra*/ Motion_Init()
 // line 29, offset 0x800a465c
	/* begin block 1 */
		// Start line: 59
	/* end block 1 */
	// End Line: 60

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Motion_Init(void)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Motion_InitEnv(struct MOTION_96fake *Env /*$s1*/, struct MOTION_72fake *Tmd /*$s0*/)
 // line 34, offset 0x800a4664
	/* begin block 1 */
		// Start line: 68
	/* end block 1 */
	// End Line: 69

void Motion_InitEnv(MOTION_96fake *Env,MOTION_72fake *Tmd)

{
  Tmd_InitFile((TMD_72fake *)Tmd);
  *(MOTION_72fake **)&(Env->Obj).vert_top = Tmd + 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Motion_InitAni(struct MOTION_98fake *buff /*$a0*/)
 // line 41, offset 0x800a46a0
	/* begin block 1 */
		// Start line: 43
		// Start offset: 0x800A46A0
		// Variables:
	// 		int i; // $t1
	// 		int Pivots; // $t2
	// 		int SizeRot; // $a2
	// 		int SizeHead; // $v1
	// 		int Version; // $v0
	// 		int Frames; // $t0
	// 		struct MOTION_97fake *base; // $a1
	/* end block 1 */
	// End offset: 0x800A47B8
	// End Line: 93

	/* begin block 2 */
		// Start line: 86
	/* end block 2 */
	// End Line: 87

void Motion_InitAni(MOTION_98fake *buff)

{
  ushort uVar1;
  int iVar2;
  ushort *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  MOTION_98fake *pMVar7;
  
  puVar3 = &(buff->Anim).Version + buff->nAnim * 2;
  if (buff->Text != 0x42424242) {
    iVar6 = 0;
    buff->Text = 0x42424242;
    pMVar7 = buff;
    if (0 < (int)buff->nAnim) {
      do {
        *(ushort **)&pMVar7->Anim = puVar3;
        uVar1 = puVar3[3];
        if (*puVar3 == 4) {
          iVar4 = 4;
          if (puVar3[1] == 1) {
            iVar4 = 0x14;
          }
          iVar5 = (uint)uVar1 + 1;
          iVar2 = iVar5 * 8 + 0x14;
          if (((puVar3[5] & 0x100) == 0) && (iVar2 = iVar2 + iVar5 * 2, (uVar1 & 1) == 0)) {
            iVar2 = iVar2 + 2;
          }
          *(int *)(puVar3 + 8) = (int)puVar3 + iVar2;
          puVar3 = (ushort *)((int)puVar3 + iVar2 + iVar4 * (uint)puVar3[2] * (uint)puVar3[3]);
        }
        else {
          if (*puVar3 == 0x4000) {
            iVar4 = 8;
            if (puVar3[1] == 1) {
              iVar4 = 0x10;
            }
            puVar3 = (ushort *)((int)puVar3 + iVar4 * (uint)puVar3[2] * (uint)uVar1 + 0x14);
          }
        }
        iVar6 = iVar6 + 1;
        pMVar7 = (MOTION_98fake *)&pMVar7->nAnim;
      } while (iVar6 < (int)buff->nAnim);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Motion_EnvRotTransPers(struct MOTION_94fake *sq /*$a0*/, struct MOTION_96fake *env /*$a1*/, struct MOTION_97fake *AnItem /*$s0*/, short nFrame /*$a0*/, struct MOTION_7fake *pos /*stack 16*/, struct MOTION_7fake *rot /*stack 20*/, long scale /*stack 24*/, TDRFuncPtr_Motion_EnvRotTransPers7modify modify /*stack 28*/)
 // line 96, offset 0x800a47c0
	/* begin block 1 */
		// Start line: 97
		// Start offset: 0x800A47C0
		// Variables:
	// 		struct MOTION_5fake Matrix; // stack offset -40
	// 		short *Altitude; // $v1
	/* end block 1 */
	// End offset: 0x800A4A54
	// End Line: 164

	/* begin block 2 */
		// Start line: 235
	/* end block 2 */
	// End Line: 236

void Motion_EnvRotTransPers
               (MOTION_94fake *sq,MOTION_96fake *env,undefined AnItem,short nFrame,undefined1 pos,
               undefined1 rot,long scale,TDRFuncPtr_Motion_EnvRotTransPers7modify modify)

{
  undefined4 in_zero;
  undefined4 in_at;
  undefined4 *puVar1;
  int iVar2;
  short *psVar3;
  undefined3 in_register_00000019;
  int iVar4;
  uint uVar5;
  MOTION_5fake MStack40;
  
  uVar5 = (uint)(ushort)nFrame;
  iVar4 = CONCAT31(in_register_00000019,AnItem);
  DAT_800b42f0 = scale;
  DAT_800b42ec = scale;
  Scale_Vector = scale;
  puVar1 = *(undefined4 **)&(env->Obj).vert_top;
  VerTop = *puVar1;
  NormTop = puVar1[2];
  ModifyAngle = modify;
  Scale = scale;
  if (*(short *)(iVar4 + 2) == 1) {
    iVar2 = (uint)*(ushort *)(iVar4 + 4) * (int)nFrame * 0x14;
  }
  else {
    iVar2 = (uint)*(ushort *)(iVar4 + 4) * (int)nFrame * 4;
  }
  MatrixRot = (_ROTMATRIX *)(*(int *)(iVar4 + 0x10) + iVar2);
  if ((*(ushort *)(iVar4 + 10) & 0x100) == 0) {
    psVar3 = (short *)(iVar4 + (uint)*(ushort *)(iVar4 + 6) * 8 + 0x1c +
                      ((int)(uVar5 << 0x10) >> 0xf));
  }
  else {
    psVar3 = (short *)(((int)(uVar5 << 0x10) >> 0xd) + iVar4 + 0x18);
  }
  DAT_800b430c._0_2_ = (short)((int)((int)*psVar3 * (uint)(sq->Header).Scale) >> 6);
  if (scale != 0) {
    DAT_800b430c._0_2_ = (short)((int)(short)DAT_800b430c * scale >> 0xc);
  }
  if ((*(ushort *)(iVar4 + 10) & 1) == 0) {
    Root._2_2_ = 0;
    Root._0_2_ = 0;
  }
  else {
    iVar2 = iVar4 + ((int)(uVar5 << 0x10) >> 0xd);
    Root._0_2_ = (short)((int)((int)*(short *)(iVar2 + 0x14) * (uint)(sq->Header).Scale) >> 6);
    Root._2_2_ = (short)((int)((int)*(short *)(iVar2 + 0x16) * (uint)(sq->Header).Scale) >> 6);
    if (scale != 0) {
      Root._0_2_ = (short)((int)(short)Root * scale >> 0xc);
      Root._2_2_ = (short)((int)Root._2_2_ * scale >> 0xc);
    }
  }
  setCopReg(2,in_zero,*_pos);
  setCopReg(2,in_at,_pos[1]);
  copFunction(2,0x486012);
  MStack40.t[0] = getCopReg(2,0x19);
  MStack40.t[1] = getCopReg(2,0x1a);
  MStack40.t[2] = getCopReg(2,0x1b);
  MStack40.t[0] = MStack40.t[0] + Cam_Matrix.t[0];
  MStack40.t[1] = MStack40.t[1] + Cam_Matrix.t[1];
  MStack40.t[2] = MStack40.t[2] + Cam_Matrix.t[2];
  Sq = sq;
  Env = env;
  RotMatrix(_rot,(undefined2 *)&MStack40);
  if (Scale != 0) {
    ScaleMatrix((uint *)&MStack40,&Scale_Vector);
  }
  MulRotMatrix((uint *)&MStack40);
  if (*(short *)(iVar4 + 2) == 1) {
    Motion_EnvPersMat(&MStack40,0);
  }
  else {
    Motion_EnvPersAng(&MStack40,0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Motion_EnvPersMat(struct MOTION_5fake *Father /*$a2*/, short PivotId /*$a3*/)
 // line 167, offset 0x800a4a64
	/* begin block 1 */
		// Start line: 168
		// Start offset: 0x800A4A64
		// Variables:
	// 		struct MOTION_5fake Matrix; // stack offset -56
	// 		struct MOTION_93fake *Pivot; // $s1
	// 		struct MOTION_95fake *EnvData; // $s0
	// 		long First; // $s4
	// 		long NormFirst; // $s3
	// 		long i; // $s0
	/* end block 1 */
	// End offset: 0x800A4CA4
	// End Line: 213

	/* begin block 2 */
		// Start line: 405
	/* end block 2 */
	// End Line: 406

void Motion_EnvPersMat(MOTION_5fake *Father,short PivotId)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 in_zero;
  undefined4 in_at;
  int iVar3;
  ushort *puVar4;
  _struct_15807 *p_Var5;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  int local_20;
  int local_1c;
  
  iVar3 = (int)PivotId;
  p_Var5 = &Sq->Data + iVar3;
  puVar4 = (ushort *)((int)&(Env->Obj).vert_top + iVar3 * 0xc + 4);
  uVar1 = puVar4[1];
  uVar2 = puVar4[5];
  setCopControlWord(2,0,*(undefined4 *)Father->m);
  setCopControlWord(2,0x800,*(undefined4 *)(Father->m + 2));
  setCopControlWord(2,0x1000,*(undefined4 *)(Father->m + 4));
  setCopControlWord(2,0x1800,*(undefined4 *)(Father->m + 6));
  setCopControlWord(2,0x2000,*(undefined4 *)(Father->m + 8));
  if (iVar3 == 0) {
    setCopReg(2,in_zero,Root);
    setCopReg(2,in_at,DAT_800b430c);
    copFunction(2,0x486012);
    local_24 = getCopReg(2,0x19);
    local_20 = getCopReg(2,0x1a);
    local_1c = getCopReg(2,0x1b);
  }
  else {
    setCopReg(2,in_zero,*(undefined4 *)p_Var5->FatherTrans);
    setCopReg(2,in_at,*(undefined4 *)(p_Var5->FatherTrans + 2));
    copFunction(2,0x486012);
    local_24 = getCopReg(2,0x19);
    local_20 = getCopReg(2,0x1a);
    local_1c = getCopReg(2,0x1b);
  }
  local_24 = local_24 + Father->t[0];
  local_20 = local_20 + Father->t[1];
  local_1c = local_1c + Father->t[2];
  SetMulMatrix((undefined4 *)Father,(ushort *)(MatrixRot + (int)PivotId));
  setCopControlWord(2,0x2800,local_24);
  setCopControlWord(2,0x3000,local_20);
  setCopControlWord(2,0x3800,local_1c);
  if (puVar4[4] != 0) {
    GtxTmd_RotN(NormTop + (uint)uVar2 * 8,Tmd_2D + (uint)uVar2,(uint)puVar4[4]);
  }
  if (*puVar4 != 0) {
    GtxTmd_RotTransPersN(VerTop + (uint)uVar1 * 8,Tmd_2D + (uint)uVar1,(uint)*puVar4);
  }
  if (p_Var5->nSon != '\0') {
    local_38 = getCopControlWord(2,0);
    local_34 = getCopControlWord(2,0x800);
    local_30 = getCopControlWord(2,0x1000);
    local_2c = getCopControlWord(2,0x1800);
    local_28 = getCopControlWord(2,0x2000);
    local_24 = getCopControlWord(2,0x2800);
    local_20 = getCopControlWord(2,0x3000);
    local_1c = getCopControlWord(2,0x3800);
    iVar3 = 0;
    if (p_Var5->nSon != '\0') {
      do {
        Motion_EnvPersMat((MOTION_5fake *)&local_38,
                          (short)(((uint)p_Var5->TopSonId + iVar3) * 0x10000 >> 0x10));
        iVar3 = iVar3 + 1;
      } while (iVar3 < (int)(uint)p_Var5->nSon);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Motion_EnvPersAng(struct MOTION_5fake *Father /*$s2*/, short PivotId /*$a2*/)
 // line 216, offset 0x800a4cc4
	/* begin block 1 */
		// Start line: 217
		// Start offset: 0x800A4CC4
		// Variables:
	// 		struct MOTION_5fake Matrix; // stack offset -56
	// 		struct MOTION_93fake *Pivot; // $s1
	// 		struct MOTION_95fake *EnvData; // $s0
	// 		long VerFirst; // $s4
	// 		long NormFirst; // $s3

		/* begin block 1.1 */
			// Start line: 274
			// Start offset: 0x800A4F64
			// Variables:
		// 		long i; // $s0
		/* end block 1.1 */
		// End offset: 0x800A4FE0
		// End Line: 282
	/* end block 1 */
	// End offset: 0x800A4FE0
	// End Line: 283

	/* begin block 2 */
		// Start line: 522
	/* end block 2 */
	// End Line: 523

void Motion_EnvPersAng(MOTION_5fake *Father,short PivotId)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 in_zero;
  undefined4 in_at;
  int iVar3;
  ushort *puVar4;
  _struct_15807 *p_Var5;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  int local_20;
  int local_1c;
  
  iVar3 = (int)PivotId;
  p_Var5 = &Sq->Data + iVar3;
  puVar4 = (ushort *)((int)&(Env->Obj).vert_top + iVar3 * 0xc + 4);
  uVar1 = puVar4[1];
  uVar2 = puVar4[5];
  setCopControlWord(2,0,*(undefined4 *)Father->m);
  setCopControlWord(2,0x800,*(undefined4 *)(Father->m + 2));
  setCopControlWord(2,0x1000,*(undefined4 *)(Father->m + 4));
  setCopControlWord(2,0x1800,*(undefined4 *)(Father->m + 6));
  setCopControlWord(2,0x2000,*(undefined4 *)(Father->m + 8));
  if (iVar3 == 0) {
    setCopReg(2,in_zero,Root);
    setCopReg(2,in_at,DAT_800b430c);
    copFunction(2,0x486012);
    local_24 = getCopReg(2,0x19);
    local_20 = getCopReg(2,0x1a);
    local_1c = getCopReg(2,0x1b);
  }
  else {
    setCopReg(2,in_zero,*(undefined4 *)p_Var5->FatherTrans);
    setCopReg(2,in_at,*(undefined4 *)(p_Var5->FatherTrans + 2));
    copFunction(2,0x486012);
    local_24 = getCopReg(2,0x19);
    local_20 = getCopReg(2,0x1a);
    local_1c = getCopReg(2,0x1b);
  }
  if (Scale != 0) {
    local_24 = local_24 * Scale >> 0xc;
    local_20 = local_20 * Scale >> 0xc;
    local_1c = local_1c * Scale >> 0xc;
  }
  local_24 = local_24 + Father->t[0];
  local_20 = local_20 + Father->t[1];
  AngleRot = (long *)((int)MatrixRot->m + ((int)((uint)(ushort)PivotId << 0x10) >> 0xe));
  local_1c = local_1c + Father->t[2];
  DAT_800b4304 = (undefined2)((*AngleRot >> 0x15) << 1);
  DAT_800b4302 = (ushort)((uint)*AngleRot >> 9) & 0x800 | (ushort)((uint)*AngleRot >> 10) & 0x7ff;
  Angle = (undefined2)(((uint)*(ushort *)AngleRot & 0x7ff) << 1);
  if ((p_Var5->Flag != 0) && (ModifyAngle != (code *)0x0)) {
    (*ModifyAngle)((uint)p_Var5->Flag,&Angle);
  }
  RotMatrix(&Angle,(undefined2 *)&local_38);
  SetMulMatrix((undefined4 *)Father,(ushort *)&local_38);
  setCopControlWord(2,0x2800,local_24);
  setCopControlWord(2,0x3000,local_20);
  setCopControlWord(2,0x3800,local_1c);
  if (puVar4[4] != 0) {
    GtxTmd_RotN(NormTop + (uint)uVar2 * 8,Tmd_2D + (uint)uVar2,(uint)puVar4[4]);
  }
  if (*puVar4 != 0) {
    GtxTmd_RotTransPersN(VerTop + (uint)uVar1 * 8,Tmd_2D + (uint)uVar1,(uint)*puVar4);
  }
  if (p_Var5->nSon != '\0') {
    local_38 = getCopControlWord(2,0);
    local_34 = getCopControlWord(2,0x800);
    local_30 = getCopControlWord(2,0x1000);
    local_2c = getCopControlWord(2,0x1800);
    local_28 = getCopControlWord(2,0x2000);
    local_24 = getCopControlWord(2,0x2800);
    local_20 = getCopControlWord(2,0x3000);
    local_1c = getCopControlWord(2,0x3800);
    iVar3 = 0;
    if (p_Var5->nSon != '\0') {
      do {
        Motion_EnvPersAng((MOTION_5fake *)&local_38,
                          (short)(((uint)p_Var5->TopSonId + iVar3) * 0x10000 >> 0x10));
        iVar3 = iVar3 + 1;
      } while (iVar3 < (int)(uint)p_Var5->nSon);
    }
  }
  return;
}



// autogenerated function stub: 
// void __rdata_obj() /* __rdata_obj method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
void __rdata_obj() 
{ // line 392, offset 0x800a5000
	return null;
}




