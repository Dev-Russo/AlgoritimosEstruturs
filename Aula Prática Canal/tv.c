#include<stdio.h>
#include<string.h>

typedef struct sCanal
{
    char nome[50];
    int num;
}Canal;

typedef struct sNo
{
    Canal info;
    struct sNo* dir;
    struct sNo* esq;
}No;

No* Alocar_No()
{
    No* aux;
    aux = (No*)malloc(sizeof(No));
    return aux;
}

int lista_vazia(No* plista)
{
    if(plista == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void inserir_Final(No** pplista, int canal, char nome)
{
    No* novo;
    No* aux;
    novo = Alocar_No();
    if(novo == NULL)
    {
        printf("error - Não foi possivel alocar.");
    }
    else
    {
        strcpy((*novo).info.nome) = nome;
        (*novo).info.num = canal;
        (*novo).esq = NULL;
        (*novo).dir = NULL;

        if(lista_vazia(pplista))
        {
            (*pplista) = novo;
        }
        aux = (*pplista);
        while((*aux).dir != NULL)
        {
            aux = (*aux).dir;
            //(*aux).esq = aux;
        }
        (*novo).esq = aux;
    }
}

int desalocarNo(No* no)
{  
   free(no); 
}

void exibir_lista(No** pplista)
{
    No* percorre;
    if(lista_vazia(pplista))
    {
        printf("Lista vazia nao elementos para mostrar");
    }
    else
    {
        percorre = (*pplista);
        while (percorre != NULL)
        {
            printf("%d", (*percorre).info.num);
            percorre = (*percorre).dir;
        }
    }
}

int remover_final(No** pplista, int elem)
{
    No* aux;
    No* guardaPonteiro;
    if(lista_vazia(pplista))
    {
        printf("Lista vazia adicione elementos primeiro");
        return 0;
    }
    else
    {
        aux = (*pplista);
        while (aux != NULL)
        {
            if((*aux).info.num == elem)
            {
                (*guardaPonteiro).esq = aux;
                (*guardaPonteiro).dir = (*aux).esq;
                desalocarNo(aux);        
            }
        }
        aux = (*aux).dir;
    }
}