#include <iostream>
#include "Mur.h"
using namespace std;

Mur::Mur(){

    hauteur_mur=0;
    larg_mur=0;
    vitesse_mur=0;
    pos_y=0;
    retard_joueur=0;
}

Mur:: Mur (int largeur, float hauteur, float vitesse,int retard_mur){

    larg_mur=largeur;
    hauteur_mur=hauteur;
    
    retard_joueur=retard_mur;
    
    pos_y=hauteur+retard_joueur;

    vitesse_mur=vitesse;

}

void Mur::TestRegMur(){

    Mur mur=Mur();
    assert(mur.hauteur_mur==0 && mur.larg_mur==0&& mur.vitesse_mur==0&& mur.retard_joueur==0 && mur.pos_y==0);
    mur =Mur(10,10,10,10);
    assert(mur.hauteur_mur==10 && mur.larg_mur==10&& mur.vitesse_mur==10&& mur.retard_joueur==10 && mur.pos_y==0);

}



