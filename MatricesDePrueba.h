#ifndef MATRICESDEPRUEBA_H
#define MATRICESDEPRUEBA_H

#include "AlgoritmoSimplex.h"

// Fábrica de Refrescos BebiCo
void MatrizDePrueba1(){
    //primer Fila, numeros de la funcion objetivos
    Matriz[0][0] = 1;
    Matriz[0][1] = -2;
    Matriz[0][2] = -3;
    Matriz[0][3] = 0;
    Matriz[0][4] = 0;
    Matriz[0][5] = 0;
    Matriz[0][6] = 0;
    Matriz[0][7] = 0;
    //Segunda Fila, cocientes de M
    Matriz[1][0] = 0;
    Matriz[1][1] = 0;
    Matriz[1][2] = 0;
    Matriz[1][3] = 0;
    Matriz[1][4] = 0;
    Matriz[1][5] = -1;
    Matriz[1][6] = -1;
    Matriz[1][7] = 0;
    //Tercer Fila, normal
    Matriz[2][0] = 0;
    Matriz[2][1] = 0.5;
    Matriz[2][2] = 0.25;
    Matriz[2][3] = 1;
    Matriz[2][4] = 0;
    Matriz[2][5] = 0;
    Matriz[2][6] = 0;
    Matriz[2][7] = 4;
    //Cuarta Fila, normal
    Matriz[3][0] = 0;
    Matriz[3][1] = 1;
    Matriz[3][2] = 3;
    Matriz[3][3] = 0;
    Matriz[3][4] = -1;
    Matriz[3][5] = 1;
    Matriz[3][6] = 0;
    Matriz[3][7] = 20;
    //Cuarta Fila, normal
    Matriz[4][0] = 0;
    Matriz[4][1] = 1;
    Matriz[4][2] = 1;
    Matriz[4][3] = 0;
    Matriz[4][4] = 0;
    Matriz[4][5] = 0;
    Matriz[4][6] = 1;
    Matriz[4][7] = 10;
}



// Fábrica de La Agricultura
void MatrizDePrueba2(){
    //primer Fila, numeros de la funcion objetivos
    Matriz[0][0] = 1;
    Matriz[0][1] = -10000;
    Matriz[0][2] = -3000;
    Matriz[0][3] = 0;
    Matriz[0][4] = 0;
    Matriz[0][5] = 0;
    Matriz[0][6] = 0;
    Matriz[0][7] = 0;
    //Segunda Fila, cocientes de M
    Matriz[1][0] = 0;
    Matriz[1][1] = 0;
    Matriz[1][2] = 0;
    Matriz[1][3] = 0;
    Matriz[1][4] = 0;
    Matriz[1][5] = 0;
    Matriz[1][6] = 1;
    Matriz[1][7] = 0;
    //Tercer Fila, normal
    Matriz[2][0] = 0;
    Matriz[2][1] = 1;
    Matriz[2][2] = 1;
    Matriz[2][3] = 1;
    Matriz[2][4] = 0;
    Matriz[2][5] = 0;
    Matriz[2][6] = 0;
    Matriz[2][7] = 7;
    //Cuarta Fila, normal
    Matriz[3][0] = 0;
    Matriz[3][1] = 10;
    Matriz[3][2] = 4;
    Matriz[3][3] = 0;
    Matriz[3][4] = 1;
    Matriz[3][5] = 0;
    Matriz[3][6] = 0;
    Matriz[3][7] = 40;
    //Cuarta Fila, normal
    Matriz[4][0] = 0;
    Matriz[4][1] = 0;
    Matriz[4][2] = 1;
    Matriz[4][3] = 0;
    Matriz[4][4] = 0;
    Matriz[4][5] = -1;
    Matriz[4][6] = 1;
    Matriz[4][7] = 3;
}



#endif /* MATRICESDEPRUEBA_H */

