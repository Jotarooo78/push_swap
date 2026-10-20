# push_swap

Programme en C qui trie une pile d'entiers en utilisant un nombre minimal d'opérations, avec deux piles et un jeu d'instructions restreint. Projet de l'école 42.

## Principe
- Deux piles, `a` (nombres à trier) et `b` (vide au départ)
- Instructions autorisées : `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`
- Objectif : afficher la plus courte suite d'instructions qui trie `a` par ordre croissant

## Notions abordées
- Complexité algorithmique et optimisation du nombre de coups
- Algorithmes de tri adaptés selon la taille de l'entrée (petites piles, grandes piles)
- Structures de données : listes chaînées, piles
- Validation des entrées (doublons, dépassement d'entier, caractères invalides)
- Gestion mémoire

## Stack
C, Makefile

## Installation et utilisation
```bash
git clone git@github.com:Jotarooo78/push_swap.git
cd push_swap
make
./push_swap 3 2 1 5 4
```

Vérification avec le checker fourni :
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

## Structure
- `srcs/` : code source
- `includes/` : en-têtes
