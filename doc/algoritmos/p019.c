//Agregamos las librerias necesarias para las funciones que necesitamos
#include <stdio.h>
#include <stdlib.h>

//Declaramos una estructura
typedef struct 
{
	//Miembros de la estructura
	int *data;
	unsigned int Id_Front;
	unsigned int Id_End;
	unsigned int Size;
}FILA;//Nombre de la estructura

//Aqui ponemos los prototipos de las funciones utilizadas
FILA* CrearFila(unsigned int Tam);
void FreeFila(FILA *pf);
void PrintFila(FILA *pf);
char Enqueue(FILA *pf, int dato);
char IsFull(FILA *pf);
char Dequeue(FILA *p, int *dato);
char IsEmpty(FILA *p);
char FrontofQueue(FILA *p,int*dato);
unsigned int SizeofQueue(FILA *p);

//Inicializamos la funcion principal 
int main()
{
	//Declaracion de variables de esta funcion
	FILA *Fila1=NULL;//Declaramos la variable MiPila de tipo FILA

	PrintFila(Fila1);//Imprimimos la pila

	if(!Enqueue(Fila1,10))//aplicamos la funcion enqueue a fila1, con elv alor de 10
		printf("\n Dato no entro en la fila.");
	Fila1 = CrearFila(5);//Guardamos en Fila1 la funcion crearFila con 6 elementos
	IsEmpty(Fila1);
	//aplicamos la funcion enqueue a fila1, con elv alor de 10
	if(!Enqueue(Fila1,10))
		printf("\n Dato no entro en la fila.");
	//aplicamos la funcion enqueue a fila1, con elv alor de 20
	if(!Enqueue(Fila1,20))
		printf("\n Dato no entro en la fila.");
	//aplicamos la funcion enqueue a fila1, con elv alor de 30
	if(!Enqueue(Fila1,30))
		printf("\n Dato no entro en la fila.");
	//aplicamos la funcion enqueue a fila1, con elv alor de 40
	if(!Enqueue(Fila1,40))
		printf("\n Dato no entro en la fila.");
	//aplicamos la funcion enqueue a fila1, con elv alor de 50
	if(!Enqueue(Fila1,50))
		printf("\n Dato no entro en la fila.");
	//aplicamos la funcion enqueue a fila1, con elv alor de 60
	if(!Enqueue(Fila1,60))
		printf("\n Dato no entro en la fila.");
	printf("\nLa fila es al siguiente: \n");

    //Imprimimos la fila con los valores agregados
	PrintFila(Fila1);
	//Mostramos el primer valor de la fila
	FrontofQueue(Fila1,0);
	//Mostramos la cantidad de datos de la fila
	SizeofQueue(Fila1);
	//Eliminamos el primer valor de la fila
	Dequeue(Fila1,0);
	//Se imprime la fila con el valor eliminado
	PrintFila(Fila1);
	//Verificamos si la fila esta vacia
	IsEmpty(Fila1);
	//Con un valor menos, volvemos a imprimir el valor
	FrontofQueue(Fila1,0);
	//Con un valor menos, volvemos a mostrar la cantidad de datos de la fila
	SizeofQueue(Fila1);
	//Eliminamos el primer valor de la fila
	Dequeue(Fila1,0);
	//Eliminamos el primer valor de la fila
	Dequeue(Fila1,0);
	//Eliminamos el primer valor de la fila
	Dequeue(Fila1,0);
	//Eliminamos el primer valor de la fila
	Dequeue(Fila1,0);
	//Se imprime la fila con los valores eliminados
	PrintFila(Fila1);
	//Comprobamos si la fila esta vacia
	IsEmpty(Fila1);
	//Mostramos la cantidad de datos de la fila
	SizeofQueue(Fila1);

    //Liberamos la memoria de la fila
	FreeFila(Fila1);

    //Se imprime un salto de linea
	printf("\n");
	return 0;//se retorna el valor de 0 para verificar que haya finalizado sin problemas
}

//Se inicializa la funcion dequeue
char Dequeue(FILA *p, int *dato)
{
	//Declaracion de varibales de la funcion
	char Flag;

    //Se comprueba si la fila existe
    if(p->Id_Front == p->Size)
    {
        printf("\nError al hacer el dequeue, fila no inicializada");
		Flag = 0;
    } 
	else
	{
		//Elimina el ultimo primer valor de la fila
		p->Id_Front += 1;
		Flag = 1;
    }
    printf("\ndespues de hacer el dequeue: ");
	return Flag;
}

//Se inicializa la funcion IsEmpty
char IsEmpty(FILA *p)
{
	char Flag = 0;
	//En caso de que la pila este vacia se muestra el mensaje
	if(p->Id_End==p->Id_Front)
	{
		printf("\n La Fila essta vacia!");
		return Flag;
	}
	else
	{
		//De ser la contrario muestra este otro mensaje
		printf("\n La fila no esta vacia");
	}
}

//Se inicializa la funcion frontofqueue
char FrontofQueue(FILA *p,int*dato)
{
	//Se declaran las variables locales de la funcion
    char Flag;
    unsigned int frontofQ;

    //Se verifica si la pila se ha inicializado
    if(p->Id_Front == p->Size)
    {
        printf("\nError, fila no inicializada");
		Flag = 0;
    } 
    else
    {
    //Se le asigna a la variable frontofQ el valor del id front
    frontofQ = p->data[p->Id_Front];
    //Imprimimos el valor
    printf("\nFront of queue: %i", frontofQ);
    }

    return Flag;
}

//Se inicializa la funcion sizeofqueue
unsigned int SizeofQueue(FILA *p)
{
	//Se declaran las variables de la funcion
    unsigned int sizeofQ = 0;
    //Se guarda en la variable el id end menos el id front
    sizeofQ = p->Id_End - p->Id_Front;

    //Se imprime el valor
    printf("\nLa fila tiene %u datos.",sizeofQ);
    return sizeofQ;
}

//Se inicializa la funcion IsFull
char IsFull(FILA *pf)
{
	//Se verifica si la fila se llena
	if(pf->Id_End<pf->Size)
		return 0;
	else
		return 1;
}

//Se inicializa la funcion enqueue
char Enqueue(FILA *pf, int dato)
{
	//Se declaran las variables locales de la funcion
	char Flag=0;
    
    //Se verifica si la pila se ha iniciado
    if (pf==NULL)
    {
    	printf("Error: la pila no esta inicializada");
    }
    //Si la fila no esta llena...
    else if(!IsFull(pf))
    {
    //... Se agrega el dato a la fila
    	pf->data[pf->Id_End]=dato;
    	//El id aumenta en 1
	    pf->Id_End++;
	    Flag = 1;
    }
    //Se retorna Flag
    return Flag;
}

//Se inicializa la funcion printfila
void PrintFila(FILA *pf)
{
	//Se declaran las variables de esta funcion
	int k;

	//Si no se ha inicializado la fila
	if(pf==NULL)
	{
		printf("Error al imprimir");
		return;
	}
	//Imprime los datos de la fila
	for(k=pf->Id_End-1;k>=(signed int)pf->Id_Front;k--)
		printf("\n%i, ",pf->data[k]);
}

//Se inicializa la funcion crear fila del tipo FILA
FILA* CrearFila(unsigned int Tam)
{
	//Se declaran las variables de la funcion
	FILA *ptr;

    //Se reserva memoria para la fila
	ptr=(FILA *)malloc(sizeof(FILA));
    
    //Error al reservar memoria
	if(ptr==NULL)
	{
		printf("Error al reservar memoria para la fila. ");
		exit(0);
	}

    //Se asignan valores a las funciones
	ptr->Id_Front=0;
	ptr->Id_End=0;
	ptr->Size=Tam;
	//Se reserva memoria
	ptr->data=(int *)malloc(Tam*sizeof(int));

    //Error al reservar memoria
	if (ptr->data==NULL)
	{
		printf("Error al reservar memoria para los datos de la pila");
		exit(0);
	}
	//Se retorna la variable ptr
	return ptr;
}

//Se inciializa la funcion freefila
void FreeFila(FILA *pf)
{
	if(pf!=NULL)
	{   
		//Se libera la fila
		free(pf->data);
		free(pf);
	}
	//Error al liberar la fila
	else
		printf("\n Error al liberar la fila");
}