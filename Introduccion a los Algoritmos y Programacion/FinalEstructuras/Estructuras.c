// Estructuras de Datos
// Es un tipo de dato mas complejo, que está formado 
// por campos
// Cada CAMPO puede ser una variable basica o comun
// Tambien puede ser un arreglo


#include <stdio.h>
#include <string.h>

typedef struct 
{
    int dni;
    float altura;
    char Nombre[20];
}Persona;


int main(){

    Persona cliente;

    // CARGANDO DATOS DE UNA A LA ESTRUCTURA
    cliente.dni = 43767679;
    cliente.altura = 1.80;
    strcpy(cliente.Nombre, "Ulises Sosa");

    printf("Cliente: %s -  %d  - %.2f \n", cliente.Nombre, cliente.dni, cliente.altura);

    // CON INGRESO DE DATOS Y ARREGLO
    
    Persona clientes[5];

    for (int i = 0; i < 1; i++)
    {
        printf("Ingrese el nombre del cliente: \n");
        fflush(stdin);
        gets(clientes[i].Nombre);
        printf("Ingrese el dni del cliente: \n");
        scanf("%d", &clientes[i].dni);
        printf("Ingrese la altura del cliente: \n");
        scanf("%f", &clientes[i].altura);
    }

    for (int i = 0; i < 1; i++)
    {
       printf("Cliente %d: %s -  %d  - %.2f \n", i+1, clientes[i].Nombre, clientes[i].dni, clientes[i].altura); 
    }
    
    return 0;
}