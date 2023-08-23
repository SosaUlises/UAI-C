
#include <stdio.h>
#define FI 3 // Cantidad de Camiones
#define CO 6 // Cantidad de Datos

void ingresoDatos(float CAMIONES[][CO]);
void procesoDatos(float CAMIONES[][CO]);
void salidaDatos(float CAMIONES[][CO]);

void promedioKm(float CAMIONES[][CO]);
void consumoComb(float CAMIONES[][CO]);

int main()
{
    float CAMIONES[FI][CO]; // 0- Unidad  1- cantidadViajes  2- kmRecorridos  3- PromedioViaje  4- ConsumoCombus 5- CostoViaje

    ingresoDatos(CAMIONES);
    procesoDatos(CAMIONES);
    salidaDatos(CAMIONES);

    return 0;
}

void ingresoDatos(float CAMIONES[][CO])
{
    int camion;
    float cantViajes, kmRec;

    for (int i = 0; i < FI; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == 0)
            {
                printf("Ingrese la unidad del camion: %d \n ", i+1);
                scanf("%d", &camion);
                CAMIONES[i][j] = camion;
            }else if(j == 1){
                printf("Ingrese la cantidad de viajes: \n");
                scanf("%f", &cantViajes);
                CAMIONES[i][j] = cantViajes;
            }else{
                printf("Ingrese la cantidad de kilometros recorridos: \n");
                scanf("%f", &kmRec);
                CAMIONES[i][j] = kmRec;
            }
        }
    }
}

void procesoDatos(float CAMIONES[][CO]){

    promedioKm(CAMIONES);
    consumoComb(CAMIONES);

}

void salidaDatos(float CAMIONES[][CO]){

    for(int i = 0; i < FI; i++){
            printf("--------------------------\n");
            printf("Unidad del camion: %.0f \n", CAMIONES[i][0]);
            printf("Cantidad de viajes: %.0f \n", CAMIONES[i][1]);
            printf("Kilometros recorridos: %.1f \n", CAMIONES[i][2]);
            printf("Promedio de kilometros por viaje: %.1f km.\n", CAMIONES[i][3]);
            printf("Consumo de litros de combustible: %.2f l. \n", CAMIONES[i][4]);
            printf("Costo del viaje: $%.2f \n", CAMIONES[i][5]);
    }
}

void promedioKm(float CAMIONES[][CO]){
    int cantidadViajes;
    float kmRecorridos;
    for(int i=0; i < FI; i++){
        cantidadViajes = CAMIONES[i][1]; 
        kmRecorridos = CAMIONES[i][2];

        CAMIONES[i][3] = (kmRecorridos / cantidadViajes);
    }
}

void consumoComb(float CAMIONES[][CO]){
    float consumoLitros, kmRecorridos;

    for(int i = 0; i < FI; i++){
        kmRecorridos = CAMIONES[i][2];

        consumoLitros = (kmRecorridos / 100) * 25;

        CAMIONES[i][4] = consumoLitros;

        // En conjunto calculamos y guardamos el costo del viaje

        CAMIONES[i][5] = (consumoLitros * 280);
    }
}