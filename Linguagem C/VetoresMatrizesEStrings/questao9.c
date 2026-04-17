/*
Questão 9 (Código / Análise) Escreva um programa em C que declare uma matriz 3x3 de inteiros,
preencha-a com os valores de 1 a 9 (usando laços for) e a exiba no formato tabular abaixo:
q) Saída esperada:
r) 1 2 3
s) 4 5 6
t) 7 8 9
*/

#include <stdio.h>
#define M 3

int main(void){
    int mat[M][M];
    int i, j, z = 0;
    
    //preenchendo o vetor com numeros de um a nove
    for(i=0; i<M; i++){
        for(j=0; j<M; j++){
            mat[i][j] = ++z;
        }
    }

    //imprimindo o vertor
    for(i=0; i<M; i++){
        for(j=0; j<M; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
} 