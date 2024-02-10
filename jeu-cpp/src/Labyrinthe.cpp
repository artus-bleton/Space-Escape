#include "Labyrinthe.h"



using namespace std;
// J'ai mis des constantes car on utilise ces variables afin de crée le tableau de cellule
//Ça marche pas sinon
//C'est juste pour pouvoir essayer differentes tailles differentes 


Labyrinthe::Labyrinthe(){

    entree = 0;
    sortie = 0;

    Haut_laby=8;
    Larg_Laby=8;

    tab_Grille[0][sortie].setNorth(false);
    tab_Grille[Haut_laby-1][entree].setSouth(false);

    // Mise en place des valeures dans les cellules : 
    valCellule();

    creationPattern();

    mettre_piece();

}


Labyrinthe::Labyrinthe(int in, int out, int hauteur, int largeur){

    srand((unsigned int)time(NULL));

    Haut_laby = hauteur;
    Larg_Laby = largeur;
    
    sortie=out;
    entree=in;

    tab_Grille[0][out].setNorth(false);
    tab_Grille[Haut_laby-1][in].setSouth(false);

    // Mise en place des valeures dans les cellules : 
    valCellule();

    creationPattern();

    mettre_piece();
    
}

Labyrinthe::~Labyrinthe(){
    entree = 0;
    sortie = 0;

}



void Labyrinthe::creationPattern(){

    bool cond = false;
    while(cond == false){
        //choix d'une cellule aleatoire

        int aleaI = rand() % Haut_laby;
        int aleaJ = rand() % Larg_Laby;


        //choix d'une direction :  N=0 , S=1, E=2, W=3
        int direction = rand() % 4;

        while(((aleaI == 0) && (direction == 0)) || ((aleaI == Haut_laby-1) && (direction == 1)) || 
                ((aleaJ == 0) && (direction == 3)) || ((aleaJ == Larg_Laby-1) && (direction == 2))){
                    direction = (direction + 1) % 4;
                }

        //Propagation de la valeure :
        //prendre les deux valeures :  N=0 , S=1, E=2, W=3
        int valeure_a_copier = tab_Grille[aleaI][aleaJ].getValeure();
        int valeure_a_remplacer;
        int newI, newJ;

        if(direction == 0){
            newI = aleaI - 1;
            newJ = aleaJ;
        }
        if(direction == 1){
            newI = aleaI + 1;
            newJ = aleaJ;
        }
        if(direction == 2){
            newJ = aleaJ + 1;
            newI = aleaI;
        }
        
        if(direction == 3){
            newJ = aleaJ - 1;
            newI = aleaI;
        }
        
        valeure_a_remplacer = tab_Grille[newI][newJ].getValeure();

        if(valeure_a_remplacer != valeure_a_copier){
            tab_Grille[newI][newJ].delMurFromDirectionOpo(direction);
            tab_Grille[aleaI][aleaJ].delMurFromDirection(direction);
        }
        
        //remplacer toutes les valeures
        for (int i = 0; i<Haut_laby; i++){
            for(int j = 0; j < Larg_Laby; j++){
                
                if(tab_Grille[i][j].getValeure() == valeure_a_remplacer){
                    tab_Grille[i][j].setValeure(valeure_a_copier);

                }
            }
        } 

        cond = labTermine();
        
    }

}

bool Labyrinthe::labTermine(){
    
    int termine = true;
    for (int i = 0; i<Haut_laby; i++){
        for(int j = 0; j < Larg_Laby; j++){

            if(tab_Grille[0][0].getValeure() != tab_Grille[i][j].getValeure()){
                termine = false;
            }
        }
    }
    return termine;
}

void Labyrinthe::valCellule(){

    int val = 0;
    for (int i = 0; i<Haut_laby; i++){
        for(int j = 0; j < Larg_Laby; j++){

            tab_Grille[i][j].setValeure(val);
            val++;
        }
    }
}



void const  Labyrinthe::printLabTexte()
{   // affichage pour chaque ligne
    for (int i = 0; i < Haut_laby; i++) {
        
        // Affiche les murs du haut
        for (int j = 0; j < Larg_Laby; j++) {
            if (tab_Grille[i][j].getNorth()) {
                cout << "+---";
            } else {
                cout << "+   ";
            }
        }
        cout << "+" << endl;
        
        // Afficher les murs des coté et les valeurs de la cellule
        for (int j = 0; j < Larg_Laby; j++) {
            if (tab_Grille[i][j].getWest()) {
                cout << "| ";
            } else {
                cout << "  ";
            }
            
            // Affiche le contenu de laa cellule
            if (i == 0 && j == entree) {
                cout << "0 ";
            } else if (i == Haut_laby - 1 && j == sortie) {
                cout << "S ";
            } else if (tab_Grille[i][j].getValeure() == 0) {
                cout << "";
            } else {
                cout << "0 ";
            }
            
            if (j == Larg_Laby - 1) {
                if (tab_Grille[i][j].getEst()) {
                    cout << "|";
                } else {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
    
    // Afficher les murs du bas de la derniere ligne
    for (int j = 0; j < Larg_Laby; j++) {
        if (tab_Grille[Haut_laby - 1][j].getSouth()) {
            cout << "+---";
        } else {
            cout << "+   ";
        }
    }
    cout << "+" << endl;  
}

void Labyrinthe::Creation_Laby(){

    valCellule();
    creationPattern();
}

void Labyrinthe::labyNnull(){
    for (int i = 0; i<Haut_laby; i++){
        for(int j = 0; j < Larg_Laby; j++){

            tab_Grille[i][j].setNorth(false);
            tab_Grille[i][j].setSouth(false);
            tab_Grille[i][j].setWest(false);
            tab_Grille[i][j].setEst(false);
        }
    }       
}

void Labyrinthe::mettre_piece(){
    
    int nbr_etoile=2;
    
    for(int i=0;i<8;i+=3){
        
        for(int x=0;x<nbr_etoile;x++){
            
            int j=rand()%8;
            if(tab_Grille[i][j].piece_test==true){j--;}
            tab_Grille[i][j].piece_test=true;

        }
    }
}

void Labyrinthe::testreglab(){

    Labyrinthe Lab=Labyrinthe();

    assert(tab_Grille[0][sortie].getNorth()==false);
    assert(tab_Grille[Haut_laby-1][entree].getSouth()==false);
    cout<<"Labyrinthe crée par le constructeur par defaut"<<endl;
    Lab.printLabTexte();

    Lab=Labyrinthe(3,3,8,8);

    assert(tab_Grille[0][sortie].getNorth()==false);
    assert(tab_Grille[Haut_laby-1][entree].getSouth()==false);
    assert(sortie!=3);
    assert(entree!=3);
    cout<<"Bonne construction par copie"<<endl;
    Lab.printLabTexte();
    cout<<"Labyrinthe crée par le constructeur numero 2"<<endl;

    Lab.labyNnull();
    Lab.printLabTexte();
    cout<<"Bonne destruction du labyrinthe"<<endl;       

}




