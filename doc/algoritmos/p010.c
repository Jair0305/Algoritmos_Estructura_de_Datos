//Arreglos de cadenas de caracteres (String).

#include <stdio.h>

void CapturaFrases(unsigned int N, char listado[][100]);
void MostrarFrases(unsigned int N, char listado[][100]);
int main()
{
	const unsigned char Numerodecadenas = 100;
	char arreglodecadenas[Numerodecadenas][100];
	unsigned int N;

	printf("Cuantos enunciados va a guardar?  ");
	scanf("%u",&N);
    gets(&arreglodecadenas[0][0]);

    CapturaFrases(N,arreglodecadenas);
    MostrarFrases(N,arreglodecadenas);

    printf("\n");
	return 0;
}

void CapturaFrases(unsigned int N, char listado[][100])
{   unsigned int i;
	for(i=0;i<N;i++)
	{
		printf("Escribe la frase %i: ",i+1);
		gets(&listado[i][0]);
	}

}
void MostrarFrases(unsigned int N, char listado[][100])
{   unsigned int i;
	for(i=0;i<N;i++)
		puts(&listado[i][0]);
        printf("\n");
	//	printf("\n%s: ",&listado[i][0]);

}