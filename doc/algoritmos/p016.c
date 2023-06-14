#include <stdio.h>
#include <stdlib.h>

//Aqui van los prototipos de las funciones
int* CapturaVector(unsigned int Ne);
void ImprimeVector(int* ptr, unsigned int Ne);
float PromedioVector(int* ptr, unsigned int Ne);
int* CopiaVectorInvertido(int* ptr, unsigned int Ne);

//Se inicia la funcion principal
int main()
{
	//Se declaran las variables locales de la función principal
	unsigned int N;
	int *ptr;
	float prom;
	int *vi;

    //Se le pide la cantidad de numeros que tendra el vector
	printf("Escriba la cantidad de numeros enteros a capturar: ");
	//Se guarda en la variable N
	scanf("%u",&N);
	//Se utilizan las funciones, para la captura, impresion
	//promedio y la funcion d einvertir el vector
	ptr=CapturaVector(N);
	ImprimeVector(ptr,N);
	prom=PromedioVector(ptr,N);
	//Con la variable vi, llamamos a la funcion de la copia del vector invertido
	vi = CopiaVectorInvertido(ptr,N);
	//Luego la imprimimos con la misma funcion que imprimimos el vector hace un momento
	ImprimeVector(vi,N);

    //Se libera la memoria
	free(ptr);
	free(vi);
	printf("\n El promedio del vector es: %f",prom);
    
    //Un salto de linea
    printf("\n");
    //Al terminar, si no ha habido errores, retorna un 0
	return 0;
}

//Se inicia la funcion agregada
int* CopiaVectorInvertido(int* ptr, unsigned int Ne)
{
	//declaramos al variable *P
	int *p;
    

	p=(int*)malloc(Ne * sizeof(int));

    //Se inciia el ciclo for que nos permite girar los valores del vector
	for(unsigned int k=0;k<Ne;k++)
	{
		*(p+k) = *(ptr+(Ne-(k+1)));
	}
    
    //Se retorna la variable p
	return p;
}

//Funcion que con el que captura el vector
int* CapturaVector(unsigned int Ne)
{
	//Se declaran las variables locales de esta funcion
	int* puntero;
	unsigned int k;

	puntero = (int *)malloc(Ne*sizeof(int));

    //Validar si la memoria fue reservada
	if(puntero==NULL)
	{
		printf("Error al reservar la memoria para almacenar los datos");
		exit(0);
	}
    
    //En este ciclo for se repasan el numero de numeros que tendra el vector
	for(k=0;k<Ne;k++)
	{
		//Se piden los numeros del vector al usuario y los guarda en puntero
		printf("Entero %i: ",k+1);
		scanf("%i",puntero+k);
	}
	//se retorna la variable puntero
	return puntero;
}

//Esta es la funcion para imprimir los vectores
void ImprimeVector(int* ptr, unsigned int Ne)
{
	//declaracion de la variable local
	unsigned int k;


	printf("\n{ ");
	//hace un repaso sobre los numeros del vector apra luego imprimirlos
	for(k=0;k<Ne;k++)
		printf("%i ",*(ptr+k));
	printf("}");
}

//Esta es la funcion para sacar el promedio del vector
float PromedioVector(int* ptr, unsigned int Ne)
{
	//variables locales de la funcion
	unsigned int k;
	float result;
	int sum=0;

	//Se hace un recuento de los numeros del vector
	for(k=0; k<Ne; k++)
		//los suma
		sum +=*(ptr+k);
	//guarda en la variable result la division entre sum y Ne
	result=(float)sum/Ne;
	//Da el promedio y retorna la variable result
	return result;
}