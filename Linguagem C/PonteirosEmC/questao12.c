/*
Questão 12 (Discursiva) Explique a diferença entre os operadores & e * quando usados com
ponteiros. Para cada operador, dê um exemplo de declaração ou expressão em código e descreva
o que ele faz.

R: O & serve pra endereço de variaveis exemplo, &x1 = 0001 | &x2 = 0002 e quando usadas no
próprio ponteiro mostra o endereço dele ex: &ptr = 0003
O * serve pra mostrar/ler/modificar o valor apontado por um ponteiro
ex: *ptr = 1

codigo:
*/

#include <stdio.h>

int main(void){
    int i = 5;
    int *pi = &i;

    printf("Endereco de i = %p e de pi = %p\n", &i, &pi);
    printf("Valor aontado por pi = %d", *pi);
    
    return 0;
}