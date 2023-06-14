#include<stdio.h>

int main()
{
    char frase[200];
    unsigned int k=0, NumCaracterPorPalabra;
// Captura una cadena
    printf("\nEscriba una frase: ");
    scanf("%[^\n]s", frase); 

// Eliminar los espacios y tomar en cuneta solo los caracteres. Recomendable usar un ciclo while:
    while(frase[k]!='\0')// Principio a fin de la cadena. Ciclo que recorre desde del primer caracter, hasta el final de la cadena.
    { 
        // Ciclo que brinca los espacios hasta encontrar el primer caracter 
        while(frase[k]==' ')
        {
            k++;
        }
        // Ciclo que contabiliza los caracteres hasta encontrar el siguiente espacio
        NumCaracterPorPalabra=0;
        while(frase[k]!=' '&&frase[k]!='\0')
        {
            putchar(frase[k]); //<< Enviar toda la palabra y su cantidad de caracteres
            NumCaracterPorPalabra++;
            k++;
        }
        if(frase[k-1]!=' ') 
        printf("\t\t %u\n", NumCaracterPorPalabra);    // \t << tabulacion, genera "tabla"
    }


    printf(" \n");
    return 0;
}