#include <stdio.h>
#include <string.h>

#define V 2  // vehiculos
#define P 8  // patente
#define M 15 // marca/modelo

// Estructuras
typedef struct
{
    int unidad;
    char patente[P];
    char marca[M];
    int year;
    int tipoCombustible;
    char categoria;
} Moviles;

typedef struct
{
    int movil;
    float distancia;
    float costo;
} Cotizaciones;

// Funciones
int menu();
void seleccion(int op, Moviles remises[], Cotizaciones cotizacion[]);
void ingresarMoviles(Moviles remises[]);
void mostrarMoviles(Moviles remises[]);
void cotizarViaje(Cotizaciones cotizacion[]);
void calculoTarifa(float distancia, Cotizaciones cotizacion[], int i);
void listaCotizaciones(Cotizaciones cotizacion[]);
void listarCotizacionesOrdenadas(Cotizaciones cotizacion[]);
void buscarPatente(Moviles remises[]);

// Funcion MAIN
int main()
{
    Moviles remises[V];
    Cotizaciones cotizacion[V];

    int op;
    do
    {
        op = menu();
        seleccion(op, remises, cotizacion);
    } while (op != 0);

    return 0;
}

// Menus

int menu()
{
    int op;

    printf("1- Ingreso de datos \n");
    printf("2- Mostrar los datos \n");
    printf("3- Cotizar viaje \n");
    printf("4- Listado de cotizaciones \n");
    printf("5- Ordenar cotizaciones\n");
    printf("6- Buscar patente\n");
    printf("0- Fin del programa \n");

    do
    {
        printf("Ingrese una opcion: ");
        scanf("%d", &op);
    } while (op < 0 || op > 6);

    return op;
}
void seleccion(int op, Moviles remises[], Cotizaciones cotizacion[])
{
    switch (op)
    {
    case 1:
        ingresarMoviles(remises);
        break;
    case 2:
        mostrarMoviles(remises);
        break;
    case 3:
        cotizarViaje(cotizacion);
        break;
    case 4:
        listaCotizaciones(cotizacion);
        break;
    case 5:
        listarCotizacionesOrdenadas(cotizacion);
        break;
    case 6:
        buscarPatente(remises);
        break;
    default:
        break;
    }
}

void ingresarMoviles(Moviles remises[])
{
    int nUnidad, year, nCombustible;
    char cadenaPatente[P];
    char cadenaModelo[M];
    char cat;

    for (int i = 0; i < V; i++)
    {
        // Numero de Unidad
        do
        {
            printf("Ingrese el numero de unidad %d:", i + 1);
            scanf("%d", &nUnidad);
        } while (nUnidad < 1 || nUnidad > 50);
        remises[i].unidad = nUnidad;

        // Patentes
        do
        {
            printf("Ingrese la patente de la unidad: \n");
            fflush(stdin);
            fgets(cadenaPatente, sizeof(cadenaPatente), stdin);

            // Eliminar el salto de línea si existe
            if (cadenaPatente[strlen(cadenaPatente) - 1] == '\n')
            {
                cadenaPatente[strlen(cadenaPatente) - 1] = '\0'; // Caracter nulo, reemplazamos por salto de linea
            }

        } while (strlen(cadenaPatente) > P);
        strcpy(remises[i].patente, cadenaPatente);

        // Marca/Modelo
        do
        {
            printf("Ingrese la marca y el modelo de la unidad: \n");
            fflush(stdin);
            fgets(cadenaModelo, sizeof(cadenaModelo), stdin);

            // Eliminar el salto de línea si existe
            if (cadenaModelo[strlen(cadenaModelo) - 1] == '\n')
            {
                cadenaModelo[strlen(cadenaModelo) - 1] = '\0'; // Caracter nulo, reemplazamos por salto de linea
            }

        } while (strlen(cadenaModelo) < 1 || strlen(cadenaModelo) > M);
        strcpy(remises[i].marca, cadenaModelo);

        // Año de fabricacion
        do
        {
            printf("Ingrese el anio de fabricacion:");
            scanf("%d", &year);
        } while (year < 2018 || year > 2023);
        remises[i].year = year;

        // Tipo de combustible
        do
        {
            printf("Ingrese el tipo de combustible: \n");
            printf("(1) Nafta (2) Gas  (3) GasOil \n");
            scanf("%d", &nCombustible);
        } while (nCombustible < 1 || nCombustible > 3);
        remises[i].tipoCombustible = nCombustible;

        // Categoria
        do
        {
            printf("Ingrese la categoria: \n");
            printf("(a) Urbana (b) InterUrbana hasta 60kms (c) Larga distancia mas de 60kms \n");
            scanf(" %c", &cat);
        } while (cat != 'a' && cat != 'b' && cat != 'c');
        remises[i].categoria = cat;
    }
}

void mostrarMoviles(Moviles remises[])
{

    for (int i = 0; i < V; i++)
    {
        printf("============================ \n");
        printf("Unidad: %d \n", remises[i].unidad);
        printf("Patente: %s\n", remises[i].patente);
        printf("Anio: %d \n", remises[i].year);
        printf("Modelo: %s\n", remises[i].marca);

        // Mostrar combustible
        switch (remises[i].tipoCombustible)
        {
        case 1:
            printf("Combustible: Nafta \n");
            break;
        case 2:
            printf("Combustible: Gas \n");
            break;
        case 3:
            printf("Combustible: GasOil \n");
            break;
        }
        // Mostrar categoria
        switch (remises[i].categoria)
        {
        case 'a':
            printf("Categoria: Urbano \n");
            break;
        case 'b':
            printf("Categoria: InterUrbano \n");
            break;
        case 'c':
            printf("Categoria: Larga distancia \n");
            break;
        }
    }
}

void cotizarViaje(Cotizaciones cotizacion[])
{
    int resp, unidad;
    float distancia;
    int i = 0;

    do
    {
        printf("Ingrese la unidad del movil: \n");
        scanf("%d", &unidad);
        cotizacion[i].movil = unidad;
        printf("Ingrese la distancia recorrida: \n");
        scanf("%f", &distancia);
        cotizacion[i].distancia = distancia;

        calculoTarifa(distancia, cotizacion, i);

        printf("Desea seguir agregando cotizaciones? (1)-Si (0)-No \n");
        scanf("%d", &resp);
        i++;
    } while (resp != 0);
}

void calculoTarifa(float distancia, Cotizaciones cotizacion[], int i)
{
    float total;

    if (distancia <= 20)
    {
        total = distancia * 80;
    }
    else if (distancia > 20 && distancia <= 60)
    {
        total = distancia * 60;
    }
    else if (distancia > 60)
    {
        total = distancia * 40;
    }

    cotizacion[i].costo = total;
    printf("Costo total: $%.2f \n", cotizacion[i].costo);
}

void listaCotizaciones(Cotizaciones cotizacion[])
{
    printf("--Cotizaciones-- \n");
    printf("========================\n");
    for (int i = 0; i < V; i++)
    {
        printf("Unidad del movil: %d \n", cotizacion[i].movil);
        printf("Kilometros recorridos: %.1f \n", cotizacion[i].distancia);
        printf("Costo total del viaje: $%.2f \n", cotizacion[i].costo);
        printf("========================\n");
    }
}

void listarCotizacionesOrdenadas(Cotizaciones cotizacion[])
{

    int auxM;
    float auxD, auxT;

    for (int i = 0; i < V - 1; i++)
    {
        for (int j = i + 1; j < V; j++)
        {
            if (cotizacion[i].movil > cotizacion[j].movil)
            {
                auxM = cotizacion[i].movil;
                cotizacion[i].movil = cotizacion[j].movil;
                cotizacion[j].movil = auxM;

                auxD = cotizacion[i].distancia;
                cotizacion[i].distancia = cotizacion[j].distancia;
                cotizacion[j].distancia = auxD;

                auxT = cotizacion[i].costo;
                cotizacion[i].costo = cotizacion[j].costo;
                cotizacion[j].costo = auxT;
            }
        }
    }
    listaCotizaciones(cotizacion);
}

void buscarPatente(Moviles remises[])
{

    int res = 0;
    int pos;
    char patenteB[P];

    printf("Ingrese la patente a buscar: \n");
    fflush(stdin);
    gets(patenteB);

    for (int i = 0; i < V; i++)
    {
        if (strcmp(remises[i].patente, patenteB) == 0)
        {
            res = 1;
            pos = i;
        }
    }

    if (res == 0)
    {
        printf("No se encontro la patente buscada! \n");
    }
    else
    {
        printf("Vehiculo encontrado: \n");
        printf("Anio: %d \n", remises[pos].year);
        printf("Modelo: %s\n", remises[pos].marca);

        // Mostrar combustible
        switch (remises[pos].tipoCombustible)
        {
        case 1:
            printf("Combustible: Nafta \n");
            break;
        case 2:
            printf("Combustible: Gas \n");
            break;
        case 3:
            printf("Combustible: GasOil \n");
            break;
        }
    }
}