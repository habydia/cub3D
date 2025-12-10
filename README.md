# cub3D
parsing (analyse des fichiers), rendu graphique, gestion des événements (clavier/souris), et optimisation. Vous êtes chargé de la partie parsing, qui est cruciale car elle permet de charger et valider les données d'entrée avant le rendu.



Extraire : Identifier et isoler les parties utiles de la ligne (e.g., chemin pour textures, valeurs RGB pour couleurs).
Parser : Analyser et convertir les données (e.g., découper RGB en entiers, valider le format).
Stocker : Sauvegarder dans t_file_data pour utilisation ultérieure (rendu, validation).
Cela permet de traiter textures (NO/SO/WE/EA) et couleurs (F/C) avant la map, avec gestion d'erreurs.