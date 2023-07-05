#ifndef BESTIAIRE_H_INCLUDED
#define BESTIAIRE_H_INCLUDED

// initialise le tableau d'espece de pokemon disponible dans le jeu.
void initBestiaire(EspecePokemon bestiaire[]);

// affiche le bestiaire tri� dans l'rodre naturel (l'ordre de saisi).
void afficheBestiaire(EspecePokemon bestiaire[]);

// affiche le bestiaire tri� par nom de pokemon croissant.
void afficheBestiaireTrie(EspecePokemon bestiaire[]);

// rechercher l'esp�ce d'un pokemon, � partir de son nom, dans le bestiaire
EspecePokemon lookupEspecePokemon(EspecePokemon bestiaire[], char* nom);

#endif



#endif // BESTIAIRE_H_INCLUDED
