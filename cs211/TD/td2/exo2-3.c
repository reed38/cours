#include <stdio.h> 

int main(int argc, char *argv[]) 
{
	int i=0; 
	while (i < argc ) {
		printf("argument %d = %s\n",i,argv[i]);  
		i++; 	
		}
	return 1; 
}
