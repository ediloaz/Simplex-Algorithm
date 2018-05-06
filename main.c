#include "Latex.h"
#include "Tabla.h"
#include "Parameters.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    srand(time(NULL));                                          // Cambiamos la semilla de la función rand() cada vez que iniciamos el programa.
    TablaPrueba();
//    Latex();
    return (EXIT_SUCCESS);
}

