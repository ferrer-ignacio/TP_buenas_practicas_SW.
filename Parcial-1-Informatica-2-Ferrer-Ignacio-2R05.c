#include <stdio.h>
#include <string.h>

struct lista_libros{
	char titulo[100];
	char autor[50];
	int anioPublicacion;
};

struct lista_libros libro[100];

void cargarLibros(struct lista_libros *libro,int cant_libros,int *bandera);
//función para cargar libros uno a uno
void mostrarLibros(struct lista_libros *libro, int cant_libros, int bandera);
//Función que muestra la lista de todos los libros cargados
void guardarLibros(struct lista_libros *libro, int cant_libros, int bandera);
//Función para cargar la lista de libros en un archivo de texto
void buscarLibro(struct lista_libros *libro, int cant_libros, int bandera);
//Función para buscar un libro dentro de la lista cargada


int main(int argc, char *argv[]) {
	struct lista_libros libro;
	int opcion,bandera = 0, cant_libros;
	
	do{
		printf("\t--Menú--\n");
		printf("Ingrese la opción que desea realizar\n");
		printf("1: Cargar nuevos libros\n");
		printf("2: Mostrar todos los libros cargados\n");				//Menú de opciones del programa
		printf("3: Buscar libros desde 'busqueda.txt'\n");
		printf("4: Guardar libros en 'libros.txt'\n");
		printf("Presione 0 para salir del programa\n");
		scanf("%d",&opcion);
		switch(opcion){
			case 1:
				printf("Cuántos libros desea ingresar?\n");
				scanf("%d",&cant_libros);
				getchar();												//El getchar() limpia el búfer después del scanf
				cargarLibros(&libro, cant_libros, &bandera);
			break;
		
			case 2:
				if(bandera == 1)
				{
					mostrarLibros(&libro, cant_libros, bandera);
				}
				else
				{
					printf("Primero debe ingresar libros. Seleccione la opción 1\n");				//Si la bandera es 0, aún no se ha creado la lista de libros, por lo que no se puede imprimir nada
				}
			break;
				
			case 3:
				if(bandera == 1)
				{
					buscarLibro(&libro, cant_libros, bandera);
				}
				else
				{
					printf("Primero debe ingresar libros. Seleccione la opción 1\n");			//Si la bandera es 0, no se puede buscar nada, porque no se han ingresado libros
				}
			break;
			
			case 4:
				if(bandera == 1)
				{
					guardarLibros(&libro, cant_libros, bandera);
				}
				else
				{
					printf("No hay libros cargados que guardar. Ingrese primero una lista de libros\n");
				}
			break;
		}
	} while(opcion != 0);
	return 0;
}

void cargarLibros(struct lista_libros *libro, int cant_libros, int *bandera){
	int i;
	
	for(i=0;i<cant_libros;i++){
		printf("\nLIBRO NUMERO %d\n",i+1);
		printf("Ingrese el título\n");
		scanf("%s",libro[i].titulo);						//Bucle que guarda los libros uno a uno en un arreglo de estructuras
		printf("Ingrese el autor\n");
		scanf("%s",libro[i].autor);
		printf("Ingrese el año de publicación\n");
		scanf("%d",&libro[i].anioPublicacion);
	}
	*bandera = 1;											//Actualizo la bandera para saber que ya tengo ingresada una lista de libros
}

void mostrarLibros(struct lista_libros *libro, int cant_libros, int bandera){
	int i;
	
	for(i=0;i<cant_libros;i++){
		printf("\nLIBRO NUMERO %d\n",i+1);
		printf("Título: %s\n",libro[i].titulo);							//Muestro uno por uno los libros de la lista
		printf("Autor: %s\n",libro[i].autor);
		printf("Año de publicación: %d\n",libro[i].anioPublicacion);
	}
}

void buscarLibro(struct lista_libros *libro, int cant_libros, int bandera){
	int i,opcion,anoPublicacion_buscado,coincidencias;
	char titulo_buscado[100], autor_buscado[50];
	
	printf("Ingrese por qué parámetro desea buscar\n");
	printf("1: Buscar por título\n");
	printf("2: Buscar por autor\n");							//Menú para buscar libros por un parámetro elegido por el usuario
	printf("3: Buscar por año de publicación\n");
	scanf("%d", &opcion);
	
	switch(opcion){
		case 1:
			coincidencias=0;
			printf("Ingrese el título a buscar\n");
			scanf("%s",titulo_buscado);
			for(i=0;i<cant_libros;i++)
			{
				if(strstr(libro[i].titulo, titulo_buscado) != NULL)
				{
					printf("\nLIBRO NUMERO %d\n",i+1);								//Si encuentro una coincidencia la imprimo
					printf("Título: %s\n",libro[i].titulo);
					printf("Autor: %s\n",libro[i].autor);
					printf("Año de publicación: %d\n",libro[i].anioPublicacion);
					coincidencias++;												//Actualizo las coincidencias a un numero distinto de 0
				}
			}
			if(coincidencias == 0)
			{
				printf("No se encontró ningún libro con ese título\n");
			}
		break;
		
		case 2:
			coincidencias=0;
			printf("Ingrese el autor a buscar\n");
			scanf("%s",autor_buscado);
			for(i=0;i<cant_libros;i++)
			{
				if(strstr(libro[i].autor, autor_buscado) != NULL)
				{
					printf("\nLIBRO NUMERO %d\n",i+1);
					printf("Título: %s\n",libro[i].titulo);								//Si encuentro una coincidencia la imprimo
					printf("Autor: %s\n",libro[i].autor);
					printf("Año de publicación: %d\n",libro[i].anioPublicacion);
					coincidencias++;													//Actualizo las coincidencias a un numero distinto de 0
				}
			}
			if(coincidencias == 0)
			{
				printf("No se encontró ningún libro de ese autor\n");
			}
		break;
			
		case 3:
			coincidencias = 0;
			printf("Ingrese el ano de publicación a buscar\n");
			scanf("%d",&anoPublicacion_buscado);
			for(i=0;i<cant_libros;i++)
			{
				if(libro[i].anioPublicacion == anoPublicacion_buscado)
				{
					printf("\nLIBRO NUMERO %d\n",i+1);
					printf("Título: %s\n",libro[i].titulo);								//Si encuentro una coincidencia la imprimo
					printf("Autor: %s\n",libro[i].autor);
					printf("Año de publicación: %d\n",libro[i].anioPublicacion);
					coincidencias++;													//Actualizo las coincidencias a un numero distinto de 0
				}
			}
			if(coincidencias == 0)
			{
				printf("No se encontró ningún libro publicado ese año.\n");
			}
		break;
	}
}

void guardarLibros(struct lista_libros *libro, int cant_libros, int bandera){
	int i;
	FILE *archivo;
	
	archivo = fopen("libros.txt","w");												//Guardo los libros en un archivo de texto llamado libros.txt
	if(archivo != NULL)
	{
		for(i=0;i<cant_libros;i++)
		{
			fprintf(archivo,"\nLibro %d: \n",i+1);
			fprintf(archivo,"Título: %s \n",libro[i].titulo);
			fprintf(archivo,"Autor: %s \n",libro[i].autor);
			fprintf(archivo,"Año de publicación: %d \n",libro[i].anioPublicacion);
		}
		printf("Libros guardados correctamente en 'libros.txt'\n");
		fclose(archivo);
	}
	else
	{
		printf("Problemas al abrir 'libros.txt'. Intente nuevamente");
	}
	
}
