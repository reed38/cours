#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])
	{


	FILE* fdin=fopen(argv[1],"r");
	FILE* fdout=fopen(argv[2],"w");
	int i=0;
	int c1,c2;
	int c[10];
	if(fdin==NULL)
	{
		fprintf(stderr,"error when reading the input file %s",argv[0]);
		perror("");
		return EXIT_FAILURE;
	}
	if(fdout==NULL)
	{
		fprintf(stderr,"error when writing the output file %s",argv[1]);
		perror("");
		return EXIT_FAILURE;
	}

		fprintf(stdout,"\nsaisissez les deux colones à échanger sous la forme c1:c2: \n");
		scanf("\n%d:%d",&c1,&c2);
		fprintf(stdout, "\n%d: %d ",c1,c2);






	// read a formated line (format is strict)
	// and we assume it has been checked before
	while((fscanf(fdin,"%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;",c,c+1,c+2,c+3,c+4,c+5,c+6,c+7,c+8,c+9)) == 10 ) {
		for (i=0;i<10;i++) {
			if (i == c1 ) fprintf(fdout,"%d;",c[c2]);
			else if (i == c2 ) fprintf(fdout,"%d;",c[c1]);
			else fprintf(fdout,"%d;",c[i]);
		}
		fprintf(fdout,"\n");
	}

	// dont forget to close file
	fclose(fdin);
	fclose(fdout);

	return 0;
}
