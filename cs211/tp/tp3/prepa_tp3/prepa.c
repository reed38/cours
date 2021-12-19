#include <stdio.h>
#include <stdlib.h>

typedef struct node Lnode;
 struct node {
		char data ;
		struct node *link ;
		} ;

void insertionTete(Lnode **ph,char item){


	Lnode *nouveau=malloc(sizeof(Lnode));
	nouveau->data=item;
	nouveau->link= *ph;
	*ph=nouveau;
}




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


void suppressionTete(Lnode **ph)
{
	Lnode *ptr=*ph;
	*ph=ptr->link;
	free(ptr);


	}


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
