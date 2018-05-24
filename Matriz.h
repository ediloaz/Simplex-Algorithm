#ifndef MATRIZ_H
#define MATRIZ_H

#include <stdbool.h>
#include "Parser.h"
#include "Interfaz.h"


// Creación de la matriz
float Matriz[12][28];

// Filas y columnas de la matriz (fila contando la fila de la M)
int FilasMatriz;
int ColumnasMatriz;

// Las variables que se van a usar
int cantidad_variables;
int cantidad_holguras;
int cantidad_excesos;
int cantidad_artificiales;

// El nombre del programa
char nombre_programa[80];

// Los posibles 8 nombres de las variables
char nombre_variables[8][40];

// Tabla intermedia por la que se va imprimiendo
int numero_tabla_intermedia = 1;

// 1: Maximizar     || 0: Minimizar
bool maximizar;                 // si es TRUE es maximizar o si es FALSE es minimizar
// 1: Sí imprimir     || 0: No imprimir
bool tablas_intermedias;

// Indica si la matriz es degenerada
int TablaDeMatrizDegenerada;
int TablaDeMatrizNoAcotada;

// Banderas para los casos especiales
// Orden: [0] No acotado
//        [1] No factible
//        [2] Degenerado
//        [3] Múltiples soluciones
bool casos_especiales[4];       

// Banderas para indicar las variables que se usan
bool flags_variables[8];
// Banderas para indicar las restricciones que se usan
bool flags_restricciones[10];

// Some arrays...
float constants_objective_function[8];
float constants[10][8];
float equals[10];
int   symbols[10];
float soluciones_multiples[4][9];        // 9: Z  ||  [0,]: x1 - x8

void PrintMatriz();


int getColumnasMatriz(){
    return ColumnasMatriz;
}
void setColumnasMatriz(int pColumnasMatriz){
     ColumnasMatriz = pColumnasMatriz;
     printf("\nColumnas definidas a %i\n", pColumnasMatriz);
}

int getFilasMatriz(){
    return FilasMatriz;
}
void setFilasMatriz(int pFilasMatriz){
    FilasMatriz = pFilasMatriz;
    printf("\nFilas definidas a %i\n", pFilasMatriz);
}

int getCantidadVariables(){
    return cantidad_variables;
}
void setCantidadVariables(int p_cantidad_variables){
     cantidad_variables = p_cantidad_variables;
     printf("\nVariables definidas a %i\n", p_cantidad_variables);
}

int getCantidadHolguras(){
    return cantidad_holguras;
}
void setCantidadHolguras(int p_cantidad_holguras){
     cantidad_holguras = p_cantidad_holguras;
     printf("\nHolguras definidas a %i\n", p_cantidad_holguras);
}

int getCantidadExcesos(){
    return cantidad_excesos;
}
void setCantidadExcesos(int p_cantidad_excesos){
     cantidad_excesos = p_cantidad_excesos;
     printf("\nExcesos definidas a %i\n", p_cantidad_excesos);
}

int getCantidadArtificiales(){
    return cantidad_artificiales;
}
void setCantidadArtificiales(int p_cantidad_artificiales){
     cantidad_artificiales = p_cantidad_artificiales;
     printf("\nArtificiales definidas a %i\n", p_cantidad_artificiales);
}

bool getMaximizar(){
    return maximizar;
}
void setMaximizar(bool p_maximizar){
    maximizar = p_maximizar;
}

bool getTablasIntermedias(){
    return tablas_intermedias;
}
void setTablasIntermedias(bool p_tablas_intermedias){
    tablas_intermedias = p_tablas_intermedias;
}

char * getNombrePrograma(){
    return nombre_programa;
}
void setNombrePrograma(char *  p_nombre_programa){
    strcpy(nombre_programa, p_nombre_programa);
}



// - - - - - 


bool IsItARow(float * constants){
    for (int i = 0 ; i < 8 ; i++){
        if (constants[i] != 0.0) return true;
    }
    return false;
}


void FillMatriz(){
    int cantidad_variables_usadas  = 0;
    int cantidad_holguras_usadas  = 0;
    int cantidad_excesos_usadas  = 0;
    int cantidad_artificiales_usadas  = 0;
//    printf("\n\nVoy por la corrida %d \n\n", 0);
    PrintMatriz();
     
    // Llenar con la función objetivo
    Matriz[0][0] = 1;
    for (int j = 1 ; j < ColumnasMatriz ; j++){     // USAMOS MÉTODO 2, SI ES MIN CONVERTIDOS LOS X DE SÍMBOLO
        if (maximizar)  Matriz[0][j] = constants_objective_function[j-1] * -1.0;
        else            Matriz[0][j] = constants_objective_function[j-1] * -1.0;
    }
//    printf("\n\n");
    
//    printf("\n\nVoy por la corrida %d \n\n", 1);
    PrintMatriz();
    
    int inicio;
    // Llenar con las restricciones
    int real_i = 2, var_i;
    for (int i = 2 ; i < 12 ; i++){
        if (flags_restricciones[i-2] == true){
            var_i = i-2;
            i = real_i;
            real_i ++;
            
            // Columna de Z
            inicio = 0;
            Matriz[i][inicio] = 0 ;  // Siempre es 0;
            
            // Columnas de Xi
            inicio = 1;
            cantidad_variables_usadas = 0;
            for (int j = inicio ; j < 9 ; j++){
                if (flags_variables[j-inicio]){
//                    printf("flags_variables[%i] si entró", j);
                    Matriz[i][inicio + cantidad_variables_usadas] = constants[var_i][j-inicio];
                    cantidad_variables_usadas ++;
                }else{
//                    printf("flags_variables[%i] No entró", j);
                }
            }
            // Columnas de si
            
            if (symbols[var_i] == 0){       // 1 holgura
                inicio = 1 + cantidad_variables;
                Matriz[i][inicio + cantidad_holguras_usadas] = 1;
                cantidad_holguras_usadas ++;
            }else if (symbols[var_i] == 1){ // 1 artificial
                inicio = 1 + cantidad_variables + cantidad_holguras + cantidad_excesos;
                Matriz[i][inicio + cantidad_artificiales_usadas] = 1;
                if (maximizar)  Matriz[1][inicio + cantidad_artificiales_usadas] =  1;       // Ms
                else            Matriz[1][inicio + cantidad_artificiales_usadas] = -1;
                cantidad_artificiales_usadas ++;
            }else if (symbols[var_i] == 2){ // 1 artificial y 1 exceso
                inicio = 1 + cantidad_variables + cantidad_holguras + cantidad_excesos;
                Matriz[i][inicio + cantidad_artificiales_usadas] = 1;
                if (maximizar)  Matriz[1][inicio + cantidad_artificiales_usadas] =  1;       // Ms
                else            Matriz[1][inicio + cantidad_artificiales_usadas] = -1;
                cantidad_artificiales_usadas ++;
                
                inicio = 1 + cantidad_variables + cantidad_holguras;
                Matriz[i][inicio + cantidad_excesos_usadas] = -1;
                cantidad_excesos_usadas ++;
            }
            // Columna de resultado
            Matriz[i][ColumnasMatriz-1] = equals[var_i];
//            printf("\n\n");
            
            i = var_i+2;
//            printf("\n\nVoy por la corrida %d \n\n", i);
//                PrintMatriz();
        }
    }
    PrintMatriz();
}
//cantidad_variables;
//int cantidad_holguras;
//int cantidad_excesos;
//int cantidad_artificiales;
// Some arrays...
//float constants[10][8];
//float equals[10];
//int   symbols[10];
void CountCantidadVariables(){
    int   cantidad_filas = 0, cantidad_columnas = 0;
    int temp_cantidad_variables  = 0;
    int temp_cantidad_holguras  = 0;
    int temp_cantidad_excesos  = 0;
    int temp_cantidad_artificiales  = 0;
    
    // iniciar banderas de variables Xj
    for (int j = 0 ; j < 8 ; j++){
        flags_variables[j] = false;
    }
    // iniciar banderas de restricciones Ri
    for (int i = 0 ; i < 10 ; i++){
        flags_restricciones[i] = false;
    }
    // Busca las Xi entre las restricciones
    for (int i = 0 ; i < 10 ; i++){
        for (int j = 0 ; j < 8 ; j++){
            if (flags_variables[j] == false && constants[i][j] != (float)0){
                flags_variables[j] = true;
                temp_cantidad_variables ++;
//                printf("\n\n R%d tiene el valor %.2f en X%d \n\n", i+1, constants[i][j], j+1);
            }
        }
        if (IsItARow(constants[i])) {
            flags_restricciones[i] = true;
            cantidad_filas ++;
        }
    }
    // Busca las Xi entre la función objetivo
    for (int j = 0 ; j < 8 ; j++){
        if (flags_variables[j] == false && constants_objective_function[j] != (float)0){
            flags_variables[j] = true;
            temp_cantidad_variables ++;
        }
    }
    
    // Busca las si, ei y ai entre las restricciones
    for (int i = 0 ; i < 10 ; i++){
        if (flags_restricciones[i] == true){
            if (symbols[i] == 0){
                temp_cantidad_holguras ++;
//                printf("\n\n R%d tiene el simbolo %d \n\n", i+1, symbols[i]);
            }else if (symbols[i] == 1){
                temp_cantidad_artificiales ++;
//                printf("\n\n R%d tiene el simbolo %d \n\n", i+1, symbols[i]);
            }else if (symbols[i] == 2){
                temp_cantidad_artificiales ++;
                temp_cantidad_excesos ++;
//                printf("\n\n R%d tiene el simbolo %d \n\n", i+1, symbols[i]);
            }
        }
    }
    cantidad_filas = 2 + cantidad_filas;
    setFilasMatriz(cantidad_filas);
    cantidad_columnas = 1 + temp_cantidad_variables + temp_cantidad_holguras + temp_cantidad_excesos + temp_cantidad_artificiales + 1;
    setColumnasMatriz(cantidad_columnas);
    setCantidadVariables(temp_cantidad_variables);
    setCantidadHolguras(temp_cantidad_holguras);
    setCantidadExcesos(temp_cantidad_excesos);
    setCantidadArtificiales(temp_cantidad_artificiales);
}

void ParserVariables(){ 
    printf(" ");
    if (id_switch_tablas_intermedias == 1) setTablasIntermedias(true);
    else                                   setTablasIntermedias(false);
    
    if (id_radiobutton_max == 1) {
        printf("\n\n\n MAXIIMIMIIZAR \n\n\n ");
        setMaximizar(true);
    }
    else{
        printf("\n\n\n MINIMIZAR \n\n\n ");
        setMaximizar(false);
    }
    
    printf("Función objetivo: \n");
    printf("\tTexto: %s",texto_funcion_objetivo);
    for (int j = 0 ; j < 8 ; j++){
        constants_objective_function[j] = GetConstant(texto_funcion_objetivo, j+1);
        printf("\tX%i: %.1f", j+1 ,constants_objective_function[j]);
    }
    puts("\n");

    printf("Restricciones: \n");
    for (int i = 0 ; i < 10 ; i++){
        printf("\tTexto: %s",s_constraints[i]);
        for (int j = 0 ; j < 8 ; j++){
            constants[i][j] = GetConstant(s_constraints[i], j+1);
            printf("\tX%i: %.1f", j+1 ,constants[i][j]);
            
        }
        printf("\n");
    }
    printf("Igualados: \n");
    for (int i = 0 ; i < 10 ; i++){
        equals[i] = atof(s_equals[i]);
        printf("\tX%i: %.1f", i,equals[i]);
        printf("\n");
    }
    printf("Igualadores: \n");
    for (int i = 0 ; i < 10 ; i++){
        symbols[i] = s_equalitor[i];
        printf("\tX%i: %d", i,symbols[i]);
        printf("\n");
    }
    
    printf("Variables: \n");
    for (int i = 0 ; i < 8 ; i++){
        strcpy(nombre_variables[i], s_nombre_variables[i]);
        printf("\tX%i: %s", i,nombre_variables[i]);
        printf("\n");
    }
    
    strcpy(nombre_programa, texto_nombre_problema);
    
    CountCantidadVariables();
    
}

void CreateMatriz(){
    ParserVariables();
    FillMatriz();
//    CountCantidadVariables();
    
}

#endif /* MATRIZ_H */

