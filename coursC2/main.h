typedef struct Coordonnees Coordonnees;
// Cree un alias pour la structure Coordonnees


struct Coordonnees {
    int x;
    int y;
};


typedef struct Personne Personne;
struct Personne{
    char nom[100];
    char prenom[100];
    char adresse[1000];

    int age;
    int etudiant;
};

typedef enum Volume Volume;
enum Volume
{
    FAIBL = 10, MOYEN = 50, FORT = 100
};

// Prototype de fonction fOpen
FILE *fOpen(const char* nomDuFichier, const char* modeOuverture);

// "r"  : lecture seule.
// "w"  : écriture seule.
// "a"  : Ajout / ecriture a la fin du fichier.
// "a+"  : ajout en lecture / écriture à la fin. Vous écrivez et lisez du texte à partir de la fin du fichier. Si le fichier n'existe pas, il sera créé.
// "r+"  : lecture et écriture. Vous pourrez lire et écrire dans le fichier. Le fichier doit avoir été créé au préalable.
// "w+"  : lecture et écriture, avec suppression du contenu au préalable. Le fichier est donc d'abord vidé de son contenu, vous pouvez y écrire, et le lire ensuite. Si le fichier n'existe pas, il sera créé.