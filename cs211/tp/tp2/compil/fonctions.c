#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "bitmap.h"
#include "fonctions.h"




FILE* open_file(char *file, char *mode)
{
  FILE *flux=fopen(file,mode);
  if(flux==NULL)
  {
    fprintf(stderr,"error when oppening %s\n",file);
    perror("");
    return NULL;
  }
  else
    return(flux);

}

int close_file(FILE* flux)
{
  if (fclose(flux)==EOF)
  {
    //mfprintf(stderr,"error when closing file %s\n", flux);
    perror("");
    return EXIT_FAILURE;
  }
}

int exo1(char *input, char* output)
{
  FILE* fdin=open_file(input,"r");
  FILE* fdout=open_file(output,"w");
  char c;
  unsigned int indice_octet=0;
  char buffer;
  while((c=getc(fdin))!=EOF){
    if (indice_octet==8)
      {
        fputc(buffer,fdout);
        indice_octet=0;
        buffer=0;
      }
    if(isalpha(c))
    {
      buffer<<=1;
      indice_octet++;
      if(isupper(c))
      {
        buffer+=1;
      }
    }
  }
  close_file(fdin);
  close_file(fdout);

}
//transporteur "r", source "w", offset début des données de l'image dans le fichier parcouru par transporteur
int exo2(FILE* transporteur,FILE* source, int offset,size_t tailleimage)
{
  fseek(transporteur,offset,SEEK_SET);
  char c;
  unsigned char buffer=0;
  unsigned int indice_octet=0;

  for (int i=0;i<tailleimage;i++)
  {
    c=fgetc(transporteur);
    if(indice_octet==8)
    {
      putc(buffer,source);
      indice_octet=0;
      buffer=0;
    }


    buffer<<=1;
    buffer+=c &1;
    indice_octet+=1;


  }
}
//probleme boucle infinie EOF jamais atteint
void masquage1(char* originel, char* source, char* transporteur)
{
  FILE* fd_originel=open_file(originel,"r");
  FILE* fd_source=open_file(source,"r");
  FILE* fd_transporteur=open_file(transporteur,"w");
  unsigned char c_source;
  unsigned char c_originel;
  while((fread(&c_source,sizeof(unsigned char),1,fd_source))==1)
  {

    for(int indice_octet=0;indice_octet<8;indice_octet++)
    {

      c_originel=getc(fd_originel);

      unsigned char tmp=c_source;
      if((tmp &1 ) == 1)
      {
        c_originel=toupper(c_originel);
      }
      else
      {
        c_originel=tolower(c_originel);
      }
      c_source>>=1;
      putc(c_originel,fd_transporteur);

    }
  }
  close_file(fd_originel);
  close_file(fd_source);
  close_file(fd_transporteur);
}


int masquage2(FILE* fd_transporteur,FILE* fd_source,FILE* fd_originel,unsigned int offset)
{
  unsigned char octet_source=getc(fd_source);
  unsigned char octet_originel;
  fseek(fd_transporteur,offset,SEEK_SET);
  fseek(fd_originel,offset,SEEK_SET);

  //on code le contenu de surce dans transporteur
  while(fread(&octet_source,sizeof(unsigned char),1,fd_source))
  {
    fread(&octet_source,sizeof(unsigned char),1,fd_source);
    for (int i=0;i<8;i++)
    {
      fread(&octet_originel,sizeof(unsigned char),1,fd_originel);
      unsigned char tmp=octet_source;
      tmp&=1;
      octet_originel>>=1;
      octet_originel<<=1;
      octet_originel|=tmp;
      fwrite(&octet_originel,sizeof(unsigned char),1,fd_transporteur);
      octet_source>>=1;
    }

  }
}


void read_header(fichierEntete *fichier,imageEntete* image, couleurPallete* pallette,FILE* flux)
{
  fseek(flux,0,SEEK_SET);
  fread(fichier,sizeof(fichierEntete),1,flux);
  fread(image,sizeof(imageEntete),1,flux);
  fread(pallette,sizeof(pallette),1,flux);

}

void afficher_header(fichierEntete struct_fichier_en_tete, imageEntete struct_image_en_tete)
{
  //affichage données fichier en tête
  printf("\n donnée du fichier d'en tête:");
  printf("\n signature: %u",struct_fichier_en_tete.signature);
  printf("\n taille fchier: %u",struct_fichier_en_tete.tailleFichier);
  printf("\n reserve: %u",struct_fichier_en_tete.reserve);
  printf("\n offset: %u",struct_fichier_en_tete.offset);
  //affichage des données de l'entête de l'imageEntete
  printf("\n donnée de l'image:");
  printf("\n taille en tête: %u",struct_image_en_tete.tailleEntete);
  printf("\n largeur: %u",struct_image_en_tete.largeur);
  printf("\n hauteur: %u",struct_image_en_tete.hauteur);
  printf("\n plan: %u",struct_image_en_tete.plan);
  printf("\n profondeur: %u",struct_image_en_tete.profondeur);
  printf("\n compression : %u",struct_image_en_tete.compression);
  printf("\n taille image : %u",struct_image_en_tete.tailleImage);
  printf("\n resolution horizontale: %u",struct_image_en_tete.resolutionHorizontale);
  printf("\n resolution verticale: %u",struct_image_en_tete.resolutionVerticale);
  printf("\n nombre de couleurs: %u",struct_image_en_tete.nombreCouleurs);
  printf("\n nombre de coulaurs importantes: %u",struct_image_en_tete.nombreCouleursImportantes);


}
