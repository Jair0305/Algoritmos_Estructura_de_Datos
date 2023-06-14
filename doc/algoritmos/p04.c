#include <stdio.h>//Agregamos la librería stdio.h que contiene las funciones básicas del lenguaje de programación C.

unsigned int Sumatoria(unsigned int N);//Aqui Se ponen los prototipos de las funciones que vayamos utilizando.

int main()//Inicia función Principal.
{
	unsigned int N,suma; //Declaracion de las variables.

	printf("\nDigite un numero natural");//pedimos un numero mediante un texto que se muestra al usuario.
	scanf("%u",&N);//guardamos el numero en la variable "N".

	suma = Sumatoria(N);//Aplicamos la funcion "Sumatoria" al numero N y lo guardamos en suma.

	printf("El resultado de la sumatoria de los primeros %i numeros es: %i",N,suma);//Imprimimos el resultado de la suma.
	printf("\n");//Aqui solo se imprime un salto de linea.

	return 0;//se retorna el valor de 0 para verificar que haya finalizado sin problemas.
}

unsigned int Sumatoria(unsigned int N)//Aqui comienza la funcion "Sumatoria".
{
	unsigned int suma;//Aqui se declaran las o en este caso la variable local de la funcion.

	if(N==1)//
		return 1;//Para evitar un bucle infinito, implementamos el caso base, que nos dice que si N es igual a 1, retorna 1.

	suma = N+Sumatoria(N-1);//Aqui llamamos a la misma funcion de donde estamos trabjando para seguir la recursividad.
	return suma;//Al final de la suma, retornamos ese valor.
}