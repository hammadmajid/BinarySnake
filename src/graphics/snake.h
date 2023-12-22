//
// Created by hammad on 12/22/23.
//

#ifndef SNAKE_H
#define SNAKE_H
#include "SFML/Graphics/RectangleShape.hpp"

inline auto draw_snake() -> sf::RectangleShape {
    sf::RectangleShape snake;

    snake.setSize(sf::Vector2f(20u, 20u));
    snake.setPosition(20, 20);
    snake.setFillColor(sf::Color::Cyan);

    return snake;
}

#endif //SNAKE_H
