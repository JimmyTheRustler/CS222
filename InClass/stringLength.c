#include <stdio.h>


int length( char string[] ){
	
	int i = 0;
	while(string[i] != '\0'){
		i++;
	}
	return i;
	
	
}

void reverseString( char string[] ){
	
	int i = 0;
	int size = length(string);
	for( i = 0; i < size/2; i++ ){
		char temp = string[i];
		string[i] = string[size - i - 1];
		string[size - i - 1] = temp;
		
	}
	
}

int main(){
	
	char text[] = "I like potatoes!";
	int size = length(text);
	
	printf("Text length = %d\n", size);


	return 0;
}
