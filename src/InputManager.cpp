#include "InputManager.h"

#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#endif

InputManager::InputManager() {
    // Initialize all key states to false.
    keyState[Key::SPACE] = false;
    keyState[Key::ESCAPE] = false;
}

void InputManager::pollKeyboard() {
#ifdef _WIN32
    // On Windows, use _kbhit and _getch for non-blocking keyboard input.
    while (_kbhit()) {
        int ch = _getch();
        if (ch == ' ')
            keyState[Key::SPACE] = true;
        else if (ch == 27) // ASCII code for ESC
            keyState[Key::ESCAPE] = true;
    }
#else
    // On Unix-like systems, use termios and fcntl to set non-blocking input.
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);           // Get current terminal settings.
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);          // Disable canonical mode and echo.
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);    // Apply new settings immediately.
    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK); // Set non-blocking mode.
    
    int ch;
    while((ch = getchar()) != EOF) {
        if(ch == ' ')
            keyState[Key::SPACE] = true;
        else if(ch == 27)
            keyState[Key::ESCAPE] = true;
    }
    // Restore terminal settings.
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, flags);
#endif
}

void InputManager::update() {
    // Reset key states at the beginning of each frame.
    keyState[Key::SPACE] = false;
    keyState[Key::ESCAPE] = false;
    pollKeyboard();
}

bool InputManager::isKeyPressed(Key key) const {
    auto it = keyState.find(key);
    return it != keyState.end() ? it->second : false;
}
