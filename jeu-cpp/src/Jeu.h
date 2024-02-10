
#ifndef _jeu_h_
#define _jeu_h_

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include "Personnage.h"
#include"Mur.h"
#include"time.h"

#include "Labyrinthe.h"
#include "Cellule.h"

/**
 * @class Jeu
 * @brief Classe qui gère le déroulement du jeu
 *
 * Cette classe gère la logique du jeu, y compris la boucle principale de jeu, la gestion des événements et la mise à jour de l'état du jeu.
 */
class Jeu {
 
public:

    /**
     * @brief Constructeur de la classe Jeu
     */
    Jeu();

    /**
     * @brief Gère la direction du personnage
     * @param ev Événement SDL à gérer
     */
    void choix_dir_perso(SDL_Event ev);

    /**
     * @brief Boucle principale du jeu
     */
    void const Boucle_jeu();

    /**
     * @brief Actualise les murs
     */
    void actualiser_mur();

    /**
     * @brief Vérifie si le personnage est en collision avec un mur
     * @return True si le personnage est en collision avec un mur, false sinon
     */
    bool const check_mur_perso();

    bool  check_etoile_perso();

    /**
     * @brief Convertit les coordonnées du personnage en cellule du labyrinthe
     * @return La cellule correspondante aux coordonnées du personnage
     */
    Cellule const coordPerso_to_Cellule();

    
    int decalage; // incompréhension aussi, la variable est pas utilisée mais si on la supprime plus rien ne marche
    int level; //Je comprends pas ca mdr j'ai l'impression que c'est inutilise mais quand on le retire le jeu marche plus
    int score;
    //Encore plus bizarre, si j'essaie de mettre ces variables au début de public, ca marcche plus non plus
    Labyrinthe laby_suiv;
    Labyrinthe laby;
    Labyrinthe laby_prec;
    Personnage perso;
    Mur mur;

private:

    float vit = 0.4;
    int niveau_actuel = 1;
    int dir_perso = -1;
    int dir_secondaire = -1;

    /**
     * @brief Effectue des tests de régression
     */
    void test_regression();

    /**
     * @brief Actualise l'état du jeu
     */
    void Actualiser();


;

    /**
     * @brief Vérifie si le personnage est bloqué dans une direction donnée
     * @param direction Direction à vérifier
     * @return True si le personnage est bloqué, false sinon
     */
    bool  stop_joueur(int direction);

    /**
     * @brief Vérifie si le personnage est dans le coin supérieur gauche de la carte
     * @return True si le personnage est dans le coin supérieur gauche, false sinon
     */
    bool const check_coin_gauche();

    /**
     * @brief Effectue des tests de régression sur la classe Jeu
     */
    void test_regressionJeu();
       
    /**
     * @brief Modifie le niveau en cours
     */
    
    void modif_niveau();
    /**
     * @return true si le personnage est à la fin du labyrinthe, false sinon
     */
    
    bool perso_end_laby();

    };

#endif