#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    int tabuleiro[10][10];
    char indices_colunas[10] = {'A', 'B', 'C', 'D','E','F','G','H','I','J'};
    int pos_inicial_vertical[2] = {0,0};
    int pos_inicial_horizontal[2] = {0,2};

   // preenche o tabuleiro
   int count_v=0, count_h=0;
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            if (i==pos_inicial_vertical[0] && j==pos_inicial_vertical[1]){
                
                tabuleiro[i][j] = 3;
                count_v++;
                if (count_v >= 3){
                    continue;
                }
                pos_inicial_vertical[0]++;
                
            }else if (i==pos_inicial_horizontal[0] && j==pos_inicial_horizontal[1]){
                tabuleiro[i][j] = 3;
                count_h++;
                if(count_h >= 3){
                    continue;
                }
                pos_inicial_horizontal[1]++;
            }else{
                tabuleiro[i][j] = 0;
            }
        }
    }

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.
    int pos_inicial_diag1[2] = {1,2};
    int pos_inicial_diag2[2] = {1,4};
    int count_d1=0, count_d2=0;
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            if (i==pos_inicial_diag1[0] && j==pos_inicial_diag1[1]){
                
                tabuleiro[i][j] = 3;
                count_d1++;
                if (count_d1 >= 3){
                    continue;
                }
                pos_inicial_diag1[0]++;
                pos_inicial_diag1[1]++;
                
            }else if (i==pos_inicial_diag2[0] && j==pos_inicial_diag2[1]){
                tabuleiro[i][j] = 3;
                count_d2++;
                if(count_d2 >= 3){
                    continue;
                }
                pos_inicial_diag2[1]++;
                pos_inicial_diag2[0]++;
            }else if (tabuleiro[i][j] != 3){
                tabuleiro[i][j] = 0;
            }
        }
    }

        // imprime os indices das colunas
        printf("   ");
        for (int i=0; i<10; i++){
            printf("%c ", indices_colunas[i]);
        }
        printf("\n ");
        for (int i=0; i<7; i++){
            printf("---");
        }
        // imprime o tabuleiro
        for (int i=0; i<10; i++){
            printf("\n%d| ", i);
            for(int j=0; j<10; j++){
                printf("%d ", tabuleiro[i][j]);
            }
            printf("\n");
        }

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    int matriz[3][5] = {0};
    for (int i = 0; i < 3; i++) {
        // Calcula o número de 1's na linha atual
        int num_uns = 2 * i + 1;

        // Calcula o índice inicial para centralizar os 1's
        int inicio = (5 - num_uns) / 2;

        // Preenche os 1's na linha atual
        for (int j = inicio; j < inicio + num_uns; j++) {
            matriz[i][j] = 1;
        }
    }

    // imprime matriz
    printf("Pirâmide:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0
    int matriz2[3][3] = {0};
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if(i==0 && j==1){
                matriz2[i][j] = 1;
            }
            if(i==1){
                matriz2[i][j] = 1;
            }
            if(i==2 && j==1){
                matriz2[i][j] = 1;
            }
        }
    }


    // imprime matriz
    printf("Octaedro:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz2[i][j]);
        }
        printf("\n");
    }

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0
    int meio = 5/2;
    int matriz3[5][5] = {0};
    // preencher com 1 a linha e coluna do meio
    for (int i=0; i<5; i++){
        matriz3[meio][i] = 1;
        matriz3[i][meio] = 1;
    }

    // imprime matriz
    printf("Cruz:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", matriz3[i][j]);
        }
        printf("\n");
    }

    return 0;
}
