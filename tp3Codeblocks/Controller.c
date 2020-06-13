#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    if(path != NULL && pArrayListEmployee != NULL) {
        FILE * pFile;
        pFile = fopen(path, "r");
        if(pFile != NULL) {
            parser_EmployeeFromText(pFile, pArrayListEmployee);
            return 1;
        }
    }
    return 0;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    if(path != NULL && pArrayListEmployee != NULL) {
        FILE* pFile;
        pFile = fopen(path, "rb");
        if(pFile != NULL) {
            parser_EmployeeFromBinary(pFile, pArrayListEmployee);
            return 1;
        }
    }
    return 0;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    if(pArrayListEmployee != NULL) {
        int id;
        char nombre[128];
        int horasTrb;
        int sueldo;
        if(ll_isEmpty(pArrayListEmployee)) {
            id = 1;
        } else {
            int len = ll_len(pArrayListEmployee);
            Employee* aux = (Employee*) ll_get(pArrayListEmployee, len-1);
            employee_getId(aux, &id);
            id++;
        }
        ingresarString("Ingrese nombre del empleado: ", nombre);
        horasTrb = ingreseInt("Ingrese horas trabajadas del empleado: ", "Error al ingresar las horas, no puede ser menor a 0, ingrese de nuevo", 0);
        sueldo = ingreseInt("Ingrese sueldo del empleado: ", "Error al ingresar el sueldo, no puede ser menor a 0, ingrese de nuevo", 0);

        Employee* em = employee_new();
        employee_setId(em, id);
        employee_setNombre(em, nombre);
        employee_setHorasTrabajadas(em, horasTrb);
        employee_setSueldo(em, sueldo);

        ll_add(pArrayListEmployee, em);

        return 1;
    }
    return 0;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    if(pArrayListEmployee != NULL && !ll_isEmpty(pArrayListEmployee)) {
        printf("Modificar Empleado\n");
        controller_ListEmployee(pArrayListEmployee);
        Employee* emA = getEmployeePorId(pArrayListEmployee);
        if(emA != NULL) {
            if(deseaActualizar("Quiere actualizar el nombre s/n: ")) {
                char nombre[128];
                ingresarString("Ingrese nuevo nombre del empleado: ", nombre);
                employee_setNombre(emA, nombre);
            }

            if(deseaActualizar("Quiere actualizar las horas trabajadas s/n: ")) {
                int horasTrb;
                horasTrb = ingreseInt("Ingrese horas trabajadas: ", "Error al ingresar las horas, no puede ser menor a 0, ingrese de nuevo", 0);
                employee_setHorasTrabajadas(emA, horasTrb);
            }

            if(deseaActualizar("Quiere actualizar el sueldo s/n ")) {
                int sueldo;
                sueldo = ingreseInt("Ingrese sueldo: ", "Error al ingresar el sueldo, no puede ser menor a 0, ingrese de nuevo", 0);
                employee_setSueldo(emA, sueldo);
            }

            return 1;
        }
        printf("No se encontro un empleado con ese ID... \n");
    }
    return 0;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    if(pArrayListEmployee != NULL && !ll_isEmpty(pArrayListEmployee)) {
        printf("Eliminar Empleado\n");
        controller_ListEmployee(pArrayListEmployee);
        Employee* emA = getEmployeePorId(pArrayListEmployee);
        if(emA != NULL) {
            int index = ll_indexOf(pArrayListEmployee, emA);
            ll_remove(pArrayListEmployee, index);
            return 1;
        }
        printf("No se encontro un empleado con ese ID... \n");
    }
    return 0;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    if(pArrayListEmployee != NULL && !ll_isEmpty(pArrayListEmployee)) {
        int size = ll_len(pArrayListEmployee);
        int id, horasTrb, sueldo;
        char nombre[128];
        printf("%10s %20s %20s %10s\n", "id", "nombre", "hs/trabajadas", "sueldo");
        for(int i=0; i<size; i++) {
            Employee* aux = (Employee*) ll_get(pArrayListEmployee, i);
            employee_getId(aux, &id);
            employee_getNombre(aux, nombre);
            employee_getHorasTrabajadas(aux, &horasTrb);
            employee_getSueldo(aux, &sueldo);
            printf("%10d %20s %20d %10d\n", id, nombre, horasTrb, sueldo);
        }
        return 1;
    }
    return 0;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    if(pArrayListEmployee != NULL && !ll_isEmpty(pArrayListEmployee)) {
        ll_sort(pArrayListEmployee, employee_CompareByName, 1);
        return 1;
    }
    return 0;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    if(pArrayListEmployee != NULL && !ll_isEmpty(pArrayListEmployee)) {
        FILE* archivo;
        int i;
        archivo = fopen(path,"w");
        if(archivo!=NULL) {
            int len = ll_len(pArrayListEmployee);
            int id, horasTrb, sueldo;
            char nombre[128];
            fprintf(archivo,"Id,Nombre,Horas Trabajadas, Sueldo\n");
            for(i=0; i<len; i++) {
                Employee* aux = (Employee*) ll_get(pArrayListEmployee, i);
                employee_getId(aux, &id);
                employee_getNombre(aux, nombre);
                employee_getHorasTrabajadas(aux, &horasTrb);
                employee_getSueldo(aux, &sueldo);
                fprintf(archivo,"%d,%s,%d,%d\n", id, nombre, horasTrb, sueldo);
            }
            fclose(archivo);
            printf("Datos guardados\n");
            return 1;
        } else {
            printf("No se pudieron guardar los datos\n");
        }
    }
    return 0;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    if(pArrayListEmployee != NULL && !ll_isEmpty(pArrayListEmployee)) {
        FILE* archivo;
        archivo = fopen(path, "wb");
        if(archivo!=NULL) {
            int len = ll_len(pArrayListEmployee);
            char nombre[128];
            for(int i = 0; i<len; i++) {
                Employee* aux = (Employee*) ll_get(pArrayListEmployee, i);
                fwrite(aux, sizeof(Employee), 1, archivo);
            }
            printf("Datos guardados\n");
        }
        fclose(archivo);
        return 1;
    }
    return 0;
}

int obtenerId(char* mensaje) {
    int id;
    printf("%s", mensaje);
    scanf("%d", &id);
    return id;
}

int deseaActualizar(char* mensaje) {
    char opcion;
    printf("%s", mensaje);
    __fpurge(stdin);
    scanf("%c", &opcion);
    if(opcion == 's') {
        return 1;
    }
    return 0;
}

int ingresarString(char* mensaje, char* str) {
    if(mensaje != NULL && str != NULL) {
        char nombre[128];
        printf(mensaje);
        __fpurge(stdin);
        fgets(nombre, 128, stdin);
        nombre[strlen(nombre)-1]='\0';
        strcpy(str, nombre);
        return 1;
    }
    return 0;
}

int ingreseInt(char* mensaje, char* error, int minimo) {
    int valor;
    printf("%s", mensaje);
    scanf("%d", &valor);
    while(valor<minimo){
        printf("%s",error);
        scanf("%d",&valor);
    }
    return valor;
}

Employee* getEmployeePorId(LinkedList* pArrayListEmployee) {
    Employee* em;
    if(pArrayListEmployee != NULL) {
        int id = obtenerId("Ingrese id del empleado: ");
        int len = ll_len(pArrayListEmployee);
        for(int i = 0; i < len; i++) {
            int idAux;
            Employee* aux = (Employee*) ll_get(pArrayListEmployee, i);
            employee_getId(aux, &idAux);
            if(id == idAux) {
                em = aux;
            }
        }
    }
    return em;
}
