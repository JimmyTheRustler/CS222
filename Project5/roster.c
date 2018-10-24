#include <stdio.h>

void help();
int main(){
	help();
	return 0;
}

void help(){
	printf("1. Help:\n");
	printf("	Displays all of the commands and gives a short description about each one.\n\n");
	
	printf("2. Load:\n");
	printf("	Adds all the student records from a given file to the roster. Takes a file name argument.\n\n");
	
	printf("3. Save:\n");
	printf("	Save the records of all living students in the roster to a file. Format is identical to the file that was read into the program. Takes a file name argument\n\n");
	
	printf("4. Clear:\n");
	printf("	Clear the rosters for the four houses and for the list of deceased student.\n\n");
	
	printf("5. InOrder:\n");
	printf("	Prints out each house in an inOrder traversal.\n\n");

	printf("6. PreOrder:\n");
	printf("	Prints out each house in an preOrder traversal.\n\n");

	printf("7. PostOrder:\n");
	printf("	Prints out each house in an postOrder traversal.\n\n");

	printf("8. Add:\n");
	printf("	Add's a student with the given attributes to the roster. Takes first name, last name, points, year, and house as arguments.\n\n");

	printf("9. Kill:\n");
	printf("	Find the given student in the given house's roster, remove that student from the roster, and will add the students name to the deceased roster. Takes first name, last name, and house arguments.\n\n");

	printf("10. Find:\n");
	printf("	Will find a given student in the given houses roster and will print out their data. Takes first name, last name, and house arguments.\n\n");

	printf("11. Points:\n");
	printf("	Find the given student in the given house's roster and add a specified amount of points to their point total. Can add negative numbers as well. Takes a first name, last name, house, and number arguments.\n\n");

	printf("12. Score:\n");
	printf("	Prints out the current point scores for all houses. Points from deceased students are not factored in.\n\n");

	printf("13. Quit:\n");
	printf("	Quits the program.\n\n");

}



