#include<stdio.h>
#include<string.h>

typedef struct Pessoa
{
    char nome[30];
    int idade;
    char endereco[30];

}People;

int main()
{
    People pes;

    strcpy(pes.nome, "Murilo");
    pes.idade = 20;
    strcpy(pes.endereco, "Centro");

    printf("%s\n", &pes.nome);

    printf("%d\n", pes.idade);

    printf("%s\n", &pes.endereco);

    return 0;

}