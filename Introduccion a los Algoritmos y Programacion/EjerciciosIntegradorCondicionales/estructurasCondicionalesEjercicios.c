#include <stdio.h>

int main()
{
    
// Ejercicio 1- 	

  int valor1, valor2;
	
	printf("Ingrese el primer valor \n");
	scanf("%d", &valor1);
	printf("Ingrese el segundo valor \n");
	scanf("%d", &valor2);
	
	if(valor1 ==  valor2){ 
	printf("Son iguales los valores");
	};

	return 0;

	
 /* // Ejercicio 2-     
  int valor;  
	printf("Ingresar el valor \n");
	scanf("%d", &valor);
	
	if(valor == 0){
		printf("El numero es 0 \n");
	}else if(valor > 0){
		printf("El numero es positivo \n");
	}else{
		printf("El numero es negativo \n");
	};


// Ejercicio 3-

  int lado1, lado2, lado3;
	
	printf("Ingresar el valor del primer lado \n");
	scanf("%d", &lado1);
	printf("Ingresar el valor del segundo lado \n");
	scanf("%d", &lado2);
	printf("Ingresar el valor del tercer lado \n");
	scanf("%d", &lado3);
	
	if( lado1 == lado2 == lado3){
		printf("Es un triangulo equilatero");
	} else if (lado1 != lado2 && lado1 != lado3 && lado2  != lado3){
		printf("Es un triangulo escaleno");
	} else {
		printf("Es un triangulo isoceles");
	};
	
	return 0;

// Ejercicio 4-     
 
  int valor1, valor2, valor3, sumaValores, promedio;
	
	printf("Ingrese el primer valor \n");
	scanf("%d", &valor1);
	printf("Ingrese el segundo valor \n");
	scanf("%d", &valor2);
	printf("Ingrese el tercer valor \n");
	scanf("%d", &valor3);
	
	sumaValores = valor1 + valor2 + valor3;
	promedio = sumaValores / 3;
	
	if(valor1 > promedio){
		printf("El valor1 es mayor que el promedio");
	}else if(valor2 > promedio){
		printf("El valor 2 es mayor que el promedio");
	}else if(valor3 > promedio){
		printf("El valor 3 es mayor que el promedio");
	}
	
	
	return 0;

	
// Ejercicio 5- 	
  
  int valor1, valor2, valor3, valor4;
	
	printf("Ingrese el valor 1 \n");
	scanf("%d", &valor1);
	printf("Ingrese el valor 2 \n");
	scanf("%d", &valor2);
	printf("Ingrese el valor 3 \n");
	scanf("%d", &valor3);
	printf("Ingrese el valor 4 \n");
	scanf("%d", &valor4);
	
	if( valor1 + valor2 > valor3 + valor4){
		printf("La primer suma es mas grande");
	}else{
		printf("La segunda suma es mas grande");
	}
	
	return 0;

// Ejercicio 6- 	
 
  int edad1,altura1, edad2,altura2;
	
	printf("Ingresar la edad de la primera persona \n");
	scanf("%d", &edad1);
	printf("Ingresar la altura de la primera persona \n");
	scanf("%d", &altura1);
	printf("Ingresar la edad de la segunda persona \n");
	scanf("%d", &edad2);
	printf("Ingresar la altura de la segunda persona \n");
	scanf("%d", &altura2);
	
	if(edad1 > edad2){
		printf("La primera persona es mas grande y tiene una estatura de %d m. ", altura1);
	}else{
		printf("La segunda persona es mas grande y tiene una estatura de %d m.", altura2);
	};

// Ejercicio 7-      
 
  int valorHora, tiempoTrabajado, sueldo;
	
	printf("Ingrese el valor de la hora de trabajo \n");
	scanf("%d", &valorHora);
	printf("Ingrese el tiempo trabajado \n");
	scanf("%d", &tiempoTrabajado);
	
	sueldo = valorHora * tiempoTrabajado;
	
	if(tiempoTrabajado < 50){
		printf("El sueldo es de: $%d \n", sueldo);
	}else if(tiempoTrabajado >= 50 && tiempoTrabajado < 150){
		sueldo = sueldo + 100;
		printf("El sueldo es de: $%d \n", sueldo);
	}else if(tiempoTrabajado >= 150){
		sueldo = sueldo + 200;
		printf("El sueldo es de: $%d \n", sueldo);
	}
	

	return 0;

// Ejercicio 8-

    int dia, mes, anio;
    int es_bisiesto = 0;
    int dia_maximo;

    printf("Ingrese el dia: ");
    scanf("%d", &dia);
    printf("Ingrese el mes: ");
    scanf("%d", &mes);
    printf("Ingrese el anio: ");
    scanf("%d", &anio);

    if (anio % 4 == 0) {
        if (anio % 100 == 0) {
            if (anio % 400 == 0) {
                es_bisiesto = 1;
            }
        } else {
            es_bisiesto = 1;
        }
    }

    if (mes < 1 || mes > 12) {
        printf("Fecha no valida\n");
        return 0;
    }
    switch (mes) {
        case 2:
            if (es_bisiesto) {
                dia_maximo = 29;
            } else {
                dia_maximo = 28;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            dia_maximo = 30;
            break;
        default:
            dia_maximo = 31;
            break;
    }
    if (dia < 1 || dia > dia_maximo) {
        printf("Fecha no valida\n");
        return 0;
    }
    printf("Fecha valida\n");

    return 0;



// Ejercicio 9-

  int sueldo, cat, antiguedad;
	
	printf("Ingrese el sueldo del empleado \n");
	scanf("%d", &sueldo);
	printf("Ingrese la categoria del empleado \n");
	scanf("%d", &cat);
	printf("Ingrese la antiguedad del empleado \n");
	scanf("%d", &antiguedad);
	
	if(cat == 1){
		sueldo = sueldo + antiguedad * 50;
		printf("El sueldo es de: $%d", sueldo);
	}else{
		printf("El sueldo es de: $%d", sueldo);
	};
	
	return 0;


// Ejercicio 10-    	

  int sueldo,cat, antiguedad;
	
	printf("Ingrese el sueldo del empleado \n");
	scanf("%d", &sueldo);
	printf("Ingrese la categoria del empleado \n");
	scanf("%d", &cat);
	printf("Ingrese la antiguedad del empleado \n");
	scanf("%d", &antiguedad);
	
	if(cat == 1){
		sueldo = sueldo + antiguedad * 50;
	};
	
	if(antiguedad > 5){
		printf("Sueldo del empleado: $%d", sueldo);
	};
	
	return 0;


// Ejercicio 11-

  int horasTrabajadas, cat, sueldo;
	
	printf("Ingrese la cantidad de horas trabajadas por el empleado \n");
	scanf("%d", &horasTrabajadas);
	
	printf("Ingrese la categoria del empleado \n");
	scanf("%d", &cat);
	switch(cat){
		case 1: sueldo = horasTrabajadas * 50;
		break;
		case 2: sueldo = horasTrabajadas * 70;
		break;
		case 3: sueldo = horasTrabajadas * 80;
		break;
		default: printf("Categoria no disponible \n");
	}
	printf("El sueldo del empleado es de: $%d \n", sueldo);
	

	return 0;

   */
}
