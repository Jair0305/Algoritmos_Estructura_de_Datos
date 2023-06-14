//Cadenas de caracteres
#include <stdio.h>

int main()
{
	char nombre[50]="Jair :B";
	char cadena1[]="Hola mundo";
    char cadena2[]={72,111,108,97,'\0'};
    char cadena3[]={'m','u','n','d','o','\0'};
    char cadena4[100]="Saludos a todos";
    char cadena5[100];
    char cadena6[100], k=0,caracter;
    

   //scanf("%[^\n]",cadena5);
    
   /* scanf("%[^\n]",cadena6);
    getchar();
    gets(nombre);*/
    printf("escribe el nombre pofabo");
    do
    {
    	caracter=getchar();
    	nombre[k]=caracter;
    	k++;
    }
    while(caracter!='\n');
    nombre[k]='\0';


/*    printf("\n%s\n%s\n%s\n%s\n%s",nombre,cadena1,cadena2,cadena3,cadena4);
    printf("\n\n%s",nombre);
    printf("\n%s",cadena1);
    printf("\n%s",cadena2);
    printf("\n%s",cadena3);
    printf("\n%s",cadena4);*/
    
  //  printf("\n\nCadena5 : %s",cadena5);
  //  printf("\nCadena 6 : %s",cadena6);
  //  printf("\nNombre : %s",nombre);
    printf("nombre xd: ");
    //puts(nombre);
    k=0;
    while(nombre[k]!='\n')
    {
    	putchar(nombre[k]);
    	k++;
    }
    printf("\n");
	return 0;
}