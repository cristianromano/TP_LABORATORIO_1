#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "empleado.h"
#define TAM 7


int main()
{

    char seguir = 's';
    int opcion;
    int trigger = 1;
    eFecha lista[TAM];


    eEmpleado listado[TAM];
    initEmpleado(listado,TAM);
    hardcodeoDatos(listado,TAM);

    do{


        opcion = menu();

        switch(opcion)
        {
        case 1:
        clean();
        ingresoDatos(listado,TAM,lista);
        trigger = 1;
        break;

        case 2:

        if(trigger==1){
            clean();
            modificar(listado,TAM);
        }
        else
        {
            printf("no hay empleados ingresados.\n");
        }
        break;

        case 3:
         if(trigger==1){
            clean();
            mostrarEmpleado(listado,TAM);
        }
        else
        {
            printf("no hay empleados ingresados.\n");
        }
        break;

        case 4:
         if(trigger==1){
            clean();
            remover(listado,TAM);
        }
        else
        {
            printf("no hay empleados ingresados.\n");
        }
        break;

        case 5:
         if(trigger==1){
            clean();
            ordenamientoBurbuja(listado,TAM);
            mostrarEmpleado(listado,TAM);
        }
        else
        {
            printf("no hay empleados ingresados.\n");
        }
        break;

        case 6:
        seguir = 'n';
        break;
        default:
        printf("no es una opcion.\n");
        break;

        }

        pause();
        clean();

    }while(seguir=='s');


    return 0;
}
