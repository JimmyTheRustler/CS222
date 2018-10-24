#include<stdio.h>
#include "lab9.h"
char menu();
void printAllContacts(const ContactList* list);
void getLine(char buffer[]);
void addContact(char* name, char* email, int age, ContactList* list);
Contact* findContact(char* name, const contactList* list);
void printContact(const Contact* toPrint);

int main()
{
	char input;
	char name[NAME_LENGTH];
	char email[EMAIL_LENGTH];
	int age;
	ContactList list;
	Contact* contactPointer = NULL;
	
	list.capacity = 5;
	list.contacts = (Contact*)malloc(list.capacity*sizeof(Contact));
	list.size = 0;
		
	while( (input = menu()) != 'Q' )
	{
		switch( input )			
		{
			case 'A':	//add contact
				printf("\tEnter name: ");
				getLine(name);
				printf("\tEnter e-mail: ");
				getLine(email);
				printf("\tEnter age: ");
				scanf("%d", &age);		
				addContact(name, email, age, &list);
				break;
			case 'F':	//find contact
				printf("\tEnter name: ");
				getLine(name);
				contactPointer = findContact(name, &list);
				if( contactPointer == NULL )
					printf("\t\"%s\" not found\n", name);
				else
					printContact( contactPointer );
				break;			
			case 'P': 	//print all contacts
				printAllContacts(&list);
				break;
		}
	}

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

void printAllContacts(const ContactList* list)
{
	int i = 0;

	if( list->size > 0 )
	{
		// print everything
		for(i = 0; i < list->size; i++)
		{
		  printContact(&list->contacts[i]);
		  printf("\t----------------\n");
		}
	}
	else
		printf("\tContact list is empty!\n");
}

void getLine(char buffer[])
{
	int i = 0;
	char c;
	while( (c = getchar()) != '\n' && c != EOF )
		buffer[i++] = c;
	buffer[i] = '\0';
}

void addContact(char* name, char* email, int age, ContactList* list){
	if(size == capacity){
		ContactList.capacity = ContactList.capacity * 2;
		ContactList.contacts = (Contact*)realloc(ContactList.contacts, ContactList.capacity);
	}
	list -> Contact.name = name;
	list -> Contact.email = email;
	list -> Contact.age = age;
	ContactList.size++;
}
Contact* findContact(char* name, const ContactList* list){
	while(list != NULL){
		if(name == list.Contact.name)
			printf("%s <%s> is %d years old.", list.Contact.name, list.Contact.email, list.Contact.age);
			return;
		list = list -> next;
	}
	return NULL;
}
void printContact(const Contact* toPrint){
	while(toPrint != NULL){
		printf("%s <%s> is %d years old.", toPrint.Contact.name, toPrint.Contact.email, toPrint.Contact.age);
		println("----------------");
		toPrint = toPrint -> next;
	}	
}
