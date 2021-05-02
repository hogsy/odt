#include "THISDUST.H"
#include "OVERLAY.H"


// decompiled code
// original method signature: 
// void /*$ra*/ Overlay_Init()
 // line 102, offset 0x8005b364
	/* begin block 1 */
		// Start line: 103
		// Start offset: 0x8005B364
		// Variables:
	// 		long i; // $s0
	/* end block 1 */
	// End offset: 0x8005B428
	// End Line: 146

	/* begin block 2 */
		// Start line: 204
	/* end block 2 */
	// End Line: 205

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Overlay_Init(void)

{
  int iVar1;
  char *__s;
  
  iVar1 = 0;
  BarX = 0xf;
  BarY = Scr_H + -0x23;
  Overlay_SetPrims();
  __s = Sound_TrackNames;
  OVER_DISPLAY = 0;
  SPELL_DISPLAY = 0;
  BOSS_DISPLAY = 0;
  Over_BossBlinkHandle = (TASK *)0x0;
  Over_BossPercent = 0;
  HBarX = BarX + 0x30;
  DBarX = Scr_W + -0x50;
  HBarY = BarY + 2;
  Overlay_SetHealthPrims();
  Boss_PosY = -0x28;
  Overlay_SetBossPrims(0);
  Invent_Init();
  Stats_Init();
  do {
    sprintf(__s,s__ODT_LEVEL_02d_XA_1_800ad6cc,iVar1);
    iVar1 = iVar1 + 1;
    __s = __s + 0x28;
  } while (iVar1 < 8);
  Overlay_Handle = Task_Add(Overlay_Task,0x300);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Overlay_Delete()
 // line 150, offset 0x8005b454
	/* begin block 1 */
		// Start line: 371
	/* end block 1 */
	// End Line: 372

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Overlay_Delete(void)

{
  Task_Kill(DAT_800b3f0c);
  Task_Kill(DAT_800b6e80);
  Task_Kill(Overlay_Handle);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Overlay_EndSector()
 // line 158, offset 0x8005b498
	/* begin block 1 */
		// Start line: 387
	/* end block 1 */
	// End Line: 388

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Overlay_EndSector(void)

{
  Sound_Off();
  if (LifeHandle != (TASK *)0x0) {
    Task_Kill(LifeHandle);
  }
  Inventaire.moving = '\0';
  *(undefined4 *)(DAT_800b3f0c + 0x20) = 0;
  SPELL_MOVING = 0;
  SPELL_DISPLAY = 0;
  *(undefined2 *)(DAT_800b3f0c + 0x54) = 0;
  Invent_DeleteDropped();
  DBarX = Scr_W;
  BarX = 0xf;
  HBarX = 0x3f;
  BarY = Scr_H + -0x23;
  HBarY = Scr_H + -0x21;
  *(undefined4 *)(DAT_800b6e80 + 0x20) = 0;
  DBarX = DBarX + -0x50;
  *(undefined2 *)(DAT_800b6e80 + 0x54) = 0;
  Overlay_SetPrims();
  Overlay_SetHealthPrims();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Overlay_SetPrims()
 // line 194, offset 0x8005b55c
	/* begin block 1 */
		// Start line: 195
		// Start offset: 0x8005B55C
		// Variables:
	// 		long i; // $s2
	// 		long dummy; // $s1
	// 		struct OVERLAY_70fake shp; // stack offset -40
	// 		short HeadW; // stack offset -24
	// 		short w; // stack offset -20
	// 		short h; // stack offset -22

		/* begin block 1.1 */
			// Start line: 211
			// Start offset: 0x8005B5B0
			// Variables:
		// 		struct OVERLAY_31fake *p; // $s0
		/* end block 1.1 */
		// End offset: 0x8005B5B0
		// End Line: 211

		/* begin block 1.2 */
			// Start line: 230
			// Start offset: 0x8005B6A4
		/* end block 1.2 */
		// End offset: 0x8005B6A4
		// End Line: 231

		/* begin block 1.3 */
			// Start line: 254
			// Start offset: 0x8005B758
		/* end block 1.3 */
		// End offset: 0x8005B758
		// End Line: 255

		/* begin block 1.4 */
			// Start line: 270
			// Start offset: 0x8005B7DC
			// Variables:
		// 		struct OVERLAY_31fake *p; // $s0
		/* end block 1.4 */
		// End offset: 0x8005B7DC
		// End Line: 270

		/* begin block 1.5 */
			// Start line: 295
			// Start offset: 0x8005B8D4
			// Variables:
		// 		struct OVERLAY_31fake *p; // $s0
		/* end block 1.5 */
		// End offset: 0x8005B8D4
		// End Line: 295

		/* begin block 1.6 */
			// Start line: 326
			// Start offset: 0x8005BA5C
		/* end block 1.6 */
		// End offset: 0x8005BA5C
		// End Line: 327
	/* end block 1 */
	// End offset: 0x8005BAB8
	// End Line: 334

	/* begin block 2 */
		// Start line: 482
	/* end block 2 */
	// End Line: 483

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Overlay_SetPrims(void)

{
  uchar uVar1;
  uint uVar2;
  SHAPE_31fake *prim;
  int iVar3;
  int iVar4;
  int iVar5;
  SHAPE_68fake local_28;
  ushort local_18;
  ushort local_16;
  ushort local_14 [2];
  
  iVar3 = 0;
  local_28.shape = 0x75;
  local_28.y = BarY + -10;
  local_28.file = Effects_Pcl;
  local_28.x = BarX;
  Shp_GetWH(&local_28,(short *)&local_18,(short *)&local_16);
  iVar4 = 0;
  do {
    iVar3 = iVar3 + 1;
    Shp_SetPolyFT4((SHAPE_31fake *)(&Over_LWeapon + iVar4),&local_28,
                   (short)(((uint)local_18 + 1) * 0x10000 >> 0x10),
                   (short)(((uint)local_16 + 1) * 0x10000 >> 0x10));
    (&DAT_800b29fc)[iVar4] = (&DAT_800b29fc)[iVar4] + '\x01';
    (&DAT_800b2a0c)[iVar4] = (&DAT_800b2a0c)[iVar4] + '\x01';
    (&DAT_800b2a05)[iVar4] = (&DAT_800b2a05)[iVar4] + '\x01';
    (&DAT_800b2a0d)[iVar4] = (&DAT_800b2a0d)[iVar4] + '\x01';
    iVar4 = iVar4 + 0x28;
  } while (iVar3 < 2);
  iVar4 = 0;
  local_28.shape = (short)DAT_800b1de0 + 0xf3;
  local_28.y = BarY + -3;
  local_28.x = BarX + 0x12;
  Shp_GetWH(&local_28,(short *)local_14,(short *)&local_16);
  local_28.y = BarY + -3;
  local_28.x = local_28.x -
               (short)((int)(((int)((uint)local_14[0] << 0x10) >> 0x10) +
                            (((uint)local_14[0] << 0x10) >> 0x1f)) >> 1);
  prim = (SHAPE_31fake *)&Over_LSymbol;
  do {
    iVar4 = iVar4 + 1;
    Shp_SetPolyFT4(prim,&local_28,local_14[0],local_16);
    prim = prim + 1;
  } while (iVar4 < 2);
  local_28.shape = 0x82;
  Shp_GetWH(&local_28,(short *)local_14,(short *)&local_16);
  iVar4 = 0;
  prim = (SHAPE_31fake *)&Over_RBar;
  local_28.shape = 0x83;
  local_18 = (local_14[0] + local_18) - 2;
  local_28.y = BarY + 1;
  local_28.x = BarX + local_18;
  Shp_GetWH(&local_28,(short *)local_14,(short *)&local_16);
  local_18 = local_14[0] + local_18 + 10;
  do {
    iVar4 = iVar4 + 1;
    Shp_SetPolyFT4(prim,&local_28,local_14[0],(short)(((uint)local_16 + 1) * 0x10000 >> 0x10));
    prim->v2 = prim->v2 + '\x01';
    prim->v3 = prim->v3 + '\x01';
    prim = prim + 1;
  } while (iVar4 < 2);
  iVar3 = 0;
  local_28.shape = 0x75;
  local_28.x = BarX + local_18;
  local_28.y = BarY + -10;
  Shp_GetWH(&local_28,(short *)local_14,(short *)&local_16);
  iVar4 = 0;
  do {
    iVar3 = iVar3 + 1;
    Shp_SetPolyFT4((SHAPE_31fake *)(&Over_RWeapon + iVar4),&local_28,
                   (short)(((uint)local_14[0] + 1) * 0x10000 >> 0x10),
                   (short)(((uint)local_16 + 1) * 0x10000 >> 0x10));
    (&DAT_800b2a4c)[iVar4] = (&DAT_800b2a4c)[iVar4] + '\x01';
    (&DAT_800b2a5c)[iVar4] = (&DAT_800b2a5c)[iVar4] + '\x01';
    (&DAT_800b2a55)[iVar4] = (&DAT_800b2a55)[iVar4] + '\x01';
    (&DAT_800b2a5d)[iVar4] = (&DAT_800b2a5d)[iVar4] + '\x01';
    iVar4 = iVar4 + 0x28;
  } while (iVar3 < 2);
  if (DAT_800b1de1 == '\x04') {
    local_28.shape = 0xfa;
  }
  else {
    local_28.shape = 0xfb;
    if (DAT_800b1de1 != '\x05') {
      local_28.shape = (short)DAT_800b1de1 + 0xf6;
    }
  }
  iVar3 = 0;
  local_28.x = BarX + local_18 + 8;
  local_28.y = BarY + -3;
  Shp_GetWH(&local_28,(short *)local_14,(short *)&local_16);
  iVar4 = 0;
  do {
    iVar3 = iVar3 + 1;
    Shp_SetPolyFT4((SHAPE_31fake *)(&Over_RSymbol + iVar4),&local_28,
                   (short)(((uint)local_14[0] + 1) * 0x10000 >> 0x10),
                   (short)(((uint)local_16 + 1) * 0x10000 >> 0x10));
    (&DAT_800b295c)[iVar4] = (&DAT_800b295c)[iVar4] + '\x01';
    (&DAT_800b296c)[iVar4] = (&DAT_800b296c)[iVar4] + '\x01';
    (&DAT_800b2965)[iVar4] = (&DAT_800b2965)[iVar4] + '\x01';
    (&DAT_800b296d)[iVar4] = (&DAT_800b296d)[iVar4] + '\x01';
    iVar4 = iVar4 + 0x28;
  } while (iVar3 < 2);
  local_28.shape = (short)DAT_800b1de1 + 0x93;
  if ('\x03' < DAT_800b1de1) {
    local_28.shape = 0x96;
  }
  local_28.x = 0xad;
  local_28.y = BarY + 7;
  Shp_GetWH(&local_28,(short *)local_14,(short *)&local_16);
  if (DAT_800b1de1 == '\x04') {
    iVar4 = 0;
  }
  else {
    if (DAT_800b1de1 == '\x05') {
      uVar2 = (uint)*(ushort *)(_DAT_800b1d3c + 0x9e) << 0x10;
      iVar4 = (int)(((int)uVar2 >> 0x10) + (uVar2 >> 0x1f)) >> 1;
    }
    else {
      iVar4 = (int)*(short *)(&DAT_800b1de2 + (int)DAT_800b1de1 * 8);
    }
  }
  iVar3 = 100;
  if (iVar4 < 0x65) {
    iVar3 = iVar4;
  }
  iVar5 = 0;
  prim = (SHAPE_31fake *)&Over_Ammo;
  iVar4 = (iVar3 * 0x4d) / 100;
  do {
    Shp_SetPolyFT4(prim,&local_28,(short)((uint)(iVar4 * 0x10000) >> 0x10),
                   (short)(((uint)local_16 + 1) * 0x10000 >> 0x10));
    iVar5 = iVar5 + 1;
    uVar1 = prim->u0 + (char)iVar4;
    prim->u3 = uVar1;
    prim->u1 = uVar1;
    prim->v3 = prim->v3 + '\x01';
    prim->v2 = prim->v2 + '\x01';
    prim = prim + 1;
  } while (iVar5 < 2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Overlay_SetSpellsPrims()
 // line 337, offset 0x8005bad0
	/* begin block 1 */
		// Start line: 338
		// Start offset: 0x8005BAD0
		// Variables:
	// 		long i; // $s5
	// 		long j; // $s1
	// 		short w; // stack offset -48
	// 		short h; // stack offset -46
	// 		short spell_index; // $v1
	// 		struct OVERLAY_70fake shp; // stack offset -64

		/* begin block 1.1 */
			// Start line: 353
			// Start offset: 0x8005BB2C
			// Variables:
		// 		struct OVERLAY_31fake *p; // $s2
		/* end block 1.1 */
		// End offset: 0x8005BBF0
		// End Line: 368

		/* begin block 1.2 */
			// Start line: 379
			// Start offset: 0x8005BC44
			// Variables:
		// 		unsigned char col; // $s2

			/* begin block 1.2.1 */
				// Start line: 389
				// Start offset: 0x8005BCA8
			/* end block 1.2.1 */
			// End offset: 0x8005BCA8
			// End Line: 390
		/* end block 1.2 */
		// End offset: 0x8005BD2C
		// End Line: 399
	/* end block 1 */
	// End offset: 0x8005BD44
	// End Line: 401

	/* begin block 2 */
		// Start line: 934
	/* end block 2 */
	// End Line: 935

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Overlay_SetSpellsPrims(void)

{
  byte bVar1;
  short *psVar2;
  char *pcVar3;
  SHAPE_31fake *prim;
  int iVar4;
  uchar uVar5;
  SHAPE_31fake *prim_00;
  short *psVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  SHAPE_68fake local_40;
  ushort local_30;
  ushort local_2e [3];
  
  iVar8 = 0;
  iVar9 = 0;
  local_40.shape = 0x9a;
  local_40.file = Effects_Pcl;
  Shp_GetWH(&local_40,(short *)&local_30,(short *)local_2e);
  do {
    prim_00 = (SHAPE_31fake *)(&Over_SpellBacks + iVar9);
    iVar4 = 0;
    pcVar3 = &DAT_800b282d + iVar9;
    iVar7 = 2;
    psVar6 = &Spell_Offsets;
    do {
      psVar2 = (short *)((int)&Spell_Offsets + iVar7);
      iVar7 = iVar7 + 4;
      local_40.x = *psVar6;
      psVar6 = psVar6 + 2;
      iVar4 = iVar4 + 1;
      local_40.x = Spell_X + local_40.x;
      local_40.y = Spell_Y + *psVar2;
      Shp_SetPolyFT4(prim_00,&local_40,(short)(((uint)local_30 + 1) * 0x10000 >> 0x10),
                     (short)(((uint)local_2e[0] + 1) * 0x10000 >> 0x10));
      prim_00 = prim_00 + 1;
      pcVar3[-0x1e] = pcVar3[-0x1e] | 2;
      pcVar3[-1] = pcVar3[-1] + '\x01';
      pcVar3[-0x11] = pcVar3[-0x11] + '\x01';
      *pcVar3 = *pcVar3 + '\x01';
      pcVar3[-8] = pcVar3[-8] + '\x01';
      pcVar3 = pcVar3 + 0x28;
    } while (iVar4 < 4);
    iVar8 = iVar8 + 1;
    iVar9 = iVar9 + 0xa0;
  } while (iVar8 < 2);
  iVar9 = 0;
  prim_00 = (SHAPE_31fake *)&Over_Spells;
  iVar8 = 2;
  psVar6 = &Spell_Offsets;
  local_40.file = Pl_Pcl;
  do {
    bVar1 = (&DAT_800b1e20)[iVar9];
    if (bVar1 != 0x80) {
      uVar5 = '0';
      if ((bVar1 & 0x40) != 0) {
        uVar5 = -0x50;
      }
      local_40.shape = (&PSpells)[(uint)bVar1 & 0x3f].icon;
      iVar4 = 0;
      local_40.x = Spell_X + *psVar6;
      local_40.y = Spell_Y + *(short *)((int)&Spell_Offsets + iVar8);
      Shp_GetWH(&local_40,(short *)&local_30,(short *)local_2e);
      prim = prim_00;
      do {
        Shp_SetPolyFT4(prim,&local_40,(short)(((uint)local_30 + 1) * 0x10000 >> 0x10),
                       (short)(((uint)local_2e[0] + 1) * 0x10000 >> 0x10));
        iVar4 = iVar4 + 1;
        prim->r0 = uVar5;
        prim->g0 = uVar5;
        prim->b0 = uVar5;
        prim->code = prim->code & 0xfe;
        prim->u3 = prim->u3 + '\x01';
        prim->u1 = prim->u1 + '\x01';
        prim->v3 = prim->v3 + '\x01';
        prim->v2 = prim->v2 + '\x01';
        prim = prim + 4;
      } while (iVar4 < 2);
    }
    prim_00 = prim_00 + 1;
    iVar8 = iVar8 + 4;
    iVar9 = iVar9 + 1;
    psVar6 = psVar6 + 2;
  } while (iVar9 < 4);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Overlay_SetHealthPrims()
 // line 404, offset 0x8005bd70
	/* begin block 1 */
		// Start line: 405
		// Start offset: 0x8005BD70
		// Variables:
	// 		long i; // $s2
	// 		long j; // $s1
	// 		long dummy; // $s1
	// 		struct OVERLAY_70fake shp; // stack offset -56
	// 		short w; // stack offset -40
	// 		short h; // stack offset -38

		/* begin block 1.1 */
			// Start line: 420
			// Start offset: 0x8005BDCC
			// Variables:
		// 		struct OVERLAY_31fake *p; // $s0
		/* end block 1.1 */
		// End offset: 0x8005BDCC
		// End Line: 420

		/* begin block 1.2 */
			// Start line: 442
			// Start offset: 0x8005BEE0
		/* end block 1.2 */
		// End offset: 0x8005BEE0
		// End Line: 444

		/* begin block 1.3 */
			// Start line: 466
			// Start offset: 0x8005BFD8
		/* end block 1.3 */
		// End offset: 0x8005BFD8
		// End Line: 467

		/* begin block 1.4 */
			// Start line: 484
			// Start offset: 0x8005C068
			// Variables:
		// 		struct OVERLAY_31fake *p; // $s0
		/* end block 1.4 */
		// End offset: 0x8005C068
		// End Line: 484
	/* end block 1 */
	// End offset: 0x8005C11C
	// End Line: 498

	/* begin block 2 */
		// Start line: 1213
	/* end block 2 */
	// End Line: 1214

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Overlay_SetHealthPrims(void)

{
  uchar uVar1;
  SHAPE_31fake *prim;
  short w;
  int iVar2;
  int iVar3;
  int iVar4;
  SHAPE_68fake local_38;
  ushort local_28;
  ushort local_26 [3];
  
  iVar3 = 0;
  local_38.shape = 0x82;
  local_38.file = Effects_Pcl;
  local_38.x = HBarX;
  local_38.y = HBarY;
  Shp_GetWH(&local_38,(short *)&local_28,(short *)local_26);
  _w = 0;
  do {
    iVar3 = iVar3 + 1;
    Shp_SetPolyFT4((SHAPE_31fake *)(&Over_LBar + _w),&local_38,
                   (short)(((uint)local_28 + 1) * 0x10000 >> 0x10),
                   (short)(((uint)local_26[0] + 1) * 0x10000 >> 0x10));
    (&DAT_800b263c)[_w] = (&DAT_800b263c)[_w] + '\x01';
    (&DAT_800b264c)[_w] = (&DAT_800b264c)[_w] + '\x01';
    (&DAT_800b2645)[_w] = (&DAT_800b2645)[_w] + '\x01';
    (&DAT_800b264d)[_w] = (&DAT_800b264d)[_w] + '\x01';
    _w = _w + 0x28;
  } while (iVar3 < 2);
  local_38.shape = 0x91;
  local_38.x = HBarX + 0xd;
  local_38.y = HBarY + 3;
  Shp_GetWH(&local_38,(short *)&local_28,(short *)local_26);
  if ((int)_DAT_800b1c58 == 0) {
    w = 0;
  }
  else {
    _w = ((int)_DAT_800b1c58 * 0x4e0) / 100 >> 4;
    w = (short)_w;
    if (_w < 4) {
      w = 4;
    }
  }
  _w = 0;
  prim = (SHAPE_31fake *)&Over_Health;
  do {
    Shp_SetPolyFT4(prim,&local_38,w,(short)(((uint)local_26[0] + 1) * 0x10000 >> 0x10));
    _w = _w + 1;
    uVar1 = prim->u0 + (char)w;
    prim->u3 = uVar1;
    prim->u1 = uVar1;
    prim->v3 = prim->v3 + '\x01';
    prim->v2 = prim->v2 + '\x01';
    prim = prim + 1;
  } while (_w < 2);
  local_38.shape = 0x92;
  local_38.x = HBarX + 0xd;
  local_38.y = HBarY + 0xb;
  Shp_GetWH(&local_38,(short *)&local_28,(short *)local_26);
  if (_DAT_800b1e36 == 0) {
    w = 0;
  }
  else {
    _w = (int)((uint)_DAT_800b1e36 * 0x4e0) / 100 >> 4;
    w = (short)_w;
    if (_w < 4) {
      w = 4;
    }
  }
  _w = 0;
  prim = (SHAPE_31fake *)&Over_Mana;
  do {
    Shp_SetPolyFT4(prim,&local_38,w,(short)(((uint)local_26[0] + 1) * 0x10000 >> 0x10));
    _w = _w + 1;
    uVar1 = prim->u0 + (char)w;
    prim->u3 = uVar1;
    prim->u1 = uVar1;
    prim->v3 = prim->v3 + '\x01';
    prim->v2 = prim->v2 + '\x01';
    prim = prim + 1;
  } while (_w < 2);
  local_38.shape = 0xef;
  local_38.y = 0x28;
  Shp_GetWH(&local_38,(short *)&local_28,(short *)local_26);
  _w = 0;
  iVar3 = 0;
  do {
    iVar2 = 0;
    w = 0;
    iVar4 = 0;
    do {
      prim = (SHAPE_31fake *)(&Over_PlayerState + iVar3 + iVar4);
      iVar4 = iVar4 + 0x28;
      local_38.shape = (short)iVar2 + 0xef;
      iVar2 = iVar2 + 1;
      local_38.x = DBarX + w + -10;
      Shp_SetPolyFT4(prim,&local_38,(short)(((uint)local_28 + 1) * 0x10000 >> 0x10),
                     (short)(((uint)local_26[0] + 1) * 0x10000 >> 0x10));
      prim->code = prim->code & 0xfd;
      prim->u3 = prim->u3 + '\x01';
      prim->u1 = prim->u1 + '\x01';
      prim->v3 = prim->v3 + '\x01';
      prim->v2 = prim->v2 + '\x01';
      w = w + 0x14;
    } while (iVar2 < 4);
    _w = _w + 1;
    iVar3 = iVar3 + 0xa0;
  } while (_w < 2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Overlay_RotBoussole(struct OVERLAY_31fake *Prims /*$s2*/, long PosX /*$s4*/, long PosY /*$s5*/)
 // line 501, offset 0x8005c140
	/* begin block 1 */
		// Start line: 502
		// Start offset: 0x8005C140
		// Variables:
	// 		struct OVERLAY_5fake mr; // stack offset -200
	// 		struct OVERLAY_6fake d[4]; // stack offset -168
	// 		struct OVERLAY_7fake angle; // stack offset -104
	// 		struct OVERLAY_7fake TabCoord[4]; // stack offset -96
	// 		struct OVERLAY_7fake *psv; // $a2
	// 		struct OVERLAY_70fake shp; // stack offset -64
	// 		long i; // $s1
	// 		long f; // stack offset -36
	// 		long offset; // $s3
	// 		short w; // stack offset -40
	// 		short h; // stack offset -38

		/* begin block 1.1 */
			// Start line: 552
			// Start offset: 0x8005C324
			// Variables:
		// 		struct OVERLAY_7fake dummy; // stack offset -48
		/* end block 1.1 */
		// End offset: 0x8005C324
		// End Line: 552
	/* end block 1 */
	// End offset: 0x8005C3B0
	// End Line: 562

	/* begin block 2 */
		// Start line: 1532
	/* end block 2 */
	// End Line: 1533

/* WARNING: Could not reconcile some variable overlaps */

void Overlay_RotBoussole(undefined Prims,long PosX,long PosY)

{
  int iVar1;
  undefined4 in_zero;
  undefined4 in_at;
  long lVar2;
  short *psVar3;
  undefined3 in_register_00000011;
  int iVar4;
  int *piVar5;
  int iVar6;
  short sVar7;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined2 local_a8 [2];
  undefined2 local_a4;
  undefined2 local_98;
  undefined2 local_94;
  undefined2 local_88;
  undefined2 local_84;
  undefined2 local_78;
  undefined2 local_74;
  undefined4 local_68;
  undefined4 local_64;
  short local_60 [4];
  short local_58;
  short local_56;
  undefined2 local_54;
  short local_50;
  short local_4e;
  undefined2 local_4c;
  short local_48;
  short local_46;
  undefined2 local_44;
  SHAPE_68fake local_40;
  undefined4 local_30;
  undefined4 local_2c;
  short local_28;
  short local_26;
  undefined4 local_24;
  
  iVar4 = CONCAT31(in_register_00000011,Prims);
  memset(&local_68,0,8);
  sVar7 = 0;
  local_40.shape = 0xf5;
  local_40.file = Effects_Pcl;
  Shp_GetWH(&local_40,&local_28,&local_26);
  local_58 = local_28 >> 1;
  local_60[0] = -local_58;
  local_4e = local_26 >> 1;
  local_60[1] = -local_4e;
  local_60[2] = 0;
  local_54 = 0;
  local_4c = 0;
  local_44 = 0;
  if (Pvl_LevelNumber == 6) {
    iVar6 = 0;
    if (Pvl_SectorNumber == 8) {
      sVar7 = 0x400;
    }
    else {
      psVar3 = &Over_RotSectors;
      sVar7 = 0;
      do {
        if (Pvl_SectorNumber == *psVar3) {
          sVar7 = 0x800;
        }
        iVar6 = iVar6 + 1;
        psVar3 = psVar3 + 1;
      } while (iVar6 < 4);
    }
  }
  setCopReg(2,in_zero,local_68);
  setCopReg(2,in_at,local_64);
  copFunction(2,0x486012);
  local_b4 = getCopReg(2,0x19);
  local_b0 = getCopReg(2,0x1a);
  local_ac = getCopReg(2,0x1b);
  local_56 = local_60[1];
  local_50 = local_60[0];
  local_48 = local_58;
  local_46 = local_4e;
  local_28 = local_58;
  local_26 = local_4e;
  lVar2 = Direction((int)DAT_800b4170 - (int)Cam_Pos_,(int)DAT_800b4172 - (int)DAT_800b416a);
  local_64 = CONCAT22(local_64._2_2_,sVar7 + (short)lVar2 + -0x400);
  RotMatrix((short *)&local_68,(undefined2 *)&local_c8);
  setCopControlWord(2,0x2800,local_b4);
  setCopControlWord(2,0x3000,local_b0);
  setCopControlWord(2,0x3800,local_ac);
  setCopControlWord(2,0,local_c8);
  setCopControlWord(2,0x800,local_c4);
  setCopControlWord(2,0x1000,local_c0);
  setCopControlWord(2,0x1800,local_bc);
  setCopControlWord(2,0x2000,local_b8);
  iVar6 = 0;
  piVar5 = (int *)local_a8;
  do {
    memset(&local_30,0,8);
    local_30 = CONCAT22(local_60[iVar6 * 4 + 1],local_60[iVar6 * 4]);
    setCopReg(2,in_zero,local_30);
    setCopReg(2,in_at,local_2c);
    copFunction(2,0x480012);
    iVar1 = getCopReg(2,0x19);
    *piVar5 = iVar1;
    iVar1 = getCopReg(2,0x1a);
    piVar5[1] = iVar1;
    iVar1 = getCopReg(2,0x1b);
    piVar5[2] = iVar1;
    local_24 = getCopControlWord(2,0xf800);
    iVar6 = iVar6 + 1;
    *piVar5 = *piVar5 + PosX;
    piVar5[1] = piVar5[1] + PosY;
    piVar5 = piVar5 + 4;
  } while (iVar6 < 4);
  *(undefined2 *)(iVar4 + 8) = local_a8[0];
  *(undefined2 *)(iVar4 + 10) = local_a4;
  *(undefined2 *)(iVar4 + 0x10) = local_98;
  *(undefined2 *)(iVar4 + 0x12) = local_94;
  *(undefined2 *)(iVar4 + 0x18) = local_88;
  *(undefined2 *)(iVar4 + 0x1a) = local_84;
  *(undefined2 *)(iVar4 + 0x20) = local_78;
  *(undefined2 *)(iVar4 + 0x22) = local_74;
  *(undefined2 *)(iVar4 + 0x30) = local_a8[0];
  *(undefined2 *)(iVar4 + 0x32) = local_a4;
  *(undefined2 *)(iVar4 + 0x38) = local_98;
  *(undefined2 *)(iVar4 + 0x3a) = local_94;
  *(undefined2 *)(iVar4 + 0x40) = local_88;
  *(undefined2 *)(iVar4 + 0x42) = local_84;
  *(undefined2 *)(iVar4 + 0x48) = local_78;
  *(undefined2 *)(iVar4 + 0x4a) = local_74;
  setCopControlWord(2,0x2800,Cam_Matrix.t[0]);
  setCopControlWord(2,0x3000,Cam_Matrix.t[1]);
  setCopControlWord(2,0x3800,Cam_Matrix.t[2]);
  setCopControlWord(2,0,Cam_Matrix.m[0]._0_4_);
  setCopControlWord(2,0x800,Cam_Matrix.m._4_4_);
  setCopControlWord(2,0x1000,Cam_Matrix.m[1]._2_4_);
  setCopControlWord(2,0x1800,Cam_Matrix.m[2]._0_4_);
  setCopControlWord(2,0x2000,Cam_Matrix._16_4_);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Overlay_Task()
 // line 572, offset 0x8005c4d8
	/* begin block 1 */
		// Start line: 573
		// Start offset: 0x8005C4D8
		// Variables:
	// 		struct OVERLAY_104fake t; // stack offset -40
	// 		long event; // $s0
	/* end block 1 */
	// End offset: 0x8005C664
	// End Line: 627

	/* begin block 2 */
		// Start line: 1736
	/* end block 2 */
	// End Line: 1737

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Overlay_Task(void)

{
  uint uVar1;
  undefined auStack40 [32];
  
  Task_Next();
  Overlay_Handle->display = Overlay_Display;
  Text_SetContext((TEXT_102fake *)auStack40);
  Text_SetContextFont(0x70);
  Text_SetContextXY(0,0);
  Text_SetContextWH(Scr_W,Scr_H);
  Text_SetContextRange(1);
  Text_SetContextMode(0);
  do {
    uVar1 = Task_EventRead(TaskCurrent);
    if ((uVar1 & 0x14) != 0) {
      Overlay_SetHealthPrims();
    }
    if ((uVar1 & 200) != 0) {
      Overlay_SetPrims();
    }
    if ((uVar1 & 0x20) != 0) {
      Stats_LifeAppear();
    }
    if ((uVar1 & 1) != 0) {
      Overlay_InventAppear();
    }
    if ((uVar1 & 2) != 0) {
      Overlay_InventDisappear();
    }
    if ((uVar1 & 0x800) != 0) {
      Overlay_SpellsAppear();
    }
    if ((uVar1 & 0x1000) != 0) {
      Overlay_SpellsDisappear(TaskCurrent->event_param);
    }
    if ((uVar1 & 0x2000) != 0) {
      Overlay_SetSpellsPrims();
    }
    if ((uVar1 & 0x100) != 0) {
      Overlay_BossAppear();
    }
    if ((uVar1 & 0x200) != 0) {
      Overlay_BossDisappear();
    }
    if ((uVar1 & 0x400) != 0) {
      Overlay_SetBossPrims((uint)*(ushort *)&TaskCurrent->event_param);
    }
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Overlay_Display()
 // line 630, offset 0x8005c664
	/* begin block 1 */
		// Start line: 631
		// Start offset: 0x8005C664
		// Variables:
	// 		long i; // $t0
	// 		long nb_lweapon; // $a2
	// 		char str[10]; // stack offset -24

		/* begin block 1.1 */
			// Start line: 700
			// Start offset: 0x8005CC6C
		/* end block 1.1 */
		// End offset: 0x8005CCA0
		// End Line: 704
	/* end block 1 */
	// End offset: 0x8005CDBC
	// End Line: 711

	/* begin block 2 */
		// Start line: 1902
	/* end block 2 */
	// End Line: 1903

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Overlay_Display(void)

{
  undefined *puVar1;
  _SCREEN *p_Var2;
  short sVar3;
  int iVar4;
  ulong *puVar5;
  uint *puVar6;
  uint *puVar7;
  int iVar8;
  int iVar9;
  undefined *puVar10;
  undefined *puVar11;
  char acStack24 [16];
  
  p_Var2 = Scr;
  if ((OVER_DISPLAY != 0) && ((_DAT_800b1c56 & 8) == 0)) {
    if (SPELL_DISPLAY != 0) {
      iVar9 = 0;
      puVar10 = &Over_SpellBacks;
      puVar11 = &Over_Spells;
      iVar4 = (int)Scr_Frame;
      iVar8 = iVar4 * 0xa0;
      do {
        if (((&DAT_800b1e20)[iVar9] == -0x80) || ((&DAT_800b1e20)[iVar9] == -1)) {
          *(uint *)(&Over_SpellBacks + iVar8) =
               *(uint *)(&Over_SpellBacks + iVar8) & 0xff000000 | p_Var2->ot[1] & 0xffffff;
          puVar5 = p_Var2->ot;
          puVar1 = puVar10;
        }
        else {
          *(uint *)(&Over_Spells + iVar8) =
               *(uint *)(&Over_Spells + iVar8) & 0xff000000 | p_Var2->ot[1] & 0xffffff;
          puVar5 = p_Var2->ot;
          puVar1 = puVar11;
        }
        puVar5[1] = puVar5[1] & 0xff000000 | (uint)(puVar1 + iVar4 * 0xa0) & 0xffffff;
        puVar10 = puVar10 + 0x28;
        iVar8 = iVar8 + 0x28;
        iVar9 = iVar9 + 1;
        puVar11 = puVar11 + 0x28;
      } while (iVar9 < 4);
    }
    p_Var2 = Scr;
    if (BOSS_DISPLAY != 0) {
      iVar8 = (int)Scr_Frame;
      puVar6 = (uint *)(&Over_Boss + iVar8 * 0x28);
      *puVar6 = *puVar6 & 0xff000000 | Scr->ot[1] & 0xffffff;
      p_Var2->ot[1] = p_Var2->ot[1] & 0xff000000 | (uint)puVar6 & 0xffffff;
      puVar6 = (uint *)(&Over_BossBack + iVar8 * 0x28);
      *puVar6 = *puVar6 & 0xff000000 | p_Var2->ot[1] & 0xffffff;
      p_Var2->ot[1] = p_Var2->ot[1] & 0xff000000 | (uint)puVar6 & 0xffffff;
    }
    if (Pvl_Pause != 0) {
      Stats_LifeDisplay(0x14,0x1e,(char)Scr_Frame * '(' + -0x48);
    }
    p_Var2 = Scr;
    iVar8 = (int)Scr_Frame;
    iVar4 = iVar8 * 0x28;
    puVar6 = (uint *)(&Over_Health + iVar4);
    *puVar6 = *puVar6 & 0xff000000 | Scr->ot[1] & 0xffffff;
    puVar7 = (uint *)(&Over_Ammo + iVar4);
    p_Var2->ot[1] = p_Var2->ot[1] & 0xff000000 | (uint)puVar6 & 0xffffff;
    *puVar7 = *puVar7 & 0xff000000 | p_Var2->ot[1] & 0xffffff;
    puVar6 = (uint *)(&Over_Mana + iVar4);
    p_Var2->ot[1] = p_Var2->ot[1] & 0xff000000 | (uint)puVar7 & 0xffffff;
    *puVar6 = *puVar6 & 0xff000000 | p_Var2->ot[1] & 0xffffff;
    puVar7 = (uint *)(&Over_LBar + iVar4);
    p_Var2->ot[1] = p_Var2->ot[1] & 0xff000000 | (uint)puVar6 & 0xffffff;
    *puVar7 = *puVar7 & 0xff000000 | p_Var2->ot[1] & 0xffffff;
    puVar6 = (uint *)(&Over_RBar + iVar4);
    p_Var2->ot[1] = p_Var2->ot[1] & 0xff000000 | (uint)puVar7 & 0xffffff;
    *puVar6 = *puVar6 & 0xff000000 | p_Var2->ot[1] & 0xffffff;
    p_Var2->ot[1] = p_Var2->ot[1] & 0xff000000 | (uint)puVar6 & 0xffffff;
    puVar6 = (uint *)(&Over_RSymbol + iVar4);
    *puVar6 = *puVar6 & 0xff000000 | p_Var2->ot[1] & 0xffffff;
    p_Var2->ot[1] = p_Var2->ot[1] & 0xff000000 | (uint)puVar6 & 0xffffff;
    if ((_DAT_800b1d62 & 2) != 0) {
      puVar6 = (uint *)(&Over_PlayerState + iVar8 * 0xa0);
      *puVar6 = *puVar6 & 0xff000000 | p_Var2->ot[1] & 0xffffff;
      p_Var2->ot[1] = p_Var2->ot[1] & 0xff000000 | (uint)puVar6 & 0xffffff;
    }
    p_Var2 = Scr;
    if ((_DAT_800b1d62 & 4) != 0) {
      puVar6 = (uint *)(&DAT_800b2ba0 + (int)Scr_Frame * 0xa0);
      *puVar6 = *puVar6 & 0xff000000 | Scr->ot[1] & 0xffffff;
      p_Var2->ot[1] = p_Var2->ot[1] & 0xff000000 | (uint)puVar6 & 0xffffff;
    }
    p_Var2 = Scr;
    if ((_DAT_800b1d62 & 0x10) != 0) {
      puVar6 = (uint *)(&DAT_800b2bc8 + (int)Scr_Frame * 0xa0);
      *puVar6 = *puVar6 & 0xff000000 | Scr->ot[1] & 0xffffff;
      p_Var2->ot[1] = p_Var2->ot[1] & 0xff000000 | (uint)puVar6 & 0xffffff;
    }
    p_Var2 = Scr;
    if ((_DAT_800b1d62 & 8) != 0) {
      puVar6 = (uint *)(&DAT_800b2bf0 + (int)Scr_Frame * 0xa0);
      *puVar6 = *puVar6 & 0xff000000 | Scr->ot[1] & 0xffffff;
      p_Var2->ot[1] = p_Var2->ot[1] & 0xff000000 | (uint)puVar6 & 0xffffff;
    }
    sVar3 = Invent_GetNbObjects((&Pl_LeftWeapons)[(int)DAT_800b1de0],0);
    if (sVar3 != 0) {
      if (DAT_800b1de0 == '\x02') {
        Overlay_RotBoussole(0x98,(int)BarX + 0x13,(int)BarY + 7);
      }
      else {
        sprintf(acStack24,(char *)&PTR_DAT_800ad6e0);
        Text_SetText(acStack24,(short)(((uint)(ushort)BarX + 0x23) * 0x10000 >> 0x10),
                     (short)(((uint)(ushort)BarY + 0x12) * 0x10000 >> 0x10));
      }
      p_Var2 = Scr;
      puVar6 = (uint *)(&Over_LSymbol + (int)Scr_Frame * 0x28);
      *puVar6 = *puVar6 & 0xff000000 | Scr->ot[1] & 0xffffff;
      p_Var2->ot[1] = p_Var2->ot[1] & 0xff000000 | (uint)puVar6 & 0xffffff;
    }
    p_Var2 = Scr;
    iVar8 = (int)Scr_Frame;
    puVar6 = (uint *)(&Over_LWeapon + iVar8 * 0x28);
    *puVar6 = *puVar6 & 0xff000000 | Scr->ot[1] & 0xffffff;
    p_Var2->ot[1] = p_Var2->ot[1] & 0xff000000 | (uint)puVar6 & 0xffffff;
    puVar6 = (uint *)(&Over_RWeapon + iVar8 * 0x28);
    *puVar6 = *puVar6 & 0xff000000 | p_Var2->ot[1] & 0xffffff;
    p_Var2->ot[1] = p_Var2->ot[1] & 0xff000000 | (uint)puVar6 & 0xffffff;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Overlay_MoveHealthBar(short mode /*$a0*/)
 // line 714, offset 0x8005cdcc
	/* begin block 1 */
		// Start line: 2080
	/* end block 1 */
	// End Line: 2081

void Overlay_MoveHealthBar(short mode)

{
  code *f;
  
  if (mode == 0) {
    f = Overlay_MoveHealthAwayTask;
  }
  else {
    if (mode != 1) {
      return;
    }
    f = Overlay_MoveHealthBackTask;
  }
  Task_Add(f,0x100);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Overlay_MoveHealthAwayTask()
 // line 728, offset 0x8005ce1c
	/* begin block 1 */
		// Start line: 729
		// Start offset: 0x8005CE1C
		// Variables:
	// 		long i; // $s0
	// 		long Off_X; // $s1
	/* end block 1 */
	// End offset: 0x8005CEB4
	// End Line: 751

	/* begin block 2 */
		// Start line: 2108
	/* end block 2 */
	// End Line: 2109

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Overlay_MoveHealthAwayTask(void)

{
  int iVar1;
  
  Task_Next();
  iVar1 = 0;
  do {
    HBarX = HBarX + -4;
    DBarX = DBarX + -6;
    iVar1 = iVar1 + 1;
    Overlay_SetHealthPrims();
    Overlay_MoveBossPrims(-6);
    Task_Next();
  } while (iVar1 < 10);
  iVar1 = 0;
  do {
    HBarY = HBarY + -5;
    DBarX = DBarX + -6;
    iVar1 = iVar1 + 1;
    Overlay_SetHealthPrims();
    Overlay_MoveBossPrims(-6);
    Task_Next();
  } while (iVar1 < 10);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Overlay_MoveHealthBackTask()
 // line 754, offset 0x8005cec8
	/* begin block 1 */
		// Start line: 755
		// Start offset: 0x8005CEC8
		// Variables:
	// 		long i; // $s0
	// 		long Off_X; // $s1
	/* end block 1 */
	// End offset: 0x8005CF60
	// End Line: 777

	/* begin block 2 */
		// Start line: 2177
	/* end block 2 */
	// End Line: 2178

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Overlay_MoveHealthBackTask(void)

{
  int iVar1;
  
  Task_Next();
  iVar1 = 0;
  do {
    HBarY = HBarY + 5;
    DBarX = DBarX + 6;
    iVar1 = iVar1 + 1;
    Overlay_SetHealthPrims();
    Overlay_MoveBossPrims(6);
    Task_Next();
  } while (iVar1 < 10);
  iVar1 = 0;
  do {
    HBarX = HBarX + 4;
    DBarX = DBarX + 6;
    iVar1 = iVar1 + 1;
    Overlay_SetHealthPrims();
    Overlay_MoveBossPrims(6);
    Task_Next();
  } while (iVar1 < 10);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Overlay_SpellsAppear()
 // line 780, offset 0x8005cf74
	/* begin block 1 */
		// Start line: 2247
	/* end block 1 */
	// End Line: 2248

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Overlay_SpellsAppear(void)

{
  if ((((Inventaire.moving == '\0') || (Inventaire.mode == '\x01')) && (SPELL_DISPLAY == 0)) &&
     (SPELL_MOVING == 0)) {
    Task_Add(Overlay_SpellsAppearTask,0x100);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Overlay_SpellsDisappear(long mode /*$a0*/)
 // line 792, offset 0x8005cfd8
	/* begin block 1 */
		// Start line: 793
		// Start offset: 0x8005CFD8
	/* end block 1 */
	// End offset: 0x8005D05C
	// End Line: 806

	/* begin block 2 */
		// Start line: 2271
	/* end block 2 */
	// End Line: 2272

void Overlay_SpellsDisappear(long mode)

{
  if (((((mode & 0x10000000U) == 0) ||
       ((Inventaire.moving == '\0' &&
        ((*(short *)(DAT_800b3f0c + 0x54) == 0 || (Inventaire.mode != '\x01')))))) &&
      (SPELL_DISPLAY != 0)) && (SPELL_MOVING == 0)) {
    Task_Add(Overlay_SpellsDisappearTask,0x100);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Overlay_SetSpellOFF(long value /*$a0*/)
 // line 808, offset 0x8005d06c
	/* begin block 1 */
		// Start line: 809
		// Start offset: 0x8005D06C
		// Variables:
	// 		long param; // $a2
	/* end block 1 */
	// End offset: 0x8005D088
	// End Line: 815

	/* begin block 2 */
		// Start line: 2304
	/* end block 2 */
	// End Line: 2305

void Overlay_SetSpellOFF(long value)

{
  uint param;
  
  param = (uint)*(ushort *)&Overlay_Handle->event_param;
  if (value == 0) {
    param = param | 0x10000000;
  }
  Task_EventExec(Overlay_Handle,Overlay_Handle->event_msg | 0x1000,param);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Overlay_UpdateBoss(long value /*$a0*/)
 // line 818, offset 0x8005d0a8
	/* begin block 1 */
		// Start line: 819
		// Start offset: 0x8005D0A8
		// Variables:
	// 		long param; // $a2
	/* end block 1 */
	// End offset: 0x8005D0A8
	// End Line: 819

	/* begin block 2 */
		// Start line: 2324
	/* end block 2 */
	// End Line: 2325

void Overlay_UpdateBoss(long value)

{
  Task_EventExec(Overlay_Handle,Overlay_Handle->event_msg | 0x400,
                 Overlay_Handle->event_param & 0xffff0000U | value & 0xffffU);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Overlay_SpellsAppearTask()
 // line 828, offset 0x8005d0e8
	/* begin block 1 */
		// Start line: 829
		// Start offset: 0x8005D0E8
		// Variables:
	// 		long i; // $s0
	/* end block 1 */
	// End offset: 0x8005D168
	// End Line: 847

	/* begin block 2 */
		// Start line: 2349
	/* end block 2 */
	// End Line: 2350

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Overlay_SpellsAppearTask(void)

{
  int iVar1;
  
  iVar1 = 10;
  Spell_X = 0x14;
  Spell_Y = -0x50;
  SPELL_DISPLAY = 1;
  SPELL_MOVING = 1;
  do {
    Spell_Y = Spell_Y + 10;
    iVar1 = iVar1 + -1;
    Overlay_SetSpellsPrims();
    Task_Next();
  } while (iVar1 != 0);
  SPELL_MOVING = 0;
  if (Pvl_Pause != 0) {
    Task_EventExec(Overlay_Handle,Overlay_Handle->event_msg | 2,Overlay_Handle->event_param);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Overlay_SpellsDisappearTask()
 // line 850, offset 0x8005d178
	/* begin block 1 */
		// Start line: 851
		// Start offset: 0x8005D178
		// Variables:
	// 		long i; // $s0
	/* end block 1 */
	// End offset: 0x8005D1B8
	// End Line: 863

	/* begin block 2 */
		// Start line: 2407
	/* end block 2 */
	// End Line: 2408

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Overlay_SpellsDisappearTask(void)

{
  int iVar1;
  
  iVar1 = 0xb;
  SPELL_MOVING = 1;
  do {
    Spell_Y = Spell_Y + -10;
    iVar1 = iVar1 + -1;
    Overlay_SetSpellsPrims();
    Task_Next();
  } while (iVar1 != 0);
  SPELL_MOVING = 0;
  SPELL_DISPLAY = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Overlay_InventAppear()
 // line 868, offset 0x8005d1d0
	/* begin block 1 */
		// Start line: 2458
	/* end block 1 */
	// End Line: 2459

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Overlay_InventAppear(void)

{
  if ((*(short *)(DAT_800b3f0c + 0x54) == 0) && (Inventaire.moving == '\0')) {
    Task_Add(Invent_AppearTask,0x200);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Overlay_InventDisappear()
 // line 877, offset 0x8005d220
	/* begin block 1 */
		// Start line: 2477
	/* end block 1 */
	// End Line: 2478

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Overlay_InventDisappear(void)

{
  if ((*(short *)(DAT_800b3f0c + 0x54) != 0) && (Inventaire.moving == '\0')) {
    Task_Add(Invent_DisappearTask,0x200);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Overlay_ChangeRWeapon(struct _PLAYER *pl /*$a3*/, short offset /*$a2*/)
 // line 886, offset 0x8005d270
	/* begin block 1 */
		// Start line: 2495
	/* end block 1 */
	// End Line: 2496

void Overlay_ChangeRWeapon(_PLAYER *pl,short offset)

{
  char cVar1;
  int iVar2;
  
  if ((int)offset < 0x10) {
    if ((pl->env1).Obj.primitive_top.Data[0x19] == 5) {
      Fx_Play(0x40,(char)pl + ',');
      return;
    }
    iVar2 = ((uint)(ushort)offset + (uint)(pl->env1).Obj.primitive_top.Data[0x19]) * 0x1000000;
    cVar1 = (char)((uint)iVar2 >> 0x18);
    (pl->env1).Obj.primitive_top.Data[0x19] =
         cVar1 + (((char)((iVar2 >> 0x18) / 5) + ((cVar1 >> 0x18) >> 7)) - (cVar1 >> 7)) * -5;
  }
  else {
    if ((int)(char)(pl->env1).Obj.primitive_top.Data[0x19] == (int)offset + -0x10)
    goto LAB_8005d31c;
    (pl->env1).Obj.primitive_top.Data[0x19] = (char)offset - 0x10;
  }
  Fx_Play(0x40,(char)pl + ',');
LAB_8005d31c:
  Task_EventExec(Overlay_Handle,Overlay_Handle->event_msg | 0x88,Overlay_Handle->event_param);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Overlay_ChangeLWeapon(struct _PLAYER *pl /*$s4*/, short offset /*$s6*/)
 // line 913, offset 0x8005d344
	/* begin block 1 */
		// Start line: 914
		// Start offset: 0x8005D344
		// Variables:
	// 		int i; // $s0
	// 		int k; // $s3
	// 		long old; // $s2
	/* end block 1 */
	// End offset: 0x8005D454
	// End Line: 961

	/* begin block 2 */
		// Start line: 2552
	/* end block 2 */
	// End Line: 2553

void Overlay_ChangeLWeapon(_PLAYER *pl,short offset)

{
  short sVar1;
  short *psVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  int unaff_s3;
  
  iVar5 = (int)(char)(pl->env1).Obj.primitive_top.Data[0x18];
  if ((int)offset < 0x10) {
    psVar2 = &Pl_LeftWeapons + iVar5;
    _bVar3 = iVar5;
    do {
      sVar1 = *psVar2;
      psVar2 = psVar2 + 1;
      iVar4 = _bVar3;
      if (sVar1 == -1) {
        psVar2 = &Pl_LeftWeapons;
        iVar4 = -1;
        unaff_s3 = _bVar3;
      }
      _bVar3 = iVar4 + 1;
      bVar3 = (byte)_bVar3;
      sVar1 = Invent_GetNbObjects(*psVar2,0);
      if (sVar1 != 0) goto LAB_8005d3d0;
    } while ((int)(char)(pl->env1).Obj.primitive_top.Data[0x18] != _bVar3);
    if (_bVar3 != iVar5) {
      (pl->env1).Obj.primitive_top.Data[0x18] = (byte)unaff_s3;
    }
  }
  else {
    bVar3 = 0;
    if (Pl_LeftWeapons != -1) {
      psVar2 = &Pl_LeftWeapons;
      iVar5 = (int)Pl_LeftWeapons;
      do {
        psVar2 = psVar2 + 1;
        if (iVar5 == (int)offset + -0x10) goto LAB_8005d3d0;
        iVar5 = (int)*psVar2;
        bVar3 = bVar3 + 1;
      } while (iVar5 != -1);
    }
  }
LAB_8005d444:
  if (offset != 0) {
    Fx_Play(0x40,(char)pl + ',');
  }
  Task_EventExec(Overlay_Handle,Overlay_Handle->event_msg | 0x40,Overlay_Handle->event_param);
  return;
LAB_8005d3d0:
  (pl->env1).Obj.primitive_top.Data[0x18] = bVar3;
  goto LAB_8005d444;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Overlay_SetText(char *str /*$s0*/)
 // line 970, offset 0x8005d494
	/* begin block 1 */
		// Start line: 971
		// Start offset: 0x8005D494
	/* end block 1 */
	// End offset: 0x8005D4BC
	// End Line: 977

	/* begin block 2 */
		// Start line: 2684
	/* end block 2 */
	// End Line: 2685

void Overlay_SetText(char *str)

{
  if (Zone_TextHandle != (TASK *)0x0) {
    Task_Kill(Zone_TextHandle);
  }
  Zone_TextHandle = Task_Add(Overlay_SetTextTask,0x200);
  sprintf((char *)(Zone_TextHandle + 1),(char *)&PTR_DAT_800ad6e4,str);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Overlay_SetTextTask()
 // line 986, offset 0x8005d4f8
	/* begin block 1 */
		// Start line: 987
		// Start offset: 0x8005D4F8
		// Variables:
	// 		struct OVERLAY_104fake t; // stack offset -48
	// 		long i; // $s0
	// 		char *str; // $s1
	/* end block 1 */
	// End offset: 0x8005D5A4
	// End Line: 1011

	/* begin block 2 */
		// Start line: 2719
	/* end block 2 */
	// End Line: 2720

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Overlay_SetTextTask(void)

{
  int iVar1;
  TASK *text;
  undefined auStack48 [32];
  
  text = TaskCurrent + 1;
  TaskCurrent->destructor = Zone_TxtDispDestructor;
  Text_SetContext((TEXT_102fake *)auStack48);
  iVar1 = 0;
  Text_SetContextFont(0x70);
  Text_SetContextXY(0,0);
  Text_SetContextWH(Scr_W,Scr_H);
  Text_SetContextRange(1);
  Text_SetContextMode(0);
  do {
    iVar1 = iVar1 + 1;
    Text_SetText((char *)text,-0x7ffe,(short)(((uint)(ushort)Scr_H - 0x55) * 0x10000 >> 0x10));
    Task_Next();
  } while (iVar1 < 0x2d);
  Task_Sleep(2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Overlay_SetBossPrims(long percent /*$s3*/)
 // line 1021, offset 0x8005d5c0
	/* begin block 1 */
		// Start line: 1022
		// Start offset: 0x8005D5C0
		// Variables:
	// 		int i; // $s1
	// 		int dummy; // $s3
	// 		struct OVERLAY_70fake shp; // stack offset -56
	// 		struct OVERLAY_8fake col; // stack offset -40
	// 		short w; // stack offset -32
	// 		short h; // stack offset -30

		/* begin block 1.1 */
			// Start line: 1055
			// Start offset: 0x8005D680
			// Variables:
		// 		struct OVERLAY_31fake *p; // $s0
		/* end block 1.1 */
		// End offset: 0x8005D680
		// End Line: 1055

		/* begin block 1.2 */
			// Start line: 1072
			// Start offset: 0x8005D750
			// Variables:
		// 		struct OVERLAY_31fake *p; // $s0
		/* end block 1.2 */
		// End offset: 0x8005D750
		// End Line: 1072
	/* end block 1 */
	// End offset: 0x8005D7E8
	// End Line: 1082

	/* begin block 2 */
		// Start line: 2814
	/* end block 2 */
	// End Line: 2815

void Overlay_SetBossPrims(long percent)

{
  int iVar1;
  int iVar2;
  SHAPE_68fake local_38;
  undefined local_28;
  undefined local_27;
  undefined local_26;
  short local_20;
  ushort local_1e [3];
  
  if (percent != Over_BossPercent) {
    Over_BossPercent = percent;
    Overlay_BlinkBossPrims();
  }
  if (percent < 0x33) {
    if (percent < 0x15) {
      local_27 = 100;
    }
    else {
      local_27 = 200;
    }
    local_28 = 0xfa;
  }
  else {
    local_28 = 100;
    local_27 = 0xfa;
  }
  local_26 = 100;
  iVar1 = 0;
  local_38.shape = 0x83;
  local_38.file = Effects_Pcl;
  local_38.x = DBarX + -0x1e;
  local_38.y = Boss_PosY;
  Shp_GetWH(&local_38,&local_20,(short *)local_1e);
  iVar2 = 0;
  do {
    iVar1 = iVar1 + 1;
    Shp_SetPolyFT4((SHAPE_31fake *)(&Over_BossBack + iVar2),&local_38,local_20,
                   (short)(((uint)local_1e[0] + 1) * 0x10000 >> 0x10));
    (&DAT_800b2d1c)[iVar2] = (&DAT_800b2d1c)[iVar2] + '\x01';
    (&DAT_800b2d2c)[iVar2] = (&DAT_800b2d2c)[iVar2] + '\x01';
    (&DAT_800b2d25)[iVar2] = (&DAT_800b2d25)[iVar2] + '\x01';
    (&DAT_800b2d2d)[iVar2] = (&DAT_800b2d2d)[iVar2] + '\x01';
    iVar2 = iVar2 + 0x28;
  } while (iVar1 < 2);
  local_38.shape = 0x90;
  local_38.x = local_38.x + 0x10;
  local_38.y = Boss_PosY + 7;
  Shp_GetWH(&local_38,&local_20,(short *)local_1e);
  iVar2 = 0;
  iVar1 = 0;
  do {
    Shp_SetPolyFT4((SHAPE_31fake *)(&Over_Boss + iVar1),&local_38,
                   (short)((uint)(((percent * 0x4b) / 100) * 0x10000) >> 0x10),
                   (short)(((uint)local_1e[0] + 1) * 0x10000 >> 0x10));
    (&DAT_800b2d5f)[iVar1] = (&DAT_800b2d5f)[iVar1] & 0xfe;
    (&DAT_800b2d5c)[iVar1] = local_28;
    iVar2 = iVar2 + 1;
    (&DAT_800b2d5d)[iVar1] = local_27;
    (&DAT_800b2d7c)[iVar1] = (&DAT_800b2d7c)[iVar1] + '\x01';
    (&DAT_800b2d6c)[iVar1] = (&DAT_800b2d6c)[iVar1] + '\x01';
    (&DAT_800b2d7d)[iVar1] = (&DAT_800b2d7d)[iVar1] + '\x01';
    (&DAT_800b2d5e)[iVar1] = local_26;
    (&DAT_800b2d75)[iVar1] = (&DAT_800b2d75)[iVar1] + '\x01';
    iVar1 = iVar1 + 0x28;
  } while (iVar2 < 2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Overlay_MoveBossPrims(long offset /*$a0*/)
 // line 1085, offset 0x8005d804
	/* begin block 1 */
		// Start line: 1087
		// Start offset: 0x8005D804
		// Variables:
	// 		long i; // $a2

		/* begin block 1.1 */
			// Start line: 1091
			// Start offset: 0x8005D810
		/* end block 1.1 */
		// End offset: 0x8005D810
		// End Line: 1093

		/* begin block 1.2 */
			// Start line: 1101
			// Start offset: 0x8005D85C
		/* end block 1.2 */
		// End offset: 0x8005D85C
		// End Line: 1103
	/* end block 1 */
	// End offset: 0x8005D89C
	// End Line: 1108

	/* begin block 2 */
		// Start line: 3001
	/* end block 2 */
	// End Line: 3002

void Overlay_MoveBossPrims(long offset)

{
  short sVar1;
  undefined *puVar2;
  int iVar3;
  
  iVar3 = 0;
  puVar2 = &Over_BossBack;
  do {
    iVar3 = iVar3 + 1;
    sVar1 = (short)offset;
    *(short *)(puVar2 + 8) = *(short *)(puVar2 + 8) + sVar1;
    *(short *)(puVar2 + 0x10) = *(short *)(puVar2 + 0x10) + sVar1;
    *(short *)(puVar2 + 0x18) = *(short *)(puVar2 + 0x18) + sVar1;
    *(short *)(puVar2 + 0x20) = *(short *)(puVar2 + 0x20) + sVar1;
    puVar2 = puVar2 + 0x28;
  } while (iVar3 < 2);
  iVar3 = 0;
  puVar2 = &Over_Boss;
  do {
    iVar3 = iVar3 + 1;
    *(short *)(puVar2 + 8) = *(short *)(puVar2 + 8) + sVar1;
    *(short *)(puVar2 + 0x10) = *(short *)(puVar2 + 0x10) + sVar1;
    *(short *)(puVar2 + 0x18) = *(short *)(puVar2 + 0x18) + sVar1;
    *(short *)(puVar2 + 0x20) = *(short *)(puVar2 + 0x20) + sVar1;
    puVar2 = puVar2 + 0x28;
  } while (iVar3 < 2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Overlay_BossAppear()
 // line 1111, offset 0x8005d8a4
	/* begin block 1 */
		// Start line: 3072
	/* end block 1 */
	// End Line: 3073

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Overlay_BossAppear(void)

{
  Task_Add(Overlay_BossAppearTask,0x100);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Overlay_BossDisappear()
 // line 1117, offset 0x8005d8cc
	/* begin block 1 */
		// Start line: 3085
	/* end block 1 */
	// End Line: 3086

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Overlay_BossDisappear(void)

{
  Task_Add(Overlay_BossDisappearTask,0x100);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Overlay_BossAppearTask()
 // line 1122, offset 0x8005d8f4
	/* begin block 1 */
		// Start line: 1123
		// Start offset: 0x8005D8F4
		// Variables:
	// 		int i; // $s0
	// 		short percent; // $s1
	/* end block 1 */
	// End offset: 0x8005D95C
	// End Line: 1139

	/* begin block 2 */
		// Start line: 3096
	/* end block 2 */
	// End Line: 3097

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Overlay_BossAppearTask(void)

{
  short sVar1;
  int iVar2;
  
  iVar2 = 0x13;
  BOSS_DISPLAY = 1;
  Boss_PosY = -0x28;
  sVar1 = 10;
  do {
    iVar2 = iVar2 + -1;
    Boss_PosY = Boss_PosY + 3;
    Overlay_SetBossPrims((int)sVar1);
    Task_Next();
    sVar1 = sVar1 + 5;
  } while (iVar2 != -1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Overlay_BossDisappearTask()
 // line 1141, offset 0x8005d974
	/* begin block 1 */
		// Start line: 1142
		// Start offset: 0x8005D974
		// Variables:
	// 		long i; // $s0
	/* end block 1 */
	// End offset: 0x8005D9B8
	// End Line: 1153

	/* begin block 2 */
		// Start line: 3157
	/* end block 2 */
	// End Line: 3158

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Overlay_BossDisappearTask(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = 0x12;
  do {
    Boss_PosY = Boss_PosY + -3;
    Overlay_SetBossPrims(0);
    Task_Next();
    bVar1 = iVar2 != -1;
    iVar2 = iVar2 + -1;
  } while (bVar1);
  BOSS_DISPLAY = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Overlay_BlinkBossPrims()
 // line 1162, offset 0x8005d9d0
	/* begin block 1 */
		// Start line: 3211
	/* end block 1 */
	// End Line: 3212

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Overlay_BlinkBossPrims(void)

{
  if (Over_BossBlinkHandle != (TASK *)0x0) {
    Task_Kill(Over_BossBlinkHandle);
  }
  Over_BossBlinkHandle = Task_Link(Overlay_BlinkBossPrimsTask,0x80);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Overlay_BlinkBossPrimsTask()
 // line 1170, offset 0x8005da08
	/* begin block 1 */
		// Start line: 1173
		// Start offset: 0x8005DA08
	/* end block 1 */
	// End offset: 0x8005DA08
	// End Line: 1175

	/* begin block 2 */
		// Start line: 3231
	/* end block 2 */
	// End Line: 3232

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Overlay_BlinkBossPrimsTask(void)

{
  TaskCurrent->destructor = Overlay_BlinkBossDestructor;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Overlay_BlinkBossDestructor(struct TASK *handle /*$a0*/)
 // line 1187, offset 0x8005da20
	/* begin block 1 */
		// Start line: 3262
	/* end block 1 */
	// End Line: 3263

void Overlay_BlinkBossDestructor(TASK *handle)

{
  Over_BossBlinkHandle = (TASK *)0x0;
  BOSS_DISPLAY = 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Overlay_BlinkState()
 // line 1198, offset 0x8005da34
	/* begin block 1 */
		// Start line: 3284
	/* end block 1 */
	// End Line: 3285

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Overlay_BlinkState(void)

{
  if (Over_StateBlinkHandle != (TASK *)0x0) {
    Task_Kill(Over_StateBlinkHandle);
  }
  Over_StateBlinkHandle = Task_Link(Overlay_BlinkStateTask,0x80);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Overlay_BlinkStateTask()
 // line 1206, offset 0x8005da6c
	/* begin block 1 */
		// Start line: 1207
		// Start offset: 0x8005DA6C
		// Variables:
	// 		long i; // $s0
	// 		short save_state; // $s2
	/* end block 1 */
	// End offset: 0x8005DB10
	// End Line: 1222

	/* begin block 2 */
		// Start line: 3300
	/* end block 2 */
	// End Line: 3301

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Overlay_BlinkStateTask(void)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0x1e;
  TaskCurrent->destructor = Overlay_BlinkStateDestructor;
  uVar1 = _DAT_800b1d62 & 0x1e;
  iVar3 = 10;
  do {
    if (iVar2 == (iVar3 - (iVar2 >> 0x1f)) * 3) {
      _DAT_800b1d62 = _DAT_800b1d62 | uVar1;
    }
    else {
      _DAT_800b1d62 = _DAT_800b1d62 & ~uVar1;
    }
    iVar2 = iVar2 + -1;
    Task_Next();
    iVar3 = iVar2 / 3 + (iVar2 >> 0x1f);
  } while (iVar2 != 0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Overlay_BlinkStateDestructor(struct TASK *handle /*$a0*/)
 // line 1224, offset 0x8005db2c
	/* begin block 1 */
		// Start line: 3359
	/* end block 1 */
	// End Line: 3360

void Overlay_BlinkStateDestructor(TASK *handle)

{
  Over_StateBlinkHandle = (TASK *)0x0;
  Pl_ClearStateBits((_PLAYER *)&Player,0x1e);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Overlay_DisplayPicture(char *FileName /*$s2*/, long w /*$s0*/, long time /*$s1*/)
 // line 1238, offset 0x8005db58
	/* begin block 1 */
		// Start line: 1239
		// Start offset: 0x8005DB58
		// Variables:
	// 		long t; // $v1
	/* end block 1 */
	// End offset: 0x8005DC7C
	// End Line: 1301

	/* begin block 2 */
		// Start line: 3389
	/* end block 2 */
	// End Line: 3390

void Overlay_DisplayPicture(char *FileName,long w,long time)

{
  uint uVar1;
  int iVar2;
  
  Scr_InitZone(0,0,(short)w,0x1e0,0);
  iVar2 = 1;
  if (w == 0x140) {
    iVar2 = 2;
  }
  if (iVar2 == 0) {
    trap(0x1c00);
  }
  if ((iVar2 == -1) && ((int)Main_Param.ScreenX == -0x80000000)) {
    trap(0x1800);
  }
  Screens.disp.screen.y = Main_Param.ScreenY;
  _SCREEN_800b993c.disp.screen.y = Main_Param.ScreenY;
  Screens.disp.screen.x = (short)((int)Main_Param.ScreenX / iVar2);
  _SCREEN_800b993c.disp.screen.x = Screens.disp.screen.x;
  SetDispMask(0);
  Picture = (ulong *)File_Read(FileName + 6,(void *)0x0);
  Scr_ClearCall = Overlay_PictureFunc;
  iVar2 = time + -1;
  Scr_Clear();
  Scr_Swap();
  SetDispMask(1);
  while ((iVar2 != -1 && (uVar1 = Joy_ReadLog(0), (uVar1 & 0x100) == 0))) {
    iVar2 = iVar2 + -1;
    Joy_Driver();
    VSync(0);
  }
  Scr_ClearCall = (code *)0x0;
  Overlay_FreePicture();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Overlay_FreePicture()
 // line 1325, offset 0x8005dca4
	/* begin block 1 */
		// Start line: 3569
	/* end block 1 */
	// End Line: 3570

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Overlay_FreePicture(void)

{
  if (Picture != (ulong *)0x0) {
    Heap_FreeMem(Picture);
  }
  Picture = (ulong *)0x0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Overlay_PictureFunc()
 // line 1334, offset 0x8005dccc
	/* begin block 1 */
		// Start line: 1335
		// Start offset: 0x8005DCCC
		// Variables:
	// 		struct _SCREEN *pscr; // $a0
	/* end block 1 */
	// End offset: 0x8005DCF0
	// End Line: 1341

	/* begin block 2 */
		// Start line: 3587
	/* end block 2 */
	// End Line: 3588

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Overlay_PictureFunc(void)

{
  _SCREEN *p_Var1;
  
  p_Var1 = &Screens;
  if (Scr == &Screens) {
    p_Var1 = &_SCREEN_800b993c;
  }
  LoadImage(&p_Var1->draw,Picture + 5);
  DrawSync();
  return;
}





