#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include "Latex.h"
//#include "Matriz.h"
#include "Interfaz.h"
//#include "Tabla.h"
#include "AlgoritmoSimplex.h"

#define PRINT(x) (printf("%s", x))
#define LENGHT(x) (sizeof(x) / sizeof((x)[0]))

struct timeval st, et;


int main(int argc, char** argv) {
    srand(time(NULL));                                          // Cambiamos la semilla de la función rand() cada vez que iniciamos el programa.
    PRINT("Inicio \n\n");
//     IniciarLatex();

    IniciarInterfaz(argc, argv);
    
    AlgoritmoSimplex();
    
//     gtk_window_close(window);
//     TerminarLatex();
    printf("\n\nFinal \n\n");
    return (EXIT_SUCCESS);
}