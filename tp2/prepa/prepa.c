#include <stdio.h>
#include <stdlib.h>
_Bool is_in_char(char* tab, int length, char element);
void nombres_impairs();
int lis_et_compte(char* nom_fichier);

_Bool is_in_char(char* tab, int length, char element)
{
  _Bool is_in=0;
  for (int i=0;i<length;i++)
  {
    if(tab[i]==element)
    {
      is_in=1;
      break;

    }

  }
  return is_in;
}

void nombres_impairs()
{
  FILE* fl;
  fl=fopen("nombres_impairs.txt","w");
  if(fl==NULL)


  for(int i=0;i<=100;i++)
  {
    if(i%2==1)
      fprintf(fl,"%d",i);

  }
  if(flcose(fl)==EOF)
  {
    fprintf(stderr,"erreur lors de la fermeture fu fichier nombre_impaire.txt")
    return(EXIT_FAILURE);
  }


}



int lis_et_compte(char* nom_fichier)
{
  char c;
  int nmbre_voyelles=0;
  char* liste_voyelle="aeiouy";
  FILE* flux=fopen(nom_fichier,"r");
  //gestion d'erreur
  if( NULL == flux ){
    fprintf(stderr,"erreur ouverture %s\n",nom_fichier);
    perror("");
    return EXIT_FAILURE ;

}

  while( EOF != ( c = getc(flux)) )
  {

    if(is_in_char(liste_voyelle,6,c))
      nmbre_voyelles++;
  }
  if(fclose(flux)==EOF)
  {
    printf("erreur lors de la fermeture du fichier %s", nom_fichier);
    return EXIT_FAILURE;
  }


  return(nmbre_voyelles);




}
int main(int argc, char *argv[])

{
  char *nom_fichier="fichier.txt";
  int a=lis_et_compte(nom_fichier);
  printf("\n nombre de voyelles:%d",a);
  return 0;


}
