/*
Questão 17 (Código / Análise) Escreva um programa completo com as seguintes funções:
 aa) int maior(int a, int b) — retorna o maior entre dois inteiros.
 bb) int menorVetor(int v[], int n) — retorna o menor elemento de um vetor de n elementos.
 cc) No main(): leia 5 inteiros, armazene em um vetor, e exiba o maior par de vizinhos e o menor
elemento do vetor.
*/

#include<stdio.h>

int maior(int a, int b);
int menorVetor(int v[], int n);

int main(void){
    int vet[5], i;
    int menor, par1, par2;
    
    for(i=0; i<5; i++){
        printf("Digite o %d valor do vetor => ", i+1);
        scanf("%d", &vet[i]);
    }

    //menor do vet
    menor = vet[0];
    for(i=0;i<5;i++){
        if(vet[i]<menor){
            menor = vet[i];
        }
    }


    par1 = vet[0]; par2 = vet[1];
    for(i=1;i<5;i++){
        if( (vet[i-1]+vet[i])>(par1+par2) ){
            par1 = vet[i-1];
            par2 = vet[i]; 
            }
        }

    printf("Menor elemento do vetor => %d\n", menor);
    printf("maior par => %d e %d\n", par1, par2);
    
    return 0;
}

int maior(int a, int b){
    if(a>=b){
        return a;
    } else {
    return b;
    }
}

int menorVetor(int v[], int n){
    int men = v[0], i;
    for(i=0; i<n; i++){
        if(v[i]<men){
            men = v[i];
        }
    }
    return men;
}