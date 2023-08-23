/*
    Construir un programa que realiza lo siguente.
    Ingreso los siguientes datos:
        1) El numero de la estacion meteorologica. 
        2) Cada estacion toma las temperaturas diarias en peri­odos
           de una hora, o sea en un di­a realiza 24 lecturas.
           Dichas lecturas seran numeros reales. 
        3) Tambien es necesario guardar los valores enteros de:
           la presion (entero)
           la humedad relativa (es un porcentaje 0-100), 
           la direccion del viento (001 a 360// N= 0  360, E= 090, S=180, W=270)
           la intensidad o velocidad (entero en km/h  Nudos knots milla nÃ¡utica/hora).
            Utizaremos: (Matriz de numeros Enteros)         
           
    Se desea saber u obtener:  ( procesos --> salidas )
        a) El promedio diario de las temperaturas.
        b) La temperatura mi­nima y maxima.
        c) El maximo valor de humedad relativa.
        d) Cual fue la maxima intensidad y direccion del viento

*/
#include <stdio.h>
#define TEMP 4
#define V 4

void ingresoDatos(int estacion[], float Temp[], float Viento[][V]);
void procesoDatos(float Temp[], float Viento[][V], float *promedio, float *tempMaxima, float *tempMinima, float *maximaHumedad, float *mInt, float *mDirec);
void salidaDatos(float promedio, float tempMaxima, float tempMinima, float maximaHumedad, float mInt, float mDirec);


float promedioTemps(float Temp[]);
float tMaxima(float Temp[]);
float tMinima(float Temp[]);
float mHumedad(float Viento[][V]);
void mIntDirec(float Viento[][V], float *mInt, float *mDirec);


int main(){
    int estacion[TEMP];
    float Temp[TEMP];
    float Viento[TEMP][V]; // presion - humedad - direccion - intensidad

    float promedio, tempMaxima, tempMinima;
    float maximaHumedad, mInt, mDirec;

    ingresoDatos(estacion,Temp,Viento);
    procesoDatos(Temp,Viento, &promedio, &tempMaxima, &tempMinima, &maximaHumedad, &mInt, &mDirec);
    salidaDatos(promedio, tempMaxima, tempMinima, maximaHumedad, mInt, mDirec);
    
    
    return 0;
}


void ingresoDatos(int estacion[], float Temp[], float Viento[][V]){
    int numero, i=0, j=0, ingreso;
    float temp;

    for(i = 0; i < TEMP ; i++){
        printf("Ingrese la estacion %d: \n", i+1);
        scanf("%d", &numero);
         printf("Ingrese la temperatura: \n");
        scanf("%f", &temp);

        estacion[i] = numero;
        Temp[i] = temp;
    }

    for(  i = 0; i < TEMP ; i++){

        for ( j = 0; j < V; j++)
        {
           printf("Ingreso de Viento, valor:  %d-  \n", j+1);
           printf("1- Presion \n");
           printf("2- Humedad \n");
           printf("3- Direccion \n");
           printf("4- Intensidad \n");

           scanf("%d", &ingreso);
           Viento[i][j] = ingreso;
        }
        
    }

}

void procesoDatos(float Temp[], float Viento[][V], float *promedio, float *tempMaxima, float *tempMinima, float *maximaHumedad, float *mInt, float *mDirec){
    
    *promedio = promedioTemps(Temp);
    *tempMaxima = tMaxima(Temp);
    *tempMinima = tMinima(Temp);
    
    *maximaHumedad = mHumedad(Viento);
    mIntDirec(Viento, mInt, mDirec);
}

float promedioTemps(float Temp[]){
    float prom, sumTemp;

    // Calcular promedio de temps
    for(int i = 0; i < TEMP; i++){
        sumTemp += Temp[i];
    }
    prom = sumTemp / TEMP;
    
    return prom;
}

float tMaxima(float Temp[]){
    float maxima=0;

    for(int i = 0; i < TEMP; i++){
        if(Temp[i] >= maxima){
            maxima = Temp[i];
        }
    }
    return maxima;
}

float tMinima(float Temp[]){
    float minima=999;
  

    for(int i = 0; i < TEMP; i++){
        if(Temp[i] <= minima){
            minima = Temp[i];
        }
    }
    return minima;
}

float mHumedad(float Viento[][V]){
    float maximaHumedad=0;

    for(int i=0; i < TEMP; i++){
        if(Viento[i][1] >= maximaHumedad){
            maximaHumedad = Viento[i][1];
        }
    }

    return maximaHumedad;
}

void mIntDirec(float Viento[][V], float *mInt, float *mDirec){
    float maximoViento=-1, maximoDireccion=0;
    

    for(int i = 0; i < TEMP; i++){
        if(Viento[i][3] > maximoViento){
            maximoViento = Viento[i][3];
           maximoDireccion = Viento[i][2];
            }
    }
    *mInt= maximoViento;
    *mDirec= maximoDireccion;
}

void salidaDatos(float promedio, float tempMaxima, float tempMinima, float maximaHumedad, float mInt, float mDirec){

    printf("Promedio de temperaturas: %.2f \n", promedio);
    printf("Temperatura Maxima: %.2f \n", tempMaxima);
    printf("Temperatura Minima: %.2f \n", tempMinima);
    printf("Maxima Humedad: %.2f \n", maximaHumedad);
    printf("Maxima Intensidad de viento: %.2f \n", mInt);
    printf("Maxima Direccion: %.2f \n", mDirec);
}