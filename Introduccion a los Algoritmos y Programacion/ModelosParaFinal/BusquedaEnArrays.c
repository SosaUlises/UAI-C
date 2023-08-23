#include <stdio.h>

int buscar(int Datos[]);

int main()
{

    int Datos[10] = {10, 30, 42, 5, 26, 50, 60, 80, 56, 73};
    int k;

    k = buscar(Datos);
    if(k == 10){
        printf("No se encontro el numero buscado \n");
    }else{
        printf("Si se encontro el numero, en el indice %d \n", k);
    }

    return 0;
}

int buscar(int Datos[]){
    int i = 0;
    int valor;
    printf("Ingrese el numero a buscar: \n");
    scanf("%d", &valor);

    while (Datos[i] != valor && i < 10)
    {
        i++;
    }
    
    return i;
}