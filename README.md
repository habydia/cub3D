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

### Parsing du Fichier .cub

Le parsing transforme un fichier `.cub` en structures de donnees completes et validees. Le processus se deroule en trois phases principales:

**Phase 1: Extraction et Validation des Metadonnees**

Textures (NO/SO/WE/EA):
- Chaque ligne commence par l'identifiant (NO, SO, WE, EA) suivi du chemin du fichier
- Le parser extrait le chemin, le valide, et stocke l'adresse memoire de l'image chargee
- Validation: chaque texture doit etre definie exactement une fois

Couleurs (F/C):
- Format: `F 255,100,50` ou `C 0,0,0` (RGB separe par des virgules)
- Le parser decoupe la ligne, convertit chaque valeur en entier (0-255)
- Validation: chaque couleur doit etre definie exactement une fois avec 3 composantes RGB valides

**Phase 2: Accumulation de la Carte**

- Les lignes qui ne correspondent pas aux definitions de textures/couleurs sont considerees comme part de la carte
- Chaque ligne de carte est ajoutee a une liste chainee temporaire
- Les lignes vides avant la premiere ligne de carte sont ignorees
- Une ligne peut contenir des caracteres valides (`0`, `1`, `N`, `S`, `E`, `W`, ` `) ou etre rejetee

**Phase 3: Conversion et Validation de la Carte**

Conversion en grille 2D:
- La liste chainee est convertie en tableau 2D `char **map`
- Hauteur: nombre de lignes de carte accumulees
- Largeur: taille de la ligne la plus longue

Validations imperatives:

1. **Uniformite de largeur**: Toutes les lignes doivent avoir la meme largeur (padding avec espaces si necessaire)

2. **Joueur unique**: Il doit y avoir exactement une position de joueur (N, S, E, ou W)

3. **Fermeture spatiale** (Flood-fill):
   - A partir de la position du joueur, on parcourt tous les espaces (`0` et position joueur)
   - On verifie que la zone accessible reste completement entouree de murs (`1`)
   - Cela detecte les breches dans les murs et les positions inaccessibles

4. **Limite personnage**: Le joueur ne peut pas etre positionne sur une arete (bord de grille)

Schema du flux de parsing:

```
Fichier .cub
     |
     v
Ouverture et lecture ligne par ligne
     |
     v
Validation d'extension (.cub)
     |
     +--> Ligne vide ? --> Ignorer (avant la map)
     |
     +--> Format texture (NO/SO/WE/EA) ? --> Extraire et charger l'image
     |
     +--> Format couleur (F/C RGB) ? --> Extraire et valider RGB (0-255)
     |
     +--> Ligne de map ? --> Ajouter a liste chainee
     |
     v
Conversion liste --> char **map (allocation memoire)
     |
     v
Validation etape 1: Uniformite de largeur (padding)
     |
     v
Validation etape 2: Position joueur unique (detection N/S/E/W)
     |
     v
Validation etape 3: Fermeture spatiale (flood-fill depuis joueur)
     |
     v
Validation etape 4: Pas de joueur sur les bords
     |
     v
Succes: Retour structure t_file_data remplie OU Erreur: Liberation et exit
```

Gestion des erreurs:

Chaque etape de parsing peut generer une erreur:
- Fichier introuvable ou non-lisible
- Ligne mal formatee (texture ou couleur invalides)
- Metadonnees manquantes ou dupliquees
- Carte mal formee (pas assez de lignes, largeur variable, joueur manquant)
- Espace non-ferme (murs manquants, breche detectee)

A la premiere erreur, le programme affiche un message expliquant le probleme et s'arrete proprement.

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

## Resume

Cub3D implemente un moteur raycasting 3D fonctionnel en utilisant:
- DDA pour traverser efficacement la grille et trouver les murs
- Raycasting pour convertir une carte 2D en vue 3D
- Texture mapping pour appliquer les textures sur les murs
- Architecture modulaire respectant les contraintes de norminette