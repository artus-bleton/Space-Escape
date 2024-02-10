| Affichage                                                    |
| ------------------------------------------------------------ |
| - Game: Jeu                                                  |
| - Largeur_fenetre: int                                       |
| - Hauteur_fenetre: int                                       |
| - window: SDL_Window*                                        |
| - renderer: SDL_Renderer*                                    |
| - Image_Fenetre: SDL_Surface*                                |
| - Texture_Fenetre: SDL_Texture*                              |
| - rect_fenetre: SDL_Rect                                     |
| - jouerButton: SDL_Rect                                      |
| - jouerTextSurface: SDL_Surface*                             |
| - jouerTextTexture: SDL_Texture*                             |
| - jouerText: SDL_Rect                                        |
| - quitterButton: SDL_Rect                                    |
| - quitterTextSurface: SDL_Surface*                           |
| - quitterTextTexture: SDL_Texture*                           |
| - quitterText: SDL_Rect                                      |
|                                                              |
| + Affichage()                                                |
| + Menu()                                                     |
| + Demarrage()                                                |
| + destructionFenetre()                                       |
| + LancerJeu()                                                |
| - Initialisation_Jeu()                                       |
| - BoucleRunFenetre()                                         |
| - Actualiser_Affichage()                                     |
| - AfficherLab(Laby:Labyrinthe, decalage:int)                 |
| - AfficherCell(pos_x:int, pos_y:int, cell:Cellule, long_cell:int, larg_cell:int) |
| - affiche_mur(mur:Mur)                                       |
| - Afficher_piece(pos_x:int, pos_y:int, cell:Cellule, long_piece:int, larg_piece:int) |
| - test_regressionAff()                                       |
| - tab_score()                                                |







| Cellule                       |
| ----------------------------- |
| - coin_x : int                |
| - coin_y : int                |
| - N : bool                    |
| - S : bool                    |
| - E : bool                    |
| - W : bool                    |
| - valeur : int                |
|                               |
| + Cellule()                   |
| + ~Cellule()                  |
| + setNorth(bool)              |
| + setSouth(bool)              |
| + setEst(bool)                |
| + setWest(bool)               |
| + getNorth() : bool           |
| + getSouth() : bool           |
| + getEst() : bool             |
| + getWest() : bool            |
| + getValeur() : int           |
| + setValeur(int)              |
| + set_coin_x(unsigned int)    |
| + set_coin_y(unsigned int)    |
| + get_coin_x() : int          |
| + get_coin_y() : int          |
| + delMurFromDirectionOpo(int) |
| + delMurFromDirection(int)    |
| + erase_piece()               |

​      



| Jeu                                     |
| --------------------------------------- |
| - vit : float                           |
| - niveau_actuel : int                   |
| - dir_perso : int                       |
| - dir_secondaire : int                  |
| - laby_suiv : Labyrinthe                |
| - laby : Labyrinthe                     |
| - laby_prec : Labyrinthe                |
| - perso : Personnage                    |
| - mur : Mur                             |
| - decalage : int                        |
| - level : int                           |
| - score : int                           |
|                                         |
| + Jeu()                                 |
| + choix_dir_perso(ev: SDL_Event) : void |
| + Boucle_jeu() : void                   |
| + actualiser_mur() : void               |
| + check_mur_perso() : bool              |
| + check_etoile_perso() : bool           |
| + coordPerso_to_Cellule() : Cellule     |
| - test_regression() : void              |
| - Actualiser() : void                   |
| - stop_joueur(direction: int) : bool    |
| - check_coin_gauche() : bool            |
| - test_regressionJeu() : void           |
| - modif_niveau() : void                 |
| - perso_end_laby() : bool               |







| Labyrinthe                       |
| -------------------------------- |
| - Larg_Laby : int                |
| - Haut_laby : int                |
| - entree : int                   |
| - sortie : int                   |
| - tab_Grille : Cellule [50] [50] |
|                                  |
| + Labyrinthe()                   |
| + Labyrinthe(int,int,int,int)    |
| + ~Labyrinthe()                  |
| + Creation_Laby()                |
| + printLabTexte()                |
| + labyNnull()                    |
| - creationPattern()              |
| - labTermine() : bool            |
| - valCellule()                   |
| - mettre_piece()                 |







| Mur                           |
| ----------------------------- |
| - larg_mur                    |
| - hauteur_mur                 |
| - vitesse_mur                 |
| - couleur_mur                 |
| - transparence_couleur        |
| - retard_joueur               |
| - pos_y                       |
| - rect_mur                    |
|                               |
| + Mur()                       |
| + Mur(int, float, float, int) |







| Personnage                                                   |
| ------------------------------------------------------------ |
| - pos_x : int                                                |
| - pos_y : int                                                |
| - decalage : int                                             |
| - imageSurface : SDL_Surface*                                |
| - Texture : SDL_Texture*                                     |
| - rect : SDL_Rect                                            |
|                                                              |
| + Personnage()                                               |
| + Personnage(X : int, Y : int,                               |
| decal : int)                                                 |
| + ~Personnage()                                              |
| + deplacer_droite() : void                                   |
| + deplacer_gauche() : void                                   |
| + deplacer_haut() : void                                     |
| + deplacer_bas() : void                                      |
| + InitPerso_SDL(renderer : SDL_Renderer*) : void             |
| + choix_deplacement_personnage(choix : int, collision: bool ):void |
| + Actualiser_Perso(renderer :SDL_Renderer*) : void           |
| + test_regressionPer() : void                                |





| Piece         |
| ------------- |
| + pos_x : int |
| + pos_y : int |
|               |
| + Piece()     |