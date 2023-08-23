
#include <stdio.h>


int main(){

    int Datos [10] = {10,30,42,5,26,50,60,80,56,73};


    // Mostrar arreglo DESORDENADO
    printf("Mostrar arreglo DESORDENADO \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d \t", Datos[i]);
    }
    printf("\n");
    

    // Ordenamiento del Arreglo CON METODO BURBUJA
    int aux;
    for (int i = 0; i < 9; i++)  // MENOR QUE 9, XQ TENGO QUE COMPARAR CONTRA TODOS MENOS EL ULTIMO
    {
        for (int j =  i+1 ; j < 10; j++)  // J TOMA EL VALOR DE I+1 , Y EL TAMAÑO DE TODO EL ARREGLO
        {
            if (Datos[i] > Datos[j])  // > ascendente
            {                         // < descendente
                aux = Datos[i];
                Datos[i] = Datos[j];
                Datos[j] = aux;

            }
            
        }
        
    }

    // Mostrar arreglo ORDENADOR
    printf("Mostrar arreglo ORDENADO \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d \t", Datos[i]);
    }
    

    return 0;
}