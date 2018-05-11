#ifndef TABLA_H
#define TABLA_H

/*
 * n1 : Cantidad de variables (x)
 * n2 : Cantidad de variables de holgura
 * n3 : Cantidad de variables de exceso
 * n4 : Cantidad de variables artificiales
 */
int n1, n2, n3, n4;

int columna_actual;     // Posición J de la columna escogida para el cálculo
//int pivote;             // Posición I del Pivote escogido de esa columna
int x = 25, y = 10;               // x: Cantidad de filas | y: Cantidad de columnas
float tabla[25][10];        // 


void TablaPrueba(){
    for (int i = 0 ; i < x ; i++){
        for (int j = 0 ; j < y ; j++){
            tabla[x][y] = (float)(rand()%100) ;
            printf("%.1f \t ", tabla[x][y]);
        }
        printf("\n");
    }
}

#endif /* TABLA_H */

