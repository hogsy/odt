#include "THISDUST.H"
#include "OBJECT.H"


// decompiled code
// original method signature: 
// void /*$ra*/ Object_Init()
 // line 42, offset 0x8002fc54
	/* begin block 1 */
		// Start line: 85
	/* end block 1 */
	// End Line: 86

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Object_Init(void)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Object_InitFile()
 // line 53, offset 0x8002fc5c
	/* begin block 1 */
		// Start line: 54
		// Start offset: 0x8002FC5C
		// Variables:
	// 		short i; // $s1
	// 		struct _D3_OBJECT *o; // $s0
	/* end block 1 */
	// End offset: 0x8002FD6C
	// End Line: 72

	/* begin block 2 */
		// Start line: 116
	/* end block 2 */
	// End Line: 117

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Object_InitFile(void)

{
  _D3_OBJECT *o;
  int iVar1;
  
  iVar1 = 0;
  o = Pvl_Objects;
  if (0 < Pvl_File->n_lobjects) {
    do {
      Object_Constructor(o,(_D3_OBJECT **)0x0);
      iVar1 = iVar1 + 1;
      o = (_D3_OBJECT *)&o[1].last_pos.vz;
    } while (iVar1 * 0x10000 >> 0x10 < (int)Pvl_File->n_lobjects);
  }
  iVar1 = 0;
  o = Pvl_HoleObjects;
  if (0 < Pvl_File->n_hobjects) {
    do {
      Object_Constructor(o,&Pvl_HoleObjects);
      iVar1 = iVar1 + 1;
      o = (_D3_OBJECT *)&o[1].last_pos.vz;
    } while (iVar1 * 0x10000 >> 0x10 < (int)Pvl_File->n_hobjects);
  }
  iVar1 = 0;
  o = Pvl_GlobalObjects;
  if (0 < Pvl_File->n_gobjects) {
    do {
      Object_Constructor(o,&Pvl_GlobalObjects);
      iVar1 = iVar1 + 1;
      o = (_D3_OBJECT *)&o[1].last_pos.vz;
    } while (iVar1 * 0x10000 >> 0x10 < (int)Pvl_File->n_gobjects);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Object_Constructor(struct _D3_OBJECT *o /*$s1*/, struct _D3_OBJECT **list /*$s5*/)
 // line 75, offset 0x8002fd80
	/* begin block 1 */
		// Start line: 76
		// Start offset: 0x8002FD80
		// Variables:
	// 		void *Lnk_Skls; // $s3
	// 		void *Lnk_Envs; // $s2
	// 		short tmd_file; // $s0
	// 		short mindex; // $s4
	// 		struct M_OBJECT *mo; // $s0
	/* end block 1 */
	// End offset: 0x80030228
	// End Line: 233

	/* begin block 2 */
		// Start line: 163
	/* end block 2 */
	// End Line: 164

void Object_Constructor(_D3_OBJECT *o,_D3_OBJECT **list)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  TMD_72fake *Tmd;
  void *File;
  void *File_00;
  _struct_256 _Var4;
  MOTION_96fake *Env;
  MOTION_98fake *buff;
  TASK *pTVar5;
  int iVar6;
  _D3_OBJECT *p_Var7;
  undefined4 uVar8;
  short index;
  M_OBJECT *obj;
  
  index = *(short *)((int)&o->description + 2);
  sVar2 = *(short *)&o->description;
  uVar8 = *(undefined4 *)&(o->pos).vz;
  *(undefined4 *)&o->last_pos = *(undefined4 *)&o->pos;
  *(undefined4 *)&(o->last_pos).vz = uVar8;
  uVar3 = o->collision_mode;
  (o->rot).pad = (o->rot).vz;
  if ((uVar3 & 0x200) == 0) {
    File = FileGroup_GetAddr(Pvl_Lnk,2);
    Tmd = (TMD_72fake *)FileGroup_GetAddr(File,(int)index);
    *(TMD_72fake **)&o->description = Tmd;
    Tmd_InitFile(Tmd);
    Shp_TmdToVram(Pvl_Pcl,o->description,0,1);
  }
  else {
    D3_ClearCollBits(o,4);
    uVar3 = o[1].pos.vy;
    if ((uint)uVar3 - 2 < 2) {
      if (o[1].pos.pad == 0) {
        bVar1 = Pl_Ammos[(int)o[1].pos.vz + (int)Pvl_PlayerNumber * 4];
        index = o[1].pos.vy;
        o[1].pos.vz = (ushort)bVar1;
        if (index == 2) {
          index = -0xc - (ushort)bVar1;
        }
        else {
          index = -0x11 - (ushort)bVar1;
        }
      }
    }
    else {
      if (Pvl_PlayerNumber == 5) {
        if (uVar3 == 1) {
          o[1].pos.vy = 0;
          index = -7;
        }
        else {
          if (uVar3 == 0) {
            o[1].pos.vy = 1;
            index = -10;
          }
        }
      }
    }
    o->comp_opt1 = index;
    Object_TakenSetDescription(o,index);
  }
  if ((o->display_mode & 0x40U) == 0) {
    if ((o->display_mode & 0x1000U) == 0) {
      o->description = (void *)((int)o->description + 0xc);
    }
  }
  else {
    File = FileGroup_GetAddr(Pvl_Lnk,3);
    File_00 = FileGroup_GetAddr(Pvl_Lnk,4);
    obj = (M_OBJECT *)(&Pvl_Mobjects->sit + (int)sVar2 * 0xd);
    obj->sit = o;
    if ((o->display_mode & 0x1000U) == 0) {
      _Var4 = (_struct_256)FileGroup_GetAddr(File,(int)(short)(obj->Sq).Header.Version);
      (obj->Sq).Header = _Var4;
      *(undefined *)((int)_Var4 + 3) = 0x40;
      Env = (MOTION_96fake *)FileGroup_GetAddr(File_00,(int)(short)(obj->Sq).Data.FatherTrans[0]);
      *(MOTION_96fake **)(obj->Sq).Data.FatherTrans = Env;
      Motion_InitEnv(Env,(MOTION_72fake *)o->description);
    }
    else {
      *(void **)(obj->Sq).Data.FatherTrans = o->description;
    }
    *(M_OBJECT **)&o->description = obj;
    if (-1 < *(int *)((obj->Sq).Data.FatherTrans + 2)) {
      File = FileGroup_GetAddr(Pvl_Lnk,5);
      buff = (MOTION_98fake *)FileGroup_GetAddr(File,(int)(short)(obj->Sq).Data.FatherTrans[2]);
      *(MOTION_98fake **)((obj->Sq).Data.FatherTrans + 2) = buff;
      Motion_InitAni(buff);
      Manim_ForceAnim(obj,0);
      if (*(char *)((int)&o[1].pos.vx + 1) != '\0') {
        (obj->Env).Obj.normal_top.vx = (obj->Env).Obj.normal_top.vx & 0xfffe;
      }
    }
  }
  if ((o->display_mode & 4U) != 0) {
    o->matrices = Pvl_Matrix + (int)o->matrices;
  }
  if (*(short *)((int)&o->b_hurt + 2) != 0) {
    o->shapes = Pvl_Shapes + (int)o->shapes;
  }
  iVar6 = (int)*(short *)((int)&o[1].father + 2);
  if (-1 < iVar6) {
    *(ushort *)((int)&o[1].father + 2) = (ushort)(byte)Pvl_Sounds[iVar6];
  }
  o->list = list;
  if ((int)o->prec < 0) {
    o->prec = (_D3_OBJECT *)0x0;
  }
  else {
    o->prec = (_D3_OBJECT *)((int)Pvl_Objects + (int)o->prec * 0xa4);
  }
  if ((int)o->next < 0) {
    o->next = (_D3_OBJECT *)0x0;
  }
  else {
    o->next = (_D3_OBJECT *)((int)Pvl_Objects + (int)o->next * 0xa4);
  }
  if ((int)o->child < 0) {
    o->child = (_D3_OBJECT *)0x0;
  }
  else {
    o->child = (_D3_OBJECT *)((int)Pvl_Objects + (int)o->child * 0xa4);
  }
  p_Var7 = o->father;
  if ((int)p_Var7 < 0) {
    if ((int)p_Var7 < -1) {
      o->father = (_D3_OBJECT *)((int)Pvl_Platforms + (int)p_Var7 * -0xa4 + -0x148);
    }
    else {
      o->father = (_D3_OBJECT *)0x0;
    }
  }
  else {
    o->father = (_D3_OBJECT *)((int)Pvl_Objects + (int)p_Var7 * 0xa4);
  }
  iVar6 = (int)*(char *)((int)&o[1].pos.vx + 1);
  if ((iVar6 == 0) ||
     ((TDRFuncPtr_Task_Link0f)(&Object_Comps)[iVar6 + -1] == (TDRFuncPtr_Task_Link0f)0x0)) {
    o->handle = (TASK *)0x0;
  }
  else {
    pTVar5 = Task_Link((TDRFuncPtr_Task_Link0f)(&Object_Comps)[iVar6 + -1],0x300);
    o->handle = pTVar5;
    *(_D3_OBJECT **)&pTVar5->local = o;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Object_TakenSetDescription(struct _D3_OBJECT *o /*$s1*/, short index /*$a1*/)
 // line 236, offset 0x8003024c
	/* begin block 1 */
		// Start line: 499
	/* end block 1 */
	// End Line: 500

void Object_TakenSetDescription(_D3_OBJECT *o,short index)

{
  void *pvVar1;
  
  if (index < -0x40) {
    pvVar1 = FileGroup_GetAddr(Pvl_LnkLocals,(int)(short)-(index + 0x41));
    o->description = pvVar1;
  }
  else {
    pvVar1 = FileGroup_GetAddr(Pvl_LnkGlobals,(int)~index);
    o->description = pvVar1;
    Object_SetIndexInElement(o,~index);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Object_SetIndexInElement(struct _D3_OBJECT *obj /*$a0*/, short index /*$a1*/)
 // line 254, offset 0x800302d4
	/* begin block 1 */
		// Start line: 538
	/* end block 1 */
	// End Line: 539

void Object_SetIndexInElement(_D3_OBJECT *obj,short index)

{
  short sVar1;
  
  sVar1 = obj[1].pos.vy;
  if (sVar1 == 2) {
    obj[1].pos.pad = index + -8;
    return;
  }
  if (sVar1 != 3) {
    return;
  }
  obj[1].pos.pad = index + -0xc;
  return;
}





