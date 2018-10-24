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
	
	FILE* file = fopen(fileName, "wb");

	fwrite(&size, sizeof(int), 1, file);
	
	fprintf(file, "%d\n", size);

	int i;
	
	srand(time(NULL));

	
	for(i = 0; i < size; i++){
		int num = rand()%1000;
		fwrite(&num, sizeof(int), 1, file);
		//fprintf(file, "%d\n", rand() % 100000);
	}
	
	fclose(file);
	return 0;
}
