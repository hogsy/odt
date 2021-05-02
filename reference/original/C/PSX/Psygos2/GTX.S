// WARNING: This file's extension ('.S') indicates that it may not have been a C or C++ file.
// It should contain Ghidra's best effort at decompiling the machine language to C, 
// but TDR does not currently attempt to handle assembly language or other non-C/C++ code differently, 
// so any decompiled code below may not reflect the original project source code for this file.
// If the source file is from a library, you should replace it with the original library version of the file.
// Otherwise, manual reconstruction of the code may be required, 
// Especially if the original source code was assembly language which used hardware features inaccessible to C.
#include "THISDUST.H"
#include "GTX.H"


// decompiled code
// original method signature: 
// void GtxTmd_RotTransPersN1() /* GtxTmd_RotTransPersN1 method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 408, offset 0x800180ac
void GtxTmd_RotTransPersN1(undefined4 *puParm1,undefined4 *puParm2,int iParm3)

{
  undefined4 in_zero;
  undefined4 in_at;
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  setCopReg(2,in_zero,*puParm1);
  setCopReg(2,in_at,puParm1[1]);
  puParm1 = puParm1 + 2;
  copFunction(2,0x180001);
  while( true ) {
    iVar3 = getCopReg(2,0x4000);
    uVar1 = getCopReg(2,0x7000);
    uVar2 = getCopReg(2,0x9800);
    setCopReg(2,in_zero,*puParm1);
    setCopReg(2,in_at,puParm1[1]);
    puParm1 = puParm1 + 2;
    iParm3 = iParm3 + -1;
    copFunction(2,0x180001);
    *puParm2 = uVar1;
    puParm2[1] = uVar2 | iVar3 << 0x10;
    if (iParm3 == 0) break;
    puParm2 = puParm2 + 4;
  }
  return;
}



// decompiled code
// original method signature: 
// void GtxTmd_RotTransPersN() /* GtxTmd_RotTransPersN method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 473, offset 0x8001810c
void GtxTmd_RotTransPersN(undefined4 *puParm1,undefined4 *puParm2,int iParm3)

{
  undefined4 in_zero;
  undefined4 in_at;
  undefined4 in_v0;
  undefined4 in_v1;
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  
  setCopReg(2,in_zero,*puParm1);
  setCopReg(2,in_at,puParm1[1]);
  setCopReg(2,in_v0,puParm1[2]);
  setCopReg(2,in_v1,puParm1[3]);
  setCopReg(2,puParm1,puParm1[4]);
  setCopReg(2,puParm2,puParm1[5]);
  puParm1 = puParm1 + 6;
  copFunction(2,0x280030);
  while( true ) {
    uVar1 = getCopReg(2,0x6000);
    uVar2 = getCopReg(2,0x6800);
    uVar3 = getCopReg(2,0x7000);
    iVar7 = getCopReg(2,0x4000);
    uVar4 = getCopReg(2,0x8800);
    uVar5 = getCopReg(2,0x9000);
    uVar6 = getCopReg(2,0x9800);
    uVar8 = iVar7 << 0x10;
    setCopReg(2,in_zero,*puParm1);
    setCopReg(2,in_at,puParm1[1]);
    setCopReg(2,in_v0,puParm1[2]);
    setCopReg(2,in_v1,puParm1[3]);
    setCopReg(2,puParm1,puParm1[4]);
    setCopReg(2,puParm2,puParm1[5]);
    puParm1 = puParm1 + 6;
    copFunction(2,0x280030);
    *puParm2 = uVar1;
    puParm2[1] = uVar4 | uVar8;
    if (iParm3 == 1) {
      return;
    }
    puParm2[4] = uVar2;
    puParm2[5] = uVar5 | uVar8;
    if (iParm3 == 2) break;
    puParm2[8] = uVar3;
    iParm3 = iParm3 + -3;
    puParm2[9] = uVar6 | uVar8;
    if (iParm3 == 0) {
      return;
    }
    puParm2 = puParm2 + 0xc;
  }
  return;
}



// decompiled code
// original method signature: 
// void GtxTmd_DisplayLON() /* GtxTmd_DisplayLON method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 605, offset 0x800181c4
/* WARNING: Instruction at (ram,0x8001845c) overlaps instruction at (ram,0x80018458)
    */

undefined8
GtxTmd_DisplayLON(int *param_1,uint *param_2,int param_3,int param_4,int param_5,uint param_6)

{
  uint uVar1;
  uint uVar2;
  undefined4 in_zero;
  undefined4 in_at;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  uint *puVar9;
  uint *puVar10;
  uint uVar11;
  undefined4 *puVar12;
  uint uVar13;
  uint uVar14;
  undefined4 *puVar15;
  uint uVar16;
  undefined4 *puVar17;
  uint uVar18;
  int *piVar19;
  int *in_t6;
  int *in_t7;
  int iVar20;
  int iVar21;
  
  iVar20 = *param_1;
  iVar21 = param_1[2];
  DAT_1f800050 = param_5;
  DAT_1f800008 = param_6 & 0xffffff;
  iVar3 = param_1[5];
  puVar9 = (uint *)param_1[4];
  puVar10 = (uint *)0x0;
  DAT_1f800000 = param_3;
  DAT_1f800004 = param_4;
  do {
    uVar7 = DAT_1f800048;
    uVar11 = *puVar9;
    if ((uVar11 & 0x4000000) == 0) {
      uVar5 = puVar9[1];
      puVar8 = puVar9;
    }
    else {
      puVar8 = puVar9 + 2;
      uVar5 = DAT_1f800008;
      DAT_1f800040 = puVar9;
    }
    uVar18 = puVar8[2];
    if ((uVar11 & 0x10000000) == 0) {
      uVar13 = puVar8[3];
      puVar9 = puVar8 + 4;
      uVar14 = uVar13 & 0xffff;
    }
    else {
      uVar13 = puVar8[4];
      uVar14 = (int)puVar8[3] >> 0x10;
      in_t6 = (int *)(puVar8[3] & 0xffff);
      in_t7 = (int *)(uVar13 & 0xffff);
      puVar9 = puVar8 + 5;
    }
    puVar12 = (undefined4 *)(iVar20 + ((int)uVar18 >> 0x10) * 8);
    puVar15 = (undefined4 *)(iVar20 + uVar14 * 8);
    puVar17 = (undefined4 *)(iVar20 + ((int)uVar13 >> 0x10) * 8);
    DAT_1f800030 = getCopReg(2,0x14);
    DAT_1f800034 = getCopReg(2,0x15);
    DAT_1f800038 = getCopReg(2,0x16);
    setCopReg(2,in_zero,*puVar12);
    setCopReg(2,in_at,puVar12[1]);
    setCopReg(2,uVar11 & 0x4000000,*puVar15);
    setCopReg(2,uVar11 & 0x10000000,puVar15[1]);
    setCopReg(2,puVar9,*puVar17);
    setCopReg(2,param_2,puVar17[1]);
    copFunction(2,0x280030);
    DAT_1f80000c = iVar3;
    if (puVar10 != (uint *)0x0) {
      puVar8 = (uint *)(DAT_1f800000 + DAT_1f80004c * 4);
      uVar6 = DAT_1f800048 & 0xff000000;
      DAT_1f80000c = iVar3;
      *puVar10 = DAT_1f800048 << 0x18 | *puVar8;
      *puVar8 = (uint)puVar10 & 0xffffff;
      uVar2 = DAT_1f800038;
      uVar1 = DAT_1f800034;
      uVar16 = DAT_1f800018;
      uVar14 = DAT_1f800014;
      uVar13 = DAT_1f800010;
      param_2 = param_2 + (uVar7 & 0xff) + 1;
      if ((uVar7 & 0x4000000) == 0) {
        if ((uVar7 & 0x10000000) == 0) {
          puVar10[1] = DAT_1f800038 | uVar6;
          puVar10[2] = uVar13;
          puVar10[3] = uVar14;
          puVar10[4] = uVar16;
        }
        else {
          puVar10[1] = DAT_1f800030 | uVar6;
          puVar10[3] = uVar1;
          puVar10[5] = uVar2;
          uVar13 = DAT_1f800018;
          uVar7 = DAT_1f800014;
          puVar10[2] = DAT_1f800010;
          puVar10[4] = uVar7;
          puVar10[6] = uVar13;
        }
      }
      else {
        if ((uVar7 & 0x10000000) == 0) {
          puVar10[1] = DAT_1f800038 | uVar6;
          puVar10[2] = uVar13;
          uVar7 = DAT_1f800018;
          puVar10[4] = DAT_1f800014;
          puVar10[6] = uVar7;
          uVar7 = DAT_1f800044[2];
          uVar13 = DAT_1f800044[3];
          puVar10[3] = DAT_1f800044[1];
          puVar10[5] = uVar7;
          puVar10[7] = uVar13;
        }
        else {
          uVar7 = DAT_1f800044[1];
          puVar10[1] = DAT_1f800030 | uVar6;
          puVar10[2] = uVar13;
          puVar10[3] = uVar7;
          puVar10[4] = uVar1;
          uVar13 = DAT_1f800038;
          uVar7 = DAT_1f800018;
          uVar16 = DAT_1f800044[2];
          uVar14 = DAT_1f800044[3];
          puVar10[5] = DAT_1f800014;
          puVar10[6] = uVar16;
          puVar10[7] = uVar13;
          puVar10[8] = uVar7;
          puVar10[9] = uVar14;
        }
      }
    }
    DAT_1f800044 = DAT_1f800040;
    copFunction(2,0x1400006);
    puVar10 = (uint *)0x0;
    iVar3 = getCopReg(2,0xc000);
    uVar7 = uVar11 & 0x20000;
    copFunction(2,0x158002d);
    if (uVar7 == 0) {
      iVar4 = getCopReg(2,0x3800);
      if (iVar3 >= 0) goto code_r0x80018460;
    }
    else {
      iVar4 = getCopReg(2,0x3800);
code_r0x80018460:
      uVar7 = (uint)(iVar3 < 0) & (int)uVar7 >> 0x11;
      iVar4 = iVar4 - DAT_1f800050;
      if (4 < iVar4) {
        if (DAT_1f800004 == 0) {
          DAT_1f80004c = 0;
        }
        else {
          DAT_1f800048 = uVar11;
          DAT_1f80004c = iVar4;
          if (DAT_1f800004 <= iVar4) goto LAB_8001858c;
        }
        DAT_1f800010 = getCopReg(2,0xc);
        DAT_1f800014 = getCopReg(2,0xd);
        DAT_1f800018 = getCopReg(2,0xe);
        piVar19 = (int *)(iVar21 + (uVar18 & 0xffff) * 8);
        if (uVar7 == 0) {
          setCopReg(2,in_zero,*piVar19);
          setCopReg(2,in_at,piVar19[1]);
          uVar7 = uVar11 & 0x10000000;
          setCopReg(2,0x3000,uVar5);
          if (uVar7 == 0) goto code_r0x80018588;
          in_t6 = (int *)(iVar21 + (int)in_t6 * 8);
          in_t7 = (int *)(iVar21 + (int)in_t7 * 8);
          setCopReg(2,0x10000000,*in_t6);
          setCopReg(2,uVar7,in_t6[1]);
          setCopReg(2,puVar9,*in_t7);
          setCopReg(2,param_2,in_t7[1]);
          copFunction(2,0xf80416);
          puVar10 = param_2;
          DAT_1f800048 = uVar11;
        }
        else {
          setCopReg(2,0,-(*piVar19 + -0x10000));
          setCopReg(2,0x800,-piVar19[1]);
          setCopReg(2,0x3000,uVar5);
          if ((uVar11 & 0x10000000) == 0) {
code_r0x80018588:
            uVar7 = uVar11 & 0x10000000;
            copFunction(2,0xe80413);
            puVar10 = param_2;
            DAT_1f800048 = uVar11;
          }
          else {
            in_t6 = (int *)(iVar21 + (int)in_t6 * 8);
            in_t7 = (int *)(iVar21 + (int)in_t7 * 8);
            setCopReg(2,0x1000,-(*in_t6 + -0x10000));
            setCopReg(2,0x1800,-in_t6[1]);
            uVar7 = -in_t7[1];
            setCopReg(2,0x2000,-(*in_t7 + -0x10000));
            setCopReg(2,0x2800,uVar7);
            copFunction(2,0xf80416);
            puVar10 = param_2;
            DAT_1f800048 = uVar11;
          }
        }
      }
    }
LAB_8001858c:
    uVar11 = DAT_1f800048;
    iVar3 = DAT_1f80000c + -1;
    if (iVar3 == 0) {
      if (puVar10 != (uint *)0x0) {
        puVar9 = (uint *)(DAT_1f800000 + DAT_1f80004c * 4);
        uVar7 = DAT_1f800048 & 0xff000000;
        *puVar10 = DAT_1f800048 << 0x18 | *puVar9;
        *puVar9 = (uint)puVar10 & 0xffffff;
        puVar9 = DAT_1f800044;
        uVar16 = DAT_1f800018;
        uVar14 = DAT_1f800014;
        uVar13 = DAT_1f800010;
        param_2 = param_2 + (uVar11 & 0xff) + 1;
        DAT_1f800030 = getCopReg(2,0x14);
        uVar5 = getCopReg(2,0x15);
        uVar18 = getCopReg(2,0x16);
        if ((uVar11 & 0x4000000) == 0) {
          if ((uVar11 & 0x10000000) == 0) {
            DAT_1f800034 = uVar5;
            DAT_1f800038 = uVar18;
            puVar10[1] = uVar18 | uVar7;
            puVar10[2] = uVar13;
            puVar10[3] = uVar14;
            puVar10[4] = uVar16;
          }
          else {
            DAT_1f800034 = uVar5;
            DAT_1f800038 = uVar18;
            puVar10[1] = DAT_1f800030 | uVar7;
            puVar10[3] = uVar5;
            puVar10[5] = uVar18;
            uVar5 = DAT_1f800018;
            uVar11 = DAT_1f800014;
            puVar10[2] = DAT_1f800010;
            puVar10[4] = uVar11;
            puVar10[6] = uVar5;
          }
        }
        else {
          if ((uVar11 & 0x10000000) == 0) {
            DAT_1f800034 = uVar5;
            DAT_1f800038 = uVar18;
            puVar10[1] = uVar18 | uVar7;
            puVar10[2] = uVar13;
            puVar9 = DAT_1f800044;
            uVar11 = DAT_1f800018;
            puVar10[4] = DAT_1f800014;
            puVar10[6] = uVar11;
            uVar11 = puVar9[2];
            uVar5 = puVar9[3];
            puVar10[3] = puVar9[1];
            puVar10[5] = uVar11;
            puVar10[7] = uVar5;
          }
          else {
            uVar11 = DAT_1f800044[1];
            DAT_1f800034 = uVar5;
            DAT_1f800038 = uVar18;
            puVar10[1] = DAT_1f800030 | uVar7;
            puVar10[2] = uVar13;
            puVar10[3] = uVar11;
            puVar10[4] = uVar5;
            uVar11 = DAT_1f800038;
            uVar7 = DAT_1f800018;
            uVar18 = puVar9[2];
            uVar5 = puVar9[3];
            puVar10[5] = DAT_1f800014;
            puVar10[6] = uVar18;
            puVar10[7] = uVar11;
            puVar10[8] = uVar7;
            puVar10[9] = uVar5;
          }
        }
      }
      return CONCAT44(param_2,uVar7);
    }
  } while( true );
}



// decompiled code
// original method signature: 
// void GtxTmd_DisplayLOFF() /* GtxTmd_DisplayLOFF method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 921, offset 0x8001872c
/* WARNING: Instruction at (ram,0x80018988) overlaps instruction at (ram,0x80018984)
    */

undefined8 GtxTmd_DisplayLOFF(int *param_1,uint *param_2,int param_3,int param_4,int param_5)

{
  uint uVar1;
  uint uVar2;
  undefined4 in_zero;
  undefined4 in_at;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  int *piVar9;
  uint *puVar10;
  uint uVar11;
  int iVar12;
  undefined4 *puVar13;
  uint *puVar14;
  undefined4 *puVar15;
  uint uVar16;
  uint uVar17;
  undefined4 *puVar18;
  int in_t5;
  int in_t6;
  int iVar19;
  
  iVar3 = param_1[5];
  iVar19 = *param_1;
  piVar8 = (int *)param_1[4];
  DAT_1f800050 = param_5;
  puVar10 = (uint *)0x0;
  DAT_1f800000 = param_3;
  DAT_1f800004 = param_4;
  do {
    uVar7 = DAT_1f800048;
    uVar11 = *piVar8 - 0x1000000;
    piVar9 = piVar8;
    if ((uVar11 & 0x4000000) != 0) {
      piVar9 = piVar8 + 3;
      DAT_1f800040 = piVar8;
    }
    iVar12 = piVar9[1];
    if ((uVar11 & 0x10000000) != 0) {
      in_t5 = piVar9[2];
      in_t6 = piVar9[3];
      piVar9 = piVar9 + 2;
    }
    piVar8 = piVar9 + 4;
    puVar13 = (undefined4 *)(iVar19 + (piVar9[2] & 0xffffU) * 8);
    puVar15 = (undefined4 *)(iVar19 + (piVar9[2] >> 0x10) * 8);
    puVar18 = (undefined4 *)(iVar19 + (int)*(short *)(piVar9 + 3) * 8);
    DAT_1f800030 = getCopReg(2,0x14);
    DAT_1f800034 = getCopReg(2,0x15);
    DAT_1f800038 = getCopReg(2,0x16);
    setCopReg(2,in_zero,*puVar13);
    setCopReg(2,in_at,puVar13[1]);
    setCopReg(2,uVar11 & 0x4000000,*puVar15);
    setCopReg(2,uVar11 & 0x10000000,puVar15[1]);
    setCopReg(2,piVar8,*puVar18);
    setCopReg(2,param_2,puVar18[1]);
    copFunction(2,0x280030);
    DAT_1f80000c = iVar3;
    if (puVar10 != (uint *)0x0) {
      puVar14 = (uint *)(DAT_1f800000 + DAT_1f80004c * 4);
      uVar6 = DAT_1f800048 & 0xff000000;
      DAT_1f80000c = iVar3;
      *puVar10 = DAT_1f800048 << 0x18 | *puVar14;
      *puVar14 = (uint)puVar10 & 0xffffff;
      uVar2 = DAT_1f800038;
      uVar1 = DAT_1f800034;
      uVar16 = DAT_1f800018;
      uVar17 = DAT_1f800014;
      uVar5 = DAT_1f800010;
      param_2 = param_2 + (uVar7 & 0xff) + 1;
      if ((uVar7 & 0x4000000) == 0) {
        if ((uVar7 & 0x10000000) == 0) {
          puVar10[1] = DAT_1f800038 | uVar6;
          puVar10[2] = uVar5;
          puVar10[3] = uVar17;
          puVar10[4] = uVar16;
        }
        else {
          puVar10[1] = DAT_1f800030 | uVar6;
          puVar10[3] = uVar1;
          puVar10[5] = uVar2;
          uVar5 = DAT_1f800018;
          uVar7 = DAT_1f800014;
          puVar10[2] = DAT_1f800010;
          puVar10[4] = uVar7;
          puVar10[6] = uVar5;
        }
      }
      else {
        if ((uVar7 & 0x10000000) == 0) {
          puVar10[1] = DAT_1f800038 | uVar6;
          puVar10[2] = uVar5;
          uVar7 = DAT_1f800018;
          puVar10[4] = DAT_1f800014;
          puVar10[6] = uVar7;
          uVar7 = DAT_1f800044[2];
          uVar5 = DAT_1f800044[3];
          puVar10[3] = DAT_1f800044[1];
          puVar10[5] = uVar7;
          puVar10[7] = uVar5;
        }
        else {
          uVar7 = DAT_1f800044[1];
          puVar10[1] = DAT_1f800030 | uVar6;
          puVar10[2] = uVar5;
          puVar10[3] = uVar7;
          puVar10[4] = uVar1;
          uVar5 = DAT_1f800038;
          uVar7 = DAT_1f800018;
          uVar16 = DAT_1f800044[2];
          uVar17 = DAT_1f800044[3];
          puVar10[5] = DAT_1f800014;
          puVar10[6] = uVar16;
          puVar10[7] = uVar5;
          puVar10[8] = uVar7;
          puVar10[9] = uVar17;
        }
      }
    }
    DAT_1f800044 = DAT_1f800040;
    copFunction(2,0x1400006);
    puVar10 = (uint *)0x0;
    iVar3 = getCopReg(2,0xc000);
    uVar7 = uVar11 & 0x20000;
    copFunction(2,0x158002d);
    if (uVar7 == 0) {
      iVar4 = getCopReg(2,0x3800);
      if (iVar3 >= 0) goto code_r0x8001898c;
    }
    else {
      iVar4 = getCopReg(2,0x3800);
code_r0x8001898c:
      uVar7 = (uint)(iVar3 < 0) & (int)uVar7 >> 0x11;
      iVar4 = iVar4 - DAT_1f800050;
      if (4 < iVar4) {
        if (DAT_1f800004 == 0) {
          DAT_1f80004c = 0;
        }
        else {
          DAT_1f800048 = uVar11;
          DAT_1f80004c = iVar4;
          if (DAT_1f800004 <= iVar4) goto LAB_80018a08;
        }
        DAT_1f800010 = getCopReg(2,0xc);
        DAT_1f800014 = getCopReg(2,0xd);
        DAT_1f800018 = getCopReg(2,0xe);
        if ((uVar11 & 0x10000000) == 0) {
          setCopReg(2,0x3000,iVar12);
          copFunction(2,0x780010);
          puVar10 = param_2;
          DAT_1f800048 = uVar11;
        }
        else {
          setCopReg(2,0xa000,iVar12);
          setCopReg(2,0xa800,in_t5);
          setCopReg(2,0xb000,in_t6);
          copFunction(2,0xf8002a);
          puVar10 = param_2;
          DAT_1f800048 = uVar11;
        }
      }
    }
LAB_80018a08:
    uVar11 = DAT_1f800048;
    iVar3 = DAT_1f80000c + -1;
    if (iVar3 == 0) {
      if (puVar10 != (uint *)0x0) {
        puVar14 = (uint *)(DAT_1f800000 + DAT_1f80004c * 4);
        uVar7 = DAT_1f800048 & 0xff000000;
        *puVar10 = DAT_1f800048 << 0x18 | *puVar14;
        *puVar14 = (uint)puVar10 & 0xffffff;
        piVar8 = DAT_1f800044;
        uVar2 = DAT_1f800018;
        uVar1 = DAT_1f800014;
        uVar16 = DAT_1f800010;
        param_2 = param_2 + (uVar11 & 0xff) + 1;
        DAT_1f800030 = getCopReg(2,0x14);
        uVar5 = getCopReg(2,0x15);
        uVar17 = getCopReg(2,0x16);
        if ((uVar11 & 0x4000000) == 0) {
          if ((uVar11 & 0x10000000) == 0) {
            DAT_1f800034 = uVar5;
            DAT_1f800038 = uVar17;
            puVar10[1] = uVar17 | uVar7;
            puVar10[2] = uVar16;
            puVar10[3] = uVar1;
            puVar10[4] = uVar2;
          }
          else {
            DAT_1f800034 = uVar5;
            DAT_1f800038 = uVar17;
            puVar10[1] = DAT_1f800030 | uVar7;
            puVar10[3] = uVar5;
            puVar10[5] = uVar17;
            uVar5 = DAT_1f800018;
            uVar11 = DAT_1f800014;
            puVar10[2] = DAT_1f800010;
            puVar10[4] = uVar11;
            puVar10[6] = uVar5;
          }
        }
        else {
          if ((uVar11 & 0x10000000) == 0) {
            DAT_1f800034 = uVar5;
            DAT_1f800038 = uVar17;
            puVar10[1] = uVar17 | uVar7;
            puVar10[2] = uVar16;
            piVar8 = DAT_1f800044;
            uVar11 = DAT_1f800018;
            puVar10[4] = DAT_1f800014;
            puVar10[6] = uVar11;
            uVar11 = piVar8[2];
            uVar5 = piVar8[3];
            puVar10[3] = piVar8[1];
            puVar10[5] = uVar11;
            puVar10[7] = uVar5;
          }
          else {
            uVar11 = DAT_1f800044[1];
            DAT_1f800034 = uVar5;
            DAT_1f800038 = uVar17;
            puVar10[1] = DAT_1f800030 | uVar7;
            puVar10[2] = uVar16;
            puVar10[3] = uVar11;
            puVar10[4] = uVar5;
            uVar11 = DAT_1f800038;
            uVar7 = DAT_1f800018;
            uVar17 = piVar8[2];
            uVar5 = piVar8[3];
            puVar10[5] = DAT_1f800014;
            puVar10[6] = uVar17;
            puVar10[7] = uVar11;
            puVar10[8] = uVar7;
            puVar10[9] = uVar5;
          }
        }
      }
      return CONCAT44(param_2,uVar7);
    }
  } while( true );
}



// autogenerated function stub: 
// void GtxTmd_Display3LOFF() /* GtxTmd_Display3LOFF method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
void GtxTmd_Display3LOFF() 
{ // line 1132, offset 0x80018ba0
	return null;
}


// decompiled code
// original method signature: 
// void GtxTmx_Display4LOFF() /* GtxTmx_Display4LOFF method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 1266, offset 0x80018e00
uint * GtxTmx_Display4LOFF(int param_1,uint *param_2,int param_3,int param_4,int param_5)

{
  _TMD_2D *p_Var1;
  int iVar2;
  uint *puVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  _TMD_2D *p_Var8;
  uint in_t5;
  uint uVar9;
  uint in_t6;
  uint uVar10;
  uint uVar11;
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  int iVar12;
  undefined4 unaff_s2;
  uint uVar13;
  undefined4 unaff_s3;
  uint uVar14;
  
  p_Var1 = Tmd_2D;
  iVar12 = *(int *)(param_1 + 0x14);
  piVar4 = *(int **)(param_1 + 0x10);
  DAT_1f800054 = unaff_s0;
  DAT_1f800058 = unaff_s1;
  DAT_1f80005c = unaff_s2;
  DAT_1f800060 = unaff_s3;
  do {
    iVar12 = iVar12 + -1;
    p_Var8 = p_Var1 + (piVar4[10] >> 0x10);
    setCopReg(2,p_Var8,*(undefined4 *)(p_Var1 + (piVar4[9] & 0xffff)));
    setCopReg(2,in_t5,*(undefined4 *)(p_Var1 + (piVar4[9] >> 0x10)));
    setCopReg(2,in_t6,*(undefined4 *)(p_Var1 + (piVar4[10] & 0xffff)));
    uVar5 = *(uint *)&p_Var1[piVar4[9] & 0xffff].vz;
    uVar6 = *(uint *)&p_Var1[piVar4[9] >> 0x10].vz;
    uVar7 = *(uint *)&p_Var1[piVar4[10] & 0xffff].vz;
    copFunction(2,0x1400006);
    uVar9 = uVar5 & 0xffff;
    uVar10 = uVar6 & 0xffff;
    uVar11 = uVar7 & 0xffff;
    if (uVar9 < uVar10) {
      uVar9 = uVar10;
    }
    uVar10 = *(uint *)&p_Var8->vz & 0xffff;
    if (uVar9 < uVar11) {
      uVar9 = uVar11;
    }
    if (uVar9 < uVar10) {
      uVar9 = uVar10;
    }
    in_t5 = (int)uVar9 >> 2;
    in_t6 = (uint)((int)in_t5 < param_4);
    if (in_t5 != 0) {
      iVar2 = getCopReg(2,0xc000);
      if (((int)in_t5 < param_4) && (0 < iVar2)) {
        if (param_5 <= (int)param_2) {
          return param_2;
        }
        setCopReg(2,0x4000,(int)uVar5 >> 0x10);
        setCopReg(2,0x3000,piVar4[5]);
        copFunction(2,0x780010);
        uVar9 = getCopReg(2,0xb000);
        setCopReg(2,0x4000,(int)uVar6 >> 0x10);
        setCopReg(2,0x3000,piVar4[6]);
        copFunction(2,0x780010);
        in_t6 = getCopReg(2,0xb000);
        setCopReg(2,0x4000,(int)uVar7 >> 0x10);
        setCopReg(2,0x3000,piVar4[7]);
        copFunction(2,0x780010);
        uVar11 = getCopReg(2,0xb000);
        setCopReg(2,0x4000,(int)*(uint *)&p_Var8->vz >> 0x10);
        setCopReg(2,0x3000,piVar4[8]);
        iVar2 = *piVar4;
        copFunction(2,0x780010);
        uVar13 = *(uint *)p_Var8;
        uVar14 = getCopReg(2,0xb000);
        puVar3 = (uint *)(param_3 + in_t5 * 4);
        in_t5 = *puVar3 | 0xc000000;
        uVar5 = piVar4[1];
        uVar6 = piVar4[2];
        uVar7 = piVar4[3];
        uVar10 = piVar4[4];
        *puVar3 = (uint)param_2 & 0xffffff;
        *param_2 = in_t5;
        param_2[1] = uVar9 | iVar2 - 0x1000000U & 0xff000000;
        uVar9 = getCopReg(2,0xc);
        param_2[2] = uVar9;
        param_2[3] = uVar5;
        param_2[4] = in_t6;
        uVar9 = getCopReg(2,0xd);
        param_2[5] = uVar9;
        param_2[6] = uVar6;
        param_2[7] = uVar11;
        uVar9 = getCopReg(2,0xe);
        param_2[8] = uVar9;
        param_2[9] = uVar7;
        param_2[10] = uVar14;
        param_2[0xb] = uVar13;
        param_2[0xc] = uVar10;
        param_2 = param_2 + 0xd;
      }
    }
    piVar4 = piVar4 + 0xb;
  } while (iVar12 != 0);
  return param_2;
}



// decompiled code
// original method signature: 
// void GtxTmd_ApplyMIMe() /* GtxTmd_ApplyMIMe method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 1516, offset 0x80019014
int GtxTmd_ApplyMIMe(uint **param_1,int param_2)

{
  short sVar1;
  uint **ppuVar2;
  uint **ppuVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint *puVar7;
  uint **ppuVar8;
  uint **ppuVar9;
  uint **ppuVar10;
  
  ppuVar2 = param_1 + 7;
  ppuVar8 = ppuVar2 + (int)param_1[1] * 2;
  ppuVar9 = ppuVar8 + (int)param_1[1] * 2;
  ppuVar10 = ppuVar9;
  if (param_2 != 0) {
    setCopReg(2,0x4000,param_2);
    ppuVar3 = ppuVar8;
    do {
      setCopReg(2,0x4800,(uint)*ppuVar2 & 0xffff);
      setCopReg(2,0x5000,(int)*ppuVar2 >> 0x10);
      setCopReg(2,0x5800,(int)*(short *)(ppuVar2 + 1));
      ppuVar2 = ppuVar2 + 2;
      puVar7 = *ppuVar9;
      copFunction(2,0x198003d);
      sVar1 = *(short *)(ppuVar9 + 1);
      uVar4 = getCopReg(2,0x4800);
      uVar5 = getCopReg(2,0x5000);
      uVar6 = getCopReg(2,0x5800);
      *(short *)ppuVar3 = (short)puVar7 + (short)uVar4;
      *(short *)((int)ppuVar3 + 2) = (short)((uint)puVar7 >> 0x10) + (short)uVar5;
      *(short *)(ppuVar3 + 1) = sVar1 + (short)uVar6;
      ppuVar9 = ppuVar9 + 2;
      ppuVar3 = ppuVar3 + 2;
      ppuVar10 = ppuVar8;
    } while (ppuVar2 != ppuVar8);
  }
  *(uint ***)param_1 = ppuVar10;
  return param_2;
}



// decompiled code
// original method signature: 
// void GtxTmx_Display3LON() /* GtxTmx_Display3LON method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 1605, offset 0x800190a8
/* WARNING: Instruction at (ram,0x80019170) overlaps instruction at (ram,0x8001916c)
    */

uint * GtxTmx_Display3LON(int param_1,uint *param_2,int param_3,int param_4,int param_5,uint param_6
                         ,int param_7)

{
  bool bVar1;
  _TMD_2D *p_Var2;
  undefined4 in_zero;
  uint uVar3;
  uint *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  uint uVar11;
  int iVar12;
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  int iVar13;
  undefined4 unaff_s2;
  
  p_Var2 = Tmd_2D;
  iVar13 = *(int *)(param_1 + 0x14);
  DAT_1f800008 = param_6 & 0xffffff;
  puVar4 = *(uint **)(param_1 + 0x10);
  DAT_1f800054 = unaff_s0;
  DAT_1f800058 = unaff_s1;
  DAT_1f80005c = unaff_s2;
  do {
    iVar13 = iVar13 + -1;
    uVar8 = puVar4[5];
    uVar9 = puVar4[6];
    puVar5 = (undefined4 *)((int)&p_Var2->vx + ((int)puVar4[4] >> 0xc));
    uVar11 = puVar5[1];
    setCopReg(2,uVar8,*puVar5);
    setCopReg(2,uVar9,*(undefined4 *)((int)&p_Var2->vx + ((int)uVar8 >> 0xc)));
    setCopReg(2,uVar11,*(undefined4 *)((int)&p_Var2->vx + ((int)uVar9 >> 0xc)));
    copFunction(2,0x1400006);
    uVar6 = *puVar4;
    iVar12 = ((int)(uVar11 & 0xffff) >> 2) - param_5;
    if (0 < iVar12) {
      uVar3 = getCopReg(2,0xc000);
      bVar1 = 0 < (int)uVar3;
      if (iVar12 < param_4) {
        if ((uVar6 & 0x20000) == 0) {
          uVar3 = (uint)((int)param_2 < param_7);
          if (!bVar1) goto LAB_80019224;
          setCopReg(2,0x4000,(int)uVar11 >> 0x10);
          if ((int)param_2 >= param_7) {
            return param_2;
          }
        }
        else {
          setCopReg(2,0x4000,(int)uVar11 >> 0x10);
        }
        setCopReg(2,in_zero,*(undefined4 *)&p_Var2[puVar4[4] & 0xffff].nx);
        setCopReg(2,0xffffff,*(undefined4 *)&p_Var2[puVar4[4] & 0xffff].nz);
        setCopReg(2,uVar3,*(undefined4 *)&p_Var2[uVar8 & 0xffff].nx);
        setCopReg(2,(uint)bVar1,*(undefined4 *)&p_Var2[uVar8 & 0xffff].nz);
        setCopReg(2,puVar4 + 7,*(undefined4 *)&p_Var2[uVar9 & 0xffff].nx);
        setCopReg(2,param_2,*(undefined4 *)&p_Var2[uVar9 & 0xffff].nz);
        setCopReg(2,param_3,DAT_1f800008);
        copFunction(2,0xf80416);
        uVar9 = puVar4[1];
        uVar11 = puVar4[2];
        uVar3 = puVar4[3];
        puVar10 = (uint *)(param_3 + iVar12 * 4);
        uVar7 = *puVar10;
        uVar8 = getCopReg(2,0xa000);
        *puVar10 = (uint)param_2 & 0xffffff;
        *param_2 = uVar7 | 0x9000000;
        param_2[1] = uVar8 | uVar6 & 0xff000000;
        uVar6 = getCopReg(2,0xc);
        param_2[2] = uVar6;
        param_2[3] = uVar9;
        uVar6 = getCopReg(2,0x15);
        param_2[4] = uVar6;
        uVar6 = getCopReg(2,0xd);
        param_2[5] = uVar6;
        param_2[6] = uVar11;
        uVar6 = getCopReg(2,0x16);
        param_2[7] = uVar6;
        uVar6 = getCopReg(2,0xe);
        param_2[8] = uVar6;
        param_2[9] = uVar3;
        param_2 = param_2 + 10;
      }
    }
LAB_80019224:
    puVar4 = puVar4 + 7;
    if (iVar13 == 0) {
      return param_2;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// void GtxTmx_DisplayLON() /* GtxTmx_DisplayLON method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 1787, offset 0x80019240
/* WARNING: Instruction at (ram,0x800194dc) overlaps instruction at (ram,0x800194d8)
    */

undefined8
GtxTmx_DisplayLON(int param_1,uint *param_2,int param_3,int param_4,int param_5,uint param_6)

{
  uint uVar1;
  uint uVar2;
  _TMD_2D *p_Var3;
  undefined4 in_zero;
  undefined4 in_at;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  uint *puVar10;
  uint *puVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  _TMD_2D *p_Var16;
  uint uVar17;
  _TMD_2D *in_t6;
  _TMD_2D *in_t7;
  undefined4 unaff_s2;
  undefined4 unaff_s3;
  
  p_Var3 = Tmd_2D;
  DAT_1f800050 = param_5;
  DAT_1f800008 = param_6 & 0xffffff;
  iVar4 = *(int *)(param_1 + 0x14);
  puVar9 = *(uint **)(param_1 + 0x10);
  puVar11 = (uint *)0x0;
  DAT_1f800000 = param_3;
  DAT_1f800004 = param_4;
  do {
    uVar8 = DAT_1f800048;
    uVar12 = *puVar9;
    if ((uVar12 & 0x4000000) == 0) {
      uVar6 = puVar9[1];
      puVar10 = puVar9;
    }
    else {
      puVar10 = puVar9 + 2;
      uVar6 = DAT_1f800008;
      DAT_1f800040 = puVar9;
    }
    if ((uVar12 & 0x10000000) == 0) {
      uVar13 = puVar10[3];
      puVar9 = puVar10 + 4;
      uVar14 = uVar13 & 0xffff;
    }
    else {
      uVar13 = puVar10[4];
      uVar14 = (int)puVar10[3] >> 0x10;
      in_t6 = (_TMD_2D *)(puVar10[3] & 0xffff);
      in_t7 = (_TMD_2D *)(uVar13 & 0xffff);
      puVar9 = puVar10 + 5;
    }
    uVar17 = puVar10[2] & 0xffff;
    p_Var16 = p_Var3 + ((int)uVar13 >> 0x10);
    DAT_1f800030 = getCopReg(2,0x14);
    DAT_1f800034 = getCopReg(2,0x15);
    DAT_1f800038 = getCopReg(2,0x16);
    iVar5 = *(int *)&p_Var3[(int)puVar10[2] >> 0x10].vz;
    setCopReg(2,p_Var16,*(undefined4 *)(p_Var3 + ((int)puVar10[2] >> 0x10)));
    setCopReg(2,uVar17,*(undefined4 *)(p_Var3 + uVar14));
    setCopReg(2,in_t6,*(undefined4 *)p_Var16);
    setCopReg(2,0x4000,iVar5 >> 0x10);
    setCopReg(2,0x8800,iVar5);
    setCopReg(2,unaff_s2,*(undefined4 *)&p_Var3[uVar14].vz);
    setCopReg(2,unaff_s3,*(undefined4 *)&p_Var16->vz);
    DAT_1f80000c = iVar4;
    if (puVar11 != (uint *)0x0) {
      puVar10 = (uint *)(DAT_1f800000 + DAT_1f80004c * 4);
      uVar7 = DAT_1f800048 & 0xff000000;
      DAT_1f80000c = iVar4;
      *puVar11 = DAT_1f800048 << 0x18 | *puVar10;
      *puVar10 = (uint)puVar11 & 0xffffff;
      uVar2 = DAT_1f800038;
      uVar1 = DAT_1f800034;
      uVar15 = DAT_1f800018;
      uVar14 = DAT_1f800014;
      uVar13 = DAT_1f800010;
      param_2 = param_2 + (uVar8 & 0xff) + 1;
      if ((uVar8 & 0x4000000) == 0) {
        if ((uVar8 & 0x10000000) == 0) {
          puVar11[1] = DAT_1f800038 | uVar7;
          puVar11[2] = uVar13;
          puVar11[3] = uVar14;
          puVar11[4] = uVar15;
        }
        else {
          puVar11[1] = DAT_1f800030 | uVar7;
          puVar11[3] = uVar1;
          puVar11[5] = uVar2;
          uVar13 = DAT_1f800018;
          uVar8 = DAT_1f800014;
          puVar11[2] = DAT_1f800010;
          puVar11[4] = uVar8;
          puVar11[6] = uVar13;
        }
      }
      else {
        if ((uVar8 & 0x10000000) == 0) {
          puVar11[1] = DAT_1f800038 | uVar7;
          puVar11[2] = uVar13;
          uVar8 = DAT_1f800018;
          puVar11[4] = DAT_1f800014;
          puVar11[6] = uVar8;
          uVar8 = DAT_1f800044[2];
          uVar13 = DAT_1f800044[3];
          puVar11[3] = DAT_1f800044[1];
          puVar11[5] = uVar8;
          puVar11[7] = uVar13;
        }
        else {
          uVar8 = DAT_1f800044[1];
          puVar11[1] = DAT_1f800030 | uVar7;
          puVar11[2] = uVar13;
          puVar11[3] = uVar8;
          puVar11[4] = uVar1;
          uVar13 = DAT_1f800038;
          uVar8 = DAT_1f800018;
          uVar15 = DAT_1f800044[2];
          uVar14 = DAT_1f800044[3];
          puVar11[5] = DAT_1f800014;
          puVar11[6] = uVar15;
          puVar11[7] = uVar13;
          puVar11[8] = uVar8;
          puVar11[9] = uVar14;
        }
      }
    }
    DAT_1f800044 = DAT_1f800040;
    copFunction(2,0x1400006);
    puVar11 = (uint *)0x0;
    iVar4 = getCopReg(2,0xc000);
    uVar8 = uVar12 & 0x20000;
    copFunction(2,0x158002d);
    if (uVar8 == 0) {
      iVar5 = getCopReg(2,0x3800);
      if (iVar4 >= 0) goto code_r0x800194e0;
    }
    else {
      iVar5 = getCopReg(2,0x3800);
code_r0x800194e0:
      uVar8 = (uint)(iVar4 < 0) & (int)uVar8 >> 0x11;
      iVar5 = iVar5 - DAT_1f800050;
      if (4 < iVar5) {
        if (DAT_1f800004 == 0) {
          DAT_1f80004c = 0;
        }
        else {
          DAT_1f800048 = uVar12;
          DAT_1f80004c = iVar5;
          if (DAT_1f800004 <= iVar5) goto LAB_8001960c;
        }
        DAT_1f800010 = getCopReg(2,0xc);
        DAT_1f800014 = getCopReg(2,0xd);
        DAT_1f800018 = getCopReg(2,0xe);
        if (uVar8 == 0) {
          setCopReg(2,in_zero,*(undefined4 *)&p_Var3[uVar17].nx);
          setCopReg(2,in_at,*(undefined4 *)&p_Var3[uVar17].nz);
          uVar8 = uVar12 & 0x10000000;
          setCopReg(2,0x3000,uVar6);
          if (uVar8 == 0) goto code_r0x80019608;
          p_Var16 = p_Var3 + (int)in_t6;
          setCopReg(2,p_Var16,*(undefined4 *)&p_Var16->nx);
          setCopReg(2,uVar8,*(undefined4 *)&p_Var16->nz);
          setCopReg(2,puVar9,*(undefined4 *)&p_Var3[(int)in_t7].nx);
          setCopReg(2,param_2,*(undefined4 *)&p_Var3[(int)in_t7].nz);
          copFunction(2,0xf80416);
          puVar11 = param_2;
          in_t6 = (_TMD_2D *)((int)in_t6 * 0x10);
          in_t7 = (_TMD_2D *)((int)in_t7 * 0x10);
          DAT_1f800048 = uVar12;
        }
        else {
          setCopReg(2,0,-(*(int *)(uVar17 * 0x10 + 8) + -0x10000));
          setCopReg(2,0x800,-*(int *)(uVar17 * 0x10 + 0xc));
          setCopReg(2,0x3000,uVar6);
          if ((uVar12 & 0x10000000) == 0) {
code_r0x80019608:
            uVar8 = uVar12 & 0x10000000;
            copFunction(2,0xe80413);
            puVar11 = param_2;
            DAT_1f800048 = uVar12;
          }
          else {
            in_t6 = p_Var3 + (int)in_t6;
            in_t7 = p_Var3 + (int)in_t7;
            setCopReg(2,0x1000,-(*(int *)&in_t6->nx + -0x10000));
            setCopReg(2,0x1800,-*(int *)&in_t6->nz);
            uVar8 = -*(int *)&in_t7->nz;
            setCopReg(2,0x2000,-(*(int *)&in_t7->nx + -0x10000));
            setCopReg(2,0x2800,uVar8);
            copFunction(2,0xf80416);
            puVar11 = param_2;
            DAT_1f800048 = uVar12;
          }
        }
      }
    }
LAB_8001960c:
    uVar12 = DAT_1f800048;
    iVar4 = DAT_1f80000c + -1;
    if (iVar4 == 0) {
      if (puVar11 != (uint *)0x0) {
        puVar9 = (uint *)(DAT_1f800000 + DAT_1f80004c * 4);
        uVar8 = DAT_1f800048 & 0xff000000;
        *puVar11 = DAT_1f800048 << 0x18 | *puVar9;
        *puVar9 = (uint)puVar11 & 0xffffff;
        puVar9 = DAT_1f800044;
        uVar15 = DAT_1f800018;
        uVar17 = DAT_1f800014;
        uVar14 = DAT_1f800010;
        param_2 = param_2 + (uVar12 & 0xff) + 1;
        DAT_1f800030 = getCopReg(2,0x14);
        uVar6 = getCopReg(2,0x15);
        uVar13 = getCopReg(2,0x16);
        if ((uVar12 & 0x4000000) == 0) {
          if ((uVar12 & 0x10000000) == 0) {
            DAT_1f800034 = uVar6;
            DAT_1f800038 = uVar13;
            puVar11[1] = uVar13 | uVar8;
            puVar11[2] = uVar14;
            puVar11[3] = uVar17;
            puVar11[4] = uVar15;
          }
          else {
            DAT_1f800034 = uVar6;
            DAT_1f800038 = uVar13;
            puVar11[1] = DAT_1f800030 | uVar8;
            puVar11[3] = uVar6;
            puVar11[5] = uVar13;
            uVar6 = DAT_1f800018;
            uVar12 = DAT_1f800014;
            puVar11[2] = DAT_1f800010;
            puVar11[4] = uVar12;
            puVar11[6] = uVar6;
          }
        }
        else {
          if ((uVar12 & 0x10000000) == 0) {
            DAT_1f800034 = uVar6;
            DAT_1f800038 = uVar13;
            puVar11[1] = uVar13 | uVar8;
            puVar11[2] = uVar14;
            puVar9 = DAT_1f800044;
            uVar12 = DAT_1f800018;
            puVar11[4] = DAT_1f800014;
            puVar11[6] = uVar12;
            uVar12 = puVar9[2];
            uVar6 = puVar9[3];
            puVar11[3] = puVar9[1];
            puVar11[5] = uVar12;
            puVar11[7] = uVar6;
          }
          else {
            uVar12 = DAT_1f800044[1];
            DAT_1f800034 = uVar6;
            DAT_1f800038 = uVar13;
            puVar11[1] = DAT_1f800030 | uVar8;
            puVar11[2] = uVar14;
            puVar11[3] = uVar12;
            puVar11[4] = uVar6;
            uVar12 = DAT_1f800038;
            uVar8 = DAT_1f800018;
            uVar13 = puVar9[2];
            uVar6 = puVar9[3];
            puVar11[5] = DAT_1f800014;
            puVar11[6] = uVar13;
            puVar11[7] = uVar12;
            puVar11[8] = uVar8;
            puVar11[9] = uVar6;
          }
        }
      }
      return CONCAT44(param_2,uVar8);
    }
  } while( true );
}



// decompiled code
// original method signature: 
// void GtxShp_DisplayListLOFF() /* GtxShp_DisplayListLOFF method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 2146, offset 0x800197ac
uint * GtxShp_DisplayListLOFF
                 (int *param_1,uint *param_2,int param_3,int param_4,int param_5,int param_6)

{
  short sVar1;
  undefined4 in_zero;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint *puVar13;
  int iVar14;
  uint uVar15;
  undefined4 unaff_s0;
  uint *puVar16;
  int iVar17;
  
  iVar17 = *param_1;
  DAT_1f800008._0_2_ = *(short *)(param_1 + 3);
  puVar16 = (uint *)param_1[2];
  puVar9 = (undefined4 *)param_1[1];
  DAT_1f800004 = param_5;
  DAT_1f800000 = param_4;
  DAT_1f800010 = unaff_s0;
  do {
    setCopReg(2,in_zero,*puVar9);
    setCopReg(2,0x800,puVar9[1]);
    uVar2 = (int)puVar9[1] >> 0x10;
    copFunction(2,0x180001);
    iVar11 = *(int *)(iVar17 + ((int)uVar2 >> 8 & 0xffU) * 4 + 0x10);
    iVar7 = (int)Scr_GeomScreen;
    iVar8 = (int)*(uint *)(iVar11 + 4) >> 0x10;
    uVar3 = *(uint *)(iVar11 + 4) & 0xffff;
    uVar12 = ((*(uint *)(iVar11 + 8) & 0xffff) - 1) + uVar3;
    iVar14 = ((int)*(uint *)(iVar11 + 8) >> 0x10) + -1 + iVar8;
    iVar4 = getCopReg(2,0x9800);
    iVar5 = iVar4 + DAT_1f800004 >> 2;
    if (0x3f < iVar4 + DAT_1f800004) {
      iVar4 = getCopReg(2,0x7000);
      if (DAT_1f800000 == 0) {
        iVar6 = 0;
      }
      else {
        iVar6 = iVar5;
        if (DAT_1f800000 <= iVar5) goto LAB_800199c4;
      }
      if (param_6 <= (int)param_2) {
        return param_2;
      }
      puVar13 = (uint *)(param_3 + iVar6 * 4);
      *param_2 = *puVar13 | 0x9000000;
      *puVar13 = (uint)param_2 & 0xffffff;
      sVar1 = *(short *)(iVar11 + 2);
      if (puVar16 == (uint *)0x0) {
        uVar10 = 0x2c808080;
      }
      else {
        uVar10 = *puVar16 & 0xffffff | 0x2c000000;
        puVar16 = puVar16 + 1;
      }
      uVar10 = uVar10 | (uint)*(byte *)(iVar11 + 0x11) << 0x19;
      setCopReg(2,0xa000,uVar10);
      copFunction(2,0xf8002a);
      param_2[3] = iVar8 << 8 | uVar3 | (int)(short)Pals[(int)*(short *)(iVar11 + 0xe)].clut << 0x10
      ;
      param_2[5] = iVar8 << 8 | uVar12 | (int)sVar1 << 0x10;
      param_2[7] = iVar14 * 0x100 | uVar3;
      param_2[9] = iVar14 * 0x100 | uVar12;
      iVar5 = (int)((uVar2 & 0xff) * iVar7) / iVar5 >> 1;
      uVar12 = (int)(short)iVar4 - iVar5 & 0xffff;
      uVar2 = (int)(short)iVar4 + 1 + iVar5 & 0xffff;
      uVar15 = ((iVar4 >> 0x10) - iVar5) * 0x10000;
      uVar3 = ((iVar4 >> 0x10) + 1 + iVar5) * 0x10000;
      param_2[2] = uVar12 | uVar15;
      param_2[4] = uVar2 | uVar15;
      param_2[6] = uVar12 | uVar3;
      param_2[8] = uVar2 | uVar3;
      uVar2 = getCopReg(2,0xa000);
      param_2[1] = ((int)uVar10 >> 0x18) << 0x18 | uVar2;
      param_2 = param_2 + 10;
    }
LAB_800199c4:
    iVar4 = (int)(short)DAT_1f800008;
    puVar9 = puVar9 + 2;
    DAT_1f800008._0_2_ = (short)(iVar4 + -1);
    if (iVar4 + -1 == 0) {
      return param_2;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// void __SN_ENTRY_POINT() /* __SN_ENTRY_POINT method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 2359, offset 0x800199e4
/* WARNING: This function may have set the stack pointer */

void entry(long param_1,long *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = &DAT_800afe40;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  } while (puVar1 < &Heap_Start);
  __heapsize = _ramsize + (-0xbb920 - (int)_stacksize);
  __heapbase = &Heap_Start;
  main(param_1,param_2);
  return;
}





