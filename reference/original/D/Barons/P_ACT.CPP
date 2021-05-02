#include "THISDUST.H"
#include "P_ACT.H"


// decompiled code
// original method signature: 
// void /*$ra*/ Pl_GetAction(struct _PLAYER *pl /*$s5*/)
 // line 78, offset 0x800352a8
	/* begin block 1 */
		// Start line: 79
		// Start offset: 0x800352A8
		// Variables:
	// 		unsigned short *JoyBits; // $s0
	// 		unsigned short *Actions; // $s1
	// 		unsigned short Pav_ForceJoys[4]; // stack offset -56
	// 		unsigned short Pav_SetJoys[3]; // stack offset -48
	// 		long reload; // $a0
	// 		long look; // $s3
	// 		short *ModeBits; // $s2

		/* begin block 1.1 */
			// Start line: 165
			// Start offset: 0x80035424
			// Variables:
		// 		long x; // $s1
		// 		long y; // $s2
		/* end block 1.1 */
		// End offset: 0x800354FC
		// End Line: 181

		/* begin block 1.2 */
			// Start line: 208
			// Start offset: 0x800355D8
			// Variables:
		// 		long spell; // $s4
		// 		long i; // $s3
		// 		long button; // $fp
		// 		long trig; // $s6

			/* begin block 1.2.1 */
				// Start line: 242
				// Start offset: 0x800356E8
				// Variables:
			// 		struct _MONSTER *m; // $s0
			// 		long color; // $s1
			/* end block 1.2.1 */
			// End offset: 0x80035730
			// End Line: 259
		/* end block 1.2 */
		// End offset: 0x80035928
		// End Line: 385
	/* end block 1 */
	// End offset: 0x80035B70
	// End Line: 415

	/* begin block 2 */
		// Start line: 156
	/* end block 2 */
	// End Line: 157

/* WARNING: Type propagation algorithm not settling */

void Pl_GetAction(_PLAYER *pl)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  bool bVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  ulong uVar8;
  _PLAYER *p_Var9;
  uint type;
  uint Action;
  long param;
  ushort *puVar10;
  int iVar11;
  ushort *puVar12;
  int iVar13;
  _D3_OBJECT **pp_Var14;
  short *psVar15;
  ushort uVar16;
  ushort local_38;
  ushort local_36;
  undefined2 local_34;
  undefined2 local_32;
  ushort local_30;
  ushort local_2e;
  undefined2 local_2c;
  
  local_34 = 0x1000;
  local_32 = 0;
  local_2c = 0;
  local_38 = PJOY_SHOT | PJOY_AIM;
  local_36 = PJOY_ESQUIVE;
  local_30 = PJOY_BOMB;
  local_2e = PJOY_JUMP;
  if (((pl->m_obj).nAnim & 0x800U) != 0) {
    if (*(short *)(DAT_800b3f0c + 0x54) == 0) {
      param = Overlay_Handle->event_param;
      type = Overlay_Handle->event_msg | 1;
    }
    else {
      param = Overlay_Handle->event_param;
      type = Overlay_Handle->event_msg | 2;
    }
    Task_EventExec(Overlay_Handle,type,param);
  }
  if (*(short *)(DAT_800b3f0c + 0x54) != 0) {
    (pl->m_obj).dummy1 = 0;
    (pl->m_obj).nAnim = 0;
    return;
  }
  if (((pl->m_obj).nAnim & PJOY_RIGHTHAND) != 0) {
    if ((*(ushort *)&(pl->m_obj).shadow.u0 & 0x400) == 0) {
      Overlay_ChangeRWeapon(pl,1);
    }
    else {
      Fx_Play(0x42,0);
    }
  }
  if ((*(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x16) == 0x36) &&
     (iVar13 = 0, (*(ushort *)&(pl->m_obj).shadow.u0 & 1) != 0)) {
    uVar16 = (pl->m_obj).dummy1;
    iVar11 = 0;
    if ((uVar16 & 0x1000) == 0) {
      if ((uVar16 & 0x4000) != 0) {
        iVar11 = -4;
      }
      uVar16 = (pl->m_obj).dummy1;
    }
    else {
      iVar11 = 4;
    }
    if ((uVar16 & 0x8000) == 0) {
      if ((uVar16 & 0x2000) != 0) {
        iVar13 = -4;
      }
    }
    else {
      iVar13 = 4;
    }
    iVar6 = rcos((int)(pl->obj).rot.vz);
    iVar7 = rsin((int)(pl->obj).rot.vz);
    sVar5 = (pl->obj).rot.vz;
    (pl->obj).pos.vx = (pl->obj).pos.vx + (short)(iVar6 * iVar11 - iVar7 * iVar13 >> 0xc);
    iVar6 = rsin((int)sVar5);
    iVar7 = rcos((int)(pl->obj).rot.vz);
    (pl->obj).pos.vy = (pl->obj).pos.vy + (short)(iVar6 * iVar11 + iVar7 * iVar13 >> 0xc);
  }
  if (((*(ushort *)&(pl->m_obj).shadow.u0 & 0x40) != 0) &&
     (uVar16 = (pl->m_obj).dummy1, (uVar16 & PJOY_STRAFE) == 0)) {
    if ((uVar16 & 0x8000) != 0) {
      (pl->obj).rot.vz = (pl->obj).rot.vz + 0x40U & 0xfff;
    }
    if (((pl->m_obj).dummy1 & 0x2000U) != 0) {
      (pl->obj).rot.vz = (pl->obj).rot.vz - 0x40U & 0xfff;
    }
  }
  if ((((pl->m_obj).nAnim & PJOY_SPELL) != 0) && ((*(ushort *)&(pl->m_obj).shadow.u0 & 0x20) == 0))
  {
    Fx_Play(0x42,0);
  }
  if ((((pl->m_obj).dummy1 & PJOY_SPELL) == 0) ||
     (bVar4 = false, (*(ushort *)&(pl->m_obj).shadow.u0 & 0x20) == 0)) {
    Overlay_SetSpellOFF(0);
  }
  else {
    uVar16 = 0;
    iVar13 = 0;
    Task_EventExec(Overlay_Handle,Overlay_Handle->event_msg | 0x800,Overlay_Handle->event_param);
    Task_EventExec(Overlay_Handle,Overlay_Handle->event_msg | 0x2000,Overlay_Handle->event_param);
    p_Var9 = pl;
    do {
      bVar1 = *(byte *)&(p_Var9->env2).Obj.n_normal;
      type = (uint)bVar1 & 0x3f;
      if ((bVar1 & 0x40) != 0) {
        if ((type == 8) && ((Pvl_File->mode & 1U) != 0)) {
          *(byte *)&(p_Var9->env2).Obj.n_normal = bVar1 & 0xbf;
        }
        else {
          param = Pl_GetSpellCost(pl,type);
          iVar11 = (int)&(pl->obj).next + iVar13;
          if (param <= (int)(uint)*(ushort *)((pl->env2).Obj.primitive_top.Data + 0xe)) {
            PSpell_GetTargets(pl,type,&PSpell_Targets4);
            iVar13 = 0;
            if (0 < PSpell_nTargets) {
              iVar11 = 0;
              do {
                pp_Var14 = (_D3_OBJECT **)((int)&PSpell_Targets4 + iVar11);
                if (((int)(*pp_Var14)->collision_mode & 0x8000U) != 0) {
                  iVar11 = *(int *)&(*pp_Var14)[1].last_pos;
                  param = 0xc04040;
                  *(undefined2 *)(iVar11 + 0x156) = 1;
                  *(ushort *)(iVar11 + 0x158) = *(ushort *)(iVar11 + 0x158) | 8;
                  uVar8 = MSpell_TestAppliedOnObject(*pp_Var14,type);
                  if (uVar8 == 0) {
                    param = 0x804080;
                  }
                  (*pp_Var14)->color = param;
                  *(undefined2 *)(iVar11 + 0x14a) = 1;
                }
                iVar13 = iVar13 + 1;
                iVar11 = iVar13 * 4;
              } while (iVar13 < (int)PSpell_nTargets);
            }
            break;
          }
          *(byte *)(iVar11 + 0x1e8) = *(byte *)(iVar11 + 0x1e8) & 0xbf;
        }
      }
      iVar13 = iVar13 + 1;
      p_Var9 = (_PLAYER *)((int)&(pl->obj).next + iVar13);
    } while (iVar13 < 4);
    uVar3 = (pl->m_obj).dummy1;
    iVar13 = 0;
    if ((uVar3 & 0x10) == 0) {
      iVar13 = 1;
      if ((uVar3 & 0x80) == 0) {
        iVar13 = 2;
        if ((uVar3 & 0x20) == 0) {
          iVar13 = 3;
          if ((uVar3 & 0x40) == 0) {
            iVar13 = -1;
          }
          else {
            bVar4 = true;
            uVar16 = (pl->m_obj).nAnim & 0x40;
          }
        }
        else {
          bVar4 = true;
          uVar16 = (pl->m_obj).nAnim & 0x20;
        }
      }
      else {
        bVar4 = true;
        uVar16 = (pl->m_obj).nAnim & 0x80;
      }
    }
    else {
      bVar4 = true;
      uVar16 = (pl->m_obj).nAnim & 0x10;
    }
    iVar11 = (int)&(pl->obj).next + iVar13;
    if ((-1 < iVar13) && ((*(byte *)(iVar11 + 0x1e8) & 0x80) == 0)) {
      bVar1 = *(byte *)(iVar11 + 0x1e8);
      if ((bVar1 & 0x40) == 0) {
        param = Pl_GetSpellCost(pl,(uint)bVar1);
        if ((param <= (int)(uint)*(ushort *)((pl->env2).Obj.primitive_top.Data + 0xe)) &&
           ((bVar1 != 8 || ((Pvl_File->mode & 1U) == 0)))) {
          bVar1 = *(byte *)((int)&(pl->env2).Obj.n_normal + 1);
          *(byte *)&(pl->env2).Obj.n_normal = *(byte *)&(pl->env2).Obj.n_normal & 0xbf;
          bVar2 = *(byte *)((int)&(pl->env2).Obj.n_normal + 2);
          *(byte *)((int)&(pl->env2).Obj.n_normal + 1) = bVar1 & 0xbf;
          bVar1 = *(byte *)((int)&(pl->env2).Obj.n_normal + 3);
          *(byte *)((int)&(pl->env2).Obj.n_normal + 2) = bVar2 & 0xbf;
          *(byte *)((int)&(pl->env2).Obj.n_normal + 3) = bVar1 & 0xbf;
          uVar16 = 0;
          *(byte *)(iVar11 + 0x1e8) = *(byte *)(iVar11 + 0x1e8) | 0x40;
          Fx_Play(0x40,0);
        }
      }
      else {
        if (((uVar16 != 0) && (type = (uint)bVar1 & 0x3f, PSpell_nTargets != 0)) &&
           (param = Pl_GetSpellCost(pl,type),
           param <= (int)(uint)*(ushort *)((pl->env2).Obj.primitive_top.Data + 0xe))) {
          Action = 0x16;
          goto LAB_80035b68;
        }
      }
    }
    if (bVar4) {
      if (uVar16 == 0) {
        return;
      }
      Fx_Play(0x42,0);
      return;
    }
  }
  bVar4 = false;
  puVar10 = &local_38;
  psVar15 = Pav_ForceModes;
  puVar12 = Pav_ForceActions;
  *(ushort *)&(pl->m_obj).shadow.b0 =
       *(ushort *)&(pl->m_obj).shadow.b0 | (pl->m_obj).dummy1 & PJOY_AIM;
  uVar16 = local_38;
  while (uVar16 != 0) {
    uVar16 = *(ushort *)&(pl->m_obj).shadow.b0;
    if (((uVar16 & *puVar10) != 0) && ((*(ushort *)&(pl->m_obj).shadow.u0 & *psVar15) != 0)) {
      if (*puVar12 == 0x14) {
        if (((uVar16 & PJOY_SHOT) != 0) ||
           ((iVar13 = (int)(char)(pl->env1).Obj.primitive_top.Data[0x19], iVar13 != 4 &&
            ((*(short *)((pl->env1).Obj.primitive_top.Data + iVar13 * 8 + 0x1a) != 0 ||
             (param = Invent_ReloadAmmo(pl), param != 0)))))) {
LAB_80035a14:
          *(ushort *)&(pl->m_obj).shadow.b0 = *(ushort *)&(pl->m_obj).shadow.b0 & ~*puVar10;
          Pl_ForceAction(pl,(uint)*puVar12,0);
          return;
        }
        bVar4 = true;
      }
      else {
        if ((*puVar12 != 6) || (!bVar4)) goto LAB_80035a14;
      }
    }
    puVar10 = puVar10 + 1;
    psVar15 = (short *)((ushort *)psVar15 + 1);
    uVar16 = *puVar10;
    puVar12 = puVar12 + 1;
  }
  puVar12 = &local_30;
  puVar10 = Pav_SetActions;
  uVar16 = local_30;
  while (uVar16 != 0) {
    uVar16 = *(ushort *)&(pl->m_obj).shadow.b0;
    if ((uVar16 & *puVar12) != 0) {
      if (*puVar10 != 0x15) {
        *(ushort *)&(pl->m_obj).shadow.b0 = uVar16 & ~*puVar12;
        Action = (uint)*puVar10;
        type = 0;
        goto LAB_80035b68;
      }
      if (((&Pl_LeftWeapons)[(int)(char)(pl->env1).Obj.primitive_top.Data[0x18]] != 0x1a) &&
         (sVar5 = Invent_GetNbObjects((&Pl_LeftWeapons)
                                      [(int)(char)(pl->env1).Obj.primitive_top.Data[0x18]],0),
         sVar5 != 0)) {
        *(ushort *)&(pl->m_obj).shadow.b0 = *(ushort *)&(pl->m_obj).shadow.b0 & ~*puVar12;
        Action = (uint)*puVar10;
        type = 0;
        goto LAB_80035b68;
      }
      *(ushort *)&(pl->m_obj).shadow.b0 = *(ushort *)&(pl->m_obj).shadow.b0 & ~*puVar12;
      Fx_Play(0x42,0);
    }
    puVar12 = puVar12 + 1;
    uVar16 = *puVar12;
    puVar10 = puVar10 + 1;
  }
  if (bVar4) {
    return;
  }
  if (((pl->m_obj).dummy1 & 0xf000U) != 0) {
    Pl_SetAction(pl,6,0);
  }
  if (((pl->m_obj).nFrame & 0x4000U) == 0) {
    return;
  }
  Action = 7;
  type = 0;
LAB_80035b68:
  Pl_SetAction(pl,Action,type);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pl_SetAction(struct _PLAYER *pl /*$s0*/, long Action /*$a1*/, long Param /*$a2*/)
 // line 418, offset 0x80035ba0
	/* begin block 1 */
		// Start line: 1077
	/* end block 1 */
	// End Line: 1078

/* WARNING: Type propagation algorithm not settling */

void Pl_SetAction(_PLAYER *pl,long Action,long Param)

{
  if ((int)(pl->m_obj).shadow.y1 != Action) {
    Task_EventExec((TASK *)(pl->m_obj).Ani.Anim.Rot,Action + 1,Param);
    (pl->m_obj).Ani.Anim.Rot[4].m[3] = 0;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pl_ForceAction(struct _PLAYER *pl /*$s0*/, long Action /*$a1*/, long Param /*$a2*/)
 // line 428, offset 0x80035be8
	/* begin block 1 */
		// Start line: 1097
	/* end block 1 */
	// End Line: 1098

/* WARNING: Type propagation algorithm not settling */

void Pl_ForceAction(_PLAYER *pl,long Action,long Param)

{
  (pl->m_obj).Ani.Anim.Rot[4].m[3] = 1;
  Task_EventExec((TASK *)(pl->m_obj).Ani.Anim.Rot,Action + 1,Param);
  (pl->m_obj).Ani.Anim.Rot[4].m[3] = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pact_StartSector()
 // line 443, offset 0x80035c2c
	/* begin block 1 */
		// Start line: 444
		// Start offset: 0x80035C2C
		// Variables:
	// 		struct _PLAYER *pl; // $s1
	// 		struct _ZONE *z; // $s2
	// 		struct _D3_OBJECT *o; // $s0
	// 		long spell; // $a0
	/* end block 1 */
	// End offset: 0x80035D1C
	// End Line: 480

	/* begin block 2 */
		// Start line: 1128
	/* end block 2 */
	// End Line: 1129

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pact_StartSector(void)

{
  char cVar1;
  _D3_OBJECT *o;
  void *pvVar2;
  _ZONE *zone;
  
  zone = (_ZONE *)TaskCurrent->event_param;
  pvVar2 = TaskCurrent->local;
  o = (_D3_OBJECT *)0x0;
  if (zone->nObjects != 0) {
    o = ((_D3_OBJECT *)zone->Tab_Objects)->next;
  }
  cVar1 = *(char *)((int)pvVar2 + 0x1ec);
  *(undefined *)((int)pvVar2 + 0x1ec) = 0;
  if (((o == (_D3_OBJECT *)0x0) || (*(char *)((int)&o[1].pos.vx + 1) != '\x01')) ||
     (1 < (uint)(ushort)o[1].pos.vy - 8)) {
    if (cVar1 != '\0') {
      Fx_Play(0x2b,0);
      Task_Link(Paf_TeleportEffectTask,0x200);
    }
    if (((o == (_D3_OBJECT *)0x0) || (*(char *)((int)&o[1].pos.vx + 1) != '\x01')) ||
       (1 < (uint)(ushort)o[1].pos.vy - 8)) {
      *(undefined2 *)((int)pvVar2 + 0x1e) = 0;
      *(ushort *)((int)pvVar2 + 0x1a) = *(ushort *)((int)pvVar2 + 0x1a) | 0x10;
      Paf_EnterSector(zone,o);
      return;
    }
  }
  Paf_TeleportIn(o);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pact_ExitSector()
 // line 483, offset 0x80035d34
	/* begin block 1 */
		// Start line: 484
		// Start offset: 0x80035D34
		// Variables:
	// 		struct _PLAYER *pl; // $s1
	// 		struct _D3_OBJECT *o; // $a1
	// 		struct _ZONE *z; // $v1
	/* end block 1 */
	// End offset: 0x80035DFC
	// End Line: 521

	/* begin block 2 */
		// Start line: 1221
	/* end block 2 */
	// End Line: 1222

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pact_ExitSector(void)

{
  int iVar1;
  _D3_OBJECT *ou;
  void *pvVar2;
  
  pvVar2 = TaskCurrent->local;
  iVar1 = TaskCurrent->event_param;
  *(int *)((int)pvVar2 + 0x118) = iVar1;
  if ((*(ushort *)((int)pvVar2 + 0x122) & 0x200) == 0) {
    if (((iVar1 != 0) && (*(short *)(iVar1 + 0x28) != 0)) &&
       (ou = (*(_D3_OBJECT **)(iVar1 + 0x2c))->next, (*(uint *)&ou[1].pos & 0xffffff00) == 0x80100))
    {
      Paf_TeleportOut(ou);
    }
  }
  else {
    *(undefined4 *)((int)pvVar2 + 0xb0) = *(undefined4 *)(iVar1 + 0xc);
    Manim_ForceAnim((M_OBJECT *)((int)pvVar2 + 0xa4),0);
    Manim_WaitAnim((M_OBJECT *)((int)pvVar2 + 0xa4));
  }
  *(ushort *)((int)pvVar2 + 0xcc) = *(ushort *)((int)pvVar2 + 0xcc) & 0xfffe;
  *(ushort *)((int)pvVar2 + 0x1e) = *(ushort *)((int)pvVar2 + 0x1e) | 8;
  do {
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pact_Save()
 // line 524, offset 0x80035dfc
	/* begin block 1 */
		// Start line: 525
		// Start offset: 0x80035DFC
		// Variables:
	// 		struct _PLAYER *pl; // $s1
	// 		struct _D3_OBJECT *ou; // $s2
	// 		struct _ZONE *z; // $s0
	/* end block 1 */
	// End offset: 0x80035F18
	// End Line: 571

	/* begin block 2 */
		// Start line: 1312
	/* end block 2 */
	// End Line: 1313

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pact_Save(void)

{
  ushort uVar1;
  _ZONE *p_Var2;
  long lVar3;
  _PLAYER *pl;
  _D3_OBJECT *o;
  
  o = (_D3_OBJECT *)TaskCurrent->event_param;
  pl = (_PLAYER *)TaskCurrent->local;
  TaskCurrent->event_enable = 0;
  p_Var2 = Zone_GetObjectZone(o);
  Manim_SetAnim((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data,0x50);
  Pl_AdjustUse(pl,(char)o + ',',0,0);
  *(ushort *)&(pl->m_obj).Env.Obj.n_primitive = *(ushort *)&(pl->m_obj).Env.Obj.n_primitive & 0xfffe
  ;
  Pvl_PauseGame();
  TaskCurrent->enable = 1;
  Pvl_SetStateBits(o,2);
  lVar3 = InGame_SaveGame(pl,p_Var2->entry_id,0);
  if (lVar3 != 0) {
    Pvl_SetStateBits(o,1);
  }
  Pvl_ClearStateBits(o,2);
  if (((pl->obj).collision_state & 8U) == 0) {
    Pvl_UnpauseGame();
    uVar1 = *(ushort *)&(pl->m_obj).shadow.u0;
    *(undefined2 *)&(pl->m_obj).shadow.u1 = 0;
    *(ushort *)&(pl->m_obj).shadow.u0 = uVar1 | 8;
    do {
      *(short *)&(pl->m_obj).shadow.u1 = *(short *)&(pl->m_obj).shadow.u1 + 0x80;
      Task_Next();
    } while (*(short *)&(pl->m_obj).shadow.u1 != 0x800);
    uVar1 = *(ushort *)&(pl->m_obj).shadow.u0;
    (pl->obj).rot.vz = (pl->obj).rot.vz + 0x800U & 0xfff;
    *(ushort *)&(pl->m_obj).shadow.u0 = uVar1 & 0xfff7;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Paf_TeleportOut(struct _D3_OBJECT *ou /*$s1*/)
 // line 574, offset 0x80035f30
	/* begin block 1 */
		// Start line: 575
		// Start offset: 0x80035F30
		// Variables:
	// 		struct _PLAYER *pl; // $s0
	/* end block 1 */
	// End offset: 0x80035F30
	// End Line: 575

	/* begin block 2 */
		// Start line: 1425
	/* end block 2 */
	// End Line: 1426

void Paf_TeleportOut(_D3_OBJECT *ou)

{
  _PLAYER *pl;
  
  pl = (_PLAYER *)TaskCurrent->local;
  TaskCurrent->event_enable = 0;
  Manim_SetAnim((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data,0x50);
  Pl_AdjustUse(pl,(char)ou + ',',0,0);
  *(ushort *)&(pl->m_obj).Env.Obj.n_primitive = *(ushort *)&(pl->m_obj).Env.Obj.n_primitive & 0xfffe
  ;
  D3_PlaySound(ou,0);
  Task_Link(Paf_TeleportEffectTask,0x200);
  Task_Sleep(0xe);
  (pl->obj).display_mode = (pl->obj).display_mode & 0xffef;
  Task_Sleep(7);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Paf_TeleportIn(struct _D3_OBJECT *ou /*$s1*/)
 // line 601, offset 0x80035fcc
	/* begin block 1 */
		// Start line: 602
		// Start offset: 0x80035FCC
		// Variables:
	// 		struct _PLAYER *pl; // $s0
	/* end block 1 */
	// End offset: 0x80035FCC
	// End Line: 602

	/* begin block 2 */
		// Start line: 1489
	/* end block 2 */
	// End Line: 1490

void Paf_TeleportIn(_D3_OBJECT *ou)

{
  void *pvVar1;
  
  pvVar1 = TaskCurrent->local;
  Paf_EnterSector((_ZONE *)0x0,ou);
  TaskCurrent->event_enable = 0;
  *(ushort *)((int)pvVar1 + 0x1a) = *(ushort *)((int)pvVar1 + 0x1a) & 0xffef;
  Manim_SetAnim((M_OBJECT *)((int)pvVar1 + 0xa4),0x61);
  *(ushort *)((int)pvVar1 + 0xcc) = *(ushort *)((int)pvVar1 + 0xcc) & 0xfffe;
  *(ushort *)((int)pvVar1 + 0x40) = (ou->rot).vz + 0xc00U & 0xfff;
  Task_Next();
  D3_PlaySound(ou,0);
  Task_Link(Paf_TeleportEffectTask,0x200);
  Task_Sleep(0xe);
  *(ushort *)((int)pvVar1 + 0x1a) = *(ushort *)((int)pvVar1 + 0x1a) | 0x10;
  Task_Sleep(7);
  TaskCurrent->event_enable = 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Paf_TeleportEffectTask()
 // line 635, offset 0x800360a0
	/* begin block 1 */
		// Start line: 636
		// Start offset: 0x800360A0
		// Variables:
	// 		struct P_ACT_7fake pos; // stack offset -32
	// 		struct P_ACT_71fake list; // stack offset -24
	/* end block 1 */
	// End offset: 0x800361C8
	// End Line: 669

	/* begin block 2 */
		// Start line: 1572
	/* end block 2 */
	// End Line: 1573

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Paf_TeleportEffectTask(void)

{
  byte bVar1;
  undefined auStack32 [6];
  undefined2 local_1a;
  void *local_18;
  undefined *local_14;
  undefined4 local_10;
  undefined2 local_c;
  
  Boxes_GetCenter((_D3_OBJECT *)TaskCurrent->local,0xe0);
  local_14 = auStack32;
  local_c = 1;
  local_10 = 0;
  local_1a = 0x2600;
  local_18 = Pl_Pcl;
  do {
    *(short *)(local_14 + 6) = *(short *)(local_14 + 6) + 10;
    Main_Prims = (void *)GtxShp_DisplayListLOFF
                                   (&local_18,Main_Prims,Scr->ot + 8,0,0,
                                    Main_TextContext.Font.ascii_tab._20_4_);
    Task_Next();
    bVar1 = local_14[6];
  } while (bVar1 < 0x8c);
  while (bVar1 != 0) {
    *(short *)(local_14 + 6) = *(short *)(local_14 + 6) + -0x14;
    Main_Prims = (void *)GtxShp_DisplayListLOFF
                                   (&local_18,Main_Prims,Scr->ot + 8,0,0,
                                    Main_TextContext.Font.ascii_tab._20_4_);
    Task_Next();
    bVar1 = local_14[6];
  }
  Task_Sleep(2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Paf_EnterSector(struct _ZONE *zone /*$s2*/, struct _D3_OBJECT *o /*$s1*/)
 // line 673, offset 0x800361e0
	/* begin block 1 */
		// Start line: 674
		// Start offset: 0x800361E0
		// Variables:
	// 		struct _PLAYER *pl; // $s0
	// 		struct _D3_OBJECT *ot; // $v1

		/* begin block 1.1 */
			// Start line: 692
			// Start offset: 0x80036250
			// Variables:
		// 		long zmin; // $v0
		// 		long zmax; // $v1
		/* end block 1.1 */
		// End offset: 0x800362E8
		// End Line: 704
	/* end block 1 */
	// End offset: 0x800364B4
	// End Line: 753

	/* begin block 2 */
		// Start line: 1663
	/* end block 2 */
	// End Line: 1664

void Paf_EnterSector(_ZONE *zone,_D3_OBJECT *o)

{
  short sVar1;
  short sVar2;
  _D3_OBJECT *p_Var3;
  short sVar4;
  uint uVar5;
  long lVar6;
  undefined4 uVar7;
  _PLAYER *pl;
  
  pl = (_PLAYER *)TaskCurrent->local;
  D3_InsertObject((_D3_OBJECT *)pl,&Pvl_GlobalObjects);
  (pl->obj).collision_state = (pl->obj).collision_state & 0xfff7;
  Track_SetMode(2,0);
  if (o == (_D3_OBJECT *)0x0) {
    if (zone == (_ZONE *)0x0) goto LAB_800364b4;
    uVar5 = (int)zone->x1 + (int)zone->x2;
    (pl->obj).pos.vx = (short)((int)(uVar5 + (uVar5 >> 0x1f)) >> 1);
    sVar4 = zone->y1;
    sVar1 = zone->y2;
    (pl->obj).pos.vz = 10000;
    uVar5 = (int)sVar4 + (int)sVar1;
    (pl->obj).pos.vy = (short)((int)(uVar5 + (uVar5 >> 0x1f)) >> 1);
    lVar6 = Pl_TestHeight(pl,0);
    p_Var3 = Boxes_Object;
    (pl->obj).pos.vz = (short)lVar6;
    if (((int)p_Var3->collision_mode & 0x8000U) != 0) {
      sVar4 = (p_Var3->pos).vz;
      goto code_r0x800363c8;
    }
  }
  else {
    if ((*(uint *)&o[1].pos & 0xffffff00) == 0xf00) {
      sVar4 = (o->pos).vz;
      sVar1 = (o->b_box).vz;
      sVar2 = *(short *)&o[1].prec;
      uVar7 = *(undefined4 *)&(o->pos).vz;
      *(undefined4 *)&(pl->obj).pos = *(undefined4 *)&o->pos;
      *(undefined4 *)&(pl->obj).pos.vz = uVar7;
      uVar7 = *(undefined4 *)&(o->rot).vz;
      *(undefined4 *)&(pl->obj).rot = *(undefined4 *)&o->rot;
      *(undefined4 *)&(pl->obj).rot.vz = uVar7;
      uVar5 = (int)sVar4 * 2 + (int)sVar1 + (int)sVar2;
      (pl->obj).pos.vz = (short)((int)(uVar5 + (uVar5 >> 0x1f)) >> 1) + -100;
      uVar7 = *(undefined4 *)&(pl->obj).pos.vz;
      *(undefined4 *)&(pl->obj).last_pos = *(undefined4 *)&(pl->obj).pos;
      *(undefined4 *)&(pl->obj).last_pos.vz = uVar7;
      Pl_ForceAction(pl,0xe,(long)o);
    }
    uVar5 = (int)(o->b_box).vx + (int)*(short *)&o->b_step;
    (pl->obj).pos.vx = (o->pos).vx + (short)((int)(uVar5 + (uVar5 >> 0x1f)) >> 1);
    uVar5 = (int)(o->b_box).vy + (int)*(short *)((int)&o->b_sunk + 2);
    (pl->obj).pos.vy = (o->pos).vy + (short)((int)(uVar5 + (uVar5 >> 0x1f)) >> 1);
    sVar4 = *(short *)&o[1].prec + (o->pos).vz + 0x14;
code_r0x800363c8:
    (pl->obj).pos.vz = sVar4;
  }
  if (zone != (_ZONE *)0x0) {
    uVar5 = zone->mode & 0xe;
    if (uVar5 == 4) {
      (pl->obj).rot.vz = 0;
    }
    else {
      if (uVar5 < 5) {
        if (uVar5 == 2) {
          (pl->obj).rot.vz = 0x400;
        }
      }
      else {
        if (uVar5 == 6) {
          (pl->obj).rot.vz = 0x800;
        }
        else {
          if (uVar5 == 8) {
            (pl->obj).rot.vz = 0xc00;
          }
        }
      }
    }
    if (-1 < zone->camera) {
      Track_SetMode(10,(long)zone);
    }
    if ((zone->mode & 0x40U) != 0) {
      (pl->obj).pos.vz = (pl->obj).pos.vz + 500;
      uVar7 = *(undefined4 *)&(pl->obj).pos.vz;
      *(undefined4 *)&(pl->obj).last_pos = *(undefined4 *)&(pl->obj).pos;
      *(undefined4 *)&(pl->obj).last_pos.vz = uVar7;
      Manim_SetAnim((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data,0x61);
      Pl_ForceAction(pl,9,0);
    }
  }
LAB_800364b4:
  uVar7 = *(undefined4 *)&(pl->obj).pos.vz;
  *(undefined4 *)&(pl->obj).last_pos = *(undefined4 *)&(pl->obj).pos;
  *(undefined4 *)&(pl->obj).last_pos.vz = uVar7;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pact_Wait()
 // line 763, offset 0x800364ec
	/* begin block 1 */
		// Start line: 764
		// Start offset: 0x800364EC
		// Variables:
	// 		struct _PLAYER *pl; // $s1
	// 		long time; // $s0
	// 		long mini; // $s4
	/* end block 1 */
	// End offset: 0x80036648
	// End Line: 798

	/* begin block 2 */
		// Start line: 1866
	/* end block 2 */
	// End Line: 1867

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pact_Wait(void)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  long lVar4;
  int iVar5;
  _PLAYER *pl;
  
  pl = (_PLAYER *)TaskCurrent->local;
  Manim_SetAnim((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data,0x61);
  *(ushort *)&(pl->m_obj).Env.Obj.n_primitive = *(ushort *)&(pl->m_obj).Env.Obj.n_primitive & 0xfffe
  ;
  iVar5 = *(int *)(*(int *)((pl->m_obj).Env.Obj.primitive_top.Data + 0xc) +
                   (int)*(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x16) * 4 + 8);
  uVar3 = (uint)*(ushort *)(iVar5 + 6);
  uVar1 = *(ushort *)(iVar5 + 8);
  if (uVar1 == 0) {
    trap(0x1c00);
  }
  if (((uint)uVar1 == 0xffffffff) && (uVar3 == 0x8000000)) {
    trap(0x1800);
  }
  do {
    lVar4 = M_rand();
    iVar5 = lVar4 % 100 + (int)(uVar3 << 4) / (int)(uint)uVar1 + 0x4f;
    while (iVar5 != -1) {
      if (((pl->m_obj).dummy1 & PJOY_AIM) == 0) {
        *(undefined2 *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x24) = 0;
        *(undefined2 *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x26) = 0;
      }
      else {
        Paf_Look(pl);
      }
      uVar2 = *(ushort *)&(pl->m_obj).Env.Obj.n_primitive;
      if ((uVar2 & 0x4000) != 0) {
        *(ushort *)&(pl->m_obj).Env.Obj.n_primitive = uVar2 & 0xfffe;
      }
      iVar5 = iVar5 + -1;
      Task_Next();
    }
    *(ushort *)&(pl->m_obj).Env.Obj.n_primitive = *(ushort *)&(pl->m_obj).Env.Obj.n_primitive | 1;
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Paf_Look(struct _PLAYER *pl /*$a0*/)
 // line 801, offset 0x80036648
	/* begin block 1 */
		// Start line: 803
		// Start offset: 0x80036648
	/* end block 1 */
	// End offset: 0x8003671C
	// End Line: 826

	/* begin block 2 */
		// Start line: 1973
	/* end block 2 */
	// End Line: 1974

/* WARNING: Type propagation algorithm not settling */

void Paf_Look(_PLAYER *pl)

{
  ushort uVar1;
  short sVar2;
  
  uVar1 = (pl->m_obj).dummy1;
  if ((uVar1 & 0x1000) == 0) {
    if ((uVar1 & 0x4000) == 0) {
      if ((uVar1 & 0x2000) == 0) {
        if ((uVar1 & 0x8000) == 0) goto LAB_800366bc;
        sVar2 = *(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x26) + 0x40;
      }
      else {
        sVar2 = *(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x26) + -0x40;
      }
      *(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x26) = sVar2;
    }
    else {
      *(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x24) =
           *(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x24) + -0x40;
    }
  }
  else {
    *(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x24) =
         *(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x24) + 0x40;
  }
LAB_800366bc:
  if (0x300 < *(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x26)) {
    *(undefined2 *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x26) = 0x300;
  }
  if (*(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x26) < -0x300) {
    *(undefined2 *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x26) = 0xfd00;
  }
  if (*(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x24) < -0x300) {
    *(undefined2 *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x24) = 0xfd00;
  }
  if (0x180 < *(short *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x24)) {
    *(undefined2 *)((pl->m_obj).Env.Obj.primitive_top.Data + 0x24) = 0x180;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pact_Freeze()
 // line 831, offset 0x80036724
	/* begin block 1 */
		// Start line: 832
		// Start offset: 0x80036724
		// Variables:
	// 		struct _PLAYER *pl; // $s0
	// 		long i; // $a0
	/* end block 1 */
	// End offset: 0x80036964
	// End Line: 894

	/* begin block 2 */
		// Start line: 2026
	/* end block 2 */
	// End Line: 2027

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pact_Freeze(void)

{
  ushort uVar1;
  TASK *pTVar2;
  char cVar3;
  short *psVar4;
  int iVar5;
  _D3_OBJECT *p_Var6;
  _D3_OBJECT *o;
  
  o = (_D3_OBJECT *)TaskCurrent->local;
  (o->rot).vz = 0x400;
  Manim_SetAnim((M_OBJECT *)&o[1].last_pos.vz,0x61);
  pTVar2 = TaskCurrent;
  *(ushort *)&o[1].difficulty = *(ushort *)&o[1].difficulty & 0xfffe;
  pTVar2->event_enable = 0;
  D3_ClearCollBits(o,8);
  uVar1 = o[2].pos.vz;
  while ((uVar1 & 0xf) != 0) {
    if ((uVar1 & 0x1000) != 0) {
      (o->pos).vy = (o->pos).vy + 0x19;
    }
    if ((o[2].pos.vz & 0x4000U) != 0) {
      (o->pos).vy = (o->pos).vy + -0x19;
    }
    if ((o[2].pos.vz & 0x8000U) != 0) {
      (o->pos).vx = (o->pos).vx + -0x19;
    }
    if ((o[2].pos.vz & 0x2000U) != 0) {
      (o->pos).vx = (o->pos).vx + 0x19;
    }
    if ((o[2].pos.vz & PJOY_SHOT) != 0) {
      (o->pos).vz = (o->pos).vz + -0x19;
    }
    if ((o[2].pos.vz & PJOY_BOMB) != 0) {
      (o->pos).vz = (o->pos).vz + 0x19;
    }
    if ((o[2].pos.vz & PJOY_JUMP) != 0) {
      iVar5 = 3;
      psVar4 = &o->index;
      *(undefined4 *)&o[4].pos = 0x3ff6f;
      o->hit_points = 100;
      o[4].b_box.vy = 100;
      *(undefined2 *)&o[4].shapes = 9;
      do {
        psVar4[0xd5] = 100;
        iVar5 = iVar5 + -1;
        psVar4 = psVar4 + -4;
      } while (-1 < iVar5);
      Task_EventExec(Overlay_Handle,Overlay_Handle->event_msg | 0xfc,Overlay_Handle->event_param);
      iVar5 = 0;
      p_Var6 = o;
      if ((o[2].pos.pad & PJOY_JUMP) != 0) {
        do {
          cVar3 = *(char *)&p_Var6[3].comp_opt4 + '\x01';
          if (9 < (int)*(char *)&p_Var6[3].comp_opt4 + 1) {
            cVar3 = '\t';
          }
          *(char *)&p_Var6[3].comp_opt4 = cVar3;
          iVar5 = iVar5 + 1;
          p_Var6 = (_D3_OBJECT *)&p_Var6->child;
        } while (iVar5 < 4);
      }
    }
    if ((o[2].pos.vz & PJOY_ESQUIVE) != 0) {
      Scts_Interruptors = -1;
    }
    Task_Next();
    uVar1 = o[2].pos.vz;
  }
  D3_SetCollBits(o,8);
  TaskCurrent->event_enable = 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pact_Use()
 // line 914, offset 0x80036994
	/* begin block 1 */
		// Start line: 915
		// Start offset: 0x80036994
		// Variables:
	// 		struct _PLAYER *pl; // $s3
	// 		struct _ZONE *z; // $s0
	// 		struct _CAMERA *c; // $s5
	// 		struct _D3_OBJECT *ou; // $s1
	// 		short anm; // $s2
	// 		short last_state; // $s6
	// 		short t; // $s4
	/* end block 1 */
	// End offset: 0x80036CD4
	// End Line: 1049

	/* begin block 2 */
		// Start line: 2220
	/* end block 2 */
	// End Line: 2221

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pact_Use(void)

{
  byte bVar1;
  long Anim;
  int t;
  M_OBJECT *obj;
  _D3_OBJECT *o;
  short unaff_s2;
  _PLAYER *pl;
  short unaff_s4;
  _CAMERA *p_Var2;
  
  pl = (_PLAYER *)TaskCurrent->local;
  TaskCurrent->event_enable = 0;
  t = *(int *)&(pl->m_obj).Env.Obj.primitive_top;
  o = (*(_D3_OBJECT **)(t + 0x2c))->next;
  *(_D3_OBJECT **)&(pl->m_obj).Scale = o;
  p_Var2 = (_CAMERA *)0x0;
  if (*(char *)((int)&o[1].pos.vx + 1) != '\a') {
    Paf_UseCustom(o);
    return;
  }
  bVar1 = Pvl_SctState[(int)o->index];
  if (((o[1].pos.pad & 0xfeU) == 4) && ((Scts_Interruptors & (int)o[1].last_pos.vy) == 0)) {
    obj = (M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data;
    *(undefined4 *)((pl->m_obj).Env.Obj.primitive_top.Data + 0xc) =
         *(undefined4 *)((int)o->description + 0xc);
    Manim_SetAnim(obj,4);
    D3_ClearCollBits(o,1);
    Pl_AdjustUse(pl,(char)o + ',',(int)(o->rot).vz,1);
    D3_SetCollBits(o,1);
    Fx_Play(0x42,0);
    Manim_WaitAnim(obj);
    return;
  }
  switch((int)(((uint)(ushort)o[1].pos.vy - 1) * 0x10000) >> 0x10) {
  case 0:
  case 2:
    unaff_s2 = 3;
    if ((bVar1 & 2) == 0) {
      unaff_s2 = 2;
    }
    unaff_s4 = 1;
    break;
  case 1:
    unaff_s2 = 1;
    unaff_s4 = 2;
    break;
  case 3:
  case 4:
    unaff_s2 = 2;
    unaff_s4 = 3;
    break;
  case 5:
    Pl_ForceAction(pl,0x13,(long)o);
  }
  if (-1 < (int)*(char *)(t + 0x2a)) {
    p_Var2 = Pvl_Cameras + (int)*(char *)(t + 0x2a);
    Track_SetMode(10,t);
  }
  obj = (M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data;
  *(undefined4 *)((pl->m_obj).Env.Obj.primitive_top.Data + 0xc) =
       *(undefined4 *)((int)o->description + 0xc);
  Manim_SetAnim(obj,(int)unaff_s2);
  if (unaff_s4 != 2) {
    D3_ClearCollBits(o,1);
  }
  Pl_AdjustUse(pl,(char)o + ',',(int)(o->rot).vz,1);
  if (unaff_s4 != 2) {
    D3_SetCollBits(o,1);
  }
  if (o[1].pos.vy == 5) {
    Manim_WaitAnim(obj);
    Paf_UseSas(o);
  }
  else {
    Task_EventExec(o->handle,5,(long)pl);
    Manim_WaitAnim(obj);
    if (unaff_s4 == 2) {
      Anim = 2;
    }
    else {
      if (unaff_s4 != 3) goto LAB_80036c5c;
      Anim = 5;
      if ((bVar1 & 2) == 0) {
        Anim = 4;
      }
      Manim_SetAnim(obj,Anim);
      Manim_WaitAnim((M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data);
      Anim = 3;
    }
    obj = (M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data;
    Manim_SetAnim(obj,Anim);
    Manim_WaitAnim(obj);
  }
LAB_80036c5c:
  if (p_Var2 != (_CAMERA *)0x0) {
    if (p_Var2->delay_out == 0) {
      Track_SetMode(2,0);
    }
    else {
      if ((Pvl_LevelNumber != 2) && (Pvl_SectorNumber != 6)) {
        *(ushort *)&(pl->m_obj).Env.Obj.n_primitive =
             *(ushort *)&(pl->m_obj).Env.Obj.n_primitive & 0xfffe;
        Track_Wait();
      }
    }
  }
  TaskCurrent->event_enable = 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Paf_UseSas(struct _D3_OBJECT *ou /*$s2*/)
 // line 1052, offset 0x80036cfc
	/* begin block 1 */
		// Start line: 1053
		// Start offset: 0x80036CFC
		// Variables:
	// 		struct _PLAYER *pl; // $s0
	// 		struct _D3_OBJECT *ot; // $s1
	// 		struct P_ACT_7fake rot; // stack offset -32
	// 		long a; // $s3
	/* end block 1 */
	// End offset: 0x80036F1C
	// End Line: 1144

	/* begin block 2 */
		// Start line: 2509
	/* end block 2 */
	// End Line: 2510

void Paf_UseSas(_D3_OBJECT *ou)

{
  ushort uVar1;
  int iVar2;
  TASK *t;
  _D3_OBJECT *obj;
  void *param;
  _D3_OBJECT *p_Var3;
  uint unaff_s3;
  ushort local_1c;
  
  p_Var3 = ou->child;
  param = TaskCurrent->local;
  while( true ) {
    local_1c = 0;
    if ((*(ushort *)((int)param + 0x108) & 0x8000) != 0) {
      Manim_SetAnim((M_OBJECT *)((int)param + 0xa4),4);
      local_1c = 8;
      unaff_s3 = 0;
    }
    if ((*(ushort *)((int)param + 0x108) & 0x2000) != 0) {
      Manim_SetAnim((M_OBJECT *)((int)param + 0xa4),5);
      local_1c = 0xfff8;
      unaff_s3 = 1;
    }
    if ((*(ushort *)((int)param + 0x10a) & PJOY_JUMP) != 0) break;
    iVar2 = (int)((uint)local_1c << 0x10) >> 0x10;
    if (iVar2 == 0) {
      *(ushort *)((int)param + 0xcc) = *(ushort *)((int)param + 0xcc) & 0xfffe;
    }
    else {
      if (ou[1].pos.pad == 100) {
        if ((*(ushort *)((int)param + 0x108) & 0xa000) != 0) {
          iVar2 = (uint)(ushort)(p_Var3->pos).vx -
                  ((int)(iVar2 + (((uint)local_1c << 0x10) >> 0x1f)) >> 1);
          (p_Var3->pos).vx = (short)iVar2;
          if (iVar2 * 0x10000 >> 0x10 < (int)p_Var3[1].pos.pad) {
            (p_Var3->pos).vx = p_Var3[1].pos.pad;
          }
          if (*(int *)&p_Var3[1].last_pos < (int)(p_Var3->pos).vx) {
            (p_Var3->pos).vx = p_Var3[1].last_pos.vx;
          }
        }
      }
      else {
        t = ou->handle;
        *(uint *)&ou[1].last_pos = *(uint *)&ou[1].last_pos & 0xffff0000 | unaff_s3;
        Task_EventExec(t,5,(long)param);
        uVar1 = *(ushort *)((int)param + 0xcc);
        while ((uVar1 & 0x4000) == 0) {
          if (((int)*(short *)((int)param + 0xc6) & 0x8000U) != 0) {
            obj = p_Var3->child;
            (p_Var3->rot).vz = (p_Var3->rot).vz + local_1c + 0x1000 & 0xfff;
            D3_RotList(obj,0xe0);
          }
          Task_Next();
          uVar1 = *(ushort *)((int)param + 0xcc);
        }
      }
    }
    Task_Next();
  }
  if (ou[1].pos.pad == 100) {
    *(ushort *)((int)param + 0xcc) = *(ushort *)((int)param + 0xcc) & 0xfffe;
  }
  else {
    Manim_SetAnim((M_OBJECT *)((int)param + 0xa4),3);
    Manim_WaitAnim((M_OBJECT *)((int)param + 0xa4));
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Paf_UseCustom(struct _D3_OBJECT *ou /*$a0*/)
 // line 1147, offset 0x80036f38
	/* begin block 1 */
		// Start line: 2787
	/* end block 1 */
	// End Line: 2788

void Paf_UseCustom(_D3_OBJECT *ou)

{
  if (ou->handle != (TASK *)0x0) {
    Task_EventExec(ou->handle,5,0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Paf_TestUse()
 // line 1154, offset 0x80036f68
	/* begin block 1 */
		// Start line: 1155
		// Start offset: 0x80036F68
		// Variables:
	// 		struct _PLAYER *pl; // $s2
	// 		struct _D3_OBJECT *o; // $s1

		/* begin block 1.1 */
			// Start line: 1182
			// Start offset: 0x80037030
			// Variables:
		// 		long dir; // $s0
		// 		long dist; // $s0
		/* end block 1.1 */
		// End offset: 0x800370CC
		// End Line: 1197
	/* end block 1 */
	// End offset: 0x80037110
	// End Line: 1210

	/* begin block 2 */
		// Start line: 2802
	/* end block 2 */
	// End Line: 2803

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Paf_TestUse(void)

{
  _D3_OBJECT *o;
  int iVar1;
  long d1;
  long lVar2;
  uint uVar3;
  _PLAYER *pl;
  
  pl = (_PLAYER *)TaskCurrent->local;
  o = Paf_TestUsePossible(pl);
  if (o == (_D3_OBJECT *)0x0) {
    return;
  }
  if ((o->display_mode & 0x10U) == 0) {
    return;
  }
  if (*(char *)((int)&o[1].pos.vx + 1) == '\a') {
    if (((o[1].pos.vy == 6) && (uVar3 = SEXT24(o[1].last_pos.vy), uVar3 != 0)) &&
       ((Scts_Interruptors & uVar3) == 0)) {
      return;
    }
    iVar1 = (int)(pl->obj).pos.vz - (int)(o->pos).vz;
    if (iVar1 < 0) {
      iVar1 = -iVar1;
    }
    if (0x32 < iVar1) {
      return;
    }
    if (o[1].pos.vy != 3) {
      iVar1 = DeltaDirection((int)(pl->obj).rot.vz,(int)(o->rot).vz);
      if (iVar1 < 0) {
        iVar1 = -iVar1;
      }
      if (0x1ff < iVar1) {
        return;
      }
      if (o[1].pos.vy == 1) {
        d1 = Direction((int)(pl->obj).pos.vx - (int)(o->pos).vx,
                       (int)(pl->obj).pos.vy - (int)(o->pos).vy);
        lVar2 = Distance2D((int)(o->pos).vx,(int)(o->pos).vy,(int)(pl->obj).pos.vx,
                           (int)(pl->obj).pos.vy);
        iVar1 = DeltaDirection(d1,(int)(o->rot).vz);
        if (iVar1 < 0) {
          iVar1 = -iVar1;
        }
        if ((iVar1 < 0x380) && (0x3c < lVar2)) {
          return;
        }
      }
    }
  }
  d1 = Pvl_TestStateBits(o,1);
  if ((d1 == 0) && ((d1 = Pvl_TestStateBits(o,2), d1 == 0 || (o[1].pos.pad != 2)))) {
    Pl_ForceAction(pl,0x11,0);
  }
  return;
}



// decompiled code
// original method signature: 
// struct _D3_OBJECT * /*$ra*/ Paf_TestUsePossible(struct _PLAYER *pl /*$a0*/)
 // line 1213, offset 0x80037128
	/* begin block 1 */
		// Start line: 1215
		// Start offset: 0x80037128
		// Variables:
	// 		struct _ZONE *z; // $v0
	/* end block 1 */
	// End offset: 0x80037154
	// End Line: 1227

	/* begin block 2 */
		// Start line: 2925
	/* end block 2 */
	// End Line: 2926

/* WARNING: Type propagation algorithm not settling */

_D3_OBJECT * Paf_TestUsePossible(_PLAYER *pl)

{
  if (*(short *)((int)&(pl->m_obj).Env.Obj.n_normal + 2) == 0x44) {
    return (*(_D3_OBJECT **)(*(int *)&(pl->m_obj).Env.Obj.primitive_top + 0x2c))->next;
  }
  return (_D3_OBJECT *)0x0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Pact_Spell()
 // line 1236, offset 0x8003715c
	/* begin block 1 */
		// Start line: 1237
		// Start offset: 0x8003715C
		// Variables:
	// 		struct _PLAYER *pl; // $s0
	// 		long spell; // $s2
	/* end block 1 */
	// End offset: 0x8003715C
	// End Line: 1237

	/* begin block 2 */
		// Start line: 2967
	/* end block 2 */
	// End Line: 2968

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Pact_Spell(void)

{
  _PLAYER *pl;
  M_OBJECT *obj;
  long spell;
  
  spell = TaskCurrent->event_param;
  pl = (_PLAYER *)TaskCurrent->local;
  TaskCurrent->event_enable = 0;
  obj = (M_OBJECT *)(pl->m_obj).Env.Obj.primitive_top.Data;
  Manim_SetAnim(obj,(int)(&PSpells)[spell].anim);
  Fx_Play(0,(char)pl + ',');
  PSpell_Effect(pl,spell,1);
  Manim_WaitEvent(obj,0x4000);
  Manim_WaitEvent(obj,0x8000);
  *(ushort *)&(pl->m_obj).Env.Obj.n_primitive = *(ushort *)&(pl->m_obj).Env.Obj.n_primitive & 0xfffe
  ;
  PSpell_Effect(pl,spell,0);
  PSpell_Spell(pl,spell);
  *(ushort *)&(pl->m_obj).Env.Obj.n_primitive = *(ushort *)&(pl->m_obj).Env.Obj.n_primitive | 1;
  Manim_WaitAnim(obj);
  TaskCurrent->event_enable = 1;
  return;
}





