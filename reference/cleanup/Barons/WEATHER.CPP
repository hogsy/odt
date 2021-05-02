#include "THISDUST.H"
#include "WEATHER.H"


// decompiled code
// original method signature: 
// void /*$ra*/ Weather_Add(struct _LIGHT *l /*$s0*/)
 // line 49, offset 0x800653ec
	/* begin block 1 */
		// Start line: 50
		// Start offset: 0x800653EC
	/* end block 1 */
	// End offset: 0x800654B0
	// End Line: 76

	/* begin block 2 */
		// Start line: 98
	/* end block 2 */
	// End Line: 99

void Weather_Add(_LIGHT *l)

{
  bool bVar1;
  ushort uVar2;
  _WEATHER *wea;
  short type;
  
  wea = (_WEATHER *)Task_Link(Weather_Task,0x67c);
  *(_WEATHER **)&l->handle = wea;
  (wea->center).vx = (l->pos).vx;
  (wea->center).vy = (l->pos).vy;
  (wea->center).vz = (l->pos).vz;
  *(char *)&wea[5].task.s7 = (char)((ushort)(l->color).vx >> 4);
  *(undefined *)((int)&wea[5].task.s7 + 1) = (char)((ushort)(l->color).vy >> 4);
  uVar2 = (l->color).vz;
  *(undefined2 *)((int)&wea[5].task.event_ra + 2) = 0;
  *(undefined *)((int)&wea[5].task.s7 + 2) = (char)(uVar2 >> 4);
  *(short *)&wea[5].task.event_s0 = l->fall_off + 1;
  *(ushort *)((int)&wea[5].task.event_s0 + 2) = (ushort)l->density;
  bVar1 = l->amb != '\x05';
  if (bVar1) {
    type = (ushort)l->amb - 1;
  }
  else {
    type = 0;
  }
  Weather_Init(wea,type,(ushort)!bVar1);
  return;
}



// decompiled code
// original method signature: 
// struct TASK * /*$ra*/ Weather_AddRain(struct WEATHER_7fake *pos /*$s4*/, long duration /*$s5*/, long fall_off /*$s1*/, struct WEATHER_8fake *col /*$s2*/, long density /*stack 16*/)
 // line 79, offset 0x800654c0
	/* begin block 1 */
		// Start line: 80
		// Start offset: 0x800654C0
		// Variables:
	// 		struct _WEATHER *wea; // $s0
	/* end block 1 */
	// End offset: 0x800654C0
	// End Line: 80

	/* begin block 2 */
		// Start line: 167
	/* end block 2 */
	// End Line: 168

TASK * Weather_AddRain(undefined pos,long duration,long fall_off,undefined col,long density)

{
  _WEATHER *wea;
  undefined3 in_register_00000011;
  undefined3 in_register_0000001d;
  undefined4 uVar1;
  
  wea = (_WEATHER *)Task_Link(Weather_Task,0x67c);
  uVar1 = ((undefined4 *)CONCAT31(in_register_00000011,pos))[1];
  *(undefined4 *)&wea->center = *(undefined4 *)CONCAT31(in_register_00000011,pos);
  *(undefined4 *)&(wea->center).vz = uVar1;
  wea[5].task.s7 = *(long *)CONCAT31(in_register_0000001d,col);
  *(undefined2 *)((int)&wea[5].task.event_ra + 2) = (short)duration;
  *(short *)&wea[5].task.event_s0 = (short)fall_off + 1;
  *(undefined2 *)((int)&wea[5].task.event_s0 + 2) = (short)density;
  Weather_Init(wea,0,1);
  return (TASK *)wea;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Weather_Init(struct _WEATHER *wea /*$s1*/, short type /*$a1*/, short mode /*$a2*/)
 // line 100, offset 0x80065584
	/* begin block 1 */
		// Start line: 101
		// Start offset: 0x80065584
		// Variables:
	// 		long i; // $s0
	// 		short *a; // $s6
	// 		struct WEATHER_7fake *p; // $s2
	// 		struct WEATHER_7fake *lp; // $s3
	// 		struct WEATHER_7fake *s; // $fp
	/* end block 1 */
	// End offset: 0x800658D0
	// End Line: 159

	/* begin block 2 */
		// Start line: 228
	/* end block 2 */
	// End Line: 229

void Weather_Init(_WEATHER *wea,short type,short mode)

{
  short sVar1;
  int iVar2;
  long lVar3;
  TASK **ppTVar4;
  TASK *pTVar5;
  int iVar6;
  TASK **ppTVar7;
  _struct_444 *p_Var8;
  long *plVar9;
  long *plVar10;
  long *plVar11;
  
  plVar10 = &wea[5].task.fp;
  ppTVar7 = &wea[1].task.bprec;
  p_Var8 = &wea->last_pos;
  plVar11 = &wea[1].task.event_s7;
  if (type == 2) {
    wea[5].task.event_s2 = -0x7ff9a36c;
    wea[5].task.event_s3 = -0x7ff99f94;
    Weather_InitLines(wea,0);
    iVar6 = 0;
    sVar1 = *(short *)((int)&wea[5].task.event_s0 + 2);
    *(undefined2 *)&wea[5].task.event_s0 = 7;
    if (0 < sVar1) {
      plVar9 = &wea[1].task.event_fp;
      ppTVar4 = &wea[1].task.bnext;
      do {
        *(short *)ppTVar7 = (wea->center).vx;
        *(short *)((int)ppTVar4 + -2) = (wea->center).vy;
        *(short *)ppTVar4 = (wea->center).vz;
        iVar2 = rand();
        *(short *)plVar11 = (short)iVar2 + (short)(iVar2 / 0x3c) * -0x3c + -0x1e;
        iVar2 = rand();
        *(short *)((int)plVar9 + -2) = (short)iVar2 + (short)(iVar2 / 0x3c) * -0x3c + -0x1e;
        iVar2 = rand();
        *(short *)plVar9 = (short)iVar2 + (short)(iVar2 / 0x3c) * -0x3c + -0x1e;
        if (*(short *)&wea[5].task.event_s0 == 0) {
          *(short *)plVar10 = 1;
        }
        else {
          lVar3 = M_rand();
          iVar2 = (int)*(short *)&wea[5].task.event_s0;
          if (iVar2 == 0) {
            trap(0x1c00);
          }
          if ((iVar2 == -1) && (lVar3 == -0x80000000)) {
            trap(0x1800);
          }
          *(short *)plVar10 = (short)(lVar3 % iVar2) + 1;
        }
        iVar6 = iVar6 + 1;
        plVar10 = (long *)((int)plVar10 + 2);
        ppTVar4 = ppTVar4 + 2;
        pTVar5 = ppTVar7[1];
        *(TASK **)p_Var8 = *ppTVar7;
        *(TASK **)&p_Var8->vz = pTVar5;
        ppTVar7 = ppTVar7 + 2;
        p_Var8 = p_Var8 + 1;
        plVar9 = plVar9 + 2;
        plVar11 = plVar11 + 2;
      } while (iVar6 < (int)*(short *)((int)&wea[5].task.event_s0 + 2));
    }
  }
  else {
    if (type < 3) {
      if (type == 0) {
        wea[5].task.event_s2 = -0x7ff9a5a8;
        wea[5].task.event_s3 = -0x7ff99f94;
        (wea->center).pad = mode;
        Weather_InitLines(wea,1);
        iVar6 = 0;
        if (0 < *(short *)((int)&wea[5].task.event_s0 + 2)) {
          do {
            Weather_InitPos(wea,(char)ppTVar7);
            iVar6 = iVar6 + 1;
            pTVar5 = ppTVar7[1];
            *(TASK **)p_Var8 = *ppTVar7;
            *(TASK **)&p_Var8->vz = pTVar5;
            ppTVar7 = ppTVar7 + 2;
            p_Var8 = p_Var8 + 1;
          } while (iVar6 < (int)*(short *)((int)&wea[5].task.event_s0 + 2));
        }
      }
    }
    else {
      iVar6 = 0;
      if (type == 3) {
        wea[5].task.event_s2 = -0x7ff9a0a8;
        sVar1 = *(short *)((int)&wea[5].task.event_s0 + 2);
        wea[5].task.event_s3 = -0x7ff99f94;
        if (0 < sVar1) {
          ppTVar4 = &wea[1].task.bnext;
          do {
            *(short *)ppTVar7 = (wea->center).vx;
            *(short *)((int)ppTVar4 + -2) = (wea->center).vy;
            iVar6 = iVar6 + 1;
            *(short *)ppTVar4 = (wea->center).vz;
            ppTVar4 = ppTVar4 + 2;
            *(short *)plVar10 = *(short *)&wea[5].task.event_s0;
            plVar10 = (long *)((int)plVar10 + 2);
            pTVar5 = ppTVar7[1];
            *(TASK **)p_Var8 = *ppTVar7;
            *(TASK **)&p_Var8->vz = pTVar5;
            ppTVar7 = ppTVar7 + 2;
            p_Var8 = p_Var8 + 1;
          } while (iVar6 < (int)*(short *)((int)&wea[5].task.event_s0 + 2));
        }
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Weather_Task()
 // line 162, offset 0x80065900
	/* begin block 1 */
		// Start line: 163
		// Start offset: 0x80065900
		// Variables:
	// 		struct _WEATHER *wea; // $v0
	/* end block 1 */
	// End offset: 0x8006592C
	// End Line: 170

	/* begin block 2 */
		// Start line: 418
	/* end block 2 */
	// End Line: 419

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Weather_Task(void)

{
  _func_13 *p_Var1;
  
  p_Var1 = TaskCurrent[9].event_exec;
  TaskCurrent->display = (_func_11 *)TaskCurrent[9].event_ra;
  if (p_Var1 != (_func_13 *)0x0) {
    (*p_Var1)();
  }
  TaskCurrent->display = (_func_11 *)0x0;
  Task_Sleep(2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Weather_InitPos(struct _WEATHER *wea /*$s1*/, struct WEATHER_7fake *p /*$s2*/)
 // line 174, offset 0x80065950
	/* begin block 1 */
		// Start line: 175
		// Start offset: 0x80065950
	/* end block 1 */
	// End offset: 0x80065950
	// End Line: 175

	/* begin block 2 */
		// Start line: 442
	/* end block 2 */
	// End Line: 443

void Weather_InitPos(_WEATHER *wea,undefined p)

{
  long lVar1;
  undefined3 in_register_00000015;
  short *psVar2;
  int iVar3;
  
  psVar2 = (short *)CONCAT31(in_register_00000015,p);
  iVar3 = (int)*(short *)&wea[5].task.event_s0 << 1;
  lVar1 = M_rand();
  if (iVar3 == 0) {
    trap(0x1c00);
  }
  if ((iVar3 == -1) && (lVar1 == -0x80000000)) {
    trap(0x1800);
  }
  *psVar2 = ((wea->center).vx + (short)(lVar1 % iVar3)) - *(short *)&wea[5].task.event_s0;
  lVar1 = M_rand();
  if (iVar3 == 0) {
    trap(0x1c00);
  }
  if ((iVar3 == -1) && (lVar1 == -0x80000000)) {
    trap(0x1800);
  }
  psVar2[1] = ((wea->center).vy + (short)(lVar1 % iVar3)) - *(short *)&wea[5].task.event_s0;
  lVar1 = M_rand();
  if (iVar3 == 0) {
    trap(0x1c00);
  }
  if ((iVar3 == -1) && (lVar1 == -0x80000000)) {
    trap(0x1800);
  }
  psVar2[2] = ((wea->center).vz + (short)(lVar1 % iVar3)) - *(short *)&wea[5].task.event_s0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Weather_MoveRain()
 // line 184, offset 0x80065a58
	/* begin block 1 */
		// Start line: 185
		// Start offset: 0x80065A58
		// Variables:
	// 		struct _WEATHER *wea; // $s2
	// 		long i; // $s5
	// 		long end; // $s6

		/* begin block 1.1 */
			// Start line: 191
			// Start offset: 0x80065AA0
			// Variables:
		// 		struct WEATHER_7fake *lp; // $s4
		// 		struct WEATHER_7fake *p; // $s0
		// 		struct _PLATFORM *plat; // $a0
		// 		long borne; // $v1

			/* begin block 1.1.1 */
				// Start line: 200
				// Start offset: 0x80065ABC
				// Variables:
			// 		struct WEATHER_7fake wind; // stack offset -40
			/* end block 1.1.1 */
			// End offset: 0x80065C24
			// End Line: 240
		/* end block 1.1 */
		// End offset: 0x80065C5C
		// End Line: 245
	/* end block 1 */
	// End offset: 0x80065C6C
	// End Line: 247

	/* begin block 2 */
		// Start line: 463
	/* end block 2 */
	// End Line: 464

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Weather_MoveRain(void)

{
  char cVar1;
  TASK *wea;
  int iVar2;
  _PLATFORM *p_Var3;
  int iVar4;
  undefined pos;
  long *plVar5;
  long *plVar6;
  TASK **ppTVar7;
  TASK **ppTVar8;
  int iVar9;
  short local_28;
  short local_26;
  short local_24;
  
  wea = TaskCurrent;
  iVar2 = (int)*(short *)((int)&TaskCurrent[9].event_msg + 2);
  iVar9 = 1;
  if (iVar2 != 0) {
    iVar9 = iVar2;
  }
  while (iVar9 != 0) {
    ppTVar8 = &wea[1].father;
    plVar5 = &wea[1].event_s5;
    iVar2 = 0;
    if (0 < *(short *)((int)&wea[9].event_param + 2)) {
      plVar6 = &wea[1].event_s6;
      ppTVar7 = &wea[1].child;
      do {
        memset(&local_28,0,8);
        pos = SUB41(plVar5,0);
        Wind_GetValue(pos,0xd8);
        *(short *)ppTVar8 = *(short *)plVar5;
        *(short *)((int)ppTVar7 + -2) = *(short *)((int)plVar6 + -2);
        *(short *)ppTVar7 = *(short *)plVar6;
        *(short *)plVar5 = *(short *)plVar5 + local_28;
        *(short *)((int)plVar6 + -2) = *(short *)((int)plVar6 + -2) + local_26;
        *(short *)plVar6 = local_24 + *(short *)plVar6 + -0x28;
        p_Var3 = Plat_GetPlat(pos);
        if (p_Var3 == (_PLATFORM *)0x0) {
          iVar4 = -500;
        }
        else {
          iVar4 = (int)*(short *)&p_Var3[1].obj.prec + (int)p_Var3[1].obj.pos.vy;
        }
        if ((int)*(short *)plVar6 < iVar4) {
          if ((p_Var3 != (_PLATFORM *)0x0) && (*(short *)((int)&wea[1].next + 2) != 0)) {
            cVar1 = *(char *)((int)&p_Var3[1].obj.pos.vx + 1);
            if ((cVar1 == '\0') || (p_Var3[1].obj.pos.vy == 0)) {
              Impact_Rain(pos,(char)wea + 'H',7);
            }
            else {
              if (cVar1 == '\x01') {
                Impact_Circle(pos,1);
              }
              else {
                if (cVar1 == '\x03') {
                  Impact_Acid(pos);
                }
              }
            }
          }
          Weather_InitPos((_WEATHER *)wea,pos);
          *(short *)ppTVar8 = *(short *)plVar5;
          *(short *)((int)ppTVar7 + -2) = *(short *)((int)plVar6 + -2);
          *(short *)ppTVar7 = *(short *)plVar6;
        }
        iVar2 = iVar2 + 1;
        ppTVar7 = ppTVar7 + 2;
        ppTVar8 = ppTVar8 + 2;
        plVar6 = plVar6 + 2;
        plVar5 = plVar5 + 2;
      } while (iVar2 < (int)*(short *)((int)&wea[9].event_param + 2));
    }
    if (*(short *)((int)&wea[9].event_msg + 2) != 0) {
      iVar9 = iVar9 + -1;
    }
    Task_Next();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Weather_MoveFire()
 // line 250, offset 0x80065c94
	/* begin block 1 */
		// Start line: 251
		// Start offset: 0x80065C94
		// Variables:
	// 		struct _WEATHER *wea; // $s2
	// 		long i; // $fp

		/* begin block 1.1 */
			// Start line: 255
			// Start offset: 0x80065CD4
			// Variables:
		// 		short *a; // $s6
		// 		struct WEATHER_7fake *lp; // $s7
		// 		struct WEATHER_7fake *p; // $s3
		// 		struct WEATHER_7fake *s; // $s5

			/* begin block 1.1.1 */
				// Start line: 264
				// Start offset: 0x80065D00
				// Variables:
			// 		struct WEATHER_7fake wind; // stack offset -56
			/* end block 1.1.1 */
			// End offset: 0x80065F18
			// End Line: 292
		/* end block 1.1 */
		// End offset: 0x80065F48
		// End Line: 294
	/* end block 1 */
	// End offset: 0x80065F58
	// End Line: 296

	/* begin block 2 */
		// Start line: 639
	/* end block 2 */
	// End Line: 640

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Weather_MoveFire(void)

{
  short sVar1;
  TASK *pTVar2;
  int iVar3;
  long lVar4;
  long *plVar5;
  long *plVar6;
  long *plVar7;
  TASK **ppTVar8;
  long *plVar9;
  long *plVar10;
  TASK **ppTVar11;
  int iVar12;
  short local_38;
  short local_36;
  short local_34;
  int local_30;
  
  pTVar2 = TaskCurrent;
  local_30 = -0x77777777;
  do {
    ppTVar11 = &pTVar2[1].father;
    plVar10 = &pTVar2[9].s4;
    plVar7 = &pTVar2[1].event_s5;
    plVar9 = &pTVar2[2].event_ra;
    iVar12 = 0;
    if (0 < *(short *)((int)&pTVar2[9].event_param + 2)) {
      plVar6 = &pTVar2[2].event_s0;
      plVar5 = &pTVar2[1].event_s6;
      ppTVar8 = &pTVar2[1].child;
      do {
        memset(&local_38,0,8);
        Wind_GetValue((char)plVar7,200);
        *(short *)ppTVar11 = *(short *)plVar7;
        *(short *)((int)ppTVar8 + -2) = *(short *)((int)plVar5 + -2);
        *(short *)ppTVar8 = *(short *)plVar5;
        *(short *)plVar7 = *(short *)plVar7 + *(short *)plVar9 + local_38;
        *(short *)((int)plVar5 + -2) =
             *(short *)((int)plVar5 + -2) + *(short *)((int)plVar6 + -2) + local_36;
        *(short *)plVar5 = *(short *)plVar5 + *(short *)plVar6 + local_34;
        *(short *)plVar9 = *(short *)plVar9 + -1;
        *(short *)((int)plVar6 + -2) = *(short *)((int)plVar6 + -2) + -1;
        *(short *)plVar6 = *(short *)plVar6 + -4;
        sVar1 = *(short *)plVar10;
        *(ushort *)plVar10 = sVar1 - 1U;
        if (((int)((uint)(ushort)(sVar1 - 1U) << 0x10) < 1) || (*(short *)plVar5 < 0)) {
          *(short *)plVar7 = *(short *)&pTVar2[1].prec;
          *(short *)((int)plVar5 + -2) = *(short *)((int)&pTVar2[1].prec + 2);
          *(short *)plVar5 = *(short *)&pTVar2[1].next;
          iVar3 = rand();
          *(short *)plVar9 =
               (short)iVar3 +
               ((short)((int)((ulonglong)((longlong)iVar3 * (longlong)local_30) >> 0x20) + iVar3 >>
                       5) - (short)(iVar3 >> 0x1f)) * -0x3c + -0x1e;
          iVar3 = rand();
          *(short *)((int)plVar6 + -2) =
               (short)iVar3 +
               ((short)((int)((ulonglong)((longlong)iVar3 * (longlong)local_30) >> 0x20) + iVar3 >>
                       5) - (short)(iVar3 >> 0x1f)) * -0x3c + -0x1e;
          iVar3 = rand();
          *(short *)plVar6 =
               (short)iVar3 +
               ((short)((int)((ulonglong)((longlong)iVar3 * (longlong)local_30) >> 0x20) + iVar3 >>
                       5) - (short)(iVar3 >> 0x1f)) * -0x3c + -0x1e;
          lVar4 = M_rand();
          iVar3 = (int)*(short *)&pTVar2[9].event_param;
          if (iVar3 == 0) {
            trap(0x1c00);
          }
          if ((iVar3 == -1) && (lVar4 == -0x80000000)) {
            trap(0x1800);
          }
          *(short *)plVar10 = (short)(lVar4 % iVar3) + 1;
          *(short *)ppTVar11 = *(short *)plVar7;
          *(short *)((int)ppTVar8 + -2) = *(short *)((int)plVar5 + -2);
          *(short *)ppTVar8 = *(short *)plVar5;
        }
        iVar12 = iVar12 + 1;
        plVar10 = (long *)((int)plVar10 + 2);
        ppTVar8 = ppTVar8 + 2;
        ppTVar11 = ppTVar11 + 2;
        plVar5 = plVar5 + 2;
        plVar7 = plVar7 + 2;
        plVar6 = plVar6 + 2;
        plVar9 = plVar9 + 2;
      } while (iVar12 < (int)*(short *)((int)&pTVar2[9].event_param + 2));
    }
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Weather_MoveImpact()
 // line 299, offset 0x80065f58
	/* begin block 1 */
		// Start line: 300
		// Start offset: 0x80065F58
		// Variables:
	// 		struct _WEATHER *wea; // $s0
	// 		long i; // $t0
	// 		short *a; // $s1

		/* begin block 1.1 */
			// Start line: 305
			// Start offset: 0x80065F88
			// Variables:
		// 		struct WEATHER_7fake *lp; // $t2
		// 		struct WEATHER_7fake *p; // $a2
		// 		struct WEATHER_7fake *s; // $t1
		/* end block 1.1 */
		// End offset: 0x80066038
		// End Line: 323
	/* end block 1 */
	// End offset: 0x80066058
	// End Line: 325

	/* begin block 2 */
		// Start line: 814
	/* end block 2 */
	// End Line: 815

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Weather_MoveImpact(void)

{
  ushort uVar1;
  TASK *pTVar2;
  TASK *pTVar3;
  long *plVar4;
  long *plVar5;
  long *plVar6;
  TASK **ppTVar7;
  int iVar8;
  long *plVar9;
  TASK **ppTVar10;
  
  pTVar3 = TaskCurrent;
  uVar1 = *(ushort *)&TaskCurrent[9].s4;
  pTVar2 = TaskCurrent + 9;
  *(ushort *)&TaskCurrent[9].s4 = uVar1 - 1;
  while (0 < (int)((uint)uVar1 << 0x10)) {
    ppTVar10 = &pTVar3[1].father;
    plVar6 = &pTVar3[1].event_s5;
    plVar9 = &pTVar3[2].event_ra;
    iVar8 = 0;
    if (0 < *(short *)((int)&pTVar3[9].event_param + 2)) {
      plVar5 = &pTVar3[2].event_s0;
      plVar4 = &pTVar3[1].event_s6;
      ppTVar7 = &pTVar3[1].child;
      do {
        *(short *)ppTVar10 = *(short *)plVar6;
        iVar8 = iVar8 + 1;
        *(short *)((int)ppTVar7 + -2) = *(short *)((int)plVar4 + -2);
        ppTVar10 = ppTVar10 + 2;
        *(short *)ppTVar7 = *(short *)plVar4;
        ppTVar7 = ppTVar7 + 2;
        *(short *)plVar6 = *(short *)plVar6 + *(short *)plVar9;
        plVar9 = plVar9 + 2;
        *(short *)((int)plVar4 + -2) = *(short *)((int)plVar4 + -2) + *(short *)((int)plVar5 + -2);
        plVar6 = plVar6 + 2;
        *(short *)plVar4 = *(short *)plVar4 + *(short *)plVar5;
        plVar4 = plVar4 + 2;
        *(short *)plVar5 = *(short *)plVar5 - *(short *)&pTVar3[9].event_sp;
        plVar5 = plVar5 + 2;
      } while (iVar8 < (int)*(short *)((int)&pTVar3[9].event_param + 2));
    }
    Task_Next();
    uVar1 = *(ushort *)&pTVar2->s4;
    *(ushort *)&pTVar2->s4 = uVar1 - 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Weather_DisplayLines()
 // line 328, offset 0x8006606c
	/* begin block 1 */
		// Start line: 329
		// Start offset: 0x8006606C
		// Variables:
	// 		struct _WEATHER *wea; // $s0
	// 		struct WEATHER_37fake *line; // $s2
	// 		struct WEATHER_37fake *pli; // $t2
	// 		struct WEATHER_55fake *tp; // $s1
	// 		struct WEATHER_8fake c2; // stack offset -40
	// 		struct WEATHER_8fake c1; // stack offset -32
	// 		long i; // $a3
	// 		long z; // stack offset -24
	/* end block 1 */
	// End offset: 0x80066320
	// End Line: 373

	/* begin block 2 */
		// Start line: 925
	/* end block 2 */
	// End Line: 926

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Weather_DisplayLines(void)

{
  short *psVar1;
  short sVar2;
  undefined4 uVar3;
  TASK *pTVar4;
  TASK *pTVar5;
  _SCREEN *p_Var6;
  undefined4 in_zero;
  undefined4 in_at;
  short *psVar7;
  _TMD_2D *p_Var8;
  int iVar9;
  undefined4 in_a3;
  byte *pbVar10;
  uint *puVar11;
  int iVar12;
  uint *puVar13;
  undefined *local_28;
  
  pTVar5 = TaskCurrent;
  local_28 = PTR_DAT_800ad714;
  puVar13 = (uint *)(&TaskCurrent[7].event_ra + (int)Scr_Frame * 0x1e);
  puVar11 = (uint *)((int)TaskCurrent + (int)Scr_Frame * 300 + 0x200);
  pTVar4 = TaskCurrent + 1;
  setCopReg(2,in_zero,pTVar4->father);
  setCopReg(2,in_at,TaskCurrent[1].child);
  copFunction(2,0x180001);
  uVar3 = getCopReg(2,0xe);
  *(undefined4 *)Tmd_2D = uVar3;
  p_Var8 = Tmd_2D;
  iVar12 = getCopReg(2,0x9800);
  *(short *)(puVar11 + 2) = Tmd_2D->vx;
  *(short *)((int)puVar11 + 10) = p_Var8->vy;
  if ((iVar12 >> 2 <= (int)Scr_OtSize + -1) && (-1 < iVar12 >> 2)) {
    GtxTmd_RotTransPersN
              (&pTVar4->father,p_Var8,(int)*(short *)((int)&pTVar5[9].event_param + 2),in_a3,
               local_28);
    iVar12 = 0;
    if (0 < *(short *)((int)&pTVar5[9].event_param + 2)) {
      psVar7 = (short *)((int)puVar11 + 10);
      p_Var8 = Tmd_2D;
      do {
        iVar12 = iVar12 + 1;
        psVar7[-1] = p_Var8->vx;
        psVar1 = &p_Var8->vy;
        p_Var8 = p_Var8 + 1;
        *psVar7 = *psVar1;
        psVar7 = psVar7 + 10;
      } while (iVar12 < (int)*(short *)((int)&pTVar5[9].event_param + 2));
    }
    GtxTmd_RotTransPersN
              (&pTVar5[1].event_s5,Tmd_2D,(int)*(short *)((int)&pTVar5[9].event_param + 2),iVar12,
               local_28);
    iVar12 = 0;
    if (0 < *(short *)((int)&pTVar5[9].event_param + 2)) {
      pbVar10 = (byte *)((int)puVar11 + 7);
      do {
        p_Var8 = Tmd_2D + iVar12;
        iVar9 = (int)((uint)(ushort)p_Var8->vz << 0x10) >> 0x12;
        if ((0x1d < iVar9) && (iVar9 <= (int)Scr_OtSize + -1)) {
          *(short *)(pbVar10 + 9) = p_Var8->vx;
          sVar2 = p_Var8->vy;
          *pbVar10 = *pbVar10 | 2;
          p_Var6 = Scr;
          *(short *)(pbVar10 + 0xb) = sVar2;
          *puVar11 = *puVar11 & 0xff000000 | p_Var6->ot[iVar9] & 0xffffff;
          p_Var6->ot[iVar9] = p_Var6->ot[iVar9] & 0xff000000 | (uint)puVar11 & 0xffffff;
          *puVar13 = *puVar13 & 0xff000000 | p_Var6->ot[iVar9] & 0xffffff;
          p_Var6->ot[iVar9] = p_Var6->ot[iVar9] & 0xff000000 | (uint)puVar13 & 0xffffff;
        }
        iVar12 = iVar12 + 1;
        pbVar10 = pbVar10 + 0x14;
        puVar11 = puVar11 + 5;
        puVar13 = puVar13 + 2;
      } while (iVar12 < (int)*(short *)((int)&pTVar5[9].event_param + 2));
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Weather_InitLines(struct _WEATHER *wea /*$a0*/, short trans /*$a1*/)
 // line 376, offset 0x80066338
	/* begin block 1 */
		// Start line: 377
		// Start offset: 0x80066338
		// Variables:
	// 		long i; // $t3
	// 		long j; // $t0
	// 		struct WEATHER_37fake *pli; // $a2
	// 		struct WEATHER_55fake *tp; // $v1
	// 		struct WEATHER_8fake c0; // stack offset -8
	/* end block 1 */
	// End offset: 0x8006645C
	// End Line: 398

	/* begin block 2 */
		// Start line: 1055
	/* end block 2 */
	// End Line: 1056

void Weather_InitLines(_WEATHER *wea,short trans)

{
  undefined *puVar1;
  undefined uVar2;
  uint uVar3;
  undefined *puVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined local_8;
  undefined uStack7;
  undefined uStack6;
  
  puVar1 = PTR_DAT_800ad718;
  iVar10 = 0;
  iVar9 = 0x458;
  iVar8 = 0x200;
  do {
    iVar7 = 0;
    if (0 < *(short *)((int)&wea[5].task.event_s0 + 2)) {
      puVar6 = (uint *)((int)&(wea->task).next + iVar9);
      puVar4 = (undefined *)((int)&(wea->task).next + iVar8 + 3);
      do {
        local_8 = SUB41(puVar1,0);
        puVar4[-3] = local_8;
        uStack7 = (undefined)((uint)puVar1 >> 8);
        puVar4[-2] = uStack7;
        uStack6 = (undefined)((uint)puVar1 >> 0x10);
        puVar4[-1] = uStack6;
        puVar4[5] = *(undefined *)&wea[5].task.s7;
        puVar4[6] = *(undefined *)((int)&wea[5].task.s7 + 1);
        uVar2 = *(undefined *)((int)&wea[5].task.s7 + 2);
        puVar4[-4] = 4;
        *puVar4 = 0x50;
        puVar4[7] = uVar2;
        uVar2 = 0x50;
        if (trans != 0) {
          uVar2 = 0x52;
        }
        *puVar4 = uVar2;
        *(undefined *)((int)puVar6 + -1) = 1;
        uVar5 = 0xe1000000;
        if (Scr_Dtd != 0) {
          uVar5 = 0xe1000200;
        }
        uVar3 = uVar5 | 0x420;
        if (Scr_Dfe == 0) {
          uVar3 = uVar5 | 0x20;
        }
        iVar7 = iVar7 + 1;
        puVar4 = puVar4 + 0x14;
        *puVar6 = uVar3;
        puVar6 = puVar6 + 2;
      } while (iVar7 < (int)*(short *)((int)&wea[5].task.event_s0 + 2));
    }
    iVar9 = iVar9 + 0x78;
    iVar10 = iVar10 + 1;
    iVar8 = iVar8 + 300;
  } while (iVar10 < 2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Impact_Add(struct WEATHER_7fake *pos /*$s1*/, struct WEATHER_8fake *col /*$s2*/, struct WEATHER_7fake *speed /*$s4*/, short nb_part /*$a3*/, int life /*stack 16*/, int trans /*stack 20*/, int grav /*stack 24*/)
 // line 407, offset 0x80066464
	/* begin block 1 */
		// Start line: 408
		// Start offset: 0x80066464
		// Variables:
	// 		struct _WEATHER *wea; // $s0
	// 		struct WEATHER_7fake *s; // $s3
	// 		long i; // $s2
	/* end block 1 */
	// End offset: 0x80066660
	// End Line: 438

	/* begin block 2 */
		// Start line: 1140
	/* end block 2 */
	// End Line: 1141

void Impact_Add(undefined pos,undefined col,undefined speed,short nb_part,int life,int trans,
               int grav)

{
  undefined uVar1;
  short sVar2;
  _WEATHER *wea;
  int iVar3;
  int iVar4;
  undefined3 in_register_00000011;
  short *psVar5;
  undefined3 in_register_00000015;
  undefined *puVar6;
  undefined3 in_register_00000019;
  ushort *puVar7;
  long *plVar8;
  int iVar9;
  long *plVar10;
  
  puVar7 = (ushort *)CONCAT31(in_register_00000019,speed);
  puVar6 = (undefined *)CONCAT31(in_register_00000015,col);
  psVar5 = (short *)CONCAT31(in_register_00000011,pos);
  sVar2 = Impact_Clipped(pos);
  if (sVar2 == 0) {
    wea = (_WEATHER *)Task_Add(Weather_Task,0x77c);
    (wea->center).vx = *psVar5;
    (wea->center).vy = psVar5[1];
    (wea->center).vz = psVar5[2];
    *(undefined *)&wea[5].task.s7 = *puVar6;
    plVar10 = &wea[1].task.event_s7;
    *(undefined *)((int)&wea[5].task.s7 + 1) = puVar6[1];
    uVar1 = puVar6[2];
    *(short *)&wea[5].task.event_s1 = (short)grav;
    *(short *)((int)&wea[5].task.event_s0 + 2) = nb_part;
    *(short *)&wea[5].task.event_s0 = (short)life;
    *(undefined *)((int)&wea[5].task.s7 + 2) = uVar1;
    Weather_Init(wea,3,0);
    Weather_InitLines(wea,(short)trans);
    iVar9 = 0;
    if (0 < *(short *)((int)&wea[5].task.event_s0 + 2)) {
      plVar8 = &wea[1].task.event_fp;
      do {
        iVar9 = iVar9 + 1;
        iVar3 = rand();
        iVar4 = (int)((uint)*puVar7 << 0x10) >> 0x10;
        if (iVar4 == 0) {
          trap(0x1c00);
        }
        if ((iVar4 == -1) && (iVar3 == -0x80000000)) {
          trap(0x1800);
        }
        *(short *)plVar10 =
             (short)(iVar3 % iVar4) - (short)((int)(iVar4 + (((uint)*puVar7 << 0x10) >> 0x1f)) >> 1)
        ;
        iVar3 = rand();
        iVar4 = (int)((uint)puVar7[1] << 0x10) >> 0x10;
        if (iVar4 == 0) {
          trap(0x1c00);
        }
        if ((iVar4 == -1) && (iVar3 == -0x80000000)) {
          trap(0x1800);
        }
        *(short *)((int)plVar8 + -2) =
             (short)(iVar3 % iVar4) -
             (short)((int)(iVar4 + (((uint)puVar7[1] << 0x10) >> 0x1f)) >> 1);
        iVar3 = rand();
        iVar4 = (int)((uint)puVar7[2] << 0x10) >> 0x10;
        if (iVar4 == 0) {
          trap(0x1c00);
        }
        if ((iVar4 == -1) && (iVar3 == -0x80000000)) {
          trap(0x1800);
        }
        plVar10 = plVar10 + 2;
        *(short *)plVar8 =
             ((short)(iVar3 % iVar4) -
             (short)((int)(iVar4 + (((uint)puVar7[2] << 0x10) >> 0x1f)) >> 1)) + 10;
        plVar8 = plVar8 + 2;
      } while (iVar9 < (int)*(short *)((int)&wea[5].task.event_s0 + 2));
    }
  }
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ Impact_Clipped(struct WEATHER_7fake *pos /*$a0*/)
 // line 441, offset 0x80066690
	/* begin block 1 */
		// Start line: 442
		// Start offset: 0x80066690
		// Variables:
	// 		struct WEATHER_9fake p2D; // stack offset -16
	// 		long z; // stack offset -8
	/* end block 1 */
	// End offset: 0x80066744
	// End Line: 461

	/* begin block 2 */
		// Start line: 1246
	/* end block 2 */
	// End Line: 1247

/* WARNING: Unknown calling convention yet parameter storage is locked */

short Impact_Clipped(undefined pos)

{
  undefined4 uVar1;
  undefined4 in_zero;
  undefined4 in_at;
  short sVar2;
  undefined3 in_register_00000011;
  int iVar3;
  short local_10;
  short sStack14;
  
  setCopReg(2,in_zero,*(undefined4 *)CONCAT31(in_register_00000011,pos));
  setCopReg(2,in_at,((undefined4 *)CONCAT31(in_register_00000011,pos))[1]);
  copFunction(2,0x180001);
  uVar1 = getCopReg(2,0xe);
  iVar3 = getCopReg(2,0x9800);
  local_10 = (short)uVar1;
  sVar2 = 1;
  if ((-1 < local_10) && (sVar2 = 1, local_10 <= Scr_W)) {
    sStack14 = (short)((uint)uVar1 >> 0x10);
    sVar2 = 1;
    if ((-1 < sStack14) && (sVar2 = 1, sStack14 <= Scr_H)) {
      sVar2 = 1;
      if ((iVar3 >> 2 <= (int)Scr_OtSize + -1) && (sVar2 = 1, 9 < iVar3 >> 2)) {
        sVar2 = 0;
      }
    }
  }
  return sVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Impact_DisplayShapeList(short num_shape /*$a0*/)
 // line 464, offset 0x8006674c
	/* begin block 1 */
		// Start line: 465
		// Start offset: 0x8006674C
		// Variables:
	// 		struct _WCIRC *circ; // $a2
	// 		short i; // $a1
	/* end block 1 */
	// End offset: 0x800667CC
	// End Line: 477

	/* begin block 2 */
		// Start line: 1292
	/* end block 2 */
	// End Line: 1293

void Impact_DisplayShapeList(short num_shape)

{
  byte bVar1;
  TASK *pTVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  pTVar2 = TaskCurrent;
  iVar5 = 0;
  bVar1 = *(byte *)((int)&TaskCurrent[1].next + 3);
  if (0 < *(short *)&TaskCurrent[1].prec) {
    iVar4 = 0;
    do {
      iVar3 = (iVar4 >> 0xd) + pTVar2[7].event_s1;
      *(ushort *)(iVar3 + 6) = (ushort)*(byte *)(iVar3 + 6);
      iVar4 = (iVar4 >> 0xd) + pTVar2[7].event_s1;
      iVar5 = iVar5 + 1;
      *(ushort *)(iVar4 + 6) = *(ushort *)(iVar4 + 6) | ((ushort)bVar1 + num_shape) * 0x100;
      iVar4 = iVar5 * 0x10000;
    } while (iVar5 * 0x10000 >> 0x10 < (int)*(short *)&pTVar2[1].prec);
  }
  Main_Prims = (void *)GtxShp_DisplayListLOFF
                                 (&pTVar2[7].event_s0,Main_Prims,Scr->ot,(int)Scr_OtSize,0,
                                  Main_TextContext.Font.ascii_tab._20_4_);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Impact_DisplayShape()
 // line 481, offset 0x80066818
	/* begin block 1 */
		// Start line: 482
		// Start offset: 0x80066818
		// Variables:
	// 		struct _WCIRC *circ; // $a0
	// 		short size; // $v1
	// 		struct WEATHER_7fake pos; // stack offset -24
	// 		struct WEATHER_8fake c; // stack offset -16
	/* end block 1 */
	// End offset: 0x80066898
	// End Line: 500

	/* begin block 2 */
		// Start line: 1343
	/* end block 2 */
	// End Line: 1344

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Impact_DisplayShape(void)

{
  char cVar1;
  TASK *pTVar2;
  TASK *local_18;
  TASK *local_14;
  TASK *local_10 [2];
  
  pTVar2 = TaskCurrent;
  *(ushort *)((int)&TaskCurrent[1].bprec + 2) =
       (ushort)*(byte *)((int)&TaskCurrent[1].next + 2) |
       (*(short *)&TaskCurrent[1].next + (ushort)*(byte *)((int)&TaskCurrent[1].next + 3)) * 0x100;
  local_18 = pTVar2[1].child;
  local_14 = pTVar2[1].bprec;
  cVar1 = *(char *)((int)&pTVar2[1].father + 3);
  *(TASK **)&pTVar2[7].event_s1 = (TASK *)&local_18;
  if (cVar1 != -1) {
    local_10[0] = pTVar2[1].father;
    *(TASK **)&pTVar2[7].event_s2 = (TASK *)local_10;
  }
  Main_Prims = (void *)GtxShp_DisplayListLOFF
                                 (&pTVar2[7].event_s0,Main_Prims,Scr->ot,(int)Scr_OtSize,0,
                                  Main_TextContext.Font.ascii_tab._20_4_);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Impact_Rain(struct WEATHER_7fake *pos /*$a0*/, struct WEATHER_8fake *col /*$a1*/, short nb_part /*$a2*/)
 // line 504, offset 0x800668e0
	/* begin block 1 */
		// Start line: 505
		// Start offset: 0x800668E0
		// Variables:
	// 		struct WEATHER_7fake speed; // stack offset -16
	/* end block 1 */
	// End offset: 0x800668E0
	// End Line: 505

	/* begin block 2 */
		// Start line: 1397
	/* end block 2 */
	// End Line: 1398

void Impact_Rain(undefined1 pos,undefined1 col,short nb_part)

{
  Impact_Add(pos,col,0xf0,nb_part,8,1,3);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Impact_D3Blood(struct WEATHER_7fake *pos /*$s1*/, struct _D3_OBJECT *o /*$s2*/, short nb_part /*$a2*/)
 // line 512, offset 0x80066948
	/* begin block 1 */
		// Start line: 513
		// Start offset: 0x80066948
		// Variables:
	// 		struct WEATHER_118fake *t; // $a0
	// 		short nb; // $a1
	/* end block 1 */
	// End offset: 0x800669E8
	// End Line: 532

	/* begin block 2 */
		// Start line: 1414
	/* end block 2 */
	// End Line: 1415

void Impact_D3Blood(undefined pos,_D3_OBJECT *o,short nb_part)

{
  short sVar1;
  SFX_118fake *ex;
  undefined3 in_register_00000011;
  undefined4 uVar2;
  
  sVar1 = Impact_Clipped(pos);
  if (sVar1 == 0) {
    ex = (SFX_118fake *)Task_Add(SFX_ExplosionTask,0x784);
    uVar2 = ((undefined4 *)CONCAT31(in_register_00000011,pos))[1];
    *(undefined4 *)&(ex->obj).pos = *(undefined4 *)CONCAT31(in_register_00000011,pos);
    *(undefined4 *)&(ex->obj).pos.vz = uVar2;
    *(undefined2 *)(ex[1].type + 4) = 4;
    *(undefined2 *)(ex[1].type + 6) = 0x14;
    *(_D3_OBJECT **)&(ex->t).local = o;
    if (0xf < nb_part) {
      nb_part = 0xf;
    }
    SFX04_Init(ex,(int)nb_part,0x29,1);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Impact_Sprites(struct WEATHER_7fake *pos /*$s0*/, long nb_part /*$s1*/, long sprite /*$s3*/, long size /*$s2*/)
 // line 535, offset 0x80066a00
	/* begin block 1 */
		// Start line: 536
		// Start offset: 0x80066A00
		// Variables:
	// 		struct WEATHER_118fake *t; // $v0
	/* end block 1 */
	// End offset: 0x80066A90
	// End Line: 555

	/* begin block 2 */
		// Start line: 1473
	/* end block 2 */
	// End Line: 1474

void Impact_Sprites(undefined pos,long nb_part,long sprite,long size)

{
  short sVar1;
  SFX_118fake *ex;
  undefined3 in_register_00000011;
  undefined4 uVar2;
  
  sVar1 = Impact_Clipped(pos);
  if (sVar1 == 0) {
    ex = (SFX_118fake *)Task_Add(SFX_ExplosionTask,0x784);
    uVar2 = ((undefined4 *)CONCAT31(in_register_00000011,pos))[1];
    *(undefined4 *)&(ex->obj).pos = *(undefined4 *)CONCAT31(in_register_00000011,pos);
    *(undefined4 *)&(ex->obj).pos.vz = uVar2;
    (ex->t).local = (void *)0x0;
    *(short *)(ex[1].type + 4) = (short)size;
    *(undefined2 *)(ex[1].type + 6) = 0x1e;
    SFX04_Init(ex,nb_part,sprite,size & 0xffff0000U | 1);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Impact_Blood(struct WEATHER_7fake *pos /*$a0*/, long nb_part /*$a1*/)
 // line 558, offset 0x80066aac
	/* begin block 1 */
		// Start line: 1532
	/* end block 1 */
	// End Line: 1533

void Impact_Blood(undefined1 pos,long nb_part)

{
  Impact_Sprites(pos,nb_part,0x29,4);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Impact_GreenBlood(struct WEATHER_7fake *pos /*$a0*/, long nb_part /*$a1*/)
 // line 564, offset 0x80066ad0
	/* begin block 1 */
		// Start line: 1545
	/* end block 1 */
	// End Line: 1546

void Impact_GreenBlood(undefined1 pos,long nb_part)

{
  Impact_Sprites(pos,nb_part,0xc6,4);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Impact_Petrole(struct WEATHER_7fake *pos /*$a0*/, long nb_part /*$a1*/)
 // line 570, offset 0x80066af4
	/* begin block 1 */
		// Start line: 1558
	/* end block 1 */
	// End Line: 1559

void Impact_Petrole(undefined1 pos,long nb_part)

{
  Impact_Sprites(pos,nb_part,0x99,nb_part & 0xffff0000U | 0xc);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Impact_Sparks(struct WEATHER_7fake *pos /*$a0*/, short nb_part /*$a1*/)
 // line 576, offset 0x80066b20
	/* begin block 1 */
		// Start line: 577
		// Start offset: 0x80066B20
		// Variables:
	// 		struct WEATHER_8fake col; // stack offset -24
	// 		struct WEATHER_7fake speed; // stack offset -16
	/* end block 1 */
	// End offset: 0x80066B20
	// End Line: 577

	/* begin block 2 */
		// Start line: 1571
	/* end block 2 */
	// End Line: 1572

void Impact_Sparks(undefined1 pos,short nb_part)

{
  Impact_Add(pos,0xe8,0xf0,nb_part,0xf,0,2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Impact_Circle(struct WEATHER_7fake *pos /*$s1*/, short nb /*$a1*/)
 // line 591, offset 0x80066ba4
	/* begin block 1 */
		// Start line: 592
		// Start offset: 0x80066BA4
		// Variables:
	// 		struct _WCIRC *circle; // $a2
	// 		long i; // $a1
	/* end block 1 */
	// End offset: 0x80066C30
	// End Line: 610

	/* begin block 2 */
		// Start line: 1602
	/* end block 2 */
	// End Line: 1603

void Impact_Circle(undefined pos,short nb)

{
  undefined2 *puVar1;
  short sVar2;
  TASK *pTVar3;
  TASK *pTVar4;
  undefined3 in_register_00000011;
  undefined2 *puVar5;
  int iVar6;
  
  puVar5 = (undefined2 *)CONCAT31(in_register_00000011,pos);
  sVar2 = Impact_Clipped(pos);
  if (sVar2 == 0) {
    pTVar3 = Task_Add(Impact_CircleTask,0x66c);
    *(short *)&pTVar3[1].prec = nb;
    iVar6 = 0;
    pTVar4 = pTVar3;
    if (0 < (int)((uint)(ushort)nb << 0x10)) {
      do {
        *(undefined2 *)&pTVar4[1].child = *puVar5;
        iVar6 = iVar6 + 1;
        *(undefined2 *)((int)&pTVar4[1].child + 2) = puVar5[1];
        puVar1 = puVar5 + 2;
        puVar5 = puVar5 + 4;
        *(undefined2 *)&pTVar4[1].bprec = *puVar1;
        pTVar4 = (TASK *)&pTVar4->father;
      } while (iVar6 < (int)*(short *)&pTVar3[1].prec);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Impact_CircleTask()
 // line 613, offset 0x80066c44
	/* begin block 1 */
		// Start line: 614
		// Start offset: 0x80066C44
		// Variables:
	// 		struct _WCIRC *circle; // $s1
	// 		long i; // $s0
	/* end block 1 */
	// End offset: 0x80066CC8
	// End Line: 632

	/* begin block 2 */
		// Start line: 1657
	/* end block 2 */
	// End Line: 1658

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Impact_CircleTask(void)

{
  char cVar1;
  TASK *pTVar2;
  char cVar3;
  short sVar4;
  uint uVar5;
  uint uVar6;
  
  pTVar2 = TaskCurrent;
  sVar4 = Impact_InitCircles();
  uVar6 = 0;
  if (sVar4 != 0) {
    TaskCurrent->display = Impact_DisplayCircles;
    uVar5 = 0;
    do {
      if (uVar5 == 0) {
        cVar1 = *(char *)((int)&pTVar2[1].next + 3);
        cVar3 = cVar1 + '\x01';
        if (cVar1 == '\a') {
          cVar3 = '\0';
        }
        *(char *)((int)&pTVar2[1].next + 3) = cVar3;
      }
      uVar6 = uVar6 + 1;
      Task_Next();
      uVar5 = uVar6 & 1;
    } while ((int)uVar6 < 0xf);
    Task_Sleep(2);
  }
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ Impact_InitCircles()
 // line 635, offset 0x80066ce0
	/* begin block 1 */
		// Start line: 637
		// Start offset: 0x80066CE0
		// Variables:
	// 		struct _WCIRC *circ; // $t0
	// 		long i; // $t1
	// 		long j; // $a2
	/* end block 1 */
	// End offset: 0x80066D94
	// End Line: 655

	/* begin block 2 */
		// Start line: 1710
	/* end block 2 */
	// End Line: 1711

/* WARNING: Unknown calling convention yet parameter storage is locked */

short Impact_InitCircles(void)

{
  TASK *pTVar1;
  short sVar2;
  int iVar3;
  TASK *pTVar4;
  int iVar5;
  TASK *pTVar6;
  int iVar7;
  int iVar8;
  
  pTVar1 = TaskCurrent;
  sVar2 = *(short *)&TaskCurrent[1].prec;
  iVar7 = 0;
  *(undefined *)((int)&TaskCurrent[1].next + 3) = 0;
  if (0 < sVar2) {
    iVar8 = 0;
    pTVar4 = pTVar1;
    pTVar6 = pTVar1;
    do {
      sVar2 = *(short *)&pTVar6[1].child + -0x1e;
      *(short *)&pTVar4[1].event_param = sVar2;
      *(short *)&pTVar4[1].fp = sVar2;
      sVar2 = *(short *)&pTVar6[1].child + 0x1e;
      *(short *)&pTVar4[1].event_exec = sVar2;
      pTVar4[1].enable = sVar2;
      iVar5 = 0;
      sVar2 = *(short *)((int)&pTVar6[1].child + 2) + -0x1e;
      pTVar4[1].event_enable = sVar2;
      *(short *)((int)&pTVar4[1].fp + 2) = sVar2;
      sVar2 = *(short *)((int)&pTVar6[1].child + 2) + 0x1e;
      *(short *)((int)&pTVar4[1].event_exec + 2) = sVar2;
      *(short *)((int)&pTVar4[1].event_param + 2) = sVar2;
      iVar3 = iVar8;
      do {
        iVar5 = iVar5 + 1;
        *(short *)((int)&pTVar1[1].text_context + iVar3) = *(short *)&pTVar1[1].bprec + -10;
        iVar3 = iVar3 + 8;
      } while (iVar5 < 4);
      iVar8 = iVar8 + 0x20;
      pTVar6 = (TASK *)&pTVar6->father;
      iVar7 = iVar7 + 1;
      pTVar4 = (TASK *)&pTVar4->display;
    } while (iVar7 < (int)*(short *)&pTVar1[1].prec);
  }
  return 1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Impact_DisplayCircles()
 // line 659, offset 0x80066d9c
	/* begin block 1 */
		// Start line: 660
		// Start offset: 0x80066D9C
		// Variables:
	// 		struct _WCIRC *circ; // $s3
	// 		long i; // $s2
	// 		long j; // $a2
	// 		long z; // $a0
	// 		struct WEATHER_70fake shp; // stack offset -80
	// 		struct WEATHER_31fake *pft4; // $s1
	// 		struct WEATHER_7fake tab_inter[4]; // stack offset -64
	/* end block 1 */
	// End offset: 0x80066FB8
	// End Line: 710

	/* begin block 2 */
		// Start line: 1772
	/* end block 2 */
	// End Line: 1773

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Impact_DisplayCircles(void)

{
  TASK *pTVar1;
  _SCREEN *p_Var2;
  int iVar3;
  undefined *puVar4;
  undefined4 *puVar5;
  _TMD_2D *p_Var6;
  int iVar7;
  undefined *puVar8;
  int iVar9;
  undefined4 uVar10;
  short *psVar11;
  SHAPE_31fake *prim;
  int iVar12;
  SHAPE_68fake local_50;
  undefined4 local_40 [8];
  
  pTVar1 = TaskCurrent;
  iVar12 = 0;
  local_50.file = Effects_Pcl;
  local_50.shape = (ushort)*(byte *)((int)&TaskCurrent[1].next + 3) + 0xcc;
  prim = (SHAPE_31fake *)((int)TaskCurrent + (int)Scr_Frame * 0x140 + 0x1dc);
  if (0 < *(short *)&TaskCurrent[1].prec) {
    psVar11 = &prim->y3;
    do {
      Shp_SetPolyFT4(prim,&local_50,0x14,0x14);
      iVar9 = 0;
      iVar7 = iVar12 << 5;
      puVar5 = local_40;
      do {
        iVar3 = (int)&pTVar1->prec + iVar7;
        uVar10 = *(undefined4 *)(iVar3 + 0xe0);
        *puVar5 = *(undefined4 *)(iVar3 + 0xdc);
        puVar5[1] = uVar10;
        *(undefined2 *)((int)puVar5 + 6) = 0;
        puVar5 = puVar5 + 2;
        iVar9 = iVar9 + 1;
        iVar7 = iVar7 + 8;
      } while (iVar9 < 4);
      GtxTmd_RotTransPersN(local_40,Tmd_2D,4);
      p_Var6 = Tmd_2D;
      psVar11[-0xd] = Tmd_2D->vx;
      psVar11[-0xc] = p_Var6->vy;
      psVar11[-9] = p_Var6[1].vx;
      psVar11[-8] = p_Var6[1].vy;
      psVar11[-5] = p_Var6[2].vx;
      psVar11[-4] = p_Var6[2].vy;
      puVar8 = &DAT_00002710;
      psVar11[-1] = p_Var6[3].vx;
      iVar7 = 0;
      *psVar11 = p_Var6[3].vy;
      do {
        puVar4 = (undefined *)((int)((uint)(ushort)p_Var6->vz << 0x10) >> 0x12);
        p_Var6->vz = p_Var6->vz >> 2;
        p_Var2 = Scr;
        if ((int)puVar4 < (int)puVar8) {
          puVar8 = puVar4;
        }
        iVar7 = iVar7 + 1;
        p_Var6 = p_Var6 + 1;
      } while (iVar7 < 4);
      if ((10 < (int)puVar8) && ((int)puVar8 < (int)Scr_OtSize)) {
        prim->tag = prim->tag & 0xff000000 | Scr->ot[(int)puVar8] & 0xffffff;
        p_Var2->ot[(int)puVar8] = p_Var2->ot[(int)puVar8] & 0xff000000 | (uint)prim & 0xffffff;
      }
      iVar12 = iVar12 + 1;
      psVar11 = psVar11 + 0x14;
      prim = prim + 1;
    } while (iVar12 < (int)*(short *)&pTVar1[1].prec);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Impact_Acid(struct WEATHER_7fake *pos /*$s0*/)
 // line 720, offset 0x80066fdc
	/* begin block 1 */
		// Start line: 721
		// Start offset: 0x80066FDC
		// Variables:
	// 		struct _WCIRC *circle; // $v0
	/* end block 1 */
	// End offset: 0x80067034
	// End Line: 734

	/* begin block 2 */
		// Start line: 1986
	/* end block 2 */
	// End Line: 1987

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Impact_Acid(undefined pos)

{
  short sVar1;
  TASK *pTVar2;
  undefined3 in_register_00000011;
  undefined2 *puVar3;
  
  puVar3 = (undefined2 *)CONCAT31(in_register_00000011,pos);
  sVar1 = Impact_Clipped(pos);
  if (sVar1 == 0) {
    pTVar2 = Task_Add(Impact_AcidTask,0x56c);
    *(undefined2 *)&pTVar2[1].prec = 1;
    *(undefined2 *)&pTVar2[1].child = *puVar3;
    *(undefined2 *)((int)&pTVar2[1].child + 2) = puVar3[1];
    *(undefined2 *)&pTVar2[1].bprec = puVar3[2];
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Impact_AcidTask()
 // line 737, offset 0x80067044
	/* begin block 1 */
		// Start line: 738
		// Start offset: 0x80067044
		// Variables:
	// 		struct _WCIRC *circle; // $s1
	// 		long i; // $s0
	/* end block 1 */
	// End offset: 0x800670B4
	// End Line: 754

	/* begin block 2 */
		// Start line: 2020
	/* end block 2 */
	// End Line: 2021

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Impact_AcidTask(void)

{
  char cVar1;
  TASK *pTVar2;
  char cVar3;
  short sVar4;
  uint uVar5;
  uint uVar6;
  
  pTVar2 = TaskCurrent;
  sVar4 = Impact_InitAcid();
  uVar6 = 0;
  if (sVar4 != 0) {
    uVar5 = 0;
    do {
      if (uVar5 == 0) {
        cVar1 = *(char *)((int)&pTVar2[1].next + 3);
        cVar3 = cVar1 + '\x01';
        if (cVar1 == '\x05') {
          cVar3 = '\0';
        }
        *(char *)((int)&pTVar2[1].next + 3) = cVar3;
      }
      uVar6 = uVar6 + 1;
      Task_Next();
      uVar5 = uVar6 & 3;
    } while ((int)uVar6 < 0x14);
    Task_Sleep(2);
  }
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ Impact_InitAcid()
 // line 757, offset 0x800670cc
	/* begin block 1 */
		// Start line: 758
		// Start offset: 0x800670CC
		// Variables:
	// 		struct _WCIRC *circ; // $s0
	/* end block 1 */
	// End offset: 0x80067150
	// End Line: 783

	/* begin block 2 */
		// Start line: 2066
	/* end block 2 */
	// End Line: 2067

/* WARNING: Unknown calling convention yet parameter storage is locked */

short Impact_InitAcid(void)

{
  bool bVar1;
  void *pvVar2;
  TASK *pTVar3;
  TASK *pTVar4;
  _PLATFORM *p_Var5;
  
  pTVar3 = TaskCurrent;
  *(undefined2 *)&TaskCurrent[1].next = 0xc6;
  *(undefined *)((int)&pTVar3[1].next + 2) = 0x10;
  *(undefined *)((int)&pTVar3[1].next + 3) = 0;
  *(undefined *)((int)&pTVar3[1].father + 3) = 0xff;
  p_Var5 = Plat_GetPlat((char)pTVar3 + -100);
  pvVar2 = Effects_Pcl;
  bVar1 = p_Var5[1].obj.pos.vy != 0;
  if (bVar1) {
    *(undefined2 *)&pTVar3[7].event_s3 = 1;
    *(undefined2 *)((int)&pTVar3[1].bprec + 2) = 0xc610;
    *(void **)&pTVar3[7].event_s0 = pvVar2;
    pTVar4 = TaskCurrent;
    pTVar3[7].event_s2 = 0;
    pTVar4->display = Impact_DisplayShape;
  }
  return (short)(ushort)bVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Impact_Bubble(struct WEATHER_7fake *pos /*$s1*/, short nshp /*$a1*/, short life /*$a2*/, short height /*$a3*/)
 // line 792, offset 0x80067160
	/* begin block 1 */
		// Start line: 793
		// Start offset: 0x80067160
		// Variables:
	// 		struct _WBUBBLE *bub; // $v1
	/* end block 1 */
	// End offset: 0x800671F0
	// End Line: 808

	/* begin block 2 */
		// Start line: 2172
	/* end block 2 */
	// End Line: 2173

void Impact_Bubble(undefined pos,short nshp,short life,short height)

{
  short sVar1;
  TASK *pTVar2;
  undefined3 in_register_00000011;
  undefined2 *puVar3;
  
  puVar3 = (undefined2 *)CONCAT31(in_register_00000011,pos);
  sVar1 = Impact_Clipped(pos);
  if (sVar1 == 0) {
    pTVar2 = Task_Add(Impact_BubbleTask,0x490);
    if (0x1e < nshp) {
      nshp = 0x1e;
    }
    *(short *)&pTVar2[1].prec = nshp;
    *(short *)&pTVar2[1].next = life;
    *(short *)((int)&pTVar2[1].prec + 2) = height;
    *(undefined2 *)&pTVar2[1].father = *puVar3;
    *(undefined2 *)((int)&pTVar2[1].father + 2) = puVar3[1];
    *(undefined2 *)&pTVar2[1].child = puVar3[2];
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Impact_BubbleTask()
 // line 811, offset 0x8006720c
	/* begin block 1 */
		// Start line: 812
		// Start offset: 0x8006720C
		// Variables:
	// 		struct _WBUBBLE *bub; // $s0
	// 		struct WEATHER_7fake *p; // $a3
	// 		struct WEATHER_7fake *s; // $t0
	// 		long i; // $s1
	// 		long j; // $a2
	/* end block 1 */
	// End offset: 0x80067330
	// End Line: 840

	/* begin block 2 */
		// Start line: 2210
	/* end block 2 */
	// End Line: 2211

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Impact_BubbleTask(void)

{
  TASK *pTVar1;
  short sVar2;
  TASK **ppTVar3;
  long *plVar4;
  int iVar5;
  TASK **ppTVar6;
  long *plVar7;
  int iVar8;
  
  pTVar1 = TaskCurrent;
  iVar8 = (int)*(short *)&TaskCurrent[1].next;
  sVar2 = Impact_InitBubble();
  if (sVar2 != 0) {
    while (iVar8 = iVar8 + -1, iVar8 != -1) {
      ppTVar6 = &pTVar1[1].bprec;
      plVar7 = &pTVar1[2].event_s1;
      iVar5 = 0;
      if (0 < *(short *)&pTVar1[1].prec) {
        plVar4 = &pTVar1[2].event_s2;
        ppTVar3 = &pTVar1[1].bnext;
        do {
          if (*(short *)ppTVar3 < *(short *)((int)&pTVar1[1].prec + 2)) {
            *(short *)ppTVar6 = *(short *)ppTVar6 + *(short *)plVar7;
            *(short *)((int)ppTVar3 + -2) =
                 *(short *)((int)ppTVar3 + -2) + *(short *)((int)plVar4 + -2);
            *(short *)ppTVar3 = *(short *)ppTVar3 + *(short *)plVar4;
          }
          iVar5 = iVar5 + 1;
          ppTVar3 = ppTVar3 + 2;
          ppTVar6 = ppTVar6 + 2;
          plVar4 = plVar4 + 2;
          plVar7 = plVar7 + 2;
        } while (iVar5 < (int)*(short *)&pTVar1[1].prec);
      }
      Main_Prims = (void *)GtxShp_DisplayListLOFF
                                     (&pTVar1[4].s5,Main_Prims,Scr->ot,(int)Scr_OtSize,0,
                                      Main_TextContext.Font.ascii_tab._20_4_);
      Task_Next();
    }
  }
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ Impact_InitBubble()
 // line 843, offset 0x80067344
	/* begin block 1 */
		// Start line: 844
		// Start offset: 0x80067344
		// Variables:
	// 		struct _WBUBBLE *bub; // $s0
	// 		struct WEATHER_7fake *p; // $s3
	// 		struct WEATHER_7fake *s; // $s5
	// 		long i; // $s4
	// 		long size; // $v0
	/* end block 1 */
	// End offset: 0x800674A8
	// End Line: 869

	/* begin block 2 */
		// Start line: 2284
	/* end block 2 */
	// End Line: 2285

/* WARNING: Unknown calling convention yet parameter storage is locked */

short Impact_InitBubble(void)

{
  short sVar1;
  undefined2 uVar2;
  ushort uVar3;
  TASK *pTVar4;
  long lVar5;
  long lVar6;
  ushort *puVar7;
  long *plVar8;
  TASK *pTVar9;
  int iVar10;
  long *plVar11;
  
  pTVar4 = TaskCurrent;
  iVar10 = 0;
  pTVar9 = (TASK *)&TaskCurrent[1].bprec;
  uVar2 = *(undefined2 *)&TaskCurrent[1].prec;
  sVar1 = *(short *)&TaskCurrent[1].prec;
  plVar11 = &TaskCurrent[2].event_s1;
  *(void **)&TaskCurrent[4].s5 = Effects_Pcl;
  pTVar4[4].s7 = 0;
  *(TASK **)&pTVar4[4].s6 = pTVar9;
  *(undefined2 *)&pTVar4[4].fp = uVar2;
  if (0 < sVar1) {
    plVar8 = &pTVar4[2].event_s2;
    puVar7 = (ushort *)((int)&pTVar4[1].bnext + 2);
    do {
      lVar5 = M_rand();
      lVar6 = lVar5;
      if (lVar5 < 0) {
        lVar6 = lVar5 + 3;
      }
      *(undefined2 *)&pTVar9->prec = *(undefined2 *)&pTVar4[1].father;
      puVar7[-2] = *(ushort *)((int)&pTVar4[1].father + 2);
      uVar3 = *(ushort *)&pTVar4[1].child;
      *puVar7 = (short)lVar5 + (short)(lVar6 >> 2) * -4 + 1U | 0xe200;
      puVar7[-1] = uVar3;
      lVar6 = M_rand();
      *(short *)plVar11 = (short)lVar6 + (short)(lVar6 / 3) * -3 + -1;
      lVar6 = M_rand();
      *(short *)((int)plVar8 + -2) = (short)lVar6 + (short)(lVar6 / 3) * -3 + -1;
      lVar6 = M_rand();
      iVar10 = iVar10 + 1;
      pTVar9 = (TASK *)&pTVar9->father;
      puVar7 = puVar7 + 4;
      plVar11 = plVar11 + 2;
      *(short *)plVar8 = (short)lVar6 + (short)(lVar6 / 5) * -5 + 5;
      plVar8 = plVar8 + 2;
    } while (iVar10 < (int)*(short *)&pTVar4[1].prec);
  }
  return 1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Impact_Smoke(struct WEATHER_7fake *pos /*$s0*/, short mode /*$a1*/)
 // line 879, offset 0x800674d4
	/* begin block 1 */
		// Start line: 880
		// Start offset: 0x800674D4
		// Variables:
	// 		struct _WCIRC *smoke; // $v0
	/* end block 1 */
	// End offset: 0x80067538
	// End Line: 894

	/* begin block 2 */
		// Start line: 2408
	/* end block 2 */
	// End Line: 2409

void Impact_Smoke(undefined pos,short mode)

{
  short sVar1;
  TASK *pTVar2;
  undefined3 in_register_00000011;
  undefined2 *puVar3;
  
  puVar3 = (undefined2 *)CONCAT31(in_register_00000011,pos);
  sVar1 = Impact_Clipped(pos);
  if (sVar1 == 0) {
    pTVar2 = Task_Add(Impact_SmokeTask,0x56c);
    *(undefined2 *)&pTVar2[1].prec = 1;
    *(short *)((int)&pTVar2[1].prec + 2) = mode;
    *(undefined2 *)&pTVar2[1].child = *puVar3;
    *(undefined2 *)((int)&pTVar2[1].child + 2) = puVar3[1];
    *(undefined2 *)&pTVar2[1].bprec = puVar3[2];
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Impact_SmokeTask()
 // line 897, offset 0x8006754c
	/* begin block 1 */
		// Start line: 898
		// Start offset: 0x8006754C
		// Variables:
	// 		struct _WCIRC *circle; // $s0
	// 		short i; // $s1
	// 		short borne; // $v1
	// 		struct WEATHER_7fake pos; // stack offset -24
	/* end block 1 */
	// End offset: 0x80067654
	// End Line: 924

	/* begin block 2 */
		// Start line: 2444
	/* end block 2 */
	// End Line: 2445

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Impact_SmokeTask(void)

{
  char cVar1;
  TASK *pTVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  
  pTVar2 = TaskCurrent;
  sVar3 = Impact_InitSmoke();
  if (sVar3 != 0) {
    iVar4 = 0x1e;
    if (*(short *)((int)&pTVar2[1].prec + 2) != 0) {
      iVar4 = 0x20;
    }
    iVar5 = 0;
    if (iVar4 != 0) {
      do {
        if (*(short *)((int)&pTVar2[1].prec + 2) == 0) {
          *(short *)&pTVar2[1].bprec = *(short *)&pTVar2[1].bprec + 3;
          cVar1 = (char)((uint)(iVar5 << 0x10) >> 0x18);
          *(char *)((int)&pTVar2[1].next + 3) =
               ((char)(((iVar5 << 0x10) >> 0x10) / 5) + ((cVar1 >> 0x10) >> 7)) - (cVar1 >> 7);
        }
        else {
          sVar3 = *(short *)&pTVar2[1].bprec;
          *(undefined *)((int)&pTVar2[1].next + 3) =
               (char)((int)(((iVar5 << 0x10) >> 0x10) + ((uint)(iVar5 << 0x10) >> 0x1f)) >> 1);
          *(short *)&pTVar2[1].bprec = sVar3 + 2;
        }
        Task_Next();
        iVar5 = iVar5 + 1;
      } while (iVar5 * 0x10000 >> 0x10 < iVar4);
    }
    Task_Sleep(2);
  }
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ Impact_InitSmoke()
 // line 927, offset 0x8006766c
	/* begin block 1 */
		// Start line: 929
		// Start offset: 0x8006766C
		// Variables:
	// 		struct _WCIRC *circ; // $a0
	// 		struct WEATHER_71fake *list; // $v1
	/* end block 1 */
	// End offset: 0x800676C4
	// End Line: 945

	/* begin block 2 */
		// Start line: 2521
	/* end block 2 */
	// End Line: 2522

/* WARNING: Unknown calling convention yet parameter storage is locked */

short Impact_InitSmoke(void)

{
  TASK *pTVar1;
  TASK *pTVar2;
  undefined2 uVar3;
  
  pTVar1 = TaskCurrent;
  *(undefined *)((int)&TaskCurrent[1].next + 2) = 0x19;
  *(undefined *)((int)&pTVar1[1].next + 3) = 0;
  *(undefined *)((int)&pTVar1[1].father + 3) = 0xff;
  *(void **)&pTVar1[7].event_s0 = Effects_Pcl;
  pTVar1[7].event_s2 = 0;
  *(undefined2 *)&pTVar1[7].event_s3 = 1;
  if (*(short *)((int)&pTVar1[1].prec + 2) == 0) {
    uVar3 = 0x9b;
  }
  else {
    uVar3 = 0x65;
  }
  *(undefined2 *)&pTVar1[1].next = uVar3;
  pTVar2 = TaskCurrent;
  *(ushort *)((int)&pTVar1[1].bprec + 2) = *(short *)&pTVar1[1].next << 8 | 0x19;
  pTVar2->display = Impact_DisplayShape;
  return 1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Impact_Heat(struct WEATHER_7fake *pos /*$s0*/)
 // line 960, offset 0x800676f0
	/* begin block 1 */
		// Start line: 961
		// Start offset: 0x800676F0
		// Variables:
	// 		struct _WCIRC *heat; // $v0
	/* end block 1 */
	// End offset: 0x80067748
	// End Line: 974

	/* begin block 2 */
		// Start line: 2599
	/* end block 2 */
	// End Line: 2600

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Impact_Heat(undefined pos)

{
  short sVar1;
  TASK *pTVar2;
  undefined3 in_register_00000011;
  undefined2 *puVar3;
  
  puVar3 = (undefined2 *)CONCAT31(in_register_00000011,pos);
  sVar1 = Impact_Clipped(pos);
  if (sVar1 == 0) {
    pTVar2 = Task_Add(Impact_HeatTask,0x56c);
    *(undefined2 *)&pTVar2[1].prec = 1;
    *(undefined2 *)&pTVar2[1].child = *puVar3;
    *(undefined2 *)((int)&pTVar2[1].child + 2) = puVar3[1];
    *(undefined2 *)&pTVar2[1].bprec = puVar3[2];
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Impact_HeatTask()
 // line 976, offset 0x80067758
	/* begin block 1 */
		// Start line: 977
		// Start offset: 0x80067758
		// Variables:
	// 		long i; // $s0
	// 		short nbf; // $v0
	// 		struct WEATHER_8fake col; // stack offset -16
	/* end block 1 */
	// End offset: 0x80067814
	// End Line: 1007

	/* begin block 2 */
		// Start line: 2631
	/* end block 2 */
	// End Line: 2632

/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Impact_HeatTask(void)

{
  int iVar1;
  undefined4 local_10;
  
  local_10 = PTR_DAT_800ad730;
  iVar1 = 10;
  Impact_InitHeat();
  do {
    iVar1 = iVar1 + -1;
    Task_Next();
  } while (iVar1 != 0);
  iVar1 = 100;
  do {
    if ((byte)local_10 < 4) {
      local_10 = (undefined *)((uint)local_10 & 0xffffff00);
    }
    else {
      local_10 = (undefined *)((uint)local_10 & 0xffffff00 | (uint)(byte)((byte)local_10 - 3));
    }
    if (local_10._1_1_ < 3) {
      local_10 = (undefined *)((uint)local_10 & 0xffff00ff);
    }
    else {
      local_10._0_2_ = CONCAT11(local_10._1_1_ - 2,(byte)local_10);
      local_10 = (undefined *)((uint)local_10 & 0xffff0000 | (uint)(ushort)local_10);
    }
    if (local_10._2_1_ < 2) {
      local_10 = (undefined *)((uint)local_10 & 0xff00ffff);
    }
    else {
      local_10._0_3_ = CONCAT12(local_10._2_1_ - 1,(ushort)local_10);
      local_10 = (undefined *)(uint)(uint3)local_10;
    }
    iVar1 = iVar1 + -1;
    Task_Next();
  } while (iVar1 != 0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Impact_InitHeat()
 // line 1009, offset 0x80067824
	/* begin block 1 */
		// Start line: 1011
		// Start offset: 0x80067824
		// Variables:
	// 		struct _WCIRC *circ; // $v1
	// 		struct WEATHER_71fake *list; // $a0
	/* end block 1 */
	// End offset: 0x80067824
	// End Line: 1011

	/* begin block 2 */
		// Start line: 2717
	/* end block 2 */
	// End Line: 2718

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Impact_InitHeat(void)

{
  void *pvVar1;
  TASK *pTVar2;
  
  pTVar2 = TaskCurrent;
  *(undefined *)((int)&TaskCurrent[1].next + 3) = 0;
  pvVar1 = Pl_Pcl;
  *(undefined2 *)&pTVar2[1].next = 0x3f;
  *(void **)&pTVar2[7].event_s0 = pvVar1;
  *(undefined2 *)&pTVar2[7].event_s3 = 1;
  pTVar2[7].event_s2 = 0;
  *(undefined2 *)((int)&pTVar2[1].bprec + 2) = 0x3d19;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Impact_Stone(struct WEATHER_7fake *pos /*$s1*/, short nb_part /*$a1*/)
 // line 1033, offset 0x80067864
	/* begin block 1 */
		// Start line: 1034
		// Start offset: 0x80067864
		// Variables:
	// 		struct WEATHER_118fake *t; // $s0
	/* end block 1 */
	// End offset: 0x8006790C
	// End Line: 1059

	/* begin block 2 */
		// Start line: 2779
	/* end block 2 */
	// End Line: 2780

void Impact_Stone(undefined pos,short nb_part)

{
  short sVar1;
  SFX_118fake *ex;
  undefined3 in_register_00000011;
  short *psVar2;
  
  psVar2 = (short *)CONCAT31(in_register_00000011,pos);
  sVar1 = Impact_Clipped(pos);
  if (sVar1 == 0) {
    ex = (SFX_118fake *)Task_Add(SFX_ExplosionTask,0x784);
    (ex->obj).pos.vx = *psVar2;
    (ex->obj).pos.vy = psVar2[1];
    sVar1 = psVar2[2];
    *(undefined2 *)(ex[1].type + 4) = 10;
    *(undefined2 *)(ex[1].type + 6) = 0x32;
    (ex->t).local = (void *)0x0;
    (ex->obj).pos.vz = sVar1;
    Fx_Play(0x36,(char)ex + -0x44);
    SFX04_Init(ex,(int)nb_part,0xd4,0xff000c);
    SFX_D3ShakeScreen(&ex->obj,(_D3_OBJECT *)&Player,0x3c,10);
  }
  return;
}





