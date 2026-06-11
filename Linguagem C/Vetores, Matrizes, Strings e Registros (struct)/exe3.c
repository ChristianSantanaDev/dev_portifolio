/*
Implemente as funções abaixo sem usar <string.h>:
1 int meu_strlen ( const char *s );
2 char * meu_strcpy ( char * dest , const char * src ) ;
3 char * meu_strcat ( char * dest , const char * src ) ;
4 int meu_strcmp ( const char *s1 , const char * s2 );
5 char * meu_strrev ( char * s) ;  inverte in - place 
No main(), teste cada função com exemplos demonstrativos e compare os resultados
com as funções originais de <string.h>.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int meu_strlen(const char *s){
    int i = 0;
    int acc = 0;

    while(*(s+i) != '\0'){
        acc++;
        i++;
    }
    return acc;
}

char *meu_strcpy (char * dest , const char * src){
    char *endereco_inicial = dest;
    int i;

    for(i = 0; *(src+i) != '\0'; i++){
        *(dest+i) = *(src+i);
    }

    *(dest+i) = '\0';

    return endereco_inicial;
    
}


int meu_strcmp ( const char *s1 , const char * s2 ){
    int i = 0;

    while((*(s1+i) == *(s2+i)) && (*(s1+i) != '\0')){
        i++;
    }

    return (int)*(s1+i)-*(s2+i);
}

char *meu_strrev(char *s){
    char *posi = s;
    char aux;

    int i, tamanho = meu_strlen(s);

    for(i = 0; i < tamanho/2; i++){
        aux = *(s+i);
        *(s+i) = *(s+(tamanho-1-i));
        *(s+(tamanho-i-1)) = aux;
    }
    return posi;
}


int main(void){
    //testando strlen
    char e1[100] = "Eu estou programando em C!";
    printf("Contando e1 com meu_strlen: %d\n", meu_strlen(e1));
    printf("Contando e1 com strlen: %zu\n\n", strlen(e1));
    //------------------------------------------------------------
    //testando strcpy
    char ea1[50] = "", ea2[50] = "Linguagem de programacao.";
    char ea1a[50] = "", ea2a[50] = "Linguagem de programacao.";
    meu_strcpy(ea1, ea2);
    printf("Testando meu_strcpy: %s\n", ea1);
    strcpy(ea1a, ea2a);
    printf("Testando strcpy: %s\n\n", ea1a);
    //-------------------------------------------------------------
    //testando strcmp
    char eb1[50] = "Ola", eb2[50] = "Ola";
    printf("Testando meu_strcmp\n");
    if(meu_strcmp(eb1, eb2) == 0) printf("São iguais\n");
    printf("Testando strcmp\n");
    if(strcmp(eb1, eb2) == 0) printf("São iguais\n\n");
    //------------------------------------------------------------
    //testando strrev
    char ec1[50] = "Programar";
    printf("Testando meu_strrev\n");
    printf("Antes: %s\n", ec1);
    meu_strrev(ec1);
    printf("Depois: %s\n", ec1);
    //------------------------------------------------------------
    return 0;
}

