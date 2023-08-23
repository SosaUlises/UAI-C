#include <stdio.h>

#define FI 3
#define CO 4

int main(){

    // Cargar notas de materias en una Matriz ( Filas - Columnas )


    float nota;
    float matriz[FI][CO];

    for(int i = 0; i < FI; i++){

        for(int j = 0; j < CO; j++){

            do{
                printf("Ingrese la nota %d: \n", i+1);
                scanf("%f", &nota);
            }while(nota < 1 || nota > 10);
        
        matriz[i][j] = nota;
        }
    }

    // Mostrar los datos por fila y columna

    for (int i = 0; i < FI; i++){
        for(int j = 0; j < CO; j++){
            printf("Fila %d Columna %d : %.2f \n", i,j,matriz[i][j]);
        }
    }

    return 0;
}