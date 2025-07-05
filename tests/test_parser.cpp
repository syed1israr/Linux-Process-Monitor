#include "../include/parser.hpp"
#include <iostream>

int main() {
    std::vector<ProcessInfo> processes = getAllProcessInfo();

    for (const auto& p : processes) {
        std::cout << "PID: " << p.pid
                  << " | Name: " << p.name
                  << " | State: " << p.state
                  << " | RAM: " << p.memoryUsage << " MB"
                  << " | User: " << p.user << '\n';
    }

    return 0;
}
