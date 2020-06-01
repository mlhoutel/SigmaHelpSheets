#include <stdio.h>

// We define the Rectangle structure. 
typedef struct {

	// It contains some of it's Properties like the position (x,y) and the size (height, width)
	float x;
	float y;
	float height;
	float width;

	// Structs are not like Classes, wecannot create functions inside it.

} Rectangle;

// We create a function to calculate the area of a Rectangle
float calcArea(Rectangle r) {
	return r.height * r.width;
}

// We alse create a function to print the properties of the struct, it call the precedent function to compute the area
void toString(Rectangle r) {
	printf("structure: Rectangle\n + Position: [%f, %f]\n + Size: [%f, %f]\n + Area: %f", r.x, r.y, r.height, r.width, calcArea(r));
}

int main() {

	// We instantiate a Rectangle with the name rectangle
	Rectangle rectangle;

	// We edit it's properties
	rectangle.x = 10.0;
	rectangle.y = 2.0;
	rectangle.height = 3.7;
	rectangle.width = 6.5;

	// We call the toString function to see if the properties have changed
	toString(rectangle);
}