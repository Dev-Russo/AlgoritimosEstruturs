#include <stdio.h>
#include <stdlib.h>

// Estrutura que representa cada música da playlist
typedef struct Musica {
    char nome[100];
    int duracao;
    struct Musica *prox;
    struct Musica *ant;
} Musica;

// Função para inserir música no final da lista
void inserir(Musica **lista) {
    Musica *nova_musica = (Musica *) malloc(sizeof(Musica));
    printf("Digite o nome da musica: ");
    scanf("%s", nova_musica->nome);
    printf("Digite a duracao em minutos: ");
    scanf("%d", &nova_musica->duracao);

    // Caso a lista esteja vazia, a nova música será o primeiro elemento
    if (*lista == NULL) {
        *lista = nova_musica;
        nova_musica->ant = NULL;
        nova_musica->prox = NULL;
    }
    // Caso contrário, adiciona a nova música no final da lista
    else {
        Musica *atual = *lista;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = nova_musica;
        nova_musica->ant = atual;
        nova_musica->prox = NULL;
    }
}

// Função para remover a última música da lista
void remover(Musica **lista) {
    // Caso a lista esteja vazia, não há nada a ser removido
    if (*lista == NULL) {
        printf("A lista ja esta vazia!\n");
        return;
    }
    // Caso haja apenas um elemento na lista, remove-o e atualiza o ponteiro para a lista
    else if ((*lista)->prox == NULL) {
        free(*lista);
        *lista = NULL;
    }
    // Caso contrário, percorre a lista até encontrar o último elemento e o remove
    else {
        Musica *atual = *lista;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->ant->prox = NULL;
        free(atual);
    }
}

// Função para exibir as músicas da lista
void exibir(Musica *lista) {
    // Caso a lista esteja vazia, não há nada para exibir
    if (lista == NULL) {
        printf("A lista esta vazia!\n");
    }
    // Caso contrário, percorre a lista e exibe cada elemento
    else {
        printf("Playlist:\n");
        while (lista != NULL) {
            printf("Nome: %s, Duracao: %d min\n", lista->nome, lista->duracao);
            lista = lista->prox;
        }
    }
}

// Função para contar o número de elementos na lista
int contar(Musica *lista) {
    int contador = 0;
    while (lista != NULL) {
        contador++;
        lista = lista->prox;
    }
    return contador;
}
