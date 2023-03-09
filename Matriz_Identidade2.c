#include <stdio.h>
#include <stdlib.h>

#define LINHA 3
#define COLUNA 3

int main(){
    float** matriz = (float**) malloc(LINHA*sizeof(float*));

    for(int i = 0; i < LINHA; i++){
        matriz[i] = (float*) malloc(COLUNA*sizeof(float));
    }

    for(int i = 0; i < LINHA; i++){
        for(int j = 0; j < COLUNA; j++){

        }
    }

    int cont = 0;
    for(int i = 0; i < LINHA; i++){
        for(int j = 0; j < COLUNA; j++){
            cont += matriz[i][j];
        }
        if(cont != 1)
            printf("Erro");
        cont = 0;
    }
    printf("\n");

   /*for(int i = 0; i < LINHA; i++){
        for(int j = 0; j < COLUNA; j++){
            printf("%.0f", matriz[i][j]);
        }
        printf("\n");
    }*/ 
}