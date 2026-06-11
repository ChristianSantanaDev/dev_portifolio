/*
Exercício 2 — Matriz dinâmica — alocação por ponteiro de ponteiros
Implemente as funções:
1 int ** alocarMatriz ( int linhas , int colunas );
2 void preencherMatriz ( int ** mat , int linhas , int colunas );
3 void exibirMatriz (int ** mat , int linhas , int colunas );
4 void liberarMatriz ( int ** mat , int linhas ) ;
No main(), solicite as dimensões ao usuário, aloque a matriz, preencha com valores
lidos do teclado, exiba-a formatada e libere a memória.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int **alocarMatriz ( int linhas , int colunas ){
    int **matriz = (int **) malloc(linhas * sizeof(int *));
    if(matriz == NULL) return NULL;

    for(int i = 0; i < linhas; i++){
        matriz[i] = (int *) calloc(colunas, sizeof(int));
        if(matriz[i] == NULL) return NULL;
    }
    return matriz;
}

void preencherMatriz ( int **mat , int linhas , int colunas ){
    int i, j;
    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            printf("Digite matriz[%d][%d] .: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

void exibirMatriz (int **mat , int linhas , int colunas ){
    int i, j;
    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }    
}
void liberarMatriz ( int **mat , int linhas ){
    int i = 0;
    while(i < linhas){
        free(mat[i]);
        mat[i] = NULL;
        i++;
    }
    free(mat);
    mat = NULL;
}

int main(void){
    int linha, coluna;

    printf("Digite a linha da matriz .: ");
    scanf("%d", &linha);
    printf("Digite a coluna .: ");
    scanf("%d", &coluna);

    int **matriz = alocarMatriz(linha, coluna);
    if(matriz == NULL) return 1;

    preencherMatriz(matriz, linha, coluna);
    exibirMatriz(matriz, linha, coluna);
    liberarMatriz(matriz, linha);
    matriz = NULL;

    return 0;
}