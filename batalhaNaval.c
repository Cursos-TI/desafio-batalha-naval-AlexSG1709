#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

void exibirTabuleiro(int tabuleiro[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (tabuleiro[i][j] == 0) {
                printf("0 ");  // Água
            } else if (tabuleiro[i][j] == 3) {
                printf("3 ");  // Navio
            } else if (tabuleiro[i][j] == 5) {
                printf("5 ");  // Área afetada pela habilidade
            }
        }
        printf("\n");
    }
}

// Função para aplicar a habilidade Cone
void aplicarCone(int tabuleiro[10][10], int x, int y, int tamanho) {
    int cone[tamanho][tamanho]; // Matriz de cone

    // Preencher a matriz de cone com a forma de cone (1 = área afetada)
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j <= i; j++) {
            cone[i][j] = 1; // Áreas afetadas pelo cone
        }
    }

    // Sobrepor a matriz de cone no tabuleiro
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j <= i; j++) {
            int cx = x + i; // Coordenada X no tabuleiro
            int cy = y + j; // Coordenada Y no tabuleiro

            // Verificar se a coordenada está dentro do tabuleiro
            if (cx >= 0 && cx < 10 && cy >= 0 && cy < 10 && cone[i][j] == 1) {
                tabuleiro[cx][cy] = 5; // Marca a área afetada
            }
        }
    }
}

// Função para aplicar a habilidade Cruz
void aplicarCruz(int tabuleiro[10][10], int x, int y, int tamanho) {
    int cruz[tamanho][tamanho]; // Matriz de cruz

    // Preencher a matriz de cruz (1 = área afetada)
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (i == tamanho / 2 || j == tamanho / 2) {
                cruz[i][j] = 1; // Áreas afetadas pela cruz
            } else {
                cruz[i][j] = 0;
            }
        }
    }

    // Sobrepor a matriz de cruz no tabuleiro
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            int cx = x + i - tamanho / 2; // Coordenada X no tabuleiro
            int cy = y + j - tamanho / 2; // Coordenada Y no tabuleiro

            // Verificar se a coordenada está dentro do tabuleiro
            if (cx >= 0 && cx < 10 && cy >= 0 && cy < 10 && cruz[i][j] == 1) {
                tabuleiro[cx][cy] = 5; // Marca a área afetada
            }
        }
    }
}

// Função para aplicar a habilidade Octaedro
void aplicarOctaedro(int tabuleiro[10][10], int x, int y, int tamanho) {
    int octaedro[tamanho][tamanho]; // Matriz de octaedro

    // Preencher a matriz de octaedro (1 = área afetada)
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (i + j >= tamanho / 2 && j - i <= tamanho / 2) {
                octaedro[i][j] = 1; // Áreas afetadas pelo octaedro
            } else {
                octaedro[i][j] = 0;
            }
        }
    }

    // Sobrepor a matriz de octaedro no tabuleiro
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            int cx = x + i - tamanho / 2; // Coordenada X no tabuleiro
            int cy = y + j - tamanho / 2; // Coordenada Y no tabuleiro

            // Verificar se a coordenada está dentro do tabuleiro
            if (cx >= 0 && cx < 10 && cy >= 0 && cy < 10 && octaedro[i][j] == 1) {
                tabuleiro[cx][cy] = 5; // Marca a área afetada
            }
        }
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0}; // 0 = água, 3 = navio

    // Navio 1 (horizontal)
    int navio1_linha = 2;
    int navio1_coluna = 3;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[navio1_linha][navio1_coluna + i] = 3;
    }

    // Navio 2 (vertical)
    int navio2_linha = 5;
    int navio2_coluna = 1;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[navio2_linha + i][navio2_coluna] = 3;
    }

    // Navio 3 (diagonal principal)
    int navio3_linha = 7;
    int navio3_coluna = 7;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[navio3_linha + i][navio3_coluna + i] = 3;
    }

    // Navio 4 (diagonal secundária)
    int navio4_linha = 1;
    int navio4_coluna = 8;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[navio4_linha + i][navio4_coluna - i] = 3;
    }

    printf("TABULEIRO DE BATALHA NAVAL\n");
    // Exibição do tabuleiro
    printf("  A B C D E F G H I J\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
// Aplicar habilidades no tabuleiro
aplicarCone(tabuleiro, 1, 2, 5);      // Habilidade Cone
aplicarCruz(tabuleiro, 4, 3, 5);      // Habilidade Cruz
aplicarOctaedro(tabuleiro, 7, 7, 5);  // Habilidade Octaedro

// Exibir o tabuleiro após aplicar as habilidades
printf("Tabuleiro com habilidades:\n");
exibirTabuleiro(tabuleiro);

    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
