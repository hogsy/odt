#include "THISDUST.H"
#include "ERROR.H"


// decompiled code
// original method signature: 
// void /*$ra*/ ErrorMaster()
 // line 29, offset 0x8009ab48
	/* begin block 1 */
		// Start line: 30
		// Start offset: 0x8009AB48
	/* end block 1 */
	// End offset: 0x8009AB48
	// End Line: 30

	/* begin block 2 */
		// Start line: 58
	/* end block 2 */
	// End Line: 59

/* WARNING: Unknown calling convention yet parameter storage is locked */

void ErrorMaster(void)

{
  SystemError();
  return;
}



// decompiled code
// original method signature: 
// void SystemError() /* SystemError method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 32, offset 0x8009ab6c
void SystemError(void)

{
                    /* WARNING: Treating indirect jump as call */
  (*(code *)0xa0)();
  return;
}





