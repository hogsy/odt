#include "THISDUST.H"
#include "CDOOR.H"


// decompiled code
// original method signature: 
// void /*$ra*/ CB_Door_Main_Task()
 // line 57, offset 0x8004e128
	/* begin block 1 */
		// Start line: 58
		// Start offset: 0x8004E128
		// Variables:
	// 		struct _D3_OBJECT *D3Obj; // $s0
	// 		long comp; // $v1
	// 		long tmp; // $v0
	// 		long exhitpoints; // $s2
	/* end block 1 */
	// End offset: 0x8004E304
	// End Line: 102

	/* begin block 2 */
		// Start line: 116
	/* end block 2 */
	// End Line: 117

/* WARNING: Unknown calling convention yet parameter storage is locked */

void CB_Door_Main_Task(void)

{
  short sVar1;
  long testkey;
  long type;
  _D3_OBJECT *o;
  
  o = (_D3_OBJECT *)TaskCurrent->local;
  sVar1 = o->hit_points;
  D3_SetBonuses(o,0,o);
  do {
    switch((int)o[1].pos.vy & 0x3f) {
    case 0:
      Door_Slide_Normal(o,0);
      break;
    case 1:
      Door_Turn_Normal(o,0,2);
      break;
    case 2:
      Door_Slide_Once(o,1);
      break;
    case 3:
      testkey = 1;
      goto LAB_8004e2a4;
    case 4:
      Door_Slide_Once(o,0);
      break;
    case 5:
    case 0x3f:
      testkey = 0;
LAB_8004e2a4:
      type = 2;
      goto LAB_8004e2a8;
    case 6:
      Door_Dive_Once(o,0);
      break;
    case 7:
      Door_Dive_Once(o,1);
      break;
    case 8:
      Door_MIMe(o,1);
      break;
    case 9:
      Door_Dive_Normal(o,0);
      break;
    case 10:
      Door_GrilleLente(o);
      break;
    case 0xb:
      Door_CheatObject(o);
    case 0xc:
      Door_EnemyTurn(o);
      break;
    case 0xd:
      Door_Drawer(o);
      break;
    case 0xe:
      testkey = 1;
      type = 1;
      goto LAB_8004e2a8;
    case 0xf:
      testkey = 1;
      type = 0;
LAB_8004e2a8:
      Door_Turn_Once(o,testkey,type);
    }
    o[1].pos.vy = 0xff;
    do {
      if ((sVar1 != 0) && (o->hit_points == 0)) break;
      Task_Next();
    } while (o[1].pos.vy == 0xff);
    if ((sVar1 != 0) && (o->hit_points == 0)) {
      Zone_DeleteObject(o);
      D3_ExplodeObject(o);
      o->handle = (TASK *)0x0;
      return;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Door_CheatObject(struct _D3_OBJECT *o /*$s1*/)
 // line 107, offset 0x8004e334
	/* begin block 1 */
		// Start line: 108
		// Start offset: 0x8004E334
		// Variables:
	// 		struct CDOOR_104fake t; // stack offset -56
	// 		long i; // $s0
	// 		long firsttime; // $s2
	/* end block 1 */
	// End offset: 0x8004E478
	// End Line: 138

	/* begin block 2 */
		// Start line: 219
	/* end block 2 */
	// End Line: 220

void Door_CheatObject(_D3_OBJECT *o)

{
  short sVar1;
  int index;
  int iVar2;
  undefined auStack56 [32];
  
  iVar2 = 0;
  Text_SetContext((TEXT_102fake *)auStack56);
  Text_SetContextFont(0x70);
  Text_SetContextXY(0,0);
  Text_SetContextWH(0x140,0xf0);
  Text_SetContextRange(0);
  Text_SetContextMode(0);
  Task_Sleep(0x14);
  do {
    if (((o->collision_state & 1U) != 0) || (iVar2 == 1)) {
      iVar2 = 2;
      o->collision_state = o->collision_state & 0xfffe;
      index = 0;
      while (sVar1 = Text_AmountOfTexts((char *)Pvl_Texts[(int)*(short *)((int)&o[1].prec + 2)]),
            index < (int)sVar1) {
        Text_DisplayLine((char *)Pvl_Texts[(int)*(short *)((int)&o[1].prec + 2)],index,100,
                         (long *)0x0);
        index = index + 1;
      }
      o->collision_state = o->collision_state & 0xfffe;
    }
    if ((iVar2 == 0) && ((o->display_mode & 0x10U) != 0)) {
      iVar2 = 1;
    }
    (o->rot).vz = (o->rot).vz + 0x23;
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Door_ActivateChild(struct _D3_OBJECT *o /*$a0*/, long activate /*$s2*/)
 // line 141, offset 0x8004e478
	/* begin block 1 */
		// Start line: 142
		// Start offset: 0x8004E478
		// Variables:
	// 		struct _D3_OBJECT *child; // $s0
	/* end block 1 */
	// End offset: 0x8004E4E0
	// End Line: 156

	/* begin block 2 */
		// Start line: 294
	/* end block 2 */
	// End Line: 295

void Door_ActivateChild(_D3_OBJECT *o,long activate)

{
  _D3_OBJECT *o_00;
  
  o_00 = o->child;
  while (o_00 != (_D3_OBJECT *)0x0) {
    if (*(char *)((int)&o_00[1].pos.vx + 1) == '\x03') {
      if (activate == 0) {
        D3_ClearCollBits(o_00,9);
      }
      else {
        D3_SetCollBits(o_00,9);
      }
    }
    o_00 = o_00->next;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Door_DisplayChild(struct _D3_OBJECT *o /*$a0*/, long disp /*$s2*/)
 // line 159, offset 0x8004e4f8
	/* begin block 1 */
		// Start line: 160
		// Start offset: 0x8004E4F8
		// Variables:
	// 		struct _D3_OBJECT *child; // $s0
	/* end block 1 */
	// End offset: 0x8004E5C8
	// End Line: 182

	/* begin block 2 */
		// Start line: 330
	/* end block 2 */
	// End Line: 331

void Door_DisplayChild(_D3_OBJECT *o,long disp)

{
  char cVar1;
  ushort uVar2;
  long lVar3;
  _D3_OBJECT *o_00;
  
  o_00 = o->child;
  while (o_00 != (_D3_OBJECT *)0x0) {
    cVar1 = *(char *)((int)&o_00[1].pos.vx + 1);
    if ((cVar1 == '\0') || (cVar1 == '\x03')) {
      if (disp == 0) {
        uVar2 = o_00->display_mode & 0xffef;
      }
      else {
        uVar2 = o_00->display_mode | 0x10;
      }
      o_00->display_mode = uVar2;
    }
    if (((((int)o_00->collision_mode & 0x8000U) != 0) &&
        (lVar3 = Pvl_TestStateBits(o_00,2), lVar3 == 0)) && ((o_00->collision_mode & 8U) == 0)) {
      if (disp == 0) {
        uVar2 = o_00->display_mode & 0xffef;
      }
      else {
        uVar2 = o_00->display_mode | 0x10;
      }
      o_00->display_mode = uVar2;
    }
    o_00 = o_00->next;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Door_Drawer(struct _D3_OBJECT *o /*$s1*/)
 // line 184, offset 0x8004e5e0
	/* begin block 1 */
		// Start line: 185
		// Start offset: 0x8004E5E0
		// Variables:
	// 		long speed; // $s5
	// 		long distance; // $s2
	// 		long multiplier; // $s0
	// 		long X; // $v0
	// 		long Y; // $v1
	// 		long Xs[4]; // stack offset -48
	// 		struct _D3_OBJECT *tmpobj; // $s0
	// 		struct _D3_OBJECT *next; // $s2
	// 		struct _D3_OBJECT *delobj; // $s3
	// 		long motion; // $s6
	/* end block 1 */
	// End offset: 0x8004EB4C
	// End Line: 318

	/* begin block 2 */
		// Start line: 380
	/* end block 2 */
	// End Line: 381

void Door_Drawer(_D3_OBJECT *o)

{
  bool bVar1;
  int iVar2;
  long Anim;
  _D3_OBJECT *o_00;
  int iVar3;
  uint uVar4;
  M_OBJECT *obj;
  int iVar5;
  _D3_OBJECT *p_Var6;
  int Distance;
  _D3_OBJECT *o_01;
  int speed;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  
  bVar1 = *(int *)&o[1].last_pos != 1;
  Task_Next();
  Task_Next();
  if (bVar1) {
    Door_DisplayChild(o,0);
    Door_ActivateChild(o,0);
  }
  speed = (int)o[1].pos.vz;
  local_30 = (int)(o->pos).vx << 0xc;
  iVar5 = 1;
  local_2c = (int)(o->pos).vy << 0xc;
  Distance = (int)o[1].pos.pad * 100;
  iVar3 = (int)*(short *)((int)&o->b_sunk + 2) - (int)*(short *)((int)&o->b_step + 2);
  if (iVar3 < 0) {
    iVar3 = -iVar3;
  }
  iVar2 = (int)*(short *)&o->b_step - (int)(o->b_box).vx;
  if (iVar2 < 0) {
    iVar2 = -iVar2;
  }
  if (speed < 0) {
    iVar5 = -1;
  }
  if (iVar2 < iVar3) {
    iVar3 = rsin((int)(o->rot).vz);
    local_24 = local_2c + (-iVar3 * Distance * iVar5 >> 8);
    uVar4 = SEXT24((o->rot).vz);
  }
  else {
    iVar3 = rsin((int)(o->rot).vz - 0x400);
    local_24 = local_2c + (-iVar3 * Distance * iVar5 >> 8);
    uVar4 = (int)(o->rot).vz - 0x400;
  }
  iVar3 = rcos(uVar4);
  local_28 = local_30 + (iVar3 * Distance * iVar5 >> 8);
  *(undefined4 *)&o[1].last_pos = 0;
  Anim = Pvl_TestStateBits(o,1);
  if (Anim != 0) {
    if (bVar1) {
      Door_DisplayChild(o,1);
      Door_End_Move(o,Distance,speed,1);
      *(undefined4 *)&o[1].last_pos = 1;
      Door_ActivateChild(o,1);
    }
    else {
      o_00 = Monster_GetChild(o,0x6f);
      if (o_00 == (_D3_OBJECT *)0x0) {
        return;
      }
      o_00 = o_00->child;
      if (o_00 == (_D3_OBJECT *)0x0) {
        return;
      }
      if (o_00->next == (_D3_OBJECT *)0x0) {
        return;
      }
      Anim = Pvl_TestStateBits(o_00,2);
      if (Anim == 0) {
        obj = (M_OBJECT *)o->description;
      }
      else {
        obj = (M_OBJECT *)o->description;
      }
      Manim_SetAnim(obj,(uint)(Anim == 0));
      Manim_GoToFrame((M_OBJECT *)o->description,
                      (uint)*(ushort *)
                             (*(int *)(*(int *)((((M_OBJECT *)o->description)->Sq).Data.FatherTrans
                                               + 2) + 8) + 6) - 1);
      *(ushort *)((int)o->description + 0x28) = *(ushort *)((int)o->description + 0x28) & 0xfffe;
    }
  }
  while ((o_00 = Monster_GetChild(o,0x6f), o_00 != (_D3_OBJECT *)0x0 &&
         (o_00 = o_00->child, o_00 != (_D3_OBJECT *)0x0))) {
    if (!bVar1) {
      D3_ClearCollBits(o,9);
      o_01 = o_00;
      if (o_00->next != (_D3_OBJECT *)0x0) {
        o_01 = o_00->next;
      }
      while ((Anim = Pvl_TestStateBits(o_00,2), Anim == 0 &&
             (Anim = Pvl_TestStateBits(o_01,2), Anim == 0))) {
        Task_Next();
      }
      Door_DisplayChild(o,1);
      Anim = Pvl_TestStateBits(o_00,2);
      if (Anim == 0) {
        p_Var6 = o->child;
        if (((int)p_Var6->collision_mode & 0x8000U) == 0) {
          p_Var6 = p_Var6->next;
        }
        (p_Var6->pos).vx = (o->pos).vx + -0x14;
        obj = (M_OBJECT *)o->description;
        Anim = 1;
      }
      else {
        p_Var6 = o->child;
        if (((int)p_Var6->collision_mode & 0x8000U) == 0) {
          p_Var6 = p_Var6->next;
        }
        (p_Var6->rot).vz = (p_Var6->rot).vz + 0x800U & 0xfff;
        (p_Var6->pos).vx = (o->pos).vx + 0xf;
        obj = (M_OBJECT *)o->description;
        Anim = 0;
      }
      Manim_SetAnim(obj,Anim);
      D3_DeleteObject(o_00);
      D3_DeleteObject(o_01);
      D3_PlaySound(o,0);
      Manim_WaitAnim((M_OBJECT *)o->description);
      *(ushort *)((int)o->description + 0x28) = *(ushort *)((int)o->description + 0x28) & 0xfffe;
      *(undefined4 *)&o[1].last_pos = 1;
      Door_ActivateChild(o,1);
      Pvl_SetStateBits(o,1);
      return;
    }
    Anim = Pvl_TestStateBits(o_00,2);
    if (Anim == 0) {
      while (Anim = Pvl_TestStateBits(o_00,2), Anim == 0) {
        Task_Next();
      }
    }
    else {
      while (Anim = Pvl_TestStateBits(o_00,2), Anim != 0) {
        Task_Next();
      }
    }
    if ((Pvl_SctState[(int)o->index] & 1U) == 0) {
      Door_DisplayChild(o,1);
      Door_Slide_Move(o,speed,&local_30,0,1);
      *(undefined4 *)&o[1].last_pos = 1;
      Door_ActivateChild(o,1);
      iVar3 = (int)*(short *)((int)&o[1].handle + 2);
      if (iVar3 != -1) {
        Pvl_EnemyZones[iVar3].flags = Pvl_EnemyZones[iVar3].flags | 1;
      }
    }
    else {
      Door_ActivateChild(o,0);
      Door_Slide_Move(o,-speed,&local_30,0,1);
      Door_DisplayChild(o,0);
      iVar3 = (int)*(short *)((int)&o[1].handle + 2);
      if (iVar3 != -1) {
        Pvl_EnemyZones[iVar3].flags = Pvl_EnemyZones[iVar3].flags & 0xfe;
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Door_EnemyTurn(struct _D3_OBJECT *o /*$s0*/)
 // line 320, offset 0x8004eb74
	/* begin block 1 */
		// Start line: 321
		// Start offset: 0x8004EB74
		// Variables:
	// 		struct _ZONE *z; // $a1
	// 		long distance; // $s3
	// 		long speed; // $s2
	// 		long i; // $a3
	// 		struct _D3_OBJECT *tmp; // $a0
	// 		struct _MONSTER *monst; // $a2
	// 		long oneinzone; // $s1
	/* end block 1 */
	// End offset: 0x8004EE70
	// End Line: 383

	/* begin block 2 */
		// Start line: 667
	/* end block 2 */
	// End Line: 668

void Door_EnemyTurn(_D3_OBJECT *o)

{
  short sVar1;
  bool bVar2;
  _ZONE *p_Var3;
  _D3_OBJECT *p_Var4;
  int iVar5;
  int iVar6;
  int speed;
  int Distance;
  
  if ((Pvl_LevelNumber == 4) && (Pvl_SectorNumber == 5)) {
    D3_SetCollBits(o,9);
  }
  else {
    D3_ClearCollBits(o,4);
  }
  sVar1 = o[1].pos.pad;
  o[1].pos.vy = o[1].pos.vy & 0xfU | (ushort)((int)(o->rot).vz << 4);
  speed = (int)o[1].pos.vz;
  Distance = (int)sVar1 * 100;
  do {
    while( true ) {
      p_Var3 = Zone_GetObjectZone(o);
      iVar6 = 0;
      bVar2 = false;
      if (0 < p_Var3->nObjects) {
        do {
          p_Var4 = p_Var3->Tab_Objects[iVar6];
          iVar5 = *(int *)&p_Var4[1].last_pos;
          if (((p_Var4 != o) && ((p_Var4->display_mode & 0x10U) != 0)) &&
             ((Pvl_SctState[(int)p_Var4->index] & 2U) == 0)) {
            sVar1 = (p_Var4->pos).vx;
            if (((p_Var3->x1 < sVar1) && (sVar1 < p_Var3->x2)) &&
               ((sVar1 = (p_Var4->pos).vy, p_Var3->y1 < sVar1 && (sVar1 < p_Var3->y2)))) {
              bVar2 = true;
              if (*(int *)(iVar5 + 0xfc) != 0) {
                *(_D3_OBJECT **)(iVar5 + 0xfc) = o;
              }
            }
            else {
              if (*(_D3_OBJECT **)(iVar5 + 0xfc) == o) {
                *(undefined4 *)(iVar5 + 0xfc) = 0;
              }
            }
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < (int)p_Var3->nObjects);
      }
      if (bVar2) break;
      if ((Pvl_SctState[(int)o->index] & 1U) == 0) {
LAB_8004ee60:
        Task_Next();
      }
      else {
        if ((Pvl_LevelNumber == 4) && (Pvl_SectorNumber == 5)) {
          D3_ClearCollBits(o,9);
        }
        Door_Turn_Move(o,Distance,-speed,2);
        (o->rot).vz = o[1].pos.vy >> 4;
      }
    }
    if ((Pvl_SctState[(int)o->index] & 1U) != 0) goto LAB_8004ee60;
    if ((Pvl_LevelNumber == 4) && (Pvl_SectorNumber == 5)) {
      D3_ClearCollBits(o,9);
    }
    Door_Turn_Move(o,Distance,speed,2);
    if ((Pvl_LevelNumber == 4) && (Pvl_SectorNumber == 5)) {
      D3_SetCollBits(o,9);
    }
  } while( true );
}



// decompiled code
// original method signature: 
// long /*$ra*/ CDoor_ShouldOpen(struct _D3_OBJECT *o /*$s1*/, long testkey /*$a1*/, long zoneattached /*$a2*/, long *Zone_Result /*$s0*/)
 // line 386, offset 0x8004ee70
	/* begin block 1 */
		// Start line: 387
		// Start offset: 0x8004EE70
		// Variables:
	// 		struct CDOOR_104fake t; // stack offset -48
	// 		unsigned long key; // $s2
	// 		long i; // $s0
	// 		long zone; // $v1
	/* end block 1 */
	// End offset: 0x8004F048
	// End Line: 440

	/* begin block 2 */
		// Start line: 833
	/* end block 2 */
	// End Line: 834

long CDoor_ShouldOpen(_D3_OBJECT *o,long testkey,long zoneattached,long *Zone_Result)

{
  ushort uVar1;
  short sVar2;
  long lVar3;
  int index;
  uint uVar4;
  undefined auStack48 [32];
  
  uVar4 = 0xffffffff;
  if (testkey != 0) {
    uVar4 = Scts_Interruptors;
  }
  if (zoneattached == 0) {
    uVar1 = o->collision_state;
    if ((uVar1 & 0x100) == 0) goto LAB_8004eee8;
    o->collision_state = uVar1 & 0xfeff;
    if ((uVar1 & 1) == 0) {
      return 0;
    }
    index = o[1].color;
    o->collision_state = uVar1 & 0xfefe;
    if ((*(ushort *)(index + 0x1c) & 0x1010) == 0) {
      return 0;
    }
  }
  else {
    lVar3 = Task_EventRead(TaskCurrent);
    if (Zone_Result != (long *)0x0) {
      *Zone_Result = lVar3;
    }
    if (lVar3 != 2) {
LAB_8004eee8:
      o[1].pos.vy = o[1].pos.vy & 0xffef;
      return 0;
    }
  }
  if ((uVar4 & *(uint *)&o[1].last_pos) == *(uint *)&o[1].last_pos) {
    return (uint)(byte)Pvl_SctState[(int)o->index] & 1 ^ 1;
  }
  if (*(short *)((int)&o[1].prec + 2) != -1) {
    uVar1 = o[1].pos.vy;
    if ((uVar1 & 0x10) == 0) {
      o[1].pos.vy = uVar1 | 0x10;
      Text_SetContext((TEXT_102fake *)auStack48);
      Text_SetContextFont(0x70);
      Text_SetContextXY(0,0);
      Text_SetContextWH(Scr_W,Scr_H);
      Text_SetContextRange(0);
      Text_SetContextMode(0);
      index = 0;
      while (sVar2 = Text_AmountOfTexts((char *)Pvl_Texts[(int)*(short *)((int)&o[1].prec + 2)]),
            index < (int)sVar2) {
        Text_DisplayLine((char *)Pvl_Texts[(int)*(short *)((int)&o[1].prec + 2)],index,0x32,
                         (long *)0x0);
        index = index + 1;
      }
      return 0;
    }
    return 0;
  }
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Door_Dive_Once(struct _D3_OBJECT *D3Obj /*$s0*/, long testkey /*$s5*/)
 // line 443, offset 0x8004f060
	/* begin block 1 */
		// Start line: 444
		// Start offset: 0x8004F060
		// Variables:
	// 		long zoneattached; // $s1
	// 		long Xs[2]; // stack offset -40
	// 		long distance; // $a1
	// 		long speed; // $s2
	// 		long exhitpoints; // $s4
	/* end block 1 */
	// End offset: 0x8004F294
	// End Line: 488

	/* begin block 2 */
		// Start line: 959
	/* end block 2 */
	// End Line: 960

void Door_Dive_Once(_D3_OBJECT *D3Obj,long testkey)

{
  short sVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  long zoneattached;
  int speed;
  int local_28;
  int local_24;
  
  zoneattached = 0;
  sVar1 = D3Obj->hit_points;
  iVar3 = (int)D3Obj[1].pos.pad;
  speed = (int)D3Obj[1].pos.vz;
  local_28 = (int)(D3Obj->pos).vz << 0xc;
  if (speed < 0) {
    local_24 = (int)(D3Obj->pos).vz * 0x1000 + iVar3 * -0x640;
  }
  else {
    local_24 = (int)(D3Obj->pos).vz * 0x1000 + iVar3 * 0x640;
  }
  if ((Pvl_SctState[(int)D3Obj->index] & 1U) == 0) {
    lVar2 = Zone_IsZoneAttached(D3Obj);
    if (lVar2 != 0) {
      zoneattached = 1;
    }
    while( true ) {
      if ((sVar1 != 0) && (D3Obj->hit_points == 0)) {
        return;
      }
      lVar2 = CDoor_ShouldOpen(D3Obj,testkey,zoneattached,(long *)0x0);
      if (lVar2 != 0) break;
      Task_Next();
    }
    D3_SetBonuses(D3Obj,1,D3Obj);
    Invent_RemoveUsedKey(*(long *)&D3Obj[1].last_pos,0);
    Door_Slide_Dive(D3Obj,speed,&local_28,0);
    iVar3 = (int)*(short *)((int)&D3Obj[1].handle + 2);
    if (iVar3 != -1) {
      Pvl_EnemyZones[iVar3].flags = Pvl_EnemyZones[iVar3].flags & 0xfe;
    }
    if ((((Pvl_LevelNumber == 3) && (Pvl_SectorNumber == 2)) ||
        ((Pvl_LevelNumber == 5 && (Pvl_SectorNumber == 3)))) ||
       ((Pvl_LevelNumber == 6 && ((Pvl_SectorNumber == 10 || (Pvl_SectorNumber == 0xb)))))) {
      SFX_ShakeScreen(0x28,0xc);
      Fx_Play(0x36,(char)D3Obj + ',');
    }
  }
  else {
    iVar4 = (int)*(short *)((int)&D3Obj[1].handle + 2);
    if (iVar4 != -1) {
      Pvl_EnemyZones[iVar4].flags = Pvl_EnemyZones[iVar4].flags & 0xfe;
    }
    Door_End_Dive(D3Obj,iVar3 * 100,speed);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Door_Slide_Once(struct _D3_OBJECT *D3Obj /*$s0*/, long testkey /*$s6*/)
 // line 491, offset 0x8004f2b8
	/* begin block 1 */
		// Start line: 492
		// Start offset: 0x8004F2B8
		// Variables:
	// 		long zoneattached; // $s4
	// 		long speed; // $s2
	// 		long distance; // $s3
	// 		long multiplier; // $s1
	// 		long X; // $v0
	// 		long Y; // $v1
	// 		long Xs[4]; // stack offset -48
	// 		long exhitpoints; // $s5
	/* end block 1 */
	// End offset: 0x8004F558
	// End Line: 543

	/* begin block 2 */
		// Start line: 1061
	/* end block 2 */
	// End Line: 1062

void Door_Slide_Once(_D3_OBJECT *D3Obj,long testkey)

{
  short sVar1;
  int iVar2;
  long lVar3;
  int speed;
  uint uVar4;
  int iVar5;
  int Distance;
  long zoneattached;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  
  sVar1 = D3Obj->hit_points;
  local_30 = (int)(D3Obj->pos).vx << 0xc;
  iVar5 = 1;
  local_2c = (int)(D3Obj->pos).vy << 0xc;
  Distance = (int)D3Obj[1].pos.pad * 100;
  speed = (int)*(short *)((int)&D3Obj->b_sunk + 2) - (int)*(short *)((int)&D3Obj->b_step + 2);
  if (speed < 0) {
    speed = -speed;
  }
  iVar2 = (int)*(short *)&D3Obj->b_step - (int)(D3Obj->b_box).vx;
  if (iVar2 < 0) {
    iVar2 = -iVar2;
  }
  zoneattached = 0;
  if (D3Obj[1].pos.vz < 0) {
    iVar5 = -1;
  }
  if (speed < iVar2) {
    speed = rsin((int)(D3Obj->rot).vz);
    local_24 = local_2c + (-speed * Distance * iVar5 >> 8);
    uVar4 = SEXT24((D3Obj->rot).vz);
  }
  else {
    speed = rsin((int)(D3Obj->rot).vz - 0x400);
    local_24 = local_2c + (-speed * Distance * iVar5 >> 8);
    uVar4 = (int)(D3Obj->rot).vz - 0x400;
  }
  speed = rcos(uVar4);
  local_28 = local_30 + (speed * Distance * iVar5 >> 8);
  speed = (int)D3Obj[1].pos.vz;
  if ((Pvl_SctState[(int)D3Obj->index] & 1U) == 0) {
    lVar3 = Zone_IsZoneAttached(D3Obj);
    if (lVar3 != 0) {
      zoneattached = 1;
    }
    while( true ) {
      if ((sVar1 != 0) && (D3Obj->hit_points == 0)) {
        return;
      }
      lVar3 = CDoor_ShouldOpen(D3Obj,testkey,zoneattached,(long *)0x0);
      if (lVar3 != 0) break;
      Task_Next();
    }
    D3_SetBonuses(D3Obj,1,D3Obj);
    Invent_RemoveUsedKey(*(long *)&D3Obj[1].last_pos,0);
    Door_Slide_Move(D3Obj,speed,&local_30,0,0);
    speed = (int)*(short *)((int)&D3Obj[1].handle + 2);
    if (speed != -1) {
      Pvl_EnemyZones[speed].flags = Pvl_EnemyZones[speed].flags & 0xfe;
    }
  }
  else {
    iVar5 = (int)*(short *)((int)&D3Obj[1].handle + 2);
    if (iVar5 != -1) {
      Pvl_EnemyZones[iVar5].flags = Pvl_EnemyZones[iVar5].flags & 0xfe;
    }
    Door_End_Move(D3Obj,Distance,speed,0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Door_Turn_Once(struct _D3_OBJECT *D3Obj /*$s3*/, long testkey /*$s0*/, long type /*$s5*/)
 // line 546, offset 0x8004f580
	/* begin block 1 */
		// Start line: 547
		// Start offset: 0x8004F580
		// Variables:
	// 		struct _D3_OBJECT *tmpobj; // $s0
	// 		long zoneattached; // $s6
	// 		long speed; // $s4
	// 		long distance; // $s7
	// 		long exhitpoints; // $fp
	// 		long fathersOK; // $s2
	// 		struct _D3_OBJECT *tmp; // $s0
	// 		struct _D3_OBJECT *tmp2; // $s1
	/* end block 1 */
	// End offset: 0x8004F9DC
	// End Line: 662

	/* begin block 2 */
		// Start line: 1185
	/* end block 2 */
	// End Line: 1186

void Door_Turn_Once(_D3_OBJECT *D3Obj,long testkey,long type)

{
  short sVar1;
  short sVar2;
  bool bVar3;
  _D3_OBJECT *p_Var4;
  ushort uVar5;
  long lVar6;
  long lVar7;
  _D3_OBJECT *o;
  ushort uVar8;
  int speed;
  int Distance;
  
  sVar1 = D3Obj->hit_points;
  uVar8 = D3Obj[1].pos.vy & 0xf;
  if (type == 1) {
    uVar5 = (ushort)((int)(D3Obj->rot).vy << 4);
  }
  else {
    if (type < 2) {
      if (type != 0) goto LAB_8004f624;
      uVar5 = (ushort)((int)(D3Obj->rot).vx << 4);
    }
    else {
      if (type != 2) goto LAB_8004f624;
      uVar5 = (ushort)((int)(D3Obj->rot).vz << 4);
    }
  }
  uVar8 = uVar8 | uVar5;
LAB_8004f624:
  sVar2 = D3Obj[1].pos.pad;
  D3Obj[1].pos.vy = uVar8;
  speed = (int)D3Obj[1].pos.vz;
  Distance = (int)sVar2 * 100;
  if ((Pvl_SctState[(int)D3Obj->index] & 1U) == 0) {
    if ((D3Obj->child != (_D3_OBJECT *)0x0) &&
       ((*(uint *)&D3Obj->child[1].pos & 0xffffff00) == 0xb0800)) {
      Invent_RemoveUsedKey(0x400000,1);
      D3Obj->child->display_mode = D3Obj->child->display_mode & 0xffef;
      D3_ClearCollBits(D3Obj->child,9);
      o = Pvl_GlobalObjects;
      if ((Scts_Interruptors & 0x1000000U) != 0) {
        while (o != (_D3_OBJECT *)0x0) {
          if ((*(uint *)&o[1].pos & 0xffffff00) == 0xd0300) {
            o->display_mode = o->display_mode & 0xffef;
            D3_ClearCollBits(o,9);
          }
          o = o->next;
        }
        do {
          Task_Next();
        } while( true );
      }
    }
    lVar6 = Zone_IsZoneAttached(D3Obj);
    if ((testkey != 0) && (*(int *)&D3Obj[1].last_pos == 0)) {
      while( true ) {
        o = D3Obj->father;
        bVar3 = true;
        while (p_Var4 = o, o != (_D3_OBJECT *)0x0) {
          while (p_Var4 != (_D3_OBJECT *)0x0) {
            if (((uint)*(byte *)((int)&o[1].pos.vx + 1) - 6 < 2) &&
               ((lVar7 = Pvl_TestStateBits(o,2), lVar7 == 0 ||
                (lVar7 = Pvl_TestStateBits(o,1), lVar7 != 0)))) {
              bVar3 = false;
            }
            p_Var4 = p_Var4->next;
          }
          o = o->father;
        }
        testkey = 0;
        if (bVar3) break;
        Task_Next();
        *(undefined4 *)&D3Obj[1].last_pos = 0xffffffff;
        CDoor_ShouldOpen(D3Obj,1,0,(long *)0x0);
        *(undefined4 *)&D3Obj[1].last_pos = 0;
      }
    }
    while( true ) {
      if ((sVar1 != 0) && (D3Obj->hit_points == 0)) {
        return;
      }
      lVar7 = CDoor_ShouldOpen(D3Obj,testkey,(uint)(lVar6 != 0),(long *)0x0);
      if ((lVar7 != 0) || ((testkey != 0 && (*(int *)&D3Obj[1].last_pos == 0)))) break;
      Task_Next();
    }
    if ((Pvl_LevelNumber == 7) && (Pvl_SectorNumber == 10)) {
      o = D3Obj->child;
      Scts_Interruptors = Scts_Interruptors & ~*(uint *)&D3Obj[1].last_pos;
      if (o != (_D3_OBJECT *)0x0) {
        o->display_mode = o->display_mode | 0x10;
        D3_SetCollBits(D3Obj->child,9);
        Scts_Interruptors = Scts_Interruptors | 0x1000000;
      }
    }
    D3_SetBonuses(D3Obj,1,D3Obj);
    Invent_RemoveUsedKey(*(long *)&D3Obj[1].last_pos,0);
    if (type < 2) {
      D3_ClearCollBits(D3Obj,9);
    }
    Door_Turn_Move(D3Obj,Distance,speed,type);
    speed = (int)*(short *)((int)&D3Obj[1].handle + 2);
    if (speed != -1) {
      Pvl_EnemyZones[speed].flags = Pvl_EnemyZones[speed].flags & 0xfe;
    }
  }
  else {
    D3_SetBonuses(D3Obj,1,D3Obj);
    Door_End_Turn(D3Obj,Distance,speed,type);
    speed = (int)*(short *)((int)&D3Obj[1].handle + 2);
    if (speed != -1) {
      Pvl_EnemyZones[speed].flags = Pvl_EnemyZones[speed].flags & 0xfe;
    }
    if (type != 2) {
      D3_ClearCollBits(D3Obj,9);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Door_Dive_Normal(struct _D3_OBJECT *D3Obj /*$s0*/, long testkey /*$s4*/)
 // line 667, offset 0x8004fa0c
	/* begin block 1 */
		// Start line: 668
		// Start offset: 0x8004FA0C
		// Variables:
	// 		long Zone_Result; // stack offset -40
	// 		long zoneattached; // $s2
	// 		long Xs[2]; // stack offset -48
	// 		long distance; // $a1
	// 		long speed; // $s1
	// 		long exhitpoints; // $s5
	/* end block 1 */
	// End offset: 0x8004FC6C
	// End Line: 712

	/* begin block 2 */
		// Start line: 1439
	/* end block 2 */
	// End Line: 1440

void Door_Dive_Normal(_D3_OBJECT *D3Obj,long testkey)

{
  short sVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  int speed;
  int local_30;
  int local_2c;
  long local_28 [2];
  
  sVar1 = D3Obj->hit_points;
  iVar4 = (int)D3Obj[1].pos.pad;
  speed = (int)D3Obj[1].pos.vz;
  local_30 = (int)(D3Obj->pos).vz << 0xc;
  if (speed < 0) {
    local_2c = (int)(D3Obj->pos).vz * 0x1000 + iVar4 * -0x640;
  }
  else {
    local_2c = (int)(D3Obj->pos).vz * 0x1000 + iVar4 * 0x640;
  }
  if ((Pvl_SctState[(int)D3Obj->index] & 1U) == 0) {
    lVar2 = Zone_IsZoneAttached(D3Obj);
    local_28[0] = Task_EventRead(TaskCurrent);
    while ((sVar1 == 0 || (D3Obj->hit_points != 0))) {
      lVar3 = CDoor_ShouldOpen(D3Obj,testkey,(uint)(lVar2 != 0),local_28);
      if (lVar3 == 0) {
        if (((lVar2 != 0) && (local_28[0] != 2)) && ((Pvl_SctState[(int)D3Obj->index] & 1U) != 0)) {
          D3_SetBonuses(D3Obj,0,D3Obj);
          Door_Slide_Dive(D3Obj,-speed,&local_30,0);
          iVar4 = (int)*(short *)((int)&D3Obj[1].handle + 2);
          if (iVar4 != -1) {
            Pvl_EnemyZones[iVar4].flags = Pvl_EnemyZones[iVar4].flags | 1;
          }
        }
        else {
          Task_Next();
        }
      }
      else {
        D3_SetBonuses(D3Obj,1,D3Obj);
        if (testkey != 0) {
          Invent_RemoveUsedKey(*(long *)&D3Obj[1].last_pos,0);
        }
        Door_Slide_Dive(D3Obj,speed,&local_30,0);
        iVar4 = (int)*(short *)((int)&D3Obj[1].handle + 2);
        if (iVar4 != -1) {
          Pvl_EnemyZones[iVar4].flags = Pvl_EnemyZones[iVar4].flags & 0xfe;
        }
      }
    }
  }
  else {
    iVar5 = (int)*(short *)((int)&D3Obj[1].handle + 2);
    if (iVar5 != -1) {
      Pvl_EnemyZones[iVar5].flags = Pvl_EnemyZones[iVar5].flags & 0xfe;
    }
    Door_End_Dive(D3Obj,iVar4 * 100,speed);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Door_Slide_Normal(struct _D3_OBJECT *D3Obj /*$s0*/, long testkey /*$s5*/)
 // line 715, offset 0x8004fc90
	/* begin block 1 */
		// Start line: 716
		// Start offset: 0x8004FC90
		// Variables:
	// 		long Zone_Result; // stack offset -40
	// 		long zoneattached; // $s4
	// 		long distance; // $s2
	// 		long multiplier; // $s1
	// 		long X; // $v0
	// 		long Y; // $v1
	// 		long Xs[4]; // stack offset -56
	// 		long speed; // $s3
	// 		long exhitpoints; // $s6
	/* end block 1 */
	// End offset: 0x8004FFF0
	// End Line: 774

	/* begin block 2 */
		// Start line: 1540
	/* end block 2 */
	// End Line: 1541

void Door_Slide_Normal(_D3_OBJECT *D3Obj,long testkey)

{
  short sVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int Distance;
  int speed;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  long local_28 [2];
  
  sVar1 = D3Obj->hit_points;
  speed = (int)D3Obj[1].pos.vz;
  local_38 = (int)(D3Obj->pos).vx << 0xc;
  iVar7 = 1;
  local_34 = (int)(D3Obj->pos).vy << 0xc;
  Distance = (int)D3Obj[1].pos.pad * 100;
  iVar5 = (int)*(short *)((int)&D3Obj->b_sunk + 2) - (int)*(short *)((int)&D3Obj->b_step + 2);
  if (iVar5 < 0) {
    iVar5 = -iVar5;
  }
  iVar2 = (int)*(short *)&D3Obj->b_step - (int)(D3Obj->b_box).vx;
  if (iVar2 < 0) {
    iVar2 = -iVar2;
  }
  if (speed < 0) {
    iVar7 = -1;
  }
  if (iVar5 < iVar2) {
    iVar5 = rsin((int)(D3Obj->rot).vz);
    local_2c = local_34 + (-iVar5 * Distance * iVar7 >> 8);
    uVar6 = SEXT24((D3Obj->rot).vz);
  }
  else {
    iVar5 = rsin((int)(D3Obj->rot).vz - 0x400);
    local_2c = local_34 + (-iVar5 * Distance * iVar7 >> 8);
    uVar6 = (int)(D3Obj->rot).vz - 0x400;
  }
  iVar5 = rcos(uVar6);
  local_30 = local_38 + (iVar5 * Distance * iVar7 >> 8);
  if ((Pvl_SctState[(int)D3Obj->index] & 1U) != 0) {
    D3_SetBonuses(D3Obj,1,D3Obj);
    Door_End_Move(D3Obj,Distance,speed,0);
    iVar5 = (int)*(short *)((int)&D3Obj[1].handle + 2);
    if (iVar5 != -1) {
      Pvl_EnemyZones[iVar5].flags = Pvl_EnemyZones[iVar5].flags & 0xfe;
    }
  }
  lVar3 = Zone_IsZoneAttached(D3Obj);
  local_28[0] = Task_EventRead(TaskCurrent);
  while ((sVar1 == 0 || (D3Obj->hit_points != 0))) {
    lVar4 = CDoor_ShouldOpen(D3Obj,testkey,1,local_28);
    if (lVar4 == 0) {
      if (((lVar3 == 0) || (local_28[0] == 2)) || ((Pvl_SctState[(int)D3Obj->index] & 1U) == 0)) {
        Task_Next();
      }
      else {
        iVar5 = (int)*(short *)((int)&D3Obj[1].handle + 2);
        if (iVar5 != -1) {
          Pvl_EnemyZones[iVar5].flags = Pvl_EnemyZones[iVar5].flags | 1;
        }
        Door_Slide_Move(D3Obj,-speed,&local_38,4,0);
        D3_SetBonuses(D3Obj,0,D3Obj);
      }
    }
    else {
      D3_SetBonuses(D3Obj,1,D3Obj);
      if (testkey != 0) {
        Invent_RemoveUsedKey(*(long *)&D3Obj[1].last_pos,0);
      }
      Door_Slide_Move(D3Obj,speed,&local_38,1,0);
      iVar5 = (int)*(short *)((int)&D3Obj[1].handle + 2);
      if (iVar5 != -1) {
        Pvl_EnemyZones[iVar5].flags = Pvl_EnemyZones[iVar5].flags & 0xfe;
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Door_Turn_Normal(struct _D3_OBJECT *D3Obj /*$s0*/, long testkey /*$s6*/, long type /*$s3*/)
 // line 778, offset 0x80050018
	/* begin block 1 */
		// Start line: 779
		// Start offset: 0x80050018
		// Variables:
	// 		long Zone_Result; // stack offset -48
	// 		long zoneattached; // $s4
	// 		long distance; // $s2
	// 		long speed; // $s1
	// 		long exhitpoints; // $s7
	/* end block 1 */
	// End offset: 0x800502D0
	// End Line: 832

	/* begin block 2 */
		// Start line: 1677
	/* end block 2 */
	// End Line: 1678

void Door_Turn_Normal(_D3_OBJECT *D3Obj,long testkey,long type)

{
  short sVar1;
  short sVar2;
  ushort uVar3;
  long lVar4;
  int iVar5;
  ushort uVar6;
  int speed;
  int Distance;
  long local_30 [2];
  
  sVar1 = D3Obj->hit_points;
  uVar6 = D3Obj[1].pos.vy & 0xf;
  if (type == 1) {
    uVar3 = (ushort)((int)(D3Obj->rot).vy << 4);
  }
  else {
    if (type < 2) {
      if (type != 0) goto LAB_800500b4;
      uVar3 = (ushort)((int)(D3Obj->rot).vx << 4);
    }
    else {
      if (type != 2) goto LAB_800500b4;
      uVar3 = (ushort)((int)(D3Obj->rot).vz << 4);
    }
  }
  uVar6 = uVar6 | uVar3;
LAB_800500b4:
  sVar2 = D3Obj[1].pos.pad;
  D3Obj[1].pos.vy = uVar6;
  speed = (int)D3Obj[1].pos.vz;
  Distance = (int)sVar2 * 100;
  if ((Pvl_SctState[(int)D3Obj->index] & 1U) != 0) {
    D3_SetBonuses(D3Obj,1,D3Obj);
    Door_End_Turn(D3Obj,Distance,speed,type);
    iVar5 = (int)*(short *)((int)&D3Obj[1].handle + 2);
    if (iVar5 != -1) {
      Pvl_EnemyZones[iVar5].flags = Pvl_EnemyZones[iVar5].flags & 0xfe;
    }
  }
  Zone_IsZoneAttached(D3Obj);
  local_30[0] = Task_EventRead(TaskCurrent);
  while ((sVar1 == 0 || (D3Obj->hit_points != 0))) {
    lVar4 = CDoor_ShouldOpen(D3Obj,testkey,1,local_30);
    if (lVar4 == 0) {
      if ((local_30[0] == 2) || ((Pvl_SctState[(int)D3Obj->index] & 1U) == 0)) {
        Task_Next();
      }
      else {
        iVar5 = (int)*(short *)((int)&D3Obj[1].handle + 2);
        if (iVar5 != -1) {
          Pvl_EnemyZones[iVar5].flags = Pvl_EnemyZones[iVar5].flags | 1;
        }
        Door_Turn_Move(D3Obj,Distance,-speed,type);
        D3_SetBonuses(D3Obj,0,D3Obj);
        (D3Obj->rot).vz = D3Obj[1].pos.vy >> 4;
      }
    }
    else {
      D3_SetBonuses(D3Obj,1,D3Obj);
      if (testkey != 0) {
        Invent_RemoveUsedKey(*(long *)&D3Obj[1].last_pos,0);
      }
      Door_Turn_Move(D3Obj,Distance,speed,type);
      iVar5 = (int)*(short *)((int)&D3Obj[1].handle + 2);
      if (iVar5 != -1) {
        Pvl_EnemyZones[iVar5].flags = Pvl_EnemyZones[iVar5].flags & 0xfe;
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Door_Turn_Move(struct _D3_OBJECT *D3Obj /*$s3*/, long Distance /*$s2*/, long speed /*$s4*/, long type /*$s5*/)
 // line 837, offset 0x800502fc
	/* begin block 1 */
		// Start line: 838
		// Start offset: 0x800502FC
		// Variables:
	// 		long Angle; // $s1
	// 		long sAngle; // $s0
	// 		long EndDistance; // $s7
	// 		long tmp; // $a0
	// 		long handle; // $s6
	/* end block 1 */
	// End offset: 0x800504C0
	// End Line: 894

	/* begin block 2 */
		// Start line: 1804
	/* end block 2 */
	// End Line: 1805

void Door_Turn_Move(_D3_OBJECT *D3Obj,long Distance,long speed,long type)

{
  short snd_handle;
  short sVar1;
  int iVar2;
  int iVar3;
  int unaff_s1;
  long lVar4;
  int iVar5;
  
  if ((D3Obj->collision_state & 0x80U) == 0) {
    snd_handle = -1;
  }
  else {
    snd_handle = D3_PlaySound(D3Obj,0);
  }
  Pvl_SctState[(int)D3Obj->index] = Pvl_SctState[(int)D3Obj->index] ^ 1;
  iVar5 = Distance >> 2;
  if (type == 1) {
    unaff_s1 = (int)(D3Obj->rot).vy << 0xc;
  }
  else {
    if (type < 2) {
      if (type == 0) {
        unaff_s1 = (int)(D3Obj->rot).vx << 0xc;
      }
    }
    else {
      if (type == 2) {
        unaff_s1 = (int)(D3Obj->rot).vz << 0xc;
      }
    }
  }
  lVar4 = speed;
  if (0 < Distance) {
    do {
      iVar2 = lVar4;
      if (lVar4 < 0) {
        iVar2 = -lVar4;
      }
      Distance = Distance - iVar2;
      unaff_s1 = unaff_s1 + speed * 0x80;
      sVar1 = (short)(unaff_s1 >> 0xc);
      if (type == 1) {
        (D3Obj->rot).vy = sVar1;
      }
      else {
        if (type < 2) {
          if (type == 0) {
            (D3Obj->rot).vx = sVar1;
          }
        }
        else {
          if (type == 2) {
            (D3Obj->rot).vz = sVar1;
          }
        }
      }
      if (Distance < iVar5) {
        iVar2 = speed;
        if (speed < 0) {
          iVar2 = -speed;
        }
        iVar3 = 0;
        if (0x20000 < iVar2) {
          speed = speed - (speed >> 3);
          iVar3 = lVar4 >> 3;
        }
        lVar4 = lVar4 - iVar3;
      }
      do {
        Task_Next();
      } while (((int)D3Obj->collision_state & 0xfc00U) != 0);
    } while (0 < Distance);
  }
  if (snd_handle != -1) {
    D3_StopSound(D3Obj,snd_handle);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Door_End_Turn(struct _D3_OBJECT *D3Obj /*$a0*/, long Distance /*$a1*/, long speed /*$a2*/, long type /*$a3*/)
 // line 897, offset 0x800504ec
	/* begin block 1 */
		// Start line: 898
		// Start offset: 0x800504EC
		// Variables:
	// 		long multiplier; // $v1
	/* end block 1 */
	// End offset: 0x80050574
	// End Line: 913

	/* begin block 2 */
		// Start line: 1927
	/* end block 2 */
	// End Line: 1928

void Door_End_Turn(_D3_OBJECT *D3Obj,long Distance,long speed,long type)

{
  int iVar1;
  
  iVar1 = 1;
  if (speed < 0) {
    iVar1 = -1;
  }
  if (type == 1) {
    (D3Obj->rot).vy = (D3Obj->rot).vy + (short)(iVar1 * Distance >> 5);
    return;
  }
  if (1 < type) {
    if (type != 2) {
      return;
    }
    (D3Obj->rot).vz = (D3Obj->rot).vz + (short)(iVar1 * Distance >> 5);
    return;
  }
  if (type != 0) {
    return;
  }
  (D3Obj->rot).vx = (D3Obj->rot).vx + (short)(iVar1 * Distance >> 5);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Door_MoveChildren(struct _D3_OBJECT *o /*$a0*/, long addx /*$a1*/, long addy /*$a2*/)
 // line 915, offset 0x8005057c
	/* begin block 1 */
		// Start line: 917
		// Start offset: 0x8005057C
		// Variables:
	// 		struct _D3_OBJECT *child; // $v1
	/* end block 1 */
	// End offset: 0x80050600
	// End Line: 938

	/* begin block 2 */
		// Start line: 1963
	/* end block 2 */
	// End Line: 1964

void Door_MoveChildren(_D3_OBJECT *o,long addx,long addy)

{
  _D3_OBJECT *p_Var1;
  
  p_Var1 = o->child;
  while (p_Var1 != (_D3_OBJECT *)0x0) {
    if (*(char *)((int)&p_Var1[1].pos.vx + 1) == '\0') {
      (p_Var1->pos).vx = (p_Var1->pos).vx + (short)addx + (short)addy;
    }
    if ((((p_Var1->collision_mode & 0x10U) != 0) ||
        (*(char *)((int)&p_Var1[1].pos.vx + 1) == '\x03')) && ((p_Var1->collision_mode & 8U) == 0))
    {
      (p_Var1->pos).vx = (p_Var1->pos).vx + (short)addx + (short)addy;
    }
    p_Var1 = p_Var1->next;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Door_End_Move(struct _D3_OBJECT *D3Obj /*$s1*/, long Distance /*$s3*/, long speed /*$t1*/, long direction /*$a3*/)
 // line 940, offset 0x80050608
	/* begin block 1 */
		// Start line: 941
		// Start offset: 0x80050608
		// Variables:
	// 		long xx; // $a3
	// 		long yy; // $v1
	// 		long X; // $t0
	// 		long Y; // $a2
	// 		long sX; // $a1
	// 		long sY; // $s2
	// 		long multiplier; // $s0
	/* end block 1 */
	// End offset: 0x80050700
	// End Line: 969

	/* begin block 2 */
		// Start line: 2010
	/* end block 2 */
	// End Line: 2011

void Door_End_Move(_D3_OBJECT *D3Obj,long Distance,long speed,long direction)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  short sVar7;
  int iVar8;
  
  iVar4 = (int)*(short *)((int)&D3Obj->b_sunk + 2) - (int)*(short *)((int)&D3Obj->b_step + 2);
  if (iVar4 < 0) {
    iVar4 = -iVar4;
  }
  iVar2 = (int)*(short *)&D3Obj->b_step - (int)(D3Obj->b_box).vx;
  if (iVar2 < 0) {
    iVar2 = -iVar2;
  }
  iVar3 = iVar4;
  if (direction != 0) {
    iVar3 = iVar2;
    iVar2 = iVar4;
  }
  iVar4 = 1;
  if (speed < 0) {
    iVar4 = -1;
  }
  if (iVar3 < iVar2) {
    iVar2 = rsin((int)(D3Obj->rot).vz);
    uVar6 = SEXT24((D3Obj->rot).vz);
  }
  else {
    iVar2 = rsin((int)(D3Obj->rot).vz - 0x400);
    uVar6 = (int)(D3Obj->rot).vz - 0x400;
  }
  iVar3 = rcos(uVar6);
  iVar8 = (int)(D3Obj->pos).vx;
  iVar5 = (int)(D3Obj->pos).vy;
  sVar7 = (short)(iVar5 * 0x1000 + (-iVar2 * Distance * iVar4 >> 8) >> 0xc);
  (D3Obj->last_pos).vy = sVar7;
  (D3Obj->pos).vy = sVar7;
  sVar1 = (short)(iVar8 * 0x1000 + (iVar3 * Distance * iVar4 >> 8) >> 0xc);
  (D3Obj->pos).vx = sVar1;
  (D3Obj->last_pos).vx = sVar1;
  Door_MoveChildren(D3Obj,(int)(D3Obj->pos).vx - iVar8,(int)sVar7 - iVar5);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Door_Slide_Move(struct _D3_OBJECT *D3Obj /*$s6*/, long speed /*$s1*/, long *Xs /*$s0*/, long exzone /*$a3*/, long direction /*stack 16*/)
 // line 981, offset 0x80050768
	/* begin block 1 */
		// Start line: 982
		// Start offset: 0x80050768
		// Variables:
	// 		long X; // $s2
	// 		long Y; // $s4
	// 		long sX; // $s3
	// 		long sY; // $s5
	// 		long EX; // $s7
	// 		long EY; // $a3
	// 		long QuitMove; // $fp
	// 		long tmp; // $v0
	// 		long handle; // stack offset -56
	/* end block 1 */
	// End offset: 0x80050AA0
	// End Line: 1068

	/* begin block 2 */
		// Start line: 2110
	/* end block 2 */
	// End Line: 2111

void Door_Slide_Move(_D3_OBJECT *D3Obj,long speed,long *Xs,long exzone,long direction)

{
  bool bVar1;
  short snd_handle;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  bVar1 = true;
  if ((D3Obj->collision_state & 0x80U) == 0) {
    snd_handle = -1;
  }
  else {
    snd_handle = D3_PlaySound(D3Obj,0);
  }
  D3_SetCollBits(D3Obj,8);
  iVar4 = (int)*(short *)((int)&D3Obj->b_sunk + 2) - (int)*(short *)((int)&D3Obj->b_step + 2);
  if (iVar4 < 0) {
    iVar4 = -iVar4;
  }
  iVar2 = (int)*(short *)&D3Obj->b_step - (int)(D3Obj->b_box).vx;
  if (iVar2 < 0) {
    iVar2 = -iVar2;
  }
  iVar6 = iVar2;
  if (direction != 0) {
    iVar6 = iVar4;
    iVar4 = iVar2;
  }
  if (iVar4 < iVar6) {
    iVar4 = rsin((int)(D3Obj->rot).vz);
    uVar5 = SEXT24((D3Obj->rot).vz);
  }
  else {
    iVar4 = rsin((int)(D3Obj->rot).vz - 0x400);
    uVar5 = (int)(D3Obj->rot).vz - 0x400;
  }
  iVar2 = -iVar4 * speed >> 8;
  iVar4 = rcos(uVar5);
  Pvl_SctState[(int)D3Obj->index] = Pvl_SctState[(int)D3Obj->index] ^ 1;
  iVar4 = iVar4 * speed >> 8;
  if ((Pvl_SctState[(int)D3Obj->index] & 1U) == 0) {
    iVar8 = *Xs;
    iVar6 = Xs[1];
    uVar5 = Xs[2];
    uVar7 = Xs[3];
  }
  else {
    uVar5 = *Xs;
    uVar7 = Xs[1];
    iVar8 = Xs[2];
    iVar6 = Xs[3];
  }
  do {
    iVar3 = iVar6 - uVar7;
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
    if (iVar3 < 0x64000) {
      iVar3 = iVar8 - uVar5;
      if (iVar3 < 0) {
        iVar3 = -iVar3;
      }
      if (iVar3 < 0x64000) {
        iVar3 = iVar4;
        if (iVar4 < 0) {
          iVar3 = -iVar4;
        }
        if (0x2000 < iVar3) {
          iVar4 = iVar4 - (iVar4 >> 3);
        }
        iVar3 = iVar2;
        if (iVar2 < 0) {
          iVar3 = -iVar2;
        }
        if (0x2000 < iVar3) {
          iVar2 = iVar2 - (iVar2 >> 3);
        }
      }
    }
    Door_MoveChildren(D3Obj,((int)uVar5 >> 0xc) - (int)(D3Obj->pos).vx,
                      ((int)uVar7 >> 0xc) - (int)(D3Obj->pos).vy);
    (D3Obj->pos).vx = (short)((int)uVar5 >> 0xc);
    (D3Obj->pos).vy = (short)((int)uVar7 >> 0xc);
    Task_Next();
    uVar5 = (uVar5 & 0xfff) + (int)(D3Obj->pos).vx * 0x1000 + iVar4;
    uVar7 = (uVar7 & 0xfff) + (int)(D3Obj->pos).vy * 0x1000 + iVar2;
    if (iVar4 == 0) {
      if ((0 < iVar2) && (iVar6 < (int)uVar7)) {
        bVar1 = false;
      }
      if ((iVar2 < 0) && ((int)uVar7 < iVar6)) {
        bVar1 = false;
      }
    }
    if (iVar2 == 0) {
      if ((0 < iVar4) && (iVar8 < (int)uVar5)) {
        bVar1 = false;
      }
      if ((iVar4 < 0) && ((int)uVar5 < iVar8)) {
        bVar1 = false;
      }
    }
    if ((0 < iVar4) && (iVar8 < (int)uVar5)) {
      bVar1 = false;
    }
    if ((iVar4 < 0) && ((int)uVar5 < iVar8)) {
      bVar1 = false;
    }
  } while (bVar1);
  (D3Obj->pos).vx = (short)(iVar8 >> 0xc);
  (D3Obj->pos).vy = (short)(iVar6 >> 0xc);
  D3_ClearCollBits(D3Obj,8);
  if (snd_handle != -1) {
    D3_StopSound(D3Obj,snd_handle);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Door_Slide_Dive(struct _D3_OBJECT *D3Obj /*$s4*/, long speed /*$s1*/, long *Xs /*$s0*/, long exzone /*$a3*/)
 // line 1071, offset 0x80050ad0
	/* begin block 1 */
		// Start line: 1072
		// Start offset: 0x80050AD0
		// Variables:
	// 		long Z; // $s1
	// 		long sZ; // $s0
	// 		long EZ; // $s2
	// 		long handle; // $s5
	// 		long tmp; // $v0
	// 		long QuitMove; // $s3
	/* end block 1 */
	// End offset: 0x80050C60
	// End Line: 1121

	/* begin block 2 */
		// Start line: 2302
	/* end block 2 */
	// End Line: 2303

void Door_Slide_Dive(_D3_OBJECT *D3Obj,long speed,long *Xs,long exzone)

{
  bool bVar1;
  short snd_handle;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  bVar1 = true;
  if ((D3Obj->collision_state & 0x80U) == 0) {
    snd_handle = -1;
  }
  else {
    snd_handle = D3_PlaySound(D3Obj,0);
  }
  D3_SetCollBits(D3Obj,8);
  Pvl_SctState[(int)D3Obj->index] = Pvl_SctState[(int)D3Obj->index] ^ 1;
  if ((Pvl_SctState[(int)D3Obj->index] & 1U) == 0) {
    iVar5 = *Xs;
  }
  else {
    iVar5 = Xs[1];
  }
  iVar2 = (int)(D3Obj->pos).vz;
  iVar3 = speed << 4;
  uVar4 = iVar2 * 0x1000;
  iVar2 = iVar2 * -0x1000;
  do {
    iVar2 = iVar5 + iVar2;
    if (iVar2 < 0) {
      iVar2 = -iVar2;
    }
    if (iVar2 < 0x64000) {
      iVar2 = iVar3;
      if (iVar3 < 0) {
        iVar2 = -iVar3;
      }
      if (0x2000 < iVar2) {
        iVar3 = iVar3 - (iVar3 >> 3);
      }
    }
    (D3Obj->pos).vz = (short)((int)uVar4 >> 0xc);
    Task_Next();
    uVar4 = (uVar4 & 0xfff) + (int)(D3Obj->pos).vz * 0x1000 + iVar3;
    if ((0 < iVar3) && (iVar5 < (int)uVar4)) {
      bVar1 = false;
    }
    if ((iVar3 < 0) && ((int)uVar4 < iVar5)) {
      bVar1 = false;
    }
    iVar2 = -uVar4;
  } while (bVar1);
  (D3Obj->pos).vz = (short)(iVar5 >> 0xc);
  D3_ClearCollBits(D3Obj,8);
  if (snd_handle != -1) {
    D3_StopSound(D3Obj,snd_handle);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Door_End_Dive(struct _D3_OBJECT *D3Obj /*$a0*/, long Distance /*$a1*/, long speed /*$a2*/)
 // line 1123, offset 0x80050c88
	/* begin block 1 */
		// Start line: 1125
		// Start offset: 0x80050C88
		// Variables:
	// 		long Z; // $v0
	// 		long sZ; // $-1
	// 		long multiplier; // $v1
	/* end block 1 */
	// End offset: 0x80050C94
	// End Line: 1131

	/* begin block 2 */
		// Start line: 2411
	/* end block 2 */
	// End Line: 2412

void Door_End_Dive(_D3_OBJECT *D3Obj,long Distance,long speed)

{
  short sVar1;
  int iVar2;
  
  iVar2 = 1;
  if (speed < 0) {
    iVar2 = -1;
  }
  sVar1 = (short)((int)(D3Obj->pos).vz * 0x1000 + Distance * 0x10 * iVar2 >> 0xc);
  (D3Obj->last_pos).vz = sVar1;
  (D3Obj->pos).vz = sVar1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Door_GrilleLente(struct _D3_OBJECT *obj /*$s3*/)
 // line 1142, offset 0x80050cc0
	/* begin block 1 */
		// Start line: 1143
		// Start offset: 0x80050CC0
		// Variables:
	// 		struct _D3_OBJECT *ot; // $s4
	// 		struct _D3_OBJECT *oc; // $s0
	// 		struct _ZONE *z; // stack offset -48
	// 		long pos; // $s2
	// 		long speed; // $s7
	// 		long snd; // $s5
	// 		long dead; // $s5
	// 		long half; // $fp
	// 		long cntdown; // $s1
	// 		long cntdownlim; // $s0

		/* begin block 1.1 */
			// Start line: 1227
			// Start offset: 0x80050F0C
			// Variables:
		// 		long i; // $s1

			/* begin block 1.1.1 */
				// Start line: 1237
				// Start offset: 0x80050F30
				// Variables:
			// 		struct CDOOR_7fake exp; // stack offset -56
			/* end block 1.1.1 */
			// End offset: 0x80050F30
			// End Line: 1239
		/* end block 1.1 */
		// End offset: 0x80051038
		// End Line: 1246
	/* end block 1 */
	// End offset: 0x80051078
	// End Line: 1258

	/* begin block 2 */
		// Start line: 2445
	/* end block 2 */
	// End Line: 2446

void Door_GrilleLente(_D3_OBJECT *obj)

{
  ushort uVar1;
  bool bVar2;
  short snd_handle;
  long lVar3;
  _ZONE *z;
  uint uVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  _D3_OBJECT *obj_00;
  int iVar9;
  int iVar10;
  int iVar11;
  
  snd_handle = -1;
  obj->hit_power = 'd';
  lVar3 = Pvl_TestStateBits(obj,1);
  if (lVar3 != 0) {
    (obj->pos).vz = (obj->pos).vz + obj[1].pos.pad;
    do {
      Task_Next();
    } while( true );
  }
  do {
    lVar3 = Task_EventRead(TaskCurrent);
    if (lVar3 == 1) {
      iVar11 = TaskCurrent->event_param;
      z = Zone_GetObjectZone(obj);
      if ((*(ushort *)(iVar11 + 0x1c) & 0x1000) != 0) {
        Pvl_SetStateBits(obj,1);
        D3_SetCollBits(obj,10);
        iVar8 = 0x18;
        iVar10 = (int)(obj->pos).vz << 8;
        uVar1 = obj[1].pos.vz;
        iVar7 = (int)obj[1].pos.pad << 8;
        sVar5 = uVar1 - 1;
        uVar4 = (uint)uVar1 << 0x10;
        iVar6 = (int)uVar4 >> 0x10;
        obj[1].pos.vz = sVar5;
        if (iVar6 == 0) {
          trap(0x1c00);
        }
        if ((iVar6 == -1) && (iVar7 == -0x80000000)) {
          trap(0x1800);
        }
        iVar9 = 10;
        while (sVar5 != -1) {
          if ((((int)obj[1].pos.vz < (int)(iVar6 + (uVar4 >> 0x1f)) >> 1) &&
              (iVar9 = iVar9 + -1, iVar9 == -1)) && (Fx_Play(0xe,0), iVar9 = iVar8, 3 < iVar8)) {
            iVar8 = iVar8 + -1;
            iVar9 = iVar8;
          }
          if (obj[1].pos.vz < 0x14) {
            iVar8 = 1;
          }
          snd_handle = D3_UpdateSound(obj,0,snd_handle);
          iVar10 = iVar10 + iVar7 / iVar6;
          (obj->pos).vz = (short)((uint)iVar10 >> 8);
          Task_Next();
          if (((int)obj->collision_state & 0xfc00U) != 0) {
            iVar10 = (int)(obj->pos).vz << 8;
          }
          Task_Next();
          sVar5 = obj[1].pos.vz + -1;
          obj[1].pos.vz = sVar5;
        }
        if (snd_handle != -1) {
          D3_StopSound(obj,snd_handle);
        }
        D3_ClearCollBits(obj,10);
        bVar2 = false;
        snd_handle = Zone_IsPosInZone(z,(char)iVar11 + ',');
        if (snd_handle != 0) {
          bVar2 = true;
          iVar8 = 0;
          *(undefined2 *)(iVar11 + 0x20) = 0;
          *(ushort *)(iVar11 + 0x11c) = *(ushort *)(iVar11 + 0x11c) & 0xfffb;
          do {
            iVar8 = iVar8 + 1;
            M_rand();
            M_rand();
            M_rand();
            SFX_Explosion(200,1,0);
          } while (iVar8 < 3);
        }
        if (!bVar2) {
          obj_00 = obj->child;
          while (obj_00 != (_D3_OBJECT *)0x0) {
            D3_ExplodeObject(obj_00);
            obj_00 = obj_00->next;
          }
        }
        do {
          Task_Next();
        } while( true );
      }
    }
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_Elevator_Main_Task()
 // line 1297, offset 0x80051078
	/* begin block 1 */
		// Start line: 1298
		// Start offset: 0x80051078
		// Variables:
	// 		struct _D3_OBJECT *D3Obj; // $s0
	// 		long comp; // $v1
	/* end block 1 */
	// End offset: 0x8005121C
	// End Line: 1330

	/* begin block 2 */
		// Start line: 2804
	/* end block 2 */
	// End Line: 2805

/* WARNING: Unknown calling convention yet parameter storage is locked */

void CB_Elevator_Main_Task(void)

{
  long X;
  long Y;
  long Z;
  _D3_OBJECT *D3Obj;
  long local_10;
  
  D3Obj = (_D3_OBJECT *)TaskCurrent->local;
  switch((uint)(ushort)D3Obj[1].pos.vy & 0xf) {
  case 0:
    Platform_Z_Exit(D3Obj,0);
    break;
  case 1:
    Platform_ShootLock(D3Obj);
  case 2:
    Task_Next();
    local_10 = 1;
    X = 0;
    goto LAB_80051118;
  case 3:
    Task_Next();
    local_10 = 0;
    X = 1;
LAB_80051118:
    Platform_Once(D3Obj,local_10,X,0,0);
    break;
  case 4:
    Task_Next();
    local_10 = 0;
    goto LAB_80051140;
  case 5:
    local_10 = 1;
LAB_80051140:
    Platform_Once(D3Obj,0,0,1,local_10);
    break;
  case 6:
    local_10 = 1;
    X = 0;
    Y = 0;
    Z = 1;
    goto LAB_80051214;
  case 7:
    local_10 = 1;
    X = 1;
    Y = 0;
    goto LAB_80051210;
  case 8:
    local_10 = 1;
    goto LAB_80051204;
  case 9:
    Platform_ShootSwitch(D3Obj);
    break;
  case 0xb:
    Platform_Pince_Sucre(D3Obj,0);
    break;
  case 0xc:
    Platform_Pince_Sucre(D3Obj,1);
    break;
  case 0xd:
    local_10 = 0;
    X = 0;
    Y = 0;
    Z = 1;
    goto LAB_80051214;
  case 0xe:
    local_10 = 0;
    X = 1;
    Y = 0;
    goto LAB_80051210;
  case 0xf:
    local_10 = 0;
LAB_80051204:
    X = 0;
    Y = 1;
LAB_80051210:
    Z = 0;
LAB_80051214:
    Platform_Normal(D3Obj,X,Y,Z,local_10);
  }
  Zone_DeleteObject(D3Obj);
  D3Obj->handle = (TASK *)0x0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Platform_ShootSwitch(struct _D3_OBJECT *o /*$s6*/)
 // line 1339, offset 0x80051238
	/* begin block 1 */
		// Start line: 1340
		// Start offset: 0x80051238
		// Variables:
	// 		struct _MONSTER monst; // stack offset -416
	// 		struct CDOOR_7fake pos; // stack offset -64
	// 		struct CDOOR_7fake oldpos; // stack offset -56
	// 		struct _D3_OBJECT *tmpobj; // $s1
	// 		struct _D3_OBJECT *final; // stack offset -48
	// 		struct M_OBJECT *mo; // $fp
	// 		long currentstage; // $s7
	// 		long i; // $s2
	// 		long j; // $s0
	// 		long tmpx; // $s4
	// 		long tmpy; // $s3
	/* end block 1 */
	// End offset: 0x800515F8
	// End Line: 1438

	/* begin block 2 */
		// Start line: 2888
	/* end block 2 */
	// End Line: 2889

/* WARNING: Could not reconcile some variable overlaps */

void Platform_ShootSwitch(_D3_OBJECT *o)

{
  short sVar1;
  short sVar2;
  undefined *puVar3;
  long lVar4;
  uint uVar5;
  int iVar6;
  _D3_OBJECT *p_Var7;
  int childID;
  uint uVar8;
  M_OBJECT *obj;
  _D3_OBJECT *local_1a0 [2];
  undefined auStack407 [11];
  undefined2 local_18c;
  undefined4 local_40;
  uint local_3c;
  undefined4 local_38;
  undefined4 local_34;
  _D3_OBJECT *local_30;
  
  local_30 = Monster_GetChild(o,0x7b);
  obj = (M_OBJECT *)local_30->description;
  local_38 = *(undefined4 *)&o->pos;
  local_34 = *(undefined4 *)&(o->pos).vz;
  *(_D3_OBJECT ***)&o[1].last_pos = local_1a0;
  local_18c = 4;
  local_1a0[0] = o;
  Monster_Main_Init(o);
  childID = 9;
  puVar3 = auStack407;
  do {
    puVar3[0x13c] = 6;
    childID = childID + -1;
    puVar3 = puVar3 + -1;
  } while (-1 < childID);
  D3_SetCollBits(o,0x8000);
  D3_SetCollBits(o,9);
  (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
  p_Var7 = o;
  childID = 1;
  do {
    Task_Next();
    iVar6 = childID;
    if (o->hit_points == 0) {
      uVar8 = 0;
      Fx_Play((short)(((uint)*(ushort *)((int)&o->father[1].father + 2) + 1) * 0x10000 >> 0x10),200)
      ;
      sVar1 = (p_Var7->pos).vx;
      sVar2 = (p_Var7->pos).vy;
      do {
        local_40 = *(uint *)&p_Var7->pos;
        local_3c = *(uint *)&(p_Var7->pos).vz;
        lVar4 = M_rand();
        local_3c = local_3c & 0xffff0000 |
                   (uint)(ushort)((short)local_3c + (short)lVar4 + (short)(lVar4 / 400) * -400);
        uVar5 = M_rand();
        iVar6 = rcos(uVar5 & 0xfff);
        local_40 = local_40 & 0xffff0000 |
                   (uint)(ushort)((short)local_40 + (short)(iVar6 * 100 >> 0xc));
        iVar6 = rsin(uVar5 & 0xfff);
        local_40 = local_40 & 0xffff |
                   (uint)(ushort)(local_40._2_2_ + (short)(iVar6 * 100 >> 0xc)) << 0x10;
        Impact_Smoke(0xc0,0);
        if (uVar8 == 0xe) {
          Impact_Stone(0xc0,0xf);
        }
        if (uVar8 == 7) {
          Impact_Stone(0xc0,0xf);
        }
        if ((uVar8 & 1) == 0) {
          (p_Var7->pos).vx = sVar1;
          (p_Var7->pos).vy = sVar2;
        }
        else {
          (p_Var7->pos).vx = sVar1 + 4;
          (p_Var7->pos).vy = sVar2 + 4;
        }
        uVar8 = uVar8 + 1;
        Task_Next();
      } while ((int)uVar8 < 0x28);
      iVar6 = childID + 1;
      p_Var7->display_mode = p_Var7->display_mode & 0xffef;
      p_Var7 = Monster_GetChild(o,childID);
      if (p_Var7 == (_D3_OBJECT *)0x0) {
        iVar6 = 10;
      }
      else {
        sVar1 = p_Var7->hit_points;
        p_Var7[1].pos.vz = 0;
        o->hit_points = sVar1;
        p_Var7->display_mode = p_Var7->display_mode | 0x10;
        *(undefined4 *)&p_Var7->pos = local_38;
        *(undefined4 *)&(p_Var7->pos).vz = local_34;
      }
    }
    childID = iVar6;
  } while (iVar6 != 10);
  Pvl_SetStateBits(o,2);
  local_30->display_mode = local_30->display_mode | 0x10;
  D3_ClearCollBits(o,9);
  D3_SetCollBits(local_30,9);
  Impact_Stone((char)o + ',',0x10);
  Manim_SetAnim(obj,0);
  while (((obj->Env).Obj.normal_top.vx & 0x4000U) == 0) {
    if (((obj->Env).Obj.vert_top.pad & 1U) != 0) {
      D3_PlaySoundCamera(o->father,2);
    }
    if (((obj->Env).Obj.vert_top.pad & 2U) != 0) {
      D3_PlaySoundCamera(o->father,0);
    }
    Task_Next();
  }
  (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
  local_30->display_mode = local_30->display_mode & 0xffef;
  local_30 = Monster_GetChild(o,0x141);
  local_30->display_mode = local_30->display_mode | 0x10;
  do {
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Platform_ShootLock(struct _D3_OBJECT *o /*$s5*/)
 // line 1441, offset 0x800515f8
	/* begin block 1 */
		// Start line: 1442
		// Start offset: 0x800515F8
		// Variables:
	// 		struct _D3_OBJECT *dad; // $s6
	// 		struct _D3_OBJECT *one; // $s1
	// 		struct _D3_OBJECT *two; // $s3
	// 		struct _D3_OBJECT *three; // $s4
	// 		long timer; // $s2
	// 		long counter; // $s0
	/* end block 1 */
	// End offset: 0x8005176C
	// End Line: 1494

	/* begin block 2 */
		// Start line: 3152
	/* end block 2 */
	// End Line: 3153

void Platform_ShootLock(_D3_OBJECT *o)

{
  _D3_OBJECT *p_Var1;
  _D3_OBJECT *p_Var2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  _D3_OBJECT *p_Var6;
  
  p_Var6 = o->father;
  p_Var1 = Monster_GetChild(o,1);
  p_Var2 = Monster_GetChild(o,2);
  iVar5 = 0;
  iVar4 = 0;
  if (p_Var6 == (_D3_OBJECT *)0x0) {
    return;
  }
  o->hit_points = 0x1000;
LAB_8005166c:
  while( true ) {
    do {
      while( true ) {
        Task_Next();
        if (((o->hit_points != 0x1000) &&
            (o->hit_points = 0x1000, *(char *)((int)&p_Var6[1].pos.vx + 1) < '\x02')) &&
           (iVar5 == 0)) {
          iVar4 = iVar4 + 1;
          D3_PlaySound(o,0);
          if (iVar4 == 3) {
            iVar4 = 0;
            *(undefined *)((int)&p_Var6[1].pos.vx + 1) = 3;
            iVar5 = 0x3c;
          }
        }
        o->display_mode = o->display_mode & 0xffef;
        p_Var1->display_mode = p_Var1->display_mode & 0xffef;
        uVar3 = p_Var2->display_mode & 0xffef;
        p_Var2->display_mode = uVar3;
        if (iVar4 != 1) break;
        p_Var1->display_mode = p_Var1->display_mode | 0x10;
      }
      if (1 < iVar4) goto LAB_80051718;
    } while (iVar4 != 0);
    if (iVar5 != 0) break;
    p_Var2->display_mode = uVar3 | 0x10;
  }
  uVar3 = o->display_mode;
  iVar5 = iVar5 + -1;
  goto code_r0x80051760;
LAB_80051718:
  if (iVar4 == 2) {
    uVar3 = o->display_mode;
code_r0x80051760:
    o->display_mode = uVar3 | 0x10;
  }
  goto LAB_8005166c;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Platform_Pince_Sucre(struct _D3_OBJECT *D3Obj /*$s2*/, long Retour /*stack 4*/)
 // line 1503, offset 0x8005179c
	/* begin block 1 */
		// Start line: 1504
		// Start offset: 0x8005179C
		// Variables:
	// 		struct M_OBJECT *mo; // $s1
	// 		long distance; // stack offset -56
	// 		unsigned long key; // $a0
	// 		long fixX; // stack offset -52
	// 		long fixY; // stack offset -48
	// 		long fixZ; // stack offset -44
	// 		long i; // $s0
	// 		long speed; // $s6
	// 		long Fx_HandleX; // $s4
	// 		long Fx_HandleZ; // $s0
	// 		long Grabbed; // $s5
	// 		struct _PLAYER *colli; // $s7
	// 		struct CDOOR_70fake shp; // stack offset -152
	// 		struct CDOOR_31fake pft4[2]; // stack offset -136
	/* end block 1 */
	// End offset: 0x80051CA8
	// End Line: 1638

	/* begin block 2 */
		// Start line: 3279
	/* end block 2 */
	// End Line: 3280

/* WARNING: Could not reconcile some variable overlaps */

void Platform_Pince_Sucre(_D3_OBJECT *D3Obj,long Retour)

{
  ushort uVar1;
  bool bVar2;
  short snd_handle;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  M_OBJECT *obj;
  int iVar7;
  _PLAYER *pl;
  SHAPE_68fake local_98;
  SHAPE_31fake SStack136;
  SHAPE_31fake SStack96;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  local_98.file = Pl_Pcl;
  obj = (M_OBJECT *)D3Obj->description;
  local_38 = (int)D3Obj[1].pos.pad * 100;
  iVar7 = 0x10;
  if (local_38 < 0) {
    local_38 = local_38 + 0x1f;
  }
  local_38 = local_38 >> 0xd;
  *(SHAPE_31fake **)&(obj->Env).Obj.vert_top = &SStack136;
  local_98.shape = 0x25;
  Shp_SetPolyFT4(&SStack136,&local_98,0,0);
  Shp_SetPolyFT4(&SStack96,&local_98,0,0);
  local_34 = (int)(D3Obj->pos).vx;
  D3Obj->display_mode = D3Obj->display_mode | 0x80;
  local_30 = (int)(D3Obj->pos).vy;
  local_2c = (int)(D3Obj->pos).vz;
  D3_SetBox(D3Obj,-0x32,-0x32,0,0x32,0x32,200);
  D3_SetCollBits(D3Obj,(long)&DAT_00002008);
  do {
    bVar2 = false;
    uVar4 = *(uint *)&D3Obj[1].last_pos;
    uVar3 = Scts_Interruptors & uVar4;
    (D3Obj->pos).vz = (short)local_2c;
    if (uVar3 != uVar4) {
      do {
        Task_Next();
      } while ((Scts_Interruptors & *(uint *)&D3Obj[1].last_pos) != *(uint *)&D3Obj[1].last_pos);
    }
    (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
    iVar5 = 0;
    if (0 < D3Obj[1].pos.vz) {
      do {
        iVar5 = iVar5 + 1;
        Task_Next();
      } while (iVar5 < (int)D3Obj[1].pos.vz);
    }
    snd_handle = D3_PlaySound(D3Obj,4);
    Manim_SetAnim(obj,0);
    while (((obj->Env).Obj.normal_top.vx & 0x4000U) == 0) {
      Task_Next();
      if ((((((int)(obj->Env).Obj.vert_top.pad & 0x8000U) != 0) && (!bVar2)) &&
          (((int)D3Obj->collision_state & 0xfc00U) != 0)) &&
         (pl = *(_PLAYER **)&D3Obj[1].hit_points, ((pl->obj).collision_mode & 0x1000U) != 0)) {
        bVar2 = true;
        Pl_ForceAction(pl,0xc,(long)D3Obj);
      }
      if (((obj->Env).Obj.vert_top.pad & 1U) != 0) {
        D3_StopSound(D3Obj,snd_handle);
      }
      if (((obj->Env).Obj.vert_top.pad & 2U) != 0) {
        D3_PlaySound(D3Obj,0);
      }
      if (((obj->Env).Obj.vert_top.pad & 4U) != 0) {
        snd_handle = D3_PlaySound(D3Obj,4);
      }
    }
    D3_StopSound(D3Obj,snd_handle);
    snd_handle = D3_PlaySound(D3Obj,2);
    Manim_SetAnim(obj,1);
    iVar5 = local_38 << 1;
    iVar6 = 0;
    if (0 < iVar5) {
      do {
        (D3Obj->pos).vx = (D3Obj->pos).vx + (short)iVar7;
        Task_Next();
        if (((int)(obj->Env).Obj.vert_top.pad & 0x8000U) != 0) {
          (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < iVar5);
    }
    (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx | 1;
    D3_StopSound(D3Obj,snd_handle);
    D3_PlaySound(D3Obj,1);
    Manim_WaitEvent(obj,0x4000);
    snd_handle = D3_PlaySound(D3Obj,4);
    Manim_WaitAnim(obj);
    D3_StopSound(D3Obj,snd_handle);
    D3_PlaySound(D3Obj,0);
    Manim_SetAnim(obj,2);
    while (((obj->Env).Obj.normal_top.vx & 0x4000U) == 0) {
      Task_Next();
      if ((((int)(obj->Env).Obj.vert_top.pad & 0x8000U) != 0) && (bVar2)) {
        Pl_ForceAction(pl,0xd,(long)D3Obj);
      }
      if (((obj->Env).Obj.vert_top.pad & 1U) != 0) {
        snd_handle = D3_PlaySound(D3Obj,4);
      }
    }
    D3_StopSound(D3Obj,snd_handle);
    if (bVar2) {
      if (Retour != 0) {
        iVar7 = -iVar7;
        goto LAB_80051ba4;
      }
LAB_80051bbc:
      snd_handle = D3_PlaySound(D3Obj,2);
      Manim_SetAnim(obj,3);
      (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
      iVar5 = local_38 << 1;
      iVar6 = 0;
      if (0 < iVar5) {
        do {
          (D3Obj->pos).vx = (D3Obj->pos).vx - (short)iVar7;
          Task_Next();
          uVar1 = (obj->Env).Obj.normal_top.vx;
          if ((uVar1 & 0x4000) != 0) {
            (obj->Env).Obj.normal_top.vx = uVar1 & 0xfffe;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < iVar5);
      }
      D3_StopSound(D3Obj,snd_handle);
      D3_PlaySound(D3Obj,1);
      Manim_SetAnim(obj,4);
      Manim_WaitAnim(obj);
      if (0 < iVar7) {
        (D3Obj->pos).vx = (short)local_34;
        (D3Obj->pos).vy = (short)local_30;
        (D3Obj->pos).vz = (short)local_2c;
      }
    }
    else {
LAB_80051ba4:
      if ((Retour == 0) || (!bVar2)) goto LAB_80051bbc;
    }
    (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Platform_Once(struct _D3_OBJECT *D3Obj /*$s0*/, long X /*$s7*/, long Y /*$fp*/, long Z /*stack 12*/, long special /*stack 16*/)
 // line 1642, offset 0x80051ca8
	/* begin block 1 */
		// Start line: 1643
		// Start offset: 0x80051CA8
		// Variables:
	// 		struct CDOOR_7fake spd; // stack offset -72
	// 		long snd_handle; // $s2
	// 		long Speed; // stack offset -64
	// 		long Position; // $s4
	// 		long EndPosition; // $s5
	// 		long CurrentPos; // $s1
	// 		long Position2; // $s6
	// 		long EndPosition2; // stack offset -60
	// 		long difference; // stack offset -56
	// 		long exvalue; // $s2
	// 		long timer; // stack offset -52
	// 		long firstchildz; // stack offset -48
	/* end block 1 */
	// End offset: 0x80052680
	// End Line: 1876

	/* begin block 2 */
		// Start line: 3623
	/* end block 2 */
	// End Line: 3624

void Platform_Once(_D3_OBJECT *D3Obj,long X,long Y,long Z,long special)

{
  char cVar1;
  ushort uVar2;
  long lVar3;
  short snd_handle;
  short sVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  uint unaff_s1;
  int unaff_s4;
  int unaff_s6;
  int iVar12;
  int local_3c;
  int local_34;
  int local_30;
  
  iVar5 = (int)D3Obj[1].pos.vz;
  local_34 = 0x1e;
  iVar6 = iVar5 * 0x10;
  if (D3Obj->child != (_D3_OBJECT *)0x0) {
    D3_MoveList(D3Obj->child,0xb8);
    local_30 = (int)(D3Obj->child->pos).vz - (int)(D3Obj->pos).vz;
  }
  if (X != 0) {
    unaff_s4 = (int)(D3Obj->pos).vx << 0xc;
    unaff_s6 = unaff_s4;
  }
  if (Y != 0) {
    unaff_s4 = (int)(D3Obj->pos).vy << 0xc;
    unaff_s6 = unaff_s4;
  }
  if (Z != 0) {
    unaff_s4 = (int)(D3Obj->pos).vz << 0xc;
    unaff_s6 = unaff_s4;
  }
  if (iVar6 < 1) {
    iVar7 = (int)D3Obj[1].pos.pad * -0x640;
  }
  else {
    iVar7 = (int)D3Obj[1].pos.pad * 0x640;
  }
  iVar7 = unaff_s4 + iVar7;
  iVar12 = unaff_s6;
  local_3c = iVar7;
  if (iVar6 < 0) {
    iVar12 = iVar7;
    local_3c = unaff_s6;
  }
  D3_SetCollBits(D3Obj,8);
  uVar11 = *(undefined4 *)&(D3Obj->pos).vz;
  *(undefined4 *)&D3Obj->last_pos = *(undefined4 *)&D3Obj->pos;
  *(undefined4 *)&(D3Obj->last_pos).vz = uVar11;
  Task_Next();
  iVar10 = unaff_s4 - iVar12;
  *(undefined *)((int)&D3Obj[1].pos.vx + 1) = 0xff;
  if ((((Pvl_LevelNumber != 2) && (Pvl_SectorNumber != 6)) && (Pvl_LevelNumber != 6)) &&
     ((Pvl_SectorNumber != 3 &&
      ((Scts_Interruptors & *(uint *)&D3Obj[1].last_pos) == *(uint *)&D3Obj[1].last_pos)))) {
    snd_handle = (short)(iVar7 >> 0xc);
    if (X != 0) {
      (D3Obj->pos).vx = snd_handle;
    }
    if (Y != 0) {
      (D3Obj->pos).vy = snd_handle;
    }
    if (Z != 0) {
      (D3Obj->pos).vz = snd_handle;
    }
    uVar11 = *(undefined4 *)&(D3Obj->pos).vz;
    *(undefined4 *)&D3Obj->last_pos = *(undefined4 *)&D3Obj->pos;
    *(undefined4 *)&(D3Obj->last_pos).vz = uVar11;
  }
LAB_80051ef4:
  do {
    if (*(int *)&D3Obj[1].last_pos != 0) goto LAB_80051f60;
    uVar2 = D3Obj->collision_state;
    if ((uVar2 & 0x10) != 0) {
      local_34 = 0x1e;
    }
    iVar9 = local_34 + -1;
    if (local_34 < 1) {
      while (iVar9 = local_34, (uVar2 & 0x10) == 0) {
        Task_Next();
        uVar2 = D3Obj->collision_state;
      }
    }
    while( true ) {
      local_34 = iVar9;
      lVar3 = Scts_Interruptors;
      cVar1 = *(char *)((int)&D3Obj[1].pos.vx + 1);
      if (cVar1 != -1) {
        while ((cVar1 != '\x03' &&
               ((uVar8 = *(uint *)&D3Obj[1].last_pos, (lVar3 & uVar8) == uVar8 ||
                ((Scts_Interruptors & uVar8) != uVar8))))) {
          Task_Next();
          cVar1 = *(char *)((int)&D3Obj[1].pos.vx + 1);
        }
      }
      if ((Pvl_LevelNumber == 2) && (Pvl_SectorNumber == 6)) {
        *(undefined *)((int)&D3Obj[1].pos.vx + 1) = 2;
      }
      D3Obj->collision_state = D3Obj->collision_state & 0xffef;
      if (X != 0) {
        unaff_s1 = (int)(D3Obj->pos).vx << 0xc;
      }
      if (Y != 0) {
        unaff_s1 = (int)(D3Obj->pos).vy << 0xc;
      }
      if (Z != 0) {
        unaff_s1 = (int)(D3Obj->pos).vz << 0xc;
      }
      snd_handle = D3_PlaySound(D3Obj,0);
      do {
        snd_handle = D3_UpdateSound(D3Obj,0,snd_handle);
        sVar4 = (short)((int)(unaff_s1 + iVar6) >> 0xc);
        if (X != 0) {
          (D3Obj->pos).vx = sVar4;
        }
        if (Y != 0) {
          (D3Obj->pos).vy = sVar4;
        }
        if (Z != 0) {
          (D3Obj->pos).vz = sVar4;
        }
        if (D3Obj->child != (_D3_OBJECT *)0x0) {
          D3_MoveList(D3Obj->child,0xb8);
        }
        Task_Next();
        if ((D3Obj->child != (_D3_OBJECT *)0x0) &&
           ((int)(D3Obj->pos).vz + local_30 != (int)(D3Obj->child->pos).vz)) {
          D3_MoveList(D3Obj->child,0xb8);
        }
        unaff_s1 = unaff_s1 + iVar6 & 0xffff;
        if (X != 0) {
          unaff_s1 = unaff_s1 | (int)(D3Obj->pos).vx << 0xc;
        }
        if (Y != 0) {
          unaff_s1 = unaff_s1 | (int)(D3Obj->pos).vy << 0xc;
        }
        if (Z != 0) {
          unaff_s1 = unaff_s1 | (int)(D3Obj->pos).vz << 0xc;
        }
      } while (((int)unaff_s1 < local_3c) && (iVar12 < (int)unaff_s1));
      D3_StopSound(D3Obj,snd_handle);
      snd_handle = (short)(iVar7 >> 0xc);
      if (X != 0) {
        (D3Obj->pos).vx = snd_handle;
      }
      if (Y != 0) {
        (D3Obj->pos).vy = snd_handle;
      }
      if (Z != 0) {
        (D3Obj->pos).vz = snd_handle;
      }
      if (special != 0) {
        unaff_s4 = unaff_s4 + iVar10;
        iVar12 = iVar12 - iVar10;
        local_3c = local_3c + iVar10;
        Scts_Interruptors = Scts_Interruptors & ~*(uint *)&D3Obj[1].last_pos;
        iVar7 = iVar7 - iVar10;
        goto LAB_80051ef4;
      }
      if (*(char *)((int)&D3Obj[1].pos.vx + 1) != -1) {
        *(undefined *)((int)&D3Obj[1].pos.vx + 1) = 2;
      }
      iVar9 = (int)*(short *)((int)&D3Obj[1].handle + 2);
      if (iVar9 != -1) {
        Pvl_EnemyZones[iVar9].flags = Pvl_EnemyZones[iVar9].flags & 0xfe;
      }
      if (*(int *)&D3Obj[1].last_pos == 0) {
        while ((D3Obj->collision_state & 0x10U) != 0) {
          D3Obj->collision_state = D3Obj->collision_state & 0xffef;
          Task_Next();
        }
        do {
          Task_Next();
        } while ((D3Obj->collision_state & 0x10U) == 0);
      }
      else {
        cVar1 = *(char *)((int)&D3Obj[1].pos.vx + 1);
        while ((cVar1 == -1 &&
               ((Scts_Interruptors & *(uint *)&D3Obj[1].last_pos) == *(uint *)&D3Obj[1].last_pos)))
        {
          Task_Next();
          cVar1 = *(char *)((int)&D3Obj[1].pos.vx + 1);
        }
      }
      lVar3 = Scts_Interruptors;
      cVar1 = *(char *)((int)&D3Obj[1].pos.vx + 1);
      if (cVar1 != -1) {
        while ((cVar1 != '\x03' &&
               ((uVar8 = lVar3 & *(uint *)&D3Obj[1].last_pos, uVar8 != *(uint *)&D3Obj[1].last_pos
                || ((Scts_Interruptors & uVar8) == uVar8))))) {
          Task_Next();
          cVar1 = *(char *)((int)&D3Obj[1].pos.vx + 1);
        }
      }
      if (X != 0) {
        unaff_s1 = (int)(D3Obj->pos).vx << 0xc;
      }
      if (Y != 0) {
        unaff_s1 = (int)(D3Obj->pos).vy << 0xc;
      }
      if (Z != 0) {
        unaff_s1 = (int)(D3Obj->pos).vz << 0xc;
      }
      snd_handle = D3_PlaySound(D3Obj,0);
      do {
        snd_handle = D3_UpdateSound(D3Obj,0,snd_handle);
        uVar8 = unaff_s1 + iVar5 * -0x10;
        sVar4 = (short)((int)uVar8 >> 0xc);
        if (X != 0) {
          (D3Obj->pos).vx = sVar4;
        }
        if (Y != 0) {
          (D3Obj->pos).vy = sVar4;
        }
        if (Z != 0) {
          (D3Obj->pos).vz = sVar4;
        }
        if (D3Obj->child != (_D3_OBJECT *)0x0) {
          D3_MoveList(D3Obj->child,0xb8);
        }
        Task_Next();
        if ((D3Obj->child != (_D3_OBJECT *)0x0) &&
           ((int)(D3Obj->pos).vz + local_30 != (int)(D3Obj->child->pos).vz)) {
          D3_MoveList(D3Obj->child,0xb8);
        }
        unaff_s1 = uVar8 & 0xffff;
        if (X != 0) {
          unaff_s1 = unaff_s1 | (int)(D3Obj->pos).vx << 0xc;
        }
        if (Y != 0) {
          unaff_s1 = unaff_s1 | (int)(D3Obj->pos).vy << 0xc;
        }
        if (Z != 0) {
          unaff_s1 = unaff_s1 | (int)(D3Obj->pos).vz << 0xc;
        }
      } while ((((int)unaff_s1 < local_3c) && (iVar12 < (int)unaff_s1)) ||
              (((int)D3Obj->collision_state & 0x8000U) != 0));
      D3_StopSound(D3Obj,snd_handle);
      snd_handle = (short)(unaff_s4 >> 0xc);
      if (X != 0) {
        (D3Obj->pos).vx = snd_handle;
      }
      if (Y != 0) {
        (D3Obj->pos).vy = snd_handle;
      }
      if (Z != 0) {
        (D3Obj->pos).vz = snd_handle;
      }
      iVar9 = (int)*(short *)((int)&D3Obj[1].handle + 2);
      if (iVar9 != -1) {
        Pvl_EnemyZones[iVar9].flags = Pvl_EnemyZones[iVar9].flags | 1;
      }
      if (*(char *)((int)&D3Obj[1].pos.vx + 1) != -1) {
        *(undefined *)((int)&D3Obj[1].pos.vx + 1) = 1;
      }
      if (*(int *)&D3Obj[1].last_pos == 0) break;
LAB_80051f60:
      cVar1 = *(char *)((int)&D3Obj[1].pos.vx + 1);
      while ((iVar9 = local_34, cVar1 == -1 &&
             (iVar9 = local_34,
             (Scts_Interruptors & *(uint *)&D3Obj[1].last_pos) != *(uint *)&D3Obj[1].last_pos))) {
        Task_Next();
        cVar1 = *(char *)((int)&D3Obj[1].pos.vx + 1);
      }
    }
    uVar2 = D3Obj->collision_state;
    while ((uVar2 & 0x10) != 0) {
      D3Obj->collision_state = uVar2 & 0xffef;
      Task_Next();
      uVar2 = D3Obj->collision_state;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Platform_Normal(struct _D3_OBJECT *D3Obj /*$s1*/, long X /*$s4*/, long Y /*$s5*/, long Z /*$s6*/, long normal /*stack 16*/)
 // line 1878, offset 0x80052680
	/* begin block 1 */
		// Start line: 1879
		// Start offset: 0x80052680
		// Variables:
	// 		struct CDOOR_7fake spd; // stack offset -64
	// 		long snd_handle; // $s2
	// 		long Speed; // $fp
	// 		long Position; // $s3
	// 		long EndPosition; // stack offset -56
	// 		long CurrentPos; // $s0
	// 		long flipflop; // stack offset -52
	/* end block 1 */
	// End offset: 0x80052AD8
	// End Line: 1979

	/* begin block 2 */
		// Start line: 4109
	/* end block 2 */
	// End Line: 4110

void Platform_Normal(_D3_OBJECT *D3Obj,long X,long Y,long Z,long normal)

{
  bool bVar1;
  short snd_handle;
  short sVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint unaff_s0;
  uint uVar6;
  uint unaff_s3;
  short local_30;
  
  if (X != 0) {
    unaff_s3 = (int)(D3Obj->pos).vx << 0x10;
  }
  if (Y != 0) {
    unaff_s3 = (int)(D3Obj->pos).vy << 0x10;
  }
  if (Z != 0) {
    unaff_s3 = (int)(D3Obj->pos).vz << 0x10;
  }
  iVar4 = (int)D3Obj[1].pos.vz;
  if (iVar4 < 0) {
    unaff_s3 = unaff_s3 + (int)D3Obj[1].pos.pad * -0x6400;
  }
  bVar1 = true;
  iVar3 = (int)D3Obj[1].pos.pad;
  if (iVar3 < 0) {
    iVar3 = -iVar3;
  }
  iVar3 = unaff_s3 + iVar3 * 0x6400;
  if (iVar4 < 0) {
    iVar4 = -iVar4;
  }
  D3_SetCollBits(D3Obj,8);
  uVar5 = *(undefined4 *)&(D3Obj->pos).vz;
  *(undefined4 *)&D3Obj->last_pos = *(undefined4 *)&D3Obj->pos;
  *(undefined4 *)&(D3Obj->last_pos).vz = uVar5;
  do {
    if ((normal != 0) || (bVar1)) {
      while ((D3Obj->collision_state & 0x10U) == 0) {
        Task_Next();
      }
      D3Obj->collision_state = D3Obj->collision_state & 0xffef;
    }
    if (X != 0) {
      unaff_s0 = (int)(D3Obj->pos).vx << 0x10;
    }
    if (Y != 0) {
      unaff_s0 = (int)(D3Obj->pos).vy << 0x10;
    }
    if (Z != 0) {
      unaff_s0 = (int)(D3Obj->pos).vz << 0x10;
    }
    if (unaff_s0 == unaff_s3) {
      snd_handle = D3_PlaySound(D3Obj,0);
      while ((int)unaff_s0 < iVar3) {
        uVar6 = unaff_s0 + iVar4 * 0x100;
        sVar2 = (short)(uVar6 >> 0x10);
        if (X != 0) {
          (D3Obj->pos).vx = sVar2;
        }
        if (Y != 0) {
          (D3Obj->pos).vy = sVar2;
        }
        if (Z != 0) {
          (D3Obj->pos).vz = sVar2;
        }
        if (D3Obj->child != (_D3_OBJECT *)0x0) {
          D3_MoveList(D3Obj->child,0xc0);
        }
        unaff_s0 = uVar6 & 0xffff;
        Task_Next();
        if (X != 0) {
          unaff_s0 = unaff_s0 | (int)(D3Obj->pos).vx << 0x10;
        }
        if (Y != 0) {
          unaff_s0 = unaff_s0 | (int)(D3Obj->pos).vy << 0x10;
        }
        if (Z != 0) {
          unaff_s0 = unaff_s0 | (int)(D3Obj->pos).vz << 0x10;
        }
      }
      D3_StopSound(D3Obj,snd_handle);
      snd_handle = (short)((uint)iVar3 >> 0x10);
      if (X != 0) {
        (D3Obj->pos).vx = snd_handle;
      }
      if (Y != 0) {
        (D3Obj->pos).vy = snd_handle;
      }
      if (Z != 0) {
        (D3Obj->pos).vz = snd_handle;
      }
    }
    else {
      snd_handle = D3_PlaySound(D3Obj,0);
      while ((int)unaff_s3 < (int)unaff_s0) {
        uVar6 = unaff_s0 + iVar4 * -0x100;
        sVar2 = (short)(uVar6 >> 0x10);
        if (X != 0) {
          (D3Obj->pos).vx = sVar2;
        }
        if (Y != 0) {
          (D3Obj->pos).vy = sVar2;
        }
        if (Z != 0) {
          (D3Obj->pos).vz = sVar2;
        }
        if (D3Obj->child != (_D3_OBJECT *)0x0) {
          D3_MoveList(D3Obj->child,0xc0);
        }
        unaff_s0 = uVar6 & 0xffff;
        Task_Next();
        if (X != 0) {
          unaff_s0 = unaff_s0 | (int)(D3Obj->pos).vx << 0x10;
        }
        if (Y != 0) {
          unaff_s0 = unaff_s0 | (int)(D3Obj->pos).vy << 0x10;
        }
        if (Z != 0) {
          unaff_s0 = unaff_s0 | (int)(D3Obj->pos).vz << 0x10;
        }
      }
      D3_StopSound(D3Obj,snd_handle);
      local_30 = (short)(unaff_s3 >> 0x10);
      if (X != 0) {
        (D3Obj->pos).vx = local_30;
      }
      if (Y != 0) {
        (D3Obj->pos).vy = local_30;
      }
      if (Z != 0) {
        (D3Obj->pos).vz = local_30;
      }
    }
    while ((D3Obj->collision_state & 0x10U) != 0) {
      D3Obj->collision_state = D3Obj->collision_state & 0xffef;
      Task_Next();
    }
    bVar1 = (bool)(bVar1 ^ 1);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Platform_DestEffect(struct TASK *t /*$a0*/)
 // line 1982, offset 0x80052ad8
	/* begin block 1 */
		// Start line: 1984
		// Start offset: 0x80052AD8
		// Variables:
	// 		struct _D3_OBJECT *wheel; // $v0
	/* end block 1 */
	// End offset: 0x80052AD8
	// End Line: 1984

	/* begin block 2 */
		// Start line: 4339
	/* end block 2 */
	// End Line: 4340

void Platform_DestEffect(TASK *t)

{
  int iVar1;
  
  iVar1 = *(int *)((int)t->local + 0x24);
  *(ushort *)(iVar1 + 0x28) = *(ushort *)(iVar1 + 0x28) & 0xfffe;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Platform_TreatEffects()
 // line 1990, offset 0x80052afc
	/* begin block 1 */
		// Start line: 1991
		// Start offset: 0x80052AFC
		// Variables:
	// 		struct _D3_OBJECT *wheel; // $a0
	/* end block 1 */
	// End offset: 0x80052B44
	// End Line: 1999

	/* begin block 2 */
		// Start line: 4354
	/* end block 2 */
	// End Line: 4355

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Platform_TreatEffects(void)

{
  void **ppvVar1;
  int iVar2;
  
  ppvVar1 = &TaskCurrent->local;
  TaskCurrent->destructor = Platform_DestEffect;
  iVar2 = *(int *)((int)*ppvVar1 + 0x24);
  *(ushort *)(iVar2 + 0x28) = *(ushort *)(iVar2 + 0x28) | 1;
  do {
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Platform_Z_Exit(struct _D3_OBJECT *D3Obj /*$s1*/, long reinit /*$s4*/)
 // line 2002, offset 0x80052b44
	/* begin block 1 */
		// Start line: 2003
		// Start offset: 0x80052B44
		// Variables:
	// 		struct M_OBJECT *mo; // $s2
	// 		struct _D3_OBJECT *tmp; // $v1
	// 		struct _D3_OBJECT *wheel; // $s3
	// 		struct TASK *t; // $s0
	/* end block 1 */
	// End offset: 0x80052F1C
	// End Line: 2126

	/* begin block 2 */
		// Start line: 4381
	/* end block 2 */
	// End Line: 4382

void Platform_Z_Exit(_D3_OBJECT *D3Obj,long reinit)

{
  ushort uVar1;
  _ZONE *Param;
  _D3_OBJECT *p_Var2;
  undefined4 uVar3;
  TASK *t;
  TASK *t_00;
  M_OBJECT *obj;
  _D3_OBJECT *p_Var4;
  
  obj = (M_OBJECT *)D3Obj->description;
  t = (TASK *)0x0;
  p_Var4 = (_D3_OBJECT *)0x0;
  if (D3Obj->father != (_D3_OBJECT *)0x0) {
    p_Var2 = D3Obj->father->child;
    while (p_Var4 = (_D3_OBJECT *)0x0, p_Var2 != (_D3_OBJECT *)0x0) {
      if ((*(char *)((int)&p_Var2[1].pos.vx + 1) == '\0') && ((p_Var2->display_mode & 0x40U) != 0))
      {
        *(undefined *)((int)&p_Var2[1].pos.vx + 1) = 1;
        p_Var4 = p_Var2;
        break;
      }
      p_Var2 = p_Var2->next;
    }
  }
  Pvl_SetStateBits(D3Obj,4);
  Task_Next();
  if ((Scts_Interruptors & *(uint *)&D3Obj[1].last_pos) == *(uint *)&D3Obj[1].last_pos) {
    if ((D3Obj->display_mode & 0x40U) != 0) {
      Manim_GoToFrame(obj,(uint)*(ushort *)
                                 (*(int *)(*(int *)((obj->Sq).Data.FatherTrans + 2) + 8) + 6) - 1);
      (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
      uVar3 = *(undefined4 *)&(D3Obj->pos).vz;
      *(undefined4 *)&D3Obj->last_pos = *(undefined4 *)&D3Obj->pos;
      *(undefined4 *)&(D3Obj->last_pos).vz = uVar3;
    }
    t_00 = t;
    if (p_Var4 != (_D3_OBJECT *)0x0) {
      t_00 = Task_Add(Platform_TreatEffects,0x100);
      *(_D3_OBJECT **)&t_00->local = p_Var4;
    }
    Platform_Z_Movement(D3Obj,(int)D3Obj[1].pos.pad * 100,-(int)D3Obj[1].pos.vz);
    if (t_00 != (TASK *)0x0) {
      Task_Kill(t_00);
      t_00 = (TASK *)0x0;
    }
  }
  else {
    t_00 = t;
    if ((D3Obj->display_mode & 0x40U) != 0) {
      D3_ClearCollBits(D3Obj,1);
      Platform_Z_Set(D3Obj,(int)D3Obj[1].pos.pad * 100,-(int)D3Obj[1].pos.vz);
      while ((Scts_Interruptors & *(uint *)&D3Obj[1].last_pos) != *(uint *)&D3Obj[1].last_pos) {
        Task_Next();
      }
      if (p_Var4 != (_D3_OBJECT *)0x0) {
        t = Task_Add(Platform_TreatEffects,0x100);
        *(_D3_OBJECT **)&t->local = p_Var4;
      }
      D3_SetCollBits(D3Obj,9);
      (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx | 1;
      Manim_WaitAnim(obj);
      (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
      t_00 = t;
      if (t != (TASK *)0x0) {
        t_00 = (TASK *)0x0;
        *(ushort *)((int)p_Var4->description + 0x28) =
             *(ushort *)((int)p_Var4->description + 0x28) & 0xfffe;
        Task_Kill(t);
      }
    }
  }
  uVar1 = D3Obj->collision_state;
  while ((uVar1 & 0x10) != 0) {
    D3Obj->collision_state = uVar1 & 0xffef;
    Task_Next();
    uVar1 = D3Obj->collision_state;
  }
  while( true ) {
    while ((D3Obj->collision_state & 0x10U) == 0) {
      Task_Next();
    }
    if (p_Var4 != (_D3_OBJECT *)0x0) {
      t_00 = Task_Add(Platform_TreatEffects,0x100);
      *(_D3_OBJECT **)&t_00->local = p_Var4;
    }
    Platform_Z_Movement(D3Obj,(int)D3Obj[1].pos.pad * 100,(int)D3Obj[1].pos.vz);
    if (t_00 != (TASK *)0x0) {
      Task_Kill(t_00);
      t_00 = (TASK *)0x0;
    }
    D3Obj->collision_state = D3Obj->collision_state & 0xffef;
    Task_Next();
    if ((D3Obj->collision_state & 0x10U) != 0) break;
    if (p_Var4 != (_D3_OBJECT *)0x0) {
      t_00 = Task_Add(Platform_TreatEffects,0x100);
      *(_D3_OBJECT **)&t_00->local = p_Var4;
    }
    Platform_Z_Movement(D3Obj,(int)D3Obj[1].pos.pad * 100,-(int)D3Obj[1].pos.vz);
    if (t_00 != (TASK *)0x0) {
      Task_Kill(t_00);
      t_00 = (TASK *)0x0;
    }
    if (reinit == 0) {
      Pvl_SctState[(int)D3Obj->index] = Pvl_SctState[(int)D3Obj->index] & 0xfe;
    }
  }
  Param = Zone_GetObjectZone(D3Obj);
  Pl_ForceAction((_PLAYER *)&Player,1,(long)Param);
  do {
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Platform_Z_Set(struct _D3_OBJECT *D3Obj /*$a0*/, long Distance /*$a1*/, long speed /*$a2*/)
 // line 2130, offset 0x80052f1c
	/* begin block 1 */
		// Start line: 2132
		// Start offset: 0x80052F1C
		// Variables:
	// 		struct _D3_OBJECT *obj; // $v1
	// 		long Z; // $v0
	// 		long sZ; // $-1
	// 		long multiplier; // $v1
	/* end block 1 */
	// End offset: 0x80052F6C
	// End Line: 2153

	/* begin block 2 */
		// Start line: 4693
	/* end block 2 */
	// End Line: 4694

void Platform_Z_Set(_D3_OBJECT *D3Obj,long Distance,long speed)

{
  short sVar1;
  int iVar2;
  _D3_OBJECT *p_Var3;
  
  iVar2 = 1;
  if (speed < 0) {
    iVar2 = -1;
  }
  p_Var3 = D3Obj->child;
  sVar1 = (short)((int)(D3Obj->pos).vz * 0x1000 + Distance * 0x10 * iVar2 >> 0xc);
  (D3Obj->pos).vz = sVar1;
  (D3Obj->last_pos).vz = sVar1;
  while (p_Var3 != (_D3_OBJECT *)0x0) {
    (p_Var3->pos).vz = sVar1;
    (p_Var3->last_pos).vz = sVar1;
    p_Var3 = p_Var3->next;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Platform_Z_Movement(struct _D3_OBJECT *D3Obj /*$s0*/, long Distance /*$s3*/, long speed /*$s4*/)
 // line 2155, offset 0x80052f74
	/* begin block 1 */
		// Start line: 2156
		// Start offset: 0x80052F74
		// Variables:
	// 		struct CDOOR_7fake spd; // stack offset -48
	// 		long Z; // $s1
	// 		long sZ; // $s2
	// 		long EndDistance; // $s7
	// 		long tmp; // $v1
	// 		long Fx_Handle; // $s5
	// 		long position; // $s6
	/* end block 1 */
	// End offset: 0x800530EC
	// End Line: 2220

	/* begin block 2 */
		// Start line: 4743
	/* end block 2 */
	// End Line: 4744

void Platform_Z_Movement(_D3_OBJECT *D3Obj,long Distance,long speed)

{
  short sVar1;
  short snd_handle;
  int iVar2;
  int iVar3;
  int iVar4;
  _D3_OBJECT *p_Var5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  snd_handle = -1;
  sVar1 = (D3Obj->last_pos).vz;
  D3_SetCollBits(D3Obj,8);
  iVar8 = speed << 4;
  uVar6 = *(undefined4 *)&(D3Obj->pos).vz;
  *(undefined4 *)&D3Obj->last_pos = *(undefined4 *)&D3Obj->pos;
  *(undefined4 *)&(D3Obj->last_pos).vz = uVar6;
  iVar9 = Distance >> 4;
  iVar7 = (int)(D3Obj->pos).vz << 0xc;
  iVar3 = (int)sVar1 + 100;
  if (0 < Distance) {
    do {
      iVar2 = (int)(D3Obj->last_pos).vz;
      if (iVar3 == iVar2) {
        D3_StopSound(D3Obj,snd_handle);
        if (iVar7 >> 0xc == (int)(D3Obj->pos).vz) {
          iVar7 = iVar7 + iVar8;
        }
      }
      else {
        snd_handle = D3_UpdateSound(D3Obj,0,snd_handle);
        iVar3 = speed;
        if (speed < 0) {
          iVar3 = -speed;
        }
        Distance = Distance - iVar3;
        iVar7 = iVar7 + iVar8;
        if (Distance < iVar9) {
          iVar3 = iVar8;
          if (iVar8 < 0) {
            iVar3 = -iVar8;
          }
          iVar4 = 0;
          if (0x1000 < iVar3) {
            iVar8 = iVar8 - (iVar8 >> 3);
            iVar4 = speed >> 3;
          }
          speed = speed - iVar4;
        }
      }
      p_Var5 = D3Obj->child;
      (D3Obj->pos).vz = (short)(iVar7 >> 0xc);
      if (p_Var5 != (_D3_OBJECT *)0x0) {
        D3_MoveList(D3Obj->child,0xd0);
      }
      Task_Next();
      iVar3 = iVar2;
    } while (0 < Distance);
  }
  D3_ClearCollBits(D3Obj,8);
  D3_StopSound(D3Obj,snd_handle);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_TrapsTask()
 // line 2266, offset 0x80053130
	/* begin block 1 */
		// Start line: 2267
		// Start offset: 0x80053130
		// Variables:
	// 		struct _D3_OBJECT *D3Obj; // $s0
	// 		long comp; // $v1
	/* end block 1 */
	// End offset: 0x80053338
	// End Line: 2304

	/* begin block 2 */
		// Start line: 4979
	/* end block 2 */
	// End Line: 4980

/* WARNING: Unknown calling convention yet parameter storage is locked */

void CB_TrapsTask(void)

{
  long XX;
  long YY;
  _D3_OBJECT *o;
  
  o = (_D3_OBJECT *)TaskCurrent->local;
  switch((uint)(ushort)o[1].pos.vy & 0x1f) {
  case 0:
    Traps_DropAway(o);
    break;
  case 1:
    XX = 1;
    YY = 0;
    goto LAB_800531ac;
  case 2:
    XX = 0;
    YY = 1;
LAB_800531ac:
    Traps_BloodyPinns(o,XX,YY,0);
    break;
  case 3:
    Traps_BloodyPinns(o,0,0,1);
    break;
  case 4:
    XX = 1;
    YY = 0;
    goto LAB_800531f4;
  case 5:
    XX = 0;
    YY = 1;
LAB_800531f4:
    Traps_Bullet(o,XX,YY,0);
    break;
  case 6:
    Traps_Bullet(o,0,0,1);
    break;
  case 7:
    Traps_Balance(o,0);
    break;
  case 8:
    Traps_Balance(o,1);
    break;
  case 9:
    Traps_Piston(o,0);
    break;
  case 10:
    Traps_Piston(o,1);
    break;
  case 0xb:
    Traps_FireWall(o);
    break;
  case 0xc:
    Traps_Ventilo(o);
    break;
  case 0xd:
    Traps_LethalPick(o);
    break;
  case 0xe:
    Traps_EngrenageRemove(o);
    break;
  case 0xf:
    Traps_EngrenageAdd(o);
    break;
  case 0x10:
    Traps_Trappe(o);
    break;
  case 0x11:
    Traps_Pipette(o);
    break;
  case 0x12:
    Traps_LameCirc(o);
    break;
  case 0x13:
    Traps_VoletEau(o);
    break;
  case 0x14:
    Traps_HiddenGrenade(o);
    break;
  case 0x15:
    Traps_VitreFragile(o);
    break;
  case 0x16:
    Traps_ExploseWhenSwitched(o);
    break;
  case 0x17:
    Traps_BroSurvive(o);
  }
  Zone_DeleteObject(o);
  o->handle = (TASK *)0x0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Traps_OptimiseCollisions()
 // line 2309, offset 0x80053354
	/* begin block 1 */
		// Start line: 2310
		// Start offset: 0x80053354
		// Variables:
	// 		struct _D3_OBJECT *D3Obj; // $a0
	/* end block 1 */
	// End offset: 0x80053398
	// End Line: 2317

	/* begin block 2 */
		// Start line: 5066
	/* end block 2 */
	// End Line: 5067

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Traps_OptimiseCollisions(void)

{
  _D3_OBJECT *o;
  
  o = (_D3_OBJECT *)TaskCurrent->local;
  if ((o->collision_state & 0x80U) == 0) {
    D3_ClearCollBits(o,9);
  }
  else {
    D3_SetCollBits(o,9);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Traps_ExploseWhenSwitched(struct _D3_OBJECT *o /*$s1*/)
 // line 2319, offset 0x800533a8
	/* begin block 1 */
		// Start line: 2320
		// Start offset: 0x800533A8
		// Variables:
	// 		long i; // $s0
	/* end block 1 */
	// End offset: 0x8005341C
	// End Line: 2331

	/* begin block 2 */
		// Start line: 5086
	/* end block 2 */
	// End Line: 5087

void Traps_ExploseWhenSwitched(_D3_OBJECT *o)

{
  long lVar1;
  int iVar2;
  
  D3_SetCollBits(o,9);
  do {
    lVar1 = Pvl_TestStateBits(o->father,2);
    if (lVar1 != 0) {
      lVar1 = Pvl_TestStateBits(o->father,1);
      iVar2 = 0;
      if (lVar1 != 0) {
        do {
          iVar2 = iVar2 + 1;
          Task_Next();
        } while (iVar2 < 0x3c);
        D3_ClearCollBits(o,(long)&DAT_00004011);
        o->display_mode = o->display_mode & 0xffef;
        SFX_AddExplosion(o,0,0);
        return;
      }
    }
    (o->pos).vz = (o->pos).vz + -0x19;
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Traps_FireWall(struct _D3_OBJECT *D3Obj /*$s2*/)
 // line 2337, offset 0x80053454
	/* begin block 1 */
		// Start line: 2338
		// Start offset: 0x80053454
		// Variables:
	// 		struct CDOOR_7fake pos[4]; // stack offset -64
	// 		struct _D3_OBJECT *child; // $s5
	// 		long Cos; // $s0
	// 		long Sin; // $v0
	// 		long x; // $s1
	// 		long i; // $s0
	/* end block 1 */
	// End offset: 0x8005392C
	// End Line: 2405

	/* begin block 2 */
		// Start line: 5127
	/* end block 2 */
	// End Line: 5128

void Traps_FireWall(_D3_OBJECT *D3Obj)

{
  char cVar1;
  char cVar2;
  long lVar3;
  int iVar4;
  _D3_OBJECT *p_Var5;
  
  p_Var5 = D3Obj->child;
  rcos((int)(D3Obj->rot).vz);
  rsin((int)(D3Obj->rot).vz);
  while( true ) {
    Impact_Smoke(0xd8,0);
    iVar4 = 0;
    do {
      iVar4 = iVar4 + 1;
      Task_Next();
    } while (iVar4 < 0xf);
    Impact_Smoke(0xd8,0);
    iVar4 = 0;
    do {
      iVar4 = iVar4 + 1;
      Task_Next();
    } while (iVar4 < 8);
    lVar3 = M_rand();
    cVar2 = (char)lVar3 + (char)(lVar3 / 3) * -3;
    D3_PlaySound(D3Obj,0);
    cVar1 = (char)D3Obj;
    Shoot_Add(D3Obj,cVar2 * '\b' + -0x40,cVar1 + '<',0,6,0x21,5,0);
    if ((p_Var5 != (_D3_OBJECT *)0x0) && (D3Obj->child == (_D3_OBJECT *)0x0)) break;
    iVar4 = 0;
    if (0 < (int)D3Obj[1].pos.pad + 3) {
      do {
        iVar4 = iVar4 + 1;
        Task_Next();
      } while (iVar4 < (int)D3Obj[1].pos.pad + 3);
    }
    Impact_Smoke(cVar2 * '\b' + -0x40,0);
    iVar4 = 0;
    do {
      iVar4 = iVar4 + 1;
      Task_Next();
    } while (iVar4 < 0x1e);
    Impact_Smoke(0xd8,0);
    iVar4 = 0;
    do {
      iVar4 = iVar4 + 1;
      Task_Next();
    } while (iVar4 < 8);
    lVar3 = M_rand();
    cVar2 = (char)lVar3 + (char)(lVar3 / 3) * -3;
    D3_PlaySound(D3Obj,0);
    Shoot_Add(D3Obj,cVar2 * '\b' + -0x40,cVar1 + '<',0,6,0x21,5,0);
    if ((p_Var5 != (_D3_OBJECT *)0x0) && (D3Obj->child == (_D3_OBJECT *)0x0)) break;
    iVar4 = 0;
    if (0 < (int)D3Obj[1].pos.pad + 3) {
      do {
        iVar4 = iVar4 + 1;
        Task_Next();
      } while (iVar4 < (int)D3Obj[1].pos.pad + 3);
    }
    Impact_Smoke(cVar2 * '\b' + -0x40,0);
    iVar4 = 0;
    do {
      iVar4 = iVar4 + 1;
      Task_Next();
    } while (iVar4 < 0x1e);
    Impact_Smoke(0xd8,0);
    iVar4 = 0;
    do {
      iVar4 = iVar4 + 1;
      Task_Next();
    } while (iVar4 < 0xf);
    Impact_Smoke(0xd8,0);
    iVar4 = 0;
    do {
      iVar4 = iVar4 + 1;
      Task_Next();
    } while (iVar4 < 0xf);
    Impact_Smoke(0xd8,0);
    iVar4 = 0;
    do {
      iVar4 = iVar4 + 1;
      Task_Next();
    } while (iVar4 < 8);
    lVar3 = M_rand();
    cVar2 = (char)lVar3 + (char)(lVar3 / 3) * -3;
    D3_PlaySound(D3Obj,0);
    Shoot_Add(D3Obj,cVar2 * '\b' + -0x40,cVar1 + '<',0,6,0x21,5,0);
    if ((p_Var5 != (_D3_OBJECT *)0x0) && (D3Obj->child == (_D3_OBJECT *)0x0)) break;
    iVar4 = 0;
    if (0 < (int)D3Obj[1].pos.pad + 3) {
      do {
        iVar4 = iVar4 + 1;
        Task_Next();
      } while (iVar4 < (int)D3Obj[1].pos.pad + 3);
    }
    Impact_Smoke(cVar2 * '\b' + -0x40,0);
    iVar4 = 0;
    do {
      iVar4 = iVar4 + 1;
      Task_Next();
    } while (iVar4 < 0x1e);
  }
  *(undefined *)((int)&D3Obj[1].pos.vx + 1) = 0;
  do {
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Traps_Piston(struct _D3_OBJECT *D3Obj /*$s2*/, long dust /*stack 4*/)
 // line 2408, offset 0x8005392c
	/* begin block 1 */
		// Start line: 2409
		// Start offset: 0x8005392C
		// Variables:
	// 		long position; // $s5
	// 		long speed; // $s6
	// 		long turnspeed; // $s7
	// 		long startpos; // $s3
	// 		long start; // stack offset -56
	// 		long end; // stack offset -52
	// 		long innerspeed; // $s0
	// 		long distance; // $s0
	// 		long i; // $s1
	// 		long waitperiod; // stack offset -48
	// 		long boxsize1; // $a2
	// 		long boxsize2; // $v1
	// 		struct CDOOR_7fake pos; // stack offset -80
	// 		struct CDOOR_7fake pos1; // stack offset -72
	// 		struct CDOOR_7fake pos2; // stack offset -64
	/* end block 1 */
	// End offset: 0x800543F0
	// End Line: 2591

	/* begin block 2 */
		// Start line: 5320
	/* end block 2 */
	// End Line: 5321

void Traps_Piston(_D3_OBJECT *D3Obj,long dust)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int local_38;
  int local_34;
  
  iVar2 = (int)D3Obj[1].pos.vz;
  if (iVar2 < 0) {
    iVar2 = -iVar2;
  }
  uVar5 = *(uint *)&D3Obj[1].last_pos;
  D3Obj->hit_power = '\n';
  *(uint *)&D3Obj[1].last_pos = uVar5 & 0xffff;
  iVar6 = (int)uVar5 >> 0x10;
  iVar2 = (iVar2 * 0x640) / 0x1e;
  iVar8 = (int)D3Obj[1].pos.pad * 0x640;
  D3_ClearCollBits(D3Obj,(long)&DAT_00002002);
  D3_SetCollBits(D3Obj,9);
  iVar11 = iVar2 >> 9;
  uVar7 = *(undefined4 *)&(D3Obj->pos).vz;
  *(undefined4 *)&D3Obj->last_pos = *(undefined4 *)&D3Obj->pos;
  *(undefined4 *)&(D3Obj->last_pos).vz = uVar7;
  uVar5 = (uint)((int)D3Obj->comp_opt3 - (int)(D3Obj->b_box).vy <
                (int)*(short *)&D3Obj->b_step - (int)(D3Obj->b_box).vx);
  sVar1 = (D3Obj->rot).vz;
  if ((sVar1 == 0x400) || (sVar1 == 0xc00)) {
    uVar5 = uVar5 - 1;
  }
  if (iVar8 < 0) {
    iVar2 = -iVar2;
  }
  if (uVar5 == 0) {
    sVar1 = (D3Obj->pos).vx;
  }
  else {
    sVar1 = (D3Obj->pos).vy;
  }
  iVar10 = (int)sVar1 * 0x1000;
  if (iVar8 < 1) {
    local_38 = iVar10 + iVar8;
    local_34 = iVar10;
  }
  else {
    local_38 = iVar10;
    local_34 = iVar10 + iVar8;
  }
  iVar3 = local_38 >> 0xc;
  iVar3 = local_34 >> 0xc;
  iVar8 = 0xfff;
  TaskCurrent->display = Traps_OptimiseCollisions;
  do {
    if (iVar8 != 0xfff) {
      iVar9 = 0;
      iVar8 = iVar11;
      if (0 < iVar6) {
        do {
          (D3Obj->rot).vy = (D3Obj->rot).vy + (short)iVar8;
          Task_Next();
          iVar4 = iVar8;
          if (iVar8 < 0) {
            iVar4 = -iVar8;
          }
          if (8 < iVar4) {
            iVar8 = iVar8 - (iVar8 >> 4);
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 < iVar6);
      }
      D3_PlaySound(D3Obj,0);
      iVar11 = -iVar11;
    }
    if ((Scts_Interruptors & *(uint *)&D3Obj[1].last_pos) != *(uint *)&D3Obj[1].last_pos) {
      do {
        Task_Next();
      } while ((Scts_Interruptors & *(uint *)&D3Obj[1].last_pos) != *(uint *)&D3Obj[1].last_pos);
    }
    if (iVar2 < 1) {
      D3_SetCollBits(D3Obj,2);
      while( true ) {
        iVar10 = iVar10 + iVar2;
        iVar8 = iVar10 >> 0xc;
        if (((Scts_Interruptors & *(uint *)&D3Obj[1].last_pos) != *(uint *)&D3Obj[1].last_pos) ||
           (iVar8 <= iVar3)) break;
        if (uVar5 == 0) {
          (D3Obj->pos).vx = (short)iVar8;
        }
        else {
          (D3Obj->pos).vy = (short)iVar8;
        }
        (D3Obj->rot).vy = (D3Obj->rot).vy + (short)iVar11;
        Task_Next();
        if (uVar5 == 0) {
          iVar10 = (int)(D3Obj->pos).vx << 0xc;
        }
        else {
          iVar10 = (int)(D3Obj->pos).vy << 0xc;
        }
      }
      D3_PlaySound(D3Obj,2);
      if ((iVar8 <= iVar3) && (dust != 0)) {
        if (uVar5 == 0) {
          (D3Obj->pos).vx = (short)iVar3;
        }
        else {
          (D3Obj->pos).vy = (short)iVar3;
        }
        Task_Next();
        D3_PlaySound(D3Obj,1);
        M_rand();
        if (uVar5 == 0) {
          M_rand();
        }
        else {
          M_rand();
        }
        Impact_Smoke(0xb0,0);
        M_rand();
        if (uVar5 == 0) {
          M_rand();
        }
        else {
          M_rand();
        }
        Impact_Smoke(0xb0,0);
        M_rand();
        if (uVar5 == 0) {
          M_rand();
          iVar10 = local_38;
        }
        else {
          M_rand();
          iVar10 = local_38;
        }
        goto LAB_800543cc;
      }
    }
    else {
      D3_SetCollBits(D3Obj,2);
      while( true ) {
        iVar10 = iVar10 + iVar2;
        iVar8 = iVar10 >> 0xc;
        if (((Scts_Interruptors & *(uint *)&D3Obj[1].last_pos) != *(uint *)&D3Obj[1].last_pos) ||
           (iVar3 <= iVar8)) break;
        if (uVar5 == 0) {
          (D3Obj->pos).vx = (short)iVar8;
        }
        else {
          (D3Obj->pos).vy = (short)iVar8;
        }
        (D3Obj->rot).vy = (D3Obj->rot).vy + (short)iVar11;
        Task_Next();
        if (uVar5 == 0) {
          iVar10 = (int)(D3Obj->pos).vx << 0xc;
        }
        else {
          iVar10 = (int)(D3Obj->pos).vy << 0xc;
        }
      }
      D3_PlaySound(D3Obj,2);
      if ((iVar3 <= iVar8) && (dust != 0)) {
        if (uVar5 == 0) {
          (D3Obj->pos).vx = (short)iVar3;
        }
        else {
          (D3Obj->pos).vy = (short)iVar3;
        }
        Task_Next();
        D3_PlaySound(D3Obj,1);
        M_rand();
        if (uVar5 == 0) {
          M_rand();
        }
        else {
          M_rand();
        }
        Impact_Smoke(0xb0,0);
        M_rand();
        if (uVar5 == 0) {
          M_rand();
        }
        else {
          M_rand();
        }
        Impact_Smoke(0xb0,0);
        M_rand();
        if (uVar5 == 0) {
          M_rand();
          iVar10 = local_34;
        }
        else {
          M_rand();
          iVar10 = local_34;
        }
LAB_800543cc:
        Impact_Smoke(0xb0,0);
      }
    }
    D3_ClearCollBits(D3Obj,2);
    iVar8 = -iVar2;
    iVar2 = iVar8;
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Platform_Trimble(struct _D3_OBJECT *D3Obj /*$s2*/, long speed /*$fp*/, long time /*$s3*/)
 // line 2594, offset 0x800543f0
	/* begin block 1 */
		// Start line: 2595
		// Start offset: 0x800543F0
		// Variables:
	// 		struct CDOOR_5fake m; // stack offset -112
	// 		struct CDOOR_7fake v; // stack offset -80
	// 		struct CDOOR_7fake vorig; // stack offset -72
	// 		struct CDOOR_7fake vrot; // stack offset -64
	// 		struct CDOOR_6fake vout; // stack offset -56
	// 		long rnd; // $v0
	// 		long Dspeed; // $s1
	/* end block 1 */
	// End offset: 0x8005465C
	// End Line: 2636

	/* begin block 2 */
		// Start line: 5770
	/* end block 2 */
	// End Line: 5771

/* WARNING: Could not reconcile some variable overlaps */

void Platform_Trimble(_D3_OBJECT *D3Obj,long speed,long time)

{
  undefined4 in_zero;
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_50;
  uint local_4c;
  short local_48;
  short local_46;
  short local_44;
  short local_40;
  short local_3e;
  undefined2 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  iVar4 = time / speed;
  if (speed == 0) {
    trap(0x1c00);
  }
  uVar1 = 0x80000000;
  if ((speed == -1) && (time == -0x80000000)) {
    trap(0x1800);
  }
  local_48 = (short)((int)*(short *)&D3Obj->b_step + (int)(D3Obj->b_box).vx >> 1);
  local_46 = (short)((int)D3Obj->comp_opt3 + (int)(D3Obj->b_box).vy >> 1);
  local_50 = CONCAT22(-local_46,-local_48);
  local_44 = (short)((int)*(short *)&D3Obj[1].prec + (int)(D3Obj->b_box).vz >> 1);
  local_4c._0_2_ = -local_44;
  local_4c = local_4c & 0xffff0000 | (uint)(ushort)local_4c;
  local_48 = (D3Obj->pos).vx + local_48;
  local_46 = (D3Obj->pos).vy + local_46;
  local_3c = 0;
  local_44 = (D3Obj->pos).vz + local_44;
  while (0 < iVar4) {
    local_3e = 0;
    local_40 = 0;
    uVar2 = M_rand();
    if ((uVar2 & 3) == 2) {
      local_40 = 0x14;
    }
    if ((uVar2 & 3) == 3) {
      local_40 = -0x14;
    }
    uVar2 = M_rand();
    if ((uVar2 & 3) == 2) {
      local_3e = 0x14;
    }
    if ((uVar2 & 3) == 3) {
      local_3e = -0x14;
    }
    RotMatrix(&local_40,(undefined2 *)&local_70);
    (D3Obj->rot).vx = local_40;
    (D3Obj->rot).vy = local_3e;
    setCopControlWord(2,0,local_70);
    setCopControlWord(2,0x800,local_6c);
    setCopControlWord(2,0x1000,local_68);
    setCopControlWord(2,0x1800,local_64);
    setCopControlWord(2,0x2000,local_60);
    setCopReg(2,in_zero,local_50);
    setCopReg(2,uVar1,local_4c);
    copFunction(2,0x486012);
    local_38 = getCopReg(2,0x19);
    local_34 = getCopReg(2,0x1a);
    local_30 = getCopReg(2,0x1b);
    (D3Obj->pos).vx = local_48 + (short)local_38;
    (D3Obj->pos).vy = local_46 + (short)local_34;
    (D3Obj->pos).vz = local_44 + (short)local_30;
    setCopControlWord(2,0x2800,Cam_Matrix.t[0]);
    setCopControlWord(2,0x3000,Cam_Matrix.t[1]);
    setCopControlWord(2,0x3800,Cam_Matrix.t[2]);
    setCopControlWord(2,0,Cam_Matrix.m[0]._0_4_);
    setCopControlWord(2,0x800,Cam_Matrix.m._4_4_);
    setCopControlWord(2,0x1000,Cam_Matrix.m[1]._2_4_);
    setCopControlWord(2,0x1800,Cam_Matrix.m[2]._0_4_);
    setCopControlWord(2,0x2000,Cam_Matrix._16_4_);
    iVar3 = speed + -1;
    while (iVar3 != -1) {
      iVar3 = iVar3 + -1;
      Task_Next();
    }
    iVar4 = iVar4 + -1;
  }
  (D3Obj->rot).vz = 0;
  (D3Obj->rot).vy = 0;
  (D3Obj->rot).vx = 0;
  (D3Obj->pos).vx = local_48 + (short)local_50;
  local_50._2_2_ = (short)((uint)local_50 >> 0x10);
  (D3Obj->pos).vy = local_46 + local_50._2_2_;
  (D3Obj->pos).vz = local_44 + (ushort)local_4c;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Traps_DropAway(struct _D3_OBJECT *D3Obj /*$s2*/)
 // line 2643, offset 0x800546d4
	/* begin block 1 */
		// Start line: 2644
		// Start offset: 0x800546D4
		// Variables:
	// 		struct _PLAYER *pl; // $s1
	// 		long i; // $s0
	// 		long StartZ; // $s3
	// 		long KillObject; // $s5
	// 		long TestZone; // $s4
	/* end block 1 */
	// End offset: 0x800549F4
	// End Line: 2737

	/* begin block 2 */
		// Start line: 5893
	/* end block 2 */
	// End Line: 5894

void Traps_DropAway(_D3_OBJECT *D3Obj)

{
  bool bVar1;
  short sVar2;
  ushort uVar3;
  long lVar4;
  long lVar5;
  int iVar6;
  undefined4 uVar7;
  short sVar8;
  int iVar9;
  long time;
  
  sVar2 = D3Obj[1].last_pos.vx;
  if ((sVar2 != 0) && (iVar9 = 0, sVar2 != 0)) {
    do {
      iVar9 = iVar9 + 1;
      Task_Next();
    } while (iVar9 < (int)(uint)(ushort)D3Obj[1].last_pos.vx);
  }
  if ((Pvl_SctState[(int)D3Obj->index] & 1U) == 0) {
    lVar4 = Zone_IsZoneAttached(D3Obj);
    bVar1 = D3Obj[1].pos.pad != -1;
    if (!bVar1) {
      D3Obj[1].pos.pad = 0;
    }
    sVar2 = (D3Obj->pos).vz;
    do {
      D3_SetCollBits(D3Obj,8);
      iVar9 = 0;
      uVar7 = *(undefined4 *)&(D3Obj->pos).vz;
      *(undefined4 *)&D3Obj->last_pos = *(undefined4 *)&D3Obj->pos;
      *(undefined4 *)&(D3Obj->last_pos).vz = uVar7;
      time = (long)D3Obj[1].last_pos.vy;
      do {
        if (lVar4 == 0) {
          if ((D3Obj->collision_state & 0x110U) == 0x110) {
            iVar6 = D3Obj[1].color;
            if ((((*(ushort *)(iVar6 + 0x1c) & 0x1000) != 0) && (iVar9 = iVar6, iVar6 != 0)) &&
               (iVar9 = iVar6, *(int *)(iVar6 + 0xfc) != 0)) {
              iVar9 = 0;
            }
            D3Obj->collision_state = D3Obj->collision_state & 0xfeff;
          }
        }
        else {
          lVar5 = Task_EventRead(TaskCurrent);
          if (lVar5 == 2) break;
        }
        Task_Next();
      } while (iVar9 == 0);
      if (time == 0) {
        time = 0xf;
      }
      D3_PlaySound(D3Obj,0);
      Platform_Trimble(D3Obj,2,time);
      D3_PlaySound(D3Obj,1);
      D3_SetCollBits(D3Obj,8);
      uVar7 = *(undefined4 *)&(D3Obj->pos).vz;
      *(undefined4 *)&D3Obj->last_pos = *(undefined4 *)&D3Obj->pos;
      *(undefined4 *)&(D3Obj->last_pos).vz = uVar7;
      sVar8 = 0;
      while (((-300 < (D3Obj->pos).vz && ((D3Obj->collision_state & 0x20U) == 0)) &&
             ((D3Obj->collision_state & 0xfc00U) == 0))) {
        sVar8 = sVar8 + -6;
        (D3Obj->pos).vz = (D3Obj->pos).vz + sVar8;
        Task_Next();
      }
      D3_ClearCollBits(D3Obj,9);
      sVar8 = D3Obj[1].pos.pad;
      D3Obj->display_mode = D3Obj->display_mode & 0xffef;
      uVar3 = D3Obj->collision_state;
      (D3Obj->pos).vz = sVar2;
      (D3Obj->last_pos).vz = sVar2;
      D3Obj->collision_state = uVar3 & 0xffef;
      if (sVar8 == 0) break;
      iVar9 = 0;
      if (0 < sVar8) {
        do {
          iVar9 = iVar9 + 1;
          Task_Next();
        } while (iVar9 < (int)D3Obj[1].pos.pad);
      }
      iVar9 = 0;
      Tmd_ForceSemiTrans((char)D3Obj->description);
      D3_SetCollBits(D3Obj,1);
      D3Obj->display_mode = D3Obj->display_mode | 0x10;
      Fx_Play(0x3e,(char)D3Obj + ',');
      do {
        iVar9 = iVar9 + 1;
        Task_Next();
      } while (iVar9 < 0x1e);
      Tmd_ForceSolid((char)D3Obj->description);
    } while (D3Obj[1].pos.pad != 0);
    if (bVar1) {
      Pvl_SctState[(int)D3Obj->index] = Pvl_SctState[(int)D3Obj->index] | 1;
    }
  }
  D3_DeleteObject(D3Obj);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Traps_BloodyPinns(struct _D3_OBJECT *D3Obj /*$s1*/, long XX /*$s6*/, long YY /*$s7*/, long ZZ /*$fp*/)
 // line 2741, offset 0x80054a18
	/* begin block 1 */
		// Start line: 2742
		// Start offset: 0x80054A18
		// Variables:
	// 		long SizeBB; // $s5
	// 		long Speed; // stack offset -48
	// 		long SpeedExtra; // $s5
	// 		long PosUp; // $s3
	// 		long PosDown; // $s4
	// 		long Pos; // $s2
	// 		long i; // $s0
	// 		long TestZone; // stack offset -44
	/* end block 1 */
	// End offset: 0x80054EAC
	// End Line: 2863

	/* begin block 2 */
		// Start line: 6107
	/* end block 2 */
	// End Line: 6108

void Traps_BloodyPinns(_D3_OBJECT *D3Obj,long XX,long YY,long ZZ)

{
  bool bVar1;
  long lVar2;
  long lVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int unaff_s2;
  short sVar7;
  int unaff_s3;
  short sVar8;
  short sVar9;
  int unaff_s5;
  short local_30;
  
  sVar9 = D3Obj[1].last_pos.vx;
  if ((sVar9 != 0) && (iVar5 = 0, sVar9 != 0)) {
    do {
      iVar5 = iVar5 + 1;
      Task_Next();
    } while (iVar5 < (int)(uint)(ushort)D3Obj[1].last_pos.vx);
  }
  if (XX != 0) {
    unaff_s3 = (int)(D3Obj->pos).vx;
    unaff_s5 = (int)*(short *)&D3Obj->b_step - (int)(D3Obj->b_box).vx;
    if (unaff_s5 < 0) {
      unaff_s5 = -unaff_s5;
    }
  }
  if (YY != 0) {
    unaff_s3 = (int)(D3Obj->pos).vy;
    unaff_s5 = (int)(D3Obj->b_box).vy - (int)D3Obj->comp_opt3;
    if (unaff_s5 < 0) {
      unaff_s5 = -unaff_s5;
    }
  }
  if (ZZ != 0) {
    unaff_s3 = (int)(D3Obj->pos).vz;
    unaff_s5 = (int)*(short *)&D3Obj[1].prec - (int)(D3Obj->b_box).vz;
    if (unaff_s5 < 0) {
      unaff_s5 = -unaff_s5;
    }
  }
  if (D3Obj[1].pos.vz < 0) {
    iVar5 = unaff_s3;
    unaff_s3 = unaff_s3 - unaff_s5;
  }
  else {
    iVar5 = unaff_s3 + unaff_s5;
  }
  sVar9 = (short)(unaff_s5 >> 3);
  local_30 = sVar9 + 10;
  sVar9 = sVar9 + 0xe;
  if (D3Obj[1].pos.vz < 0) {
    local_30 = -local_30;
    sVar9 = -sVar9;
  }
  lVar2 = Zone_IsZoneAttached(D3Obj);
  D3Obj->display_mode = D3Obj->display_mode & 0xffef;
  do {
    if (lVar2 != 0) {
      while (lVar3 = Task_EventRead(TaskCurrent), lVar3 != 2) {
        Task_Next();
      }
    }
    D3_ClearCollBits(D3Obj,0x2000);
    iVar6 = 0;
    if (0 < D3Obj[1].last_pos.vy) {
      do {
        iVar6 = iVar6 + 1;
        Task_Next();
      } while (iVar6 < (int)D3Obj[1].last_pos.vy);
    }
    D3Obj->display_mode = D3Obj->display_mode | 0x10;
    D3_SetCollBits(D3Obj,(long)&DAT_0000200a);
    uVar4 = *(undefined4 *)&(D3Obj->pos).vz;
    *(undefined4 *)&D3Obj->last_pos = *(undefined4 *)&D3Obj->pos;
    *(undefined4 *)&(D3Obj->last_pos).vz = uVar4;
    D3_PlaySound(D3Obj,0);
    if (XX != 0) {
      unaff_s2 = (int)(D3Obj->pos).vx;
    }
    if (YY != 0) {
      unaff_s2 = (int)(D3Obj->pos).vy;
    }
    if (ZZ != 0) {
      unaff_s2 = (int)(D3Obj->pos).vz;
    }
    sVar7 = (short)iVar5;
    if (iVar5 < unaff_s2) {
LAB_80054ce4:
      if (XX != 0) {
        (D3Obj->pos).vx = sVar7;
      }
      if (YY != 0) {
        (D3Obj->pos).vy = sVar7;
      }
      bVar1 = unaff_s2 < unaff_s3;
      if (ZZ != 0) {
        (D3Obj->pos).vz = sVar7;
      }
    }
    else {
      do {
        if (unaff_s2 < unaff_s3) break;
        Task_Next();
        if (XX != 0) {
          (D3Obj->pos).vx = (D3Obj->pos).vx + local_30;
        }
        if (YY != 0) {
          (D3Obj->pos).vy = (D3Obj->pos).vy + local_30;
        }
        if (ZZ != 0) {
          (D3Obj->pos).vz = (D3Obj->pos).vz + local_30;
        }
        if (XX != 0) {
          unaff_s2 = (int)(D3Obj->pos).vx;
        }
        if (YY != 0) {
          unaff_s2 = (int)(D3Obj->pos).vy;
        }
        if (ZZ != 0) {
          unaff_s2 = (int)(D3Obj->pos).vz;
        }
      } while (unaff_s2 <= iVar5);
      bVar1 = unaff_s2 < unaff_s3;
      if (iVar5 < unaff_s2) goto LAB_80054ce4;
    }
    sVar8 = (short)unaff_s3;
    if (bVar1) {
      if (XX != 0) {
        (D3Obj->pos).vx = sVar8;
      }
      if (YY != 0) {
        (D3Obj->pos).vy = sVar8;
      }
      if (ZZ != 0) {
        (D3Obj->pos).vz = sVar8;
      }
    }
    iVar6 = 0;
    Task_Next();
    D3_ClearCollBits(D3Obj,(long)&DAT_0000200a);
    if (0 < D3Obj[1].pos.pad) {
      do {
        iVar6 = iVar6 + 1;
        Task_Next();
      } while (iVar6 < (int)D3Obj[1].pos.pad);
    }
    if (XX != 0) {
      unaff_s2 = (int)(D3Obj->pos).vx;
    }
    if (YY != 0) {
      unaff_s2 = (int)(D3Obj->pos).vy;
    }
    if (ZZ != 0) {
      unaff_s2 = (int)(D3Obj->pos).vz;
    }
    if (iVar5 < unaff_s2) {
LAB_80054e40:
      if (XX != 0) {
        (D3Obj->pos).vx = sVar7;
      }
      if (YY != 0) {
        (D3Obj->pos).vy = sVar7;
      }
      bVar1 = unaff_s2 < unaff_s3;
      if (ZZ != 0) {
        (D3Obj->pos).vz = sVar7;
      }
    }
    else {
      do {
        if (unaff_s2 < unaff_s3) break;
        Task_Next();
        if (XX != 0) {
          (D3Obj->pos).vx = (D3Obj->pos).vx - sVar9;
        }
        if (YY != 0) {
          (D3Obj->pos).vy = (D3Obj->pos).vy - sVar9;
        }
        if (ZZ != 0) {
          (D3Obj->pos).vz = (D3Obj->pos).vz - sVar9;
        }
        if (XX != 0) {
          unaff_s2 = (int)(D3Obj->pos).vx;
        }
        if (YY != 0) {
          unaff_s2 = (int)(D3Obj->pos).vy;
        }
        if (ZZ != 0) {
          unaff_s2 = (int)(D3Obj->pos).vz;
        }
      } while (unaff_s2 <= iVar5);
      bVar1 = unaff_s2 < unaff_s3;
      if (iVar5 < unaff_s2) goto LAB_80054e40;
    }
    if (bVar1) {
      if (XX != 0) {
        (D3Obj->pos).vx = sVar8;
      }
      if (YY != 0) {
        (D3Obj->pos).vy = sVar8;
      }
      if (ZZ != 0) {
        (D3Obj->pos).vz = sVar8;
      }
    }
    D3Obj->display_mode = D3Obj->display_mode & 0xffef;
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Traps_Bullet(struct _D3_OBJECT *D3Obj /*$s2*/, long XX /*stack 4*/, long YY /*stack 8*/, long ZZ /*stack 12*/)
 // line 2865, offset 0x80054eac
	/* begin block 1 */
		// Start line: 2866
		// Start offset: 0x80054EAC
		// Variables:
	// 		struct CDOOR_8fake Color; // stack offset -56
	// 		struct CDOOR_7fake Position; // stack offset -48
	// 		long TestZone; // $s7
	// 		long KillObject; // $fp
	// 		long Collisioned; // $s3
	// 		long i; // $s0
	// 		long StartPos; // $s5
	// 		long Pos; // $s1
	// 		long Speed; // $s6
	// 		long internaltimer; // $s4
	/* end block 1 */
	// End offset: 0x8005521C
	// End Line: 2956

	/* begin block 2 */
		// Start line: 6370
	/* end block 2 */
	// End Line: 6371

void Traps_Bullet(_D3_OBJECT *D3Obj,long XX,long YY,long ZZ)

{
  bool bVar1;
  short sVar2;
  bool bVar3;
  short sVar4;
  long lVar5;
  long lVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int unaff_s5;
  
  sVar2 = D3Obj[1].pos.vz;
  iVar11 = (int)*(uint *)&D3Obj[1].last_pos >> 0x10;
  uVar7 = *(uint *)&D3Obj[1].last_pos & 0xffff;
  if ((uVar7 != 0) && (iVar9 = 0, uVar7 != 0)) {
    do {
      iVar9 = iVar9 + 1;
      Task_Next();
    } while (iVar9 < (int)(uint)(ushort)D3Obj[1].last_pos.vx);
  }
  lVar5 = Zone_IsZoneAttached(D3Obj);
  bVar1 = D3Obj[1].pos.pad != -1;
  if (!bVar1) {
    D3Obj[1].pos.pad = 0;
  }
  if (XX != 0) {
    unaff_s5 = (int)(D3Obj->pos).vx << 0x10;
  }
  if (YY != 0) {
    unaff_s5 = (int)(D3Obj->pos).vy << 0x10;
  }
  if (ZZ != 0) {
    unaff_s5 = (int)(D3Obj->pos).vz << 0x10;
  }
  *(undefined *)((int)&D3Obj[1].pos.vx + 1) = 0xe0;
  *(_D3_OBJECT **)&D3Obj[1].last_pos = D3Obj;
  do {
    sVar4 = (short)((uint)unaff_s5 >> 0x10);
    if (XX != 0) {
      (D3Obj->pos).vx = sVar4;
      (D3Obj->last_pos).vx = sVar4;
    }
    if (YY != 0) {
      (D3Obj->pos).vy = sVar4;
      (D3Obj->last_pos).vy = sVar4;
    }
    if (ZZ != 0) {
      (D3Obj->pos).vz = sVar4;
      (D3Obj->last_pos).vz = sVar4;
    }
    D3Obj->collision_state = D3Obj->collision_state & 0x3ff;
    if (lVar5 != 0) {
      Task_EventRead(TaskCurrent);
      do {
        Task_Next();
        lVar6 = Task_EventRead(TaskCurrent);
      } while (lVar6 != 2);
    }
    iVar9 = 0;
    if (0 < iVar11) {
      do {
        iVar9 = iVar9 + 1;
        Task_Next();
      } while (iVar9 < iVar11);
    }
    D3_SetCollBits(D3Obj,(long)&DAT_0000200a);
    uVar8 = *(undefined4 *)&(D3Obj->pos).vz;
    *(undefined4 *)&D3Obj->last_pos = *(undefined4 *)&D3Obj->pos;
    *(undefined4 *)&(D3Obj->last_pos).vz = uVar8;
    D3_PlaySound(D3Obj,0);
    bVar3 = false;
    iVar10 = 0;
    iVar9 = unaff_s5;
    do {
      iVar9 = iVar9 + (int)sVar2 * 0x100;
      sVar4 = (short)((uint)iVar9 >> 0x10);
      if (XX != 0) {
        (D3Obj->pos).vx = sVar4;
      }
      if (YY != 0) {
        (D3Obj->pos).vy = sVar4;
      }
      if (ZZ != 0) {
        (D3Obj->pos).vz = sVar4;
      }
      if (((int)D3Obj->collision_state & 0xfc00U) != 0) {
        bVar3 = true;
        Impact_Rain(0xd0,200,7);
        D3_ClearCollBits(D3Obj,1);
        break;
      }
      iVar10 = iVar10 + 1;
      Task_Next();
    } while (iVar10 < 0x3c);
    D3_ClearCollBits(D3Obj,0xb);
    D3Obj->display_mode = D3Obj->display_mode & 0xffef;
    if (bVar3) {
      while (bVar3 = iVar10 < 0x3c, iVar10 = iVar10 + 1, bVar3) {
        Task_Next();
      }
    }
    iVar9 = 0;
    if (0 < D3Obj[1].pos.pad) {
      do {
        iVar9 = iVar9 + 1;
        Task_Next();
      } while (iVar9 < (int)D3Obj[1].pos.pad);
    }
    D3_SetCollBits(D3Obj,1);
    sVar4 = D3Obj[1].pos.pad;
    D3Obj->display_mode = D3Obj->display_mode | 0x10;
    if (sVar4 == 0) {
      if (bVar1) {
        Pvl_SctState[(int)D3Obj->index] = Pvl_SctState[(int)D3Obj->index] | 1;
      }
      D3_DeleteObject(D3Obj);
      return;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Traps_CreateBBox(long angle /*$s3*/, long length /*$s4*/, long YY /*$s0*/, long hei /*$fp*/, long wid /*stack 16*/, long len /*stack 20*/, struct CDOOR_7fake *bb /*stack 24*/)
 // line 2959, offset 0x80055254
	/* begin block 1 */
		// Start line: 2960
		// Start offset: 0x80055254
		// Variables:
	// 		long x; // $s2
	// 		long y; // $v1
	// 		long z; // $s5
	/* end block 1 */
	// End offset: 0x800552E8
	// End Line: 2972

	/* begin block 2 */
		// Start line: 6594
	/* end block 2 */
	// End Line: 6595

void Traps_CreateBBox(long angle,long length,long YY,long hei,long wid,long len,undefined1 bb)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = rsin(angle);
  sVar2 = (short)(iVar4 * length >> 0xc);
  iVar4 = rcos(angle);
  if (YY == 0) {
    sVar3 = 0;
  }
  else {
    iVar5 = rsin(angle);
    sVar2 = 0;
    sVar3 = (short)(-iVar5 * length >> 0xc);
  }
  sVar1 = sVar2 - (short)wid;
  _bb[0x1c] = sVar1;
  _bb[0x10] = sVar1;
  _bb[0xc] = sVar1;
  *_bb = sVar1;
  sVar2 = sVar2 + (short)wid;
  _bb[0x18] = sVar2;
  _bb[0x14] = sVar2;
  _bb[8] = sVar2;
  _bb[4] = sVar2;
  sVar2 = sVar3 - (short)len;
  _bb[0x19] = sVar2;
  _bb[0x1d] = sVar2;
  _bb[9] = sVar2;
  _bb[0xd] = sVar2;
  sVar3 = sVar3 + (short)len;
  _bb[0x15] = sVar3;
  _bb[0x11] = sVar3;
  _bb[5] = sVar3;
  _bb[1] = sVar3;
  sVar2 = (short)(iVar4 * length >> 0xc);
  sVar3 = sVar2 - (short)hei;
  _bb[0xe] = sVar3;
  _bb[10] = sVar3;
  _bb[6] = sVar3;
  _bb[2] = sVar3;
  sVar2 = sVar2 + (short)hei;
  _bb[0x1e] = sVar2;
  _bb[0x1a] = sVar2;
  _bb[0x16] = sVar2;
  _bb[0x12] = sVar2;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Traps_Balance(struct _D3_OBJECT *D3Obj /*$s4*/, long YY /*$s6*/)
 // line 2981, offset 0x800553a4
	/* begin block 1 */
		// Start line: 2982
		// Start offset: 0x800553A4
		// Variables:
	// 		long i; // $s0
	// 		long enda; // stack offset -72
	// 		long endb; // stack offset -68
	// 		long brake; // $s7
	// 		long end; // $s3
	// 		long speed; // $s1
	// 		long gravity; // $s2
	// 		long grav; // stack offset -64
	// 		long currentpos; // $s0
	// 		long w; // stack offset -60
	// 		long h; // stack offset -56
	// 		long l; // stack offset -52
	// 		long length; // $fp
	// 		long changed; // $s5
	/* end block 1 */
	// End offset: 0x800556D4
	// End Line: 3086

	/* begin block 2 */
		// Start line: 6642
	/* end block 2 */
	// End Line: 6643

void Traps_Balance(_D3_OBJECT *D3Obj,long YY)

{
  bool bVar1;
  int len;
  int hei;
  int wid;
  int iVar2;
  int iVar3;
  int iVar4;
  int angle;
  int iVar5;
  int iVar6;
  short sVar7;
  int length;
  char bb;
  int local_48;
  int local_40;
  
  local_40 = 1;
  wid = (int)*(short *)&D3Obj->b_step - (int)(D3Obj->b_box).vx >> 1;
  len = (int)(D3Obj->b_box).vy - (int)D3Obj->comp_opt3 >> 1;
  hei = wid + len >> 1;
  length = hei - ((int)*(short *)&D3Obj[1].prec - (int)(D3Obj->b_box).vz);
  iVar4 = (uint)(ushort)D3Obj[1].pos.vz << 0x10;
  iVar2 = iVar4 >> 0x10;
  if (0x380 < iVar2) {
    local_40 = 2;
  }
  if (0x600 < iVar2) {
    local_40 = 4;
  }
  iVar4 = iVar4 >> 0x11;
  if (YY == 0) {
    local_48 = (int)(D3Obj->rot).vy;
    iVar2 = (int)(D3Obj->rot).vx;
    iVar3 = local_48 - iVar4;
  }
  else {
    iVar2 = (int)(D3Obj->rot).vx;
    iVar3 = iVar2 - iVar4;
    local_48 = iVar2;
  }
  local_48 = local_48 + iVar4;
  iVar4 = 0;
  if (D3Obj[1].last_pos.vx != 0) {
    do {
      iVar4 = iVar4 + 1;
      Task_Next();
    } while (iVar4 < (int)(uint)(ushort)D3Obj[1].last_pos.vx);
  }
  if (D3Obj->hit_power == '\0') {
    D3_ClearCollBits(D3Obj,(long)&DAT_0000200a);
  }
  else {
    D3_SetCollBits(D3Obj,(long)&DAT_0000200a);
  }
  if (YY == 0) {
    (D3Obj->rot).vy = (short)iVar3;
  }
  else {
    (D3Obj->rot).vx = (short)iVar3;
  }
  bb = (char)D3Obj + 'L';
  iVar4 = iVar3;
  do {
    if (YY == 0) {
      sVar7 = (D3Obj->rot).vy;
    }
    else {
      sVar7 = (D3Obj->rot).vx;
    }
    angle = (int)sVar7;
    bVar1 = iVar4 == local_48;
    iVar6 = 0;
    iVar5 = local_40;
    iVar4 = local_48;
    if (bVar1) {
      iVar5 = -local_40;
      iVar4 = iVar3;
    }
    bVar1 = false;
    sVar7 = (short)iVar4;
    if (iVar5 < 1) {
      D3_PlaySound(D3Obj,0);
      do {
        if (angle < iVar4) break;
        if ((!bVar1) && (angle < iVar2)) {
          iVar5 = -iVar5;
          iVar6 = iVar6 + iVar5;
          bVar1 = true;
        }
        angle = angle + iVar6;
        iVar6 = iVar6 + iVar5;
        Task_Next();
        if (YY == 0) {
          (D3Obj->rot).vy = (short)angle;
        }
        else {
          (D3Obj->rot).vx = (short)angle;
        }
        Traps_CreateBBox(angle,length,YY,hei,wid,len,bb);
      } while (iVar6 != 0);
      if (YY != 0) goto LAB_8005568c;
      (D3Obj->rot).vy = sVar7;
    }
    else {
      D3_PlaySound(D3Obj,0);
      do {
        if (iVar4 < angle) break;
        if ((!bVar1) && (iVar2 < angle)) {
          iVar5 = -iVar5;
          iVar6 = iVar6 + iVar5;
          bVar1 = true;
        }
        angle = angle + iVar6;
        iVar6 = iVar6 + iVar5;
        Task_Next();
        if (YY == 0) {
          (D3Obj->rot).vy = (short)angle;
        }
        else {
          (D3Obj->rot).vx = (short)angle;
        }
        Traps_CreateBBox(angle,length,YY,hei,wid,len,bb);
      } while (iVar6 != 0);
      if (YY == 0) {
        (D3Obj->rot).vy = sVar7;
      }
      else {
LAB_8005568c:
        (D3Obj->rot).vx = sVar7;
      }
    }
    iVar5 = 0;
    Task_Next();
    if (0 < D3Obj[1].last_pos.vy) {
      do {
        iVar5 = iVar5 + 1;
        Task_Next();
      } while (iVar5 < (int)D3Obj[1].last_pos.vy);
    }
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Traps_CreateVentiloBBox(struct _D3_OBJECT *o /*$s0*/, long offset /*$s1*/)
 // line 3089, offset 0x800556d4
	/* begin block 1 */
		// Start line: 3090
		// Start offset: 0x800556D4
		// Variables:
	// 		struct CDOOR_5fake mr; // stack offset -96
	// 		struct CDOOR_7fake min; // stack offset -64
	// 		struct CDOOR_7fake max; // stack offset -56
	// 		struct CDOOR_7fake angle; // stack offset -48
	// 		struct CDOOR_6fake dummy; // stack offset -40
	// 		struct _PLATFORM *plat; // $a0
	// 		long i; // $a1
	// 		long f; // stack offset -24
	/* end block 1 */
	// End offset: 0x800558D8
	// End Line: 3135

	/* begin block 2 */
		// Start line: 6911
	/* end block 2 */
	// End Line: 6912

void Traps_CreateVentiloBBox(_D3_OBJECT *o,long offset)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 in_zero;
  undefined4 in_at;
  _PLATFORM *p_Var4;
  undefined4 *puVar5;
  _D3_OBJECT *p_Var6;
  int iVar7;
  int iVar8;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  short local_40;
  undefined2 local_3e;
  undefined2 local_3c;
  undefined2 local_38;
  undefined2 local_36;
  undefined2 local_34;
  undefined4 local_30;
  uint local_2c;
  short local_28;
  short local_24;
  short local_20;
  
  memset(&local_30,0,8);
  p_Var4 = Plat_GetPlat((char)o + ',');
  if ((o->rot).vz == 0x800) {
    iVar7 = offset + -0x10e;
  }
  else {
    iVar7 = 0xaa - offset;
  }
  local_3e = 0xfff6;
  local_40 = (short)iVar7;
  local_38 = (undefined2)(iVar7 + 100);
  local_36 = 10;
  local_34 = 0;
  iVar8 = (uint)*(ushort *)&p_Var4[1].obj.prec - (uint)(ushort)(o->pos).vz;
  local_3c = (undefined2)iVar8;
  D3_SetBox(o,(int)local_40,-10,iVar8 * 0x10000 >> 0x10,(iVar7 + 100) * 0x10000 >> 0x10,10,0);
  if (((o->rot).vz & 0x7ffU) != 0) {
    setCopReg(2,in_zero,local_30);
    setCopReg(2,in_at,local_2c);
    copFunction(2,0x486012);
    local_4c = getCopReg(2,0x19);
    local_48 = getCopReg(2,0x1a);
    local_44 = getCopReg(2,0x1b);
    local_2c = local_2c & 0xffff0000 | (uint)(ushort)(o->rot).vz;
    RotMatrix((short *)&local_30,(undefined2 *)&local_60);
    setCopControlWord(2,0x2800,local_4c);
    setCopControlWord(2,0x3000,local_48);
    setCopControlWord(2,0x3800,local_44);
    setCopControlWord(2,0,local_60);
    setCopControlWord(2,0x800,local_5c);
    setCopControlWord(2,0x1000,local_58);
    setCopControlWord(2,0x1800,local_54);
    setCopControlWord(2,0x2000,local_50);
    iVar8 = 0;
    iVar7 = 0x4c;
    p_Var6 = o;
    do {
      puVar5 = (undefined4 *)((int)&o->next + iVar7);
      setCopReg(2,in_zero,*puVar5);
      setCopReg(2,in_at,puVar5[1]);
      copFunction(2,0x480012);
      uVar1 = getCopReg(2,0x19);
      uVar2 = getCopReg(2,0x1a);
      uVar3 = getCopReg(2,0x1b);
      getCopControlWord(2,0xf800);
      local_28 = (short)uVar1;
      (p_Var6->b_box).vx = local_28;
      local_24 = (short)uVar2;
      iVar7 = iVar7 + 8;
      (p_Var6->b_box).vy = local_24;
      local_20 = (short)uVar3;
      iVar8 = iVar8 + 1;
      (p_Var6->b_box).vz = local_20;
      p_Var6 = (_D3_OBJECT *)&p_Var6->child;
    } while (iVar8 < 8);
    setCopControlWord(2,0x2800,Cam_Matrix.t[0]);
    setCopControlWord(2,0x3000,Cam_Matrix.t[1]);
    setCopControlWord(2,0x3800,Cam_Matrix.t[2]);
    setCopControlWord(2,0,Cam_Matrix.m[0]._0_4_);
    setCopControlWord(2,0x800,Cam_Matrix.m._4_4_);
    setCopControlWord(2,0x1000,Cam_Matrix.m[1]._2_4_);
    setCopControlWord(2,0x1800,Cam_Matrix.m[2]._0_4_);
    setCopControlWord(2,0x2000,Cam_Matrix._16_4_);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Traps_Ventilo(struct _D3_OBJECT *D3Obj /*$s1*/)
 // line 3138, offset 0x800558ec
	/* begin block 1 */
		// Start line: 3139
		// Start offset: 0x800558EC
		// Variables:
	// 		struct CDOOR_7fake step; // stack offset -40
	// 		long angmin; // $s4
	// 		long angmax; // $s5
	// 		long dist; // $s6
	// 		long unefois; // $s3
	// 		struct _D3_OBJECT *child; // $s0
	/* end block 1 */
	// End offset: 0x80055B90
	// End Line: 3207

	/* begin block 2 */
		// Start line: 7038
	/* end block 2 */
	// End Line: 7039

/* WARNING: Removing unreachable block (ram,0x80055b1c) */
/* WARNING: Removing unreachable block (ram,0x80055b2c) */
/* WARNING: Removing unreachable block (ram,0x80055b34) */

void Traps_Ventilo(_D3_OBJECT *D3Obj)

{
  short sVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  _D3_OBJECT *p_Var7;
  int unaff_s3;
  short local_28;
  short local_26;
  short local_24;
  
  memset(&local_28,0,8);
  iVar3 = ((int)((uint)(ushort)D3Obj[1].pos.vz << 0x10) >> 0x18) * 0x1000;
  local_26 = (short)((ulonglong)((longlong)iVar3 * 0xb60b60b7) >> 0x28) - (short)(iVar3 >> 0x1f);
  D3Obj->display_mode = D3Obj->display_mode | 3;
  D3_SetCollBits(D3Obj,(long)&DAT_00002002);
  uVar6 = *(undefined4 *)&(D3Obj->pos).vz;
  *(undefined4 *)&D3Obj->last_pos = *(undefined4 *)&D3Obj->pos;
  *(undefined4 *)&(D3Obj->last_pos).vz = uVar6;
  p_Var7 = D3Obj->child;
  while (p_Var7 != (_D3_OBJECT *)0x0) {
    D3Obj->child->display_mode = D3Obj->child->display_mode | 3;
    D3Obj->child->display_mode = D3Obj->child->display_mode & 0xffef;
    D3_ClearCollBits(D3Obj->child,9);
    p_Var7 = p_Var7->next;
  }
  do {
    D3_ClearCollBits(D3Obj,9);
    uVar4 = SEXT24(D3Obj[1].pos.pad);
    if ((uVar4 == 0) || ((Scts_Interruptors & uVar4) != 0)) {
      (D3Obj->rot).vx = (D3Obj->rot).vx + local_28;
      sVar1 = (D3Obj->rot).vx;
      iVar3 = (int)sVar1;
      (D3Obj->rot).vy = (D3Obj->rot).vy + local_26;
      (D3Obj->rot).vz = (D3Obj->rot).vz + local_24;
      if (iVar3 < 0) {
        iVar3 = iVar3 + 0xfff;
      }
      sVar2 = (D3Obj->rot).vy;
      iVar5 = (int)sVar2;
      (D3Obj->rot).vx = sVar1 + (short)(iVar3 >> 0xc) * -0x1000;
      if (iVar5 < 0) {
        iVar5 = iVar5 + 0xfff;
      }
      sVar1 = (D3Obj->rot).vz;
      iVar3 = (int)sVar1;
      (D3Obj->rot).vy = sVar2 + (short)(iVar5 >> 0xc) * -0x1000;
      if (iVar3 < 0) {
        iVar3 = iVar3 + 0xfff;
      }
      p_Var7 = D3Obj->child;
      (D3Obj->rot).vz = sVar1 + (short)(iVar3 >> 0xc) * -0x1000;
      if (p_Var7 != (_D3_OBJECT *)0x0) {
        p_Var7->display_mode = p_Var7->display_mode | 0x10;
        D3_RotList(D3Obj->child,0xd8);
      }
      iVar3 = (int)(D3Obj->rot).vy;
      if ((iVar3 < 0x75a) || (0x8a6 < iVar3)) {
        unaff_s3 = 0;
      }
      else {
        Traps_CreateVentiloBBox(D3Obj,((iVar3 + -0x75a) * 0x1b8) / 0x14c);
        if (unaff_s3 == 0) {
          unaff_s3 = 1;
          D3_PlaySound(D3Obj,0);
        }
        if ((D3Obj->collision_state & 0x80U) != 0) {
          D3_SetCollBits(D3Obj,9);
        }
      }
    }
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Traps_LethalPick(struct _D3_OBJECT *obj /*$s1*/)
 // line 3210, offset 0x80055b90
	/* begin block 1 */
		// Start line: 3211
		// Start offset: 0x80055B90
		// Variables:
	// 		long i; // $s0
	// 		long TestZone; // $s2
	/* end block 1 */
	// End offset: 0x80055C88
	// End Line: 3249

	/* begin block 2 */
		// Start line: 7208
	/* end block 2 */
	// End Line: 7209

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Traps_LethalPick(_D3_OBJECT *obj)

{
  long lVar1;
  long lVar2;
  int iVar3;
  
  lVar1 = Zone_IsZoneAttached(obj);
  D3_ClearCollBits(obj,8);
  D3_SetCollBits(obj,(long)&DAT_00002002);
  obj->hit_power = 'd';
  do {
    if (lVar1 != 0) {
      lVar2 = Task_EventRead(TaskCurrent);
      if (lVar2 == 1) {
        D3_SetCollBits(obj,8);
      }
      else {
        if (lVar2 == 4) {
          D3_ClearCollBits(obj,8);
        }
      }
      if (((obj->collision_mode & 8U) != 0) && (iVar3 = 0, (_DAT_800b1c56 & 2) != 0)) {
        do {
          Impact_Blood(100,10);
          Task_Sleep(10);
          iVar3 = iVar3 + 1;
        } while (iVar3 < 10);
      }
    }
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Traps_Trappe(struct _D3_OBJECT *obj /*$s0*/)
 // line 3256, offset 0x80055c88
	/* begin block 1 */
		// Start line: 3257
		// Start offset: 0x80055C88
		// Variables:
	// 		struct CDOOR_7fake rot; // stack offset -16
	/* end block 1 */
	// End offset: 0x80055E14
	// End Line: 3309

	/* begin block 2 */
		// Start line: 7303
	/* end block 2 */
	// End Line: 7304

void Traps_Trappe(_D3_OBJECT *obj)

{
  short Fx;
  ushort uVar1;
  uint uVar2;
  
  uVar2 = SEXT24(obj[1].pos.vz);
  if ((Scts_Interruptors & uVar2) == 0) goto LAB_80055cdc;
  Scts_Interruptors = Scts_Interruptors & ~uVar2;
  do {
    while( true ) {
      uVar2 = SEXT24(obj[1].pos.vz);
LAB_80055cdc:
      if ((Scts_Interruptors & uVar2) != 0) break;
      Task_Next();
    }
    D3_ClearCollBits(obj,1);
    Fx = *(short *)((int)&obj[1].father + 2);
    if (Fx != -1) {
      Fx_Play(Fx,0);
    }
    Fx = (obj->rot).vx;
    while (Fx < 0x400) {
      D3_RotList(obj->child,0xf0);
      Trps_ClearCollisions(obj->child);
      Task_Next();
      Fx = (obj->rot).vx + 0x80;
      (obj->rot).vx = Fx;
    }
    Task_Sleep((int)Scr_TicksPerSecond * 5);
    if (0 < (obj->rot).vx) {
      do {
        D3_RotList(obj->child,0xf0);
        Trps_ClearCollisions(obj->child);
        Task_Next();
        uVar1 = (obj->rot).vx - 0x80;
        (obj->rot).vx = uVar1;
      } while (0 < (int)((uint)uVar1 << 0x10));
    }
    D3_SetCollBits(obj,1);
    Scts_Interruptors = Scts_Interruptors & ~(int)obj[1].pos.vz;
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Trps_ClearCollisions(struct _D3_OBJECT *o /*$s0*/)
 // line 3311, offset 0x80055e14
	/* begin block 1 */
		// Start line: 7466
	/* end block 1 */
	// End Line: 7467

void Trps_ClearCollisions(_D3_OBJECT *o)

{
  if (o != (_D3_OBJECT *)0x0) {
    do {
      if (o->child != (_D3_OBJECT *)0x0) {
        Trps_ClearCollisions(o->child);
      }
      D3_ClearCollBits(o,1);
      o = o->next;
    } while (o != (_D3_OBJECT *)0x0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Traps_VitreFragile(struct _D3_OBJECT *o /*$s0*/)
 // line 3327, offset 0x80055e6c
	/* begin block 1 */
		// Start line: 3328
		// Start offset: 0x80055E6C
		// Variables:
	// 		long maxi; // $a1
	/* end block 1 */
	// End offset: 0x80055F44
	// End Line: 3355

	/* begin block 2 */
		// Start line: 7503
	/* end block 2 */
	// End Line: 7504

void Traps_VitreFragile(_D3_OBJECT *o)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = o[1].pos.vz;
  uVar2 = (uint)uVar1;
  iVar3 = (int)(uVar2 << 0x10) >> 0x10;
  if (iVar3 != 0) {
    do {
      if ((o->collision_state & 0x10U) != 0) {
        o[1].pos.vz = uVar1 - 1;
        if ((int)(short)(uVar1 - 1) == (iVar3 << 1) / 3) {
          D3_PlaySound(o,1);
        }
        if ((int)o[1].pos.vz == (iVar3 / 3 + (iVar3 >> 0x1f)) - ((int)(uVar2 << 0x10) >> 0x1f)) {
          D3_PlaySound(o,0);
        }
        if (o[1].pos.vz == 0x1e) {
          D3_PlaySound(o,2);
        }
      }
      Task_Next();
      uVar1 = o[1].pos.vz;
    } while (o[1].pos.vz != 0);
  }
  D3_ExplodeObject(o);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Traps_HiddenGrenade(struct _D3_OBJECT *o /*$s3*/)
 // line 3359, offset 0x80055f64
	/* begin block 1 */
		// Start line: 3360
		// Start offset: 0x80055F64
		// Variables:
	// 		struct _MONSTER *monst; // stack offset -48
	// 		struct _D3_OBJECT *ro; // $s1
	// 		struct _D3_OBJECT *father; // $s6
	// 		struct M_OBJECT *mofat; // $s7
	// 		struct _D3_OBJECT *plat; // $s5
	// 		struct _D3_OBJECT *plats; // $s4
	// 		struct CDOOR_7fake orig; // stack offset -64
	// 		struct CDOOR_7fake spd; // stack offset -56
	// 		long dir; // $s2
	// 		long duration; // $s2
	// 		long i; // $v1
	// 		long rotz; // $s0
	// 		struct _D3_OBJECT *explo; // $v0
	/* end block 1 */
	// End offset: 0x800563D0
	// End Line: 3496

	/* begin block 2 */
		// Start line: 7567
	/* end block 2 */
	// End Line: 7568

void Traps_HiddenGrenade(_D3_OBJECT *o)

{
  short sVar1;
  long lVar2;
  _D3_OBJECT *p_Var3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  _D3_OBJECT *p_Var11;
  _D3_OBJECT *obj;
  int iVar12;
  _D3_OBJECT *p_Var13;
  _D3_OBJECT *o_00;
  void *pvVar14;
  
  pvVar14 = o->father->description;
  o_00 = o->father->father;
  *(ushort *)((int)pvVar14 + 0x28) = *(ushort *)((int)pvVar14 + 0x28) & 0xfffe;
  o->display_mode = o->display_mode & 0xffef;
  D3_ClearCollBits(o,9);
  uVar6 = *(undefined4 *)&o->pos;
  uVar8 = *(undefined4 *)&(o->pos).vz;
  p_Var11 = o_00->child;
  sVar1 = p_Var11[1].pos.vz;
  while (sVar1 != 0) {
    p_Var11 = p_Var11->next;
    sVar1 = p_Var11[1].pos.vz;
  }
  p_Var11 = p_Var11->child;
  obj = p_Var11;
  while (obj != (_D3_OBJECT *)0x0) {
    if (*(char *)((int)&obj[1].pos.vx + 1) == '\x06') {
      obj = obj->child;
      break;
    }
    obj = obj->next;
  }
  iVar7 = *(int *)&obj[1].last_pos;
  p_Var13 = p_Var11;
  while ((p_Var13 != (_D3_OBJECT *)0x0 && (*(char *)((int)&p_Var13[1].pos.vx + 1) != '\n'))) {
    p_Var13 = p_Var13->next;
  }
  do {
    if (p_Var11 == (_D3_OBJECT *)0x0) {
LAB_800560c4:
      Task_Next();
      o_00->display_mode = o_00->display_mode & 0xffef;
      do {
        o_00->display_mode = o_00->display_mode & 0xffef;
        Pvl_ClearStateBits(o_00,2);
        while( true ) {
          lVar2 = Pvl_TestStateBits(o_00,2);
          iVar10 = 0;
          if (lVar2 != 0) break;
          Task_Next();
        }
        iVar12 = 0;
        *(ushort *)((int)pvVar14 + 0x28) = *(ushort *)((int)pvVar14 + 0x28) & 0xfffe | 4;
        do {
          lVar2 = Direction((int)(obj->pos).vx - (int)(o->father->pos).vx,
                            (int)(obj->pos).vy - (int)(o->father->pos).vy);
          uVar4 = (lVar2 - (int)(o->father->rot).vz) - iVar10;
          uVar5 = uVar4;
          if ((int)uVar4 < 0) {
            uVar5 = -uVar4;
          }
          if (0x10 < (int)uVar5) {
            if ((uVar4 & 0xfff) < 0x800) {
              iVar10 = iVar10 + 0x10;
            }
            if (0x800 < (uVar4 & 0xfff)) {
              iVar10 = iVar10 + -0x10;
            }
          }
          *(short *)((int)pvVar14 + 0x26) = (short)iVar10;
          Task_Next();
          iVar12 = iVar12 + 1;
        } while (iVar12 < 0x3c);
        iVar12 = 0;
        o->display_mode = o->display_mode | 0x10;
        D3_PlaySound(o,0);
        *(undefined4 *)&o->pos = uVar6;
        *(undefined4 *)&(o->pos).vz = uVar8;
        uVar9 = *(undefined4 *)&(o->pos).vz;
        *(undefined4 *)&o->last_pos = *(undefined4 *)&o->pos;
        *(undefined4 *)&(o->last_pos).vz = uVar9;
        (o->rot).vz = (short)iVar10 + 0x400;
        do {
          iVar12 = iVar12 + 1;
          iVar10 = rcos((int)(o->rot).vz);
          sVar1 = (o->rot).vz;
          (o->pos).vx = (o->pos).vx + (short)(iVar10 * 0x23 >> 0xc);
          iVar10 = rsin((int)sVar1);
          (o->pos).vy = (o->pos).vy + (short)(iVar10 * 0x23 >> 0xc);
          if (0xf < iVar12) {
            iVar12 = 0x10;
            if ((int)(obj->pos).vz + 200 < (int)(o->pos).vz) {
              (o->pos).vz = (o->pos).vz + -0x10;
            }
            D3_GoToDir(o,(int)(obj->pos).vx - (int)(o->pos).vx,(int)(obj->pos).vy - (int)(o->pos).vy
                       ,0x3c);
          }
          Task_Next();
          lVar2 = Distance2D((int)(obj->pos).vx,(int)(obj->pos).vy,(int)(o->pos).vx,(int)(o->pos).vy
                            );
        } while (100 < lVar2);
        *(undefined2 *)(iVar7 + 0xf2) = 0;
        *(undefined2 *)((int)pvVar14 + 0x26) = 0;
        SFX_Explosion((char)o + ',',1,0);
        o->display_mode = o->display_mode & 0xffef;
        *(undefined *)((int)&p_Var13[1].pos.vx + 1) = 3;
        if ((Scts_Interruptors & *(uint *)&p_Var11[1].last_pos) != *(uint *)&p_Var11[1].last_pos) {
          *(undefined *)((int)&p_Var11[1].pos.vx + 1) = 3;
        }
        uVar5 = *(uint *)&p_Var11->next[1].last_pos;
        if ((Scts_Interruptors & uVar5) != uVar5) {
          *(undefined *)((int)&p_Var11->next[1].pos.vx + 1) = 3;
        }
        p_Var3 = Monster_GetChild(obj,2);
        if (p_Var3 == (_D3_OBJECT *)0x0) {
          p_Var3 = Monster_GetChild(obj,4);
          if (p_Var3 == (_D3_OBJECT *)0x0) {
            obj->hit_points = 0;
          }
          else {
            p_Var3->hit_points = 0;
            obj->hit_points = obj->hit_points >> 1;
          }
        }
        else {
          p_Var3->hit_points = 0;
          sVar1 = obj->hit_points;
          obj->hit_points =
               sVar1 - ((short)((ulonglong)((longlong)(int)sVar1 * 0x55555556) >> 0x20) -
                       (sVar1 >> 0xf));
        }
      } while( true );
    }
    if ((*(uint *)&p_Var11[1].pos & 0xffffff00) == 0) {
      p_Var11 = p_Var11->child;
      goto LAB_800560c4;
    }
    p_Var11 = p_Var11->next;
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Traps_BroSurvive(struct _D3_OBJECT *o /*$s0*/)
 // line 3498, offset 0x800563d0
	/* begin block 1 */
		// Start line: 3499
		// Start offset: 0x800563D0
		// Variables:
	// 		struct _D3_OBJECT *tmp; // $v1
	/* end block 1 */
	// End offset: 0x80056448
	// End Line: 3511

	/* begin block 2 */
		// Start line: 7886
	/* end block 2 */
	// End Line: 7887

void Traps_BroSurvive(_D3_OBJECT *o)

{
  short sVar1;
  _D3_OBJECT *p_Var2;
  
  sVar1 = o->hit_points;
  while (sVar1 != 0) {
    Task_Next();
    sVar1 = o->hit_points;
  }
  p_Var2 = o->father->child;
  while (p_Var2 != (_D3_OBJECT *)0x0) {
    if ((p_Var2->display_mode & 0x10U) == 0) {
      p_Var2->display_mode = p_Var2->display_mode | 0x10;
    }
    p_Var2 = p_Var2->next;
  }
  D3_ExplodeObject(o);
  return;
}





