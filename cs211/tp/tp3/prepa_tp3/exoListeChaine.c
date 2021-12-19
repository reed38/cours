#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/* Ici, on est oblig� d'utiliser la notation struct xxx,
car la structure s'auto-r�f�rence!*/
typedef struct node Lnode;
 struct node {
		char data ;
		struct node *link ;
		} ;

/* Insertion en "t�te de liste" */
void insertionTete(Lnode **ph,char item){


	Lnode *nouveau=malloc(sizeof(Lnode));
	nouveau->data=item;
	nouveau->link= *ph;
	*ph=nouveau;
}



/* Insertion en "queue de liste" */
void insertionQueue(Lnode **ph,char item)	{
	Lnode *ptr=*ph;
	while(ptr->link!=NULL)
	{
		ptr=ptr->link;
	}
	Lnode *nouveau=malloc(sizeof(Lnode));
	nouveau->data=item;
	ptr->link=nouveau;
	nouveau->link=NULL;


	}

/* Suppression en "t�te de liste" */
void suppressionTete(Lnode **ph)
{
	Lnode *ptr=*ph;
	*ph=ptr->link;
	free(ptr);


	}

/* Suppression en "Queue" de liste" */
void suppressionQueue(Lnode **ph)
{
	Lnode* ptr=*ph;
	while((ptr->link)->link!=NULL)
	{
		ptr=ptr->link;
	}

	Lnode *tmp=ptr->link;
	ptr->link=NULL;
	free(tmp);

	}

/* Proc�dure d'affichage de la liste. Ne doit pas �tre modifi�e!!! */
void listeAffiche(Lnode  *ptr){
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

//	listeAffiche(tete) ;
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
