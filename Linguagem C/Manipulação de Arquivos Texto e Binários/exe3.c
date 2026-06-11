/*
Exercício 3 — Análise de arquivo texto
Crie um arquivo texto.txt com pelo menos 5 linhas de conteúdo. Em seguida,
escreva um programa que leia o arquivo e informe:
a) O número total de linhas.
b) O número total de palavras.
c) O número total de caracteres (excluindo \n).
d) A linha de maior comprimento (exiba o conteúdo e o número da linha).
Obs.: Use fgets() para leitura linha a linha e funções de <string.h> para o processamento.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
    FILE *arquivo = fopen("index.html", "w");
    if(arquivo == NULL) return 1;

    //gravação

    fprintf(arquivo, "<h1>Titulo 1</h1>\n");
    fprintf(arquivo, "<h1>Titulo 2</h1>\n");
    fprintf(arquivo, "<h1>Titulo 3</h1>\n");
    fprintf(arquivo, "<h1>Titulo 4</h1>\n");
    fprintf(arquivo, "<h1>Titulo 5</h1>\n");
    fprintf(arquivo, "<h1>Titulo 6</h1>\n");

    fclose(arquivo);

    //LER
    arquivo = fopen("index.html", "r");
    if(arquivo == NULL) return 1;

    int i;

    char linha[50];
    char linha_top[6][50];
    for(i = 0; fgets(linha, sizeof(linha), arquivo) != NULL; i++){
        printf("%s", linha);
        strcpy(linha_top[i], linha);
    }
    fclose(arquivo);

    //contar
    printf("O 'index.html' tem %d linhas\n", i);

    int palavras = 0;
    //vou considerar assim que uma palavra tem que ter 1 letra e pula
    for(int a=0;a<6;a++){
        for(int b = 0; b < strlen(linha_top[a]); b++){

            if(linha_top[a][b] >= 'A' && linha_top[a][b] <= 'Z' ||
               linha_top[a][b] >= 'a' && linha_top[a][b] <= 'z'){
                palavras++;
               }
            //agora tem que pular
            while (linha_top[a][b] >= 'A' && linha_top[a][b] <= 'Z' ||
                   linha_top[a][b] >= 'a' && linha_top[a][b] <= 'z'){
                b++;
            }
            
        }
    }

    printf("O 'index.html' tem %d palavras\n", palavras);

    //contar caracteres
    int char_top = 0;

    for(int a = 0; a < strlen(linha_top[a]); a++){
        char_top += strlen(linha_top[a])-1;
    }

    printf("O 'index.html' tem %d caracteres.\n", char_top);

    
    int maior = 0;
    int num_linha_maior = 0;

    char linha_maior[50];

    for(int az = 0; az < i; az++){

        int tamanho = strlen(linha_top[az]);

        // remover o \n da comparação
        if(linha_top[az][tamanho - 1] == '\n'){
            tamanho--;
        }

        if(tamanho > maior){

            maior = tamanho;

            strcpy(linha_maior, linha_top[az]);

            num_linha_maior = az + 1;
        }
    }

    printf("Linha de maior comprimento:\n");
    printf("Linha %d: %s", num_linha_maior, linha_maior);
    printf("Quantidade de caracteres: %d\n", maior);

    return 0;
}