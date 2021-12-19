#define BLOCSIZE 512
#define BLOCNUM 1024
#define NAMELEN 256

extern struct objet *obj ;
extern char volume[BLOCSIZE * BLOCNUM ];
extern unsigned short FAT[BLOCNUM];
extern unsigned short freeblocks;

/**
\brief Cette fonction permet :
D'initialiser le tableau FAT en déclarant tous les blocs libres.
D'initialiser la variable freeblocks à BLOCNUM.
D'initialiser la variable obj
*/
/*description en français fonctionnement de initialise_fat:
on saisie les valeurs des variables freeblocks, BLOCNUM*/
void initialise_fat();


/**
\brief Cette fonction permet de rechercher un objet par son nom dans la liste chaînée décrivant les objets
\param nom nom de l'objet à rechercher
\return pointeur vers l'objet trouvé ou NULL sinon.
description en français:
tete: de type pointeur vers pointeur d'objet
pointeur_obj: pointe vers l'adresse pointée par tete
tant que le nom dans objet ne correspond pas on fait pointer pointeur obj vers la structure suivante donnée par next.
Si on arrive à la fin de la chaine sans avoir trouvé, on retourne NULL, sinon on retourne l'adresse de la structure
contenant le bon nom.
*/
struct objet *rechercher_objet(char *nom);
//

/**
\brief Cette fonction permet de créer un objet en vérifiant qu'aucun objet n'a le même nom dans la liste (pas triée par nom)
si possible, de réserver des blocs dans le tableau FAT et de copier les données (data) dans ces blocs.
mettre à jour la variable freeblocks
\param nom nom de l'objet
\param auteur proprietaire de l'objet
\param taille la taille de l'objet
\param data les données à copier

description en français:
on réutilise la fonction rechercher_objet pour savoir si le nom est déja utilisé.
Si le nom n'est pas utillisé, on crée une struct objet pour stocker taille-auteur-nom, que l'on rajoute à la fin
de la chaine obj avec la fonction Insertion queue.
On réserve ensuite de la place en soustrayant à freeblocks le nombre de blocs nécessaires pour stocker char* nom.

*/
struct objet *creer_objet(char *nom, unsigned short auteur,unsigned int taille, char *data);

/**
\brief  Cette fonction permet de supprimer un objet trouvé par son nom, de libérer les blocs dans le tableau FAT, et de mettre à jour la variable freeblocks
\param nom
\return -1 si erreur, 0 sinon.


*/
int supprimer_objet(char *nom);


/**
\brief Cette fonction permet :
De supprimer l'ensemble des objets
De liberer l'ensemble des blocs dans le tableau FAT
De modifier la variable freeblocks
*/
void supprimer_tout();

/** POUR LES PLUS RAPIDES ..................** BONUS ** BONUS ** BONUS **
\brief Cette fonction permet :
De lire le contenu d'un objet et de le copier dans une structure de données allouée dynamiquement
Attention à la taille !!!!!!!!!!!!!!
\param nom nom de l'objet
\return -1 si erreur, 0 sinon.
*/

int lire_objet(struct objet *o,char **data);
