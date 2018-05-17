#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MatricesDePrueba.h"

#ifndef _LATEX_H_
#define _LATEX_H_

#define NAME_OF_TEX_FILE "LATEX.tex"
#define NAME_OF_PDF_FILE "LATEX.pdf"
#define RED  "\x1B[31m"
#define GRN  "\x1B[32m"
#define BCK  "\x1B[0m"

FILE * tex_file;

double GetProbabilidad(int n);




void Latex_Write(char * text){
    fputs(text, tex_file);
}
void Latex_WriteI(char * text, int numero){
    fprintf(tex_file, text, numero);
}
void Latex_WriteII(char * text, int numero1, int numero2){
    fprintf(tex_file, text, numero1, numero2);
}
void Latex_WriteF(char * text, float numero){
    fprintf(tex_file, text, numero);
}
void Latex_WriteFF(char * text, float numero1, float numero2){
    fprintf(tex_file, text, numero1, numero2);
}


void Latex_PrintStartTable(int numero_tabla){
    Latex_Write(" \n");
    Latex_Write("\\begin{frame}  \n");
    if (numero_tabla == 0)      Latex_Write("\\frametitle{Tabla inicial} \n");
    else if(numero_tabla == -1) Latex_Write("\\frametitle{Tabla final} \n");
    else if(numero_tabla == -2) Latex_Write("\\frametitle{Tabla intermedia 1} \n");
    else                        Latex_WriteI("\\frametitle{Tabla intermedia \\#%d} \n", numero_tabla);
    Latex_Write("\\begin{table}[H] \n");
    Latex_Write("\\begin{center} \n");
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
        if (columna_escogida == columna_actual) Latex_WriteI(" & \\cellcolor{color_columna_candidata}\\textcolor{color_blanco}{\\textbf{x$_{%d}$}}", i+1);
        else                                    Latex_WriteI(" & \\textbf{x$_{%d}$}", i+1);
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

void Latex_PrintEndTable(int numero_tabla, int columna_escogida, bool canonizada){
    Latex_Write("\\end{tabular} \n");
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
    Latex_PrintEndTable(numero_tabla, columna_escogida, canonizada);
}


//void Latex_Table(struct st_tabla_A tabla){
//    Latex_Table_Start(tabla.N);
//    Latex_Table_Content(tabla.N, tabla.N);
//    Latex_Table_End();
//}

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
    Latex_Write("\\subtitle{Operations Research} \n");
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

