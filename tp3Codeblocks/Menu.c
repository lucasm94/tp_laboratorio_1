int opcionMenu(void) {
    int opcion;
    printf("--- Menu ---\n");
    printf("1. Cargar datos de los empleados desde archivo csv (modo texto)\n");
    printf("2. Cargar datos de los empleados desde archivo binario (modo binario)\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar datos de los empleados en archivo csv (modo texto)\n");
    printf("9. Guardar datos de los empleados en archivo bin (modo binario)\n");
    printf("10. Salir\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}
