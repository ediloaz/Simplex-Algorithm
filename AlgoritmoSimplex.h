#ifndef ALGORITMOSIMPLEX_H
#define ALGORITMOSIMPLEX_H

#include <stdio.h>
#include <stdbool.h>
//#include "MatricesDePrueba.h"

#define reset     "\x1B[0m"
#define bold      "\x1B[1m"

// Variables globales
// Variables de holgura, de exceso y artificiales
int cantidad_variables;
int cantidad_holguras;
int cantidad_excesos;
int cantidad_artificiales;


// Información de la matriz
int FilasMatriz = 6;
int ColumnasMatriz = 9;
//float Matriz[5][8];
float Matriz[6][9];
// Otros datos
//int i,j;
int NumeroFinalizar = 0;
int numero_tabla_intermedia = 1;
bool maximizar;     // si es 1 es maximizar o si es -1 es minimizar

void BOLD(){
    printf("%s", bold);
}

void RESET(){
    printf("%s", reset);
}

void PrintMatriz(){ /* Función donde se ejecuta la lógica del programa */
    printf("Z \t x1 \t x2 \t s1 \t e1 \t a1 \t a2 \t X\n");
    for (int i=0;i<FilasMatriz;i++)
    {
        if (i==2) BOLD();
       for(int j=0;j<ColumnasMatriz;j++)
        {
        printf("%.1f \t",Matriz[i][j]);
        }
        printf("\n");
    }
    RESET();
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


// Dakota Modificado ((Para soluciones multiples)
void MatrizDePrueba3(){
    maximizar = true;
    cantidad_variables = 3;
    cantidad_holguras = 4;
    cantidad_excesos = 0;
    cantidad_artificiales = 0;
    FilasMatriz = 6;
    ColumnasMatriz = 9;

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


// Fábrica de La Agricultura ((Tiene Ms)
void MatrizDePrueba2(){
    maximizar = true;
    cantidad_variables = 2;
    cantidad_holguras = 2;
    cantidad_excesos =1;
    cantidad_artificiales = 1;
    FilasMatriz = 5;
    ColumnasMatriz = 8;

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

//void CanonizarMs(int posicion_artificiales){
//    int a, b, c; 
//    for(  a = posicion_artificiales ; a < posicion_artificiales + cantidad_artificiales; a = a + 1 ){//este ciclo va a recorrer todas las artificiales
//      for(  b = 2 ; b < ColumnasMatriz; b = b + 1 ){//este ciclo va a recorrer todas las artificiales
//            if ( Matriz[b][a] == 1){//si da igual a uno, aqui es donde se encuentra el 1 de la M que estamos canonizando
//              //printf("%d\n", b );
//              for(  c = 0 ; c < ColumnasMatriz; c = c + 1 ){//este ciclo va a recorrer todas las artificiales
//                    Matriz[1][c] = Matriz[1][c] + Matriz[b][c];
//            }
//         }
//       }
//
//    }
//    PrintTablaIntermedia();
//}

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

// Hay columnas que quedan con valores muy, muy decimalizados, por ejempo 0.00000000000000341, y esto provoca que sea mayor a 0, cuando no debe ser así
int ColumnaCandidata(){            // i={0,1}
    float numero_candidato  = 0;
    int columna_candidata = -1;
    int i = -1;
    if(ExistenMs()){
        printf("Sí existen Ms\n");
        i = 1;
        if (maximizar){
            printf("Sí existen Ms | MAX\n");
            for (int j=1 ; j< ColumnasMatriz-1 ; j++){
                if (((int)(100*Matriz[i][j]) < (int)(100*numero_candidato))){       // Es negativo
                    numero_candidato  = Matriz[i][j];
                    columna_candidata = j;
                    printf("Sí existen Ms | MAX | Candidato: %d (%f)\n", j, numero_candidato);
                }
            }
            if (columna_candidata == -1){ // Sí habían Ms pero ninguna cumplía ser menor o mayor a 0. Entonces se busca si en la fila 0 cumple alguno
                i = 0;
                for (int j=1 ; j< ColumnasMatriz-1 ; j++){
                    if (((int)(100*Matriz[i][j]) < (int)(100*numero_candidato)) && Matriz[1][j] == 0.0){       // Es negativo
                        numero_candidato  = Matriz[i][j];
                        columna_candidata = j;
                    }
                }   
            }
        }else if(!maximizar){
            printf("Sí existen Ms | MIN\n");
            for (int j=1 ; j< ColumnasMatriz-1 ; j++){
                if ((int)(100*Matriz[i][j]) > (int)(100*numero_candidato)){       // Es positivo
                    numero_candidato  = Matriz[i][j];
                    columna_candidata = j;
//                    printf("Sí existen Ms | MIN | Candidato: %d (%d)\n", j, (int)(100*Matriz[i][j]));
                }else if(((int)(100*Matriz[i][j]) == (int)(100*numero_candidato)) && (int)(100*numero_candidato)!=0){ // Empate de Ms, revisar el número acompañante
                    printf("Sí existen Ms | MIN | Candidato: %d empate con %d \n", j, columna_candidata);
                    if (Matriz[0][j] > Matriz[0][columna_candidata]){       // Es positivo
                        numero_candidato  = Matriz[i][j];
                        columna_candidata = j;
                        printf("Sí existen Ms | MIN | Candidato: %d empate con %d CAMBIADA\n", j, columna_candidata);
                    }
                }
            }
            if (columna_candidata == -1){ // Sí habían Ms pero ninguna cumplía ser menor o mayor a 0. Entonces se busca si en la fila 0 cumple alguno
                i = 0;
                for (int j=1 ; j< ColumnasMatriz-1 ; j++){
                    if (Matriz[i][j] > numero_candidato && Matriz[1][j] == 0.0){       // Es negativo
                        numero_candidato  = Matriz[i][j];
                        columna_candidata = j;
                    }
                }   
            }
        }
    }else{  
        printf("NO existen Ms\n");
        i = 0;
        if (maximizar){
            for (int j=1 ; j< ColumnasMatriz-1 ; j++){
                if (((int)(100*Matriz[i][j]) < (int)(100*numero_candidato))){       // Es negativo
                    numero_candidato  = Matriz[i][j];
                    columna_candidata = j;
                }
            }
        }else if(!maximizar){
            for (int j=1 ; j< ColumnasMatriz-1 ; j++){
                if (((int)(100*Matriz[i][j]) > (int)(100*numero_candidato))){       // Es positivo
                    numero_candidato  = Matriz[i][j];
                    columna_candidata = j;
                }
            }
        }
    }
    
    

    printf("Columna candidata: %d (%.1f)\n",columna_candidata, numero_candidato);
    return columna_candidata;   
}

//
//int ColumnaCandidata(){            // i={0,1}
//    float numero_candidato  = 0;
//    int columna_candidata = -1;
//    if(ExistenMs()){                    // Si existen todavía Ms, debe sacarlos
//        int i = 1;
//        for (int j=1 ; j< ColumnasMatriz-1 ; j++){
//            if (Matriz[i][j] > 0){       // Es negativo
//                numero_candidato  = Matriz[i][j];
//                columna_candidata = j;
//                
//            }
//        }
//    }else{                              // Ya no existen Ms
//        int i = 0;
//        if (maximizar){
//            for (int j=1 ; j< ColumnasMatriz-1 ; j++){
//                if (Matriz[i][j] < numero_candidato){       // Es negativo
//                    numero_candidato  = Matriz[i][j];
//                    columna_candidata = j;
//                }
//            }
//        }else{      // Minimizar
//            for (int j=1 ; j< ColumnasMatriz-1 ; j++){
//                if (Matriz[i][j] > numero_candidato){       // Es positivo
//                    numero_candidato  = Matriz[i][j];
//                    columna_candidata = j;
//                }
//            }
//        }
//        
//    }
//    printf("Columna candidata: %d (%.1f)\n",columna_candidata, numero_candidato);
//    return columna_candidata;   
//}
//

int EncontrarPivote(int columna_escogida){
    float division_menor = 9999;
    float division_actual;
    int i_pivote = -1;
    for(int i = 2 ; i < FilasMatriz ; i++ ){  //este ciclo va a recorrer todas las filas para encontrar la division menor
        printf("voy por la fila %d\n",i);
        if (Matriz[i][columna_escogida] > 0 ){                //si es mayor o igual a uno, es un pivote candidatos
            division_actual = Matriz[i][ColumnasMatriz-1]/Matriz[i][columna_escogida] ;
            if (division_actual < division_menor){
                printf("ESCOGÍ la fila %d\n",i);
                division_menor = division_actual;
                i_pivote = i;
            }
        }
    }
    return i_pivote;
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

void CanonizarColumna(int i_pivote, int columna_escogida){
    float pivote = Matriz[i_pivote][columna_escogida];
    float multiplicador_escogido;
    for (int i = 0 ;  i<FilasMatriz ; i++){
        if (i!=i_pivote){                 // La fila del pivote se cálcula después todas las otras.
            multiplicador_escogido = -Matriz[i][columna_escogida]/pivote;
            for (int j=0 ; j<ColumnasMatriz ; j++){
                Matriz[i][j] = Matriz[i][j] + (multiplicador_escogido*Matriz[i_pivote][j]);
            }
        }
        PrintTablaIntermedia();
    }
    multiplicador_escogido = 1/pivote;
    for (int j=0 ; j<ColumnasMatriz ; j++){
        Matriz[i_pivote][j] = multiplicador_escogido*Matriz[i_pivote][j];
    }
}


void CanonizarMs(){
    int posicion_artificiales = GetPosicionArtificiales();
    int i_pivote;
    printf("pos %d\n", posicion_artificiales);
    for (int j = posicion_artificiales ; j < ColumnasMatriz-1 ; j++){             //este ciclo va a recorrer todas las artificiales
        i_pivote = EncontrarPivote(j);
        printf("Pivote:%d y pasé por j:%d (%.1f)\n", i_pivote,j, Matriz[i_pivote][j]);
        CanonizarColumna(i_pivote, j);
    }
    printf("tabla despues de can. Ms\n");
    PrintTablaIntermedia();
}
//

void AlgoritmoSimplex(){
    //Llenamos la matriz
    MatrizDePrueba3();
    
    PrintTablaInicial();
       
    
    
    // Canonizar Ms
    if (ExistenMs()) CanonizarMs();

    int i_pivote;
    int columna_escogida;
    float pivote;
    // Se realiza el simplex normal
    // Mientras exista una columna candidata hace el simplex
    // Candidata: Si está maximizando y es negativa, ó, si está minimizando y es positiva.
    int a=0;
    while (ExisteColumnaCandidata() && a<10){
        a++;
        PrintTablaIntermedia();
        // Se busca la columna
        columna_escogida = ColumnaCandidata();
        if (columna_escogida==-1) {
            printf("No se pudo escoger la columna");
            break;                   // terminó
        }
        // Se busca el pivote (dentro de la columna)
        i_pivote = EncontrarPivote(columna_escogida);
        if (i_pivote==-1){
            printf("No se pudo escoger el pivote, sol. no factible");
            break;                   // terminó
        }

        printf("voy a canonizaaaar %d %d", i_pivote, columna_escogida);
        CanonizarColumna(i_pivote, columna_escogida);
    }
     
}




#endif /* ALGORITMOSIMPLEX_H */

