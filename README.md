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

Le parsing transforme un fichier `.cub` en structures de données complètes et validées. Le processus se déroule en trois phases principales:

### Phase 1: Extraction et Validation des Métadonnées

**Textures** (NO/SO/WE/EA): 
- Chaque ligne commence par l'identifiant (NO, SO, WE, EA) suivi du chemin du fichier
- Le parser extrait le chemin, le valide, et stocke l'adresse mémoire de l'image chargée
- Validation: chaque texture doit être définie exactement une fois

**Couleurs** (F/C):
- Format: `F 255,100,50` ou `C 0,0,0` (RGB séparé par des virgules)
- Le parser découpe la ligne, convertit chaque valeur en entier (0-255), et stoppe à la première non-validité
- Validation: chaque couleur doit être définie exactement une fois avec 3 composantes RGB valides

### Phase 2: Accumulation de la Carte

- Les lignes qui ne correspondent pas aux définitions de textures/couleurs sont considérées comme part de la carte
- Chaque ligne de carte est ajoutée à une liste chaînée temporaire
- Les lignes vides avant la première ligne de carte sont ignorées
- Une ligne peut contenir des caractères valides (`0`, `1`, `N`, `S`, `E`, `W`, ` `) ou être rejetée

### Phase 3: Conversion et Validation de la Carte

**Conversion en grille 2D**:
- La liste chaînée est convertie en tableau 2D `char **map`
- Hauteur: nombre de lignes de carte accumulées
- Largeur: taille de la ligne la plus longue

**Validations imperatives**:

1. **Uniformité de largeur**: Toutes les lignes doivent avoir la même largeur (padding avec espaces si nécessaire)

2. **Joueur unique**: Il doit y avoir exactement une position de joueur (N, S, E, ou W)

3. **Fermeture spatiale** (Flood-fill):
   - À partir de la position du joueur, on parcourt tous les espaces (`0` et position joueur)
   - On vérifie que la zone accessible reste complètement entourée de murs (`1`)
   - Cela détecte les brèches dans les murs et les positions inaccessibles

4. **Limite personnage**: Le joueur ne peut pas être positionné sur une arête (bord de grille)

### Schéma du Flux de Parsing

```
Fichier .cub
     |
     v
Ouverture et lecture ligne par ligne (read_file)
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
     +--> Ligne de map ? --> Ajouter à liste chaînée
     |
     v
Conversion liste --> char **map (allocation mémoire)
     |
     v
Validation étape 1: Uniformité de largeur (padding)
     |
     v
Validation étape 2: Position joueur unique (détection N/S/E/W)
     |
     v
Validation étape 3: Fermeture spatiale (flood-fill depuis joueur)
     |
     v
Validation étape 4: Pas de joueur sur les bords
     |
     v
Succès: Retour structure t_file_data remplie OU Erreur: Libération et exit
```

### Gestion des Erreurs

Chaque étape de parsing peut générer une erreur:
- Fichier introuvable ou non-lisible
- Ligne mal formatée (texture ou couleur invalides)
- Métadonnées manquantes ou dupliquées
- Carte mal formée (pas assez de lignes, largeur variable, joueur manquant)
- Espace non-fermé (murs manquants, brèche détectée)

À la première erreur, le programme affiche un message expliquant le problème et s'arrête proprement.

### Intégration
Après parsing réussi, `t_file_data` contient la carte, les textures, les couleurs et la position du joueur. Cette structure est utilisée par le moteur de raycasting pour le rendu 3D. En cas d'erreur, le programme s'arrête sans initialiser le moteur graphique.

## DDA Algorithm (Digital Differential Analyzer)

Le DDA est un algorithme de traversée de grille utilisé dans le raycasting pour trouver les intersections entre un rayon et les murs de la carte. Voici comment il fonctionne:

1. **Initialisation**: À partir de la position du joueur et de la direction du rayon, on calcule les distances de pas pour les prochaines intersections en X et en Y.

2. **Traversée de grille**: On parcourt la grille de la carte en pas unitaires, en comparant les distances X et Y pour savoir quel axe franchir en premier.

3. **Détection de collision**: À chaque étape, on vérifie si la cellule actuelle contient un mur. Si oui, on a trouvé la collision. Si non, on continue.

4. **Direction du pas**: L'algorithme détermine si on bouge en X+, X-, Y+ ou Y- selon l'angle du rayon.

5. **Distance perpendiculaire**: Une fois le mur trouvé, on calcule la distance perpendiculaire (non directe) pour éviter l'effet fisheye (distorsion de l'image).

Le DDA est efficace car il n'utilise que des additions et des comparaisons, pas de multiplications coûteuses.

## Raycasting Overview

Le raycasting est la technique principale du moteur 3D de cub3D. Voici le processus:

1. **Lancement de rayons**: Pour chaque colonne de pixels à l'écran (800 rayons), on lance un rayon depuis la position du joueur à différents angles.

2. **Intersection avec les murs**: Chaque rayon utilise l'algorithme DDA pour trouver le mur le plus proche dans sa trajectoire.

3. **Calcul de la hauteur**: La distance au mur détermine la hauteur de la colonne de pixels à l'écran. Plus le mur est proche, plus la colonne est haute.

4. **Mapping de texture**: Pour chaque mur trouvé, on détermine quelle texture appliquer (North, South, East, West) et on calcule les coordonnées UV pour l'affichage correct.

5. **Rendu colonne par colonne**: Chaque colonne de pixels est remplie avec les données de texture calculées, créant l'illusion d'une vue 3D en perspective.

6. **Optimisation fisheye**: Sans correction, les rayons des bords donneraient une image distordue. On utilise la distance perpendiculaire pour corriger cela.

## Useful Resources

Sources de recherche pour le DDA et Raycasting:

DDA (Digital Differential Analyzer):
1. Algorithme DDA - Interactive Explanation
   https://aaaa.sh/creatures/dda-algorithm-interactive/

2. DDA Line Generation Algorithm - GeeksforGeeks
   https://www.geeksforgeeks.org/computer-graphics/dda-line-generation-algorithm-computer-graphics/

Raycasting:
3. Raycasting Tutorial - LoDevInfo
   https://lodev.org/cgtutor/raycasting.html

4. Raycasting Game Tutorial - YouTube
   https://www.youtube.com/watch?v=G9i78WoBBIU

5. Raycasting: De Doom a Wolfenstein
   https://guy-grave.developpez.com/tutoriels/jeux/doom-wolfenstein-raycasting/

6. Raycasting - Wikipedia
   https://fr.wikipedia.org/wiki/Raycasting

Implementation Cub3D:
7. Cub3D Nathaan Implementation
   https://nathaan.me/projects/cub3d

## Made by
-Lebrou Hadia