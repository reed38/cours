#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int nombre;
  printf("saisissez le nombre: \n");
  scanf("%d", &nombre);


  while (nombre!=1)
  {
    if(nombre%2==0)
      nombre/=2;
    else
      nombre*=3+1;

    printf("%d", nombre);
  }
  for (int i=0;1<10;i++)
  {
    if(nombre%2==0)
      nombre/=2;
    else
      nombre*=3+1;

    printf("%d", nombre);

  }
  return 0;
}
