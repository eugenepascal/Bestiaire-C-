#ifndef pokedex_h
#define pokedex_h

#include "pokemon.h"
#include "ressources.h"


typedef struct {

    // tableau dynamique de pokemons
    Pokemon* mesPokemons;

    // capacité maximale du tableau
    int capacity;

    // nombre de pokemon dans le tableau jusqu'à maintenant.
    int nbPokemons;
    } Pokedex;

Pokedex* initPokedex(const int size);

void insertPokemon(Pokedex** moPokedex, Pokemon p);

void displayPokedex(Pokedex* pokedex,EspecePokemon bestiaire[150], char* typesLabel[18], const Ressources ressources);

Pokemon* genererPokemon(EspecePokemon bestiaire[150], char* typesLabel[18]);



#endif /* pokedex_h */
