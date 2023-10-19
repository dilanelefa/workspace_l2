#ifndef PILE_AVEC_TABLEAU
#define PILE_AVEC_TABLEAU

#define TAILLE_MAX 255

typedef struct pile{
    char T[TAILLE_MAX];
    int sommet;
}Pile;

Pile initialisation();
int estVide(Pile p);
int estPleine(Pile p);
void empiler(Pile *p, char valeur);
char depiler(Pile *p);

#endif
