#include "Habitat.h"

Habitat HabitatOlustur(){
	Habitat this;
	this = (Habitat)malloc(sizeof(struct HABITAT));
	
	this->HabitatYoket = &HabitatYoket;
	this->ye = &ye;
	return this;
}

void ye(char* dosyaYolu){
	FILE* dosya = fopen(dosyaYolu, "r");
	
	if (dosya == NULL) {
        printf("Dosya acilamadi!");
    }
	
	
	int toplamSayi = 0;
	int sayiIcerisinde=0;

    int satirSayisi = 0;
    int karakter;

    // Dosyadaki her bir karakteri oku
    while ((karakter = fgetc(dosya)) != EOF) {
        // Eğer karakter yeni satır karakteri ise, satır sayısını artır
        if (karakter == '\n') {
            satirSayisi++;
        }
		if (isdigit(karakter)) {
            if (!sayiIcerisinde) {
                // Yeni bir sayının başlangıcı
                toplamSayi++;
                sayiIcerisinde = 1;
            }
        } else if (karakter == '\n') {
            sayiIcerisinde = 0; 
        } else {
            sayiIcerisinde = 0; 
        }
		
    }
	satirSayisi+=1;
	fclose(dosya);
	

	
	int sutunSayisi = toplamSayi/satirSayisi;
	
	//printf("satir sayisi: %d\n ",satirSayisi);
	//printf("toplam sayi: %d\n",toplamSayi);
	//printf("sutun sayi: %d\n",sutunSayisi);
	
	int dizi[toplamSayi];
	char* harfler=(char*)malloc(toplamSayi*sizeof(char*));
	
	FILE* dosya2 = fopen(dosyaYolu, "r");
	//dosyadaki verileri okuyup int dizisine attım
	for (int i = 0; i <toplamSayi; i++) {
        fscanf(dosya2,"%d",&dizi[i]);
    }
	fclose(dosya2);

	
	// dizideki verilere gore harfdizisi olusturdum
	for(int i=0;i<toplamSayi;i++){
		if(dizi[i]>= 1 && dizi[i]< 10) {
			//printf("%d",dizi[i]);
			Bitki b = BitkiOlustur(dizi[i]);
			harfler[i] = *(b->super->gorunum());
			b->BitkiYoket(b);
		}
		
		else if(dizi[i]>= 10 && dizi[i]<=20) {
			Bocek c = BocekOlustur(dizi[i]);
			harfler[i] =*(c->super->gorunum());
			c->BocekYoket(c);
		}
		
		else if(dizi[i]>= 21 && dizi[i]<=50) {
			Sinek s = SinekOlustur(dizi[i]);
			harfler[i]=*(s->super->super->gorunum());
			s->SinekYoket(s);
		}
		
		else if(dizi[i]>= 51 && dizi[i]<=99) {
			Pire p = PireOlustur(dizi[i]);
			harfler[i]=*(p->super->super->gorunum());
			p->PireYoket(p);
		}
		
	}
	

	
	char* yasayan=harfler; //ilk elemanı tutar
	char* sonraki=harfler+1; // sonraki elemanı tutar
	int* YasayanDeger=dizi;
	int* SonrakiDeger=dizi+1;
	
	
	
for(int i=0;i<toplamSayi;i++){
		system("cls");
		// harf dizisini yazdırma
	for (int i = 0; i < satirSayisi; i++) {
		for(int j = 0; j < sutunSayisi; j++){
			printf("%c ",harfler[i*sutunSayisi+j]); 
		}
		printf("\n");
    }
		printf("\n");
	
		if(*yasayan=='C'){
			if(*sonraki=='B'||*sonraki=='P'){
				*sonraki='X';
				sonraki=sonraki+1;
				SonrakiDeger=SonrakiDeger+1;
			}
			else if(*sonraki=='S'){
				*yasayan='X';
				yasayan=sonraki;
				sonraki=sonraki+1;
				YasayanDeger=SonrakiDeger;
				SonrakiDeger=SonrakiDeger+1;
			}
			else if(*sonraki=='C'){
				if(*YasayanDeger<*SonrakiDeger){
					*yasayan='X';
					yasayan=sonraki;
					sonraki=sonraki+1;
					YasayanDeger=SonrakiDeger;
					SonrakiDeger=SonrakiDeger+1;
				}
				else{
					*sonraki='X';
					sonraki=sonraki+1;
					SonrakiDeger=SonrakiDeger+1;
				}
			}
		}
		
		else if(*yasayan=='S'){
			if(*sonraki=='C'||*sonraki=='P'){
				*sonraki='X';
				sonraki=sonraki+1;
				SonrakiDeger=SonrakiDeger+1;
			}
			
			else if(*sonraki=='B'){
				*yasayan='X';
				yasayan=sonraki;
				sonraki=sonraki+1;
				YasayanDeger=SonrakiDeger;
				SonrakiDeger=SonrakiDeger+1;
			}
			else if(*sonraki=='S'){
				if(*YasayanDeger<*SonrakiDeger){
					*yasayan='X';
					yasayan=sonraki;
					sonraki=sonraki+1;
					YasayanDeger=SonrakiDeger;
					SonrakiDeger=SonrakiDeger+1;
				}
				else{
					*sonraki='X';
					sonraki=sonraki+1;
					SonrakiDeger=SonrakiDeger+1;
				}
			}
		}
		
		else if(*yasayan=='B'){
			if(*sonraki=='S'||*sonraki=='P'){
				*sonraki='X';
				sonraki=sonraki+1;
				SonrakiDeger=SonrakiDeger+1;
			}

			else if(*sonraki=='C'){
				*yasayan='X';
				yasayan=sonraki;
				sonraki=sonraki+1;
				YasayanDeger=SonrakiDeger;
				SonrakiDeger=SonrakiDeger+1;
			}
			else if(*sonraki=='B'){
				if(*YasayanDeger<*SonrakiDeger){
					*yasayan='X';
					yasayan=sonraki;
					sonraki=sonraki+1;
					YasayanDeger=SonrakiDeger;
					SonrakiDeger=SonrakiDeger+1;
				}
				else{
					*sonraki='X';
					sonraki=sonraki+1;
					SonrakiDeger=SonrakiDeger+1;
				}
			}
		}
		
		else if(*yasayan=='P'){
			if(*sonraki=='C'||*sonraki=='B'||*sonraki=='S'){
				*yasayan='X';
				yasayan=sonraki;
				sonraki=sonraki+1;
				YasayanDeger=SonrakiDeger;
				SonrakiDeger=SonrakiDeger+1;
			}
			else if(*sonraki=='P'){
				if(*YasayanDeger<*SonrakiDeger){
					*yasayan='X';
					yasayan=sonraki;
					sonraki=sonraki+1;
					YasayanDeger=SonrakiDeger;
					SonrakiDeger=SonrakiDeger+1;
				}
				else{
					*sonraki='X';
					sonraki=sonraki+1;
					SonrakiDeger=SonrakiDeger+1;
				}
			}
		}
		
	}
	
	//Kazananı yazdırma
	for (int i = 0; i < satirSayisi; i++) {
			for(int j = 0; j < sutunSayisi; j++){
				if(dizi[i*sutunSayisi+j]==*YasayanDeger && harfler[i*sutunSayisi+j]!='X'){
					printf("Kazanan: %c : (%d, %d)",*yasayan,i,j);
				}
			}
	}

}



void HabitatYoket(const Habitat this){
	if(this == NULL) return;
	free(this);
}