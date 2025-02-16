#include "Pipe.h"
#include <cstdlib>

Pipe::Pipe(int startX) : x(startX) {
    // Randomly position the gap within the screen boundaries.
    gapY = rand() % (Config::SCREEN_HEIGHT - Config::PIPE_GAP);
}

void Pipe::update(float deltaTime, float speed) {
    // Move the pipe leftward based on its speed and elapsed time.
    x -= static_cast<int>(speed * deltaTime);
}

bool Pipe::isOffScreen() const {
    // Consider the pipe off screen when its x-coordinate is less than -1.
    return x < -1;
}

int Pipe::getX() const {
    return x;
}

int Pipe::getGapY() const {
    return gapY;
}

int Pipe::getGapHeight() {
    return Config::PIPE_GAP;
}

void Pipe::reset(int newX) {
    x = newX;
    // Choose a new random position for the gap.
    gapY = rand() % (Config::SCREEN_HEIGHT - Config::PIPE_GAP);
}
