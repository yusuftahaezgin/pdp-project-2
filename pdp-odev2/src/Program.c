#include "Canli.h"
#include "Bitki.h"
#include "Bocek.h"
#include "Sinek.h"
#include "Pire.h"
#include "Habitat.h"




int main(){
	
	
	char* yol ="C:\\Users\\HP\\Desktop\\Veri.txt";
	Habitat hb = HabitatOlustur();
	hb->ye(yol);
	
	hb->HabitatYoket(hb);
	
	return 0;
}