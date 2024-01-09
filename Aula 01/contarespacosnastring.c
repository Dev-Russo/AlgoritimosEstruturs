#include<stdio.h>
#include<string.h>

int main(){
    int count = 0;  
    int i;
    char frase[50];

    printf("digite uma palavra\n");
    gets(frase);

    for ( i = 0; i < 50; i++)
    {
        if (frase[i] == ' '){
            count ++;
        }
    }

    printf("%d", count);


    return 0;
}