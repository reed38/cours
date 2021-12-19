#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"


void copy_past_tab(int* tab1, int *tab2, int length)
{
	for (int i=0;i<length;i++)
	{
		tab2[i]=tab1[i];

	}
}

void affiche(int* a, int n){
	int i;
	for (i = 0 ; i < n ; i++){
		printf("%d ", a[i]);
	}
	printf("\n\n");
}


int compare(int* a, int *b, int n){
	int i;
	for(i=0; i < n ; i++){
		if (a[i] != b[i]){
			printf("Comparison FAILED at index %d\n\n", i);
			return i;
		}
	}

	printf("Comparison OK\n\n");
	return -1;
}


void swap(int* a, int* b) //prend en entrée deux pointeurs et échange leurs valeur
{
  int tmp= *a;
  *a=*b;
  *b=tmp;
}


int bublle_sort(int* tab, int length)
{
	int count_operations=0;
  for (int i=0;i<length;i++)
  {
    for (int j=0;j<(length-i-1);j++)
      {
        if(tab[j+1]<tab[j])
        {
          swap((tab+j),(tab+j+1));

        }
      }
   }
	 return (count_operations);
}

int insertion_sort(int* tab, int length)
{
	int comparaison_count=0;
	for (int i=1; i<length;i++)
	{
		int j=i;
		while(tab[j]<tab[j-1] && j>0)
		{
			comparaison_count++;
			swap(&tab[j-1],&tab[j]);
			j--;
		}
	}
	return comparaison_count;
}




void merge(int* tab, int* tmp, int left, int mid, int right, int* CNT)
{
    int i=left, j=mid, k=0;

		//on crée une copie de tab dans temp
		for (int i=0;i<right;i++)
		{
			tmp[i]=tab[i];
		}
		//on compare les valeurs des parties doites et gauche de tmp pour les placer dans tab en fct de leur valeurs
    while(i<mid && j<right)
    {
        if(tmp[i]>tmp[j])
        {
            tab[k]=tmp[j];
            j++;
        }
        else
        {
            tab[k]=tmp[i];
            i++;
        }
        CNT++;
        k++;
    }

        //on recopie la moitié restante
        while(i<mid)
        {

        tab[k]=tmp[i];
         i++;
				 k++;
			 	 CNT++;
        }
				while(j<right)
			   {
					tab[k]=tmp[j];
			    j++;
					k++;
					CNT++;
			    }




}

//BONUS
_Bool asc(int a, int b)
{
	if(a<b)
		return 1;
	else
		return 0;
}

_Bool desc(int a ,int b)
{
	if(a>b)
		return 1;
	else
		return 0;
}


int bublle_sort_v2(int* tab, int length,_Bool (*fonction_tri)(int a,int b))
{
	int count_operations=0;
  for (int i=0;i<length;i++)
  {
    for (int j=0;j<(length-i-1);j++)
      {
        if(fonction_tri(tab[j+1],tab[j]))
        {
          swap((tab+j),(tab+j+1));

        }
      }
   }
	 return (count_operations);
}
