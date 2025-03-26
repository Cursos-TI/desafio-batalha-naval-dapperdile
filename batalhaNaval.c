#include <stdio.h>

#define TAMANHO 10
#define HABILIDADE_TAMANHO 5 // Tamanho das matrizes de habilidades

void aplicar_habilidade(int tabuleiro[TAMANHO][TAMANHO], int habilidade[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO], int origem_x, int origem_y) {
    int offset = HABILIDADE_TAMANHO / 2; // Para centralizar a matriz no ponto de origem

    for (int i = 0; i < HABILIDADE_TAMANHO; i++) {
        for (int j = 0; j < HABILIDADE_TAMANHO; j++) {
            int x = origem_x + i - offset;
            int y = origem_y + j - offset;

            // Garantir que não saímos dos limites do tabuleiro
            if (x >= 0 && x < TAMANHO && y >= 0 && y < TAMANHO) {
                // Marcar apenas se a matriz de habilidade indica 1 e a posição não contém um navio
                if (habilidade[i][j] == 1 && tabuleiro[x][y] != 3) {
                    tabuleiro[x][y] = 5;
                }
            }
        }
    }
}

void imprimir_tabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    char colunas[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; // Índices das colunas

    printf("   "); // Espaço para alinhar os números das linhas
    for (int i = 0; i < TAMANHO; i++) {
        printf("%c ", colunas[i]); // Exibir os índices das colunas
    }
    printf("\n");

    for (int i = 0; i < TAMANHO; i++) {
        printf("%2d ", i + 1); // Exibir os números das linhas
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0}; // Inicializar tabuleiro com água (0)

    // Inserindo navios
    tabuleiro[2][2] = 3; tabuleiro[3][2] = 3; tabuleiro[4][2] = 3; // Vertical
    tabuleiro[5][5] = 3; tabuleiro[5][6] = 3; tabuleiro[5][7] = 3; // Horizontal
    tabuleiro[1][1] = 3; tabuleiro[2][2] = 3; tabuleiro[3][3] = 3; // Diagonal ↘
    tabuleiro[1][8] = 3; tabuleiro[2][7] = 3; tabuleiro[3][6] = 3; // Diagonal ↙

    // Matrizes das habilidades
    int cone[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    int cruz[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };

    int octaedro[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // Aplicando habilidades em diferentes pontos
    aplicar_habilidade(tabuleiro, cone, 3, 3);
    aplicar_habilidade(tabuleiro, cruz, 5, 5);
    aplicar_habilidade(tabuleiro, octaedro, 7, 7);

    // Exibir o tabuleiro final com índices
    imprimir_tabuleiro(tabuleiro);

    return 0;
}
