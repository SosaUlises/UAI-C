#include <stdio.h>

int menu();
void seleccion(int op);

int main(){
int op;
    
    do
    {
        op = menu();
        seleccion(op);
    } while (op != 0);
    
}

int menu(){
    int op;

    printf("Opcion 1 \n");
    printf("Opcion 2 \n");
    printf("Opcion 3 \n");
    printf("Opcion 0 SALIR \n");

    do
    {
        printf("Ingrese la opcion: \n");
        scanf("%d", &op);
    } while ( op < 0 || op > 3);

    return op;
}

void seleccion(opcion){

    switch (opcion)
    {
    case 1: // llamado de funtions
        break;
    
    default:
        break;
    }
}