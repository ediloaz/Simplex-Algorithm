#ifndef ALGORITMOSIMPLEX_H
#define ALGORITMOSIMPLEX_H

#include <stdio.h>
#include <stdbool.h>
#include "MatricesDePrueba.h"


void BOLD(){
    printf("\x1B[1m");
}

void RESET(){
    printf("\x1B[0m");
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
    BOLD();
    printf("Tabla intermedia #%d:\n",numero_tabla_intermedia);
    RESET();
    PrintMatriz();
    numero_tabla_intermedia ++;
}


bool ExistenMs(){
    for (int j = 0 ; j < ColumnasMatriz ; j++){
        if(Matriz[1][j] != 0){
            return true;
        }
    }
    return false;
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

// Hay columnas que quedan con valores muy, muy decimalizados, por ejempo 0.00000000000000341, y esto provoca que sea mayor a 0, cuando no debe ser así
int ColumnaCandidata(){            // i={0,1}
    float numero_candidato  = 0;
    int columna_candidata = -1;
    int i = -1;
    if(ExistenMs()){
//        printf("Sí existen Ms\n");
        i = 1;
        if (maximizar){
//            printf("Sí existen Ms | MAX\n");
            for (int j=1 ; j< ColumnasMatriz-1 ; j++){
                if (((int)(100*Matriz[i][j]) < (int)(100*numero_candidato))){       // Es negativo
                    numero_candidato  = Matriz[i][j];
                    columna_candidata = j;
//                    printf("Sí existen Ms | MAX | Candidato: %d (%f)\n", j, numero_candidato);
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
//            printf("Sí existen Ms | MIN\n");
            for (int j=1 ; j< ColumnasMatriz-1 ; j++){
                if ((int)(100*Matriz[i][j]) > (int)(100*numero_candidato)){       // Es positivo
                    numero_candidato  = Matriz[i][j];
                    columna_candidata = j;
//                    printf("Sí existen Ms | MIN | Candidato: %d (%d)\n", j, (int)(100*Matriz[i][j]));
                }else if(((int)(100*Matriz[i][j]) == (int)(100*numero_candidato)) && (int)(100*numero_candidato)!=0){ // Empate de Ms, revisar el número acompañante
//                    printf("Sí existen Ms | MIN | Candidato: %d empate con %d \n", j, columna_candidata);
                    if (Matriz[0][j] > Matriz[0][columna_candidata]){       // Es positivo
                        numero_candidato  = Matriz[i][j];
                        columna_candidata = j;
//                        printf("Sí existen Ms | MIN | Candidato: %d empate con %d CAMBIADA\n", j, columna_candidata);
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
//        printf("NO existen Ms\n");
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
    
    
    return columna_candidata;   
}


int EncontrarPivote(int columna_escogida){
    float division_menor = 9999;
    float division_actual;
    int i_pivote = -1;
    for(int i = 2 ; i < FilasMatriz ; i++ ){  //este ciclo va a recorrer todas las filas para encontrar la division menor
//        printf("voy por la fila %d\n",i);
        if (Matriz[i][columna_escogida] > 0 ){                //si es mayor o igual a uno, es un pivote candidatos
            division_actual = Matriz[i][ColumnasMatriz-1]/Matriz[i][columna_escogida] ;
            if (division_actual < division_menor){
//                printf("ESCOGÍ la fila %d\n",i);
                division_menor = division_actual;
                i_pivote = i;
            }
        }
    }
    return i_pivote;
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
//        PrintTablaIntermedia();
    }
    multiplicador_escogido = 1/pivote;
    for (int j=0 ; j<ColumnasMatriz ; j++){
        Matriz[i_pivote][j] = multiplicador_escogido*Matriz[i_pivote][j];
    }
}


void CanonizarMs(){
    int posicion_artificiales = GetPosicionArtificiales();
    int i_pivote;
//    printf("pos %d\n", posicion_artificiales);
    for (int j = posicion_artificiales ; j < ColumnasMatriz-1 ; j++){             //este ciclo va a recorrer todas las artificiales
        i_pivote = EncontrarPivote(j);
//        printf("Pivote:%d y pasé por j:%d (%.1f)\n", i_pivote,j, Matriz[i_pivote][j]);
        CanonizarColumna(i_pivote, j);
    }
    PrintTablaIntermedia();
}
//

void AlgoritmoSimplex(){
    int i_pivote;
    int columna_escogida;
    float pivote;
    
    MatrizDePrueba3();

    PrintTablaInicial();
    
    if (ExistenMs()) CanonizarMs();
    
    while (ExisteColumnaCandidata()){
        columna_escogida = ColumnaCandidata();
        if (columna_escogida==-1) {
            printf("No se pudo escoger la columna \n");
            break;
        }
        puts("");
        printf("Columna escogida: %d\n",columna_escogida);

        
        i_pivote = EncontrarPivote(columna_escogida);
        if (i_pivote==-1){
            printf("No se pudo escoger el pivote, sol. no factible \n");
            break;
        }
        printf("Pivote escogido: %.2f (%d,%d)\n", Matriz[i_pivote][columna_escogida], i_pivote, columna_escogida);
        puts("");
        CanonizarColumna(i_pivote, columna_escogida);
        PrintTablaIntermedia();
    }
     
}




#endif /* ALGORITMOSIMPLEX_H */

