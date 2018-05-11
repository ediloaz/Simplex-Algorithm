#ifndef ALGORITMOSIMPLEX_H
#define ALGORITMOSIMPLEX_H

#include <stdio.h>
#include <stdbool.h>



// Variables globales
// Variables de holgura, de exceso y artificiales
int cantidad_variables = 2;
int cantidad_holguras = 1;
int cantidad_excesos =1;
int cantidad_artificiales = 2;
// Información de la matriz
const int FilasMatriz = 5;
const int ColumnasMatriz = 8;
float Matriz[5][8];
// Otros datos
int i,j;
int NumeroFinalizar = 0;
int numero_tabla_intermedia = 1;
bool maximizar = true;     // si es 1 es maximizar o si es -1 es minimizar


void PrintMatriz(){ /* Función donde se ejecuta la lógica del programa */
    printf("Z \t x1 \t x2 \t s1 \t e1 \t a1 \t a2 \t X\n");
    for (i=0;i<FilasMatriz;i++)
    {
       for(j=0;j<ColumnasMatriz;j++)
        {
        printf("%.1f \t",Matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void PrintTablaInicial(){
    printf("Tabla inicial:\n");
    PrintMatriz();
}

void PrintTablaFinal(){
    printf("Tabla final:\n");
    PrintMatriz();
}


void PrintTablaIntermedia(){
    printf("Tabla intermedia #%d:\n",numero_tabla_intermedia);
    PrintMatriz();
    numero_tabla_intermedia ++;
}


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

bool ExistenMs(){
    for (int j = 0 ; j < ColumnasMatriz ; j++){
        if(Matriz[1][j] != 0){
            return true;
        }
    }
    return false;
}

void CanonizarMs(int posicion_artificiales){
    int a, b, c; 
    for(  a = posicion_artificiales ; a < posicion_artificiales + cantidad_artificiales; a = a + 1 ){//este ciclo va a recorrer todas las artificiales
      for(  b = 2 ; b < ColumnasMatriz; b = b + 1 ){//este ciclo va a recorrer todas las artificiales
            if ( Matriz[b][a] == 1){//si da igual a uno, aqui es donde se encuentra el 1 de la M que estamos canonizando
              //printf("%d\n", b );
              for(  c = 0 ; c < ColumnasMatriz; c = c + 1 ){//este ciclo va a recorrer todas las artificiales
                    Matriz[1][c] = Matriz[1][c] + Matriz[b][c];
            }
         }
       }

    }
    PrintTablaIntermedia();
}

int GetPosicionArtificiales(){
    return 1 + cantidad_variables + cantidad_holguras + cantidad_excesos;
}



bool ExisteColumnaCandidata(){
    if(ExistenMs()){
        return true;
    }else{
        for(int j = 1 ; j < ColumnasMatriz ; j++){
            if (maximizar && Matriz[0][j]<0){
                return true;
            }else if(!maximizar && Matriz[0][j]>0){
                return true;
            }
        }
    }
    return false;
}

//bool ExistenMs(int posicion_artificiales){
//    for(int j = 1 ; j < posicion_artificiales; j++ ){//este ciclo va a recorrer todas las variables normales, de holgura y exceso
//        if (Matriz[1][j] > 0){            //si alguna de la fila de las M es mayor a 0, entonces se agarra esa columna
//            return true;
//        }
//    }
//}


int ColumnaCandidata(){            // i={0,1}
    float numero_candidato  = 0;
    int columna_candidata = -1;
    if(ExistenMs()){                    // Si existen todavía Ms, debe sacarlos
        int i = 1;
        for (int j=1 ; j< ColumnasMatriz-1 ; j++){
            if (Matriz[i][j] > 0){       // Es negativo
                numero_candidato  = Matriz[i][j];
                columna_candidata = j;
                
            }
        }
    }else{                              // Ya no existen Ms
        int i = 0;
        if (maximizar){
            for (int j=1 ; j< ColumnasMatriz-1 ; j++){
                if (Matriz[i][j] < numero_candidato){       // Es negativo
                    numero_candidato  = Matriz[i][j];
                    columna_candidata = j;
                }
            }
        }else{
            for (int j=1 ; j< ColumnasMatriz-1 ; j++){
                if (Matriz[i][j] > numero_candidato){       // Es positivo
                    numero_candidato  = Matriz[i][j];
                    columna_candidata = j;
                }
            }
        }
        
    }
    printf("Columna candidata: %d (%.1f)\n",columna_candidata, numero_candidato);
    return columna_candidata;   
}


int EncontrarPivote(int j){
    int division_menor = 9999;
    int division_actual;
    int pivote = -1;
    for(int i = 2 ; i < FilasMatriz ; i++ ){  //este ciclo va a recorrer todas las filas para encontrar la division menor
        if (Matriz[i][j] >= 1 ){                //si es mayor o igual a uno, es un pivote candidatos
            division_actual = Matriz[i][ColumnasMatriz]/Matriz[i][j] ;
            if (division_actual < division_menor){
                division_menor = division_actual;
                pivote = i;
            }
        }
    }
}

void DividirFila(int i, float divisor){
//    for(int j = 1 ; j < ColumnasMatriz; j++){
//        Matriz[i][j] = Matriz [i][j]/divisor;
//    }
}

// Devuelve el número por el que se debe dividir la fila
// Coger el pivote, osea 1. Multiplicarlo por Fx. Restar Fx -el resultado
// 
float EncontrarDivisor(int i, float divisor){
    // Esto fue una prueba, no está bien pensado... 
}

void CanonizarColumna(int i_pivote, int j){
//    float divisor;
//    for(int i = 2 ; i < FilasMatriz ; i++){
//        if (i != i_pivote){         // Deja en 0 el que no es pivote
//            divisor = EncontrarDivisor(i, Matriz[i][j]);
//        }else{                      // deja en 1 el pivote
//            divisor = (float)pivote;
//        }
//        DividirFila(i, divisor);
//    }
}

void AlgoritmoSimplex(){
    //Llenamos la matriz
    MatrizDePrueba1();
    
    PrintTablaInicial();
       
    int posicion_artificiales = GetPosicionArtificiales();
    
    // Canonizar Ms
    if (ExistenMs()) CanonizarMs(posicion_artificiales);

    // Se realiza el simplex normal
    // Mientras exista una columna candidata hace el simplex
    // Candidata: Si está maximizando y es negativa, ó, si está minimizando y es positiva.
    while (ExisteColumnaCandidata()){
        PrintTablaIntermedia();
        // Se busca la columna
        int j = ColumnaCandidata();
        if (j==-1) break;                   // terminó
        // Se busca el pivote (dentro de la columna)
        int i = EncontrarPivote(j); 
        if (i==-1) break;                   // Solución no factible
        // Guarda el valor del pivote
        CanonizarColumna(i, j);
    }
     
}

#endif /* ALGORITMOSIMPLEX_H */

