#include <stdio.h>
#include <stdlib.h>


void test(int* tab)
{
  printf("%ld",(sizeof(tab)/sizeof(int)));
}

int main(void)
{
  int *ptr=malloc(5*sizeof(int));
  test(ptr);
  return 0;
}
