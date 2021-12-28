#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/* Ici, on est oblig� d'utiliser la notation struct xxx,
car la structure s'auto-r�f�rence!*/
typedef struct node {
		char data ;
		struct node *link ;
		} Lnode ;

/* Insertion en "t�te de liste" */
void insertionTete(Lnode **ph,char item){
	Lnode *suivant=malloc(sizeof(Lnode));
	suivant->data=item;
	suivant->link=*ph;
	*ph=suivant;
	/* A compl�ter */
	}

/* Insertion en "queue de liste" */
void insertionQueue(Lnode **ph,char item)	{
	Lnode *suivant=*Lnode;

	While(suivant->link!=NULL)
	{
		suivant=suivant->link;
	}
	Lnode *new=malloc(sizeof(Lnode));
	new->data=item;
	new->link=NULL;
	suivant->link=new;
	/* A compl�ter */
	}

/* Suppression en "t�te de liste" */
void suppressionTete(Lnode **ph){
	Lnode *tmp=*ph;
	*ph=tmp->link;
	free(tmp);


	}

/* Suppression en "Queue" de liste" */
void suppressionQueue(Lnode **ph){
	Lnode* suivant=*Lnode;
	while(suivant->link->link!=NULL)
	{
		suivant=suivant->link;
	}
	Lnode *tmp=suivant->link;
	suivant->link=NULL;
	free(tmp);
	/* A compl�ter */
	}

/* Proc�dure d'affichage de la liste. Ne doit pas �tre modifi�e!!! */
void listeAffiche(Lnode * ptr){
	if ( NULL == ptr )
		printf("Liste vide!") ;
	else
		printf("Contenu de la liste : ") ;
	while ( NULL != ptr ) 	{
		printf("%c ",ptr->data);
		ptr = ptr->link ;
		}
	printf("\n") ;
	}

/* Programme principal. Ne doit pas �tre modifi�!!! */
int main(void) {
	Lnode *tete = NULL ;

	listeAffiche(tete) ;
	insertionTete(&tete,'a') ;
	listeAffiche(tete) ;
	insertionTete(&tete,'c') ;
	listeAffiche(tete) ;
	insertionQueue(&tete,'t') ;
	listeAffiche(tete) ;
	insertionQueue(&tete,'s') ;
	listeAffiche(tete) ;
	suppressionTete(&tete) ;
	listeAffiche(tete) ;
	suppressionTete(&tete) ;
	listeAffiche(tete) ;
	suppressionQueue(&tete) ;
	listeAffiche(tete) ;
	suppressionTete(&tete) ;
	listeAffiche(tete) ;

   return EXIT_SUCCESS;
   }
