#include<stdio.h>


void ordena(int *n1, int *n2, int *n3) {
    int temp;

    if (*n1 > *n2) {
        temp = *n1;
        *n1 = *n2;
        *n2 = temp;
    }
    if (*n1 > *n3) {
        temp = *n1;
        *n1 = *n3;
        *n3 = temp;
    }
    if (*n2 > *n3) {
        temp = *n2;
        *n2 = *n3;
        *n3 = temp;
    }
}

int main() {
    int n1, n2, n3;

    printf("Digite 3 numeros: ");
    scanf("%d %d %d", &n1, &n2, &n3);

    ordena(&n1, &n2, &n3);

    printf("Numeros ordenados: %d %d %d\n", n1, n2, n3);
    
    return 0;
}