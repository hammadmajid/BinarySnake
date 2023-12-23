#ifndef SNAKE_H
#define SNAKE_H
#include "SFML/Graphics/RectangleShape.hpp"

inline auto draw_snake(const unsigned int windowWidth, const unsigned int windowHeight) -> sf::RectangleShape {
    sf::RectangleShape snake;

    snake.setSize(sf::Vector2f(20u, 20u));
    const float startX = static_cast<float>(windowWidth) / 2.0f;
    const float startY = static_cast<float>(windowHeight) / 2.0f;
    snake.setPosition(startX, startY);
    snake.setFillColor(sf::Color::Cyan);

    return snake;
}

#endif //SNAKE_H
