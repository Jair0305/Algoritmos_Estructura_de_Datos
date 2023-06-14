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
	struct NODO *prev;
}NODO;//Nombre de la estructura

//Aqui ponemos los prototipos de las funciones utilizadas
NODO* CrearNodo(int dato);
void InsertarNodoFinal(NODO *list, int dato);
void ImprimeListaAdelante(NODO *list);
void ImprimeListaAtras(NODO *list);
void EliminarNodoFinal(NODO *list);
void InsertarNodoAlInicio(NODO *list, int dato);
void EliminarNodoAlInicio(NODO *list);

//Inicializamos la funcion principal 
int main()
{
	//Declaracion de variables de esta funcion
	NODO Lista;
	Lista.next=NULL;
	Lista.prev=NULL;
    
    //Imprimimos la lista hacia adelante
	ImprimeListaAdelante(&Lista);
    //Imprimimos la lista hacia atras
	ImprimeListaAtras(&Lista);
	//Insertamos un nodo al final con el valor de 10
	InsertarNodoFinal(&Lista,10);
	//Insertamos un nodo al final con el valor de 20
	InsertarNodoFinal(&Lista,20);
	//Insertamos un nodo al final con el valor de 30
	InsertarNodoFinal(&Lista,30);
	//Insertamos un nodo al final con el valor de 40
	InsertarNodoFinal(&Lista,40);
	//Insertamos un nodo al final con el valor de 50
	InsertarNodoFinal(&Lista,50);
	//Insertamos un nodo al final con el valor de 60
	InsertarNodoFinal(&Lista,60);
	//Insertamos un nodo al final con el valor de 70
	InsertarNodoFinal(&Lista,70);
	//Insertamos un nodo al final con el valor de 80
	InsertarNodoFinal(&Lista,80);
	//Insertamos un nodo al Inicio con el valor de 38
	InsertarNodoAlInicio(&Lista,38);
	printf("\nLa lista de inicio a fin: ");
	//Imprimimos la lista hacia adelante
    ImprimeListaAdelante(&Lista);
	printf("\nLa lista de fin a inicio: ");
	//Imprimimos la lista hacia atras
	ImprimeListaAtras(&Lista);
	EliminarNodoAlInicio(&Lista);
	//Eliminamos 3 nodos
	EliminarNodoFinal(&Lista);
	EliminarNodoFinal(&Lista);
	EliminarNodoFinal(&Lista);
	printf("\nLa lista de inicio a fin despues de eliminar 3 nodos: ");
	//Imprimimos la lista hacia adelante
    ImprimeListaAdelante(&Lista);
	printf("\nLa lista de fin a inicio despues de eliminar 3 nodos: ");
	//Imprimimos la lista hacia atras
	ImprimeListaAtras(&Lista);
	//Eliminamos 5 nodos mas
	EliminarNodoFinal(&Lista);
	EliminarNodoFinal(&Lista);
	EliminarNodoFinal(&Lista);
	EliminarNodoFinal(&Lista);
	EliminarNodoFinal(&Lista);
	printf("\nLa lista de inicio a fin despues de eliminar 8 nodos: ");
	//Imprimimos la lista hacia adelante
    ImprimeListaAdelante(&Lista);
	printf("\nLa lista de fin a inicio despues de eliminar 8 nodos: ");
	//Imprimimos la lista hacia atras
	ImprimeListaAtras(&Lista);

	printf("\n");
	return 0;
}

//Inicializamos la funcion Insertar nodo al inicio
void InsertarNodoAlInicio(NODO *list, int dato)
{
	NODO* aux;
	NODO* newNodo;
	newNodo = CrearNodo(dato);

	if((list->next == NULL) && (list->prev == NULL))
	{ //Lista vacia
		list->next = (struct NODO*)newNodo;
		list->prev = (struct NODO*)newNodo; 
		//Se asigna la dirección del nuevo nodo al apuntador del nodo inicial y nodo final
	}
	else
	{ //La lista contiene al menos un nodo inicializado
		aux =(NODO *)list->next;
		//Buscar el nodo de inicio
		while(aux->prev != NULL)
			aux = (NODO*)aux->prev;

		aux ->prev= (struct NODO*)newNodo;
		newNodo->next= (struct NODO*)aux;
		list->next=(struct NODO*) newNodo;
	}
}


void EliminarNodoAlInicio(NODO *list)
{
	NODO* inicio;
	NODO* segundo;
	if((list->next == NULL) && (list->prev == NULL))
	{
	//Lista vacia
	printf("\nNo se puede eliminar Nodo, lista vacía\n");
	}
	else
	{
	//La lista contiene al menos un nodo inicializado
	inicio = (NODO*)list->prev;
	if(list->next==list->prev)
		{
			free(inicio);
			list->next=NULL; //hacer la lista vacia
			list->prev=NULL; //hacer la lista vacia
		}
		else
		{
		//Buscar el nodofinal
			while(inicio->prev != NULL)
				inicio = (NODO*)inicio->prev;
			segundo=(NODO*)inicio->next;
			segundo->prev= NULL;
			list->next=(struct NODO*)segundo;
			free(inicio); //liberar la memoria del ultimo nodo
		}
	}
}
void InsertarNodoFinal(NODO *list, int dato)
{
	//Se declaran las variables locales de la funcion
	NODO *aux;
	NODO *Newnodo;
    
    //Añade un nodo al final de la lista
	Newnodo=CrearNodo(dato);
	if((list->next==NULL)&&(list->prev==NULL))
	{
		list->next=(struct NODO *)Newnodo;
		list->prev=(struct NODO *)Newnodo;
	}
	else
	{
		aux=list;

		while(aux->next!=NULL)
			aux=(NODO *)aux->next;
		aux->next=(struct NODO *)Newnodo;
		Newnodo->prev=(struct NODO *)aux;
		list->prev=(struct NODO *)Newnodo;
	}
}

void EliminarNodoFinal(NODO *list)
{
	//Se declaran las variables locales de la funcion
	NODO *ultimo;
	NODO *penultimo;

	if((list->next==NULL)&&(list->prev==NULL))
	{
		printf("\nNo se puede eliminar nodo, lista vacia!");
	}
	else
	{
		ultimo = (NODO *)list->next;
		if (list -> next==list->prev)
		{
			free(ultimo);
			list->next=NULL;
			list->prev=NULL;
		}
		else
		{
			while(ultimo->next!=NULL)
				ultimo =(NODO *)ultimo->next;
			
			penultimo=(NODO *)ultimo->prev;
			penultimo->next=NULL;
			list->prev=(NODO *)	penultimo;
			free(ultimo);
		}
	}
}

void ImprimeListaAdelante(NODO *list)
{
	//Se declaran las variables locales de la funcion
    NODO* aux;
    
    if(list->next == NULL)
    {
        //Lista vacia
        printf("Lista vacía\n");
    }

    else
    {
        //La lista contiene al menos un nodo inicializado
        aux = (NODO*)list->next;
        //Imprimimr el nodo apuntado por aux
        do
        {
            printf("\n%i ", aux->dato);
            aux = (NODO*)aux ->next;
        }        
        while(aux != NULL);
    }
}

//Se inicializa la funcion imprimelistaatras
void ImprimeListaAtras(NODO *list)
{
	//Se declaran las variables locales de la funcion
        NODO* aux;
    
    if(list->prev == NULL)
    {
        //Lista vacia
        printf("Lista vacía\n");
    }

    else
    {
        //La lista contiene al menos un nodo inicializado
        aux = (NODO*)list->prev;
        //Imprimimr el nodo apuntado por aux
        do
        {
            printf("\n%i ", aux->dato);
            aux = (NODO*)aux ->prev;
        }        
        while(aux != NULL);
    }
}

//Se inicializa la funcion Crear nodo
NODO* CrearNodo(int dato)
{
	//Se declaran las variables locales de la funcion
	NODO *ptr;
	ptr = (NODO *)malloc(sizeof(NODO));
	if (ptr==NULL)
	{
		printf("Error al reservar memoria para el nodo");
		exit(0);
	}
	ptr->dato=dato;
	ptr->next=NULL;
	ptr->prev=NULL;
	return ptr;
}