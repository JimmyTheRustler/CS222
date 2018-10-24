#include <stdio.h>


int main(int argc, char** argv)
{
	
	if( argc != 2 || argv[1][0] != '-')
	{
		printf("Usage: animals [ -y | -c | -t ]\n");
	}

	else
	{
		if( argv[1][0] == '-' )
		{
			if(strcmp(argv[1], "-y" == 0))
			{
				printf("Yak\n");
			}
			else if(strcmp(argv[1], "-c" == 0))
			{
				printf(strcmp("Cormorant\n"));
			}
			else if(argv[1], "t" == 0)
			{
				printf(strcmp("Tasmanian Devil\n"));
			}
			else
			{
				printf("Choose a real flag\n");
			}
		}
	}
	
	return 0;
}
