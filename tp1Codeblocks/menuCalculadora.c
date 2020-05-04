#include <stdio.h>

int menu(void) {
    int opcion;
    printf("Seleccionar una opción\n");
    printf("1. Ingresar operando A\n");
    printf("2. Ingresar operando B\n");
    printf("3. Calcular todas las operaciones\n");
    printf("\ta) Calcular la suma (A+B)\n");
    printf("\tb) Calcular la resta (A-B)\n");
    printf("\tc) Calcular la division (A/B)\n");
    printf("\td) Calcular la multiplicacion (A*B)\n");
    printf("\te) Calcular el factorial\n");
    printf("4. Informar resultados\n");
    printf("5. Salir\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}
