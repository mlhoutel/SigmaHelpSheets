#include <stdio.h> 	// NULL
#include <stdlib.h> //srand, rand
#include <time.h> 	// time
#include <math.h>	// pow

int main() {
	
	rand()%100; // Rand integer from 0 to 99

	srand(time(NULL)); // Initialise the random generator with the internal clock as a Seed
	rand()%100; // This one is a more random number (current seed is quite special)

	srand (1); // The random generator's seed is 1 by default, go put it back to see
	rand()%100; // This next random number should be the SAME as the first one
	
	// To have a delimited random number, you can use this:
	int max=112, min=75;
	srand(time(NULL));
	for (int i = 0; i < 10; ++i)
	{
		int random = (rand()%(max-min))+min;
		printf("%i ", random); // (ex: 110 109 98 89 105 94 79 103 93 101)
	}
}