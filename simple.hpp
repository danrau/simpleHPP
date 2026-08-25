#pragma once

#include <limits>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <random>
#include <cassert>
#include <fstream>
#include <sstream>
#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif

namespace simple {

const std::string simpleHPPversion = "simpleHPP | v0.2a";

enum class TimeUnit {
    Microseconds,
    Milliseconds,
    Seconds,
    Minutes
};

inline void simpleHPP() {
    std::cout << "Git:\"https://github.com/danrau/simpleHPP\"" << std::endl;
    std::cout << simpleHPPversion << std::endl;
    std::cout << "Mail: blink.dagger1337@icloud.com" << std::endl;
}

inline bool hasfile(const std::string& filename) {
    std::ifstream file(filename);
    return file.good();
}

inline std::string readfile(const std::string& filename) {
    if (!hasfile(filename)) return "";
    std::ifstream read(filename);
    std::stringstream buf;
    buf << read.rdbuf();
    return buf.str();
}

inline std::string input(const std::string& prompt = "") {
    std::string result;

    if (!prompt.empty()) std::cout << prompt;
    if (!std::cin) std::cin.clear();
    if (std::cin.peek() == '\n') std::cin.ignore();

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

        long long int getTime(TimeUnit timetype = TimeUnit::Milliseconds) const {
            if (start_time == TimePoint()) return 0;
            auto current_end = (end_time == TimePoint())
                                ? std::chrono::high_resolution_clock::now()
                                : end_time;
            
            auto duration = current_end - start_time;
            if (timetype == TimeUnit::Microseconds) return std::chrono::duration_cast<std::chrono::microseconds>(duration).count();
            else if (timetype == TimeUnit::Milliseconds) return std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
            else if (timetype == TimeUnit::Seconds) return std::chrono::duration_cast<std::chrono::seconds>(duration).count();
            else if (timetype == TimeUnit::Minutes) return std::chrono::duration_cast<std::chrono::minutes>(duration).count();
            
            std::abort();
        }

        double getTimeX() const {
            return static_cast<double>(getTime(TimeUnit::Microseconds)) / 1000000.0;
        }
};

inline std::string genProgressBar(int percent) {
    
    if (percent < 0) percent = 0;
    if (percent > 100) percent = 100;

    std::string bar = "[";
    int hashes = percent / 10;
    int dashes = 10 - hashes;

    bar += std::string(hashes, '#');
    bar += std::string(dashes, '-');
    bar += "] " + std::to_string(percent) + "%";

    return bar;
}

inline int randint(int min = 1, int max = 100) {
    if (min > max) std::swap(min, max);
    static thread_local std::random_device rd;
    static thread_local std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}

inline double randouble(double min = 1, double max = 100) {
    if (min > max) std::swap(min, max);
    static thread_local std::random_device rd;
    static thread_local std::mt19937 gen(rd());
    
    std::uniform_real_distribution<double> dist(min, max);
    return dist(gen);
}

inline void wait(int time, TimeUnit unit = TimeUnit::Milliseconds) {
    if (unit == TimeUnit::Milliseconds) std::this_thread::sleep_for(std::chrono::milliseconds(time));
    else if (unit == TimeUnit::Microseconds) std::this_thread::sleep_for(std::chrono::microseconds(time));
    else if (unit == TimeUnit::Seconds) std::this_thread::sleep_for(std::chrono::seconds(time));
    else if (unit == TimeUnit::Minutes) std::this_thread::sleep_for(std::chrono::minutes(time));
}

inline void ccls() {
    #if defined(_WIN32) || defined(_WIN64)
    static bool init_ansi = []() {
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hOut == INVALID_HANDLE_VALUE) return false;

        DWORD dwMode = 0;
        if (!GetConsoleMode(hOut, &dwMode)) return false;
        
        dwMode |= 0x0004;
        return SetConsoleMode(hOut, dwMode);
    }();
    #endif

    std::cout << "\033[2J\033[H" << std::flush;
}

}