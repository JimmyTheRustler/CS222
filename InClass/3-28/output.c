#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
	printf("Give me an integer: ");
	int size;
	scanf("%d", &size);
	char fileName[100];
	printf("Enter file name: ");
	scanf("%s", fileName);
	
	FILE* file = fopen(fileName, "w");

	fprintf(file, "%d\n", size);

	int i;
	srand(time(NULL));
	for(i = 0; i < size; i++){
		fprintf(file, "%d\n", rand() % 100000);
	}
	
	fclose(file);
	return 0;
}
