#ifndef PokemonTypes_h
#define PokemonTypes_h

// le type enuméré décrivant le type de Pokemon parmis les 18 exietant dans Pokemon Go
typedef enum {Normal, Fighting, Flying, Poison, Ground, Rock, Bug, Ghost, Steel, Fire, Grass, Water, Electric, Psychic, Ice, Dragon, Dark, Fairy} PokemonType;

typedef struct EspecePokemon {
    char* nom;
    PokemonType type;
    int nbBonbonsPourEvoluer;
    char* evolvesTo;
    bool estEvolue;
} EspecePokemon;

#endif /* PokemonTypes_h */
