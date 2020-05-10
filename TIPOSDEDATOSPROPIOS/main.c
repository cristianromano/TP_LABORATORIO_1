#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "bibloteca.h"
#include "sectores.h"
#include "informes.h"
#define TAM 7
#define TAMSECTORES 5


int main()
{

    char seguir = 's';
    int opcion;
    int trigger = 1;
    eFecha lista[TAM];
    eSector sectores[TAMSECTORES] = { {1,"SISTEMAS"},{2,"RRHH"},{3,"VENTAS"},{4,"AT.CLIENTE"},{5,"OPERACIONES"} };


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
            modificar(listado,TAM,TAMSECTORES,sectores);
        }
        else
        {
            printf("no hay empleados ingresados.\n");
        }
        break;

        case 3:
         if(trigger==1){
            clean();
            mostrarEmpleado(listado,TAM,TAMSECTORES,sectores);
        }
        else
        {
            printf("no hay empleados ingresados.\n");
        }
        break;

        case 4:
         if(trigger==1){
            clean();
            remover(listado,TAM,TAMSECTORES,sectores);
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
            mostrarEmpleado(listado,TAM,TAMSECTORES,sectores);
        }
        else
        {
            printf("no hay empleados ingresados.\n");
        }
        break;

        case 6:
         if(trigger==1){
            clean();
            menuDeInformes(listado,TAM,sectores,TAMSECTORES);
        }
        else
        {
            printf("no hay empleados ingresados.\n");
        }
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

    }while(seguir=='s');


    return 0;
}
