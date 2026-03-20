#include <stdio.h>
#include <string.h> 
#include <ctype.h>

int metinbul(char *metin,char *aranan){
	return strstr(metin,aranan)!=NULL;
}
void strlwr(char *str){
	for(int i=0;str[i];i++){
		str[i]=tolower(str[i]);
	}
}
int Kackere(char*metin,char*aranan){
	int sayi=0;
	char *ptr = metin;
    int uzunluk = strlen(aranan);

    while ((ptr = strstr(ptr, aranan)) != NULL) {
        sayi++;
        ptr += uzunluk;
    }
    return sayi;
}
void satirAra(char *satir, char *aranan, int satirNo) {
    char satirKopya[1000];
    char arananKopya[100];

    strcpy(satirKopya, satir);
    strcpy(arananKopya, aranan);

    strlwr(satirKopya);
    strlwr(arananKopya);

    if (metinbul(satirKopya, arananKopya)) {
        int tekrar = Kackere(satirKopya, arananKopya);
        printf("Satir %d (%dx): %s", satirNo, tekrar, satir);
    }
}
