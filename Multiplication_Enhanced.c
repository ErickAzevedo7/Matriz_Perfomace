#include <stdio.h>
#include <stdlib.h>
#include <intrin.h>

#define LINHA_A 3
#define COLUNA_A 3
#define LINHA_B 3
#define COLUNA_B 3

int main(void) {
    float *matrizA = (float*) _aligned_malloc(LINHA_A*COLUNA_A*sizeof(float), 32);

    /*for(int i = 0; i < LINHA_A; i++){
        matrizA[i] = (float*) _aligned_malloc(COLUNA_A*sizeof(float), 32);
    }*/

    float *matrizB = (float*) _aligned_malloc(LINHA_B*COLUNA_B*sizeof(float), 32);

    /*for(int i = 0; i < LINHA_B; i++){
        matrizB[i] = (float*) _aligned_malloc(COLUNA_B*sizeof(float), 32);
    }*/

    float *matrizRE = (float*) _aligned_malloc(LINHA_A*COLUNA_B*sizeof(float), 32);

    /*for(int i = 0; i < LINHA_A; i++){
        matrizRE[i] = (float*) _aligned_malloc(COLUNA_B*sizeof(float), 32);
    }*/

    for(int i = 0; i < LINHA_A; i++){
            for(int j = 0; j < COLUNA_A; j++){
                matrizA[i * COLUNA_A + j] = rand() % 1000;
            }            
        }

    for(int i = 0; i < LINHA_B; i++){
            for(int j = 0; j < COLUNA_B; j++){
                matrizB[i * COLUNA_B + j] = rand() % 1000;
            }
        }

    if(COLUNA_A == LINHA_B){
        for(int i = 0; i < LINHA_A; i++){
            for(int j = 0; j < COLUNA_B; j++){
                __m256 m0 = _mm256_setzero_ps();
                for(int k = 0; k < LINHA_A; k++){
                    __m256 m1 = _mm256_broadcast_ss(matrizA + (i * LINHA_A) + k);
                    __m256 m2 = _mm256_broadcast_ss(matrizB + (k * COLUNA_B) + j);
                    __m256 m3 = _mm256_mul_ps(m1, m2);
                    m0 = _mm256_add_ps(m0, m3);
                    //e += matrizA[i][k] * matrizB[k][j];
                }
                _mm256_store_ps(matrizRE + (i * LINHA_A) + j, m0);
                //matrizRE[i][j] = e;
            }
        }
    }

    for(int i = 0; i < LINHA_A; i++){
        for(int j = 0; j < COLUNA_B; j++){
            printf("%f ", matrizA[i * COLUNA_B + j]);
        }
        printf("\n");
    } 

    return 0;
}