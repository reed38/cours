#include <stdio.h>
#include "fonctions.h"

void test()
{
  int* chaine="banane";
  printf ("\nle nombre de caractères est: %d\n",compter_caractere(chaine,'a'));
  return 0;
}
