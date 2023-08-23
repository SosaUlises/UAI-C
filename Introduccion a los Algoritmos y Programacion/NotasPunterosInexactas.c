#include <stdio.h>


void ingresoDatos(float *notas, float *contador,float *minimo, float *max);
void procesoDatos(float notas, float contador,  float *promedio);
void salidaDatos(float promedio, float minimo, float max);
float buscarPromedio(float notas, float contador);



int main()
{
      float notas, contador;
      float promedio, max, minimo;

      ingresoDatos(&notas, &contador, &minimo, &max);
      procesoDatos(notas, contador, &promedio);
      salidaDatos(promedio,minimo,max);


    return 0;
}


void ingresoDatos(float *notas, float *contador, float *minimo, float *max){

    float nota, acumulacion=0 ,cont=0;

    printf("Ingrese una nota \n");
    scanf("%f", &nota);

    *minimo = nota;
    *max = nota;

    while(nota != 0){

        acumulacion += nota;
        cont++;

        if (nota < *minimo) {
            *minimo = nota;
        } else if (nota > *max) {
            *max = nota;
        }

        printf("Ingrese una nota: \n");
        scanf("%f", &nota);
    }
    *notas = acumulacion;
    *contador = cont;
       
    return;
}

void procesoDatos(float notas, float contador, float *promedio){
   
    *promedio = buscarPromedio(notas, contador);
   
}

float buscarPromedio(float notas, float contador){
    return (notas/contador);
}

void salidaDatos(float promedio, float minimo, float max){
    printf("Promedio del curso: %.2f \n", promedio);
    printf("Promedio mayor del curso: %.2f \n", max);
    printf("Promedio menor del curso: %.2f \n", minimo);
}