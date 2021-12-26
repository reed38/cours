#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<math.h>
#include "bitmap.h"
#include "fonctions.h"

//#define EXO1
//#define EXO2
#define MASQUAGE1



int main(void)
{
  #ifdef EXO1
  char *transporteur="transporteur.bmp";
  char *source="source.jpg";
  encrypte_image("source.png","originel_1.bmp","transporteur_2.bmp");
  #endif

  #ifdef EXO2
  FILE* fd_transporteur=open_file("transporteur.bmp","r");
  FILE* fd_source=open_file("source.bmp","w");

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
  FILE* fd_transporteur=open_file("transporteur.bmp","r");
  FILE* fd_source=open_file("source.bmp","w");
  fichierEntete *fichier=malloc(sizeof(fichierEntete));
  imageEntete *image=malloc(sizeof(imageEntete));
  couleurPallete *pallette=malloc(sizeof(couleurPallete));
  read_header(fichier,image,pallette,fd_transporteur);

  FILE* originel=open_file("transporteur.txt","r");
  FILE *transporteur=open_file("transporteur_1.txt","w");
  FILE* source=open_file("source.txt","r");
  masquage1(originel,source,transporteur,image->tailleImage);
  #endif






  return 0;


}
