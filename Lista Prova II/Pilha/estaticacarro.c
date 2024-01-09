#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAMP 10

typedef struct carro
{
    int anodefab;
    int peso;
    char modelo[50];
}carro;

typedef struct sPilha
{
    carro pcarro[TAMP];
    int topo;
}Pilha;

void incializarp(Pilha *pPilha)
{
    pPilha->topo = -1;
}

int vazia(Pilha *pPilha)
{
    if(pPilha->topo == -1)
        return 1;
    return 0;
}

int cheia(Pilha *pPilha)
{
    if(pPilha->topo == TAMP)
        return 1;
    return 0;
}

void push(Pilha *pPliha, int peso, int ano, char *modelo)
{
    if(cheia(pPliha) == 1)
    {
        printf("Error - Lista Pilha cheia");
        return;
    }
    else
    {
        (pPliha->topo)++;
        pPliha->pcarro[pPliha->topo].anodefab = ano;
        pPliha->pcarro[pPliha->topo].peso = peso;
        strcpy(pPliha->pcarro[pPliha->topo].modelo, modelo);
    }
}

carro top(Pilha *ppilha)
{
    if(vazia(ppilha) == 1)
    {
        printf("Error - Pilha vazia");
        carro vaziocarro = {0, 0, ""};
        return vaziocarro;
    }
    return ppilha->pcarro[ppilha->topo];
}

void pop(Pilha *pPilha)
{
    if(vazia(pPilha))
    {
        printf("Error - Pilha Vazia");
        return; 
    }
    pPilha->topo--;
}

void imprirelementoseremovendo(Pilha *pPilha)
{
    if(vazia(pPilha))
    {
        printf("Error - Pilha vazaia");
        return;
    }
    while (!vazia(pPilha))
    {
        carro topcarro = top(pPilha);
        printf("Carro:\n");
        printf("Ano: %d\n", topcarro.anodefab);
        printf("Peso: %d\n", topcarro.peso);
        printf("Modelo: %s\n", topcarro.modelo);
        pop(pPilha);
    }
}


int main() {
    Pilha sPilha;
    incializarp(&sPilha);
    int choice;
    
    do {
        printf("\nMenu de Opcoes:\n");
        printf("1. Inserir um elemento no topo da pilha\n");
        printf("2. Remover um elemento do topo da pilha\n");
        printf("3. Retornar o elemento que esta no topo da pilha sem remove-lo\n");
        printf("4. Exibir todos os elementos da pilha\n");
        printf("0. Sair do programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                carro newCar;
                printf("Ano de fabricao: ");
                scanf("%d", &newCar.anodefab);
                printf("Peso: ");
                scanf("%d", &newCar.peso);
                printf("Modelo: ");
                scanf("%s", newCar.modelo);
                push(&sPilha, newCar.peso, newCar.anodefab, newCar.modelo);
                printf("Carro inserido no topo da pilha\n");
                break;
            }
            case 2:
                pop(&sPilha);
                printf("Elemento removido do topo da pilha\n");
                break;
            case 3: {
                carro topCar = top(&sPilha);
                if (topCar.anodefab != 0) {
                    printf("Elemento no topo da pilha:\n");
                    printf("Ano: %d\n", topCar.anodefab);
                    printf("Peso: %d\n", topCar.peso);
                    printf("Modelo: %s\n", topCar.modelo);
                }
                break;
            }
            case 4:
                imprirelementoseremovendo(&sPilha);
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

