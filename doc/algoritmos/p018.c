//Agregamos las librerias necesarias para las funciones que necesitamos
#include <stdio.h>
#include <stdlib.h>

//Declaramos una estructura
typedef struct 
{
	//Miembros de la estructura
	int *datos;
	int id;
	unsigned int size;
}PILA;//Nombre de la estructura

//Aqui ponemos los prototipos de las funciones utilizadas
PILA* CrearPila(unsigned int Tam);
void FreePila(PILA *ptr);
char Push(PILA *ptr, int dato);
char IsFull(PILA *ptr);
void PrintPila(PILA *ptr);
char Pop(PILA *p, int*d);
char IsEmpty(PILA *p);

//Inicializamos la funcion principal 
int main()
{
	//Declaracion de variables de esta funcion
	PILA *MiPila=NULL;//Declaramos la variable MiPila de tipo PILA

	MiPila = CrearPila(5);//Guardamos en mi pila la funcion crearpila con 5 elementos
	PrintPila(MiPila);//Imprimimos la pila

    //Aplicamos la función push a mipila, con el valor 10
	if(!Push(MiPila,10))
	{
		printf("\n Dato no aplicado");
	}
	//Aplicamos la función push a mipila, con el valor 20
	if(!Push(MiPila,20))
	{
		printf("\n Dato no aplicado");
	}
	//Aplicamos la función push a mipila, con el valor 30
	if(!Push(MiPila,30))
	{
		printf("\n Dato no aplicado");
	}
	//Aplicamos la función push a mipila, con el valor 40
	if(!Push(MiPila,40))
	{
		printf("\n Dato no aplicado");
	}
	//Aplicamos la función push a mipila, con el valor 50
	if(!Push(MiPila,50))
	{
		printf("\n Dato no aplicado");
	}
	//Aplicamos la función push a mipila, con el valor 60
	if(!Push(MiPila,60))
	{
		printf("\n Dato no aplicado");
	}
	//Imprimilos la pila con los valoresa gregados
	PrintPila(MiPila);
	//Eliminamos un valor de la pila
	Pop(MiPila,0);
	//Volvemos a imprimir la pila para ver los cambios aplicados
	PrintPila(MiPila);
	//Comprobamos si la pila esta vacia
	IsEmpty(MiPila);
	//Eliminamos los valores restantes de la pila
	Pop(MiPila,0);
	Pop(MiPila,0);
	Pop(MiPila,0);
	Pop(MiPila,0);
	//Imprimimos la pila una vez mas 
	PrintPila(MiPila);
	//Comprobamos si la pila esta vacia
	IsEmpty(MiPila);
	//Liberamos la memoria de la fila
	FreePila(MiPila);
	//Se imprime un salto de linea
	printf("\n");
	return 0;//se retorna el valor de 0 para verificar que haya finalizado sin problemas
}

//Inicialziamos la funcion Pop
char Pop(PILA *p, int*d)
{
	//Se declaran las varibles locales de la funcion
	char Flag;

	//Si no se ha inicializado la pila, no se puede hacer pop
    if(p->id == p->size)
    {
        printf("\nError al hacer pop, pila no inicializada");
		Flag = 0;
    } 
	else
	{
		//Se elimina el ultimo valor agregado
		p->id -= 1;
		Flag = 1;
    }
    printf("\ndespues de hacer el pop: ");
	return Flag;
}

//Inicializamos la funcion IsEmpty
char IsEmpty(PILA *p)
{
	//Comprobamos si la pila esta vacia
	if(p->id == -1)
	{
		printf("\nLa pila esta vacia");
	}
	else
	{
		printf("\nla pila tiene datos aun");
	}
}

void PrintPila(PILA *ptr)
{
	//Se declaran las varibles locales de la funcion
	int k;

    //Si no se ha creado la pila, no podemos imprimir
	if(ptr==NULL)
	{
		printf("\n Error al imprimir: la pila no esta inicializada");
		return;
	}
	//Se imprime valor a valor desde el primer dato introducido hasta el ultimo
	for(k=ptr->id;k>=0;k--)
		printf("\n%i",ptr->datos[k]);
}

//Se inicializa la funcion IsFull
char IsFull(PILA *ptr)
{
	//Se verifica si se lleno la fila segun el numero de datos que recibe
	if(ptr->id == (ptr->size-1))
		return 1;
	else
		return 0;
}

//Se inicializa la funcion push
char Push(PILA *ptr, int dato)
{
	//Se declaran las varibles locales de la funcion
	char Flag = 0;

    //Si no se ha creado la pila, no podemos hacer push
	if(ptr==NULL)
		printf("\n Error: la pila no esta inicializada");
	else if(!IsFull(ptr))
	{
		//Se agrega el dato que ingresamos en la funcion main
		ptr -> id++;
		ptr ->datos[ptr->id] = dato;
		Flag = 1;
	}
	return Flag;
}

//Se inicializa la variable crearPila
PILA* CrearPila(unsigned int Tam)
{
	//Declaracion de variables de esta funcion
	//Se declara una variable ptr_a_pila de tipo PILA
	PILA *ptr_a_pila;

    //Se reserva memoria
	ptr_a_pila = (PILA *)malloc(sizeof(PILA));

    //Error al reservar la memoria
	if(ptr_a_pila==NULL)
	{
		printf("Error al reservar la memoria para la pila.");
		exit(0);
	}

    //Se define el tamaño de la pila al momento de crearla
	ptr_a_pila->id=-1;
	ptr_a_pila->size=Tam;
	//Se reserva memoria
	ptr_a_pila->datos=(int *)malloc(Tam*sizeof(int));


	if(ptr_a_pila->datos==NULL)
	{
		//Error al reservar la memoria
		printf("Error al reservar la memoria para los datos de la pila");
		exit(0);
	}
	//Se retorna la variable
	return ptr_a_pila;
}

//Se inicializa la funcion Freepila
void FreePila(PILA *ptr)
{
	//Si ptr es distinto de null
	if(ptr!=NULL)
	{
	//Se libera la memoria de la pila
	free(ptr->datos);
	free(ptr);	
	}
	//Algun error al intentar liberar la memoria de la pila
	else
		printf("\n Error al liberar la pila, pila no inicializada");
}