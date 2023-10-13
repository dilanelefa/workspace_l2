#include <stdio.h>
#include <stdlib.h>
#include "pile_avec_liste.h"

Pile initialisation(int taille_max){
    Pile p;
    p.sommet = NULL;
    p.nb_element = 0;
    p.taille_max = taille_max;
    return p;
}

int estVide(Pile p){
    return p.sommet == NULL;
}

int estPleine(Pile p){
    return p.taille_max == p.nb_element;
}

void empiler(Pile *p, char valeur){
    if(!estPleine(*p)){
        Liste nouveau = (Liste)malloc(sizeof(struct cellule));
        if(nouveau == NULL)
            return;
        nouveau->valeur = valeur;
        nouveau->suivant = NULL;
        if(estVide(*p)){
            p->sommet = nouveau;
        }
        else{
            nouveau->suivant = p->sommet;
            p->sommet = nouveau;
        }
        p->nb_element++;
    }
}

char depiler(Pile *p){
    char valeur = ' ';
    if(!estVide(*p)){
        Liste element = p->sommet;
        p->sommet = p->sommet->suivant;
        valeur = element->valeur;
        free(element);
        p->nb_element--;
    }

    return valeur;
}

void print(Pile p){
    if(!estVide(p)){
        Liste t = p.sommet;
        while(t!=NULL){
            printf("%c", t->valeur);
            t = t->suivant;
        }
        printf("\n");
    }
}
