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

    // TODO :  MEMOIRE (Super important en C):

    // Connaitre la taille allouee selon un type :
    sizeof (int);

    printf("char : %d octets\n", sizeof(char));
    printf("int : %d octets\n", sizeof(int));
    printf("long : %d octets\n", sizeof(long));
    printf("double : %d octets\n", sizeof(double));

    // Afficher taille d'un type custom marche aussi
    sizeof(Coordonnees);

    // malloc : demander la permission au systeme d'allouer de la memoire
    // free : liberer la memoire

    // 1 Appeler malloc
    // 2 Verifier la valeur retournee
    // 3 Liberer la memoire avec free


    // ALLOCATION MANUELLE DE MEMOIRE :
    //Prototype de malloc :
    void* malloc(size_t nombreOctetsNecessaires);

    int* memoireAllouee = NULL; //Creation pointeur sur int
    memoireAllouee = malloc(sizeof(int)); // On demande au systeme d'allouer de la memoire pour un int

    if(memoireAllouee == NULL)
    {
        exit(0); // On arrete le programme
    }
    // Sinon on peut continuer le programme

    printf("Quel age avez vous? ");
    scanf("Vous avez %d ans", *memoireAllouee);
    // Liberer la memoire
    //void free(void* pointeur);
    free(memoireAllouee);


    // Tableau dynamique :
    int nombreDAmis = 0, i = 0;
    int* ageAmis = NULL;

    printf("Combien avez-vous d'amis ? ");
    scanf("%d", &nombreDAmis);

    if(nombreDAmis > 0)
    {
        ageAmis = malloc(nombreDAmis * sizeof(int));

        if (ageAmis == NULL)
        {
            exit(0);
        }

        for (i = 0; i < nombreDAmis; i++)
        {
            printf("Quel age a votre ami numero %d ? ", i + 1);
            scanf("%d", &ageAmis[i]);
        }

        printf("\n\nVos amis ont les ages suivants :\n");
        for (i = 0 ; i < nombreDAmis ; i++)
        {
            printf("%d ans\n", ageAmis[i]);
        }

        free(ageAmis);
    }

    // TODO : Recuperation securisee d'une chaine de caracteres
    // gets : lit toute une chaine de caracteres
    // fgets : lit une chaine de caracteres jusqu'a un caractere donne

    // Prototype de fgets : char *fgets(char *str, int num, FILE *stream);

    return 0;
}

void initialiserCoordonnees(Coordonnees *point) {
    (*point).x = 0; // Pointeur sur point.x
    point->y = 0; // Version raccourcie
}
