#include "pokedex.h"

#include <string>
#include <iostream>
#include "utils.h"

using namespace std;

// inclure stdlib si vous procéder l'allocation dynamique avec malloc.
// #include <stdlib.h>


// allocation dynamique de "size" pokemons
Pokedex* initPokedex(const int size) {

    // allocation dynamique en C++ de la structure.
    Pokedex* pokedex = new Pokedex;

    // Alernative en C pour vous montrer les deux
    // Pokedex* pokedex = (Pokedex*)malloc (sizeof(Pokedex));

    pokedex->capacity = size; // ou encore (*pokedex).capacity = size;
    pokedex->nbPokemons = 0;

    pokedex->mesPokemons = new Pokemon[size];

    return pokedex;
}

// insère un pokemon a sa place dans le tableau afin de le
// maintenir trié. Le critère de tri est le nom du pokemon.
// Le pokedex est passé comme un pointeur vers un pointeur de pokedex.
// Pourquoi ?
// Si on passe seulement un pointeur vers le pokedex, le contenu du
// pointeur vers le pokedex est perdu ! (cela reste un passage de
// parametre par valeur (du pointeur).
void insertPokemon(Pokedex** monPokedex, Pokemon p) {

    // on réalise un déréfencement une fois pour toutes, le reste
    // du code de cette fonction devient plus lisible.
    Pokedex* pokedex = *monPokedex;

    // 1- A-t-on assez de place dans la tabeau dynamique ?
    if (pokedex->capacity == pokedex->nbPokemons) {

        // le tableau dynamique est plein,
        // on va commencer par l'aggrandir de 50% de sa capacité
        Pokedex* newpokedex = initPokedex((int) (pokedex->capacity*1.5));
        for (int i =0; i < pokedex->nbPokemons; i++) {
            newpokedex->mesPokemons[i] = pokedex->mesPokemons[i];
        }
        newpokedex->nbPokemons = pokedex->nbPokemons;


        // le pokedex devient celui nouvellement construit contenant les anciens pokemons.
        *monPokedex = newpokedex;
        pokedex = newpokedex;

    }

    // 2- on cherche l'index auquel nous allons insérer ce
    // nouveau pokemon, au regard de son nom (tri par ordre
    // croissant des noms de pokemon).
    if (pokedex->nbPokemons == 0) {
        pokedex->mesPokemons[0] = p;
    } else {
        // au moins un pokemon, cherchons la position du
        // nouveau pokemon.
        int i = 0;
        while (i < pokedex->nbPokemons && strcmp(pokedex->mesPokemons[i].nom, p.nom) < 0) {
            i++;
        }

        // on quitte la boucle car il faut l'insérer à la fin, ou en cours de tableau
        // suivant si on a quitté car i == pokedex->nbPokemons ou si on a trouvé un pokemon
        // après le pokemon $p$ dnas l'ordre alphabétique.
        if (i == pokedex->nbPokemons) {
            pokedex->mesPokemons[i] = p;
        } else {
            // il faut décaler les pokemons du sous tableau partant de la droite du
            // tbaleau afin d'y faire un trou dans le tableau et y placr notre pokemon.
            // Voir principe du tri par insertion vu en module BCD algorithmie.
            for (int k = pokedex->nbPokemons-1; k >= i; k--) {
                pokedex->mesPokemons[k+1] = pokedex->mesPokemons[k];
            }
            pokedex->mesPokemons[i] = p;
        }
    }

    pokedex->nbPokemons = pokedex->nbPokemons +1;
}

void displayPokedex(Pokedex* pokedex, EspecePokemon bestiaire[150], char* typesLabel[18], const Ressources ressources) {
    cout << "Mes ressources : " << "\t " << ressources.candies << " bonbons \t" << ressources.stardust << " poussières" << endl << endl;
    cout << endl << "Contenu du pokedex (Actuellement " << pokedex->nbPokemons << " pokemons capturés)" << endl;
    for (int i = 0; i < pokedex->nbPokemons; i++) {
        cout << i << " : " ;
        display(pokedex->mesPokemons[i], bestiaire, typesLabel);
    }
}


Pokemon* genererPokemon(EspecePokemon bestiaire[150], char* typesLabel[18]) {
    Pokemon* p = new Pokemon;

    EspecePokemon e = bestiaire[random_at_most(149)];
    while (e.estEvolue != 0) {
        e = bestiaire[random_at_most(149)];
    }
    p->nom = e.nom;
    p->xp = 0;
    p->cp = 200 + (int)random_at_most(800); // un nombre de cp dans [200;1000]
    p->pv = 30 + (int)random_at_most(470); // un nombre de PV dans [30;500]
    return p;
}






