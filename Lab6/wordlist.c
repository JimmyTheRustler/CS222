#include <stdio.h>
#include <string.h>

void backwards(char **argv, int count);

void reverse(char **argv, int count);

void sort(char **argv, int count);

int main(int argc, char **argv){
	
	int i = 0;
	char **arguments;	

	while(argc[1][i] != '\0'){
		if(argc[1][1] != '-')
			printf("Invalid Input");
		else{
			i++;
			arguments += argc[1][i];
		}
	}

	return 0;
}

void backwards(char **argv, int count){
	//reverse argv[2]+
	int argCount = 2;
	int i = 0;
	int currChar;
	
	while(argv[argCount][i] != '\0'){
		currChar = argv[argCount][i];
		
	}
	
}
void reverse(char **argv, int count){
	int i = 2;
	int j = 0;

	while(argv[i][j] != '\0')
		i++
	while(i > 2){
		while(argv[i][j] != '\0'){
			printf(argv[i][j]);
			j++;
		}
		i--;
	}
	
	
}
void sort(char **argv, int count){
	
	
	
}


