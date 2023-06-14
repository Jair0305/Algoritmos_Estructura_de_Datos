#include <stdio.h>//Agregamos la librería stdio.h que contiene las funciones básicas del lenguaje de programación C.

int main()//Inicia función Principal
{   char frase[200];//Se declaran las variables.
    unsigned int k=0, NumCaracterPorPalabra, NumCaracterTotal, np;

   
	printf("Escribe la frase: ");//Se le pide al usuario que capture una cadena
	scanf("%[^\n]s",frase);//La cadena se guarda en el array

	NumCaracterTotal = 0;
    np = 0; //igualamos estas dos variabels en cero.

    //En este ciclo recorre la cadena desde el primer caracter hasta el ultimo.
	while(frase[k]!='\0')
	{ 

	//Ciclo que esquiva los espacios hasta encontrar el primer caracter.
	  while((frase[k]==' ')&&(frase[k]!='\0'))
             k++;

      //Ciclo que contabiliza los caracteres hasta encontrar el siguiente espacio.
      NumCaracterPorPalabra = 0;
      while((frase[k]!=' ')&&(frase[k]!='\0'))
      { putchar(frase[k]);
      	NumCaracterPorPalabra++;
      	k++;
      	//Mientras que no se encuentre ningún espacio, el numero de caracter por palabra va aumentando
      }
      	 if(frase[k-1]!=' ')
      	 {
      	 printf("\t\t %u\n", NumCaracterPorPalabra);    // \t << tabulacion, genera "tabla"
      	 //En este punto sumaremos np+1, que ira guardando el número de palabras d ela cadena
      	 np=np+1;	
      	 } 
        
         NumCaracterTotal = NumCaracterTotal + NumCaracterPorPalabra;
         //En esta variable se irán sumando los carácteres de todas las palabras.
	}

    printf("\nnumero de caracteres en total: %u",NumCaracterTotal);//Imprimimos el numero de caracteres totales.
    printf("\nnumero de palabras: %u",np);//Guardamos el número total de palabras

	printf("\n");
	return 0;
}