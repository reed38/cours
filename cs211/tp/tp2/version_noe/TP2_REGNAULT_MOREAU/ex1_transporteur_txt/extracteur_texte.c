#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main()
{

  FILE *ftransporteur, *fsource;
  ftransporteur = fopen("transporteur.txt","r");
  fsource = fopen("source.txt","w");

  char c;
  int oct=0;
  int indice_bit=0;

  while((c=getc(ftransporteur))!=EOF)
  {

    if(indice_bit==8)
    {
      indice_bit=0;
      putc(oct,fsource);
      printf("%d\n",oct);
      oct=0;
    }

    if(isalpha(c)!=0)
    {
      if(isupper(c)!=0)
      {
        oct+=pow(2,7-indice_bit);
      }
      indice_bit++;
    }

  }

  fclose(ftransporteur);
  fclose(fsource);

}
