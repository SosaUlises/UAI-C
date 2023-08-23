#include <stdio.h>
#include <string.h>
#define T 2

void ingresoDatos(char camion[20], int cViajes[], float kmRecorridos[]);
void procesoDatos(int cViajes[], float kmRecorridos[], float promedioKm[], float consumoC[], float costoViajes[], float *mayorPromedioKm,float *menorPromedioKm, float *mayorCosto,float *menorCosto);
void salidaDatos(char camion[20], int cViajes[], float kmRecorridos[], float promedioKm[], float consumoC[], float costoViajes[], float mayorPromedioKm, float menorPromedioKm, float mayorCosto,float menorCosto);
void promedioKilometros(int cViajes[], float kmRecorridos[], float promedioKm[]);
void consumoCombustible(float kmRecorridos[], float consumoC[], float costoViajes[]);
float maxProKm(float promedioKm[]);
float minProKm(float promedioKm[]);
float maxCosto(float costoViajes[]);
float minCosto(float costoViajes[]);



int main(){

    int cViajes[T];
    float kmRecorridos[T];
    char camion[20];
    float promedioKm[T], consumoC[T], costoViaje[T];
    float mayorPromedioKm, menorPromedioKm, mayorCosto, menorCosto;


    ingresoDatos(camion, cViajes, kmRecorridos);
    procesoDatos(cViajes, kmRecorridos, promedioKm, consumoC, costoViaje, &mayorPromedioKm, &menorPromedioKm, &mayorCosto, &menorCosto);
    salidaDatos(camion,cViajes,kmRecorridos,promedioKm,consumoC,costoViaje,mayorCosto,menorCosto,mayorPromedioKm,menorPromedioKm);
    return 0;
}


void ingresoDatos(char camion[20], int cViajes[], float kmRecorridos[]){

    char nEmpresa[20];
    int viajes;
    float km;

    for(int i = 0; i < T; i++){

        printf("Ingrese el nombre de la empresa: \n");
        fflush(stdin);
        gets(nEmpresa);
        strcpy(camion[i], nEmpresa);

        printf("Ingrese la cantidad de viajes: \n");
        scanf("%d", &viajes);
        cViajes[i] = viajes;

        printf("Ingrese la cantidad de kmRecorridos");
        scanf("%f", &km);
        kmRecorridos[i] = km;
    }
}
void procesoDatos(int cViajes[], float kmRecorridos[], float promedioKm[], float consumoC[], float costoViajes[], float *mayorPromedioKm, float *menorPromedioKm, float *mayorCosto,float *menorCosto){

    promedioKilometros(cViajes, kmRecorridos, promedioKm);
    consumoCombustible(kmRecorridos, consumoC, costoViajes);
    *mayorPromedioKm = maxProKm(promedioKm);
    *menorPromedioKm = minProKm(promedioKm);
    *mayorCosto = maxCosto(costoViajes);
    *menorCosto = minCosto(costoViajes);
}

void salidaDatos(char camion[20], int cViajes[], float kmRecorridos[], float promedioKm[], float consumoC[], float costoViajes[], float mayorPromedioKm, float menorPromedioKm, float mayorCosto,float menorCosto){
    for (int i = 0; i < T; i++)
    {
        printf("Muestra de datos: \n");
        printf("Nombre de la empresa: %c \n", camion[i]);
        printf("Cantidad de viajes: %d \n", cViajes[i]);
        printf("Cantidad de kilometros recorridos: %.2f \n", kmRecorridos[i]);
        printf("Promedio de kilometros por viaje: %.2f \n", promedioKm[i]);
        printf("Consumo de litros de combustible: %.1f \n", consumoC[i]);
        printf("Costo del viaje: %.2f \n", costoViajes[i]);
        printf("----------------------------------------------------- \n");
    }
        printf("----------------------------------------------------- \n");
        printf("Mayor promedio de kilometros: %.2f \n", mayorPromedioKm);
        printf("Menor promedio de kilometros: %.2f \n", menorPromedioKm); 
        printf("Mayor costo de viaje: %.1f \n", mayorCosto);
        printf("Menor costo de viaje: %.1f \n", menorCosto);

}

void promedioKilometros(int cViajes[], float kmRecorridos[], float promedioKm[]){
    int result;
    for(int i = 0; i < T; i++){
        result = (kmRecorridos[i]/cViajes[i]);
        promedioKm[i] = result;
    }
}
void consumoCombustible(float kmRecorridos[], float consumoC[], float costoViajes[]){
    int result;

    for (int i = 0; i < T; i++)
    {
       result = (kmRecorridos[i]/100) * 25;
       consumoC[i] = result;

       // Calculamos costo del viaje
       costoViajes[i] = (result * 280);
    }
}


float maxProKm(float promedioKm[]){
    float max = -1;

    for (int i = 0; i < T; i++)
    {
        if(promedioKm[i] > max){
            max = promedioKm[i];
        }
    }
    return max;
}
float minProKm(float promedioKm[]){
    float min = 1000000;

    for (int i = 0; i < T; i++)
    {
        if(promedioKm[i] < min){
            min = promedioKm[i];
        }
    }
    return min;
}

float maxCosto(float costoViajes[]){

    float max = -1;

    for (int i = 0; i < T; i++)
    {
        if(costoViajes[i] > max){
            max = costoViajes[i];
        }
    }
   return max;
}

float minCosto(float costoViajes[]){

    float min = 100000000;

    for (int i = 0; i < T; i++)
    {
        if(costoViajes[i] < min){
            min = costoViajes[i];
        }
    }
   return min;
}