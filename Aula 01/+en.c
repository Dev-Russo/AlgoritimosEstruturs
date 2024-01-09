#include<stdio.h>
#include<string.h>

void matrizDeDiagonalIgual(int x){
    int i, j;

    for ( i = 0; i < x; i++)
    {
        for ( j = 0; j < x; j++)
        {
            if(i == j){
                printf("n");
            }else{
                printf("+");
            }    
        }
        printf("\n");
    }
    


}

int main(){
    int n;

    printf("Digite um numero\n");
    scanf("%d", &n);

    matrizDeDiagonalIgual(n);

    return 0;
}