#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef LATEX_H
#define LATEX_H


#define PATH_OF_TEX_FILE "LATEX.tex"
#define PATH_OF_PDF_FILE "LATEX.pdf"
#define OUT_PATH "./Salida/"
#define RED  "\x1B[31m"
#define GRN  "\x1B[32m"
#define BCK  "\x1B[0m"



void MoveFiles(){
//    char command[] = "mv -v ./";
//    char blank[] = " ";
//    strcat(command, PATH_OF_TEX_FILE);
//    strcat(command, blank);
//    strcat(command, OUT_PATH);
//    strcat(command, PATH_OF_TEX_FILE);
//    system(command);
    system("mv -v ./LATEX.pdf ./Salida/LATEX.pdf");
    system("mv -v ./LATEX.tex ./Salida/LATEX.tex");
    system("mv -v ./LATEX.log ./Salida/LATEX.log");
    system("mv -v ./LATEX.aux ./Salida/LATEX.aux");
}


// - - - - - - - - - - - - - - - - 
// - - - - - - - - - - - - - - - - 
// - - - PRINT TABLES  - - - - - - 
void Latex_Table_Start(int N){
    FILE * tex_file;
    tex_file = fopen(PATH_OF_TEX_FILE, "a+");
    fputs("\\begin{center} \n", tex_file);          // \begin{center}
    fputs("\\begin{tabular}{", tex_file);
    for (int i=0 ; i<N ; i++) fputs("|c", tex_file);
    fputs("|} \n", tex_file);                       // \begin{tabular}{|c|c|c|c|c|c|c|c|}
    fputs("\\hline \n", tex_file);                  // \hline 
    fclose(tex_file);
}











void Latex_Start(){
    FILE * tex_file;
    tex_file = fopen(PATH_OF_TEX_FILE, "w");
    fputs("% A.B.B. Dinámicos vs. A.B.B. Greedy \n", tex_file);
    fputs("% Written by Edisson López \n", tex_file);
    fputs("% Contact: ediloaz@gmail.com \n", tex_file);
    fputs("% Cartago, Costa Rica \n", tex_file);
    fputs("  \n", tex_file);
    fputs("% For the course: \n", tex_file);
    fputs("% 	Operations Research (of Costa Rica Institute of Technology) \n", tex_file);
    fputs("% 	Teacher: Dr. Jose Francisco Torres \n", tex_file);
    fputs(" \n", tex_file);
    fputs("% HEADER { \n", tex_file);
    fputs("\\documentclass[a4paper,twocolumn,10pt]{article} \n", tex_file);
    fputs("\\usepackage{tikz} \n", tex_file);
    fputs("\\usepackage{pgfplots} \n", tex_file);
    fputs("\\pgfplotsset{compat=1.10} \n", tex_file);
    fputs("\\usetikzlibrary{shapes.geometric,arrows,fit,matrix,positioning} \n", tex_file);
    fputs("\\tikzset \n", tex_file);
    fputs("{ \n", tex_file);
    fputs("    treenode/.style = {circle, draw=black, align=center, minimum size=1cm} \n", tex_file);
    fputs("} \n", tex_file);
    fputs("\\usepackage{lmodern} \n", tex_file);
    fputs("\\usepackage{float} \n", tex_file);
    fputs("\\usepackage[T1]{fontenc} \n", tex_file);
    fputs("%\\usepackage[spanish]{babel} \n", tex_file);
    fputs("\\usepackage[utf8]{inputenc} \n", tex_file);
    fputs("\\usepackage[left=0.7cm, top=1.5cm, right=0.7cm, bottom=2cm]{geometry} \n", tex_file);
    fputs("\\newcommand\\tab[1][1cm]{\\hspace*{#1}} \n", tex_file);
    fputs("\\newcommand\\minitab[1][0.5cm]{\\hspace*{#1}} \n", tex_file);
    fputs("\\title{A.B.B. Dinámicos vs. A.B.B. Greedy} \n", tex_file);
    fputs("\\author{Edisson López Díaz} \n", tex_file);
    fputs("\\date{\\today}  \n", tex_file);
    fputs("% } HEADER \n", tex_file);
    
    fputs("% DOCUMENT { \n", tex_file);
    fputs("\\begin{document} \n", tex_file);
    fputs("\\maketitle \n", tex_file);
    fclose(tex_file);
}


void Latex_End(){
    FILE * tex_file;
    tex_file = fopen(PATH_OF_TEX_FILE, "a+");
    fputs("\\end{document}\n", tex_file);
    fputs("% } DOCUMENT \n", tex_file);
    fputs("% Última línea del documento", tex_file);
    fclose(tex_file);
}


void GeneratePDF(){
    char command[] = "pdflatex ";
    strcat(command, PATH_OF_TEX_FILE);
    system(command);
}

void OpenPDF(){
    char command[] = "xdg-open ";
    strcat(command, PATH_OF_PDF_FILE);
    system(command);
}

void Latex(){
    Latex_Start();
    Latex_End();
    GeneratePDF();
    OpenPDF();
    MoveFiles();
}

#endif /* LATEX_H */

