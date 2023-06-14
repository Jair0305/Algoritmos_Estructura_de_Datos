//Agregamos las librerias necesarias para las funciones que necesitamos
#include <stdio.h>
#include <stdlib.h>

struct NODO;

//Declaramos una estructura
typedef struct
{
	//Miembros de la estructura
	int dato;
	struct NODO *next;
}NODO;//Nombre de la estructura

//Aqui ponemos los prototipos de las funciones utilizadas
NODO *CrearNodo(int dato);
void InsertarNodo(NODO **list, int dato);
void ImprimeLista(NODO *list);
void EliminarNodo(NODO **list);
void InsertarNodoAlInicio(NODO **list, int dato);
void EliminarNodoAlInicio(NODO **list);

//Inicializamos la funcion principal 
int main()
{
	//Declaracion de variables de esta funcion
	NODO *Lista=NULL;
	int num;
    
    //Imprimimos la lista
	ImprimeLista(Lista);
	//Insertamos un nodo 10
	InsertarNodo(&Lista,10);
	//Insertamos un nodo 20
	InsertarNodo(&Lista,20);
	//Insertamos un nodo 30
	InsertarNodo(&Lista,30);
	//Insertamos un nodo 40
	InsertarNodo(&Lista,40);
	//Insertamos un nodo 50
	InsertarNodo(&Lista,50);
	//Insertamos un nodo 60
	InsertarNodo(&Lista,60);
	//Insertamos un nodo 70
	InsertarNodo(&Lista,70);
	//Insertamos un nodo 80
	InsertarNodo(&Lista,80);
	//Insertamos un nodo 90
	InsertarNodo(&Lista,90);
	//Insertamos nodo al inicio 9
	InsertarNodoAlInicio(&Lista,9);
	//Insertamos nodo al inicio 8
	InsertarNodoAlInicio(&Lista,8);
	//Insertamos nodo al inicio 7
	InsertarNodoAlInicio(&Lista,7);
	//Insertamos nodo al inicio 6
	InsertarNodoAlInicio(&Lista,6);

    //Imprimimos la lista
	ImprimeLista(Lista);

    //Eliminamos un nodo del final
	EliminarNodo(&Lista);
	printf("\nSe elimina un nodo del final:\n");
	//Imprimimos la lista
	ImprimeLista(Lista);

    //Eliminamos un nodo del final
	EliminarNodo(&Lista);
	//Eliminamos un nodo del final
	EliminarNodo(&Lista);
	//Eliminamos un nodo del final
	EliminarNodo(&Lista);
	printf("\nEliminamos 3 nodos mas del final:");
	//Imprimimos la lista
	ImprimeLista(Lista);

	EliminarNodoAlInicio(&Lista);
    printf("\nEliminando nodo del inicio\n");
    //Imprimimos la lista
	ImprimeLista(Lista);
	//Eliminamos un nodo del inicio
	EliminarNodoAlInicio(&Lista);
	//Eliminamos un nodo del inicio
	EliminarNodoAlInicio(&Lista);
	//Eliminamos un nodo del inicio
	EliminarNodoAlInicio(&Lista);
	printf("\nEliminando 3 nodos mas del inicio\n");
	//Imprimimos la lista
	ImprimeLista(Lista);

	printf(" \n");
	return 0;//se retorna el valor de 0 para verificar que haya finalizado sin problemas
}

void InsertarNodoAlInicio(NODO **list, int dato)
{
	NODO *NewNodo;

	NewNodo = CrearNodo(dato);

	if(*list==NULL)
	{
		//Lista vacia
		*list = NewNodo; // Se asigna la direcion del nuevo nodo a list, entonces se convierte en el nodo1
	}
	else
	{
		//La lista contiene al menos un nodo insertado
		NewNodo->next = (struct NODO *)*list;
		*list = NewNodo;
	}
}

void EliminarNodoAlInicio(NODO **list)
{
	NODO *aux;

	if(*list==NULL)
	{
		//Lista vacia
		printf("\nNo se puede eliminar Nodo, Lista Vacia!.");
	}
	else
	{
		aux = *list;
		*list = (NODO *)aux->next;
		free(aux);

	}
}

void EliminarNodo(NODO **list)
{
	NODO *ultimo;
	NODO *penultimo;

	if(*list==NULL)
	{
		//Lista vacia
		printf("\nNo se puede eliminar Nodo, Lista Vacia!.");
	}
	else
	{
		//La lista contiene al menos un nodo insertado
		ultimo = *list;
		if(ultimo->next==NULL)
		{
			free(ultimo);
			*list = NULL;
		}
		else
		{
			//Buscar el nodo que apunta a NULL(El nodo final)
		    while(ultimo->next!=NULL)
		    {
			    penultimo = ultimo;
			    ultimo =(NODO *) ultimo->next;
		    }
		    penultimo->next = NULL;
		    free(ultimo);
		}

	}
}

void ImprimeLista(NODO *list)
{
	NODO *aux;
	if(list==NULL)
	{
		//Lista vacia
		printf("\n Lista Vacia!");
	}
	else
	{
		//La lista contiene al menos un nodo insertado
		aux = list;
		//Imprimir el nodo apuntado por aux
		do
		{
			printf("\n%i",aux->dato);
			aux =(NODO *) aux->next;

		} while(aux!=NULL);
	}
}

NODO *CrearNodo(int dato)
{
	NODO *ptr;

	ptr = (NODO *)malloc(sizeof(NODO));

	if(ptr==NULL)
	{
		printf("\n Error al reservar la memroia para el nodo.");
		exit(0);
	}
	ptr->dato = dato;
	ptr->next = NULL;

	return ptr;
}
void InsertarNodo(NODO **list, int dato)
{
	NODO *aux;
	NODO *NewNodo;

	NewNodo = CrearNodo(dato);

	if(*list==NULL)
	{
		//Lista vacia
		*list = NewNodo; // Se asigna la direcion del nuevo nodo a list, entonces se convierte en el nodo1
	}
	else
	{
		//La lista contiene al menos un nodo insertado
		aux = *list;

		// Buscar el nodo que paunta a NULL (El nodo final)
		while(aux->next!=NULL)
			aux = (NODO *)aux->next;

		aux->next = (struct NODO *)NewNodo;
	}
}