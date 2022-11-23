#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#define TAILLE_MAX 1000

void initialiserCoordonnees(Coordonnees *point);

int main(int argc, char *argv[]) {

    Volume volume = FAIBLE;

    Coordonnees monPoint;
    Coordonnees *pointeur = &monPoint;

    monPoint.x = 10; // On travaille sur la variable, on utilise le point
    pointeur->x = 10; // On travaille sur un pointeur, on utilise la flèche

    initialiserCoordonnees(&monPoint);

    // GESTION DES FICHIERS :

    FILE *fichier = NULL;
    int age = 0;

    fichier = fopen('test.txt', 'w');

    if (fichier != NULL) {
        char chaine[TAILLE_MAX] = "";
        // On demande l'age
        printf("Quel age avez-vous ? ");
        scanf("%d", &age);

        // On l'ecrit dans le fichier
        fprintf(fichier, "La personne qui utilise le programme a %d ans.", age);

        // Lecture de tout le fichier :
        while(fgets(chaine, TAILLE_MAX, fichier) != NULL) {
            printf("%s", chaine);
        }


        // Recuperation de 3 nombres separes par des espaces :
        int score[3] = {0}; // Tableau des 3 meilleurs scores
        fscanf(fichier, "%d %d %d", &score[0], &score[1], &score[2]);
        printf("Les 3 meilleurs scores sont : %d, %d, %d", score[0], score[1], score[2]);


        // DEPLACEMENT DANS UN FICHIER :

        // ftell : indique à quelle position vous êtes actuellement dans le fichier.

        // fseek : positionne le curseur à un endroit précis.

        // rewind : remet le curseur au début du fichier (c'est équivalent à demander à la fonction fseek de positionner le curseur au début).


        // RENOMMER UN FICHIER :
        rename("test.txt", "test2.txt");

        // SUPPRIMER UN FICHIER :
        // remove("test2.txt");
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
