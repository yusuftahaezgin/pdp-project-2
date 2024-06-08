#include "Pire.h"

Pire PireOlustur(int deger){
	Pire this;
	this = (Pire)malloc(sizeof(struct PIRE));
	this->super= BocekOlustur(deger);
	
	
	this->super->super->gorunum = &PireGorunum;
	this->PireYoket = &PireYoket;
	return this;
}

static char* PireGorunum(){
	return "P";
	
}

void PireYoket(const Pire this){
	if(this == NULL) return;
	this->super->super->yoket(this->super->super);
	this->super->BocekYoket(this->super);
	free(this);
}