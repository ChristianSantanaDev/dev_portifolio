/*
Implemente uma pilha (stack) de inteiros usando alocação dinâmica. A pilha deve
ter capacidade inicial de 4 elementos e dobrar de tamanho automaticamente com
realloc() ao atingir o limite. Implemente as operações:
1 void push ( int ** pilha , int * topo , int * capacidade , int valor );
2 int pop (int * pilha , int * topo );
3 int peek ( int * pilha , int topo );
Demonstre no main() com pelo menos 10 inserções e 5 remoções, exibindo o estado
da pilha após cada operação
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void push ( int ** pilha , int * topo , int * capacidade , int valor ){
    if(*topo >= *capacidade){
        //estourou realocar
        int *temp = NULL;

        *capacidade*=2;

        temp = (int *) realloc(*pilha, *capacidade * sizeof(int));
        if(temp == NULL){
            printf("Erro ao realocar memoria");
            exit(1);
        }
        *pilha = temp;
        printf("PILHA CHEIA! Alterada a capacidade para %d\n", *capacidade);
    }

    (*pilha)[*topo] = valor;
    *topo += 1;
    
}

int pop (int * pilha , int * topo ){
    *topo -= 1;
    return pilha[*topo];
}

int peek ( int * pilha , int topo ){
    return pilha[topo-1];
}

int main(void){
    int topo = 0, capacidade = 4;
    int *pilha = (int *) malloc(capacidade * sizeof(int));
    int i;

    printf("Inserindo valores na pilha (push).\n");

    for(i = 0; i < 10; i++){
        printf("Inserindo na pilha o valor '%d'\n", i*2);
        push(&pilha, &topo,&capacidade, i*2);
        printf("Valor = %d\n", peek(pilha, topo));
    }

    printf("\n\nRemovendo valores da pilha (pop).\n");
        for(i = 0; i < 5; i++){
        printf("Removendo na pilha o valor '%d'\n", pop(pilha, &topo));
        printf("Valor = %d\n", peek(pilha, topo));
    }

    free(pilha);
    pilha = NULL;

    return 0;
}