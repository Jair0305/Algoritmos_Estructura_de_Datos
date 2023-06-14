#include<stdio.h>//Agregamos la librería stdio.h que contiene las funciones básicas del lenguaje de programación C.

float PromedioVector(int X[], unsigned int Ne);//Aqui Se ponen los prototipos de las funciones que vayamos utilizando, cada uno conforme a su respectiva función.
void CapturarVector(int X[], unsigned int Ne);
void ImprimeVector(int X[], unsigned int Ne);

int main()//Inicia función Principal
{ int Vector[100];//Declaracion de las variables, en el caso de esta línea de códigco, tenemos una cadena.
  unsigned int N;
  float promedio;

  printf("\nNumero de elementos que va a capturar: ");//pedimos un numero mediante un texto que se muestra al usuario.
  scanf("%u",&N);//guardamos el numero en la variable ya decalrada anteriormente "N".

  CapturarVector(Vector,N);//Aplicamos la funcion "CapturaVector" al número N y a la cadena Vector.
  printf("\nEl vector capturado es: ");//Aquí imprimimos un breve mensaje al usuario previo de mandar el resultado.
  ImprimeVector(Vector,N);//Aplicamos la función "ImprimeVector" al número N y a la cadena "Vector".

  promedio=PromedioVector(Vector,N);//Aplicamos la función "PromedioVector" al número N y ala cadena Vector y lo guardamos en la variable promedio.

  printf("\n El promedio es: %f",promedio);//Imprimimos el resultado del promedio.
  printf("\n");//Aqui solo se imprime un salto de linea.
  return 0;//se retorna el valor de 0 para verificar que haya finalizado sin problemas
}

void ImprimeVector(int X[], unsigned int Ne)//Empieza la función "ImprimeVector".
{ unsigned int i;//Se declaran las variables locales de esta función
	for(i=0;i<Ne;i++)//en este ciclo el contador va imprimiendo los números, hasta llegar a el número de números que tendrá el vector, digitado anteriormente por el usuario.
		printf("\nV[%i]=%i",i,X[i]);//Se imprime el número digitado por el usuario con su respectiva posición según el contador.
	

}

void CapturarVector(int X[], unsigned int Ne)//Empieza la función "CapturarVector".
{ unsigned int i;//Se declara la variable local de esta función.

  for(i=0; i<Ne; i++)//En este ciclo el contador va capturando los números, hasta llegar a el número de números que tendrá el vector, digitado anteriormente por el usuario.
  	  {
  	  	printf("\nX[%i]=",i);//Se imprime el número del vector, indicando a el usuario que capture el número como tal.
  	  	scanf("%i",&X[i]);//Se guarda el valor del número.
  	  }
	
}

float PromedioVector(int X[], unsigned int Ne)//Empieza la función "PromedioVector".
{ unsigned int i;//Se declaran las variables locales de esta función.
  int suma=0;
  float prom;

  for(i=0; i<Ne; i++)//Se inicia un ciclo que irá sumando los números del vector ya antes digitados.
  	  suma+=X[i];//Se van sumando todos los números del vector y se guarda en la variable suma.
  prom=suma/(float)Ne;//Se saca el promedio de la suma y se guarda en prom. Hace falta cambiar la variable Ne de int a float.
  return prom;//Se retorna la variable prom.
}

