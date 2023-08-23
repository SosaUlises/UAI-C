#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define TotalVentas 3

void ingresoDeDatos(int codigosYCantidad[][3], float preciosUnitariosVenta[], char productosVendidos[][50]);
void procesoDeDatos(int codigosYCantidad[][3], float preciosUnitariosVenta[], float promediosPrecios[],int *pIndexMayor,int *pIndexMenor,float *pMayorAux, float *pMenorAux);
void salidaDeDatos(int codigosYCantidad[][3], float preciosUnitariosVenta[],float promediosPrecios[],char productosVendidos[][50],int *pIndexMayor,int *pIndexMenor,float *pMayorAux, float *pMenorAux,char productos[][20]);

void promediosDePrecios(int codigosYCantidad[][3], float preciosUnitariosVenta[], float promediosPrecios[]);
void promedioMayorMenor (float promediosPrecios[],int *pIndexMayor,int *pIndexMenor,float *pMayorAux, float *pMenorAux);

int main(int argc, char *argv[]) {
	
	int codigosYCantidad[TotalVentas][3],indexMayor,indexMenor;
	float preciosUnitariosVenta[TotalVentas],promediosPrecios[4],mayorAux=0,menorAux=100000000;
	char productosVendidos[TotalVentas][50];
	char productos[4][20]={"PAPAS","CEBOLLAS","ZANAHORIAS","ZAPALLITOS"};
	
	int *pIndexMayor=&indexMayor, *pIndexMenor=&indexMenor;
	float *pMayorAux=&mayorAux, *pMenorAux=&menorAux;

	
	ingresoDeDatos(codigosYCantidad, preciosUnitariosVenta, productosVendidos);
	procesoDeDatos(codigosYCantidad, preciosUnitariosVenta, promediosPrecios, pIndexMayor, pIndexMenor, pMayorAux, pMenorAux);
	salidaDeDatos(codigosYCantidad, preciosUnitariosVenta,promediosPrecios,productosVendidos,pIndexMayor, pIndexMenor, pMayorAux, pMenorAux,productos);
	
	return 0;
}

void ingresoDeDatos(int codigosYCantidad[][3], float preciosUnitariosVenta[], char productosVendidos[][50])
{
	int cantidadVentas=0;
	char seguir='s';
	
	do
	{
		do
		{
			printf("Ingrese el codigo de cliente: \n");
			scanf("%d",&codigosYCantidad[cantidadVentas][0]);
		}
		while(codigosYCantidad[cantidadVentas][0]<1000||codigosYCantidad[cantidadVentas][0]>9999);
		
		printf("Ingrese el nombre del producto: \n");
		scanf("%50s",&productosVendidos[cantidadVentas]);
		do
		{
			printf("Ingrese el codigo de producto: (1-Papas - 2-Cebollas - 3-Zanahorias - 4-Zapallitos)\n");
			scanf("%d",&codigosYCantidad[cantidadVentas][1]);
		}
		while(codigosYCantidad[cantidadVentas][1]<1||codigosYCantidad[cantidadVentas][1]>4);

		printf("Ingrese la cantidad vendida del producto: \n");
		scanf("%d",&codigosYCantidad[cantidadVentas][2]);
		printf("Ingrese el precio por unidad del producto: \n");
		scanf("%f",&preciosUnitariosVenta[cantidadVentas]);

		cantidadVentas+=1;
		printf("Desea seguir realizando compras?\n('s' para seguir en caso de no querer cualquier otra tecla)\n");
		scanf(" %c",&seguir);
	}
	while(cantidadVentas<TotalVentas&&seguir=='s'||cantidadVentas<TotalVentas&&seguir=='S');

	printf("\n\nCARGA DE DATOS EXITOSA!\n\n");
	return;
}
void procesoDeDatos(int codigosYCantidad[][3], float preciosUnitariosVenta[],float promediosPrecios[],int *pIndexMayor,int *pIndexMenor,float *pMayorAux, float *pMenorAux)
{
	
	promediosDePrecios(codigosYCantidad, preciosUnitariosVenta, promediosPrecios);
	promedioMayorMenor (promediosPrecios, pIndexMayor, pIndexMenor, pMayorAux, pMenorAux );
	
	return;	
}



void salidaDeDatos(int codigosYCantidad[][3], float preciosUnitariosVenta[],float promediosPrecios[],char productosVendidos[][50], int *pIndexMayor,int *pIndexMenor,float *pMayorAux, float *pMenorAux,char productos[][20])
{
	int i;
	printf("\n\nCOMPRAS REALIZADAS:\n");
	for (i=0;i<TotalVentas;i++)
	{
		printf("NOMBRE DEL PRODUCTO: %s\n",productosVendidos[i]);
		printf("PRECIO UNITARIO DEL PRODUCTO: %.2f\n",preciosUnitariosVenta[i]);
		printf("CODIGO CLIENTE: %d \t CODIGO PRODUCTO: %d \t CANTIDAD DE PRODUCTOS: %d \n",codigosYCantidad[i][0],codigosYCantidad[i][1],codigosYCantidad[i][2]);
	}
	
	printf("\n\nPROMEDIOS DE PRODUCTOS:\n");
	for(i=0;i<4;i++)
	{
		printf("%s - %.2f",productos[i],promediosPrecios[i]);
	}
	
	
	printf("\n\nMAYOR Y MENOR PROMEDIO DE VENTAS:\n");
	switch(*pIndexMayor)
	{
		case 0:
			printf("El mayor promedio es %.2f - PAPAS\n",*pMayorAux);
			break;
		case 1:
			printf("El mayor promedio es %.2f - CEBOLLAS\n",*pMayorAux);
			break;
		case 2:
			printf("El mayor promedio es %.2f - ZANAHORIAS\n",*pMayorAux);
			break;
		case 3:
			printf("El mayor promedio es %.2f - ZAPALLITOS\n",*pMayorAux);
			break;
	}
		switch(*pIndexMenor)
	{
		case 0:
			printf("El menor promedio es %.2f - PAPAS\n",*pMenorAux);
			break;
		case 1:
			printf("El menor promedio es %.2f - CEBOLLAS\n",*pMenorAux);
			break;
		case 2:
			printf("El menor promedio es %.2f - ZANAHORIAS\n",*pMenorAux);
			break;
		case 3:
			printf("El menor promedio es %.2f - ZAPALLITOS\n",*pMenorAux);
			break;
	}
	return;
}

void promediosDePrecios(int codigosYCantidad[][3], float preciosUnitariosVenta[], float promediosPrecios[])
{
	int i,compradoresPapas=0,compradoresCebollas=0,compradoresZanahorias=0,compradoresZapallitos=0;
	float papasPrecio=0,cebollasPrecio=0,zanahoriasPrecio=0,zapallitosPrecio=0;
	for(i=0;i<TotalVentas;i++)
	{
		int opcion=codigosYCantidad[i][1];
		switch(opcion)
		{
			case 1:
				papasPrecio+=preciosUnitariosVenta[i]*(float)codigosYCantidad[i][2];
				compradoresPapas+=1;
				break;
			case 2:
				cebollasPrecio+=preciosUnitariosVenta[i]*(float)codigosYCantidad[i][2];
				compradoresCebollas+=1;
				break;
			case 3:
				zanahoriasPrecio+=preciosUnitariosVenta[i]*(float)codigosYCantidad[i][2];
				compradoresZanahorias+=1;
				break;
			case 4:
				zapallitosPrecio+=preciosUnitariosVenta[i]*(float)codigosYCantidad[i][2];
				compradoresZapallitos+=1;
				break;
		};
	};
	
	promediosPrecios[0]=papasPrecio/(float)compradoresPapas;
	promediosPrecios[1]=cebollasPrecio/(float)compradoresCebollas;
	promediosPrecios[2]=zanahoriasPrecio/(float)compradoresZanahorias;
	promediosPrecios[3]=zapallitosPrecio/(float)compradoresZapallitos;
	
	return;
}

void promedioMayorMenor (float promediosPrecios[],int *pIndexMayor,int *pIndexMenor,float *pMayorAux, float *pMenorAux)
{
	int i;
	for(i=0;i<4;i++)
	{
		if(promediosPrecios[i]>*pMayorAux)
		{
			*pMayorAux=promediosPrecios[i];
			*pIndexMayor=i;
		}
		if(promediosPrecios[i]<*pMenorAux)
		{
			*pMenorAux=promediosPrecios[i];
			*pIndexMenor=i;
		}
	}
	return;
}