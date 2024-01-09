#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAML 20

typedef struct listalinearestatica
{

    int nReais[TAML];
    int n;

} Lista;

void inicializar_lista(Lista *prtL)
{
    int i;

    for (i = 0; i < TAML; i++)
    {
        (*prtL).n++;
        (*prtL).nReais[(*prtL).n] = 0;
    }

    (*prtL).n = -1;
}

int verifica_lista_cheia(Lista *prtL)
{
    if ((*prtL).n + 1 == TAML)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int inserir_final(Lista *prtL, int Elem)
{
    if (verifica_lista_cheia(prtL))
    {
        printf("ERROR - Lista cheia");
        return 1;
    }
    else
    {
        (*prtL).n++;
        (*prtL).nReais[(*prtL).n] = Elem;
        return 0;
    }
}

void imprir_lista(Lista *prtL)
{
    int i;

    for (i = 0; i < TAML; i++)
    {
        if ((*prtL).nReais[i] != 0)
        {
            printf("%d\n", (*prtL).nReais[i]);
        }
    }
}

int main()
{
    Lista *pl;
    pl = (Lista *)malloc(sizeof(TAML));

    inicializar_lista(&pl);
    if (pl != NULL)
    {
        inserir_final(&pl, 2);
        imprir_lista(&pl);
    }

    return 0;
}