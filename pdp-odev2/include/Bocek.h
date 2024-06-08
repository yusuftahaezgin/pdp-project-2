#ifndef BOCEK_H
#define BOCEK_H

#include "Canli.h"

struct BOCEK{
	Canli super;
	
	
	void (*BocekYoket)(struct BOCEK*);
};
typedef struct BOCEK* Bocek;

Bocek BocekOlustur(int);
static char* BocekGorunum();
void BocekYoket(const Bocek);
#endif