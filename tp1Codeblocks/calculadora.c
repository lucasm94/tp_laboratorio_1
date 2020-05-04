#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"
#include "menuCalculadora.h"

/*
* \brief solicita el ingreso de un numero
* \param char[] mensaje a mostrar
* \return el valor ingresado
*
*/
int obtenerInt(char[]);

/*
* \brief Valida si se debe ejecutar los calculos
* \param int si ejecutoOperaciones
* \param int si se cargo el operando A
* \param int si se cargo el operando B
* \param int operando A
* \param int operando B
* \param int operando A en ultima ejecucion
* \param int operando B en ultima ejecucion
* \return el resultado de la validacion
*
*/
int validarEjecucionDeCalulos(int, int, int, int, int, int, int);

/*
* \brief Valida que se hayan ingresado los operandos
* \param int primer operando
* \param int segundo operando
* \return validacion de los operandos
*
*/
int ingresoValores(int, int);

/*
* \brief Valida si es la primera ejecucion o se intenta ejecutar los calculos con nuevos valores,
 * evita repetir el procedimiento
* \param int si ejecutoOperaciones
* \param int operando A
* \param int operando B
* \param int operando A utilizado en los ultimos calculos
* \param int operando A utilizado en los ultimos calculos
* \return validacion
*
*/
int primerosONuevosValores(int, int, int, int, int);

/*
* \brief Informa los resultados de las operaciones
* \param int operando A
* \param int operando B
* \param int resultado suma
* \param int resultado resta
* \param float resultado division
* \param int resultado producto
* \param int resultado factorial A
* \param int resultado factorial B
*
*/
void informarResultados(int, int, int, int, float, int, int, int);

/*
* \brief Informa resultado de la division
* \param int operando A
* \param int operando B
* \param float resultado division
*
*/
void informarDivision(int, int, float);

/*
* \brief Informa resultado de los factoriales
* \param int operando A
* \param int operando B
* \param int resultado factorial A
* \param int resultado factorial B
*
*/
void informarFactoriales(int, int, int, int);

int calculadora(void) {
    int opcion;
    int operandoA;
    int operandoB;
    int operandoAUtilizado;
    int operandoBUtilizado;
    int resultadoSuma;
    int resultadoResta;
    int resultadoMultiplicacion;
    float resultadoDivision;
    int factorialA;
    int factorialB;
    //flags
    int operandoAIngresado = 0;
    int operandoBIngresado = 0;
    int ejecutoCalculos = 0;


    do {
        opcion = menu();
        switch(opcion)
        {
            case 1:
                operandoA = obtenerInt("Ingrese el primer operando (A): ");
                operandoAIngresado = 1;
                break;
            case 2:
                operandoB = obtenerInt("Ingrese el segundo operando (B): ");
                operandoBIngresado = 1;
                break;
            case 3:

                if(validarEjecucionDeCalulos(ejecutoCalculos, operandoAIngresado, operandoBIngresado,
                                             operandoA, operandoB, operandoAUtilizado, operandoBUtilizado)) {
                    printf("Calculando todas las operaciones\n");
                    operandoAUtilizado = operandoA;
                    operandoBUtilizado = operandoB;
                    resultadoSuma = suma(operandoA, operandoB);
                    resultadoResta = resta(operandoA, operandoB);
                    resultadoDivision = division(operandoA, operandoB);
                    resultadoMultiplicacion = multiplicacion(operandoA, operandoB);
                    factorialA = factorial(operandoA);
                    factorialB = factorial(operandoB);
                    ejecutoCalculos = 1;
                }

                break;
            case 4:

                if(ejecutoCalculos) {
                    printf("Resultados con los valores %d y %d que se calcularon las operaciones: \n",
                           operandoAUtilizado, operandoBUtilizado);
                    informarResultados(operandoAUtilizado, operandoBUtilizado, resultadoSuma, resultadoResta,
                                       resultadoDivision, resultadoMultiplicacion, factorialA, factorialB);
                    if(operandoA != operandoAUtilizado || operandoB != operandoBUtilizado) {
                        printf("Para ver los resultados con los nuevos valores debe Calcular todas las operaciones\n");
                    }
                } else {
                    printf("Tiene que Calcular todas las operaciones primero\n");
                }

                break;
        }
        if(opcion != 5) {
            system("read -p 'Presionar enter para continuar...' var");
        }

        system("clear");
    }while(opcion!=5);
    return 0;
}

int validarEjecucionDeCalulos(int ejecutoCalculos, int ingresoA, int ingresoB,
                              int operandoA, int operandoB, int operandoAUtilizado, int operandoBUtilizado) {

    if(ingresoValores(ingresoA, ingresoB) && (!ejecutoCalculos ||
       primerosONuevosValores(ejecutoCalculos, operandoA, operandoB, operandoAUtilizado, operandoBUtilizado))) {
        return 1;
    }
    return 0;
}

int ingresoValores(int ingresoA, int ingresoB) {
    if(ingresoA && ingresoB) {
        return 1;
    }
    if(!ingresoA && !ingresoB){
        printf("Tiene que ingresar los dos valores\n");
    } else if(!ingresoB) {
        printf("Tiene que ingresar el segundo valor\n");
    } else {
        printf("Tiene que ingresar el primer valor\n");
    }
    return 0;
}

int primerosONuevosValores(int ejecuto, int operandoA, int operandoB, int utilizadoA, int utilizadoB) {
    if(operandoA != utilizadoA || operandoB != utilizadoB) {
        return 1;
    }
    return 0;
}

int obtenerInt(char mensaje[]){
    int valor;
    printf("%s", mensaje);
    scanf("%d", &valor);
    return valor;
}

void informarResultados(int operandoA, int operandoB, int suma, int resta, float division, int producto,
                        int factorialA, int factorialB){
    printf("a) El resultado de %d + %d es: %d", operandoA, operandoB, suma);
    printf("\nb) El resultado de %d - %d es: %d", operandoA, operandoB, resta);
    informarDivision(operandoA, operandoB, division);
    printf("\nd) El resultado de %d*%d es: %d", operandoA, operandoB, producto);
    informarFactoriales(operandoA, operandoB, factorialA, factorialB);
}

void informarDivision(int operandoA, int operandoB, float division) {
    if(division == 0) {
        printf("\nc) No es posible dividir por cero");
    } else {
        printf("\nc) El resultado de %d/%d es: %f", operandoA, operandoB, division);
    }
}

void informarFactoriales(int operandoA, int operandoB, int factorialA, int factorialB) {
    printf("\ne) ");
    if(factorialA == 0) {
        printf("No se puedo calcular el factorial de %d por ser menor a 1", operandoA);
    } else {
        printf("El factorial de %d es: %d", operandoA, factorialA);
    }
    printf(" y ");
    if(factorialB == 0) {
        printf("No se puedo calcular el factorial de %d por ser menor a 1\n", operandoB);
    } else {
        printf("El factorial de %d es: %d\n", operandoB, factorialB);
    }
}
