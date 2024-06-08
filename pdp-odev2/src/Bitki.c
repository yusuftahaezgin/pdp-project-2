#include "Bitki.h"

Bitki BitkiOlustur(int deger){
	Bitki this;
	this = (Bitki)malloc(sizeof(struct BITKI));
	this->super = CanliOlustur(deger);
	
	this->super->gorunum = &BitkiGorunum;
	this->BitkiYoket = &BitkiYoket;
	return this;
}

char* BitkiGorunum(){
	return "B";
	
}

void BitkiYoket(const Bitki this){
	if(this == NULL) return;
	this->super->yoket(this->super);
	free(this);
}