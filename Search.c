#include <stdio.h>
#include <string.h> 
int main(){
	char metin[10000]={"Yazılım dünyasında en sık karşılaşılan hatalardan biri, karakter dizilerinin sonuna 'null terminator' eklemeyi unutmaktır. C programlama dili bu konuda çok hassastır. Eğer dikkat edilmezse, bilgisayar hafızadaki rastgele karakterleri de ekrana basabilir."};
	char bul[100]={"Karşılaştırılan\0"};
	char *sonuc=strstr(metin,bul);
	
	if(sonuc!=NULL){
		printf("%s aranan kelime\n",bul);
	}
	else{
		printf("Kelime yok");
	}
	return 0;
	
}