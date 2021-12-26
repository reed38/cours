#include <stdio.h>
#include <stdlib.h>


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

int nombres_impaires()
{
  char* outputo="nombres_impaires.txt";
  FILE* output =fopen(outputo,"w");
  if (output==NULL)
  {
    printf("erreur lors de l'ouverture du fichier %s",outputo);
    perror("");
    return EXIT_FAILURE;
  }
  int count=0;
  int i=0;
  while(count<100)
  {
    if (i%2==1)
    {
      fprintf(output,"%d ",i);
      count++;

    }
    i++;

  }
  if(fclose(output)==EOF)
  {
    fprintf(stderr,"ereur lors de la fermeture du fichier %s",outputo);
    perror("");
    return EXIT_FAILURE;
  }
}


int lis_et_compte(char *fichier)
{
  int nmbre_voyelles=0;
  char c;
  char* liste_voyelle="aeiouy";
  FILE* flux=fopen(fichier,"r");
  //gestion d'erreur
  if( NULL == flux ){
    fprintf(stderr,"erreur ouverture %s\n",fichier);
    perror("");
    return EXIT_FAILURE ;

}

  while( EOF != ( c= getc(flux)) )
  {

    if(is_in_char(liste_voyelle,6,c))
      nmbre_voyelles++;
  }
  if(fclose(flux)==EOF)
  {
    printf("erreur lors de la fermeture du fichier %s", fichier);
    return EXIT_FAILURE;
  }


  return(nmbre_voyelles);

}
int main(int argc, char *argv[])

{

  
  printf("\n nombre de voyelles:%d",lis_et_compte(argv[1]));
  return 0;


}
