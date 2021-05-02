#include "THISDUST.H"
#include "INGAME.H"


// decompiled code
// original method signature: 
// void /*$ra*/ InGame_Init()
 // line 171, offset 0x80081f38
	/* begin block 1 */
		// Start line: 173
		// Start offset: 0x80081F38
		// Variables:
	// 		long f; // $a0
	/* end block 1 */
	// End offset: 0x80081F78
	// End Line: 185

	/* begin block 2 */
		// Start line: 346
	/* end block 2 */
	// End Line: 347

/* WARNING: Unknown calling convention yet parameter storage is locked */

void InGame_Init(void)

{
  INGAME_45fake *pIVar1;
  int iVar2;
  
  iVar2 = 0;
  pIVar1 = InGame_Tiles;
  do {
    *(undefined *)((int)&pIVar1->tag + 3) = 3;
    pIVar1->code = '`';
    pIVar1->r0 = -0x40;
    pIVar1->g0 = '@';
    pIVar1->b0 = '@';
    iVar2 = iVar2 + 1;
    pIVar1 = pIVar1 + 1;
  } while (iVar2 < 2);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ InGame_Confirm(short Title /*$a0*/)
 // line 189, offset 0x80081f80
	/* begin block 1 */
		// Start line: 190
		// Start offset: 0x80081F80
		// Variables:
	// 		long c; // $s0
	/* end block 1 */
	// End offset: 0x80081F80
	// End Line: 190

	/* begin block 2 */
		// Start line: 382
	/* end block 2 */
	// End Line: 383

long InGame_Confirm(short Title)

{
  long lVar1;
  
  InGame_MenuAlloc(1);
  InGame_MenuClear();
  InGame_MenuTitle((char *)Pvl_UtilityTexts[0x31]);
  InGame_MenuOption((char *)Pvl_UtilityTexts[0x45],'!');
  InGame_MenuOption((char *)Pvl_UtilityTexts[0x46],'\"');
  InGame_MenuExec(1,-1);
  lVar1 = InGame_MenuWait();
  InGame_MenuFree();
  return (uint)(lVar1 == 0x21);
}



// decompiled code
// original method signature: 
// void /*$ra*/ InGame_Pause()
 // line 223, offset 0x80082018
	/* begin block 1 */
		// Start line: 224
		// Start offset: 0x80082018
		// Variables:
	// 		long c; // $s1
	// 		struct TASK *t; // $s2
	// 		long bMenu; // $s0
	/* end block 1 */
	// End offset: 0x80082144
	// End Line: 333

	/* begin block 2 */
		// Start line: 453
	/* end block 2 */
	// End Line: 454

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void InGame_Pause(void)

{
  bool bVar1;
  TASK *t;
  long lVar2;
  long def_opt;
  
  Task_Next();
  Fx_PlayInPause(0x3f,100);
  t = Task_Link(InGame_CheatTask,0x100);
  def_opt = 0;
  do {
    InGame_MenuAlloc(1);
    bVar1 = false;
    InGame_MenuClear();
    InGame_MenuTitle((char *)Pvl_UtilityTexts[0x2c]);
    InGame_MenuOption((char *)Pvl_UtilityTexts[0x2e],'\"');
    InGame_MenuOption((char *)Pvl_UtilityTexts[0x2f],'%');
    InGame_MenuOption((char *)Pvl_UtilityTexts[0x30],'#');
    InGame_MenuExec(def_opt,-2);
    def_opt = InGame_MenuWait();
    InGame_MenuFree();
    if (def_opt == 0x23) {
      def_opt = 0;
      lVar2 = InGame_Confirm(0);
      bVar1 = true;
      if (lVar2 != 0) {
        bVar1 = false;
        Pvl_AbortGame();
      }
    }
    else {
      if (def_opt == 0x25) {
        def_opt = 1;
        lVar2 = InGame_LoadGame();
        bVar1 = lVar2 == 0;
      }
    }
  } while ((bVar1) && ((_DAT_800b1c56 & 8) == 0));
  Task_Kill(t);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ InGame_CheatTask()
 // line 338, offset 0x80082164
	/* begin block 1 */
		// Start line: 339
		// Start offset: 0x80082164
		// Variables:
	// 		long i; // $s1
	// 		long j; // $s0
	// 		long k; // $a2
	// 		long c; // $s2
	// 		long n; // $s3
	// 		unsigned short t; // $s7
	/* end block 1 */
	// End offset: 0x80082534
	// End Line: 469

	/* begin block 2 */
		// Start line: 688
	/* end block 2 */
	// End Line: 689

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void InGame_CheatTask(void)

{
  ushort uVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  long lVar6;
  ushort *puVar7;
  undefined *puVar8;
  int iVar9;
  int spell;
  int iVar10;
  
  iVar10 = 0;
  if (InGame_Cheats != 0) {
    iVar3 = 0;
    do {
      uVar1 = *(ushort *)((int)&InGame_Cheats + iVar3);
      (&InGame_Cheats)[iVar10 + 1] = 0;
      iVar10 = iVar10 + 2 + (uint)uVar1;
      iVar3 = iVar10 * 2;
    } while ((&InGame_Cheats)[iVar10] != 0);
  }
  do {
    uVar4 = Joy_ReadTrig(0);
    if ((uVar4 & 0xffff) != 0) {
      iVar10 = 0;
      iVar3 = 0;
      uVar1 = InGame_Cheats;
      while (uVar1 != 0) {
        puVar7 = &InGame_Cheats + iVar10 + 1;
        uVar1 = (&InGame_Cheats)[iVar10];
        uVar5 = (uint)*puVar7 + 1;
        if ((uVar4 & 0xffff) == (uint)(&InGame_Cheats)[iVar10 + (uint)*puVar7 + 2]) {
          *puVar7 = (ushort)uVar5;
          if ((uVar5 & 0xffff) == (uint)uVar1) {
            *puVar7 = 0;
            Fx_PlayInPause(0x3b,0);
            switch(iVar3) {
            case 0:
              _DAT_800b1c58 = 100;
              Task_EventExec(Overlay_Handle,Overlay_Handle->event_msg | 4,
                             Overlay_Handle->event_param);
              break;
            case 1:
              _DAT_800b1e36 = 100;
              Task_EventExec(Overlay_Handle,Overlay_Handle->event_msg | 0x10,
                             Overlay_Handle->event_param);
              break;
            case 2:
              iVar9 = 3;
              spell = -0x7ff4e3b0;
              do {
                *(undefined2 *)(spell + 0x1aa) = 100;
                iVar9 = iVar9 + -1;
                spell = spell + -8;
              } while (-1 < iVar9);
              Task_EventExec(Overlay_Handle,Overlay_Handle->event_msg | 0x88,
                             Overlay_Handle->event_param);
              break;
            case 3:
              spell = 0;
              puVar8 = &Player;
              do {
                cVar2 = puVar8[0x1ac] + '\x01';
                if (9 < (int)(char)puVar8[0x1ac] + 1) {
                  cVar2 = '\t';
                }
                puVar8[0x1ac] = cVar2;
                spell = spell + 1;
                puVar8 = puVar8 + 8;
              } while (spell < 4);
              break;
            case 4:
              uVar5 = (uint)_DAT_800b1e38;
              _DAT_800b1e38 = 0x6400;
              if (uVar5 + 0xa00 < 0x6401) {
                _DAT_800b1e38 = (ushort)(uVar5 + 0xa00);
              }
              uVar5 = (uint)_DAT_800b1e3a;
              _DAT_800b1e3a = 0x6400;
              if (uVar5 + 0xa00 < 0x6401) {
                _DAT_800b1e3a = (ushort)(uVar5 + 0xa00);
              }
              uVar5 = (uint)_DAT_800b1e3c;
              _DAT_800b1e3c = 0x6400;
              if (uVar5 + 0xa00 < 0x6401) {
                _DAT_800b1e3c = (ushort)(uVar5 + 0xa00);
              }
              break;
            case 5:
              _DAT_800b1e34 = 0xffff;
              break;
            case 6:
              Stats_MonsterBars = Stats_MonsterBars ^ 1;
              break;
            case 7:
              if (_DAT_800b1e30 < 0x33) {
                _DAT_800b1e30 = 0x33;
              }
              break;
            case 8:
              spell = 0;
              do {
                if ((spell != 4) && (spell != 7)) {
                  lVar6 = Pl_GetSpellLevel((_PLAYER *)&Player,spell,(long *)0x0);
                  if (lVar6 + 1 != 0) {
                    Pl_SetSpellLevel((_PLAYER *)&Player,spell,lVar6 + 1,(long *)0x0);
                  }
                }
                spell = spell + 1;
              } while (spell < 0x12);
              break;
            case 9:
              spell = 0;
              do {
                if ((spell != 4) && (spell != 7)) {
                  Pl_GetSpellLevel((_PLAYER *)&Player,spell,(long *)0x0);
                  Pl_SetSpellLevel((_PLAYER *)&Player,spell,0,(long *)0x0);
                }
                spell = spell + 1;
              } while (spell < 0x12);
            }
          }
        }
        else {
          *puVar7 = 0;
        }
        iVar10 = iVar10 + 2 + (uint)uVar1;
        uVar1 = (&InGame_Cheats)[iVar10];
        iVar3 = iVar3 + 1;
      }
    }
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ InGame_LevelEnd(struct _PLAYER *pl /*$s2*/, long entry /*$s3*/)
 // line 474, offset 0x80082534
	/* begin block 1 */
		// Start line: 475
		// Start offset: 0x80082534
		// Variables:
	// 		long c; // $s0
	/* end block 1 */
	// End offset: 0x800825EC
	// End Line: 512

	/* begin block 2 */
		// Start line: 1194
	/* end block 2 */
	// End Line: 1195

void InGame_LevelEnd(_PLAYER *pl,long entry)

{
  long lVar1;
  
  Card_Start();
  do {
    InGame_MenuAlloc(1);
    InGame_MenuClear();
    InGame_MenuTitle((char *)Pvl_UtilityTexts[0x32]);
    InGame_MenuOption((char *)Pvl_UtilityTexts[0x45],'!');
    InGame_MenuOption((char *)Pvl_UtilityTexts[0x46],'\"');
    InGame_MenuExec(0,-2);
    lVar1 = InGame_MenuWait();
    InGame_MenuFree();
    if (lVar1 != 0x21) break;
    lVar1 = InGame_SaveGame(pl,entry,1);
  } while (lVar1 == 0);
  Card_Stop();
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ InGame_LoadGame()
 // line 518, offset 0x80082610
	/* begin block 1 */
		// Start line: 519
		// Start offset: 0x80082610
		// Variables:
	// 		long channel; // $s1
	// 		long file; // $v0
	// 		char text[48]; // stack offset -104
	// 		char name[24]; // stack offset -56

		/* begin block 1.1 */
			// Start line: 533
			// Start offset: 0x80082668
		/* end block 1.1 */
		// End offset: 0x80082794
		// End Line: 588
	/* end block 1 */
	// End offset: 0x800827A8
	// End Line: 591

	/* begin block 2 */
		// Start line: 1282
	/* end block 2 */
	// End Line: 1283

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

long InGame_LoadGame(void)

{
  uint uVar1;
  long lVar2;
  uint channel;
  char acStack104 [48];
  char acStack56 [24];
  
  InGame_LoadMode = 1;
  Card_Start();
  if ((_DAT_800b1c56 & 8) == 0) {
    do {
      uVar1 = InGame_ChooseCard();
      if (uVar1 != 0xfffffffe) {
        channel = uVar1 & 0xff;
        if (uVar1 == 0xffffffff) break;
        lVar2 = InGame_ChooseFile(channel,1,0);
        if (lVar2 != -2) {
          if (lVar2 == -1) break;
          InGame_TestFile((char *)(&InGame_Directory + lVar2),acStack56,0);
          sprintf(acStack104,(char *)Pvl_UtilityTexts[0x3b],acStack56,((int)channel >> 4) + 1);
          InGame_DisplayText(acStack104,3);
          lVar2 = Pvl_LoadGame((_PLAYER *)&Player,(short)channel,(char *)(&InGame_Directory + lVar2)
                              );
          if (lVar2 == 0) {
            OVER_DISPLAY = 0;
            sprintf(acStack104,(char *)Pvl_UtilityTexts[0x3d]);
            InGame_DisplayText(acStack104,(int)Scr_TicksPerSecond * 3);
            _DAT_800b1d50 = 0;
            _DAT_800b1c56 = _DAT_800b1c56 | 8;
          }
          else {
            sprintf(acStack104,(char *)Pvl_UtilityTexts[0x36]);
            InGame_DisplayText(acStack104,(int)Scr_TicksPerSecond * 3);
          }
        }
      }
    } while ((_DAT_800b1c56 & 8) == 0);
  }
  Card_Stop();
  return (uint)(_DAT_800b1c56 >> 3) & 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ InGame_SaveGame(struct _PLAYER *pl /*$a0*/, long entry /*$a1*/, long mode /*$a2*/)
 // line 597, offset 0x800827e4
	/* begin block 1 */
		// Start line: 598
		// Start offset: 0x800827E4
		// Variables:
	// 		char text[80]; // stack offset -112
	// 		char name[20]; // stack offset -32

		/* begin block 1.1 */
			// Start line: 625
			// Start offset: 0x8008280C
		/* end block 1.1 */
		// End offset: 0x8008280C
		// End Line: 683
	/* end block 1 */
	// End offset: 0x8008280C
	// End Line: 688

	/* begin block 2 */
		// Start line: 1453
	/* end block 2 */
	// End Line: 1454

long InGame_SaveGame(_PLAYER *pl,long entry,long mode)

{
  InGame_DisplayText(s_Sauvegarde_non_disponible_800ad940,(int)Scr_TicksPerSecond * 3);
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ InGame_ChooseCard()
 // line 692, offset 0x8008281c
	/* begin block 1 */
		// Start line: 693
		// Start offset: 0x8008281C
		// Variables:
	// 		long a; // $s2
	// 		long b; // $s1
	// 		long c; // $s0
	// 		long d; // $v1
	// 		char text[80]; // stack offset -104
	/* end block 1 */
	// End offset: 0x80082A54
	// End Line: 790

	/* begin block 2 */
		// Start line: 1650
	/* end block 2 */
	// End Line: 1651

/* WARNING: Unknown calling convention yet parameter storage is locked */

long InGame_ChooseCard(void)

{
  long channel;
  long lVar1;
  long lVar2;
  long channel_00;
  long def_opt;
  char acStack104 [80];
  
  sprintf(acStack104,s__s_1____800ad964,Pvl_UtilityTexts[0x37]);
  InGame_DisplayText(acStack104,3);
  channel = Card_Exist(0);
  sprintf(acStack104,s__s_2____800ad96c,Pvl_UtilityTexts[0x37]);
  InGame_DisplayText(acStack104,3);
  lVar1 = Card_Exist(0x10);
  if (channel == 0) {
    if (lVar1 == 0) {
      sprintf(acStack104,(char *)&PTR_DAT_800ad974,Pvl_UtilityTexts[0x33]);
      InGame_DisplayText(acStack104,(int)Scr_TicksPerSecond * 3);
      return -1;
    }
  }
  else {
    def_opt = 0;
    if (lVar1 != 0) {
      do {
        InGame_MenuAlloc(1);
        InGame_MenuClear();
        sprintf(acStack104,(char *)&PTR_DAT_800ad974,Pvl_UtilityTexts[0x3e]);
        InGame_MenuTitle(acStack104);
        sprintf(acStack104,&DAT_800ad978,Pvl_UtilityTexts[0x44]);
        InGame_MenuOption(acStack104,'\x10');
        sprintf(acStack104,&DAT_800ad980,Pvl_UtilityTexts[0x44]);
        InGame_MenuOption(acStack104,'\x11');
        InGame_MenuOption((char *)Pvl_UtilityTexts[0x47],'\"');
        InGame_MenuExec(def_opt,0x11);
        def_opt = InGame_MenuWait();
        InGame_MenuFree();
        if (def_opt < 0) {
          return -2;
        }
        if (def_opt == 0x22) {
          return -1;
        }
        lVar2 = -3;
        if ((def_opt == 0x10) && (channel == 2)) {
          channel_00 = 0;
LAB_800829e0:
          lVar2 = InGame_FormatCard(channel_00);
        }
        else {
          if ((def_opt == 0x11) && (channel_00 = 0x10, lVar1 == 2)) goto LAB_800829e0;
        }
        if (lVar2 != -1) {
          if (lVar2 == -3) {
            return (uint)(def_opt != 0x10) << 4;
          }
          return lVar2;
        }
      } while( true );
    }
    if (channel != 0) {
      if (channel != 2) {
        return 0;
      }
      channel = 0;
      goto LAB_80082a4c;
    }
  }
  if (lVar1 != 2) {
    return 0x10;
  }
  channel = 0x10;
LAB_80082a4c:
  channel = InGame_FormatCard(channel);
  return channel;
}



// decompiled code
// original method signature: 
// long /*$ra*/ InGame_FormatCard(long channel /*$s1*/)
 // line 793, offset 0x80082a70
	/* begin block 1 */
		// Start line: 794
		// Start offset: 0x80082A70
		// Variables:
	// 		long i; // $s0
	// 		char text[80]; // stack offset -104
	/* end block 1 */
	// End offset: 0x80082C08
	// End Line: 865

	/* begin block 2 */
		// Start line: 1900
	/* end block 2 */
	// End Line: 1901

long InGame_FormatCard(long channel)

{
  size_t sVar1;
  long lVar2;
  uint uVar3;
  long lVar4;
  char local_68 [80];
  
  InGame_MenuAlloc(1);
  InGame_MenuClear();
  sprintf(local_68,(char *)Pvl_UtilityTexts[0x41],(channel >> 4) + 1);
  uVar3 = 0;
  if (InGame_LoadMode == 0) {
    InGame_MenuTitle(local_68);
    InGame_MenuOption((char *)Pvl_UtilityTexts[0x45],'!');
    InGame_MenuOption((char *)Pvl_UtilityTexts[0x46],'\"');
    InGame_MenuExec(1,channel);
    lVar4 = InGame_MenuWait();
  }
  else {
    while( true ) {
      sVar1 = strlen(local_68);
      if (sVar1 <= uVar3) break;
      if (local_68[uVar3] == '.') {
        local_68[uVar3 + 1] = '\0';
        break;
      }
      uVar3 = uVar3 + 1;
    }
    InGame_MenuTitle(local_68);
    lVar4 = -1;
    InGame_MenuOption((char *)Pvl_UtilityTexts[0x47],'#');
    InGame_MenuExec(0,channel);
    lVar2 = InGame_MenuWait();
    if (lVar2 == 0x23) {
      lVar4 = 0x22;
    }
  }
  InGame_MenuFree();
  if (lVar4 == -1) {
    uVar3 = 0xfffffffe;
  }
  else {
    if (lVar4 == 0x22) {
      uVar3 = 0xffffffff;
    }
    else {
      sprintf(local_68,s__s__d____800ad988,Pvl_UtilityTexts[0x39],(channel >> 4) + 1);
      InGame_DisplayText(local_68,3);
      lVar4 = Card_Format(channel);
      uVar3 = 0xffffffff;
      if (lVar4 == 0) {
        InGame_nFiles = 0;
        uVar3 = channel | 0x100;
      }
    }
  }
  return uVar3;
}



// decompiled code
// original method signature: 
// long /*$ra*/ InGame_ChooseFile(long channel /*$s7*/, long mode /*$fp*/, long bSave /*$a2*/)
 // line 869, offset 0x80082c24
	/* begin block 1 */
		// Start line: 870
		// Start offset: 0x80082C24
		// Variables:
	// 		char text[80]; // stack offset -184
	// 		char file[32]; // stack offset -104
	// 		short f; // $s0
	// 		short fs[15]; // stack offset -72
	// 		long i; // $s0
	// 		long j; // $s3
	// 		long k; // $s2
	// 		long n; // $s6
	// 		long free; // $s4
	/* end block 1 */
	// End offset: 0x80083058
	// End Line: 1048

	/* begin block 2 */
		// Start line: 2065
	/* end block 2 */
	// End Line: 2066

long InGame_ChooseFile(long channel,long mode,long bSave)

{
  short sVar1;
  long def_opt;
  int iVar2;
  long lVar3;
  long lVar4;
  DIRENTRY *name;
  char *__format;
  int iVar5;
  int iVar6;
  char command;
  uint uVar7;
  int iVar8;
  char acStack184 [80];
  char acStack104 [32];
  short asStack72 [16];
  
  iVar5 = channel >> 4;
  sprintf(acStack184,s__s__d____800ad988,Pvl_UtilityTexts[0x38],iVar5 + 1);
  InGame_DisplayText(acStack184,3);
  def_opt = Card_ReadDirectory(channel,&InGame_Directory,&InGame_nFiles);
  lVar4 = InGame_nFiles;
  iVar8 = 0xf;
  if (def_opt == 0) {
    iVar6 = 0;
    if (0 < InGame_nFiles) {
      name = &InGame_Directory;
      do {
        iVar2 = name->size + 0x1fff;
        if (iVar2 < 0) {
          iVar2 = name->size + 0x3ffe;
        }
        iVar8 = iVar8 - (iVar2 >> 0xd);
        iVar6 = iVar6 + 1;
        name = name + 1;
      } while (iVar6 < InGame_nFiles);
    }
    def_opt = 0;
    do {
      InGame_MenuAlloc(1);
      uVar7 = 0;
      InGame_MenuClear();
      if ((mode == 0) && (iVar8 == 0)) {
        uVar7 = 1;
        iVar6 = 0;
        if (0 < lVar4) {
          name = &InGame_Directory;
          do {
            lVar3 = InGame_TestFile((char *)name,acStack104,0);
            if (lVar3 != 0) {
              uVar7 = 2;
            }
            iVar6 = iVar6 + 1;
            name = name + 1;
          } while (iVar6 < lVar4);
        }
      }
      if (uVar7 == 1) {
        __format = (char *)Pvl_UtilityTexts[0x3f];
LAB_80082e34:
        sprintf(acStack184,__format,iVar5 + 1);
      }
      else {
        if (uVar7 < 2) {
          if (uVar7 == 0) {
            sprintf(acStack184,s__s__d___800ad994,Pvl_UtilityTexts[0x44],iVar5 + 1);
          }
        }
        else {
          if (uVar7 == 2) {
            __format = (char *)Pvl_UtilityTexts[0x40];
            goto LAB_80082e34;
          }
        }
      }
      InGame_MenuTitle(acStack184);
      command = '\0';
      iVar6 = 0;
      iVar2 = 0;
      do {
        if ((iVar6 < lVar4) &&
           (lVar3 = InGame_TestFile(InGame_Directory.name + iVar2,acStack104,0), lVar3 != 0)) {
          asStack72[(int)InGame_MenuNbOptions] = (short)iVar6;
          InGame_MenuOption(acStack104,command);
          command = command + '\x01';
        }
        iVar6 = iVar6 + 1;
        iVar2 = iVar2 + 0x28;
      } while (iVar6 < 0xf);
      if (mode == 0) {
        if ((iVar8 != 0) && (iVar6 = 0, 0 < iVar8)) {
          do {
            iVar6 = iVar6 + 1;
            InGame_MenuOption((char *)Pvl_UtilityTexts[0x42],'&');
          } while (iVar6 < iVar8);
        }
      }
      else {
        if (InGame_MenuNbOptions == 0) {
          sprintf(acStack184,(char *)Pvl_UtilityTexts[0x34],iVar5 + 1);
          InGame_DisplayText(acStack184,(int)Scr_TicksPerSecond * 3);
          InGame_MenuFree();
          return -1;
        }
      }
      InGame_MenuOption((char *)Pvl_UtilityTexts[0x47],'\"');
      InGame_MenuExec(def_opt,channel);
      def_opt = InGame_MenuWait();
      InGame_MenuFree();
      if (def_opt == -1) {
        return -2;
      }
      if (def_opt == 0x22) goto LAB_80082ca8;
      if (def_opt == 0x26) {
        if (mode != 0) {
LAB_80083044:
          return (int)asStack72[def_opt];
        }
        goto LAB_80083054;
      }
      if (mode != 0) goto LAB_80083044;
      sVar1 = asStack72[def_opt];
      InGame_MenuAlloc(1);
      InGame_MenuClear();
      InGame_TestFile((char *)(&InGame_Directory + (int)sVar1),acStack104,0);
      sprintf(acStack184,s__s__s___800ad99c,Pvl_UtilityTexts[0x43],acStack104);
      InGame_MenuTitle(acStack184);
      InGame_MenuOption((char *)Pvl_UtilityTexts[0x45],'!');
      InGame_MenuOption((char *)Pvl_UtilityTexts[0x46],'\"');
      InGame_MenuExec(1,channel);
      lVar3 = InGame_MenuWait();
      InGame_MenuFree();
      if (lVar3 == -1) {
        return -2;
      }
    } while (lVar3 != 0x21);
    lVar4 = Card_DeleteFile(channel,(char *)(&InGame_Directory + (int)sVar1));
    def_opt = -1;
    if (lVar4 == 0) {
LAB_80083054:
      def_opt = 0x80;
    }
  }
  else {
LAB_80082ca8:
    def_opt = -1;
  }
  return def_opt;
}



// decompiled code
// original method signature: 
// long /*$ra*/ InGame_TestFile(char *name /*$s0*/, char *string /*$s1*/, long n /*$v0*/)
 // line 1052, offset 0x80083088
	/* begin block 1 */
		// Start line: 1053
		// Start offset: 0x80083088
		// Variables:
	// 		long p; // $a2
	// 		long l; // $a3
	// 		long n1; // $v1
	// 		long n2; // $a0
	// 		long n3; // $a1

		/* begin block 1.1 */
			// Start line: 1061
			// Start offset: 0x800830A8
		/* end block 1.1 */
		// End offset: 0x800830C8
		// End Line: 1067
	/* end block 1 */
	// End offset: 0x8008316C
	// End Line: 1095

	/* begin block 2 */
		// Start line: 2593
	/* end block 2 */
	// End Line: 2594

long InGame_TestFile(char *name,char *string,long n)

{
  int iVar1;
  int iVar2;
  
  if (name == (char *)0x0) {
    iVar1 = (int)Pvl_PlayerNumber;
    iVar2 = (int)Pvl_LevelNumber;
  }
  else {
    iVar1 = strncmp(name + 2,s_SLES_01409_800ad9b0,10);
    if (iVar1 != 0) {
      return 0;
    }
    iVar1 = (uint)(byte)name[0xc] - 0x41;
    iVar2 = (uint)(byte)name[0xd] - 0x41;
    n = ((uint)(byte)name[0xe] - 0x30) * 100 + ((uint)(byte)name[0xf] - 0x30) * 10 +
        ((uint)(byte)name[0x10] - 0x30);
    if (string == (char *)0x0) {
      return n;
    }
  }
  sprintf(string,s__s__d__03d_800ad9a4,Pl_Names6[iVar1],iVar2,n);
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ InGame_GetFileIndex()
 // line 1098, offset 0x80083180
	/* begin block 1 */
		// Start line: 1099
		// Start offset: 0x80083180
		// Variables:
	// 		long index; // $v1
	// 		long numero; // $s1
	// 		long i; // $s0
	/* end block 1 */
	// End offset: 0x800831F8
	// End Line: 1118

	/* begin block 2 */
		// Start line: 2707
	/* end block 2 */
	// End Line: 2708

/* WARNING: Unknown calling convention yet parameter storage is locked */

long InGame_GetFileIndex(void)

{
  long lVar1;
  int iVar2;
  long lVar3;
  DIRENTRY *name;
  
  lVar3 = 1;
  iVar2 = 0;
  if (0 < InGame_nFiles) {
    name = &InGame_Directory;
    do {
      lVar1 = InGame_TestFile((char *)name,(char *)0x0,0);
      if ((lVar1 != 0) && (lVar3 <= lVar1)) {
        lVar3 = lVar1 + 1;
      }
      iVar2 = iVar2 + 1;
      name = name + 1;
    } while (iVar2 < InGame_nFiles);
  }
  if (999 < lVar3) {
    lVar3 = 1;
  }
  return lVar3;
}



// decompiled code
// original method signature: 
// void /*$ra*/ InGame_DisplayText(char *text /*$s2*/, long time /*$s1*/)
 // line 1125, offset 0x80083214
	/* begin block 1 */
		// Start line: 1126
		// Start offset: 0x80083214
		// Variables:
	// 		long i; // $s0
	/* end block 1 */
	// End offset: 0x8008325C
	// End Line: 1135

	/* begin block 2 */
		// Start line: 2777
	/* end block 2 */
	// End Line: 2778

void InGame_DisplayText(char *text,long time)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < time) {
    do {
      Text_SetText(text,-0x7ffe,-0x7ffd);
      iVar1 = iVar1 + 1;
      Task_Next();
    } while (iVar1 < time);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ InGame_MenuAlloc(long help /*$s0*/)
 // line 1140, offset 0x80083274
	/* begin block 1 */
		// Start line: 2811
	/* end block 1 */
	// End Line: 2812

void InGame_MenuAlloc(long help)

{
  InGame_MenuTexts = (char *)Heap_AllocMem(0x1000);
  InGame_MenuOptions = (INGAME_134fake *)Heap_AllocMem(0x80);
  InGame_MenuHandle = (TASK *)0x0;
  InGame_MenuHelp = (short)help;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ InGame_MenuFree()
 // line 1150, offset 0x800832b4
	/* begin block 1 */
		// Start line: 2835
	/* end block 1 */
	// End Line: 2836

/* WARNING: Unknown calling convention yet parameter storage is locked */

void InGame_MenuFree(void)

{
  Heap_FreeMem(InGame_MenuTexts);
  Heap_FreeMem(InGame_MenuOptions);
  if (InGame_MenuHandle != (TASK *)0x0) {
    Task_Kill(InGame_MenuHandle);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ InGame_MenuClear()
 // line 1160, offset 0x800832fc
	/* begin block 1 */
		// Start line: 2857
	/* end block 1 */
	// End Line: 2858

/* WARNING: Unknown calling convention yet parameter storage is locked */

void InGame_MenuClear(void)

{
  InGame_MenuText = InGame_MenuTexts;
  InGame_MenuTit = (char *)0x0;
  InGame_MenuNbOptions = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ InGame_MenuTitle(char *title /*$s0*/)
 // line 1168, offset 0x80083314
	/* begin block 1 */
		// Start line: 2873
	/* end block 1 */
	// End Line: 2874

void InGame_MenuTitle(char *title)

{
  size_t sVar1;
  
  InGame_MenuTit = InGame_MenuText;
  strcpy(InGame_MenuText,title);
  sVar1 = strlen(title);
  InGame_MenuText = InGame_MenuText + sVar1;
  *InGame_MenuText = '\0';
  InGame_MenuText = InGame_MenuText + 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ InGame_MenuOption(char *text /*$s0*/, char command /*$s2*/)
 // line 1180, offset 0x8008336c
	/* begin block 1 */
		// Start line: 1181
		// Start offset: 0x8008336C
		// Variables:
	// 		long i; // $s1
	/* end block 1 */
	// End offset: 0x800833F0
	// End Line: 1197

	/* begin block 2 */
		// Start line: 2898
	/* end block 2 */
	// End Line: 2899

void InGame_MenuOption(char *text,char command)

{
  char *__dest;
  size_t sVar1;
  int iVar2;
  
  __dest = InGame_MenuText;
  iVar2 = (int)InGame_MenuNbOptions;
  if (text == (char *)0x0) {
    InGame_MenuOptions[iVar2].text = (char *)0x0;
  }
  else {
    InGame_MenuOptions[iVar2].text = InGame_MenuText;
    strcpy(__dest,text);
    sVar1 = strlen(text);
    InGame_MenuText = InGame_MenuText + sVar1;
    *InGame_MenuText = '\0';
    InGame_MenuText = InGame_MenuText + 1;
  }
  InGame_CommandList[iVar2] = command;
  InGame_MenuNbOptions = InGame_MenuNbOptions + 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ InGame_MenuExec(long def_opt /*$s0*/, long card_test /*$s1*/)
 // line 1206, offset 0x80083424
	/* begin block 1 */
		// Start line: 2959
	/* end block 1 */
	// End Line: 2960

void InGame_MenuExec(long def_opt,long card_test)

{
  InGame_MenuHandle = Task_Add(InGame_MenuTask,0);
  InGame_MenuHandle->s0 = def_opt;
  InGame_MenuHandle->s1 = card_test;
  InGame_MenuSelected = -2;
  InGame_OptionSelected = -2;
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ InGame_MenuWait()
 // line 1221, offset 0x80083478
	/* begin block 1 */
		// Start line: 2999
	/* end block 1 */
	// End Line: 3000

/* WARNING: Unknown calling convention yet parameter storage is locked */

long InGame_MenuWait(void)

{
  if (InGame_MenuSelected == -2) {
    do {
      Task_Next();
    } while (InGame_MenuSelected == -2);
  }
  return (int)InGame_MenuSelected;
}



// decompiled code
// original method signature: 
// void /*$ra*/ InGame_MenuTask()
 // line 1230, offset 0x800834c0
	/* begin block 1 */
		// Start line: 1231
		// Start offset: 0x800834C0
		// Variables:
	// 		struct INGAME_104fake t; // stack offset -88
	// 		long i; // $s0
	// 		long y; // $s1
	// 		long ystart; // $s7
	// 		long htitle; // $s4
	// 		long s; // $s2
	// 		long command; // stack offset -56
	// 		long result; // stack offset -52
	// 		long test; // $s3
	// 		long current; // $s5
	/* end block 1 */
	// End offset: 0x800838B4
	// End Line: 1341

	/* begin block 2 */
		// Start line: 3018
	/* end block 2 */
	// End Line: 3019

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void InGame_MenuTask(void)

{
  short sVar1;
  _SCREEN *p_Var2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  long lVar6;
  int iVar7;
  char *text;
  ulong *puVar8;
  INGAME_45fake *pIVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  undefined auStack88 [32];
  int iStack56;
  int local_34 [3];
  
  Text_SetContext((TEXT_102fake *)auStack88);
  iVar14 = 0;
  Text_SetContextFont(0x70);
  Text_SetContextXY(0,0);
  Text_SetContextWH(Scr_W,Scr_H);
  Text_SetContextRange(0);
  Text_SetContextMode(0);
  uVar13 = TaskCurrent->s1;
  iVar12 = TaskCurrent->s0;
  uVar15 = uVar13 & 0x10;
  if (InGame_MenuTit != (char *)0x0) {
    uVar3 = Text_AmountOfTexts(InGame_MenuTit);
    iVar14 = ((int)((uint)uVar3 << 0x10) >> 0xd) + 8;
  }
  iVar16 = (((int)(((int)((uint)(ushort)Scr_H << 0x10) >> 0x10) +
                  (((uint)(ushort)Scr_H << 0x10) >> 0x1f)) >> 1) + (int)InGame_MenuNbOptions * -4) -
           (iVar14 >> 1);
  if (-1 < (int)uVar13) {
    MemCardExist(uVar15);
  }
  do {
    iVar11 = iVar16;
    if (InGame_MenuTit != (char *)0x0) {
      Text_SetText(InGame_MenuTit,-0x7ffe,(short)iVar16);
      iVar11 = iVar16 + iVar14;
    }
    iVar10 = 0;
    if (0 < InGame_MenuNbOptions) {
      do {
        if (InGame_MenuOptions[iVar10].text != (char *)0x0) {
          Text_SetText(InGame_MenuOptions[iVar10].text,-0x7ffe,(short)iVar11);
        }
        iVar10 = iVar10 + 1;
        iVar11 = iVar11 + 8;
      } while (iVar10 < (int)InGame_MenuNbOptions);
    }
    iVar10 = (int)((uint)(ushort)Scr_W << 0x10) >> 0x10;
    iVar4 = (int)Scr_Frame;
    iVar7 = iVar10 + (((uint)(ushort)Scr_W << 0x10) >> 0x1f);
    pIVar9 = InGame_Tiles + iVar4;
    if (iVar10 < 0) {
      iVar10 = iVar10 + 3;
    }
    sVar1 = (short)(iVar7 >> 1);
    InGame_Tiles[iVar4].x0 = sVar1 - (short)(iVar10 >> 2);
    InGame_Tiles[iVar4].w = sVar1;
    p_Var2 = Scr;
    InGame_Tiles[iVar4].y0 = (short)iVar16 + (short)iVar14 + (short)iVar12 * 8;
    InGame_Tiles[iVar4].h = 9;
    pIVar9->tag = pIVar9->tag & 0xff000000 | *p_Var2->ot & 0xffffff;
    puVar8 = p_Var2->ot;
    *puVar8 = *puVar8 & 0xff000000 | (uint)pIVar9 & 0xffffff;
    uVar5 = Joy_ReadTrig(0);
    if ((uVar5 & 0x1000) != 0) {
      iVar4 = (int)InGame_MenuNbOptions;
      iVar10 = iVar12 + iVar4 + -1;
      iVar12 = iVar10 % iVar4;
      if (iVar4 == 0) {
        trap(0x1c00);
      }
      if ((iVar4 == -1) && (iVar10 == -0x80000000)) {
        trap(0x1800);
      }
      Fx_PlayInPause(0x3f,100);
    }
    uVar5 = Joy_ReadTrig(0);
    iVar10 = iVar12 + 1;
    if ((uVar5 & 0x4000) != 0) {
      iVar4 = (int)InGame_MenuNbOptions;
      iVar12 = iVar10 % iVar4;
      if (iVar4 == 0) {
        trap(0x1c00);
      }
      if ((iVar4 == -1) && (iVar10 == -0x80000000)) {
        trap(0x1800);
      }
      Fx_PlayInPause(0x3f,100);
    }
    uVar5 = Joy_ReadTrig(0);
    if ((uVar5 & 0x40) != 0) goto LAB_80083880;
    if ((uVar13 == 0xfffffffe) && (uVar5 = Joy_ReadTrig(0), (uVar5 & 0x800) != 0)) {
      iVar12 = 0;
      goto LAB_80083880;
    }
    lVar6 = Joy_IsConnected(0);
    if (lVar6 == 0) {
      text = (char *)Pvl_UtilityTexts[0x2d];
    }
    else {
      text = (char *)Pvl_UtilityTexts[0x68];
    }
    Text_SetText(text,-0x7ffe,(short)((uint)((iVar11 + 0x10) * 0x10000) >> 0x10));
    if ((_DAT_800b1c56 & 8) != 0) goto LAB_80083854;
    if ((-1 < (int)uVar13) && (iVar11 = MemCardSync(1,&iStack56,local_34), iVar11 == 1)) {
      if ((local_34[0] == 1) || (local_34[0] == 3)) {
LAB_80083854:
        iVar12 = -1;
LAB_80083880:
        InGame_MenuSelected = (short)iVar12;
        if (-1 < iVar12 << 0x10) {
          InGame_MenuSelected = (short)InGame_CommandList[iVar12];
        }
        InGame_MenuHandle = (TASK *)0x0;
        InGame_OptionSelected = (short)iVar12;
        return;
      }
      if (uVar13 == 0x11) {
        uVar15 = (uint)(uVar15 == 0) << 4;
      }
      MemCardExist(uVar15);
    }
    Task_Next();
  } while( true );
}





