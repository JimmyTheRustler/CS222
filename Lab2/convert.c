#include <stdio.h>
#include "conversion.h"

int main(){
	
	int character;
	character = getchar();
	
	while(character != -1){
		if(character != '\r'){
			putchar(character);
		}
		character = getchar();
	
	}	
	
	return 0;
}

