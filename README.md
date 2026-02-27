# cub3D

## Description
cub3D est un projet de l'école 42 implémentant un moteur de jeu 3D simple en C, inspiré de Wolfenstein 3D. Le jeu utilise le raycasting pour créer un environnement 3D navigable à partir d'une carte 2D.

Le projet est divisé en plusieurs parties : parsing (analyse des fichiers), rendu graphique, gestion des événements (clavier/souris), et optimisation. Vous êtes chargé de la partie parsing, qui est cruciale car elle permet de charger et valider les données d'entrée avant le rendu.

## Clone
Clonez le dépôt en incluant le sous-module MiniLibX :

```bash
git clone --recursive https://github.com/votre-repo/cub3d.git
```
Ou :
```bash
git clone https://github.com/votre-repo/cub3d.git
git submodule update --init --recursive
```

## Compile and Run
Il y a deux versions du programme, la partie obligatoire et la partie bonus. La partie bonus ajoute la collision avec les murs, une minimap, et la possibilité de tourner la vue en déplaçant la souris.

Le programme prend un fichier de map en argument. Les maps sont disponibles dans le répertoire maps. Il y a des bonnes maps avec lesquelles le programme devrait fonctionner correctement, et des mauvaises maps que le programme devrait rejeter. Par exemple :

```bash
./cub3d maps/good/library.cub
```
## Controls
Les contrôles pour le mouvement et la rotation sont :

- W : avancer
- S : reculer
- A : se déplacer à gauche
- D : se déplacer à droite
- Flèche gauche : tourner à gauche
- Flèche droite : tourner à droite
- Souris : tourner en déplaçant la souris (bonus uniquement)

## Parsing Overview
Le parsing transforme un fichier `.cub` en structures de données utilisables :
- **Extraire** : Identifier et isoler les parties utiles de la ligne (e.g., chemin pour textures, valeurs RGB pour couleurs).
- **Parser** : Analyser et convertir les données (e.g., découper RGB en entiers, valider le format).
- **Stocker** : Sauvegarder dans `t_file_data` pour utilisation ultérieure (rendu, validation).
Cela permet de traiter textures (NO/SO/WE/EA) et couleurs (F/C) avant la map, avec gestion d'erreurs.

### Schéma du Flux de Parsing de la Map

```
Fichier .cub
     |
     v
Lecture ligne par ligne (read_file)
     |
     +--> Ligne vide ? --> Ignorer
     |
     +--> Texture/ Couleur ? --> Traiter (process_textures/colors)
     |
     +--> Map ? --> Ajouter à liste (process_map)
     |
     v
Fin de lecture --> to_2d_map (finalisation)
     |
     +--> Convertir liste en char **map
     |
     +--> Valider largeur uniforme (validate_width)
     |
     +--> Valider joueur unique (validate_player)
     |
     +--> Valider fermeture (validate_closure - flood fill)
     |
     v
Map validée ou erreur
```
### Intégration
Après parsing réussi, `t_file_data` est utilisé pour le rendu 3D. En cas d'erreur, le programme s'arrête.

## Useful Resources
Ressources utiles pour ce projet :

- MiniLibX : Documentation de hsmits
- MiniLibX : Tutoriel de gontjarow
- Xlib (pour les événements MLX) : Le manuel Xlib
- Raycasting : Tutoriel de Lode's Computer Graphics - Raycasting
- Raycasting : Tutoriel de Permadi
- Mouvement : Calcul de la direction dans les jeux 2D : Utilisation des fonctions trigonométriques partie 1

## Made by
-Lebrou Hadia