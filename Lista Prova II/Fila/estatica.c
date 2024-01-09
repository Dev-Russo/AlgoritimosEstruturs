#include <stdio.h>
#include <stdlib.h>

#define TAMF 4

typedef struct fila
{
    int inteiros[TAMF];
    int inicio, fim;
} fila;

void inicia(fila *pfila)
{
    pfila->fim = TAMF - 1;
    pfila->inicio = TAMF - 1;
}

int vazia(fila *pfila)
{
    if (pfila->fim == pfila->inicio)
    {
        printf("FILA VAZIA\n");
        return 1;
    }
    return 0;
}

int cheia(fila *pfila)
{
    return (pfila->fim + 1) % TAMF == pfila->inicio;
}

void inserir(fila *pfila, int elem)
{
    if (cheia(pfila))
    {
        printf("FILA CHEIA\n");
    }
    else
    {
        pfila->fim = (pfila->fim + 1) % TAMF;
        pfila->inteiros[pfila->fim] = elem;
        printf("Elemento %d inserido na fila\n", elem);
    }
}

int remover(fila *pfila)
{
    int a;
    if (vazia(pfila))
    {
        printf("Impossivel remover. Fila vazia.\n");
    }
    else
    {
        printf("Elemento removido da fila.\n");
        a = pfila->inicio = (pfila->inicio + 1) % TAMF;
    }
    return a;
}

void imprimirNaoClassica(fila *pfila)
{
    if (vazia(pfila))
    {
        printf("Fila vazia.\n");
        return;
    }

    printf("Elementos da fila (Impressão nao classica):\n");

    int indice = pfila->inicio;  // Variável auxiliar que começa com o índice do início

    do
    {
        printf("%d\n", pfila->inteiros[indice]);  // Imprime o valor da posição atual

        indice++;  // Avança para a próxima posição

        if (indice >= TAMF)  // Se o índice ultrapassar o tamanho máximo, retorna ao início da fila
            indice = 0;

    } while (indice != pfila->fim);  // Enquanto o índice não for igual ao índice do fim

    printf("%d\n", pfila->inteiros[indice]);  // Imprime o último elemento (índice do fim)
}



void imprimir_classica(fila *pfila)
{
    if (vazia(pfila)) {
        printf("A fila esta vazia.\n");
        return;
    }

    int aux = pfila->inicio;
    while (aux != pfila->fim) {
        printf("Elemento: %d\n", remover(pfila));
        aux = (aux + 1) % TAMF;
    }

    printf("Elemento: %d\n", remover(pfila) );
}


int main()
{
    fila fila;
    inicia(&fila);
    int escolha, a;

    printf("Menu de Opcoes:\n");

    do
    {
        printf("1. Inserir um elemento na fila\n");
        printf("2. Remover um elemento da fila\n");
        printf("3. Exibir todos os elementos da fila (Impressao nao classica)\n");
        printf("4. Exibir todos os elementos da fila (Impressao classica)\n");
        printf("0. Sair do programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            printf("Digite o elemento a ser inserido: ");
            scanf("%d", &a);
            inserir(&fila, a);
            break;
        case 2:
            remover(&fila);
            break;
        case 3:
            printf("Elementos da fila (Impressao nao clássica): ");
            imprimirNaoClassica(&fila);
            break;
        case 4:
            printf("Elementos da fila (Impressao classica): ");
            imprimir_classica(&fila);
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
