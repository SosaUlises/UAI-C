/*

Ejercicio Integrador 2
Pedir al usuario que ingrese dos números (permitir ingresar número con decimales).
Luego presentar el siguiente menú:
1. Informar su suma
2. Informar su resta
3. Informar su multiplicación
4. Informar su división
5. Salir
Seleccione una operación:
Mostrar el resultado de la operación seleccionada.
Si el usuario ingresa la opción 5 el programa debe terminar.
Si el usuario ingresa un valor fuera de rango 1 a 5 sale del programa.

*/

int main(int argc, char *argv[])
{

    float valor1, valor2, resultado;

    int menu;

    printf("Ingrese el primer valor: \n");

    scanf("%f", &valor1);

    printf("Ingrese el segundo valor: \n");

    scanf("%f", &valor2);

    printf("---Menu--- \n");

    printf("1- Informar su suma \n");

    printf("2- Informar su resta \n");

    printf("3- Informar su multiplicacion \n");

    printf("4- Informar su division \n");

    printf("5- Salir \n");

    scanf("%d", &menu);

    switch (menu)
    {

    case 1:
        resultado = valor1 + valor2;

        printf("El resultado de la suma es: %f", resultado);

        break;

    case 2:
        resultado = valor1 - valor2;

        printf("El resultado de la resta es: %f", resultado);

        break;

    case 3:
        resultado = valor1 * valor2;

        printf("El resultado de la multiplicacion es: %f", resultado);

        break;

    case 4:
        resultado = valor1 / valor2;

        printf("El resultado de la division es: %f", resultado);

        break;

    case 5:
        printf("Salio del programa");

        break;

    default:
        printf("Salio del programa");
    };

    return 0;
}