#include <stdio.h>

/*int main(void)
{
int mois;
int annee;
int jour;
char prenom[100];
  printf("saisissez année de naissance: \n");
  scanf("%d",&annee);
  printf("saisissez le mois de naissance: \n");
  scanf("\n%d",&mois);
  printf("saisissez jour: \n");
  scanf("\n%d",&jour);

  printf("prénom: \n");
  scanf("%s",prenom);

  printf("vous vous appelez %s née le %d/%d/%d",prenom,annee,mois,jour);
  return (0);
}*/

  int main(int argc,char* argv[])

{
  printf("\n saisissez le chemin du fichier: ");
  char nom_fichier[100];
  scanf("%s",nom_fichier);
  FILE * fopen(const char* nom_fichier, const char *w);

}
