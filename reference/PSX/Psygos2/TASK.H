#ifndef TASK_H
#define TASK_H


extern void Task_Init(); // 0x8009AB7C

extern void Task_Start(); // 0x8009AB90

extern struct TASK * Task_Add(TDRFuncPtr_Task_Add0f f, long stack); // 0x8009ABE4

extern struct TASK * Task_Link(TDRFuncPtr_Task_Link0f f, long stack); // 0x8009AD14

extern void Task_Sleep(long time); // 0x8009AD98

extern void Task_EnableList(struct TASK *t); // 0x8009ADD8

extern void Task_DisableList(struct TASK *t); // 0x8009AE28

extern void Task_Next(); // 0x8009AE6C

extern struct TASK * Task_Kill(struct TASK *t); // 0x8009AFEC

extern struct TASK * Task_KillList(struct TASK *t); // 0x8009B0D0

extern void Task_EventExec(struct TASK *t, long type, long param); // 0x8009B10C

extern long Task_EventRead(struct TASK *t); // 0x8009B1C8

extern long Task_EventWait(); // 0x8009B1D4

extern struct TASK * Task_Malloc(TDRFuncPtr_Task_Malloc0f f, long size); // 0x8009B230

extern void Task_EventVec(); // 0x8009B2AC


typedef void (*TDRFuncPtr_Task_Add0f)();

typedef void (*TDRFuncPtr_Task_Link0f)();

typedef void (*TDRFuncPtr_Task_Malloc0f)();




#endif
