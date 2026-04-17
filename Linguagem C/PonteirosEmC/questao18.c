/*
Questão 18 (Código / Análise) O que o programa abaixo imprime? Explique passo a passo o que
acontece em cada chamada recursiva.
*/
#include <stdio.h>
int soma(int n) {
 if (n <= 0) return 0;
 return n + soma(n - 1);
}
int main() {
 printf("%d\n", soma(5));
 return 0;
}
/*
R:15
A função se auto chama e vai somando assim:
soma(5) = 5+soma(4)
soma(4) = 4+soma(3)
soma(3) = 3+soma(2)
soma(2) = 2+soma(1)
soma(1) = 1+soma(0)
e depois ela devolve tudo 5+4+3+2+1 = 15
*/