#include <stdio.h>
#include <stdlib.h>

int main(){

	char* array = NULL;
	int size = 10;

	do
	{

		array = (char*)malloc(sizeof(char)*size);
		if(array != NULL){
			array[0] = 'a';
			free(array);
			size *= 10;
		}
	}while(array != NULL);

	printf("Size thats too big: %u \n", size);
	
	return 0;
}
