#ifndef HABITAT_H
#define HABITAT_H

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "ctype.h"

#include "Canli.h"
#include "Bitki.h"
#include "Bocek.h"
#include "Sinek.h"
#include "Pire.h"

struct HABITAT{
	
	
	void (*ye)(char*);
	void (*HabitatYoket)(struct HABITAT*);
};

typedef struct HABITAT* Habitat;

Habitat HabitatOlustur();
void ye(char*);
void HabitatYoket(const Habitat);
#endif