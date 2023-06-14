#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	int Id;
	char nombre[20];
	char apellidoP[20];
	char apellidoM[20];
	char numero[15];
	int nr;
}Registro[100];

void EliminarR(Registro Persona);
void BuscarporID(Registro Persona);
void OrdenarporID(Registro Persona);
void OrdenarporN(Registro Persona);
void OrdenarporA(Registro Persona);
void CapturarR(Registro Persona);

int main()
{
	unsigned char salir=0;
	unsigned int opcion;
	Registro p;
	do
	{
		printf("\n- Sistema de Registro -\n");
		printf("\n1. Ingresar Registro");
		printf("\n2. Eliminar Registro");
		printf("\n3. Buscar Registro usando el ID");
		printf("\n4. Listar los registros por el ID");
		printf("\n5. Listar los registros por el NOMBRE");
		printf("\n6. Listar los registros por el APELLIDO PATERNO");
		printf("\n7. Salir");
		printf("\n\nOpcion: ");
		scanf("%u",&opcion);
		switch(opcion)
		{
			case 1:
			CapturarR(p);
			break;

			case 2:
			EliminarR(p);
			break;

			case 3:
			BuscarporID(p);
			break;

			case 4:
			OrdenarporID(p);
			break;

			case 5:
			OrdenarporN(p);
			break;

			case 6:
			OrdenarporA(p);
			break;

			case 7:
			salir=1;
			break;    

			default: printf("\nOpcion no valida.");
		}
	}
	while(!salir);

	printf(" \n");
	return 0;
}

void CapturarR(Registro Persona)
{
	unsigned int i=1;

	printf("Ingrese el Id del registro: ");
	scanf("%i",&Persona[i].Id);
	printf("\nIngrese el nombre de la persona: ");
	scanf(" %s",&Persona[i].nombre);
	printf("\nIngrese el apellido paterno de la persona: ");
	scanf(" %s",&Persona[i].apellidoP);
	printf("\nIngrese el apellido materno de la persona: ");
	scanf(" %s",&Persona[i].apellidoM);
	printf("\nIngrese el numero de telefono de la persona: ");
	scanf(" %s",&Persona[i].numero);
	Persona[i].nr = i;

	i++;
}

void EliminarR(Registro Persona)
{
	int i=0;
	printf("Ingrese el registro que quiere eliminar");
	scanf("%i",&i);
	Persona[i].Id=NULL;
	Persona[i].nombre=NULL;
	Persona[i].apellidoP=NULL;
	Persona[i].apellidoM=NULL;
	Persona[i].numero=NULL;
}

void BuscarporID(Registro Persona)
{
	int i=0;
	printf("Ingrese el ID que quiere encontrar");
	scanf("%i",&i);
}

void OrdenarporID(Registro Persona)
{

}

void OrdenarporN(Registro Persona)
{

}

void OrdenarporA(Registro Persona)
{

}