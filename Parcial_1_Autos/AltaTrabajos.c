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

int inicializarTrabajos(eTrabajo listaTrabajo[], int tam)
{
	int todoOk = 0;
	if(listaTrabajo != NULL && tam > 0)
	{
		for(int i = 0 ; i < tam ; i++)
		{
			listaTrabajo[i].isEmpty = 1;
		}
		todoOk = 1;
	}
	return todoOk;
}

int buscarLibreTrabajos(eTrabajo listaTrabajo[], int tam)
{
    int indice = -1;

   for(int i = 0 ; i < tam ; i++)
    {
        if( listaTrabajo[i].isEmpty)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int cargarTrabajo(eTrabajo* pTrabajo, eAuto vecAutos[], eMarca vecMarcas[], eColor vecColores[], eServicio vecServicio[], eFecha vecFecha[], int tamMarcas,  int tamAutos, int tamServicios, int tamColores)
{
    int todoOk = 0;
    int indice;
    int id;
    eTrabajo auxTrabajo;

    if(pTrabajo != NULL)
	{

        mostrarAutos(vecAutos, vecMarcas, vecColores, tamAutos, tamMarcas, tamColores);


		printf("\nIngrese ID del auto: ");
		scanf("%d", &id);
        indice = buscarAutoId(vecAutos, tamAutos, id);

        if(indice == -1){
            printf("\n=============================================="
                   "\n El ID %d no esta cargado en el sistema       "
                   "\n==============================================", id);
        }else{

        mostrarServicios(vecServicio, tamServicios);

        do{
		printf("\nQue opcion elige: ");
		fflush(stdin);
		scanf("%d", &auxTrabajo.idServicio);
		}while(auxTrabajo.idServicio < 20000 || auxTrabajo.idServicio > 20003);
		pTrabajo->idServicio = auxTrabajo.idServicio;

		printf("Ingrese Fecha: \n");
		do{
		printf("Ingrese dia: ");
		scanf("%d", &auxTrabajo.fecha.dia);
		}while(auxTrabajo.fecha.dia < 1 || auxTrabajo.fecha.dia > 31);
		pTrabajo->fecha.dia=auxTrabajo.fecha.dia;

		do{
		printf("Ingrese mes: ");
		scanf("%d", &auxTrabajo.fecha.mes);
		}while(auxTrabajo.fecha.mes < 1 || auxTrabajo.fecha.mes > 12);
		pTrabajo->fecha.mes=auxTrabajo.fecha.mes;

		do{
		printf("Ingrese año: ");
		scanf("%d", &auxTrabajo.fecha.anio);
		}while(auxTrabajo.fecha.anio < 1950 || auxTrabajo.fecha.anio > 2021);
		pTrabajo->fecha.anio=auxTrabajo.fecha.anio;



		todoOk = 1;
	}
	}

    return todoOk;
}

int altaTrabajos(int* pIdTrabajo, eTrabajo vecTrabajo[], eAuto vecAutos[], eMarca vecMarcas[], eColor vecColores[], eServicio vecServicio[], eFecha vecFecha[],  int tamMarcas, int tamColores,  int tamTrabajos, int tamServicios, int tamAutos, int tamFecha)
{
	char seguir;
    int todoOk = 0;
    eTrabajo auxTrabajo;

    if(pIdTrabajo != NULL && tamTrabajos > 0 )
    {
    	do
    	{
    		printf("***    Alta Trabajo   ***\n\n");

			if(buscarLibreTrabajos(vecTrabajo, tamTrabajos) == -1)
			{
				printf("\nNo hay lugar en el sistema.");
			}
			else
			{
				cargarTrabajo(&auxTrabajo, vecAutos, vecMarcas,vecColores, vecServicio ,vecFecha, tamMarcas, tamAutos, tamServicios, tamColores);
				auxTrabajo.id = *pIdTrabajo;
				*pIdTrabajo = *pIdTrabajo + 1;
				vecTrabajo[buscarLibreAutos(vecTrabajo, tamTrabajos)] = auxTrabajo;
				todoOk = 1;
			}
			printf("\nLe gustaria ingresar otro Trabajo:");
			fflush(stdin);
			scanf("%c", &seguir);
			seguir = toupper(seguir);


    	}while(seguir != 'N');


    }
    return todoOk;
}


int hardcodearTrabajos(int* pId ,eTrabajo vec[], int tam, int cant)
{


    int todoOk = 0;

    eTrabajo trabajos[] =
	{
		{10000, 1000,20002, {2,8,2001}},
		{10001, 1002,20000, {19,6,2003}},
		{10002, 1003,20003, {25,11,2003}},
		{10003, 1004,20001, {30,11,1999}},
	};


    if(vec != NULL && tam > 0 && cant <= tam && cant <= 10)
    {

      for(int i = 0 ; i < cant ; i++){

      vec[i] = trabajos[i];
      *pId = *pId + 1;
      }
        todoOk = 1;
    }
    return todoOk;
}
