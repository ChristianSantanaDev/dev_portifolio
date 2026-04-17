#include <stdio.h>
/*
Questão 20 (Código / Análise) Analise o programa a seguir (que contém erros). Identifique e
corrija todos os erros, explicando o que cada erro causa.
 jj) Liste todos os erros encontrados (sintaxe e lógica).
 kk) Reescreva o programa corrigido.
 ll) Qual seria a saída correta após as correções?
#include <stdio.h>
int soma(int a, int b) {
 return a + b //falta;
}
int main() {
 int x = 5, y = 3;
 int *p;
 p = x; //faltou o &
 float resultado;
 resultado = x / y; // é bom colocar o (float) pra garantir o decimal
 printf("Soma: %d\n", soma(x, y));
 printf("Endereco: %d\n", *p); // tem que tirar o * se não puxa o valor apontado
 printf("Divisao: %f\n", resultado);
 return 0;
}
*/
//programa corrigido

int soma(int a, int b) {
    return a + b;
}

int main(){
    int x = 5, y = 3;
    int *p = &x;
    float resultado;

    resultado = (float)x / y;
    
    printf("Soma: %d\n", soma(x, y));
    printf("Endereco %p\n", p);
    printf("Divisão %f\n", resultado);
}
/*
Soma: 8
Endereco 0xFFF81CA
Divisão 1.666...
*/