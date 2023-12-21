#include <SFML/Graphics.hpp>

int main() {
    constexpr unsigned int windowWidth = 1920u;
    constexpr unsigned int windowHeight = 1080u;
    constexpr unsigned int gridSize = 30u;

    auto window = sf::RenderWindow{{windowWidth, windowHeight}, "Binary Snake"};
    window.setFramerateLimit(144);

    // Create a 2D array to represent the grid
    std::vector<std::vector<sf::RectangleShape>> grid;

    // Initialize the grid with rectangles
    for (unsigned int i = 0; i < gridSize; i++) {
        std::vector<sf::RectangleShape> row;
        for (unsigned int j = 0; j < gridSize; j++) {
            constexpr unsigned int cellSize = 20u;
            sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
            cell.setPosition(static_cast<float>(i) * cellSize, static_cast<float>(j) * cellSize);
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
