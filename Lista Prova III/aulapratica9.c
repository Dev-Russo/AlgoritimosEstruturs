#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Pessoa
{
    char nome[50];
    int idade;
    float peso;
}pessoa;

typedef struct sNo
{
    pessoa pes;
    struct sNo *dir;
    struct sNo *Esq;
}no;

no* arv_Inicializar(no** raiz)
{
    *raiz = NULL;
    return *raiz;
}

no* alocarNo()
{
    no* novo = (no*)malloc(sizeof(no));
    if(novo == NULL)
    {
        printf("Erro na ALocacao");
    }
    return novo;
}

no* inserir(no** raiz, char* nome, int idade, float peso)
{
    if(*raiz == NULL)
    {
        no* novo;
        novo = alocarNo(novo);
        if(novo != NULL)
        {
            strcpy(novo->pes.nome, nome);
            novo->pes.peso = peso;
            novo->pes.idade = idade;
            return novo;
            novo->dir = NULL;
            novo->Esq = NULL;
        }
    }
    
    if(idade < ((*raiz)->Esq)->pes.idade)
    {
        (*raiz)->Esq = (inserir(&((*raiz)->Esq), nome, idade, peso));
    }else if( idade > ((*raiz)->dir)->pes.idade)
    {
        (*raiz)->dir = (inserir(&((*raiz)->dir), nome, idade, peso));
    }

    return *raiz;
}

void imprimir(no* raiz)
{
    printf("%s\n", raiz->pes.nome);
    printf("%d\n", raiz->pes.idade);
    printf("%f\n", raiz->pes.peso);
}

void preordem(no* raiz)
{
    if(raiz != NULL)
    {
        imprimir(raiz);
        preordem(raiz->Esq);
        preordem(raiz->dir);
    }
}

void emordem(no* raiz)
{
    if(raiz != NULL)
    {
        emordem(raiz->Esq);
        imprimir(raiz);
        emordem(raiz->dir);
    }
}

void posordem(no* raiz)
{
    if(raiz != NULL)
    {
        posordem(raiz->Esq);
        posordem(raiz->dir);
        imprimir(raiz);
    }
}

int main()
{
    no** raiz;
    *raiz = NULL;

    raiz = inserir(raiz, "Maria", 15, 55);
    preordem(raiz);
    


    return 0;
}