#ifndef _labyrinthe
#define _labyrinthe

#include "Cellule.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include<SDL2/SDL.h>
#include<cassert>

class Labyrinthe{

public:

    /**
     * @brief Constructeur par défaut de la classe Labyrinthe
     */
    Labyrinthe();

    /**
     * @brief Constructeur de la classe Labyrinthe avec paramètres
     * @param entree : l'entrée du labyrinthe
     * @param sortie : la sortie du labyrinthe
     * @param hauteur : la hauteur du labyrinthe
     * @param largeur : la largeur du labyrinthe
     */
    Labyrinthe(int entree,int sortie, int hauteur, int largeur);

    /**
     * @brief Destructeur de la classe Labyrinthe
     */
    ~Labyrinthe();    

    int Larg_Laby; ///< La largeur du labyrinthe
    int Haut_laby; ///< La hauteur du labyrinthe

    int entree; ///< L'entrée du labyrinthe
    int sortie; ///< La sortie du labyrinthe

    /**
     * @brief Création du labyrinthe
     */
    void Creation_Laby();
    
    
    Cellule tab_Grille [50][50]; ///< Tableau de cellules pour le labyrinthe

    /**
     * @brief Affichage du labyrinthe en texte
     */
    void const printLabTexte();

    /**
     * @brief Réinitialisation du labyrinthe
     */
    void labyNnull();


    /**
     * @brief Teste regression de la classe 
     */
    void testreglab();

    private:

    /**
     * @brief Création d'un pattern pour le labyrinthe
     */
    void creationPattern();

    /**
     * @brief Vérification de la terminaison de la création du labyrinthe
     * @return true si la création du labyrinthe est terminée, sinon false
     */
    bool labTermine();

    /**
     * @brief Attribution de valeurs pour chaque cellule du labyrinthe
     */
    void valCellule();

    /**
     * @brief Se charge de repartire les pieces dans le labyrinthe
     */
    void mettre_piece();



    
};

#endif