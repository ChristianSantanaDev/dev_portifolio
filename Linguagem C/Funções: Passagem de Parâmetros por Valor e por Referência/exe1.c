/*
Implemente duas versões de uma função de troca (swap):
a) trocarPorValor(int a, int b) — recebe cópias e tenta trocar internamente.
b) trocarPorReferencia(int *a, int *b) — recebe endereços e realiza a troca
efetivamente.

No main(), declare duas variáveis inteiras, exiba seus valores antes e depois de cada
chamada. Explique em comentários no código por que a versão por valor não altera
os originais.

1 Prototipo das funcoes 
2 void trocarPorValor ( int a , int b );
3 void trocarPorReferencia (int *a , int *b );
*/

#include<stdio.h>

void trocarPorValor(int a, int b);
void trocarPorReferencia(int *a, int *b);

int main(void){
    int a = 5, b = 10;

    //Aqui não vai trocar pois passa apenas uma copia local das variaveis sendo assim 
    //não fazendo uma alteração nas variaveis passadas.
    printf("Troca por valor\n");
    printf("Antes:\nA=%d | B=%d\n", a, b);
    trocarPorValor(a, b);
    printf("Depois:\nA=%d | B=%d\n\n\n", a, b);

    //Aqui vai trocar pois ele passa o endereço de onde esta a e b na memoria.
    printf("Troca por referencia\n");
    printf("Antes:\nA=%d | B=%d\n", a, b);
    trocarPorReferencia(&a, &b);
    printf("Depois:\nA=%d | B=%d\n", a, b);

    return 0;
}

void trocarPorValor(int a, int b){
    int aux = a;
    a = b;
    b = aux;
}

void trocarPorReferencia(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}
