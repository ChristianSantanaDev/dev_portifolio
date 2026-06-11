#include<stdio.h>

void exibe_vet(int vetor[], int n){
    for(int i = 0; i < n; i++){
        printf("%d\n", vetor[i]);
    }
    printf("\n");
}


void buble_sort(int vet[], int n){
    int i, j;

    for(i = (n-1); i > 0; i--){
        for(j = 0; j < i; j++){
            if(vet[j] > vet[j+1]){
                int temp = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = temp;
            }
        }
    }
}

int main(void){
    int vet[10] = {12, 34, 33, 9, 10, 0, -1, 2, 4, 11};
    exibe_vet(vet, 10);
    buble_sort(vet, 10);
    exibe_vet(vet, 10);

    return 0;

}
    