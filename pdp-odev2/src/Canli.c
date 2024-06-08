#include "Canli.h"

Canli CanliOlustur(int deger){
	Canli this;
	this = malloc(sizeof(struct CANLI));
	this->deger=deger;
	
	//this->toString = &toString;
	this->yoket = &CanliYoket;
	return this;
}
//char* toString(const Canli,void*); 
void CanliYoket(const Canli this){
	if(this == NULL) return;
	free(this);
	
}