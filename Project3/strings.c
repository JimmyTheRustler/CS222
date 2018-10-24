#include <stdio.h>
#include "new_string.h"
#include <string.h>

int main(){
	
	
		
	/* String Copy */
	//Ours ~~~~~~~~~~~~~~~~~Not Working
	char src[500*sizeof(int)];
	char dest[500*sizeof(int)];
	new_strcpy(src, "Goon Platoon");
	new_strcpy(dest, src);
	printf("Source: %s\n", src);
	printf("String copy \"Goon Platoon\" = %s\n", dest);
	//String.h
	char srch[500*sizeof(int)];
	char desth[500*sizeof(int)];
	strcpy(srch, "Goon Platoon");
	strcpy(desth, srch);
	printf("String copy string.h \"Goon Platoon\" = %s\n\n", desth);

	/* String Compare */
	//ours
	char str_cmp3[15];
	char str_cmp4[15];
	int ret_cmp2;
	strcpy(str_cmp3, "ab");
	strcpy(str_cmp4, "aB");
	
	ret_cmp2 = new_strcmp(str_cmp3, str_cmp4);
	printf("ret_cmp2: %i\n", ret_cmp2);
	if (ret_cmp2 < 0)
		printf("str3 is less than str4\n");
	else if (ret_cmp2 > 0) 
		printf("str4 is less than str3\n");
	else
		printf("str3 is equal to str4\n");

	//String.h
	char str_cmp1[15];
	char str_cmp2[15];
	int ret_cmp1;
	strcpy(str_cmp1, "ab");
	strcpy(str_cmp2, "aB");

	ret_cmp1 = strcmp(str_cmp1, str_cmp2);
	printf("ret_cmp1: %i\n",ret_cmp1);
	if (ret_cmp1 < 0)
		printf("str1 is less than str2\n\n");
	else if (ret_cmp1 > 0) 
		printf("str2 is less than str1\n\n");
	else
		printf("str1 is equal to str2\n\n");
	
	/* String num Compare */
	
	//ours
	char strncmp3[15];
	char strncmp4[15];
	int retncmp2;
	strcpy(strncmp3, "abcdE");
	strcpy(strncmp4, "abcde");
	
	retncmp2 = new_strncmp(strncmp3, strncmp4, 5);
	printf("retncmp2: %i\n", retncmp2);
	if (retncmp2 < 0)
		printf("str3 is less than str4\n");
	else if (retncmp2 > 0) 
		printf("str4 is less than str3\n");
	else
		printf("str3 is equal to str4\n");

	//string.h
	char strncmp1[15];
	char strncmp2[15];
	int retncmp1;
	strcpy(strncmp1, "abcdE");
	strcpy(strncmp2, "abcde");
	
	retncmp1 = strncmp(strncmp1, strncmp2, 5);
	printf("retncmp1: %i\n", retncmp1);
	if (retncmp1 < 0)
		printf("str1 is less than str2\n\n");
	else if (retncmp1 > 0) 
		printf("str2 is less than str1\n\n");
	else
		printf("str1 is equal to str2\n\n");

	/* String Length */
	//ours
	int newLen = new_strlen("Wangjangle");
	//String.h
	int len = strlen("Wangjangle");
	printf("String Length \"Wangjangle\" = %d\n", newLen);	
	printf("String Length string.h \"Wangjangle\" = %d\n\n", len);

	/* String Cat */

	//ours
	char srcCat1[50], destCat1[50];

   	new_strcpy(srcCat1,  "Machine");
	new_strcpy(destCat1, "Meme");

	new_strcat(destCat1, srcCat1);
	printf("Our destination string : %s\n", destCat1);

	//Theirs
	char srcCat[50], destCat[50];

   	strcpy(srcCat,  "Machine");
	strcpy(destCat, "Meme");

	strcat(destCat, srcCat);
	printf("Theirs destination string : %s\n\n", destCat);
	
	/* String Character */
	//ours
	
	const char str1[] = "Lost in the sauce";
	const char chr1 = 't';
	char *ret1;
	ret1 = new_strchr(str1, chr1);
	printf("String Character \"Lost in the sauce\" at t = %s\n", ret1);
	

	//String.h
	const char str[] = "Lost in the sauce";
	const char chr = 't';
	char *ret;
	ret = strchr(str, chr);
	printf("String Character string.h \"Lost in the sauce\" at t = %s\n\n", ret);
	
	
	
	/* String String */
	
	//ours
	const char hayStack1[4096] = "Hey yo  would ya look at that";
	const char needle1[4096] = "ya";
	char *strstr_ret1;

	strstr_ret1 = new_strstr(hayStack1, needle1);
	printf("Our Substring: %s\n", strstr_ret1);	

		
	//theirs

	const char hayStack[4096] = "Hey would ya look at that";
	const char needle[4096] = "ya";
	char *strstr_ret;

	strstr_ret = strstr(hayStack, needle);
	printf("Their Substring: %s\n", strstr_ret);	
  


	return 0;
}
