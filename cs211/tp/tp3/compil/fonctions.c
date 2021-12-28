#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fat.h"



void initialise_fat(){
  for (int i=0;i<BLOCNUM  ;i++)
  {
    FAT[i]=0xFFFF ;
  }
  for(int j=0; j<BLOCSIZE*BLOCNUM; j++)
  {
    volume[j]=0;
  }
  freeblocks=BLOCNUM;
  obj=NULL;
}

int search_freeblock(int taille)
{
  for (int i=0;i<BLOCNUM;i++)
  {
    if (FAT[i]==0xFFFF)
    {
      taille-=BLOCSIZE;
      return i;
    }

  }
}

struct objet *rechercher_objet(char *nom){

  struct objet *ptr=obj;
  while(ptr->next!=NULL && !(strcmp(nom,ptr->nom)))
  {
    ptr=ptr->next;
  }
  return ptr;
}






struct objet *creer_objet(char *nom, unsigned short auteur,unsigned int taille, char *data)
{

  if(rechercher_objet(nom)!=NULL)
  {
    fprintf(stderr,"error the name %s already exists\n",nom);
    return NULL;
  }
  if(taille/BLOCSIZE>freeblocks)
  {
    fprintf(stderr,"not enought space remaining\n");
    return NULL;
  }
  else{


    freeblocks-=taille/BLOCSIZE;
    unsigned int currentblock=search_freeblock(taille);

    struct objet *suivant=malloc(sizeof(struct objet));
    strcpy(suivant->nom,nom);
    suivant->taille=taille;
    suivant->auteur=auteur;
    suivant->index=currentblock;

    struct objet *ptr=obj->next;
    while(ptr->next!=NULL)
    {
      ptr=ptr->next;
    }
    //on assigne les valeurs de la nouvelle structure

    ptr->next=suivant;
    suivant->next=NULL;


//on rempli le tableau tant

    while(taille>=BLOCSIZE)
    {
      FAT[currentblock]=search_freeblock(taille);
      memcpy(&volume[BLOCSIZE*currentblock],&data[BLOCSIZE*currentblock],BLOCSIZE);


    }
    //on copie les données restantes taille<BLOCNUM
    if(taille>0)
    {
      FAT[currentblock]=search_freeblock(taille);
      memcpy(&volume[BLOCSIZE*currentblock],&data[BLOCSIZE*currentblock],taille);
    }
    //on affecte la valeur de la dernière case du tableau
    FAT[FAT[currentblock]]=0xFFFE;
    return (suivant);
}


}



int supprimer_objet(char *nom){

  struct objet *ptr=obj;
//on supprime la structure assosciée à l'objet
  while(!strcmp(nom,ptr->next->nom))
  {
    ptr=ptr->next;
  }
  struct objet *tmp=ptr->next;
  ptr->next=ptr->next->next;
  unsigned int currentblock=tmp->index;
  unsigned int nextblock;

  free(tmp);
  //on libère l'espace de fat
  while(FAT[currentblock]!= 0xFFFE )
  {
    nextblock=FAT[currentblock];
    FAT[currentblock]=0xFFFF;
    currentblock=nextblock;
    freeblocks++;
  }
  FAT[i]=0xFFFF;
  freeblocks++;

  return 1;


}

void supprimer_tout(){
  //on efface les données de la struct
  while(obj!=NULL)
  {
    struct objet *tmp=obj;
    obj->next=tmp->next;
    free(tmp);
  }
  //on effece les données de structure
  initialise_fat();


}
