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

void satirAra(char *satir, char *aranan, int satirNo) {
    char satirKopya[BUFFER_SIZE];
    char arananKopya[KELIME_SIZE];

    strcpy(satirKopya, satir);
    strcpy(arananKopya, aranan);

	kucukHarfCevir(satirKopya);
    kucukHarfCevir(arananKopya);
    
      char *konum = strstr(satirKopya, arananKopya);

    if (metinbul(satirKopya, arananKopya)) {
        int tekrar = Kackere(satirKopya, arananKopya);
        int org = konum - satirKopya;
        printf("Satir %d (%dx): %s", satirNo, tekrar, satir+org);
    }
}

//-----------Fonksiyonların çağırıldığı kısım
int main() {
    FILE *dosya;
    char arananKelime[KELIME_SIZE];
    char satir[BUFFER_SIZE];
    char *dosyaYolu = "veriler.txt";
    int satirNo = 1;       

    //-----------Kelime alma kısmı--------
    printf("Aramak istediginiz kelimeyi giriniz: ");
    if (fgets(arananKelime, KELIME_SIZE, stdin) != NULL) {
        arananKelime[strcspn(arananKelime, "\n")] = 0;
    }

    //---------------Dosyayı aç-----------
    dosya = fopen(dosyaYolu, "r");
    if (dosya == NULL) {
        fprintf(stderr, "Hata: '%s' dosyasi bulunamadi!\n", dosyaYolu);
        return 1;
    }

    printf("\n'%s' icerisinde '%s' aranıyor...\n", dosyaYolu, arananKelime);
    printf("----------------------------------------------------------\n");

    //satır satır arama yapan kısım
    while (fgets(satir, BUFFER_SIZE, dosya) != NULL) {
        satirAra(satir, arananKelime, satirNo);  
        satirNo++;                                
    }

    fclose(dosya);

    printf("----------------------------------------------------------\n");
    printf("Arama tamamlandi.\n");
    return 0;
}