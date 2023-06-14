#include <stdio.h>
#include <stdlib.h>

int* CapturaVector(unsigned int Ne);
void ImprimeVector(int* ptr, unsigned int Ne);
float PromedioVector(int* ptr, unsigned int Ne);
int* CopiaVectorInvertido(int* ptr, unsigned int Ne);

int main()
{
	unsigned int N;
	int *ptr;
	float prom;

    
	printf("Escriba la cantidad de numeros enteros a capturar: ");
	scanf("%u",&N);
	ptr=CapturaVector(N);
	ImprimeVector(ptr,N);
	prom=PromedioVector(ptr,N);
	free(ptr);
	printf("\n El promedio del vector es: %f",prom);

    CopiaVectorInvertido(ptr, N);
    printf("\n");
	return 0;
}

int* CopiaVectorInvertido(int* ptr, unsigned int Ne)
{
	int *p,i;
    unsigned int k;
    int aux;

      p=(int*)malloc(Ne * sizeof(int));


      printf("\nArreglo invertido: \n\n");
      for(i=Ne-1;i>=0;i--)
      {
      		aux=i;
	         	*p = *ptr;
            printf("%u ",*(p));
      }
}

int* CapturaVector(unsigned int Ne)
{
	int* puntero;
	unsigned int k;

	puntero = (int *)malloc(Ne*sizeof(int));

	if(puntero==NULL)
	{
		printf("Error al reservar la memoria para almacenar los datos");
		exit(0);
	}

	for(k=0;k<Ne;k++)
	{
		printf("Entero %i: ",k+1);
		scanf("%i",puntero+k);
	}
	return puntero;
}

void ImprimeVector(int* ptr, unsigned int Ne)
{
	unsigned int k;
	printf("\n{ ");
	for(k=0;k<Ne;k++)
		printf("%i ",*(ptr+k));
	printf("}");
}

float PromedioVector(int* ptr, unsigned int Ne)
{
	unsigned int k;
	float result;
	int sum=0;
	for(k=0; k<Ne; k++)
		sum +=*(ptr+k);
	result=(float)sum/Ne;
	return result;
}