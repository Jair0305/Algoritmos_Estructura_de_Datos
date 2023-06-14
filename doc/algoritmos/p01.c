#include <stdio.h>//Agregamos la librería stdio.h que contiene las funciones básicas del lenguaje de programación C.

int main(){//Inicia función Principal
	unsigned int N, i, sum=0;//Declaracion de las variables
	printf ("Escriba un numero natural");//pedimos un numero mediante un texto que se muestra al usuario
	scanf("%u",&N);//guardamos el numero en la variable "N"
	
	for (i=0 ; i <= N ; i++ ){ /*creamos un contador, con un ciclo for para ir sumando los numeros en base al numero dado por el usuario. */
		sum = sum + i;//Se le agrega el valor de "i" a Suma.
	}
	printf("La sumatoria de los %i primeros numeros es: %i",N, sum); // se muestra en consola el valor de la sumatoria de "N" Numeros
	return 0; //se retorna el valor de 0 para verificar que haya finalizado sin problemas
} 