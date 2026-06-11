/*
Exercício 1 — Leitura e escrita em arquivo texto
Escreva um programa que:
a) Crie o arquivo notas.txt e grave os dados de 5 alunos (nome e nota, um por
linha) usando fprintf().
b) Releia o arquivo com fscanf() e calcule a média da turma.
c) Crie o arquivo aprovados.txt e grave apenas os alunos com nota ≥ 6,0.
d) Exiba na tela o conteúdo de aprovados.txt usando fgets().
Obs.: Sempre verifique se fopen() retornou NULL. Feche todos os arquivos com
fclose().
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void super_fgets(char *n, int i){
    fgets(n, i, stdin);
    n[strcspn(n, "\n")] = '\0';
}

int main(void){
    FILE *f = fopen("notas.txt", "w");
    if(f == NULL) return 1;

    for(int i=0;i<5;i++){
        char nome[50];
        float nota;
        printf("Digite o nome do aluno .: ");
        super_fgets(nome, 50);
        printf("Digite a nota do aluno .: ");
        scanf("%f", &nota);
        getchar();

        fprintf(f, "%s;%.2f\n", nome, nota);
        printf("\n");
    }
    fclose(f);

    //fazer media e gravar;
    char nome[5][50];
    float nota[5];
    float media = 0;
    int i = 0;
    f = fopen("notas.txt", "r");
    if(f == NULL) return 1;
    
    while(fscanf(f, " %[^;];%f", nome[i], &nota[i]) == 2){
        media += nota[i];
        i++;
    }

    media = (float)media/5;
    printf("Media: %.2f\n\n", media);

    fclose(f);

    //escrita
    f = fopen("aprovados.txt", "w");
    if(f == NULL) return 1;
    for(int a = 0; a < 5; a++){
        if(nota[a] >= 6.0){
            fprintf(f, "%s;%.2f\n", nome[a], nota[a]);
        }
    }

    fclose(f);

    //ler denovo

    f = fopen("aprovados.txt", "r");
    if(f == NULL) return 1;
    
    char nomess[50];
    float notass;
    printf("Conteudo de 'aprovados.txt'\n");
    while(fscanf(f, " %[^;];%f", nomess, &notass) == 2){
        printf("Nome: %-49s-Nota: %.2f\n", nomess, notass);
    }

    fclose(f);


    return 0;
}