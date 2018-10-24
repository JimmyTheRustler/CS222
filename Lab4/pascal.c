#include <stdio.h>

int readInt(){
	int c = 0;
	int i = 0;
  
	while( (c = getchar()) != EOF && c != '\n' )
	{
		if( c >= '0' && c <= '9')	
			i = i * 10 + (c - '0');	
	}

	return i;
}

long long factorial(long long row){
	if(row == 0 || row == 1)
		return 1;
	else
		return row * factorial(row - 1);
	
	
}

int main(){
	int usrInput;
	int row, col;
	int ans;	
	printf("Enter how many rows your want (0-20): ");
	usrInput = readInt();

	if(usrInput > 20 || usrInput < 0){
		printf("Invalid Input");
		return 0;
	}
	
	for(row = 0; row < usrInput; row++){
		for(col = 0; col < row+1; col++){
			ans = factorial(row) / (factorial(row-col) * factorial(col));
			printf("%d ",ans);
		}
		printf("\n"); 
	}
	
	return 0;
}
