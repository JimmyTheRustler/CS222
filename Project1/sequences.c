#include<stdio.h>

int main() {	
	printf("Prime Numbers: \n");		
	primeCheck();
	printf("\n");
	

	printf("Lazy Caterer's Sequence:\n");	
	lazyCaterer();
	printf("\n");

	return 0;	
}	

void lazyCaterer(){
	int numCuts;
	int slices;
	int i;
	numCuts = 0;
	slices = 0;
	
	for(i = 0; i <= 49; i++){
		slices = ( (numCuts * numCuts) + numCuts + 2 ) / 2;
		numCuts++;
		printf("%i ", slices);
	}

}

void primeCheck(){
	int primeCount;
	int primeTestNum;
	int boolean;
	int i;

	primeCount = 0;
	boolean = 1; /* 0 == False | 1 == True */


	for(primeTestNum = 2; primeCount < 50; primeTestNum++){
		boolean = 1;
		for(i = 2; i < primeTestNum; i++){
			
			if(primeTestNum % i == 0){
				boolean = 0;	
			}
		}
		if(boolean == 1){
			printf("%i ", primeTestNum);
			primeCount++;
		}
	}
			
}
