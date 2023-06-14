#include <stdio.h>

int main()
{   FILE* Archivo1;
    char Caracter='x';
    char Texto[100]="\nEsta es una linea de texto escrito con la funcion fputs()";
    float r;

    //Crea un archivo en modo escritura
	Archivo1=fopen("nuevo.txt","w");

	//Validar el resutlado de al cracion del archivo
	if(Archivo1!=NULL)
    {//EL archivo se creo correctamente
        
/*
        //Funcion que permite escribir un caracter dentro del archivo
        fputc(Caracter,Archivo1);
        fputc('_',Archivo1);
        fputc(75,Archivo1);

        //Funcion que permite escribir una cadena de caracteres en el archivo
        fputs(Texto,Archivo1);
        fputs("\nCadena directa como parametro",Archivo1);
        printf("\nEscriba un mensaje: ");
        scanf("%[^\n]",Texto);
        fputs(Texto,Archivo1);
*/
        //Funcion que permite escribir texto con formato
        for (int i = 0; i < 10; i++)
        	fprintf(Archivo1,"Esta es la linea de texto numero %i\n",i+1);

        for (int i = 0; i < 5; i++)
        {
        	r = i*3.1416;
        	fprintf(Archivo1,"%f\n",r);
        }

        //Cerrar el archivo cuando ya no se utiliza
    	fclose(Archivo1);
    }
    else//Error al crear el archivo para escritura
    	printf("Error: no se pudo crear el archivo\n");

    printf("\n");
	return 0;
}