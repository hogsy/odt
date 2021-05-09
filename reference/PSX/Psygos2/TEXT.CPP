#include "THISDUST.H"
#include "TEXT.H"


// decompiled code
// original method signature: 
// void /*$ra*/ Text_Init()
 // line 59, offset 0x800a2fe0
	/* begin block 1 */
		// Start line: 119
	/* end block 1 */
	// End Line: 120

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Text_Init(void)

{
  Tab_Char2 = (char *)0x0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Text_AllocMem(long size /*$s0*/)
 // line 65, offset 0x800a2fec
	/* begin block 1 */
		// Start line: 130
	/* end block 1 */
	// End Line: 131

void Text_AllocMem(long size)

{
  if (Tab_Char2 != (char *)0x0) {
    Heap_FreeMem(Tab_Char2);
  }
  Tab_Char2 = (char *)Heap_AllocMem(size << 1);
  PTR_800b42a4 = Tab_Char2 + size;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Text_FreeMem()
 // line 77, offset 0x800a3034
	/* begin block 1 */
		// Start line: 155
	/* end block 1 */
	// End Line: 156

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Text_FreeMem(void)

{
  if (Tab_Char2 != (char *)0x0) {
    Heap_FreeMem(Tab_Char2);
  }
  Tab_Char2 = (char *)0x0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Text_InitFont(struct TEXT_101fake *f /*$s0*/, void *pcl /*$a1*/, short s /*$a2*/, short type /*$s1*/)
 // line 86, offset 0x800a305c
	/* begin block 1 */
		// Start line: 87
		// Start offset: 0x800A305C
		// Variables:
	// 		long i; // $a0
	/* end block 1 */
	// End offset: 0x800A3180
	// End Line: 135

	/* begin block 2 */
		// Start line: 173
	/* end block 2 */
	// End Line: 174

void Text_InitFont(undefined f,void *pcl,short s,short type)

{
  int iVar1;
  void **ppvVar2;
  uchar *puVar3;
  undefined3 in_register_00000011;
  void **ppvVar4;
  int iVar5;
  uchar *puVar6;
  
  ppvVar4 = (void **)CONCAT31(in_register_00000011,f);
  *ppvVar4 = pcl;
  *(short *)(ppvVar4 + 2) = s;
  *(undefined *)(ppvVar4 + 3) = 0;
  Text_SetFontIChar(f,0);
  Text_SetFontILine(f,1);
  iVar5 = 1;
  iVar1 = (int)ppvVar4 + 1;
  do {
    *(undefined *)(iVar1 + 0xc) = 0;
    iVar5 = iVar5 + 1;
    iVar1 = (int)ppvVar4 + iVar5;
  } while (iVar5 < 0xff);
  if (type == 1) {
    iVar1 = 0;
    ppvVar2 = ppvVar4;
    do {
      *(undefined *)((int)ppvVar2 + 0x2d) = (char)iVar1;
      iVar1 = iVar1 + 1;
      ppvVar2 = (void **)(iVar1 + (int)ppvVar4);
    } while (iVar1 < 0x76);
  }
  else {
    if ((type < 2) && (type == 0)) {
      iVar1 = 0;
      ppvVar2 = ppvVar4;
      do {
        *(undefined *)((int)ppvVar2 + 0x2d) = (char)iVar1;
        iVar1 = iVar1 + 1;
        ppvVar2 = (void **)(iVar1 + (int)ppvVar4);
      } while (iVar1 < 0x3a);
      iVar1 = 0;
      ppvVar2 = ppvVar4;
      do {
        *(char *)((int)ppvVar2 + 0x6d) = (char)iVar1 + ' ';
        iVar1 = iVar1 + 1;
        ppvVar2 = (void **)(iVar1 + (int)ppvVar4);
      } while (iVar1 < 0x1a);
      iVar1 = 0;
      iVar5 = 1;
      puVar6 = &Text_Accents;
      *(undefined *)(ppvVar4 + 0x12) = 0x48;
      *(undefined *)((int)ppvVar4 + 0x4a) = 0x49;
      do {
        puVar3 = &Text_Accents + iVar5;
        iVar5 = iVar5 + 2;
        iVar1 = iVar1 + 1;
        *(uchar *)((int)ppvVar4 + (uint)*puVar6 + 0xc) = *puVar3;
        puVar6 = puVar6 + 2;
      } while (iVar1 < 0x1d);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Text_InitContext(struct TEXT_102fake *t /*$a0*/)
 // line 138, offset 0x800a3194
	/* begin block 1 */
		// Start line: 297
	/* end block 1 */
	// End Line: 298

void Text_InitContext(TEXT_102fake *t)

{
  *(undefined4 *)&(t->Font).interchar = 0x808080;
  *(undefined2 *)((t->Font).ascii_tab + 4) = 1;
  *(undefined2 *)((t->Font).ascii_tab + 6) = 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Text_SetFontIChar(struct TEXT_101fake *f /*$s0*/, short ic /*$s1*/)
 // line 147, offset 0x800a31b0
	/* begin block 1 */
		// Start line: 148
		// Start offset: 0x800A31B0
		// Variables:
	// 		struct TEXT_68fake s; // stack offset -40
	// 		short w; // stack offset -24
	// 		short h; // stack offset -22
	/* end block 1 */
	// End offset: 0x800A31B0
	// End Line: 148

	/* begin block 2 */
		// Start line: 314
	/* end block 2 */
	// End Line: 315

void Text_SetFontIChar(undefined f,short ic)

{
  undefined3 in_register_00000011;
  void **ppvVar1;
  SHAPE_68fake local_28;
  char local_18 [2];
  short asStack22 [3];
  
  ppvVar1 = (void **)CONCAT31(in_register_00000011,f);
  local_28.file = *ppvVar1;
  *(char *)(ppvVar1 + 1) = (char)ic;
  local_28.shape = (ushort)*(byte *)(ppvVar1 + 3) + *(short *)(ppvVar1 + 2);
  Shp_GetWH(&local_28,(short *)local_18,asStack22);
  *(char *)((int)ppvVar1 + 6) = (char)ic + local_18[0];
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Text_SetFontILine(struct TEXT_101fake *f /*$s1*/, short il /*$s0*/)
 // line 166, offset 0x800a3218
	/* begin block 1 */
		// Start line: 167
		// Start offset: 0x800A3218
		// Variables:
	// 		struct TEXT_68fake s; // stack offset -40
	// 		short w; // stack offset -24
	// 		short h; // stack offset -22
	/* end block 1 */
	// End offset: 0x800A3218
	// End Line: 167

	/* begin block 2 */
		// Start line: 373
	/* end block 2 */
	// End Line: 374

void Text_SetFontILine(undefined f,short il)

{
  undefined3 in_register_00000011;
  void **ppvVar1;
  SHAPE_68fake local_28;
  short sStack24;
  char local_16 [6];
  
  ppvVar1 = (void **)CONCAT31(in_register_00000011,f);
  local_28.file = *ppvVar1;
  local_28.shape = (ushort)*(byte *)(ppvVar1 + 3) + *(short *)(ppvVar1 + 2);
  Shp_GetWH(&local_28,&sStack24,(short *)local_16);
  *(char *)((int)ppvVar1 + 5) = (char)il + local_16[0];
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Text_SetText(char *text /*$s5*/, short x /*$s6*/, short y /*$s0*/)
 // line 185, offset 0x800a327c
	/* begin block 1 */
		// Start line: 186
		// Start offset: 0x800A327C
		// Variables:
	// 		long curx; // $s2
	// 		long cury; // $s5
	// 		short shpW; // stack offset -48
	// 		short shpH; // stack offset -46
	// 		char *pc; // $s4
	// 		struct TEXT_102fake *t; // $s1
	// 		struct TEXT_101fake *f; // $s7
	// 		struct TEXT_31fake *pPrim; // $s3
	// 		struct TEXT_68fake shp; // stack offset -64
	// 		struct TEXT_8fake *color; // stack offset -44
	/* end block 1 */
	// End offset: 0x800A36A8
	// End Line: 276

	/* begin block 2 */
		// Start line: 427
	/* end block 2 */
	// End Line: 428

void Text_SetText(char *text,short x,short y)

{
  byte bVar1;
  char cVar2;
  ushort uVar3;
  _SCREEN *p_Var4;
  long lVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  TEXT_102fake *t;
  short sVar9;
  int iVar10;
  SHAPE_31fake *prim;
  short sVar11;
  int iVar12;
  int iVar13;
  void **ppvVar14;
  SHAPE_68fake local_40;
  ushort local_30;
  ushort local_2e;
  char *local_2c;
  
  prim = (SHAPE_31fake *)pChar;
  t = (TEXT_102fake *)TaskCurrent->text_context;
  ppvVar14 = (void **)(t->Font).pcl;
  local_40.file = *ppvVar14;
  local_2c = &(t->Font).interchar;
  if (x == -0x7fff) {
    lVar5 = Text_LenX(text,t);
    iVar10 = ((int)*(short *)((t->Font).ascii_tab + 8) + (int)*(short *)((t->Font).ascii_tab + 0xc))
             - lVar5;
  }
  else {
    if (x < -0x7fff) {
      iVar10 = (int)*(short *)((t->Font).ascii_tab + 8);
    }
    else {
      if (x == -0x7ffe) {
        uVar7 = Text_LenX(text,t);
        uVar6 = (uint)*(ushort *)((t->Font).ascii_tab + 0xc) << 0x10;
        iVar10 = ((int)*(short *)((t->Font).ascii_tab + 8) +
                 ((int)(((int)uVar6 >> 0x10) + (uVar6 >> 0x1f)) >> 1)) -
                 ((int)((uVar7 >> 0x1f) + uVar7) >> 1);
      }
      else {
        if (x == -0x7ffc) {
          iVar10 = (int)(t->Font).off_shape;
        }
        else {
          iVar10 = (int)*(short *)((t->Font).ascii_tab + 8) + (int)x;
        }
      }
    }
  }
  sVar9 = (short)iVar10;
  if (y == -0x7ffd) {
    uVar7 = Text_LenY(text,t);
    uVar6 = (uint)*(ushort *)((t->Font).ascii_tab + 0xe) << 0x10;
    iVar12 = ((int)*(short *)((t->Font).ascii_tab + 10) +
             ((int)(((int)uVar6 >> 0x10) + (uVar6 >> 0x1f)) >> 1)) -
             ((int)((uVar7 >> 0x1f) + uVar7) >> 1);
  }
  else {
    if (y == -0x7ffc) {
      iVar12 = (int)(t->Font).pad2;
    }
    else {
      iVar12 = (int)*(short *)((t->Font).ascii_tab + 10) + (int)y;
    }
  }
  sVar11 = (short)iVar12;
  if (*text != '\0') {
    iVar13 = (int)x;
    pcVar8 = (char *)prim + 0x25;
    do {
      bVar1 = *text;
      if (bVar1 == 10) {
        if (iVar13 == -0x7fff) {
          lVar5 = Text_LenX((char *)((byte *)text + 1),t);
          iVar10 = ((int)*(short *)((t->Font).ascii_tab + 8) +
                   (int)*(short *)((t->Font).ascii_tab + 0xc)) - lVar5;
        }
        else {
          if (iVar13 < -0x7fff) {
            iVar10 = (int)*(short *)((t->Font).ascii_tab + 8);
          }
          else {
            if (iVar13 == -0x7ffe) {
              uVar7 = Text_LenX((char *)((byte *)text + 1),t);
              uVar6 = (uint)*(ushort *)((t->Font).ascii_tab + 0xc) << 0x10;
              iVar10 = ((int)*(short *)((t->Font).ascii_tab + 8) +
                       ((int)(((int)uVar6 >> 0x10) + (uVar6 >> 0x1f)) >> 1)) -
                       ((int)((uVar7 >> 0x1f) + uVar7) >> 1);
            }
            else {
              iVar10 = (int)*(short *)((t->Font).ascii_tab + 8) + iVar13;
            }
          }
        }
        iVar12 = iVar12 + (int)*(char *)((int)ppvVar14 + 5);
      }
      else {
        if (bVar1 < 0xb) {
          if (bVar1 == 9) {
            iVar10 = iVar10 + (int)*(char *)((int)ppvVar14 + 6) * 8;
          }
          else {
LAB_800a353c:
            local_40.x = (short)iVar10;
            local_40.y = (short)iVar12;
            local_40.shape =
                 (ushort)*(byte *)((int)ppvVar14 + (uint)(byte)*text + 0xc) +
                 *(short *)(ppvVar14 + 2);
            Shp_GetWH(&local_40,(short *)&local_30,(short *)&local_2e);
            iVar10 = iVar10 + (int)(short)local_30 + (int)*(char *)(ppvVar14 + 1);
            Shp_SetPolyFT4(prim,&local_40,(short)(((uint)local_30 + 1) * 0x10000 >> 0x10),
                           (short)(((uint)local_2e + 1) * 0x10000 >> 0x10));
            SetShadeTex((int)prim,0);
            SetSemiTrans((int)prim,(uint)*(ushort *)((t->Font).ascii_tab + 2) & 4);
            uVar3 = *(ushort *)(pcVar8 + -0xf);
            *(ushort *)(pcVar8 + -0xf) = uVar3 & 0xff9f;
            *(ushort *)(pcVar8 + -0xf) =
                 uVar3 & 0xff9f | (ushort)(((uint)*(ushort *)((t->Font).ascii_tab + 2) & 3) << 5);
            pcVar8[-0x21] = *local_2c;
            pcVar8[-0x20] = local_2c[1];
            cVar2 = local_2c[2];
            pcVar8[-1] = pcVar8[-1] + '\x01';
            pcVar8[-0x11] = pcVar8[-0x11] + '\x01';
            *pcVar8 = *pcVar8 + '\x01';
            pcVar8[-0x1f] = cVar2;
            pcVar8[-8] = pcVar8[-8] + '\x01';
            p_Var4 = Scr;
            pcVar8 = pcVar8 + 0x28;
            prim->tag = prim->tag & 0xff000000 |
                        Scr->ot[(int)*(short *)(t->Font).ascii_tab] & 0xffffff;
            uVar7 = (uint)prim & 0xffffff;
            prim = prim + 1;
            p_Var4->ot[(int)*(short *)(t->Font).ascii_tab] =
                 p_Var4->ot[(int)*(short *)(t->Font).ascii_tab] & 0xff000000 | uVar7;
          }
        }
        else {
          if (bVar1 != 0xd) {
            if (bVar1 != 0x20) goto LAB_800a353c;
            iVar10 = iVar10 + (int)*(char *)((int)ppvVar14 + 6);
          }
        }
      }
      sVar11 = (short)iVar12;
      sVar9 = (short)iVar10;
      text = (char *)((byte *)text + 1);
    } while (*text != 0);
  }
  (t->Font).off_shape = sVar9;
  (t->Font).pad2 = sVar11;
  pChar = (char *)prim;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Text_SetText3D(char *text /*$a0*/, struct TEXT_7fake *pos /*$a1*/)
 // line 281, offset 0x800a36e4
	/* begin block 1 */
		// Start line: 282
		// Start offset: 0x800A36E4
		// Variables:
	// 		struct TEXT_9fake pos2D; // stack offset -24
	// 		long z; // stack offset -16
	/* end block 1 */
	// End offset: 0x800A36E4
	// End Line: 282

	/* begin block 2 */
		// Start line: 685
	/* end block 2 */
	// End Line: 686

void Text_SetText3D(char *text,undefined pos)

{
  undefined4 uVar1;
  undefined4 in_zero;
  undefined4 in_at;
  undefined3 in_register_00000015;
  short local_18;
  short sStack22;
  
  setCopReg(2,in_zero,*(undefined4 *)CONCAT31(in_register_00000015,pos));
  setCopReg(2,in_at,((undefined4 *)CONCAT31(in_register_00000015,pos))[1]);
  copFunction(2,0x180001);
  uVar1 = getCopReg(2,0xe);
  getCopReg(2,0x9800);
  local_18 = (short)uVar1;
  sStack22 = (short)((uint)uVar1 >> 0x10);
  Text_SetText(text,local_18,sStack22);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Text_LenX(char *text /*$s1*/, struct TEXT_102fake *t /*$a1*/)
 // line 292, offset 0x800a373c
	/* begin block 1 */
		// Start line: 293
		// Start offset: 0x800A373C
		// Variables:
	// 		struct TEXT_101fake *f; // $s2
	// 		struct TEXT_68fake shp; // stack offset -40
	// 		short len; // $s0
	// 		short w; // stack offset -24
	// 		short h; // stack offset -22
	// 		short flag; // $a0
	/* end block 1 */
	// End offset: 0x800A383C
	// End Line: 320

	/* begin block 2 */
		// Start line: 707
	/* end block 2 */
	// End Line: 708

long Text_LenX(char *text,TEXT_102fake *t)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  void **ppvVar4;
  SHAPE_68fake local_28;
  ushort local_18;
  short asStack22 [3];
  
  ppvVar4 = (void **)(t->Font).pcl;
  local_28.file = *ppvVar4;
  iVar2 = 0;
  bVar1 = *text;
  iVar3 = 0;
  do {
    if ((bVar1 == 0) || (bVar1 == 10)) {
      return (iVar3 - iVar2) * 0x10000 >> 0x10;
    }
    bVar1 = *text;
    if (bVar1 != 0xd) {
      if (bVar1 < 0xe) {
        if (bVar1 == 9) {
          iVar3 = iVar3 + ((int)((uint)*(byte *)((int)ppvVar4 + 6) << 0x18) >> 0x15);
        }
        else {
LAB_800a37e8:
          local_28.shape =
               (ushort)*(byte *)((int)ppvVar4 + (uint)(byte)*text + 0xc) + *(short *)(ppvVar4 + 2);
          Shp_GetWH(&local_28,(short *)&local_18,asStack22);
          iVar2 = (int)*(char *)(ppvVar4 + 1);
          iVar3 = iVar3 + (uint)local_18 + iVar2;
        }
      }
      else {
        if (bVar1 != 0x20) goto LAB_800a37e8;
        iVar3 = iVar3 + (int)*(char *)((int)ppvVar4 + 6);
      }
    }
    text = (char *)((byte *)text + 1);
    bVar1 = *text;
  } while( true );
}



// decompiled code
// original method signature: 
// long /*$ra*/ Text_LenY(char *text /*$a0*/, struct TEXT_102fake *t /*$a1*/)
 // line 326, offset 0x800a3860
	/* begin block 1 */
		// Start line: 328
		// Start offset: 0x800A3860
		// Variables:
	// 		long l; // $a2
	/* end block 1 */
	// End offset: 0x800A3894
	// End Line: 342

	/* begin block 2 */
		// Start line: 794
	/* end block 2 */
	// End Line: 795

long Text_LenY(char *text,TEXT_102fake *t)

{
  char cVar1;
  int iVar2;
  
  cVar1 = *text;
  iVar2 = 1;
  while (cVar1 != '\0') {
    if (cVar1 == '\n') {
      iVar2 = iVar2 + 1;
    }
    text = text + 1;
    cVar1 = *text;
  }
  return iVar2 * (int)*(char *)((int)(t->Font).pcl + 5);
}



// decompiled code
// original method signature: 
// void /*$ra*/ Text_SetContext(struct TEXT_102fake *t /*$a0*/)
 // line 346, offset 0x800a38b4
	/* begin block 1 */
		// Start line: 828
	/* end block 1 */
	// End Line: 829

void Text_SetContext(TEXT_102fake *t)

{
  if ((t != (TEXT_102fake *)0x0) && (TaskCurrent != (TASK *)0x0)) {
    *(TEXT_102fake **)&TaskCurrent->text_context = t;
  }
  *(undefined4 *)&(t->Font).interchar = 0x808080;
  *(undefined2 *)((t->Font).ascii_tab + 4) = 1;
  *(undefined2 *)((t->Font).ascii_tab + 6) = 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Text_SetContextFont(struct TEXT_101fake *f /*$a0*/)
 // line 357, offset 0x800a38f0
	/* begin block 1 */
		// Start line: 850
	/* end block 1 */
	// End Line: 851

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Text_SetContextFont(undefined f)

{
  undefined3 in_register_00000011;
  
  if (((void *)CONCAT31(in_register_00000011,f) != (void *)0x0) && (TaskCurrent != (TASK *)0x0)) {
    (TaskCurrent->text_context->Font).pcl = (void *)CONCAT31(in_register_00000011,f);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Text_SetContextXY(short a /*$a0*/, short b /*$a1*/)
 // line 363, offset 0x800a3920
	/* begin block 1 */
		// Start line: 862
	/* end block 1 */
	// End Line: 863

void Text_SetContextXY(short a,short b)

{
  TASK *pTVar1;
  
  pTVar1 = TaskCurrent;
  if (TaskCurrent != (TASK *)0x0) {
    *(short *)((TaskCurrent->text_context->Font).ascii_tab + 8) = a;
    *(short *)((pTVar1->text_context->Font).ascii_tab + 10) = b;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Text_SetContextWH(short a /*$a0*/, short b /*$a1*/)
 // line 372, offset 0x800a3954
	/* begin block 1 */
		// Start line: 880
	/* end block 1 */
	// End Line: 881

void Text_SetContextWH(short a,short b)

{
  TASK *pTVar1;
  
  pTVar1 = TaskCurrent;
  if (TaskCurrent != (TASK *)0x0) {
    *(short *)((TaskCurrent->text_context->Font).ascii_tab + 0xc) = a;
    *(short *)((pTVar1->text_context->Font).ascii_tab + 0xe) = b;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Text_SetContextRange(short r /*$a0*/)
 // line 381, offset 0x800a3988
	/* begin block 1 */
		// Start line: 898
	/* end block 1 */
	// End Line: 899

void Text_SetContextRange(short r)

{
  if (TaskCurrent != (TASK *)0x0) {
    *(short *)(TaskCurrent->text_context->Font).ascii_tab = r;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Text_SetContextMode(short a /*$a0*/)
 // line 387, offset 0x800a39b0
	/* begin block 1 */
		// Start line: 910
	/* end block 1 */
	// End Line: 911

void Text_SetContextMode(short a)

{
  if (TaskCurrent != (TASK *)0x0) {
    *(short *)((TaskCurrent->text_context->Font).ascii_tab + 2) = a;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Text_SetContextColor(long a /*$a0*/)
 // line 395, offset 0x800a39d8
	/* begin block 1 */
		// Start line: 926
	/* end block 1 */
	// End Line: 927

void Text_SetContextColor(long a)

{
  if (TaskCurrent != (TASK *)0x0) {
    *(long *)&(TaskCurrent->text_context->Font).interchar = a;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Text_SetContextScale(short scalex /*$a0*/, short scaley /*$a1*/)
 // line 403, offset 0x800a3a00
	/* begin block 1 */
		// Start line: 942
	/* end block 1 */
	// End Line: 943

void Text_SetContextScale(short scalex,short scaley)

{
  TASK *pTVar1;
  
  pTVar1 = TaskCurrent;
  if (TaskCurrent != (TASK *)0x0) {
    *(short *)((TaskCurrent->text_context->Font).ascii_tab + 4) = scalex;
    *(short *)((pTVar1->text_context->Font).ascii_tab + 6) = scaley;
  }
  return;
}



// decompiled code
// original method signature: 
// char * /*$ra*/ Text_GetIndexPointers(char *input /*$a0*/, char *crc /*$a3*/, long **array /*$s7*/)
 // line 440, offset 0x800a3a34
	/* begin block 1 */
		// Start line: 441
		// Start offset: 0x800A3A34
		// Variables:
	// 		long *pointer; // $s6
	// 		short i; // $s2
	// 		char *tmp; // $s1
	// 		char *endline; // $s0
	/* end block 1 */
	// End offset: 0x800A3C4C
	// End Line: 511

	/* begin block 2 */
		// Start line: 1015
	/* end block 2 */
	// End Line: 1016

char * Text_GetIndexPointers(char *input,char *crc,long **array)

{
  char *__s;
  char *pcVar1;
  short sVar2;
  int iVar3;
  long *plVar4;
  
  plVar4 = (long *)0x0;
  if (*input != '[') {
    __s = input + 1;
    do {
      input = __s;
      __s = input + 1;
    } while (*input != '[');
  }
  input = input + 1;
  iVar3 = 0;
  if (*input == '%') {
    __s = (char *)0x0;
  }
  else {
    do {
      sVar2 = (short)iVar3;
      iVar3 = iVar3 + 1;
      crc[(int)sVar2] = input[(int)sVar2];
    } while (iVar3 * 0x10000 >> 0x10 < 4);
    crc[4] = '\0';
    __s = strchr(input,10);
    __s = __s + 2;
    pcVar1 = strchr(__s,0x5d);
    *pcVar1 = '\0';
    iVar3 = atoi(__s);
    *pcVar1 = ']';
    __s = strchr(__s,10);
    __s = strchr(__s + 1,10);
    __s = strchr(__s,0x5b);
    if (0 < (int)(short)iVar3) {
      plVar4 = (long *)Heap_AllocMem((int)(short)iVar3 << 2);
    }
    iVar3 = 0;
    while( true ) {
      while (__s[1] != ']') {
        __s = __s + 1;
      }
      if ((__s[2] == '[') && (__s[3] == ']')) break;
      pcVar1 = __s + 3;
      if (*pcVar1 != ']') {
        __s = __s + 4;
        do {
          pcVar1 = __s;
          __s = pcVar1 + 1;
        } while (*pcVar1 != ']');
      }
      __s = strchr(pcVar1 + 1,0x5b);
      __s[-1] = '\0';
      if ((__s[-2] == '\n') || (__s[-2] == '\r')) {
        __s[-2] = '\0';
      }
      if ((__s[-3] == '\n') || (__s[-3] == '\r')) {
        __s[-3] = '\0';
      }
      *(char **)(((iVar3 << 0x10) >> 0xe) + (int)plVar4) = pcVar1 + 1;
      iVar3 = iVar3 + 1;
    }
    __s = __s + 4;
    *array = plVar4;
  }
  return __s;
}



// decompiled code
// original method signature: 
// short /*$ra*/ Text_AmountOfTexts(char *src /*$a0*/)
 // line 516, offset 0x800a3c78
	/* begin block 1 */
		// Start line: 517
		// Start offset: 0x800A3C78
		// Variables:
	// 		char *next; // $v0
	// 		short i; // $s0

		/* begin block 1.1 */
			// Start line: 524
			// Start offset: 0x800A3C90
		/* end block 1.1 */
		// End offset: 0x800A3CA4
		// End Line: 525
	/* end block 1 */
	// End offset: 0x800A3CAC
	// End Line: 527

	/* begin block 2 */
		// Start line: 1202
	/* end block 2 */
	// End Line: 1203

short Text_AmountOfTexts(char *src)

{
  int iVar1;
  
  iVar1 = 0;
  src = src + -1;
  if (src != (char *)0x0) {
    while (src = strchr(src + 1,0xd), src != (char *)0x0) {
      iVar1 = iVar1 + 1;
    }
  }
  return (short)((uint)((iVar1 + 1) * 0x10000) >> 0x10);
}



// decompiled code
// original method signature: 
// void /*$ra*/ Text_DisplayLine(char *src /*$a0*/, long index /*$a1*/, long time /*$s5*/, long *info /*$s4*/)
 // line 531, offset 0x800a3cc8
	/* begin block 1 */
		// Start line: 532
		// Start offset: 0x800A3CC8
		// Variables:
	// 		char *text; // $s3
	// 		char *next; // $s1
	// 		long i; // $s0

		/* begin block 1.1 */
			// Start line: 539
			// Start offset: 0x800A3D04
		/* end block 1.1 */
		// End offset: 0x800A3D24
		// End Line: 544
	/* end block 1 */
	// End offset: 0x800A3DA0
	// End Line: 553

	/* begin block 2 */
		// Start line: 1233
	/* end block 2 */
	// End Line: 1234

void Text_DisplayLine(char *src,long index,long time,long *info)

{
  int iVar1;
  char *pcVar2;
  char *__s;
  
  pcVar2 = src + -2;
  iVar1 = 0;
  if (0 < index + 1) {
    do {
      __s = src;
      pcVar2 = strchr(__s,0xd);
      iVar1 = iVar1 + 1;
      if (pcVar2 == (char *)0x0) goto LAB_800a3d40;
      src = pcVar2 + 2;
    } while (iVar1 < index + 1);
  }
  if (pcVar2 != (char *)0x0) {
    *pcVar2 = '\0';
  }
LAB_800a3d40:
  iVar1 = 0;
  if (0 < time) {
    do {
      if ((info != (long *)0x0) && (*info == 0)) break;
      iVar1 = iVar1 + 1;
      Text_SetText(__s,-0x7ffe,(short)(((uint)(ushort)Scr_H - 0x46) * 0x10000 >> 0x10));
      Task_Next();
    } while (iVar1 < time);
  }
  if (pcVar2 != (char *)0x0) {
    *pcVar2 = '\r';
  }
  return;
}



// decompiled code
// original method signature: 
// void strchr() /* strchr method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 745, offset 0x800a3dc4
char * strchr(char *__s,int __c)

{
  char *pcVar1;
  
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)0xa0)();
  return pcVar1;
}





