#include <stdio.h>
#include <stdlib.h>
#include "pile_avec_tableau.h"
#include "verification_expression.h"

int main(){
    char expression[255];
    printf("Entre une expression: ");
    scanf("%[^\n]", expression);
    if(verification_expression(expression)){
        printf("L'expression est bien forme.\n");
    }else{
        printf("L'expression est mal forme.\n");
    }
    return 0;
}
