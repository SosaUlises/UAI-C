/*

Ejercicio Integrador 3
Realizar un programa que permita registrar los datos para una venta de $4600.
Para ello, se le pedirá al usuario que ingrese su DNI, validar que dicho número no sea menor
que 1000000 ni mayor que 99999999.
Luego, requerir al usuario que seleccione el medio de pago:
1-Efectivo, 2-Tarjeta de crédito, si selecciona tarjeta, pedir que ingrese una opción de las
siguientes: 1-Visa, 2-American Express, 3-Mercado Pago, 4-Cabal.
Además, requerir la cantidad de cuotas en las que abonará (1, 3, 6 o 12).
El interés por pagar en cuotas será de: 0 interés para efectivo o 1 cuota, 10% para 3 cuotas y
20% para 6 y 30% para 12 cuotas.
Validar que todos los datos ingresados por el usuario sean correctos, en caso contrario
informar la situación y finalizar programa.
Por último, presentar un resumen de la operación, por ejemplo:
DNI: 38.456.123
Medio de pago: Tarjeta de crédito
Tarjeta: Cabal
Cuotas: 3 Total: $478

*/

int main(int argc, char *argv[])
{

    int dni, medioPago, monto = 4600, opcionTarjeta, cantidadCuotas;

    printf("Ingrese su numero del documento de identidad \n");

    scanf("%d", &dni);

    if (dni < 1000000 || dni > 99999999)
    {

        printf("Documento de identidad no valido! \n");

        return 0;
    }

    printf("Medio de Pago \n");

    printf("1- Efectivo \n");

    printf("2- Tarjeta de credito \n");

    scanf("%d", &medioPago);

    if (medioPago == 2)
    {

        printf("Seleccione opcion \n");

        printf("1- Visa \n");

        printf("2- American Express \n");

        printf("3- Mercado Pago \n");

        printf("4- Cabal \n");

        scanf("%d", &opcionTarjeta);

        printf("Ingrese la cantidad de cuotas: \n");

        scanf("%d", &cantidadCuotas);

        switch (cantidadCuotas)
        {

        case 1:
            monto = monto;

            break;

        case 3:
            monto = monto * 0.10;

            break;

        case 6:
            monto = monto * 0.20;

            break;

        case 12:
            monto = monto * 0.30;

            break;

        default:
            printf("Cuotas no validas");
            return 0;
        }
    }

    printf("--Resumen-- \n");

    printf("DNI: %d \n", dni);

    if (medioPago == 1)
    {

        printf("Medio de pago: Efectivo \n");
    }
    else
    {

        printf("Medio de pago: Tarjeta de credito \n");
    };

    if (opcionTarjeta == 1)
    {

        printf("Tarjeta: Visa \n");
    }
    else if (opcionTarjeta == 2)
    {

        printf("Tarjeta: American Express \n");
    }
    else if (opcionTarjeta == 3)
    {

        printf("Tarjeta: Mercado Pago \n");
    }
    else if (opcionTarjeta == 4)
    {

        printf("Tarjeta: Cabal \n");
    }

    printf("Cuotas: %d \n", cantidadCuotas);

    printf("Total: $%d \n", monto);

    return 0;
}