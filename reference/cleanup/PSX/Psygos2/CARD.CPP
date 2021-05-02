#include "THISDUST.H"
#include "CARD.H"


// decompiled code
// original method signature: 
// void /*$ra*/ Card_Init()
 // line 18, offset 0x800a3e04
	/* begin block 1 */
		// Start line: 37
	/* end block 1 */
	// End Line: 38

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Card_Init(void)

{
  Card_Used = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Card_Start()
 // line 24, offset 0x800a3e10
	/* begin block 1 */
		// Start line: 49
	/* end block 1 */
	// End Line: 50

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Card_Start(void)

{
  if (Card_Used == 0) {
    MemCardStart();
  }
  Card_Used = Card_Used + 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Card_Stop()
 // line 33, offset 0x800a3e40
	/* begin block 1 */
		// Start line: 68
	/* end block 1 */
	// End Line: 69

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Card_Stop(void)

{
  bool bVar1;
  short sVar2;
  
  sVar2 = Card_Used + -1;
  bVar1 = Card_Used == 1;
  Card_Used = sVar2;
  if (bVar1) {
    Card_Used = sVar2;
    MemCardStop();
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Card_Test(long channel /*$s0*/)
 // line 40, offset 0x800a3e78
	/* begin block 1 */
		// Start line: 41
		// Start offset: 0x800A3E78
		// Variables:
	// 		long dummy; // stack offset -24
	// 		long result; // stack offset -20

		/* begin block 1.1 */
			// Start line: 47
			// Start offset: 0x800A3E90
		/* end block 1.1 */
		// End offset: 0x800A3EBC
		// End Line: 52
	/* end block 1 */
	// End offset: 0x800A3ECC
	// End Line: 56

	/* begin block 2 */
		// Start line: 82
	/* end block 2 */
	// End Line: 83

long Card_Test(long channel)

{
  uint uVar1;
  int iVar2;
  int iStack24;
  int local_14;
  
  do {
    do {
      uVar1 = MemCardAccept(channel);
    } while (uVar1 == 0);
    iVar2 = MemCardSync(0,&iStack24,&local_14);
    if (iVar2 == 0) {
      ErrorMaster();
    }
  } while (local_14 == 3);
  return local_14;
}



// decompiled code
// original method signature: 
// char * /*$ra*/ Card_GetName(char *file /*$s1*/)
 // line 61, offset 0x800a3ee0
	/* begin block 1 */
		// Start line: 62
		// Start offset: 0x800A3EE0
	/* end block 1 */
	// End offset: 0x800A3EE0
	// End Line: 62

	/* begin block 2 */
		// Start line: 127
	/* end block 2 */
	// End Line: 128

char * Card_GetName(char *file)

{
  Card_Name = DAT_800adb7c;
  s_______800b42b1[0] = DAT_800adb7d;
  strcat(&Card_Name,&DAT_800adb80);
  strcat(&Card_Name,s_SLES_01409_800adb84);
  strcat(&Card_Name,file);
  return &Card_Name;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Card_SetName(struct _CARD_HEADER *h /*$s0*/, char *name /*$a1*/)
 // line 91, offset 0x800a3f58
	/* begin block 1 */
		// Start line: 92
		// Start offset: 0x800A3F58
		// Variables:
	// 		long i; // $v0
	/* end block 1 */
	// End offset: 0x800A3F88
	// End Line: 104

	/* begin block 2 */
		// Start line: 199
	/* end block 2 */
	// End Line: 200

void Card_SetName(_CARD_HEADER *h,char *name)

{
  int iVar1;
  char *pcVar2;
  
  Asc2Sjis_String((ushort *)h->name,(uchar *)name);
  iVar1 = 0x1b;
  pcVar2 = h->name + 0x17;
  do {
    pcVar2[0x44] = '\0';
    iVar1 = iVar1 + -1;
    pcVar2 = pcVar2 + -1;
  } while (-1 < iVar1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Card_SetIcons(struct _CARD_HEADER *h /*$s3*/, long ni /*$s4*/, struct CARD_68fake *shp /*$s2*/)
 // line 107, offset 0x800a3f98
	/* begin block 1 */
		// Start line: 108
		// Start offset: 0x800A3F98
		// Variables:
	// 		struct CARD_21fake rc; // stack offset -40
	// 		short i; // $s1
	// 		short u; // stack offset -32
	// 		short v; // stack offset -30
	/* end block 1 */
	// End offset: 0x800A40C4
	// End Line: 136

	/* begin block 2 */
		// Start line: 232
	/* end block 2 */
	// End Line: 233

void Card_SetIcons(_CARD_HEADER *h,long ni,CARD_68fake *shp)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  short local_28;
  short local_26;
  undefined2 local_24;
  undefined2 local_22;
  short local_20;
  short local_1e [3];
  
  h->type = (char)ni + '\x10';
  uVar1 = Shp_GetPal((SHAPE_68fake *)shp);
  iVar3 = (int)((uint)uVar1 << 0x10) >> 0xd;
  iVar4 = 0;
  local_28 = *(short *)((int)&Pals[0].x + iVar3);
  local_26 = *(short *)((int)&Pals[0].y + iVar3);
  local_24 = 0x10;
  local_22 = 1;
  StoreImage(&local_28,h->clut);
  local_24 = 4;
  local_22 = 0x10;
  if (0 < ni) {
    do {
      Shp_GetUV((SHAPE_68fake *)shp,&local_20,local_1e);
      sVar2 = Shp_GetMode((SHAPE_68fake *)shp);
      iVar3 = (int)local_20;
      if (iVar3 < 0) {
        iVar3 = iVar3 + 3;
      }
      local_28 = (&TPages)[(int)sVar2].x + (short)(iVar3 >> 2);
      local_26 = (&TPages)[(int)sVar2].y + local_1e[0];
      StoreImage(&local_28,h->icons + ((iVar4 << 0x10) >> 9));
      iVar4 = iVar4 + 1;
      shp->shape = shp->shape + 1;
    } while (iVar4 * 0x10000 >> 0x10 < ni);
  }
  DrawSync();
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Card_Exist(long channel /*$s0*/)
 // line 140, offset 0x800a40ec
	/* begin block 1 */
		// Start line: 141
		// Start offset: 0x800A40EC
		// Variables:
	// 		long exist; // $s0
	/* end block 1 */
	// End offset: 0x800A4128
	// End Line: 159

	/* begin block 2 */
		// Start line: 355
	/* end block 2 */
	// End Line: 356

long Card_Exist(long channel)

{
  long lVar1;
  
  Card_Start();
  lVar1 = Card_Test(channel);
  Card_Stop();
  if (lVar1 == 0) {
    lVar1 = 1;
  }
  else {
    lVar1 = (uint)(lVar1 == 4) << 1;
  }
  return lVar1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Card_ReadDirectory(long channel /*$s1*/, struct DIRENTRY *directory /*$s2*/, long *files /*$s3*/)
 // line 162, offset 0x800a4138
	/* begin block 1 */
		// Start line: 163
		// Start offset: 0x800A4138
		// Variables:
	// 		long result; // $s0
	/* end block 1 */
	// End offset: 0x800A41A4
	// End Line: 184

	/* begin block 2 */
		// Start line: 403
	/* end block 2 */
	// End Line: 404

long Card_ReadDirectory(long channel,DIRENTRY *directory,long *files)

{
  uint uVar1;
  
  Card_Start();
  uVar1 = Card_Test(channel);
  if (uVar1 == 0) {
    uVar1 = MemCardGetDirentry(channel,&DAT_800adb90,(int)directory,files,0,0xf);
  }
  Card_Stop();
  return uVar1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Card_CreateFile(long channel /*$s1*/, char *name /*$s2*/, long nb /*$s3*/)
 // line 187, offset 0x800a41c0
	/* begin block 1 */
		// Start line: 188
		// Start offset: 0x800A41C0
		// Variables:
	// 		long result; // $s0
	/* end block 1 */
	// End offset: 0x800A4224
	// End Line: 209

	/* begin block 2 */
		// Start line: 458
	/* end block 2 */
	// End Line: 459

long Card_CreateFile(long channel,char *name,long nb)

{
  long lVar1;
  char *pcVar2;
  
  Card_Start();
  lVar1 = Card_Test(channel);
  if (lVar1 == 0) {
    pcVar2 = Card_GetName(name);
    lVar1 = MemCardCreateFile(channel,pcVar2,nb);
  }
  Card_Stop();
  return lVar1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Card_WriteFile(long channel /*$s2*/, char *name /*$s3*/, struct _CARD_HEADER *h /*$s0*/, long size /*$s1*/)
 // line 212, offset 0x800a4240
	/* begin block 1 */
		// Start line: 213
		// Start offset: 0x800A4240
		// Variables:
	// 		long dummy; // stack offset -32
	// 		long result; // stack offset -28
	/* end block 1 */
	// End offset: 0x800A432C
	// End Line: 252

	/* begin block 2 */
		// Start line: 513
	/* end block 2 */
	// End Line: 514

long Card_WriteFile(long channel,char *name,_CARD_HEADER *h,long size)

{
  char *pcVar1;
  int iVar2;
  int iStack32;
  long local_1c;
  
  iVar2 = size + 0x1fff;
  if (iVar2 < 0) {
    iVar2 = size + 0x3ffe;
  }
  h->magic[0] = 'S';
  h->magic[1] = 'C';
  h->n_blocks = (char)(iVar2 >> 0xd);
  local_1c = Card_CreateFile(channel,name,(int)(short)(iVar2 >> 0xd));
  if ((local_1c == 0) || (local_1c == 6)) {
    Card_Start();
    local_1c = Card_Test(channel);
    if (local_1c == 0) {
      pcVar1 = Card_GetName(name);
      iVar2 = MemCardWriteFile(channel,pcVar1,h,0,size);
      if (iVar2 == 0) {
        ErrorMaster();
      }
      iVar2 = MemCardSync(0,&iStack32,&local_1c);
      if (iVar2 == 0) {
        ErrorMaster();
      }
    }
    Card_Stop();
  }
  return local_1c;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Card_ReadFile(long channel /*$s0*/, char *name /*$s2*/, struct _CARD_HEADER *h /*$s3*/, long size /*$s1*/)
 // line 255, offset 0x800a4348
	/* begin block 1 */
		// Start line: 256
		// Start offset: 0x800A4348
		// Variables:
	// 		long dummy; // stack offset -32
	// 		long result; // stack offset -28
	/* end block 1 */
	// End offset: 0x800A43D8
	// End Line: 283

	/* begin block 2 */
		// Start line: 609
	/* end block 2 */
	// End Line: 610

long Card_ReadFile(long channel,char *name,_CARD_HEADER *h,long size)

{
  int iVar1;
  int iStack32;
  long local_1c;
  
  Card_Start();
  local_1c = Card_Test(channel);
  if (local_1c == 0) {
    iVar1 = MemCardReadFile(channel,name,h,0,size);
    if (iVar1 == 0) {
      ErrorMaster();
    }
    iVar1 = MemCardSync(0,&iStack32,&local_1c);
    if (iVar1 == 0) {
      ErrorMaster();
    }
  }
  Card_Stop();
  return local_1c;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Card_DeleteFile(long channel /*$s1*/, char *name /*$s2*/)
 // line 286, offset 0x800a43f4
	/* begin block 1 */
		// Start line: 287
		// Start offset: 0x800A43F4
		// Variables:
	// 		long result; // $s0
	/* end block 1 */
	// End offset: 0x800A4440
	// End Line: 308

	/* begin block 2 */
		// Start line: 671
	/* end block 2 */
	// End Line: 672

long Card_DeleteFile(long channel,char *name)

{
  long lVar1;
  
  Card_Start();
  lVar1 = Card_Test(channel);
  if (lVar1 == 0) {
    lVar1 = MemCardDeleteFile(channel,name);
  }
  Card_Stop();
  return lVar1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Card_Format(long channel /*$s0*/)
 // line 311, offset 0x800a4458
	/* begin block 1 */
		// Start line: 312
		// Start offset: 0x800A4458
		// Variables:
	// 		long result; // $s0
	/* end block 1 */
	// End offset: 0x800A4458
	// End Line: 312

	/* begin block 2 */
		// Start line: 726
	/* end block 2 */
	// End Line: 727

long Card_Format(long channel)

{
  uint uVar1;
  
  Card_Start();
  uVar1 = MemCardFormat(channel);
  Card_Stop();
  return uVar1;
}





