#include <iostream>
#include "Neurone.h"
#include "NeurMono.h"
#include <stdlib.h>

using namespace std;

int main(){
  char tabWeight[5];
  char tabEntry[5];
  int treshold1 = 25;
  int calculatedOutput1;
  
  /* Initialisation of some NeurMono */
  
  NeurMono* neur1 = new NeurMono();
  NeurMono* neur2 = new NeurMono();
  NeurMono* neur3 = new NeurMono();
  NeurMono* neur4 = new NeurMono();
  
  /* Some tests */
  int i=0;
  for(i=0;i<5;i++){
    tabWeight[i]=rand()%14;
  }
  for(i=0;i<5;i++){
    tabEntry[i]=(i+13)%4; 
  }
  
  neur1->setWeightList(tabWeight);
  neur1->setentryTab(tabEntry);
  neur1->setTreshold(treshold1);

  calculatedOutput1 = neur1->getOutput();
  
  

  return 0;
  
  
}