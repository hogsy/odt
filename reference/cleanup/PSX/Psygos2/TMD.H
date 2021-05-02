#ifndef TMD_H
#define TMD_H


extern void Tmd_Init(); // 0x8009E240

extern void Tmd_InitFile(struct TMD_72fake *Tmd); // 0x8009E254

extern void Tmd_AllocMem(long nVertices); // 0x8009E274

extern void Tmd_FreeMem(); // 0x8009E2B4

extern void Tmd_ForceSemiTrans(struct TMD_91fake *Tmd); // 0x8009E2DC

extern void Tmd_ForceSolid(struct TMD_91fake *Tmd); // 0x8009E31C

extern void Tmd_ChangeColor(struct TMD_91fake *Tmd, struct TMD_8fake *col); // 0x8009E35C

extern void Tmd_StretchZ(struct TMD_91fake *Tmd, struct TMD_7fake *pVert, short stretch); // 0x8009E418

extern short Tmd_TestEndStretchZ(struct TMD_91fake *Tmd, struct TMD_7fake *pVert); // 0x8009E470

extern void Tmd_SetZ(struct TMD_91fake *Tmd, short value); // 0x8009E4AC

extern long Tmd_GetnPrimitives(void *File); // 0x8009E4DC

extern void Tmd_GetBox(struct TMD_91fake *Tmd, struct TMD_7fake *min, struct TMD_7fake *max); // 0x8009E510

extern void GsMapModelingData() ; // 0x8009E620


#endif
