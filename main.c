#include <stdio.h>
#include <stdlib.h>

int taille_tab(int nombre){ //avoir la longueur du nombre
    int temp = nombre;
    int taille = 0;
    while (temp > 0) {
        taille++;
        temp /= 10;
    }
    return taille;
}

int retourner_tableau(int *tab, int taille){ //retourne le tableau
    int a;
    for (int i = 0; i < taille/2; ++i) {
        a = tab[i];
        tab[i] = tab[taille-1-i];
        tab[taille-1-i] = a;
    }
}

int main() {
    int nombre;
    printf("Entrez un nombre : \n");
    scanf("%d", &nombre);

    int nbtemp = nombre;
    int taille = taille_tab(nombre);

    if (taille == 1) { // Aucun arrangement possible
        printf("Aucun changement possible\n");
        return 0;
    }

    int *tab = (int *)malloc(taille * sizeof(int));
    for (int i = taille - 1; i >= 0; i--) {
        tab[i] = nbtemp % 10;
        nbtemp /= 10;
    }

    if (taille == 2){ //si la taille est de deux simplement retourner le tableau une fois
        printf("%d%d\nEst le resultat", tab[1], tab[0]);
        free(tab);
        return 0;
    }

    int j=0; // compteur
    do {
        retourner_tableau(tab, taille-j-1);
        // inverse le debut du tableau. Les cases traitées sont les 1234 puis 123 puis 12
        j++; // augmente le compteur pour diminuer le nombre de case traité
    } while (j < taille - 1); // jusqu'à ce qu'on fasse la moitie du nombre de case

    retourner_tableau(tab, taille); //retourne le tabeau à la fin pour le resultat final
    printf("la solution est :\n");

    for (int i = 0; i < taille; ++i) {
        printf("%d", tab[i]);
    }
    free(tab);
    return 0;

}
