#include <stdio.h>

int menu();
void seleccion(int op, int Numeros[], int *suma, int CopiaNumeros[]);
void ingresoDatos(int Numeros[]);
void mostrarDatos(int Numeros[]);
int sumarDatos(int Numeros[], int *suma);
float promedio(int *suma);
void maxMin(int Numeros[]);
void copiarVectores(int Numeros[], int CopiaNumeros[]);
void ordenarArray(int Numeros[], int CopiaNumeros[]);
void buscarValor(int Numeros[]);
#define T 3

int main()
{
    int op;
    int Numeros[T];
    int CopiaNumeros[T];
    int suma;
    // Menu de opciones
    do
    {
        op = menu();
        seleccion(op, Numeros, &suma, CopiaNumeros);
    } while (op != 0);

    return 0;
}

int menu()
{
    int op;

    printf("1- Ingreso de datos en el arreglo  \n");
    printf("2- Mostrar los datos del arreglo \n");
    printf("3- Sumar y mostrar los datos del arreglo \n");
    printf("4- Calcular el promedio de los datos del arreglo \n");
    printf("5- Mostrar el maximo y minimo valor \n");
    printf("6- Copiar un vector en otro y mostrarlos \n");
    printf("7- Ordenamiento del arreglo \n");
    printf("8- Buscar un valor en el Array \n");
    printf("0- Salir \n");

    do
    {
        printf("Ingrese la opcion: \n");
        scanf("%d", &op);
    } while (op < 0 || op > 9);

    return op;
}

void seleccion(int opcion, int Numeros[], int *suma, int CopiaNumeros[])
{

    switch (opcion)
    {
    case 1:
        ingresoDatos(Numeros);
        break;
    case 2:
        mostrarDatos(Numeros);
        break;
    case 3:
        sumarDatos(Numeros, suma);
        break;
    case 4:
        printf("Promedio total: %.2f \n", promedio(suma));
        break;
    case 5:
        maxMin(Numeros);
        break;
    case 6:
        copiarVectores(Numeros, CopiaNumeros);
        break;
    case 7:
        ordenarArray(Numeros, CopiaNumeros);
        break;
    case 8:
        buscarValor(Numeros);
        break;
    default:
        break;
    }
}

void ingresoDatos(int Numeros[])
{
    int n;
    printf("INGRESO: \n");

    for (int i = 0; i < T; i++)
    {
        printf("Ingrese el numero: \n");
        scanf("%d", &n);
        Numeros[i] = n;
    }
}

void mostrarDatos(int Numeros[])
{
    printf("Mostrar lista de datos: \n");

    for (int i = 0; i < T; i++)
    {
        printf("%d \t", Numeros[i]);
    }
}

int sumarDatos(int Numeros[], int *suma)
{
    int sum = 0;

    for (int i = 0; i < T; i++)
    {
        sum += Numeros[i];
    }
    *suma = sum;
    return printf("Suma total de numeros: %d \n", sum);
}

float promedio(int *suma)
{
    float promedio;

    promedio = (*suma / T);

    return promedio;
}

void maxMin(int Numeros[])
{

    int max = Numeros[0];
    int min = Numeros[0];

    for (int i = 0; i < T; i++)
    {
        if (Numeros[i] >= max)
        {
            max = Numeros[i];
        }

        if (Numeros[i] <= min)
        {
            min = Numeros[i];
        }
    }
    printf("Maximo numero: %d \n", max);
    printf("Minimo numeros: %d \n", min);
}

void copiarVectores(int Numeros[], int CopiaNumeros[])
{

    for (int i = 0; i < T; i++)
    {
        CopiaNumeros[i] = Numeros[i]; // Para hacer una copia inversa, el primer valor se copiara en el ultimo indice
                                      //  CopiaNumeros[ T - 1 - i] = Numeros[i];
    }

    printf("Mostrando los dos arreglos: \n");
    for (int i = 0; i < T; i++)
    {
        printf("Original: %d \t", Numeros[i]);
        printf("Copia: %d \t", CopiaNumeros[i]);
        printf("\n");
    }

    return;
}

void ordenarArray(int Numeros[], int CopiaNumeros[])
{
    int aux;
    // Copia de arreglo
    for (int i = 0; i < T; i++)
    {
        CopiaNumeros[i] = Numeros[i];
    }
    // Ordenamos
    for (int i = 0; i < T - 1; i++)
    {
        for (int j = i + 1; j < T; j++)
        {
            if (CopiaNumeros[i] > CopiaNumeros[j])
            {
                aux = CopiaNumeros[i];
                CopiaNumeros[i] = CopiaNumeros[j];
                CopiaNumeros[j] = aux;
            }
        }
    }
    printf("Mostrar arreglo ordenado: \n");
    for (int i = 0; i < T; i++)
    {
        printf("%d \t", CopiaNumeros[i]);
    }
}

void buscarValor(int Numeros[]){

    int valor, i=0;

    printf("Ingrese el numero a buscar: \n");
    scanf("%d", &valor);

    while (Numeros[i] != valor && i < T)
    {
        i++;
    }
    
    if( i == T){
        printf("No se encontro el numero! \n");
    }
    else{
        printf("El numero se encontro en la posicion: %d \n", i+1);
    }

}