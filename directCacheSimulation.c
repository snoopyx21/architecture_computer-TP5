#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "directCache.h"

int rand_Adresse(int inf, int supp){
  int interval = supp-inf;
  int adresse = (rand() % interval )+ inf;
  return adresse;
}


int main(int argc, char **argv){
 srand (time(NULL));
 ///à compléter
 struct DCache * c =DCache_Create(7);
 int nblw=1000000;
 int infaddr=0x00000000;
 int suppaddr=0x00000FFF;
 int nbhit=0;
 int nbmiss=0
 int I=0;
 int adresse;
 DCache_Disp(c);
 for(I=0;I<NBLW;I++){
   adresse=rand_Adresse(infaddr,suppaddr);
   printf("adresse : %x \n",adresse);
   if (lwDC(NULL,adresse,c) nbhit++;
   else nbmiss++;
 }
 DCache_Disp(c);
 printf("lecture : %10d , hits : %10d , miss : %10d \n",nblw,nbhit,nbmiss);
 DCache_Delete(c);
 return 0;
} 
