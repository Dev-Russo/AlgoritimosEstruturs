#include <stdio.h>
#include <string.h>

void atualizarpontos(int *time1, int *time2, int gols1, int gols2 ){

    if(gols1 > gols2){
        *time1 += 3;
    }if(gols2 > gols1){
        *time2 += 3;
    }else{
        *time1 += 1;
        *time2 += 1;
    }
}

int main(){
    int pontostime1, pontostime2, golstime1, golstime2;

    printf("Digite o numero de gols do time 1:\n");
    scanf("%d", &golstime1);

    printf("Digite o numero de gols do time 2:\n");
    scanf("%d", &golstime2);

    printf("Digite quantos pontos o time 1 tinha antes da partida:\n");
    scanf("%d", &pontostime1);

    printf("Digite quantos pontos o time 2 tinha antes da partida:\n");
    scanf("%d", &pontostime2);

    atualizarpontos(&pontostime1, &pontostime2, golstime1, golstime2);

    printf("Pontos do Time 1: %d\n", pontostime1);

    printf("Pontos do Time 2: %d\n", pontostime2);

    return 0;
}