int suma(int intA, int intB) {
    return intA+intB;
}

int resta(int intA, int intB){
    return intA-intB;
}

float division(int intA, int intB){
    if(intB == 0) {
        return 0;
    }
    return (float) intA/intB;
}

int multiplicacion(int intA, int intB){
    return intA*intB;
}

int factorial(int intA){
    if(intA < 1) {
        return 0;
    }
    int factorial = 1;
    for(int i = 1; i <= intA; i++){
        factorial = factorial * i;
    }
    return factorial;
}
