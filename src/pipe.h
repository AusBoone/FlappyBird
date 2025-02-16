#ifndef PIPE_H
#define PIPE_H

#include "Config.h"

/**
 * @brief Represents a pipe obstacle in the game.
 *
 * The Pipe class stores the pipe's horizontal position and the vertical position
 * of its gap. It provides functions to update its position and check if it has moved off screen.
 */
class Pipe {
public:
    /**
     * @brief Construct a new Pipe object.
     * @param startX The starting x-coordinate for the pipe.
     */
    Pipe(int startX);
    
    /**
     * @brief Update the pipe's position.
     * @param deltaTime The time elapsed since the last frame.
     * @param speed The current speed at which pipes move.
     */
    void update(float deltaTime, float speed);
    
    /**
     * @brief Check if the pipe has moved off screen.
     * @return true if off screen; false otherwise.
     */
    bool isOffScreen() const;
    
    /**
     * @brief Get the current x-coordinate of the pipe.
     * @return int The x-coordinate.
     */
    int getX() const;
    
    /**
     * @brief Get the y-coordinate where the gap starts.
     * @return int The gap's starting y-coordinate.
     */
    int getGapY() const;
    
    /**
     * @brief Get the height of the gap.
     * @return int The gap height.
     */
    static int getGapHeight();
    
    /**
     * @brief Reset the pipe's position and randomly choose a new gap position.
     * @param newX The new x-coordinate for the pipe.
     */
    void reset(int newX);
    
private:
    int x;    ///< The current horizontal position of the pipe.
    int gapY; ///< The vertical position where the gap begins.
};

#endif // PIPE_H
