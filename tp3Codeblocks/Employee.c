#include <stdlib.h>
#include "Employee.h"
#include <string.h>

Employee* employee_new()
{
    return (Employee*) malloc(sizeof(Employee));
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* employee = (Employee*) malloc(sizeof(Employee));
    employee->id = atoi(idStr);
    strcpy(employee->nombre, nombreStr);
    employee->horasTrabajadas = atoi(horasTrabajadasStr);
    employee->sueldo = atoi(sueldoStr);
}

int employee_setNombre(Employee* this,char* nombre)
{
    if(this != NULL && nombre != NULL) {
        strcpy(this->nombre, nombre);
        return 1;
    }
    return 0;
}

int employee_getNombre(Employee* this,char* nombre)
{
    if(this != NULL && nombre != NULL) {
        strcpy(nombre, this->nombre);
        return 1;
    }
    return 0;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    if(this != NULL) {
        this->sueldo = sueldo;
        return 1;
    }
    return 0;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    if(this != NULL && sueldo!= NULL) {
        *sueldo = this->sueldo;
        return 1;
    }
    return 0;
}

int employee_setId(Employee* this,int id)
{
    if(this != NULL && id!= NULL) {
        this->id = id;
        return 1;
    }
    return 0;
}
int employee_getId(Employee* this,int* id)
{
    if(this != NULL && id!= NULL) {
        *id = this->id;
        return 1;
    }
    return 0;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    if(this != NULL) {
        this->horasTrabajadas = horasTrabajadas;
        return 1;
    }
    return 0;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajdas)
{
    if(this != NULL && horasTrabajdas!= NULL) {
        *horasTrabajdas = this->horasTrabajadas;
        return 1;
    }
    return 0;
}


int employee_CompareByName(Employee* e1, Employee* e2)
{
    if(e1 != NULL && e2 != NULL && e1->nombre != NULL && e2->nombre != NULL) {
        return strcmp(e1->nombre, e2->nombre);
    }
    return -1;
}

int employee_CompareById(Employee* e1, Employee* e2)
{
    if(e1 != NULL && e2 != NULL && e1->id != NULL && e2->id != NULL) {
        if(e1->id > e2->id) {
            return 1;
        } else {
            if(e1->id < e2->id) {
                return -1;
            } else {
                return 0;
            }
        }
        return strcmp(e1->nombre, e2->nombre);
    }
    return -1;
}



