#include <stdio.h>
#include <stdlib.h>

int main() {
    int opcao;

    do {
        printf("\n1- Copiar arquivo\n2- Comparar arquivos\n3- Mostrar N linhas\n4- Sair\nOpcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            char orig[100], dest[100], buffer[512];
            FILE *f1, *f2;
            int lidos;

            printf("Arquivo origem: ");
            scanf("%s", orig);
            printf("Arquivo destino: ");
            scanf("%s", dest);

            f1 = fopen(orig, "rb");
            f2 = fopen(dest, "wb");

            if (f1 && f2) {
                while ((lidos = fread(buffer, 1, sizeof(buffer), f1)) > 0) {
                    fwrite(buffer, 1, lidos, f2);
                }
                printf("Copiado com sucesso!\n");
                fclose(f1);
                fclose(f2);
            } else {
                printf("Erro ao abrir arquivos.\n");
            }
        } 
        else if (opcao == 2) {
            char arq1[100], arq2[100];
            FILE *f1, *f2;
            int c1, c2, pos = 0, igual = 1;

            printf("Arquivo 1: ");
            scanf("%s", arq1);
            printf("Arquivo 2: ");
            scanf("%s", arq2);

            f1 = fopen(arq1, "rb");
            f2 = fopen(arq2, "rb");

            if (f1 && f2) {
                while (1) {
                    c1 = fgetc(f1);
                    c2 = fgetc(f2);

                    if (c1 != c2) {
                        igual = 0;
                        break;
                    }
                    if (c1 == EOF) break; // Chegou ao fim de ambos juntos
                    pos++;
                }

                if (igual) printf("Arquivos sao identicos.\n");
                else printf("Diferentes na posicao (byte): %d\n", pos);

                fclose(f1);
                fclose(f2);
            } else {
                printf("Erro ao abrir arquivos.\n");
            }
        } 
        else if (opcao == 3) {
            char arq[100], linha[256];
            FILE *f;
            int n, cont = 0;

            printf("Arquivo texto: ");
            scanf("%s", arq);
            printf("Numero de linhas: ");
            scanf("%d", &n);

            f = fopen(arq, "r");
            if (f) {
                printf("\n--- Exibindo %d linhas ---\n", n);
                while (cont < n && fgets(linha, sizeof(linha), f) != NULL) {
                    printf("%s", linha);
                    cont++;
                }
                fclose(f);
            } else {
                printf("Erro ao abrir arquivo.\n");
            }
        }

    } while (opcao != 4);

    printf("Saindo...\n");
    return 0;
}