#include <stdio.h>
#include<stdlib.h>
#include "mymath.h"

int main(int argc,char *argv[])
{
  int nombre;
  printf("\nsaisissez le nombre: ");
  scanf("\n%d",&nombre);
  printf("\nla factorielle du nombre est: factorielle=%d",factorielle(nombre));
  return 0;
}
