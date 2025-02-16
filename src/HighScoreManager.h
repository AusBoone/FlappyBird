#ifndef HIGHSCOREMANAGER_H
#define HIGHSCOREMANAGER_H

#include <string>
#include <vector>

/**
 * @brief Manages persistent high scores for the game.
 *
 * This class loads scores from a file and saves new scores as needed.
 * Scores are stored in a vector and sorted in descending order.
 */
class HighScoreManager {
public:
    /**
     * @brief Construct a new HighScoreManager object.
     * @param filename The file used for storing high scores.
     */
    HighScoreManager(const std::string &filename);
    
    /**
     * @brief Load high scores from the file.
     */
    void loadScores();
    
    /**
     * @brief Save a new score to the file.
     * @param score The score to be saved.
     */
    void saveScore(int score);
    
    /**
     * @brief Get the loaded high scores.
     * @return const std::vector<int>& A reference to the vector of scores.
     */
    const std::vector<int>& getScores() const;
    
private:
    std::string filename;      ///< The file name where scores are stored.
    std::vector<int> scores;   ///< Container for high scores.
};

#endif // HIGHSCOREMANAGER_H
