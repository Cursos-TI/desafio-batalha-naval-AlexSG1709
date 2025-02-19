#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

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
