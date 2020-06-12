#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;

    pFile = fopen(path,"r+");

    int retorno = 1;

    if(pFile!=NULL)
    {
        parser_EmployeeFromText(pFile,pArrayListEmployee);
        printf("exito al cargar datos por texto.\n");
        retorno = 0;
    }
    else
    {
        printf("error al cargar datos por texto.\n");
    }


    fclose(pFile);

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;

    pFile = fopen(path,"rb");

    int retorno = 1;

    if(pFile!=NULL)
    {
        parser_EmployeeFromBinary(pFile,pArrayListEmployee);
        printf("exito al cargar datos por binario.\n");
        retorno = 0;
    }
    else
    {
        printf("error al cargar datos por binario.\n");
    }


    fclose(pFile);

    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* this;
    char nombre[20], sueldo[20], horasTrabajadas[20], id[20];
    int idAux;
    char rta;

    if(pArrayListEmployee!=NULL)
    {
        printf("ingrese nombre: ");
        fflush(stdin);

        gets(nombre);

        printf("ingrese sueldo: ");
        fflush(stdin);

        scanf("%s",sueldo);

        printf("ingrese horas trabajadas: ");
        fflush(stdin);

        scanf("%s",horasTrabajadas);

        fflush(stdin);

        idAux = ultimoID(pArrayListEmployee)+1;

        fflush(stdin);

        sprintf(id,"%d",idAux);

        fflush(stdin);

        printf("seguro que desea cargar empleado? s/n\n");
        scanf("%c",&rta);

        if(rta=='s' || rta=='S')
        {
            this = employee_newParametros(id,nombre,horasTrabajadas,sueldo);

            ll_add(pArrayListEmployee,this);

            printf("empleado cargado con exito.\n");
            pause();
            clean();
        }

        else
        {
            printf("no se a cargado empleado.\n");
            pause();
            clean();
        }

    }

    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int numero, opcion = 0;
    Employee* this;
    char rta;
    float sueldo;
    int horas;

    if(mostrarEmpleados(pArrayListEmployee)==0)
    {
        printf("ingrese ID de empleado que desea modificar: \n");
        scanf("%d",&numero);
        clean();

        if(pArrayListEmployee!=NULL)
        {
            this = buscarEmpleado(pArrayListEmployee,numero);

            if(this!=NULL)
            {
                printf("ID             NOMBRE      HORAS         SUELDO\n");
                printf("--------------------------------------------------\n");
                mostrarEmpleado(this);
                printf("\neste es el empleado que desea modificar? s/n\n");
                fflush(stdin);
                scanf("%c",&rta);

                if(rta=='s' || rta=='S')
                {
                    clean();
                    printf("que dato desea modificar?\n1.Sueldo\n2.Horas\n");
                    scanf("%d",&opcion);

                    switch(opcion)
                    {
                    case 1:
                        printf("ingrese nuevo sueldo: ");
                        scanf("%f",&sueldo);
                        employee_setSueldo(this,sueldo);
                        printf("nuevo sueldo cargado con exito\n");
                        break;

                    case 2:
                        printf("ingrese nuevo horario: ");
                        scanf("%d",&horas);
                        employee_setHorasTrabajadas(this,horas);
                        printf("nuevas horas cargadas con exito\n");
                        break;

                    default:
                        printf("no es una opcion\n");
                        break;
                    }
                }


            }

        }
    }





    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int numero;
    Employee* this;
    int index;
    char rta;

    if(mostrarEmpleados(pArrayListEmployee)==0)
    {
        printf("ingrese ID de empleado que desea remover: \n");
        scanf("%d",&numero);
        clean();

        if(pArrayListEmployee!=NULL)
        {
            this = buscarEmpleado(pArrayListEmployee,numero);

            if(this!=NULL)
            {
                printf("ID             NOMBRE      HORAS         SUELDO\n");
                printf("--------------------------------------------------\n");
                mostrarEmpleado(this);
                printf("\neste es el empleado que desea remover? s/n\n");
                fflush(stdin);
                scanf("%c",&rta);

                if(rta=='s' || rta=='S')
                {
                    clean();

                    index = ll_indexOf(pArrayListEmployee,this);
                    ll_remove(pArrayListEmployee,index);
                    printf("empleado removido con exito.\n");

                }
            }


        }

    }

    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int mostrarEmpleados(LinkedList* arrayEmpleados)
{
    int i;
    int retorno = 0;
    int flag = 0;

    Employee* this;

    if(arrayEmpleados!=NULL)
    {
        printf("ID             NOMBRE      HORAS         SUELDO\n");
        printf("--------------------------------------------------\n");
        for(i=0; i<ll_len(arrayEmpleados); i++)
        {
            this = (Employee*) ll_get(arrayEmpleados,i);

            if(this!=NULL)
            {
                mostrarEmpleado(this);
                flag = 1;

            }

            printf("--------------------------------------------------\n");
        }

        if(flag==0)
        {
            printf("no hay empleados.\n");

            retorno = 1;
        }

    }



    return retorno;

}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{

    int opcion;

    if(pArrayListEmployee!=NULL && (mostrarEmpleados(pArrayListEmployee))==0)
    {
        printf("eliga dato a ordenar: \n1.nombre\n2.ID\nopcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            ll_sort(pArrayListEmployee,sortNombre,1);
            printf("ordenado con exito.\n");
            break;

        case 2:
            ll_sort(pArrayListEmployee,sortID,1);
            printf("ordenado con exito.\n");
            break;

        default:
            printf("no es una opcion.\n");
            break;
        }
    }



    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{

    FILE* pFile;

    int i;

    pFile = fopen(path,"w+");

    Employee* this;


    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {

        fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");

        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
           this = (Employee*)ll_get(pArrayListEmployee,i);

           fprintf(pFile,"%d,%s,%d,%f\n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);


        }


        printf("guardado con exito.\n");
    }

    fclose(pFile);
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;

    int i;

    pFile = fopen(path,"wb");

    Employee* this;


    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {


        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
           this = (Employee*)ll_get(pArrayListEmployee,i);

           fwrite(this,sizeof(Employee),1,pFile);

        }

        fclose(pFile);
        printf("guardado con exito.\n");

    }


    return 1;
}

