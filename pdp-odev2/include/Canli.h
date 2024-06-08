#ifndef CANLI_H
#define CANLI_H

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"


struct CANLI{
	int deger;
	
	char* (*toString)(struct CANLI*,void*);
	char* (*gorunum)(); 
	void (*yoket)(struct CANLI*);
};

typedef struct CANLI* Canli;

Canli CanliOlustur(int);
//char* toString(const Canli,void*);
void CanliYoket(const Canli);

#endif