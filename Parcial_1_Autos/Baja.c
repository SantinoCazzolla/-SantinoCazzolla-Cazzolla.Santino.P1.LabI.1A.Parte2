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

int buscarAutoId(eAuto lista[], int tam, int id)
{
    int indice = -1;

   for(int i = 0 ; i < tam ; i++)
    {
        if(!lista[i].isEmpty && lista[i].id == id)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int bajaAuto(eAuto lista[], eMarca vecMarcas[], eColor vecColores[], int tam, int tamMarcas, int tamColores)
{
    int todoOk= 0;
    int indice;
    int id;
    char confirma;

    if(lista != NULL && tam > 0)
        {
            printf("\n      ***   BAJA DE AUTO  ***      ");
            printf("\n\n Ingrese ID del auto que desea eliminar: ");
            scanf("%d", &id);

            indice = buscarAutoId(lista, tam, id);

            if(indice == -1)
                {
                        printf("\n=============================================="
                               "\n El ID %d no esta cargado en el sistema       "
                               "\n==============================================", id);
                }else
                {
                    mostrarAuto(lista[indice], vecMarcas, vecColores, tamMarcas, tamColores);
                    printf("\n Confirma la baja del auto?");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    if(confirma == 's')
                        {
                            lista[indice].isEmpty = 1;
                            todoOk = 1;
                        }else
                        {
                           printf("\n Baja cancelada");
                        }

                }
        }

    return todoOk;
}
