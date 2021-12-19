#include<stdio.h>
#include<string.h>
#include <stdbool.h>
void iswap(int* a, int* b);
void affiche_2( int (*tab) [2], int longueur, int hauteur);
int retourne_min(int (*tab)[2], int longueur, int hauteur);
int retourne_max(int (*tab)[2], int longueur, int hauteur);
int somme_tableau(int (*tab)[2], int hauteur, int longueur);
int find_element(int (*tab)[2], int longueur, int hauteur, int element);
void affiche_1( int tab[], int longueur);

void affiche_1( int tab[], int longueur)
{
  for (int i=0;i<longueur; i++)
  {
    printf("%d",tab[i]);
  }
}
void affiche_2( int (*tab) [2], int longueur, int hauteur)
{
  for (int i=0;i<longueur;i++)
  {
    for(int j=0;j<hauteur;j++)
    {
      printf("%d",tab[j][i]);

    }
  }
}


int retourne_min(int (*tab)[2], int longueur, int hauteur)
{
  int min=0;
  for (int i=0;i<hauteur;i++)
  {
    for (int j=0; j<longueur; j++)
    {
      if (tab[i][j]<min)
        min=tab[i][j];
    }
  }
  return (min);

}

int retourne_max(int (*tab)[2], int longueur, int hauteur)
{
  int max=0;
  for (int i=0;i<hauteur;i++)
  {
    for (int j=0; j<longueur; j++)
    {
      if (tab[i][j]>max)
        max=tab[i][j];
    }
  }
  return (max);
}



  int somme_tableau(int (*tab)[2], int hauteur, int longueur)
  {
    int somme=0;

    for (int i=0;i<hauteur;i++)
    {
      for (int j=0; j<longueur; j++)
      {
        somme+=tab[i][j];
      }
    }
    return(somme);
  }

  int find_element(int (*tab)[2], int longueur, int hauteur, int element)
  {
    _Bool found=0;
    for (int i=0;i<hauteur;i++)
    {
      for (int j=0; j<longueur; j++)
      {
        if(element==tab[i][j])
        {
          found=1;
          goto fin_de_la_boucle;
        }
      }
    }
    fin_de_la_boucle:printf("\n sortie de la boucle");
    return(found);
  }
void iswap(int* a, int* b)
{
  int tmp=*a;
  *a=*b;
  *b=tmp;
}

void inverse_tableau(int tab[], int longueur)
{

  for (int i=0;i<(longueur/2);i++)
  {
    iswap(&tab[i],&tab[longueur-i-1]);
  }
}


bool lire_ligne(char chaine[],size_t max)
{
  size_t i;
  for (i=0;i< max-1;i++)
  {
    char c;
    if (scanf("%c", &c) != 1)
      return (false);
    else if (c=='\n')
      break;

    chaine[i] = c;
    }
    chaine[i] = '\0';
    return true;

}


int main(void)
{
    char chaine[10];

    printf("Quel est votre prénom ? ");

    if (lire_ligne(chaine, sizeof chaine))
        printf("Bien le bonjour %s !\n", chaine);

    return 0;
}
