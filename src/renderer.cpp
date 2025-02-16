#include "Renderer.h"
#include <iostream>

Renderer::Renderer() { }

void Renderer::clearScreen() {
    // Use ANSI escape codes to clear the console screen and move the cursor to the top-left.
    std::cout << "\033[2J\033[H";
}

void Renderer::drawBorders(std::vector<std::string>& buffer) {
    // Create a border string using the configured border symbol.
    std::string topBottom(Config::SCREEN_WIDTH + 2, Config::BORDER_SYMBOL);
    // Insert the top border and add the bottom border.
    buffer.insert(buffer.begin(), topBottom);
    buffer.push_back(topBottom);
    // Add left and right borders for each line.
    for (auto& line : buffer) {
        line = Config::BORDER_SYMBOL + line + Config::BORDER_SYMBOL;
    }
}

void Renderer::render(const std::vector<std::string>& screenBuffer, int score, const std::string& stateMessage) {
    clearScreen(); // Clear the screen before rendering the new frame.
    std::cout << "Score: " << score << "\n";
    if (!stateMessage.empty())
        std::cout << stateMessage << "\n";
    // Output each line of the screen buffer.
    for (const auto& line : screenBuffer)
        std::cout << line << "\n";
}
