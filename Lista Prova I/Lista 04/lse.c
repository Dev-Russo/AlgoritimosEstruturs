#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct sNo
{
    int numero;
    struct sNo* esquerdo;
    struct sNo* direito;
}no;

void inserir_inicio(no** pplista, int elemento)
{
    no* novo;
    novo = (no*)malloc(sizeof(no));
    if(novo == NULL)
    {
        printf("não foi possivel alocar");
    }
    else
    {
        novo->numero = elemento;
        novo->esquerdo = NULL;
        novo->direito = NULL;
        if(*pplista == NULL)
        {
            *pplista = novo;
        }
        else
        {
            novo->direito = *pplista;
            (*(*pplista)).esquerdo = novo;
            (*pplista) = novo;
        }
    }
}

void remover_incio(no** pplista)
{
    no* aux;
    aux = *pplista;
    if(*pplista == NULL)
    {
        printf("lista vazia");
    }
    else
    {
        *pplista = aux->direito;
        if(*pplista != NULL)
        {
            (*pplista)->esquerdo = NULL;
        }
        free(aux);
    }
}

void exibirinverso(no** pplista)
{
    no* aux;
    int a;
    aux = *pplista;
    while (aux->direito != NULL)
    {
        aux = aux->direito;
    }
    while (aux != NULL)
    {
        printf("%d", aux->numero);
        aux = aux->esquerdo;
    }
}

void soma(no** pplista)
{
    no* aux;
    int soma;
    aux = pplista;
    while (aux != NULL)
    {
        soma += aux->numero;
        aux = aux->direito;
    }
    
}