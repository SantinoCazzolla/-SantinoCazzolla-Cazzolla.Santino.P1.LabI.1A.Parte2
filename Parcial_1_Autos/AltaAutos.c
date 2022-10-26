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

int inicializarAutos(eAuto vecAuto[], int tam)
{
	int todoOk = 0;
	if(vecAuto != NULL && tam > 0)
	{
		for(int i = 0 ; i < tam ; i++)
		{
			vecAuto[i].isEmpty = 1;
		}
		todoOk = 1;
	}
	return todoOk;
}

int buscarLibreAutos(eAuto vecAuto[], int tam)
{
    int indice = -1;

   for(int i = 0 ; i < tam ; i++)
    {
        if( vecAuto[i].isEmpty)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int cargarAuto(eAuto * pAuto, eMarca vecMarcas[], eColor vecColores[], int tamAutos, int tamMarcas, int tamColores )
{
    int todoOk = 0;
    eAuto auxAuto;

    if(pAuto != NULL){


		printf("\nIngrese ID Marca: ");
        mostrarMarcas(vecMarcas, tamMarcas);

		do{
		printf("\nQue opcion elige: ");
		fflush(stdin);
		scanf("%d", &auxAuto.idMarca);
		}while(auxAuto.idMarca < 1000 || auxAuto.idMarca > 1004);
		pAuto->idMarca=auxAuto.idMarca;


		printf("\nIngrese ID Color: ");
		mostrarColores(vecColores, tamColores);

		do{
		printf("\nQue opcion elige: ");
		fflush(stdin);
		scanf("%d", &auxAuto.idColor);
		}while(auxAuto.idColor < 5000 || auxAuto.idColor > 5004);
		pAuto->idColor=auxAuto.idColor;

        do{
		printf("\nIngrese Tipo de Caja: (m / a) ");
		fflush(stdin);
		scanf("%c", &auxAuto.caja);
		auxAuto.caja = toupper(auxAuto.caja);
        }while(!validarCaja(auxAuto.caja));
		pAuto->caja=auxAuto.caja;



		pAuto->isEmpty = 0;



		todoOk = 1;
	}

    return todoOk;
}

int altaAutos(int* pIdAuto, eAuto vecAuto[], eMarca vecMarcas[], eColor vecColores[], int tamAutos, int tamMarcas, int tamColores)
{
	char seguir;
    int todoOk = 0;
    eAuto axuAuto;

   system("cls");

    if(pIdAuto != NULL && vecAuto != NULL && vecMarcas != NULL && vecColores != NULL && tamAutos > 0 && tamAutos > 0 && tamMarcas > 0 && tamColores >0)
    {
    	do
    	{
    		printf("***    Alta Auto   ***\n\n");

			if(buscarLibreAutos(vecAuto, tamAutos) == -1)
			{
				printf("\nNo hay lugar en el sistema.");
			}
			else
			{
				cargarAuto(&axuAuto, vecMarcas,vecColores,tamAutos,tamMarcas,tamColores);
				axuAuto.id = *pIdAuto;
				*pIdAuto = *pIdAuto + 1;
				vecAuto[buscarLibreAutos(vecAuto, tamAutos)] = axuAuto;
				todoOk = 1;
			}
			printf("\nLe gustaria ingresar otro Auto:");
			fflush(stdin);
			scanf("%c", &seguir);


    	}while(seguir != 'n');


    }
    return todoOk;
}

int hardcodearAutos(int* pId ,eAuto vec[], int tam, int cant)
{
	int todoOk = 0;

    eAuto autos[] =
	{
		{1000, 1001, 5000, 'm',},
		{1001, 1003, 5002, 'a',},
		{1002, 1002, 5001, 'm',},
		{1003, 1003, 5003, 'a',},
		{1004, 1003, 5002, 'a',},
		{1005, 1004, 5001, 'm',},
		{1006, 1001, 5000, 'm',},
		{1007, 1000, 5000, 'a',},
		{1008, 1001, 5001, 'a',},
	};

 if(vec != NULL && tam > 0 && cant <= tam && cant <= 10)
    {

      for(int i = 0 ; i < cant ; i++){

      vec[i] = autos[i];
      *pId = *pId + 1;
      }
        todoOk = 1;
    }
    return todoOk;
}

/*
int hardcodearClientes(int* pId ,eCliente vec[], int tam, int cant)
{
	int todoOk = 0;

    eCliente clientes[] =
	{
		{1000, "Carlos", 'm'},
		{1001, "Esteban", 'm'},
		{1002, "Flor", 'f'},
		{1003, "Juli", 'f'},
		{1004, "Santino", 'm'},
		{1005, "Marta", 'f'},
		{1006, "Olivia", 'f'},
		{1007, "Renato", 'm'},
		{1008, "Lucas", 'm'},
	};

 if(vec != NULL && tam > 0 && cant <= tam && cant <= 10)
    {

      for(int i = 0 ; i < cant ; i++){

      vec[i] = clientes[i];
      *pId = *pId + 1;
      }
        todoOk = 1;
    }
    return todoOk;
}

*/
