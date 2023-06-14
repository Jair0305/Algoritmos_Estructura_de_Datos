//Agregamos las librerias necesarias para las funciones que necesitamos
#include <stdio.h>
#include <stdlib.h>

//Aqui ponemos los prototipos de las funciones utilizadas
void Ordenamiento(int *dat, unsigned int Ne);

//Inicializamos la funcion principal 
int main()
{
	//Declaracion de variables de esta funcion
	int Datos[]={3,8,1,-5,9,23,5,2,33,0};
	int i;
	int Ne = 10;
    
    //Se imprimen los datos 
	printf("\n Los datos: ");
	for(i=0; i<Ne; i++)
		printf("\n%i",Datos[i]);
	//Se aplica la funcion de ordenamiento
	Ordenamiento(Datos,Ne);
	printf("\n Los datos ordenados de menor a mayor");
	//Se imprimen los datos 
	for(i=0; i<Ne; i++)
		printf("\n%i",Datos[i]);

	printf("\nhola");
	return 0;
}

//Se inicializa la funcion Ordenamiento
void Ordenamiento(int *dat, unsigned int Ne)
{
	//Declaracion de las variables de la funcion
	unsigned int k,j;
	int aux;
    

    for(j=0; j<Ne; j++)
	for(k=0; k<(Ne-1); k++)
	{
		//comparacion de pares
		if(dat[k]>dat[k+1])
		{
			//intercambio de los datos
			aux = dat[k];
			dat[k]=dat[k+1];
			dat[k+1]=aux;
		}
	}
}