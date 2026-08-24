#pragma once

#include <limits>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <random>
#include <cassert>

namespace simple {

const std::string simpleHPPversion = "simpleHPP | v0.1b";

inline void simpleHPP() {
    std::cout << "Git:\"https://github.com/danrau/simpleHPP\"" << std::endl;
    std::cout << simpleHPPversion << std::endl;
    std::cout << "Mail: blink.dagger1337@icloud.com" << std::endl;
}

inline std::string input(std::string prompt = "") {
    std::string result;

    if (!prompt.empty()) std::cout << prompt;
    #if defined(_WIN32) || defined(_WIN64)
    if (std::cin.rdbuf()->in_avail() > 0) {
        for (int i = std::cin.rdbuf()->in_avail(); i > 0; i--) {
            std::cin.ignore();
        }
    }
    #else
    if (std::cin.peek() != EOF && std::cin.peek() != '\n') {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    #endif
    if (std::cin.peek() == '\n') {
        std::cin.ignore();
    }

    getline(std::cin, result);
    return result;
}

class Timer {
    private:
        using TimePoint = std::chrono::time_point<std::chrono::high_resolution_clock>;

        TimePoint start_time;
        TimePoint end_time;

    public:
        void start() {
            start_time = std::chrono::high_resolution_clock::now();
        }

        void end() {
            end_time = std::chrono::high_resolution_clock::now();
        }

        void clear() {
            start_time = TimePoint();
            end_time = TimePoint();
        }

        long long int get_time() {
            if (start_time == TimePoint()) return 0;
            if (end_time == TimePoint()) {
                auto now = std::chrono::high_resolution_clock::now();
                return std::chrono::duration_cast<std::chrono::microseconds>(now - start_time).count();
            }
            return std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
        }
};

inline std::string gen_progres_bar(int percent) {
    assert(percent >= 0);
    assert(percent <= 100);
    if (percent < 0 || percent > 100) std::abort();
    std::string bar = "[";
    int hashes = percent / 10;
    int dashes = 10 - hashes;
    bar += std::string(hashes, '#');
    bar += std::string(dashes, '-');
    bar += "] " + std::to_string(percent) + "%";
    return bar;
}

inline int randint(int min = 1, int max = 100) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}


enum class WaitUnit {
    Microseconds,
    Milliseconds,
    Seconds,
    Minutes
};

inline void wait(int time, WaitUnit unit = WaitUnit::Milliseconds) {
    if (unit == WaitUnit::Milliseconds) std::this_thread::sleep_for(std::chrono::milliseconds(time));
    else if (unit == WaitUnit::Microseconds) std::this_thread::sleep_for(std::chrono::microseconds(time));
    else if (unit == WaitUnit::Seconds) std::this_thread::sleep_for(std::chrono::seconds(time));
    else if (unit == WaitUnit::Minutes) std::this_thread::sleep_for(std::chrono::minutes(time));
}

inline void ccls() {
    #if defined(_WIN32) || defined(_WIN64)
        std::system("cls");
    #else
        std::system("clear");
    #endif
}

}