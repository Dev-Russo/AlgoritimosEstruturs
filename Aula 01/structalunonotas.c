#include<stdio.h>
#include<string.h>

typedef struct Aluno
{
    char nome[20];
    int matricula;
    int p1;
    int p2;
    int p3;
}Aluno;


int main()
{
    Aluno al[5];
    int i;

    for ( i = 0; i < 5; i++)
    {
        printf("Insira os dados do aluno %d\n", i + 1);
        printf("Matricula: ");
        scanf("%d", &al[i].matricula);
        printf("Nome: ");
        scanf("%s", al[i].nome);
        printf("Nota 1: ");
        scanf("%d", &al[i].p1);
        printf("Nota 2: ");
        scanf("%d", &al[i].p2);
        printf("Nota 3: ");
        scanf("%d", &al[i].p3);
    }
    

    int maiornota = 0;
    int matriculadoaluno = 0;
    for ( i = 0; i < 5; i++)
    {
        if (al[i].p1 > maiornota)
        {
            maiornota = al[i].p1;
            matriculadoaluno = i;
        }
        
    }
    
    printf("Aluno com a maior nota tem a matricula %d e a nota correspondente a %d\n", 
        al[matriculadoaluno].matricula, al[matriculadoaluno].p1);


    
    float maiormedia = 0;
    float media = 0;
    int count = 0;
    for ( i = 0; i < 5; i++)
    {
        media = ((al[i].p1 + al[i].p2 + al[i].p3)/3);
        if (media > maiormedia)
        {
            maiormedia = media;
            count = i;
        }
           
    }

    printf("Aluno com a maior media tem a matricula %d e a media correspondente a %f\n",
        al[count].matricula, maiormedia);


    float menormedia = 100;
    int media1 = 0;
    int count1 = 0;
    for ( i = 0; i < 5; i++)
    {
        media1 = ((al[i].p1 + al[i].p2 + al[i].p3)/3);
        if (media1 < menormedia)
        {
            menormedia = media1;
            count1 = i;
        }
           
    }

    printf("Aluno com a menor media tem a matricula %d e a media correspondente a %f\n",
        al[count1].matricula, menormedia);

    int media2 = 0;
    for ( i = 0; i < 5; i++)
    {
        media2 = ((al[i].p1 + al[i].p2 + al[i].p3)/3);
        if(media2 > 60)
        {
            printf("Aluno da matricula %d e nome %s foi aprovado\n", al[i].matricula, al[i].nome);
        }
        if(media2 < 60)
        {
             printf("Aluno da matricula %d e nome %s foi reprovado\n", al[i].matricula, al[i].nome);
        }
    }
    

    return 0;
}


    