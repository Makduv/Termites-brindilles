# Projet : Simulation de termites rassemblant des brindilles

## ✨ Objectif
Simuler le comportement de termites déplaçant aléatoirement des brindilles pour les regrouper en un seul tas.

## 🔍 Principes de fonctionnement
- Grille 2D avec termites et brindilles placées aléatoirement
- Chaque termite :
  1. Se déplace aléatoirement
  2. Ramasse une brindille devant lui
  3. Se redéplace aléatoirement
  4. Pose la brindille sur une case vide
- Les termites agissent "en même temps" à chaque itération

## 📄 Fichiers fournis
- `coord.h` / `coord.cpp` : gestion des coordonnées et des directions
- `projet.cpp` : test manuel des déplacements directionnels
- `testcoord.cpp` : tests unitaires
- `Makefile`, `coord.o`, `testCoord.o` : compilation partielle

## 🔧 Etapes de réalisation 

### 1. Types abstraits fondamentaux
- Coord : position (x, y)
- Direction : {N, NE, E, SE, S, SO, O, NO}
- Fonctions disponibles : `creeCoord`, `devantCoord`, `aDroite`, `aGauche`, `egalCoord`, etc.

### 2. Grille
- Type `Grille` : tableau 2D de `Case`
- `Case` contient : brindille (bool), termite (int = numéro ou -1)
- Fonctions : `poseBrindille`, `enleveBrindille`, `poseTermite`, `enleveTermite`, etc.

### 3. Termite
- Direction, position, si il porte une brindille, sablier
- Tableau de termites
- Fonctions : `directionTermite`, `devantTermite`, `porteBrindille`, `tourneAleat`, `avanceTermite`, `chargeTermite`, `dechargeTermite`

### 4. Algorithme principal
- Fonction `rassemblerBrindille()` avec sablier de 6 pas entre ramassage/dépôt
- Tourne jusqu'à trouver case libre
- Empêche qu'un termite se bloque en posant une brindille

### 5. Interface utilisateur
- `getchar()` pour avancer itération par itération
- Touche `.` pour quitter, `*` ou `/` pour accélérer / ralentir

### 6. Affichage
- `cout` pour grille
- Symboles termites selon direction : `/`, `\`, `-`, `|`

### 7. Organisation des fichiers
- `termite.cpp` + `termite.h`
- `grille.cpp` + `grille.h`
- `main.cpp` pour l'algo principal et l'affichage

### 8. Bonus possibles
- Affichage SFML
- Algorithme plus intelligent
- Grille torique ou tunnels

---

## ⚡ Compilation & Tests
- Compiler avec : `make`
- Lancer : `./projet`
- Lancer tests : `./testcoord`

---

## 🕊 Structure recommandée du projet
```
projet/
├── coord.h / coord.cpp         # Coordonnées et directions
├── grille.h / grille.cpp       # Grille et gestion des cases
├── termite.h / termite.cpp     # Comportement d'un termite
├── main.cpp                   # Simulation principale
├── Makefile
└── testcoord.cpp             # Tests unitaires sur coord
```
