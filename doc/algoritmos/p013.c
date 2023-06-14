#include <stdio.h>

int main()
{   FILE* Archivo1;
	int Entero;
	float Real;
    char Caracter;
    char Cadena[200];
	//Abrir un archivo en modo lectura
	Archivo1=fopen("nuevo.txt","r");

	//Validar el resultado de la apertura del archivo
	if (Archivo1!=NULL)
	{//Se abrio el archivo para lectura

		//Funcion que permite leer un caracter desde el archivo
		/*
		Caracter = fgetc(Archivo1);
        printf("El primer caracter es: %c\n",Caracter);

        //Lectura de 10 caracteres
        for (int k = 0; k < 20; k++)
        {
        	Caracter=fgetc(Archivo1);
        	printf("%c",Caracter);
        }
        printf("\n");

        rewind(Archivo1);
        //Leer el archivo completo
        while(!feof(Archivo1))
        {
        	Caracter=fgetc(Archivo1);
        	printf("%c",Caracter);
        }
        */
        //Funcion que permite leer una linea de texto
        //Lectura de una linea de texto
        /*
        fgets(Cadena,200,Archivo1);
        printf("%s",Cadena);
        //Lectura de 5 lineas de texto
        for (int k = 0; k < 5; k++)
        {
        	fgets(Cadena,200,Archivo1);
        	printf("\n%s",Cadena);
        }
        
        rewind(Archivo1);
        printf("\nArchivo Completo: \n");
        //Lectura del archivo completo:
        while(!feof(Archivo1))
        {
        	fgets(Cadena,200,Archivo1);
        	printf("\n%s",Cadena);
        }
        */


        //Funcion que permite leer texto con formato
        fscanf(Archivo1,"%f",&Real);
        printf("\n El float es: %f",Real);
        fscanf(Archivo1,"%i",&Entero);
        printf("\n El entero es: %i",Entero);
        fscanf(Archivo1,"%c",&Caracter);
        printf("\n El char es: %c",Caracter);
        fscanf(Archivo1,"%s",&Cadena);
        printf("\n La cadena es es: %s",Cadena);

		//Cerrar el archivo cuando ya temrinamos de usarlo
		fclose(Archivo1);
	}
	else//Error al abrir el archivo apra lectura
		printf("Error: no se pudo abrir el archivo\n");

	printf("\n");
	return 0;
}