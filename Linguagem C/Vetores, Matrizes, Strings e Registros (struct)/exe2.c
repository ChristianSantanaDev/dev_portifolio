#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define N 4

/*
Exercício 2 — Operações com matrizes N × N
Implemente, usando funções, as seguintes operações sobre matrizes N ×N (N definido
por #define):
a) Preencher com valores aleatórios entre 1 e 100 (use rand()).
b) Exibir formatada.
c) Calcular a transposta.
d) Calcular o produto de duas matrizes.
e) Verificar se a matriz é simétrica (A = AT
).
Obs.: Use N = 4. Passe as matrizes como parâmetros bidimensionais às funções.
*/

void pre_ale(int matriz[N][N]){
    int i, j;
    
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            matriz[i][j] = (rand() % 100) + 1;
        }
    }
}

void exi_for(int matriz[N][N]){
    int i, j;
    
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("%-5d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("------------------------\n\n");
}

void cal_tra(int matriz[N][N]){
    int j, i;

    for(j = 0; j < N; j++){
        for(i = 0; i < N; i++){
            printf("%-5d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("------------------------\n\n");
}

void cal_pro(int m1[N][N], int m2[N][N]){
    int a, b, c;
    int acc;

    for(a = 0; a < N; a++){


        for(b = 0; b < N; b++){

            acc = 0;
            for(c = 0; c < N; c++){
                acc = acc + (m1[a][c]*m2[c][b]);
            }
            printf("%-5d ", acc);
        }
        printf("\n");
    }
    printf("------------------------\n\n");
}

int ver_tra(int matriz[N][N]){
    // se transposta retorna 1 senão retorna 0
    int j, i;
    int ver = 1;

    for(j = 0; j < N; j++){
        for(i = 0; i < N; i++){
            if(matriz[i][j] != matriz[j][i]){
                ver = 0;
            }
        }
    }

    return ver;
}


int main(void){
    srand(time(NULL));
    int a[N][N], b[N][N];
    pre_ale(a);
    pre_ale(b);
    printf("Exibindo matriz A\n");
    exi_for(a);
    printf("Exibindo matriz B\n");
    exi_for(b);
    printf("Exibindo matriz A(transposta)\n");
    cal_tra(a);
    printf("Exibindo matriz B(transposta)\n");
    cal_tra(b);
    printf("Exibindo produto de A e B\n");
    cal_pro(a, b);

    printf("A matriz A é %s\n", (ver_tra(a) == 1) ? "transposta.\n" : "não transposta.\n");
    printf("A matriz B é %s\n", (ver_tra(b) == 1) ? "transposta.\n" : "não transposta.\n");

    return 0;
}