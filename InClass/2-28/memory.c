#include <stdio.h>
#include<stdlib.h>


int main(){
	int size;
	
	printf("Enter size of list: ");
	scanf("%d", &size);

	int* array = malloc(sizeof(int) * size);

	int i;
	for(i = 0; i < size; i++){
		printf("Enter element %d: ", i+1);
		scanf("%d", &array[i]);
		
		
	}

	for(i = 0; i < size - 1; i++){
		int small = i;
		int j;
		for(int j = i + 1; j < size + 1; j++){
			if(array[j] < array[small])
				small = j;
		}
		int temp = array[small];
		array[small] = array[i];
		array[i] = temp;
	}
	
	printf("Printing sorted array\n");
	for(i = 0; i < size - 1; i++){
		printf("%d, ", array[i]);
	}
	printf("%d\n", array[i]);
	
	free(array);
	array = NULL;
	
	return 0;
}
