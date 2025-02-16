#include <iostream>   // for input/output operations (cout, endl)
#include <cstdlib>    // for srand() and rand()
#include <ctime>      // for time()
#include <Windows.h>  // for Sleep() and GetAsyncKeyState()
#include <conio.h>    // for getch()

// Constants for screen dimensions
const int SCREEN_HEIGHT = 20;
const int SCREEN_WIDTH = 30;

// Constants for character symbols
const char BIRD = 'O';
const char PIPE = '|';
const char BLANK = ' ';

void drawScreen(const int birdX, const int birdY, const int pipe1X, const int pipe2X, int score) {
    
    // Display the current score
    std::cout << "Score: " << score << std::endl;

    // Draw the game screen
    for (int y = 0; y < SCREEN_HEIGHT; y++) {
        for (int x = 0; x < SCREEN_WIDTH; x++) {
            if (y == birdY && x == birdX) {
                std::cout << BIRD;
            } else if (x == pipe1X || x == pipe2X) {
                std::cout << PIPE;
            } else {
                std::cout << BLANK;
            }
        }
        std::cout << std::endl;
    }
}

void gameOverScreen(int score) {

    // Display the game over message and the player's final score
    std::cout << "Game over!\nYour score is: " << score << std::endl;
    std::cout << "Press any key to exit...";
    getch();
}

int main() {

    // Seed the random number generator
    srand(time(NULL));

    // Initialize variables for the bird's position and pipe's position
    int birdX = SCREEN_WIDTH / 2;
    int birdY = SCREEN_HEIGHT / 2;
    int pipe1X = SCREEN_WIDTH;
    int pipe2X = SCREEN_WIDTH + 4;
    int pipeY = rand() % (SCREEN_HEIGHT - 3) + 1;
    int pipeGap = 3;
    int birdVelocity = 0;
    int score = 0;
    int delayAfterCollision = 50; // Delay before game over screen appears (in milliseconds)
    int speedIncreaseInterval = 10; // Increase game speed every 10 points
    float birdPosY = birdY;
    float birdVelY = 0;
    float gravity = 0.1; // Acceleration due to gravity
    float birdAccY = 0;
    int scoreMultiplier = 1;
    bool paused = false;

    // Main game loop
    while (true) {

        // Handle user input
        if (GetAsyncKeyState(VK_SPACE)) {
            if (!paused) {
                birdAccY = -0.5; // Accelerate the bird upward
            }
        }
        if (GetAsyncKeyState(VK_ESCAPE)) {
            paused = !paused; // Toggle pause state
        }

        // Update game state
        if (!paused) {
            birdPosY += birdVelY; // Update bird position
            birdVelY += birdAccY; // Update bird velocity
            birdAccY += gravity; // Update bird acceleration
            birdY = static_cast<int>(birdPosY); // Convert bird position to integer
            pipe1X--;
            pipe2X--;
            if (pipe1X <= 0) {
                pipe1X = SCREEN_WIDTH;
                pipe2X = SCREEN_WIDTH + 4;
                pipeY = rand() % (SCREEN_HEIGHT - pipeGap) + 1;
            }
            if ((birdX == pipe1X || birdX == pipe2X) && (birdY < pipeY || birdY > pipeY + pipeGap)) {
                // Game over
                Sleep(delayAfterCollision);
                gameOverScreen(score);
                break;
            }

            // Increment score if bird passes through pipes
            if (birdX == pipe1X + 1) {
                score += scoreMultiplier;
                if (score % speedIncreaseInterval == 0) {
                    pipe1X++; // Increase game speed
                    pipe2X++;
                }
                if (score % 2 == 0) {
                    scoreMultiplier++; // Increase score multiplier every 2 points
                }
            }
        }

        // Draw the screen
        drawScreen(birdX, birdY, pipe1X, pipe2X, score);
        Sleep(100);
    }
