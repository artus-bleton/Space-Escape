#include "Personnage.h"

#include <iostream>
#include<cassert>

using namespace std ;


Personnage::Personnage(){

    pos_x = 0 ;
    pos_y = 0 ;
}

Personnage::Personnage(int X ,int Y, int decal){
     
    pos_x = X ;
    pos_y = Y ;
    // ajouter les assert faut que la coordonne soit dans la labyrinte exemple 200 * 200 pixel
    
    decalage=decal; //Point de depart du Labyrinthe, plus le laby est long, plus cette valeur est grande !!!
}

Personnage::~Personnage(){

    pos_x = 0 ;  // ca revient a supprimer le Perso quand il meurt
    pos_y = 0 ;  // coordonne a revoir selon la labyrinte
}



//J'ai tenté une collision et je pense que c'est mieux de gerer cet aspect du jeu dans la classe Jeu

void Personnage::deplacer_droite(){
    pos_x ++;

    
}

void Personnage::deplacer_gauche(){

    pos_x--;
    
}

void Personnage::deplacer_haut(){

    pos_y-- ;
    
    decalage--;
}

void Personnage::deplacer_bas(){
    
    pos_y++ ;
    
    decalage++;
}


void Personnage::choix_deplacement_personnage(int choix, bool collision){

    if (choix == 0 && collision){
        deplacer_haut();
    }
    if (choix == 1 && collision){
        deplacer_bas();
    }
    if (choix == 2 && collision){
        deplacer_droite();
    }
    if (choix == 3 && collision){
        deplacer_gauche();
    }
}



void Personnage::test_regressionPer(){
    
    // test constructeur par défaut
    Personnage p1;
    assert(p1.pos_x == 0 && p1.pos_y == 0);

    // test constructeur avec paramètres
    Personnage p2(10, 20, 0);
    assert(p2.pos_x == 10 && p2.pos_y == 20);

    // test déplacement vers la droite
    p1.deplacer_droite();
    assert(p1.pos_x == 1 && p1.pos_y == 0);

    // test déplacement vers la gauche
    p1.deplacer_gauche();
    assert(p1.pos_x == 0 && p1.pos_y == 0);

    // test déplacement vers le haut
    p1.deplacer_haut();
    assert(p1.pos_x == 0 && p1.pos_y == -1);

    // test déplacement vers le bas
    p1.deplacer_bas();
    assert(p1.pos_x == 0 && p1.pos_y == 0);

    // test choix de déplacement du personnage
    p1.choix_deplacement_personnage(0, true);
    assert(p1.pos_x == 0 && p1.pos_y == -1);

    cout<<"Les fonctions sont operationnelles"<<endl;

    //ajouter les test concernant sdl
}


 


