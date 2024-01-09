#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMP 10

typedef struct sPratos
{
    int tipo;
    struct sPratos *prox;
} Pratos;

Pratos *alocar()
{
    Pratos *novo;
    novo = (Pratos *)malloc(sizeof(Pratos));
    return novo;
}

void desalocar(Pratos *pPratos)
{
    free(pPratos);
}

Pratos *inicia(Pratos **pPlista)
{
    *pPlista = NULL;
    return *pPlista;
}

int listavazia(Pratos **pPratos)
{
    if (*pPratos == NULL)
    {
        return 1;
    }
    return 0;
}

void push(Pratos **ppPratos, int elem)
{
    Pratos *novo;
    novo = alocar();

    if (novo != NULL)
    {
        novo->tipo = elem;
        novo->prox = *ppPratos;
        *ppPratos = novo;
    }
    else
    {
        printf("Erro na alocação");
    }
}

void remover(Pratos **ppPratos)
{
    Pratos *aux;
    if (listavazia(ppPratos))
    {
        printf("Lista Vazia");
    }
    else
    {
        aux = *ppPratos;
        *ppPratos = aux->prox;
        desalocar(aux);
    }
}

int retornaTopo(Pratos *pPratos)
{
    if (listavazia(&pPratos))
    {
        printf("Pilha Vazia");
        return -1;
    }
    else
    {
        return pPratos->tipo;
    }
}

void pop(Pratos **ppPratos)
{
    if (listavazia(ppPratos))
        printf("Erro - Pilha Vazia");
    else
    {
        while (*ppPratos != NULL)
        {
            Pratos *aux;
            aux = *ppPratos;
            switch (retornaTopo(aux))
            {
            case 1:
                printf("Prato de Porcelana\n");
                break;

            case 2:
                printf("Prato de Plastico\n");
                break;

            case 3:
                printf("Prato de Video\n");
                break;

            default:
                break;
            }
            *ppPratos = aux->prox;
            desalocar(aux);
        }
    }
}

int main()
{
    Pratos *pPrato;
    inicia(&pPrato);
    int choice;
    int elem;

    do
    {
        printf("Menu de Opcoes:\n");
        printf("1. Inserir um elemento no topo da pilha\n");
        printf("2. Remover um elemento do topo da pilha\n");
        printf("3. Retornar o elemento que esta no topo da pilha sem remove-lo\n");
        printf("4. Exibir todos os elementos da pilha\n");
        printf("0. Sair do programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            printf("Escolha entre as opcoes:\n1: Porcelana\n2: Plastico\n3: Vidro\n");
            scanf("%d", &elem);
            push(&pPrato, elem);
            break;
        }
        case 2:
        {
            pop(&pPrato);
            printf("Elemento Removido\n");
            break;
        }
        case 3:
        {
            switch (retornaTopo(pPrato))
            {
            case 1:
                printf("Prato de Porcelana\n");
                break;

            case 2:
                printf("Prato de Plastico\n");
                break;

            case 3:
                printf("Prato de Video\n");
                break;

            default:
                break;
            }
            break;
        }
        case 4:
            pop(&pPrato);
            break;
        case 0:
            printf("Encerrando o programa...\n");
            break;
        default:
            printf("Opção inválida\n");
            break;
        }

    } while (choice != 0);

    return 0;
}
