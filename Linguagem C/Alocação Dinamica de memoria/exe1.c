/*
Escreva um programa que:
a) Solicite ao usuário a quantidade n de inteiros.
b) Aloque dinamicamente um vetor de n inteiros com malloc().
c) Leia os valores do teclado e calcule a soma.
d) Peça um novo tamanho m > n e utilize realloc() para expandir o vetor.
e) Preencha as novas posições com zeros e exiba o vetor completo.
f) Libere a memória com free() ao final.
Obs.: Verifique sempre se malloc() / realloc() retornaram NULL antes de prosseguir.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
    int n, m, soma = 0;
    int *arr = NULL, *temp = NULL;

    printf("Type array size .: ");
    scanf("%d", &n);

    arr = (int *) calloc(n, sizeof(int));
    if(arr == NULL) return 1;

    for(int i = 0; i<n; i++){
        printf("Digite arr[%d] .: ", i);
        scanf("%d", arr+i);
        soma += *(arr+i);
    }

    printf("Soma total = %d\n", soma);

    printf("\nType new array size .: ");
    scanf("%d", &m);

    temp = (int *) realloc(arr, m * sizeof(int));
    if(temp == NULL) return 1;

    arr = temp;

    for(int i = n; i < m; i++){
        *(arr+i) = 0;
    }

    printf("Displaying vector\n");


    for(int i = 0; i < m; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");
    
    free(arr);
    arr = NULL;
    temp = NULL;
    
    return 0;
}