#include <stdio.h>
#include <stdlib.h>

typedef struct ABP
{
    char letra;
    struct ABP *esq;
    struct ABP *dir;
} abp;

typedef struct sABP
{
    abp *ptRaiz
}sabp;

void inicializarABP(abp **raiz)
{
    *raiz = NULL;
}

struct abp* criarNo(int valor) {
    abp* novoNo = (abp*)malloc(sizeof(abp));
    if (novoNo == NULL) {
        printf("Erro ao alocar memória para o novo nó\n");
        return NULL;
    }
    
    novoNo->letra = valor;
    novoNo->dir = NULL;
    novoNo->esq = NULL;
    return novoNo;
}

abp* inserir(abp* raiz, char elem)
{
    if(raiz == NULL)
    {
        return criarNo(elem);
    }

    if(elem < raiz->letra)
    {
        raiz->esq = inserir(raiz->esq, elem);
    }else if(elem > raiz->letra)
    {
        raiz->dir = inserir(raiz->dir, elem);
    }

    return raiz;
}

// abp * pesquisar(abp** raiz, char elem)
// {
//     abp* aux;
//     aux = raiz;

//     if(aux == NULL)
//     {
//         return NULL;
//     }else if(elem < aux->letra)
//     {
//         return pesquisar(aux->esq, elem);
//     }else if(elem > aux->letra)
//     {
//         return pesquisar(aux->dir, elem);
//     }else
//     return aux;
// }

abp * remover(abp* raiz, int elem)
{
    if(raiz->dir == NULL)
    {
        abp* aux = raiz;
        raiz = raiz->esq;
        free(aux);
    }
    else
    {
        abp* pai = raiz;
        abp* f = raiz->esq;
        while (f->dir != NULL)
        {
            pai = f;        
            f = f->dir;
        }
        raiz->letra = f->letra;
        f->letra = elem;
        raiz->esq = remover(raiz->esq, elem);
        
    }
    return raiz;
}

void imprimir(abp* raiz)
{
    printf("%c ", raiz->letra);
}

void preordem(abp *raiz)
{
    if(raiz != NULL)
    {
        imprimir(raiz);
        preordem(raiz->esq);
        preordem(raiz->dir);
    }
}

int contarElementos(abp* raiz) {
    if (raiz == NULL) {
        return 0;
    }

    int elementosEsq = contarElementos(raiz->esq);
    int elementosDir = contarElementos(raiz->dir);

    return 1 + elementosEsq + elementosDir;
}

int main()
{
     abp* raiz = NULL;

    raiz = inserir(raiz, 'D');
    raiz = inserir(raiz, 'B');
    raiz = inserir(raiz, 'F');
    raiz = inserir(raiz, 'A');
    raiz = inserir(raiz, 'C');
    raiz = inserir(raiz, 'E');
    raiz = inserir(raiz, 'G');

    printf("Impressao pre-ordem: ");
    preordem(raiz);
    printf("\n");

    return 0;
}