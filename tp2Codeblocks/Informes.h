#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#include "ArrayEmployees.h"
#include <stdio.h>
#include <stdlib.h>

void mostrarInformes(eEmployee* list, int len);
int informarEmployees(eEmployee* list, int len);
int informarDatosSalarios(eEmployee* list, int len);
int menuOpciones(void);
int menuOpcionesOrden(void);

#endif // INFORMES_H_INCLUDED
