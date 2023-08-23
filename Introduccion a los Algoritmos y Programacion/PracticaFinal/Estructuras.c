#include <stdio.h>
#include <string.h>
#define TC 20
#define TE 2

typedef struct
{
    int dni;
    char nombre[TC];
    char apellido[TC];
    float sueldo;
    int antiguedad;
} Persona;

void opcion(Persona empleados[]);
int menu();
void seleccion(int op, Persona empleados[]);
void ingresoDatos(Persona empleados[]);
void mostrarDatos(Persona empleados[]);
void totalSueldos(Persona empleados[]);
void ordenarPorDni(Persona empleados[]);
void buscarPorDni(Persona empleados[]);

int main()
{
    // Persona cliente;       // Persona es tipo de dato
    //  Cliente es una variable.
    Persona empleados[TE]; // Arreglo de estructura

    // Menu de opciones
    opcion(empleados);
    return 0;
};

void opcion(Persona empleados[])
{
    int op;
    do
    {
        op = menu();
        seleccion(op, empleados);
    } while (op != 0);
}

int menu()
{
    int op;

    printf("1- Ingreso de datos en el arreglo de estructuras \n ");
    printf("2- Mostrar los datos del arreglo de estructuras \n");
    printf("3- Mostrar la suma total de sueldos \n");
    printf("4- Ordenar por DNI \n");
    printf("5- Buscar empleado por DNI \n");
    printf("0- Salir \n");

    do
    {
        printf("Ingrese la opcion: ");
        scanf("%d", &op);
    } while (op < 0 || op > 7);

    return op;
}

void seleccion(int opcion, Persona empleados[])
{

    switch (opcion)
    {
    case 1:
        ingresoDatos(empleados);
        break;
    case 2:
        mostrarDatos(empleados);
        break;
    case 3:
        totalSueldos(empleados);
        break;
    case 4:
        ordenarPorDni(empleados);
        break;
    case 5:
        buscarPorDni(empleados);
    default:
        break;
    }
}

void ingresoDatos(Persona empleados[])
{
    int doc, antiguedad;
    float sueldo;
    char Nombre[TC], Apellido[TC];

    for (int i = 0; i < TE; i++)
    {

        // Ingreso DNI
        do
        {
            printf("Ingrese el numero de DNI: ");
            scanf("%d", &doc);
        } while (doc < 1000 || doc > 9999);

        empleados[i].dni = doc;

        // Ingreso Nombre
        do
        {
            printf("Ingrese el nombre del empleado: ");
            fflush(stdin);
            gets(Nombre);
        } while (strlen(Nombre) < 1 || strlen(Nombre) > 20);
        strcpy(empleados[i].nombre, Nombre);

        // Ingreso Apellido
        do
        {
            printf("Ingrese el apellido del empleado: ");
            fflush(stdin);
            gets(Apellido);
        } while (strlen(Apellido) < 1 || strlen(Apellido) > 20);
        strcpy(empleados[i].apellido, Apellido);

        // Ingreso Sueldo
        do
        {
            printf("Ingrese el sueldo del empleado: ");
            scanf("%f", &sueldo);
        } while (sueldo < 1000 || sueldo > 1000000);
        empleados[i].sueldo = sueldo;

        // Ingreso antiguedad
        do
        {
            printf("Ingrese la antiguedad del empleado: ");
            scanf("%d", &antiguedad);
        } while (antiguedad < 0 || antiguedad > 82);
        empleados[i].antiguedad = antiguedad;
    }
}

void mostrarDatos(Persona empleados[])
{

    for (int i = 0; i < TE; i++)
    {
        printf("Empleado %d:  DNI: %d Nombre: %s Apellido: %s Sueldo: $%.2f Antiguedad: %d \n", i + 1, empleados[i].dni, empleados[i].nombre, empleados[i].apellido, empleados[i].sueldo, empleados[i].antiguedad);
    }
}

void totalSueldos(Persona empleados[])
{
    float totalSueldos = 0;

    for (int i = 0; i < TE; i++)
    {
        totalSueldos += empleados[i].sueldo;
    }

    printf("Suma total de sueldos: $%.2f \n", totalSueldos);
}

void ordenarPorDni(Persona empleados[])
{
    int aux, auxa;
    float auxf;
    char auxc[TC];

    for (int i = 0; i < TE - 1; i++)
    {
        for (int j = i + 1; i < TE; i++)
        {
            if (empleados[i].dni > empleados[j].dni)
            {
                aux = empleados[i].dni;
                empleados[i].dni = empleados[j].dni;
                empleados[j].dni = aux;

                auxa = empleados[i].antiguedad;
                empleados[i].antiguedad = empleados[j].antiguedad;
                empleados[j].antiguedad = auxa;

                auxf = empleados[i].sueldo;
                empleados[i].sueldo = empleados[j].sueldo;
                empleados[j].sueldo = auxf;

                strcpy(auxc, empleados[i].nombre);
                strcpy(empleados[i].nombre, empleados[j].nombre);
                strcpy(empleados[j].nombre, auxc);

                strcpy(auxc, empleados[i].apellido);
                strcpy(empleados[i].apellido, empleados[j].apellido);
                strcpy(empleados[j].apellido, auxc);
            }
        }
    }
}
void buscarPorDni(Persona empleados[])
{

    int dniB, i = 0;

    printf("Ingrese el DNI a buscar: \n");
    scanf("%d", &dniB);

    while (empleados[i].dni != dniB && i < TE)
    {
        i++;
    }

    if (i == TE)
    {
        printf("No se encontro un empleado con ese DNI! \n");
    }
    else
    {
        printf("El DNI se encontro en la posicion: %d \n", i + 1);

        printf("Empleado %d:  DNI: %d Nombre: %s Apellido: %s Sueldo: $%.2f Antiguedad: %d \n", i + 1, empleados[i].dni, empleados[i].nombre, empleados[i].apellido, empleados[i].sueldo, empleados[i].antiguedad);
    }
}