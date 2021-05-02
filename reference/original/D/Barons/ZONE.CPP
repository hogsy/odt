#include "THISDUST.H"
#include "ZONE.H"


// decompiled code
// original method signature: 
// void /*$ra*/ Zone_InitFile()
 // line 28, offset 0x80030308
	/* begin block 1 */
		// Start line: 29
		// Start offset: 0x80030308
		// Variables:
	// 		long i; // $s1
	// 		struct _ZONE *z; // $s2
	// 		long *pIndex; // $s3
	/* end block 1 */
	// End offset: 0x80030388
	// End Line: 43

	/* begin block 2 */
		// Start line: 61
	/* end block 2 */
	// End Line: 62

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Zone_InitFile(void)

{
  short sVar1;
  short *psVar2;
  int iVar3;
  _ZONE *z;
  long *plVar4;
  
  iVar3 = 0;
  if (0 < Pvl_File->n_zones) {
    psVar2 = &Pvl_Zones->nObjects;
    z = Pvl_Zones;
    plVar4 = Pvl_Indices;
    do {
      *(undefined *)((int)psVar2 + 3) = (char)iVar3;
      *(long **)(psVar2 + 2) = plVar4;
      Zone_Constructor(z);
      iVar3 = iVar3 + 1;
      sVar1 = *psVar2;
      psVar2 = psVar2 + 0x18;
      z = z + 1;
      plVar4 = plVar4 + (int)sVar1;
    } while (iVar3 < (int)Pvl_File->n_zones);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Zone_Constructor(struct _ZONE *z /*$a2*/)
 // line 46, offset 0x800303a4
	/* begin block 1 */
		// Start line: 47
		// Start offset: 0x800303A4
		// Variables:
	// 		long i; // $a1
	/* end block 1 */
	// End offset: 0x80030404
	// End Line: 53

	/* begin block 2 */
		// Start line: 123
	/* end block 2 */
	// End Line: 124

void Zone_Constructor(_ZONE *z)

{
  _D3_OBJECT *p_Var1;
  int iVar2;
  
  p_Var1 = Pvl_Objects;
  iVar2 = 0;
  if (0 < z->nObjects) {
    do {
      z->Tab_Objects[iVar2] = (_D3_OBJECT *)((int)p_Var1 + (int)z->Tab_Objects[iVar2] * 0xa4);
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)z->nObjects);
  }
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ Zone_IsPosInZone(struct _ZONE *z /*$a0*/, struct ZONE_7fake *pos /*$a1*/)
 // line 62, offset 0x8003040c
	/* begin block 1 */
		// Start line: 157
	/* end block 1 */
	// End Line: 158

short Zone_IsPosInZone(_ZONE *z,undefined pos)

{
  short sVar1;
  undefined3 in_register_00000015;
  short *psVar2;
  
  psVar2 = (short *)CONCAT31(in_register_00000015,pos);
  sVar1 = 0;
  if (((int)z->x1 <= (int)*psVar2) && (sVar1 = 0, (int)*psVar2 <= (int)z->x2 + -1)) {
    sVar1 = 0;
    if (((int)z->y1 <= (int)psVar2[1]) && (sVar1 = 0, (int)psVar2[1] <= (int)z->y2 + -1)) {
      sVar1 = 0;
      if ((z->z1 <= psVar2[2]) && (sVar1 = 1, z->z2 < psVar2[2])) {
        sVar1 = 0;
      }
    }
  }
  return sVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Zone_DeleteObject(struct _D3_OBJECT *obj /*$a0*/)
 // line 73, offset 0x800304a4
	/* begin block 1 */
		// Start line: 75
		// Start offset: 0x800304A4
		// Variables:
	// 		struct _D3_OBJECT *o; // $v1
	// 		struct _D3_OBJECT **ind; // $v1
	// 		long i; // $a1
	// 		long tmp; // $a2
	/* end block 1 */
	// End offset: 0x8003060C
	// End Line: 108

	/* begin block 2 */
		// Start line: 184
	/* end block 2 */
	// End Line: 185

void Zone_DeleteObject(_D3_OBJECT *obj)

{
  short sVar1;
  _PVL_HEADER *p_Var2;
  _D3_OBJECT **pp_Var3;
  _D3_OBJECT *p_Var4;
  int iVar5;
  int iVar6;
  
  p_Var2 = Pvl_File;
  iVar5 = 0;
  pp_Var3 = (_D3_OBJECT **)Pvl_Indices;
  if (0 < Pvl_File->n_indices) {
    do {
      if (*pp_Var3 == obj) {
        *pp_Var3 = (_D3_OBJECT *)0x0;
      }
      iVar5 = iVar5 + 1;
      pp_Var3 = pp_Var3 + 1;
    } while (iVar5 < (int)p_Var2->n_indices);
  }
  sVar1 = *(short *)((int)&obj[1].handle + 2);
  iVar5 = 0;
  if (sVar1 != -1) {
    iVar6 = 0;
    p_Var4 = Pvl_Objects;
    if (0 < (int)Pvl_File->n_lobjects) {
      do {
        if (*(short *)((int)&p_Var4[1].handle + 2) == sVar1) {
          iVar6 = iVar6 + 1;
        }
        iVar5 = iVar5 + 1;
        p_Var4 = (_D3_OBJECT *)&p_Var4[1].last_pos.vz;
      } while (iVar5 < (int)Pvl_File->n_lobjects);
    }
    if (Pvl_HoleObjects != (_D3_OBJECT *)0x0) {
      p_Var4 = Pvl_HoleObjects;
      do {
        if (*(short *)((int)&p_Var4[1].handle + 2) == *(short *)((int)&obj[1].handle + 2)) {
          iVar6 = iVar6 + 1;
        }
        p_Var4 = p_Var4->next;
      } while (p_Var4 != (_D3_OBJECT *)0x0);
    }
    if (Pvl_GlobalObjects != (_D3_OBJECT *)0x0) {
      p_Var4 = Pvl_GlobalObjects;
      do {
        if (*(short *)((int)&p_Var4[1].handle + 2) == *(short *)((int)&obj[1].handle + 2)) {
          iVar6 = iVar6 + 1;
        }
        p_Var4 = p_Var4->next;
      } while (p_Var4 != (_D3_OBJECT *)0x0);
    }
    if ((iVar6 == 1) && (iVar5 = (int)*(short *)((int)&obj[1].handle + 2), iVar5 != -1)) {
      Pvl_EnemyZones[iVar5].flags = Pvl_EnemyZones[iVar5].flags & 0xfe;
    }
    *(undefined2 *)((int)&obj[1].handle + 2) = 0xffff;
  }
  return;
}



// decompiled code
// original method signature: 
// struct _ZONE * /*$ra*/ Zone_GetZone(struct ZONE_7fake *pos /*$s2*/)
 // line 111, offset 0x80030614
	/* begin block 1 */
		// Start line: 112
		// Start offset: 0x80030614
		// Variables:
	// 		struct _ZONE *z; // $s0
	// 		long i; // $s1
	/* end block 1 */
	// End offset: 0x8003068C
	// End Line: 120

	/* begin block 2 */
		// Start line: 269
	/* end block 2 */
	// End Line: 270

/* WARNING: Unknown calling convention yet parameter storage is locked */

_ZONE * Zone_GetZone(undefined1 pos)

{
  short sVar1;
  _ZONE *z;
  int iVar2;
  
  iVar2 = 0;
  z = Pvl_Zones;
  if (0 < Pvl_File->n_zones) {
    do {
      sVar1 = Zone_IsPosInZone(z,pos);
      iVar2 = iVar2 + 1;
      if (sVar1 != 0) {
        return z;
      }
      z = z + 1;
    } while (iVar2 < (int)Pvl_File->n_zones);
  }
  return (_ZONE *)0x0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Zone_TestObject(struct _D3_OBJECT *obj /*$fp*/)
 // line 123, offset 0x800306a4
	/* begin block 1 */
		// Start line: 124
		// Start offset: 0x800306A4
		// Variables:
	// 		struct ZONE_7fake *p; // stack offset -56
	// 		struct ZONE_7fake *lp; // stack offset -52
	// 		struct _D3_OBJECT *oz; // $v0
	// 		struct _ZONE *z; // $s4
	// 		struct _ZONE *ZoneExit; // stack offset -48
	// 		long i; // $s6
	// 		long j; // $s0
	// 		long Event; // $s1
	// 		long lt; // $s3
	// 		long t; // $s1
	// 		long NeedExit; // $s7
	// 		long NeedCamera; // $s5
	// 		long ChangedCamera; // stack offset -44
	/* end block 1 */
	// End offset: 0x80030958
	// End Line: 230

	/* begin block 2 */
		// Start line: 297
	/* end block 2 */
	// End Line: 298

void Zone_TestObject(_D3_OBJECT *obj)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  _PVL_HEADER *p_Var4;
  short sVar5;
  short sVar6;
  long lVar7;
  int iVar8;
  TASK *t;
  char pos;
  int iVar9;
  int type;
  short *psVar10;
  _ZONE *z;
  int iVar11;
  _ZONE *local_30;
  
  z = Pvl_Zones;
  p_Var4 = Pvl_File;
  bVar2 = false;
  iVar11 = 0;
  pos = (char)obj + ',';
  bVar3 = false;
  obj[1].pos.pad = 0;
  if (0 < p_Var4->n_zones) {
    psVar10 = &z->nObjects;
    do {
      bVar1 = false;
      sVar5 = Zone_IsPosInZone(z,pos);
      sVar6 = Zone_IsPosInZone(z,(char)obj + '4');
      if (*(char *)(psVar10 + -4) == 'I') {
        if (sVar5 != 0) {
          lVar7 = Boxes_GetHeight(obj,pos,300);
          if (lVar7 < (int)(obj->pos).vz) {
            sVar5 = 0;
          }
          if (lVar7 < (int)(obj->last_pos).vz) {
            sVar6 = 0;
          }
          goto LAB_800307a0;
        }
LAB_80030840:
        if (sVar6 != 0) {
          type = 4;
          if (-1 < *(char *)(psVar10 + 1)) {
            bVar1 = true;
          }
          goto LAB_8003085c;
        }
      }
      else {
LAB_800307a0:
        if (sVar5 == 0) goto LAB_80030840;
        if ('?' < *(char *)(psVar10 + -4)) {
          *(_ZONE **)&obj[1].last_pos = z;
          obj[1].pos.pad = (short)*(char *)(psVar10 + -4);
        }
        if (psVar10[-0xc] != 0) {
          bVar2 = true;
          local_30 = z;
        }
        type = 2;
        if (sVar6 == 0) {
          Zone_TextDisplay(z);
          bVar1 = -1 < *(char *)(psVar10 + 1);
          type = 1;
          if ((*(uint *)(psVar10 + -10) & 0xffffff) == 0x504b43) {
            Pvl_CheckPoint(*(uint *)(psVar10 + -10),1);
          }
        }
LAB_8003085c:
        if ((-1 < *(char *)(psVar10 + -4)) && (iVar9 = 0, 0 < *psVar10)) {
          do {
            iVar8 = *(int *)(iVar9 * 4 + *(int *)(psVar10 + 2));
            if (iVar8 != 0) {
              bVar2 = false;
              t = *(TASK **)(iVar8 + 0x14);
              bVar1 = false;
              if ((t != (TASK *)0x0) && (t->event_msg == 0)) {
                Task_EventExec(t,type,(long)obj);
              }
            }
            iVar9 = iVar9 + 1;
          } while (iVar9 < (int)*psVar10);
        }
        if ((bVar1) && (type == 1)) {
          Track_SetMode(10,(long)z);
          bVar3 = true;
        }
        if (((!bVar3) && (bVar1)) && (type == 4)) {
          Track_SetMode(2,0);
        }
        if (bVar2) {
          Pl_ForceAction((_PLAYER *)obj,1,(long)local_30);
        }
      }
      iVar11 = iVar11 + 1;
      psVar10 = psVar10 + 0x18;
      z = z + 1;
    } while (iVar11 < (int)Pvl_File->n_zones);
  }
  return;
}



// decompiled code
// original method signature: 
// struct _ZONE * /*$ra*/ Zone_GetEntry(long id /*$a0*/)
 // line 233, offset 0x80030988
	/* begin block 1 */
		// Start line: 235
		// Start offset: 0x80030988
		// Variables:
	// 		struct _ZONE *z; // $v1
	// 		long i; // $a1
	/* end block 1 */
	// End offset: 0x800309E4
	// End Line: 248

	/* begin block 2 */
		// Start line: 667
	/* end block 2 */
	// End Line: 668

_ZONE * Zone_GetEntry(long id)

{
  _ZONE *p_Var1;
  int iVar2;
  
  iVar2 = 0;
  p_Var1 = Pvl_Zones;
  if (0 < (int)Pvl_File->n_zones) {
    do {
      if ((p_Var1->entry_id != 0) && ((p_Var1->entry_id == id || (id == 0)))) {
        return p_Var1;
      }
      iVar2 = iVar2 + 1;
      p_Var1 = p_Var1 + 1;
    } while (iVar2 < (int)Pvl_File->n_zones);
  }
  return (_ZONE *)0x0;
}



// decompiled code
// original method signature: 
// struct _ZONE * /*$ra*/ Zone_GetObjectExit(struct _D3_OBJECT *o /*$s0*/)
 // line 251, offset 0x800309ec
	/* begin block 1 */
		// Start line: 252
		// Start offset: 0x800309EC
		// Variables:
	// 		struct _ZONE *z; // $v1
	/* end block 1 */
	// End offset: 0x80030A30
	// End Line: 260

	/* begin block 2 */
		// Start line: 704
	/* end block 2 */
	// End Line: 705

_ZONE * Zone_GetObjectExit(_D3_OBJECT *o)

{
  _ZONE *p_Var1;
  _ZONE *p_Var2;
  
  p_Var1 = Zone_GetObjectZone(o);
  while ((p_Var2 = (_ZONE *)0x0, p_Var1 != (_ZONE *)0x0 && (p_Var2 = p_Var1, p_Var1->exit_crc == 0))
        ) {
    p_Var1 = Zone_GetObjectNext(o);
  }
  return p_Var2;
}



// decompiled code
// original method signature: 
// struct _ZONE * /*$ra*/ Zone_GetObjectNext(struct _D3_OBJECT *o /*$a0*/)
 // line 262, offset 0x80030a40
	/* begin block 1 */
		// Start line: 264
		// Start offset: 0x80030A40
		// Variables:
	// 		long i; // $t0
	// 		long j; // $a1
	// 		struct _ZONE *z; // $a2
	/* end block 1 */
	// End offset: 0x80030AD4
	// End Line: 280

	/* begin block 2 */
		// Start line: 731
	/* end block 2 */
	// End Line: 732

_ZONE * Zone_GetObjectNext(_D3_OBJECT *o)

{
  int iVar1;
  _D3_OBJECT **pp_Var2;
  int iVar3;
  _ZONE *p_Var4;
  
  if (Zone_iSearch < (int)Pvl_File->n_zones) {
    do {
      p_Var4 = Pvl_Zones + Zone_iSearch;
      iVar1 = Zone_iSearch + 1;
      iVar3 = 0;
      if (0 < (int)p_Var4->nObjects) {
        pp_Var2 = p_Var4->Tab_Objects;
        do {
          iVar3 = iVar3 + 1;
          if (*pp_Var2 == o) {
            Zone_iSearch = iVar1;
            return p_Var4;
          }
          pp_Var2 = pp_Var2 + 1;
        } while (iVar3 < (int)p_Var4->nObjects);
      }
      iVar3 = Zone_iSearch + 1;
      Zone_iSearch = iVar1;
    } while (iVar3 < (int)Pvl_File->n_zones);
  }
  return (_ZONE *)0x0;
}



// decompiled code
// original method signature: 
// struct _ZONE * /*$ra*/ Zone_GetObjectZone(struct _D3_OBJECT *o /*$a0*/)
 // line 283, offset 0x80030adc
	/* begin block 1 */
		// Start line: 779
	/* end block 1 */
	// End Line: 780

_ZONE * Zone_GetObjectZone(_D3_OBJECT *o)

{
  _ZONE *p_Var1;
  
  Zone_iSearch = 0;
  p_Var1 = Zone_GetObjectNext(o);
  return p_Var1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Zone_IsZoneAttached(struct _D3_OBJECT *obj /*$a0*/)
 // line 291, offset 0x80030b00
	/* begin block 1 */
		// Start line: 293
		// Start offset: 0x80030B00
		// Variables:
	// 		struct _D3_OBJECT **ind; // $v0
	// 		long i; // $v1
	/* end block 1 */
	// End offset: 0x80030B4C
	// End Line: 302

	/* begin block 2 */
		// Start line: 801
	/* end block 2 */
	// End Line: 802

long Zone_IsZoneAttached(_D3_OBJECT *obj)

{
  int iVar1;
  _D3_OBJECT **pp_Var2;
  
  iVar1 = 0;
  pp_Var2 = (_D3_OBJECT **)Pvl_Indices;
  if (0 < (int)Pvl_File->n_indices) {
    do {
      iVar1 = iVar1 + 1;
      if (*pp_Var2 == obj) {
        return 1;
      }
      pp_Var2 = pp_Var2 + 1;
    } while (iVar1 < (int)Pvl_File->n_indices);
  }
  return 0;
}



// decompiled code
// original method signature: 
// struct _ZONE * /*$ra*/ Zone_GetLinkedZone(struct _D3_OBJECT *obj /*$a0*/, char type /*$a1*/)
 // line 304, offset 0x80030b54
	/* begin block 1 */
		// Start line: 306
		// Start offset: 0x80030B54
		// Variables:
	// 		struct _ZONE *z; // $a3
	// 		long i; // $t1
	// 		long j; // $a1
	/* end block 1 */
	// End offset: 0x80030BEC
	// End Line: 319

	/* begin block 2 */
		// Start line: 829
	/* end block 2 */
	// End Line: 830

_ZONE * Zone_GetLinkedZone(_D3_OBJECT *obj,char type)

{
  _D3_OBJECT *p_Var1;
  int iVar2;
  char *pcVar3;
  _ZONE *p_Var4;
  int iVar5;
  
  iVar5 = 0;
  if (0 < (int)Pvl_File->n_zones) {
    pcVar3 = &Pvl_Zones->type;
    p_Var4 = Pvl_Zones;
    do {
      iVar2 = 0;
      if (0 < (int)*(short *)(pcVar3 + 8)) {
        p_Var1 = *(_D3_OBJECT **)(pcVar3 + 0xc);
        do {
          if ((*(_D3_OBJECT **)p_Var1 == obj) && (*pcVar3 == type)) {
            return p_Var4;
          }
          iVar2 = iVar2 + 1;
          p_Var1 = (_D3_OBJECT *)((_D3_OBJECT **)p_Var1 + 1);
        } while (iVar2 < (int)*(short *)(pcVar3 + 8));
      }
      iVar5 = iVar5 + 1;
      pcVar3 = pcVar3 + 0x30;
      p_Var4 = p_Var4 + 1;
    } while (iVar5 < (int)Pvl_File->n_zones);
  }
  return (_ZONE *)0x0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Zone_TextDisplay(struct _ZONE *z /*$s0*/)
 // line 322, offset 0x80030bf4
	/* begin block 1 */
		// Start line: 323
		// Start offset: 0x80030BF4
		// Variables:
	// 		long i; // $v1
	/* end block 1 */
	// End offset: 0x80030CC4
	// End Line: 356

	/* begin block 2 */
		// Start line: 866
	/* end block 2 */
	// End Line: 867

void Zone_TextDisplay(_ZONE *z)

{
  int iVar1;
  int iVar2;
  _D3_OBJECT **pp_Var3;
  
  if (((z->mode & 0x10U) != 0) || ((Pvl_Texts != (long *)0x0 && (-1 < z->text_index)))) {
    iVar1 = (int)z->nObjects;
    if (iVar1 != 0) {
      iVar2 = 0;
      if (0 < iVar1) {
        pp_Var3 = z->Tab_Objects;
        do {
          if (*pp_Var3 != (_D3_OBJECT *)0x0) break;
          iVar2 = iVar2 + 1;
          pp_Var3 = pp_Var3 + 1;
        } while (iVar2 < iVar1);
        iVar1 = (int)z->nObjects;
      }
      if (iVar2 == iVar1) {
        return;
      }
    }
    if (Zone_TextHandle != (TASK *)0x0) {
      Task_Kill(Zone_TextHandle);
      Zone_TextHandle = (TASK *)0x0;
    }
    Zone_TextHandle = Task_Link(Zone_TxtDispTask,0);
    *(_ZONE **)&Zone_TextHandle->local = z;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Zone_TxtDispTask()
 // line 359, offset 0x80030cd4
	/* begin block 1 */
		// Start line: 360
		// Start offset: 0x80030CD4
		// Variables:
	// 		struct _ZONE *z; // $s0
	// 		long index; // $s1
	// 		long i; // $s0
	// 		struct ZONE_104fake t; // stack offset -48
	/* end block 1 */
	// End offset: 0x80030EAC
	// End Line: 417

	/* begin block 2 */
		// Start line: 942
	/* end block 2 */
	// End Line: 943

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Zone_TxtDispTask(void)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  _ZONE *z;
  int index;
  undefined auStack48 [32];
  
  z = (_ZONE *)TaskCurrent->local;
  sVar1 = z->text_index;
  TaskCurrent->destructor = Zone_TxtDispDestructor;
  if (((z->mode & 0x20U) == 0) ||
     (uVar3 = (int)z->keymask << 0x10 | (int)z->intermask, (uVar3 & Scts_Interruptors) != uVar3)) {
    Text_SetContext((TEXT_102fake *)auStack48);
    Text_SetContextFont(0x70);
    Text_SetContextXY(0,0);
    Text_SetContextWH(Scr_W,Scr_H);
    Text_SetContextRange(0);
    Text_SetContextMode(0);
    if ((z->mode & 0x10U) == 0) {
      if ((z->mode & 1U) != 0) {
        Pvl_SetZoneStateBits(z,1);
        z->text_index = -1;
      }
      index = 0;
      while (sVar2 = Text_AmountOfTexts((char *)Pvl_Texts[(int)sVar1]), index < (int)sVar2) {
        Text_DisplayLine((char *)Pvl_Texts[(int)sVar1],index,0x5a,(long *)0x0);
        index = index + 1;
      }
    }
    else {
      z->text_index = -1;
      z->mode = z->mode & 0xffffffef;
      Pvl_SetZoneStateBits(z,1);
      Pvl_nSecrets = Pvl_nSecrets + 1;
      index = 0;
      while (sVar1 = Text_AmountOfTexts((char *)Pvl_UtilityTexts[0x4e]), index < (int)sVar1) {
        Text_DisplayLine((char *)Pvl_UtilityTexts[0x4e],index,0x5a,(long *)0x0);
        index = index + 1;
      }
    }
    Task_Sleep(2);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Zone_TxtDispDestructor(struct TASK *t /*$a0*/)
 // line 420, offset 0x80030ec0
	/* begin block 1 */
		// Start line: 1080
	/* end block 1 */
	// End Line: 1081

void Zone_TxtDispDestructor(TASK *t)

{
  Zone_TextHandle = (TASK *)0x0;
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ Zone_GetEnemyZone(short x /*$a0*/, short y /*$a1*/, short z /*$a2*/, unsigned long low /*$a3*/, unsigned long high /*stack 16*/)
 // line 427, offset 0x80030ecc
	/* begin block 1 */
		// Start line: 428
		// Start offset: 0x80030ECC
		// Variables:
	// 		struct _ENEMYZONE *zo; // $v1
	// 		int i; // $t0
	/* end block 1 */
	// End offset: 0x80030FD8
	// End Line: 449

	/* begin block 2 */
		// Start line: 1097
	/* end block 2 */
	// End Line: 1098

short Zone_GetEnemyZone(short x,short y,short z,ulong low,ulong high)

{
  short *psVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < (int)Pvl_File->n_enemyzones) {
    iVar2 = 0;
    do {
      psVar1 = (short *)((int)&Pvl_EnemyZones->x1 + iVar2);
      if ((((((low & 1) != 0) && (*psVar1 <= x)) && (x <= psVar1[3])) &&
          ((psVar1[1] <= y && (y <= psVar1[4])))) &&
         ((psVar1[2] <= z && ((z <= psVar1[5] && ((*(byte *)((int)psVar1 + 0xd) & 0x21) == 0)))))) {
        return (short)iVar3;
      }
      low = low >> 1;
      if (iVar3 == 0x1f) {
        low = high;
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x18;
    } while (iVar3 < (int)Pvl_File->n_enemyzones);
  }
  return -1;
}



// decompiled code
// original method signature: 
// short /*$ra*/ Zone_GetEnemyZonePath(short xs /*$s5*/, short ys /*$s4*/, short zs /*$a2*/, short xd /*$a3*/, int yd /*stack 16*/, int zd /*stack 20*/, unsigned long low /*stack 24*/, unsigned long high /*stack 28*/, short *res /*stack 32*/)
 // line 463, offset 0x80030fe0
	/* begin block 1 */
		// Start line: 464
		// Start offset: 0x80030FE0
		// Variables:
	// 		struct _BACKPOINTER list[64]; // stack offset -296
	// 		unsigned long l; // $a3
	// 		unsigned long h; // $t4
	// 		long current; // $t1
	// 		long newel; // $t2
	// 		long sour; // $s1
	// 		long dest; // $a1
	// 		long old; // $t7
	// 		long i; // $s0
	// 		long j; // $a1
	// 		long x1; // $a0
	// 		long x2; // $a3
	// 		long y1; // $a2
	// 		long y2; // $v1
	/* end block 1 */
	// End offset: 0x800314C0
	// End Line: 569

	/* begin block 2 */
		// Start line: 1183
	/* end block 2 */
	// End Line: 1184

short Zone_GetEnemyZonePath
                (short xs,short ys,short zs,short xd,int yd,int zd,ulong low,ulong high,short *res)

{
  byte bVar1;
  short sVar2;
  short *psVar3;
  long lVar4;
  int iVar5;
  int iVar6;
  _ENEMYZONE *p_Var7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  short local_128 [128];
  
  *res = 0x7fff;
  res[1] = 0x7fff;
  res[2] = -1;
  sVar2 = Zone_GetEnemyZone(xs,ys,zs,low,high);
  iVar16 = (int)sVar2;
  sVar2 = Zone_GetEnemyZone(xd,(short)yd,(short)zd,low,high);
  iVar8 = (int)sVar2;
  sVar2 = -1;
  if (((iVar16 != -1) && (iVar8 != -1)) && (sVar2 = 0, iVar16 != iVar8)) {
    iVar15 = 0;
    if (0 < Pvl_File->n_enemyzones) {
      iVar6 = 0;
      do {
        iVar12 = (int)&Pvl_EnemyZones->x1 + iVar6;
        *(byte *)(iVar12 + 0xd) = *(byte *)(iVar12 + 0xd) & 0x3f;
        iVar15 = iVar15 + 1;
        iVar6 = iVar6 + 0x18;
      } while (iVar15 < (int)Pvl_File->n_enemyzones);
    }
    iVar13 = 0;
    iVar12 = -1;
    iVar15 = -4;
    iVar6 = iVar8;
    while( true ) {
      Pvl_EnemyZones[iVar6].flags = Pvl_EnemyZones[iVar6].flags | 0x80;
      uVar11 = Pvl_EnemyZones[iVar6].low & low;
      uVar14 = Pvl_EnemyZones[iVar6].high & high;
      if (((uVar14 | uVar11) != 0) && (iVar9 = 0, 0 < Pvl_File->n_enemyzones)) {
        iVar10 = 0;
        do {
          p_Var7 = Pvl_EnemyZones;
          if ((((uVar11 & 1) != 0) &&
              (bVar1 = (&Pvl_EnemyZones->flags)[iVar10], (bVar1 & 0x81) == 0)) &&
             (((Pvl_EnemyZones[iVar6].flags & bVar1 & 0xc) != 0 ||
              (((Pvl_EnemyZones[iVar6].flags & 0xc) == 0 || ((bVar1 & 0xc) == 0)))))) {
            if (iVar16 == iVar9) {
              p_Var7 = Pvl_EnemyZones + iVar6;
              if ((p_Var7->flags & 0x20) == 0) {
                psVar3 = (short *)((int)&Pvl_EnemyZones->x1 + iVar10);
                if (p_Var7->type == '\x03') {
                  iVar12 = (int)psVar3[1];
                  iVar8 = (int)*psVar3 + (int)psVar3[3];
                  iVar15 = (int)psVar3[4];
                }
                else {
                  iVar8 = (int)p_Var7->x1;
                  if ((int)p_Var7->x1 < (int)*psVar3) {
                    iVar8 = (int)*psVar3;
                  }
                  iVar15 = (int)Pvl_EnemyZones[iVar16].x2;
                  if ((int)Pvl_EnemyZones[iVar6].x2 <= (int)Pvl_EnemyZones[iVar16].x2) {
                    iVar15 = (int)Pvl_EnemyZones[iVar6].x2;
                  }
                  iVar12 = (int)Pvl_EnemyZones[iVar16].y1;
                  if ((int)Pvl_EnemyZones[iVar16].y1 <= (int)Pvl_EnemyZones[iVar6].y1) {
                    iVar12 = (int)Pvl_EnemyZones[iVar6].y1;
                  }
                  iVar8 = iVar8 + iVar15;
                  iVar15 = (int)Pvl_EnemyZones[iVar6].y2;
                  if ((int)Pvl_EnemyZones[iVar16].y2 < (int)Pvl_EnemyZones[iVar6].y2) {
                    iVar15 = (int)Pvl_EnemyZones[iVar16].y2;
                  }
                }
                *res = (short)(iVar8 >> 1);
                p_Var7 = Pvl_EnemyZones;
                iVar15 = iVar12 + iVar15 >> 1;
                res[1] = (short)iVar15;
                p_Var7 = p_Var7 + iVar16;
                iVar8 = (int)p_Var7->x1 + (int)p_Var7->x2 >> 1;
                iVar16 = (int)p_Var7->y1 + (int)p_Var7->y2 >> 1;
                if ((((int)*res - iVar8 ^ (int)xs - iVar8) < 0) ||
                   ((iVar15 - iVar16 ^ (int)ys - iVar16) < 0)) {
                  lVar4 = Direction(iVar8 - (int)xs,iVar16 - (int)ys);
                  res[2] = (short)lVar4;
                }
                else {
                  res[2] = -1;
                }
                return (short)((uint)((iVar6 + 1) * 0x10000) >> 0x10);
              }
              *res = (short)((int)Pvl_EnemyZones[iVar8].x1 + (int)Pvl_EnemyZones[iVar8].x2 >> 1);
              res[1] = (short)((int)Pvl_EnemyZones[iVar8].y1 + (int)Pvl_EnemyZones[iVar8].y2 >> 1);
              return -2;
            }
            local_128[iVar13 * 2] = (short)iVar12;
            local_128[iVar13 * 2 + 1] = (short)iVar9;
            iVar5 = (int)&p_Var7->x1 + iVar10;
            iVar13 = iVar13 + 1;
            *(byte *)(iVar5 + 0xd) = *(byte *)(iVar5 + 0xd) | 0x80;
          }
          uVar11 = uVar11 >> 1;
          if (iVar9 == 0x1f) {
            uVar11 = uVar14;
          }
          iVar9 = iVar9 + 1;
          iVar10 = iVar10 + 0x18;
        } while (iVar9 < (int)Pvl_File->n_enemyzones);
      }
      iVar12 = iVar12 + 1;
      if (iVar12 == iVar13) break;
      if (iVar12 != 0) {
        iVar8 = (int)local_128[(int)*(short *)((int)local_128 + iVar15 + 4) * 2 + 1];
      }
      iVar6 = (int)*(short *)((int)local_128 + iVar15 + 6);
      iVar15 = iVar15 + 4;
    }
    sVar2 = 0;
  }
  return sVar2;
}





