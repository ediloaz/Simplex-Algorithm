#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "Matriz.h"

#ifndef _LATEX_H_
#define _LATEX_H_

#define NAME_OF_TEX_FILE "LATEX.tex"
#define NAME_OF_PDF_FILE "LATEX.pdf"
#define RED  "\x1B[31m"
#define GRN  "\x1B[32m"
#define BCK  "\x1B[0m"

FILE * tex_file;

double GetProbabilidad(int n);


char *replace_str(char *str, char *orig, char *rep)
{
  static char buffer[4096];
  char *p;

  if(!(p = strstr(str, orig)))  // Is 'orig' even in 'str'?
    return str;

  strncpy(buffer, str, p-str); // Copy characters from 'str' start to 'orig' st$
  buffer[p-str] = '\0';

  sprintf(buffer+(p-str), "%s%s", rep, p+strlen(orig));

  return buffer;
}




void Latex_Write(char * text){
    fputs(text, tex_file);
}
void Latex_WriteS(char * text, char * string){
    fprintf(tex_file, text, string);
}
void Latex_WriteI(char * text, int numero){
    fprintf(tex_file, text, numero);
}
void Latex_WriteII(char * text, int numero1, int numero2){
    fprintf(tex_file, text, numero1, numero2);
}
void Latex_WriteF(char * text, float float_number){
    int number = (int)(float_number*1000);
    if (number%10 == 0 && number%100 == 0 && number%1000 == 0){
        text = replace_str(text, "%.1f", "%d");
        fprintf(tex_file, text, (int)float_number);
    }
    else{
        fprintf(tex_file, text, float_number);
    }
}

void Latex_WriteFS(char * text, float float_number, char * string){
    int number = (int)(float_number*1000);
    if (number%10 == 0 && number%100 == 0 && number%1000 == 0){
        text = replace_str(text, "%.1f", "%d");
        fprintf(tex_file, text, (int)float_number, string );
    }
    else{
        fprintf(tex_file, text, float_number, string);
    }
}


void Latex_WriteFF(char * text, float float_number1, float float_number2){
    int number1 = (int)(float_number1*1000);
    int number2 = (int)(float_number2*1000);
    if (number1%10 == 0 && number1%100 == 0 && number1%1000 == 0){
        text = replace_str(text, "%.1f", "%d");
        if (number2%10 == 0 && number2%100 == 0 && number2%1000 == 0){
            if (number2<0)  text = replace_str(text, "+%.1f", "%d");
            else            text = replace_str(text, "%.1f", "%d");
            fprintf(tex_file, text, (int)float_number1, (int)float_number2);
        }else{
            fprintf(tex_file, text, (int)float_number1, float_number2);
        }
    }else{
        if (number2%10 == 0 && number2%100 == 0 && number2%1000 == 0){
            printf("Cambie solo uno? Antes: %s", text);
            text = replace_str(text, "%.1f", "%AAAAAAAA");      // Cambio temporal
            printf("| Despues%s", text);
            if (number2<0)  text = replace_str(text, "+%.1f", "%d");
            else            text = replace_str(text, "%.1f", "%d");
            text = replace_str(text, "%AAAAAAAA", "%.1f");      // Cambio temporal
            fprintf(tex_file, text, float_number1, (int)float_number2);
        }else{
            fprintf(tex_file, text, float_number1, float_number2);
        }
    }
}

bool ColumnaEsCanonizada(int j){
    int number, contador = 0;
    number = (int)(Matriz[0][j]*1000);
    printf("\n\n IF: %d", number);
    if (number != 0) return false;
    number = (int)(Matriz[1][j]*1000);
    printf("\n\n IF: %d", number);
    if (number != 0) return false;
    for (int i = 2 ; i < FilasMatriz ; i++){
        number = (int)(Matriz[i][j]*1000);
        printf("\n\n IF: %d", number);
        if (number == 1000){
            contador ++;
        }else if (number != 0){
            return false;
        }
    }
    if (contador == 1)  return true;    // Hubo 0s y un 1
    else                return false;   // No hubo 1s
}

int UnoDeColumnaCanonizada(int j){
    int number;
    for (int i = 2 ; i < FilasMatriz ; i++){
        number = (int)(Matriz[i][j]*1000);
        if (number == 1000){
            return i;
        }
    }
    return 0;
}




// - - - - - - - - - - - - -
// - - SECTION 4, 5 & 6  - - 
// - - - - - - - - - - - - - 
void Latex_PrintStartTable(int numero_tabla){
    Latex_Write(" \n");
    Latex_Write("\\begin{frame}  \n");
    if (numero_tabla == 0)      Latex_Write("\\frametitle{Tabla inicial} \n");
    else if(numero_tabla == -1) Latex_Write("\\frametitle{Tabla final} \n");
    else if(numero_tabla == -2) Latex_Write("\\frametitle{Tabla intermedia 1} \n");
    else                        Latex_WriteI("\\frametitle{Tabla intermedia \\#%d} \n", numero_tabla);
    Latex_Write("\\begin{table}[H] \n");
    Latex_Write("\\begin{center} \n");
    Latex_Write("\\resizebox{\\linewidth}{!}{ \n");
    Latex_WriteI("\\begin{tabular}{|*{%d}{c|}} \n", getColumnasMatriz());
}

void Latex_PrintCellsTable_Cell(int i, int j, bool es_primera, int i_pivote, int columna_escogida){
    if (es_primera){
        if (j == columna_escogida){
            if (i == i_pivote)  Latex_WriteF("\\cellcolor{color_pivote}\\textbf{%.1f}", Matriz[i][j]);  // Es el pivote
            else                Latex_WriteF("\\cellcolor{color_columna_candidata}\\textcolor{color_blanco}{%.1f}", Matriz[i][j]);  // Es de la columna a canonizar
        }else{
            Latex_WriteF("%.1f", Matriz[i][j]);  // Celda normal
        }
    }else{
        if (j == columna_escogida){
            if (i == i_pivote)  Latex_WriteF(" & \\cellcolor{color_pivote}\\textbf{%.1f}", Matriz[i][j]);  // Es el pivote
            else                Latex_WriteF(" & \\cellcolor{color_columna_candidata}\\textcolor{color_blanco}{%.1f}", Matriz[i][j]);  // Es de la columna a canonizar
        }else{
            Latex_WriteF(" & %.1f", Matriz[i][j]);  // Celda normal  i_pivote = -1 y columna_escogida = -1
        }
    }
}

void Latex_PrintCellsTable_FirstRow(int columna_escogida){
    int columna_actual;
    Latex_Write("\\hline \n");
    Latex_Write("\\textbf{Z} ");
    for (int i = 0 ; i < cantidad_variables ; i++){
        columna_actual = i + 1;
        if (columna_escogida == columna_actual) Latex_WriteS(" & \\cellcolor{color_columna_candidata}\\textcolor{color_blanco}{\\textbf{%s}}", nombre_variables[i]);
        else                                    Latex_WriteS(" & \\textbf{%s}", nombre_variables[i]);
    }
    for (int i = 0 ; i < cantidad_holguras ; i++){
        columna_actual = i + cantidad_variables + 1;
        if (columna_escogida == columna_actual) Latex_WriteI(" & \\cellcolor{color_columna_candidata}\\textcolor{color_blanco}{\\textbf{s$_{%d}$}}", i+1);
        else                                    Latex_WriteI(" & \\textbf{s$_{%d}$}", i+1);
    }
    for (int i = 0 ; i < cantidad_excesos ; i++){
        columna_actual = i + cantidad_variables + cantidad_holguras + 1;
        if (columna_escogida == columna_actual) Latex_WriteI(" & \\cellcolor{color_columna_candidata}\\textcolor{color_blanco}{\\textbf{e$_{%d}$}}", i+1);
        else                                    Latex_WriteI(" & \\textbf{e$_{%d}$}", i+1);
    }
    for (int i = 0 ; i < cantidad_artificiales ; i++){
        columna_actual = i + cantidad_variables + cantidad_holguras + cantidad_excesos + 1;
        if (columna_escogida == columna_actual) Latex_WriteI(" & \\cellcolor{color_columna_candidata}\\textcolor{color_blanco}{\\textbf{a$_{%d}$}}", i+1);
        else                                    Latex_WriteI(" & \\textbf{a$_{%d}$}", i+1);
    }
    Latex_Write(" & \\textbf{•} \\\\");
    
    Latex_Write("\\hline \\hline \n");
}

bool EsCero(float float_number){
    int number = (int)(float_number*1000);
    if (number%10 == 0 && number%100 == 0 && number%1000 == 0){
        return true;
    }
    else{
        return false;
    }
}

void Latex_PrintCellsTable_SecondRow(int i_pivote, int columna_escogida){
    for (int j = 0 ; j < ColumnasMatriz ; j++){
        if (j == 0){
            if (j == columna_escogida){
                if (1 == i_pivote || 0 == i_pivote) {   // Es el pivote
                    if      (Matriz[0][j] == 0.0 && Matriz[1][j] == 0.0)    Latex_Write("\\cellcolor{color_pivote}\\textbf{0}"); 
                    else if (Matriz[0][j] == 0.0 && Matriz[1][j] != 0.0)    Latex_WriteF("\\cellcolor{color_pivote}\\textbf{%.1fM}", Matriz[1][j]); 
                    else if (Matriz[0][j] != 0.0 && Matriz[1][j] == 0.0)    Latex_WriteF("\\cellcolor{color_pivote}\\textbf{%.1f}", Matriz[0][j]);  
                    else                                                    Latex_WriteFF("\\cellcolor{color_pivote}\\textbf{%.1f+%.1fM}", Matriz[0][j], Matriz[1][j]); 
                }
                else{                                   // Es de la columna a canonizar
                    if      (Matriz[0][j] == 0.0 && Matriz[1][j] == 0.0)    Latex_Write("\\cellcolor{color_columna_candidata}\\textcolor{color_blanco}{0}"); 
                    else if (Matriz[0][j] == 0.0 && Matriz[1][j] != 0.0)    Latex_WriteF("\\cellcolor{color_columna_candidata}\\textcolor{color_blanco}{%.1fM}", Matriz[1][j]); 
                    else if (Matriz[0][j] != 0.0 && Matriz[1][j] == 0.0)    Latex_WriteF("\\cellcolor{color_columna_candidata}\\textcolor{color_blanco}{%.1f}", Matriz[0][j]);  
                    else                                                    Latex_WriteFF("\\cellcolor{color_columna_candidata}\\textcolor{color_blanco}{%.1f+%.1fM}", Matriz[0][j], Matriz[1][j]);
                }
            }else{
                if      (Matriz[0][j] == 0.0 && Matriz[1][j] == 0.0)    Latex_Write("0"); 
                else if (Matriz[0][j] == 0.0 && Matriz[1][j] != 0.0)    Latex_WriteF("%.1fM", Matriz[1][j]); 
                else if (Matriz[0][j] != 0.0 && Matriz[1][j] == 0.0)    Latex_WriteF("%.1f", Matriz[0][j]);  
                else                                                    Latex_WriteFF("%.1f+%.1fM", Matriz[0][j], Matriz[1][j]);
            }
        }else{
            if (j == columna_escogida){
                if (1 == i_pivote || 0 == i_pivote) {   // Es el pivote
                    if      (Matriz[0][j] == 0.0 && Matriz[1][j] == 0.0)    Latex_Write(" & \\cellcolor{color_pivote}\\textbf{0}"); 
                    else if (Matriz[0][j] == 0.0 && Matriz[1][j] != 0.0)    Latex_WriteF(" & \\cellcolor{color_pivote}\\textbf{%.1fM}", Matriz[1][j]); 
                    else if (Matriz[0][j] != 0.0 && Matriz[1][j] == 0.0)    Latex_WriteF(" & \\cellcolor{color_pivote}\\textbf{%.1f}", Matriz[0][j]);  
                    else                                                    Latex_WriteFF(" & \\cellcolor{color_pivote}\\textbf{%.1f+%.1fM}", Matriz[0][j], Matriz[1][j]); 
                }
                else{                                   // Es de la columna a canonizar
                    if      (Matriz[0][j] == 0.0 && Matriz[1][j] == 0.0)    Latex_Write(" & \\cellcolor{color_columna_candidata}\\textcolor{color_blanco}{0}"); 
                    else if (Matriz[0][j] == 0.0 && Matriz[1][j] != 0.0)    Latex_WriteF(" & \\cellcolor{color_columna_candidata}\\textcolor{color_blanco}{%.1fM}", Matriz[1][j]); 
                    else if (Matriz[0][j] != 0.0 && Matriz[1][j] == 0.0)    Latex_WriteF(" & \\cellcolor{color_columna_candidata}\\textcolor{color_blanco}{%.1f}", Matriz[0][j]);  
                    else                                                    Latex_WriteFF(" & \\cellcolor{color_columna_candidata}\\textcolor{color_blanco}{%.1f+%.1fM}", Matriz[0][j], Matriz[1][j]);
                }
            }else{
                    if      (Matriz[0][j] == 0.0 && Matriz[1][j] == 0.0)    Latex_Write(" & 0"); 
                    else if (Matriz[0][j] == 0.0 && Matriz[1][j] != 0.0)    Latex_WriteF(" & %.1fM", Matriz[1][j]); 
                    else if (Matriz[0][j] != 0.0 && Matriz[1][j] == 0.0)    Latex_WriteF(" & %.1f", Matriz[0][j]);  
                    else                                                    Latex_WriteFF(" & %.1f+%.1fM", Matriz[0][j], Matriz[1][j]);
            }
        }
    }
    Latex_Write(" \\\\");
    Latex_Write("\\hline \n");
}


void Latex_PrintCellsTable(int i_pivote, int columna_escogida){
    int ColumnasMatriz = getColumnasMatriz();
    int FilasMatriz = getFilasMatriz();
    Latex_PrintCellsTable_FirstRow(columna_escogida);
    Latex_PrintCellsTable_SecondRow(i_pivote,columna_escogida);
    for (int i = 2 ; i < FilasMatriz ; i++ ){
        Latex_PrintCellsTable_Cell(i,0,true,i_pivote,columna_escogida); // Para no imprimir el "&" 
        for (int j = 1 ; j < ColumnasMatriz ; j++){
            Latex_PrintCellsTable_Cell(i,j,false,i_pivote,columna_escogida);
        }   
        Latex_Write("\\\\ \n");
        Latex_Write("\\hline \n");
    }
}

void Latex_PrintEndTable(int numero_tabla, int columna_escogida, bool canonizada, int i_pivote){
    Latex_Write("\\end{tabular}} \n");
    if (numero_tabla == 0){         // Tabla inicial
        Latex_Write("\\caption{Tabla inicial.} \n");
    }else if (numero_tabla == -1){  // Tabla final
        Latex_Write("\\caption{Tabla final.} \n");      
    }else{                          // Tabla intermedia
        if (canonizada) {
            if (columna_escogida == -2){
                if (cantidad_artificiales == 1) Latex_Write("\\caption{Tabla intermedia 1, con la columna a$_{1}$ canonizada.} \n");
                else                            Latex_Write("\\caption{Tabla intermedia 1, con las columnas a$_{i}$ canonizadas.} \n");
            }
                
            else                        Latex_WriteII("\\caption{Tabla intermedia %d, con la columna de %d canonizada.} \n", numero_tabla, columna_escogida+1);
        }
            
        else            Latex_WriteI("\\caption{Tabla intermedia %d, durante el pivoteo.} \n", numero_tabla);
    }
    
    if (!canonizada && numero_tabla != 0  && numero_tabla != -1){
        Latex_Write("{\\scriptsize Cálculos: ");
        // {\\scriptsize Cálculos: 48/8 = 0.2 | 48/8 = 0.2 | \textbf{48/8 = 0.2} | 48/8 = 0.2  }
        float division_menor = 9999;
        float division_actual;
        for(int i = 2 ; i < FilasMatriz ; i++ ){  //este ciclo va a recorrer todas las filas para encontrar la division menor
    //        printf("voy por la fila %d\n",i);
            if (Matriz[i][columna_escogida] > 0 ){                //si es mayor o igual a uno, es un pivote candidatos
                division_actual = Matriz[i][ColumnasMatriz-1]/Matriz[i][columna_escogida] ;
                if (division_actual < division_menor){  // Solo así puede imprimir el resultado
                    if (i == i_pivote){
                        Latex_WriteF("\\textbf{%.1f", Matriz[i][ColumnasMatriz-1]);
                        Latex_WriteF("/%.1f", Matriz[i][columna_escogida] );
                        Latex_WriteF(" = %.1f}", division_actual);
                    }else{
                        Latex_WriteF("%.1f", Matriz[i][ColumnasMatriz-1]);
                        Latex_WriteF("/%.1f", Matriz[i][columna_escogida] );
                        Latex_WriteF(" = %.1f", division_actual);
                    }
                    if (i!=FilasMatriz-1) Latex_Write(" | ");
                }
            }
        }
        Latex_Write("} \n");
    }
    Latex_Write("\\end{center} \n");
    Latex_Write("\\end{table} \n");
    Latex_Write("\\end{frame} \n");
    Latex_Write(" \n");
}

/* Tabla inicial:               Latex_PrintTable(0, -1, -1, false)
 * Tabla intermedia canonizada: Latex_PrintTable(#, -1, -1, true)
 * Tabla con pivoteo:           Latex_PrintTable(#,  #,  #, false)
 * Tabla final:                 Latex_PrintTable(-1,-1, -1, false)
 * Tabla Ms canonizada:         Latex_PrintTable(-2,-1, -2, true)
 */
void Latex_PrintTable(int numero_tabla, int i_pivote, int columna_escogida, bool canonizada){
    Latex_PrintStartTable(numero_tabla);
    Latex_PrintCellsTable(i_pivote,columna_escogida);
    Latex_PrintEndTable(numero_tabla, columna_escogida, canonizada, i_pivote);
}











// - - - - - - - - - 
// - - SECTION 3 - - 
// - - - - - - - - - 
void Latex_PrintEndProblemSection(){
//    Latex_Write("\\end{column} \n");
//    Latex_Write("\\end{columns} \n");
    Latex_Write("\\end{frame} \n");
    Latex_Write("\n");
}

void Latex_PrintStartProblemSection(){
    Latex_Write(" \n");
    Latex_Write("\\section{Problema original}  \n");
    Latex_Write("\\begin{frame}[shrink]  \n");
    Latex_WriteS("\\frametitle{%s} \n",nombre_programa);
//    Latex_Write("\\begin{columns} \n");
//    Latex_Write("\\begin{column}{0.5\\textwidth} \n");
}

void Latex_PrintContentProblemSection(){
    if (maximizar == true)  Latex_Write("\\begin{alertblock}{Maximizar} \n");
    else                    Latex_Write("\\begin{alertblock}{Minimizar} \n");
    Latex_Write("\\begin{itemize} \n");
    Latex_Write("\\item $Z = ");
    if (Matriz[0][1]>0) Latex_WriteFS("%.1f %s",Matriz[0][1], nombre_variables[0]);
    else            Latex_WriteFS("-%.1f %s",-1*Matriz[0][1], nombre_variables[0]);
    for (int i = 1 ; i < cantidad_variables ; i++){
        if (Matriz[0][i+1]>0) Latex_WriteFS(" + %.1f %s",Matriz[0][i+1], nombre_variables[i]);
        else                  Latex_WriteFS(" - %.1f %s",-1*Matriz[0][i+1], nombre_variables[i]);
    }
    Latex_Write("$ \n");
    Latex_Write("\\end{itemize} \n");
    Latex_Write("\\end{alertblock} \n");
    Latex_Write("\\begin{alertblock}{Restricciones} \n");
    Latex_Write("\\begin{enumerate} \n");
    for (int i = 2 ; i < FilasMatriz ; i++){
        Latex_WriteFS("\\item $ %.1f%s ",Matriz[i][1], nombre_variables[0]);
        for (int j = 1 ; j < cantidad_variables ; j++){
            if (Matriz[i][j]<0) Latex_WriteFS(" - %.1f %s",-1*Matriz[i][j+1], nombre_variables[j]);
            else                Latex_WriteFS(" + %.1f %s",Matriz[i][j+1], nombre_variables[j]);
        }
        if (symbols[i-2] == 0 )      Latex_WriteF(" \\leq %.1f",Matriz[i][ColumnasMatriz-1]);
        else if (symbols[i-2] == 1 ) Latex_WriteF("  = %.1f",Matriz[i][ColumnasMatriz-1]);
        else if (symbols[i-2] == 2 ) Latex_WriteF(" \\geq %.1f",Matriz[i][ColumnasMatriz-1]);
        else                         Latex_WriteF("  |error| %.1f",Matriz[i][ColumnasMatriz-1]);
        Latex_Write("$ \n");
    }
    Latex_Write("\\end{enumerate} \n");
    Latex_Write("\\end{alertblock} \n");
//    Latex_Write("\\end{column} \n");
//    Latex_Write("\\begin{column}{0.5\\textwidth}  \n");
//    Latex_Write("\\begin{alertblock}{Nombres de las variables} \n");
//    Latex_Write("\\begin{itemize} \n");
//    for (int i = 0 ; i < cantidad_variables ; i++){
//        Latex_WriteI("\\item $x_{%i}$: ", i+1);
//        Latex_WriteS("%s ", nombre_variables[i]);
//        Latex_Write(" \n");
//    }
//    Latex_Write("\\end{itemize} \n");
//    Latex_Write("\\end{alertblock} \n");
}

void Latex_PrintProblemSection(bool maximizar){
    Latex_PrintStartProblemSection();
    Latex_PrintContentProblemSection(maximizar);
    Latex_PrintEndProblemSection();
}










// - - - - - - - - - - - - 
// - - Final Solution  - - 
// - - - - - - - - - - - -      
void Latex_PrintSlideSolution(){            // Escribir en prosa, "Debe ser 10 Carros, 3.5 zanahorias y 1 laptop para obtener 200.
    Latex_Write("\n");
    Latex_Write("\\section{Solución} \n");
    Latex_Write("\\begin{frame} \n");
    Latex_Write("\\frametitle{Solución} \n");
    Latex_Write("\\begin{exampleblock}{Solución óptima} \n");
    Latex_WriteS("{\\scriptsize %s} \n", nombre_programa);
    Latex_Write("\\begin{itemize} \n");
    Latex_WriteF("\\item $Z = %.1f$ \n", Matriz[0][ColumnasMatriz-1]);
    int i_solucion;
    for (int j = 1 ; j < cantidad_variables+1 ; j++){
        puts("\n\n entré a for \n\n");
        if (ColumnaEsCanonizada(j)){
            puts("\n\n entré a IF \n\n");
            i_solucion = UnoDeColumnaCanonizada(j);
            Latex_WriteFF("\\item $x_{%.1f} = %.1f$ \n",(float)j,  Matriz[i_solucion][ColumnasMatriz-1]);
        }
    }
    Latex_Write("\\end{itemize} \n");
    Latex_Write("\\end{exampleblock} \n");
    Latex_Write("\\end{frame} \n");
    Latex_Write("\n");
}
void Latex_PrintParticularCasesSolution(){
    Latex_Write("\n");
    Latex_Write("\\begin{frame} \n");
    Latex_Write("\\frametitle{Casos especiales} \n");
    if (casos_especiales[0] || casos_especiales[1] || casos_especiales[2] || casos_especiales[3]){
        Latex_Write("\\begin{exampleblock}{} \n");
        Latex_Write("El problema presentó los siguientes casos especiales: \n");
        Latex_Write("\\begin{enumerate} \n");
        if (casos_especiales[0])    Latex_Write("\\item Problema no acotado  \n");
        if (casos_especiales[1])    Latex_Write("\\item Problema no factible  \n");
        if (casos_especiales[2])    Latex_Write("\\item Problema degenerado  \n");
        if (casos_especiales[3])    Latex_Write("\\item Problema con soluciones múltiples  \n");
        Latex_Write("\\end{enumerate} \n");
        Latex_Write("\\end{exampleblock} \n");
        Latex_Write("En los siguientes slides se explicará ésto. \n");
    }else{
        Latex_Write("El problema no presentó ningún caso especial \n");
    }
    Latex_Write("\\end{frame} \n");
    Latex_Write("\n");
}

void Latex_PrintNotLimitedProblems(){
    Latex_Write("\n");
    Latex_Write("\\begin{frame} \n");
    Latex_Write("\\frametitle{Problema no acotado} \n");
    Latex_WriteI("El problema se hizo no acotado al no poder escoger el pivote, en la tabla intermedia #%d no hubo una celda que cumpliera como pivote.\n", TablaDeMatrizNoAcotada);
    Latex_Write("\\end{frame} \n");
    Latex_Write("\n");
}


void Latex_PrintNotFeasibleProblems(){
    Latex_Write("\n");
    Latex_Write("\\begin{frame} \n");
    Latex_Write("\\frametitle{Problema no factible} \n");
    Latex_Write("El problema se hizo no factible al hacer un recorrido sobre la primer fila de la tabla final y se encontraron Ms.\n");
    Latex_Write("\\end{frame} \n");
    Latex_Write("\n");
}

void Latex_PrintDegeneratedProblems(){
    Latex_Write("\n");
    Latex_Write("\\begin{frame} \n");
    Latex_Write("\\frametitle{Problema degenerado} \n");
    Latex_WriteI("El problema se degeneró durante el cálculo del pivote en la tabla intermedia \\#%d hubieron dos celdas posibles a escoger como éste. \n", TablaDeMatrizDegenerada);
    Latex_Write("\\end{frame} \n");
    Latex_Write("\n");
}

void Latex_PrintSlideMultipleSolutionsProblems(int numero_slide){
    Latex_Write("\n");
    Latex_Write("\\begin{frame}[shrink]   \n");
    Latex_WriteII("\\frametitle{Soluciones múltiples %d y %d} \n", numero_slide, numero_slide+1);
    Latex_Write("\\begin{columns} \n");
    // Columna de la izquierda
    Latex_Write("\\begin{column}{0.5\\textwidth} \n");
    Latex_WriteI("\\begin{exampleblock}{Solución alternativa \\#%d} \n", numero_slide);
    Latex_Write("\\begin{itemize} \n");
    for (int i = 0 ; i < cantidad_variables ; i++){
        Latex_WriteS("\\item %s = ", nombre_variables[i]);
        Latex_WriteF("%.1f \n", soluciones_multiples[numero_slide-1][i]);
    }
    Latex_Write("\\end{itemize}  \n");
    Latex_Write("\\end{exampleblock}  \n");
    Latex_Write("\\end{column} \n");
    // Columna de la derecha
    Latex_Write("\\begin{column}{0.5\\textwidth} \n");
    Latex_WriteI("\\begin{exampleblock}{Solución alternativa \\#%d} \n", numero_slide +1);
    Latex_Write("\\begin{itemize}  \n");
    for (int i = 0 ; i < cantidad_variables ; i++){
        Latex_WriteS("\\item %s = ", nombre_variables[i]);
        Latex_WriteF("%.1f \n", soluciones_multiples[numero_slide][i]);
    }
    Latex_Write("\\end{itemize}  \n");
    Latex_Write("\\end{exampleblock}  \n");
    Latex_Write("\\end{column} \n");
    Latex_Write("\\end{columns} \n");
    Latex_Write("\\end{frame} \n");
    Latex_Write("\n");
}

void Latex_PrintMultipleSolutionsProblems(){
    Latex_Write("\n");
    Latex_Write("\\begin{frame} \n");
    Latex_Write("\\frametitle{Problema con soluciones múltiples} \n");
    Latex_Write("El problema llega a tener soluciones múltiples cuando se obtiene una base factible que tomamos como la solución del problema. Sin embargo, existe una variable no básica con un cero en la primera fila. \\\\ \n\n");
    Latex_Write("En los siguientes dos slides se darán las 4 soluciones alternativas \n");
    Latex_Write("\\end{frame} \n");
    Latex_Write("\n");
    Latex_PrintSlideMultipleSolutionsProblems(1);   // para el 1y2
    Latex_PrintSlideMultipleSolutionsProblems(3);   // para el 3y4
}

void Latex_PrintFinalSolution(){
    Latex_PrintSlideSolution();
    Latex_PrintParticularCasesSolution();
    if (casos_especiales[0])    Latex_PrintNotLimitedProblems();        // No acotados
    if (casos_especiales[1])    Latex_PrintNotFeasibleProblems();       // No factibles
    if (casos_especiales[2])    Latex_PrintDegeneratedProblems();       // Degenerados
    if (casos_especiales[3])    Latex_PrintMultipleSolutionsProblems(); // Múltiples soluciones
}



void Latex_PrintEndSlide(){
    Latex_Write("\\begin{frame}\\frametitle{}\\begin{center}{\\Huge - slide final -}\\end{center}\\end{frame} \n");
}




// - - - - - - - - - - - - 
// - - CONFIGURACIONES - - 
// - - - - - - - - - - - - 
void Latex_ComentariosIniciales(){
    fputs("% Technological of Costa Rica \n", tex_file);
    fputs("% Operations Research\n", tex_file);
    fputs("% 3rd Project\n", tex_file);
    fputs("% Linear Programming\n", tex_file);
    fputs("% Alonso Rivas Solano (2014079916)\n", tex_file);
    fputs("% Daniel Herrera Brenes (2015130539)\n", tex_file);
    fputs("% Edisson López Díaz (2013103311)\n", tex_file);
    fputs(" \n", tex_file);
}

void Latex_Header(){
    FILE * tex_file;
    tex_file = fopen(NAME_OF_TEX_FILE, "w");
    fclose(tex_file);
}



void Latex_InicializarVariable(){
    tex_file = fopen(NAME_OF_TEX_FILE, "w");
}

void Latex_FinalizarVariable(){
    fclose(tex_file);
}


void Latex_WriteHeader(){
    Latex_Write("\\documentclass{beamer} \n");
    Latex_Write("\\usetheme[progressbar=frametitle]{metropolis} \n");
    Latex_Write("\\setbeamertemplate{frame numbering}[fraction] \n");
    Latex_Write("\\useoutertheme{metropolis} \n");
    Latex_Write("\\useinnertheme{metropolis} \n");
    Latex_Write("\\usefonttheme{metropolis} \n");
    Latex_Write("\\usecolortheme{metropolis} \n");
    Latex_Write("\\usepackage[utf8]{inputenc} \n");
    Latex_Write("\\usepackage{lmodern} \n");
    Latex_Write("\\usepackage[T1]{fontenc} \n");
    Latex_Write("\\usepackage[spanish]{babel} \n");
    Latex_Write("\\usepackage{tikz} \n");
    Latex_Write("\\usepackage{natbib} \n");
    Latex_Write("\\usepackage{hyperref} \n");
    Latex_Write("\\usepackage{multirow} \n");
    Latex_Write("\\usepackage{colortbl} \n");
    Latex_Write("\\usepackage{helvet} \n");
    Latex_Write("\\usepackage[export]{adjustbox} % loads also graphicx \n");
    Latex_Write("\\usepackage{lipsum} \n");
    Latex_Write("%Definiciones \n");
    Latex_Write("\\definecolor{color_columna_candidata}{rgb}{0, 0.424, 0.455} \n");
    Latex_Write("\\definecolor{color_pivote}{rgb}{0.973, 0.80, 0.341} \n");
    Latex_Write("\\definecolor{color_blanco}{rgb}{1,1,1} \n");
    Latex_Write("% Commands \n");
    Latex_Write("\\newcommand\\tab[1][1cm]{\\hspace*{#1}}  \n");
    Latex_Write("\\newcommand\\minitab[1][0.5cm]{\\hspace*{#1}}  \n");
    Latex_Write("% Tittle information \n");
    Latex_Write("\\title{Símplex} \n");
    Latex_Write("\\subtitle{Investigación de operaciones} \n");
    Latex_Write("\\author[A. \\& D. \\& E.]{% \n");
      Latex_Write("\\texorpdfstring{% \n");
        Latex_Write("\\begin{columns} \n");
          Latex_Write("\\column{.33\\linewidth} \n");
          Latex_Write("\\centering \n");
          Latex_Write("\\\\  Daniel Herrera  \\\\ 2015130539 \\\\ \n");
          Latex_Write("\\column{.33\\linewidth} \n");
          Latex_Write("\\centering \n");
          Latex_Write("\\\\  Edisson López \\\\ 2013103311 \\\\ \n");
          Latex_Write("\\column{.33\\linewidth} \n");
          Latex_Write("\\centering \n");
          Latex_Write("\\\\ Alonso Rivas \\\\ 2014079916 \\\\ \n");
        Latex_Write("\\end{columns} \n");
     Latex_Write("} \n");
     Latex_Write("{Author 1, Author 2, Author 3} \n");
    Latex_Write("} \n");
    Latex_Write("\\date{} \n");
    Latex_Write("\\institute{% \n");
      Latex_Write("\\texorpdfstring{% \n");
        Latex_Write("\\begin{columns} \n");
          Latex_Write("\\column{.9\\linewidth} \n");
          Latex_Write("\\centering \n");
          Latex_Write("\\\\ \n");
          Latex_Write("Tecnológico de Costa Rica \\\\ \n");
          Latex_Write("Semestre 1, 2018 \\\\ \n");
          Latex_Write("24 de mayo, 2018 \n");
        Latex_Write("\\end{columns} \n");
     Latex_Write("} \n");
    Latex_Write("} \n");
}



void Latex_WriteSection(){
    Latex_Write("%Inicio del documento \n");
    Latex_Write("\\begin{document} \n");
}

void Latex_WriteSection2(){
    Latex_Write("\n");
    Latex_Write("% - - - - - - - - - ;\n");
    Latex_Write("% - - - - 2 - - - - ;\n");
    Latex_Write("% Algoritmo Sı́mplex: uno o dos slides que expliquen\n");
    Latex_Write("% un poco el algoritmo Sı́mplex.\n");
    Latex_Write("\\section{Algoritmo Símplex}\n");
    Latex_Write("\\begin{frame}\n");
    Latex_Write("\\lipsum[1-1]\n");
    Latex_Write("\\end{frame}\n");
    Latex_Write("\n");
    Latex_Write("\\begin{frame}\n");
    Latex_Write("\\lipsum[1-1]\n");
    Latex_Write("\\end{frame}\n");
    Latex_Write("\n");
}

void Latex_WriteCover(){
    Latex_Write("\n");
    Latex_Write("% - - 1st Slide - - ; \n");
    Latex_Write("% - - Cover - - - - ; \n");
    Latex_Write("\\begin{frame}[plain,t] \n");
    Latex_Write("\\maketitle \n");
    Latex_Write("\\end{frame} \n");
    Latex_Write("\n");
}

void Latex_WriteDocument(){
    Latex_Write("%Inicio del documento \n");
    Latex_Write("\\begin{document} \n");
    Latex_WriteCover();
    Latex_WriteSection2();
}



void Latex_End(){
    fputs("\\end{document}\n", tex_file);
    fputs("% } DOCUMENT \n", tex_file);
    fputs("% Última línea del documento", tex_file);
}


void GeneratePDF(){
    char command[] = "pdflatex ";
    strcat(command, NAME_OF_TEX_FILE);
    system(command);
}

void OpenPDF(){
    char command[] = "xdg-open ";
    strcat(command, NAME_OF_PDF_FILE);
    system(command);
}


void MoveFiles(){
    system("mv -v ./LATEX.pdf ./Salida/LATEX.pdf");
    system("mv -v ./LATEX.tex ./Salida/LATEX.tex");
    system("mv -v ./LATEX.log ./Salida/LATEX.log");
    system("mv -v ./LATEX.aux ./Salida/LATEX.aux");
    system("mv -v ./LATEX.nav ./Salida/LATEX.nav");
    system("mv -v ./LATEX.out ./Salida/LATEX.out");
    system("mv -v ./LATEX.snm ./Salida/LATEX.snm");
    system("mv -v ./LATEX.toc ./Salida/LATEX.toc");
}


void Latex(){
    Latex_WriteHeader();
    Latex_End();
    GeneratePDF();
    OpenPDF();
    printf("\nPress Enter to close the program.");
    getchar();
    MoveFiles();
    
}
void TerminarLatex(){
    Latex_End();
    Latex_FinalizarVariable();
    GeneratePDF();
    OpenPDF();
    printf("\nPress Enter to close the program.");
    getchar();
    MoveFiles();
}


void IniciarLatex(){
    Latex_InicializarVariable();
    Latex_ComentariosIniciales();
    Latex_WriteHeader();
    Latex_WriteDocument();
}

#endif /* LATEX_H */

