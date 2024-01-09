#include<stdio.h>
int main()
{
int x, *p ;
x = 10;
p = x ;
printf("%d" , *p );
return 0;
}

//O programa está errado pois o ponteiro está eperando outro tipo de dado, para arrumar seria necessários
//alterar o codigo para "p = &x", assim o código seria corrigido e p estaria apontando para x.