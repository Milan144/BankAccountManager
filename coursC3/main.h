#include <stdio.h>
#include <stdlib.h>

typedef struct Element Element;
struct Element
{
    int nombre;
    Element *suivant;
};

typedef struct Liste Liste;
struct Liste
{
    Element *premier;
    int nbElements;
};

Liste *initialisation()
{
    Liste *liste = malloc(sizeof(*liste));
    Element *element = malloc(sizeof(*element));

    if (liste == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    element->nombre = 0;
    element->suivant = NULL;
    liste->premier = element;

    return liste;
}

void insertion(Liste *liste, int nvNombre)
{
    // Creation nv element
    Element *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->nombre = nvNombre;

    // Insertion nv element
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}

// Supprime le premier element de la liste
void suppression(Liste *liste)
{
    // Verification que la liste n est pas nulle
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    // Verification qu'il a au moins un element
    if (liste->premier != NULL)
    {
        Element *aSupprimer = liste->premier;
        liste->premier = liste->premier->suivant;
        free(aSupprimer);
    }
}

void afficherListe(Liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *actuel = liste->premier;

    while (actuel != NULL)
    {
        printf("%d -> ", actuel->nombre);
        actuel = actuel->suivant;
    }
    printf("NULL\n");
}

// Insertion d'un element apres l'element indique en parametre
void insertionApres(Liste *liste, int nvNombre, int apres)
{
    // Creation nv element
    Element *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->nombre = nvNombre;

    // Insertion nv element
    Element *actuel = liste->premier;
    while (actuel->nombre != apres)
    {
        actuel = actuel->suivant;
    }
    nouveau->suivant = actuel->suivant;
    actuel->suivant = nouveau;
}

// Supprime un element de la liste donne en parametre
void suppressionElement(Liste *liste, int aSupprimer)
{
    // Verification que la liste n est pas nulle
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    // Verification qu'il a au moins un element
    if (liste->premier != NULL)
    {
        Element *actuel = liste->premier;
        Element *precedent = NULL;
        while (actuel->nombre != aSupprimer)
        {
            precedent = actuel;
            actuel = actuel->suivant;
        }
        precedent->suivant = actuel->suivant;
        free(actuel);
    }
}

// Suppression de tout les elements de la liste
void suppressionTout(Liste *liste)
{
    // Verification que la liste n est pas nulle
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    // Verification qu'il a au moins un element
    if (liste->premier != NULL)
    {
        Element *actuel = liste->premier;
        Element *precedent = NULL;
        while (actuel != NULL)
        {
            precedent = actuel;
            actuel = actuel->suivant;
            free(precedent);
        }
    }
}

// Retourne le nombre d'elements de la liste et le sauvegarde dans Liste nbElements
void nbElements(Liste *liste)
{
    // Verification que la liste n est pas nulle
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }
    // Verification qu'il a au moins un element
    if (liste->premier != NULL)
    {
        Element *actuel = liste->premier;
        int nb = 0;
        while (actuel != NULL)
        {
            nb++;
            actuel = actuel->suivant;
        }
        liste->nbElements = nb;
    }
}