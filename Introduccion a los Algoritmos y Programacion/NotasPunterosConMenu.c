#include <stdio.h>

int menu();
void seleccion(int opcion, float *notas, float *maximo, float *minimo, int *contador);
void ingresoDatos(float *notas, float *maximo, float *minimo, int *contador);
float calcularPromedio(float notas, float contador);

int main(){

    float notas, maximo, minimo; 
    int opcion, contador;

    do{
        opcion = menu();
        seleccion(opcion, &notas, &maximo, &minimo, &contador);

    }while(opcion != 0);

    return 0;
}

int menu(){
    int op;
    printf("Menu de opciones: \n");
    printf("1- Ingreso de notas. \n");
    printf("2- Suma total de notas. \n");
    printf("3- Promedio total de notas. \n");
    printf("4- Maximo promedio de notas. \n");
    printf("5- Minimo promedio de notas. \n");
    printf("0- Salir del programa. \n");
    do{
        printf("Ingrese la opcion: \n");
        scanf("%d", &op);
    }while(op < 0 || op > 5);
    return op;
}

void seleccion(int opcion, float *notas, float *maximo, float *minimo, int *contador){

    switch (opcion)
    {
    case 1:
        ingresoDatos(notas, maximo, minimo, contador);
        break;
    case 2:
        printf("Suma total de notas: %.2f \n", *notas);
        break;
    case 3:
        calcularPromedio(*notas,*contador);
        break;
    case 4:
        printf("Maximo promedio de notas: %.2f \n", *maximo);
        break;
    case 5:
        printf("Minimo promedio de notas: %.2f \n", *minimo);
        break;
    case 0:
        printf("Saliste del menu.. \n");
        break;
    }

}

void ingresoDatos(float *notas, float *maximo, float *minimo, int *contador){

    float nota, cont=0, acum=0;

    printf("Ingrese una nota: \n");
    scanf("%f", &nota);
    
    *maximo = nota;
    *minimo = nota;

    while(nota != 0){
        cont++;
        acum += nota;

     if(nota > *maximo){
        *maximo = nota;
    }else if(nota < *minimo){
        *minimo = nota;
    }

    printf("Ingrese una nota: \n");
    scanf("%f", &nota);   
    }

    *notas = acum;
    *contador = cont;
    return;
}


float calcularPromedio(float notas, float contador){
    float result;
    result = (notas/contador);
    printf("Promedio de notas %.2f \n", result);
    return result;
}