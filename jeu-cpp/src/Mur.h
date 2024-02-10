#ifndef _mur
#define _mur
#include<iostream>
#include<cassert>


class Mur {

public:
    
    /**
     * @brief Constructeur de la classe Mur avec paramètres
     * @param largeur : la largeur du mur
     * @param hauteur : la hauteur du mur
     * @param vitesse : la vitesse de déplacement du mur
     * @param retard_mur : le temps de retard du mur avant de commencer à se déplacer
     */
    Mur (int largeur, float hauteur, float vitesse,int retard_mur);

    /**
     * @brief Constructeur de la classe Mur par défaut
     */
    Mur();


    /**
     * @brief Cest de regressionde la classe 
     */
    void TestRegMur();

    
    int larg_mur; ///< La largeur du mur
    float hauteur_mur; ///< La hauteur du mur
    int vitesse_mur; ///< La vitesse de déplacement du mur

    int couleur_mur; ///< La couleur du mur
    int transparence_couleur; ///< La transparence de la couleur du mur

    int retard_joueur; ///< Le temps de retard pour que le joueur puisse éviter le mur

    float pos_y; ///< La position verticale du mur

};

#endif