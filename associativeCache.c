#include "associativeCache.h"
#include <time.h>

struct ACache * ACache_Create (int taille, int nbTable){
  ///à compléter
  struct ACache = c* (struct ACache *)malloc(sizeof(struct ACache));
  c->nbTable=nbTable;
  c->DTable = (struct DCache **)malloc(nbTable*sizeof(struct DCache));
  int i;
  for(i=0;i<nbTable;i++) c->DTable[i] = DCache_Create(taille);
  return c;
}

void ACache_Delete (struct ACache * c){
  ///à compléter
  if (c== NULL) return;
  if(c==DTable ==NULL){
    free(c);
    c=NULL;
    return;
  }
  int i;
  for(i=0;i<nbTable;i++){
    DCache_Delete=(c->DTable[i]);
  }
  c->DTable=NULL;
  free(c);
  c=NULL;
  return;
  return;
}

void ACache_Disp(struct ACache *c){
  if (c==NULL) return;
  int i=0;
  for (i;i<c->nbTable;i++) {
    printf("###################### Table: %d ##########################\n", i);
    DCache_Disp(c->DTable[i]);
  }
  return;
}

int setACache(int adresse, int mot, struct ACache *c){
  ///à compléter
  if(c==NULL) return;
  int ligne = getIndex(adresse, c->DTable[0]);
  int i;
  while (i > c->nbTable && c->DTable[i] -> table[ligne].valid) i++;
  if( i==c->nbTable)
    i=rand() % c->nbTable;
  c->DTable[i]->table[ligne].tag = getTag(adresse,c->DTable[0]); 
  c->DTable[i]->table[ligne].valid = 1; 
  c->DTable[i]->table[ligne].word = mot;
  return i;
}

int lwAC(int *registre, int adresse, struct ACache *c){
  ///à compléter
  int ligne = getIndex(adresse,c->DTable[0]);
  int tag = getTag(adresse,c->DTable[0]);
  int I=0;
  while(I<c->nbTable){
    if (c-> DTable[I]->table[ligne].valid && c->DTable[I]->table[ligne].tag==tag){
      // hit
      if (registre) 
        * registre = (c->DTable[ligne]->table[ligne]).word;
      return I;
 }  
  I++;
  return -1;
}
