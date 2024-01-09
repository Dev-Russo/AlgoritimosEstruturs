#include<stdio.h>
#include<string.h>
#define MAX 5


typedef struct Eletrodomestico
{
    char nome[16];
    int potencia;
    int tempo;
}Eletrodomestico;

int main ()
{
    Eletrodomestico eletro[MAX];
    int i;
    float t;
    float consumoTotal = 0;
    float consumoRelativo[MAX];

    for ( i = 0; i < 5; i++)
    {
        printf("Digite o nome do Eletrodoméstico");
        scanf("%s", eletro[i].nome);

        printf("Digite a potencia em (Kw do aparelho)");
        scanf("%d", &eletro[i].potencia);

        printf("Digite o tempo que o aparelho fica ligado em (horas)");
        scanf("%d", &eletro[i].tempo);

    }

    printf("Digite a quantidade de tempo que os Eletrodomesticos ficam ligado em dias");
    scanf("%f", &t);
    
    for ( i = 0; i < MAX; i++)
    {
        consumoRelativo[i] =  ((eletro[i].potencia * eletro[i].tempo)/1000);
        consumoTotal += consumoRelativo[i];
    }

    for ( i = 0; i < MAX; i++)
    {
        printf("Consumo relativo do %s: %f", eletro[i].nome, (consumoRelativo[i]/consumoTotal));
    }
    
    
    return 0;
}