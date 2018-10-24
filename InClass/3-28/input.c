#include <stdio.h>


int main(){
	printf("What is the filename: ");
	char filename[100];
	scanf("%s", filename);
	
	FILE* file = fopen(filename, "r");
	int total;
	fscanf(file, "%d", &total);

	int i;
	int number;
	int sum = 0;
	for(i = 0; i < total; i++){
		fscanf(file, "%d", number);
		sum = number + sum;
	}
	double avg = 0.0;
	avg = sum / (double)total;

	printf("Average: %f", avg);
	fclose(file);
	
	
	return 0;
}
