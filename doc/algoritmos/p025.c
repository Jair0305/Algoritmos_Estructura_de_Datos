#include<stdio.h>
#include<stdlib.h>

//Uso de la función QuickSort para el ordenamiento de un vector de datoas enteros

int funcionX(const void *ptr1, const void *ptr2);

int main()
{
  double datos[10]={3.72,8.32,1.56,-5.78,9.56,23.38,5.15,2.33,33.84,0.33};
  int k, Ne=10;

  printf("\nLos datos son: ");
  for(k=0; k<Ne; k++)
    printf("\n%g", datos[k]);

  qsort(datos, Ne, sizeof(double), funcionX);

  printf("\nLos datos ordenados de menor a mayor por funcion QuickSort: ");
  for(k=0; k<Ne; k++)
    printf("\n%g", datos[k]);

  return 0;
}

//Función de comparación para el método de ordenamiento QuickSort -1 0 1
int funcionX(const void *ptr1, const void*ptr2)
{
  if(((double) ptr1) > (*(double *) ptr2))
    return 1;
  else if (((double) ptr1) < (*(double *) ptr2))
    return -1;
  else
    return 0;
}