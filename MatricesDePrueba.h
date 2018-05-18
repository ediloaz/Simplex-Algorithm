#ifndef MATRICESDEPRUEBA_H
#define MATRICESDEPRUEBA_H

//#include "AlgoritmoSimplex.h"
#include <stdbool.h>



// Variables globales
// Variables de holgura, de exceso y artificiales
int cantidad_variables;
int cantidad_holguras;
int cantidad_excesos;
int cantidad_artificiales;

 char nombre_variables[8][40];

// Información de la matriz
int FilasMatriz = 6;
int ColumnasMatriz = 9;
//float Matriz[5][8];
float Matriz[6][9];
// Otros datos
//int i,j;
int NumeroFinalizar = 0;
int numero_tabla_intermedia = 1;

bool maximizar;                 // si es 1 es maximizar o si es -1 es minimizar
bool tablas_intermedias = true;

bool casos_especiales[4];       // Banderas para los casos especiales
                                // Orden: [0] No acotado
                                //        [1] No factible
                                //        [2] Degenerado
                                //        [3] Múltiples soluciones

void MatrizDePrueba1();
void MatrizDePrueba2();
void MatrizDePrueba3();

int getColumnasMatriz(){
    return ColumnasMatriz;
}

int getFilasMatriz(){
    return FilasMatriz;
}




// Dakota Modificado (Para soluciones multiples)
void MatrizDePrueba3(){
    maximizar = true;
    cantidad_variables = 3;
    cantidad_holguras = 4;
    cantidad_excesos = 0;
    cantidad_artificiales = 0;
    FilasMatriz = 6;
    ColumnasMatriz = 9;
    
     strcpy(nombre_variables[0], "Carros");
    strcpy(nombre_variables[1], "Motos");
    strcpy(nombre_variables[2], "Abejones");
    strcpy(nombre_variables[3], "Gorriones");
    strcpy(nombre_variables[4], "Loros");
    strcpy(nombre_variables[5], "Procesos");
    strcpy(nombre_variables[6], "Hilos");
    strcpy(nombre_variables[7], "Comas");

    //primer Fila, numeros de la funcion objetivos
    Matriz[0][0] = 1;
    Matriz[0][1] = -60;
    Matriz[0][2] = -35;
    Matriz[0][3] = -20;
    Matriz[0][4] = 0;
    Matriz[0][5] = 0;
    Matriz[0][6] = 0;
    Matriz[0][7] = 0;
    Matriz[0][8] = 0;
    //Segunda Fila, cocientes de M
        Matriz[1][0] = 0;
    Matriz[1][1] = 0;
    Matriz[1][2] = 0;
    Matriz[1][3] = 0;
    Matriz[1][4] = 0;
    Matriz[1][5] = 0;
    Matriz[1][6] = 0;
    Matriz[1][7] = 0;
    Matriz[1][8] = 0;
    //Tercer Fila, normal
    Matriz[2][0] = 0;
    Matriz[2][1] = 8;
    Matriz[2][2] = 6;
    Matriz[2][3] = 1;
    Matriz[2][4] = 1;
    Matriz[2][5] = 0;
    Matriz[2][6] = 0;
    Matriz[2][7] = 0;
    Matriz[2][8] = 48;
    //Tercer Fila, normal
    Matriz[3][0] = 0;
    Matriz[3][1] = 4;
    Matriz[3][2] = 2;
    Matriz[3][3] = 1.5;
    Matriz[3][4] = 0;
    Matriz[3][5] = 1;
    Matriz[3][6] = 0;
    Matriz[3][7] = 0;
    Matriz[3][8] = 20;
    //Cuarta Fila, normal
    Matriz[4][0] = 0;
    Matriz[4][1] = 2;
    Matriz[4][2] = 1.5;
    Matriz[4][3] = 0.5;
    Matriz[4][4] = 0;
    Matriz[4][5] = 0;
    Matriz[4][6] = 1;
    Matriz[4][7] = 0;
    Matriz[4][8] = 8;
    //Cuarta Fila, normal
    Matriz[5][0] = 0;
    Matriz[5][1] = 0;
    Matriz[5][2] = 1;
    Matriz[5][3] = 0;
    Matriz[5][4] = 0;
    Matriz[5][5] = 0;
    Matriz[5][6] = 0;
    Matriz[5][7] = 1;
    Matriz[5][8] = 5;
}


// Fábrica de La Agricultura (Tiene Ms)
void MatrizDePrueba2(){
    maximizar = true;
    cantidad_variables = 2;
    cantidad_holguras = 2;
    cantidad_excesos =1;
    cantidad_artificiales = 1;
    FilasMatriz = 5;
    ColumnasMatriz = 8;

         strcpy(nombre_variables[0], "Carros");
    strcpy(nombre_variables[1], "Motos");
    strcpy(nombre_variables[2], "Abejones");
    strcpy(nombre_variables[3], "Gorriones");
    strcpy(nombre_variables[4], "Loros");
    strcpy(nombre_variables[5], "Procesos");
    strcpy(nombre_variables[6], "Hilos");
    strcpy(nombre_variables[7], "Comas");
    
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


// Fábrica de Refrescos BebiCo (Tiene Ms)
void MatrizDePrueba1(){
    maximizar = false;
    cantidad_variables = 2;
    cantidad_holguras = 1;
    cantidad_excesos =1;
    cantidad_artificiales = 2;
    FilasMatriz = 5;
    ColumnasMatriz = 8;
    
         strcpy(nombre_variables[0], "Carros");
    strcpy(nombre_variables[1], "Motos");
    strcpy(nombre_variables[2], "Abejones");
    strcpy(nombre_variables[3], "Gorriones");
    strcpy(nombre_variables[4], "Loros");
    strcpy(nombre_variables[5], "Procesos");
    strcpy(nombre_variables[6], "Hilos");
    strcpy(nombre_variables[7], "Comas");
    
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



#endif /* MATRICESDEPRUEBA_H */

