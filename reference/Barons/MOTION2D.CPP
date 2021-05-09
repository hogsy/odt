#include "THISDUST.H"
#include "MOTION2D.H"


// decompiled code
// original method signature: 
// void * /*$ra*/ Motion2D_EnvMotionCapture(struct M_OBJECT *mo /*$t5*/, void *prims /*$s2*/, long type /*stack 8*/)
 // line 43, offset 0x8002481c
	/* begin block 1 */
		// Start line: 44
		// Start offset: 0x8002481C
		// Variables:
	// 		struct MOTION2D_93fake *tmd; // $fp
	// 		struct MOTION2D_92fake *p; // $s3
	// 		struct _TMD_2D *v0; // $s5
	// 		struct _TMD_2D *v1; // $s7
	// 		struct _TMD_2D *v2; // $s6
	// 		struct _TMD_2D *n0; // $t2
	// 		struct MOTION2D_8fake color; // stack offset -88
	// 		long z; // $s0
	// 		long i; // $a3
	// 		long clip; // stack offset -56
	// 		long dq; // $a0
	// 		long minx; // $s1
	// 		long maxx; // $s0
	// 		long cx; // $t0

		/* begin block 1.1 */
			// Start line: 76
			// Start offset: 0x80024988
			// Variables:
		// 		long miny; // $s4
		// 		long offset; // stack offset -52

			/* begin block 1.1.1 */
				// Start line: 97
				// Start offset: 0x80024A74
				// Variables:
			// 		long rate; // $v0
			/* end block 1.1.1 */
			// End offset: 0x80024A94
			// End Line: 97
		/* end block 1.1 */
		// End offset: 0x80024ADC
		// End Line: 103

		/* begin block 1.2 */
			// Start line: 154
			// Start offset: 0x80024CA8
			// Variables:
		// 		struct MOTION2D_8fake color; // stack offset -80
		/* end block 1.2 */
		// End offset: 0x80024CA8
		// End Line: 158

		/* begin block 1.3 */
			// Start line: 174
			// Start offset: 0x80024D30
		/* end block 1.3 */
		// End offset: 0x80024D30
		// End Line: 178

		/* begin block 1.4 */
			// Start line: 190
			// Start offset: 0x80024DB0
			// Variables:
		// 		struct MOTION2D_32fake *pg3; // $a1
		// 		struct MOTION2D_6fake color; // stack offset -72
		/* end block 1.4 */
		// End offset: 0x80024F90
		// End Line: 219
	/* end block 1 */
	// End offset: 0x80025060
	// End Line: 289

	/* begin block 2 */
		// Start line: 86
	/* end block 2 */
	// End Line: 87

void * Motion2D_EnvMotionCapture(M_OBJECT *mo,void *prims,long type)

{
  short sVar1;
  short sVar2;
  short sVar3;
  _PVL_HEADER *p_Var4;
  _SCREEN *p_Var5;
  undefined4 in_zero;
  undefined4 in_at;
  byte bVar6;
  _TMD_2D *p_Var7;
  int iVar8;
  ulong *puVar9;
  uint uVar10;
  uint uVar11;
  int in_t0;
  _TMD_2D *in_t2;
  int iVar12;
  int iVar13;
  int iVar14;
  uint *puVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  _TMD_2D *unaff_s5;
  uint *unaff_s6;
  _TMD_2D *unaff_s7;
  int iVar19;
  int local_48;
  int local_40;
  
  iVar19 = *(int *)(*(int *)(mo->Sq).Data.FatherTrans + 8);
  iVar16 = *(int *)(iVar19 + 0x10);
  if (type == 1) {
    SetFarColor(0,0,0);
    iVar13 = 0x7fff;
    iVar12 = -0x7fff;
    uVar10 = 0;
    sVar1 = (mo->Env).Obj.vert_top.vz;
    p_Var7 = Tmd_2D;
    iVar17 = iVar12;
    iVar8 = iVar13;
    if (*(uint *)(iVar19 + 4) != 0) {
      do {
        iVar12 = (int)p_Var7->vx;
        iVar13 = iVar12;
        if (iVar8 < iVar12) {
          iVar13 = iVar8;
        }
        if (iVar12 < iVar17) {
          iVar12 = iVar17;
        }
        uVar10 = uVar10 + 1;
        p_Var7 = p_Var7 + 1;
        iVar17 = iVar12;
        iVar8 = iVar13;
      } while (uVar10 < *(uint *)(iVar19 + 4));
    }
    in_t0 = (int)(iVar13 + iVar12 + ((uint)(iVar13 + iVar12) >> 0x1f)) >> 1;
    uVar10 = 0;
    p_Var7 = Tmd_2D;
    if (*(int *)(iVar19 + 4) != 0) {
      do {
        uVar10 = uVar10 + 1;
        p_Var7->vx = (short)in_t0 +
                     (short)((uint)(((int)p_Var7->vx - in_t0) * ((int)sVar1 * 0x20 + 0x100)) >> 8);
        p_Var7 = p_Var7 + 1;
      } while (uVar10 < *(uint *)(iVar19 + 4));
    }
  }
  iVar12 = -0x7fff;
  if (type == 3) {
    iVar17 = 0x7fff;
    iVar13 = 0x7fff;
    uVar10 = (uint)(ushort)(mo->Env).Obj.vert_top.vz << 0x10;
    SetFarColor(0,0,0);
    uVar11 = 0;
    p_Var7 = Tmd_2D;
    iVar8 = iVar12;
    iVar14 = iVar13;
    iVar18 = iVar17;
    if (*(uint *)(iVar19 + 4) != 0) {
      do {
        iVar17 = (int)p_Var7->vy;
        if (iVar18 < (int)p_Var7->vy) {
          iVar17 = iVar18;
        }
        iVar12 = (int)p_Var7->vx;
        iVar13 = iVar12;
        if (iVar14 < iVar12) {
          iVar13 = iVar14;
        }
        if (iVar12 < iVar8) {
          iVar12 = iVar8;
        }
        uVar11 = uVar11 + 1;
        p_Var7 = p_Var7 + 1;
        iVar8 = iVar12;
        iVar14 = iVar13;
        iVar18 = iVar17;
      } while (uVar11 < *(uint *)(iVar19 + 4));
    }
    in_t0 = (int)(iVar13 + iVar12 + ((uint)(iVar13 + iVar12) >> 0x1f)) >> 1;
    uVar11 = 0;
    p_Var7 = Tmd_2D;
    if (*(int *)(iVar19 + 4) != 0) {
      do {
        iVar13 = ((int)p_Var7->vy - iVar17) + ((int)(((int)uVar10 >> 0x10) + (uVar10 >> 0x1f)) >> 1)
        ;
        iVar12 = iVar13;
        if (iVar13 < 0) {
          iVar12 = iVar13 + 7;
        }
        uVar11 = uVar11 + 1;
        p_Var7->vx = (short)in_t0 +
                     (short)((uint)(((int)p_Var7->vx - in_t0) *
                                   ((iVar13 + (iVar12 >> 3) * -8) * 0x20 + 0x50)) >> 8);
        p_Var7 = p_Var7 + 1;
      } while (uVar11 < *(uint *)(iVar19 + 4));
    }
  }
  iVar12 = (int)Tmd_2D->vz;
  if (iVar12 < 0) {
    iVar12 = iVar12 + 3;
  }
  iVar12 = iVar12 >> 2;
  if ((0 < iVar12) && (iVar12 < (int)Scr_OtSize)) {
    uVar10 = 0;
    if (*(int *)(iVar19 + 0x14) != 0) {
      iVar13 = iVar12 * 4;
      puVar15 = (uint *)prims;
      do {
        bVar6 = *(byte *)(iVar16 + 3) & 0xfd;
        if (bVar6 == 0x30) {
          unaff_s5 = Tmd_2D + (int)*(short *)(iVar16 + 10);
          unaff_s7 = Tmd_2D + (int)*(short *)(iVar16 + 0xe);
          iVar17 = (int)*(short *)(iVar16 + 8);
          iVar8 = (int)*(short *)(iVar16 + 0x12) << 4;
LAB_80024c38:
          unaff_s6 = (uint *)((int)&Tmd_2D->vx + iVar8);
          in_t2 = Tmd_2D + iVar17;
        }
        else {
          if (bVar6 < 0x31) {
            if (bVar6 == 0x20) {
              unaff_s5 = Tmd_2D + (int)*(short *)(iVar16 + 10);
              unaff_s7 = Tmd_2D + (int)*(short *)(iVar16 + 0xc);
              iVar17 = (int)*(short *)(iVar16 + 8);
              iVar8 = (int)*(short *)(iVar16 + 0xe) << 4;
              goto LAB_80024c38;
            }
            if (bVar6 == 0x24) {
              sVar1 = *(short *)(iVar16 + 0x12);
              sVar2 = *(short *)(iVar16 + 0x14);
              sVar3 = *(short *)(iVar16 + 0x16);
              goto LAB_80024c24;
            }
          }
          else {
            if (bVar6 == 0x34) {
              sVar1 = *(short *)(iVar16 + 0x12);
              sVar2 = *(short *)(iVar16 + 0x16);
              sVar3 = *(short *)(iVar16 + 0x1a);
LAB_80024c24:
              unaff_s5 = Tmd_2D + (int)sVar1;
              unaff_s7 = Tmd_2D + (int)sVar2;
              iVar8 = (int)sVar3 << 4;
              iVar17 = (int)*(short *)(iVar16 + 0x10);
              goto LAB_80024c38;
            }
          }
        }
        setCopReg(2,0x6000,*(undefined4 *)unaff_s5);
        setCopReg(2,0x7000,*unaff_s6);
        setCopReg(2,0x6800,*(undefined4 *)unaff_s7);
        copFunction(2,0x1400006);
        iVar17 = getCopReg(2,0x18);
        prims = puVar15;
        if (0 < iVar17) {
          prims = puVar15;
          if (Main_TextContext.Font.ascii_tab._20_4_ <= puVar15 + 2) break;
          if (type == 0) {
            puVar15[2] = *(uint *)unaff_s5;
            puVar15[3] = *(uint *)unaff_s7;
            puVar15[4] = *unaff_s6;
            setCopReg(2,in_zero,*(undefined4 *)&in_t2->nx);
            setCopReg(2,in_at,*(undefined4 *)&in_t2->nz);
            setCopReg(2,0xffffff,0xc04040);
            setCopReg(2,0x4000,(uint)(ushort)unaff_s5->dq);
            copFunction(2,0xe80413);
            uVar11 = getCopReg(2,0x16);
            puVar15[1] = uVar11;
            *(undefined *)((int)puVar15 + 3) = 4;
            *(undefined *)((int)puVar15 + 7) = 0x22;
          }
          else {
            if (type != 2) {
              if ((mo->sit->collision_mode & 0x1000U) == 0) {
                local_48 = (int)(mo->Env).Obj.vert_top.vz * -0x80 + 0xff0;
                local_40 = local_48;
                if (local_48 < 0) {
                  local_48 = 0;
                  local_40 = local_48;
                }
              }
              else {
                local_48 = (int)(mo->Env).Obj.vert_top.vz * -0x80 + 0xff0;
                if (local_48 < 0) {
                  local_48 = 0;
                }
                local_40 = 0;
              }
              puVar15[2] = *(uint *)unaff_s5;
              puVar15[4] = *(uint *)unaff_s7;
              puVar15[6] = *unaff_s6;
              iVar17 = (int)unaff_s5->vx - in_t0;
              if (iVar17 < 0) {
                iVar17 = -iVar17;
              }
              iVar17 = iVar17 << 7;
              if (0x1000 < iVar17) {
                iVar17 = 0x1000;
              }
              setCopReg(2,iVar13,local_48);
              setCopReg(2,in_t2,local_40);
              setCopReg(2,0xff000000,local_40);
              setCopReg(2,0x4000,iVar17);
              copFunction(2,0x980011);
              uVar11 = getCopReg(2,0x16);
              puVar15[1] = uVar11;
              iVar17 = (int)unaff_s7->vx - in_t0;
              if (iVar17 < 0) {
                iVar17 = -iVar17;
              }
              iVar17 = iVar17 << 7;
              if (0x1000 < iVar17) {
                iVar17 = 0x1000;
              }
              setCopReg(2,iVar13,local_48);
              setCopReg(2,in_t2,local_40);
              setCopReg(2,0xff000000,local_40);
              setCopReg(2,0x4000,iVar17);
              copFunction(2,0x980011);
              uVar11 = getCopReg(2,0x16);
              puVar15[3] = uVar11;
              iVar17 = (int)*(short *)unaff_s6 - in_t0;
              if (iVar17 < 0) {
                iVar17 = -iVar17;
              }
              iVar17 = iVar17 << 7;
              if (0x1000 < iVar17) {
                iVar17 = 0x1000;
              }
              setCopReg(2,iVar13,local_48);
              setCopReg(2,in_t2,local_40);
              setCopReg(2,0xff000000,local_40);
              setCopReg(2,0x4000,iVar17);
              copFunction(2,0x980011);
              uVar11 = getCopReg(2,0x16);
              puVar15[5] = uVar11;
              *(undefined *)((int)puVar15 + 3) = 6;
              *(undefined *)((int)puVar15 + 7) = 0x32;
              p_Var5 = Scr;
              *puVar15 = *puVar15 & 0xff000000 | Scr->ot[iVar12] & 0xffffff;
              prims = puVar15 + 7;
              p_Var5->ot[iVar12] = p_Var5->ot[iVar12] & 0xff000000 | (uint)puVar15 & 0xffffff;
              goto LAB_80024f90;
            }
            puVar15[2] = *(uint *)unaff_s5;
            puVar15[3] = *(uint *)unaff_s7;
            uVar11 = *unaff_s6;
            puVar15[1] = 0xffffff;
            *(undefined *)((int)puVar15 + 3) = 4;
            *(undefined *)((int)puVar15 + 7) = 0x20;
            puVar15[4] = uVar11;
          }
          p_Var5 = Scr;
          *puVar15 = *puVar15 & 0xff000000 | Scr->ot[iVar12] & 0xffffff;
          prims = puVar15 + 5;
          p_Var5->ot[iVar12] = p_Var5->ot[iVar12] & 0xff000000 | (uint)puVar15 & 0xffffff;
        }
LAB_80024f90:
        uVar10 = uVar10 + 1;
        iVar16 = iVar16 + (uint)*(byte *)(iVar16 + 1) * 4 + 4;
        puVar15 = (uint *)prims;
      } while (uVar10 < *(uint *)(iVar19 + 0x14));
    }
    *(undefined *)((int)prims + 3) = 1;
    p_Var5 = Scr;
    uVar10 = 0xe1000000;
    if (Scr_Dtd != 0) {
      uVar10 = 0xe1000200;
    }
    uVar11 = uVar10 | 0x420;
    if (Scr_Dfe == 0) {
      uVar11 = uVar10 | 0x20;
    }
    ((uint *)prims)[1] = uVar11;
    *(uint *)prims = *(uint *)prims & 0xff000000 | p_Var5->ot[iVar12] & 0xffffff;
    p_Var4 = Pvl_File;
    puVar9 = p_Var5->ot + iVar12;
    *puVar9 = *puVar9 & 0xff000000 | (uint)prims & 0xffffff;
    prims = (uint *)prims + 2;
    SetFarColor((uint)(p_Var4->fog).r,(uint)(p_Var4->fog).g,(uint)(p_Var4->fog).b);
  }
  return prims;
}



// decompiled code
// original method signature: 
// void * /*$ra*/ Motion2D_ShapesMotionCapture(struct M_OBJECT *mo /*$s7*/, struct MOTION2D_31fake *pft4 /*$s2*/, long start /*$fp*/, long end /*stack 12*/, long average /*stack 16*/, long coef /*stack 20*/, long mode /*stack 24*/)
 // line 292, offset 0x80025090
	/* begin block 1 */
		// Start line: 293
		// Start offset: 0x80025090
		// Variables:
	// 		struct MOTION2D_70fake shp; // stack offset -80
	// 		struct _TMD_2D *pvert; // $s3
	// 		short w; // stack offset -64
	// 		short h; // stack offset -62
	// 		long i; // $s4
	// 		long n; // stack offset -60
	// 		long w1; // $a2
	// 		long h1; // $a3
	// 		long z; // $s1
	// 		long tmp; // $v1
	/* end block 1 */
	// End offset: 0x800256A8
	// End Line: 403

	/* begin block 2 */
		// Start line: 749
	/* end block 2 */
	// End Line: 750

void * Motion2D_ShapesMotionCapture
                 (M_OBJECT *mo,undefined pft4,long start,long end,long average,long coef,long mode)

{
  ushort uVar1;
  bool bVar2;
  _SCREEN *p_Var3;
  int iVar4;
  void *pvVar5;
  SHAPE_31fake *prim;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined3 in_register_00000015;
  uint uVar9;
  uchar *puVar10;
  _TMD_2D *p_Var11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  SHAPE_68fake local_50;
  short local_40;
  short local_3e;
  uint local_3c;
  uint local_38;
  uint local_34;
  int local_30;
  
  prim = (SHAPE_31fake *)CONCAT31(in_register_00000015,pft4);
  if (mode == 10) {
    uVar1 = *(ushort *)((int)&(mo->Env).nPivot + 2);
    iVar4 = *(int *)(*(int *)(*(int *)(mo->Sq).Data.FatherTrans + 8) + 4);
    *(short *)((int)&(mo->Env).nPivot + 2) = uVar1 + 4;
    local_3c = iVar4 - 0x10;
    if (average == 0) {
      trap(0x1c00);
    }
    p_Var11 = (_TMD_2D *)((int)&Tmd_2D->vx + ((uint)uVar1 & 0xf0));
  }
  else {
    local_3c = *(uint *)(*(int *)(*(int *)(mo->Sq).Data.FatherTrans + 8) + 4);
    p_Var11 = Tmd_2D;
    if (average == 0) {
      trap(0x1c00);
      p_Var11 = Tmd_2D;
    }
  }
  local_3c = local_3c / (uint)average;
  local_50.file = Effects_Pcl;
  iVar6 = (int)(mo->Env).Obj.vert_top.vz;
  iVar4 = end - (start + -1);
  if (iVar4 == 0) {
    trap(0x1c00);
  }
  if ((iVar4 == -1) && (iVar6 == -0x80000000)) {
    trap(0x1800);
  }
  local_50.shape = (short)start + (short)(iVar6 % iVar4);
  Shp_GetWH(&local_50,&local_40,&local_3e);
  iVar4 = 0;
  local_40 = (short)((uint)((int)local_40 * coef) >> 8);
  local_3e = (short)((uint)((int)local_3e * coef) >> 8);
  if (0 < (int)local_3c) {
    local_38 = mode - 2;
    local_34 = (uint)(local_38 < 5);
    puVar10 = &prim->v3;
    local_30 = local_38 * 4;
    do {
      if (mode == 10) {
        iVar7 = (int)(mo->Env).Obj.vert_top.vz;
        iVar6 = end - (start + -1);
        if (iVar6 == 0) {
          trap(0x1c00);
        }
        if ((iVar6 == -1) && (iVar7 == -0x80000000)) {
          trap(0x1800);
        }
        iVar6 = iVar4 * 8 + iVar7 % iVar6;
        iVar7 = end - start;
        local_50.shape = (short)iVar6;
        if (iVar7 < iVar6) {
          iVar6 = iVar6 - iVar7;
          do {
            bVar2 = iVar7 < iVar6;
            iVar6 = iVar6 - iVar7;
          } while (bVar2);
          local_50.shape = (short)iVar6 + (short)iVar7;
        }
        local_50.shape = (short)start + local_50.shape;
      }
      iVar6 = (int)((uint)(ushort)p_Var11->vz << 0x10) >> 0x12;
      iVar7 = iVar6 + -0x10;
      if ((0 < iVar7) && (iVar7 < (int)Scr_OtSize + -0xc)) {
        if (Main_TextContext.Font.ascii_tab._20_4_ <= (int)prim) {
          return prim;
        }
        uVar8 = SEXT24(local_40);
        iVar12 = uVar8 * (int)Scr_GeomScreen;
        uVar13 = iVar12 / iVar7;
        if (iVar7 == 0) {
          trap(0x1c00);
        }
        if ((iVar7 == -1) && (iVar12 == -0x80000000)) {
          trap(0x1800);
        }
        uVar9 = SEXT24(local_3e);
        iVar12 = uVar9 * (int)Scr_GeomScreen;
        uVar14 = iVar12 / iVar7;
        if (iVar7 == 0) {
          trap(0x1c00);
        }
        if ((iVar7 == -1) && (iVar12 == -0x80000000)) {
          trap(0x1800);
        }
        if (mode == 1) {
          if ((int)uVar8 < (int)uVar13) {
            uVar13 = uVar8;
          }
          if ((int)uVar9 < (int)uVar14) {
            uVar14 = uVar9;
          }
        }
        else {
          if ((int)(uVar8 << 2) < (int)uVar13) {
            uVar13 = uVar8 << 2;
          }
          if ((int)(uVar9 << 2) < (int)uVar14) {
            uVar14 = uVar9 << 2;
          }
        }
        local_50.x = p_Var11->vx;
        local_50.y = p_Var11->vy;
        if ((local_34 != 0) || (mode == 8)) {
          local_50.x = local_50.x - (short)((int)(uVar13 + (uVar13 >> 0x1f)) >> 1);
          local_50.y = local_50.y - (short)((int)(uVar14 + (uVar14 >> 0x1f)) >> 1);
        }
        Shp_SetPolyFT4(prim,&local_50,(short)uVar13,(short)uVar14);
        if (((local_34 != 0) || (mode == 8)) || (mode == 9)) {
          puVar10[-0x1e] = puVar10[-0x1e] & 0xfe;
          iVar7 = iVar6 + -4;
          if (local_38 < 8) {
                    /* WARNING: Could not recover jumptable at 0x80025488. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            pvVar5 = (void *)(**(code **)((int)PTR_ARRAY_800a5014 + local_30))();
            return pvVar5;
          }
        }
        puVar10[-0x11] = puVar10[-0x11] + '\x01';
        puVar10[-1] = puVar10[-1] + '\x01';
        puVar10[-8] = puVar10[-8] + '\x01';
        *puVar10 = *puVar10 + '\x01';
        p_Var3 = Scr;
        puVar10 = puVar10 + 0x28;
        prim->tag = prim->tag & 0xff000000 | Scr->ot[iVar7] & 0xffffff;
        uVar13 = (uint)prim & 0xffffff;
        prim = prim + 1;
        p_Var3->ot[iVar7] = p_Var3->ot[iVar7] & 0xff000000 | uVar13;
      }
      iVar4 = iVar4 + 1;
      p_Var11 = p_Var11 + average;
    } while (iVar4 < (int)local_3c);
  }
  return prim;
}



// decompiled code
// original method signature: 
// void * /*$ra*/ Motion2D_ManimSmoke(struct M_OBJECT *mo /*$s1*/, void *prims /*$s0*/)
 // line 407, offset 0x800256dc
	/* begin block 1 */
		// Start line: 408
		// Start offset: 0x800256DC
		// Variables:
	// 		long coef; // $v1
	/* end block 1 */
	// End offset: 0x80025770
	// End Line: 427

	/* begin block 2 */
		// Start line: 1085
	/* end block 2 */
	// End Line: 1086

void * Motion2D_ManimSmoke(M_OBJECT *mo,void *prims)

{
  void *pvVar1;
  int iVar2;
  long coef;
  
  iVar2 = (int)(mo->Env).Obj.vert_top.vz;
  if (iVar2 < 0x11) {
    coef = iVar2 << 4;
  }
  else {
    if (iVar2 < 0x28) {
      coef = 0x100;
    }
    else {
      coef = (0x38 - iVar2) * 8;
    }
  }
  pvVar1 = Motion2D_ShapesMotionCapture(mo,(char)prims,0x65,0x74,0x28,coef,10);
  if (0x31 < (mo->Env).Obj.vert_top.vz) {
    Manim_SetEffect(mo,(TDRFuncPtr_Manim_SetEffect1f)0x0);
  }
  (mo->Env).Obj.normal_top.vx = (mo->Env).Obj.normal_top.vx | 0x10;
  return pvVar1;
}



// decompiled code
// original method signature: 
// void * /*$ra*/ Motion2D_EffectSmokeXtra(struct M_OBJECT *mo /*$s0*/, void *prims /*$s1*/)
 // line 434, offset 0x80025794
	/* begin block 1 */
		// Start line: 435
		// Start offset: 0x80025794
		// Variables:
	// 		long coef; // $v1
	/* end block 1 */
	// End offset: 0x80025890
	// End Line: 461

	/* begin block 2 */
		// Start line: 1142
	/* end block 2 */
	// End Line: 1143

void * Motion2D_EffectSmokeXtra(M_OBJECT *mo,void *prims)

{
  short sVar1;
  ushort uVar2;
  void *pvVar3;
  int iVar4;
  long coef;
  ushort uVar5;
  
  iVar4 = (int)(mo->Env).Obj.vert_top.vz;
  if (iVar4 < 0x11) {
    coef = iVar4 << 4;
  }
  else {
    if (iVar4 < 0x50) {
      coef = 0x100;
    }
    else {
      coef = (0x60 - iVar4) * 8;
    }
  }
  pvVar3 = Motion2D_ShapesMotionCapture(mo,(char)prims,0x65,0x74,0x28,coef,10);
  if (0x60 < (mo->Env).Obj.vert_top.vz) {
    Manim_SetEffect(mo,(TDRFuncPtr_Manim_SetEffect1f)0x0);
  }
  sVar1 = (mo->Env).Obj.vert_top.vz;
  uVar2 = (mo->Env).Obj.vert_top.vz;
  uVar5 = (mo->Env).Obj.normal_top.vx & 0xffef;
  (mo->Env).Obj.normal_top.vx = uVar5;
  if ((0x27 < sVar1) && (((uVar2 & 1) != 0 || (0x2c < sVar1)))) {
    uVar2 = (mo->Env).Obj.vert_top.vz;
    if (0x12 < (uint)uVar2 - 0x2e) {
      return pvVar3;
    }
    if ((uVar2 & 3) != 0) {
      return pvVar3;
    }
    uVar5 = (mo->Env).Obj.normal_top.vx;
  }
  (mo->Env).Obj.normal_top.vx = uVar5 | 0x10;
  return pvVar3;
}



// decompiled code
// original method signature: 
// void * /*$ra*/ Motion2D_ManimBurn(struct M_OBJECT *mo /*$s1*/, void *prims /*$s0*/)
 // line 465, offset 0x800258a8
	/* begin block 1 */
		// Start line: 466
		// Start offset: 0x800258A8
		// Variables:
	// 		long coef; // $v1
	/* end block 1 */
	// End offset: 0x80025938
	// End Line: 485

	/* begin block 2 */
		// Start line: 1206
	/* end block 2 */
	// End Line: 1207

void * Motion2D_ManimBurn(M_OBJECT *mo,void *prims)

{
  void *pvVar1;
  int iVar2;
  long coef;
  
  iVar2 = (int)(mo->Env).Obj.vert_top.vz;
  if (iVar2 < 0x11) {
    coef = iVar2 << 4;
  }
  else {
    if (iVar2 < 0x28) {
      coef = 0x100;
    }
    else {
      coef = (0x38 - iVar2) * 8;
    }
  }
  pvVar1 = Motion2D_ShapesMotionCapture(mo,(char)prims,0xaa,0xc5,3,coef,0);
  if (0x37 < (mo->Env).Obj.vert_top.vz) {
    Manim_SetEffect(mo,(TDRFuncPtr_Manim_SetEffect1f)0x0);
  }
  (mo->Env).Obj.normal_top.vx = (mo->Env).Obj.normal_top.vx | 0x10;
  return pvVar1;
}



// decompiled code
// original method signature: 
// void * /*$ra*/ Motion2D_ManimSmallBurn(struct M_OBJECT *mo /*$s1*/, void *prims /*$s0*/)
 // line 492, offset 0x8002595c
	/* begin block 1 */
		// Start line: 493
		// Start offset: 0x8002595C
		// Variables:
	// 		long coef; // $v1
	/* end block 1 */
	// End offset: 0x800259EC
	// End Line: 512

	/* begin block 2 */
		// Start line: 1263
	/* end block 2 */
	// End Line: 1264

void * Motion2D_ManimSmallBurn(M_OBJECT *mo,void *prims)

{
  void *pvVar1;
  int iVar2;
  long coef;
  
  iVar2 = (int)(mo->Env).Obj.vert_top.vz;
  if (iVar2 < 5) {
    coef = iVar2 << 6;
  }
  else {
    if (iVar2 < 0x10) {
      coef = 0x100;
    }
    else {
      coef = (0x18 - iVar2) * 0x10;
    }
  }
  pvVar1 = Motion2D_ShapesMotionCapture(mo,(char)prims,0xaa,0xc5,0x18,coef,0);
  if (0x17 < (mo->Env).Obj.vert_top.vz) {
    Manim_SetEffect(mo,(TDRFuncPtr_Manim_SetEffect1f)0x0);
  }
  (mo->Env).Obj.normal_top.vx = (mo->Env).Obj.normal_top.vx | 0x10;
  return pvVar1;
}



// decompiled code
// original method signature: 
// void * /*$ra*/ Motion2D_ManimElectricity(struct M_OBJECT *mo /*$s2*/, void *prims /*$s1*/)
 // line 519, offset 0x80025a10
	/* begin block 1 */
		// Start line: 520
		// Start offset: 0x80025A10
		// Variables:
	// 		long coef; // $s0
	// 		long r; // $a2
	/* end block 1 */
	// End offset: 0x80025AC4
	// End Line: 540

	/* begin block 2 */
		// Start line: 1320
	/* end block 2 */
	// End Line: 1321

void * Motion2D_ManimElectricity(M_OBJECT *mo,void *prims)

{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  long coef;
  
  iVar3 = (int)(mo->Env).Obj.vert_top.vz;
  if (iVar3 < 5) {
    coef = iVar3 << 6;
  }
  else {
    coef = 0x100;
    if (0xf < iVar3) {
      coef = (0x14 - iVar3) * 8;
    }
  }
  uVar1 = M_rand();
  uVar4 = 0;
  if (Pvl_Pause == 0) {
    uVar4 = uVar1 & 0xf;
  }
  pvVar2 = Motion2D_ShapesMotionCapture(mo,(char)prims,0xa8,0xa9,uVar4 + 0x30,coef,1);
  if (0x14 < (mo->Env).Obj.vert_top.vz) {
    Manim_SetEffect(mo,(TDRFuncPtr_Manim_SetEffect1f)0x0);
  }
  (mo->Env).Obj.normal_top.vx = (mo->Env).Obj.normal_top.vx | 0x10;
  return pvVar2;
}



// decompiled code
// original method signature: 
// void * /*$ra*/ Motion2D_ManimGhost(struct M_OBJECT *mo /*$s0*/, void *prims /*$s1*/)
 // line 547, offset 0x80025aec
	/* begin block 1 */
		// Start line: 548
		// Start offset: 0x80025AEC
		// Variables:
	// 		long coef; // $v1
	/* end block 1 */
	// End offset: 0x80025BF0
	// End Line: 576

	/* begin block 2 */
		// Start line: 1379
	/* end block 2 */
	// End Line: 1380

void * Motion2D_ManimGhost(M_OBJECT *mo,void *prims)

{
  short sVar1;
  uint uVar2;
  void *pvVar3;
  int iVar4;
  long coef;
  ushort uVar5;
  
  iVar4 = (int)(mo->Env).Obj.vert_top.vz;
  uVar5 = (mo->Env).Obj.normal_top.vx & 0xffdf;
  (mo->Env).Obj.normal_top.vx = uVar5;
  if (iVar4 < 0x11) {
    coef = iVar4 << 3;
  }
  else {
    if (iVar4 < 0x80) {
      (mo->Env).Obj.normal_top.vx = uVar5 | 0x20;
      (mo->Env).Obj.vert_top.vz = 0x20;
      uVar2 = M_rand();
      coef = 0x70;
      if (Pvl_Pause == 0) {
        coef = (uVar2 & 0x1f) + 0x70;
      }
    }
    else {
      coef = (iVar4 + -0x80) * -8 + 0x80;
    }
  }
  pvVar3 = Motion2D_ShapesMotionCapture(mo,(char)prims,0xe8,0xe8,8,coef,2);
  sVar1 = (mo->Env).Obj.vert_top.vz;
  if ((sVar1 < 0x11) || (0x7f < sVar1)) {
    uVar5 = (mo->Env).Obj.normal_top.vx | 0x10;
  }
  else {
    uVar5 = (mo->Env).Obj.normal_top.vx & 0xffef;
  }
  (mo->Env).Obj.normal_top.vx = uVar5;
  if (0x8f < (mo->Env).Obj.vert_top.vz) {
    Manim_SetEffect(mo,(TDRFuncPtr_Manim_SetEffect1f)0x0);
  }
  return pvVar3;
}



// decompiled code
// original method signature: 
// void * /*$ra*/ Motion2D_ManimInvincibility(struct M_OBJECT *mo /*$s0*/, void *prims /*$s1*/)
 // line 580, offset 0x80025c08
	/* begin block 1 */
		// Start line: 581
		// Start offset: 0x80025C08
		// Variables:
	// 		long coef; // $v1
	/* end block 1 */
	// End offset: 0x80025CD8
	// End Line: 602

	/* begin block 2 */
		// Start line: 1450
	/* end block 2 */
	// End Line: 1451

void * Motion2D_ManimInvincibility(M_OBJECT *mo,void *prims)

{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  ushort uVar4;
  
  iVar3 = (int)(mo->Env).Obj.vert_top.vz;
  uVar4 = (mo->Env).Obj.normal_top.vx & 0xffdf;
  (mo->Env).Obj.normal_top.vx = uVar4;
  if (iVar3 < 5) {
    iVar3 = iVar3 << 4;
  }
  else {
    if (iVar3 < 0x80) {
      (mo->Env).Obj.normal_top.vx = uVar4 | 0x20;
      (mo->Env).Obj.vert_top.vz = 8;
      uVar1 = M_rand();
      iVar3 = 0x70;
      if (Pvl_Pause == 0) {
        iVar3 = (uVar1 & 0x1f) + 0x70;
      }
    }
    else {
      iVar3 = (0x90 - iVar3) * 8;
    }
  }
  pvVar2 = Motion2D_ShapesMotionCapture
                     (mo,(char)prims,0xe8,0xe8,0x30,iVar3 << 1,
                      (int)*(short *)((int)&(mo->Env).nPivot + 2) + 3);
  if (0x8f < (mo->Env).Obj.vert_top.vz) {
    Manim_SetEffect(mo,(TDRFuncPtr_Manim_SetEffect1f)0x0);
  }
  (mo->Env).Obj.normal_top.vx = (mo->Env).Obj.normal_top.vx | 0x10;
  return pvVar2;
}



// decompiled code
// original method signature: 
// void * /*$ra*/ Motion2D_ManimMagic(struct M_OBJECT *mo /*$s2*/, void *prims /*$s1*/)
 // line 609, offset 0x80025cfc
	/* begin block 1 */
		// Start line: 1515
	/* end block 1 */
	// End Line: 1516

void * Motion2D_ManimMagic(M_OBJECT *mo,void *prims)

{
  uint uVar1;
  uint uVar2;
  
  if (Pvl_Pause == 0) {
    uVar1 = M_rand();
    uVar2 = M_rand();
    prims = Motion2D_ShapesMotionCapture
                      (mo,(char)prims,0xa1,0xa6,(uVar1 & 3) + 0x10,(uVar2 & 0x100) + 0x80,9);
  }
  (mo->Env).Obj.normal_top.vx = (mo->Env).Obj.normal_top.vx | 0x10;
  return prims;
}



// decompiled code
// original method signature: 
// void * /*$ra*/ Motion2D_EffectAnimXtra(struct M_OBJECT *mo /*$s0*/, void *prims /*$s1*/)
 // line 622, offset 0x80025d90
	/* begin block 1 */
		// Start line: 623
		// Start offset: 0x80025D90
		// Variables:
	// 		long coef; // $v1
	/* end block 1 */
	// End offset: 0x80025E88
	// End Line: 649

	/* begin block 2 */
		// Start line: 1543
	/* end block 2 */
	// End Line: 1544

void * Motion2D_EffectAnimXtra(M_OBJECT *mo,void *prims)

{
  short sVar1;
  ushort uVar2;
  void *pvVar3;
  int iVar4;
  long coef;
  ushort uVar5;
  
  iVar4 = (int)(mo->Env).Obj.vert_top.vz;
  if (iVar4 < 0x11) {
    coef = iVar4 << 4;
  }
  else {
    if (iVar4 < 0x50) {
      coef = 0x100;
    }
    else {
      coef = (0x60 - iVar4) * 8;
    }
  }
  pvVar3 = Motion2D_ShapesMotionCapture(mo,(char)prims,0xaa,0xc5,3,coef,0);
  if (0x60 < (mo->Env).Obj.vert_top.vz) {
    Manim_SetEffect(mo,(TDRFuncPtr_Manim_SetEffect1f)0x0);
  }
  sVar1 = (mo->Env).Obj.vert_top.vz;
  uVar2 = (mo->Env).Obj.vert_top.vz;
  uVar5 = (mo->Env).Obj.normal_top.vx & 0xffef;
  (mo->Env).Obj.normal_top.vx = uVar5;
  if ((0x27 < sVar1) && (((uVar2 & 1) != 0 || (0x2c < sVar1)))) {
    uVar2 = (mo->Env).Obj.vert_top.vz;
    if (0x12 < (uint)uVar2 - 0x2e) {
      return pvVar3;
    }
    if ((uVar2 & 3) != 0) {
      return pvVar3;
    }
    uVar5 = (mo->Env).Obj.normal_top.vx;
  }
  (mo->Env).Obj.normal_top.vx = uVar5 | 0x10;
  return pvVar3;
}



// decompiled code
// original method signature: 
// void * /*$ra*/ Motion2D_ManimFreeze(struct M_OBJECT *mo /*$s0*/, void *prims /*$s1*/)
 // line 653, offset 0x80025ea0
	/* begin block 1 */
		// Start line: 1607
	/* end block 1 */
	// End Line: 1608

void * Motion2D_ManimFreeze(M_OBJECT *mo,void *prims)

{
  short sVar1;
  ushort uVar2;
  uint uVar3;
  
  sVar1 = (mo->Env).Obj.vert_top.vz;
  if ((mo->Env).Obj.vert_top.vz < 0x88) {
    if ((ushort)(sVar1 - 0x12U) < 0x6e) {
      (mo->Env).Obj.vert_top.vz = sVar1 + -6;
    }
  }
  else {
    Manim_SetEffect(mo,(TDRFuncPtr_Manim_SetEffect1f)0x0);
  }
  uVar2 = (mo->Env).Obj.vert_top.vz;
  if (((uVar2 & 1) == 0) || ((uint)uVar2 - 8 < 10)) {
    uVar2 = (mo->Env).Obj.normal_top.vx & 0xffef;
  }
  else {
    uVar2 = (mo->Env).Obj.normal_top.vx | 0x10;
  }
  (mo->Env).Obj.normal_top.vx = uVar2;
  if (((((mo->Env).Obj.normal_top.vx & 0x10U) == 0) &&
      (prims = Motion2D_EnvMotionCapture(mo,prims,0),
      (uint)(ushort)(mo->Env).Obj.vert_top.vz - 8 < 0x78)) && (Pvl_Pause == 0)) {
    uVar3 = M_rand();
    prims = Motion2D_ShapesMotionCapture(mo,(char)prims,0xa1,0xa6,(uVar3 & 0x1f) + 0x30,0x100,0);
  }
  return prims;
}



// decompiled code
// original method signature: 
// void * /*$ra*/ Motion2D_ManimVampire(struct M_OBJECT *mo /*$s0*/, void *prims /*$s1*/)
 // line 684, offset 0x80025fd0
	/* begin block 1 */
		// Start line: 685
		// Start offset: 0x80025FD0
		// Variables:
	// 		long coef; // $v1
	/* end block 1 */
	// End offset: 0x800260BC
	// End Line: 711

	/* begin block 2 */
		// Start line: 1669
	/* end block 2 */
	// End Line: 1670

void * Motion2D_ManimVampire(M_OBJECT *mo,void *prims)

{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  ushort uVar4;
  
  iVar3 = (int)(mo->Env).Obj.vert_top.vz;
  uVar4 = (mo->Env).Obj.normal_top.vx & 0xffdf;
  (mo->Env).Obj.normal_top.vx = uVar4;
  if (iVar3 < 5) {
    iVar3 = iVar3 << 4;
  }
  else {
    if (iVar3 < 0x80) {
      (mo->Env).Obj.normal_top.vx = uVar4 | 0x20;
      (mo->Env).Obj.vert_top.vz = 8;
      uVar1 = M_rand();
      iVar3 = 0x70;
      if (Pvl_Pause == 0) {
        iVar3 = (uVar1 & 0x1f) + 0x70;
      }
    }
    else {
      iVar3 = (0x90 - iVar3) * 8;
    }
  }
  pvVar2 = Motion2D_ShapesMotionCapture(mo,(char)prims,0xe8,0xe8,0x20,iVar3 << 1,8);
  if (0x8f < (mo->Env).Obj.vert_top.vz) {
    if (mo->sit->color == 0xff2020) {
      mo->sit->color = 0x808080;
    }
    Manim_SetEffect(mo,(TDRFuncPtr_Manim_SetEffect1f)0x0);
  }
  (mo->Env).Obj.normal_top.vx = (mo->Env).Obj.normal_top.vx | 0x10;
  return pvVar2;
}



// decompiled code
// original method signature: 
// void * /*$ra*/ Motion2D_ManimDistortion(struct M_OBJECT *mo /*$s0*/, void *prims /*$s1*/)
 // line 718, offset 0x800260e0
	/* begin block 1 */
		// Start line: 1742
	/* end block 1 */
	// End Line: 1743

void * Motion2D_ManimDistortion(M_OBJECT *mo,void *prims)

{
  void *pvVar1;
  
  if (0x13f < (mo->Env).Obj.vert_top.vz) {
    Manim_SetEffect(mo,(TDRFuncPtr_Manim_SetEffect1f)0x0);
  }
  pvVar1 = Motion2D_EnvMotionCapture(mo,prims,1);
  return pvVar1;
}



// decompiled code
// original method signature: 
// void * /*$ra*/ Motion2D_ManimSmallDistortion(struct M_OBJECT *mo /*$s0*/, void *prims /*$s1*/)
 // line 733, offset 0x80026134
	/* begin block 1 */
		// Start line: 1772
	/* end block 1 */
	// End Line: 1773

void * Motion2D_ManimSmallDistortion(M_OBJECT *mo,void *prims)

{
  void *pvVar1;
  
  if (0x1f < (mo->Env).Obj.vert_top.vz) {
    Manim_SetEffect(mo,(TDRFuncPtr_Manim_SetEffect1f)0x0);
  }
  pvVar1 = Motion2D_EnvMotionCapture(mo,prims,2);
  return pvVar1;
}



// decompiled code
// original method signature: 
// void * /*$ra*/ Motion2D_ManimWaveDistortion(struct M_OBJECT *mo /*$s0*/, void *prims /*$s1*/)
 // line 748, offset 0x80026188
	/* begin block 1 */
		// Start line: 1802
	/* end block 1 */
	// End Line: 1803

void * Motion2D_ManimWaveDistortion(M_OBJECT *mo,void *prims)

{
  void *pvVar1;
  
  if (0x13f < (mo->Env).Obj.vert_top.vz) {
    Manim_SetEffect(mo,(TDRFuncPtr_Manim_SetEffect1f)0x0);
  }
  pvVar1 = Motion2D_EnvMotionCapture(mo,prims,3);
  return pvVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Motion2D_FireRainInit(struct _FIRERAIN *fr /*$s0*/, struct _D3_OBJECT *owner /*$s2*/, long hp /*$s1*/)
 // line 794, offset 0x800261dc
	/* begin block 1 */
		// Start line: 795
		// Start offset: 0x800261DC
		// Variables:
	// 		long i; // $a1
	/* end block 1 */
	// End offset: 0x80026270
	// End Line: 817

	/* begin block 2 */
		// Start line: 1894
	/* end block 2 */
	// End Line: 1895

void Motion2D_FireRainInit(_FIRERAIN *fr,_D3_OBJECT *owner,long hp)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  
  D3_SetBox((_D3_OBJECT *)fr,-0xc,-0xc,-0xc,0xc,0xc,0xc);
  iVar3 = 0x1f;
  iVar2 = (int)&(fr->obj).collision_state + 1;
  (fr->obj).collision_mode = 0x2002;
  (fr->obj).hit_power = (uchar)hp;
  *(undefined *)((int)fr->dcolors + 1) = 0xf0;
  pvVar1 = Pl_Pcl;
  *(_D3_OBJECT **)(fr->dcolors + 5) = (_D3_OBJECT *)&fr[8].obj.b_step;
  (fr->obj).collision_state = 0;
  *(_D3_OBJECT **)(fr->dcolors + 2) = owner;
  *(undefined2 *)(fr->dcolors + 6) = 8;
  fr[8].trails.vz = 0;
  *(void **)(fr->dcolors + 3) = pvVar1;
  do {
    *(undefined *)(iVar2 + 0xb54) = 0;
    iVar3 = iVar3 + -1;
    iVar2 = iVar2 + -1;
  } while (-1 < iVar3);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Motion2D_FireRainAdd(struct TASK *t /*$a0*/, struct MOTION2D_7fake *p /*$a1*/, struct MOTION2D_7fake *s /*$a2*/)
 // line 820, offset 0x80026288
	/* begin block 1 */
		// Start line: 822
		// Start offset: 0x80026288
		// Variables:
	// 		struct _FIRERAIN *fr; // $a0
	// 		long i; // $a3
	/* end block 1 */
	// End offset: 0x8002632C
	// End Line: 844

	/* begin block 2 */
		// Start line: 1986
	/* end block 2 */
	// End Line: 1987

void Motion2D_FireRainAdd(TASK *t,undefined p,undefined s)

{
  TASK *pTVar1;
  undefined3 in_register_00000015;
  undefined3 in_register_00000019;
  int iVar2;
  int iVar3;
  TASK *pTVar4;
  _func_12 *p_Var5;
  TASK *pTVar6;
  
  pTVar6 = t + 1;
  iVar2 = 0;
  pTVar1 = pTVar6;
  pTVar4 = pTVar6;
  if (*(short *)&t[0x15].s2 < 0x20) {
    do {
      iVar3 = (int)&pTVar6->prec + iVar2;
      iVar2 = iVar2 + 1;
      if (*(char *)(iVar3 + 0xb54) == '\0') {
        p_Var5 = ((_func_12 **)CONCAT31(in_register_00000015,p))[1];
        pTVar1[1].destructor = *(_func_12 **)CONCAT31(in_register_00000015,p);
        *(_func_12 **)&pTVar1[1].local = p_Var5;
        pTVar6 = ((TASK **)CONCAT31(in_register_00000019,s))[1];
        pTVar1[3].next = *(TASK **)CONCAT31(in_register_00000019,s);
        pTVar1[3].father = pTVar6;
        pTVar4[0x13].next = (TASK *)0x0;
        *(undefined *)(iVar3 + 0xb54) = 1;
        *(short *)&t[0x15].s2 = *(short *)&t[0x15].s2 + 1;
        return;
      }
      pTVar1 = (TASK *)&pTVar1->father;
      pTVar4 = (TASK *)&pTVar4->next;
    } while (iVar2 < 0x20);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Motion2D_FireRainMove(struct _FIRERAIN *fr /*$s5*/, long gravity /*stack 4*/)
 // line 847, offset 0x80026334
	/* begin block 1 */
		// Start line: 848
		// Start offset: 0x80026334
		// Variables:
	// 		struct MOTION2D_7fake *p; // $s2
	// 		struct MOTION2D_7fake *s; // $s3
	// 		struct MOTION2D_7fake *t; // $s4
	// 		long i; // $s7
	// 		long j; // $s0
	/* end block 1 */
	// End offset: 0x8002665C
	// End Line: 922

	/* begin block 2 */
		// Start line: 2045
	/* end block 2 */
	// End Line: 2046

void Motion2D_FireRainMove(_FIRERAIN *fr,long gravity)

{
  byte bVar1;
  long lVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 *puVar8;
  short *psVar9;
  short *psVar10;
  _FIRERAIN *p_Var11;
  uint i;
  int local_38;
  int local_34;
  _FIRERAIN *local_30;
  
  i = 0;
  local_38 = 0xb4;
  local_34 = 0;
  p_Var11 = fr;
  local_30 = fr;
  do {
    bVar1 = *(byte *)&p_Var11[8].list.pos.vz;
    if (bVar1 != 0) {
      if (bVar1 < 2) {
        psVar9 = (short *)((int)&(fr->obj).next + local_38);
        psVar10 = (short *)((int)&fr[1].obj.b_hurt + local_34);
        *psVar9 = *psVar9 + *psVar10;
        psVar9[1] = psVar9[1] + psVar10[1];
        psVar9[2] = psVar9[2] + psVar10[2];
        puVar5 = (undefined4 *)(&fr[1].n_drops + i * 0x20);
        if (gravity != 0) {
          psVar10[2] = psVar10[2] + -1;
        }
        iVar7 = 0;
        puVar8 = puVar5;
        do {
          *(short *)puVar8 =
               *psVar9 - ((short)((ulonglong)((longlong)((int)*psVar10 * iVar7) * 0x55555556) >>
                                 0x20) - (short)((int)*psVar10 * iVar7 >> 0x1f));
          *(short *)((int)puVar8 + 2) =
               psVar9[1] -
               ((short)((ulonglong)((longlong)((int)psVar10[1] * iVar7) * 0x55555556) >> 0x20) -
               (short)((int)psVar10[1] * iVar7 >> 0x1f));
          *(short *)(puVar8 + 1) =
               psVar9[2] -
               ((short)((ulonglong)((longlong)((int)psVar10[2] * iVar7) * 0x55555556) >> 0x20) -
               (short)((int)psVar10[2] * iVar7 >> 0x1f));
          lVar2 = M_rand();
          *(ushort *)((int)puVar8 + 6) = (((ushort)lVar2 & 3) + 0x29) * 0x100 | 10U - (short)iVar7;
          iVar7 = iVar7 + 1;
          puVar8 = puVar8 + 2;
        } while (iVar7 < 8);
        if (*(short *)(puVar5 + 1) < -500) {
          *(undefined *)&p_Var11[8].list.pos.vz = 0;
          fr[8].trails.vz = fr[8].trails.vz + -1;
        }
        else {
          iVar3 = local_30[7].colors[6] + 0x303030;
          iVar7 = 0x808080;
          if (iVar3 < 0x808081) {
            iVar7 = iVar3;
          }
          uVar4 = Pvl_GameTime & 3;
          local_30[7].colors[6] = iVar7;
          if ((i & 3) == uVar4) {
            uVar6 = puVar5[1];
            *(undefined4 *)&(fr->obj).pos = *puVar5;
            *(undefined4 *)&(fr->obj).pos.vz = uVar6;
            uVar6 = puVar5[0xf];
            *(undefined4 *)&(fr->obj).last_pos = puVar5[0xe];
            *(undefined4 *)&(fr->obj).last_pos.vz = uVar6;
            lVar2 = Boxes_TestObject((_D3_OBJECT *)fr);
            if (lVar2 != 0) {
              Fx_Play(0xc,(char)fr + (char)local_38);
              iVar7 = 0;
              *(char *)&p_Var11[8].list.pos.vz = *(char *)&p_Var11[8].list.pos.vz + '\x01';
              psVar10[2] = 5;
              do {
                uVar6 = *(undefined4 *)&(fr->obj).last_pos.vz;
                *puVar5 = *(undefined4 *)&(fr->obj).last_pos;
                puVar5[1] = uVar6;
                iVar7 = iVar7 + 1;
                *(short *)(puVar5 + 1) = *(short *)(puVar5 + 1) + 0x19;
                puVar5 = puVar5 + 2;
              } while (iVar7 < 8);
            }
          }
        }
      }
      else {
        Motion2D_FireRainImpact(fr,i);
      }
    }
    p_Var11 = (_FIRERAIN *)((int)&(p_Var11->obj).next + 1);
    i = i + 1;
    local_38 = local_38 + 8;
    local_34 = local_34 + 8;
    local_30 = (_FIRERAIN *)&(local_30->obj).prec;
  } while ((int)i < 0x20);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Motion2D_FireRainImpact(struct _FIRERAIN *fr /*$s3*/, long i /*$s4*/)
 // line 925, offset 0x8002668c
	/* begin block 1 */
		// Start line: 926
		// Start offset: 0x8002668C
		// Variables:
	// 		struct MOTION2D_7fake *s; // $s5
	// 		long j; // $s2

		/* begin block 1.1 */
			// Start line: 946
			// Start offset: 0x800266FC
			// Variables:
		// 		long rc; // $s0
		// 		long rs; // $a0
		/* end block 1.1 */
		// End offset: 0x80026760
		// End Line: 953
	/* end block 1 */
	// End offset: 0x800267FC
	// End Line: 963

	/* begin block 2 */
		// Start line: 2301
	/* end block 2 */
	// End Line: 2302

void Motion2D_FireRainImpact(_FIRERAIN *fr,long i)

{
  int iVar1;
  int iVar2;
  long lVar3;
  short *psVar4;
  int iVar5;
  
  iVar5 = (int)&(fr->obj).next + i;
  if (*(byte *)(iVar5 + 0xb54) < 10) {
    iVar5 = 0;
    psVar4 = &fr[1].n_drops + i * 0x20;
    do {
      iVar1 = rcos(iVar5 << 9);
      iVar2 = rsin(iVar5 << 9);
      iVar1 = iVar1 * 100;
      if (iVar1 < 0) {
        iVar1 = iVar1 + 7;
      }
      iVar2 = iVar2 * 100;
      *psVar4 = *psVar4 + (short)(iVar1 >> 0xf);
      if (iVar2 < 0) {
        iVar2 = iVar2 + 7;
      }
      psVar4[1] = psVar4[1] + (short)(iVar2 >> 0xf);
      iVar5 = iVar5 + 1;
      psVar4[2] = psVar4[2] + *(short *)(&fr[1].obj.b_sunk + i * 2);
      lVar3 = M_rand();
      iVar1 = (int)&(fr->obj).next + i;
      psVar4[3] = (((ushort)lVar3 & 3) + 0x29) * 0x100 | 10 - (ushort)*(byte *)(iVar1 + 0xb54);
      psVar4 = psVar4 + 4;
    } while (iVar5 < 8);
    fr[7].colors[i + 6] = ((uint)*(byte *)(iVar1 + 0xb54) - 2) * -0x101010 + 0x808080;
    *(char *)(iVar1 + 0xb54) = *(char *)(iVar1 + 0xb54) + '\x01';
  }
  else {
    *(undefined *)(iVar5 + 0xb54) = 0;
    fr[8].trails.vz = fr[8].trails.vz + -1;
  }
  return;
}



// decompiled code
// original method signature: 
// struct TASK * /*$ra*/ Motion2D_FireRain(struct _D3_OBJECT *owner /*$s1*/, struct MOTION2D_7fake *pos /*$s0*/, long area /*$s4*/, long time /*$s5*/, long freq /*stack 16*/, long hp /*stack 20*/)
 // line 967, offset 0x80026820
	/* begin block 1 */
		// Start line: 968
		// Start offset: 0x80026820
		// Variables:
	// 		struct TASK *t; // $v0
	/* end block 1 */
	// End offset: 0x80026820
	// End Line: 968

	/* begin block 2 */
		// Start line: 2417
	/* end block 2 */
	// End Line: 2418

TASK * Motion2D_FireRain(_D3_OBJECT *owner,undefined pos,long area,long time,long freq,long hp)

{
  TASK *pTVar1;
  long lVar2;
  undefined3 in_register_00000015;
  
  pTVar1 = Task_Add(Motion2D_FireRainTask,0xf78);
  *(_D3_OBJECT **)&pTVar1->s0 = owner;
  pTVar1->s1 = *(long *)CONCAT31(in_register_00000015,pos);
  lVar2 = ((long *)CONCAT31(in_register_00000015,pos))[1];
  pTVar1->s3 = area;
  pTVar1->s4 = time;
  pTVar1->s5 = freq;
  pTVar1->s6 = hp;
  pTVar1->s2 = lVar2;
  return pTVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Motion2D_FireRainTask()
 // line 990, offset 0x800268b4
	/* begin block 1 */
		// Start line: 991
		// Start offset: 0x800268B4
		// Variables:
	// 		long freq; // $s4
	// 		long time; // $s6
	// 		long area; // $s5
	// 		long i; // $s2
	// 		long hp; // $a2
	// 		struct MOTION2D_7fake center; // stack offset -64
	// 		struct MOTION2D_7fake spd; // stack offset -56
	// 		struct _FIRERAIN *fr; // $s3

		/* begin block 1.1 */
			// Start line: 1019
			// Start offset: 0x80026988
			// Variables:
		// 		long r; // $s0
		// 		struct MOTION2D_7fake pos; // stack offset -48
		/* end block 1.1 */
		// End offset: 0x80026A38
		// End Line: 1030
	/* end block 1 */
	// End offset: 0x80026A80
	// End Line: 1043

	/* begin block 2 */
		// Start line: 2489
	/* end block 2 */
	// End Line: 2490

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Motion2D_FireRainTask(void)

{
  _D3_OBJECT **pp_Var1;
  long *plVar2;
  TASK *pTVar3;
  uint uVar4;
  long lVar5;
  int iVar6;
  _FIRERAIN *fr;
  int iVar7;
  int iVar8;
  int iVar9;
  
  pTVar3 = TaskCurrent;
  iVar6 = 0;
  fr = (_FIRERAIN *)(TaskCurrent + 1);
  pp_Var1 = (_D3_OBJECT **)&TaskCurrent->s0;
  plVar2 = &TaskCurrent->s6;
  iVar8 = TaskCurrent->s3;
  iVar9 = TaskCurrent->s4;
  iVar7 = TaskCurrent->s5;
  TaskCurrent->display = Motion2D_FireRainTaskDisplay;
  Motion2D_FireRainInit(fr,*pp_Var1,*plVar2);
  M_rand();
  M_rand();
  if (0 < iVar9) {
    do {
      if (iVar7 == 0) {
        trap(0x1c00);
      }
      if ((iVar7 == -1) && (iVar6 == -0x80000000)) {
        trap(0x1800);
      }
      if (iVar6 % iVar7 == 0) {
        uVar4 = M_rand();
        lVar5 = M_rand();
        if (iVar8 == 0) {
          trap(0x1c00);
        }
        if ((iVar8 == -1) && (lVar5 == -0x80000000)) {
          trap(0x1800);
        }
        rcos(uVar4 & 0xfff);
        rsin(uVar4 & 0xfff);
        Motion2D_FireRainAdd(TaskCurrent,0xd0,200);
      }
      Motion2D_FireRainMove(fr,0);
      iVar6 = iVar6 + 1;
      Task_Next();
    } while (iVar6 < iVar9);
  }
  while (*(short *)&pTVar3[0x15].s2 != 0) {
    Motion2D_FireRainMove(fr,0);
    Task_Next();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Motion2D_FireRainTaskDisplay()
 // line 1046, offset 0x80026aac
	/* begin block 1 */
		// Start line: 1047
		// Start offset: 0x80026AAC
		// Variables:
	// 		struct _FIRERAIN *fr; // $s0
	// 		long i; // $s1
	// 		long j; // $a0
	/* end block 1 */
	// End offset: 0x80026BC4
	// End Line: 1071

	/* begin block 2 */
		// Start line: 2674
	/* end block 2 */
	// End Line: 2675

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Motion2D_FireRainTaskDisplay(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  TASK *pTVar4;
  TASK *pTVar5;
  TASK *pTVar6;
  int iVar7;
  int iVar8;
  TASK *pTVar9;
  int iVar10;
  TASK *pTVar11;
  
  pTVar4 = TaskCurrent;
  iVar10 = 0;
  pTVar9 = TaskCurrent + 1;
  TaskCurrent->display = Motion2D_FireRainTaskDisplay;
  pTVar11 = pTVar9;
  do {
    cVar1 = *(char *)((int)&pTVar9[0x14].bnext + iVar10);
    if (cVar1 != '\0') {
      iVar7 = 0;
      pTVar6 = pTVar9;
      if (cVar1 == '\x01') {
        iVar8 = 0;
        pTVar6 = pTVar9;
        do {
          pTVar5 = (TASK *)((int)pTVar11[0x13].next - iVar8);
          if ((int)pTVar5 < 0) {
            pTVar5 = (TASK *)0x0;
          }
          *(TASK **)&pTVar6[0x13].event_s6 = pTVar5;
          iVar8 = iVar8 + 0x101010;
          iVar7 = iVar7 + 1;
          pTVar6 = (TASK *)&pTVar6->next;
        } while (iVar7 < 8);
      }
      else {
        do {
          iVar7 = iVar7 + 1;
          *(TASK **)&pTVar6[0x13].event_s6 = pTVar11[0x13].next;
          pTVar6 = (TASK *)&pTVar6->next;
        } while (iVar7 < 8);
      }
      pvVar3 = Main_Prims;
      uVar2 = Main_TextContext.Font.ascii_tab._20_4_;
      *(long **)&pTVar4[2].exec = &pTVar9[4].event_s2 + iVar10 * 0x10;
      Main_Prims = (void *)GtxShp_DisplayListLOFF
                                     (&pTVar4[2].bnext,pvVar3,Scr->ot,(int)Scr_OtSize,0,uVar2);
    }
    iVar10 = iVar10 + 1;
    pTVar11 = (TASK *)&pTVar11->next;
  } while (iVar10 < 0x20);
  return;
}



// decompiled code
// original method signature: 
// struct TASK * /*$ra*/ Motion2D_FireWork(struct _D3_OBJECT *owner /*$s2*/, struct MOTION2D_7fake *pos /*$s0*/, struct MOTION2D_7fake *spd /*$s1*/, long duration /*$s5*/, long n_drops /*stack 16*/, long hp /*stack 20*/)
 // line 1084, offset 0x80026bdc
	/* begin block 1 */
		// Start line: 1085
		// Start offset: 0x80026BDC
		// Variables:
	// 		struct TASK *t; // $v0
	/* end block 1 */
	// End offset: 0x80026BDC
	// End Line: 1085

	/* begin block 2 */
		// Start line: 2778
	/* end block 2 */
	// End Line: 2779

TASK * Motion2D_FireWork(_D3_OBJECT *owner,undefined pos,undefined spd,long duration,long n_drops,
                        long hp)

{
  TASK *pTVar1;
  long lVar2;
  undefined3 in_register_00000015;
  undefined3 in_register_00000019;
  
  pTVar1 = Task_Add(Motion2D_FireWorkTask,0xf78);
  *(_D3_OBJECT **)&pTVar1->s0 = owner;
  pTVar1->s1 = *(long *)CONCAT31(in_register_00000015,pos);
  pTVar1->s2 = ((long *)CONCAT31(in_register_00000015,pos))[1];
  pTVar1->s3 = *(long *)CONCAT31(in_register_00000019,spd);
  lVar2 = ((long *)CONCAT31(in_register_00000019,spd))[1];
  pTVar1->s5 = duration;
  pTVar1->s6 = n_drops;
  pTVar1->s7 = hp;
  pTVar1->s4 = lVar2;
  return pTVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Motion2D_FireWorkTask()
 // line 1109, offset 0x80026c84
	/* begin block 1 */
		// Start line: 1110
		// Start offset: 0x80026C84
		// Variables:
	// 		struct _FIRERAIN *fr; // $s2
	// 		struct MOTION2D_7fake pos; // stack offset -48
	// 		struct MOTION2D_7fake spd; // stack offset -40
	// 		long i; // $s3
	// 		long d; // $s0
	// 		long n; // $s5
	// 		long r; // $s1
	/* end block 1 */
	// End offset: 0x80026F1C
	// End Line: 1177

	/* begin block 2 */
		// Start line: 2855
	/* end block 2 */
	// End Line: 2856

/* WARNING: Removing unreachable block (ram,0x80026e28) */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Motion2D_FireWorkTask(void)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  char cVar4;
  TASK *pTVar5;
  TASK *t;
  short sVar6;
  int iVar7;
  _FIRERAIN *fr;
  int iVar8;
  int iVar9;
  uint uVar10;
  
  pTVar5 = TaskCurrent;
  iVar8 = 0;
  fr = (_FIRERAIN *)(TaskCurrent + 1);
  iVar7 = TaskCurrent->s5;
  iVar9 = TaskCurrent->s6;
  Motion2D_FireRainInit(fr,(_D3_OBJECT *)TaskCurrent->s0,TaskCurrent->s7);
  t = TaskCurrent;
  TaskCurrent->display = Motion2D_FireRainTaskDisplay;
  t->destructor = Motion2D_FireWorkTaskDestructor;
  sVar6 = Fx_Play(0x23,0xd0);
  t = TaskCurrent;
  *(short *)((int)&pTVar5[0x15].s2 + 2) = sVar6;
  Motion2D_FireRainAdd(t,0xd0,0xd8);
  cVar4 = (char)pTVar5;
  if (0 < iVar7) {
    do {
      bVar1 = *(byte *)&pTVar5[0x15].bnext;
      if (bVar1 != 1) goto code_r0x80026d88;
      iVar8 = iVar8 + 1;
      Fx_SetVolume(*(short *)((int)&pTVar5[0x15].s2 + 2),cVar4 + 'D');
      Motion2D_FireRainMove(fr,1);
      Task_Next();
    } while (iVar8 < iVar7);
  }
  bVar1 = *(byte *)&pTVar5[0x15].bnext;
code_r0x80026d88:
  if (1 < bVar1) {
    sVar6 = *(short *)((int)&pTVar5[4].next + 2);
    sVar2 = *(short *)&pTVar5[4].father;
    *(short *)&pTVar5[2].destructor = *(short *)&pTVar5[2].destructor - *(short *)&pTVar5[4].next;
    sVar3 = *(short *)&pTVar5[2].local;
    *(short *)((int)&pTVar5[2].destructor + 2) = *(short *)((int)&pTVar5[2].destructor + 2) - sVar6;
    *(short *)&pTVar5[2].local = sVar3 - sVar2;
  }
  sVar6 = *(short *)((int)&pTVar5[0x15].s2 + 2);
  iVar7 = 0;
  *(undefined *)&pTVar5[0x15].bnext = 0;
  *(undefined2 *)&pTVar5[0x15].s2 = 0;
  Sound_Stop((int)sVar6,0);
  TaskCurrent->destructor = (_func_12 *)0x0;
  Fx_Play(0x35,cVar4 + 'D');
  if (0 < iVar9) {
    do {
      if (iVar9 == 0) {
        trap(0x1c00);
      }
      uVar10 = (0x1000 / iVar9) * iVar7;
      rcos(uVar10);
      M_rand();
      rsin(uVar10);
      M_rand();
      iVar7 = iVar7 + 1;
      M_rand();
      Motion2D_FireRainAdd(TaskCurrent,cVar4 + 'D',0xd8);
    } while (iVar7 < iVar9);
  }
  while (*(short *)&pTVar5[0x15].s2 != 0) {
    Motion2D_FireRainMove(fr,1);
    Task_Next();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Motion2D_FireWorkTaskDestructor(struct TASK *t /*$a0*/)
 // line 1180, offset 0x80026f40
	/* begin block 1 */
		// Start line: 1181
		// Start offset: 0x80026F40
	/* end block 1 */
	// End offset: 0x80026F40
	// End Line: 1181

	/* begin block 2 */
		// Start line: 3073
	/* end block 2 */
	// End Line: 3074

void Motion2D_FireWorkTaskDestructor(TASK *t)

{
  Sound_Stop((int)*(short *)((int)&t[0x15].s2 + 2),0);
  return;
}



// decompiled code
// original method signature: 
// struct TASK * /*$ra*/ Motion2D_FireBall(struct _D3_OBJECT *owner /*$s1*/, struct _D3_OBJECT *target /*$s2*/, struct MOTION2D_7fake *pos /*$s0*/, struct MOTION2D_7fake *rot /*$s3*/, long hp /*stack 16*/)
 // line 1219, offset 0x80026f64
	/* begin block 1 */
		// Start line: 1220
		// Start offset: 0x80026F64
		// Variables:
	// 		struct TASK *t; // $v0
	/* end block 1 */
	// End offset: 0x80026F64
	// End Line: 1220

	/* begin block 2 */
		// Start line: 3151
	/* end block 2 */
	// End Line: 3152

TASK * Motion2D_FireBall(_D3_OBJECT *owner,_D3_OBJECT *target,undefined pos,undefined rot,long hp)

{
  TASK *pTVar1;
  long lVar2;
  undefined3 in_register_00000019;
  undefined3 in_register_0000001d;
  
  pTVar1 = Task_Add(Motion2D_FireBallTask,0x63c);
  *(_D3_OBJECT **)&pTVar1->s0 = owner;
  *(_D3_OBJECT **)&pTVar1->s1 = target;
  pTVar1->s2 = *(long *)CONCAT31(in_register_00000019,pos);
  pTVar1->s3 = ((long *)CONCAT31(in_register_00000019,pos))[1];
  pTVar1->s4 = *(long *)CONCAT31(in_register_0000001d,rot);
  lVar2 = ((long *)CONCAT31(in_register_0000001d,rot))[1];
  pTVar1->s6 = hp;
  pTVar1->s5 = lVar2;
  return pTVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Motion2D_FireBallTask()
 // line 1243, offset 0x80026ffc
	/* begin block 1 */
		// Start line: 1244
		// Start offset: 0x80026FFC
		// Variables:
	// 		long pos[2]; // stack offset -32
	// 		long rot[2]; // stack offset -24
	// 		long i; // $s0
	// 		struct _D3_OBJECT *owner; // $a1
	// 		struct _D3_OBJECT *target; // $a2
	// 		struct _FIREBALL *fb; // $s1
	/* end block 1 */
	// End offset: 0x800270F0
	// End Line: 1278

	/* begin block 2 */
		// Start line: 3209
	/* end block 2 */
	// End Line: 3210

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Motion2D_FireBallTask(void)

{
  TASK *pTVar1;
  short sVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  _FIREBALL *fb;
  
  pTVar1 = TaskCurrent;
  TaskCurrent->display = Motion2D_FireBallTaskDisplay;
  pTVar1->destructor = Motion2D_FireBallTaskDestructor;
  fb = (_FIREBALL *)(pTVar1 + 1);
  Motion2D_FireBallInit(fb,(_D3_OBJECT *)pTVar1->s0,(_D3_OBJECT *)pTVar1->s1,0xe0,0xe8,pTVar1->s6);
  sVar2 = Fx_Play(0x23,(char)pTVar1 + -0x44);
  iVar4 = (int)Scr_TicksPerSecond;
  *(short *)&pTVar1[6].event_ra = sVar2;
  iVar5 = 0;
  if (0 < iVar4 * 10) {
    do {
      lVar3 = Motion2D_FireBallMove(fb);
      if (lVar3 != 0) {
        Motion2D_FireBallImpact(fb);
        return;
      }
      iVar5 = iVar5 + 1;
      Task_Next();
    } while (iVar5 < (int)Scr_TicksPerSecond * 10);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Motion2D_FireBallTaskDisplay()
 // line 1281, offset 0x80027104
	/* begin block 1 */
		// Start line: 1282
		// Start offset: 0x80027104
	/* end block 1 */
	// End offset: 0x80027104
	// End Line: 1282

	/* begin block 2 */
		// Start line: 3330
	/* end block 2 */
	// End Line: 3331

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Motion2D_FireBallTaskDisplay(void)

{
  Main_Prims = (void *)GtxShp_DisplayListLOFF
                                 (&TaskCurrent[6].event_msg,Main_Prims,Scr->ot,(int)Scr_OtSize,0,
                                  Main_TextContext.Font.ascii_tab._20_4_);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Motion2D_FireBallTaskDestructor(struct TASK *t /*$a0*/)
 // line 1292, offset 0x8002715c
	/* begin block 1 */
		// Start line: 1293
		// Start offset: 0x8002715C
	/* end block 1 */
	// End offset: 0x8002717C
	// End Line: 1300

	/* begin block 2 */
		// Start line: 3362
	/* end block 2 */
	// End Line: 3363

void Motion2D_FireBallTaskDestructor(TASK *t)

{
  if (-1 < (int)*(short *)&t[6].event_ra) {
    Sound_Stop((int)*(short *)&t[6].event_ra,0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Motion2D_FireBallInit(struct _FIREBALL *fb /*$s0*/, struct _D3_OBJECT *owner /*$s2*/, struct _D3_OBJECT *target /*$s3*/, struct MOTION2D_7fake *pos /*$a3*/, struct MOTION2D_7fake *rot /*stack 16*/, long hp /*stack 20*/)
 // line 1303, offset 0x8002718c
	/* begin block 1 */
		// Start line: 1304
		// Start offset: 0x8002718C
		// Variables:
	// 		long i; // $a1
	/* end block 1 */
	// End offset: 0x80027294
	// End Line: 1332

	/* begin block 2 */
		// Start line: 3384
	/* end block 2 */
	// End Line: 3385

void Motion2D_FireBallInit
               (_FIREBALL *fb,_D3_OBJECT *owner,_D3_OBJECT *target,undefined pos,undefined1 rot,
               long hp)

{
  void *pvVar1;
  _struct_243 *p_Var2;
  int iVar3;
  undefined3 in_register_0000001d;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  puVar4 = (undefined4 *)CONCAT31(in_register_0000001d,pos);
  uVar5 = puVar4[1];
  *(undefined4 *)&(fb->obj).pos = *puVar4;
  *(undefined4 *)&(fb->obj).pos.vz = uVar5;
  uVar5 = puVar4[1];
  *(undefined4 *)&(fb->obj).last_pos = *puVar4;
  *(undefined4 *)&(fb->obj).last_pos.vz = uVar5;
  uVar5 = _rot[1];
  *(undefined4 *)&(fb->obj).rot = *_rot;
  *(undefined4 *)&(fb->obj).rot.vz = uVar5;
  D3_SetBox((_D3_OBJECT *)fb,-0x19,-0x19,-0x19,0x19,0x19,0x19);
  iVar3 = 0xf;
  p_Var2 = &(fb->obj).rot;
  (fb->obj).collision_mode = 0x2002;
  *(undefined *)((int)&fb->snd + 1) = 0xf0;
  *(_D3_OBJECT **)&fb[5].obj.hit_points = (_D3_OBJECT *)&fb[1].obj.father;
  (fb->obj).hit_power = (uchar)hp;
  pvVar1 = Pl_Pcl;
  (fb->obj).collision_state = 0;
  fb[1].obj.prec = owner;
  fb[1].obj.child = target;
  fb[5].obj.description = (void *)0x0;
  *(short **)&fb[5].obj.description = &fb[4].obj.last_pos.vz;
  *(undefined2 *)&fb[5].obj.color = 0;
  *(void **)&fb[5].obj.collision_mode = pvVar1;
  do {
    *(undefined4 *)(p_Var2 + 0x55) = 0;
    iVar3 = iVar3 + -1;
    p_Var2 = (_struct_243 *)&p_Var2[-1].vz;
  } while (-1 < iVar3);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Motion2D_FireBallMove(struct _FIREBALL *fb /*$s0*/)
 // line 1335, offset 0x800272b0
	/* begin block 1 */
		// Start line: 1336
		// Start offset: 0x800272B0
		// Variables:
	// 		struct MOTION2D_7fake c; // stack offset -24
	// 		long dz; // $s1
	// 		long i; // $a2
	/* end block 1 */
	// End offset: 0x800273E4
	// End Line: 1375

	/* begin block 2 */
		// Start line: 3514
	/* end block 2 */
	// End Line: 3515

long Motion2D_FireBallMove(_FIREBALL *fb)

{
  short sVar1;
  int iVar2;
  long lVar3;
  undefined uVar4;
  int iVar5;
  _FIREBALL *p_Var6;
  int iVar7;
  short local_18;
  short local_16;
  short local_14;
  
  Boxes_GetCenter(fb[1].obj.child,0xe8);
  iVar7 = (int)local_14 - (int)(fb->obj).pos.vz;
  D3_GoToDir((_D3_OBJECT *)fb,(int)local_18 - (int)(fb->obj).pos.vx,
             (int)local_16 - (int)(fb->obj).pos.vy,0x80);
  iVar2 = rcos((int)(fb->obj).rot.vz);
  sVar1 = (fb->obj).rot.vz;
  (fb->obj).pos.vx = (fb->obj).pos.vx + (short)(iVar2 * 0x21 >> 0xc);
  iVar2 = rsin((int)sVar1);
  (fb->obj).pos.vy = (fb->obj).pos.vy + (short)(iVar2 * 0x21 >> 0xc);
  if (iVar7 < 0x22) {
    if (-0x22 < iVar7) goto LAB_8002737c;
    sVar1 = (fb->obj).pos.vz + -0x21;
  }
  else {
    sVar1 = (fb->obj).pos.vz + 0x21;
  }
  (fb->obj).pos.vz = sVar1;
LAB_8002737c:
  Motion2D_FireBallCompute(fb,0);
  if (*(short *)&fb[5].obj.color < 0x10) {
    *(short *)&fb[5].obj.color = *(short *)&fb[5].obj.color + 1;
  }
  iVar7 = 0;
  iVar2 = 0x80;
  p_Var6 = fb;
  do {
    iVar5 = (uint)*(byte *)&p_Var6[4].obj.last_pos.vz + 0x10;
    uVar4 = (char)iVar5;
    if (iVar2 < iVar5) {
      uVar4 = (char)iVar2;
    }
    iVar2 = iVar2 + -4;
    *(undefined *)&p_Var6[4].obj.last_pos.vz = uVar4;
    *(undefined *)&p_Var6[4].obj.last_pos.pad = uVar4;
    *(undefined *)((int)&p_Var6[4].obj.last_pos.vz + 1) = uVar4;
    iVar7 = iVar7 + 1;
    p_Var6 = (_FIREBALL *)&(p_Var6->obj).prec;
  } while (iVar7 < 0x10);
  Fx_SetVolume(fb[5].obj.pos.vx,(char)fb + ',');
  lVar3 = Boxes_TestObject((_D3_OBJECT *)fb);
  return (uint)(lVar3 != 0);
}



// decompiled code
// original method signature: 
// void /*$ra*/ Motion2D_FireBallCompute(struct _FIREBALL *fb /*$s3*/, long base /*$s2*/)
 // line 1385, offset 0x80027410
	/* begin block 1 */
		// Start line: 1386
		// Start offset: 0x80027410
		// Variables:
	// 		long i; // $s1
	/* end block 1 */
	// End offset: 0x800274B4
	// End Line: 1397

	/* begin block 2 */
		// Start line: 3631
	/* end block 2 */
	// End Line: 3632

void Motion2D_FireBallCompute(_FIREBALL *fb,long base)

{
  short sVar1;
  _D3_OBJECT **pp_Var2;
  long lVar3;
  _D3_OBJECT *p_Var4;
  _D3_OBJECT **pp_Var5;
  int iVar6;
  
  iVar6 = base + 0xf;
  if (base < iVar6) {
    do {
      pp_Var5 = &(fb->obj).next + (iVar6 + base) * 2;
      pp_Var2 = &(fb->obj).next + (iVar6 + base + -1) * 2;
      p_Var4 = pp_Var2[0x2b];
      pp_Var5[0x2a] = pp_Var2[0x2a];
      pp_Var5[0x2b] = p_Var4;
      lVar3 = M_rand();
      sVar1 = (short)iVar6;
      iVar6 = iVar6 + -1;
      *(ushort *)((int)pp_Var5 + 0xae) =
           (((ushort)lVar3 & 3) + 0x29) * 0x100 | ((0x10 - (short)base) - sVar1) * 4;
    } while (base < iVar6);
  }
  pp_Var2 = &(fb->obj).next + base * 2;
  p_Var4 = *(_D3_OBJECT **)&(fb->obj).pos.vz;
  pp_Var2[0x2a] = *(_D3_OBJECT **)&(fb->obj).pos;
  pp_Var2[0x2b] = p_Var4;
  *(undefined2 *)((int)pp_Var2 + 0xae) = 0x2919;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Motion2D_FireBallImpact(struct _FIREBALL *fb /*$s4*/)
 // line 1402, offset 0x80027504
	/* begin block 1 */
		// Start line: 1403
		// Start offset: 0x80027504
		// Variables:
	// 		long r; // $s0
	// 		long i; // $s1
	// 		long j; // $s3
	// 		struct MOTION2D_7fake pos; // stack offset -40
	/* end block 1 */
	// End offset: 0x80027808
	// End Line: 1484

	/* begin block 2 */
		// Start line: 3676
	/* end block 2 */
	// End Line: 3677

void Motion2D_FireBallImpact(_FIREBALL *fb)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  undefined uVar5;
  int iVar6;
  uint uVar7;
  long lVar8;
  int iVar9;
  _D3_OBJECT *ot;
  _D3_OBJECT **pp_Var10;
  _FIREBALL *p_Var11;
  _D3_OBJECT *p_Var12;
  int iVar13;
  _FIREBALL *p_Var14;
  int iVar15;
  ushort uVar16;
  _D3_OBJECT *local_28;
  _D3_OBJECT *local_24;
  
  iVar15 = 0;
  if (0 < *(short *)&fb[5].obj.color) {
    iVar13 = 0x40;
    iVar9 = 0x80;
    p_Var11 = fb;
    p_Var14 = fb;
    do {
      iVar6 = (int)&(fb->obj).next + iVar9;
      ot = (_D3_OBJECT *)p_Var11[1].obj.list;
      *(_D3_OBJECT **)(iVar6 + 0xa8) = p_Var11[1].obj.father;
      *(_D3_OBJECT **)(iVar6 + 0xac) = ot;
      *(undefined4 *)((int)&fb[4].obj.last_pos.vz + iVar13) =
           *(undefined4 *)&p_Var14[4].obj.last_pos.vz;
      p_Var14 = (_FIREBALL *)&(p_Var14->obj).prec;
      iVar13 = iVar13 + 4;
      p_Var11 = (_FIREBALL *)&(p_Var11->obj).child;
      iVar15 = iVar15 + 1;
      iVar9 = iVar9 + 8;
    } while (iVar15 < (int)*(short *)&fb[5].obj.color);
  }
  p_Var12 = fb[1].obj.child;
  ot = *(_D3_OBJECT **)&(fb->list).pos.vz;
  *(short *)&fb[5].obj.color = *(short *)&fb[5].obj.color + 0x10;
  if (p_Var12 != ot) {
    fb[1].obj.child = (_D3_OBJECT *)0x0;
    local_28 = *(_D3_OBJECT **)&(fb->obj).pos;
    local_24 = *(_D3_OBJECT **)&(fb->obj).pos.vz;
  }
  iVar15 = 1;
  Sound_Stop((int)fb[5].obj.pos.vx,0);
  fb[5].obj.pos.vx = -1;
  Fx_Play(0x35,(char)fb + ',');
  pp_Var10 = &(fb->obj).child;
  do {
    ot = (_D3_OBJECT *)fb[1].obj.list;
    pp_Var10[0x2a] = fb[1].obj.father;
    pp_Var10[0x2b] = ot;
    iVar15 = iVar15 + 1;
    pp_Var10 = pp_Var10 + 2;
  } while (iVar15 < 0x10);
  iVar15 = 0;
  p_Var11 = fb;
  do {
    iVar15 = iVar15 + 1;
    uVar7 = M_rand();
    iVar9 = rcos(uVar7 & 0xfff);
    p_Var11[2].poses.vx = (short)(iVar9 * 5 >> 0xc);
    iVar9 = rsin(uVar7 & 0xfff);
    p_Var11[2].poses.vy = (short)(iVar9 * 5 >> 0xc);
    p_Var11[2].poses.vz = 0;
    p_Var11 = (_FIREBALL *)&(p_Var11->obj).child;
  } while (iVar15 < 0x10);
  iVar15 = 1;
  pp_Var10 = &(fb->obj).prec;
  do {
    pp_Var10[0xaa] = (_D3_OBJECT *)0x808080;
    iVar15 = iVar15 + 1;
    pp_Var10 = pp_Var10 + 1;
  } while (iVar15 < 0x10);
  iVar15 = 0;
  uVar16 = 1;
  do {
    ot = fb[1].obj.child;
    if (ot != (_D3_OBJECT *)0x0) {
      Boxes_GetCenter(ot,0xd8);
    }
    Motion2D_FireBallCompute(fb,0x10);
    iVar9 = (int)*(short *)&fb[5].obj.color + -1;
    if (0x10 < iVar9) {
      pp_Var10 = &(fb->obj).next + iVar9;
      do {
        uVar5 = (undefined)((uint)*(byte *)(pp_Var10 + 0xaa) - 8);
        if ((int)((uint)*(byte *)(pp_Var10 + 0xaa) - 8) < 0) {
          uVar5 = 0;
        }
        *(undefined *)(pp_Var10 + 0xaa) = uVar5;
        *(undefined *)((int)pp_Var10 + 0x2aa) = uVar5;
        *(undefined *)((int)pp_Var10 + 0x2a9) = uVar5;
        iVar9 = iVar9 + -1;
        pp_Var10 = pp_Var10 + 0x18;
      } while (0x10 < iVar9);
    }
    iVar9 = 0;
    p_Var11 = fb;
    p_Var14 = fb;
    do {
      p_Var11[1].obj.father = local_28;
      *(_D3_OBJECT **)&p_Var11[1].obj.list = local_24;
      sVar4 = (short)iVar15;
      sVar1 = p_Var11[2].poses.vy;
      sVar2 = p_Var11[2].poses.vz;
      *(short *)&p_Var11[1].obj.father =
           *(short *)&p_Var11[1].obj.father + p_Var11[2].poses.vx * sVar4;
      sVar3 = *(short *)&p_Var11[1].obj.list;
      *(short *)((int)&p_Var11[1].obj.father + 2) =
           *(short *)((int)&p_Var11[1].obj.father + 2) + sVar1 * sVar4;
      *(short *)&p_Var11[1].obj.list = sVar3 + sVar2 * sVar4;
      iVar9 = iVar9 + 1;
      *(int *)&p_Var14[4].obj.last_pos.vz = *(int *)&p_Var14[4].obj.last_pos.vz + -0x80808;
      lVar8 = M_rand();
      p_Var14 = (_FIREBALL *)&(p_Var14->obj).prec;
      *(ushort *)((int)&p_Var11[1].obj.list + 2) = (((ushort)lVar8 & 3) + 0x29) * 0x100 | uVar16;
      p_Var11 = (_FIREBALL *)&(p_Var11->obj).child;
    } while (iVar9 < 0x10);
    uVar16 = uVar16 + 4;
    Task_Next();
    iVar15 = iVar15 + 1;
  } while (iVar15 < 0x10);
  return;
}



// decompiled code
// original method signature: 
// struct TASK * /*$ra*/ Motion2D_Flame(struct _D3_OBJECT *obj /*$fp*/, struct MOTION2D_7fake *pos /*$s3*/, struct MOTION2D_7fake *rot /*$s4*/, long growth /*$s5*/, long max /*stack 16*/, long power /*stack 20*/, long mode /*stack 24*/)
 // line 1536, offset 0x80027830
	/* begin block 1 */
		// Start line: 1537
		// Start offset: 0x80027830
		// Variables:
	// 		struct TASK *t; // $s1
	// 		struct _FLAME *f; // $s0
	/* end block 1 */
	// End offset: 0x80027830
	// End Line: 1537

	/* begin block 2 */
		// Start line: 4047
	/* end block 2 */
	// End Line: 4048

TASK * Motion2D_Flame(_D3_OBJECT *obj,undefined pos,undefined rot,long growth,long max,long power,
                     long mode)

{
  undefined uVar1;
  char cVar2;
  TASK *pTVar3;
  undefined3 in_register_00000015;
  TASK **ppTVar4;
  undefined3 in_register_00000019;
  TASK *pTVar5;
  long lVar6;
  
  ppTVar4 = (TASK **)CONCAT31(in_register_00000015,pos);
  pTVar3 = Task_Add(Motion2D_FlameTask,0x6fc);
  cVar2 = (char)pTVar3;
  pTVar5 = ppTVar4[1];
  pTVar3[2].bnext = *ppTVar4;
  *(TASK **)&pTVar3[2].exec = pTVar5;
  pTVar5 = ppTVar4[1];
  *(TASK **)&pTVar3[1].s0 = *ppTVar4;
  *(TASK **)&pTVar3[1].s1 = pTVar5;
  lVar6 = ((long *)CONCAT31(in_register_00000019,rot))[1];
  pTVar3[1].s4 = *(long *)CONCAT31(in_register_00000019,rot);
  pTVar3[1].s5 = lVar6;
  pTVar3[7].event_s7 = growth;
  pTVar3[8].next = (TASK *)0x0;
  pTVar3[7].event_fp = max;
  *(long *)&pTVar3[8].father = mode;
  uVar1 = *(undefined *)&Motion2D_FlameDesc[mode].shot;
  *(_D3_OBJECT **)&pTVar3[2].bprec = obj;
  *(undefined *)((int)&pTVar3[2].father + 1) = uVar1;
  pTVar5 = (TASK *)Motion2D_FlameInit((_D3_OBJECT *)(pTVar3 + 1),cVar2 + '<',cVar2 + 'L',
                                      cVar2 + -0x2c,power,max,mode);
  pTVar3[8].prec = pTVar5;
  pTVar3->destructor = Motion2D_FlameDestructor;
  *(TASK **)&pTVar3->local = pTVar3 + 1;
  pTVar3->display = Motion2D_FlameTaskDisplay;
  return pTVar3;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Motion2D_FlameModify(struct TASK *t /*$a0*/, struct MOTION2D_7fake *pos /*$a1*/, struct MOTION2D_7fake *rot /*$a2*/)
 // line 1565, offset 0x80027998
	/* begin block 1 */
		// Start line: 1567
		// Start offset: 0x80027998
		// Variables:
	// 		struct _FLAME *f; // $v1
	/* end block 1 */
	// End offset: 0x800279EC
	// End Line: 1580

	/* begin block 2 */
		// Start line: 4147
	/* end block 2 */
	// End Line: 4148

void Motion2D_FlameModify(TASK *t,undefined pos,undefined rot)

{
  void *pvVar1;
  undefined3 in_register_00000015;
  undefined4 *puVar2;
  undefined3 in_register_00000019;
  undefined4 uVar3;
  
  puVar2 = (undefined4 *)CONCAT31(in_register_00000015,pos);
  pvVar1 = t->local;
  if (puVar2 != (undefined4 *)0x0) {
    uVar3 = puVar2[1];
    *(undefined4 *)((int)pvVar1 + 0xa4) = *puVar2;
    *(undefined4 *)((int)pvVar1 + 0xa8) = uVar3;
    uVar3 = ((undefined4 *)CONCAT31(in_register_00000019,rot))[1];
    *(undefined4 *)((int)pvVar1 + 0x3c) = *(undefined4 *)CONCAT31(in_register_00000019,rot);
    *(undefined4 *)((int)pvVar1 + 0x40) = uVar3;
    return;
  }
  *(undefined4 *)((int)pvVar1 + 0x3f4) = 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Motion2D_FlameTask()
 // line 1583, offset 0x800279f4
	/* begin block 1 */
		// Start line: 1584
		// Start offset: 0x800279F4
		// Variables:
	// 		struct _FLAME *f; // $s0
	/* end block 1 */
	// End offset: 0x80027A80
	// End Line: 1602

	/* begin block 2 */
		// Start line: 4183
	/* end block 2 */
	// End Line: 4184

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Motion2D_FlameTask(void)

{
  long lVar1;
  _D3_OBJECT *obj;
  
  obj = (_D3_OBJECT *)TaskCurrent->local;
  while( true ) {
    lVar1 = Motion2D_FlameCompute
                      (obj,(char)obj + -0x54,(char)obj + '\x04',*(long *)&obj[9].collision_mode,
                       *(long *)&obj[9].hit_points,obj[9].color,*(long *)&obj[9].pos);
    if (lVar1 != 0) break;
    (obj[1].matrices)->m[0] = obj[1].last_pos.vz;
    (obj[1].matrices)->m[1] = obj[1].last_pos.pad;
    (obj[1].matrices)->m[2] = obj[1].rot.vx;
    Task_Next();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Motion2D_FlameTaskDisplay()
 // line 1605, offset 0x80027a90
	/* begin block 1 */
		// Start line: 1606
		// Start offset: 0x80027A90
		// Variables:
	// 		struct _FLAME *f; // $a0
	/* end block 1 */
	// End offset: 0x80027A90
	// End Line: 1606

	/* begin block 2 */
		// Start line: 4241
	/* end block 2 */
	// End Line: 4242

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Motion2D_FlameTaskDisplay(void)

{
  Motion2D_FlameDisplay((char)TaskCurrent->local + -0x54);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Motion2D_FlameDestructor(struct TASK *t /*$a0*/)
 // line 1617, offset 0x80027abc
	/* begin block 1 */
		// Start line: 1618
		// Start offset: 0x80027ABC
		// Variables:
	// 		struct _FLAME *f; // $v0
	/* end block 1 */
	// End offset: 0x80027ABC
	// End Line: 1618

	/* begin block 2 */
		// Start line: 4265
	/* end block 2 */
	// End Line: 4266

void Motion2D_FlameDestructor(TASK *t)

{
  Sound_Stop(*(int *)((int)t->local + 0x3f0),0);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Motion2D_FlameInit(struct _D3_OBJECT *obj /*$s2*/, struct MOTION2D_71fake *list /*$s1*/, struct MOTION2D_7fake *poses /*$s6*/, struct MOTION2D_8fake *colors /*$s5*/, long power /*stack 16*/, long max /*stack 20*/, long mode /*stack 24*/)
 // line 1626, offset 0x80027ae8
	/* begin block 1 */
		// Start line: 1627
		// Start offset: 0x80027AE8
		// Variables:
	// 		struct _FLAME_DESC *desc; // $s3
	// 		long i; // $a0
	// 		long snd; // $v0
	/* end block 1 */
	// End offset: 0x80027C60
	// End Line: 1668

	/* begin block 2 */
		// Start line: 4283
	/* end block 2 */
	// End Line: 4284

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long Motion2D_FlameInit(_D3_OBJECT *obj,undefined list,undefined poses,undefined colors,long power,
                       long max,long mode)

{
  void *pvVar1;
  short sVar2;
  void *pvVar3;
  int iVar4;
  char pos;
  undefined3 in_register_00000015;
  void **ppvVar5;
  undefined3 in_register_00000019;
  undefined4 *puVar6;
  undefined3 in_register_0000001d;
  undefined4 *puVar7;
  undefined4 uVar8;
  
  puVar7 = (undefined4 *)CONCAT31(in_register_0000001d,colors);
  puVar6 = (undefined4 *)CONCAT31(in_register_00000019,poses);
  ppvVar5 = (void **)CONCAT31(in_register_00000015,list);
  D3_SetBox(obj,-0x21,-0x21,-0x21,0x21,0x21,0x21);
  obj->child = (_D3_OBJECT *)0x0;
  obj->collision_mode = 0x2002;
  obj->hit_power = (uchar)power;
  obj[1].pos.vy = 0;
  pvVar3 = Effects_Pcl;
  pvVar1 = Pl_Pcl;
  if (Motion2D_FlameDesc[mode].pcl_file == '\0') {
    ppvVar5[2] = (void *)0x0;
  }
  else {
    ppvVar5[2] = (void *)0x0;
    pvVar3 = pvVar1;
  }
  *ppvVar5 = pvVar3;
  *(undefined4 **)(ppvVar5 + 1) = puVar6;
  *(undefined4 **)(ppvVar5 + 2) = puVar7;
  *(undefined2 *)(ppvVar5 + 3) = 1;
  uVar8 = *(undefined4 *)&(obj->pos).vz;
  *puVar6 = *(undefined4 *)&obj->pos;
  puVar6[1] = uVar8;
  *(ushort *)((int)ppvVar5[1] + 6) = Motion2D_FlameDesc[mode].shp1 << 8 | 0xc;
  iVar4 = 0;
  if (0 < max + 1) {
    do {
      *puVar7 = 0x808080;
      iVar4 = iVar4 + 1;
      puVar7 = puVar7 + 1;
    } while (iVar4 < max + 1);
  }
  if (mode == 1) {
    sVar2 = D3_PlaySound(_DAT_800b1d3c,6);
  }
  else {
    pos = (char)obj + ',';
    Fx_Play(0x22,pos);
    sVar2 = Fx_Play(0x23,pos);
  }
  return (int)sVar2;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Motion2D_FlameCompute(struct _D3_OBJECT *obj /*$s3*/, struct MOTION2D_71fake *list /*$s2*/, struct MOTION2D_7fake *spd /*$s4*/, long growth /*$a3*/, long max /*stack 16*/, long disappear /*stack 20*/, long mode /*stack 24*/)
 // line 1671, offset 0x80027c88
	/* begin block 1 */
		// Start line: 1672
		// Start offset: 0x80027C88
		// Variables:
	// 		struct _FLAME_DESC *desc; // $s0
	// 		struct MOTION2D_7fake *pos; // $a0
	// 		long i; // $s1
	// 		long j; // $s0

		/* begin block 1.1 */
			// Start line: 1747
			// Start offset: 0x80028020
		/* end block 1.1 */
		// End offset: 0x800280F0
		// End Line: 1774
	/* end block 1 */
	// End offset: 0x80028200
	// End Line: 1798

	/* begin block 2 */
		// Start line: 4393
	/* end block 2 */
	// End Line: 4394

long Motion2D_FlameCompute
               (_D3_OBJECT *obj,undefined list,undefined spd,long growth,long max,long disappear,
               long mode)

{
  bool bVar1;
  ushort uVar2;
  undefined4 *puVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  short *psVar8;
  short *psVar9;
  short sVar10;
  undefined3 in_register_00000015;
  int iVar11;
  undefined3 in_register_00000019;
  short *psVar12;
  int iVar13;
  undefined4 uVar14;
  int iVar15;
  long lVar16;
  
  psVar12 = (short *)CONCAT31(in_register_00000019,spd);
  iVar11 = CONCAT31(in_register_00000015,list);
  if (mode == 0) {
    *(short *)(*(int *)(iVar11 + 4) + 6) = *(short *)(*(int *)(iVar11 + 4) + 6) + 0x100;
    iVar7 = *(int *)(iVar11 + 4);
    if ((int)Motion2D_FlameDesc[0].shp2 << 8 < (int)((int)*(short *)(iVar7 + 6) & 0xff00U)) {
      *(short *)(iVar7 + 6) = *(short *)(iVar7 + 6) + -0x400;
    }
  }
  iVar7 = 0;
  if (0 < (int)*(short *)(iVar11 + 0xc) + -1) {
    iVar13 = 8;
    psVar9 = psVar12;
    do {
      psVar8 = (short *)(*(int *)(iVar11 + 4) + iVar13);
      *psVar8 = *psVar8 + *psVar9;
      psVar8[1] = psVar8[1] + psVar9[1];
      psVar8[2] = psVar8[2] + psVar9[2];
      if (Motion2D_FlameDesc[mode].gravity != '\0') {
        psVar9[2] = psVar9[2] + -5;
      }
      uVar2 = psVar8[3];
      sVar10 = (short)((uint)uVar2 + growth);
      psVar8[3] = sVar10;
      if (mode == 0) {
        uVar4 = (uint)uVar2 + growth + 0x100;
        psVar8[3] = (short)uVar4;
        if ((int)Motion2D_FlameDesc[0].shp3 << 8 < (int)(uVar4 & 0xff00)) {
          psVar8[3] = sVar10 + -0x300;
        }
      }
      psVar9 = psVar9 + 4;
      iVar7 = iVar7 + 1;
      iVar13 = iVar13 + 8;
    } while (iVar7 < (int)*(short *)(iVar11 + 0xc) + -1);
  }
  if (disappear == 0) {
    lVar16 = max;
    if ((int)*(short *)(iVar11 + 0xc) < max) {
      lVar16 = (int)*(short *)(iVar11 + 0xc);
    }
    if (1 < lVar16) {
      psVar9 = psVar12 + lVar16 * 4;
      do {
        iVar7 = lVar16 * 8;
        lVar16 = lVar16 + -1;
        puVar3 = (undefined4 *)(iVar7 + *(int *)(iVar11 + 4));
        *puVar3 = puVar3[-2];
        puVar3[1] = puVar3[-1];
        *(undefined4 *)(psVar9 + -4) = *(undefined4 *)(psVar9 + -8);
        *(undefined4 *)(psVar9 + -2) = *(undefined4 *)(psVar9 + -6);
        psVar9 = psVar9 + -4;
      } while (1 < lVar16);
    }
    uVar4 = M_rand();
    iVar7 = rcos(((int)(obj->rot).vz + (uVar4 & 0xf)) - 8);
    *psVar12 = (short)(iVar7 * 5 >> 9);
    uVar4 = M_rand();
    iVar7 = rsin(((int)(obj->rot).vz + (uVar4 & 0xf)) - 8);
    psVar12[1] = (short)(iVar7 * 5 >> 9);
    uVar4 = M_rand();
    iVar7 = rsin(((int)(obj->rot).vx + (uVar4 & 0xf)) - 8);
    psVar12[2] = (short)(iVar7 * 5 >> 9);
    puVar3 = *(undefined4 **)(iVar11 + 4);
    puVar3[2] = *puVar3;
    puVar3[3] = puVar3[1];
    *(ushort *)(*(int *)(iVar11 + 4) + 0xe) = Motion2D_FlameDesc[mode].shp4 << 8 | 10;
    if ((int)*(short *)(iVar11 + 0xc) <= max) {
      *(short *)(iVar11 + 0xc) = *(short *)(iVar11 + 0xc) + 1;
    }
  }
  else {
    if (**(char **)(iVar11 + 8) == '\0') {
      return 1;
    }
    iVar7 = 0;
    if (0 < *(short *)(iVar11 + 0xc)) {
      do {
        lVar16 = M_rand();
        iVar13 = iVar7 * 8 + *(int *)(iVar11 + 4);
        *(short *)(iVar13 + 4) = *(short *)(iVar13 + 4) + ((ushort)lVar16 & 3);
        iVar6 = iVar7 * 4;
        pcVar5 = (char *)(iVar6 + *(int *)(iVar11 + 8));
        *pcVar5 = *pcVar5 + -0x10;
        iVar13 = iVar6 + *(int *)(iVar11 + 8);
        *(char *)(iVar13 + 1) = *(char *)(iVar13 + 1) + -0x10;
        iVar6 = iVar6 + *(int *)(iVar11 + 8);
        *(char *)(iVar6 + 2) = *(char *)(iVar6 + 2) + -0x10;
        iVar7 = iVar7 + 1;
      } while (iVar7 < (int)*(short *)(iVar11 + 0xc));
    }
  }
  obj[1].pos.vy = obj[1].pos.vy + 1U & 3;
  if (mode == 0) {
    D3_SetBox(obj,-0x10,-0x10,-0x10,0x10,0x10,0x10);
    D3_ClearCollBits(obj,0x2000);
    Boxes_GetCenter(*(_D3_OBJECT **)&obj[1].last_pos,(char)obj + '4');
    uVar14 = (*(undefined4 **)(iVar11 + 4))[1];
    *(undefined4 *)&obj->pos = **(undefined4 **)(iVar11 + 4);
    *(undefined4 *)&(obj->pos).vz = uVar14;
    lVar16 = Boxes_TestObject(obj);
    D3_SetCollBits(obj,0x2000);
    D3_SetBox(obj,-0x21,-0x21,-0x21,0x21,0x21,0x21);
    if (lVar16 != 0) {
      bVar1 = Scr_Frame == 0;
      *(undefined2 *)(iVar11 + 0xc) = 1;
      if (bVar1) {
        return 0;
      }
      Impact_Smoke((char)*(undefined4 *)(iVar11 + 4),1);
      return 0;
    }
  }
  iVar7 = 1;
  sVar10 = *(short *)(iVar11 + 0xc);
  if (1 < *(short *)(iVar11 + 0xc)) {
    do {
      iVar15 = iVar7 + (int)obj[1].pos.vy;
      iVar6 = (int)sVar10 + -1;
      iVar13 = iVar15;
      if (iVar6 <= iVar15) {
        iVar13 = iVar15 % iVar6;
        if (iVar6 == 0) {
          trap(0x1c00);
        }
        if ((iVar6 == -1) && (iVar15 == -0x80000000)) {
          trap(0x1800);
        }
      }
      puVar3 = (undefined4 *)(iVar13 * 8 + *(int *)(iVar11 + 4));
      uVar14 = puVar3[1];
      *(undefined4 *)&obj->last_pos = *puVar3;
      *(undefined4 *)&(obj->last_pos).vz = uVar14;
      iVar6 = iVar13 * 8 + *(int *)(iVar11 + 4);
      uVar14 = *(undefined4 *)(iVar6 + 0xc);
      *(undefined4 *)&obj->pos = *(undefined4 *)(iVar6 + 8);
      *(undefined4 *)&(obj->pos).vz = uVar14;
      lVar16 = Boxes_TestObject(obj);
      if ((lVar16 != 0) || ((obj->collision_state & 0x20U) != 0)) {
        *(short *)(iVar11 + 0xc) = (short)iVar13 + 1;
        Impact_Smoke((char)obj + ',',1);
      }
      iVar7 = iVar7 + 4;
      sVar10 = *(short *)(iVar11 + 0xc);
    } while (iVar7 < (int)*(short *)(iVar11 + 0xc));
  }
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Motion2D_FlameDisplay(struct MOTION2D_71fake *list /*$a0*/)
 // line 1801, offset 0x80028228
	/* begin block 1 */
		// Start line: 4700
	/* end block 1 */
	// End Line: 4701

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Motion2D_FlameDisplay(undefined list)

{
  Main_Prims = (void *)GtxShp_DisplayListLOFF
                                 (list,Main_Prims,Scr->ot,(int)Scr_OtSize,0,
                                  Main_TextContext.Font.ascii_tab._20_4_);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Motion2D_Lightning(struct MOTION2D_7fake *s /*$s0*/, struct MOTION2D_7fake *d /*$s1*/, long r /*$s2*/, long n /*$s3*/)
 // line 1828, offset 0x80028278
	/* begin block 1 */
		// Start line: 1829
		// Start offset: 0x80028278
		// Variables:
	// 		struct TASK *t; // $v0
	// 		struct _LIGHTNING *l; // $v0
	/* end block 1 */
	// End offset: 0x80028278
	// End Line: 1829

	/* begin block 2 */
		// Start line: 4755
	/* end block 2 */
	// End Line: 4756

void Motion2D_Lightning(undefined s,undefined d,long r,long n)

{
  TASK *pTVar1;
  undefined3 in_register_00000011;
  undefined3 in_register_00000015;
  TEXTCONTEXT *pTVar2;
  long lVar3;
  
  pTVar1 = Task_Link(Motion2D_LightningTask,0x300);
  pTVar2 = ((TEXTCONTEXT **)CONCAT31(in_register_00000011,s))[1];
  pTVar1[1].text_context = *(TEXTCONTEXT **)CONCAT31(in_register_00000011,s);
  *(TEXTCONTEXT **)&pTVar1[1].enable = pTVar2;
  lVar3 = ((long *)CONCAT31(in_register_00000015,d))[1];
  pTVar1[1].event_msg = *(long *)CONCAT31(in_register_00000015,d);
  pTVar1[1].event_param = lVar3;
  *(long *)&pTVar1[1].event_exec = r;
  pTVar1[1].event_ra = n;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Motion2D_LightningTask()
 // line 1843, offset 0x80028318
	/* begin block 1 */
		// Start line: 1844
		// Start offset: 0x80028318
		// Variables:
	// 		struct _LIGHTNING *l; // $s0
	// 		long i; // $s1
	/* end block 1 */
	// End offset: 0x800283B4
	// End Line: 1867

	/* begin block 2 */
		// Start line: 4792
	/* end block 2 */
	// End Line: 4793

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Motion2D_LightningTask(void)

{
  TASK *pTVar1;
  TASK *pTVar2;
  int iVar3;
  
  pTVar1 = TaskCurrent;
  iVar3 = 0;
  pTVar2 = TaskCurrent + 1;
  TaskCurrent->display = Motion2D_LightningTaskDisplay;
  *(TASK **)&pTVar1->local = pTVar2;
  pTVar1[1].event_s0 = 1;
  *(undefined *)((int)&pTVar1[1].event_sp + 1) = 0x20;
  *(undefined *)&pTVar1[1].event_sp = 0x20;
  *(undefined *)((int)&pTVar1[1].event_sp + 2) = 0x60;
  *(undefined *)((int)&pTVar1[1].event_sp + 3) = 0;
  do {
    if (pTVar1[1].event_s0 != 0) {
      Motion2D_LightningCompute
                ((char)pTVar1 + -0x20,(char)pTVar1 + -0x18,*(short *)&pTVar1[1].event_exec,
                 (char)pTVar2,(int)*(short *)&pTVar1[1].event_ra);
    }
    iVar3 = iVar3 + 1;
    Task_Next();
    pTVar1[1].event_s0 = pTVar1[1].event_s0 ^ 1;
  } while (iVar3 < 0x14);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Motion2D_LightningTaskDisplay()
 // line 1870, offset 0x800283c8
	/* begin block 1 */
		// Start line: 1871
		// Start offset: 0x800283C8
		// Variables:
	// 		struct _LIGHTNING *l; // $a1
	/* end block 1 */
	// End offset: 0x80028428
	// End Line: 1878

	/* begin block 2 */
		// Start line: 4873
	/* end block 2 */
	// End Line: 4874

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Motion2D_LightningTaskDisplay(void)

{
  void *pvVar1;
  short n;
  
  pvVar1 = TaskCurrent->local;
  if ((*(int *)((int)pvVar1 + 0x6c) != 0) || (Pvl_Pause != 0)) {
    n = (short)*(int *)((int)pvVar1 + 0x68);
    if (*(int *)((int)pvVar1 + 0x68) < 0) {
      n = -n;
    }
    Motion2D_LightningDisplay((char)pvVar1 + '`',(char)pvVar1,n,1);
  }
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ Motion2D_LightningCompute(struct MOTION2D_7fake *s /*stack 0*/, struct MOTION2D_7fake *d /*stack 4*/, short r /*$s1*/, struct MOTION2D_7fake *pts /*$s7*/, int n /*stack 16*/)
 // line 1881, offset 0x80028438
	/* begin block 1 */
		// Start line: 1882
		// Start offset: 0x80028438
		// Variables:
	// 		long a; // stack offset -72
	// 		long i; // $s5
	// 		long j; // $a0
	// 		long dt; // $s0
	// 		long coll; // stack offset -68

		/* begin block 1.1 */
			// Start line: 1899
			// Start offset: 0x80028584
		/* end block 1.1 */
		// End offset: 0x80028950
		// End Line: 1938
	/* end block 1 */
	// End offset: 0x8002897C
	// End Line: 1941

	/* begin block 2 */
		// Start line: 4895
	/* end block 2 */
	// End Line: 4896

/* WARNING: Removing unreachable block (ram,0x800285c0) */

short Motion2D_LightningCompute(undefined s,undefined d,short r,undefined pts,int n)

{
  bool bVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  short sVar8;
  int iVar9;
  int iVar10;
  undefined3 in_register_00000011;
  undefined4 *puVar11;
  undefined3 in_register_00000015;
  short *psVar12;
  undefined3 in_register_0000001d;
  undefined4 uVar13;
  int iVar14;
  uint uVar15;
  undefined4 *puVar16;
  undefined4 *puVar17;
  int iVar18;
  uint uVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  short local_50;
  
  puVar16 = (undefined4 *)CONCAT31(in_register_0000001d,pts);
  psVar12 = (short *)CONCAT31(in_register_00000015,d);
  puVar11 = (undefined4 *)CONCAT31(in_register_00000011,s);
  bVar1 = -1 < n << 0x10;
  local_50 = (short)n;
  if (!bVar1) {
    local_50 = -local_50;
  }
  lVar2 = Distance3D((int)*(short *)puVar11,(int)*(short *)((int)puVar11 + 2),
                     (int)*(short *)(puVar11 + 1),(int)*psVar12,(int)psVar12[1],(int)psVar12[2]);
  lVar3 = M_rand();
  uVar19 = lVar3 % lVar2;
  if (lVar2 == 0) {
    trap(0x1c00);
  }
  if ((lVar2 == -1) && (lVar3 == -0x80000000)) {
    trap(0x1800);
  }
  if (lVar2 < 0) {
    lVar2 = lVar2 + 3;
  }
  uVar15 = 1;
  iVar9 = ((int)(uVar19 + (uVar19 >> 0x1f)) >> 1) - (lVar2 >> 2);
  uVar13 = puVar11[1];
  *puVar16 = *puVar11;
  puVar16[1] = uVar13;
  iVar10 = (int)local_50;
  if (1 < iVar10) {
    iVar18 = iVar10 + -1;
    puVar17 = puVar16;
    do {
      puVar17 = puVar17 + 2;
      iVar4 = rcos((int)r);
      iVar5 = rsin((int)r);
      if (iVar18 == 0) {
        trap(0x1c00);
      }
      uVar19 = (0x800 / iVar18) * uVar15;
      iVar6 = rsin(uVar19);
      iVar7 = rsin(uVar19);
      iVar20 = ((int)*psVar12 - (int)*(short *)puVar11) * uVar15;
      if (iVar18 == 0) {
        trap(0x1c00);
      }
      if ((iVar18 == -1) && (iVar20 == -0x80000000)) {
        trap(0x1800);
      }
      iVar21 = ((int)psVar12[1] - (int)*(short *)((int)puVar11 + 2)) * uVar15;
      if (iVar18 == 0) {
        trap(0x1c00);
      }
      if ((iVar18 == -1) && (iVar21 == -0x80000000)) {
        trap(0x1800);
      }
      iVar22 = ((int)psVar12[2] - (int)*(short *)(puVar11 + 1)) * uVar15;
      if (iVar18 == 0) {
        trap(0x1c00);
      }
      if ((iVar18 == -1) && (iVar22 == -0x80000000)) {
        trap(0x1800);
      }
      lVar2 = M_rand();
      iVar14 = (int)(short)(iVar6 * iVar9 >> 0xc);
      iVar7 = (int)(short)(iVar7 * iVar9 >> 0xc);
      iVar6 = lVar2 % 100;
      if (iVar6 < 0) {
        iVar6 = iVar6 + 3;
      }
      *(short *)puVar17 =
           *(short *)puVar11 + (short)(iVar20 / iVar18) +
           (short)((int)(short)iVar4 * iVar14 - (int)(short)iVar5 * iVar7 >> 0xc) +
           (short)(iVar6 >> 2) + -0xc;
      lVar2 = M_rand();
      iVar6 = lVar2 % 100;
      if (iVar6 < 0) {
        iVar6 = iVar6 + 3;
      }
      *(short *)((int)puVar16 + 10) =
           *(short *)((int)puVar11 + 2) + (short)(iVar21 / iVar18) +
           (short)((int)(short)iVar5 * iVar14 + (int)(short)iVar4 * iVar7 >> 0xc) +
           (short)(iVar6 >> 2) + -0xc;
      *(short *)(puVar16 + 3) = *(short *)(puVar11 + 1) + (short)(iVar22 / iVar18);
      if (bVar1) {
        sVar8 = (short)uVar15;
        if ((uVar15 & 1) == 0) {
          lVar2 = Boxes_GetHeight((_D3_OBJECT *)0x0,(char)puVar17,0);
          if ((int)*(short *)(puVar16 + 3) <= lVar2) {
            if (iVar10 <= (int)uVar15) {
              return sVar8;
            }
            do {
              uVar13 = puVar16[1];
              *puVar17 = *puVar16;
              puVar17[1] = uVar13;
              uVar15 = uVar15 + 1;
              puVar16 = puVar16 + 2;
              puVar17 = puVar17 + 2;
            } while ((int)uVar15 < (int)local_50);
            return sVar8;
          }
        }
        else {
          lVar2 = Boxes_GetHeightPlatform((_D3_OBJECT *)0x0,(char)puVar17);
          if ((int)*(short *)(puVar16 + 3) <= lVar2) {
            if (iVar10 <= (int)uVar15) {
              return sVar8;
            }
            do {
              uVar13 = puVar16[1];
              *puVar17 = *puVar16;
              puVar17[1] = uVar13;
              uVar15 = uVar15 + 1;
              puVar16 = puVar16 + 2;
              puVar17 = puVar17 + 2;
            } while ((int)uVar15 < (int)local_50);
            return sVar8;
          }
        }
      }
      uVar15 = uVar15 + 1;
      puVar16 = puVar16 + 2;
    } while ((int)uVar15 < iVar10);
  }
  return local_50;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Motion2D_LightningDisplay(struct MOTION2D_8fake *color /*stack 0*/, struct MOTION2D_7fake *pts /*$fp*/, short n /*stack -56*/, short fbranche /*stack -48*/)
 // line 1944, offset 0x800289ac
	/* begin block 1 */
		// Start line: 1945
		// Start offset: 0x800289AC
		// Variables:
	// 		struct MOTION2D_33fake *pg4; // $s1
	// 		struct MOTION2D_71fake list; // stack offset -120
	// 		struct MOTION2D_7fake imps[2]; // stack offset -104
	// 		struct MOTION2D_8fake clow; // stack offset -88
	// 		struct MOTION2D_8fake colors[2]; // stack offset -80
	// 		long l; // $a1
	// 		long ll; // $a2
	// 		long z; // stack offset -64
	// 		long sxy; // stack offset -68
	// 		long sxyl; // stack offset -72
	// 		short i; // $s4
	// 		short r; // $s7
	/* end block 1 */
	// End offset: 0x80029350
	// End Line: 2076

	/* begin block 2 */
		// Start line: 5075
	/* end block 2 */
	// End Line: 5076

/* WARNING: Could not reconcile some variable overlaps */

void Motion2D_LightningDisplay(undefined color,undefined pts,short n,short fbranche)

{
  bool bVar1;
  _SCREEN *p_Var2;
  undefined4 in_zero;
  undefined4 in_at;
  short sVar3;
  ushort uVar4;
  ushort uVar5;
  int iVar6;
  long lVar7;
  long lVar8;
  int iVar9;
  int iVar10;
  undefined3 in_register_00000011;
  undefined4 *puVar11;
  int iVar12;
  undefined3 in_register_00000015;
  undefined4 *puVar13;
  int iVar14;
  undefined4 *puVar15;
  undefined4 uVar16;
  int *piVar17;
  uint *puVar18;
  uint *puVar19;
  uint *puVar20;
  int iVar21;
  void *local_78;
  undefined4 *local_74;
  undefined4 *local_70;
  undefined2 local_6c;
  undefined4 auStack104 [4];
  byte local_58;
  byte local_57;
  byte local_56;
  undefined4 local_50 [2];
  undefined4 local_48;
  undefined4 local_44;
  int local_40;
  ushort local_38;
  short local_30;
  
  puVar13 = (undefined4 *)CONCAT31(in_register_00000015,pts);
  puVar11 = (undefined4 *)CONCAT31(in_register_00000011,color);
  local_58 = *(byte *)puVar11 >> 1;
  local_57 = *(byte *)((int)puVar11 + 1) >> 1;
  local_56 = *(byte *)((int)puVar11 + 2) >> 1;
  setCopReg(2,in_zero,*puVar13);
  setCopReg(2,in_at,puVar13[1]);
  copFunction(2,0x180001);
  local_48 = getCopReg(2,0xe);
  puVar15 = (undefined4 *)((int)puVar13 + ((int)((uint)(ushort)n << 0x10) >> 0xd) + -8);
  setCopReg(2,in_zero,*puVar15);
  setCopReg(2,in_at,puVar15[1]);
  copFunction(2,0x180001);
  local_44 = getCopReg(2,0xe);
  local_48._2_2_ = (short)(local_48 >> 0x10);
  local_44._2_2_ = (short)(local_44 >> 0x10);
  local_38 = n;
  local_30 = fbranche;
  iVar6 = Direction(((int)local_48._2_2_ - (int)local_44._2_2_) * 0x10000 >> 0x10,
                    (int)(((local_48 & 0xffff) - (local_44 & 0xffff)) * 0x10000) >> 0x10);
  if (iVar6 < 0) {
    iVar6 = -iVar6;
  }
  if ((0xc00 < (iVar6 - 0x200U & 0xffff)) || (bVar1 = true, (iVar6 - 0x601U & 0xffff) < 0x3ff)) {
    bVar1 = false;
  }
  iVar10 = (int)(short)local_38;
  iVar6 = 1;
  puVar20 = (uint *)Main_Prims;
  if (1 < iVar10) {
    iVar21 = iVar10 + -1;
    piVar17 = (int *)((int)Main_Prims + 0x20);
    puVar20 = (uint *)Main_Prims;
    do {
      puVar15 = (undefined4 *)((int)puVar13 + ((iVar6 << 0x10) >> 0xd));
      setCopReg(2,in_zero,*puVar15);
      setCopReg(2,in_at,puVar15[1]);
      copFunction(2,0x180001);
      local_44 = getCopReg(2,0xe);
      local_40 = getCopReg(2,0x9800);
      local_40 = local_40 >> 2;
      if ((local_40 != 0) && (local_40 < (int)Scr_OtSize)) {
        if (Main_TextContext.Font.ascii_tab._20_4_ <= puVar20 + 0x1a) break;
        lVar7 = M_rand();
        lVar8 = lVar7;
        if (lVar7 < 0) {
          lVar8 = lVar7 + 7;
        }
        if (Pvl_Pause == 0) {
          iVar9 = (lVar7 + (lVar8 >> 3) * -8 + 6) * (int)Scr_GeomScreen;
          if (local_40 == 0) {
            trap(0x1c00);
          }
          if ((local_40 == -1) && (iVar9 == -0x80000000)) {
            trap(0x1800);
          }
        }
        else {
          iVar9 = (int)Scr_GeomScreen * 6;
          if (local_40 == 0) {
            trap(0x1c00);
          }
          if ((local_40 == -1) && (iVar9 == -0x80000000)) {
            trap(0x1800);
          }
        }
        iVar9 = iVar9 / local_40;
        sVar3 = (short)iVar6;
        iVar14 = 1;
        if ((1 < (int)sVar3) && ((int)sVar3 < iVar21)) {
          if (iVar9 < 0) {
            iVar9 = iVar9 + 0xf;
          }
          iVar14 = (iVar9 >> 4) + 1;
        }
        iVar9 = ((int)Scr_GeomScreen * 0x14) / local_40;
        if (local_40 == 0) {
          trap(0x1c00);
        }
        in_at = 0x80000000;
        if ((local_40 == -1) && ((int)Scr_GeomScreen * 0x14 == -0x80000000)) {
          trap(0x1800);
        }
        if (bVar1) {
          iVar9 = iVar9 << 0x10;
          iVar14 = iVar14 << 0x10;
        }
        *(undefined *)(piVar17 + -7) = 0xff;
        *(undefined *)((int)piVar17 + -0x1b) = 0xff;
        *(undefined *)((int)piVar17 + -0x1a) = 0xff;
        *(undefined *)((int)piVar17 + -0x1d) = 5;
        *(undefined *)((int)piVar17 + -0x19) = 0x2a;
        piVar17[-6] = local_44 - iVar14;
        piVar17[-5] = local_44 + iVar14;
        piVar17[-3] = local_48 + iVar14;
        piVar17[-4] = local_48 - iVar14;
        p_Var2 = Scr;
        *puVar20 = *puVar20 & 0xff000000 | Scr->ot[local_40] & 0xffffff;
        p_Var2->ot[local_40] = p_Var2->ot[local_40] & 0xff000000 | (uint)puVar20 & 0xffffff;
        *(undefined *)(piVar17 + -1) = 0;
        *(undefined *)((int)piVar17 + -3) = 0;
        *(undefined *)((int)piVar17 + -2) = 0;
        *(undefined *)(piVar17 + 3) = 0;
        *(undefined *)((int)piVar17 + 0xd) = 0;
        *(undefined *)((int)piVar17 + 0xe) = 0;
        *(byte *)(piVar17 + 1) = local_58;
        *(byte *)((int)piVar17 + 5) = local_57;
        *(byte *)((int)piVar17 + 6) = local_56;
        *(byte *)(piVar17 + 5) = local_58;
        *(byte *)((int)piVar17 + 0x15) = local_57;
        *(undefined *)((int)piVar17 + -5) = 8;
        *(undefined *)((int)piVar17 + -1) = 0x3a;
        *(byte *)((int)piVar17 + 0x16) = local_56;
        iVar12 = (int)sVar3;
        puVar18 = puVar20 + 6;
        iVar14 = 0;
        if (iVar12 < iVar21) {
          iVar14 = iVar9;
        }
        *piVar17 = local_44 - iVar14;
        piVar17[2] = local_44;
        iVar14 = 0;
        if (1 < iVar12) {
          iVar14 = iVar9;
        }
        piVar17[4] = local_48 - iVar14;
        piVar17[6] = local_48;
        p_Var2 = Scr;
        *puVar18 = *puVar18 & 0xff000000 | Scr->ot[local_40] & 0xffffff;
        p_Var2->ot[local_40] = p_Var2->ot[local_40] & 0xff000000 | (uint)puVar18 & 0xffffff;
        *(undefined *)(piVar17 + 8) = 0;
        *(undefined *)((int)piVar17 + 0x21) = 0;
        *(undefined *)((int)piVar17 + 0x22) = 0;
        *(undefined *)(piVar17 + 0xc) = 0;
        *(undefined *)((int)piVar17 + 0x31) = 0;
        *(undefined *)((int)piVar17 + 0x32) = 0;
        *(byte *)(piVar17 + 10) = local_58;
        *(byte *)((int)piVar17 + 0x29) = local_57;
        *(byte *)((int)piVar17 + 0x2a) = local_56;
        *(byte *)(piVar17 + 0xe) = local_58;
        puVar18 = puVar20 + 0xf;
        *(byte *)((int)piVar17 + 0x39) = local_57;
        *(undefined *)((int)piVar17 + 0x1f) = 8;
        *(undefined *)((int)piVar17 + 0x23) = 0x3a;
        *(byte *)((int)piVar17 + 0x3a) = local_56;
        iVar14 = 0;
        if (iVar12 < iVar21) {
          iVar14 = iVar9;
        }
        piVar17[9] = local_44 + iVar14;
        piVar17[0xb] = local_44;
        iVar14 = 0;
        if (1 < iVar12) {
          iVar14 = iVar9;
        }
        piVar17[0xd] = local_48 + iVar14;
        piVar17[0xf] = local_48;
        p_Var2 = Scr;
        iVar9 = (int)Scr_Dfe;
        iVar14 = (int)Scr_Dtd;
        *puVar18 = *puVar18 & 0xff000000 | Scr->ot[local_40] & 0xffffff;
        puVar19 = puVar20 + 0x18;
        p_Var2->ot[local_40] = p_Var2->ot[local_40] & 0xff000000 | (uint)puVar18 & 0xffffff;
        SetDrawTPage((int)puVar19,iVar9,iVar14,0x20);
        p_Var2 = Scr;
        piVar17 = piVar17 + 0x1a;
        *puVar19 = *puVar19 & 0xff000000 | Scr->ot[local_40] & 0xffffff;
        puVar20 = puVar20 + 0x1a;
        p_Var2->ot[local_40] = p_Var2->ot[local_40] & 0xff000000 | (uint)puVar19 & 0xffffff;
      }
      iVar6 = iVar6 + 1;
      local_48 = local_44;
    } while (iVar6 * 0x10000 >> 0x10 < iVar10);
  }
  local_74 = auStack104;
  local_70 = local_50;
  local_78 = Pl_Pcl;
  local_50[0] = *puVar11;
  local_6c = 1;
  Main_Prims = puVar20;
  lVar8 = M_rand();
  iVar6 = (int)(short)local_38 + -2;
  if (iVar6 == 0) {
    trap(0x1c00);
  }
  if ((iVar6 == -1) && (lVar8 == -0x80000000)) {
    trap(0x1800);
  }
  uVar16 = (puVar13 + (lVar8 % iVar6) * 2)[3];
  *local_74 = (puVar13 + (lVar8 % iVar6) * 2)[2];
  local_74[1] = uVar16;
  lVar8 = M_rand();
  puVar15 = local_74;
  *(short *)((int)local_74 + 6) = (((ushort)lVar8 & 1) + 0x41) * 0x100;
  uVar5 = *(ushort *)((int)local_74 + 6);
  if (local_30 == 0) {
    lVar8 = M_rand();
    iVar6 = lVar8 % 100;
    if (iVar6 < 0) {
      iVar6 = iVar6 + 0xf;
    }
    uVar4 = (short)(iVar6 >> 4) + 0xc;
  }
  else {
    lVar8 = M_rand();
    iVar6 = lVar8 % 100;
    if (iVar6 < 0) {
      iVar6 = iVar6 + 3;
    }
    uVar4 = (short)(iVar6 >> 2) + 0x19;
  }
  *(ushort *)((int)puVar15 + 6) = uVar5 | uVar4;
  if (Pvl_Pause == 0) {
    Main_Prims = (void *)GtxShp_DisplayListLOFF
                                   (&local_78,Main_Prims,Scr->ot,(int)Scr_OtSize,0xffffffe7,
                                    Main_TextContext.Font.ascii_tab._20_4_);
  }
  puVar15 = local_74;
  local_6c = 2;
  local_70[1] = *puVar11;
  iVar6 = ((int)((uint)local_38 << 0x10) >> 0xd) + (int)puVar13;
  uVar16 = *(undefined4 *)(iVar6 + -4);
  *local_74 = *(undefined4 *)(iVar6 + -8);
  local_74[1] = uVar16;
  uVar16 = puVar13[1];
  local_74[2] = *puVar13;
  local_74[3] = uVar16;
  lVar8 = M_rand();
  iVar6 = lVar8 % 100;
  if (iVar6 < 0) {
    iVar6 = iVar6 + 3;
  }
  lVar7 = M_rand();
  puVar11 = local_74;
  lVar8 = lVar7;
  if (lVar7 < 0) {
    lVar8 = lVar7 + 3;
  }
  if (Pvl_Pause == 0) {
    uVar5 = ((short)lVar7 + (short)(lVar8 >> 2) * -4 + 0x3d) * 0x100;
  }
  else {
    uVar5 = 0x3d00;
  }
  uVar4 = uVar5 | 0x32;
  if (Pvl_Pause == 0) {
    uVar4 = uVar5 + (short)(iVar6 >> 2) + 0x32;
  }
  *(ushort *)((int)puVar15 + 6) = uVar4;
  lVar7 = M_rand();
  lVar8 = lVar7;
  if (lVar7 < 0) {
    lVar8 = lVar7 + 3;
  }
  if (Pvl_Pause == 0) {
    uVar5 = ((short)lVar7 + (short)(lVar8 >> 2) * -4 + 0x3d) * 0x100 | 0xc;
  }
  else {
    uVar5 = 0x3d0c;
  }
  *(ushort *)((int)puVar11 + 0xe) = uVar5;
  Main_Prims = (void *)GtxShp_DisplayListLOFF
                                 (&local_78,Main_Prims,Scr->ot,(int)Scr_OtSize,0xffffff9c,
                                  Main_TextContext.Font.ascii_tab._20_4_);
  return;
}



// decompiled code
// original method signature: 
// struct TASK * /*$ra*/ Motion2D_Storm(struct _D3_OBJECT *ot /*$s0*/, long power /*$s1*/, struct TASK **handle /*$s2*/)
 // line 2100, offset 0x800293c4
	/* begin block 1 */
		// Start line: 2101
		// Start offset: 0x800293C4
		// Variables:
	// 		struct TASK *t; // $v0
	/* end block 1 */
	// End offset: 0x80029408
	// End Line: 2114

	/* begin block 2 */
		// Start line: 5611
	/* end block 2 */
	// End Line: 5612

TASK * Motion2D_Storm(_D3_OBJECT *ot,long power,TASK **handle)

{
  TASK *pTVar1;
  
  pTVar1 = Task_Link(Motion2D_StormTask,0x180);
  *(_D3_OBJECT **)&pTVar1->s0 = ot;
  pTVar1->s1 = power;
  *(TASK ***)&pTVar1->s2 = handle;
  if (handle != (TASK **)0x0) {
    *handle = pTVar1;
  }
  return pTVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Motion2D_StormEnd(struct TASK *t /*$a0*/)
 // line 2117, offset 0x80029420
	/* begin block 1 */
		// Start line: 2119
		// Start offset: 0x80029420
		// Variables:
	// 		struct _STORM *st; // $v1
	/* end block 1 */
	// End offset: 0x80029434
	// End Line: 2129

	/* begin block 2 */
		// Start line: 5652
	/* end block 2 */
	// End Line: 5653

void Motion2D_StormEnd(TASK *t)

{
  if (t != (TASK *)0x0) {
    *(undefined4 *)((int)t->local + 0x38) = 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Motion2D_StormTask()
 // line 2132, offset 0x8002943c
	/* begin block 1 */
		// Start line: 2133
		// Start offset: 0x8002943C
		// Variables:
	// 		struct _STORM st; // stack offset -88
	// 		struct _D3_OBJECT *ot; // $s2
	// 		long i; // $s0
	// 		long type; // $a0
	// 		long end; // $s3
	// 		long custom; // $s4
	/* end block 1 */
	// End offset: 0x80029694
	// End Line: 2227

	/* begin block 2 */
		// Start line: 5686
	/* end block 2 */
	// End Line: 5687

/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Motion2D_StormTask(void)

{
  bool bVar1;
  TASK *pTVar2;
  void *pvVar3;
  uint uVar4;
  uint uVar5;
  long Index;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_58;
  int local_54;
  undefined4 local_50;
  uint local_4c;
  undefined2 local_48;
  undefined2 local_46;
  short local_44;
  undefined2 local_40;
  undefined2 local_3e;
  short local_3c;
  byte local_38;
  byte local_37;
  byte local_36;
  undefined *local_34;
  undefined *local_30;
  undefined4 local_2c;
  undefined4 *local_24;
  int local_20;
  
  pTVar2 = TaskCurrent;
  local_24 = (undefined4 *)TaskCurrent->s2;
  iVar8 = TaskCurrent->s0;
  uVar4 = TaskCurrent->s1;
  bVar1 = 2 < (int)uVar4;
  if (bVar1) {
    uVar5 = 2;
    local_50 = *(undefined4 *)(iVar8 + 0x2c);
    local_4c._0_2_ = (short)*(uint *)(iVar8 + 0x30);
    local_4c = *(uint *)(iVar8 + 0x30) & 0xffff0000 |
               (uint)(ushort)(*(short *)(iVar8 + 0x70) + (short)local_4c + -300);
  }
  else {
    uVar5 = uVar4 & 2;
    uVar4 = 0x80;
  }
  *(int **)&TaskCurrent->local = &local_58;
  pTVar2->display = Motion2D_StormDisplay;
  if (uVar5 == 0) {
    pvVar3 = FileGroup_GetAddr(Pl_Spells,5);
    Index = 6;
  }
  else {
    pvVar3 = FileGroup_GetAddr(Pl_Spells,2);
    Index = 3;
  }
  local_58 = (int)pvVar3 + 0xc;
  pvVar3 = FileGroup_GetAddr(Pl_Spells,Index);
  local_54 = (int)pvVar3 + 0xc;
  local_30 = (undefined *)0x800;
  local_34 = (undefined *)0x800;
  local_44 = 0;
  local_46 = 0;
  local_48 = 0;
  local_3c = 0;
  local_3e = 0;
  local_40 = 0;
  local_2c = 0x1000;
  local_36 = 0;
  local_37 = 0;
  local_38 = 0;
  local_20 = 0;
  Fx_Play(0x2e,(char)iVar8 + ',');
  iVar6 = 0;
  if (0 < (int)uVar4) {
    iVar7 = uVar4 - 0x20;
    do {
      if (!bVar1) {
        local_50 = *(undefined4 *)(iVar8 + 0x2c);
        local_4c._0_2_ = (short)*(uint *)(iVar8 + 0x30);
        local_4c = *(uint *)(iVar8 + 0x30) & 0xffff0000 |
                   (uint)(ushort)(*(short *)(iVar8 + 0x70) + (short)local_4c + -300);
      }
      local_34 = local_34 + 0xc0;
      local_3c = local_3c + 0x10;
      local_44 = local_44 + -0x10;
      if (0x1200 < (int)local_34) {
        local_34 = &DAT_00001200;
      }
      if (iVar6 < iVar7) {
        local_36 = (byte)((uint)local_38 + 3);
        if (0x80 < (uint)local_38 + 3) {
          local_36 = 0x80;
        }
      }
      else {
        local_36 = (byte)((uint)local_38 - 4);
        if ((int)((uint)local_38 - 4) < 0) {
          local_36 = 0;
        }
      }
      if ((local_20 != 0) && (iVar6 < iVar7)) {
        iVar6 = iVar7;
      }
      iVar6 = iVar6 + 1;
      local_38 = local_36;
      local_37 = local_36;
      local_30 = local_34;
      Task_Next();
    } while (iVar6 < (int)uVar4);
  }
  if (local_24 != (undefined4 *)0x0) {
    *local_24 = 0;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Motion2D_StormDisplay()
 // line 2230, offset 0x800296b4
	/* begin block 1 */
		// Start line: 2231
		// Start offset: 0x800296B4
		// Variables:
	// 		struct MOTION2D_5fake mn64; // stack offset -56
	// 		struct _STORM *st; // $s0
	/* end block 1 */
	// End offset: 0x800296B4
	// End Line: 2231

	/* begin block 2 */
		// Start line: 5935
	/* end block 2 */
	// End Line: 5936

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Motion2D_StormDisplay(void)

{
  char cVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)TaskCurrent->local;
  cVar1 = (char)puVar2;
  Light_SetIdentity();
  Motion2D_SetTrans(cVar1 + '\b',200);
  Motion2D_DisplayTmd(cVar1 + '\x10',cVar1 + '$',(char)*puVar2,cVar1 + ' ',Scr->ot + 8,0,200);
  Motion2D_DisplayTmd(cVar1 + '\x18',cVar1 + '$',(char)puVar2[1],cVar1 + ' ',Scr->ot + 9,0,200);
  SetBackColor((uint)(Pvl_File->light_ambient).r,(uint)(Pvl_File->light_ambient).g,
               (uint)(Pvl_File->light_ambient).b);
  setCopControlWord(2,0,Cam_Matrix.m[0]._0_4_);
  setCopControlWord(2,0x800,Cam_Matrix.m._4_4_);
  setCopControlWord(2,0x1000,Cam_Matrix.m[1]._2_4_);
  setCopControlWord(2,0x1800,Cam_Matrix.m[2]._0_4_);
  setCopControlWord(2,0x2000,Cam_Matrix._16_4_);
  setCopControlWord(2,0x2800,Cam_Matrix.t[0]);
  setCopControlWord(2,0x3000,Cam_Matrix.t[1]);
  setCopControlWord(2,0x3800,Cam_Matrix.t[2]);
  return;
}



// decompiled code
// original method signature: 
// struct TASK * /*$ra*/ Motion2D_Twister(struct _D3_OBJECT *ot /*$s0*/, long type /*$s1*/)
 // line 2272, offset 0x800297d8
	/* begin block 1 */
		// Start line: 2273
		// Start offset: 0x800297D8
		// Variables:
	// 		struct TASK *t; // $v0
	/* end block 1 */
	// End offset: 0x800297D8
	// End Line: 2273

	/* begin block 2 */
		// Start line: 6019
	/* end block 2 */
	// End Line: 6020

TASK * Motion2D_Twister(_D3_OBJECT *ot,long type)

{
  TASK *pTVar1;
  
  pTVar1 = Task_Link(Motion2D_TwisterTask,0x180);
  *(_D3_OBJECT **)&pTVar1->s0 = ot;
  pTVar1->s1 = type;
  return pTVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Motion2D_TwisterEnd(struct TASK *t /*$a0*/)
 // line 2285, offset 0x8002981c
	/* begin block 1 */
		// Start line: 2287
		// Start offset: 0x8002981C
		// Variables:
	// 		struct _TWISTER *tw; // $v1
	/* end block 1 */
	// End offset: 0x8002981C
	// End Line: 2289

	/* begin block 2 */
		// Start line: 6052
	/* end block 2 */
	// End Line: 6053

void Motion2D_TwisterEnd(TASK *t)

{
  *(undefined2 *)((int)t->local + 0x2e) = 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Motion2D_TwisterTask()
 // line 2294, offset 0x8002982c
	/* begin block 1 */
		// Start line: 2295
		// Start offset: 0x8002982C
		// Variables:
	// 		long i; // $s0
	// 		long sxy_max; // $s2
	// 		long sz_max; // $s1
	// 		struct _TWISTER tw; // stack offset -64
	/* end block 1 */
	// End offset: 0x80029A98
	// End Line: 2370

	/* begin block 2 */
		// Start line: 6072
	/* end block 2 */
	// End Line: 6073

/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Motion2D_TwisterTask(void)

{
  TASK *pTVar1;
  void *pvVar2;
  int iVar3;
  long Index;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 local_40;
  uint local_3c;
  undefined2 local_38;
  undefined2 local_36;
  short local_34;
  byte local_30;
  byte local_2f;
  byte local_2e;
  undefined local_2d;
  int local_2c;
  int local_28;
  int local_24;
  int local_1c;
  long local_18;
  short local_14;
  short local_12;
  
  pTVar1 = TaskCurrent;
  local_18 = TaskCurrent->s0;
  local_14 = *(short *)&TaskCurrent->s1;
  *(undefined4 **)&TaskCurrent->local = &local_40;
  pTVar1->display = Motion2D_TwisterTaskDisplay;
  Index = 1;
  if (local_14 == 0) {
    Index = 7;
  }
  pvVar2 = FileGroup_GetAddr(Pl_Spells,Index);
  local_1c = (int)pvVar2 + 0xc;
  local_34 = 0;
  local_36 = 0;
  local_38 = 0;
  local_2d = 0;
  local_2e = 0;
  local_2f = 0;
  local_30 = 0;
  local_12 = 0;
  if (local_14 == 0) {
    local_28 = 0x1000;
    local_2c = 0x1000;
    iVar6 = (((int)*(short *)(local_18 + 0x70) - (int)*(short *)(local_18 + 0x50)) + 100) * 10;
    iVar5 = 0x4000;
  }
  else {
    iVar5 = 0x800;
    iVar6 = 0x800;
    local_28 = 0x200;
    local_2c = 0x200;
  }
  local_24 = 0;
  iVar4 = 0;
  Fx_Play(0x2f,(char)local_18 + ',');
  do {
    Tmd_ChangeColor((char)local_1c,0xd0);
    local_40 = *(undefined4 *)(local_18 + 0x2c);
    local_3c = *(uint *)(local_18 + 0x30);
    if (local_14 == 0) {
      local_3c = local_3c & 0xffff0000 |
                 (uint)(ushort)(*(short *)(local_18 + 0x70) + (short)local_3c + 200);
    }
    local_34 = local_34 + 0x580;
    iVar3 = iVar6;
    if (iVar6 < 0) {
      iVar3 = iVar6 + 0x1f;
    }
    iVar3 = local_24 + (iVar3 >> 5);
    local_24 = iVar6;
    if (iVar3 < iVar6) {
      local_24 = iVar3;
    }
    iVar3 = local_2c + 0x40;
    local_2c = iVar5;
    if (iVar3 < iVar5) {
      local_2c = iVar3;
    }
    if (iVar4 < 0x61) {
      local_2e = (byte)((uint)local_30 + 3);
      if (0xa0 < (uint)local_30 + 3) {
        local_2e = 0xa0;
      }
    }
    else {
      local_2e = (byte)((uint)local_30 - 5);
      if ((int)((uint)local_30 - 5) < 0) {
        local_2e = 0;
      }
    }
    if (local_14 != 0) {
      if (local_12 == 0) {
        if (iVar4 >= 0x60) {
          iVar4 = 0x5f;
        }
      }
      else {
        if (iVar4 < 0x60) {
          iVar4 = 0x60;
        }
      }
    }
    iVar4 = iVar4 + 1;
    local_30 = local_2e;
    local_2f = local_2e;
    local_28 = local_2c;
    Task_Next();
  } while (iVar4 < 0x80);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Motion2D_TwisterTaskDisplay()
 // line 2373, offset 0x80029ab0
	/* begin block 1 */
		// Start line: 2374
		// Start offset: 0x80029AB0
		// Variables:
	// 		struct MOTION2D_5fake mn64; // stack offset -40
	// 		struct _TWISTER *tw; // $s0
	/* end block 1 */
	// End offset: 0x80029AB0
	// End Line: 2374

	/* begin block 2 */
		// Start line: 6284
	/* end block 2 */
	// End Line: 6285

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Motion2D_TwisterTaskDisplay(void)

{
  char p;
  void *pvVar1;
  
  pvVar1 = TaskCurrent->local;
  Light_SetIdentity();
  p = (char)pvVar1;
  Motion2D_SetTrans(p,0xd8);
  Motion2D_DisplayTmd(p + '\b',p + '\x14',(char)*(undefined4 *)((int)pvVar1 + 0x24),p + '\x10',
                      Scr->ot,(int)Scr_OtSize,0xd8);
  SetBackColor((uint)(Pvl_File->light_ambient).r,(uint)(Pvl_File->light_ambient).g,
               (uint)(Pvl_File->light_ambient).b);
  setCopControlWord(2,0,Cam_Matrix.m[0]._0_4_);
  setCopControlWord(2,0x800,Cam_Matrix.m._4_4_);
  setCopControlWord(2,0x1000,Cam_Matrix.m[1]._2_4_);
  setCopControlWord(2,0x1800,Cam_Matrix.m[2]._0_4_);
  setCopControlWord(2,0x2000,Cam_Matrix._16_4_);
  setCopControlWord(2,0x2800,Cam_Matrix.t[0]);
  setCopControlWord(2,0x3000,Cam_Matrix.t[1]);
  setCopControlWord(2,0x3800,Cam_Matrix.t[2]);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Motion2D_DisplayTmd(struct MOTION2D_7fake *r /*$a0*/, struct MOTION2D_6fake *s /*$s0*/, struct MOTION2D_93fake *tmd /*$s1*/, struct MOTION2D_8fake *col /*$s2*/, void *ot /*stack 16*/, long otsize /*stack 20*/, struct MOTION2D_5fake *mn64 /*stack 24*/)
 // line 2398, offset 0x80029b8c
	/* begin block 1 */
		// Start line: 2399
		// Start offset: 0x80029B8C
		// Variables:
	// 		struct MOTION2D_5fake m; // stack offset -56
	/* end block 1 */
	// End offset: 0x80029B8C
	// End Line: 2399

	/* begin block 2 */
		// Start line: 6334
	/* end block 2 */
	// End Line: 6335

void Motion2D_DisplayTmd(undefined r,undefined s,undefined tmd,undefined col,void *ot,long otsize,
                        undefined1 mn64)

{
  undefined3 in_register_00000011;
  undefined3 in_register_00000015;
  undefined3 in_register_00000019;
  undefined3 in_register_0000001d;
  uint local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  RotMatrixZYX((short *)CONCAT31(in_register_00000011,r),(undefined2 *)&local_38);
  MulMatrix2((undefined4 *)&Cam_Matrix,&local_38);
  ScaleMatrix(&local_38,(int *)CONCAT31(in_register_00000015,s));
  setCopControlWord(2,0,local_38);
  setCopControlWord(2,0x800,local_34);
  setCopControlWord(2,0x1000,local_30);
  setCopControlWord(2,0x1800,local_2c);
  setCopControlWord(2,0x2000,local_28);
  Main_Prims = (void *)GtxTmd_DisplayLON(CONCAT31(in_register_00000019,tmd),Main_Prims,ot,otsize,0,
                                         *(undefined4 *)CONCAT31(in_register_0000001d,col));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Motion2D_SetTrans(struct MOTION2D_7fake *p /*$a0*/, struct MOTION2D_5fake *mn64 /*$a1*/)
 // line 2420, offset 0x80029c58
	/* begin block 1 */
		// Start line: 2421
		// Start offset: 0x80029C58
		// Variables:
	// 		struct MOTION2D_5fake m; // stack offset -32
	/* end block 1 */
	// End offset: 0x80029C58
	// End Line: 2421

	/* begin block 2 */
		// Start line: 6379
	/* end block 2 */
	// End Line: 6380

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Motion2D_SetTrans(undefined p,undefined1 mn64)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 in_zero;
  undefined4 in_at;
  undefined3 in_register_00000011;
  
  setCopReg(2,in_zero,*(undefined4 *)CONCAT31(in_register_00000011,p));
  setCopReg(2,in_at,((undefined4 *)CONCAT31(in_register_00000011,p))[1]);
  copFunction(2,0x486012);
  iVar1 = getCopReg(2,0x19);
  iVar2 = getCopReg(2,0x1a);
  iVar3 = getCopReg(2,0x1b);
  setCopControlWord(2,0x2800,iVar1 + Cam_Matrix.t[0]);
  setCopControlWord(2,0x3000,iVar2 + Cam_Matrix.t[1]);
  setCopControlWord(2,0x3800,iVar3 + Cam_Matrix.t[2]);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Motion2D_SetRotTrans(struct MOTION2D_7fake *p /*$a0*/, struct MOTION2D_7fake *r /*$s0*/)
 // line 2433, offset 0x80029cdc
	/* begin block 1 */
		// Start line: 2434
		// Start offset: 0x80029CDC
		// Variables:
	// 		struct MOTION2D_5fake m; // stack offset -72
	// 		struct MOTION2D_5fake mn64; // stack offset -40
	/* end block 1 */
	// End offset: 0x80029CDC
	// End Line: 2434

	/* begin block 2 */
		// Start line: 6405
	/* end block 2 */
	// End Line: 6406

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Motion2D_SetRotTrans(undefined1 p,undefined r)

{
  undefined3 in_register_00000015;
  ushort auStack72 [32];
  
  Motion2D_SetTrans(p,0xd8);
  RotMatrixZYX((short *)CONCAT31(in_register_00000015,r),auStack72);
  SetMulMatrix((undefined4 *)&Cam_Matrix,auStack72);
  return;
}





