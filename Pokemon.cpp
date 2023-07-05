//
//  pokemon.cpp
//  AlgoFISE1
//
//  Created by Christophe Gravier on 08/09/16.
//  Copyright � 2016 Christophe Gravier. All rights reserved.

#include "pokemon.h"
#include <iostream>
using namespace std;

void evolve(Pokemon* p, char* nextEvolution) {

    char* oldName = p->nom;
    p->nom = nextEvolution;
    p->evolution = p->evolution+1;
    cout << endl << "F�licitations, votre " << oldName << " est devenu un " << nextEvolution << " ! " << endl << endl;
}

void powerup(Pokemon* p) {
    p->cp = (int) p->cp * 1.25
    cout << "F�licitations, votre " << p->nom << " a progress� et gagn� 25% de ses points de combats, une v�ritable armoire �
    glace ! ";
}

void display(const Pokemon p, EspecePokemon bestiaire[150], char* typesLabel[18]) {

    cout << p.nom;

    // SEANCE 2 : on r�cup�re l'espece du pokemon associer en recherchant dans le bestiaire.
    EspecePokemon esp = lookupEspecePokemon(bestiaire, p.nom);
    cout << "  | ";
    cout << typesLabel[esp.type];
    cout << " | ";
    // END AJOUT SEANCE 2

    cout << "  (Evolution : " << p.evolution << ")" << endl;
    cout << "PV : " << p.pv << "   |   XP : " << p.xp << "   |   CP " << p.cp << endl;

    cout << endl;
}
