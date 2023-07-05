
//
//  main.cpp
//  AlgoFISE1
//
//  Created by Christophe Gravier on 08/09/16.
//  Copyright © 2016 Christophe Gravier. All rights reserved.
//

#include <iostream>
#include "pokemon.h"
#include "bestiaire.h"
#include "pokedex.h"
#include "utils.h"
#include "ressources.h"

using namespace std;

void printMenu() {
    cout << endl << endl;;
    cout << " 1 - Index des Pokemons" << endl;
    cout << " 2 - Mon Pokedex" << endl;
    cout << " 3 - Attraper un Pokemon" << endl;
    cout << " 4 - Power-up et évolution" << endl;
    cout << " 5 - Combat" << endl;
    cout << " 6 - Quitter" << endl;
}

void powerupAndEvolution(Pokedex* pokedex,EspecePokemon bestiaire[150], Ressources &ressources) {
    int newchoice = 0;
    int idPokemon = -1;
    do {
        cout << "Choisir l'identifiant du pokemon à faire évoluer ou progresser." << endl;
        cin >> idPokemon;
    } while (idPokemon < 0);


    // récupérons le pointeur vers le pokemon que l'on souhaite modifier.
    Pokemon* p = &(pokedex->mesPokemons[idPokemon]);

    cout << "Choisir l'action à réaliser : " << endl;
    cout << " 1 - Powerup" << endl;
    cout << " 2 - Evolution" << endl;
    cout << " 3 - Retour au menu principal" << endl;

    do {
        cin >> newchoice;
        if (newchoice !=1 && newchoice != 2 && newchoice !=3) {
            cout << "mauvais choix, saisir 1, 2 ou 3";
        }
    }
    while (newchoice !=1 && newchoice != 2 && newchoice !=3);


    if (newchoice == 1) {
        if (ressources.candies >= 10 && ressources.stardust >= 500) {
            ressources.candies = ressources.candies - 10;
            ressources.stardust = ressources.stardust - 500;
            powerup(p);
        } else {
            cout << "Power-up impossible : 10 bonbons et 500 poussières sont nécessaires. Peut être devriez-vous attraper plus de pokemons !";
        }
    } else if (newchoice == 2) {

            // retrouver l'espece de pokemon du pokemon p. Il est pertinent de penser à externaliser cette recherche dans une fonction "rechercheEspece"
            // avec le bestiaire et le pokemon à chercher dans le fichier bestiaire par exemple.
            int i = 0;
            while (i < 150 && strcmp(p->nom, bestiaire[i].nom) != 0) {
                i++;
            }

            // identifier le nom de l'espece vers laquelle le pokemon evolue
            char* nextEvolution = bestiaire[i].evolvesTo;

            // connaitre le nombre de bonbons nécessaires pour cette évolution
            int nbBonbonsNecessaires = bestiaire[i].nbBonbonsPourEvoluer;

        if (nextEvolution == nullptr) {
            cout << "Evolution impossible: le pokemon est déjà dans sa dernière évolution !";
        } else {
            if (ressources.candies < nbBonbonsNecessaires) {
                cout << "Evolution impossible : "<< nbBonbonsNecessaires << " bonbons sont nécessaires. Peut être devriez-vous attraper plus de pokemons !";
            }
            else {
                ressources.candies = ressources.candies - nbBonbonsNecessaires;
                evolve(p, nextEvolution);
            }
        }
    }
}

int main(int argc, const char * argv[]) {

    EspecePokemon bestiaire[150];
    initBestiaire(bestiaire);

    // initialisation des ressources diponibles
    Ressources ressources;

    // quelques ressources pour démarrer le jeu
    ressources.stardust = 1000;
    ressources.candies = 100;

    char* typesLabel[18] = {"Normal", "Fighting", "Flying", "Poison", "Ground", "Rock", "Bug", "Ghost", "Steel", "Fire", "Grass", "Water", "Electric", "Psychic", "Ice", "Dragon", "Dark", "Fairy"};

    Pokedex* pokedex = initPokedex(3);
    Pokemon a;
    a.nom = "Seadra";
    a.xp = 1;
    a.cp = 4;
    a.evolution = 1;
    a.pv = 23;

    Pokemon b;
    b.nom = "Arbok";
    b.xp = 0;
    b.cp = 123;
    b.evolution = 2;
    b.pv = 134;

    Pokemon c;
    c.nom = "Zubat";
    c.xp = 40;
    c.cp = 300;
    c.evolution = 1;
    c.pv = 223;

    Pokemon d;
    d.nom = "Paras";
    d.xp = 0;
    d.cp = 23;
    d.evolution = 1;
    d.pv = 90;

    Pokemon e;
    e.nom = "Arkanine";
    e.xp = 0;
    e.cp = 23;
    e.evolution = 2;
    e.pv = 290;

    insertPokemon(&pokedex, a);
    cout << "******* Pokedex after inserting pokemon a *********" << endl;
    displayPokedex(pokedex, bestiaire, typesLabel, ressources);
    cout << "***************************************************" << endl << endl << endl;

    insertPokemon(&pokedex, b);
    cout << "******* Pokedex after inserting pokemon b *********" << endl;
    displayPokedex(pokedex, bestiaire, typesLabel, ressources);
    cout << "***************************************************" << endl << endl << endl;

    insertPokemon(&pokedex, c);
    cout << "******* Pokedex after inserting pokemon c *********" << endl;
    displayPokedex(pokedex, bestiaire, typesLabel, ressources);
    cout << "***************************************************" << endl << endl << endl;

    insertPokemon(&pokedex, d);
    cout << "******* Pokedex after inserting pokemon d *********" << endl;
    displayPokedex(pokedex, bestiaire, typesLabel, ressources);
    cout << "***************************************************" << endl << endl << endl;

    insertPokemon(&pokedex, e);
    cout << "******* Pokedex after inserting pokemon e *********" << endl;
    displayPokedex(pokedex, bestiaire, typesLabel, ressources);
    cout << "***************************************************" << endl << endl << endl;

    int choice = 6;

    cout << "                                   .::.                            " << endl;
    cout << "                                 .;:**'                            "<<endl;
    cout << "                                 `                                 "<<endl;
    cout << "     .:XHHHHk.              db.   .;;.     dH  MX                  "<<endl;
    cout << "   oMMMMMMMMMMM       ~MM  dMMP :MMMMMR   MMM  MR      ~MRMN       "<<endl;
    cout << "   QMMMMMb  \"MMX       MMMMMMP !MX' :M~   MMM MMM  .oo. XMMM 'MMM  "<<endl;
    cout << "     `MMMM.  )M> :X!Hk. MMMM   XMM.o\"  .  MMMMMMM X?XMMM MMM>!MMP  "<<endl;
    cout << "      'MMMb.dM! XM M'?M MMMMMX.`MMMMMMMM~ MM MMM XM `\" MX MMXXMM   "<<endl;
    cout << "       ~MMMMM~ XMM. .XM XM`\"MMMb.~*?**~ .MMX M t MMbooMM XMMMMMP   "<<endl;
    cout << "        ?MMM>  YMMMMMM! MM   `?MMRb.    `\"\"\"   !L\"MMMMM XM IMMM    "<<endl;
    cout << "         MMMX   \"MMMM\"  MM       ~%:           !Mh.\"\"\" dMI IMMP    "<<endl;
    cout << "         'MMM.                                             IMX     "<<endl;
    cout << "          ~M!M                                             IMP     "<<endl << endl;
    cout << "                            - TSE EDITION -                        "<<endl;

    printMenu();


    do {
    cin >> choice;
    switch(choice) {
            case 1 : {
                int chx = 0;
                do {
                    cout << " 1 - Tri naturel "<< endl << " 2 - Tri par nom " << endl;
                    cin >> chx;
                } while (chx != 1 && chx != 2);
                if (chx == 1) {
                    afficheBestiaire(bestiaire);
                } else {
                    afficheBestiaireTrie(bestiaire);
                }
                break;
            }
            case 2 :
                displayPokedex(pokedex, bestiaire, typesLabel, ressources);
                break;
            case 3 : {
                int catchchoice = 3;
                do {
                    Pokemon* p = genererPokemon(bestiaire, typesLabel);
                    cout << endl << "\tVous apercevez le pokemon sauvage suivant : " << endl << endl;
                    display(*p,bestiaire, typesLabel);
                    cout << endl << "\tQue souhaitez-vous faire ? " << endl;
                    cout << "\t 1- Tenter de le capturer" << endl;

                    cout << "\t 2- Laisser ce pokemon vivre sa vie en plein air.";
                    cout << "Regardons s'il n'y en aurait pas d'autres aux alentours ..." << endl;
                    cout << "\t 3- Ne plus attraper de pokemon." << endl;
                    cin >> catchchoice;

                    if (catchchoice == 1) {
                        if ((int)(random_at_most(100)) >= 70) {
                            cout << "\t Vous avez capturé ce pokemon, hell yeah !" << endl << endl;
                            insertPokemon(&pokedex, *p);

                            //mise à jour des ressources
                            ressources.stardust = ressources.stardust + 100;
                            ressources.candies = ressources.candies + 3;
                        } else {
                            cout << "\t Le pokemon s'est échappé ! " << endl << endl;
                        }

                        catchchoice = 3;
                        cout << "\tVoulez-vous continuer à attraper des pokemons ?"<< endl;
                        cout << "\t 1 - Oui" << endl;
                        cout << "\t 2 - Non" << endl;
                        cin >> catchchoice;
                        if (catchchoice == 2) {
                            catchchoice = 3; // forcer le fait de sortir du menu après une capture
                        }

                    }
                } while (catchchoice != 3);
                break;
            }
            case 4 :
            cout << "Voici le contenu de votre pokedex : " << endl << endl;
                displayPokedex(pokedex, bestiaire, typesLabel, ressources);
                powerupAndEvolution(pokedex, bestiaire, ressources);
                break;
            case 5 :
                break;
            case 6 :
                std::cout << "Good bye, we will catch 'em all later!\n";
                return 0;
            default :
                cout << "Veuillez saisir une entrée entre 1 et 6.";
                break;
        }
        printMenu();
    } while (choice != 6);

    std::cout << "Good bye, we will ctach 'em all later!\n";
    return 0;
}
