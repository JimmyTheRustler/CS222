#include<stdio.h>
/*
Date: 	  1-31-19
Class: 	  CS 222
Project:  Project 1
Names:	  James O'Brien
	  Nathan Cafarchio


*/

int main() {	

	printf("Lazy Caterer's Sequence:\n");	
	
	lazyCaterer();
	
	printf("\n\n");

	
	printf("Prime Numbers:\n");		
	
	primeCheck();
	
	printf("\n\n");
	

	printf("Fibonacci Sequence:\n");	
	
	fibonacci();
	
	printf("\n\n");


	printf("Collatz Stopping Times:\n");	
	
	collatz();
	
	printf("\n\n");


	printf("Happy Numbers:\n");	
	
	happy();
	
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

void fibonacci(){

	long long current = 1;

	long long prev1 = 0;

	long long prev2 = 0;

	int i;

	


	for(i = 0; i < 50; i++){

		printf("%lld ", current);

		prev2 = prev1;

		prev1 = current;

		current = prev1 + prev2;


	}





}


void collatz(){

	int count = 0;

	int i;

	int current;


	for(i = 1; i <= 50; i++){

		current = i;

		while(current != 1){

			if(current % 2 == 0){
		
				current = current / 2;

			} else {

				current = current * 3 + 1;
			
			}
			
			count++;

		}
	
		printf("%i ", count);
		
		count = 0;

	}

}


void happy(){

	int count = 0;

	int i = 1;

	int current;

	int sum;

	int digit;


	while(count < 50){

		current = i;

		

		while(current != 4 && current != 1){

			sum = 0;
	
			while(current > 0){

				digit = current % 10;

				sum = sum + (digit * digit);

				current = current / 10;

			}

			current = sum;


		}

		if(current == 1){
		
			printf("%i ", i);

			count++;

		}

		i++;

	}	



}


