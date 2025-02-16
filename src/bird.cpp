#include "Bird.h"

Bird::Bird(int x, int y)
    : x(x), posY(y), velocityY(0.0f) {}

void Bird::update(float deltaTime, bool flap) {
    // If flap is triggered, apply an upward force.
    if (flap)
        velocityY = Config::FLAP_STRENGTH;
    // Apply gravity to the vertical velocity.
    velocityY += Config::GRAVITY * deltaTime;
    // Update the bird's vertical position.
    posY += velocityY * deltaTime * 50; // The multiplier adjusts the game feel.
    
    // Clamp the bird's position within the screen boundaries.
    if (posY < 0) posY = 0;
    if (posY > Config::SCREEN_HEIGHT - 1) posY = Config::SCREEN_HEIGHT - 1;
}

int Bird::getX() const {
    return x;
}

int Bird::getY() const {
    return static_cast<int>(posY);
}

void Bird::reset(int x, int y) {
    this->x = x;
    posY = y;
    velocityY = 0.0f;
}
