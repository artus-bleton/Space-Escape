#include "Cellule.h"
#include <cassert>
#include <iostream>
#include <stdlib.h> 

using namespace std;

Cellule::Cellule(){

    setNorth(true);
    setSouth(true);
    setEst(true);
    setWest(true);
    coin_x=0;
    coin_y=0;
    piece=Piece();
    piece_test=false;
}

Cellule::~Cellule(){

    setNorth(false);
    setSouth(false);
    setEst(false);
    setWest(false);
}

void Cellule::setNorth(bool no){N = no;}
void Cellule::setSouth(bool so){S = so;}
void Cellule::setWest(bool we){W = we;}
void Cellule::setEst(bool es){E = es;}

bool Cellule::getNorth(){return N;}
bool Cellule::getSouth(){return S;}
bool Cellule::getEst(){return E;}
bool Cellule::getWest(){return W;}


int Cellule::getValeure(){
    return valeure;

}

void Cellule::setValeure(int val){
    valeure = val;
}

void Cellule::set_coint_x(int unsigned coinX){
    coin_x = coinX;
}

void Cellule::set_coint_y(int unsigned coinY){
    coin_y = coinY;
}

int Cellule::get_coint_x(){
    return coin_x+100;
}

int Cellule::get_coint_y(){
    return coin_y+100;
}

void Cellule::delMurFromDirection(int dir){

    if (dir == 0){setNorth(false);}
    if (dir == 1){setSouth(false);}
    if (dir == 2){setEst(false);}
    if (dir == 3){setWest(false);}
}

void Cellule::delMurFromDirectionOpo(int dir){

    if (dir == 0){setSouth(false);}
    if (dir == 1){setNorth(false);}
    if (dir == 2){setWest(false);}
    if (dir == 3){setEst(false);}
}

void const Cellule::afficher_etat_Cellule(){
    cout<<"N : "<<N<<endl;
    cout<<"S : "<<S<<endl;
    cout<<"E : "<<E<<endl;
    cout<<"W : "<<W<<endl<<endl;
}

void const Cellule::test_regressionCel() {
    
    // Test du constructeur et des méthodes d'accès aux directions
    Cellule c;
    assert(c.getNorth() == true);
    assert(c.getSouth() == true);
    assert(c.getEst() == true);
    assert(c.getWest() == true);
    
    // Test de la méthode setValeure
    c.setValeure(42);
    assert(c.getValeure() == 42);

    // Test de la méthode set_coint_x
    c.set_coint_x(10);
    assert(c.get_coint_x() == 10);

    // Test de la méthode set_coint_y
    c.set_coint_y(20);
    assert(c.get_coint_y() == 20);

    // Test de la méthode delMurFromDirection
    c.delMurFromDirection(0); // Supprime le mur nord
    assert(c.getNorth() == false);
    
    // Test de la méthode delMurFromDirectionOpo
    c.delMurFromDirectionOpo(1); // Supprime le mur nord
    assert(c.getNorth() == false);

    // Test de la méthode afficher_etat_Cellule
    cout << "Affichage de l'état de la cellule : " << endl;
    c.afficher_etat_Cellule();

    // Test du destructeur
    c.~Cellule();
    assert(c.getNorth() == false);
    assert(c.getSouth() == false);
    assert(c.getEst() == false);
    assert(c.getWest() == false);

    cout << "Tous les tests ont été effectués avec succès !" << endl;
}

void Cellule::erase_piece(){

    piece_test=false;
}