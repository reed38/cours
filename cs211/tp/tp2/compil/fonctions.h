FILE* open_file(char *file, char *mode);
int close_file(FILE* flux);
int exo1(char *input, char* output);
int exo2(FILE* transporteur,FILE* source, int offset,size_t tailleimage);
void masquage1(FILE* originel, FILE* source, FILE* transporteur,size_t taille);
void read_header(fichierEntete *fichier,imageEntete* image, couleurPallete* pallette,FILE* flux);
void afficher_header(fichierEntete struct_fichier_en_tete, imageEntete struct_image_en_tete);
