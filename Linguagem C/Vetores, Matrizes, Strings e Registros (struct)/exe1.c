/*
Exercício 1 — Cadastro de alunos com struct
Defina a estrutura:
1 typedef struct {
2 int matricula ;
3 char nome [50];
4 float notas [4];
5 float media ;
6 } Aluno ;
Escreva funções para:
a) Ler os dados de um aluno.
b) Calcular a média das 4 notas.
c) Exibir o boletim formatado.
d) Ordenar um vetor de alunos por média (decrescente).
No main(), cadastre 5 alunos, calcule as médias, ordene e exiba o ranking final.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int matricula;
    char nome[50];
    float notas[4];
    float media;
} Aluno;

float calcular_media(float *vet_notas, int n){
    float media = 0;
    for(int i = 0; i < n; i++){
        media += vet_notas[i];
    }
    return (float)media/n;
}

void ler_dado(Aluno *var){
    printf("1-Digite o numero de matricula do aluno\n=> ");
    scanf("%d", &var->matricula);
    getchar(); // para tirar o enter do buffer

    printf("2-Digite o nome do aluno\n=> ");
    fgets(var->nome, 50, stdin);
    var->nome[strcspn(var->nome, "\n")] = '\0';

    for(int i = 0; i < 4; i++){
        printf("3.%d-Digite a nota do aluno\n=> ", i+1);
        scanf("%f", &var->notas[i]);
        getchar();
    }
    var->media = calcular_media(var->notas, 4);
    printf("\nDados preenchidos com sucesso!\n\n");
}

void ordena_dec(Aluno vet[], int n){
    //variaveis
    int i, j;
    Aluno aux;
    //buble sort decrescente
        for(i = 0; i < n; i++){
            for(j = n-1; j > i; j--){
                //comparando a media
                if(vet[j].media > vet[j-1].media){
                    //swap
                    aux = vet[j];
                    vet[j] = vet[j-1];
                    vet[j-1] = aux;
                }
            }
        }

}

void exibe_bol(Aluno vet[], int n){
    int i, j;
    for(i = 0; i < n; i++){
        printf("Nome do Aluno: %s | Matricula: %d\n", vet[i].nome, vet[i].matricula);
        printf("Notas do aluno:\n");
        
        for(j = 0; j < 4; j++){
            printf("Nota %d: %.2f\n", j+1, vet[i].notas[j]);
        }
        printf("Media: %.2f\n", vet[i].media);
        printf("---------------------------------\n\n");
    }
    
}



int main(void){
    Aluno vet[5];
    int i;

    for(i = 0; i < 5; i++){
        ler_dado(&vet[i]);
    }

    printf("\n\nOrdenando notas em ordem decrescente...");
    ordena_dec(vet, 5);
    printf("\nNotas ordenadas com sucesso!\n\n");
    exibe_bol(vet, 5);



    return 0;
}

