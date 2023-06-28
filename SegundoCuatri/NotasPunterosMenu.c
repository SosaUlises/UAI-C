#include<stdio.h>


void ingresoDatos(float *notas);
void procesoDatos();
void salidaDatos();
float buscarMaximoP();
float buscarMinimoP();
float buscarPromedio();

int main(){


    float notas;
    float maximoP, minimoP, promedio;

    void ingresoDatos(&notas);
    void procesoDatos();
    void salidaDatos();
    
    return 0;
}


void ingresoDatos(float *notas){
    float contador=0;
    float acumulador=0;
    float nota;

    while(nota != 0){
        printf("Ingrese la nota:  \n");
        scanf("%f", &nota);
        acumulador += nota;
        contador++;
    }

    return;
}
void procesoDatos();
void salidaDatos();
float buscarMaximoP();
float buscarMinimoP();
float buscarPromedio();