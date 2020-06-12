#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    float sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,float sueldo);
int employee_getSueldo(Employee* this,float* sueldo);

int mostrarEmpleado(Employee* this);

int mostrarEmpleados(LinkedList* arrayEmpleados);

Employee* buscarEmpleado(LinkedList* arrayEmpleados, int id);
int ultimoID(LinkedList* arrayEmpleados);

void clean();
void pause();
void limpiarBuffer();

int sortNombre(void* datoUno , void* datoDos);
int sortID(void* datoUno , void* datoDos);

#endif // employee_H_INCLUDED
