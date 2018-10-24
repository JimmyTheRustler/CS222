#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	
	srand(time(NULL));
	int i = 0;
	for(i = 0; i < 10; i++){
		int val = rand() % 3 - 1;
		printf("%d\n", val);
	
	}


	return 0;
}
