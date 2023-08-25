#include "bits.h"

void afficheBits(int n){
  int i=8*sizeof(int)-1;
  for(i;i>=0; i--) printf(" %d ",BIT(n,i));
  printf("\n");
} 
