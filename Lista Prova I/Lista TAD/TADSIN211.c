#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAML 45

typedef struct aluno
{
    char nome[50];
    int matricula;
    int notas[10];
}aluno;

typedef struct listaaluno
{
    aluno al[TAML];
    int n;
}listaaluno;

void inicializarlista(listaaluno* lista)
{
    lista->n = -1;
}

int listacheia(listaaluno* lista)
{
    if(lista->n + 1 == TAML)
    {
        printf("ERROR - LISTA CHEIA");
        return 1;
    }
    else
    {
        return 0;
    }
}

void inseririnicio(listaaluno* lista, char* nome, int matricula, int nota[10])
{
    if(listacheia(lista))
    {
        printf("ERRO - LISTA CHEIA");
    }
    for (int i = lista->n + 1; i > 0; i--)
    {
        lista->al[i] = lista->al[i-1];
    }
    strcpy(lista->al[0].nome, nome);
    lista->al[0].matricula = matricula;
    for (int i = 0; i < 10; i++)
    {
        lista->al[0].notas[i] = nota[i];
    }
    
    lista->n++;
}

int procurarpmatricula(listaaluno* lista, int pmatricula)
{
    for (int i = 0; i < TAML; i++)
    {
        if(lista->al[i].matricula == pmatricula)
        {
            printf("%d",i);
            return i;
        }
        if (i == TAML)
        {
            printf("Não encontrada");
            return 1;
        }
    }
    return 0;
}

void removeraluno(listaaluno* lista)
{
    lista->al[lista->n].matricula = 0;
    for (int i = 0; i < 10; i++)
    {
        lista->al[lista->n].notas[i] = 0;    
    }
    lista->al[lista->n].nome = "";
}

void notafinal(listaaluno* lista)
{
    int count;
    for ( int i = 0; i < TAML; i++)
    {
        printf("%s", lista->al[i].nome);
        printf("%d", lista->al[i].matricula);
        for (int i = 0; i < 10; i++)
        {
            count = count + lista->al[i].notas;
        }
        printf("%d", count);
    }
    
}

int main()
{
    return 0;
}