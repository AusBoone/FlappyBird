#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <string>
#include "Config.h"

/**
 * @brief Responsible for rendering the game screen.
 *
 * The Renderer class builds and outputs the visual representation of the game,
 * including drawing borders, the game elements, and overlay messages.
 */
class Renderer {
public:
    /**
     * @brief Construct a new Renderer object.
     */
    Renderer();
    
    /**
     * @brief Clear the console screen.
     *
     * Uses ANSI escape codes to clear the screen and reset the cursor position.
     */
    void clearScreen();
    
    /**
     * @brief Render the screen buffer along with score and overlay message.
     * @param screenBuffer A vector of strings representing the game screen.
     * @param score The current game score.
     * @param stateMessage Additional message to display (e.g., game state).
     */
    void render(const std::vector<std::string>& screenBuffer, int score, const std::string& stateMessage = "");
    
    /**
     * @brief Draw borders around the screen buffer.
     * @param buffer The screen buffer to modify by adding borders.
     */
    void drawBorders(std::vector<std::string>& buffer);
};

#endif // RENDERER_H
