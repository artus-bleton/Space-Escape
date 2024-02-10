#include "Affichage.h"
#include <cassert>
#include <iostream>
#include <stdlib.h> 
#include <unistd.h> 
using namespace std;


// Creation De ce constructeur pour eviter le stack smashing 

Affichage::Affichage(){


    window=nullptr;
    renderer=nullptr;

    Image_Fenetre=nullptr;
    Texture_Fenetre=nullptr;

    jouerTextSurface=nullptr;
    jouerTextTexture=nullptr;
    
    quitterTextSurface=nullptr;
    quitterTextTexture=nullptr;

    didactitielTextSurface=nullptr;
    didactitielTextTexture=nullptr;

    Texture=nullptr;
    imageSurface=nullptr;

    Largeur_fenetre=0;
    Hauteur_fenetre=0;
    Game= Jeu();

}

//La fonction initalise nos librairies
void Affichage::Demarrage(){

if (SDL_Init(SDL_INIT_VIDEO) != 0){

      cout<<"Erreur init sdl wsh"<<endl;
      SDL_Quit();
      }

      window = SDL_CreateWindow("Space_Laby", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900, 900, SDL_WINDOW_SHOWN);
    
    if (window == nullptr){
        
        cout<<"Erreur init fenetre"<<endl;
        SDL_Quit();
    }
   
   
   if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit ();
        exit(1);
   }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    if (renderer == nullptr){
        // Erreur : impossible de créer le renderer
        cout<<"Erreur init render"<<endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    // Charger une police pour le texte des boutons
    if(TTF_Init()!=0){

        cout<<"Erreur d'initialisation de sdl_ttf : "<<endl;
    }

    if (Mix_Init(MIX_INIT_MP3) < 0) {
        printf("Erreur d'initialisation de SDL_mixer : %s\n", Mix_GetError());

    } 
  
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) < 0) {
        printf("Erreur d'initialisation de SDL_mixer : %s\n", Mix_GetError());
    }

    Menu();
}



void Affichage::Menu(){

//Ces variables ont servis a positionner les carrées a ne pas effacer, on sait jamais 
    int repos_x=-50;
    int repos_y=-250;
    int transparence_bouton=175;
    int hauteur_boutton=70;
    int largeur_boutton=200;

    Largeur_fenetre=900;
    Hauteur_fenetre=900;   
    // Variable pour l'ecriture
    TTF_Font * font = TTF_OpenFont("font.ttf", 30);


    Mix_Chunk * wav=Mix_LoadWAV("data/son_menu.wav");

    if (wav == NULL) {
        cout<<"Impossible de charger le fichier audio : %s\n";
 
    }
    
    int channel = Mix_PlayChannel(-1, wav, 0);
   
    if (channel == -1) {
        printf("Impossible de jouer le fichier audio : %s\n", Mix_GetError());

    }

    Mix_Volume(channel,MIX_MAX_VOLUME/4);
    
    if (font == nullptr)
    {
        // Erreur : impossible de charger la police
        cout<<"Erreur init 3"<<endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
 
  //Mise en place du fond

    rect_fenetre={0,0,Largeur_fenetre,Hauteur_fenetre};
    Image_Fenetre=IMG_Load("./data/Space_Background.png");
    Texture_Fenetre=SDL_CreateTextureFromSurface(renderer,Image_Fenetre);
    SDL_FreeSurface(imageSurface);
    SDL_RenderCopy(renderer,Texture_Fenetre,NULL,&rect_fenetre);

    SDL_Rect titre;
    SDL_Surface *titre_surface;
    SDL_Texture *titre__texture;
    titre_surface=IMG_Load("data/titre.png");
    titre__texture=SDL_CreateTextureFromSurface(renderer,titre_surface);
    SDL_FreeSurface(titre_surface);
    titre={150,225,665,65};
    SDL_RenderCopy(renderer,titre__texture,NULL,&titre);

    SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_BLEND);
    // Créer un bouton "Jouer"
    jouerButton.x = 300-repos_x;
    jouerButton.y = 200-repos_y;
    jouerButton.w = largeur_boutton;
    jouerButton.h = hauteur_boutton;
    SDL_SetRenderDrawColor(renderer, 98, 8, 125, transparence_bouton);
    SDL_RenderFillRect(renderer, &jouerButton);
    
    jouerTextSurface = TTF_RenderText_Solid(font, "Jouer", {0, 0, 0});
    jouerTextTexture = SDL_CreateTextureFromSurface(renderer, jouerTextSurface);
    jouerText.x = 350-repos_x;
    jouerText.y = 205-repos_y;
    jouerText.w = 100;
    jouerText.h = 50;
    SDL_RenderCopy(renderer, jouerTextTexture, nullptr, &jouerText);

    // Créer un bouton "Quitter"
    quitterButton.x = 300-repos_x;;
    quitterButton.y = 300-repos_y;
    quitterButton.w = largeur_boutton;
    quitterButton.h = hauteur_boutton;
    SDL_SetRenderDrawColor(renderer, 98,8,125,transparence_bouton);
    SDL_RenderFillRect(renderer, &quitterButton);
    
    quitterTextSurface = TTF_RenderText_Solid(font, "Quitter", {0, 0, 0});
    quitterTextTexture = SDL_CreateTextureFromSurface(renderer, quitterTextSurface);
    quitterText.x = 350-repos_x;
    quitterText.y = 305-repos_y;
    quitterText.w =100;
    quitterText.h = 50;
    SDL_RenderCopy(renderer, quitterTextTexture, nullptr, &quitterText);

    // Créer un bouton "Didactitiel"

    didactitielButton.x = 300-repos_x;;
    didactitielButton.y = 400-repos_y;
    didactitielButton.w = largeur_boutton;
    didactitielButton.h = hauteur_boutton;
    SDL_SetRenderDrawColor(renderer, 98,8,125,transparence_bouton);
    SDL_RenderFillRect(renderer, &didactitielButton);
   
    didactitielTextSurface = TTF_RenderText_Solid(font, "Didactitiel", {0,0,0});
    didactitielTextTexture = SDL_CreateTextureFromSurface(renderer, didactitielTextSurface);

    didactitielText.x = 350-repos_x;
    didactitielText.y = 405-repos_y;
    didactitielText.w = 100;
    didactitielText.h = 50;
    SDL_RenderCopy(renderer, didactitielTextTexture, nullptr, &didactitielText);
 
    // Afficher le menu    
    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(titre__texture);
    SDL_DestroyTexture(Texture_Fenetre);
    TTF_CloseFont(font);
    bool ouvert=true;
    while (ouvert)
    
    {
        SDL_Event event;
        
        while(SDL_PollEvent(&event))
        
        {
            switch (event.type)
            
            {
                case SDL_QUIT:
                    detruire_menu();
                   destructionJeu();
                    
                    ouvert=false;
                    Mix_HaltChannel(channel);
                    Mix_FreeChunk(wav);
                    break;
            

                case SDL_MOUSEBUTTONDOWN:
                    // L'utilisateur a cliqué sur un bouton
                    
                    int mouseX = event.button.x;
                    int mouseY = event.button.y;   
                    Mix_HaltChannel(channel);
                    Mix_FreeChunk(wav);                        
                    
                    if (mouseX >= jouerButton.x && mouseX <= jouerButton.x + jouerButton.w && mouseY >= jouerButton.y && mouseY <= jouerButton.y + jouerButton.h)
                    {
                        ouvert=false;
                        detruire_menu();
                        LancerJeu();
                      
                        break;
                    }
                    
                    else if (mouseX >= quitterButton.x && mouseX <= quitterButton.x + quitterButton.w && mouseY >= quitterButton.y && mouseY <= quitterButton.y + quitterButton.h)
                    {
                        // L'utilisateur a cliqué sur le bouton "Quitter"
                        ouvert=false;
                        detruire_menu();
                       destructionJeu();
                        break;
                    }
                    
                    else if (mouseX >= didactitielButton.x && mouseX <= didactitielButton.x + didactitielButton.w && mouseY >= didactitielButton.y && mouseY <= didactitielButton.y + didactitielButton.h)
                    {
                        // L'utilisateur a cliqué sur le bouton "Didactitiel"
                        // écrire le code
                        ouvert=false;
                        detruire_menu();
                        Didactitiel();
                        
                        break;
                }
                     
             }
            
        }
    }
}
     
void Affichage::Initialisation_Jeu(){


     //Mise en place du fond
    
    rect_fenetre={0,0,Largeur_fenetre,Hauteur_fenetre};
    Image_Fenetre=IMG_Load("./data/Space_Background.png");
    Texture_Fenetre=SDL_CreateTextureFromSurface(renderer,Image_Fenetre);
    SDL_RenderCopy(renderer,Texture_Fenetre,NULL,&rect_fenetre);

    //Mise en place du Labyrinthe
    AfficherLab(Game.laby,Game.perso.decalage);
    //Mise en place du Labyrinthe
    charger_perso();   
    SDL_RenderPresent(renderer);


}
    

void Affichage::BoucleRunFenetre(){
    
    bool ouvert=true;
    SDL_Event event;
    Mix_Chunk * wav=Mix_LoadWAV("data/laby.wav");
    Mix_Chunk * son=Mix_LoadWAV("data/son_piece.wav");
    if (wav == NULL) {
        cout<<"Impossible de charger le fichier audio : %s\n";
 
    }
    
    int channel=Mix_PlayChannel(-1, wav, -1);
   
    if (channel == -1) {
        printf("Impossible de jouer le fichier audio : %s\n", Mix_GetError());

    }

    Mix_Volume(channel,MIX_MAX_VOLUME*2);

    while(ouvert){   

        Game.Boucle_jeu();

         while(SDL_PollEvent(&event)){
            
            if(event.type==SDL_KEYDOWN){

                Game.choix_dir_perso(event);
   
            }

            if(event.type==SDL_QUIT ){    
                
                ouvert=false;
                Mix_HaltChannel(channel);
                Mix_FreeChunk(wav);
                Mix_FreeChunk(son);
               destructionJeu();
            }

        }
    
        if(Game.check_mur_perso()){
            
            int score=Game.score;
            Game=Jeu();
            Mix_HaltChannel(channel);
            Mix_FreeChunk(wav);
            Mix_FreeChunk(son);
            tab_score(score);
            break; 
        }
        
       if(Game.check_etoile_perso()){
            
            int coin_channel=Mix_PlayChannel(1,son,0);
            Mix_Volume(coin_channel,MIX_MAX_VOLUME/3);
                        
        }

        Actualiser_Affichage();
    }
}
                 

void Affichage:: Actualiser_Affichage(){
    
    SDL_RenderCopy(renderer,Texture_Fenetre,NULL,&rect_fenetre);
 
    AfficherLab(Game.laby,Game.perso.decalage);   

    charger_perso(); // Cette fonction n'affiche pas le personnage mais charge juste notre carré

    affiche_mur(Game.mur);
    SDL_RenderPresent(renderer);

    usleep(333);
 
}

void Affichage::destructionJeu(){
    
    SDL_DestroyRenderer(renderer);
    cout<<"rendu bouge "<<endl;

    SDL_DestroyWindow(window);

    cout<<"fenetre bouge "<<endl;

    SDL_DestroyTexture(Texture_Fenetre);
    cout<<"TEXTURE FENETRE DETRUITE"<<endl;

    SDL_FreeSurface(Image_Fenetre);
    cout<<"SURFACE IMAGE DETRUITE"<<endl; 
    SDL_DestroyTexture(Texture);
    SDL_FreeSurface(imageSurface);
    IMG_Quit();
    SDL_Quit();
    TTF_Quit();
    Mix_Quit();
        
}

void Affichage::detruire_menu(){

    cout<<"DESTRUCTION :"<<endl;
    
    SDL_DestroyTexture(jouerTextTexture);
    cout<<"1 bouge "<<endl;
    SDL_FreeSurface(jouerTextSurface);
    cout<<"2 bouge "<<endl;

    SDL_DestroyTexture(quitterTextTexture);
    cout<<"3 bouge "<<endl;

    SDL_FreeSurface(quitterTextSurface);

    cout<<"4 bouge "<<endl;

    
    SDL_DestroyTexture(didactitielTextTexture);

    cout<<"5 bouge "<<endl;

    SDL_FreeSurface(didactitielTextSurface);

}

void const Affichage::AfficherLab(Labyrinthe const &  Laby, int const & decalage){

    int TY=50;

    for (int i = 0; i < Game.laby.Haut_laby; i++){

        int min_y = (i *100 ) - decalage;              //Pour commencer l'affichage par le bas par les y

        for(int j = 0; j < Game.laby.Larg_Laby; j++){

            int min_x = (j * 100) + 50;

            AfficherCell(min_x, min_y, Laby.tab_Grille[i][j],100,5);
            
            if(Game.laby.tab_Grille[i][j].piece_test) {Afficher_piece(min_x, min_y, Laby.tab_Grille[i][j],TY,TY);}       
        }
    }
    
    for (int i = 0; i < Game.laby_suiv.Haut_laby; i++){

        int min_y = (i *100 ) - decalage - 800 ;              //Pour commencer l'affichage par le bas par les y

        for(int j = 0; j < Game.laby_suiv.Larg_Laby; j++){

            int min_x = (j * 100) + 50;

            AfficherCell(min_x, min_y, Game.laby_suiv.tab_Grille[i][j],100,5);      
        }
    }

    for (int i = 0; i < Game.laby_prec.Haut_laby; i++){

        int min_y = (i *100 ) - decalage + 800 ;              //Pour commencer l'affichage par le bas par les y

        for(int j = 0; j < Game.laby_prec.Larg_Laby; j++){

            int min_x = (j * 100) + 50;

            AfficherCell(min_x, min_y, Game.laby_prec.tab_Grille[i][j],100,5);    
        }
    }
}



void Affichage::AfficherCell( int pos_x,  int  pos_y , Cellule cell, int long_cell, int larg_cell){

    SDL_Rect rect;
    cell.set_coint_x(pos_x);
    cell.set_coint_y(pos_y);


    SDL_SetRenderDrawColor(renderer, 255,255,255, 255);

    if(cell.getNorth()){
        
        rect={pos_x,pos_y,long_cell,larg_cell};
        SDL_RenderFillRect(renderer,&rect);
 
    }

    if(cell.getSouth() ){
        
        rect={pos_x,pos_y+long_cell,long_cell,larg_cell};
        SDL_RenderFillRect(renderer,&rect);
    }

    if(cell.getEst()){
        rect={pos_x+long_cell,pos_y,larg_cell,long_cell};
        SDL_RenderFillRect(renderer,&rect);
  
    }

    if(cell.getWest()){
        rect={pos_x,pos_y,larg_cell,long_cell};
        SDL_RenderFillRect(renderer,&rect); 
    
    }

    if(cell.getSouth() && cell.getEst()){
    
        int x_test = cell.get_coint_x();
        int y_test = cell.get_coint_y();
        rect={x_test,y_test,larg_cell,larg_cell};
        SDL_RenderFillRect(renderer,&rect);
    
    }
 
}

void Affichage::test_regressionAff(){ 
    
    // test d'initialisation de fenetre
    Affichage aff_test;
    cout<<"Verification menu "<<endl;
    aff_test.Demarrage();

    assert(aff_test.window != nullptr && "Erreur lors de la destruction de la fenetre.");
    cout<<"&"<<endl;
    
    assert(aff_test.renderer != nullptr && "Erreur lors de la destruction du rendu.");
    assert(aff_test.Texture_Fenetre != nullptr && "Erreur lors dela destruction de la texture fenetre.");
    assert(aff_test.Image_Fenetre != nullptr && "Erreur lors de la destruction de la texture fenetre.");
    assert(aff_test.jouerTextTexture != nullptr && "Erreur lors de la destruction de la texture du bouton jouer.");
    assert(aff_test.jouerTextSurface != nullptr && "Erreur lors de la destruction de la surface du bouton Jouer.");
    assert(aff_test.quitterTextSurface != nullptr && "Erreur lors de la destruction de la texture du bouton quitter.");
    assert(aff_test.quitterTextTexture != nullptr && "Erreur lors de la destruction de la surface du bouton quitter.");    
    
    cout<<"Aucune fuite lors de la destruction du menu"<<endl;
    aff_test.Demarrage();
    cout<<"Verification Jeu "<<endl;

    assert(aff_test.window != nullptr && "Erreur lors de la destruction de la fenetre.");
    assert(aff_test.renderer != nullptr && "Erreur lors de la destruction du rendu.");
    assert(aff_test.Texture_Fenetre != nullptr && "Erreur lors dela destruction de la texture fenetre.");
    assert(aff_test.Image_Fenetre != nullptr && "Erreur lors de la destruction de la texture fenetre.");
    assert(aff_test.jouerTextTexture != nullptr && "Erreur lors de la destruction de la texture du bouton jouer.");
    assert(aff_test.jouerTextSurface != nullptr && "Erreur lors de la destruction de la surface du bouton Jouer.");
    assert(aff_test.quitterTextSurface != nullptr && "Erreur lors de la destruction de la texture du bouton quitter.");
    assert(aff_test.quitterTextTexture != nullptr && "Erreur lors de la destruction de la surface du bouton quitter.");
    
    cout<<"Aucune fuite lors de la destruction du Jeu"<<endl;

} 

void const Affichage::affiche_mur(Mur const & mur){

    srand((unsigned int)time(NULL));
    SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_BLEND);
    SDL_Rect rect_mur;
    
    int transparence_couleur=100;
    int couleur_mur=rand() % 255;

    if(couleur_mur<100){
        SDL_SetRenderDrawColor(renderer,couleur_mur,0,0,transparence_couleur);
    }
    
    else if(couleur_mur>100 && couleur_mur<200){
        SDL_SetRenderDrawColor(renderer,0,couleur_mur,0,transparence_couleur);

    }

    else {SDL_SetRenderDrawColor(renderer,0,0,couleur_mur,transparence_couleur);}

    rect_mur={0,mur.pos_y - Game.perso.decalage ,mur.larg_mur,mur.hauteur_mur}; 
    
    SDL_RenderFillRect(renderer,&rect_mur);
}


void Affichage::tab_score(int score){

  Mix_Chunk * wav=Mix_LoadWAV("data/game_over.wav");

  if (wav == NULL) {
        cout<<"Impossible de charger le fichier audio : %s\n";
 
    }
    
  int channel = Mix_PlayChannel(-1, wav, 0);
   
  if (channel == -1) {
        printf("Impossible de jouer le fichier audio : %s\n", Mix_GetError());

    }

  Mix_Volume(channel,MIX_MAX_VOLUME/4);


  SDL_RenderCopy(renderer,Texture_Fenetre,NULL,&rect_fenetre);

  SDL_Rect squareRect;
  squareRect.w = 400;
  squareRect.h = 430;
  squareRect.x = (900/2-squareRect.w/2);
  squareRect.y = (900/2-squareRect.w / 2)-90;

  SDL_SetRenderDrawColor(renderer, 98, 8, 125, 175);
  SDL_RenderFillRect(renderer, &squareRect);

  TTF_Font* font1 = TTF_OpenFont("font.ttf", 100);
  SDL_Color textColor = { 0, 0, 0 }; 

  SDL_Surface* textSurface = TTF_RenderText_Solid(font1, "SCORE :", textColor);
  SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
 
  SDL_Rect textRect;
  textRect.w = 100;
  textRect.h = 50;
  textRect.x = squareRect.x / 2 + squareRect.w/2 +90;
  textRect.y = squareRect.y + squareRect.w/2-50;
  SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
 
  char score_str[32];

  sprintf(score_str, " %d",score);
  cout<<score<<endl;
  textSurface = TTF_RenderText_Solid(font1,score_str, textColor);
  textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
  SDL_Rect numberRect;
  
  numberRect.w = textSurface->w;
  numberRect.h = textSurface->h;
  numberRect.x = squareRect.x / 2 + squareRect.w/2 +70;
  numberRect.y =squareRect.y + squareRect.w/2;
  
  SDL_RenderCopy(renderer, textTexture, NULL, &numberRect);
  
  SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);

  SDL_Rect star;
  int nbr_etoile=score/60;
  star.w = 120;
  star.h = 120;
  SDL_Surface* star_surface = IMG_Load("data/star.png");
  SDL_Texture* star_texture = SDL_CreateTextureFromSurface(renderer,star_surface);
  
  if(nbr_etoile>3){nbr_etoile=3;}
  
  for(int i=0;i<nbr_etoile;i++){
    star.x = 300+i*100;
    star.y = 200;
    SDL_RenderCopy(renderer, star_texture, NULL, &star);
    SDL_RenderPresent(renderer);
    SDL_Delay(500);
  }

  //Le nombre d'etoile changera en fonction du score
  //Il faut trouver notre facon de calculer le score aussi 

  SDL_Rect menu,rejouer,quitter;
  SDL_Surface * quitter_surface;
  SDL_Surface * rejouer_surface;
  SDL_Texture * quitter_texture;
  SDL_Texture * rejouer_texture;
 
  menu.x=300;
  menu.y=500;
  menu.h=60;
  menu.w=60;
 
  rejouer.x=menu.x+130;
  rejouer.y=menu.y;
  rejouer.h=60;
  rejouer.w=60;
 
  quitter.x=rejouer.x+120;
  quitter.y=menu.y;
  quitter.h=60;
  quitter.w=60;

  textSurface=IMG_Load("data/Maison.png");
  textTexture=SDL_CreateTextureFromSurface(renderer,textSurface);

  quitter_surface=IMG_Load("data/QUITTER.png");
  rejouer_surface=IMG_Load("data/rejouer1.png");

  quitter_texture=SDL_CreateTextureFromSurface(renderer,quitter_surface);
  rejouer_texture=SDL_CreateTextureFromSurface(renderer,rejouer_surface);

  SDL_FreeSurface(quitter_surface);
  SDL_FreeSurface(rejouer_surface);

  SDL_RenderCopy(renderer,textTexture, NULL, &menu);
  SDL_RenderCopy(renderer,rejouer_texture, NULL, &rejouer);
  SDL_RenderCopy(renderer,quitter_texture, NULL, &quitter);
  
 
  SDL_RenderPresent(renderer);

  SDL_FreeSurface(textSurface);
  SDL_DestroyTexture(textTexture);
  SDL_DestroyTexture(quitter_texture);
  SDL_DestroyTexture(rejouer_texture);
  SDL_FreeSurface(star_surface);
  SDL_DestroyTexture(star_texture);
  TTF_CloseFont(font1);

    bool ouvert=true;
    SDL_Event e;
    while(ouvert){
        
        while(SDL_PollEvent(&e)){
                
            if(e.type==SDL_MOUSEBUTTONDOWN){
                    
                int mouseX = e.button.x;
                int mouseY = e.button.y;
               
                 
                if(mouseX >= menu.x && mouseX <= menu.x + menu.w && mouseY >= menu.y && mouseY <= menu.y + menu.h){
                    ouvert=false;
                    Mix_HaltChannel(channel);
                    Mix_FreeChunk(wav);
                    Menu();
                    break;
                }

                if( mouseX >= rejouer.x && mouseX <= rejouer.x + rejouer.w && mouseY >= rejouer.y && mouseY <= rejouer.y + rejouer.h){
                    
                    ouvert=false;
                    Mix_HaltChannel(channel);
                    Mix_FreeChunk(wav);
                    LancerJeu();
                }

                if( mouseX >= quitter.x && mouseX <= quitter.x +  quitter.w && mouseY >=  quitter.y && mouseY <=  quitter.y +  quitter.h){
                    
                    ouvert=false;
                    Mix_HaltChannel(channel);
                    Mix_FreeChunk(wav);
                   destructionJeu();
                    break;
                }

                    //J'ajouterai le code quand je trouverai les images pour recommancer une partie, aller au menu et quitter le jeu
            }
        }
    
    
    }
    
}

void Affichage::LancerJeu(){

    Initialisation_Jeu();
    BoucleRunFenetre();
}

void Affichage::Afficher_piece(int pos_x,  int  pos_y , Cellule cell, int long_piece, int larg_piece){

    cell.piece.pos_x=pos_x;
    cell.piece.pos_y=pos_y;
    SDL_Rect piece_rect;
    
    SDL_Surface * piece_surface=nullptr;
    SDL_Texture * piece_texture=nullptr;
    
    piece_surface=IMG_Load("data/img_piece.png");
    piece_texture=SDL_CreateTextureFromSurface(renderer,piece_surface);
    
    piece_rect={cell.piece.pos_x+25,cell.piece.pos_y+25,long_piece,larg_piece};
    SDL_RenderCopy(renderer,piece_texture,NULL,&piece_rect);
    
    SDL_DestroyTexture(piece_texture);
    SDL_FreeSurface(piece_surface);
    
}

void Affichage::charger_perso(){

    SDL_Rect rect;
    imageSurface=IMG_Load("data/perso.png");
     //Creation de la Texture a partir du rendu et de l'image du perso
    Texture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    // Créez un rectangle SDL qui représente le carré
    rect={Game.perso.pos_x,450,90,90};        //La coordonées y vaut 450 car il n'y que le labyrinthe qui avance ou recule, on ne modifie pas 
   
    SDL_RenderCopy(renderer,Texture,NULL,&rect);
}

void Affichage::Didactitiel(){

    rect_fenetre={0,0,Largeur_fenetre,Hauteur_fenetre};
    Image_Fenetre=IMG_Load("./data/Space_Background.png");
    Texture_Fenetre=SDL_CreateTextureFromSurface(renderer,Image_Fenetre);
    SDL_FreeSurface(Image_Fenetre);
    SDL_RenderCopy(renderer,Texture_Fenetre,NULL,&rect_fenetre);


    SDL_Color color = { 255, 255, 255 }; 
    TTF_Font * font = TTF_OpenFont("font.ttf", 30);

    SDL_Surface* tuto_surface = TTF_RenderText_Blended_Wrapped(font, "Commandes :\nUtilisez les touches ZQSD pour bouger l'ovni dans differentes directions. Pour eviter le mur multicolore, vous devrez explorez le labyrinthe spatiale. Collectez des pieces pour augmenter votre score. Faites attention aux murs car ils peuvent ralentir votre progression.\n\nBut du jeu :\nLe but du jeu est de faire le meilleur score possible en collectant des pièces tout en évitant le mur multicolore.", color, 600);
    /*
    Voici le texte ecrit:

    Commandes : Utilisez les touches ZQSD (ou les touches fléchées) pour déplacer l'ovni dans les différentes directions. 
    Pour éviter le mur multicolore, vous devrez vous déplacer rapidement et changer de direction fréquemment. 
    Collectez des pièces pour augmenter votre score. Faites attention aux murs car ils peuvent ralentir votre progression
    But du jeu : Le but du jeu est de faire le meilleur score possible en collectant des pièces tout en évitant le mur multicolore. 
     */
    
    
    SDL_Texture* tuto_texture = SDL_CreateTextureFromSurface(renderer, tuto_surface);
    SDL_Rect rect_tuto={50,175,800,500};
    
    SDL_RenderCopy(renderer,tuto_texture,NULL,&rect_tuto);
    
    SDL_RenderPresent(renderer);
    SDL_FreeSurface(tuto_surface);
    SDL_DestroyTexture(tuto_texture);
    TTF_CloseFont(font);

    bool ouvert=true;
    SDL_Event event;
    while(ouvert){

        while (SDL_PollEvent(&event))
        {
            if(event.type==SDL_KEYDOWN){

                if(event.key.keysym.sym == SDLK_r){

                    ouvert=false;
                    Menu();
                }
            }

            if(event.type==SDL_QUIT){

                ouvert=false;
            }
            
        }
        
    }
}
