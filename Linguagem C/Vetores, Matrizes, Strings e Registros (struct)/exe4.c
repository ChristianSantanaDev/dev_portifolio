/*
Implemente uma agenda simples com a estrutura:
1 typedef struct {
2 char nome [40];
3 char telefone [15];
4 char email [50];
5 } Contato ;
O programa deve oferecer um menu com as opções:
a) Adicionar contato.
b) Buscar por nome (busca linear).
c) Listar todos em ordem alfabética.
d) Remover contato.
e) Sair.
Suporte até 50 contatos em um vetor estático.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
    char nome [40];
    char telefone [15];
    char email [50];
} Contato ;

void buble_sort(Contato *vetor, int n){
    int i, j;
    Contato *mvet = vetor; 
    Contato aux;

    for(i=n-1; i >= 0; i--){
        for(j = 0; j<i; j++){
            if(strcmp(mvet[j].nome, mvet[j+1].nome) > 0){
                aux = mvet[j];
                mvet[j] = mvet[j+1];
                mvet[j+1] = aux;
            }
        }
    }
}

void super_fgets(char *n, int i){
    fgets(n, i, stdin);
    n[strcspn(n, "\n")] = '\0';
}

int main(void){
    Contato vetor[50];
    int i = 0;
    int op;
    
    while(1){
        printf("1-Adicionar contatos\n2-Buscar por nome\n3-Listar todos em ordem alfabetica\n4-Remover contato\n0-Sair\nDigite sua opcao\n=> \n");
        scanf("%d", &op);
        getchar();
        
        if(op == 1){
            if(i == 50){
                printf("\n\nAgenda cheia!\n\n");
            } else {
                printf("\n\nAdicionar contato!\n");
                printf("Digite o nome => ");
                super_fgets(vetor[i].nome, 40);
                printf("Digite o telefone => ");
                super_fgets(vetor[i].telefone, 15);
                printf("Digite o email => ");
                super_fgets(vetor[i].email, 50);
                printf("Contato adicionado com sucesso!\n\n");
                i++;
            }

        } else if(op == 2){
            if(i == 0){
                printf("\n\nSem contatos a buscar!\n\n");
            } else {
                printf("\n\nBuscar por nome!\n");
                char nome[40];
                printf("Digite o nome que quer buscar => ");
                super_fgets(nome, 40);
                //busca
                int pos = -1;
                for(pos = 0; pos < i; pos++){
                    if(strcmp(nome, vetor[pos].nome) == 0){
                        break;
                    }
                }
                if(pos != -1){
                    printf("\nNome achado na posição %d!\n", pos);
                    printf("Nome: %s\n", vetor[pos].nome);
                    printf("Telefone: %s\n", vetor[pos].telefone);
                    printf("Email: %s\n\n", vetor[pos].email);
                } else {
                    printf("Nome não encontrado!\n\n");
                }
            }

        } else if(op == 3){
            if(i == 0){
                printf("\n\nSem contatos a Mostrar!\n\n");
            } else {
                buble_sort(vetor, i);
                for(int j = 0; j < i; j++){
                    printf("\n\nContato n°%d\n", j+1);
                    printf("Nome: %s\n", vetor[j].nome);
                    printf("Telefone: %s\n", vetor[j].telefone);
                    printf("Email: %s\n", vetor[j].email);
                    printf("-----------------------------------------\n");
                }
                printf("\n\n");   
            }
        } else if(op == 4){
            if(i == 0){
                printf("\n\nSem contatos a remover!\n\n");
            } else {
                printf("\n\nRemover contato!\n");
                printf("Digite o o numero do contato que deseja remover.\n\n");

                for(int j = 0; j < i; j++){
                    printf("\n\nContato n°%d\n", j+1);
                    printf("Nome: %s\n", vetor[j].nome);
                    printf("-----------------------------------------\n");
                }
                printf("\n\n");

                int ap;
                printf("Digite o o numero do contato que deseja remover.\n\n");
                scanf("%d", &ap);
                getchar();

                /*
                logica abcd
                       abdd
                       abd
                */
                //verificar se é valido
                if(ap>=1 && ap<=i){
                    for(int j=ap-1;j<i-1;j++){
                        vetor[j] = vetor[j+1];
                    }
                    i--;
                }
                printf("\n\n");
            }
        } else if(op == 0){
            printf("\n\nSaindo!\n\n");
            break;
        } else{
            printf("\n\nOpção invalida!\n\n");
        }
    }

    return 0;
}