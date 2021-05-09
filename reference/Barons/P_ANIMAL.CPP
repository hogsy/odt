#include "THISDUST.H"
#include "P_ANIMAL.H"


// decompiled code
// original method signature: 
// void /*$ra*/ Pan_AddAnimal(struct _PLAYER *pl /*$s3*/, void *Lnk /*$s2*/)
 // line 48, offset 0x80034258
	/* begin block 1 */
		// Start line: 49
		// Start offset: 0x80034258
		// Variables:
	// 		struct _P_ANIMAL *an; // $s0
	// 		struct P_ANIMAL_74fake *Tmd; // $s1
	// 		struct TASK *t; // $s1
	/* end block 1 */
	// End offset: 0x80034258
	// End Line: 49

	/* begin block 2 */
		// Start line: 96
	/* end block 2 */
	// End Line: 97

void Pan_AddAnimal(_PLAYER *pl,void *Lnk)

{
  short Offset;
  TASK *pTVar1;
  _func_10 *p_Var2;
  void *pvVar3;
  _func_11 *p_Var4;
  TMD_72fake *Tmd;
  TASK *o;
  
  pTVar1 = Task_Link(Pan_Task,0x510);
  o = pTVar1 + 1;
  *(TASK **)&pTVar1->local = o;
  *(undefined2 *)((int)&pTVar1[1].exec + 2) = 0x15f;
  *(_PLAYER **)&pTVar1[2].event_s1 = pl;
  *(undefined2 *)((int)&pTVar1[1].s4 + 2) = 0;
  *(undefined2 *)&pTVar1[1].s4 = 0;
  pTVar1[1].bnext = (TASK *)0x0;
  D3_SetBox((_D3_OBJECT *)o,-0x14,-0x14,-0x14,0x14,0x14,0x14);
  *(TASK **)&pTVar1[1].destructor = (TASK *)&pTVar1[2].bnext;
  *(undefined2 *)((int)&pTVar1[1].text_context + 2) = 0x2000;
  *(undefined2 *)((int)&pTVar1[1].event_msg + 2) = 0;
  *(long **)&pTVar1[1].s6 = &pTVar1[2].s7;
  pTVar1[1].local = (void *)0x808080;
  *(undefined2 *)&pTVar1[1].sp = 0x2003;
  *(undefined2 *)((int)&pTVar1[1].sp + 2) = 0;
  *(undefined2 *)&pTVar1[1].display = 0;
  *(_PLAYER **)&pTVar1[2].bprec = pl;
  pTVar1[2].destructor = (_func_12 *)0x0;
  pTVar1[2].s6 = 0;
  pTVar1[2].bnext = o;
  p_Var2 = (_func_10 *)FileGroup_GetAddr(Lnk,0);
  pTVar1[2].exec = p_Var2;
  pvVar3 = FileGroup_GetAddr(Lnk,1);
  pTVar1[2].sp = pvVar3;
  p_Var4 = (_func_11 *)FileGroup_GetAddr(Lnk,3);
  pTVar1[2].display = p_Var4;
  *(undefined2 *)((int)&pTVar1[2].local + 2) = 0xffff;
  Tmd = (TMD_72fake *)FileGroup_GetAddr(Lnk,2);
  Tmd_InitFile(Tmd);
  Offset = Shp_GetMark(Pl_Pcl,0x4d2);
  Shp_TmdToVram(Pl_Pcl,Tmd,Offset,0);
  Motion_InitAni((MOTION_98fake *)pTVar1[2].display);
  Motion_InitEnv((MOTION_96fake *)pTVar1[2].sp,(MOTION_72fake *)Tmd);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pan_Task()
 // line 102, offset 0x800343c8
	/* begin block 1 */
		// Start line: 103
		// Start offset: 0x800343C8
		// Variables:
	// 		struct _P_ANIMAL *an; // $s0
	/* end block 1 */
	// End offset: 0x80034498
	// End Line: 128

	/* begin block 2 */
		// Start line: 260
	/* end block 2 */
	// End Line: 261

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pan_Task(void)

{
  long lVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  pvVar3 = TaskCurrent->local;
  Task_Sleep(4);
  TaskCurrent->display = Pan_Display;
  uVar2 = *(undefined4 *)(*(int *)((int)pvVar3 + 0x100) + 0x30);
  *(undefined4 *)((int)pvVar3 + 0x2c) = *(undefined4 *)(*(int *)((int)pvVar3 + 0x100) + 0x2c);
  *(undefined4 *)((int)pvVar3 + 0x30) = uVar2;
  *(short *)((int)pvVar3 + 0x30) = *(short *)((int)pvVar3 + 0x30) + 200;
  do {
    Task_EventExec(TaskCurrent,1,0);
    lVar1 = Task_EventWait();
    *(long *)((int)pvVar3 + 0x10c) = lVar1;
    if (lVar1 == 1) {
      Pan_ActMove();
    }
    else {
      if (lVar1 == 2) {
        Pan_ActAttack();
      }
    }
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pan_Display()
 // line 131, offset 0x80034498
	/* begin block 1 */
		// Start line: 132
		// Start offset: 0x80034498
		// Variables:
	// 		struct _P_ANIMAL *an; // $s0
	// 		struct _D3_OBJECT *ot; // $a2
	/* end block 1 */
	// End offset: 0x80034628
	// End Line: 185

	/* begin block 2 */
		// Start line: 338
	/* end block 2 */
	// End Line: 339

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pan_Display(void)

{
  char cVar1;
  undefined *puVar2;
  int param;
  void *pvVar3;
  
  pvVar3 = TaskCurrent->local;
  if (Pvl_Pause == 0) {
    if ((*(int *)((int)pvVar3 + 0x10c) != 2) &&
       ((*(ushort *)(*(int *)((int)pvVar3 + 0x100) + 0x1e) & 2) != 0)) {
      param = *(int *)(*(int *)((int)pvVar3 + 0x100) + 0x90);
      if (((byte)(*(char *)(param + 0x99) + 0x20U) < 0x1a) &&
         (((int)*(short *)(param + 0x1c) & 0x8000U) == 0)) {
        param = *(int *)(param + 0xa0);
      }
      if (((param != 0) && (((int)*(short *)(param + 0x1c) & 0x8000U) != 0)) &&
         (*(short *)(param + 0x6a) == 1)) {
        Task_EventExec(TaskCurrent,2,param);
      }
    }
    Manim_PlayAnim((M_OBJECT *)((int)pvVar3 + 0xa4));
    cVar1 = (char)pvVar3;
    if ((*(ushort *)((int)pvVar3 + 0xc6) & 2) != 0) {
      Fx_Play(0x46,cVar1 + ',');
    }
    if ((*(ushort *)((int)pvVar3 + 0xc6) & 4) != 0) {
      Fx_Play(0x44,cVar1 + ',');
    }
    if ((*(int *)((int)pvVar3 + 0x10c) == 1) && ((char)Pvl_GameTime == '\0')) {
      Fx_Play(0x45,cVar1 + ',');
    }
  }
  if (*(char *)(*(int *)((int)pvVar3 + 0x100) + 500) == '\v') {
    Manim_SetEffect((M_OBJECT *)((int)pvVar3 + 0xa4),(TDRFuncPtr_Manim_SetEffect1f)0x0);
    puVar2 = &DAT_003030ff;
  }
  else {
    *(undefined4 *)((int)pvVar3 + 0xd4) = *(undefined4 *)(*(int *)((int)pvVar3 + 0x100) + 0xd4);
    *(undefined2 *)((int)pvVar3 + 0xc4) = *(undefined2 *)(*(int *)((int)pvVar3 + 0x100) + 0xc4);
    puVar2 = *(undefined **)(*(int *)((int)pvVar3 + 0x100) + 0x28);
  }
  *(undefined **)((int)pvVar3 + 0x28) = puVar2;
  Main_Prims = Manim_DisplayActor((M_OBJECT *)((int)pvVar3 + 0xa4),Main_Prims,0,(int)Scr_W);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pan_ActMove()
 // line 191, offset 0x8003465c
	/* begin block 1 */
		// Start line: 192
		// Start offset: 0x8003465C
		// Variables:
	// 		struct _P_ANIMAL *an; // $s3
	// 		struct _PLATFORM *p; // $v0
	// 		struct _D3_OBJECT *obj; // $s0
	// 		struct _D3_OBJECT (*os[8]); // stack offset -56
	// 		long n; // $s1
	// 		long d; // $s2
	/* end block 1 */
	// End offset: 0x80034874
	// End Line: 253

	/* begin block 2 */
		// Start line: 464
	/* end block 2 */
	// End Line: 465

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pan_ActMove(void)

{
  bool bVar1;
  _PLATFORM *p_Var2;
  _D3_OBJECT *obj;
  long lVar3;
  uint uVar4;
  _D3_OBJECT **pp_Var5;
  _D3_OBJECT *obj_00;
  int iVar6;
  void *pvVar7;
  int iVar8;
  _D3_OBJECT *local_38 [8];
  
  pvVar7 = TaskCurrent->local;
  do {
    iVar6 = 0;
    p_Var2 = Plat_GetPlat((char)*(undefined4 *)((int)pvVar7 + 0x100) + ',');
    if ((p_Var2 == (_PLATFORM *)0x0) || (obj = (p_Var2->obj).child, obj == (_D3_OBJECT *)0x0)) {
LAB_80034824:
      if (iVar6 == 0) goto LAB_8003482c;
    }
    else {
      bVar1 = true;
      do {
        if (!bVar1) break;
        if ((((*(uint *)&obj->collision_mode & 0x801) == 1) &&
            (*(char *)((int)&obj[1].pos.vx + 1) == '\0')) &&
           (lVar3 = Distance3D((int)(obj->pos).vx,(int)(obj->pos).vy,
                               (int)(obj->pos).vz + (int)*(short *)&obj[1].prec,
                               (int)*(short *)(*(int *)((int)pvVar7 + 0x100) + 0x2c),
                               (int)*(short *)(*(int *)((int)pvVar7 + 0x100) + 0x2e),
                               (int)*(short *)(*(int *)((int)pvVar7 + 0x100) + 0x30)),
           lVar3 - 0x33U < 0x2ed)) {
          if ((((obj->child != (_D3_OBJECT *)0x0) &&
               (*(char *)((int)&obj->child[1].pos.vx + 1) == '\x03')) &&
              ((obj->hit_points != 0 &&
               ((obj->hit_points < 0x15 && (uVar4 = M_rand(), (uVar4 & 1) == 0)))))) &&
             (199 < lVar3)) {
            Pan_Attack(obj);
            return;
          }
          local_38[iVar6] = obj;
          iVar6 = iVar6 + 1;
        }
        obj = obj->next;
        bVar1 = iVar6 < 8;
      } while (obj != (_D3_OBJECT *)0x0);
      if (iVar6 != 0) {
        lVar3 = M_rand();
        iVar8 = lVar3 % iVar6;
        if (iVar6 == 0) {
          trap(0x1c00);
        }
        if ((iVar6 == -1) && (lVar3 == -0x80000000)) {
          trap(0x1800);
        }
        pp_Var5 = local_38 + iVar8;
        obj_00 = *pp_Var5;
        while (iVar8 != 0) {
          obj_00 = *pp_Var5;
          iVar8 = iVar8 + -1;
          pp_Var5 = pp_Var5 + -1;
        }
        iVar6 = 1;
        goto LAB_80034824;
      }
LAB_8003482c:
      obj_00 = *(_D3_OBJECT **)((int)pvVar7 + 0x100);
    }
    lVar3 = Pan_LandOnObject(obj_00);
    if (lVar3 == 0) {
      lVar3 = Pan_MoveFly(*(_D3_OBJECT **)((int)pvVar7 + 0x100),0);
      if (lVar3 == 0) {
        Task_Next();
      }
    }
    else {
      Pan_TakeOff();
    }
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pan_ActAttack()
 // line 256, offset 0x80034894
	/* begin block 1 */
		// Start line: 257
		// Start offset: 0x80034894
	/* end block 1 */
	// End offset: 0x80034894
	// End Line: 257

	/* begin block 2 */
		// Start line: 686
	/* end block 2 */
	// End Line: 687

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pan_ActAttack(void)

{
  Pan_Attack((_D3_OBJECT *)TaskCurrent->event_param);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Pan_MoveFly(struct _D3_OBJECT *obj /*stack 0*/, long attack /*stack 4*/)
 // line 270, offset 0x800348c0
	/* begin block 1 */
		// Start line: 271
		// Start offset: 0x800348C0
		// Variables:
	// 		struct _P_ANIMAL *an; // $s0
	// 		struct P_ANIMAL_7fake poses[4]; // stack offset -80
	// 		long tx; // $s4
	// 		long ty; // $s5
	// 		long tz; // $s1
	// 		long i; // $s3
	// 		long j; // $v1
	// 		long move; // $s7
	// 		long speed; // stack offset -48
	// 		long sample; // $fp
	/* end block 1 */
	// End offset: 0x80034C00
	// End Line: 367

	/* begin block 2 */
		// Start line: 715
	/* end block 2 */
	// End Line: 716

/* WARNING: Could not reconcile some variable overlaps */

long Pan_MoveFly(_D3_OBJECT *obj,long attack)

{
  bool bVar1;
  short sVar2;
  long speed;
  int x;
  int y;
  undefined4 *puVar3;
  undefined4 uVar4;
  _D3_OBJECT *o;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48 [6];
  undefined4 local_30;
  
  iVar7 = 0;
  o = (_D3_OBJECT *)TaskCurrent->local;
  local_50 = *(undefined4 *)(o[2].color + 0x2c);
  local_4c = *(undefined4 *)(o[2].color + 0x30);
  Manim_SetAnim((M_OBJECT *)&o[1].last_pos.vz,0);
  if (attack == 0) {
    local_30 = 0x100;
    iVar8 = 4;
  }
  else {
    local_30 = 0x180;
    iVar8 = 2;
  }
  puVar6 = &local_50;
  do {
    bVar1 = false;
    speed = Pan_TestObject(obj,(_PLAYER *)o[2].color,1);
    if (speed == 0) {
      return 0;
    }
    if ((Pvl_GameTime & iVar8 - 1U) == 0) {
      x = 1;
      if (iVar7 == iVar8) {
        if (1 < iVar7) {
          puVar3 = local_48;
          y = 0;
          do {
            uVar4 = puVar3[1];
            *(undefined4 *)((int)&local_50 + y) = *puVar3;
            *(undefined4 *)((int)&local_4c + y) = uVar4;
            puVar3 = puVar3 + 2;
            x = x + 1;
            y = y + 8;
          } while (x < iVar8);
        }
        puVar6 = puVar6 + -2;
        iVar7 = iVar7 + -1;
      }
      if ((((obj->pos).vx != *(short *)puVar6) || ((obj->pos).vy != *(short *)((int)puVar6 + 2))) ||
         ((obj->pos).vz != *(short *)(puVar6 + 1))) {
        iVar7 = iVar7 + 1;
        uVar4 = *(undefined4 *)&(obj->pos).vz;
        *puVar6 = *(undefined4 *)&obj->pos;
        puVar6[1] = uVar4;
        puVar6 = puVar6 + 2;
      }
    }
    iVar5 = (int)(short)local_4c - (int)(o->pos).vz;
    x = (int)(short)local_50 - (int)(o->pos).vx;
    y = (int)local_50._2_2_ - (int)(o->pos).vy;
    if (attack == 0) {
      sVar2 = *(short *)&obj[1].prec;
      iVar5 = iVar5 + 0x50;
    }
    else {
      sVar2 = *(short *)&obj[1].prec;
      iVar5 = iVar5 + -0x14;
    }
    if (attack == 0) {
      speed = 0x40;
    }
    else {
      speed = 0x80;
    }
    D3_GoToDir(o,x,y,speed);
    Manim_SetAnim((M_OBJECT *)&o[1].last_pos.vz,0);
    if (iVar5 + (int)sVar2 < -0x19) {
      sVar2 = (o->pos).vz + -0xc;
LAB_80034b3c:
      bVar1 = true;
      (o->pos).vz = sVar2;
    }
    else {
      if (0x19 < iVar5 + (int)sVar2) {
        sVar2 = (o->pos).vz + 0xc;
        goto LAB_80034b3c;
      }
    }
    if (x < 0) {
      x = -x;
    }
    if (x < 0x32) {
      if (y < 0) {
        y = -y;
      }
      if (0x31 < y) goto LAB_80034bd0;
      o[1].comp_opt1 = 0;
      o[1].comp_opt3 = (short)local_30;
      if (iVar7 != 0) {
        x = 1;
        puVar3 = local_48;
        y = 0;
        do {
          uVar4 = puVar3[1];
          *(undefined4 *)((int)&local_50 + y) = *puVar3;
          *(undefined4 *)((int)&local_4c + y) = uVar4;
          puVar3 = puVar3 + 2;
          x = x + 1;
          y = y + 8;
        } while (x < 4);
        puVar6 = puVar6 + -2;
        iVar7 = iVar7 + -1;
      }
    }
    else {
LAB_80034bd0:
      bVar1 = true;
      o[1].comp_opt3 = (short)local_30 + 0xc0;
      o[1].comp_opt1 = 0x100;
    }
    Task_Next();
    if ((!bVar1) && (iVar7 == 0)) {
      return 1;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// long /*$ra*/ Pan_LandOnObject(struct _D3_OBJECT *obj /*$s2*/)
 // line 370, offset 0x80034c30
	/* begin block 1 */
		// Start line: 371
		// Start offset: 0x80034C30
		// Variables:
	// 		struct _P_ANIMAL *an; // $s0
	// 		struct P_ANIMAL_7fake pos; // stack offset -32
	// 		long x; // $s4
	// 		long y; // $s3
	// 		long tx; // $a2
	// 		long ty; // $a1
	// 		long tz; // $a0
	// 		long move; // $s1
	/* end block 1 */
	// End offset: 0x80034F38
	// End Line: 471

	/* begin block 2 */
		// Start line: 946
	/* end block 2 */
	// End Line: 947

long Pan_LandOnObject(_D3_OBJECT *obj)

{
  bool bVar1;
  short sVar2;
  long lVar3;
  _D3_OBJECT *p_Var4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  _D3_OBJECT *o;
  short local_20;
  short local_1e;
  short local_1c;
  
  o = (_D3_OBJECT *)TaskCurrent->local;
  lVar3 = Pan_MoveFly(obj,0);
  if (lVar3 == 0) {
LAB_80034c6c:
    lVar3 = 0;
  }
  else {
    p_Var4 = (_D3_OBJECT *)o[2].color;
    if (obj == p_Var4) {
      iVar5 = rcos((int)(obj->rot).vz);
      uVar7 = SEXT24((obj->rot).vz);
    }
    else {
      uVar7 = Direction((int)(p_Var4->pos).vx - (int)(obj->pos).vx,
                        (int)(p_Var4->pos).vy - (int)(obj->pos).vy);
      iVar5 = rcos(uVar7);
      uVar7 = Direction((int)*(short *)(o[2].color + 0x2c) - (int)(obj->pos).vx,
                        (int)*(short *)(o[2].color + 0x2e) - (int)(obj->pos).vy);
    }
    iVar6 = rsin(uVar7);
    Manim_SetAnim((M_OBJECT *)&o[1].last_pos.vz,0);
    o[1].comp_opt1 = 0;
    o[1].comp_opt3 = 0x100;
    do {
      lVar3 = Pan_TestObject(obj,(_PLAYER *)o[2].color,0);
      if (lVar3 == 0) goto LAB_80034c6c;
      lVar3 = D3_GoToDir(o,iVar5 >> 6,iVar6 >> 6,0x40);
      bVar1 = lVar3 != 0;
      Pan_GetLandPos(obj,0xe0);
      iVar10 = (int)local_20 - (int)(o->pos).vx;
      iVar9 = (int)local_1e - (int)(o->pos).vy;
      iVar8 = (int)local_1c - (int)(o->pos).vz;
      sVar2 = (o->pos).vx;
      if (iVar10 < 0xb) {
        sVar2 = sVar2 + -10;
        if (iVar10 < -10) goto LAB_80034d88;
      }
      else {
        sVar2 = sVar2 + 10;
LAB_80034d88:
        (o->pos).vx = sVar2;
        bVar1 = true;
      }
      if (iVar9 < 0xb) {
        if (iVar9 < -10) {
          sVar2 = (o->pos).vy + -10;
          goto LAB_80034dc4;
        }
      }
      else {
        sVar2 = (o->pos).vy + 10;
LAB_80034dc4:
        bVar1 = true;
        (o->pos).vy = sVar2;
      }
      if (iVar8 < 0xb) {
        if (iVar8 < -10) {
          sVar2 = (o->pos).vz + -10;
          goto LAB_80034dfc;
        }
      }
      else {
        sVar2 = (o->pos).vz + 10;
LAB_80034dfc:
        bVar1 = true;
        (o->pos).vz = sVar2;
      }
      Task_Next();
    } while (((bVar1) || ((*(ushort *)&o[1].difficulty & 0x4000) == 0)) &&
            (lVar3 = Pan_TestObject(obj,(_PLAYER *)o[2].color,0), lVar3 != 0));
    lVar3 = Pan_TestObject(obj,(_PLAYER *)o[2].color,0);
    if (lVar3 != 0) {
      Pan_GetLandPos(obj,(char)o + ',');
      Manim_SetAnim((M_OBJECT *)&o[1].last_pos.vz,2);
      while ((*(ushort *)&o[1].difficulty & 0x4000) == 0) {
        (o->pos).vz = (o->pos).vz + -5;
        Task_Next();
      }
    }
    iVar5 = (int)Scr_TicksPerSecond * 5 + -1;
    *(ushort *)&o[1].difficulty = *(ushort *)&o[1].difficulty & 0xfffe;
    lVar3 = 1;
    if (iVar5 != -1) {
      do {
        lVar3 = Pan_TestObject(obj,(_PLAYER *)o[2].color,0);
        if (lVar3 == 0) {
          return 1;
        }
        if ((obj->collision_mode & 0x1000U) == 0) {
          lVar3 = Distance2D((int)*(short *)(o[2].color + 0x2c),(int)*(short *)(o[2].color + 0x2e),
                             (int)(o->pos).vx,(int)(o->pos).vy);
          if (lVar3 < 0x33) {
            return 1;
          }
        }
        else {
          (o->rot).vz = (obj->rot).vz;
        }
        iVar5 = iVar5 + -1;
        Task_Next();
      } while (iVar5 != -1);
      lVar3 = 1;
    }
  }
  return lVar3;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pan_TakeOff()
 // line 474, offset 0x80034f58
	/* begin block 1 */
		// Start line: 475
		// Start offset: 0x80034F58
		// Variables:
	// 		struct _P_ANIMAL *an; // $s0
	/* end block 1 */
	// End offset: 0x80034FAC
	// End Line: 486

	/* begin block 2 */
		// Start line: 1169
	/* end block 2 */
	// End Line: 1170

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pan_TakeOff(void)

{
  void *pvVar1;
  
  pvVar1 = TaskCurrent->local;
  Manim_SetAnim((M_OBJECT *)((int)pvVar1 + 0xa4),1);
  while ((*(ushort *)((int)pvVar1 + 0xcc) & 0x4000) == 0) {
    *(short *)((int)pvVar1 + 0x30) = *(short *)((int)pvVar1 + 0x30) + 5;
    Task_Next();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pan_Attack(struct _D3_OBJECT *obj /*$s1*/)
 // line 489, offset 0x80034fbc
	/* begin block 1 */
		// Start line: 490
		// Start offset: 0x80034FBC
		// Variables:
	// 		struct _P_ANIMAL *an; // $s0
	/* end block 1 */
	// End offset: 0x800350EC
	// End Line: 532

	/* begin block 2 */
		// Start line: 1199
	/* end block 2 */
	// End Line: 1200

void Pan_Attack(_D3_OBJECT *obj)

{
  long lVar1;
  _PLAYER *pl;
  _D3_OBJECT *ot;
  
  ot = (_D3_OBJECT *)TaskCurrent->local;
  lVar1 = Pan_MoveFly(obj,1);
  if (lVar1 != 0) {
    Manim_SetAnim((M_OBJECT *)&ot[1].last_pos.vz,3);
    *(undefined *)((int)&ot[1].pos.vx + 1) = 0xf3;
    ot->hit_power = '\x14';
    if (*(char *)((int)&obj[1].pos.vx + 1) != '\0') {
      pl = (_PLAYER *)ot[2].color;
      ot->hit_power = '\x03';
      if ((pl->env2).Obj.primitive_top.Data[4] == 3) {
        lVar1 = Pl_GetSpellLevel(pl,3,(long *)0x0);
        ot->hit_points = ot->hit_points * ((short)lVar1 + 2);
      }
      if ((((_PLAYER *)ot[2].color)->env2).Obj.primitive_top.Data[4] == 0xb) {
        lVar1 = Pl_GetSpellLevel((_PLAYER *)ot[2].color,0xb,(long *)0x0);
        *(undefined *)((int)&ot[1].pos.vx + 1) = 0xf0;
        ot->hit_points = ot->hit_points + ((short)lVar1 + 1) * 2;
      }
    }
    while( true ) {
      if (((*(ushort *)&ot[1].difficulty & 0x4000) != 0) ||
         (lVar1 = Pan_TestObject(obj,(_PLAYER *)ot[2].color,1), lVar1 == 0)) goto LAB_800350e4;
      lVar1 = Boxes_TestObject(ot);
      if (lVar1 != 0) break;
      Task_Next();
    }
    (ot->rot).vz = (ot->rot).vz + 0x800U & 0xfff;
LAB_800350e4:
    Manim_WaitAnim((M_OBJECT *)&ot[1].last_pos.vz);
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Pan_TestObject(struct _D3_OBJECT *obj /*$s1*/, struct _PLAYER *pl /*$a1*/, long fmove /*$s2*/)
 // line 537, offset 0x80035100
	/* begin block 1 */
		// Start line: 538
		// Start offset: 0x80035100
		// Variables:
	// 		struct _P_ANIMAL *an; // $s0
	/* end block 1 */
	// End offset: 0x800351CC
	// End Line: 558

	/* begin block 2 */
		// Start line: 1300
	/* end block 2 */
	// End Line: 1301

long Pan_TestObject(_D3_OBJECT *obj,_PLAYER *pl,long fmove)

{
  long lVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  pvVar3 = TaskCurrent->local;
  if ((obj->collision_state & 4U) == 0) {
    lVar1 = Distance3D((int)(obj->pos).vx,(int)(obj->pos).vy,(int)(obj->pos).vz,
                       (int)*(short *)(*(int *)((int)pvVar3 + 0x100) + 0x2c),
                       (int)*(short *)(*(int *)((int)pvVar3 + 0x100) + 0x2e),
                       (int)*(short *)(*(int *)((int)pvVar3 + 0x100) + 0x30));
    if (799 < lVar1) {
      return 0;
    }
    if (fmove == 0) {
      if (*(int *)&obj->pos != *(int *)((int)pvVar3 + 0x104)) {
        return 0;
      }
      if ((obj->pos).vz != *(short *)((int)pvVar3 + 0x108)) goto LAB_800351a0;
    }
    uVar2 = *(undefined4 *)&(obj->pos).vz;
    *(undefined4 *)((int)pvVar3 + 0x104) = *(undefined4 *)&obj->pos;
    *(undefined4 *)((int)pvVar3 + 0x108) = uVar2;
    lVar1 = 1;
  }
  else {
LAB_800351a0:
    lVar1 = 0;
  }
  return lVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pan_GetLandPos(struct _D3_OBJECT *obj /*$s0*/, struct P_ANIMAL_7fake *out /*$s1*/)
 // line 561, offset 0x800351e4
	/* begin block 1 */
		// Start line: 562
		// Start offset: 0x800351E4

		/* begin block 1.1 */
			// Start line: 571
			// Start offset: 0x8003523C
			// Variables:
		// 		long y; // $v1
		// 		long rc; // $s0
		/* end block 1.1 */
		// End offset: 0x80035294
		// End Line: 581
	/* end block 1 */
	// End offset: 0x80035294
	// End Line: 582

	/* begin block 2 */
		// Start line: 1354
	/* end block 2 */
	// End Line: 1355

void Pan_GetLandPos(_D3_OBJECT *obj,undefined out)

{
  int iVar1;
  int iVar2;
  undefined3 in_register_00000015;
  short *psVar3;
  
  psVar3 = (short *)CONCAT31(in_register_00000015,out);
  *psVar3 = (obj->pos).vx;
  psVar3[1] = (obj->pos).vy;
  psVar3[2] = (obj->pos).vz + *(short *)&obj[1].prec + 0x3c;
  if ((obj->collision_mode & 0x1000U) != 0) {
    iVar1 = rcos((int)(obj->rot).vz);
    iVar2 = rsin((int)(obj->rot).vz);
    *psVar3 = *psVar3 + (short)(iVar2 * -0xc >> 0xc);
    psVar3[1] = psVar3[1] + (short)(iVar1 * 0xc >> 0xc);
  }
  return;
}





