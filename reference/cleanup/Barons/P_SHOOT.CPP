#include "THISDUST.H"
#include "P_SHOOT.H"


// decompiled code
// original method signature: 
// void /*$ra*/ PGrenade_Add(struct _PLAYER *pl /*$s1*/, long speed /*$s4*/)
 // line 130, offset 0x8003dee8
	/* begin block 1 */
		// Start line: 131
		// Start offset: 0x8003DEE8
		// Variables:
	// 		struct P_SHOOT_7fake pos; // stack offset -40
	// 		struct P_SHOOT_7fake rot; // stack offset -32
	// 		long rc; // $s0
	// 		long rs; // $a3
	// 		long tx; // $a0
	// 		long ty; // $v1
	// 		long tz; // $t0
	/* end block 1 */
	// End offset: 0x8003E0C4
	// End Line: 170

	/* begin block 2 */
		// Start line: 260
	/* end block 2 */
	// End Line: 261

void PGrenade_Add(_PLAYER *pl,long speed)

{
  short local_1c;
  
  local_1c = (short)*(undefined4 *)&(pl->obj).rot.vz;
  rcos((int)local_1c);
  rsin((int)local_1c);
  if ((&Pl_LeftWeapons)[(int)(char)(pl->env1).Obj.primitive_top.Data[0x18]] == 5) {
    SHPG1_Init(pl,0xd8,0xe0,speed);
  }
  else {
    if ((&Pl_LeftWeapons)[(int)(char)(pl->env1).Obj.primitive_top.Data[0x18]] == 6) {
      SHPG2_Init(pl,0xd8,0xe0);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PShoot_Add(struct _PLAYER *pl /*$s0*/)
 // line 173, offset 0x8003e0e4
	/* begin block 1 */
		// Start line: 174
		// Start offset: 0x8003E0E4
		// Variables:
	// 		struct P_SHOOT_7fake pos; // stack offset -32
	// 		struct P_SHOOT_7fake rot; // stack offset -24
	// 		long ammo; // $s1
	/* end block 1 */
	// End offset: 0x8003E204
	// End Line: 203

	/* begin block 2 */
		// Start line: 366
	/* end block 2 */
	// End Line: 367

void PShoot_Add(_PLAYER *pl)

{
  TASK *t;
  short sVar1;
  int iVar2;
  _D3_OBJECT **pp_Var3;
  int iVar4;
  
  PShoot_GetPos(pl,0xe0);
  iVar2 = (int)(char)(pl->env1).Obj.primitive_top.Data[0x19];
  iVar4 = 1;
  if (iVar2 == 1) {
    SHPF_Add(pl,0xe0,0xe8);
  }
  else {
    if (iVar2 < 2) {
      if (iVar2 != 0) goto LAB_8003e1c4;
      SHPL_Add(pl,0xe0,0xe8);
      iVar4 = 2;
    }
    else {
      if (iVar2 == 2) {
        SHPE_Add(pl,0xe0,0xe8);
      }
      else {
        if (iVar2 == 3) {
          SHPA_Add(pl,0xe0,0xe8);
          iVar4 = 10;
        }
      }
    }
  }
  iVar2 = (int)(char)(pl->env1).Obj.primitive_top.Data[0x19];
LAB_8003e1c4:
  t = Overlay_Handle;
  if (iVar2 != 4) {
    pp_Var3 = &(pl->obj).next + iVar2 * 2;
    sVar1 = *(short *)((int)pp_Var3 + 0x1aa) - (short)iVar4;
    if ((int)*(short *)((int)pp_Var3 + 0x1aa) - iVar4 < 0) {
      sVar1 = 0;
    }
    *(short *)((int)pp_Var3 + 0x1aa) = sVar1;
    Task_EventExec(t,t->event_msg | 8,t->event_param);
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ PShoot_GetPos(struct _PLAYER *pl /*$s7*/, struct P_SHOOT_7fake *pos /*$s3*/)
 // line 206, offset 0x8003e218
	/* begin block 1 */
		// Start line: 207
		// Start offset: 0x8003E218
		// Variables:
	// 		long tx; // $s4
	// 		long ty; // $s5
	// 		long tz; // $s6
	// 		long lx; // $s2
	// 		short r; // $s1
	/* end block 1 */
	// End offset: 0x8003E40C
	// End Line: 253

	/* begin block 2 */
		// Start line: 439
	/* end block 2 */
	// End Line: 440

/* WARNING: Type propagation algorithm not settling */

long PShoot_GetPos(_PLAYER *pl,undefined pos)

{
  ushort uVar1;
  ushort uVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  undefined3 in_register_00000015;
  short *psVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  short sVar11;
  
  psVar6 = (short *)CONCAT31(in_register_00000015,pos);
  sVar11 = *(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x16);
  if (sVar11 == 0x55) {
    iVar9 = 8;
    iVar10 = -10;
    sVar11 = 0x92;
    iVar8 = 100;
  }
  else {
    if (sVar11 < 0x56) {
      if (sVar11 != 0x54) {
        return 0;
      }
      iVar9 = 0x15;
      iVar10 = -3;
      sVar11 = 0x9e;
      iVar8 = 0x5a;
    }
    else {
      if (sVar11 == 0x56) {
        iVar9 = 0xb;
        iVar10 = -0x1e;
        sVar11 = 0x96;
        iVar8 = 0x67;
      }
      else {
        if (sVar11 != 0x57) {
          return 0;
        }
        iVar9 = 0x26;
        iVar10 = -0xd;
        sVar11 = 0x4e;
        iVar8 = 0x76;
      }
    }
  }
  uVar1 = (pl->obj).rot.vz;
  uVar2 = *(ushort *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x26);
  iVar4 = rcos((int)(short)uVar1);
  iVar5 = rsin((int)(short)uVar1);
  *psVar6 = (pl->obj).pos.vx;
  psVar6[1] = (pl->obj).pos.vy;
  sVar3 = (pl->obj).pos.vz;
  psVar6[2] = sVar3;
  psVar6[2] = sVar3 + sVar11;
  *psVar6 = *psVar6 + (short)((int)(short)iVar4 * iVar9 - (int)(short)iVar5 * iVar10 >> 0xc);
  psVar6[1] = psVar6[1] + (short)((int)(short)iVar5 * iVar9 + (int)(short)iVar4 * iVar10 >> 0xc);
  iVar9 = rsin((int)*(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x24));
  psVar6[2] = psVar6[2] + (short)(iVar9 * iVar8 >> 0xc);
  uVar7 = (int)(((uint)uVar1 + (uint)uVar2) * 0x10000) >> 0x10;
  iVar9 = rcos((int)*(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x24));
  iVar9 = iVar9 * iVar8 >> 0xc;
  iVar8 = rcos(uVar7);
  *psVar6 = *psVar6 + (short)(iVar8 * iVar9 >> 0xc);
  iVar8 = rsin(uVar7);
  psVar6[1] = psVar6[1] + (short)(iVar8 * iVar9 >> 0xc);
  return 1;
}



// decompiled code
// original method signature: 
// struct P_SHOOT_143fake * /*$ra*/ PShoot_Init(struct _PLAYER *pl /*$s2*/, struct P_SHOOT_7fake *pos /*$s4*/, struct P_SHOOT_7fake *rot /*$s5*/, short type /*$s3*/, TDRFuncPtr_PShoot_Init4f_move f_move /*stack 16*/, TDRFuncPtr_PShoot_Init5f_impact f_impact /*stack 20*/, TDRFuncPtr_PShoot_Init6f_display f_display /*stack 24*/, TDRFuncPtr_PShoot_Init7f_destructor f_destructor /*stack 28*/)
 // line 256, offset 0x8003e438
	/* begin block 1 */
		// Start line: 257
		// Start offset: 0x8003E438
		// Variables:
	// 		struct TASK *t; // $s1
	// 		struct P_SHOOT_143fake *sh; // $s0
	// 		long s; // $a1
	/* end block 1 */
	// End offset: 0x8003E4C8
	// End Line: 273

	/* begin block 2 */
		// Start line: 561
	/* end block 2 */
	// End Line: 562

P_SHOOT_143fake *
PShoot_Init(_PLAYER *pl,undefined pos,undefined rot,short type,TDRFuncPtr_PShoot_Init4f_move f_move,
           TDRFuncPtr_PShoot_Init5f_impact f_impact,TDRFuncPtr_PShoot_Init6f_display f_display,
           TDRFuncPtr_PShoot_Init7f_destructor f_destructor)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  TASK *pTVar4;
  undefined3 in_register_00000015;
  int iVar5;
  undefined3 in_register_00000019;
  long lVar6;
  P_SHOOT_143fake *obj;
  
  switch((int)(((uint)(ushort)type + 0x13) * 0x10000) >> 0x10) {
  case 0:
    iVar5 = 0x210;
    break;
  default:
    iVar5 = 0x400;
    break;
  case 9:
    iVar5 = 0x5f0;
    break;
  case 10:
    iVar5 = 0x734;
    break;
  case 0xb:
    iVar5 = 0x3b4;
    break;
  case 0xc:
    iVar5 = 800;
  }
  pTVar4 = Task_Link(PShoot_Task,iVar5 + 0xe4);
  obj = (P_SHOOT_143fake *)(pTVar4 + 1);
  pTVar4[1].bnext = pTVar4;
  *(_PLAYER **)&pTVar4[2].bnext = pl;
  D3_InsertObject((_D3_OBJECT *)obj,&Pvl_PlayerShots);
  bVar1 = (pl->env1).Obj.primitive_top.Data[0x19];
  *(undefined *)((int)&pTVar4[2].father + 1) = (char)type;
  *(_PLAYER **)&pTVar4[2].bprec = pl;
  *(short *)((int)&pTVar4[2].s7 + 2) = (short)(char)bVar1;
  D3_ClearCollBits((_D3_OBJECT *)obj,0xffff);
  *(undefined2 *)((int)&pTVar4[1].sp + 2) = 0;
  lVar6 = ((long *)CONCAT31(in_register_00000015,pos))[1];
  pTVar4[1].s0 = *(long *)CONCAT31(in_register_00000015,pos);
  pTVar4[1].s1 = lVar6;
  lVar6 = ((long *)CONCAT31(in_register_00000019,rot))[1];
  pTVar4[1].s4 = *(long *)CONCAT31(in_register_00000019,rot);
  pTVar4[1].s5 = lVar6;
  *(short *)&pTVar4[1].s2 = (pl->obj).pos.vx;
  *(short *)((int)&pTVar4[1].s2 + 2) = (pl->obj).pos.vy;
  sVar2 = (pl->obj).pos.vz;
  uVar3 = (pl->m_obj).Sq.Header.Version;
  *(TDRFuncPtr_PShoot_Init4f_move *)&pTVar4[2].fp = f_move;
  *(ushort *)&pTVar4[1].s3 = sVar2 + uVar3 + -1;
  *(TDRFuncPtr_PShoot_Init5f_impact *)&pTVar4[2].text_context = f_impact;
  *(TDRFuncPtr_PShoot_Init6f_display *)&pTVar4->display = f_display;
  *(TDRFuncPtr_PShoot_Init7f_destructor *)&pTVar4->destructor = f_destructor;
  return obj;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PShoot_Destructor(struct TASK *t /*$a0*/)
 // line 308, offset 0x8003e5dc
	/* begin block 1 */
		// Start line: 309
		// Start offset: 0x8003E5DC
		// Variables:
	// 		struct P_SHOOT_143fake *sh; // $a0
	/* end block 1 */
	// End offset: 0x8003E5DC
	// End Line: 309

	/* begin block 2 */
		// Start line: 704
	/* end block 2 */
	// End Line: 705

void PShoot_Destructor(TASK *t)

{
  t[1].bnext = (TASK *)0x0;
  D3_DeleteObject((_D3_OBJECT *)(t + 1));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PShoot_Task()
 // line 317, offset 0x8003e600
	/* begin block 1 */
		// Start line: 318
		// Start offset: 0x8003E600
		// Variables:
	// 		struct P_SHOOT_143fake *sh; // $s0
	/* end block 1 */
	// End offset: 0x8003E6C8
	// End Line: 346

	/* begin block 2 */
		// Start line: 724
	/* end block 2 */
	// End Line: 725

/* WARNING: Unknown calling convention yet parameter storage is locked */

void PShoot_Task(void)

{
  short sVar1;
  TASK *pTVar2;
  uint uVar3;
  
  pTVar2 = TaskCurrent;
  while( true ) {
    sVar1 = *(short *)&pTVar2[2].s7;
    if ((*(short *)&pTVar2[2].s7 != 0) && (*(short *)&pTVar2[2].s7 = sVar1 + -1, sVar1 == 1))
    goto LAB_8003e680;
    uVar3 = (*(code *)pTVar2[2].fp)();
    if ((uVar3 & 0xffff) != 0) break;
    Task_Next();
  }
  if (pTVar2[2].text_context != (TEXTCONTEXT *)0x0) {
    (*(code *)pTVar2[2].text_context)();
  }
LAB_8003e680:
  if ((uint)*(ushort *)((int)&pTVar2[2].s7 + 2) - 1 < 2) {
    *(undefined2 *)&pTVar2[8].display = 1;
    while (uVar3 = (*(code *)pTVar2[2].fp)(), (uVar3 & 0xffff) == 0) {
      Task_Next();
    }
  }
  TaskCurrent->display = (_func_11 *)0x0;
  Task_Sleep(2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SHPL_Add(struct _PLAYER *pl /*$s1*/, struct P_SHOOT_7fake *pos /*$s2*/, struct P_SHOOT_7fake *rot /*$a2*/)
 // line 369, offset 0x8003e6ec
	/* begin block 1 */
		// Start line: 370
		// Start offset: 0x8003E6EC
		// Variables:
	// 		struct P_SHOOT_7fake rotr; // stack offset -24
	/* end block 1 */
	// End offset: 0x8003E860
	// End Line: 405

	/* begin block 2 */
		// Start line: 828
	/* end block 2 */
	// End Line: 829

void SHPL_Add(_PLAYER *pl,undefined1 pos,undefined1 rot)

{
  uint uVar1;
  int iVar2;
  
  if ((char)(pl->env1).Obj.primitive_top.Data
            [(int)(char)(pl->env1).Obj.primitive_top.Data[0x19] * 8 + 0x1c] < '\b') {
    SHPL1_Init(pl,pos,0xe8);
  }
  else {
    SHPL1_Init(pl,pos,0xe8);
    SHPL1_Init(pl,pos,0xe8);
  }
  uVar1 = (uint)(pl->env1).Obj.primitive_top.Data
                [(int)(char)(pl->env1).Obj.primitive_top.Data[0x19] * 8 + 0x1c] << 0x18;
  iVar2 = (int)(((int)uVar1 >> 0x18) + (uVar1 >> 0x1f)) >> 1;
  if (iVar2 != 3) {
    if (iVar2 < 4) {
      if (iVar2 != 2) {
        return;
      }
      goto LAB_8003e858;
    }
    if (iVar2 != 4) {
      return;
    }
  }
  SHPL2_Init(pl,pos,0xe8);
LAB_8003e858:
  SHPL2_Init(pl,pos,0xe8);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SHPL1_Init(struct _PLAYER *pl /*$s1*/, struct P_SHOOT_7fake *pos /*$a1*/, struct P_SHOOT_7fake *rot /*$a2*/)
 // line 408, offset 0x8003e878
	/* begin block 1 */
		// Start line: 409
		// Start offset: 0x8003E878
		// Variables:
	// 		short i; // $a0
	// 		struct P_SHOOT_143fake *sh; // $s0
	/* end block 1 */
	// End offset: 0x8003E9E4
	// End Line: 447

	/* begin block 2 */
		// Start line: 920
	/* end block 2 */
	// End Line: 921

void SHPL1_Init(_PLAYER *pl,undefined1 pos,undefined1 rot)

{
  byte bVar1;
  void *pvVar2;
  P_SHOOT_143fake *pPVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  short Fx;
  int iVar7;
  undefined4 uVar8;
  
  pPVar3 = PShoot_Init(pl,pos,rot,-7,SHPL1_Move,SHPL1_Impact,SHPL1_Display,PShoot_Destructor);
  uVar4 = M_rand();
  Fx = 0x25;
  if ((uVar4 & 1) != 0) {
    Fx = 0x24;
  }
  Fx_Play(Fx,(char)pl + ',');
  Impact_Smoke((char)pPVar3 + ',',0);
  iVar5 = rcos((int)(pPVar3->obj).rot.vz);
  Fx = (pPVar3->obj).rot.vz;
  *(int *)(pPVar3->t + 0x18) = iVar5 * 10 >> 9;
  iVar5 = rsin((int)Fx);
  Fx = (pPVar3->obj).rot.vx;
  *(int *)(pPVar3->t + 0x1c) = iVar5 * 10 >> 9;
  iVar5 = rsin((int)Fx);
  iVar7 = 0;
  *(int *)(pPVar3->t + 0x20) = iVar5 * 10 >> 9;
  do {
    uVar4 = 0xe1000000;
    iVar5 = (int)&(pPVar3->obj).next + ((iVar7 << 0x10) >> 0xd);
    *(undefined *)(iVar5 + 0xe7) = 1;
    if (Scr_Dtd != 0) {
      uVar4 = 0xe1000200;
    }
    uVar6 = uVar4 | 0x420;
    if (Scr_Dfe == 0) {
      uVar6 = uVar4 | 0x20;
    }
    *(uint *)(iVar5 + 0xe8) = uVar6;
    iVar7 = iVar7 + 1;
  } while (iVar7 * 0x10000 >> 0x10 < 2);
  Fx = 0xc;
  if ('\x01' < (char)(pl->env1).Obj.primitive_top.Data
                     [(int)(char)(pl->env1).Obj.primitive_top.Data[0x19] * 8 + 0x1c]) {
    Fx = 0x19;
  }
  *(short **)pPVar3->t = &pPVar3[1].obj.index;
  *(_struct_241 **)&pPVar3->impact = &(pPVar3->obj).pos;
  (pPVar3->obj).pos.pad = Fx + 0x2800;
  pvVar2 = Pl_Pcl;
  *(undefined2 *)(pPVar3->t + 4) = 1;
  *(undefined4 *)&pPVar3[1].obj.index = 0x808080;
  pPVar3->move = pvVar2;
  bVar1 = (pl->env1).Obj.primitive_top.Data
          [(int)(char)(pl->env1).Obj.primitive_top.Data[0x19] * 8 + 0x1c];
  (pPVar3->obj).collision_mode = 0x23;
  (pPVar3->obj).hit_power = bVar1 * '\x05' + '\n';
  uVar8 = *(undefined4 *)&(pPVar3->obj).pos.vz;
  *(undefined4 *)&pPVar3[1].obj.collision_mode = *(undefined4 *)&(pPVar3->obj).pos;
  *(undefined4 *)&pPVar3[1].obj.hit_points = uVar8;
  *(undefined2 *)&pPVar3[1].obj.description = 1;
  *(undefined2 *)((int)&pPVar3[1].obj.description + 2) = 0;
  *(undefined2 *)(pPVar3->t + 0x28) = 0x32;
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ SHPL1_Move()
 // line 462, offset 0x8003ea8c
	/* begin block 1 */
		// Start line: 463
		// Start offset: 0x8003EA8C
		// Variables:
	// 		struct P_SHOOT_143fake *sh; // $s0
	// 		long l; // $v1

		/* begin block 1.1 */
			// Start line: 487
			// Start offset: 0x8003EB68
			// Variables:
		// 		struct P_SHOOT_7fake ns; // stack offset -24
		/* end block 1.1 */
		// End offset: 0x8003EC54
		// End Line: 518
	/* end block 1 */
	// End offset: 0x8003EC68
	// End Line: 527

	/* begin block 2 */
		// Start line: 1059
	/* end block 2 */
	// End Line: 1060

/* WARNING: Unknown calling convention yet parameter storage is locked */

short SHPL1_Move(void)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  TASK *pTVar4;
  short sVar5;
  long lVar6;
  _func_13 *p_Var7;
  short sVar8;
  uint uVar9;
  undefined uVar10;
  TASK *ot;
  
  pTVar4 = TaskCurrent;
  ot = TaskCurrent + 1;
  sVar5 = *(short *)&TaskCurrent[2].s4;
  sVar8 = *(short *)&TaskCurrent[2].s5;
  *(short *)&TaskCurrent[1].s0 = *(short *)&TaskCurrent[1].s0 + *(short *)&TaskCurrent[2].s3;
  sVar2 = *(short *)&pTVar4[1].s1;
  *(short *)((int)&pTVar4[1].s0 + 2) = *(short *)((int)&pTVar4[1].s0 + 2) + sVar5;
  sVar5 = *(short *)((int)&pTVar4[2].s7 + 2);
  *(short *)&pTVar4[1].s1 = sVar2 + sVar8;
  sVar8 = 0x2c;
  if ('\x01' < *(char *)(&pTVar4[2].bnext[2].event_fp + (int)sVar5 * 2)) {
    sVar8 = 0x22;
  }
  if (*(short *)&pTVar4[2].s7 < sVar8) {
    sVar5 = *(short *)&pTVar4[2].s5;
    *(short *)&pTVar4[2].event_ra = *(short *)&pTVar4[2].event_ra + *(short *)&pTVar4[2].s3;
    sVar8 = *(short *)&pTVar4[2].event_s0;
    *(short *)((int)&pTVar4[2].event_ra + 2) =
         *(short *)((int)&pTVar4[2].event_ra + 2) + *(short *)&pTVar4[2].s4;
    *(short *)&pTVar4[2].event_s0 = sVar8 + sVar5;
  }
  lVar6 = Boxes_TestObject((_D3_OBJECT *)ot);
  if (lVar6 == 0) {
LAB_8003ec60:
    *(undefined2 *)&pTVar4[2].event_s1 = 0;
    sVar5 = 0;
  }
  else {
    uVar3 = *(ushort *)((int)&pTVar4[1].sp + 2);
    if ((uVar3 & 2) != 0) {
      sVar5 = *(short *)((int)&pTVar4[2].event_s1 + 2);
      *(ushort *)((int)&pTVar4[1].sp + 2) = uVar3 & 0xfffd;
      sVar5 = sVar5 + 1;
      *(short *)((int)&pTVar4[2].event_s1 + 2) = sVar5;
      if (sVar5 < 3) {
        sVar5 = *(short *)&pTVar4[2].s3;
        sVar8 = *(short *)&pTVar4[2].s4;
        sVar2 = *(short *)&pTVar4[2].s5;
        Boxes_BounceObject(0xe8);
        pTVar4[2].s3 = (int)sVar5;
        pTVar4[2].s4 = (int)sVar8;
        *(short *)&pTVar4[1].s1 = *(short *)&pTVar4[1].s1 + -0x19;
        pTVar4[2].s5 = (int)sVar2;
        lVar6 = pTVar4[1].s1;
        pTVar4[2].event_ra = pTVar4[1].s0;
        pTVar4[2].event_s0 = lVar6;
        bVar1 = *(byte *)((int)&pTVar4[1].display + 2);
        *(undefined2 *)&pTVar4[2].s7 = 100;
        *(undefined *)((int)&pTVar4[2].father + 1) = 0xec;
        uVar9 = (uint)bVar1 << 1;
        uVar10 = 0xff;
        if (uVar9 < 0x100) {
          uVar10 = (char)uVar9;
        }
        sVar5 = *(short *)((int)&pTVar4[2].event_s1 + 2);
        *(undefined *)((int)&pTVar4[1].display + 2) = uVar10;
        if (sVar5 == 1) {
          p_Var7 = (_func_13 *)&DAT_002020ff;
        }
        else {
          p_Var7 = (_func_13 *)&DAT_0020ff20;
        }
        pTVar4[2].event_exec = p_Var7;
        D3_PlaySound((_D3_OBJECT *)pTVar4[2].prec,0);
        goto LAB_8003ec60;
      }
    }
    sVar5 = 1;
  }
  return sVar5;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SHPL1_Impact()
 // line 530, offset 0x8003ec7c
	/* begin block 1 */
		// Start line: 531
		// Start offset: 0x8003EC7C
		// Variables:
	// 		struct P_SHOOT_143fake *sh; // $s0
	/* end block 1 */
	// End offset: 0x8003ED84
	// End Line: 553

	/* begin block 2 */
		// Start line: 1215
	/* end block 2 */
	// End Line: 1216

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SHPL1_Impact(void)

{
  TASK *pTVar1;
  TASK *pTVar2;
  long lVar3;
  
  pTVar1 = TaskCurrent;
  if (*(short *)&TaskCurrent[2].event_s1 != 0) {
    lVar3 = TaskCurrent[2].event_s0;
    TaskCurrent[1].s0 = TaskCurrent[2].event_ra;
    pTVar1[1].s1 = lVar3;
  }
  pTVar2 = TaskCurrent;
  *(short *)((int)pTVar1[2].sp + 6) =
       (short)((ulonglong)
               ((longlong)(int)((uint)*(byte *)((int)pTVar1[2].sp + 6) << 3) * 0x2aaaaaab) >> 0x20)
       + 0x3100;
  pTVar2->display = (_func_11 *)0x0;
  while ((int)((uint)*(ushort *)((int)pTVar1[2].sp + 6) << 0x10) >> 0x18 < 0x3d) {
    Main_Prims = (void *)GtxShp_DisplayListLOFF
                                   (&pTVar1[2].exec,Main_Prims,Scr->ot,(int)Scr_OtSize,0xffffff6a,
                                    Main_TextContext.Font.ascii_tab._20_4_);
    Task_Next();
    *(short *)((int)pTVar1[2].sp + 6) = *(short *)((int)pTVar1[2].sp + 6) + 0x100;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SHPL1_Display()
 // line 560, offset 0x8003ed94
	/* begin block 1 */
		// Start line: 561
		// Start offset: 0x8003ED94
		// Variables:
	// 		struct P_SHOOT_143fake *sh; // $fp
	// 		struct P_SHOOT_32fake *g; // $s0
	// 		struct P_SHOOT_32fake *d; // $s2
	// 		struct P_SHOOT_7fake pos; // stack offset -72
	// 		struct P_SHOOT_8fake col; // stack offset -64
	// 		long z; // stack offset -52
	// 		long sxy0; // stack offset -44
	// 		long sxy2; // stack offset -56
	// 		long sxy; // stack offset -48
	/* end block 1 */
	// End offset: 0x8003F134
	// End Line: 678

	/* begin block 2 */
		// Start line: 1278
	/* end block 2 */
	// End Line: 1279

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SHPL1_Display(void)

{
  short sVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  void *pvVar5;
  TASK *pTVar6;
  _SCREEN *p_Var7;
  undefined4 in_zero;
  undefined4 in_at;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  TASK **ppTVar11;
  int iVar12;
  TASK *pTVar13;
  undefined4 local_48;
  uint local_44;
  
  pTVar6 = TaskCurrent;
  pvVar5 = Main_Prims;
  pTVar13 = TaskCurrent + 1;
  setCopReg(2,in_zero,TaskCurrent[2].event_ra);
  setCopReg(2,in_at,TaskCurrent[2].event_s0);
  copFunction(2,0x180001);
  uVar2 = getCopReg(2,0xe);
  iVar12 = getCopReg(2,0x9800);
  iVar12 = iVar12 >> 2;
  if ((iVar12 != 0) && (iVar12 < (int)Scr_OtSize)) {
    Main_Prims = (void *)((int)Main_Prims + 0x38);
    uVar8 = 0x800b0000;
    iVar9 = rcos((int)*(short *)&TaskCurrent[1].s5 + 0x400);
    sVar1 = *(short *)&pTVar6[1].s0;
    iVar10 = rsin((int)*(short *)&pTVar6[1].s5 + 0x400);
    local_48 = CONCAT22(*(short *)((int)&pTVar6[1].s0 + 2) + (short)((iVar10 * 100) / 6 >> 0xc),
                        sVar1 + (short)((iVar9 * 100) / 6 >> 0xc));
    local_44 = local_44 & 0xffff0000 | (uint)*(ushort *)&pTVar6[1].s1;
    setCopReg(2,in_zero,local_48);
    setCopReg(2,uVar8,local_44);
    copFunction(2,0x180001);
    uVar3 = getCopReg(2,0xe);
    setCopReg(2,in_zero,pTVar6[1].s0);
    setCopReg(2,uVar8,pTVar6[1].s1);
    copFunction(2,0x180001);
    uVar4 = getCopReg(2,0xe);
    *(undefined4 *)((int)pvVar5 + 0x10) = uVar3;
    *(undefined4 *)((int)pvVar5 + 8) = uVar4;
    *(undefined *)((int)pvVar5 + 3) = 6;
    *(undefined *)((int)pvVar5 + 7) = 0x32;
    *(undefined *)((int)pvVar5 + 4) = 0xff;
    *(undefined *)((int)pvVar5 + 5) = 0xff;
    *(undefined *)((int)pvVar5 + 6) = 0xff;
    *(undefined *)((int)pvVar5 + 0xc) = 0x10;
    *(undefined *)((int)pvVar5 + 0xd) = 0x10;
    *(undefined *)((int)pvVar5 + 0xe) = 0x80;
    *(undefined *)((int)pvVar5 + 0x14) = 0x10;
    *(undefined *)((int)pvVar5 + 0x15) = 0x10;
    *(undefined *)((int)pvVar5 + 0x16) = 0x10;
    *(undefined4 *)((int)pvVar5 + 0x18) = uVar2;
    iVar9 = rcos((int)*(short *)&pTVar6[1].s5 - 0x400);
    sVar1 = *(short *)&pTVar6[1].s0;
    iVar10 = rsin((int)*(short *)&pTVar6[1].s5 - 0x400);
    local_48 = CONCAT22(*(short *)((int)&pTVar6[1].s0 + 2) + (short)((iVar10 * 100) / 6 >> 0xc),
                        sVar1 + (short)((iVar9 * 100) / 6 >> 0xc));
    setCopReg(2,in_zero,local_48);
    setCopReg(2,uVar8,local_44);
    copFunction(2,0x180001);
    uVar3 = getCopReg(2,0xe);
    *(undefined4 *)((int)pvVar5 + 0x2c) = uVar3;
    *(undefined4 *)((int)pvVar5 + 0x24) = uVar4;
    *(undefined *)((int)pvVar5 + 0x1f) = 6;
    *(undefined *)((int)pvVar5 + 0x23) = 0x32;
    *(undefined *)((int)pvVar5 + 0x20) = 0xff;
    *(undefined *)((int)pvVar5 + 0x21) = 0xff;
    *(undefined *)((int)pvVar5 + 0x22) = 0xff;
    *(undefined4 *)((int)pvVar5 + 0x34) = uVar2;
    *(undefined *)((int)pvVar5 + 0xc) = 0x10;
    *(undefined *)((int)pvVar5 + 0xd) = 0x10;
    *(undefined *)((int)pvVar5 + 0xe) = 0x80;
    *(undefined *)((int)pvVar5 + 0x30) = 0x10;
    *(undefined *)((int)pvVar5 + 0x31) = 0x10;
    *(undefined *)((int)pvVar5 + 0x32) = 0x10;
    p_Var7 = Scr;
    *(uint *)pvVar5 = *(uint *)pvVar5 & 0xff000000 | Scr->ot[iVar12] & 0xffffff;
    p_Var7->ot[iVar12] = p_Var7->ot[iVar12] & 0xff000000 | (uint)pvVar5 & 0xffffff;
    iVar9 = (int)Scr_Frame;
    *(uint *)((int)pvVar5 + 0x1c) =
         *(uint *)((int)pvVar5 + 0x1c) & 0xff000000 | p_Var7->ot[iVar12] & 0xffffff;
    ppTVar11 = &pTVar13->prec + iVar9 * 2;
    p_Var7->ot[iVar12] = p_Var7->ot[iVar12] & 0xff000000 | (int)pvVar5 + 0x1cU & 0xffffff;
    ppTVar11[0x39] = (TASK *)((uint)ppTVar11[0x39] & 0xff000000 | p_Var7->ot[iVar12] & 0xffffff);
    p_Var7->ot[iVar12] =
         p_Var7->ot[iVar12] & 0xff000000 | (uint)(&pTVar13[1].enable + iVar9 * 4) & 0xffffff;
  }
  Main_Prims = (void *)GtxShp_DisplayListLOFF
                                 (&pTVar6[2].exec,Main_Prims,Scr->ot,(int)Scr_OtSize,0,
                                  Main_TextContext.Font.ascii_tab._20_4_);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SHPL2_Init(struct _PLAYER *pl /*$s1*/, struct P_SHOOT_7fake *pos /*$a1*/, struct P_SHOOT_7fake *rot /*$a2*/)
 // line 684, offset 0x8003f1a0
	/* begin block 1 */
		// Start line: 685
		// Start offset: 0x8003F1A0
		// Variables:
	// 		long i; // $a3
	// 		long j; // $a2
	// 		struct P_SHOOT_55fake *t; // $a0
	// 		struct P_SHOOT_143fake *sh; // $s0
	// 		struct P_SHOOT_71fake *list; // $v1
	/* end block 1 */
	// End offset: 0x8003F354
	// End Line: 721

	/* begin block 2 */
		// Start line: 1619
	/* end block 2 */
	// End Line: 1620

void SHPL2_Init(_PLAYER *pl,undefined1 pos,undefined1 rot)

{
  byte bVar1;
  short sVar2;
  P_SHOOT_143fake *pPVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  P_SHOOT_143fake *pPVar8;
  int iVar9;
  int iVar10;
  _struct_5591 _Var11;
  
  pPVar3 = PShoot_Init(pl,pos,rot,-8,SHPL2_Move,SHPL2_Impact,SHPL2_Display,PShoot_Destructor);
  iVar4 = rcos((int)(pPVar3->obj).rot.vz);
  sVar2 = (pPVar3->obj).rot.vz;
  *(int *)(pPVar3->t + 0x18) = iVar4 * 0x50 >> 0xc;
  iVar4 = rsin((int)sVar2);
  sVar2 = (pPVar3->obj).rot.vx;
  *(int *)(pPVar3->t + 0x1c) = iVar4 * 0x50 >> 0xc;
  iVar4 = rsin((int)sVar2);
  iVar10 = 0;
  *(int *)(pPVar3->t + 0x20) = iVar4 * 10 >> 9;
  *(undefined4 *)(pPVar3[1].t + 8) = 0;
  do {
    iVar9 = 0;
    iVar4 = 0xe4;
    do {
      iVar7 = (int)&(pPVar3->obj).next + iVar10 * 8 + iVar4;
      *(undefined *)(iVar7 + 3) = 1;
      uVar6 = 0xe1000000;
      if (Scr_Dtd != 0) {
        uVar6 = 0xe1000200;
      }
      uVar5 = uVar6 | 0x420;
      if (Scr_Dfe == 0) {
        uVar5 = uVar6 | 0x20;
      }
      *(uint *)(iVar7 + 4) = uVar5;
      iVar9 = iVar9 + 1;
      iVar4 = iVar4 + 0x10;
    } while (iVar9 < 7);
    iVar10 = iVar10 + 1;
  } while (iVar10 < 2);
  iVar4 = 0;
  pPVar3->move = Pl_Pcl;
  *(undefined4 *)pPVar3->t = 0;
  *(_struct_241 **)&pPVar3->impact = &(pPVar3->obj).pos;
  (pPVar3->obj).pos.pad = 0x280c;
  *(undefined2 *)(pPVar3->t + 4) = 1;
  bVar1 = (pl->env1).Obj.primitive_top.Data
          [(int)(char)(pl->env1).Obj.primitive_top.Data[0x19] * 8 + 0x1c];
  (pPVar3->obj).collision_mode = 0x23;
  (pPVar3->obj).hit_power = (bVar1 - 4) * '\x05' + '\n';
  pPVar8 = pPVar3;
  do {
    _Var11 = *(_struct_5591 *)&(pPVar3->obj).pos.vz;
    *(undefined4 *)&pPVar8[1].list.pos.vz = *(undefined4 *)&(pPVar3->obj).pos;
    pPVar8[1].list.col = _Var11;
    iVar4 = iVar4 + 1;
    *(short *)&pPVar8[1].list.col.b = (pPVar3->obj).rot.vz;
    pPVar8 = (P_SHOOT_143fake *)&(pPVar8->obj).child;
  } while (iVar4 < 8);
  *(undefined2 *)(pPVar3->t + 0x28) = 0x32;
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ SHPL2_Move()
 // line 725, offset 0x8003f370
	/* begin block 1 */
		// Start line: 726
		// Start offset: 0x8003F370
		// Variables:
	// 		struct P_SHOOT_143fake *sh; // $s0
	// 		struct P_SHOOT_6fake vec; // stack offset -40
	// 		struct P_SHOOT_6fake vecsq; // stack offset -24
	// 		long d; // $v1
	// 		long sz; // $v1
	/* end block 1 */
	// End offset: 0x8003F57C
	// End Line: 764

	/* begin block 2 */
		// Start line: 1737
	/* end block 2 */
	// End Line: 1738

/* WARNING: Unknown calling convention yet parameter storage is locked */

short SHPL2_Move(void)

{
  short sVar1;
  short sVar2;
  short sVar3;
  TASK *pTVar4;
  _D3_OBJECT *p_Var5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  long lVar10;
  long lVar11;
  int iVar12;
  int x;
  int y;
  undefined4 in_t1;
  undefined4 in_t2;
  undefined4 in_t3;
  TASK *ot;
  
  pTVar4 = TaskCurrent;
  ot = TaskCurrent + 1;
  p_Var5 = D3_SeekDistTarget((_D3_OBJECT *)ot,600,0x10);
  *(_D3_OBJECT **)&pTVar4[3].event_s2 = p_Var5;
  if (p_Var5 == (_D3_OBJECT *)0x0) {
    lVar10 = M_rand();
    lVar11 = lVar10;
    if (lVar10 < 0) {
      lVar11 = lVar10 + 0xff;
    }
    iVar12 = (int)*(short *)&pTVar4[1].s5 + lVar10 + (lVar11 >> 8) * -0x100;
    y = iVar12 + 0xf80;
    x = y;
    if (y < 0) {
      x = iVar12 + 0x1f7f;
    }
    *(short *)&pTVar4[1].s5 = (short)y + (short)(x >> 0xc) * -0x1000;
  }
  else {
    uVar6 = (int)(p_Var5->b_box).vx + (int)*(short *)&p_Var5->b_step;
    uVar7 = (int)(p_Var5->b_box).vy + (int)*(short *)((int)&p_Var5->b_sunk + 2);
    uVar8 = (int)(p_Var5->b_box).vz + (int)*(short *)&p_Var5[1].prec;
    sVar1 = (p_Var5->pos).vz;
    x = ((int)(p_Var5->pos).vx + ((int)(uVar6 + (uVar6 >> 0x1f)) >> 1)) -
        (int)*(short *)&pTVar4[1].s0;
    y = ((int)(p_Var5->pos).vy + ((int)(uVar7 + (uVar7 >> 0x1f)) >> 1)) -
        (int)*(short *)((int)&pTVar4[1].s0 + 2);
    D3_GoToDir((_D3_OBJECT *)ot,x,y,0xc0);
    iVar9 = ((int)sVar1 + ((int)(uVar8 + (uVar8 >> 0x1f)) >> 1)) - (int)*(short *)&pTVar4[1].s1;
    setCopReg(2,in_t1,x);
    setCopReg(2,in_t2,y);
    setCopReg(2,in_t3,iVar9);
    copFunction(2,0xa00428);
    x = getCopReg(2,0x19);
    y = getCopReg(2,0x1a);
    iVar12 = getCopReg(2,0x1b);
    uVar6 = SquareRoot0(x + y + iVar12);
    if ((int)uVar6 < 1) {
      uVar6 = 1;
    }
    else {
      uVar6 = SquareRoot0(x + y + iVar12);
    }
    iVar9 = iVar9 * 0x100;
    if (uVar6 == 0) {
      trap(0x1c00);
    }
    if ((uVar6 == 0xffffffff) && (iVar9 == -0x80000000)) {
      trap(0x1800);
    }
    y = pTVar4[2].s5;
    x = (iVar9 / (int)uVar6) * 0x50 >> 8;
    if (y < x) {
      pTVar4[2].s5 = y + 8;
    }
    else {
      if (x < y) {
        pTVar4[2].s5 = y + -8;
      }
    }
  }
  x = rcos((int)*(short *)&pTVar4[1].s5);
  sVar1 = *(short *)&pTVar4[1].s5;
  pTVar4[2].s3 = x * 0x50 >> 0xc;
  x = rsin((int)sVar1);
  sVar1 = *(short *)&pTVar4[1].s0;
  pTVar4[2].s4 = x * 0x50 >> 0xc;
  sVar2 = *(short *)&pTVar4[2].s5;
  *(short *)&pTVar4[1].s0 = sVar1 + *(short *)&pTVar4[2].s3;
  sVar1 = *(short *)((int)&pTVar4[1].s0 + 2);
  sVar3 = *(short *)&pTVar4[2].s4;
  *(short *)&pTVar4[1].s1 = *(short *)&pTVar4[1].s1 + sVar2;
  *(short *)((int)&pTVar4[1].s0 + 2) = sVar1 + sVar3;
  lVar11 = Boxes_TestObject((_D3_OBJECT *)ot);
  return (short)lVar11;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SHPL2_Impact()
 // line 776, offset 0x8003f608
	/* begin block 1 */
		// Start line: 777
		// Start offset: 0x8003F608
		// Variables:
	// 		struct P_SHOOT_143fake *sh; // $s0
	/* end block 1 */
	// End offset: 0x8003F6B0
	// End Line: 794

	/* begin block 2 */
		// Start line: 1876
	/* end block 2 */
	// End Line: 1877

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SHPL2_Impact(void)

{
  TASK *pTVar1;
  
  pTVar1 = TaskCurrent;
  *(undefined2 *)((int)TaskCurrent[2].sp + 6) = 0x3110;
  pTVar1->display = (_func_11 *)0x0;
  while ((int)((uint)*(ushort *)((int)pTVar1[2].sp + 6) << 0x10) >> 0x18 < 0x3d) {
    Main_Prims = (void *)GtxShp_DisplayListLOFF
                                   (&pTVar1[2].exec,Main_Prims,Scr->ot,(int)Scr_OtSize,0xffffff6a,
                                    Main_TextContext.Font.ascii_tab._20_4_);
    *(short *)((int)pTVar1[2].sp + 6) = *(short *)((int)pTVar1[2].sp + 6) + 0x100;
    Task_Next();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SHPL2_Display()
 // line 797, offset 0x8003f6c0
	/* begin block 1 */
		// Start line: 798
		// Start offset: 0x8003F6C0
		// Variables:
	// 		struct P_SHOOT_143fake *sh; // stack offset -72
	// 		struct P_SHOOT_7fake pos; // stack offset -96
	// 		struct P_SHOOT_33fake *g; // $s2
	// 		struct P_SHOOT_33fake *d; // $s3
	// 		long z; // stack offset -76
	// 		long sxy; // stack offset -88
	// 		long sxyl; // stack offset -68
	// 		long sxyr; // stack offset -64
	// 		long sxy0; // stack offset -84
	// 		long sxy1; // stack offset -80
	// 		long lrgb; // $a3
	// 		long i; // $s7
	// 		long size; // $s0
	/* end block 1 */
	// End offset: 0x8003FACC
	// End Line: 871

	/* begin block 2 */
		// Start line: 1920
	/* end block 2 */
	// End Line: 1921

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SHPL2_Display(void)

{
  void *pvVar1;
  _SCREEN *p_Var2;
  undefined4 in_zero;
  undefined4 in_at;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined uVar6;
  TASK *pTVar7;
  long lVar8;
  int iVar9;
  TASK **ppTVar10;
  char cVar11;
  int iVar12;
  short local_60;
  short local_5e;
  undefined2 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  int local_4c;
  TASK *local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 *local_3c;
  int local_38;
  undefined4 local_30;
  
  pTVar7 = TaskCurrent;
  lVar8 = TaskCurrent[1].s1;
  TaskCurrent[3].event_s0 = TaskCurrent[1].s0;
  pTVar7[3].event_s1 = lVar8;
  local_48 = pTVar7 + 1;
  *(undefined2 *)((int)&pTVar7[3].event_s1 + 2) = *(undefined2 *)&pTVar7[1].s5;
  setCopReg(2,in_zero,pTVar7[3].s2);
  setCopReg(2,in_at,pTVar7[3].s3);
  copFunction(2,0x180001);
  local_58 = getCopReg(2,0xe);
  local_30 = 0x10;
  iVar12 = 1;
  local_3c = (undefined4 *)&local_60;
  ppTVar10 = &pTVar7[1].father;
  cVar11 = '\0';
  local_38 = 8;
  pTVar7[3].s2 = pTVar7[3].s4;
  pTVar7[3].s3 = pTVar7[3].s5;
  local_44 = local_58;
  local_40 = local_58;
  do {
    pvVar1 = Main_Prims;
    local_5c = *(undefined2 *)(ppTVar10 + 0x56);
    Main_Prims = (void *)((int)Main_Prims + 0x48);
    uVar3 = 0x800b0000;
    iVar4 = rcos((int)*(short *)((int)ppTVar10 + 0x15a) + 0x400);
    iVar9 = iVar12 * 2;
    local_60 = *(short *)(ppTVar10 + 0x55) + (short)(iVar4 * iVar9 >> 0xc);
    iVar4 = rsin((int)*(short *)((int)ppTVar10 + 0x15a) + 0x400);
    local_5e = *(short *)((int)ppTVar10 + 0x156) + (short)(iVar4 * iVar9 >> 0xc);
    setCopReg(2,in_zero,*local_3c);
    setCopReg(2,uVar3,local_3c[1]);
    copFunction(2,0x180001);
    local_54 = getCopReg(2,0xe);
    puVar5 = (undefined4 *)((int)&local_48[2].s2 + local_38);
    setCopReg(2,in_zero,*puVar5);
    setCopReg(2,uVar3,puVar5[1]);
    copFunction(2,0x180001);
    local_50 = getCopReg(2,0xe);
    local_4c = getCopReg(2,0x9800);
    local_4c = local_4c >> 2;
    *(undefined4 *)((int)pvVar1 + 8) = local_54;
    *(undefined4 *)((int)pvVar1 + 0x18) = local_44;
    *(undefined4 *)((int)pvVar1 + 0x10) = local_50;
    *(undefined *)((int)pvVar1 + 3) = 8;
    *(undefined *)((int)pvVar1 + 7) = 0x3a;
    *(char *)((int)pvVar1 + 0xc) = cVar11;
    *(char *)((int)pvVar1 + 0xd) = cVar11;
    *(char *)((int)pvVar1 + 0xe) = cVar11;
    *(undefined *)((int)pvVar1 + 4) = 0x10;
    *(undefined *)((int)pvVar1 + 5) = 0x10;
    *(char *)((int)pvVar1 + 6) = cVar11;
    *(undefined *)((int)pvVar1 + 0x14) = 0x10;
    *(undefined *)((int)pvVar1 + 0x15) = 0x10;
    uVar6 = (undefined)local_30;
    *(undefined *)((int)pvVar1 + 0x16) = uVar6;
    *(undefined *)((int)pvVar1 + 0x1c) = uVar6;
    *(undefined *)((int)pvVar1 + 0x1d) = uVar6;
    *(undefined *)((int)pvVar1 + 0x1e) = uVar6;
    *(undefined4 *)((int)pvVar1 + 0x20) = local_58;
    local_44 = local_54;
    iVar4 = rcos((int)*(short *)((int)ppTVar10 + 0x15a) - 0x400);
    local_60 = *(short *)(ppTVar10 + 0x55) + (short)(iVar4 * iVar9 >> 0xc);
    iVar4 = rsin((int)*(short *)((int)ppTVar10 + 0x15a) - 0x400);
    local_5e = *(short *)((int)ppTVar10 + 0x156) + (short)(iVar4 * iVar9 >> 0xc);
    setCopReg(2,in_zero,*local_3c);
    setCopReg(2,uVar3,local_3c[1]);
    copFunction(2,0x180001);
    local_54 = getCopReg(2,0xe);
    *(undefined4 *)((int)pvVar1 + 0x2c) = local_54;
    *(undefined4 *)((int)pvVar1 + 0x3c) = local_40;
    *(undefined4 *)((int)pvVar1 + 0x34) = local_50;
    *(undefined4 *)((int)pvVar1 + 0x44) = local_58;
    local_58 = local_50;
    *(undefined *)((int)pvVar1 + 0x27) = 8;
    *(undefined *)((int)pvVar1 + 0x2b) = 0x3a;
    *(char *)((int)pvVar1 + 0x30) = cVar11;
    *(char *)((int)pvVar1 + 0x31) = cVar11;
    *(char *)((int)pvVar1 + 0x32) = cVar11;
    *(undefined *)((int)pvVar1 + 0x28) = 0x10;
    *(undefined *)((int)pvVar1 + 0x29) = 0x10;
    *(char *)((int)pvVar1 + 0x2a) = cVar11;
    *(undefined *)((int)pvVar1 + 0x38) = 0x10;
    *(undefined *)((int)pvVar1 + 0x39) = 0x10;
    uVar6 = (undefined)local_30;
    *(undefined *)((int)pvVar1 + 0x3a) = uVar6;
    *(undefined *)((int)pvVar1 + 0x40) = uVar6;
    *(undefined *)((int)pvVar1 + 0x41) = uVar6;
    *(undefined *)((int)pvVar1 + 0x42) = uVar6;
    p_Var2 = Scr;
    if ((local_4c != 0) && (local_4c < (int)Scr_OtSize)) {
      *(uint *)pvVar1 = *(uint *)pvVar1 & 0xff000000 | Scr->ot[local_4c] & 0xffffff;
      p_Var2->ot[local_4c] = p_Var2->ot[local_4c] & 0xff000000 | (uint)pvVar1 & 0xffffff;
      *(uint *)((int)pvVar1 + 0x24) =
           *(uint *)((int)pvVar1 + 0x24) & 0xff000000 | p_Var2->ot[local_4c] & 0xffffff;
      p_Var2->ot[local_4c] = p_Var2->ot[local_4c] & 0xff000000 | (int)pvVar1 + 0x24U & 0xffffff;
    }
    if (iVar12 < 7) {
      pTVar7 = (&local_48->prec + (iVar12 + 1) * 2)[0x56];
      ppTVar10[0x55] = (&local_48->prec + (iVar12 + 1) * 2)[0x55];
      ppTVar10[0x56] = pTVar7;
    }
    ppTVar10 = ppTVar10 + 2;
    cVar11 = cVar11 + ' ';
    iVar12 = iVar12 + 1;
    local_38 = local_38 + 8;
    local_40 = local_54;
  } while (iVar12 < 8);
  local_40 = local_54;
  Main_Prims = (void *)GtxShp_DisplayListLOFF
                                 (&local_48[1].exec,Main_Prims,Scr->ot,(int)Scr_OtSize,0,
                                  Main_TextContext.Font.ascii_tab._20_4_);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SHPE_Add(struct _PLAYER *pl /*$a0*/, struct P_SHOOT_7fake *pos /*$a1*/, struct P_SHOOT_7fake *rot /*$a2*/)
 // line 883, offset 0x8003fb3c
	/* begin block 1 */
		// Start line: 2224
	/* end block 1 */
	// End Line: 2225

void SHPE_Add(_PLAYER *pl,undefined1 pos,undefined1 rot)

{
  SHPE1_Init(pl,pos,rot);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SHPE1_Init(struct _PLAYER *pl /*$s1*/, struct P_SHOOT_7fake *pos /*$a1*/, struct P_SHOOT_7fake *rot /*$a2*/)
 // line 890, offset 0x8003fb5c
	/* begin block 1 */
		// Start line: 891
		// Start offset: 0x8003FB5C
		// Variables:
	// 		struct P_SHOOT_143fake *sh; // $s0
	// 		struct P_SHOOT_70fake shp; // stack offset -32
	/* end block 1 */
	// End offset: 0x8003FB5C
	// End Line: 891

	/* begin block 2 */
		// Start line: 2238
	/* end block 2 */
	// End Line: 2239

void SHPE1_Init(_PLAYER *pl,undefined1 pos,undefined1 rot)

{
  char cVar1;
  short sVar2;
  P_SHOOT_143fake *o;
  uint uVar3;
  char pos_00;
  
  o = PShoot_Init(pl,pos,rot,-10,SHPE1_Move,(TDRFuncPtr_PShoot_Init5f_impact)0x0,SHPE1_Display,
                  SHPE1_Destructor);
  o[3].obj.rot.vx = 1;
  (o->obj).collision_mode = 0x2003;
  D3_SetBox((_D3_OBJECT *)o,-0x21,-0x21,-0x21,0x21,0x21,0x21);
  pos_00 = (char)pl + ',';
  cVar1 = *(char *)(*(int *)&o->duration + (int)*(short *)(o->t + 0x2a) * 8 + 0x1ac);
  *(undefined *)&o[3].obj.pos.vz = 0x60;
  *(undefined *)((int)&o[3].obj.pos.vz + 1) = 0xd0;
  *(undefined *)&o[3].obj.pos.pad = 0x60;
  uVar3 = (int)cVar1 + 1;
  (o->obj).hit_power = (char)((int)(uVar3 + (uVar3 >> 0x1f)) >> 1) + '\x01';
  Fx_Play(0x1d,pos_00);
  sVar2 = Fx_Play(0x1e,pos_00);
  *(int *)(o->t + 0x24) = (int)sVar2;
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ SHPE1_Move()
 // line 922, offset 0x8003fc54
	/* begin block 1 */
		// Start line: 923
		// Start offset: 0x8003FC54
		// Variables:
	// 		struct P_SHOOT_143fake *sh; // $s1
	// 		struct _PLATFORM *p; // $a0
	// 		struct _D3_OBJECT (*ot[5]); // stack offset -80
	// 		struct P_SHOOT_7fake s; // stack offset -56
	// 		struct P_SHOOT_7fake d; // stack offset -48
	// 		long i; // $s2
	// 		long n; // $v0
	// 		long no; // $s4
	// 		long l; // $s3
	/* end block 1 */
	// End offset: 0x800400AC
	// End Line: 1028

	/* begin block 2 */
		// Start line: 2328
	/* end block 2 */
	// End Line: 2329

/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Unknown calling convention yet parameter storage is locked */

short SHPE1_Move(void)

{
  TASK *pTVar1;
  short r;
  uint uVar2;
  long lVar3;
  _PLATFORM *p_Var4;
  _D3_OBJECT *o;
  int iVar5;
  TASK **ppTVar6;
  TASK *t;
  _D3_OBJECT **pp_Var7;
  TASK *ot;
  int iVar8;
  int dist_max;
  int iVar9;
  int iVar10;
  char cVar11;
  _D3_OBJECT *local_50 [6];
  undefined4 local_38;
  TASK *local_34;
  short local_30;
  short local_2e;
  short local_2c;
  
  pTVar1 = TaskCurrent;
  ot = TaskCurrent + 1;
  uVar2 = M_rand();
  if ((uVar2 & 1) == 0) {
    lVar3 = M_rand();
    Fx_Play((ushort)lVar3 & 1 | 0x20,(char)pTVar1[2].bnext + ',');
  }
  t = Overlay_Handle;
  if ((Pvl_GameTime & 3U) == 0) {
    ppTVar6 = &(pTVar1[2].bnext)->prec + (int)*(short *)((int)&pTVar1[2].s7 + 2) * 2;
    if (*(short *)((int)ppTVar6 + 0x1aa) != 0) {
      *(short *)((int)ppTVar6 + 0x1aa) = *(short *)((int)ppTVar6 + 0x1aa) + -1;
      Task_EventExec(t,t->event_msg | 8,t->event_param);
    }
  }
  lVar3 = PShoot_GetPos((_PLAYER *)pTVar1[2].bnext,200);
  r = 1;
  if ((lVar3 != 0) &&
     (((*(ushort *)&pTVar1[2].bnext[1].event_s3 & PJOY_SHOT) != 0 ||
      (r = 1, *(short *)&pTVar1[6].prec != 0)))) {
    p_Var4 = Plat_GetPlat(200);
    iVar8 = 0;
    if ((p_Var4 == (_PLATFORM *)0x0) ||
       (((cVar11 = *(char *)((int)&p_Var4[1].obj.pos.vx + 1), cVar11 == '\0' || (cVar11 == '\x04'))
        || ((int)(p_Var4->obj).pos.vz + (int)*(short *)&p_Var4[1].obj.prec +
            (int)p_Var4[1].obj.pos.vy <= (int)(short)local_34)))) {
      iVar9 = 0;
      r = *(short *)((int)&pTVar1[2].s7 + 2);
      t = pTVar1[2].bnext;
      cVar11 = -0x1c;
      *(undefined2 *)((int)&pTVar1[5].event_fp + 2) = 0;
      iVar10 = 0;
      dist_max = (int)*(char *)(&t[2].event_fp + (int)r * 2) * 0x32 + 700;
      pp_Var7 = local_50;
      do {
        t = pTVar1[2].bnext;
        *(short *)&pTVar1[1].s4 =
             *(short *)&(pTVar1[2].bnext)->s4 + *(short *)&pTVar1[2].bnext[1].s3;
        *(undefined2 *)((int)&pTVar1[1].s4 + 2) = *(undefined2 *)((int)&t->s4 + 2);
        *(short *)&pTVar1[1].s5 = *(short *)&t->s5 + *(short *)((int)&t[1].s3 + 2);
        *(TASK **)&pTVar1[1].s0 = local_38;
        *(TASK **)&pTVar1[1].s1 = local_34;
        if (iVar8 == 0) {
          local_50[0] = D3_SeekLookTarget((_D3_OBJECT *)pTVar1[2].bnext,0x400,dist_max,0x10);
        }
        else {
          o = D3_SeekDistTarget(local_50[iVar8 + -1],dist_max,0x10);
          *pp_Var7 = o;
          if (o == (_D3_OBJECT *)0x0) break;
        }
        if (*pp_Var7 == (_D3_OBJECT *)0x0) {
          iVar5 = rcos((int)*(short *)&pTVar1[1].s5);
          local_30 = (short)local_38 + (short)(iVar5 * dist_max >> 0xc);
          iVar5 = rsin((int)*(short *)&pTVar1[1].s5);
          local_2e = local_38._2_2_ + (short)(iVar5 * dist_max >> 0xc);
          iVar5 = rsin((int)*(short *)&pTVar1[1].s4);
          local_2c = (short)local_34 + (short)(iVar5 * dist_max >> 0xc);
        }
        else {
          iVar9 = iVar9 + 1;
          Boxes_GetCenter(*pp_Var7,0xd0);
          D3_ClearCollBits(*pp_Var7,0x10);
        }
        r = *(short *)&pTVar1[1].s5;
        *(short *)((int)&pTVar1[5].event_fp + 2) = *(short *)((int)&pTVar1[5].event_fp + 2) + 1;
        r = Motion2D_LightningCompute(200,0xd0,r,(char)ot + cVar11,0xc);
        *(bool *)((int)&ot[4].event_s7 + iVar8) = (int)r < 0xc;
        local_38 = (&ot->prec + (iVar10 * 4 + (int)r + -1) * 2)[0x39];
        local_34 = (&ot->prec + (iVar10 * 4 + (int)r + -1) * 2)[0x3a];
        *(TASK **)&pTVar1[1].s0 = local_38;
        *(TASK **)&pTVar1[1].s1 = local_34;
        Boxes_TestObject((_D3_OBJECT *)ot);
        if (*pp_Var7 == (_D3_OBJECT *)0x0) break;
        pp_Var7 = pp_Var7 + 1;
        cVar11 = cVar11 + '`';
        iVar8 = iVar8 + 1;
        iVar10 = iVar10 + 3;
      } while (iVar8 < 5);
      iVar8 = 0;
      if (0 < iVar9) {
        pp_Var7 = local_50;
        do {
          o = *pp_Var7;
          pp_Var7 = pp_Var7 + 1;
          iVar8 = iVar8 + 1;
          D3_SetCollBits(o,0x10);
        } while (iVar8 < iVar9);
      }
      r = 0;
      if (*(short *)&pTVar1[6].prec != 0) {
        iVar8 = 0;
        if (0 < *(short *)((int)&pTVar1[5].event_fp + 2)) {
          cVar11 = -0x1c;
          do {
            if (*(char *)((int)&ot[4].event_s7 + iVar8) != '\0') {
              Impact_Smoke((char)ot + cVar11 + 'X',1);
            }
            iVar8 = iVar8 + 1;
            cVar11 = cVar11 + '`';
          } while (iVar8 < (int)*(short *)((int)&pTVar1[5].event_fp + 2));
        }
        r = 0;
      }
    }
    else {
      lVar3 = (pTVar1[2].bnext)->s1;
      pTVar1[1].s0 = (pTVar1[2].bnext)->s0;
      pTVar1[1].s1 = lVar3;
      *(char *)((int)&pTVar1[1].display + 2) = *(char *)((int)&pTVar1[1].display + 2) << 2;
      Boxes_TestObject((_D3_OBJECT *)ot);
      r = 1;
    }
  }
  return r;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SHPE1_Display()
 // line 1031, offset 0x800400d8
	/* begin block 1 */
		// Start line: 1032
		// Start offset: 0x800400D8
		// Variables:
	// 		struct P_SHOOT_143fake *sh; // $s0
	// 		short i; // $s1
	/* end block 1 */
	// End offset: 0x8004017C
	// End Line: 1041

	/* begin block 2 */
		// Start line: 2607
	/* end block 2 */
	// End Line: 2608

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SHPE1_Display(void)

{
  TASK *pTVar1;
  int iVar2;
  TASK *pTVar3;
  int iVar4;
  
  pTVar1 = TaskCurrent;
  pTVar3 = TaskCurrent + 1;
  if (((*(short *)&TaskCurrent[6].prec != 0) || (Pvl_Pause != 0)) &&
     (iVar4 = 0, 0 < *(short *)((int)&TaskCurrent[5].event_fp + 2))) {
    iVar2 = 0;
    do {
      Motion2D_LightningDisplay
                ((char)pTVar1 + 'T',(char)pTVar3 + (char)((uint)iVar2 >> 0x10) * '`' + -0x1c,0xc,
                 (ushort)(*(char *)((int)&pTVar3[4].event_s7 + (iVar2 >> 0x10)) == '\0'));
      iVar4 = iVar4 + 1;
      iVar2 = iVar4 * 0x10000;
    } while (iVar4 * 0x10000 >> 0x10 < (int)*(short *)((int)&pTVar1[5].event_fp + 2));
  }
  *(ushort *)&pTVar1[6].prec = *(ushort *)&pTVar1[6].prec ^ 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SHPE1_Destructor(struct TASK *t /*$a0*/)
 // line 1045, offset 0x800401a0
	/* begin block 1 */
		// Start line: 1046
		// Start offset: 0x800401A0
		// Variables:
	// 		struct P_SHOOT_143fake *sh; // $s0
	/* end block 1 */
	// End offset: 0x800401A0
	// End Line: 1046

	/* begin block 2 */
		// Start line: 2636
	/* end block 2 */
	// End Line: 2637

void SHPE1_Destructor(TASK *t)

{
  PShoot_Destructor(t);
  Sound_Stop(t[2].s6,0);
  Fx_Play(0x1f,(char)t[2].bnext + ',');
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SHPA_Add(struct _PLAYER *pl /*$a0*/, struct P_SHOOT_7fake *pos /*$a1*/, struct P_SHOOT_7fake *rot /*$a2*/)
 // line 1063, offset 0x800401e0
	/* begin block 1 */
		// Start line: 1064
		// Start offset: 0x800401E0
	/* end block 1 */
	// End offset: 0x800401E0
	// End Line: 1064

	/* begin block 2 */
		// Start line: 2672
	/* end block 2 */
	// End Line: 2673

void SHPA_Add(_PLAYER *pl,undefined1 pos,undefined rot)

{
  undefined3 in_register_00000019;
  
  SFX_Fusion((_D3_OBJECT *)pl,pos,
             ((int)(char)(pl->env1).Obj.primitive_top.Data
                         [(int)(char)(pl->env1).Obj.primitive_top.Data[0x19] * 8 + 0x1c] + 1) * 0x14
             ,(int)*(short *)(CONCAT31(in_register_00000019,rot) + 4),1000,0x8080ff);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SHPG1_Init(struct _PLAYER *pl /*$s0*/, struct P_SHOOT_7fake *pos /*$a1*/, struct P_SHOOT_7fake *rot /*$a2*/, long speed /*$s2*/)
 // line 1084, offset 0x80040234
	/* begin block 1 */
		// Start line: 1085
		// Start offset: 0x80040234
		// Variables:
	// 		struct P_SHOOT_143fake *sh; // $s1
	// 		struct P_SHOOT_71fake *list; // $s3
	// 		struct P_SHOOT_70fake shp; // stack offset -40
	/* end block 1 */
	// End offset: 0x800402FC
	// End Line: 1109

	/* begin block 2 */
		// Start line: 2721
	/* end block 2 */
	// End Line: 2722

void SHPG1_Init(_PLAYER *pl,undefined1 pos,undefined1 rot,long speed)

{
  short sVar1;
  short sVar2;
  void *pvVar3;
  P_SHOOT_143fake *o;
  int iVar4;
  SHAPE_68fake local_28;
  
  o = PShoot_Init(pl,pos,rot,-0xb,SHPG1_Move,SHPG1_Impact,SHPG1_Display,PShoot_Destructor);
  Fx_Play(0x1c,(char)pl + ',');
  sVar1 = (o->obj).pos.vz;
  *(int *)(o->t + 8) = (int)(o->obj).pos.vx << 0xc;
  sVar2 = (o->obj).pos.vy;
  *(int *)(o->t + 0x10) = (int)sVar1 << 0xc;
  *(int *)(o->t + 0xc) = (int)sVar2 << 0xc;
  if (speed != 2) {
    if (2 < speed) {
      if (speed == 3) {
        speed = 0xc;
      }
      goto LAB_800402fc;
    }
    if (speed < 0) goto LAB_800402fc;
  }
  speed = 8;
LAB_800402fc:
  iVar4 = rcos((int)(o->obj).rot.vz);
  sVar1 = (o->obj).rot.vz;
  *(int *)(o->t + 0x18) = iVar4 * speed * 4;
  iVar4 = rsin((int)sVar1);
  sVar1 = (o->obj).rot.vx;
  *(int *)(o->t + 0x1c) = iVar4 * speed * 4;
  iVar4 = rsin((int)sVar1);
  pvVar3 = Effects_Pcl;
  *(int *)(o->t + 0x20) = iVar4 * speed * 4;
  *(_struct_241 **)&o->impact = &(o->obj).pos;
  o->move = pvVar3;
  *(undefined4 *)o->t = 0;
  (o->obj).pos.pad = 0x5f0c;
  local_28.file = Pl_Pcl;
  *(undefined2 *)(o->t + 4) = 1;
  local_28.shape = 0x25;
  Shp_SetPolyFT4((SHAPE_31fake *)&o[1].obj.father,&local_28,0,0);
  Shp_SetPolyFT4((SHAPE_31fake *)&o[1].obj.last_pos,&local_28,0,0);
  (o->obj).comp_opt1 = 2;
  (o->obj).hit_points = 0;
  *(undefined2 *)((int)&(o->obj).comp_opt4 + 2) = 0;
  (o->obj).collision_mode = 1;
  D3_SetBox((_D3_OBJECT *)o,-0x21,-0x21,-0x21,0x21,0x21,0x21);
  iVar4 = (int)Scr_TicksPerSecond;
  *(undefined2 *)&o[1].obj.child = 0;
  *(short *)(o->t + 0x28) = (short)((int)(iVar4 * 5 + ((uint)(iVar4 * 5) >> 0x1f)) >> 1);
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ SHPG1_Move()
 // line 1138, offset 0x80040420
	/* begin block 1 */
		// Start line: 1139
		// Start offset: 0x80040420
		// Variables:
	// 		struct P_SHOOT_143fake *sh; // $s0
	// 		short shp; // $a0
	/* end block 1 */
	// End offset: 0x80040604
	// End Line: 1198

	/* begin block 2 */
		// Start line: 2862
	/* end block 2 */
	// End Line: 2863

/* WARNING: Unknown calling convention yet parameter storage is locked */

short SHPG1_Move(void)

{
  TASK *pTVar1;
  TASK *pTVar2;
  TASK *pTVar3;
  short sVar4;
  uint uVar5;
  long lVar6;
  int iVar7;
  int iVar8;
  TASK *ot;
  
  pTVar3 = TaskCurrent;
  ot = TaskCurrent + 1;
  iVar8 = TaskCurrent[2].s3;
  pTVar1 = TaskCurrent + 2;
  pTVar2 = TaskCurrent + 2;
  TaskCurrent[2].s5 = TaskCurrent[2].s5 + -0x2800;
  pTVar3[2].s0 = pTVar1->s0 + pTVar2->s4;
  pTVar3[2].local = (void *)((int)pTVar3[2].local + iVar8);
  pTVar3[2].s1 = pTVar3[2].s1 + pTVar3[2].s5;
  *(short *)&pTVar3[1].s0 = (short)((int)pTVar3[2].local >> 0xc);
  iVar8 = pTVar3[2].s1;
  *(undefined2 *)((int)&pTVar3[1].s0 + 2) = (short)(pTVar3[2].s0 >> 0xc);
  *(short *)&pTVar3[1].s1 = (short)(iVar8 >> 0xc);
  uVar5 = Boxes_TestObject((_D3_OBJECT *)ot);
  if ((uVar5 & 0xffff) == 0) {
    iVar8 = (int)((uint)*(ushort *)((int)&pTVar3[1].s1 + 2) << 0x10) >> 0x18;
    if (((pTVar3[2].s3 != 0) || (pTVar3[2].s4 != 0)) || (iVar7 = iVar8 << 0x10, pTVar3[2].s5 != 0))
    {
      iVar8 = iVar8 + 1;
      iVar7 = iVar8 * 0x10000;
    }
    sVar4 = (short)(iVar8 << 8);
    if (100 < iVar7 >> 0x10) {
      sVar4 = 0x5f00;
    }
    *(short *)((int)&pTVar3[1].s1 + 2) = sVar4 + 0xc;
  }
  else {
    sVar4 = pTVar3[2].enable + 1;
    pTVar3[2].enable = sVar4;
    if (sVar4 < 5) {
      lVar6 = M_rand();
      Fx_Play((ushort)lVar6 & 1 | 0x16,(char)pTVar3 + -0x44);
    }
    Boxes_BounceObject12((char)pTVar3 + 'X');
    pTVar3[2].local = (void *)((int)*(short *)&pTVar3[1].s0 << 0xc);
    pTVar3[2].s0 = (int)*(short *)((int)&pTVar3[1].s0 + 2) << 0xc;
    pTVar3[2].s3 = (pTVar3[2].s3 << 1) / 3;
    sVar4 = *(short *)&pTVar3[1].s1;
    pTVar3[2].s4 = (pTVar3[2].s4 << 1) / 3;
    pTVar3[2].s1 = (int)sVar4 << 0xc;
    pTVar3[2].s5 = (pTVar3[2].s5 << 1) / 3;
  }
  sVar4 = 0;
  if ((*(short *)&pTVar3[2].s7 < 2) && (sVar4 = 1, *(short *)&pTVar3[1].s1 < -500)) {
    sVar4 = 0;
  }
  return sVar4;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SHPG1_Impact()
 // line 1201, offset 0x80040618
	/* begin block 1 */
		// Start line: 1202
		// Start offset: 0x80040618
	/* end block 1 */
	// End offset: 0x80040618
	// End Line: 1202

	/* begin block 2 */
		// Start line: 3045
	/* end block 2 */
	// End Line: 3046

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SHPG1_Impact(void)

{
  SFX_ExplodeObject((_D3_OBJECT *)(TaskCurrent + 1));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SHPG1_Display()
 // line 1209, offset 0x80040640
	/* begin block 1 */
		// Start line: 1210
		// Start offset: 0x80040640
		// Variables:
	// 		struct P_SHOOT_143fake *sh; // $s0
	// 		struct P_SHOOT_5fake m; // stack offset -40
	// 		long z; // $a1
	/* end block 1 */
	// End offset: 0x80040790
	// End Line: 1228

	/* begin block 2 */
		// Start line: 3062
	/* end block 2 */
	// End Line: 3063

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SHPG1_Display(void)

{
  int iVar1;
  int iVar2;
  TASK *pTVar3;
  _SCREEN *p_Var4;
  undefined4 in_zero;
  undefined4 in_at;
  long lVar5;
  int iVar6;
  TASK *o;
  
  pTVar3 = TaskCurrent;
  o = TaskCurrent + 1;
  setCopReg(2,in_zero,TaskCurrent[1].s0);
  setCopReg(2,in_at,TaskCurrent[1].s1);
  copFunction(2,0x486012);
  iVar6 = getCopReg(2,0x19);
  iVar1 = getCopReg(2,0x1a);
  iVar2 = getCopReg(2,0x1b);
  setCopControlWord(2,0x2800,iVar6 + Cam_Matrix.t[0]);
  setCopControlWord(2,0x3000,iVar1 + Cam_Matrix.t[1]);
  setCopControlWord(2,0x3800,iVar2 + Cam_Matrix.t[2]);
  lVar5 = D3_SetShadow((_D3_OBJECT *)o,(char)o + (char)Scr_Frame * '(' + -0x18);
  p_Var4 = Scr;
  if ((lVar5 != 0) && (lVar5 < (int)Scr_OtSize)) {
    iVar6 = (int)Scr_Frame;
    (&o->prec + iVar6 * 10)[0x3a] =
         (TASK *)((uint)(&o->prec + iVar6 * 10)[0x3a] & 0xff000000 | Scr->ot[lVar5] & 0xffffff);
    p_Var4->ot[lVar5] =
         p_Var4->ot[lVar5] & 0xff000000 | (uint)(&o[1].event_msg + iVar6 * 10) & 0xffffff;
  }
  setCopControlWord(2,0x2800,Cam_Matrix.t[0]);
  setCopControlWord(2,0x3000,Cam_Matrix.t[1]);
  setCopControlWord(2,0x3800,Cam_Matrix.t[2]);
  Main_Prims = (void *)GtxShp_DisplayListLOFF
                                 (&pTVar3[2].exec,Main_Prims,Scr->ot,(int)Scr_OtSize,0,
                                  Main_TextContext.Font.ascii_tab._20_4_);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SHPG2_Init(struct _PLAYER *pl /*$a0*/, struct P_SHOOT_7fake *pos /*$a1*/, struct P_SHOOT_7fake *rot /*$a2*/)
 // line 1243, offset 0x800407fc
	/* begin block 1 */
		// Start line: 1244
		// Start offset: 0x800407FC
		// Variables:
	// 		struct P_SHOOT_143fake *sh; // $s0
	// 		struct P_SHOOT_70fake shp; // stack offset -24
	/* end block 1 */
	// End offset: 0x800407FC
	// End Line: 1244

	/* begin block 2 */
		// Start line: 3132
	/* end block 2 */
	// End Line: 3133

void SHPG2_Init(_PLAYER *pl,undefined1 pos,undefined1 rot)

{
  short sVar1;
  P_SHOOT_143fake *o;
  void *File;
  undefined4 uVar2;
  SHAPE_68fake local_18;
  
  o = PShoot_Init(pl,pos,rot,-0xc,SHPG2_Move,SHPG1_Impact,SHPG2_Display,SHPG2_Destructor);
  sVar1 = Fx_Play(0xf,(char)o + ',');
  File = Pvl_LnkGlobals;
  *(int *)(o->t + 0x24) = (int)sVar1;
  uVar2 = *(undefined4 *)&(o->obj).pos.vz;
  *(undefined4 *)&(o->obj).last_pos = *(undefined4 *)&(o->obj).pos;
  *(undefined4 *)&(o->obj).last_pos.vz = uVar2;
  File = FileGroup_GetAddr(File,10);
  local_18.file = Pl_Pcl;
  (o->obj).description = (void *)((int)File + 0xc);
  (o->obj).rot.vx = 0x200;
  local_18.shape = 0x25;
  Shp_SetPolyFT4((SHAPE_31fake *)&o[1].obj.child,&local_18,0,0);
  Shp_SetPolyFT4((SHAPE_31fake *)&o[1].obj.pos.vz,&local_18,0,0);
  (o->obj).comp_opt1 = 2;
  *(undefined2 *)((int)&(o->obj).comp_opt4 + 2) = 0;
  D3_SetBox((_D3_OBJECT *)o,-0x21,-0x21,-0x21,0x21,0x21,0x21);
  *(short *)(o->t + 0x28) = Scr_TicksPerSecond * 10;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SHPG2_Destructor(struct TASK *t /*$a0*/)
 // line 1274, offset 0x80040934
	/* begin block 1 */
		// Start line: 1275
		// Start offset: 0x80040934
		// Variables:
	// 		struct P_SHOOT_143fake *sh; // $s0
	/* end block 1 */
	// End offset: 0x80040934
	// End Line: 1275

	/* begin block 2 */
		// Start line: 3214
	/* end block 2 */
	// End Line: 3215

void SHPG2_Destructor(TASK *t)

{
  PShoot_Destructor(t);
  Sound_Stop(t[2].s6,0);
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ SHPG2_Move()
 // line 1286, offset 0x80040964
	/* begin block 1 */
		// Start line: 1287
		// Start offset: 0x80040964
		// Variables:
	// 		struct P_SHOOT_143fake *sh; // $a0
	/* end block 1 */
	// End offset: 0x80040A20
	// End Line: 1308

	/* begin block 2 */
		// Start line: 3239
	/* end block 2 */
	// End Line: 3240

/* WARNING: Unknown calling convention yet parameter storage is locked */

short SHPG2_Move(void)

{
  TASK *pTVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  TASK *pTVar5;
  int iVar6;
  
  sVar2 = Scr_TicksPerSecond;
  pTVar1 = TaskCurrent;
  iVar4 = (uint)*(ushort *)&TaskCurrent[2].s7 << 0x10;
  iVar6 = iVar4 >> 0x10;
  if ((int)Scr_TicksPerSecond < iVar6) {
    pTVar5 = TaskCurrent[2].bnext;
    *(short *)&TaskCurrent[1].s5 = *(short *)&TaskCurrent[1].s5 + 0x10;
    sVar3 = 0;
    if ((*(ushort *)&pTVar5[1].event_s3 & PJOY_BOMB) == 0) {
      *(short *)&pTVar1[2].s7 = sVar2;
    }
  }
  else {
    sVar3 = 1;
    if ((1 < iVar6) &&
       (sVar3 = 0, (iVar6 + ((iVar6 / 6 + (iVar6 >> 0x1f)) - (iVar4 >> 0x1f)) * -6 & 0xffffU) == 0))
    {
      Fx_Play(0xe,(char)TaskCurrent + -0x44);
      sVar3 = 0;
    }
  }
  return sVar3;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SHPG2_Display()
 // line 1311, offset 0x80040a30
	/* begin block 1 */
		// Start line: 1312
		// Start offset: 0x80040A30
		// Variables:
	// 		long z; // $a1
	// 		struct P_SHOOT_5fake m; // stack offset -40
	// 		struct P_SHOOT_143fake *sh; // $s0
	/* end block 1 */
	// End offset: 0x80040B80
	// End Line: 1330

	/* begin block 2 */
		// Start line: 3294
	/* end block 2 */
	// End Line: 3295

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SHPG2_Display(void)

{
  int iVar1;
  int iVar2;
  char cVar3;
  TASK *pTVar4;
  _SCREEN *p_Var5;
  undefined4 in_zero;
  undefined4 in_at;
  long lVar6;
  int iVar7;
  TASK *o;
  
  pTVar4 = TaskCurrent;
  o = TaskCurrent + 1;
  setCopReg(2,in_zero,TaskCurrent[1].s0);
  setCopReg(2,in_at,TaskCurrent[1].s1);
  copFunction(2,0x486012);
  iVar7 = getCopReg(2,0x19);
  iVar1 = getCopReg(2,0x1a);
  iVar2 = getCopReg(2,0x1b);
  setCopControlWord(2,0x2800,iVar7 + Cam_Matrix.t[0]);
  setCopControlWord(2,0x3000,iVar1 + Cam_Matrix.t[1]);
  setCopControlWord(2,0x3800,iVar2 + Cam_Matrix.t[2]);
  lVar6 = D3_SetShadow((_D3_OBJECT *)o,(char)o + (char)Scr_Frame * '(' + -0x1c);
  p_Var5 = Scr;
  cVar3 = (char)pTVar4;
  if ((lVar6 != 0) && (lVar6 < (int)Scr_OtSize)) {
    iVar7 = (int)Scr_Frame;
    (&o->prec + iVar7 * 10)[0x39] =
         (TASK *)((uint)(&o->prec + iVar7 * 10)[0x39] & 0xff000000 | Scr->ot[lVar6] & 0xffffff);
    p_Var5->ot[lVar6] =
         p_Var5->ot[lVar6] & 0xff000000 | (uint)(&o[1].enable + iVar7 * 0x14) & 0xffffff;
  }
  Motion2D_SetRotTrans(cVar3 + -0x44,cVar3 + -0x34);
  Main_Prims = (void *)GtxTmd_DisplayLOFF(pTVar4[1].destructor,Main_Prims,Scr->ot,(int)Scr_OtSize,0)
  ;
  setCopControlWord(2,0,Cam_Matrix.m[0]._0_4_);
  setCopControlWord(2,0x800,Cam_Matrix.m._4_4_);
  setCopControlWord(2,0x1000,Cam_Matrix.m[1]._2_4_);
  setCopControlWord(2,0x1800,Cam_Matrix.m[2]._0_4_);
  setCopControlWord(2,0x2000,Cam_Matrix._16_4_);
  setCopControlWord(2,0x2800,Cam_Matrix.t[0]);
  setCopControlWord(2,0x3000,Cam_Matrix.t[1]);
  setCopControlWord(2,0x3800,Cam_Matrix.t[2]);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SHPF_Add(struct _PLAYER *pl /*$a0*/, struct P_SHOOT_7fake *pos /*$a1*/, struct P_SHOOT_7fake *rot /*$a2*/)
 // line 1350, offset 0x80040c18
	/* begin block 1 */
		// Start line: 3376
	/* end block 1 */
	// End Line: 3377

void SHPF_Add(_PLAYER *pl,undefined1 pos,undefined1 rot)

{
  SHPF1_Init(pl,pos,rot);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SHPF1_Init(struct _PLAYER *pl /*$s1*/, struct P_SHOOT_7fake *pos /*$a1*/, struct P_SHOOT_7fake *rot /*$a2*/)
 // line 1356, offset 0x80040c38
	/* begin block 1 */
		// Start line: 1357
		// Start offset: 0x80040C38
		// Variables:
	// 		struct P_SHOOT_143fake *sh; // $s0
	// 		struct P_SHOOT_71fake *list; // $a1
	// 		long level; // $v1
	/* end block 1 */
	// End offset: 0x80040C38
	// End Line: 1357

	/* begin block 2 */
		// Start line: 3388
	/* end block 2 */
	// End Line: 3389

void SHPF1_Init(_PLAYER *pl,undefined1 pos,undefined1 rot)

{
  short sVar1;
  char cVar2;
  P_SHOOT_143fake *obj;
  int iVar3;
  long lVar4;
  uint uVar5;
  
  obj = PShoot_Init(pl,pos,rot,-9,SHPF1_Move,(TDRFuncPtr_PShoot_Init5f_impact)0x0,SHPF1_Display,
                    SHPF1_Destructor);
  uVar5 = (uint)(pl->env1).Obj.primitive_top.Data
                [(int)(char)(pl->env1).Obj.primitive_top.Data[0x19] * 8 + 0x1c] << 0x18;
  iVar3 = rcos((int)(obj->obj).rot.vz);
  sVar1 = (obj->obj).rot.vz;
  *(int *)(obj->t + 0x18) = iVar3 * 0x50 >> 0xc;
  iVar3 = rsin((int)sVar1);
  sVar1 = (obj->obj).rot.vx;
  *(int *)(obj->t + 0x1c) = iVar3 * 0x50 >> 0xc;
  iVar3 = rsin((int)sVar1);
  cVar2 = (char)obj;
  *(int *)(obj->t + 0x20) = iVar3 * 10 >> 9;
  iVar3 = (int)(((int)uVar5 >> 0x18) + (uVar5 >> 0x1f)) >> 1;
  *(short *)((int)&obj[4].spd.pad + 2) = (short)((int)uVar5 >> 0x18) * 3 + 8;
  obj[4].duration = (short)iVar3 + 1;
  lVar4 = Motion2D_FlameInit((_D3_OBJECT *)obj,cVar2 + -0x58,cVar2 + -0x1c,cVar2 + 'l',iVar3 * 3 + 5
                             ,0x28,0);
  *(long *)(obj->t + 0x24) = lVar4;
  *(undefined2 *)&obj[4].spd.pad = 0;
  *(undefined2 *)(obj->t + 0x28) = 0;
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ SHPF1_Move()
 // line 1393, offset 0x80040d60
	/* begin block 1 */
		// Start line: 1394
		// Start offset: 0x80040D60
		// Variables:
	// 		struct P_SHOOT_143fake *sh; // $s0
	// 		struct P_SHOOT_71fake *list; // $s2
	// 		long growth; // $a3
	// 		long max; // $t0
	// 		long disappear; // $s1
	/* end block 1 */
	// End offset: 0x80040E9C
	// End Line: 1428

	/* begin block 2 */
		// Start line: 3519
	/* end block 2 */
	// End Line: 3520

/* WARNING: Unknown calling convention yet parameter storage is locked */

short SHPF1_Move(void)

{
  short sVar1;
  short sVar2;
  char cVar3;
  TASK *pTVar4;
  short sVar5;
  long lVar6;
  TASK **ppTVar7;
  TASK *t;
  TASK *obj;
  
  pTVar4 = TaskCurrent;
  t = Overlay_Handle;
  obj = TaskCurrent + 1;
  cVar3 = (char)TaskCurrent;
  if (Pvl_GameTime == (Pvl_GameTime / 6) * 6) {
    ppTVar7 = &(TaskCurrent[2].bnext)->prec + (int)*(short *)((int)&TaskCurrent[2].s7 + 2) * 2;
    if (*(short *)((int)ppTVar7 + 0x1aa) != 0) {
      *(short *)((int)ppTVar7 + 0x1aa) = *(short *)((int)ppTVar7 + 0x1aa) + -1;
      Task_EventExec(t,t->event_msg | 8,t->event_param);
    }
  }
  t = pTVar4[2].bnext;
  sVar5 = *(short *)&pTVar4[8].destructor;
  sVar1 = *(short *)((int)&pTVar4[8].display + 2);
  sVar2 = *(short *)&pTVar4[8].display;
  *(short *)&pTVar4[1].s4 = *(short *)&(pTVar4[2].bnext)->s4 + *(short *)&pTVar4[2].bnext[1].s3;
  *(undefined2 *)((int)&pTVar4[1].s4 + 2) = *(undefined2 *)((int)&t->s4 + 2);
  *(short *)&pTVar4[1].s5 = *(short *)&t->s5 + *(short *)((int)&t[1].s3 + 2);
  lVar6 = Motion2D_FlameCompute
                    ((_D3_OBJECT *)obj,cVar3 + '8',cVar3 + -0x44,(int)sVar5,(int)sVar1,(int)sVar2,0)
  ;
  sVar5 = 1;
  if ((lVar6 == 0) && (sVar5 = 0, (int)sVar2 == 0)) {
    lVar6 = PShoot_GetPos((_PLAYER *)pTVar4[2].bnext,(char)pTVar4[2].sp);
    sVar5 = 1;
    if ((lVar6 != 0) && (sVar5 = 0, (*(ushort *)&pTVar4[2].bnext[1].event_s3 & PJOY_SHOT) == 0)) {
      sVar5 = 1;
    }
  }
  return sVar5;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SHPF1_Destructor(struct TASK *t /*$a0*/)
 // line 1431, offset 0x80040eb4
	/* begin block 1 */
		// Start line: 1432
		// Start offset: 0x80040EB4
		// Variables:
	// 		struct P_SHOOT_143fake *sh; // $s0
	/* end block 1 */
	// End offset: 0x80040EB4
	// End Line: 1432

	/* begin block 2 */
		// Start line: 3636
	/* end block 2 */
	// End Line: 3637

void SHPF1_Destructor(TASK *t)

{
  PShoot_Destructor(t);
  Sound_Stop(t[2].s6,0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SHPF1_Display()
 // line 1446, offset 0x80040ee4
	/* begin block 1 */
		// Start line: 1447
		// Start offset: 0x80040EE4
	/* end block 1 */
	// End offset: 0x80040EE4
	// End Line: 1447

	/* begin block 2 */
		// Start line: 3667
	/* end block 2 */
	// End Line: 3668

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SHPF1_Display(void)

{
  Motion2D_FlameDisplay((char)TaskCurrent + '8');
  return;
}





