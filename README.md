# cub3D

## Description
cub3D est un projet de l'école 42 implémentant un moteur de jeu 3D simple en C, inspiré de Wolfenstein 3D. Le jeu utilise le raycasting pour créer un environnement 3D navigable à partir d'une carte 2D.

Le projet est divisé en plusieurs parties : parsing (analyse des fichiers), rendu graphique, gestion des événements (clavier/souris), et optimisation. Vous êtes chargé de la partie parsing, qui est cruciale car elle permet de charger et valider les données d'entrée avant le rendu.

## Parsing Overview
Le parsing transforme un fichier `.cub` en structures de données utilisables :
- **Extraire** : Identifier et isoler les parties utiles de la ligne (e.g., chemin pour textures, valeurs RGB pour couleurs).
- **Parser** : Analyser et convertir les données (e.g., découper RGB en entiers, valider le format).
- **Stocker** : Sauvegarder dans `t_file_data` pour utilisation ultérieure (rendu, validation).
Cela permet de traiter textures (NO/SO/WE/EA) et couleurs (F/C) avant la map, avec gestion d'erreurs.

## Parsing de la Map - Explication Détaillée

### Vue d'ensemble
La map est la section du fichier `.cub` décrivant le labyrinthe 2D. Elle est parsée en deux phases :
1. **Collecte** : Pendant la lecture, chaque ligne de map est ajoutée à une liste temporaire.
2. **Finalisation** : Après lecture, la liste est convertie en tableau 2D et validée.

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

### Étapes Détaillées

#### 1. Collecte des Lignes (`process_map`)
- **Entrée** : Ligne du fichier (e.g., "111", "1N1").
- **Action** : Ajouter à `data->map_lines` (liste chaînée) si non vide.
- **Sortie** : Liste de lignes brutes.

#### 2. Conversion en Tableau 2D (`to_2d_map`)
- **Entrée** : Liste `map_lines`.
- **Action** : Allouer `data->map` (tableau de chaînes), copier les lignes.
- **Sortie** : `data->map` (char **), `data->map_height`.

#### 3. Validation de la Largeur (`validate_width`)
- **Règle** : Toutes les lignes doivent avoir la même longueur.
- **Action** : Mesurer `ft_strlen` de chaque ligne, comparer.
- **Erreur** : "Map lines have different widths".

#### 4. Validation du Joueur (`validate_player`)
- **Règle** : Exactement un `N/S/E/W`.
- **Action** : Parcourir la map, compter, enregistrer position/direction.
- **Erreur** : "Multiple players" ou "No player".

#### 5. Validation de la Fermeture (`validate_closure`)
- **Règle** : Map entourée de murs (`1`), pas de trous.
- **Action** : Flood fill depuis le joueur, vérifier que tous `0` sont accessibles.
- **Erreur** : "Map is not closed".

### Exemple
Fichier `.cub` :
```
NO wall.xpm
F 100,100,100
111
1N1
111
```

- **Collecte** : Lignes "111", "1N1", "111" dans liste.
- **Conversion** : `map[0] = "111"`, `map[1] = "1N1"`, `map[2] = "111"`, `height=3`, `width=3`.
- **Validations** : Largeur OK, joueur N à (1,1), fermée.

### Intégration
Après parsing réussi, `t_file_data` est utilisé pour le rendu 3D. En cas d'erreur, le programme s'arrête.

## Installation et Utilisation
- `make` : Compiler le projet.
- `./cub3D maps/map.cub` : Lancer le jeu avec une map valide.

