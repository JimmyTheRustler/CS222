#include <stdio.h>


int main(){
	char name[80];
	int age;
	int number;

	printf("Enter Name: ");
	scanf("%s", name);
	printf("Enter age: ");
	scanf("%d", &age);
	
	printf("Name:  %s Age: %d" *name, age);
		
	return 0;
}
