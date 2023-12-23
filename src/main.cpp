#include <SFML/Graphics.hpp>
#include "grid.h"
#include "snake.h"

int main() {
    constexpr unsigned int windowWidth = 1366u;
    constexpr unsigned int windowHeight = 768u;

    auto window = sf::RenderWindow{{windowWidth, windowHeight}, "Binary Snake"};
    window.setFramerateLimit(20);

    // Create a 2D array to represent the grid
   auto grid = setup_grid(windowWidth, windowHeight);

    // Create the snake's body
    auto snake = draw_snake(windowWidth, windowHeight);

    // Directions for the snake
    float xDirection = 0.0f;
    float yDirection = 0.0f;

    while (window.isOpen()) {
        for (auto event = sf::Event{}; window.pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();

        // Draw the grid
        for (const auto&row: grid) {
            for (const auto&cell: row) {
                window.draw(cell);
            }
        }

        // Draw the snake
        window.draw(snake);

        // Move the snake
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) { // Up
            yDirection = 20.0f;
            xDirection = 0.0f;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::K)) { // Down
            yDirection = -20.0f;
            xDirection = 0.0f;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::L)) { // Right
            xDirection = 20.0f;
            yDirection = 0.0f;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::H)) { // Left
            xDirection = -20.0f;
            yDirection = 0.0f;
        }

        snake.move(xDirection, yDirection);

        window.display();
    }
}
