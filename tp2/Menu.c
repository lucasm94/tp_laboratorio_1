#include "Menu.h"
#include "Informes.h"
#include <stdio_ext.h>
#define REINTENTOS 10
#define T 1000

/** \brief abm de empleados
*
* \return 0
*
*/
int menu(void) {
    eEmployee employees[T];
    int opcion;
    int cargoEmpleados = initEmployees(employees, T);
    if(!cargoEmpleados) {
        do {
            opcion = mostrarOpcionesMenu();
            switch(opcion) {
                case 1:
                    if(agregarEmpleado(employees, T, STRINGLEN, REINTENTOS)) {
                        cargoEmpleados = 1;
                    }
                    break;
                case 2:
                    if(cargoEmpleados) {
                        modificarEmpleado(employees, T, STRINGLEN, REINTENTOS);
                    } else {
                        mostrarNoCargoEmpleados("Actualizar");
                    }
                    break;
                case 3:
                    if(cargoEmpleados) {
                        eliminarEmpleado(employees, T);
                    } else {
                        mostrarNoCargoEmpleados("eliminar");
                    }
                    break;
                case 4:
                    if(cargoEmpleados){
                        mostrarInformes(employees, T);
                    } else {
                        mostrarNoCargoEmpleados("informar");
                    }
                    break;
            }
            if(opcion != 5) {
                system("read -p 'Presionar enter para continuar...' var");
            }
            system("clear");
        }while(opcion!=5);
    } else {
        printf("Error al inicializar los empleados\n");
    }
    return 0;
}

/** \brief muestra mensaje de error por no poder cargar empleados
*
* \param char mensaje[]
*
*/
void mostrarNoCargoEmpleados(char mensaje[]) {
    printf("Para poder %s debe existir por lo menos un empleado\n", mensaje);
    printf("para eso ejecute la opcion 1. Ingresar empleadoo.\n");
}

/** \brief muestra menu de opciones para el abm
*
* \return opcion int
*
*/
int mostrarOpcionesMenu(void) {
    int opcion;
    printf("Seleccionar una opción\n");
    printf("1. Ingresar empleado \n");
    printf("2. Modificar empleado \n");
    printf("3. Eliminar empleado\n");
    printf("4. Informar empleados\n");
    printf("5. Salir\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

/** \brief alta de empleado
*
* \param list Employee*
* \param len int
* \param lenInput int
* \param reintentos int
* \return int 0 si hay error, 1 si ok
*
*/
int agregarEmpleado(eEmployee* list, int len,int lenInput, int reintentos) {
    eEmployee employee = ingresoDatosEmpleado(lenInput, reintentos);
    if(employee.isEmpty == TRUE) {
        printf("Supero el maximo de intentos al ingresar los datos del empleado, reintente luego\n");
    } else {
        employee.id = createId(list, len);
        if(addEmployee(list, len, employee.id, employee.name, employee.lastName, employee.salary, employee.sector) == 0) {
            printf("Se agrego al empleado %s %s con exito \n", employee.name, employee.lastName);
            return 1;
        } else {
            printf("No se pudo agregar al empleado %s %s \n", employee.name, employee.lastName);
            return 0;
        }
    }
}

/** \brief crea un empleado
*
* \param lenInput int
* \param reintentos int
* \return eEmployee empty si hay error en el ingreso de datos, eEmployee con datos ingresados si es ok
*
*/
eEmployee ingresoDatosEmpleado(int lenInput, int reintentos) {
    eEmployee employee = {0, "", "", -1, -1, TRUE};
    printf("Agregar empleado - Debera ingresar los siguientes datos: \n");
    for(int i = 0; i<3 && employee.isEmpty == TRUE; i++) {
        if(strlen(employee.name) == 0) {
            strcpy(employee.name, (ingreseString("Ingrese nombre: ", "Ingreso un nombre invalido\n", lenInput, reintentos)).valor);
        }
        if(strlen(employee.lastName) == 0) {
            strcpy(employee.lastName, (ingreseString("Ingrese apellido: ", "Ingreso un apellido invalido\n", lenInput, reintentos)).valor);
        }
        if(employee.salary == -1) {
            employee.salary = ingreseFloat("Ingrese salario: ", "Ingreso un salario invalido\n", 0, reintentos);
        }
        if(employee.sector == -1) {
            employee.sector = ingreseInt("Ingrese sector: ", "Ingreso un sector invalido\n", 0, reintentos);
        }
        if(strlen(employee.name) > 0 && strlen(employee.lastName) > 0 && employee.salary != -1 && employee.sector != -1) {
            employee.isEmpty = FALSE;
        }
    }
    return employee;
}

/** \brief ingreso de id
*
* \param char mensaje[] - tipo de opcion donde se va a pedir el ingreso de id
* \return id ingresado
*
*/
int ingresarId(char mensaje[]) {
    int id;
    printf("%s empleado - Debera ingresar el id del empleado a %s: ", mensaje, mensaje);
    scanf("%d", &id);
    return id;
}

/** \brief elimina empleado
*
* \param list Employee*
* \param len int
*
*/
void eliminarEmpleado(eEmployee* list, int len) {
    int id = ingresarId("eliminar");
    if(removeEmployee(list, len, id) != -1) {
        printf("se elimino el empleado con id: %d \n", id);
    } else {
        printf("No se encontro al empleado con id: %d \n", id);
    }
}

/** \brief modifica empleado
*
* \param list Employee*
* \param len int
* \param lenInput int
* \param reintentos int
*
*/
void modificarEmpleado(eEmployee* list, int len, int lenInput, int reintentos) {
    int id = ingresarId("modificar");
    int opcion;
    float nuevoSalario;
    int nuevoSector;
    int resultado;
    eString string;
    do {
        opcion = mostrarMenuActualizar();
        switch (opcion) {
            case 1:
                string = ingreseString("Ingrese nombre: ", "Ingreso un nombre invalido\n", lenInput, reintentos);
                if(strlen(string.valor) > 0) {
                    resultado = actualizarNombreOApellido(list, len, id, string.valor, NAME);
                    mostrarResultadoActualizacion(resultado);
                }
                break;
            case 2:
                string = ingreseString("Ingrese apellido: ", "Ingreso un apellido invalido\n", lenInput, reintentos);
                if(strlen(string.valor) > 0) {
                    resultado =  actualizarNombreOApellido(list, len, id, string.valor, LASTNAME);
                    mostrarResultadoActualizacion(resultado);
                }
                break;
            case 3:
                nuevoSalario = ingreseFloat("Ingrese salario: ", "Ingreso un salario invalido\n", 0, reintentos);
                if(nuevoSalario != -1) {
                    resultado =  actualizarSalario(list, len, id, nuevoSalario);
                    mostrarResultadoActualizacion(resultado);
                }
                break;
            case 4:
                nuevoSector = ingreseInt("Ingrese sector: ", "Ingreso un sector invalido\n", 0, reintentos);
                if(nuevoSector != -1) {
                    resultado =  actualizarSector(list, len, id, nuevoSector);
                    mostrarResultadoActualizacion(resultado);
                }
                break;
        }
    } while(opcion != 5);
}

/** \brief menu de opciones para actualizar empleado
*
* \return opcion
*
*/
int mostrarMenuActualizar(void) {
    int opcion;
    printf("Menu Actualizar\n");
    printf("Seleccionar una opción:\n");
    printf("1. Modificar nombre \n");
    printf("2. Modificar apellido \n");
    printf("3. Modificar salario\n");
    printf("4. Modificar sector\n");
    printf("5. Salir\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

/** \brief muestra mensaje de resultado de actualizacion
*
* \param resultado int, -1 si hubo error al realizar la actualizacion
*
*/
void mostrarResultadoActualizacion(int resultado) {
    if(resultado == -1) {
        printf("No se pudo realizar la actualizacion, el id no existe\n");
    } else {
        printf("Se realizo la actualizacion\n");
    }
}

/** \brief pide al usuario el ingreso de un int
*
* \return -1 error al superar el maximo de reintentos, valor ingesado
*
*/
int ingreseInt(char mensaje[], char error[], int minimo, int reintentos) {
    int valor = -1;
    int i = 0;
    for(i; i < reintentos && valor == -1; i++) {
        printf(mensaje);
        scanf("%d", &valor);
        if(valor < minimo) {
            valor = -1;
            printf(error);
        }
    }
    superoIntentos(i, reintentos);
    return valor;
}

/** \brief pide al usuario el ingreso de un float
*
* \param mensaje[] char
* \param error[] char
* \param minimo int
* \param resultado int
*
* \return -1 error al superar el maximo de reintentos, valor ingesado
*
*/
float ingreseFloat(char mensaje[], char error[], int minimo, int reintentos) {
    float valor = -1;
    int i = 0;
    for(i; i < reintentos && valor == -1; i++) {
        printf(mensaje);
        scanf("%f", &valor);
        if(valor < minimo) {
            valor = -1;
            printf(error);
        }
    }
    superoIntentos(i, reintentos);
    return valor;
}

/** \brief pide al usuario el ingreso de un "string"
*
* \param mensaje[] char
* \param error[] char
* \param minimo int
* \param resultado int
*
* \return -1 error al superar el maximo de reintentos, valor ingesado
*
*/
eString ingreseString(char mensaje[], char error[], int maximo, int reintentos) {
    eString string = {""};
    char ingreso[maximo];
    int i = 0;
    int inputOk = FALSE;
    for(i; i < reintentos && inputOk == FALSE; i++) {
        printf(mensaje);
        __fpurge(stdin);
        fgets(ingreso, maximo, stdin);
        ingreso[strlen(ingreso)-1]='\0';
        if(strlen(ingreso) > maximo) {
            printf(error);
        } else {
            inputOk = TRUE;
        }
    }
    if(inputOk) {
        strcpy(string.valor, ingreso);
    }
    superoIntentos(i, reintentos);
    return string;
}

/** \brief compara resultado y reintentos, si son iguales muestra mensaje de error
*
* \param resultado int
* \param reintentos int
*
*/
void superoIntentos(int resultado, int reintentos) {
    if(resultado == reintentos) {
        printf("Supero el maximo de intentos, reintente mas tarde\n");
    }
}