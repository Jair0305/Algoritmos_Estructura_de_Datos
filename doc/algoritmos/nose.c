#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Persona
{
	char Id[50];
	char nombre[50];
	char apellidom[50];
	char apellidop[50];
	char numero[50];
}Persona[30];

typedef struct Nodo
{
	Persona persona;
	struct Nodo* siguiente;
}Nodo;

typedef struct Lista
{
	Nodo* cabeza;
	int longitud;
}Lista;

Nodo* CrearNodo(Persona* persona);
void DestruirNodo(Nodo* nodo);
void Insertaralprincipio(Lista* lista, Persona* persona);
void Insertaralfinal(Lista* lista, Persona* persona);
void InsertarDespues(int n, Lista* lista, Persona* persona);
Persona* Obtener(int n, Lista* lista);
int Contar(Lista* lista);
int Vacia(Lista* lista);
void EliminarAlPrincipio(Lista* lista);
void EliminarAlUltimo(Lista* lista);
void EliminarElementoN(int n, Lista* lista);
void EliminarElementoN(int n, Lista* lista);
void imprimirlista(Lista* lista, Persona* p);
void CapturarPersona(Persona* persona, Lista* lista);

int main()
{
	int o;
	unsigned char salir=0;
	unsigned int opcion;
	Persona p;
	Lista l;
	unsigned int i, j;
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
			CapturarPersona(&p,&l);

			break;

			case 2:
			do
			{
				printf("Desea eliminar el primer o ultimo registro? \n 1=primer 2=ultimo");
				scanf("%d",&o);
				if(o==1)
				{
					EliminarAlPrincipio(&l);
				}
				else if(o==2)
				{
					EliminarAlUltimo(&l);
				}
			}
			while(o>0 && o<3);
			break;

			case 3:
			printf("Ingrese el Id que quiere consultar");
			scanf("%d",&i);
			Obtener(i,&l);
			break;

			case 4:
			break;

			case 5:
			Contar(&l);
			break;

			case 6:
						imprimirlista(&l,&p);
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

void imprimirlista(Lista* lista, Persona* p)
{
	printf("%s\n", p[lista->longitud]->nombre);
}

void CapturarPersona(Persona* persona, Lista* lista)
{
    char Id[50];
	char nombre[50];
	char apellidom[50];
	char apellidop[50];
	char numero[50];

    //libro = (Libro*)malloc(sizeof(Libro));
    //lista = (Lista*)malloc(sizeof(Lista));
    printf("\nIngrese el id de la persona: ");
    scanf("%d",&Id);
    printf("\nIngrese el nombre de la persona: ");
    scanf("%s",&nombre);
    printf("\nIngrese el apellido paterno de la persona: ");
    scanf("%s",&apellidop);
    printf("\nIngrese el apellido materno de la persona: ");
    scanf("%s",&apellidom);
    printf("\nIngrese el numero de telefono de la persona: ");
    scanf("%s",&numero);
    persona[1]->Id == Id;
    persona[1]->nombre == nombre;
    persona[1]->apellidop == apellidop;
    persona[1]->apellidom == apellidom;
    persona[1]->numero == numero;
    Insertaralprincipio(lista,persona);
}

Nodo* CrearNodo(Persona* persona)
{
	Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));
	strncpy(nodo->persona[50].Id, persona[1]->Id, 50);
	strncpy(nodo->persona[50].nombre, persona[1]->nombre, 50);
	strncpy(nodo->persona[50].apellidop, persona[1]->apellidop, 50);
	strncpy(nodo->persona[50].apellidom, persona[1]->apellidom, 50);
    strncpy(nodo->persona[50].numero, persona[1]->numero, 50);

    nodo->siguiente = NULL;
    return nodo;
}

void DestruirNodo(Nodo* nodo)
{
	free(nodo);
}

void Insertaralprincipio(Lista* lista, Persona* persona)
{
	Nodo* nodo = CrearNodo(persona);
	nodo->siguiente = lista->cabeza;
	lista->cabeza = nodo;
	lista->longitud++;
}

void Insertaralfinal(Lista* lista, Persona* persona)
{
	Nodo* nodo = CrearNodo(persona);
	if(lista->cabeza = NULL)
	{
		lista->cabeza = nodo;
	}
	else
	{
		Nodo* puntero = lista->cabeza;
		while(puntero->siguiente)
		{
			puntero = puntero->siguiente;
		}
		puntero->siguiente = nodo;
	}
}

void InsertarDespues(int n, Lista* lista, Persona* persona)
{
	Nodo* nodo = CrearNodo(persona);
	if (lista->cabeza == NULL)
	{
		lista->cabeza = nodo;
	}
	else
	{
		Nodo* puntero = lista->cabeza;
		int posicion = 0;
		while (posicion < n && puntero->siguiente)
		{
			puntero = puntero->siguiente;
			posicion++;
		}
		nodo->siguiente = puntero->siguiente;
		puntero->siguiente = nodo;
	}
	lista->longitud++;
}

Persona* Obtener(int n, Lista* lista)
{
	if(lista->cabeza == NULL)
	{
		return NULL;
	}
	else
	{
		Nodo* puntero = lista->cabeza;
		int posicion = 0;
		while(posicion < n && puntero->siguiente)
		{
			puntero = puntero->siguiente;
			posicion++;
		}
		if(posicion != n)
		{
			return NULL;
		}
		else
		{
			return &puntero->persona;
		}
	}
}

int Contar(Lista* lista)
{
	return lista->longitud;
}

int Vacia(Lista* lista)
{
	return lista->cabeza == NULL;
}

void EliminarAlPrincipio(Lista* lista)
{
	if(lista->cabeza)
	{
		Nodo* eliminado = lista->cabeza;
		lista->cabeza = lista->cabeza->siguiente;
		DestruirNodo(eliminado);
		lista->longitud--;
	}
}

void EliminarAlUltimo(Lista* lista)
{
	if (lista->cabeza)
	{
		if(lista->cabeza->siguiente)
		{
			Nodo* puntero = lista->cabeza;
			while(puntero->siguiente->siguiente)
			{
				puntero = puntero->siguiente;
			}
			Nodo* eliminado = puntero->siguiente;
			puntero->siguiente = NULL;
			DestruirNodo(eliminado);
			lista->longitud--;
		}
		else
		{
			Nodo* eliminado = lista->cabeza;
			lista->cabeza = NULL;
			DestruirNodo(eliminado);
			lista->longitud--;
		}
	}
}

void EliminarElementoN(int n, Lista* lista)
{
	if(lista->cabeza)
	{
		if(n == 0)
		{
			Nodo* eliminado = lista->cabeza;
			lista->cabeza = lista->cabeza->siguiente;
			DestruirNodo(eliminado);
			lista->longitud--;
		}
		else if(n < lista->longitud)
		{
			Nodo* puntero = lista->cabeza;
			int posicion = 0;
			while(posicion < (n-1))
			{
				puntero = puntero->siguiente;
				posicion++;
			}
			Nodo* eliminado = puntero->siguiente;
			puntero->siguiente = eliminado->siguiente;
			DestruirNodo(eliminado);
			lista->longitud--;
		}	
	}
}