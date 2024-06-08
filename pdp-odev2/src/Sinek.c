#include "Sinek.h"

Sinek SinekOlustur(int deger){
	Sinek this;
	this = (Sinek)malloc(sizeof(struct SINEK));
	//this->super->super = CanliOlustur(deger);
	this->super = BocekOlustur(deger);
	
	
	this->super->super->gorunum = &SinekGorunum;
	this->SinekYoket = &SinekYoket;
	return this;
}

char* SinekGorunum(){
	return "S";
	
}

void SinekYoket(const Sinek this){
	if(this == NULL) return;
	this->super->super->yoket(this->super->super);
	this->super->BocekYoket(this->super);
	free(this);
}