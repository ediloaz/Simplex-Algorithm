#ifndef ALGORITMOSIMPLEX_H
#define ALGORITMOSIMPLEX_H

#include <stdio.h>

int cantidadVariables = 2;
int cantidadHolguras = 1;
int cantidadExcesos =1;
int cantidadArtificiales = 2;
int FilasMatriz = 5;
int ColumnasMatriz = 8;
float Matriz[5][8];
int i,j;
int NumeroFinalizar = 0;
int max = -1;// si es 1 es maximizar o si es -1 es minimizar
float divisionMenor = 100000000;
float divisionMenorAcutal = 100000000;
int PosDivisionMenorA = 0;
int PosDivisionMenorB = 0;


int BuscarPivote(void) /* Función donde se ejecuta la lógica del programa */
{
  int pivote;
  pivote =0;

	return pivote; /* sale de la función */
}

void PrintMatriz(void) /* Función donde se ejecuta la lógica del programa */
{
for (i=0;i<FilasMatriz;i++)
{
for(j=0;j<ColumnasMatriz;j++)
{
printf("%f ",Matriz[i][j]);
}
printf("\n");
}
}

void AlgoritmoSimplex(){

//Llenamos la matriz

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

int a,b,c,d;

// aqui sabemos si se maximiza o minimiza
if (max == 1){
  NumeroFinalizar = -1;
}else{NumeroFinalizar = 1;}

int ComienzodeArtificiales = 1 + cantidadVariables + cantidadHolguras + cantidadExcesos;
//canonizar las m
if (cantidadArtificiales > 0 ){

for(  a = ComienzodeArtificiales ; a < ComienzodeArtificiales + cantidadArtificiales; a = a + 1 ){//este ciclo va a recorrer todas las artificiales

  for(  b = 2 ; b < ColumnasMatriz; b = b + 1 ){//este ciclo va a recorrer todas las artificiales

        if ( Matriz[b][a] == 1){//si da igual a uno, aqui es donde se encuentra el 1 de la M que estamos canonizando
          //printf("%d\n", b );
          for(  c = 0 ; c < ColumnasMatriz; c = c + 1 ){//este ciclo va a recorrer todas las artificiales
                Matriz[1][c] = Matriz[1][c] + Matriz[b][c];
        }
     }
   }

}
}


//ahora se procede a hacer el simplex normal
ComienzodeArtificiales = 1 + cantidadVariables + cantidadHolguras + cantidadExcesos;
while( d = 1 ) {
PrintMatriz();
// aqui busca el pivote
for(  a = 1 ; a < ComienzodeArtificiales; a = a + 1 ){//este ciclo va a recorrer todas las variables normales, de holgura y exceso
  if ( Matriz[1][a] > 0){//si alguna de la fila de las M es mayor a 0, entonces se agarra esa columna

  for(  b = 2 ; b < ColumnasMatriz; b = b + 1 ){//este ciclo va a recorrer todas las columnas para encontrar la division menor

        if ( Matriz[b][a] > 1 ){//si da igual a uno, es un pivote candidatos
          divisionMenorAcutal = Matriz[b][ColumnasMatriz]/Matriz[b][a] ;
          if (divisionMenorAcutal < divisionMenor){
            divisionMenor = divisionMenorAcutal;
            PosDivisionMenorB = b;
            PosDivisionMenorA = a;

          }
     }
   }
}
}
//printf("\n %f \n ", Matriz[PosDivisionMenorB][PosDivisionMenorA]);
// se transforma en 1 la fila
int PivoteDividir = Matriz[PosDivisionMenorB][PosDivisionMenorA]; //se guarda el numero que va a dividir toda la fila
for(  a = 1 ; a < ColumnasMatriz; a = a + 1 ){//este ciclo va a recorrer todas las variables normales, de holgura y exceso
  Matriz [PosDivisionMenorB][a] = Matriz [PosDivisionMenorB][a] / PivoteDividir;
}
//printf("\n %d, %d ", PosDivisionMenorA,PosDivisionMenorB);
printf(" \n \n");
PrintMatriz();
break;
//aqui hace las divisiones
for(  a = 1 ; a < ComienzodeArtificiales; a = a + 1 ){//este ciclo va a recorrer todas las variables normales, de holgura y exceso
  if ( Matriz[1][a] > 0){//si alguna de la fila de las M es mayor a 0, entonces se agarra esa columna

  for(  b = 2 ; b < ColumnasMatriz; b = b + 1 ){//este ciclo va a recorrer todas las columnas para encontrar la division menor

        if ( Matriz[b][a] > 1 ){//si da igual a uno, es un pivote candidatos
          divisionMenorAcutal = Matriz[b][ColumnasMatriz]/Matriz[b][a] ;
          if (divisionMenorAcutal < divisionMenor){
            divisionMenor = divisionMenorAcutal;
            PosDivisionMenorB = b;

          }
     }
   }

}
}




}
}

#endif /* ALGORITMOSIMPLEX_H */

