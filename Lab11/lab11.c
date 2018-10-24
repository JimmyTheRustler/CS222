#include "lab11.h"
#include <stdio.h>
#include <string.h>

char menu();
void readLine(char buffer[]);
void printContact(const Contact* contact);

Contact* addContact(char* name, char* email, int age, Contact* root);
Contact* findContact(char* name, Contact* root);
void printSortedContacts(Contact* root);
void cleanUp(Contact* root);
void printContact(const Contact* toPrint);

int main()
{	
	char name[NAME_LENGTH];
	char email[EMAIL_LENGTH];
	int age = 0;
	Contact* root = NULL;
	Contact* found = NULL;
	char choice = '\0';	

	do
	{
		choice = menu();
		switch( choice )
		{
			case 'A': 
				printf("\tEnter name: ");
				readLine(name);
				printf("\tEnter e-mail: ");
				readLine(email);
				printf("\tEnter age: ");
				scanf("%d", &age);
				root = addContact(name, email, age, root);
				break;
			case 'F':
				printf("\tEnter name: ");
				readLine(name);
				found = findContact( name, root );
				if( found == NULL )
					printf("\"%s\" not found\n", name);
				else
					printContact( found );
				break;
			case 'P':
				printSortedContacts( root );
				break;
		}	
	} while( choice != 'Q' );
	
	cleanUp( root );
	root = NULL;

	return 0;
}

char menu()
{  
	int choice;  // input

	// print menu  
	printf("A - Add a contact\n");
	printf("F - Find and display a contact\n");
	printf("P - Print contact list\n");
	printf("Q - Quit\n");
	printf("Your choice: ");

	// Get input
	while( isspace(choice = getchar()) );
	while( getchar() != '\n');

	return toupper(choice);
}

void readLine(char buffer[])
{
	int value = 0;
	int index = 0;
	
	value = getchar();
	while( value != '\n' && value != EOF )
	{
		buffer[index++] = value;
		value = getchar();
	}
	
	buffer[index] = '\0';
}

void printContact(const Contact* contact)
{
	printf("\t%s ", contact->name);
	printf("<%s> ", contact->email);
	printf("is %d years old.\n", contact->age);
}

Contact* addContact(char* name, char* email, int age, Contact* root){
	if(root == NULL){
		Contact* node = (Contact*)malloc(sizeof(Contact));
		char* nameCopy = strdup(name);
		char* emailCopy = strdup(email);
		node->name = nameCopy;
		node->email = emailCopy;
		node->age = age;
		root = node;
	}

	else if(strcmp(root->name, name) >= 0){ //left
		root->left = addContact(name, email, age, root->left);
	}
	else if(strcmp(root->name, name) < 0) { //right
		root->right = addContact(name, email, age, root->right);
	}
	return root;
}
Contact* findContact(char* name, Contact* root){
	if(root == NULL)
		return NULL;
	else if(strcmp((root->name), name) == 0){
		return root;
	}
	else if(strcmp((root->name), name) > 0){//left
		return findContact(name, root->left);
	}

	else if(strcmp((root->name), name) < 0){ //right
		return findContact(name, root->right);
	}
	return NULL;
	
}
void printSortedContacts(Contact* root){
	if(root != NULL){
		printSortedContacts(root->left);
		printSortedContacts(root->right);
		printContact(root);
	}
	
}
void cleanUp(Contact* root){
	if(root != NULL){
		cleanUp(root->left);
		cleanUp(root->right);
		free(root);
	}
	free(root);
}
