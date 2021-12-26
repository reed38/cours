#include <stdio.h>
#include <stdlib.h>


int main(void)
{
  int year, month, day;
  char prenom[50];
  printf("\nsaisissez votre année de naissance: ");
  scanf("\n %d",&year);
  printf("\n mois: ");
  scanf("\n%d",&month);
  printf("\n jour: ");
  scanf("\n %d",&day);
  printf("\n prenom: ");
  scanf("\n %50s",prenom);
  printf(" vous vous appelez %s, né(e) le %d/%d/%d",prenom,day,month,year);
}
