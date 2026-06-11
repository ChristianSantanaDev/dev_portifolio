/*
Exercício 3 — Conversão de temperatura em lote
Implemente as funções:
1 float celsiusParaFahrenheit ( float c );
2 float fahrenheitParaCelsius ( float f );
3 void converterLote ( float vet [] , int n , char origem );
converterLote() deve percorrer o vetor e converter cada elemento no próprio lugar 
(passagem implícita por ponteiro de array). O parâmetro origem indica ’C’
(Celsius) ou ’F’ (Fahrenheit). No main(), demonstre com um vetor de 5 temperaturas lidas do teclado.
*/

#include<stdio.h>
#include<string.h>

float celsiusParaFahrenheit ( float c );
float fahrenheitParaCelsius ( float f );
void converterLote ( float vet [] , int n , char origem );

int main(void){
    float vet_temp[5];
    int i = 0;

    while(i < 5){
        printf("Digite a temp_vet[%d] => ", i);
        scanf("%f", &vet_temp[i]);
        i++;
    }

    converterLote(vet_temp, 5, 'C');

    printf("Temperaturas em C convertidas para F\n");
    i = 0;
    while(i < 5){
        printf("%.2f\n", vet_temp[i]);
        i++;
    }

    return 0;
}

float celsiusParaFahrenheit ( float c ){
    return c * (9.0/5.0) + 32.0;
}

float fahrenheitParaCelsius ( float f ){
    return (5.0/9.0) * (f - 32.0);
}

void converterLote ( float vet [] , int n , char origem ){
    if(origem =='C') {
        //converter vetor para F
        for(int i=0;i<n;i++){
            vet[i] = celsiusParaFahrenheit(vet[i]);
        }

    } else if(origem == 'F') {
        //converter vetor para C
        for(int i=0;i<n;i++){
            vet[i] = fahrenheitParaCelsius(vet[i]);
        }
    }
}
