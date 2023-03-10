#include <stdio.h>
#include <immintrin.h>

#define LINHA 50000
#define COLUNA 50000

int main(){
    float** matriz = (float**) _aligned_malloc(LINHA*sizeof(float*), 32);

    for(int i = 0; i < LINHA; i++){
        matriz[i] = (float*) _aligned_malloc(COLUNA*sizeof(float), 32);
    }

    for(int i = 0; i < LINHA; i++){
        for(int j = 0; j < COLUNA; j++){
            if(i == j){
                matriz[i][j] = 1;
            }
            else
                matriz[i][j] = 0;
        }
    }

    for(int i = 0; i < LINHA; i++){
        int cont = 0;
        for(int j = 0; j < COLUNA; j++){
            if(i == j){
                if(matriz[i][j] != 1)
                    printf("Erro");
            }
            cont += matriz[i][j];
        }
        if(cont != 1)
            printf("Erro");
    }
    printf("\n");

   /*for(int i = 0; i < LINHA; i++){
        for(int j = 0; j < COLUNA; j++){
            printf("%.0f", matriz[i][j]);
        }
        printf("\n");
    }*/
}