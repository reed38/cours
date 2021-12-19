#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int find_number_f_digits(int nombre);

void afficher(int tab[], int size);


int find_number_f_digits(int nombre)
{

  for (int i=1;i<nombre;i++)
  {

    if(((i-1) <= log10(nombre)) && (log10(nombre) <=i))
      {
      return (i);
       }

     }


}

void afficher(int tab[], int size)
{
  printf("\n");
  for (int i=0;i<size; i++)
  {
    printf("%d ", tab[i]);
  }


}


int main(void)
{
int nombre_max;
printf("nombre max:\n");
scanf("\n%d",&nombre_max);



for (int nombre=0;nombre<nombre_max;nombre++)
  {
    printf("%d\n",nombre);
    int nombre_digits=find_number_f_digits(nombre);
    int somme_cubes=0;
    for (int digit=0;digit<=nombre_digits;digit++)
    {
      somme_cubes+=pow(nombre% (int) pow(10,digit),3);
    }

    if(somme_cubes==nombre)
      printf("le nombre %d vérrifie les conditions \n",nombre);


  }




      return(0);

}
