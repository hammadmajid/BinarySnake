#include <SFML/Graphics.hpp>
#include "graphics/grid.h"
#include "graphics/snake.h"

int main() {
    constexpr unsigned int windowWidth = 1366u;
    constexpr unsigned int windowHeight = 768u;

    auto window = sf::RenderWindow{{windowWidth, windowHeight}, "Binary Snake"};
    window.setFramerateLimit(20);

    // Create a 2D array to represent the grid
   auto grid = setup_grid(windowWidth, windowHeight);

    // Create the snake's body
    auto snake = draw_snake(windowWidth, windowHeight);

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

        window.display();
    }
}
