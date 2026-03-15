#include <stdio.h>
#include <string.h> 
int main()
{
    char str[300]={"Selam guzeller ben dünyaaaa!"};
    char bul[20]={"guzeller"};
    char *sonuc = strstr(str,bul);
    if(sonuc!=NULL)
    {
        printf("Bulunan kelime: %s\n",sonuc);
    }
    else
    {
        printf("Kelime bulunamadı.\n"); 
    }
    return 0;
}