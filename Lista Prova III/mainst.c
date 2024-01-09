#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Funcionario
{
    int salario;
    int cargo;
    char nome[50];
} func;

typedef struct sNo{
    func func;
    struct sNo* dir;
    struct sNo* esq;
} no;

typedef struct sABP{
    no* ptraiz;
} abp;

no* inserir(no* raiz, int salario, int cargo, char* nome)
{
    if(raiz == NULL)
    {
        no* novoNo = (no*)malloc(sizeof(no));
        if(novoNo == NULL)
        {
            printf("Erro na alocação de memória\n");
        }
        else
        {
            novoNo->func.cargo = cargo;
            novoNo->func.salario = salario;
            strcpy(novoNo->func.nome, nome);
            novoNo->dir = NULL;
            novoNo->esq = NULL;
        }
        return novoNo;
    }

    int comparar = strcmp(nome, raiz->func.nome);

    if(comparar < 0)
    {
        raiz->esq = inserir(raiz->esq, salario, cargo, nome);
    }
    else if(comparar > 0)
    {
        raiz->dir = inserir(raiz->dir, salario, cargo, nome);
    }
    
    return raiz;
}

void imprimir(no* raiz)
{
    printf("%s ", raiz->func.nome);
    printf("%d ", raiz->func.salario);
    switch (raiz->func.cargo)
    {
    case 1:
        printf("Cargo: Gerente\n");
        break;

    case 2:
        printf("Cargo: Funcionario\n");
        break;

    case 3:
        printf("Cargo: Dono\n");
        break;

    default:
        break;
    }
}

void emordem(no* raiz)
{
    if(raiz != NULL)
    {
        emordem(raiz->esq);
        imprimir(raiz);
        emordem(raiz->dir);
    }
}

int main()
{
    no* raiz = NULL;

    raiz = inserir(raiz, 1800, 1, "Joao");
    raiz = inserir(raiz, 1500, 1, "Maria");
    raiz = inserir(raiz, 1700, 3, "Carla");
    raiz = inserir(raiz, 900, 2, "Ze");

    emordem(raiz);
    
    return 0;
}
