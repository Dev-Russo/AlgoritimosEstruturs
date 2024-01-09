#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct contatos
{
    char nome[50];
    int telefone;
}scontatos;

typedef struct slista
{
    scontatos cont;
    struct slista *prox;
}lista;

lista* inicializa(lista *plista)
{
    plista = NULL;
    return plista;
}

lista* alocar()
{
    lista *aux;
    aux = (lista*)malloc(sizeof(lista));
    return aux;
}

int listavazia(lista* plista)
{
    if (plista == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void imprimirlista(lista* plista)
{
    lista* aux;
    if(listavazia(plista))
    {
        printf("lista vazia\n");    
    }
    else
    {
        aux = plista;
        while (aux != NULL)
        {
            printf("Nome:%s\nNumero:%d\n", aux->cont.nome, aux->cont.telefone);
            aux = aux->prox;
        } 
    }
}


lista* inseririnicio(lista* plista, int numero, char* nome)
{
    lista *novo;
    novo = alocar();
    if(novo != NULL) {
        strcpy(novo->cont.nome, nome);
        novo->cont.telefone = numero;
        novo->prox = plista;
        plista = novo;
        return plista;
    }
    return NULL;
}

lista* pesquisar(lista* plista, int elem)
{
    lista* aux;
    if(listavazia(plista))
    {
        return NULL;
    }
    else
    {
        aux = plista;
        while (aux != NULL)
        {
            if(aux->cont.telefone == elem)
            {
                return aux;
            }
            aux = aux->prox;
        }
        return NULL;
    }
}

void mover_parafrente(lista **plista, int telefone) {
    lista *atual = *plista;
    lista *anterior = NULL;

    // buscar o contato desejado e sua posição anterior
    while (atual != NULL && atual->cont.telefone != telefone) {
        anterior = atual;
        atual = atual->prox;
    }

    // verificar se o contato não está no início da lista
    if (anterior != NULL && atual != NULL) {
        // remover o contato da posição atual
        anterior->prox = atual->prox;

        // inserir o contato na posição anterior à sua posição atual
        atual->prox = anterior->prox;
        anterior->prox = atual;
    } else {
        printf("Contato não encontrado ou já está no início da lista.\n");
    }
}



void transposicao(lista **plista, int telefone) {
    lista *atual = *plista;
    lista *anterior = NULL;
    lista *anterior_anterior = NULL;

    // buscar o contato desejado e suas posições anterior e anterior-anterior
    while (atual != NULL && atual->cont.telefone != telefone) {
        anterior_anterior = anterior;
        anterior = atual;
        atual = atual->prox;
    }

    // verificar se o contato não está no início da lista
    if (anterior != NULL && atual != NULL) {
        // remover o contato da posição atual
        anterior->prox = atual->prox;

        // inserir o contato na posição anterior à sua posição anterior
        if (anterior_anterior == NULL) {
            // o contato deve ser inserido no início da lista
            atual->prox = *plista;
            *plista = atual;
        } else {
            atual->prox = anterior_anterior->prox;
            anterior_anterior->prox = atual;
        }
    } else {
        printf("Contato não encontrado ou já está no início da lista.\n");
    }
}

void contagem(lista **plista, int telefone) {
    lista *atual = *plista;
    lista *anterior = NULL;
    lista *anterior_anterior = NULL;

    // buscar o contato desejado e suas posições anterior e anterior-anterior
    while (atual != NULL && atual->cont.telefone != telefone) {
        anterior_anterior = anterior;
        anterior = atual;
        atual = atual->prox;
    }

    // verificar se o contato não está no início da lista
    if (anterior != NULL && atual != NULL) {
        // remover o contato da posição atual
        anterior->prox = atual->prox;

        // contar quantos contatos têm telefone menor que o telefone do contato removido
        int contador = 0;
        lista* aux = *plista;
        while (aux != NULL && aux->cont.telefone < telefone) {
            contador++;
            aux = aux->prox;
        }

        // inserir o contato removido na posição correspondente ao contador
        if (anterior_anterior == NULL || contador == 0) {
            // o contato deve ser inserido no início da lista
            atual->prox = *plista;
            *plista = atual;
        } else {
            // o contato deve ser inserido após o contato correspondente ao contador
            lista *anterior_contador = plista;
            for (int i = 1; i < contador; i++) {
                anterior_contador = anterior_contador->prox;
            }
            atual->prox = anterior_contador->prox;
            anterior_contador->prox = atual;
        }
    }
}

int main()
{
    lista** plista;
    plista = (lista*)malloc(sizeof(lista));
    if (plista!=NULL)
    {
        plista = inicializa(plista);
        plista = inseririnicio(plista, 10, "Russo");
        plista = inseririnicio(plista, 15, "Rafael");
        imprimirlista(plista);
        plista = mover_para_frente(plista, 10);
        imprimirlista(plista);
    }
    return 0;
}