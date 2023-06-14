#include <stdio.h>
#include <string.h>
#include <stdlib.h>	
#include <locale.h> 
 
#define MAX 80
#define VALOR_CENTINELA -1

struct persona{
	int Id;
	char nombre[20];
	char apellidoP[20];
	char apellidoM[20];
	int numero[15];
	int nr;
};
 
typedef struct persona Persona;

void menuBuscar();
void menuMostrar();

Persona *obtenerProductos(int *n);
char existeProducto(int codigoProducto, Persona *persona);
char insertarProducto(Persona persona);
char eliminarProducto(int codigoProducto);
char guardarReporte();

int leecad(char *cad, int n);

void tituloPrincipal();

char linea[MAX];

int main()
{
	Persona persona;
	int i = 1;
	char salir = 0;
	int opcion = -1;

	do {
		printf("MENU PRINCIPAL\n");
		printf("\n[1] Insertar nuevo producto\n");
		printf("[2] Mostrar listado de productos\n");
		printf("[3] Eliminar un producto\n");
		printf("[4] Buscar producto por clave\n");
		printf("[5] Modificar un producto\n");
		printf("[6] Eliminación física de registros\n");
		printf("[7] Salir\n");
		printf("\nIngrese su opción: ");
 
		leecad(linea, MAX);
		sscanf(linea, "%d", &opcion);
 
		switch (opcion) {
 
			case 1:
				insertarProducto(persona);
				break;
 
			case 2:
				menuMostrar();
				break;
 
			case 3:
				eliminarProducto(i);
				break;
 
			case 4:
				menuBuscar();
				break;
 
			case 5:
				break;
 
			case 6:
				break;
 
			case 7:
				salir = 1;
				break;
		}
 
	} while (!salir);
	return 0;
}
 
Persona *obtenerProductos(int *n)
{
	FILE *archivo;
	Persona persona;
	Persona *productos; /* Vector dinámico de productos */
	int i;
 
	/* Abre el archivo en modo lectura */
	archivo = fopen("productos.dat", "rb");
 
	if (archivo == NULL) { /* Si no se pudo abrir el archivo, el valor de archivo es NULL */
		*n = 0; /* No se pudo abrir. Se considera n  */
		productos = NULL;
	} else {
 
		fseek(archivo, 0, SEEK_END); /* Posiciona el cursor al final del archivo */
		*n = ftell(archivo) / sizeof(Persona); /* # de productos almacenados en el archivo. (# de registros) */
		productos = (Persona *)malloc((*n) * sizeof(Persona)); /* Se reserva memoria para todos los productos almacenados en el archivo */
 
		/* Se recorre el archivo secuencialmente */
		fseek(archivo, 0, SEEK_SET); /* Posiciona el cursor al principio del archivo */
		fread(&persona, sizeof(persona), 1, archivo);
		i = 0;
		while (!feof(archivo)) {
			productos[i++] = persona;
			fread(&persona, sizeof(persona), 1, archivo);
		}
 
		/* Cierra el archivo */
		fclose(archivo);
	}
 
	return productos;
}

void menuBuscar()
{
	Persona persona;
	int id;
	char repite = 1;
	char respuesta[MAX];
 
	do {
		printf("\nNumero de registro: ");
		leecad(linea, MAX);
		sscanf(linea, "%d", id);

		if (existeProducto(id, &persona)) {
 
			printf("\n\tCódigo del producto: %d\n", persona.Id);
			printf("\tNombre del producto: %s\n", persona.nombre);			
			printf("\tCosto del producto: %s $\n", persona.apellidoP);
			printf("\tPrecio del producto: %s $\n", persona.apellidoM);
			printf("\tCantidad: %i\n", persona.numero);
 
		} else {
			/* El producto no existe */
			printf("\n\tEl producto de código %d no existe.\n", id);
		}
 
		printf("\n\tDesea seguir buscando algún producto? [S/N]: ");
		leecad(respuesta, MAX);
 
		if (!(strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0)) {
			repite = 0;
		}
 
	} while (repite);
}

void menuMostrar()
{
	Persona *persona;
	int numeroProductos;
	int i;
	float costoTotal;
	float precioTotal;
	int cantidadTotal;
	char respuesta[MAX];

	persona = obtenerProductos(&numeroProductos); 
 
	if (numeroProductos == 0) {
		printf("\n\tEl archivo está vacío!!\n");
		getchar();
 
	} else {
		for (i = 0; i < numeroProductos; i++) {
			if (persona[i].Id != VALOR_CENTINELA) {
				printf("%d %s %s %s %d\n", persona[i].Id, persona[i].nombre, persona[i].apellidoP, persona[i].apellidoM, persona[i].numero);
			}
		}
 
			getchar();
		}
}


 
char insertarProducto(Persona persona)
{
	FILE *archivo;
	char insercion;

	archivo = fopen("productos.dat", "ab");	
 
	if (archivo == NULL) { 
		insercion = 0;
 
	} else {
		fwrite(&producto, sizeof(producto), 1, archivo);
		insercion = 1;
 
		/* Cierra el archivo */
		fclose(archivo);
	}
 
	return insercion;
}
 
char eliminarProducto(int codigoProducto)
{
	FILE *archivo;
	FILE *auxiliar;
	Persona persona;
	char elimina;
 
	archivo = fopen("productos.dat", "r+b");
 
	if (archivo == NULL) { 
		elimina = 0;
 
	} else {
		elimina = 0;
		fread(&persona, sizeof(persona), 1, archivo);
		while (!feof(archivo)) {
			if (persona.Id == codigoProducto) {
				fseek(archivo, ftell(archivo) - sizeof(persona), SEEK_SET);
				persona.Id = VALOR_CENTINELA;
				fwrite(&persona, sizeof(persona), 1, archivo);
				elimina = 1;
				break;
			}
			fread(&producto, sizeof(producto), 1, archivo);
		}
 
		fclose(archivo);
	}
 
	return elimina;
}
 
int leecad(char *cad, int n)
{
	int i, c;
	c = getchar();
	if (c == EOF) {
		cad[0] = '\0';
		return 0;
	}
	if (c == '\n') {
		i = 0;
	} else {
		cad[0] = c;
		i = 1;
	}
	for (; i < n - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
		cad[i] = c;
	}
	cad[i] = '\0';

	if (c != '\n' && c != EOF)
		while ((c = getchar()) != '\n' && c != EOF);
 
	return 1;
}