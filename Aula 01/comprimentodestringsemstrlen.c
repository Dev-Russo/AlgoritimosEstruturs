#include<stdio.h>

int main(){
    char palavra[50];
    int i;
    int count = 0;

    for ( i = 0; i < 50; i++)
    {
        palavra[i]  = ' ';
    }
    

    printf("Digite uma Palavra\n");
    scanf("%s", palavra);

    for ( i = 0; i < 50; i++)
    {
        if (palavra[i] != ' ')
        {
            count ++;
        }
        
    }

    printf("%d", count - 1);
    
    
    
    return 0;
}