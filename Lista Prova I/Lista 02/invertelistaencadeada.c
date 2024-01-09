#include<stdio.h>
#include<stdlib.h>

typedef struct lista
{
    int a;
    struct lista* prox;
}lista;

void inverte(lista **lista)
{
    struct lista *atual, *anterior, *proximo;
    atual = *lista;
    anterior = NULL;
    while (atual != NULL)
    {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }
    *lista = anterior;
}