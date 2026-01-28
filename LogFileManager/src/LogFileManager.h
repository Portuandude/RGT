#ifndef LOG_FILE_MANAGER_H
#define LOG_FILE_MANAGER_H

#include <iostream>
#include <string>
#include <map>
#include <memory>
#include <fstream>
#include <stdexcept>
#include <chrono>
#include <iomanip>
#include <vector>

/// @brief Timestamp + LogFile Management
class LogFileManager {
private:
    std::map<std::string, std::unique_ptr<std::ofstream>> files;

public:
    LogFileManager();
    ~LogFileManager() = default;

    // 복사 금지
    LogFileManager(const LogFileManager&) = delete;
    LogFileManager& operator=(const LogFileManager&) = delete;

    // 이동 허용
    LogFileManager(LogFileManager&&) = default;
    LogFileManager& operator=(LogFileManager&&) = default;

    void openLogFile(const std::string& filename);
    void writeLog(const std::string& filename, const std::string& message);
    std::vector<std::string> readLogs(const std::string& filename);
    void closeLogFile(const std::string& filename);
};

#endif // LOG_FILE_MANAGER_H
