#ifndef BITKI_H
#define BITKI_H

#include "Canli.h"

struct BITKI{
	Canli super;
	
	
	void (*BitkiYoket)(struct BITKI*);
};
typedef struct BITKI* Bitki;

Bitki BitkiOlustur(int);
static char* BitkiGorunum();
void BitkiYoket(const Bitki);
#endif