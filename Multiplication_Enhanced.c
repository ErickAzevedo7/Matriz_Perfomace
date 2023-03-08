#include <stdio.h>
#include <stdlib.h>

#define LINHA_A 2000
#define COLUNA_A 2000
#define LINHA_B 2000
#define COLUNA_B 2000

int main(void) {
    int **matrizA = (int**) malloc(LINHA_A*sizeof(int*));

    for(int i = 0; i < LINHA_A; i++){
        matrizA[i] = (int*) malloc(COLUNA_A*sizeof(int));
    }

    int **matrizB = (int**) malloc(LINHA_A*sizeof(int*));

    for(int i = 0; i < LINHA_B; i++){
        matrizB[i] = (int*) malloc(COLUNA_B*sizeof(int));
    }

    int **matrizRE = (int**) malloc(LINHA_A*sizeof(int*));

    for(int i = 0; i < LINHA_A; i++){
        matrizRE[i] = (int*) malloc(COLUNA_B*sizeof(int));
    }

    for(int i = 0; i < LINHA_A; i++){
            for(int j = 0; j < COLUNA_A; j++){
                matrizA[i][j] = rand() % 1000;
            }            
        }

    for(int i = 0; i < LINHA_B; i++){
            for(int j = 0; j < COLUNA_B; j++){
                matrizB[i][j] = rand() % 1000;
            }
        }

    if(COLUNA_A == LINHA_B){
        for(int i = 0; i < LINHA_A; i++){
            for(int j = 0; j < COLUNA_B; j++){
                int e = 0;
                for(int k = 0; k < LINHA_A; k++){
                    e += matrizA[i][k] * matrizB[k][j];
                }
                matrizRE[i][j] = e;
            }
        }

        /*for(int i = 0; i < LINHA_A; i++){
            for(int j = 0; j < COLUNA_B; j++){
                printf("%d ", matrizRE[i][j]);
            }
            printf("\n");
        } */     
    }
}