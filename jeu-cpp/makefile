OBJ_FILES = obj/main.o obj/Labyrinthe.o obj/Cellule.o obj/Jeu.o obj/Personnage.o obj/Affichage.o obj/Mur.o 
EXE = bin/Jeu

bin/Jeu : obj/main.o obj/Labyrinthe.o obj/Cellule.o obj/Jeu.o obj/Personnage.o obj/Affichage.o obj/Mur.o obj/Piece.o 
	g++ obj/main.o obj/Cellule.o obj/Labyrinthe.o obj/Jeu.o obj/Personnage.o obj/Affichage.o obj/Mur.o obj/Piece.o   -o bin/Jeu  -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

bin/TestAff : obj/mainTestAffichage.o obj/Labyrinthe.o obj/Cellule.o obj/Jeu.o obj/Personnage.o obj/Affichage.o obj/Mur.o obj/Piece.o 
	g++ obj/mainTestAffichage.o obj/Cellule.o obj/Labyrinthe.o obj/Jeu.o obj/Personnage.o obj/Affichage.o obj/Mur.o obj/Piece.o   -o bin/TestAff  -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

bin/TestLaby: obj/mainTestLaby.o obj/Labyrinthe.o obj/Cellule.o obj/Jeu.o obj/Personnage.o obj/Affichage.o obj/Mur.o   obj/Piece.o 
	g++ obj/mainTestLaby.o obj/Cellule.o obj/Labyrinthe.o obj/Jeu.o obj/Personnage.o obj/Affichage.o obj/Mur.o obj/Piece.o   -o bin/TestLaby  -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

bin/TestPerso: obj/mainTestPerso.o obj/Labyrinthe.o obj/Cellule.o obj/Jeu.o obj/Personnage.o obj/Affichage.o obj/Mur.o obj/Piece.o 
	g++ obj/mainTestPerso.o obj/Cellule.o obj/Labyrinthe.o obj/Jeu.o obj/Personnage.o obj/Affichage.o obj/Mur.o obj/Piece.o   -o bin/TestPerso -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

obj/Affichage.o: src/Affichage.cpp src/Affichage.h
	g++  -ggdb  -c src/Affichage.cpp -o obj/Affichage.o -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

obj/main.o: src/main.cpp src/Affichage.h
	g++ -Wall -ggdb   -c src/main.cpp -o obj/main.o -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

obj/mainTestPerso.o: src/mainTestPerso.cpp src/Affichage.h
	g++ -Wall -ggdb   -c src/mainTestPerso.cpp -o obj/mainTestPerso.o -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

obj/mainTestAffichage.o: src/mainTestAffichage.cpp src/Affichage.h
	g++ -Wall -ggdb   -c src/mainTestAffichage.cpp -o obj/mainTestAffichage.o -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
	
obj/mainTestLaby.o: src/mainTestLaby.cpp src/Affichage.h
	g++ -Wall -ggdb   -c src/mainTestLaby.cpp -o obj/mainTestLaby.o -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer


obj/Cellule.o : src/Cellule.cpp src/Cellule.h 
	g++ -Wall  -ggdb  -c src/Cellule.cpp -o obj/Cellule.o -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

obj/Labyrinthe.o : src/Labyrinthe.cpp src/Labyrinthe.h 
	g++ -Wall  -ggdb  -c src/Labyrinthe.cpp -o obj/Labyrinthe.o -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
  
obj/Jeu.o : src/Jeu.cpp src/Jeu.h
	g++ -Wall -ggdb  -c src/Jeu.cpp -o obj/Jeu.o -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

obj/Personnage.o : src/Personnage.cpp src/Personnage.h
	g++ -Wall -ggdb  -c src/Personnage.cpp -o obj/Personnage.o -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

obj/Mur.o : src/Mur.cpp src/Mur.h
	g++ -Wall -ggdb  -c src/Mur.cpp -o obj/Mur.o -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

obj/Piece.o : src/Piece.cpp src/Piece.h
	g++ -Wall -ggdb  -c src/Piece.cpp -o obj/Piece.o -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
 

clean :
	rm $(OBJ_FILES) $(EXE)
