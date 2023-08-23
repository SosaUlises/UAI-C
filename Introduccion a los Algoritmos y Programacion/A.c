#include <stdio.h>
#include <string.h>
#define V 200
#define C 5 // 1-CodigoCliente 2-Nombre 3-CodigoProducto 4-CantidadVendida 5-Precio
#define P 4 // 1-Papa 2-Cebolla 3-Zanahoria 4-Zapallito
#define L 6 // Posiciones datos arreglo ventasproductos
void ingresoDatos(float VENTAS[][C], int *cantidadClientes);
void procesoDatos(float VENTAS[][C], int *cantidadClientes, int *tPapa, int *tCebo, int *tZana, int *tZapa, float *totalVentas, int *mayor, int *menor, int *totalCantidadVentas, float PROMEDIOVENTASPRODUCTOS[][L]);
void salidaDatos(float PROMEDIOVENTASPRODUCTOS[][L], int cantidadClientes, int mayor, int menor);

void obtenerVentas(float VENTAS[][C], int *cantidadClientes, int *tPapa, int *tCebo, int *tZana, int *tZapa, float *totalVentas, int *totalCantidadVentas, float PROMEDIOVENTASPRODUCTOS[][L]);
int obtenerMayor(float PROMEDIOVENTASPRODUCTOS[][L]);
int obtenerMenor(float PROMEDIOVENTASPRODUCTOS[][L]);

int main()
{
    float VENTAS[V][C];
    float PROMEDIOVENTASPRODUCTOS[1][L];
    int cantidadClientes, totalCantidadVentas;
    int tPapa = 0, tCebo = 0, tZana = 0, tZapa = 0;
    float totalVentas;
    int mayor, menor;

    ingresoDatos(VENTAS, &cantidadClientes);
    procesoDatos(VENTAS, &cantidadClientes, &tPapa, &tCebo, &tZana, &tZapa, &totalVentas, &mayor, &menor, &totalCantidadVentas, PROMEDIOVENTASPRODUCTOS);
    salidaDatos(PROMEDIOVENTASPRODUCTOS, cantidadClientes, mayor, menor);
    return 0;
}

void ingresoDatos(float VENTAS[][C], int *cantidadClientes)
{
    float cCliente, cProducto, cVendida, pUnidad;
    char nombre[20];
    int i = 0;
    int op;

    do
    {

        for (int j = 0; j <= C; j++)
        {
            switch (j)
            {
            case 1:
                do
                {
                    printf("Ingrese el codigo del cliente:  \n");
                    scanf("%f", &cCliente);
                } while (cCliente < 1000 || cCliente > 9999);
                VENTAS[i][j] = cCliente;
                break;
            case 2:
                printf("Ingrese el Nombre del Cliente: \n");
                fflush(stdin);
                gets(nombre);
                break;
            case 3:
                do
                {
                    printf("Codigo del producto:  \n");
                    scanf("%f", &cProducto);
                } while (cProducto < 1 || cProducto > 4);
                VENTAS[i][j] = cProducto;
                break;
            case 4:
                printf("Cantidad vendida:  \n");
                scanf("%f", &cVendida);
                VENTAS[i][j] = cVendida;
                break;
            case 5:
                printf("Precio de la unidad:  \n");
                scanf("%f", &pUnidad);
                VENTAS[i][j] = pUnidad;
                break;
            }
        }

        printf("Desea agregar una venta?: 1- Si 0- No \n");
        scanf("%d", &op);
        i++;
    } while (op != 0 || i >= 200);

    *cantidadClientes = i;
}

void procesoDatos(float VENTAS[][C], int *cantidadClientes, int *tPapa, int *tCebo, int *tZana, int *tZapa, float *totalVentas, int *mayor, int *menor, int *totalCantidadVentas, float PROMEDIOVENTASPRODUCTOS[][L])
{

    obtenerVentas(VENTAS, cantidadClientes, tPapa, tCebo, tZana, tZapa, totalVentas, totalCantidadVentas, PROMEDIOVENTASPRODUCTOS);
    *mayor = obtenerMayor(PROMEDIOVENTASPRODUCTOS);
    *menor = obtenerMenor(PROMEDIOVENTASPRODUCTOS);
    printf("%d", *menor);
}

void obtenerVentas(float VENTAS[][C], int *cantidadClientes, int *tPapa, int *tCebo, int *tZana, int *tZapa, float *totalVentas, int *totalCantidadVentas, float PROMEDIOVENTASPRODUCTOS[][L])
{

    int acumulacionTotal = 0;
    int papa = 0, cebolla = 0, zanahoria = 0, zapallito = 0;
    int papaPrecio = 0, cebollaPrecio = 0, zanahoriaPrecio = 0, zapallitoPrecio = 0;
    int cpapa=0, ccebo=0, czana = 0, czapa = 0; 
    for (int i = 0; i < *cantidadClientes; i++)
    {
        acumulacionTotal += VENTAS[i][4] * VENTAS[i][5];
                             // cant        // precio

        if (VENTAS[i][3] == 1)
        {
            papa += VENTAS[i][4];
            papaPrecio += VENTAS[i][5];
            cpapa++;
        }
        else if (VENTAS[i][3] == 2)
        {
            cebolla += VENTAS[i][4];
            cebollaPrecio += VENTAS[i][5];
            ccebo++;
        }
        else if (VENTAS[i][3] == 3)
        {
            zanahoria += VENTAS[i][4];
            zanahoriaPrecio += VENTAS[i][5];
            czana++;
        }
        else
        {
            zapallito += VENTAS[i][4];
            zapallitoPrecio += VENTAS[i][5];
            czapa++;
        }
    }
    
    *totalVentas = acumulacionTotal;
    if(cpapa != 0){
        *tPapa = (papaPrecio * papa) / cpapa;
    }else{
        *tPapa = 0;
    }
    if(ccebo!= 0){
        *tCebo = (cebollaPrecio * cebolla) / ccebo;
    }else{
        *tCebo = 0;
    }
    if(czana != 0){
        *tZana = (zanahoria * zanahoriaPrecio) / czana;
    }else{
        *tZana = 0;
    }
     if(czapa != 0){
         *tZapa = (zapallito * zapallitoPrecio) / czapa;
    }else{
        *tZapa = 0;
    }
    
   
    *totalCantidadVentas = (papa + cebolla + zanahoria + zapallito);
    

    for (int j = 0; j < 6; j++)
    {
        switch (j)
        {
        case 0:
            PROMEDIOVENTASPRODUCTOS[0][j] = *tPapa; // Promedio de papas
            break;
        case 1:
            PROMEDIOVENTASPRODUCTOS[0][j] = *tCebo; // Promedio de cebollas
            break;
        case 2:
            PROMEDIOVENTASPRODUCTOS[0][j] = *tZana; // Promedio de zanahorias
            break;
        case 3:
            PROMEDIOVENTASPRODUCTOS[0][j] = *tZapa; // Promedio de zapallito
            break;
        case 4:
            PROMEDIOVENTASPRODUCTOS[0][j] = *totalCantidadVentas; // Cantidad total en $ de ventas
            break;
        case 5:
            PROMEDIOVENTASPRODUCTOS[0][j] = *totalVentas; // Suma total de todas las ventas
            break;
        default:
            break;
        }
    }
}

int obtenerMayor(float PROMEDIOVENTASPRODUCTOS[][L])
{
    int tmayor = 0;
    int posMayor = 0;
    for (int j = 0; j < 4; j++)
    {
        if (PROMEDIOVENTASPRODUCTOS[0][j] > tmayor)
        {
            tmayor = PROMEDIOVENTASPRODUCTOS[0][j];
            posMayor = j + 1;
        }
    }

    return posMayor;
}

int obtenerMenor(float PROMEDIOVENTASPRODUCTOS[][L])
{
    int tmenor = 1000000;
    int posMenor = 0;

    for (int j = 0; j < 4; j++)
    {
        if (PROMEDIOVENTASPRODUCTOS[0][j] == 0)
        {
            posMenor = 0;
        }else if(PROMEDIOVENTASPRODUCTOS[0][j] <= tmenor){
         
            tmenor = PROMEDIOVENTASPRODUCTOS[0][j];
            posMenor = j + 1;
        }
    }

    return posMenor;
}

void salidaDatos(float PROMEDIOVENTASPRODUCTOS[][L], int cantidadClientes, int mayor, int menor)
{

    printf("Ventas del dia: \n");
    printf("Total de ventas: $%.1f \n", PROMEDIOVENTASPRODUCTOS[0][5]);
    printf("Cantidad de clientes: %d \n", cantidadClientes);
    printf("Cantidad de ventas en total: %.0f \n", PROMEDIOVENTASPRODUCTOS[0][4]);
    printf("Promedio de papas: %.2f   \n", PROMEDIOVENTASPRODUCTOS[0][0]);
    printf("Promedio de cebollas: %.2f  \n", PROMEDIOVENTASPRODUCTOS[0][1]);
    printf("Promedio de zanahorias: %.2f  \n", PROMEDIOVENTASPRODUCTOS[0][2]);
    printf("Promedio de zapallitos: %.2f \n", PROMEDIOVENTASPRODUCTOS[0][3]);

    switch (mayor)
    {
    case 1:
        printf("Mayor promedio: Codigo: %d - Papa\n", mayor);
        break;
    case 2:
        printf("Mayor promedio: Codigo: %d - Cebolla\n", mayor);
        break;
    case 3:
        printf("Mayor promedio: Codigo: %d - Zanahoria\n", mayor);
        break;
    case 4:
        printf("Mayor promedio: Codigo: %d - Zapallito\n", mayor);
        break;
    default:
        printf("Mayor promedio: Codigo: 0 - 0\n");
        break;
    }

    switch (menor)
    {
    case 1:
        printf("Menor promedio: Codigo: %d - Papa\n", menor);
        break;
    case 2:
        printf("Menor promedio: Codigo: %d - Cebolla\n", menor);
        break;
    case 3:
        printf("Menor promedio: Codigo: %d - Zanahoria\n", menor);
        break;
    case 4:
        printf("Menor promedio: Codigo: %d - Zapallito\n", menor);
        break;
    default:
        printf("Menor promedio: Codigo: 0 - 0\n");
        break;
    }
}