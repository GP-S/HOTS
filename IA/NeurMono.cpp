#include "NeurMono.h"
#define lengthEntryVector 5
#define nb_entry lengthEntryVector

NeurMono::NeurMono(char * entryTab, char * weightList, int treshold, Agent * agent) :
Neurone(entryTab,  weightList, treshold)
{
	this->Asset = agent;
	int HighAverage=0;
	int HA=0;
	int LowAverage=0;
	int LA=0;
	int Average=0;
}

NeurMono::~NeurMono()
{
}

int NeurMono::getOutput()
{
	int res = 0;
	for (int i = 0; i < lengthEntryVector; i++)
	{
		res += weightList[i] * entryTab[i];
	}
	//return calculatedOutput=res>treshold?1:0;
	if(res>treshold)
	   return calculatedOutput=1;
	else
	  return calculatedOutput=0;
}


void NeurMono::learn(int expectedOutput)
{	int j;
	int k;
	int i;
	/* Firstly we calculate the average of all the element of the entry vector, then the low average 
	 * (average of the element which are lower than the average) and the high average (same thing but 
	 * with the elements higher than the average) 
	 * */
	for(j=0;j<lengthEntryVector;j++){
		Average=Average+weightList[j]/lengthEntryVector;
	}
	for(k=0;k<lengthEntryVector;k++){
		if(weightList[k]>=Average){
			HighAverage+=weightList[k]; // high average * number of elements
			HA++; // number of elements higher than the average
		}
		else{
			LowAverage+=weightList[k];
			LA++;
		}
	}
	HighAverage=HighAverage/HA;
	LowAverage=LowAverage/LA;
	
	/* Now, depends on the equality beetwen the calculated output and the expected output, we modify 
	 * the weight of the neurone.
	 * */
	if((calculatedOutput==1 && expectedOutput==1) || (calculatedOutput==0 && expectedOutput==1)){
		for(i=0;i<lengthEntryVector;i++){
			/* The modification of the weight is not uniform, the lower weights have the lower augmentation
			 * and the higher weights have the stronger augmentation. 
			 * */
			if(weightList[i]<LowAverage)
				weightList[i]+=delta;
			else if(LowAverage<=weightList[i]<Average)
				weightList[i]+=2*delta;
			else if(Average<=weightList[i]<HighAverage)
				weightList[i]+=3*delta;
			else
				weightList[i]+=4*delta;
		}
	}
	else if(calculatedOutput==1 && expectedOutput==0){
		for(i=0;i<lengthEntryVector;i++){
			/* We use this way of modification to emphasize particular comportments. 
			 * */
			if(weightList[i]<LowAverage)
				weightList[i]-=2*delta;
			else if(LowAverage<=weightList[i]<Average)
				weightList[i]-=4*delta;
			else if(Average<=weightList[i]<HighAverage)
				weightList[i]-=4*delta;
			else
				weightList[i]-=2*delta;
		}
	}
	else
		{/* then we have calculatedOutput==expectedOutput==0 and we do nothing */}
}

