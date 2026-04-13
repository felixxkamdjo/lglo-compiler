# Rapport de projet — Compilateur LGLo

**Cours** : Théorie des Langages et Compilation  
**Enseignant** : MANDA ABEGA DEA GIA - ARII  
**Groupe** : 02  
**Membres** : NJAI-LOBE Daniella, KAMDJO Félix Junior, KAMFO KAMFO Idriss, LISSOM Kenzo, MBADZO TAYO Richenelle, KOMBOU Danielle  

---

## 1. Introduction

La théorie des langages et la compilation constituent l'un des piliers fondamentaux de l'informatique théorique et appliquée. Comprendre comment un langage de programmation naît — depuis la définition formelle de sa grammaire jusqu'à la construction d'un compilateur capable de le traduire en instructions exécutables — c'est toucher à l'essence même de ce qui fait d'un ordinateur une machine programmable. C'est dans cette perspective que s'inscrit le présent projet, réalisé dans le cadre du cours de Théorie des Langages et Compilation.

La tâche assignée consistait à partir d'une grammaire initiale minimaliste décrivant une unique instruction d'affectation, et d'en étendre significativement le périmètre pour concevoir, spécifier et implémenter un compilateur complet pour un langage original désigné sous le nom de **LGLo** — *Langage de Génération Logique*.

Le présent rapport documente l'ensemble de la démarche : les choix de conception du langage, la grammaire formelle et ses règles BNF, l'architecture du compilateur, et le détail de chaque composant implémenté.

---

## 2. Présentation du langage LGLo

### 2.1 Philosophie de conception

LGLo emprunte la rigueur syntaxique de C/C++ (accolades, opérateur `<--` issu de la grammaire originale, terminateur d'instruction `#`), la sécurité de Rust (déclaration explicite de mutabilité avec `mut`), et introduit une couche d'originalité à travers un vocabulaire issu du **latin technique** — pragmatique, mémorisable, et résolument distinct des langages de programmation populaires.

### 2.2 Mots-clés du langage

| Rôle | Mot-clé | Inspiration |
|------|---------|-------------|
| Variable mutable | `mut` | Rust |
| Constante | `imm` | Latin *immutabilis* |
| Lecture | `captum` | Latin *capere* (capturer) |
| Écriture | `emittum` | Latin *emittere* (émettre) |
| Fonction | `functio` | Latin direct |
| Procédure | `actio` | Latin *actio* (action) |
| Retour | `reddere` | Latin *reddere* (rendre) |
| Condition | `quia` | Latin *quia* (si/car) |
| Sinon | `aliter` | Latin *aliter* (autrement) |
| Boucle while | `dum` | Latin *dum* (tant que) |
| Boucle for | `iter` | Latin *iter* (chemin) |
| Fin instruction | `#` | Grammaire originale |
| Affectation | `<--` | Grammaire originale |

### 2.3 Types primitifs

| Type | Mot-clé | Équivalent courant |
|------|---------|-------------------|
| Entier | `integer` | `int` |
| Réel | `reales` | `float` / `double` |
| Chaîne | `catena` | `string` |
| Booléen | `bina` | `bool` |
| Vide | `nullum` | `void` |
| Vrai | `verum` | `true` |
| Faux | `falsum` | `false` |

### 2.4 Exemple de programme LGLo

```
(* calcul de la factorielle *)
functio integer factorielle(integer n) {
    quia(n <= 1) {
        reddere 1 #
    }
    reddere n * factorielle(n - 1) #
}

mut integer resultat <-- factorielle(5) #
emittum(resultat) #
```

---

## 3. Grammaire formelle

### 3.1 Définition

La grammaire de LGLo est définie comme un quadruplet **G = (VN, VT, AXI, P)** où :

- **VN** est l'ensemble des symboles non-terminaux
- **VT** est l'ensemble des symboles terminaux
- **AXI** est l'axiome de départ
- **P** est l'ensemble des règles de production

La grammaire est construite dans l'esprit des grammaires **LL(1)** : chaque règle est déterminée par un token distinctif unique, ce qui rend l'analyse prédictive et minimise les conflits *shift/reduce* dans Bison.

### 3.2 Règles BNF principales

```
AXI         → liste_inst

liste_inst  → liste_inst instruction
            | instruction

instruction → affectation #
            | declaration #
            | lecture #
            | ecriture #
            | condition
            | boucle_dum
            | boucle_iter
            | def_functio
            | def_actio
            | appel #
            | reddere expr #

declaration → mut TYPE identi
            | mut TYPE identi <-- expr
            | imm TYPE identi <-- expr

condition   → quia ( expr_bool ) bloc
            | quia ( expr_bool ) bloc aliter bloc
            | quia ( expr_bool ) bloc aliter condition

boucle_iter → iter ( identi in expr de expr jusqua expr ) bloc
```

### 3.3 Justifications de conception

**Distinction `functio` / `actio`** — contrairement à C/C++ qui unifie les deux sous `function`, LGLo impose une distinction explicite entre une fonction qui calcule et retourne une valeur (`functio` + `reddere`) et une procédure qui agit sans retour (`actio`). Cette distinction rend le code plus lisible et oblige le développeur à réfléchir à la sémantique de chaque sous-programme.

**La constante `imm`** — inspirée de Rust, elle exige une valeur à la déclaration. Il est syntaxiquement impossible d'écrire `imm integer x #` sans initialisation. Cette contrainte est vérifiable directement à l'analyse syntaxique.

**La boucle `iter`** — la syntaxe `iter(i in 0 de 2 jusqua 10)` se lit naturellement : *itère i, en partant de 0, par pas de 2, jusqu'à 10 exclu*. Le paramètre `de` (le pas) est obligatoire, ce qui élimine toute ambiguïté lors de l'analyse.

**Le terminateur `#`** — conservé de la grammaire originale, il constitue un marqueur identitaire fort pour LGLo et simplifie la gestion des erreurs dans Bison : une instruction mal formée est détectée immédiatement.

---

## 4. Architecture du compilateur

### 4.1 Vue d'ensemble

Le compilateur LGLo suit le pipeline classique en trois phases :

```
Source .lglo
     |
     v
[ Analyse lexicale ]   — Flex   — lexer.l
     |
     v  tokens
[ Analyse syntaxique ] — Bison  — parser.y  →  AST
     |
     v  ASTNode*
[ Analyse sémantique ] — C      — semantic.c
     |
     v
  Résultat
```

### 4.2 Description des composants

| Fichier | Rôle |
|---------|------|
| `lexer.l` | Analyse lexicale — reconnaissance des tokens |
| `parser.y` | Analyse syntaxique — construction de l'AST |
| `ast.h / ast.c` | Définition et constructeurs de l'AST |
| `semantic.h / semantic.c` | Analyse sémantique — table des symboles |
| `error.h / error.c` | Gestion centralisée des erreurs |
| `global.h` | Constantes et codes de retour globaux |
| `main.c` | Point d'entrée — orchestre les trois phases |

---

## 5. Analyse lexicale — `lexer.l`

### 5.1 Rôle

Le fichier `lexer.l` est traité par **Flex** pour produire un analyseur lexical en C. Il lit le source LGLo caractère par caractère et retourne à Bison une suite de *tokens* — les unités atomiques du langage.

### 5.2 Principes appliqués

**Longest match** — Flex applique toujours la règle qui correspond à la séquence la plus longue. Ainsi `<--` est reconnu comme un seul token `AFFECT` et non comme `<` suivi de `--`.

**Priorité des règles** — en cas d'égalité de longueur, Flex choisit la première règle définie. Les mots-clés sont donc définis avant le pattern général `IDENTI`, garantissant que `dum` ne soit jamais tokenisé comme un identifiant.

**Ordre des opérateurs** — les opérateurs à deux caractères (`<=`, `>=`, `==`, `!=`) précèdent leurs homologues à un caractère (`<`, `>`) pour la même raison.

### 5.3 Extrait illustratif

```c
/* mots-cles de controle */
"quia"    { return QUIA;   }
"aliter"  { return ALITER; }
"dum"     { return DUM;    }
"iter"    { return ITER;   }

/* identifiant — apres tous les mots-cles */
{IDENTI}  { yylval.chaine = strdup(yytext); return IDENTI; }

/* nombre reel avant nombre entier, obligatoire */
{NOMBRE_REEL}    { yylval.reel   = atof(yytext); return NOMBRE_REEL;    }
{NOMBRE_ENTIER}  { yylval.entier = atoi(yytext); return NOMBRE_ENTIER;  }
```

---

## 6. Analyse syntaxique — `parser.y`

### 6.1 Rôle

Le fichier `parser.y` est traité par **Bison** pour produire un analyseur syntaxique LALR(1) en C. Il reçoit les tokens du lexer, vérifie leur agencement selon les règles BNF, et construit l'AST en appelant les fonctions `ast_*()` à chaque réduction.

### 6.2 Gestion des priorités

Les conflits d'ambiguïté sur les expressions arithmétiques et booléennes sont résolus par les directives `%left` et `%right`. Le cas particulier du moins unaire (`-x`) est traité avec `%prec UMINUS`, une pseudo-priorité qui le distingue du moins binaire (`a - b`) sans modifier le token `MOINS`.

```
%left  OU
%left  ET
%right NON
%left  INF SUP INF_EG SUP_EG EGAL DIFF
%left  PLUS MOINS
%left  MULT DIV MOD
%right UMINUS
```

### 6.3 Extrait illustratif

```c
/* structure conditionnelle avec chaine aliter quia */
condition
    : QUIA PAREN_OUV expr_bool PAREN_FER bloc
        { $$ = ast_quia($3, $5, NULL); }
    | QUIA PAREN_OUV expr_bool PAREN_FER bloc ALITER bloc
        { $$ = ast_quia($3, $5, $7); }
    | QUIA PAREN_OUV expr_bool PAREN_FER bloc ALITER condition
        { $$ = ast_quia($3, $5, $7); }
    ;
```

---

## 7. Abstract Syntax Tree — `ast.h / ast.c`

### 7.1 Rôle

L'AST (*Abstract Syntax Tree*) est la représentation en mémoire du programme source après l'analyse syntaxique. Chaque construction du langage — déclaration, affectation, condition, boucle, appel — correspond à un type de noeud précis.

### 7.2 Structure d'un noeud

Chaque noeud est une structure C combinant un champ `type` (l'énumération `NodeType`) et une `union` contenant les données propres à chaque variante. L'`union` garantit que chaque noeud n'occupe en mémoire que la place nécessaire à sa variante.

```c
typedef struct ASTNode {
    NodeType type;
    union {
        int     valeur_entier;
        float   valeur_reel;
        char   *valeur_chaine;
        struct { struct ASTNode *gauche; struct ASTNode *droite; } liste;
        struct { char *type_var; char *nom; struct ASTNode *init; } decl;
        /* ... */
    } data;
} ASTNode;
```

### 7.3 Affichage de l'AST (mode debug)

La fonction `ast_afficher()` permet de visualiser l'arbre construit dans le terminal. Pour le programme `mut integer x <-- 5 #`, la sortie produite est :

```
[Programme]
  [Decl mut] integer x
    init =>
      [Entier] 5
```

---

## 8. Analyse sémantique — `semantic.c`

### 8.1 Rôle

L'analyse sémantique intervient après la construction de l'AST. Elle parcourt l'arbre récursivement et effectue des vérifications que la grammaire seule ne peut pas exprimer.

### 8.2 Table des symboles

La table des symboles est une liste chaînée de structures `Symbole`. Chaque entrée mémorise le nom, le type, la catégorie (`SYM_VARIABLE`, `SYM_CONSTANTE`, `SYM_FUNCTIO`, `SYM_ACTIO`) et la portée (*scope*) du symbole.

La portée est gérée par un compteur entier : `ts_ouvrir_portee()` l'incrémente à chaque entrée dans un bloc `{ }`, `ts_fermer_portee()` le décrémente et supprime tous les symboles de la portée fermée.

### 8.3 Vérifications effectuées

- Toute variable utilisée a été déclarée au préalable
- Aucun identifiant n'est déclaré deux fois dans la même portée
- Une constante `imm` n'est jamais réaffectée
- Les types sont compatibles dans les affectations et les expressions
- Le type retourné par `reddere` correspond au type de retour déclaré de la `functio`
- La variable d'itération d'un bloc `iter` est locale à ce bloc

### 8.4 Extrait illustratif

```c
case N_AFFECT: {
    Symbole *s = ts_chercher(ts, n->data.affect.cible);
    if (!s) {
        erreur_variable_non_declaree(n->data.affect.cible, 0);
        nb_erreurs++;
        break;
    }
    if (s->categorie == SYM_CONSTANTE) {
        erreur_affectation_constante(n->data.affect.cible, 0);
        nb_erreurs++;
        break;
    }
    char *type_val = analyser_expr(n->data.affect.valeur, ts);
    if (type_val && strcmp(type_val, s->type) != 0) {
        erreur_type_incompatible(s->type, type_val, 0);
        nb_erreurs++;
    }
    break;
}
```

---

## 9. Gestion des erreurs

Les erreurs sont centralisées dans `error.h / error.c` et organisées en quatre catégories correspondant aux phases du compilateur :

| Catégorie | Préfixe affiché | Déclencheur |
|-----------|-----------------|-------------|
| Lexicale | `[Erreur lexicale]` | Caractère non reconnu par Flex |
| Syntaxique | `[Erreur syntaxique]` | Règle BNF non respectée |
| Sémantique | `[Erreur semantique]` | Violation de type, portée, constante |
| Fatale | `[Erreur fatale]` | Échec interne non récupérable |

L'analyse sémantique accumule toutes les erreurs via un compteur `nb_erreurs` avant de rendre son verdict — elle ne s'arrête pas à la première erreur détectée.

---

## 10. Compilation et exécution

### 10.1 Commandes

```bash
# compilation standard
make

# compilation avec affichage de l'AST
make debug

# execution sur un programme valide
./build/lglo_compiler tests/valid/factorial.lglo

# nettoyage
make clean
```

### 10.2 Ordre de génération

Le `Makefile` respecte l'ordre de dépendance suivant :

1. **Bison** génère `parser.tab.c` et `parser.tab.h` depuis `parser.y`
2. **Flex** génère `lexer.c` depuis `lexer.l` (nécessite `parser.tab.h`)
3. **GCC** compile et lie tous les fichiers C pour produire l'exécutable

---

## 11. Conclusion

Ce projet a permis de mettre en pratique l'ensemble de la chaîne de compilation — de la spécification formelle d'un langage à son implémentation complète avec Flex et Bison. La conception du langage LGLo, avec son vocabulaire latin original et ses règles inspirées de plusieurs paradigmes modernes, a constitué un exercice de réflexion autant que d'implémentation.

Les trois phases du compilateur — analyse lexicale, syntaxique et sémantique — ont été implémentées de manière modulaire et cohérente, chaque composant ayant un rôle bien délimité et des interfaces clairement définies. L'AST constitue le pivot central qui relie ces phases entre elles.