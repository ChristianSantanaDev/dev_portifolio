/*
Questão 3 (Código / Análise) Escreva um programa completo em C que declare as variáveis
abaixo, atribua valores a elas e as imprima conforme o exemplo de saída.
d) int: ano atual
e) float: nota final (com 2 casas decimais)
f) char: conceito (ex.: 'A')
g) Saída esperada: Ano: 2025 | Nota: 8.75 | Conceito: A 
*/
#include<stdio.h>

int main(void){
	int ano_atual = 2025;
	float nota_final = 8.75;
	char conceito = 'A';
	
	printf("Ano: %d | Nota: %.2f | Conceito: %c\n", ano_atual, nota_final, conceito);


	return 0;
}
