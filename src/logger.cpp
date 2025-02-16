#include "Logger.h"

Logger::Logger(const std::string &filename) {
    // Open the log file in append mode.
    logFile.open(filename, std::ios::out | std::ios::app);
}

Logger::~Logger() {
    // Ensure the file is closed upon destruction.
    if (logFile.is_open())
        logFile.close();
}

void Logger::log(const std::string &message) {
    // Lock the mutex to ensure thread-safe access to the log file.
    std::lock_guard<std::mutex> lock(mtx);
    logFile << message << std::endl;
}
