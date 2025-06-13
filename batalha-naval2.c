/*
 * Batalha Naval - Nível Aventureiro
 * Tabuleiro 10x10 com navios horizontais, verticais e diagonais
 */

#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define AGUA 0
#define TAM_NAVIO 3

void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

int podePosicionar(int tabuleiro[TAM][TAM], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha + (direcao == 1 ? i : 0) + (diagonal == 1 ? i : 0);
        int c = coluna + (direcao == 0 ? i : 0) + (diagonal == 1 ? i : 0);
        int c2 = coluna - (diagonal == 2 ? i : 0);

        if (diagonal == 1 && (l >= TAM || c >= TAM || tabuleiro[l][c] != AGUA)) return 0;
        if (diagonal == 2 && (l >= TAM || c2 < 0 || tabuleiro[l][c2] != AGUA)) return 0;
        if (diagonal == 0 && (l >= TAM || c >= TAM || tabuleiro[l][c] != AGUA)) return 0;
    }
    return 1;
}

void posicionarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha + (direcao == 1 ? i : 0) + (diagonal == 1 ? i : 0);
        int c = coluna + (direcao == 0 ? i : 0) + (diagonal == 1 ? i : 0);
        int c2 = coluna - (diagonal == 2 ? i : 0);

        if (diagonal == 1)
            tabuleiro[l][c] = NAVIO;
        else if (diagonal == 2)
            tabuleiro[l][c2] = NAVIO;
        else
            tabuleiro[l][c] = NAVIO;
    }
}

void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nTabuleiro:\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    inicializarTabuleiro(tabuleiro);

    // Navio horizontal (linha 2, coluna 1)
    if (podePosicionar(tabuleiro, 2, 1, 0, 0)) {
        posicionarNavio(tabuleiro, 2, 1, 0, 0);
    }

    // Navio vertical (linha 0, coluna 7)
    if (podePosicionar(tabuleiro, 0, 7, 1, 0)) {
        posicionarNavio(tabuleiro, 0, 7, 1, 0);
    }

    // Navio diagonal \ (linha 5, coluna 0)
    if (podePosicionar(tabuleiro, 5, 0, 0, 1)) {
        posicionarNavio(tabuleiro, 5, 0, 0, 1);
    }

    // Navio diagonal / (linha 0, coluna 9)
    if (podePosicionar(tabuleiro, 0, 9, 0, 2)) {
        posicionarNavio(tabuleiro, 0, 9, 0, 2);
    }

    exibirTabuleiro(tabuleiro);

    return 0;
}

