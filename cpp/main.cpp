#include <SFML/Graphics.hpp>

int main() {
    // Create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Square Movement");

    // Create a square
    sf::RectangleShape square(sf::Vector2f(50.f, 50.f));
    square.setFillColor(sf::Color::Green);
    square.setPosition(375.f, 275.f); // Start near center

    float speed = 200.f; // pixels per second
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Delta time for smooth movement
        float deltaTime = clock.restart().asSeconds();

        // Movement
        sf::Vector2f pos = square.getPosition();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            pos.y -= speed * deltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            pos.y += speed * deltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            pos.x -= speed * deltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            pos.x += speed * deltaTime;

        // Keep square inside window
        if (pos.x < 0) pos.x = 0;
        if (pos.y < 0) pos.y = 0;
        if (pos.x > 800 - square.getSize().x) pos.x = 800 - square.getSize().x;
        if (pos.y > 600 - square.getSize().y) pos.y = 600 - square.getSize().y;

        square.setPosition(pos);

        // Clear, draw, and display
        window.clear();
        window.draw(square);
        window.display();
    }

    return 0;
}
