#include <stdio.h>
#include <stdlib.h>

typedef struct //Se crea una estructura llamada matriz
{
	//Esta tiene como miembros, M,N y dato
	unsigned int M;
	unsigned int N;
	int *dato;
}MATRIZ;

//Aqui se ponen los prototipos de las funciones usadas en el programa
MATRIZ* CapturaMatriz(unsigned int filas, unsigned int columnas);
MATRIZ* ProductoMatriz(MATRIZ *A, MATRIZ *B);
void ImprimeMatriz(MATRIZ *p);
void FreeMatriz(MATRIZ *p);

//Se inicializa la funcion principal
int main()
{
	//Se declaran las variables locales de la funcion
	unsigned int Ma, Na, Mb, Nb;
	int *A, *B, *C;

    //Se pregunta al usuario el numero de filas de A y se guarda en Ma
	printf("\nNumero de filas de A: ");
	scanf("%u",&Ma);
	//Se pregunta al usuario el numerod e columnas de A y se guarda en Na
	printf("\nNumero de columnas de A: ");
	scanf("%u",&Na);
	//Se guarda en la variable A la funcion CapturaMatriz aplicandola a las variables Ma y Na
	A=CapturaMatriz(Ma,Na);
	printf("\n");

	//Se una la funcion imprimematriz aplicandola a A para imprimir el resultado
	ImprimeMatriz(A);

    printf("\n");
    //Se pregunta al usuario el numero de filas de B y se guarda en Mb
	printf("\nNumero de filas de B: ");
	scanf("%u",&Mb);
	//Se pregunta al usuario el numerod e columnas de B y se guarda en Nb
	printf("\nNumero de columnas de B: ");
	scanf("%u",&Nb);
	printf("\n");
	//Se guarda en la variable B la funcion CapturaMatriz aplicandola a las variables Mb y Nb
	B=CapturaMatriz(Mb,Nb);
	printf("\n");
	//Se una la funcion imprimematriz aplicandola a B para imprimir el resultado
	ImprimeMatriz(B);

    //Se guarda en la variable C el resultado de la funcion productomatriz aplciandola a A y B
	C=ProductoMatriz(A,B);
    printf("\nEl producto de A*B= \n");
    //Se imprime el resultado del producto de las 2 matrices
    ImprimeMatriz(C);
    printf("\n");

    //Se libera la memoria con una funcion para la matriz A, B y C
	FreeMatriz(A);
	FreeMatriz(B);
	FreeMatriz(C);

	printf("\n");//Aqui solo se imprime un salto d elinea

	return 0;//se retorna el valor de 0 para verificar que haya finalizado sin problemas
}

//Se inicia la funcion Free Matriz, esta la usamos en la funcion main para liberar la memoria de las matrices
void FreeMatriz(MATRIZ *p)
{
	free(p->dato);
	free(p);
}

//Se inicia la funcion producto matriz
MATRIZ* ProductoMatriz(MATRIZ *A, MATRIZ *B)
{
	//Se declaran las varibales locales de la funcion
	unsigned int i,j,k;
    
    //Se declara la variable product de tipo MATRIZ
	MATRIZ *product=NULL;
	//Para que se pueda sacar el producto, las columnas de A, deben ser igual a las filas de B
	if(A->N==B->M)
	{
		//Se reserva memoria para la variable product
		product = (MATRIZ *)malloc(sizeof(MATRIZ));
		if(product==NULL)//Si no se puede reservar la memoria, te arroja el siguiente mensaje
		{
			printf("Error al reservar memoria para el producto \n");
			exit(0);
		}
			product->M=A->M;
			product->N=B->N;

			//Reservar la memoria para almacenar los datos de la matriz MxN
			product->dato=(int *)malloc(A->M*B->N*sizeof(int));
		if(product->dato==NULL)
		{
			//Si no se puede reservar la memoria, te arroja el siguiente mensaje
			printf("Error al reservar la memoria para los datos del producto MATRIZ. ");
			exit(0);
		}
		//En estos ciclos for, es donde nos empieza a hacer las operaciones correspondientes para sacar el producto
		for(i=0; i<product->M;i++)
			for(j=0;j<product->N;j++)
			{
				product->dato[i*product->N+j]=0;
				for(k=0;k<A->N;k++)
					*(product->dato+i*product->N+j)+= *(A->dato+i*A->N+k) * * (B->dato+k*B->N+j);
			}
	}
	//No se puede sacar el producto por que las columnas de A, no son iguales a las filas de B
	else
	printf("No se puede realizar el producto debido a que las dimensiones no corresponden. \n");
    
    //Se retorna la variable product
	return product;
}

//Se inicia la funcion CapturaMatriz
MATRIZ* CapturaMatriz(unsigned int filas, unsigned int columnas)
{
	//Se declara la variable ptr de tipo MATRIZ
	MATRIZ *ptr;
	unsigned int i, j;

	//Reservar memoria para almacenar una estructura MATRIZ
	ptr = (MATRIZ *)malloc(sizeof(MATRIZ));
	if (ptr==NULL)
	{
	//Si no se puede reservar la memoria, te arroja el siguiente mensaje
		printf("Error al reservar la memoria para la matriz. \n");
		exit(0);
	}
	//Accediendo a los miembros de la estructura mediante un apuntador
	ptr->M=filas;
	ptr->N=columnas;

	//Reservar la memoria para almacenar los datos de la matriz de MxN
	ptr->dato=(int *)malloc(filas*columnas*sizeof(int));
	if(ptr->dato==NULL)
	{
		//Si no se puede reservar la memoria, te arroja el siguiente mensaje
		printf("Error al reservar la memoria para los datos de la MATRIZ.");
        exit(0);
	}
	//Iniciamos con la captura de los datos
	for (i = 0; i < filas; i++)
	{
		for(j=0; j<columnas; j++)
		{
			printf("Dato[%u][%u]= ",i,j);
			scanf("%i",&ptr->dato[i*columnas+j]);
		}
	}
	//Se retorna la variable ptr

	return ptr;
}

//Se inicia la funcion imprimematriz
void ImprimeMatriz(MATRIZ *p)
{
	//Se declaran las variables locales de la funcion
	int i,j;
	//Se abre un ciclo for
	for(i=0;i<p->M;i++)
	{
		//SAlto de linea
		printf("\n");
		//Se abre otro ciclo for en el que ya se comenzaran a imprimir los datos de la matriz
		for(j=0;j<p->N;j++)
			printf("%i ", *(p->dato+i*p->N+j));
	}
}
