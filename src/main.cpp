#include <SFML/Graphics.hpp>

int main() {
    constexpr unsigned int windowWidth = 1366u;
    constexpr unsigned int windowHeight = 768u;
    constexpr unsigned int gridSize = 30u;

    auto window = sf::RenderWindow{{windowWidth, windowHeight}, "Binary Snake"};
    window.setFramerateLimit(144);

    constexpr unsigned int cellSize = 20u;
    constexpr unsigned int gridWidth = gridSize * cellSize;
    constexpr unsigned int gridHeight = gridSize * cellSize;

    // Calculate the starting position to center the grid
    float startX = (windowWidth - gridWidth) / 2.0f;
    float startY = (windowHeight - gridHeight) / 2.0f;

    // Create a 2D array to represent the grid
    std::vector<std::vector<sf::RectangleShape>> grid;

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

        window.display();
    }
}
