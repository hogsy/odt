#include "THISDUST.H"
#include "TASK.H"


// decompiled code
// original method signature: 
// void /*$ra*/ Task_Init()
 // line 28, offset 0x8009ab7c
	/* begin block 1 */
		// Start line: 57
	/* end block 1 */
	// End Line: 58

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Task_Init(void)

{
  TaskFirst = (TASK *)0x0;
  TaskLast = (TASK *)0x0;
  TaskCurrent = (TASK *)0x0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Task_Start()
 // line 36, offset 0x8009ab90
	/* begin block 1 */
		// Start line: 37
		// Start offset: 0x8009AB90
		// Variables:
	// 		struct TASK *t; // $v0
	// 		long sp; // $sp
	/* end block 1 */
	// End offset: 0x8009AB90
	// End Line: 37

	/* begin block 2 */
		// Start line: 72
	/* end block 2 */
	// End Line: 73

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Task_Start(void)

{
  TASK *pTVar1;
  undefined auStack24 [16];
  
  TaskSystem = Task_Malloc((TDRFuncPtr_Task_Malloc0f)0x0,0x10);
  pTVar1 = TaskFirst;
  *(undefined **)&TaskSystem->sp = auStack24;
  TaskCurrent = TaskSystem;
  TaskSystem->next = pTVar1;
  Scr_Clear();
  Task_nTasks = 0;
  Task_Next();
  Heap_FreeMem(TaskSystem);
  return;
}



// decompiled code
// original method signature: 
// struct TASK * /*$ra*/ Task_Add(TDRFuncPtr_Task_Add0f f /*$a0*/, long stack /*$a1*/)
 // line 66, offset 0x8009abe4
	/* begin block 1 */
		// Start line: 67
		// Start offset: 0x8009ABE4
		// Variables:
	// 		struct TASK *t; // $a1
	// 		struct TASK *n; // $v1
	// 		struct TASK *p; // $a0
	/* end block 1 */
	// End offset: 0x8009AD04
	// End Line: 136

	/* begin block 2 */
		// Start line: 133
	/* end block 2 */
	// End Line: 134

TASK * Task_Add(TDRFuncPtr_Task_Add0f f,long stack)

{
  TASK *pTVar1;
  TASK *pTVar2;
  TASK *pTVar3;
  TASK *pTVar4;
  
  pTVar1 = Task_Malloc((TDRFuncPtr_Task_Malloc0f)f,stack);
  pTVar3 = TaskCurrent;
  pTVar4 = TaskLast;
  pTVar2 = TaskFirst;
  if (TaskCurrent == (TASK *)0x0) {
    pTVar1->father = (TASK *)0x0;
    TaskFirst = pTVar1;
    pTVar1->prec = (TASK *)0x0;
    pTVar1->bprec = (TASK *)0x0;
    pTVar1->next = pTVar2;
    pTVar1->bnext = pTVar2;
    pTVar4 = pTVar1;
    if (pTVar2 != (TASK *)0x0) {
      pTVar2->prec = pTVar1;
      pTVar2->bprec = pTVar1;
      pTVar4 = TaskLast;
    }
  }
  else {
    pTVar2 = TaskCurrent->bnext;
    if (pTVar2 == (TASK *)0x0) {
      if (TaskCurrent->child == (TASK *)0x0) {
        pTVar2 = TaskCurrent->next;
        pTVar1->next = pTVar2;
        pTVar4 = pTVar3;
      }
      else {
        pTVar2 = TaskCurrent->father;
        while (pTVar2 != (TASK *)0x0) {
          if (pTVar2->bnext != (TASK *)0x0) {
            if (pTVar2 != (TASK *)0x0) {
              pTVar2 = pTVar2->bnext;
              pTVar4 = pTVar2->prec;
              pTVar1->next = pTVar2;
              goto LAB_8009ac8c;
            }
            break;
          }
          pTVar2 = pTVar2->father;
        }
        pTVar1->next = pTVar2;
      }
    }
    else {
      pTVar4 = pTVar2->prec;
      pTVar1->next = pTVar2;
    }
LAB_8009ac8c:
    pTVar1->prec = pTVar4;
    pTVar4->next = pTVar1;
    pTVar4 = pTVar1;
    if (pTVar2 != (TASK *)0x0) {
      pTVar2->prec = pTVar1;
      pTVar4 = TaskLast;
    }
    TaskLast = pTVar4;
    pTVar2 = TaskCurrent;
    pTVar3 = TaskCurrent->bnext;
    pTVar4 = TaskCurrent->father;
    pTVar1->bprec = TaskCurrent;
    pTVar1->father = pTVar4;
    pTVar1->bnext = pTVar3;
    pTVar2->bnext = pTVar1;
    pTVar4 = TaskLast;
    if (pTVar3 != (TASK *)0x0) {
      pTVar3->bprec = pTVar1;
      pTVar4 = TaskLast;
    }
  }
  TaskLast = pTVar4;
  return pTVar1;
}



// decompiled code
// original method signature: 
// struct TASK * /*$ra*/ Task_Link(TDRFuncPtr_Task_Link0f f /*$a0*/, long stack /*$a1*/)
 // line 140, offset 0x8009ad14
	/* begin block 1 */
		// Start line: 141
		// Start offset: 0x8009AD14
		// Variables:
	// 		struct TASK *t; // $a0
	// 		struct TASK *n; // $a1
	/* end block 1 */
	// End offset: 0x8009AD88
	// End Line: 167

	/* begin block 2 */
		// Start line: 288
	/* end block 2 */
	// End Line: 289

TASK * Task_Link(TDRFuncPtr_Task_Link0f f,long stack)

{
  TASK *pTVar1;
  TASK *pTVar2;
  TEXTCONTEXT *pTVar3;
  TASK *pTVar4;
  
  pTVar2 = Task_Malloc((TDRFuncPtr_Task_Malloc0f)f,stack);
  pTVar1 = TaskCurrent;
  pTVar4 = TaskCurrent->next;
  TaskCurrent->next = pTVar2;
  pTVar2->prec = pTVar1;
  pTVar2->next = pTVar4;
  pTVar1 = pTVar2;
  if (pTVar4 != (TASK *)0x0) {
    pTVar4->prec = pTVar2;
    pTVar1 = TaskLast;
  }
  TaskLast = pTVar1;
  pTVar1 = TaskCurrent;
  pTVar2->local = TaskCurrent->local;
  pTVar3 = pTVar1->text_context;
  pTVar2->father = pTVar1;
  pTVar2->bprec = (TASK *)0x0;
  pTVar2->text_context = pTVar3;
  pTVar4 = pTVar1->child;
  pTVar1->child = pTVar2;
  pTVar2->bnext = pTVar4;
  if (pTVar4 != (TASK *)0x0) {
    pTVar4->bprec = pTVar2;
  }
  return pTVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Task_Sleep(long time /*$s0*/)
 // line 173, offset 0x8009ad98
	/* begin block 1 */
		// Start line: 359
	/* end block 1 */
	// End Line: 360

void Task_Sleep(long time)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = time + -1;
  if (0 < time) {
    do {
      Task_Next();
      bVar1 = 0 < iVar2;
      iVar2 = iVar2 + -1;
    } while (bVar1);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Task_EnableList(struct TASK *t /*$s0*/)
 // line 180, offset 0x8009add8
	/* begin block 1 */
		// Start line: 373
	/* end block 1 */
	// End Line: 374

void Task_EnableList(TASK *t)

{
  if (t != (TASK *)0x0) {
    do {
      Task_EnableList(t->child);
      t->enable = 1;
      t = t->bnext;
    } while (t != (TASK *)0x0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Task_DisableList(struct TASK *t /*$s0*/)
 // line 191, offset 0x8009ae28
	/* begin block 1 */
		// Start line: 399
	/* end block 1 */
	// End Line: 400

void Task_DisableList(TASK *t)

{
  if (t != (TASK *)0x0) {
    do {
      Task_DisableList(t->child);
      t->enable = 0;
      t = t->bnext;
    } while (t != (TASK *)0x0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Task_Next()
 // line 204, offset 0x8009ae6c
	/* begin block 1 */
		// Start line: 205
		// Start offset: 0x8009AE6C
		// Variables:
	// 		struct TASK *n; // $v1
	// 		long sp; // $sp
	// 		long ra; // $ra
	/* end block 1 */
	// End offset: 0x8009AFDC
	// End Line: 313

	/* begin block 2 */
		// Start line: 435
	/* end block 2 */
	// End Line: 436

/* WARNING: Unknown calling convention yet parameter storage is locked */
/* WARNING: Exceeded maximum restarts with more pending */

void Task_Next(void)

{
  TASK *pTVar1;
  long unaff_s0;
  long unaff_s1;
  long unaff_s2;
  long unaff_s3;
  long unaff_s4;
  long unaff_s5;
  long unaff_s6;
  long unaff_s7;
  undefined *puVar2;
  long unaff_s8;
  _func_10 *unaff_retaddr;
  undefined auStackX0 [16];
  undefined auStack24 [16];
  
  pTVar1 = TaskCurrent;
  puVar2 = auStack24;
  if (TaskCurrent == (TASK *)0x0) {
    return;
  }
  *(BADSPACEBASE **)&TaskCurrent->sp = register0x00000074;
  pTVar1->exec = unaff_retaddr;
  pTVar1->s0 = unaff_s0;
  pTVar1->s1 = unaff_s1;
  pTVar1->s2 = unaff_s2;
  pTVar1->s3 = unaff_s3;
  pTVar1->s4 = unaff_s4;
  pTVar1->s5 = unaff_s5;
  pTVar1->s6 = unaff_s6;
  pTVar1->s7 = unaff_s7;
  pTVar1->fp = unaff_s8;
  if (pTVar1->display != (_func_11 *)0x0) {
    (*pTVar1->display)();
  }
  pTVar1 = TaskCurrent->next;
  do {
    if (pTVar1 == (TASK *)0x0) {
      Scr_Swap(*puVar2);
      Scr_Clear(*puVar2);
      TaskCurrent = TaskFirst;
      pTVar1 = TaskCurrent;
    }
    TaskCurrent = pTVar1;
    puVar2 = (undefined *)TaskCurrent->sp;
    if (TaskCurrent->enable == 0) {
      if (TaskCurrent->display != (_func_11 *)0x0) {
        (*TaskCurrent->display)();
      }
      pTVar1 = TaskCurrent->next;
    }
    else {
      (*TaskCurrent->exec)();
      pTVar1 = Task_Kill(TaskCurrent,*puVar2);
    }
  } while (TaskFirst != (TASK *)0x0);
  TaskCurrent = (TASK *)0x0;
                    /* WARNING: Could not recover jumptable at 0x8009afd4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*TaskSystem->exec)();
  return;
}



// decompiled code
// original method signature: 
// struct TASK * /*$ra*/ Task_Kill(struct TASK *t /*$s2*/)
 // line 316, offset 0x8009afec
	/* begin block 1 */
		// Start line: 317
		// Start offset: 0x8009AFEC
		// Variables:
	// 		struct TASK *p; // $s0
	// 		struct TASK *n; // $s1
	// 		struct TASK *f; // $s3
	// 		struct TASK *bn; // $v1
	// 		struct TASK *bp; // $v0
	/* end block 1 */
	// End offset: 0x8009B09C
	// End Line: 362

	/* begin block 2 */
		// Start line: 662
	/* end block 2 */
	// End Line: 663

TASK * Task_Kill(TASK *t)

{
  TASK *pTVar1;
  TASK *pTVar2;
  TASK *pTVar3;
  TASK *pTVar4;
  
  if (t->destructor != (_func_12 *)0x0) {
    (*t->destructor)();
  }
  pTVar3 = t->next;
  pTVar2 = t->prec;
  pTVar4 = t->father;
  if (t->child != (TASK *)0x0) {
    pTVar3 = Task_KillList(t->child);
  }
  pTVar1 = pTVar3;
  if (pTVar2 != (TASK *)0x0) {
    pTVar2->next = pTVar3;
    pTVar1 = TaskFirst;
  }
  TaskFirst = pTVar1;
  if (pTVar3 != (TASK *)0x0) {
    pTVar3->prec = pTVar2;
    pTVar2 = TaskLast;
  }
  TaskLast = pTVar2;
  pTVar1 = t->bnext;
  pTVar2 = t->bprec;
  if (pTVar1 != (TASK *)0x0) {
    pTVar1->bprec = pTVar2;
  }
  if (pTVar2 == (TASK *)0x0) {
    if (pTVar4 != (TASK *)0x0) {
      pTVar4->child = pTVar1;
    }
  }
  else {
    pTVar2->bnext = pTVar1;
  }
  Heap_FreeMem(t);
  Task_nTasks = Task_nTasks + -1;
  return pTVar3;
}



// decompiled code
// original method signature: 
// struct TASK * /*$ra*/ Task_KillList(struct TASK *t /*$s0*/)
 // line 369, offset 0x8009b0d0
	/* begin block 1 */
		// Start line: 370
		// Start offset: 0x8009B0D0
		// Variables:
	// 		struct TASK *n; // $v0
	/* end block 1 */
	// End offset: 0x8009B0FC
	// End Line: 377

	/* begin block 2 */
		// Start line: 776
	/* end block 2 */
	// End Line: 777

TASK * Task_KillList(TASK *t)

{
  TASK *in_v0;
  
  if (t != (TASK *)0x0) {
    do {
      in_v0 = Task_Kill(t);
      t = t->bnext;
    } while (t != (TASK *)0x0);
  }
  return in_v0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Task_EventExec(struct TASK *t /*$t3*/, long type /*$a1*/, long param /*$a2*/)
 // line 385, offset 0x8009b10c
	/* begin block 1 */
		// Start line: 386
		// Start offset: 0x8009B10C
		// Variables:
	// 		long sp; // $sp
	/* end block 1 */
	// End offset: 0x8009B1C0
	// End Line: 431

	/* begin block 2 */
		// Start line: 809
	/* end block 2 */
	// End Line: 810

/* WARNING: Exceeded maximum restarts with more pending */

void Task_EventExec(TASK *t,long type,long param)

{
  TASK *pTVar1;
  _func_13 *UNRECOVERED_JUMPTABLE;
  
  if (t->event_enable != 0) {
    UNRECOVERED_JUMPTABLE = t->event_exec;
    t->event_msg = type;
    t->event_param = param;
    pTVar1 = TaskCurrent;
    if (UNRECOVERED_JUMPTABLE != (_func_13 *)0x0) {
      *(_func_13 **)&t->exec = UNRECOVERED_JUMPTABLE;
      t->sp = t->event_sp;
      if (pTVar1 == t) {
                    /* WARNING: Could not recover jumptable at 0x8009b170. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE)();
        return;
      }
      t->s0 = t->event_s0;
      t->s1 = t->event_s1;
      t->s2 = t->event_s2;
      t->s3 = t->event_s3;
      t->s4 = t->event_s4;
      t->s5 = t->event_s5;
      t->s6 = t->event_s6;
      t->s7 = t->event_s7;
      t->fp = t->event_fp;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Task_EventRead(struct TASK *t /*$a0*/)
 // line 440, offset 0x8009b1c8
	/* begin block 1 */
		// Start line: 442
		// Start offset: 0x8009B1C8
		// Variables:
	// 		long result; // $v0
	/* end block 1 */
	// End offset: 0x8009B1C8
	// End Line: 442

	/* begin block 2 */
		// Start line: 934
	/* end block 2 */
	// End Line: 935

long Task_EventRead(TASK *t)

{
  long lVar1;
  
  lVar1 = t->event_msg;
  t->event_msg = 0;
  return lVar1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Task_EventWait()
 // line 449, offset 0x8009b1d4
	/* begin block 1 */
		// Start line: 450
		// Start offset: 0x8009B1D4
		// Variables:
	// 		long ra; // $ra
	// 		long sp; // $sp
	/* end block 1 */
	// End offset: 0x8009B230
	// End Line: 470

	/* begin block 2 */
		// Start line: 955
	/* end block 2 */
	// End Line: 956

/* WARNING: Unknown calling convention yet parameter storage is locked */

long Task_EventWait(void)

{
  long lVar1;
  long unaff_retaddr;
  
  TaskCurrent->event_ra = unaff_retaddr;
  Task_EventVec();
  while (TaskCurrent->event_msg == 0) {
    Task_Next();
  }
  lVar1 = TaskCurrent->event_msg;
  TaskCurrent->event_msg = 0;
  return lVar1;
}



// decompiled code
// original method signature: 
// struct TASK * /*$ra*/ Task_Malloc(TDRFuncPtr_Task_Malloc0f f /*$s1*/, long size /*$s0*/)
 // line 478, offset 0x8009b230
	/* begin block 1 */
		// Start line: 479
		// Start offset: 0x8009B230
		// Variables:
	// 		struct TASK *t; // $v0
	/* end block 1 */
	// End offset: 0x8009B250
	// End Line: 485

	/* begin block 2 */
		// Start line: 1013
	/* end block 2 */
	// End Line: 1014

TASK * Task_Malloc(TDRFuncPtr_Task_Malloc0f f,long size)

{
  TASK *pTVar1;
  
  if (size == 0) {
    size = 0x800;
  }
  pTVar1 = (TASK *)Heap_AllocMem(size + 0x90);
  pTVar1->sp = (void *)((int)&pTVar1[1].prec + size);
  pTVar1->event_exec = (_func_13 *)0x0;
  pTVar1->event_msg = 0;
  *(TDRFuncPtr_Task_Malloc0f *)&pTVar1->exec = f;
  pTVar1->child = (TASK *)0x0;
  pTVar1->event_enable = 1;
  pTVar1->enable = 1;
  pTVar1->destructor = (_func_12 *)0x0;
  pTVar1->display = (_func_11 *)0x0;
  pTVar1->text_context = (TEXTCONTEXT *)0x0;
  Task_nTasks = Task_nTasks + 1;
  return pTVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Task_EventVec()
 // line 525, offset 0x8009b2ac
	/* begin block 1 */
		// Start line: 1150
	/* end block 1 */
	// End Line: 1151

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Task_EventVec(void)

{
  TASK *pTVar1;
  long unaff_s0;
  long unaff_s1;
  long unaff_s2;
  long unaff_s3;
  long unaff_s4;
  long unaff_s5;
  long unaff_s6;
  long unaff_s7;
  long unaff_s8;
  _func_13 *unaff_retaddr;
  undefined auStackX0 [16];
  
  pTVar1 = TaskCurrent;
  TaskCurrent->event_s0 = unaff_s0;
  pTVar1->event_s1 = unaff_s1;
  pTVar1->event_s2 = unaff_s2;
  pTVar1->event_s3 = unaff_s3;
  pTVar1->event_s4 = unaff_s4;
  pTVar1->event_s5 = unaff_s5;
  pTVar1->event_s6 = unaff_s6;
  pTVar1->event_s7 = unaff_s7;
  pTVar1->event_fp = unaff_s8;
  pTVar1->event_exec = unaff_retaddr;
  *(BADSPACEBASE **)&pTVar1->event_sp = register0x00000074;
  return;
}





