//Agregamos las librerias necesarias para las funciones que necesitamos
#include <stdio.h>

//Aqui ponemos los prototipos de las funciones utilizadas
int busqueda_binaria(int a[], int e, int l, int r);

//Inicializamos la funcion principal 
int main()
{
	//Declaracion de variables de esta funcion
	int unsorted[] = {9,5,13,3,8,7,2,12,6,10,4,11,1};
	int sorted[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
	int index = busqueda_binaria(sorted, 12, 0, 12);

    //Se imprime el resultado
	printf("index of 14: %d\n", index);

	return 0;
}

//Inicializamos la funcion de busqueda binaria
int busqueda_binaria(int a[], int e, int l, int r)
{	
	//Declaracion de variables de esta funcion
	int mid = l + (r - l) / 2;

	if (l > r) return -1;
	if (a[mid] == e)
		return mid;
	else if (a[mid] > e)
		return busqueda_binaria(a, e, l, mid - 1);
	else
		return busqueda_binaria(a, e, mid + 1, r);
}
