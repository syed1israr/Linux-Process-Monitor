#pragma once
#include <string>
#include <vector>

struct ProcessInfo {
    int pid;
    std::string name;
    std::string state;
    double memoryUsage;   // in MB
    std::string user;
};

// Declare functions
std::vector<int> getAllPIDs();
ProcessInfo getProcessInfo(int pid);
std::vector<ProcessInfo> getAllProcessInfo();
