#include <stdio.h>

unsigned int Factorial(unsigned int n);

int main()
{ 
 int n;
 unsigned int fact;

 printf("*Escriba un numero natural para el calculo de su factorial:\n\n\n");
 scanf("%u", &n);

 fact = Factorial(n);

 printf("el factorial de %i! es: %i ",n,fact);
 printf("\n\n\n");


	return 0;
}
unsigned int Factorial(unsigned int n){

	 int producto=1;
     int contador=2;

	while(contador <= n)
    {
    producto = producto * contador;
    contador = contador +1;	
    }
    return producto;
}