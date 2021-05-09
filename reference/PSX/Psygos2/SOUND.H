#ifndef SOUND_H
#define SOUND_H


extern void Sound_Init(unsigned char bMode); // 0x8009FEBC

extern void Sound_Start(); // 0x8009FF9C

extern void Sound_Quit(); // 0x8009FFC0

extern void * Sound_LoadGroup(char *name); // 0x8009FFC8

extern void Sound_ReleaseGroup(); // 0x8009FFE8

extern short Sound_AllocGroup(void *group); // 0x800A000C

extern void * Sound_FileRead(void *group, long wSampleId); // 0x800A0088

extern void Sound_SetMasterVolume(unsigned char bVolume); // 0x800A00A8

extern void Sound_SetCdVolume(unsigned char bVolume); // 0x800A00C4

extern void Sound_SetCallBack(TDRFuncPtr_Sound_SetCallBack0CallBack CallBack); // 0x800A00F4

extern void Sound_SetMode(unsigned char bMode); // 0x800A0114

extern void Sound_UnInit(); // 0x800A0130

extern void Sound_Pause(); // 0x800A016C

extern void Sound_Continue(); // 0x800A0264

extern long Sound_TransferVAG(void *group, short wSampleId, void *pImgPtr); // 0x800A0318

extern int Sound_FreeSRAM(char dwSampleId); // 0x800A048C

extern long Sound_VagIsLoop(char *pVag); // 0x800A053C

extern short Sound_TestEmptyVoices(char *bStatus); // 0x800A055C

extern void Sound_SetVoicePitch(long dwVoice, long dwMulti, char bPitchMode); // 0x800A05B8

extern long Sound_TurnOffUnusedVoices(char *bStatus); // 0x800A0634

extern void Sound_Off(); // 0x800A08AC

extern void Sound_ManageVoices(); // 0x800A0964

extern short Sound_Play(struct _VoiceSetting *Set); // 0x800A0B94

extern short Sound_PlayInPause(struct _VoiceSetting *Set); // 0x800A0E54

extern void Sound_Stop(int wPlayId, int wStopAll); // 0x800A0FC4

extern void Sound_StopTask(); // 0x800A10FC

extern void Sound_Update(struct _VoiceSetting *Set); // 0x800A1454

extern void Sound_SetVol(int wPlayId, unsigned char bVolume); // 0x800A1508

extern void Sound_SetPitch(long wPlayId, long dwVol); // 0x800A1594

extern void Sound_SetEffectVolume(int wPlayId); // 0x800A1728

extern void Sound_SetMonoVolume(long wPlayId); // 0x800A179C

extern void Sound_SetStereoVolume(long wPlayId); // 0x800A180C

extern void Sound_SetDolbyVolume(int wPlayId); // 0x800A18E4

extern int Sound_GetFreePlayId(); // 0x800A1B28

extern int Sound_GetFreeVoice(); // 0x800A1B7C

extern void Sound_GetPanLRFB(struct SOUND_7fake *pos, char *PanLR, char *PanFB); // 0x800A1C40

extern char Sound_GetVolFromDist(struct SOUND_7fake *pos, struct SOUND_7fake *reference, long curve); // 0x800A1DA8

extern long Sound_IsON(int wSampleId); // 0x800A1EE4

extern void Sound_PlayCd(short wTrack, short wChannel); // 0x800A1F10

extern void Sound_PlayCdTask(); // 0x800A1F70

extern void Sound_ReadCdTrack(short wTrack, short wChannel); // 0x800A1FC0

extern void Sound_StopCd(); // 0x800A21B8

extern void Sound_PlayCdDestructor(); // 0x800A21E0

extern void SpuInitMalloc() ; // 0x800A2200


typedef void (*TDRFuncPtr_Sound_SetCallBack0CallBack)();




#endif
