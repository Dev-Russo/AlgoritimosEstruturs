#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sNo {
    int dado;
    struct sNo* prox;
} No;

typedef struct sPilha {
    No* topo;
} Pilha;

Pilha* criarPilha() {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

void empilhar(Pilha* pilha, int dado) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = dado;
    novoNo->prox = pilha->topo;
    pilha->topo = novoNo;
}

int desempilhar(Pilha* pilha) {
    if (pilha->topo == NULL) {
        printf("Erro - Pilha Vazia\n");
        return 0;
    }
    No* noTopo = pilha->topo;
    int dado = noTopo->dado;
    pilha->topo = noTopo->prox;
    free(noTopo);
    return dado;
}

int calcularExpressao(const char* expressao) {
    Pilha* pilha = criarPilha();
    int i, operando1, operando2, resultado;
    char caractere;

    for (i = 0; expressao[i] != '\0'; i++) {
        caractere = expressao[i];
        if (isdigit(caractere)) {
            int valor = caractere - '0';  // Converter o caractere numérico para valor inteiro
            empilhar(pilha, valor);
        }
        else if (caractere == '+' || caractere == '-' || caractere == '*' || caractere == '/') {
            operando2 = desempilhar(pilha);
            operando1 = desempilhar(pilha);

            switch (caractere) {
                case '+':
                    resultado = operando1 + operando2;
                    break;
                case '-':
                    resultado = operando1 - operando2;
                    break;
                case '*':
                    resultado = operando1 * operando2;
                    break;
                case '/':
                    resultado = operando1 / operando2;
                    break;
            }

            empilhar(pilha, resultado);
        }
    }

    resultado = desempilhar(pilha);
    return resultado;
}

int main() {
    char expressao[100];

    printf("Digite a expressao aritmetica pos-fixada: ");
    fgets(expressao, sizeof(expressao), stdin);
    expressao[strcspn(expressao, "\n")] = '\0';

    int resultado = calcularExpressao(expressao);
    printf("Resultado: %d\n", resultado);

    return 0;
}