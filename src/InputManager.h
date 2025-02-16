#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <unordered_map>

/**
 * @brief Enum representing keys used for game input.
 */
enum class Key {
    SPACE,   ///< Represents the spacebar, used for flapping.
    ESCAPE,  ///< Represents the escape key, used for pausing/resuming.
    NONE     ///< Represents no key.
};

/**
 * @brief Manages keyboard input.
 *
 * The InputManager class polls the keyboard state and allows the game
 * to query whether specific keys were pressed. It supports edge detection
 * to prevent continuous input from a single key press.
 */
class InputManager {
public:
    /**
     * @brief Construct a new InputManager object.
     */
    InputManager();
    
    /**
     * @brief Update the internal state of key presses.
     *
     * This function should be called once per frame to refresh key states.
     */
    void update();
    
    /**
     * @brief Check if a specific key was pressed in the current frame.
     * @param key The key to check.
     * @return true if the key was pressed; false otherwise.
     */
    bool isKeyPressed(Key key) const;
    
private:
    std::unordered_map<Key, bool> keyState; ///< Stores the pressed state of each key.
    
    /**
     * @brief Poll the keyboard for key presses.
     *
     * Platform-specific implementation for checking if keys are pressed.
     */
    void pollKeyboard();
};

#endif // INPUTMANAGER_H
