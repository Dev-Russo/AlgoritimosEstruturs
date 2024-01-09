#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct supermercado
{
    char nome[50];
    int preco;
} supermercado;

typedef struct sno
{
    supermercado mercado;
    struct sno *prox;
} no;

no *inica(no *plista)
{
    plista = NULL;
    return plista;
}

no *alocarno()
{
    no *aux;
    aux = (no *)malloc(sizeof(no));
    return aux;
}

void desalocar(no *plista)
{
    free(plista);
}

int listavazia(no *plista)
{
    if (plista == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

no *inseririnicio(no *plista, char *nome, int preco)
{
    no *novo;
    novo = alocarno();
    if (novo != NULL)
    {
        strcpy(novo->mercado.nome, nome);
        novo->mercado.preco = preco;
        novo->prox = plista;
        plista = novo;
        return plista;
    }
    else
    {
        return NULL;
    }
}

no *removernofinal(no *plista)
{
    no *aux;
    if (listavazia(plista))
    {
        printf("Lista Vazia");
    }
    else
    {
        aux = plista;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        desalocar(aux);
    }
    return NULL;
}

no *contador(no *plista)
{
    no *aux;
    int count = 0;
    if (listavazia(plista))
    {
        printf("lista vazia");
    }
    else
    {
        aux = plista;
        while (aux != NULL)
        {
            count++;
            aux = aux->prox;
        }
        printf("Quantidade de intens na lista: %d\n", count);
    }
    return 0;
}

no *precomaior50(no *plista)
{
    no *aux;
    if (listavazia(plista))
    {
        printf("lista vazia");
    }
    else
    {
        aux = plista;
        do
        {
            if (plista->mercado.preco >= 50)
            {
                printf("Produto: %s\nTem preco: %d\n", aux->mercado.nome, aux->mercado.preco);
            }
            aux = aux->prox;
        } while (aux->prox != NULL);
    }
    return 0;
}

int main()
{
    no *plista;
    plista = (no *)malloc(sizeof(no));
    if (plista != NULL)
    {
        plista = inica(plista);
        plista = inseririnicio(plista, "Papel Higienico", 51);
        contador(plista);
        precomaior50(plista);
        removernofinal(plista);
    }
    return 0;
}