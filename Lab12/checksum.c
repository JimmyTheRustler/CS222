#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main( int argc, char *argv[] ){
	
	char* fileName = argv[1];
	char buffer;
	int sum;
	int place = 1;
	int bytes = 0;
	unsigned int total = 0;
	int i = 0;
	int r = 0;
	int s = 0;
	int blockNum = 0;
	unsigned int twoShift = 2 << 15;
	
	int file = open(fileName, O_RDONLY);
	
	while(place == 1){
		place = read(file, &buffer, sizeof(char));	
		if (place == 1 ){
			sum += (unsigned int)buffer;
			bytes++;
		}
	}

	r = (sum % (2 << 15)) + (sum / (2 << 15));
	s = (r % (2 << 15)) + (r / (2 << 15));

	blockNum = bytes / 512;

	if(bytes % 512 != 0)
		blockNum++;
	
	printf("%d %d %s\n", s, blockNum, fileName);
	
	return 0;
}
