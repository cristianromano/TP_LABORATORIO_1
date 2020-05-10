#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hardcodeo.h"
#include "bibloteca.h"
#include "sectores.h"




static int generarId()
{
	static int contadorId=0;
	contadorId++;
	return contadorId;
}

void ingresoDatos(eEmpleado emp[], int tam, eFecha auxFecha[])
{

    int i = 0;
    int indice;
    int id = generarId();

    indice = buscarLibre(emp,tam);

    if(indice == -1)
    {
        printf("NO HAY MAS LUGAR.");
    }

    else
    {

       /* printf("%d.ingrese ID: ",i+1);
        scanf("%d",&emp[indice].id);
        fflush(stdin);*/



        printf("%d.ingrese nombre: ",i+1);
        gets(emp[indice].nombre);
        fflush(stdin);

        printf("%d.ingrese apellido: ",i+1);
        gets(emp[indice].apellido);
        fflush(stdin);

        printf("%d.ingrese sector: ",i+1);
        scanf("%d",&emp[indice].idSector);
        fflush(stdin);

        printf("%d.ingrese edad: ",i+1);
        scanf("%d",&emp[indice].edad);
        fflush(stdin);

        printf("%d.ingrese sexo: ",i+1);
        scanf("%c",&emp[indice].sexo);
        fflush(stdin);

        printf("%d.ingrese sueldo: ",i+1);
        scanf("%f",&emp[indice].sueldo);
        fflush(stdin);

        printf("%d.ingrese fecha de entrada xx/xx/xxxx: \n",i+1);
        scanf("%d%d%d",&auxFecha[indice].dia,&auxFecha[indice].mes,&auxFecha[indice].anio);

        emp[indice].fechaIngreso = auxFecha[indice];

        fflush(stdin);

        emp[indice].id = id;

        emp[indice].isEmpty = 0;


        printf("\n");

        pregunta(emp,tam,auxFecha);
    }

}


void ordenamientoBurbuja(eEmpleado listado[], int tam)
{

    int i;
    int flagSwap;
    eEmpleado auxEmpleado;

    do
    {

        flagSwap=0;

        for(i=0; i<tam-1; i++)
        {

            if(listado[i].idSector>listado[i+1].idSector)
            {

                flagSwap = 1;
                auxEmpleado = listado[i];
                listado[i] = listado[i+1];
                listado[i+1] = auxEmpleado;

            }

            else if(listado[i].idSector == listado[i+1].idSector && listado[i].apellido>listado[i+1].apellido)
            {

                auxEmpleado = listado[i];
                listado[i] = listado[i+1];
                listado[i+1] = auxEmpleado;
            }
        }

    }
    while(flagSwap);
}

void initEmpleado(eEmpleado listado[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        listado[i].isEmpty = 1;

    }
}

void mostrarEmpleado(eEmpleado listado[],int tam, int tamsec , eSector sectores[])
{
    int trigger = 0;
    int i;

    printf("**********************************************************************************\n");
    printf("  ID      NOMBRE        APELLIDO        SECTOR     SEXO    SUELDO     FECHA INGRESO    SECTOR         hame EDAD\n");
    for(i=0; i<tam; i++)
    {

        if(listado[i].isEmpty == 0)
        {
            printListado(listado[i],tamsec,sectores);
            trigger = 1;
        }


    }

    if(trigger==0)
    {
        printf("no hay empleados.\n");
    }

}

void printListado(eEmpleado listado , int tamsec , eSector sectores[])
{

    char descripcion[20];

    cargarDescripcion(descripcion,sectores,listado.idSector,tamsec);

    printf("  %d  %10s %10s\t         %02d         %c      %5.2f     %02d/%0d/%d     %10s        %d\n",listado.id,listado.nombre,listado.apellido,listado.idSector,listado.sexo,listado.sueldo,listado.fechaIngreso.dia,
           listado.fechaIngreso.mes,listado.fechaIngreso.anio,descripcion,listado.edad);



}

int buscarLibre(eEmpleado listado[],int tam)
{
    int retorno = -1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(listado[i].isEmpty == 1)
        {
            retorno = i;
            break;
        }

    }

    return retorno;

}


int buscarEmpleado(int id, eEmpleado listado[], int tam)
{
    int i;
    int retorno = -1;

    for(i=0; i<tam; i++)
    {
        if(listado[i].id == id && listado[i].isEmpty == 0)
        {
            retorno = i;
            break;
        }
    }



    return retorno;

}



int menu()
{

    int opcion = 0;

    printf("1.INGRESAR EMPLEADO\n");
    printf("2.MODIFICAR EMPLEADO\n");
    printf("3.LISTAR EMPLEADO\n");
    printf("4.REMOVER EMPLEADO\n");
    printf("5.ORDENAR POR APELLIDO Y SECTOR A EMPLEADOS\n");
    printf("6.MENU DE INFORMES\n");
    printf("7.SALIR\n");


    printf("eliga una opcion: ");
    scanf("%d",&opcion);

    return opcion;


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



void pregunta(eEmpleado listado[], int tam, eFecha lista[])
{
    char pregunta;
    printf("desea seguir ingresando empleados? ");
    scanf("%c",&pregunta);


    if(pregunta=='s' || pregunta=='S' )
    {
        ingresoDatos(listado,tam,lista);
    }


}

void preguntaModificar(eEmpleado listado[], int tam , int tamsec , eSector sectores[])
{
    char pregunta;
    printf("desea modificar otros empleados? ");
    scanf("%c",&pregunta);


    if(pregunta=='s' || pregunta=='S' )
    {
        clean();
        modificar(listado,tam,tamsec,sectores);
    }


}

void preguntaEliminar(eEmpleado listado[], int tam , int tamsec , eSector sectores[])
{
    char pregunta;
    printf("desea eliminar otros empleados? ");
    scanf("%c",&pregunta);


    if(pregunta=='s' || pregunta=='S' )
    {
        clean();
        remover(listado,tam,tamsec,sectores);
    }


}


void modificar(eEmpleado listado[], int tam , int tamsec , eSector sectores[])
{
    int numero = 0;
    int id = 0;
    char nombre[20];
    char apellido[20];
    float sueldo;
    int sector;

    char respuesta;

    mostrarEmpleado(listado,tam,tamsec,sectores);

    printf("\ningrese el ID del empleado que desee modificar: ");
    scanf("%d",&numero);
    limpiarBuffer();


    if((id = buscarEmpleado(numero,listado,tam)) < 0)
    {
        printf("\nno se encontro empleado.\n");

    }

    else
    {
        printf("usuario encontrado.\n");
        pause();
        clean();

        printf("MODIFICAR:\n1.Nombre\n2.Sueldo\n3.Apellido\n4.Sector\neliga una opcion: ");
        scanf("%d",&numero);

        switch(numero)
        {
        case 1:
            printf("ingrese nuevo nombre: ");
            limpiarBuffer();
            gets(nombre);

            printf("esta seguro?: ");
            scanf("%c",&respuesta);
            limpiarBuffer();
            if(respuesta=='s' || respuesta=='S' )
            {

                strcpy(listado[id].nombre,nombre);
                printf("cambio realizado.\n");

            }

            else
            {
                printf("ningun cambio fue realizado.\n");
            }

            break;

        case 2:
            printf("ingrese nuevo sueldo: ");
            scanf("%f",&sueldo);

            printf("esta seguro?: ");
            limpiarBuffer();
            scanf("%c",&respuesta);
            limpiarBuffer();

            if(respuesta=='s' || respuesta=='S')
            {

                listado[id].sueldo = sueldo;
                printf("cambio realizado.\n");

            }

            else
            {
                printf("ningun cambio fue realizado.\n");
            }

            break;

        case 3:
            printf("ingrese nuevo apellido: ");
            limpiarBuffer();
            gets(apellido);

            printf("esta seguro?: ");
            scanf("%c",&respuesta);
            limpiarBuffer();
            if(respuesta=='s' || respuesta=='S' )
            {

                strcpy(listado[id].apellido,apellido);
                printf("cambio realizado.\n");

            }

            else
            {
                printf("ningun cambio fue realizado.\n");
            }
            break;

        case 4:
            printf("ingrese nuevo sector: ");
            scanf("%d",&sector);

            printf("esta seguro?: ");
            limpiarBuffer();
            scanf("%c",&respuesta);
            limpiarBuffer();

            if(respuesta=='s' || respuesta=='S')
            {

                listado[id].sector = sector;
                printf("cambio realizado.\n");

            }

            else
            {
                printf("ningun cambio fue realizado.\n");
            }

            break;


        default:
            printf("no es una opcion valida.\n");
            break;

        }

    }


    printf("\n");
    preguntaModificar(listado,tam,tamsec,sectores);


}



void remover(eEmpleado listado[], int tam , int tamsec , eSector sectores[])
{
    int numero = 0;
    int id = 0;
    char respuesta;

    mostrarEmpleado(listado,tam,tamsec,sectores);

    printf("ingrese ID de empleado a remover: ");
    scanf("%d",&numero);

    if((id = buscarEmpleado(numero,listado,tam)<0))
    {
        printf("no se encontro el ID\n");
    }

    else
    {

        printf("seguro desea remover al empleado? %s:",listado[id].nombre);
        limpiarBuffer();
        scanf("%c",&respuesta);
        limpiarBuffer();

        if(respuesta=='s' || respuesta=='S')
        {
            listado[id].isEmpty = 1;
            printf("empleado removido.\n");
        }
        else
        {
            printf("ningun cambio fue realizado.\n");
        }
    }

    printf("\n");
    preguntaEliminar(listado,tam,tamsec,sectores);

}



void hardcodeoDatos(eEmpleado listado[] , int tam)
{

int i;



    for(i=0 ; i<tam ; i++)
    {

        strcpy(listado[i].nombre,nombres[i]);
        limpiarBuffer();
        strcpy(listado[i].apellido,apellidos[i]);
        limpiarBuffer();
        listado[i].id = ids[i];

      //  listado[i].sector = idSectores[i];
        listado[i].sexo = sexos[i];
        listado[i].sueldo = sueldos[i];
        listado[i].fechaIngreso.dia = dias[i];
        listado[i].fechaIngreso.mes = meses[i];
        listado[i].fechaIngreso.anio = anios[i];
        listado[i].idSector = idSectores[i];
        listado[i].edad = edades[i];
         listado[i].isEmpty = 0;

    }

}

int cargarDescripcion(char descripcion[] , eSector sectores[] , int id , int tamsec)
{

    int i , retorno;

    retorno = -1;

    for(i=0;i<tamsec;i++)
    {
        if(sectores[i].id == id)
        {
            strcpy(descripcion,sectores[i].descripcion);
            retorno = 1;
        }

    }

    return retorno;

}


