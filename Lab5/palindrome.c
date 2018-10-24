#include <stdio.h>

#define MAX 1024

int input(char readIn[]){
	int index = 0;
	int currChar = getchar();
	while(currChar != EOF && currChar != '\n'){	
		if(index < MAX){
			readIn[index] = currChar;
			index++;
		}
		currChar = getchar();
	}
	readIn[index] = '\0';
	return index;
}


		
int main(){
	char usrInput[MAX];
	int count = 0;
	int diff = 'a' - 'A';
	int palinTrue = 1;
	
	printf("Enter word: ");
	count = input(usrInput);

	for(int i = 0; i < count / 2 && palinTrue == 1; i++){
		char tempBegin = usrInput[i];
		char tempEnd = usrInput[count - 1 - i];
		if(tempEnd >= 'A' && tempEnd <= 'Z')
			tempEnd += diff;
		if(tempBegin >= 'A' && tempBegin <= 'Z')
			tempBegin += diff;
		
		if(tempBegin != tempEnd)
			palinTrue = 0;
		
		
	}
	for(int i = 0; i < count; i++){
		printf("%c", usrInput[i]);
	}
	
	if(palinTrue == 0)
		printf(" is not a Palindrome! \n");
	else
		printf(" is a Palindrome! \n");

	return 0;
}
