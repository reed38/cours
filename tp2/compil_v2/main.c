#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<math.h>
#include "bitmap.h"
#include "fonctions.h"




int main(void)
{
  char *transporteur="transporteur.bmp";
  char *source="source.jpg";
  fichierEntete struct_fichier_en_tete;
  imageEntete struct_image_en_tete;
  couleurPallete struct_couleur_palette;
  //convertit_minuscule("transporteur.txt","original.txt");
  int convertit_minuscule(char *file_in, char *file_out);

lire_header(&struct_fichier_en_tete, &struct_image_en_tete, transporteur);


//afficher_header(struct_fichier_en_tete, struct_image_en_tete);

decrypte_ex2(transporteur, source,struct_fichier_en_tete.offset,struct_image_en_tete.tailleImage);


  return 0;


}
