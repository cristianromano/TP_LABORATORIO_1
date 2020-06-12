#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

Employee* employee_new()
{
    Employee* this;

    this = (Employee*)malloc(sizeof(Employee));

    if(this!= NULL)
    {

        this->id = 0;
        this->horasTrabajadas = 0;
        this->sueldo = 0.0;
        strcpy(this->nombre," ");

    }

    else
    {
        printf("no hay lugar libre.\n");
    }
    return this;


}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* this = employee_new();

    int id, horasTrabajadas;
    float sueldo;

    if(this!=NULL)
    {
        id = atoi(idStr);
        horasTrabajadas = atoi(horasTrabajadasStr);
        sueldo = atof(sueldoStr);

        employee_setId(this,id);
        employee_setHorasTrabajadas(this,horasTrabajadas);
        employee_setNombre(this,nombreStr);
        employee_setSueldo(this,sueldo);
    }

    return this;

}

void employee_delete(Employee* this)
{
    free(this);
}

int employee_setId(Employee* this,int id)
{
    int retorno = 1;

    if(this!=NULL)
    {
        this->id = id;
        retorno = 0;
    }

    return retorno;
}


int employee_getId(Employee* this,int* id)
{

    int retorno = 1; // mal

    if(this!=NULL)
    {
        *id = this->id;
        retorno = 0;
    }

    return retorno;

}

int employee_setNombre(Employee* this,char* nombre)
{

    int retorno = 1;

    if(this!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno = 0;
    }

    return retorno;

}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = 1; // mal

    if(this!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno = 0;
    }

    return retorno;
}


int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = 1;

    if(this!=NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 0;
    }

    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = 1; // mal

    if(this!=NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }

    return retorno;
}

int employee_setSueldo(Employee* this,float sueldo)
{
    int retorno = 1;

    if(this!=NULL)
    {
        this->sueldo = sueldo;
        retorno = 0;
    }

    return retorno;
}

int employee_getSueldo(Employee* this,float* sueldo)
{

    int retorno = 1; // mal

    if(this!=NULL)
    {
        *sueldo = this->sueldo;
        retorno = 0;
    }

    return retorno;
}

int mostrarEmpleado(Employee* this)
{
    int retorno = 1;

    if(this!=NULL)
    {
        printf("%04d  %15s       %4d         %6.2f\n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);
        retorno = 0;
    }

    return retorno;

}

/*int mostrarEmpleados(LinkedList* arrayEmpleados)
{
    int i;
    int retorno = 1;
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
        }


    }



    return retorno;

}*/

Employee* buscarEmpleado(LinkedList* arrayEmpleados, int id)
{

    int i;
    Employee* this = NULL;

    if(arrayEmpleados!=NULL)
    {
        for(i=0; i<ll_len(arrayEmpleados); i++)
        {

            this = (Employee*)ll_get(arrayEmpleados,i);

            if(this->id == id)
            {
                return this;
            }


        }
    }


    return this;

}




int ultimoID(LinkedList* arrayEmpleados)
{
    int retorno = -1;
    int mayor = 0;
    int flag = 0;
    Employee* this;
    int i;

    if(arrayEmpleados!=NULL)
    {
        for(i=0; i<ll_len(arrayEmpleados); i++)
        {
            this = (Employee*)ll_get(arrayEmpleados,i);

            if(this!=NULL)
            {
                if(this->id > mayor || flag == 0)
                {
                    mayor = this->id;
                    flag = 1;
                }
            }
        }

        retorno = mayor;


    }

    return retorno;
}



int sortID(void* datoUno , void* datoDos)
{

   int retorno;
   Employee* idUno = (Employee*) datoUno;
   Employee* idDos = (Employee*) datoDos;

   if(idUno->id < idDos->id)
   {
       retorno =  1;
   }

   else if(idUno->id > idDos->id)
   {
       retorno =  0;
   }


   return retorno;
}



int sortNombre(void* datoUno , void* datoDos)
{

   int retorno;
   Employee* nombreUno = (Employee*) datoUno;
   Employee* nombreDos = (Employee*) datoDos;

   if(strcmp(nombreUno->nombre , nombreDos->nombre)>0)
   {
       retorno =  1;
   }

   else if(strcmp(nombreUno->nombre , nombreDos->nombre)<0)
   {
       retorno =  0;
   }


   return retorno;
}

void menu(int* opcion)
{

    printf("1.CARGAR TEXTO\n2.AGREGAR EMPLEADO\n3.EDITAR EMPLEADO\n4.MOSTRAR EMPLEADO\n5.REMOVER EMPLEADO\n6.ORDENAR EMPLEADO\n7.GUARDAR EN TEXTO\n8.GUARDAR EN BINARIO\n9.CARGAR BINARIO\n10.SALIR\nOPCION: ");
    scanf("%d",&*opcion);

}

void clean()
{
    system("cls");
}

void pause()
{
    system("pause");
}

void limpiarBuffer()
{
    fflush(stdin);
}
