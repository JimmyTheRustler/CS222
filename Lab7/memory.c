#include <stdio.h>
#include <stdlib.h>

void merge(int array1[], int len1, int array2[], int len2, int result[]);

int main(){
	
	int len1;
	int len2;
	int* array1;
	int* array2;
	int* result;
	int i;
	
	printf("Enter length of 1st list: ");
	scanf("%d", &len1);
	printf("Enter length of 2nd list: ");
	scanf("%d", &len2);

	array1 = malloc(sizeof(int) * len1);
	array2 = malloc(sizeof(int) * len2);
	result = malloc(sizeof(int) * (len1 + len2));

	for(i = 0; i < len1; i++){
		scanf("%d", &array1[i]);
	}
	for(i = 0; i < len2; i++){
		scanf("%d", &array2[i]);
	}
	
	merge(array1, len1, array2, len2, result);

	printf("List 1: ");
	for(i = 0; i < len1; i++){
		printf("%d ", array1[i]);
	}
	printf("\n");
	printf("List 2: ");
	for(i = 0; i < len2; i++){
		printf("%d ", array2[i]);
	}
	printf("\n");
	printf("Merged list: ");
	for(i = 0; i < len1+len2; i++){
		printf("%d ", result[i]);
	}
	printf("\n");
	
	free(array1);
	free(array2);
	free(result);
		
	return 0;
}

void merge(int array1[], int len1, int array2[], int len2, int result[]){
	
	int i = 0;
	int j = 0;
	int k = 0;
	
	while( i < len1 && j < len2 ){
		if(array1[i] < array2[j]){
			result[k] = array1[i];
			k++;
			i++;
		}
		else{
			result[k] = array2[j];
			k++;
			j++;
		}
		
	}
		
	while( i < len1 ){
		result[k] = array1[i];
		k++;
		i++;
	}
	while( j < len2 ){
		result[k] = array2[j];
		k++;
		j++;
	}
	
}


