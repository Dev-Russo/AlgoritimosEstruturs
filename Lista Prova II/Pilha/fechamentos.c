#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sNo {
    char dado;            // Dado armazenado em um nó da pilha (delimitador)
    struct sNo* prox;     // Ponteiro para o próximo nó
} No;

typedef struct sPilha {
    No* topo;             // Ponteiro para o topo da pilha
} Pilha;

Pilha* criarPilha() {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->topo = NULL;   // Inicializa o topo da pilha como NULL (pilha vazia)
    return pilha;
}

void empilhar(Pilha* pilha, char dado) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = dado;             // Armazena o dado no novo nó
    novoNo->prox = pilha->topo;      // O próximo nó aponta para o antigo topo da pilha
    pilha->topo = novoNo;            // O topo da pilha aponta para o novo nó
}

char desempilhar(Pilha* pilha) {
    if (pilha->topo == NULL) {
        printf("Erro - Pilha Vazia\n");
        return '\0';
    }
    No* noTopo = pilha->topo;
    char dado = noTopo->dado;         // Armazena o dado do nó do topo
    pilha->topo = noTopo->prox;       // O topo da pilha aponta para o próximo nó
    free(noTopo);                     // Libera a memória do nó removido
    return dado;
}

int delimitadorCombinado(char abertura, char fechamento) {
    if (abertura == '(' && fechamento == ')')
        return 1;
    else if (abertura == '[' && fechamento == ']')
        return 1;
    else if (abertura == '{' && fechamento == '}')
        return 1;
    else
        return 0;
}

int expressaoBalanceada(const char* expressao) {
    Pilha* pilha = criarPilha();
    int i;
    char caractere;

    for (i = 0; expressao[i] != '\0'; i++) {
        if (expressao[i] == '(' || expressao[i] == '[' || expressao[i] == '{') {
            empilhar(pilha, expressao[i]);    // Empilha os delimitadores de abertura encontrados
        }
        else if (expressao[i] == ')' || expressao[i] == ']' || expressao[i] == '}') {
            if (pilha->topo == NULL) {
                return 0;   // Se o topo da pilha estiver vazio, a expressão está desbalanceada
            }
            else {
                caractere = desempilhar(pilha);  // Desempilha o delimitador do topo da pilha
                if (!delimitadorCombinado(caractere, expressao[i])) {
                    return 0;   // Se os delimitadores não combinarem, a expressão está desbalanceada
                }
            }
        }
    }

    if (pilha->topo == NULL)
        return 1;   // Se a pilha estiver vazia, a expressão está balanceada
    else
        return 0;   // Caso contrário, a expressão está desbalanceada
}

int main() {
    char expressao[100];

    printf("Digite uma expressao aritmetica: ");
    fgets(expressao, sizeof(expressao), stdin);
    expressao[strcspn(expressao, "\n")] = '\0';

    if (expressaoBalanceada(expressao))
        printf("Os delimitadores estao corretos na expressao.\n");
    else
        printf("Os delimitadores estao incorretos ou desbalanceados na expressao.\n");

    return 0;
}
