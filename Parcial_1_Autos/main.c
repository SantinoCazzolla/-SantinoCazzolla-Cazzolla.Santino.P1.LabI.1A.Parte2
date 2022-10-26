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

#define TAM 14
#define TAM_M 6
#define TAM_C 5
#define TAM_S 4
#define TAM_T 9
#define TAM_F 5

int main()
{
    eMarca listaMarca[TAM_M]=
    {
        {1000, "Renault"},
        {1001, "Ford"},
        {1002, "Fiat"},
        {1003, "Chevrolet"},
        {1004, "Peugeot"}
    };

    eColor listaColor[TAM_C]=
    {
        {5000, "Negro"},
        {5001, "Blanco"},
        {5002, "Rojo"},
        {5003, "Gris"},
        {5004, "Azul"},
    };

    eServicio listaServicio[TAM_S]=
    {
        {20000, "Lavado", 450},
        {20001, "Pulido", 500},
        {20002, "Encerado", 600},
        {20003, "Completo", 900},
    };

    eTrabajo listaTrabajo[TAM_T];

    eFecha listaFecha[TAM_F];

    //eCliente listaClientes[TAM_CLIENTE];

    eAuto listaAutos[TAM];

    int opcionMenuInicio;
    char respuesta;
    int todoOkInciadosAutos=0;
    int siguienteIdAuto = 1000;
    int siguienteIdTrabajo = 1;

    todoOkInciadosAutos = inicializarAutos(listaAutos, TAM);

    if(todoOkInciadosAutos==1){
            hardcodearAutos(&siguienteIdAuto, listaAutos, TAM, 9);
            hardcodearTrabajos(&siguienteIdTrabajo, listaTrabajo, TAM_T, 5);

    do
	{

	menuInicio();
	opcionMenuInicio = ingresoDeOpcionMenuPricipal();


	switch (opcionMenuInicio) {

		case 'A':

        altaAutos(&siguienteIdAuto, listaAutos, listaMarca, listaColor ,TAM, TAM_M,TAM_C);

		break;

        case 'B':

        mostrarAutos(listaAutos, listaMarca, listaColor, TAM,  TAM_M, TAM_C);
        modificarAuto(listaAutos, listaMarca, listaColor ,TAM, TAM_M,TAM_C);

		break;

		case 'C':

        mostrarAutos(listaAutos, listaMarca, listaColor,TAM, TAM_M, TAM_C);
        if(!bajaAuto(listaAutos, listaMarca, listaColor ,TAM, TAM_M,TAM_C))
            {
              printf("\n=============================="
                     "\n Error Al realizar la baja    "
                     "\n==============================");
            }else
            {
                printf("\n Baja realizada con exito ");
            }

		break;

		case 'D':

        mostrarAutos(listaAutos, listaMarca, listaColor, TAM, TAM_M, TAM_C);

		break;

		case 'E':

        mostrarMarcas(listaMarca, TAM_M);

        mostrarAutosColorSelec(listaAutos,TAM,listaColor,TAM_C,listaMarca,TAM_M);

		break;

		case 'F':

        mostrarColores(listaColor, TAM_C);

		break;

        case 'G':

        mostrarServicios(listaServicio, TAM_S);

		break;

        case 'H':

        altaTrabajos(&siguienteIdTrabajo, listaTrabajo, listaAutos, listaMarca, listaColor, listaServicio, listaFecha, TAM_M, TAM_C, TAM_T, TAM_S, TAM_F, TAM);


        break;

        case 'I':

        mostrarTrabajos(listaAutos, TAM, listaTrabajo, listaMarca, listaServicio, listaFecha, TAM_M, TAM_S, TAM_F);

        break;

        case 'J':

            switch(menuInformes())
            {
            case 1:

                mostrarAutosColorSelec(listaAutos, TAM, listaColor, TAM_C, listaMarca, TAM_M);

            break;

            case 2:

            mostrarAutosMarcaSelec(listaAutos, TAM, listaColor, TAM_C, listaMarca, TAM_M);

            break;

            case 3:

            mostrarPorsentajeDeCajas(listaAutos,TAM, listaColor,TAM_C, listaMarca,TAM_M);

            break;


            case 4:

            mostrarPorCaja(listaAutos, TAM ,listaMarca, TAM_M, listaColor,TAM_C);

            break;

            case 5:

            contarMarcaYColor(listaAutos, TAM, listaMarca, TAM_M, listaColor, TAM_C);

            break;

            case 6:

            marcaMasElegida(listaAutos, TAM, listaMarca, TAM_M, listaColor, TAM_C);

            break;
            }

        break;

		case 'K':

        confirmacionSalida(&respuesta);

        break;

        default:

        printf("\n Ingrese valor valido ");

	}

	}while(respuesta !='s');

    }else
    {
        errorAlInicializar();
    }

    return 0;

}
