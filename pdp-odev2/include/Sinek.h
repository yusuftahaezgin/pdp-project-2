#ifndef SINEK_H
#define SINEK_H

#include "Bocek.h"

struct SINEK{
	Bocek super;
	
	
	void (*SinekYoket)(struct SINEK*);
};
typedef struct SINEK* Sinek;

Sinek SinekOlustur(int);
char* SinekGorunum();
void SinekYoket(const Sinek);
#endif