#include <stdio.h>//Agregamos la librería stdio.h que contiene las funciones básicas del lenguaje de programación C.
#include <math.h>//Se agrega esta librería que nos permite hacer ciertas operaciones como elevar al cuadrado o sacar raices.

unsigned int Fn(unsigned int n);//Aquí se agregan los prototipos de las funciones extra que utilices.
int main()//Inicia función Principal.
{
	unsigned int N,n=0,fb,cont;//Declaracion de las variables globales.
	printf("Escriba un numero natural para mostrar la secuencia de Fibonacci\n");//pedimos un numero mediante un texto que se muestra al usuario.
	scanf("%u",&N);//guardamos el numero en la variable "N".
    
    printf("\n La secuencia de los primeros %i numeros de fibonacci es: ",N);
	for(cont=0;cont<N;cont=cont+1)//Se abre un contador en un ciclo for para aplicar la serie fibonacci hasta llegar al número de números que introduce el usuario.
	   {
	   	fb=Fn(n);//Se aplica la funcion "Fn" a la variable n y se guarda en fb.
	   	printf("%i, ",fb);//Aquí se muestra el resultado de ka serie fibonacci.
	   	n = n+1;
	   }	

	printf("\n");//Aquí solo se imprime un salto de línea.
	return 0;//se retorna el valor de 0 para verificar que haya finalizado sin problemas
}
unsigned int Fn(unsigned int n)//Se abre una nueva función llamada "Fn".
{
	unsigned int fn;
	float r;//Se declaran las variables locales.
	r =(1+sqrt(5))/2;
    
    fn=(pow(r,n)-pow((1-r),n)) / sqrt(5);//Se hacen las operaciones que corresponden a la formula de la serie fibonacci
    return fn;//La función retorna el valor de fn.
}