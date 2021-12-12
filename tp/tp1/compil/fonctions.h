#include <stdio.h>


void swap(int* a, int* b);
int compare(int* a, int *b, int n);
void affiche(int* a, int n);
void merge(int* tab, int* tmp, int left, int mid, int right, int* cnt);

void mergeSort(int *tab,int* tmp, int l, int r,int* CNT);
int bublle_sort(int* tab, int length);
int insertion_sort(int* tab, int length);
int bublle_sort(int* tab, int length);
_Bool asc(int a, int b);
_Bool desc(int a, int b);
int bublle_sort_v2(int* tab, int length,_Bool (*fonction_tri)(int a,int b));
