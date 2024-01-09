#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define TAML 50

typedef struct inteiros
{
    int numeros[TAML];
    int n;
}inte;

void inicializa(inte* inter)
{
    inter->n = -1;
}

int verificalista(inte* inter)
{
    if(inter->n + 1 == TAML)
    {
        return 1;
    }else{
        return 0;
    }
}

void inserirFinal(inte* inter, int elem)
{
    if(verificalista(inter))
    {
        printf("ERROR - Lista Cheia");
    }
    inter->n++;
    inter->numeros[inter->n] = elem; 
}

int inserirpork(inte* inter, int elem, int k)
{
    if(verificalista(inter))
    {
        printf("ERROR - Lista Cheia");
    }
    if(k < 0 || k > inter->n + 1)
    {
        printf("ERROR - Numero invalido");
        return 1;
    }
    else
    {
        for (int i = inter->n; i > k; i--)
        {
            inter->numeros[inter->n + 1] = inter->numeros[inter->n];
        }
        inter->numeros[k] = elem;
        inter->n++;
        return 0;
    }
}

int removerpork(inte* inter, int k)
{
    if(verificalista(inter))
    {
        printf("ERROR - Lista Cheia");
    }
    if(k < 0 || k > inter->n + 1)
    {
        printf("ERROR - Numero invalido");
        return 1;
    }
    else
    {
        for (int i = k; i < inter->n ; i++)
        {
            inter->numeros[inter->n] = inter->numeros[inter->n + 1];
        }
        inter->n--;
        return 0;
    }
}

int modificarpork(inte* inter, int elem, int k)
{
    if(verificalista(inter))
    {
        printf("ERROR - Lista Cheia");
    }
    if(k < 0 || k > inter->n + 1)
    {
        printf("ERROR - Numero invalido");
        return 1;
    }
    else
    {
        inter->numeros[k] = elem;
        return 0;
    }
}

int main()
{
    return 0;
}