#include <SFML/Graphics.hpp>
#include "grid.h"
#include "snake.h"

int main() {
    constexpr unsigned int windowWidth = 1366u;
    constexpr unsigned int windowHeight = 768u;

    auto window = sf::RenderWindow{{windowWidth, windowHeight}, "Binary Snake"};
    window.setFramerateLimit(20);

    auto grid = Grid::setup_grid(windowWidth, windowHeight);

    Snake snake(windowWidth, windowHeight);
    auto snake_body = snake.draw_snake();

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
        window.draw(snake_body);

        // Move the snake
        Snake::set_direction(xDirection, yDirection);
        snake_body.move(xDirection, yDirection);

        window.display();
    }
}
