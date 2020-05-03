#ifndef TP2_INFORMES_H
#define TP2_INFORMES_H

#include "ArrayEmployees.h"
#include <stdio.h>
#include <stdlib.h>

void mostrarInformes(eEmployee* list, int len);
int informarEmployees(eEmployee* list, int len);
int informarDatosSalarios(eEmployee* list, int len);
int menuOpciones(void);
int menuOpcionesOrden(void);

#endif //TP2_INFORMES_H
