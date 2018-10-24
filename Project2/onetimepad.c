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
unsigned char rotate(unsigned char character, int count);
int sum(char array[], int size);
int bits(unsigned char character);

int main(){

	unsigned char message[MAX];//stores the message
	unsigned char key[MAX];//stores the key	
	
	int messLength = input(message);
	int keyLength = input(key);
	int i = 0;
	int index = keyLength;
	
	
	while(index < messLength){//tiling, repeats the key over and over until it is the same length as the message
		key[index] = key[index % keyLength];
		index++;
	}
	
	keyLength = messLength;
	
	int sum = key[keyLength - 1] % keyLength;	
	
	for( i = 0; i < messLength; i++){//chaining
		int num = i - 1;
		if(i == 0)//num < 0
			num = messLength - 1;
		key[i] = rotate(key[i] ^ key[sum], bits(key[num]));
		sum += key[i];
		sum = sum % messLength;
	}

	for(i = 0; i < messLength; i++)//prints the encrypted/decrypted message
		putchar( message[i] ^ key[i]);
	
	
	return 0;
}
/*
*bits: counts the number of ones in the binary equivalent of the chararacter
*returns: the number of ones as an int
*/
int bits(unsigned char character){
	int count = 0;
	int i = 0;
	for(i = 0; i < 7; i++){
		if(character % 2 == 1)
			count++;
		character = character >> 1;
	}
	
	return count;
}

/*
*rotate: takes an unsigned char and right shifts by count, wraps the numbers back around leaving the MSB as a zero
*returns: the new unsigned char that has been rotated
*/

unsigned char rotate(unsigned char character, int count){
	
	int i = 0;
	int odd = 0;//1 if odd, 0 if even
	for(i = 0; i < count; i++){
		odd = (character % 2);
		character = (character >> 1);
		if(odd == 1)
			character = character | (1 << 6);
	}
	
	return character;
}

/*
*input: reads in a file and stores into an array, stops when it hits the delimiter or EOF
*returns: returns a char array with the message or key stored inside
*/

//look at
int input(char readIn[]){
	int index = 0;
	int currChar = getchar();
	while(currChar != EOF && currChar != DELIM){	
		if(index < MAX){
			readIn[index] = currChar;
			index++;
		}
		currChar = getchar();
	}

	return index;
}
