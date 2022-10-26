#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "AltaAutos.h"
#include "EstructurasAutos.h"
#include "Muestra.h"
#include "Validar.h"
#include "Baja.h"
#include "Modificar.h"
#include "AltaTrabajos.h"
#include "Informes.h"

void menuInicio()
{
	printf("\n\n|=================================================|\n"
		   "|           ADMINISTRACION DE LAVADERO            |\n"
		   "|=================================================|\n"
		   "| A. ALTA DE AUTO                                 |\n"
		   "|                                                 |\n"
		   "| B. MODIFICAR AUTO                               |\n"
		   "|                                                 |\n"
		   "| C. BAJA DE  AUTO                                |\n"
		   "|                                                 |\n"
		   "| D. LISTAR AUTOS                                 |\n"
		   "|                                                 |\n"
		   "| E. LISTAR MARCAS                                |\n"
		   "|                                                 |\n"
		   "| F. LISTAR COLORES                               |\n"
		   "|                                                 |\n"
		   "| G. LISTAR SERVICIOS                             |\n"
		   "|                                                 |\n"
		   "| H. ALTA TRABAJO                                 |\n"
		   "|                                                 |\n"
		   "| I. LISTAR TRABAJOS                              |\n"
		   "|                                                 |\n"
		   "| J. INFORMES                                     |\n"
           "|                                                 |\n"
           "| K. SALIR                                        |\n"
		   "|=================================================|\n");

}

char ingresoDeOpcionMenuPricipal(){
	char s;

	printf("\n\nIngrese la opcion que desea: ");
	fflush(stdin);
	scanf("%c", &s);
	s = toupper(s);
	validarCaracterMenuInicio(s);

	return s;

}

int confirmacionSalida(char* respuesta) {

	int retorno =0;
	char aux;

	printf("\n\nSeguro quiere salir del programa??: (S / N)  ");
	fflush(stdin);
	scanf("%c", &aux);

	if(aux == 's' || aux == 'S')
	{
		*respuesta = 's';
	}else
	{
		*respuesta = 'n';
	}

	return retorno;

}

void errorAlInicializar()
{
    printf("\n==========================="
           "\n Error Al Inicializar       "
           "\n===========================");
}

int mostrarAuto(eAuto autos, eMarca marcas[], eColor colores[], int tamMarcas, int tamColores)
{
    int todoOk = 0;
    char auxMarcas[20];
    char auxColores[20];

    if(marcas != NULL && tamMarcas > 0 && colores != NULL && tamColores > 0)
    {
        cargarDescripcionMarca(autos.idMarca, auxMarcas, marcas, tamMarcas);
        cargarDescripcionColores(autos.idColor, auxColores, colores, tamColores);


    printf("\n|   %d   |   %s          |     %s    |     %c     | ", autos.id, auxMarcas, auxColores, autos.caja);

    todoOk = 1;


    }

    return todoOk;
}

int mostrarAutos(eAuto lista[], eMarca vecMarcas[], eColor vecColores[], int tam, int tamMarcas, int tamColores)
{
    int todoOk= 0;

    if(lista != NULL && tam > 0)
        {
            printf("\n                        *** LISTA DE AUTOS ***                       "
                   "\n---------------------------------------------------------------------"
                   "\n|   ID   |            MARCA            |     COLOR     |    CAJA    |"
                   "\n---------------------------------------------------------------------");

            for(int i = 0; i < tam; i++)
                {
                    if(!lista[i].isEmpty)
                        {
                             mostrarAuto(lista[i], vecMarcas, vecColores, tamMarcas, tamColores);
                        }
                }

            todoOk = 1;

        }

        return todoOk;
}

int mostrarMarcas(eMarca vec[], int tam)
{
	int todoOk=0;



	if(vec!=NULL && tam > 0)
	{

	    system("cls");

		printf("\n\n    |***Lista de Marcas***   |\n");
		printf("----|------------------------|\n");
		printf(" ID |            Descripcion |\n");

		for(int i=0; i<tam;i++)
		{
			printf("%4d|   %20s |\n", vec[i].id, vec[i].descripcion);
		}
		printf("\n\n");

		todoOk=1;

        system("pause");
	}
	return todoOk;
}

int mostrarColores(eColor vec[], int tam)
{
	int todoOk=0;



	if(vec!=NULL && tam > 0)
	{

	    system("cls");

		printf("\n\n    |***Lista de Colores***   |\n");
		printf("----|------------------------|\n");
		printf(" ID |            Descripcion |\n");

		for(int i=0; i<tam;i++)
		{
			printf("%4d|   %20s |\n", vec[i].id, vec[i].nombreColor);
		}
		printf("\n\n");

		todoOk=1;

        system("pause");
	}
	return todoOk;
}

int mostrarServicios(eServicio vec[], int tam)
{
	int todoOk=0;



	if(vec!=NULL && tam > 0)
	{
	    system("cls");

		printf("     |***Lista de Servicios***            |\n");
		printf("-----|------------------------------------|\n");
		printf(" ID  |            Descripcion             |\n");

		for(int i=0; i<tam;i++)
		{
			printf("%4d|   %20s |    $%d   |\n", vec[i].id, vec[i].descripcion, vec[i].precio);
		}
		printf("\n\n");

		todoOk=1;

        system("pause");
	}
	return todoOk;
}

char subMenuModificar()
{
	printf("\n\n|=================================================|\n"
		   "|               QUE DESEA MODIFICAR               |\n"
		   "|=================================================|\n"
		   "| A. MARCA                                        |\n"
		   "|                                                 |\n"
		   "| B. COLOR                                        |\n"
		   "|                                                 |\n"
		   "| C. CAJA                                         |\n"
		   "|=================================================|\n");

    	char s;

	printf("\n\nIngrese la opcion que desea: ");
	fflush(stdin);
	scanf("%c", &s);
	s = toupper(s);
	validarCaracterMenuModificacion(s);

	return s;

}

int cargarDescripcionMarca(int idMarcas, char descripcion[], eMarca vec[], int tam)
{
	int todoOk=0;

	if(descripcion!=NULL && vec !=NULL && tam > 0)
	{
		for(int i=0; i<tam; i++)
		{
			if(vec[i].id==idMarcas)
			{
				strcpy(descripcion, vec[i].descripcion);
				break;
			}
		}

		todoOk=1;
	}
	return todoOk;
}

int cargarDescripcionColores(int idColores, char descripcion[], eColor vec[], int tam)
{
	int todoOk=0;
	if(descripcion!=NULL && vec !=NULL && tam > 0)
	{
		for(int i=0; i<tam; i++)
		{
			if(vec[i].id==idColores)
			{
				strcpy(descripcion, vec[i].nombreColor);
				break;
			}
		}

		todoOk=1;
	}
	return todoOk;
}

int cargarDescripcionServicios(int idServicios, char descripcion[], eServicio vec[], int tam)
{
	int todoOk=0;
	if(descripcion!=NULL && vec !=NULL && tam > 0)
	{
		for(int i=0; i<tam; i++)
		{
			if(vec[i].id==idServicios)
			{
				strcpy(descripcion, vec[i].descripcion);
				break;
			}
		}

		todoOk=1;
	}
	return todoOk;
}


int mostrarTrabajo(eAuto autos, eTrabajo trabajos[]  ,eMarca marcas[], eServicio servicios[], eFecha fechas[], int tamMarcas, int tamServicios, int tamFechas)
{
    int todoOk = 0;
    char auxMarcas[20];
    char auxServicios[20];

    if(marcas != NULL && tamMarcas > 0 && servicios != NULL && tamServicios > 0)
    {
        cargarDescripcionMarca(autos.idMarca, auxMarcas, marcas, tamMarcas);
        cargarDescripcionServicios(trabajos->idServicio, auxServicios, servicios, tamServicios);


    printf("\n|   %d   |     %s     |     %s   |   %d/%d/%d   | ", autos.id, auxMarcas, auxServicios, fechas->dia, fechas->mes , fechas->anio);

    todoOk = 1;


    }

    return todoOk;
}

int mostrarTrabajos(eAuto lista[], int tam, eTrabajo trabajos[], eMarca marcas[], eServicio servicios[], eFecha fechas[], int tamMarcas, int tamServicios, int tamFechas)
{

int todoOk = 0;

    if(lista != NULL && tam > 0)
        {
            printf("\n              *** LISTA DE TRABAJOS ***            "
                   "\n---------------------------------------------------"
                   "\n|   ID   |     MARCA     |   SERVICIO   |  FECHA  |"
                   "\n---------------------------------------------------");

            for(int i = 0; i < tam; i++)
                {
                    if(!lista[i].isEmpty)
                        {
                             mostrarTrabajo(lista[i], trabajos  , marcas, servicios, fechas, tamMarcas, tamServicios, tamFechas);
                        }
                }

            todoOk = 1;

        }

        return todoOk;
}

int menuInformes(){
  int opcion;

  printf("         INFORMES\n\n");
  printf("1. Listar autos por color\n");
  printf("2. Listar autos por marca\n");
  printf("3. Informar Promedio de autos con caja manual y promedio de autos con caja automática\n");
  printf("4. Mostrar un listado de los autos separados por tipo de caja.\n");
  printf("5. Elegir un color y una marca y contar cuantos autos hay de ese color y esa marca.\n");
  printf("6. Mostrar la o las marcas más elegidas por los clientes.\n");


  printf("\nIngrese opcion ");
  scanf("%d", &opcion);

  return opcion;
}
