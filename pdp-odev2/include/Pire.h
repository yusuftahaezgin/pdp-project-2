#ifndef PIRE_H
#define PIRE_H

#include "Bocek.h"

struct PIRE{
	Bocek super;
	
	
	void (*PireYoket)(struct PIRE*);
};
typedef struct PIRE* Pire;

Pire PireOlustur(int);
static char* PireGorunum();
void PireYoket(const Pire);
#endif