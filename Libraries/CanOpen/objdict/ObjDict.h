
/* File generated by gen_cfile.py. Should not be modified. */

#ifndef OBJDICT_H
#define OBJDICT_H

#include "data.h"

/* Prototypes of function provided by object dictionnary */
UNS32 ObjDict_valueRangeTest (UNS8 typeValue, void * value);
const indextable * ObjDict_scanIndexOD (UNS16 wIndex, UNS32 * errorCode, ODCallback_t **callbacks);

/* Master node data struct */
extern CO_Data ObjDict_Data;
extern UNS16 inj_dur_1a;		/* Mapped at index 0x2000, subindex 0x00*/
extern UNS16 inj_dur_1b;		/* Mapped at index 0x2001, subindex 0x00*/
extern UNS16 inj_dur_2a;		/* Mapped at index 0x2002, subindex 0x00*/
extern UNS16 inj_dur_2b;		/* Mapped at index 0x2003, subindex 0x00*/
extern UNS16 inj_dur_3a;		/* Mapped at index 0x2004, subindex 0x00*/
extern UNS16 inj_dur_3b;		/* Mapped at index 0x2005, subindex 0x00*/
extern UNS16 inj_dur_4a;		/* Mapped at index 0x2006, subindex 0x00*/
extern UNS16 inj_dur_4b;		/* Mapped at index 0x2007, subindex 0x00*/
extern UNS16 inj_dur_5a;		/* Mapped at index 0x2008, subindex 0x00*/
extern UNS16 inj_dur_5b;		/* Mapped at index 0x2009, subindex 0x00*/
extern UNS16 inj_dur_6a;		/* Mapped at index 0x200A, subindex 0x00*/
extern UNS16 inj_dur_6b;		/* Mapped at index 0x200B, subindex 0x00*/

#endif // OBJDICT_H