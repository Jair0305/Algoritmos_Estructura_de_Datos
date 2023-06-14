#include<stdio.h>
#include<stdlib.h>

//Se declara una estructura llamada UNIDAD DE APRENDIZAJE
//con los miembros Id, Nombre, Area, Tipo, NumCre y HorasSem
typedef struct
{ 
	unsigned char Id;
  char Nombre[100];
  char Area[50];
  char Tipo[50];
  unsigned int NumCre;
  unsigned char HorasSem;
}UNIDADdeAPRENDIZAJE;

//Se declara una estructura llamada UDA_ESTATUS
//con los miembros Calificacion, oportunidad y aprobada
typedef struct
{
	float Calificacion;
  unsigned int  Oportunidad;
  unsigned char Aprobada;
}UDA_ESTATUS;

//Se declara una estructura llamada PERSONA
//con los miembros Nombres, Apaterno y Amaterno
typedef struct
{
	char Nombres[40];
  char Apaterno[20];
  char Amaterno[20];
}PERSONA;

//Se declara una estructura llamada REGISTRO
//con los miembros Id, Id_UDA y tiene 2 miembos que son
//de tipo estructura als caules ya declaramos antes
typedef struct
{
	unsigned char Id;
  unsigned char Id_UDA;
  UDA_ESTATUS   Status;
  PERSONA       Profesor;   
}REGISTRO;

//Aqui van las variables globales, aqui usamos la variable del nombre del archivo
//para hacerlo mas facil de abrir, ese archivo es de donde sacamos toda la
//informacion de las udas con la que hemos estado trabajndo
const char NombreDelArhivoDeUDAS[]="ListadoUDA.txt";
//como en el archivo hay 72 udas, tambien declaramos la variable global
//del total de udas para que sea mas facil de acceder.
const unsigned char Total_UDAS=72;

//Aqui van los prototipos d elas funciones que se utilizaron durante el programa
void PrintUDA(UNIDADdeAPRENDIZAJE UDA);
void LecturaArchivoUDAS(UNIDADdeAPRENDIZAJE UDA[]);
void CapturarRegistro(REGISTRO UDAcursada[], unsigned char NumReg);
void PrintRegistro(REGISTRO UDAcursada[], unsigned char NumReg, UNIDADdeAPRENDIZAJE LisatdoUDAS[]);
void GuardarRegistros(REGISTRO UDAcursada[], unsigned int NumDeRegistros);
unsigned char LeerRegistros(REGISTRO UDAcursada[]);
float PromedioGeneral(REGISTRO UDAcursada[], unsigned char NumReg, UNIDADdeAPRENDIZAJE ListadoUDAS[]);
int TotalCreditos(REGISTRO UDAcursada[], unsigned char NumReg, UNIDADdeAPRENDIZAJE ListadoUDAS[]);
void listadou(UNIDADdeAPRENDIZAJE UDA[]);
void Printuda(UNIDADdeAPRENDIZAJE UDA);

int main()//se inicializa la funcion principal
{
  //Se declara un Arreglo de estructuras de datos de tipo UNUDAD DE APRENDIZAJE llamado UDA
  UNIDADdeAPRENDIZAJE UDA[Total_UDAS];
  //Se declara un Arreglo de estructuras de datos de tipo REGISTRO llamado UDAcursada
  REGISTRO UDAcursada[Total_UDAS];
  //aqui hay variables varias que utilizamos en la funcion principal
  unsigned char NumeroRegistros=0;
  unsigned char salir=0;
  unsigned int opcion,k;
  float promedio;
  int tc = 0;
  int aux;

//Se manda a llamar la función que lee el archivo, se ahce desde el principio para 
//poder trabajar con él, el resto del programa
LecturaArchivoUDAS(UDA);

//aqui hacemos un menú con un do-while, en este menú están las diferentes
//opciones que tiene el usuario para realizar en el programa
do
{
	printf("\n- Sistema de Registro de Calificaciones -\n");
  printf("\n1. Ingresar Registro");
  printf("\n2. Listado de Registros");
  printf("\n3. Guardar Registros");
  printf("\n4. Leer Registros");
  printf("\n5. Sacar Promedio General");
  printf("\n6. Sacar promedio por semestre");
  printf("\n7. Sacar numero de creditos");
  printf("\n8. Listado de las udas");
  printf("\n9. Salir");
  printf("\n\nOpcion: ");
  //Se captura el resultado del usuario
  scanf("%u",&opcion);
  //Se abre un switch, para que, según la respeusta del usuario,
  //se ejecute esa acción
  switch(opcion)
  {
  	case 1:
  	NumeroRegistros++;
    CapturarRegistro(UDAcursada,NumeroRegistros);
    break;

    case 2:
    for(k=0; k<NumeroRegistros; k++)
    	PrintRegistro(UDAcursada,k+1,UDA);
    break;

    case 3:
    GuardarRegistros(UDAcursada,NumeroRegistros);
    break;

    case 4:
    NumeroRegistros=LeerRegistros(UDAcursada);
    break;

    case 5:
    //Se inicia un ciclo for que repasa los registros que se han hecho
    for(k=0; k<NumeroRegistros; k++)
    //aqui con la variable promedio, mandamos a llamar a la funcion y luego
    //la imprimimos
    promedio = (PromedioGeneral(UDAcursada,k+1,UDA))/NumeroRegistros;
    printf("\n El promedio general es: %f\n",promedio);
    break;

    case 6:
    break;

    case 7:
    //Se inciia un ciclo for que repasa los registros que se han hecho
    for(k=0; k<NumeroRegistros; k++)
    {
    //Con la variable aux, llamo a la función      
      aux = TotalCreditos(UDAcursada,k+1,UDA);
      //voy sumando los resultados y los guardo en la variable tc
      tc += aux;
    }
    
    //imprimo el total de creditos
    printf("\nTotal de creditos: %u",tc);
    break;  
    
    case 8:
    listadou(UDA);
    break;

    case 9:
    salir=1;
    break;    

    default: printf("\nOpcion no valida.");
  }
}
while(!salir);

  printf(" \n");
  return 0;
}

//Esta es una funcion para imprimir el nombre de las udas con el id y los creditos
void listadou(UNIDADdeAPRENDIZAJE UDA[])
{
  FILE* Archivo;
  unsigned int aux,k;
  Archivo=fopen(NombreDelArhivoDeUDAS,"r");
  if(Archivo!=NULL)
  {
    printf("\n Aqui puede buscar la UDA con su id, si es que no la sabe");
    for(k=0; k<Total_UDAS; k++)
    {
      fscanf(Archivo,"%u",&aux);
      UDA[k].Id=aux;
      fgetc(Archivo);
      fgets(UDA[k].Nombre,100,Archivo);
      fgets(UDA[k].Area,50,Archivo);
      fgets(UDA[k].Tipo,50,Archivo);
      fscanf(Archivo,"%u",&aux);
      UDA[k].NumCre=aux;
      fscanf(Archivo,"%u",&aux);
      UDA[k].HorasSem=aux;
    }
    fclose(Archivo);
  }
  else
  {
    printf("Error al leer el archivo ListadoUDA.txt o no se encuentra \n");
    exit(0);
  }
  printf("\n\n");
  for(k=0;k<Total_UDAS;k++)
    Printuda(UDA[k]);

  printf("\n");
}

//Se inicia la función para caprturar los registros.
void CapturarRegistro(REGISTRO UDAcursada[], unsigned char NumReg)
{
  //Se declaran las variables locales de esta función
  unsigned char Indice;
  unsigned int aux;
  float Calif;
  
  
  Indice=NumReg-1;
  UDAcursada[Indice].Id=NumReg;

  //Se le va preguntando al usuario todos los datos que quiere regristrar
  //para luego guardarlos
  //Se pide el id de la uda, calificacion y oportunidad en qeu se cursó.
  printf("\nEscriba el Id correspondiente a la UDA cursada: ");
  scanf("%u",&aux);
  UDAcursada[Indice].Id_UDA=aux;
  printf("Calificacion: ");
  scanf("%f",&Calif);
  UDAcursada[Indice].Status.Calificacion=Calif;
  printf("En que Oportunidad se curso: ");
  scanf("%u",&aux);
  UDAcursada[Indice].Status.Oportunidad=aux;

  //Esta es alguna clase de if, pero comprimido por decirlo de alguna manera
  //Regresa 2 valores, 0 o 1, false o true
  UDAcursada[Indice].Status.Aprobada=(Calif<7.0)?0:1;
  
  //Eliminamos la tecla "Enter" que se queda en el buffer del teclado despues de leer la oportunidad
  //Se piden los datos del profesor que impartió la uda
  gets(&UDAcursada[Indice].Profesor.Nombres[0]);
  printf("Nombre(s) del profesor:  ");
  gets(&UDAcursada[Indice].Profesor.Nombres[0]);
  printf("Apellido Paterno:  ");
  gets(&UDAcursada[Indice].Profesor.Apaterno[0]);
  printf("Apellido Materno:  ");
  gets(&UDAcursada[Indice].Profesor.Amaterno[0]);
}

//Aqui se inicia la funcion para sacar el total de creditos
int TotalCreditos(REGISTRO UDAcursada[], unsigned char NumReg, UNIDADdeAPRENDIZAJE ListadoUDAS[])
{
  //decalramos una variable aux
	unsigned int aux=0;

  //abrimos un if, en el que si la materika está aprobada, aux vale la cantidad de creditos
  if(UDAcursada[NumReg-1].Status.Aprobada)
    aux = ((int)(ListadoUDAS[NumReg-1].NumCre));
  //en caso de que la materia no haya sido aprobada, los creditos no se suman 
  else 
    aux = 0;

  return aux;
}

//Aqui se inicia la funcion del promedio general
float PromedioGeneral(REGISTRO UDAcursada[], unsigned char NumReg, UNIDADdeAPRENDIZAJE ListadoUDAS[])
{
  //declaramos una variable float llamada aux
	float aux;
  
  // aqui se van sumando las calificaciones que ya registró el usuario
  aux = aux + UDAcursada[NumReg-1].Status.Calificacion;

  //se retorna la variable aux
	return aux;
}

//Aqui se leen los registros hechos por el usuario
unsigned char LeerRegistros(REGISTRO UDAcursada[])
{
  FILE* Archivo;
  unsigned int aux,k;
  unsigned char NumeroDeRegistros;

  Archivo=fopen("registroUDAS.txt","r");
  if(Archivo!=NULL)
  {
  printf("\n Se ha abierto el archivo");
  fscanf(Archivo,"%u",&aux);
  NumeroDeRegistros=aux;
  //Aqui hace el recuento de los registros, al pasar por todos estos, aumenta k
  //que es el numero de registros que se han hecho
  for(k=0; k<NumeroDeRegistros; k++)
  {
  	fscanf(Archivo,"%u",&aux);
    UDAcursada[k].Id=aux;
    fscanf(Archivo,"%u",&aux);
    UDAcursada[k].Id_UDA=aux;
    fscanf(Archivo,"%u",&UDAcursada[k].Status.Calificacion);
    fscanf(Archivo,"%u",&aux);
    UDAcursada[k].Status.Oportunidad=aux;
    fscanf(Archivo,"%u",&aux);
    UDAcursada[k].Status.Aprobada=aux;
    fgetc(Archivo);
    fgets(UDAcursada[k].Profesor.Nombres,40,Archivo);
    fgets(UDAcursada[k].Profesor.Apaterno,20,Archivo);
    fgets(UDAcursada[k].Profesor.Amaterno,20,Archivo);
  }

  fclose(Archivo);
  printf("\n Se leyeron %u registros y se cerro el archivo\n",NumeroDeRegistros);
  
  //al haber hecho el recuento, se imprime la cantidad de registros que se hicieron
  }
  else
  {
  	printf("Error al leer el archivo ListadoUDA.txt o no se encuentra \n");
    exit(0);
  }
}

//Aqui se inicia la función para guardar los registros
void GuardarRegistros(REGISTRO UDAcursada[], unsigned int NumDeRegistros)
{ 
	FILE* Archivo; 
  unsigned int i;
  
  //Crea un archivo en modo escritura
  Archivo=fopen("registroUDAS.txt","w");
 
  //Validar el resultado de la creación del archivo
  if(Archivo!=NULL)
  {
    //Se creo el archivo para escritura correctamente
  	fprintf(Archivo,"%u\n",NumDeRegistros);
    for(i=0; i<NumDeRegistros; i++)
    {
    	fprintf(Archivo,"%u\n",UDAcursada[i].Id);
      fprintf(Archivo,"%u\n",UDAcursada[i].Id_UDA);
      fprintf(Archivo,"%g\n",UDAcursada[i].Status.Calificacion);
      fprintf(Archivo,"%u\n",UDAcursada[i].Status.Oportunidad);
      fprintf(Archivo,"%u\n",UDAcursada[i].Status.Aprobada);
      fprintf(Archivo,"%s\n",UDAcursada[i].Profesor.Nombres);
      fprintf(Archivo,"%s\n",UDAcursada[i].Profesor.Apaterno);
      fprintf(Archivo,"%s\n",UDAcursada[i].Profesor.Amaterno);
    }
    //Cerrar el archivo cuando ya terminamos de usarlo
    fclose(Archivo);
    printf("\nregistros guardados correctamente.\n");
  }
  else
  //Error al crear el archivo para escritura
  	printf("Error: no se pudo crear el archivo \n");
    printf(" \n");
}

//ESta funcion imprime los registros que el usuario haya ingresado
void PrintRegistro(REGISTRO UDAcursada[], unsigned char NumReg, UNIDADdeAPRENDIZAJE ListadoUDAS[])
{
  //solo retoma los mismos datos que ingreso el usuario
  //calificacion, oprtunidad, profesos y si ses que aprobo la materia
  printf("\n Registro %i:",UDAcursada[NumReg-1].Id);
  PrintUDA( ListadoUDAS[ UDAcursada[NumReg-1].Id_UDA - 1 ] ); 
  printf("\n Calificacion: %2.2f",UDAcursada[NumReg-1].Status.Calificacion);
  printf("\n Oportunidad: %i",UDAcursada[NumReg-1].Status.Oportunidad);
  if(UDAcursada[NumReg-1].Status.Aprobada)
     printf("\n UDA Aprobada");
  else
     printf("\n UDA NO Aprobada");
  printf("\n Profesor: %s %s %s\n",UDAcursada[NumReg-1].Profesor.Nombres,UDAcursada[NumReg-1].Profesor.Apaterno,UDAcursada[NumReg-1].Profesor.Amaterno);
}

//Esta funcion es la que se encarga de sacar toda la informacion del archivo del que trabajamos
void LecturaArchivoUDAS(UNIDADdeAPRENDIZAJE UDA[])
{ 
	FILE* Archivo;
  unsigned int aux,k;
  Archivo=fopen(NombreDelArhivoDeUDAS,"r"); //se abre el archivo
  if(Archivo!=NULL)
  {
  	printf("\n Se ha abierto el archivo");
    for(k=0; k<Total_UDAS; k++)
    {
      //de aqui extrae los datos que tiene el archivo y los guarda
    	fscanf(Archivo,"%u",&aux);
      UDA[k].Id=aux;
      fgetc(Archivo);
      fgets(UDA[k].Nombre,100,Archivo);
      fgets(UDA[k].Area,50,Archivo);
      fgets(UDA[k].Tipo,50,Archivo);
      fscanf(Archivo,"%u",&aux);
      UDA[k].NumCre=aux;
      fscanf(Archivo,"%u",&aux);
      UDA[k].HorasSem=aux;
    }
    fclose(Archivo); //se cierra el archivo
    printf("\n Se leyeron todos los registros y se cerro el archivo");
  }
  else
  {
  	printf("Error al leer el archivo ListadoUDA.txt o no se encuentra \n");
    exit(0);
  }
}

//esta funcion imprime todos los registros que hay en el archivo
void PrintUDA(UNIDADdeAPRENDIZAJE UDA)
{ 
	printf("\nID: %u",UDA.Id);
  printf("\nNombre: %s",UDA.Nombre);
  printf("Area: %s",UDA.Area);
  printf("Tipo: %s",UDA.Tipo);
  printf("Numero de Creditos: %u",UDA.NumCre);
  printf("\nHoras por Semana: %u",UDA.HorasSem);
}

//ESta funcion hace lo mismo que al anterior, pero solo imprime el nombre de la uda, el id y los creditos
void Printuda(UNIDADdeAPRENDIZAJE UDA)
{
  printf("\nID: %u",UDA.Id);
  printf("\nNombre: %s",UDA.Nombre);
  printf("Numero de Creditos: %u\n",UDA.NumCre);
}