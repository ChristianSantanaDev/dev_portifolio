/*
Questão 8 (Código / Análise) Analise o código abaixo e responda:
#include <stdio.h>
int main() {
 int v[5] = {3, 7, 2, 9, 1};
 int i, soma = 0;
 for (i = 0; i < 5; i++) soma += v[i];
 printf("%d\n", soma);
 return 0;
}

n) Qual o valor impresso?
22.
o) O que aconteceria se o acesso fosse v[5]? Por quê?
O computador não responderia direito ou acessaria um lixo de memoria, pois o v[5] não
existe, o v só vai de 0 até 4
p) Como ficaria o código para encontrar o maior elemento do vetor em vez da soma?
*/

#include<stdio.h>

int main(void){
    int vet[] = {3, 7, 2, 9, 1};
    int maior = 0, i;
    int tamanhovetor = sizeof(vet)/sizeof(vet[0]); // Isso mostra pra gente o tamanho do vetor, cada int tem 4B o sizeof(vet) tem 20B (4*5) e depois o sizeof(vet[0]) = 4B, 20/4 = 5 elementos, poderiamos colocar 4, mas se fosse um vetor double ou char?

    maior = vet[0]; //assumimos que o maior elemento é o v[0] e tentamos provar o contrario
    
    for(i=1;i<tamanhovetor;i++){ // começa com 1 pq não faz sentido perguntar 10 é maior que 10 sendo que a gente já sabe
        if(vet[i]>maior){
            maior = vet[i];
        }
    }
    printf("Maior => %d\n", maior);
}