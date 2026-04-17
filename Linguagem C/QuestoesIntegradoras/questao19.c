/*
Questão 19 (Código / Análise) Escreva um programa completo em C que:
 ee) Declare um vetor de 5 floats.
 ff) Preencha o vetor com valores lidos do teclado (usando scanf).
 gg) Passe o vetor para uma função calcularMedia(float v[], int n) que retorne a média.
 hh) Exiba a média com 2 casas decimais no main().
 ii) Use ponteiro na função para acessar os elementos do vetor.
*/

#include<stdio.h>

float calcularMedia(float v[], int n);

int main(void){
    float vet[5];
    int i;
    
    for(i=0;i<5;i++){
        printf("%d posicao=> ", i+1);
        scanf("%f", &vet[i]);
    }
    
    printf("Media do vet = %.2f\n", calcularMedia(vet, 5) );
    return 0;
}

float calcularMedia(float v[], int n){
    float acc = 0;
    int i;
    for(i=0;i<n;i++){
        acc+=*(v+i);
    }
    return (float)acc/n;
} 