#include "ArrayEmployees.h"

/** \brief Busca indixe del array libre
*
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int index, si no encuentra lugar libre -1
*
*/
int buscarLibre(eEmployee* list, int length) {
    int i = 0;
    while(i < length && list[i].isEmpty == FALSE) {
        i++;
    }
    if(i < length) {
        return i;
    }
    return -1;
}

/** \brief To indicate that all position in the array are empty,
*
this function put the flag (isEmpty) in TRUE in all
*
position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(eEmployee* list, int len) {
    if(len < 1) {
        return -1;
    }
    for(int i = 0; i < len; i++) {
        list[i].isEmpty = TRUE;
        list[i].id = -1;
    }
    return 0;
}

/** \brief add in a existing list of employees the values received as parameters
*
in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int addEmployee(eEmployee* list, int len, int id, char name[], char lastName[], float salary, int sector) {
    int i = buscarLibre(list, len);
    if(i != -1) {
        list[i].id = id;
        strcpy(list[i].name, name);
        strcpy(list[i].lastName, lastName);
        list[i].salary = salary;
        list[i].sector = sector;
        list[i].isEmpty = FALSE;
        return 0;
    }
    return -1;
}

/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(eEmployee* list, int len,int id) {
    if(len > 0) {
        int i = 0;
        while(i<len && list[i].id != id) {
            i++;
        }
        if(i < len && list[i].isEmpty == FALSE) {
            return i;
        }
    }
    return -1;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(eEmployee* list, int len, int id) {
    int i = findEmployeeById(list,len,id);
    if(i != -1) {
        list[i].isEmpty = TRUE;
        return 0;
    }
    return -1;
}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(eEmployee* list, int len, int order) {
    if(order == UP) {
        return sortEmployeesUp(list, len);
    } else {
        return sortEmployeesDown(list, len);
    }
}

/** \brief Ordena los elementos del array por apellido y sector de manera ascendente
*
* \param list Employee*
* \param len int
* \return int Return (-1) si len es incorrecto - (0) si Ok
*
*/
int sortEmployeesUp(eEmployee* list, int len) {
    if(len > 0) {
        int i;
        int j;
        eEmployee employeeAux;
        for(i=0; i<len-1; i++) {
            for(j=i+1; j<len; j++) {
                if(strcmp(list[i].lastName, list[j].lastName)>0) {
                    employeeAux  =  list[i];
                    list[i] = list[j];
                    list[j] = employeeAux;
                } else if(strcmp(list[i].lastName,list[j].lastName)==0 && list[i].sector>list[j].sector) {
                    employeeAux  =  list[i];
                    list[i] = list[j];
                    list[j] = employeeAux;
                }
            }
        }
        return 0;
    }
    return -1;
}

/** \brief Ordena los elementos del array por apellido y sector de manera desascendente
*
* \param list Employee*
* \param len int
* \return int Return (-1) si len es incorrecto - (0) si Ok
*
*/
int sortEmployeesDown(eEmployee* list, int len) {
    if(len > 0) {
        int i;
        int j;
        eEmployee employeeAux;
        for(i=0; i<len-1; i++) {
            for(j=i+1; j<len; j++) {
                if(strcmp(list[i].lastName, list[j].lastName)<0) {
                    employeeAux  =  list[i];
                    list[i] = list[j];
                    list[j] = employeeAux;
                } else if(strcmp(list[i].lastName,list[j].lastName)==0 && list[i].sector<list[j].sector) {
                    employeeAux  =  list[i];
                    list[i] = list[j];
                    list[j] = employeeAux;
                }
            }
        }
        return 0;
    }
    return -1;
}

/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees(eEmployee* list, int length) {
    if(length > 0) {
        printf("%6s %26s %26s %30s %20s\n", "id", "Nombre", "Apellido", "Salario", "Sector");
        for(int i = 0; i < length; i++) {
            if(!list[i].isEmpty) {
                printf("%6d %26s %26s %32f %16d\n", list[i].id, list[i].name, list[i].lastName, list[i].salary,
                       list[i].sector);
            }
        }
        return 0;
    }
    return -1;
}

/** \brief actualiza el nombre o el apellido del empleado con el id ingresado, el parametro atributo indica
 * que se va a actualizar
*
* \param list Employee*
* \param length int
* \param id int
* \param valor char[51]
* \return -1 si no existe empleado con el id ingresado, 0 si ok
*
*/
int actualizarNombreOApellido(eEmployee* list, int length, int id, char valor[51], int atributo) {
    int i = findEmployeeById(list, length, id);
    if(i != -1) {
        if(atributo == NAME) {
            strcpy(list[i].name, valor);
        } else {
            strcpy(list[i].lastName, valor);
        }
        return 0;
    }
    return -1;
}

/** \brief actualiza el sector del empleado con el id ingresado
*
* \param list Employee*
* \param length int
* \param id int
* \param sector int
* \return -1 si no existe empleado con el id ingresado, 0 si ok
*
*/
int actualizarSector(eEmployee* list, int length, int id, int sector) {
    int i = findEmployeeById(list, length, id);
    if(i != -1) {
        list[i].sector = sector;
        return 0;
    }
    return -1;
}

/** \brief actualiza el salario del empleado con el id ingresado
*
* \param list Employee*
* \param length int
* \param id int
* \param salario int
* \return -1 si no existe empleado con el id ingresado, 0 si ok
*
*/
int actualizarSalario(eEmployee* list, int length, int id, float salario) {
    int i = findEmployeeById(list, length, id);
    if(i != -1) {
        list[i].salary = salario;
        return 0;
    }
    return -1;
}

/** \brief crea id autoincremental para un empleado
*
* \param list Employee*
* \param length int
* \return 0 como primer id
*
*/
int createId(eEmployee* list, int len) {
    int maximo = -1;
    for(int i = 0; i<len; i++) {
        if(list[i].id > maximo) {
            maximo = list[i].id;
        }
    }
    if(maximo == -1) {
        return 0;
    } else {
        return maximo+1;
    }
}

/** \brief muestra Total y promedio de los salarios, y cuántos empleados superan el salario promedio
 *
* \param list Employee*
* \param length int
* \return -1 si hay error, 0 si ok
*
*/
int mostrarInfoSalarios(eEmployee* list, int length) {
    if(length > 0) {
        printf("Informe sobre el total y el promedio de los salarios, cuantos empleados superan el salario promedio\n");
        printf("%24s %24s %26s \n", "salario total", "salario promedio", "superan promedio");
        int total = sumaSalarios(list, length);
        float promedio = promedioSalarios(list, length, total);
        int cantidad = cantidadSalariosMayorAlPromedio(list, length, promedio);
        printf("%24d %24f %20d \n", total, promedio, cantidad);
        return 0;
    }
    return -1;
}

/** \brief suma todos los salarios de los empleados activos
 *
* \param list Employee*
* \param length int
* \return 0 length incorrecto o si no hay salarios, total si existen salarios
*
*/
int sumaSalarios(eEmployee* list, int length) {
    if(length < 1) {
        return 0;
    }
    int total = 0;
    for (int i = 0; i < length; ++i) {
        if(list[i].isEmpty == FALSE) {
            total = total + list[i].salary;
        }
    }
    return total;
}

/** \brief cuántos empleados superan el salario promedio
 *
* \param list Employee*
* \param length int
* \param promedio float
* \return 0 length incorrecto o si no hay salarios, total si superan al promedio
*
*/
int cantidadSalariosMayorAlPromedio(eEmployee* list, int length, float promedio) {
    if(length < 1) {
        return 0;
    }
    int total = 0;
    for (int i = 0; i < length; ++i) {
        if(list[i].isEmpty == FALSE && list[i].salary > promedio) {
            total++;
        }
    }
    return total;
}

/** \brief promedio de los salarios
 *
* \param list Employee*
* \param length int
* \param totalSalario int
* \return 0 length incorrecto o si no hay salarios, promedio si existen salarios
*
*/
float promedioSalarios(eEmployee* list, int length, int total) {
    if(length < 1) {
        return 0;
    }
    int lenActivos = 0;
    for (int i = 0; i < length; ++i) {
        if(list[i].isEmpty == FALSE) {
            lenActivos++;
        }
    }
    return (float) total / lenActivos;
}
