#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include "Latex.h"
//#include "Interfaz.h"
#include "Tabla.h"
#include "AlgoritmoSimplex.h"

#define PRINT(x) (printf("%s", x))
#define LENGHT(x) (sizeof(x) / sizeof((x)[0]))

struct timeval st, et;


int main(int argc, char** argv) {
    srand(time(NULL));                                          // Cambiamos la semilla de la función rand() cada vez que iniciamos el programa.
    printf("Inicio \n\n");

    // IniciarInterfaz(argc, argv);
    
    AlgoritmoSimplex();
    
    // Latex();
    
    printf("\n\nFinal \n\n");
    return (EXIT_SUCCESS);
}