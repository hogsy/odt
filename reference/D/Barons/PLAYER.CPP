#include "THISDUST.H"
#include "PLAYER.H"


// decompiled code
// original method signature: 
// void /*$ra*/ Pl_Init()
 // line 74, offset 0x80031a14
	/* begin block 1 */
		// Start line: 149
	/* end block 1 */
	// End Line: 150

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pl_Init(void)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pl_InitPlayer(short p /*$s1*/)
 // line 79, offset 0x80031a1c
	/* begin block 1 */
		// Start line: 80
		// Start offset: 0x80031A1C
		// Variables:
	// 		struct PLAYER_74fake *Tmd1; // $s2
	// 		struct PLAYER_74fake *Tmd2; // $s1
	// 		struct _PLAYER *pl; // $s3
	// 		struct PLAYER_70fake shp; // stack offset -48
	// 		short i; // $s1
	// 		short w; // stack offset -32
	// 		short h; // stack offset -30
	// 		short offset; // $s4
	/* end block 1 */
	// End offset: 0x80032094
	// End Line: 278

	/* begin block 2 */
		// Start line: 158
	/* end block 2 */
	// End Line: 159

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Pl_InitPlayer(short p)

{
  short Offset;
  size_t sVar1;
  TMD_72fake *Tmd;
  TMD_72fake *Tmd_00;
  void *T;
  int iVar2;
  char cVar3;
  int iVar4;
  SHAPE_68fake local_30;
  ushort local_20;
  ushort local_1e [3];
  
  sVar1 = strlen(Pl_Files3);
  cVar3 = (char)p + '1';
  Pl_Files3[sVar1 - 5] = cVar3;
  sVar1 = strlen(PTR_DAT_800a69d0);
  PTR_DAT_800a69d0[sVar1 - 5] = cVar3;
  sVar1 = strlen(PTR_DAT_800a69d4);
  PTR_DAT_800a69d4[sVar1 - 5] = cVar3;
  Pl_Lnk = File_Read(Pl_Files3,(void *)0x0);
  Pl_Pcl = File_Read(PTR_DAT_800a69d4,(void *)0x0);
  _DAT_800b1d10 = FileGroup_GetAddr(Pl_Lnk,0);
  _DAT_800b1d14 = FileGroup_GetAddr(Pl_Lnk,1);
  _DAT_800b1d18 = (MOTION_96fake *)FileGroup_GetAddr(Pl_Lnk,2);
  _DAT_800b1d1c = (MOTION_96fake *)FileGroup_GetAddr(Pl_Lnk,3);
  _DAT_800b1d20 = (MOTION_98fake *)FileGroup_GetAddr(Pl_Lnk,6);
  Tmd = (TMD_72fake *)FileGroup_GetAddr(Pl_Lnk,4);
  Tmd_00 = (TMD_72fake *)FileGroup_GetAddr(Pl_Lnk,5);
  Shp_GroupToVram(Pl_Pcl,1);
  Offset = Shp_GetMark(Pl_Pcl,0x4d2);
  Tmd_InitFile(Tmd);
  Shp_TmdToVram(Pl_Pcl,Tmd,Offset,0);
  Tmd_InitFile(Tmd_00);
  Shp_TmdToVram(Pl_Pcl,Tmd_00,Offset,0);
  Motion_InitEnv(_DAT_800b1d18,(MOTION_72fake *)Tmd);
  Motion_InitEnv(_DAT_800b1d1c,(MOTION_72fake *)Tmd_00);
  Pl_Spells = FileGroup_GetAddr(Pl_Lnk,7);
  iVar4 = 0;
  if (0 < *(int *)Pl_Spells) {
    iVar2 = 0;
    do {
      Tmd = (TMD_72fake *)FileGroup_GetAddr(Pl_Spells,iVar2 >> 0x10);
      Tmd_InitFile(Tmd);
      T = FileGroup_GetAddr(Pl_Spells,iVar2 >> 0x10);
      Shp_TmdToVram(Pl_Pcl,T,Offset,0);
      iVar4 = iVar4 + 1;
      iVar2 = iVar4 * 0x10000;
    } while (iVar4 * 0x10000 >> 0x10 < *(int *)Pl_Spells);
  }
  iVar4 = 0;
  _DAT_800b1cf8 = &DAT_800b1d90;
  local_30.shape = 0x25;
  local_30.file = Pl_Pcl;
  Shp_SetPolyFT4((SHAPE_31fake *)&DAT_800b1d90,&local_30,0,0);
  Shp_SetPolyFT4((SHAPE_31fake *)&DAT_800b1db8,&local_30,0,0);
  local_30.shape = 0x23;
  Shp_GetWH(&local_30,(short *)&local_20,(short *)local_1e);
  local_30.y = 0x10;
  local_30.x = (Scr_W - local_20) + -0x10;
  do {
    iVar2 = (int)(short)iVar4 * 0x28;
    Shp_SetPolyFT4((SHAPE_31fake *)(&Pl_AirPrims + iVar2),&local_30,
                   (short)(((uint)local_20 + 1) * 0x10000 >> 0x10),
                   (short)(((uint)local_1e[0] + 1) * 0x10000 >> 0x10));
    iVar4 = iVar4 + 1;
    (&DAT_800b1b44)[iVar2] = (&DAT_800b1b44)[iVar2] + '\x01';
    (&DAT_800b1b54)[iVar2] = (&DAT_800b1b54)[iVar2] + '\x01';
    (&DAT_800b1b4d)[iVar2] = (&DAT_800b1b4d)[iVar2] + '\x01';
    (&DAT_800b1b55)[iVar2] = (&DAT_800b1b55)[iVar2] + '\x01';
  } while (iVar4 * 0x10000 >> 0x10 < 2);
  iVar4 = 0;
  local_30.shape = local_30.shape + 1;
  local_30.y = local_30.y + 3;
  local_30.x = local_30.x + 6;
  Shp_GetWH(&local_30,(short *)&local_20,(short *)local_1e);
  do {
    iVar2 = (int)(short)iVar4 * 0x28;
    Shp_SetPolyFT4((SHAPE_31fake *)(&DAT_800b1b80 + iVar2),&local_30,
                   (short)(((uint)local_20 + 1) * 0x10000 >> 0x10),
                   (short)(((uint)local_1e[0] + 1) * 0x10000 >> 0x10));
    iVar4 = iVar4 + 1;
    (&DAT_800b1b94)[iVar2] = (&DAT_800b1b94)[iVar2] + '\x01';
    (&DAT_800b1ba4)[iVar2] = (&DAT_800b1ba4)[iVar2] + '\x01';
    (&DAT_800b1b9d)[iVar2] = (&DAT_800b1b9d)[iVar2] + '\x01';
    (&DAT_800b1ba5)[iVar2] = (&DAT_800b1ba5)[iVar2] + '\x01';
  } while (iVar4 * 0x10000 >> 0x10 < 2);
  local_30.shape = 2;
  Shp_GetWH(&local_30,(short *)&local_20,(short *)local_1e);
  iVar4 = 0;
  local_30.y = 0x10;
  local_30.x = (Scr_W - local_20) + -0x10;
  do {
    iVar2 = (int)(short)iVar4 * 0x28;
    Shp_SetPolyFT4((SHAPE_31fake *)(&Pl_CameraPrims + iVar2),&local_30,
                   (short)(((uint)local_20 + 1) * 0x10000 >> 0x10),
                   (short)(((uint)local_1e[0] + 1) * 0x10000 >> 0x10));
    iVar4 = iVar4 + 1;
    (&DAT_800b1be4)[iVar2] = (&DAT_800b1be4)[iVar2] + '\x01';
    (&DAT_800b1bf4)[iVar2] = (&DAT_800b1bf4)[iVar2] + '\x01';
    (&DAT_800b1bed)[iVar2] = (&DAT_800b1bed)[iVar2] + '\x01';
    (&DAT_800b1bf5)[iVar2] = (&DAT_800b1bf5)[iVar2] + '\x01';
  } while (iVar4 * 0x10000 >> 0x10 < 2);
  *(undefined *)((int)_DAT_800b1d10 + 3) = 0x40;
  *(undefined *)((int)_DAT_800b1d14 + 3) = 0x40;
  Manim_SetEffect((M_OBJECT *)&DAT_800b1cdc,(TDRFuncPtr_Manim_SetEffect1f)0x0);
  _DAT_800b1cec = 0;
  _DAT_800b1cdc = &Player;
  _DAT_800b1e32 = 0x96;
  _DAT_800b1c52 = 0;
  _DAT_800b1ce0 = _DAT_800b1d10;
  _DAT_800b1ce4 = _DAT_800b1d18;
  _DAT_800b1ce8 = _DAT_800b1d20;
  D3_ClearCollBits((_D3_OBJECT *)&Player,0xffff);
  _DAT_800b1c52 = _DAT_800b1c52 | 0x5df;
  D3_SetCollBits((_D3_OBJECT *)&Player,(long)&DAT_00001009);
  D3_SetBox((_D3_OBJECT *)&Player,-0x14,-0x14,0,0x14,0x14,(uint)_DAT_800b1e32);
  _DAT_800b1c8a = 0x2000;
  _DAT_800b1c4c = 0;
  _DAT_800b1c5c = &DAT_800b1cdc;
  _DAT_800b1c92 = 0;
  _DAT_800b1c7c = &DAT_800b1d68;
  Motion_InitAni(_DAT_800b1ce8);
  Manim_ForceAnim((M_OBJECT *)&DAT_800b1cdc,0x61);
  _DAT_800b1c64 = 0x7fff;
  _DAT_800b1c66 = 0x7fff;
  _DAT_800b1c68 = 0x7fff;
  DAT_800b1e24 = 0;
  _DAT_800b1c74 = 0;
  _DAT_800b1c76 = 0;
  _DAT_800b1c78 = 0;
  _DAT_800b1d56 = 0;
  _DAT_800b1d54 = 0;
  _DAT_800b1d04 = _DAT_800b1d04 & 0xfffe;
  if (Pvl_LoadedGame == 0) {
    iVar4 = 0;
    do {
      if ((Pvl_Demo == 0) || (3 < (short)iVar4)) {
        *(undefined2 *)(&DAT_800b1de2 + ((iVar4 << 0x10) >> 0xd)) = 0;
      }
      iVar2 = iVar4 << 0x10;
      iVar4 = iVar4 + 1;
      iVar2 = iVar2 >> 0xd;
      (&DAT_800b1de5)[iVar2] = 0;
      *(undefined2 *)(&DAT_800b1de6 + iVar2) = 0;
    } while (iVar4 * 0x10000 >> 0x10 < 6);
    _DAT_800b1de2 = 100;
    _DAT_800b1dea = 0x32;
    DAT_800b1de1 = 0;
    DAT_800b1de0 = 0;
    DAT_800b1e2c = 0xff;
    _DAT_800b1e36 = 0x4b;
    _DAT_800b1c58 = 100;
    _DAT_800b1e30 = 5;
    _DAT_800b1d62 = 0;
    _DAT_800b1e4a = 0;
    Pl_SetStateBits((_PLAYER *)&Player,0x20);
  }
  _DAT_800b1d34 = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pl_AddPlayer(struct _PLAYER *pl /*$s0*/, long entry /*$a1*/)
 // line 282, offset 0x800320b8
	/* begin block 1 */
		// Start line: 283
		// Start offset: 0x800320B8
		// Variables:
	// 		struct _ZONE *z; // $s1
	/* end block 1 */
	// End offset: 0x800320B8
	// End Line: 283

	/* begin block 2 */
		// Start line: 729
	/* end block 2 */
	// End Line: 730

void Pl_AddPlayer(_PLAYER *pl,long entry)

{
  _ZONE *p_Var1;
  TASK *pTVar2;
  
  p_Var1 = Zone_GetEntry(entry);
  *(undefined2 *)((int)&(pl->m_obj).Env.Obj.n_normal + 2) = 0;
  pTVar2 = Task_Add(Pl_TaskTest,0x300);
  *(TASK **)(pl->m_obj).Ani.Anim.Reserved = pTVar2;
  *(_PLAYER **)&pTVar2->local = pl;
  *(_ZONE **)(*(int *)(pl->m_obj).Ani.Anim.Reserved + 0x2c) = p_Var1;
  Manim_SetEffect((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data,
                  (TDRFuncPtr_Manim_SetEffect1f)0x0);
  (pl->obj).color = 0x808080;
  (pl->m_obj).Ani.Anim.Flags = 0xffff;
  (pl->m_obj).shadow.x1 = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pl_DeletePlayer(struct _PLAYER *pl /*$s0*/)
 // line 304, offset 0x80032134
	/* begin block 1 */
		// Start line: 786
	/* end block 1 */
	// End Line: 787

void Pl_DeletePlayer(_PLAYER *pl)

{
  D3_DeleteObject((_D3_OBJECT *)pl);
  Task_Kill(*(TASK **)(pl->m_obj).Ani.Anim.Reserved);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pl_InitLevel()
 // line 311, offset 0x80032164
	/* begin block 1 */
		// Start line: 312
		// Start offset: 0x80032164
		// Variables:
	// 		long i; // $s0
	/* end block 1 */
	// End offset: 0x800321E0
	// End Line: 325

	/* begin block 2 */
		// Start line: 800
	/* end block 2 */
	// End Line: 801

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pl_InitLevel(void)

{
  long lVar1;
  int iVar2;
  int iVar3;
  
  Pl_Snds = File_Read(PTR_DAT_800a69d0,(void *)0x0);
  lVar1 = Sound_TransferVAG(Pl_Snds,0,(void *)0x0);
  Pl_SoundsId = (short)lVar1;
  Pl_nSounds = *(short *)Pl_Snds;
  iVar3 = 1;
  iVar2 = 0x10000;
  if (1 < Pl_nSounds) {
    do {
      Sound_TransferVAG(Pl_Snds,(short)((uint)iVar2 >> 0x10),(void *)0x0);
      iVar3 = iVar3 + 1;
      iVar2 = iVar3 * 0x10000;
    } while (iVar3 < (int)Pl_nSounds);
  }
  Heap_FreeMem(Pl_Snds);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pl_DeleteLevel()
 // line 331, offset 0x800321fc
	/* begin block 1 */
		// Start line: 332
		// Start offset: 0x800321FC
		// Variables:
	// 		long i; // $s0
	/* end block 1 */
	// End offset: 0x8003223C
	// End Line: 338

	/* begin block 2 */
		// Start line: 854
	/* end block 2 */
	// End Line: 855

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pl_DeleteLevel(void)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < Pl_nSounds) {
    do {
      Sound_FreeSRAM((char)Pl_SoundsId + (char)iVar1);
      iVar1 = iVar1 + 1;
    } while (iVar1 < (int)Pl_nSounds);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pl_DeleteWholePlayer()
 // line 341, offset 0x8003224c
	/* begin block 1 */
		// Start line: 342
		// Start offset: 0x8003224C
	/* end block 1 */
	// End offset: 0x8003224C
	// End Line: 342

	/* begin block 2 */
		// Start line: 879
	/* end block 2 */
	// End Line: 880

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pl_DeleteWholePlayer(void)

{
  Heap_FreeMem(Pl_Lnk);
  Shp_GroupRelease(Pl_Pcl,1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pl_Pause()
 // line 353, offset 0x8003227c
	/* begin block 1 */
		// Start line: 905
	/* end block 1 */
	// End Line: 906

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pl_Pause(void)

{
  *(undefined2 *)(_DAT_800b1d2c + 0x54) = 0;
  *(undefined4 *)(_DAT_800b1d30 + 0x20) = 0;
  Task_DisableList(*(TASK **)(_DAT_800b1d2c + 0xc));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pl_Unpause()
 // line 364, offset 0x800322bc
	/* begin block 1 */
		// Start line: 927
	/* end block 1 */
	// End Line: 928

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pl_Unpause(void)

{
  *(undefined2 *)(_DAT_800b1d2c + 0x54) = 1;
  *(undefined4 *)(_DAT_800b1d30 + 0x20) = 0x800328e0;
  Task_EnableList(*(TASK **)(_DAT_800b1d2c + 0xc));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pl_TaskTest()
 // line 381, offset 0x80032304
	/* begin block 1 */
		// Start line: 382
		// Start offset: 0x80032304
		// Variables:
	// 		struct _PLAYER *pl; // $s1
	// 		struct _ZONE *z; // $s0
	// 		long dblast5; // $s4
	// 		long dblast6; // $s3
	// 		long dblast7; // $s2
	// 		long sunk; // $s5
	/* end block 1 */
	// End offset: 0x800326F8
	// End Line: 511

	/* begin block 2 */
		// Start line: 963
	/* end block 2 */
	// End Line: 964

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pl_TaskTest(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  ushort uVar8;
  ushort uVar9;
  ushort uVar10;
  ushort uVar11;
  short sVar12;
  short sVar13;
  bool bVar14;
  bool bVar15;
  ushort uVar16;
  ushort uVar17;
  TASK *pTVar18;
  void *Lnk;
  TASK *t;
  int Param;
  _PLAYER *pl;
  ushort uVar19;
  ushort uVar20;
  ushort uVar21;
  ushort uVar22;
  
  bVar14 = false;
  uVar19 = 0;
  pl = (_PLAYER *)TaskCurrent->local;
  uVar20 = 0;
  pTVar18 = Task_Link(Pl_TaskMove,0x900);
  t = TaskCurrent;
  *(TASK **)&(pl->m_obj).Ani.Anim.Rot = pTVar18;
  (pl->m_obj).dummy1 = 0;
  (pl->m_obj).nAnim = 0;
  sVar12 = Pvl_PlayerNumber;
  Param = t->s0;
  (pl->obj).collision_state = 8;
  uVar21 = 0;
  if (sVar12 == 5) {
    Lnk = FileGroup_GetAddr(Pl_Lnk,8);
    Pan_AddAnimal(pl,Lnk);
  }
  PSpell_RestoreSpell(pl);
  if (((*(short *)(Param + 0x28) != 0) && (**(int **)(Param + 0x2c) != 0)) &&
     (t = *(TASK **)(**(int **)(Param + 0x2c) + 0x14), t != (TASK *)0x0)) {
    Task_EventExec(t,8,(long)pl);
  }
  Pl_ForceAction(pl,0,Param);
  Task_EventExec(Overlay_Handle,Overlay_Handle->event_msg | 0xfc,Overlay_Handle->event_param);
  Track_SetMode(1,0);
  do {
    if (((pl->obj).collision_state & 8U) == 0) {
      if (((pl->obj).collision_state & 2U) != 0) {
        Pl_ForceAction(pl,0xf,(pl->m_obj).Env.Obj.n_vert);
      }
      if (bVar14) {
        if (((pl->obj).collision_state & 0x20U) == 0) {
          bVar14 = false;
          goto LAB_8003247c;
        }
LAB_80032490:
        bVar15 = true;
        if (!bVar14) {
          Fx_Play(0x1b,(char)pl + ',');
          bVar15 = true;
        }
      }
      else {
LAB_8003247c:
        bVar15 = bVar14;
        if (((pl->obj).collision_state & 0x20U) != 0) goto LAB_80032490;
      }
      uVar17 = Pvl_Trig0;
      uVar1 = Pvl_Run0;
      if ((pl->m_obj).shadow.x1 == 0) {
        (pl->m_obj).nAnim = Pvl_Trig0;
        (pl->m_obj).dummy1 = uVar1;
        uVar1 = (pl->m_obj).dummy1;
        uVar16 = *(ushort *)&(pl->m_obj).shadow.b0 | uVar17;
        *(ushort *)&(pl->m_obj).shadow.b0 = uVar16;
        *(ushort *)&(pl->m_obj).shadow.b0 = uVar16 & uVar1;
        uVar1 = (pl->m_obj).effect_subtype;
        uVar16 = *(ushort *)&(pl->m_obj).shadow.tag;
        (pl->m_obj).nFrame = uVar1 & uVar17;
        uVar1 = uVar1 | uVar16;
        uVar16 = *(ushort *)((int)&(pl->m_obj).shadow.tag + 2);
        uVar2 = (pl->m_obj).nAnim;
        (pl->m_obj).nFrame = uVar17 & uVar1;
        uVar17 = uVar17 & (uVar1 | uVar16);
        uVar1 = *(ushort *)&(pl->m_obj).shadow.r0;
        (pl->m_obj).nFrame = uVar17;
        uVar17 = uVar17 | uVar1 & uVar2;
        (pl->m_obj).nFrame = uVar17;
        uVar17 = uVar17 | uVar2 & uVar21;
        (pl->m_obj).nFrame = uVar17;
        uVar17 = uVar17 | (pl->m_obj).nAnim & uVar20;
        (pl->m_obj).nFrame = uVar17;
        uVar17 = uVar17 | (pl->m_obj).nAnim & uVar19;
        uVar1 = *(ushort *)&(pl->m_obj).shadow.tag;
        (pl->m_obj).nFrame = uVar17;
        uVar17 = uVar17 | uVar1 & (pl->m_obj).effect_subtype;
        uVar1 = *(ushort *)((int)&(pl->m_obj).shadow.tag + 2);
        uVar16 = (pl->m_obj).effect_subtype;
        (pl->m_obj).nFrame = uVar17;
        uVar2 = *(ushort *)&(pl->m_obj).shadow.r0;
        uVar17 = uVar17 | uVar1 & (pl->m_obj).effect_subtype;
        (pl->m_obj).nFrame = uVar17;
        uVar17 = uVar17 | uVar2 & uVar16;
        (pl->m_obj).nFrame = uVar17;
        uVar1 = *(ushort *)&(pl->m_obj).shadow.tag;
        uVar2 = *(ushort *)((int)&(pl->m_obj).shadow.tag + 2);
        uVar3 = *(ushort *)&(pl->m_obj).shadow.r0;
        uVar4 = *(ushort *)&(pl->m_obj).shadow.tag;
        uVar5 = *(ushort *)((int)&(pl->m_obj).shadow.tag + 2);
        uVar6 = *(ushort *)&(pl->m_obj).shadow.r0;
        uVar7 = *(ushort *)&(pl->m_obj).shadow.tag;
        uVar8 = *(ushort *)((int)&(pl->m_obj).shadow.tag + 2);
        uVar9 = *(ushort *)&(pl->m_obj).shadow.r0;
        uVar22 = *(ushort *)&(pl->m_obj).shadow.r0;
        uVar17 = uVar17 | (pl->m_obj).effect_subtype & uVar21;
        (pl->m_obj).nFrame = uVar17;
        uVar17 = uVar17 | uVar16 & uVar20;
        (pl->m_obj).nFrame = uVar17;
        uVar17 = uVar17 | uVar16 & uVar19;
        uVar16 = *(ushort *)((int)&(pl->m_obj).shadow.tag + 2);
        uVar10 = *(ushort *)&(pl->m_obj).shadow.tag;
        uVar11 = *(ushort *)&(pl->m_obj).shadow.tag;
        (pl->m_obj).nFrame = uVar17;
        uVar17 = uVar17 | uVar16 & uVar10;
        uVar16 = *(ushort *)&(pl->m_obj).shadow.r0;
        uVar10 = *(ushort *)((int)&(pl->m_obj).shadow.tag + 2);
        (pl->m_obj).nFrame = uVar17;
        uVar17 = uVar17 | uVar16 & uVar11;
        uVar16 = *(ushort *)&(pl->m_obj).shadow.r0;
        (pl->m_obj).nFrame = uVar17;
        uVar17 = uVar17 | uVar7 & uVar21;
        (pl->m_obj).nFrame = uVar17;
        uVar17 = uVar17 | uVar4 & uVar20;
        (pl->m_obj).nFrame = uVar17;
        uVar17 = uVar17 | uVar1 & uVar19;
        (pl->m_obj).nFrame = uVar17;
        uVar17 = uVar17 | uVar16 & uVar10;
        (pl->m_obj).nFrame = uVar17;
        uVar17 = uVar17 | uVar8 & uVar21;
        (pl->m_obj).nFrame = uVar17;
        uVar17 = uVar17 | uVar5 & uVar20;
        (pl->m_obj).nFrame = uVar17;
        uVar17 = uVar17 | uVar2 & uVar19;
        (pl->m_obj).nFrame = uVar17;
        uVar17 = uVar17 | uVar9 & uVar21;
        (pl->m_obj).nFrame = uVar17;
        uVar17 = uVar17 | uVar6 & uVar20;
        (pl->m_obj).nFrame = uVar17;
        (pl->m_obj).nFrame = uVar17 | uVar3 & uVar19 | uVar20 & uVar21 | uVar19 & uVar21;
        *(ushort *)&(pl->m_obj).shadow.r0 = uVar10;
        sVar12 = (pl->m_obj).effect_subtype;
        sVar13 = (pl->m_obj).nAnim;
        *(ushort *)((int)&(pl->m_obj).shadow.tag + 2) = uVar11;
        *(short *)&(pl->m_obj).shadow.tag = sVar12;
        (pl->m_obj).effect_subtype = sVar13;
        uVar19 = uVar20;
      }
      else {
        (pl->m_obj).dummy1 = 0;
        (pl->m_obj).nAnim = 0;
        *(undefined2 *)&(pl->m_obj).shadow.b0 = 0;
        (pl->m_obj).nFrame = 0;
        (pl->m_obj).effect_subtype = 0;
        *(undefined2 *)&(pl->m_obj).shadow.tag = 0;
        *(undefined2 *)((int)&(pl->m_obj).shadow.tag + 2) = 0;
        *(undefined2 *)&(pl->m_obj).shadow.r0 = 0;
        uVar22 = uVar21;
        uVar21 = uVar20;
      }
      Pl_GetAction(pl);
      bVar14 = bVar15;
      uVar20 = uVar21;
      uVar21 = uVar22;
    }
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pl_TaskMove()
 // line 514, offset 0x800326f8
	/* begin block 1 */
		// Start line: 515
		// Start offset: 0x800326F8
		// Variables:
	// 		struct _PLAYER *pl; // $s1
	// 		struct PLAYER_104fake t; // stack offset -48
	/* end block 1 */
	// End offset: 0x80032800
	// End Line: 559

	/* begin block 2 */
		// Start line: 1490
	/* end block 2 */
	// End Line: 1491

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pl_TaskMove(void)

{
  byte bVar1;
  TASK *pTVar2;
  long lVar3;
  ulong uVar4;
  int wPlayId;
  undefined4 uVar5;
  _PLAYER *pl;
  undefined auStack48 [32];
  
  pl = (_PLAYER *)TaskCurrent->local;
  Text_SetContext((TEXT_102fake *)auStack48);
  Text_SetContextFont(0x70);
  Text_SetContextXY(0,0);
  Text_SetContextWH(Scr_W,Scr_H);
  Text_SetContextRange(0);
  Text_SetContextMode(0);
  Task_Next();
  lVar3 = Task_EventWait();
  (pl->m_obj).shadow.y1 = (short)lVar3 + -1;
  TaskCurrent->display = Pl_TaskState;
  wPlayId = (int)(short)(pl->m_obj).Ani.Anim.Flags;
  (pl->m_obj).shadow.clut = *(ushort *)&(pl->m_obj).shadow.u0;
  bVar1 = *(byte *)&(pl->m_obj).shadow.y1;
  *(undefined4 *)&(pl->m_obj).Ani.Anim.Trans = 0;
  (pl->m_obj).Scale = 0;
  *(undefined2 *)&(pl->m_obj).shadow.u0 = *(undefined2 *)&Pl_Actions[(uint)bVar1].mode;
  if (-1 < wPlayId) {
    Sound_Stop(wPlayId,0);
    (pl->m_obj).Ani.Anim.Flags = 0xffff;
  }
  if (((pl->m_obj).shadow.clut & 8) != 0) {
    (pl->obj).rot.vz = (pl->obj).rot.vz + *(short *)&(pl->m_obj).shadow.u1 & 0xfff;
  }
  uVar4 = (pl->m_obj).Ani.Text;
  uVar5 = *(undefined4 *)&(pl->m_obj).Ani.Anim;
  *(undefined4 *)((pl->m_obj).Env.Obj.primitive_top.Data + 4) =
       *(undefined4 *)&(pl->m_obj).Env.Data.nPrim;
  *(ulong *)((pl->m_obj).Env.Obj.primitive_top.Data + 8) = uVar4;
  *(undefined4 *)((pl->m_obj).Env.Obj.primitive_top.Data + 0xc) = uVar5;
  D3_SetLowBox((_D3_OBJECT *)pl,-0x14,-0x14,0x14,0x14,0);
  D3_SetHighBox((_D3_OBJECT *)pl,-0x14,-0x14,0x14,0x14,
                (uint)*(ushort *)((pl->env2).Obj.primitive_top.Data + 10));
  D3_SetCollBits((_D3_OBJECT *)pl,8);
  *(undefined2 *)&(pl->m_obj).Sq.Data.nSon = 0xffff;
  (pl->m_obj).Ani.Anim.nPivot = 0xffff;
  (pl->m_obj).Ani.Anim.nFrame = 0xffff;
  (pl->m_obj).Ani.Anim.Speed = 0xffff;
  pTVar2 = TaskCurrent;
  (pl->obj).rot.vy = 0;
  (pl->obj).rot.vx = 0;
  pTVar2->event_enable = 1;
  (*Pl_Actions[(uint)*(byte *)&(pl->m_obj).shadow.y1].function)();
  TaskCurrent->event_enable = 1;
  Pl_SetAction(pl,3,0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pl_TaskState()
 // line 588, offset 0x800328e0
	/* begin block 1 */
		// Start line: 589
		// Start offset: 0x800328E0
		// Variables:
	// 		struct _PLAYER *pl; // $s0
	// 		struct _D3_OBJECT *ot; // $s1
	// 		long hp; // $s2
	// 		long all; // $a0

		/* begin block 1.1 */
			// Start line: 669
			// Start offset: 0x80032B50
			// Variables:
		// 		long fx; // $s1
		// 		long r; // $s2
		/* end block 1.1 */
		// End offset: 0x80032C10
		// End Line: 696
	/* end block 1 */
	// End offset: 0x80032D34
	// End Line: 737

	/* begin block 2 */
		// Start line: 1667
	/* end block 2 */
	// End Line: 1668

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pl_TaskState(void)

{
  char cVar1;
  ushort snd;
  bool bVar2;
  char cVar3;
  long lVar4;
  uint uVar5;
  TDRFuncPtr_Manim_SetEffect1f pTVar6;
  short Fx;
  code *f;
  _PLAYER *pl;
  int iVar7;
  long unaff_s2;
  
  pl = (_PLAYER *)TaskCurrent->local;
  if (((pl->obj).collision_state & 8U) != 0) {
    return;
  }
  D3_SetCollBits((_D3_OBJECT *)pl,1);
  Pafh_TestHold(pl);
  Pl_AdjustPosZ(pl);
  if (((pl->obj).hit_points == 0) && ((*(ushort *)&(pl->m_obj).shadow.u0 & 4) == 0)) {
    Pl_ForceAction(pl,0x10,0);
  }
  Pl_ManageStateBits(pl);
  Pl_DisplayLookDisable();
  cVar3 = (char)pl;
  if (((pl->obj).collision_state & 0x20U) != 0) {
    *(undefined2 *)((int)&(pl->m_obj).Env.Obj.n_primitive + 2) = 0xc0;
    iVar7 = *(int *)&(pl->m_obj).Env.Obj.normal_top;
    if ((Scr_Frame != 0) && (lVar4 = M_rand(), lVar4 == (lVar4 / 3) * 3)) {
      D3_Splash((_D3_OBJECT *)pl);
    }
    cVar1 = *(char *)(iVar7 + 0x99);
    if (cVar1 == '\x02') {
LAB_80032a1c:
      unaff_s2 = 0;
    }
    else {
      if (cVar1 < '\x03') {
        if (cVar1 == '\x01') goto LAB_80032a1c;
      }
      else {
        if (cVar1 == '\x03') {
          unaff_s2 = 1;
        }
        else {
          if (cVar1 == '\x04') {
            unaff_s2 = 100;
          }
        }
      }
    }
    if (*(short *)(iVar7 + 0x9e) != 0) {
      Pl_SetStateBits(pl,4);
    }
    if (((((pl->obj).collision_state & 8U) == 0) && (unaff_s2 == 0)) &&
       ((int)(pl->obj).pos.vz + (int)(short)(pl->m_obj).Sq.Header.Version <
        (int)*(short *)(iVar7 + 0x70) + (int)*(short *)(iVar7 + 0x30) +
        (int)*(short *)(iVar7 + 0x9a))) {
      unaff_s2 = Pl_DisplayAir();
      bVar2 = true;
    }
    else {
      (pl->m_obj).shadow.x2 = -1;
      bVar2 = false;
    }
    if ((((pl->m_obj).shadow.y2 & 0x20U) != 0) || ((pl->env2).Obj.primitive_top.Data[4] == 6)) {
      unaff_s2 = 0;
    }
    if (unaff_s2 != 0) {
      if (((Pvl_GameTime & 0x1fU) == 0) && (!bVar2)) {
        Fx_Play(1,cVar3 + ',');
      }
      if (Scr_Frame != 0) {
        Pl_ReduceHitPoints(pl,(short)unaff_s2);
      }
    }
  }
  if ((*(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x22) != 0) &&
     ((*(ushort *)&(pl->m_obj).Env.Obj.n_primitive & 1) != 0)) {
    if ((*(ushort *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x22) & 1) != 0) {
      snd = (pl->obj).collision_state;
      iVar7 = 0x12;
      if (((snd & 0x20) == 0) && (iVar7 = 0x16, (snd & 0x4000) != 0)) {
        Fx = *(short *)(*(int *)&(pl->m_obj).Env.Obj.vert_top.vz + 0x6a);
        if (Fx == 2) {
          iVar7 = 0x10;
        }
        else {
          if (Fx < 3) {
            if (Fx == 0) {
              iVar7 = 0x14;
            }
          }
          else {
            if (Fx == 4) {
              iVar7 = 0x18;
            }
          }
        }
      }
      uVar5 = M_rand();
      Fx = (short)((iVar7 + (uVar5 & 1)) * 0x10000 >> 0x10);
      if ((pl->env2).Obj.primitive_top.Data[4] == 6) {
        Fx_PlaySoft(Fx,cVar3 + ',');
      }
      else {
        Fx_Play(Fx,cVar3 + ',');
      }
    }
    if (((*(ushort *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x22) & 2) != 0) &&
       (snd = (pl->m_obj).Ani.Anim.nPivot, -1 < (short)snd)) {
      D3_PlaySound((_D3_OBJECT *)pl,snd);
    }
    if (((*(ushort *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x22) & 4) != 0) &&
       (snd = (pl->m_obj).Ani.Anim.nFrame, -1 < (short)snd)) {
      D3_PlaySound((_D3_OBJECT *)pl,snd);
    }
    if (((*(ushort *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x22) & 8) != 0) &&
       (snd = (pl->m_obj).Ani.Anim.Speed, -1 < (short)snd)) {
      D3_PlaySound((_D3_OBJECT *)pl,snd);
    }
  }
  if ((*(ushort *)&(pl->m_obj).shadow.u0 & 0x80) == 0) goto LAB_80032d24;
  snd = (pl->m_obj).shadow.tpage;
  if (snd == 1) {
    pTVar6 = *(TDRFuncPtr_Manim_SetEffect1f *)&(pl->m_obj).Env.Data;
    f = Motion2D_ManimSmallBurn;
  }
  else {
    if ((short)snd < 2) {
      if (snd != 0) goto LAB_80032d24;
      Impact_Smoke(cVar3 + ',',1);
      pTVar6 = *(TDRFuncPtr_Manim_SetEffect1f *)&(pl->m_obj).Env.Data;
      f = Motion2D_ManimBurn;
    }
    else {
      if (snd != 2) goto LAB_80032d24;
      pTVar6 = *(TDRFuncPtr_Manim_SetEffect1f *)&(pl->m_obj).Env.Data;
      f = Motion2D_ManimElectricity;
    }
  }
  if (pTVar6 != f) {
    Manim_SetEffect((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data,f);
  }
LAB_80032d24:
  (pl->obj).collision_state = (pl->obj).collision_state & 0xfffd;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pl_ManageStateBits(struct _PLAYER *pl /*$s0*/)
 // line 740, offset 0x80032d4c
	/* begin block 1 */
		// Start line: 741
		// Start offset: 0x80032D4C
		// Variables:
	// 		struct PLAYER_8fake color; // stack offset -16
	/* end block 1 */
	// End offset: 0x8003301C
	// End Line: 811

	/* begin block 2 */
		// Start line: 1977
	/* end block 2 */
	// End Line: 1978

/* WARNING: Could not reconcile some variable overlaps */

void Pl_ManageStateBits(_PLAYER *pl)

{
  ushort uVar1;
  short sVar2;
  uint3 uVar3;
  int iVar4;
  undefined uVar5;
  undefined uVar6;
  uint uVar7;
  undefined4 local_10;
  
  uVar7 = (pl->obj).color;
  uVar1 = (pl->m_obj).shadow.y2;
  (pl->obj).color = 0x808080;
  local_10._1_1_ = (byte)(uVar7 >> 8);
  local_10._3_1_ = (undefined)(uVar7 >> 0x18);
  if ((uVar1 & 1) == 0) {
    if ((uVar1 & 0x20) == 0) {
      if ((uVar1 & 0x1e) == 0) goto LAB_80032ea8;
      local_10._0_2_ = (ushort)uVar7;
      uVar3 = (uint3)(uVar7 >> 8);
      if (local_10._1_1_ == 0xff) {
        uVar7 = (uVar7 & 0xff) + 8;
        if (0x80 < uVar7) {
          uVar7 = 0x80;
        }
        local_10._0_3_ = CONCAT12((char)uVar7,(ushort)local_10);
        local_10._1_3_ = uVar3 & 0xff0000 | (uint3)local_10 >> 8;
        local_10 = uVar7 & 0xff | (uint)local_10._1_3_ << 8;
        if ((uVar7 & 0xff) == 0x80) {
          local_10._0_1_ = (undefined)(uVar7 & 0xff);
          local_10._0_2_ = CONCAT11(0xfe,(undefined)local_10);
          local_10 = (uint)local_10._1_3_ << 8 & 0xffff0000 | (uint)(ushort)local_10;
        }
      }
      else {
        uVar7 = (uVar7 & 0xff) - 8;
        if ((int)uVar7 < 0) {
          uVar7 = 0;
        }
        local_10._0_3_ = CONCAT12((char)uVar7,(ushort)local_10);
        local_10._1_3_ = uVar3 & 0xff0000 | (uint3)local_10 >> 8;
        local_10 = uVar7 & 0xff | (uint)local_10._1_3_ << 8;
        if ((uVar7 & 0xff) == 0) {
          local_10._0_1_ = (undefined)(uVar7 & 0xff);
          local_10._0_2_ = CONCAT11(0xff,(undefined)local_10);
          local_10 = (uint)local_10._1_3_ << 8 & 0xffff0000 | (uint)(ushort)local_10;
        }
      }
    }
    else {
      if ((*(ushort *)&(pl->m_obj).shadow.u2 & 1) == 0) {
        (pl->obj).color = 0x808080;
        goto LAB_80032ea8;
      }
      local_10 = 0xffffff;
    }
  }
  else {
    uVar5 = (undefined)((uint)local_10._1_1_ + 4);
    if (0x80 < (uint)local_10._1_1_ + 4) {
      uVar5 = 0x80;
    }
    _uVar6 = (uVar7 & 0xff) - 4;
    uVar6 = (undefined)_uVar6;
    uVar7 = _uVar6 & 0xff;
    if ((int)_uVar6 < 0x80) {
      uVar6 = 0x80;
      uVar7 = 0x80;
    }
    local_10 = CONCAT31(CONCAT21(CONCAT11(local_10._3_1_,uVar5),uVar5),uVar6);
    if (uVar7 < 0x81) {
      Pl_ClearStateBits(pl,1);
    }
  }
  (pl->obj).color = local_10;
LAB_80032ea8:
  uVar1 = (pl->m_obj).shadow.y2;
  if ((uVar1 & 0x20) == 0) {
    if ((uVar1 & 2) != 0) {
      iVar4 = (uint)(*(ushort *)((pl->env2).Obj.primitive_top.Data + 0x10) >> 8) + 1;
      if (iVar4 == 0) {
        trap(0x1c00);
      }
      if ((iVar4 == -1) && (Pvl_GameTime == -0x80000000)) {
        trap(0x1800);
      }
      if (Pvl_GameTime % iVar4 == 0) {
        Pl_ReduceHitPoints(pl,1);
      }
    }
    if (((pl->m_obj).shadow.y2 & 4U) != 0) {
      uVar7 = (uint)(*(ushort *)((pl->env2).Obj.primitive_top.Data + 0x10) >> 7) | 1;
      if (uVar7 == 0) {
        trap(0x1c00);
      }
      if ((uVar7 == 0xffffffff) && (Pvl_GameTime == -0x80000000)) {
        trap(0x1800);
      }
      if (Pvl_GameTime % uVar7 == 0) {
        Pl_ReduceHitPoints(pl,1);
      }
    }
  }
  else {
    sVar2 = *(short *)&(pl->m_obj).shadow.u2;
    *(short *)&(pl->m_obj).shadow.u2 = sVar2 + -1;
    if (sVar2 == 1) {
      Pl_ClearStateBits(pl,0x20);
    }
  }
  if (((pl->m_obj).shadow.y2 & 8U) != 0) {
    sVar2 = *(short *)&(pl->m_obj).shadow.u2;
    *(undefined2 *)((int)&(pl->m_obj).Env.Obj.scale + 2) = 0xc0;
    *(short *)&(pl->m_obj).shadow.u2 = sVar2 + -1;
    if (sVar2 == 1) {
      Pl_ClearStateBits(pl,8);
    }
  }
  if ((((pl->m_obj).shadow.y2 & 0x10U) != 0) &&
     (sVar2 = *(short *)&(pl->m_obj).shadow.u2, *(short *)&(pl->m_obj).shadow.u2 = sVar2 + -1,
     sVar2 == 1)) {
    Pl_ClearStateBits(pl,0x10);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pl_SetStateBits(struct _PLAYER *pl /*$s1*/, long bits /*$s0*/)
 // line 814, offset 0x8003302c
	/* begin block 1 */
		// Start line: 2137
	/* end block 1 */
	// End Line: 2138

void Pl_SetStateBits(_PLAYER *pl,long bits)

{
  ushort uVar1;
  uint uVar2;
  short sVar3;
  ushort uVar4;
  
  uVar4 = (ushort)bits;
  if ((bits & 0x20U) != 0) {
    uVar1 = (pl->m_obj).shadow.y2;
    *(short *)&(pl->m_obj).shadow.u2 = Scr_TicksPerSecond * 5;
    (pl->m_obj).shadow.y2 = uVar1 & 0xffe7;
  }
  if ((bits & 1U) != 0) {
    (pl->obj).color = 0xfc;
  }
  if (((pl->m_obj).shadow.y2 & 0x20U) == 0) {
    if ((bits & 0x18U) != 0) {
      sVar3 = Scr_TicksPerSecond *
              ((short)((int)(0x1e - (uint)(*(ushort *)((pl->env2).Obj.primitive_top.Data + 0x10) >>
                                          8)) / 10) + 10);
      uVar1 = (pl->m_obj).shadow.y2;
      *(short *)&(pl->m_obj).shadow.u2 = Scr_TicksPerSecond;
      (pl->m_obj).shadow.y2 = uVar1 & 0xffe7;
      *(short *)&(pl->m_obj).shadow.u2 = sVar3;
    }
    uVar2 = bits & 2;
    if ((bits & 4U) != 0) {
      if (((pl->m_obj).shadow.y2 & 2U) != 0) {
        bits = bits & 0xfffffffb;
      }
      uVar4 = (ushort)bits;
      uVar2 = bits & 2;
    }
    if (uVar2 != 0) {
      Pl_ClearStateBits(pl,4);
    }
    (pl->m_obj).shadow.y2 = (pl->m_obj).shadow.y2 | uVar4;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pl_ClearStateBits(struct _PLAYER *pl /*$a0*/, long bits /*$a1*/)
 // line 853, offset 0x80033150
	/* begin block 1 */
		// Start line: 2224
	/* end block 1 */
	// End Line: 2225

void Pl_ClearStateBits(_PLAYER *pl,long bits)

{
  if (((bits & 0x38U) != 0) && (((int)(pl->m_obj).shadow.y2 & bits) != 0)) {
    *(undefined2 *)&(pl->m_obj).shadow.u2 = 0;
  }
  (pl->m_obj).shadow.y2 = (pl->m_obj).shadow.y2 & ~(ushort)bits;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pl_DisplayLookDisable()
 // line 868, offset 0x80033188
	/* begin block 1 */
		// Start line: 870
		// Start offset: 0x80033188
		// Variables:
	// 		struct _PLAYER *pl; // $a0
	/* end block 1 */
	// End offset: 0x80033240
	// End Line: 876

	/* begin block 2 */
		// Start line: 2254
	/* end block 2 */
	// End Line: 2255

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pl_DisplayLookDisable(void)

{
  _SCREEN *p_Var1;
  uint *puVar2;
  
  p_Var1 = Scr;
  if ((((*(ushort *)((int)TaskCurrent->local + 0x108) & PJOY_AIM) != 0) &&
      ((*(ushort *)((int)TaskCurrent->local + 0x10a) & PJOY_AIM) == 0)) && (Track_HasLooked == 0)) {
    puVar2 = (uint *)(&Pl_CameraPrims + (int)Scr_Frame * 0x28);
    *puVar2 = *puVar2 & 0xff000000 | Scr->ot[1] & 0xffffff;
    p_Var1->ot[1] = p_Var1->ot[1] & 0xff000000 | (uint)puVar2 & 0xffffff;
  }
  Track_HasLooked = 0;
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Pl_DisplayAir()
 // line 880, offset 0x80033250
	/* begin block 1 */
		// Start line: 882
		// Start offset: 0x80033250
		// Variables:
	// 		struct _PLAYER *pl; // $a1
	// 		long hp; // $t1
	// 		long w; // $a2
	/* end block 1 */
	// End offset: 0x800332E0
	// End Line: 904

	/* begin block 2 */
		// Start line: 2278
	/* end block 2 */
	// End Line: 2279

/* WARNING: Unknown calling convention yet parameter storage is locked */

long Pl_DisplayAir(void)

{
  char cVar1;
  _SCREEN *p_Var2;
  short sVar3;
  int iVar4;
  uint *puVar5;
  void *pvVar6;
  uint *puVar7;
  int iVar8;
  long lVar9;
  
  pvVar6 = TaskCurrent->local;
  iVar8 = (uint)(*(ushort *)((int)pvVar6 + 0x200) >> 8) * -8 + 0x100;
  lVar9 = 0;
  if (iVar8 < 0x10) {
    iVar8 = 0x10;
  }
  iVar4 = (int)*(short *)((int)pvVar6 + 0x128);
  if (iVar4 < 0) {
    sVar3 = 0x6400;
  }
  else {
    if (iVar4 == 0) {
      lVar9 = (long)Scr_Frame;
      goto LAB_800332c8;
    }
    sVar3 = *(short *)((int)pvVar6 + 0x128) - (short)iVar8;
    if (iVar4 - iVar8 < 0) {
      sVar3 = 0;
    }
  }
  *(short *)((int)pvVar6 + 0x128) = sVar3;
LAB_800332c8:
  if ((*(ushort *)((int)pvVar6 + 0x12a) & 0x20) != 0) {
    lVar9 = 0;
  }
  iVar8 = (((int)((uint)*(ushort *)((int)pvVar6 + 0x128) << 0x10) >> 0x18) * 0x35) / 100;
  cVar1 = (char)iVar8;
  (&DAT_800b1b94)[(int)Scr_Frame * 0x28] = (&DAT_800b1b8c)[(int)Scr_Frame * 0x28] + cVar1;
  (&DAT_800b1ba4)[(int)Scr_Frame * 0x28] = (&DAT_800b1b8c)[(int)Scr_Frame * 0x28] + cVar1;
  iVar4 = (int)Scr_Frame * 0x28;
  puVar7 = (uint *)(&Pl_AirPrims + iVar4);
  sVar3 = (short)iVar8;
  *(short *)(&DAT_800b1b90 + iVar4) = *(short *)(&DAT_800b1b88 + iVar4) + sVar3;
  p_Var2 = Scr;
  puVar5 = (uint *)(&DAT_800b1b80 + iVar4);
  *(short *)(&DAT_800b1ba0 + iVar4) = *(short *)(&DAT_800b1b88 + iVar4) + sVar3;
  *puVar5 = *puVar5 & 0xff000000 | *p_Var2->ot & 0xffffff;
  *p_Var2->ot = *p_Var2->ot & 0xff000000 | (uint)puVar5 & 0xffffff;
  *puVar7 = *puVar7 & 0xff000000 | *p_Var2->ot & 0xffffff;
  *p_Var2->ot = *p_Var2->ot & 0xff000000 | (uint)puVar7 & 0xffffff;
  return lVar9;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Pl_AcceptCollisioned(struct _D3_OBJECT *ot /*$a2*/, struct _D3_OBJECT *obj /*$a1*/, long bits /*$a2*/)
 // line 933, offset 0x80033438
	/* begin block 1 */
		// Start line: 934
		// Start offset: 0x80033438
		// Variables:
	// 		struct _PLAYER *pl; // $a0
	/* end block 1 */
	// End offset: 0x800334F8
	// End Line: 970

	/* begin block 2 */
		// Start line: 2434
	/* end block 2 */
	// End Line: 2435

long Pl_AcceptCollisioned(_D3_OBJECT *ot,_D3_OBJECT *obj,long bits)

{
  if ((ot->collision_mode & 0x1000U) == 0) {
    if (((byte)(*(char *)((int)&ot[1].pos.vx + 1) + 0x20U) < 0x1a) &&
       (*(char *)&obj[4].matrices == '\x06')) {
      return 0;
    }
    if ((byte)(*(char *)((int)&ot[1].pos.vx + 1) + 6U) < 5) {
      if ((*(char *)&obj[4].matrices != '\x06') && (*(char *)&obj[4].matrices != '\v')) {
        return 1;
      }
      return 0;
    }
  }
  else {
    if ((obj->collision_mode & 0x200U) != 0) {
      if (*(char *)&ot[4].matrices == '\x06') {
        return 0;
      }
      CB_TakeObject((_PLAYER *)ot,obj);
      return 0;
    }
  }
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Pl_Collisioned(struct _D3_OBJECT *ot /*$s1*/, struct _D3_OBJECT *obj /*$s0*/, long bits /*$s2*/)
 // line 973, offset 0x80033508
	/* begin block 1 */
		// Start line: 975
		// Start offset: 0x80033528
		// Variables:
	// 		struct _PLAYER *pl; // $a1
	/* end block 1 */
	// End offset: 0x80033700
	// End Line: 1038

	/* begin block 2 */
		// Start line: 2514
	/* end block 2 */
	// End Line: 2515

long Pl_Collisioned(_D3_OBJECT *ot,_D3_OBJECT *obj,long bits)

{
  ushort uVar1;
  long lVar2;
  char cVar3;
  _D3_OBJECT *ot_00;
  
  while( true ) {
    ot_00 = ot;
    ot = obj;
    lVar2 = Pl_AcceptCollisioned(ot_00,ot,bits);
    if (lVar2 == 0) {
      return 0;
    }
    if ((ot_00->collision_mode & 0x1000U) == 0) break;
    if (((ot->collision_mode & 0x40U) != 0) && ((bits & 0x3c00U) != 0)) {
      uVar1 = ot_00->collision_state;
      *(_D3_OBJECT **)&ot_00[2].color = ot;
      ot_00->collision_state = uVar1 | 0x40;
    }
    if ((((*(char *)((int)&ot[1].pos.vx + 1) != '\r') || (1 < (uint)(ushort)ot[1].pos.vy - 9)) ||
        (obj = ot_00, (ot->collision_mode & 2U) == 0)) &&
       (obj = ot_00, (*(uint *)&ot[1].pos & 0xffffff00) != 0x120100)) {
      if ((ot->collision_mode & 2U) == 0) {
        return 1;
      }
      cVar3 = *(char *)((int)&ot[1].pos.vx + 1);
      obj = ot_00;
      if ((cVar3 != -9) && (obj = ot_00, cVar3 != -0x10)) {
        return 1;
      }
    }
  }
  cVar3 = *(char *)((int)&ot_00[1].pos.vx + 1);
  if ((cVar3 == -9) || (cVar3 == -0x10)) {
    if (*(char *)&ot[4].matrices == '\v') {
      return 1;
    }
    cVar3 = *(char *)((int)&ot_00[1].pos.vx + 1);
  }
  if ((cVar3 == '\r') && ((uint)(ushort)ot_00[1].pos.vy - 9 < 2)) {
    (ot->pos).vx = (ot->pos).vx + ((ot_00->pos).vx - (ot_00->last_pos).vx);
    (ot->pos).vy = (ot->pos).vy + ((ot_00->pos).vy - (ot_00->last_pos).vy);
    (ot->pos).vz = (ot->pos).vz + ((ot_00->pos).vz - (ot_00->last_pos).vz);
  }
  if ((ot_00->collision_mode & 2U) == 0) {
    return 1;
  }
  if ((*(ushort *)&ot[2].matrices & 4) != 0) {
    return 1;
  }
  if ((ot[2].b_box.pad & 0x20U) == 0) {
    uVar1 = ot->collision_state;
    *(_D3_OBJECT **)&ot[1].description = ot_00;
    ot->collision_state = uVar1 | 2;
    return 1;
  }
  return 1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pl_TurnBackRot(struct _PLAYER *pl /*$s2*/, long dx /*$a1*/, long dy /*$a2*/)
 // line 1041, offset 0x80033718
	/* begin block 1 */
		// Start line: 1042
		// Start offset: 0x80033718
		// Variables:
	// 		long px; // $s1
	// 		long py; // $s0
	// 		long ix; // $s6
	// 		long iy; // $s5
	// 		long rz; // $s3
	// 		long iz; // $s4
	/* end block 1 */
	// End offset: 0x800338AC
	// End Line: 1067

	/* begin block 2 */
		// Start line: 2651
	/* end block 2 */
	// End Line: 2652

/* WARNING: Removing unreachable block (ram,0x80033840) */
/* WARNING: Type propagation algorithm not settling */

void Pl_TurnBackRot(_PLAYER *pl,long dx,long dy)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  iVar3 = *(int *)(*(int *)((pl->m_obj).Env.Obj.primitive_top.Data + 0xc) +
                   (int)*(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x16) * 4 + 8);
  uVar4 = (uint)*(ushort *)(iVar3 + 6);
  uVar1 = *(ushort *)(iVar3 + 8);
  iVar3 = (int)(uVar4 << 4) / (int)(uint)uVar1;
  if (uVar1 == 0) {
    trap(0x1c00);
  }
  if (((uint)uVar1 == 0xffffffff) && (uVar4 == 0x8000000)) {
    trap(0x1800);
  }
  if (iVar3 == 0) {
    trap(0x1c00);
  }
  if ((iVar3 == -1) && (dx << 0x10 == -0x80000000)) {
    trap(0x1800);
  }
  if (iVar3 == 0) {
    trap(0x1c00);
  }
  if ((iVar3 == -1) && (dy << 0x10 == -0x80000000)) {
    trap(0x1800);
  }
  uVar4 = (int)(pl->obj).pos.vy << 0x10;
  uVar5 = (int)(pl->obj).pos.vx << 0x10;
  *(ushort *)&(pl->m_obj).shadow.u0 = *(ushort *)&(pl->m_obj).shadow.u0 | 8;
  uVar1 = *(ushort *)&(pl->m_obj).Env.Obj.n_primitive;
  if (iVar3 == 0) {
    trap(0x1c00);
  }
  iVar6 = 0;
  while ((uVar1 & 0x4000) == 0) {
    iVar6 = iVar6 + 0x8000000 / iVar3;
    uVar5 = uVar5 + (dx << 0x10) / iVar3;
    uVar4 = uVar4 + (dy << 0x10) / iVar3;
    (pl->obj).pos.vx = (short)(uVar5 >> 0x10);
    (pl->obj).pos.vy = (short)(uVar4 >> 0x10);
    *(short *)&(pl->m_obj).shadow.u1 = (short)((uint)iVar6 >> 0x10);
    Task_Next();
    uVar5 = (int)(pl->obj).pos.vx << 0x10 | uVar5 & 0xffff;
    uVar1 = *(ushort *)&(pl->m_obj).Env.Obj.n_primitive;
    uVar4 = (int)(pl->obj).pos.vy << 0x10 | uVar4 & 0xffff;
  }
  sVar2 = (pl->obj).rot.vz;
  *(ushort *)&(pl->m_obj).shadow.u0 = *(ushort *)&(pl->m_obj).shadow.u0 & 0xfff7;
  (pl->obj).rot.vz = sVar2 + 0x800U & 0xfff;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pl_AdjustUse(struct _PLAYER *pl /*$s2*/, struct PLAYER_7fake *pos /*$s0*/, long rotz /*stack 8*/, long frot /*$s7*/)
 // line 1072, offset 0x800338f0
	/* begin block 1 */
		// Start line: 1073
		// Start offset: 0x800338F0
		// Variables:
	// 		long dx; // $s6
	// 		long dy; // $s5
	// 		long drz; // $fp
	// 		long x; // $s0
	// 		long y; // $s3
	// 		long rz; // $s4
	/* end block 1 */
	// End offset: 0x80033A98
	// End Line: 1117

	/* begin block 2 */
		// Start line: 2720
	/* end block 2 */
	// End Line: 2721

/* WARNING: Type propagation algorithm not settling */

void Pl_AdjustUse(_PLAYER *pl,undefined pos,long rotz,long frot)

{
  long lVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined3 in_register_00000015;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint unaff_s4;
  int unaff_s8;
  
  lVar1 = Manim_GetEventTime((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data,-0x8000);
  iVar4 = (int)(pl->obj).pos.vx;
  iVar6 = (int)(short)lVar1;
  iVar2 = ((int)*(short *)CONCAT31(in_register_00000015,pos) - iVar4) * 0x10000;
  if (iVar6 == 0) {
    trap(0x1c00);
  }
  if ((iVar6 == -1) && (iVar2 == -0x80000000)) {
    trap(0x1800);
  }
  iVar3 = (int)(pl->obj).pos.vy;
  uVar5 = iVar4 << 0x10;
  iVar4 = ((int)((short *)CONCAT31(in_register_00000015,pos))[1] - iVar3) * 0x10000;
  if (iVar6 == 0) {
    trap(0x1c00);
  }
  if ((iVar6 == -1) && (iVar4 == -0x80000000)) {
    trap(0x1800);
  }
  uVar7 = iVar3 << 0x10;
  if (frot != 0) {
    lVar1 = DeltaDirection(rotz,(int)(pl->obj).rot.vz);
    unaff_s8 = (lVar1 << 0x10) / iVar6;
    if (iVar6 == 0) {
      trap(0x1c00);
    }
    if ((iVar6 == -1) && (lVar1 << 0x10 == -0x80000000)) {
      trap(0x1800);
    }
    unaff_s4 = (int)(pl->obj).rot.vz << 0x10;
  }
  while ((((int)*(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x22) & 0x8000U) == 0 &&
         (uVar5 = uVar5 + iVar2 / iVar6, (*(ushort *)&(pl->m_obj).Env.Obj.n_primitive & 0x4000) == 0
         ))) {
    uVar7 = uVar7 + iVar4 / iVar6;
    (pl->obj).pos.vx = (short)(uVar5 >> 0x10);
    (pl->obj).pos.vy = (short)(uVar7 >> 0x10);
    if (frot != 0) {
      unaff_s4 = unaff_s4 + unaff_s8;
      (pl->obj).rot.vz = (short)(unaff_s4 >> 0x10);
    }
    Task_Next();
    uVar5 = (int)(pl->obj).pos.vx << 0x10 | uVar5 & 0xffff;
    uVar7 = (int)(pl->obj).pos.vy << 0x10 | uVar7 & 0xffff;
    if (frot != 0) {
      unaff_s4 = (int)(pl->obj).rot.vz << 0x10 | unaff_s4 & 0xffff;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pl_AdjustPosZ(struct _PLAYER *pl /*$s2*/)
 // line 1126, offset 0x80033ac8
	/* begin block 1 */
		// Start line: 1127
		// Start offset: 0x80033AC8
		// Variables:
	// 		long i; // $s0

		/* begin block 1.1 */
			// Start line: 1175
			// Start offset: 0x80033C00
			// Variables:
		// 		struct _ZONE *z; // $s3
		// 		struct _D3_OBJECT *os; // $s1
		/* end block 1.1 */
		// End offset: 0x80033C78
		// End Line: 1189
	/* end block 1 */
	// End offset: 0x80033D20
	// End Line: 1204

	/* begin block 2 */
		// Start line: 2849
	/* end block 2 */
	// End Line: 2850

void Pl_AdjustPosZ(_PLAYER *pl)

{
  bool bVar1;
  long lVar2;
  short sVar3;
  int iVar4;
  _D3_OBJECT *ot;
  int iVar5;
  
  iVar4 = *(int *)&(pl->m_obj).Ani.Anim.Trans;
  if (iVar4 != 0) {
    bVar1 = (*(ushort *)(iVar4 + 0x1e) & 4) != 0;
    if ((((pl->obj).collision_state & 0x4000U) != 0) &&
       ((*(uint *)(iVar4 + 0x98) & 0xffffff00) != 0xf00)) {
      bVar1 = true;
    }
    if (bVar1) {
      Pl_ForceAction(pl,9,0);
    }
    else {
      D3_MoveWithObject((_D3_OBJECT *)pl,*(_D3_OBJECT **)&(pl->m_obj).Ani.Anim.Trans);
    }
  }
  if ((*(ushort *)&(pl->m_obj).shadow.u0 & 1) != 0) {
    return;
  }
  if ((((pl->obj).collision_state & 0x4000U) == 0) &&
     (lVar2 = Boxes_TestGround((_D3_OBJECT *)pl), lVar2 == 0)) {
    lVar2 = Pl_TestHeight(pl,0);
    iVar4 = (int)(pl->obj).pos.vz;
    if ((iVar4 < lVar2) || (lVar2 <= iVar4 + -0x6e)) {
      Pl_ForceAction(pl,9,0);
      return;
    }
    (pl->obj).pos.vz = (pl->obj).pos.vz + -0x14;
  }
  else {
    D3_MoveWithObject((_D3_OBJECT *)pl,*(_D3_OBJECT **)&(pl->m_obj).Env.Obj.vert_top.vz);
    sVar3 = *(short *)((int)&(pl->m_obj).Env.Obj.n_normal + 2);
    if (sVar3 == 0x4a) {
      if (((pl->m_obj).shadow.y1 != 8) && (((pl->obj).collision_state & 0x4000U) != 0)) {
        iVar5 = *(int *)&(pl->m_obj).Env.Obj.primitive_top;
        ot = *(_D3_OBJECT **)&(pl->m_obj).Env.Obj.vert_top.vz;
        iVar4 = 0;
        if (0 < *(short *)(iVar5 + 0x28)) {
          do {
            if ((ot == *(_D3_OBJECT **)(iVar4 * 4 + *(int *)(iVar5 + 0x2c))) &&
               (lVar2 = Boxes_GetExtendedMaxZ(ot), lVar2 != 0)) {
              Pl_ForceAction(pl,8,(long)ot);
            }
            iVar4 = iVar4 + 1;
          } while (iVar4 < (int)*(short *)(iVar5 + 0x28));
        }
      }
      sVar3 = *(short *)((int)&(pl->m_obj).Env.Obj.n_normal + 2);
    }
    if (sVar3 == 0x4c) {
      (pl->obj).pos.vx = (pl->obj).pos.vx + 10;
    }
    else {
      if (sVar3 < 0x4d) {
        if (sVar3 == 0x4b) {
          (pl->obj).pos.vx = (pl->obj).pos.vx + -10;
        }
      }
      else {
        if (sVar3 == 0x4d) {
          sVar3 = (pl->obj).pos.vy + -10;
        }
        else {
          if (sVar3 != 0x4e) goto LAB_80033d04;
          sVar3 = (pl->obj).pos.vy + 10;
        }
        (pl->obj).pos.vy = sVar3;
      }
    }
  }
LAB_80033d04:
  lVar2 = Pafd_AdjustZ();
  if (lVar2 != 0) {
    (pl->obj).last_pos.vz = (pl->obj).pos.vz;
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Pl_TestHeight(struct _PLAYER *pl /*$s2*/, long dist /*$s1*/)
 // line 1207, offset 0x80033d3c
	/* begin block 1 */
		// Start line: 1208
		// Start offset: 0x80033D3C
		// Variables:
	// 		struct PLAYER_7fake pos; // stack offset -32
	/* end block 1 */
	// End offset: 0x80033DC8
	// End Line: 1223

	/* begin block 2 */
		// Start line: 3020
	/* end block 2 */
	// End Line: 3021

long Pl_TestHeight(_PLAYER *pl,long dist)

{
  long lVar1;
  uint uVar2;
  
  if (dist != 0) {
    uVar2 = SEXT24((pl->obj).rot.vz);
    rcos(uVar2);
    rsin(uVar2);
  }
  lVar1 = Boxes_GetHeight((_D3_OBJECT *)pl,0xe0,0x1c2);
  return lVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pl_ReduceHitPoints(struct _PLAYER *pl /*$s0*/, short hits /*$a1*/)
 // line 1227, offset 0x80033df4
	/* begin block 1 */
		// Start line: 1228
		// Start offset: 0x80033DF4
		// Variables:
	// 		long coeff; // $a0
	/* end block 1 */
	// End offset: 0x80033F18
	// End Line: 1258

	/* begin block 2 */
		// Start line: 3061
	/* end block 2 */
	// End Line: 3062

void Pl_ReduceHitPoints(_PLAYER *pl,short hits)

{
  uint uVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  
  uVar1 = ((uint)(*(ushort *)((pl->env2).Obj.primitive_top.Data + 0x10) >> 8) - 0x1e) * 5;
  iVar4 = 0x100 - ((int)(uVar1 + (uVar1 >> 0x1f)) >> 1);
  if (Pvl_Difficulty == 0) {
    iVar4 = iVar4 / 3;
  }
  else {
    if (Pvl_Difficulty != 1) goto LAB_80033e88;
  }
  iVar4 = (iVar4 << 1) / 3;
LAB_80033e88:
  sVar3 = 1;
  if (0 < iVar4 * (int)hits >> 8) {
    sVar3 = (short)((uint)(iVar4 * (int)hits) >> 8);
  }
  sVar2 = (pl->obj).hit_points - sVar3;
  if ((int)(pl->obj).hit_points - (int)sVar3 < 0) {
    sVar2 = 0;
  }
  (pl->obj).hit_points = sVar2;
  if (((sVar2 != 0) && (sVar2 < 0x15)) && (sVar3 = Invent_GetNbObjects(0,0), sVar3 != 0)) {
    Fx_Play(0x3b,(char)pl + ',');
    Invent_RemoveUsedObject(0,0,0);
    (pl->obj).hit_points = (pl->obj).hit_points + 0x19;
  }
  Task_EventExec(Overlay_Handle,Overlay_Handle->event_msg | 4,Overlay_Handle->event_param);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pl_AddExperience(struct _PLAYER *pl /*$s1*/, struct _D3_OBJECT *ot /*$s0*/)
 // line 1262, offset 0x80033f44
	/* begin block 1 */
		// Start line: 3134
	/* end block 1 */
	// End Line: 3135

void Pl_AddExperience(_PLAYER *pl,_D3_OBJECT *ot)

{
  ushort uVar1;
  short sVar2;
  long lVar3;
  
  if (((ot->exp != '\0') && (((pl->obj).collision_mode & 0x1000U) != 0)) &&
     (lVar3 = Pvl_TestStateBits(ot,0x20), lVar3 == 0)) {
    uVar1 = *(ushort *)((pl->env2).Obj.primitive_top.Data + 0xc);
    if ((uint)uVar1 + (uint)ot->exp * 0x100 < 0x10000) {
      sVar2 = uVar1 + (ushort)ot->exp * 0x100;
    }
    else {
      sVar2 = -1;
    }
    *(short *)((pl->env2).Obj.primitive_top.Data + 0xc) = sVar2;
    Pvl_SetStateBits(ot,0x20);
    if (*(short *)((pl->env2).Obj.primitive_top.Data + 0xc) == -1) {
      Stats_AtTheMax();
    }
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Pl_GetFlying(struct _PLAYER *pl /*$a0*/)
 // line 1276, offset 0x80033ffc
	/* begin block 1 */
		// Start line: 3163
	/* end block 1 */
	// End Line: 3164

long Pl_GetFlying(_PLAYER *pl)

{
  uint uVar1;
  
  uVar1 = 0;
  if ((*(ushort *)&(pl->m_obj).shadow.u0 & 1) != 0) {
    uVar1 = (uint)(*(int *)&(pl->m_obj).Ani.Anim.Trans == 0);
  }
  return uVar1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Pl_IsWeaponAvailable(struct _PLAYER *pl /*$a0*/, long weapon /*$a1*/)
 // line 1282, offset 0x80034024
	/* begin block 1 */
		// Start line: 1284
		// Start offset: 0x80034024
	/* end block 1 */
	// End offset: 0x80034044
	// End Line: 1298

	/* begin block 2 */
		// Start line: 3178
	/* end block 2 */
	// End Line: 3179

/* WARNING: Type propagation algorithm not settling */

long Pl_IsWeaponAvailable(_PLAYER *pl,long weapon)

{
  if (*(int *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x10) != 0) {
    return 0;
  }
  return (uint)(0 < *(short *)((pl->env1).Obj.primitive_top.Data + weapon * 8 + 0x1a));
}



// decompiled code
// original method signature: 
// long /*$ra*/ Pl_GetSpellCost(struct _PLAYER *pl /*$s0*/, long spell /*$a1*/)
 // line 1301, offset 0x8003404c
	/* begin block 1 */
		// Start line: 1302
		// Start offset: 0x8003404C
		// Variables:
	// 		long coeff; // $s2
	// 		long cost; // $s1
	/* end block 1 */
	// End offset: 0x8003417C
	// End Line: 1339

	/* begin block 2 */
		// Start line: 3212
	/* end block 2 */
	// End Line: 3213

/* WARNING: Type propagation algorithm not settling */

long Pl_GetSpellCost(_PLAYER *pl,long spell)

{
  long lVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = (int)(&PSpells)[spell].cost;
  iVar4 = ((uint)(*(ushort *)((pl->env2).Obj.primitive_top.Data + 0x14) >> 8) - 0x1e) * -2 + 0x100;
  if (iVar3 < 1) {
    if (spell == 8) {
      lVar2 = Pl_GetSpellLevel(pl,8,(long *)0x0);
      lVar1 = PSpell_TestSelection(pl,8);
      iVar3 = (lVar2 + lVar1) * -2 - iVar3;
    }
    else {
      if (spell < 9) {
        iVar5 = iVar3 * iVar4;
        if (spell == 1) {
          if ((pl->obj).hit_points < 0xb) {
            return 0x7fff;
          }
          return 0;
        }
        goto LAB_80034168;
      }
      iVar5 = iVar3 * iVar4;
      if (spell != 0xb) goto LAB_80034168;
      lVar2 = Pl_GetSpellLevel(pl,0xb,(long *)0x0);
      lVar1 = PSpell_TestSelection(pl,0xb);
      iVar5 = -iVar3 * iVar4;
      if (lVar2 + lVar1 < 2) goto LAB_80034168;
      iVar3 = (int)(iVar3 * -3 + ((uint)(iVar3 * -3) >> 0x1f)) >> 1;
    }
  }
  iVar5 = iVar3 * iVar4;
LAB_80034168:
  lVar2 = iVar5 >> 8;
  if (lVar2 < 1) {
    lVar2 = 1;
  }
  return lVar2;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Pl_GetSpellLevel(struct _PLAYER *pl /*$a0*/, long spell /*$a1*/, long *spell_levels /*$a2*/)
 // line 1342, offset 0x80034194
	/* begin block 1 */
		// Start line: 1344
		// Start offset: 0x80034194
		// Variables:
	// 		long *plevel; // $a2
	// 		long level; // $v0
	/* end block 1 */
	// End offset: 0x800341E4
	// End Line: 1365

	/* begin block 2 */
		// Start line: 3308
	/* end block 2 */
	// End Line: 3309

long Pl_GetSpellLevel(_PLAYER *pl,long spell,long *spell_levels)

{
  if ((spell_levels == (long *)0x0) && ((1 << (spell & 0x1fU) & (pl->env2).Obj.n_vert) == 0)) {
    return -1;
  }
  if (spell_levels == (long *)0x0) {
    spell_levels = (long *)&(pl->env2).Obj.normal_top;
  }
  if (0xf < spell) {
    spell = spell + -0x10;
    spell_levels = (long *)&((_struct_382 *)spell_levels)->vz;
  }
  return (*spell_levels & 3 << (spell << 1 & 0x1fU)) >> (spell << 1 & 0x1fU) & 3;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pl_SetSpellLevel(struct _PLAYER *pl /*$a0*/, long spell /*$a1*/, long level /*$a2*/, long *spell_levels /*$a3*/)
 // line 1368, offset 0x800341f4
	/* begin block 1 */
		// Start line: 1370
		// Start offset: 0x800341F4
		// Variables:
	// 		long *plevel; // $a3
	/* end block 1 */
	// End offset: 0x80034230
	// End Line: 1382

	/* begin block 2 */
		// Start line: 3360
	/* end block 2 */
	// End Line: 3361

void Pl_SetSpellLevel(_PLAYER *pl,long spell,long level,long *spell_levels)

{
  (pl->env2).Obj.n_vert = (pl->env2).Obj.n_vert | 1 << (spell & 0x1fU);
  if (3 < level) {
    level = 3;
  }
  if (spell_levels == (long *)0x0) {
    spell_levels = (long *)&(pl->env2).Obj.normal_top;
  }
  if (0xf < spell) {
    spell = spell + -0x10;
    spell_levels = (long *)&((_struct_382 *)spell_levels)->vz;
  }
  *spell_levels = *spell_levels & ~(3 << (spell << 1 & 0x1fU)) | level << (spell << 1 & 0x1fU);
  return;
}





