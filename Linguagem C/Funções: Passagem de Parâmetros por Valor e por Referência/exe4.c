/*
Escreva um programa que declare um vetor de 10 inteiros e, usando exclusivamente
aritmética de ponteiros (sem índices [ ]):
a) Preencha o vetor com os quadrados dos índices (0, 1, 4, 9, . . .).
b) Exiba todos os elementos.
c) Calcule a soma dos elementos por meio de uma função que recebe int *inicio
e int *fim (ponteiro para além do último elemento).
Obs.: Proibido usar indexação com [ ] nas funções de preenchimento, exibição e soma
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int calcula_soma(int *inicio, int *fim);

int main(void){
    int i;
    int *vet = (int *) malloc( 10 * sizeof(int) );
    if(vet == NULL) return 1;

    for(i = 0; i < 10; i++){
        *(vet+i) = i*i;
    }
    
    for(i = 0; i < 10; i++){
        printf("%d ", *(vet+i));
    }

    printf("\nSoma geral de vet = %d\n\n", calcula_soma(vet, vet+10));
    printf("\n\n...\n\n");
    
    free(vet);
    vet = NULL;
    return 0;
}

int calcula_soma(int *inicio, int *fim){
    int soma = 0;
    for(int *i = inicio; i< fim; i++){
        soma += *i;
    }
    return soma;
}
