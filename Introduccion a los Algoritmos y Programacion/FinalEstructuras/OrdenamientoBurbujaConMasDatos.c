#include <stdio.h>


int main(){

    int Datos [10] = {10,30,42,5,26,50,60,80,56,73};
    int Kilometros [10] = {100,300,423,544,263,504,60,803,56,723};
    int Combustible [10] = {1,3,4,5,2,5,6,8,5,7};


    int aux;

    for (int i = 0; i < 9; i++)  
    {
        for (int j =  i+1 ; j < 10; j++)  
        {
            if (Datos[i] >= Datos[j])  // LA CONDICION QUE PASE VA A ORDENADOR, LOS OTROS DATOS SE ARRASTRAN CON SU INDICE. 
            {                         // (Kilometros[i] >< Kilometros[j] ...) 
                aux = Datos[i];       // BASICAMENTE KM Y COMBUSTIBLE VAN A SER ARRASTRADOS AL INDICE EN DONDE SE ACOMODE SU DATO[] EN EL ORDENAMIENTO
                Datos[i] = Datos[j];
                Datos[j] = aux;

                aux = Kilometros[i];
                Kilometros[i] = Kilometros[j];        // Es lo mismo, agrego los otros nombres.
                Kilometros[j] = aux;

                aux = Combustible[i];
                Combustible[i] = Combustible[j];
                Combustible[j] = aux;

            }
            
        }
        
    }

    // Mostrar arreglo ORDENADOR
    printf("Mostrar arreglo ORDENADO \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d \t", Datos[i]);
    }
    printf("\n");

    for (int i = 0; i < 10; i++)
    {
        printf("%d \t", Kilometros[i]);
    }
    printf("\n");

    for (int i = 0; i < 10; i++)
    {
        printf("%d \t", Combustible[i]);
    }
    printf("\n");

    return 0;
}