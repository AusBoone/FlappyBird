#include "HighScoreManager.h"
#include <fstream>
#include <sstream>
#include <algorithm>

HighScoreManager::HighScoreManager(const std::string &filename) : filename(filename) {
    loadScores();
}

void HighScoreManager::loadScores() {
    scores.clear();
    std::ifstream file(filename);
    if (!file) return; // No file found; start with an empty score list.
    
    std::string line;
    // Read each line and convert it to an integer score.
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int score;
        if (iss >> score)
            scores.push_back(score);
    }
    file.close();
    // Sort scores in descending order.
    std::sort(scores.rbegin(), scores.rend());
}

void HighScoreManager::saveScore(int score) {
    scores.push_back(score);
    // Append the new score to the file.
    std::ofstream file(filename, std::ios::app);
    if (file)
        file << score << "\n";
}

const std::vector<int>& HighScoreManager::getScores() const {
    return scores;
}
