#include "Bocek.h"

Bocek BocekOlustur(int deger){
	Bocek this;
	this = (Bocek)malloc(sizeof(struct BOCEK));
	this->super = CanliOlustur(deger); // kalıtım benzetimi burada
	
	
	this->super->gorunum = &BocekGorunum;
	this->BocekYoket = &BocekYoket;
	return this;
}

static char* BocekGorunum(){
	return "C";
	
}

void BocekYoket(const Bocek this){
	if(this == NULL) return;
	this->super->yoket(this->super);
	free(this);
}