#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct{

int dia;
int mes;
int anio;

}eFecha;

typedef struct{

char nombre[20];
char apellido[20];
int sector;
int id;
float sueldo;
eFecha fechaIngreso;
int isEmpty;
int idSector;
int edad;

}eEmpleado;


void ingresoDatos(eEmpleado emp[] , int tam , eFecha auxFecha[]);
void printListado(eEmpleado listado);
void ordenamientoBurbuja(eEmpleado listado[] , int tam);
void initEmpleado(eEmpleado listado[], int tam);
int mostrarEmpleado(eEmpleado listado[],int tam);
int buscarLibre(eEmpleado listado[],int tam);
int buscarEmpleado(int id , eEmpleado listado[] , int tam);
int menu();
void clean();
void pause();
void limpiarBuffer();
void modificar(eEmpleado listado[], int tam);
void pregunta(eEmpleado listado[] , int tam , eFecha lista[]);
void preguntaModificar(eEmpleado listado[], int tam);
void remover(eEmpleado listado[], int tam);
void preguntaEliminar(eEmpleado listado[], int tam);
void hardcodeoDatos(eEmpleado listado[] , int tam);


#endif // EMPLEADO_H_INCLUDED
