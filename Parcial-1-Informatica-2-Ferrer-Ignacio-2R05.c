#include <stdio.h>
#include <string.h>
struct lista_libros{
	char titulo[100];
	char autor[50];
	int anoPublicacion;
};

struct lista_libros libro[100];

void cargarLibros(struct lista_libros *libro,int cant_libros,int *bandera);
void mostrarLibros(struct lista_libros *libro, int cant_libros, int bandera);
void guardarLibros(struct lista_libros *libro, int cant_libros, int bandera);
void buscarLibro(struct lista_libros *libro, int cant_libros, int bandera);


int main(int argc, char *argv[]) {
	struct lista_libros libro;
	int opcion,bandera = 0, cant_libros;
	do{
		printf("\t--Men�--\n");
		printf("Ingrese la opci�n que desea realizar\n");
		printf("1: Cargar nuevos libros\n");
		printf("2: Mostrar todos los libros cargados\n");
		printf("3: Buscar libros desde 'busqueda.txt'\n");
		printf("4: Guardar libros en 'libros.txt'\n");
		printf("Presione 0 para salir del programa\n");
		scanf("%d",&opcion);
		switch(opcion){
			case 1:
				printf("Cu�ntos libros desea ingresar?\n");
				scanf("%d",&cant_libros);
				getchar();
				cargarLibros(&libro, cant_libros, &bandera);
			break;
		
			case 2:
				if(bandera == 1)
				{
					mostrarLibros(&libro, cant_libros, bandera);
				}
				else
				{
					printf("Primero debe ingresar libros. Seleccione la opci�n 1\n");
				}
			break;
				
			case 3:
				if(bandera == 1)
				{
					buscarLibro(&libro, cant_libros, bandera);
				}
				else
				{
					printf("Primero debe ingresar libros. Seleccione la opci�n 1\n");
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
		printf("Ingrese el t�tulo\n");
		scanf("%s",libro[i].titulo);
		printf("Ingrese el autor\n");
		scanf("%s",libro[i].autor);
		printf("Ingrese el a�o de publicaci�n\n");
		scanf("%d",&libro[i].anoPublicacion);
	}
	*bandera = 1;
}

void mostrarLibros(struct lista_libros *libro, int cant_libros, int bandera){
	int i;
	
	for(i=0;i<cant_libros;i++){
		printf("\nLIBRO NUMERO %d\n",i+1);
		printf("T�tulo: %s\n",libro[i].titulo);
		printf("Autor: %s\n",libro[i].autor);
		printf("A�o de publicaci�n: %d\n",libro[i].anoPublicacion);
	}
}

void buscarLibro(struct lista_libros *libro, int cant_libros, int bandera){
	int i,opcion,anoPublicacion_buscado,coincidencias;
	char titulo_buscado[100], autor_buscado[50];
	
	printf("Ingrese por qu� par�metro desea buscar\n");
	printf("1: Buscar por t�tulo\n");
	printf("2: Buscar por autor\n");
	printf("3: Buscar por a�o de publicaci�n\n");
	scanf("%d", &opcion);
	
	switch(opcion){
		case 1:
			coincidencias=0;
			printf("Ingrese el t�tulo a buscar\n");
			scanf("%s",titulo_buscado);
			for(i=0;i<cant_libros;i++)
			{
				if(strstr(libro[i].titulo, titulo_buscado) != NULL)
				{
					printf("\nLIBRO NUMERO %d\n",i+1);
					printf("T�tulo: %s\n",libro[i].titulo);
					printf("Autor: %s\n",libro[i].autor);
					printf("A�o de publicaci�n: %d\n",libro[i].anoPublicacion);
					coincidencias++;
				}
			}
			if(coincidencias == 0)
			{
				printf("No se encontr� ning�n libro con ese t�tulo\n");
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
					printf("T�tulo: %s\n",libro[i].titulo);
					printf("Autor: %s\n",libro[i].autor);
					printf("A�o de publicaci�n: %d\n",libro[i].anoPublicacion);
					coincidencias++;
				}
			}
			if(coincidencias == 0)
			{
				printf("No se encontr� ning�n libro de ese autor\n");
			}
		break;
			
		case 3:
			coincidencias = 0;
			printf("Ingrese el ano de publicaci�n a buscar\n");
			scanf("%d",&anoPublicacion_buscado);
			for(i=0;i<cant_libros;i++)
			{
				if(libro[i].anoPublicacion == anoPublicacion_buscado)
				{
					printf("\nLIBRO NUMERO %d\n",i+1);
					printf("T�tulo: %s\n",libro[i].titulo);
					printf("Autor: %s\n",libro[i].autor);
					printf("A�o de publicaci�n: %d\n",libro[i].anoPublicacion);
					coincidencias++;
				}
			}
			if(coincidencias == 0)
			{
				printf("No se encontr� ning�n libro publicado ese a�o.\n");
			}
		break;
	}
}

void guardarLibros(struct lista_libros *libro, int cant_libros, int bandera){
	int i;
	FILE *archivo;
	
	archivo = fopen("libros.txt","w");
	if(archivo != NULL)
	{
		for(i=0;i<cant_libros;i++)
		{
			fprintf(archivo,"\nLibro %d: \n",i+1);
			fprintf(archivo,"T�tulo: %s \n",libro[i].titulo);
			fprintf(archivo,"Autor: %s \n",libro[i].autor);
			fprintf(archivo,"A�o de publicaci�n: %d \n",libro[i].anoPublicacion);
		}
		printf("Libros guardados correctamente en 'libros.txt'\n");
		fclose(archivo);
	}
	else
	{
		printf("Problemas al abrir 'libros.txt'. Intente nuevamente");
	}
	
}
