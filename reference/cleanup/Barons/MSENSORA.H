#ifndef MSENSORA_H
#define MSENSORA_H


extern long MSensor_AddFear(struct _MONSTER *monst, short value); // 0x80070604

extern long MSensor_AddAgression(struct _MONSTER *monst, short value); // 0x80070670

extern long MSensorA_Test_AmIInZone(struct _MONSTER *monst); // 0x800706E4

extern long MSensorA_Test_HeightInFront(struct _MONSTER *mo); // 0x8007085C

extern long MSensorA_Test_Fear(struct _MONSTER *monst); // 0x80070CD4

extern long MSensorA_Test_Agression(struct _MONSTER *monst); // 0x80070CF4

extern long MSensorA_Test_HitPoints(struct _MONSTER *mo); // 0x80070D14

extern long MSensorA_Test_TargetedByPlayer(struct _MONSTER *monst); // 0x80070D38

extern long MSensorA_Test_TargetedByMonster(struct _MONSTER *monst); // 0x80070E38

extern long MSensorA_Test_TouchedObject(struct _MONSTER *monst); // 0x80070E40


#endif
