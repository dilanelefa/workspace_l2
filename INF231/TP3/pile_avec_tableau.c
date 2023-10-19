#include <stdio.h>
#include <stdlib.h>
#include "pile_avec_tableau.h"

Pile initialisation(){
    Pile p;
    p.sommet = -1;
    for(int i = 0; i < TAILLE_MAX; i++){
        p.T[i] = '0';
    }
    return p;
}

int estVide(Pile p){
    return p.sommet == -1;
}

int estPleine(Pile p){
    return TAILLE_MAX == p.sommet;
}

void empiler(Pile *p, char valeur){
    if(!estPleine(*p)){
        p->sommet++;
        p->T[p->sommet] = valeur; 
    }
}

char depiler(Pile *p){
    char valeur = ' ';
    if(!estVide(*p)){
        valeur = p->T[p->sommet];
        p->T[p->sommet] = '0';
        p->sommet--;
    }
    return valeur;
}
