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
│   │   ├── lexer.l
│   │
│   ├── parser/
│   │   ├── parser.y
│   │   └── parser.tab.h
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
├── build/
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
| `tokens.h` | Déclaration des tokens utilisés par Bison |

#### `parser/`

| Fichier | Rôle |
|---------|------|
| `parser.y` | Règles syntaxiques (grammaire BNF vers Bison) |
| `parser.tab.h` | Fichier généré automatiquement par Bison |

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
| `expected/` | Sorties de référence pour la validation automatique (optionnel) |

---

### `docs/`

Documentation technique du projet, incluant la grammaire formelle et les règles BNF du langage LGLo.

---

### `build/`

Répertoire de sortie de la compilation. Contient les fichiers intermédiaires générés (`lexer.c`, `parser.c`) ainsi que l'exécutable final.

---

### `Makefile`

Automatise l'ensemble du processus de compilation : génération des fichiers Flex et Bison, compilation des sources C, production de l'exécutable.

---

### `.gitignore`

Exclut du dépôt les fichiers temporaires, les fichiers générés automatiquement et les binaires compilés.

---

## Installation des outils

### Prérequis

Les outils suivants doivent être installés sur la machine :

- `gcc`
- `flex`
- `bison`
- `make`

### Installation (Linux / Debian / Ubuntu)

```bash
sudo apt update
sudo apt install build-essential flex bison
```

### Vérification des versions

```bash
flex --version
bison --version
gcc --version
```

---

## Compilation du projet

Depuis la racine du projet :

```bash
make
```

Cette commande génère les fichiers Flex et Bison, compile l'ensemble des sources et produit l'exécutable dans le dossier `build/`.

---

## Exécution

```bash
./build/lglo_compiler <fichier_source.lglo>
```

Exemple :

```bash
./build/lglo_compiler tests/valid/test1.lglo
```

---

## Tests

### Programme valide

```bash
./build/lglo_compiler tests/valid/factorial.lglo
```

Le compilateur doit analyser le fichier sans émettre d'erreur.

### Programme invalide

```bash
./build/lglo_compiler tests/invalid/missing_hash.lglo
```

Le compilateur doit détecter et signaler l'erreur syntaxique correspondante.

---

## Auteurs

Projet réalisé par le **Groupe 02** dans le cadre du cours de Théorie des Langages et Compilation.

| Nom | Prénom |
|-----|--------|
| NDJAI-LOBE | Daniella |
| KAMDJO | Félix Junior |
| KAMFO KAMFO | Idriss |
| LISSOM | Kenzo |
| MBADZO TAYO | Richenelle |
| KOMBOU | Danielle |

---

## Licence

Projet académique — usage pédagogique exclusif.