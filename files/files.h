#include <stdlib.h>
#include <stdio.h>

typedef struct Element Element;
struct Element
{
    int nombre;
    Element *suivant;
};

typedef struct File File;
struct File
{
    Element *premier;
};

File *initialiser()
{
    File *file = malloc(sizeof(*file));
    file->premier = NULL;
    return 0;
}

void enfiler(File *file, int nvNombre)
{
    Element *nouveau = malloc(sizeof(*nouveau));
    if (file == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveau->nombre = nvNombre;
    nouveau->suivant = NULL;

    if(file->premier != NULL)
    {
        Element *elementActuel = file->premier;
        while(elementActuel->suivant != NULL)
        {
            elementActuel = elementActuel->suivant;
        }
        elementActuel->suivant = nouveau;
    }
    else
    {
        file->premier = nouveau;
    }
}

int defiler(File *file)
{
    if(file == NULL)
    {
        exit(EXIT_FAILURE);
    }

    int nombreDefile = 0;

    if (file->premier != NULL)
    {
        Element *elementDefile = file->premier;
        nombreDefile = elementDefile->nombre;
        file->premier = elementDefile->suivant;
        free(elementDefile);
    }
    return nombreDefile;
}

void afficherFile(File *file)
{
    if (file == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Element *actuel = file->premier;

    while (actuel != NULL)
    {
        printf("%d\n", actuel->nombre);
        actuel = actuel->suivant;
    }

    printf("\n");
}
