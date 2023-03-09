#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINHA_A 2048
#define COLUNA_A 2048
#define LINHA_B 2048
#define COLUNA_B 2048

int main(void) {
    float **matrizA = (float**) malloc(LINHA_A*sizeof(float*));

    for(int i = 0; i < LINHA_A; i++){
        matrizA[i] = (float*) malloc(COLUNA_A*sizeof(float));
    }

    float **matrizB = (float**) malloc(LINHA_B*sizeof(float*));

    for(int i = 0; i < LINHA_B; i++){
        matrizB[i] = (float*) malloc(COLUNA_B*sizeof(float));
    }

    float **matrizRE = (float**) malloc(LINHA_A*sizeof(float*));

    for(int i = 0; i < LINHA_A; i++){
        matrizRE[i] = (float*) malloc(COLUNA_B*sizeof(float));
    }

    for(int i = 0; i < LINHA_A; i++){
        for(int j = 0; j < COLUNA_A; j++){
            matrizA[i][j] = rand() % 1000;
        }            
    }

    for(int i = 0; i < LINHA_B; i++){
        for(int j = 0; j < COLUNA_B; j++){
            matrizB[i ][j] = rand() % 1000;
            ///if(i == j)
            //    matrizB[i * COLUNA_B + j] = 1;
            //else
            //    matrizB[i * COLUNA_B + j] = 0;
        }
    }

    time_t init = time(NULL);

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
    }

    time_t fim = time(NULL);

    float time_dif = fim - init;

    printf("o tempo foi %f.0", time_dif);

    /*for(int i = 0; i < LINHA_A; i++){
        for(int j = 0; j < COLUNA_B; j++){
            printf("%f ", matrizRE[i][j]);
        }
        printf("\n");
    }*/
}