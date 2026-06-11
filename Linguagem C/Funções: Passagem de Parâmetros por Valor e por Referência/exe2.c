/* 
Exercício 2 — Calculadora de estatísticas
Escreva a função abaixo e implemente seu corpo:
1 void estatisticas (int vet [] , int n ,
2 float * media , int * maior , int * menor );
A função deve calcular, via parâmetros de saída por referência, a média, o maior e o
menor valor de um vetor de n inteiros. No main(), leia o vetor do teclado e exiba os
três resultados.
Obs.: Utilize passagem do vetor por referência (ponteiro) e os demais como parâmetros
de saída. Teste com pelo menos dois vetores de tamanhos diferentes.
*/

#include<stdio.h>

void estatisticas (int vet [] , int n , float *media , int *maior , int *menor);

int main(void){
    int vetor[5] = {10, 30, 50, 60, 35};
    int maior = 0, menor = 0;
    float media = 0;

    estatisticas(vetor, 5, &media, &maior, &menor);
    
    printf("Estatisticas\n");
    printf("maior = %d\n", maior);
    printf("menor = %d\n", menor);
    printf("media = %.2f\n", media);
    return 0;
}

void estatisticas (int vet [] , int n , float *media , int *maior , int *menor){
    int i;

    //definição inicial
    *media = *maior = *menor = vet[0];

    //laço geral pra identificação de elementos e media
    for(i = 1; i < n; i++){
        //identificar maior menor
        if(vet[i] > *maior) *maior = vet[i]; else
        if(vet[i] < *menor) *menor = vet[i];
        
        *media += vet[i];
    }
    *media = (float)*media/n;
}