#ifndef SECTORES_H_INCLUDED
#define SECTORES_H_INCLUDED

typedef struct{

int id;
char descripcion[20];

}eSector;

void listarSectores(eSector sectores[] , int tamsec);

#endif // SECTORES_H_INCLUDED

