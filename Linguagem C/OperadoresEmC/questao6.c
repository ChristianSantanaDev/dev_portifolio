/*Questão 6 (Código / Análise)
 Escreva um programa que leia dois números inteiros com scanf()
 e exiba: a soma, a diferença, o produto, o quociente real (com 2 casas decimais)
 e o resto da divisão.
*/

#include<stdio.h>

float divr1(int a, int b);
int divr2(int a, int b);

int main(void){
    int a = 0, b = 0;
    printf("Digite 2 numeros =>");
    scanf("%d%d", &a, &b);
    
    printf("\nSoma: %d\nDiferenca: %d\nProduto: %d\nQuociente real: %.2f\nResto da divisão: %d\n\n", (a+b), (a-b), (a*b), divr1(a,b), divr2(a, b) );
    
    return 0;
}

float divr1(int a, int b){
    if(b==0){
        printf("ERROR! divisão por 0!");
        return 0.0;
    } else {
    return (float)a/b;
    }
}

int divr2(int a, int b){
    if(b==0){
        return 0;
    } else {
    return (a%b);
    }
}