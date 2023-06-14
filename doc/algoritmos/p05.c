#include <stdio.h>//Agregamos la librería stdio.h que contiene las funciones básicas del lenguaje de programación C.

unsigned int Factorial(unsigned int N);//Aqui Se ponen los prototipos de las funciones que vayamos utilizando.

int main()//Inicia función Principal
{
	unsigned int N,fact;//Declaracion de las variables.

	printf("\nDigite un numero natural");//pedimos un numero mediante un texto que se muestra al usuario.
	scanf("%u",&N);//guardamos el numero en la variable ya decalrada anteriormente "N".

	fact = Factorial(N);//Aplicamos la funcion "Factorial" al numero N y lo guardamos en la variable fact.

	printf("El resultado del Factorial de %i es: %i",N,fact);//Imprimimos el resultado del factorial.
	printf("\n");//Aqui solo se imprime un salto de linea.

	return 0;//se retorna el valor de 0 para verificar que haya finalizado sin problemas
}

unsigned int Factorial(unsigned int N)//Aqui comienza la funcion "Factorial".
{
	unsigned int productos;//Aqui se declaran las o en este caso la variable local de la funcion.
	if(N==1) return 1;//Para evitar un bucle infinito, implementamos el caso base, que nos dice que si N es igual a 1, retorna 1.	
	return N*Factorial(N-1);//De no ser N=1, aplicamos la misma funcion a N-1 para seguir la recursividad y retornamos el resultado.
}