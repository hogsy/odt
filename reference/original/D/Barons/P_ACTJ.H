#ifndef P_ACTJ_H
#define P_ACTJ_H


extern void Pactj_Fall(); // 0x800383D4

extern void Pactj_Jump(); // 0x8003856C

extern void Pafj_ExecJpUp(short anm, short h, short dist); // 0x80038CD0

extern void Pafj_ExecJpDown(short sxy); // 0x80038EF0

extern void Pafj_ExecJpForward(short Anm, short txya); // 0x80039248

extern void Pafj_ExecReception(short cumul_z); // 0x800392CC

extern long Pafj_ExecChute(); // 0x800393E4


#endif
