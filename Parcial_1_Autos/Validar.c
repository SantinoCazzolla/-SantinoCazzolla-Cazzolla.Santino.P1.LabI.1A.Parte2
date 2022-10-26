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

int validarCaracterMenuInicio(char x)
{
    int todoOk = 0;
    if(x == 'A' ||x == 'B' ||x == 'C' ||x == 'D' ||x == 'E' ||x == 'F' ||x == 'G' ||x == 'H' ||x == 'I' ||x == 'J' )
        {
            todoOk = 1;
        }else
        {
         printf("\n=============================="
                "\n Ingrese una opcion correcta  "
                "\n==============================");
        }

        return todoOk;
}

int validarCaja(char x)
{
    int todoOk = 0;
    if(x == 'M' ||x == 'A' )
        {
            todoOk = 1;
        }else
        {
         printf("\n=============================="
                "\n Ingrese una opcion correcta  "
                "\n==============================");
        }

        return todoOk;
}

int validarCaracterMenuModificacion(char x)
{
    int todoOk = 0;
    if(x == 'A' ||x == 'B' ||x == 'C')
        {
            todoOk = 1;
        }else
        {
         printf("\n=============================="
                "\n Ingrese una opcion correcta  "
                "\n==============================");
        }

        return todoOk;

}

