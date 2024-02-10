#ifndef _cellule
#define _cellule

#include "Piece.h"
/**
 * @class Cellule
 * @brief Classe représentant une cellule dans un labyrinthe.
 * Une cellule est définie par sa position dans le labyrinthe et les murs qui la délimitent.
 */

class Cellule{

    public:

        /**
         * @brief Constructeur par défaut de la classe Cellule.
         * Initialise les murs à true (présents) et la valeur de la cellule à 0.
         */
        Cellule();

        /**
         * @brief Destructeur de la classe Cellule.
         */
        ~Cellule();

        /**
         * @brief Setter pour le mur nord de la cellule.
         * @param no : booléen indiquant la présence (true) ou l'absence (false) du mur nord.
         */
        void setNorth( bool no);

        /**
         * @brief Setter pour le mur sud de la cellule.
         * @param so : booléen indiquant la présence (true) ou l'absence (false) du mur sud.
         */
        void setSouth(const bool so);

        /**
         * @brief Setter pour le mur est de la cellule.
         * @param es : booléen indiquant la présence (true) ou l'absence (false) du mur est.
         */
        void setEst(bool es);

        /**
         * @brief Setter pour le mur ouest de la cellule.
         * @param we : booléen indiquant la présence (true) ou l'absence (false) du mur ouest.
         */
        void setWest(bool we);

        /**
         * @brief Getter pour le mur nord de la cellule.
         * @return un booléen indiquant la présence (true) ou l'absence (false) du mur nord.
         */
        bool getNorth();

        /**
         * @brief Getter pour le mur sud de la cellule.
         * @return un booléen indiquant la présence (true) ou l'absence (false) du mur sud.
         */
        bool getSouth();

        /**
         * @brief Getter pour le mur est de la cellule.
         * @return un booléen indiquant la présence (true) ou l'absence (false) du mur est.
         */
        bool getEst();

        /**
         * @brief Getter pour le mur ouest de la cellule.
         * @return un booléen indiquant la présence (true) ou l'absence (false) du mur ouest.
         */
        bool getWest();

        /**
         * @brief Getter pour la valeur de la cellule.
         * @return un entier représentant la valeur de la cellule.
         */
        int getValeure();

        /**
         * @brief Setter pour la valeur de la cellule.
         * @param val : un entier représentant la valeur à attribuer à la cellule.
         */
        void setValeure(int val);

        /**
         * @brief Setter pour la coordonnée x du coin supérieur gauche de la cellule.
         * @param coinX : un entier non signé représentant la coordonnée x.
         */
        void set_coint_x(int unsigned coinX);
        
        /**
        @brief Définit la position en y du coin de la cellule
        @param coinY La position en y du coin de la cellule
        */
        void set_coint_y(int unsigned coinY);
        
        /**
        @brief Retourne la position en x du coin de la cellule
        @return int La position en x du coin de la cellule
        */
        int get_coint_x();
        
        /**
        @brief Retourne la position en y du coin de la cellule
        @return int La position en y du coin de la cellule
        */
        int get_coint_y();
        
        /**
        @brief Supprime le mur opposé à celui donné en paramètre
        @param direction La direction du mur à supprimer
        */
        void delMurFromDirectionOpo(int direction);
        
        /**
        @brief Supprime le mur dans la direction donnée en paramètre
        @param direction La direction du mur à supprimer
        */
        void delMurFromDirection(int direction);

        /**
        * @brief Indique si la cellule contient une piece ou non
        */
        Piece piece;
        bool piece_test;
        
        void erase_piece();

        private:

        int coin_x, coin_y; /**< Coordonnées x et y de la cellule */
        bool N, S, E, W; /**< Présence ou non d'un mur dans les directions Nord, Sud, Est et Ouest */
        int valeure; /**< Valeur associée à la cellule */

        /**
         * @brief Affiche l'état de la cellule (coordonnées et présence ou non de murs).
         */
        void const afficher_etat_Cellule();

        /**
         * @brief Teste le bon fonctionnement de la classe Cellule.
         */
        void const test_regressionCel();
                                                   
};

#endif