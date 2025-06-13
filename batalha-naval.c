#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define VALOR_AGUA 0
#define VALOR_NAVIO 3

// Função para inicializar o tabuleiro com 0 (água)
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = VALOR_AGUA;
        }
    }
}

// Função para verificar se é possível posicionar o navio
int podePosicionar(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, char orientacao) {
    if (orientacao == 'H') {
        // Verifica se o navio ultrapassa os limites
        if (coluna + TAM_NAVIO > TAM_TABULEIRO) return 0;

        // Verifica sobreposição
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha][coluna + i] != VALOR_AGUA) return 0;
        }
    } else if (orientacao == 'V') {
        if (linha + TAM_NAVIO > TAM_TABULEIRO) return 0;

        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna] != VALOR_AGUA) return 0;
        }
    }

    return 1;
}

// Função para posicionar o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, char orientacao) {
    if (podePosicionar(tabuleiro, linha, coluna, orientacao)) {
        if (orientacao == 'H') {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linha][coluna + i] = VALOR_NAVIO;
            }
        } else if (orientacao == 'V') {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linha + i][coluna] = VALOR_NAVIO;
            }
        }
    } else {
        printf("Erro: Não foi possível posicionar o navio em [%d][%d] na orientação %c\n", linha, coluna, orientacao);
    }
}

// Função para exibir o tabuleiro na tela
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("\n--- Tabuleiro Batalha Naval ---\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializa o tabuleiro com 0
    inicializarTabuleiro(tabuleiro);

    // Posições iniciais dos navios (linha, coluna)
    int linhaNavioH = 2, colunaNavioH = 4; // Horizontal
    int linhaNavioV = 5, colunaNavioV = 7; // Vertical

    // Posiciona navios
    posicionarNavio(tabuleiro, linhaNavioH, colunaNavioH, 'H');
    posicionarNavio(tabuleiro, linhaNavioV, colunaNavioV, 'V');

    // Exibe o tabuleiro com os navios
    exibirTabuleiro(tabuleiro);

    return 0;
}