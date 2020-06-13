#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    if(pFile != NULL && pArrayListEmployee != NULL) {
        char id[30], nombre[128], horasTbr[30], sueldo[30];
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTbr, sueldo);
        while(!feof(pFile)) {
            if(feof(pFile)) {
                break;
            }
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTbr, sueldo);
            Employee* employee = employee_newParametros(id, nombre, horasTbr, sueldo);
            ll_add(pArrayListEmployee, employee);
        }
        fclose(pFile);
        return 1;
    }
    return 0;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    if(pFile != NULL && pArrayListEmployee != NULL) {
        while(!feof(pFile)) {
            if(feof(pFile)) {
                break;
            }
            Employee* employee = employee_new();
            if(fread(employee, sizeof(Employee), 1, pFile)==1){
                ll_add(pArrayListEmployee, employee);
            }
        }
        fclose(pFile);
        return 1;
    }
    return 0;
}
