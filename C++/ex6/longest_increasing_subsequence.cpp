// Exercice 6 — Longest Increasing Subsequence (LIS)
// Niveau: Moyennement difficile
//
// Énoncé :
// Écrire un programme qui lit un entier n (1 ≤ n ≤ 100000) suivi de n
// entiers, et affiche la longueur de la plus longue sous-suite strictement
// croissante (LIS).
//
// Format d'entrée :
// n
// a1 a2 a3 ... an
//
// Format de sortie :
// longueur_de_la_LIS
//
// Exemple :
// Entrée :
// 8
// 10 9 2 5 3 7 101 18
// Sortie :
// 4
//
// Consignes :
// - Implémentez la fonction `int lis_length(const vector<int>& a)`.
// - Vous pouvez utiliser un algorithme O(n log n) ou O(n^2) selon votre goût.
// - Ne pas modifier la façon dont l'entrée/sortie est lue dans `main`.

#include <bits/stdc++.h>
using namespace std;

int lis_length(const vector<int>& a) {
    // TODO: implémenter la logique ici
    // Retourner la longueur de la plus longue sous-suite strictement croissante
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << lis_length(a) << '\n';
    return 0;
}
