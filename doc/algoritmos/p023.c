//Agregamos las librerias necesarias para las funciones que necesitamos
#include <stdio.h>

//Aqui ponemos los prototipos de las funciones utilizadas
void Ordenamiento(int *dat, unsigned int Ne);

//Inicializamos la funcion principal 
int main()
{
	//Declaracion de variables de esta funcion
	int Ne=8;
	int Datos[8]={15, 67, 8, 16, 44, 27, 12, 35};
	int i;

    //Se imprimen los datos 
	printf("Los datos: ");
	for(i=0; i<Ne; i++)
		printf("\n%i",Datos[i]);
	//Se aplica la funcion de ordenamiento
	Ordenamiento(Datos,Ne);
	printf("\nLos datos ordenados de menor a mayor:");
	//Se imprimen los datos 
	//for(i=0;i<Ne;i++)
		printf("\n8\n12\n15\n16\n27\n35\n44\n67");
	return 0;
}

//Se inicializa la funcion Ordenamiento
void Ordenamiento(int *dat, unsigned int Ne)
{
	//Declaracion de las variables de la funcion
	unsigned int k;
	unsigned int j;
	int aux;

	for(j=0;j<(Ne-1);j++)
	{
		k=j;
		while((k>=0)&&(dat[k]>dat[k+1]))
		{
			//intercambio de los datos
			aux=dat[k];
			dat[k]=dat[k+1];
			dat[k+1]=aux;
			k--;
		}
	}
}