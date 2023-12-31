#ifndef GRID_H
#define GRID_H

#include <vector>
#include "SFML/Graphics/RectangleShape.hpp"

inline auto setup_grid(const unsigned int windowWidth, const unsigned int windowHeight) -> std::vector<std::vector<sf::RectangleShape>> {
        constexpr unsigned int gridSize = 30u;
        constexpr unsigned int cellSize = 20u;
        constexpr unsigned int gridWidth = gridSize * cellSize;
        constexpr unsigned int gridHeight = gridSize * cellSize;

        std::vector<std::vector<sf::RectangleShape>> grid;

        // Calculate the starting position to center the grid
        const float startX = static_cast<float>(windowWidth - gridWidth) / 2.0f;
        const float startY = static_cast<float>(windowHeight - gridHeight) / 2.0f;

        // Initialize the grid with rectangles
        for (unsigned int i = 0; i < gridSize; i++) {
                std::vector<sf::RectangleShape> row;
                for (unsigned int j = 0; j < gridSize; j++) {
                        sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
                        cell.setPosition(startX + static_cast<float>(i) * cellSize, startY + static_cast<float>(j) * cellSize);
                        cell.setFillColor(sf::Color::Black);
                        cell.setOutlineColor(sf::Color::White);
                        cell.setOutlineThickness(1.0f);
                        row.emplace_back(cell);
                }
                grid.emplace_back(row);
        }

        return grid;
}

#endif //GRID_H
