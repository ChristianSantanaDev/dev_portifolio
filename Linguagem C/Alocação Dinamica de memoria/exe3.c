/*
Escreva um programa que:
a) Solicite ao usuário quantos nomes deseja cadastrar (n).
b) Aloque dinamicamente um vetor de n ponteiros para char (char **nomes) usando calloc().
c) Para cada nome, aloque exatamente strlen(nome)+1 bytes com malloc().
d) Exiba todos os nomes em ordem alfabética (ordene com um algoritmo simples
de seleção ou bolha).
e) Libere toda a memória alocada.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
    //receber a quantidade
    int num;

    printf("Informe a quantidade de nomes que deseja cadastrar. ");
    scanf("%d", &num);

    getchar();

    char **vet = (char **) calloc(num, sizeof(char *));
    if(vet == NULL) return 1;

    //buffer
    char buffer[1000+1];

    for(int i = 0; i < num; i++){
        printf("Digite o nome .: ");
        fgets(buffer, 1001, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        vet[i] = (char *) calloc(strlen(buffer)+1, sizeof(char));
        if(vet[i] == NULL) return 1;
         
        strcpy(vet[i], buffer);
    }

    //ordenar
    char *aux;
    for(int i = num-1; i>=0; i--){
        for(int j=0;j<i;j++){
            if(strcmp(vet[j], vet[j+1]) > 0){
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
            }
        }
    }

    for(int i = 0; i < num; i++){
        printf("%d - %s\n", i+1, vet[i]);
    }

    for(int i = 0; i < num; i++){
        free(vet[i]);
        vet[i] = NULL;
    }

    free(vet);
    vet = NULL;

    return 0;
}