#include <stdio.h>//Agregamos la librería stdio.h que contiene las funciones básicas del lenguaje de programación C.

unsigned int Factorial(unsigned int n);//Aquí se agregan los prototipos de las funciones extra que utilices.

int main()//Inicia función Principal.
{ 
 int n;
 unsigned int fact;//Declaracion de las variables globales.

 printf("*Escriba un numero natural para el calculo de su factorial:\n\n\n");//pedimos un numero mediante un texto que se muestra al usuario.
 scanf("%u", &n);//guardamos el numero en la variable "n".

 fact = Factorial(n); //Aplicamos la función "Factorial"(que veremos más abajo) al número que nos de el usuario y lo guardamos en la variable "fact".

 printf("el factorial de %i! es: %i ",n,fact);//Aquí le mostramos el resultado al usuario, siendo que se guardó en fact, imprimimos ese valor
 printf("\n\n\n"); //Aquí solo se imprimen saltos de línea xd.


	return 0;//se retorna el valor de 0 para verificar que haya finalizado sin problemas
}
unsigned int Factorial(unsigned int n){//Aquí se abre una nueva función llamada "Factorial"

	 int producto=1;//Aquí se declaran las variables locales de esta función.
     int contador=2;

	while(contador <= n)//Se abre un ciclo while 
    {
    producto = producto * contador;
    contador = contador +1;	//Aquí se hacen las operaciones con las variables.
    }
    return producto;//Aquí retornamos el resultado de las operaciones para poder aplicarlas en la función principal.
}