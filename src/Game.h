#ifndef GAME_H
#define GAME_H

#include "Bird.h"
#include "Pipe.h"
#include "InputManager.h"
#include "Renderer.h"
#include "HighScoreManager.h"
#include "AudioManager.h"
#include "Logger.h"
#include <vector>

/**
 * @brief Enum representing the various states of the game.
 */
enum class GameState {
    MENU,    ///< The initial menu state.
    PLAYING, ///< The game is actively being played.
    PAUSED,  ///< The game is paused.
    GAMEOVER ///< The game has ended.
};

/**
 * @brief The main game class encapsulating all game logic.
 *
 * The Game class manages the game loop, input processing, state updates, rendering,
 * and transitions between different game states. It also integrates other managers
 * such as the high score manager, audio manager, and logger.
 */
class Game {
public:
    /**
     * @brief Construct a new Game object.
     */
    Game();
    
    /**
     * @brief Run the main game loop.
     *
     * This function will continuously process input, update game state, and render
     * the game until the application is terminated.
     */
    void run();
    
private:
    /**
     * @brief Process player input based on the current game state.
     */
    void processInput();
    
    /**
     * @brief Update the game state.
     * @param deltaTime The time elapsed since the last frame.
     */
    void update(float deltaTime);
    
    /**
     * @brief Render the current game frame.
     */
    void render();
    
    /**
     * @brief Reset the game to its initial state.
     */
    void resetGame();
    
    /**
     * @brief Check for collisions between the bird and obstacles.
     * @return true if a collision is detected; false otherwise.
     */
    bool checkCollision() const;
    
    GameState state;                  ///< Current state of the game.
    Bird bird;                        ///< The player's bird.
    std::vector<Pipe> pipes;          ///< Container for active pipes.
    InputManager inputManager;        ///< Handles user input.
    Renderer renderer;                ///< Renders the game screen.
    HighScoreManager highScoreManager;///< Manages persistent high scores.
    AudioManager audioManager;        ///< Handles audio playback.
    Logger logger;                    ///< Logs game events.
    int score;                        ///< The player's current score.
    float pipeSpeed;                  ///< Current speed of pipe movement.
    float pipeSpawnTimer;             ///< Timer for pipe spawning.
};

#endif // GAME_H
