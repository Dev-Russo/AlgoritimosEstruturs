#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct livro
{
    char nome[50];
    int pagina;
} livro;

typedef struct sNo
{
    livro livro;
    struct sNo *prox;
}sno;

sno *inicializa(sno *plista)
{
    plista = NULL;
    return plista;
}

int listavazia(sno *plista)
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

sno *alocar()
{
    sno *aux;
    aux = (sno *)malloc(sizeof(aux));
    return aux;
}

sno *adicionarinicio(sno *plista, int npagina, char *nome)
{
    sno *novo;
    novo = alocar();
    if (novo != NULL)
    {
        strcpy(novo->livro.nome, nome);
        novo->livro.pagina = npagina;
        novo->prox = plista;
        plista = novo;
        return plista;
    }
    else
    {
        return NULL;
    }
}

sno *adicionarnofinal(sno *plista, int npagina, char *nome)
{
    sno *novo;
    sno *aux;
    novo = alocar();
    if (novo != NULL)
    {
        strcpy(novo->livro.nome, nome);
        novo->livro.pagina = npagina;
        novo->prox = NULL;
        if (listavazia(plista))
        {
            plista = novo;
        }
        else
        {
            aux = plista;
            while (aux->prox != NULL)
            {
                aux = aux->prox;
            }
            aux->prox = novo;
        }
        return plista;
    }
    return NULL;
}

sno *contador(sno *plista)
{
    sno *aux;
    int count = 0;
    if (listavazia(plista))
    {
        printf("LISTA VAZIA\n");
    }
    else
    {
        aux = plista;
        while (aux->prox != NULL)
        {
            count++;
            aux = aux->prox;
        }
        printf("A lista tem %d itens\n", count);
    }
    return 0;
}

int contadorrecursivo(sno *plista, int a)
{
    if (plista == NULL)
        return a;
    else
    {
        return contadorrecursivo(plista->prox, a + 1);
    }
}

int main()
{
    sno *plista;
    plista = (sno *)malloc(sizeof(sno));
    if (plista != NULL)
    {
        plista = inicializa(plista);
        plista = adicionarinicio(plista, 50, "joao joelho");
        plista = adicionarinicio(plista, 2000, "senhor dos anieis");
        contador(plista);
        printf("%d", contadorrecursivo(plista, 0));
    }
    return 0;
}