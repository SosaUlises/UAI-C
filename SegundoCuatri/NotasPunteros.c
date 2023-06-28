#include <stdio.h>


void ingresoDatos(float *n1, float *n2, float *n3, float *n4);
void procesoDatos(float n1, float n2, float n3, float n4, float *promedio, float *maximoP, float *minimoP);
void salidaDatos(float promedio, float maximoP, float minimoP);
float buscarPromedio(float n1, float n2, float n3, float n4);
float buscarMaximo(float n1, float n2, float n3, float n4);
float buscarMinimo(float n1, float n2, float n3, float n4);


int main()
{
      float n1,n2,n3,n4;
      float maximoP, minimoP, promedio;

      ingresoDatos(&n1, &n2, &n3, &n4);
      procesoDatos(n1,n2,n3,n4, &promedio, &maximoP, &minimoP);
      salidaDatos(promedio, maximoP,minimoP);


    return 0;
}


void ingresoDatos(float *n1, float *n2, float *n3, float *n4){
    *n1 = 10;
    *n2 = 20;
    *n3 = 30;
    *n4 = 50;
    return;
}

void procesoDatos(float n1, float n2, float n3, float n4, float *promedio, float *maximoP, float *minimoP){
    *promedio = buscarPromedio(n1,n2,n3,n4);
    *maximoP = buscarMaximo(n1, n2, n3, n4);
    *minimoP = buscarMinimo(n1,n2,n3,n4);
    return;
}

float buscarPromedio(float n1, float n2, float n3, float n4){
    float promedio = ((n1+n2+n3+n4)/4);
    return promedio;
}

float buscarMaximo(float n1, float n2, float n3, float n4){
    float maximoP;
    if(n1 > n2 && n1 > n3 && n1 > n4){
        maximoP = n1;
    }else 
    if(n2 > n1 && n2 > n3 && n2 > n4){
        maximoP = n2;
    }else
    if(n3 > n1 && n3 > n2 && n3 > n4){
        maximoP = n3;
    }else{
        maximoP = n4;
    }

    return maximoP;
}

float buscarMinimo(float n1, float n2, float n3, float n4){
float minimoP;
    if(n1 < n2 && n1 < n3 && n1 < n4){
        minimoP = n1;
    }else 
    if(n2 < n1 && n2 < n3 && n2 < n4){
        minimoP = n2;
    }else
    if(n3 < n1 && n3 < n2 && n3 < n4){
        minimoP = n3;
    }else{
        minimoP   = n4;
    }

    return minimoP;
}

void salidaDatos(float promedio, float maximoP, float minimoP){
    printf("Promedio del curso: %.2f \n", promedio);
    printf("Promedio mayor del curso: %.2f \n", maximoP);
    printf("Promedio menor del curso: %.2f \n", minimoP);
}