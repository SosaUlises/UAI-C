#include <stdio.h>
#define CAM 10

void ingresoDatos(int nUnidad[], int cViajes[], float kmRecorrido[]);

void procesoDatos(int cViajes[], float kmRecorridos[], float promedio[], float costoOil[], float consumoLitros[]);

void salidaDatos(int nUnidad[], float promedio[], float costoOil[], float consumoLitros[]);

void promedioKilometros(int cViajes[], float kmRecorridos[], float promedio[]);

void consumoCamLitros(float kmRecorridos[], float consumoLitros[]);

void costoCamOil(float kmRecorridos[], float costoOil[]);

int main()
{

    int nUnidad[CAM], cViajes[CAM];

    float kmRecorrido[CAM];

    float promedio[CAM];

    float costoOil[CAM], consumoLitros[CAM];

    ingresoDatos(nUnidad, cViajes, kmRecorrido);

    procesoDatos(cViajes, kmRecorrido, promedio, costoOil, consumoLitros);

    salidaDatos(nUnidad, promedio, costoOil, consumoLitros);

    return 0;
}

void ingresoDatos(int nUnidad[], int cViajes[], float kmRecorrido[])
{
    
    for (int i=0; i < CAM; i++)
    {

        printf("Ingrese el numero de unidad del camion: \n");

        scanf("%d", &nUnidad[i]);

        printf("Ingrese la cantidad de viajes: \n");

        scanf("%d", &cViajes[i]);

        printf("Ingrese los kilometros recorridos: \n");

        scanf("%f", &kmRecorrido[i]);
    }
}

void procesoDatos(int cViajes[], float kmRecorridos[], float promedio[], float costoOil[], float consumoLitros[])
{

     promedioKilometros(cViajes, kmRecorridos, promedio);

    consumoCamLitros(kmRecorridos, consumoLitros);

    costoCamOil(kmRecorridos, costoOil);
}

void salidaDatos(int nUnidad[], float promedio[], float costoOil[], float consumoLitros[])
{

    for ( int i = 0; i < CAM; i++)
    {

        printf("Camion %d: \n", i + 1);

        printf("Numero Unidad: %d \n", nUnidad[i]);

        printf("Promedio de kilometros por viaje: %.2f\n", promedio[i]);

        printf("Consto de gas oil: $%.2f \n", costoOil[i]);

        printf("Consumo de litros: %.2f \n", consumoLitros[i]);
    }
}

void promedioKilometros(int cViajes[], float kmRecorridos[], float promedio[])
{

    float promedioKm;

    for (int i = 0; i < CAM; i++)
    {

        promedioKm = (kmRecorridos[i] / cViajes[i]);

        promedio[i] = promedioKm;
    }
}

void consumoCamLitros(float kmRecorridos[], float consumoLitros[])
{

    float costoPromedio;

    for (int i = 0; i < CAM; i++)
    {

        costoPromedio = (kmRecorridos[i] / 100) * 25;


        consumoLitros[i] = costoPromedio;
    }
}

void costoCamOil(float kmRecorridos[], float costoOil[])
{

    float costoPromedio;

    for(int i = 0; i < CAM; i++)
    {

        costoPromedio = (kmRecorridos[i] / 100) * 25;

        costoOil[i] = (costoPromedio * 280);
    }
}


 
