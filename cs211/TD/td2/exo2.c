#include <stdio.h>
#include <stdlib.h>
#include <string.h>



FILE* open_file(const char* fichier, const char* mod)

{
  FILE* fd= fopen(fichier,mod);
  if(fd==NULL)
  {
    fprintf(stderr,"erreur lors de l'ouverture du fichier %s\n",fichier);
    perror("");
    exit (EXIT_FAILURE);
  }
  return fd;


}
// <input> <output> <column1> <column2>   intervert column 1 and column 2
//of input and write the result in output
int main(int argc, char* argv[])
{
  FILE* input=open_file(argv[1],"r");
  FILE* output=open_file(argv[2],"w");
  char* tab [11];
  char buffer[256];
  char *str,*save_ptr,*token;
  int c1=(int)argv[3][0]-48;
  int c2=(int)argv[4][0]-48;
  printf("jiiiijij");

  while(!(feof(input)))
  {
    fgets(buffer,256,input);

    int i;
    for(i=0,str=buffer; ;i++,str=NULL){
      token=strtok_r(str,";",&save_ptr);

      if(token==NULL){
        break;
      }

      else
        tab[i]= token;

    }

      char *tmp=tab[c1];
      tab[c1]=  tab[c2];
      tab[c2]=tmp;

      //on recopie la ligne modifié dans output
      for (int j=0;j<10;j++)
      {

        fwrite(tab[j],sizeof(char)*strlen(tab[j]),1,output);
        fwrite(";",sizeof(char),1,output);

      }
      fwrite("\n",sizeof(char),1,output);






  }
}





/*
#include <stdio.h>

#define MAXLEN 1024

int main(int argc, char *argv[])
	{
	FILE *fi;
	FILE *fo;
	char buf[MAXLEN];
	size_t len;

	if (argc != 3 ) {
		printf("usage:  <file in> <file out>\n");
		return -1;
	}
	if ((fi=fopen(argv[1],"r")) == NULL ) {
		return -1;
	}
	if ((fo=fopen(argv[2],"w")) == NULL ) {
		fclose(fi);
		return -1;
	}
	// loka at man fread to see how to know if it's an error or eof
	while(!feof(fi) && ((len=fread(buf,1,MAXLEN,fi)) != 0 )) {
		fwrite(buf,1,len,fo);
	}

	// dont forget to close file
	fclose(fi);
	fclose(fo);

	return 0;
}*/
