#include<stdio.h>
#include<string.h>

void inverterString(char x[]){
    int count,i, j;
    char keep;

    count = strlen(x);
    for ( i = 0, j = count -1; i < j ; i++, j--)
    {
        keep = x[i];
        x[i] = x[j];
        x[j] = keep;
    }
    
    printf("%s", x);
    printf("%d", count);

}

int main(){
    char palavra[50];


    printf("Digite uma palavra\n");
    gets(palavra);

    inverterString(palavra);


    return 0;
}