#include "THISDUST.H"
#include "SKY.H"


// decompiled code
// original method signature: 
// void /*$ra*/ Sky_InitFile()
 // line 27, offset 0x800680b8
	/* begin block 1 */
		// Start line: 54
	/* end block 1 */
	// End Line: 55

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Sky_InitFile(void)

{
  short sVar1;
  
  sVar1 = Sky_TestPresence();
  if (sVar1 == 0) {
    Sky.handle = (TASK *)0x0;
  }
  else {
    Sky.volume = 2;
    Sky.handle = Task_Link(Sky_Task,0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Sky_DeleteFile()
 // line 40, offset 0x80068108
	/* begin block 1 */
		// Start line: 82
	/* end block 1 */
	// End Line: 83

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Sky_DeleteFile(void)

{
  if (Sky.handle != (TASK *)0x0) {
    Task_Kill(Sky.handle);
  }
  Sky.handle = (TASK *)0x0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Sky_Task()
 // line 49, offset 0x80068130
	/* begin block 1 */
		// Start line: 50
		// Start offset: 0x80068130
		// Variables:
	// 		long cpt; // $s0
	// 		struct SKY_7fake pos; // stack offset -24

		/* begin block 1.1 */
			// Start line: 72
			// Start offset: 0x800681E8
			// Variables:
		// 		long i; // $s1
		/* end block 1.1 */
		// End offset: 0x8006839C
		// End Line: 100
	/* end block 1 */
	// End offset: 0x800683B0
	// End Line: 107

	/* begin block 2 */
		// Start line: 100
	/* end block 2 */
	// End Line: 101

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void Sky_Task(void)

{
  long lVar1;
  _ZONE *p_Var2;
  int iVar3;
  int iVar4;
  
  TaskCurrent->destructor = Sky_Destructor;
  lVar1 = M_rand();
  Sky_Fog = (Pvl_File->fog).r;
  DAT_800b2e0d = (Pvl_File->fog).g;
  DAT_800b2e0e = (Pvl_File->fog).b;
  iVar3 = lVar1 % 500;
  do {
    p_Var2 = Sky_TestZones();
    if (p_Var2 != (_ZONE *)0x0) {
      if (iVar3 == 0) {
        p_Var2 = Sky_TestZones();
        iVar3 = -1;
        if (p_Var2 == (_ZONE *)0x0) goto LAB_800683a0;
        lVar1 = M_rand();
        iVar3 = lVar1 % 500;
        if (Sky.volume == 2) {
          Fx_Play(0x34,100);
          iVar4 = 0;
        }
        else {
          Fx_PlaySoft(0x34,0xe8);
          iVar4 = 0;
        }
        do {
          (Pvl_File->fog).r = -1;
          (Pvl_File->fog).g = -1;
          (Pvl_File->fog).b = -1;
          SetFarColor(0xff,0xff,0xff);
          _SCREEN_800b993c.draw.r0 = -1;
          Screens.draw.r0 = -1;
          _SCREEN_800b993c.draw.g0 = -1;
          Screens.draw.g0 = -1;
          _SCREEN_800b993c.draw.b0 = -1;
          Screens.draw.b0 = -1;
          Task_Sleep(3);
          (Pvl_File->fog).r = Sky_Fog;
          (Pvl_File->fog).g = DAT_800b2e0d;
          (Pvl_File->fog).b = DAT_800b2e0e;
          iVar4 = iVar4 + 1;
          SetFarColor((uint)Sky_Fog,(uint)DAT_800b2e0d,(uint)DAT_800b2e0e);
          _SCREEN_800b993c.draw.r0 = Sky_Fog;
          Screens.draw.r0 = Sky_Fog;
          _SCREEN_800b993c.draw.g0 = DAT_800b2e0d;
          Screens.draw.g0 = DAT_800b2e0d;
          _SCREEN_800b993c.draw.b0 = DAT_800b2e0e;
          Screens.draw.b0 = DAT_800b2e0e;
          Task_Sleep(3);
        } while (iVar4 < 2);
      }
      iVar3 = iVar3 + -1;
    }
LAB_800683a0:
    Task_Next();
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Sky_Destructor(struct TASK *handle /*$a0*/)
 // line 110, offset 0x800683b0
	/* begin block 1 */
		// Start line: 248
	/* end block 1 */
	// End Line: 249

void Sky_Destructor(TASK *handle)

{
  (Pvl_File->fog).r = Sky_Fog;
  (Pvl_File->fog).g = DAT_800b2e0d;
  (Pvl_File->fog).b = DAT_800b2e0e;
  SetFarColor((uint)Sky_Fog,(uint)DAT_800b2e0d,(uint)DAT_800b2e0e);
  Screens.draw.r0 = Sky_Fog;
  Screens.draw.g0 = DAT_800b2e0d;
  Screens.draw.b0 = DAT_800b2e0e;
  _SCREEN_800b993c.draw.r0 = Sky_Fog;
  _SCREEN_800b993c.draw.g0 = DAT_800b2e0d;
  _SCREEN_800b993c.draw.b0 = DAT_800b2e0e;
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ Sky_TestPresence()
 // line 121, offset 0x8006844c
	/* begin block 1 */
		// Start line: 123
		// Start offset: 0x8006844C
		// Variables:
	// 		int i; // $v1
	// 		struct _ZONE *z; // $a0
	/* end block 1 */
	// End offset: 0x8006848C
	// End Line: 133

	/* begin block 2 */
		// Start line: 274
	/* end block 2 */
	// End Line: 275

/* WARNING: Unknown calling convention yet parameter storage is locked */

short Sky_TestPresence(void)

{
  int iVar1;
  _ZONE *p_Var2;
  
  iVar1 = (int)Pvl_File->n_zones;
  p_Var2 = Pvl_Zones;
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = iVar1 + -1;
    if (p_Var2->sky_active != '\0') break;
    p_Var2 = p_Var2 + 1;
  }
  return 1;
}



// decompiled code
// original method signature: 
// struct _ZONE * /*$ra*/ Sky_TestZones()
 // line 136, offset 0x80068494
	/* begin block 1 */
		// Start line: 137
		// Start offset: 0x80068494
		// Variables:
	// 		struct SKY_7fake *p; // $s2
	// 		struct _ZONE *z; // $s0
	// 		int i; // $s1
	/* end block 1 */
	// End offset: 0x80068508
	// End Line: 154

	/* begin block 2 */
		// Start line: 310
	/* end block 2 */
	// End Line: 311

/* WARNING: Unknown calling convention yet parameter storage is locked */

_ZONE * Sky_TestZones(void)

{
  short sVar1;
  _ZONE *z;
  int iVar2;
  
  iVar2 = (int)Pvl_File->n_zones;
  z = Pvl_Zones;
  while( true ) {
    if (iVar2 == 0) {
      return (_ZONE *)0x0;
    }
    if ((z->sky_active != '\0') && (sVar1 = Zone_IsPosInZone(z,100), sVar1 != 0)) break;
    iVar2 = iVar2 + -1;
    z = z + 1;
  }
  return z;
}





