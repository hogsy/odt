#include "THISDUST.H"
#include "ASC2SJIS.H"


// decompiled code
// original method signature: 
// unsigned short /*$ra*/ Asc2Sjis_Char(unsigned char ascii_code /*$a2*/)
 // line 54, offset 0x800a4490
	/* begin block 1 */
		// Start line: 55
		// Start offset: 0x800A4490
		// Variables:
	// 		unsigned short sjis_code; // $v0
	// 		unsigned char stmp; // $v1
	// 		unsigned char stmp2; // $a1
	/* end block 1 */
	// End offset: 0x800A45A0
	// End Line: 91

	/* begin block 2 */
		// Start line: 111
	/* end block 2 */
	// End Line: 112

ushort Asc2Sjis_Char(uchar ascii_code)

{
  uint in_v1;
  int iVar1;
  
  iVar1 = 0;
  if ((byte)(ascii_code - 0x20) < 0x10) {
    iVar1 = 1;
  }
  else {
    if ((byte)(ascii_code - 0x30) < 10) {
      in_v1 = 0;
    }
    else {
      if ((byte)(ascii_code - 0x3a) < 7) {
        iVar1 = 0xb;
      }
      else {
        if ((byte)(ascii_code + 0xbf) < 0x1a) {
          in_v1 = 1;
        }
        else {
          if ((byte)(ascii_code + 0xa5) < 6) {
            iVar1 = 0x25;
          }
          else {
            if ((byte)(ascii_code + 0x9f) < 0x1a) {
              in_v1 = 2;
            }
            else {
              iVar1 = 0x3f;
              if (3 < (byte)(ascii_code + 0x85)) {
                return 0x8140;
              }
            }
          }
        }
      }
    }
  }
  if (iVar1 != 0) {
    return ascii_k_table[(uint)ascii_code - (iVar1 + 0x1f)];
  }
  return ((&ascii_table)[(in_v1 & 0xff) * 2] + (ushort)ascii_code) -
         USHORT_ARRAY_800adb96[(in_v1 & 0xff) * 2];
}



// decompiled code
// original method signature: 
// void /*$ra*/ SwapByte(unsigned short *sjis_code /*$a0*/)
 // line 93, offset 0x800a4640
	/* begin block 1 */
		// Start line: 94
		// Start offset: 0x800A4640
	/* end block 1 */
	// End offset: 0x800A4640
	// End Line: 95

	/* begin block 2 */
		// Start line: 187
	/* end block 2 */
	// End Line: 188

void SwapByte(ushort *sjis_code)

{
  *sjis_code = *sjis_code >> 8 | (ushort)*(byte *)sjis_code << 8;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Asc2Sjis_String(unsigned short *sjis_string /*$s3*/, unsigned char *ascii_string /*$a1*/)
 // line 102, offset 0x800a45a8
	/* begin block 1 */
		// Start line: 103
		// Start offset: 0x800A45A8
		// Variables:
	// 		int i; // $s2

		/* begin block 1.1 */
			// Start line: 105
			// Start offset: 0x800A45DC

			/* begin block 1.1.1 */
				// Start line: 105
				// Start offset: 0x800A45DC
			/* end block 1.1.1 */
			// End offset: 0x800A45DC
			// End Line: 105
		/* end block 1.1 */
		// End offset: 0x800A45DC
		// End Line: 105
	/* end block 1 */
	// End offset: 0x800A4618
	// End Line: 108

	/* begin block 2 */
		// Start line: 204
	/* end block 2 */
	// End Line: 205

void Asc2Sjis_String(ushort *sjis_string,uchar *ascii_string)

{
  uchar ascii_code;
  ushort uVar1;
  ushort *puVar2;
  int iVar3;
  
  ascii_code = *ascii_string;
  iVar3 = 0;
  puVar2 = sjis_string;
  while (ascii_code != '\0') {
    ascii_code = *ascii_string;
    ascii_string = ascii_string + 1;
    iVar3 = iVar3 + 1;
    uVar1 = Asc2Sjis_Char(ascii_code);
    *puVar2 = uVar1;
    *puVar2 = uVar1 >> 8 | (ushort)*(byte *)puVar2 << 8;
    ascii_code = *ascii_string;
    puVar2 = puVar2 + 1;
  }
  sjis_string[iVar3] = 0;
  return;
}





