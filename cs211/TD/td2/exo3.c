#include <stdio.h>

#define MAXLEN 1024

int main(int argc, char *argv[])
	{
	FILE *fi;
	FILE *fo;
	char buf[MAXLEN];
	size_t len;

	if (argc != 3 ) {
		printf("usage: %s <file in> <file out>\n");
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
}
