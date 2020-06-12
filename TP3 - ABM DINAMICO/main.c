#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{

    char rta = 's';
    int opcion = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();



    do
    {

        menu(&opcion);

        switch(opcion)
        {
        case 1:
            controller_loadFromText("data.csv",listaEmpleados);
            break;

        case 2:
            clean();
            controller_addEmployee(listaEmpleados);
            break;

        case 3:
            clean();
            controller_editEmployee(listaEmpleados);

            break;
        case 4:
             clean();
             mostrarEmpleados(listaEmpleados);
            break;


         case 5:
             clean();
             controller_removeEmployee(listaEmpleados);
            break;

        case 6:
             clean();
             controller_sortEmployee(listaEmpleados);
            break;

        case 7:
             clean();
             controller_saveAsText("data.csv",listaEmpleados);
            break;

        case 8:
             clean();
             controller_saveAsBinary("dataBinario.csv",listaEmpleados);
            break;

        case 9:
            controller_loadFromBinary("dataBinario.csv",listaEmpleados);
            break;

        case 10:
            rta = 'n';

            break;

        default:
            printf("no es una opcion.\n");
            break;
        }

        printf("\n");
        pause();
        clean();
    }
    while(rta=='s');

        return 0;
}
