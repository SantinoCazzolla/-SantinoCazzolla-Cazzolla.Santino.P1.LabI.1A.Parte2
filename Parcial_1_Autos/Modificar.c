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

int modificarAuto(eAuto lista[], eMarca vecMarcas[], eColor vecColores[], int tam, int tamMarcas, int tamColores)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    int auxMarca;
    int auxColor;
    char auxCaja;

    if(lista != NULL && tam > 0)
        {
            printf("\n\n        ***   MODIFICAR AUTO  ***          ");
            printf("\n\n Ingrese ID del auto que desea modificar: ");
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
                    printf("\n Confirma modificacion?");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    if(confirma == 's')
                        {
                            switch(subMenuModificar())
                            {
                            case 'A':

                            mostrarMarcas(vecMarcas, tamMarcas);
                            do{
                            printf("\nIngrese nueva marca ");
                            scanf("%d", &auxMarca);
                            }while(auxMarca < 100 || auxMarca > 104);
                            lista[indice].idMarca = auxMarca;

                            break;

                            case 'B':

                            mostrarColores(vecColores, tamColores);
                            do{
                            printf("\nIngrese nuevo color ");
                            scanf("%d", &auxColor);
                            }while(auxColor < 100 || auxColor > 104);
                            lista[indice].idColor = auxColor;

                            break;

                            case 'C':

                            do{
                            printf("\nIngrese Tipo de Caja: (m / a) ");
                            fflush(stdin);
                            scanf("%c", &auxCaja);
                            auxCaja = toupper(auxCaja);
                            }while(!validarCaja(auxCaja));
                            lista[indice].caja = auxCaja;

                            break;

                            }
                            todoOk = 1;
                        }else
                        {
                           printf("\n Modificaion cancelada");
                        }

                }
        }

    return todoOk;
}
