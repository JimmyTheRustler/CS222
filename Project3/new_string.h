char* new_strcpy(char* destination, const char* source);
char* new_strncpy(char* destiantion, const char* source, size_t n);
int new_strcmp(const char* string1, const char *string2);
int new_strncmp(const char* string1, const char* string2, size_t n);
char* new_strcat(char* destination, const char* source);
char* new_strncat(char* destination, const char* source, size_t n);
size_t new_strlen(const char* string);
char* new_strchr(const char* string, int character);
char* new_strstr(const char* haystack, const char* needle);

char* new_strcpy(char* destination, const char* source){
	size_t i;
 
	for(i=0;source[i] != '\0';i++)
		destination[i] = source[i];
  	return destination;
	  
}

char* new_strncpy(char* destination, const char* source, size_t n){
	size_t i;

	for(i=0; i < n && source[i] != '\0';i++)
		destination[i] = source[i];
	for(i=0;i<n;i++)
		destination[i] = source[i];

	return destination;
}

int new_strcmp(const char* string1, const char* string2){
	int i = 0;
	int sum = 0;
	
	while(string1[i] != '\0' && string2[i] != '\0'){
		sum = string1[i] - string2[i];
		if(sum != 0)
			return sum;
		i++;
	}
	return sum;

}

int new_strncmp(const char* string1, const char* string2, size_t n){
	int i;
	int sum;
	sum = 0;
	
	for(i = 0; i < n; i++){
		sum = string1[i] - string2[i];
		if(sum != 0)
			return sum;
	}
	return sum;

}

char* new_strcat(char* destination, const char* source){
	int i=0, size = new_strlen(destination);
  
	for(i=0;source[i]!='\0';i++)
		destination[size+i] = source[i];
	return destination;
}

char* new_strncat(char* destination, const char* source, size_t n){
	int i, size = new_strlen(destination);

	for(i=0;i<n;i++)
		if(source[i] != '\0')
			destination[size+i] = source[i];

	return destination;
}	

size_t new_strlen(const char* string){
	int i = 0;
	while(string[i] != '\0')
		i++;
	return i;
}

char* new_strchr(const char* string, int character){
	char tempString[new_strlen(string)];
	char *ret;
	int i = 0;
	int j = 0;
	int found = 0;	
	
	while(string[i] != character && string[i] != '\0')
		i++;
	while(string[i] != '\0'){
		found = 1;
		tempString[j] = string[i];
		i++;
		j++;	
	}
	
	if(found == 0)
		return NULL;
	else{
		new_strcpy(ret, tempString);
		return ret;
	}	
}

char* new_strstr(const char* haystack, const char* needle){
	
	int needleLength = new_strlen(needle);
	char tempString[new_strlen(haystack)];
	int hayLen = new_strlen(haystack);
	char* ret;
	int i = 0;
	int tempi;
	int j = 0;
	int k = 0;
	int found = 0;
	
	printf("Init String: %s\n", haystack);
	printf("needleLength: %d\n", needleLength);
	
	while(found != 1 && haystack[i] != '\0'){
		if(haystack[i] == needle[j]){
			tempi = i;
			while(j < needleLength && haystack[tempi] == needle[j]){
				if(j == needleLength - 1)
					found += 1;
				tempi++;
				j++;
			}
		}
		j = 0;
		i++;
	}
	i--;
	
	if(found == 1)
		return &haystack[i];
	else
		return NULL;
}
