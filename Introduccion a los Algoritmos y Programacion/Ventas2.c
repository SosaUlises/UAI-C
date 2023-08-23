#include <stdio.h>
#include <string.h>
#define V 200
#define C 5 // 1-CodigoCliente 2-Nombre 3-CodigoProducto 4-CantidadVendida 5-Precio
#define P 4 // 1-Papa 2-Cebolla 3-Zanahoria 4-Zapallito
#define L 6 // Posiciones datos arreglo ventasproductos
void ingresoDatos(float VENTAS[][C], int *cantidadClientes);
void procesoDatos(float VENTAS[][C], int *cantidadClientes, int *tPapa, int *tCebo, int *tZana, int *tZapa, float *totalVentas, int *mayor, int *menor, int *totalCantidadVentas, int VENTASPRODUCTOS[][L]);
void salidaDatos(int VENTASPRODUCTOS[][L], int cantidadClientes, int mayor, int menor);

void obtenerVentas(float VENTAS[][C], int *cantidadClientes, int *tPapa, int *tCebo, int *tZana, int *tZapa, float *totalVentas, int *totalCantidadVentas, int VENTASPRODUCTOS[][L]);
int obtenerMayor(int VENTASPRODUCTOS[][L]);
int obtenerMenor(int VENTASPRODUCTOS[][L]);

int main()
{
    float VENTAS[V][C];
    int VENTASPRODUCTOS[1][L];
    int cantidadClientes, totalCantidadVentas;
    int tPapa = 0, tCebo = 0, tZana = 0, tZapa = 0;
    float totalVentas;
    int mayor, menor;

    ingresoDatos(VENTAS, &cantidadClientes);
    procesoDatos(VENTAS, &cantidadClientes, &tPapa, &tCebo, &tZana, &tZapa, &totalVentas, &mayor, &menor, &totalCantidadVentas, VENTASPRODUCTOS);
    salidaDatos(VENTASPRODUCTOS, cantidadClientes, mayor, menor);
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

void procesoDatos(float VENTAS[][C], int *cantidadClientes, int *tPapa, int *tCebo, int *tZana, int *tZapa, float *totalVentas, int *mayor, int *menor, int *totalCantidadVentas, int VENTASPRODUCTOS[][L])
{

    obtenerVentas(VENTAS, cantidadClientes, tPapa, tCebo, tZana, tZapa, totalVentas, totalCantidadVentas, VENTASPRODUCTOS);
    *mayor = obtenerMayor(VENTASPRODUCTOS);
    *menor = obtenerMenor(VENTASPRODUCTOS);
}

void obtenerVentas(float VENTAS[][C], int *cantidadClientes, int *tPapa, int *tCebo, int *tZana, int *tZapa, float *totalVentas, int *totalCantidadVentas, int VENTASPRODUCTOS[][L])
{

    int acumulacionTotal = 0;
    int papa = 0, cebolla = 0, zanahoria = 0, zapallito = 0;
    for (int i = 0; i < *cantidadClientes; i++)
    {
        acumulacionTotal += VENTAS[i][4] * VENTAS[i][5];

        if (VENTAS[i][3] == 1)
        {
            papa += VENTAS[i][4];
        }
        else if (VENTAS[i][3] == 2)
        {
            cebolla += VENTAS[i][4];
        }
        else if (VENTAS[i][3] == 3)
        {
            zanahoria += VENTAS[i][4];
        }
        else
        {
            zapallito += VENTAS[i][4];
        }
    }

    *tPapa = papa;
    *tCebo = cebolla;
    *tZana = zanahoria;
    *tZapa = zapallito;
    *totalCantidadVentas = (*tPapa + *tCebo + *tZana + *tZapa);
    *totalVentas = acumulacionTotal;

    for (int j = 0; j < 6; j++)
    {
        switch (j)
        {
        case 0:
            VENTASPRODUCTOS[0][j] = *tPapa; // Cantidad total de papas
            break;
        case 1:
            VENTASPRODUCTOS[0][j] = *tCebo; // Cantidad total de cebollas
            break;
        case 2:
            VENTASPRODUCTOS[0][j] = *tZana; // Cantidad total de zanahorias
            break;
        case 3:
            VENTASPRODUCTOS[0][j] = *tZapa; // Cantidad total de zapallito
            break;
        case 4:
            VENTASPRODUCTOS[0][j] = *totalCantidadVentas; // Cantidad total en $ de ventas
            break;
        case 5:
            VENTASPRODUCTOS[0][j] = *totalVentas; // Suma total de todas las ventas
            break;
        default:
            break;
        }
    }
}

int obtenerMayor(int VENTASPRODUCTOS[][L])
{
    int tmayor = 0;
    int posMayor = 0;
    for (int j = 0; j < 4; j++)
    {
        if (VENTASPRODUCTOS[0][j] > tmayor)
        {
            tmayor = VENTASPRODUCTOS[0][j];
            posMayor = j + 1;
        }
    }

    return posMayor;
}

int obtenerMenor(int VENTASPRODUCTOS[][L])
{
    int tmenor = 1000000;
    int posMenor = 0;

    for (int j = 0; j < 4; j++)
    {
        if (VENTASPRODUCTOS[0][j] == 0)
        {
            posMenor = 0;
        }
        else if (VENTASPRODUCTOS[0][j] < tmenor)
        {
            tmenor = VENTASPRODUCTOS[0][j];
            posMenor = j + 1;
        }
    }

    return posMenor;
}

void salidaDatos(int VENTASPRODUCTOS[][L], int cantidadClientes, int mayor, int menor)
{

    printf("Ventas del dia: \n");
    printf("Total de ventas: $%d \n", VENTASPRODUCTOS[0][5]);
    printf("Cantidad de clientes: %d \n", cantidadClientes);
    printf("Cantidad de ventas en total: %d \n", VENTASPRODUCTOS[0][4]);
    printf("Cantidad de papas vendidas: %d \n", VENTASPRODUCTOS[0][0]);
    printf("Cantidad de cebollas vendidas: %d \n", VENTASPRODUCTOS[0][1]);
    printf("Cantidad de zanahorias vendidas: %d \n", VENTASPRODUCTOS[0][2]);
    printf("Cantidad de zapallitos vendidos: %d \n", VENTASPRODUCTOS[0][3]);

    switch (mayor)
    {
    case 1:
        printf("Mayor venta: Codigo: %d - Papa\n", mayor);
        break;
    case 2:
        printf("Mayor venta: Codigo: %d - Cebolla\n", mayor);
        break;
    case 3:
        printf("Mayor venta: Codigo: %d - Zanahoria\n", mayor);
        break;
    case 4:
        printf("Mayor venta: Codigo: %d - Zapallito\n", mayor);
        break;
    default:
        printf("Mayor venta: Codigo: 0 - 0\n");
        break;
    }

    switch (menor)
    {
    case 1:
        printf("Menor venta: Codigo: %d - Papa\n", menor);
        break;
    case 2:
        printf("Menor venta: Codigo: %d - Cebolla\n", menor);
        break;
    case 3:
        printf("Menor venta: Codigo: %d - Zanahoria\n", menor);
        break;
    case 4:
        printf("Menor venta: Codigo: %d - Zapallito\n", menor);
        break;
    default:
        printf("Mayor venta: Codigo: 0 - 0\n");
        break;
    }
}