/* Fonction compter_caractere renvoyant un entier, prenant en entrée une chaine de caractères, et un caractère.
Cette fonction compte et retourne le nombre d’occurrences du caractère dans la chaine. */

int compter_caractere(char *s, char c) {
	int indice=0;
	int compteur=0;
	while(s[indice]!='\0')
	{
		if(s[indice]==c)
			compteur++;

		indice++;

	}
	return compteur;
}


/* Fonction sous_chaine, prenant en entrée une chaine de caractères et un caractère,
cette fonction retourne un pointeur vers la première occurrence du caractère dans la chaine, NULL si non trouvé */

char *sous_chaine(char *s, char c) {
	int indice=0;
	char *ptr=NULL;
	while((s[indice]!='\0') && (s[indice]!=c)
	{
		if(s[indice]==c)
			indice++;
	}
	ptr=s+indice;
	return ptr;
}


/* Fonction supprimer_espace, prenant en entrée une chaine de caractères
cette fonction remplace dans la chaine de caractères en paramètre, toutes les successions de plusieurs espaces consécutifs par un seul espace
Cette fonction retourne le nombre de suppression
*/
int supprimer_espace(char *s) {
	return -1;
}


/* Fonction majuscule, prenant en entrée une chaine de caractères.
Cette fonction permet de substituer dans la chaine en parametre:
	- un caractère de l'alphabet minuscule qui suit une ponctuation (les caractères .!?) suivi d'un espace,
	- le premier caractère de la chaine par sa majuscule (s'il existe)
Cette fonction retourne le nombre de substitutions.

exemple: "bonjour! comment vas-tu?"  --> "Bonjour! Comment vas-tu?
exemple: " bonjour! comment vas-tu?" --> " bonjour! Comment vas-tu?

*/

int majuscule(char *s) {
	return -1;
}


/* PLUS DUR :
Fonction modifier_chiffre, prenant en entrée une chaine de caractères, cette fonction doit modifier les chiffres par leur représentation en caractères ex:
j'ai 2 voitures --> j'ai deux voitures
--- On ne traitera pas les nombres ni les accords !!
j'ai 23 voitures --> j'ai 23 voitures
j'ai 1 voiture   --> j'ai un voiture
cette fonction retournera un pointeur vers un type char indiquant la chaine de caractères destination.
Cette fonction je vous l'accorde est totalement inutile ;)
*/

char *modifier_chiffre(char *s) {
	return NULL;
}
