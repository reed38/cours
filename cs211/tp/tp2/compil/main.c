#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<math.h>
#include "bitmap.h"
#include "fonctions.h"

//#define EXO1
//#define EXO2
//#define MASQUAGE1
#define MASQUAGE2



int main(void)
{
  #ifdef EXO1
  char *transporteur="transporteur.txt";
  char *source="source.txt";

  exo1(transporteur,source);
  #endif

  #ifdef EXO2
  FILE* fd_transporteur=open_file("transporteur_1.bmp","r");
  FILE* fd_source=open_file("source_1.bmp","w");

  fichierEntete *fichier=malloc(sizeof(fichierEntete));
  imageEntete *image=malloc(sizeof(imageEntete));
  couleurPallete *pallette=malloc(sizeof(couleurPallete));
  read_header(fichier,image,pallette,fd_transporteur);
  afficher_header(*fichier,*image);
  exo2(fd_transporteur,fd_source,fichier->offset,image->tailleImage);

  close_file(fd_source);
  close_file(fd_transporteur);
  #endif

  #ifdef MASQUAGE1

  char *transporteur="transporteur_1.txt";
  char *originel="transporteur.txt";
  char *source="source.txt";
  masquage1(originel,source,transporteur);

  #endif


  #ifdef MASQUAGE2
  FILE* fd_transporteur=open_file("transporteur_1.bmp","w");
  FILE* fd_source=open_file("source.bmp","r");
  FILE* fd_originel=open_file("originel.bmp","r");
  fichierEntete *fichier=malloc(sizeof(fichierEntete));
  imageEntete *image=malloc(sizeof(imageEntete));
  couleurPallete *pallette=malloc(sizeof(couleurPallete));
  read_header(fichier,image,pallette,fd_originel);
  fwrite(fichier,sizeof(fichierEntete),1,fd_transporteur);
  fwrite(image,sizeof(imageEntete),1,fd_transporteur);
  fwrite(pallette,sizeof(couleurPallete),1,fd_transporteur);
  masquage2(fd_transporteur,fd_source,fd_originel,fichier->offset);

  close_file(fd_transporteur);
  close_file(fd_source);
  close_file(fd_originel);

#endif





  return 0;


}
