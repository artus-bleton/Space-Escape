
#ifndef _affichage_h_
#define _affichage_h_

#include "Jeu.h"
#include "Mur.h"
#include "Piece.h"
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include<SDL2/SDL_mixer.h>
#include<time.h>

/**
 * @class Affichage
 * @brief Classe qui gère l'affichage graphique du jeu.
 *
 * Cette classe permet de créer une fenêtre, d'afficher un labyrinthe ainsi que les cellules le constituant,
 * de rafraîchir l'affichage et de détruire la fenêtre à la fin de la partie.
 */

class Affichage{
    
    public:

    /**
     * @brief Constructeur par défaut de la classe Affichage.
     *
     * Initialise les variables membres.
     */
    Affichage();

    /**
     * @brief Afficher le menu de demarrage
     *
     * 
     */
    
    void Menu();

    void Demarrage();


   /**
     * @brief Détruit la fenêtre.
     *
     * Cette fonction détruit la fenêtre et libère la mémoire allouée pour les surfaces et textures associées.
     */
    void destructionJeu();

    void LancerJeu();

 
    Jeu Game; // instance du jeu en cours

    int Largeur_fenetre; // largeur de la fenêtre en pixels
    int Hauteur_fenetre; // hauteur de la fenêtre en pixels
    
    /**
     * @brief Initialise la fenêtre et effectue les premiers affichages.
     *
     * Cette fonction crée une fenêtre de la taille voulue, la rend visible et affiche le titre du jeu ainsi qu'une image.
     */
    void  Initialisation_Jeu();
    
    /**
     * @brief Cycle de vie de la fenêtre.
     *
     * Cette fonction contient la boucle principale qui permet de garder la fenêtre ouverte et d'afficher le jeu en continu.
     */
    void BoucleRunFenetre();

 

    /**
     * @brief Actualise l'affichage.
     *
     * Cette fonction rafraîchit l'affichage en recréant la texture de la fenêtre à partir de sa surface et en l'affichant sur l'écran.
     */
    void Actualiser_Affichage();

    void Didactitiel();

    /**
     * @brief Affiche le labyrinthe.
     *
     * Cette fonction affiche un labyrinthe à l'écran en parcourant toutes les cellules qui le composent.
     *
     * @param Laby Le labyrinthe à afficher.
     * @param decalage Le décalage à appliquer pour centrer le labyrinthe sur l'écran.
     */
    void const AfficherLab(Labyrinthe const & Laby, int const & decalage);

    /**
     * @brief Affiche une cellule.
     *
     * Cette fonction affiche une cellule à l'écran en dessinant ses murs et en ajoutant des couleurs en fonction de sa valeur.
     *
     * @param pos_x La position en abscisse de la cellule.
     * @param pos_y La position en ordonnée de la cellule.
     * @param cell La cellule à afficher.
     * @param long_cell La longueur de la cellule en pixels.
     * @param larg_cell La largeur de la cellule en pixels.
     */
    void AfficherCell(int pos_x, int pos_y, Cellule cell, int long_cell, int larg_cell);

    /** @brief Affiche un mur dans la fenêtre.
     * @param mur Le mur à afficher.
     */
    void const affiche_mur(Mur const & mur);


      /**
     * @brief Affiche le pieces.
     *
     * Cette fonction affiche les pieces à l'écran
     *
     * @param pos_x La position en abscisse de la piece.
     * @param pos_y La position en ordonnée de la piece.
     * @param cell La piece à afficher.
     * @param long_cell La longueur de la piece en pixels.
     * @param larg_cell La largeur de la piece en pixels.
    
     */
    void Afficher_piece(int pos_x,  int  pos_y , Cellule cell, int long_piece, int larg_piece);

    /**
     * @brief Actualise l'affichage du personnage
     * @param renderer : le renderer de la fenêtre SDL
     */
    void charger_perso();

    /**
     * @brief Teste la fonctionnalité d'affichage.
     */
    void test_regressionAff();
    /**
     * @brief Affiche le score en fin de partie.
     */
    void tab_score(int score);


      /**
     * @brief Detruit les pointeurs utilisés dans le menu
     */
    void detruire_menu();


    /**
     * @brief Pointeur vers la fenêtre.
     */
    SDL_Window * window ;

    /**
     * @brief Pointeur vers le renderer pour la fenêtre.
     */
    SDL_Renderer * renderer ;

    /**
     * @brief Surface de la fenêtre.
     */
    SDL_Surface * Image_Fenetre;

    /**
     * @brief Texture de la fenêtre.
     */
    SDL_Texture * Texture_Fenetre;

    /**
     * @brief Rectangle pour la fenêtre.
     */
    SDL_Rect rect_fenetre;
    /**
     * @brief Variable pour determiner la police des ecritures.
     */
    
    private:
    SDL_Rect jouerButton;
    SDL_Surface* jouerTextSurface;
    SDL_Texture* jouerTextTexture;
    SDL_Rect jouerText;

    SDL_Rect quitterButton;
    SDL_Surface* quitterTextSurface;
    SDL_Texture* quitterTextTexture;
    SDL_Rect quitterText;
    
    SDL_Rect didactitielButton;
    SDL_Surface* didactitielTextSurface;
    SDL_Texture* didactitielTextTexture;
    SDL_Rect didactitielText;

    SDL_Texture * Texture;
    SDL_Surface * imageSurface;




};

#endif