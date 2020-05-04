#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "StringAcotado.h"

int menu(void);
int mostrarOpcionesMenu(void);
int agregarEmpleado(eEmployee* list, int len, int lenInput, int reintentos);
void modificarEmpleado(eEmployee* list, int len, int lenInput, int reintentos);
void eliminarEmpleado(eEmployee* list, int len);
void mostrarNoCargoEmpleados(char mensaje[]);
int mostrarMenuActualizar(void);
void mostrarResultadoActualizacion(int resultado);
int ingreseInt(char mensaje[], char error[], int minimo, int reintentos);
float ingreseFloat(char mensaje[], char error[], int minimo, int reintentos);
eString ingreseString(char mensaje[], char error[], int maximo, int reintentos);
void superoIntentos(int resultado, int reintentos);
eEmployee ingresoDatosEmpleado(int lenInput, int reintentos);

#endif // MENU_H_INCLUDED
