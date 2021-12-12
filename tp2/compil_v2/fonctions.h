#include <stdio.h>

int ex1(char *fichier_transporteur,char* fichier_source);

 void read_header(char *fichier_transporteur,/*couleurPallete struct_couleurs, imageEntete strcuct_img_entete,*/ fichierEntete struct_fichier_entete);
int lire_header(fichierEntete *file_header, imageEntete *picture_header, char* fichier);
void afficher_header(fichierEntete struct_fichier_en_tete, imageEntete struct_image_en_tete);
int decrypte_ex2(char *transporteur, char *source,unsigned int offset,unsigned int taille_image);
int convertit_minuscule(char *file_in, char *file_out);
int encrypte_upper(char *source, char *original,char *transporteur);
