#include <stdio.h>
#include <stdlib.h>
#include <intrin.h>

#define LINHA_A 2000
#define COLUNA_A 2000
#define LINHA_B 2000
#define COLUNA_B 2000

int main(void) {
    int **matrizA = (int**) _aligned_malloc(LINHA_A*sizeof(int*), 32);

    for(int i = 0; i < LINHA_A; i++){
        matrizA[i] = (int*) _aligned_malloc(COLUNA_A*sizeof(int), 32);
    }

    int **matrizB = (int**) _aligned_malloc(LINHA_A*sizeof(int*), 32);

    for(int i = 0; i < LINHA_B; i++){
        matrizB[i] = (int*) _aligned_malloc(COLUNA_B*sizeof(int), 32);
    }

    int **matrizRE = (int**) _aligned_malloc(LINHA_A*sizeof(int*), 32);

    for(int i = 0; i < LINHA_A; i++){
        matrizRE[i] = (int*) _aligned_malloc(COLUNA_B*sizeof(int), 32);
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
                __m256 m0 = _mm256_setzero_ps();
                for(int k = 0; k < LINHA_A; k++){
                    __m256 m1 = _mm256_broadcast_ss(matrizA + i * LINHA_A + k);
                    __m256 m2 = _mm256_load_ps(matrizB + k * COLUNA_B + j);
                    __m256 m3 = _mm256_mul_ps(m1, m2);
                    m0 = __m256_add_ps(m0, m3);
                    //e += matrizA[i][k] * matrizB[k][j];
                }
                _mm256_store_ps(matrizRE + i * LINHA_A + j, m0);
                //matrizRE[i][j] = e;
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