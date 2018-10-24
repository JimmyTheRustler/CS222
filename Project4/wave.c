#include <stdio.h>
#include <stdlib.h>
#include "wave.h"
#include <limits.h>

/*
Names: Malcolm Sykes, James O'Brien
Date: 3-23-18
Class: CS222
Project Name: Wave Goodbye
File Names: wave.c wave.h makefile
*/


/* Prototyping */
int readHeader( WaveHeader* header );
int writeHeader( const WaveHeader* header );
int input(short* left, short* right, int size);
short getShort();
short putShort(short channel);
void reverse(short* left, short* right, int size);
void flip(short* left, short* right, int size);
void volume(short* left, short* right, int size, float volModifyer);
short* changeSpeed(short* channel, int size, double speed);
void fadeOut(short* left, short* right, int size, double length);
void fadeIn(short* left, short* right, int size, double length);
float argToFloat(int p, char *argv[]);
short* echo(short* channel, int size, float scale, float delay);

int main( int argc, char *argv[] ){ //argc == # of arguments   argv == points to each argument of the program
	WaveHeader header; //init header
	readHeader(&header); //reads in header
	short* leftChannel = (short*)malloc(sizeof(short) * (header.dataChunk.size / 2));  //makes left channel short array
	short* rightChannel = (short*)malloc(sizeof(short) * (header.dataChunk.size / 2));  //makes right channel short array
	int totalSize = header.dataChunk.size;	//makes a size variable
	int channelSize = totalSize/4;
	int headerSize = header.size - header.dataChunk.size;
	short* flipTemp;
	input(leftChannel, rightChannel, channelSize);	 //writes .wav data to right and left channels
	int p = 0;

	if(header.ID[0] != 'R' && header.ID[1] != 'I' && header.ID[2] != 'F' && header.ID[3] != 'F'){ //if the file is not a RIFF file, exit the program
		fprintf(stderr, "File is not a RIFF file");
		return 0;
	}
	
	if(header.formatChunk.ID[0] != 'f' && header.formatChunk.ID[1] != 'm' && header.formatChunk.ID[2] != 't' || header.formatChunk.bitsPerSample != 16|| header.formatChunk.compression != 1){ //if the format chunk is incorrect, exit the program
		fprintf(stderr, "Format chunk is corrupted");
		return 0;
	}
	
	if(header.dataChunk.ID[0] != 'd' && header.dataChunk.ID[1] != 'a' && header.dataChunk.ID[2] != 't' && header.dataChunk.ID[3] != 'a'){ //if the format chunk is not properly defined
		fprintf(stderr, "Format chunk is corrupted");
		return 0;
	}
	
	if(header.formatChunk.channels != 2){//if there are not two channels
		fprintf(stderr, "File is not stereo");
		return 0;
	}
	
	if(header.formatChunk.sampleRate != 44100){//if the sample reat is not 44100 samples per second
		fprintf(stderr, "File does not use 44,100Hz sample rate");
		return 0;
	}
	
	if(header.formatChunk.bitsPerSample != 16){ //if the samples are not 16 bits
		fprintf(stderr, "File does not have 16-bit samples");
		return 0;
	}
	if(leftChannel == NULL || rightChannel == NULL){ //if malloc failed and returned NULL
	fprintf(stderr, "Program out of memory");
	return 0;
	}
	
	while(p+1 < argc){
		if(argv[p+1][0] == '-'){
			switch(argv[p+1][1]){
				case 'r': //reverse
					reverse(leftChannel, rightChannel, channelSize);
				break;
				case 's': //Change speed
					if( atof(argv[p+2]) <= 0 ){
						fprintf(stderr, "A positive number must be supplied for the speed change.");
						return 0;
					}
					header.dataChunk.size = header.dataChunk.size /  atof(argv[p+2]);
					header.size = header.dataChunk.size + headerSize;
					leftChannel = changeSpeed(leftChannel, channelSize, atof(argv[p+2]));
					rightChannel = changeSpeed(rightChannel, channelSize, atof(argv[p+2]));
				break;
				case 'f': //Flip
					flipTemp = leftChannel;
					leftChannel = rightChannel;
					rightChannel = flipTemp;
				break;
				case 'o': //Fade out
					if( atof(argv[p+2]) <= 0 ){
						fprintf(stderr, "A positive number must be supplied for the fade out time.");
						return 0;
					}
					fadeOut(leftChannel, rightChannel, channelSize, atof(argv[p+2]));
				break;
				case 'i': //Fade in
					if( atof(argv[p+2]) <= 0 ){
						fprintf(stderr, "A positive number must be supplied for the fade in time.");
						return 0;
					}
					fadeIn(leftChannel, rightChannel, channelSize, atof(argv[p+2]));	
				break;
				case 'v': //volume
					if( atof(argv[p+2]) <= 0 ){
						fprintf(stderr, "A positive number must be supplied for the volume scale.");
						return 0;
					}
					volume(leftChannel, rightChannel, channelSize, atof(argv[p+2]));
				break;
				case 'e': //Echo
					if( atof(argv[p+2]) <= 0 || atof(argv[p+3]) <=0 ){
						fprintf(stderr, "A positive number must be supplied for the echo delay and the scale parameters.");
						return 0;
					}
					header.dataChunk.size = header.dataChunk.size + ((44100 * atof(argv[p+3])) * 4);
					header.size = header.dataChunk.size + headerSize;
					leftChannel = echo(leftChannel, channelSize, atof(argv[p+2]), atof(argv[p+3]));
					rightChannel = echo(rightChannel, channelSize, atof(argv[p+2]), atof(argv[p+3]));
				break;
				
			}
		}
		p++;
	}
	
	//writes header for file
	writeHeader(&header);
	int i = 0;
	//for loop that writes out left and right channels to a file
	for(i = 0; i < header.dataChunk.size / 4; i++){
		putShort(leftChannel[i]);
		putShort(rightChannel[i]);
	}
	
	
	return 0;
}

//reads in file header
int readHeader( WaveHeader* header )
{	
	if( fread( header, sizeof( WaveHeader ), 1, stdin) != 1 )
		return 0;	
		
	return 1;	
}

//writes out file header
int writeHeader( const WaveHeader* header )
{	
	if( fwrite( header, sizeof( WaveHeader ), 1, stdout) != 1 )			
		return 0;	
		
	return 1;	
}

short putShort(short channel){
	//first putchar's first half a short
	putchar(channel & 0xFF);
	//putchars the second half of the short
	putchar(channel >> 8);
}

short getShort(){
	short a = getchar();
	short b = getchar();
	//combines two characters to make 1 short as .wav sound data is stored as shorts.
	short c = (((short)b) << 8) | a;
	return c;
}
int input(short* left, short* right, int size){
	int i = 0;
	//forLoop that calls getShort() to populate both left and right channel short arrays
	for(i = 0; i < size; i++){
		left[i] = getShort();
		right[i] = getShort();
	}
}
void reverse(short* left, short* right, int size){
	short temp = 0;
	int i = 0;
	for(i = 0; i < size/2; i++){ 
		//reverse left channel
		temp = left[i];
		left[i] = left[ ( size )-i-1 ];	
		left[ ( size )-i-1 ] = temp;
		//reverses right channel
		temp = right[i];
		right[i] = right[ ( size )-i-1 ];
		right[ ( size )-i-1 ] = temp;
	}
}
void flip(short* left, short* right, int size){
	short* temp = (short*)malloc(sizeof(short) * (size));
	int i = 0;
	//copys left channel to temp array
	for(i = 0; i < size; i++){
		temp[i] = left[i];
	//over-writes left channel with right channel
		left[i] = right[i];
	//over-writes right channel with temp left channel
		right[i] = temp[i];
	}
	//free's temp channel array
	free(temp);
}

void volume(short* left, short* right, int size, float volModifyer){
	int i = 0;
	int temp;
	
	//sets left channel volume
	for(i = 0; i < size; i++){
		temp = left[i] * volModifyer * volModifyer;
		//if-else statements to keep volume inside of the range of short min and max
		if(temp <= SHRT_MAX && temp >= SHRT_MIN)
			left[i] = temp;
		else if(temp > SHRT_MAX)
			left[i] = SHRT_MAX;
		else if(temp < SHRT_MIN)
			left[i] = SHRT_MIN;
	}
	
	//sets right channel volume	
	for(i = 0; i < size; i++){
		temp = right[i] * volModifyer * volModifyer;
		//if-else statements to keep volume inside of the range of short min and max
		if(temp <= SHRT_MAX && temp >= SHRT_MIN)
			right[i] = temp;
		else if(temp > SHRT_MAX)
			right[i] = SHRT_MAX;
		else if(temp < SHRT_MIN)
			right[i] = SHRT_MIN;

	}
}

short* changeSpeed(short* channel, int size, double speed){
	//make new channel appropriately sized for how long or short the audio file is now
	short* newChannel = (short*)malloc(sizeof(short) * (int)(size / speed));
	int i; 
	//forLoop that fills newChannel with the original channel's info modified by the speed
	for(i = 0; i < (int)(size / speed); i++)
		newChannel[i] = channel[(int)(i * speed)];
	//free's old channel not in use
	free(channel);	
	return newChannel;
}

void fadeOut(short* left, short* right, int size, double length){
	int fadeSize = 44100*length;
	int i;
	double j = 0.0;
	int maxFadeSize = size - fadeSize;
	
	if(fadeSize > size){
		maxFadeSize = 0;
	}
	//forLoop to fade out the audio file quadraticly
	for(i = maxFadeSize ; i < size; i++){
		left[i] *= (1.0 - (j / fadeSize)) * (1.0 - (j / fadeSize));
		right[i] *= (1.0 - (j / fadeSize)) * (1.0 - (j / fadeSize));
		j += 1.0;
	} 
}

void fadeIn(short* left, short* right, int size, double length){
	int fadeSize = 44100*length;	

	int i;
	if(fadeSize > size)
		fadeSize = size;
	//forLoop to fade in the audio file quadraticly
	for(i = 0; i < fadeSize; i++){
        	left[i] *= (i/(double)(fadeSize)) * (i/(double)(fadeSize));
        	right[i] *= (i/(double)(fadeSize)) * (i/(double)(fadeSize));
    	}
}
short* echo(short* channel, int size, float scale, float delay){
	int i = 0;
	int j = 0;
	int echoSize = delay * 44100;
	short* echoChannel = (short*)malloc(sizeof(short) * (int)(size + echoSize));
	//write main channel to new echo channel
	for(i = 0; i < size; i++){
		echoChannel[i] = channel[i];
	}
	//add echo to the echo channel	
	for(i = echoSize; i < size + echoSize; i++){
		echoChannel[i] = echoChannel[i] + (channel[j] * scale);
		j++;
	}
	free(channel);
	return echoChannel;
}
