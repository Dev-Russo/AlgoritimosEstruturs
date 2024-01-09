#include <stdio.h>
#include <string.h>

int main() {
    char s[] = "Texto de exemplo";
    int i = 2, j = 7;
    int tam = j - i + 1;
    char segmento[tam+1];


    strncpy(segmento, s+i, tam);

    segmento[tam] = '\0';

    printf("Segmento: %s\n", segmento);


    
    return 0;

}