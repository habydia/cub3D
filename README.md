# Cub3D - 42 School Project

Implementation de raycasting 3D en C, inspiree par les moteurs de jeux Doom et Wolfenstein 3D.

## Installation et Compilation

Prerequis:
- Systeme: Linux
- Compilateur: GCC
- Bibliotheques: X11 (libxext-dev, libx11-dev), libm

Compilation:
```bash
make        # Compilation standard
make bonus  # Avec minimap
make clean  # Nettoyage
```

Le binaire s'appelle cub3D.

## Utilisation

```bash
./cub3D maps/good/good_map.cub
```

Controles:
- W/Fleche Haut: Avancer
- A/Fleche Gauche: Tourner gauche
- S/Fleche Bas: Reculer
- D/Fleche Droite: Tourner droite
- ESC: Quitter

## Sources de Recherche

1. Algorithme DDA - Interactive Explanation
   https://aaaa.sh/creatures/dda-algorithm-interactive/

2. Raycasting Tutorial - LoDevInfo
   https://lodev.org/cgtutor/raycasting.html

3. Cub3D Nathaan Implementation
   https://nathaan.me/projects/cub3d

4. Raycasting Game Tutorial - YouTube
   https://www.youtube.com/watch?v=G9i78WoBBIU

5. Raycasting: De Doom a Wolfenstein
   https://guy-grave.developpez.com/tutoriels/jeux/doom-wolfenstein-raycasting/

6. Raycasting - Wikipedia
   https://fr.wikipedia.org/wiki/Raycasting

7. DDA Line Generation Algorithm - GeeksforGeeks
   https://www.geeksforgeeks.org/computer-graphics/dda-line-generation-algorithm-computer-graphics/

## Concepts Techniques

### Algorithme DDA (Digital Differential Analyzer)

Le DDA est un algorithme de traversee de grille qui permet de suivre un rayon a travers une carte 2D jusqu'a trouver un mur.

Principe:
- Partir de la position du joueur
- Suivre le rayon dans sa direction
- Traverser la grille cellule par cellule
- Arreter quand on rencontre un mur

Etapes:
1. Initialiser le rayon (position, direction, grille de depart)
2. Calculer les directions de progression (step_x, step_y)
3. Boucle: avancer dans la grille jusqu'a detecter collision
   - Si tmax_x < tmax_y: pas horizontal
   - Sinon: pas vertical
4. Determiner le type de collision (horizontal ou vertical)

Avantages:
- Pas de trigonometrie couteux
- Parcours rapide de la grille
- Resultat exact

Implementation dans Cub3D:
```
raycasting.c
  |
  |- init_ray()              (preparer rayon)
  |- calculate_step()        (directions)
  |- perform_dda()           (traverser grille)
  |- calculate_wall_distance() (distance)
  |- draw_wall_vertical_line() (rendu)
```

### Raycasting

Le raycasting est une technique de rendu 3D qui cree une vue 3D a partir d'une carte 2D.

Principe:
- Pour chaque colonne d'ecran (800 colonnes)
- Envoyer un rayon depuis le joueur
- Utiliser DDA pour trouver le premier mur
- Calculer la hauteur du mur sur l'ecran
- Remplir la colonne avec la texture du mur

Fonctionnement:
1. Cast ray: envoyer un rayon
2. DDA traversal: trouver collision avec mur
3. Distance calculation: calculer distance perpendiculaire
4. Wall height: hauteur = hauteur_ecran / distance
5. Texture mapping: trouver pixels texture
6. Render column: afficher colonne

Correction fisheye:
Sans correction, l'image se deforme aux bords.
Solution: utiliser distance perpendiculaire au plan camera
au lieu de distance euclidienne.

Code principal:
```c
        init_ray(game, &ray, x, 800);
        calculate_step(game, &ray);
        perform_dda(game, &ray);
        calculate_wall_distance(game, &ray);
        draw_wall_vertical_line(game, &ray, x, 600);
```

## Architecture

Modules principaux:

raycasting/ - Moteur 3D
  - raycasting.c: orchestrateur
  - raycasting_utils_init_ray.c: init des rayons
  - raycasting_utils_calculate_step.c: etapes DDA
  - raycasting_utils_dda_algo.c: algo DDA
  - raycasting_utils_calculate_wall_distance.c: distance
  - raycasting_utils_draw_vertical_line.c: rendu colonnes

textures/ - Gestion textures
render_3d/ - Rendu sol/plafond
player/ - Joueur et collisions
keyboard/ - Entrees utilisateur
window/ - Fenetre et affichage
game/ - Contexte general
minimap/ - Minimap (bonus)

## Norminette Compliance

Le projet respecte la 42 Norminette:
- Max 5 fonctions par fichier .c
- Max 25 lignes par fonction
- Max 80 caracteres par ligne
- Max 4 parametres par fonction

Status: 34/42 fichiers conformes (modules raycasting 100% OK)

## Resume

Cub3D implemente un moteur raycasting 3D fonctionnel en utilisant:
- DDA pour traverser efficacement la grille et trouver les murs
- Raycasting pour convertir une carte 2D en vue 3D
- Texture mapping pour appliquer les textures sur les murs
- Architecture modulaire respectant les contraintes de norminette