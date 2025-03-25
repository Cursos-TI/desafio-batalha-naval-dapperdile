#include <stdio.h>

int main() {
    int board[10][10] = {0}; // Criado o campo

    // Print das colunas (A-J)
    printf("   "); // Espaço para os simbulos
    for (char c = 'A'; c <= 'J'; c++) {
        printf("%c ", c); // Exibe letras das colunas
    }
    printf("\n");

    // Print do separador
    printf("  ");
    for (int i = 0; i < 10; i++) {
        printf("--");
    }
    printf("\n");

    // Print dos numeros das linhas (0-9)
    for (int i = 0; i < 10; i++) {
        printf("%d | ", i);
        // Loop para preencher a posição dos navios
        for (int j = 0; j < 10; j++) {
            if (i == 3&&(j>2&&j<6))
            {
                printf("3 ");
            }
            else if ((i>5&&i<9)&&j==8)
            {
                printf("3 ");
            }
            else if (i==j&&(i>3&&i<7))
            {
                printf("3 ");
            }
            else { printf("0 ");}
        }
        printf("\n");
    }

    return 0;
}
