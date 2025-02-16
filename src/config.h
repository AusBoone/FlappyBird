#ifndef CONFIG_H
#define CONFIG_H

/**
 * @file Config.h
 * @brief Contains configuration constants used throughout the game.
 *
 * This header defines various constants that determine the game settings,
 * such as screen dimensions, physics parameters, timing intervals, and
 * character symbols used in rendering.
 */
namespace Config {
    constexpr int SCREEN_HEIGHT = 20;         ///< Height of the game screen in rows.
    constexpr int SCREEN_WIDTH = 30;          ///< Width of the game screen in columns.
    constexpr int PIPE_GAP = 4;               ///< Vertical gap in pipes through which the bird must fly.
    constexpr float GRAVITY = 0.1f;           ///< Acceleration due to gravity.
    constexpr float FLAP_STRENGTH = -0.5f;      ///< Upward force applied when the bird flaps.
    constexpr int INITIAL_PIPE_INTERVAL = 30; ///< Interval (in arbitrary units) for spawning new pipes.
    constexpr int FRAME_DELAY_MS = 100;       ///< Frame delay in milliseconds for the game loop.
    
    // Symbols used for rendering game elements.
    const char BIRD_SYMBOL = 'O';             ///< Symbol representing the bird.
    const char PIPE_SYMBOL = '|';             ///< Symbol representing a pipe.
    const char BLANK_SYMBOL = ' ';            ///< Symbol representing an empty space.
    const char BORDER_SYMBOL = '#';           ///< Symbol for the border around the game screen.
}

#endif // CONFIG_H
