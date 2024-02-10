#include"Jeu.h"
#include <unistd.h> 

#include <iostream>
using namespace std;

//ON PEUT UTILISER CETTE VALEURE POUR LA VITESSE DU MUR, MAIS JE COMPRENDS TOUJOURS PAS POURQUOI CA MARCHE PAS AVEC MUR.VITESSE


Jeu::Jeu(){

      
    srand((unsigned int)time(NULL));

    int entree= rand() % 8;
    int sortie= rand() % 8;
    int sortie_suiv = rand() % 8;

    laby_prec=Labyrinthe(0,0,1,8);

    laby= Labyrinthe(entree,sortie,8,8);
    laby_suiv = Labyrinthe(sortie,sortie_suiv,8,8);

    perso = Personnage((entree*100) +50,(laby.Haut_laby*100)-50, 250 + (laby.Haut_laby - 8)*100);   // Ces coordonnées sont utilisées pour les collision

    //Le delta minimum avec le perso est -150
    mur = Mur ((laby.Larg_Laby+1)*100,(laby.Haut_laby+1)*100,0,400);

}
 

void Jeu::choix_dir_perso(SDL_Event ev){

    if (ev.key.keysym.sym == SDLK_q){
        dir_secondaire=  3;
    }
    if (ev.key.keysym.sym == SDLK_s ){
        dir_secondaire = 1;
    }
    if(ev.key.keysym.sym == SDLK_d  ){
        dir_secondaire = 2;
    }
    if (ev.key.keysym.sym == SDLK_z ){
        dir_secondaire = 0;
    }  
}


Cellule const Jeu::coordPerso_to_Cellule(){

    return laby.tab_Grille[(perso.pos_y -50) / 100][(perso.pos_x -50) / 100];
}

bool Jeu::stop_joueur(int direction){
    
    Cellule Cell =coordPerso_to_Cellule();
    if (check_coin_gauche()){

        if ((Cell.getNorth() == true) && (direction == 0) ){
            return false;
        }
        if ((Cell.getSouth() == true) && (direction == 1) ){
            return false;
        }
        if (( Cell.getEst() == true) && (direction == 2)) {
            return false;
        }
        if (( Cell.getWest() == true) &&  (direction == 3)){
            return false;
        }
        else{
            return true;
        }
    }
    return true;
    
}


bool const Jeu::check_coin_gauche(){
    
    //return True si le perso est bien placé (aligné dans la cellule)
    return ((perso.pos_x)%50==0 ) && ((perso.pos_y)%50==0) && ((perso.pos_y+100)%100!=0) && ((perso.pos_x+100)%100!=0) ;
 
}


void const Jeu::Boucle_jeu(){
/*
    cout<<"niveau actuel : "<<niveau_actuel<<endl<<"Retard du mur : "<<perso.pos_y - mur.pos_y<<endl<<endl;
*/

    if ((stop_joueur(dir_secondaire)==false)||(check_coin_gauche())){ 
        
                        dir_perso = dir_secondaire;
    }

    perso.choix_deplacement_personnage(dir_perso, stop_joueur(dir_perso));
    actualiser_mur();
    if(perso_end_laby()){modif_niveau();}


}

void Jeu::test_regressionJeu(){ 
        

} 

void Jeu::actualiser_mur(){
    
    mur.pos_y -=  vit;
    mur.hauteur_mur += vit;
}

bool const Jeu::check_mur_perso(){

    return( mur.pos_y <= perso.pos_y);
    
}

bool Jeu:: perso_end_laby(){

    return (perso.pos_y==-50 && (perso.pos_x-50)/100==laby.sortie);
}


void Jeu::modif_niveau(){

    cout<<"Changement de niveau"<<endl;
    niveau_actuel += 1;
    score+=20;
    int sortie=rand() % 8;
    int entree=laby.sortie;
                                                        
    laby_prec = laby;
    laby = laby_suiv;
    laby_suiv = Labyrinthe(laby.sortie,sortie,8 ,8);         //Crée le nouveau laby 
    int pos_x_joueur=(laby.Haut_laby*100)-50;

    mur = Mur ((laby.Larg_Laby+1)*100,mur.pos_y + 800 ,0.1,0);
    perso = Personnage(entree*100+50,pos_x_joueur, 250 + (laby.Haut_laby - 8)*100);
}


bool Jeu::check_etoile_perso(){
   
    if(coordPerso_to_Cellule().piece_test){
        
        cout<<coordPerso_to_Cellule().piece_test<<endl;
        cout<<score<<endl;
        score=score+10;
        laby.tab_Grille[(perso.pos_y -50) / 100][(perso.pos_x -50) / 100].piece_test=false;
        return true;
        }
    
    else {return false;}

}