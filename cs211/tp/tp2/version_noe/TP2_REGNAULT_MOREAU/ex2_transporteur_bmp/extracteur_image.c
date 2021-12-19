#include "bitmap.h"
#include <stdio.h>
#include <math.h>

int main()
{
  FILE *transporteur, *source;
  transporteur = fopen("transporteur2.bmp","r");
  source = fopen("source.bmp","w");

  if(transporteur==NULL)
  {
    printf("Erreur d'ouverture du transporteur.");
    return 1;
  }

  if(source==NULL)
  {
    printf("Erreur de création de la source.");
    return 1;
  }

  fichierEntete BMP_header;
  imageEntete DIB_header;
  couleurPallete palette_header;

  fread(&BMP_header, sizeof(fichierEntete), 1, transporteur);
  fread(&DIB_header, sizeof(imageEntete), 1, transporteur);
  //fread(&palette_header, sizeof(couleurPallete), 1, transporteur); //inutilisé, cf wikipedia

  print_BMP_header(&BMP_header, &DIB_header, &palette_header);



  unsigned char pixel_value, octet=0;
  int indice_octet=0;

  while(fread(&pixel_value, sizeof(char), 1, transporteur) == 1) //on n'est pas au bout de la matrice
  {
    pixel_value &= 1; //masque les 7 premiers bits de l'octet du pixel pour récupérer le bit de poids faible du pixel

    if(indice_octet==8) //on a collecté 1 octet, on l'écrit
    {
      fwrite(&octet, sizeof(char), 1, source);
      indice_octet=0;
      octet=0;
    }

    if(pixel_value == 1)
    {
      octet+=pow(2,7-indice_octet);
    }

    indice_octet++;
  }

  fclose(transporteur);
  fclose(source);

  return 0;
}



void print_BMP_header(fichierEntete *BMP_header, imageEntete *DIB_header, couleurPallete *palette_header)
{
  printf("\n1ère partie : en-tête BMP : \n");
  printf("Signature : %d\n", BMP_header->signature);
  printf("Taille du fichier : %d octets\n", BMP_header->tailleFichier);
  printf("Données application : %d\n", BMP_header->reserve);
  printf("Début de la matrice de pixels (offset) : %d\n\n", BMP_header->offset);

  printf("2ème partie : en-tête DIB : \n");
  printf("Taille en-tête : %d octets\n", DIB_header->tailleEntete);
  printf("Largeur : %d pixels\n", DIB_header->largeur);
  printf("Hauteur : %d pixels\n", DIB_header->hauteur);
  printf("Nombre de plans de couleur : %d\n", DIB_header->plan);
  printf("Bits par pixel : %d\n", DIB_header->profondeur);
  printf("Compression utilisée : %d\n", DIB_header->compression);
  printf("Taille de l'image : %d octets\n", DIB_header->tailleImage);
  printf("Résoltution horizontale : %d pmh\n", DIB_header->resolutionHorizontale);
  printf("Résolution verticale : %d pmv\n", DIB_header->resolutionVerticale);
  printf("Nombre de couleurs : %d\n", DIB_header->nombreCouleursImportantes);
  printf("Nombre de couleurs importantes : %d\n\n", DIB_header->nombreCouleursImportantes);

  printf("3ème partie : en-tête palette de couleurs\n");
  printf("Bleu : %d\n", palette_header->B);
  printf("Vert : %d\n", palette_header->V);
  printf("Rouge : %d\n", palette_header->R);
  printf("Données application : %d\n\n", palette_header->reserve);

}
