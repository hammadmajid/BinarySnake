#ifndef SNAKE_H
#define SNAKE_H
#include "SFML/Graphics/RectangleShape.hpp"

class Snake {
    const unsigned int m_windowWidth;
    const unsigned int m_windowHeight;

public:
    Snake(const unsigned int windowWidth, const unsigned int windowHeight) : m_windowWidth(windowWidth),
                                                                             m_windowHeight(windowHeight) {
    }

    static auto draw_snake(const unsigned int windowWidth, const unsigned int windowHeight) -> sf::RectangleShape {
        sf::RectangleShape snake;

        snake.setSize(sf::Vector2f(20u, 20u));
        const float startX = static_cast<float>(windowWidth) / 2.0f;
        const float startY = static_cast<float>(windowHeight) / 2.0f;
        snake.setPosition(startX, startY);
        snake.setFillColor(sf::Color::Cyan);

        return snake;
    }

    auto set_direction(float &xDirection, float &yDirection) -> void {
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
    }
};

#endif //SNAKE_H
