#include <stdio.h>
#include <math.h>
#include "bitmap.h"

int main()
{
  FILE *originel, *secret, *transporteur2;
  originel = fopen("originel.bmp","r");
  secret = fopen("secret.bmp","r");
  transporteur2 = fopen("transporteur2.bmp","w");

  if(originel==NULL)
  {
    printf("Erreur d'ouverture de l'originel.");
    return 1;
  }

  if(secret==NULL)
  {
    printf("Erreur d'ouverture du secret.");
    return 1;
  }

  if(transporteur2==NULL)
  {
    printf("Erreur de création du transporteur2.");
    return 1;
  }


  //RECOPIE INTEGRALE DE ORIGINEL DANS TRANSPORTEUR

  fichierEntete BMP_header;
  imageEntete DIB_header;

  fread(&BMP_header, sizeof(fichierEntete), 1, originel);
  fread(&DIB_header, sizeof(imageEntete), 1, originel);


  fwrite(&BMP_header, sizeof(fichierEntete), 1, transporteur2);
  fwrite(&DIB_header, sizeof(imageEntete), 1, transporteur2);


  unsigned char pixel_value;
  while(fread(&pixel_value, sizeof(char), 1, originel) == 1)
  {
    fwrite(&pixel_value, sizeof(char), 1, transporteur2);
  }

  //On se replace au niveau des matrices de pixel (offset de 54)
  fseek(transporteur2, 54, SEEK_SET);
  fseek(originel, 54, SEEK_SET);



  //MASQUAGE DU SECRET DANS L'ORIGINEL

  unsigned char secret_octet_value, pixel_originel_value, transporteur_octet_value;
  while(fread(&secret_octet_value, sizeof(char), 1, secret) == 1) //TQ il y a des octets du fichier secret à dissimuler, on en lit un
  {
    for(int i=0; i<=7; i++) //pour chque bit de l'octet secret
    {
      fread(&pixel_originel_value, sizeof(char), 1, originel); //on lit le premier octet de pixel de l'originel
      unsigned char puiss=pow(2,7-i); //pow retourne un long et le ET logique entre char et long ne marche pas, on convertit le long en char
      transporteur_octet_value = ((pixel_originel_value&254) + ((secret_octet_value&puiss)/puiss));
      fwrite(&transporteur_octet_value, sizeof(char), 1, transporteur2);
      //l'octet à écrire est l'octet originel, avec le bit de poids faible à 0 (masque 254),
      // + 0 ou 1 selon si le bit i de l'octet secret est à 0 ou 1
    }
  }




  fclose(originel);
  fclose(secret);
  fclose(transporteur2);

  return 0;
}
