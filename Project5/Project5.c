#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Student.h"

Student* add(Student* root, Student* node);
Student* search( Student* root, char* first, char* last);
Student* delete(Student* root, char* first, char* last);
Student* smallest(Student* node, Student* parent);
char* fullName(char* first, char* last);
void inOrder(Student* root);
void preOrder(Student* root);
void postOrder(Student* root);
void printRoster(FILE* output, Student* root);
void help();
int score(Student* root, int score);
void clear(Student* root);



int main(){
	Student* houses[5];
	int i;
	for(i = 0; i < 5; i++)
		houses[i] = NULL;
	char input[100];
	
	do{	
		printf("Enter Command: ");
		scanf("%s", input);
		//Help Command
		if( strcmp(input, "help")  == 0 ){
			help();
		}
		//Load Command
		else if( strcmp(input, "load") == 0 ){
			
			char inputFile[100];
			scanf("%s", inputFile);
			
			FILE *file;
		
			if(file = fopen(inputFile, "r")){
					
				int done = 0;
				while(!done){
					char firstname[50];
					char lastname[50];
					char house[50];
					int year, points;
					
					int read = fscanf(file, "%s %s %d %d %s", firstname, lastname, &points, &year, house);
					if(read == 5){
						Student* current = (Student*)malloc(sizeof(Student));
						current->left = NULL;
						current->right = NULL;
						current->first = strdup(firstname);
						current->last = strdup(lastname);
						current->year = year;
						current->points = points;
						int i;
						for(i = 0; i < 4; i++)
							if(strcmp(house, HOUSE_NAMES[i]) == 0){
								current->house = i;
								houses[i] = add(houses[i], current);
							}
					}
					else
						done = 1;
				}
				fclose(file);
				printf("Successfully loaded data from file %s\n", inputFile);
			}
			else{
				printf("Load failed. Invalid file: %s\n", inputFile);
			}
			
		}
		//Save Command
		else if( strcmp(input, "save") == 0 ){
			char outputFile[100];
			scanf("%s", outputFile);	
	
			FILE* output;
			if(output = fopen(outputFile, "w")){
				printRoster(output, houses[0]);
				printRoster(output, houses[1]);
				printRoster(output, houses[2]);
				printRoster(output, houses[3]);
				fclose(output);
				printf("Successfully saved data to file %s\n", outputFile);
			}
			else{
				printf("Save failed. Invalid file: %s\n", outputFile);
			}
		}
		//Clear Command
		else if( strcmp(input, "clear") == 0 ){	
			clear(houses[0]);
			clear(houses[1]);
			clear(houses[2]);
			clear(houses[3]);
			clear(houses[4]);
			
			houses[0] = NULL;
		 	houses[1] = NULL;
		 	houses[2] = NULL;
		 	houses[3] = NULL;
		 	houses[4] = NULL;
			printf("All data cleared.\n");
		}
		//In-Order Command
		else if( strcmp(input, "inorder") == 0 ){
			printf("Gryffindor House\n\n");
			inOrder(houses[0]);
			printf("\n");
			printf("Ravenclaw House\n\n");
			inOrder(houses[1]);
			printf("\n");
			printf("Hufflepuff House\n\n");
			inOrder(houses[2]);
			printf("\n");
			printf("Slytherin House\n\n");
			inOrder(houses[3]);
			printf("\n");
			printf("Deceased House\n\n");
			inOrder(houses[4]);
			printf("\n");
		}
		//Pre-Order Command
		else if( strcmp(input, "preorder") == 0 ){
			printf("Gryffindor House\n\n");
			preOrder(houses[0]);
			printf("\n");
			printf("Ravenclaw House\n\n");
			preOrder(houses[1]);
			printf("\n");
			printf("Hufflepuff House\n\n");
			preOrder(houses[2]);
			printf("\n");
			printf("Slytherin House\n\n");
			preOrder(houses[3]);
			printf("\n");
			printf("Deceased House\n\n");
			preOrder(houses[4]);
			printf("\n");
		}
		//Post-Order Command
		else if( strcmp(input, "postorder") == 0 ){
			printf("Gryffindor House\n\n");
			postOrder(houses[0]);
			printf("\n");
			printf("Ravenclaw House\n\n");
			postOrder(houses[1]);
			printf("\n");
			printf("Hufflepuff House\n\n");
			postOrder(houses[2]);
			printf("\n");
			printf("Slytherin House\n\n");
			postOrder(houses[3]);
			printf("\n");
			printf("Deceased House\n\n");
			postOrder(houses[4]);
			printf("\n");
		}
		//Add Command
		else if( strcmp(input, "add") == 0 ){
			char house[50];
			char first[50];
			char last[50];
			int year;
			int points;
			
			Student* student = (Student*)malloc(sizeof(Student));
			scanf("%s %s %d %d %s", first, last, &points, &year, house);
			student->left = NULL;
			student->right = NULL;
			student->first = strdup(first);
			student->last = strdup(last);
			student->year = year;
			student->points = points;
			if(year > 7 || year < 1){
				printf("Add failed. Invalid year: %d\n", year);
			}
			
			else{	
				int i;
				for(i = 0; i < 4; i++){
					if(strcmp(house, HOUSE_NAMES[i]) == 0){
						student->house = i;
						houses[i] = add(houses[i], student);
						printf("Added %s %s to roster.\n", first, last);
					}
					else if(i == 4)
						printf("Add failed.  Invalid house: %s\n", house);
				}
			}
		}
		//Kill Command
		else if( strcmp(input, "kill") == 0 ){
			char house[50];
			char first[50];
			char last[50];
			
			scanf("%s %s %s", first, last, house);
			Student* found;
			
			for(i = 0; i < 4; i++){
				if(strcmp(house, HOUSE_NAMES[i]) == 0)
					found = search(houses[i], first, last);
				else if(i == 3)
					printf("Kill failed.  Invalid house: %s\n", house);
			}
			
			if(found == NULL){
				printf("Kill failed. %s %s was not found in %s House\n", first, last, house);
			}
			else{
				Student* toKill = (Student*)malloc(sizeof(Student));
				toKill->first = found->first;
				toKill->last = found->last;
				toKill->left = NULL;
				toKill->right = NULL;
				toKill->points = found->points;
				toKill->year = found->year;
				
				houses[4] = add(houses[4], toKill);
				for(i = 0; i < 4; i++){
					if(strcmp(house, HOUSE_NAMES[i]) == 0){
						houses[i] = delete(houses[i], found->first, found->last);
						toKill->house = i;
					}
						
				}
				printf("Moved %s %s to list of deceased students.\n", first, last);
			}
		}
		//Find Command
		else if( strcmp(input, "find") == 0 ){
			char house[50];
			char first[50];
			char last[50];
			int valid = 1;
			
			scanf("%s %s %s", first, last, house);
			Student* found = NULL;
			
			for(i = 0; i < 4; i++){
				if(strcmp(house, HOUSE_NAMES[i]) == 0)
					found = search(houses[i], first, last);
				else if(i == 3){
					printf("Kill failed.  Invalid house: %s\n", house);
					valid = 0;
				}	
			}
				
			if(found != NULL){
				char* namey = fullName(found->first, found->last);
				printf("%-25s \t Points: %d\t Year: %d\t House: %s\n", namey, found->points, found->year, HOUSE_NAMES[found->house]);
			}
			else if(valid)
				printf("Find failed.  %s %s was not found in %s House\n", first, last, house);
			
		}
		//Points Command
		else if( strcmp(input, "points") == 0 ){
			char house[50];
			char first[50];
			char last[50];
			int number;			
			
			scanf("%s %s %s %d", first, last, house, &number);
			Student* found;
			
			for(i = 0; i < 4; i++){
				if(strcmp(house, HOUSE_NAMES[i]) == 0)
					found = search(houses[i], first, last);
				else if(i == 3)
					printf("Point change failed.  Invalid house: %s\n", house);
			}
		
			
			if(found == NULL){
				printf("Point change failed. %s %s was not found in %s House\n", first, last, house);
			}
			else{
				found->points += number;
				printf("Points for %s %s changed to %d.\n", first, last, found->points);
			}
			
			
		}
		//Score Command
		else if( strcmp(input, "score") == 0 ){
			printf("Point totals: \n\n");
			printf("Gryffindor: %d\n", score(houses[0], 0));
			printf("Ravenclaw: %d\n", score(houses[1], 0));
			printf("Hufflepuff: %d\n", score(houses[2], 0));
			printf("Slytherin: %d\n", score(houses[3], 0));
		}
		//Quit Command
		else if( strcmp(input, "quit") == 0 ){
			printf("All data cleared\n");
			clear(houses[0]);
			clear(houses[1]);
			clear(houses[2]);
			clear(houses[3]);

			houses[0] = NULL;
		 	houses[1] = NULL;
		 	houses[2] = NULL;
		 	houses[3] = NULL;
		 	houses[4] = NULL;
		}
		else{
			printf("Unknown command: %s\n", input);	
		}		
	}while( strcmp(input, "quit") );

	return 0;
}

Student* add(Student* root, Student* node){
	if(root == NULL)
		return node;
	else if(strcmp(node->last, root->last) < 0)
		root->left = add(root->left, node);
	else if(strcmp(node->last, root->last) > 0)
		root->right = add(root->right, node);
	else if (strcmp(node->last, root->last) == 0){
		if(strcmp(node->first, root->first) < 0)
			root->left = add(root->left, node);
		else if(strcmp(node->first, root->first) > 0)
			root->right = add(root->right, node);
	}
		
	return root;
}


Student* delete(Student* root, char* first, char* last){
	if(root == NULL)
		return NULL;
	else if(strcmp(last, root->last) < 0)
		root->left = delete(root->left, first, last);
	else if(strcmp(last, root->last) > 0)
		root->right = delete(root->right, first, last);
	else{		//Last names equal
		if(strcmp(first, root->first) < 0)
			root->left = delete(root->left, first, last);
		else if(strcmp(first, root->first) > 0)
			root->right = delete(root->right,  first, last);
		else{		//First names equal.  Deleting root
			if(root->left == NULL)		//No left child
				return root->right;
			else if(root->right == NULL)		//No right child
				return root->left;
			else{
				Student* temp = smallest(root->right, root);
				temp->left = root->left;
				temp->right = root->right;
				*root = *temp;
			}
		}
	}
	
	return root;
}

Student* smallest(Student* node, Student* parent){
	if(node->left != NULL)
		return smallest(node->left, node);
	else if(parent->left == node)
		parent->left = node->right;
	else
		parent->right = node->right;
		
	return node;
}

Student* search( Student* root, char* first, char* last){
	if(root == NULL)
		return NULL;
	else if(strcmp(last, root->last) < 0)
		return search(root->left, first, last);
	else if(strcmp(last, root->last) > 0)
		return search(root->right, first, last);
	else if (strcmp(last, root->last) == 0){
		if(strcmp(first, root->first) < 0)
			return search(root->left, first, last);
		else if(strcmp(first, root->first) > 0)
			return search(root->right, first, last);
		else
			return root;
	}
}

void printRoster(FILE* output, Student* root){
	if(root != NULL){
		fprintf(output, "%s %s %d %d %s\n", root->first, root->last, root->points, root->year, HOUSE_NAMES[root->house]);
		printRoster(output, root->left);
		printRoster(output, root->right);
	}
}

char* fullName(char* first, char* last){
	char* name = strdup(first);
	name = strcat(name, " ");
	name = strcat(name, last);
	
	return name;
}

void inOrder(Student* root){
	if(root != NULL){
		inOrder(root->left);
		char* name = fullName(root->first, root->last);
		printf("%-25s \t Points: %d\t Year: %d\t House: %s\n", name, root->points, root->year, HOUSE_NAMES[root->house]);
		free(name);
		inOrder(root->right);
	}
}

void preOrder(Student* root){
	if(root != NULL){
		char* name = fullName(root->first, root->last);
		printf("%-25s \t Points: %d\t Year: %d\t House: %s\n", name, root->points, root->year, HOUSE_NAMES[root->house]);
		free(name);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void postOrder(Student* root){
	if(root != NULL){
		postOrder(root->left);
		postOrder(root->right);
		char* name = fullName(root->first, root->last);
		printf("%-25s \t Points: %d\t Year: %d\t House: %s\n", name, root->points, root->year, HOUSE_NAMES[root->house]);
		free(name);
	}
}

void help(){
	FILE* helpFile = fopen("help.txt", "r");
	char c = fgetc(helpFile);
	while(c != EOF){
		printf ("%c", c);
		c = fgetc(helpFile);
 	}
	fclose(helpFile);
}

int score(Student* root, int wizardScore){
	if(root != NULL){
		wizardScore += root->points;
		score(root->left, wizardScore);
		score(root->right, wizardScore);
	}
	return wizardScore;	
}

void clear(Student* root){
	if(root != NULL){
		clear(root->left);
		clear(root->right);
		free(root->first);
		free(root->last);
		free(root);
	}
}
