#ifndef BESTIAIRE_H_INCLUDED
#define BESTIAIRE_H_INCLUDED

// initialise le tableau d'espece de pokemon disponible dans le jeu.
void initBestiaire(EspecePokemon bestiaire[]);

// affiche le bestiaire trié dans l'rodre naturel (l'ordre de saisi).
void afficheBestiaire(EspecePokemon bestiaire[]);

// affiche le bestiaire trié par nom de pokemon croissant.
void afficheBestiaireTrie(EspecePokemon bestiaire[]);

// rechercher l'espèce d'un pokemon, à partir de son nom, dans le bestiaire
EspecePokemon lookupEspecePokemon(EspecePokemon bestiaire[], char* nom);

#endif



#endif // BESTIAIRE_H_INCLUDED
