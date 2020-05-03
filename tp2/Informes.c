#include "Informes.h"

/** \brief muestra menu de opciones para ver informes
*
* \param list Employee* Pointer to array of employees
* \param len int Array length
*
*/
void mostrarInformes(eEmployee* list, int len) {
    int opcion;
    int resultadoMuestra;
    int orden;
    do {
        opcion = menuOpciones();
        switch(opcion)
        {
            case 1:
                orden = menuOpcionesOrden();
                if(orden == UP) {
                    sortEmployees(list, len, UP);
                } else {
                    sortEmployees(list, len, DOWN);
                }
                resultadoMuestra = informarEmployees(list, len);
                if(resultadoMuestra == -1) {
                    printf("No se pudo ejecutar la muestra de empleados, intente en otro momento");
                }
                break;
            case 2:
                resultadoMuestra = informarDatosSalarios(list, len);
                if(resultadoMuestra == -1) {
                    printf("No se pudo ejecutar la muestra de datos sobre los salarios, intente en otro momento");
                }
                break;
        }
        if(opcion != 3) {
            system("read -p 'Presionar enter para continuar...' var");
        }
        system("clear");
    }while(opcion!=3);

}

/** \brief muestra menu de opciones
*
* \return int opcion
*
*/
int menuOpciones(void) {
    int opcion;
    printf("Seleccionar una opción\n");
    printf("1. Listado de empleados \n");
    printf("2. Informacion sobre salarios \n");
    printf("3. Salir\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

/** \brief muestra menu de opciones de orden
*
* \return int opcion, UP o DOWN
*
*/
int menuOpcionesOrden(void) {
    int opcion;
    do {
        printf("Seleccionar una opción\n");
        printf("1. Orden de empleados ascendente \n");
        printf("2. Orden de empleados descendente \n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
    } while(opcion != 1 && opcion != 2);
    if(opcion == 1) {
        return UP;
    } else {
        return DOWN;
    }
}

/** \brief muestra lista de empleados
*
* \param list Employee*
* \param len int
* \return int -1 si hay error, 0 si ok
*
*/
int informarEmployees(eEmployee* list, int len) {
    return printEmployees(list, len);
}

/** \brief muestra informacion sobre el salario y los empleados
*
* \param list Employee*
* \param len int
* \return int -1 si hay error, 0 si ok
*
*/
int informarDatosSalarios(eEmployee* list, int len) {
    return mostrarInfoSalarios(list, len);
}