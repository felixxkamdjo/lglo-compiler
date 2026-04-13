# LGLo Compiler

## Description

Le **LGLo Compiler** est un projet académique réalisé dans le cadre du cours de **Théorie des Langages et Compilation**.
Il consiste à concevoir et implémenter un compilateur pour le langage **LGLo** *(Langage de Génération Logique)*, à partir d'une grammaire formelle définie en BNF.

Le langage LGLo est un langage impératif inspiré de plusieurs paradigmes modernes, intégrant :

- des déclarations de variables et constantes (`mut`, `imm`)
- des structures de contrôle (`quia`, `aliter`, `dum`, `iter`)
- des entrées/sorties (`captum`, `emittum`)
- des fonctions (`functio`) et procédures (`actio`)

Le compilateur repose sur les outils classiques :

- **Flex** pour l'analyse lexicale
- **Bison** pour l'analyse syntaxique

---

## Architecture du projet

```
lglo-compiler/
│
├── src/
│   ├── lexer/
│   │   └── lexer.l
│   │
│   ├── parser/
│   │   └── parser.y
│   │
│   ├── ast/
│   │   ├── ast.h
│   │   └── ast.c
│   │
│   ├── semantic/
│   │   ├── semantic.h
│   │   └── semantic.c
│   │
│   ├── utils/
│   │   ├── error.h
│   │   └── error.c
│   │
│   └── main.c
│
├── include/
│   └── global.h
│
├── tests/
│   ├── valid/
│   ├── invalid/
│   └── expected/
│
├── docs/
│   └── grammaire.pdf
│
├── Makefile
├── README.md
└── .gitignore
```

---

## Description des dossiers et fichiers

### `src/`

Contient le cœur du compilateur.

#### `lexer/`

| Fichier | Rôle |
|---------|------|
| `lexer.l` | Définit les règles lexicales (tokens du langage LGLo) |

#### `parser/`

| Fichier | Rôle |
|---------|------|
| `parser.y` | Règles syntaxiques (grammaire BNF vers Bison) |
| `parser.tab.h` | Fichier généré automatiquement par Bison — ne pas modifier |

#### `ast/`

Contient les structures de l'**Abstract Syntax Tree (AST)**. Permet de représenter le programme source sous une forme arborescente structurée, utilisée pour les passes d'analyse ultérieures.

#### `semantic/`

Prend en charge les vérifications sémantiques :

- vérification que toute variable utilisée a été déclarée
- respect des contraintes de type entre les opérandes
- application des contraintes propres au langage (`imm`, `nullum`, etc.)

#### `utils/`

Regroupe les fonctions utilitaires transversales, notamment la gestion et le formatage des messages d'erreur.

#### `main.c`

Point d'entrée du compilateur. Reçoit le fichier source LGLo en argument, initialise les différentes phases d'analyse et orchestre leur exécution.

---

### `include/`

Contient les définitions et déclarations globales partagées entre les différents modules du compilateur (`global.h`).

---

### `tests/`

| Dossier | Contenu |
|---------|---------|
| `valid/` | Programmes LGLo syntaxiquement et sémantiquement corrects |
| `invalid/` | Programmes contenant des erreurs intentionnelles |
| `expected/` | Sorties de référence pour la validation automatique |

---

### `docs/`

Documentation technique du projet, incluant la grammaire formelle et les règles BNF du langage LGLo.

---

### `Makefile`

Automatise l'ensemble du processus de compilation : génération des fichiers Flex et Bison, compilation des sources C, production de l'exécutable dans `build/`.

---

### `.gitignore`

Exclut du dépôt les fichiers temporaires, les fichiers générés automatiquement et les binaires compilés.

---

## Installation et configuration

### Linux / Debian / Ubuntu

#### Prérequis

```bash
sudo apt update
sudo apt install build-essential flex bison
```

#### Vérification

```bash
gcc --version
flex --version
bison --version
make --version
```

---

### Windows — via MSYS2

MSYS2 est un environnement de développement pour Windows qui fournit GCC, Flex, Bison et Make dans un terminal compatible Unix.

#### Étape 1 — Installer MSYS2

Télécharger l'installateur depuis le site officiel :

```
https://www.msys2.org
```

Lancer l'installateur et suivre les étapes. Le répertoire d'installation par défaut est `C:\msys64`.

Une fois installé, ouvrir le terminal **MSYS2 MinGW 64-bit** (et non MSYS2 MSYS).

#### Étape 2 — Mettre à jour MSYS2

```bash
pacman -Syu
```

Fermer le terminal si demandé, le rouvrir, puis finaliser la mise à jour :

```bash
pacman -Su
```

#### Étape 3 — Installer GCC, Flex et Bison

```bash
pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-flex mingw-w64-x86_64-bison
```

#### Étape 4 — Installer Make

```bash
pacman -S mingw-w64-x86_64-make
```

Make est installé sous le nom `mingw32-make.exe`. Il faut le renommer en `make.exe` pour que le `Makefile` fonctionne sans modification.

Se rendre dans le dossier `bin` de MinGW :

```bash
cd C:\msys64\mingw64\bin
```

Puis copier l'exécutable sous le bon nom :

```bash
cp mingw32-make.exe make.exe
```

#### Étape 5 — Vérification

```bash
gcc --version
flex --version
bison --version
make --version
```

Tous les outils doivent répondre avec leur numéro de version.

#### Étape 6 — Ajouter MinGW au PATH Windows (si nécessaire)

Si les commandes ne sont pas reconnues en dehors du terminal MSYS2, ajouter `C:\msys64\mingw64\bin` aux variables d'environnement système :

- Ouvrir **Paramètres** > **Système** > **Paramètres système avancés**
- Cliquer sur **Variables d'environnement**
- Dans **Variables système**, sélectionner `Path` et cliquer sur **Modifier**
- Ajouter `C:\msys64\mingw64\bin`
- Valider et redémarrer le terminal

---

## Compilation du projet

Cloner le dépôt et se placer à la racine :

```bash
git clone <url-du-depot>
cd lglo-compiler
```

Compiler :

```bash
make
```

Cette commande génère les fichiers Flex et Bison dans `build/`, compile l'ensemble des sources C et produit l'exécutable `build/lglo_compiler`.

Pour nettoyer les fichiers générés :

```bash
make clean
```

Pour compiler en mode debug (affiche l'AST dans le terminal) :

```bash
make debug
```

---

## Exécution

```bash
./build/lglo_compiler <fichier_source.lglo>
```

Exemple :

```bash
./build/lglo_compiler tests/valid/test1.lglo
```

Sortie attendue :

```
Compilation de : tests/valid/test1.lglo
[OK] Analyse syntaxique reussie.
[OK] Analyse semantique reussie.
[OK] Compilation terminee avec succes.
```

---

## Tests

### Programme valide

```bash
./build/lglo_compiler tests/valid/factorial.lglo
```

Le compilateur analyse le fichier et retourne les trois messages `[OK]`.

### Programme invalide — erreur syntaxique

```bash
./build/lglo_compiler tests/invalid/missing_hash.lglo
```

Le compilateur détecte et signale les instructions dont le terminateur `#` est absent.

### Programme invalide — erreurs sémantiques

```bash
./build/lglo_compiler tests/invalid/wrong_decl.lglo
```

Le compilateur signale les violations sémantiques : variable non déclarée, double déclaration, modification d'une constante `imm`, incompatibilité de types.

---

## Auteurs

Projet réalisé par le **Groupe 02** dans le cadre du cours de Théorie des Langages et Compilation.

| Nom | Prénom |
|-----|--------|
| NJAI-LOBE | Daniella |
| KAMDJO | Félix Junior |
| KAMFO KAMFO | Idriss |
| LISSOM | Kenzo |
| MBADZO TAYO | Richenelle |
| KOMBOU | Danielle |

---

## Licence

Projet académique — usage pédagogique exclusif.