#include <stdio.h>//Agregamos la librería stdio.h que contiene las funciones básicas del lenguaje de programación C.

void CapturaMatriz(int Ma[][10], unsigned int M, unsigned int N);//Aqui Se ponen los prototipos de las funciones que vayamos utilizando, cada uno conforme a su respectiva función.
void ImprimeMatriz(int Ma[][10], unsigned int M, unsigned int N);
char SumaMatrices(int A[][10], unsigned int Ma, unsigned int Na,int B[][10], unsigned int Mb, unsigned int Nb,int C[][10], unsigned int Mc, unsigned int Nc);
char ProductoMatrices(int A[][10], unsigned int Ma, unsigned int Na,int B[][10], unsigned int Mb, unsigned int Nb,int C[][10], unsigned int Mc, unsigned int Nc);


int main()//Inicia función Principal
{ int A[10][10];//Se declaran las variables.
	int B[10][10];
	int C[10][10];
  unsigned int Ma,Na,Mb,Nb,Mc,Nc;
  char flag;//flag se utilzia para almacenar un valor binario

  //Para poder imprimir nuestra matriz necesitamos filas y columnas, así que le pedimos al usuario la cantidad de cada una que tendrá la matriz.
	printf("\nIngrese el numero de filas de la matriz A: ");
	scanf("%u",&Ma);//El número de filas se guarda en Ma.
	printf("\nIngrese el numero de columnas de la matriz A: ");
	scanf("%u",&Na);//El número de columnas se guarda en Na.

	CapturaMatriz(A,Ma,Na);//Se aplica la función "CapturaMatriz" para las variables A,Ma,Na.
	ImprimeMatriz(A,Ma,Na);//Se aplica la función "ImprimeMatriz" para las variables A,Ma,Na.

  //Para poder hacer suimar o multiplciar matrices, se encesitan al menos 2 matrices, entonces aquí al igual que con la primera, pedimos los datos.
	printf("\nIngrese el numero de filas de la matriz B: ");
	scanf("%u",&Mb);//El número de filas se guarda en Mb.
	printf("\nIngrese el numero de columnas de la matriz B: ");
	scanf("%u",&Nb);//El número de columnas se guarda en Nb.

	CapturaMatriz(B,Mb,Nb);//Se aplica la función "CapturaMatriz" para las variables B,Mb,Nb.
	ImprimeMatriz(B,Mb,Nb);//Se aplica la función "ImprimeMatriz" para las variables B,Mb,Nb.

	flag = SumaMatrices(A,Ma,Na,B,Mb,Nb,C,Mc,Nc);//se iguala flag y la función.

	printf("\n");//Aqui solo se imprime un salto de linea.

	if(flag)//De ser que no haya habido errores en cuanto a la suma, continua con la impresión d ela amtriz resultante.
		{ Mc=Ma;
			Nc=Na;
			printf("\nA+B=");
		ImprimeMatriz(C,Mc,Nc);//Utiliza la función para imprimir la matriz C.
	}
  else//Si hubo algún proble, imprime un mensaje de que no se pudo ahcer la operación.
  	printf("La suma de las matrices no es posible porque no tiene las mismas dimensiones");
    Mc=Ma;
    Nc=Nb;
	printf("\n");//Aqui solo se imprime un salto de linea.


	flag = ProductoMatrices(A,Ma,Na,B,Mb,Nb,C,Mc,Nc);//ahora se iguala flag y la función.

	printf("\n");//Aqui solo se imprime un salto de linea
	if(flag)//De ser que no haya habido errores en cuanto a la suma, continua con la impresión d ela amtriz resultante.
		{
			printf("\nA*B=");
		ImprimeMatriz(C,Mc,Nc);//Utiliza la función para imprimir la matriz C.
	}
  else//Si hubo algún proble, imprime un mensaje de que no se pudo ahcer la operación.
  	printf("El producto de las matrices no es posible");
	printf("\n");//Aqui solo se imprime un salto de linea

	return 0;
}

char ProductoMatrices(int A[][10], unsigned int Ma, unsigned int Na,int B[][10], unsigned int Mb, unsigned int Nb,int C[][10], unsigned int Mc, unsigned int Nc)//Se inicia la funcion "ProductoMatrices".
{ unsigned int i,j,k;//Se declaran las variables locales de la función.
	if((Na==Mb)&&(Mc==Ma)&&(Nc==Nb))//Para poder multiplicar 2 matrices, las filas de A debe ser la misma cantidad que las columnas de B, asíq eu se ahce la comparación.
	{ for(i=0; i<Mc; i++)
		for(j=0; j<Nc; j++)//Se inician 2 ciclos for para poder multiplicar.
			{ C[i][j] = 0;
				for(k=0;k<Na;k++)
			      C[i][j] += A[i][k]*B[k][j];//Aquí se hace la multiplicación de las matrices
		}
		return 1;//De que la comparación sea correcta, retorna un 1.
	}
  return 0;//De no ser así, retorna un 0.
}

char SumaMatrices(int A[][10], unsigned int Ma, unsigned int Na,int B[][10], unsigned int Mb, unsigned int Nb,int C[][10], unsigned int Mc, unsigned int Nc)//Se inicia la funcion "SumaMatrices".
{ unsigned int i,j;//Se declaran las variables locales de la función.
	if((Ma==Mb)&&(Na==Nb))//Para poder sumar 2 matrices, las 2 deben tener las mismas dimenciones, así que aquí se hace la comparación, si las filas y columnas son del mismo tamaño.
	{ for(i=0; i<Ma; i++)
		for(j=0; j<Na; j++)//Se inician dos ciclos for para poder ir haciendo la suma de los elementos.
			C[i][j]=A[i][j]+B[i][j];//El resultado de la suma se guarda en la matriz C.
		return 1;//De que la comparación sea correcta, retorna un 1.
	}
  return 0;//De no ser así, retorna un 0.
}

void ImprimeMatriz(int Ma[][10], unsigned int M, unsigned int N)//Se inicia la funcion "ImprimeMatriz".
{ unsigned int i,j;//Se declaran las variables locales de la función.

	for(i=0; i<M; i++)
	{   printf("\n");//Aqui solo se imprime un salto de linea
		for(j=0; j<N; j++)//Se inician dos ciclos for uno dentro de otro, para poder imprimir los datos.
		  printf("%i, ",Ma[i][j]);//Este es el código que imprime el dato como tal, se agrega una coma para separar los datos de la matriz.
		}

}

void CapturaMatriz(int Ma[][10], unsigned int M, unsigned int N)//Se inicia la funcion "CapturaMatriz".
{ unsigned int i,j;//Se declaran las variables locales de la función.

	for(i=0; i<M; i++)
		for(j=0; j<N; j++)//Se inician dos ciclos for uno dentro de otro, para poder capturar los datos.
		{ printf("\nM[%i][%i]=",i,j);//Aquí se imprime la posición de la amtriz, para que el usuario sepa en que posición de esta se va a guardar el dígito.
	      scanf("%i",&Ma[i][j]);//Se guardan todos los dígitos dentro de la matriz.
		}
}