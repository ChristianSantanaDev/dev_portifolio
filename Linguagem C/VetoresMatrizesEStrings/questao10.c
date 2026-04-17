/*
Questão 10 (Código / Análise) Dado o código abaixo com strings, preencha os espaços em branco
e determine a saída:
u) Preencha os quatro blanks para que a saída seja: Linguagem C tem 11 caracteres.
v) Qual seria o resultado de strcmp("abc", "abc") e strcmp("abc", "xyz")?
R: 0, -1
*/

#include <stdio.h>
#include <string.h>

int main() {
 char s1[30] = "Linguagem ";
 char s2[] = "C";
 strcat(s1, s2);
 printf("%s tem %d caracteres.\n",s1, strlen(s1));
 return 0;
}