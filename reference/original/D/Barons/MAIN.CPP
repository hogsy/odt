#include "THISDUST.H"
#include "MAIN.H"


// decompiled code
// original method signature: 
// long /*$ra*/ main(long argc /*$a0*/, long *argv /*$s0*/)
 // line 48, offset 0x80019a68
	/* begin block 1 */
		// Start line: 49
		// Start offset: 0x80019A68
		// Variables:
	// 		long mode; // $a2
	// 		long datrack; // $v0
	// 		long sector; // $v1
	// 		char text[256]; // stack offset -264
	/* end block 1 */
	// End offset: 0x80019A68
	// End Line: 49

	/* begin block 2 */
		// Start line: 96
	/* end block 2 */
	// End Line: 97

long main(long argc,long *argv)

{
  char acStack264 [256];
  
  __main();
  Main_TextContext.Font.ascii_tab._16_4_ = argv[1];
  sprintf(acStack264,s_ODT_start____Mode__d__Timeout__d_800ad22c,*argv,
          Main_TextContext.Font.ascii_tab._16_4_,argv[2],argv[3]);
  printf(acStack264);
  OS_Init(Main_Startup);
  printf(s_ODT_End_800ad268);
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Main_Startup()
 // line 126, offset 0x80019adc
	/* begin block 1 */
		// Start line: 127
		// Start offset: 0x80019ADC
		// Variables:
	// 		long Main_Trailer; // $s1
	/* end block 1 */
	// End offset: 0x80019E24
	// End Line: 355

	/* begin block 2 */
		// Start line: 261
	/* end block 2 */
	// End Line: 262

/* WARNING: Removing unreachable block (ram,0x80019c74) */
/* WARNING: Removing unreachable block (ram,0x80019cc0) */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Main_Startup(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  _PARAMETRE *p_Var5;
  
  Main_Param.firstlaunch = 1;
  Main_Param.showcredits = 0;
  Main_Param.PadConfig = 0;
  Main_Param.Difficulty = 1;
  Main_Param.Movies = 1;
  Main_Param.Sound3D = 2;
  Main_Param.SelectPerso = 0;
  Main_Param.hideinit[0] = 0;
  Main_Param.hideinit[1] = 1;
  Main_Param.hideinit[2] = 0;
  Main_Param.hideinit[3] = 1;
  Main_Param.hideinit[4] = 0;
  Main_Param.hideinit[5] = 0;
  Main_Param.ScreenX = Screens.disp.screen.x;
  Main_Param.ScreenY = Screens.disp.screen.y;
  Overlay_DisplayPicture(s_Legal_Legal_tim_800ad274,0x280,3);
  File_Exec(s_Movies_exe_800ad284,(long)&DAT_801ff800,-1,
            CONCAT22(Screens.disp.screen.x,Screens.disp.screen.y));
  p_Var5 = &Main_Param;
  OS_Remove();
  OS_Install(&DAT_800cb920);
  Overlay_DisplayPicture(s_Legal_Loading_tim_800ad290,0x280,3);
  File_Read(s_Rsc_Menu_bin_800ad2a4,Menu_Start);
  Main_Param.Controller = 0;
  Main_Param.Level = 0;
  Main_Param.Sector = 1;
  Main_Param.CardId = 0;
  Main_Param.GameType = 0;
  Main_Param.Sfx = (short)((int)((uint)Sound_MasterVol * 100) / 0xff);
  Main_Param.CD = (short)((int)((uint)Sound_CdVol * 100) / 0xff);
  Menu_Launch(&Main_Param);
  puVar1 = &DAT_800c9d40;
  do {
    uVar2 = puVar1[1];
    uVar3 = puVar1[2];
    uVar4 = puVar1[3];
    *(undefined4 *)p_Var5 = *puVar1;
    *(undefined4 *)&p_Var5->Sfx = uVar2;
    *(undefined4 *)&p_Var5->Master = uVar3;
    *(undefined4 *)&p_Var5->Movies = uVar4;
    puVar1 = puVar1 + 4;
    p_Var5 = (_PARAMETRE *)&p_Var5->Difficulty;
  } while (puVar1 != (undefined4 *)0x800c9dc0);
  *(undefined4 *)p_Var5 = uRam800c9dc0;
  if ((short)DAT_800c9d40 != 4) {
    Main_GetOptions();
    OS_Remove();
    OS_Install(&Heap_Start);
    Scr_InitZone(0,0,0x140,0x1e0,0);
    Scr_Swap();
    VSync(0);
    Scr_Clear();
    Scr_Swap();
    VSync(0);
    Scr_SetOtSize(600);
    Tmd_AllocMem(0x400);
    Text_AllocMem((long)&DAT_000032c8);
    Pvl_PlayGame();
    if (Pvl_Demo == 0) {
      Main_Param.ScreenX = Pvl_ScrX;
      Main_Param.ScreenY = Pvl_ScrY;
      Main_Param.Difficulty = Pvl_Difficulty;
      Main_Param.Movies = Pvl_Movies;
      Main_Param.Sound3D = ZEXT12(Sound_Mode);
    }
    Overlay_DisplayPicture(s_Legal_Feat1_tim_800ad2c8,0x280,(int)Scr_TicksPerSecond << 4);
    Overlay_DisplayPicture(s_Legal_Feat2_tim_800ad2d8,0x280,(int)Scr_TicksPerSecond << 4);
  }
  OS_Remove();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Main_GetOptions()
 // line 363, offset 0x80019e44
	/* begin block 1 */
		// Start line: 364
		// Start offset: 0x80019E44
		// Variables:
	// 		struct _PARAMETRE *p; // $s1
	// 		long i; // $v1
	/* end block 1 */
	// End offset: 0x8001A188
	// End Line: 558

	/* begin block 2 */
		// Start line: 870
	/* end block 2 */
	// End Line: 871

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Main_GetOptions(void)

{
  undefined4 *puVar1;
  short *psVar2;
  int iVar3;
  undefined4 *puVar4;
  
  puVar4 = &DAT_800c9d40;
  Pvl_Demo = 0;
  if ((short)DAT_800c9d40 == 2) {
    iVar3 = 5;
    psVar2 = &SHORT_800b3f1a;
    do {
      *psVar2 = -1;
      iVar3 = iVar3 + -1;
      psVar2 = psVar2 + -1;
    } while (-1 < iVar3);
  }
  else {
    if ((short)DAT_800c9d40 < 3) {
      if ((short)DAT_800c9d40 != 1) {
        Pvl_Demo = 0;
        return;
      }
    }
    else {
      if ((short)DAT_800c9d40 != 3) {
        if ((short)DAT_800c9d40 != 4) {
          Pvl_Demo = 0;
          return;
        }
        Pvl_ScrX = (short)DAT_800c9d54;
        Pvl_ScrY = DAT_800c9d54._2_2_;
        Pvl_Demo = 1;
        Pvl_Difficulty = 1;
        PJOY_RIGHTHAND = USHORT_800c6c00;
        PJOY_AIM = DAT_800c6c04;
        PJOY_BOMB = USHORT_800c6bfe;
        PJOY_JUMP = USHORT_800c6bfa;
        PJOY_SHOT = Menu_PadCfg;
        PJOY_SPELL = DAT_800c6c06;
        PJOY_STRAFE = DAT_800c6c02;
        PJOY_ESQUIVE = USHORT_800c6bfc;
        return;
      }
    }
    Pvl_SectorNumber = 1;
    _DAT_800b1e38 = 0x2300;
    _DAT_800b1e3a = 0x2300;
    _DAT_800b1e3c = 0x1900;
    _DAT_800b1e34 = 0x8000;
    Pvl_Difficulty = 0;
    Pvl_Movies = 0;
    Pvl_LevelNumber = 2;
    Pvl_PlayerNumber = 0;
    Pvl_ScrX = (short)DAT_800c9d54;
    Pvl_ScrY = DAT_800c9d54._2_2_;
    PJOY_SHOT = Menu_PadCfg;
    PJOY_JUMP = USHORT_800c6bfa;
    PJOY_ESQUIVE = USHORT_800c6bfc;
    PJOY_BOMB = USHORT_800c6bfe;
    PJOY_RIGHTHAND = USHORT_800c6c00;
    PJOY_STRAFE = DAT_800c6c02;
    PJOY_AIM = DAT_800c6c04;
    PJOY_SPELL = DAT_800c6c06;
    _DAT_800b1e44 = DAT_800c9d68;
    _DAT_800b1e48 = DAT_800c9d6a;
    _DAT_800b1e3e = DAT_800c9d66;
    DAT_800b1de4 = 3;
    DAT_800b1dec = 2;
    DAT_800b1df4 = 0;
    DAT_800b1dfc = 0;
    _DAT_800b1e14 = 0x825;
    _DAT_800b1e1c = 0;
    _DAT_800b1e18 = 0;
    _DAT_800b1e42 = DAT_800c9d6e;
    _DAT_800b1de8 = DAT_800c9d78;
    _DAT_800b1df0 = DAT_800c9d7a;
    _DAT_800b1df8 = DAT_800c9d7c;
    _DAT_800b1e40 = DAT_800c9d6c;
    _DAT_800b1e00 = DAT_800c9d7e;
    Pl_SetSpellLevel((_PLAYER *)&Player,0,1,(long *)0x0);
    iVar3 = 0;
    psVar2 = &Invent_Param;
    DAT_800b1e20 = 5;
    DAT_800b1e21 = 0xb;
    DAT_800b1e22 = 0;
    DAT_800b1e23 = 2;
    do {
      puVar1 = puVar4 + 0x10;
      puVar4 = (undefined4 *)((int)puVar4 + 2);
      iVar3 = iVar3 + 1;
      *psVar2 = *(short *)puVar1;
      psVar2 = psVar2 + 1;
    } while (iVar3 < 6);
  }
  return;
}





