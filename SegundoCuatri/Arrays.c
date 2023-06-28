
#include <stdio.h>
#define TAM 100


int main(){

float Notas[TAM];
float nota, maximo=0, minimo=100, promedio=0, acum=0;
int i=0,cant=0;


// Carga de notas
nota = 1; // Para que pase al while
while ( nota != 0 && i < TAM){

    do{
        printf("Ingrese la nota %d: \n", i+1);
        scanf("%f", &nota);

    }while(nota < 0 || nota > 10);

    Notas[i] = nota;
    i++;
}
cant = i - 1;

// Suma de notas y promedio

for(int i=0; i < cant; i++){
    acum += Notas[i];
}
promedio = acum / cant;
printf("Promedio de las notas: %.2f \n", promedio);

// Buscamos maximos y minimos

for(int i=0; i < cant; i++){

    if(Notas[i] > maximo){
        maximo = Notas[i];
    }else
    if(Notas[i] < minimo){
        minimo = Notas[i];
    }
}
printf("Nota maxima: %.2f \n", maximo);
printf("Nota minima: %.2f \n", minimo);

}