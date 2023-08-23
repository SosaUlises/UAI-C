#include <stdio.h>
#include <string.h>


int main(){

    char Nombre[20];

    printf("Ingrese una cadena de caracteres: \n");
    gets(Nombre);
    printf("La cadena ingresada es %s \n", Nombre);

    // Mostrar por caracter individual
    int longitud = strlen(Nombre);

    for(int i=0; i < longitud; i++){
        printf(" %c \t", Nombre[i]);
    }

    return 0;
}