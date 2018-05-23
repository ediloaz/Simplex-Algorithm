#ifndef DATOSMATRICESDEPRUEBA_H
#define DATOSMATRICESDEPRUEBA_H


#include <stdbool.h>


void MatrizDePrueba1();
void MatrizDePrueba2();
void MatrizDePrueba3();
void MatrizDePrueba4();


void MatrizDePrueba5(){ //problema degenerado
    
    maximizar = true;
    tablas_intermedias = true;
        
    FilasMatriz = 5;
    ColumnasMatriz = 7;
    
    cantidad_variables = 2;
    cantidad_holguras = 3;
    cantidad_excesos =0;
    cantidad_artificiales = 0;
    
    flags_variables[0] = true;
    flags_variables[1] = true;
    flags_variables[2] = false;
    flags_variables[3] = false;
    flags_variables[4] = false;
    flags_variables[5] = false;
    flags_variables[6] = false;
    flags_variables[7] = false;
    
    flags_restricciones[0] = true;
    flags_restricciones[1] = true;
    flags_restricciones[2] = true;
    flags_restricciones[3] = false;
    flags_restricciones[4] = false;
    flags_restricciones[5] = false;
    flags_restricciones[6] = false;
    flags_restricciones[7] = false;
    flags_restricciones[8] = false;
    flags_restricciones[9] = false;
    
    strcpy(nombre_variables[0], "Carros");
    strcpy(nombre_variables[1], "Motos");
    strcpy(nombre_variables[2], "Bicis");
    strcpy(nombre_variables[3], "Gorriones");
    strcpy(nombre_variables[4], "Loros");
    strcpy(nombre_variables[5], "Procesos");
    strcpy(nombre_variables[6], "Hilos");
    strcpy(nombre_variables[7], "Comas");

    strcpy(nombre_programa, "Problema degenerado");
    
    //primer Fila, numeros de la funcion objetivos
    Matriz[0][0] = 1;
    Matriz[0][1] = -2;
    Matriz[0][2] = -1;
    Matriz[0][3] = 0;
    Matriz[0][4] = 0;
    Matriz[0][5] = 0;
    Matriz[0][6] = 0;
    
    //Segunda Fila, cocientes de M
    Matriz[1][0] = 0;
    Matriz[1][1] = 0;
    Matriz[1][2] = 0;
    Matriz[1][3] = 0;
    Matriz[1][4] = 0;
    Matriz[1][5] = 0;
    Matriz[1][6] = 0;
    
     //Segunda Fila, cocientes de M
    Matriz[2][0] = 0;
    Matriz[2][1] = 3;
    Matriz[2][2] = 1;
    Matriz[2][3] = 1;
    Matriz[2][4] = 0;
    Matriz[2][5] = 0;
    Matriz[2][6] = 6;
    
    

    //Tercer Fila, normal
    Matriz[3][0] = 0;
    Matriz[3][1] = 1;
    Matriz[3][2] = -1;
    Matriz[3][3] = 0;
    Matriz[3][4] = 1;
    Matriz[3][5] = 0;
    Matriz[3][6] = 2;
    //Cuarta Fila, normal
    Matriz[4][0] = 0;
    Matriz[4][1] = 0;
    Matriz[4][2] = 1;
    Matriz[4][3] = 0;
    Matriz[4][4] = 0;
    Matriz[4][5] = 1;
    Matriz[4][6] = 3;

   
}



void MatrizDePrueba4(){ //problema no factible
    
    maximizar = true;
    tablas_intermedias = true;
        
    FilasMatriz = 6;
    ColumnasMatriz = 10;
    
    cantidad_variables = 2;
    cantidad_holguras = 2;
    cantidad_excesos = 2;
    cantidad_artificiales = 2;
    
    flags_variables[0] = true;
    flags_variables[1] = true;
    flags_variables[2] = false;
    flags_variables[3] = false;
    flags_variables[4] = false;
    flags_variables[5] = false;
    flags_variables[6] = false;
    flags_variables[7] = false;
    
    flags_restricciones[0] = true;
    flags_restricciones[1] = true;
    flags_restricciones[2] = true;
    flags_restricciones[3] = true;
    flags_restricciones[4] = false;
    flags_restricciones[5] = false;
    flags_restricciones[6] = false;
    flags_restricciones[7] = false;
    flags_restricciones[8] = false;
    flags_restricciones[9] = false;
    
    strcpy(nombre_variables[0], "Carros deportivos");
    strcpy(nombre_variables[1], "Motoscicletas");
    strcpy(nombre_variables[2], "Abejones de mayo");
    strcpy(nombre_variables[3], "Gorriones");
    strcpy(nombre_variables[4], "Loros");
    strcpy(nombre_variables[5], "Procesos");
    strcpy(nombre_variables[6], "Hilos");
    strcpy(nombre_variables[7], "Comas");

    strcpy(nombre_programa, "Problema no factible");
    
    //primer Fila, numeros de la funcion objetivos
    Matriz[0][0] = 1;
    Matriz[0][1] = -300;
    Matriz[0][2] = -200;
    Matriz[0][3] = 0;
    Matriz[0][4] = 0;
    Matriz[0][5] = 0;
    Matriz[0][6] = 0;
    Matriz[0][7] = 0;
    Matriz[0][8] = 0;
    Matriz[0][9] = 0;
   
    //Segunda Fila, cocientes de M
    Matriz[1][0] = 0;
    Matriz[1][1] = 0;
    Matriz[1][2] = 0;
    Matriz[1][3] = 0;
    Matriz[1][4] = 0;
    Matriz[1][5] = 0;
    Matriz[1][6] = 0;
    Matriz[1][7] = 1;
    Matriz[1][8] = 1;
    Matriz[1][9] = 0;
   
    
    //Tercer Fila, normal
    Matriz[2][0] = 0;
    Matriz[2][1] = 0.025;
    Matriz[2][2] = 0.016666667;
    Matriz[2][3] = 1;
    Matriz[2][4] = 0;
    Matriz[2][5] = 0;
    Matriz[2][6] = 0;
    Matriz[2][7] = 0;
    Matriz[2][8] = 0;
    Matriz[2][9] = 1;
   
    //Cuarta Fila, normal
    Matriz[3][0] = 0;
    Matriz[3][1] = 0.02;
    Matriz[3][2] = 0.02;
    Matriz[3][3] = 0;
    Matriz[3][4] = 1;
    Matriz[3][5] = 0;
    Matriz[3][6] = 0;
    Matriz[3][7] = 0;
    Matriz[3][8] = 0;
    Matriz[3][9] = 1;
    //Cuarta Fila, normal
    Matriz[4][0] = 0;
    Matriz[4][1] = 1;
    Matriz[4][2] = 0;
    Matriz[4][3] = 0;
    Matriz[4][4] = 0;
    Matriz[4][5] = -1;
    Matriz[4][6] = 0;
    Matriz[4][7] = 1;
    Matriz[4][8] = 0;
    Matriz[4][9] = 30;
    
    //Cuarta Fila, normal
    Matriz[5][0] = 0;
    Matriz[5][1] = 0;
    Matriz[5][2] = 1;
    Matriz[5][3] = 0;
    Matriz[5][4] = 0;
    Matriz[5][5] = 0;
    Matriz[5][6] = -1;
    Matriz[5][7] = 0;
    Matriz[5][8] = 1;
    Matriz[5][9] = 20;
}




// Dakota Modificado (Para soluciones multiples)
void MatrizDePrueba3(){
    
    maximizar = true;
    tablas_intermedias = true;
    
    FilasMatriz         = 6;
    ColumnasMatriz      = 9;
    
    cantidad_variables  = 3;
    cantidad_holguras   = 4;
    cantidad_excesos    = 0;
    cantidad_artificiales = 0;
    
    flags_variables[0] = true;
    flags_variables[1] = true;
    flags_variables[2] = true;
    flags_variables[3] = false;
    flags_variables[4] = false;
    flags_variables[5] = false;
    flags_variables[6] = false;
    flags_variables[7] = false;
    
    flags_restricciones[0] = true;
    flags_restricciones[1] = true;
    flags_restricciones[2] = true;
    flags_restricciones[3] = true;
    flags_restricciones[4] = false;
    flags_restricciones[5] = false;
    flags_restricciones[6] = false;
    flags_restricciones[7] = false;
    flags_restricciones[8] = false;
    flags_restricciones[9] = false;
    
    strcpy(nombre_variables[0], "Mesas");
    strcpy(nombre_variables[1], "Sillas");
    strcpy(nombre_variables[2], "Escritorios");
    strcpy(nombre_variables[3], "Gorriones");
    strcpy(nombre_variables[4], "Loros");
    strcpy(nombre_variables[5], "Procesos");
    strcpy(nombre_variables[6], "Hilos");
    strcpy(nombre_variables[7], "Comas");

    strcpy(nombre_programa, "Dakota Modificado (Para soluciones multiples)");
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
    tablas_intermedias = true;
    
    FilasMatriz = 5;
    ColumnasMatriz = 8;
    
    maximizar = true;
    cantidad_variables = 2;
    cantidad_holguras = 2;
    cantidad_excesos =1;
    cantidad_artificiales = 1;
    
    flags_variables[0] = true;
    flags_variables[1] = true;
    flags_variables[2] = false;
    flags_variables[3] = false;
    flags_variables[4] = false;
    flags_variables[5] = false;
    flags_variables[6] = false;
    flags_variables[7] = false;
    
    flags_restricciones[0] = true;
    flags_restricciones[1] = true;
    flags_restricciones[2] = true;
    flags_restricciones[3] = false;
    flags_restricciones[4] = false;
    flags_restricciones[5] = false;
    flags_restricciones[6] = false;
    flags_restricciones[7] = false;
    flags_restricciones[8] = false;
    flags_restricciones[9] = false;
    
    strcpy(nombre_variables[0], "Carros");
    strcpy(nombre_variables[1], "Motos");
    strcpy(nombre_variables[2], "Abejones");
    strcpy(nombre_variables[3], "Gorriones");
    strcpy(nombre_variables[4], "Loros");
    strcpy(nombre_variables[5], "Procesos");
    strcpy(nombre_variables[6], "Hilos");
    strcpy(nombre_variables[7], "Comas");

    strcpy(nombre_programa, "Fábrica de La Agricultura (Con Ms)");
    
    
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
    tablas_intermedias = true;
    
    FilasMatriz = 5;
    ColumnasMatriz = 8;
          
    cantidad_variables = 2;
    cantidad_holguras = 1;
    cantidad_excesos =1;
    cantidad_artificiales = 2;
    
    symbols[0] = 0;
    symbols[1] = 2;
    symbols[2] = 1;
    symbols[3] = -1;
    symbols[4] = -1;
    
    flags_variables[0] = true;
    flags_variables[1] = true;
    flags_variables[2] = true;
    flags_variables[3] = false;
    flags_variables[4] = false;
    flags_variables[5] = false;
    flags_variables[6] = false;
    flags_variables[7] = false;
    
    flags_restricciones[0] = true;
    flags_restricciones[1] = true;
    flags_restricciones[2] = true;
    flags_restricciones[3] = true;
    flags_restricciones[4] = false;
    flags_restricciones[5] = false;
    flags_restricciones[6] = false;
    flags_restricciones[7] = false;
    flags_restricciones[8] = false;
    flags_restricciones[9] = false;
    
    strcpy(nombre_variables[0], "Carros deportivos");
    strcpy(nombre_variables[1], "Motoscicletas");
    strcpy(nombre_variables[2], "Abejones de mayo");
    strcpy(nombre_variables[3], "Gorriones");
    strcpy(nombre_variables[4], "Loros");
    strcpy(nombre_variables[5], "Procesos");
    strcpy(nombre_variables[6], "Hilos");
    strcpy(nombre_variables[7], "Comas");

    strcpy(nombre_programa, "Dakota Modificado (Para soluciones multiples)");
    
    
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




#endif /* DATOSMATRICESDEPRUEBA_H */

