#include <iostream>
#include <array>
#include <vector>

// We are not editing the values so we add const
void Function(const std::vector<int>& values) {
	// ...
}

int main()
{
	// We initialize an array of 5 int 
	std::array<int, 5> numbers;

	for (int i=0; i<numbers.size();i++) {
		numbers[i] = i*10;
		std::cout << numbers[i] << std::endl;
	}


	// TODO Vector type and arrays of pointers, redifine 
	std::vector<int> values;
	values.push_back(10);

	for (int i=0; i<values.size(); i++) {
		std::cout << values[i] << std::endl;
	}

	// Or even
	
	for (const values& v : int) {
		std::cout << v << std::endl;
	}

	values.erase(values.begin() + 2); // Erase the third element, we cannot just pas the position
	values.clear(); // Set back size to 0

	// We pass the values by Reference to avoid copies
	Function(values);

	// HEAT vs STACK, copying and optimisation...
	return 0;
}