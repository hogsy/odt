#include "THISDUST.H"
#include "CDOOR2.H"


// decompiled code
// original method signature: 
// void /*$ra*/ Door_MIMe(struct _D3_OBJECT *D3Obj /*$s0*/, long testkey /*$s6*/)
 // line 64, offset 0x80056460
	/* begin block 1 */
		// Start line: 65
		// Start offset: 0x80056460
		// Variables:
	// 		unsigned long key; // $v0
	// 		long Zone_Result; // $s1
	// 		long speed; // $s2
	// 		long zoneattached; // $s5
	/* end block 1 */
	// End offset: 0x80056618
	// End Line: 113

	/* begin block 2 */
		// Start line: 128
	/* end block 2 */
	// End Line: 129

void Door_MIMe(_D3_OBJECT *D3Obj,long testkey)

{
  short sVar1;
  long lVar2;
  uint uVar3;
  long lVar4;
  uint unaff_s1;
  int speed;
  
  speed = (int)D3Obj[1].pos.vz;
  lVar2 = Zone_IsZoneAttached(D3Obj);
  if ((Pvl_SctState[(int)D3Obj->index] & 1U) != 0) {
    Door_End_MIMe(D3Obj,1);
    D3_ClearCollBits(D3Obj,1);
    Zone_DeleteObject(D3Obj);
    if (D3Obj[1].pos.pad == 0) {
      return;
    }
  }
  do {
    while( true ) {
      uVar3 = 0xffffffff;
      if (testkey != 0) {
        uVar3 = Scts_Interruptors;
      }
      if (((uVar3 & *(uint *)&D3Obj[1].last_pos) == *(uint *)&D3Obj[1].last_pos) &&
         ((((lVar4 = Task_EventRead(TaskCurrent), lVar4 == 2 && (lVar2 != 0)) ||
           ((D3Obj->collision_state & 1U) != 0)) && ((Pvl_SctState[(int)D3Obj->index] & 1U) == 0))))
      break;
      if (((unaff_s1 & 4) == 0) || ((Pvl_SctState[(int)D3Obj->index] & 1U) == 0)) {
        D3Obj->collision_state = D3Obj->collision_state & 0xfffe;
        Task_Next();
        unaff_s1 = Task_EventRead(TaskCurrent);
      }
      else {
        D3Obj->collision_state = D3Obj->collision_state & 0xfffe;
        unaff_s1 = Door_MIMe_Move(D3Obj,-speed);
      }
    }
    unaff_s1 = Door_MIMe_Move(D3Obj,speed);
    sVar1 = D3Obj[1].pos.pad;
  } while ((sVar1 != 0) && (sVar1 != 2));
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Door_MIMe_Move(struct _D3_OBJECT *D3Obj /*$s2*/, long speed /*$s3*/)
 // line 117, offset 0x80056640
	/* begin block 1 */
		// Start line: 118
		// Start offset: 0x80056640
		// Variables:
	// 		long nbFrame; // $s0
	// 		long coef; // $s1
	// 		long step; // $s4
	// 		struct CDOOR2_7fake *pvert; // $s6
	// 		long ReturnValue; // $s5
	/* end block 1 */
	// End offset: 0x8005678C
	// End Line: 160

	/* begin block 2 */
		// Start line: 235
	/* end block 2 */
	// End Line: 236

/* WARNING: Removing unreachable block (ram,0x800566d8) */

long Door_MIMe_Move(_D3_OBJECT *D3Obj,long speed)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  
  iVar2 = speed;
  if (speed < 0) {
    iVar2 = -speed;
  }
  lVar4 = 0;
  iVar3 = (uint)(speed < 1) << 0xc;
  Pvl_SctState[(int)D3Obj->index] = Pvl_SctState[(int)D3Obj->index] ^ 1;
  if (speed == 0) {
    trap(0x1c00);
  }
  D3_PlaySound(D3Obj,0);
  while (iVar2 = iVar2 + -1, iVar2 != -1) {
    iVar3 = iVar3 + 0x1000 / speed;
    uVar1 = Task_EventRead(TaskCurrent);
    if ((uVar1 & 5) != 0) {
      lVar4 = Task_EventRead(TaskCurrent);
    }
    GtxTmd_ApplyMIMe((uint **)D3Obj->description,iVar3);
    Task_Next();
  }
  if (D3Obj[1].pos.pad == 2) {
    if (-1 < speed) goto LAB_80056784;
  }
  else {
    if (speed < 0) {
LAB_80056784:
      D3_SetCollBits(D3Obj,1);
      return lVar4;
    }
  }
  D3_ClearCollBits(D3Obj,1);
  return lVar4;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Door_End_MIMe(struct _D3_OBJECT *D3Obj /*$a0*/, long mode /*$a1*/)
 // line 164, offset 0x800567bc
	/* begin block 1 */
		// Start line: 165
		// Start offset: 0x800567BC
	/* end block 1 */
	// End offset: 0x800567BC
	// End Line: 165

	/* begin block 2 */
		// Start line: 358
	/* end block 2 */
	// End Line: 359

void Door_End_MIMe(_D3_OBJECT *D3Obj,long mode)

{
  GtxTmd_ApplyMIMe((uint **)D3Obj->description,(uint)(mode != 0) << 0xc);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Traps_EngrenageRemove(struct _D3_OBJECT *D3Obj /*$s4*/)
 // line 226, offset 0x800567e8
	/* begin block 1 */
		// Start line: 227
		// Start offset: 0x800567E8
		// Variables:
	// 		long hilite; // $s1
	// 		long sens; // $s5
	// 		long trig; // $s3
	// 		struct _D3_OBJECT *obj; // $s0
	// 		struct CDOOR2_7fake *pos; // $a0
	// 		unsigned char col; // $s2
	// 		long TestZone; // $s6
	// 		struct CDOOR2_104fake t; // stack offset -72

		/* begin block 1.1 */
			// Start line: 401
			// Start offset: 0x80056C54
			// Variables:
		// 		short num_obj; // $v1
		/* end block 1.1 */
		// End offset: 0x80056CD8
		// End Line: 420
	/* end block 1 */
	// End offset: 0x80056CF8
	// End Line: 422

	/* begin block 2 */
		// Start line: 484
	/* end block 2 */
	// End Line: 485

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Traps_EngrenageRemove(_D3_OBJECT *D3Obj)

{
  char cVar1;
  short sVar2;
  int iVar3;
  long lVar4;
  uint uVar5;
  TASK *pTVar6;
  _func_27 **pp_Var7;
  _D3_OBJECT *o;
  int iVar8;
  undefined uVar9;
  uint uVar10;
  int iVar11;
  long lVar12;
  undefined auStack72 [32];
  
  pTVar6 = TaskCurrent;
  iVar8 = 0;
  iVar11 = 8;
  *(_D3_OBJECT **)&TaskCurrent->local = D3Obj;
  pTVar6->destructor = CB_LoopingSoundDestructor;
  Text_SetContext((TEXT_102fake *)auStack72);
  uVar10 = 0x80;
  Text_SetContextFont(0x70);
  Text_SetContextXY(0,0);
  lVar12 = 0;
  Text_SetContextWH(Scr_W,Scr_H);
  Text_SetContextRange(1);
  Text_SetContextMode(0);
  o = D3Obj->child;
  if (o != (_D3_OBJECT *)0x0) {
    do {
      iVar3 = (int)o[1].pos.vz;
      if (iVar3 == 0x4d) {
        pp_Var7 = (_func_27 **)&DAT_800a6c28;
      }
      else {
        pp_Var7 = &Shoot_TabFunctions[5].display + iVar3 * 2;
      }
      (o->pos).vx = (o->pos).vx + *(short *)pp_Var7;
      (o->pos).vy = (o->pos).vy + *(short *)((int)pp_Var7 + 2);
      (o->pos).vz = (o->pos).vz + *(short *)(pp_Var7 + 1);
      o = o->next;
    } while (o != (_D3_OBJECT *)0x0);
    o = D3Obj->child;
  }
  cVar1 = *(char *)((int)&o[1].pos.vx + 1);
  while (cVar1 != '\x03') {
    o = o->next;
    cVar1 = *(char *)((int)&o[1].pos.vx + 1);
  }
  lVar4 = Pvl_TestStateBits(o,1);
  if (lVar4 == 0) {
    lVar12 = Zone_IsZoneAttached(D3Obj);
    o->display_mode = o->display_mode | 0x10;
  }
  else {
    Zone_DeleteObject(D3Obj);
    o->display_mode = o->display_mode & 0xffef;
  }
  o = D3Obj->child;
  *(undefined4 *)&D3Obj[1].last_pos = 0xffffffff;
  while (o != (_D3_OBJECT *)0x0) {
    o = o->next;
  }
  do {
    uVar5 = Joy_ReadTrig(0);
    sVar2 = D3_UpdateSound(D3Obj,0,D3Obj[1].last_pos.vx);
    *(int *)&D3Obj[1].last_pos = (int)sVar2;
    if (lVar12 != 0) {
      lVar4 = Task_EventRead(TaskCurrent);
      if (lVar4 == 2) {
        if ((0 < iVar11) && (0xf7 < (uVar10 & 0xff))) {
          iVar11 = -8;
        }
        if ((iVar11 < 0) && ((uVar10 & 0xff) < 0x81)) {
          iVar11 = 8;
        }
        uVar10 = uVar10 + iVar11;
        iVar3 = iVar8;
        if ((uVar5 & 0x8000) != 0) {
          Fx_Play(0x40,100);
          uVar10 = 0xff;
          iVar3 = 10;
          if (iVar8 != 1) {
            iVar3 = iVar8 + -1;
          }
          if ((iVar3 == 4) || (iVar3 == 6)) {
            iVar3 = iVar3 + -1;
          }
        }
        iVar8 = iVar3;
        if ((uVar5 & 0x2000) != 0) {
          Fx_Play(0x40,100);
          uVar10 = 0xff;
          iVar8 = 1;
          if (iVar3 != 10) {
            iVar8 = iVar3 + 1;
          }
          if ((iVar8 == 4) || (iVar8 == 6)) {
            iVar8 = iVar8 + 1;
          }
        }
        if ((uVar5 & 0x5000) != 0) {
          _DAT_800b1d58 = 0;
          iVar8 = 0;
          iVar11 = 8;
          uVar10 = 0x80;
        }
        if ((uVar5 & (uint)PJOY_JUMP) != 0) {
          Inventaire.moving = '\0';
          _DAT_800b1d58 = 0;
          if (iVar8 == 8) {
            o = D3Obj->child;
            pTVar6 = o->handle;
            while (pTVar6 == (TASK *)0x0) {
              o = o->next;
              pTVar6 = o->handle;
            }
            Fx_Play(0x3e,100);
            sVar2 = Invent_AddObject((_PLAYER *)&Player,o);
            if (sVar2 != 0) {
              lVar12 = 0;
              Task_Next();
              Zone_DeleteObject(D3Obj);
              Pvl_SetStateBits(o,1);
              o->display_mode = o->display_mode & 0xffef;
            }
          }
          else {
            lVar12 = 0;
            Scts_Interruptors = Scts_Interruptors | (int)D3Obj[1].pos.pad;
            uVar10 = 0x80;
          }
        }
      }
      else {
        if (lVar4 < 3) {
          if (lVar4 == 1) {
            iVar11 = 8;
            Inventaire.moving = '\x01';
            iVar8 = 1;
            Overlay_SetText((char *)Pvl_Texts[(int)*(short *)((int)&D3Obj[1].prec + 2)]);
            _DAT_800b1d58 = 1;
          }
          else {
            uVar10 = 0x80;
          }
        }
        else {
          uVar10 = 0x80;
          if (lVar4 == 4) {
            Inventaire.moving = '\0';
          }
        }
      }
    }
    o = D3Obj->child;
    (D3Obj->rot).vy = (D3Obj->rot).vy + (short)PTR_DAT_800a6bee;
    while (o != (_D3_OBJECT *)0x0) {
      sVar2 = o[1].pos.vz + -1;
      if (o[1].pos.vz == 0x4d) {
        sVar2 = 8;
      }
      if (iVar8 == (int)sVar2) {
        uVar9 = (undefined)uVar10;
        *(undefined *)&o->color = uVar9;
        *(undefined *)((int)&o->color + 1) = uVar9;
        *(undefined *)((int)&o->color + 2) = uVar9;
      }
      else {
        o->color = 0x808080;
      }
      iVar3 = (int)sVar2;
      if (iVar3 < 7) {
        (o->rot).vy = (o->rot).vy + *(short *)(&PTR_DAT_800a6bee + iVar3 * 2);
      }
      else {
        (o->rot).vx = (o->rot).vx + *(short *)(&PTR_DAT_800a6bee + iVar3 * 2);
      }
      o = o->next;
    }
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Traps_EngrenageAdd(struct _D3_OBJECT *D3Obj /*$s2*/)
 // line 425, offset 0x80056cf8
	/* begin block 1 */
		// Start line: 426
		// Start offset: 0x80056CF8
		// Variables:
	// 		struct _D3_OBJECT *obj; // $a1
	// 		struct _D3_OBJECT *missing; // $s1
	// 		struct CDOOR2_7fake *pos; // $a0
	// 		long Added; // $s0
	// 		struct CDOOR2_104fake t; // stack offset -56
	/* end block 1 */
	// End offset: 0x80056EF8
	// End Line: 494

	/* begin block 2 */
		// Start line: 1050
	/* end block 2 */
	// End Line: 1051

void Traps_EngrenageAdd(_D3_OBJECT *D3Obj)

{
  bool bVar1;
  long lVar2;
  int iVar3;
  _D3_OBJECT *p_Var4;
  _D3_OBJECT *o;
  undefined auStack56 [32];
  
  Text_SetContext((TEXT_102fake *)auStack56);
  Text_SetContextFont(0x70);
  Text_SetContextXY(0,0);
  Text_SetContextWH(Scr_W,Scr_H);
  Text_SetContextRange(1);
  Text_SetContextMode(0);
  p_Var4 = D3Obj->child;
  while (p_Var4 != (_D3_OBJECT *)0x0) {
    if (p_Var4[1].pos.vz == 4) {
      p_Var4->display_mode = p_Var4->display_mode & 0xffef;
      o = p_Var4;
    }
    iVar3 = (int)p_Var4[1].pos.vz * 8;
    (p_Var4->pos).vx = (p_Var4->pos).vx + *(short *)(&DAT_800a6c48 + iVar3);
    (p_Var4->pos).vz = (p_Var4->pos).vz + *(short *)(&DAT_800a6c4c + iVar3);
    p_Var4 = p_Var4->next;
  }
  lVar2 = Pvl_TestStateBits(o,1);
  bVar1 = lVar2 != 0;
  if (bVar1) {
    o->display_mode = o->display_mode | 0x10;
  }
  do {
    lVar2 = Task_EventRead(TaskCurrent);
    if (lVar2 == 1) {
      if (!bVar1) {
        Overlay_SetText((char *)Pvl_Texts[(int)*(short *)((int)&D3Obj[1].prec + 2)]);
      }
    }
    else {
      if (lVar2 == 6) {
        o->display_mode = o->display_mode | 0x10;
        Pvl_SetStateBits(o,1);
        Scts_Interruptors = Scts_Interruptors | (int)D3Obj[1].pos.pad;
        bVar1 = true;
      }
    }
    p_Var4 = D3Obj->child;
    (D3Obj->rot).vy = (D3Obj->rot).vy + (short)PTR_DAT_800a6c56;
    while (p_Var4 != (_D3_OBJECT *)0x0) {
      if (bVar1) {
        (p_Var4->rot).vy =
             (p_Var4->rot).vy + *(short *)(&PTR_DAT_800a6c56 + ((int)p_Var4[1].pos.vz + -1) * 2);
      }
      p_Var4 = p_Var4->next;
    }
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Traps_Pipette(struct _D3_OBJECT *D3Obj /*$s5*/)
 // line 508, offset 0x80056ef8
	/* begin block 1 */
		// Start line: 509
		// Start offset: 0x80056EF8
		// Variables:
	// 		struct _D3_OBJECT *eau; // $s4
	// 		struct _ZONE *z; // $fp
	// 		long dumpLevels; // $s7
	// 		long nLevels; // $s2
	// 		long nMoving; // $s6
	// 		long FirstTime; // stack offset -48

		/* begin block 1.1 */
			// Start line: 547
			// Start offset: 0x80056FE4
			// Variables:
		// 		long i; // $s0
		// 		long step; // $s3
		// 		long end; // $s1
		/* end block 1.1 */
		// End offset: 0x800570E0
		// End Line: 589
	/* end block 1 */
	// End offset: 0x800570F0
	// End Line: 593

	/* begin block 2 */
		// Start line: 1245
	/* end block 2 */
	// End Line: 1246

void Traps_Pipette(_D3_OBJECT *D3Obj)

{
  bool bVar1;
  TASK *pTVar2;
  short sVar3;
  long nMoving;
  _ZONE *t;
  int iVar4;
  int iVar5;
  int LevelZ;
  _D3_OBJECT *o;
  int iVar6;
  
  pTVar2 = TaskCurrent;
  bVar1 = true;
  *(_D3_OBJECT **)&TaskCurrent->local = D3Obj;
  pTVar2->destructor = CB_LoopingSoundDestructor;
  o = D3Obj->child;
  iVar6 = 0;
  while ((o != (_D3_OBJECT *)0x0 && (*(char *)((int)&o[1].pos.vx + 1) != '\0'))) {
    o = o->next;
  }
  nMoving = Pipette_FindMovingVertices(o);
  Pipette_ChangeWater(o,-0x96,nMoving);
  t = Zone_GetObjectZone(D3Obj);
  *(undefined4 *)&D3Obj[1].last_pos = 0xffffffff;
  do {
    iVar4 = Pipette_GetNbLevels(D3Obj);
    sVar3 = D3_UpdateSound(D3Obj,0,D3Obj[1].last_pos.vx);
    *(int *)&D3Obj[1].last_pos = (int)sVar3;
    if (iVar6 != iVar4) {
      if (bVar1) {
        bVar1 = false;
      }
      else {
        LevelZ = (iVar6 + -10) * 0xf;
        Pipette_SetWater(o,LevelZ,nMoving);
        while (iVar4 == LevelZ) {
          iVar4 = Pipette_GetNbLevels(D3Obj);
          Task_Next();
        }
      }
      LevelZ = -1;
      Pipette_SetWater(o,(iVar6 + -10) * 0xf,nMoving);
      if (0 < iVar4 - iVar6) {
        LevelZ = 1;
      }
      iVar6 = (iVar4 - iVar6) * 0xf;
      if ((t != (_ZONE *)0x0) && (-1 < t->camera)) {
        Track_SetMode(10,(long)t);
      }
      iVar5 = 0;
      if (iVar6 != 0) {
        do {
          Pipette_ChangeWater(o,LevelZ,nMoving);
          iVar5 = iVar5 + LevelZ;
          Task_Next();
        } while (iVar5 != iVar6);
      }
      iVar6 = iVar4;
      if (iVar4 == 10) {
        Scts_Interruptors = Scts_Interruptors | (int)D3Obj[1].pos.vz;
        iVar6 = iVar4;
      }
    }
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// long /*$ra*/ Pipette_FindMovingVertices(struct _D3_OBJECT *o /*$a0*/)
 // line 596, offset 0x800570f0
	/* begin block 1 */
		// Start line: 598
		// Start offset: 0x800570F0
		// Variables:
	// 		long i; // $v1
	// 		long IndMid; // $a2
	// 		long nVert; // $a3
	// 		struct CDOOR2_7fake *pVert; // $a1
	/* end block 1 */
	// End offset: 0x8005714C
	// End Line: 610

	/* begin block 2 */
		// Start line: 1445
	/* end block 2 */
	// End Line: 1446

long Pipette_FindMovingVertices(_D3_OBJECT *o)

{
  int iVar1;
  int iVar2;
  long *plVar3;
  int iVar4;
  long lVar5;
  int iVar6;
  
  iVar2 = 0;
  iVar6 = *(int *)(o->description + 1);
  iVar4 = *(int *)o->description;
  lVar5 = 0;
  if (0 < iVar6) {
    plVar3 = &Pipette_TabVertMid;
    do {
      iVar1 = (int)*(short *)(iVar4 + 4);
      if (iVar1 < 0) {
        iVar1 = -iVar1;
      }
      if (iVar1 < 1) {
        *plVar3 = iVar2;
        plVar3 = plVar3 + 1;
        lVar5 = lVar5 + 1;
      }
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 + 8;
    } while (iVar2 < iVar6);
  }
  return lVar5;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pipette_SetWater(struct _D3_OBJECT *o /*$a0*/, long LevelZ /*$a1*/, long nMoving /*$a2*/)
 // line 614, offset 0x80057154
	/* begin block 1 */
		// Start line: 616
		// Start offset: 0x80057154
		// Variables:
	// 		int i; // $v1
	// 		struct CDOOR2_7fake *Vertices; // $a3
	/* end block 1 */
	// End offset: 0x80057190
	// End Line: 621

	/* begin block 2 */
		// Start line: 1484
	/* end block 2 */
	// End Line: 1485

void Pipette_SetWater(_D3_OBJECT *o,long LevelZ,long nMoving)

{
  int iVar1;
  long *plVar2;
  int iVar3;
  
  iVar3 = *(int *)o->description;
  iVar1 = 0;
  if (0 < nMoving) {
    plVar2 = &Pipette_TabVertMid;
    do {
      iVar1 = iVar1 + 1;
      *(undefined2 *)(*plVar2 * 8 + iVar3 + 4) = (short)LevelZ;
      plVar2 = plVar2 + 1;
    } while (iVar1 < nMoving);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pipette_ChangeWater(struct _D3_OBJECT *o /*$a0*/, long diffZ /*$a1*/, long nMoving /*$a2*/)
 // line 624, offset 0x80057198
	/* begin block 1 */
		// Start line: 626
		// Start offset: 0x80057198
		// Variables:
	// 		int i; // $a0
	// 		struct CDOOR2_7fake *Vertices; // $t0
	/* end block 1 */
	// End offset: 0x800571E0
	// End Line: 631

	/* begin block 2 */
		// Start line: 1506
	/* end block 2 */
	// End Line: 1507

void Pipette_ChangeWater(_D3_OBJECT *o,long diffZ,long nMoving)

{
  int iVar1;
  int iVar2;
  long *plVar3;
  int iVar4;
  
  iVar4 = *(int *)o->description;
  iVar2 = 0;
  if (0 < nMoving) {
    plVar3 = &Pipette_TabVertMid;
    do {
      iVar1 = *plVar3 * 8 + iVar4;
      iVar2 = iVar2 + 1;
      *(short *)(iVar1 + 4) = *(short *)(iVar1 + 4) + (short)diffZ;
      plVar3 = plVar3 + 1;
    } while (iVar2 < nMoving);
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Pipette_GetNbLevels(struct _D3_OBJECT *o /*$a0*/)
 // line 634, offset 0x800571e8
	/* begin block 1 */
		// Start line: 636
		// Start offset: 0x800571E8
		// Variables:
	// 		struct _D3_OBJECT *child; // $v1
	// 		long sum; // $a0
	/* end block 1 */
	// End offset: 0x80057248
	// End Line: 651

	/* begin block 2 */
		// Start line: 1527
	/* end block 2 */
	// End Line: 1528

long Pipette_GetNbLevels(_D3_OBJECT *o)

{
  _D3_OBJECT *p_Var1;
  int iVar2;
  
  p_Var1 = o->child;
  iVar2 = 0;
  while (p_Var1 != (_D3_OBJECT *)0x0) {
    if (*(char *)((int)&p_Var1[1].pos.vx + 1) == '\a') {
      iVar2 = iVar2 + (int)p_Var1[1].pos.pad;
    }
    p_Var1 = p_Var1->next;
  }
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  if (0x14 < iVar2) {
    iVar2 = 0x14;
  }
  return iVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Traps_LameCirc(struct _D3_OBJECT *D3Obj /*$s2*/)
 // line 659, offset 0x80057250
	/* begin block 1 */
		// Start line: 660
		// Start offset: 0x80057250
		// Variables:
	// 		struct _D3_OBJECT *child; // $s1
	// 		struct _D3_OBJECT *bchild; // $s0
	// 		struct CDOOR2_7fake rot; // stack offset -48
	// 		struct CDOOR2_7fake trans; // stack offset -40
	// 		long i; // $s0
	// 		long axe; // $s6
	// 		long time; // $s5
	// 		long speed; // $v1
	// 		long dist; // $s4
	/* end block 1 */
	// End offset: 0x80057524
	// End Line: 730

	/* begin block 2 */
		// Start line: 1576
	/* end block 2 */
	// End Line: 1577

void Traps_LameCirc(_D3_OBJECT *D3Obj)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  _D3_OBJECT *o;
  _D3_OBJECT *o_00;
  short sVar5;
  int iVar6;
  uint uVar7;
  undefined auStack48 [4];
  short local_2c;
  short local_28;
  short local_26;
  
  o_00 = D3Obj->child;
  memset(auStack48,0,8);
  memset(&local_28,0,8);
  iVar2 = (int)D3Obj[1].pos.vz;
  iVar6 = (int)*(uint *)&D3Obj[1].last_pos >> 0x10;
  if (iVar2 == 0) {
    trap(0x1c00);
  }
  if ((iVar2 == -1) && (iVar6 == -0x80000000)) {
    trap(0x1800);
  }
  uVar7 = *(uint *)&D3Obj[1].last_pos & 0xffff;
  iVar1 = (iVar6 / iVar2) * 0x1e;
  if (iVar1 < 0) {
    iVar1 = (iVar6 / iVar2) * -0x1e;
  }
  if (o_00 != (_D3_OBJECT *)0x0) {
    sVar5 = 0;
    do {
      (o_00->rot).vz = (D3Obj->rot).vz + sVar5;
      uVar4 = *(undefined4 *)&(D3Obj->pos).vz;
      *(undefined4 *)&o_00->pos = *(undefined4 *)&D3Obj->pos;
      *(undefined4 *)&(o_00->pos).vz = uVar4;
      D3_SetCollBits(o_00,(long)&DAT_0000200a);
      o = o_00->child;
      if (o != (_D3_OBJECT *)0x0) {
        D3_ClearCollBits(o,1);
        uVar4 = *(undefined4 *)&(D3Obj->pos).vz;
        *(undefined4 *)&o->pos = *(undefined4 *)&D3Obj->pos;
        *(undefined4 *)&(o->pos).vz = uVar4;
        (o->rot).vz = (o_00->rot).vz;
      }
      o_00 = o_00->next;
      sVar5 = sVar5 + 0x555;
    } while (o_00 != (_D3_OBJECT *)0x0);
  }
  D3_ClearCollBits(D3Obj,1);
  local_2c = 0x71;
  if (uVar7 == 0) {
    if (iVar1 == 0) {
      trap(0x1c00);
    }
    if ((iVar1 == -1) && (iVar6 * 100 == -0x80000000)) {
      trap(0x1800);
    }
    local_28 = (short)((uint)((iVar6 * 100) / iVar1) >> 8);
  }
  else {
    if (iVar1 == 0) {
      trap(0x1c00);
    }
    if ((iVar1 == -1) && (iVar6 * 100 == -0x80000000)) {
      trap(0x1800);
    }
    local_26 = (short)((uint)((iVar6 * 100) / iVar1) >> 8);
  }
  uVar3 = SEXT24(D3Obj[1].pos.pad);
  iVar2 = iVar1;
  if (uVar3 != 0) {
    while (iVar2 = iVar1, (Scts_Interruptors & uVar3) == 0) {
      Task_Next();
      uVar3 = SEXT24(D3Obj[1].pos.pad);
    }
  }
  do {
    while (iVar2 == 0) {
      if (uVar7 == 0) {
        local_28 = -local_28;
        iVar2 = iVar1;
      }
      else {
        local_26 = -local_26;
        iVar2 = iVar1;
      }
    }
    o_00 = D3Obj->child;
    (D3Obj->rot).vz = (D3Obj->rot).vz + local_2c;
    D3_RotList(o_00,0xd0);
    if (uVar7 == 0) {
      (D3Obj->pos).vx = (D3Obj->pos).vx + local_28;
    }
    else {
      (D3Obj->pos).vy = (D3Obj->pos).vy + local_26;
    }
    D3_MoveList(D3Obj->child,0xd8);
    Task_Next();
    iVar2 = iVar2 + -1;
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Traps_VoletEau(struct _D3_OBJECT *D3Obj /*$s1*/)
 // line 790, offset 0x80057524
	/* begin block 1 */
		// Start line: 791
		// Start offset: 0x80057524
		// Variables:
	// 		struct TASK *Handle_Fall; // $s5
	// 		struct _D3_OBJECT *roue; // $s3
	// 		struct CDOOR2_9fake Tab2D[5]; // stack offset -96
	// 		struct CDOOR2_7fake pos; // stack offset -72
	// 		long TabZ[5]; // stack offset -64
	// 		long FlagRot; // stack offset -40
	// 		long FlagPos; // stack offset -36
	// 		long cpt; // $s0
	// 		long NbFalls; // $s2
	// 		long fx_handle; // $s4

		/* begin block 1.1 */
			// Start line: 834
			// Start offset: 0x8005764C
		/* end block 1.1 */
		// End offset: 0x8005764C
		// End Line: 836
	/* end block 1 */
	// End offset: 0x80057714
	// End Line: 867

	/* begin block 2 */
		// Start line: 1862
	/* end block 2 */
	// End Line: 1863

void Traps_VoletEau(_D3_OBJECT *D3Obj)

{
  short snd_handle;
  long lVar1;
  _D3_OBJECT *p_Var2;
  TASK *handle;
  short *psVar3;
  short *psVar4;
  short *psVar5;
  int iVar6;
  long NbFalls;
  uint local_28;
  long local_24;
  
  NbFalls = 0;
  local_28 = 0xc;
  local_24 = 0;
  lVar1 = Pvl_TestStateBits(D3Obj,1);
  iVar6 = 0;
  if (lVar1 != 0) {
    psVar5 = &Volets_TabRot;
    psVar3 = &Volets_TabPos;
    psVar4 = &Volets_PosX;
    do {
      snd_handle = *psVar4;
      psVar4 = psVar4 + 1;
      iVar6 = iVar6 + 1;
      *psVar3 = snd_handle;
      snd_handle = *psVar5;
      psVar5 = psVar5 + 1;
      psVar3[3] = snd_handle;
      psVar3 = psVar3 + 4;
    } while (iVar6 < 5);
    local_28 = 0x1f;
    local_24 = 0x1f;
  }
  Scts_Interruptors = Scts_Interruptors | local_28;
  p_Var2 = Volets_Init(D3Obj);
  iVar6 = 3;
  snd_handle = -1;
  handle = SFX_StreamWaterFall(0xb8);
  do {
    snd_handle = D3_UpdateSound(D3Obj,1,snd_handle);
    if (NbFalls == 7) {
      (p_Var2->rot).vy = (p_Var2->rot).vy + -10;
      Pvl_SetStateBits(D3Obj,1);
      Scts_Interruptors = Scts_Interruptors | (int)D3Obj[1].pos.vz;
    }
    else {
      Pvl_ClearStateBits(D3Obj,1);
      Scts_Interruptors = Scts_Interruptors & ~(int)D3Obj[1].pos.vz;
    }
    Volets_CheckRot(D3Obj,(long *)&local_28);
    Volets_CheckPos(D3Obj,&local_24);
    NbFalls = Volets_GetNbFalls(local_28,local_24);
    Volets_SetVisibleFalls(D3Obj,NbFalls);
    Volets_SetStream(D3Obj,handle,NbFalls);
    if (iVar6 == 0) {
      iVar6 = 3;
      Volets_Impacts(D3Obj,NbFalls);
    }
    iVar6 = iVar6 + -1;
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// struct _D3_OBJECT * /*$ra*/ Volets_Init(struct _D3_OBJECT *D3Obj /*$s2*/)
 // line 870, offset 0x80057714
	/* begin block 1 */
		// Start line: 871
		// Start offset: 0x80057714
		// Variables:
	// 		struct _D3_OBJECT *child; // $s1
	// 		struct _D3_OBJECT *bchild; // $a2
	// 		struct _D3_OBJECT *roue; // $s3
	// 		struct M_OBJECT *mo; // $s0
	// 		long index; // $a0
	/* end block 1 */
	// End offset: 0x800578AC
	// End Line: 926

	/* begin block 2 */
		// Start line: 2058
	/* end block 2 */
	// End Line: 2059

_D3_OBJECT * Volets_Init(_D3_OBJECT *D3Obj)

{
  char cVar1;
  int iVar2;
  _D3_OBJECT *p_Var3;
  M_OBJECT *obj;
  _D3_OBJECT *o;
  _D3_OBJECT *unaff_s3;
  
  o = D3Obj->child;
  while (o != (_D3_OBJECT *)0x0) {
    cVar1 = *(char *)((int)&o[1].pos.vx + 1);
    if (cVar1 == '\0') {
      (o->pos).vx = (D3Obj->pos).vx + DAT_800a6ce8;
      (o->pos).vy = (D3Obj->pos).vy + DAT_800a6cea;
      (o->pos).vz = (D3Obj->pos).vz + DAT_800a6cec;
      unaff_s3 = o;
    }
    else {
      if ((*(uint *)&o[1].pos & 0xffffff00) == 0x50700) {
        iVar2 = (int)o[1].last_pos.vy;
        p_Var3 = o->child;
        (p_Var3->pos).vx = (D3Obj->pos).vx + (&Volets_TabPos)[iVar2 * 4];
        (p_Var3->pos).vy = (D3Obj->pos).vy + *(short *)(&DAT_800a6cc2 + iVar2 * 8);
        (p_Var3->pos).vz = (D3Obj->pos).vz + *(short *)(&DAT_800a6cc4 + iVar2 * 8);
        (p_Var3->rot).vy = (&DAT_800a6cc6)[iVar2 * 4];
        p_Var3[1].pos.pad = (D3Obj->pos).vx + Volets_TabLimits[iVar2 * 2];
        *(int *)&p_Var3[1].last_pos =
             (int)(D3Obj->pos).vx + (int)*(short *)((int)Volets_TabLimits + (iVar2 << 2 | 2U));
      }
      else {
        if ((cVar1 == '\a') && (((int)o[1].pos.vz & Scts_Interruptors) != 0)) {
          obj = (M_OBJECT *)o->description;
          Pvl_SetStateBits(o,2);
          Manim_GoToFrame(obj,(uint)*(ushort *)
                                     (*(int *)(*(int *)((obj->Sq).Data.FatherTrans + 2) + 8) + 6) -
                              1);
        }
      }
    }
    o = o->next;
  }
  return unaff_s3;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Volets_Impacts(struct _D3_OBJECT *o /*$s2*/, long NbImpacts /*$s3*/)
 // line 930, offset 0x800578d4
	/* begin block 1 */
		// Start line: 931
		// Start offset: 0x800578D4
		// Variables:
	// 		struct CDOOR2_8fake col; // stack offset -40
	// 		struct CDOOR2_7fake pos; // stack offset -32
	// 		long i; // $s1
	/* end block 1 */
	// End offset: 0x80057974
	// End Line: 944

	/* begin block 2 */
		// Start line: 2186
	/* end block 2 */
	// End Line: 2187

void Volets_Impacts(_D3_OBJECT *o,long NbImpacts)

{
  bool bVar1;
  int iVar2;
  
  if (0 < NbImpacts) {
    iVar2 = 1;
    do {
      Impact_Rain(0xe0,0xd8,5);
      bVar1 = iVar2 < NbImpacts;
      iVar2 = iVar2 + 1;
    } while (bVar1);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Volets_CheckRot(struct _D3_OBJECT *o /*$s1*/, long *FlagRot /*$a3*/)
 // line 947, offset 0x80057990
	/* begin block 1 */
		// Start line: 948
		// Start offset: 0x80057990
		// Variables:
	// 		struct TASK *handle; // $v0
	// 		long i; // $s0
	// 		long mask; // $v1
	/* end block 1 */
	// End offset: 0x80057A6C
	// End Line: 977

	/* begin block 2 */
		// Start line: 2242
	/* end block 2 */
	// End Line: 2243

void Volets_CheckRot(_D3_OBJECT *o,long *FlagRot)

{
  TASK *pTVar1;
  uint uVar2;
  short *psVar3;
  undefined2 *puVar4;
  int iVar5;
  
  uVar2 = 1;
  iVar5 = 0;
  psVar3 = &Volets_TabRot;
  puVar4 = &Volets_TabPos;
  do {
    if ((Scts_Interruptors & uVar2) == 0) {
      if ((*FlagRot & uVar2) != 0) {
        puVar4[3] = -*psVar3;
        uVar2 = *FlagRot & ~uVar2;
        goto LAB_80057a40;
      }
    }
    else {
      if ((*FlagRot & uVar2) == 0) {
        puVar4[3] = *psVar3;
        uVar2 = *FlagRot | uVar2;
LAB_80057a40:
        *FlagRot = uVar2;
        pTVar1 = Task_Link(Volets_RotateTask,0x100);
        *(_D3_OBJECT **)&pTVar1->local = o;
        pTVar1->s0 = iVar5;
        return;
      }
    }
    uVar2 = uVar2 << 1;
    psVar3 = psVar3 + 1;
    iVar5 = iVar5 + 1;
    puVar4 = puVar4 + 4;
    if (4 < iVar5) {
      return;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Volets_CheckPos(struct _D3_OBJECT *o /*$t2*/, long *FlagPos /*$a1*/)
 // line 980, offset 0x80057a80
	/* begin block 1 */
		// Start line: 981
		// Start offset: 0x80057A80
		// Variables:
	// 		struct _D3_OBJECT *child; // $v1
	// 		struct _D3_OBJECT *bchild; // $a0
	// 		long cpt; // $a2
	// 		long mask; // $a3
	/* end block 1 */
	// End offset: 0x80057B48
	// End Line: 1010

	/* begin block 2 */
		// Start line: 2343
	/* end block 2 */
	// End Line: 2344

void Volets_CheckPos(_D3_OBJECT *o,long *FlagPos)

{
  uint uVar1;
  _D3_OBJECT *p_Var2;
  int iVar3;
  uint uVar4;
  
  iVar3 = 0;
  uVar4 = 1;
  do {
    p_Var2 = o->child;
    if (p_Var2 != (_D3_OBJECT *)0x0) {
      do {
        if (((*(uint *)&p_Var2[1].pos & 0xffffff00) == 0x50700) &&
           (iVar3 == (int)p_Var2[1].last_pos.vy)) {
          if (((int)(p_Var2->child->pos).vx == (int)(&Volets_PosX)[iVar3] + (int)(o->pos).vx) ||
             (iVar3 == 4)) {
            uVar1 = *FlagPos | uVar4;
          }
          else {
            uVar1 = *FlagPos & ~uVar4;
          }
          *FlagPos = uVar1;
          iVar3 = iVar3 + 1;
          uVar4 = uVar4 << 1;
          break;
        }
        p_Var2 = p_Var2->next;
      } while (p_Var2 != (_D3_OBJECT *)0x0);
    }
    if (4 < iVar3) {
      return;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// long /*$ra*/ Volets_GetNbFalls(long FlagRot /*$a0*/, long FlagPos /*$a1*/)
 // line 1013, offset 0x80057b50
	/* begin block 1 */
		// Start line: 1015
		// Start offset: 0x80057B50
		// Variables:
	// 		long mask; // $a3
	// 		long i; // $a2
	// 		long nbRot; // $t0
	// 		long nbPos; // $v1
	/* end block 1 */
	// End offset: 0x80057C38
	// End Line: 1065

	/* begin block 2 */
		// Start line: 2410
	/* end block 2 */
	// End Line: 2411

long Volets_GetNbFalls(long FlagRot,long FlagPos)

{
  long lVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar3 = 0;
  uVar4 = 1;
  do {
    iVar5 = iVar3;
    if ((uVar4 & FlagRot) == 0) break;
    iVar3 = iVar3 + 1;
    uVar4 = uVar4 << 1;
    iVar5 = 0;
  } while (iVar3 < 6);
  uVar4 = 1;
  iVar3 = 0;
  do {
    iVar2 = iVar3;
    if ((uVar4 & FlagPos) == 0) break;
    iVar3 = iVar2 + 1;
    uVar4 = uVar4 << 1;
    iVar2 = 0;
  } while (iVar3 < 6);
  switch(iVar2) {
  case 0:
    return 0;
  case 1:
    return 1;
  case 2:
    if (0 < iVar5) {
      return 2;
    }
    return 1;
  case 3:
    lVar1 = 4;
    break;
  case 4:
    lVar1 = 5;
    break;
  case 5:
    if ((iVar5 < 6) && (2 < iVar5)) {
      return iVar5 + 2;
    }
    goto LAB_80057bfc;
  default:
    return 0;
  }
  if (2 < iVar5) {
    return lVar1;
  }
LAB_80057bfc:
  return iVar5 + 1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Volets_SetVisibleFalls(struct _D3_OBJECT *o /*$a0*/, long NbFalls /*$a1*/)
 // line 1068, offset 0x80057c40
	/* begin block 1 */
		// Start line: 1070
		// Start offset: 0x80057C40
		// Variables:
	// 		struct _D3_OBJECT *child; // $v1
	/* end block 1 */
	// End offset: 0x80057CA4
	// End Line: 1085

	/* begin block 2 */
		// Start line: 2539
	/* end block 2 */
	// End Line: 2540

void Volets_SetVisibleFalls(_D3_OBJECT *o,long NbFalls)

{
  ushort uVar1;
  _D3_OBJECT *p_Var2;
  
  p_Var2 = o->child;
  while (p_Var2 != (_D3_OBJECT *)0x0) {
    if (*(char *)((int)&p_Var2[1].pos.vx + 1) == '\x01') {
      if (NbFalls < (int)p_Var2[1].last_pos.vy) {
        uVar1 = p_Var2->display_mode & 0xffef;
      }
      else {
        uVar1 = p_Var2->display_mode | 0x10;
      }
      p_Var2->display_mode = uVar1;
    }
    p_Var2 = p_Var2->next;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Volets_RotateTask()
 // line 1088, offset 0x80057cac
	/* begin block 1 */
		// Start line: 1089
		// Start offset: 0x80057CAC
		// Variables:
	// 		struct _D3_OBJECT *o; // $a0
	// 		struct _D3_OBJECT *child; // $s0
	// 		long numobj; // $a1
	// 		long i; // $s1
	// 		long angle; // $s3
	// 		long step; // $s2
	// 		long nbf; // $s1
	/* end block 1 */
	// End offset: 0x80057D98
	// End Line: 1123

	/* begin block 2 */
		// Start line: 2579
	/* end block 2 */
	// End Line: 2580

/* WARNING: Removing unreachable block (ram,0x80057d4c) */
/* WARNING: Removing unreachable block (ram,0x80057d5c) */
/* WARNING: Removing unreachable block (ram,0x80057d64) */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Volets_RotateTask(void)

{
  short sVar1;
  _D3_OBJECT *p_Var2;
  int iVar3;
  
  p_Var2 = ((_D3_OBJECT *)TaskCurrent->local)->child;
  iVar3 = 0x3c;
  do {
    if (p_Var2 == (_D3_OBJECT *)0x0) {
LAB_80057d30:
      sVar1 = (p_Var2->rot).vy;
      D3_PlaySound((_D3_OBJECT *)TaskCurrent->local,0);
      do {
        iVar3 = iVar3 + -1;
        (p_Var2->rot).vy = (p_Var2->rot).vy + (short)(((int)sVar1 * -2) / 0x3c);
        Task_Next();
      } while (iVar3 != 0);
      (p_Var2->rot).vy = -sVar1;
      return;
    }
    if (((*(uint *)&p_Var2[1].pos & 0xffffff00) == 0x50700) &&
       (TaskCurrent->s0 == (int)p_Var2[1].last_pos.vy)) {
      p_Var2 = p_Var2->child;
      goto LAB_80057d30;
    }
    p_Var2 = p_Var2->next;
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Volets_SetStream(struct _D3_OBJECT *o /*$a3*/, struct TASK *handle /*$a1*/, long NbFalls /*$a2*/)
 // line 1127, offset 0x80057db8
	/* begin block 1 */
		// Start line: 1128
		// Start offset: 0x80057DB8
		// Variables:
	// 		struct CDOOR2_7fake pos; // stack offset -8
	/* end block 1 */
	// End offset: 0x80057F0C
	// End Line: 1151

	/* begin block 2 */
		// Start line: 2662
	/* end block 2 */
	// End Line: 2663

/* WARNING: Could not reconcile some variable overlaps */

void Volets_SetStream(_D3_OBJECT *o,TASK *handle,long NbFalls)

{
  undefined4 local_8;
  short local_4;
  
  *(ushort *)&handle[1].s7 = *(ushort *)&handle[1].s7 & 0xfffb;
  switch(NbFalls) {
  case 1:
  case 2:
    local_8 = (&Volets_FallPos)[NbFalls * 2];
    local_4 = (short)(&DAT_800a6d40)[NbFalls * 2];
    if ((short)(&DAT_800a6cc6)[(NbFalls + -1) * 4] < 0) {
      local_8 = local_8 & 0xffff0000 | (uint)(ushort)((short)local_8 - 0x78);
    }
    break;
  case 3:
  case 4:
  case 5:
  case 6:
    local_8 = (&Volets_FallPos)[NbFalls * 2];
    local_4 = (short)(&DAT_800a6d40)[NbFalls * 2];
    break;
  case 7:
    *(ushort *)&handle[1].s7 = *(ushort *)&handle[1].s7 | 4;
    return;
  default:
    local_8 = Volets_FallPos;
    local_4 = (short)DAT_800a6d40;
  }
  *(short *)&(handle[1].bprec)->prec = (short)local_8 + (o->pos).vx;
  *(short *)((int)&(handle[1].bprec)->prec + 2) = local_8._2_2_ + (o->pos).vy;
  *(short *)&(handle[1].bprec)->next = local_4 + (o->pos).vz;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_ColumnDragon(struct _D3_OBJECT *o /*$s2*/)
 // line 1158, offset 0x80057f14
	/* begin block 1 */
		// Start line: 1159
		// Start offset: 0x80057F14
		// Variables:
	// 		struct _D3_OBJECT *child; // $s0
	// 		long numPart; // $s1
	// 		long height; // $s3
	// 		long hit_points; // $s5

		/* begin block 1.1 */
			// Start line: 1196
			// Start offset: 0x80057FDC
		/* end block 1.1 */
		// End offset: 0x80057FE8
		// End Line: 1199
	/* end block 1 */
	// End offset: 0x8005801C
	// End Line: 1210

	/* begin block 2 */
		// Start line: 2727
	/* end block 2 */
	// End Line: 2728

void CB_ColumnDragon(_D3_OBJECT *o)

{
  short sVar1;
  short sVar2;
  TASK *pTVar3;
  _D3_OBJECT *o_00;
  int num_child;
  
  o_00 = o->child;
  num_child = 1;
  while (o_00 != (_D3_OBJECT *)0x0) {
    o_00->comp_opt1 = 1;
    D3_ClearCollBits(o_00,1);
    o_00 = o_00->next;
    num_child = num_child + 1;
  }
  sVar1 = *(short *)&o[1].prec;
  CB_ColumnSetHighBoxZ(o,(int)sVar1,num_child);
  sVar2 = o->hit_points;
  o->comp_opt1 = 1;
  do {
    if (o->hit_points < 10) {
      if (num_child == 0) {
        D3_ExplodeObject(o);
        return;
      }
      o_00 = o->child;
      o->hit_points = sVar2;
      while (o_00 != (_D3_OBJECT *)0x0) {
        if ((int)o_00[1].pos.vz == num_child) {
          pTVar3 = Task_Add(CB_ColumnFall,0);
          *(_D3_OBJECT **)&pTVar3->local = o_00;
        }
        o_00 = o_00->next;
      }
      num_child = num_child + -1;
      CB_ColumnSetHighBoxZ(o,(int)sVar1,num_child);
    }
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_ColumnSetHighBoxZ(struct _D3_OBJECT *o /*$t0*/, long height /*$t1*/, long num_child /*$a2*/)
 // line 1213, offset 0x80058040
	/* begin block 1 */
		// Start line: 1214
		// Start offset: 0x80058040
		// Variables:
	// 		struct _D3_OBJECT *child; // $a3
	// 		long z; // $a1
	/* end block 1 */
	// End offset: 0x800580A0
	// End Line: 1230

	/* begin block 2 */
		// Start line: 2843
	/* end block 2 */
	// End Line: 2844

void CB_ColumnSetHighBoxZ(_D3_OBJECT *o,long height,long num_child)

{
  int z;
  _D3_OBJECT *p_Var1;
  
  p_Var1 = o->child;
  z = 0;
  while (p_Var1 != (_D3_OBJECT *)0x0) {
    if ((int)p_Var1[1].pos.vz == num_child) {
      z = ((int)*(short *)&p_Var1[1].prec + (int)(p_Var1->pos).vz) - (int)(o->pos).vz;
    }
    p_Var1 = p_Var1->next;
  }
  if (z == 0) {
    z = height;
  }
  D3_SetHighBoxZ(o,z);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_ColumnFall()
 // line 1234, offset 0x800580b8
	/* begin block 1 */
		// Start line: 1235
		// Start offset: 0x800580B8
		// Variables:
	// 		struct _D3_OBJECT *o; // $s1
	// 		struct _PLATFORM *plat; // $s4
	// 		struct CDOOR2_7fake spd; // stack offset -40
	// 		struct CDOOR2_7fake rot; // stack offset -32
	// 		long i; // $s3
	// 		long max; // $s0
	/* end block 1 */
	// End offset: 0x800583B4
	// End Line: 1281

	/* begin block 2 */
		// Start line: 2885
	/* end block 2 */
	// End Line: 2886

/* WARNING: Removing unreachable block (ram,0x80058158) */
/* WARNING: Removing unreachable block (ram,0x80058160) */
/* WARNING: Removing unreachable block (ram,0x80058148) */
/* WARNING: Removing unreachable block (ram,0x800581c4) */
/* WARNING: Removing unreachable block (ram,0x800581d4) */
/* WARNING: Removing unreachable block (ram,0x800581dc) */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void CB_ColumnFall(void)

{
  char cVar1;
  _PLATFORM *p_Var2;
  long lVar3;
  int iVar4;
  undefined4 uVar5;
  _D3_OBJECT *obj;
  short local_28;
  short local_26;
  short local_24;
  short local_20 [2];
  short local_1c;
  
  obj = (_D3_OBJECT *)TaskCurrent->local;
  memset(&local_28,0,8);
  memset(local_20,0,8);
  cVar1 = (char)obj;
  p_Var2 = Plat_GetPlat(cVar1 + ',');
  iVar4 = (int)local_28;
  if (iVar4 < 0) {
    iVar4 = -iVar4;
  }
  while (iVar4 < 2) {
    lVar3 = M_rand();
    iVar4 = lVar3 % 0x14 + -10;
    local_28 = (short)iVar4;
    if (iVar4 < 0) {
      iVar4 = -iVar4;
    }
  }
  iVar4 = (int)local_26;
  if (iVar4 < 0) {
    iVar4 = -iVar4;
  }
  while (iVar4 < 2) {
    lVar3 = M_rand();
    iVar4 = lVar3 % 0x14 + -10;
    local_26 = (short)iVar4;
    if (iVar4 < 0) {
      iVar4 = -iVar4;
    }
  }
  lVar3 = M_rand();
  local_24 = (short)lVar3 + (short)(lVar3 / 0xf) * -0xf + 2;
  lVar3 = M_rand();
  local_20[0] = (short)lVar3 + (short)(lVar3 / 200) * -200;
  lVar3 = M_rand();
  iVar4 = 99;
  local_1c = (short)lVar3 + (short)(lVar3 / 200) * -200;
  Impact_Stone(cVar1 + ',',10);
  SFX_Explosion(cVar1 + ',',1,3);
  do {
    uVar5 = *(undefined4 *)&(obj->pos).vz;
    *(undefined4 *)&obj->last_pos = *(undefined4 *)&obj->pos;
    *(undefined4 *)&(obj->last_pos).vz = uVar5;
    (obj->pos).vx = (obj->pos).vx + local_28;
    (obj->pos).vy = (obj->pos).vy + local_26;
    (obj->pos).vz = (obj->pos).vz + local_24;
    local_24 = local_24 + -1;
    (obj->rot).vx = (obj->rot).vx + local_20[0];
    (obj->rot).vz = (obj->rot).vz + local_1c;
    if ((obj->pos).vz <= *(short *)&p_Var2[1].obj.prec) {
      Impact_Stone(cVar1 + ',',10);
      D3_ExplodeObject(obj);
      return;
    }
    iVar4 = iVar4 + -1;
    Task_Next();
  } while (iVar4 != -1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_PieceOWheel(struct _D3_OBJECT *o /*$s1*/)
 // line 1294, offset 0x800583d4
	/* begin block 1 */
		// Start line: 1295
		// Start offset: 0x800583D4
		// Variables:
	// 		struct _D3_OBJECT *roue1; // $s0
	// 		struct _PLATFORM *plat; // $v0
	// 		struct _ZONE *zone; // $s4
	// 		struct CDOOR2_7fake dest; // stack offset -40
	// 		long i; // $s0
	// 		long angX; // stack offset -32
	// 		long sensX; // $s2
	/* end block 1 */
	// End offset: 0x8005873C
	// End Line: 1423

	/* begin block 2 */
		// Start line: 3025
	/* end block 2 */
	// End Line: 3026

void CB_PieceOWheel(_D3_OBJECT *o)

{
  short sVar1;
  _ZONE *z;
  _PLATFORM *p_Var2;
  long lVar3;
  undefined4 uVar4;
  _D3_OBJECT *o_00;
  int iVar5;
  long sensX;
  uint local_24;
  long alStack32 [2];
  
  z = Zone_GetObjectZone(o);
  p_Var2 = Plat_GetPlat((char)o + ',');
  uVar4 = *(undefined4 *)&o->pos;
  local_24 = *(uint *)&(o->pos).vz & 0xffff0000 |
             (uint)(ushort)((*(short *)&p_Var2[1].obj.prec + p_Var2[1].obj.pos.vy) - 0x32);
  o_00 = o->father->child;
  sensX = 1;
  while ((o_00 != (_D3_OBJECT *)0x0 && (*(char *)((int)&o_00[1].pos.vx + 1) != '\x06'))) {
    o_00 = o_00->next;
    Task_Next();
  }
  *(undefined4 *)&o[1].last_pos = 100;
  D3_ClearCollBits(o,9);
  lVar3 = Pvl_TestStateBits(o,1);
  if (lVar3 == 0) {
    lVar3 = Pvl_TestStateBits(o,2);
    if (lVar3 != 0) {
      *(undefined4 *)&o->pos = uVar4;
      *(uint *)&(o->pos).vz = local_24;
      (o->pos).vz = (o->pos).vz + 0x32;
      D3_ClearCollBits(o,0x80);
      (o->rot).vx = 0;
    }
    while ((Scts_Interruptors & (int)o[1].pos.vz) == 0) {
      Task_Next();
    }
    o->display_mode = o->display_mode | 0x10;
    D3_SetCollBits(o,9);
    lVar3 = Pvl_TestStateBits(o,2);
    if (lVar3 == 0) {
      uVar4 = *(undefined4 *)&(o_00->pos).vz;
      *(undefined4 *)&o->pos = *(undefined4 *)&o_00->pos;
      *(undefined4 *)&(o->pos).vz = uVar4;
      CB_Piece2Water(o,0xd8);
      (o->pos).vz = (o->pos).vz + 0x32;
      D3_ClearCollBits(o,0x80);
      D3_SetCollBits(o_00,1);
      (o->rot).vx = 0;
      Pvl_SetStateBits(o,2);
    }
    while (sVar1 = Zone_IsPosInZone(z,(char)o + ','), sVar1 == 0) {
      (o->pos).vx = (o->pos).vx + -5;
      sensX = CB_FloatPiece(o,alStack32,sensX);
      Task_Next();
    }
    while ((int)z->x1 + 2 <= (int)(o->pos).vx + (int)(o->b_box).vx) {
      sensX = CB_FloatPiece(o,alStack32,sensX);
      Task_Next();
    }
    Pvl_SetStateBits(o,1);
    D3_ClearCollBits(o,0xc9);
    Zone_DeleteObject(o);
    o_00 = o->father;
    Scts_Interruptors = Scts_Interruptors | (int)o[1].pos.pad;
    iVar5 = 0;
    if (o_00 != (_D3_OBJECT *)0x0) {
      uVar4 = *(undefined4 *)&(o_00->rot).vz;
      *(undefined4 *)&o->rot = *(undefined4 *)&o_00->rot;
      *(undefined4 *)&(o->rot).vz = uVar4;
      do {
        uVar4 = *(undefined4 *)&(o->father->pos).vz;
        *(undefined4 *)&o->pos = *(undefined4 *)&o->father->pos;
        *(undefined4 *)&(o->pos).vz = uVar4;
        iVar5 = iVar5 + 1;
        Task_Next();
      } while (iVar5 < 5);
    }
  }
  else {
    o->display_mode = o->display_mode | 0x10;
    D3_ClearCollBits(o,0xc9);
    Zone_DeleteObject(o);
    o_00 = o->father;
    if (o_00 != (_D3_OBJECT *)0x0) {
      uVar4 = *(undefined4 *)&(o_00->rot).vz;
      *(undefined4 *)&o->rot = *(undefined4 *)&o_00->rot;
      *(undefined4 *)&(o->rot).vz = uVar4;
      uVar4 = *(undefined4 *)&(o->father->pos).vz;
      *(undefined4 *)&o->pos = *(undefined4 *)&o->father->pos;
      *(undefined4 *)&(o->pos).vz = uVar4;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_Piece2Water(struct _D3_OBJECT *o /*$a0*/, struct CDOOR2_7fake *dest /*$a1*/)
 // line 1425, offset 0x8005875c
	/* begin block 1 */
		// Start line: 1426
		// Start offset: 0x8005875C
		// Variables:
	// 		struct CDOOR2_7fake *pos; // $s0
	// 		struct CDOOR2_7fake spos; // stack offset -24
	// 		long time; // $s1
	/* end block 1 */
	// End offset: 0x80058888
	// End Line: 1443

	/* begin block 2 */
		// Start line: 3300
	/* end block 2 */
	// End Line: 3301

/* WARNING: Removing unreachable block (ram,0x80058814) */
/* WARNING: Removing unreachable block (ram,0x800587d0) */
/* WARNING: Removing unreachable block (ram,0x8005878c) */
/* WARNING: Removing unreachable block (ram,0x8005879c) */
/* WARNING: Removing unreachable block (ram,0x800587a4) */
/* WARNING: Removing unreachable block (ram,0x800587e0) */
/* WARNING: Removing unreachable block (ram,0x800587e8) */
/* WARNING: Removing unreachable block (ram,0x80058824) */
/* WARNING: Removing unreachable block (ram,0x8005882c) */

void CB_Piece2Water(_D3_OBJECT *o,undefined dest)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  undefined3 in_register_00000015;
  short *psVar7;
  int iVar8;
  
  psVar7 = (short *)CONCAT31(in_register_00000015,dest);
  sVar1 = *psVar7;
  sVar2 = (o->pos).vx;
  sVar3 = psVar7[1];
  sVar4 = (o->pos).vy;
  sVar5 = psVar7[2];
  sVar6 = (o->pos).vz;
  iVar8 = 9;
  do {
    (o->pos).vx = (o->pos).vx + (short)(((int)sVar1 - (int)sVar2) / 10);
    (o->pos).vy = (o->pos).vy + (short)(((int)sVar3 - (int)sVar4) / 10);
    iVar8 = iVar8 + -1;
    (o->pos).vz = (o->pos).vz + (short)(((int)sVar5 - (int)sVar6) / 10);
    Task_Next();
  } while (iVar8 != -1);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ CB_FloatPiece(struct _D3_OBJECT *o /*$s0*/, long *angX /*$s1*/, long sensX /*stack 8*/)
 // line 1445, offset 0x800588a0
	/* begin block 1 */
		// Start line: 1446
		// Start offset: 0x800588A0
		// Variables:
	// 		long angle; // $a0
	// 		long speed; // $v0
	/* end block 1 */
	// End offset: 0x80058910
	// End Line: 1465

	/* begin block 2 */
		// Start line: 3351
	/* end block 2 */
	// End Line: 3352

/* WARNING: Could not reconcile some variable overlaps */

long CB_FloatPiece(_D3_OBJECT *o,long *angX,long sensX)

{
  long lVar1;
  int iVar2;
  int iVar3;
  long local_res8;
  
  iVar3 = (int)(o->rot).vx;
  if (iVar3 == 0) {
    local_res8 = sensX;
    lVar1 = CB_InitAngle(*(long *)&o[1].last_pos,5,&local_res8);
    *angX = lVar1;
  }
  else {
    iVar2 = *angX;
    if (iVar2 < 0) {
      local_res8 = sensX;
      if (iVar3 < iVar2) {
        local_res8 = 5;
      }
    }
    else {
      local_res8 = sensX;
      if (iVar2 < iVar3) {
        local_res8 = -5;
      }
    }
  }
  (o->rot).vx = (o->rot).vx + (short)local_res8;
  return local_res8;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_Lucioles(struct _D3_OBJECT *o /*$s2*/)
 // line 1480, offset 0x80058938
	/* begin block 1 */
		// Start line: 1481
		// Start offset: 0x80058938
		// Variables:
	// 		struct CDOOR2_7fake tab_pos[15]; // stack offset -368
	// 		struct CDOOR2_7fake tab_speed[15]; // stack offset -248
	// 		struct CDOOR2_7fake pos; // stack offset -128
	// 		struct CDOOR2_8fake col; // stack offset -120
	// 		struct CDOOR2_8fake tab_col[15]; // stack offset -112
	// 		struct CDOOR2_71fake list; // stack offset -48
	// 		long i; // $s0
	// 		long mask; // $s3
	// 		long zoneattached; // $s5
	/* end block 1 */
	// End offset: 0x80058BBC
	// End Line: 1559

	/* begin block 2 */
		// Start line: 3426
	/* end block 2 */
	// End Line: 3427

/* WARNING: Could not reconcile some variable overlaps */

void CB_Lucioles(_D3_OBJECT *o)

{
  TASK *pTVar1;
  short snd_handle;
  long lVar2;
  long lVar3;
  undefined pos;
  int iVar4;
  undefined *puVar5;
  uint uVar6;
  undefined auStack368 [240];
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined auStack112 [64];
  void *local_30;
  undefined *local_2c;
  undefined *local_28;
  undefined2 local_24;
  
  iVar4 = 0;
  puVar5 = auStack368;
  local_80 = *(undefined4 *)&o->pos;
  local_7c = *(undefined4 *)&(o->pos).vz;
  local_78 = PTR_DAT_800ad6b0;
  uVar6 = (int)o[1].pos.vz | (int)o[1].pos.pad << 0x10;
  lVar2 = Zone_IsZoneAttached(o);
  pTVar1 = TaskCurrent;
  TaskCurrent->destructor = CB_LoopingSoundDestructor;
  *(_D3_OBJECT **)&pTVar1->local = o;
  pTVar1->display = CB_LuciolesDisplay;
  local_80 = *(undefined4 *)&o->pos;
  local_7c = *(undefined4 *)&(o->pos).vz;
  do {
    CB_LucioleInitPos((char)puVar5);
    *(undefined2 *)(puVar5 + 6) = 0xe605;
    iVar4 = iVar4 + 1;
    puVar5 = puVar5 + 8;
  } while (iVar4 < 0xf);
  CB_LucioleInitSpeed(8);
  local_28 = auStack112;
  CB_LucioleInitCol((char)local_28,0x88);
  local_2c = auStack368;
  local_24 = 0xf;
  local_30 = Effects_Pcl;
  *(void ***)&o[1].last_pos = &local_30;
  *(undefined2 *)((int)&o[1].prec + 2) = 0xffff;
  while( true ) {
    snd_handle = D3_UpdateSound(o,0,*(short *)((int)&o[1].prec + 2));
    *(short *)((int)&o[1].prec + 2) = snd_handle;
    if ((uVar6 != 0) && (iVar4 = 0, (Scts_Interruptors & uVar6) == uVar6)) break;
    if ((lVar2 == 0) || (lVar3 = Task_EventRead(TaskCurrent), lVar3 != 2)) {
      pos = 0x80;
    }
    else {
      pos = 100;
    }
    CB_LuciolesGoToPos(o,pos,0x14);
    (o->rot).vz = (o->rot).vz + 0x32;
    CB_LuciolesMove(o,0x90,8,1);
    Task_Next();
  }
  do {
    iVar4 = iVar4 + 1;
    local_78._0_3_ =
         CONCAT12(local_78._2_1_ - local_78._2_1_ / 10,
                  CONCAT11(local_78._1_1_ - local_78._1_1_ / 10,(byte)local_78 - (byte)local_78 / 10
                          ));
    local_78 = (undefined *)((uint)local_78 & 0xff000000 | (uint)(uint3)local_78);
    CB_LuciolesMove(o,0x90,8,0);
    CB_LucioleInitCol(0x90,0x88);
    Task_Next();
  } while (iVar4 < 0x1e);
  snd_handle = *(short *)((int)&o[1].prec + 2);
  if (-1 < snd_handle) {
    D3_StopSound(o,snd_handle);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_LuciolesGoToPos(struct _D3_OBJECT *o /*$a0*/, struct CDOOR2_7fake *pos /*$a1*/, short speed /*$a2*/)
 // line 1563, offset 0x80058be0
	/* begin block 1 */
		// Start line: 1564
		// Start offset: 0x80058BE0
		// Variables:
	// 		struct CDOOR2_7fake *orig; // $t0
	// 		struct CDOOR2_7fake dist; // stack offset -8
	/* end block 1 */
	// End offset: 0x80058BE0
	// End Line: 1564

	/* begin block 2 */
		// Start line: 3691
	/* end block 2 */
	// End Line: 3692

void CB_LuciolesGoToPos(_D3_OBJECT *o,undefined pos,short speed)

{
  short sVar1;
  short sVar2;
  undefined3 in_register_00000015;
  ushort *puVar3;
  int iVar4;
  int iVar5;
  
  puVar3 = (ushort *)CONCAT31(in_register_00000015,pos);
  iVar4 = (int)speed;
  iVar5 = (int)(((uint)*puVar3 - (uint)(ushort)(o->pos).vx) * 0x10000) >> 0x10;
  if (iVar4 == 0) {
    trap(0x1c00);
  }
  if ((iVar4 == -1) && (iVar5 == -0x80000000)) {
    trap(0x1800);
  }
  sVar1 = puVar3[1] - (o->pos).vy;
  sVar2 = puVar3[2] - (o->pos).vz;
  (o->pos).vx = (o->pos).vx + (short)(iVar5 / iVar4);
  if (iVar4 == 0) {
    trap(0x1c00);
  }
  if ((iVar4 == -1) && ((int)sVar1 == -0x80000000)) {
    trap(0x1800);
  }
  (o->pos).vy = (o->pos).vy + sVar1 / speed;
  if (iVar4 == 0) {
    trap(0x1c00);
  }
  if ((iVar4 == -1) && ((int)sVar2 == -0x80000000)) {
    trap(0x1800);
  }
  (o->pos).vz = (o->pos).vz + sVar2 / speed;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_LuciolesDisplay()
 // line 1578, offset 0x80058d0c
	/* begin block 1 */
		// Start line: 1579
		// Start offset: 0x80058D0C
		// Variables:
	// 		struct CDOOR2_5fake mr; // stack offset -48
	// 		struct _D3_OBJECT *o; // $a0
	// 		struct CDOOR2_71fake *list; // $s2
	/* end block 1 */
	// End offset: 0x80058D0C
	// End Line: 1579

	/* begin block 2 */
		// Start line: 3731
	/* end block 2 */
	// End Line: 3732

/* WARNING: Unknown calling convention yet parameter storage is locked */

void CB_LuciolesDisplay(void)

{
  undefined4 in_zero;
  undefined4 in_at;
  void *pvVar1;
  undefined4 uVar2;
  ushort auStack48 [10];
  int local_1c;
  int local_18;
  int local_14;
  
  pvVar1 = TaskCurrent->local;
  uVar2 = *(undefined4 *)((int)pvVar1 + 0xa0);
  setCopReg(2,in_zero,*(undefined4 *)((int)pvVar1 + 0x2c));
  setCopReg(2,in_at,*(undefined4 *)((int)pvVar1 + 0x30));
  copFunction(2,0x486012);
  local_1c = getCopReg(2,0x19);
  local_18 = getCopReg(2,0x1a);
  local_14 = getCopReg(2,0x1b);
  local_1c = local_1c + Cam_Matrix.t[0];
  local_18 = local_18 + Cam_Matrix.t[1];
  local_14 = local_14 + Cam_Matrix.t[2];
  setCopControlWord(2,0x2800,local_1c);
  setCopControlWord(2,0x3000,local_18);
  setCopControlWord(2,0x3800,local_14);
  RotMatrixZYX((short *)((int)pvVar1 + 0x3c),auStack48);
  SetMulMatrix((undefined4 *)&Cam_Matrix,auStack48);
  Main_Prims = (void *)GtxShp_DisplayListLOFF
                                 (uVar2,Main_Prims,Scr->ot,(int)Scr_OtSize,0,
                                  Main_TextContext.Font.ascii_tab._20_4_);
  setCopControlWord(2,0x2800,Cam_Matrix.t[0]);
  setCopControlWord(2,0x3000,Cam_Matrix.t[1]);
  setCopControlWord(2,0x3800,Cam_Matrix.t[2]);
  setCopControlWord(2,0,Cam_Matrix.m[0]._0_4_);
  setCopControlWord(2,0x800,Cam_Matrix.m._4_4_);
  setCopControlWord(2,0x1000,Cam_Matrix.m[1]._2_4_);
  setCopControlWord(2,0x1800,Cam_Matrix.m[2]._0_4_);
  setCopControlWord(2,0x2000,Cam_Matrix._16_4_);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_LucioleInitPos(struct CDOOR2_7fake *sv /*$a0*/)
 // line 1602, offset 0x80058e70
	/* begin block 1 */
		// Start line: 3787
	/* end block 1 */
	// End Line: 3788

/* WARNING: Unknown calling convention yet parameter storage is locked */

void CB_LucioleInitPos(undefined sv)

{
  undefined3 in_register_00000011;
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)CONCAT31(in_register_00000011,sv);
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_LucioleInitCol(struct CDOOR2_8fake *tab_col /*$a0*/, struct CDOOR2_8fake *col /*$a1*/)
 // line 1609, offset 0x80058e80
	/* begin block 1 */
		// Start line: 1611
		// Start offset: 0x80058E80
		// Variables:
	// 		struct CDOOR2_8fake *c; // $a0
	// 		long i; // $v1
	/* end block 1 */
	// End offset: 0x80058EA8
	// End Line: 1616

	/* begin block 2 */
		// Start line: 3804
	/* end block 2 */
	// End Line: 3805

/* WARNING: Unknown calling convention yet parameter storage is locked */

void CB_LucioleInitCol(undefined tab_col,undefined col)

{
  int iVar1;
  undefined3 in_register_00000011;
  undefined4 *puVar2;
  undefined3 in_register_00000015;
  
  puVar2 = (undefined4 *)CONCAT31(in_register_00000011,tab_col);
  iVar1 = 0;
  do {
    *puVar2 = *(undefined4 *)CONCAT31(in_register_00000015,col);
    iVar1 = iVar1 + 1;
    puVar2 = puVar2 + 1;
  } while (iVar1 < 0xf);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_LucioleInitSpeed(struct CDOOR2_7fake *tab_spd /*$a0*/)
 // line 1619, offset 0x80058eb0
	/* begin block 1 */
		// Start line: 1620
		// Start offset: 0x80058EB0
		// Variables:
	// 		long i; // $s3
	// 		struct CDOOR2_7fake *spd; // $s2
	/* end block 1 */
	// End offset: 0x80058FBC
	// End Line: 1631

	/* begin block 2 */
		// Start line: 3821
	/* end block 2 */
	// End Line: 3822

/* WARNING: Unknown calling convention yet parameter storage is locked */

void CB_LucioleInitSpeed(undefined tab_spd)

{
  long lVar1;
  undefined3 in_register_00000011;
  short *psVar2;
  short *psVar3;
  int iVar4;
  
  psVar3 = (short *)CONCAT31(in_register_00000011,tab_spd);
  iVar4 = 0;
  psVar2 = psVar3 + 3;
  do {
    iVar4 = iVar4 + 1;
    lVar1 = M_rand();
    *psVar3 = (short)lVar1 + (short)(lVar1 / 0x1e) * -0x1e + -0xf;
    lVar1 = M_rand();
    psVar2[-2] = (short)lVar1 + (short)(lVar1 / 0x1e) * -0x1e + -0xf;
    lVar1 = M_rand();
    psVar2[-1] = (short)lVar1 + (short)(lVar1 / 0x1e) * -0x1e + -0xf;
    lVar1 = M_rand();
    psVar3 = psVar3 + 4;
    *psVar2 = (short)lVar1 + (short)(lVar1 / 0x1e) * -0x1e;
    psVar2 = psVar2 + 4;
  } while (iVar4 < 0xf);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_LucioleInvertSpeed(struct CDOOR2_7fake *spd /*$s0*/)
 // line 1634, offset 0x80058fd8
	/* begin block 1 */
		// Start line: 3873
	/* end block 1 */
	// End Line: 3874

/* WARNING: Unknown calling convention yet parameter storage is locked */

void CB_LucioleInvertSpeed(undefined spd)

{
  long lVar1;
  undefined3 in_register_00000011;
  short *psVar2;
  
  psVar2 = (short *)CONCAT31(in_register_00000011,spd);
  *psVar2 = -*psVar2;
  psVar2[2] = -psVar2[2];
  psVar2[1] = -psVar2[1];
  lVar1 = M_rand();
  psVar2[3] = (short)lVar1 + (short)(lVar1 / 0x1e) * -0x1e;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_LuciolesMove(struct _D3_OBJECT *o /*$a0*/, struct CDOOR2_7fake *tab_pos /*$a1*/, struct CDOOR2_7fake *tab_spd /*$a2*/, long invert /*$s6*/)
 // line 1643, offset 0x80059054
	/* begin block 1 */
		// Start line: 1644
		// Start offset: 0x80059054
		// Variables:
	// 		long i; // $s5
	// 		struct CDOOR2_7fake *tp; // $s2
	// 		struct CDOOR2_7fake *ts; // $s4
	/* end block 1 */
	// End offset: 0x80059148
	// End Line: 1668

	/* begin block 2 */
		// Start line: 3894
	/* end block 2 */
	// End Line: 3895

void CB_LuciolesMove(_D3_OBJECT *o,undefined tab_pos,undefined tab_spd,long invert)

{
  long lVar1;
  undefined3 in_register_00000015;
  undefined3 in_register_00000019;
  short *psVar2;
  short *psVar3;
  short *psVar4;
  short *psVar5;
  short *psVar6;
  int iVar7;
  
  psVar3 = (short *)CONCAT31(in_register_00000019,tab_spd);
  psVar4 = (short *)CONCAT31(in_register_00000015,tab_pos);
  iVar7 = 0;
  psVar5 = psVar3 + 3;
  psVar2 = psVar4 + 2;
  psVar6 = psVar3;
  do {
    lVar1 = Distance3D(0,0,0,(int)*psVar4,(int)psVar2[-1],(int)*psVar2);
    if ((lVar1 < 0x12d) || (invert == 0)) {
LAB_800590ec:
      *psVar4 = *psVar4 + *psVar3;
      psVar2[-1] = psVar2[-1] + psVar3[1];
      *psVar2 = *psVar2 + psVar3[2];
    }
    else {
      if (*psVar5 == 0) {
        CB_LucioleInvertSpeed((char)psVar6);
        goto LAB_800590ec;
      }
      *psVar5 = *psVar5 + -1;
    }
    psVar3 = psVar3 + 4;
    iVar7 = iVar7 + 1;
    psVar2 = psVar2 + 4;
    psVar4 = psVar4 + 4;
    psVar5 = psVar5 + 4;
    psVar6 = psVar6 + 4;
    if (0xe < iVar7) {
      return;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_DalleWeight(struct _D3_OBJECT *o /*$s4*/)
 // line 1680, offset 0x80059170
	/* begin block 1 */
		// Start line: 1681
		// Start offset: 0x80059170
		// Variables:
	// 		struct _ZONE *z; // $s6
	// 		struct CDOOR2_104fake t; // stack offset -88
	// 		long nbobj; // $s2
	// 		long sum; // $s3
	// 		long TabIndex[4]; // stack offset -56

		/* begin block 1.1 */
			// Start line: 1714
			// Start offset: 0x80059258
			// Variables:
		// 		struct _D3_OBJECT *drop; // $s0
		// 		long index; // $s1
		/* end block 1.1 */
		// End offset: 0x8005934C
		// End Line: 1772
	/* end block 1 */
	// End offset: 0x8005935C
	// End Line: 1776

	/* begin block 2 */
		// Start line: 4015
	/* end block 2 */
	// End Line: 4016

void CB_DalleWeight(_D3_OBJECT *o)

{
  short sVar1;
  _ZONE *z;
  long nbobj;
  _PLATFORM *p_Var2;
  int iVar3;
  _TAKEN_OBJECT *p_Var4;
  long lVar5;
  int sum;
  undefined auStack88 [32];
  long local_38 [4];
  
  z = Zone_GetObjectZone(o);
  Text_SetContext((TEXT_102fake *)auStack88);
  Text_SetContextFont(0x70);
  Text_SetContextXY(0,0);
  Text_SetContextWH(Scr_W,Scr_H);
  Text_SetContextRange(0);
  Text_SetContextMode(0);
  CB_WeightDisableSmoke(o);
  nbobj = Pvl_TestStateBits(o,2);
  if (nbobj != 0) {
    p_Var2 = Plat_GetPlat((char)o + ',');
    (o->pos).vz = *(short *)&p_Var2[1].obj.prec;
    return;
  }
  do {
    sum = 0;
    if ((o->collision_state & 0x10U) != 0) {
      p_Var4 = (_TAKEN_OBJECT *)0x0;
      o->collision_state = o->collision_state & 0xffef;
      iVar3 = Invent_GetDroppedIndex(0x16,0);
      nbobj = 0;
      if (-1 < iVar3) {
        p_Var4 = (_TAKEN_OBJECT *)((int)Pvl_TakenObjects + iVar3 * 0xb0);
        nbobj = 0;
      }
      while (p_Var4 != (_TAKEN_OBJECT *)0x0) {
        sVar1 = Zone_IsPosInZone(z,(char)p_Var4 + ',');
        lVar5 = nbobj;
        if (sVar1 != 0) {
          lVar5 = nbobj + 1;
          sVar1 = *(short *)&p_Var4[1].obj.description;
          local_38[nbobj] = iVar3;
          sum = sum + (int)sVar1;
        }
        iVar3 = Invent_GetDroppedIndex(0x16,iVar3 + 1);
        if (iVar3 < 0) {
          p_Var4 = (_TAKEN_OBJECT *)0x0;
          nbobj = lVar5;
        }
        else {
          p_Var4 = (_TAKEN_OBJECT *)((int)Pvl_TakenObjects + iVar3 * 0xb0);
          nbobj = lVar5;
        }
      }
      CB_WeightSetPos(o,nbobj,local_38);
      lVar5 = CB_ReceptTestSum(o,nbobj,sum);
      if (lVar5 == 1) {
        CB_RightWeight(o,nbobj,local_38);
        return;
      }
      if ((1 < lVar5) && (lVar5 == 2)) {
        CB_WrongWeight(o,nbobj,local_38);
      }
    }
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// long /*$ra*/ CB_ReceptTestSum(struct _D3_OBJECT *o /*$a0*/, long nbobj /*$a1*/, long sum /*$a2*/)
 // line 1779, offset 0x80059388
	/* begin block 1 */
		// Start line: 4282
	/* end block 1 */
	// End Line: 4283

long CB_ReceptTestSum(_D3_OBJECT *o,long nbobj,long sum)

{
  long lVar1;
  int iVar2;
  
  if ((sum == 0) || (nbobj < 2)) {
    return 0;
  }
  iVar2 = (int)o[1].pos.vz;
  if ((sum <= iVar2) && (nbobj < 3)) {
    lVar1 = -1;
    if (iVar2 <= sum) {
      lVar1 = 1;
    }
    return lVar1;
  }
  return 2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_WeightDisableSmoke(struct _D3_OBJECT *o /*$a0*/)
 // line 1800, offset 0x800593d8
	/* begin block 1 */
		// Start line: 1802
		// Start offset: 0x800593D8
		// Variables:
	// 		struct _D3_OBJECT *child; // $v1
	/* end block 1 */
	// End offset: 0x80059414
	// End Line: 1815

	/* begin block 2 */
		// Start line: 4323
	/* end block 2 */
	// End Line: 4324

void CB_WeightDisableSmoke(_D3_OBJECT *o)

{
  _D3_OBJECT *p_Var1;
  
  p_Var1 = o->child;
  while( true ) {
    if (p_Var1 == (_D3_OBJECT *)0x0) {
      return;
    }
    if (*(char *)((int)&p_Var1[1].pos.vx + 1) == '\x01') break;
    p_Var1 = p_Var1->next;
  }
  p_Var1->handle->enable = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_WeightSetPos(struct _D3_OBJECT *o /*$a3*/, long nbobj /*$a1*/, long *tab /*$a2*/)
 // line 1818, offset 0x8005941c
	/* begin block 1 */
		// Start line: 1819
		// Start offset: 0x8005941C
		// Variables:
	// 		struct _D3_OBJECT *weight; // $a3
	// 		struct CDOOR2_7fake c; // stack offset -8
	/* end block 1 */
	// End offset: 0x800594F8
	// End Line: 1840

	/* begin block 2 */
		// Start line: 4358
	/* end block 2 */
	// End Line: 4359

void CB_WeightSetPos(_D3_OBJECT *o,long nbobj,long *tab)

{
  uint uVar1;
  short sVar2;
  int iVar3;
  short sVar4;
  
  if (nbobj != 0) {
    uVar1 = (int)o->comp_opt2 + (int)*(short *)&o[1].child;
    sVar4 = (o->pos).vx + (short)((int)(uVar1 + (uVar1 >> 0x1f)) >> 1);
    uVar1 = (int)o->comp_opt3 + (int)*(short *)((int)&o[1].child + 2);
    sVar2 = (o->pos).vy + (short)((int)(uVar1 + (uVar1 >> 0x1f)) >> 1);
    iVar3 = *tab;
    *(short *)((int)Pvl_TakenObjects + iVar3 * 0xb0 + 0x2c) = sVar4 + -0x32;
    *(short *)((int)Pvl_TakenObjects + iVar3 * 0xb0 + 0x2e) = sVar2 + -0x32;
    if (1 < nbobj) {
      iVar3 = tab[1];
      *(short *)((int)Pvl_TakenObjects + iVar3 * 0xb0 + 0x2c) = sVar4 + 0x32;
      *(short *)((int)Pvl_TakenObjects + iVar3 * 0xb0 + 0x2e) = sVar2 + 0x32;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_WrongWeight(struct _D3_OBJECT *o /*$a0*/, long nbobj /*$s4*/, long *tab /*$s0*/)
 // line 1843, offset 0x80059500
	/* begin block 1 */
		// Start line: 1844
		// Start offset: 0x80059500
		// Variables:
	// 		long i; // $s2
	// 		struct _D3_OBJECT *child; // $s1

		/* begin block 1.1 */
			// Start line: 1872
			// Start offset: 0x800595DC
			// Variables:
		// 		struct _TAKEN_OBJECT *to; // $s0
		/* end block 1.1 */
		// End offset: 0x8005961C
		// End Line: 1877
	/* end block 1 */
	// End offset: 0x8005963C
	// End Line: 1880

	/* begin block 2 */
		// Start line: 4410
	/* end block 2 */
	// End Line: 4411

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CB_WrongWeight(_D3_OBJECT *o,long nbobj,long *tab)

{
  undefined4 uVar1;
  short sVar2;
  _TAKEN_OBJECT *obj;
  _D3_OBJECT *p_Var3;
  int iVar4;
  
  uVar1 = _DAT_800b1c68;
  p_Var3 = o->child;
  if (p_Var3 != (_D3_OBJECT *)0x0) {
    do {
      if (*(char *)((int)&p_Var3[1].pos.vx + 1) == '\x01') {
        *(undefined4 *)&p_Var3->pos = _DAT_800b1c64;
        *(undefined4 *)&(p_Var3->pos).vz = uVar1;
        p_Var3->handle->enable = 1;
        Task_EventExec(p_Var3->handle,-0x2000,0);
        break;
      }
      p_Var3 = p_Var3->next;
    } while (p_Var3 != (_D3_OBJECT *)0x0);
    iVar4 = 0;
    if (p_Var3 != (_D3_OBJECT *)0x0) {
      Task_EventExec(Overlay_Handle,Overlay_Handle->event_msg | 2,Overlay_Handle->event_param);
      Task_Sleep(0x14);
      if (0 < nbobj) {
        do {
          obj = (_TAKEN_OBJECT *)((int)Pvl_TakenObjects + *tab * 0xb0);
          sVar2 = Invent_AddObject((_PLAYER *)&Player,(_D3_OBJECT *)obj);
          if (sVar2 != 0) {
            D3_DeleteObject((_D3_OBJECT *)obj);
          }
          iVar4 = iVar4 + 1;
          tab = tab + 1;
        } while (iVar4 < nbobj);
      }
      Task_EventExec(p_Var3->handle,-0x4000,0);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_RightWeight(struct _D3_OBJECT *o /*$s3*/, long nbobj /*$s2*/, long *tab /*$s6*/)
 // line 1883, offset 0x80059660
	/* begin block 1 */
		// Start line: 1884
		// Start offset: 0x80059660
		// Variables:
	// 		long i; // $s0
	// 		long maxZ; // $s4

		/* begin block 1.1 */
			// Start line: 1908
			// Start offset: 0x8005973C
			// Variables:
		// 		struct _D3_OBJECT *weight; // $v0
		/* end block 1.1 */
		// End offset: 0x8005973C
		// End Line: 1908
	/* end block 1 */
	// End offset: 0x80059794
	// End Line: 1916

	/* begin block 2 */
		// Start line: 4499
	/* end block 2 */
	// End Line: 4500

void CB_RightWeight(_D3_OBJECT *o,long nbobj,long *tab)

{
  short sVar1;
  short sVar2;
  short sVar3;
  _PLATFORM *p_Var4;
  int *piVar5;
  int iVar6;
  
  p_Var4 = Plat_GetPlat((char)o + ',');
  sVar1 = *(short *)&p_Var4[1].obj.prec;
  iVar6 = 0;
  piVar5 = tab;
  if (0 < nbobj) {
    do {
      iVar6 = iVar6 + 1;
      D3_ClearCollBits((_D3_OBJECT *)((int)Pvl_TakenObjects + *piVar5 * 0xb0),1);
      piVar5 = piVar5 + 1;
    } while (iVar6 < nbobj);
  }
  Task_EventExec(Overlay_Handle,Overlay_Handle->event_msg | 2,Overlay_Handle->event_param);
  D3_PlaySound(o,0);
  sVar2 = (o->pos).vz;
  sVar3 = (o->pos).vz;
  while (sVar1 < sVar2) {
    (o->pos).vz = sVar3 + -1;
    iVar6 = 0;
    piVar5 = tab;
    if (0 < nbobj) {
      do {
        iVar6 = iVar6 + 1;
        *(short *)((int)Pvl_TakenObjects + *piVar5 * 0xb0 + 0x30) =
             *(short *)((int)Pvl_TakenObjects + *piVar5 * 0xb0 + 0x30) + -1;
        piVar5 = piVar5 + 1;
      } while (iVar6 < nbobj);
    }
    Task_Next();
    sVar2 = (o->pos).vz;
    sVar3 = (o->pos).vz;
  }
  Pvl_SetStateBits(o,2);
  return;
}





