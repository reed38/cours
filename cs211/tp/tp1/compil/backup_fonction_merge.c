void merge(int *tab, int* tmp[],int right , int mid, int left, int* CNT)
{

	if (left>right)
	{
		fprintf(stderr,"erreur left>right");
		return (EXIT_FAILURE);
	}



		int i, j, k;
		int n1 = mid - left + 1;
		int n2 = right - mid;
		// on recopie le contenu de tab dans tmp
		copy_past_tab(tab,tmp,sizeof(tab)/sizeof(int));

		/* Merge the temp arrays back into arr[l..r]*/
		i = 0; // indexe initiale du sous tableau a gauche
		j = 0; // indexe initiale du sous tableau a droite
		k = 0; // indexe initiale du tableau mergé

		while (i < n1 && j < n2)
		{
			if (tab[n1+i] <= tab[n2+j]) {
				tmp[k] = tab[n1+i];
				i++;

			}
			else {
				tmp[k] = tab[n2+j];
				j++;
			}
			k++;
			CNT++;
		}

		//on copie les éléments restant si il y en a du sous tableau a gauche
		while (i < n1)
		{
			tmp[k] = tab[n1+i];
			i++;
			k++;
			CNT++;
		}

		//on copie les éléments restant si il y en a du sous tableau a droite
		while (j < n2) {
			tmp[k] = tab[n2+j];
			j++;
			k++;
			CNT++;
		}
	}





void mergeSort(int arr[], int l, int r)
{
	if (left < right) {
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int m = l + (r - l) / 2;

		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}





void merge(int *tab, int length, int* CNT)
{
	int tab*=malloc(length*sizeof(int));


	for (int i=0;i<length/2;i++)
	{
		if(tab[(2i)]<tab[(2i+1)])
			swap(tab[(2i)],tab[(2i+1)]);
	}

	for int(i=0;i<length/4;i++)
	{
		if(tab[(4i)]<tab[(4i+2)])
			swap(tab[(4i)],tab[(4i+3)]);

			if(tab[(4i+1)]<tab[(4i+2)])
				swap(tab[(4i)],tab[(4i+2)]);

	}


}
