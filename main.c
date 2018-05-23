#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include "Latex.h"
#include "Matriz.h"
//#include "Interfaz.h"         // DESCOMENTAR PARA LA INTERFAZ
#include "AlgoritmoSimplex.h"

#define PRINT(x) (printf("%s", x))
#define LENGHT(x) (sizeof(x) / sizeof((x)[0]))

struct timeval st, et;


// DESCOMENTAR PARA LA INTERFAZ
// main.c 8 (//#include "Interfaz.h")
// main.c 32 (//    IniciarInterfaz(argc, argv))
// Matriz.h 6 (//#include "Interfaz.h")
// Matriz.h 293 (Toda la función del ParserVariables())
// AlgoritmoSimplex.h 289 (CreateMatriz());


// gcc -o interface main.c -Wall `pkg-config --cflags --libs gtk+-3.0` -export-dynamic

int main(int argc, char** argv) {
    srand(time(NULL));                                          // Cambiamos la semilla de la función rand() cada vez que iniciamos el programa.
    PRINT("Inicio \n\n");
     IniciarLatex();

//    IniciarInterfaz(argc, argv);
    
    AlgoritmoSimplex();
    
//     gtk_window_close(window);
     TerminarLatex();
    printf("\n\nFinal \n\n");
    return (EXIT_SUCCESS);
}