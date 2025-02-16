#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <string>
#include <mutex>

/**
 * @brief A simple thread-safe logger class.
 *
 * This class provides basic logging functionality by appending messages
 * to a specified log file. It uses a mutex to ensure that log entries from
 * multiple threads do not interleave.
 */
class Logger {
public:
    /**
     * @brief Construct a new Logger object.
     * @param filename The file name to which logs will be written.
     */
    Logger(const std::string &filename);
    
    /**
     * @brief Destroy the Logger object and close the log file.
     */
    ~Logger();
    
    /**
     * @brief Log a message to the file.
     * @param message The message to be logged.
     */
    void log(const std::string &message);
    
private:
    std::ofstream logFile; ///< Output file stream for the log.
    std::mutex mtx;        ///< Mutex to ensure thread safety.
};

#endif // LOGGER_H
