#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno
{
    char nome[50];
    float peso;
} aluno;

typedef struct sNo
{
    aluno al;
    struct sNo* esq;
    struct sNo* dir;
} no;

no* alocar()
{
    no* novoNo = (no*)malloc(sizeof(no));
    return novoNo;
}

no* inserir(no* raiz, char* nome, float peso)
{
    if (raiz == NULL)
    {
        no* novo = alocar();
        if (novo == NULL)
        {
            printf("Erro na alocação de memória.\n");
            return NULL;
        }
        else
        {
            strcpy(novo->al.nome, nome);
            novo->al.peso = peso;
            novo->esq = NULL;
            novo->dir = NULL;
            return novo;
        }
    }

    if (peso < raiz->al.peso)
    {
        raiz->esq = inserir(raiz->esq, nome, peso);
    }
    else if (peso > raiz->al.peso)
    {
        raiz->dir = inserir(raiz->dir, nome, peso);
    }

    return raiz;
}

void imprimir(no* raiz)
{
    if (raiz != NULL)
    {
        imprimir(raiz->esq);
        printf("%s - %.2f\n", raiz->al.nome, raiz->al.peso);
        imprimir(raiz->dir);
    }
}

no* buscarMinimo(no* raiz)
{
    if (raiz == NULL)
        return NULL;
    else if (raiz->esq == NULL)
        return raiz;
    else
        return buscarMinimo(raiz->esq);
}

no* remover(no* raiz, char* nome)
{
    if (raiz == NULL)
        return raiz;   // Verifica se a raiz é NULL se for retorna a própria raiz pois não tem valor a ser removido

    if (strcmp(nome, raiz->al.nome) < 0)        // Compara a string se for menor que <0 vai para a esquerda
        raiz->esq = remover(raiz->esq, nome);     //Chama recursivamente o metodo remover para o lado esquerdo

    else if (strcmp(nome, raiz->al.nome) > 0)  // Compara a string mas se ela for maior que 0 ele vai para a direita
        raiz->dir = remover(raiz->dir, nome);  // Chama recursivamente o remover do lado direito

    else  
    {
        if (raiz->esq == NULL && raiz->dir == NULL)   // Ve se a arvore é folha
        {   
            free(raiz);                             // Se for desaloca da memória
            raiz = NULL;                            // Atualiza o ponteiro Para NULL
        }
        else if (raiz->esq == NULL)                // Verifica se o lado esquerdo da arvore/subarvore é NULL
        {
            no* temp = raiz;                       // Cria um nó temporario e atribui o valor da raiz
            raiz = raiz->dir;                      // Raiz agora recebe o valor do lado direito pois não tem valor a esquerda então é atribuido o maior valor
            free(temp);                            // Desaloca a Arvor/Subarvore 
        }
        else if (raiz->dir == NULL)                // Verifica se a raiz do lado direito é NULL
        {
            no* temp = raiz;                       // Caso seja cria um nó temporario
            raiz = raiz->esq;                      // Atribui o valor a esquerda para a raiz
            free(temp);                            // Desaloca o nó anterior
        }
        else
        {
            no* temp = buscarMinimo(raiz->dir);             // Encontra o menor valor para substituir 
            raiz = temp;                                    // Transfere os valores          
            raiz->dir = remover(raiz->dir, temp->al.nome);  // Chama a função remover recursivamente
        }
    }
    return raiz;
}

void liberarArvore(no* raiz)
{
    if (raiz != NULL)
    {
        liberarArvore(raiz->esq);
        liberarArvore(raiz->dir);
        free(raiz);
    }
}

int main()
{
    no* raiz = NULL;

    raiz = inserir(raiz, "Maria", 76);
    raiz = inserir(raiz, "João", 82);
    raiz = inserir(raiz, "Ana", 68);
    raiz = inserir(raiz, "Pedro", 71);

    printf("Árvore original:\n");
    imprimir(raiz);
    printf("\n");

    raiz = remover(raiz, "Ana");

    printf("Árvore após remover Ana:\n");
    imprimir(raiz);
    printf("\n");

    liberarArvore(raiz);

    return 0;
}
