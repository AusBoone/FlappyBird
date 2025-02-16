#include "Game.h"
#include "Config.h"
#include <chrono>
#include <thread>
#include <cstdlib>
#include <iostream>

Game::Game()
    : state(GameState::MENU),
      bird(Config::SCREEN_WIDTH / 4, Config::SCREEN_HEIGHT / 2),
      highScoreManager("highscores.txt"),
      logger("game.log"),
      score(0),
      pipeSpeed(10.0f),
      pipeSpawnTimer(0.0f)
{
    // Initialize with one pipe at the right edge of the screen.
    pipes.push_back(Pipe(Config::SCREEN_WIDTH));
}

void Game::resetGame() {
    // Reset game variables to start a new game.
    score = 0;
    pipeSpeed = 10.0f;
    pipeSpawnTimer = 0.0f;
    bird.reset(Config::SCREEN_WIDTH / 4, Config::SCREEN_HEIGHT / 2);
    pipes.clear();
    pipes.push_back(Pipe(Config::SCREEN_WIDTH));
    state = GameState::PLAYING;
    logger.log("Game reset.");
}

void Game::processInput() {
    // Update input state for the current frame.
    inputManager.update();
    
    // Process input based on the current game state.
    if (state == GameState::MENU) {
        if (inputManager.isKeyPressed(Key::SPACE)) {
            state = GameState::PLAYING;
            logger.log("Starting game from menu.");
        }
    } else if (state == GameState::PLAYING) {
        if (inputManager.isKeyPressed(Key::ESCAPE)) {
            state = GameState::PAUSED;
            logger.log("Game paused.");
        }
    } else if (state == GameState::PAUSED) {
        if (inputManager.isKeyPressed(Key::ESCAPE)) {
            state = GameState::PLAYING;
            logger.log("Game resumed.");
        }
    } else if (state == GameState::GAMEOVER) {
        if (inputManager.isKeyPressed(Key::SPACE)) {
            resetGame();
            logger.log("Game restarted after game over.");
        }
    }
}

void Game::update(float deltaTime) {
    if (state == GameState::PLAYING) {
        // Update bird physics; trigger a flap if SPACE was pressed.
        bool flap = inputManager.isKeyPressed(Key::SPACE);
        bird.update(deltaTime, flap);

        // Update each pipe's position.
        for (auto& pipe : pipes) {
            pipe.update(deltaTime, pipeSpeed);
        }
        
        // Remove pipes that have moved off screen and increment score.
        if (!pipes.empty() && pipes.front().isOffScreen()) {
            pipes.erase(pipes.begin());
            score++;
            audioManager.playSound("score");
            logger.log("Pipe passed. Score incremented.");
        }
        
        // Spawn new pipes periodically.
        pipeSpawnTimer += deltaTime * 100;
        if (pipeSpawnTimer > Config::INITIAL_PIPE_INTERVAL) {
            pipes.push_back(Pipe(Config::SCREEN_WIDTH));
            pipeSpawnTimer = 0.0f;
        }
        
        // Gradually increase the pipe speed to increase difficulty.
        pipeSpeed = 10.0f + score * 0.5f;
        
        // Check for collisions between the bird and pipes or borders.
        if (checkCollision()) {
            state = GameState::GAMEOVER;
            audioManager.playSound("collision");
            highScoreManager.saveScore(score);
            logger.log("Collision detected. Game over.");
        }
    }
}

bool Game::checkCollision() const {
    int birdX = bird.getX();
    int birdY = bird.getY();
    
    // Check collision with top and bottom screen boundaries.
    if (birdY <= 0 || birdY >= Config::SCREEN_HEIGHT - 1)
        return true;
    
    // Check collision with each pipe.
    for (const auto& pipe : pipes) {
        if (pipe.getX() == birdX) {
            int gapY = pipe.getGapY();
            int gapHeight = Pipe::getGapHeight();
            if (birdY < gapY || birdY > gapY + gapHeight)
                return true;
        }
    }
    return false;
}

void Game::render() {
    // Create a buffer representing the game screen.
    std::vector<std::string> buffer(Config::SCREEN_HEIGHT, std::string(Config::SCREEN_WIDTH, Config::BLANK_SYMBOL));
    
    // Draw the bird in the buffer.
    int bx = bird.getX();
    int by = bird.getY();
    if (by >= 0 && by < Config::SCREEN_HEIGHT && bx >= 0 && bx < Config::SCREEN_WIDTH)
        buffer[by][bx] = Config::BIRD_SYMBOL;
    
    // Draw each pipe into the buffer.
    for (const auto& pipe : pipes) {
        int px = pipe.getX();
        int gapY = pipe.getGapY();
        int gapHeight = Pipe::getGapHeight();
        if(px >= 0 && px < Config::SCREEN_WIDTH) {
            for (int y = 0; y < Config::SCREEN_HEIGHT; y++) {
                if (y < gapY || y > gapY + gapHeight)
                    buffer[y][px] = Config::PIPE_SYMBOL;
            }
        }
    }
    
    // Add a border around the game screen for visual enhancement.
    renderer.drawBorders(buffer);
    
    // Prepare a state message for overlay (menu, paused, or game over).
    std::string stateMsg;
    if(state == GameState::MENU)
        stateMsg = "Press SPACE to start!";
    else if(state == GameState::PAUSED)
        stateMsg = "Paused. Press ESC to resume.";
    else if(state == GameState::GAMEOVER)
        stateMsg = "Game Over! Press SPACE to restart.";
    
    // Render the final buffer along with score and state message.
    renderer.render(buffer, score, stateMsg);
}

void Game::run() {
    using clock = std::chrono::high_resolution_clock;
    auto previousTime = clock::now();
    
    // Main game loop
    while (true) {
        auto currentTime = clock::now();
        std::chrono::duration<float> elapsed = currentTime - previousTime;
        previousTime = currentTime;
        float deltaTime = elapsed.count();  // Time elapsed since last frame
        
        processInput();   // Handle user input for this frame.
        update(deltaTime); // Update game state based on elapsed time.
        render();         // Render the current game frame.
        
        // Sleep to control the frame rate.
        std::this_thread::sleep_for(std::chrono::milliseconds(Config::FRAME_DELAY_MS));
    }
}
