#include "THISDUST.H"
#include "INVENTRY.H"


// decompiled code
// original method signature: 
// void /*$ra*/ Invent_Init()
 // line 194, offset 0x800838e8
	/* begin block 1 */
		// Start line: 195
		// Start offset: 0x800838E8

		/* begin block 1.1 */
			// Start line: 203
			// Start offset: 0x8008391C
			// Variables:
		// 		long i; // $v1
		/* end block 1.1 */
		// End offset: 0x8008393C
		// End Line: 209
	/* end block 1 */
	// End offset: 0x8008393C
	// End Line: 210

	/* begin block 2 */
		// Start line: 388
	/* end block 2 */
	// End Line: 389

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Invent_Init(void)

{
  int iVar1;
  int iVar2;
  
  DAT_800b3f0c = Task_Add(Invent_Task,0x400);
  Cpt_Alert = 0;
  Inventaire.moving = '\0';
  if (Pvl_LoadedGame == 0) {
    Inventaire.spells_invisible = 0;
    iVar2 = 1;
    iVar1 = -0x7ff4c64c;
    do {
      *(undefined4 *)(iVar1 + 0xc) = 0;
      iVar2 = iVar2 + -1;
      iVar1 = iVar1 + -4;
    } while (-1 < iVar2);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_AppearTask()
 // line 213, offset 0x8008394c
	/* begin block 1 */
		// Start line: 214
		// Start offset: 0x8008394C
		// Variables:
	// 		long i; // $s0
	/* end block 1 */
	// End offset: 0x80083A48
	// End Line: 260

	/* begin block 2 */
		// Start line: 440
	/* end block 2 */
	// End Line: 441

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Invent_AppearTask(void)

{
  uint uVar1;
  int iVar2;
  
  if (Zone_TextHandle != (TASK *)0x0) {
    Task_Kill(Zone_TextHandle);
  }
  Inventaire.moving = '\x01';
  uVar1 = Joy_ReadLog(0);
  if ((uVar1 & (uint)PJOY_SPELL) == 0) {
    Inventaire.mode = '\0';
    Stats_Appear();
  }
  else {
    Inventaire.mode = '\x01';
  }
  iVar2 = 0;
  Invent_InitBackGround();
  Fx_Play(0x39,100);
  Overlay_MoveHealthBar(0);
  Invent_Update((_PLAYER *)&Player);
  do {
    BarY = BarY + 5;
    iVar2 = iVar2 + 1;
    Overlay_SetPrims();
    Task_Next();
  } while (iVar2 < 10);
  Invent_GoToScreen();
  Inventaire.moving = '\0';
  if (Pvl_Pause != 0) {
    Task_EventExec(Overlay_Handle,Overlay_Handle->event_msg | 2,Overlay_Handle->event_param);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_GoToScreen()
 // line 263, offset 0x80083a58
	/* begin block 1 */
		// Start line: 264
		// Start offset: 0x80083A58
		// Variables:
	// 		long i; // $s1
	/* end block 1 */
	// End offset: 0x80083B2C
	// End Line: 293

	/* begin block 2 */
		// Start line: 549
	/* end block 2 */
	// End Line: 550

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Invent_GoToScreen(void)

{
  int iVar1;
  int iVar2;
  
  Inventaire.posy = Scr_H + 0x23;
  *(undefined2 *)(DAT_800b3f0c + 0x54) = 1;
  *(undefined4 *)(DAT_800b3f0c + 0x20) = 0x80084a04;
  if (Inventaire.mode == '\x01') {
    iVar2 = 0;
    Invent_BuildSpellList((_PLAYER *)&Player);
    Task_EventExec(Overlay_Handle,Overlay_Handle->event_msg | 0x800,Overlay_Handle->event_param);
    iVar1 = 0;
  }
  else {
    Overlay_SetSpellOFF(1);
    iVar2 = 0;
    iVar1 = 0;
  }
  do {
    Invent_MoveHelp((short)((uint)iVar1 >> 0x10));
    iVar2 = iVar2 + 1;
    Invent_MoveCadre();
    Invent_MoveArrows();
    Inventaire.posy = Inventaire.posy + -6;
    Task_Next();
    iVar1 = iVar1 + 0xc0000;
  } while (iVar2 < 10);
  Invent_MoveHelp(0x78);
  Invent_MoveCadre();
  Invent_MoveArrows();
  Task_Next();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_DisappearTask()
 // line 300, offset 0x80083b60
	/* begin block 1 */
		// Start line: 301
		// Start offset: 0x80083B60
		// Variables:
	// 		long i; // $s0
	/* end block 1 */
	// End offset: 0x80083BE0
	// End Line: 330

	/* begin block 2 */
		// Start line: 632
	/* end block 2 */
	// End Line: 633

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Invent_DisappearTask(void)

{
  int iVar1;
  
  Task_Add(Overlay_SpellsDisappearTask,0x100);
  Fx_Play(0x39,100);
  Inventaire.moving = '\x01';
  iVar1 = 0;
  Stats_Disappear();
  Overlay_MoveHealthBar(1);
  Invent_OuttaScreen();
  do {
    BarY = BarY + -5;
    iVar1 = iVar1 + 1;
    Overlay_SetPrims();
    Task_Next();
  } while (iVar1 < 10);
  Inventaire.moving = '\0';
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_OuttaScreen()
 // line 334, offset 0x80083bf4
	/* begin block 1 */
		// Start line: 335
		// Start offset: 0x80083BF4
		// Variables:
	// 		long i; // $s0
	/* end block 1 */
	// End offset: 0x80083C58
	// End Line: 349

	/* begin block 2 */
		// Start line: 712
	/* end block 2 */
	// End Line: 713

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Invent_OuttaScreen(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = 0;
  do {
    Invent_MoveHelp((short)((uint)((iVar1 + 9) * 0xe0000) >> 0x10));
    iVar2 = iVar2 + 1;
    Invent_MoveCadre();
    Invent_MoveArrows();
    Inventaire.posy = Inventaire.posy + 6;
    Task_Next();
    iVar1 = -iVar2;
  } while (iVar2 < 0xb);
  *(undefined4 *)(DAT_800b3f0c + 0x20) = 0;
  *(undefined2 *)(DAT_800b3f0c + 0x54) = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_Task()
 // line 354, offset 0x80083c84
	/* begin block 1 */
		// Start line: 355
		// Start offset: 0x80083C84
		// Variables:
	// 		long i; // $a1
	// 		long j; // $v1
	// 		long trig; // $s2
	// 		long use; // $s1
	// 		long alert_mode; // $s3
	// 		long sens; // $s5
	// 		char message[80]; // stack offset -144
	// 		struct _INVENT_LIST *l; // $s0
	// 		struct INVENTRY_104fake t; // stack offset -64

		/* begin block 1.1 */
			// Start line: 458
			// Start offset: 0x80083F48
		/* end block 1.1 */
		// End offset: 0x80084068
		// End Line: 492

		/* begin block 1.2 */
			// Start line: 505
			// Start offset: 0x800840BC
		/* end block 1.2 */
		// End offset: 0x800840BC
		// End Line: 505

		/* begin block 1.3 */
			// Start line: 577
			// Start offset: 0x800842D0
		/* end block 1.3 */
		// End offset: 0x80084308
		// End Line: 582
	/* end block 1 */
	// End offset: 0x80084394
	// End Line: 608

	/* begin block 2 */
		// Start line: 756
	/* end block 2 */
	// End Line: 757

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Invent_Task(void)

{
  bool bVar1;
  byte bVar2;
  TASK *pTVar3;
  byte bVar4;
  short *psVar5;
  long lVar6;
  int iVar7;
  short Fx;
  _INVENT_LIST *p_Var8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  short mode;
  int iVar12;
  char acStack144 [80];
  char acStack64 [32];
  
  Text_SetContext((TEXT_102fake *)(acStack144 + 0x50));
  iVar12 = 8;
  Text_SetContextFont(0x70);
  Text_SetContextXY(0,0);
  Text_SetContextWH(Scr_W,Scr_H);
  Text_SetContextRange(1);
  Text_SetContextMode(0);
  iVar10 = 0;
  p_Var8 = Inventaire.inv_list;
  Inventaire.posx = 0x1e;
  Shift_Col = -1;
  Inventaire.posy = Scr_H + 0x1e;
  do {
    iVar7 = 0x1f;
    psVar5 = &p_Var8->list[0x1e].text_crc;
    p_Var8->hilite = '\0';
    p_Var8->deb_list = '\0';
    p_Var8->nb_obj = '\0';
    do {
      psVar5[3] = 0;
      iVar7 = iVar7 + -1;
      psVar5 = psVar5 + -5;
    } while (-1 < iVar7);
    iVar10 = iVar10 + 1;
    p_Var8 = p_Var8 + 1;
  } while (iVar10 < 2);
  Invent_InitBackGround();
  Invent_InitArrows();
  Invent_InitAlertWindow();
  Invent_MoveHelp(0);
  pTVar3 = TaskCurrent;
  TaskCurrent->display = (_func_11 *)0x0;
  pTVar3->enable = 0;
  Task_Next();
  TaskCurrent->display = Invent_Display;
  do {
    uVar11 = 0;
    if (Inventaire.moving == '\0') {
      uVar11 = Joy_ReadTrig(0);
    }
    else {
      Cpt_Alert = 0;
    }
    uVar9 = (uint)(byte)Inventaire.mode;
    p_Var8 = Inventaire.inv_list + uVar9;
    if (uVar11 != 0) {
      Cpt_Alert = 0;
    }
    if (SHIFT_STATS != 0) goto LAB_80084234;
    if (Inventaire.mode != '\0') {
      if ((((uVar11 & 0x8000) != 0) && (Inventaire.inv_list[uVar9].hilite != '\0')) &&
         (SPELL_MOVING == 0)) {
        Fx_Play(0x40,100);
        bVar2 = Inventaire.inv_list[uVar9].deb_list;
        bVar4 = Inventaire.inv_list[uVar9].hilite - 1;
        Inventaire.inv_list[uVar9].hilite = bVar4;
        if (bVar4 < bVar2) {
          Inventaire.inv_list[uVar9].deb_list = bVar2 - 1;
        }
      }
      if ((((uVar11 & 0x2000) != 0) &&
          ((int)(uint)(byte)Inventaire.inv_list[uVar9].hilite <
           (int)((uint)(byte)p_Var8->nb_obj - 1))) && (SPELL_MOVING == 0)) {
        Fx_Play(0x40,100);
        bVar2 = Inventaire.inv_list[uVar9].deb_list;
        bVar4 = Inventaire.inv_list[uVar9].hilite + 1;
        Inventaire.inv_list[uVar9].hilite = bVar4;
        if ((uint)bVar2 + 5 <= (uint)bVar4) {
          Inventaire.inv_list[uVar9].deb_list = bVar2 + 1;
        }
      }
      if ((uVar11 & 0x10) != 0) {
        Invent_SpellGoToButton((_PLAYER *)&Player,0);
      }
      if ((uVar11 & 0x80) != 0) {
        Invent_SpellGoToButton((_PLAYER *)&Player,1);
      }
      if ((uVar11 & 0x20) != 0) {
        Invent_SpellGoToButton((_PLAYER *)&Player,2);
      }
      if ((uVar11 & 0x40) != 0) {
        Invent_SpellGoToButton((_PLAYER *)&Player,3);
      }
      goto LAB_80084234;
    }
    if (((uVar11 & 0x8000) != 0) && (Inventaire.inv_list[uVar9].hilite != '\0')) {
      Fx_Play(0x40,100);
      bVar2 = Inventaire.inv_list[uVar9].deb_list;
      bVar4 = Inventaire.inv_list[uVar9].hilite - 1;
      Inventaire.inv_list[uVar9].hilite = bVar4;
      if (bVar4 < bVar2) {
        Inventaire.inv_list[uVar9].deb_list = bVar2 - 1;
      }
    }
    if (((uVar11 & 0x2000) != 0) &&
       ((int)(uint)(byte)Inventaire.inv_list[uVar9].hilite < (int)((uint)(byte)p_Var8->nb_obj - 1)))
    {
      Fx_Play(0x40,100);
      bVar2 = Inventaire.inv_list[uVar9].deb_list;
      bVar4 = Inventaire.inv_list[uVar9].hilite + 1;
      Inventaire.inv_list[uVar9].hilite = bVar4;
      if ((uint)bVar2 + 5 <= (uint)bVar4) {
        Inventaire.inv_list[uVar9].deb_list = bVar2 + 1;
      }
    }
    if (((uVar11 & 0x40) == 0) || (p_Var8->nb_obj == '\0')) goto LAB_8008408c;
    lVar6 = Invent_UseObject((_PLAYER *)&Player);
    if (0 < lVar6) {
      Fx_Play(0x3f,100);
      goto LAB_8008408c;
    }
    Fx = 0x3b;
    if ((1 < lVar6 + 5U) && (Fx = 0x3f, lVar6 != -7)) {
      Fx = 0x42;
    }
    mode = 2;
    Fx_Play(Fx,100);
    switch(lVar6) {
    case 0:
      lVar6 = Pvl_UtilityTexts[4];
      break;
    default:
      goto switchD_80083f40_caseD_9;
    case -8:
      lVar6 = Pvl_UtilityTexts[7];
      break;
    case -7:
      mode = 0;
      Invent_SPRINT_AB(acStack144,(uint)(byte)Inventaire.inv_list[uVar9].pad,0x48,0);
      goto switchD_80083f40_caseD_9;
    case -6:
      lVar6 = Pvl_UtilityTexts[9];
      break;
    case -5:
      mode = 1;
      sprintf(acStack144,s__s__s_800ad9f0,
              Pvl_UtilityTexts[(uint)(byte)(&PSpells)[(uint)(byte)Inventaire.inv_list[1].pad].text],
              Pvl_UtilityTexts[0x4d]);
      goto switchD_80083f40_caseD_9;
    case -4:
      mode = 1;
      sprintf(acStack144,(char *)&PTR_DAT_800ad9ec,Pvl_UtilityTexts[0x4c]);
      goto switchD_80083f40_caseD_9;
    case -3:
      lVar6 = Pvl_UtilityTexts[8];
      break;
    case -2:
      lVar6 = Pvl_UtilityTexts[6];
      break;
    case -1:
      lVar6 = Pvl_UtilityTexts[5];
    }
    sprintf(acStack144,(char *)&PTR_DAT_800ad9ec,lVar6);
switchD_80083f40_caseD_9:
    Cpt_Alert = 0x3c;
LAB_8008408c:
    if (((uVar11 & 0x10) != 0) && (p_Var8->nb_obj != '\0')) {
      lVar6 = Invent_DropObject((_PLAYER *)&Player);
      if (lVar6 == 0) {
        mode = 2;
        sprintf(acStack144,(char *)&PTR_DAT_800ad9ec,Pvl_UtilityTexts[10]);
        Fx_Play(0x42,100);
        Cpt_Alert = 0x3c;
      }
    }
LAB_80084234:
    if ((uVar11 & (uint)PJOY_SPELL) != 0) {
      Inventaire.moving = '\x01';
      Fx_Play(0x39,100);
      if (Inventaire.mode == '\0') {
        Stats_Disappear();
      }
      else {
        Stats_Appear();
      }
      Invent_OuttaScreen();
      Inventaire.mode = Inventaire.mode ^ 1;
      Invent_InitBackGround();
      Invent_GoToScreen();
      Inventaire.moving = '\0';
    }
    lVar6 = Task_EventRead(TaskCurrent);
    if (lVar6 == 1) {
      mode = 2;
      Cpt_Alert = 0x3c;
      sprintf(acStack144,(char *)&PTR_DAT_800ad9ec,Pvl_UtilityTexts[6]);
      Fx_Play(0x42,100);
    }
    Fx = Cpt_Alert + -1;
    if ((Cpt_Alert != 0) && (bVar1 = Cpt_Alert != 1, Cpt_Alert = Fx, bVar1)) {
      Cpt_Alert = Fx;
      Invent_Alert(acStack144,mode);
    }
    if ((0 < iVar12) && (0xf9 < Shift_Col)) {
      iVar12 = -8;
    }
    if ((iVar12 < 0) && (Shift_Col < 0x81)) {
      iVar12 = 8;
    }
    Shift_Col = Shift_Col + (char)iVar12;
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_InitBackGround()
 // line 611, offset 0x80084394
	/* begin block 1 */
		// Start line: 613
		// Start offset: 0x80084394
		// Variables:
	// 		long i; // $a1
	// 		struct INVENTRY_29fake *p; // $v1
	// 		struct INVENTRY_36fake *pl; // $v1
	/* end block 1 */
	// End offset: 0x800844D0
	// End Line: 655

	/* begin block 2 */
		// Start line: 1314
	/* end block 2 */
	// End Line: 1315

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Invent_InitBackGround(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  
  puVar5 = &DAT_800b3efc;
  iVar4 = 0;
  iVar3 = 0;
  do {
    (&DAT_800b3ecf)[iVar4] = 5;
    (&DAT_800b3ed3)[iVar4] = 0x28;
    sVar1 = Scr_W;
    *(undefined2 *)((int)&DAT_800b3ed4 + iVar4) = 0;
    *(undefined2 *)((int)&DAT_800b3ed6 + iVar4) = 0xbe;
    *(undefined2 *)((int)&DAT_800b3eda + iVar4) = 0xbe;
    *(undefined2 *)((int)&DAT_800b3edc + iVar4) = 0;
    *(undefined2 *)((int)&DAT_800b3ede + iVar4) = 0xfa;
    *(undefined2 *)((int)&DAT_800b3ee2 + iVar4) = 0xfa;
    *(short *)((int)&DAT_800b3ed8 + iVar4) = sVar1;
    *(short *)((int)&DAT_800b3ee0 + iVar4) = sVar1;
    if (Inventaire.mode == '\x01') {
      (&DAT_800b3ed0)[iVar4] = 0x1e;
      (&DAT_800b3ed1)[iVar4] = 0x1e;
      (&DAT_800b3ed2)[iVar4] = 10;
    }
    else {
      (&DAT_800b3ed0)[iVar4] = 0x28;
      (&DAT_800b3ed1)[iVar4] = 0x28;
      (&DAT_800b3ed2)[iVar4] = 0x28;
    }
    (&DAT_800b3ed3)[iVar4] = (&DAT_800b3ed3)[iVar4] | 2;
    iVar2 = iVar3 * 0x10;
    (&DAT_800b3e7f)[iVar2] = 3;
    (&DAT_800b3e83)[iVar2] = 0x40;
    sVar1 = Scr_W;
    (&DAT_800b3e84)[iVar3 * 8] = 0;
    (&DAT_800b3e86)[iVar3 * 8] = 0xbe;
    (&DAT_800b3e8a)[iVar3 * 8] = 0xbe;
    (&DAT_800b3e88)[iVar3 * 8] = sVar1;
    if (Inventaire.mode == '\x01') {
      (&DAT_800b3e80)[iVar2] = 100;
      (&DAT_800b3e81)[iVar2] = 100;
      (&DAT_800b3e82)[iVar2] = 200;
    }
    else {
      (&DAT_800b3e80)[iVar2] = 100;
      (&DAT_800b3e81)[iVar2] = 100;
      (&DAT_800b3e82)[iVar2] = 100;
    }
    puVar5[3] = 1;
    puVar5 = puVar5 + 8;
    iVar4 = iVar4 + 0x18;
    iVar2 = iVar3 + 1;
    (&DAT_800b3f00)[iVar3 * 2] = 0xe1000240;
    iVar3 = iVar2;
  } while (iVar2 < 2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_InitArrows()
 // line 658, offset 0x800844d8
	/* begin block 1 */
		// Start line: 659
		// Start offset: 0x800844D8
		// Variables:
	// 		long i; // $s2
	// 		struct INVENTRY_31fake *p; // $s0
	// 		struct INVENTRY_70fake shp; // stack offset -48
	// 		short w; // stack offset -32
	// 		short h; // stack offset -30
	// 		short y; // $s3
	/* end block 1 */
	// End offset: 0x80084660
	// End Line: 698

	/* begin block 2 */
		// Start line: 1502
	/* end block 2 */
	// End Line: 1503

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Invent_InitArrows(void)

{
  int iVar1;
  int iVar2;
  short sVar3;
  SHAPE_68fake local_30;
  ushort local_20;
  ushort local_1e [3];
  
  iVar2 = 0;
  local_30.shape = 0x76;
  sVar3 = Inventaire.posy + -10;
  local_30.file = Effects_Pcl;
  Shp_GetWH(&local_30,(short *)&local_20,(short *)local_1e);
  iVar1 = 0;
  sVar3 = sVar3 - (short)((int)(((int)((uint)local_1e[0] << 0x10) >> 0x10) +
                               (((uint)local_1e[0] << 0x10) >> 0x1f)) >> 1);
  do {
    iVar2 = iVar2 + 1;
    local_30.x = 10;
    local_30.shape = 0x76;
    local_30.y = sVar3;
    Shp_SetPolyFT4((SHAPE_31fake *)(&DAT_800b3d8c + iVar1),&local_30,
                   (short)(((uint)local_20 + 1) * 0x10000 >> 0x10),
                   (short)(((uint)local_1e[0] + 1) * 0x10000 >> 0x10));
    (&DAT_800b3d93)[iVar1] = (&DAT_800b3d93)[iVar1] & 0xfe;
    (&DAT_800b3db0)[iVar1] = (&DAT_800b3db0)[iVar1] + '\x01';
    (&DAT_800b3da0)[iVar1] = (&DAT_800b3da0)[iVar1] + '\x01';
    (&DAT_800b3db1)[iVar1] = (&DAT_800b3db1)[iVar1] + '\x01';
    (&DAT_800b3da9)[iVar1] = (&DAT_800b3da9)[iVar1] + '\x01';
    local_30.x = 0x127;
    local_30.shape = 0x77;
    local_30.y = sVar3;
    Shp_SetPolyFT4((SHAPE_31fake *)(&DAT_800b3db4 + iVar1),&local_30,
                   (short)(((uint)local_20 + 1) * 0x10000 >> 0x10),
                   (short)(((uint)local_1e[0] + 1) * 0x10000 >> 0x10));
    (&DAT_800b3dbb)[iVar1] = (&DAT_800b3dbb)[iVar1] & 0xfe;
    (&DAT_800b3dd8)[iVar1] = (&DAT_800b3dd8)[iVar1] + '\x01';
    (&DAT_800b3dc8)[iVar1] = (&DAT_800b3dc8)[iVar1] + '\x01';
    (&DAT_800b3dd9)[iVar1] = (&DAT_800b3dd9)[iVar1] + '\x01';
    (&DAT_800b3dd1)[iVar1] = (&DAT_800b3dd1)[iVar1] + '\x01';
    iVar1 = iVar1 + 0x50;
  } while (iVar2 < 2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_MoveCadre()
 // line 701, offset 0x8008467c
	/* begin block 1 */
		// Start line: 702
		// Start offset: 0x8008467C
		// Variables:
	// 		long i; // $a1
	/* end block 1 */
	// End offset: 0x80084728
	// End Line: 720

	/* begin block 2 */
		// Start line: 1681
	/* end block 2 */
	// End Line: 1682

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Invent_MoveCadre(void)

{
  short sVar1;
  short sVar2;
  undefined *puVar3;
  int iVar4;
  short sVar5;
  
  sVar2 = Scr_H;
  iVar4 = 0;
  puVar3 = &DAT_800b3ecc;
  sVar5 = Scr_W + -1;
  do {
    *(undefined2 *)(puVar3 + 8) = 0;
    sVar1 = Inventaire.posy;
    iVar4 = iVar4 + 1;
    *(short *)(puVar3 + 0xc) = sVar5;
    *(short *)(puVar3 + 10) = sVar1 + -0x23;
    sVar1 = Inventaire.posy;
    *(short *)(puVar3 + 0x12) = sVar2 + -1;
    *(short *)(puVar3 + 0x16) = sVar2 + -1;
    *(undefined2 *)(puVar3 + 0x10) = 0;
    *(short *)(puVar3 + 0x14) = sVar5;
    *(short *)(puVar3 + 0xe) = sVar1 + -0x23;
    sVar1 = Scr_W;
    puVar3 = puVar3 + 0x18;
  } while (iVar4 < 2);
  iVar4 = 0;
  puVar3 = &DAT_800b3e7c;
  do {
    *(undefined2 *)(puVar3 + 8) = 0;
    sVar2 = Inventaire.posy;
    *(short *)(puVar3 + 0xc) = sVar1;
    *(short *)(puVar3 + 10) = sVar2 + -0x23;
    iVar4 = iVar4 + 1;
    *(short *)(puVar3 + 0xe) = Inventaire.posy + -0x23;
    puVar3 = puVar3 + 0x10;
  } while (iVar4 < 2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_MoveArrows()
 // line 723, offset 0x80084730
	/* begin block 1 */
		// Start line: 724
		// Start offset: 0x80084730
		// Variables:
	// 		long i; // $t0
	// 		struct INVENTRY_31fake *p; // $v0
	// 		struct INVENTRY_70fake shp; // stack offset -32
	// 		short w; // stack offset -16
	// 		short h; // stack offset -14
	// 		short x; // $v1
	// 		short y; // $a1
	/* end block 1 */
	// End offset: 0x80084810
	// End Line: 748

	/* begin block 2 */
		// Start line: 1740
	/* end block 2 */
	// End Line: 1741

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Invent_MoveArrows(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  SHAPE_68fake local_20;
  short local_10;
  ushort local_e [3];
  
  local_20.shape = 0x76;
  sVar1 = Inventaire.posy + -10;
  local_20.file = Effects_Pcl;
  Shp_GetWH(&local_20,&local_10,(short *)local_e);
  iVar3 = 0;
  iVar2 = 0;
  sVar1 = sVar1 - (short)((int)(((int)((uint)local_e[0] << 0x10) >> 0x10) +
                               (((uint)local_e[0] << 0x10) >> 0x1f)) >> 1);
  sVar4 = sVar1 + local_e[0];
  do {
    *(undefined2 *)((int)&DAT_800b3d94 + iVar2) = 10;
    *(undefined2 *)((int)&DAT_800b3da4 + iVar2) = 10;
    *(short *)((int)&DAT_800b3d96 + iVar2) = sVar1;
    *(short *)((int)&DAT_800b3d9c + iVar2) = local_10 + 10;
    *(short *)((int)&DAT_800b3d9e + iVar2) = sVar1;
    *(short *)((int)&DAT_800b3da6 + iVar2) = sVar4;
    *(short *)((int)&DAT_800b3dac + iVar2) = local_10 + 10;
    *(short *)((int)&DAT_800b3dae + iVar2) = sVar4;
    iVar3 = iVar3 + 1;
    *(undefined2 *)((int)&DAT_800b3dbc + iVar2) = 0x127;
    *(short *)((int)&DAT_800b3dbe + iVar2) = sVar1;
    *(short *)((int)&DAT_800b3dc4 + iVar2) = local_10 + 0x127;
    *(short *)((int)&DAT_800b3dc6 + iVar2) = sVar1;
    *(undefined2 *)((int)&DAT_800b3dcc + iVar2) = 0x127;
    *(short *)((int)&DAT_800b3dce + iVar2) = sVar4;
    *(short *)((int)&DAT_800b3dd4 + iVar2) = local_10 + 0x127;
    *(short *)((int)&DAT_800b3dd6 + iVar2) = sVar4;
    iVar2 = iVar2 + 0x50;
  } while (iVar3 < 2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_MoveHelp(short valx /*$a0*/)
 // line 769, offset 0x80084820
	/* begin block 1 */
		// Start line: 770
		// Start offset: 0x80084820
		// Variables:
	// 		long i; // $s1
	// 		long j; // $s3
	// 		short w; // stack offset -40
	// 		short h; // stack offset -38
	// 		short *pTabShapes; // $v0
	// 		short borne; // $s5
	// 		struct INVENTRY_70fake shp; // stack offset -56
	/* end block 1 */
	// End offset: 0x800849DC
	// End Line: 824

	/* begin block 2 */
		// Start line: 1879
	/* end block 2 */
	// End Line: 1880

void Invent_MoveHelp(short valx)

{
  short *psVar1;
  ushort *puVar2;
  _struct_689 *prim;
  int iVar3;
  int iVar4;
  _struct_689 *p_Var5;
  SHAPE_68fake local_38;
  ushort local_28;
  ushort local_26 [3];
  
  Inventaire.helpx = valx + -100;
  local_38.file = Effects_Pcl;
  if (Inventaire.mode == '\0') {
    local_38.y = 0x4b;
    psVar1 = &Invent_ObjHelpShapes;
  }
  else {
    local_38.y = 0x7d;
    psVar1 = Invent_SpellHelpShapes;
  }
  iVar4 = 0;
  p_Var5 = &Inventaire.help;
  local_38.x = Inventaire.helpx;
  do {
    if ((iVar4 == 0) && (iVar3 = 0, puVar2 = &Invent_SpellKeys, Inventaire.mode == '\0')) {
      do {
        if (PJOY_SPELL == *puVar2) {
          local_38.shape = *psVar1 + (short)iVar3;
        }
        iVar3 = iVar3 + 1;
        puVar2 = puVar2 + 1;
      } while (iVar3 < 4);
    }
    else {
      local_38.shape = *psVar1;
    }
    Shp_GetWH(&local_38,(short *)&local_28,(short *)local_26);
    iVar3 = 0;
    prim = p_Var5;
    do {
      iVar3 = iVar3 + 1;
      Shp_SetPolyFT4((SHAPE_31fake *)prim,&local_38,(short)(((uint)local_28 + 1) * 0x10000 >> 0x10),
                     (short)(((uint)local_26[0] + 1) * 0x10000 >> 0x10));
      ((SHAPE_31fake *)prim)->u1 = ((SHAPE_31fake *)prim)->u1 + '\x01';
      ((SHAPE_31fake *)prim)->u3 = ((SHAPE_31fake *)prim)->u3 + '\x01';
      ((SHAPE_31fake *)prim)->v2 = ((SHAPE_31fake *)prim)->v2 + '\x01';
      ((SHAPE_31fake *)prim)->v3 = ((SHAPE_31fake *)prim)->v3 + '\x01';
      prim = (_struct_689 *)((SHAPE_31fake *)prim + 4);
    } while (iVar3 < 2);
    p_Var5 = p_Var5 + 1;
    iVar4 = iVar4 + 1;
    local_38.x = local_38.x + psVar1[1];
    local_38.y = local_38.y + psVar1[2];
    psVar1 = psVar1 + 3;
  } while (iVar4 < 4);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_Display()
 // line 833, offset 0x80084a04
	/* begin block 1 */
		// Start line: 834
		// Start offset: 0x80084A04
		// Variables:
	// 		struct INVENTRY_5fake Save_Matrix; // stack offset -40
	// 		struct _INVENT_LIST *l; // $s0
	/* end block 1 */
	// End offset: 0x80084CB8
	// End Line: 873

	/* begin block 2 */
		// Start line: 2116
	/* end block 2 */
	// End Line: 2117

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Invent_Display(void)

{
  byte bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  _SCREEN *p_Var10;
  uint uVar11;
  uint *puVar12;
  uint uVar13;
  int iVar14;
  
  lVar9 = Cam_Matrix.t[2];
  lVar8 = Cam_Matrix.t[1];
  lVar7 = Cam_Matrix.t[0];
  uVar6 = Cam_Matrix._16_4_;
  uVar5 = Cam_Matrix.m[2]._0_4_;
  uVar4 = Cam_Matrix.m[1]._2_4_;
  uVar3 = Cam_Matrix.m._4_4_;
  uVar2 = Cam_Matrix.m[0]._0_4_;
  uVar11 = (uint)(byte)Inventaire.mode;
  if ((_DAT_800b1c56 & 8) == 0) {
    if (Inventaire.mode == '\0') {
      Invent_ObjectDisplay();
    }
    else {
      Invent_SpellDisplay();
    }
    bVar1 = Inventaire.inv_list[uVar11].deb_list;
    if (bVar1 != 0) {
      if (Inventaire.inv_list[uVar11].nb_obj != '\0') {
        Invent_DisplayArrow(0);
      }
      bVar1 = Inventaire.inv_list[uVar11].deb_list;
    }
    if ((uint)bVar1 + 5 < (uint)(byte)Inventaire.inv_list[uVar11].nb_obj) {
      Invent_DisplayArrow(1);
    }
    p_Var10 = Scr;
    iVar14 = (int)Scr_Frame;
    uVar13 = (uint)(ushort)Scr_W;
    puVar12 = (uint *)(&DAT_800b3e7c + iVar14 * 0x10);
    *puVar12 = *puVar12 & 0xff000000 | Scr->ot[1] & 0xffffff;
    p_Var10->ot[1] = p_Var10->ot[1] & 0xff000000 | (uint)puVar12 & 0xffffff;
    puVar12 = (uint *)(&DAT_800b3ecc + iVar14 * 0x18);
    *puVar12 = *puVar12 & 0xff000000 | p_Var10->ot[1] & 0xffffff;
    p_Var10->ot[1] = p_Var10->ot[1] & 0xff000000 | (uint)puVar12 & 0xffffff;
    puVar12 = (uint *)(&DAT_800b3efc + iVar14 * 8);
    *puVar12 = *puVar12 & 0xff000000 | p_Var10->ot[1] & 0xffffff;
    uVar11 = (uint)(ushort)Scr_H;
    p_Var10->ot[1] = p_Var10->ot[1] & 0xff000000 | (uint)puVar12 & 0xffffff;
    SetGeomOffset((int)(((int)(uVar13 << 0x10) >> 0x10) + ((uVar13 << 0x10) >> 0x1f)) >> 1,
                  (int)(((int)(uVar11 << 0x10) >> 0x10) + ((uVar11 << 0x10) >> 0x1f)) >> 1);
    setCopControlWord(2,0,uVar2);
    setCopControlWord(2,0x800,uVar3);
    setCopControlWord(2,0x1000,uVar4);
    setCopControlWord(2,0x1800,uVar5);
    setCopControlWord(2,0x2000,uVar6);
    setCopControlWord(2,0x2800,lVar7);
    setCopControlWord(2,0x3000,lVar8);
    setCopControlWord(2,0x3800,lVar9);
  }
  Cam_Matrix.m[0]._0_4_ = uVar2;
  Cam_Matrix.m._4_4_ = uVar3;
  Cam_Matrix.m[1]._2_4_ = uVar4;
  Cam_Matrix.m[2]._0_4_ = uVar5;
  Cam_Matrix._16_4_ = uVar6;
  Cam_Matrix.t[0] = lVar7;
  Cam_Matrix.t[1] = lVar8;
  Cam_Matrix.t[2] = lVar9;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_DisplayButtons()
 // line 876, offset 0x80084cc8
	/* begin block 1 */
		// Start line: 879
		// Start offset: 0x80084CC8
		// Variables:
	// 		long i; // $t1
	/* end block 1 */
	// End offset: 0x80084D54
	// End Line: 884

	/* begin block 2 */
		// Start line: 2238
	/* end block 2 */
	// End Line: 2239

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Invent_DisplayButtons(void)

{
  _SCREEN *p_Var1;
  int iVar2;
  ulong *puVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  p_Var1 = Scr;
  iVar7 = 0;
  iVar8 = -0x7ff4c3b4;
  iVar2 = (int)Scr_Frame;
  iVar6 = iVar2 * 0xa0;
  do {
    uVar5 = iVar2 * 0xa0 + iVar8;
    iVar8 = iVar8 + 0x28;
    puVar4 = (uint *)((int)&Inventaire.help.tag + iVar6);
    *puVar4 = *puVar4 & 0xff000000 | p_Var1->ot[1] & 0xffffff;
    puVar3 = p_Var1->ot;
    iVar7 = iVar7 + 1;
    puVar3[1] = puVar3[1] & 0xff000000 | uVar5 & 0xffffff;
    iVar6 = iVar6 + 0x28;
  } while (iVar7 < 4);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_DisplayArrow(long arrow /*$a0*/)
 // line 887, offset 0x80084d5c
	/* begin block 1 */
		// Start line: 889
		// Start offset: 0x80084D5C
		// Variables:
	// 		struct INVENTRY_31fake *p; // $a1
	/* end block 1 */
	// End offset: 0x80084D5C
	// End Line: 892

	/* begin block 2 */
		// Start line: 2263
	/* end block 2 */
	// End Line: 2264

void Invent_DisplayArrow(long arrow)

{
  uchar uVar1;
  _SCREEN *p_Var2;
  uint *puVar3;
  
  uVar1 = Shift_Col;
  puVar3 = (uint *)(&DAT_800b3d8c + (int)Scr_Frame * 0x50 + arrow * 0x28);
  *(undefined *)((int)puVar3 + 5) = 0x80;
  *(undefined *)((int)puVar3 + 6) = 0x80;
  *(uchar *)(puVar3 + 1) = uVar1;
  p_Var2 = Scr;
  *puVar3 = *puVar3 & 0xff000000 | Scr->ot[1] & 0xffffff;
  p_Var2->ot[1] = p_Var2->ot[1] & 0xff000000 | (uint)puVar3 & 0xffffff;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_ObjectDisplay()
 // line 896, offset 0x80084df0
	/* begin block 1 */
		// Start line: 897
		// Start offset: 0x80084DF0
		// Variables:
	// 		struct _INVENT_LIST *l; // $s3
	// 		long i; // $s0
	// 		long borne; // $s6
	// 		char str[50]; // stack offset -96
	// 		void *otl; // $s4

		/* begin block 1.1 */
			// Start line: 897
			// Start offset: 0x80084DF0
		/* end block 1.1 */
		// End offset: 0x80084DF0
		// End Line: 897

		/* begin block 1.2 */
			// Start line: 972
			// Start offset: 0x80084F5C
		/* end block 1.2 */
		// End offset: 0x80084F88
		// End Line: 975

		/* begin block 1.3 */
			// Start line: 987
			// Start offset: 0x80084FF4
			// Variables:
		// 		struct _INV_OBJECT *invo; // $s2
		// 		struct _TAKEN_OBJECT *to; // $s1
		/* end block 1.3 */
		// End offset: 0x80085130
		// End Line: 1018
	/* end block 1 */
	// End offset: 0x80085194
	// End Line: 1024

	/* begin block 2 */
		// Start line: 2281
	/* end block 2 */
	// End Line: 2282

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Invent_ObjectDisplay(void)

{
  short sVar1;
  void *otl;
  _SCREEN *p_Var2;
  uint uVar3;
  uint uVar4;
  char *text;
  _TAKEN_OBJECT *to;
  short *psVar5;
  _INVENT_LIST *p_Var6;
  int iVar7;
  uint uVar8;
  char acStack96 [56];
  
  uVar3 = (uint)(byte)Inventaire.mode;
  p_Var6 = Inventaire.inv_list + uVar3;
  Invent_DisplayButtons();
  Invent_SPRINT_AB(acStack96,0x4a,0x4b,0);
  Text_SetText(acStack96,(short)(((uint)(ushort)Inventaire.helpx + 0x23) * 0x10000 >> 0x10),0x50);
  strcpy(acStack96,(char *)Pvl_UtilityTexts[0x49]);
  Text_SetText(acStack96,(short)(((uint)(ushort)Inventaire.helpx + 0x23) * 0x10000 >> 0x10),0x5f);
  if (SHIFT_STATS == 0) {
    Text_SetText((char *)Pvl_UtilityTexts[0xd],
                 (short)(((uint)(ushort)Inventaire.helpx + 0x23) * 0x10000 >> 0x10),0x73);
    text = (char *)Pvl_UtilityTexts[0xe];
  }
  else {
    Text_SetText((char *)Pvl_UtilityTexts[0xb],
                 (short)(((uint)(ushort)Inventaire.helpx + 0x23) * 0x10000 >> 0x10),0x73);
    text = (char *)Pvl_UtilityTexts[0xc];
  }
  Text_SetText(text,(short)(((uint)(ushort)Inventaire.helpx + 0x23) * 0x10000 >> 0x10),0x89);
  otl = Main_Prims;
  if ((p_Var6->nb_obj == '\0') && (Cpt_Alert == 0)) {
    sprintf(acStack96,(char *)&PTR_DAT_800ad9ec,Pvl_UtilityTexts[0xf]);
    Invent_Alert(acStack96,0);
  }
  else {
    Main_Prims = (void *)((int)Main_Prims + 0x400);
    ClearOTagR((undefined4 *)otl);
    uVar4 = (uint)(byte)Inventaire.inv_list[uVar3].deb_list + 5;
    uVar8 = (uint)(byte)p_Var6->nb_obj;
    if (uVar4 < (uint)(byte)p_Var6->nb_obj) {
      uVar8 = uVar4;
    }
    SetGeomScreen(0x80);
    uVar4 = (uint)(byte)Inventaire.inv_list[uVar3].deb_list;
    if (uVar4 < uVar8) {
      iVar7 = uVar4 * 10 + 4;
      do {
        psVar5 = (short *)(&p_Var6->nb_obj + iVar7);
        sVar1 = *psVar5;
        to = (_TAKEN_OBJECT *)((int)Pvl_TakenObjects + (int)sVar1 * 0xb0);
        Invent_SetCamera((_D3_OBJECT *)to,6);
        *(short *)((int)Pvl_TakenObjects + (int)sVar1 * 0xb0 + 0x40) = psVar5[1];
        SetGeomOffset((int)Inventaire.posx +
                      (uVar4 - (uint)(byte)Inventaire.inv_list[uVar3].deb_list) * 0x35 + 0x19,
                      (int)Inventaire.posy + -10);
        Main_Prims = Invent_DisplayTmd(to,otl,Main_Prims,
                                       (uint)(uVar4 == (uint)(byte)Inventaire.inv_list[uVar3].hilite
                                             ));
        sprintf(acStack96,(char *)&PTR_DAT_800ada30,(uint)*(byte *)(psVar5 + 2));
        Text_SetText(acStack96,
                     (short)(((uint)(ushort)Inventaire.posx +
                             (uVar4 - (uint)(byte)Inventaire.inv_list[uVar3].deb_list) * 0x35 + 5) *
                             0x10000 >> 0x10),
                     (short)(((uint)(ushort)Inventaire.posy + 5) * 0x10000 >> 0x10));
        if (uVar4 == (uint)(byte)Inventaire.inv_list[uVar3].hilite) {
          psVar5[1] = psVar5[1] + -0x23;
          Invent_DisplayObjectName(to,(short)uVar4);
        }
        uVar4 = uVar4 + 1;
        iVar7 = iVar7 + 10;
      } while ((int)uVar4 < (int)uVar8);
    }
    SetGeomScreen(0x100);
    p_Var2 = Scr;
    *(uint *)otl = *(uint *)otl & 0xff000000 | Scr->ot[1] & 0xffffff;
    p_Var2->ot[1] = p_Var2->ot[1] & 0xff000000 | (int)otl + 0x3fcU & 0xffffff;
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Invent_IsNameFemale(char *str /*$s0*/)
 // line 1027, offset 0x800851c0
	/* begin block 1 */
		// Start line: 1028
		// Start offset: 0x800851C0
		// Variables:
	// 		static char *c; // offset 0x800b3160
	/* end block 1 */
	// End offset: 0x800851F8
	// End Line: 1040

	/* begin block 2 */
		// Start line: 2581
	/* end block 2 */
	// End Line: 2582

long Invent_IsNameFemale(char *str)

{
  char cVar1;
  size_t sVar2;
  
  sVar2 = strlen(str);
  str = str + sVar2;
  c_32 = str + -1;
  cVar1 = str[-1];
  if (cVar1 == '$') {
    str[-1] = '\0';
  }
  return (uint)(cVar1 == '$');
}



// decompiled code
// original method signature: 
// long /*$ra*/ Invent_SPRINT_A(char *name /*$s0*/, char *str /*$a1*/, long A /*$a2*/)
 // line 1043, offset 0x80085208
	/* begin block 1 */
		// Start line: 1044
		// Start offset: 0x80085208
	/* end block 1 */
	// End offset: 0x80085250
	// End Line: 1051

	/* begin block 2 */
		// Start line: 2613
	/* end block 2 */
	// End Line: 2614

long Invent_SPRINT_A(char *name,char *str,long A)

{
  long lVar1;
  
  if (str == (char *)0x0) {
    sprintf(name,(char *)&PTR_DAT_800ad9ec,Pvl_UtilityTexts[A]);
  }
  else {
    strcpy(name,str);
  }
  lVar1 = Invent_IsNameFemale(name);
  return lVar1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Invent_SPRINT_AB(char *str /*$s4*/, long A /*$a1*/, long B /*$s0*/, long Invert /*$s2*/)
 // line 1055, offset 0x80085268
	/* begin block 1 */
		// Start line: 1056
		// Start offset: 0x80085268
		// Variables:
	// 		char str1[40]; // stack offset -104
	// 		char str2[40]; // stack offset -64
	/* end block 1 */
	// End offset: 0x80085320
	// End Line: 1071

	/* begin block 2 */
		// Start line: 2637
	/* end block 2 */
	// End Line: 2638

long Invent_SPRINT_AB(char *str,long A,long B,long Invert)

{
  char *pcVar1;
  char *__s;
  char acStack104 [40];
  char acStack64 [40];
  
  sprintf(acStack104,(char *)&PTR_DAT_800ad9ec,Pvl_UtilityTexts[A]);
  Invent_IsNameFemale(acStack104);
  __s = acStack64;
  sprintf(__s,(char *)&PTR_DAT_800ad9ec,Pvl_UtilityTexts[B]);
  Invent_IsNameFemale(__s);
  if (Invert == 0) {
    pcVar1 = acStack104;
  }
  else {
    pcVar1 = __s;
    __s = acStack104;
  }
  sprintf(str,s__s__s_800ad9f0,pcVar1,__s);
  return 0;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Invent_D3GetName(struct _D3_OBJECT *o /*$s3*/, struct _TAKEN_OBJECT *to /*$a1*/, char *name /*$s1*/)
 // line 1075, offset 0x80085344
	/* begin block 1 */
		// Start line: 1076
		// Start offset: 0x80085344
		// Variables:
	// 		long Sexe; // $s0
	// 		char *string; // $s2

		/* begin block 1.1 */
			// Start line: 1084
			// Start offset: 0x80085380
			// Variables:
		// 		long *text_array; // $v1
		/* end block 1.1 */
		// End offset: 0x80085384
		// End Line: 1086

		/* begin block 1.2 */
			// Start line: 1097
			// Start offset: 0x800853C0
			// Variables:
		// 		long i; // $a0
		// 		struct _TAKEN_OBJECT *to2; // $v0

			/* begin block 1.2.1 */
				// Start line: 1112
				// Start offset: 0x800853F8
				// Variables:
			// 		long *text_array; // $v1
			/* end block 1.2.1 */
			// End offset: 0x80085424
			// End Line: 1115
		/* end block 1.2 */
		// End offset: 0x80085424
		// End Line: 1116
	/* end block 1 */
	// End offset: 0x80085860
	// End Line: 1289

	/* begin block 2 */
		// Start line: 2684
	/* end block 2 */
	// End Line: 2685

/* WARNING: Type propagation algorithm not settling */

long Invent_D3GetName(_D3_OBJECT *o,_TAKEN_OBJECT *to,char *name)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  _TAKEN_OBJECT *p_Var6;
  long *plVar7;
  char **ppcVar8;
  short crc;
  long A;
  char *str;
  
  A = 0;
  iVar5 = (int)*(short *)((int)&o[1].prec + 2);
  str = (char *)0x0;
  if (-1 < iVar5) {
    if (to == (_TAKEN_OBJECT *)0x0) {
      if (Pvl_Texts != (long *)0x0) {
        ppcVar8 = (char **)(Pvl_Texts + iVar5);
        goto LAB_80085420;
      }
      if (*(undefined **)&o[1].last_pos == &DAT_00001234) {
        p_Var6 = Pvl_TakenObjects;
        if ((_TAKEN_OBJECT *)o != Pvl_TakenObjects) {
          iVar5 = 1;
          do {
            p_Var6 = (_TAKEN_OBJECT *)&p_Var6[1].obj.last_pos.vz;
            if (iVar5 == 0x20) {
              p_Var6 = (_TAKEN_OBJECT *)0x0;
              break;
            }
            iVar5 = iVar5 + 1;
          } while (p_Var6 != (_TAKEN_OBJECT *)o);
        }
        if (p_Var6 != (_TAKEN_OBJECT *)0x0) {
          crc = p_Var6[1].obj.last_pos.vx;
          goto LAB_800853fc;
        }
      }
    }
    else {
      crc = to[1].obj.last_pos.vx;
LAB_800853fc:
      plVar7 = Pvl_GetSectorText(crc);
      if (plVar7 != (long *)0x0) {
        ppcVar8 = (char **)(plVar7 + (int)*(short *)((int)&o[1].prec + 2));
LAB_80085420:
        str = *ppcVar8;
      }
    }
  }
  cVar4 = s_Socle_800ada3c[5];
  cVar3 = s_Socle_800ada3c[4];
  cVar2 = DAT_800ada39;
  cVar1 = DAT_800ada38;
  switch(o[1].pos.vy) {
  case 0:
    str = (char *)0x0;
    A = 0x10;
    break;
  case 1:
    str = (char *)0x0;
    A = 0x11;
    break;
  case 2:
    crc = o[1].pos.vz;
    if (crc == 1) {
      A = Invent_SPRINT_AB(name,0x12,0x16,0);
      return A;
    }
    if (crc < 2) {
      if (crc != 0) {
        return 0;
      }
      A = Invent_SPRINT_AB(name,0x12,0x15,0);
      return A;
    }
    if (crc == 2) {
      A = Invent_SPRINT_AB(name,0x12,0x17,0);
      return A;
    }
    if (crc != 3) {
      return 0;
    }
    A = Invent_SPRINT_AB(name,0x12,0x18,0);
    return A;
  case 3:
    crc = o[1].pos.vz;
    if (crc == 1) {
      A = Invent_SPRINT_AB(name,0x13,0x16,0);
      return A;
    }
    if (crc < 2) {
      if (crc != 0) {
        return 0;
      }
      A = Invent_SPRINT_AB(name,0x13,0x15,0);
      return A;
    }
    if (crc == 2) {
      A = Invent_SPRINT_AB(name,0x13,0x17,0);
      return A;
    }
    if (crc != 3) {
      return 0;
    }
    A = Invent_SPRINT_AB(name,0x13,0x18,0);
    return A;
  case 4:
    crc = o[1].pos.vz;
    if (crc == 1) {
      A = Invent_SPRINT_AB(name,0x4b,0x1a,0);
      return A;
    }
    if (crc < 2) {
      if (crc != 0) {
        return 0;
      }
      A = Invent_SPRINT_AB(name,0x4b,0x19,0);
      return A;
    }
    if (crc == 2) {
      A = Invent_SPRINT_AB(name,0x4b,0x1b,0);
      return A;
    }
    if (crc != 3) {
      return 0;
    }
    A = Invent_SPRINT_AB(name,0x4b,0x1c,0);
    return A;
  case 5:
    str = (char *)0x0;
    A = 0x1d;
    break;
  case 6:
    str = (char *)0x0;
    A = 0x1e;
    break;
  case 7:
  case 8:
  case 9:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0x15:
    A = 0x24;
    break;
  case 0xf:
    str = (char *)0x0;
    A = 0x2a;
    break;
  case 0x10:
    str = (char *)0x0;
    A = 0x1f;
    break;
  case 0x11:
    crc = o[1].pos.vz;
    if (crc == 1) {
      A = Invent_SPRINT_AB(name,0x20,0x22,0);
      return A;
    }
    if (crc < 2) {
      if (crc != 0) {
        return 0;
      }
      A = Invent_SPRINT_AB(name,0x20,0x21,0);
      return A;
    }
    if (crc != 2) {
      return 0;
    }
    A = Invent_SPRINT_AB(name,0x20,0x14,0);
    return A;
  case 0x12:
    A = 0x23;
    break;
  case 0x13:
    str = (char *)0x0;
    A = 0x26;
    break;
  case 0x14:
    if (o[1].pos.pad == 1) {
      *(undefined4 *)name = DAT_800ada34;
      name[4] = cVar1;
      name[5] = cVar2;
      name[6] = DAT_800ada3a;
      return 0;
    }
    *(undefined4 *)name = s_Socle_800ada3c._0_4_;
    name[4] = cVar3;
    name[5] = cVar4;
    return 0;
  case 0x16:
    A = 0x23;
    break;
  case 0x17:
    str = (char *)0x0;
    A = 0x25;
    break;
  case 0x18:
    A = 0x27;
    break;
  case 0x19:
    str = (char *)0x0;
    A = 0x29;
    break;
  case 0x1a:
    str = (char *)0x0;
    A = 0x28;
    break;
  case 0x1b:
    str = (char *)0x0;
    A = 0x2b;
    break;
  default:
    goto switchD_8008544c_caseD_1c;
  }
  A = Invent_SPRINT_A(name,str,A);
switchD_8008544c_caseD_1c:
  return A;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_DisplayObjectName(struct _TAKEN_OBJECT *to /*$s0*/, short index /*$a1*/)
 // line 1293, offset 0x80085880
	/* begin block 1 */
		// Start line: 1294
		// Start offset: 0x80085880
		// Variables:
	// 		struct _INVENT_LIST *l; // $a0
	// 		char str[50]; // stack offset -64
	/* end block 1 */
	// End offset: 0x80085880
	// End Line: 1294

	/* begin block 2 */
		// Start line: 3132
	/* end block 2 */
	// End Line: 3133

void Invent_DisplayObjectName(_TAKEN_OBJECT *to,short index)

{
  char acStack64 [56];
  
  Text_SetContextXY((short)(((uint)(ushort)Inventaire.posx +
                             ((int)index - (uint)(byte)Inventaire.inv_list[0].deb_list) * 0x35 +
                            0x14) * 0x10000 >> 0x10),0);
  Text_SetContextWH(10,Scr_H);
  Invent_D3GetName((_D3_OBJECT *)to,to,acStack64);
  Text_SetText(acStack64,-0x7ffe,(short)(((uint)(ushort)Inventaire.posy - 0x21) * 0x10000 >> 0x10));
  Text_SetContextXY(0,0);
  Text_SetContextWH(Scr_W,Scr_H);
  return;
}



// decompiled code
// original method signature: 
// void * /*$ra*/ Invent_DisplayTmd(struct _TAKEN_OBJECT *to /*$s6*/, void *otl /*stack 4*/, void *Prims /*$s4*/, long hilite /*$s0*/)
 // line 1310, offset 0x8008594c
	/* begin block 1 */
		// Start line: 1311
		// Start offset: 0x8008594C
		// Variables:
	// 		struct INVENTRY_5fake mr; // stack offset -176
	// 		struct INVENTRY_5fake ml; // stack offset -144
	// 		struct INVENTRY_5fake ms; // stack offset -112
	// 		struct INVENTRY_5fake mn64; // stack offset -80
	// 		struct INVENTRY_7fake ang; // stack offset -48
	// 		struct _D3_OBJECT *obj; // $s7
	// 		struct INVENTRY_93fake *tmd; // $a0
	// 		long col; // $fp
	// 		long dispmode; // $s5

		/* begin block 1.1 */
			// Start line: 1339
			// Start offset: 0x80085A74
			// Variables:
		// 		long i; // $s0
		// 		long n; // $s3
		// 		long value; // $s2
		/* end block 1.1 */
		// End offset: 0x80085AF0
		// End Line: 1355
	/* end block 1 */
	// End offset: 0x80085B18
	// End Line: 1362

	/* begin block 2 */
		// Start line: 3172
	/* end block 2 */
	// End Line: 3173

void * Invent_DisplayTmd(_TAKEN_OBJECT *to,void *otl,void *Prims,long hilite)

{
  short sVar1;
  undefined4 in_zero;
  undefined4 in_at;
  int iVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  uint dispmode;
  undefined *col;
  ushort auStack176 [10];
  int local_9c;
  int local_98;
  int local_94;
  undefined4 local_30;
  undefined4 local_2c;
  
  memset(&local_30,0,8);
  col = &DAT_00404040;
  dispmode = SEXT24((to->obj).display_mode);
  if (hilite != 0) {
    col = (undefined *)0xa0a0a0;
  }
  setCopReg(2,in_zero,local_30);
  setCopReg(2,in_at,local_2c);
  copFunction(2,0x486012);
  local_9c = getCopReg(2,0x19);
  local_98 = getCopReg(2,0x1a);
  local_94 = getCopReg(2,0x1b);
  local_9c = local_9c + Cam_Matrix.t[0];
  local_98 = local_98 + Cam_Matrix.t[1];
  local_94 = local_94 + Cam_Matrix.t[2];
  setCopControlWord(2,0x2800,local_9c);
  setCopControlWord(2,0x3000,local_98);
  setCopControlWord(2,0x3800,local_94);
  RotMatrix((short *)&(to->obj).rot,auStack176);
  SetMulMatrix((undefined4 *)&Cam_Matrix,auStack176);
  if ((dispmode & 4) != 0) {
    Invent_SetLightMatrices((char)auStack176);
  }
  uVar4 = 1;
  if ((dispmode & 0x1000) == 0) {
    Prims = Invent_GtxTmd((char)(to->obj).description,dispmode,0xb0,otl,(long)col,Prims);
  }
  else {
    iVar5 = (int)*(short *)((int)(to->obj).description + 8);
    iVar2 = 0;
    if (0 < iVar5) {
      cVar3 = '\f';
      do {
        sVar1 = *(short *)&to[1].obj.hit_power;
        if (((sVar1 != 0x17) && (sVar1 != 0x14)) || (((int)to[1].obj.pos.pad & uVar4) != 0)) {
          Prims = Invent_GtxTmd((char)(to->obj).description + cVar3,dispmode,0xb0,otl,(long)col,
                                Prims);
        }
        cVar3 = cVar3 + '\x1c';
        iVar2 = iVar2 + 1;
        uVar4 = uVar4 << 1;
      } while (iVar2 < iVar5);
    }
  }
  return Prims;
}



// decompiled code
// original method signature: 
// void * /*$ra*/ Invent_GtxTmd(struct INVENTRY_93fake *tmd /*$s1*/, long dispmode /*$a1*/, struct INVENTRY_5fake *mn64 /*$a2*/, void *otl /*$s2*/, long col /*stack 16*/, void *Prims /*stack 20*/)
 // line 1366, offset 0x80085b4c
	/* begin block 1 */
		// Start line: 1367
		// Start offset: 0x80085B4C
		// Variables:
	// 		long neutral; // stack offset -24
	/* end block 1 */
	// End offset: 0x80085BD8
	// End Line: 1380

	/* begin block 2 */
		// Start line: 3301
	/* end block 2 */
	// End Line: 3302

void * Invent_GtxTmd(undefined tmd,long dispmode,undefined1 mn64,void *otl,long col,void *Prims)

{
  undefined3 in_register_00000011;
  void *pvVar1;
  
  if ((dispmode & 4U) == 0) {
    Tmd_ChangeColor(tmd,0x10);
    pvVar1 = (void *)GtxTmd_DisplayLOFF(CONCAT31(in_register_00000011,tmd),Prims,otl,0x100,0);
    Tmd_ChangeColor(tmd,0xe8);
  }
  else {
    pvVar1 = (void *)GtxTmd_DisplayLON(CONCAT31(in_register_00000011,tmd),Prims,otl,0x100,0,col,
                                       0x808080);
  }
  return pvVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_SetLightMatrices(struct INVENTRY_5fake *mr /*$a0*/)
 // line 1384, offset 0x80085bf4
	/* begin block 1 */
		// Start line: 1385
		// Start offset: 0x80085BF4
		// Variables:
	// 		struct INVENTRY_5fake ml; // stack offset -96
	// 		struct INVENTRY_5fake ms; // stack offset -64
	// 		struct INVENTRY_5fake matrix; // stack offset -32
	/* end block 1 */
	// End offset: 0x80085BF4
	// End Line: 1385

	/* begin block 2 */
		// Start line: 3342
	/* end block 2 */
	// End Line: 3343

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Invent_SetLightMatrices(undefined mr)

{
  undefined3 in_register_00000011;
  ushort *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  undefined4 uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  uint local_5c;
  uint local_50;
  
  puVar1 = (ushort *)CONCAT31(in_register_00000011,mr);
  uVar2 = getCopControlWord(2,0);
  uVar7 = getCopControlWord(2,0x800);
  uVar3 = getCopControlWord(2,0x1000);
  uVar8 = getCopControlWord(2,0x1800);
  uVar12 = getCopControlWord(2,0x2000);
  getCopControlWord(2,0x2800);
  getCopControlWord(2,0x3000);
  getCopControlWord(2,0x3800);
  setCopControlWord(2,0,light_m.m[0]._0_4_);
  setCopControlWord(2,0x800,light_m.m._4_4_);
  setCopControlWord(2,0x1000,light_m.m[1]._2_4_);
  setCopControlWord(2,0x1800,light_m.m[2]._0_4_);
  setCopControlWord(2,0x2000,light_m._16_4_);
  setCopReg(2,0x4800,(uint)*puVar1);
  setCopReg(2,0x5000,(uint)puVar1[3]);
  setCopReg(2,0x5800,(uint)puVar1[6]);
  copFunction(2,0x49e012);
  uVar4 = getCopReg(2,0x4800);
  iVar9 = getCopReg(2,0x5000);
  uVar13 = getCopReg(2,0x5800);
  setCopReg(2,0x4800,(uint)puVar1[1]);
  setCopReg(2,0x5000,(uint)puVar1[4]);
  setCopReg(2,0x5800,(uint)puVar1[7]);
  copFunction(2,0x49e012);
  iVar5 = getCopReg(2,0x4800);
  uVar10 = getCopReg(2,0x5000);
  iVar14 = getCopReg(2,0x5800);
  setCopReg(2,0x4800,(uint)puVar1[2]);
  setCopReg(2,0x5000,(uint)puVar1[5]);
  setCopReg(2,0x5800,(uint)puVar1[8]);
  copFunction(2,0x49e012);
  uVar6 = getCopReg(2,0x4800);
  iVar11 = getCopReg(2,0x5000);
  uVar15 = getCopReg(2,0x5800);
  local_5c = uVar6 & 0xffff | iVar9 << 0x10;
  local_50 = local_50 & 0xffff0000 | uVar15 & 0xffff;
  setCopControlWord(2,0x4000,uVar4 & 0xffff | iVar5 << 0x10);
  setCopControlWord(2,0x4800,local_5c);
  setCopControlWord(2,0x5000,uVar10 & 0xffff | iVar11 << 0x10);
  setCopControlWord(2,0x5800,uVar13 & 0xffff | iVar14 << 0x10);
  setCopControlWord(2,0x6000,local_50);
  setCopControlWord(2,0,uVar2);
  setCopControlWord(2,0x800,uVar7);
  setCopControlWord(2,0x1000,uVar3);
  setCopControlWord(2,0x1800,uVar8);
  setCopControlWord(2,0x2000,uVar12);
  setCopControlWord(2,0x8000,color_m.m[0]._0_4_);
  setCopControlWord(2,0x8800,color_m.m._4_4_);
  setCopControlWord(2,0x9000,color_m.m[1]._2_4_);
  setCopControlWord(2,0x9800,color_m.m[2]._0_4_);
  setCopControlWord(2,0xa000,color_m._16_4_);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_SetBoxCenter(struct _D3_OBJECT *obj /*$a2*/)
 // line 1398, offset 0x80085db8
	/* begin block 1 */
		// Start line: 1399
		// Start offset: 0x80085DB8
		// Variables:
	// 		struct INVENTRY_7fake *min; // $t1
	// 		struct INVENTRY_7fake *max; // $a0
	// 		long dumX; // $a3
	// 		long dumY; // $t2
	// 		long dumZ; // $t0
	/* end block 1 */
	// End offset: 0x80085EC0
	// End Line: 1424

	/* begin block 2 */
		// Start line: 3370
	/* end block 2 */
	// End Line: 3371

void Invent_SetBoxCenter(_D3_OBJECT *obj)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  short sVar6;
  
  uVar1 = (int)*(short *)((int)&obj[1].child + 2) - (int)obj->comp_opt3;
  iVar2 = (int)(uVar1 + (uVar1 >> 0x1f)) >> 1;
  if (iVar2 < 0) {
    iVar2 = -iVar2;
  }
  uVar1 = (int)*(short *)&obj[1].child - (int)obj->comp_opt2;
  iVar4 = (int)(uVar1 + (uVar1 >> 0x1f)) >> 1;
  if (iVar4 < 0) {
    iVar4 = -iVar4;
  }
  uVar1 = (int)*(short *)&obj[1].father - (int)*(short *)&obj->comp_opt4;
  iVar3 = (int)(uVar1 + (uVar1 >> 0x1f)) >> 1;
  if (iVar3 < 0) {
    iVar3 = -iVar3;
  }
  sVar6 = (short)iVar2;
  if (iVar2 < iVar4) {
    sVar6 = (short)iVar4;
  }
  (obj->pos).pad = sVar6;
  sVar5 = (short)iVar3;
  if (iVar3 < (int)sVar6) {
    sVar5 = sVar6;
  }
  (obj->pos).pad = sVar5;
  if (100 < sVar5) {
    sVar5 = 100;
  }
  sVar6 = obj[1].pos.vy;
  (obj->pos).pad = sVar5;
  if (sVar6 != 0x17) {
    (obj->pos).vx = obj->comp_opt2 + (short)iVar4;
    (obj->pos).vy = obj->comp_opt3 + (short)iVar2;
    (obj->pos).vz = *(short *)&obj->comp_opt4 + (short)iVar3;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_SetCamera(struct _D3_OBJECT *obj /*$s1*/, short dist /*$a1*/)
 // line 1427, offset 0x80085ec8
	/* begin block 1 */
		// Start line: 1428
		// Start offset: 0x80085EC8
		// Variables:
	// 		long coef; // $v1
	// 		struct INVENTRY_7fake Eye; // stack offset -32
	// 		struct INVENTRY_7fake Visee; // stack offset -24
	/* end block 1 */
	// End offset: 0x80085EC8
	// End Line: 1428

	/* begin block 2 */
		// Start line: 3431
	/* end block 2 */
	// End Line: 3432

void Invent_SetCamera(_D3_OBJECT *obj,short dist)

{
  short local_18;
  short local_16;
  short local_14;
  
  memset(&local_18,0,8);
  local_18 = (obj->pos).vx;
  local_16 = (obj->pos).vy;
  local_14 = (obj->pos).vz;
  Cam_SetMatrix(0xe0,(char)&local_18);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_Update(struct _PLAYER *pl /*$a0*/)
 // line 1445, offset 0x80085f58
	/* begin block 1 */
		// Start line: 1446
		// Start offset: 0x80085F58
		// Variables:
	// 		long i; // $s2
	// 		struct _TAKEN_OBJECT *to; // $s0
	// 		char *po; // $s3
	// 		struct _INVENT_LIST *l; // $s5
	// 		struct _INV_OBJECT *o; // $s4
	/* end block 1 */
	// End offset: 0x80086050
	// End Line: 1482

	/* begin block 2 */
		// Start line: 3484
	/* end block 2 */
	// End Line: 3485

void Invent_Update(_PLAYER *pl)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  short *psVar4;
  int iVar5;
  byte *pbVar6;
  _INV_OBJECT *p_Var7;
  
  p_Var7 = Inventaire.inv_list[0].list;
  Inventaire.inv_list[0].nb_obj = (pl->env2).Obj.primitive_top.Data[0x22];
  pbVar6 = (pl->env2).Obj.primitive_top.Data + 0x24;
  if (Inventaire.inv_list[0].nb_obj != 0) {
    iVar5 = 0;
    if (Inventaire.inv_list[0].nb_obj != 0) {
      psVar4 = &Inventaire.inv_list[0].list[0].text_crc;
      do {
        iVar5 = iVar5 + 1;
        bVar1 = *pbVar6;
        bVar2 = *pbVar6;
        pbVar6 = pbVar6 + 1;
        iVar3 = (uint)bVar1 * 0xb0;
        p_Var7->index = (ushort)bVar2;
        p_Var7 = p_Var7 + 1;
        *(undefined *)(psVar4 + -1) = *(undefined *)((int)Pvl_TakenObjects + iVar3 + 0xa5);
        *psVar4 = *(short *)((int)Pvl_TakenObjects + iVar3 + 0xac);
        Invent_SetBoxCenter((_D3_OBJECT *)((int)Pvl_TakenObjects + iVar3));
        *(undefined2 *)((int)Pvl_TakenObjects + iVar3 + 0x3c) = 0;
        *(undefined2 *)((int)Pvl_TakenObjects + iVar3 + 0x3e) = 0;
        *(undefined2 *)((int)Pvl_TakenObjects + iVar3 + 0x40) = 0;
        psVar4 = psVar4 + 5;
      } while (iVar5 < (int)(uint)(byte)Inventaire.inv_list[0].nb_obj);
    }
    if (Inventaire.inv_list[0].nb_obj == '\x01') {
      Inventaire.inv_list[0].hilite = '\0';
      Invent_MoveCadre();
    }
    Invent_SetTotalObjects();
    Invent_SortPlayerIndices();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_SetTotalObjects()
 // line 1485, offset 0x80086078
	/* begin block 1 */
		// Start line: 1487
		// Start offset: 0x80086078
		// Variables:
	// 		struct _TAKEN_OBJECT *to; // $a0
	// 		long i; // $v1
	/* end block 1 */
	// End offset: 0x800860B8
	// End Line: 1496

	/* begin block 2 */
		// Start line: 3593
	/* end block 2 */
	// End Line: 3594

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Invent_SetTotalObjects(void)

{
  int iVar1;
  _TAKEN_OBJECT *p_Var2;
  
  p_Var2 = Pvl_TakenObjects;
  Invent_NbObjects = 0;
  iVar1 = 0;
  do {
    if (-1 < p_Var2[1].obj.pos.vz) {
      Invent_NbObjects = Invent_NbObjects + 1;
    }
    iVar1 = iVar1 + 1;
    p_Var2 = (_TAKEN_OBJECT *)&p_Var2[1].obj.last_pos.vz;
  } while (iVar1 < 0x20);
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ Invent_AddObject(struct _PLAYER *pl /*$s2*/, struct _D3_OBJECT *obj /*$s1*/)
 // line 1503, offset 0x800860c0
	/* begin block 1 */
		// Start line: 1504
		// Start offset: 0x800860C0
		// Variables:
	// 		long i; // $v1
	// 		long index; // $s0
	// 		long value; // $v0
	// 		char str[50]; // stack offset -80
	// 		long FOUND; // $s3
	// 		struct INVENTRY_7fake *pos; // $v0
	// 		struct _TAKEN_OBJECT *to; // $a0

		/* begin block 1.1 */
			// Start line: 1518
			// Start offset: 0x80086108
		/* end block 1.1 */
		// End offset: 0x8008615C
		// End Line: 1545

		/* begin block 1.2 */
			// Start line: 1531
			// Start offset: 0x80086184
		/* end block 1.2 */
		// End offset: 0x800861A0
		// End Line: 1547
	/* end block 1 */
	// End offset: 0x80086414
	// End Line: 1632

	/* begin block 2 */
		// Start line: 3631
	/* end block 2 */
	// End Line: 3632

short Invent_AddObject(_PLAYER *pl,_D3_OBJECT *obj)

{
  char cVar1;
  ushort uVar2;
  bool bVar3;
  undefined uVar4;
  short sVar5;
  short sVar6;
  _D3_OBJECT *p_Var7;
  int iVar8;
  _TAKEN_OBJECT *p_Var9;
  int iVar10;
  _D3_OBJECT *p_Var11;
  _D3_OBJECT *p_Var12;
  _D3_OBJECT *p_Var13;
  long lVar14;
  char acStack80 [56];
  
  bVar3 = false;
  sVar5 = Invent_ObjectIsStored(pl,obj);
  sVar6 = 1;
  if (sVar5 == 0) {
    sVar5 = Invent_IsFull();
    if (sVar5 == 0) {
      Fx_Play(0x40,0);
      Pl_AddExperience(pl,obj);
      p_Var9 = Pvl_TakenObjects;
      iVar8 = 0;
      lVar14 = 0;
      do {
        if (((p_Var9[1].obj.pos.vy & 8U) == 0) && (p_Var9 == (_TAKEN_OBJECT *)obj)) {
          bVar3 = true;
          Task_Kill(obj->handle);
          uVar2 = obj[1].last_pos.pad;
          obj->handle = (TASK *)0x0;
          obj[1].last_pos.pad = uVar2 & 0xfffd;
          break;
        }
        iVar8 = iVar8 + 1;
        lVar14 = lVar14 + 1;
        p_Var9 = (_TAKEN_OBJECT *)&p_Var9[1].obj.last_pos.vz;
      } while (iVar8 < 0x20);
      if (!bVar3) {
        lVar14 = Invent_GetFreeTakenObject();
      }
      iVar8 = lVar14 * 0xb0;
      *(undefined2 *)((int)Pvl_TakenObjects + iVar8 + 0xa8) = 0;
      *(undefined2 *)((int)Pvl_TakenObjects + iVar8 + 0xaa) = 0;
      p_Var7 = obj;
      p_Var9 = (_TAKEN_OBJECT *)((int)Pvl_TakenObjects + iVar8);
      do {
        p_Var11 = p_Var7->prec;
        p_Var12 = p_Var7->child;
        p_Var13 = p_Var7->father;
        (p_Var9->obj).next = p_Var7->next;
        (p_Var9->obj).prec = p_Var11;
        (p_Var9->obj).child = p_Var12;
        (p_Var9->obj).father = p_Var13;
        p_Var7 = (_D3_OBJECT *)&p_Var7->list;
        p_Var9 = (_TAKEN_OBJECT *)&(p_Var9->obj).list;
      } while (p_Var7 != (_D3_OBJECT *)&obj[1].last_pos);
      (p_Var9->obj).next = p_Var7->next;
      *(undefined2 *)((int)Pvl_TakenObjects + iVar8 + 0x18) = 0xffff;
      *(undefined *)((int)Pvl_TakenObjects + iVar8 + 0x23) = 0;
      *(undefined4 *)((int)Pvl_TakenObjects + iVar8 + 0x14) = 0;
      *(undefined2 *)((int)Pvl_TakenObjects + iVar8 + 0x2c) = 0;
      *(undefined2 *)((int)Pvl_TakenObjects + iVar8 + 0x2e) = 0;
      *(undefined2 *)((int)Pvl_TakenObjects + iVar8 + 0x30) = 0;
      uVar4 = *(undefined *)&obj[1].pos.vy;
      *(undefined2 *)((int)Pvl_TakenObjects + iVar8 + 0xa6) = 0;
      *(undefined *)((int)Pvl_TakenObjects + iVar8 + 0xa4) = uVar4;
      iVar10 = (int)obj[1].pos.vz;
      if (-1 < iVar10) {
        *(undefined2 *)((int)Pvl_TakenObjects + iVar8 + 0xa6) = (short)(1 << (iVar10 + 0xcU & 0x1f))
        ;
      }
      if (!bVar3) {
        uVar4 = 5;
        if (1 < (uint)*(byte *)((int)Pvl_TakenObjects + iVar8 + 0xa4) - 5) {
          uVar4 = 1;
        }
        *(undefined *)((int)Pvl_TakenObjects + iVar8 + 0xa5) = uVar4;
        *(undefined2 *)((int)Pvl_TakenObjects + iVar8 + 0xac) = 0;
        if ((-1 < *(short *)((int)&obj[1].prec + 2)) && (Pvl_Texts != (long *)0x0)) {
          *(short *)((int)Pvl_TakenObjects + iVar8 + 0xac) = Pvl_File->crc;
        }
      }
      if ((uint)*(byte *)((int)Pvl_TakenObjects + iVar8 + 0xa4) - 7 < 8) {
        *(ushort *)((int)Pvl_TakenObjects + iVar8 + 0xa6) =
             *(ushort *)((int)Pvl_TakenObjects + iVar8 + 0xa6) | 4;
      }
      if ((obj[1].pos.vy == 0x18) && (obj[1].pos.vz == 0x4d)) {
        *(ushort *)((int)Pvl_TakenObjects + iVar8 + 0xa6) =
             *(ushort *)((int)Pvl_TakenObjects + iVar8 + 0xa6) | 4;
      }
      cVar1 = *(char *)((int)Pvl_TakenObjects + iVar8 + 0xa4);
      if (cVar1 == '\x15') {
        *(ushort *)((int)Pvl_TakenObjects + iVar8 + 0xa6) =
             *(ushort *)((int)Pvl_TakenObjects + iVar8 + 0xa6) | 4;
        cVar1 = *(char *)((int)Pvl_TakenObjects + iVar8 + 0xa4);
      }
      if ((cVar1 == '\x17') || (cVar1 == '\x14')) {
        *(ushort *)((int)Pvl_TakenObjects + iVar8 + 0xa6) =
             *(ushort *)((int)Pvl_TakenObjects + iVar8 + 0xa6) | 4;
        Invent_UpdateMultiObject((_TAKEN_OBJECT *)((int)Pvl_TakenObjects + iVar8),obj);
      }
      (pl->env2).Obj.primitive_top.Data
      [(int)*(short *)((pl->env2).Obj.primitive_top.Data + 0x22) + 0x24] = (byte)lVar14;
      *(short *)((pl->env2).Obj.primitive_top.Data + 0x22) =
           *(short *)((pl->env2).Obj.primitive_top.Data + 0x22) + 1;
      Invent_SortPlayerIndices();
      Invent_Update(pl);
      Pl_AddExperience(pl,obj);
      sVar6 = 1;
      if (!bVar3) {
        if (obj[1].pos.vy == 0x1b) {
          Pvl_nGaz = Pvl_nGaz + 1;
          sVar6 = 1;
        }
        else {
          Pvl_nItems = Pvl_nItems + 1;
          sVar6 = 1;
        }
      }
    }
    else {
      Fx_Play(0x42,0);
      sprintf(acStack80,(char *)&PTR_DAT_800ad9ec,*Pvl_UtilityTexts);
      Overlay_SetText(acStack80);
      sVar6 = 0;
    }
  }
  return sVar6;
}



// decompiled code
// original method signature: 
// short /*$ra*/ Invent_ObjectIsStored(struct _PLAYER *pl /*$s4*/, struct _D3_OBJECT *obj /*$s2*/)
 // line 1636, offset 0x80086430
	/* begin block 1 */
		// Start line: 1637
		// Start offset: 0x80086430
		// Variables:
	// 		struct _TAKEN_OBJECT *to; // $s0
	// 		char *po; // $s3
	// 		long i; // $s1

		/* begin block 1.1 */
			// Start line: 1699
			// Start offset: 0x8008660C
			// Variables:
		// 		long value; // $v1
		/* end block 1.1 */
		// End offset: 0x8008662C
		// End Line: 1710
	/* end block 1 */
	// End offset: 0x800866AC
	// End Line: 1736

	/* begin block 2 */
		// Start line: 3939
	/* end block 2 */
	// End Line: 3940

/* WARNING: Type propagation algorithm not settling */

short Invent_ObjectIsStored(_PLAYER *pl,_D3_OBJECT *obj)

{
  byte bVar1;
  char cVar2;
  long lVar3;
  int iVar4;
  uint uVar5;
  _TAKEN_OBJECT *to;
  int iVar6;
  byte *pbVar7;
  
  pbVar7 = (pl->env2).Obj.primitive_top.Data + 0x24;
  iVar6 = 0;
  if (0 < *(short *)((pl->env2).Obj.primitive_top.Data + 0x22)) {
    do {
      iVar4 = (uint)*pbVar7 * 0xb0;
      to = (_TAKEN_OBJECT *)((int)Pvl_TakenObjects + iVar4);
      if (((((*(short *)((int)Pvl_TakenObjects + iVar4 + 0xa8) == 0) &&
            (lVar3 = Invent_D3IsTheSame((_D3_OBJECT *)to,obj), lVar3 != 0)) &&
           ((*(ushort *)((int)Pvl_TakenObjects + iVar4 + 0xa6) & 8) == 0)) &&
          (cVar2 = *(char *)((int)Pvl_TakenObjects + iVar4 + 0xa4), cVar2 != '\x16')) &&
         ((cVar2 != '\x04' || (*(short *)((int)Pvl_TakenObjects + iVar4 + 0x9e) == obj[1].pos.pad)))
         ) {
        Fx_Play(0x40,(char)obj + ',');
        if ((*(undefined **)&obj[1].last_pos == &DAT_00001234) ||
           (*(undefined **)&obj[1].last_pos == &DAT_00005678)) {
          if (*(char *)((int)Pvl_TakenObjects + iVar4 + 0xa4) == '\x14') {
            *(ushort *)((int)Pvl_TakenObjects + iVar4 + 0xaa) =
                 *(ushort *)((int)Pvl_TakenObjects + iVar4 + 0xaa) | obj[1].pos.vz;
            return 1;
          }
          lVar3 = Invent_RemoveDroppedObject(obj);
          *(char *)((int)Pvl_TakenObjects + iVar4 + 0xa5) =
               *(char *)((int)Pvl_TakenObjects + iVar4 + 0xa5) + (char)lVar3;
          return 1;
        }
        Pl_AddExperience(pl,obj);
        if (*(char *)((int)Pvl_TakenObjects + iVar4 + 0xa4) == '\x1b') {
          Pvl_nGaz = Pvl_nGaz + 1;
        }
        else {
          Pvl_nItems = Pvl_nItems + 1;
        }
        bVar1 = *(byte *)((int)Pvl_TakenObjects + iVar4 + 0xa4);
        if (bVar1 == 0x14) {
          Invent_UpdateMultiObject(to,obj);
          lVar3 = Invent_MultiIsComplete(to);
          if (lVar3 == 0) {
            return 1;
          }
          if (*(short *)((int)Pvl_TakenObjects + iVar4 + 0x9e) == 0) {
            Scts_Interruptors = Scts_Interruptors | 0x20000000;
            return 1;
          }
          uVar5 = 0x40000000;
code_r0x80086664:
          Scts_Interruptors = Scts_Interruptors | uVar5;
          return 1;
        }
        if (bVar1 < 0x15) {
          if ((bVar1 < 7) && (4 < bVar1)) {
            cVar2 = *(char *)((int)Pvl_TakenObjects + iVar4 + 0xa5) + '\x05';
            goto LAB_80086684;
          }
        }
        else {
          if (bVar1 == 0x17) {
            Invent_UpdateMultiObject(to,obj);
            lVar3 = Invent_MultiIsComplete(to);
            if (lVar3 == 0) {
              return 1;
            }
            uVar5 = SEXT24(*(short *)((int)Pvl_TakenObjects + iVar4 + 0x9e));
            goto code_r0x80086664;
          }
        }
        cVar2 = *(char *)((int)Pvl_TakenObjects + iVar4 + 0xa5) + '\x01';
LAB_80086684:
        *(char *)((int)Pvl_TakenObjects + iVar4 + 0xa5) = cVar2;
        return 1;
      }
      iVar6 = iVar6 + 1;
      pbVar7 = pbVar7 + 1;
    } while (iVar6 < (int)*(short *)((pl->env2).Obj.primitive_top.Data + 0x22));
  }
  return 0;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Invent_D3IsTheSame(struct _D3_OBJECT *o1 /*$a0*/, struct _D3_OBJECT *o2 /*$a1*/)
 // line 1739, offset 0x800866cc
	/* begin block 1 */
		// Start line: 1741
		// Start offset: 0x800866CC
		// Variables:
	// 		long type; // $v1
	/* end block 1 */
	// End offset: 0x8008673C
	// End Line: 1774

	/* begin block 2 */
		// Start line: 4237
	/* end block 2 */
	// End Line: 4238

long Invent_D3IsTheSame(_D3_OBJECT *o1,_D3_OBJECT *o2)

{
  int iVar1;
  
  iVar1 = (int)o1[1].pos.vy;
  if (iVar1 == (int)o2[1].pos.vy) {
    switch(iVar1) {
    case 2:
    case 3:
    case 4:
    case 0x11:
      if (o1[1].pos.vz != o2[1].pos.vz) {
        return 0;
      }
      break;
    case 7:
    case 8:
    case 9:
    case 10:
    case 0xb:
    case 0xc:
    case 0xd:
    case 0xe:
    case 0x15:
    case 0x18:
      goto switchD_80086700_caseD_7;
    case 0x14:
      if (o1[1].pos.pad != o2[1].pos.pad) {
        return 0;
      }
    }
    return 1;
  }
switchD_80086700_caseD_7:
  return 0;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Invent_SetCarac(long carac /*$a0*/, long value /*$a1*/)
 // line 1777, offset 0x80086744
	/* begin block 1 */
		// Start line: 4313
	/* end block 1 */
	// End Line: 4314

long Invent_SetCarac(long carac,long value)

{
  carac = carac + value;
  if (100 < carac) {
    carac = 100;
  }
  return carac;
}



// decompiled code
// original method signature: 
// short /*$ra*/ Invent_IsFull()
 // line 1783, offset 0x80086760
	/* begin block 1 */
		// Start line: 4324
	/* end block 1 */
	// End Line: 4325

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

short Invent_IsFull(void)

{
  ushort uVar1;
  long lVar2;
  
  lVar2 = Invent_GetFreeTakenObject();
  if (lVar2 == -1) {
    uVar1 = 1;
  }
  else {
    uVar1 = (ushort)(_DAT_800b1e4a < 0x10) ^ 1;
  }
  return (short)uVar1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Invent_GetTakenIndex(long type /*$a0*/, long elem /*$a1*/)
 // line 1793, offset 0x800867a8
	/* begin block 1 */
		// Start line: 1795
		// Start offset: 0x800867A8
		// Variables:
	// 		long index; // $v1
	/* end block 1 */
	// End offset: 0x800867EC
	// End Line: 1813

	/* begin block 2 */
		// Start line: 4349
	/* end block 2 */
	// End Line: 4350

long Invent_GetTakenIndex(long type,long elem)

{
  if (type == 2) {
    type = elem + 2;
  }
  else {
    if (type < 3) {
      if (type < 0) {
        return -1;
      }
    }
    else {
      if (type != 3) {
        return -1;
      }
      type = elem + 6;
    }
  }
  return type;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Invent_GetFreeTakenObject()
 // line 1817, offset 0x800867f8
	/* begin block 1 */
		// Start line: 1819
		// Start offset: 0x800867F8
		// Variables:
	// 		long freeIndex; // $v1
	/* end block 1 */
	// End offset: 0x80086828
	// End Line: 1828

	/* begin block 2 */
		// Start line: 4397
	/* end block 2 */
	// End Line: 4398

/* WARNING: Unknown calling convention yet parameter storage is locked */

long Invent_GetFreeTakenObject(void)

{
  int iVar1;
  _TAKEN_OBJECT *p_Var2;
  
  iVar1 = 0;
  p_Var2 = Pvl_TakenObjects;
  do {
    if (p_Var2[1].obj.pos.vz == -1) {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
    p_Var2 = (_TAKEN_OBJECT *)&p_Var2[1].obj.last_pos.vz;
  } while (iVar1 < 0x20);
  return -1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_SortPlayerIndices()
 // line 1831, offset 0x80086838
	/* begin block 1 */
		// Start line: 1832
		// Start offset: 0x80086838
		// Variables:
	// 		long i; // $s0
	// 		long j; // $a1
	// 		long min; // $a3
	// 		long limit; // $s1
	// 		long CurIndex; // $a2
	// 		long NbFixed; // $s2
	// 		short TabInter[16]; // stack offset -88
	// 		short TabIndices[16]; // stack offset -56

		/* begin block 1.1 */
			// Start line: 1841
			// Start offset: 0x80086870
			// Variables:
		// 		struct _D3_OBJECT *o; // $v0
		/* end block 1.1 */
		// End offset: 0x80086870
		// End Line: 1841
	/* end block 1 */
	// End offset: 0x80086A54
	// End Line: 1881

	/* begin block 2 */
		// Start line: 4431
	/* end block 2 */
	// End Line: 4432

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Invent_SortPlayerIndices(void)

{
  short sVar1;
  long lVar2;
  short *psVar3;
  short *psVar4;
  ushort *puVar5;
  int iVar6;
  ushort uVar7;
  short sVar8;
  int iVar9;
  short sVar10;
  int iVar11;
  ushort local_58 [16];
  short local_38 [16];
  
  iVar11 = 0;
  iVar9 = 0;
  if (0 < _DAT_800b1e4a) {
    do {
      lVar2 = Invent_GetTakenIndex
                        ((int)*(short *)((int)Pvl_TakenObjects +
                                        (uint)(byte)(&DAT_800b1e4c)[iVar9] * 0xb0 + 0x9a),
                         (int)*(short *)((int)Pvl_TakenObjects +
                                        (uint)(byte)(&DAT_800b1e4c)[iVar9] * 0xb0 + 0x9c));
      local_38[iVar9] = (short)lVar2;
      iVar9 = iVar9 + 1;
    } while (iVar9 < (int)_DAT_800b1e4a);
  }
  iVar9 = (int)_DAT_800b1e4a;
  if (0 < iVar9) {
    iVar9 = 0;
    sVar10 = -1;
    do {
      sVar8 = 0x20;
      iVar6 = 0;
      _uVar7 = 0;
      uVar7 = 0;
      psVar4 = local_38;
      if (0 < (int)_DAT_800b1e4a) {
        do {
          sVar1 = *psVar4;
          if ((sVar10 < sVar1) && (sVar1 < sVar8)) {
            _uVar7 = (uint)(byte)(&DAT_800b1e4c)[iVar6];
            sVar8 = sVar1;
          }
          uVar7 = (ushort)_uVar7;
          iVar6 = iVar6 + 1;
          psVar4 = psVar4 + 1;
        } while (iVar6 < (int)_DAT_800b1e4a);
      }
      if (sVar8 == 0x20) break;
      iVar6 = iVar9 + 1;
      local_58[iVar9] = uVar7;
      iVar11 = iVar11 + 1;
      iVar9 = iVar6;
      sVar10 = sVar8;
    } while (iVar6 < (int)_DAT_800b1e4a);
    iVar9 = (int)_DAT_800b1e4a;
  }
  if (iVar11 < iVar9) {
    puVar5 = local_58 + iVar11;
    psVar4 = local_38;
    iVar9 = 0;
    do {
      if (-1 < *psVar4) {
        psVar3 = local_38 + iVar9;
        do {
          psVar3 = psVar3 + 1;
          psVar4 = psVar4 + 1;
          iVar9 = iVar9 + 1;
        } while (-1 < *psVar3);
      }
      psVar4 = psVar4 + 1;
      iVar11 = iVar11 + 1;
      *puVar5 = (ushort)(byte)(&DAT_800b1e4c)[iVar9];
      puVar5 = puVar5 + 1;
      iVar9 = iVar9 + 1;
    } while (iVar11 < (int)_DAT_800b1e4a);
  }
  iVar9 = 0;
  if (0 < _DAT_800b1e4a) {
    puVar5 = local_58;
    do {
      (&DAT_800b1e4c)[iVar9] = *(undefined *)puVar5;
      iVar9 = iVar9 + 1;
      puVar5 = puVar5 + 1;
    } while (iVar9 < (int)_DAT_800b1e4a);
  }
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ Invent_GetNbObjects(short type /*$a0*/, short elem /*$a1*/)
 // line 1884, offset 0x80086a70
	/* begin block 1 */
		// Start line: 1885
		// Start offset: 0x80086A70
		// Variables:
	// 		long i; // $s1
	// 		struct _TAKEN_OBJECT *to; // $s0
	/* end block 1 */
	// End offset: 0x80086B74
	// End Line: 1915

	/* begin block 2 */
		// Start line: 4603
	/* end block 2 */
	// End Line: 4604

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

short Invent_GetNbObjects(short type,short elem)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  
  if ((-1 < (int)type) && (iVar4 = 0, 0 < _DAT_800b1e4a)) {
    do {
      iVar3 = (uint)(byte)(&DAT_800b1e4c)[iVar4] * 0xb0;
      bVar1 = *(byte *)((int)Pvl_TakenObjects + iVar3 + 0xa4);
      if ((uint)bVar1 == (int)type) {
        if (bVar1 < 2) {
LAB_80086b4c:
          return (ushort)*(byte *)((int)Pvl_TakenObjects + iVar3 + 0xa5);
        }
        if (bVar1 < 4) {
          sVar2 = Invent_GetElemNumber((_TAKEN_OBJECT *)((int)Pvl_TakenObjects + iVar3));
        }
        else {
          if (bVar1 != 0x14) goto LAB_80086b4c;
          sVar2 = *(short *)((int)Pvl_TakenObjects + iVar3 + 0x9e);
        }
        if (elem == sVar2) goto LAB_80086b4c;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < (int)_DAT_800b1e4a);
  }
  return 0;
}



// decompiled code
// original method signature: 
// struct _D3_OBJECT * /*$ra*/ Invent_GetDroppedD3(short type /*$a0*/)
 // line 1918, offset 0x80086b94
	/* begin block 1 */
		// Start line: 1920
		// Start offset: 0x80086B94
		// Variables:
	// 		long i; // $a2
	// 		struct _TAKEN_OBJECT *to; // $a1
	/* end block 1 */
	// End offset: 0x80086BEC
	// End Line: 1930

	/* begin block 2 */
		// Start line: 4693
	/* end block 2 */
	// End Line: 4694

_D3_OBJECT * Invent_GetDroppedD3(short type)

{
  ushort *puVar1;
  _TAKEN_OBJECT *p_Var2;
  int iVar3;
  
  p_Var2 = Pvl_TakenObjects;
  iVar3 = 0;
  puVar1 = (ushort *)&Pvl_TakenObjects[1].obj.pos.vy;
  while (((uint)*(byte *)(puVar1 + -1) != (int)type || ((*puVar1 & 2) == 0))) {
    iVar3 = iVar3 + 1;
    puVar1 = puVar1 + 0x58;
    p_Var2 = (_TAKEN_OBJECT *)&p_Var2[1].obj.last_pos.vz;
    if (0x1f < iVar3) {
      return (_D3_OBJECT *)0x0;
    }
  }
  return (_D3_OBJECT *)p_Var2;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Invent_GetDroppedIndex(short type /*$a0*/, long index /*$a1*/)
 // line 1934, offset 0x80086bf4
	/* begin block 1 */
		// Start line: 1936
		// Start offset: 0x80086BF4
		// Variables:
	// 		long i; // $a1
	// 		struct _TAKEN_OBJECT *to; // $v1
	/* end block 1 */
	// End offset: 0x80086C74
	// End Line: 1951

	/* begin block 2 */
		// Start line: 4728
	/* end block 2 */
	// End Line: 4729

long Invent_GetDroppedIndex(short type,long index)

{
  ushort *puVar1;
  
  if (0x1f < (uint)index) {
    return -1;
  }
  if (index < 0x20) {
    puVar1 = (ushort *)((int)Pvl_TakenObjects + index * 0xb0 + 0xa6);
    do {
      if (((uint)*(byte *)(puVar1 + -1) == (int)type) && ((*puVar1 & 2) != 0)) {
        return index;
      }
      index = index + 1;
      puVar1 = puVar1 + 0x58;
    } while (index < 0x20);
  }
  return -1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_UnDropObject(long index /*$s1*/)
 // line 1954, offset 0x80086c7c
	/* begin block 1 */
		// Start line: 1955
		// Start offset: 0x80086C7C
		// Variables:
	// 		struct _TAKEN_OBJECT *to; // $s0
	/* end block 1 */
	// End offset: 0x80086C7C
	// End Line: 1955

	/* begin block 2 */
		// Start line: 4773
	/* end block 2 */
	// End Line: 4774

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Invent_UnDropObject(long index)

{
  int iVar1;
  
  iVar1 = index * 0xb0;
  Task_Kill(*(TASK **)((int)Pvl_TakenObjects + iVar1 + 0x14));
  *(undefined4 *)((int)Pvl_TakenObjects + iVar1 + 0x14) = 0;
  *(undefined2 *)((int)Pvl_TakenObjects + iVar1 + 0xa8) = 0;
  *(undefined2 *)((int)Pvl_TakenObjects + iVar1 + 0xaa) = 0;
  *(undefined2 *)((int)Pvl_TakenObjects + iVar1 + 0x18) = (short)index;
  *(undefined *)((int)Pvl_TakenObjects + iVar1 + 0x23) = 0;
  *(ushort *)((int)Pvl_TakenObjects + iVar1 + 0x1a) =
       *(ushort *)((int)Pvl_TakenObjects + iVar1 + 0x1a) & 0xffef;
  *(ushort *)((int)Pvl_TakenObjects + iVar1 + 0xa6) =
       *(ushort *)((int)Pvl_TakenObjects + iVar1 + 0xa6) & 0xfffd;
  (&DAT_800b1e4c)[(int)_DAT_800b1e4a] = (char)index;
  _DAT_800b1e4a = _DAT_800b1e4a + 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_RemoveObjInPlayer(struct _PLAYER *pl /*$a3*/, struct _INVENT_LIST *l /*$a1*/, long start /*$a2*/)
 // line 1983, offset 0x80086d28
	/* begin block 1 */
		// Start line: 1984
		// Start offset: 0x80086D28
		// Variables:
	// 		long i; // $a2
	/* end block 1 */
	// End offset: 0x80086DA8
	// End Line: 2000

	/* begin block 2 */
		// Start line: 4850
	/* end block 2 */
	// End Line: 4851

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Invent_RemoveObjInPlayer(_PLAYER *pl,_INVENT_LIST *l,long start)

{
  while (start < (int)_DAT_800b1e4a + -1) {
    (pl->env2).Obj.primitive_top.Data[start + 0x24] =
         (pl->env2).Obj.primitive_top.Data[start + 0x25];
    start = start + 1;
  }
  if (l->deb_list != '\0') {
    l->deb_list = l->deb_list + -1;
  }
  if (l->hilite != '\0') {
    l->hilite = l->hilite + -1;
  }
  if ((byte)l->hilite < (byte)l->deb_list) {
    l->hilite = l->deb_list;
  }
  *(short *)((pl->env2).Obj.primitive_top.Data + 0x22) =
       *(short *)((pl->env2).Obj.primitive_top.Data + 0x22) + -1;
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Invent_RemoveDroppedObject(struct _D3_OBJECT *obj /*$a0*/)
 // line 2004, offset 0x80086dbc
	/* begin block 1 */
		// Start line: 2006
		// Start offset: 0x80086DBC
		// Variables:
	// 		struct _TAKEN_OBJECT *to; // $a1
	// 		long i; // $a2
	// 		long nObj; // $a3

		/* begin block 1.1 */
			// Start line: 2012
			// Start offset: 0x80086DD4
		/* end block 1.1 */
		// End offset: 0x80086DF0
		// End Line: 2024
	/* end block 1 */
	// End offset: 0x80086E00
	// End Line: 2026

	/* begin block 2 */
		// Start line: 4892
	/* end block 2 */
	// End Line: 4893

long Invent_RemoveDroppedObject(_D3_OBJECT *obj)

{
  byte bVar1;
  long *plVar2;
  _TAKEN_OBJECT *p_Var3;
  int iVar4;
  
  p_Var3 = Pvl_TakenObjects;
  iVar4 = 0;
  plVar2 = &Pvl_TakenObjects[1].obj.color;
  do {
    iVar4 = iVar4 + 1;
    if (p_Var3 == (_TAKEN_OBJECT *)obj) {
      bVar1 = *(byte *)((int)plVar2 + 5);
      *(undefined *)((int)plVar2 + 5) = 0;
      *(undefined2 *)(plVar2 + 2) = 0xffff;
      *plVar2 = 0;
      return (uint)bVar1;
    }
    plVar2 = plVar2 + 0x2c;
    p_Var3 = (_TAKEN_OBJECT *)&p_Var3[1].obj.last_pos.vz;
  } while (iVar4 < 0x20);
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_RemoveUsedObject(long type /*$s2*/, long elem /*$s6*/, long mode /*$s3*/)
 // line 2031, offset 0x80086e08
	/* begin block 1 */
		// Start line: 2032
		// Start offset: 0x80086E08
		// Variables:
	// 		long i; // $s1
	// 		long FOUND; // $v0
	// 		struct _TAKEN_OBJECT *to; // $s0
	// 		struct _INVENT_LIST *l; // $s5
	/* end block 1 */
	// End offset: 0x80086F44
	// End Line: 2080

	/* begin block 2 */
		// Start line: 4962
	/* end block 2 */
	// End Line: 4963

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Invent_RemoveUsedObject(long type,long elem,long mode)

{
  bool bVar1;
  short sVar2;
  int iVar3;
  int start;
  
  start = 0;
  if (0 < _DAT_800b1e4a) {
    do {
      iVar3 = (uint)(byte)(&DAT_800b1e4c)[start] * 0xb0;
      if ((int)*(short *)((int)Pvl_TakenObjects + iVar3 + 0x9a) == type) {
        if ((type < 4) && (1 < type)) {
          sVar2 = Invent_GetElemNumber((_TAKEN_OBJECT *)((int)Pvl_TakenObjects + iVar3));
          bVar1 = elem == (int)sVar2;
        }
        else {
          bVar1 = true;
        }
        if (bVar1) {
          *(char *)((int)Pvl_TakenObjects + iVar3 + 0xa5) =
               *(char *)((int)Pvl_TakenObjects + iVar3 + 0xa5) + -1;
          if (mode == 2) {
            *(undefined *)((int)Pvl_TakenObjects + iVar3 + 0xa5) = 0;
          }
          if (mode != 0) {
            Invent_FlyObject((_TAKEN_OBJECT *)((int)Pvl_TakenObjects + iVar3),-1);
          }
          if (*(char *)((int)Pvl_TakenObjects + iVar3 + 0xa5) == '\0') {
            *(undefined2 *)((int)Pvl_TakenObjects + iVar3 + 0xa6) = 0;
            *(undefined2 *)((int)Pvl_TakenObjects + iVar3 + 0xa8) = 0xffff;
            Invent_RemoveObjInPlayer((_PLAYER *)&Player,Inventaire.inv_list,start);
            start = start + -1;
          }
        }
      }
      start = start + 1;
    } while (start < (int)_DAT_800b1e4a);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_RemoveUsedKey(long mask /*stack 0*/, long force /*$s6*/)
 // line 2083, offset 0x80086f6c
	/* begin block 1 */
		// Start line: 2084
		// Start offset: 0x80086F6C
		// Variables:
	// 		long i; // $s1
	// 		long value; // $s3
	// 		long dummy; // $a0
	// 		long cpt; // $s4
	// 		long m; // $s5
	// 		long FOUND; // $s2
	// 		struct _TAKEN_OBJECT *to; // $s0
	// 		struct _INVENT_LIST *l; // $s7
	// 		char string[100]; // stack offset -144
	/* end block 1 */
	// End offset: 0x800871FC
	// End Line: 2190

	/* begin block 2 */
		// Start line: 5116
	/* end block 2 */
	// End Line: 5117

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Invent_RemoveUsedKey(long mask,long force)

{
  bool bVar1;
  int iVar2;
  long lVar3;
  undefined *puVar4;
  int iVar5;
  int start;
  uint uVar6;
  int start_00;
  uint uVar7;
  
  start_00 = 0;
  uVar7 = (uint)mask >> 0x10;
  uVar6 = 1;
  do {
    if (((uVar7 & uVar6) != 0) && (start = 0, 0 < _DAT_800b1e4a)) {
      do {
        iVar2 = (uint)(byte)(&DAT_800b1e4c)[start] * 0xb0;
        iVar5 = (int)*(short *)((int)Pvl_TakenObjects + iVar2 + 0x9a);
        bVar1 = false;
        if ((iVar5 == start_00 + 7) && (start_00 < 9)) {
LAB_800870a8:
          bVar1 = true;
LAB_800870ac:
          if (bVar1) {
            if (force == 0) {
              Invent_FlyObject((_TAKEN_OBJECT *)((int)Pvl_TakenObjects + iVar2),-1);
            }
            *(undefined *)((int)Pvl_TakenObjects + iVar2 + 0xa5) = 0;
            *(undefined2 *)((int)Pvl_TakenObjects + iVar2 + 0xa6) = 0;
            *(undefined2 *)((int)Pvl_TakenObjects + iVar2 + 0xa8) = 0xffff;
            Invent_RemoveObjInPlayer((_PLAYER *)&Player,Inventaire.inv_list,start);
          }
        }
        else {
          if (iVar5 != 0x14) {
            if (((iVar5 == 0x15) &&
                ((uint)*(ushort *)((int)Pvl_TakenObjects + iVar2 + 0x9c) == uVar6)) &&
               ((*(short *)((int)Pvl_TakenObjects + iVar2 + 0x9e) != 100 || (force != 0))))
            goto LAB_800870a8;
            goto LAB_800870ac;
          }
          lVar3 = Invent_MultiIsComplete((_TAKEN_OBJECT *)((int)Pvl_TakenObjects + iVar2));
          if (lVar3 != 0) {
            if ((uVar7 == 0x2000) && (*(short *)((int)Pvl_TakenObjects + iVar2 + 0x9e) == 0)) {
              bVar1 = true;
            }
            if ((uVar7 == 0x4000) && (*(short *)((int)Pvl_TakenObjects + iVar2 + 0x9e) == 1)) {
              bVar1 = true;
            }
            goto LAB_800870ac;
          }
        }
        start = start + 1;
      } while (start < (int)_DAT_800b1e4a);
    }
    uVar6 = uVar6 << 1;
    start_00 = start_00 + 1;
    if (0x8000 < (int)uVar6) {
      uVar6 = 1;
      do {
        if (((mask & 0xffffU & uVar6) != 0) && (0 < _DAT_800b1e4a)) {
          puVar4 = &Player;
          start_00 = 0;
          do {
            start = (uint)(byte)puVar4[0x214] * 0xb0;
            if (((*(short *)((int)Pvl_TakenObjects + start + 0x9a) == 0x17) &&
                (lVar3 = Invent_MultiIsComplete((_TAKEN_OBJECT *)((int)Pvl_TakenObjects + start)),
                lVar3 != 0)) &&
               (((int)*(short *)((int)Pvl_TakenObjects + start + 0x9e) & mask & 0xffffU) != 0)) {
              Invent_FlyObject((_TAKEN_OBJECT *)((int)Pvl_TakenObjects + start),-1);
              *(undefined *)((int)Pvl_TakenObjects + start + 0xa5) = 0;
              *(undefined2 *)((int)Pvl_TakenObjects + start + 0xa6) = 0;
              *(undefined2 *)((int)Pvl_TakenObjects + start + 0xa8) = 0xffff;
              Invent_RemoveObjInPlayer((_PLAYER *)&Player,Inventaire.inv_list,start_00);
            }
            start = start_00 + 1;
            puVar4 = (undefined *)(start_00 + -0x7ff4e3c7);
            start_00 = start;
          } while (start < (int)_DAT_800b1e4a);
        }
        uVar6 = uVar6 << 1;
      } while ((int)uVar6 < 0x8000);
      return;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_RemoveMarkedObject(long limit /*$s2*/)
 // line 2193, offset 0x8008722c
	/* begin block 1 */
		// Start line: 2194
		// Start offset: 0x8008722C
		// Variables:
	// 		struct _TAKEN_OBJECT *to; // $a0
	// 		struct _INVENT_LIST *l; // $s4
	// 		long i; // $s0
	/* end block 1 */
	// End offset: 0x80087354
	// End Line: 2231

	/* begin block 2 */
		// Start line: 5465
	/* end block 2 */
	// End Line: 5466

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Invent_RemoveMarkedObject(long limit)

{
  undefined *puVar1;
  int iVar2;
  short *psVar3;
  int start;
  
  if (0 < _DAT_800b1e4a) {
    puVar1 = &Player;
    start = 0;
    do {
      iVar2 = (uint)(byte)puVar1[0x214] * 0xb0;
      if ((*(char *)((int)Pvl_TakenObjects + iVar2 + 0x99) == '\x03') &&
         ((int)*(short *)((int)Pvl_TakenObjects + iVar2 + 0x9a) == limit)) {
        *(undefined *)((int)Pvl_TakenObjects + iVar2 + 0xa5) = 0;
        *(undefined2 *)((int)Pvl_TakenObjects + iVar2 + 0xa6) = 0;
        *(undefined2 *)((int)Pvl_TakenObjects + iVar2 + 0xa8) = 0xffff;
        Invent_RemoveObjInPlayer((_PLAYER *)&Player,Inventaire.inv_list,start);
        start = start + -1;
      }
      iVar2 = start + 1;
      puVar1 = (undefined *)(start + -0x7ff4e3c7);
      start = iVar2;
    } while (iVar2 < (int)_DAT_800b1e4a);
  }
  start = 0;
  psVar3 = &Pvl_TakenObjects[1].obj.pos.vz;
  do {
    if (((*psVar3 != -1) && (*(char *)((int)psVar3 + -0xf) == '\x03')) && ((int)psVar3[-7] == limit)
       ) {
      *(undefined *)((int)psVar3 + -3) = 0;
      psVar3[-1] = 0;
      *psVar3 = -1;
    }
    start = start + 1;
    psVar3 = psVar3 + 0x58;
  } while (start < 0x20);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_UseInventBack(struct _PLAYER *pl /*$a0*/)
 // line 2234, offset 0x80087374
	/* begin block 1 */
		// Start line: 2235
		// Start offset: 0x80087374
		// Variables:
	// 		struct _TAKEN_OBJECT *to; // $v1
	// 		struct _INVENT_LIST *l; // $t1
	// 		long i; // $a2
	/* end block 1 */
	// End offset: 0x80087410
	// End Line: 2256

	/* begin block 2 */
		// Start line: 5578
	/* end block 2 */
	// End Line: 5579

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Invent_UseInventBack(_PLAYER *pl)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  
  if (0 < _DAT_800b1e4a) {
    puVar1 = &Player;
    iVar3 = 0;
    do {
      iVar2 = (uint)(byte)puVar1[0x214] * 0xb0;
      if ((*(char *)((int)Pvl_TakenObjects + iVar2 + 0xa5) != '\0') &&
         (*(char *)((int)Pvl_TakenObjects + iVar2 + 0xa4) == '\x13')) {
        Inventaire.inv_list[0].hilite = puVar1[0x214];
        Invent_UseObject(pl);
        return;
      }
      iVar2 = iVar3 + 1;
      puVar1 = (undefined *)(iVar3 + -0x7ff4e3c7);
      iVar3 = iVar2;
    } while (iVar2 < (int)_DAT_800b1e4a);
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Invent_UseObject(struct _PLAYER *pl /*$s1*/)
 // line 2259, offset 0x80087420
	/* begin block 1 */
		// Start line: 2260
		// Start offset: 0x80087420
		// Variables:
	// 		long value; // $a2
	// 		long ObjectID; // $s0
	// 		long UpgradeValue; // $s0
	// 		long Spell_Learnt; // $s4
	// 		long Anim_Player; // $s5
	// 		long SetVisible; // $s6
	// 		struct _INVENT_LIST *l; // $s3
	// 		char *po; // $v0
	// 		struct _TAKEN_OBJECT *to; // $s2
	// 		struct _D3_OBJECT *D3Obj; // $a3

		/* begin block 1.1 */
			// Start line: 2322
			// Start offset: 0x800875C0
			// Variables:
		// 		long real_level; // $a0
		// 		long max_level; // $a1

			/* begin block 1.1.1 */
				// Start line: 2334
				// Start offset: 0x80087648
			/* end block 1.1.1 */
			// End offset: 0x800876C8
			// End Line: 2353
		/* end block 1.1 */
		// End offset: 0x800876C8
		// End Line: 2356
	/* end block 1 */
	// End offset: 0x80087B5C
	// End Line: 2555

	/* begin block 2 */
		// Start line: 5640
	/* end block 2 */
	// End Line: 5641

/* WARNING: Removing unreachable block (ram,0x80087620) */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long Invent_UseObject(_PLAYER *pl)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  TASK *t;
  char cVar4;
  short sVar5;
  int iVar6;
  _D3_OBJECT *p_Var7;
  long lVar8;
  undefined uVar9;
  ushort uVar10;
  undefined *puVar11;
  uint uVar12;
  undefined *puVar13;
  int carac;
  _D3_OBJECT **pp_Var14;
  _TAKEN_OBJECT *to;
  int iVar15;
  int iVar16;
  
  iVar15 = 0;
  bVar3 = false;
  bVar2 = false;
  iVar6 = (uint)(pl->env2).Obj.primitive_top.Data[(uint)(byte)Inventaire.inv_list[0].hilite + 0x24]
          * 0xb0;
  to = (_TAKEN_OBJECT *)((int)Pvl_TakenObjects + iVar6);
  if (*(char *)((int)Pvl_TakenObjects + iVar6 + 0xa5) == '\0') {
    return -1;
  }
  switch(*(undefined *)((int)Pvl_TakenObjects + iVar6 + 0xa4)) {
  case 0:
    carac = (int)(pl->obj).hit_points;
    if (99 < carac) {
      return -2;
    }
    lVar8 = Invent_SetCarac(carac,0x19);
    t = Overlay_Handle;
    (pl->obj).hit_points = (short)lVar8;
    Task_EventExec(t,t->event_msg | 4,t->event_param);
    break;
  case 1:
    if (99 < *(ushort *)((pl->env2).Obj.primitive_top.Data + 0xe)) {
      return -2;
    }
    lVar8 = Invent_SetCarac((uint)*(ushort *)((pl->env2).Obj.primitive_top.Data + 0xe),0x19);
    t = Overlay_Handle;
    *(short *)((pl->env2).Obj.primitive_top.Data + 0xe) = (short)lVar8;
    Task_EventExec(t,t->event_msg | 0x10,t->event_param);
    break;
  case 2:
    sVar5 = Invent_GetElemNumber(to);
    if ((int)sVar5 < 0) {
      return 0;
    }
    pp_Var14 = &(pl->obj).next + (int)sVar5 * 2;
    carac = (int)*(short *)((int)pp_Var14 + 0x1aa);
    if (99 < carac) {
      return -2;
    }
    lVar8 = Invent_SetCarac(carac,0x14);
    *(undefined2 *)((int)pp_Var14 + 0x1aa) = (short)lVar8;
    Stats_SetTanks(200,0x14);
    bVar3 = true;
    break;
  case 3:
    sVar5 = Invent_GetElemNumber(to);
    carac = (int)sVar5;
    if (carac < 0) {
      return 0;
    }
    if ((pl->env2).Obj.primitive_top.Data[4] == 3) {
      bVar1 = (pl->env1).Obj.primitive_top.Data[carac * 8 + 0x1d];
    }
    else {
      bVar1 = (pl->env1).Obj.primitive_top.Data[carac * 8 + 0x1c];
    }
    pp_Var14 = &(pl->obj).next + carac * 2;
    sVar5 = *(short *)(pp_Var14 + 0x6c);
    iVar16 = 100 / (int)sVar5;
    if ((int)sVar5 == 0) {
      trap(0x1c00);
    }
    if (9 < iVar16) {
      iVar16 = 9;
    }
    if (iVar16 <= (int)(char)bVar1 + 1) {
      return 0xfffffffe;
    }
    uVar12 = SEXT24((short)(sVar5 * ((short)(char)bVar1 + 2)));
    if ((int)(uint)(*(ushort *)((pl->env2).Obj.primitive_top.Data + 0x12) >> 8) < (int)uVar12) {
      Task_EventExec(DAT_800b6e80,2,carac << 0x10 | uVar12);
      return -6;
    }
    uVar9 = (undefined)((int)*(char *)(pp_Var14 + 0x6b) + 1);
    if (iVar16 < (int)*(char *)(pp_Var14 + 0x6b) + 1) {
      uVar9 = (undefined)iVar16;
    }
    *(undefined *)(pp_Var14 + 0x6b) = uVar9;
    goto LAB_80087848;
  case 4:
    lVar8 = Invent_AddSpell(pl,to);
    if (lVar8 < 0) {
      if (lVar8 == -0x4000) {
        return 0xfffffffe;
      }
      Task_EventExec(DAT_800b6e80,1,-lVar8 >> 8);
      return -3;
    }
    iVar15 = 1;
    if (0 < lVar8) {
      iVar15 = 2;
    }
    break;
  case 5:
  case 6:
    Inventaire.inv_list[0].pad = *(char *)((int)Pvl_TakenObjects + iVar6 + 0xa4) + '\x18';
    goto LAB_80087a78;
  default:
    return 0;
  case 0x10:
    if (((pl->m_obj).shadow.y2 & 0x1eU) == 0) {
      return -8;
    }
    Overlay_BlinkState();
    break;
  case 0x11:
    sVar5 = Invent_GetElemNumber(to);
    if (sVar5 < 0) {
      return 0;
    }
    if (sVar5 == 1) {
      if (_DAT_800b1e40 == 0) {
        return -2;
      }
      if (99 < _DAT_800b1e3a >> 8) {
        return -2;
      }
      puVar11 = (undefined *)((uint)*(ushort *)((pl->env2).Obj.primitive_top.Data + 0x12) + 0x500);
      *(short *)((pl->env2).Obj.primitive_top.Data + 0x12) = (short)puVar11;
      if (&DAT_00006400 < (undefined *)((uint)puVar11 & 0xffff)) {
        puVar11 = &DAT_00006400;
      }
      uVar10 = *(ushort *)((pl->env2).Obj.primitive_top.Data + 0x1e);
      *(short *)((pl->env2).Obj.primitive_top.Data + 0x12) = (short)puVar11;
    }
    else {
      if (sVar5 < 2) {
        if (sVar5 == 0) {
          if (*(short *)((pl->env2).Obj.primitive_top.Data + 0x16) == 0) {
            return -2;
          }
          uVar10 = *(ushort *)((pl->env2).Obj.primitive_top.Data + 0x10);
          uVar12 = (uint)*(ushort *)((pl->env2).Obj.primitive_top.Data + 0x1c);
          if (uVar12 <= (uint)(uVar10 >> 8)) {
            return 0xfffffffe;
          }
          *(ushort *)((pl->env2).Obj.primitive_top.Data + 0x10) = uVar10 + 0x500;
          uVar10 = *(ushort *)((pl->env2).Obj.primitive_top.Data + 0x10);
          uVar12 = uVar12 << 8;
          if (uVar12 < (uint)uVar10) {
            uVar10 = (ushort)uVar12;
          }
          *(ushort *)((pl->env2).Obj.primitive_top.Data + 0x10) = uVar10;
          Stats_SetTanks(200,0x14);
          if ((uint)*(ushort *)((pl->env2).Obj.primitive_top.Data + 0x10) ==
              (uint)*(ushort *)((pl->env2).Obj.primitive_top.Data + 0x1c) << 8) {
            return 0xfffffffe;
          }
        }
        break;
      }
      if (sVar5 != 2) break;
      if (*(short *)((pl->env2).Obj.primitive_top.Data + 0x1a) == 0) {
        return -2;
      }
      uVar10 = *(ushort *)((pl->env2).Obj.primitive_top.Data + 0x14);
      uVar12 = (uint)*(ushort *)((pl->env2).Obj.primitive_top.Data + 0x20);
      if (uVar12 <= (uint)(uVar10 >> 8)) {
        return 0xfffffffe;
      }
      *(ushort *)((pl->env2).Obj.primitive_top.Data + 0x14) = uVar10 + 0x500;
      puVar11 = (undefined *)(uint)*(ushort *)((pl->env2).Obj.primitive_top.Data + 0x14);
      puVar13 = (undefined *)(uVar12 << 8);
      if (puVar13 < puVar11) {
        puVar11 = puVar13;
      }
      uVar10 = *(ushort *)((pl->env2).Obj.primitive_top.Data + 0x20);
      *(short *)((pl->env2).Obj.primitive_top.Data + 0x14) = (short)puVar11;
    }
    if (((uint)puVar11 & 0xffff) == (uint)uVar10 << 8) {
      return -2;
    }
LAB_80087848:
    Stats_SetTanks(200,0x14);
    break;
  case 0x13:
    bVar2 = true;
    break;
  case 0x18:
    p_Var7 = Paf_TestUsePossible((_PLAYER *)&Player);
    uVar12 = SEXT24(*(short *)((int)Pvl_TakenObjects + iVar6 + 0x9c));
    if ((uVar12 != 0x4d) && (uVar12 != 100)) {
      Scts_Interruptors = Scts_Interruptors | uVar12;
    }
    if (p_Var7 == (_D3_OBJECT *)0x0) {
      return 0;
    }
    if ((*(uint *)&p_Var7[1].pos & 0xffffff00) == 0x60700) {
      if (*(short *)((int)Pvl_TakenObjects + iVar6 + 0x9c) != p_Var7[1].last_pos.vy) {
        return 0;
      }
      goto LAB_80087a10;
    }
    if ((p_Var7->handle == (TASK *)0x0) || (p_Var7[1].pos.vz == 0x4d)) {
      sVar5 = p_Var7[1].pos.vz;
    }
    else {
      sVar5 = p_Var7[1].last_pos.vy;
    }
    if (sVar5 != *(short *)((int)Pvl_TakenObjects + iVar6 + 0x9c)) {
      return 0;
    }
    Task_EventExec(p_Var7->handle,6,0);
    if (99 < sVar5) goto LAB_80087a10;
    goto LAB_80087a18;
  case 0x19:
    p_Var7 = Paf_TestUsePossible((_PLAYER *)&Player);
    if (p_Var7 == (_D3_OBJECT *)0x0) {
      return 0;
    }
    if ((p_Var7->display_mode & 0x10U) != 0) {
      return 0;
    }
    if (p_Var7[1].last_pos.vy != *(short *)((int)Pvl_TakenObjects + iVar6 + 0x9c)) {
      return 0;
    }
    p_Var7->display_mode = p_Var7->display_mode | 0x10;
LAB_80087a10:
    _DAT_800b1d54 = 7;
    Pl_ForceAction((_PLAYER *)&Player,0x11,0);
LAB_80087a18:
    Task_EventExec(Overlay_Handle,Overlay_Handle->event_msg | 2,Overlay_Handle->event_param);
    break;
  case 0x1a:
    Inventaire.inv_list[0].pad = '(';
LAB_80087a78:
    Overlay_ChangeLWeapon(pl,(ushort)*(byte *)((int)Pvl_TakenObjects + iVar6 + 0xa4) + 0x10);
    return -7;
  }
  Inventaire.inv_list[0].list[(uint)(byte)Inventaire.inv_list[0].hilite].num =
       Inventaire.inv_list[0].list[(uint)(byte)Inventaire.inv_list[0].hilite].num + -1;
  cVar4 = *(char *)((int)Pvl_TakenObjects + iVar6 + 0xa5) + -1;
  *(char *)((int)Pvl_TakenObjects + iVar6 + 0xa5) = cVar4;
  if (cVar4 == '\0') {
    *(undefined2 *)((int)Pvl_TakenObjects + iVar6 + 0xa8) = 0xffff;
    Invent_RemoveObjInPlayer(pl,Inventaire.inv_list,(uint)(byte)Inventaire.inv_list[0].hilite);
    Invent_Update(pl);
  }
  if ((iVar15 == 0) || (_DAT_800b1e4a == 0)) {
    if (bVar2) {
      Invent_SetAllVisible(pl);
    }
    if (bVar3) {
      if ((pl->m_obj).shadow.y1 != 3) {
        return 1;
      }
      Invent_PlayerReload();
    }
    lVar8 = 1;
  }
  else {
    lVar8 = -4;
    if (iVar15 != 1) {
      lVar8 = -5;
    }
  }
  return lVar8;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_PlayerReload()
 // line 2559, offset 0x80087b84
	/* begin block 1 */
		// Start line: 6263
	/* end block 1 */
	// End Line: 6264

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Invent_PlayerReload(void)

{
  Task_Link(Invent_PlayerReloadTask,0x80);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_PlayerReloadTask()
 // line 2564, offset 0x80087bac
	/* begin block 1 */
		// Start line: 2565
		// Start offset: 0x80087BAC
		// Variables:
	// 		struct _PLAYER *pl; // $s0
	/* end block 1 */
	// End offset: 0x80087BAC
	// End Line: 2565

	/* begin block 2 */
		// Start line: 6274
	/* end block 2 */
	// End Line: 6275

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Invent_PlayerReloadTask(void)

{
  _DAT_800b1d04 = _DAT_800b1d04 & 0xfffe;
  Manim_ForceAnim((M_OBJECT *)&DAT_800b1cdc,0x62);
  Fx_Play(0x3f,100);
  Manim_WaitAnim((M_OBJECT *)&DAT_800b1cdc);
  _DAT_800b1d04 = _DAT_800b1d04 & 0xfffe;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_AutomaticDrop(struct _PLAYER *pl /*$a0*/)
 // line 2581, offset 0x80087c2c
	/* begin block 1 */
		// Start line: 2582
		// Start offset: 0x80087C2C
		// Variables:
	// 		struct _INVENT_LIST *l; // $a3
	// 		long i; // $a1

		/* begin block 1.1 */
			// Start line: 2588
			// Start offset: 0x80087C58
			// Variables:
		// 		char *po; // $v0
		// 		struct _TAKEN_OBJECT *to; // $v0
		/* end block 1.1 */
		// End offset: 0x80087CA8
		// End Line: 2596
	/* end block 1 */
	// End offset: 0x80087CC0
	// End Line: 2597

	/* begin block 2 */
		// Start line: 6314
	/* end block 2 */
	// End Line: 6315

void Invent_AutomaticDrop(_PLAYER *pl)

{
  char cVar1;
  int iVar2;
  
  Inventaire.inv_list[0].hilite = '\0';
  iVar2 = 0;
  if (0 < *(short *)((pl->env2).Obj.primitive_top.Data + 0x22)) {
    do {
      cVar1 = Inventaire.inv_list[0].hilite + '\x01';
      if ((*(ushort *)
            ((int)Pvl_TakenObjects +
            (uint)(pl->env2).Obj.primitive_top.Data
                  [(uint)(byte)Inventaire.inv_list[0].hilite + 0x24] * 0xb0 + 0xa6) & 4) == 0) {
        Invent_DropObject(pl);
        return;
      }
      iVar2 = iVar2 + 1;
      Inventaire.inv_list[0].hilite = cVar1;
    } while (iVar2 < (int)*(short *)((pl->env2).Obj.primitive_top.Data + 0x22));
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Invent_DropObject(struct _PLAYER *pl /*$s2*/)
 // line 2600, offset 0x80087cd0
	/* begin block 1 */
		// Start line: 2601
		// Start offset: 0x80087CD0
		// Variables:
	// 		struct _INVENT_LIST *l; // $s1
	// 		char *po; // $v0
	// 		struct _TAKEN_OBJECT *to; // $s0
	/* end block 1 */
	// End offset: 0x80087DDC
	// End Line: 2633

	/* begin block 2 */
		// Start line: 6362
	/* end block 2 */
	// End Line: 6363

long Invent_DropObject(_PLAYER *pl)

{
  short sVar1;
  _PVL_HEADER *p_Var2;
  int iVar3;
  long lVar4;
  uint uVar5;
  
  uVar5 = (uint)(byte)Inventaire.inv_list[0].hilite;
  iVar3 = (uint)(pl->env2).Obj.primitive_top.Data[uVar5 + 0x24] * 0xb0;
  lVar4 = 0;
  if ((*(ushort *)((int)Pvl_TakenObjects + iVar3 + 0xa6) & 4) == 0) {
    if (*(short *)((int)Pvl_TakenObjects + iVar3 + 0x9a) == 0x1b) {
      lVar4 = 0;
    }
    else {
      lVar4 = 0;
      if (Inventaire.inv_list[0].list[uVar5].num != '\0') {
        Inventaire.inv_list[0].list[uVar5].num = '\0';
        p_Var2 = Pvl_File;
        *(ushort *)((int)Pvl_TakenObjects + iVar3 + 0xa6) =
             *(ushort *)((int)Pvl_TakenObjects + iVar3 + 0xa6) | 2;
        sVar1 = p_Var2->crc;
        *(undefined4 *)((int)Pvl_TakenObjects + iVar3 + 0xa0) = 0x1234;
        *(short *)((int)Pvl_TakenObjects + iVar3 + 0xa8) = sVar1;
        Invent_LaunchD3Object(pl,(ushort)(byte)Inventaire.inv_list[0].hilite);
        Fx_Play(0x3e,(char)pl + ',');
        *(short *)((int)Pvl_TakenObjects + iVar3 + 0xa8) = Pvl_File->crc;
        Invent_RemoveObjInPlayer(pl,Inventaire.inv_list,(uint)(byte)Inventaire.inv_list[0].hilite);
        Invent_Update(pl);
        lVar4 = 1;
      }
    }
  }
  return lVar4;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_LaunchD3Object(struct _PLAYER *pl /*$a2*/, short num /*$a1*/)
 // line 2636, offset 0x80087df4
	/* begin block 1 */
		// Start line: 2637
		// Start offset: 0x80087DF4
		// Variables:
	// 		struct _TAKEN_OBJECT *to; // $s0
	// 		struct _INVENT_LIST *l; // $v1
	/* end block 1 */
	// End offset: 0x80087DF4
	// End Line: 2637

	/* begin block 2 */
		// Start line: 6439
	/* end block 2 */
	// End Line: 6440

void Invent_LaunchD3Object(_PLAYER *pl,short num)

{
  TASK *pTVar1;
  undefined4 uVar2;
  int iVar3;
  _TAKEN_OBJECT *obj;
  
  iVar3 = (int)Inventaire.inv_list[0].list[(int)num].index * 0xb0;
  obj = (_TAKEN_OBJECT *)((int)Pvl_TakenObjects + iVar3);
  *(undefined2 *)((int)Pvl_TakenObjects + iVar3 + 0x3c) = 0;
  *(undefined2 *)((int)Pvl_TakenObjects + iVar3 + 0x3e) = 0;
  *(short *)((int)Pvl_TakenObjects + iVar3 + 0x40) = (pl->obj).rot.vz;
  uVar2 = *(undefined4 *)&(pl->obj).pos.vz;
  *(undefined4 *)((int)Pvl_TakenObjects + iVar3 + 0x2c) = *(undefined4 *)&(pl->obj).pos;
  *(undefined4 *)((int)Pvl_TakenObjects + iVar3 + 0x30) = uVar2;
  *(undefined4 *)((int)Pvl_TakenObjects + iVar3 + 0x34) =
       *(undefined4 *)((int)Pvl_TakenObjects + iVar3 + 0x2c);
  *(undefined4 *)((int)Pvl_TakenObjects + iVar3 + 0x38) =
       *(undefined4 *)((int)Pvl_TakenObjects + iVar3 + 0x30);
  *(undefined4 *)((int)Pvl_TakenObjects + iVar3 + 0x14) = 0;
  *(undefined2 *)((int)Pvl_TakenObjects + iVar3 + 0x5a) = 0;
  D3_InsertObject((_D3_OBJECT *)obj,&Pvl_GlobalObjects);
  D3_SetCollBits((_D3_OBJECT *)obj,0x201);
  D3_ClearCollBits((_D3_OBJECT *)obj,0x88);
  pTVar1 = Task_Link(CB_BonusTask,0x300);
  *(TASK **)((int)Pvl_TakenObjects + iVar3 + 0x14) = pTVar1;
  *(_TAKEN_OBJECT **)&pTVar1->local = obj;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_ReleaseLocalObjects()
 // line 2672, offset 0x80087ef0
	/* begin block 1 */
		// Start line: 2673
		// Start offset: 0x80087EF0
		// Variables:
	// 		struct _TAKEN_OBJECT *to; // $s2
	// 		long i; // $s0
	/* end block 1 */
	// End offset: 0x80087FA8
	// End Line: 2704

	/* begin block 2 */
		// Start line: 6546
	/* end block 2 */
	// End Line: 6547

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Invent_ReleaseLocalObjects(void)

{
  short *psVar1;
  int type;
  
  BOSS_DISPLAY = 0;
  Invent_UseInventBack((_PLAYER *)&Player);
  type = 7;
  do {
    Invent_RemoveUsedObject(type,0,0);
    type = type + 1;
  } while (type < 0xf);
  type = 0x12;
  do {
    if (type != 0x14) {
      Invent_RemoveUsedObject(type,0,0);
    }
    type = type + 1;
  } while (type < 0x1a);
  type = 0;
  psVar1 = &Pvl_TakenObjects[1].obj.pos.vz;
  do {
    if ((psVar1[-1] & 2U) != 0) {
      psVar1[-1] = 0;
      *(undefined *)((int)psVar1 + -3) = 0;
      *psVar1 = -1;
    }
    type = type + 1;
    psVar1 = psVar1 + 0x58;
  } while (type < 0x20);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_DeleteDropped()
 // line 2707, offset 0x80087fc0
	/* begin block 1 */
		// Start line: 2708
		// Start offset: 0x80087FC0
		// Variables:
	// 		struct _TAKEN_OBJECT *to; // $v0
	// 		long i; // $s1
	/* end block 1 */
	// End offset: 0x8008800C
	// End Line: 2723

	/* begin block 2 */
		// Start line: 6635
	/* end block 2 */
	// End Line: 6636

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Invent_DeleteDropped(void)

{
  TASK **ppTVar1;
  int iVar2;
  
  iVar2 = 0;
  ppTVar1 = &Pvl_TakenObjects[0].obj.handle;
  do {
    if (*ppTVar1 != (TASK *)0x0) {
      Task_Kill(*ppTVar1);
      *ppTVar1 = (TASK *)0x0;
    }
    iVar2 = iVar2 + 1;
    ppTVar1 = ppTVar1 + 0x2c;
  } while (iVar2 < 0x20);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_InitTakenObjects()
 // line 2732, offset 0x80088020
	/* begin block 1 */
		// Start line: 2734
		// Start offset: 0x80088020
		// Variables:
	// 		long i; // $a1
	// 		long j; // $a0
	// 		struct _TAKEN_OBJECT *to; // $v0
	/* end block 1 */
	// End offset: 0x80088080
	// End Line: 2755

	/* begin block 2 */
		// Start line: 6705
	/* end block 2 */
	// End Line: 6706

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Invent_InitTakenObjects(void)

{
  _TAKEN_OBJECT *p_Var1;
  _TAKEN_OBJECT *p_Var2;
  uint uVar3;
  int iVar4;
  
  p_Var2 = Pvl_TakenObjects;
  if (Pvl_LoadedGame == 0) {
    iVar4 = 0;
    do {
      uVar3 = 0;
      *(undefined *)((int)&p_Var2[1].obj.pos.vx + 1) = 0;
      p_Var2[1].obj.pos.vy = 0;
      p_Var2[1].obj.pos.pad = 0;
      p_Var2[1].obj.pos.vz = -1;
      p_Var1 = p_Var2;
      do {
        *(undefined *)&(p_Var1->obj).next = 0;
        uVar3 = uVar3 + 1;
        p_Var1 = (_TAKEN_OBJECT *)((int)&(p_Var2->obj).next + uVar3);
      } while (uVar3 < 0xa4);
      iVar4 = iVar4 + 1;
      p_Var2 = (_TAKEN_OBJECT *)&p_Var2[1].obj.last_pos.vz;
    } while (iVar4 < 0x20);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_SetTakenObjects()
 // line 2759, offset 0x80088088
	/* begin block 1 */
		// Start line: 2760
		// Start offset: 0x80088088
		// Variables:
	// 		long i; // $s1
	// 		struct _TAKEN_OBJECT *to; // $s2

		/* begin block 1.1 */
			// Start line: 2794
			// Start offset: 0x80088138
		/* end block 1.1 */
		// End offset: 0x800881A0
		// End Line: 2810
	/* end block 1 */
	// End offset: 0x800881B0
	// End Line: 2812

	/* begin block 2 */
		// Start line: 6777
	/* end block 2 */
	// End Line: 6778

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Invent_SetTakenObjects(void)

{
  TASK *pTVar1;
  short *psVar2;
  TASK **ppTVar3;
  int iVar4;
  _TAKEN_OBJECT *obj;
  
  obj = Pvl_TakenObjects;
  Invent_InitLoaded();
  iVar4 = 0;
  psVar2 = &Invent_Param;
  Shoot_NbShots = 0;
  BOSS_DISPLAY = 0;
  do {
    if (-1 < (int)*psVar2) {
      Invent_InitGlobalObject((int)*psVar2);
      *psVar2 = -1;
    }
    iVar4 = iVar4 + 1;
    psVar2 = psVar2 + 1;
  } while (iVar4 < 6);
  iVar4 = 0x20;
  ppTVar3 = &Pvl_TakenObjects[0].obj.handle;
  Inventaire.inv_list[0].hilite = '\0';
  Inventaire.inv_list[0].deb_list = '\0';
  do {
    if (((*(ushort *)((int)ppTVar3 + 0x92) & 2) != 0) &&
       (*(short *)(ppTVar3 + 0x25) == Pvl_File->crc)) {
      D3_InsertObject((_D3_OBJECT *)obj,&Pvl_GlobalObjects);
      if (*(short *)((int)ppTVar3 + 0x86) != 0x16) {
        *(short *)(ppTVar3 + 7) = *(short *)(ppTVar3 + 7) + -0x32;
      }
      if ((*(ushort *)((int)ppTVar3 + 6) & 0x1000) != 0) {
        *(short *)(ppTVar3 + 7) = *(short *)(ppTVar3 + 7) + -0x32;
      }
      pTVar1 = Task_Link(CB_BonusTask,0x300);
      *ppTVar3 = pTVar1;
      *(_TAKEN_OBJECT **)&pTVar1->local = obj;
    }
    iVar4 = iVar4 + -1;
    ppTVar3 = ppTVar3 + 0x2c;
    obj = (_TAKEN_OBJECT *)&obj[1].obj.last_pos.vz;
  } while (iVar4 != 0);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Invent_InitGlobalObject(long glob_index /*$s4*/)
 // line 2816, offset 0x800881cc
	/* begin block 1 */
		// Start line: 2817
		// Start offset: 0x800881CC
		// Variables:
	// 		struct _TAKEN_OBJECT *to; // $s0
	// 		struct _D3_OBJECT *o; // $s1
	// 		struct INVENTRY_7fake min; // stack offset -40
	// 		struct INVENTRY_7fake max; // stack offset -32
	// 		long i; // $a0
	// 		long value; // $v1
	// 		long index; // $s3
	// 		long type; // $s1
	// 		long elem; // $s2
	/* end block 1 */
	// End offset: 0x800884A0
	// End Line: 2907

	/* begin block 2 */
		// Start line: 6931
	/* end block 2 */
	// End Line: 6932

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long Invent_InitGlobalObject(long glob_index)

{
  short type;
  short sVar1;
  undefined uVar2;
  short sVar3;
  long lVar4;
  void *pvVar5;
  int local_34;
  long xz;
  int local_38;
  int iVar6;
  long nx;
  long ny;
  long nz;
  short local_28;
  short local_26;
  short local_24;
  short local_20;
  short local_1e;
  short local_1c;
  
  type = Invent_TabOptions[glob_index * 2];
  sVar1 = *(short *)((int)Invent_TabOptions + (glob_index << 2 | 2U));
  sVar3 = Invent_GetNbObjects(type,0);
  if (sVar3 != 0) {
    iVar6 = 0;
    if (0 < (int)_DAT_800b1e4a) {
      do {
        local_38 = (uint)(byte)(&DAT_800b1e4c)[iVar6] * 0xb0;
        if (((uint)*(byte *)((int)Pvl_TakenObjects + local_38 + 0xa4) == (int)type) &&
           (*(short *)((int)Pvl_TakenObjects + local_38 + 0x9c) == sVar1)) {
          *(char *)((int)Pvl_TakenObjects + local_38 + 0xa5) =
               *(char *)((int)Pvl_TakenObjects + local_38 + 0xa5) + '\x01';
          return (uint)(byte)(&DAT_800b1e4c)[iVar6];
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < (int)_DAT_800b1e4a);
    }
  }
  lVar4 = Invent_GetFreeTakenObject();
  iVar6 = lVar4 * 0xb0;
  local_38 = (int)_DAT_800b1e4a;
  _DAT_800b1e4a = _DAT_800b1e4a + 1;
  (&DAT_800b1e4c)[local_38] = (char)lVar4;
  pvVar5 = FileGroup_GetAddr(Pvl_LnkGlobals,(int)(short)(ushort)glob_index);
  *(void **)((int)Pvl_TakenObjects + iVar6 + 0x24) = pvVar5;
  *(undefined2 *)((int)Pvl_TakenObjects + iVar6 + 0x18) = 0xffff;
  *(ushort *)((int)Pvl_TakenObjects + iVar6 + 0x62) = ~(ushort)glob_index;
  *(short *)((int)Pvl_TakenObjects + iVar6 + 0x9a) = type;
  *(undefined *)((int)Pvl_TakenObjects + iVar6 + 0x99) = 3;
  *(undefined2 *)((int)Pvl_TakenObjects + iVar6 + 0x20) = 0;
  *(undefined *)((int)Pvl_TakenObjects + iVar6 + 0x22) = 0;
  *(undefined *)((int)Pvl_TakenObjects + iVar6 + 0x23) = 0;
  *(undefined2 *)((int)Pvl_TakenObjects + iVar6 + 0x5a) = 0;
  *(short *)((int)Pvl_TakenObjects + iVar6 + 0x9c) = sVar1;
  if (((uint)(int)type < 2) || (type == 0x1a)) {
    *(ushort *)((int)Pvl_TakenObjects + iVar6 + 0x1a) =
         *(ushort *)((int)Pvl_TakenObjects + iVar6 + 0x1a) | 0x1000;
  }
  *(ushort *)((int)Pvl_TakenObjects + iVar6 + 0x1a) =
       *(ushort *)((int)Pvl_TakenObjects + iVar6 + 0x1a) | 0x13;
  D3_SetCollBits((_D3_OBJECT *)(_TAKEN_OBJECT *)((int)Pvl_TakenObjects + iVar6),0x201);
  nx = -0x28;
  if ((*(ushort *)((int)Pvl_TakenObjects + iVar6 + 0x1a) & 0x1000) == 0) {
    local_38 = *(int *)((int)Pvl_TakenObjects + iVar6 + 0x24) + 0xc;
    *(int *)((int)Pvl_TakenObjects + iVar6 + 0x24) = local_38;
    Tmd_GetBox((char)local_38,0xd8,0xe0);
    local_38 = (int)local_20;
    nx = (long)local_28;
    ny = (long)local_26;
    nz = (long)local_24;
    local_34 = (int)local_1e;
    xz = (long)local_1c;
  }
  else {
    ny = -0x28;
    nz = -0x28;
    xz = 0x28;
    local_38 = 0x28;
    local_34 = 0x28;
  }
  D3_SetBox((_D3_OBJECT *)(_TAKEN_OBJECT *)((int)Pvl_TakenObjects + iVar6),nx,ny,nz,local_38,
            local_34,xz);
  *(undefined2 *)((int)Pvl_TakenObjects + iVar6 + 0xa8) = 0;
  *(undefined *)((int)Pvl_TakenObjects + iVar6 + 0xa4) =
       *(undefined *)((int)Pvl_TakenObjects + iVar6 + 0x9a);
  local_38 = (int)*(short *)((int)Pvl_TakenObjects + iVar6 + 0x9c);
  if (-1 < local_38) {
    *(ushort *)((int)Pvl_TakenObjects + iVar6 + 0xa6) =
         *(ushort *)((int)Pvl_TakenObjects + iVar6 + 0xa6) | (ushort)(1 << (local_38 + 0xcU & 0x1f))
    ;
  }
  uVar2 = 5;
  if (1 < (uint)*(ushort *)((int)Pvl_TakenObjects + iVar6 + 0x9a) - 5) {
    uVar2 = 1;
  }
  *(undefined *)((int)Pvl_TakenObjects + iVar6 + 0xa5) = uVar2;
  Invent_Update((_PLAYER *)&Player);
  Overlay_ChangeLWeapon((_PLAYER *)&Player,0);
  return lVar4;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_InitLoaded()
 // line 2910, offset 0x800884c0
	/* begin block 1 */
		// Start line: 2911
		// Start offset: 0x800884C0
		// Variables:
	// 		long i; // $s4
	// 		struct _TAKEN_OBJECT *to; // $s3
	// 		struct _D3_OBJECT *o; // $s1

		/* begin block 1.1 */
			// Start line: 2921
			// Start offset: 0x8008850C
			// Variables:
		// 		char index; // $a1
		/* end block 1.1 */
		// End offset: 0x800885F8
		// End Line: 2966
	/* end block 1 */
	// End offset: 0x8008860C
	// End Line: 2967

	/* begin block 2 */
		// Start line: 7241
	/* end block 2 */
	// End Line: 7242

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Invent_InitLoaded(void)

{
  byte bVar1;
  void *pvVar2;
  int Index;
  ushort *puVar3;
  _TAKEN_OBJECT *p_Var4;
  int iVar5;
  
  p_Var4 = Pvl_TakenObjects;
  if (Pvl_LoadedGame != 0) {
    iVar5 = 0;
    puVar3 = (ushort *)&Pvl_TakenObjects[1].obj.pos.vy;
    do {
      if (puVar3[1] != 0xffff) {
        if (*(char *)(puVar3 + -0x22) < -0x40) {
          pvVar2 = FileGroup_GetAddr(Pvl_LnkLocals,(int)(char)-(*(byte *)(puVar3 + -0x22) + 0x41));
          *(void **)(puVar3 + -0x41) = pvVar2;
        }
        else {
          Index = (int)(char)~*(byte *)(puVar3 + -0x22);
          pvVar2 = FileGroup_GetAddr(Pvl_LnkGlobals,Index);
          *(void **)(puVar3 + -0x41) = pvVar2;
          puVar3[-5] = *(ushort *)((int)Invent_TabOptions + (Index << 2 | 2U));
        }
        if (((p_Var4->obj).display_mode & 0x1000U) == 0) {
          (p_Var4->obj).description = (void *)((int)(p_Var4->obj).description + 0xc);
        }
        (p_Var4->obj).index = -1;
        (p_Var4->obj).hit_points = 0;
        (p_Var4->obj).hit_power = '\0';
        (p_Var4->obj).exp = '\0';
        *(undefined2 *)((int)&(p_Var4->obj).b_hurt + 2) = 0;
        *(undefined *)((int)&p_Var4[1].obj.hit_points + 1) = 3;
        bVar1 = *(byte *)(puVar3 + -1);
        p_Var4[1].obj.color = 0;
        *(ushort *)&p_Var4[1].obj.hit_power = (ushort)bVar1;
        if ((*puVar3 & 2) != 0) {
          p_Var4[1].obj.color = 0x1234;
        }
        (p_Var4->obj).collision_mode = 0x201;
      }
      iVar5 = iVar5 + 1;
      puVar3 = puVar3 + 0x58;
      p_Var4 = (_TAKEN_OBJECT *)&p_Var4[1].obj.last_pos.vz;
    } while (iVar5 < 0x20);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_InitAlertWindow()
 // line 2976, offset 0x80088634
	/* begin block 1 */
		// Start line: 2978
		// Start offset: 0x80088634
		// Variables:
	// 		long i; // $a2
	// 		long j; // $a0
	// 		struct INVENTRY_36fake *pl; // $v0
	/* end block 1 */
	// End offset: 0x80088698
	// End Line: 2993

	/* begin block 2 */
		// Start line: 7441
	/* end block 2 */
	// End Line: 7442

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Invent_InitAlertWindow(void)

{
  _ALERT_WINDOW *p_Var1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  
  iVar4 = 0;
  puVar3 = &DAT_800b31b0;
  do {
    iVar2 = 0;
    puVar3[3] = 5;
    puVar3[7] = 0x28;
    p_Var1 = &Alert_Window;
    do {
      iVar2 = iVar2 + 1;
      *(undefined *)((int)&(&p_Var1->BackLine)[iVar4 * 2].tag + 3) = 3;
      *(undefined *)((int)&(&p_Var1->BackLine)[iVar4 * 2].tag + 7) = 0x40;
      p_Var1 = (_ALERT_WINDOW *)&p_Var1->BackGround;
    } while (iVar2 < 2);
    iVar4 = iVar4 + 1;
    puVar3 = puVar3 + 0x18;
  } while (iVar4 < 2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_Alert(char *message /*$a0*/, short mode /*$a1*/)
 // line 2996, offset 0x800886a0
	/* begin block 1 */
		// Start line: 2997
		// Start offset: 0x800886A0
		// Variables:
	// 		struct INVENTRY_29fake *p; // $v1
	// 		struct INVENTRY_36fake *pl; // $t1
	// 		struct INVENTRY_8fake col1; // stack offset -24
	// 		struct INVENTRY_8fake col2; // stack offset -16
	/* end block 1 */
	// End offset: 0x80088750
	// End Line: 3020

	/* begin block 2 */
		// Start line: 7488
	/* end block 2 */
	// End Line: 7489

void Invent_Alert(char *message,short mode)

{
  _SCREEN *p_Var1;
  short sVar2;
  short sVar3;
  int iVar4;
  uint *puVar5;
  _struct_698 *p_Var6;
  _struct_699 *p_Var7;
  uchar local_18;
  uchar local_17;
  uchar local_16;
  undefined local_10;
  undefined local_f;
  undefined local_e;
  
  if (mode == 1) {
    local_17 = 'd';
    local_18 = 'd';
    local_16 = -6;
    local_f = 0x14;
    local_10 = 0x14;
    local_e = 0x46;
  }
  else {
    if (mode < 2) {
      if (mode == 0) {
        local_16 = 'd';
        local_17 = 'd';
        local_18 = 'd';
        local_e = 0x14;
        local_f = 0x14;
        local_10 = 0x14;
      }
    }
    else {
      if (mode == 2) {
        local_18 = -6;
        local_16 = 'd';
        local_17 = 'd';
        local_10 = 100;
        local_e = 0x1e;
        local_f = 0x1e;
      }
    }
  }
  Text_SetText(message,-0x7ffe,(short)(((uint)(ushort)Inventaire.posy - 0x1e) * 0x10000 >> 0x10));
  iVar4 = (int)Scr_Frame;
  p_Var6 = &Alert_Window.BackLine + iVar4 * 2;
  (&Alert_Window.BackLine)[iVar4 * 2].x0 = 0;
  sVar3 = Inventaire.posy + -0x23;
  (&Alert_Window.BackLine)[iVar4 * 2].x1 = Scr_W;
  (&Alert_Window.BackLine)[iVar4 * 2].y0 = sVar3;
  (&Alert_Window.BackLine)[iVar4 * 2].y1 = Inventaire.posy + -0x23;
  (&Alert_Window.BackLine)[iVar4 * 2].r0 = local_18;
  (&Alert_Window.BackLine)[iVar4 * 2].g0 = local_17;
  (&Alert_Window.BackLine)[iVar4 * 2].b0 = local_16;
  p_Var1 = Scr;
  p_Var6->tag = p_Var6->tag & 0xff000000 | Scr->ot[1] & 0xffffff;
  sVar2 = Scr_W;
  iVar4 = (int)Scr_Frame * 0x20;
  p_Var7 = (_struct_699 *)((int)&Alert_Window.BackGround + iVar4);
  p_Var1->ot[1] = p_Var1->ot[1] & 0xff000000 | (uint)p_Var6 & 0xffffff;
  *(undefined2 *)((int)&Alert_Window.BackGround + iVar4 + 8) = 0;
  sVar3 = Inventaire.posy;
  *(short *)((int)&Alert_Window.BackGround + iVar4 + 0xc) = sVar2;
  *(short *)((int)&Alert_Window.BackGround + iVar4 + 10) = sVar3 + -0x14;
  *(short *)((int)&Alert_Window.BackGround + iVar4 + 0xe) = Inventaire.posy + -0x14;
  *(uchar *)((int)&Alert_Window.BackGround + iVar4 + 4) = local_18;
  *(uchar *)((int)&Alert_Window.BackGround + iVar4 + 5) = local_17;
  *(uchar *)((int)&Alert_Window.BackGround + iVar4 + 6) = local_16;
  p_Var1 = Scr;
  p_Var7->tag = p_Var7->tag & 0xff000000 | Scr->ot[1] & 0xffffff;
  iVar4 = (int)Scr_Frame * 0x18;
  p_Var1->ot[1] = p_Var1->ot[1] & 0xff000000 | (uint)p_Var7 & 0xffffff;
  *(undefined2 *)(&DAT_800b31b8 + iVar4) = 0;
  sVar2 = Scr_W;
  sVar3 = Inventaire.posy + -0x23;
  *(short *)(&DAT_800b31bc + iVar4) = Scr_W;
  *(short *)(&DAT_800b31ba + iVar4) = sVar3;
  sVar3 = Inventaire.posy;
  *(undefined2 *)(&DAT_800b31c0 + iVar4) = 0;
  *(short *)(&DAT_800b31be + iVar4) = sVar3 + -0x23;
  sVar3 = Inventaire.posy;
  *(short *)(&DAT_800b31c4 + iVar4) = sVar2;
  *(short *)(&DAT_800b31c2 + iVar4) = sVar3 + -0x14;
  *(short *)(&DAT_800b31c6 + iVar4) = Inventaire.posy + -0x14;
  (&DAT_800b31b4)[iVar4] = local_10;
  (&DAT_800b31b5)[iVar4] = local_f;
  (&DAT_800b31b6)[iVar4] = local_e;
  p_Var1 = Scr;
  puVar5 = (uint *)(&DAT_800b31b0 + (int)Scr_Frame * 0x18);
  *puVar5 = *puVar5 & 0xff000000 | Scr->ot[1] & 0xffffff;
  p_Var1->ot[1] = p_Var1->ot[1] & 0xff000000 | (uint)puVar5 & 0xffffff;
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ Invent_GetElemNumber(struct _TAKEN_OBJECT *to /*$a0*/)
 // line 3040, offset 0x800889a8
	/* begin block 1 */
		// Start line: 7596
	/* end block 1 */
	// End Line: 7597

short Invent_GetElemNumber(_TAKEN_OBJECT *to)

{
  uint uVar1;
  
  uVar1 = (int)to[1].obj.pos.vy & 0xf000;
  if (uVar1 == 0x2000) {
    return 1;
  }
  if (uVar1 < 0x2001) {
    if (uVar1 == 0x1000) {
      return 0;
    }
  }
  else {
    if (uVar1 == 0x4000) {
      return 2;
    }
    if (uVar1 == 0x8000) {
      return 3;
    }
  }
  return -1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_UpdateMultiObject(struct _TAKEN_OBJECT *to /*$s0*/, struct _D3_OBJECT *obj /*$s1*/)
 // line 3058, offset 0x80088a1c
	/* begin block 1 */
		// Start line: 3059
		// Start offset: 0x80088A1C
		// Variables:
	// 		long value; // $a0
	/* end block 1 */
	// End offset: 0x80088A80
	// End Line: 3071

	/* begin block 2 */
		// Start line: 7631
	/* end block 2 */
	// End Line: 7632

void Invent_UpdateMultiObject(_TAKEN_OBJECT *to,_D3_OBJECT *obj)

{
  ushort uVar1;
  
  uVar1 = to[1].obj.pos.pad;
  if (to[1].obj.pos.pad == 0) {
    to[1].obj.pos.pad = uVar1 | (ushort)(1 << ((int)obj[1].pos.vz & 0x1fU));
  }
  else {
    to[1].obj.pos.pad = uVar1 | (ushort)(1 << ((int)obj[1].pos.vz & 0x1fU));
    Invent_FlyObject(to,(int)obj[1].pos.vz);
  }
  *(short *)((int)&to[1].obj.description + 2) = obj[1].pos.pad;
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Invent_MultiIsComplete(struct _TAKEN_OBJECT *to /*$a0*/)
 // line 3075, offset 0x80088aa0
	/* begin block 1 */
		// Start line: 3077
		// Start offset: 0x80088AA0
		// Variables:
	// 		long n; // $a3
	// 		long i; // $a2
	// 		long value; // $v1
	// 		long mask; // $a1
	/* end block 1 */
	// End offset: 0x80088AD0
	// End Line: 3083

	/* begin block 2 */
		// Start line: 7669
	/* end block 2 */
	// End Line: 7670

long Invent_MultiIsComplete(_TAKEN_OBJECT *to)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  uVar2 = 1;
  iVar4 = *(int *)((int)(to->obj).description + 8);
  uVar1 = 0;
  if (0 < iVar4) {
    do {
      uVar1 = uVar1 | uVar2;
      iVar3 = iVar3 + 1;
      uVar2 = uVar2 << 1;
    } while (iVar3 < iVar4);
  }
  return (uint)(uVar1 == (int)to[1].obj.pos.pad);
}



// decompiled code
// original method signature: 
// long /*$ra*/ Invent_IsMultiPresent(long multi_number /*$a0*/, long subobject_index /*$a1*/)
 // line 3087, offset 0x80088ae4
	/* begin block 1 */
		// Start line: 3089
		// Start offset: 0x80088AE4
		// Variables:
	// 		struct _TAKEN_OBJECT *to; // $v1
	// 		long FOUND; // $t0
	// 		long i; // $a2
	// 		long value; // $v1
	/* end block 1 */
	// End offset: 0x80088B8C
	// End Line: 3113

	/* begin block 2 */
		// Start line: 7702
	/* end block 2 */
	// End Line: 7703

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long Invent_IsMultiPresent(long multi_number,long subobject_index)

{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  _TAKEN_OBJECT *in_v1;
  int iVar4;
  
  bVar1 = false;
  if (0 < (int)_DAT_800b1e4a) {
    puVar2 = &Player;
    iVar4 = 0;
    do {
      iVar3 = (uint)(byte)puVar2[0x214] * 0xb0;
      in_v1 = (_TAKEN_OBJECT *)((int)Pvl_TakenObjects + iVar3);
      if ((*(char *)((int)Pvl_TakenObjects + iVar3 + 0xa4) == '\x14') &&
         (multi_number == (int)*(short *)((int)Pvl_TakenObjects + iVar3 + 0x9e))) {
        bVar1 = true;
        break;
      }
      iVar3 = iVar4 + 1;
      puVar2 = (undefined *)(iVar4 + -0x7ff4e3c7);
      iVar4 = iVar3;
    } while (iVar3 < (int)_DAT_800b1e4a);
  }
  if (bVar1) {
    return (uint)(((int)in_v1[1].obj.pos.pad & 1 << (subobject_index & 0x1fU)) != 0);
  }
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_SetAllInvisible(struct _PLAYER *pl /*$s3*/)
 // line 3116, offset 0x80088b94
	/* begin block 1 */
		// Start line: 3117
		// Start offset: 0x80088B94
		// Variables:
	// 		long i; // $a1
	// 		long j; // $a0
	// 		long glob_index; // $s2
	// 		long index; // $v0
	// 		struct _TAKEN_OBJECT *to; // $s4

		/* begin block 1.1 */
			// Start line: 3125
			// Start offset: 0x80088BC8
			// Variables:
		// 		long percent; // $s0
		/* end block 1.1 */
		// End offset: 0x80088C28
		// End Line: 3136
	/* end block 1 */
	// End offset: 0x80088D38
	// End Line: 3175

	/* begin block 2 */
		// Start line: 7769
	/* end block 2 */
	// End Line: 7770

void Invent_SetAllInvisible(_PLAYER *pl)

{
  long lVar1;
  _PLAYER *p_Var2;
  short *psVar3;
  int iVar4;
  _INVENTAIRE *p_Var5;
  int iVar6;
  int glob_index;
  _TAKEN_OBJECT *unaff_s4;
  
  glob_index = 0xb;
  p_Var2 = pl;
  do {
    iVar6 = 0x1e;
    lVar1 = Invent_InitGlobalObject(glob_index);
    iVar4 = 0;
    do {
      if (iVar6 < (int)*(short *)((p_Var2->env1).Obj.primitive_top.Data + 0x1a)) {
        *(char *)((int)Pvl_TakenObjects + lVar1 * 0xb0 + 0xa5) =
             *(char *)((int)Pvl_TakenObjects + lVar1 * 0xb0 + 0xa5) + '\x01';
      }
      iVar4 = iVar4 + 1;
      iVar6 = iVar6 + 0x14;
    } while (iVar4 < 4);
    *(undefined2 *)((p_Var2->env1).Obj.primitive_top.Data + 0x1a) = 0;
    p_Var2 = (_PLAYER *)&(p_Var2->obj).child;
    glob_index = glob_index + 1;
  } while ((int)p_Var2 < (int)&(pl->obj).hit_points);
  glob_index = 0;
  p_Var2 = pl;
  if (0 < *(short *)((pl->env2).Obj.primitive_top.Data + 0x22)) {
    do {
      iVar4 = (uint)(p_Var2->env2).Obj.primitive_top.Data[0x24] * 0xb0;
      unaff_s4 = (_TAKEN_OBJECT *)((int)Pvl_TakenObjects + iVar4);
      *(ushort *)((int)Pvl_TakenObjects + iVar4 + 0xa6) =
           *(ushort *)((int)Pvl_TakenObjects + iVar4 + 0xa6) | 8;
      glob_index = glob_index + 1;
      p_Var2 = (_PLAYER *)((int)&(pl->obj).next + glob_index);
    } while (glob_index < (int)*(short *)((pl->env2).Obj.primitive_top.Data + 0x22));
  }
  glob_index = 0;
  Inventaire.spells_invisible = (pl->env2).Obj.n_vert;
  p_Var5 = &Inventaire;
  *(undefined2 *)((pl->env2).Obj.primitive_top.Data + 0x22) = 0;
  (pl->env2).Obj.n_vert = 0;
  p_Var2 = pl;
  do {
    glob_index = glob_index + 1;
    p_Var5->spells_levels[0] = *(long *)&(p_Var2->env2).Obj.normal_top;
    *(undefined4 *)&(p_Var2->env2).Obj.normal_top = 0;
    p_Var2 = (_PLAYER *)&(p_Var2->obj).prec;
    p_Var5 = (_INVENTAIRE *)&p_Var5->helpx;
  } while (glob_index < 2);
  iVar4 = 3;
  glob_index = (int)&(pl->obj).next + 3;
  do {
    *(undefined *)(glob_index + 0x1e8) = 0x80;
    iVar4 = iVar4 + -1;
    glob_index = glob_index + -1;
  } while (-1 < iVar4);
  glob_index = 0;
  psVar3 = &unaff_s4[1].obj.pos.vz;
  do {
    if ((psVar3[-1] & 2U) != 0) {
      psVar3[-1] = 0;
      *(undefined *)((int)psVar3 + -3) = 0;
      *psVar3 = -1;
    }
    glob_index = glob_index + 1;
    psVar3 = psVar3 + 0x58;
  } while (glob_index < 0x20);
  Inventaire.inv_list[0].hilite = '\0';
  Inventaire.inv_list[1].hilite = '\0';
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Invent_CountInvisible()
 // line 3180, offset 0x80088d64
	/* begin block 1 */
		// Start line: 3182
		// Start offset: 0x80088D64
		// Variables:
	// 		struct _TAKEN_OBJECT *to; // $a0
	// 		long i; // $v1
	// 		long nInvisible; // $a1
	/* end block 1 */
	// End offset: 0x80088D98
	// End Line: 3191

	/* begin block 2 */
		// Start line: 7961
	/* end block 2 */
	// End Line: 7962

/* WARNING: Unknown calling convention yet parameter storage is locked */

long Invent_CountInvisible(void)

{
  int iVar1;
  _TAKEN_OBJECT *p_Var2;
  long lVar3;
  
  p_Var2 = Pvl_TakenObjects;
  lVar3 = 0;
  iVar1 = 0x1f;
  do {
    if ((p_Var2[1].obj.pos.vy & 8U) != 0) {
      lVar3 = lVar3 + 1;
    }
    iVar1 = iVar1 + -1;
    p_Var2 = (_TAKEN_OBJECT *)&p_Var2[1].obj.last_pos.vz;
  } while (-1 < iVar1);
  return lVar3;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_SetAllVisible(struct _PLAYER *pl /*$s3*/)
 // line 3195, offset 0x80088da0
	/* begin block 1 */
		// Start line: 3196
		// Start offset: 0x80088DA0
		// Variables:
	// 		struct _TAKEN_OBJECT *to; // $s5
	// 		long i; // $s1
	// 		long value; // $s4

		/* begin block 1.1 */
			// Start line: 3202
			// Start offset: 0x80088DD8

			/* begin block 1.1.1 */
				// Start line: 3227
				// Start offset: 0x80088E70
				// Variables:
			// 		long level; // $s0
			// 		long found; // $a0
			/* end block 1.1.1 */
			// End offset: 0x80088EF8
			// End Line: 3242
		/* end block 1.1 */
		// End offset: 0x80088EF8
		// End Line: 3243
	/* end block 1 */
	// End offset: 0x80088F68
	// End Line: 3260

	/* begin block 2 */
		// Start line: 7993
	/* end block 2 */
	// End Line: 7994

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Invent_SetAllVisible(_PLAYER *pl)

{
  bool bVar1;
  bool bVar2;
  short sVar3;
  long level;
  long lVar4;
  int spell;
  int iVar5;
  long *plVar6;
  uint uVar7;
  _TAKEN_OBJECT *obj;
  
  obj = Pvl_TakenObjects;
  uVar7 = 1;
  spell = 0;
  plVar6 = &Pvl_TakenObjects[1].obj.color;
  do {
    if ((*(ushort *)((int)plVar6 + 6) & 8) != 0) {
      *plVar6 = 0x5678;
      if (*(char *)(plVar6 + 1) == '\x14') {
        *(undefined2 *)(plVar6 + -1) = *(undefined2 *)((int)plVar6 + 10);
      }
      sVar3 = Invent_ObjectIsStored(pl,(_D3_OBJECT *)obj);
      if (sVar3 == 0) {
        *(ushort *)((int)plVar6 + 6) = *(ushort *)((int)plVar6 + 6) & 0xfff7;
        (pl->env2).Obj.primitive_top.Data
        [(int)*(short *)((pl->env2).Obj.primitive_top.Data + 0x22) + 0x24] = (byte)spell;
        *(short *)((pl->env2).Obj.primitive_top.Data + 0x22) =
             *(short *)((pl->env2).Obj.primitive_top.Data + 0x22) + 1;
      }
      *plVar6 = 0;
    }
    if (((spell < 0x12) && (spell != 4)) && (lVar4 = 0, spell != 7)) {
      bVar1 = (uVar7 & (pl->env2).Obj.n_vert) != 0;
      if (bVar1) {
        lVar4 = Pl_GetSpellLevel(pl,spell,(long *)0x0);
      }
      bVar2 = (uVar7 & Inventaire.spells_invisible) != 0;
      if (bVar2) {
        level = Pl_GetSpellLevel(pl,spell,Inventaire.spells_levels);
        lVar4 = lVar4 + level;
      }
      level = 3;
      if (lVar4 < 4) {
        level = lVar4;
      }
      if (bVar2 || bVar1) {
        Pl_SetSpellLevel(pl,spell,level,(long *)0x0);
      }
    }
    spell = spell + 1;
    plVar6 = plVar6 + 0x2c;
    obj = (_TAKEN_OBJECT *)&obj[1].obj.last_pos.vz;
    uVar7 = uVar7 << 1;
  } while (spell < 0x20);
  Inventaire.spells_invisible = 0;
  iVar5 = 1;
  spell = -0x7ff4c64c;
  do {
    *(undefined4 *)(spell + 0xc) = 0;
    iVar5 = iVar5 + -1;
    spell = spell + -4;
  } while (-1 < iVar5);
  Invent_SortPlayerIndices();
  Invent_Update(pl);
  while (0x10 < _DAT_800b1e4a) {
    Invent_AutomaticDrop(pl);
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Invent_AddSpell(struct _PLAYER *pl /*$s3*/, struct _TAKEN_OBJECT *to /*$a0*/)
 // line 3296, offset 0x80088f8c
	/* begin block 1 */
		// Start line: 3297
		// Start offset: 0x80088F8C
		// Variables:
	// 		struct _INVENT_LIST *l; // $v0
	// 		struct INVENTRY_130fake *sp; // $s0
	// 		long i; // $v1
	// 		long index; // $s2
	// 		long level; // $s0
	// 		long cost; // $s1
	// 		long mana; // $s4
	// 		long element; // $a0
	/* end block 1 */
	// End offset: 0x8008906C
	// End Line: 3337

	/* begin block 2 */
		// Start line: 8251
	/* end block 2 */
	// End Line: 8252

long Invent_AddSpell(_PLAYER *pl,_TAKEN_OBJECT *to)

{
  short sVar1;
  ushort uVar2;
  short sVar3;
  long lVar4;
  int spell;
  P_SPELL_130fake *pPVar5;
  int level;
  int iVar6;
  
  pPVar5 = &PSpells;
  sVar1 = *(short *)((int)&to[1].obj.description + 2);
  uVar2 = *(ushort *)((pl->env2).Obj.primitive_top.Data + 0x14);
  sVar3 = Invent_GetElemNumber(to);
  spell = 0;
  do {
    if ((uint)(byte)pPVar5->element == (int)sVar3) break;
    spell = spell + 1;
    pPVar5 = pPVar5 + 1;
  } while (spell < 0x12);
  spell = (int)sVar1 + spell;
  iVar6 = (int)(&PSpells)[spell].mini;
  lVar4 = Pl_GetSpellLevel(pl,spell,(long *)0x0);
  level = lVar4 + 1;
  lVar4 = -0x4000;
  if (level < 4) {
    if (0 < level) {
      iVar6 = iVar6 + iVar6 * level;
    }
    lVar4 = -iVar6;
    if (iVar6 <= (int)(uint)uVar2) {
      Pl_SetSpellLevel(pl,spell,level,(long *)0x0);
      Inventaire.inv_list[1].pad = (char)spell;
      lVar4 = level;
    }
  }
  return lVar4;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_BuildSpellList(struct _PLAYER *pl /*$a0*/)
 // line 3340, offset 0x8008908c
	/* begin block 1 */
		// Start line: 3342
		// Start offset: 0x8008908C
		// Variables:
	// 		struct _INVENT_LIST *l; // $a2
	// 		long i; // $a1
	// 		long value; // $a3
	/* end block 1 */
	// End offset: 0x80089110
	// End Line: 3356

	/* begin block 2 */
		// Start line: 8344
	/* end block 2 */
	// End Line: 8345

void Invent_BuildSpellList(_PLAYER *pl)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 1;
  Inventaire.inv_list[1].nb_obj = '\0';
  iVar1 = 0;
  do {
    if (((pl->env2).Obj.n_vert & uVar2) != 0) {
      Inventaire.inv_list[1].list[(uint)(byte)Inventaire.inv_list[1].nb_obj].index = (short)iVar1;
      Inventaire.inv_list[1].list[(uint)(byte)Inventaire.inv_list[1].nb_obj].num = '\x01';
      Inventaire.inv_list[1].nb_obj = Inventaire.inv_list[1].nb_obj + '\x01';
    }
    iVar1 = iVar1 + 1;
    uVar2 = uVar2 << 1;
  } while (iVar1 < 0x20);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_SpellDisplay()
 // line 3359, offset 0x80089118
	/* begin block 1 */
		// Start line: 3360
		// Start offset: 0x80089118
		// Variables:
	// 		struct _INVENT_LIST *l; // $fp
	// 		struct INVENTRY_7fake Eye; // stack offset -256
	// 		struct INVENTRY_7fake Visee; // stack offset -248
	// 		struct INVENTRY_93fake *tmd; // stack offset -60
	// 		struct INVENTRY_5fake mr; // stack offset -240
	// 		struct INVENTRY_5fake ml; // stack offset -208
	// 		struct INVENTRY_5fake ms; // stack offset -176
	// 		struct INVENTRY_70fake shp; // stack offset -144
	// 		char str[50]; // stack offset -128
	// 		long i; // $s2
	// 		long borne; // stack offset -56
	// 		struct INVENTRY_31fake *pft4; // $s4
	// 		void *otl; // $s7

		/* begin block 1.1 */
			// Start line: 3387
			// Start offset: 0x8008920C
		/* end block 1.1 */
		// End offset: 0x8008923C
		// End Line: 3390

		/* begin block 1.2 */
			// Start line: 3405
			// Start offset: 0x800892B0
			// Variables:
		// 		struct _INV_OBJECT *invo; // $s0
		// 		struct INVENTRY_7fake Rot; // stack offset -72
		// 		unsigned char col; // $s3
		// 		long color; // $s6
		// 		short w; // stack offset -64
		// 		short h; // stack offset -62
		/* end block 1.2 */
		// End offset: 0x80089398
		// End Line: 3439
	/* end block 1 */
	// End offset: 0x800895CC
	// End Line: 3481

	/* begin block 2 */
		// Start line: 8387
	/* end block 2 */
	// End Line: 8388

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Invent_SpellDisplay(void)

{
  short spell;
  void *pvVar1;
  _TMD_2D *p_Var2;
  _SCREEN *p_Var3;
  undefined4 in_zero;
  undefined4 uVar4;
  long lVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  _INV_OBJECT *p_Var9;
  undefined4 *puVar10;
  uchar col;
  SHAPE_31fake *prim;
  ushort auStack240 [10];
  int local_dc;
  int local_d8;
  int local_d4;
  SHAPE_68fake local_90;
  char acStack128 [56];
  undefined4 uStack72;
  short local_44;
  short local_40;
  short local_3e;
  int local_3c;
  uint local_38;
  SHAPE_68fake *local_34;
  undefined4 *local_30;
  
  iVar6 = (int)Scr_Frame;
  prim = (SHAPE_31fake *)(&Tab_Spells + iVar6 * 200);
  local_3c = (int)PTR_800b2df8 + 0xc;
  Invent_DisplayButtons();
  Text_SetText((char *)Pvl_UtilityTexts[1],Inventaire.helpx,0x73);
  pvVar1 = Main_Prims;
  if ((Inventaire.inv_list[1].nb_obj == '\0') && (Cpt_Alert == 0)) {
    sprintf(acStack128,(char *)&PTR_DAT_800ad9ec,Pvl_UtilityTexts[2]);
    Invent_Alert(acStack128,1);
  }
  else {
    Main_Prims = (void *)((int)Main_Prims + 0x400);
    uVar4 = 0x800b0000;
    ClearOTagR((undefined4 *)pvVar1);
    uVar7 = (uint)(byte)Inventaire.inv_list[1].deb_list;
    local_90.file = Pl_Pcl;
    local_38 = (uint)(byte)Inventaire.inv_list[1].nb_obj;
    if (uVar7 + 5 < (uint)(byte)Inventaire.inv_list[1].nb_obj) {
      local_38 = uVar7 + 5;
    }
    local_34 = &local_90;
    if (uVar7 < local_38) {
      local_30 = &uStack72;
      puVar10 = (undefined4 *)(&DAT_800b3200 + iVar6 * 200);
      do {
        p_Var9 = Inventaire.inv_list[1].list + uVar7;
        memset(&uStack72,0,8);
        local_90.shape = (&PSpells)[(int)p_Var9->index].icon;
        Shp_GetWH(local_34,&local_40,&local_3e);
        Shp_SetPolyFT4(prim,local_34,local_40,local_3e);
        *(byte *)((int)puVar10 + -0x19) = *(byte *)((int)puVar10 + -0x19) & 0xfe;
        col = '@';
        if (uVar7 == (uint)(byte)Inventaire.inv_list[1].hilite) {
          col = -0x40;
          if (Inventaire.inv_list[1].list[uVar7].angle < 0) {
            Inventaire.inv_list[1].list[uVar7].angle = 0x1000;
          }
          spell = p_Var9->index;
          Inventaire.inv_list[1].list[uVar7].angle =
               Inventaire.inv_list[1].list[uVar7].angle + -0x20;
          lVar5 = Invent_GetSpellColor(spell,1);
          Invent_DisplaySpellName((short)uVar7,p_Var9->index);
        }
        else {
          spell = p_Var9->index;
          Inventaire.inv_list[1].list[uVar7].angle = 0x500;
          lVar5 = Invent_GetSpellColor(spell,0);
        }
        *(uchar *)(puVar10 + -7) = col;
        *(uchar *)((int)puVar10 + -0x1b) = col;
        *(uchar *)((int)puVar10 + -0x1a) = col;
        Cam_SetMatrix(0,8);
        SetGeomOffset((int)Inventaire.posx +
                      (uVar7 - (uint)(byte)Inventaire.inv_list[1].deb_list) * 0x35 + 0x19,
                      (int)Inventaire.posy + -10);
        setCopReg(2,in_zero,*local_30);
        setCopReg(2,uVar4,local_30[1]);
        copFunction(2,0x486012);
        local_dc = getCopReg(2,0x19);
        local_d8 = getCopReg(2,0x1a);
        local_d4 = getCopReg(2,0x1b);
        local_dc = local_dc + Cam_Matrix.t[0];
        local_d8 = local_d8 + Cam_Matrix.t[1];
        local_d4 = local_d4 + Cam_Matrix.t[2];
        setCopControlWord(2,0x2800,local_dc);
        setCopControlWord(2,0x3000,local_d8);
        setCopControlWord(2,0x3800,local_d4);
        local_44 = Inventaire.inv_list[1].list[uVar7].angle;
        RotMatrix((short *)local_30,auStack240);
        SetMulMatrix((undefined4 *)&Cam_Matrix,auStack240);
        Invent_SetLightMatrices((char)auStack240);
        GtxTmd_RotTransPersN(&pan_princ,Tmd_2D,4);
        p_Var2 = Tmd_2D;
        puVar10[-6] = *(undefined4 *)Tmd_2D;
        puVar10[-4] = *(undefined4 *)(p_Var2 + 1);
        puVar10[-2] = *(undefined4 *)(p_Var2 + 2);
        *puVar10 = *(undefined4 *)(p_Var2 + 3);
        puVar10 = puVar10 + 10;
        Main_Prims = (void *)GtxTmd_DisplayLON(local_3c,Main_Prims,pvVar1,0x100,0,lVar5);
        p_Var3 = Scr;
        uVar4 = 0x800b0000;
        prim->tag = prim->tag & 0xff000000 | *Scr->ot & 0xffffff;
        uVar8 = (uint)prim & 0xffffff;
        prim = prim + 1;
        *p_Var3->ot = *p_Var3->ot & 0xff000000 | uVar8;
        Invent_DisplaySpellLevels
                  (uVar7 - (uint)(byte)Inventaire.inv_list[1].deb_list,(int)p_Var9->index,col);
        uVar7 = uVar7 + 1;
      } while ((int)uVar7 < (int)local_38);
    }
    p_Var3 = Scr;
    *(uint *)pvVar1 = *(uint *)pvVar1 & 0xff000000 | *Scr->ot & 0xffffff;
    *p_Var3->ot = *p_Var3->ot & 0xff000000 | (int)pvVar1 + 0x3fcU & 0xffffff;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_DisplaySpellLevels(long numspell /*$a0*/, long index /*$a1*/, unsigned char col /*$s5*/)
 // line 3484, offset 0x800895fc
	/* begin block 1 */
		// Start line: 3485
		// Start offset: 0x800895FC
		// Variables:
	// 		struct INVENTRY_70fake shp; // stack offset -88
	// 		struct INVENTRY_31fake *pft4; // $s1
	// 		long i; // $s4
	// 		long j; // $t0
	// 		long level; // $s6
	// 		struct INVENTRY_7fake vert[4]; // stack offset -72

		/* begin block 1.1 */
			// Start line: 3513
			// Start offset: 0x80089710
		/* end block 1.1 */
		// End offset: 0x80089710
		// End Line: 3513
	/* end block 1 */
	// End offset: 0x80089840
	// End Line: 3531

	/* begin block 2 */
		// Start line: 8923
	/* end block 2 */
	// End Line: 8924

void Invent_DisplaySpellLevels(long numspell,long index,uchar col)

{
  short sVar1;
  short sVar2;
  _TMD_2D *p_Var3;
  _SCREEN *p_Var4;
  long lVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  SHAPE_31fake *prim;
  short *psVar11;
  int iVar12;
  int iVar13;
  SHAPE_68fake local_58;
  undefined4 local_48 [8];
  
  iVar13 = 0;
  prim = (SHAPE_31fake *)(&Tab_SpellLevels + (int)Scr_Frame * 800 + numspell * 0xa0);
  lVar5 = Pl_GetSpellLevel((_PLAYER *)&Player,index,(long *)0x0);
  local_58.shape = 3;
  local_58.x = 0;
  local_58.y = 0;
  local_58.file = Pl_Pcl;
  if (-1 < lVar5) {
    puVar10 = (undefined4 *)&prim->x3;
    iVar12 = 2;
    psVar11 = &Spell_UpPos;
    do {
      Shp_SetPolyFT4(prim,&local_58,10,10);
      *(uchar *)(puVar10 + -7) = col;
      *(uchar *)((int)puVar10 + -0x1b) = col;
      *(uchar *)((int)puVar10 + -0x1a) = col;
      *(char *)(puVar10 + -3) = *(char *)(puVar10 + -3) + '\x01';
      *(char *)((int)puVar10 + -3) = *(char *)((int)puVar10 + -3) + '\x01';
      *(char *)(puVar10 + 1) = *(char *)(puVar10 + 1) + '\x01';
      *(byte *)((int)puVar10 + -0x19) = *(byte *)((int)puVar10 + -0x19) & 0xfe;
      *(char *)((int)puVar10 + 5) = *(char *)((int)puVar10 + 5) + '\x01';
      iVar7 = 0;
      do {
        iVar8 = iVar7 + 1;
        puVar6 = local_48 + iVar7 * 2;
        sVar1 = *psVar11;
        sVar2 = *(short *)((int)&Spell_UpPos + iVar12);
        uVar9 = (&DAT_800ada68)[iVar7 * 2];
        *(undefined **)puVar6 = (&pan_level)[iVar7 * 2];
        local_48[iVar7 * 2 + 1] = uVar9;
        *(short *)puVar6 = *(short *)puVar6 + sVar1 * 0x32;
        *(short *)(local_48 + iVar7 * 2 + 1) = *(short *)(local_48 + iVar7 * 2 + 1) + sVar2 * 0x32;
        iVar7 = iVar8;
      } while (iVar8 < 4);
      GtxTmd_RotTransPersN(local_48,Tmd_2D,4);
      p_Var3 = Tmd_2D;
      iVar12 = iVar12 + 4;
      psVar11 = psVar11 + 2;
      iVar13 = iVar13 + 1;
      puVar10[-6] = *(undefined4 *)Tmd_2D;
      puVar10[-4] = *(undefined4 *)(p_Var3 + 1);
      puVar10[-2] = *(undefined4 *)(p_Var3 + 2);
      *puVar10 = *(undefined4 *)(p_Var3 + 3);
      p_Var4 = Scr;
      puVar10 = puVar10 + 10;
      prim->tag = prim->tag & 0xff000000 | *Scr->ot & 0xffffff;
      *p_Var4->ot = *p_Var4->ot & 0xff000000 | (uint)prim & 0xffffff;
      prim = prim + 1;
    } while (iVar13 <= lVar5);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_DisplaySpellName(short index /*$a0*/, short spell /*$a1*/)
 // line 3534, offset 0x8008986c
	/* begin block 1 */
		// Start line: 3535
		// Start offset: 0x8008986C
		// Variables:
	// 		struct _INVENT_LIST *l; // $a2
	/* end block 1 */
	// End offset: 0x8008986C
	// End Line: 3535

	/* begin block 2 */
		// Start line: 9243
	/* end block 2 */
	// End Line: 9244

void Invent_DisplaySpellName(short index,short spell)

{
  Text_SetContextXY((short)(((uint)(ushort)Inventaire.posx +
                             ((int)index - (uint)(byte)Inventaire.inv_list[1].deb_list) * 0x35 +
                            0x14) * 0x10000 >> 0x10),0);
  Text_SetContextWH(10,Scr_H);
  Text_SetText((char *)Pvl_UtilityTexts
                       [(uint)(byte)(&PSpells.text)[(int)((uint)(ushort)spell << 0x10) >> 0xc]],
               -0x7ffe,(short)(((uint)(ushort)Inventaire.posy - 0x21) * 0x10000 >> 0x10));
  Text_SetContextXY(0,0);
  Text_SetContextWH(Scr_W,Scr_H);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Invent_GetSpellColor(short spell /*$a0*/, long hilite /*$a1*/)
 // line 3549, offset 0x80089950
	/* begin block 1 */
		// Start line: 3551
		// Start offset: 0x80089950
		// Variables:
	// 		long color; // $a2
	/* end block 1 */
	// End offset: 0x80089A00
	// End Line: 3573

	/* begin block 2 */
		// Start line: 9281
	/* end block 2 */
	// End Line: 9282

long Invent_GetSpellColor(short spell,long hilite)

{
  byte bVar1;
  undefined *in_a2;
  
  bVar1 = (&PSpells.element)[(int)((uint)(ushort)spell << 0x10) >> 0xc];
  if (bVar1 == 1) {
    in_a2 = &DAT_00404080;
    if (hilite != 0) {
      in_a2 = (undefined *)0x8080c0;
    }
  }
  else {
    if (bVar1 < 2) {
      if ((bVar1 == 0) && (in_a2 = (undefined *)0x804040, hilite != 0)) {
        in_a2 = (undefined *)0xc08080;
      }
    }
    else {
      if (bVar1 == 2) {
        in_a2 = &DAT_00404040;
        if (hilite != 0) {
          in_a2 = (undefined *)0xc0c0c0;
        }
      }
      else {
        if ((bVar1 == 3) && (in_a2 = &DAT_00408040, hilite != 0)) {
          in_a2 = (undefined *)0x80c080;
        }
      }
    }
  }
  return (long)in_a2;
}



// decompiled code
// original method signature: 
// short /*$ra*/ Invent_UseSpell(struct _PLAYER *pl /*$t3*/, short index /*$t4*/)
 // line 3577, offset 0x80089a0c
	/* begin block 1 */
		// Start line: 3578
		// Start offset: 0x80089A0C
		// Variables:
	// 		long i; // $a2
	// 		struct _INVENT_LIST *l; // $a0
	// 		struct _INV_OBJECT *invo; // $t0

		/* begin block 1.1 */
			// Start line: 3589
			// Start offset: 0x80089A60
			// Variables:
		// 		char spellindex; // $a3
		/* end block 1.1 */
		// End offset: 0x80089AA0
		// End Line: 3600
	/* end block 1 */
	// End offset: 0x80089AD0
	// End Line: 3605

	/* begin block 2 */
		// Start line: 9334
	/* end block 2 */
	// End Line: 9335

short Invent_UseSpell(_PLAYER *pl,short index)

{
  short sVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  _PLAYER *p_Var5;
  int iVar6;
  _INV_OBJECT *p_Var7;
  
  p_Var7 = Inventaire.inv_list[1].list + (uint)(byte)Inventaire.inv_list[1].hilite;
  if (Inventaire.inv_list[1].nb_obj == '\0') {
    sVar1 = 0;
  }
  else {
    iVar6 = 0;
    p_Var5 = pl;
    do {
      uVar2 = (uint)*(byte *)&(p_Var5->env2).Obj.n_normal;
      uVar4 = uVar2 & 0xbf;
      bVar3 = (byte)uVar4;
      *(byte *)&(p_Var5->env2).Obj.n_normal = bVar3;
      if ((uVar4 != 0x80) && ((uVar2 & 0x3f) == (int)p_Var7->index)) {
        if (iVar6 == (int)index) {
          *(byte *)&(p_Var5->env2).Obj.n_normal = bVar3 | 0x40;
        }
        else {
          *(undefined *)&(p_Var5->env2).Obj.n_normal = 0x80;
        }
      }
      iVar6 = iVar6 + 1;
      p_Var5 = (_PLAYER *)((int)&(pl->obj).next + iVar6);
    } while (iVar6 < 4);
    *(char *)((int)&(pl->env2).Obj.n_normal + (int)index) = *(char *)&p_Var7->index + '@';
    Overlay_SetSpellsPrims();
    sVar1 = 1;
  }
  return sVar1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Invent_SpellGetPos(struct _PLAYER *pl /*$a0*/, long index /*$a1*/)
 // line 3608, offset 0x80089ae0
	/* begin block 1 */
		// Start line: 3610
		// Start offset: 0x80089AE0
		// Variables:
	// 		long i; // $v1

		/* begin block 1.1 */
			// Start line: 3615
			// Start offset: 0x80089AE8
			// Variables:
		// 		char sel; // $v0
		/* end block 1.1 */
		// End offset: 0x80089B04
		// End Line: 3619
	/* end block 1 */
	// End offset: 0x80089B14
	// End Line: 3622

	/* begin block 2 */
		// Start line: 9416
	/* end block 2 */
	// End Line: 9417

long Invent_SpellGetPos(_PLAYER *pl,long index)

{
  byte bVar1;
  _PLAYER *p_Var2;
  int iVar3;
  
  iVar3 = 0;
  p_Var2 = pl;
  while ((bVar1 = *(byte *)&(p_Var2->env2).Obj.n_normal, bVar1 == 0x80 ||
         (((uint)bVar1 & 0x3f) != index))) {
    iVar3 = iVar3 + 1;
    p_Var2 = (_PLAYER *)((int)&(pl->obj).next + iVar3);
    if (3 < iVar3) {
      return -1;
    }
  }
  return iVar3;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_SpellGoToButton(struct _PLAYER *pl /*$s0*/, long index /*$s1*/)
 // line 3625, offset 0x80089b24
	/* begin block 1 */
		// Start line: 3626
		// Start offset: 0x80089B24
		// Variables:
	// 		struct TASK *handle; // $v0
	/* end block 1 */
	// End offset: 0x80089B70
	// End Line: 3638

	/* begin block 2 */
		// Start line: 9454
	/* end block 2 */
	// End Line: 9455

void Invent_SpellGoToButton(_PLAYER *pl,long index)

{
  TASK *pTVar1;
  
  if ((SPELL_MOVING == 0) && (Inventaire.inv_list[1].nb_obj != '\0')) {
    SPELL_MOVING = 1;
    pTVar1 = Task_Add(Invent_SpellGoToButtonTask,0x800);
    *(_PLAYER **)&pTVar1->s0 = pl;
    pTVar1->s1 = index;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_SpellGoToButtonTask()
 // line 3640, offset 0x80089b84
	/* begin block 1 */
		// Start line: 3641
		// Start offset: 0x80089B84
		// Variables:
	// 		struct _PLAYER *pl; // stack offset -60
	// 		long index; // stack offset -56
	// 		long i; // $s3
	// 		long j; // $s2
	// 		short w; // stack offset -64
	// 		short h; // stack offset -62
	// 		char nbf; // stack offset -48
	// 		struct INVENTRY_70fake shp; // stack offset -808
	// 		struct INVENTRY_31fake *pft4; // $s0
	// 		struct INVENTRY_31fake prims[2][8]; // stack offset -792
	// 		struct _INVENT_LIST *l; // $s1
	// 		struct _INV_OBJECT *invo; // $s0
	// 		struct INVENTRY_9fake BegPos; // stack offset -152
	// 		struct INVENTRY_9fake EndPos; // stack offset -144
	// 		struct INVENTRY_9fake StepPos; // stack offset -136
	// 		struct INVENTRY_7fake TabTray[8]; // stack offset -128

		/* begin block 1.1 */
			// Start line: 3698
			// Start offset: 0x80089E74
			// Variables:
		// 		long cpt; // $a1

			/* begin block 1.1.1 */
				// Start line: 3716
				// Start offset: 0x80089F54
				// Variables:
			// 		char c; // $s1
			// 		short s; // $a2
			/* end block 1.1.1 */
			// End offset: 0x80089F98
			// End Line: 3727
		/* end block 1.1 */
		// End offset: 0x8008A074
		// End Line: 3737
	/* end block 1 */
	// End offset: 0x8008A0A8
	// End Line: 3743

	/* begin block 2 */
		// Start line: 9486
	/* end block 2 */
	// End Line: 9487

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Invent_SpellGoToButtonTask(void)

{
  uchar uVar1;
  void *pvVar2;
  _SCREEN *p_Var3;
  byte bVar4;
  long lVar5;
  undefined2 *puVar6;
  ushort *puVar7;
  int iVar8;
  int iVar9;
  _INV_OBJECT *p_Var10;
  uint uVar11;
  SHAPE_31fake *prim;
  int iVar12;
  int iVar13;
  SHAPE_68fake local_328;
  ulong auStack792 [160];
  short local_98;
  short local_96;
  undefined2 local_90;
  undefined2 local_8e;
  short local_88;
  short local_86;
  ushort local_80 [28];
  undefined2 local_48 [4];
  ushort local_40;
  ushort local_3e;
  _PLAYER *local_3c;
  long local_38;
  byte local_30;
  
  iVar12 = 7;
  puVar6 = local_48;
  local_3c = (_PLAYER *)TaskCurrent->s0;
  local_38 = TaskCurrent->s1;
  p_Var10 = Inventaire.inv_list[1].list + (uint)(byte)Inventaire.inv_list[1].hilite;
  do {
    *puVar6 = 0xffff;
    iVar12 = iVar12 + -1;
    puVar6 = puVar6 + -4;
  } while (-1 < iVar12);
  local_328.file = Pl_Pcl;
  local_328.shape = (&PSpells)[(int)p_Var10->index].icon;
  Shp_GetWH(&local_328,(short *)&local_40,(short *)&local_3e);
  lVar5 = Invent_SpellGetPos(local_3c,(int)p_Var10->index);
  if (lVar5 == -1) {
    local_30 = 0x14;
    local_96 = Inventaire.posy + -10;
    local_98 = Inventaire.posx +
               ((ushort)(byte)Inventaire.inv_list[1].hilite -
               (ushort)(byte)Inventaire.inv_list[1].deb_list) * 0x35 + 0x19;
  }
  else {
    if (lVar5 == local_38) {
      SPELL_MOVING = 0;
      Invent_UseSpell(local_3c,(short)local_38);
      Fx_Play(0x42,100);
      return;
    }
    local_30 = 10;
    local_98 = TabPos[lVar5 * 2] +
               (short)((int)(((int)((uint)local_40 << 0x10) >> 0x10) +
                            (((uint)local_40 << 0x10) >> 0x1f)) >> 1) + 0x14;
    local_96 = *(short *)((int)TabPos + (lVar5 << 2 | 2U)) +
               (short)((int)(((int)((uint)local_3e << 0x10) >> 0x10) +
                            (((uint)local_3e << 0x10) >> 0x1f)) >> 1) + 0x14;
  }
  bVar4 = local_30;
  uVar11 = (uint)local_30;
  iVar12 = (uint)(ushort)TabPos[local_38 * 2] +
           ((int)(((int)((uint)local_40 << 0x10) >> 0x10) + (((uint)local_40 << 0x10) >> 0x1f)) >> 1
           ) + 0x14;
  iVar8 = (iVar12 * 0x10000 >> 0xc) + (int)local_98 * -0x10;
  if (local_30 == 0) {
    trap(0x1c00);
  }
  if ((uVar11 == 0xffffffff) && (iVar8 == -0x80000000)) {
    trap(0x1800);
  }
  local_90 = (undefined2)iVar12;
  iVar9 = (uint)*(ushort *)((int)TabPos + (local_38 << 2 | 2U)) +
          ((int)(((int)((uint)local_3e << 0x10) >> 0x10) + (((uint)local_3e << 0x10) >> 0x1f)) >> 1)
          + 0x14;
  iVar12 = (iVar9 * 0x10000 >> 0xc) + (int)local_96 * -0x10;
  if (local_30 == 0) {
    trap(0x1c00);
  }
  if ((uVar11 == 0xffffffff) && (iVar12 == -0x80000000)) {
    trap(0x1800);
  }
  iVar13 = 0;
  local_8e = (undefined2)iVar9;
  local_88 = (short)(iVar8 / (int)uVar11);
  local_86 = (short)(iVar12 / (int)uVar11);
  Fx_Play(0x3b,100);
  if (bVar4 != 0) {
    do {
      iVar12 = iVar13;
      if (iVar13 < 0) {
        iVar12 = iVar13 + 7;
      }
      iVar12 = iVar13 + (iVar12 >> 3) * -8;
      iVar8 = 0;
      puVar7 = local_80;
      do {
        iVar8 = iVar8 + 1;
        puVar7[2] = puVar7[2] - 0x1e;
        puVar7[3] = puVar7[3] - 1;
        puVar7 = puVar7 + 4;
      } while (iVar8 < 8);
      local_80[iVar12 * 4] =
           (local_98 + (short)(iVar13 * (int)local_88 >> 4)) -
           (short)((int)(((int)((uint)local_40 << 0x10) >> 0x10) +
                        (((uint)local_40 << 0x10) >> 0x1f)) >> 1);
      iVar8 = 0;
      local_80[iVar12 * 4 + 2] = 0xf0;
      local_80[iVar12 * 4 + 3] = local_40;
      iVar9 = 0;
      local_80[iVar12 * 4 + 1] =
           (local_96 + (short)(iVar13 * (int)local_86 >> 4)) -
           (short)((int)(((int)((uint)local_3e << 0x10) >> 0x10) +
                        (((uint)local_3e << 0x10) >> 0x1f)) >> 1);
      do {
        local_328.x = local_80[iVar8 * 4];
        uVar1 = *(uchar *)(local_80 + iVar8 * 4 + 2);
        local_328.y = local_80[iVar8 * 4 + 1];
        prim = (SHAPE_31fake *)((int)&auStack792[(int)Scr_Frame * 8].tag + iVar9);
        if ((int)((uint)local_328.x << 0x10) < 0) break;
        Shp_SetPolyFT4(prim,&local_328,local_80[iVar8 * 4 + 3],local_80[iVar8 * 4 + 3]);
        prim->r0 = uVar1;
        prim->g0 = uVar1;
        prim->b0 = uVar1;
        pvVar2 = Pl_Pcl;
        iVar12 = *(int *)((int)Pl_Pcl + (int)local_328.shape * 4 + 0x10);
        *(ushort *)(iVar12 + 2) = *(ushort *)(iVar12 + 2) & 0xff9f;
        iVar12 = *(int *)((int)pvVar2 + (int)local_328.shape * 4 + 0x10);
        *(ushort *)(iVar12 + 2) = *(ushort *)(iVar12 + 2) | 0x20;
        prim->code = prim->code & 0xfe | 2;
        p_Var3 = Scr;
        prim->tag = prim->tag & 0xff000000 | *Scr->ot & 0xffffff;
        iVar8 = iVar8 + 1;
        *p_Var3->ot = *p_Var3->ot & 0xff000000 | (uint)prim & 0xffffff;
        iVar9 = iVar9 + 0x28;
      } while (iVar8 < 8);
      iVar13 = iVar13 + 1;
      Task_Next();
    } while (iVar13 < (int)(uint)local_30);
  }
  Invent_UseSpell(local_3c,(short)local_38);
  SPELL_MOVING = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_FlyObject(struct _TAKEN_OBJECT *to /*$s0*/, long multi /*$s1*/)
 // line 3746, offset 0x8008a0d8
	/* begin block 1 */
		// Start line: 3747
		// Start offset: 0x8008A0D8
		// Variables:
	// 		struct TASK *handle; // $v0
	/* end block 1 */
	// End offset: 0x8008A0D8
	// End Line: 3747

	/* begin block 2 */
		// Start line: 9904
	/* end block 2 */
	// End Line: 9905

void Invent_FlyObject(_TAKEN_OBJECT *to,long multi)

{
  TASK *pTVar1;
  
  pTVar1 = Task_Add(Invent_FlyObjectTask,0);
  *(_TAKEN_OBJECT **)&pTVar1->local = to;
  pTVar1->s0 = multi;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Invent_FlyObjectTask()
 // line 3755, offset 0x8008a11c
	/* begin block 1 */
		// Start line: 3756
		// Start offset: 0x8008A11C
		// Variables:
	// 		struct _TAKEN_OBJECT *to; // $s3
	// 		long multi_mode; // $s7
	// 		struct _D3_OBJECT *o; // $s1
	// 		struct INVENTRY_5fake Save_Matrix; // stack offset -80
	// 		long i; // $s2
	// 		long cpt; // $s4
	// 		long offset; // $s6
	// 		short old_multi; // stack offset -48
	// 		void *otl; // $s0
	/* end block 1 */
	// End offset: 0x8008A41C
	// End Line: 3831

	/* begin block 2 */
		// Start line: 9925
	/* end block 2 */
	// End Line: 9926

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Invent_FlyObjectTask(void)

{
  void *otl;
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  _SCREEN *p_Var9;
  short sVar10;
  uint uVar11;
  ushort uVar12;
  uint uVar13;
  int iVar14;
  _TAKEN_OBJECT *to;
  uint uVar15;
  int iVar16;
  uint uVar17;
  
  iVar14 = 0x3c;
  uVar15 = 0x28;
  iVar16 = 0;
  to = (_TAKEN_OBJECT *)TaskCurrent->local;
  uVar17 = TaskCurrent->s0;
  Task_Next();
  Invent_SetBoxCenter((_D3_OBJECT *)to);
  uVar12 = to[1].obj.pos.pad & ~(ushort)(1 << (uVar17 & 0x1f));
  to[1].obj.pos.pad = uVar12;
  do {
    (to->obj).rot.vz = (to->obj).rot.vz + 100;
    lVar8 = Cam_Matrix.t[2];
    lVar7 = Cam_Matrix.t[1];
    lVar6 = Cam_Matrix.t[0];
    uVar5 = Cam_Matrix._16_4_;
    uVar4 = Cam_Matrix.m[2]._0_4_;
    uVar3 = Cam_Matrix.m[1]._2_4_;
    uVar2 = Cam_Matrix.m._4_4_;
    uVar1 = Cam_Matrix.m[0]._0_4_;
    if (iVar14 < 0x1e) {
      iVar16 = iVar16 + 10;
      sVar10 = (to->obj).pos.pad + 1;
LAB_8008a26c:
      iVar14 = iVar14 + -1;
      (to->obj).pos.pad = sVar10;
    }
    else {
      if ((((int)uVar17 < 0) || (iVar14 != 0x1e)) || (uVar15 == 0)) {
        sVar10 = (to->obj).pos.pad + -1;
        goto LAB_8008a26c;
      }
      uVar15 = uVar15 - 1;
      to[1].obj.pos.pad = to[1].obj.pos.pad | (ushort)(1 << (uVar17 & 0x1f));
      if ((0x14 < (int)uVar15) && ((uVar15 & 1) != 0)) {
        to[1].obj.pos.pad = uVar12;
      }
    }
    SetGeomOffset(((int)(((int)((uint)(ushort)Scr_W << 0x10) >> 0x10) +
                        (((uint)(ushort)Scr_W << 0x10) >> 0x1f)) >> 1) + iVar16,
                  (int)(((int)((uint)(ushort)Scr_H << 0x10) >> 0x10) +
                       (((uint)(ushort)Scr_H << 0x10) >> 0x1f)) >> 1);
    Invent_SetCamera((_D3_OBJECT *)to,9);
    otl = Main_Prims;
    Main_Prims = (void *)((int)Main_Prims + 0x800);
    ClearOTagR((undefined4 *)otl);
    Main_Prims = Invent_DisplayTmd(to,otl,Main_Prims,1);
    p_Var9 = Scr;
    uVar11 = (uint)(ushort)Scr_W;
    uVar13 = (uint)(ushort)Scr_H;
    *(uint *)otl = *(uint *)otl & 0xff000000 | *Scr->ot & 0xffffff;
    *p_Var9->ot = *p_Var9->ot & 0xff000000 | (int)otl + 0x7fcU & 0xffffff;
    Cam_Matrix.m[0]._0_4_ = uVar1;
    Cam_Matrix.m._4_4_ = uVar2;
    Cam_Matrix.m[1]._2_4_ = uVar3;
    Cam_Matrix.m[2]._0_4_ = uVar4;
    Cam_Matrix._16_4_ = uVar5;
    Cam_Matrix.t[0] = lVar6;
    Cam_Matrix.t[1] = lVar7;
    Cam_Matrix.t[2] = lVar8;
    SetGeomOffset((int)(((int)(uVar11 << 0x10) >> 0x10) + ((uVar11 << 0x10) >> 0x1f)) >> 1,
                  (int)(((int)(uVar13 << 0x10) >> 0x10) + ((uVar13 << 0x10) >> 0x1f)) >> 1);
    setCopControlWord(2,0,Cam_Matrix.m[0]._0_4_);
    setCopControlWord(2,0x800,Cam_Matrix.m._4_4_);
    setCopControlWord(2,0x1000,Cam_Matrix.m[1]._2_4_);
    setCopControlWord(2,0x1800,Cam_Matrix.m[2]._0_4_);
    setCopControlWord(2,0x2000,Cam_Matrix._16_4_);
    setCopControlWord(2,0x2800,Cam_Matrix.t[0]);
    setCopControlWord(2,0x3000,Cam_Matrix.t[1]);
    setCopControlWord(2,0x3800,Cam_Matrix.t[2]);
    Task_Next();
    if (iVar14 == 0) {
      return;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// long /*$ra*/ Invent_ReloadAmmo(struct _PLAYER *pl /*$a0*/)
 // line 3834, offset 0x8008a44c
	/* begin block 1 */
		// Start line: 10178
	/* end block 1 */
	// End Line: 10179

long Invent_ReloadAmmo(_PLAYER *pl)

{
  byte bVar1;
  short sVar2;
  
  bVar1 = (pl->env1).Obj.primitive_top.Data[0x19];
  if (((char)bVar1 < '\x04') && (sVar2 = Invent_GetNbObjects(2,(short)(char)bVar1), sVar2 != 0)) {
    return 1;
  }
  return 0;
}





