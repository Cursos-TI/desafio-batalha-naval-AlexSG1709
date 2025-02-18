#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    int tabuleiro[10][10] = {0}; // Inicializa o tabuleiro com água (0)

    // Define as coordenadas dos navios (exemplo)
    int navio1_linha_inicial = 2; // Corresponde à linha 3
    int navio1_coluna_inicial = 3; // Corresponde à coluna D
    int navio2_linha_inicial = 5; // Corresponde à linha 6
    int navio2_coluna_inicial = 1; // Corresponde à coluna B

    // Posiciona o navio 1 (horizontal)
    for (int i = 0; i < 3; i++) {
        tabuleiro[navio1_linha_inicial][navio1_coluna_inicial + i] = 3; // 3 representa o navio
    }

    // Posiciona o navio 2 (vertical)
    for (int i = 0; i < 3; i++) {
        tabuleiro[navio2_linha_inicial + i][navio2_coluna_inicial] = 3; // 3 representa o navio
    }

        printf("Tabuleiro de Batalha Naval\n");

    // Exibe o tabuleiro com letras nas colunas e números nas linhas
    printf("  A B C D E F G H I J\n"); // Imprime as letras das colunas
    for (int i = 0; i < 10; i++) {
        printf("%d ", i + 1); // Imprime o número da linha (1 a 10)
        for (int j = 0; j < 10; j++) {
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
