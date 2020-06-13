#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Menu.h"
#define DATA_CSV_R "data.csv"
#define DATA_CSV_W "data.csv"
#define DATA_BIN_R "data.bin"
#define DATA_BIN_W "data.bin"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main() {

    LinkedList* miLista2 = ll_newLinkedList();

    int opcion;

    do {

        opcion = opcionMenu();

        switch(opcion) {
            case 1:
                if(controller_loadFromText(DATA_CSV_R, miLista2)) {
                    printf("Empleados cargados\n");
                } else {
                    printf("No se pudieron cargar los empleados\n");
                }
                break;
            case 2:
                if(controller_loadFromBinary(DATA_BIN_R, miLista2)) {
                    printf("Empleados cargados\n");
                } else {
                    printf("No se pudieron cargar los empleados\n");
                }
                break;
            case 3:
                if(controller_addEmployee(miLista2)) {
                    printf("Empleado agregado\n");
                } else {
                    printf("No se pudo agregar al empleado");
                }
                break;
            case 4:
                if(controller_editEmployee(miLista2)) {
                    printf("Empleado editado\n");
                } else {
                    printf("No se pudo editar al empleado\n");
                }
                break;
            case 5:
                if(controller_removeEmployee(miLista2)) {
                    printf("Empleado eliminado\n");
                } else {
                    printf("No se pudo eliminar al empleado\n");
                }
                break;
            case 6:
                controller_ListEmployee(miLista2);
                break;
            case 7:
                if(controller_sortEmployee(miLista2)) {
                    printf("Empleados ordenados\n");
                    controller_ListEmployee(miLista2);
                } else {
                    printf("No se pudo ordenar a los empleados\n");
                }
                break;
            case 8:
                if(controller_saveAsText(DATA_CSV_W, miLista2)) {
                    printf("Archivo generado\n");
                    ll_deleteLinkedList(miLista2);
                } else {
                    printf("No se pudo generar el archivo\n");
                }
                break;
            case 9:
                if(controller_saveAsBinary(DATA_BIN_W, miLista2)) {
                    printf("Archivo generado\n");
                    ll_deleteLinkedList(miLista2);
                } else {
                    printf("No se pudo generar el archivo\n");
                }
                break;
        }

        if(opcion == 8 || opcion == 9) {
            miLista2 = ll_newLinkedList();
        }

        if(opcion != 10) {
            system("read -p 'Presionar enter para continuar...' var");
        }
        system("clear");

    } while(opcion != 10);

    return 0;
}
