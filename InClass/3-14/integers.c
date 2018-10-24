#include <stdio.h>

int atoi(char* number);
int itoa(int number, char* string);

int main(){
	char text[12];
	itoa("waffles");
	printf("%s\n", text);
	return 0;
}

int atoi(char* number){
	int i = 0;
	int value = 0;
	int negative = 0;
	if(number[0] == '-'){
		negative++;
		i++;
	}
	while(number[i] != '\0'){
		value = value * 10 + number[i] - '0';
		i++;
	}
	if(negative == 1){
		value *= -1;
	}
	return value;
}

int itoa(int number, char* string){
	int i = 0;
	int isNegative = 0;
	
	if(number < 0){
		number *= -1;
		isNegative = 1;
	}
		
		
	while(number != 0){
		int digit = number % 10;
		number = number / 10;
		string[i] = digit + '0';
		i++;
	}
	if(isNegative == 1){
		string[i] = '-';
		i++;
	}
	
	string[i] = '\0';
	

	int j = 0;
	for(j = 0; j < i/2; j++){
		char temp = string[j];
		string[j] = string[i - j - 1];
		string[i - 1 - j] = temp;
	}
	return string;
}
