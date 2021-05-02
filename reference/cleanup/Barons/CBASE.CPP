#include "THISDUST.H"
#include "CBASE.H"


// decompiled code
// original method signature: 
// void /*$ra*/ CB_BonusTask()
 // line 81, offset 0x80047860
	/* begin block 1 */
		// Start line: 82
		// Start offset: 0x80047860
		// Variables:
	// 		struct _D3_OBJECT *o; // $s0
	// 		struct _D3_OBJECT obj; // stack offset -192

		/* begin block 1.1 */
			// Start line: 120
			// Start offset: 0x80047940
			// Variables:
		// 		long i; // $a2
		/* end block 1.1 */
		// End offset: 0x80047AD8
		// End Line: 157

		/* begin block 1.2 */
			// Start line: 170
			// Start offset: 0x80047B1C
			// Variables:
		// 		long event; // $s2

			/* begin block 1.2.1 */
				// Start line: 177
				// Start offset: 0x80047B5C
				// Variables:
			// 		long duration; // $s1
			/* end block 1.2.1 */
			// End offset: 0x80047C24
			// End Line: 204
		/* end block 1.2 */
		// End offset: 0x80047CFC
		// End Line: 234
	/* end block 1 */
	// End offset: 0x80047D0C
	// End Line: 238

	/* begin block 2 */
		// Start line: 163
	/* end block 2 */
	// End Line: 164

/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void CB_BonusTask(void)

{
  short sVar1;
  TASK *pTVar2;
  undefined *puVar3;
  _D3_OBJECT *p_Var4;
  long nx;
  int iVar5;
  long ny;
  int iVar6;
  long nz;
  uint uVar7;
  undefined4 uVar8;
  _D3_OBJECT *o;
  long local_d0;
  long local_cc;
  long local_c8;
  _D3_OBJECT *local_c0;
  _D3_OBJECT *local_bc;
  _D3_OBJECT *local_b8;
  _D3_OBJECT *local_b4;
  TASK *local_ac;
  ushort local_a6;
  short local_a4;
  void *local_9c;
  long local_98;
  undefined4 local_94;
  uint local_90;
  undefined4 local_84;
  uint local_80;
  _ROTMATRIX *local_7c;
  undefined2 local_66;
  
  o = (_D3_OBJECT *)TaskCurrent->local;
  if (*(undefined **)&o[1].last_pos != &DAT_00001234) {
    if ((Pvl_BossState & 0x800U) == 0) {
      o->exp = '\0';
      Pvl_BossState = Pvl_BossState | 0x800;
    }
    else {
      o->exp = '\x01';
      Pvl_BossState = Pvl_BossState & 0xf7ff;
    }
  }
  TaskCurrent->display = CB_BonusDisplay2;
  sVar1 = o[1].pos.vy;
  if (((sVar1 != 0x16) && (sVar1 != 0x12)) && (o[1].pos.vz != 0x4d)) {
    (o->pos).vz = (o->pos).vz + 0x32;
  }
  pTVar2 = TaskCurrent;
  puVar3 = &local_c0;
  if ((o->display_mode & 0x1000U) != 0) {
    *(undefined **)&TaskCurrent->local = puVar3;
    pTVar2->display = CB_BonusDisplay;
    local_94 = *(undefined4 *)&o->pos;
    uVar7 = *(uint *)&(o->pos).vz;
    (o->pos).vz = (o->pos).vz + 0x32;
    local_90._0_2_ = (short)uVar7;
    local_90 = uVar7 & 0xffff0000 | (uint)(ushort)((short)local_90 + 0x32);
    local_84 = *(undefined4 *)&o->rot;
    local_80 = *(uint *)&(o->rot).vz;
    local_66 = 0;
    iVar5 = 0;
    local_a4 = o->collision_mode;
    local_a6 = o->display_mode & 0xefff;
    local_7c = o->matrices;
    local_b4 = (_D3_OBJECT *)0x0;
    local_c0 = (_D3_OBJECT *)0x0;
    local_bc = (_D3_OBJECT *)0x0;
    local_b8 = (_D3_OBJECT *)0x0;
    local_ac = (TASK *)0x0;
    p_Var4 = o;
    do {
      uVar8 = *(undefined4 *)&(p_Var4->b_box).vz;
      *(undefined4 *)(puVar3 + 0x4c) = *(undefined4 *)&p_Var4->b_box;
      *(undefined4 *)(puVar3 + 0x50) = uVar8;
      p_Var4 = (_D3_OBJECT *)&p_Var4->child;
      iVar5 = iVar5 + 1;
      puVar3 = puVar3 + 8;
    } while (iVar5 < 8);
    sVar1 = o[1].pos.vy;
    if ((sVar1 == 0x17) || (sVar1 == 0x14)) {
      nx = -0x32;
      local_9c = (void *)((int)o->description + (int)o[1].pos.vz * 0x1c + 0xc);
      local_98 = o->color;
      ny = -0x32;
      nz = -0x32;
      o->display_mode = o->display_mode & 0xffef;
      local_d0 = 0x32;
      local_cc = 0x32;
      local_c8 = 0x32;
    }
    else {
      local_9c = (void *)((int)o->description + 0x28);
      D3_ClearCollBits((_D3_OBJECT *)&local_c0,1);
      nx = -0x28;
      ny = -0x28;
      nz = -0x14;
      local_d0 = 0x28;
      local_cc = 0x28;
      local_c8 = 0x14;
    }
    D3_SetBox(o,nx,ny,nz,local_d0,local_cc,local_c8);
  }
  do {
    if ((o->collision_state & 0x80U) == 0) {
      sVar1 = o[1].pos.vy;
      if ((sVar1 == 0x17) || (sVar1 == 0x14)) {
LAB_80047cb0:
        local_80 = local_80 & 0xffff0000 | (uint)(ushort)((short)local_80 + 0x1e);
      }
      else {
        local_a6 = local_a6 & 0xffef;
      }
    }
    else {
      nx = Task_EventRead(TaskCurrent);
      if ((o->display_mode & 0x10U) != 0) {
        local_a6 = local_a6 | 0x10;
      }
      if (nx == -0x4000) {
        iVar6 = TaskCurrent->event_param;
        iVar5 = (int)Scr_TicksPerSecond;
        local_a6 = local_a6 & 0xffef;
        o->display_mode = o->display_mode & 0xffef;
        D3_ClearCollBits(o,1);
        sVar1 = o[1].pos.vy;
        if (sVar1 == 1) {
          CB_BonusTestMana(o);
        }
        else {
          if (sVar1 == 2) {
            CB_BonusTestAmmo(o);
          }
          else {
            Task_Sleep(iVar6 * iVar5);
          }
        }
        Impact_Smoke((char)o + ',',1);
        Fx_Play(0x3b,100);
        local_a6 = local_a6 | 0x10;
        o->display_mode = o->display_mode | 0x10;
        D3_SetCollBits(o,1);
      }
      if ((o->display_mode & 0x1000U) != 0) {
        if (nx == -0x2000) {
          Fx_Play(0x3e,0);
          sVar1 = o[1].pos.vy;
          if ((sVar1 == 0x17) || (sVar1 == 0x14)) {
            o->display_mode = o->display_mode & 0xffef;
          }
          local_a6 = local_a6 | 0x10;
          local_94 = *(undefined4 *)&o->pos;
          local_90 = *(uint *)&(o->pos).vz;
        }
        (o->rot).vz = (o->rot).vz + -0x5a;
        goto LAB_80047cb0;
      }
      sVar1 = o[1].pos.vy;
      if (((sVar1 != 0x16) && (sVar1 != 0x12)) && (o[1].pos.vz != 0x4d)) {
        (o->rot).vz = (o->rot).vz + -0x1e;
      }
    }
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_BonusDisplay()
 // line 263, offset 0x80047d0c
	/* begin block 1 */
		// Start line: 264
		// Start offset: 0x80047D0C
		// Variables:
	// 		struct _D3_OBJECT *o; // $a0
	/* end block 1 */
	// End offset: 0x80047D58
	// End Line: 281

	/* begin block 2 */
		// Start line: 643
	/* end block 2 */
	// End Line: 644

/* WARNING: Unknown calling convention yet parameter storage is locked */

void CB_BonusDisplay(void)

{
  if ((((_D3_OBJECT *)TaskCurrent->local)->display_mode & 0x1010U) != 0) {
    Main_Prims = D3_DisplayTmd((_D3_OBJECT *)TaskCurrent->local,Main_Prims,0,(int)Scr_W);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_BonusDisplay2()
 // line 284, offset 0x80047d68
	/* begin block 1 */
		// Start line: 700
	/* end block 1 */
	// End Line: 701

/* WARNING: Unknown calling convention yet parameter storage is locked */

void CB_BonusDisplay2(void)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_BonusTestAmmo(struct _D3_OBJECT *o /*$s2*/)
 // line 303, offset 0x80047d70
	/* begin block 1 */
		// Start line: 304
		// Start offset: 0x80047D70
		// Variables:
	// 		long nObjects; // $s0
	// 		long ammo; // $s1
	/* end block 1 */
	// End offset: 0x80047E0C
	// End Line: 315

	/* begin block 2 */
		// Start line: 723
	/* end block 2 */
	// End Line: 724

void CB_BonusTestAmmo(_D3_OBJECT *o)

{
  short sVar1;
  short sVar2;
  
  sVar2 = Invent_GetNbObjects(o[1].pos.vy,o[1].pos.vz);
  sVar1 = *(short *)(&DAT_800b1de2 + (int)o[1].pos.vz * 8);
  while ((sVar2 != 0 || (sVar1 != 0))) {
    sVar2 = Invent_GetNbObjects(o[1].pos.vy,o[1].pos.vz);
    sVar1 = *(short *)(&DAT_800b1de2 + (int)o[1].pos.vz * 8);
    Task_Next();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_BonusTestMana(struct _D3_OBJECT *o /*$s2*/)
 // line 318, offset 0x80047e24
	/* begin block 1 */
		// Start line: 319
		// Start offset: 0x80047E24
		// Variables:
	// 		long nObjects; // $s0
	// 		long mana; // $s1
	/* end block 1 */
	// End offset: 0x80047E94
	// End Line: 330

	/* begin block 2 */
		// Start line: 755
	/* end block 2 */
	// End Line: 756

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CB_BonusTestMana(_D3_OBJECT *o)

{
  ushort uVar1;
  short sVar2;
  
  sVar2 = Invent_GetNbObjects(o[1].pos.vy,o[1].pos.vz);
  uVar1 = _DAT_800b1e36;
  if (sVar2 == 0) goto LAB_80047e8c;
  do {
    do {
      sVar2 = Invent_GetNbObjects(o[1].pos.vy,o[1].pos.vz);
      uVar1 = _DAT_800b1e36;
      Task_Next();
    } while (sVar2 != 0);
LAB_80047e8c:
  } while (0x14 < uVar1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_TakeObject(struct _PLAYER *pl /*$s1*/, struct _D3_OBJECT *o /*$s0*/)
 // line 333, offset 0x80047eac
	/* begin block 1 */
		// Start line: 334
		// Start offset: 0x80047EAC
		// Variables:
	// 		long value; // $a1
	/* end block 1 */
	// End offset: 0x80047FC0
	// End Line: 382

	/* begin block 2 */
		// Start line: 785
	/* end block 2 */
	// End Line: 786

void CB_TakeObject(_PLAYER *pl,_D3_OBJECT *o)

{
  short sVar1;
  
  sVar1 = o[1].pos.vy;
  if (sVar1 == 0xf) {
    Fx_Play(0x3b,(char)o + ',');
    *(short *)((pl->env2).Obj.primitive_top.Data + 8) =
         *(short *)((pl->env2).Obj.primitive_top.Data + 8) + 1;
    CB_TakeObjectDelete(o);
    Stats_LifeAppear();
    return;
  }
  if (sVar1 < 0x10) {
    if (6 < sVar1) {
      sVar1 = Invent_AddObject(pl,o);
      if (sVar1 == 0) {
        return;
      }
      Scts_Interruptors = Scts_Interruptors | 1 << ((int)o[1].pos.vy + 9U & 0x1f);
      goto LAB_80047fb8;
    }
  }
  else {
    if (sVar1 == 0x15) {
      sVar1 = Invent_AddObject(pl,o);
      if (sVar1 == 0) {
        return;
      }
      Scts_Interruptors = Scts_Interruptors | (int)o[1].pos.vz << 0x10;
      goto LAB_80047fb8;
    }
  }
  sVar1 = Invent_AddObject(pl,o);
  if (sVar1 == 0) {
    return;
  }
LAB_80047fb8:
  CB_TakeObjectDelete(o);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_TakeObjectDelete(struct _D3_OBJECT *o /*$s0*/)
 // line 384, offset 0x80047fd4
	/* begin block 1 */
		// Start line: 385
		// Start offset: 0x80047FD4
		// Variables:
	// 		char str[80]; // stack offset -168
	// 		char name[80]; // stack offset -88
	// 		long death_duration; // $a2
	/* end block 1 */
	// End offset: 0x8004801C
	// End Line: 403

	/* begin block 2 */
		// Start line: 890
	/* end block 2 */
	// End Line: 891

void CB_TakeObjectDelete(_D3_OBJECT *o)

{
  long lVar1;
  uint param;
  char acStack168 [80];
  char acStack88 [80];
  
  param = 0;
  if (*(undefined **)&o[1].last_pos != &DAT_00001234) {
    param = (uint)*(undefined **)&o[1].last_pos & 0xffff;
  }
  if (param == 0) {
    D3_DeleteObject(o);
  }
  else {
    Task_EventExec(o->handle,-0x4000,param);
  }
  lVar1 = Invent_D3GetName(o,(_TAKEN_OBJECT *)0x0,acStack88);
  sprintf(acStack168,s__s__s_800ad688,acStack88,CB_StringPickedUp + lVar1 * 0x1e);
  Overlay_SetText(acStack168);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_TranslationTask()
 // line 421, offset 0x80048074
	/* begin block 1 */
		// Start line: 422
		// Start offset: 0x80048074
		// Variables:
	// 		struct _D3_OBJECT *o; // $s0
	// 		long dist; // $a2
	// 		long BeginPos; // stack offset -40
	// 		long EndPos; // stack offset -36
	// 		long nb_frames; // $s1
	// 		long event; // $v1
	// 		short Interruptor; // $s2
	// 		short Loop; // $s5
	// 		short cpt_loop; // $s1
	// 		long ZoneAttached; // $s6
	// 		struct CBASE_6fake step; // stack offset -72

		/* begin block 1.1 */
			// Start line: 542
			// Start offset: 0x80048354
			// Variables:
		// 		struct CBASE_6fake bstep; // stack offset -56
		/* end block 1.1 */
		// End offset: 0x80048400
		// End Line: 564
	/* end block 1 */
	// End offset: 0x80048614
	// End Line: 654

	/* begin block 2 */
		// Start line: 965
	/* end block 2 */
	// End Line: 966

/* WARNING: Unknown calling convention yet parameter storage is locked */

void CB_TranslationTask(void)

{
  short sVar1;
  short snd_handle;
  ushort uVar2;
  long lVar3;
  long lVar4;
  int nbframes;
  undefined4 uVar5;
  _D3_OBJECT *obj;
  uint uVar6;
  int iVar7;
  int local_48;
  int local_44;
  int local_40;
  int local_38;
  int local_34;
  int local_30;
  int local_28;
  int local_24;
  
  obj = (_D3_OBJECT *)TaskCurrent->local;
  local_24 = 0;
  snd_handle = obj[1].last_pos.vy;
  uVar2 = obj[1].last_pos.vx;
  lVar3 = Zone_IsZoneAttached(obj);
  memset(&local_48,0,0x10);
  TaskCurrent->destructor = CB_TranslateDestructor;
  nbframes = (int)obj[1].pos.pad;
  if (nbframes == 0) {
    nbframes = 1;
  }
  else {
    nbframes = nbframes * 0xf >> 7;
  }
  if (obj[1].pos.vy < 6) {
    sVar1 = obj[1].pos.vz;
    (obj->pos).pad = 0;
    local_24 = (int)sVar1 * 100;
    iVar7 = local_24 / nbframes;
    if (nbframes == 0) {
      trap(0x1c00);
    }
    if ((nbframes == -1) && (local_24 == -0x80000000)) {
      trap(0x1800);
    }
    local_24 = local_24 >> 8;
  }
  else {
    iVar7 = ((int)obj[1].pos.vz * 0x1000) / 0x168 >> 8;
    local_24 = iVar7 * nbframes;
  }
  switch(obj[1].pos.vy) {
  case 0:
    local_28 = (int)(obj->pos).vx;
    local_48 = iVar7;
    break;
  case 1:
    local_48 = -iVar7;
    local_28 = (int)(obj->pos).vx;
    goto LAB_800482ac;
  case 2:
    local_28 = (int)(obj->pos).vy;
    local_44 = iVar7;
    break;
  case 3:
    local_44 = -iVar7;
    local_28 = (int)(obj->pos).vy;
    goto LAB_800482ac;
  case 4:
    local_28 = (int)(obj->pos).vz;
    local_40 = iVar7;
    break;
  case 5:
    local_40 = -iVar7;
    local_28 = (int)(obj->pos).vz;
    goto LAB_800482ac;
  case 6:
    local_28 = (int)(obj->rot).vx;
    local_48 = iVar7;
    break;
  case 7:
    local_48 = -iVar7;
    local_28 = (int)(obj->rot).vx;
    goto LAB_800482ac;
  case 8:
    local_28 = (int)(obj->rot).vy;
    local_44 = iVar7;
    break;
  case 9:
    local_44 = -iVar7;
    local_28 = (int)(obj->rot).vy;
    goto LAB_800482ac;
  case 10:
    local_28 = (int)(obj->rot).vz;
    local_40 = iVar7;
    break;
  case 0xb:
    local_40 = -iVar7;
    local_28 = (int)(obj->rot).vz;
LAB_800482ac:
    local_24 = local_28 - local_24;
    goto switchD_800481c4_caseD_e;
  case 0xc:
    sVar1 = (obj->rot).vx;
    local_48 = iVar7;
    goto LAB_800482e8;
  case 0xd:
    sVar1 = (obj->rot).vy;
    local_44 = iVar7;
LAB_800482e8:
    local_28 = (int)sVar1;
    local_24 = local_24 + local_28;
    CB_PontLevis(obj,0xb8,local_28,local_24,nbframes);
  default:
    goto switchD_800481c4_caseD_e;
  }
  local_24 = local_24 + local_28;
switchD_800481c4_caseD_e:
  if (((int)snd_handle != 0) && (lVar4 = Test_Interruptors((int)snd_handle), lVar4 != 0)) {
    Pvl_SetStateBits(obj,1);
  }
  if ((Pvl_SctState[(int)obj->index] & 1U) != 0) {
    local_38 = local_48 * nbframes;
    local_34 = local_44 * nbframes;
    local_30 = local_40 * nbframes;
    if (obj[1].pos.vy < 6) {
      CB_TranslateObjects(obj,200);
      uVar5 = *(undefined4 *)&(obj->pos).vz;
      *(undefined4 *)&obj->last_pos = *(undefined4 *)&obj->pos;
      *(undefined4 *)&(obj->last_pos).vz = uVar5;
    }
    else {
      if (obj[1].pos.pad == 0) goto LAB_80048400;
      CB_RotateObjects(obj,200,1);
    }
    CB_InvertTransRot(obj,&local_28,&local_24,0xb8);
  }
LAB_80048400:
  *(undefined2 *)((int)&obj[1].prec + 2) = 0xffff;
  nbframes = (int)snd_handle;
  do {
    if (nbframes != 0) {
      if ((Pvl_SctState[(int)obj->index] & 1U) == 0) {
        while (lVar4 = Test_Interruptors(nbframes), lVar4 == 0) {
          Task_Next();
        }
        if (uVar2 != 0xffff) {
          Pvl_SetStateBits(obj,1);
        }
      }
      else {
        while ((lVar4 = Test_Interruptors(nbframes), lVar4 != 0 && (uVar2 != 0xffff))) {
          Task_Next();
        }
        Pvl_ClearStateBits(obj,1);
      }
    }
    lVar4 = 1;
    if (lVar3 != 0) {
      lVar4 = Task_EventRead(TaskCurrent);
    }
    if (lVar4 == 1) {
      TaskCurrent->event_enable = 0;
      uVar6 = (uint)uVar2;
      if (uVar2 == 0) {
        while (lVar3 = CB_EndTransRot(obj,local_24), lVar3 == 0) {
          if (obj[1].pos.vy < 6) {
            CB_TranslateObjects(obj,0xb8);
          }
          else {
            CB_RotateObjects(obj,0xb8,1);
          }
          Task_Next();
        }
        Pvl_SetStateBits(obj,1);
        return;
      }
      do {
        while (lVar4 = CB_EndTransRot(obj,local_24), lVar4 == 0) {
          if (obj[1].pos.vy < 6) {
            CB_TranslateObjects(obj,0xb8);
          }
          else {
            CB_RotateObjects(obj,0xb8,1);
          }
          Task_Next();
        }
        (obj->pos).pad = 1;
        CB_InvertTransRot(obj,&local_28,&local_24,0xb8);
        iVar7 = uVar6 << 0x10;
        if (0 < iVar7) {
          uVar6 = uVar6 - 1;
          iVar7 = uVar6 * 0x10000;
        }
      } while (iVar7 != 0);
    }
    snd_handle = *(short *)((int)&obj[1].prec + 2);
    if (-1 < snd_handle) {
      D3_StopSound(obj,snd_handle);
      *(undefined2 *)((int)&obj[1].prec + 2) = 0xffff;
    }
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_TranslateDestructor(struct TASK *handle /*$a0*/)
 // line 657, offset 0x8004863c
	/* begin block 1 */
		// Start line: 658
		// Start offset: 0x8004863C
		// Variables:
	// 		struct _D3_OBJECT *o; // $a0
	/* end block 1 */
	// End offset: 0x8004863C
	// End Line: 658

	/* begin block 2 */
		// Start line: 1537
	/* end block 2 */
	// End Line: 1538

void CB_TranslateDestructor(TASK *handle)

{
  short snd_handle;
  _D3_OBJECT *o;
  
  o = (_D3_OBJECT *)handle->local;
  snd_handle = *(short *)((int)&o[1].prec + 2);
  *(undefined *)((int)&o[1].pos.vx + 1) = 0;
  o->handle = (TASK *)0x0;
  D3_StopSound(o,snd_handle);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Test_Interruptors(long mask /*$a0*/)
 // line 669, offset 0x8004866c
	/* begin block 1 */
		// Start line: 1565
	/* end block 1 */
	// End Line: 1566

long Test_Interruptors(long mask)

{
  return (uint)((~Scts_Interruptors & mask) == 0);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_TranslateObjects(struct _D3_OBJECT *o /*$s0*/, struct CBASE_6fake *trans /*$s1*/)
 // line 675, offset 0x80048688
	/* begin block 1 */
		// Start line: 676
		// Start offset: 0x80048688
		// Variables:
	// 		struct CBASE_7fake strans; // stack offset -24
	/* end block 1 */
	// End offset: 0x800486CC
	// End Line: 684

	/* begin block 2 */
		// Start line: 1576
	/* end block 2 */
	// End Line: 1577

void CB_TranslateObjects(_D3_OBJECT *o,undefined trans)

{
  short snd_handle;
  undefined4 uVar1;
  undefined4 uVar2;
  _D3_OBJECT *obj;
  undefined3 in_register_00000015;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)CONCAT31(in_register_00000015,trans);
  if ((-1 < *(short *)((int)&o[1].father + 2)) &&
     (snd_handle = *(short *)((int)&o[1].prec + 2), -2 < snd_handle)) {
    snd_handle = D3_UpdateSound(o,0,snd_handle);
    *(short *)((int)&o[1].prec + 2) = snd_handle;
  }
  uVar1 = puVar3[1];
  uVar2 = puVar3[2];
  (o->pos).vx = (o->pos).vx + (short)((uint)*puVar3 >> 8);
  (o->pos).vy = (o->pos).vy + (short)((uint)uVar1 >> 8);
  obj = o->child;
  (o->pos).vz = (o->pos).vz + (short)((uint)uVar2 >> 8);
  D3_MoveList(obj,0xe8);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_RotateObjects(struct _D3_OBJECT *o /*$s0*/, struct CBASE_6fake *rot /*$s1*/, long RotList /*$s2*/)
 // line 696, offset 0x8004874c
	/* begin block 1 */
		// Start line: 697
		// Start offset: 0x8004874C
		// Variables:
	// 		struct CBASE_7fake srot; // stack offset -24
	/* end block 1 */
	// End offset: 0x800487F4
	// End Line: 715

	/* begin block 2 */
		// Start line: 1623
	/* end block 2 */
	// End Line: 1624

void CB_RotateObjects(_D3_OBJECT *o,undefined rot,long RotList)

{
  short sVar1;
  short sVar2;
  undefined3 in_register_00000015;
  short *psVar3;
  
  psVar3 = (short *)CONCAT31(in_register_00000015,rot);
  if (-1 < *(short *)((int)&o[1].father + 2)) {
    sVar2 = D3_UpdateSound(o,0,*(short *)((int)&o[1].prec + 2));
    *(short *)((int)&o[1].prec + 2) = sVar2;
  }
  sVar2 = psVar3[2];
  sVar1 = psVar3[4];
  (o->rot).vx = (o->rot).vx + *psVar3;
  (o->rot).vy = (o->rot).vy + sVar2;
  (o->rot).vz = (o->rot).vz + sVar1;
  if (RotList != 0) {
    D3_RotList(o->child,0xe8);
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ CB_EndTransRot(struct _D3_OBJECT *o /*$a0*/, long pos /*$a1*/)
 // line 718, offset 0x8004880c
	/* begin block 1 */
		// Start line: 1669
	/* end block 1 */
	// End Line: 1670

long CB_EndTransRot(_D3_OBJECT *o,long pos)

{
  ushort uVar1;
  bool bVar2;
  short sVar3;
  
  if (('\x05' < *(char *)((int)&o[1].pos.vx + 1)) && (o[1].pos.pad < 1)) {
    return 0;
  }
  uVar1 = o[1].pos.vy;
  if (0xb < uVar1) {
    return 0;
  }
  sVar3 = (short)pos;
  switch(uVar1) {
  case 0:
    bVar2 = (int)(o->pos).vx < pos;
    break;
  case 1:
    bVar2 = pos < (int)(o->pos).vx;
    break;
  case 2:
    bVar2 = (int)(o->pos).vy < pos;
    goto LAB_80048894;
  case 3:
    bVar2 = pos < (int)(o->pos).vy;
LAB_80048894:
    if (bVar2) {
      return 0;
    }
    (o->pos).vy = sVar3;
    return 1;
  case 4:
    bVar2 = (int)(o->pos).vz < pos;
    goto LAB_800488bc;
  case 5:
    bVar2 = pos < (int)(o->pos).vz;
LAB_800488bc:
    if (bVar2) {
      return 0;
    }
    (o->pos).vz = sVar3;
    return 1;
  case 6:
    bVar2 = (int)(o->rot).vx < pos;
    goto LAB_800488e4;
  case 7:
    bVar2 = pos < (int)(o->rot).vx;
LAB_800488e4:
    if (bVar2) {
      return 0;
    }
    (o->rot).vx = sVar3;
    return 1;
  case 8:
    bVar2 = (int)(o->rot).vy < pos;
    goto LAB_8004890c;
  case 9:
    bVar2 = pos < (int)(o->rot).vy;
LAB_8004890c:
    if (bVar2) {
      return 0;
    }
    (o->rot).vy = sVar3;
    return 1;
  case 10:
    bVar2 = (int)(o->rot).vz < pos;
    goto LAB_80048934;
  case 0xb:
    bVar2 = pos < (int)(o->rot).vz;
LAB_80048934:
    if (bVar2) {
      return 0;
    }
    (o->rot).vz = sVar3;
    return 1;
  }
  if (bVar2) {
    return 0;
  }
  (o->pos).vx = sVar3;
  return 1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_InvertTransRot(struct _D3_OBJECT *o /*$a0*/, long *BeginPos /*$a1*/, long *EndPos /*$a2*/, struct CBASE_6fake *step /*$a3*/)
 // line 756, offset 0x80048960
	/* begin block 1 */
		// Start line: 758
		// Start offset: 0x80048960
		// Variables:
	// 		long dummy; // $v1
	/* end block 1 */
	// End offset: 0x80048990
	// End Line: 770

	/* begin block 2 */
		// Start line: 1747
	/* end block 2 */
	// End Line: 1748

void CB_InvertTransRot(_D3_OBJECT *o,long *BeginPos,long *EndPos,undefined step)

{
  ushort uVar1;
  short sVar2;
  long lVar3;
  undefined3 in_register_0000001d;
  int *piVar4;
  
  piVar4 = (int *)CONCAT31(in_register_0000001d,step);
  if (o[1].pos.vy < 0xc) {
    uVar1 = o[1].pos.vy;
    sVar2 = -1;
    if ((uVar1 & 1) == 0) {
      sVar2 = 1;
    }
    o[1].pos.vy = uVar1 + sVar2;
  }
  lVar3 = *BeginPos;
  *BeginPos = *EndPos;
  *EndPos = lVar3;
  *piVar4 = -*piVar4;
  piVar4[2] = -piVar4[2];
  piVar4[1] = -piVar4[1];
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_PontLevis(struct _D3_OBJECT *D3Obj /*$s2*/, struct CBASE_6fake *step /*$s3*/, long Begin /*stack 8*/, long End /*stack 12*/, long nbframes /*stack 16*/)
 // line 779, offset 0x800489c8
	/* begin block 1 */
		// Start line: 780
		// Start offset: 0x800489C8
		// Variables:
	// 		long Zone_Result; // $s1
	// 		long WaitTime; // $fp
	// 		long EndTurn; // $s0
	// 		long Open; // $s4
	// 		long Closed; // $s5
	// 		struct CBASE_7fake min; // stack offset -72
	// 		struct CBASE_7fake max; // stack offset -64
	// 		struct _D3_OBJECT *weight; // $s6

		/* begin block 1.1 */
			// Start line: 795
			// Start offset: 0x80048A74
			// Variables:
		// 		struct CBASE_6fake bstep; // stack offset -56
		/* end block 1.1 */
		// End offset: 0x80048B18
		// End Line: 815
	/* end block 1 */
	// End offset: 0x80048D78
	// End Line: 913

	/* begin block 2 */
		// Start line: 1793
	/* end block 2 */
	// End Line: 1794

void CB_PontLevis(_D3_OBJECT *D3Obj,undefined1 step,long Begin,long End,long nbframes)

{
  bool bVar1;
  short sVar2;
  short snd_handle;
  long lVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  _D3_OBJECT *p_Var8;
  long lVar9;
  _D3_OBJECT *p_Var10;
  uint uVar11;
  int iVar12;
  int iVar13;
  long local_res8;
  long local_resc;
  short local_48;
  short sStack70;
  short local_44;
  short local_40;
  short sStack62;
  short local_3c;
  
  uVar11 = 0;
  iVar12 = 0;
  iVar13 = 1;
  uVar7 = *(undefined4 *)&D3Obj->comp_opt2;
  lVar9 = D3Obj->comp_opt4;
  p_Var8 = D3Obj[1].child;
  p_Var10 = D3Obj[1].father;
  sVar2 = D3Obj[1].last_pos.vy;
  local_res8 = Begin;
  local_resc = End;
  lVar3 = Pvl_TestStateBits(D3Obj,0x12);
  if (lVar3 != 0) {
    CB_RotateObjects(D3Obj,200,0);
    CB_PontLevisChangeBBox(D3Obj);
    lVar3 = Pvl_TestStateBits(D3Obj,2);
    if (lVar3 != 0) {
      do {
        Task_Next();
      } while( true );
    }
    CB_InvertTransRot(D3Obj,&local_res8,&local_resc,step);
    iVar12 = 1;
    iVar13 = 0;
    uVar11 = CB_PontLevisTestZones(D3Obj,(_D3_OBJECT *)0x0);
  }
LAB_80048b30:
  do {
    uVar4 = uVar11 & 5;
    do {
      do {
        if (uVar4 == 0) {
          uVar11 = CB_PontLevisTestZones(D3Obj,(_D3_OBJECT *)0x0);
          Task_Next();
          goto LAB_80048b30;
        }
        uVar5 = uVar11 & 4;
        if ((uVar11 & 1) != 0) {
          if (iVar13 == 0) {
            CB_InvertTransRot(D3Obj,&local_res8,&local_resc,step);
          }
          iVar13 = 0;
          do {
            uVar11 = CB_PontLevisTestZones(D3Obj,(_D3_OBJECT *)0x0);
            CB_RotateObjects(D3Obj,step,0);
            lVar3 = CB_PontLevisTestEnd(D3Obj,step,local_res8,local_resc);
            Task_Next();
            if ((uVar11 & 4) != 0) break;
          } while (lVar3 == 0);
          uVar5 = uVar11 & 4;
          iVar12 = iVar13;
          if (lVar3 != 0) {
            iVar12 = 1;
            CB_PontLevisChangeBBox(D3Obj);
            snd_handle = *(short *)((int)&D3Obj[1].prec + 2);
            uVar11 = 0;
            if (-1 < snd_handle) {
              D3_StopSound(D3Obj,snd_handle);
              *(undefined2 *)((int)&D3Obj[1].prec + 2) = 0xffff;
            }
            uVar5 = 0;
          }
        }
        uVar4 = uVar11 & 5;
      } while (uVar5 == 0);
      if (iVar12 != 0) {
        TaskCurrent->event_enable = 0;
        Task_Sleep((int)sVar2 * 0x1e);
        D3Obj->collision_state = D3Obj->collision_state | 0x10;
        bVar1 = true;
        while (bVar1) {
          do {
            D3Obj->collision_state = D3Obj->collision_state & 0xffef;
            Task_Next();
          } while ((D3Obj->collision_state & 0x10U) != 0);
          Task_Sleep(0x1e);
          bVar1 = (D3Obj->collision_state & 0x10U) != 0;
        }
        TaskCurrent->event_enable = 1;
      }
      CB_InvertTransRot(D3Obj,&local_res8,&local_resc,step);
      local_48 = (short)uVar7;
      sStack70 = (short)((uint)uVar7 >> 0x10);
      local_44 = (short)lVar9;
      local_40 = (short)p_Var8;
      iVar12 = 0;
      sStack62 = (short)((uint)p_Var8 >> 0x10);
      local_3c = (short)p_Var10;
      D3_SetBox(D3Obj,(int)local_48,(int)sStack70,(int)local_44,(int)local_40,(int)sStack62,
                (int)local_3c);
      iVar6 = iVar12;
      while (uVar11 = Task_EventRead(TaskCurrent), (uVar11 & 1) == 0) {
        if (iVar6 != 0) goto LAB_80048d3c;
        CB_RotateObjects(D3Obj,step,0);
        iVar6 = CB_PontLevisTestEnd(D3Obj,step,local_res8,local_resc);
        Task_Next();
      }
      uVar4 = uVar11 & 5;
    } while (iVar6 == 0);
LAB_80048d3c:
    iVar13 = 1;
    CB_InvertTransRot(D3Obj,&local_res8,&local_resc,step);
    snd_handle = *(short *)((int)&D3Obj[1].prec + 2);
    uVar11 = 0;
    if (-1 < snd_handle) {
      D3_StopSound(D3Obj,snd_handle);
      *(undefined2 *)((int)&D3Obj[1].prec + 2) = 0xffff;
      iVar12 = 0;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// long /*$ra*/ CB_PontLevisTestEnd(struct _D3_OBJECT *o /*$a0*/, struct CBASE_6fake *step /*$a1*/, long begin /*$a2*/, long end /*$a3*/)
 // line 916, offset 0x80048d78
	/* begin block 1 */
		// Start line: 918
		// Start offset: 0x80048D78
		// Variables:
	// 		long sens; // $a1
	// 		long curpos; // $a0
	/* end block 1 */
	// End offset: 0x80048DC0
	// End Line: 945

	/* begin block 2 */
		// Start line: 2099
	/* end block 2 */
	// End Line: 2100

long CB_PontLevisTestEnd(_D3_OBJECT *o,undefined step,long begin,long end)

{
  short sVar1;
  bool bVar2;
  int iVar3;
  undefined3 in_register_00000015;
  int iVar4;
  
  if (o[1].pos.vy == 0xc) {
    iVar4 = *(int *)CONCAT31(in_register_00000015,step);
    sVar1 = (o->rot).vx;
  }
  else {
    iVar4 = ((int *)CONCAT31(in_register_00000015,step))[1];
    sVar1 = (o->rot).vy;
  }
  iVar3 = (int)sVar1;
  if (end < begin) {
    bVar2 = iVar3 < end;
    if (-1 < iVar4) {
      return (uint)(begin < iVar3);
    }
  }
  else {
    bVar2 = end < iVar3;
    if (iVar4 < 0) {
      return (uint)(iVar3 < begin);
    }
  }
  return (uint)bVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_PontLevisChangeBBox(struct _D3_OBJECT *o /*$s1*/)
 // line 947, offset 0x80048dd0
	/* begin block 1 */
		// Start line: 948
		// Start offset: 0x80048DD0
		// Variables:
	// 		struct CBASE_5fake mr; // stack offset -96
	// 		struct CBASE_7fake min; // stack offset -64
	// 		struct CBASE_7fake max; // stack offset -56
	// 		struct CBASE_7fake angle; // stack offset -48
	// 		struct CBASE_6fake dummy; // stack offset -40
	// 		long f; // stack offset -24
	// 		long i; // $a3
	/* end block 1 */
	// End offset: 0x80048FD0
	// End Line: 983

	/* begin block 2 */
		// Start line: 2158
	/* end block 2 */
	// End Line: 2159

/* WARNING: Could not reconcile some variable overlaps */

void CB_PontLevisChangeBBox(_D3_OBJECT *o)

{
  undefined4 in_zero;
  undefined4 in_at;
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  short local_40;
  short local_3e;
  short local_3c;
  short local_38;
  short local_36;
  short local_34;
  uint local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  int local_20;
  undefined4 local_18;
  
  memset(&local_30,0,8);
  setCopReg(2,in_zero,local_30);
  setCopReg(2,in_at,local_2c);
  copFunction(2,0x486012);
  local_4c = getCopReg(2,0x19);
  local_48 = getCopReg(2,0x1a);
  local_44 = getCopReg(2,0x1b);
  if (o[1].pos.vy == 0xc) {
    local_30 = local_30 & 0xffff0000 | (uint)(ushort)(o->rot).vx;
  }
  else {
    local_30 = local_30 & 0xffff | (uint)(ushort)(o->rot).vy << 0x10;
  }
  RotMatrix((short *)&local_30,(undefined2 *)&local_60);
  setCopControlWord(2,0x2800,local_4c);
  setCopControlWord(2,0x3000,local_48);
  setCopControlWord(2,0x3800,local_44);
  setCopControlWord(2,0,local_60);
  setCopControlWord(2,0x800,local_5c);
  setCopControlWord(2,0x1000,local_58);
  setCopControlWord(2,0x1800,local_54);
  setCopControlWord(2,0x2000,local_50);
  iVar3 = 0;
  iVar2 = 0x4c;
  local_3c = 15000;
  local_3e = 15000;
  local_40 = 15000;
  local_34 = -15000;
  local_36 = -15000;
  local_38 = -15000;
  do {
    puVar1 = (undefined4 *)((int)&o->next + iVar2);
    setCopReg(2,in_zero,*puVar1);
    setCopReg(2,in_at,puVar1[1]);
    copFunction(2,0x480012);
    local_28 = getCopReg(2,0x19);
    local_24 = getCopReg(2,0x1a);
    local_20 = getCopReg(2,0x1b);
    local_18 = getCopControlWord(2,0xf800);
    if (local_28 < (int)local_40) {
      local_40 = (short)local_28;
    }
    if (local_24 < (int)local_3e) {
      local_3e = (short)local_24;
    }
    if (local_20 < (int)local_3c) {
      local_3c = (short)local_20;
    }
    if ((int)local_38 < local_28) {
      local_38 = (short)local_28;
    }
    if ((int)local_36 < local_24) {
      local_36 = (short)local_24;
    }
    if ((int)local_34 < local_20) {
      local_34 = (short)local_20;
    }
    iVar3 = iVar3 + 1;
    iVar2 = iVar2 + 8;
  } while (iVar3 < 8);
  D3_SetBox(o,(int)local_40,(int)local_3e,(int)local_3c,(int)local_38,(int)local_36,(int)local_34);
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
// long /*$ra*/ CB_PontLevisTestZones(struct _D3_OBJECT *D3Obj /*$s4*/, struct _D3_OBJECT *weight /*$s1*/)
 // line 991, offset 0x8004905c
	/* begin block 1 */
		// Start line: 992
		// Start offset: 0x8004905C
		// Variables:
	// 		struct _ZONE *z; // $s0
	// 		struct _ZONE *zPlayer; // $s3
	// 		struct _ZONE *zObject; // $s2
	// 		struct _D3_OBJECT *child; // $s6
	// 		long ZoneEvent; // $s5
	/* end block 1 */
	// End offset: 0x80049198
	// End Line: 1043

	/* begin block 2 */
		// Start line: 2261
	/* end block 2 */
	// End Line: 2262

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long CB_PontLevisTestZones(_D3_OBJECT *D3Obj,_D3_OBJECT *weight)

{
  short sVar1;
  uint uVar2;
  _D3_OBJECT *p_Var3;
  _ZONE *z;
  _ZONE *p_Var4;
  _ZONE *p_Var5;
  _D3_OBJECT *p_Var6;
  
  p_Var6 = D3Obj->child;
  p_Var4 = (_ZONE *)0x0;
  uVar2 = Task_EventRead(TaskCurrent);
  p_Var5 = (_ZONE *)0x0;
  if ((uVar2 & 3) != 0) {
    p_Var5 = _DAT_800b1cd8;
  }
  p_Var3 = Invent_GetDroppedD3(0x16);
  z = Zone_GetObjectZone(D3Obj);
  while ((z != (_ZONE *)0x0 && (p_Var3 != (_D3_OBJECT *)0x0))) {
    sVar1 = Zone_IsPosInZone(z,100);
    if (sVar1 != 0) {
      p_Var5 = z;
    }
    sVar1 = Zone_IsPosInZone(z,(char)p_Var3 + ',');
    if (sVar1 != 0) {
      uVar2 = 0;
      p_Var4 = z;
    }
    z = Zone_GetObjectNext(D3Obj);
  }
  if (p_Var4 == (_ZONE *)0x0) {
    Pvl_ClearStateBits(D3Obj,0x10);
  }
  else {
    Pvl_SetStateBits(D3Obj,0x10);
  }
  if ((((p_Var6 != (_D3_OBJECT *)0x0) && (p_Var4 != (_ZONE *)0x0)) && (p_Var5 != (_ZONE *)0x0)) &&
     ((p_Var4 != p_Var5 && (*(char *)((int)&p_Var6[1].pos.vx + 1) == '\b')))) {
    Pvl_SetStateBits(D3Obj,2);
    do {
      Task_Next();
    } while( true );
  }
  return uVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_InterruptorTask()
 // line 1078, offset 0x800491c4
	/* begin block 1 */
		// Start line: 1079
		// Start offset: 0x800491C4
		// Variables:
	// 		struct _D3_OBJECT *o; // $s0
	// 		struct _D3_OBJECT *oc; // $v1
	// 		struct _D3_OBJECT *user; // $a1
	// 		struct M_OBJECT *mo; // $s1
	// 		struct _ZONE *z; // $v1
	// 		long Event; // $v1
	// 		long oldhp; // $s3
	/* end block 1 */
	// End offset: 0x80049638
	// End Line: 1256

	/* begin block 2 */
		// Start line: 2442
	/* end block 2 */
	// End Line: 2443

/* WARNING: Unknown calling convention yet parameter storage is locked */

void CB_InterruptorTask(void)

{
  short sVar1;
  short sVar2;
  long lVar3;
  _ZONE *p_Var4;
  void *pvVar5;
  _D3_OBJECT *user;
  _D3_OBJECT *o;
  M_OBJECT *obj;
  
  o = (_D3_OBJECT *)TaskCurrent->local;
  obj = (M_OBJECT *)o->description;
  sVar1 = o->hit_points;
  Pvl_ClearStateBits(o,1);
  sVar2 = o[1].pos.vy;
  if (sVar2 == 9) {
    CB_DalleRadio(o);
LAB_80049348:
    CB_DalleInt(o);
  }
  else {
    if (sVar2 < 10) {
      if (sVar2 == 8) {
        if ((Scts_Interruptors & (int)o[1].pos.vz) != 0) {
          Pvl_ClearStateBits(o,2);
          sVar1 = o[1].pos.pad;
          o[1].pos.pad = 0;
          sVar1 = (o->pos).vz + sVar1 * -10;
          (o->last_pos).vz = sVar1;
          (o->pos).vz = sVar1;
        }
        while (o[1].pos.pad != 0) {
          if (((o->collision_state & 2U) != 0) &&
             (pvVar5 = o[1].description, o->collision_state = o->collision_state & 0xfffd,
             -7 < *(char *)((int)pvVar5 + 0x99))) {
            sVar1 = o[1].pos.pad;
            sVar2 = (o->pos).vz + -0x14;
            o[1].pos.pad = sVar1 + -1;
            (o->last_pos).vz = sVar2;
            (o->pos).vz = sVar2;
            D3_PlaySound(o,(ushort)(sVar1 == 1));
          }
          Task_Next();
        }
        Scts_Interruptors = Scts_Interruptors | (int)o[1].pos.vz;
        Pvl_SetStateBits(o,2);
        o->handle = (TASK *)0x0;
        return;
      }
      goto LAB_8004935c;
    }
    if (sVar2 == 10) goto LAB_80049348;
    if (sVar2 != 0xb) goto LAB_8004935c;
  }
  CB_DalleWeight(o);
LAB_8004935c:
  lVar3 = Pvl_TestStateBits(o,8);
  if (lVar3 != 0) {
    o->display_mode = o->display_mode | 0x10;
    D3_SetCollBits(o,1);
  }
  lVar3 = Pvl_TestStateBits(o,2);
  if (lVar3 == 0) {
    if ((o->display_mode & 0x40U) != 0) {
      (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
    }
    D3_StopMotion(o->child);
    user = o->child;
    while (user != (_D3_OBJECT *)0x0) {
      if (*(char *)((int)&user[1].pos.vx + 1) == '\0') {
        sVar2 = *(short *)((int)&user->b_hurt + 2);
        *(undefined2 *)((int)&user->b_hurt + 2) = 0;
        user[1].pos.pad = sVar2;
      }
      user = user->next;
    }
  }
  else {
    if ((o[1].pos.pad & 1U) == 0) {
      p_Var4 = Zone_GetObjectZone(o);
      if (p_Var4 != (_ZONE *)0x0) {
        p_Var4->camera = -1;
      }
      Zone_DeleteObject(o);
    }
    D3_RunMotion(o->child);
    if ((o->display_mode & 0x40U) != 0) {
      Manim_GoToFrame(obj,(uint)*(ushort *)
                                 (*(int *)(*(int *)((obj->Sq).Data.FatherTrans + 2) + 8) + 6) - 1);
    }
    if ((o[1].pos.pad & 1U) == 0) {
      o->handle = (TASK *)0x0;
      return;
    }
  }
  if ((o->display_mode & 0x10U) == 0) {
    Pvl_SetStateBits(o,1);
    while (lVar3 = Task_EventRead(TaskCurrent), lVar3 != 6) {
      Task_Next();
    }
    o->display_mode = o->display_mode | 0x10;
    D3_SetCollBits(o,1);
    Pvl_ClearStateBits(o,1);
    Pvl_SetStateBits(o,8);
  }
  do {
    lVar3 = Task_EventRead(TaskCurrent);
    sVar2 = o[1].pos.vy;
    user = (_D3_OBJECT *)TaskCurrent->event_param;
    if ((sVar2 == 2) && (lVar3 == 5)) {
      o->display_mode = o->display_mode & 0xffef;
      o->child->display_mode = o->child->display_mode | 0x10;
      CB_InterruptorSwitchONOFF(o,user);
      o->handle = (TASK *)0x0;
      return;
    }
    if (sVar2 == 0) {
      if (lVar3 == 1) {
LAB_800495a0:
        CB_InterruptorSwitchONOFF(o,user);
        if ((*(uint *)&o[1].pos.vz & 0x650000) == 0) {
          o->handle = (TASK *)0x0;
          return;
        }
      }
    }
    else {
      if (sVar2 < 6) {
        if (lVar3 == 5) goto LAB_800495a0;
      }
      else {
        if (((((ushort)(o[1].pos.vy - 6U) < 2) && ((o->collision_state & 2U) != 0)) && (sVar1 != 0))
           && (o->hit_points == 0)) {
          if (sVar2 == 7) {
            CB_InterruptorSwitchONOFF(o,(_D3_OBJECT *)o[1].description);
          }
          D3_ExplodeObject(o);
          return;
        }
      }
    }
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_DalleInt(struct _D3_OBJECT *o /*$s0*/)
 // line 1259, offset 0x80049654
	/* begin block 1 */
		// Start line: 1260
		// Start offset: 0x80049654
		// Variables:
	// 		struct _D3_OBJECT *oc; // $s1
	// 		long i; // $s1
	// 		long time; // $s2
	/* end block 1 */
	// End offset: 0x800499CC
	// End Line: 1379

	/* begin block 2 */
		// Start line: 2920
	/* end block 2 */
	// End Line: 2921

/* WARNING: Type propagation algorithm not settling */

void CB_DalleInt(_D3_OBJECT *o)

{
  ushort uVar1;
  long lVar2;
  short sVar3;
  int iVar4;
  _PLAYER *pl;
  int iVar5;
  
  sVar3 = o[1].pos.vz;
  iVar5 = 0;
  if (sVar3 != 2) goto LAB_800496a0;
  lVar2 = Pvl_TestStateBits(o,2);
  if (lVar2 != 0) {
    (o->pos).vz = (o->pos).vz + -0x32;
  }
  do {
    sVar3 = o[1].pos.vz;
LAB_800496a0:
    if (sVar3 == 1) {
      lVar2 = Pvl_TestStateBits(o,2);
      if (lVar2 == 0) {
        if ((o->collision_state & 0x110U) == 0x110) {
          Pvl_SetStateBits(o,2);
          Scts_Interruptors = Scts_Interruptors | (int)o[1].last_pos.vy;
          D3_PlaySound(o,0);
          iVar5 = (int)o[1].pos.pad;
          Pl_AddExperience((_PLAYER *)o[1].color,o);
        }
LAB_80049820:
        if ((o->collision_state & 0x10U) != 0) goto LAB_80049834;
      }
      else {
        if (iVar5 != 0) goto LAB_80049820;
        if ((o->collision_state & 0x10U) == 0) {
          Pvl_ClearStateBits(o,2);
          Scts_Interruptors = Scts_Interruptors & ~(int)o[1].last_pos.vy;
          D3_PlaySound(o,0);
          goto LAB_80049820;
        }
LAB_80049834:
        iVar5 = (int)o[1].pos.pad;
      }
      uVar1 = o->collision_state & 0xfeef;
LAB_800499ac:
      o->collision_state = uVar1;
    }
    else {
      if (sVar3 < 2) {
        if (sVar3 == 0) {
          lVar2 = Pvl_TestStateBits(o,2);
          if (lVar2 == 0) {
            if (((o->collision_state & 0x101U) == 0x101) &&
               ((pl = (_PLAYER *)o[1].color, ((pl->obj).collision_mode & 0x1000U) != 0 ||
                ((*(char *)((int)&(pl->m_obj).Env.Obj.normal_top.vz + 1) == '\0' &&
                 (*(short *)&(pl->m_obj).Env.Obj.n_normal == o[1].pos.pad)))))) {
              Pvl_SetStateBits(o,2);
              Scts_Interruptors = Scts_Interruptors | (int)o[1].last_pos.vy;
              iVar5 = 10;
              D3_PlaySound(o,0);
              Pl_AddExperience(pl,o);
            }
          }
          else {
            if (((((iVar5 == 0) && ((*(uint *)&o->collision_mode & 0x1010000) != 0x10000)) &&
                 ((o->collision_state & 0x100U) != 0)) &&
                ((iVar4 = o[1].color, *(char *)(iVar4 + 0x99) != '\0' ||
                 (*(short *)(iVar4 + 0x9c) != o[1].pos.pad)))) &&
               ((*(ushort *)(iVar4 + 0x1c) & 0x1000) == 0)) {
              Pvl_ClearStateBits(o,2);
              Scts_Interruptors = Scts_Interruptors & ~(int)o[1].last_pos.vy;
              o->collision_state = o->collision_state & 0xfeff;
              D3_PlaySound(o,0);
            }
          }
          uVar1 = o->collision_state & 0xfefe;
          goto LAB_800499ac;
        }
      }
      else {
        if (sVar3 == 2) {
          lVar2 = Pvl_TestStateBits(o,2);
          if ((lVar2 == 0) && ((o->collision_state & 0x110U) == 0x110)) {
            Pvl_SetStateBits(o,2);
            Scts_Interruptors = Scts_Interruptors | (int)o[1].last_pos.vy;
            iVar4 = 0;
            Pl_AddExperience((_PLAYER *)o[1].color,o);
            Task_Sleep(0x1e);
            D3_PlaySound(o,0);
            do {
              iVar4 = iVar4 + 1;
              (o->pos).vz = (o->pos).vz + -5;
              Task_Next();
            } while (iVar4 < 10);
          }
          uVar1 = o->collision_state & 0xfeef;
          goto LAB_800499ac;
        }
      }
    }
    if (iVar5 != 0) {
      iVar5 = iVar5 + -1;
    }
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_DalleRadio(struct _D3_OBJECT *o /*$s1*/)
 // line 1382, offset 0x800499cc
	/* begin block 1 */
		// Start line: 1383
		// Start offset: 0x800499CC
		// Variables:
	// 		struct _D3_OBJECT *oc; // $s0
	// 		long Event; // $s3
	// 		long pos; // $s7
	// 		long pos_depart; // stack offset -56
	// 		long max; // $s6
	// 		long offset; // $s2
	// 		long sound; // $s5
	// 		long lsound; // $s0
	// 		long father; // stack offset -52
	// 		long Fx_Handle; // stack offset -48
	// 		long color; // $fp
	// 		struct _PLATFORM *plat; // $s4
	/* end block 1 */
	// End offset: 0x80049D84
	// End Line: 1518

	/* begin block 2 */
		// Start line: 3296
	/* end block 2 */
	// End Line: 3297

void CB_DalleRadio(_D3_OBJECT *o)

{
  short sVar1;
  ushort uVar2;
  bool bVar3;
  bool bVar4;
  short sVar5;
  bool bVar6;
  short sVar7;
  short snd_handle;
  uint uVar8;
  long lVar9;
  _PLATFORM *p_Var10;
  long lVar11;
  int iVar12;
  _D3_OBJECT *o_00;
  int iVar13;
  int iVar14;
  long lVar15;
  
  snd_handle = -1;
  bVar6 = false;
  sVar1 = (o->pos).vz;
  lVar15 = o->color;
  uVar8 = (int)*(short *)&o[1].prec - (int)(o->b_box).vz;
  iVar14 = (int)(uVar8 + (uVar8 >> 0x1f)) >> 1;
  D3_SetCollBits(o,8);
  if ((o->father == (_D3_OBJECT *)0x0) || ((*(uint *)&o->father[1].pos & 0xffffff00) != 0x90700)) {
    bVar6 = true;
  }
  lVar9 = Pvl_TestStateBits(o,4);
  if ((lVar9 == 0) && (Pvl_SetStateBits(o,4), bVar6)) {
    Pvl_SetStateBits(o,2);
  }
  lVar9 = Pvl_TestStateBits(o,2);
  iVar13 = 0;
  if (lVar9 != 0) {
    (o->pos).vz = sVar1 - (short)iVar14;
    iVar13 = iVar14;
  }
  p_Var10 = Plat_GetPlat((char)o + ',');
  bVar4 = false;
  do {
    lVar9 = Task_EventRead(TaskCurrent);
    if (*(char *)((int)&p_Var10[1].obj.pos.vx + 1) == '\x01') {
      if (p_Var10[1].obj.pos.vy != 0) {
        lVar11 = Pvl_TestStateBits(o,2);
        if (lVar11 == 0) {
          o->color = lVar15;
        }
        else {
          o->color = 0x807050;
        }
        goto LAB_80049b48;
      }
      o->color = lVar15;
      uVar2 = o->collision_state;
      (o->pos).vz = ((p_Var10->obj).pos.vz + *(short *)&p_Var10[1].obj.prec) - (o->b_box).vz;
      o->collision_state = uVar2 & 0xffef;
      bVar3 = bVar4;
    }
    else {
LAB_80049b48:
      if (bVar6) {
        o[1].pos.pad = 0;
        lVar11 = Pvl_TestStateBits(o,2);
        if (lVar11 != 0) {
          o[1].pos.pad = o[1].pos.vz;
        }
        o_00 = o->child;
        while (o_00 != (_D3_OBJECT *)0x0) {
          lVar11 = Pvl_TestStateBits(o_00,2);
          if (lVar11 != 0) {
            o[1].pos.pad = o[1].pos.pad + o_00[1].pos.vz;
          }
          o_00 = o_00->next;
        }
      }
      if ((lVar9 == 1) && (lVar9 = Pvl_TestStateBits(o,2), lVar9 != 0)) {
        Pvl_ClearStateBits(o,2);
      }
      if (((o->collision_state & 0x10U) != 0) && (lVar9 = Pvl_TestStateBits(o,2), lVar9 == 0)) {
        o_00 = o->father;
        if ((o_00 == (_D3_OBJECT *)0x0) || ((*(uint *)&o_00[1].pos & 0xffffff00) != 0x90700)) {
          o_00 = o->child;
          while (o_00 != (_D3_OBJECT *)0x0) {
            Task_EventExec(o_00->handle,1,0);
            o_00 = o_00->next;
          }
        }
        else {
          Task_EventExec(o_00->handle,1,0);
          o_00 = o->father->child;
          while (o_00 != (_D3_OBJECT *)0x0) {
            if (o_00 != o) {
              Task_EventExec(o_00->handle,1,0);
            }
            o_00 = o_00->next;
          }
        }
        Pvl_SetStateBits(o,2);
        o->collision_state = o->collision_state & 0xffef;
      }
      bVar3 = false;
      lVar9 = Pvl_TestStateBits(o,2);
      if (lVar9 == 0) {
        iVar12 = iVar13 + -2;
        if ((0 < iVar13) && (iVar13 = iVar12, iVar12 < 0)) {
          iVar13 = 0;
        }
      }
      else {
        if (iVar13 < iVar14) {
          iVar13 = iVar13 + 2;
          bVar3 = true;
          if (iVar14 < iVar13) {
            iVar13 = iVar14;
          }
        }
      }
      sVar5 = (short)iVar13;
      if (bVar3) {
        sVar7 = sVar1 - sVar5;
        if (!bVar4) {
          snd_handle = D3_PlaySound(o,1);
LAB_80049d6c:
          sVar7 = sVar1 - sVar5;
        }
      }
      else {
        sVar7 = sVar1 - sVar5;
        if (bVar4) {
          D3_StopSound(o,snd_handle);
          D3_PlaySound(o,0);
          goto LAB_80049d6c;
        }
      }
      (o->pos).vz = sVar7;
    }
    Task_Next();
    bVar4 = bVar3;
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_InterruptorSwitchONOFF(struct _D3_OBJECT *o /*$s0*/, struct _D3_OBJECT *user /*$s1*/)
 // line 1521, offset 0x80049d84
	/* begin block 1 */
		// Start line: 1522
		// Start offset: 0x80049D84
		// Variables:
	// 		struct M_OBJECT *mo; // $s2
	// 		struct _ZONE *z; // $v1
	// 		long last_state; // $s3
	// 		long time; // $s1
	/* end block 1 */
	// End offset: 0x8004A0F0
	// End Line: 1633

	/* begin block 2 */
		// Start line: 3707
	/* end block 2 */
	// End Line: 3708

void CB_InterruptorSwitchONOFF(_D3_OBJECT *o,_D3_OBJECT *user)

{
  ushort uVar1;
  _ZONE *p_Var2;
  long lVar3;
  long time;
  _D3_OBJECT *obj;
  short snd;
  M_OBJECT *obj_00;
  
  obj_00 = (M_OBJECT *)o->description;
  if ((*(uint *)&o[1].pos.vz & 0x650000) == 0) {
    p_Var2 = Zone_GetObjectZone(o);
    if (p_Var2 != (_ZONE *)0x0) {
      p_Var2->camera = -1;
    }
    Zone_DeleteObject(o);
  }
  Pvl_SetStateBits(o,1);
  lVar3 = Pvl_TestStateBits(o,2);
  if (lVar3 == 0) {
    Pvl_SetStateBits(o,2);
  }
  else {
    Pvl_ClearStateBits(o,2);
  }
  if (user != (_D3_OBJECT *)0x0) {
    Pl_AddExperience((_PLAYER *)user,o);
  }
  if ((o->display_mode & 0x40U) != 0) {
    if (o[1].pos.vy == 5) {
      Manim_ForceAnim(obj_00,(uint)(ushort)o[1].last_pos.vx);
      time = M_rand();
      snd = (short)((uint)((time % 3) * 0x10000) >> 0x10);
    }
    else {
      time = 0;
      Manim_SetAnim(obj_00,(uint)(lVar3 != 0));
      snd = o[1].pos.vy;
      if (snd == 1) {
        time = 0x14;
      }
      if ((snd == 4) && (lVar3 == 0)) {
        Manim_WaitEvent(obj_00,0x8000);
      }
      else {
        if ((o[1].pos.vy == 3) && (time = 0x19, lVar3 == 0)) {
          time = 0x28;
        }
      }
      Task_Sleep(time);
      snd = 0;
    }
    D3_PlaySound(o,snd);
    Manim_WaitAnim(obj_00);
    (obj_00->Env).Obj.normal_top.vx = (obj_00->Env).Obj.normal_top.vx & 0xfffe;
  }
  Pvl_ClearStateBits(o,1);
  snd = o[1].pos.vy;
  if (snd != 5) {
    if (lVar3 == 0) {
      uVar1 = o[1].pos.pad;
      if ((uVar1 & 0xfe) == 2) {
        Scts_Interruptors = Scts_Interruptors & ~(int)o[1].pos.vz;
      }
      else {
        if ((snd == 7) && (uVar1 == 1)) {
          Scts_Interruptors = Scts_Interruptors | (int)o[1].pos.vz << 0x10;
        }
        else {
          Scts_Interruptors = Scts_Interruptors | (uint)(ushort)o[1].pos.vz;
        }
      }
      obj = o->child;
      if ((obj != (_D3_OBJECT *)0x0) && (*(char *)((int)&obj[1].pos.vx + 1) == '\0')) {
        D3_RunMotion(obj);
      }
      obj = o->child;
      while (obj != (_D3_OBJECT *)0x0) {
        if (*(char *)((int)&obj[1].pos.vx + 1) == '\0') {
          *(short *)((int)&obj->b_hurt + 2) = obj[1].pos.pad;
        }
        obj = obj->next;
      }
    }
    else {
      if ((o[1].pos.pad & 0xfeU) == 2) {
        Scts_Interruptors = Scts_Interruptors | (int)o[1].pos.vz;
      }
      else {
        Scts_Interruptors = Scts_Interruptors & ~(int)o[1].pos.vz;
      }
      obj = o->child;
      if ((obj != (_D3_OBJECT *)0x0) && (*(char *)((int)&obj[1].pos.vx + 1) == '\0')) {
        D3_StopMotion(obj);
      }
      obj = o->child;
      while (obj != (_D3_OBJECT *)0x0) {
        if (*(char *)((int)&obj[1].pos.vx + 1) == '\0') {
          *(undefined2 *)((int)&obj->b_hurt + 2) = 0;
        }
        obj = obj->next;
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_MiscTask()
 // line 1663, offset 0x8004a10c
	/* begin block 1 */
		// Start line: 1664
		// Start offset: 0x8004A10C
		// Variables:
	// 		struct _D3_OBJECT *o; // $s0
	/* end block 1 */
	// End offset: 0x8004A2A0
	// End Line: 1692

	/* begin block 2 */
		// Start line: 4007
	/* end block 2 */
	// End Line: 4008

/* WARNING: Unknown calling convention yet parameter storage is locked */

void CB_MiscTask(void)

{
  _D3_OBJECT *o;
  
  o = (_D3_OBJECT *)TaskCurrent->local;
  switch(o[1].pos.vy) {
  case 0:
    CB_WayByInterrupt(o);
    o->handle = (TASK *)0x0;
    break;
  case 1:
    CB_Cascade(o);
    o->handle = (TASK *)0x0;
    break;
  case 2:
    CB_ToxicSmoke(o);
    o->handle = (TASK *)0x0;
    break;
  case 3:
    CB_Passeur(o);
    o->handle = (TASK *)0x0;
    break;
  case 4:
    CB_ColumnDragon(o);
    o->handle = (TASK *)0x0;
    break;
  case 5:
    CB_PieceOWheel(o);
    o->handle = (TASK *)0x0;
    break;
  case 6:
    CB_Lucioles(o);
    o->handle = (TASK *)0x0;
    break;
  case 7:
    CB_Caisse47(o);
    o->handle = (TASK *)0x0;
    break;
  case 8:
    CB_TeleportPod(o);
    o->handle = (TASK *)0x0;
    break;
  case 9:
    CB_SavePod(o);
    o->handle = (TASK *)0x0;
    break;
  case 10:
    CB_Stalagtite(o);
    o->handle = (TASK *)0x0;
    break;
  case 0xb:
    CB_Lvl4_05(o);
    o->handle = (TASK *)0x0;
    break;
  case 0xc:
    CB_JetDeau(o);
    o->handle = (TASK *)0x0;
    break;
  case 0xd:
    CB_PushedIfInterrupt(o);
    o->handle = (TASK *)0x0;
    break;
  case 0xe:
    CB_Dangerous(o);
    o->handle = (TASK *)0x0;
    break;
  case 0xf:
    CB_FireWall(o);
    o->handle = (TASK *)0x0;
    break;
  case 0x10:
    CB_WallAhPuch(o);
    o->handle = (TASK *)0x0;
    break;
  case 0x11:
    CB_GreenPearl(o);
    o->handle = (TASK *)0x0;
    break;
  case 0x12:
    CB_Laser39(o);
    o->handle = (TASK *)0x0;
    break;
  case 0x13:
    CB_Grue28(o);
    o->handle = (TASK *)0x0;
    break;
  case 0x14:
    CB_LoopingSound(o);
  default:
    o->handle = (TASK *)0x0;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_TeleportPod(struct _D3_OBJECT *o /*$s2*/)
 // line 1698, offset 0x8004a2b4
	/* begin block 1 */
		// Start line: 1699
		// Start offset: 0x8004A2B4
		// Variables:
	// 		struct _D3_OBJECT *ot; // $s0
	// 		struct _ZONE *z; // $s1
	// 		long event; // $v0
	/* end block 1 */
	// End offset: 0x8004A364
	// End Line: 1731

	/* begin block 2 */
		// Start line: 4077
	/* end block 2 */
	// End Line: 4078

void CB_TeleportPod(_D3_OBJECT *o)

{
  _ZONE *Param;
  long lVar1;
  _PLAYER *pl;
  
  Param = Zone_GetObjectExit(o);
  do {
    while( true ) {
      while( true ) {
        lVar1 = Task_EventRead(TaskCurrent);
        pl = (_PLAYER *)TaskCurrent->event_param;
        if (lVar1 != 1) break;
        if (Param != (_ZONE *)0x0) {
          Pl_ForceAction(pl,1,(long)Param);
          CB_TeleportOut(o,(_D3_OBJECT *)pl);
        }
      }
      if (lVar1 == 8) break;
      Task_Next();
    }
    Task_Sleep(0x50);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_TeleportOut(struct _D3_OBJECT *o /*$s2*/, struct _D3_OBJECT *ot /*$a1*/)
 // line 1734, offset 0x8004a364
	/* begin block 1 */
		// Start line: 1735
		// Start offset: 0x8004A364
		// Variables:
	// 		struct _D3_OBJECT *oc; // $a1
	// 		long time; // $s0
	// 		long offset[5]; // stack offset -80
	// 		long direct[5]; // stack offset -56
	/* end block 1 */
	// End offset: 0x8004A464
	// End Line: 1772

	/* begin block 2 */
		// Start line: 4169
	/* end block 2 */
	// End Line: 4170

void CB_TeleportOut(_D3_OBJECT *o,_D3_OBJECT *ot)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  _D3_OBJECT *p_Var4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int local_50 [6];
  int local_38 [6];
  
  iVar7 = 0;
  do {
    p_Var4 = o->child;
    if (p_Var4 != (_D3_OBJECT *)0x0) {
      iVar6 = 0;
      piVar3 = local_50;
      piVar5 = local_38;
      do {
        if (iVar7 == iVar6) {
          p_Var4->display_mode = p_Var4->display_mode | 0x10;
          *piVar3 = 0;
          *piVar5 = 5;
        }
        if ((p_Var4->display_mode & 0x10U) != 0) {
          iVar2 = *piVar3 + *piVar5;
          *piVar3 = iVar2;
          if (iVar2 < 0xc9) {
            if (iVar2 < 0) {
              *piVar3 = 0;
              *piVar5 = 5;
            }
          }
          else {
            *piVar3 = 200;
            *piVar5 = -5;
          }
          (p_Var4->pos).vz = (o->pos).vz + *(short *)piVar3 + 100;
        }
        p_Var4 = p_Var4->next;
        piVar3 = piVar3 + 1;
        piVar5 = piVar5 + 1;
        iVar6 = iVar6 + 10;
      } while (p_Var4 != (_D3_OBJECT *)0x0);
    }
    Task_Next();
    bVar1 = iVar7 < 0xe;
    iVar7 = iVar7 + 1;
  } while (bVar1);
  D3_ClearDisplayBitsList(o->child,0x10);
  Task_Sleep(7);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_SavePod(struct _D3_OBJECT *o /*$s1*/)
 // line 1781, offset 0x8004a49c
	/* begin block 1 */
		// Start line: 1782
		// Start offset: 0x8004A49C
		// Variables:
	// 		struct _D3_OBJECT *ot; // $v1
	// 		struct _D3_OBJECT *oc; // $a0
	// 		struct _ZONE *z; // $v1
	// 		long dz; // $s0
	/* end block 1 */
	// End offset: 0x8004A6F0
	// End Line: 1869

	/* begin block 2 */
		// Start line: 4318
	/* end block 2 */
	// End Line: 4319

void CB_SavePod(_D3_OBJECT *o)

{
  short sVar1;
  _ZONE *p_Var2;
  long lVar3;
  _D3_OBJECT *p_Var4;
  undefined4 uVar5;
  int iVar6;
  
  TaskCurrent->destructor = CB_SavePodDestructor;
  *(undefined2 *)((int)&o[1].prec + 2) = 0xffff;
  p_Var2 = Zone_GetObjectZone(o);
  if (p_Var2 != (_ZONE *)0x0) {
    p_Var2->z2 = (o->pos).vz + 0x21;
  }
  D3_ClearDisplayBitsList(o->child,0x10);
  p_Var4 = o->child;
  while (p_Var4 != (_D3_OBJECT *)0x0) {
    p_Var4 = p_Var4->next;
  }
  lVar3 = Pvl_TestStateBits(o,2);
  if (lVar3 != 0) {
    Pvl_SetStateBits(o,1);
    Pvl_ClearStateBits(o,2);
  }
  lVar3 = Pvl_TestStateBits(o,1);
  if (lVar3 == 0) {
    TaskCurrent->display = CB_SavePodDisplay;
    p_Var4 = o->child;
    sVar1 = 0x32;
    while (p_Var4 != (_D3_OBJECT *)0x0) {
      uVar5 = *(undefined4 *)&(o->pos).vz;
      *(undefined4 *)&p_Var4->pos = *(undefined4 *)&o->pos;
      *(undefined4 *)&(p_Var4->pos).vz = uVar5;
      (p_Var4->pos).vz = (p_Var4->pos).vz + sVar1;
      p_Var4 = p_Var4->next;
      sVar1 = sVar1 + 0x32;
    }
    while (lVar3 = Pvl_TestStateBits(o,1), lVar3 == 0) {
      lVar3 = Task_EventRead(TaskCurrent);
      if ((lVar3 == 1) &&
         (((((_PLAYER *)TaskCurrent->event_param)->obj).collision_mode & 0x1000U) != 0)) {
        Pl_ForceAction((_PLAYER *)TaskCurrent->event_param,2,(long)o);
      }
      p_Var4 = o->child;
      while (p_Var4 != (_D3_OBJECT *)0x0) {
        sVar1 = (p_Var4->pos).vz + 2;
        (p_Var4->pos).vz = sVar1;
        if ((int)(o->pos).vz + 200 <= (int)sVar1) {
          (p_Var4->pos).vz = (o->pos).vz + 0x32;
        }
        p_Var4 = p_Var4->next;
      }
      sVar1 = D3_UpdateSound(o,1,*(short *)((int)&o[1].prec + 2));
      *(short *)((int)&o[1].prec + 2) = sVar1;
      Task_Next();
    }
    do {
      p_Var4 = o->child;
      iVar6 = 0;
      while (p_Var4 != (_D3_OBJECT *)0x0) {
        sVar1 = (p_Var4->pos).vz + 2;
        (p_Var4->pos).vz = sVar1;
        if ((int)(o->pos).vz + 200 <= (int)sVar1) {
          (p_Var4->pos).vz = (o->pos).vz + 200;
          iVar6 = iVar6 + 1;
        }
        p_Var4 = p_Var4->next;
      }
      Task_Next();
    } while (iVar6 < 3);
  }
  o->handle = (TASK *)0x0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_SavePodDisplay()
 // line 1873, offset 0x8004a708
	/* begin block 1 */
		// Start line: 1874
		// Start offset: 0x8004A708
		// Variables:
	// 		struct _D3_OBJECT *oc; // $s0
	// 		struct _D3_OBJECT *o; // $s1
	// 		struct CBASE_8fake color; // stack offset -24
	// 		long dz; // $v1
	/* end block 1 */
	// End offset: 0x8004A7CC
	// End Line: 1904

	/* begin block 2 */
		// Start line: 4558
	/* end block 2 */
	// End Line: 4559

/* WARNING: Unknown calling convention yet parameter storage is locked */

void CB_SavePodDisplay(void)

{
  _D3_OBJECT *obj;
  
  obj = *(_D3_OBJECT **)((int)TaskCurrent->local + 8);
  while (obj != (_D3_OBJECT *)0x0) {
    Tmd_ChangeColor((char)obj->description,0xe8);
    Main_Prims = D3_DisplayTmd(obj,Main_Prims,0,(int)Scr_W);
    obj = obj->next;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_SavePodDestructor(struct TASK *t /*$a0*/)
 // line 1907, offset 0x8004a7e4
	/* begin block 1 */
		// Start line: 1908
		// Start offset: 0x8004A7E4
		// Variables:
	// 		struct _D3_OBJECT *o; // $v0
	/* end block 1 */
	// End offset: 0x8004A80C
	// End Line: 1917

	/* begin block 2 */
		// Start line: 4664
	/* end block 2 */
	// End Line: 4665

void CB_SavePodDestructor(TASK *t)

{
  int wPlayId;
  
  wPlayId = (int)*(short *)((int)t->local + 0x72);
  if (-1 < wPlayId) {
    Sound_Stop(wPlayId,0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_Caisse47(struct _D3_OBJECT *caisse /*$s0*/)
 // line 1922, offset 0x8004a81c
	/* begin block 1 */
		// Start line: 1923
		// Start offset: 0x8004A81C
		// Variables:
	// 		struct _D3_OBJECT *crochet; // $s1
	// 		struct _D3_OBJECT *obj; // $v1
	// 		long dx; // $s5
	// 		long dy; // $s4
	// 		long dz; // $s7
	// 		long rx; // $s3
	// 		long rz; // $s2
	// 		long hith; // $fp

		/* begin block 1.1 */
			// Start line: 2027
			// Start offset: 0x8004AB34
			// Variables:
		// 		long hold; // $a0
		/* end block 1.1 */
		// End offset: 0x8004ABF0
		// End Line: 2055
	/* end block 1 */
	// End offset: 0x8004AC00
	// End Line: 2057

	/* begin block 2 */
		// Start line: 4694
	/* end block 2 */
	// End Line: 4695

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CB_Caisse47(_D3_OBJECT *caisse)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  bool bVar5;
  long lVar6;
  long lVar7;
  _D3_OBJECT *obj;
  int wPlayId;
  undefined4 uVar8;
  _D3_OBJECT *o;
  short sVar9;
  short sVar10;
  
  o = caisse->father;
  sVar1 = (caisse->pos).vz;
  sVar2 = o->hit_points;
  sVar10 = (caisse->pos).vx - (o->pos).vx;
  sVar3 = (o->pos).vz;
  sVar9 = (caisse->pos).vy - (o->pos).vy;
  D3_ClearCollBits(caisse,1);
  caisse->display_mode = caisse->display_mode & 0xffef;
  do {
    if (caisse->child == (_D3_OBJECT *)0x0) {
      D3_ClearCollBits(o,1);
      do {
        obj = o->child;
        bVar5 = false;
        if (obj != (_D3_OBJECT *)0x0) {
          do {
            if (_DAT_800b1d34 == obj) {
              bVar5 = true;
            }
            obj = obj->next;
          } while ((obj != (_D3_OBJECT *)0x0) && (!bVar5));
        }
        if (*(short *)((int)&o[1].prec + 2) == -2) {
          *(undefined2 *)((int)&o[1].prec + 2) = 0xffff;
        }
        if ((!bVar5) &&
           (lVar7 = Distance2D((int)(o->pos).vx,(int)(o->pos).vy,100,-900), lVar7 < 0x1a)) {
          wPlayId = (int)*(short *)((int)&o[1].prec + 2);
          if (-1 < wPlayId) {
            Sound_Stop(wPlayId,0);
          }
          obj = o->child;
          *(undefined2 *)((int)&o[1].prec + 2) = 0xfffe;
          (o->pos).vx = 100;
          (o->pos).vy = -900;
          while (obj != (_D3_OBJECT *)0x0) {
            (obj->pos).vx = 100;
            (obj->pos).vy = -900;
            obj = obj->next;
          }
        }
        Task_Next();
      } while( true );
    }
    D3_SetCollBits(caisse,9);
    caisse->collision_state = 0;
    caisse->display_mode = caisse->display_mode | 0x10;
    D3_ClearCollBits(caisse,0x80);
    o->hit_points = sVar2;
    caisse->hit_points = 1;
    (caisse->rot).vz = 0;
    (caisse->rot).vy = 0;
    (caisse->rot).vx = 0;
    while( true ) {
      if (((int)caisse->collision_state & 0xfc00U) == 0) {
        uVar8 = *(undefined4 *)&(o->pos).vz;
        *(undefined4 *)&caisse->pos = *(undefined4 *)&o->pos;
        *(undefined4 *)&(caisse->pos).vz = uVar8;
        (caisse->pos).vx = (caisse->pos).vx + sVar10;
        (caisse->pos).vz = (caisse->pos).vz + (sVar1 - sVar3);
        (caisse->pos).vy = (caisse->pos).vy + sVar9;
      }
      else {
        (o->pos).vx = (caisse->pos).vx - sVar10;
        obj = o->child;
        (o->pos).vy = (caisse->pos).vy - sVar9;
        while (obj != (_D3_OBJECT *)0x0) {
          if (obj != caisse) {
            (obj->pos).vx = (caisse->pos).vx - sVar10;
            (obj->pos).vy = (caisse->pos).vy - sVar9;
          }
          obj = obj->next;
        }
      }
      if ((caisse->hit_points == 0) || (o->hit_points == 0)) break;
      Task_Next();
    }
    D3_SetCollBits(caisse,0x80);
    lVar7 = M_rand();
    lVar6 = M_rand();
    sVar4 = caisse->hit_points;
    while (sVar4 != 0) {
      (caisse->rot).vx = (caisse->rot).vx + (short)lVar7 + (short)(lVar7 / 0xf) * -0xf + 0x10;
      (caisse->rot).vz = (caisse->rot).vz + (short)lVar6 + (short)(lVar6 / 0xf) * -0xf + 0x10;
      Task_Next();
      obj = caisse->child;
      if (obj == (_D3_OBJECT *)0x0) break;
      if ((((obj->collision_state & 1U) != 0) && ((obj->collision_state & 0x100U) != 0)) &&
         ((_D3_OBJECT *)obj[1].color == caisse)) {
        D3_ExplodeObject(obj);
      }
      sVar4 = caisse->hit_points;
    }
    if (-0x1f5 < (caisse->pos).vz) {
      SFX_Explosion((char)caisse + ',',(int)caisse->comp_opt1,
                    (int)*(short *)((int)&caisse->comp_opt4 + 2));
    }
    D3_ClearCollBits(caisse,1);
    caisse->display_mode = caisse->display_mode & 0xffef;
    caisse->collision_state = caisse->collision_state & 0xfeff;
    (o->pos).pad = 0;
    do {
      Task_Next();
    } while ((o->pos).pad == 0);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_PasseurSounds(struct CBASE_134fake *p /*$s1*/)
 // line 2116, offset 0x8004ac00
	/* begin block 1 */
		// Start line: 2117
		// Start offset: 0x8004AC00
		// Variables:
	// 		long evt; // $s0
	/* end block 1 */
	// End offset: 0x8004ADC8
	// End Line: 2161

	/* begin block 2 */
		// Start line: 5280
	/* end block 2 */
	// End Line: 5281

void CB_PasseurSounds(CBASE_134fake *p)

{
  ushort uVar1;
  short sVar2;
  uint uVar3;
  long lVar4;
  int iVar5;
  
  uVar1 = (p->mo->Env).Obj.vert_top.pad;
  if ((uVar1 & 1) != 0) {
    uVar3 = M_rand();
    D3_PlaySound(p->o,(ushort)((uVar3 & 1) << 1) | 5);
  }
  if ((uVar1 & 0x10) != 0) {
    lVar4 = M_rand();
    D3_PlaySound(p->o,((ushort)lVar4 & 1) * 2 + 6);
  }
  if ((uVar1 & 2) != 0) {
    lVar4 = M_rand();
    D3_PlaySound(p->o,((ushort)lVar4 & 1) + 0xd);
  }
  if ((uVar1 & 4) != 0) {
    D3_PlaySound(p->o,9);
  }
  if ((uVar1 & 8) != 0) {
    D3_PlaySound(p->o,10);
  }
  if ((uVar1 & 0x20) != 0) {
    D3_PlaySound(p->o,2);
  }
  if ((uVar1 & 0x40) != 0) {
    lVar4 = M_rand();
    D3_PlaySound(p->o,((ushort)lVar4 & 1) + 0xf);
  }
  if (((uVar1 & 0x80) != 0) && (uVar3 = M_rand(), (uVar3 & 7) == 0)) {
    D3_PlaySound(p->o,2);
  }
  if ((uVar1 & 0x100) != 0) {
    D3_PlaySound(p->o,4);
  }
  if (p->rspd == 0) {
    if (p->rsnd < 0) {
      return;
    }
    D3_StopSound(p->o,*(short *)&p->rsnd);
    iVar5 = -1;
  }
  else {
    uVar3 = M_rand();
    if ((uVar3 & 0x3f) == 0) {
      D3_PlaySound(p->o,3);
    }
    if (-1 < p->rsnd) {
      return;
    }
    sVar2 = D3_PlaySound(p->o,0);
    iVar5 = (int)sVar2;
  }
  p->rsnd = iVar5;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_Passeur(struct _D3_OBJECT *obj /*$s3*/)
 // line 2164, offset 0x8004addc
	/* begin block 1 */
		// Start line: 2165
		// Start offset: 0x8004ADDC
		// Variables:
	// 		struct CBASE_134fake p; // stack offset -96
	// 		long time; // $s2
	// 		long i; // $s0
	// 		long stepofcounter; // $s1
	/* end block 1 */
	// End offset: 0x8004B264
	// End Line: 2294

	/* begin block 2 */
		// Start line: 5376
	/* end block 2 */
	// End Line: 5377

void CB_Passeur(_D3_OBJECT *obj)

{
  char cVar1;
  _PVL_HEADER *p_Var2;
  _LIGHT *p_Var3;
  short sVar4;
  int iVar5;
  long Anim;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  _D3_OBJECT *local_60;
  _D3_OBJECT *local_5c;
  _D3_OBJECT *local_58;
  _D3_OBJECT *local_54;
  M_OBJECT *local_50;
  TASK *local_4c;
  _ZONE *local_48;
  _ZONE *local_44;
  _ZONE *local_40;
  _LIGHT *local_3c;
  int local_38;
  undefined4 local_2c;
  int local_28;
  undefined4 local_24;
  int local_20;
  _ROTMATRIX *local_1c;
  
  *(_D3_OBJECT **)&TaskCurrent->local = (_D3_OBJECT *)&local_60;
  local_5c = obj->child;
  local_58 = local_5c->child;
  local_54 = local_58->child;
  local_50 = (M_OBJECT *)obj->description;
  local_4c = (TASK *)local_5c->description;
  local_60 = obj;
  local_48 = Zone_GetObjectZone(obj);
  while (local_48->type != '\0') {
    local_48 = Zone_GetObjectNext(obj);
  }
  local_44 = Zone_GetObjectZone(obj);
  cVar1 = local_44->type;
  while (cVar1 != '\x01') {
    local_44 = Zone_GetObjectNext(obj);
    cVar1 = local_44->type;
  }
  local_40 = Zone_GetObjectZone(obj);
  cVar1 = local_40->type;
  p_Var2 = Pvl_File;
  while (cVar1 != '\x02') {
    Pvl_File = p_Var2;
    local_40 = Zone_GetObjectNext(obj);
    cVar1 = local_40->type;
    p_Var2 = Pvl_File;
  }
  iVar9 = 1;
  local_1c = (_ROTMATRIX *)0xffffffff;
  local_38 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  Pvl_File = p_Var2;
  TaskCurrent->display = CB_PasseurState;
  iVar7 = 0;
  p_Var3 = Pvl_Lights;
  if (0 < p_Var2->n_lights) {
    do {
      local_3c = p_Var3;
      iVar7 = iVar7 + 1;
      if (local_3c->amb == '\x06') break;
      p_Var3 = local_3c + 1;
    } while (iVar7 < (int)p_Var2->n_lights);
  }
  Anim = 0;
LAB_8004afc8:
  do {
    Manim_SetAnim(local_50,Anim);
LAB_8004afd0:
    do {
      Manim_WaitAnim(local_50);
LAB_8004afdc:
      if (*(short *)((int)&(local_50->Env).Version + 2) == 0) {
        do {
          do {
            uVar6 = *(undefined4 *)&(local_58->pos).vz;
            *(undefined4 *)&local_60->pos = *(undefined4 *)&local_58->pos;
            *(undefined4 *)&(local_60->pos).vz = uVar6;
            (local_60->pos).vx = (local_60->pos).vx + 0xfa;
            (local_60->pos).vy = (local_60->pos).vy + 100;
            uVar6 = *(undefined4 *)&(local_60->pos).vz;
            *(undefined4 *)&local_60->last_pos = *(undefined4 *)&local_60->pos;
            *(undefined4 *)&(local_60->last_pos).vz = uVar6;
            Manim_SetAnim(local_50,4);
            iVar9 = iVar9 + -1;
            (local_50->Env).Obj.normal_top.vx = (local_50->Env).Obj.normal_top.vx & 0xfffe;
            if (iVar9 == -1) {
              (local_50->Env).Obj.normal_top.vx = (local_50->Env).Obj.normal_top.vx | 1;
              Manim_WaitAnim(local_50);
              Anim = M_rand();
              iVar9 = Anim % 0x1e + 0x32;
            }
            Task_Next();
          } while ((local_58->collision_state & 0x10U) == 0);
          sVar4 = Zone_IsPosInZone(local_40,(char)obj + ',');
        } while (sVar4 != 0);
        Manim_SetAnim(local_50,1);
        Manim_WaitAnim(local_50);
        if ((local_58->collision_state & 0x10U) != 0) {
          Manim_SetAnim(local_50,2);
          iVar7 = 2;
          Manim_WaitAnim(local_50);
          do {
            sVar4 = Zone_IsPosInZone(local_40,(char)obj + ',');
            if (sVar4 != 0) break;
            if ((iVar7 == 0) || (iVar7 = iVar7 + -1, (local_58->collision_state & 0x10U) != 0)) {
              iVar7 = 2;
            }
            iVar8 = 0;
            Manim_SetAnim(local_50,5);
            do {
              iVar5 = local_38 + 0x100;
              local_38 = 0x800;
              if (iVar5 < 0x801) {
                local_38 = iVar5;
              }
              if (iVar8 < 8) {
                local_28 = local_28 + 5;
              }
              if (iVar8 < 4) {
                local_20 = local_20 + -3;
              }
              iVar8 = iVar8 + 1;
              Task_Next();
            } while (iVar8 < 0xc);
            Manim_WaitAnim(local_50);
          } while (iVar7 != 0);
        }
        goto LAB_8004afdc;
      }
      sVar4 = *(short *)((int)&(local_50->Env).Version + 2);
      if (sVar4 == 2) {
LAB_8004afc0:
        Anim = 3;
        goto LAB_8004afc8;
      }
      if (2 < sVar4) {
        if (sVar4 == 3) break;
        if (sVar4 == 5) goto LAB_8004afc0;
        goto LAB_8004afd0;
      }
    } while (sVar4 != 1);
    Anim = 0;
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_PasseurState()
 // line 2297, offset 0x8004b264
	/* begin block 1 */
		// Start line: 2298
		// Start offset: 0x8004B264
		// Variables:
	// 		struct CBASE_134fake *p; // $s0
	// 		struct CBASE_5fake m; // stack offset -48
	// 		long rc; // $s1
	// 		long rs; // $a0
	// 		long dx; // $a2
	// 		long dy; // $a1
	/* end block 1 */
	// End offset: 0x8004B704
	// End Line: 2426

	/* begin block 2 */
		// Start line: 5677
	/* end block 2 */
	// End Line: 5678

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void CB_PasseurState(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  short sVar3;
  undefined4 in_zero;
  undefined4 in_at;
  int iVar4;
  int iVar5;
  _D3_OBJECT *p_Var6;
  int iVar7;
  _ZONE *p_Var8;
  _LIGHT *p_Var9;
  short sVar10;
  undefined4 uVar11;
  CBASE_134fake *p;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  short local_1c;
  short local_18;
  short local_14;
  
  if (Pvl_Pause == 0) {
    p = (CBASE_134fake *)TaskCurrent->local;
    CB_PasseurSounds(p);
    p->rx8 = (int)CONCAT21((p->or->pos).vx,*(undefined *)&p->rx8);
    p->ry8 = (int)CONCAT21((p->or->pos).vy,*(undefined *)&p->ry8);
    iVar4 = rcos((int)(p->or->rot).vz);
    iVar5 = rsin((int)(p->or->rot).vz);
    iVar7 = p->rspd + -0x10;
    if (iVar7 < 0) {
      iVar7 = 0;
    }
    p->rspd = iVar7;
    p->rx8 = p->rx8 + (iVar7 * (iVar4 >> 4) >> 8);
    iVar5 = p->ry8 + (iVar7 * (iVar5 >> 4) >> 8);
    p->ry8 = iVar5;
    iVar4 = (int)(p->or->pos).vx;
    iVar7 = (p->rx8 >> 8) - iVar4;
    sVar10 = (short)((uint)iVar5 >> 8) - (p->or->pos).vy;
    if (iVar4 < -0xc1c) {
      Scts_Interruptors = Scts_Interruptors & 0x80000000;
      in_at = 0x800b0000;
      if (Scts_Interruptors == 0) {
        p_Var8 = p->rzone;
        iVar7 = iVar7 + 0x189c;
      }
      else {
        p_Var8 = p->ezone;
        iVar7 = iVar7 + 0xc1c;
      }
      sVar10 = sVar10 + ((short)((int)p_Var8->y1 + (int)p_Var8->y2 >> 1) - (p->or->pos).vy);
    }
    sVar3 = (short)iVar7;
    (p->or->pos).vx = (p->or->pos).vx + sVar3;
    (p->or->pos).vy = (p->or->pos).vy + sVar10;
    (p->o->pos).vx = (p->o->pos).vx + sVar3;
    (p->o->pos).vy = (p->o->pos).vy + sVar10;
    if (100 < iVar7) {
      _DAT_800b1c64 = CONCAT22(_DAT_800b1c66 + sVar10,_DAT_800b1c64 + sVar3);
      _DAT_800b1c6c = _DAT_800b1c64;
      _DAT_800b1c70 = _DAT_800b1c68;
      Cam_Pos_ = Cam_Pos_ + sVar3;
      DAT_800b416a = DAT_800b416a + sVar10;
      DAT_800b4170 = DAT_800b4170 + sVar3;
      DAT_800b4172 = DAT_800b4172 + sVar10;
      Cam_Target_ = Cam_Target_ + sVar3;
      DAT_800b415a = DAT_800b415a + sVar10;
      DAT_800b4160 = DAT_800b4160 + sVar3;
      DAT_800b4162 = DAT_800b4162 + sVar10;
      in_at = 0x800b0000;
      p_Var6 = p->or;
      uVar11 = *(undefined4 *)&(p_Var6->pos).vz;
      *(undefined4 *)&p_Var6->last_pos = *(undefined4 *)&p_Var6->pos;
      *(undefined4 *)&(p_Var6->last_pos).vz = uVar11;
      p_Var6 = p->o;
      uVar11 = *(undefined4 *)&(p_Var6->pos).vz;
      *(undefined4 *)&p_Var6->last_pos = *(undefined4 *)&p_Var6->pos;
      *(undefined4 *)&(p_Var6->last_pos).vz = uVar11;
    }
    RotMatrixZYX((short *)&p->or->rot,(undefined2 *)&local_30);
    setCopControlWord(2,0,local_30);
    setCopControlWord(2,0x800,local_2c);
    setCopControlWord(2,0x1000,local_28);
    setCopControlWord(2,0x1800,local_24);
    setCopControlWord(2,0x2000,local_20);
    (p->ol->pos).vx = -0xf0;
    (p->ol->pos).vy = 200;
    (p->ol->pos).vz = 200;
    setCopReg(2,in_zero,*(undefined4 *)&p->ol->pos);
    setCopReg(2,in_at,*(undefined4 *)&(p->ol->pos).vz);
    copFunction(2,0x486012);
    uVar11 = getCopReg(2,0x19);
    uVar1 = getCopReg(2,0x1a);
    uVar2 = getCopReg(2,0x1b);
    local_1c = (short)uVar11;
    (p->ol->pos).vx = (p->or->pos).vx + local_1c;
    local_18 = (short)uVar1;
    (p->ol->pos).vy = (p->or->pos).vy + local_18;
    local_14 = (short)uVar2;
    (p->ol->pos).vz = (p->or->pos).vz + local_14;
    p_Var9 = p->l;
    uVar11 = *(undefined4 *)&(p->ol->pos).vz;
    *(undefined4 *)&p_Var9->pos = *(undefined4 *)&p->ol->pos;
    *(undefined4 *)&(p_Var9->pos).vz = uVar11;
    p_Var6 = p->os;
    uVar11 = *(undefined4 *)&(p->o->pos).vz;
    *(undefined4 *)&p_Var6->pos = *(undefined4 *)&p->o->pos;
    *(undefined4 *)&(p_Var6->pos).vz = uVar11;
    *(undefined2 *)((int)&(p->mos->Env).Version + 2) =
         *(undefined2 *)((int)&(p->mo->Env).Version + 2);
    *(undefined2 *)&(p->mos->Env).nPivot = *(undefined2 *)&(p->mo->Env).nPivot;
    p->or->collision_state = p->or->collision_state & 0xffef;
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
// void /*$ra*/ CB_WayByInterrupt(struct _D3_OBJECT *o /*$s1*/)
 // line 2431, offset 0x8004b718
	/* begin block 1 */
		// Start line: 2432
		// Start offset: 0x8004B718
		// Variables:
	// 		long c; // $s0
	// 		long ls; // $s0
	/* end block 1 */
	// End offset: 0x8004B928
	// End Line: 2515

	/* begin block 2 */
		// Start line: 5967
	/* end block 2 */
	// End Line: 5968

void CB_WayByInterrupt(_D3_OBJECT *o)

{
  int color;
  uint uVar1;
  uint uVar2;
  
  uVar2 = Scts_Interruptors & (int)o[1].pos.vz;
  if (uVar2 == 0) {
    o->color = 0;
    D3_SetColorList(o->child,0);
    o->display_mode = o->display_mode & 0xffef;
    D3_ClearDisplayBitsList(o->child,0x10);
    D3_ClearCollBits(o,1);
    D3_ClearCollBitsList(o->child,1);
  }
  else {
    o->color = 0x808080;
    D3_SetColorList(o->child,0x808080);
    o->display_mode = o->display_mode | 0x10;
    D3_SetDisplayBitsList(o->child,0x10);
    D3_SetCollBits(o,1);
    D3_SetCollBitsList(o->child,1);
  }
  do {
    uVar1 = SEXT24(o[1].pos.vz);
    while ((Scts_Interruptors & uVar1) != uVar2) {
      D3_PlaySound(o,0);
      if (uVar2 == 0) {
        o->display_mode = o->display_mode | 0x10;
        D3_SetDisplayBitsList(o->child,0x10);
        D3_SetCollBits(o,1);
        D3_SetCollBitsList(o->child,1);
        color = o->color;
        while (color < 0x808081) {
          o->color = color;
          D3_SetColorList(o->child,color);
          Task_Next();
          color = color + 0x20202;
        }
        uVar1 = SEXT24(o[1].pos.vz);
        uVar2 = Scts_Interruptors & uVar1;
      }
      else {
        color = o->color;
        while (-1 < color) {
          o->color = color;
          D3_SetColorList(o->child,color);
          Task_Next();
          color = color + -0x20202;
        }
        o->display_mode = o->display_mode & 0xffef;
        D3_ClearDisplayBitsList(o->child,0x10);
        D3_ClearCollBits(o,1);
        D3_ClearCollBitsList(o->child,1);
        uVar1 = SEXT24(o[1].pos.vz);
        uVar2 = Scts_Interruptors & uVar1;
      }
    }
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_Cascade(struct _D3_OBJECT *o /*$s3*/)
 // line 2530, offset 0x8004b928
	/* begin block 1 */
		// Start line: 2531
		// Start offset: 0x8004B928
		// Variables:
	// 		struct CBASE_93fake *tmd; // $v0
	// 		struct CBASE_92fake *TmdPrim; // stack offset -44
	// 		struct CBASE_92fake *pPrim; // $s1
	// 		long nPrim; // $fp
	// 		int i; // $s0
	// 		int j; // $a0
	// 		short *pUV; // $a1
	// 		short step; // $s7
	// 		struct CBASE_7fake pos; // stack offset -64
	// 		unsigned char *Ref; // $s6
	// 		unsigned char cpt; // $s5
	// 		unsigned char v[3]; // stack offset -56
	// 		unsigned char High; // stack offset -47
	// 		unsigned char Low; // stack offset -48
	/* end block 1 */
	// End offset: 0x8004BC20
	// End Line: 2618

	/* begin block 2 */
		// Start line: 6176
	/* end block 2 */
	// End Line: 6177

void CB_Cascade(_D3_OBJECT *o)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  short sVar4;
  TASK *pTVar5;
  char cVar6;
  short sVar7;
  long *plVar8;
  byte *pbVar9;
  int iVar10;
  ushort *puVar11;
  ulong uVar12;
  ushort *puVar13;
  char cVar14;
  ulong size;
  byte local_38 [8];
  byte local_30;
  byte local_2f [3];
  ushort *local_2c;
  
  cVar14 = '\b';
  size = *(ulong *)((int)o->description + 0x14);
  local_2c = *(ushort **)((int)o->description + 0x10);
  sVar4 = o[1].pos.vz;
  plVar8 = (long *)Heap_AllocMem(size);
  pTVar5 = TaskCurrent;
  o->shapes = plVar8;
  *(_D3_OBJECT **)&pTVar5->local = o;
  pTVar5->destructor = CB_CascadeDestructor;
  uVar12 = size;
  puVar13 = local_2c;
  while (uVar12 != 0) {
    iVar10 = 0;
    puVar11 = puVar13;
    do {
      puVar11 = puVar11 + 2;
      pbVar9 = local_38 + iVar10;
      iVar10 = iVar10 + 1;
      *pbVar9 = (byte)(*puVar11 >> 8);
    } while (iVar10 < 3);
    cVar6 = CB_CascadeGetRef((char *)local_38);
    *(char *)((int)plVar8 + (uVar12 - 1)) = cVar6;
    uVar12 = uVar12 - 1;
    puVar13 = puVar13 + (uint)*(byte *)((int)puVar13 + 1) * 2 + 2;
  }
  *(undefined2 *)((int)&o[1].prec + 2) = 0xffff;
  uVar12 = size;
  puVar13 = local_2c;
  do {
    while (uVar12 == 0) {
      if ((o[1].pos.pad != 0) && (bVar1 = cVar14 == '\0', cVar14 = cVar14 + -1, bVar1)) {
        M_rand();
        M_rand();
        cVar14 = '\b';
        Impact_Smoke(0xc0,1);
      }
      if (-1 < *(short *)((int)&o[1].father + 2)) {
        sVar7 = D3_UpdateSound(o,0,*(short *)((int)&o[1].prec + 2));
        *(short *)((int)&o[1].prec + 2) = sVar7;
      }
      Task_Next();
      uVar12 = size;
      puVar13 = local_2c;
    }
    iVar10 = 0;
    puVar11 = puVar13;
    do {
      puVar11 = puVar11 + 2;
      pbVar9 = local_38 + iVar10;
      iVar10 = iVar10 + 1;
      *pbVar9 = (byte)(*puVar11 >> 8);
    } while (iVar10 < 3);
    CB_CascadeGetLimits((char *)local_38,(char *)&local_30,(char *)local_2f);
    bVar2 = local_38[(uint)local_2f[0]];
    iVar10 = 0;
    cVar6 = (char)sVar4;
    pbVar9 = local_38;
    if ((int)(uint)*(byte *)((int)plVar8 + (uVar12 - 1)) < (int)((uint)bVar2 - (int)sVar4)) {
      do {
        iVar10 = iVar10 + 1;
        *pbVar9 = *pbVar9 - cVar6;
        pbVar9 = local_38 + iVar10;
      } while (iVar10 < 3);
    }
    else {
      bVar3 = local_38[(uint)local_30];
      pbVar9 = local_38;
      do {
        iVar10 = iVar10 + 1;
        *pbVar9 = *pbVar9 + ((bVar2 - bVar3) - cVar6);
        pbVar9 = local_38 + iVar10;
      } while (iVar10 < 3);
    }
    iVar10 = 0;
    puVar11 = puVar13;
    do {
      puVar11 = puVar11 + 2;
      bVar2 = *(byte *)puVar11;
      pbVar9 = local_38 + iVar10;
      *puVar11 = (ushort)bVar2;
      iVar10 = iVar10 + 1;
      *puVar11 = CONCAT11(*pbVar9,bVar2);
    } while (iVar10 < 3);
    uVar12 = uVar12 - 1;
    puVar13 = puVar13 + (uint)*(byte *)((int)puVar13 + 1) * 2 + 2;
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_CascadeDestructor(struct TASK *handle /*$a0*/)
 // line 2729, offset 0x8004bc20
	/* begin block 1 */
		// Start line: 2730
		// Start offset: 0x8004BC20
		// Variables:
	// 		struct _D3_OBJECT *o; // $a0
	// 		unsigned char *Ref; // $s0
	/* end block 1 */
	// End offset: 0x8004BC4C
	// End Line: 2738

	/* begin block 2 */
		// Start line: 6643
	/* end block 2 */
	// End Line: 6644

void CB_CascadeDestructor(TASK *handle)

{
  short snd_handle;
  _D3_OBJECT *o;
  long *ptt;
  
  o = (_D3_OBJECT *)handle->local;
  snd_handle = *(short *)((int)&o[1].prec + 2);
  ptt = o->shapes;
  if (-1 < snd_handle) {
    D3_StopSound(o,snd_handle);
  }
  Heap_FreeMem(ptt);
  return;
}



// decompiled code
// original method signature: 
// char /*$ra*/ CB_CascadeGetRef(char *v /*$a0*/)
 // line 2745, offset 0x8004bc64
	/* begin block 1 */
		// Start line: 2747
		// Start offset: 0x8004BC64
		// Variables:
	// 		int i; // $v1
	// 		unsigned char ValueMin; // $a2
	/* end block 1 */
	// End offset: 0x8004BC98
	// End Line: 2757

	/* begin block 2 */
		// Start line: 6682
	/* end block 2 */
	// End Line: 6683

char CB_CascadeGetRef(char *v)

{
  byte *pbVar1;
  int iVar2;
  byte bVar3;
  
  bVar3 = 0xff;
  iVar2 = 0;
  pbVar1 = (byte *)v;
  do {
    if (*pbVar1 < bVar3) {
      bVar3 = *pbVar1;
    }
    iVar2 = iVar2 + 1;
    pbVar1 = (byte *)(v + iVar2);
  } while (iVar2 < 3);
  return (char)bVar3;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_CascadeGetLimits(char *v /*$a0*/, char *Low /*$a1*/, char *High /*$a2*/)
 // line 2761, offset 0x8004bca0
	/* begin block 1 */
		// Start line: 2763
		// Start offset: 0x8004BCA0
		// Variables:
	// 		int i; // $a3
	// 		unsigned char ValueMin; // $t1
	// 		unsigned char ValueMax; // $t2
	/* end block 1 */
	// End offset: 0x8004BCF8
	// End Line: 2782

	/* begin block 2 */
		// Start line: 6717
	/* end block 2 */
	// End Line: 6718

void CB_CascadeGetLimits(char *v,char *Low,char *High)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  byte bVar5;
  byte bVar6;
  
  bVar6 = 0;
  bVar5 = 0xff;
  iVar3 = 0;
  pbVar4 = (byte *)v;
  do {
    bVar1 = *pbVar4;
    bVar2 = bVar1;
    if (bVar1 < bVar5) {
      *Low = (char)iVar3;
      bVar2 = *pbVar4;
      bVar5 = bVar1;
    }
    if (bVar6 < bVar2) {
      *High = (char)iVar3;
      bVar6 = bVar2;
    }
    iVar3 = iVar3 + 1;
    pbVar4 = (byte *)(v + iVar3);
  } while (iVar3 < 3);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_ToxicSmoke(struct _D3_OBJECT *o /*$s0*/)
 // line 2835, offset 0x8004bd00
	/* begin block 1 */
		// Start line: 2836
		// Start offset: 0x8004BD00
		// Variables:
	// 		struct TASK *stream; // $s3
	// 		struct CBASE_7fake spd; // stack offset -40
	// 		long val; // $s1
	// 		long flag; // $s6
	// 		long fx_handle; // $s2

		/* begin block 1.1 */
			// Start line: 2856
			// Start offset: 0x8004BDA0
			// Variables:
		// 		long event; // $s5
		/* end block 1.1 */
		// End offset: 0x8004BF50
		// End Line: 2916
	/* end block 1 */
	// End offset: 0x8004BF60
	// End Line: 2920

	/* begin block 2 */
		// Start line: 6871
	/* end block 2 */
	// End Line: 6872

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CB_ToxicSmoke(_D3_OBJECT *o)

{
  short sVar1;
  ushort uVar2;
  short snd_handle;
  TASK *pTVar3;
  long lVar4;
  long value;
  int iVar5;
  short sVar6;
  int flag;
  undefined auStack40 [8];
  
  memset(auStack40,0,8);
  snd_handle = -1;
  flag = (int)o[1].last_pos.vy;
  value = 0xc;
  if (flag != 0) {
    value = 4;
  }
  CB_StreamSetSpeed(o,0xd8,value);
  CB_SmokeSetBBox(o);
  D3_SetCollBits(o,0x2000);
  pTVar3 = SFX_StreamSteam((char)o + ',',0xd8,flag);
  iVar5 = 0;
  *(TASK **)&TaskCurrent->local = pTVar3;
  do {
    Joy_ReadTrigAll();
    Joy_ReadLogAll();
    value = Task_EventRead(TaskCurrent);
    D3_ClearCollBits(o,8);
    uVar2 = *(ushort *)&pTVar3[1].s7;
    if ((uVar2 & 4) == 0) {
      sVar6 = snd_handle;
      if (iVar5 == 0) {
        sVar1 = o[1].pos.pad;
        iVar5 = (int)Scr_TicksPerSecond;
        sVar6 = -1;
        *(ushort *)&pTVar3[1].s7 = uVar2 | 4;
        iVar5 = (int)sVar1 * iVar5 >> 8;
        D3_StopSound(o,snd_handle);
      }
      snd_handle = sVar6;
      if ((flag == 0) &&
         (lVar4 = Distance3D((int)(o->pos).vx,(int)(o->pos).vy,(int)(o->pos).vz,(int)_DAT_800b1c64,
                             (int)_DAT_800b1c66,(int)_DAT_800b1c68), snd_handle = sVar6, lVar4 < 400
         )) {
        D3_SetCollBits(o,8);
        snd_handle = sVar6;
      }
    }
    else {
      if (iVar5 == 0) {
        sVar6 = o[1].pos.vz;
        iVar5 = (int)Scr_TicksPerSecond;
        *(ushort *)&pTVar3[1].s7 = uVar2 & 0xfffb;
        iVar5 = (int)sVar6 * iVar5 >> 8;
        snd_handle = D3_UpdateSound(o,0,snd_handle);
      }
    }
    if (value == -0x2000) {
      snd_handle = D3_UpdateSound(o,0,snd_handle);
      *(ushort *)&pTVar3[1].s7 = *(ushort *)&pTVar3[1].s7 & 0xfffb;
      if ((flag == 0) &&
         (lVar4 = Distance3D((int)(o->pos).vx,(int)(o->pos).vy,(int)(o->pos).vz,(int)_DAT_800b1c64,
                             (int)_DAT_800b1c66,(int)_DAT_800b1c68), lVar4 < 400)) {
        D3_SetCollBits(o,8);
      }
    }
    if (value == -0x4000) {
      D3_StopSound(o,snd_handle);
      *(ushort *)&pTVar3[1].s7 = *(ushort *)&pTVar3[1].s7 | 4;
      D3_ClearCollBits(o,8);
      snd_handle = -1;
      TaskCurrent->enable = 0;
    }
    iVar5 = iVar5 + -1;
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_SmokeSetBBox(struct _D3_OBJECT *o /*$s1*/)
 // line 2923, offset 0x8004bf60
	/* begin block 1 */
		// Start line: 2924
		// Start offset: 0x8004BF60
		// Variables:
	// 		struct CBASE_5fake mr; // stack offset -96
	// 		struct CBASE_7fake min; // stack offset -64
	// 		struct CBASE_7fake max; // stack offset -56
	// 		struct CBASE_7fake trans; // stack offset -48
	// 		struct CBASE_6fake dummy; // stack offset -40
	// 		long f; // stack offset -24
	// 		long i; // $a1
	/* end block 1 */
	// End offset: 0x8004C1B8
	// End Line: 2961

	/* begin block 2 */
		// Start line: 7071
	/* end block 2 */
	// End Line: 7072

/* WARNING: Could not reconcile some variable overlaps */

void CB_SmokeSetBBox(_D3_OBJECT *o)

{
  undefined4 in_zero;
  undefined4 in_at;
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  int local_20;
  undefined4 local_18;
  
  local_40 = DAT_800ad690;
  local_3c = PTR_DAT_800ad694;
  local_38 = PTR_DAT_800ad698;
  local_34 = DAT_800ad69c;
  memset(&local_30,0,8);
  D3_SetBox(o,(int)(short)local_40,(int)local_40._2_2_,(int)(short)local_3c,(int)(short)local_38,
            (int)local_38._2_2_,(int)(short)local_34);
  setCopReg(2,in_zero,local_30);
  setCopReg(2,in_at,local_2c);
  copFunction(2,0x486012);
  local_4c = getCopReg(2,0x19);
  local_48 = getCopReg(2,0x1a);
  local_44 = getCopReg(2,0x1b);
  RotMatrix((short *)&o->rot,(undefined2 *)&local_60);
  setCopControlWord(2,0x2800,local_4c);
  setCopControlWord(2,0x3000,local_48);
  setCopControlWord(2,0x3800,local_44);
  setCopControlWord(2,0,local_60);
  setCopControlWord(2,0x800,local_5c);
  setCopControlWord(2,0x1000,local_58);
  setCopControlWord(2,0x1800,local_54);
  setCopControlWord(2,0x2000,local_50);
  iVar3 = 0;
  iVar2 = 0x4c;
  local_3c._0_2_ = 10000;
  local_40._2_2_ = 10000;
  local_40._0_2_ = 10000;
  local_34._0_2_ = -10000;
  local_38._2_2_ = -10000;
  local_38._0_2_ = -10000;
  do {
    puVar1 = (undefined4 *)((int)&o->next + iVar2);
    setCopReg(2,in_zero,*puVar1);
    setCopReg(2,in_at,puVar1[1]);
    copFunction(2,0x480012);
    local_28 = getCopReg(2,0x19);
    local_24 = getCopReg(2,0x1a);
    local_20 = getCopReg(2,0x1b);
    local_18 = getCopControlWord(2,0xf800);
    if (local_28 < (int)(short)local_40) {
      local_40._0_2_ = (short)local_28;
    }
    if ((int)(short)local_38 < local_28) {
      local_38._0_2_ = (short)local_28;
    }
    if (local_24 < (int)local_40._2_2_) {
      local_40._2_2_ = (short)local_24;
    }
    if ((int)local_38._2_2_ < local_24) {
      local_38._2_2_ = (short)local_24;
    }
    if (local_20 < (int)(short)local_3c) {
      local_3c._0_2_ = (short)local_20;
    }
    if ((int)(short)local_34 < local_20) {
      local_34._0_2_ = (short)local_20;
    }
    iVar3 = iVar3 + 1;
    iVar2 = iVar2 + 8;
  } while (iVar3 < 8);
  setCopControlWord(2,0x2800,Cam_Matrix.t[0]);
  setCopControlWord(2,0x3000,Cam_Matrix.t[1]);
  setCopControlWord(2,0x3800,Cam_Matrix.t[2]);
  setCopControlWord(2,0,Cam_Matrix.m[0]._0_4_);
  setCopControlWord(2,0x800,Cam_Matrix.m._4_4_);
  setCopControlWord(2,0x1000,Cam_Matrix.m[1]._2_4_);
  setCopControlWord(2,0x1800,Cam_Matrix.m[2]._0_4_);
  setCopControlWord(2,0x2000,Cam_Matrix._16_4_);
  D3_SetBox(o,(int)(short)local_40,(int)local_40._2_2_,(int)(short)local_3c,(int)(short)local_38,
            (int)local_38._2_2_,(int)(short)local_34);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_JetDeau(struct _D3_OBJECT *o /*$s4*/)
 // line 2973, offset 0x8004c244
	/* begin block 1 */
		// Start line: 2974
		// Start offset: 0x8004C244
		// Variables:
	// 		struct _D3_OBJECT *child; // $s0
	// 		struct TASK *stream; // $s6
	// 		struct CBASE_7fake spd; // stack offset -56
	// 		long i; // $s0
	// 		long len; // $s1
	// 		long size; // $s2
	// 		long fx_handle; // $s3
	// 		long unefois; // $s1

		/* begin block 1.1 */
			// Start line: 2993
			// Start offset: 0x8004C2CC
			// Variables:
		// 		struct M_OBJECT *mo; // $s2
		// 		struct M_OBJECT *mobro; // $s5
		// 		struct _D3_OBJECT *bro; // $s7
		// 		struct CBASE_7fake pos; // stack offset -48
		/* end block 1.1 */
		// End offset: 0x8004C66C
		// End Line: 3098
	/* end block 1 */
	// End offset: 0x8004C7A8
	// End Line: 3137

	/* begin block 2 */
		// Start line: 7189
	/* end block 2 */
	// End Line: 7190

void CB_JetDeau(_D3_OBJECT *o)

{
  short sVar1;
  ushort uVar2;
  bool bVar3;
  short snd_handle;
  TASK *t;
  _D3_OBJECT *p_Var4;
  _D3_OBJECT *p_Var5;
  long value;
  uint uVar6;
  int iVar7;
  M_OBJECT *obj;
  void *pvVar8;
  _D3_OBJECT *o_00;
  undefined2 local_38;
  undefined2 local_36;
  undefined2 local_34;
  undefined2 local_32;
  
  memset(&local_38,0,8);
  value = 0x14;
  iVar7 = 8;
  p_Var5 = o->child;
  snd_handle = -1;
  while ((p_Var5 != (_D3_OBJECT *)0x0 && (*(char *)((int)&p_Var5[1].pos.vx + 1) != '\0'))) {
    p_Var5 = p_Var5->next;
  }
  if (*(int *)&o[1].last_pos != 1) {
    CB_StreamSetSpeed(o,200,0x14);
    t = SFX_StreamGeiser((char)o + ',',200);
    *(TASK **)&TaskCurrent->local = t;
    while (snd_handle = D3_UpdateSound(o,0,snd_handle), (Scts_Interruptors & (int)o[1].pos.vz) == 0)
    {
      Task_Next();
    }
    uVar6 = 0;
    do {
      snd_handle = D3_UpdateSound(o,0,snd_handle);
      if ((uVar6 & 1) == 0) {
        value = value + -1;
      }
      if (uVar6 == ((int)uVar6 / 6) * 6) {
        iVar7 = iVar7 + -1;
      }
      CB_StreamSetSpeed(o,200,value);
      *(undefined2 *)&t[1].destructor = local_38;
      *(undefined2 *)((int)&t[1].destructor + 2) = local_36;
      uVar6 = uVar6 + 1;
      *(undefined2 *)((int)&t[1].s7 + 2) = (short)iVar7;
      *(undefined2 *)&t[1].local = local_34;
      Task_Next();
    } while (iVar7 != 0);
    D3_StopSound(o,snd_handle);
    Task_Kill(t);
    Scts_Interruptors = Scts_Interruptors | (int)o[1].pos.pad;
    return;
  }
  p_Var4 = o->father;
  obj = (M_OBJECT *)p_Var4->description;
  if (p_Var4->next != (_D3_OBJECT *)0x0) {
    o_00 = p_Var4->next;
  }
  if (p_Var4->prec != (_D3_OBJECT *)0x0) {
    o_00 = p_Var4->prec;
  }
  *(undefined *)((int)&p_Var4[1].pos.vx + 1) = 1;
  pvVar8 = o_00->description;
  *(undefined *)((int)&o_00[1].pos.vx + 1) = 1;
  *(undefined *)((int)&o[1].pos.vx + 1) = 0xee;
  CB_StreamSetSpeed(o,200,0x18);
  Boxes_GetCenter(o,0xd0);
  local_32 = 1;
  t = SFX_StreamGeiser((char)o + ',',200);
  *(TASK **)&TaskCurrent->local = t;
  D3_ClearCollBits(o,(long)&DAT_00002009);
  *(ushort *)&t[1].s7 = *(ushort *)&t[1].s7 | 4;
  do {
    Manim_ForceAnim(obj,0);
    (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
    *(ushort *)((int)pvVar8 + 0x28) = *(ushort *)((int)pvVar8 + 0x28) & 0xfffe;
    sVar1 = o[1].pos.vz;
    bVar3 = true;
    while (((Scts_Interruptors & (int)sVar1) == 0 || (p_Var5 != (_D3_OBJECT *)0x0))) {
      Task_Next();
      if (((Scts_Interruptors & (int)o[1].pos.vz) != 0) &&
         ((bVar3 && (((obj->Env).Obj.normal_top.vx & 1U) == 0)))) {
        snd_handle = D3_UpdateSound(o->father,0,snd_handle);
        (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx | 1;
        *(ushort *)((int)pvVar8 + 0x28) = *(ushort *)((int)pvVar8 + 0x28) | 1;
        uVar2 = (obj->Env).Obj.normal_top.vx;
        while ((uVar2 & 0x4000) == 0) {
          snd_handle = D3_UpdateSound(o->father,0,snd_handle);
          Task_Next();
          uVar2 = (obj->Env).Obj.normal_top.vx;
        }
        D3_StopSound(o->father,snd_handle);
        bVar3 = false;
        (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
      }
      p_Var5 = o->child;
      while ((p_Var5 != (_D3_OBJECT *)0x0 && (*(char *)((int)&p_Var5[1].pos.vx + 1) == '\0'))) {
        p_Var5 = p_Var5->next;
      }
      if (!bVar3) {
        if ((*(ushort *)((int)pvVar8 + 0x22) & 1) != 0) {
          D3_PlaySound(o_00,0);
        }
        if ((*(ushort *)((int)pvVar8 + 0x22) & 2) != 0) {
          D3_PlaySound(o_00,1);
        }
      }
      sVar1 = o[1].pos.vz;
    }
    while (((obj->Env).Obj.normal_top.vx & 1U) != 0) {
      Task_Next();
    }
    uVar6 = 1;
    *(ushort *)&t[1].s7 = *(ushort *)&t[1].s7 & 0xfffb;
    D3_SetCollBits(o,(long)&DAT_00002009);
    do {
      if ((*(ushort *)((int)pvVar8 + 0x22) & 1) != 0) {
        D3_PlaySound(o_00,0);
      }
      if ((*(ushort *)((int)pvVar8 + 0x22) & 2) != 0) {
        D3_PlaySound(o_00,1);
      }
      if ((Scts_Interruptors & (int)o[1].pos.vz) == 0) break;
      if (0x712 < (int)uVar6) {
        Manim_SetAnim(obj,1);
      }
      if ((uVar6 & 0xf) == 0) {
        Impact_Petrole(0xd0,((((uint)(ushort)(o->rot).vz & 0xfff) >> 10) + 1) * 0x10000 | 5);
      }
      snd_handle = D3_UpdateSound(o,0,snd_handle);
      Task_Next();
      uVar6 = uVar6 + 1;
    } while ((int)uVar6 < 0x690);
    *(ushort *)((int)pvVar8 + 0x28) = *(ushort *)((int)pvVar8 + 0x28) & 0xfffe;
    D3_StopSound(o,snd_handle);
    Pvl_ClearStateBits(o->father->father,2);
    Scts_Interruptors = Scts_Interruptors & ~(int)o[1].pos.vz;
    *(ushort *)&t[1].s7 = *(ushort *)&t[1].s7 | 4;
    D3_ClearCollBits(o,(long)&DAT_00002009);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_StreamSetSpeed(struct _D3_OBJECT *o /*$s0*/, struct CBASE_7fake *spd /*$s2*/, long value /*$s1*/)
 // line 3140, offset 0x8004c7d8
	/* begin block 1 */
		// Start line: 7602
	/* end block 1 */
	// End Line: 7603

void CB_StreamSetSpeed(_D3_OBJECT *o,undefined spd,long value)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  undefined3 in_register_00000015;
  undefined2 *puVar4;
  
  puVar4 = (undefined2 *)CONCAT31(in_register_00000015,spd);
  iVar2 = rsin((int)(o->rot).vz);
  puVar4[1] = (short)(iVar2 * value >> 0xc);
  uVar3 = SEXT24((o->rot).vy);
  if (uVar3 == 0) {
    iVar2 = rcos((int)(o->rot).vz);
    *puVar4 = (short)(iVar2 * value >> 0xc);
    iVar2 = rsin((int)(o->rot).vx);
    uVar1 = (undefined2)(iVar2 * value >> 0xc);
  }
  else {
    iVar2 = rcos(uVar3);
    *puVar4 = (short)(iVar2 * value >> 0xc);
    iVar2 = rsin((int)(o->rot).vy);
    uVar1 = (undefined2)(-(iVar2 * value) >> 0xc);
  }
  puVar4[2] = uVar1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_PushedIfInterrupt(struct _D3_OBJECT *o /*$s1*/)
 // line 3169, offset 0x8004c8a8
	/* begin block 1 */
		// Start line: 3170
		// Start offset: 0x8004C8A8
		// Variables:
	// 		struct _ZONE *z; // $s2

		/* begin block 1.1 */
			// Start line: 3185
			// Start offset: 0x8004C91C
			// Variables:
		// 		short x; // $v1
		// 		short y; // $a1
		/* end block 1.1 */
		// End offset: 0x8004C9B0
		// End Line: 3204
	/* end block 1 */
	// End offset: 0x8004C9C0
	// End Line: 3210

	/* begin block 2 */
		// Start line: 7660
	/* end block 2 */
	// End Line: 7661

void CB_PushedIfInterrupt(_D3_OBJECT *o)

{
  _ZONE *p_Var1;
  int iVar2;
  int iVar3;
  
  p_Var1 = Zone_GetObjectZone(o);
  iVar3 = (int)o[1].last_pos.vy;
  D3_ClearCollBits(o,0x40);
  do {
    if ((Scts_Interruptors & (int)o[1].pos.vz) != 0) {
      D3_SetCollBits(o,0x40);
    }
    if ((o->collision_mode & 0x40U) != 0) {
      if ((((iVar3 == 0) || (iVar3 == 2)) &&
          ((iVar2 = (int)(o->pos).vx, (int)p_Var1->x2 + -2 <= iVar2 + (int)*(short *)&o->b_step ||
           (iVar2 + (int)(o->b_box).vx < (int)p_Var1->x1 + 2)))) ||
         ((iVar3 - 1U < 2 &&
          ((iVar2 = (int)(o->pos).vy, (int)p_Var1->y2 <= iVar2 + (int)(o->b_box).vy ||
           (iVar2 + (int)*(short *)((int)&o->b_sunk + 2) < (int)p_Var1->y1)))))) {
        Scts_Interruptors = Scts_Interruptors | (int)o[1].pos.pad;
        return;
      }
    }
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_Stalagtite(struct _D3_OBJECT *o /*$s0*/)
 // line 3222, offset 0x8004c9f4
	/* begin block 1 */
		// Start line: 7769
	/* end block 1 */
	// End Line: 7770

void CB_Stalagtite(_D3_OBJECT *o)

{
  long lVar1;
  
  D3_ClearCollBits(o,0x80);
  while( true ) {
    if (o->hit_points == 0) {
      D3_SetCollBits(o,0x80);
    }
    lVar1 = Boxes_TestObject(o);
    if (lVar1 != 0) break;
    Task_Next();
  }
  D3_ClearCollBits(o,0x88);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_Dangerous(struct _D3_OBJECT *o /*$s1*/)
 // line 3251, offset 0x8004ca5c
	/* begin block 1 */
		// Start line: 3252
		// Start offset: 0x8004CA5C
		// Variables:
	// 		long cpt; // $s0
	/* end block 1 */
	// End offset: 0x8004CAE0
	// End Line: 3270

	/* begin block 2 */
		// Start line: 7832
	/* end block 2 */
	// End Line: 7833

void CB_Dangerous(_D3_OBJECT *o)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = (int)o[1].pos.pad;
  D3_SetCollBits(o,0x2000);
  uVar1 = Scts_Interruptors & (int)o[1].pos.vz;
  while (uVar1 == 0) {
    if (iVar2 == 0) {
      D3_SetCollBits(o,10);
      iVar2 = (int)o[1].pos.pad;
    }
    else {
      D3_ClearCollBits(o,10);
    }
    iVar2 = iVar2 + -1;
    Task_Next();
    uVar1 = Scts_Interruptors & (int)o[1].pos.vz;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_FireWall(struct _D3_OBJECT *o /*$s1*/)
 // line 3280, offset 0x8004caf4
	/* begin block 1 */
		// Start line: 3281
		// Start offset: 0x8004CAF4
		// Variables:
	// 		struct _D3_OBJECT *child; // $s0
	// 		struct CBASE_7fake pos; // stack offset -32
	// 		short MinZ; // $s3
	// 		long i; // $s0
	// 		long FireSize; // $s2
	// 		struct TASK *FireTask; // $s4

		/* begin block 1.1 */
			// Start line: 3332
			// Start offset: 0x8004CC1C
			// Variables:
		// 		struct _D3_OBJECT *child; // $s3
		/* end block 1.1 */
		// End offset: 0x8004CCD4
		// End Line: 3369
	/* end block 1 */
	// End offset: 0x8004CD08
	// End Line: 3380

	/* begin block 2 */
		// Start line: 7890
	/* end block 2 */
	// End Line: 7891

void CB_FireWall(_D3_OBJECT *o)

{
  short sVar1;
  long lVar2;
  TASK *t;
  _D3_OBJECT *o_00;
  int iVar3;
  int iVar4;
  
  iVar4 = 0x19;
  o_00 = o->child;
  sVar1 = (o->b_box).vz;
  lVar2 = Pvl_TestStateBits(o,0x40);
  t = TaskCurrent;
  if (lVar2 == 0) {
    TaskCurrent->destructor = CB_FireWallDestructor;
    *(_D3_OBJECT **)&t->local = o;
    *(undefined4 *)&o[1].last_pos = 0xffffffff;
    o->hit_points = 1000;
    *(undefined2 *)((int)&o[1].father + 2) = 0;
    *(undefined *)((int)&o[1].pos.vx + 1) = 0xf7;
    D3_SetCollBits(o,3);
    if (o_00 != (_D3_OBJECT *)0x0) {
      D3_ClearCollBits(o_00,3);
    }
    D3_SetHighBoxZ(o,(int)sVar1 + 200);
    t = SFX_StreamFireWall(0xe0);
    while( true ) {
      if (((o->collision_state & 2U) != 0) && (*(char *)((int)o[1].description + 0x99) != -0x11)) {
        o->hit_points = 1000;
      }
      if (o->hit_points < 1) break;
      sVar1 = D3_UpdateSound(o,0x33,o[1].last_pos.vx);
      *(int *)&o[1].last_pos = (int)sVar1;
      Task_Next();
    }
    o_00 = o->child;
    Pvl_SetStateBits(o,0x40);
    do {
      *(undefined2 *)((int)&t[1].s7 + 2) = (short)iVar4;
      iVar4 = iVar4 + -2;
      iVar3 = 0;
      do {
        iVar3 = iVar3 + 1;
        sVar1 = D3_UpdateSound(o,0x33,o[1].last_pos.vx);
        *(int *)&o[1].last_pos = (int)sVar1;
        Task_Next();
      } while (iVar3 < 5);
    } while (0 < iVar4);
    iVar4 = 0x80;
    *(undefined2 *)((int)&t[1].s7 + 2) = 2;
    *(undefined2 *)&t[1].fp = 0xfffe;
    do {
      iVar4 = iVar4 + -3;
      sVar1 = D3_UpdateSound(o,0x33,o[1].last_pos.vx);
      *(int *)&o[1].last_pos = (int)sVar1;
      Task_Next();
    } while (0 < iVar4);
    if (o_00 != (_D3_OBJECT *)0x0) {
      *(undefined *)((int)&o_00[1].pos.vx + 1) = 0xf7;
      D3_SetCollBits(o_00,(long)&DAT_0000200a);
    }
    D3_ClearCollBits(o,(long)&DAT_0000200b);
    Task_Kill(t);
  }
  else {
    D3_ClearCollBits(o,(long)&DAT_0000200b);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_FireWallDestructor(struct TASK *handle /*$a0*/)
 // line 3382, offset 0x8004cd28
	/* begin block 1 */
		// Start line: 3383
		// Start offset: 0x8004CD28
		// Variables:
	// 		struct _D3_OBJECT *o; // $v0
	/* end block 1 */
	// End offset: 0x8004CD50
	// End Line: 3388

	/* begin block 2 */
		// Start line: 8125
	/* end block 2 */
	// End Line: 8126

void CB_FireWallDestructor(TASK *handle)

{
  int wPlayId;
  
  wPlayId = *(int *)((int)handle->local + 0xa0);
  if (-1 < wPlayId) {
    Sound_Stop(wPlayId,0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_WallAhPuch(struct _D3_OBJECT *o /*$s2*/)
 // line 3394, offset 0x8004cd60
	/* begin block 1 */
		// Start line: 3395
		// Start offset: 0x8004CD60
		// Variables:
	// 		struct _D3_OBJECT *child; // $a0
	// 		struct _D3_OBJECT *HiddenWall; // $s0
	// 		long i; // $s1
	// 		long offset; // $s0
	/* end block 1 */
	// End offset: 0x8004CFFC
	// End Line: 3469

	/* begin block 2 */
		// Start line: 8149
	/* end block 2 */
	// End Line: 8150

void CB_WallAhPuch(_D3_OBJECT *o)

{
  short Fx;
  short Fx_00;
  long lVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  _D3_OBJECT *o_00;
  int iVar5;
  
  o_00 = o->child;
  Scts_Interruptors = Scts_Interruptors & ~(int)o[1].pos.vz;
  while ((o_00 != (_D3_OBJECT *)0x0 && (*(char *)((int)&o_00[1].pos.vx + 1) == '\0'))) {
    o_00 = o_00->next;
  }
  o_00->display_mode = o_00->display_mode & 0xffef;
  D3_ClearCollBits(o_00,1);
  while (uVar4 = SEXT24(o[1].pos.vz), (Scts_Interruptors & uVar4) != uVar4) {
    Task_Next();
  }
  iVar5 = 0;
  o_00->display_mode = o_00->display_mode | 0x10;
  D3_SetCollBits(o_00,1);
  do {
    lVar1 = M_rand();
    Fx_00 = (short)(lVar1 % 0x28) + -10;
    iVar2 = rand();
    if (iVar2 == (iVar2 / 10) * 10) {
      Fx = *(short *)((int)&o[1].father + 2);
      if (-1 < Fx) {
        Fx_Play_Sample(Fx,(char)o + ',',0x70,1);
      }
    }
    o_00 = o->child;
    (o->pos).vz = (o->pos).vz - Fx_00;
    while (o_00 != (_D3_OBJECT *)0x0) {
      if (*(char *)((int)&o_00[1].pos.vx + 1) == '\0') {
        (o_00->pos).vz = (o_00->pos).vz - Fx_00;
      }
      o_00 = o_00->next;
    }
    iVar5 = iVar5 + 1;
    Task_Next();
    iVar2 = lVar1 % 0x28 + -5;
  } while (iVar5 < 0x3c);
  iVar5 = 0;
  do {
    o_00 = o->child;
    (o->pos).vz = (o->pos).vz - (short)iVar2;
    while (o_00 != (_D3_OBJECT *)0x0) {
      if (*(char *)((int)&o_00[1].pos.vx + 1) == '\0') {
        (o_00->pos).vz = (o_00->pos).vz - (short)iVar2;
      }
      o_00 = o_00->next;
    }
    iVar3 = rand();
    if (iVar3 == (iVar3 / 10) * 10) {
      Fx_00 = *(short *)((int)&o[1].father + 2);
      if (-1 < Fx_00) {
        Fx_Play_Sample(Fx_00,(char)o + ',',0x70,1);
      }
    }
    iVar5 = iVar5 + 1;
    Task_Next();
    iVar2 = iVar2 + 5;
  } while (iVar5 < 0x3c);
  o_00 = o->child;
  o->display_mode = o->display_mode & 0xffef;
  while (o_00 != (_D3_OBJECT *)0x0) {
    if (*(char *)((int)&o_00[1].pos.vx + 1) == '\0') {
      o_00->display_mode = o_00->display_mode & 0xffef;
    }
    o_00 = o_00->next;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_GreenPearl(struct _D3_OBJECT *o /*$s1*/)
 // line 3474, offset 0x8004d01c
	/* begin block 1 */
		// Start line: 3475
		// Start offset: 0x8004D01C
		// Variables:
	// 		long i; // $s0
	// 		long handle; // $s2
	// 		struct CBASE_8fake col; // stack offset -24
	/* end block 1 */
	// End offset: 0x8004D1E0
	// End Line: 3529

	/* begin block 2 */
		// Start line: 8351
	/* end block 2 */
	// End Line: 8352

void CB_GreenPearl(_D3_OBJECT *o)

{
  bool bVar1;
  short sVar2;
  long lVar3;
  uint uVar4;
  int iVar5;
  
  o->display_mode = o->display_mode & 0xffef;
  D3_ClearCollBits(o,1);
  Invent_RemoveUsedKey(-0x80000000,1);
  uVar4 = SEXT24(o[1].pos.pad);
  if ((Scts_Interruptors & uVar4) != uVar4) {
    while (lVar3 = Task_EventRead(TaskCurrent), lVar3 != 6) {
      Task_Next();
    }
    Scts_Interruptors = Scts_Interruptors | (int)o[1].pos.pad;
  }
  Zone_DeleteObject(o);
  o->display_mode = o->display_mode | 0x10;
  while (lVar3 = CB_PearlRSonsVisible(o), lVar3 == 0) {
    Task_Next();
  }
  sVar2 = Fx_Play(0x29,(char)o + ',');
  iVar5 = 1;
  do {
    (o->pos).vz = (o->pos).vz + 3;
    (o->rot).vz = (o->rot).vz + 10;
    Task_Next();
    bVar1 = iVar5 < 100;
    iVar5 = iVar5 + 1;
  } while (bVar1);
  Sound_Stop((int)sVar2,0);
  Scts_Interruptors = Scts_Interruptors | (uint)(ushort)o[1].last_pos.vy;
  CB_PearlSetSonsInvisible(o);
  SFX_ShockWave(5,(char)o + ',',0xe8,1);
  iVar5 = 1;
  do {
    (o->pos).vz = (o->pos).vz + 3;
    (o->rot).vz = (o->rot).vz + 10;
    Task_Next();
    bVar1 = iVar5 < 0x32;
    iVar5 = iVar5 + 1;
  } while (bVar1);
  o->display_mode = o->display_mode & 0xffef;
  do {
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// long /*$ra*/ CB_PearlRSonsVisible(struct _D3_OBJECT *o /*$a0*/)
 // line 3531, offset 0x8004d1e0
	/* begin block 1 */
		// Start line: 3533
		// Start offset: 0x8004D1E0
		// Variables:
	// 		struct _D3_OBJECT *child; // $a0
	// 		struct _D3_OBJECT *bchild; // $v1
	/* end block 1 */
	// End offset: 0x8004D234
	// End Line: 3552

	/* begin block 2 */
		// Start line: 8484
	/* end block 2 */
	// End Line: 8485

long CB_PearlRSonsVisible(_D3_OBJECT *o)

{
  _D3_OBJECT *p_Var1;
  _D3_OBJECT *p_Var2;
  
  p_Var2 = o->child;
  do {
    if (p_Var2 == (_D3_OBJECT *)0x0) {
      return 1;
    }
    p_Var1 = p_Var2->child;
    while (p_Var1 != (_D3_OBJECT *)0x0) {
      if ((p_Var1->display_mode & 0x10U) == 0) {
        return 0;
      }
      p_Var1 = p_Var1->next;
    }
    p_Var2 = p_Var2->next;
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_PearlSetSonsInvisible(struct _D3_OBJECT *o /*$a0*/)
 // line 3554, offset 0x8004d244
	/* begin block 1 */
		// Start line: 3556
		// Start offset: 0x8004D244
		// Variables:
	// 		struct _D3_OBJECT *child; // $a0
	// 		struct _D3_OBJECT *bchild; // $v1
	/* end block 1 */
	// End offset: 0x8004D294
	// End Line: 3571

	/* begin block 2 */
		// Start line: 8530
	/* end block 2 */
	// End Line: 8531

void CB_PearlSetSonsInvisible(_D3_OBJECT *o)

{
  _D3_OBJECT *p_Var1;
  _D3_OBJECT *p_Var2;
  
  p_Var2 = o->child;
  while (p_Var2 != (_D3_OBJECT *)0x0) {
    p_Var1 = p_Var2->child;
    while (p_Var1 != (_D3_OBJECT *)0x0) {
      p_Var1->display_mode = p_Var1->display_mode & 0xffef;
      p_Var1 = p_Var1->next;
    }
    p_Var2 = p_Var2->next;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_Laser39(struct _D3_OBJECT *o /*$s3*/)
 // line 3577, offset 0x8004d29c
	/* begin block 1 */
		// Start line: 3578
		// Start offset: 0x8004D29C
		// Variables:
	// 		long n_child; // $s2
	// 		long n; // $s1
	// 		long step; // $v0
	// 		long cpt; // $s0
	// 		struct CBASE_8fake col; // stack offset -40
	// 		struct CBASE_8fake off; // stack offset -32
	// 		struct _ZONE *zCam; // $s4
	/* end block 1 */
	// End offset: 0x8004D3EC
	// End Line: 3631

	/* begin block 2 */
		// Start line: 8575
	/* end block 2 */
	// End Line: 8576

void CB_Laser39(_D3_OBJECT *o)

{
  _ZONE *t;
  long lVar1;
  int iVar2;
  int iVar3;
  undefined auStack32 [8];
  
  iVar3 = 4;
  memset(auStack32,0,4);
  iVar2 = 0;
  t = Zone_GetObjectZone(o->father);
  Zone_GetObjectZone(o);
  Tmd_ChangeColor((char)o->description,0xd8);
  do {
    lVar1 = CB_Laser39GetNChild(o);
    if (iVar2 < 1) {
      D3_PlaySound(o,0);
      iVar2 = rand();
      iVar2 = iVar2 % 0x3c;
      Tmd_ChangeColor((char)o->description,0xe0);
      Task_Sleep(2);
      Tmd_ChangeColor((char)o->description,0xd8);
    }
    if (lVar1 != iVar3) {
      if ((((lVar1 == 2) || (lVar1 == 0)) && (t != (_ZONE *)0x0)) && (-1 < t->camera)) {
        Track_SetMode(10,(long)t);
      }
      Tmd_ChangeColor((char)o->description,0xd8);
      iVar3 = lVar1;
    }
    iVar2 = iVar2 + -1;
    Task_Next();
  } while (iVar3 != 0);
  o->display_mode = o->display_mode & 0xffef;
  D3_ClearCollBits(o,1);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ CB_Laser39GetNChild(struct _D3_OBJECT *o /*$a0*/)
 // line 3634, offset 0x8004d420
	/* begin block 1 */
		// Start line: 3636
		// Start offset: 0x8004D420
		// Variables:
	// 		struct _D3_OBJECT *child; // $v1
	// 		long n; // $a0
	/* end block 1 */
	// End offset: 0x8004D454
	// End Line: 3647

	/* begin block 2 */
		// Start line: 8696
	/* end block 2 */
	// End Line: 8697

long CB_Laser39GetNChild(_D3_OBJECT *o)

{
  _D3_OBJECT *p_Var1;
  int iVar2;
  
  p_Var1 = o->child;
  iVar2 = 0;
  while (p_Var1 != (_D3_OBJECT *)0x0) {
    if (0 < p_Var1->hit_points) {
      iVar2 = iVar2 + 1;
    }
    p_Var1 = p_Var1->next;
  }
  return iVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_Grue28(struct _D3_OBJECT *o /*$s0*/)
 // line 3655, offset 0x8004d45c
	/* begin block 1 */
		// Start line: 3656
		// Start offset: 0x8004D45C
		// Variables:
	// 		struct CBASE_7fake rot; // stack offset -16
	/* end block 1 */
	// End offset: 0x8004D500
	// End Line: 3672

	/* begin block 2 */
		// Start line: 8737
	/* end block 2 */
	// End Line: 8738

void CB_Grue28(_D3_OBJECT *o)

{
  TASK *pTVar1;
  long lVar2;
  _D3_OBJECT *obj;
  undefined auStack16 [4];
  short local_c;
  
  memset(auStack16,0,8);
  pTVar1 = TaskCurrent;
  TaskCurrent->destructor = CB_Grue28Destructor;
  *(_D3_OBJECT **)&pTVar1->local = o;
  lVar2 = Pvl_TestStateBits(o,1);
  if (lVar2 != 0) {
    local_c = Grue_TabRot[(int)o[1].pos.vz] - (o->rot).vz;
    obj = o->child;
    (o->rot).vz = Grue_TabRot[(int)o[1].pos.vz];
    D3_RotList(obj,0xf0);
  }
  do {
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_Grue28Destructor(struct TASK *handle /*$a0*/)
 // line 3674, offset 0x8004d500
	/* begin block 1 */
		// Start line: 3675
		// Start offset: 0x8004D500
		// Variables:
	// 		struct _D3_OBJECT *o; // $s0
	// 		struct CBASE_7fake rot; // stack offset -16
	/* end block 1 */
	// End offset: 0x8004D500
	// End Line: 3675

	/* begin block 2 */
		// Start line: 8781
	/* end block 2 */
	// End Line: 8782

void CB_Grue28Destructor(TASK *handle)

{
  _D3_OBJECT *o;
  undefined auStack16 [8];
  
  o = (_D3_OBJECT *)handle->local;
  memset(auStack16,0,8);
  Pvl_SetStateBits(o,1);
  Grue_TabRot[(int)o[1].pos.vz] = (o->rot).vz;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_LoopingSound(struct _D3_OBJECT *o /*$s0*/)
 // line 3686, offset 0x8004d558
	/* begin block 1 */
		// Start line: 8805
	/* end block 1 */
	// End Line: 8806

void CB_LoopingSound(_D3_OBJECT *o)

{
  TASK *pTVar1;
  short sVar2;
  uint uVar3;
  
  pTVar1 = TaskCurrent;
  TaskCurrent->destructor = CB_LoopingSoundDestructor;
  *(_D3_OBJECT **)&pTVar1->local = o;
  *(undefined4 *)&o[1].last_pos = 0xffffffff;
  do {
    uVar3 = SEXT24(o[1].pos.vz);
    if (((Scts_Interruptors & uVar3) == uVar3) && (-1 < *(short *)((int)&o[1].father + 2))) {
      sVar2 = D3_UpdateSound(o,0,o[1].last_pos.vx);
      *(int *)&o[1].last_pos = (int)sVar2;
    }
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_LoopingSoundDestructor(struct TASK *handle /*$a0*/)
 // line 3705, offset 0x8004d5dc
	/* begin block 1 */
		// Start line: 3706
		// Start offset: 0x8004D5DC
		// Variables:
	// 		struct _D3_OBJECT *o; // $a0
	/* end block 1 */
	// End offset: 0x8004D608
	// End Line: 3711

	/* begin block 2 */
		// Start line: 8852
	/* end block 2 */
	// End Line: 8853

void CB_LoopingSoundDestructor(TASK *handle)

{
  _D3_OBJECT *o;
  
  o = (_D3_OBJECT *)handle->local;
  if (-1 < *(int *)&o[1].last_pos) {
    D3_StopSound(o,o[1].last_pos.vx);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_FloatingTask()
 // line 3716, offset 0x8004d618
	/* begin block 1 */
		// Start line: 3717
		// Start offset: 0x8004D618
		// Variables:
	// 		struct _D3_OBJECT *o; // $s0
	// 		long angX; // $s3
	// 		long angY; // $s4
	// 		long inter; // $s1
	// 		long sensX; // stack offset -40
	// 		long sensY; // stack offset -36
	// 		long Player_WasON; // $s2
	/* end block 1 */
	// End offset: 0x8004D7D8
	// End Line: 3790

	/* begin block 2 */
		// Start line: 8875
	/* end block 2 */
	// End Line: 8876

/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void CB_FloatingTask(void)

{
  bool bVar1;
  bool bVar2;
  short sVar3;
  long lVar4;
  int iVar5;
  void *pvVar6;
  int angle;
  long unaff_s3;
  long unaff_s4;
  int local_28;
  int local_24;
  
  pvVar6 = TaskCurrent->local;
  bVar2 = false;
  angle = (int)((uint)*(ushort *)((int)pvVar6 + 0x9e) << 0x10) >> 0x18;
  do {
    lVar4 = Task_EventRead(TaskCurrent);
    if (lVar4 == 1) {
      bVar2 = true;
    }
    else {
      if (bVar2) {
        iVar5 = *(int *)((int)pvVar6 + 0x3c);
        bVar2 = false;
        while (iVar5 != 0) {
          if (*(short *)((int)pvVar6 + 0x3c) < 0) {
            sVar3 = *(short *)((int)pvVar6 + 0x3c) + 1;
LAB_8004d6b0:
            *(short *)((int)pvVar6 + 0x3c) = sVar3;
          }
          else {
            sVar3 = *(short *)((int)pvVar6 + 0x3c) + -1;
            if (0 < *(short *)((int)pvVar6 + 0x3c)) goto LAB_8004d6b0;
          }
          if (*(short *)((int)pvVar6 + 0x3e) < 0) {
            sVar3 = *(short *)((int)pvVar6 + 0x3e) + 1;
LAB_8004d6d4:
            *(short *)((int)pvVar6 + 0x3e) = sVar3;
          }
          else {
            sVar3 = *(short *)((int)pvVar6 + 0x3e) + -1;
            if (0 < *(short *)((int)pvVar6 + 0x3e)) goto LAB_8004d6d4;
          }
          Task_Next();
          iVar5 = *(int *)((int)pvVar6 + 0x3c);
        }
      }
      if (angle != 0) {
        if (*(short *)((int)pvVar6 + 0x9a) != 2) {
          if ((int)*(short *)((int)pvVar6 + 0x3c) == 0) {
            unaff_s3 = CB_InitAngle(angle,1,&local_28);
          }
          else {
            if (((int)*(short *)((int)pvVar6 + 0x3c) == unaff_s3) &&
               (bVar1 = local_28 < 0, local_28 = -1, bVar1)) {
              local_28 = 1;
            }
          }
          *(short *)((int)pvVar6 + 0x3c) = *(short *)((int)pvVar6 + 0x3c) + (short)local_28;
        }
        if (*(short *)((int)pvVar6 + 0x9a) != 1) {
          if ((int)*(short *)((int)pvVar6 + 0x3e) == 0) {
            unaff_s4 = CB_InitAngle(angle,1,&local_24);
          }
          else {
            if (((int)*(short *)((int)pvVar6 + 0x3e) == unaff_s4) &&
               (bVar1 = local_24 < 0, local_24 = -1, bVar1)) {
              local_24 = 1;
            }
          }
          *(short *)((int)pvVar6 + 0x3e) = *(short *)((int)pvVar6 + 0x3e) + (short)local_24;
        }
      }
    }
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_Float(struct _D3_OBJECT *ot /*$s1*/, struct _D3_OBJECT *oc /*$s0*/)
 // line 3793, offset 0x8004d7d8
	/* begin block 1 */
		// Start line: 3794
		// Start offset: 0x8004D7D8
		// Variables:
	// 		long lenX; // $v0
	// 		long lenY; // $v0
	// 		long posX; // $a0
	// 		long posY; // $a0
	// 		long ang_total; // $a2
	/* end block 1 */
	// End offset: 0x8004D9A8
	// End Line: 3841

	/* begin block 2 */
		// Start line: 9094
	/* end block 2 */
	// End Line: 9095

void CB_Float(_D3_OBJECT *ot,_D3_OBJECT *oc)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  Task_EventExec(oc->handle,1,0);
  iVar3 = (((int)((uint)(ushort)oc[1].pos.vz << 0x10) >> 0x18) * 0x400) / 0x5a;
  sVar4 = oc[1].pos.vy;
  if (sVar4 != 1) {
    iVar5 = (int)(ot->pos).vx - (int)(oc->pos).vx;
    iVar6 = iVar5;
    if (iVar5 < 0) {
      iVar6 = -iVar5;
    }
    iVar6 = iVar6 * iVar3;
    uVar1 = (int)*(short *)&oc->b_step - (int)(oc->b_box).vx;
    iVar2 = (int)(uVar1 + (uVar1 >> 0x1f)) >> 1;
    iVar7 = iVar6 / iVar2;
    if (iVar2 == 0) {
      trap(0x1c00);
    }
    if ((iVar2 == -1) && (iVar6 == -0x80000000)) {
      trap(0x1800);
    }
    if (iVar5 < 0) {
      if (-iVar7 < (int)(oc->rot).vy) {
        (oc->rot).vy = (oc->rot).vy + -4;
      }
    }
    else {
      if ((int)(oc->rot).vy < iVar7) {
        (oc->rot).vy = (oc->rot).vy + 4;
      }
    }
    sVar4 = oc[1].pos.vy;
  }
  if (sVar4 != 2) {
    iVar5 = (int)(ot->pos).vy - (int)(oc->pos).vy;
    iVar6 = iVar5;
    if (iVar5 < 0) {
      iVar6 = -iVar5;
    }
    iVar6 = iVar6 * iVar3;
    uVar1 = (int)*(short *)((int)&oc->b_step + 2) - (int)*(short *)((int)&oc->b_sunk + 2);
    iVar3 = (int)(uVar1 + (uVar1 >> 0x1f)) >> 1;
    iVar2 = iVar6 / iVar3;
    if (iVar3 == 0) {
      trap(0x1c00);
    }
    if ((iVar3 == -1) && (iVar6 == -0x80000000)) {
      trap(0x1800);
    }
    if (iVar5 < 0) {
      if ((int)(oc->rot).vx < iVar2) {
        (oc->rot).vx = (oc->rot).vx + 4;
      }
    }
    else {
      if (-iVar2 < (int)(oc->rot).vx) {
        (oc->rot).vx = (oc->rot).vx + -4;
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_Float4aWhile(struct _D3_OBJECT *o /*$s2*/, short angle /*$a1*/, short time /*$s7*/, short speed /*$a3*/)
 // line 3845, offset 0x8004d9bc
	/* begin block 1 */
		// Start line: 3846
		// Start offset: 0x8004D9BC
		// Variables:
	// 		long angX; // $s0
	// 		long angY; // $s1
	// 		long sensX; // stack offset -56
	// 		long sensY; // stack offset -52
	// 		long rotX; // stack offset -48
	// 		long rotY; // $fp
	/* end block 1 */
	// End offset: 0x8004DAEC
	// End Line: 3897

	/* begin block 2 */
		// Start line: 9212
	/* end block 2 */
	// End Line: 9213

/* WARNING: Could not reconcile some variable overlaps */

void CB_Float4aWhile(_D3_OBJECT *o,short angle,short time,short speed)

{
  short sVar1;
  int iVar2;
  long unaff_s0;
  long unaff_s1;
  int speed_00;
  int iVar3;
  int local_38;
  int local_34;
  int local_30;
  
  iVar3 = 399;
  speed_00 = (int)speed;
  local_30 = (int)(o->rot).vx;
  sVar1 = (o->rot).vy;
  do {
    iVar2 = (int)(o->rot).vx;
    if (iVar2 == local_30) {
      unaff_s0 = CB_InitAngle((int)angle,speed_00,&local_38);
    }
    else {
      if (unaff_s0 < 0) {
        if (iVar2 < unaff_s0) {
          local_38 = speed_00;
        }
      }
      else {
        if (unaff_s0 < iVar2) {
          local_38 = -speed_00;
        }
      }
    }
    iVar2 = (int)(o->rot).vy;
    (o->rot).vx = (o->rot).vx + (short)local_38;
    if (iVar2 == (int)sVar1) {
      unaff_s1 = CB_InitAngle((int)angle,speed_00,&local_34);
    }
    else {
      if (unaff_s1 < 0) {
        if (iVar2 <= unaff_s1) {
          local_34 = speed_00;
        }
      }
      else {
        if (unaff_s1 <= iVar2) {
          local_34 = -speed_00;
        }
      }
    }
    (o->rot).vy = (o->rot).vy + (short)local_34;
    Task_Next();
    iVar3 = iVar3 + -1;
  } while (iVar3 * 0x10000 >> 0x10 != -1);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ CB_InitAngle(long angle /*$s0*/, long speed /*$s2*/, long *sens /*$s3*/)
 // line 3901, offset 0x8004db1c
	/* begin block 1 */
		// Start line: 3902
		// Start offset: 0x8004DB1C
		// Variables:
	// 		long ret; // $v1
	/* end block 1 */
	// End offset: 0x8004DBB0
	// End Line: 3915

	/* begin block 2 */
		// Start line: 9367
	/* end block 2 */
	// End Line: 9368

long CB_InitAngle(long angle,long speed,long *sens)

{
  long lVar1;
  int iVar2;
  
  do {
    lVar1 = M_rand();
    if (angle == 0) {
      trap(0x1c00);
    }
    if ((angle == -1) && (lVar1 == -0x80000000)) {
      trap(0x1800);
    }
    iVar2 = lVar1 % angle - ((int)(angle + ((uint)angle >> 0x1f)) >> 1);
  } while (iVar2 == 0);
  iVar2 = iVar2 * 0xb;
  if (iVar2 < 0) {
    *sens = -speed;
  }
  else {
    *sens = speed;
  }
  return iVar2;
}



// decompiled code
// original method signature: 
// long /*$ra*/ CB_TestPlanteExplosion(struct _D3_OBJECT *o /*$s0*/, long Explode /*$s1*/, long Z /*$a1*/)
 // line 3920, offset 0x8004dbd0
	/* begin block 1 */
		// Start line: 9412
	/* end block 1 */
	// End Line: 9413

long CB_TestPlanteExplosion(_D3_OBJECT *o,long Explode,long Z)

{
  if (((Explode == 0) && ((o->collision_state & 2U) != 0)) && (o->hit_points == 0)) {
    if ((byte)(*(char *)((int)o[1].description + 0x99) + 0xeU) < 2) {
      o->hit_points = 10;
    }
    else {
      D3_SetHighBoxZ(o,Z);
      o[1].description = (void *)0x0;
      Pvl_SetStateBits(o,0x40);
      SFX_ExplodeObject(o);
      Explode = 1;
    }
  }
  return Explode;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_PlanteTask()
 // line 3947, offset 0x8004dc7c
	/* begin block 1 */
		// Start line: 3948
		// Start offset: 0x8004DC7C
		// Variables:
	// 		struct _D3_OBJECT *o; // $s2
	// 		struct CBASE_93fake *pTmd; // $s0
	// 		struct CBASE_7fake *pvert; // $s7
	// 		struct CBASE_7fake min; // stack offset -72
	// 		struct CBASE_7fake max; // stack offset -64
	// 		struct CBASE_8fake col; // stack offset -56
	// 		long coef; // $s1
	// 		long coef_beg; // $s5
	// 		long maxZ; // stack offset -48
	// 		long Explode; // $s6

		/* begin block 1.1 */
			// Start line: 3985
			// Start offset: 0x8004DD84
			// Variables:
		// 		long step; // $s0
		// 		long step2; // $fp
		// 		long num_i; // $s3
		// 		long nbf; // $s4
		/* end block 1.1 */
		// End offset: 0x8004DF80
		// End Line: 4039
	/* end block 1 */
	// End offset: 0x8004DF88
	// End Line: 4040

	/* begin block 2 */
		// Start line: 9467
	/* end block 2 */
	// End Line: 9468

/* WARNING: Unknown calling convention yet parameter storage is locked */

void CB_PlanteTask(void)

{
  bool bVar1;
  short sVar2;
  long lVar3;
  long lVar4;
  undefined Tmd;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  _D3_OBJECT *o;
  int iVar9;
  uint uVar10;
  long Explode;
  undefined4 uVar11;
  short local_3c;
  
  o = (_D3_OBJECT *)TaskCurrent->local;
  Explode = 0;
  puVar5 = (undefined4 *)o->description;
  uVar11 = *puVar5;
  if (((int)o[1].pos.vz & Scts_Interruptors) != 0) {
    Pvl_SetStateBits(o,0x40);
  }
  Tmd = SUB41(puVar5,0);
  if ((Pvl_SctState[(int)o->index] & 0x40U) != 0) {
    D3_ClearCollBits(o,1);
    Tmd_SetZ(Tmd,0);
    Tmd_ChangeColor(Tmd,200);
    Zone_DeleteObject(o);
    do {
      Task_Next();
    } while( true );
  }
  Tmd_GetBox(Tmd,0xb8,0xc0);
  iVar8 = 0;
  while( true ) {
    sVar2 = Tmd_TestEndStretchZ((char)o->description,(char)uVar11);
    if (sVar2 != 0) {
      D3_ClearCollBits(o,1);
    }
    lVar3 = Task_EventRead(TaskCurrent);
    if (lVar3 == 1) break;
    lVar3 = M_rand();
    uVar10 = lVar3 % 0x1e + 10;
    M_rand();
    lVar3 = M_rand();
    iVar9 = 1;
    iVar6 = lVar3 % 99 + 1;
    if (0 < (int)uVar10) {
      iVar7 = iVar6;
      do {
        Explode = CB_TestPlanteExplosion(o,Explode,(int)local_3c);
        if (((int)o->display_mode & 0x8000U) != 0) {
          GtxTmd_ApplyMIMe((uint **)o->description,iVar8);
        }
        iVar8 = iVar8 + iVar7;
        if (iVar9 < (int)(uVar10 + (uVar10 >> 0x1f)) >> 1) {
          iVar7 = iVar7 + 1;
        }
        else {
          iVar7 = iVar7 + -1;
        }
        Task_Next();
        bVar1 = iVar9 < (int)uVar10;
        iVar9 = iVar9 + 1;
      } while (bVar1);
    }
    lVar4 = M_rand();
    lVar3 = lVar4;
    if (lVar4 < 0) {
      lVar3 = lVar4 + 0x1ff;
    }
    iVar7 = lVar4 + (lVar3 >> 9) * -0x200;
    iVar9 = iVar8;
    while (iVar8 = iVar7, iVar7 <= iVar9) {
      Explode = CB_TestPlanteExplosion(o,Explode,(int)local_3c);
      if (((int)o->display_mode & 0x8000U) != 0) {
        GtxTmd_ApplyMIMe((uint **)o->description,iVar9);
      }
      iVar9 = iVar9 - iVar6;
      Task_Next();
    }
  }
  Zone_DeleteObject(o);
  D3_ClearCollBits(o,1);
  Scts_Interruptors = Scts_Interruptors | (int)o[1].pos.vz;
  do {
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ CB_Lvl4_05(struct _D3_OBJECT *o /*$s4*/)
 // line 4044, offset 0x8004df88
	/* begin block 1 */
		// Start line: 4045
		// Start offset: 0x8004DF88
		// Variables:
	// 		long sensor[5]; // stack offset -72
	// 		struct _MONSTER (*monst[5]); // stack offset -48
	// 		struct _D3_OBJECT *tmpobj; // $s0
	// 		long i; // $s0
	// 		long nmonst; // $s3
	/* end block 1 */
	// End offset: 0x8004E0E4
	// End Line: 4078

	/* begin block 2 */
		// Start line: 9690
	/* end block 2 */
	// End Line: 9691

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CB_Lvl4_05(_D3_OBJECT *o)

{
  _D3_OBJECT *p_Var1;
  long lVar2;
  _ZONE *Param;
  _D3_OBJECT *o_00;
  int iVar3;
  _D3_OBJECT **pp_Var4;
  _D3_OBJECT **pp_Var5;
  int iVar6;
  _D3_OBJECT *local_48 [6];
  _D3_OBJECT *local_30 [6];
  
  o_00 = o->child;
  iVar3 = 0;
  while ((o_00 != (_D3_OBJECT *)0x0 && (iVar3 != 5))) {
    iVar6 = iVar3;
    if (((int)o_00->collision_mode & 0x8000U) != 0) {
      iVar6 = iVar3 + 1;
      p_Var1 = *(_D3_OBJECT **)&o_00[1].last_pos;
      local_30[iVar3] = p_Var1;
      local_48[iVar3] = p_Var1->prec;
      local_30[iVar3]->prec = (_D3_OBJECT *)0x0;
      o_00->display_mode = o_00->display_mode & 0xffef;
      D3_ClearCollBits(o_00,9);
    }
    o_00 = o_00->next;
    iVar3 = iVar6;
  }
  while (lVar2 = Task_EventRead(o->handle), lVar2 != 2) {
    Task_Next();
  }
  _DAT_800b1d58 = 1;
  iVar6 = 0;
  if (0 < iVar3) {
    pp_Var4 = local_30;
    pp_Var5 = local_48;
    do {
      (*pp_Var4)->prec = *pp_Var5;
      pp_Var5 = pp_Var5 + 1;
      (*pp_Var4)->next->display_mode = (*pp_Var4)->next->display_mode | 0x10;
      o_00 = *pp_Var4;
      iVar6 = iVar6 + 1;
      pp_Var4 = pp_Var4 + 1;
      D3_SetCollBits(o_00->next,9);
    } while (iVar6 < iVar3);
  }
  iVar3 = 0;
  if (0 < o[1].pos.vz) {
    do {
      iVar3 = iVar3 + 1;
      Task_Next();
    } while (iVar3 < (int)o[1].pos.vz);
  }
  _DAT_800b1d58 = 0;
  Param = Zone_GetObjectZone(o);
  Pl_ForceAction((_PLAYER *)&Player,1,(long)Param);
  return;
}





