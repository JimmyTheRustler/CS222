#include <stdio.h>


int main(){

	int a = 10;
	int b = 20;
	int c = 30;
	
	int* value = &b;
	value++;
	
	printf("%d\n", *value);
	
	int numbers[] = {3, 5, 7, 9, 11};
	int* value1;
	value1 = numbers;
	
	
	return 0;
}
