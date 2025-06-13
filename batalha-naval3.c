// Batalha Naval com Habilidades Especiais - Nível Mestre
// Posicionamento de navios e sobreposição de áreas de habilidade

#include <stdio.h>
#define TAM 10

void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

void posicionarNavioHorizontal(int tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int i = 0; i < 3; i++) {
        if (coluna + i < TAM) {
            tabuleiro[linha][coluna + i] = 3;
        }
    }
}

void posicionarNavioVertical(int tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int i = 0; i < 3; i++) {
        if (linha + i < TAM) {
            tabuleiro[linha + i][coluna] = 3;
        }
    }
}

void posicionarNavioDiagonalPrincipal(int tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int i = 0; i < 3; i++) {
        if (linha + i < TAM && coluna + i < TAM) {
            tabuleiro[linha + i][coluna + i] = 3;
        }
    }
}

void posicionarNavioDiagonalSecundaria(int tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int i = 0; i < 3; i++) {
        if (linha + i < TAM && coluna - i >= 0) {
            tabuleiro[linha + i][coluna - i] = 3;
        }
    }
}

void aplicarHabilidade(int tabuleiro[TAM][TAM], int origem_x, int origem_y, int habilidade[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int linha = origem_x - 2 + i;
            int coluna = origem_y - 2 + j;
            if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM && habilidade[i][j] == 1 && tabuleiro[linha][coluna] == 0) {
                tabuleiro[linha][coluna] = 5;
            }
        }
    }
}

void construirMatrizCone(int matriz[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matriz[i][j] = 0;
        }
    }
    matriz[0][2] = 1;
    for (int j = 1; j <= 3; j++) matriz[1][j] = 1;
    for (int j = 0; j <= 4; j++) matriz[2][j] = 1;
}

void construirMatrizCruz(int matriz[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matriz[i][j] = (i == 2 || j == 2) ? 1 : 0;
        }
    }
}

void construirMatrizOctaedro(int matriz[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matriz[i][j] = 0;
        }
    }
    matriz[0][2] = 1;
    matriz[1][1] = matriz[1][2] = matriz[1][3] = 1;
    matriz[2][0] = matriz[2][1] = matriz[2][2] = matriz[2][3] = matriz[2][4] = 1;
    matriz[3][1] = matriz[3][2] = matriz[3][3] = 1;
    matriz[4][2] = 1;
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
    int cone[5][5], cruz[5][5], octaedro[5][5];

    inicializarTabuleiro(tabuleiro);

    posicionarNavioHorizontal(tabuleiro, 0, 0);
    posicionarNavioVertical(tabuleiro, 2, 2);
    posicionarNavioDiagonalPrincipal(tabuleiro, 4, 4);
    posicionarNavioDiagonalSecundaria(tabuleiro, 6, 6);

    construirMatrizCone(cone);
    construirMatrizCruz(cruz);
    construirMatrizOctaedro(octaedro);

    aplicarHabilidade(tabuleiro, 5, 2, cone);
    aplicarHabilidade(tabuleiro, 3, 7, cruz);
    aplicarHabilidade(tabuleiro, 8, 8, octaedro);

    exibirTabuleiro(tabuleiro);

    return 0;
}

