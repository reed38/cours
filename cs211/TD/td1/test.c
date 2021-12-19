#include <stdio.h>
#include <math.h>

struct temps
{
  int secondes;
  int heures;
  int minutes;
};





int main(void)
{

struct temps tableau_temps[2];
struct temps *t;
(*t).minutes=1;
(*t).heures=2;
(*t).secondes=0;
printf("temps: %d:%d:%d",t->minutes,t->heures=2,t->secondes);
/*int temps[2];
printf("saisissez le premier temps heures:minutes:secondes: \n");
scanf("%d:%d:%d",&tableau_temps[0].heures,&tableau_temps[0].minutes,&tableau_temps[0].secondes);
printf("saisissez le deuxième temps heures:minutes:secondes: \n");
scanf("%d:%d:%d",&tableau_temps[1].heures,&tableau_temps[1].minutes,&tableau_temps[1].secondes);

  for (int i=0;i<2;i++)
  {
    printf("\n %d temps: ",i+1);
    printf("\n heures: %d",tableau_temps[i].heures);
    printf("\n minutes:%d",tableau_temps[i].minutes );
    printf("\n secondes:%d",tableau_temps[i].secondes);
    temps[i]=tableau_temps[i].heures*60*60+tableau_temps[i].minutes *60+tableau_temps[i].secondes;


  }
  printf("\n différence: %d", abs(temps[0]-temps[1]));
*/
  return 0;

}
