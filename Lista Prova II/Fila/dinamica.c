#include <stdio.h>
#include <stdlib.h>

typedef struct carro
{
    int placa;
    int eixos;
} Carro;

typedef struct sNo
{
    Carro car;
    struct sNo* prox;
} No;

typedef struct sFila
{
    No* inicio;
    No* fim;
} Fila;

void inicia(Fila* pfila)
{
    pfila->inicio = NULL;
    pfila->fim = NULL;
}

int vazia(Fila* pfila)
{
    return pfila->inicio == NULL;
}

void inserir(Fila* pfila, int eixos, int placa)
{
    No* novo;
    novo = (No*)malloc(sizeof(No));
    if (novo != NULL)
    {
        novo->car.eixos = eixos;
        novo->car.placa = placa;
        novo->prox = NULL;
        if (vazia(pfila) == 1)
        {
            pfila->fim = novo;
            pfila->inicio = novo;
        }
        else
        {
            pfila->fim->prox = novo;
            pfila->fim = novo;
        }
    }
    else
    {
        printf("Error - Não foi possivel alocar");
    }
}

void remover(Fila* pfila)
{
    No* aux;
    if (vazia(pfila) == 1)
    {
        printf("ERROR - Lista Vazia");
    }
    else
    {
        aux = pfila->inicio;
        pfila->inicio = aux->prox;
        if (pfila->inicio == NULL)
        {
            pfila->fim = NULL;
        }
        free(aux);
    }
}

void imprimirsemexcluir(Fila* pfila)
{
    No* aux;
    if (vazia(pfila))
    {
        printf("ERROR - Lista Vazia");
    }
    else
    {
        aux = pfila->inicio;
        while (aux != NULL)
        {
            printf("Placa: %d\n", aux->car.placa);
            printf("Eixos: %d\n", aux->car.eixos);
            aux = aux->prox;
        }
    }
}

void imprimireexcluir(Fila* pfila)
{
    No* aux;
    if (vazia(pfila))
    {
        printf("ERROR - Lista Vazia");
    }
    else
    {
        while (pfila->inicio != NULL)
        {
            aux = pfila->inicio;
            printf("Placa: %d\n", aux->car.placa);
            printf("Eixos: %d\n", aux->car.eixos);
            pfila->inicio = aux->prox;
            free(aux);
        }
        pfila->fim = NULL;
    }
}

int main()
{
    Fila fila;
    inicia(&fila);
    int escolha, placa, eixo;

    do
    {
        printf("Menu de Opcoes:\n");
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
            printf("Digite o numero da placa: ");
            scanf("%d", &placa);

            printf("Digite a quantidade de eixos: ");
            scanf("%d", &eixo);

            inserir(&fila, eixo, placa);
            break;
        case 2:
            remover(&fila);
            printf("Elemento Removido\n");
            break;
        case 3:
            printf("Elementos da fila (Impressao nao classica):\n");
            imprimirsemexcluir(&fila);
            break;
        case 4:
            printf("Elementos da fila (Impressao classica):\n");
            imprimireexcluir(&fila);
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
