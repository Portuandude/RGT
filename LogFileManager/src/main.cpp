#include "LogFileManager.h"

int main() {
    try {
        LogFileManager manager;

        manager.openLogFile("error.log");
        manager.openLogFile("debug.log");
        manager.openLogFile("info.log");

        manager.writeLog("error.log", "Database connection failed");
        manager.writeLog("debug.log", "User login attempt");
        manager.writeLog("info.log", "Server started successfully");

        std::vector<std::string> errorLogs = manager.readLogs("error.log");

        for (const auto& log : errorLogs) {
            std::cout << log << std::endl;
        }

        manager.closeLogFile("error.log");
        manager.closeLogFile("debug.log");
        manager.closeLogFile("info.log");
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
