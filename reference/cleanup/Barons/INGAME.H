#ifndef INGAME_H
#define INGAME_H


extern void InGame_Init(); // 0x80081F38

extern long InGame_Confirm(short Title); // 0x80081F80

extern void InGame_Pause(); // 0x80082018

extern void InGame_CheatTask(); // 0x80082164

extern void InGame_LevelEnd(struct _PLAYER *pl, long entry); // 0x80082534

extern long InGame_LoadGame(); // 0x80082610

extern long InGame_SaveGame(struct _PLAYER *pl, long entry, long mode); // 0x800827E4

extern long InGame_ChooseCard(); // 0x8008281C

extern long InGame_FormatCard(long channel); // 0x80082A70

extern long InGame_ChooseFile(long channel, long mode, long bSave); // 0x80082C24

extern long InGame_TestFile(char *name, char *string, long n); // 0x80083088

extern long InGame_GetFileIndex(); // 0x80083180

extern void InGame_DisplayText(char *text, long time); // 0x80083214

extern void InGame_MenuAlloc(long help); // 0x80083274

extern void InGame_MenuFree(); // 0x800832B4

extern void InGame_MenuClear(); // 0x800832FC

extern void InGame_MenuTitle(char *title); // 0x80083314

extern void InGame_MenuOption(char *text, char command); // 0x8008336C

extern void InGame_MenuExec(long def_opt, long card_test); // 0x80083424

extern long InGame_MenuWait(); // 0x80083478

extern void InGame_MenuTask(); // 0x800834C0


#endif
