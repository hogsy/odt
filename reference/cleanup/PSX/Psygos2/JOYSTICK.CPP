#include "THISDUST.H"
#include "JOYSTICK.H"


// decompiled code
// original method signature: 
// void /*$ra*/ Joy_Init()
 // line 59, offset 0x8009cea4
	/* begin block 1 */
		// Start line: 60
		// Start offset: 0x8009CEA4
		// Variables:
	// 		long i; // $v1
	/* end block 1 */
	// End offset: 0x8009CEF4
	// End Line: 80

	/* begin block 2 */
		// Start line: 118
	/* end block 2 */
	// End Line: 119

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Joy_Init(void)

{
  JOYSTICK_104fake *pJVar1;
  int iVar2;
  
  InitTAP(Joy_Data,0x22,&DAT_800b4082,0x22);
  StartTAP();
  VSync(0);
  iVar2 = 7;
  pJVar1 = &JOYSTICK_104fake_800b40f6;
  do {
    pJVar1->type = '\0';
    iVar2 = iVar2 + -1;
    pJVar1 = (JOYSTICK_104fake *)&pJVar1[-1].running;
  } while (-1 < iVar2);
  Joy_RefreshPhysLog();
  Joy_Read = 0;
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Joy_IsConnected(long i /*$a0*/)
 // line 91, offset 0x8009cf0c
	/* begin block 1 */
		// Start line: 190
	/* end block 1 */
	// End Line: 191

long Joy_IsConnected(long i)

{
  return (uint)Joys[i].type;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Joy_IsMultiTap(long side /*$a0*/)
 // line 100, offset 0x8009cf30
	/* begin block 1 */
		// Start line: 207
	/* end block 1 */
	// End Line: 208

long Joy_IsMultiTap(long side)

{
  return (uint)(Joys[side].type == '\b');
}



// decompiled code
// original method signature: 
// void /*$ra*/ Joy_RefreshPhysLog()
 // line 108, offset 0x8009cf5c
	/* begin block 1 */
		// Start line: 109
		// Start offset: 0x8009CF5C
		// Variables:
	// 		long i; // $s0
	/* end block 1 */
	// End offset: 0x8009CFB0
	// End Line: 118

	/* begin block 2 */
		// Start line: 222
	/* end block 2 */
	// End Line: 223

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Joy_RefreshPhysLog(void)

{
  JOYSTICK_104fake *pJVar1;
  int j;
  char data;
  
  j = 7;
  pJVar1 = &JOYSTICK_104fake_800b40f6;
  do {
    pJVar1->type = '\0';
    j = j + -1;
    pJVar1 = (JOYSTICK_104fake *)&pJVar1[-1].running;
  } while (-1 < j);
  j = 0;
  data = '`';
  do {
    Joy_ReadTap(data,j);
    j = j + 1;
    data = data + '\"';
  } while (j < 2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Joy_ReadTap(struct JOYSTICK_105fake *data /*$a3*/, long j /*$a1*/)
 // line 121, offset 0x8009cfc4
	/* begin block 1 */
		// Start line: 122
		// Start offset: 0x8009CFC4
		// Variables:
	// 		long type; // $a0
	/* end block 1 */
	// End offset: 0x8009D264
	// End Line: 190

	/* begin block 2 */
		// Start line: 253
	/* end block 2 */
	// End Line: 254

void Joy_ReadTap(undefined data,long j)

{
  char cVar1;
  int iVar2;
  ushort uVar3;
  byte bVar4;
  undefined3 in_register_00000011;
  JOYSTICK_106fake *data_00;
  
  data_00 = (JOYSTICK_106fake *)CONCAT31(in_register_00000011,data);
  if (data_00->status == '\0') {
    bVar4 = data_00->type >> 4;
  }
  else {
    bVar4 = 0;
    if ((Joys[j].type != -1) && (bVar4 = 0xff, Joys[j].type == '\0')) {
      bVar4 = 0;
    }
  }
  if (bVar4 == 8) {
    Joy_ReadMultiTap(data_00,j);
    return;
  }
  Joys[j].type = bVar4;
  Joys[j].current = *(ushort *)&data_00->pads << 8 | *(ushort *)&data_00->pads >> 8;
  if (bVar4 != 5) {
    if (bVar4 < 6) {
      if (bVar4 != 4) goto LAB_8009d250;
      uVar3 = Joys[j].current;
      Joys[j].ty = -0x80;
      Joys[j].tx = -0x80;
      if ((uVar3 & 0x8000) == 0) {
        cVar1 = '`';
      }
      else {
        if ((uVar3 & 0x2000) != 0) goto LAB_8009d0e0;
        cVar1 = -0x60;
      }
      Joys[j].tx = cVar1;
LAB_8009d0e0:
      if ((Joys[j].current & 0x1000) == 0) {
        Joys[j].ty = '`';
        return;
      }
      if ((Joys[j].current & 0x4000) != 0) {
        return;
      }
      Joys[j].ty = -0x60;
      return;
    }
    if (bVar4 != 7) {
      if (bVar4 == 0xff) {
        return;
      }
LAB_8009d250:
      Joys[j].type = '\0';
      return;
    }
  }
  if ((uint)(byte)(data_00->pads).t1 - 0x51 < 0x5f) {
    (data_00->pads).t1 = -0x80;
  }
  if ((uint)(byte)(data_00->pads).t2 - 0x51 < 0x5f) {
    (data_00->pads).t2 = -0x80;
  }
  if ((data_00->pads).t1 < '\0') {
    if (0x80 < (byte)(data_00->pads).t1) {
      uVar3 = Joys[j].current & 0xdfff;
      goto LAB_8009d1bc;
    }
  }
  else {
    uVar3 = Joys[j].current & 0x7fff;
LAB_8009d1bc:
    Joys[j].current = uVar3;
  }
  if ((data_00->pads).t2 < '\0') {
    iVar2 = j * 4;
    if ((byte)(data_00->pads).t2 < 0x81) goto LAB_8009d228;
    uVar3 = Joys[j].current & 0xbfff;
  }
  else {
    uVar3 = Joys[j].current & 0xefff;
  }
  Joys[j].current = uVar3;
  iVar2 = j << 2;
LAB_8009d228:
  iVar2 = (iVar2 + j) * 2;
  (&Joys[0].tx)[iVar2] = (data_00->pads).t1;
  (&Joys[0].ty)[iVar2] = (data_00->pads).t2;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Joy_ReadMultiTap(struct JOYSTICK_106fake *data /*$s4*/, long j /*$s0*/)
 // line 193, offset 0x8009d274
	/* begin block 1 */
		// Start line: 194
		// Start offset: 0x8009D274
		// Variables:
	// 		long i; // $s2
	/* end block 1 */
	// End offset: 0x8009D2DC
	// End Line: 208

	/* begin block 2 */
		// Start line: 399
	/* end block 2 */
	// End Line: 400

void Joy_ReadMultiTap(JOYSTICK_106fake *data,long j)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  
  iVar3 = 0;
  cVar2 = '\x02';
  do {
    Joy_ReadTap((char)data + cVar2,j);
    if (j == 0) {
      j = 1;
    }
    else {
      bVar1 = j == 1;
      j = j + 1;
      if (bVar1) {
        j = 4;
      }
    }
    iVar3 = iVar3 + 1;
    cVar2 = cVar2 + '\b';
  } while (iVar3 < 4);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Joy_ReadLog(long j /*$a0*/)
 // line 213, offset 0x8009d2fc
	/* begin block 1 */
		// Start line: 456
	/* end block 1 */
	// End Line: 457

long Joy_ReadLog(long j)

{
  Joy_Read = 1;
  return (uint)Joys[j].running;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Joy_ReadTrig(long j /*$a0*/)
 // line 220, offset 0x8009d328
	/* begin block 1 */
		// Start line: 470
	/* end block 1 */
	// End Line: 471

long Joy_ReadTrig(long j)

{
  Joy_Read = 1;
  return (uint)Joys[j].trigger;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Joy_ReadX(long j /*$a0*/)
 // line 227, offset 0x8009d354
	/* begin block 1 */
		// Start line: 484
	/* end block 1 */
	// End Line: 485

long Joy_ReadX(long j)

{
  Joy_Read = 1;
  return (uint)(byte)Joys[j].tx;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Joy_ReadY(long j /*$a0*/)
 // line 234, offset 0x8009d380
	/* begin block 1 */
		// Start line: 498
	/* end block 1 */
	// End Line: 499

long Joy_ReadY(long j)

{
  Joy_Read = 1;
  return (uint)(byte)Joys[j].ty;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Joy_ReadLogAll()
 // line 243, offset 0x8009d3ac
	/* begin block 1 */
		// Start line: 516
	/* end block 1 */
	// End Line: 517

/* WARNING: Unknown calling convention yet parameter storage is locked */

long Joy_ReadLogAll(void)

{
  Joy_Read = 1;
  return (uint)Joy_StateAll.running;
}



// decompiled code
// original method signature: 
// long /*$ra*/ Joy_ReadTrigAll()
 // line 250, offset 0x8009d3c0
	/* begin block 1 */
		// Start line: 530
	/* end block 1 */
	// End Line: 531

/* WARNING: Unknown calling convention yet parameter storage is locked */

long Joy_ReadTrigAll(void)

{
  Joy_Read = 1;
  return (uint)Joy_StateAll.trigger;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Joy_Driver()
 // line 259, offset 0x8009d3d4
	/* begin block 1 */
		// Start line: 260
		// Start offset: 0x8009D3D4
		// Variables:
	// 		long i; // $s1
	/* end block 1 */
	// End offset: 0x8009D4A0
	// End Line: 291

	/* begin block 2 */
		// Start line: 547
	/* end block 2 */
	// End Line: 548

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Joy_Driver(void)

{
  long lVar1;
  ushort uVar2;
  JOYSTICK_104fake *pJVar3;
  int i;
  
  Joy_RefreshPhysLog();
  Joy_StateAll.running = 0;
  i = 0;
  if (Joy_Read != 0) {
    Joy_StateAll.trigger = 0;
  }
  pJVar3 = Joys;
  do {
    lVar1 = Joy_IsConnected(i);
    if ((lVar1 == 0) || (lVar1 = Joy_IsConnected(i), lVar1 == 0xff)) {
      pJVar3->running = 0;
      pJVar3->trigger = 0;
    }
    else {
      if (Joy_Read != 0) {
        uVar2 = ~(pJVar3->current | pJVar3->running);
        pJVar3->trigger = uVar2;
        Joy_StateAll.trigger = Joy_StateAll.trigger | uVar2;
      }
      pJVar3->running = ~pJVar3->current;
      Joy_StateAll.running = Joy_StateAll.running | ~pJVar3->current;
    }
    pJVar3 = pJVar3 + 1;
    i = i + 1;
  } while (i < 8);
  Joy_Read = 0;
  return;
}





