#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include <string>

/**
 * @brief Manages audio playback for the game.
 *
 * This is a stub implementation. In a complete project, this class would be
 * integrated with an audio library (e.g., SFML, SDL_mixer) to handle sound effects.
 */
class AudioManager {
public:
    /**
     * @brief Construct a new AudioManager object.
     */
    AudioManager();
    
    /**
     * @brief Play a sound effect.
     * @param soundName The identifier for the sound to play.
     */
    void playSound(const std::string &soundName);
};

#endif // AUDIOMANAGER_H
