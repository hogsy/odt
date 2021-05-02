#ifndef MENU_H
#define MENU_H


extern int Menu_BootupInitGfx(); // 0x800BC134

extern int Menu_BootupDrawGfx(); // 0x800BC234

extern long Menu_BootupTestCard(int slot); // 0x800BC340

extern long Menu_BootupWaitAnswer(); // 0x800BC458

extern long Menu_BootupCheck(); // 0x800BC540

extern long Menu_BootupRead(); // 0x800BC594

extern void Menu_TaskBootupMC(); // 0x800BC688

extern void Menu_TaskBootup(); // 0x800BC75C

extern long Menu_FirstBootup(); // 0x800BC87C

extern void Menu_Launch(struct _PARAMETRE *main_p); // 0x800BC9A0

extern void Menu_InitGeneral(); // 0x800BD044

extern void Menu_TranslateSpecChar(void *script); // 0x800BDC04

extern void Menu_InitScripteString(void *scripte); // 0x800BDDA0

extern void Menu_InitScripteParam(void *scripte); // 0x800BDE40

extern void Menu_NextLine(); // 0x800BDEE0

extern char * Menu_NextTxt(); // 0x800BDF34

extern int Menu_NextParam(); // 0x800BDF88

extern void Menu_ReadPage(); // 0x800BDFF0

extern void Menu_InitPageGeneral(); // 0x800BE3BC

extern void Menu_InitPageLoad(); // 0x800BE4CC

extern void Menu_InitPageSelect(); // 0x800BE528

extern void Menu_InitPageCenterScreen(); // 0x800BE66C

extern void Menu_ReadCmd(); // 0x800BE6F4

extern void Menu_CmdL(); // 0x800BE7D4

extern void Menu_CmdS(); // 0x800BE8AC

extern void Menu_CmdT(); // 0x800BE958

extern void Menu_CmdB(); // 0x800BE990

extern void Menu_CmdM(); // 0x800BEBA4

extern void Menu_PlayCd(); // 0x800BED04

extern void Menu_PageLoadPSX(); // 0x800BED3C

extern void Menu_PageLoadPC(); // 0x800BF290

extern void Menu_ChangeSector(int step); // 0x800BF298

extern void Menu_PageSelectPerso(); // 0x800BF398

extern void Menu_LegalTask(); // 0x800BF564

extern void Menu_Task(); // 0x800BF56C

extern void Menu_AddToStrList(char *s, short a, short y, short f, int n); // 0x800BFEB4

extern void Menu_MoveSelectGame(short p); // 0x800BFF34

extern short Menu_BuildStrList(short slot); // 0x800C0004

extern void Menu_TaskMemCard(); // 0x800C0158

extern void Menu_ToScreenStd(short Fr); // 0x800C03CC

extern void Menu_ToScreenTitle(); // 0x800C0AA8

extern void Menu_MireInit(); // 0x800C0B24

extern void Menu_Mire(); // 0x800C0DA4

extern void Menu_ScreenSetup(); // 0x800C1014

extern void Menu_ToScreenHelp(); // 0x800C1100

extern void Menu_RestoreCenterScreen(); // 0x800C13C0

extern void Menu_UpdateCenterScreen(); // 0x800C1414

extern void Menu_ExitCenterScreen(); // 0x800C1468

extern short Menu_ChkJoyCenterScreen(short fx_handle); // 0x800C14C4

extern void Menu_InitChangePage(struct _OPTION *Opt); // 0x800C167C

extern void Menu_ChkJoyCaseSPSX(); // 0x800C17F4

extern short Menu_ChkJoy(); // 0x800C1A0C

extern void Menu_MoveOpt(short p); // 0x800C1EA4

extern void Menu_SetParam(short p, short c); // 0x800C1FF0

extern short Menu_GetParam(short p); // 0x800C207C

extern void Menu_FctOpt(struct _OPTION *Opt); // 0x800C2128

extern void Menu_TaskSfx(); // 0x800C2654

extern void Menu_TaskSnd3D(); // 0x800C2724

extern struct _OPTION * Menu_FindOpt(short d); // 0x800C272C

extern void Menu_FX(); // 0x800C27B0

extern short Fade_Execute(struct _FADE *Fade); // 0x800C2824

extern void Fade_Init(struct _FADE *f, struct MENU_8fake c1, struct MENU_8fake c2, short p); // 0x800C31F4

extern short Fade_Calculate(struct _FADE *f); // 0x800C3258

extern void Fade_Set(struct _FADE *Fade, short f); // 0x800C338C

extern void Menu_TaskMotion(); // 0x800C339C

extern short Menu_GetMotionEvent(struct _PERSO *Perso); // 0x800C3F50

extern void Menu_MotionSound(struct _PERSO *Perso, long ID); // 0x800C3F78

extern void Menu_TaskCheat(); // 0x800C407C

extern void Menu_ToScreenPermanent(); // 0x800C423C

extern void Menu_ToScreenSelect(char Id, short Fr); // 0x800C476C

extern void Menu_InitSelect(); // 0x800C4E64

extern void Menu_ChkJoySelect(); // 0x800C54D0

extern void Menu_ChangeSelect(short s); // 0x800C5670

extern void Menu_InitSlideX(struct _SLIDE *slide, short xi, short xt, short time); // 0x800C5790

extern void Menu_InitSlideY(struct _SLIDE *slide, short yi, short yt, short time); // 0x800C5834

extern short Menu_DoSlide(struct _SLIDE *slide); // 0x800C58D8

extern short Menu_SelectLevel(); // 0x800C59B0

extern short Menu_SelectSector(); // 0x800C5BF0

extern void Menu_SwapBackground(); // 0x800C5DCC

extern void Menu_CreditsLaunch(short flag); // 0x800C5E4C

extern void Menu_CreditsInitScript(); // 0x800C604C

extern void Menu_TaskCredits(); // 0x800C61E0

extern void Menu_TabSector() ; // 0x800C68D4


#endif
