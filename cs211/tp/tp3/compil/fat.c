#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "fat.h"

struct objet
{
char nom[NAMELEN];
unsigned int taille;
unsigned short auteur;
unsigned short index;
struct objet *next;
};

struct objet *obj  ;
char volume[BLOCSIZE * BLOCNUM ];
unsigned short FAT[BLOCNUM];
unsigned short freeblocks;








int find_free_block(short unsigned int *tab, int length)
{
  for (int i=0;i<length;i++)
  {
    if (tab[i]==0xffff)
    {
      return i;
    }
  }
  return EXIT_FAILURE;
}

void initialise_fat()
{

  freeblocks=BLOCNUM;
  for (int i=0;i<BLOCNUM;i++)
  {
    FAT[i]=0xFFFF;
  }
  obj=NULL;


}


struct objet *rechercher_objet(char *nom)
{
  struct objet *ptr_suivant=obj->next;
  while(ptr_suivant!=NULL && !(strcmp(ptr_suivant->nom,nom)))
  {
    ptr_suivant=ptr_suivant->next;
  }
  return ptr_suivant;
}



struct objet *creer_objet(char *nom, unsigned short auteur,unsigned int taille, char *data)
{

  if(freeblocks> taille/BLOCSIZE)
  {
    if (rechercher_objet(nom)!=NULL  )
    {
      int first_block=find_free_block(FAT,BLOCNUM);

      struct objet *new=malloc(sizeof(struct objet));
      strcpy(new->nom,nom);
      new->taille=taille;
      new->auteur=auteur;
      new->next=NULL;
      new->index=first_block;

      unsigned int blocs_number=taille/BLOCSIZE-1;


      struct objet *ptr_suivant=obj->next;

      while(ptr_suivant!=NULL)
      {
        ptr_suivant=ptr_suivant->next;
      }
      ptr_suivant->next=new;

      int identifiant=first_block;
      for (int i=1;i<blocs_number-1;i++)
      {

        //on différencie le cas ou on utilise un bloc complet et le cas ou on utilise un bloc incomplet
        if (BLOCSIZE<(taille-identifiant*BLOCSIZE))
        {
          memcpy(&volume[BLOCSIZE*identifiant],&data[BLOCSIZE*identifiant],BLOCSIZE);
        }
        else
        {
          memcpy(&volume[BLOCSIZE*identifiant],&data[BLOCSIZE*identifiant],(taille-identifiant*BLOCSIZE));

        }
        int next_block=find_free_block(FAT,BLOCNUM);
        FAT[identifiant]=next_block;
        identifiant=next_block;
        freeblocks--;

      }
        return new;


    }
    else
    {
      fprintf(stderr,"\n l'espace mémoire est déja utilisé");
      return NULL;
    }
  }
  else
  {
    fprintf(stderr, "\nespace disponible insufffisant ");
    return NULL;
  }




}



int supprimer_objet(char *nom)
{
  assert(rechercher_objet(nom)!=NULL);
  struct objet *suivant=malloc(sizeof(struct objet));
  suivant=obj->next;
  while(suivant!=NULL && !strcmp((suivant->next)->nom,nom))
  {
    suivant=suivant->next;
  }
  struct objet  *tmp=suivant->next;
  suivant->next=(suivant->next)->next;
  free(tmp);
  return EXIT_SUCCESS;

}


void supprimer_tout();
