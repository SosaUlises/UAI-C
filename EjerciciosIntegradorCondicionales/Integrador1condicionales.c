/*


Ejercicio Integrador 1
La compañía que gestiona la autopista ha decidido cambiar las tarifas de peaje. Estas tarifas
dependen de:
● Tipo de vehículo (camión, automóvil o moto) que desee utilizar la autopista
● Número de pasajeros que lleve
● Tipo horario del día:
Horario A: horas de “Alta” congestión:
● Los automóviles con tres pasajeros o más no pagan peaje
● Los camiones pagan $300
● Las motos pagan $100
Horario B: horas de “Baja” congestión:
● Los automóviles pagan $150
● Los camiones pagan $200
● Las motos no pagan peaje
En este horario la tarifa es independientemente del número de pasajeros.
Escriba un programa que leyendo el tipo de vehículo, tipo de horario de congestión alta o baja
y el número de pasajeros, calcule la tarifa que le debe cobrar a un vehículo. Validar que el tipo
de vehículo sea uno de los mencionados y que el número de pasajeros no sea mayor a 5


*/

int main(int argc, char *argv[])
{

    int tipoVehiculo;

    int horario;

    int pasajero;

    printf("Ingresar el tipo de vehiculo:\n (1)Automovil \n (2)Camion \n (3)Moto \n");

    scanf("%d", &tipoVehiculo);

    printf("Ingresar el horario: \n Alta (1) \n Baja (2) \n");

    scanf("%d", &horario);

    printf("Ingresar la cantidad de pasajeros: \n");

    scanf("%d", &pasajero);

    if (tipoVehiculo != 1 && tipoVehiculo != 2 && tipoVehiculo != 3)
    {

        printf("Vehiculo no valido!");

        return 0;
    }
    else if (pasajero > 5)
    {

        printf("No pueden ir mas de 5 pasajeros");

        return 0;
    }
    else if (horario != 1 && horario != 2)
    {

        printf("Horario incorrecto");

        return 0;
    };

    if (horario == 1)
    {

        if (tipoVehiculo == 1 && pasajero >= 3)
        {

            printf("No paga peaje");
        }
        else if (tipoVehiculo == 1 && pasajero < 3 && pasajero >= 1)
        {

            printf("Automovil paga $200");
        }
        else if (tipoVehiculo == 2)
        {

            printf("Camion paga $300");
        }
        else
        {

            printf("Moto paga $100");
        };
    }
    else
    {

        if (tipoVehiculo == 1)
        {

            printf("Automovil paga $150");
        }
        else if (tipoVehiculo == 2)
        {

            printf("Camion paga $200");
        }
        else
        {

            printf("Moto no paga peaje");
        };
    };

    return 0;
}