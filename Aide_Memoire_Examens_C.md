# Aide-mémoire C pour l’examen

Ce document résume les notions et fonctions que vous avez utilisées dans vos dossiers et exercices de programmation C.

---

## 1. Bases de C à retenir

### Entrées / sorties
- `printf("...")` : afficher un message
- `scanf("%d", &x)` : lire une valeur entière
- `scanf("%f", &x)` : lire un nombre décimal
- `scanf("%s", chaine)` : lire une chaîne de caractères

Exemple :
```c
int age;
printf("Entrez votre age : ");
scanf("%d", &age);
printf("Age : %d\n", age);
```

---

## 2. Fonctions utiles vues dans vos exercices

### 2.1 Fonction qui calcule somme et produit
Fichier : `Labo_Tableau-Pointeur/Exercice_Tableau-Pointeur.c`

```c
void sommeEtProduit(int *tab, int taille, int *somme, int *produit)
```

Utilisation :
- `tab` = tableau d’entiers
- `taille` = nombre d’éléments
- `somme` et `produit` = variables à remplir

Exemple :
```c
int tab[5] = {1, 2, 3, 4, 5};
int somme, produit;

sommeEtProduit(tab, 5, &somme, &produit);
printf("Somme = %d\n", somme);
printf("Produit = %d\n", produit);
```

---

### 2.2 Fonction qui modifie une variable avec un pointeur
Fichier : `Pointeur/1-Pointeur/Pointeur1.c`

```c
void modification(int *nombre)
```

Utilisation :
- on passe l’adresse de la variable
- la fonction modifie la valeur directement

Exemple :
```c
int x = 10;
modification(&x);
```

---

### 2.3 Fonction qui échange deux valeurs
Fichier : `Pointeur/1-Pointeur/Exercice_Pointeur.c`

```c
int echange(int *nombre1, int *nombre2)
```

Utilisation :
```c
int a = 5, b = 8;
echange(&a, &b);
```

---

### 2.4 Fonction logarithme népérien
Fichier : `Labo_Fonction/main.c`

```c
float LogNeperien(float x, float n)
```

Utilisation :
- `x` = valeur de départ
- `n` = nombre d’itérations

Exemple :
```c
float result = LogNeperien(2, 5);
printf("Resultat = %f\n", result);
```

---

### 2.5 Fonction de saisie d’un choix
Fichier : `Labo_Fonction/main.c`

```c
float Encodage_de_N_et_X(int Choix)
```

Utilisation :
- `Choix = 1` pour saisir `x`
- `Choix = 2` pour saisir `n`

Exemple :
```c
float x = Encodage_de_N_et_X(1);
float n = Encodage_de_N_et_X(2);
```

---

### 2.6 Fonction d’affichage
Fichier : `Labo_Fonction/main.c`

```c
void Affichage_du_resultat(float x, float n)
```

Utilisation :
```c
Affichage_du_resultat(x, n);
```

---

### 2.7 Fonction qui traite un tableau
Fichier : `Labo_Fonction/main.c`

```c
void Resultat_Tableau(void)
```

Utilisation :
- remplit un tableau aléatoire
- applique `LogNeperien`
- affiche les résultats

---

## 3. Pointeurs : formule essentielle

### Déclaration
```c
int *p;
```

### Adresse d’une variable
```c
p = &x;
```

### Valeur pointée
```c
*p = 10;
```

### Exemple complet
```c
int x = 5;
int *p = &x;

printf("x = %d\n", x);
printf("*p = %d\n", *p);
```

### Règle importante
- `&x` = adresse de `x`
- `*p` = valeur stockée à l’adresse contenue dans `p`

---

## 4. Tableaux

### Déclaration
```c
int tab[5];
```

### Initialisation
```c
int tab[5] = {1, 2, 3, 4, 5};
```

### Accès à un élément
```c
tab[0]
```

### Passage à une fonction
```c
void fonction(int tab[], int taille)
```

---

## 5. Structures

Les exercices de structures utilisent des `struct` pour regrouper des données.

Exemple :
```c
struct data {
    int age;
    char nom[20];
};
```

Utilisation :
```c
struct data personne;
personne.age = 20;
```

---

## 6. Bonnes habitudes pour l’examen

1. Toujours déclarer les fonctions avant `main()` si vous les utilisez.
2. Utiliser `&` avec `scanf`.
3. Utiliser `*` avec les pointeurs.
4. Vérifier les types (`int`, `float`, `char`).
5. Bien nommer les fonctions pour qu’elles soient faciles à comprendre.

---

## 7. Mini résumé rapide

- `printf` → afficher
- `scanf` → lire
- `&x` → adresse d’une variable
- `*p` → valeur pointée
- Les fonctions permettent de séparer le code en blocs simples
- Les tableaux et les pointeurs sont souvent utilisés ensemble

---

## 8. Conseils pour réviser

Révisez surtout :
- les pointeurs,
- les fonctions avec paramètres,
- les tableaux,
- les structures,
- l’usage de `scanf` et `printf`.

Si vous voulez, je peux ensuite vous faire une version encore plus courte, sous forme de fiche 1 page, prête à imprimer.
