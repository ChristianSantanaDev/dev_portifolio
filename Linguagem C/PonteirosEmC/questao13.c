/*
uestão 13 (Código / Análise) Analise o programa abaixo e determine a saída de cada printf().
Justifique cada resposta.
*/

#include <stdio.h>

int main() {
 int x = 100;
 int *p = &x; // SAÍDAS:
 printf("A: %d\n", x); //100
 printf("B: %d\n", *p); //100
 *p = 200;
 printf("C: %d\n", x); //200
 printf("D: %d\n", *p); //200
 return 0;
}