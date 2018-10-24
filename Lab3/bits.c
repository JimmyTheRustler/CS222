#include <stdio.h>

/**
 * Function: 	readInt
 * Returns: 	an int, read from standard input. 
 **/
int readInt()
{
	int c = 0;
	int i = 0;
  
	while( (c = getchar()) != EOF && c != '\n' )
	{
		if( c >= '0' && c <= '9')	
			i = i * 10 + (c - '0');	
	}

	return i;
}
// main function
int main()
{
	int value = 0;
	int newVal;
	printf("Please enter a numerical value: ");
	value = readInt();

	int bitMod;	/* which bit to modify */
	int bitSet;	/* what to set a bit to */
	char input;	/* user option selection */

	
	printf("Do you want to set, unset, or flip a bit? (s, u, f):");
	input = getchar();

	readInt();
	printf("Which bit? (0-31)");
	bitMod = readInt();
	
	if(input == 's'){/* Setting a bit to 1*/ 
		bitSet = (1 << bitMod);
		newVal = (bitSet | value);
		
		printf("The result of thesetting but %i in %i is %i \n", bitMod, value, newVal);
	}
	else if (input == 'u'){ /* Unsetting a bit */
		bitSet = (1 << bitMod);
		/* need a bitwise not ~ */
		newVal = (value & (~bitSet));
		printf("The result of the unsetting %i in %i is %i \n", bitMod, value, newVal);	
	}
	else{/* Flipping a bit */ 
		bitSet = (1 << bitMod);
		newVal = (bitSet ^ value);
		printf("The result of the flipping %i in %i is %i \n", bitMod, value, newVal);	
	}
	
	return 0;
}

