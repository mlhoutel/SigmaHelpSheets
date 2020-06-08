#include <SFML/Graphics.hpp>

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    // Create a Rectangle shape to display
    sf::RectangleShape rectangle(sf::Vectir2f(120,50)); // Width, Height
    rectangle.setFillColor(sf::Color(150, 50, 250));
    rectangle/setOutlineThickness(10);
    rectangle.setOutlineColor(sf::Color::Red);
    rectangle.setorigin(sf::Vector2f(100, 100));
    rectangle.setPosition(100, 200);
    rectangle.setRotation(30);

    // Create a Circle shape to display
    sf::CircleShape circle(50, 0); // Radius, Number of faces (0=circle, 3=triangle ...)

    // Create a Triangle shape to display
    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(10,10));
    triangle.setPoint(1, sf::Vector2f(20,20));
    triangle.setPoint(2, sf::Vector2f(30,10));


    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
        return EXIT_FAILURE;
    sf::Text text("Text", font, 50);

    // Start display loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
        	// Close window: exit
            if (event.type == sf::Event::KeyPressed)
                system("pause");
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen
        window.clear(sf::Color::Black);

        // Draw the rectangle
        window.draw(rectangle);

        // Draw the circle
        window.draw(circle);

		// Draw the triangle
        window.draw(triangle);

        // Draw the string
        window.draw(text);

        // Update the window
        window.display();

		// Set delay to update
        sleep(milliseconds(10));
    }

}