#ifndef MSENSORB_H
#define MSENSORB_H


extern long MSensorB_Test_Path(struct _MONSTER *monst); // 0x80070EB4

extern long MSensorB_Test_ViolatedWaitZone(struct _MONSTER *mo); // 0x80070FF8

extern long MSensorB_Test_HeardPlayer(struct _MONSTER *mo); // 0x800710C8

extern long MSensorB_Test_ViewMonster(struct _MONSTER *monst); // 0x800710D0

extern long MSensorB_Test_ViewPlayer(struct _MONSTER *mo); // 0x800711C0

extern long MSensorB_Test_NearToPlayer(struct _MONSTER *mo); // 0x80071384

extern long MSensorB_Test_HitByPlayerBullet(struct _MONSTER *monst); // 0x800713C0

extern long MSensorB_Test_HitByMonsterBullet(struct _MONSTER *monst); // 0x80071414

extern long MSensorB_Test_HitByGrenade(struct _MONSTER *monst); // 0x80071498

extern long MSensorB_Test_MyTarget(struct _MONSTER *mo); // 0x800714C0

extern long MSensorB_Test_TargetInformation(struct _MONSTER *mo); // 0x8007150C


#endif
