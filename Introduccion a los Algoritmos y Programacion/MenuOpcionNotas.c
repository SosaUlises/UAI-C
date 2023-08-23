#include <stdio.h>

int main(){

    int opcion;
    do{
        opcion = menu();
        seleccion(opcion);
    }while(opcion != 0);
}

int menu(){
    int op;
    printf("1- mostrar \n");
    printf("2- salir \n");

    do{
        printf("Ingrese la opcion \n");
        scanf("%d", &op); 
    }while(op < 0 || op > 5);

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