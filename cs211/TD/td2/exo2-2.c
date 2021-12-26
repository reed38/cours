#include <stdio.h>

int main(void)
{
        char c;
        printf("entrer un premier caractère\n");
        scanf("\n%c",&c);
        printf("le caractère est %c de code ascii decimal %d et hexadecimal 0x%x\n",c,c,c);
        printf("entrer un deuxième caractère\n");
        scanf("\n%c",&c); 
        printf("le caractère est %c de code ascii decimal %d et hexadecimal 0x%x\n",c,c,c);
	return 1;
}
