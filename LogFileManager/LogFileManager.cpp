#include <iostream>
#include <string>
#include <map>
#include <memory>
#include <fstream>
#include <stdexcept>
#include <chrono>
#include <iomanip>
#include <vector>
#include <iterator>

/// @brief Timestamp + LogFile Management
class LogFileManager{
private:
    std::map<std::string, std::unique_ptr<std::ofstream>> files;
public:
    LogFileManager() = default;
    
    LogFileManager(const LogFileManager&) = delete;
    LogFileManager& operator=(const LogFileManager&) = delete;

    LogFileManager(LogFileManager&&) = default;
    LogFileManager& operator=(LogFileManager&&) = default;

    void openLogFile(const std::string& filename);
    void writeLog(const std::string& filename, const std::string& message);
    std::vector<std::string> readLogs(const std::string& filename);
    void closeLogFile(const std::string& filename);
};

/// @brief Open Log file
void LogFileManager::openLogFile(const std::string& filename){
    if(files.find(filename)!=files.end()) return;
        
    auto file = std::make_unique<std::ofstream>(filename, std::ios::app);
        
    if (!file->is_open()) throw std::runtime_error("Fail open log file: " + filename);

    files[filename] = std::move(file);
}

/// @brief Write Log to file
void LogFileManager::writeLog(const std::string& filename, const std::string& message){
    auto it = files.find(filename);

    if(it==files.end()) throw std::runtime_error("Log file not open: " + filename);

    auto _now = std::chrono::system_clock::now();

    std::time_t time = std::chrono::system_clock::to_time_t(_now);
    (*it->second) << "[" << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S")<< "] " << message << std::endl;

    if (it->second->fail()) throw std::runtime_error("Fail write to log file: " + filename);
}

/// @brief Read Log to file
/// @return vector<log>
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

/// @brief 
void LogFileManager::closeLogFile(const std::string& filename) {
    auto it = files.find(filename);
    if (it != files.end()) {
        // unique_ptr가 소멸되면서 파일 자동 close
        files.erase(it);
    }
}

void main()
{
    LogFileManager manager;
    manager.openLogFile("error.log");
    manager.openLogFile("debug.log");
    manager.openLogFile("info.log");
    manager.writeLog("error.log", "Database connection failed");
    manager.writeLog("debug.log", "User login attempt");
    manager.writeLog("info.log", "Server started successfully");
    std::vector<std::string> errorLogs = manager.readLogs("error.log");

}