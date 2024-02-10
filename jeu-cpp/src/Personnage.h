#ifndef _personnage
#define _personnage

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

class Personnage {

public :

    int pos_x ; ///< La position horizontale du personnage
    int pos_y ; ///< La position verticale du personnage

    int decalage; ///< Le décalage du personnage

    /**
     * @brief Constructeur par défaut
     */
    Personnage();

    /**
     * @brief Constructeur avec des paramètres
     * @param X : la position horizontale initiale du personnage
     * @param Y : la position verticale initiale du personnage
     * @param decal : le décalage du personnage
     */
    Personnage(int X , int Y, int decal);

    /**
     * @brief Destructeur
     */
    ~Personnage();

    /**
     * @brief Déplace le personnage vers la droite
     */
    void deplacer_droite();

    /**
     * @brief Déplace le personnage vers la gauche
     */
    void deplacer_gauche();

    /**
     * @brief Déplace le personnage vers le haut
     */
    void deplacer_haut();

    /**
     * @brief Déplace le personnage vers le bas
     */
    void deplacer_bas();

    /**
     * @brief Choix de déplacement pour le personnage
     * @param choix : le choix de déplacement du personnage
     * @param collision : indique si le personnage est en collision
     */
    void choix_deplacement_personnage(int choix, bool collision);
 

    /**
     * @brief Test de régression pour le personnage
     */
    void test_regressionPer();

    SDL_Surface* imageSurface; ///< La surface de l'image du personnage
    SDL_Texture * Texture; ///< La texture du personnage 
    SDL_Rect rect; ///< Le rectangle SDL du personnage
};

#endif