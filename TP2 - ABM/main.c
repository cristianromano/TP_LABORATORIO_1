#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "empleado.h"
#define TAM 50


int main()
{

    char seguir = 's';
    int opcion;
    eFecha lista[TAM];


    eEmpleado listado[TAM];
    initEmpleado(listado,TAM);
    hardcodeoDatos(listado,TAM);

    do
    {


        opcion = menu();

        switch(opcion)
        {
        case 1:
            clean();
            ingresoDatos(listado,TAM,lista);


            break;

        case 2:

            clean();
            modificar(listado,TAM);


            break;

        case 3:
            clean();
            mostrarEmpleado(listado,TAM);


            break;

        case 4:
            clean();
            remover(listado,TAM);


            break;

        case 5:

            clean();
            ordenamientoBurbuja(listado,TAM);
            mostrarEmpleado(listado,TAM);
            break;

        case 6:

            clean();
            promedioSalarios(listado,TAM);


            break;

        case 7:
            seguir = 'n';
            break;
        default:
            printf("no es una opcion.\n");
            break;

        }

        pause();
        clean();

    }
    while(seguir=='s');


    return 0;
}
