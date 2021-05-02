#ifndef OBJECT_H
#define OBJECT_H


extern void Object_Init(); // 0x8002FC54

extern void Object_InitFile(); // 0x8002FC5C

extern void Object_Constructor(struct _D3_OBJECT *o, struct _D3_OBJECT **list); // 0x8002FD80

extern void Object_TakenSetDescription(struct _D3_OBJECT *o, short index); // 0x8003024C

extern void Object_SetIndexInElement(struct _D3_OBJECT *obj, short index); // 0x800302D4


#endif
