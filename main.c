#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER_SIZE 256
#define KELIME_SIZE 50

//---------Arama Kısmı-------------
int metinbul(char *metin, char *aranan) {
    return strstr(metin, aranan) != NULL;
}

void kucukHarfCevir(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int Kackere(char *metin, char *aranan) {
    int sayi = 0;
    char *ptr = metin;
    int uzunluk = strlen(aranan);
    while ((ptr = strstr(ptr, aranan)) != NULL) {
        sayi++;
        ptr += uzunluk;
    }
    return sayi;
}
//satirAra: Verilen satirda aranan kelimeyi arar.Parametreler: satir (incelenecek metin), aranan (kelime), satirNo (satir numarasi)

void satirAra(char *satir, char *aranan, int satirNo,FILE *ciktiDosya) {
    char satirKopya[BUFFER_SIZE];
    char arananKopya[KELIME_SIZE];

    strncpy(satirKopya, satir, BUFFER_SIZE - 1);
    satirKopya[BUFFER_SIZE - 1] = '\0';

	strncpy(arananKopya, aranan, KELIME_SIZE - 1);
    arananKopya[KELIME_SIZE - 1] = '\0';

    kucukHarfCevir(satirKopya);
    kucukHarfCevir(arananKopya);

    if (metinbul(satirKopya, arananKopya)) {
        int tekrar = Kackere(satirKopya, arananKopya);
        satir[strcspn(satir, "\n")] = '\0';
        printf("Satir %d (%dx): %s\n", satirNo, tekrar, satir);
		if (ciktiDosya != NULL) {
   			 fprintf(ciktiDosya, "Satir %d (%dx): %s\n", satirNo, tekrar, satir);
			}
    }
}

//-----------Fonksiyonların çağırıldığı kısım
int main() {
    FILE *dosya;
    FILE *ciktiDosya;
	char ciktiYolu[BUFFER_SIZE];	
    char arananKelime[KELIME_SIZE];
    char satir[BUFFER_SIZE];
    char dosyaYolu[BUFFER_SIZE]; // Sabit metin yerine dizi olarak güncellendi
    int satirNo = 1;       

    //-----------Dosya adı alma kısmı--------
    printf("Arama yapilacak dosya adini giriniz (orn: veriler.txt): ");
    if (fgets(dosyaYolu, BUFFER_SIZE, stdin) != NULL) {
        dosyaYolu[strcspn(dosyaYolu, "\n")] = 0; // Sondaki alt satır karakterini temizle
    }

    //-----------Kelime alma kısmı--------
    printf("Aramak istediginiz kelimeyi giriniz: ");
    if (fgets(arananKelime, KELIME_SIZE, stdin) != NULL) {
        arananKelime[strcspn(arananKelime, "\n")] = 0;
    }

    //---------------Dosyayı aç-----------
    dosya = fopen(dosyaYolu, "r");
    snprintf(ciktiYolu, BUFFER_SIZE, "%s_%s_sonuc.txt", dosyaYolu, arananKelime);
	ciktiDosya = fopen(ciktiYolu, "w");
	if (ciktiDosya == NULL) {
    fprintf(stderr, "Hata: cikti dosyasi olusturulamadi!\n");
    fclose(dosya);
    return 1;
}
    if (dosya == NULL) {
        fprintf(stderr, "Hata: '%s' dosyasi bulunamadi!\n", dosyaYolu);
        return 1;
    }

    printf("\n'%s' icerisinde '%s' aranıyor...\n", dosyaYolu, arananKelime);
    printf("----------------------------------------------------------\n");

    //satır satır arama yapan kısım
    while (fgets(satir, BUFFER_SIZE, dosya) != NULL) {
        satirAra(satir, arananKelime, satirNo,ciktiDosya);  
        satirNo++;                                
    }

    fclose(dosya);fclose(ciktiDosya);

    printf("----------------------------------------------------------\n");
    printf("Arama tamamlandi.\n");
    return 0;
}