#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
    char nome[50];
    int peso;
    struct aluno* esquerda;
    struct aluno* direita;
} Aluno;

Aluno* criarAluno(char nome[], int peso) {
    Aluno* novoAluno = (Aluno*)malloc(sizeof(Aluno));
    strcpy(novoAluno->nome, nome);
    novoAluno->peso = peso;
    novoAluno->esquerda = NULL;
    novoAluno->direita = NULL;
    return novoAluno;
}

Aluno* inserirAluno(Aluno* raiz, char nome[], int peso) {
    if (raiz == NULL) {
        return criarAluno(nome, peso);
    }

    if (peso < raiz->peso) {
        raiz->esquerda = inserirAluno(raiz->esquerda, nome, peso);
    } else {
        raiz->direita = inserirAluno(raiz->direita, nome, peso);
    }

    return raiz;
}

Aluno* encontrarMinimo(Aluno* raiz) {
    if (raiz == NULL) {
        return NULL;
    } else if (raiz->esquerda == NULL) {
        return raiz;
    } else {
        return encontrarMinimo(raiz->esquerda);
    }
}

Aluno* removerAluno(Aluno* raiz, char nome[]) {
    if (raiz == NULL) {
        return raiz;
    }

    if (strcmp(nome, raiz->nome) < 0) {
        raiz->esquerda = removerAluno(raiz->esquerda, nome);

    } else if (strcmp(nome, raiz->nome) > 0) {
        raiz->direita = removerAluno(raiz->direita, nome);
        
    } else {
        if (raiz->esquerda == NULL) {
            Aluno* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            Aluno* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        Aluno* temp = encontrarMinimo(raiz->direita);
        raiz = temp;
        raiz->direita = removerAluno(raiz->direita, temp->nome);
    }

    return raiz;
}

void exibirAlunosEmOrdem(Aluno* raiz) {
    if (raiz != NULL) {
        exibirAlunosEmOrdem(raiz->esquerda);
        printf("Nome: %s, Peso: %d\n", raiz->nome, raiz->peso);
        exibirAlunosEmOrdem(raiz->direita);
    }
}

void liberarArvore(Aluno* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}

int main() {
    Aluno* arvore = NULL;

    arvore = inserirAluno(arvore, "João", 70);
    arvore = inserirAluno(arvore, "Maria", 65);
    arvore = inserirAluno(arvore, "Pedro", 80);
    arvore = inserirAluno(arvore, "Ana", 75);

    printf("Alunos em ordem crescente de peso:\n");
    exibirAlunosEmOrdem(arvore);

    char nomeRemover[50];
    printf("Digite o nome do aluno a ser removido: ");
    scanf("%s", nomeRemover);

    arvore = removerAluno(arvore, nomeRemover);

    printf("Alunos em ordem crescente de peso após a remoção:\n");
    exibirAlunosEmOrdem(arvore);

    liberarArvore(arvore);

    return 0;
}
