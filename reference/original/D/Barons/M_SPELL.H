#ifndef M_SPELL_H
#define M_SPELL_H


extern unsigned long MSpell_TestAppliedOnObject(struct _D3_OBJECT *D3Obj, long index); // 0x800817C4

extern long MSpell_AppliedOnObject(struct _D3_OBJECT *D3Obj, long index); // 0x8008186C

extern void MSpell_SpellTesting(struct _MONSTER *monst, long WhatSpell, long WParam1, long anim); // 0x80081934


#endif
