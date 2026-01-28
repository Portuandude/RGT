#include "LogFileManager.h"

LogFileManager::LogFileManager() = default;

/// @brief Open Log file
void LogFileManager::openLogFile(const std::string& filename) {
    if (files.find(filename) != files.end()) return;

    auto file = std::make_unique<std::ofstream>(filename, std::ios::app);
    if (!file->is_open()) {
        throw std::runtime_error("Fail open log file: " + filename);
    }

    files[filename] = std::move(file);
}

/// @brief Write Log to file
void LogFileManager::writeLog(const std::string& filename, const std::string& message) {
    auto it = files.find(filename);
    if (it == files.end()) {
        throw std::runtime_error("Log file not open: " + filename);
    }

    auto now = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(now);

    (*it->second)
        << "[" << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S") << "] "
        << message << std::endl;

    if (it->second->fail()) {
        throw std::runtime_error("Fail write to log file: " + filename);
    }
}

/// @brief Read Log file
std::vector<std::string> LogFileManager::readLogs(const std::string& filename) {
    std::vector<std::string> logs;

    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open log file for reading: " + filename);
    }

    std::string line;
    while (std::getline(file, line)) {
        logs.push_back(line);
    }

    return logs;
}

/// @brief Close Log file
void LogFileManager::closeLogFile(const std::string& filename) {
    auto it = files.find(filename);
    if (it != files.end()) {
        // unique_ptr 소멸 → 파일 자동 close
        files.erase(it);
    }
}
