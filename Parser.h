#ifndef PARSER_H
#define PARSER_H

#include "Matriz.h"

bool CheckChars(char * a){
    return true;
}

int FoundSymbol(char * a, int position_constant){
    for (int i = position_constant ; i > -1 ; i--){       // revisar si es -1
        printf("\n\nPos: %d  ||  Char: %c \n", i, a[i]);
        if (a[i] == '+'){
            printf("\t Fue positivo \n");
            return +1;
        }else if (a[i] == '-'){
            printf("\t Fue negativo \n");
            return -1;
        }else if (a[i] == ' '){
            printf("\t Fue blank \n");
//            puts("blanco \n\n");
        }else{
            printf("\t Fue otra vara \n");
            if (i==0) break;
            return 0;
        }
    }
    return +1;
}

float GetConstantByPosition(char * a, int position_x){
    int digit, multipler = 1;
    float constant, decimal_area, error = -99999.0;
    if (a[position_x-1] > 47 && a[position_x-1] < 58) constant = 0;
    else  constant = 1;
    bool decimal_used = false;
    for (int i = position_x-1 ; i > -1 ; i--){
//        printf("SubFor: %d \n", i);
        if (a[i] > 47 && a[i] < 58){
            digit = (a[i] - 48)*multipler;
            constant += digit;
            multipler *= 10;
//            printf("un digito: %d\n", digit);
        }else if ((a[i] == '.' || a[i] == ',') && decimal_used == false){
            if (constant == 0) {
//                printf("error Constante es 0 \n\n");
//                return error;
            }
            decimal_area = constant/multipler;
            constant = decimal_area;
            multipler = 1;
            decimal_used = true;
//            printf("Convertido a decimal: %f\n",constant );
        }else{
            int symbol = FoundSymbol(a, i);
            if (symbol == 0){
//                printf("error símbolo tiene un 0 \n\n");
                return error;
            }
            printf("\n Cons antes: %.1f", constant);
            constant *= symbol;
            printf("\n Cons despues: %.1f", constant);
            break;
        }
    }
    
    return constant;
}

float GetConstant(char * a, int i_x){
    // apariciones de Xi
    float constant = 0;
    for (int i = 0 ; i < 80-1 ; i++){
//        printf("\t\t ** X%d posicion %d con el char %c(%d) ** \n\n", i_x, i, a[i], (int)a[i]);
        if ((a[i] == 'x' || a[i] == 'X') && (a[i+1] == i_x+48)){
            // Entontró la posiciones del Xi en la variable i
            constant = GetConstantByPosition(a, i);
            if (constant == -99999.0)                 return -99999.0;
            else if (constant == 0 || constant == -0) constant = 1;
        }else if ((a[i] == 'x' || a[i] == 'X') && (a[i+1] < 49 || a[i+1] > 56)){
//            printf("error con la i de Xi, a: %c || a+1:  %c \n\n",  a[i], a[i+1]);
            return -99999.0;        // Encontró un X seguido de un valor 
        }else if((int)a[i] == 0){
            // terminó;
            break;
        }
    }
    return constant;
}

void PrintConstraints(float * constants){
    printf("Restricciones \n");
    for (int i = 0 ; i < 8 ; i++){
        printf("\tx%d: %.2f \n",i+1, constants[i]);
    }
}
//
//void ParserConstraints(){
//    
//}
//
//void ParserByRow(char * a){
////    char a[300] = " 12.56x1 - x2 - 1.44x5 + 1.84x4 - 80.44x8 ";
////    char a[300] = " 5x1 + 8x2 + 800x3 \n\n\n";
//    bool error_parser = false;
//    float constants[8];                                           // lista de todas las constantes
//    for (int i = 0 ; i < 8 ; i++){
//        constants[i] = GetConstant(a, i+1);
//        if (constants[i] == -99999.0){
//            error_parser = true;
//        }
//    }
//    if (error_parser)   printf("Error: Formato de restricciones");
//    else                PrintConstraints(constants);
//}
//
//
//float * GetConstantsByString(char * a){
////    char a[300] = " 12.56x1 - x2 - 1.44x5 + 1.84x4 - 80.44x8 ";
////    char a[300] = " 5x1 + 8x2 + 800x3 \n\n\n";
//    bool error_parser = false;
//    float constants[8];                                           // lista de todas las constantes
//    for (int i = 0 ; i < 8 ; i++){
//        constants[i] = GetConstant(a, i+1);
//        if (constants[i] == -99999.0){
//            error_parser = true;
//        }
//    }
//    return constants;
//}

#endif /* PARSER_H */

