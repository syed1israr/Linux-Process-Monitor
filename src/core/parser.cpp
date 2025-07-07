#include "../../include/parser.hpp"
#include <dirent.h>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <pwd.h>
#include <vector>
#include <string>
#include <algorithm>

std::vector<int> getAllPIDs() {
    std::vector<int> pids;
    DIR* dir = opendir("/proc");
    if (!dir) return pids;

    struct dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        std::string name = entry->d_name;
        if (std::all_of(name.begin(), name.end(), ::isdigit)) {
            pids.push_back(std::stoi(name));
        }
    }
    closedir(dir);
    return pids;
}

std::string getUsernameFromUid(int uid) {
    struct passwd* pw = getpwuid(uid);
    if (pw) return pw->pw_name;
    return "unknown";
}

ProcessInfo getProcessInfo(int pid) {
    ProcessInfo info;
    info.pid = pid;

    std::string path = "/proc/" + std::to_string(pid) + "/status";
    std::ifstream file(path);
    std::string line;

    while (getline(file, line)) {
        if (line.find("Name:") == 0)
            info.name = line.substr(6);
        else if (line.find("State:") == 0)
            info.state = line.substr(7);
        else if (line.find("VmRSS:") == 0)
            info.memoryUsage = std::stod(line.substr(7)) / 1024.0;
        else if (line.find("Uid:") == 0) {
            std::istringstream iss(line.substr(5));
            int uid;
            iss >> uid;
            info.user = getUsernameFromUid(uid);
        }
    }

    return info;
}

std::vector<ProcessInfo> getAllProcessInfo() {
    std::vector<ProcessInfo> list;
    for (int pid : getAllPIDs()) {
        try {
            list.push_back(getProcessInfo(pid));
        } catch (...) {
            continue;
        }
    }
    return list;
}
