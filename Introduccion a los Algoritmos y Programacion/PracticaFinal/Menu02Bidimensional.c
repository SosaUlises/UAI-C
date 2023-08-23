#include <stdio.h>
#define FI 3
#define CO 4

int menu();
void seleccion(int op, int Matriz01[][CO], int suma[], int CopiaMatriz01[][CO]);
void ingresoDatos(int Matriz01[][CO]);
void mostrarDatos(int Matriz01[][CO]);
void sumarDatos(int Matriz01[][CO], int suma[]);
void promedio(int suma[]);
void maxMin(int Matriz01[][CO]);
void copiarMatrices(int Matriz01[][CO], int CopiaMatriz01[][CO]);
void ordenarMatrizPorFila(int Matriz01[][CO]);
void buscarValor(int Matriz01[][CO]);

int main()
{
    int op;
    int Matriz01[FI][CO];
    int CopiaMatriz01[FI][CO];
    int suma[FI];
    // Menu de opciones
    do
    {
        op = menu();
        seleccion(op, Matriz01, suma, CopiaMatriz01);
    } while (op != 0);

    return 0;
}

int menu()
{
    int op;

    printf("1- Ingreso de datos en la matriz \n");
    printf("2- Mostrar los datos de la matriz \n");
    printf("3- Sumar los datos de cada fila de la matriz \n");
    printf("4- Calcular el promedio por filas de la matriz \n");
    printf("5- Mostrar el maximo y minimo valor de toda la matriz \n");
    printf("6- Copiar la matriz en otra y mostrar ambas \n");
    printf("7- Ordenamiento de la matriz por una fila determinada \n");
    printf("8- Buscar un valor dentro de la matriz \n");
    printf("0- Salir \n");

    do
    {
        printf("Ingrese la opcion: \n");
        scanf("%d", &op);
    } while (op < 0 || op > 9);

    return op;
}

void seleccion(int opcion, int Matriz01[][CO], int suma[], int CopiaMatriz01[][CO])
{

    switch (opcion)
    {
    case 1:
        ingresoDatos(Matriz01);
        break;
    case 2:
        mostrarDatos(Matriz01);
        break;
    case 3:
        sumarDatos(Matriz01, suma);
        break;
    case 4:
        promedio(suma);
        break;
    case 5:
        maxMin(Matriz01);
        break;
    case 6:
        copiarMatrices(Matriz01, CopiaMatriz01);
        break;
    case 7:
        ordenarMatrizPorFila(Matriz01);
        break;
    case 8:
        buscarValor(Matriz01);
        break;
    default:
        break;
    }
}

void ingresoDatos(int Matriz01[][CO])
{
    int n;
    printf("INGRESO: \n");

    for (int i = 0; i < FI; i++)
    {
        printf("Fila %d: \n", i + 1);
        for (int j = 0; j < CO; j++)
        {
            printf("Ingrese un valor: \n");
            scanf("%d", &n);

            Matriz01[i][j] = n;
        }
    }
}

void mostrarDatos(int Matriz01[][CO])
{
    printf("Mostrar lista de datos: \n");

    for (int i = 0; i < FI; i++)
    {
        for (int j = 0; j < CO; j++)
        {
            printf("%d \t", Matriz01[i][j]);
        }
        printf("\n");
    }
}

void sumarDatos(int Matriz01[][CO], int suma[])
{
    int acum;

    for (int i = 0; i < FI; i++)
    {
        acum = 0;
        for (int j = 0; j < CO; j++)
        {
            acum += Matriz01[i][j];
        }

        suma[i] = acum;
    }
}

void promedio(int suma[])
{
    float promedio;

    for (int i = 0; i < FI; i++)
    {
        promedio = (suma[i] / CO);
        printf("Promedio fila %d: %.2f \n", i + 1, promedio);
    }
}

void maxMin(int Matriz01[][CO])
{
    int min = Matriz01[0][0];
    int max = Matriz01[0][0];

    for (int i = 0; i < FI; i++)
    {
        for (int j = 0; j < CO; j++)
        {
            if (Matriz01[i][j] < min)
            {
                min = Matriz01[i][j];
            }
            if (Matriz01[i][j] > max)
            {
                max = Matriz01[i][j];
            }
        }
    }

    printf("Valor maximo de la matriz: %d \n", max);
    printf("Valor minimo de la matriz: %d \n", min);
}

void copiarMatrices(int Matriz01[][CO], int CopiaMatriz01[][CO])
{

    for (int i = 0; i < FI; i++)
    {
        for (int j = 0; j < CO; j++)
        {
            CopiaMatriz01[i][j] = Matriz01[i][j];
        }
    }

    printf("Mostrando la Matriz Copiada: \n");
    for (int i = 0; i < FI; i++)
    {
        for (int j = 0; j < CO; j++)
        {
            printf("%d \t", CopiaMatriz01[i][j]);
        }
        printf("\n");
    }

    return;
}

void ordenarMatrizPorFila(int Matriz01[][CO])
{
    int fila, aux;
    do
    {
        printf("Ingrese la fila a modificar: \n");
        scanf("%d", &fila);
    } while (fila < 1 || fila > FI);

    fila--; // para usar el indice

    for (int i = 0; i < CO - 1; i++) // 3 filas: 1,2,3  indices: 0,1,2
    {
        for (int j = i + 1; j < CO; j++)
        {
            if (Matriz01[fila][i] > Matriz01[fila][j])
            {
                for (int k = 0; k < FI; k++) // Acomoda una fila determinada ascendentemente y los demas valores de la columna la acompañan.
                {
                    aux = Matriz01[k][i];
                    Matriz01[k][i] = Matriz01[k][j];
                    Matriz01[k][j] = aux;
                }
            }
        }
    }
}

void buscarValor(int Matriz01[][CO])
{

    int valor, fil = 0, col = 0, bandera=-1;

    printf("Ingrese el numero a buscar: \n");
    scanf("%d", &valor);

    for (int i = 0; i < FI; i++)
    {
        for (int j = 0; j < CO; j++)
        {
            if (Matriz01[i][j] == valor)
            {
                bandera = Matriz01[i][j];
                fil = i;
                col = j;
            }
            
        }
        
    }

    if (bandera == -1)
    {
        printf("No se encontro el numero! \n");
    }
    else
    {
        printf("Se encontro el numero en la Fila %d, Columna %d \n", fil+1, col+1);
    }
}