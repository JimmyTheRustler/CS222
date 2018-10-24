/*
 Authors: Jimmy O'Brien and Austin Reth
 Created: 02/09/2018
 Title: Project 2
 Description: Creates a one time pad encryption and decryption.
*/

#include <stdio.h>
#define MAX 2048
#define DELIM 255

int input(char readIn[]);

int main(){

	char currChar;
	char message[MAX];
	char key[MAX];
	int messLength = input(message);
	int keyLength = input(key);
/*	int i;
	for(i = 0; i < keyLength; i++)
		printf("%c", key[i]);
*/
	
	return 0;
}

int input(char readIn[]){
	int index = 0;
	int currChar;
	while(index < MAX){
		currChar = getchar();
		if(currChar == DELIM || currChar == EOF)
			return index;
		else
			readIn[index] = currChar;
		index++;
	}
	return index;
}
