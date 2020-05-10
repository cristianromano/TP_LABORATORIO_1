#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informes.h"
#include "bibloteca.h"
#include "sectores.h"
#define TAM 7
#define TAMSECTORES 5


void menuDeInformes(eEmpleado listado[], int tam, eSector sectores[], int tamsec)
{
    int numero = 0;
    char seguir = 's';



    do
    {

        menuParaInformes();
        printf("ingrese opcion: ");
        scanf("%d",&numero);

        switch(numero)
        {
        case 1:
            clean();
            informeSalario(listado,TAM,TAMSECTORES,sectores);
            break;
        case 2:
            clean();
            informeEmpleadoAnio(listado,TAM,sectores,TAMSECTORES);
            break;

        case 3:
            clean();
            informeEmpleadoSector(listado,TAM,sectores,TAMSECTORES);
            break;

        case 4:
            clean();
            informarEmpleadosXSector(listado,TAM,sectores,TAMSECTORES);
            break;

        case 5:
            clean();
            informarMayorSueldoSector(listado,TAM,sectores,TAMSECTORES);
            break;

        case 6:
            clean();
            informarMayorSueldoEmpleado(listado,TAM,sectores,TAMSECTORES);
            break;

        case 7:
            clean();
            aumentoSueldoSector(listado,TAM,sectores,TAMSECTORES);
            break;

        case 8:
            clean();
            informarSectorMasCostoso(listado,TAM,sectores,TAMSECTORES);
            break;

        case 9:
            clean();
            totalSueldosXSector(listado,TAM,sectores,TAMSECTORES);
            break;

        case 10:
            clean();
            cantidadEmpleadosXSector(listado,TAM,sectores,TAMSECTORES);
            break;

        case 11:
            clean();
            empleadoMasJovenSector(listado,TAM,sectores,TAMSECTORES);
            break;

        case 12:
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


}

void menuParaInformes()
{

    printf("1.INFORMES SOBRE SUELDOS\n");
    printf("2.INFORME SOBRE ANIO DE INGRESO\n");
    printf("3.INFORME SOBRE EMPLEADO X SECTOR\n");
    printf("4.INFORME EMPLEADOS TODOS LOS SECTORES\n");
    printf("5.INFORME EMPLEADOS MAYOR SUELDO DEL SECTOR\n");
    printf("6.INFORME NOMBRE EMPLEADO/S CON MAYOR SUELDO DEL SECTOR\n");
    printf("7.AUMENTO DEL SUELDO X PORCENTAJE DE UN SECTOR SELECCIONADO\n");
    printf("8.INFORME SECTOR MAS COSTOSO\n");
    printf("9.INFORME SOBRE EL TOTAL DE SUELDOS X SECTOR\n");
    printf("10.INFORME SOBRE LA CANTIDAD DE EMPLEADOS X SECTOR\n");
    printf("11.INFORME SOBRE EL EMPLEADO MAS JOVEN X SECTOR\n");
    printf("12.SALIR DEL MENU DE INFORMES EMPLEADOS\n");

}

void informeSalario(eEmpleado listado[], int tam, int tamsec, eSector sectores[])
{
    int i;
    int contador = 0;
    float acumulador = 0;
    float promedio = 0;


    for(i=0; i<tam; i++)
    {
        acumulador += listado[i].sueldo;
        contador++;

    }

    promedio = acumulador / contador;

    printf("el total de los sueldos es: %.2f\n",acumulador);
    printf("el promedio de los sueldos es: %.2f\n",promedio);
    printf("EMPLEADOS QUE SUPERAN EL PROMEDIO: \n");


    for(i=0; i<tam; i++)
    {
        if(promedio < listado[i].sueldo)
        {
            printListado(listado[i],tamsec,sectores);
        }

    }

}


void informeEmpleadoAnio(eEmpleado listado[], int tam, eSector sectores[], int tamsec)
{

    int i;
    int numero;
    int trigger = 0;

    printf("ingrese anio de ingreso: ");
    scanf("%d",&numero);


    printf("**********************************************************************************\n");
    printf("  ID      NOMBRE        APELLIDO        SECTOR     SEXO    SUELDO     FECHA INGRESO    SECTOR\n");

    for(i=0; i<tam; i++)
    {

        if(listado[i].fechaIngreso.anio == numero && listado[i].isEmpty == 0)
        {
            printListado(listado[i],tamsec,sectores);
            printf("*************************************************************************************************\n");
            trigger = 1;
        }

    }

    if(trigger == 0)
    {
        printf("no hay empleado registrado en el anio %d\n",numero);
    }


}

void informeEmpleadoSector(eEmpleado listado[], int tam, eSector sectores[], int tamsec)
{


    int i;
    int numero;
    int trigger = 0;

    char descripcion[20];

    listarSectores(sectores,tamsec);

    printf("ingrese sector: ");
    scanf("%d",&numero);

    cargarDescripcion(descripcion,sectores,numero,tamsec);


    clean();

    printf("*********************************************************************************************************\n");
    printf("  ID      NOMBRE        APELLIDO        SECTOR     SEXO    SUELDO     FECHA INGRESO    SECTOR\n");

    for(i=0; i<tam; i++)
    {

        if(listado[i].idSector == numero && listado[i].isEmpty == 0)
        {
            printListado(listado[i],tamsec,sectores);
            printf("*************************************************************************************************\n");
            trigger = 1;
        }

    }

    if(trigger == 0)
    {
        printf("no hay empleado registrado en el sector %s\n",descripcion);
    }


}



void informarEmpleadosXSector(eEmpleado listado[], int tam, eSector sectores[], int tamsec)
{
    int i, j;
    int trigger;

    for(i=0; i<tamsec; i++)
    {

        printf("SECTOR %s\n",sectores[i].descripcion);

        trigger = 0;
        for(j=0; j<tam; j++)
        {
            if(listado[j].idSector == sectores[i].id && listado[j].isEmpty == 0)
            {
                printListado(listado[j],tamsec,sectores);
                trigger = 1;
            }
        }


        if(trigger == 0)
        {
            printf("no hay empleados en ese sector.\n");
        }

        printf("*************************************************************************************************\n");

    }

}


void informarMayorSueldoSector(eEmpleado listado[], int tam, eSector sectores[], int tamsec)
{

    int i;
    int numero = 0;
    float mayor = 0;
    char descripcion[20];
    int trigger;

    listarSectores(sectores,tamsec);
    printf("Ingrese el sector: ");
    scanf("%d",&numero);

    cargarDescripcion(descripcion,sectores,numero,tamsec);


    trigger = 0;

    for(i=0; i<tam; i++)
    {
        if(listado[i].idSector == numero && listado[i].isEmpty == 0)
        {

            if(listado[i].sueldo > mayor)
            {
                mayor = listado[i].sueldo;
                trigger = 1;
            }


        }


    }

    if(trigger == 0)
    {
        printf("no hay empleados en ese sector.\n");
    }


    else
    {
        printf("el mayor sueldo del sector %s es: %.2f\n",descripcion,mayor);
    }



}

void informarMayorSueldoEmpleado(eEmpleado listado[], int tam, eSector sectores[], int tamsec)
{

    int i;
    int numero = 0;
    float mayor = 0;
    char descripcion[20];
    char nombre[20];
    int trigger;

    listarSectores(sectores,tamsec);
    printf("Ingrese el sector: ");
    scanf("%d",&numero);

    cargarDescripcion(descripcion,sectores,numero,tamsec);


    trigger = 0;

    for(i=0; i<tam; i++)
    {
        if(listado[i].idSector == numero && listado[i].isEmpty == 0)
        {

            if(listado[i].sueldo > mayor)
            {
                mayor = listado[i].sueldo;
                strcpy(nombre,listado[i].nombre);
                trigger = 1;
            }


        }


    }

    if(trigger == 0)
    {
        printf("no hay empleados en ese sector.\n");
    }


    else
    {
        printf("el nombre del empleado que mas gana del sector es: %s \n",nombre);
    }



}


void aumentoSueldoSector(eEmpleado listado[], int tam, eSector sectores[], int tamsec)
{

    int i;
    char descripcion[20];
    float aumento;
    int porcentaje;
    int numero;

    listarSectores(sectores,tamsec);
    printf("Ingrese el sector: ");
    scanf("%d",&numero);
    printf("Ingrese el aumento al sector: ");
    scanf("%d",&porcentaje);

    cargarDescripcion(descripcion,sectores,numero,tamsec);

    for(i=0; i<tam; i++)
    {

        if(listado[i].idSector == numero)
        {

            aumento = (listado[i].sueldo * porcentaje)/100;

            listado[i].sueldo += aumento;

        }


    }


}


void informarSectorMasCostoso(eEmpleado listado[], int tam, eSector sectores[], int tamsec)
{

    int i, j;
//   int trigger;
    float acumulador;
    char descripcion[20];
    char sector[20];
    float mayor = 0;

    for(i=0; i<tamsec; i++)
    {

        acumulador = 0;
        for(j=0; j<tam; j++)
        {

            if(listado[j].idSector == sectores[i].id && listado[j].isEmpty == 0)
            {

                cargarDescripcion(descripcion,sectores,sectores[i].id,tamsec);
                acumulador = acumulador + listado[j].sueldo;


            }

        }

        if(acumulador > mayor)
        {
            mayor = acumulador;
            strcpy(sector,descripcion);
        }



    }


    printf("el sector con mas costo es el %s con un total de %.2f\n",sector,mayor);



}


void totalSueldosXSector(eEmpleado listado[], int tam, eSector sectores[], int tamsec)
{

    int i, j;
    int trigger;
    float acumulador = 0;

    for(i=0; i<tamsec; i++)
    {

        printf("SECTOR %s\n",sectores[i].descripcion);

        acumulador = 0;
        trigger = 0;
        for(j=0; j<tam; j++)
        {
            if(listado[j].idSector == sectores[i].id && listado[j].isEmpty == 0)
            {
                acumulador = acumulador + listado[j].sueldo;
                trigger = 1;
            }
        }

        printf("el total de sueldos del sector %s es de: %.2f\n",sectores[i].descripcion,acumulador);

        if(trigger == 0)
        {
            printf("no hay empleados en ese sector.\n");
        }

        printf("*************************************************************************************************\n");

    }


}


void cantidadEmpleadosXSector(eEmpleado listado[], int tam, eSector sectores[], int tamsec)
{

    int i, j;
    int trigger;
    int acumulador = 0;

    for(i=0; i<tamsec; i++)
    {

        printf("SECTOR %s\n",sectores[i].descripcion);

        acumulador = 0;
        trigger = 0;
        for(j=0; j<tam; j++)
        {
            if(listado[j].idSector == sectores[i].id && listado[j].isEmpty == 0)
            {
                acumulador++;
                trigger = 1;
            }
        }

        printf("el total de empleados del sector %s es de: %d\n",sectores[i].descripcion,acumulador);

        if(trigger == 0)
        {
            printf("no hay empleados en ese sector.\n");
        }

        printf("*************************************************************************************************\n");

    }

}



void empleadoMasJovenSector(eEmpleado listado[], int tam, eSector sectores[], int tamsec)
{
    int i, j;
    int trigger;
    int menorEdad;


    for(i=0; i<tamsec; i++)
    {

        printf("SECTOR %s\n",sectores[i].descripcion);

        menorEdad = 0;
        trigger = 0;
        for(j=0; j<tam; j++)
        {
            if(listado[j].idSector == sectores[i].id && listado[j].isEmpty == 0)
            {
                if(listado[j].edad < menorEdad || trigger == 0)
                {
                    menorEdad = listado[j].edad;
                    trigger = 1;
                }

            }
        }

        printf("el empleado mas joven del sector %s es de: %d\n",sectores[i].descripcion,menorEdad);

        if(trigger == 0)
        {
            printf("no hay empleados en ese sector.\n");
        }

        printf("*************************************************************************************************\n");

    }
}


















