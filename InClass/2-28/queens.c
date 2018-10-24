#include <stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 8
	
int main(){
	
	srand(time(NULL));
	
	char** board = (char**)malloc(sizeof(char*)*8);
	int i;
	for(i = 0; i < 0; i++)
		board[i] = (char*)malloc(sizeof(char)*8);
	
	for(i = 0; i < SIZE; i++){
		for(j = 0; j < SIZE; j++){
			int value = rand() % SIZE;
			if(value == 0){
				board[i][j] = 'Q';
			}
			else{
				board
			}
		}
	}
	
	
	return 0;
}
