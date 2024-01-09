#include<stdio.h>
#include<stdlib.h>

#define TAML 4

typedef struct Deque
{
    int interiros[TAML];
    int fim, inicio;
} deque;

void inicia(deque *pdeque)
{
    pdeque->inicio = TAML - 1;
    pdeque->fim = TAML - 1;
}

int vazia(deque *pdeque)
{
    return pdeque->fim == pdeque->inicio;
}

int cheia(deque *pdeque)
{
    return (pdeque->fim + 1) % TAML == pdeque->inicio;
}

void inseririnicio(deque *pdeque, int elem)
{
    if(cheia(pdeque))
    {
        printf("Error - LISTA CHEIA");
        return;
    }
    else
    {
        pdeque->inicio = (pdeque->inicio - 1 + TAML) % TAML;
        pdeque->interiros[pdeque->inicio] = elem;
    }
}

int removerinicio(deque *pdeque)
{
    int a;
    if(vazia(pdeque))
    {
        printf("impossivel printar lista vazia");
        return;
    }
    else
    {
        a = pdeque->inicio = (pdeque->inicio + 1) % TAML;
        printf("elemento removido com sucesso");
    }
    return a;
}

void inserirfim(deque *pdeque, int elem)
{
    if(cheia(pdeque))
    {
        printf("Nao foi possivel inserir o elemento lista cheia");
        return;
    }
    else
    {
        pdeque->fim = (pdeque->fim + 1) % TAML;
        pdeque->interiros[pdeque->fim] = elem;
    }
}

int removerfim(deque *pdeque)
{
    int aux;
    if(vazia(pdeque))
    {
        printf("Nao foi possivel fazer a alteracao - Lista Vazia");
        return;
    }
    else
    {
        aux = pdeque->fim = (pdeque->fim - 1 + TAML) % TAML;
        printf("Elemento removido com sucesso");
    }
    return aux;
}

void leiturasemexcluir(deque *pdeque)
{
    if(vazia(pdeque))
    {
        printf("Nao ha itens para ser lido");
        return;
    }
    else
    {
       int aux = pdeque->inicio;

       while (aux != pdeque->fim)
       {
            aux = (aux + 1) % TAML;
            printf("Elemento: %d\n", pdeque->interiros[aux]);
       }
        
    }
}


void leituraclassica(deque *pdeque)
{
    if(vazia(pdeque))
    {
        printf("Nao ha itens para ser lido");
        return;
    }
    else
    {
        int aux = pdeque->inicio;

        while (aux != pdeque->fim)
        {
            aux = (aux + 1) % TAML;
            printf("Elemento: %d\n", pdeque->interiros[aux]);
            removerinicio(pdeque);
        }
        
    }
}


int main()
{
    deque meuDeque;
    inicia(&meuDeque);
    int escolha, elemento;

    printf("Menu de Opcoes:\n");

    do
    {
        printf("1. Inserir um elemento no inicio do deque\n");
        printf("2. Remover um elemento no inicio do deque\n");
        printf("3. Inserir um elemento no fim do deque\n");
        printf("4. Remover um elemento no fim do deque\n");
        printf("5. Exibir todos os elementos do deque (Impressao nao classica)\n");
        printf("6. Exibir todos os elementos do deque (Impressao classica)\n");
        printf("0. Sair do programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            printf("Digite o elemento a ser inserido no inicio do deque: ");
            scanf("%d", &elemento);
            inseririnicio(&meuDeque, elemento);
            break;
        case 2:
            removerinicio(&meuDeque);
            break;
        case 3:
            printf("Digite o elemento a ser inserido no fim do deque: ");
            scanf("%d", &elemento);
            inserirfim(&meuDeque, elemento);
            break;
        case 4:
            removerfim(&meuDeque);
            break;
        case 5:
            printf("Elementos do deque (Impressao nao classica):\n");
            leiturasemexcluir(&meuDeque);
            break;
        case 6:
            printf("Elementos do deque (Impressao classica):\n");
            leituraclassica(&meuDeque);
            break;
        case 0:
            printf("Encerrando o programa...\n");
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }

    } while (escolha != 0);

    return 0;
}
