#include "THISDUST.H"
#include "STATS.H"


// decompiled code
// original method signature: 
// void /*$ra*/ Stats_Init()
 // line 91, offset 0x8008a490
	/* begin block 1 */
		// Start line: 182
	/* end block 1 */
	// End Line: 183

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Stats_Init(void)

{
  DAT_800b6e80 = Task_Add(Stats_Task,0);
  Stats_Load = (TASK *)0x0;
  Stats_Spirit = (TASK *)0x0;
  Stats_EOLHandle = (TASK *)0x0;
  Stats_MonsterBars = '\x01';
  Stats.fx_handle = -1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Stats_PrepareDisplay(long sx /*$s4*/, long sy /*$s5*/)
 // line 103, offset 0x8008a4dc
	/* begin block 1 */
		// Start line: 104
		// Start offset: 0x8008A4DC
		// Variables:
	// 		long i; // $s1
	// 		long j; // $s2
	// 		struct STATS_70fake shp; // stack offset -56
	// 		struct STATS_36fake *pl; // $a0
	// 		short w; // stack offset -40
	// 		short h; // stack offset -38
	/* end block 1 */
	// End offset: 0x8008AA34
	// End Line: 235

	/* begin block 2 */
		// Start line: 212
	/* end block 2 */
	// End Line: 213

void Stats_PrepareDisplay(long sx,long sy)

{
  short sVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  undefined *puVar6;
  short sVar7;
  undefined *puVar8;
  short sVar9;
  uint *puVar10;
  short sVar11;
  undefined *puVar12;
  undefined4 *puVar13;
  _struct_705 *prim;
  SHAPE_31fake *prim_00;
  SHAPE_31fake *prim_01;
  int iVar14;
  int iVar15;
  _struct_701 *p_Var16;
  SHAPE_68fake local_38;
  ushort local_28;
  ushort local_26 [3];
  
  iVar14 = 0;
  sVar1 = (short)sx;
  sVar2 = (short)sy;
  puVar13 = &DAT_800b6e74;
  puVar12 = &DAT_800b6e70;
  puVar10 = &DAT_800b6e64;
  puVar8 = &DAT_800b6e60;
  puVar6 = &DAT_800b6e30;
  local_38.file = Effects_Pcl;
  Stats.x = sVar1;
  Stats.y = sVar2;
  do {
    puVar6[7] = 0x28;
    puVar6[3] = 5;
    *(short *)(puVar6 + 8) = sVar1 + -5;
    *(short *)(puVar6 + 10) = sVar2 + -5;
    *(short *)(puVar6 + 0xc) = sVar1 + 0x7d;
    *(short *)(puVar6 + 0xe) = sVar2 + -5;
    *(short *)(puVar6 + 0x10) = sVar1 + -5;
    *(short *)(puVar6 + 0x12) = sVar2 + 0x96;
    *(short *)(puVar6 + 0x14) = sVar1 + 0x7d;
    *(short *)(puVar6 + 0x16) = sVar2 + 0x96;
    puVar6[4] = 0x28;
    puVar6[5] = 0x28;
    puVar6[6] = 0x28;
    puVar6[7] = 0x2a;
    puVar8[3] = 1;
    uVar4 = 0xe1000000;
    if (Scr_Dtd != 0) {
      uVar4 = 0xe1000200;
    }
    if (Scr_Dfe == 0) {
      uVar4 = uVar4 | 0x40;
    }
    else {
      uVar4 = uVar4 | 0x440;
    }
    *puVar10 = uVar4;
    puVar12[3] = 1;
    *puVar13 = 0xe1000260;
    puVar13 = puVar13 + 2;
    puVar12 = puVar12 + 8;
    puVar10 = puVar10 + 2;
    puVar8 = puVar8 + 8;
    iVar14 = iVar14 + 1;
    puVar6 = puVar6 + 0x18;
  } while (iVar14 < 2);
  sVar11 = sVar1 + -5;
  sVar9 = sVar2 + -5;
  sVar7 = sVar2 + 0x96;
  iVar14 = 0;
  do {
    iVar5 = iVar14 * 0x40;
    (&DAT_800b6db3)[iVar5] = 3;
    (&DAT_800b6db7)[iVar5] = 0x40;
    sVar3 = Scr_W;
    (&DAT_800b6db8)[iVar14 * 0x20] = sVar11;
    (&DAT_800b6dba)[iVar14 * 0x20] = sVar9;
    (&DAT_800b6dbe)[iVar14 * 0x20] = sVar9;
    (&DAT_800b6db4)[iVar5] = 100;
    (&DAT_800b6db5)[iVar5] = 100;
    (&DAT_800b6db6)[iVar5] = 100;
    (&DAT_800b6dbc)[iVar14 * 0x20] = sVar3 + -1;
    (&DAT_800b6dc3)[iVar5] = 3;
    (&DAT_800b6dc7)[iVar5] = 0x40;
    (&DAT_800b6dc8)[iVar14 * 0x20] = sVar11;
    (&DAT_800b6dca)[iVar14 * 0x20] = sVar9;
    (&DAT_800b6dcc)[iVar14 * 0x20] = sVar11;
    (&DAT_800b6dce)[iVar14 * 0x20] = sVar7;
    (&DAT_800b6dc4)[iVar5] = 100;
    (&DAT_800b6dc5)[iVar5] = 100;
    (&DAT_800b6dc6)[iVar5] = 100;
    (&DAT_800b6dd3)[iVar5] = 3;
    (&DAT_800b6dd7)[iVar5] = 0x40;
    sVar3 = Scr_W;
    iVar15 = iVar14 + 1;
    (&DAT_800b6dd8)[iVar14 * 0x20] = sVar11;
    (&DAT_800b6dda)[iVar14 * 0x20] = sVar7;
    (&DAT_800b6dde)[iVar14 * 0x20] = sVar7;
    (&DAT_800b6dd4)[iVar5] = 100;
    (&DAT_800b6dd5)[iVar5] = 100;
    (&DAT_800b6dd6)[iVar5] = 100;
    (&DAT_800b6ddc)[iVar14 * 0x20] = sVar3 + -1;
    (&DAT_800b6de3)[iVar5] = 3;
    (&DAT_800b6de7)[iVar5] = 0x40;
    (&DAT_800b6de8)[iVar14 * 0x20] = sVar1 + 0x77;
    (&DAT_800b6dea)[iVar14 * 0x20] = sVar9;
    (&DAT_800b6dec)[iVar14 * 0x20] = sVar1 + 0x77;
    (&DAT_800b6dee)[iVar14 * 0x20] = sVar7;
    (&DAT_800b6de4)[iVar5] = 100;
    (&DAT_800b6de5)[iVar5] = 100;
    (&DAT_800b6de6)[iVar5] = 100;
    iVar14 = iVar15;
  } while (iVar15 < 2);
  local_38.shape = 0x81;
  local_38.x = sVar1 + 0x17;
  local_38.y = sVar2 + 0x12;
  Shp_GetWH(&local_38,(short *)&local_28,(short *)local_26);
  iVar14 = 0;
  p_Var16 = &Stats.fond_jauge;
  do {
    iVar5 = 0;
    prim_01 = (SHAPE_31fake *)p_Var16;
    if (iVar14 == 3) {
      local_38.x = local_38.x + 7;
      prim_01 = (SHAPE_31fake *)p_Var16;
    }
    do {
      iVar5 = iVar5 + 1;
      Shp_SetPolyFT4(prim_01,&local_38,(short)(((uint)local_28 + 1) * 0x10000 >> 0x10),
                     (short)(((uint)local_26[0] + 1) * 0x10000 >> 0x10));
      prim_01->r0 = -0x80;
      prim_01->g0 = -0x80;
      prim_01->b0 = -0x80;
      prim_01->code = prim_01->code & 0xfe;
      prim_01->u1 = prim_01->u1 + '\x01';
      prim_01->u3 = prim_01->u3 + '\x01';
      prim_01->v2 = prim_01->v2 + '\x01';
      prim_01->v3 = prim_01->v3 + '\x01';
      prim_01 = prim_01 + 5;
    } while (iVar5 < 2);
    iVar14 = iVar14 + 1;
    local_38.x = local_38.x + 0x13;
    p_Var16 = p_Var16 + 1;
  } while (iVar14 < 4);
  local_38.shape = 0x7b;
  local_38.x = sVar1 + 0x1a;
  local_38.y = sVar2 + 0x5e;
  Shp_GetWH(&local_38,(short *)&local_28,(short *)local_26);
  iVar14 = 0;
  prim = &Stats.levels;
  do {
    iVar14 = iVar14 + 1;
    Shp_SetPolyFT4((SHAPE_31fake *)prim,&local_38,(short)(((uint)local_28 + 1) * 0x10000 >> 0x10),
                   (short)(((uint)local_26[0] + 1) * 0x10000 >> 0x10));
    ((SHAPE_31fake *)prim)->u1 = ((SHAPE_31fake *)prim)->u1 + '\x01';
    ((SHAPE_31fake *)prim)->u3 = ((SHAPE_31fake *)prim)->u3 + '\x01';
    ((SHAPE_31fake *)prim)->v2 = ((SHAPE_31fake *)prim)->v2 + '\x01';
    ((SHAPE_31fake *)prim)->v3 = ((SHAPE_31fake *)prim)->v3 + '\x01';
    prim = (_struct_705 *)((SHAPE_31fake *)prim + 5);
  } while (iVar14 < 2);
  local_38.shape = 0x7d;
  local_38.x = sVar1 + 0x15;
  local_38.y = sVar2;
  Shp_GetWH(&local_38,(short *)&local_28,(short *)local_26);
  iVar14 = 0;
  prim_01 = (SHAPE_31fake *)&DAT_800b5d30;
  do {
    iVar5 = 0;
    prim_00 = prim_01;
    if (iVar14 == 3) {
      local_38.x = local_38.x + 7;
      prim_00 = prim_01;
    }
    do {
      iVar5 = iVar5 + 1;
      Shp_SetPolyFT4(prim_00,&local_38,(short)(((uint)local_28 + 1) * 0x10000 >> 0x10),
                     (short)(((uint)local_26[0] + 1) * 0x10000 >> 0x10));
      prim_00->r0 = -0x80;
      prim_00->g0 = -0x80;
      prim_00->b0 = -0x80;
      prim_00->code = prim_00->code & 0xfe;
      prim_00->u1 = prim_00->u1 + '\x01';
      prim_00->u3 = prim_00->u3 + '\x01';
      prim_00->v2 = prim_00->v2 + '\x01';
      prim_00->v3 = prim_00->v3 + '\x01';
      prim_00 = prim_00 + 8;
    } while (iVar5 < 2);
    prim_01 = prim_01 + 1;
    iVar14 = iVar14 + 1;
    local_38.shape = local_38.shape + 1;
    local_38.x = local_38.x + 0x13;
  } while (iVar14 < 4);
  local_38.shape = 0x7c;
  local_38.x = sVar1 + 6;
  local_38.y = sVar2 + 0x58;
  Shp_GetWH(&local_38,(short *)&local_28,(short *)local_26);
  iVar14 = 0;
  prim_01 = (SHAPE_31fake *)&DAT_800b5dd0;
  do {
    iVar14 = iVar14 + 1;
    Shp_SetPolyFT4(prim_01,&local_38,(short)(((uint)local_28 + 1) * 0x10000 >> 0x10),
                   (short)(((uint)local_26[0] + 1) * 0x10000 >> 0x10));
    prim_01->u1 = prim_01->u1 + '\x01';
    prim_01->u3 = prim_01->u3 + '\x01';
    prim_01->v2 = prim_01->v2 + '\x01';
    prim_01->v3 = prim_01->v3 + '\x01';
    prim_01 = prim_01 + 8;
  } while (iVar14 < 2);
  Stats_SetTanks(sx,sy);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Stats_SetHilite(long mode /*$a0*/)
 // line 239, offset 0x8008aa64
	/* begin block 1 */
		// Start line: 241
		// Start offset: 0x8008AA64
		// Variables:
	// 		long i; // $a1
	// 		long j; // $a3
	// 		unsigned char col; // $t0
	/* end block 1 */
	// End offset: 0x8008AAFC
	// End Line: 275

	/* begin block 2 */
		// Start line: 725
	/* end block 2 */
	// End Line: 726

void Stats_SetHilite(long mode)

{
  undefined *puVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  undefined uVar5;
  
  uVar5 = 100;
  if (mode != 0) {
    uVar5 = 0xfa;
  }
  iVar4 = 0;
  puVar3 = &DAT_800b6db0;
  do {
    iVar2 = 0;
    puVar1 = puVar3;
    do {
      puVar1[4] = uVar5;
      puVar1[5] = 100;
      puVar1[6] = 100;
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 0x40;
    } while (iVar2 < 2);
    iVar4 = iVar4 + 1;
    puVar3 = puVar3 + 0x10;
  } while (iVar4 < 4);
  iVar4 = 0;
  puVar3 = &DAT_800b6e30;
  do {
    if (mode == 0) {
      puVar3[4] = 0x28;
      puVar3[5] = 0x28;
      puVar3[6] = 0x28;
    }
    else {
      puVar3[4] = 0x28;
      puVar3[5] = 4;
      puVar3[6] = 4;
    }
    iVar4 = iVar4 + 1;
    puVar3 = puVar3 + 0x18;
  } while (iVar4 < 2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Stats_SetTanks(long sx /*$s7*/, long sy /*$fp*/)
 // line 278, offset 0x8008ab04
	/* begin block 1 */
		// Start line: 279
		// Start offset: 0x8008AB04
		// Variables:
	// 		long i; // $s1
	// 		long j; // $s4
	// 		long k; // $s2
	// 		short w; // stack offset -48
	// 		short h; // stack offset -46
	// 		struct STATS_70fake shp; // stack offset -64
	// 		struct STATS_31fake *p; // $s0
	/* end block 1 */
	// End offset: 0x8008AE48
	// End Line: 366

	/* begin block 2 */
		// Start line: 815
	/* end block 2 */
	// End Line: 816

void Stats_SetTanks(long sx,long sy)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int num_power;
  SHAPE_31fake *prim;
  int iVar4;
  SHAPE_31fake *prim_00;
  int iVar5;
  int num_weapon;
  SHAPE_68fake local_40;
  ushort local_30;
  ushort local_2e [3];
  
  num_weapon = 0;
  local_40.file = Effects_Pcl;
  Stats_SetTanksLevels(sx,sy);
  local_40.shape = 0x8d;
  sVar2 = (short)sx;
  local_40.x = sVar2 + 0x20;
  sVar3 = (short)sy;
  local_40.y = sVar3 + 0x62;
  Shp_GetWH(&local_40,(short *)&local_30,(short *)local_2e);
  prim_00 = (SHAPE_31fake *)&DAT_800b5bf0;
  do {
    num_power = (int)(short)local_30;
    sVar1 = *(short *)(&DAT_800b1de2 + num_weapon * 8);
    iVar4 = 0;
    prim = prim_00;
    do {
      iVar4 = iVar4 + 1;
      Shp_SetPolyFT4(prim,&local_40,
                     (short)((uint)(((num_power * (int)sVar1) / 100 + 1) * 0x10000) >> 0x10),
                     (short)(((uint)local_2e[0] + 1) * 0x10000 >> 0x10));
      prim->u1 = prim->u1 + '\x01';
      prim->u3 = prim->u3 + '\x01';
      prim->v2 = prim->v2 + '\x01';
      prim->v3 = prim->v3 + '\x01';
      prim = prim + 4;
    } while (iVar4 < 2);
    prim_00 = prim_00 + 1;
    num_weapon = num_weapon + 1;
    local_40.shape = local_40.shape + 1;
    local_40.y = local_40.y + 0xb;
  } while (num_weapon < 4);
  Stats.nb_powerups = '\0';
  local_40.shape = 0x78;
  local_40.y = sVar3 + 0x62;
  Shp_GetWH(&local_40,(short *)&local_30,(short *)local_2e);
  num_weapon = 0;
  do {
    local_40.x = sVar2 + 0x5b;
    num_power = 0;
    do {
      iVar4 = 0;
      iVar5 = 0;
      local_40.shape =
           ((short)((ulonglong)((longlong)num_power * 0x55555556) >> 0x20) -
           (short)(num_power >> 0x1f)) + 0x78;
      do {
        iVar4 = iVar4 + 1;
        prim_00 = (SHAPE_31fake *)
                  ((int)&DAT_800b5fb0 + iVar5 + (uint)(byte)Stats.nb_powerups * 0x28);
        Shp_SetPolyFT4(prim_00,&local_40,(short)(((uint)local_30 + 1) * 0x10000 >> 0x10),
                       (short)(((uint)local_2e[0] + 1) * 0x10000 >> 0x10));
        iVar5 = iVar5 + 0x5a0;
        prim_00->code = prim_00->code & 0xfe;
        Stats_SetPowerColor((char)prim_00,num_power,num_weapon);
        prim_00->u1 = prim_00->u1 + '\x01';
        prim_00->u3 = prim_00->u3 + '\x01';
        prim_00->v2 = prim_00->v2 + '\x01';
        prim_00->v3 = prim_00->v3 + '\x01';
      } while (iVar4 < 2);
      num_power = num_power + 1;
      Stats.nb_powerups = Stats.nb_powerups + '\x01';
      local_40.x = local_40.x + 2;
    } while (num_power < 9);
    num_weapon = num_weapon + 1;
    local_40.y = local_40.y + 0xb;
  } while (num_weapon < 4);
  num_weapon = 0;
  prim_00 = (SHAPE_31fake *)&DAT_800b6af0;
  local_40.shape = 0x77;
  local_40.x = sVar2 + -3;
  local_40.y = sVar3 + 0x5e;
  do {
    num_power = 0;
    prim = prim_00;
    do {
      Shp_SetPolyFT4(prim,&local_40,9,9);
      num_power = num_power + 1;
      prim->code = prim->code & 0xfe;
      prim->u3 = prim->u3 + '\x01';
      prim->u1 = prim->u1 + '\x01';
      prim->v3 = prim->v3 + '\x01';
      prim->v2 = prim->v2 + '\x01';
      prim = prim + 4;
    } while (num_power < 2);
    num_weapon = num_weapon + 1;
    local_40.y = local_40.y + 0xd;
    prim_00 = prim_00 + 1;
  } while (num_weapon < 4);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Stats_SetTanksLevels(long sx /*$a0*/, long sy /*$s0*/)
 // line 369, offset 0x8008ae78
	/* begin block 1 */
		// Start line: 370
		// Start offset: 0x8008AE78
		// Variables:
	// 		long i; // $s2
	// 		long j; // $a3
	// 		long posy; // $s3
	// 		long step; // $t2
	// 		struct STATS_70fake shp; // stack offset -48
	// 		short dummy; // $t1
	// 		short w; // stack offset -32
	// 		short h; // stack offset -30
	/* end block 1 */
	// End offset: 0x8008B3EC
	// End Line: 482

	/* begin block 2 */
		// Start line: 1197
	/* end block 2 */
	// End Line: 1198

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Stats_SetTanksLevels(long sx,long sy)

{
  short sVar1;
  undefined *puVar2;
  short sVar3;
  undefined *puVar4;
  int iVar5;
  SHAPE_31fake *prim;
  int iVar6;
  int iVar7;
  int iVar8;
  SHAPE_68fake local_30;
  ushort local_20;
  short local_1e [3];
  
  local_30.x = (short)sx + 0x1a;
  local_30.shape = 0x97;
  local_30.file = Effects_Pcl;
  Shp_GetWH(&local_30,(short *)&local_20,local_1e);
  iVar6 = 0;
  sVar1 = (short)sy + local_1e[0] + 0x1a;
  prim = (SHAPE_31fake *)&DAT_800b5ab0;
  iVar7 = (int)((int)local_1e[0] * (uint)(_DAT_800b1e38 >> 8)) / 100;
  local_30.y = sVar1 - (short)iVar7;
  do {
    iVar6 = iVar6 + 1;
    Shp_SetPolyFT4(prim,&local_30,(short)(((uint)local_20 + 1) * 0x10000 >> 0x10),
                   (short)((uint)((iVar7 + 1) * 0x10000) >> 0x10));
    prim->u1 = prim->u1 + '\x01';
    prim->u3 = prim->u3 + '\x01';
    prim->v2 = prim->v2 + '\x01';
    prim->v3 = prim->v3 + '\x01';
    prim = prim + 4;
  } while (iVar6 < 2);
  iVar7 = 0;
  puVar2 = &DAT_800b6c30;
  sVar3 = sVar1 - (short)((int)((uint)_DAT_800b1e44 * (int)local_1e[0]) / 100);
  do {
    puVar2[3] = 3;
    puVar2[7] = 0x40;
    *(short *)(puVar2 + 10) = sVar3;
    *(short *)(puVar2 + 8) = local_30.x;
    iVar7 = iVar7 + 1;
    *(short *)(puVar2 + 0xe) = sVar3;
    puVar2[4] = 0xfa;
    puVar2[5] = 0x50;
    puVar2[6] = 0x50;
    *(ushort *)(puVar2 + 0xc) = local_30.x + local_20;
    puVar2 = puVar2 + 0x20;
  } while (iVar7 < 2);
  iVar6 = 0;
  prim = (SHAPE_31fake *)&DAT_800b5ad8;
  local_30.x = local_30.x + 0x13;
  iVar7 = (int)((int)local_1e[0] * (uint)(_DAT_800b1e3a >> 8)) / 100;
  local_30.y = sVar1 - (short)iVar7;
  do {
    iVar6 = iVar6 + 1;
    Shp_SetPolyFT4(prim,&local_30,(short)(((uint)local_20 + 1) * 0x10000 >> 0x10),
                   (short)((uint)((iVar7 + 1) * 0x10000) >> 0x10));
    prim->u1 = prim->u1 + '\x01';
    prim->u3 = prim->u3 + '\x01';
    prim->v2 = prim->v2 + '\x01';
    prim->v3 = prim->v3 + '\x01';
    prim = prim + 4;
  } while (iVar6 < 2);
  iVar7 = (uint)(byte)Stats.nb_levels[(uint)(byte)Stats.num_weapon] + 1;
  if (iVar7 == 0) {
    trap(0x1c00);
  }
  if ((iVar7 == -1) && ((int)local_1e[0] == -0x80000000)) {
    trap(0x1800);
  }
  iVar6 = 0;
  iVar7 = ((int)local_1e[0] / iVar7) * 0x100 + 0x80;
  if (Stats.nb_levels[(uint)(byte)Stats.num_weapon] != 0) {
    puVar2 = &DAT_800b6c70;
    iVar5 = iVar7;
    do {
      iVar8 = 0;
      sVar3 = sVar1 - ((short)iVar5 >> 8);
      puVar4 = puVar2;
      do {
        puVar4[3] = 3;
        puVar4[7] = 0x40;
        *(short *)(puVar4 + 10) = sVar3;
        *(short *)(puVar4 + 8) = local_30.x;
        iVar8 = iVar8 + 1;
        *(short *)(puVar4 + 0xe) = sVar3;
        puVar4[4] = 0xfa;
        puVar4[5] = 200;
        puVar4[6] = 0x32;
        *(ushort *)(puVar4 + 0xc) = local_30.x + local_20;
        puVar4 = puVar4 + 0xa0;
      } while (iVar8 < 2);
      puVar2 = puVar2 + 0x10;
      iVar6 = iVar6 + 1;
      iVar5 = iVar5 + iVar7;
    } while (iVar6 < (int)(uint)(byte)Stats.nb_levels[(uint)(byte)Stats.num_weapon]);
  }
  iVar6 = 0;
  prim = (SHAPE_31fake *)&DAT_800b5b00;
  local_30.x = local_30.x + 0x13;
  iVar7 = (int)((int)local_1e[0] * (uint)(_DAT_800b1e3c >> 8)) / 100;
  local_30.y = sVar1 - (short)iVar7;
  do {
    iVar6 = iVar6 + 1;
    Shp_SetPolyFT4(prim,&local_30,(short)(((uint)local_20 + 1) * 0x10000 >> 0x10),
                   (short)((uint)((iVar7 + 1) * 0x10000) >> 0x10));
    prim->u1 = prim->u1 + '\x01';
    prim->u3 = prim->u3 + '\x01';
    prim->v2 = prim->v2 + '\x01';
    prim->v3 = prim->v3 + '\x01';
    prim = prim + 4;
  } while (iVar6 < 2);
  iVar7 = 0;
  puVar2 = &DAT_800b6c40;
  sVar3 = sVar1 - (short)((int)((uint)_DAT_800b1e48 * (int)local_1e[0]) / 100);
  do {
    puVar2[3] = 3;
    puVar2[7] = 0x40;
    *(short *)(puVar2 + 10) = sVar3;
    *(short *)(puVar2 + 8) = local_30.x;
    iVar7 = iVar7 + 1;
    *(short *)(puVar2 + 0xe) = sVar3;
    puVar2[4] = 0xfa;
    puVar2[5] = 0x50;
    puVar2[6] = 0x50;
    *(ushort *)(puVar2 + 0xc) = local_30.x + local_20;
    puVar2 = puVar2 + 0x20;
  } while (iVar7 < 2);
  iVar6 = 0;
  prim = (SHAPE_31fake *)&DAT_800b5b28;
  local_30.shape = 0x98;
  local_30.x = local_30.x + 0x1a;
  iVar7 = (int)((int)local_1e[0] * (uint)(_DAT_800b1e34 >> 8)) / 0xff;
  local_30.y = sVar1 - (short)iVar7;
  do {
    iVar6 = iVar6 + 1;
    Shp_SetPolyFT4(prim,&local_30,(short)(((uint)local_20 + 1) * 0x10000 >> 0x10),
                   (short)((uint)((iVar7 + 1) * 0x10000) >> 0x10));
    prim->u1 = prim->u1 + '\x01';
    prim->u3 = prim->u3 + '\x01';
    prim->v2 = prim->v2 + '\x01';
    prim->v3 = prim->v3 + '\x01';
    prim = prim + 4;
  } while (iVar6 < 2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Stats_SetHiliteTanks()
 // line 485, offset 0x8008b40c
	/* begin block 1 */
		// Start line: 487
		// Start offset: 0x8008B40C
		// Variables:
	// 		long i; // $a1
	// 		long j; // $a3
	// 		struct STATS_31fake *p; // $v0
	// 		unsigned char col; // $a2
	/* end block 1 */
	// End offset: 0x8008B510
	// End Line: 516

	/* begin block 2 */
		// Start line: 1562
	/* end block 2 */
	// End Line: 1563

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Stats_SetHiliteTanks(void)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uchar uVar6;
  uchar uVar7;
  int iVar8;
  undefined *puVar9;
  int iVar10;
  
  iVar8 = 0;
  iVar10 = -0x7ff4a6e0;
  puVar9 = &DAT_800b5d30;
  do {
    uVar6 = -0x80;
    if ((iVar8 != (int)Stats.carac) || (uVar6 = Shift_Col, uVar7 = -0x80, SHIFT_STATS != 0)) {
      uVar7 = uVar6;
    }
    iVar5 = 0;
    iVar4 = 0;
    iVar3 = 0;
    do {
      puVar1 = puVar9 + iVar3;
      puVar1[4] = uVar7;
      puVar1[5] = 0x80;
      puVar1[6] = 0x80;
      iVar2 = iVar4 + iVar10;
      iVar4 = iVar4 + 200;
      iVar5 = iVar5 + 1;
      *(uchar *)(iVar2 + 4) = uVar7;
      *(undefined *)(iVar2 + 5) = 0x80;
      *(undefined *)(iVar2 + 6) = 0x80;
      iVar3 = iVar3 + 0x140;
    } while (iVar5 < 2);
    iVar10 = iVar10 + 0x28;
    iVar8 = iVar8 + 1;
    puVar9 = puVar9 + 0x28;
  } while (iVar8 < 3);
  uVar6 = -0x80;
  if (SHIFT_STATS != 0) {
    uVar6 = Shift_Col;
  }
  iVar3 = 0;
  iVar10 = 0;
  iVar8 = 0;
  do {
    (&DAT_800b5dac)[iVar10] = 0x80;
    (&DAT_800b5dad)[iVar10] = uVar6;
    (&DAT_800b5dae)[iVar10] = 0x80;
    iVar3 = iVar3 + 1;
    (&Stats.symboles.r0)[iVar8] = -0x80;
    (&Stats.symboles.g0)[iVar8] = uVar6;
    (&Stats.symboles.b0)[iVar8] = -0x80;
    iVar10 = iVar10 + 0x140;
    iVar8 = iVar8 + 200;
  } while (iVar3 < 2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Stats_SetPowerColor(struct STATS_31fake *p /*$a0*/, long num_power /*$a1*/, long num_weapon /*$a2*/)
 // line 519, offset 0x8008b518
	/* begin block 1 */
		// Start line: 521
		// Start offset: 0x8008B518
		// Variables:
	// 		long max_power; // $a3
	// 		long coef; // $v1
	/* end block 1 */
	// End offset: 0x8008B5A8
	// End Line: 552

	/* begin block 2 */
		// Start line: 1652
	/* end block 2 */
	// End Line: 1653

/* WARNING: Removing unreachable block (ram,0x8008b574) */

void Stats_SetPowerColor(undefined p,long num_power,long num_weapon)

{
  undefined uVar1;
  int iVar2;
  undefined3 in_register_00000011;
  int iVar3;
  
  iVar3 = CONCAT31(in_register_00000011,p);
  iVar2 = (int)*(short *)(&DAT_800b1de8 + num_weapon * 8);
  if ((int)(char)(&DAT_800b1de4)[num_weapon * 8] < num_power) {
    if (iVar2 == 0) {
      iVar2 = 10;
    }
    if (iVar2 == 0) {
      trap(0x1c00);
    }
    uVar1 = 0x32;
    if (100 / iVar2 <= num_power) {
      *(undefined *)(iVar3 + 4) = 0xfa;
      *(undefined *)(iVar3 + 5) = 0;
      *(undefined *)(iVar3 + 6) = 0;
      return;
    }
  }
  else {
    uVar1 = 0xff;
  }
  *(undefined *)(iVar3 + 4) = uVar1;
  *(undefined *)(iVar3 + 5) = uVar1;
  *(undefined *)(iVar3 + 6) = uVar1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Stats_Display()
 // line 555, offset 0x8008b5b0
	/* begin block 1 */
		// Start line: 556
		// Start offset: 0x8008B5B0
		// Variables:
	// 		long i; // $a2
	// 		struct STATS_31fake *p; // $a3
	// 		struct STATS_36fake *pl; // $a3
	/* end block 1 */
	// End offset: 0x8008BC80
	// End Line: 647

	/* begin block 2 */
		// Start line: 1737
	/* end block 2 */
	// End Line: 1738

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Stats_Display(void)

{
  bool bVar1;
  uchar uVar2;
  _SCREEN *p_Var3;
  _SCREEN *p_Var4;
  int iVar5;
  char *text;
  ulong *puVar6;
  short x;
  undefined *puVar7;
  undefined *puVar8;
  int iVar9;
  int iVar10;
  _struct_701 *p_Var11;
  uint *puVar12;
  
  uVar2 = Shift_Col;
  if ((_DAT_800b1c56 & 8) != 0) {
    return;
  }
  if (SHIFT_STATS == 0) {
    puVar12 = (uint *)(&DAT_800b6af0 + (int)Scr_Frame * 0xa0 + (uint)(byte)Stats.num_weapon * 0x28);
    *(undefined *)((int)puVar12 + 5) = 0x80;
    *(undefined *)((int)puVar12 + 6) = 0x80;
    *(uchar *)(puVar12 + 1) = uVar2;
    p_Var3 = Scr;
    *puVar12 = *puVar12 & 0xff000000 | Scr->ot[1] & 0xffffff;
    p_Var3->ot[1] = p_Var3->ot[1] & 0xff000000 | (uint)puVar12 & 0xffffff;
    goto LAB_8008b6fc;
  }
  if (Stats.carac == 1) {
    text = (char *)Pvl_UtilityTexts[0x22];
    x = 0xe1;
  }
  else {
    if (Stats.carac < 2) {
      if (Stats.carac != 0) goto LAB_8008b6fc;
      text = (char *)Pvl_UtilityTexts[0x21];
      x = 0xd2;
    }
    else {
      x = 0xfa;
      if (Stats.carac != 2) goto LAB_8008b6fc;
      text = (char *)Pvl_UtilityTexts[0x14];
    }
  }
  Text_SetText(text,x,0x19);
LAB_8008b6fc:
  p_Var3 = Scr;
  if (_DAT_800b1e44 < 100) {
    puVar12 = (uint *)(&DAT_800b6c30 + (int)Scr_Frame * 0x20);
    *puVar12 = *puVar12 & 0xff000000 | Scr->ot[1] & 0xffffff;
    p_Var3->ot[1] = p_Var3->ot[1] & 0xff000000 | (uint)puVar12 & 0xffffff;
  }
  p_Var3 = Scr;
  if (_DAT_800b1e48 < 100) {
    puVar12 = (uint *)(&DAT_800b6c40 + (int)Scr_Frame * 0x20);
    *puVar12 = *puVar12 & 0xff000000 | Scr->ot[1] & 0xffffff;
    p_Var3->ot[1] = p_Var3->ot[1] & 0xff000000 | (uint)puVar12 & 0xffffff;
  }
  p_Var3 = Scr;
  iVar9 = 0;
  if (Stats.nb_levels[(uint)(byte)Stats.num_weapon] != '\0') {
    puVar7 = &DAT_800b6c70;
    iVar5 = (int)Scr_Frame;
    do {
      puVar12 = (uint *)(puVar7 + iVar5 * 0xa0);
      *puVar12 = *puVar12 & 0xff000000 | p_Var3->ot[1] & 0xffffff;
      puVar6 = p_Var3->ot;
      puVar6[1] = puVar6[1] & 0xff000000 | (uint)puVar12 & 0xffffff;
      iVar9 = iVar9 + 1;
      puVar7 = puVar7 + 0x10;
    } while (iVar9 < (int)(uint)(byte)Stats.nb_levels[(uint)(byte)Stats.num_weapon]);
  }
  p_Var3 = Scr;
  iVar9 = 0;
  puVar12 = &DAT_800b5fb0 + (int)Scr_Frame * 0x168;
  if (Stats.nb_powerups != '\0') {
    do {
      *puVar12 = *puVar12 & 0xff000000 | p_Var3->ot[1] & 0xffffff;
      puVar6 = p_Var3->ot;
      iVar9 = iVar9 + 1;
      puVar6[1] = puVar6[1] & 0xff000000 | (uint)puVar12 & 0xffffff;
      puVar12 = puVar12 + 10;
    } while (iVar9 < (int)(uint)(byte)Stats.nb_powerups);
  }
  p_Var3 = Scr;
  iVar9 = 0;
  puVar12 = (uint *)(&DAT_800b5ab0 + (int)Scr_Frame * 0xa0);
  do {
    iVar9 = iVar9 + 1;
    *puVar12 = *puVar12 & 0xff000000 | p_Var3->ot[1] & 0xffffff;
    puVar6 = p_Var3->ot;
    puVar6[1] = puVar6[1] & 0xff000000 | (uint)puVar12 & 0xffffff;
    p_Var4 = Scr;
    puVar12 = puVar12 + 10;
  } while (iVar9 < 4);
  iVar9 = 0;
  puVar12 = (uint *)(&DAT_800b5bf0 + (int)Scr_Frame * 0xa0);
  do {
    iVar9 = iVar9 + 1;
    *puVar12 = *puVar12 & 0xff000000 | p_Var4->ot[1] & 0xffffff;
    puVar6 = p_Var4->ot;
    puVar6[1] = puVar6[1] & 0xff000000 | (uint)puVar12 & 0xffffff;
    p_Var3 = Scr;
    puVar12 = puVar12 + 10;
  } while (iVar9 < 4);
  iVar9 = 0;
  p_Var11 = &Stats.fond_jauge + (int)Scr_Frame * 5;
  do {
    iVar9 = iVar9 + 1;
    p_Var11->tag = p_Var11->tag & 0xff000000 | p_Var3->ot[1] & 0xffffff;
    puVar6 = p_Var3->ot;
    puVar6[1] = puVar6[1] & 0xff000000 | (uint)p_Var11 & 0xffffff;
    p_Var4 = Scr;
    p_Var11 = p_Var11 + 1;
  } while (iVar9 < 5);
  iVar9 = 0;
  puVar12 = (uint *)(&DAT_800b5d30 + (int)Scr_Frame * 0x140);
  do {
    iVar9 = iVar9 + 1;
    *puVar12 = *puVar12 & 0xff000000 | p_Var4->ot[1] & 0xffffff;
    puVar6 = p_Var4->ot;
    puVar6[1] = puVar6[1] & 0xff000000 | (uint)puVar12 & 0xffffff;
    p_Var3 = Scr;
    puVar12 = puVar12 + 10;
  } while (iVar9 < 5);
  iVar10 = 0;
  puVar7 = &DAT_800b6db0;
  iVar5 = (int)Scr_Frame;
  iVar9 = iVar5 * 0x40;
  do {
    puVar8 = puVar7 + iVar5 * 0x40;
    puVar7 = puVar7 + 0x10;
    *(uint *)(&DAT_800b6db0 + iVar9) =
         *(uint *)(&DAT_800b6db0 + iVar9) & 0xff000000 | p_Var3->ot[1] & 0xffffff;
    puVar6 = p_Var3->ot;
    iVar10 = iVar10 + 1;
    puVar6[1] = puVar6[1] & 0xff000000 | (uint)puVar8 & 0xffffff;
    p_Var4 = Scr;
    iVar9 = iVar9 + 0x10;
  } while (iVar10 < 4);
  iVar9 = (int)Scr_Frame;
  puVar12 = (uint *)(&DAT_800b6e30 + iVar9 * 0x18);
  *puVar12 = *puVar12 & 0xff000000 | Scr->ot[1] & 0xffffff;
  bVar1 = SHIFT_STATS == 0;
  p_Var4->ot[1] = p_Var4->ot[1] & 0xff000000 | (uint)puVar12 & 0xffffff;
  if (bVar1) {
    puVar7 = &DAT_800b6e60;
  }
  else {
    puVar7 = &DAT_800b6e70;
  }
  puVar12 = (uint *)(puVar7 + iVar9 * 8);
  *puVar12 = *puVar12 & 0xff000000 | p_Var4->ot[1] & 0xffffff;
  p_Var4->ot[1] = p_Var4->ot[1] & 0xff000000 | (uint)puVar12 & 0xffffff;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Stats_Task()
 // line 650, offset 0x8008bc90
	/* begin block 1 */
		// Start line: 651
		// Start offset: 0x8008BC90
		// Variables:
	// 		long i; // $a2
	// 		long run; // $s3
	// 		long trig; // $s0
	// 		long BorneMax; // $a0
	// 		long SOUND_JAUGE; // $s1
	// 		unsigned short exp; // $a2
	// 		unsigned short ExpCoef; // $s5
	// 		struct STATS_104fake t; // stack offset -64

		/* begin block 1.1 */
			// Start line: 759
			// Start offset: 0x8008BFB8
			// Variables:
		// 		long dummy; // $a1
		/* end block 1.1 */
		// End offset: 0x8008C168
		// End Line: 800

		/* begin block 1.2 */
			// Start line: 894
			// Start offset: 0x8008C450
			// Variables:
		// 		long event; // $s1
		/* end block 1.2 */
		// End offset: 0x8008C534
		// End Line: 923
	/* end block 1 */
	// End offset: 0x8008C544
	// End Line: 927

	/* begin block 2 */
		// Start line: 1959
	/* end block 2 */
	// End Line: 1960

/* WARNING: Removing unreachable block (ram,0x8008bd5c) */
/* WARNING: Removing unreachable block (ram,0x8008bff8) */
/* WARNING: Removing unreachable block (ram,0x8008c008) */
/* WARNING: Removing unreachable block (ram,0x8008c010) */
/* WARNING: Removing unreachable block (ram,0x8008c084) */
/* WARNING: Removing unreachable block (ram,0x8008c094) */
/* WARNING: Removing unreachable block (ram,0x8008c09c) */
/* WARNING: Removing unreachable block (ram,0x8008c108) */
/* WARNING: Removing unreachable block (ram,0x8008c118) */
/* WARNING: Removing unreachable block (ram,0x8008c120) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Stats_Task(void)

{
  bool bVar1;
  bool bVar2;
  TASK *pTVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  uint uVar7;
  int iVar8;
  _STATS *p_Var9;
  undefined *puVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  undefined auStack64 [32];
  
  Text_SetContext((TEXT_102fake *)auStack64);
  Text_SetContextFont(0x70);
  Text_SetContextXY(0,0);
  Text_SetContextWH(Scr_W,Scr_H);
  Text_SetContextRange(1);
  Text_SetContextMode(0);
  iVar11 = 0;
  p_Var9 = &Stats;
  puVar10 = &Player;
  Stats.carac = 0;
  do {
    iVar8 = (int)*(short *)(puVar10 + 0x1b0);
    if (iVar8 < 10) {
      p_Var9->nb_levels[0] = '\n';
    }
    else {
      if (iVar8 == 0) {
        trap(0x1c00);
      }
      p_Var9->nb_levels[0] = (char)(100 / iVar8) + -1;
    }
    pTVar3 = TaskCurrent;
    p_Var9 = (_STATS *)((int)&p_Var9->x + 1);
    iVar11 = iVar11 + 1;
    puVar10 = puVar10 + 8;
  } while (iVar11 < 4);
  TaskCurrent->display = (_func_11 *)0x0;
  pTVar3->enable = 0;
  Task_Next();
  TaskCurrent->display = Stats_Display;
  do {
    uVar13 = 0;
    if (Inventaire.moving == '\0') {
      uVar7 = Joy_ReadLog(0);
      uVar13 = Joy_ReadTrig(0);
    }
    else {
      uVar7 = 0;
    }
    if ((uVar13 & 2) != 0) {
      SHIFT_STATS = SHIFT_STATS ^ 1;
      C_Armor = _DAT_800b1e38;
      C_Weapons = _DAT_800b1e3a;
      C_Spells = _DAT_800b1e3c;
      C_Exp = _DAT_800b1e34;
      Fx_Play(0x40,100);
      Stats_SetHilite(SHIFT_STATS);
      Stats_SetHiliteTanks();
    }
    if (Pvl_Pause == 0) {
      if (LifeHandle == (TASK *)0x0) {
        Stats_LifeDisplay((int)Stats.lifeX,0x1e,(char)Scr_Frame * '(' + '0');
      }
      else {
        Task_Kill(LifeHandle);
      }
    }
    if (SHIFT_STATS == 0) {
      uVar7 = Task_EventRead(TaskCurrent);
      if ((uVar13 & 0x4000) != 0) {
        Fx_Play(0x40,100);
        bVar2 = Stats.num_weapon == '\x03';
        Stats.num_weapon = Stats.num_weapon + '\x01';
        if (bVar2) {
          Stats.num_weapon = '\0';
        }
        Stats_SetTanks(200,0x14);
      }
      if ((uVar13 & 0x1000) != 0) {
        Fx_Play(0x40,100);
        bVar2 = Stats.num_weapon == '\0';
        Stats.num_weapon = Stats.num_weapon + -1;
        if (bVar2) {
          Stats.num_weapon = '\x03';
        }
        Stats_SetTanks(200,0x14);
      }
      if ((uVar7 & 1) != 0) {
        Stats_DisplaySpiritLevel(TaskCurrent->event_param);
      }
      if ((uVar7 & 2) != 0) {
        Stats_DisplayWeaponLevel(TaskCurrent->event_param);
      }
      Stats_StopSound();
    }
    else {
      bVar2 = false;
      if ((uVar13 & 0x8000) != 0) {
        Fx_Play(0x40,100);
        Shift_Col = -1;
        bVar1 = Stats.carac == 0;
        Stats.carac = Stats.carac + -1;
        if (bVar1) {
          Stats.carac = 2;
        }
      }
      if ((uVar13 & 0x2000) != 0) {
        Fx_Play(0x40,100);
        Shift_Col = -1;
        bVar1 = Stats.carac == 2;
        Stats.carac = Stats.carac + 1;
        if (bVar1) {
          Stats.carac = 0;
        }
      }
      if ((uVar13 & 0x10) != 0) {
        _DAT_800b1e38 = C_Armor;
        _DAT_800b1e3a = C_Weapons;
        _DAT_800b1e3c = C_Spells;
        _DAT_800b1e34 = C_Exp;
        Stats_SetTanks(200,0x14);
      }
      if (((uVar13 & 0x40) != 0) && (_DAT_800b1e34 != 0)) {
        uVar12 = (uint)_DAT_800b1e34 / 3;
        iVar8 = (int)(uVar12 * (uint)_DAT_800b1e3e) / 0xa00;
        _DAT_800b1e34 = 0;
        iVar11 = (uint)_DAT_800b1e38 + iVar8;
        if ((int)((uint)_DAT_800b1e44 << 8) < iVar11) {
          _DAT_800b1e38 = (ushort)((uint)_DAT_800b1e44 << 8);
          uVar12 = uVar12 + iVar8;
        }
        else {
          _DAT_800b1e38 = (ushort)iVar11;
        }
        iVar8 = (int)((uVar12 & 0xffff) * (uint)_DAT_800b1e42) / 0xa00;
        iVar11 = (uint)_DAT_800b1e3c + iVar8;
        if ((int)((uint)_DAT_800b1e48 << 8) < iVar11) {
          _DAT_800b1e3c = (ushort)((uint)_DAT_800b1e48 << 8);
          uVar12 = uVar12 + iVar8;
        }
        else {
          _DAT_800b1e3c = (ushort)iVar11;
        }
        iVar11 = (uint)_DAT_800b1e3a + (int)((uVar12 & 0xffff) * (uint)_DAT_800b1e40) / 0xa00;
        if (iVar11 < 0x6401) {
          _DAT_800b1e3a = (ushort)iVar11;
        }
        else {
          _DAT_800b1e3a = 0x6400;
        }
        Stats_SetTanks(200,0x14);
      }
      if (((uVar7 & 0x1000) != 0) && (_DAT_800b1e34 != 0)) {
        if (Stats.carac == 1) {
          if ((_DAT_800b1e40 != 0) &&
             (uVar4 = _DAT_800b1e38, uVar5 = _DAT_800b1e3a + _DAT_800b1e40, uVar6 = _DAT_800b1e3c,
             _DAT_800b1e3a >> 8 < 100)) goto LAB_8008c284;
LAB_8008c298:
          if ((uVar13 & 0x1000) != 0) {
            Task_EventExec(DAT_800b3f0c,1,0);
          }
        }
        else {
          if (Stats.carac < 2) {
            if (Stats.carac == 0) {
              if ((_DAT_800b1e3e == 0) ||
                 (uVar4 = _DAT_800b1e38 + _DAT_800b1e3e, uVar5 = _DAT_800b1e3a,
                 uVar6 = _DAT_800b1e3c, _DAT_800b1e44 <= _DAT_800b1e38 >> 8)) goto LAB_8008c298;
LAB_8008c284:
              _DAT_800b1e3c = uVar6;
              _DAT_800b1e3a = uVar5;
              _DAT_800b1e38 = uVar4;
              Stats_DecExperience((_PLAYER *)&Player,0xa00);
              bVar2 = true;
            }
          }
          else {
            if (Stats.carac == 2) {
              if ((_DAT_800b1e42 == 0) ||
                 (uVar4 = _DAT_800b1e38, uVar5 = _DAT_800b1e3a,
                 uVar6 = _DAT_800b1e3c + _DAT_800b1e42, _DAT_800b1e48 <= _DAT_800b1e3c >> 8))
              goto LAB_8008c298;
              goto LAB_8008c284;
            }
          }
        }
        Stats_SetTanks(200,0x14);
      }
      if ((uVar7 & 0x4000) != 0) {
        if (Stats.carac == 1) {
          if ((uint)C_Weapons < (uint)_DAT_800b1e3a) {
            iVar11 = (uint)_DAT_800b1e3a - (uint)_DAT_800b1e40;
            _DAT_800b1e3a = C_Weapons;
            if ((int)(uint)C_Weapons < iVar11) {
              _DAT_800b1e3a = (ushort)iVar11;
            }
            goto LAB_8008c3e8;
          }
        }
        else {
          if (Stats.carac < 2) {
            if ((Stats.carac == 0) && ((uint)C_Armor < (uint)_DAT_800b1e38)) {
              iVar11 = (uint)_DAT_800b1e38 - (uint)_DAT_800b1e3e;
              _DAT_800b1e38 = C_Armor;
              if ((int)(uint)C_Armor < iVar11) {
                _DAT_800b1e38 = (ushort)iVar11;
              }
LAB_8008c3e8:
              Stats_IncExperience((_PLAYER *)&Player,0xa00);
              bVar2 = true;
            }
          }
          else {
            if ((Stats.carac == 2) && ((uint)C_Spells < (uint)_DAT_800b1e3c)) {
              iVar11 = (uint)_DAT_800b1e3c - (uint)_DAT_800b1e42;
              _DAT_800b1e3c = C_Spells;
              if ((int)(uint)C_Spells < iVar11) {
                _DAT_800b1e3c = (ushort)iVar11;
              }
              goto LAB_8008c3e8;
            }
          }
        }
        Stats_SetTanks(200,0x14);
      }
      if (bVar2) {
        if (Stats.fx_handle == -1) {
          Stats.fx_handle = Fx_Play(0x3a,100);
        }
      }
      else {
        Stats_StopSound();
      }
      Stats_SetHiliteTanks();
    }
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Stats_StopSound()
 // line 930, offset 0x8008c544
	/* begin block 1 */
		// Start line: 2580
	/* end block 1 */
	// End Line: 2581

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Stats_StopSound(void)

{
  if (-1 < (int)Stats.fx_handle) {
    Sound_Stop((int)Stats.fx_handle,0);
    Stats.fx_handle = -1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Stats_Appear()
 // line 940, offset 0x8008c588
	/* begin block 1 */
		// Start line: 2602
	/* end block 1 */
	// End Line: 2603

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Stats_Appear(void)

{
  Task_Add(Stats_AppearTask,0x200);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Stats_AppearTask()
 // line 945, offset 0x8008c5b0
	/* begin block 1 */
		// Start line: 946
		// Start offset: 0x8008C5B0
		// Variables:
	// 		long nbf; // $s2
	// 		long Off_X; // $s4
	// 		long LifeStep; // $s3
	/* end block 1 */
	// End offset: 0x8008C680
	// End Line: 978

	/* begin block 2 */
		// Start line: 2613
	/* end block 2 */
	// End Line: 2614

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Stats_AppearTask(void)

{
  int sx;
  int iVar1;
  short sVar2;
  
  iVar1 = 0x12;
  sVar2 = 6;
  Stats.lifeX = -100;
  if (LifeHandle != (TASK *)0x0) {
    Stats.lifeX = 0x14;
    sVar2 = 0;
    Task_Kill(LifeHandle);
    Task_Next();
  }
  *(undefined2 *)(DAT_800b6e80 + 0x54) = 1;
  *(undefined4 *)(DAT_800b6e80 + 0x20) = 0x8008b5b0;
  Stats.num_weapon = '\0';
  if (DAT_800b1de1 < '\x04') {
    Stats.num_weapon = DAT_800b1de1;
  }
  sx = 0x146;
  do {
    Stats_PrepareDisplay(sx,0x14);
    sx = sx + -7;
    iVar1 = iVar1 + -1;
    Stats.lifeX = Stats.lifeX + sVar2;
    Task_Next();
  } while (-1 < iVar1);
  Stats.lifeX = 0x14;
  Task_Next();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Stats_Disappear()
 // line 984, offset 0x8008c6b0
	/* begin block 1 */
		// Start line: 2706
	/* end block 1 */
	// End Line: 2707

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Stats_Disappear(void)

{
  Task_Add(Stats_DisappearTask,0x200);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Stats_DisappearTask()
 // line 989, offset 0x8008c6d8
	/* begin block 1 */
		// Start line: 990
		// Start offset: 0x8008C6D8
		// Variables:
	// 		long nbf; // $s1
	// 		long Off_X; // $s3
	/* end block 1 */
	// End offset: 0x8008C748
	// End Line: 1009

	/* begin block 2 */
		// Start line: 2717
	/* end block 2 */
	// End Line: 2718

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Stats_DisappearTask(void)

{
  int sx;
  int iVar1;
  
  iVar1 = 0;
  Stats_StopSound();
  SHIFT_STATS = 0;
  Stats_SetHilite(0);
  sx = 200;
  Stats_SetHiliteTanks();
  do {
    Stats_PrepareDisplay(sx,0x14);
    sx = sx + 7;
    iVar1 = iVar1 + 1;
    Stats.lifeX = Stats.lifeX + -6;
    Task_Next();
  } while (iVar1 < 0x13);
  *(undefined4 *)(DAT_800b6e80 + 0x20) = 0;
  *(undefined2 *)(DAT_800b6e80 + 0x54) = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Stats_IncExperience(struct _PLAYER *pl /*$a0*/, short coef /*$a1*/)
 // line 1014, offset 0x8008c784
	/* begin block 1 */
		// Start line: 1016
		// Start offset: 0x8008C784
		// Variables:
	// 		long BorneMax; // $a2
	/* end block 1 */
	// End offset: 0x8008C7AC
	// End Line: 1022

	/* begin block 2 */
		// Start line: 2774
	/* end block 2 */
	// End Line: 2775

void Stats_IncExperience(_PLAYER *pl,short coef)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)((pl->env2).Obj.primitive_top.Data + 0xc);
  if (0xff00 < (int)((uint)uVar1 + (int)coef)) {
    *(undefined2 *)((pl->env2).Obj.primitive_top.Data + 0xc) = 0xff00;
    return;
  }
  *(ushort *)((pl->env2).Obj.primitive_top.Data + 0xc) = uVar1 + coef;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Stats_DecExperience(struct _PLAYER *pl /*$a0*/, short coef /*$a1*/)
 // line 1025, offset 0x8008c7b4
	/* begin block 1 */
		// Start line: 2796
	/* end block 1 */
	// End Line: 2797

void Stats_DecExperience(_PLAYER *pl,short coef)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)((pl->env2).Obj.primitive_top.Data + 0xc);
  if ((int)((uint)uVar1 - (int)coef) < 0) {
    *(undefined2 *)((pl->env2).Obj.primitive_top.Data + 0xc) = 0;
    return;
  }
  *(ushort *)((pl->env2).Obj.primitive_top.Data + 0xc) = uVar1 - coef;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Stats_DisplayWeaponLevel(long level /*$s0*/)
 // line 1039, offset 0x8008c7dc
	/* begin block 1 */
		// Start line: 2823
	/* end block 1 */
	// End Line: 2824

void Stats_DisplayWeaponLevel(long level)

{
  if (Stats_Spirit != (TASK *)0x0) {
    Task_Kill(Stats_Spirit);
  }
  Stats_Spirit = Task_Link(Stats_SpiritLevelTask,0x100);
  *(long *)&Stats_Spirit->local = level;
  Stats_Spirit->s0 = 2;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Stats_DisplaySpiritLevel(long level /*$s0*/)
 // line 1049, offset 0x8008c830
	/* begin block 1 */
		// Start line: 2846
	/* end block 1 */
	// End Line: 2847

void Stats_DisplaySpiritLevel(long level)

{
  if (Stats_Spirit != (TASK *)0x0) {
    Task_Kill(Stats_Spirit);
  }
  Stats_Spirit = Task_Link(Stats_SpiritLevelTask,0x100);
  *(long *)&Stats_Spirit->local = level;
  Stats_Spirit->s0 = 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Stats_SpiritLevelTask()
 // line 1059, offset 0x8008c884
	/* begin block 1 */
		// Start line: 1060
		// Start offset: 0x8008C884
		// Variables:
	// 		long level; // $s0
	// 		long mode; // $s3
	// 		long save_weapon; // $s4
	// 		long cpt; // $s0
	// 		struct STATS_36fake prims[2]; // stack offset -56
	/* end block 1 */
	// End offset: 0x8008C9B4
	// End Line: 1103

	/* begin block 2 */
		// Start line: 2869
	/* end block 2 */
	// End Line: 2870

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Stats_SpiritLevelTask(void)

{
  TASK *pTVar1;
  char cVar2;
  _SCREEN *p_Var3;
  long lVar4;
  uint *puVar5;
  void *pvVar6;
  uint uVar7;
  uint mode;
  char unaff_s4;
  uint auStack56 [8];
  
  pTVar1 = TaskCurrent;
  TaskCurrent->destructor = Stats_SpiritLevelDestructor;
  cVar2 = Stats.num_weapon;
  mode = pTVar1->s0;
  pvVar6 = pTVar1->local;
  if (mode == 2) {
    Stats.num_weapon = (char)((uint)pvVar6 >> 0x10);
    Stats_SetTanks(200,0x14);
    unaff_s4 = cVar2;
  }
  Stats_SpiritLevelInit((uint)pvVar6 & 0xffff,200,mode);
  uVar7 = 0x31;
  do {
    lVar4 = Joy_ReadTrigAll();
    p_Var3 = Scr;
    if ((lVar4 != 0) || (Inventaire.moving != '\0')) break;
    if ((uVar7 & 4) == 0) {
      puVar5 = auStack56 + (int)Scr_Frame * 4;
      *puVar5 = *puVar5 & 0xff000000 | *Scr->ot & 0xffffff;
      *p_Var3->ot = *p_Var3->ot & 0xff000000 | (uint)puVar5 & 0xffffff;
    }
    uVar7 = uVar7 - 1;
    Task_Next();
  } while (uVar7 != 0xffffffff);
  if ((mode & 2) != 0) {
    Stats.num_weapon = unaff_s4;
    Stats_SetTanks(200,0x14);
  }
  Task_Sleep(2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Stats_SpiritLevelInit(long level /*$s2*/, struct STATS_36fake *prims /*$a1*/, long mode /*$s0*/)
 // line 1106, offset 0x8008c9dc
	/* begin block 1 */
		// Start line: 1107
		// Start offset: 0x8008C9DC
		// Variables:
	// 		long i; // $a0
	// 		long height; // $v0
	// 		long posx; // $a2
	// 		long posy; // $t1
	// 		short w; // stack offset -24
	// 		short h; // stack offset -22
	// 		struct STATS_36fake *l; // $s1
	// 		struct STATS_70fake shp; // stack offset -40
	/* end block 1 */
	// End offset: 0x8008CAE4
	// End Line: 1138

	/* begin block 2 */
		// Start line: 2990
	/* end block 2 */
	// End Line: 2991

void Stats_SpiritLevelInit(long level,undefined prims,long mode)

{
  short sVar1;
  int iVar2;
  undefined3 in_register_00000015;
  undefined *puVar3;
  short sVar4;
  SHAPE_68fake local_28;
  short local_18;
  short local_16 [3];
  
  local_28.shape = 0x97;
  local_28.file = Effects_Pcl;
  Shp_GetWH(&local_28,&local_18,local_16);
  sVar4 = Stats.x + 0x2d;
  if (mode == 1) {
    sVar4 = Stats.x + 0x40;
  }
  iVar2 = 0;
  puVar3 = (undefined *)(CONCAT31(in_register_00000015,prims) + 6);
  sVar1 = (Stats.y + local_16[0] + 0x1a) - (short)((level * (int)local_16[0]) / 100);
  do {
    puVar3[-3] = 3;
    puVar3[1] = 0x40;
    *(short *)(puVar3 + 2) = sVar4;
    *(short *)(puVar3 + 4) = sVar1;
    *(short *)(puVar3 + 8) = sVar1;
    *(short *)(puVar3 + 6) = local_18 + sVar4;
    if (mode == 2) {
      puVar3[-2] = 0xfa;
      puVar3[-1] = 0x32;
    }
    else {
      puVar3[-2] = 0xfa;
      puVar3[-1] = 200;
    }
    *puVar3 = 0x32;
    iVar2 = iVar2 + 1;
    puVar3 = puVar3 + 0x10;
  } while (iVar2 < 2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Stats_SpiritLevelDestructor(struct TASK *t /*$a0*/)
 // line 1140, offset 0x8008cafc
	/* begin block 1 */
		// Start line: 3101
	/* end block 1 */
	// End Line: 3102

void Stats_SpiritLevelDestructor(TASK *t)

{
  Stats_Spirit = (TASK *)0x0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Stats_LifeAppear()
 // line 1152, offset 0x8008cb08
	/* begin block 1 */
		// Start line: 3125
	/* end block 1 */
	// End Line: 3126

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Stats_LifeAppear(void)

{
  if (_DAT_800b1e30 != 0) {
    if (LifeHandle != (TASK *)0x0) {
      Task_Kill(LifeHandle);
    }
    LifeHandle = Task_Link(Stats_LifeTask,0x100);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Stats_LifeTask()
 // line 1164, offset 0x8008cb58
	/* begin block 1 */
		// Start line: 1165
		// Start offset: 0x8008CB58
		// Variables:
	// 		long i; // $s0
	// 		long cpt; // $s2
	// 		long posx; // $s1
	// 		long posy; // $s3
	// 		struct STATS_104fake t; // stack offset -64
	/* end block 1 */
	// End offset: 0x8008CD10
	// End Line: 1212

	/* begin block 2 */
		// Start line: 3149
	/* end block 2 */
	// End Line: 3150

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Stats_LifeTask(void)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int posx;
  int posx_00;
  int iVar4;
  undefined auStack64 [32];
  
  iVar4 = 0;
  iVar3 = 0x14;
  TaskCurrent->destructor = Stats_LifeDestructor;
  Text_SetContext((TEXT_102fake *)auStack64);
  Text_SetContextFont(0x70);
  Text_SetContextXY(0,0);
  Text_SetContextWH(Scr_W,Scr_H);
  Text_SetContextRange(0);
  Text_SetContextMode(0);
  posx = -100;
  do {
    posx_00 = posx + 6;
    iVar3 = iVar3 + -1;
    Stats_LifeDisplay(posx,0x1e,(char)Scr_Frame * '(' + '0');
    Task_Next();
    posx = posx_00;
  } while (iVar3 != 0);
  posx = 0x50;
  do {
    posx = posx + -1;
    Stats_LifeDisplay(posx_00,0x1e,(char)Scr_Frame * '(' + '0');
    Task_Next();
  } while (posx != 0);
  do {
    bVar1 = iVar4 == 10;
    bVar2 = iVar4 < 5;
    if (bVar1) {
      iVar4 = 0;
    }
    if (bVar1 || bVar2) {
      Stats_LifeDisplay(posx_00,0x1e,(char)Scr_Frame * '(' + '0');
    }
    posx = posx + 1;
    Task_Next();
    iVar4 = iVar4 + 1;
  } while (posx < 0x1e);
  posx = 0;
  do {
    posx = posx + 1;
    Stats_LifeDisplay(posx_00,0x1e,(char)Scr_Frame * '(' + '0');
    Task_Next();
    posx_00 = posx_00 + -6;
  } while (posx < 0x14);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Stats_LifeDisplay(long posx /*$s2*/, long posy /*$s3*/, struct STATS_31fake *pft4 /*$s1*/)
 // line 1215, offset 0x8008cd34
	/* begin block 1 */
		// Start line: 1216
		// Start offset: 0x8008CD34
		// Variables:
	// 		short w; // stack offset -32
	// 		short h; // stack offset -30
	// 		char str[8]; // stack offset -56
	// 		struct STATS_70fake shp; // stack offset -48
	/* end block 1 */
	// End offset: 0x8008CD6C
	// End Line: 1227

	/* begin block 2 */
		// Start line: 3315
	/* end block 2 */
	// End Line: 3316

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Stats_LifeDisplay(long posx,long posy,undefined pft4)

{
  _SCREEN *p_Var1;
  undefined3 in_register_00000019;
  SHAPE_31fake *prim;
  char acStack56 [8];
  SHAPE_68fake local_30;
  short local_20;
  short local_1e [3];
  
  prim = (SHAPE_31fake *)CONCAT31(in_register_00000019,pft4);
  local_20 = (short)((int)_DAT_800b1e30 + -1);
  if ((int)_DAT_800b1e30 + -1 < 0) {
    local_20 = 0;
  }
  sprintf(acStack56,&DAT_800ada98,(int)local_20);
  Text_SetText(acStack56,(short)((uint)((posx + 0x28) * 0x10000) >> 0x10),
               (short)((uint)((posy + 0x14) * 0x10000) >> 0x10));
  local_30.shape = 0;
  local_30.file = Pl_Pcl;
  Shp_GetWH(&local_30,&local_20,local_1e);
  local_30.x = (short)posx;
  local_30.y = (short)posy;
  Shp_SetPolyFT4(prim,&local_30,local_20,local_1e[0]);
  p_Var1 = Scr;
  prim->tag = prim->tag & 0xff000000 | *Scr->ot & 0xffffff;
  *p_Var1->ot = *p_Var1->ot & 0xff000000 | (uint)prim & 0xffffff;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Stats_LifeDestructor(struct TASK *t /*$a0*/)
 // line 1243, offset 0x8008ce50
	/* begin block 1 */
		// Start line: 3378
	/* end block 1 */
	// End Line: 3379

void Stats_LifeDestructor(TASK *t)

{
  LifeHandle = (TASK *)0x0;
  return;
}



// decompiled code
// original method signature: 
// void * /*$ra*/ Stats_DisplayMonsterLives(struct _D3_OBJECT *o /*$s3*/, void *Prims /*$s2*/)
 // line 1253, offset 0x8008ce5c
	/* begin block 1 */
		// Start line: 1254
		// Start offset: 0x8008CE5C
		// Variables:
	// 		struct _MONSTER *monst; // $s1
	// 		struct STATS_45fake *ptile; // $s0
	// 		struct STATS_7fake pos; // stack offset -48
	// 		short x; // $t8
	// 		short y; // $v0
	// 		short w; // $s4
	// 		short h; // $s5
	/* end block 1 */
	// End offset: 0x8008D16C
	// End Line: 1337

	/* begin block 2 */
		// Start line: 3397
	/* end block 2 */
	// End Line: 3398

/* WARNING: Could not reconcile some variable overlaps */

void * Stats_DisplayMonsterLives(_D3_OBJECT *o,void *Prims)

{
  short sVar1;
  bool bVar2;
  _SCREEN *p_Var3;
  uint *puVar4;
  ulong *puVar5;
  short sVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  undefined4 local_30;
  uint local_2c;
  
  iVar7 = *(int *)&o[1].last_pos;
  local_30 = *(undefined4 *)&o->pos;
  uVar8 = *(uint *)&(o->pos).vz;
  puVar4 = (uint *)Prims;
  if (Stats_MonsterBars != '\0') {
    local_2c._0_2_ = (short)uVar8;
    local_2c = uVar8 & 0xffff0000 | (uint)(ushort)((short)local_2c + *(short *)(iVar7 + 0xf8));
    sVar1 = *(short *)(iVar7 + 0x156);
    puVar4 = (uint *)Prims;
    if ((sVar1 != 0) && (puVar4 = (uint *)Prims, *(short *)(iVar7 + 0x154) != 0)) {
      if (sVar1 == -1) {
        Impact_Smoke(0xd0,1);
        *(undefined2 *)(iVar7 + 0x156) = 0;
        puVar4 = (uint *)Prims;
      }
      else {
        if (((0xe < sVar1) || ((*(ushort *)(iVar7 + 0x156) & 3) == 0)) ||
           (puVar4 = (uint *)Prims, (*(ushort *)(iVar7 + 0x158) & 8) != 0)) {
          GtxTmd_RotTransPersN(&local_30,Tmd_2D,1);
          sVar1 = Tmd_2D->vx;
          puVar4 = (uint *)Prims;
          if ((0 < Tmd_2D->vz) &&
             (puVar4 = (uint *)Prims, (int)Prims < Main_TextContext.Font.ascii_tab._20_4_)) {
            iVar9 = (int)o->hit_points * 0x13;
            iVar7 = (int)*(short *)(iVar7 + 0x154);
            if (iVar7 == 0) {
              trap(0x1c00);
            }
            if ((iVar7 == -1) && (iVar9 == -0x80000000)) {
              trap(0x1800);
            }
            *(undefined *)((int)Prims + 3) = 3;
            *(undefined *)((int)Prims + 7) = 0x60;
            *(undefined *)((int)Prims + 5) = 0xfa;
            *(undefined2 *)((int)Prims + 10) = 0x19;
            *(undefined2 *)((int)Prims + 0xe) = 2;
            *(undefined *)((int)Prims + 4) = 100;
            *(undefined *)((int)Prims + 6) = 100;
            p_Var3 = Scr;
            sVar6 = sVar1 + -9;
            *(short *)((int)Prims + 8) = sVar6;
            *(undefined2 *)((int)Prims + 0xc) = (short)(iVar9 / iVar7);
            *(uint *)Prims = *(uint *)Prims & 0xff000000 | p_Var3->ot[1] & 0xffffff;
            puVar4 = (uint *)((int)Prims + 0x10);
            puVar5 = p_Var3->ot;
            bVar2 = (int)puVar4 < Main_TextContext.Font.ascii_tab._20_4_;
            puVar5[1] = puVar5[1] & 0xff000000 | (uint)Prims & 0xffffff;
            if (bVar2) {
              *(undefined *)((int)Prims + 0x13) = 3;
              *(undefined *)((int)Prims + 0x17) = 0x60;
              *(undefined *)((int)Prims + 0x14) = 0xfa;
              *(undefined *)((int)Prims + 0x15) = 100;
              *(undefined *)((int)Prims + 0x16) = 100;
              p_Var3 = Scr;
              uVar8 = (uint)puVar4 & 0xffffff;
              *(short *)((int)Prims + 0x18) = sVar6;
              *(undefined2 *)((int)Prims + 0x1a) = 0x19;
              *(undefined2 *)((int)Prims + 0x1c) = 0x13;
              *(undefined2 *)((int)Prims + 0x1e) = 2;
              *puVar4 = *puVar4 & 0xff000000 | p_Var3->ot[1] & 0xffffff;
              puVar4 = (uint *)((int)Prims + 0x20);
              puVar5 = p_Var3->ot;
              bVar2 = (int)puVar4 < Main_TextContext.Font.ascii_tab._20_4_;
              puVar5[1] = puVar5[1] & 0xff000000 | uVar8;
              if (bVar2) {
                *(undefined *)((int)Prims + 0x24) = 0xd2;
                *(undefined *)((int)Prims + 0x25) = 0xe6;
                *(undefined *)((int)Prims + 0x23) = 3;
                *(undefined *)((int)Prims + 0x27) = 0x60;
                *(undefined *)((int)Prims + 0x26) = 0x96;
                p_Var3 = Scr;
                *(short *)((int)Prims + 0x28) = sVar1 + -10;
                *(undefined2 *)((int)Prims + 0x2a) = 0x18;
                *(undefined2 *)((int)Prims + 0x2c) = 0x15;
                *(undefined2 *)((int)Prims + 0x2e) = 4;
                *puVar4 = *puVar4 & 0xff000000 | p_Var3->ot[1] & 0xffffff;
                puVar5 = p_Var3->ot;
                puVar5[1] = puVar5[1] & 0xff000000 | (uint)puVar4 & 0xffffff;
                puVar4 = (uint *)((int)Prims + 0x30);
              }
            }
          }
        }
      }
    }
  }
  return puVar4;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Stats_GameOver()
 // line 1345, offset 0x8008d198
	/* begin block 1 */
		// Start line: 3666
	/* end block 1 */
	// End Line: 3667

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Stats_GameOver(void)

{
  Task_Link(Stats_GameOverTask,0x100);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Stats_GameOverTask()
 // line 1350, offset 0x8008d1c0
	/* begin block 1 */
		// Start line: 1351
		// Start offset: 0x8008D1C0
		// Variables:
	// 		struct STATS_31fake *p; // $s0
	// 		struct STATS_31fake prims[2]; // stack offset -128
	// 		struct STATS_70fake shp; // stack offset -48
	// 		long i; // $s1
	// 		short w; // stack offset -32
	// 		short h; // stack offset -30
	/* end block 1 */
	// End offset: 0x8008D3A0
	// End Line: 1395

	/* begin block 2 */
		// Start line: 3677
	/* end block 2 */
	// End Line: 3678

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Stats_GameOverTask(void)

{
  _SCREEN *p_Var1;
  SHAPE_31fake *pSVar2;
  int iVar3;
  int iVar4;
  SHAPE_31fake aSStack128 [2];
  SHAPE_68fake local_30;
  short local_20;
  short local_1e [3];
  
  iVar3 = 0;
  local_30.shape = 0xfc;
  local_30.file = Effects_Pcl;
  Shp_GetWH(&local_30,&local_20,local_1e);
  local_30.x = (short)((int)(((int)Scr_W - (int)local_20) +
                            ((uint)((int)Scr_W - (int)local_20) >> 0x1f)) >> 1);
  local_30.y = (short)((int)(((int)Scr_H - (int)local_1e[0]) +
                            ((uint)((int)Scr_H - (int)local_1e[0]) >> 0x1f)) >> 1);
  iVar4 = 0;
  do {
    iVar3 = iVar3 + 1;
    Shp_SetPolyFT4((SHAPE_31fake *)((int)&aSStack128[0].tag + iVar4),&local_30,local_20,local_1e[0])
    ;
    (&aSStack128[0].u1)[iVar4] = (&aSStack128[0].u1)[iVar4] + '\x01';
    (&aSStack128[0].u3)[iVar4] = (&aSStack128[0].u3)[iVar4] + '\x01';
    (&aSStack128[0].v2)[iVar4] = (&aSStack128[0].v2)[iVar4] + '\x01';
    (&aSStack128[0].v3)[iVar4] = (&aSStack128[0].v3)[iVar4] + '\x01';
    iVar4 = iVar4 + 0x28;
  } while (iVar3 < 2);
  Fx_PlayInPause(0x36,0);
  SFX_ShakeScreen(0x1e,8);
  iVar4 = 0x1e;
  do {
    p_Var1 = Scr;
    pSVar2 = aSStack128 + (int)Scr_Frame;
    pSVar2->tag = pSVar2->tag & 0xff000000 | *Scr->ot & 0xffffff;
    iVar4 = iVar4 + -1;
    *p_Var1->ot = *p_Var1->ot & 0xff000000 | (uint)pSVar2 & 0xffffff;
    Task_Next();
  } while (iVar4 != 0);
  do {
    p_Var1 = Scr;
    pSVar2 = aSStack128 + (int)Scr_Frame;
    pSVar2->tag = pSVar2->tag & 0xff000000 | *Scr->ot & 0xffffff;
    *p_Var1->ot = *p_Var1->ot & 0xff000000 | (uint)pSVar2 & 0xffffff;
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Stats_LoadingStart()
 // line 1405, offset 0x8008d3a0
	/* begin block 1 */
		// Start line: 3839
	/* end block 1 */
	// End Line: 3840

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Stats_LoadingStart(void)

{
  if (Stats_Load == (TASK *)0x0) {
    Stats_Load = Task_Link(Stats_LoadingTask,0x200);
    Stats_Load->destructor = Stats_LoadingDestructor;
    Stats_Load->local = (void *)0x1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Stats_LoadingEnd()
 // line 1418, offset 0x8008d3e8
	/* begin block 1 */
		// Start line: 3869
	/* end block 1 */
	// End Line: 3870

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Stats_LoadingEnd(void)

{
  if (Stats_Load != (TASK *)0x0) {
    Stats_Load->local = (void *)0x0;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Stats_LoadingTask()
 // line 1427, offset 0x8008d404
	/* begin block 1 */
		// Start line: 1428
		// Start offset: 0x8008D404
		// Variables:
	// 		struct STATS_31fake prims[4]; // stack offset -184
	// 		long i; // $s2
	/* end block 1 */
	// End offset: 0x8008D7E0
	// End Line: 1469

	/* begin block 2 */
		// Start line: 3885
	/* end block 2 */
	// End Line: 3886

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Stats_LoadingTask(void)

{
  _SCREEN *p_Var1;
  int iVar2;
  void *pvVar3;
  undefined uVar4;
  uint *puVar5;
  int iVar6;
  uint uStack184;
  undefined auStack180 [36];
  uint uStack144;
  undefined auStack140 [116];
  
  Stats_LoadingInit(0x48);
  iVar6 = 1;
  do {
    uVar4 = (undefined)(iVar6 << 5);
    auStack180[(int)Scr_Frame * 0x50] = uVar4;
    auStack180[(int)Scr_Frame * 0x50 + 1] = uVar4;
    auStack180[(int)Scr_Frame * 0x50 + 2] = uVar4;
    auStack140[(int)Scr_Frame * 0x50] = uVar4;
    auStack140[(int)Scr_Frame * 0x50 + 1] = uVar4;
    iVar6 = iVar6 + 1;
    auStack140[(int)Scr_Frame * 0x50 + 2] = uVar4;
    p_Var1 = Scr;
    iVar2 = (int)Scr_Frame;
    puVar5 = &uStack184 + iVar2 * 0x14;
    *puVar5 = *puVar5 & 0xff000000 | *Scr->ot & 0xffffff;
    *p_Var1->ot = *p_Var1->ot & 0xff000000 | (uint)puVar5 & 0xffffff;
    (&uStack144)[iVar2 * 0x14] = (&uStack144)[iVar2 * 0x14] & 0xff000000 | *p_Var1->ot & 0xffffff;
    *p_Var1->ot = *p_Var1->ot & 0xff000000 | (uint)(&uStack184 + iVar2 * 0x14 + 10) & 0xffffff;
    Task_Next();
  } while (iVar6 < 5);
  pvVar3 = TaskCurrent->local;
  p_Var1 = Scr;
  while (pvVar3 != (void *)0x0) {
    iVar6 = (int)Scr_Frame;
    puVar5 = &uStack184 + iVar6 * 0x14;
    Scr = p_Var1;
    *puVar5 = *puVar5 & 0xff000000 | *p_Var1->ot & 0xffffff;
    *p_Var1->ot = *p_Var1->ot & 0xff000000 | (uint)puVar5 & 0xffffff;
    (&uStack144)[iVar6 * 0x14] = (&uStack144)[iVar6 * 0x14] & 0xff000000 | *p_Var1->ot & 0xffffff;
    *p_Var1->ot = *p_Var1->ot & 0xff000000 | (uint)(&uStack184 + iVar6 * 0x14 + 10) & 0xffffff;
    Task_Next();
    pvVar3 = TaskCurrent->local;
    p_Var1 = Scr;
  }
  iVar6 = 3;
  Scr = p_Var1;
  do {
    uVar4 = (undefined)(iVar6 << 5);
    auStack180[(int)Scr_Frame * 0x50] = uVar4;
    auStack180[(int)Scr_Frame * 0x50 + 1] = uVar4;
    auStack180[(int)Scr_Frame * 0x50 + 2] = uVar4;
    auStack140[(int)Scr_Frame * 0x50] = uVar4;
    auStack140[(int)Scr_Frame * 0x50 + 1] = uVar4;
    iVar6 = iVar6 + -1;
    auStack140[(int)Scr_Frame * 0x50 + 2] = uVar4;
    p_Var1 = Scr;
    iVar2 = (int)Scr_Frame;
    puVar5 = &uStack184 + iVar2 * 0x14;
    *puVar5 = *puVar5 & 0xff000000 | *Scr->ot & 0xffffff;
    *p_Var1->ot = *p_Var1->ot & 0xff000000 | (uint)puVar5 & 0xffffff;
    (&uStack144)[iVar2 * 0x14] = (&uStack144)[iVar2 * 0x14] & 0xff000000 | *p_Var1->ot & 0xffffff;
    *p_Var1->ot = *p_Var1->ot & 0xff000000 | (uint)(&uStack184 + iVar2 * 0x14 + 10) & 0xffffff;
    Task_Next();
  } while (0 < iVar6);
  Task_Sleep(2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Stats_LoadingDestructor(struct TASK *t /*$a0*/)
 // line 1474, offset 0x8008d804
	/* begin block 1 */
		// Start line: 4011
	/* end block 1 */
	// End Line: 4012

void Stats_LoadingDestructor(TASK *t)

{
  Stats_Load = (TASK *)0x0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Stats_LoadingInit(struct STATS_31fake *prims /*$s6*/)
 // line 1480, offset 0x8008d810
	/* begin block 1 */
		// Start line: 1481
		// Start offset: 0x8008D810
		// Variables:
	// 		long i; // $s3
	// 		struct STATS_70fake shp; // stack offset -56
	// 		struct STATS_31fake *p; // $s0
	// 		short w; // stack offset -40
	// 		short h; // stack offset -38
	/* end block 1 */
	// End offset: 0x8008D9BC
	// End Line: 1524

	/* begin block 2 */
		// Start line: 4030
	/* end block 2 */
	// End Line: 4031

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Stats_LoadingInit(undefined prims)

{
  undefined3 in_register_00000011;
  SHAPE_31fake *prim;
  int iVar1;
  int iVar2;
  int iVar3;
  SHAPE_68fake local_38;
  short local_28;
  short local_26 [3];
  
  iVar3 = 0;
  iVar2 = 0x28;
  iVar1 = 0;
  local_38.file = Effects_Pcl;
  do {
    prim = (SHAPE_31fake *)(CONCAT31(in_register_00000011,prims) + iVar1);
    local_38.shape = 0xfe;
    Shp_GetWH(&local_38,&local_28,local_26);
    iVar1 = iVar1 + 0x50;
    iVar3 = iVar3 + 1;
    local_38.x = (short)((int)(((int)Scr_W - (int)local_28) +
                              ((uint)((int)Scr_W - (int)local_28) >> 0x1f)) >> 1);
    local_38.y = (short)((int)(((int)Scr_H - (int)local_26[0]) +
                              ((uint)((int)Scr_H - (int)local_26[0]) >> 0x1f)) >> 1) + -0x1e;
    Shp_SetPolyFT4(prim,&local_38,local_28,local_26[0]);
    prim->code = prim->code & 0xfe;
    prim->u3 = prim->u3 + '\x01';
    prim->u1 = prim->u1 + '\x01';
    prim->v3 = prim->v3 + '\x01';
    prim->v2 = prim->v2 + '\x01';
    prim = (SHAPE_31fake *)(CONCAT31(in_register_00000011,prims) + iVar2);
    local_38.shape = 0xff;
    Shp_GetWH(&local_38,&local_28,local_26);
    local_38.x = (short)((int)(((int)Scr_W - (int)local_28) +
                              ((uint)((int)Scr_W - (int)local_28) >> 0x1f)) >> 1);
    local_38.y = (short)((int)(((int)Scr_H - (int)local_26[0]) +
                              ((uint)((int)Scr_H - (int)local_26[0]) >> 0x1f)) >> 1) + 0x1e;
    Shp_SetPolyFT4(prim,&local_38,local_28,local_26[0]);
    prim->code = prim->code & 0xfe;
    prim->u3 = prim->u3 + '\x01';
    prim->u1 = prim->u1 + '\x01';
    prim->v3 = prim->v3 + '\x01';
    prim->v2 = prim->v2 + '\x01';
    iVar2 = iVar2 + 0x50;
  } while (iVar3 < 2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Stats_EndOfLevel()
 // line 1569, offset 0x8008d9e4
	/* begin block 1 */
		// Start line: 4322
	/* end block 1 */
	// End Line: 4323

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Stats_EndOfLevel(void)

{
  Stats_EOLHandle = Task_Add(Stats_EOLTask,0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Stats_EOLTask()
 // line 1575, offset 0x8008da0c
	/* begin block 1 */
		// Start line: 1576
		// Start offset: 0x8008DA0C
		// Variables:
	// 		struct STATS_104fake t; // stack offset -120
	// 		long i; // $s0
	// 		long mark; // $s1
	// 		long nPoints; // stack offset -56
	// 		long sItem; // $s3
	// 		long sGaz; // $a2
	// 		long sMonster; // $s2
	// 		long sSecret; // stack offset -52
	// 		long sTime; // $s4
	// 		long pItem; // $s5
	// 		long pGaz; // stack offset -48
	// 		long pMonster; // $s6
	// 		long pSecret; // $fp
	// 		long pTime; // $s7
	// 		long perfect; // stack offset -44
	// 		struct STATS_36fake line[2]; // stack offset -88
	/* end block 1 */
	// End offset: 0x8008E058
	// End Line: 1767

	/* begin block 2 */
		// Start line: 4335
	/* end block 2 */
	// End Line: 4336

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Stats_EOLTask(void)

{
  int iVar1;
  TASK *pTVar2;
  short sVar3;
  long sItems;
  long sMonsters;
  long lVar4;
  uint sMonsters_00;
  int n;
  int max;
  uint sItems_00;
  int mark;
  int sTime;
  int sSecrets;
  undefined auStack120 [64];
  int local_38;
  long local_34;
  int local_30;
  uint local_2c;
  
  Text_SetContext((TEXT_102fake *)auStack120);
  sTime = 0;
  Text_SetContextFont(0x70);
  Text_SetContextXY(0,0);
  Text_SetContextWH(Scr_W,Scr_H);
  Text_SetContextRange(0);
  Text_SetContextMode(0);
  pTVar2 = TaskCurrent;
  n = (int)Pvl_nItems;
  max = (int)Pvl_MaxItems;
  TaskCurrent->display = Stats_EOLDisplayBG;
  pTVar2->destructor = Stats_EOLDestructor;
  sItems = Stats_EOLComputeStat(n,max);
  sMonsters = Stats_EOLComputeStat((int)Pvl_nMonsters,(int)Pvl_MaxMonsters);
  local_34 = Stats_EOLComputeStat((int)Pvl_nSecrets,(int)Pvl_MaxSecrets);
  lVar4 = Stats_EOLComputeStat((int)Pvl_nGaz,(int)Pvl_MaxGaz);
  n = (int)Scr_TicksPerSecond;
  max = (Pvl_GameTime - Pvl_LevelTime) / n;
  if (n == 0) {
    trap(0x1c00);
  }
  if ((n == -1) && (Pvl_GameTime - Pvl_LevelTime == -0x80000000)) {
    trap(0x1800);
  }
  local_30 = lVar4 * 2;
  sSecrets = local_34 * 2;
  n = sMonsters * 3;
  iVar1 = (max + 0x3b) / 0x3c;
  mark = 0x65;
  if ((int)(&Stats_LevelTimings)[(int)Pvl_LevelNumber * 2] < iVar1) {
    mark = 0x67;
    if (iVar1 <= (int)SHORT_ARRAY_800adaa2[(int)Pvl_LevelNumber * 2]) {
      mark = 0x66;
      sTime = 100;
    }
  }
  else {
    sTime = 200;
  }
  local_2c = 0;
  if ((((sItems == 100) && (sMonsters == 100)) && (local_34 == 100)) && (lVar4 == 100)) {
    local_2c = (uint)(mark == 0x65);
  }
  sItems_00 = 0;
  local_38 = sItems + local_30 + n + sSecrets + sTime;
  if (0 < sItems) {
    sMonsters_00 = 0;
    do {
      if (sMonsters_00 == 0) {
        Fx_PlayInPause(0x10,0);
      }
      sMonsters_00 = Joy_ReadTrig(0);
      if ((sMonsters_00 & 0x40) != 0) {
        Task_Next();
        break;
      }
      Stats_EOLDisplay(sItems_00,0,0,0,max,mark);
      Stats_EOLDispPoints(0,0,0,0,0,0xa8,0);
      sItems_00 = sItems_00 + 2;
      Task_Next();
      sMonsters_00 = sItems_00 & 5;
    } while ((int)sItems_00 < sItems);
  }
  sMonsters_00 = 0;
  sItems_00 = 0;
  if (0 < sMonsters) {
    do {
      if (sItems_00 == 0) {
        Fx_PlayInPause(0x10,0);
      }
      sItems_00 = Joy_ReadTrig(0);
      if ((sItems_00 & 0x40) != 0) {
        Task_Next();
        break;
      }
      Stats_EOLDisplay(sItems,sMonsters_00,0,0,max,mark);
      Stats_EOLDispPoints(sItems,0,0,0,0,0xa8,0);
      sMonsters_00 = sMonsters_00 + 2;
      Task_Next();
      sItems_00 = sMonsters_00 & 5;
    } while ((int)sMonsters_00 < sMonsters);
  }
  sItems_00 = 0;
  if (0 < Pvl_nSecrets) {
    sMonsters_00 = 0;
    do {
      if (sMonsters_00 == 0) {
        Fx_PlayInPause(0x10,0);
      }
      sMonsters_00 = Joy_ReadTrig(0);
      if ((sMonsters_00 & 0x40) != 0) {
        Task_Next();
        break;
      }
      Stats_EOLDisplay(sItems,sMonsters,sItems_00,0,max,mark);
      Stats_EOLDispPoints(sItems,n,0,0,0,0xa8,0);
      sItems_00 = sItems_00 + 1;
      Task_Next();
      sMonsters_00 = sItems_00 & 5;
    } while ((int)sItems_00 < (int)Pvl_nSecrets);
  }
  sItems_00 = 0;
  if (0 < Pvl_nGaz) {
    sMonsters_00 = 0;
    do {
      if (sMonsters_00 == 0) {
        Fx_PlayInPause(0x10,0);
      }
      sMonsters_00 = Joy_ReadTrig(0);
      if ((sMonsters_00 & 0x40) != 0) {
        Task_Next();
        break;
      }
      Stats_EOLDisplay(sItems,sMonsters,(int)Pvl_nSecrets,sItems_00,max,mark);
      Stats_EOLDispPoints(sItems,n,sSecrets,0,0,0xa8,0);
      sItems_00 = sItems_00 + 1;
      Task_Next();
      sMonsters_00 = sItems_00 & 5;
    } while ((int)sItems_00 < (int)Pvl_nGaz);
  }
  sMonsters_00 = 0;
  sItems_00 = 0;
  if (sTime != 0) {
    do {
      if (sItems_00 == 0) {
        Fx_PlayInPause(0x10,0);
      }
      sItems_00 = Joy_ReadTrig(0);
      if ((sItems_00 & 0x40) != 0) {
        Task_Next();
        break;
      }
      Stats_EOLDisplay(sItems,sMonsters,(int)Pvl_nSecrets,(int)Pvl_nGaz,max,mark);
      Stats_EOLDispPoints(sItems,n,sSecrets,local_30,sMonsters_00,0xa8,local_2c);
      sMonsters_00 = sMonsters_00 + 1;
      Task_Next();
      sItems_00 = sMonsters_00 & 5;
    } while ((int)sMonsters_00 < sTime);
  }
  if ((((Pvl_Difficulty == 0) && (699 < local_38)) || ((Pvl_Difficulty == 1 && (799 < local_38))))
     || ((Pvl_Difficulty == 2 && (899 < local_38)))) {
    Fx_Play(0x3b,0);
    sVar3 = _DAT_800b1e30 + 2;
    _DAT_800b1e30 = _DAT_800b1e30 + 1;
    if (local_2c != 0) {
      _DAT_800b1e30 = sVar3;
    }
    Stats_LifeAppear();
  }
  Fx_PlayInPause(0xb,0);
  while (sItems_00 = Joy_ReadTrig(0), (sItems_00 & 0x40) == 0) {
    Stats_EOLDisplay(sItems,sMonsters,(int)Pvl_nSecrets,(int)Pvl_nGaz,max,mark);
    Stats_EOLDispPoints(sItems,n,sSecrets,local_30,sTime,0xa8,local_2c);
    Task_Next();
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Stats_EOLComputeStat(long n /*$a0*/, long max /*$a1*/)
 // line 1770, offset 0x8008e088
	/* begin block 1 */
		// Start line: 1772
		// Start offset: 0x8008E088
		// Variables:
	// 		long res; // $v1
	/* end block 1 */
	// End offset: 0x8008E0E4
	// End Line: 1777

	/* begin block 2 */
		// Start line: 4935
	/* end block 2 */
	// End Line: 4936

long Stats_EOLComputeStat(long n,long max)

{
  long lVar1;
  
  lVar1 = 100;
  if (max != 0) {
    lVar1 = (n * 100) / max;
    if (max == 0) {
      trap(0x1c00);
    }
    if ((max == -1) && (n * 100 == -0x80000000)) {
      trap(0x1800);
    }
    if (100 < lVar1) {
      lVar1 = 100;
    }
  }
  return lVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Stats_EOLDisplayBG()
 // line 1782, offset 0x8008e0ec
	/* begin block 1 */
		// Start line: 1783
		// Start offset: 0x8008E0EC
		// Variables:
	// 		long posy; // $s0
	// 		long min; // $s1
	// 		char str[20]; // stack offset -40
	/* end block 1 */
	// End offset: 0x8008E1C8
	// End Line: 1815

	/* begin block 2 */
		// Start line: 4956
	/* end block 2 */
	// End Line: 4957

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Stats_EOLDisplayBG(void)

{
  undefined4 unaff_s1;
  char acStack40 [24];
  
  Text_SetText((char *)Pvl_UtilityTexts[0x60],0x28,0x50);
  Text_SetText((char *)Pvl_UtilityTexts[0x61],0x28,0x5f);
  Text_SetText((char *)Pvl_UtilityTexts[0x62],0x28,0x6e);
  Text_SetText((char *)Pvl_UtilityTexts[99],0x28,0x7d);
  Text_SetText((char *)Pvl_UtilityTexts[100],0x28,0x96);
  if (Pvl_Difficulty == 1) {
    unaff_s1 = 800;
  }
  else {
    if (Pvl_Difficulty < 2) {
      if (Pvl_Difficulty == 0) {
        unaff_s1 = 700;
      }
    }
    else {
      if (Pvl_Difficulty == 2) {
        unaff_s1 = 900;
      }
    }
  }
  sprintf(acStack40,s____d_pts___s___800adac0,unaff_s1,Pvl_UtilityTexts[0x2a]);
  Text_SetText(acStack40,0x28,0xaa);
  Text_SetText((char *)Pvl_UtilityTexts[0x68],-0x7ffe,0xd2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Stats_EOLDisplay(long sItems /*$t0*/, long sMonsters /*$s4*/, long sSecrets /*$s6*/, long sGaz /*$s7*/, long sTime /*stack 16*/, long mark /*stack 20*/)
 // line 1892, offset 0x8008e234
	/* begin block 1 */
		// Start line: 1893
		// Start offset: 0x8008E234
		// Variables:
	// 		long h; // $s3
	// 		long m; // $s2
	// 		long s; // $s1
	// 		char str[10]; // stack offset -56
	/* end block 1 */
	// End offset: 0x8008E234
	// End Line: 1893

	/* begin block 2 */
		// Start line: 5181
	/* end block 2 */
	// End Line: 5182

void Stats_EOLDisplay(long sItems,long sMonsters,long sSecrets,long sGaz,long sTime,long mark)

{
  char acStack56 [16];
  
  sprintf(acStack56,s__d____800adad0,sItems);
  Text_SetText(acStack56,0xbe,0x50);
  sprintf(acStack56,s__d____800adad0,sMonsters);
  Text_SetText(acStack56,0xbe,0x5f);
  sprintf(acStack56,s__d____d_800adad8,sSecrets,(int)Pvl_MaxSecrets);
  Text_SetText(acStack56,0xbe,0x6e);
  sprintf(acStack56,s__d____d_800adad8,sGaz,(int)Pvl_MaxGaz);
  Text_SetText(acStack56,0xbe,0x7d);
  sprintf(acStack56,s__dh__dm__ds_800adae0,sTime / 0xe10,(sTime % 0xe10) / 0x3c,
          (sTime % 0xe10) % 0x3c);
  Text_SetText(acStack56,0x78,0x96);
  Stats_EOLDispMark(mark,0xbe,0x96);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Stats_EOLDispPoints(long sItems /*$s1*/, long sMonsters /*$s3*/, long sSecrets /*$s4*/, long sGaz /*$s5*/, long sTime /*stack 16*/, struct STATS_36fake *pl /*stack 20*/, long perfect /*stack 24*/)
 // line 1949, offset 0x8008e3e4
	/* begin block 1 */
		// Start line: 1950
		// Start offset: 0x8008E3E4
		// Variables:
	// 		char str[10]; // stack offset -56
	/* end block 1 */
	// End offset: 0x8008E564
	// End Line: 1988

	/* begin block 2 */
		// Start line: 5344
	/* end block 2 */
	// End Line: 5345

void Stats_EOLDispPoints(long sItems,long sMonsters,long sSecrets,long sGaz,long sTime,char pl,
                        long perfect)

{
  undefined4 local_38;
  undefined4 local_34;
  undefined2 local_30;
  
  sprintf((char *)&local_38,s__d_pts_800adaec,sItems);
  Text_SetText((char *)&local_38,0x104,0x50);
  sprintf((char *)&local_38,s__d_pts_800adaec,sMonsters);
  Text_SetText((char *)&local_38,0x104,0x5f);
  sprintf((char *)&local_38,s__d_pts_800adaec,sSecrets);
  Text_SetText((char *)&local_38,0x104,0x6e);
  sprintf((char *)&local_38,s__d_pts_800adaec,sGaz);
  Text_SetText((char *)&local_38,0x104,0x7d);
  sprintf((char *)&local_38,s__d_pts_800adaec,sTime);
  Text_SetText((char *)&local_38,0x104,0x96);
  Stats_EOLDisplayLine(pl + (char)Scr_Frame * '\x10',0xfa,0xa5);
  sprintf((char *)&local_38,s__d_pts_800adaec,sItems + sMonsters + sSecrets + sGaz + sTime);
  Text_SetText((char *)&local_38,0x104,0xaa);
  if (perfect != 0) {
    local_38 = s_PERFECT___800adaf4._0_4_;
    local_34 = s_PERFECT___800adaf4._4_4_;
    local_30 = s_PERFECT___800adaf4._8_2_;
    Text_SetContextColor((long)&DAT_0040ff40);
    Text_SetText((char *)&local_38,-0x7ffe,0xbe);
    Text_SetContextColor(0x808080);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Stats_EOLDispMark(long mark /*$s0*/, long posx /*$s1*/, long posy /*$s2*/)
 // line 1991, offset 0x8008e590
	/* begin block 1 */
		// Start line: 5445
	/* end block 1 */
	// End Line: 5446

void Stats_EOLDispMark(long mark,long posx,long posy)

{
  Text_SetContextColor((long)&DAT_004040ff);
  Text_SetText((char *)Pvl_UtilityTexts[mark],(short)posx,(short)posy);
  Text_SetContextColor(0x808080);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Stats_EOLDisplayLine(struct STATS_36fake *pl /*$a0*/, long posx /*$a1*/, long posy /*$a2*/)
 // line 1999, offset 0x8008e608
	/* begin block 1 */
		// Start line: 5470
	/* end block 1 */
	// End Line: 5471

void Stats_EOLDisplayLine(undefined pl,long posx,long posy)

{
  _SCREEN *p_Var1;
  short sVar2;
  ulong *puVar3;
  undefined3 in_register_00000011;
  uint *puVar4;
  
  puVar4 = (uint *)CONCAT31(in_register_00000011,pl);
  *(undefined *)((int)puVar4 + 3) = 3;
  *(undefined *)((int)puVar4 + 7) = 0x40;
  *(undefined *)(puVar4 + 1) = 0xfa;
  *(undefined *)((int)puVar4 + 5) = 100;
  *(undefined *)((int)puVar4 + 6) = 100;
  sVar2 = Scr_W;
  *(undefined2 *)((int)puVar4 + 10) = (short)posy;
  *(undefined2 *)((int)puVar4 + 0xe) = (short)posy;
  *(short *)(puVar4 + 2) = (short)posx;
  p_Var1 = Scr;
  *(short *)(puVar4 + 3) = sVar2 + -10;
  *puVar4 = *puVar4 & 0xff000000 | *p_Var1->ot & 0xffffff;
  puVar3 = p_Var1->ot;
  *puVar3 = *puVar3 & 0xff000000 | (uint)puVar4 & 0xffffff;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Stats_EOLDestructor()
 // line 2012, offset 0x8008e698
	/* begin block 1 */
		// Start line: 5508
	/* end block 1 */
	// End Line: 5509

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Stats_EOLDestructor(void)

{
  Stats_EOLHandle = (TASK *)0x0;
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Stats_EOLWait()
 // line 2018, offset 0x8008e6a4
	/* begin block 1 */
		// Start line: 5520
	/* end block 1 */
	// End Line: 5521

/* WARNING: Unknown calling convention yet parameter storage is locked */

long Stats_EOLWait(void)

{
  return (long)Stats_EOLHandle;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Stats_AtTheMax()
 // line 2028, offset 0x8008e6b0
	/* begin block 1 */
		// Start line: 5541
	/* end block 1 */
	// End Line: 5542

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Stats_AtTheMax(void)

{
  if ((*(short *)(DAT_800b3f0c + 0x54) == 0) && ((Pvl_File->mode & 1U) == 0)) {
    Task_Link(Stats_ATMTask,0x400);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Stats_ATMTask()
 // line 2041, offset 0x8008e70c
	/* begin block 1 */
		// Start line: 2042
		// Start offset: 0x8008E70C
		// Variables:
	// 		struct STATS_31fake prim[2]; // stack offset -112
	// 		long i; // $s4
	// 		long sens; // $s2
	// 		unsigned char col; // $s1
	/* end block 1 */
	// End offset: 0x8008E900
	// End Line: 2096

	/* begin block 2 */
		// Start line: 5573
	/* end block 2 */
	// End Line: 5574

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Stats_ATMTask(void)

{
  _SCREEN *p_Var1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uStack112;
  undefined auStack108 [76];
  
  iVar4 = 8;
  uVar3 = 0xff;
  if (((_DAT_800b1e44 <= _DAT_800b1e38 >> 8) && (99 < _DAT_800b1e3a >> 8)) &&
     (_DAT_800b1e48 <= _DAT_800b1e3c >> 8)) {
    _DAT_800b1e34 = 0;
    Fx_Play(0x3b,0);
    _DAT_800b1e30 = _DAT_800b1e30 + 1;
    Stats_LifeAppear();
  }
  Stats_ATMInit(0x90);
  Fx_Play(0x42,0);
  iVar5 = 0;
  do {
    if (*(short *)(DAT_800b3f0c + 0x54) != 0) break;
    if ((0 < iVar4) && (0xf9 < (uVar3 & 0xff))) {
      iVar4 = -8;
    }
    if ((iVar4 < 0) && ((uVar3 & 0xff) < 0x81)) {
      iVar4 = 8;
    }
    auStack108[(int)Scr_Frame * 0x28] = 0x80;
    uVar3 = uVar3 + iVar4;
    auStack108[(int)Scr_Frame * 0x28 + 1] = (char)uVar3;
    auStack108[(int)Scr_Frame * 0x28 + 2] = 0x80;
    p_Var1 = Scr;
    puVar2 = &uStack112 + (int)Scr_Frame * 10;
    *puVar2 = *puVar2 & 0xff000000 | Scr->ot[1] & 0xffffff;
    iVar5 = iVar5 + 1;
    p_Var1->ot[1] = p_Var1->ot[1] & 0xff000000 | (uint)puVar2 & 0xffffff;
    Task_Next();
  } while (iVar5 < 0x5a);
  Task_Sleep(2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Stats_ATMInit(struct STATS_31fake *pft4 /*$a0*/)
 // line 2099, offset 0x8008e930
	/* begin block 1 */
		// Start line: 2100
		// Start offset: 0x8008E930
		// Variables:
	// 		struct STATS_31fake *p; // $s1
	// 		long i; // $s2
	// 		short w; // stack offset -24
	// 		short h; // stack offset -22
	// 		struct STATS_70fake shp; // stack offset -40
	/* end block 1 */
	// End offset: 0x8008EA00
	// End Line: 2122

	/* begin block 2 */
		// Start line: 5752
	/* end block 2 */
	// End Line: 5753

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Stats_ATMInit(undefined pft4)

{
  undefined3 in_register_00000011;
  uchar *puVar1;
  SHAPE_31fake *prim;
  int iVar2;
  SHAPE_68fake local_28;
  ushort local_18;
  ushort local_16 [3];
  
  prim = (SHAPE_31fake *)CONCAT31(in_register_00000011,pft4);
  iVar2 = 0;
  puVar1 = &prim->v3;
  local_28.shape = 0x80;
  local_28.x = 0x118;
  local_28.y = 0x14;
  local_28.file = Effects_Pcl;
  Shp_GetWH(&local_28,(short *)&local_18,(short *)local_16);
  do {
    iVar2 = iVar2 + 1;
    Shp_SetPolyFT4(prim,&local_28,(short)(((uint)local_18 + 1) * 0x10000 >> 0x10),
                   (short)(((uint)local_16[0] + 1) * 0x10000 >> 0x10));
    prim = prim + 1;
    puVar1[-0x1e] = puVar1[-0x1e] & 0xfe;
    puVar1[-1] = puVar1[-1] + '\x01';
    puVar1[-0x11] = puVar1[-0x11] + '\x01';
    *puVar1 = *puVar1 + '\x01';
    puVar1[-8] = puVar1[-8] + '\x01';
    puVar1 = puVar1 + 0x28;
  } while (iVar2 < 2);
  return;
}



// decompiled code
// original method signature: 
// void atoi() /* atoi method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 3727, offset 0x8008ea18
int atoi(char *__nptr)

{
  int iVar1;
  
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)0xa0)();
  return iVar1;
}





