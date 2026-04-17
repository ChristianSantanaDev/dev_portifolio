/*
Questão 14 (Código / Análise) Escreva uma função chamada trocar() que receba dois inteiros por
referência (usando ponteiros) e troque seus valores. Demonstre o uso da função no main().
#include <stdio.h>
/*
Questão 14 (Código / Análise) Escreva uma função chamada trocar() que receba dois inteiros por
referência (usando ponteiros) e troque seus valores. Demonstre o uso da função no main().
*/

#include<stdio.h>

void trocar(int *a, int *b);

int main(void){
    int a = 2, b = 4;
    printf("A = %d B = %d\n\n", a, b);
    
    trocar(&a, &b);
    printf("A = %d B = %d\n", a, b);
    
    return 0;
}

void trocar(int *a, int *b){
    int aux;
    
    aux = *a;
    *a = *b;
    *b = aux;
}