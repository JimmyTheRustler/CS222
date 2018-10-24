#include<stdio.h>

int readInt(){
	int c = 0;
	int i = 0;
	while ( (c = getChar()) != '\n' && c != EOF && c != ' ' ){
		if( c >= '0' && c <= '9'){
			total = total * 10 + ( c - '0');
		}
	}
	return total;
	
}

void selectionSort(int array[], int size){
	int i = 0;
	
	for(int i = 0; i < size; i++){
		int j = 0;
		int small = i; //array[i]??
		for(j = i; j < size; j++){
			if(array[j] < array[small]){
				small = j;
			}
		}
	}
	int temp = array[i];
	array[i] = array[small];
	array[small] = temp;
	
	
	
}

int main(){
	int values[100];
	int size = 0;
	int min = values[0];
	int max = values[0];
	int total;
	int i = 0;
	double mean;

	do{
		printf("Enter an int (0-100)");
		size = readInt();
	}while(size > 100);
	
	printf("Enter positive Int's: ")
	
	//int i = 0;
	for( i = 0; i < size; i++){
		values[i] = readInt();
	}

	//int max = values[0];
	//int min = values[0];

	for(i = 0; i < size; i++){
		if(values[i] > max)
			max = values[i];
		else if(values[i] < min)
			min = values[i];
	}
	//int total;
	//double mean;
	
	for(i = 0; i < size; i++){
		total += values[i];
		mean = total / size;
	}
	
	double variance = 0.0;
	for(i = 0; i < size; i++){
		variance += (values[i] - mean) * (values[i] - mean);
		
	}
	variance /= size - 1;
	selectionSort(values, size);
		
	if(size % 2 == 0){
		median = .5 * (values[size / 2];
	}
	else{
		median = values[size / 2];
	}
	
	
	
	printf("Max: %d", max);
	printf("Min: %d", min);
	printf("Mean: %f", mean);
	
	



	
	return 0;
}
