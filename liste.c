#include <stdio.h>

void afficherSousEnsembles(int ensemble[], int n, int index, int sousEnsemble[], int tailleSousEnsemble) {
    // Si nous avons parcouru tous les éléments de l'ensemble
    if (index == n) {
        // Affiche le sous-ensemble courant
        printf("{ ");
        for (int i = 0; i < tailleSousEnsemble; i++) {
            printf("%d ", sousEnsemble[i]);
        }
        printf("}\n");
        return;
    }

    // Inclut l'élément actuel dans le sous-ensemble
    sousEnsemble[tailleSousEnsemble] = ensemble[index];
    afficherSousEnsembles(ensemble, n, index + 1, sousEnsemble, tailleSousEnsemble + 1);

    // Exclut l'élément actuel du sous-ensemble
    afficherSousEnsembles(ensemble, n, index + 1, sousEnsemble, tailleSousEnsemble);
}

int main() {
    int ensemble[] = {1, 2, 3, 4};
    int n = sizeof(ensemble) / sizeof(ensemble[0]);
    int sousEnsemble[4]; // Un tableau pour stocker le sous-ensemble actuel

    printf("Sous-ensembles de l'ensemble : \n");
    afficherSousEnsembles(ensemble, n, 0, sousEnsemble, 0);

    return 0;
}

