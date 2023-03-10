#include <stdio.h>
#include <stdlib.h>
#include <immintrin.h>
#include <time.h>

#define LINHA_A 1500
#define COLUNA_A 1500
#define LINHA_B 1500
#define COLUNA_B 1500

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

    time_t init = time(NULL);

    if(COLUNA_A == LINHA_B){
        for(int i = 0; i < LINHA_A; i++){
            for(int j = 0; j < COLUNA_B; j += 128){
                __m256 m0 = _mm256_setzero_ps();
                __m256 m1 = _mm256_setzero_ps();
                __m256 m2 = _mm256_setzero_ps();
                __m256 m3 = _mm256_setzero_ps();
                __m256 m4 = _mm256_setzero_ps();
                __m256 m5 = _mm256_setzero_ps();
                __m256 m6 = _mm256_setzero_ps();
                __m256 m7 = _mm256_setzero_ps();
                __m256 m8 = _mm256_setzero_ps();
                __m256 m9 = _mm256_setzero_ps();
                __m256 m10 = _mm256_setzero_ps();
                __m256 m11 = _mm256_setzero_ps();
                __m256 m12 = _mm256_setzero_ps();
                __m256 m13 = _mm256_setzero_ps();
                __m256 m14 = _mm256_setzero_ps();
                __m256 m15 = _mm256_setzero_ps();

                for(int k = 0; k < LINHA_A; k++){
                    __m256 A1 = _mm256_broadcast_ss(matrizA + (i * LINHA_A) + k);
                    __m256 A2 = _mm256_broadcast_ss(matrizA + (i * LINHA_A) + k);
                    __m256 A3 = _mm256_broadcast_ss(matrizA + (i * LINHA_A) + k);
                    __m256 A4 = _mm256_broadcast_ss(matrizA + (i * LINHA_A) + k);
                    __m256 A5 = _mm256_broadcast_ss(matrizA + (i * LINHA_A) + k);
                    __m256 A6 = _mm256_broadcast_ss(matrizA + (i * LINHA_A) + k);
                    __m256 A7 = _mm256_broadcast_ss(matrizA + (i * LINHA_A) + k);
                    __m256 A8 = _mm256_broadcast_ss(matrizA + (i * LINHA_A) + k);
                    __m256 A9 = _mm256_broadcast_ss(matrizA + (i * LINHA_A) + k);
                    __m256 A10 = _mm256_broadcast_ss(matrizA + (i * LINHA_A) + k);
                    __m256 A11 = _mm256_broadcast_ss(matrizA + (i * LINHA_A) + k);
                    __m256 A12 = _mm256_broadcast_ss(matrizA + (i * LINHA_A) + k);
                    __m256 A13 = _mm256_broadcast_ss(matrizA + (i * LINHA_A) + k);
                    __m256 A14 = _mm256_broadcast_ss(matrizA + (i * LINHA_A) + k);
                    __m256 A15 = _mm256_broadcast_ss(matrizA + (i * LINHA_A) + k);
                    __m256 A16 = _mm256_broadcast_ss(matrizA + (i * LINHA_A) + k);

                    __m256 B1 = _mm256_load_ps(matrizB + (k * COLUNA_B) + j);
                    __m256 B2 = _mm256_load_ps(matrizB + (k * COLUNA_B) + j + 8);
                    __m256 B3 = _mm256_load_ps(matrizB + (k * COLUNA_B) + j + 16);
                    __m256 B4 = _mm256_load_ps(matrizB + (k * COLUNA_B) + j + 24);
                    __m256 B5 = _mm256_load_ps(matrizB + (k * COLUNA_B) + j + 32);
                    __m256 B6 = _mm256_load_ps(matrizB + (k * COLUNA_B) + j + 40);
                    __m256 B7 = _mm256_load_ps(matrizB + (k * COLUNA_B) + j + 48);
                    __m256 B8 = _mm256_load_ps(matrizB + (k * COLUNA_B) + j + 56);
                    __m256 B9 = _mm256_load_ps(matrizB + (k * COLUNA_B) + j + 64);
                    __m256 B10 = _mm256_load_ps(matrizB + (k * COLUNA_B) + j + 72);
                    __m256 B11 = _mm256_load_ps(matrizB + (k * COLUNA_B) + j + 80);
                    __m256 B12 = _mm256_load_ps(matrizB + (k * COLUNA_B) + j + 88);
                    __m256 B13 = _mm256_load_ps(matrizB + (k * COLUNA_B) + j + 96);
                    __m256 B14 = _mm256_load_ps(matrizB + (k * COLUNA_B) + j + 104);
                    __m256 B15 = _mm256_load_ps(matrizB + (k * COLUNA_B) + j + 112);
                    __m256 B16 = _mm256_load_ps(matrizB + (k * COLUNA_B) + j + 120);


                    __m256 S1 = _mm256_mul_ps(A1, B1);
                    __m256 S2 = _mm256_mul_ps(A2, B2);
                    __m256 S3 = _mm256_mul_ps(A3, B3);
                    __m256 S4 = _mm256_mul_ps(A4, B4);
                    __m256 S5 = _mm256_mul_ps(A5, B5);
                    __m256 S6 = _mm256_mul_ps(A6, B6);
                    __m256 S7 = _mm256_mul_ps(A7, B7);
                    __m256 S8 = _mm256_mul_ps(A8, B8);
                    __m256 S9 = _mm256_mul_ps(A9, B9);
                    __m256 S10 = _mm256_mul_ps(A10, B10);
                    __m256 S11 = _mm256_mul_ps(A11, B11);
                    __m256 S12 = _mm256_mul_ps(A12, B12);
                    __m256 S13 = _mm256_mul_ps(A13, B13);
                    __m256 S14 = _mm256_mul_ps(A14, B14);
                    __m256 S15 = _mm256_mul_ps(A15, B15);
                    __m256 S16 = _mm256_mul_ps(A16, B16);

                    m0 = _mm256_add_ps(m0, S1);
                    m1 = _mm256_add_ps(m1, S2);
                    m2 = _mm256_add_ps(m2, S3);
                    m3 = _mm256_add_ps(m3, S4);
                    m4 = _mm256_add_ps(m4, S5);
                    m5 = _mm256_add_ps(m5, S6);
                    m6 = _mm256_add_ps(m6, S7);
                    m7 = _mm256_add_ps(m7, S8);
                    m8 = _mm256_add_ps(m8, S9);
                    m9 = _mm256_add_ps(m9, S10);
                    m10 = _mm256_add_ps(m10, S11);
                    m11 = _mm256_add_ps(m11, S12);
                    m12 = _mm256_add_ps(m12, S13);
                    m13 = _mm256_add_ps(m13, S14);
                    m14 = _mm256_add_ps(m14, S15);
                    m15 = _mm256_add_ps(m15, S16);
                    //e += matrizA[i][k] * matrizB[k][j];
                }
                _mm256_store_ps(matrizRE + (i * LINHA_A) + j, m0);
                _mm256_store_ps(matrizRE + (i * LINHA_A) + j + 8, m1);
                _mm256_store_ps(matrizRE + (i * LINHA_A) + j + 16, m2);
                _mm256_store_ps(matrizRE + (i * LINHA_A) + j + 24, m3);
                _mm256_store_ps(matrizRE + (i * LINHA_A) + j + 32, m4);
                _mm256_store_ps(matrizRE + (i * LINHA_A) + j + 40, m5);
                _mm256_store_ps(matrizRE + (i * LINHA_A) + j + 48, m6);
                _mm256_store_ps(matrizRE + (i * LINHA_A) + j + 56, m7);
                _mm256_store_ps(matrizRE + (i * LINHA_A) + j + 64, m0);
                _mm256_store_ps(matrizRE + (i * LINHA_A) + j + 72, m1);
                _mm256_store_ps(matrizRE + (i * LINHA_A) + j + 80, m2);
                _mm256_store_ps(matrizRE + (i * LINHA_A) + j + 88, m3);
                _mm256_store_ps(matrizRE + (i * LINHA_A) + j + 96, m4);
                _mm256_store_ps(matrizRE + (i * LINHA_A) + j + 104, m5);
                _mm256_store_ps(matrizRE + (i * LINHA_A) + j + 112, m6);
                _mm256_store_ps(matrizRE + (i * LINHA_A) + j + 120, m7);
                //matrizRE[i][j] = e;
            }
        }
    }
    time_t fim = time(NULL);

    float time_dif = fim - init;

    printf("o tempo foi %f\n", time_dif);

    /*for(int i = 0; i < LINHA_A; i++){
        for(int j = 0; j < COLUNA_B; j++){
            printf("%f ", matrizRE[i * COLUNA_B + j]);
        }
        printf("\n");
    }*/

    return 0;
}