#include "bibloteca.h"
#include "sectores.h"

#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

void menuDeInformes(eEmpleado listado[] , int tam , eSector sectores[] , int tamsec);
void menuParaInformes();
void informeSalario(eEmpleado listado[] , int tam , int tamsec , eSector sectores[]);
void informeEmpleadoAnio(eEmpleado listado[] , int tam , eSector sectores[] , int tamsec);
void informeEmpleadoSector(eEmpleado listado[] , int tam , eSector sectores[] , int tamsec);
void informarEmpleadosXSector(eEmpleado listado[] , int tam , eSector sectores[] , int tamsec);
void informarMayorSueldoSector(eEmpleado listado[] , int tam , eSector sectores[] , int tamsec);
void informarMayorSueldoEmpleado(eEmpleado listado[] , int tam , eSector sectores[] , int tamsec);
void aumentoSueldoSector(eEmpleado listado[] , int tam , eSector sectores[] , int tamsec);
void informarSectorMasCostoso(eEmpleado listado[] , int tam , eSector sectores[] , int tamsec);
void totalSueldosXSector(eEmpleado listado[], int tam, eSector sectores[], int tamsec);
void cantidadEmpleadosXSector(eEmpleado listado[], int tam, eSector sectores[], int tamsec);
void empleadoMasJovenSector(eEmpleado listado[], int tam, eSector sectores[], int tamsec);







#endif // INFORMES_H_INCLUDED
