#include "THISDUST.H"
#include "VIS.H"


// decompiled code
// original method signature: 
// void /*$ra*/ Vis_Init()
 // line 15, offset 0x800314ec
	/* begin block 1 */
		// Start line: 31
	/* end block 1 */
	// End Line: 32

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Vis_Init(void)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Vis_InitFile()
 // line 20, offset 0x800314f4
	/* begin block 1 */
		// Start line: 21
		// Start offset: 0x800314F4
		// Variables:
	// 		long i; // $t3
	// 		long j; // $a2
	// 		long n; // $a3
	// 		long s; // $v0
	// 		long nz; // $a1
	// 		long np; // $t1
	// 		char *v; // $t0
	// 		struct _PLATFORM **plats; // $v0
	// 		struct _VISIBILITY **vis; // $a0
	// 		struct _VISPORTAL *z; // $v0
	/* end block 1 */
	// End offset: 0x80031630
	// End Line: 63

	/* begin block 2 */
		// Start line: 40
	/* end block 2 */
	// End Line: 41

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Vis_InitFile(void)

{
  short sVar1;
  _PLATFORM *p_Var2;
  char **ptt;
  char **ppcVar3;
  _PLATFORM **pp_Var4;
  int iVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  char **ppcVar9;
  int iVar10;
  
  ptt = (char **)Heap_AllocMem(0x400);
  p_Var2 = Pvl_Platforms;
  iVar6 = 0;
  iVar10 = 0;
  pcVar8 = Pvl_Visibility;
  ppcVar9 = ptt;
  if (0 < Pvl_File->n_visibilitys) {
    do {
      iVar5 = 0;
      *ppcVar9 = pcVar8;
      sVar1 = *(short *)(pcVar8 + 0x12);
      pp_Var4 = (_PLATFORM **)(pcVar8 + (int)*(short *)(pcVar8 + 0x10) * 8 + 0x18);
      if (0 < (int)sVar1) {
        do {
          iVar5 = iVar5 + 1;
          *pp_Var4 = (_PLATFORM *)((int)p_Var2 + (int)*pp_Var4 * 0xa4);
          pp_Var4 = pp_Var4 + 1;
        } while (iVar5 < (int)sVar1);
      }
      iVar10 = iVar10 + 1;
      iVar5 = (int)*(short *)(*ppcVar9 + 0x10) * 8 + (int)*(short *)(*ppcVar9 + 0x12) * 4 + 0x18;
      iVar6 = iVar6 + iVar5;
      pcVar8 = pcVar8 + iVar5;
      ppcVar9 = ppcVar9 + 1;
    } while (iVar6 < (int)Pvl_File->n_visibilitys);
  }
  iVar6 = 0;
  ppcVar9 = ptt;
  if (0 < iVar10) {
    do {
      iVar7 = 0;
      iVar5 = (int)*(short *)(*ppcVar9 + 0x10);
      ppcVar3 = (char **)(*ppcVar9 + 0x18);
      if (0 < iVar5) {
        do {
          iVar7 = iVar7 + 1;
          *ppcVar3 = ptt[(int)*ppcVar3];
          ppcVar3 = ppcVar3 + 2;
        } while (iVar7 < iVar5);
      }
      iVar6 = iVar6 + 1;
      ppcVar9 = ppcVar9 + 1;
    } while (iVar6 < iVar10);
  }
  Heap_FreeMem(ptt);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Vis_TestObjects(struct _D3_OBJECT *ot /*$a0*/, struct _D3_OBJECT *obj /*$s0*/)
 // line 67, offset 0x80031648
	/* begin block 1 */
		// Start line: 68
		// Start offset: 0x80031648
		// Variables:
	// 		struct _VISIBILITY *v1; // $s0
	// 		struct _VISIBILITY *v2; // $a1
	// 		struct _VISPORTAL *z1; // $v0
	// 		long i; // $v1
	/* end block 1 */
	// End offset: 0x800316C0
	// End Line: 88

	/* begin block 2 */
		// Start line: 197
	/* end block 2 */
	// End Line: 198

long Vis_TestObjects(_D3_OBJECT *ot,_D3_OBJECT *obj)

{
  _VISIBILITY *p_Var1;
  _VISIBILITY *p_Var2;
  int iVar3;
  _VISIBILITY *p_Var4;
  
  p_Var1 = Vis_GetVisPos((char)ot + ',');
  p_Var2 = Vis_GetVisPos((char)obj + ',');
  iVar3 = 0;
  if (p_Var1 != p_Var2) {
    p_Var4 = p_Var1 + 1;
    if (0 < (int)p_Var1->n_zones) {
      do {
        iVar3 = iVar3 + 1;
        if (*(_VISIBILITY **)p_Var4 == p_Var2) {
          return 1;
        }
        p_Var4 = (_VISIBILITY *)&p_Var4->y2;
      } while (iVar3 < (int)p_Var1->n_zones);
    }
  }
  return 0;
}



// decompiled code
// original method signature: 
// struct _VISIBILITY * /*$ra*/ Vis_GetVisPos(struct VIS_7fake *pos /*$a0*/)
 // line 91, offset 0x800316d0
	/* begin block 1 */
		// Start line: 93
		// Start offset: 0x800316D0
		// Variables:
	// 		long x; // $a3
	// 		long y; // $a2
	// 		long i; // $a1
	// 		long s; // $v0
	// 		long w; // $t1
	// 		long h; // $a1
	// 		struct _VISIBILITY *vis; // $a0
	/* end block 1 */
	// End offset: 0x80031820
	// End Line: 126

	/* begin block 2 */
		// Start line: 255
	/* end block 2 */
	// End Line: 256

/* WARNING: Unknown calling convention yet parameter storage is locked */

_VISIBILITY * Vis_GetVisPos(undefined pos)

{
  uint uVar1;
  int iVar2;
  undefined3 in_register_00000011;
  int iVar3;
  int iVar4;
  _VISIBILITY *p_Var5;
  int iVar6;
  int iVar7;
  
  iVar7 = (int)*(short *)CONCAT31(in_register_00000011,pos);
  iVar6 = (int)((short *)CONCAT31(in_register_00000011,pos))[1];
  uVar1 = (uint)(ushort)Pvl_File->map_w << 0x10;
  iVar3 = ((int)(((int)uVar1 >> 0x10) + (uVar1 >> 0x1f)) >> 1) * 100;
  iVar4 = iVar3 + 0x76b;
  uVar1 = (uint)(ushort)Pvl_File->map_h << 0x10;
  iVar2 = ((int)(((int)uVar1 >> 0x10) + (uVar1 >> 0x1f)) >> 1) * 100;
  if (iVar4 < iVar7) {
    iVar7 = iVar4;
  }
  iVar3 = -(iVar3 + 1999);
  if (iVar7 < iVar3) {
    iVar7 = iVar3;
  }
  iVar3 = iVar2 + 0x76b;
  if (iVar3 < iVar6) {
    iVar6 = iVar3;
  }
  iVar2 = -(iVar2 + 1999);
  if (iVar6 < iVar2) {
    iVar6 = iVar2;
  }
  iVar2 = 0;
  p_Var5 = (_VISIBILITY *)Pvl_Visibility;
  if (0 < (int)Pvl_File->n_visibilitys) {
    do {
      if (((((int)p_Var5->x1 <= iVar7) && (iVar7 <= (int)p_Var5->x2)) && ((int)p_Var5->y1 <= iVar6))
         && (iVar6 <= (int)p_Var5->y2)) {
        return p_Var5;
      }
      iVar2 = iVar2 + (int)p_Var5->n_zones * 8 + (int)p_Var5->n_plats * 4 + 0x18;
      p_Var5 = (_VISIBILITY *)(&p_Var5[1].x1 + (int)p_Var5->n_plats * 2 + (int)p_Var5->n_zones * 4);
    } while (iVar2 < (int)Pvl_File->n_visibilitys);
  }
  return (_VISIBILITY *)0x0;
}





