#include <stdio.h>

int main() {

	// We define the age variable as an Integer
	int age; 

	// We use printf to output a line of text from a string
	printf("Enter an integer for your age: "); 
	
	// Scanf convert the input variable and put it in age by reference. 
	// It will not stop until scanf detect a non null "string" input.
	scanf("%i", &age); 

	// Then we use printf to output the string with the variable.
	printf("You are %i years old.\nGreat!", age);

	// fflush clean the output buffer, it discards any buffered data that has been fetched from 
	// the underlying output file, but has not been consumed by the application. Thanks to that
	// we are sure to have a clean output the next time we call the function printf.
	fflush(stdin);
}