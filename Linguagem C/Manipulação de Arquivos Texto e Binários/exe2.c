/*
Utilizando a struct Aluno do Exercício 9, implemente um sistema que:
a) Grave um vetor de alunos em arquivo binário com fwrite().
b) Leia o arquivo binário de volta para um vetor com fread() e exiba os registros.
c) Permita acesso direto (posicionamento com fseek()) para atualizar a nota de
um aluno pelo número de matrícula.
d) Exiba o tamanho do arquivo em bytes usando ftell().
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int matricula ;
    char nome [50];
    float notas [4];
    float media ;
} Aluno ;

void super_fgets(char *n, int i){
    fgets(n, i, stdin);
    n[strcspn(n, "\n")] = '\0';
}


int main(void){
    int op;
    Aluno aluno;
    printf("1-gravar aluno\n2-ver registros\n3-atualizar a nota\n4-exibir o tamanho total do arquivo em BYTES.\n");
    scanf("%d", &op);
    getchar();

    if(op == 1){
        printf("Digite a matricula .: ");
        scanf("%d", &aluno.matricula);
        getchar();

        printf("Digite o nome do aluno .: ");
        super_fgets(aluno.nome, 50);

        float media = 0.0;

        for(int i=0;i<4;i++){
            printf("Digite a nota %d => ", i+1);
            scanf("%f", &aluno.notas[i]);
            getchar();
            media += aluno.notas[i];
        }
        media = (float)media/4;
        aluno.media = media;

        //escrevendo
        FILE *f = fopen("alunos.bin", "ab");
        if(f == NULL){
            printf("Erro ao abrir para escrita!");
            return 1;
        }
        fwrite(&aluno, sizeof(Aluno), 1, f);
        printf("Aluno escrito com sucesso!\n");
        fclose(f);
    } else if(op == 2){
        FILE *f = fopen("alunos.bin", "rb");
        if( f == NULL ) return 1;

        Aluno vet[100];
        int i = 0;

        //leitura
        while(fread(&vet[i], sizeof(Aluno), 1, f) == 1){
            i++;
        }

        for(int j = 0; j < i; j++){
            printf("Aluno: %s | Matricula: %d\n", vet[j].nome, vet[j].matricula);
            printf("Notas\n");
            for(int a = 0; a < 4; a++){
                printf("Nota %d = %.2f\n", a+1, vet[j].notas[a]);
            }
            printf("Media: %.2f\n", vet[j].media);
            printf("-----------------------------------------\n");
        }
        fclose(f);
    } else if(op == 3){
        FILE *f = fopen("alunos.bin", "r+b");
        if( f == NULL ) return 1;

        int matricula;
        printf("Digite a matricula do aluno => ");
        scanf("%d", &matricula);
        getchar();

        Aluno aluno;
        int alunoEncontrado = 0;

        while(fread(&aluno, sizeof(aluno), 1, f) == 1){
            if(aluno.matricula == matricula){
                alunoEncontrado = 1;


                int notai;
                float new;

                printf("Digite a nota que quer alterar (1-4).\n");
                scanf("%d", &notai);
                getchar();
                printf("Digite a nota em si.\n");
                scanf("%f", &new);
                getchar();

                aluno.notas[notai-1] = new;

                //calcular soma
                float soma = 0;
                for(int i = 0; i < 4; i++){
                    soma += aluno.notas[i];
                }
                aluno.media = soma/4;

                //volta um reg pq ele leu e avançou
                fseek(f, -sizeof(Aluno), SEEK_CUR);

                //sobreencrever
                fwrite(&aluno, sizeof(aluno), 1, f);

                printf("Nota atualizada com sucesso!\n");
                break;
            }
        }
        //gravar

        if(alunoEncontrado == 0){
            printf("Aluno nao encontrado!\n");
        }

        fclose(f);

    } else if(op == 4){
        FILE *f = fopen("alunos.bin", "rb");
        if(f == NULL) return 1;

        fseek(f, 0, SEEK_END);

        long tamanho = ftell(f);

        printf("Tamanho do arquivo: %ld bytes\n", tamanho);
        fclose(f);
    } else {
        printf("Opção invalida\n");
    }
    return 0;
}