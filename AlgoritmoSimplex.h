#ifndef ALGORITMOSIMPLEX_H
#define ALGORITMOSIMPLEX_H

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "Matriz.h"
#include "DatosMatricesDePrueba.h"


// Del archivo DatosMatricesDePrueba.h
void MatrizDePrueba1();
void MatrizDePrueba2();
void MatrizDePrueba3();
void MatrizDePrueba4();


void BOLD(){
    printf("\x1B[1m");
}

void RESET(){
    printf("\x1B[0m");
}

void PrintMatriz(){ /* Función donde se ejecuta la lógica del programa */
    printf("Z \t ");
    for (int i = 0 ; i < 8 ; i++){
        if (flags_variables[i] == true){
            printf("%s \t ", nombre_variables[i+1]);
        }
    }
    for (int i = 0 ; i < cantidad_holguras ; i++){
        printf("s%d \t ", i+1);
    }
    for (int i = 0 ; i < cantidad_excesos ; i++){
        printf("e%d \t ", i+1);
    }
    for (int i = 0 ; i < cantidad_artificiales ; i++){
        printf("a%d \t ", i+1);
    }
    printf("X\n");
    for (int i=0;i<FilasMatriz;i++)
    {
       for(int j=0;j<ColumnasMatriz;j++)
        {
            printf("%.1f \t",Matriz[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
}

void PrintProblemaOriginal(){
    Latex_PrintProblemSection(maximizar);
}

void PrintTablaInicial(){
    printf("Tabla inicial:\n");
    PrintMatriz();
    Latex_Write("\\section{Tabla inicial} \n");
    Latex_PrintTable(0, -1, -1, false);
}

void PrintEndSlide(){
    Latex_PrintEndSlide();
}
void PrintSolucionFinal(){
    Latex_PrintFinalSolution();
}

void PrintTablaFinal(){
    printf("Tabla final:\n");
    PrintMatriz();
    Latex_Write("\\section{Tabla final} \n");
    Latex_PrintTable(-1,-1, -1, false);
}

void PrintTablaIntermedia(int columna_escogida){
    BOLD();
    printf("Tabla intermedia #%d:\n",numero_tabla_intermedia);
    RESET();
    PrintMatriz();
    numero_tabla_intermedia ++;
    Latex_PrintTable(numero_tabla_intermedia, -1, columna_escogida, true); // Canonizada
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

void VerificarFactibilidadM(){ /* Se verifica si la funcion es factible */
    for (int j = 0 ; j < GetPosicionArtificiales() ; j++){             //este ciclo va a recorrer todas las artificiales
        if ( Matriz[1][j] != 0){
            casos_especiales[1] =  true; // 1: No factibilidad
        }
    }
}

int VerificarSolucionesMultiples(){ /* Se verifica si la funcion es factible */
    int columna = 0;
    for (int j = 1 ; j < cantidad_variables+1 ; j++){             //este ciclo va a recorrer todas las artificiales
        if ( Matriz[0][j] == 0.0){
            for (int i = 2 ; i < FilasMatriz ; i++){   
                if (Matriz[i][j]== 0.0 || Matriz[i][j]== 1.0 ){
                    
                }else{return j;}
            }
        }
    }
    return columna;
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
            }else if (division_actual == division_menor && casos_especiales[2] == false){
//                MatrizDegenerada = true;
                casos_especiales[2] = true; // 2: Degenerado
                TablaDeMatrizDegenerada = numero_tabla_intermedia;
                printf("\naquí se degenero\n");
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
    Latex_PrintTable(-2,-1, -2, true); // Ms canonizadas
//    PrintTablaIntermedia();
}
//

void AlgoritmoSimplex(){
    int i_pivote;
    int columna_escogida;
    

    CreateMatriz();
//    MatrizDePrueba1();        // Normal
//    MatrizDePrueba2();          // Fábrica de La Agricultura (Con Ms) 
//    MatrizDePrueba3();          // Dakota Modificado (Para soluciones multiples)
//    MatrizDePrueba4();
//    MatrizDePrueba5();

    
    PrintProblemaOriginal();
    PrintTablaInicial();
    
    if (ExistenMs()) CanonizarMs();
    
    if (tablas_intermedias) 
    {printf("\n\n\n NO IF TABLAS INTERM \n\n\n");
        Latex_Write("\\section{Tablas intermedias} \n");}
    
    if (ExisteColumnaCandidata()==true){
        printf("\n\n\n EXISTE COLUMNA CANDIDATA \n\n\n");
    }else{
        printf("\n\n\n NO EXISTE COLUMNA CANDIDATA \n\n\n");
    }
    
    
    while (ExisteColumnaCandidata()){
        columna_escogida = ColumnaCandidata();
        if (columna_escogida==-1) {
            printf("No se pudo escoger la columna \n");
            break;
        }
        puts("");
        printf("Columna escogida: %d\n",columna_escogida);

        
        i_pivote = EncontrarPivote(columna_escogida);
        if (i_pivote==-1 && casos_especiales[0] == false){
            casos_especiales[0] = true; // 0: No acotado
            TablaDeMatrizNoAcotada = numero_tabla_intermedia;
            printf("No se pudo escoger el pivote, solucion no acotada \n");
            break;
        }
        printf("Pivote escogido: %.2f (%d,%d)\n", Matriz[i_pivote][columna_escogida], i_pivote, columna_escogida);
        puts("");
        if (tablas_intermedias) Latex_PrintTable(numero_tabla_intermedia,  i_pivote,  columna_escogida, false); // Tabla intermedia con Pivoteo
        CanonizarColumna(i_pivote, columna_escogida);
        if (tablas_intermedias) PrintTablaIntermedia(columna_escogida);
    }
    PrintTablaFinal();
    
    VerificarFactibilidadM();
    
    printf("\n\n");
    
    columna_escogida =VerificarSolucionesMultiples();
    
    //se verifica si puede tener soluciones multiples
    if (VerificarSolucionesMultiples()!=0 && casos_especiales[1] == false && casos_especiales[2] == false){
        casos_especiales[3] = true;
        //Va a guardar los primeros resultados

        int i_solucion;
//        float listaSolucion[4][cantidad_variables];
        //soluciones_multiples
        for (int j = 1 ; j < cantidad_variables+1 ; j++){
            if (ColumnaEsCanonizada(j)){
                i_solucion = UnoDeColumnaCanonizada(j);
                //printf("\\item $x_{%.1f} = %.1f$ \n",(float)j,  Matriz[i_solucion][ColumnasMatriz-1]);
                soluciones_multiples[0][j-1]=Matriz[i_solucion][ColumnasMatriz-1];

            }else{soluciones_multiples[0][j-1]=0;}
        }
        //se transforma la segunda matriz para obtener la otra solucion
        int h=0;
        while (  h<1 ){
            puts("");
            printf("Columna escogida: %d\n",columna_escogida);

            i_pivote = EncontrarPivote(columna_escogida);
            if (i_pivote==-1){
                printf("No se pudo escoger el pivote para solucion multiple, solucion no acotada \n");
                break;
            }
            printf("Pivote escogido: %.2f (%d,%d)\n", Matriz[i_pivote][columna_escogida], i_pivote, columna_escogida);
            puts("");
//            if (tablas_intermedias) Latex_PrintTable(numero_tabla_intermedia,  i_pivote,  columna_escogida, false); // Tabla intermedia con Pivoteo
            CanonizarColumna(i_pivote, columna_escogida);
//            if (tablas_intermedias) PrintTablaIntermedia(columna_escogida);
            h++;
        }

        //Va a guardar los segundos resultados

        for (int j = 1 ; j < cantidad_variables+1 ; j++){
            if (ColumnaEsCanonizada(j)){
                i_solucion = UnoDeColumnaCanonizada(j);
                //printf("\\item $x_{%.1f} = %.1f$ \n",(float)j,  Matriz[i_solucion][ColumnasMatriz-1]);
                soluciones_multiples[1][j-1]=Matriz[i_solucion][ColumnasMatriz-1];
            }else{soluciones_multiples[1][j-1]=0;}
        }

        

        // se procede a sacar las otras dos soluciones

        for (int i = 0 ; i < cantidad_variables ; i++){

               soluciones_multiples[2][i]= 0.5*soluciones_multiples[0][i] + 0.5*soluciones_multiples[1][i];
               soluciones_multiples[3][i]= 0.25*soluciones_multiples[0][i] + 0.75*soluciones_multiples[1][i];
            }
        
        
    }
    
    
    
    PrintSolucionFinal();
    PrintEndSlide();

     
}




#endif /* ALGORITMOSIMPLEX_H */

