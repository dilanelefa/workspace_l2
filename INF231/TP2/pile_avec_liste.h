#ifndef PILE_AVEC_LISTE_H
#define PILE_AVEC_LISTE_H

typedef struct cellule *Liste;
struct cellule{
    char valeur;
    Liste suivant;
};

typedef struct pile{
    int taille_max;
    Liste sommet;
    int nb_element;
}Pile;

Pile initialisation(int taille_max);
int estVide(Pile p);
int estPleine(Pile p);
void empiler(Pile *p, char valeur);
char depiler(Pile *p);

void print(Pile p);

#endif
