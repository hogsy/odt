#include "THISDUST.H"
#include "PVL.H"


// decompiled code
// original method signature: 
// void /*$ra*/ Pvl_Init()
 // line 254, offset 0x80029d20
	/* begin block 1 */
		// Start line: 509
	/* end block 1 */
	// End Line: 510

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pvl_Init(void)

{
  return;
}



// decompiled code
// original method signature: 
// char * /*$ra*/ Pvl_GetAllName()
 // line 259, offset 0x80029d28
	/* begin block 1 */
		// Start line: 260
		// Start offset: 0x80029D28
	/* end block 1 */
	// End offset: 0x80029D28
	// End Line: 260

	/* begin block 2 */
		// Start line: 518
	/* end block 2 */
	// End Line: 519

/* WARNING: Unknown calling convention yet parameter storage is locked */

char * Pvl_GetAllName(void)

{
  sprintf(Pvl_Names,s_Level_02d_Sector_02d_all_800ad308,(int)Pvl_LevelNumber,(int)Pvl_SectorNumber);
  return Pvl_Names;
}



// decompiled code
// original method signature: 
// char * /*$ra*/ Pvl_GetLnkName()
 // line 270, offset 0x80029d60
	/* begin block 1 */
		// Start line: 271
		// Start offset: 0x80029D60
	/* end block 1 */
	// End offset: 0x80029D60
	// End Line: 271

	/* begin block 2 */
		// Start line: 545
	/* end block 2 */
	// End Line: 546

/* WARNING: Unknown calling convention yet parameter storage is locked */

char * Pvl_GetLnkName(void)

{
  sprintf(Pvl_Names,s_Level_02d_Sector_02d_lnk_800ad324,(int)Pvl_LevelNumber,(int)Pvl_SectorNumber);
  return Pvl_Names;
}



// decompiled code
// original method signature: 
// char * /*$ra*/ Pvl_GetPclName()
 // line 281, offset 0x80029d98
	/* begin block 1 */
		// Start line: 282
		// Start offset: 0x80029D98
	/* end block 1 */
	// End offset: 0x80029D98
	// End Line: 282

	/* begin block 2 */
		// Start line: 570
	/* end block 2 */
	// End Line: 571

/* WARNING: Unknown calling convention yet parameter storage is locked */

char * Pvl_GetPclName(void)

{
  sprintf(Pvl_Names,s_Level_02d_Sector_02d_pcl_800ad340,(int)Pvl_LevelNumber,(int)Pvl_SectorNumber);
  return Pvl_Names;
}



// decompiled code
// original method signature: 
// char * /*$ra*/ Pvl_GetSndName()
 // line 294, offset 0x80029dd0
	/* begin block 1 */
		// Start line: 295
		// Start offset: 0x80029DD0
	/* end block 1 */
	// End offset: 0x80029DD0
	// End Line: 295

	/* begin block 2 */
		// Start line: 601
	/* end block 2 */
	// End Line: 602

/* WARNING: Unknown calling convention yet parameter storage is locked */

char * Pvl_GetSndName(void)

{
  sprintf(Pvl_Names,s_Level_02d_Snds_Sector_02d_snd_800ad35c,(int)Pvl_LevelNumber,
          (int)Pvl_SectorNumber);
  return Pvl_Names;
}



// decompiled code
// original method signature: 
// char * /*$ra*/ Pvl_GetTxtName()
 // line 305, offset 0x80029e08
	/* begin block 1 */
		// Start line: 306
		// Start offset: 0x80029E08
	/* end block 1 */
	// End offset: 0x80029E08
	// End Line: 306

	/* begin block 2 */
		// Start line: 628
	/* end block 2 */
	// End Line: 629

/* WARNING: Unknown calling convention yet parameter storage is locked */

char * Pvl_GetTxtName(void)

{
  sprintf(Pvl_Names,s_Level_02d_Level_txt_800ad37c,(int)Pvl_LevelNumber);
  return Pvl_Names;
}



// decompiled code
// original method signature: 
// char * /*$ra*/ Pvl_GetLocName()
 // line 316, offset 0x80029e3c
	/* begin block 1 */
		// Start line: 317
		// Start offset: 0x80029E3C
	/* end block 1 */
	// End offset: 0x80029E3C
	// End Line: 317

	/* begin block 2 */
		// Start line: 653
	/* end block 2 */
	// End Line: 654

/* WARNING: Unknown calling convention yet parameter storage is locked */

char * Pvl_GetLocName(void)

{
  sprintf(Pvl_Names,s_Level_02d_local_lnk_800ad390,(int)Pvl_LevelNumber);
  return Pvl_Names;
}



// decompiled code
// original method signature: 
// char * /*$ra*/ Pvl_GetBossName()
 // line 332, offset 0x80029e70
	/* begin block 1 */
		// Start line: 333
		// Start offset: 0x80029E70
	/* end block 1 */
	// End offset: 0x80029E70
	// End Line: 333

	/* begin block 2 */
		// Start line: 688
	/* end block 2 */
	// End Line: 689

/* WARNING: Unknown calling convention yet parameter storage is locked */

char * Pvl_GetBossName(void)

{
  sprintf(Pvl_Names,s_boss_02d_bin_800ad3a4,(int)Pvl_LevelNumber);
  return Pvl_Names;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pvl_GetXA()
 // line 344, offset 0x80029ea4
	/* begin block 1 */
		// Start line: 345
		// Start offset: 0x80029EA4
	/* end block 1 */
	// End offset: 0x80029EA4
	// End Line: 345

	/* begin block 2 */
		// Start line: 715
	/* end block 2 */
	// End Line: 716

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pvl_GetXA(void)

{
  sprintf(Sound_TrackNames,s__ODT_LEVEL02_XA_1_800ad3b4);
  Sound_PlayCd(0,0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pvl_StopXA()
 // line 367, offset 0x80029edc
	/* begin block 1 */
		// Start line: 764
	/* end block 1 */
	// End Line: 765

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pvl_StopXA(void)

{
  Sound_StopCd();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pvl_PlayMovie(long movie /*$a2*/)
 // line 375, offset 0x80029efc
	/* begin block 1 */
		// Start line: 376
		// Start offset: 0x80029EFC
	/* end block 1 */
	// End offset: 0x80029EFC
	// End Line: 376

	/* begin block 2 */
		// Start line: 780
	/* end block 2 */
	// End Line: 781

void Pvl_PlayMovie(long movie)

{
  File_Exec(s_Movies_exe_800ad3c8,(long)&DAT_801ff800,movie,
            CONCAT22(Screens.disp.screen.x,Screens.disp.screen.y));
  Scr_Clear();
  Scr_Swap();
  Scr_Clear();
  Scr_Swap();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pvl_InitGame()
 // line 425, offset 0x80029f64
	/* begin block 1 */
		// Start line: 426
		// Start offset: 0x80029F64
		// Variables:
	// 		struct PVL_70fake shp; // stack offset -80
	// 		char text[40]; // stack offset -64
	// 		long i; // $s1
	// 		short w; // stack offset -24
	// 		short h; // stack offset -22
	/* end block 1 */
	// End offset: 0x8002A27C
	// End Line: 528

	/* begin block 2 */
		// Start line: 885
	/* end block 2 */
	// End Line: 886

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pvl_InitGame(void)

{
  short sVar1;
  short sVar2;
  long lVar3;
  TMD_72fake *Tmd;
  void *T;
  SHAPE_31fake *prim;
  PVL_45fake *pPVar4;
  int Index;
  int iVar5;
  SHAPE_68fake local_50;
  char acStack64 [40];
  ushort local_18;
  ushort local_16 [3];
  
  Scr_InitZone(0,0,0x140,0x1e0,0);
  TPage_InitZone(0x140,0,0x2c0,0x200);
  sprintf(acStack64,s_Legal_level_d_tim_800ad3d4,(int)Pvl_LevelNumber);
  Overlay_DisplayPicture(acStack64,0x140,3);
  Screens.disp.screen.x =
       (short)((int)(((int)((uint)(ushort)Pvl_ScrX << 0x10) >> 0x10) +
                    (((uint)(ushort)Pvl_ScrX << 0x10) >> 0x1f)) >> 1);
  Screens.disp.screen.y = Pvl_ScrY;
  _SCREEN_800b993c.disp.screen.y = Pvl_ScrY;
  _SCREEN_800b993c.disp.screen.x = Screens.disp.screen.x;
  SetDispMask(1);
  TPage_AllocAt(4,0);
  TPage_AllocAt(4,0xb);
  lVar3 = TPage_Alloc(4);
  Pal_InitZone((&TPages)[lVar3].x,(&TPages)[lVar3].y,0x100,0x100);
  Pvl_Prims2 = Heap_AllocMem((ulong)&DAT_00017318);
  PTR_800b031c = Heap_AllocMem((ulong)&DAT_00017318);
  SetGeomOffset((int)(((int)((uint)(ushort)Scr_W << 0x10) >> 0x10) +
                     (((uint)(ushort)Scr_W << 0x10) >> 0x1f)) >> 1,
                (int)(((int)((uint)(ushort)Scr_H << 0x10) >> 0x10) +
                     (((uint)(ushort)Scr_H << 0x10) >> 0x1f)) >> 1);
  Scr_GeomScreen = 0x100;
  Scr_SetSync(2);
  SFX_Init();
  Track_Init();
  if (Pvl_LoadedGame == 0) {
    Pvl_GameTime = 0;
    Pvl_Prisoner_Status = 0;
    Pvl_CheckPtSector = 0;
  }
  Pvl_ResetWanted = 0;
  Index = 0;
  Pl_InitPlayer(Pvl_PlayerNumber);
  Invent_InitTakenObjects();
  Overlay_Init();
  Pvl_LnkGlobals = FileGroup_GetAddr(Effects_Tmd,0);
  if (0 < *(int *)Pvl_LnkGlobals) {
    do {
      Tmd = (TMD_72fake *)FileGroup_GetAddr(Pvl_LnkGlobals,Index);
      Tmd_InitFile(Tmd);
      T = FileGroup_GetAddr(Pvl_LnkGlobals,Index);
      Shp_TmdToVram(Effects_Pcl,T,0,0);
      Index = Index + 1;
    } while (Index < *(int *)Pvl_LnkGlobals);
  }
  TPage_Free(0);
  TPage_Free(0xb);
  Index = 0;
  pPVar4 = Pvl_BlackScreen;
  iVar5 = 0;
  local_50.shape = 0xfd;
  local_50.file = Effects_Pcl;
  Shp_GetWH(&local_50,(short *)&local_18,(short *)local_16);
  local_50.y = 0x10;
  local_50.x = (Scr_W - local_18) + -0x10;
  do {
    prim = (SHAPE_31fake *)(&Pvl_DemoPrims + iVar5);
    iVar5 = iVar5 + 0x28;
    Index = Index + 1;
    Shp_SetPolyFT4(prim,&local_50,(short)(((uint)local_18 + 1) * 0x10000 >> 0x10),
                   (short)(((uint)local_16[0] + 1) * 0x10000 >> 0x10));
    pPVar4->r0 = '\0';
    pPVar4->g0 = '\0';
    pPVar4->b0 = '\0';
    sVar2 = Scr_W;
    sVar1 = Scr_H;
    *(undefined *)((int)&pPVar4->tag + 3) = 3;
    pPVar4->code = '`';
    pPVar4->x0 = 0;
    pPVar4->y0 = 0;
    pPVar4->w = sVar2;
    pPVar4->h = sVar1;
    pPVar4 = pPVar4 + 1;
  } while (Index < 2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pvl_AbortGame()
 // line 531, offset 0x8002a294
	/* begin block 1 */
		// Start line: 1147
	/* end block 1 */
	// End Line: 1148

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pvl_AbortGame(void)

{
  _DAT_800b1c56 = _DAT_800b1c56 | 8;
  _DAT_800b1d50 = 0;
  _DAT_800b1e30 = 0xffff;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pvl_DeleteGame()
 // line 542, offset 0x8002a2c0
	/* begin block 1 */
		// Start line: 1172
	/* end block 1 */
	// End Line: 1173

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pvl_DeleteGame(void)

{
  Heap_FreeMem(Pvl_Prims2);
  Heap_FreeMem(PTR_800b031c);
  Overlay_Delete();
  Track_Delete();
  SFX_Delete();
  Pl_DeleteWholePlayer();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pvl_PlayGame()
 // line 558, offset 0x8002a310
	/* begin block 1 */
		// Start line: 1204
	/* end block 1 */
	// End Line: 1205

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pvl_PlayGame(void)

{
  InGame_Init();
  Manim_Init();
  Pvl_Init();
  Plat_Init();
  Object_Init();
  Pl_Init();
  Pvl_GameHandle = Task_Add(Pvl_GameTask,0x900);
  Task_Start();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pvl_GameTask()
 // line 575, offset 0x8002a374
	/* begin block 1 */
		// Start line: 576
		// Start offset: 0x8002A374
		// Variables:
	// 		struct PVL_104fake t; // stack offset -96
	// 		long game_over; // $s0
	// 		long level_over; // $s1
	// 		long current_level; // $s3
	// 		long entry; // $s2

		/* begin block 1.1 */
			// Start line: 616
			// Start offset: 0x8002A3EC
			// Variables:
		// 		static int Demo_Sequence; // offset 0x800ad3e8
		/* end block 1.1 */
		// End offset: 0x8002A408
		// End Line: 619

		/* begin block 1.2 */
			// Start line: 699
			// Start offset: 0x8002A514
			// Variables:
		// 		char text[40]; // stack offset -64
		/* end block 1.2 */
		// End offset: 0x8002A514
		// End Line: 701
	/* end block 1 */
	// End offset: 0x8002A580
	// End Line: 735

	/* begin block 2 */
		// Start line: 1238
	/* end block 2 */
	// End Line: 1239

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pvl_GameTask(void)

{
  bool bVar1;
  short sVar2;
  int iVar3;
  long entry;
  undefined auStack96 [32];
  char acStack64 [40];
  
  Text_SetContext((TEXT_102fake *)auStack96);
  Text_SetContextFont(0x70);
  Text_SetContextXY(0,0);
  Text_SetContextWH(Scr_W,Scr_H);
  Text_SetContextRange(0);
  Text_SetContextMode(0);
  do {
    if (Pvl_Demo != 0) {
      Demo_PlayInit(DAT_800ad3e8 & 7);
      DAT_800ad3e8 = DAT_800ad3e8 + 1;
    }
    entry = Pvl_LoadedGame;
    if ((Pvl_LoadedGame == 0) && (entry = 0, Pvl_SectorNumber == 1)) {
      entry = 0x4c564c53;
    }
    iVar3 = 0;
    Pvl_InitGame();
    bVar1 = true;
    do {
      Pvl_InitLevel();
      sVar2 = Pvl_LevelNumber;
      do {
        if (!bVar1) {
          Stats_LoadingStart();
          Task_Sleep(5);
        }
        entry = Pvl_PlaySector(Pvl_SectorNumber,entry);
        if (Pvl_Demo == 0) {
          if (entry == 0x45564f47) {
LAB_8002a4bc:
            iVar3 = 1;
          }
          else {
            if (entry == 0x47444e45) {
              iVar3 = 2;
            }
            else {
              if (_DAT_800b1e30 < 1) goto LAB_8002a4bc;
            }
          }
        }
        else {
          iVar3 = 3;
        }
        bVar1 = Pvl_LevelNumber != sVar2;
      } while (((iVar3 == 0) && (!bVar1)) && (Pvl_LoadedGame == 0));
      Pvl_DeleteLevel();
      if ((iVar3 != 0) || (Pvl_LoadedGame != 0)) break;
      sprintf(acStack64,s_Legal_level_d_tim_800ad3d4,(int)Pvl_LevelNumber);
      Overlay_DisplayPicture(acStack64,0x140,3);
    } while (Pvl_LoadedGame == 0);
    Pvl_DeleteGame();
    if (Pvl_LoadedGame == 0) {
      if (iVar3 == 2) {
        Overlay_DisplayPicture(s_Legal_Continue_tim_800ad3ec,0x280,(int)Scr_TicksPerSecond * 5);
      }
      return;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pvl_PauseGame()
 // line 738, offset 0x8002a5a0
	/* begin block 1 */
		// Start line: 1575
	/* end block 1 */
	// End Line: 1576

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pvl_PauseGame(void)

{
  Pvl_Pause = 1;
  Task_DisableList(Pvl_GameHandle->child);
  Task_EventExec(Overlay_Handle,Overlay_Handle->event_msg | 2,Overlay_Handle->event_param);
  Pl_Pause();
  Sound_Pause();
  if (LifeHandle != (TASK *)0x0) {
    Task_Kill(LifeHandle);
    LifeHandle = (TASK *)0x0;
  }
  if (Sound_CdHandle != (TASK *)0x0) {
    Sound_CdHandle->enable = 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pvl_UnpauseGame()
 // line 771, offset 0x8002a63c
	/* begin block 1 */
		// Start line: 1645
	/* end block 1 */
	// End Line: 1646

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pvl_UnpauseGame(void)

{
  if (Pvl_Pause != 0) {
    Pvl_Pause = 0;
    Task_EnableList(Pvl_GameHandle->child);
    Pl_Unpause();
    Sound_Continue();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pvl_GreyScreen()
 // line 791, offset 0x8002a684
	/* begin block 1 */
		// Start line: 794
		// Start offset: 0x8002A684
	/* end block 1 */
	// End offset: 0x8002A7B4
	// End Line: 825

	/* begin block 2 */
		// Start line: 1694
	/* end block 2 */
	// End Line: 1695

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pvl_GreyScreen(void)

{
  undefined *puVar1;
  void *pvVar2;
  _SCREEN *p_Var3;
  short sVar4;
  short sVar5;
  uint uVar6;
  
  pvVar2 = Main_Prims;
  if (Pvl_Demo == 0) {
    if ((void *)((int)Main_Prims + 0x18) <= Main_TextContext.Font.ascii_tab._20_4_) {
      puVar1 = (undefined *)((int)Main_Prims + 4);
      Main_Prims = (void *)((int)Main_Prims + 0x18);
      *puVar1 = 0;
      *(undefined *)((int)pvVar2 + 5) = 0;
      *(undefined *)((int)pvVar2 + 6) = 0;
      sVar5 = Scr_W;
      sVar4 = Scr_H;
      *(undefined *)((int)pvVar2 + 3) = 3;
      *(undefined *)((int)pvVar2 + 7) = 0x62;
      *(undefined2 *)((int)pvVar2 + 8) = 0;
      *(undefined2 *)((int)pvVar2 + 10) = 0;
      *(short *)((int)pvVar2 + 0xc) = sVar5;
      *(short *)((int)pvVar2 + 0xe) = sVar4;
      *(undefined *)((int)pvVar2 + 0x13) = 1;
      p_Var3 = Scr;
      uVar6 = 0xe1000000;
      if (Scr_Dtd != 0) {
        uVar6 = 0xe1000200;
      }
      if (Scr_Dfe != 0) {
        uVar6 = uVar6 | 0x400;
      }
      *(uint *)((int)pvVar2 + 0x14) = uVar6;
      *(uint *)pvVar2 = *(uint *)pvVar2 & 0xff000000 | p_Var3->ot[1] & 0xffffff;
      p_Var3->ot[1] = p_Var3->ot[1] & 0xff000000 | (uint)pvVar2 & 0xffffff;
      *(uint *)((int)pvVar2 + 0x10) =
           *(uint *)((int)pvVar2 + 0x10) & 0xff000000 | p_Var3->ot[1] & 0xffffff;
      p_Var3->ot[1] = p_Var3->ot[1] & 0xff000000 | (int)pvVar2 + 0x10U & 0xffffff;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pvl_InitLevel()
 // line 837, offset 0x8002a7bc
	/* begin block 1 */
		// Start line: 838
		// Start offset: 0x8002A7BC
		// Variables:
	// 		long i; // $v1
	// 		long n; // $a2
	// 		void *boss; // $s0
	/* end block 1 */
	// End offset: 0x8002A93C
	// End Line: 912

	/* begin block 2 */
		// Start line: 1803
	/* end block 2 */
	// End Line: 1804

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pvl_InitLevel(void)

{
  bool bVar1;
  char *name;
  undefined4 *ptt;
  int iVar2;
  long lVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  if (Pvl_LoadedGame == 0) {
    Pvl_ClearSctState();
    Pvl_nItems = 0;
    Pvl_nMonsters = 0;
    Pvl_nGaz = 0;
    Pvl_nSecrets = 0;
    Pvl_LevelTime = Pvl_GameTime;
  }
  Pvl_MaxItems = 0;
  Pvl_MaxMonsters = 0;
  Pvl_MaxGaz = 0;
  Pvl_MaxSecrets = 0;
  Pvl_BossState = 0;
  name = Pvl_GetLocName();
  Pvl_LnkLocals = File_Read(name,(void *)0x0);
  name = Pvl_GetTxtName();
  Pvl_Txt = File_Read(name,(void *)0x0);
  Pvl_InitTexts();
  if (Pvl_LevelNumber != 0) {
    name = Pvl_GetBossName();
    ptt = (undefined4 *)File_Read(name,(void *)0x0);
    iVar2 = Heap_GetSize(ptt);
    if (iVar2 < 0) {
      iVar2 = iVar2 + 3;
    }
    iVar4 = 0;
    puVar5 = ptt;
    puVar6 = (undefined4 *)Bosses_Start;
    if (0 < iVar2 >> 2) {
      do {
        iVar4 = iVar4 + 1;
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      } while (iVar4 < iVar2 >> 2);
    }
    Heap_FreeMem(ptt);
  }
  bVar1 = false;
  if (Pvl_SectorNumber == 1) {
    lVar3 = File_IsExist(s_Inter0u_stx_800ad400);
    bVar1 = false;
    if (lVar3 != 0) {
      Pvl_PlayMovie(0);
      bVar1 = true;
    }
  }
  Screens.disp.screen.x =
       (short)((int)(((int)((uint)(ushort)Pvl_ScrX << 0x10) >> 0x10) +
                    (((uint)(ushort)Pvl_ScrX << 0x10) >> 0x1f)) >> 1);
  Screens.disp.screen.y = Pvl_ScrY;
  _SCREEN_800b993c.disp.screen.y = Pvl_ScrY;
  _SCREEN_800b993c.disp.screen.x = Screens.disp.screen.x;
  if (bVar1) {
    _SCREEN_800b993c.disp.screen.x = Screens.disp.screen.x;
    Stats_LoadingStart();
    Task_Sleep(5);
  }
  Pl_InitLevel();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pvl_DeleteLevel()
 // line 916, offset 0x8002a954
	/* begin block 1 */
		// Start line: 1971
	/* end block 1 */
	// End Line: 1972

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pvl_DeleteLevel(void)

{
  if (Pvl_LoadedGame == 0) {
    Invent_ReleaseLocalObjects();
  }
  Heap_FreeMem(Pvl_LnkLocals);
  Pvl_DeleteTexts();
  Pl_DeleteLevel();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pvl_InitMonsters()
 // line 933, offset 0x8002a998
	/* begin block 1 */
		// Start line: 935
		// Start offset: 0x8002A998
		// Variables:
	// 		short i; // $a2
	/* end block 1 */
	// End offset: 0x8002AA3C
	// End Line: 944

	/* begin block 2 */
		// Start line: 2008
	/* end block 2 */
	// End Line: 2009

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pvl_InitMonsters(void)

{
  _D3_OBJECT *p_Var1;
  _MONSTER *p_Var2;
  _PVL_HEADER *p_Var3;
  int iVar4;
  _MONSTER *p_Var5;
  int iVar6;
  
  p_Var3 = Pvl_File;
  p_Var2 = Pvl_Monsters;
  p_Var1 = Pvl_Objects;
  iVar6 = 0;
  if (0 < Pvl_File->n_monsters) {
    iVar4 = 0;
    do {
      p_Var5 = p_Var2 + (iVar4 >> 0x10);
      iVar6 = iVar6 + 1;
      *(_MONSTER **)((int)p_Var1 + (int)p_Var5->obj * 0xa4 + 0xa0) = p_Var5;
      p_Var5->obj = (_D3_OBJECT *)((int)p_Var1 + (int)p_Var5->obj * 0xa4);
      iVar4 = iVar6 * 0x10000;
    } while (iVar6 * 0x10000 >> 0x10 < (int)p_Var3->n_monsters);
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Pvl_PlaySector(short sector /*$a0*/, long entry /*$s1*/)
 // line 953, offset 0x8002aa44
	/* begin block 1 */
		// Start line: 954
		// Start offset: 0x8002AA44
		// Variables:
	// 		long first; // $s0
	// 		long i; // $s0
	// 		struct PVL_5fake m; // stack offset -48
	/* end block 1 */
	// End offset: 0x8002ACA8
	// End Line: 1113

	/* begin block 2 */
		// Start line: 2058
	/* end block 2 */
	// End Line: 2059

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long Pvl_PlaySector(short sector,long entry)

{
  bool bVar1;
  long lVar2;
  int iVar3;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  Pvl_Pause = 0;
  Pvl_SectorNumber = sector;
  M_srand(1);
  memset(&local_30,0,0x20);
  setCopControlWord(2,0,local_30);
  setCopControlWord(2,0x800,local_2c);
  setCopControlWord(2,0x1000,local_28);
  setCopControlWord(2,0x1800,local_24);
  setCopControlWord(2,0x2000,local_20);
  setCopControlWord(2,0x2800,local_1c);
  setCopControlWord(2,0x3000,local_18);
  setCopControlWord(2,0x3800,local_14);
  if (entry == 0x4c564c53) {
    Pvl_CheckPoint(0x4c564c53,0);
  }
  Pvl_EngineHandle = Task_Link(Pvl_EngineTask,0xc00);
  Pvl_EngineHandle->s0 = entry;
  Task_Next();
  Scr_Fade(1,0xf);
  bVar1 = true;
  OVER_DISPLAY = 1;
  Stats_LoadingEnd();
  while( true ) {
    Sound_ManageVoices();
    if (Pvl_Pause == 0) {
      Pvl_GameTime = Pvl_GameTime + 1;
    }
    if (((_DAT_800b1c56 & 8) != 0) && (!bVar1)) break;
    if (Pvl_Demo == 0) {
      lVar2 = Joy_ReadLog(0);
      Pvl_Run0 = (ushort)lVar2;
      lVar2 = Joy_ReadTrig(0);
      Pvl_Trig0 = (ushort)lVar2;
      if (((!bVar1) && (Pvl_Pause == 0)) && (lVar2 = Joy_IsConnected(0), lVar2 == 0)) {
        Pvl_PauseGame();
        while (lVar2 = Joy_IsConnected(0), lVar2 == 0) {
          Text_SetText((char *)Pvl_UtilityTexts[0x2d],-0x7ffe,-0x7ffd);
          Task_Next();
        }
        Pvl_UnpauseGame();
      }
    }
    else {
      lVar2 = Demo_PlayFrame();
      if ((lVar2 != 0) || (lVar2 = Joy_ReadLog(0), lVar2 != 0)) {
        Pvl_PauseGame();
        Pvl_ExitSector();
LAB_8002ac50:
        iVar3 = 0;
        Overlay_EndSector();
        Pl_DeletePlayer((_PLAYER *)&Player);
        Task_KillList(TaskCurrent->child);
        Track_SetMode(1,0);
        Pvl_DeleteFile();
        do {
          iVar3 = iVar3 + 1;
          Task_Next();
        } while (iVar3 < 5);
        Main_Prims = (&Pvl_Prims2)[(int)Scr_Frame];
        return entry;
      }
    }
    bVar1 = false;
    Task_Next();
  }
  entry = Pvl_ExitSector();
  goto LAB_8002ac50;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Pvl_ExitSector()
 // line 1120, offset 0x8002ace4
	/* begin block 1 */
		// Start line: 1121
		// Start offset: 0x8002ACE4
		// Variables:
	// 		struct _ZONE *z; // $a0
	// 		long entry; // $s3
	// 		long save; // $s1
	// 		long i; // $s0
	// 		long game_over; // $s0

		/* begin block 1.1 */
			// Start line: 1155
			// Start offset: 0x8002AD7C
			// Variables:
		// 		long level; // $a0
		/* end block 1.1 */
		// End offset: 0x8002ADF8
		// End Line: 1165
	/* end block 1 */
	// End offset: 0x8002B034
	// End Line: 1250

	/* begin block 2 */
		// Start line: 2498
	/* end block 2 */
	// End Line: 2499

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

long Pvl_ExitSector(void)

{
  bool bVar1;
  bool bVar2;
  _SCREEN *p_Var3;
  int iVar4;
  PVL_45fake *pPVar5;
  int iVar6;
  long entry;
  
  bVar1 = false;
  bVar2 = false;
  if (Pvl_Demo == 0) {
    if ((((Pvl_SectorNumber == 0xb) && (_DAT_800b1d50 != 0)) &&
        (*(int *)(_DAT_800b1d50 + 0x18) == 0x34303245)) || (_DAT_800b1d5a == 0x101)) {
      entry = 0x47444e45;
    }
    else {
      if (_DAT_800b1d5a == 0x201) {
        bVar2 = true;
        entry = 0x45564f47;
      }
      else {
        if (_DAT_800b1d50 == 0) {
          entry = 0;
          if (Pvl_CheckPtSector != 0) {
            Pvl_SectorNumber = Pvl_CheckPtSector;
            entry = Pvl_CheckPtEntry;
          }
        }
        else {
          Pvl_SectorNumber =
               ((ushort)(byte)(Pvl_ExitNames + (int)*(short *)(_DAT_800b1d50 + 0x1c) * 0x20)[0xf] -
               0x30) + ((ushort)(byte)(Pvl_ExitNames + (int)*(short *)(_DAT_800b1d50 + 0x1c) * 0x20)
                                      [0xe] - 0x30) * 10;
          iVar4 = (int)Pvl_LevelNumber;
          iVar6 = (uint)(byte)(Pvl_ExitNames + (int)*(short *)(_DAT_800b1d50 + 0x1c) * 0x20)[6] +
                  0xffd0 + ((uint)(byte)(Pvl_ExitNames +
                                        (int)*(short *)(_DAT_800b1d50 + 0x1c) * 0x20)[5] - 0x30) *
                           10;
          Pvl_LevelNumber = (short)iVar6;
          entry = *(long *)(_DAT_800b1d50 + 0x18);
          if (iVar4 != iVar6 * 0x10000 >> 0x10) {
            bVar1 = true;
            entry = *(long *)(_DAT_800b1d50 + 0x18);
          }
        }
      }
    }
    if ((_DAT_800b1c58 == 0) && (Task_Sleep((int)Scr_TicksPerSecond * 3), _DAT_800b1e30 == 1)) {
      bVar2 = true;
    }
  }
  if (bVar2) {
    Stats_GameOver();
  }
  Task_EventExec(Overlay_Handle,Overlay_Handle->event_msg | 2,Overlay_Handle->event_param);
  if (bVar1) {
    Pvl_PauseGame();
    _DAT_800b1c56 = _DAT_800b1c56 & 0xfff7;
    InGame_LevelEnd((_PLAYER *)&Player,entry);
    _DAT_800b1c56 = _DAT_800b1c56 | 8;
  }
  Pvl_StopXA();
  Sky_DeleteFile();
  Scr_Fade(0,Scr_TicksPerSecond);
  OVER_DISPLAY = 0;
  Scr_FadeWait();
  if (((_DAT_800b1e30 == 1) && (_DAT_800b1c58 == 0)) &&
     (iVar6 = 0, 0 < (int)Scr_TicksPerSecond << 1)) {
    do {
      p_Var3 = Scr;
      pPVar5 = Pvl_BlackScreen + (int)Scr_Frame;
      pPVar5->tag = pPVar5->tag & 0xff000000 | Scr->ot[1] & 0xffffff;
      p_Var3->ot[1] = p_Var3->ot[1] & 0xff000000 | (uint)pPVar5 & 0xffffff;
      Task_Next();
      iVar6 = iVar6 + 1;
    } while (iVar6 < (int)Scr_TicksPerSecond << 1);
  }
  Pvl_UnpauseGame();
  if (_DAT_800b1c58 == 0) {
    PSpell_EndSpell((_PLAYER *)&Player);
    Manim_SetEffect((M_OBJECT *)&DAT_800b1cdc,(TDRFuncPtr_Manim_SetEffect1f)0x0);
    _DAT_800b1c58 = 100;
    _DAT_800b1d62 = 0;
    Pl_SetStateBits((_PLAYER *)&Player,0x20);
    _DAT_800b1e30 = _DAT_800b1e30 + -1;
  }
  return entry;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pvl_EngineTask()
 // line 1254, offset 0x8002b058
	/* begin block 1 */
		// Start line: 1255
		// Start offset: 0x8002B058
		// Variables:
	// 		long entry; // $s0
	// 		char text[64]; // stack offset -72
	/* end block 1 */
	// End offset: 0x8002B0EC
	// End Line: 1298

	/* begin block 2 */
		// Start line: 2793
	/* end block 2 */
	// End Line: 2794

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pvl_EngineTask(void)

{
  long Entry;
  
  Sound_Off();
  Entry = TaskCurrent->s0;
  Pvl_InitFile(Pvl_LevelNumber,Pvl_SectorNumber,Entry);
  Pl_AddPlayer((_PLAYER *)&Player,Entry);
  Pvl_GetXA();
  Main_Prims = (&Pvl_Prims2)[(int)Scr_Frame];
  Task_Next();
  TaskCurrent->display = Pvl_EngineDisplay;
  do {
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pvl_EngineDisplay()
 // line 1301, offset 0x8002b0ec
	/* begin block 1 */
		// Start line: 1302
		// Start offset: 0x8002B0EC
	/* end block 1 */
	// End offset: 0x8002B274
	// End Line: 1424

	/* begin block 2 */
		// Start line: 2904
	/* end block 2 */
	// End Line: 2905

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pvl_EngineDisplay(void)

{
  _SCREEN *p_Var1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  
  Main_Prims = (&Pvl_Prims2)[(int)Scr_Frame];
  Main_TextContext.Font.ascii_tab._20_4_ = (int)Main_Prims + 0x172b4;
  Cam_SetMatrix(0x68,0x70);
  Main_Prims = Plat_Display(Main_Prims);
  p_Var1 = Scr;
  if (Pvl_Demo != 0) {
    puVar4 = (uint *)(&Pvl_DemoPrims + (int)Scr_Frame * 0x28);
    *puVar4 = *puVar4 & 0xff000000 | Scr->ot[8] & 0xffffff;
    p_Var1->ot[8] = p_Var1->ot[8] & 0xff000000 | (uint)puVar4 & 0xffffff;
  }
  uVar2 = Joy_ReadLog(0);
  if ((uVar2 & 0x100) != 0) {
    Pvl_AbortGame();
  }
  if (Pvl_Run0 == 0) {
    Pvl_ResetWanted = Pvl_ResetWanted + 1;
  }
  else {
    Pvl_ResetWanted = 0;
  }
  iVar3 = (int)Scr_TicksPerSecond;
  if (iVar3 == 0) {
    trap(0x1c00);
  }
  if ((iVar3 == -1) && ((int)Pvl_ResetWanted == -0x80000000)) {
    trap(0x1800);
  }
  if (Main_TextContext.Font.ascii_tab._16_4_ <= (int)Pvl_ResetWanted / iVar3) {
    Pvl_AbortGame();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pvl_InitFile(short level /*$a0*/, short sector /*$a1*/, long Entry /*$a2*/)
 // line 1433, offset 0x8002b284
	/* begin block 1 */
		// Start line: 1434
		// Start offset: 0x8002B284
		// Variables:
	// 		long i; // $s0
	// 		long wMap; // $v1
	// 		long hMap; // $v0
	/* end block 1 */
	// End offset: 0x8002B67C
	// End Line: 1535

	/* begin block 2 */
		// Start line: 3189
	/* end block 2 */
	// End Line: 3190

void Pvl_InitFile(short level,short sector,long Entry)

{
  TMD_72fake *Tmd;
  void *T;
  uint uVar1;
  int Index;
  
  Pvl_EnemyShots = (_D3_OBJECT *)0x0;
  Pvl_PlayerShots = (_D3_OBJECT *)0x0;
  Pvl_LevelNumber = level;
  Pvl_SectorNumber = sector;
  Pvl_ReadSector();
  Pvl_File = (_PVL_HEADER *)FileGroup_GetAddr(Pvl_Lnk,0);
  Pvl_SetSctState();
  SetBackColor((uint)(Pvl_File->light_ambient).r,(uint)(Pvl_File->light_ambient).g,
               (uint)(Pvl_File->light_ambient).b);
  Pvl_Map = (char *)(Pvl_File + 1);
  Pvl_SortLights =
       (short *)(((_PVL_HEADER *)Pvl_Map)->id + (int)Pvl_File->map_w * (int)Pvl_File->map_h);
  Pvl_Platforms =
       (_PLATFORM *)(Pvl_SortLights + (int)Pvl_File->map_w * (int)Pvl_File->map_h * 2 * 4);
  Pvl_Objects = (_D3_OBJECT *)((int)Pvl_Platforms + (int)Pvl_File->n_platforms * 0xa4);
  Pvl_HoleObjects = (_D3_OBJECT *)((int)Pvl_Objects + (int)Pvl_File->n_lobjects * 0xa4);
  Pvl_GlobalObjects = (_D3_OBJECT *)((int)Pvl_HoleObjects + (int)Pvl_File->n_hobjects * 0xa4);
  Pvl_Lights = (_LIGHT *)((int)Pvl_GlobalObjects + (int)Pvl_File->n_gobjects * 0xa4);
  Pvl_AnimBlinks = (_ANIM_BLINK *)(&((_D3_OBJECT *)Pvl_Lights)->next + (int)Pvl_File->n_lights * 8);
  Pvl_Zones = (_ZONE *)(&Pvl_AnimBlinks->coef_max + (int)Pvl_File->n_animblinks * 0x10);
  Pvl_Visibility = (char *)(&Pvl_Zones->x1 + (int)Pvl_File->n_zones * 0x18);
  Pvl_Indices = (long *)((int)Pvl_Visibility + (int)Pvl_File->n_visibilitys);
  Pvl_EnemyZones = (_ENEMYZONE *)(Pvl_Indices + (int)Pvl_File->n_indices);
  Pvl_Monsters = (_MONSTER *)(Pvl_EnemyZones + (int)Pvl_File->n_enemyzones);
  Pvl_Matrix = (_ROTMATRIX *)(Pvl_Monsters + (int)Pvl_File->n_monsters);
  Pvl_Mobjects = (M_OBJECT *)(&((_MONSTER *)Pvl_Matrix)->obj + (int)Pvl_File->n_matrix * 5);
  Pvl_Cameras = (_CAMERA *)(&Pvl_Mobjects->sit + (int)Pvl_File->n_mobjects * 0xd);
  Pvl_ExitNames = (char *)((int)&Pvl_Cameras->pos + (int)Pvl_File->n_cameras * 0x1c);
  Pvl_Blinks = (long *)(&((_struct_323 *)Pvl_ExitNames)->vx + (int)Pvl_File->n_exitnames * 0x10);
  Pvl_Shapes = Pvl_Blinks + (int)Pvl_File->n_blinks;
  if (Pvl_File->n_lobjects == 0) {
    Pvl_Objects = (_D3_OBJECT *)0x0;
  }
  if (Pvl_File->n_gobjects == 0) {
    Pvl_GlobalObjects = (_D3_OBJECT *)0x0;
  }
  if (Pvl_File->n_hobjects == 0) {
    Pvl_HoleObjects = (_D3_OBJECT *)0x0;
  }
  if (Pvl_File->n_lights == 0) {
    Pvl_Lights = (_LIGHT *)0x0;
  }
  if (Pvl_File->n_blinks == 0) {
    Pvl_Blinks = (long *)0x0;
  }
  Index = 0;
  SetFarColor((uint)(Pvl_File->fog).r,(uint)(Pvl_File->fog).g,(uint)(Pvl_File->fog).b);
  uVar1 = (uint)(Pvl_File->fog).cd;
  SetFogNearFar((uVar1 - 4) * 100,uVar1 * 100,0x100);
  Screens.draw.r0 = (Pvl_File->fog).r;
  Screens.draw.g0 = (Pvl_File->fog).g;
  Screens.draw.b0 = (Pvl_File->fog).b;
  _SCREEN_800b993c.draw.r0 = Screens.draw.r0;
  _SCREEN_800b993c.draw.g0 = Screens.draw.g0;
  _SCREEN_800b993c.draw.b0 = Screens.draw.b0;
  if (0 < *(int *)Pvl_LnkLocals) {
    do {
      Tmd = (TMD_72fake *)FileGroup_GetAddr(Pvl_LnkLocals,Index);
      Tmd_InitFile(Tmd);
      T = FileGroup_GetAddr(Pvl_LnkLocals,Index);
      Shp_TmdToVram(Pvl_Pcl,T,0,1);
      Index = Index + 1;
    } while (Index < *(int *)Pvl_LnkLocals);
  }
  Vis_InitFile();
  Plat_InitFile();
  Object_InitFile();
  Light_InitFile();
  Zone_InitFile();
  Track_InitFile();
  Pvl_InitBlink();
  Wind_InitFile();
  Sky_InitFile();
  Pvl_Texts = Pvl_GetSectorText(Pvl_File->crc);
  Pvl_UpdateSctState();
  if (Pvl_File->n_monsters != 0) {
    Pvl_InitMonsters();
  }
  Invent_SetTakenObjects();
  Pvl_LoadedGame = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pvl_DeleteFile()
 // line 1544, offset 0x8002b698
	/* begin block 1 */
		// Start line: 1545
		// Start offset: 0x8002B698
		// Variables:
	// 		short i; // $s0
	/* end block 1 */
	// End offset: 0x8002B760
	// End Line: 1585

	/* begin block 2 */
		// Start line: 3441
	/* end block 2 */
	// End Line: 3442

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pvl_DeleteFile(void)

{
  uint uVar1;
  
  Wind_DeleteFile();
  if ((Pvl_File->mode & 1U) != 0) {
    if (Pvl_LoadedGame != 0) goto LAB_8002b6f4;
    Invent_RemoveMarkedObject(0x19);
  }
  if (Pvl_LoadedGame == 0) {
    Pvl_SaveMonsters();
  }
LAB_8002b6f4:
  Shp_GroupRelease(Pvl_Pcl,1);
  Heap_FreeMem(Pvl_Lnk);
  if (Pvl_nSounds != 0) {
    uVar1 = (uint)(ushort)Sound_nSounds;
    while (uVar1 = uVar1 - 1, (int)(uint)(byte)Pvl_Sounds[0] <= (int)(uVar1 * 0x10000) >> 0x10) {
      Sound_FreeSRAM((char)uVar1);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pvl_InitBlink()
 // line 1588, offset 0x8002b770
	/* begin block 1 */
		// Start line: 1589
		// Start offset: 0x8002B770
		// Variables:
	// 		long i; // $t0
	// 		long ig; // $t2
	// 		long n; // $t5
	// 		long j; // $t1
	// 		long ip; // $a1
	// 		long ic; // $a2
	// 		long io; // $a0
	// 		long *blink; // $t4
	// 		struct PVL_8fake *c; // $t3
	// 		struct PVL_8fake t; // stack offset -16
	// 		struct PVL_74fake *Tmd; // $t7
	// 		struct PVL_92fake *prim; // $v1
	// 		long *Primitives; // $v1
	/* end block 1 */
	// End offset: 0x8002B8BC
	// End Line: 1715

	/* begin block 2 */
		// Start line: 3546
	/* end block 2 */
	// End Line: 3547

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pvl_InitBlink(void)

{
  long *plVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  long *plVar12;
  
  if (Pvl_Blinks != (long *)0x0) {
    pvVar2 = FileGroup_GetAddr(Pvl_Lnk,1);
    plVar1 = Pvl_Blinks;
    iVar11 = 0;
    if (0 < Pvl_File->n_blinks) {
      iVar3 = 0;
      do {
        iVar9 = 0;
        iVar3 = *(int *)(iVar3 + (int)plVar1);
        plVar12 = plVar1 + iVar11 + 1;
        if (0 < iVar3) {
          iVar4 = 0;
          do {
            iVar9 = iVar9 + 2;
            iVar4 = (int)plVar12 + iVar4;
            iVar10 = 0;
            if (*(char *)(iVar4 + 3) != '\0') {
              puVar8 = (uint *)(plVar12 + iVar9);
              do {
                iVar7 = (int)*puVar8 >> 0x10;
                iVar6 = *(int *)((int)pvVar2 + (uint)*(byte *)((int)puVar8 + 1) * 0x1c + 0x1c) +
                        (*puVar8 & 0xff) * 0x2c;
                if (iVar7 == 1) {
                  uVar5 = iVar6 + 0x18;
LAB_8002b874:
                  *puVar8 = uVar5;
                }
                else {
                  if (iVar7 < 2) {
                    uVar5 = iVar6 + 0x14;
                    if (iVar7 == 0) goto LAB_8002b874;
                  }
                  else {
                    uVar5 = iVar6 + 0x1c;
                    if ((iVar7 == 2) || (uVar5 = iVar6 + 0x20, iVar7 == 3)) goto LAB_8002b874;
                  }
                }
                iVar10 = iVar10 + 1;
                puVar8 = puVar8 + 1;
                iVar9 = iVar9 + 1;
              } while (iVar10 < (int)(uint)*(byte *)(iVar4 + 3));
            }
            iVar4 = iVar9 << 2;
          } while (iVar9 < iVar3);
        }
        iVar11 = iVar11 + 1 + iVar9;
        iVar3 = iVar11 * 4;
      } while (iVar11 < (int)Pvl_File->n_blinks);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pvl_ReadSector()
 // line 1718, offset 0x8002b8cc
	/* begin block 1 */
		// Start line: 1719
		// Start offset: 0x8002B8CC
		// Variables:
	// 		void *All; // $v0
	// 		long Lnkl; // $s2
	// 		long Pcll; // $s0
	// 		long Sndl; // $s1
	/* end block 1 */
	// End offset: 0x8002B8CC
	// End Line: 1719

	/* begin block 2 */
		// Start line: 3825
	/* end block 2 */
	// End Line: 3826

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pvl_ReadSector(void)

{
  char *name;
  void *ptt;
  long nbytes;
  long nbytes_00;
  long nbytes_01;
  
  name = Pvl_GetAllName();
  File_Seek(name);
  ptt = File_ReadBytes(0x800,(void *)0x0);
  nbytes = *(long *)((int)ptt + 8);
  nbytes_00 = *(long *)((int)ptt + 0x10);
  nbytes_01 = *(long *)((int)ptt + 0x18);
  Heap_FreeMem(ptt);
  Pvl_Pcl = File_ReadBytes(nbytes,(void *)0x0);
  Shp_GroupToVram(Pvl_Pcl,1);
  Pvl_SoundFile = File_ReadBytes(nbytes_00,(void *)0x0);
  Pvl_SndToSram(Pvl_SoundFile);
  Heap_FreeMem(Pvl_SoundFile);
  Pvl_Lnk = File_ReadBytes(nbytes_01,(void *)0x0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pvl_SndToSram(void *file /*$s2*/)
 // line 1761, offset 0x8002b97c
	/* begin block 1 */
		// Start line: 1762
		// Start offset: 0x8002B97C
		// Variables:
	// 		short i; // $s1
	/* end block 1 */
	// End offset: 0x8002B9FC
	// End Line: 1770

	/* begin block 2 */
		// Start line: 3926
	/* end block 2 */
	// End Line: 3927

void Pvl_SndToSram(void *file)

{
  short sVar1;
  void *group;
  short sVar2;
  int iVar3;
  
  Pvl_nSounds = *(short *)file;
  iVar3 = 0;
  if (0 < (int)((uint)(ushort)Pvl_nSounds << 0x10)) {
    do {
      sVar2 = (short)iVar3;
      group = FileGroup_GetAddr(file,(int)sVar2);
      sVar1 = Sound_AllocGroup(group);
      iVar3 = iVar3 + 1;
      Pvl_Sounds[(int)sVar2] = (char)sVar1;
    } while (iVar3 * 0x10000 >> 0x10 < (int)Pvl_nSounds);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pvl_ClearSctState()
 // line 1779, offset 0x8002ba18
	/* begin block 1 */
		// Start line: 1781
		// Start offset: 0x8002BA18
		// Variables:
	// 		short i; // $a0
	/* end block 1 */
	// End offset: 0x8002BACC
	// End Line: 1797

	/* begin block 2 */
		// Start line: 3969
	/* end block 2 */
	// End Line: 3970

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pvl_ClearSctState(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  Scts_Interruptors = 0;
  iVar3 = 0;
  iVar2 = 0;
  do {
    (&Scts_States)[iVar2 >> 0x10] = '\0';
    iVar3 = iVar3 + 1;
    iVar2 = iVar3 * 0x10000;
  } while (iVar3 * 0x10000 >> 0x10 < 0x780);
  iVar3 = 0;
  iVar2 = 0;
  do {
    *(undefined4 *)((int)&Scts_Zones + (iVar2 >> 0xe)) = 0;
    iVar3 = iVar3 + 1;
    iVar2 = iVar3 * 0x10000;
  } while (iVar3 * 0x10000 >> 0x10 < 0x3c);
  iVar2 = 0;
  do {
    sVar1 = (short)iVar2;
    iVar2 = iVar2 + 1;
    (&Scts_Crcs)[(int)sVar1 * 6] = 0;
  } while (iVar2 * 0x10000 >> 0x10 < 0xf);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pvl_SetSctState()
 // line 1800, offset 0x8002bad4
	/* begin block 1 */
		// Start line: 1801
		// Start offset: 0x8002BAD4
		// Variables:
	// 		long first_time; // $t6
	// 		long i; // $a3
	// 		long index_o; // $t2
	// 		long n_o; // $t3
	// 		long index_m; // $a1
	// 		long n_m; // $t5
	// 		long index_z; // $t1
	// 		long n_z; // $t4

		/* begin block 1.1 */
			// Start line: 1845
			// Start offset: 0x8002BC70
			// Variables:
		// 		long mask; // $a1
		/* end block 1.1 */
		// End offset: 0x8002BCD8
		// End Line: 1865
	/* end block 1 */
	// End offset: 0x8002BD1C
	// End Line: 1875

	/* begin block 2 */
		// Start line: 4010
	/* end block 2 */
	// End Line: 4011

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pvl_SetSctState(void)

{
  short sVar1;
  short sVar2;
  short sVar3;
  bool bVar4;
  char *pcVar5;
  uint uVar6;
  uint *puVar7;
  char cVar8;
  uint uVar9;
  short *psVar10;
  int iVar11;
  undefined2 uVar12;
  int iVar13;
  short sVar14;
  int iVar15;
  
  sVar14 = 0;
  cVar8 = '\0';
  iVar13 = 0;
  bVar4 = false;
  iVar11 = 0;
  psVar10 = &Scts_Crcs;
  sVar1 = Pvl_File->n_monsters;
  sVar2 = Pvl_File->n_zones;
  iVar15 = (int)Pvl_File->n_lobjects + (int)Pvl_File->n_gobjects + (int)Pvl_File->n_hobjects;
  do {
    uVar12 = (undefined2)iVar13;
    if (*psVar10 == 0) goto LAB_8002bbb0;
    iVar13 = iVar11 << 1;
    if (*psVar10 == Pvl_File->crc) goto LAB_8002bb8c;
    sVar14 = psVar10[1] + psVar10[2];
    iVar13 = (int)psVar10[3] + (int)psVar10[4] + 0x1f;
    cVar8 = *(char *)(psVar10 + 5) + *(char *)((int)psVar10 + 0xb);
    if (iVar13 < 0) {
      iVar13 = (int)psVar10[3] + (int)psVar10[4] + 0x3e;
    }
    iVar13 = (iVar13 >> 5) << 5;
    uVar12 = (undefined2)iVar13;
    iVar11 = iVar11 + 1;
    psVar10 = psVar10 + 6;
  } while (iVar11 < 0xf);
  iVar13 = iVar11 * 2;
LAB_8002bb8c:
  if ((&Scts_Crcs)[(iVar13 + iVar11) * 2] == 0) {
LAB_8002bbb0:
    bVar4 = true;
    sVar3 = Pvl_File->crc;
    (&DAT_800b131a)[iVar11 * 6] = sVar14;
    (&DAT_800b131c)[iVar11 * 6] = (short)iVar15;
    (&DAT_800b1322)[iVar11 * 0xc] = cVar8;
    (&DAT_800b1323)[iVar11 * 0xc] = (char)sVar1;
    (&DAT_800b131e)[iVar11 * 6] = uVar12;
    (&DAT_800b1320)[iVar11 * 6] = sVar2;
    (&Scts_Crcs)[iVar11 * 6] = sVar3;
  }
  iVar13 = (int)(short)(&DAT_800b131e)[iVar11 * 6];
  Pvl_SctState = &Scts_States + (int)(short)(&DAT_800b131a)[iVar11 * 6];
  if (iVar13 < 0) {
    iVar13 = iVar13 + 0x1f;
  }
  Pvl_SctZones = &Scts_Zones + (iVar13 >> 5);
  Pvl_SctMonsters = &Scts_Monsters + (uint)(byte)(&DAT_800b1322)[iVar11 * 0xc] * 2;
  if ((Pvl_File->mode & 1U) != 0) {
    iVar11 = 0;
    if (0 < iVar15) {
      do {
        pcVar5 = Pvl_SctState + iVar11;
        iVar11 = iVar11 + 1;
        *pcVar5 = '\0';
      } while (iVar11 < iVar15);
    }
    uVar9 = 1;
    iVar11 = 0;
    if (0 < (int)sVar2) {
      uVar6 = 0xfffffffe;
      puVar7 = (uint *)Pvl_SctZones;
      do {
        uVar9 = uVar9 << 1;
        *puVar7 = *puVar7 & uVar6;
        if (uVar9 == 0) {
          uVar9 = 1;
          puVar7 = puVar7 + 1;
        }
        iVar11 = iVar11 + 1;
        uVar6 = ~uVar9;
      } while (iVar11 < (int)sVar2);
    }
  }
  if (((Pvl_File->mode & 2U) != 0) && (bVar4)) {
    Invent_SetAllInvisible((_PLAYER *)&Player);
    Overlay_ChangeRWeapon((_PLAYER *)&Player,0x14);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pvl_UpdateSctState()
 // line 1878, offset 0x8002bd2c
	/* begin block 1 */
		// Start line: 1879
		// Start offset: 0x8002BD2C
		// Variables:
	// 		short i; // $s2
	// 		struct _MONSTER *m; // $v1
	// 		struct _PLATFORM *p; // $s0
	// 		struct _ZONE *z; // $s1
	/* end block 1 */
	// End offset: 0x8002BF90
	// End Line: 1916

	/* begin block 2 */
		// Start line: 4250
	/* end block 2 */
	// End Line: 4251

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pvl_UpdateSctState(void)

{
  short sVar1;
  _D3_OBJECT *p_Var2;
  int iVar3;
  long lVar4;
  _D3_OBJECT *p_Var5;
  _MONSTER *p_Var6;
  _PLATFORM *p_Var7;
  char *pcVar8;
  short *psVar9;
  _ZONE *z;
  int iVar10;
  
  iVar10 = 0;
  p_Var7 = Pvl_Platforms;
  if (0 < Pvl_File->n_platforms) {
    do {
      p_Var2 = &p_Var7->obj;
      p_Var7 = (_PLATFORM *)&p_Var7[1].obj.last_pos.vz;
      Pvl_UpdateListSctState(p_Var2->child);
      iVar10 = iVar10 + 1;
    } while (iVar10 * 0x10000 >> 0x10 < (int)Pvl_File->n_platforms);
  }
  iVar10 = 0;
  Pvl_UpdateListSctState(Pvl_GlobalObjects);
  Pvl_UpdateListSctState(Pvl_HoleObjects);
  psVar9 = &Pvl_Monsters->index;
  if (0 < Pvl_File->n_monsters) {
    do {
      lVar4 = Pvl_TestStateBits((_D3_OBJECT *)
                                ((int)Pvl_Objects + (int)Pvl_Monsters[(int)(short)iVar10].obj * 0xa4
                                ),1);
      p_Var2 = Pvl_Objects;
      iVar3 = Pvl_SctMonsters;
      if (lVar4 != 0) {
        p_Var6 = Pvl_Monsters + (int)(short)iVar10;
        sVar1 = *(short *)((int)*psVar9 * 8 + Pvl_SctMonsters);
        p_Var5 = (_D3_OBJECT *)((int)p_Var6->obj * 0xa4 + (int)Pvl_Objects);
        (p_Var5->pos).vx = sVar1;
        (p_Var5->last_pos).vx = sVar1;
        sVar1 = *(short *)((int)*psVar9 * 8 + iVar3 + 2);
        p_Var5 = (_D3_OBJECT *)((int)p_Var6->obj * 0xa4 + (int)p_Var2);
        (p_Var5->pos).vy = sVar1;
        (p_Var5->last_pos).vy = sVar1;
        sVar1 = *(short *)((int)*psVar9 * 8 + iVar3 + 4);
        p_Var5 = (_D3_OBJECT *)((int)p_Var6->obj * 0xa4 + (int)p_Var2);
        (p_Var5->pos).vz = sVar1;
        (p_Var5->last_pos).vz = sVar1;
        *(undefined2 *)((int)p_Var2 + (int)p_Var6->obj * 0xa4 + 0x20) =
             *(undefined2 *)((int)*psVar9 * 8 + iVar3 + 6);
      }
      iVar10 = iVar10 + 1;
      psVar9 = psVar9 + 0xb0;
    } while (iVar10 * 0x10000 >> 0x10 < (int)Pvl_File->n_monsters);
  }
  iVar10 = 0;
  if (0 < Pvl_File->n_zones) {
    pcVar8 = &Pvl_Zones->camera;
    z = Pvl_Zones;
    do {
      lVar4 = Pvl_TestZoneStateBits(z,1);
      if (lVar4 != 0) {
        *(undefined2 *)(pcVar8 + -0xc) = 0xffff;
        *pcVar8 = -1;
        *(uint *)(pcVar8 + -6) = *(uint *)(pcVar8 + -6) & 0xffffffef;
      }
      iVar10 = iVar10 + 1;
      pcVar8 = pcVar8 + 0x30;
      z = z + 1;
    } while (iVar10 * 0x10000 >> 0x10 < (int)Pvl_File->n_zones);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pvl_UpdateListSctState(struct _D3_OBJECT *o /*$s0*/)
 // line 1919, offset 0x8002bfb0
	/* begin block 1 */
		// Start line: 4346
	/* end block 1 */
	// End Line: 4347

void Pvl_UpdateListSctState(_D3_OBJECT *o)

{
  long lVar1;
  
  if (o != (_D3_OBJECT *)0x0) {
    do {
      if (o->child != (_D3_OBJECT *)0x0) {
        Pvl_UpdateListSctState(o->child);
      }
      if (-1 < o->index) {
        if (((int)(uint)*(byte *)&o[1].pos.vx >> ((int)Pvl_Difficulty & 0x1fU) & 1U) == 0) {
LAB_8002c078:
          D3_DeleteObject(o);
        }
        else {
          lVar1 = Pvl_TestStateBits(o,0x80);
          if (lVar1 != 0) {
            if ((o->child == (_D3_OBJECT *)0x0) ||
               (*(char *)((int)&o->child[1].pos.vx + 1) != '\x03')) goto LAB_8002c078;
            o->display_mode = o->display_mode & 0xffef;
            D3_ClearCollBits(o,1);
            o->child->display_mode = o->child->display_mode | 0x10;
            D3_SetCollBits(o->child,1);
          }
        }
      }
      o = o->next;
    } while (o != (_D3_OBJECT *)0x0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pvl_SaveMonsters()
 // line 1953, offset 0x8002c0a0
	/* begin block 1 */
		// Start line: 1954
		// Start offset: 0x8002C0A0
		// Variables:
	// 		short i; // $s2
	// 		struct _MONSTER *m; // $s0
	/* end block 1 */
	// End offset: 0x8002C178
	// End Line: 1965

	/* begin block 2 */
		// Start line: 4444
	/* end block 2 */
	// End Line: 4445

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pvl_SaveMonsters(void)

{
  int iVar1;
  long lVar2;
  _MONSTER *p_Var3;
  short *psVar4;
  int iVar5;
  
  iVar5 = 0;
  if (0 < Pvl_File->n_monsters) {
    psVar4 = &Pvl_Monsters->index;
    p_Var3 = Pvl_Monsters;
    do {
      iVar1 = Pvl_SctMonsters;
      *(short *)((int)*psVar4 * 8 + Pvl_SctMonsters) = (p_Var3->obj->pos).vx;
      *(short *)((int)*psVar4 * 8 + iVar1 + 2) = (p_Var3->obj->pos).vy;
      *(short *)((int)*psVar4 * 8 + iVar1 + 4) = (p_Var3->obj->pos).vz;
      *(short *)((int)*psVar4 * 8 + iVar1 + 6) = p_Var3->obj->hit_points;
      lVar2 = Pvl_TestStateBits(p_Var3->obj,4);
      if (lVar2 == 0) {
        Pvl_SetStateBits(p_Var3->obj,1);
      }
      iVar5 = iVar5 + 1;
      psVar4 = psVar4 + 0xb0;
      p_Var3 = p_Var3 + 1;
    } while (iVar5 * 0x10000 >> 0x10 < (int)Pvl_File->n_monsters);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pvl_CheckPoint(long entry /*$a0*/, long fsound /*$a1*/)
 // line 1968, offset 0x8002c190
	/* begin block 1 */
		// Start line: 4480
	/* end block 1 */
	// End Line: 4481

void Pvl_CheckPoint(long entry,long fsound)

{
  if ((entry != Pvl_CheckPtEntry) || (Pvl_SectorNumber != Pvl_CheckPtSector)) {
    Pvl_CheckPtSector = Pvl_SectorNumber;
    Pvl_CheckPtEntry = entry;
    if ((entry != 0x4c564c53) && (Pvl_CheckPtEntry = entry, fsound != 0)) {
      Pvl_CheckPtEntry = entry;
      Fx_Play(0xb,0);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pvl_SetZoneStateBits(struct _ZONE *z /*$a0*/, long v /*$a1*/)
 // line 1981, offset 0x8002c1f0
	/* begin block 1 */
		// Start line: 1983
		// Start offset: 0x8002C1F0
		// Variables:
	// 		long i; // $v1
	// 		long b; // $a0
	/* end block 1 */
	// End offset: 0x8002C1F0
	// End Line: 1985

	/* begin block 2 */
		// Start line: 4514
	/* end block 2 */
	// End Line: 4515

void Pvl_SetZoneStateBits(_ZONE *z,long v)

{
  Pvl_SctZones[(uint)(z->index >> 5)] =
       Pvl_SctZones[(uint)(z->index >> 5)] | v << ((uint)z->index & 0x1f);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pvl_ClearZoneStateBits(struct _ZONE *z /*$a0*/, long v /*$a1*/)
 // line 1992, offset 0x8002c21c
	/* begin block 1 */
		// Start line: 1994
		// Start offset: 0x8002C21C
		// Variables:
	// 		long i; // $v1
	// 		long b; // $v0
	/* end block 1 */
	// End offset: 0x8002C21C
	// End Line: 1996

	/* begin block 2 */
		// Start line: 4539
	/* end block 2 */
	// End Line: 4540

void Pvl_ClearZoneStateBits(_ZONE *z,long v)

{
  Pvl_SctZones[(uint)(z->index >> 5)] =
       Pvl_SctZones[(uint)(z->index >> 5)] & ~(v << ((uint)z->index & 0x1f));
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Pvl_TestZoneStateBits(struct _ZONE *z /*$a0*/, long v /*$a1*/)
 // line 2003, offset 0x8002c24c
	/* begin block 1 */
		// Start line: 2005
		// Start offset: 0x8002C24C
		// Variables:
	// 		long i; // $v0
	// 		long b; // $v1
	/* end block 1 */
	// End offset: 0x8002C24C
	// End Line: 2007

	/* begin block 2 */
		// Start line: 4564
	/* end block 2 */
	// End Line: 4565

long Pvl_TestZoneStateBits(_ZONE *z,long v)

{
  return Pvl_SctZones[(uint)(z->index >> 5)] & v << ((uint)z->index & 0x1f);
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pvl_ClearStateBits(struct _D3_OBJECT *o /*$a0*/, long mask /*$a1*/)
 // line 2014, offset 0x8002c274
	/* begin block 1 */
		// Start line: 4587
	/* end block 1 */
	// End Line: 4588

void Pvl_ClearStateBits(_D3_OBJECT *o,long mask)

{
  if (-1 < (int)o->index) {
    Pvl_SctState[(int)o->index] = Pvl_SctState[(int)o->index] & ~(byte)mask;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pvl_SetStateBits(struct _D3_OBJECT *o /*$a0*/, long mask /*$a1*/)
 // line 2021, offset 0x8002c2a8
	/* begin block 1 */
		// Start line: 4601
	/* end block 1 */
	// End Line: 4602

void Pvl_SetStateBits(_D3_OBJECT *o,long mask)

{
  if (-1 < (int)o->index) {
    Pvl_SctState[(int)o->index] = Pvl_SctState[(int)o->index] | (byte)mask;
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Pvl_TestStateBits(struct _D3_OBJECT *o /*$a0*/, long mask /*$a1*/)
 // line 2028, offset 0x8002c2dc
	/* begin block 1 */
		// Start line: 4615
	/* end block 1 */
	// End Line: 4616

long Pvl_TestStateBits(_D3_OBJECT *o,long mask)

{
  if ((int)o->index < 0) {
    return 0;
  }
  return (uint)(byte)Pvl_SctState[(int)o->index] & mask;
}



// decompiled code
// original method signature: 
// char * /*$ra*/ Pvl_AddMaxs(char *in /*stack 0*/)
 // line 2037, offset 0x8002c30c
	/* begin block 1 */
		// Start line: 4634
	/* end block 1 */
	// End Line: 4635

char * Pvl_AddMaxs(char *in)

{
  char cVar1;
  long lVar2;
  char *local_res0;
  
  cVar1 = *in;
  while (cVar1 != '[') {
    if (*in == '{') goto code_r0x8002c378;
    cVar1 = in[1];
    in = in + 1;
  }
  if (*in == '{') {
code_r0x8002c378:
    local_res0 = in + (int)Pvl_Difficulty * 0x10 + 1;
    lVar2 = Pvl_GetMaxNumber((char **)register0x00000074);
    Pvl_MaxItems = Pvl_MaxItems + (short)lVar2;
    local_res0 = local_res0 + 1;
    lVar2 = Pvl_GetMaxNumber((char **)register0x00000074);
    Pvl_MaxMonsters = Pvl_MaxMonsters + (short)lVar2;
    local_res0 = local_res0 + 1;
    lVar2 = Pvl_GetMaxNumber((char **)register0x00000074);
    Pvl_MaxGaz = Pvl_MaxGaz + (short)lVar2;
    local_res0 = local_res0 + 1;
    lVar2 = Pvl_GetMaxNumber((char **)register0x00000074);
    Pvl_MaxSecrets = Pvl_MaxSecrets + (short)lVar2;
    in = local_res0 + 1;
  }
  return in;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Pvl_GetMaxNumber(char **in /*$a0*/)
 // line 2066, offset 0x8002c434
	/* begin block 1 */
		// Start line: 2068
		// Start offset: 0x8002C434
		// Variables:
	// 		long result; // $a1
	// 		long i; // $a2
	// 		long c; // $v1
	/* end block 1 */
	// End offset: 0x8002C46C
	// End Line: 2079

	/* begin block 2 */
		// Start line: 4722
	/* end block 2 */
	// End Line: 4723

long Pvl_GetMaxNumber(char **in)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = 0;
  do {
    iVar3 = iVar3 + 1;
    bVar1 = **in;
    *in = *in + 1;
    iVar2 = iVar2 * 10 + ((uint)bVar1 - 0x30);
  } while (iVar3 < 3);
  return iVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pvl_InitTexts()
 // line 2089, offset 0x8002c474
	/* begin block 1 */
		// Start line: 2090
		// Start offset: 0x8002C474
		// Variables:
	// 		char *txt; // $v0
	// 		long i; // $a0
	/* end block 1 */
	// End offset: 0x8002C4CC
	// End Line: 2109

	/* begin block 2 */
		// Start line: 4775
	/* end block 2 */
	// End Line: 4776

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pvl_InitTexts(void)

{
  char *in;
  int iVar1;
  int iVar2;
  PVL_135fake *pvl_txt;
  
  in = (char *)Pvl_Txt;
  iVar2 = 0xf;
  iVar1 = -0x7ff4fd34;
  do {
    *(undefined4 *)(iVar1 + 8) = 0;
    iVar2 = iVar2 + -1;
    iVar1 = iVar1 + -0xc;
  } while (-1 < iVar2);
  if (in != (char *)0x0) {
    pvl_txt = &Pvl_TxtSectors;
    do {
      in = Pvl_AddMaxs(in);
      in = Pvl_InitLevelText(in,pvl_txt);
      pvl_txt = pvl_txt + 1;
    } while (in != (char *)0x0);
  }
  Pvl_UtilityTexts = Pvl_GetSectorText(0);
  return;
}



// decompiled code
// original method signature: 
// char * /*$ra*/ Pvl_InitLevelText(char *input /*$a0*/, struct PVL_135fake *pvl_txt /*$a1*/)
 // line 2113, offset 0x8002c4e8
	/* begin block 1 */
		// Start line: 4840
	/* end block 1 */
	// End Line: 4841

char * Pvl_InitLevelText(char *input,PVL_135fake *pvl_txt)

{
  char *pcVar1;
  
  pcVar1 = Text_GetIndexPointers(input,(char *)pvl_txt,&pvl_txt->array);
  return pcVar1;
}



// decompiled code
// original method signature: 
// long * /*$ra*/ Pvl_GetSectorText(short crc /*$a0*/)
 // line 2119, offset 0x8002c508
	/* begin block 1 */
		// Start line: 2120
		// Start offset: 0x8002C508
		// Variables:
	// 		char str[8]; // stack offset -24
	// 		short i; // $s1
	/* end block 1 */
	// End offset: 0x8002C594
	// End Line: 2138

	/* begin block 2 */
		// Start line: 4852
	/* end block 2 */
	// End Line: 4853

long * Pvl_GetSectorText(short crc)

{
  int iVar1;
  short sVar2;
  int iVar3;
  char acStack24 [8];
  
  sprintf(acStack24,&DAT_800ad40c,(int)crc);
  iVar3 = 0;
  do {
    sVar2 = (short)iVar3;
    iVar1 = strcmp(acStack24,(char *)(&Pvl_TxtSectors + (int)sVar2));
    iVar3 = iVar3 + 1;
    if (iVar1 == 0) {
      return (&Pvl_TxtSectors)[(int)sVar2].array;
    }
  } while (iVar3 * 0x10000 >> 0x10 < 0x10);
  return (long *)0x0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pvl_DeleteTexts()
 // line 2141, offset 0x8002c5ac
	/* begin block 1 */
		// Start line: 2142
		// Start offset: 0x8002C5AC
		// Variables:
	// 		short i; // $s0
	/* end block 1 */
	// End offset: 0x8002C614
	// End Line: 2151

	/* begin block 2 */
		// Start line: 4906
	/* end block 2 */
	// End Line: 4907

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pvl_DeleteTexts(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = 0;
  do {
    if ((&Pvl_TxtSectors)[iVar1 >> 0x10].array != (long *)0x0) {
      Heap_FreeMem((&Pvl_TxtSectors)[iVar1 >> 0x10].array);
    }
    iVar2 = iVar2 + 1;
    iVar1 = iVar2 * 0x10000;
  } while (iVar2 * 0x10000 >> 0x10 < 0x10);
  Heap_FreeMem(Pvl_Txt);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Pvl_SaveGame(struct _PLAYER *pl /*$s6*/, long entry /*$fp*/, long channel /*stack 8*/, long n /*$s7*/, long flevel /*stack 16*/)
 // line 2276, offset 0x8002c634
	/* begin block 1 */
		// Start line: 2277
		// Start offset: 0x8002C634
		// Variables:
	// 		struct _PVL_SAVEGAME *g; // $s5
	// 		struct PVL_70fake shp; // stack offset -80
	// 		char name[20]; // stack offset -64
	// 		short i; // $a3
	// 		short j; // $t0
	// 		long result; // $s0
	/* end block 1 */
	// End offset: 0x8002CE2C
	// End Line: 2463

	/* begin block 2 */
		// Start line: 5186
	/* end block 2 */
	// End Line: 5187

long Pvl_SaveGame(_PLAYER *pl,long entry,long channel,long n,long flevel)

{
  uchar uVar1;
  short sVar2;
  short sVar3;
  long lVar4;
  short sVar5;
  ushort uVar6;
  ushort uVar7;
  ushort uVar8;
  ushort uVar9;
  ushort uVar10;
  ushort uVar11;
  ushort uVar12;
  ushort uVar13;
  ushort uVar14;
  _CARD_HEADER *h;
  int iVar15;
  int iVar16;
  long lVar17;
  char *pcVar18;
  short sVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  CARD_68fake local_50;
  char local_40;
  char local_3f;
  char local_3e;
  char local_3d;
  char local_3c;
  undefined local_3b;
  
  Pvl_SaveMonsters();
  h = (_CARD_HEADER *)Heap_AllocMem(0x1f00);
  uVar14 = PJOY_ESQUIVE;
  uVar13 = PJOY_STRAFE;
  uVar12 = PJOY_SPELL;
  uVar11 = PJOY_SHOT;
  uVar10 = PJOY_JUMP;
  uVar9 = PJOY_BOMB;
  uVar8 = PJOY_AIM;
  uVar7 = PJOY_RIGHTHAND;
  uVar6 = Pvl_Prisoner_Status;
  sVar5 = Pvl_Difficulty;
  lVar4 = Pvl_LevelTime;
  sVar3 = Pvl_ScrY;
  sVar2 = Pvl_ScrX;
  lVar17 = Pvl_GameTime;
  sVar19 = Pvl_Movies;
  uVar1 = Sound_Mode;
  *(short *)(h[1].name + 0x2c) = Main_Param.PadConfig;
  *(long *)(h + 1) = lVar17;
  *(long *)h[1].name = lVar4;
  *(short *)(h[1].name + 4) = sVar19;
  *(short *)(h[1].name + 6) = sVar5;
  *(ushort *)(h[1].name + 8) = uVar6;
  *(ushort *)(h[1].name + 10) = uVar11;
  *(ushort *)(h[1].name + 0xc) = uVar10;
  *(ushort *)(h[1].name + 0xe) = uVar14;
  *(ushort *)(h[1].name + 0x10) = uVar9;
  *(ushort *)(h[1].name + 0x12) = uVar7;
  *(ushort *)(h[1].name + 0x14) = uVar13;
  *(ushort *)(h[1].name + 0x16) = uVar8;
  *(ushort *)(h[1].name + 0x18) = uVar12;
  *(ushort *)(h[1].name + 0x20) = (ushort)uVar1;
  *(short *)(h[1].name + 0x22) = (short)flevel;
  *(short *)(h[1].name + 0x1a) = sVar2;
  *(short *)(h[1].name + 0x1c) = sVar3;
  h[1].name[0x1e] = Sound_MasterVol;
  h[1].name[0x1f] = Sound_CdVol;
  sVar3 = Pvl_nMonsters;
  sVar2 = Pvl_nGaz;
  sVar19 = Pvl_nSecrets;
  *(short *)(h[1].name + 0x24) = Pvl_nItems;
  *(short *)(h[1].name + 0x26) = sVar3;
  *(short *)(h[1].name + 0x28) = sVar2;
  *(short *)(h[1].name + 0x2a) = sVar19;
  if (flevel != 0) {
    Invent_ReleaseLocalObjects();
  }
  *(short *)(h[9].icons + 0x4c) = Pvl_PlayerNumber;
  *(ulong *)(h[9].icons + 0x54) = (pl->env2).Obj.n_vert;
  *(undefined4 *)(h[9].icons + 0x58) = *(undefined4 *)&(pl->env2).Obj.normal_top;
  *(undefined4 *)(h[9].icons + 0x5c) = *(undefined4 *)&(pl->env2).Obj.normal_top.vz;
  h[9].icons[100] = (pl->env2).Obj.primitive_top.Data[4];
  h[9].icons[0x65] = (pl->env2).Obj.primitive_top.Data[5];
  *(undefined2 *)(h[9].icons + 0x66) = *(undefined2 *)((pl->env2).Obj.primitive_top.Data + 6);
  *(short *)(h[9].icons + 0x4e) = (pl->obj).hit_points;
  *(short *)(h[9].icons + 0x50) = (pl->m_obj).shadow.y2;
  *(undefined2 *)(h[9].icons + 0x52) = *(undefined2 *)&(pl->m_obj).shadow.u2;
  *(undefined2 *)(h[9].icons + 0x68) = *(undefined2 *)((pl->env2).Obj.primitive_top.Data + 8);
  *(undefined2 *)(h[9].icons + 0x6a) = *(undefined2 *)((pl->env2).Obj.primitive_top.Data + 0xc);
  *(undefined2 *)(h[9].icons + 0x6c) = *(undefined2 *)((pl->env2).Obj.primitive_top.Data + 0xe);
  *(undefined2 *)(h[9].icons + 0x6e) = *(undefined2 *)((pl->env2).Obj.primitive_top.Data + 0x10);
  *(undefined2 *)(h[9].icons + 0x70) = *(undefined2 *)((pl->env2).Obj.primitive_top.Data + 0x12);
  *(undefined2 *)(h[9].icons + 0x72) = *(undefined2 *)((pl->env2).Obj.primitive_top.Data + 0x14);
  *(undefined2 *)(h[9].icons + 0x74) = *(undefined2 *)((pl->env2).Obj.primitive_top.Data + 0x16);
  *(undefined2 *)(h[9].icons + 0x76) = *(undefined2 *)((pl->env2).Obj.primitive_top.Data + 0x18);
  *(undefined2 *)(h[9].icons + 0x78) = *(undefined2 *)((pl->env2).Obj.primitive_top.Data + 0x1a);
  *(undefined2 *)(h[9].icons + 0x7a) = *(undefined2 *)((pl->env2).Obj.primitive_top.Data + 0x1c);
  *(undefined2 *)(h[9].icons + 0x7c) = *(undefined2 *)((pl->env2).Obj.primitive_top.Data + 0x1e);
  *(undefined2 *)(h[9].icons + 0x7e) = *(undefined2 *)((pl->env2).Obj.primitive_top.Data + 0x20);
  *(short *)(h[9].icons + 0x80) = (short)(char)(pl->env1).Obj.primitive_top.Data[0x19];
  *(short *)(h[9].icons + 0x82) = (short)(char)(pl->env1).Obj.primitive_top.Data[0x18];
  iVar22 = 0;
  *(undefined2 *)(h[9].icons + 0xb4) = *(undefined2 *)((pl->env2).Obj.primitive_top.Data + 0x22);
  *(long *)(h[9].icons + 0xb8) = Inventaire.spells_invisible;
  do {
    iVar20 = iVar22 << 0x10;
    iVar22 = iVar22 + 1;
    iVar20 = iVar20 >> 0xe;
    *(undefined4 *)(&DAT_00001360 + (int)(h->magic + iVar20)) =
         *(undefined4 *)((int)Inventaire.spells_levels + iVar20);
  } while (iVar22 * 0x10000 >> 0x10 < 2);
  iVar22 = 0;
  do {
    sVar19 = (short)iVar22;
    iVar22 = iVar22 + 1;
    (&DAT_00001304)[(int)(h->magic + (int)sVar19)] =
         *(undefined *)((int)&(pl->env2).Obj.n_normal + (int)sVar19);
  } while (iVar22 * 0x10000 >> 0x10 < 4);
  iVar20 = 0;
  iVar22 = 0;
  do {
    iVar15 = (int)&(pl->obj).next + (iVar22 >> 0xd);
    uVar24 = *(undefined4 *)(iVar15 + 0x1ae);
    *(undefined4 *)(&DAT_00001328 + (int)(h->magic + (iVar22 >> 0xd))) =
         *(undefined4 *)(iVar15 + 0x1aa);
    *(undefined4 *)(&DAT_0000132c + (int)(h->magic + (iVar22 >> 0xd))) = uVar24;
    iVar20 = iVar20 + 1;
    iVar22 = iVar20 * 0x10000;
  } while (iVar20 * 0x10000 >> 0x10 < 6);
  iVar22 = 0;
  iVar20 = 0;
  do {
    iVar20 = iVar20 >> 0x10;
    (&DAT_00001368)[(int)(h->magic + iVar20)] = (pl->env2).Obj.primitive_top.Data[iVar20 + 0x24];
    iVar21 = iVar20 * 0xb0;
    pcVar18 = h->magic + iVar20 * 0xc;
    pcVar18[0x138c] = *(char *)((int)Pvl_TakenObjects + iVar21 + 0xa4);
    pcVar18[0x138d] = *(char *)((int)Pvl_TakenObjects + iVar21 + 0xa5);
    *(undefined2 *)(pcVar18 + 5000) = *(undefined2 *)((int)Pvl_TakenObjects + iVar21 + 0xac);
    *(undefined2 *)(pcVar18 + 0x1390) = *(undefined2 *)((int)Pvl_TakenObjects + iVar21 + 0xa6);
    *(undefined2 *)(pcVar18 + 0x1392) = *(undefined2 *)((int)Pvl_TakenObjects + iVar21 + 0xa8);
    *(undefined2 *)(pcVar18 + 0x138e) = *(undefined2 *)((int)Pvl_TakenObjects + iVar21 + 0xaa);
    pcVar18 = h->magic + iVar20 * 0x4c;
    *(undefined2 *)(pcVar18 + 0x1508) = *(undefined2 *)((int)Pvl_TakenObjects + iVar21 + 0x1a);
    *(undefined2 *)(pcVar18 + 0x150a) = *(undefined2 *)((int)Pvl_TakenObjects + iVar21 + 0x9e);
    uVar24 = *(undefined4 *)((int)Pvl_TakenObjects + iVar21 + 0x30);
    *(undefined4 *)(pcVar18 + 0x150c) = *(undefined4 *)((int)Pvl_TakenObjects + iVar21 + 0x2c);
    *(undefined4 *)(pcVar18 + 0x1510) = uVar24;
    iVar23 = 0;
    *(undefined2 *)(pcVar18 + 0x1512) = *(undefined2 *)((int)Pvl_TakenObjects + iVar21 + 0x9c);
    iVar15 = 0;
    do {
      iVar16 = (iVar15 >> 0xd) + iVar21;
      uVar24 = *(undefined4 *)((int)Pvl_TakenObjects + iVar16 + 0x50);
      *(undefined4 *)(&DAT_00001514 + (int)(h->magic + (iVar15 >> 0xd) + iVar20 * 0x4c)) =
           *(undefined4 *)((int)Pvl_TakenObjects + iVar16 + 0x4c);
      *(undefined4 *)(&DAT_00001518 + (int)(h->magic + (iVar15 >> 0xd) + iVar20 * 0x4c)) = uVar24;
      lVar4 = Scts_Interruptors;
      sVar3 = Pvl_CheckPtSector;
      sVar2 = Pvl_SectorNumber;
      lVar17 = Pvl_CheckPtEntry;
      sVar19 = Pvl_LevelNumber;
      iVar23 = iVar23 + 1;
      iVar15 = iVar23 * 0x10000;
    } while (iVar23 * 0x10000 >> 0x10 < 8);
    iVar22 = iVar22 + 1;
    iVar20 = iVar22 * 0x10000;
  } while (iVar22 * 0x10000 >> 0x10 < 0x20);
  iVar22 = 0;
  *(long *)(h[1].name + 0x38) = entry;
  *(short *)(h[1].name + 0x30) = sVar19;
  *(short *)(h[1].name + 0x32) = sVar2;
  *(long *)(h[1].name + 0x3c) = lVar17;
  *(short *)h[1].pad = sVar3;
  *(long *)(h[1].name + 0x34) = lVar4;
  do {
    sVar19 = (short)iVar22;
    iVar22 = iVar22 + 1;
    h[1].pad[(int)sVar19 + 4] = (&Scts_States)[(int)sVar19];
  } while (iVar22 * 0x10000 >> 0x10 < 0x780);
  iVar22 = 0;
  do {
    iVar20 = iVar22 << 0x10;
    iVar22 = iVar22 + 1;
    iVar20 = iVar20 >> 0xe;
    *(undefined4 *)(h[4].icons + iVar20 + 0x13c) = *(undefined4 *)((int)&Scts_Zones + iVar20);
  } while (iVar22 * 0x10000 >> 0x10 < 0x3c);
  iVar20 = 0;
  iVar22 = 0;
  do {
    iVar22 = iVar22 >> 0xd;
    uVar24 = *(undefined4 *)((int)&DAT_800b0b9c + iVar22);
    *(undefined4 *)(h->magic + iVar22 + 0xabc) = *(undefined4 *)((int)&Scts_Monsters + iVar22);
    *(undefined4 *)(h->magic + iVar22 + 0xac0) = uVar24;
    iVar20 = iVar20 + 1;
    iVar22 = iVar20 * 0x10000;
  } while (iVar20 * 0x10000 >> 0x10 < 0xf0);
  iVar22 = 0;
  iVar20 = 0;
  do {
    iVar20 = iVar20 >> 0x10;
    pcVar18 = h->magic + iVar20 * 0xc;
    uVar24 = *(undefined4 *)(&DAT_800b131c + iVar20 * 6);
    uVar25 = *(undefined4 *)(&DAT_800b1320 + iVar20 * 6);
    *(undefined4 *)(pcVar18 + 0x123c) = *(undefined4 *)(&Scts_Crcs + iVar20 * 6);
    *(undefined4 *)(pcVar18 + 0x1240) = uVar24;
    *(undefined4 *)(pcVar18 + 0x1244) = uVar25;
    iVar22 = iVar22 + 1;
    iVar20 = iVar22 * 0x10000;
  } while (iVar22 * 0x10000 >> 0x10 < 0xf);
  local_50.shape = 1;
  local_50.file = Pl_Pcl;
  Card_SetIcons(h,1,&local_50);
  iVar22 = (int)Scr_TicksPerSecond;
  if (iVar22 == 0) {
    trap(0x1c00);
  }
  if ((iVar22 == -1) && (Pvl_GameTime == -0x80000000)) {
    trap(0x1800);
  }
  iVar22 = Pvl_GameTime / iVar22 << 0x10;
  iVar20 = iVar22 >> 0x10;
  iVar22 = ((iVar20 / 0x3c + (iVar20 >> 0x1f)) - (iVar22 >> 0x1f)) * 0x10000;
  iVar20 = iVar22 >> 0x10;
  iVar22 = (iVar20 / 0x3c + (iVar20 >> 0x1f)) - (iVar22 >> 0x1f);
  sprintf(&local_40,s_O_D_T____s__d__03d__02d__02d__800ad414,Pl_Names6[(int)Pvl_PlayerNumber],
          (int)Pvl_LevelNumber,n,iVar22 * 0x10000 >> 0x10,
          (iVar20 + iVar22 * -0x3c) * 0x10000 >> 0x10);
  Card_SetName(h,&local_40);
  local_3b = 0;
  local_40 = (char)Pvl_PlayerNumber + 'A';
  local_3f = (char)Pvl_LevelNumber + 'A';
  local_3e = (char)(n / 100) + '0';
  local_3c = (char)n + (char)(n / 10) * -10 + '0';
  local_3d = (char)((n % 100) / 10) + '0';
  lVar17 = Card_WriteFile(channel,&local_40,h,0x1f00);
  Heap_FreeMem(h);
  if (lVar17 == 0) {
    Pvl_CheckPoint(entry,1);
  }
  return lVar17;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Pvl_LoadGame(struct _PLAYER *pl /*$s3*/, short channel /*$a1*/, char *name /*$s1*/)
 // line 2467, offset 0x8002ce60
	/* begin block 1 */
		// Start line: 2468
		// Start offset: 0x8002CE60
		// Variables:
	// 		struct _PVL_SAVEGAME *g; // $s2
	// 		long result; // $s4
	// 		long i; // $a0
	// 		long j; // $t0
	// 		long flevel; // $t6
	/* end block 1 */
	// End offset: 0x8002D3B8
	// End Line: 2613

	/* begin block 2 */
		// Start line: 5724
	/* end block 2 */
	// End Line: 5725

long Pvl_LoadGame(_PLAYER *pl,short channel,char *name)

{
  short sVar1;
  _CARD_HEADER *h;
  long lVar2;
  _INVENTAIRE *p_Var3;
  _PLAYER *p_Var4;
  char *pcVar5;
  _CARD_HEADER *p_Var6;
  int iVar7;
  int iVar8;
  int iVar9;
  long *plVar10;
  undefined4 *puVar11;
  int iVar12;
  _TAKEN_OBJECT *p_Var13;
  int iVar14;
  _CARD_HEADER *p_Var15;
  int iVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  
  h = (_CARD_HEADER *)Heap_AllocMem(0x1f00);
  lVar2 = Card_ReadFile((int)channel,name,h,0x1f00);
  if (lVar2 == 0) {
    Main_Param.PadConfig = *(short *)(h[1].name + 0x2c);
    Pvl_GameTime = *(long *)(h + 1);
    Pvl_LevelTime = *(long *)h[1].name;
    Pvl_Movies = *(short *)(h[1].name + 4);
    Pvl_ScrX = *(short *)(h[1].name + 0x1a);
    Pvl_ScrY = *(short *)(h[1].name + 0x1c);
    Pvl_Difficulty = *(short *)(h[1].name + 6);
    Pvl_Prisoner_Status = *(ushort *)(h[1].name + 8);
    Pvl_nItems = *(short *)(h[1].name + 0x24);
    Pvl_nMonsters = *(short *)(h[1].name + 0x26);
    Pvl_nGaz = *(short *)(h[1].name + 0x28);
    Pvl_nSecrets = *(short *)(h[1].name + 0x2a);
    PJOY_SHOT = *(ushort *)(h[1].name + 10);
    PJOY_JUMP = *(ushort *)(h[1].name + 0xc);
    PJOY_ESQUIVE = *(ushort *)(h[1].name + 0xe);
    PJOY_BOMB = *(ushort *)(h[1].name + 0x10);
    PJOY_RIGHTHAND = *(ushort *)(h[1].name + 0x12);
    PJOY_STRAFE = *(ushort *)(h[1].name + 0x14);
    PJOY_AIM = *(ushort *)(h[1].name + 0x16);
    PJOY_SPELL = *(ushort *)(h[1].name + 0x18);
    sVar1 = *(short *)(h[1].name + 0x22);
    Sound_Mode = h[1].name[0x20];
    Pvl_PlayerNumber = *(short *)(h[9].icons + 0x4c);
    Sound_MasterVol = h[1].name[0x1e];
    Sound_CdVol = h[1].name[0x1f];
    (pl->env2).Obj.n_vert = *(ulong *)(h[9].icons + 0x54);
    *(undefined4 *)&(pl->env2).Obj.normal_top = *(undefined4 *)(h[9].icons + 0x58);
    *(undefined4 *)&(pl->env2).Obj.normal_top.vz = *(undefined4 *)(h[9].icons + 0x5c);
    (pl->env2).Obj.primitive_top.Data[4] = h[9].icons[100];
    (pl->env2).Obj.primitive_top.Data[5] = h[9].icons[0x65];
    *(undefined2 *)((pl->env2).Obj.primitive_top.Data + 6) = *(undefined2 *)(h[9].icons + 0x66);
    (pl->obj).hit_points = *(short *)(h[9].icons + 0x4e);
    (pl->m_obj).shadow.y2 = *(short *)(h[9].icons + 0x50);
    *(undefined2 *)&(pl->m_obj).shadow.u2 = *(undefined2 *)(h[9].icons + 0x52);
    *(undefined2 *)((pl->env2).Obj.primitive_top.Data + 8) = *(undefined2 *)(h[9].icons + 0x68);
    *(undefined2 *)((pl->env2).Obj.primitive_top.Data + 0xc) = *(undefined2 *)(h[9].icons + 0x6a);
    *(undefined2 *)((pl->env2).Obj.primitive_top.Data + 0xe) = *(undefined2 *)(h[9].icons + 0x6c);
    *(undefined2 *)((pl->env2).Obj.primitive_top.Data + 0x10) = *(undefined2 *)(h[9].icons + 0x6e);
    *(undefined2 *)((pl->env2).Obj.primitive_top.Data + 0x12) = *(undefined2 *)(h[9].icons + 0x70);
    *(undefined2 *)((pl->env2).Obj.primitive_top.Data + 0x14) = *(undefined2 *)(h[9].icons + 0x72);
    *(undefined2 *)((pl->env2).Obj.primitive_top.Data + 0x16) = *(undefined2 *)(h[9].icons + 0x74);
    *(undefined2 *)((pl->env2).Obj.primitive_top.Data + 0x18) = *(undefined2 *)(h[9].icons + 0x76);
    *(undefined2 *)((pl->env2).Obj.primitive_top.Data + 0x1a) = *(undefined2 *)(h[9].icons + 0x78);
    *(undefined2 *)((pl->env2).Obj.primitive_top.Data + 0x1c) = *(undefined2 *)(h[9].icons + 0x7a);
    *(undefined2 *)((pl->env2).Obj.primitive_top.Data + 0x1e) = *(undefined2 *)(h[9].icons + 0x7c);
    *(undefined2 *)((pl->env2).Obj.primitive_top.Data + 0x20) = *(undefined2 *)(h[9].icons + 0x7e);
    (pl->env1).Obj.primitive_top.Data[0x19] = h[9].icons[0x80];
    (pl->env1).Obj.primitive_top.Data[0x18] = h[9].icons[0x82];
    p_Var3 = &Inventaire;
    *(undefined2 *)((pl->env2).Obj.primitive_top.Data + 0x22) = *(undefined2 *)(h[9].icons + 0xb4);
    Inventaire.spells_invisible = *(long *)(h[9].icons + 0xb8);
    iVar7 = 0;
    p_Var6 = h;
    do {
      p_Var15 = p_Var6 + 9;
      p_Var6 = (_CARD_HEADER *)p_Var6->name;
      iVar7 = iVar7 + 1;
      p_Var3->spells_levels[0] = *(long *)(p_Var15->icons + 0xbc);
      p_Var3 = (_INVENTAIRE *)&p_Var3->helpx;
    } while (iVar7 < 2);
    iVar7 = 0;
    do {
      iVar8 = iVar7 + 1;
      *(undefined *)((int)&(pl->env2).Obj.n_normal + iVar7) =
           (&DAT_00001304)[(int)(h->magic + iVar7)];
      iVar7 = iVar8;
    } while (iVar8 < 4);
    iVar7 = 0;
    p_Var4 = pl;
    p_Var6 = h;
    do {
      uVar17 = *(undefined4 *)(p_Var6[9].icons + 0x88);
      *(undefined4 *)((p_Var4->env1).Obj.primitive_top.Data + 0x1a) =
           *(undefined4 *)(p_Var6[9].icons + 0x84);
      *(undefined4 *)((p_Var4->env1).Obj.primitive_top.Data + 0x1e) = uVar17;
      p_Var6 = (_CARD_HEADER *)(p_Var6->name + 4);
      iVar7 = iVar7 + 1;
      p_Var4 = (_PLAYER *)&(p_Var4->obj).child;
    } while (iVar7 < 6);
    iVar7 = 0;
    iVar16 = 0;
    iVar8 = 0;
    p_Var13 = Pvl_TakenObjects;
    p_Var6 = h;
    p_Var15 = h;
    do {
      (pl->env2).Obj.primitive_top.Data[iVar7 + 0x24] = (&DAT_00001368)[(int)(h->magic + iVar7)];
      *(char *)&p_Var13[1].obj.pos.vx = p_Var6[9].icons[0xe8];
      *(char *)((int)&p_Var13[1].obj.pos.vx + 1) = p_Var6[9].icons[0xe9];
      p_Var13[1].obj.last_pos.vx = *(short *)(p_Var6[9].icons + 0xe4);
      p_Var13[1].obj.pos.vy = *(short *)(p_Var6[9].icons + 0xec);
      p_Var13[1].obj.pos.vz = *(short *)(p_Var6[9].icons + 0xee);
      p_Var13[1].obj.pos.pad = *(short *)(p_Var6[9].icons + 0xea);
      iVar14 = 0;
      (p_Var13->obj).display_mode = *(short *)(p_Var15[10].icons + 0x60);
      *(undefined2 *)((int)&p_Var13[1].obj.description + 2) =
           *(undefined2 *)(p_Var15[10].icons + 0x62);
      uVar17 = *(undefined4 *)(p_Var15[10].icons + 0x68);
      *(undefined4 *)&(p_Var13->obj).pos = *(undefined4 *)(p_Var15[10].icons + 100);
      *(undefined4 *)&(p_Var13->obj).pos.vz = uVar17;
      *(undefined2 *)&p_Var13[1].obj.description = *(undefined2 *)(p_Var15[10].icons + 0x6a);
      iVar9 = iVar8;
      iVar12 = iVar16;
      do {
        uVar17 = *(undefined4 *)(&DAT_00001518 + (int)(h->magic + iVar12));
        *(undefined4 *)((int)&Pvl_TakenObjects[0].obj.b_box.vx + iVar9) =
             *(undefined4 *)(&DAT_00001514 + (int)(h->magic + iVar12));
        *(undefined4 *)((int)&Pvl_TakenObjects[0].obj.b_box.vz + iVar9) = uVar17;
        iVar12 = iVar12 + 8;
        iVar14 = iVar14 + 1;
        iVar9 = iVar9 + 8;
      } while (iVar14 < 8);
      iVar16 = iVar16 + 0x4c;
      iVar8 = iVar8 + 0xb0;
      p_Var15 = (_CARD_HEADER *)(p_Var15->pad + 8);
      p_Var6 = (_CARD_HEADER *)(p_Var6->name + 8);
      iVar7 = iVar7 + 1;
      p_Var13 = (_TAKEN_OBJECT *)&p_Var13[1].obj.last_pos.vz;
    } while (iVar7 < 0x20);
    Pvl_LevelNumber = *(short *)(h[1].name + 0x30);
    Pvl_SectorNumber = *(short *)(h[1].name + 0x32);
    Pvl_CheckPtEntry = *(long *)(h[1].name + 0x3c);
    Pvl_CheckPtSector = *(short *)h[1].pad;
    if (sVar1 == 0) {
      Scts_Interruptors = *(long *)(h[1].name + 0x34);
      pcVar5 = &Scts_States;
      iVar7 = 0;
      do {
        iVar8 = iVar7 + 1;
        *pcVar5 = h[1].pad[iVar7 + 4];
        pcVar5 = s_______800b0329 + iVar7;
        iVar7 = iVar8;
      } while (iVar8 < 0x780);
      iVar7 = 0;
      plVar10 = &Scts_Zones;
      p_Var6 = h;
      do {
        p_Var15 = p_Var6 + 4;
        p_Var6 = (_CARD_HEADER *)p_Var6->name;
        iVar7 = iVar7 + 1;
        *plVar10 = *(long *)(p_Var15->icons + 0x13c);
        plVar10 = plVar10 + 1;
      } while (iVar7 < 0x3c);
      iVar7 = 0;
      puVar11 = &Scts_Monsters;
      p_Var6 = h;
      do {
        uVar17 = *(undefined4 *)(p_Var6[5].icons + 0x2c);
        *puVar11 = *(undefined4 *)(p_Var6[5].icons + 0x28);
        puVar11[1] = uVar17;
        puVar11 = puVar11 + 2;
        iVar7 = iVar7 + 1;
        p_Var6 = (_CARD_HEADER *)(p_Var6->name + 4);
      } while (iVar7 < 0xf0);
      iVar7 = 0;
      puVar11 = (undefined4 *)&Scts_Crcs;
      p_Var6 = h;
      do {
        uVar17 = *(undefined4 *)(p_Var6[9].name + 0x18);
        uVar18 = *(undefined4 *)(p_Var6[9].name + 0x1c);
        *puVar11 = *(undefined4 *)(p_Var6[9].name + 0x14);
        puVar11[1] = uVar17;
        puVar11[2] = uVar18;
        puVar11 = puVar11 + 3;
        iVar7 = iVar7 + 1;
        p_Var6 = (_CARD_HEADER *)(p_Var6->name + 8);
      } while (iVar7 < 0xf);
    }
    else {
      Pvl_ClearSctState();
    }
    Pvl_LoadedGame = *(long *)(h[1].name + 0x38);
    Pvl_CheckPoint(Pvl_LoadedGame,0);
  }
  Heap_FreeMem(h);
  return lVar2;
}





