
#ifndef pokemon_h
#define pokemon_h

#include "PokemonTypes.h"
#include "bestiaire.h"

typedef struct Pokemon {

    char* nom;
    int xp;
    int evolution;
    int pv;
    int cp;

} Pokemon;


// Business logic
void evolve(Pokemon* p, char* nextEvolution);
void powerup(Pokemon* p);
void display(const Pokemon p, EspecePokemon bestiaire[150], char* typesLabel[18]);


#endif
