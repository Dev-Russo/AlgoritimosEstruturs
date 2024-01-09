#include<stdio.h>
#include<string.h>

int main()
{
    char palavra[50];

    printf("Digite uma Palavra\n");
    scanf("%s", palavra);

        if(palavra[0] == 'a'){
            printf("%s", palavra);
        }
        if (palavra[0] == 'A')
        {
            printf("%s", palavra);
        }
        
    
    
    return 0;
}