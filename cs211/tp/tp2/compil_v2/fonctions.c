#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<math.h>
#include "bitmap.h"


//azert
//ex1
int ex1(char *fichier_transporteur,char* fichier_source)

{
  char c;
  FILE* fd_transporteur=fopen(fichier_transporteur,"r");
  FILE* fd_source=fopen(fichier_source,"w");
  unsigned char octet_value;
  unsigned char indice_bit=0;
  if (NULL==fd_transporteur)
  {
    fprintf(stderr, "\nerreur d'ouverture du fichier: %s\n",fichier_transporteur);
    perror("");
    return EXIT_FAILURE;

  }
  if (NULL==fd_source)
  {
    fprintf(stderr, "\nerreur d'ouverture du fichier: %s\n",fichier_source);
    perror("");
    return EXIT_FAILURE;

  }

  while( EOF != (c = getc(fd_transporteur)) )
  {

    if(indice_bit%8==0)
    {
      indice_bit=0;
      if(isalpha((octet_value)))
      {
      fwrite(&octet_value,1,1,fd_source);
      printf("\n%d",octet_value);
    }
      octet_value=0;

    }
    if (isalpha(c))
    {
      if(isupper(c))
        octet_value+=pow(2,7-indice_bit);

      indice_bit++;
    }
  }
  if(fclose(fd_source)==EOF)
  {
    fprintf(stderr,"erreur lors de la fermeture du fichier %s",fichier_source);
    return(EXIT_FAILURE);
  }

  if(fclose(fd_transporteur)==EOF)
  {
    fprintf(stderr,"erreur lors de la fermeture du fichier %s",fichier_transporteur);
    return(EXIT_FAILURE);

  }

  return(0);



}




int lire_header(fichierEntete *file_header, imageEntete *picture_header, char* fichier)
{
  FILE* flux=fopen(fichier,"r");
  if (flux==NULL)
  {
    printf("\nerreur lors de l'ouverture de %s ",fichier);
    return EXIT_FAILURE;

  }

  fread(file_header,sizeof(fichierEntete),1,flux);
  fseek(flux, sizeof(fichierEntete), SEEK_SET);
  fread(picture_header,sizeof(imageEntete),1,flux);
  fseek(flux, sizeof(imageEntete), SEEK_CUR);


  if(fclose(flux)==EOF)
  {
    fprintf(stderr,"erreur lors de la fermeture du fichier %s",fichier);
    return EXIT_FAILURE;
  }


return 0;
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

int decrypte_ex2(char *transporteur, char *source,unsigned int offset,unsigned int taille_image)
{
  printf("1\n");

  FILE* fdin=fopen(transporteur,"r");
  FILE* fdout=fopen(source,"w");

  unsigned char tmp_pixel;
  unsigned short buffer_size=0;
  unsigned char current_buffer = 0;

  if(fdin==NULL)
  {
    printf("erreur lors de l'ouverture de %s",transporteur);
    perror("");
  return EXIT_FAILURE;
  }

  if(fdout==NULL)
  {
    printf("erreur lors de l'ouverture de %s",source);
    perror("");
  return EXIT_FAILURE;
  }


  //on se positionne au début des données après le header
  fseek(fdin,offset,SEEK_SET);


  for(int i = offset; i <taille_image; i++)
  {
            if(buffer_size==8)
            {
                fputc(current_buffer, fdout);
                buffer_size = 0;
                current_buffer=0;
            }
            tmp_pixel=fgetc(fdin);
            current_buffer = current_buffer << 1;
            current_buffer += tmp_pixel & 1;
            buffer_size++;
  }





    if(fclose(fdin)==EOF)
    {
      printf("erreur lors de la fermeture de %s",transporteur);
      perror("");
      return EXIT_FAILURE;
    }
    if(fclose(fdout)==EOF)
    {
      printf("erreur lors de la fermeture de %s",source);
      perror("");
      return EXIT_FAILURE;
    }


    return 0;

}


int encrypte_image(char *source, char *original,char *transporteur)
{
  FILE* fd_transporteur=fopen(transporteur,"w");
  FILE* fd_original=fopen(original,"r");
  FILE* fd_source=fopen(source,"r");
  unsigned char buffer;
  fichierEntete f_entete;
  imageEntete i_entete;
  lire_header(&f_entete, &i_entete, original);
  size_t taille_image=i_entete.tailleImage;
  char octet_source;
  char octet_original;




  if(fd_transporteur==NULL)
  {
    printf("erreur lors de l'ouverture du fichier %s",transporteur);
    perror("");
    return EXIT_FAILURE;
  }
  if(fd_source==NULL)
  {
    printf("erreur lors de l'ouverture du fichier %s",source);
    perror("");
    return EXIT_FAILURE;
  }
  if(fd_original==NULL)
  {
    printf("erreur lors de l'ouverture du fichier %s",original);
    perror("");
    return EXIT_FAILURE;
  }
  //on commence par recopier le contenu du file_header
  fread(&f_entete,sizeof(fichierEntete),1,fd_original);
  fwrite(&f_entete,sizeof(fichierEntete),1,fd_transporteur);
  fread(&i_entete,sizeof(imageEntete),1,fd_original);
  fwrite(&i_entete,sizeof(imageEntete),1,fd_transporteur);

  //on se place ensuite au début de la matrice de pixels

  fseek(fd_transporteur, f_entete.offset,SEEK_SET);

  fseek(fd_original, f_entete.offset,SEEK_SET);

size_t pixel=0;
while(pixel<taille_image)
  {

      octet_source=fgetc(fd_source);
      for(int i=0;i<8;i++)
      {
        octet_original=fgetc(fd_original);
        octet_original>>1;
        octet_original<<1;
        if((octet_source & 1) ==1)
          octet_original+=1;

        octet_source>>1;
        pixel++;
        fputc(octet_original,fd_transporteur);



      }
  }
  if (fclose(fd_original)==EOF)
  {
    fprintf(stderr,"erreur lors de la fermeture du ficher %s" ,original);
    perror("");
    return EXIT_FAILURE;
  }

  if (fclose(fd_source)==EOF)
  {
    fprintf(stderr,"erreur lors de la fermeture du ficher %s" ,source);
    perror("");
    return EXIT_FAILURE;
  }

  if (fclose(fd_transporteur)==EOF)
  {
    fprintf(stderr,"erreur lors de la fermeture du ficher %s" ,transporteur);
    perror("");
    return EXIT_FAILURE;
  }

}

int convertit_minuscule(char *file_in, char *file_out)
{
  FILE* fdin=fopen(file_in,"r");
  FILE* fdout=fopen(file_out,"w");
  unsigned char lettre;
  if(fdin==NULL)
  {
    fprintf(stderr,"erreur lors de l'ouverture du fichier %s",file_in);
    perror("");
    return EXIT_FAILURE;
  }
  if(fdout==NULL)
  {
    fprintf(stderr,"erreur lors de l'ouverture du fichier %s",file_out);
    perror("");
    return EXIT_FAILURE;
  }
    while((lettre=fgetc(fdin))!=EOF)
    {
      tolower((int)lettre);
      fputc(lettre,fdout);
    }
    fclose(fdin);
    fclose(fdout);


}


int encrypte_texte(char *source, char *original,char *transporteur)
{
  FILE* fd_transporteur=fopen(transporteur,"w");
  FILE* fd_original=fopen(original,"r");
  FILE* fd_source=fopen(source,"r");
  unsigned char buffer;



  if(fd_transporteur==NULL)
  {
    printf("erreur lors de l'ouverture du fichier %s",transporteur);
    perror("");
    return EXIT_FAILURE;
  }
  if(fd_source==NULL)
  {
    printf("erreur lors de l'ouverture du fichier %s",source);
    perror("");
    return EXIT_FAILURE;
  }
  if(fd_original==NULL)
  {
    printf("erreur lors de l'ouverture du fichier %s",original);
    perror("");
    return EXIT_FAILURE;
  }
  //on commence par recopier le contenu du file_header



  while((buffer=fgetc(fd_source))!=EOF )
  {





    for(int indice_bit=1;indice_bit<=8;indice_bit++)
    {
      char lettre_original=fgetc(fd_original);
        if(isalpha(lettre_original))
        {
          if(buffer & 1)
          {
            toupper(lettre_original);
          }
          fputc(lettre_original,fd_transporteur);


        }

        buffer=buffer>>1;

    }

  }

  if (fclose(fd_original)==EOF)
  {
    fprintf(stderr,"erreur lors de la fermeture du ficher %s" ,original);
    perror("");
    return EXIT_FAILURE;
  }

  if (fclose(fd_source)==EOF)
  {
    fprintf(stderr,"erreur lors de la fermeture du ficher %s" ,source);
    perror("");
    return EXIT_FAILURE;
  }

  if (fclose(fd_transporteur)==EOF)
  {
    fprintf(stderr,"erreur lors de la fermeture du ficher %s" ,transporteur);
    perror("");
    return EXIT_FAILURE;
  }

}
