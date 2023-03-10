#include <stdio.h>
#include <stdlib.h>

#define LINHA 50000
#define COLUNA 50000

int main(){
    float** matriz = (float**) malloc(LINHA*sizeof(float*));

    for(int i = 0; i < LINHA; i++){
        matriz[i] = (float*) malloc(COLUNA*sizeof(float));
    }

    for(int i = 0; i < LINHA; i++){
        for(int j = 0; j < COLUNA; j++){
            if(i == j)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }

    for(int i = 0; i < LINHA; i++){
        for(int j = 0; j < COLUNA; j++){
            if(i == j){
                if(matriz[i][j] != 1)
                    printf("Erro");
            }
            else{
                if(matriz[i][j] != 0)
                    printf("Erro");
            }
        }
    }
    printf("\n");

   /*for(int i = 0; i < LINHA; i++){
        for(int j = 0; j < COLUNA; j++){
            printf("%.0f", matriz[i][j]);
        }
        printf("\n");
    }*/ 
}