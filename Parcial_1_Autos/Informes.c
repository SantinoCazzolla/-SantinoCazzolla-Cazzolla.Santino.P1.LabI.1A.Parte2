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

int mostrarAutosColorSelec(eAuto autos[],int tamA, eColor colores[],int tamC, eMarca marcas[],int tamM)
{


    int todoOk = 0;
    int idColor;

    if(autos != NULL && tamA > 0 && marcas != NULL && tamM > 0 && colores != NULL && tamC > 0){
        mostrarColores(colores, tamC);
        printf("\nIngrese ID del color: ");
        fflush(stdin);
        scanf("%d", &idColor);
        while(idColor < 5000 || idColor >  5004){
            printf("Error. Reingrese ID del color: ");
            fflush(stdin);
            scanf("%d", &idColor);
        }
        printf("\n");
        printf("      Id                Marca                  Color        Caja\n\n");

        for(int i = 0; i < tamA; i++){

            if(!autos[i].isEmpty && (autos[i].idColor == idColor)){
                mostrarAuto(autos[i], marcas, colores, tamC, tamM);

            }
        }
        printf("\n");


        todoOk = 1;
    }
    return todoOk;
}

int mostrarAutosMarcaSelec(eAuto autos[],int tamA, eColor colores[],int tamC, eMarca marcas[],int tamM)
{


    int todoOk = 0;
    int idMarca;

    if(autos != NULL && tamA > 0 && marcas != NULL && tamM > 0 && colores != NULL && tamC > 0){
        mostrarMarcas(marcas, tamM);
        printf("\nIngrese ID del marca: ");
        fflush(stdin);
        scanf("%d", &idMarca);
        while(idMarca < 1000 || idMarca >  1004){
            printf("Error. Reingrese ID de marca: ");
            fflush(stdin);
            scanf("%d", &idMarca);
        }
        printf("\n");
        printf("      Id                Marca                  Color        Caja\n\n");

        for(int i = 0; i < tamA; i++){

            if(!autos[i].isEmpty && (autos[i].idMarca == idMarca)){
                mostrarAuto(autos[i], marcas, colores, tamC, tamM);

            }
        }
        printf("\n");


        todoOk = 1;
    }
    return todoOk;
}

int contarMarcaYColor(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC){
    int error = 1;
    int idColor;
    int idMarca;
    int cont = 0;

    if(autos != NULL && marcas != NULL && colores != NULL && tamA > 0 && tamM > 0 && tamC > 0){
        system("cls");
        printf("*** CONTADOR POR MARCA Y COLOR ***\n\n");
        mostrarColores(colores, tamC);
        printf("Ingrese id del color a mostrar: ");
        scanf("%d", &idColor);
        while(idColor < 5000 || idColor >  5004){
            printf("Id invalido. Reingrese id del tipo a mostrar: ");
            scanf("%d", &idColor);
        }


        system("cls");
        printf("*** CONTADOR POR MARCA Y COLOR ***\n\n");
        mostrarMarcas(marcas, tamM);
        printf("Ingrese id de marca a mostrar: ");
        scanf("%d", &idMarca);
        while(idMarca < 1000 || idMarca >  1004){
            printf("Id invalido. Reingrese id del tipo a mostrar: ");
            scanf("%d", &idMarca);
        }


        system("cls");
        printf("*** CONTADOR POR MARCA Y COLOR ***\n\n");
        for(int i = 0; i < tamM; i++){
            if(autos[i].idColor == idColor && autos[i].idMarca == idMarca){
                cont++;

            }
        }


        printf("Hay %d autos de ese color y marca\n\n", cont);

    }
    return error;

}

int mostrarPorCaja(eAuto autos[], int tamA ,eMarca marcas[],int tamM, eColor colores[],int tamC)
{
    int todoOk = 0;
    int contadorAutos;
    if(autos!=NULL && tamA >0 && marcas!=NULL && tamM>0 && colores!=NULL && tamC>0)
    {
        system("cls");
        for(int i = 0; i<2; i++)
        {
            contadorAutos = 0;
            printf("Tipo de caja: %c",autos->caja);
            printf("\n-----------------------------------------------------\n");
            printf(" Id       Marca              Color              caja\n");
            printf("-----------------------------------------------------\n");
            for(int j = 0; j<tamA; j++)
            {
                if(autos[j].isEmpty == 0 && autos[i].caja == autos[j].caja)
                {
                      mostrarAuto(autos[j], marcas, colores, tamC, tamM);
                    contadorAutos++;
                    todoOk = 1;
                }
            }
            printf("\n-----------------------------------------------------\n");
            printf("Cantidad: %d\n\n\n",contadorAutos);
        }
    }
    return todoOk;
}

int marcaMasElegida(eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC){
    int todoOk = 0;
    int mayorMarca;
    int totalMarca = 0;
    int totalesMarca[tamM];
    int flag = 1;
    system("cls");
    printf("\n      MARCA MAS ELEGIDA DE LOS CLIENTES\n\n");
    if(autos != NULL && tam > 0 && marcas != NULL && tamM > 0 && colores != NULL && tamC > 0){

        for(int c = 0; c < tamC; c++){

            totalMarca = 0;

            for(int b = 0; b < tam; b++){

                    if(!autos[b].isEmpty && autos[b].idMarca == marcas[c].id){
                        totalMarca ++;
                    }
                }

                totalesMarca[c] = totalMarca;
            }

            for(int i = 0; i < tamC; i++){
                if(flag || totalesMarca[i] > mayorMarca){
                    mayorMarca = totalesMarca[i];
                    flag = 0;
                }
            }
            printf("La o las marcas mas elegidas de los clientes son: \n");

            for(int i = 0; i < tamC; i++){
                if(mayorMarca == totalesMarca[i]){
                    printf("%s\n",marcas[i].descripcion);
                }
            }
            todoOk = 1;
    }
    return todoOk;
}

int mostrarPorsentajeDeCajas(eAuto autos[],int tamA, eColor colores[],int tamC, eMarca marcas[],int tamM)
{
    int todoOk = 0;
    int contadorAutos = 0;
    int cantidadTotal = 0;
    float porsentajeAutomatica;
    float porsentajeManual = 100;
    if(autos!=NULL && tamA >0 && marcas!=NULL && tamM>0 && colores!=NULL && tamC>0)
    {
        system("cls");
        for(int i = 0; i<2; i++)
        {

            contadorAutos = 0;
            printf("Tipo de caja: %c",autos->caja);
            printf("\n-----------------------------------------------------\n");
            printf(" Id       Marca              Color              caja\n");
            printf("-----------------------------------------------------\n");
            for(int j = 0; j<tamA; j++)
            {

                if(autos[j].isEmpty == 0 && autos[i].caja == autos[j].caja)
                {
                      mostrarAuto(autos[j], marcas, colores, tamC, tamM);
                    contadorAutos++;

                    cantidadTotal++;
                    todoOk = 1;
                }

            }
            printf("\n-----------------------------------------------------\n");

        }
         porsentajeAutomatica = (contadorAutos * 100) / cantidadTotal;
         porsentajeManual = porsentajeManual - porsentajeAutomatica;
         printf("El porsentaje es de caja automatica es:  %.2f, y el de manual es: %.2f \n\n\n",porsentajeAutomatica, porsentajeManual);
    }
    return todoOk;
}
