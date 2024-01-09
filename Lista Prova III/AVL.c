#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Arquivo
{
    char nome[50];
    int nmrpasta;
}arq;


typedef struct sNo
{
    arq arq;
    int fb;
    struct sNo* dir;
    struct sNo* esq;
}no;

no* alocarno()
{
    no* novo = (no*)malloc(sizeof(no));
    return novo;
}

void avl_RotDir(no** raiz)
{
    no* aux;
    aux = (*raiz)->esq;
    (*raiz)->esq = aux->dir;
    aux->dir = *raiz;
    (*raiz)->fb = 0;
    *raiz = aux;
}

void avl_RotEsq(no** raiz)
{
    no* aux;
    aux = (*raiz)->dir;
    (*raiz)->dir = aux->esq;
    aux->esq = *raiz;
    (*raiz)->fb = 0;
    *raiz = aux;
}

void avl_Aux1(no** raiz)
{   
    no* fE;
    fE = (*raiz)->esq;

    if(fE->fb == +1)
    {
        avl_RotDir(&(*raiz));
    }
    else
    {
        avl_RotEsq(&(*raiz));
    }
    (*raiz)->fb = 0;
}

void avl_Aux2(no** raiz)
{
    no* fD;
    fD = (*raiz)->dir;

    if(fD->fb == -1)
    {
        avl_RotEsq(&(*raiz));
    }
    else
    {
        avl_RotDir(&(*raiz));
    }
    (*raiz)->fb = 0;
}

int avl_inserir(no** raiz, int elem, char nome)
{
    int ok;

    if(*raiz == NULL)
    {
        *raiz = alocarno();
        if(*raiz == NULL)
        {
            return 0;
        }
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
        strcpy((*raiz)->arq.nome, nome);
        (*raiz)->arq.nmrpasta = elem;
        (*raiz)->fb = 0;

        return 1;
    }

    if(elem < (*raiz)->arq.nmrpasta)
    {
        ok = avl_inserir(&(*raiz)->esq, elem, nome);
        if(ok)
        {
            switch ((*raiz)->fb)
            {
            case -1:
                (*raiz)->fb = 0;
                ok = 0;
                break;
            
            case 0:
                (*raiz)->fb = 1;
                break;

            
            case 1:
                avl_Aux1(&(*raiz));
                ok = 0;
                break;

            }
        }

    }
    else if (elem > (*raiz)->arq.nmrpasta)
    {
        ok = avl_inserir(&(*raiz)->dir, elem, nome);
        if(ok)
        {
            switch ((*raiz)->fb)
            {
            case 1:
                (*raiz)->fb = 0;
                ok = 0;
                break;
            
            case 0:
                (*raiz)->fb = -1;
                break;

            
            case -1:
                avl_Aux2(&(*raiz));
                ok = 0;
                break;

            }
        }
    }
    else
    {
        ok = 0;
    }

    return ok;   
}

void imprimir(no* raiz)
{
    printf("%s\n", raiz->arq.nome);
    printf("%d", raiz->arq.nmrpasta);
}

void emOrdem(no* raiz)
{
    if(raiz != NULL)
    {
        emOrdem(raiz->esq);
        imprimir(raiz);
        emOrdem(raiz->dir);
    }
}


void posOrdem(no* raiz)
{
    if(raiz != NULL)
    {
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        imprimir(raiz);
    }
}


int main()
{
    return 0;
}