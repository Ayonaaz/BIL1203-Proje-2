#include <stdio.h>
#include <string.h> 

int main(){
	char metin[10000]={"My name is Alex. Every day, I wake up at 7:00 AM. I drink a cup of coffee and read the news. Then, I go to work by bus. I love my job because my colleagues are very friendly. In the evening, I cook dinner and watch a movie before I go to sleep."};
	char bul[100]={"MY"};
	strlwr (metin);
	strlwr (bul);
	char *sonuc=strstr(metin,bul);
	
	if(sonuc!=NULL){
		printf("%s aranan kelime\n",bul);
	}
	else{
		printf("Kelime yok");
	}
	return 0;
	
}