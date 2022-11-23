#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void initialiserCoordonnees(Coordonnees *point);

int main(int argc, char *argv[]) {

    Volume volume = FAIBLE;

    Coordonnees monPoint;
    Coordonnees *pointeur = &monPoint;

    monPoint.x = 10; // On travaille sur la variable, on utilise le point
    pointeur->x = 10; // On travaille sur un pointeur, on utilise la flèche

    initialiserCoordonnees(&monPoint);

    // GESTION DES FICHIER :

    FILE *fichier = NULL;
    fichier = fopen('test.txt', 'r+');

    if (fichier != NULL) {
        // On peut lire et écrire dans le fichier
        fclose(fichier);
    } else {
        printf("Impossible d'ouvrir le fichier test.txt");
    }

    return 0;
}

void initialiserCoordonnees(Coordonnees *point) {
    (*point).x = 0; // Pointeur sur point.x
    point->y = 0; // Version raccourcie
}
