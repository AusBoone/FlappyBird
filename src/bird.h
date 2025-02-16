#ifndef BIRD_H
#define BIRD_H

#include "Config.h"

/**
 * @brief Represents the bird character in the game.
 *
 * The Bird class handles the bird's position and physics, including gravity and flapping.
 */
class Bird {
public:
    /**
     * @brief Construct a new Bird object.
     * @param x The fixed x-coordinate for the bird.
     * @param y The starting y-coordinate for the bird.
     */
    Bird(int x, int y);
    
    /**
     * @brief Update the bird's physics.
     * @param deltaTime The time elapsed since the last frame.
     * @param flap Whether the bird should flap (apply upward force).
     */
    void update(float deltaTime, bool flap);
    
    /**
     * @brief Get the bird's x-coordinate.
     * @return int The x-coordinate.
     */
    int getX() const;
    
    /**
     * @brief Get the bird's y-coordinate.
     * @return int The y-coordinate (rounded from the float position).
     */
    int getY() const;
    
    /**
     * @brief Reset the bird's state.
     * @param x New x-coordinate.
     * @param y New y-coordinate.
     */
    void reset(int x, int y);
    
private:
    int x;          ///< The fixed horizontal position of the bird.
    float posY;     ///< The vertical position (as a float for smooth physics).
    float velocityY;///< The vertical velocity of the bird.
};

#endif // BIRD_H
