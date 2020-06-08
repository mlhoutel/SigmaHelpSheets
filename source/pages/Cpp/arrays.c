#include <stdio.h>

int main()
{
	// We declare an array of 4 integers 
	int numbers[5] = {0, 1, 2, 4, 8};

	// You can also declare arrays like that, the array will have the size of the elements you define
	float prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

	// You can compute it's size like that
	int length = sizeof(numbers) / sizeof(int); // 20 / 4 = 5

	for (int i=0; i<length; i++) {
		printf("%i ", numbers[i]); //display: 0 1 2 4 8
	}

	numbers[0] = 20; // {20, 1, 2, 4, 8}
	numbers[3] = 10; // {20, 1, 2, 10, 8}

	// But the solution with the size calculation is not optimal: it can be a problem when 
	// the array is not declared on the stack but on the heat, a better solution can be :
	
	const int better_length = 10;
	int better_numbers[better_length];

	for(int i=0; i<better_length; i++) {
		better_numbers[i] = i;
	}
}