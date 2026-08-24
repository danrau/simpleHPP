#pragma once

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <random>
#include <cassert>

const std::string simpleHPPversion = "simpleHPP::v0.1a";

void simpleHPP() {
    std::cout << "Git: \"https://github.com/danrau/simpleHPP\" " << std::endl;
    std::cout << simpleHPPversion << std::endl;
}

inline std::string input(std::string prompt) {
    std::string result;
    std::cout << prompt;
    if (std::cin.rdbuf()->in_avail() > 0) {
        for (int i = std::cin.rdbuf()->in_avail(); i > 0; i--) {
            std::cin.ignore();
        }
    }
    getline(std::cin, result);
    return result;
}

class Timer {
    public:
    using TimePoint = std::chrono::time_point<std::chrono::high_resolution_clock>;
    TimePoint start_time;
    TimePoint end_time;
    void start() {start_time = std::chrono::high_resolution_clock::now();}
    void end() {end_time = std::chrono::high_resolution_clock::now();}
    long long int get_time() {return std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();}
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

inline int randge(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}

inline int randint() {
    return randge(1, 100); // This is default numbers. You may change they if you need.
}

inline void wait(int i) { // basic wait work on milliseconds
    std::this_thread::sleep_for(std::chrono::milliseconds(i));
}

inline void wait_mcsec(int mcsec) {
    std::this_thread::sleep_for(std::chrono::microseconds(mcsec));
}

inline void wait_min(int min) {
    std::this_thread::sleep_for(std::chrono::minutes(min));
}

inline void wait_mlsec(int mlsec) {
    std::this_thread::sleep_for(std::chrono::milliseconds(mlsec));
}

inline void wait_sec(int secnd) {
    std::this_thread::sleep_for(std::chrono::seconds(secnd));
}

inline void ccls() {
    std::system("cls");
}