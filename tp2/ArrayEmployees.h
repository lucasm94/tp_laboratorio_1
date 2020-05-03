#ifndef TP2_ARRAYEMPLOYEES_H
#define TP2_ARRAYEMPLOYEES_H

#include <stdio.h>
#include <string.h>
#define STRINGLEN 51
#define FALSE 0
#define TRUE 1
#define UP 1
#define DOWN 0
#define NAME 0
#define LASTNAME 1

struct
{
    int id;
    char name[STRINGLEN];
    char lastName[STRINGLEN];
    float salary;
    int sector;
    int isEmpty;
}typedef eEmployee;

int initEmployees(eEmployee* list, int len);
int addEmployee(eEmployee* list, int len, int id, char name[], char lastName[], float salary, int sector);
int findEmployeeById(eEmployee* list, int len,int id);
int removeEmployee(eEmployee* list, int len, int id);
int sortEmployees(eEmployee* list, int len, int order);
int printEmployees(eEmployee* list, int length);
int buscarLibre(eEmployee* list, int length);
int createId(eEmployee* list, int len);
int sortEmployeesUp(eEmployee* list, int len);
int sortEmployeesDown(eEmployee* list, int len);
int mostrarInfoSalarios(eEmployee* list, int length);
int sumaSalarios(eEmployee* list, int length);
int cantidadSalariosMayorAlPromedio(eEmployee* list, int length, float promedio);
float promedioSalarios(eEmployee* list, int length, int total);
int actualizarNombreOApellido(eEmployee* list, int length, int id, char valor[51], int atributo);
int actualizarSector(eEmployee* list, int length, int id, int sector);
int actualizarSalario(eEmployee* list, int length, int id, float salario);

#endif //TP2_ARRAYEMPLOYEES_H
