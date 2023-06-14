//Agregamos las librerias necesarias para las funciones que necesitamos
#include<stdio.h>

//Aqui ponemos los prototipos de las funciones utilizadas
void Ordenar(int *dat, unsigned int Ne);

//Inicializamos la funcion principal 
int main()
{
	//Declaracion de variables de esta funcion
	int datos[10]={3,8,1,-5,9,23,5,2,33,0};
	int k, Ne=10;

	printf("\nLos datos son: ");
	//Se imprimen los datos 
	for(k=0; k<Ne; k++)
		printf("\n%i", datos[k]);
	//Se aplica la funcion de ordenamiento
	Ordenar(datos, Ne);

	printf("\nLos datos ordenados de menor a mayor: ");
	//Se imprimen los datos 
	for(k=0; k<Ne; k++)
		printf("\n%i", datos[k]);

	return 0;
}
//Se inicializa la funcion Ordenamiento
void Ordenar(int *dat, unsigned int Ne)
{
	//Declaracion de las variables de la funcion
	unsigned int k, j;
	int id_menor, aux;

	for(j=0; j<(Ne-1); j++) //Ciclo para buscar el menor de los números
		{
			id_menor=j;
			for(k=j+1; k<Ne; k++)
				if(dat[id_menor]>dat[k])
				{
				id_menor = k; //se hace la seleccion directa
			}
			aux=dat[j];
			dat[j]=dat[id_menor];
			dat[id_menor]=aux;
		}
}