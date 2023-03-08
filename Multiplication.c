#include <stdio.h>

#define LINHA_A 3
#define COLUNA_A 3
#define LINHA_B 3
#define COLUNA_B 3

int main(void) {
    int matrizA[LINHA_A][COLUNA_B] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    int matrizB[LINHA_B][COLUNA_B] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

    int matrizRE[LINHA_A][COLUNA_B];

    if(COLUNA_A == LINHA_B){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                int e = 0;
                for(int k = 0; k < 3; k++){
                    e += matrizA[i][k] * matrizB[k][j];
                }
                matrizRE[i][j] = e;
            }
        }

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                printf("%d ", matrizRE[i][j]);
            }
            printf("\n");
        }
    }
}