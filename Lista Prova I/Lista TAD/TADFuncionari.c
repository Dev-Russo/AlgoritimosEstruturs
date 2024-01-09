#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAML 1

typedef struct funcionario
{
    int data, mes, ano;
    int salario;
    char nome[50];
} sfuncionario;

typedef struct TADFuncionario
{
    sfuncionario sFun[TAML];
    int n;
} TAD;

void incicializarTAD(TAD *t)
{
    t->n = -1;
}

void preencherdados(TAD *t, int data, int mes, int ano, char *nome, int salario)
{
    int i;
    for (i = (t->n+1); i>0; i--)
        {
            t->sFun[i] = t->sFun[i-1];
        }        
    strcpy(t->sFun->nome, nome);
    t->sFun->data = data;
    t->sFun->mes = mes;
    t->sFun->ano = ano;
    t->sFun->salario = salario;

    t->n++;
}

void imprimirDados(TAD *t, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Nome:%s\n", t->sFun[i].nome);
        printf("Salario:%d\n", t->sFun[i].salario);
        printf("Data de nascimento:%d/%d/%d\n", t->sFun[i].data, t->sFun[i].mes, t->sFun[i].ano);
    }
}

int main()
{
    TAD *t;
    sfuncionario *sFun;
    int n;

    scanf("%d", &n);

    sFun = (sfuncionario *)malloc(n * sizeof(sfuncionario));
    t = (TAD *)malloc(sizeof(TAD));

    if (t != NULL)
    {
        incicializarTAD(t);
        preencherdados(t, 10, 2, 1999, "Murilo Russo", 2000);
        preencherdados(t, 11, 3, 1998, "Murilo", 2001);
        imprimirDados(t, n);
    }

    return 0;
}