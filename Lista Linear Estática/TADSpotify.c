#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAML 100

typedef struct Musica
{
    char* nomeMusica;
    int duracao;

} musica;

typedef struct listaSpotify
{
    musica m[TAML];
    int n;

} lista;

 void inicializarLista(lista* l)
{
    (*l).n = -1;
}

int listaCheia(lista* l)
{
    if ((*l).n + 1 == TAML)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int inserirInicio(lista* l, musica m)
{
    int i;

    if (listaCheia(l))
    {
        for (i = 0; i < TAML; i++)
        {
            (*l).m[i+1] = (*l).m[i];
        }
        (*l);
    }
}

int main()
{
    lista* l;
    musica m;
    
    l = (lista*)malloc(sizeof(TAML));
    
    
    
    if (l != NULL)
    {
        inicializarLista(&l);
        (*l).m[0].duracao = 2;
        (*l).m[0].nomeMusica = "Blind";
        printf("Digite o nome da musica");
        gets(m.nomeMusica);
        printf("Digite a duração da musica");
        scanf("%d", m.duracao);
        inserirInicio(&l, m);    
    }
    
    return 0;
}