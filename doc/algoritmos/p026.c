//Agregamos las librerias necesarias para las funciones que necesitamos
#include <stdio.h>

//Aqui ponemos los prototipos de las funciones utilizadas
void Ordenamiento(unsigned int Ne, char lista[][20]);
void CapturaPalabras(unsigned int Np, char lista[][20]); 
void MostrarLista(unsigned int Np, char lista[][20]); 
void IntercambioPalabras(unsigned int Org, unsigned int Dest, char lista[][20]); 

//Inicializamos la funcion principal 
int main()
{
	//Declaracion de variables de esta funcion
	char lista[20][20];
	unsigned int N; 

	//Se registran el numero de palabras que se capturaran y se guarda en la variable N
	printf("\nNumero de palbras a capturar: "); 
	scanf("%u", &N); 
	//Se aplica la funcion capturapalabras
	CapturaPalabras(N,lista); 
	printf("\n El listado de palabras es: "); 
	//Se aplica la funcion mostrar lista
	MostrarLista(N, lista); 

    //Se ordenan las palabras y se vuelves a imprimir
    Ordenamiento(N,lista); 
    printf("\n El listado de palabras ordenado: "); 
	MostrarLista(N, lista);

    printf("\n"); 
	return 0;
}

//Intercambio de palabras org-dest y dest-org
void IntercambioPalabras(unsigned int Org, unsigned int Dest, char lista[][20])
{   
	//Declaracion de las variables de esta funcion
	char aux[20]; 
	unsigned int i; 

    //codigo encargado de el intercambio de palabras
	for(i=0; i<20; i++)
		aux[i] = lista[Org][i];
	for(i=0; i<20; i++)
		lista[Org][i] = lista[Dest][i];
	for(i=0; i<20; i++)
		lista[Dest][i] = aux[i];
}

void MostrarLista(unsigned int Np, char lista[][20])
{   
	//Declaracion de las variables de esta funcion
	unsigned int i; 

	for(i=0; i<Np; i++)
		printf("\n %i %s", i+1, &lista[i][0]); 
}

void CapturaPalabras(unsigned int Np, char lista[][20])
{   
	//Declaracion de las variables de esta funcion
	unsigned int i; 

	for(i=0; i<Np; i++)
		{ 
			printf("\n Escribe la palabra %i: ", i+1); 
	        scanf("%s", &lista[i][0]);        
        }
}

void Ordenamiento(unsigned int Ne, char lista[][20])
{
	//Declaracion de las variables de esta funcion
	int k,j, l,Id_menor,aux;

    for(j=0; j<(Ne-1); j++) //Comparar desde el primer par al ultimo
    { 
        Id_menor = j; //El menor de todos es el de la posicion 1, la posicion cero ya esta ordenada
  	
       for(k=j+1; k<Ne; k++) 
       {
            //Hacer intercambio y se inicia desde la posicion 0, luego 1, luego 2 y asÃ­ sucesivamente 
	    	l=0; 
		    while(lista[k][l]==lista[k+1][l] )
		    	l++; 
	    	if( lista[Id_menor][l]>lista[k][l]) 
	    		Id_menor=k;
	  	}
	  	 IntercambioPalabras(j,Id_menor,lista);	    	
  } 
}