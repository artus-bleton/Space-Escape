# Jeu Labyrinthe
Ce projet est un jeu dans lequel vous incarnez un personnage bloqué dans un labyrinthe infini. Le but est de survivre le plus longtemps possible en évitant les murs et en atteignant des niveaux de plus en plus difficiles.

Le projet est développé en C++ et utilise la bibliothèque SDL pour la gestion graphique. Il compile et s'exécute sous Linux et macOS (voir ci-dessous pour les instructions d'installation des bibliothèques nécessaires pour le bon fonctionnement du jeu).

## Table des matières
- Fichier des données
- Compilation
- Execution
- Utilisation
- Fonctionalités
- Test regression des modules
- Installation
- Contributions
- Licence

## Fichier des données

- Le dossier "src" contient les fichiers source du jeu, c'est-à-dire les fichiers .cpp et .h.

- Le dossier "bin" est l'endroit où le fichier exécutable du jeu sera généré après compilation.

- Le dossier "obj" est utilisé pour stocker les fichiers d'objets générés pendant la compilation.

- Le dossier "data" contient les fichiers de données importants pour le jeu, tels que les textures, les images, les sons, les polices de 
caractères, etc.

- Le dossier "doc" contient la documentation du projet.

- Le fichier "makefile" est également inclus dans le dossier racine du projet. Il est être utilisé pour compiler le jeu en exécutant la commande "make" dans le terminal. Cette commande va d'abord générer les fichiers d'objets dans le dossier "obj" à partir des fichiers source dans le dossier "src", puis va les lier pour créer un fichier exécutable dans le dossier "bin".

## Compilation
Il est nécessaire de compiler le projet à l'aide du makefile avant d'exécuter le programme. Voici les étapes à suivre :

- Ouvrir un terminal et se déplacer dans le dossier principal du projet.

- Entrer la commande make pour compiler le jeu.

Une fois la compilation terminée, l'exécutable Jeu sera créé dans le dossier bin.

## Execution
- Pour exécuter le jeu, utiliser la commande ./bin/Jeu après avoir effectuer la compilation

- Sinon ouvrir un terminal et se déplacer dans le dossier bin. Ensuite, utiliser la commande ./Jeu pour lancer le programme

## Utilisation
Le but du jeu est de survivre le plus longtemps possible en évitant les murs et sans se faire rattraper par le mur qui se déplace en continu vers le heut et en atteignant des niveaux de plus en plus difficiles. Le labyrinthe est généré aléatoirement et est infini, ce qui signifie qu'il n'y a pas de fin.

**Pour jouer, utiliser les touches suivantes :**

- Z : pour se déplacer vers le haut.

- Q : pour se déplacer vers la gauche.

- S : pour se déplacer vers le bas.

- D : pour se déplacer vers la droite.

Le personnage avance automatiquement et le joueur peut seulement changer sa direction en appuyant sur l'une des touches de déplacement.

Le score est calculé en fonction de la distance parcourue par le personnage. Plus le personnage parcourt de distance, plus le score est élevé ,le joueur peut également collecter des bonus qui lui augmentent son score.

Le jeu est terminé lorsque le joueur entre en collision avec un mur.

## Fonctionalités

**Le jeu est doté des fonctionnalités suivantes :**

- ***Génération aléatoire de labyrinthes*** : chaque fois que le jeu est lancé, un nouveau labyrinthe est généré, offrant une expérience de jeu différente à chaque fois.

- ***Interface utilisateur conviviale*** : le jeu dispose d'une interface utilisateur simple et intuitive pour permettre aux joueurs de naviguer facilement dans le labyrinthe.

- ***Contrôles de jeu fluides*** : les joueurs peuvent se déplacer à travers le labyrinthe en utilisant les touches directionnelles ZQSD, ce qui permet une expérience de jeu fluide.

- ***Système de score*** : Calcul du score en fonction de la distance parcourue par le personnage. les joueurs peuvent essayer de battre leur score précédent en essayant de monter le plus haut possible dans le labyrinthe.

- ***Effets sonores et visuels*** : le jeu peut inclure des effets sonores et visuels pour rendre l'expérience de jeu plus immersive et engageante.

- Déplacement du mur en continu pour ajouter de la difficulté au jeu.

- Possibilité de quitter le jeu à tout moment en appuyant sur la touche Echap.

## Test regression des modules
instruction à ajouter , quoi faire pour effectuer les test

## Installation
**Pour pouvoir compiler il faut d'abord avoir installer le compilateur g++ la librairie SDL pour la gestion graphique**

### Linux :
- sudo apt install libsdl2-dev

- sudo apt install libsdl2-image-dev

- sudo apt install libsdl2-ttf-dev

- sudo apt install libsdl2-mixer-dev

### MAC OS :
- brew install gcc

- brew install sdl2

- brew install sdl2_image

- brew install sdl2_ttf
 
- brew install sdl2_mixer

## Contribution
Toute contribution au projet est la bienvenue. N'hésitez pas à signaler tout bug ou à proposer des améliorations en ouvrant une issue sur le dépôt GitHub du projet.

## Licence
