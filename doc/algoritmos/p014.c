#include <stdio.h>

//Declarar una estructura para el manejo de puntos en un plano
typedef struct 
{
	float x;
	float y;
}PUNTO_2D;

//Declarar una estructura para el manejo de puntos en un espacio tridimensional
typedef struct
{
	float x;
	float y;
	float z;
}PUNTO_3D;

//Declarar una estructura para el manejo de numeros complejos
typedef struct 
{
	float re;
	float im;
}NUMERO_COMPLEJO;

//Declarar una estructura para el manejo de vectores
typedef struct 
{
	unsigned int Ne;
    int Data[100];
}VECTOR;

//Declarar una estructura para el manejo de matrices
typedef struct 
{
	unsigned int M;
	unsigned int N;
    int Data[100][100];
}MATRIZ;

void ShowPunto2D(PUNTO_2D p);
void ShowPunto3D(PUNTO_3D p);
void ShowComplejo(NUMERO_COMPLEJO w);
void ShowVector(VECTOR v);
void ShowMatriz(MATRIZ A);

PUNTO_2D AsignarPunto2D(float x, float y);
PUNTO_3D AsignarPunto3D(float x, float y, float z);
NUMERO_COMPLEJO AsignarComplejo(float r, float i);
VECTOR CapturaVector(unsigned int N);
MATRIZ CapturaMatriz(unsigned int filas, unsigned int columnas);

int main()
{
	PUNTO_2D p1;
	PUNTO_3D p3;
	NUMERO_COMPLEJO z;
	VECTOR v1;
	MATRIZ m1;

	//Generar arreglos N dimensional de estructuras
	NUMERO_COMPLEJO Vec[5];
	NUMERO_COMPLEJO Mat[3][3];
	PUNTO_2D Arreglo[10];

	//Inicializacion de los datos de una estructura, acceso a los miembros
    //Nombredelavariable.nombredelmiembroquequeremosmodificar
    
    p1=AsignarPunto2D(3,5);
    
    p3=AsignarPunto3D(1,1,2);

    z=AsignarComplejo(3,-5);
    
    v1=CapturaVector(3);

    m1=CapturaMatriz(2,3);
    
    printf("\nUn punto en el plano es: ");
    ShowPunto2D(p1);

    printf("\nUn punto en el espacio es: ");
    ShowPunto3D(p3);

    printf("\nEl numero complejo z=");
    ShowComplejo(z);

    printf("\nEl vector es: ");
    ShowVector(v1);

    printf("\nLa matriz es: ");
    ShowMatriz(m1);

	printf("\n");
	return 0;
}

//Funciones de asignacion

PUNTO_2D AsignarPunto2D(float x, float y)
{
	PUNTO_2D aux;
	aux.x=x;
	aux.y=y;
    return aux;
}

PUNTO_3D AsignarPunto3D(float x, float y, float z)
{
	PUNTO_3D aux;
	aux.x=x;
	aux.y=y;
	aux.z=z;
    return aux;
}

NUMERO_COMPLEJO AsignarComplejo(float r, float i)
{
	NUMERO_COMPLEJO aux;
	aux.re=r;
	aux.im=i;
	return aux;
}

VECTOR CapturaVector(unsigned int N)
{
	VECTOR V;
	V.Ne=N;
	for (unsigned int k = 0; k < N; k++)
	{
		printf("\nV[%i]=",k);
		scanf("%i",&V.Data[k]);
	}
	return V;
}

MATRIZ CapturaMatriz(unsigned int filas, unsigned int columnas)
{
	MATRIZ mat;
	mat.M=filas;
	mat.N=columnas;
	for (unsigned int i = 0; i < filas; i++)
		for (unsigned int j = 0; j < columnas; j++)
		{
			printf("\nM[%i][%i]= ",i,j);
			scanf("%i", &mat.Data[i][j]);
		}
    return mat;
}

//Funciones de mostrar

void ShowPunto2D(PUNTO_2D p)
{
	printf("(%g,%g)",p.x,p.y);
}
void ShowPunto3D(PUNTO_3D p)
{
	printf("(%g,%g,%g)",p.x,p.y,p.z);
}
void ShowComplejo(NUMERO_COMPLEJO w)
{
	if(w.im<0)
		printf("%g%g",w.re,w.im);
	else
		printf("%g+%g",w.re,w.im);
}
void ShowVector(VECTOR v)
{
	printf("{");
	for (unsigned int i = 0; i < v.Ne; i++)
	    printf("%i ",i,v.Data[i]);
    printf("}");
}
void ShowMatriz(MATRIZ A)
{
	for (unsigned int i = 0; i < A.M; i++)
	{
		printf("\n");
		for (unsigned int j = 0; j < A.N; j++)
			printf("%i ,",A.Data[i][j]);
	}
}