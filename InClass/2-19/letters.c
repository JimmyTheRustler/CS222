#include <stdio.h>
#include <string.h>

void makeLower(char* letter);

int main(){

	char thing = 'P';
	char word[] = "Emacs is great, Mighty Joe Young!";
	int length = strlen(thing);
	int i;

	for(i = 0; i < length; i++){
    		makeLower(&thing[i]);
  	}

	printf("Thing before: %s\n", thing);

	makeLower( &thing );
	printf("Thing after: %s\n", thing);


	return 0;
}

void makeLower(char* letter){
	if( *letter >= 'A' && *letter <= 'Z' ){
		*letter += 'a' - 'A';
  	}
}
