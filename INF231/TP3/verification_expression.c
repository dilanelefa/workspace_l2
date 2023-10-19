#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "verification_expression.h"

int verification_charactere(char *expression, char valeur[2]){
    Pile p = initialisation();
    int bien = 1;
    for(int i = 0; i < strlen(expression); i++){
        if(expression[i] == valeur[0]){
            empiler(&p, expression[0]);
        }
        if(expression[i] == valeur[1]){
            if(estVide(p)){
                bien = 0;
                break;
            }else{
                depiler(&p);
            }
        }
    }

    if(bien == 1 && estVide(p)){
        return 1;
    }else{
        return 0;
    }
}

int verification_expression(char *expression){
    int paranthese = verification_charactere(expression, "()");
    int accolade = verification_charactere(expression, "{}");
    int crochet = verification_charactere(expression, "[]");
    return paranthese && accolade && crochet;
}
