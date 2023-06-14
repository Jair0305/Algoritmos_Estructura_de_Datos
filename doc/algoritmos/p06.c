#include <stdio.h>//Agregamos la librería stdio.h que contiene las funciones básicas del lenguaje de programación C.


unsigned int Fibonacci(unsigned int n);//Aqui Se ponen los prototipos de las funciones que vayamos utilizando.

int main()//Inicia función Principal
{
	unsigned int N,n;//Declaracion de las variables.
    printf("Calculo de los primeros N numeros de la serie fibonacci\n");//Aqui solo se imprime al usuario la funcion del codigo
    printf("Escriba un numero natural\n");//pedimos un numero mediante un texto que se muestra al usuario.
    scanf("%u",&N);//guardamos el numero en la variable ya decalrada anteriormente "N".
	for(n=0; n<=N; n++)//Iniciamos un ciclo for con el contador de n que ira incrementando hasta ser igual que N(valor escrito por el usuario).
	{
		printf("%i ",Fibonacci(n));//Cada numero de este contador, se le aplica la funcion Fibonacci para luego imprimirlo en pantalla.
	}
	printf("\n");//Aqui solo se imprime un salto de linea.
	return 0;//se retorna el valor de 0 para verificar que haya finalizado sin problemas
}
unsigned int Fibonacci(unsigned int n)//Aqui comienza la funcion "Fibonacci".
{
	unsigned int fn;//Aqui se declara la variable local de la funcion.

	if(n==0) return 0;//En este problema en particular tenemos dos casos base.
	if(n==1) return 1;//Donde si n=0, se retorna 0 y si n=1, se retorna 1.
    
    fn = Fibonacci(n-1)+Fibonacci(n-2);//De no ser 0, ni 1, pero mayor a estos, y para seguir con la recursividad, aplicamos la funcion Fibonacci a n-1 y n-2 y lo guardamos en fn
    return fn;//la funcion retorna el valor de fn.
}